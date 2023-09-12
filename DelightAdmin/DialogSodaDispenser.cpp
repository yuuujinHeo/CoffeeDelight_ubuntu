#include "DialogSodaDispenser.h"
#include "ui_DialogSodaDispenser.h"
#include "RBLAN2CAN.h"

extern RBLAN2CAN *plan;

DialogSodaDispenser::DialogSodaDispenser(QWidget *parent, DialogStock *_stock) :
    QDialog(parent), stock(_stock),
    ui(new Ui::DialogSodaDispenser)
{
    ui->setupUi(this);

    connect(&timer, SIGNAL(timeout()), this, SLOT(onTimer()));
    timer.start(200);
}

DialogSodaDispenser::~DialogSodaDispenser()
{
    delete ui;
}

void DialogSodaDispenser::onTimer(){
    static unsigned int tt = 0;
    tt++;

    if(IS_UI_LOCK){
        ui->GB_SODA->setEnabled(false);
    }else{
        ui->GB_SODA->setEnabled(true);
    }

    if(plan->sockConnectionStatus == false){
        SetLEColor(ui->LE_SODA_CONNECTION, COLOR_UNDETERMINED);

        ui->LE_DISPENSE_COUNT->setText("-");
        ui->LE_LAST_DISPENSE_ERROR->setText("-");
        ui->LE_OP_STATE->setText("-");

        ui->LE_LOADCELL_WEIGHT->setText("-");
        ui->LE_LOADCELL_SCALE->setText("-");
        ui->LE_LOADCELL_ERROR->setText("-");
    }else{
        if(SODA_DATA[0].connection_status == 1){
            SetLEColor(ui->LE_SODA_CONNECTION, COLOR_GOOD);
        }else{
            SetLEColor(ui->LE_SODA_CONNECTION, COLOR_BAD);
        }




        ui->LE_DISPENSE_COUNT->setText(QString().sprintf("%d", SODA_DATA[0].out_count));

        if(SODA_DATA[0].last_error == 0){
            ui->LE_LAST_DISPENSE_ERROR->setText("정상");
            soda_error = "정상";
        }else{
            ui->LE_LAST_DISPENSE_ERROR->setText(QString().sprintf("E%d", SODA_DATA[0].last_error));
            soda_error = QString().sprintf("E%d", SODA_DATA[0].last_error);
        }

        if(SODA_DATA[0].out_state == 0){
            ui->LE_OP_STATE->setText("준비");
        }else{
            ui->LE_OP_STATE->setText("동작중");
        }


        ui->LE_LOADCELL_WEIGHT->setText(QString().sprintf("%d", SODA_DATA[0].loadcell[0].value));
        ui->LE_LOADCELL_SCALE->setText(QString().sprintf("%d", SODA_DATA[0].loadcell[0].calib_param));

        if(SODA_DATA[0].loadcell[0].error == 0){
            SetLEColor(ui->LE_LOADCELL_ERROR, COLOR_GOOD);
            ui->LE_LOADCELL_ERROR->setText("정상");
        }else{
            SetLEColor(ui->LE_LOADCELL_ERROR, COLOR_BAD);
            ui->LE_LOADCELL_ERROR->setText("에러");
        }


        if(ui->CB_SCALE_TEST->isChecked()){
            // scale test mode
        }else{
            // loadcell scale factor set
            if(tt%5 == 0 && SODA_DATA[0].connection_status == 1){
                if(SODA_DATA[0].loadcell[0].calib_param != LOADCELL_SCALE_SODA){
                    SetCalibParam(LOADCELL_SCALE_SODA);
                }
            }
        }
    }
}


void DialogSodaDispenser::DispenseSodaByTime(int time_ms){
    SODA_DATA[0].prev_out_count = SODA_DATA[0].out_count;
    int time_100ms = time_ms/100;
    plan->SendControlData(DEV_SEND_ID_SODA_DISPENSER, 0, 0x00, 0, time_100ms);
}
void DialogSodaDispenser::DispenseSodaByWeight(int weight_g){
    SODA_DATA[0].prev_out_count = SODA_DATA[0].out_count;
    plan->SendControlData(DEV_SEND_ID_SODA_DISPENSER, 0, 0x01, 0, weight_g);
}
void DialogSodaDispenser::Tare(){
    plan->SendControlData(DEV_SEND_ID_SODA_DISPENSER, 0, 0x02, 0, 0);
}

void DialogSodaDispenser::SetCalibParam(int scale){
    plan->SendControlData(DEV_SEND_ID_SODA_DISPENSER, 0, 0x03, 0, scale);
}


int DialogSodaDispenser::LoadcellValue(){
    return SODA_DATA[0].loadcell[0].value;
}


void DialogSodaDispenser::on_BTN_DISPENSE_SODA_BY_TIME_clicked(){
    DispenseSodaByTime(ui->LE_OUT_TIME->text().toFloat()*1000.0);
    plog->write("[UI OPERATION - SODA] 탄산수 배출(시간)");
}

void DialogSodaDispenser::on_BTN_DISPENSE_SODA_BY_WEIGHT_clicked(){
    DispenseSodaByWeight(ui->LE_OUT_WEIGHT->text().toInt());
    plog->write("[UI OPERATION - SODA] 탄산수 배출(무게)");
}

void DialogSodaDispenser::on_BTN_TARE_clicked(){
    Tare();
    plog->write("[UI OPERATION - SODA] 영점");
}

void DialogSodaDispenser::on_BTN_SET_SCALE_clicked(){
    SetCalibParam(ui->LE_LOADCELL_SET_SCALE->text().toInt());
    plog->write("[UI OPERATION - SODA] Scale 설정");
}
