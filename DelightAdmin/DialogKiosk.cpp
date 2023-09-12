#include "DialogKiosk.h"
#include "ui_DialogKiosk.h"

#include "Scheduler.h"
#include "DialogOutlet.h"

extern Scheduler *pschedule;
extern DialogOutlet *poutlet;
extern Logger       *plog;

DialogKiosk::DialogKiosk(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogKiosk)
{
    ui->setupUi(this);

    stock = NULL;
    block_order = true;
    force_block_order = true;

    server = new QtHttpServer(this);
    connect(server, SIGNAL(requestNeedsReply(QtHttpRequest*,QtHttpReply*)), this, SLOT(onRequestReply(QtHttpRequest*,QtHttpReply*)));
    server->start(8000);


    connect(&timer, SIGNAL(timeout()), this, SLOT(onTimer()));
    timer.start(1000);

    orders_changed = false;
    connection_status = false;
    link_count = 30;
}

DialogKiosk::~DialogKiosk()
{
    delete ui;
}

void DialogKiosk::onTimer(){
    if(IS_UI_LOCK){
        ui->GB_KIOSK->setEnabled(false);
    }else{
        ui->GB_KIOSK->setEnabled(true);
    }

    link_count++;

    if(link_count > 100){
        if(connection_status == true)
            plog->write("[KIOSK] Disconnected ");
        connection_status = false;
        SetLEColor(ui->LE_KIOSK_CONNECTION, COLOR_BAD);
    }else{
        connection_status = true;
        SetLEColor(ui->LE_KIOSK_CONNECTION, COLOR_GOOD);
    }

    if(orders_changed){
        orders_changed = false;

        ui->LW_ORDERS->clear();
        for(int i=0; i<orders.size(); i++){
            QString temp = orders[i].pin + " [" + orders[i].menu_id + "] " + orders[i].menu_name;
            ui->LW_ORDERS->addItem(temp);
        }
    }
}


void DialogKiosk::onRequestReply(QtHttpRequest *request, QtHttpReply *reply){
    QByteArray rcvData = request->getRawData();
    QJsonObject json_input = QJsonDocument::fromJson(rcvData).object();


    QString msgType = json_input["MSG_TYPE"].toString();

    if(msgType == "ORDER"){
        replyOrder(reply, json_input);
        qDebug() << json_input;
    }else if(msgType == "REQ_STATUS"){
        replyStatus(reply, json_input);
//        qDebug() << json_input;
    }
    link_count = 0;
}


void DialogKiosk::replyOrder(QtHttpReply *reply, QJsonObject json){
    QJsonObject json_output;
    json_output["MSG_TYPE"] = "CONFIRM";
    json_output["PIN"] = json["PIN"].toString();

    QJsonArray menu_array = json["MENU"].toArray();
    for(int i=0; i<menu_array.size(); i++){
        QJsonObject temp = menu_array[i].toObject();

        ST_RECIPE_INFO new_order;
        new_order.pin = json["PIN"].toString();
        new_order.menu_id = temp["MENU_ID"].toString();
        new_order.menu_name = temp["MENU_NAME"].toString();
        new_order.option = temp["OPTION"].toString();
        new_order.recipe = stock->menu[new_order.menu_id].recipe;
        orders.push_back(new_order);
        if(orders.size() > 20){
            orders.pop_front();
        }

        pschedule->list_waiting.push_back(new_order);
    }
    plog->write("[KIOSK] NEW ORDER IN : " +json["PIN"].toString());
    orders_changed = true;

//    ui->LE_PIN->setText(json["PIN"].toString());
//    ui->LE_BARCODE->setText(json["BARCODE"].toString());
//    QJsonArray menu_array = json["MENU"].toArray();
//    for(int i=0; i<menu_array.size(); i++){
//        QJsonObject temp = menu_array[i].toObject();
//        if(i==0){
//            ui->LE_MENU_ID_1->setText(temp["MENU_ID"].toString());
//            ui->LE_MENU_NAME_1->setText(temp["MENU_NAME"].toString());
//            ui->LE_MENU_OPTION_1->setText(temp["OPTION"].toString());
//        }else if(i==1){
//            ui->LE_MENU_ID_2->setText(temp["MENU_ID"].toString());
//            ui->LE_MENU_NAME_2->setText(temp["MENU_NAME"].toString());
//            ui->LE_MENU_OPTION_2->setText(temp["OPTION"].toString());
//        }else if(i==2){
//            ui->LE_MENU_ID_3->setText(temp["MENU_ID"].toString());
//            ui->LE_MENU_NAME_3->setText(temp["MENU_NAME"].toString());
//            ui->LE_MENU_OPTION_3->setText(temp["OPTION"].toString());
//        }
//    }

    QByteArray json_string = QJsonDocument(json_output).toJson();
    generalReply(reply, json_string);
}

