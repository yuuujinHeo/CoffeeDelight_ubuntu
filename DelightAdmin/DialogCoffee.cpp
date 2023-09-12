#include "DialogCoffee.h"
#include "ui_DialogCoffee.h"

DialogCoffee::DialogCoffee(QWidget *parent, DialogStock *_stock) :
    QDialog(parent), stock(_stock),
    ui(new Ui::DialogCoffee)
{
    ui->setupUi(this);

    SetComboBox();

    coffee_command_flag = false;
    status = MACHINE_NOT_CONNECTED;
    beverage_state = BEVERAGE_NONE;
    cleaning_state = CLEANING_NONE;
    machine_error.clear();
    return_value = RETURN_NONE;
    stepRequestStatus = COMMAND_SYS_CLEANING;
    last_send_msg = "";
    queue_CMD.clear();
    queue_Status.clear();
    isRinseafterMilk = false;
    last_made_beverage = 1;


    db = QSqlDatabase::addDatabase("QSQLITE", "DB_LOADCELL2");
    db.setDatabaseName(DB_NAME_LOADCELL);
    db.open();


    timeout_after_clean = 0;

    connect(&socket, SIGNAL(connected()), this, SLOT(onConnected()));
    connect(&socket, SIGNAL(disconnected()), this, SLOT(onDisconnected()));
    connect(this, SIGNAL(gotError()),this, SLOT(onGotError()));
    connect(&sendMsgTimer, SIGNAL(timeout()), this, SLOT(onSendMsg()));
    sendMsgTimer.start(1000);
    connect(&timer, SIGNAL(timeout()), this, SLOT(onTimer()));
    timer.start(200);



    qDebug() << "version : " << socket.version();
}

DialogCoffee::~DialogCoffee()
{
    socket.close();
    machine_error.clear();
    queue_CMD.clear();
    queue_Status.clear();
    sendMsgTimer.stop();
    delete ui;
}


void DialogCoffee::SetComboBox(){
    coffee_desc_btn = stock->coffee_desc_btn;
    QStringList keys = coffee_desc_btn.keys();
    for(int i=0; i<keys.size(); i++){
        ui->CB_LIST->addItem(keys[i]);
    }
}

