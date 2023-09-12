#include "DialogRobot.h"
#include "ui_DialogRobot.h"
#include <iostream>

systemSTAT   sys_status;
systemCONFIG sys_config;
systemPOPUP  sys_popup;

using namespace std;

extern Logger   *plog;

DialogRobot::DialogRobot(QWidget *parent, DialogStock *_stock) :
    QDialog(parent), stock(_stock),
    ui(new Ui::DialogRobot)
{
    ui->setupUi(this);

    cmdConnectionStatus = false;
    dataConnectionStatus = false;
    moveCmdCnt = 0;

    system_forced_stop_flag = 0;

    motionServer = new RBTCPServer();
    motionServer->RBServerOpen(QHostAddress::AnyIPv4, 7000);


    connect(&cmdSocket, SIGNAL(connected()), this, SLOT(onCmdConnected()));
    connect(&cmdSocket, SIGNAL(disconnected()), this, SLOT(onCmdDisconnected()));
    connect(&dataSocket, SIGNAL(connected()), this, SLOT(onDataConnected()));
    connect(&dataSocket, SIGNAL(disconnected()), this, SLOT(onDataDisconnected()));

    connect(&cmdSocket, SIGNAL(readyRead()), this, SLOT(onReadyCmdRead()));
    connect(&dataSocket, SIGNAL(readyRead()), this, SLOT(onReadyDataRead()));


    FATAL_INFO_ROBOT_CONNECTION_ERROR = 0;
    FATAL_INFO_ROBOT_MISS_COMMAND_WORKING_CHECK = 0;
    FATAL_INFO_ROBOT_DATA_ERROR = 0;

    SUPER_FATAL_ERROR_ROBOT_MISS_COMMAND_WORKING_CHECK = 0;
    SUPER_FATAL_ERROR_ROBOT_DATA = 0;


    DEBUG_MISS_COMMAND_WORKING_CHECK_COUNT = 0;


    connect(&timer, SIGNAL(timeout()), this, SLOT(onTimer()));
    timer.start(100);
}

DialogRobot::~DialogRobot()
{
    delete ui;
}