void DialogKiosk::replyStatus(QtHttpReply *reply, QJsonObject json){
    QJsonObject json_output;
    json_output["MSG_TYPE"] = "REPLY_STATUS";
    json_output["READY"] = !block_order;
    if(ui->CB_FORCE_KIOSK->isChecked()){
        json_output["READY"] = !force_block_order;
    }

    stock->UpdateMenuAvailable();
    QJsonArray json_array;
    if(stock != NULL){
        QStringList key_list = stock->menu.keys();
        for(int i=0; i<key_list.size(); i++){
            QString key = key_list[i];
            QJsonObject json_temp;
            json_temp["MENU_ID"] = stock->menu[key].menu_id;
            json_temp["MENU_NAME"] = stock->menu[key].menu_name;
//            if(key == "0001" || key == "0007" ||  key == "1001" || key == "1007"){
//                json_temp["AVAILABLE"] = true;
//            }else{
//                json_temp["AVAILABLE"] = false;

//            }
            json_temp["AVAILABLE"] = stock->menu[key].available;
            json_array.push_back(json_temp);
        }
    }
    json_output["MENU"] = json_array;
//    qDebug() << json_array;

    QByteArray json_string = QJsonDocument(json_output).toJson();
    generalReply(reply, json_string);
}


void DialogKiosk::generalReply(QtHttpReply *reply, QByteArray post_data){
    QByteArray postDataSize = QByteArray::number(post_data.size());

    reply->addHeader(QtHttpHeader::ContentType, QByteArrayLiteral("application/json"));
    reply->addHeader(QtHttpHeader::ContentLength, postDataSize);
    reply->addHeader(QtHttpHeader::Connection, QByteArrayLiteral("Keep-Alive"));
    reply->addHeader(QtHttpHeader::AcceptEncoding, QByteArrayLiteral("gzip, deflate"));
    reply->addHeader(QtHttpHeader::AcceptLanguage, QByteArrayLiteral("ko-KR,en,*"));

    reply->appendRawData(post_data);
    emit reply->requestSendHeaders();
    emit reply->requestSendData();
}


void DialogKiosk::setStock(DialogStock *_stock){
    stock = _stock;
}

void DialogKiosk::on_BTN_FORCE_ORDER_BLOCK_clicked(){
    force_block_order = true;
    if(ui->CB_FORCE_KIOSK->isChecked()){
        plog->write("[UI OPERATION - KIOSK] 키오스크 강제 적용 - 주문차단");
    }
}
void DialogKiosk::on_BTN_FORCE_ORDER_PASS_clicked(){
    force_block_order = false;
    if(ui->CB_FORCE_KIOSK->isChecked()){
        plog->write("[UI OPERATION - KIOSK] 키오스크 강제 적용 - 주문허용");
    }
}

void DialogKiosk::on_CB_FORCE_KIOSK_clicked(bool checked){
    if(checked == true){
        plog->write("[UI OPERATION - KIOSK] 키오스크 강제 적용 시작");
    }else{
        plog->write("[UI OPERATION - KIOSK] 키오스크 강제 적용 종료");
    }
}