void DialogCoffee::onTimer(){
    static int filt_milk = 0;

    if(IS_UI_LOCK){
        ui->GB_COFFEE->setEnabled(false);
    }else{
        ui->GB_COFFEE->setEnabled(true);
    }

//    if(ui->RB_RINSE_ON->isChecked()){
//        isRinseafterMilk = true;
//    }else{
//        isRinseafterMilk = false;
//    }
    if(ui->CB_MILK_LOCK->isChecked()){
        ui->BTN_LC_SET_SCALE_1->setEnabled(false);
        ui->LE_LC_SET_SCALE_1->setEnabled(false);
        ui->BTN_LC_SET_SCALE_2->setEnabled(false);
        ui->LE_LC_SET_SCALE_2->setEnabled(false);
        ui->BTN_LC_SET_SCALE_3->setEnabled(false);
        ui->LE_LC_SET_SCALE_3->setEnabled(false);
        ui->BTN_LC_SET_SCALE_4->setEnabled(false);
        ui->LE_LC_SET_SCALE_4->setEnabled(false);
    }else{

        ui->BTN_LC_SET_SCALE_1->setEnabled(true);
        ui->LE_LC_SET_SCALE_1->setEnabled(true);
        ui->BTN_LC_SET_SCALE_2->setEnabled(true);
        ui->LE_LC_SET_SCALE_2->setEnabled(true);
        ui->BTN_LC_SET_SCALE_3->setEnabled(true);
        ui->LE_LC_SET_SCALE_3->setEnabled(true);
        ui->BTN_LC_SET_SCALE_4->setEnabled(true);
        ui->LE_LC_SET_SCALE_4->setEnabled(true);
    }

    if(status == MACHINE_NOT_CONNECTED){
        SetLEColor(ui->LE_COFFEE_CONNECTION, COLOR_BAD);
    }else{
        SetLEColor(ui->LE_COFFEE_CONNECTION, COLOR_GOOD);
    }



    SetLEColor(ui->LE_MACHINE_STATUS_NOT_CONNECTED, COLOR_NONE);
    SetLEColor(ui->LE_MACHINE_STATUS_PREPAREING, COLOR_NONE);
    SetLEColor(ui->LE_MACHINE_STATUS_ERROR_OCCURED, COLOR_NONE);
    SetLEColor(ui->LE_MACHINE_STATUS_ON_READY, COLOR_NONE);
    SetLEColor(ui->LE_MACHINE_STATUS_MAKING, COLOR_NONE);
    SetLEColor(ui->LE_MACHINE_STATUS_SYS_CLEANING, COLOR_NONE);
    SetLEColor(ui->LE_MACHINE_STATUS_MILK_CLEANING, COLOR_NONE);
    SetLEColor(ui->LE_MACHINE_STATUS_MILK_REPLACING, COLOR_NONE);
    if(status == MACHINE_NOT_CONNECTED){
        SetLEColor(ui->LE_MACHINE_STATUS_NOT_CONNECTED, COLOR_BAD);
    }else if(status == MACHINE_NOT_READY){
        SetLEColor(ui->LE_MACHINE_STATUS_PREPAREING, COLOR_BAD);
    }else if(status == MACHINE_ERROR_OCCURRED){
        SetLEColor(ui->LE_MACHINE_STATUS_ERROR_OCCURED, COLOR_BAD);
    }else if(status == MACHINE_READY){
        SetLEColor(ui->LE_MACHINE_STATUS_ON_READY, COLOR_BLUE);
    }else if(status == MACHINE_MAKING_BEVERAGE){
        SetLEColor(ui->LE_MACHINE_STATUS_MAKING, COLOR_BLUE);
    }else if(status == MACHINE_SYSTEM_CLEANING){
        SetLEColor(ui->LE_MACHINE_STATUS_SYS_CLEANING, COLOR_WEAKBAD);
    }else if(status == MACHINE_MILK_CLEANING){
        SetLEColor(ui->LE_MACHINE_STATUS_MILK_CLEANING, COLOR_WEAKBAD);
    }else if(status == MACHINE_MILK_REPLACEMENT){
        SetLEColor(ui->LE_MACHINE_STATUS_MILK_REPLACING, COLOR_WEAKBAD);
    }
//    if(machine_error.size() > 0){
//        ui->LE_MACHINE_STATUS_ERROR_OCCURED->setText(QString().sprintf("%d", machine_error[0]));
//    }else{
//        ui->LE_MACHINE_STATUS_ERROR_OCCURED->setText("");
//    }

    int syscleantime = Machine.dueTimeSysClean;
    int milkcleantime = Machine.dueTimeMilkClean;
    int milkreplacetime = Machine.dueTimeMilkReplace;

    if(syscleantime < 0){
        ui->LE_SYS_CLEAN_TIME_HOUR->setText("-");
        ui->LE_SYS_CLEAN_TIME_MINUTE->setText("-");
        ui->LE_SYS_CLEAN_TIME_SECOND->setText("-");
    }else{
        int hour = syscleantime/3600;
        int min = (syscleantime-hour*3600)/60;
        int sec = syscleantime%60;
        ui->LE_SYS_CLEAN_TIME_HOUR->setText(QString().sprintf("%d", hour));
        ui->LE_SYS_CLEAN_TIME_MINUTE->setText(QString().sprintf("%d", min));
        ui->LE_SYS_CLEAN_TIME_SECOND->setText(QString().sprintf("%d", sec));
    }

    if(milkcleantime < 0){
        ui->LE_MILK_CLEAN_TIME_HOUR->setText("-");
        ui->LE_MILK_CLEAN_TIME_MINUTE->setText("-");
        ui->LE_MILK_CLEAN_TIME_SECOND->setText("-");
    }else{
        int hour = milkcleantime/3600;
        int min = (milkcleantime-hour*3600)/60;
        int sec = milkcleantime%60;
        ui->LE_MILK_CLEAN_TIME_HOUR->setText(QString().sprintf("%d", hour));
        ui->LE_MILK_CLEAN_TIME_MINUTE->setText(QString().sprintf("%d", min));
        ui->LE_MILK_CLEAN_TIME_SECOND->setText(QString().sprintf("%d", sec));
    }

    if(milkreplacetime < 0){
        ui->LE_MILK_REPLACE_TIME_HOUR->setText("-");
        ui->LE_MILK_REPLACE_TIME_MINUTE->setText("-");
        ui->LE_MILK_REPLACE_TIME_SECOND->setText("-");
    }else{
        int hour = milkreplacetime/3600;
        int min = (milkreplacetime-hour*3600)/60;
        int sec = milkreplacetime%60;
        ui->LE_MILK_REPLACE_TIME_HOUR->setText(QString().sprintf("%d", hour));
        ui->LE_MILK_REPLACE_TIME_MINUTE->setText(QString().sprintf("%d", min));
        ui->LE_MILK_REPLACE_TIME_SECOND->setText(QString().sprintf("%d", sec));
    }

    if(timeout_after_clean != 0)
        timeout_after_clean--;



    ui->LE_LC_RAW_1->setText(QString().sprintf("%d", MILK_DATA[0].loadcell_raw[0]));
    ui->LE_LC_RAW_2->setText(QString().sprintf("%d", MILK_DATA[0].loadcell_raw[1]));
    ui->LE_LC_RAW_3->setText(QString().sprintf("%d", MILK_DATA[0].loadcell_raw[2]));
    ui->LE_LC_RAW_4->setText(QString().sprintf("%d", MILK_DATA[0].loadcell_raw[3]));

    ui->LE_LC_SCALE_1->setText(QString().sprintf("%d", LOADCELL_SCALE_MILK_1));
    ui->LE_LC_SCALE_2->setText(QString().sprintf("%d", LOADCELL_SCALE_MILK_2));
    ui->LE_LC_SCALE_3->setText(QString().sprintf("%d", LOADCELL_SCALE_MILK_3));
    ui->LE_LC_SCALE_4->setText(QString().sprintf("%d", LOADCELL_SCALE_MILK_4));

    ui->LE_LC_INITIAL_1->setText(QString().sprintf("%d", LOADCELL_INITIAL_MILK_1));
    ui->LE_LC_INITIAL_2->setText(QString().sprintf("%d", LOADCELL_INITIAL_MILK_2));
    ui->LE_LC_INITIAL_3->setText(QString().sprintf("%d", LOADCELL_INITIAL_MILK_3));
    ui->LE_LC_INITIAL_4->setText(QString().sprintf("%d", LOADCELL_INITIAL_MILK_4));

    int weight_1 = (MILK_DATA[0].loadcell_raw[0]-LOADCELL_INITIAL_MILK_1)/LOADCELL_SCALE_MILK_1;
    int weight_2 = (MILK_DATA[0].loadcell_raw[1]-LOADCELL_INITIAL_MILK_2)/LOADCELL_SCALE_MILK_2;
    int weight_3 = (MILK_DATA[0].loadcell_raw[2]-LOADCELL_INITIAL_MILK_3)/LOADCELL_SCALE_MILK_3;
    int weight_4 = (MILK_DATA[0].loadcell_raw[3]-LOADCELL_INITIAL_MILK_4)/LOADCELL_SCALE_MILK_4;
    ui->LE_LC_WEIGHT_1->setText(QString().sprintf("%d", weight_1));
    ui->LE_LC_WEIGHT_2->setText(QString().sprintf("%d", weight_2));
    ui->LE_LC_WEIGHT_3->setText(QString().sprintf("%d", weight_3));
    ui->LE_LC_WEIGHT_4->setText(QString().sprintf("%d", weight_4));

    int milk_weight = (weight_1+weight_2+weight_3+weight_4);
    filt_milk = (filt_milk*9+milk_weight)/10;
    ui->LE_MILK_WEIGHT->setText(QString().sprintf("%.1fkg", filt_milk/1000.0));
//    stock->SetStock("MILK", 20000);//filt_milk);
}

