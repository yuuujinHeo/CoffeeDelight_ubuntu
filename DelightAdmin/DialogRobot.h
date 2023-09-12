#ifndef DIALOGROBOT_H
#define DIALOGROBOT_H

#include <QDialog>
#include <QtNetwork>
#include <QTcpServer>
#include <QTcpSocket>
#include <QTimer>

#include "DialogStock.h"
#include "GlobalHeader.h"

#define ROBOT_NORMAL_SPEED      1.0 //1.0 //0.6
#define ROBOT_SLOW_SPEED        0.2
#define ROBOT_STOP_SPPED        0.0


class RBTCPServer;
namespace Ui {
class DialogRobot;
}

class DialogRobot : public QDialog
{
    Q_OBJECT

public:
    explicit DialogRobot(QWidget *parent = nullptr, DialogStock *_stock = nullptr);
    ~DialogRobot();



    RBTCPServer *motionServer;
    void MotionServerCommand(QString str);


    bool isError();
    void ErrorClear();
    int RobotMoving;


    QTcpSocket cmdSocket;
    QTcpSocket dataSocket;

    int cmdConnectionStatus;
    int dataConnectionStatus;


    void ConnectCmd();
    int get_robot_cmd_connection();
    void ConnectData();
    int get_robot_data_connection();

    void WriteCommand(QString str, int move_flag = false);
    int  IsMotionIdle();

    //------------------------------------------------------------------
    void CobotInit();
    void MoveJoint(float joint1, float joint2, float joint3, float joint4, float joint5, float joint6, float spd = -1, float acc = -1);
    void MoveTCP(float x, float y, float z, float rx, float ry, float rz, float spd = -1, float acc = -1);
    void MoveCircle_ThreePoint(int type, float x1, float y1, float z1, float rx1, float ry1, float rz1, float x2, float y2, float z2, float rx2, float ry2, float rz2, float spd = -1, float acc = -1);
    void MoveCircle_Axis(int type, float cx, float cy, float cz, float ax, float ay, float az, float rot_angle, float spd, float acc);
    void MoveJointBlend_Clear();
    void MoveJointBlend_AddPoint(float joint1, float joint2, float joint3, float joint4, float joint5, float joint6, float spd = -1, float acc = -1);
    void MoveJointBlend_MovePoint();
    void MoveTCPBlend_Clear();
    void MoveTCPBlend_AddPoint(float radius, float x, float y, float z, float rx, float ry, float rz, float spd = -1, float acc = -1);
    void MoveTCPBlend_MovePoint();
    void ControlBoxDigitalOut(int d0, int d1, int d2, int d3, int d4, int d5, int d6, int d7, int d8, int d9, int d10, int d11, int d12, int d13, int d14, int d15);
    void ControlBoxDout(int port, int out);
    void ControlBoxAnalogOut(float a0, float a1, float a2, float a3);
    void ToolOut(int volt, int d0, int d1);
    void ProgramMode_Real();
    void ProgramMode_Simulation();
    void BaseSpeedChange(float spd);
    void MotionPause();
    void MotionHalt();
    void MotionPlay();
    void MotionResume();
    void CollisionResume();
    //------------------------------------------------------------------

    int get_robot_AI1_connected();



    void SetSystemForcedStopFlag();
    void ClearSystemForcedStopFlag();


    int FATAL_INFO_ROBOT_CONNECTION_ERROR;
    int FATAL_INFO_ROBOT_MISS_COMMAND_WORKING_CHECK;
    int FATAL_INFO_ROBOT_DATA_ERROR;

    int SUPER_FATAL_ERROR_ROBOT_MISS_COMMAND_WORKING_CHECK;
    int SUPER_FATAL_ERROR_ROBOT_DATA;


    int DEBUG_MISS_COMMAND_WORKING_CHECK_COUNT;


public slots:
    void onTimer();

    void onCmdConnected();

    void onCmdDisconnected();
    void onDataConnected();
    void onDataDisconnected();

    void onReadyCmdRead();
    void onReadyDataRead();


private slots:
    void on_BTN_ROBOT_TASK_STOP_clicked();

    void on_BTN_ROBOT_TASK_START_clicked();

    void on_BTN_ROBOT_REAL_clicked();

    void on_BTN_ROBOT_SIMUL_clicked();

    void on_BTN_ROBOT_PAUSE_clicked();

    void on_BTN_ROBOT_RESUME_OUTCOL_clicked();

    void on_BTN_ROBOT_RESUME_PAUSED_clicked();

    void on_BTN_ROBOT_HALT_clicked();

private:
    Ui::DialogRobot *ui;
    QTimer timer;

    DialogStock *stock;

    QByteArray recvBuf;

    int cmdConfirmFlag;
    int moveCmdFlag;
    int moveCmdCnt;

    int AI1_Connected;



    int command_out_flag;

    int system_forced_stop_flag;
    int data_recv_count;
};



class RBTCPServer : public QTcpServer
{
    Q_OBJECT
public:
    RBTCPServer(QObject *parent = 0);
    ~RBTCPServer();

    void RBServerOpen(QHostAddress::SpecialAddress _host = QHostAddress::Any, quint16 _port = 7000);
    void RBSendData(QByteArray &data);
    void RBSendData(const char *str, int len);

    int  RBConnectionStatus;

    QVector<QByteArray> dataReceived;
    QByteArray RBData;

private slots:
    void    RBNewConnection();
    void    RBClientDisconnected();

protected slots:
    void    RBReadData();

signals:
    void    SigNewConnection();
    void    SigDisConnection();

protected:
    QTcpServer  *RBTcpServer;
    QTcpSocket  *RBTcpClient;

private:
    QHostAddress::SpecialAddress    RBHostAddress;
    quint16                         RBPortNumber;

};

#endif // DIALOGROBOT_H