void DialogRobot::onTimer(){
    static int cnt = 0;

    if(IS_UI_LOCK){
        ui->GB_ROBOT->setEnabled(false);
    }else{
        ui->GB_ROBOT->setEnabled(true);
    }

    if(motionServer->RBConnectionStatus == true){
        if(motionServer->dataReceived.size() > 0){
            QByteArray motionData = motionServer->dataReceived[0];
            motionServer->dataReceived.pop_front();

            QString motionStr(motionData);
//            qDebug()<< motionStr;
            if(motionStr == "ALIVE"){

            }
            else if(motionStr == "MOTION_DONE"){
                plog->write("[ROBOT] MOTION_DONE");
                RobotMoving = false;
            }
        }
    }


    if(cnt%10 == 0){
        if(cmdConnectionStatus == false){
            if(cmdSocket.state() == QAbstractSocket::UnconnectedState){
//                cout << "Test 1" << endl;
//                cmdSocket.connectToHost(QHostAddress("10.0.2.30"), 5000);
                cmdSocket.connectToHost(QHostAddress("192.168.100.130"), 5000);

//                cout<<" "<<cmdSocket.state()<<endl;
            }


        }
        if(dataConnectionStatus == false){
            if(dataSocket.state() == QAbstractSocket::UnconnectedState){
//                cout << "Test 2" << endl;
//                dataSocket.connectToHost(QHostAddress("10.0.2.30"), 5001);
                dataSocket.connectToHost(QHostAddress("192.168.100.130"), 5001);

            }
        }

    }

    int not_connect = 0;
    if(cmdConnectionStatus == false){
        not_connect++;
    }
    if(dataConnectionStatus == false){
        not_connect++;
    }



    // FATAL INFORMATION=============================================
    if(not_connect != 0){
        if(FATAL_INFO_ROBOT_CONNECTION_ERROR == 0)
            plog->write("[ROBOT] ERROR : DISCONNECTED");

        FATAL_INFO_ROBOT_CONNECTION_ERROR = 1;
    }else{
        FATAL_INFO_ROBOT_CONNECTION_ERROR = 0;
    }


    if(not_connect != 0){

    }else{
        // FATAL INFORMATION=============================================
        data_recv_count++;
        if(data_recv_count > 20){
            if(FATAL_INFO_ROBOT_DATA_ERROR == 0)
                plog->write("[ROBOT] ERROR : CAN'T RECEIVE DATA");
            FATAL_INFO_ROBOT_DATA_ERROR = 1;
        }else{
            FATAL_INFO_ROBOT_DATA_ERROR = 0;
        }

        if(DEBUG_MISS_COMMAND_WORKING_CHECK_COUNT > 2){
            if(FATAL_INFO_ROBOT_MISS_COMMAND_WORKING_CHECK == 0)
                plog->write("[ROBOT] ERROR : MISS COMMAND");
            FATAL_INFO_ROBOT_MISS_COMMAND_WORKING_CHECK = 1;
        }else{
            FATAL_INFO_ROBOT_MISS_COMMAND_WORKING_CHECK = 0;
        }


        // FATAL ERROR ===================================================
        if(OP_STATUS_OPERATING == PLATFORM_OPERATION_ON_OPERATING_STATE){
            if(FATAL_INFO_ROBOT_DATA_ERROR == 1){
                SUPER_FATAL_ERROR_ROBOT_DATA = 1;
            }
            if(FATAL_INFO_ROBOT_MISS_COMMAND_WORKING_CHECK == 1){
                SUPER_FATAL_ERROR_ROBOT_MISS_COMMAND_WORKING_CHECK = 1;
            }
        }



        QString text("reqdata");
        dataSocket.write(text.toStdString().c_str(), text.toStdString().length());

        if(system_forced_stop_flag == 0){
            if(sys_status.sdata.digital_out[0] == 1){
                ControlBoxDout(0, 0);
            }
        }else{
            if(sys_status.sdata.digital_out[0] == 0){
                ControlBoxDout(0, 1);
            }
        }
    }



    // ===================================================================================================
    if(cmdConnectionStatus == true){
        SetLEColor(ui->LE_ROBOT_CONNECTION_CMD, COLOR_GOOD);
    }else{
        SetLEColor(ui->LE_ROBOT_CONNECTION_CMD, COLOR_BAD);
    }
    if(dataConnectionStatus == true){
        SetLEColor(ui->LE_ROBOT_CONNECTION_DATA, COLOR_GOOD);
    }else{
        SetLEColor(ui->LE_ROBOT_CONNECTION_DATA, COLOR_BAD);
    }

    if(cmdConnectionStatus == true && dataConnectionStatus == true){
        if(sys_status.sdata.program_mode == 0){
            SetLEColor(ui->LE_PG_MODE_REAL, COLOR_GOOD);
            SetLEColor(ui->LE_PG_MODE_SIMULATION, "white");
        }else if(sys_status.sdata.program_mode == 1){
            SetLEColor(ui->LE_PG_MODE_REAL, "white");
            SetLEColor(ui->LE_PG_MODE_SIMULATION, COLOR_BAD);
        }else{
            SetLEColor(ui->LE_PG_MODE_REAL, "white");
            SetLEColor(ui->LE_PG_MODE_SIMULATION, "white");
        }

        if(sys_status.sdata.robot_state == 1){
            SetLEColor(ui->LE_ROBOT_STATE_IDLE, COLOR_BLUE);
            SetLEColor(ui->LE_ROBOT_STATE_MOVING, "white");
        }else if(sys_status.sdata.robot_state == 2){
            SetLEColor(ui->LE_ROBOT_STATE_IDLE, "white");
            SetLEColor(ui->LE_ROBOT_STATE_MOVING, "white");
        }else if(sys_status.sdata.robot_state == 3){
            SetLEColor(ui->LE_ROBOT_STATE_IDLE, "white");
            SetLEColor(ui->LE_ROBOT_STATE_MOVING, COLOR_BLUE);
        }else{
            SetLEColor(ui->LE_ROBOT_STATE_IDLE, "white");
            SetLEColor(ui->LE_ROBOT_STATE_MOVING, "white");
        }


        if(sys_status.sdata.is_freedrive_mode == 1){
            SetLEColor(ui->LE_ROBOT_STATUS_TEACHING, COLOR_BLUE);
        }else{
            SetLEColor(ui->LE_ROBOT_STATUS_TEACHING, "white");
        }
        if(sys_status.sdata.op_stat_collision_occur == 1){
            SetLEColor(ui->LE_ROBOT_STATUS_EXT_COLLISION, COLOR_BAD);
            //logger->write("[ROBOT] EXT COLLISION OCCURED");
        }else{
            SetLEColor(ui->LE_ROBOT_STATUS_EXT_COLLISION, "white");
        }
        if(sys_status.sdata.op_stat_self_collision == 1){
            SetLEColor(ui->LE_ROBOT_STATUS_SELF_COLLISION, COLOR_BAD);
            //logger->write("[ROBOT] SELF COLLISION OCCURED");
        }else{
            SetLEColor(ui->LE_ROBOT_STATUS_SELF_COLLISION, "white");
        }
        if(sys_status.sdata.op_stat_soft_estop_occur == 1){
            SetLEColor(ui->LE_ROBOT_STATUS_PAUSED, COLOR_BAD);
            //logger->write("[ROBOT] SOTF ESTOP OCCURED");
        }else{
            SetLEColor(ui->LE_ROBOT_STATUS_PAUSED, "white");
        }
        if(sys_status.sdata.op_stat_ems_flag != 0){
            SetLEColor(ui->LE_ROBOT_STATUS_EMS, COLOR_BAD);
            //logger->write("[ROBOT] EMS ERROR OCCURED");
        }else{
            SetLEColor(ui->LE_ROBOT_STATUS_EMS, "white");
        }
        if(sys_status.sdata.op_stat_sos_flag == 1){
            SetLEColor(ui->LE_ROBOT_STATUS_SOS, COLOR_BAD);
            //logger->write("[ROBOT] SOS ERROR OCCURED");
        }else{
            SetLEColor(ui->LE_ROBOT_STATUS_SOS, "white");
        }


        if(sys_status.sdata.task_state == 1){
            SetLEColor(ui->LE_ROBOT_PRG_WORKING_STATUS, COLOR_BAD);
        }else if(sys_status.sdata.task_state == 2){
            SetLEColor(ui->LE_ROBOT_PRG_WORKING_STATUS, "yellow");
        }else if(sys_status.sdata.task_state == 3){
            SetLEColor(ui->LE_ROBOT_PRG_WORKING_STATUS, COLOR_GOOD);
        }


        if(motionServer->RBConnectionStatus == true){
            SetLEColor(ui->LE_ROBOT_PRG_CONNECT, COLOR_GOOD);
        }else{
            SetLEColor(ui->LE_ROBOT_PRG_CONNECT, COLOR_BAD);
        }


        ui->LE_ROBOT_INIT_BASE_ANGLE->setText(QString().sprintf("%d", int(sys_status.sdata.jnt_ang[0])));
        if(OP_STATUS_OPERATING != PLATFORM_OPERATION_ON_OPERATING_STATE){
            if(sys_status.sdata.jnt_ang[0] > -120.0 && sys_status.sdata.jnt_ang[0] < 30){
                SetLEColor(ui->LE_ROBOT_INIT_BASE_ANGLE, COLOR_GOOD);
            }else{
                SetLEColor(ui->LE_ROBOT_INIT_BASE_ANGLE, COLOR_BAD);
            }
            if(sys_status.sdata.digital_out[15] == 1){
                SetLEColor(ui->LE_ROBOT_INIT_POSITION, COLOR_GOOD);
            }else{
                SetLEColor(ui->LE_ROBOT_INIT_POSITION, COLOR_BAD);
            }
        }else{
            SetLEColor(ui->LE_ROBOT_INIT_BASE_ANGLE, "white");
            SetLEColor(ui->LE_ROBOT_INIT_POSITION, "white");
        }


        // soda data input
        if(sys_status.sdata.digital_in[4] == 1){
            // low soda pressure
//            stock->SetDeviceError("SODA");
        }

    }else{
        SetLEColor(ui->LE_ROBOT_INIT_STAT_1, "white");
        SetLEColor(ui->LE_ROBOT_INIT_STAT_2, "white");
        SetLEColor(ui->LE_ROBOT_INIT_STAT_3, "white");
        SetLEColor(ui->LE_ROBOT_INIT_STAT_4, "white");

        SetLEColor(ui->LE_PG_MODE_REAL, "white");
        SetLEColor(ui->LE_PG_MODE_SIMULATION, "white");

        SetLEColor(ui->LE_ROBOT_STATE_IDLE, "white");
        SetLEColor(ui->LE_ROBOT_STATE_MOVING, "white");

        SetLEColor(ui->LE_ROBOT_STATUS_TEACHING, "white");
        SetLEColor(ui->LE_ROBOT_STATUS_EXT_COLLISION, "white");
        SetLEColor(ui->LE_ROBOT_STATUS_SELF_COLLISION, "white");
        SetLEColor(ui->LE_ROBOT_STATUS_PAUSED, "white");
        SetLEColor(ui->LE_ROBOT_STATUS_EMS, "white");
        SetLEColor(ui->LE_ROBOT_STATUS_SOS, "white");

        SetLEColor(ui->LE_ROBOT_PRG_WORKING_STATUS, "white");
        SetLEColor(ui->LE_ROBOT_PRG_CONNECT, "white");

        SetLEColor(ui->LE_ROBOT_INIT_BASE_ANGLE, "white");
        SetLEColor(ui->LE_ROBOT_INIT_POSITION, "white");

    }


    ui->LE_JNT_ENC_1->setText(QString().sprintf("%.2f", sys_status.sdata.jnt_ang[0]));
    ui->LE_JNT_ENC_2->setText(QString().sprintf("%.2f", sys_status.sdata.jnt_ang[1]));
    ui->LE_JNT_ENC_3->setText(QString().sprintf("%.2f", sys_status.sdata.jnt_ang[2]));
    ui->LE_JNT_ENC_4->setText(QString().sprintf("%.2f", sys_status.sdata.jnt_ang[3]));
    ui->LE_JNT_ENC_5->setText(QString().sprintf("%.2f", sys_status.sdata.jnt_ang[4]));
    ui->LE_JNT_ENC_6->setText(QString().sprintf("%.2f", sys_status.sdata.jnt_ang[5]));

    ui->LE_JNT_REF_1->setText(QString().sprintf("%.2f", sys_status.sdata.jnt_ref[0]));
    ui->LE_JNT_REF_2->setText(QString().sprintf("%.2f", sys_status.sdata.jnt_ref[1]));
    ui->LE_JNT_REF_3->setText(QString().sprintf("%.2f", sys_status.sdata.jnt_ref[2]));
    ui->LE_JNT_REF_4->setText(QString().sprintf("%.2f", sys_status.sdata.jnt_ref[3]));
    ui->LE_JNT_REF_5->setText(QString().sprintf("%.2f", sys_status.sdata.jnt_ref[4]));
    ui->LE_JNT_REF_6->setText(QString().sprintf("%.2f", sys_status.sdata.jnt_ref[5]));

    ui->LE_TCP_REF_X->setText(QString().sprintf("%.2f", sys_status.sdata.tcp_ref[0]));
    ui->LE_TCP_REF_Y->setText(QString().sprintf("%.2f", sys_status.sdata.tcp_ref[1]));
    ui->LE_TCP_REF_Z->setText(QString().sprintf("%.2f", sys_status.sdata.tcp_ref[2]));
    ui->LE_TCP_REF_RX->setText(QString().sprintf("%.2f", sys_status.sdata.tcp_ref[3]));
    ui->LE_TCP_REF_RY->setText(QString().sprintf("%.2f", sys_status.sdata.tcp_ref[4]));
    ui->LE_TCP_REF_RZ->setText(QString().sprintf("%.2f", sys_status.sdata.tcp_ref[5]));

}




