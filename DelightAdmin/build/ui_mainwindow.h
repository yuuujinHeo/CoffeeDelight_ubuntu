/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QPushButton *BTN_EXIT;
    QPushButton *BTN_UI_LOCK;
    QFrame *FRAME_DEVICE;
    QPushButton *BTN_SETTING;
    QFrame *FRAME;
    QFrame *FRAME_COFFEE;
    QPushButton *BTN_DEV_INFO_COFFEE;
    QWidget *layoutWidget;
    QGridLayout *gridLayout_8;
    QLabel *label_124;
    QLabel *label_125;
    QLabel *label_127;
    QLabel *label_126;
    QLabel *label_128;
    QLineEdit *LE_MACHINE_STATUS_NOT_CONNECTED;
    QLineEdit *LE_MACHINE_STATUS_PREPAREING;
    QLineEdit *LE_MACHINE_STATUS_ERROR_OCCURED;
    QLineEdit *LE_MACHINE_STATUS_ON_READY;
    QLineEdit *LE_MACHINE_STATUS_MAKING;
    QWidget *layoutWidget_2;
    QGridLayout *gridLayout_9;
    QLabel *label_111;
    QLineEdit *LE_SYS_CLEAN_TIME_HOUR;
    QLabel *label_114;
    QLineEdit *LE_SYS_CLEAN_TIME_MINUTE;
    QLabel *label_115;
    QLineEdit *LE_SYS_CLEAN_TIME_SECOND;
    QLabel *label_116;
    QLabel *label_112;
    QLineEdit *LE_MILK_CLEAN_TIME_HOUR;
    QLabel *label_118;
    QLineEdit *LE_MILK_CLEAN_TIME_MINUTE;
    QLabel *label_119;
    QLineEdit *LE_MILK_CLEAN_TIME_SECOND;
    QLabel *label_117;
    QLabel *label_113;
    QLineEdit *LE_MILK_REPLACE_TIME_HOUR;
    QLabel *label_121;
    QLineEdit *LE_MILK_REPLACE_TIME_MINUTE;
    QLabel *label_122;
    QLineEdit *LE_MILK_REPLACE_TIME_SECOND;
    QLabel *label_120;
    QWidget *layoutWidget_3;
    QVBoxLayout *verticalLayout;
    QLabel *label_123;
    QLineEdit *LE_MACHINE_STATUS_SYS_CLEANING;
    QLineEdit *LE_MACHINE_STATUS_MILK_CLEANING;
    QLineEdit *LE_MACHINE_STATUS_MILK_REPLACING;
    QFrame *FRAME_ICE_1;
    QPushButton *BTN_DEV_INFO_ICE_1;
    QWidget *layoutWidget_4;
    QGridLayout *gridLayout_7;
    QLabel *label;
    QLabel *LB_ICE_1_FULL;
    QLabel *label_2;
    QLabel *LB_ICE_1_ERROR;
    QFrame *FRAME_SODA;
    QPushButton *BTN_DEV_INFO_SODA;
    QWidget *layoutWidget_5;
    QGridLayout *gridLayout_4;
    QLabel *label_16;
    QLabel *LB_SODA_LOADCELL;
    QLabel *label_15;
    QLabel *LB_SODA_LAST_ERROR;
    QLabel *label_14;
    QLabel *LB_SODA_OP_STATE;
    QFrame *FRAME_SYRUP;
    QPushButton *BTN_DEV_INFO_SYRUP;
    QWidget *layoutWidget_6;
    QGridLayout *gridLayout_3;
    QLabel *label_5;
    QLabel *LB_SYRUP_LOADCELL;
    QLabel *label_6;
    QLabel *LB_SYRUP_LAST_ERROR;
    QLabel *label_7;
    QLabel *LB_SYRUP_OP_STATE;
    QFrame *FRAME_OUTLET;
    QPushButton *BTN_DEV_INFO_OUTLET;
    QLineEdit *LE_OUTLET_M_1_DOOR_OPEN;
    QLineEdit *LE_OUTLET_M_1_DOOR_CLOSE;
    QLineEdit *LE_OUTLET_M_1_CUP_DETECT;
    QLineEdit *LE_OUTLET_M_2_DOOR_OPEN;
    QLineEdit *LE_OUTLET_M_2_DOOR_CLOSE;
    QLineEdit *LE_OUTLET_M_2_CUP_DETECT;
    QWidget *layoutWidget_7;
    QGridLayout *gridLayout_5;
    QLabel *LB_OUTLET_M_1_CELL_3;
    QLabel *label_22;
    QLabel *label_26;
    QLabel *LB_OUTLET_M_1_CELL_1;
    QLabel *label_21;
    QLabel *LB_OUTLET_M_2_CELL_1;
    QLabel *LB_OUTLET_M_2_CELL_2;
    QLabel *LB_OUTLET_M_2_CELL_3;
    QLabel *label_24;
    QLabel *LB_OUTLET_M_1_CELL_2;
    QLabel *label_25;
    QLabel *label_23;
    QSpacerItem *horizontalSpacer;
    QFrame *FRAME_MONITOR;
    QPushButton *BTN_DEV_INFO_MONITOR;
    QWidget *layoutWidget_8;
    QGridLayout *gridLayout_6;
    QLabel *label_18;
    QLabel *LB_MONITOR_INPROGRESS;
    QLabel *label_19;
    QLabel *LB_MONITOR_WAITING;
    QLabel *label_20;
    QLabel *LB_MONITOR_COMPLETED;
    QFrame *FRAME_CUP;
    QPushButton *BTN_DEV_INFO_CUP;
    QPushButton *BTN_CUP_ADD_DONE;
    QWidget *layoutWidget_9;
    QGridLayout *gridLayout_11;
    QLabel *label_27;
    QLabel *label_33;
    QLabel *label_30;
    QLabel *LB_CUP_1_LAST_ERROR;
    QLabel *LB_CUP_2_LAST_ERROR;
    QLabel *label_29;
    QLabel *LB_CUP_1_OP_STATE;
    QLabel *LB_CUP_2_OP_STATE;
    QLabel *label_28;
    QLabel *label_34;
    QLabel *label_31;
    QLabel *LB_CUP_3_LAST_ERROR;
    QLabel *LB_CUP_4_LAST_ERROR;
    QLabel *label_32;
    QLabel *LB_CUP_3_OP_STATE;
    QLabel *LB_CUP_4_OP_STATE;
    QFrame *FRAME_ROBOT;
    QPushButton *BTN_DEV_INFO_ROBOT;
    QLabel *label_91;
    QLineEdit *LE_ROBOT_PRG_CONNECT;
    QLineEdit *LE_ROBOT_PRG_WORKING_STATUS;
    QFrame *line;
    QLineEdit *LE_ROBOT_INIT_BASE_ANGLE;
    QLineEdit *LE_ROBOT_INIT_POSITION;
    QLabel *label_92;
    QWidget *layoutWidget_10;
    QGridLayout *gridLayout_10;
    QLineEdit *LE_ROBOT_STATE_MOVING;
    QLineEdit *LE_ROBOT_STATUS_TEACHING;
    QLineEdit *LE_ROBOT_STATE_IDLE;
    QLineEdit *LE_PG_MODE_REAL;
    QLineEdit *LE_PG_MODE_SIMULATION;
    QLineEdit *LE_ROBOT_STATUS_SELF_COLLISION;
    QLineEdit *LE_ROBOT_STATUS_EXT_COLLISION;
    QLineEdit *LE_ROBOT_STATUS_PAUSED;
    QLineEdit *LE_ROBOT_STATUS_EMS;
    QLineEdit *LE_ROBOT_STATUS_SOS;
    QFrame *FRAME_HOT;
    QPushButton *BTN_DEV_INFO_HOT;
    QWidget *layoutWidget_11;
    QGridLayout *gridLayout_12;
    QLabel *label_10;
    QLabel *LB_HOT_LOADCELL;
    QLabel *label_9;
    QLabel *LB_HOT_LAST_ERROR;
    QLabel *label_8;
    QLabel *LB_HOT_OP_STATE;
    QFrame *FRAME_ICECREAM;
    QPushButton *BTN_DEV_INFO_ICECREAM;
    QWidget *layoutWidget_12;
    QGridLayout *gridLayout_2;
    QLabel *label_13;
    QLabel *LB_ICECREAM_LOADCELL;
    QLabel *label_12;
    QLabel *LB_ICECREAM_LAST_ERROR;
    QLabel *label_11;
    QLabel *LB_ICECREAM_OP_STATE;
    QFrame *FRAME_BARCODE;
    QPushButton *BTN_DEV_INFO_BARCODE;
    QLabel *label_17;
    QLabel *LB_BARCODE_LAST_DATA;
    QFrame *FRAME_DOOR;
    QPushButton *BTN_DEV_INFO_DOOR;
    QLabel *label_129;
    QLineEdit *LE_DOOR_CLOSED;
    QLabel *label_130;
    QLineEdit *LE_DOOR_OPENED;
    QFrame *FRAME_KIOSK;
    QPushButton *BTN_DEV_INFO_KIOSK;
    QLabel *LB_KIOSK_BLOCK_ORDER;
    QFrame *FRAME_STOCK;
    QPushButton *BTN_DEV_INFO_STOCK;
    QLabel *label_35;
    QFrame *FRAME_ICE_2;
    QPushButton *BTN_DEV_INFO_ICE_2;
    QWidget *layoutWidget_13;
    QGridLayout *gridLayout_13;
    QLabel *label_3;
    QLabel *LB_ICE_2_FULL;
    QLabel *label_4;
    QLabel *LB_ICE_2_ERROR;
    QWidget *layoutWidget_14;
    QGridLayout *gridLayout;
    QLabel *label_135;
    QLineEdit *LE_PLATFORM_INITIALIZING;
    QLabel *label_147;
    QLineEdit *LE_PLATFORM_WAITING_STOP;
    QLabel *label_146;
    QLineEdit *LE_PLATFORM_OPERATING;
    QLabel *label_138;
    QLineEdit *LE_PLATFORM_CLOSED;
    QFrame *GB_OP_CONTROL;
    QPushButton *BTN_DO_OPERATING;
    QPushButton *BTN_STOP_OPERATING;
    QPushButton *BTN_CANCEL_STOP;
    QPushButton *BTN_SUPER_STOP;
    QPushButton *BTN_FORCE_STOP;
    QLineEdit *LE_PLATFORM_OPENED_WHEN_OPERATING;
    QPushButton *BTN_RESUME;
    QPushButton *BTN_DO_INITIALIZING;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1920, 1080);
        MainWindow->setStyleSheet(QString::fromUtf8("background-color: #FFC600;"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        BTN_EXIT = new QPushButton(centralWidget);
        BTN_EXIT->setObjectName(QString::fromUtf8("BTN_EXIT"));
        BTN_EXIT->setGeometry(QRect(1800, 0, 89, 110));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/build/image/powerw.png"), QSize(), QIcon::Normal, QIcon::Off);
        BTN_EXIT->setIcon(icon);
        BTN_EXIT->setIconSize(QSize(60, 60));
        BTN_EXIT->setFlat(true);
        BTN_UI_LOCK = new QPushButton(centralWidget);
        BTN_UI_LOCK->setObjectName(QString::fromUtf8("BTN_UI_LOCK"));
        BTN_UI_LOCK->setGeometry(QRect(1580, 0, 89, 110));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/build/image/lockw.png"), QSize(), QIcon::Normal, QIcon::Off);
        BTN_UI_LOCK->setIcon(icon1);
        BTN_UI_LOCK->setIconSize(QSize(60, 60));
        BTN_UI_LOCK->setFlat(true);
        FRAME_DEVICE = new QFrame(centralWidget);
        FRAME_DEVICE->setObjectName(QString::fromUtf8("FRAME_DEVICE"));
        FRAME_DEVICE->setGeometry(QRect(0, 110, 401, 971));
        FRAME_DEVICE->setStyleSheet(QString::fromUtf8("background-color: rgb(239, 239, 239);"));
        FRAME_DEVICE->setFrameShape(QFrame::NoFrame);
        FRAME_DEVICE->setFrameShadow(QFrame::Raised);
        BTN_SETTING = new QPushButton(centralWidget);
        BTN_SETTING->setObjectName(QString::fromUtf8("BTN_SETTING"));
        BTN_SETTING->setGeometry(QRect(1680, 0, 111, 110));
        QFont font;
        font.setPointSize(16);
        font.setBold(true);
        font.setWeight(75);
        BTN_SETTING->setFont(font);
        BTN_SETTING->setStyleSheet(QString::fromUtf8("background-color: #FFC600;"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/build/image/settingw.png"), QSize(), QIcon::Normal, QIcon::Off);
        BTN_SETTING->setIcon(icon2);
        BTN_SETTING->setIconSize(QSize(60, 60));
        BTN_SETTING->setFlat(true);
        FRAME = new QFrame(centralWidget);
        FRAME->setObjectName(QString::fromUtf8("FRAME"));
        FRAME->setGeometry(QRect(400, 110, 1521, 971));
        FRAME->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"QLabel{ \n"
"   border: 0px solid\n"
"} \n"
"font: 9pt \"\355\225\250\354\264\210\353\241\254\353\217\213\354\233\200\";"));
        FRAME->setFrameShape(QFrame::NoFrame);
        FRAME->setFrameShadow(QFrame::Raised);
        FRAME->setLineWidth(3);
        FRAME_COFFEE = new QFrame(FRAME);
        FRAME_COFFEE->setObjectName(QString::fromUtf8("FRAME_COFFEE"));
        FRAME_COFFEE->setGeometry(QRect(1160, 560, 331, 211));
        FRAME_COFFEE->setStyleSheet(QString::fromUtf8("QFrame { \n"
"   border: 1px solid #595959 \n"
"} \n"
"QLabel {\n"
"	font: 10pt \"\355\225\250\354\264\210\353\241\254\353\217\213\354\233\200\";\n"
"}\n"
"QPushButton {\n"
"	border:1px solid #595959;\n"
"	font: 15pt \"\355\225\250\354\264\210\353\241\254\353\217\213\354\233\200\"; \n"
"}\n"
"QLineEdit {\n"
"	font: 10pt \"\355\225\250\354\264\210\353\241\254\353\217\213\354\233\200\";\n"
"}"));
        FRAME_COFFEE->setFrameShape(QFrame::Box);
        FRAME_COFFEE->setFrameShadow(QFrame::Raised);
        FRAME_COFFEE->setLineWidth(2);
        BTN_DEV_INFO_COFFEE = new QPushButton(FRAME_COFFEE);
        BTN_DEV_INFO_COFFEE->setObjectName(QString::fromUtf8("BTN_DEV_INFO_COFFEE"));
        BTN_DEV_INFO_COFFEE->setGeometry(QRect(0, 0, 331, 50));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\355\225\250\354\264\210\353\241\254\353\217\213\354\233\200"));
        font1.setPointSize(15);
        font1.setBold(false);
        font1.setItalic(false);
        font1.setWeight(50);
        BTN_DEV_INFO_COFFEE->setFont(font1);
        layoutWidget = new QWidget(FRAME_COFFEE);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(20, 60, 291, 48));
        gridLayout_8 = new QGridLayout(layoutWidget);
        gridLayout_8->setSpacing(6);
        gridLayout_8->setContentsMargins(11, 11, 11, 11);
        gridLayout_8->setObjectName(QString::fromUtf8("gridLayout_8"));
        gridLayout_8->setContentsMargins(0, 0, 0, 0);
        label_124 = new QLabel(layoutWidget);
        label_124->setObjectName(QString::fromUtf8("label_124"));
        label_124->setMaximumSize(QSize(50, 16777215));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\355\225\250\354\264\210\353\241\254\353\217\213\354\233\200"));
        font2.setPointSize(10);
        font2.setBold(false);
        font2.setItalic(false);
        font2.setWeight(50);
        label_124->setFont(font2);
        label_124->setStyleSheet(QString::fromUtf8("QLabel{ \n"
"   border: 0px solid\n"
"} "));
        label_124->setAlignment(Qt::AlignCenter);

        gridLayout_8->addWidget(label_124, 0, 0, 1, 1);

        label_125 = new QLabel(layoutWidget);
        label_125->setObjectName(QString::fromUtf8("label_125"));
        label_125->setMaximumSize(QSize(50, 16777215));
        label_125->setFont(font2);
        label_125->setStyleSheet(QString::fromUtf8("QLabel{ \n"
"   border: 0px solid\n"
"} "));
        label_125->setAlignment(Qt::AlignCenter);

        gridLayout_8->addWidget(label_125, 0, 1, 1, 1);

        label_127 = new QLabel(layoutWidget);
        label_127->setObjectName(QString::fromUtf8("label_127"));
        label_127->setMaximumSize(QSize(50, 16777215));
        label_127->setFont(font2);
        label_127->setStyleSheet(QString::fromUtf8("QLabel{ \n"
"   border: 0px solid\n"
"} "));
        label_127->setAlignment(Qt::AlignCenter);

        gridLayout_8->addWidget(label_127, 0, 2, 1, 1);

        label_126 = new QLabel(layoutWidget);
        label_126->setObjectName(QString::fromUtf8("label_126"));
        label_126->setMaximumSize(QSize(50, 16777215));
        label_126->setFont(font2);
        label_126->setStyleSheet(QString::fromUtf8("QLabel{ \n"
"   border: 0px solid\n"
"} "));
        label_126->setAlignment(Qt::AlignCenter);

        gridLayout_8->addWidget(label_126, 0, 3, 1, 1);

        label_128 = new QLabel(layoutWidget);
        label_128->setObjectName(QString::fromUtf8("label_128"));
        label_128->setMaximumSize(QSize(50, 16777215));
        label_128->setFont(font2);
        label_128->setStyleSheet(QString::fromUtf8("QLabel{ \n"
"   border: 0px solid\n"
"} "));
        label_128->setAlignment(Qt::AlignCenter);

        gridLayout_8->addWidget(label_128, 0, 4, 1, 1);

        LE_MACHINE_STATUS_NOT_CONNECTED = new QLineEdit(layoutWidget);
        LE_MACHINE_STATUS_NOT_CONNECTED->setObjectName(QString::fromUtf8("LE_MACHINE_STATUS_NOT_CONNECTED"));
        LE_MACHINE_STATUS_NOT_CONNECTED->setMaximumSize(QSize(50, 16777215));
        LE_MACHINE_STATUS_NOT_CONNECTED->setFont(font2);
        LE_MACHINE_STATUS_NOT_CONNECTED->setReadOnly(true);

        gridLayout_8->addWidget(LE_MACHINE_STATUS_NOT_CONNECTED, 1, 0, 1, 1);

        LE_MACHINE_STATUS_PREPAREING = new QLineEdit(layoutWidget);
        LE_MACHINE_STATUS_PREPAREING->setObjectName(QString::fromUtf8("LE_MACHINE_STATUS_PREPAREING"));
        LE_MACHINE_STATUS_PREPAREING->setMaximumSize(QSize(50, 16777215));
        LE_MACHINE_STATUS_PREPAREING->setFont(font2);
        LE_MACHINE_STATUS_PREPAREING->setReadOnly(true);

        gridLayout_8->addWidget(LE_MACHINE_STATUS_PREPAREING, 1, 1, 1, 1);

        LE_MACHINE_STATUS_ERROR_OCCURED = new QLineEdit(layoutWidget);
        LE_MACHINE_STATUS_ERROR_OCCURED->setObjectName(QString::fromUtf8("LE_MACHINE_STATUS_ERROR_OCCURED"));
        LE_MACHINE_STATUS_ERROR_OCCURED->setMaximumSize(QSize(50, 16777215));
        LE_MACHINE_STATUS_ERROR_OCCURED->setFont(font2);
        LE_MACHINE_STATUS_ERROR_OCCURED->setReadOnly(true);

        gridLayout_8->addWidget(LE_MACHINE_STATUS_ERROR_OCCURED, 1, 2, 1, 1);

        LE_MACHINE_STATUS_ON_READY = new QLineEdit(layoutWidget);
        LE_MACHINE_STATUS_ON_READY->setObjectName(QString::fromUtf8("LE_MACHINE_STATUS_ON_READY"));
        LE_MACHINE_STATUS_ON_READY->setMaximumSize(QSize(50, 16777215));
        LE_MACHINE_STATUS_ON_READY->setFont(font2);
        LE_MACHINE_STATUS_ON_READY->setReadOnly(true);

        gridLayout_8->addWidget(LE_MACHINE_STATUS_ON_READY, 1, 3, 1, 1);

        LE_MACHINE_STATUS_MAKING = new QLineEdit(layoutWidget);
        LE_MACHINE_STATUS_MAKING->setObjectName(QString::fromUtf8("LE_MACHINE_STATUS_MAKING"));
        LE_MACHINE_STATUS_MAKING->setMaximumSize(QSize(50, 16777215));
        LE_MACHINE_STATUS_MAKING->setFont(font2);
        LE_MACHINE_STATUS_MAKING->setReadOnly(true);

        gridLayout_8->addWidget(LE_MACHINE_STATUS_MAKING, 1, 4, 1, 1);

        layoutWidget_2 = new QWidget(FRAME_COFFEE);
        layoutWidget_2->setObjectName(QString::fromUtf8("layoutWidget_2"));
        layoutWidget_2->setGeometry(QRect(20, 110, 217, 91));
        gridLayout_9 = new QGridLayout(layoutWidget_2);
        gridLayout_9->setSpacing(6);
        gridLayout_9->setContentsMargins(11, 11, 11, 11);
        gridLayout_9->setObjectName(QString::fromUtf8("gridLayout_9"));
        gridLayout_9->setContentsMargins(0, 0, 0, 0);
        label_111 = new QLabel(layoutWidget_2);
        label_111->setObjectName(QString::fromUtf8("label_111"));
        label_111->setMinimumSize(QSize(80, 0));
        label_111->setFont(font2);
        label_111->setStyleSheet(QString::fromUtf8("QLabel{ \n"
"   border: 0px solid\n"
"} "));
        label_111->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_9->addWidget(label_111, 0, 0, 1, 1);

        LE_SYS_CLEAN_TIME_HOUR = new QLineEdit(layoutWidget_2);
        LE_SYS_CLEAN_TIME_HOUR->setObjectName(QString::fromUtf8("LE_SYS_CLEAN_TIME_HOUR"));
        LE_SYS_CLEAN_TIME_HOUR->setMaximumSize(QSize(20, 16777215));
        LE_SYS_CLEAN_TIME_HOUR->setFont(font2);
        LE_SYS_CLEAN_TIME_HOUR->setReadOnly(true);

        gridLayout_9->addWidget(LE_SYS_CLEAN_TIME_HOUR, 0, 1, 1, 1);

        label_114 = new QLabel(layoutWidget_2);
        label_114->setObjectName(QString::fromUtf8("label_114"));
        label_114->setFont(font2);
        label_114->setStyleSheet(QString::fromUtf8("QLabel{ \n"
"   border: 0px solid\n"
"} "));
        label_114->setAlignment(Qt::AlignCenter);

        gridLayout_9->addWidget(label_114, 0, 2, 1, 1);

        LE_SYS_CLEAN_TIME_MINUTE = new QLineEdit(layoutWidget_2);
        LE_SYS_CLEAN_TIME_MINUTE->setObjectName(QString::fromUtf8("LE_SYS_CLEAN_TIME_MINUTE"));
        LE_SYS_CLEAN_TIME_MINUTE->setMaximumSize(QSize(20, 16777215));
        LE_SYS_CLEAN_TIME_MINUTE->setFont(font2);
        LE_SYS_CLEAN_TIME_MINUTE->setReadOnly(true);

        gridLayout_9->addWidget(LE_SYS_CLEAN_TIME_MINUTE, 0, 3, 1, 1);

        label_115 = new QLabel(layoutWidget_2);
        label_115->setObjectName(QString::fromUtf8("label_115"));
        label_115->setFont(font2);
        label_115->setStyleSheet(QString::fromUtf8("QLabel{ \n"
"   border: 0px solid\n"
"} "));
        label_115->setAlignment(Qt::AlignCenter);

        gridLayout_9->addWidget(label_115, 0, 4, 1, 1);

        LE_SYS_CLEAN_TIME_SECOND = new QLineEdit(layoutWidget_2);
        LE_SYS_CLEAN_TIME_SECOND->setObjectName(QString::fromUtf8("LE_SYS_CLEAN_TIME_SECOND"));
        LE_SYS_CLEAN_TIME_SECOND->setMaximumSize(QSize(20, 16777215));
        LE_SYS_CLEAN_TIME_SECOND->setFont(font2);
        LE_SYS_CLEAN_TIME_SECOND->setReadOnly(true);

        gridLayout_9->addWidget(LE_SYS_CLEAN_TIME_SECOND, 0, 5, 1, 1);

        label_116 = new QLabel(layoutWidget_2);
        label_116->setObjectName(QString::fromUtf8("label_116"));
        label_116->setFont(font2);
        label_116->setStyleSheet(QString::fromUtf8("QLabel{ \n"
"   border: 0px solid\n"
"} "));
        label_116->setAlignment(Qt::AlignCenter);

        gridLayout_9->addWidget(label_116, 0, 6, 1, 1);

        label_112 = new QLabel(layoutWidget_2);
        label_112->setObjectName(QString::fromUtf8("label_112"));
        label_112->setMinimumSize(QSize(80, 0));
        label_112->setFont(font2);
        label_112->setStyleSheet(QString::fromUtf8("QLabel{ \n"
"   border: 0px solid\n"
"} "));
        label_112->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_9->addWidget(label_112, 1, 0, 1, 1);

        LE_MILK_CLEAN_TIME_HOUR = new QLineEdit(layoutWidget_2);
        LE_MILK_CLEAN_TIME_HOUR->setObjectName(QString::fromUtf8("LE_MILK_CLEAN_TIME_HOUR"));
        LE_MILK_CLEAN_TIME_HOUR->setMaximumSize(QSize(20, 16777215));
        LE_MILK_CLEAN_TIME_HOUR->setFont(font2);
        LE_MILK_CLEAN_TIME_HOUR->setReadOnly(true);

        gridLayout_9->addWidget(LE_MILK_CLEAN_TIME_HOUR, 1, 1, 1, 1);

        label_118 = new QLabel(layoutWidget_2);
        label_118->setObjectName(QString::fromUtf8("label_118"));
        label_118->setFont(font2);
        label_118->setStyleSheet(QString::fromUtf8("QLabel{ \n"
"   border: 0px solid\n"
"} "));
        label_118->setAlignment(Qt::AlignCenter);

        gridLayout_9->addWidget(label_118, 1, 2, 1, 1);

        LE_MILK_CLEAN_TIME_MINUTE = new QLineEdit(layoutWidget_2);
        LE_MILK_CLEAN_TIME_MINUTE->setObjectName(QString::fromUtf8("LE_MILK_CLEAN_TIME_MINUTE"));
        LE_MILK_CLEAN_TIME_MINUTE->setMaximumSize(QSize(20, 16777215));
        LE_MILK_CLEAN_TIME_MINUTE->setFont(font2);
        LE_MILK_CLEAN_TIME_MINUTE->setReadOnly(true);

        gridLayout_9->addWidget(LE_MILK_CLEAN_TIME_MINUTE, 1, 3, 1, 1);

        label_119 = new QLabel(layoutWidget_2);
        label_119->setObjectName(QString::fromUtf8("label_119"));
        label_119->setFont(font2);
        label_119->setStyleSheet(QString::fromUtf8("QLabel{ \n"
"   border: 0px solid\n"
"} "));
        label_119->setAlignment(Qt::AlignCenter);

        gridLayout_9->addWidget(label_119, 1, 4, 1, 1);

        LE_MILK_CLEAN_TIME_SECOND = new QLineEdit(layoutWidget_2);
        LE_MILK_CLEAN_TIME_SECOND->setObjectName(QString::fromUtf8("LE_MILK_CLEAN_TIME_SECOND"));
        LE_MILK_CLEAN_TIME_SECOND->setMaximumSize(QSize(20, 16777215));
        LE_MILK_CLEAN_TIME_SECOND->setFont(font2);
        LE_MILK_CLEAN_TIME_SECOND->setReadOnly(true);

        gridLayout_9->addWidget(LE_MILK_CLEAN_TIME_SECOND, 1, 5, 1, 1);

        label_117 = new QLabel(layoutWidget_2);
        label_117->setObjectName(QString::fromUtf8("label_117"));
        label_117->setFont(font2);
        label_117->setStyleSheet(QString::fromUtf8("QLabel{ \n"
"   border: 0px solid\n"
"} "));
        label_117->setAlignment(Qt::AlignCenter);

        gridLayout_9->addWidget(label_117, 1, 6, 1, 1);

        label_113 = new QLabel(layoutWidget_2);
        label_113->setObjectName(QString::fromUtf8("label_113"));
        label_113->setMinimumSize(QSize(80, 0));
        label_113->setFont(font2);
        label_113->setStyleSheet(QString::fromUtf8("QLabel{ \n"
"   border: 0px solid\n"
"} "));
        label_113->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_9->addWidget(label_113, 2, 0, 1, 1);

        LE_MILK_REPLACE_TIME_HOUR = new QLineEdit(layoutWidget_2);
        LE_MILK_REPLACE_TIME_HOUR->setObjectName(QString::fromUtf8("LE_MILK_REPLACE_TIME_HOUR"));
        LE_MILK_REPLACE_TIME_HOUR->setMaximumSize(QSize(20, 16777215));
        LE_MILK_REPLACE_TIME_HOUR->setFont(font2);
        LE_MILK_REPLACE_TIME_HOUR->setReadOnly(true);

        gridLayout_9->addWidget(LE_MILK_REPLACE_TIME_HOUR, 2, 1, 1, 1);

        label_121 = new QLabel(layoutWidget_2);
        label_121->setObjectName(QString::fromUtf8("label_121"));
        label_121->setFont(font2);
        label_121->setStyleSheet(QString::fromUtf8("QLabel{ \n"
"   border: 0px solid\n"
"} "));
        label_121->setAlignment(Qt::AlignCenter);

        gridLayout_9->addWidget(label_121, 2, 2, 1, 1);

        LE_MILK_REPLACE_TIME_MINUTE = new QLineEdit(layoutWidget_2);
        LE_MILK_REPLACE_TIME_MINUTE->setObjectName(QString::fromUtf8("LE_MILK_REPLACE_TIME_MINUTE"));
        LE_MILK_REPLACE_TIME_MINUTE->setMaximumSize(QSize(20, 16777215));
        LE_MILK_REPLACE_TIME_MINUTE->setFont(font2);
        LE_MILK_REPLACE_TIME_MINUTE->setReadOnly(true);

        gridLayout_9->addWidget(LE_MILK_REPLACE_TIME_MINUTE, 2, 3, 1, 1);

        label_122 = new QLabel(layoutWidget_2);
        label_122->setObjectName(QString::fromUtf8("label_122"));
        label_122->setFont(font2);
        label_122->setStyleSheet(QString::fromUtf8("QLabel{ \n"
"   border: 0px solid\n"
"} "));
        label_122->setAlignment(Qt::AlignCenter);

        gridLayout_9->addWidget(label_122, 2, 4, 1, 1);

        LE_MILK_REPLACE_TIME_SECOND = new QLineEdit(layoutWidget_2);
        LE_MILK_REPLACE_TIME_SECOND->setObjectName(QString::fromUtf8("LE_MILK_REPLACE_TIME_SECOND"));
        LE_MILK_REPLACE_TIME_SECOND->setMaximumSize(QSize(20, 16777215));
        LE_MILK_REPLACE_TIME_SECOND->setFont(font2);
        LE_MILK_REPLACE_TIME_SECOND->setReadOnly(true);

        gridLayout_9->addWidget(LE_MILK_REPLACE_TIME_SECOND, 2, 5, 1, 1);

        label_120 = new QLabel(layoutWidget_2);
        label_120->setObjectName(QString::fromUtf8("label_120"));
        label_120->setFont(font2);
        label_120->setStyleSheet(QString::fromUtf8("QLabel{ \n"
"   border: 0px solid\n"
"} "));
        label_120->setAlignment(Qt::AlignCenter);

        gridLayout_9->addWidget(label_120, 2, 6, 1, 1);

        layoutWidget_3 = new QWidget(FRAME_COFFEE);
        layoutWidget_3->setObjectName(QString::fromUtf8("layoutWidget_3"));
        layoutWidget_3->setGeometry(QRect(260, 110, 52, 91));
        verticalLayout = new QVBoxLayout(layoutWidget_3);
        verticalLayout->setSpacing(0);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label_123 = new QLabel(layoutWidget_3);
        label_123->setObjectName(QString::fromUtf8("label_123"));
        label_123->setMaximumSize(QSize(50, 16777215));
        label_123->setFont(font2);
        label_123->setStyleSheet(QString::fromUtf8("QLabel{ \n"
"   border: 0px solid\n"
"} "));
        label_123->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_123);

        LE_MACHINE_STATUS_SYS_CLEANING = new QLineEdit(layoutWidget_3);
        LE_MACHINE_STATUS_SYS_CLEANING->setObjectName(QString::fromUtf8("LE_MACHINE_STATUS_SYS_CLEANING"));
        LE_MACHINE_STATUS_SYS_CLEANING->setMaximumSize(QSize(50, 16777215));
        LE_MACHINE_STATUS_SYS_CLEANING->setFont(font2);
        LE_MACHINE_STATUS_SYS_CLEANING->setReadOnly(true);

        verticalLayout->addWidget(LE_MACHINE_STATUS_SYS_CLEANING);

        LE_MACHINE_STATUS_MILK_CLEANING = new QLineEdit(layoutWidget_3);
        LE_MACHINE_STATUS_MILK_CLEANING->setObjectName(QString::fromUtf8("LE_MACHINE_STATUS_MILK_CLEANING"));
        LE_MACHINE_STATUS_MILK_CLEANING->setMaximumSize(QSize(50, 16777215));
        LE_MACHINE_STATUS_MILK_CLEANING->setFont(font2);
        LE_MACHINE_STATUS_MILK_CLEANING->setReadOnly(true);

        verticalLayout->addWidget(LE_MACHINE_STATUS_MILK_CLEANING);

        LE_MACHINE_STATUS_MILK_REPLACING = new QLineEdit(layoutWidget_3);
        LE_MACHINE_STATUS_MILK_REPLACING->setObjectName(QString::fromUtf8("LE_MACHINE_STATUS_MILK_REPLACING"));
        LE_MACHINE_STATUS_MILK_REPLACING->setMaximumSize(QSize(50, 16777215));
        LE_MACHINE_STATUS_MILK_REPLACING->setFont(font2);
        LE_MACHINE_STATUS_MILK_REPLACING->setReadOnly(true);

        verticalLayout->addWidget(LE_MACHINE_STATUS_MILK_REPLACING);

        FRAME_ICE_1 = new QFrame(FRAME);
        FRAME_ICE_1->setObjectName(QString::fromUtf8("FRAME_ICE_1"));
        FRAME_ICE_1->setGeometry(QRect(1190, 20, 301, 131));
        FRAME_ICE_1->setStyleSheet(QString::fromUtf8("QFrame { \n"
"   border: 1px solid #595959 \n"
"} \n"
"QLabel {\n"
"	font: 10pt \"\355\225\250\354\264\210\353\241\254\353\217\213\354\233\200\";\n"
"}\n"
"QPushButton {\n"
"	border:1px solid #595959;\n"
"	font: 15pt \"\355\225\250\354\264\210\353\241\254\353\217\213\354\233\200\"; \n"
"}\n"
"QLineEdit {\n"
"	font: 10pt \"\355\225\250\354\264\210\353\241\254\353\217\213\354\233\200\";\n"
"}"));
        FRAME_ICE_1->setFrameShape(QFrame::Box);
        FRAME_ICE_1->setFrameShadow(QFrame::Raised);
        FRAME_ICE_1->setLineWidth(2);
        BTN_DEV_INFO_ICE_1 = new QPushButton(FRAME_ICE_1);
        BTN_DEV_INFO_ICE_1->setObjectName(QString::fromUtf8("BTN_DEV_INFO_ICE_1"));
        BTN_DEV_INFO_ICE_1->setGeometry(QRect(0, 0, 301, 50));
        BTN_DEV_INFO_ICE_1->setFont(font1);
        layoutWidget_4 = new QWidget(FRAME_ICE_1);
        layoutWidget_4->setObjectName(QString::fromUtf8("layoutWidget_4"));
        layoutWidget_4->setGeometry(QRect(40, 70, 211, 42));
        gridLayout_7 = new QGridLayout(layoutWidget_4);
        gridLayout_7->setSpacing(6);
        gridLayout_7->setContentsMargins(11, 11, 11, 11);
        gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
        gridLayout_7->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget_4);
        label->setObjectName(QString::fromUtf8("label"));
        label->setFont(font2);
        label->setStyleSheet(QString::fromUtf8("QLabel{ \n"
"   border: 0px solid\n"
"} "));
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_7->addWidget(label, 0, 0, 1, 1);

        LB_ICE_1_FULL = new QLabel(layoutWidget_4);
        LB_ICE_1_FULL->setObjectName(QString::fromUtf8("LB_ICE_1_FULL"));
        LB_ICE_1_FULL->setFont(font2);
        LB_ICE_1_FULL->setStyleSheet(QString::fromUtf8("QLabel{ \n"
"   border: 0px solid\n"
"} "));
        LB_ICE_1_FULL->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_7->addWidget(LB_ICE_1_FULL, 0, 1, 1, 1);

        label_2 = new QLabel(layoutWidget_4);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font2);
        label_2->setStyleSheet(QString::fromUtf8("QLabel{ \n"
"   border: 0px solid\n"
"} "));
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_7->addWidget(label_2, 1, 0, 1, 1);

        LB_ICE_1_ERROR = new QLabel(layoutWidget_4);
        LB_ICE_1_ERROR->setObjectName(QString::fromUtf8("LB_ICE_1_ERROR"));
        LB_ICE_1_ERROR->setFont(font2);
        LB_ICE_1_ERROR->setStyleSheet(QString::fromUtf8("QLabel{ \n"
"   border: 0px solid\n"
"} "));
        LB_ICE_1_ERROR->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_7->addWidget(LB_ICE_1_ERROR, 1, 1, 1, 1);

        FRAME_SODA = new QFrame(FRAME);
        FRAME_SODA->setObjectName(QString::fromUtf8("FRAME_SODA"));
        FRAME_SODA->setGeometry(QRect(30, 340, 301, 141));
        FRAME_SODA->setStyleSheet(QString::fromUtf8("QFrame { \n"
"   border: 1px solid #595959 \n"
"} \n"
"QLabel {\n"
"	font: 10pt \"\355\225\250\354\264\210\353\241\254\353\217\213\354\233\200\";\n"
"}\n"
"QPushButton {\n"
"	border:1px solid #595959;\n"
"	font: 15pt \"\355\225\250\354\264\210\353\241\254\353\217\213\354\233\200\"; \n"
"}\n"
"QLineEdit {\n"
"	font: 10pt \"\355\225\250\354\264\210\353\241\254\353\217\213\354\233\200\";\n"
"}"));
        FRAME_SODA->setFrameShape(QFrame::StyledPanel);
        FRAME_SODA->setFrameShadow(QFrame::Raised);
        BTN_DEV_INFO_SODA = new QPushButton(FRAME_SODA);
        BTN_DEV_INFO_SODA->setObjectName(QString::fromUtf8("BTN_DEV_INFO_SODA"));
        BTN_DEV_INFO_SODA->setGeometry(QRect(0, 0, 301, 50));
        BTN_DEV_INFO_SODA->setFont(font1);
        layoutWidget_5 = new QWidget(FRAME_SODA);
        layoutWidget_5->setObjectName(QString::fromUtf8("layoutWidget_5"));
        layoutWidget_5->setGeometry(QRect(80, 60, 111, 65));
        gridLayout_4 = new QGridLayout(layoutWidget_5);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        gridLayout_4->setContentsMargins(0, 0, 0, 0);
        label_16 = new QLabel(layoutWidget_5);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setFont(font2);
        label_16->setStyleSheet(QString::fromUtf8("QLabel{ \n"
"   border: 0px solid\n"
"} "));
        label_16->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_4->addWidget(label_16, 0, 0, 1, 1);

        LB_SODA_LOADCELL = new QLabel(layoutWidget_5);
        LB_SODA_LOADCELL->setObjectName(QString::fromUtf8("LB_SODA_LOADCELL"));
        LB_SODA_LOADCELL->setFont(font2);
        LB_SODA_LOADCELL->setStyleSheet(QString::fromUtf8("QLabel{ \n"
"   border: 0px solid\n"
"} "));
        LB_SODA_LOADCELL->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_4->addWidget(LB_SODA_LOADCELL, 0, 1, 1, 1);

        label_15 = new QLabel(layoutWidget_5);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setFont(font2);
        label_15->setStyleSheet(QString::fromUtf8("QLabel{ \n"
"   border: 0px solid\n"
"} "));
        label_15->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_4->addWidget(label_15, 1, 0, 1, 1);

        LB_SODA_LAST_ERROR = new QLabel(layoutWidget_5);
        LB_SODA_LAST_ERROR->setObjectName(QString::fromUtf8("LB_SODA_LAST_ERROR"));
        LB_SODA_LAST_ERROR->setFont(font2);
        LB_SODA_LAST_ERROR->setStyleSheet(QString::fromUtf8("QLabel{ \n"
"   border: 0px solid\n"
"} "));
        LB_SODA_LAST_ERROR->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_4->addWidget(LB_SODA_LAST_ERROR, 1, 1, 1, 1);

        label_14 = new QLabel(layoutWidget_5);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setFont(font2);
        label_14->setStyleSheet(QString::fromUtf8("QLabel{ \n"
"   border: 0px solid\n"
"} "));
        label_14->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_4->addWidget(label_14, 2, 0, 1, 1);

        LB_SODA_OP_STATE = new QLabel(layoutWidget_5);
        LB_SODA_OP_STATE->setObjectName(QString::fromUtf8("LB_SODA_OP_STATE"));
        LB_SODA_OP_STATE->setFont(font2);
        LB_SODA_OP_STATE->setStyleSheet(QString::fromUtf8("QLabel{ \n"
"   border: 0px solid\n"
"} "));
        LB_SODA_OP_STATE->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_4->addWidget(LB_SODA_OP_STATE, 2, 1, 1, 1);

        FRAME_SYRUP = new QFrame(FRAME);
        FRAME_SYRUP->setObjectName(QString::fromUtf8("FRAME_SYRUP"));
        FRAME_SYRUP->setGeometry(QRect(30, 180, 301, 141));
        FRAME_SYRUP->setStyleSheet(QString::fromUtf8("QFrame { \n"
"   border: 1px solid #595959 \n"
"} \n"
"QLabel {\n"
"	font: 10pt \"\355\225\250\354\264\210\353\241\254\353\217\213\354\233\200\";\n"
"}\n"
"QPushButton {\n"
"	border:1px solid #595959;\n"
"	font: 15pt \"\355\225\250\354\264\210\353\241\254\353\217\213\354\233\200\"; \n"
"}\n"
"QLineEdit {\n"
"	font: 10pt \"\355\225\250\354\264\210\353\241\254\353\217\213\354\233\200\";\n"
"}"));
        FRAME_SYRUP->setFrameShape(QFrame::StyledPanel);
        FRAME_SYRUP->setFrameShadow(QFrame::Raised);
        BTN_DEV_INFO_SYRUP = new QPushButton(FRAME_SYRUP);
        BTN_DEV_INFO_SYRUP->setObjectName(QString::fromUtf8("BTN_DEV_INFO_SYRUP"));
        BTN_DEV_INFO_SYRUP->setGeometry(QRect(0, 0, 301, 50));
        BTN_DEV_INFO_SYRUP->setFont(font1);
        layoutWidget_6 = new QWidget(FRAME_SYRUP);
        layoutWidget_6->setObjectName(QString::fromUtf8("layoutWidget_6"));
        layoutWidget_6->setGeometry(QRect(80, 60, 111, 65));
        gridLayout_3 = new QGridLayout(layoutWidget_6);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        label_5 = new QLabel(layoutWidget_6);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setFont(font2);
        label_5->setStyleSheet(QString::fromUtf8("QLabel{ \n"
"   border: 0px solid\n"
"} "));
        label_5->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_3->addWidget(label_5, 0, 0, 1, 1);

        LB_SYRUP_LOADCELL = new QLabel(layoutWidget_6);
        LB_SYRUP_LOADCELL->setObjectName(QString::fromUtf8("LB_SYRUP_LOADCELL"));
        LB_SYRUP_LOADCELL->setFont(font2);
        LB_SYRUP_LOADCELL->setStyleSheet(QString::fromUtf8("QLabel{ \n"
"   border: 0px solid\n"
"} "));
        LB_SYRUP_LOADCELL->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_3->addWidget(LB_SYRUP_LOADCELL, 0, 1, 1, 1);

        label_6 = new QLabel(layoutWidget_6);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setFont(font2);
        label_6->setStyleSheet(QString::fromUtf8("QLabel{ \n"
"   border: 0px solid\n"
"} "));
        label_6->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_3->addWidget(label_6, 1, 0, 1, 1);

        LB_SYRUP_LAST_ERROR = new QLabel(layoutWidget_6);
        LB_SYRUP_LAST_ERROR->setObjectName(QString::fromUtf8("LB_SYRUP_LAST_ERROR"));
        LB_SYRUP_LAST_ERROR->setFont(font2);
        LB_SYRUP_LAST_ERROR->setStyleSheet(QString::fromUtf8("QLabel{ \n"
"   border: 0px solid\n"
"} "));
        LB_SYRUP_LAST_ERROR->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_3->addWidget(LB_SYRUP_LAST_ERROR, 1, 1, 1, 1);

        label_7 = new QLabel(layoutWidget_6);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setFont(font2);
        label_7->setStyleSheet(QString::fromUtf8("QLabel{ \n"
"   border: 0px solid\n"
"} "));
        label_7->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_3->addWidget(label_7, 2, 0, 1, 1);

        LB_SYRUP_OP_STATE = new QLabel(layoutWidget_6);
        LB_SYRUP_OP_STATE->setObjectName(QString::fromUtf8("LB_SYRUP_OP_STATE"));
        LB_SYRUP_OP_STATE->setFont(font2);
        LB_SYRUP_OP_STATE->setStyleSheet(QString::fromUtf8("QLabel{ \n"
"   border: 0px solid\n"
"} "));
        LB_SYRUP_OP_STATE->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_3->addWidget(LB_SYRUP_OP_STATE, 2, 1, 1, 1);

        FRAME_OUTLET = new QFrame(FRAME);
        FRAME_OUTLET->setObjectName(QString::fromUtf8("FRAME_OUTLET"));
        FRAME_OUTLET->setGeometry(QRect(430, 760, 421, 181));
        FRAME_OUTLET->setStyleSheet(QString::fromUtf8("QFrame { \n"
"   border: 1px solid #595959 \n"
"} \n"
"QLabel {\n"
"	font: 10pt \"\355\225\250\354\264\210\353\241\254\353\217\213\354\233\200\";\n"
"}\n"
"QPushButton {\n"
"	border:1px solid #595959;\n"
"	font: 15pt \"\355\225\250\354\264\210\353\241\254\353\217\213\354\233\200\"; \n"
"}\n"
"QLineEdit {\n"
"	font: 10pt \"\355\225\250\354\264\210\353\241\254\353\217\213\354\233\200\";\n"
"}"));
        FRAME_OUTLET->setFrameShape(QFrame::StyledPanel);
        FRAME_OUTLET->setFrameShadow(QFrame::Raised);
        BTN_DEV_INFO_OUTLET = new QPushButton(FRAME_OUTLET);
        BTN_DEV_INFO_OUTLET->setObjectName(QString::fromUtf8("BTN_DEV_INFO_OUTLET"));
        BTN_DEV_INFO_OUTLET->setGeometry(QRect(0, 0, 421, 50));
        BTN_DEV_INFO_OUTLET->setFont(font1);
        LE_OUTLET_M_1_DOOR_OPEN = new QLineEdit(FRAME_OUTLET);
        LE_OUTLET_M_1_DOOR_OPEN->setObjectName(QString::fromUtf8("LE_OUTLET_M_1_DOOR_OPEN"));
        LE_OUTLET_M_1_DOOR_OPEN->setGeometry(QRect(30, 60, 41, 31));
        LE_OUTLET_M_1_DOOR_OPEN->setAlignment(Qt::AlignCenter);
        LE_OUTLET_M_1_DOOR_OPEN->setReadOnly(true);
        LE_OUTLET_M_1_DOOR_CLOSE = new QLineEdit(FRAME_OUTLET);
        LE_OUTLET_M_1_DOOR_CLOSE->setObjectName(QString::fromUtf8("LE_OUTLET_M_1_DOOR_CLOSE"));
        LE_OUTLET_M_1_DOOR_CLOSE->setGeometry(QRect(70, 60, 41, 31));
        LE_OUTLET_M_1_DOOR_CLOSE->setAlignment(Qt::AlignCenter);
        LE_OUTLET_M_1_DOOR_CLOSE->setReadOnly(true);
        LE_OUTLET_M_1_CUP_DETECT = new QLineEdit(FRAME_OUTLET);
        LE_OUTLET_M_1_CUP_DETECT->setObjectName(QString::fromUtf8("LE_OUTLET_M_1_CUP_DETECT"));
        LE_OUTLET_M_1_CUP_DETECT->setGeometry(QRect(120, 60, 51, 31));
        LE_OUTLET_M_1_CUP_DETECT->setReadOnly(true);
        LE_OUTLET_M_2_DOOR_OPEN = new QLineEdit(FRAME_OUTLET);
        LE_OUTLET_M_2_DOOR_OPEN->setObjectName(QString::fromUtf8("LE_OUTLET_M_2_DOOR_OPEN"));
        LE_OUTLET_M_2_DOOR_OPEN->setGeometry(QRect(240, 60, 41, 31));
        LE_OUTLET_M_2_DOOR_OPEN->setAlignment(Qt::AlignCenter);
        LE_OUTLET_M_2_DOOR_OPEN->setReadOnly(true);
        LE_OUTLET_M_2_DOOR_CLOSE = new QLineEdit(FRAME_OUTLET);
        LE_OUTLET_M_2_DOOR_CLOSE->setObjectName(QString::fromUtf8("LE_OUTLET_M_2_DOOR_CLOSE"));
        LE_OUTLET_M_2_DOOR_CLOSE->setGeometry(QRect(280, 60, 41, 31));
        LE_OUTLET_M_2_DOOR_CLOSE->setAlignment(Qt::AlignCenter);
        LE_OUTLET_M_2_DOOR_CLOSE->setReadOnly(true);
        LE_OUTLET_M_2_CUP_DETECT = new QLineEdit(FRAME_OUTLET);
        LE_OUTLET_M_2_CUP_DETECT->setObjectName(QString::fromUtf8("LE_OUTLET_M_2_CUP_DETECT"));
        LE_OUTLET_M_2_CUP_DETECT->setGeometry(QRect(340, 60, 51, 31));
        LE_OUTLET_M_2_CUP_DETECT->setReadOnly(true);
        layoutWidget_7 = new QWidget(FRAME_OUTLET);
        layoutWidget_7->setObjectName(QString::fromUtf8("layoutWidget_7"));
        layoutWidget_7->setGeometry(QRect(30, 100, 361, 71));
        gridLayout_5 = new QGridLayout(layoutWidget_7);
        gridLayout_5->setSpacing(6);
        gridLayout_5->setContentsMargins(11, 11, 11, 11);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        gridLayout_5->setContentsMargins(0, 0, 0, 0);
        LB_OUTLET_M_1_CELL_3 = new QLabel(layoutWidget_7);
        LB_OUTLET_M_1_CELL_3->setObjectName(QString::fromUtf8("LB_OUTLET_M_1_CELL_3"));
        LB_OUTLET_M_1_CELL_3->setMinimumSize(QSize(100, 0));
        LB_OUTLET_M_1_CELL_3->setFont(font2);
        LB_OUTLET_M_1_CELL_3->setStyleSheet(QString::fromUtf8("QLabel{ \n"
"   border: 0px solid\n"
"} "));
        LB_OUTLET_M_1_CELL_3->setAlignment(Qt::AlignCenter);

        gridLayout_5->addWidget(LB_OUTLET_M_1_CELL_3, 2, 1, 1, 1);

        label_22 = new QLabel(layoutWidget_7);
        label_22->setObjectName(QString::fromUtf8("label_22"));
        label_22->setFont(font2);
        label_22->setStyleSheet(QString::fromUtf8("QLabel{ \n"
"   border: 0px solid\n"
"} "));
        label_22->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_5->addWidget(label_22, 1, 0, 1, 1);

        label_26 = new QLabel(layoutWidget_7);
        label_26->setObjectName(QString::fromUtf8("label_26"));
        label_26->setFont(font2);
        label_26->setStyleSheet(QString::fromUtf8("QLabel{ \n"
"   border: 0px solid\n"
"} "));
        label_26->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_5->addWidget(label_26, 2, 3, 1, 1);

        LB_OUTLET_M_1_CELL_1 = new QLabel(layoutWidget_7);
        LB_OUTLET_M_1_CELL_1->setObjectName(QString::fromUtf8("LB_OUTLET_M_1_CELL_1"));
        LB_OUTLET_M_1_CELL_1->setMinimumSize(QSize(100, 0));
        LB_OUTLET_M_1_CELL_1->setFont(font2);
        LB_OUTLET_M_1_CELL_1->setStyleSheet(QString::fromUtf8("QLabel{ \n"
"   border: 0px solid\n"
"} "));
        LB_OUTLET_M_1_CELL_1->setAlignment(Qt::AlignCenter);

        gridLayout_5->addWidget(LB_OUTLET_M_1_CELL_1, 0, 1, 1, 1);

        label_21 = new QLabel(layoutWidget_7);
        label_21->setObjectName(QString::fromUtf8("label_21"));
        label_21->setFont(font2);
        label_21->setStyleSheet(QString::fromUtf8("QLabel{ \n"
"   border: 0px solid\n"
"} "));
        label_21->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_5->addWidget(label_21, 0, 0, 1, 1);

        LB_OUTLET_M_2_CELL_1 = new QLabel(layoutWidget_7);
        LB_OUTLET_M_2_CELL_1->setObjectName(QString::fromUtf8("LB_OUTLET_M_2_CELL_1"));
        LB_OUTLET_M_2_CELL_1->setMinimumSize(QSize(100, 0));
        LB_OUTLET_M_2_CELL_1->setFont(font2);
        LB_OUTLET_M_2_CELL_1->setStyleSheet(QString::fromUtf8("QLabel{ \n"
"   border: 0px solid\n"
"} "));
        LB_OUTLET_M_2_CELL_1->setAlignment(Qt::AlignCenter);

        gridLayout_5->addWidget(LB_OUTLET_M_2_CELL_1, 0, 4, 1, 1);

        LB_OUTLET_M_2_CELL_2 = new QLabel(layoutWidget_7);
        LB_OUTLET_M_2_CELL_2->setObjectName(QString::fromUtf8("LB_OUTLET_M_2_CELL_2"));
        LB_OUTLET_M_2_CELL_2->setMinimumSize(QSize(100, 0));
        LB_OUTLET_M_2_CELL_2->setFont(font2);
        LB_OUTLET_M_2_CELL_2->setStyleSheet(QString::fromUtf8("QLabel{ \n"
"   border: 0px solid\n"
"} "));
        LB_OUTLET_M_2_CELL_2->setAlignment(Qt::AlignCenter);

        gridLayout_5->addWidget(LB_OUTLET_M_2_CELL_2, 1, 4, 1, 1);

        LB_OUTLET_M_2_CELL_3 = new QLabel(layoutWidget_7);
        LB_OUTLET_M_2_CELL_3->setObjectName(QString::fromUtf8("LB_OUTLET_M_2_CELL_3"));
        LB_OUTLET_M_2_CELL_3->setMinimumSize(QSize(100, 0));
        LB_OUTLET_M_2_CELL_3->setFont(font2);
        LB_OUTLET_M_2_CELL_3->setStyleSheet(QString::fromUtf8("QLabel{ \n"
"   border: 0px solid\n"
"} "));
        LB_OUTLET_M_2_CELL_3->setAlignment(Qt::AlignCenter);

        gridLayout_5->addWidget(LB_OUTLET_M_2_CELL_3, 2, 4, 1, 1);

        label_24 = new QLabel(layoutWidget_7);
        label_24->setObjectName(QString::fromUtf8("label_24"));
        label_24->setFont(font2);
        label_24->setStyleSheet(QString::fromUtf8("QLabel{ \n"
"   border: 0px solid\n"
"} "));
        label_24->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_5->addWidget(label_24, 0, 3, 1, 1);

        LB_OUTLET_M_1_CELL_2 = new QLabel(layoutWidget_7);
        LB_OUTLET_M_1_CELL_2->setObjectName(QString::fromUtf8("LB_OUTLET_M_1_CELL_2"));
        LB_OUTLET_M_1_CELL_2->setMinimumSize(QSize(100, 0));
        LB_OUTLET_M_1_CELL_2->setFont(font2);
        LB_OUTLET_M_1_CELL_2->setStyleSheet(QString::fromUtf8("QLabel{ \n"
"   border: 0px solid\n"
"} "));
        LB_OUTLET_M_1_CELL_2->setAlignment(Qt::AlignCenter);

        gridLayout_5->addWidget(LB_OUTLET_M_1_CELL_2, 1, 1, 1, 1);

        label_25 = new QLabel(layoutWidget_7);
        label_25->setObjectName(QString::fromUtf8("label_25"));
        label_25->setFont(font2);
        label_25->setStyleSheet(QString::fromUtf8("QLabel{ \n"
"   border: 0px solid\n"
"} "));
        label_25->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_5->addWidget(label_25, 1, 3, 1, 1);

        label_23 = new QLabel(layoutWidget_7);
        label_23->setObjectName(QString::fromUtf8("label_23"));
        label_23->setFont(font2);
        label_23->setStyleSheet(QString::fromUtf8("QLabel{ \n"
"   border: 0px solid\n"
"} "));
        label_23->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_5->addWidget(label_23, 2, 0, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_5->addItem(horizontalSpacer, 1, 2, 1, 1);

        FRAME_MONITOR = new QFrame(FRAME);
        FRAME_MONITOR->setObjectName(QString::fromUtf8("FRAME_MONITOR"));
        FRAME_MONITOR->setGeometry(QRect(500, 20, 291, 151));
        FRAME_MONITOR->setStyleSheet(QString::fromUtf8("QFrame { \n"
"   border: 1px solid #595959 \n"
"} \n"
"QLabel {\n"
"	font: 10pt \"\355\225\250\354\264\210\353\241\254\353\217\213\354\233\200\";\n"
"}\n"
"QPushButton {\n"
"	border:1px solid #595959;\n"
"	font: 15pt \"\355\225\250\354\264\210\353\241\254\353\217\213\354\233\200\"; \n"
"}\n"
"QLineEdit {\n"
"	font: 10pt \"\355\225\250\354\264\210\353\241\254\353\217\213\354\233\200\";\n"
"}"));
        FRAME_MONITOR->setFrameShape(QFrame::StyledPanel);
        FRAME_MONITOR->setFrameShadow(QFrame::Raised);
        BTN_DEV_INFO_MONITOR = new QPushButton(FRAME_MONITOR);
        BTN_DEV_INFO_MONITOR->setObjectName(QString::fromUtf8("BTN_DEV_INFO_MONITOR"));
        BTN_DEV_INFO_MONITOR->setGeometry(QRect(0, 0, 291, 50));
        BTN_DEV_INFO_MONITOR->setFont(font1);
        layoutWidget_8 = new QWidget(FRAME_MONITOR);
        layoutWidget_8->setObjectName(QString::fromUtf8("layoutWidget_8"));
        layoutWidget_8->setGeometry(QRect(60, 70, 171, 65));
        gridLayout_6 = new QGridLayout(layoutWidget_8);
        gridLayout_6->setSpacing(6);
        gridLayout_6->setContentsMargins(11, 11, 11, 11);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        gridLayout_6->setContentsMargins(0, 0, 0, 0);
        label_18 = new QLabel(layoutWidget_8);
        label_18->setObjectName(QString::fromUtf8("label_18"));
        label_18->setFont(font2);
        label_18->setStyleSheet(QString::fromUtf8("QLabel{ \n"
"   border: 0px solid\n"
"} "));
        label_18->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_6->addWidget(label_18, 0, 0, 1, 1);

        LB_MONITOR_INPROGRESS = new QLabel(layoutWidget_8);
        LB_MONITOR_INPROGRESS->setObjectName(QString::fromUtf8("LB_MONITOR_INPROGRESS"));
        LB_MONITOR_INPROGRESS->setFont(font2);
        LB_MONITOR_INPROGRESS->setStyleSheet(QString::fromUtf8("QLabel{ \n"
"   border: 0px solid\n"
"} "));
        LB_MONITOR_INPROGRESS->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_6->addWidget(LB_MONITOR_INPROGRESS, 0, 1, 1, 1);

        label_19 = new QLabel(layoutWidget_8);
        label_19->setObjectName(QString::fromUtf8("label_19"));
        label_19->setFont(font2);
        label_19->setStyleSheet(QString::fromUtf8("QLabel{ \n"
"   border: 0px solid\n"
"} "));
        label_19->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_6->addWidget(label_19, 1, 0, 1, 1);

        LB_MONITOR_WAITING = new QLabel(layoutWidget_8);
        LB_MONITOR_WAITING->setObjectName(QString::fromUtf8("LB_MONITOR_WAITING"));
        LB_MONITOR_WAITING->setFont(font2);
        LB_MONITOR_WAITING->setStyleSheet(QString::fromUtf8("QLabel{ \n"
"   border: 0px solid\n"
"} "));
        LB_MONITOR_WAITING->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_6->addWidget(LB_MONITOR_WAITING, 1, 1, 1, 1);

        label_20 = new QLabel(layoutWidget_8);
        label_20->setObjectName(QString::fromUtf8("label_20"));
        label_20->setFont(font2);
        label_20->setStyleSheet(QString::fromUtf8("QLabel{ \n"
"   border: 0px solid\n"
"} "));
        label_20->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_6->addWidget(label_20, 2, 0, 1, 1);

        LB_MONITOR_COMPLETED = new QLabel(layoutWidget_8);
        LB_MONITOR_COMPLETED->setObjectName(QString::fromUtf8("LB_MONITOR_COMPLETED"));
        LB_MONITOR_COMPLETED->setFont(font2);
        LB_MONITOR_COMPLETED->setStyleSheet(QString::fromUtf8("QLabel{ \n"
"   border: 0px solid\n"
"} "));
        LB_MONITOR_COMPLETED->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_6->addWidget(LB_MONITOR_COMPLETED, 2, 1, 1, 1);

        FRAME_CUP = new QFrame(FRAME);
        FRAME_CUP->setObjectName(QString::fromUtf8("FRAME_CUP"));
        FRAME_CUP->setGeometry(QRect(1190, 170, 301, 211));
        FRAME_CUP->setStyleSheet(QString::fromUtf8("QFrame { \n"
"   border: 1px solid #595959 \n"
"} \n"
"QLabel {\n"
"	font: 10pt \"\355\225\250\354\264\210\353\241\254\353\217\213\354\233\200\";\n"
"}\n"
"QPushButton {\n"
"	border:1px solid #595959;\n"
"	font: 15pt \"\355\225\250\354\264\210\353\241\254\353\217\213\354\233\200\"; \n"
"}\n"
"QLineEdit {\n"
"	font: 10pt \"\355\225\250\354\264\210\353\241\254\353\217\213\354\233\200\";\n"
"}"));
        FRAME_CUP->setFrameShape(QFrame::StyledPanel);
        FRAME_CUP->setFrameShadow(QFrame::Raised);
        BTN_DEV_INFO_CUP = new QPushButton(FRAME_CUP);
        BTN_DEV_INFO_CUP->setObjectName(QString::fromUtf8("BTN_DEV_INFO_CUP"));
        BTN_DEV_INFO_CUP->setGeometry(QRect(0, 0, 301, 50));
        BTN_DEV_INFO_CUP->setFont(font1);
        BTN_DEV_INFO_CUP->setFlat(false);
        BTN_CUP_ADD_DONE = new QPushButton(FRAME_CUP);
        BTN_CUP_ADD_DONE->setObjectName(QString::fromUtf8("BTN_CUP_ADD_DONE"));
        BTN_CUP_ADD_DONE->setGeometry(QRect(220, 140, 71, 61));
        BTN_CUP_ADD_DONE->setFont(font2);
        BTN_CUP_ADD_DONE->setStyleSheet(QString::fromUtf8("QFrame { \n"
"   border: 2px solid #595959 \n"
"} \n"
"QLabel {\n"
"	font: 10pt \"\355\225\250\354\264\210\353\241\254\353\217\213\354\233\200\";\n"
"}\n"
"QPushButton {\n"
"	font: 10pt \"\355\225\250\354\264\210\353\241\254\353\217\213\354\233\200\"; \n"
"}\n"
"QLineEdit {\n"
"	font: 10pt \"\355\225\250\354\264\210\353\241\254\353\217\213\354\233\200\";\n"
"}"));
        layoutWidget_9 = new QWidget(FRAME_CUP);
        layoutWidget_9->setObjectName(QString::fromUtf8("layoutWidget_9"));
        layoutWidget_9->setGeometry(QRect(20, 60, 191, 141));
        gridLayout_11 = new QGridLayout(layoutWidget_9);
        gridLayout_11->setSpacing(6);
        gridLayout_11->setContentsMargins(11, 11, 11, 11);
        gridLayout_11->setObjectName(QString::fromUtf8("gridLayout_11"));
        gridLayout_11->setContentsMargins(0, 0, 0, 0);
        label_27 = new QLabel(layoutWidget_9);
        label_27->setObjectName(QString::fromUtf8("label_27"));
        label_27->setFont(font2);
        label_27->setStyleSheet(QString::fromUtf8("QLabel{ \n"
"   border: 0px solid\n"
"} "));
        label_27->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_11->addWidget(label_27, 0, 1, 1, 1);

        label_33 = new QLabel(layoutWidget_9);
        label_33->setObjectName(QString::fromUtf8("label_33"));
        label_33->setFont(font2);
        label_33->setStyleSheet(QString::fromUtf8("QLabel{ \n"
"   border: 0px solid\n"
"} "));
        label_33->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_11->addWidget(label_33, 0, 2, 1, 1);

        label_30 = new QLabel(layoutWidget_9);
        label_30->setObjectName(QString::fromUtf8("label_30"));
        label_30->setFont(font2);
        label_30->setStyleSheet(QString::fromUtf8("QLabel{ \n"
"   border: 0px solid\n"
"} "));
        label_30->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_11->addWidget(label_30, 1, 0, 1, 1);

        LB_CUP_1_LAST_ERROR = new QLabel(layoutWidget_9);
        LB_CUP_1_LAST_ERROR->setObjectName(QString::fromUtf8("LB_CUP_1_LAST_ERROR"));
        LB_CUP_1_LAST_ERROR->setFont(font2);
        LB_CUP_1_LAST_ERROR->setStyleSheet(QString::fromUtf8("QLabel{ \n"
"   border: 0px solid\n"
"} "));
        LB_CUP_1_LAST_ERROR->setAlignment(Qt::AlignCenter);

        gridLayout_11->addWidget(LB_CUP_1_LAST_ERROR, 1, 1, 1, 1);

        LB_CUP_2_LAST_ERROR = new QLabel(layoutWidget_9);
        LB_CUP_2_LAST_ERROR->setObjectName(QString::fromUtf8("LB_CUP_2_LAST_ERROR"));
        LB_CUP_2_LAST_ERROR->setFont(font2);
        LB_CUP_2_LAST_ERROR->setStyleSheet(QString::fromUtf8("QLabel{ \n"
"   border: 0px solid\n"
"} "));
        LB_CUP_2_LAST_ERROR->setAlignment(Qt::AlignCenter);

        gridLayout_11->addWidget(LB_CUP_2_LAST_ERROR, 1, 2, 1, 1);

        label_29 = new QLabel(layoutWidget_9);
        label_29->setObjectName(QString::fromUtf8("label_29"));
        label_29->setFont(font2);
        label_29->setStyleSheet(QString::fromUtf8("QLabel{ \n"
"   border: 0px solid\n"
"} "));
        label_29->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_11->addWidget(label_29, 2, 0, 1, 1);

        LB_CUP_1_OP_STATE = new QLabel(layoutWidget_9);
        LB_CUP_1_OP_STATE->setObjectName(QString::fromUtf8("LB_CUP_1_OP_STATE"));
        LB_CUP_1_OP_STATE->setFont(font2);
        LB_CUP_1_OP_STATE->setStyleSheet(QString::fromUtf8("QLabel{ \n"
"   border: 0px solid\n"
"} "));
        LB_CUP_1_OP_STATE->setAlignment(Qt::AlignCenter);

        gridLayout_11->addWidget(LB_CUP_1_OP_STATE, 2, 1, 1, 1);

        LB_CUP_2_OP_STATE = new QLabel(layoutWidget_9);
        LB_CUP_2_OP_STATE->setObjectName(QString::fromUtf8("LB_CUP_2_OP_STATE"));
        LB_CUP_2_OP_STATE->setFont(font2);
        LB_CUP_2_OP_STATE->setStyleSheet(QString::fromUtf8("QLabel{ \n"
"   border: 0px solid\n"
"} "));
        LB_CUP_2_OP_STATE->setAlignment(Qt::AlignCenter);

        gridLayout_11->addWidget(LB_CUP_2_OP_STATE, 2, 2, 1, 1);

        label_28 = new QLabel(layoutWidget_9);
        label_28->setObjectName(QString::fromUtf8("label_28"));
        label_28->setFont(font2);
        label_28->setStyleSheet(QString::fromUtf8("QLabel{ \n"
"   border: 0px solid\n"
"} "));
        label_28->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_11->addWidget(label_28, 3, 1, 1, 1);

        label_34 = new QLabel(layoutWidget_9);
        label_34->setObjectName(QString::fromUtf8("label_34"));
        label_34->setFont(font2);
        label_34->setStyleSheet(QString::fromUtf8("QLabel{ \n"
"   border: 0px solid\n"
"} "));
        label_34->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_11->addWidget(label_34, 3, 2, 1, 1);

        label_31 = new QLabel(layoutWidget_9);
        label_31->setObjectName(QString::fromUtf8("label_31"));
        label_31->setFont(font2);
        label_31->setStyleSheet(QString::fromUtf8("QLabel{ \n"
"   border: 0px solid\n"
"} "));
        label_31->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_11->addWidget(label_31, 4, 0, 1, 1);

        LB_CUP_3_LAST_ERROR = new QLabel(layoutWidget_9);
        LB_CUP_3_LAST_ERROR->setObjectName(QString::fromUtf8("LB_CUP_3_LAST_ERROR"));
        LB_CUP_3_LAST_ERROR->setFont(font2);
        LB_CUP_3_LAST_ERROR->setStyleSheet(QString::fromUtf8("QLabel{ \n"
"   border: 0px solid\n"
"} "));
        LB_CUP_3_LAST_ERROR->setAlignment(Qt::AlignCenter);

        gridLayout_11->addWidget(LB_CUP_3_LAST_ERROR, 4, 1, 1, 1);

        LB_CUP_4_LAST_ERROR = new QLabel(layoutWidget_9);
        LB_CUP_4_LAST_ERROR->setObjectName(QString::fromUtf8("LB_CUP_4_LAST_ERROR"));
        LB_CUP_4_LAST_ERROR->setFont(font2);
        LB_CUP_4_LAST_ERROR->setStyleSheet(QString::fromUtf8("QLabel{ \n"
"   border: 0px solid\n"
"} "));
        LB_CUP_4_LAST_ERROR->setAlignment(Qt::AlignCenter);

        gridLayout_11->addWidget(LB_CUP_4_LAST_ERROR, 4, 2, 1, 1);

        label_32 = new QLabel(layoutWidget_9);
        label_32->setObjectName(QString::fromUtf8("label_32"));
        label_32->setFont(font2);
        label_32->setStyleSheet(QString::fromUtf8("QLabel{ \n"
"   border: 0px solid\n"
"} "));
        label_32->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_11->addWidget(label_32, 5, 0, 1, 1);

        LB_CUP_3_OP_STATE = new QLabel(layoutWidget_9);
        LB_CUP_3_OP_STATE->setObjectName(QString::fromUtf8("LB_CUP_3_OP_STATE"));
        LB_CUP_3_OP_STATE->setFont(font2);
        LB_CUP_3_OP_STATE->setStyleSheet(QString::fromUtf8("QLabel{ \n"
"   border: 0px solid\n"
"} "));
        LB_CUP_3_OP_STATE->setAlignment(Qt::AlignCenter);

        gridLayout_11->addWidget(LB_CUP_3_OP_STATE, 5, 1, 1, 1);

        LB_CUP_4_OP_STATE = new QLabel(layoutWidget_9);
        LB_CUP_4_OP_STATE->setObjectName(QString::fromUtf8("LB_CUP_4_OP_STATE"));
        LB_CUP_4_OP_STATE->setFont(font2);
        LB_CUP_4_OP_STATE->setStyleSheet(QString::fromUtf8("QLabel{ \n"
"   border: 0px solid\n"
"} "));
        LB_CUP_4_OP_STATE->setAlignment(Qt::AlignCenter);

        gridLayout_11->addWidget(LB_CUP_4_OP_STATE, 5, 2, 1, 1);

        FRAME_ROBOT = new QFrame(FRAME);
        FRAME_ROBOT->setObjectName(QString::fromUtf8("FRAME_ROBOT"));
        FRAME_ROBOT->setGeometry(QRect(510, 430, 311, 191));
        FRAME_ROBOT->setStyleSheet(QString::fromUtf8("QFrame { \n"
"   border: 1px solid #595959 \n"
"} \n"
"QLabel {\n"
"	font: 10pt \"\355\225\250\354\264\210\353\241\254\353\217\213\354\233\200\";\n"
"}\n"
"QPushButton {\n"
"	border:1px solid #595959;\n"
"	font: 15pt \"\355\225\250\354\264\210\353\241\254\353\217\213\354\233\200\"; \n"
"}\n"
"QLineEdit {\n"
"	font: 10pt \"\355\225\250\354\264\210\353\241\254\353\217\213\354\233\200\";\n"
"}"));
        FRAME_ROBOT->setFrameShape(QFrame::StyledPanel);
        FRAME_ROBOT->setFrameShadow(QFrame::Raised);
        BTN_DEV_INFO_ROBOT = new QPushButton(FRAME_ROBOT);
        BTN_DEV_INFO_ROBOT->setObjectName(QString::fromUtf8("BTN_DEV_INFO_ROBOT"));
        BTN_DEV_INFO_ROBOT->setGeometry(QRect(0, 0, 311, 50));
        BTN_DEV_INFO_ROBOT->setFont(font1);
        label_91 = new QLabel(FRAME_ROBOT);
        label_91->setObjectName(QString::fromUtf8("label_91"));
        label_91->setGeometry(QRect(10, 60, 91, 21));
        label_91->setFont(font2);
        label_91->setStyleSheet(QString::fromUtf8("QLabel{ \n"
"   border: 0px solid\n"
"} "));
        label_91->setAlignment(Qt::AlignCenter);
        LE_ROBOT_PRG_CONNECT = new QLineEdit(FRAME_ROBOT);
        LE_ROBOT_PRG_CONNECT->setObjectName(QString::fromUtf8("LE_ROBOT_PRG_CONNECT"));
        LE_ROBOT_PRG_CONNECT->setGeometry(QRect(150, 60, 51, 21));
        LE_ROBOT_PRG_CONNECT->setAlignment(Qt::AlignCenter);
        LE_ROBOT_PRG_CONNECT->setReadOnly(true);
        LE_ROBOT_PRG_WORKING_STATUS = new QLineEdit(FRAME_ROBOT);
        LE_ROBOT_PRG_WORKING_STATUS->setObjectName(QString::fromUtf8("LE_ROBOT_PRG_WORKING_STATUS"));
        LE_ROBOT_PRG_WORKING_STATUS->setGeometry(QRect(100, 60, 51, 21));
        LE_ROBOT_PRG_WORKING_STATUS->setAlignment(Qt::AlignCenter);
        LE_ROBOT_PRG_WORKING_STATUS->setReadOnly(true);
        line = new QFrame(FRAME_ROBOT);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(230, 50, 2, 171));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);
        LE_ROBOT_INIT_BASE_ANGLE = new QLineEdit(FRAME_ROBOT);
        LE_ROBOT_INIT_BASE_ANGLE->setObjectName(QString::fromUtf8("LE_ROBOT_INIT_BASE_ANGLE"));
        LE_ROBOT_INIT_BASE_ANGLE->setGeometry(QRect(240, 90, 51, 21));
        LE_ROBOT_INIT_BASE_ANGLE->setFont(font2);
        LE_ROBOT_INIT_BASE_ANGLE->setAlignment(Qt::AlignCenter);
        LE_ROBOT_INIT_BASE_ANGLE->setReadOnly(true);
        LE_ROBOT_INIT_POSITION = new QLineEdit(FRAME_ROBOT);
        LE_ROBOT_INIT_POSITION->setObjectName(QString::fromUtf8("LE_ROBOT_INIT_POSITION"));
        LE_ROBOT_INIT_POSITION->setGeometry(QRect(240, 120, 51, 21));
        LE_ROBOT_INIT_POSITION->setFont(font2);
        LE_ROBOT_INIT_POSITION->setAlignment(Qt::AlignCenter);
        LE_ROBOT_INIT_POSITION->setReadOnly(true);
        label_92 = new QLabel(FRAME_ROBOT);
        label_92->setObjectName(QString::fromUtf8("label_92"));
        label_92->setGeometry(QRect(240, 60, 51, 21));
        label_92->setFont(font2);
        label_92->setStyleSheet(QString::fromUtf8("QLabel{ \n"
"   border: 0px solid\n"
"} "));
        label_92->setAlignment(Qt::AlignCenter);
        layoutWidget_10 = new QWidget(FRAME_ROBOT);
        layoutWidget_10->setObjectName(QString::fromUtf8("layoutWidget_10"));
        layoutWidget_10->setGeometry(QRect(10, 100, 212, 74));
        gridLayout_10 = new QGridLayout(layoutWidget_10);
        gridLayout_10->setSpacing(0);
        gridLayout_10->setContentsMargins(11, 11, 11, 11);
        gridLayout_10->setObjectName(QString::fromUtf8("gridLayout_10"));
        gridLayout_10->setContentsMargins(0, 0, 0, 0);
        LE_ROBOT_STATE_MOVING = new QLineEdit(layoutWidget_10);
        LE_ROBOT_STATE_MOVING->setObjectName(QString::fromUtf8("LE_ROBOT_STATE_MOVING"));
        LE_ROBOT_STATE_MOVING->setMaximumSize(QSize(50, 16777215));
        LE_ROBOT_STATE_MOVING->setFont(font2);
        LE_ROBOT_STATE_MOVING->setAlignment(Qt::AlignCenter);
        LE_ROBOT_STATE_MOVING->setReadOnly(true);

        gridLayout_10->addWidget(LE_ROBOT_STATE_MOVING, 1, 1, 1, 1);

        LE_ROBOT_STATUS_TEACHING = new QLineEdit(layoutWidget_10);
        LE_ROBOT_STATUS_TEACHING->setObjectName(QString::fromUtf8("LE_ROBOT_STATUS_TEACHING"));
        LE_ROBOT_STATUS_TEACHING->setMaximumSize(QSize(60, 16777215));
        LE_ROBOT_STATUS_TEACHING->setFont(font2);
        LE_ROBOT_STATUS_TEACHING->setAlignment(Qt::AlignCenter);
        LE_ROBOT_STATUS_TEACHING->setReadOnly(true);

        gridLayout_10->addWidget(LE_ROBOT_STATUS_TEACHING, 0, 2, 1, 1);

        LE_ROBOT_STATE_IDLE = new QLineEdit(layoutWidget_10);
        LE_ROBOT_STATE_IDLE->setObjectName(QString::fromUtf8("LE_ROBOT_STATE_IDLE"));
        LE_ROBOT_STATE_IDLE->setMaximumSize(QSize(50, 16777215));
        LE_ROBOT_STATE_IDLE->setFont(font2);
        LE_ROBOT_STATE_IDLE->setAlignment(Qt::AlignCenter);
        LE_ROBOT_STATE_IDLE->setReadOnly(true);

        gridLayout_10->addWidget(LE_ROBOT_STATE_IDLE, 0, 1, 1, 1);

        LE_PG_MODE_REAL = new QLineEdit(layoutWidget_10);
        LE_PG_MODE_REAL->setObjectName(QString::fromUtf8("LE_PG_MODE_REAL"));
        LE_PG_MODE_REAL->setMaximumSize(QSize(40, 16777215));
        LE_PG_MODE_REAL->setFont(font2);
        LE_PG_MODE_REAL->setAlignment(Qt::AlignCenter);
        LE_PG_MODE_REAL->setReadOnly(true);

        gridLayout_10->addWidget(LE_PG_MODE_REAL, 0, 0, 1, 1);

        LE_PG_MODE_SIMULATION = new QLineEdit(layoutWidget_10);
        LE_PG_MODE_SIMULATION->setObjectName(QString::fromUtf8("LE_PG_MODE_SIMULATION"));
        LE_PG_MODE_SIMULATION->setMaximumSize(QSize(40, 16777215));
        LE_PG_MODE_SIMULATION->setFont(font2);
        LE_PG_MODE_SIMULATION->setAlignment(Qt::AlignCenter);
        LE_PG_MODE_SIMULATION->setReadOnly(true);

        gridLayout_10->addWidget(LE_PG_MODE_SIMULATION, 1, 0, 1, 1);

        LE_ROBOT_STATUS_SELF_COLLISION = new QLineEdit(layoutWidget_10);
        LE_ROBOT_STATUS_SELF_COLLISION->setObjectName(QString::fromUtf8("LE_ROBOT_STATUS_SELF_COLLISION"));
        LE_ROBOT_STATUS_SELF_COLLISION->setMaximumSize(QSize(60, 16777215));
        LE_ROBOT_STATUS_SELF_COLLISION->setFont(font2);
        LE_ROBOT_STATUS_SELF_COLLISION->setAlignment(Qt::AlignCenter);
        LE_ROBOT_STATUS_SELF_COLLISION->setReadOnly(true);

        gridLayout_10->addWidget(LE_ROBOT_STATUS_SELF_COLLISION, 2, 2, 1, 1);

        LE_ROBOT_STATUS_EXT_COLLISION = new QLineEdit(layoutWidget_10);
        LE_ROBOT_STATUS_EXT_COLLISION->setObjectName(QString::fromUtf8("LE_ROBOT_STATUS_EXT_COLLISION"));
        LE_ROBOT_STATUS_EXT_COLLISION->setMaximumSize(QSize(60, 16777215));
        LE_ROBOT_STATUS_EXT_COLLISION->setFont(font2);
        LE_ROBOT_STATUS_EXT_COLLISION->setAlignment(Qt::AlignCenter);
        LE_ROBOT_STATUS_EXT_COLLISION->setReadOnly(true);

        gridLayout_10->addWidget(LE_ROBOT_STATUS_EXT_COLLISION, 1, 2, 1, 1);

        LE_ROBOT_STATUS_PAUSED = new QLineEdit(layoutWidget_10);
        LE_ROBOT_STATUS_PAUSED->setObjectName(QString::fromUtf8("LE_ROBOT_STATUS_PAUSED"));
        LE_ROBOT_STATUS_PAUSED->setMaximumSize(QSize(60, 16777215));
        LE_ROBOT_STATUS_PAUSED->setFont(font2);
        LE_ROBOT_STATUS_PAUSED->setAlignment(Qt::AlignCenter);
        LE_ROBOT_STATUS_PAUSED->setReadOnly(true);

        gridLayout_10->addWidget(LE_ROBOT_STATUS_PAUSED, 0, 3, 1, 1);

        LE_ROBOT_STATUS_EMS = new QLineEdit(layoutWidget_10);
        LE_ROBOT_STATUS_EMS->setObjectName(QString::fromUtf8("LE_ROBOT_STATUS_EMS"));
        LE_ROBOT_STATUS_EMS->setMaximumSize(QSize(60, 16777215));
        LE_ROBOT_STATUS_EMS->setFont(font2);
        LE_ROBOT_STATUS_EMS->setAlignment(Qt::AlignCenter);
        LE_ROBOT_STATUS_EMS->setReadOnly(true);

        gridLayout_10->addWidget(LE_ROBOT_STATUS_EMS, 1, 3, 1, 1);

        LE_ROBOT_STATUS_SOS = new QLineEdit(layoutWidget_10);
        LE_ROBOT_STATUS_SOS->setObjectName(QString::fromUtf8("LE_ROBOT_STATUS_SOS"));
        LE_ROBOT_STATUS_SOS->setMaximumSize(QSize(60, 16777215));
        LE_ROBOT_STATUS_SOS->setFont(font2);
        LE_ROBOT_STATUS_SOS->setAlignment(Qt::AlignCenter);
        LE_ROBOT_STATUS_SOS->setReadOnly(true);

        gridLayout_10->addWidget(LE_ROBOT_STATUS_SOS, 2, 3, 1, 1);

        FRAME_HOT = new QFrame(FRAME);
        FRAME_HOT->setObjectName(QString::fromUtf8("FRAME_HOT"));
        FRAME_HOT->setGeometry(QRect(1190, 400, 301, 141));
        FRAME_HOT->setStyleSheet(QString::fromUtf8("QFrame { \n"
"   border: 1px solid #595959 \n"
"} \n"
"QLabel {\n"
"	font: 10pt \"\355\225\250\354\264\210\353\241\254\353\217\213\354\233\200\";\n"
"}\n"
"QPushButton {\n"
"	border:1px solid #595959;\n"
"	font: 15pt \"\355\225\250\354\264\210\353\241\254\353\217\213\354\233\200\"; \n"
"}\n"
"QLineEdit {\n"
"	font: 10pt \"\355\225\250\354\264\210\353\241\254\353\217\213\354\233\200\";\n"
"}"));
        FRAME_HOT->setFrameShape(QFrame::Box);
        FRAME_HOT->setFrameShadow(QFrame::Raised);
        FRAME_HOT->setLineWidth(2);
        BTN_DEV_INFO_HOT = new QPushButton(FRAME_HOT);
        BTN_DEV_INFO_HOT->setObjectName(QString::fromUtf8("BTN_DEV_INFO_HOT"));
        BTN_DEV_INFO_HOT->setGeometry(QRect(0, 0, 301, 50));
        BTN_DEV_INFO_HOT->setFont(font1);
        layoutWidget_11 = new QWidget(FRAME_HOT);
        layoutWidget_11->setObjectName(QString::fromUtf8("layoutWidget_11"));
        layoutWidget_11->setGeometry(QRect(40, 60, 211, 65));
        gridLayout_12 = new QGridLayout(layoutWidget_11);
        gridLayout_12->setSpacing(6);
        gridLayout_12->setContentsMargins(11, 11, 11, 11);
        gridLayout_12->setObjectName(QString::fromUtf8("gridLayout_12"));
        gridLayout_12->setContentsMargins(0, 0, 0, 0);
        label_10 = new QLabel(layoutWidget_11);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setFont(font2);
        label_10->setStyleSheet(QString::fromUtf8("QLabel{ \n"
"   border: 0px solid\n"
"} "));
        label_10->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_12->addWidget(label_10, 0, 0, 1, 1);

        LB_HOT_LOADCELL = new QLabel(layoutWidget_11);
        LB_HOT_LOADCELL->setObjectName(QString::fromUtf8("LB_HOT_LOADCELL"));
        LB_HOT_LOADCELL->setFont(font2);
        LB_HOT_LOADCELL->setStyleSheet(QString::fromUtf8("QLabel{ \n"
"   border: 0px solid\n"
"} "));
        LB_HOT_LOADCELL->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_12->addWidget(LB_HOT_LOADCELL, 0, 1, 1, 1);

        label_9 = new QLabel(layoutWidget_11);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setFont(font2);
        label_9->setStyleSheet(QString::fromUtf8("QLabel{ \n"
"   border: 0px solid\n"
"} "));
        label_9->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_12->addWidget(label_9, 1, 0, 1, 1);

        LB_HOT_LAST_ERROR = new QLabel(layoutWidget_11);
        LB_HOT_LAST_ERROR->setObjectName(QString::fromUtf8("LB_HOT_LAST_ERROR"));
        LB_HOT_LAST_ERROR->setFont(font2);
        LB_HOT_LAST_ERROR->setStyleSheet(QString::fromUtf8("QLabel{ \n"
"   border: 0px solid\n"
"} "));
        LB_HOT_LAST_ERROR->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_12->addWidget(LB_HOT_LAST_ERROR, 1, 1, 1, 1);

        label_8 = new QLabel(layoutWidget_11);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setFont(font2);
        label_8->setStyleSheet(QString::fromUtf8("QLabel{ \n"
"   border: 0px solid\n"
"} "));
        label_8->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_12->addWidget(label_8, 2, 0, 1, 1);

        LB_HOT_OP_STATE = new QLabel(layoutWidget_11);
        LB_HOT_OP_STATE->setObjectName(QString::fromUtf8("LB_HOT_OP_STATE"));
        LB_HOT_OP_STATE->setFont(font2);
        LB_HOT_OP_STATE->setStyleSheet(QString::fromUtf8("QLabel{ \n"
"   border: 0px solid\n"
"} "));
        LB_HOT_OP_STATE->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_12->addWidget(LB_HOT_OP_STATE, 2, 1, 1, 1);

        FRAME_ICECREAM = new QFrame(FRAME);
        FRAME_ICECREAM->setObjectName(QString::fromUtf8("FRAME_ICECREAM"));
        FRAME_ICECREAM->setGeometry(QRect(30, 20, 301, 141));
        FRAME_ICECREAM->setStyleSheet(QString::fromUtf8("QFrame { \n"
"   border: 1px solid #595959 \n"
"} \n"
"QLabel {\n"
"	font: 10pt \"\355\225\250\354\264\210\353\241\254\353\217\213\354\233\200\";\n"
"}\n"
"QPushButton {\n"
"	border:1px solid #595959;\n"
"	font: 15pt \"\355\225\250\354\264\210\353\241\254\353\217\213\354\233\200\"; \n"
"}\n"
"QLineEdit {\n"
"	font: 10pt \"\355\225\250\354\264\210\353\241\254\353\217\213\354\233\200\";\n"
"}"));
        FRAME_ICECREAM->setFrameShape(QFrame::StyledPanel);
        FRAME_ICECREAM->setFrameShadow(QFrame::Raised);
        BTN_DEV_INFO_ICECREAM = new QPushButton(FRAME_ICECREAM);
        BTN_DEV_INFO_ICECREAM->setObjectName(QString::fromUtf8("BTN_DEV_INFO_ICECREAM"));
        BTN_DEV_INFO_ICECREAM->setGeometry(QRect(0, 0, 301, 50));
        BTN_DEV_INFO_ICECREAM->setFont(font1);
        layoutWidget_12 = new QWidget(FRAME_ICECREAM);
        layoutWidget_12->setObjectName(QString::fromUtf8("layoutWidget_12"));
        layoutWidget_12->setGeometry(QRect(80, 60, 111, 65));
        gridLayout_2 = new QGridLayout(layoutWidget_12);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        label_13 = new QLabel(layoutWidget_12);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setFont(font2);
        label_13->setStyleSheet(QString::fromUtf8("QLabel{ \n"
"   border: 0px solid\n"
"} "));
        label_13->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_13, 0, 0, 1, 1);

        LB_ICECREAM_LOADCELL = new QLabel(layoutWidget_12);
        LB_ICECREAM_LOADCELL->setObjectName(QString::fromUtf8("LB_ICECREAM_LOADCELL"));
        LB_ICECREAM_LOADCELL->setFont(font2);
        LB_ICECREAM_LOADCELL->setStyleSheet(QString::fromUtf8("QLabel{ \n"
"   border: 0px solid\n"
"} "));
        LB_ICECREAM_LOADCELL->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_2->addWidget(LB_ICECREAM_LOADCELL, 0, 1, 1, 1);

        label_12 = new QLabel(layoutWidget_12);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setFont(font2);
        label_12->setStyleSheet(QString::fromUtf8("QLabel{ \n"
"   border: 0px solid\n"
"} "));
        label_12->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_12, 1, 0, 1, 1);

        LB_ICECREAM_LAST_ERROR = new QLabel(layoutWidget_12);
        LB_ICECREAM_LAST_ERROR->setObjectName(QString::fromUtf8("LB_ICECREAM_LAST_ERROR"));
        LB_ICECREAM_LAST_ERROR->setFont(font2);
        LB_ICECREAM_LAST_ERROR->setStyleSheet(QString::fromUtf8("QLabel{ \n"
"   border: 0px solid\n"
"} "));
        LB_ICECREAM_LAST_ERROR->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_2->addWidget(LB_ICECREAM_LAST_ERROR, 1, 1, 1, 1);

        label_11 = new QLabel(layoutWidget_12);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setFont(font2);
        label_11->setStyleSheet(QString::fromUtf8("QLabel{ \n"
"   border: 0px solid\n"
"} "));
        label_11->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_11, 2, 0, 1, 1);

        LB_ICECREAM_OP_STATE = new QLabel(layoutWidget_12);
        LB_ICECREAM_OP_STATE->setObjectName(QString::fromUtf8("LB_ICECREAM_OP_STATE"));
        LB_ICECREAM_OP_STATE->setFont(font2);
        LB_ICECREAM_OP_STATE->setStyleSheet(QString::fromUtf8("QLabel{ \n"
"   border: 0px solid\n"
"} "));
        LB_ICECREAM_OP_STATE->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_2->addWidget(LB_ICECREAM_OP_STATE, 2, 1, 1, 1);

        FRAME_BARCODE = new QFrame(FRAME);
        FRAME_BARCODE->setObjectName(QString::fromUtf8("FRAME_BARCODE"));
        FRAME_BARCODE->setGeometry(QRect(870, 760, 171, 181));
        FRAME_BARCODE->setStyleSheet(QString::fromUtf8("QFrame { \n"
"   border: 1px solid #595959 \n"
"} \n"
"QLabel {\n"
"	font: 10pt \"\355\225\250\354\264\210\353\241\254\353\217\213\354\233\200\";\n"
"}\n"
"QPushButton {\n"
"	border:1px solid #595959;\n"
"	font: 15pt \"\355\225\250\354\264\210\353\241\254\353\217\213\354\233\200\"; \n"
"}\n"
"QLineEdit {\n"
"	font: 10pt \"\355\225\250\354\264\210\353\241\254\353\217\213\354\233\200\";\n"
"}"));
        FRAME_BARCODE->setFrameShape(QFrame::StyledPanel);
        FRAME_BARCODE->setFrameShadow(QFrame::Raised);
        BTN_DEV_INFO_BARCODE = new QPushButton(FRAME_BARCODE);
        BTN_DEV_INFO_BARCODE->setObjectName(QString::fromUtf8("BTN_DEV_INFO_BARCODE"));
        BTN_DEV_INFO_BARCODE->setGeometry(QRect(0, 0, 171, 50));
        BTN_DEV_INFO_BARCODE->setFont(font1);
        label_17 = new QLabel(FRAME_BARCODE);
        label_17->setObjectName(QString::fromUtf8("label_17"));
        label_17->setGeometry(QRect(10, 60, 111, 21));
        label_17->setFont(font2);
        label_17->setStyleSheet(QString::fromUtf8("QLabel{ \n"
"   border: 0px solid\n"
"} "));
        label_17->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        LB_BARCODE_LAST_DATA = new QLabel(FRAME_BARCODE);
        LB_BARCODE_LAST_DATA->setObjectName(QString::fromUtf8("LB_BARCODE_LAST_DATA"));
        LB_BARCODE_LAST_DATA->setGeometry(QRect(10, 90, 151, 21));
        LB_BARCODE_LAST_DATA->setFont(font2);
        LB_BARCODE_LAST_DATA->setStyleSheet(QString::fromUtf8("QLabel{ \n"
"   border: 0px solid\n"
"} "));
        LB_BARCODE_LAST_DATA->setAlignment(Qt::AlignCenter);
        FRAME_DOOR = new QFrame(FRAME);
        FRAME_DOOR->setObjectName(QString::fromUtf8("FRAME_DOOR"));
        FRAME_DOOR->setGeometry(QRect(810, 20, 221, 151));
        FRAME_DOOR->setStyleSheet(QString::fromUtf8("QFrame { \n"
"   border: 1px solid #595959 \n"
"} \n"
"QLabel {\n"
"	font: 10pt \"\355\225\250\354\264\210\353\241\254\353\217\213\354\233\200\";\n"
"}\n"
"QPushButton {\n"
"	border:1px solid #595959;\n"
"	font: 15pt \"\355\225\250\354\264\210\353\241\254\353\217\213\354\233\200\"; \n"
"}\n"
"QLineEdit {\n"
"	font: 10pt \"\355\225\250\354\264\210\353\241\254\353\217\213\354\233\200\";\n"
"}"));
        FRAME_DOOR->setFrameShape(QFrame::StyledPanel);
        FRAME_DOOR->setFrameShadow(QFrame::Raised);
        BTN_DEV_INFO_DOOR = new QPushButton(FRAME_DOOR);
        BTN_DEV_INFO_DOOR->setObjectName(QString::fromUtf8("BTN_DEV_INFO_DOOR"));
        BTN_DEV_INFO_DOOR->setGeometry(QRect(0, 0, 221, 50));
        BTN_DEV_INFO_DOOR->setFont(font1);
        label_129 = new QLabel(FRAME_DOOR);
        label_129->setObjectName(QString::fromUtf8("label_129"));
        label_129->setGeometry(QRect(120, 60, 81, 21));
        label_129->setFont(font2);
        label_129->setStyleSheet(QString::fromUtf8("QLabel{ \n"
"   border: 0px solid\n"
"} "));
        label_129->setAlignment(Qt::AlignCenter);
        LE_DOOR_CLOSED = new QLineEdit(FRAME_DOOR);
        LE_DOOR_CLOSED->setObjectName(QString::fromUtf8("LE_DOOR_CLOSED"));
        LE_DOOR_CLOSED->setGeometry(QRect(120, 90, 81, 51));
        LE_DOOR_CLOSED->setFont(font2);
        LE_DOOR_CLOSED->setReadOnly(true);
        label_130 = new QLabel(FRAME_DOOR);
        label_130->setObjectName(QString::fromUtf8("label_130"));
        label_130->setGeometry(QRect(20, 60, 81, 21));
        label_130->setFont(font2);
        label_130->setStyleSheet(QString::fromUtf8("QLabel{ \n"
"   border: 0px solid\n"
"} "));
        label_130->setAlignment(Qt::AlignCenter);
        LE_DOOR_OPENED = new QLineEdit(FRAME_DOOR);
        LE_DOOR_OPENED->setObjectName(QString::fromUtf8("LE_DOOR_OPENED"));
        LE_DOOR_OPENED->setGeometry(QRect(20, 90, 81, 51));
        LE_DOOR_OPENED->setFont(font2);
        LE_DOOR_OPENED->setReadOnly(true);
        FRAME_KIOSK = new QFrame(FRAME);
        FRAME_KIOSK->setObjectName(QString::fromUtf8("FRAME_KIOSK"));
        FRAME_KIOSK->setGeometry(QRect(270, 760, 141, 181));
        FRAME_KIOSK->setStyleSheet(QString::fromUtf8("QFrame { \n"
"   border: 1px solid #595959 \n"
"} \n"
"QLabel {\n"
"	font: 10pt \"\355\225\250\354\264\210\353\241\254\353\217\213\354\233\200\";\n"
"}\n"
"QPushButton {\n"
"	border:1px solid #595959;\n"
"	font: 15pt \"\355\225\250\354\264\210\353\241\254\353\217\213\354\233\200\"; \n"
"}\n"
"QLineEdit {\n"
"	font: 10pt \"\355\225\250\354\264\210\353\241\254\353\217\213\354\233\200\";\n"
"}"));
        FRAME_KIOSK->setFrameShape(QFrame::StyledPanel);
        FRAME_KIOSK->setFrameShadow(QFrame::Raised);
        BTN_DEV_INFO_KIOSK = new QPushButton(FRAME_KIOSK);
        BTN_DEV_INFO_KIOSK->setObjectName(QString::fromUtf8("BTN_DEV_INFO_KIOSK"));
        BTN_DEV_INFO_KIOSK->setGeometry(QRect(0, 0, 141, 50));
        BTN_DEV_INFO_KIOSK->setFont(font1);
        LB_KIOSK_BLOCK_ORDER = new QLabel(FRAME_KIOSK);
        LB_KIOSK_BLOCK_ORDER->setObjectName(QString::fromUtf8("LB_KIOSK_BLOCK_ORDER"));
        LB_KIOSK_BLOCK_ORDER->setGeometry(QRect(10, 80, 121, 31));
        LB_KIOSK_BLOCK_ORDER->setFont(font2);
        LB_KIOSK_BLOCK_ORDER->setStyleSheet(QString::fromUtf8("QLabel{ \n"
"   border: 0px solid\n"
"} "));
        LB_KIOSK_BLOCK_ORDER->setAlignment(Qt::AlignCenter);
        FRAME_STOCK = new QFrame(FRAME);
        FRAME_STOCK->setObjectName(QString::fromUtf8("FRAME_STOCK"));
        FRAME_STOCK->setGeometry(QRect(840, 430, 181, 191));
        FRAME_STOCK->setStyleSheet(QString::fromUtf8("QFrame { \n"
"   border: 1px solid #595959 \n"
"} \n"
"QLabel {\n"
"	font: 10pt \"\355\225\250\354\264\210\353\241\254\353\217\213\354\233\200\";\n"
"}\n"
"QPushButton {\n"
"	border:1px solid #595959;\n"
"	font: 15pt \"\355\225\250\354\264\210\353\241\254\353\217\213\354\233\200\"; \n"
"}\n"
"QLineEdit {\n"
"	font: 10pt \"\355\225\250\354\264\210\353\241\254\353\217\213\354\233\200\";\n"
"}"));
        FRAME_STOCK->setFrameShape(QFrame::StyledPanel);
        FRAME_STOCK->setFrameShadow(QFrame::Raised);
        BTN_DEV_INFO_STOCK = new QPushButton(FRAME_STOCK);
        BTN_DEV_INFO_STOCK->setObjectName(QString::fromUtf8("BTN_DEV_INFO_STOCK"));
        BTN_DEV_INFO_STOCK->setGeometry(QRect(0, 0, 181, 50));
        BTN_DEV_INFO_STOCK->setFont(font1);
        label_35 = new QLabel(FRAME);
        label_35->setObjectName(QString::fromUtf8("label_35"));
        label_35->setGeometry(QRect(1340, 790, 150, 150));
        label_35->setPixmap(QPixmap(QString::fromUtf8(":/build/image/qqyu.png")));
        label_35->setScaledContents(true);
        FRAME_ICE_2 = new QFrame(FRAME);
        FRAME_ICE_2->setObjectName(QString::fromUtf8("FRAME_ICE_2"));
        FRAME_ICE_2->setGeometry(QRect(30, 500, 301, 131));
        FRAME_ICE_2->setStyleSheet(QString::fromUtf8("QFrame { \n"
"   border: 1px solid #595959 \n"
"} \n"
"QLabel {\n"
"	font: 10pt \"\355\225\250\354\264\210\353\241\254\353\217\213\354\233\200\";\n"
"}\n"
"QPushButton {\n"
"	border:1px solid #595959;\n"
"	font: 15pt \"\355\225\250\354\264\210\353\241\254\353\217\213\354\233\200\"; \n"
"}\n"
"QLineEdit {\n"
"	font: 10pt \"\355\225\250\354\264\210\353\241\254\353\217\213\354\233\200\";\n"
"}"));
        FRAME_ICE_2->setFrameShape(QFrame::Box);
        FRAME_ICE_2->setFrameShadow(QFrame::Raised);
        FRAME_ICE_2->setLineWidth(2);
        BTN_DEV_INFO_ICE_2 = new QPushButton(FRAME_ICE_2);
        BTN_DEV_INFO_ICE_2->setObjectName(QString::fromUtf8("BTN_DEV_INFO_ICE_2"));
        BTN_DEV_INFO_ICE_2->setGeometry(QRect(0, 0, 301, 50));
        BTN_DEV_INFO_ICE_2->setFont(font1);
        layoutWidget_13 = new QWidget(FRAME_ICE_2);
        layoutWidget_13->setObjectName(QString::fromUtf8("layoutWidget_13"));
        layoutWidget_13->setGeometry(QRect(40, 70, 211, 42));
        gridLayout_13 = new QGridLayout(layoutWidget_13);
        gridLayout_13->setSpacing(6);
        gridLayout_13->setContentsMargins(11, 11, 11, 11);
        gridLayout_13->setObjectName(QString::fromUtf8("gridLayout_13"));
        gridLayout_13->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(layoutWidget_13);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setFont(font2);
        label_3->setStyleSheet(QString::fromUtf8("QLabel{ \n"
"   border: 0px solid\n"
"} "));
        label_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_13->addWidget(label_3, 0, 0, 1, 1);

        LB_ICE_2_FULL = new QLabel(layoutWidget_13);
        LB_ICE_2_FULL->setObjectName(QString::fromUtf8("LB_ICE_2_FULL"));
        LB_ICE_2_FULL->setFont(font2);
        LB_ICE_2_FULL->setStyleSheet(QString::fromUtf8("QLabel{ \n"
"   border: 0px solid\n"
"} "));
        LB_ICE_2_FULL->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_13->addWidget(LB_ICE_2_FULL, 0, 1, 1, 1);

        label_4 = new QLabel(layoutWidget_13);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setFont(font2);
        label_4->setStyleSheet(QString::fromUtf8("QLabel{ \n"
"   border: 0px solid\n"
"} "));
        label_4->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_13->addWidget(label_4, 1, 0, 1, 1);

        LB_ICE_2_ERROR = new QLabel(layoutWidget_13);
        LB_ICE_2_ERROR->setObjectName(QString::fromUtf8("LB_ICE_2_ERROR"));
        LB_ICE_2_ERROR->setFont(font2);
        LB_ICE_2_ERROR->setStyleSheet(QString::fromUtf8("QLabel{ \n"
"   border: 0px solid\n"
"} "));
        LB_ICE_2_ERROR->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_13->addWidget(LB_ICE_2_ERROR, 1, 1, 1, 1);

        label_35->raise();
        FRAME_COFFEE->raise();
        FRAME_ICE_1->raise();
        FRAME_SODA->raise();
        FRAME_SYRUP->raise();
        FRAME_OUTLET->raise();
        FRAME_MONITOR->raise();
        FRAME_CUP->raise();
        FRAME_ROBOT->raise();
        FRAME_HOT->raise();
        FRAME_ICECREAM->raise();
        FRAME_BARCODE->raise();
        FRAME_DOOR->raise();
        FRAME_KIOSK->raise();
        FRAME_STOCK->raise();
        FRAME_ICE_2->raise();
        layoutWidget_14 = new QWidget(centralWidget);
        layoutWidget_14->setObjectName(QString::fromUtf8("layoutWidget_14"));
        layoutWidget_14->setGeometry(QRect(10, 10, 381, 91));
        gridLayout = new QGridLayout(layoutWidget_14);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label_135 = new QLabel(layoutWidget_14);
        label_135->setObjectName(QString::fromUtf8("label_135"));
        label_135->setMinimumSize(QSize(100, 0));
        QFont font3;
        font3.setFamily(QString::fromUtf8("\355\225\250\354\264\210\353\241\254\353\217\213\354\233\200"));
        font3.setPointSize(18);
        font3.setBold(true);
        font3.setWeight(75);
        label_135->setFont(font3);
        label_135->setStyleSheet(QString::fromUtf8(""));
        label_135->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_135, 0, 0, 1, 1);

        LE_PLATFORM_INITIALIZING = new QLineEdit(layoutWidget_14);
        LE_PLATFORM_INITIALIZING->setObjectName(QString::fromUtf8("LE_PLATFORM_INITIALIZING"));
        QFont font4;
        font4.setPointSize(8);
        LE_PLATFORM_INITIALIZING->setFont(font4);
        LE_PLATFORM_INITIALIZING->setAutoFillBackground(false);
        LE_PLATFORM_INITIALIZING->setReadOnly(true);

        gridLayout->addWidget(LE_PLATFORM_INITIALIZING, 0, 1, 1, 1);

        label_147 = new QLabel(layoutWidget_14);
        label_147->setObjectName(QString::fromUtf8("label_147"));
        label_147->setMinimumSize(QSize(100, 0));
        QFont font5;
        font5.setFamily(QString::fromUtf8("\355\225\250\354\264\210\353\241\254\353\217\213\354\233\200"));
        font5.setPointSize(18);
        font5.setBold(true);
        font5.setWeight(75);
        font5.setKerning(false);
        label_147->setFont(font5);
        label_147->setStyleSheet(QString::fromUtf8(""));
        label_147->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_147, 0, 2, 1, 1);

        LE_PLATFORM_WAITING_STOP = new QLineEdit(layoutWidget_14);
        LE_PLATFORM_WAITING_STOP->setObjectName(QString::fromUtf8("LE_PLATFORM_WAITING_STOP"));
        LE_PLATFORM_WAITING_STOP->setFont(font4);
        LE_PLATFORM_WAITING_STOP->setAutoFillBackground(false);
        LE_PLATFORM_WAITING_STOP->setReadOnly(true);

        gridLayout->addWidget(LE_PLATFORM_WAITING_STOP, 0, 3, 1, 1);

        label_146 = new QLabel(layoutWidget_14);
        label_146->setObjectName(QString::fromUtf8("label_146"));
        label_146->setMinimumSize(QSize(100, 0));
        label_146->setFont(font3);
        label_146->setStyleSheet(QString::fromUtf8(""));
        label_146->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_146, 1, 0, 1, 1);

        LE_PLATFORM_OPERATING = new QLineEdit(layoutWidget_14);
        LE_PLATFORM_OPERATING->setObjectName(QString::fromUtf8("LE_PLATFORM_OPERATING"));
        LE_PLATFORM_OPERATING->setFont(font4);
        LE_PLATFORM_OPERATING->setAutoFillBackground(false);
        LE_PLATFORM_OPERATING->setReadOnly(true);

        gridLayout->addWidget(LE_PLATFORM_OPERATING, 1, 1, 1, 1);

        label_138 = new QLabel(layoutWidget_14);
        label_138->setObjectName(QString::fromUtf8("label_138"));
        label_138->setMinimumSize(QSize(100, 0));
        label_138->setFont(font3);
        label_138->setStyleSheet(QString::fromUtf8(""));
        label_138->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_138, 1, 2, 1, 1);

        LE_PLATFORM_CLOSED = new QLineEdit(layoutWidget_14);
        LE_PLATFORM_CLOSED->setObjectName(QString::fromUtf8("LE_PLATFORM_CLOSED"));
        LE_PLATFORM_CLOSED->setFont(font4);
        LE_PLATFORM_CLOSED->setAutoFillBackground(false);
        LE_PLATFORM_CLOSED->setReadOnly(true);

        gridLayout->addWidget(LE_PLATFORM_CLOSED, 1, 3, 1, 1);

        GB_OP_CONTROL = new QFrame(centralWidget);
        GB_OP_CONTROL->setObjectName(QString::fromUtf8("GB_OP_CONTROL"));
        GB_OP_CONTROL->setGeometry(QRect(500, 10, 941, 91));
        QFont font6;
        font6.setBold(true);
        font6.setItalic(false);
        font6.setWeight(75);
        GB_OP_CONTROL->setFont(font6);
        GB_OP_CONTROL->setStyleSheet(QString::fromUtf8(""));
        BTN_DO_OPERATING = new QPushButton(GB_OP_CONTROL);
        BTN_DO_OPERATING->setObjectName(QString::fromUtf8("BTN_DO_OPERATING"));
        BTN_DO_OPERATING->setGeometry(QRect(180, 10, 131, 71));
        QFont font7;
        font7.setFamily(QString::fromUtf8("\355\225\250\354\264\210\353\241\254\353\217\213\354\233\200"));
        font7.setPointSize(16);
        font7.setBold(false);
        font7.setWeight(50);
        BTN_DO_OPERATING->setFont(font7);
        BTN_DO_OPERATING->setAutoFillBackground(false);
        BTN_DO_OPERATING->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"background-color: rgb(255, 255, 255);\n"
