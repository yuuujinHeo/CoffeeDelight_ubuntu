#include "DialogSetting.h"
#include "ui_DialogSetting.h"

#include "Scheduler.h"

extern Scheduler *pschedule;
extern RBLAN2CAN *plan;

DialogSetting::DialogSetting(QWidget *parent, DialogStock *_stock, DialogRobot *_robot, DialogCupDispenser *_cup, DialogHotDispenser *_hot,
                             DialogCoffee *_coffee, DialogSodaDispenser *_soda, DialogIceDispenser *_ice,
                             DialogSyrup *_syrup, DialogIcecream *_icecream, DialogOutlet *_outlet,
                             DialogBarcode *_barcode, DialogMonitor *_monitor) :
    QDialog(parent), stock(_stock), robot(_robot), cup(_cup) , hot(_hot),
    coffee(_coffee), soda(_soda), ice(_ice),
    syrup(_syrup), icecream(_icecream), outlet(_outlet),
    barcode(_barcode), monitor(_monitor),
    ui(new Ui::DialogSetting)
{
    ui->setupUi(this);
    //TEST MENU
    QStringList tableHeader;
    ui->TW_TEST_MENU->setColumnCount(2);
    tableHeader << "메뉴번호" << "메뉴명";
    ui->TW_TEST_MENU->setHorizontalHeaderLabels(tableHeader);
    ui->TW_TEST_MENU->setRowCount(0);
    qDebug() << stock->menu.size();

    order_count = 0;

    QStringList menu_ids = stock->menu.keys();
    for(int i=0; i<stock->menu.size(); i++){
        if(stock->menu[menu_ids[i]].recipe.size() > 2){
            ui->TW_TEST_MENU->setRowCount(ui->TW_TEST_MENU->rowCount()+1);
            ui->TW_TEST_MENU->setItem(ui->TW_TEST_MENU->rowCount()-1,0,new QTableWidgetItem(menu_ids[i]));
            ui->TW_TEST_MENU->setItem(ui->TW_TEST_MENU->rowCount()-1,1,new QTableWidgetItem(stock->menu[menu_ids[i]].menu_name));
        }
    }

    connect(&timer, SIGNAL(timeout()), this, SLOT(onTimer()));
    timer.start(400);
}

DialogSetting::~DialogSetting()
{
    delete ui;
}