void DialogRobot::ConnectCmd(){
    if(cmdConnectionStatus){
        // disconnect
        cmdSocket.close();
    }else{
        // connect
//        cmdSocket.connectToHost(QHostAddress("10.0.2.30"), 5000);
        cmdSocket.connectToHost(QHostAddress("192.168.100.130"), 5000);
    }
}

int DialogRobot::get_robot_cmd_connection()
{
    return cmdConnectionStatus;
}
void DialogRobot::ConnectData(){
    if(dataConnectionStatus){
        // disconnect
        dataSocket.close();
    }else{
        // connect
//        dataSocket.connectToHost(QHostAddress("10.0.2.30"), 5001);
        dataSocket.connectToHost(QHostAddress("192.168.100.130"), 5001);
    }
}

int DialogRobot::get_robot_data_connection()
{
    return dataConnectionStatus;
}

void DialogRobot::onCmdConnected(){
    plog->write("[ROBOT] CMD CONNECTED");
    cmdConnectionStatus = true;
}

//void RobotHandler::onCmdErrorOccurred(){
//    cmdConnectionStatus = 10;
//}

void DialogRobot::onCmdDisconnected(){
    plog->write("[ROBOT] CMD DISCONNECTED");
    cmdConnectionStatus = false;
}
void DialogRobot::onDataConnected(){
    plog->write("[ROBOT] DATA CONNECTED");
    dataConnectionStatus = true;
}
void DialogRobot::onDataDisconnected(){
    plog->write("[ROBOT] DATA DISCONNECTED");
    dataConnectionStatus = false;
}