"border:1px solid #595959;\n"
"border-radius: 10px;"));
        BTN_DO_OPERATING->setFlat(true);
        BTN_STOP_OPERATING = new QPushButton(GB_OP_CONTROL);
        BTN_STOP_OPERATING->setObjectName(QString::fromUtf8("BTN_STOP_OPERATING"));
        BTN_STOP_OPERATING->setGeometry(QRect(330, 10, 131, 71));
        BTN_STOP_OPERATING->setFont(font7);
        BTN_STOP_OPERATING->setAutoFillBackground(false);
        BTN_STOP_OPERATING->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"background-color: rgb(255, 255, 255);\n"
"border:1px solid #595959;\n"
"border-radius: 10px;"));
        BTN_STOP_OPERATING->setFlat(true);
        BTN_CANCEL_STOP = new QPushButton(GB_OP_CONTROL);
        BTN_CANCEL_STOP->setObjectName(QString::fromUtf8("BTN_CANCEL_STOP"));
        BTN_CANCEL_STOP->setGeometry(QRect(480, 10, 131, 71));
        BTN_CANCEL_STOP->setFont(font7);
        BTN_CANCEL_STOP->setAutoFillBackground(false);
        BTN_CANCEL_STOP->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"background-color: rgb(255, 255, 255);\n"