void DialogCoffee::connect_server(QString _ip, QString _port){
    if(status == MACHINE_NOT_CONNECTED){
        QString url_str = "ws://";
        url_str +=_ip;
        url_str += ":";
        url_str += _port;
        socket.open(QUrl(url_str));
    }else{
        qDebug() << "already connected";
    }
}

bool DialogCoffee::isConnectedServer(){
    if(status == MACHINE_NOT_CONNECTED)
        return false;
    else
        return true;
}


void DialogCoffee::requestCurrentStatus(){
    QJsonObject json;
    QJsonDocument json_doc;
    QString json_str;

    if(status != MACHINE_NOT_CONNECTED && queue_Status.size() == 0){
        // 시스템 클리닝(약 1주일, 5분소요, 사람이 직접 해야함)
        if(stepRequestStatus == COMMAND_SYS_CLEANING){
//            qDebug() << "Push requestState : syscl";
            json["function"] = "getSystemCleaningState";
            json_doc = QJsonDocument(json);
            json_str = QString(json_doc.toJson());
            queue_Status.append(json_str);
        }

        // 우유 클리닝(약 3일, 8분소요, 사람이 직접 해야함)
        if(stepRequestStatus == COMMAND_MILK_CLEANING){
//            qDebug() << "Push requestState : milkcl";
            json["function"] = "getMilkCleaningState";
            json_doc = QJsonDocument(json);
            json_str = QString(json_doc.toJson());
            queue_Status.append(json_str);
        }

        // 우유 재충전(2시간, 15-20초소요, 자동)
        if(stepRequestStatus == COMMAND_MILK_REPLACEMENT){
//            qDebug() << "Push requestState : milkre";
            json["function"] = "getMilkReplacementState";
            json_doc = QJsonDocument(json);
            json_str = QString(json_doc.toJson());
            queue_Status.append(json_str);
        }
    }
}