void DialogRobot::onReadyCmdRead(){
    QByteArray datas = cmdSocket.readAll();
    if(QString(datas.data()).compare("The command was executed\n") == 0){
        cmdConfirmFlag = true;
        if(moveCmdFlag == true){
            moveCmdCnt = 5;
            sys_status.sdata.robot_state = 3;
            moveCmdFlag = false;
        }
    }else{

    }
}

void DialogRobot::onReadyDataRead()
{
    QByteArray datas = dataSocket.readAll();
    recvBuf += datas;

    while(recvBuf.length() > 4){
        if( recvBuf[0] == '$'){
            int size = ( int(uchar(recvBuf[2])<<8) | int(uchar(recvBuf[1])) );
            if(size <= recvBuf.length() )
            {
                if(3 == recvBuf[3]){
                    data_recv_count = 0;
//                    qDebug() << "#################################";
                    if(moveCmdCnt > 0){
                        moveCmdCnt--;
                    }else{
                        memcpy(&sys_status, recvBuf.data(), sizeof(systemSTAT));

                        if(sys_status.sdata.analog_in[1] < 1.0){
                            AI1_Connected = 1;
                        }
                        else{
                            AI1_Connected = 0;
                        }


                        if(command_out_flag == 1){
                            if(sys_status.sdata.robot_state == 3){
                                command_out_flag = 0;
                            }
                        }
                    }
                    recvBuf.remove(0,sizeof(systemSTAT));
                }
                else if(4 == recvBuf[3]){
                    memcpy(&sys_config, recvBuf.data(), sizeof(systemCONFIG));
                    recvBuf.remove(0,sizeof(systemCONFIG));
                }
                else if(10 == recvBuf[3]){
                    memcpy(&sys_popup, recvBuf.data(), sizeof(systemPOPUP));
                    recvBuf.remove(0,sizeof(systemPOPUP));
                }
                else{
                    recvBuf.remove(0,1);
                }
            }
        }else{
            recvBuf.remove(0,1);
        }
    }
}