void DialogSetting::onTimer(){
    if(stock->IsDeviceError("COFFEE")){
        SetLEColor(ui->LE_DEVICE_ERROR_COFFEE, COLOR_BAD);
    }else{
        SetLEColor(ui->LE_DEVICE_ERROR_COFFEE, COLOR_GOOD);
    }

    if(stock->IsDeviceError("ICE_1")){
        SetLEColor(ui->LE_DEVICE_ERROR_ICE_1, COLOR_BAD);
    }else{
        SetLEColor(ui->LE_DEVICE_ERROR_ICE_1, COLOR_GOOD);
    }
    if(stock->IsDeviceError("ICE_2")){
        SetLEColor(ui->LE_DEVICE_ERROR_ICE_2, COLOR_BAD);
    }else{
        SetLEColor(ui->LE_DEVICE_ERROR_ICE_2, COLOR_GOOD);
    }

    if(stock->IsDeviceError("PAPER_CUP_1")){
        SetLEColor(ui->LE_DEVICE_ERROR_PAPER_CUP_1, COLOR_BAD);
    }else{
        SetLEColor(ui->LE_DEVICE_ERROR_PAPER_CUP_1, COLOR_GOOD);
    }
    if(stock->IsDeviceError("PAPER_CUP_2")){
        SetLEColor(ui->LE_DEVICE_ERROR_PAPER_CUP_2, COLOR_BAD);
    }else{
        SetLEColor(ui->LE_DEVICE_ERROR_PAPER_CUP_2, COLOR_GOOD);
    }

    if(stock->IsDeviceError("PET_CUP_1")){
        SetLEColor(ui->LE_DEVICE_ERROR_PET_CUP_1, COLOR_BAD);
    }else{
        SetLEColor(ui->LE_DEVICE_ERROR_PET_CUP_1, COLOR_GOOD);
    }
    if(stock->IsDeviceError("PET_CUP_2")){
        SetLEColor(ui->LE_DEVICE_ERROR_PET_CUP_2, COLOR_BAD);
    }else{
        SetLEColor(ui->LE_DEVICE_ERROR_PET_CUP_2, COLOR_GOOD);
    }

    if(stock->IsDeviceError("HOT_WATER")){
        SetLEColor(ui->LE_DEVICE_ERROR_HOT_WATER, COLOR_BAD);
    }else{
        SetLEColor(ui->LE_DEVICE_ERROR_HOT_WATER, COLOR_GOOD);
    }

    if(stock->IsDeviceError("SODA")){
        SetLEColor(ui->LE_DEVICE_ERROR_SODA, COLOR_BAD);
    }else{
        SetLEColor(ui->LE_DEVICE_ERROR_SODA, COLOR_GOOD);
    }

    if(stock->IsDeviceError("ICECREAM")){
        SetLEColor(ui->LE_DEVICE_ERROR_ICECREAM, COLOR_BAD);
    }else{
        SetLEColor(ui->LE_DEVICE_ERROR_ICECREAM, COLOR_GOOD);
    }


    if(SUPER_FATAL_ERROR_PLATFORM_OPEN == 1){
        SetLEColor(ui->LE_SUPER_STOP_PLATFORM_OPEN, COLOR_BAD);
    }else{
        SetLEColor(ui->LE_SUPER_STOP_PLATFORM_OPEN, COLOR_GOOD);
    }
    if(plan->SUPER_FATAL_ERROR_CONNECTION_OF_LAN2CAN == 1){
        SetLEColor(ui->LE_SUPER_STOP_BOARD_CONNECTION, COLOR_BAD);
    }else{
        SetLEColor(ui->LE_SUPER_STOP_BOARD_CONNECTION, COLOR_GOOD);
    }
    if(robot->SUPER_FATAL_ERROR_ROBOT_DATA == 1){
        SetLEColor(ui->LE_SUPER_STOP_ROBOT_DATA, COLOR_BAD);
    }else{
        SetLEColor(ui->LE_SUPER_STOP_ROBOT_DATA, COLOR_GOOD);
    }
    if(robot->SUPER_FATAL_ERROR_ROBOT_MISS_COMMAND_WORKING_CHECK == 1){
        SetLEColor(ui->LE_SUPER_STOP_ROBOT_MISS_COMMAND_CHECK, COLOR_BAD);
    }else{
        SetLEColor(ui->LE_SUPER_STOP_ROBOT_MISS_COMMAND_CHECK, COLOR_GOOD);
    }
    if(outlet->SUPER_FATAL_ERROR_OUTLET_CONNECTION == 1){
        SetLEColor(ui->LE_SUPER_STOP_OUTLET_CONNECTION, COLOR_BAD);
    }else{
        SetLEColor(ui->LE_SUPER_STOP_OUTLET_CONNECTION, COLOR_GOOD);
    }
    if(outlet->SUPER_FATAL_ERROR_OUTLET_CONTROL == 1){
        SetLEColor(ui->LE_SUPER_STOP_OUTLET_CONTROL, COLOR_BAD);
    }else{
        SetLEColor(ui->LE_SUPER_STOP_OUTLET_CONTROL, COLOR_GOOD);
    }
    if(outlet->SUPER_FATAL_ERROR_OUTLET_SENSOR == 1){
        SetLEColor(ui->LE_SUPER_STOP_OUTLET_SENSOR, COLOR_BAD);
    }else{
        SetLEColor(ui->LE_SUPER_STOP_OUTLET_SENSOR, COLOR_GOOD);
    }
}