void DialogCoffee::makeBeverage(int _recipe){
        sendCommand("startBeverage",_recipe);
        last_made_beverage = _recipe;
        qDebug() << "make coffee : " << _recipe;
        coffee_command_flag = true;
        beverage_state = BEVERAGE_READY;
}

void DialogCoffee::stopBeverage(){
    sendCommand("stoppBeverage");
    beverage_state = BEVERAGE_FORCED_STOP;
}

void DialogCoffee::startCleaning(int _method){
    switch(_method){
    case COMMAND_SYS_CLEANING:
        sendCommand("startSystemCleaning");
        cleaning_state = CLEANING_READY;
        break;
    case COMMAND_MILK_CLEANING:
        sendCommand("startMilkCleaning");
        cleaning_state = CLEANING_READY;
        break;
    case COMMAND_MILK_REPLACEMENT:
        sendCommand("startMilkReplacement");
        cleaning_state = CLEANING_READY;
        break;
    case COMMAND_FOAMER_RINSING:
        sendCommand("startFoamerRinsing");
        cleaning_state = CLEANING_READY;
        break;
    }
}

void DialogCoffee::requestError(bool _onoff){
    if(_onoff == true){
        sendCommand("startPushErrors");
    }else{
        sendCommand("stoppPushErrors");
    }
}

void DialogCoffee::requestErrorCount(){
    sendCommand("getErrorActiveCount");
}

void DialogCoffee::requestActiveError(){
    sendCommand("getErrorActive");
}

void DialogCoffee::ErrorClear(int _errCode){
    QJsonObject json;
    json["function"] = "clearError";
    json["a_iErrorCode"] = _errCode;
    json["a_iClear"] = 1;
    QJsonDocument json_doc(json);
    QString json_str(json_doc.toJson());
    queue_CMD.append(json_str);
}

Machine_Status DialogCoffee::getMachineStatus(){
    return Machine;
}
int DialogCoffee::getCurrentStatus(){
    return status;
}
int DialogCoffee::getBeverageState(){
    return beverage_state;
}
int DialogCoffee::getCleaningState(){
    return cleaning_state;
}
QList<int> DialogCoffee::getMachineError(){
    return machine_error;
}
int DialogCoffee::getReturnValue(){
    return return_value;
}









void DialogCoffee::sendCommand(QString _function){
    QJsonObject json;
    json["function"] = _function;
    QJsonDocument json_doc(json);
    QString json_str(json_doc.toJson());
    queue_CMD.append(json_str);
}
void DialogCoffee::sendCommand(QString _function, int _recipe){
    QJsonObject json;
    json["function"] = _function;

    //Recipe Num
    json["a_iBtnNbr"] = _recipe;

    //DON'T CHANGE BELOW!!!!!!!
    json["a_iBarista"] = "1";
    json["a_iDecaf"] = "0";
    json["a_iSML"] = "1";
    json["a_iMilktype"] = "0";
    json["a_iSirupType"] = "0";
    json["a_iSirupSML"] = "1";
    json["a_iBeanPortioner"] = "0";
    json["a_iCupSizeAdj"] = "100";
    json["a_strToken"] = "";
    //

    QJsonDocument json_doc(json);
    QString json_str(json_doc.toJson());
    queue_CMD.append(json_str);
}
void DialogCoffee::requestStatus(QString _function){
    QJsonObject json;
    json["function"] = _function;
    QJsonDocument json_doc(json);
    QString json_str(json_doc.toJson());
    qDebug() << "SendMessage : " << json_str;
    queue_Status.append(json_str);
}

int DialogCoffee::hasError(int _errCode){
    for(int i=0;i<machine_error.size();i++){
        if(machine_error[i] == _errCode)
            return i;
    }
    return -1;
}