void DialogRobot::MotionServerCommand(QString str){
    if(motionServer->RBConnectionStatus == true){
        if(command_out_flag == 1){
            DEBUG_MISS_COMMAND_WORKING_CHECK_COUNT++;
        }else{
            DEBUG_MISS_COMMAND_WORKING_CHECK_COUNT--;
            if(DEBUG_MISS_COMMAND_WORKING_CHECK_COUNT < 0){
                DEBUG_MISS_COMMAND_WORKING_CHECK_COUNT = 0;
            }
        }
        command_out_flag = 1;

        plog->write("[ROBOT] SEND COMMAND : "+str);
        motionServer->RBSendData(str.toStdString().data(), str.toStdString().length());
    }
}

void DialogRobot::WriteCommand(QString str, int move_flag){
    if(cmdConnectionStatus){
        if(move_flag == true){
            moveCmdFlag = true;
        }
        cmdConfirmFlag = false;
        cmdSocket.write(str.toStdString().c_str(), str.toStdString().length());
    }
}

int DialogRobot::IsMotionIdle(){
    return ((cmdConfirmFlag == true) && (sys_status.sdata.robot_state == 1));
}

void DialogRobot::CobotInit(){
    QString text;
    text.sprintf("mc jall init ");
    cmdConfirmFlag = false;
    cmdSocket.write(text.toStdString().c_str(), text.toStdString().length());
}
void DialogRobot::ProgramMode_Real(){
    QString text;
    text.sprintf("pgmode real ");
    cmdConfirmFlag = false;
    cmdSocket.write(text.toStdString().c_str(), text.toStdString().length());
}
void DialogRobot::ProgramMode_Simulation(){
    QString text;
    text.sprintf("pgmode simulation ");
    cmdConfirmFlag = false;
    cmdSocket.write(text.toStdString().c_str(), text.toStdString().length());
}
void DialogRobot::MoveJoint(float joint1, float joint2, float joint3, float joint4, float joint5, float joint6, float spd, float acc){
    QString text;
    text.sprintf("jointall %.3f, %.3f, %.3f, %.3f, %.3f, %.3f, %.3f, %.3f", spd, acc, joint1, joint2, joint3, joint4, joint5, joint6);
    moveCmdFlag = true;
    cmdConfirmFlag = false;
    cmdSocket.write(text.toStdString().c_str(), text.toStdString().length());
    sys_status.sdata.robot_state = 3; //run
}
void DialogRobot::MoveTCP(float x, float y, float z, float rx, float ry, float rz, float spd, float acc){
    QString text;
    text.sprintf("movetcp %.3f, %.3f, %.3f, %.3f, %.3f, %.3f, %.3f, %.3f", spd, acc, x, y, z, rx, ry, rz);
    moveCmdFlag = true;
    cmdConfirmFlag = false;
    cmdSocket.write(text.toStdString().c_str(), text.toStdString().length());
    sys_status.sdata.robot_state = 3; //run
}
void DialogRobot::MoveCircle_ThreePoint(int type, float x1, float y1, float z1, float rx1, float ry1, float rz1, float x2, float y2, float z2, float rx2, float ry2, float rz2, float spd, float acc){
    QString text;
    char buf[15];
    if(type == 0){
        sprintf(buf, "intended");
    }else if(type == 1){
        sprintf(buf, "constant");
    }else if(type == 2){
        sprintf(buf, "radial");
    }
    text.sprintf("movecircle absolute threepoints %s %.3f, %.3f, %.3f, %.3f, %.3f, %.3f, %.3f, %.3f, %.3f, %.3f, %.3f, %.3f, %.3f, %.3f",
                 buf, spd, acc, x1, y1, z1, rx1, ry1, rz1, x2, y2, z2, rx2, ry2, rz2);
    moveCmdFlag = true;
    cmdConfirmFlag =false;
    cmdSocket.write(text.toStdString().c_str(), text.toStdString().length());
    sys_status.sdata.robot_state = 3;
}
void DialogRobot::MoveCircle_Axis(int type, float cx, float cy, float cz, float ax, float ay, float az, float rot_angle, float spd, float acc){
    QString text;
    char buf[15];
    if(type == 0){
        sprintf(buf, "intended");
    }else if(type == 1){
        sprintf(buf, "constant");
    }else if(type == 2){
        sprintf(buf, "radial");
    }
    text.sprintf("movecircle absolute axis %s %.3f, %.3f, %.3f, %.3f, %.3f, %.3f, %.3f, %.3f, %.3f",
                 buf, spd, acc, rot_angle, cx, cy, cz, ax, ay, az);
    moveCmdFlag = true;
    cmdConfirmFlag =false;
    cmdSocket.write(text.toStdString().c_str(), text.toStdString().length());
    sys_status.sdata.robot_state = 3;
}
void DialogRobot::MoveJointBlend_Clear(){
    QString text;
    text.sprintf("blend_jnt clear_pt");
    cmdConfirmFlag = false;
    cmdSocket.write(text.toStdString().c_str(), text.toStdString().length());
}
void DialogRobot::MoveJointBlend_AddPoint(float joint1, float joint2, float joint3, float joint4, float joint5, float joint6, float spd, float acc){
    QString text;
    text.sprintf("blend_jnt add_pt %.3f, %.3f, %.3f, %.3f, %.3f, %.3f, %.3f, %.3f", spd, acc, joint1, joint2, joint3, joint4, joint5, joint6);
    cmdConfirmFlag = false;
    cmdSocket.write(text.toStdString().c_str(), text.toStdString().length());
    sys_status.sdata.robot_state = 3; //run
}
void DialogRobot::MoveJointBlend_MovePoint(){
    QString text;
    text.sprintf("blend_jnt move_pt");
    moveCmdFlag = true;
    cmdConfirmFlag = false;
    cmdSocket.write(text.toStdString().c_str(), text.toStdString().length());
    sys_status.sdata.robot_state = 3;
}
void DialogRobot::MoveTCPBlend_Clear(){
    QString text;
    text.sprintf("blend_tcp clear_pt");
    cmdConfirmFlag = false;
    cmdSocket.write(text.toStdString().c_str(), text.toStdString().length());
}
void DialogRobot::MoveTCPBlend_AddPoint(float radius, float x, float y, float z, float rx, float ry, float rz, float spd, float acc){
    QString text;
    text.sprintf("blend_tcp add_pt %.3f, %.3f, %.3f, %.3f, %.3f, %.3f, %.3f, %.3f, %.3f", spd, acc, radius, x, y, z, rx, ry, rz);
    cmdConfirmFlag = false;
    cmdSocket.write(text.toStdString().c_str(), text.toStdString().length());
    sys_status.sdata.robot_state = 3; //run
}
void DialogRobot::MoveTCPBlend_MovePoint(){
    QString text;
    text.sprintf("blend_tcp move_pt");
    moveCmdFlag = true;
    cmdConfirmFlag = false;
    cmdSocket.write(text.toStdString().c_str(), text.toStdString().length());
    sys_status.sdata.robot_state = 3;
}
void DialogRobot::ControlBoxDigitalOut(int d0, int d1, int d2, int d3, int d4, int d5, int d6, int d7, int d8, int d9, int d10, int d11, int d12, int d13, int d14, int d15){
    QString text;
    text.sprintf("digital_out %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d ", d0, d1, d2, d3, d4, d5, d6, d7, d8, d9, d10, d11, d12, d13, d14, d15);
    cmdConfirmFlag = false;
    cmdSocket.write(text.toStdString().c_str(), text.toStdString().length());
}
void DialogRobot::ControlBoxDout(int port, int out){
    QString text;
    text.sprintf("set_box_dout(%d, %d) ", port, out);
    cmdConfirmFlag = false;
    cmdSocket.write(text.toStdString().c_str(), text.toStdString().length());
}
void DialogRobot::ControlBoxAnalogOut(float a0, float a1, float a2, float a3){
    QString text;
    text.sprintf("analog_out %.3f, %.3f, %.3f, %.3f ", a0, a1, a2, a3);
    cmdConfirmFlag = false;
    cmdSocket.write(text.toStdString().c_str(), text.toStdString().length());
}
void DialogRobot::ToolOut(int volt, int d0, int d1){
    int temp_volt = volt;
    if((temp_volt != 12) && (temp_volt != 24))
        temp_volt = 0;

    QString text;
    text.sprintf("tool_out %d, %d, %d ", temp_volt, d0, d1);
    cmdConfirmFlag = false;
    cmdSocket.write(text.toStdString().c_str(), text.toStdString().length());
}
void DialogRobot::BaseSpeedChange(float spd){
    QString text;
    if(spd > 1.0)
        spd = 1.0;
    if(spd < 0.0)
        spd = 0.0;
    text.sprintf("sdw default_speed %.3f ", spd);
    cmdConfirmFlag = false;
    cmdSocket.write(text.toStdString().c_str(), text.toStdString().length());
}
void DialogRobot::MotionPause(){
    QString text;
    text.sprintf("task pause ");
    cmdConfirmFlag = false;
    cmdSocket.write(text.toStdString().c_str(), text.toStdString().length());
}
void DialogRobot::MotionHalt(){
    QString text;
    text.sprintf("task stop ");
    cmdConfirmFlag = false;
    cmdSocket.write(text.toStdString().c_str(), text.toStdString().length());
}
void DialogRobot::MotionResume(){
    QString text;
    text.sprintf("task resume_a ");
    cmdConfirmFlag = false;
    cmdSocket.write(text.toStdString().c_str(), text.toStdString().length());
}
void DialogRobot::CollisionResume(){
    QString text;
    text.sprintf("task resume_b ");
    cmdConfirmFlag = false;
    cmdSocket.write(text.toStdString().c_str(), text.toStdString().length());
}
void DialogRobot::MotionPlay(){
    QString text;
    text.sprintf("task play ");
    cmdConfirmFlag = false;
    cmdSocket.write(text.toStdString().c_str(), text.toStdString().length());
}

