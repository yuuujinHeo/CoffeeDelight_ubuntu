#include "DialogSyrup.h"
#include "ui_DialogSyrup.h"
#include "RBLAN2CAN.h"

extern RBLAN2CAN *plan;
extern Logger *plog;

//static int syrup_table[] = {
//    0, 1, 2, 3, 4, 5, 6, 7,
//    10, 11, 12, 13, 14, 15, 16, 17
//};
//static int syrup_table[] = {
//    0, 1, 2, 3, 4, 5, 10, 10,
//    10, 10, 10, 10, 6, 10, 10, 7
//};

// 카페시럽(Syr1), 바닐라(Syr2), 헤이즐넛(Syr3), 카라멜(Syr4), 블루퀴라소(Syr12), 자몽(Syr6), 복숭아(Syr13), 진저레몬(Syr16)
//      A0           A1          A2            A3            A4             A5          A6             A7
//static int syrup_table[] = {
//    0, 1, 2, 3, 10, 5, 10, 10,
//    10, 10, 10, 4, 6, 10, 10, 7
//};
static int syrup_table[] = {
    0,1,2,3,4,5,6,7
};
DialogSyrup::DialogSyrup(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogSyrup)
{
    ui->setupUi(this);

    state_cleaning = 0;
    start_cleaning = false;

    connect(&timer, SIGNAL(timeout()), this, SLOT(onTimer()));
    timer.start(200);
}

DialogSyrup::~DialogSyrup()
{
    delete ui;
}

void DialogSyrup::onTimer(){
    static unsigned int tt = 0;
    static unsigned int count_cleaning=0;
    tt++;

    if(IS_UI_LOCK){
        ui->GB_SYRUP->setEnabled(false);
    }else{
        ui->GB_SYRUP->setEnabled(true);
    }

    if(start_cleaning==true){
        static int syrup_index = 0;
        if(count_cleaning == 0){
            DispenseSyrupByTime(syrup_index++, ui->LE_SYRUP_OUT_TIME_2->text().toFloat()*1000.0);
        }

        if(count_cleaning > ui->LE_SYRUP_OUT_TIME_2->text().toFloat()*5 + 3){//5Hz , +600ms
            state_cleaning++;
            count_cleaning = 0;

            if(state_cleaning > 8){
                start_cleaning = false;
            }
        }else{
            count_cleaning++;
        }
    }
    if(plan->sockConnectionStatus == false){
        SetLEColor(ui->LE_SYRUP_CONNECTION, COLOR_UNDETERMINED);

        ui->LE_SYRUP_DISPENSE_COUNT->setText("-");
        ui->LE_LAST_DISPENSE_ERROR->setText("-");
        ui->LE_OP_STATE->setText("-");

        ui->LE_LOADCELL_WEIGHT->setText("-");
        ui->LE_LOADCELL_SCALE->setText("-");
        ui->LE_LOADCELL_ERROR->setText("-");
    }else{
        if(SYRUP_DATA[0].connection_status == 1){
            SetLEColor(ui->LE_SYRUP_CONNECTION, COLOR_GOOD);
        }else{
            SetLEColor(ui->LE_SYRUP_CONNECTION, COLOR_BAD);
        }


        ui->LE_SYRUP_DISPENSE_COUNT->setText(QString().sprintf("%d", SYRUP_DATA[0].out_count));

        if(SYRUP_DATA[0].last_error == 0){
            ui->LE_LAST_DISPENSE_ERROR->setText("정상");
            syrup_error = "정상";
        }else{
            ui->LE_LAST_DISPENSE_ERROR->setText(QString().sprintf("E%d", SYRUP_DATA[0].last_error));
            syrup_error = QString().sprintf("E%d", SYRUP_DATA[0].last_error);
        }

        if(SYRUP_DATA[0].out_state == 0){
            ui->LE_OP_STATE->setText("준비");
        }else{
            ui->LE_OP_STATE->setText("동작중");
        }


        ui->LE_LOADCELL_WEIGHT->setText(QString().sprintf("%d", SYRUP_DATA[0].loadcell.value));
        ui->LE_LOADCELL_SCALE->setText(QString().sprintf("%d", SYRUP_DATA[0].loadcell.calib_param));

        if(SYRUP_DATA[0].loadcell.error == 0){
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
            if(tt%5 == 0 && SYRUP_DATA[0].connection_status == 1){
                if(SYRUP_DATA[0].loadcell.calib_param != LOADCELL_SCALE_SYRUP){
                    SetCalibParam(LOADCELL_SCALE_SYRUP);
                }
            }
        }

    }
}


void DialogSyrup::DispenseSyrupByTime(int syrup_type, int time_ms){
    SYRUP_DATA[0].prev_out_count = SYRUP_DATA[0].out_count;
    int time_100ms = time_ms/100;
    plan->SendControlData(DEV_SEND_ID_SYRUP, 0, 0x00, syrup_table[syrup_type], time_100ms);
}
void DialogSyrup::DispenseSyrupByWeight(int syrup_type, int weight_g){
    SYRUP_DATA[0].prev_out_count = SYRUP_DATA[0].out_count;
    plan->SendControlData(DEV_SEND_ID_SYRUP, 0, 0x01, syrup_table[syrup_type], weight_g);
}
void DialogSyrup::Tare(){
    plan->SendControlData(DEV_SEND_ID_SYRUP, 0, 0x02, 0, 0);
}

void DialogSyrup::SetCalibParam(int scale){
    plan->SendControlData(DEV_SEND_ID_SYRUP, 0, 0x03, 0, scale);
}


int DialogSyrup::LoadcellValue(){
    return SYRUP_DATA[0].loadcell.value;
}