void DialogCoffee::onConnected(){
    connect(&socket, SIGNAL(textMessageReceived(QString)), this, SLOT(onReceivedMsg(QString)));
    plog->write("[COFFEE] CONNECTED TO SERVER");

    Machine.dueTimeSysClean = -1;
    Machine.dueTimeMilkClean = -1;
    Machine.dueTimeMilkReplace = -1;

    status = MACHINE_READY;
    emit connected();
}
void DialogCoffee::onDisconnected(){
    if(status != MACHINE_NOT_CONNECTED){
        plog->write("[COFFEE] DISCONNECTED TO SERVER");
    }
    socket.close();
    status = MACHINE_NOT_CONNECTED;
    emit disconnected();
}

void DialogCoffee::onSendMsg(){
    static unsigned int ttt = 0;
    ttt++;
    // 연결이 안되어 있으면 연결 시도
    if(status == MACHINE_NOT_CONNECTED){
        if(ttt%5 == 0){
            connect_server(WMF_IP_ADDR, "25000");
        }
    }else{
        // 주기적 상태 체크
        if(ttt%20 == 0){
            requestCurrentStatus();
        }
        //에러 발생 시 status변경
        if(machine_error.size() > 0)
            status = MACHINE_ERROR_OCCURRED;

        //자동 청소 중일 때 status변경
        if(status != MACHINE_NOT_CONNECTED){
            if(Machine.dueTimeSysClean == 0){
                cleaning_state = CLEANING_AUTO_START;
                status = MACHINE_SYSTEM_CLEANING;
            }else if(Machine.dueTimeMilkClean == 0){
                cleaning_state = CLEANING_AUTO_START;
                status = MACHINE_MILK_CLEANING;
            }else if(Machine.dueTimeMilkReplace < 40 && Machine.dueTimeMilkReplace > -1){//check need
                if(cleaning_state == CLEANING_NONE || cleaning_state == CLEANING_DONE){
                    cleaning_state = CLEANING_AUTO_START;
                    plog->write("[COFFEE] COFFEE RINSE !!!!!!!!!!!!"+QString::number(Machine.dueTimeMilkReplace));
                    status = MACHINE_MILK_REPLACEMENT;
                }
            }else{
                if(cleaning_state == CLEANING_AUTO_START){
                    plog->write("[COFFEE] COFFEE RINSE DONE !!!!!!!!!!!!"+QString::number(status));
                    cleaning_state = CLEANING_DONE;
                    timeout_after_clean = 60000/200;
                    status = MACHINE_READY;
                }
            }
        }

        // 연결 되어 있으면 queue안의 msg를 웹소켓으로 보냄
        // 한 번에 한 개의 msg만 보내고 이에 대한 return이 들어올 때까지 대기
        if(return_value != RETURN_WAITING){
            // command 전송이 우선순위 높음
            if(!queue_CMD.isEmpty()){
                qDebug() << "Send Command : " << queue_CMD[0];
                last_send_msg = queue_CMD[0];
                socket.sendTextMessage(queue_CMD[0]);
                queue_CMD.pop_front();
                return_value = RETURN_WAITING;
            }else if(!queue_Status.isEmpty()){
//                qDebug() << "Request Status : " << queue_Status[0];
                socket.sendTextMessage(queue_Status[0]);
                last_send_msg = queue_Status[0];
                queue_Status.pop_front();
                return_value = RETURN_WAITING;
            }
        }
        //보낸 msg에 대한 return이 일정 시간내 들어오지 않으면 timeout발생
        if(return_value == RETURN_WAITING){
            timeout_count++;

            if(timeout_count > 10*2){//10sec
                plog->write("[COFFEE] RETURN TIMEOUT : "+last_send_msg);
                return_value = RETURN_TIMEOUT;
            }
        }
    }
}