int DialogRobot::get_robot_AI1_connected()
{
    return AI1_Connected;

}

void DialogRobot::SetSystemForcedStopFlag(){
    system_forced_stop_flag = 1;
}
void DialogRobot::ClearSystemForcedStopFlag(){
    system_forced_stop_flag = 0;
}

//=========================================================================
//=========================================================================


RBTCPServer::RBTCPServer(QObject *parent)
    : QTcpServer(parent), RBTcpServer(0)
{
    RBConnectionStatus = false;
    RBTcpClient = new QTcpSocket();
}

RBTCPServer::~RBTCPServer(){

}

void RBTCPServer::RBServerOpen(QHostAddress::SpecialAddress _host, quint16 _port){
    RBHostAddress = _host;
    RBPortNumber = _port;

    RBTcpServer = new QTcpServer(this);
    connect(RBTcpServer, SIGNAL(newConnection()), this, SLOT(RBNewConnection()));

    if(!RBTcpServer->listen(RBHostAddress, RBPortNumber)){
        cout << "RBserver unable to start the server" << endl;
    }else{
        cout << "RBServer open success with port(" << RBTcpServer->serverPort() << ")" << endl;
    }
}

void RBTCPServer::RBNewConnection(){
    if(RBConnectionStatus == false){
        RBTcpClient = RBTcpServer->nextPendingConnection();
        connect(RBTcpClient, SIGNAL(disconnected()), this, SLOT(RBClientDisconnected()));
        connect(RBTcpClient, SIGNAL(readyRead()), this, SLOT(RBReadData()));
        RBConnectionStatus = true;
        cout << "New client is connected" << endl;

        emit SigNewConnection();
    }else{
        QTcpSocket *dummySocket = RBTcpServer->nextPendingConnection();
        dummySocket->close();
        cout << "Client is already connected" << endl;
    }
}

