#ifndef DIALOGSETTING_H
#define DIALOGSETTING_H

#include <QDialog>
#include <QTimer>
#include <QMessageBox>

#include "DialogCupDispenser.h"
#include "DialogIceDispenser.h"
#include "DialogSodaDispenser.h"
#include "DialogCoffee.h"
#include "DialogSyrup.h"
#include "DialogRobot.h"
#include "DialogMonitor.h"
#include "DialogDoor.h"
#include "DialogBarcode.h"
#include "DialogOutlet.h"
#include "DialogIcecream.h"
#include "DialogHotDispenser.h"
#include "DialogKiosk.h"
#include "DialogStock.h"
#include "RBLAN2CAN.h"

#include "GlobalHeader.h"

namespace Ui {
class DialogSetting;
}

class DialogSetting : public QDialog
{
    Q_OBJECT

public:
    explicit DialogSetting(QWidget *parent = nullptr, DialogStock *_stock = nullptr, DialogRobot *_robot = nullptr, DialogCupDispenser *_cup = nullptr, DialogHotDispenser *_hot = nullptr,
                           DialogCoffee *_coffee = nullptr, DialogSodaDispenser *_soda = nullptr, DialogIceDispenser *_ice = nullptr,
                           DialogSyrup *_syrup = nullptr, DialogIcecream *_icecream = nullptr, DialogOutlet *_outlet = nullptr,
                           DialogBarcode *_barcode = nullptr, DialogMonitor *_monitor = nullptr);
    ~DialogSetting();

    int order_count;

public slots:
    void onTimer();

private slots:
    void on_BTN_TEST_ORDER_clicked();

    void on_BTN_ERROR_CLEAR_COFFEE_clicked();

    void on_BTN_ERROR_CLEAR_ICE_1_clicked();

    void on_BTN_ERROR_CLEAR_ICE_2_clicked();

    void on_BTN_ERROR_CLEAR_PAPER_CUP_1_clicked();

    void on_BTN_ERROR_CLEAR_PAPER_CUP_2_clicked();

    void on_BTN_ERROR_CLEAR_PET_CUP_1_clicked();

    void on_BTN_ERROR_CLEAR_PET_CUP_2_clicked();

    void on_BTN_ERROR_CLEAR_HOT_WATER_clicked();

    void on_BTN_ERROR_CLEAR_SODA_clicked();

    void on_BTN_ERROR_CLEAR_ICECREAM_clicked();


    void on_BTN_DB_RELOAD_clicked();

    void on_BTN_DB_TEST_CLEAR_clicked();

    void on_BTN_DB_TEST_ADD_clicked();

    void on_BTN_TEST_ORDER_2_clicked();

private:
    Ui::DialogSetting *ui;
    QTimer timer;


    DialogStock         *stock;
    DialogRobot         *robot;
    DialogCupDispenser  *cup;
    DialogHotDispenser  *hot;
    DialogCoffee        *coffee;
    DialogSodaDispenser *soda;
    DialogIceDispenser  *ice;
    DialogSyrup         *syrup;
    DialogIcecream      *icecream;
    DialogOutlet        *outlet;
    DialogBarcode       *barcode;
    DialogMonitor       *monitor;
};

#endif // DIALOGSETTING_H
