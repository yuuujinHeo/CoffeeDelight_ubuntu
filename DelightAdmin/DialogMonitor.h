#ifndef DIALOGMONITOR_H
#define DIALOGMONITOR_H

#include <QDialog>
#include <QtNetwork>
#include <QTimer>

#include <iostream>
#include <QDataStream>

// json -----------------------
#include <QJsonDocument>
#include <QJsonValue>
#include <QJsonArray>
#include <QJsonObject>

// connection ------------------
#include <QEventLoop>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QUrl>
#include <QNetworkRequest>


#include "GlobalHeader.h"
#include "DialogStock.h"


#define DISPLAY_URL     "http://192.168.100.104:10000"

enum{
    DISPLAY_MODE_IDLE = 0,
    DISPLAY_MODE_IN_READY,
    DISPLAY_MODE_IN_OPERATION,
};


namespace Ui {
class DialogMonitor;
}

class DialogMonitor : public QDialog
{
    Q_OBJECT

public:
    explicit DialogMonitor(QWidget *parent = nullptr, DialogStock *_stock = nullptr);
    ~DialogMonitor();


    QByteArray generalPost(QByteArray post_data);

    bool SendDisplayInfo();

    void UpdateList_WaitingDrinks(QVector<ST_RECIPE_INFO> list_waiting);
    void UpdateList_InprogressDrinks(QVector<ST_RECIPE_INFO> list_inprogress);
    void UpdateList_CompletedDrinks(QVector<ST_COMPLETED_DRINK_INFO> list_completed);
    void UpdateList_DispensingDrinkgs(ST_COMPLETED_DRINK_INFO list_dispensing[]);



    void set_display_mode(int mode);
    int get_display_mode();

    void SetDisplayMessage(QString msg);



    QVector<ST_RECIPE_INFO> disp_waiting;
    QVector<ST_RECIPE_INFO> disp_inprogress;
    QVector<ST_COMPLETED_DRINK_INFO> disp_completed;
    ST_COMPLETED_DRINK_INFO disp_dispensing[NUMBER_OF_OUTLET];



    int displayConnectionStatus;

    int FATAL_ERROR_CONNECTION_OF_DISPLAY;


    QString force_monitor_status;


    QString display_msg;

public slots:
    void onTimer();
    void ProvideContextList(const QPoint &pos);


private slots:
    void on_BTN_FORCE_OPERATION_clicked();

    void on_BTN_FORCE_MAINTENANCE_clicked();

    void on_BTN_FORCE_PREPARATION_clicked();

    void on_BTN_FORCE_ERROR_clicked();


    void on_CB_FORCE_MONITOR_STATUS_clicked(bool checked);

    void on_BTN_FORCE_CLEAR_WAITING_LIST_clicked();

    void on_BTN_FORCE_CLEAR_COMPLETED_LIST_clicked();

    void on_CB_FORCE_CLEAR_DRINKS_clicked(bool checked);

private:
    Ui::DialogMonitor *ui;
    QTimer timer;

    DialogStock *stock;

    int prev_connection;

    int display_mode;



    // 네트워크 커넥션 관리 -----------------
    QNetworkAccessManager   *manager;
    QEventLoop              connection_loop;
};

#endif // DIALOGMONITOR_H
