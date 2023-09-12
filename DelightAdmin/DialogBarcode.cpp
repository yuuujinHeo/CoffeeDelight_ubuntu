#include "DialogBarcode.h"
#include "ui_DialogBarcode.h"
#include "RBLAN2CAN.h"

extern RBLAN2CAN    *plan;

DialogBarcode::DialogBarcode(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogBarcode)
{
    ui->setupUi(this);

    NewInputNotification = false;
    NewBarcodePin = "";

    connect(&timer, SIGNAL(timeout()), this, SLOT(onTimer()));
    timer.start(200);
}

DialogBarcode::~DialogBarcode()
{
    delete ui;
}


void DialogBarcode::onTimer(){
    if(IS_UI_LOCK){
        ui->GB_BARCODE->setEnabled(false);
    }else{
        ui->GB_BARCODE->setEnabled(true);
    }

    if(plan->sockConnectionStatus == false){
        SetLEColor(ui->LE_BARCODE_CONNECTION, COLOR_UNDETERMINED);
    }else{
        if(BARCODE_DATA[0].connection_status == 1){
            SetLEColor(ui->LE_BARCODE_CONNECTION, COLOR_GOOD);
        }else{
            SetLEColor(ui->LE_BARCODE_CONNECTION, COLOR_BAD);
        }

        ui->LE_BARCODE_COUNT->setText(QString().sprintf("%d", BARCODE_DATA[0].barcode_count));
        ui->LE_BARCODE_DATA->setText(QString().sprintf("%s", BARCODE_DATA[0].barcode_data));
//        ui->LE_BARCODE_DATA->setText(QString().sprintf("%s", NewBarcodePin));
    }


    if(BARCODE_DATA[0].barcode_count != BARCODE_DATA[0].prev_barcode_count){
        BARCODE_DATA[0].prev_barcode_count = BARCODE_DATA[0].barcode_count;

        NewBarcodePin = QString().sprintf("%s", BARCODE_DATA[0].barcode_data);
        NewInputNotification = true;
    }
}
