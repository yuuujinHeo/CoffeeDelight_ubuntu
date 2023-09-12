#ifndef RBLAN2CAN_H
#define RBLAN2CAN_H

#include <QObject>
#include <QtNetwork>
#include <QTimer>
#include <iostream>

#include "GlobalHeader.h"


#define LAN2CAN_IP  "192.168.100.120"

class RBLAN2CAN : QObject
{
    Q_OBJECT

public:
    RBLAN2CAN();

    QTcpSocket  socket;

    int sockConnectionStatus;


    void SendControlData(int dev_send_id, int target, int command, int para1, int para2);

    void ClearSuperFatal();
    int SUPER_FATAL_ERROR_CONNECTION_OF_LAN2CAN;


public slots:
    void onTimer();

    void onSockConnected();
    void onSockDisconnected();
    void onSockReadyRead();

private:


    QTimer *timer;

    QByteArray recvBuf;
    int connection_count;
    int prev_sock_connection_status;

    int connection_status;
};

#endif // RBLAN2CAN_H
