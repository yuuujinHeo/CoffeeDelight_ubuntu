#include "DialogDoor.h"
#include "ui_DialogDoor.h"
#include "RBLAN2CAN.h"

extern RBLAN2CAN *plan;
extern Logger *plog;

DialogDoor::DialogDoor(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogDoor)
{
    ui->setupUi(this);

    connect(&timer, SIGNAL(timeout()), this, SLOT(onTimer()));
    timer.start(200);
}

DialogDoor::~DialogDoor()
{
    delete ui;
}

void DialogDoor::onTimer(){
    if(IS_UI_LOCK){
        ui->GB_DOOR->setEnabled(false);
    }else{
        ui->GB_DOOR->setEnabled(true);
    }

    if(plan->sockConnectionStatus == false){
        SetLEColor(ui->LE_DOOR_CONNECTION, COLOR_UNDETERMINED);

        SetLEColor(ui->LE_DOOR_OPENED, COLOR_UNDETERMINED);
        SetLEColor(ui->LE_DOOR_CLOSED, COLOR_UNDETERMINED);

        ui->LB_SENSOR_A->setText("-");
        ui->LB_SENSOR_B->setText("-");
    }else{
        if(DOOR_DATA[0].connection_status == 1){
            SetLEColor(ui->LE_DOOR_CONNECTION, COLOR_GOOD);

            if(DOOR_DATA[0].platform_sensorA == 1 && DOOR_DATA[0].platform_sensorB == 1){
                SetLEColor(ui->LE_DOOR_OPENED, COLOR_NONE);
                SetLEColor(ui->LE_DOOR_CLOSED, COLOR_BLUE);
            }else{
                SetLEColor(ui->LE_DOOR_OPENED, COLOR_BLUE);
                SetLEColor(ui->LE_DOOR_CLOSED, COLOR_NONE);
            }
            if(DOOR_DATA[0].platform_sensorA == 1){
                ui->LB_SENSOR_A->setText("닫힘");
            }else{
                ui->LB_SENSOR_A->setText("열림");
            }
            if(DOOR_DATA[0].platform_sensorB == 1){
                ui->LB_SENSOR_B->setText("닫힘");
            }else{
                ui->LB_SENSOR_B->setText("열림");
            }
        }else{
            SetLEColor(ui->LE_DOOR_CONNECTION, COLOR_BAD);

            SetLEColor(ui->LE_DOOR_OPENED, COLOR_UNDETERMINED);
            SetLEColor(ui->LE_DOOR_CLOSED, COLOR_UNDETERMINED);

            ui->LB_SENSOR_A->setText("-");
            ui->LB_SENSOR_B->setText("-");
        }
    }
}


int DialogDoor::IsPlatformClosed(){
    if(DOOR_DATA[0].platform_sensorA == 1 && DOOR_DATA[0].platform_sensorB == 1){
        return true;
    }else{
        return false;
    }
}
