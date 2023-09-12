#ifndef DIALOGKIOSK_H
#define DIALOGKIOSK_H

#include <QDialog>
#include <QTimer>

// json -----------------------
#include <QJsonDocument>
#include <QJsonValue>
#include <QJsonArray>
#include <QJsonObject>

// websocket ------------------
#include <QtHttpServer.h>
#include <QtHttpRequest.h>
#include <QtHttpReply.h>
#include <QtHttpHeader.h>

// connection ------------------
#include <QEventLoop>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QUrl>
#include <QNetworkRequest>

#include "DialogStock.h"

namespace Ui {
class DialogKiosk;
}

class DialogKiosk : public QDialog
{
    Q_OBJECT

public:
    explicit DialogKiosk(QWidget *parent = nullptr);
    ~DialogKiosk();


    void generalReply(QtHttpReply *reply, QByteArray post_data);

    void replyOrder(QtHttpReply *reply, QJsonObject json);
    void replyStatus(QtHttpReply *reply, QJsonObject json);


    void setStock(DialogStock *_stock);


    int block_order;
    int connection_status;

    QVector<ST_RECIPE_INFO> orders;
    int orders_changed;

public slots:
    void onTimer();
    void onRequestReply(QtHttpRequest *request, QtHttpReply *reply);


private slots:
    void on_BTN_FORCE_ORDER_BLOCK_clicked();

    void on_BTN_FORCE_ORDER_PASS_clicked();

    void on_CB_FORCE_KIOSK_clicked(bool checked);

private:
    Ui::DialogKiosk *ui;
    QTimer timer;

    QtHttpServer    *server;

    DialogStock     *stock;

    int force_block_order;

    int link_count;
};

#endif // DIALOGKIOSK_H