"border:1px solid #595959;\n"
"border-radius: 10px;"));
        BTN_CANCEL_STOP->setFlat(true);
        BTN_SUPER_STOP = new QPushButton(GB_OP_CONTROL);
        BTN_SUPER_STOP->setObjectName(QString::fromUtf8("BTN_SUPER_STOP"));
        BTN_SUPER_STOP->setEnabled(false);
        BTN_SUPER_STOP->setGeometry(QRect(770, 10, 141, 31));
        BTN_SUPER_STOP->setFont(font7);
        BTN_SUPER_STOP->setAutoFillBackground(false);
        BTN_SUPER_STOP->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"background-color: rgb(255, 255, 255);\n"
"border:1px solid #595959;\n"
"border-radius: 10px;"));
        BTN_SUPER_STOP->setFlat(false);
        BTN_FORCE_STOP = new QPushButton(GB_OP_CONTROL);
        BTN_FORCE_STOP->setObjectName(QString::fromUtf8("BTN_FORCE_STOP"));
        BTN_FORCE_STOP->setEnabled(false);
        BTN_FORCE_STOP->setGeometry(QRect(770, 50, 141, 31));
        BTN_FORCE_STOP->setFont(font7);
        BTN_FORCE_STOP->setAutoFillBackground(false);
        BTN_FORCE_STOP->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"background-color: rgb(255, 255, 255);\n"