void DialogSyrup::on_BTN_DISPENSE_SYRUP_BY_TIME_1_clicked(){
    DispenseSyrupByTime(0, ui->LE_SYRUP_OUT_TIME->text().toFloat()*1000.0);
    plog->write("[UI OPERATION - SYRUP] 시럽1(시간)");
}
void DialogSyrup::on_BTN_DISPENSE_SYRUP_BY_TIME_2_clicked(){
    DispenseSyrupByTime(1, ui->LE_SYRUP_OUT_TIME->text().toFloat()*1000.0);
    plog->write("[UI OPERATION - SYRUP] 시럽2(시간)");
}
void DialogSyrup::on_BTN_DISPENSE_SYRUP_BY_TIME_3_clicked(){
    DispenseSyrupByTime(2, ui->LE_SYRUP_OUT_TIME->text().toFloat()*1000.0);
    plog->write("[UI OPERATION - SYRUP] 시럽3(시간)");
}
void DialogSyrup::on_BTN_DISPENSE_SYRUP_BY_TIME_4_clicked(){
    DispenseSyrupByTime(3, ui->LE_SYRUP_OUT_TIME->text().toFloat()*1000.0);
    plog->write("[UI OPERATION - SYRUP] 시럽4(시간)");
}
void DialogSyrup::on_BTN_DISPENSE_SYRUP_BY_TIME_5_clicked(){
    DispenseSyrupByTime(4, ui->LE_SYRUP_OUT_TIME->text().toFloat()*1000.0);
    plog->write("[UI OPERATION - SYRUP] 시럽5(시간)");
}
void DialogSyrup::on_BTN_DISPENSE_SYRUP_BY_TIME_6_clicked(){
    DispenseSyrupByTime(5, ui->LE_SYRUP_OUT_TIME->text().toFloat()*1000.0);
    plog->write("[UI OPERATION - SYRUP] 시럽6(시간)");
}
void DialogSyrup::on_BTN_DISPENSE_SYRUP_BY_TIME_7_clicked(){
    DispenseSyrupByTime(6, ui->LE_SYRUP_OUT_TIME->text().toFloat()*1000.0);
    plog->write("[UI OPERATION - SYRUP] 시럽7(시간)");
}
void DialogSyrup::on_BTN_DISPENSE_SYRUP_BY_TIME_8_clicked(){
    DispenseSyrupByTime(7, ui->LE_SYRUP_OUT_TIME->text().toFloat()*1000.0);
    plog->write("[UI OPERATION - SYRUP] 시럽8(시간)");
}

void DialogSyrup::on_BTN_DISPENSE_SYRUP_BY_WEIGHT_1_clicked(){
    DispenseSyrupByWeight(0, ui->LE_SYRUP_OUT_WEIGHT->text().toInt());
    plog->write("[UI OPERATION - SYRUP] 시럽1(무게)");
}
void DialogSyrup::on_BTN_DISPENSE_SYRUP_BY_WEIGHT_2_clicked(){
    DispenseSyrupByWeight(1, ui->LE_SYRUP_OUT_WEIGHT->text().toInt());
    plog->write("[UI OPERATION - SYRUP] 시럽2(무게)");
}
void DialogSyrup::on_BTN_DISPENSE_SYRUP_BY_WEIGHT_3_clicked(){
    DispenseSyrupByWeight(2, ui->LE_SYRUP_OUT_WEIGHT->text().toInt());
    plog->write("[UI OPERATION - SYRUP] 시럽3(무게)");
}
void DialogSyrup::on_BTN_DISPENSE_SYRUP_BY_WEIGHT_4_clicked(){
    DispenseSyrupByWeight(3, ui->LE_SYRUP_OUT_WEIGHT->text().toInt());
    plog->write("[UI OPERATION - SYRUP] 시럽4(무게)");
}
void DialogSyrup::on_BTN_DISPENSE_SYRUP_BY_WEIGHT_5_clicked(){
    DispenseSyrupByWeight(4, ui->LE_SYRUP_OUT_WEIGHT->text().toInt());
    plog->write("[UI OPERATION - SYRUP] 시럽5(무게)");
}
void DialogSyrup::on_BTN_DISPENSE_SYRUP_BY_WEIGHT_6_clicked(){
    DispenseSyrupByWeight(5, ui->LE_SYRUP_OUT_WEIGHT->text().toInt());
    plog->write("[UI OPERATION - SYRUP] 시럽6(무게)");
}
void DialogSyrup::on_BTN_DISPENSE_SYRUP_BY_WEIGHT_7_clicked(){
    DispenseSyrupByWeight(6, ui->LE_SYRUP_OUT_WEIGHT->text().toInt());
    plog->write("[UI OPERATION - SYRUP] 시럽7(무게)");
}
void DialogSyrup::on_BTN_DISPENSE_SYRUP_BY_WEIGHT_8_clicked(){
    DispenseSyrupByWeight(7, ui->LE_SYRUP_OUT_WEIGHT->text().toInt());
    plog->write("[UI OPERATION - SYRUP] 시럽8(무게)");
}

void DialogSyrup::on_BTN_TARE_clicked(){
    Tare();
    plog->write("[UI OPERATION - SYRUP] 영점");
}

void DialogSyrup::on_BTN_SET_SCALE_clicked(){
    plog->write("[USER INPUT] SYRUP SET SCALE : "+ui->LE_LOADCELL_SET_SCALE->text());
    SetCalibParam(ui->LE_LOADCELL_SET_SCALE->text().toInt());
}

void DialogSyrup::on_BTN_CLEANING_clicked()
{
    plog->write("[USER INPUT] START CLEANING SYRUP");
    state_cleaning = 0;
    start_cleaning = true;
}
