#ifndef DIALOGICEDISPENSER_H
#define DIALOGICEDISPENSER_H

#include <QDialog>
#include <QTimer>

#include "DialogStock.h"
#include "GlobalHeader.h"


namespace Ui {
class DialogIceDispenser;
}

class DialogIceDispenser : public QDialog
{
    Q_OBJECT

public:
    explicit DialogIceDispenser(QWidget *parent = nullptr, DialogStock *_stock = nullptr);
    ~DialogIceDispenser();

    void DispenseIceWater(int target, int ice_time_ms, int water_time_ms);
    void ChangeCommMode(int target, int comm_mode, int cup_ignore);
    void ClearStatus(int target);
    void SetTimeout(int target, int timeout);
    void Reboot(int target);
    void SetAmbientTemperature(int target, int tempL, int tempH);

    QString ice_1_error;
    QString ice_2_error;


    int IsIceDev_1_Available();
    int IsIceDev_2_Available();


    void CheckFatalError();

    int IsIceAvailable(int dev);


    int FATAL_INFO_ICE_CONNECTION_ERROR_1;
    int FATAL_INFO_ICE_CONNECTION_ERROR_2;
    int FATAL_INFO_ICE_DEVICE_ERROR_1;
    int FATAL_INFO_ICE_DEVICE_ERROR_2;

    int FORCE_FATAL_ERROR_ICE_CONNECTION;
    int FORCE_FATAL_ERROR_ICE_DEVICE;


public slots:
    void onTimer();

private slots:
    void on_BTN_ICE_TEST_ICE_OUT_clicked();

    void on_BTN_ICE_CHANGE_COMM_MODE_clicked();

    void on_BTN_ICE_TEST_STATUS_CLEAR_clicked();

    void on_BTN_ICE_CHANGE_ICE_OUT_TIME_clicked();

    void on_BTN_ICE_TEST_REBOOT_clicked();

    void on_BTN_ICE_CHANGE_AMBIENT_TEMP_clicked();

    void on_BTN_ICE_TEST_ICE_OUT_2_clicked();

    void on_BTN_ICE_CHANGE_COMM_MODE_2_clicked();

    void on_BTN_ICE_CHANGE_ICE_OUT_TIME_2_clicked();

    void on_BTN_ICE_TEST_REBOOT_2_clicked();

    void on_BTN_ICE_TEST_STATUS_CLEAR_2_clicked();

    void on_BTN_ICE_CHANGE_AMBIENT_TEMP_2_clicked();

private:
    Ui::DialogIceDispenser *ui;
    QTimer timer;

    DialogStock *stock;
};

#endif // DIALOGICEDISPENSER_H