"border:1px solid #595959;\n"
"border-radius: 10px;"));
        BTN_FORCE_STOP->setFlat(false);
        LE_PLATFORM_OPENED_WHEN_OPERATING = new QLineEdit(GB_OP_CONTROL);
        LE_PLATFORM_OPENED_WHEN_OPERATING->setObjectName(QString::fromUtf8("LE_PLATFORM_OPENED_WHEN_OPERATING"));
        LE_PLATFORM_OPENED_WHEN_OPERATING->setGeometry(QRect(640, 10, 121, 31));
        QFont font8;
        font8.setFamily(QString::fromUtf8("\355\225\250\354\264\210\353\241\254\353\217\213\354\233\200"));
        font8.setPointSize(12);
        LE_PLATFORM_OPENED_WHEN_OPERATING->setFont(font8);
        LE_PLATFORM_OPENED_WHEN_OPERATING->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"background-color: rgb(255, 255, 255);"));
        LE_PLATFORM_OPENED_WHEN_OPERATING->setAlignment(Qt::AlignCenter);
        LE_PLATFORM_OPENED_WHEN_OPERATING->setReadOnly(true);
        BTN_RESUME = new QPushButton(GB_OP_CONTROL);
        BTN_RESUME->setObjectName(QString::fromUtf8("BTN_RESUME"));
        BTN_RESUME->setGeometry(QRect(640, 50, 121, 31));
        BTN_RESUME->setFont(font7);
        BTN_RESUME->setAutoFillBackground(false);
        BTN_RESUME->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"background-color: rgb(255, 255, 255);\n"
