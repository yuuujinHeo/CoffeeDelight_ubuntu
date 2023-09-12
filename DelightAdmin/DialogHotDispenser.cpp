#include "DialogHotDispenser.h"
#include "ui_DialogHotDispenser.h"
#include "RBLAN2CAN.h"

extern RBLAN2CAN *plan;

DialogHotDispenser::DialogHotDispenser(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogHotDispenser)
{
    ui->setupUi(this);

    connect(&timer, SIGNAL(timeout()), this, SLOT(onTimer()));
    timer.start(200);
}

DialogHotDispenser::~DialogHotDispenser()
{
    delete ui;
}

void DialogHotDispenser::onTimer(){
    static unsigned int tt = 0;
    tt++;

    if(IS_UI_LOCK){
        ui->GB_HOT->setEnabled(false);
    }else{
        ui->GB_HOT->setEnabled(true);
    }

    if(plan->sockConnectionStatus == false){
        SetLEColor(ui->LE_HOT_CONNECTION, COLOR_UNDETERMINED);

        ui->LE_DISPENSE_COUNT->setText("-");
        ui->LE_LAST_DISPENSE_ERROR->setText("-");
        ui->LE_OP_STATE->setText("-");

        ui->LE_LOADCELL_WEIGHT->setText("-");
        ui->LE_LOADCELL_SCALE->setText("-");
        ui->LE_LOADCELL_ERROR->setText("-");

        ui->LE_LOADCELL_WEIGHT_2->setText("-");
        ui->LE_LOADCELL_SCALE_2->setText("-");
        ui->LE_LOADCELL_ERROR_2->setText("-");
    }else{
        if(HOT_DATA[0].connection_status == 1){
            SetLEColor(ui->LE_HOT_CONNECTION, COLOR_GOOD);
        }else{
            SetLEColor(ui->LE_HOT_CONNECTION, COLOR_BAD);
        }


        ui->LE_DISPENSE_COUNT->setText(QString().sprintf("%d", HOT_DATA[0].out_count));

        if(HOT_DATA[0].last_error == 0){
            ui->LE_LAST_DISPENSE_ERROR->setText("정상");
            hot_error = "정상";
        }else{
            ui->LE_LAST_DISPENSE_ERROR->setText(QString().sprintf("E%d", HOT_DATA[0].last_error));
            hot_error = QString().sprintf("E%d", HOT_DATA[0].last_error);
        }

        if(HOT_DATA[0].out_state == 0){
            ui->LE_OP_STATE->setText("준비");
        }else{
            ui->LE_OP_STATE->setText("동작중");
        }


        ui->LE_LOADCELL_WEIGHT->setText(QString().sprintf("%d", HOT_DATA[0].loadcell[0].value));
        ui->LE_LOADCELL_SCALE->setText(QString().sprintf("%d", HOT_DATA[0].loadcell[0].calib_param));

        ui->LE_LOADCELL_WEIGHT_2->setText(QString().sprintf("%d", HOT_DATA[0].loadcell[1].value));
        ui->LE_LOADCELL_SCALE_2->setText(QString().sprintf("%d", HOT_DATA[0].loadcell[1].calib_param));

        ui->LE_LOADCELL_TOTAL_WEIGHT->setText(QString().sprintf("%d", LoadcellValue()));

        if(HOT_DATA[0].loadcell[0].error == 0){
            SetLEColor(ui->LE_LOADCELL_ERROR, COLOR_GOOD);
            ui->LE_LOADCELL_ERROR->setText("정상");
        }else{
            SetLEColor(ui->LE_LOADCELL_ERROR, COLOR_BAD);
            ui->LE_LOADCELL_ERROR->setText("에러");
        }

        if(HOT_DATA[0].loadcell[1].error == 0){
            SetLEColor(ui->LE_LOADCELL_ERROR_2, COLOR_GOOD);
            ui->LE_LOADCELL_ERROR_2->setText("정상");
        }else{
            SetLEColor(ui->LE_LOADCELL_ERROR_2, COLOR_BAD);
            ui->LE_LOADCELL_ERROR_2->setText("에러");
        }



        if(ui->CB_SCALE_TEST->isChecked()){
            // scale test mode
        }else{
            // loadcell scale factor set
            if(tt%5 == 0 && HOT_DATA[0].connection_status == 1){
                if(HOT_DATA[0].loadcell[0].calib_param != LOADCELL_SCALE_HOT_1){
                    SetCalibParam(LOADCELL_SCALE_HOT_1, 0);
                }
                if(HOT_DATA[0].loadcell[1].calib_param != LOADCELL_SCALE_HOT_2){
                    SetCalibParam(LOADCELL_SCALE_HOT_2, 1);
                }
            }
        }
    }
}


void DialogHotDispenser::DispenseHotByTime(int time_ms){
    HOT_DATA[0].prev_out_count = HOT_DATA[0].out_count;
    int time_100ms = time_ms/100;
    plan->SendControlData(DEV_SEND_ID_HOT_DISPENSER, 0, 0x00, 0, time_100ms);
}
void DialogHotDispenser::DispenseHotByWeight(int weight_g){
    HOT_DATA[0].prev_out_count = HOT_DATA[0].out_count;
    plan->SendControlData(DEV_SEND_ID_HOT_DISPENSER, 0, 0x01, 0, weight_g);
}
void DialogHotDispenser::Tare(){
    plan->SendControlData(DEV_SEND_ID_HOT_DISPENSER, 0, 0x02, 0, 0);
}

void DialogHotDispenser::SetCalibParam(int scale, int loadcell_id){
    plan->SendControlData(DEV_SEND_ID_HOT_DISPENSER, 0, 0x03, loadcell_id, scale);
}

int DialogHotDispenser::LoadcellValue(){
    return (HOT_DATA[0].loadcell[0].value + HOT_DATA[0].loadcell[1].value)/2;
}


void DialogHotDispenser::on_BTN_DISPENSE_HOT_BY_TIME_clicked(){
    DispenseHotByTime(ui->LE_OUT_TIME->text().toFloat()*1000.0);
    plog->write("[UI OPERATION - HOT] 온수 배출(시간)");
}

void DialogHotDispenser::on_BTN_DISPENSE_HOT_BY_WEIGHT_clicked(){
    DispenseHotByWeight(ui->LE_OUT_WEIGHT->text().toInt());
    plog->write("[UI OPERATION - HOT] 온수 배출(무게)");
}

void DialogHotDispenser::on_BTN_TARE_clicked(){
    Tare();
    plog->write("[UI OPERATION - HOT] 영점");
}

void DialogHotDispenser::on_BTN_SET_SCALE_clicked(){
    SetCalibParam(ui->LE_LOADCELL_SET_SCALE->text().toInt(), 0);
    plog->write("[UI OPERATION - HOT] Scale1 설정");
}

void DialogHotDispenser::on_BTN_SET_SCALE_2_clicked(){
    SetCalibParam(ui->LE_LOADCELL_SET_SCALE_2->text().toInt(), 1);
    plog->write("[UI OPERATION - HOT] Scale2 설정");
}