void DialogCoffee::onReceivedMsg(QString message){
    QJsonArray ArrayJson;
    QJsonObject ObjectJson;

    //msg 수신하면 timeout_count 초기화
    timeout_count = 0;

    // 메시지 파싱(QJsonArray -> QJsonObject)
    ArrayJson = QJsonDocument::fromJson(message.toUtf8()).array();
    foreach (const QJsonValue & value, ArrayJson) {
        QJsonObject obj = value.toObject();
        QString key = obj.keys().first();
        QJsonValue keyvalue = obj[key];

        //동일한 key값이 들어오면 key0, key00, key000으로 저장
        while(ObjectJson.contains(key)){
            key += "0";
        }
        ObjectJson.insert(key, keyvalue);
    }




    //각 function별 처리
    //************************************************************************* 시스템 클리닝 상태 요청
    if(ObjectJson["function"].toString() ==         "getSystemCleaningState"){
        //다음 요청할 command
        stepRequestStatus = COMMAND_MILK_CLEANING;

        //System Cleaning 강제시작 남은 시간
        Machine.dueTimeSysClean = ObjectJson["dueInSeconds"].toInt();

        return_value = ObjectJson["returnvalue"].toInt();

    //************************************************************************* 우유 클리닝 상태 요청
    }else if(ObjectJson["function"].toString() ==    "getMilkCleaningState"){
        //다음 요청할 command
        stepRequestStatus = COMMAND_MILK_REPLACEMENT;

        //Milk Cleaning 강제시작 남은 시간
        Machine.dueTimeMilkClean = ObjectJson["dueInSeconds"].toInt();
        return_value = ObjectJson["returnvalue"].toInt();

    //************************************************************************* 우유 재충전 상태 요청
    }else if(ObjectJson["function"].toString() ==    "getMilkReplacementState"){
        //다음 요청할 command
        stepRequestStatus = COMMAND_SYS_CLEANING;

        //Milk Replacement 강제시작 남은 시간
        Machine.dueTimeMilkReplace = ObjectJson["dueInSeconds"].toInt();
        return_value = ObjectJson["returnvalue"].toInt();

    //************************************************************************* 음료 추출 실행
    }else if(ObjectJson["function"].toString() ==    "startBeverage"){

        qDebug() << "Received Msg : " << ObjectJson;

        if(coffee_command_flag == true){
            coffee_command_flag = false;
        }

        //returnvalue가 있으면
        if(ObjectJson.find("returnvalue") != ObjectJson.end()){
            return_value = ObjectJson["returnvalue"].toInt();

            //정상적으로 실행되지 못함 -> 명령 중단
            if(return_value != 0){
                plog->write("[COFFEE START BEVERAGE ERROR] RETURN VALUE " + QString::number(return_value));
                beverage_state = BEVERAGE_NONE;
                emit gotError();
            }
        }

        //음료 추출 시작
        if(ObjectJson["Rcp State"].toInt() == 99 || ObjectJson["Rcp State"].toInt() == -99){
            beverage_state = BEVERAGE_DISPENSING;
            status = MACHINE_MAKING_BEVERAGE;

        //음료 추출 종료
        }else if(ObjectJson["Rcp State"].toInt() == 9){
            beverage_state = BEVERAGE_DONE;
            status = MACHINE_READY;

        //음료 추출 종료 but 문제 발생
        }else if(ObjectJson["Rcp State"].toInt() == -9){
            beverage_state = BEVERAGE_DONE_BUT_NOT_READY;
            status = MACHINE_NOT_READY;
        }

    //************************************************************************* 음료 추출 중단
    }else if(ObjectJson["function"].toString() ==    "stoppBeverage"){

        qDebug() << "Received Msg : " << ObjectJson;

        //returnvalue가 있으면
        if(ObjectJson.find("returnvalue") != ObjectJson.end()){
            return_value = ObjectJson["returnvalue"].toInt();

            //정상적으로 실행되지 못함 -> 명령 중단
            if(return_value != 0){
                beverage_state = BEVERAGE_NONE;
                emit gotError();
            }
        }

    //*************************************************************************  시스템 청소 실행
    }else if(ObjectJson["function"].toString() ==    "startSystemCleaning"){

        qDebug() << "Received Msg : " << ObjectJson;

        //returnvalue가 있으면
        if(ObjectJson.find("returnvalue") != ObjectJson.end()){
            ;
        }

        if(ObjectJson["CleanStepID"].toInt() == 0){
            status = MACHINE_READY;
        }

    //************************************************************************* 우유 재충전 실행
    }else if(ObjectJson["function"].toString() ==    "startMilkReplacement"){

        qDebug() << "Received Msg : " << ObjectJson;

        //returnvalue가 있으면
        if(ObjectJson.find("returnvalue") != ObjectJson.end()){
            return_value = ObjectJson["returnvalue"].toInt();

            //우유 재충전
            if(return_value == 0){
                status = MACHINE_MILK_REPLACEMENT;

            //정상실행 못함 -> 명령 중단
            }else{
                cleaning_state = CLEANING_NONE;
                emit gotError();
            }
        }

        //우유 재충전 시작
        if(ObjectJson["Rcp State"].toInt() == -99){
            cleaning_state = CLEANING_START;

        //우유 재충전 종료
        }else if(ObjectJson["Rcp State"].toInt() == 9){
            cleaning_state = CLEANING_DONE;
            status = MACHINE_READY;

        //우유 재충전 종료 but 문제 발생
        }else if(ObjectJson["Rcp State"].toInt() == -9){
            cleaning_state = CLEANING_DONE;
//            status = MACHINE_NOT_READY;
            status = MACHINE_READY;
        }

    //************************************************************************* 현재 에러 개수 반환
    }else if(ObjectJson["function"].toString() == "startFoamerRinsing"){

        qDebug() << "Received Msg : " << ObjectJson;

        //returnvalue가 있으면
        if(ObjectJson.find("returnvalue") != ObjectJson.end()){
            return_value = ObjectJson["returnvalue"].toInt();
            //정상실행 못함 -> 명령 중단
            if(return_value == 0){

            }else{
                cleaning_state = CLEANING_NONE;
                emit gotError();
            }

        }

        //우유 재충전 시작
        if(ObjectJson["Rcp State"].toInt() == -99){
            cleaning_state = CLEANING_START;

        //우유 재충전 종료
        }else if(ObjectJson["Rcp State"].toInt() == 9){
            plog->write("[COFFEE] FOAMER RINSE DONE");
            cleaning_state = CLEANING_DONE;
        //우유 재충전 종료 but 문제 발생
        }else if(ObjectJson["Rcp State"].toInt() == -9){
            cleaning_state = CLEANING_DONE;
        }
    //************************************************************************* 현재 에러 개수 반환
    }else if(ObjectJson["function"].toString() == "getErrorActiveCount"){

        qDebug() << "Received Msg : " << ObjectJson;

        return_value = RETURN_ACCEPT_SUCCESS;

        //에러가 있으면
        if(ObjectJson["returnvalue"].toInt() != 0){
            status = MACHINE_ERROR_OCCURRED;
        }

    //************************************************************************* 에러 변동 사항 반환
    }else if(ObjectJson["function"].toString() == "startPushErrors"){

        qDebug() << "Received Msg : " << ObjectJson;

        //새로운 에러 발생
        if(ObjectJson["Info"].toString() == "new Error"){

            machine_error.append(ObjectJson["ErrorCode"].toInt());

        //기존 에러 사라짐
        }else if(ObjectJson["Info"].toString() == "gone Error"){

            int index = hasError(ObjectJson["ErrorCode"].toInt());
            if(index > 0){
                machine_error.removeAt(index);
            }

        //현재 존재하는 모든 에러들(pushError 켜진 도중에 다시 startPushErrors 보내면)
        }else if(ObjectJson["Info"].toString() == "currentErrors"){
            machine_error.clear();
            //ErrorCode, ErrorCode0, ErrorCode00 등 (최대 10개까지..늘려도 상관 없음)
            //이미 machine_error에 등록되어 있는 에러인지 확인 후 추가
            QString key = "ErrorCode";
            for(int i = 0; i < 10; i++){
                if(ObjectJson.find(key) != ObjectJson.end())
                    if(hasError(ObjectJson[key].toInt())<0)
                        machine_error.append(ObjectJson[key].toInt());
                else
                    break;

                key += "0";
            }
        }
        return_value = ObjectJson["returnvalue"].toInt();
    }
}