"border:1px solid #595959;\n"
"border-radius: 10px;"));
        BTN_RESUME->setFlat(false);
        BTN_DO_INITIALIZING = new QPushButton(GB_OP_CONTROL);
        BTN_DO_INITIALIZING->setObjectName(QString::fromUtf8("BTN_DO_INITIALIZING"));
        BTN_DO_INITIALIZING->setGeometry(QRect(30, 10, 131, 71));
        QFont font9;
        font9.setFamily(QString::fromUtf8("\355\225\250\354\264\210\353\241\254\353\217\213\354\233\200"));
        font9.setPointSize(16);
        font9.setBold(false);
        font9.setWeight(50);
        font9.setKerning(true);
        BTN_DO_INITIALIZING->setFont(font9);
        BTN_DO_INITIALIZING->setAutoFillBackground(false);
        BTN_DO_INITIALIZING->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"background-color: rgb(255, 255, 255);\n"
"border:1px solid #595959;\n"
"border-radius: 10px;"));
        BTN_DO_INITIALIZING->setAutoDefault(false);
        BTN_DO_INITIALIZING->setFlat(false);
        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        BTN_DO_OPERATING->setDefault(false);
        BTN_DO_INITIALIZING->setDefault(false);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        BTN_EXIT->setText(QString());
        BTN_UI_LOCK->setText(QString());
        BTN_SETTING->setText(QString());
        BTN_DEV_INFO_COFFEE->setText(QCoreApplication::translate("MainWindow", "\354\273\244\355\224\274 (WMF)", nullptr));
        label_124->setText(QCoreApplication::translate("MainWindow", "\354\227\260\352\262\260\354\225\210\353\220\250", nullptr));
        label_125->setText(QCoreApplication::translate("MainWindow", "\354\244\200\353\271\204\354\244\221", nullptr));
        label_127->setText(QCoreApplication::translate("MainWindow", "\354\227\220\353\237\254\353\260\234\354\203\235", nullptr));
        label_126->setText(QCoreApplication::translate("MainWindow", "\354\244\200\353\271\204\354\231\204\353\243\214", nullptr));
        label_128->setText(QCoreApplication::translate("MainWindow", "\354\240\234\354\241\260\354\244\221", nullptr));
        label_111->setText(QCoreApplication::translate("MainWindow", "\354\213\234\354\212\244\355\205\234 \354\262\255\354\206\214", nullptr));
        label_114->setText(QCoreApplication::translate("MainWindow", "\354\213\234", nullptr));
        LE_SYS_CLEAN_TIME_MINUTE->setText(QString());
        label_115->setText(QCoreApplication::translate("MainWindow", "\353\266\204", nullptr));
        label_116->setText(QCoreApplication::translate("MainWindow", "\354\264\210", nullptr));
        label_112->setText(QCoreApplication::translate("MainWindow", "\354\232\260\354\234\240 \354\262\255\354\206\214", nullptr));
        label_118->setText(QCoreApplication::translate("MainWindow", "\354\213\234", nullptr));
        label_119->setText(QCoreApplication::translate("MainWindow", "\353\266\204", nullptr));
        label_117->setText(QCoreApplication::translate("MainWindow", "\354\264\210", nullptr));
        label_113->setText(QCoreApplication::translate("MainWindow", "\354\232\260\354\234\240 \352\264\200 \354\262\255\354\206\214", nullptr));
        label_121->setText(QCoreApplication::translate("MainWindow", "\354\213\234", nullptr));
        label_122->setText(QCoreApplication::translate("MainWindow", "\353\266\204", nullptr));
        label_120->setText(QCoreApplication::translate("MainWindow", "\354\264\210", nullptr));
        label_123->setText(QCoreApplication::translate("MainWindow", "\354\262\255\354\206\214\354\244\221", nullptr));
        BTN_DEV_INFO_ICE_1->setText(QCoreApplication::translate("MainWindow", "\354\226\274\354\235\214 \353\224\224\354\212\244\355\216\234\354\204\2341", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\353\247\214\353\271\231 : ", nullptr));
        LB_ICE_1_FULL->setText(QCoreApplication::translate("MainWindow", "\353\247\214\353\271\231\354\225\204\353\213\230", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "\354\227\220\353\237\254 : ", nullptr));
        LB_ICE_1_ERROR->setText(QCoreApplication::translate("MainWindow", "\354\227\220\353\237\254\354\227\206\354\235\214", nullptr));
        BTN_DEV_INFO_SODA->setText(QCoreApplication::translate("MainWindow", "\355\203\204\354\202\260\354\210\230", nullptr));
        label_16->setText(QCoreApplication::translate("MainWindow", "\353\241\234\353\223\234\354\205\200 :", nullptr));
        LB_SODA_LOADCELL->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        label_15->setText(QCoreApplication::translate("MainWindow", "\354\265\234\354\242\205 \354\227\220\353\237\254 :", nullptr));
        LB_SODA_LAST_ERROR->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        label_14->setText(QCoreApplication::translate("MainWindow", "\355\230\204\354\236\254 \353\217\231\354\236\221 :", nullptr));
        LB_SODA_OP_STATE->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        BTN_DEV_INFO_SYRUP->setText(QCoreApplication::translate("MainWindow", "\354\213\234\353\237\275 \353\224\224\354\212\244\355\216\234\354\204\234", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "\353\241\234\353\223\234\354\205\200 :", nullptr));
        LB_SYRUP_LOADCELL->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "\354\265\234\354\242\205 \354\227\220\353\237\254 :", nullptr));
        LB_SYRUP_LAST_ERROR->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "\355\230\204\354\236\254 \353\217\231\354\236\221 :", nullptr));
        LB_SYRUP_OP_STATE->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        BTN_DEV_INFO_OUTLET->setText(QCoreApplication::translate("MainWindow", "\353\260\260\354\266\234\352\265\254", nullptr));
        LE_OUTLET_M_1_DOOR_OPEN->setText(QCoreApplication::translate("MainWindow", "\354\227\264\353\246\274", nullptr));
        LE_OUTLET_M_1_DOOR_CLOSE->setText(QCoreApplication::translate("MainWindow", "\353\213\253\355\236\230", nullptr));
        LE_OUTLET_M_1_CUP_DETECT->setText(QCoreApplication::translate("MainWindow", "\354\273\265\352\260\220\354\247\200", nullptr));
        LE_OUTLET_M_2_DOOR_OPEN->setText(QCoreApplication::translate("MainWindow", "\354\227\264\353\246\274", nullptr));
        LE_OUTLET_M_2_DOOR_CLOSE->setText(QCoreApplication::translate("MainWindow", "\353\213\253\355\236\230", nullptr));
        LE_OUTLET_M_2_CUP_DETECT->setText(QCoreApplication::translate("MainWindow", "\354\273\265\352\260\220\354\247\200", nullptr));
        LB_OUTLET_M_1_CELL_3->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        label_22->setText(QCoreApplication::translate("MainWindow", "Cell 2:", nullptr));
        label_26->setText(QCoreApplication::translate("MainWindow", "Cell 3:", nullptr));
        LB_OUTLET_M_1_CELL_1->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        label_21->setText(QCoreApplication::translate("MainWindow", "Cell 1:", nullptr));
        LB_OUTLET_M_2_CELL_1->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        LB_OUTLET_M_2_CELL_2->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        LB_OUTLET_M_2_CELL_3->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        label_24->setText(QCoreApplication::translate("MainWindow", "Cell 1:", nullptr));
        LB_OUTLET_M_1_CELL_2->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        label_25->setText(QCoreApplication::translate("MainWindow", "Cell 2:", nullptr));
        label_23->setText(QCoreApplication::translate("MainWindow", "Cell 3:", nullptr));
        BTN_DEV_INFO_MONITOR->setText(QCoreApplication::translate("MainWindow", "\355\230\204\355\231\251\355\214\220", nullptr));
        label_18->setText(QCoreApplication::translate("MainWindow", "\354\240\234\354\241\260\354\244\221 \354\235\214\353\243\214 :", nullptr));
        LB_MONITOR_INPROGRESS->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        label_19->setText(QCoreApplication::translate("MainWindow", "\353\214\200\352\270\260\354\244\221 \354\235\214\353\243\214 :", nullptr));
        LB_MONITOR_WAITING->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        label_20->setText(QCoreApplication::translate("MainWindow", "\354\231\204\353\243\214\353\220\234 \354\235\214\353\243\214 :", nullptr));
        LB_MONITOR_COMPLETED->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        BTN_DEV_INFO_CUP->setText(QCoreApplication::translate("MainWindow", "\354\273\265 \353\224\224\354\212\244\355\216\234\354\204\234", nullptr));
        BTN_CUP_ADD_DONE->setText(QCoreApplication::translate("MainWindow", "\354\273\265\n"
"\354\266\224\352\260\200 \354\231\204\353\243\214", nullptr));
        label_27->setText(QCoreApplication::translate("MainWindow", "\354\242\205\354\235\264\354\273\2651", nullptr));
        label_33->setText(QCoreApplication::translate("MainWindow", "\354\242\205\354\235\264\354\273\2652", nullptr));
        label_30->setText(QCoreApplication::translate("MainWindow", "\354\265\234\354\242\205 \354\227\220\353\237\254 :", nullptr));
        LB_CUP_1_LAST_ERROR->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        LB_CUP_2_LAST_ERROR->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        label_29->setText(QCoreApplication::translate("MainWindow", "\355\230\204\354\236\254 \353\217\231\354\236\221 :", nullptr));
        LB_CUP_1_OP_STATE->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        LB_CUP_2_OP_STATE->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        label_28->setText(QCoreApplication::translate("MainWindow", "PET\354\273\2651", nullptr));
        label_34->setText(QCoreApplication::translate("MainWindow", "PET\354\273\2652", nullptr));
        label_31->setText(QCoreApplication::translate("MainWindow", "\354\265\234\354\242\205 \354\227\220\353\237\254 :", nullptr));
        LB_CUP_3_LAST_ERROR->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        LB_CUP_4_LAST_ERROR->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        label_32->setText(QCoreApplication::translate("MainWindow", "\355\230\204\354\236\254 \353\217\231\354\236\221 :", nullptr));
        LB_CUP_3_OP_STATE->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        LB_CUP_4_OP_STATE->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        BTN_DEV_INFO_ROBOT->setText(QCoreApplication::translate("MainWindow", "\353\241\234\353\264\207", nullptr));
        label_91->setText(QCoreApplication::translate("MainWindow", "\353\217\231\354\236\221 \355\224\204\353\241\234\352\267\270\353\236\250", nullptr));
        LE_ROBOT_PRG_CONNECT->setText(QCoreApplication::translate("MainWindow", "\355\206\265\354\213\240", nullptr));
        LE_ROBOT_PRG_WORKING_STATUS->setText(QCoreApplication::translate("MainWindow", "\354\213\244\355\226\211", nullptr));
        LE_ROBOT_INIT_BASE_ANGLE->setText(QCoreApplication::translate("MainWindow", "\353\262\240\354\235\264\354\212\244", nullptr));
        LE_ROBOT_INIT_POSITION->setText(QCoreApplication::translate("MainWindow", "\354\236\220\354\204\270", nullptr));
        label_92->setText(QCoreApplication::translate("MainWindow", "\354\264\210\352\270\260\355\231\224", nullptr));
        LE_ROBOT_STATE_MOVING->setText(QCoreApplication::translate("MainWindow", "\353\217\231\354\236\221\354\244\221", nullptr));
        LE_ROBOT_STATUS_TEACHING->setText(QCoreApplication::translate("MainWindow", "\355\213\260\354\271\255\354\244\221", nullptr));
        LE_ROBOT_STATE_IDLE->setText(QCoreApplication::translate("MainWindow", "\353\214\200\352\270\260\354\244\221", nullptr));
        LE_PG_MODE_REAL->setText(QCoreApplication::translate("MainWindow", "\353\246\254\354\226\274", nullptr));
        LE_PG_MODE_SIMULATION->setText(QCoreApplication::translate("MainWindow", "\354\213\234\353\256\254", nullptr));
        LE_ROBOT_STATUS_SELF_COLLISION->setText(QCoreApplication::translate("MainWindow", "\354\236\220\352\260\200\354\266\251\353\217\214", nullptr));
        LE_ROBOT_STATUS_EXT_COLLISION->setText(QCoreApplication::translate("MainWindow", "\354\231\270\353\266\200\354\266\251\353\217\214", nullptr));
        LE_ROBOT_STATUS_PAUSED->setText(QCoreApplication::translate("MainWindow", "\354\235\274\354\213\234\354\240\225\354\247\200", nullptr));
        LE_ROBOT_STATUS_EMS->setText(QCoreApplication::translate("MainWindow", "EMS", nullptr));
        LE_ROBOT_STATUS_SOS->setText(QCoreApplication::translate("MainWindow", "SOS", nullptr));
        BTN_DEV_INFO_HOT->setText(QCoreApplication::translate("MainWindow", "\354\230\250\354\210\230 \353\224\224\354\212\244\355\216\234\354\204\234", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "\353\241\234\353\223\234\354\205\200 :", nullptr));
        LB_HOT_LOADCELL->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "\354\265\234\354\242\205 \354\227\220\353\237\254 :", nullptr));
        LB_HOT_LAST_ERROR->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "\355\230\204\354\236\254 \353\217\231\354\236\221 :", nullptr));
        LB_HOT_OP_STATE->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        BTN_DEV_INFO_ICECREAM->setText(QCoreApplication::translate("MainWindow", "\354\225\204\354\235\264\354\212\244\355\201\254\353\246\274", nullptr));
        label_13->setText(QCoreApplication::translate("MainWindow", "\353\241\234\353\223\234\354\205\200 :", nullptr));
        LB_ICECREAM_LOADCELL->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        label_12->setText(QCoreApplication::translate("MainWindow", "\354\265\234\354\242\205 \354\227\220\353\237\254 :", nullptr));
        LB_ICECREAM_LAST_ERROR->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "\355\230\204\354\236\254 \353\217\231\354\236\221 :", nullptr));
        LB_ICECREAM_OP_STATE->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        BTN_DEV_INFO_BARCODE->setText(QCoreApplication::translate("MainWindow", "\353\260\224\354\275\224\353\223\234", nullptr));
        label_17->setText(QCoreApplication::translate("MainWindow", "\353\247\210\354\247\200\353\247\211 \353\260\224\354\275\224\353\223\234 :", nullptr));
        LB_BARCODE_LAST_DATA->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        BTN_DEV_INFO_DOOR->setText(QCoreApplication::translate("MainWindow", "\354\266\234\354\236\205\352\265\254", nullptr));
        label_129->setText(QCoreApplication::translate("MainWindow", "\353\254\270\353\213\253\355\236\230", nullptr));
        label_130->setText(QCoreApplication::translate("MainWindow", "\353\254\270\354\227\264\353\246\274", nullptr));
        BTN_DEV_INFO_KIOSK->setText(QCoreApplication::translate("MainWindow", "\355\202\244\354\230\244\354\212\244\355\201\254", nullptr));
        LB_KIOSK_BLOCK_ORDER->setText(QCoreApplication::translate("MainWindow", "\354\243\274\353\254\270\354\260\250\353\213\250", nullptr));
        BTN_DEV_INFO_STOCK->setText(QCoreApplication::translate("MainWindow", "\354\236\254\352\263\240", nullptr));
        label_35->setText(QString());
        BTN_DEV_INFO_ICE_2->setText(QCoreApplication::translate("MainWindow", "\354\226\274\354\235\214 \353\224\224\354\212\244\355\216\234\354\204\2342", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "\353\247\214\353\271\231 : ", nullptr));
        LB_ICE_2_FULL->setText(QCoreApplication::translate("MainWindow", "\353\247\214\353\271\231\354\225\204\353\213\230", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "\354\227\220\353\237\254 : ", nullptr));
        LB_ICE_2_ERROR->setText(QCoreApplication::translate("MainWindow", "\354\227\220\353\237\254\354\227\206\354\235\214", nullptr));
        label_135->setText(QCoreApplication::translate("MainWindow", "\354\264\210\352\270\260\355\231\224", nullptr));
        label_147->setText(QCoreApplication::translate("MainWindow", "\354\242\205\353\243\214 \354\213\240\355\230\270", nullptr));
        label_146->setText(QCoreApplication::translate("MainWindow", "\354\230\201\354\227\205\354\244\221", nullptr));
        label_138->setText(QCoreApplication::translate("MainWindow", "\353\254\270\353\213\253\355\236\230", nullptr));
        BTN_DO_OPERATING->setText(QCoreApplication::translate("MainWindow", "\354\230\201\354\227\205 \354\213\234\354\236\221", nullptr));
        BTN_STOP_OPERATING->setText(QCoreApplication::translate("MainWindow", "\354\230\201\354\227\205 \354\240\225\354\247\200", nullptr));
        BTN_CANCEL_STOP->setText(QCoreApplication::translate("MainWindow", "\354\240\225\354\247\200 \354\267\250\354\206\214", nullptr));
        BTN_SUPER_STOP->setText(QCoreApplication::translate("MainWindow", "Super Stop", nullptr));
        BTN_FORCE_STOP->setText(QCoreApplication::translate("MainWindow", "Force Stop", nullptr));
        LE_PLATFORM_OPENED_WHEN_OPERATING->setText(QCoreApplication::translate("MainWindow", "\353\217\231\354\236\221\354\244\221 \353\254\270\354\227\264\353\246\274", nullptr));
        BTN_RESUME->setText(QCoreApplication::translate("MainWindow", "\353\217\231\354\236\221 \354\236\254\352\260\234", nullptr));
        BTN_DO_INITIALIZING->setText(QCoreApplication::translate("MainWindow", "\354\264\210\352\270\260\355\231\224 \354\213\234\354\236\221", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
