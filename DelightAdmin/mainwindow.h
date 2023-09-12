#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QMessageBox>

#include <QtSql/QSql>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>

#include "GlobalHeader.h"

#include "RBLAN2CAN.h"

#include "DialogSetting.h"
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
#include "displaydialog.h"

#include "Scheduler.h"
#include "Logger.h"


#define MAINWINDOW_LOOP_TIME        200

#define DB_NAME_MAIL    "DB/mail"


typedef struct{
    QString mail;
    QString user;
    int level;
}MAIL_INFO;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    RBLAN2CAN           *lan;

    DialogSetting       *setting;
    DialogCupDispenser  *cup;
    DialogIceDispenser  *ice;
    DialogSodaDispenser *soda;
    DialogCoffee        *coffee;
    DialogSyrup         *syrup;
    DialogRobot         *robot;
    DialogMonitor       *monitor;
    DialogDoor          *door;
    DialogBarcode       *barcode;
    DialogOutlet        *outlet;
    DialogIcecream      *icecream;
    DialogHotDispenser  *hot;
    DialogKiosk         *kiosk;
    DialogStock         *stock;
    DisplayDialog       *display;

    Scheduler           *schedule;
    Logger              *logger;


    void LoadLoadcellDB();
    void LoadMailDB();

    void ChangeDeviceDialog(DEVICE_DIALOG_ID id);

    void CoreLogic_Initializing();
    void CoreLogic_Operating();

    void UpdatePlatformOperationInfo();

    void Update_Dev_CupInfo();
    void Update_Dev_IceInfo();
    void Update_Dev_SodaInfo();
    void Update_Dev_CoffeeInfo();
    void Update_Dev_SyrupInfo();
    void Update_Dev_RobotInfo();
    void Update_Dev_MonitorInfo();
    void Update_Dev_DoorInfo();
    void Update_Dev_BarcodeInfo();
    void Update_Dev_OutletInfo();
    void Update_Dev_Icecream();
    void Update_Dev_HotInfo();
    void Update_Dev_KioskInfo();
    void Update_Dev_StockInfo();


    void ClearForcedSuperError();
    int CheckDeviceConnection();


    void SendMail(QString content);
    QVector<MAIL_INFO> mail_infos;


public slots:
    void onTimer();

private slots:
    void on_BTN_DEV_INFO_CUP_clicked();
    void on_BTN_DEV_INFO_SODA_clicked();
    void on_BTN_DEV_INFO_COFFEE_clicked();
    void on_BTN_DEV_INFO_ICE_1_clicked();
    void on_BTN_DEV_INFO_ICE_2_clicked();
    void on_BTN_DEV_INFO_ROBOT_clicked();
    void on_BTN_DEV_INFO_SYRUP_clicked();
    void on_BTN_DEV_INFO_MONITOR_clicked();
    void on_BTN_DEV_INFO_DOOR_clicked();
    void on_BTN_DEV_INFO_BARCODE_clicked();
    void on_BTN_DEV_INFO_OUTLET_clicked();
    void on_BTN_DEV_INFO_ICECREAM_clicked();
    void on_BTN_DEV_INFO_HOT_clicked();
    void on_BTN_DEV_INFO_KIOSK_clicked();
    void on_BTN_DEV_INFO_STOCK_clicked();

    void on_BTN_DO_INITIALIZING_clicked();
    void on_BTN_DO_OPERATING_clicked();
    void on_BTN_STOP_OPERATING_clicked();
    void on_BTN_CANCEL_STOP_clicked();
    void on_BTN_SETTING_clicked();

    void on_BTN_EXIT_clicked();
    void on_BTN_UI_LOCK_clicked();
    void on_BTN_UI_UNLOCK_clicked();

    void on_BTN_CUP_ADD_DONE_clicked();

    void on_BTN_RESUME_clicked();

private:
    Ui::MainWindow *ui;
    QTimer  timer;

    QSqlDatabase    db;
};

#endif // MAINWINDOW_H