void DialogCoffee::onGotError(){
    switch(return_value){
    case RETURN_OFFLINE:
    case RETURN_NOT_READY:
    case RETURN_NOT_INITIALIZED:
        status = MACHINE_NOT_READY;
        break;
    case RETURN_BLOCKING_ERROR:
        status = MACHINE_ERROR_OCCURRED;
        break;
    case RETURN_OTHER_BEVERAGE_RUNNING:
    case RETURN_FUNCTION_BUSY:
        break;
    case RETURN_START_NOT_SUCCESS:
    case RETURN_PARAMETER_ERROR:
    case RETURN_NO_BEVERAGE_RUNNING:
    case RETURN_FUNCTION_NOT_AVAILABLE:
        break;
    case RETURN_NOT_SUCCESS:
        break;
    }
}

void DialogCoffee::on_BTN_REQUEST_BUTTON_LIST_clicked(){
    sendCommand("getBeverageButtonList");
    plog->write("[UI OPERATION - COFFEE] 버튼 리스트 요청");
}

void DialogCoffee::on_BTN_DRINK_OUT_clicked(){
    QString btn = coffee_desc_btn[ui->CB_LIST->currentText()];
    makeBeverage(btn.toInt());
    qDebug() << "coffee dispense "<<btn.toInt();
    plog->write("[UI OPERATION - COFFEE] 투출 버튼");
}


int DialogCoffee::IsRefillMilkSoon(){
    if(status == MACHINE_MILK_REPLACEMENT){
        return true;
    }
    int milk_time = Machine.dueTimeMilkReplace;
    if(milk_time >= 0 && milk_time < 180){
        return true;
    }
    return false;
}

