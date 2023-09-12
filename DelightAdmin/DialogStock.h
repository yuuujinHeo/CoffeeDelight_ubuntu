#ifndef DIALOGSTOCK_H
#define DIALOGSTOCK_H

#include <QDialog>
#include <QTimer>

#include <QtSql/QSql>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>

#include <QDebug>
#include "GlobalHeader.h"



#define DB_NAME_RECIPE  "DB/recipe"

#define MILK_APPROXIMATION_USE_AMOUNT       200


namespace Ui {
class DialogStock;
}

class DialogStock : public QDialog
{
    Q_OBJECT

public:
    explicit DialogStock(QWidget *parent = nullptr);
    ~DialogStock();

    void LoadDatabase();
    void SetUIForm();
    void UpdateUI();


    void UseStock(QString stock_name, int amount);
    void UpdateStock(QString stock_name);
    void SetStock(QString stock_name, int amount);

    int GetStock(QString stock_name);
    void FillFull(QString stock_name);
    void FillHalf(QString stock_name);

    void SetDeviceError(QString stock_name);
    void ClearDeviceError(QString stock_name);
    int IsDeviceError(QString stock_name);

    void UpdateWaitingTime();
    void UpdateStockReserved();
    void UpdateMenuAvailable();

    bool IsMenuOptionAvailable(QString menu_id);


    QMap<QString, QString> coffee_key_btn;
    QMap<QString, QString> coffee_desc_btn;

    QMap<QString, ST_STOCK> stock;
    QMap<QString, ST_MENU>  menu;
    QMap<QString, V_RECIPE> recipe;

    int ice_rotate_1;
    int ice_rotate_2;

    int ApproximateWaitingTime;

public slots:
    void onTimer();

private slots:
    void on_BTN_CUP_HALF_1_clicked();

    void on_BTN_CUP_FULL_1_clicked();

    void on_BTN_CUP_HALF_2_clicked();

    void on_BTN_CUP_FULL_2_clicked();

    void on_BTN_CUP_HALF_3_clicked();

    void on_BTN_CUP_FULL_3_clicked();

    void on_BTN_CUP_HALF_4_clicked();

    void on_BTN_CUP_FULL_4_clicked();

    void on_BTN_SYRUP_REPLACE_1_clicked();

    void on_BTN_SYRUP_REPLACE_2_clicked();

    void on_BTN_SYRUP_REPLACE_3_clicked();

    void on_BTN_SYRUP_REPLACE_4_clicked();

    void on_BTN_SYRUP_REPLACE_5_clicked();

    void on_BTN_SYRUP_REPLACE_6_clicked();

    void on_BTN_SYRUP_REPLACE_7_clicked();

    void on_BTN_SYRUP_REPLACE_8_clicked();

    void on_BTN_SYRUP_REPLACE_9_clicked();

    void on_BTN_SYRUP_REPLACE_10_clicked();

    void on_BTN_SYRUP_REPLACE_11_clicked();

    void on_BTN_SYRUP_REPLACE_12_clicked();

    void on_BTN_SYRUP_REPLACE_13_clicked();

    void on_BTN_SYRUP_REPLACE_14_clicked();

    void on_BTN_SYRUP_REPLACE_15_clicked();

    void on_BTN_SYRUP_REPLACE_16_clicked();

    void on_BTN_SAUCE_REPLACE_1_clicked();

    void on_BTN_SAUCE_REPLACE_2_clicked();

    void on_BTN_SAUCE_REPLACE_3_clicked();

    void on_BTN_SAUCE_REPLACE_4_clicked();

    void on_BTN_SAUCE_REPLACE_5_clicked();

    void on_BTN_SAUCE_REPLACE_6_clicked();

    void on_BTN_SAUCE_REPLACE_7_clicked();

    void on_BTN_SAUCE_REPLACE_8_clicked();

    void on_BTN_SAUCE_REPLACE_9_clicked();

    void on_BTN_SAUCE_REPLACE_10_clicked();

    void on_BTN_ICECREAM_HALF_clicked();

    void on_BTN_ICECREAM_FULL_clicked();

    void on_BTN_SET_STOCK_MANUAL_clicked();

    void on_BTN_DB_RELOAD_clicked();

    void on_BTN_MILK_USE_clicked();
    void on_BTN_MILK_NOUSE_clicked();
    void on_BTN_COFFEE_USE_clicked();
    void on_BTN_COFFEE_NOUSE_clicked();
    void on_BTN_SODA_USE_clicked();
    void on_BTN_SODA_NOUSE_clicked();
    void on_BTN_ICE1_USE_clicked();
    void on_BTN_ICE1_NOUSE_clicked();
    void on_BTN_ICE2_USE_clicked();
    void on_BTN_ICE2_NOUSE_clicked();
    void on_BTN_HOT_USE_clicked();
    void on_BTN_HOT_NOUSE_clicked();

    void on_BTN_ICECREAM_ADD_clicked();

    void on_BTN_ICECREAM_NOUSE_clicked();

    void on_BTN_SAUCE_NOUSE_1_clicked();
    void on_BTN_SAUCE_NOUSE_2_clicked();
    void on_BTN_SAUCE_NOUSE_3_clicked();
    void on_BTN_SAUCE_NOUSE_4_clicked();
    void on_BTN_SAUCE_NOUSE_5_clicked();
    void on_BTN_SAUCE_NOUSE_6_clicked();
    void on_BTN_SAUCE_NOUSE_7_clicked();
    void on_BTN_SAUCE_NOUSE_8_clicked();

    void on_BTN_CUP_NOUSE_1_clicked();
    void on_BTN_CUP_NOUSE_2_clicked();
    void on_BTN_CUP_NOUSE_3_clicked();
    void on_BTN_CUP_NOUSE_4_clicked();

    void on_BTN_ICE_ROTATE_clicked();

private:
    Ui::DialogStock *ui;
    QTimer   timer;

    QSqlDatabase    db;

};

#endif // DIALOGSTOCK_H