void DialogSetting::on_BTN_TEST_ORDER_clicked()
{
    if(ui->TW_TEST_MENU->currentRow() > -1){
        QString menu_id = ui->TW_TEST_MENU->item(ui->TW_TEST_MENU->currentRow(),0)->text();
        if(stock->menu.find(menu_id) != stock->menu.end()){
            ST_RECIPE_INFO new_order;
            new_order.pin = "9999";
            new_order.recipe = stock->menu[menu_id].recipe;
            new_order.menu_id = stock->menu[menu_id].menu_id;
            new_order.menu_name = stock->menu[menu_id].menu_name;
            if(ui->CB_ADD_SHOT->isChecked()){
                new_order.option = "001";
            }else{
                new_order.option = "000";
            }
            if(stock->menu[menu_id].available){
                qDebug() << "임의 테스트 주문: " << new_order.menu_name;
                pschedule->list_waiting.push_back(new_order);
                plog->write("[UI OPERATION - SETTING] 임의 테스트 주문 " + new_order.menu_name);
            }else{
                QMessageBox::information(this, "재고 부족 에러", "해당하는 메뉴를 제조할 재고가 부족합니다.");
            }
        }else{
            QMessageBox::information(this, "메뉴 ID 에러", "해당하는 메뉴ID가 존재하지 않습니다.");
        }
    }
}

void DialogSetting::on_BTN_ERROR_CLEAR_COFFEE_clicked(){
    stock->ClearDeviceError("COFFEE");
    plog->write("[UI OPERATION - SETTING] Error Clear COFFEE");
}
void DialogSetting::on_BTN_ERROR_CLEAR_ICE_1_clicked(){
    stock->ClearDeviceError("ICE_1");
    plog->write("[UI OPERATION - SETTING] Error Clear ICE_1");
}
void DialogSetting::on_BTN_ERROR_CLEAR_ICE_2_clicked(){
    stock->ClearDeviceError("ICE_2");
    plog->write("[UI OPERATION - SETTING] Error Clear ICE_2");
}
void DialogSetting::on_BTN_ERROR_CLEAR_PAPER_CUP_1_clicked(){
    stock->ClearDeviceError("PAPER_CUP_1");
    plog->write("[UI OPERATION - SETTING] Error Clear PAPER_CUP_1");
}
void DialogSetting::on_BTN_ERROR_CLEAR_PAPER_CUP_2_clicked(){
    stock->ClearDeviceError("PAPER_CUP_2");
    plog->write("[UI OPERATION - SETTING] Error Clear PAPER_CUP_2");
}
void DialogSetting::on_BTN_ERROR_CLEAR_PET_CUP_1_clicked(){
    stock->ClearDeviceError("PET_CUP_1");
    plog->write("[UI OPERATION - SETTING] Error Clear PET_CUP_1");
}
void DialogSetting::on_BTN_ERROR_CLEAR_PET_CUP_2_clicked(){
    stock->ClearDeviceError("PET_CUP_2");
    plog->write("[UI OPERATION - SETTING] Error Clear PET_CUP_2");
}
void DialogSetting::on_BTN_ERROR_CLEAR_HOT_WATER_clicked(){
    stock->ClearDeviceError("HOT_WATER");
    plog->write("[UI OPERATION - SETTING] Error Clear HOT_WATER");
}
void DialogSetting::on_BTN_ERROR_CLEAR_SODA_clicked(){
    stock->ClearDeviceError("SODA");
    plog->write("[UI OPERATION - SETTING] Error Clear SODA");
}
void DialogSetting::on_BTN_ERROR_CLEAR_ICECREAM_clicked(){
    stock->ClearDeviceError("ICECREAM");
    plog->write("[UI OPERATION - SETTING] Error Clear ICECREAM");
}


void DialogSetting::on_BTN_DB_RELOAD_clicked()
{

}

void DialogSetting::on_BTN_DB_TEST_CLEAR_clicked()
{
}

void DialogSetting::on_BTN_DB_TEST_ADD_clicked()
{

}

void DialogSetting::on_BTN_TEST_ORDER_2_clicked()
{
}