void DialogCoffee::on_BTN_LC_SET_SCALE_1_clicked(){
    int temp = ui->LE_LC_SET_SCALE_1->text().toInt();
    if(temp < 1)
        temp = 1;
    LOADCELL_SCALE_MILK_1 = temp;
    QSqlQuery query(db);
    QString update_str = QString().sprintf("UPDATE Table_Loadcell SET scale = %d WHERE uses = \'MILK_1\'", LOADCELL_SCALE_MILK_1);
    query.exec(update_str);
}

void DialogCoffee::on_BTN_LC_SET_SCALE_2_clicked(){
    int temp = ui->LE_LC_SET_SCALE_2->text().toInt();
    if(temp < 1)
        temp = 1;
    LOADCELL_SCALE_MILK_2 = temp;
    QSqlQuery query(db);
    QString update_str = QString().sprintf("UPDATE Table_Loadcell SET scale = %d WHERE uses = \'MILK_2\'", LOADCELL_SCALE_MILK_2);
    query.exec(update_str);
}

void DialogCoffee::on_BTN_LC_SET_SCALE_3_clicked(){
    int temp = ui->LE_LC_SET_SCALE_3->text().toInt();
    if(temp < 1)
        temp = 1;
    LOADCELL_SCALE_MILK_3 = temp;
    QSqlQuery query(db);
    QString update_str = QString().sprintf("UPDATE Table_Loadcell SET scale = %d WHERE uses = \'MILK_3\'", LOADCELL_SCALE_MILK_3);
    query.exec(update_str);
}

void DialogCoffee::on_BTN_LC_SET_SCALE_4_clicked(){
    int temp = ui->LE_LC_SET_SCALE_4->text().toInt();
    if(temp < 1)
        temp = 1;
    LOADCELL_SCALE_MILK_4 = temp;
    QSqlQuery query(db);
    QString update_str = QString().sprintf("UPDATE Table_Loadcell SET scale = %d WHERE uses = \'MILK_4\'", LOADCELL_SCALE_MILK_4);
    query.exec(update_str);
}

void DialogCoffee::on_BTN_LC_SET_INITIAL_1_clicked(){
    LOADCELL_INITIAL_MILK_1 = ui->LE_LC_SET_INITIAL_1->text().toInt();
    QSqlQuery query(db);
    QString update_str = QString().sprintf("UPDATE Table_Loadcell SET initial = %d WHERE uses = \'MILK_1\'", LOADCELL_INITIAL_MILK_1);
    query.exec(update_str);
}

void DialogCoffee::on_BTN_LC_SET_INITIAL_2_clicked(){
    LOADCELL_INITIAL_MILK_2 = ui->LE_LC_SET_INITIAL_2->text().toInt();
    QSqlQuery query(db);
    QString update_str = QString().sprintf("UPDATE Table_Loadcell SET initial = %d WHERE uses = \'MILK_2\'", LOADCELL_INITIAL_MILK_2);
    query.exec(update_str);
}

void DialogCoffee::on_BTN_LC_SET_INITIAL_3_clicked(){
    LOADCELL_INITIAL_MILK_3 = ui->LE_LC_SET_INITIAL_3->text().toInt();
    QSqlQuery query(db);
    QString update_str = QString().sprintf("UPDATE Table_Loadcell SET initial = %d WHERE uses = \'MILK_3\'", LOADCELL_INITIAL_MILK_3);
    query.exec(update_str);
}

void DialogCoffee::on_BTN_LC_SET_INITIAL_4_clicked(){
    LOADCELL_INITIAL_MILK_4 = ui->LE_LC_SET_INITIAL_4->text().toInt();
    QSqlQuery query(db);
    QString update_str = QString().sprintf("UPDATE Table_Loadcell SET initial = %d WHERE uses = \'MILK_4\'", LOADCELL_INITIAL_MILK_4);
    query.exec(update_str);
}

void DialogCoffee::on_BTN_LC_GET_INITIAL_clicked(){
    ui->LE_LC_SET_INITIAL_1->setText(ui->LE_LC_RAW_1->text());
    ui->LE_LC_SET_INITIAL_2->setText(ui->LE_LC_RAW_2->text());
    ui->LE_LC_SET_INITIAL_3->setText(ui->LE_LC_RAW_3->text());
    ui->LE_LC_SET_INITIAL_4->setText(ui->LE_LC_RAW_4->text());
}