void RBTCPServer::RBClientDisconnected(){
    RBTcpClient->deleteLater();
    RBConnectionStatus = false;
    cout << "Client is disconnected" << endl;

    emit SigDisConnection();
}

void RBTCPServer::RBSendData(QByteArray &data){
    RBTcpClient->write(data);
}
void RBTCPServer::RBSendData(const char *str, int len){
    RBTcpClient->write(str, len);
}

void RBTCPServer::RBReadData(){
    QDataStream in(RBTcpClient);
    in.setVersion(QDataStream::Qt_5_2);

    int size = RBTcpClient->bytesAvailable();
    RBData.resize(size);
    in.readRawData(RBData.data(), size);
    dataReceived.push_back(RBData);
}


void DialogRobot::on_BTN_ROBOT_TASK_STOP_clicked(){
    MotionHalt();
    plog->write("[UI OPERATION - ROBOT] 모션정지");
}

void DialogRobot::on_BTN_ROBOT_TASK_START_clicked(){
    MotionPlay();
    plog->write("[UI OPERATION - ROBOT] 모션시작");
}

void DialogRobot::on_BTN_ROBOT_REAL_clicked(){
    ProgramMode_Real();
    plog->write("[UI OPERATION - ROBOT] 리얼");
}

void DialogRobot::on_BTN_ROBOT_SIMUL_clicked(){
    ProgramMode_Simulation();
    plog->write("[UI OPERATION - ROBOT] 시뮬레이션");
}

void DialogRobot::on_BTN_ROBOT_PAUSE_clicked(){
    MotionPause();
    plog->write("[UI OPERATION - ROBOT] 일시정지");
}

void DialogRobot::on_BTN_ROBOT_RESUME_OUTCOL_clicked(){
    CollisionResume();
    plog->write("[UI OPERATION - ROBOT] 충돌해제");
}

void DialogRobot::on_BTN_ROBOT_RESUME_PAUSED_clicked(){
    MotionResume();
    plog->write("[UI OPERATION - ROBOT] 동작재개");
}

void DialogRobot::on_BTN_ROBOT_HALT_clicked(){
    MotionHalt();
    plog->write("[UI OPERATION - ROBOT] 정지");
}
