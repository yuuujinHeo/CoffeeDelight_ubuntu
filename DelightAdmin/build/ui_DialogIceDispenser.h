/********************************************************************************
** Form generated from reading UI file 'DialogIceDispenser.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGICEDISPENSER_H
#define UI_DIALOGICEDISPENSER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DialogIceDispenser
{
public:
    QGroupBox *GB_ICE;
    QFrame *line_2;
    QPushButton *BTN_ICE_TEST_ICE_OUT;
    QFrame *line_3;
    QComboBox *CB_ICE_CUP_IGNORE;
    QLabel *label_9;
    QPushButton *BTN_ICE_TEST_REBOOT;
    QComboBox *CB_ICE_COMM_MODE;
    QPushButton *BTN_ICE_TEST_STATUS_CLEAR;
    QPushButton *BTN_ICE_CHANGE_COMM_MODE;
    QFrame *line_5;
    QComboBox *CB_ICE_COMM_MODE_2;
    QComboBox *CB_ICE_CUP_IGNORE_2;
    QFrame *line_4;
    QPushButton *BTN_ICE_TEST_STATUS_CLEAR_2;
    QPushButton *BTN_ICE_CHANGE_COMM_MODE_2;
    QLabel *label_61;
    QPushButton *BTN_ICE_TEST_REBOOT_2;
    QFrame *line_6;
    QPushButton *BTN_ICE_TEST_ICE_OUT_2;
    QFrame *line_7;
    QFrame *line_8;
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QLabel *label_28;
    QLabel *LB_STATUS_GEAR_WORKING;
    QLabel *LB_STATUS_CUP_LEVER_DETECT;
    QLineEdit *LE_ICE_DATA_CONNECTION;
    QLabel *LB_STATUS_OUT_SOL_DETECT;
    QLabel *label_26;
    QLabel *label_111;
    QLabel *label_110;
    QLineEdit *LE_ICE_CONNECTION;
    QLabel *LB_STATUS_COMM_MODE;
    QLabel *LB_STATUS_COMP_WORKING;
    QLabel *label_41;
    QLabel *label_27;
    QLabel *label_30;
    QLineEdit *LE_ICE_ERROR;
    QLabel *LB_STATUS_FULL_ICE;
    QLabel *label_25;
    QLabel *label_29;
    QLabel *LB_ERROR_TYPE;
    QWidget *layoutWidget1;
    QGridLayout *gridLayout_2;
    QLabel *label_31;
    QLabel *LB_STATUS_LAST_ICE_TIME;
    QLabel *label_32;
    QLabel *label_43;
    QLabel *LB_STATUS_LAST_WATER_TIME;
    QLabel *label_33;
    QLabel *label_34;
    QLabel *LB_STATUS_AMBIENT_TEMP_LOW;
    QLabel *label_36;
    QLabel *LB_STATUS_AMBIENT_TEMP_HIGH;
    QLabel *label_44;
    QLabel *LB_STATUS_AMBIENT_TEMP_NOW;
    QLabel *label_45;
    QLabel *LB_STATUS_EVAPORATOR_TEMP;
    QLabel *label_46;
    QLabel *LB_STATUS_CONDENSOR_TEMP;
    QLabel *label_47;
    QLineEdit *LE_ICE_CHECK_COUNT;
    QWidget *layoutWidget2;
    QGridLayout *gridLayout_3;
    QLabel *LB_STATUS_COMP_WORKING_2;
    QLabel *LB_STATUS_FULL_ICE_2;
    QLabel *LB_STATUS_GEAR_WORKING_2;
    QLabel *label_38;
    QLabel *LB_STATUS_COMM_MODE_2;
    QLabel *label_56;
    QLabel *label_37;
    QLineEdit *LE_ICE_ERROR_2;
    QLabel *label_54;
    QLabel *label_112;
    QLabel *label_113;
    QLineEdit *LE_ICE_DATA_CONNECTION_2;
    QLineEdit *LE_ICE_CONNECTION_2;
    QLabel *label_55;
    QLabel *label_39;
    QLabel *label_35;
    QLabel *LB_STATUS_CUP_LEVER_DETECT_2;
    QLabel *LB_STATUS_OUT_SOL_DETECT_2;
    QLabel *LB_ERROR_TYPE_2;
    QWidget *layoutWidget3;
    QGridLayout *gridLayout_4;
    QLabel *label_67;
    QLabel *LB_STATUS_LAST_ICE_TIME_2;
    QLabel *label_40;
    QLabel *label_49;
    QLabel *LB_STATUS_LAST_WATER_TIME_2;
    QLabel *label_68;
    QLabel *label_51;
    QLabel *LB_STATUS_AMBIENT_TEMP_LOW_2;
    QLabel *label_42;
    QLabel *LB_STATUS_AMBIENT_TEMP_HIGH_2;
    QLabel *label_66;
    QLabel *LB_STATUS_AMBIENT_TEMP_NOW_2;
    QLabel *label_64;
    QLabel *LB_STATUS_EVAPORATOR_TEMP_2;
    QLabel *label_59;
    QLabel *LB_STATUS_CONDENSOR_TEMP_2;
    QLabel *label_48;
    QLineEdit *LE_ICE_CHECK_COUNT_2;
    QWidget *layoutWidget4;
    QGridLayout *gridLayout_5;
    QLineEdit *LE_ICE_TEST_ICE_OUT_TIME;
    QLabel *label_22;
    QLineEdit *LE_ICE_TEST_WATER_OUT_TIME;
    QLabel *label_21;
    QWidget *layoutWidget5;
    QGridLayout *gridLayout_6;
    QLineEdit *LE_ICE_TEST_ICE_OUT_TIME_2;
    QLabel *label_62;
    QLineEdit *LE_ICE_TEST_WATER_OUT_TIME_2;
    QLabel *label_63;

    void setupUi(QDialog *DialogIceDispenser)
    {
        if (DialogIceDispenser->objectName().isEmpty())
            DialogIceDispenser->setObjectName(QString::fromUtf8("DialogIceDispenser"));
        DialogIceDispenser->resize(402, 931);
        GB_ICE = new QGroupBox(DialogIceDispenser);
        GB_ICE->setObjectName(QString::fromUtf8("GB_ICE"));
        GB_ICE->setGeometry(QRect(0, 0, 401, 971));
        QFont font;
        font.setFamily(QString::fromUtf8("\355\225\250\354\264\210\353\241\254\353\217\213\354\233\200"));
        font.setPointSize(20);
        font.setBold(false);
        font.setItalic(false);
        font.setWeight(50);
        GB_ICE->setFont(font);
        GB_ICE->setStyleSheet(QString::fromUtf8("QGroupBox  {\n"
"    margin-top: 10px;\n"
"	font: 20pt \"\355\225\250\354\264\210\353\241\254\353\217\213\354\233\200\";\n"
"}\n"
"\n"
"QGroupBox::title  {\n"
"    subcontrol-origin: margin;\n"
"    subcontrol-position: top center;\n"
"    padding: 10px 8000px 10px 8000px;\n"
"    background-color: #595959;\n"
"    color: rgb(255, 255, 255);\n"
"}\n"
"QLabel {\n"
"	font: 10pt \"\355\225\250\354\264\210\353\241\254\353\217\213\354\233\200\";\n"
"}\n"
"QComboBox{\n"
"	font: 10pt \"\355\225\250\354\264\210\353\241\254\353\217\213\354\233\200\";\n"
"	background-color: #ffffff\n"
"}\n"
"QPushButton{\n"
"	font: 10pt \"\355\225\250\354\264\210\353\241\254\353\217\213\354\233\200\";\n"
"	background-color: #ffffff\n"
"}\n"
"QLineEdit{\n"
"	font: 10pt \"\355\225\250\354\264\210\353\241\254\353\217\213\354\233\200\";\n"
"	background-color: #ffffff\n"
"}\n"
"\n"
"\n"
"\n"
""));
        line_2 = new QFrame(GB_ICE);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setGeometry(QRect(20, 480, 161, 20));
        QFont font1;
        font1.setPointSize(9);
        line_2->setFont(font1);
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);
        BTN_ICE_TEST_ICE_OUT = new QPushButton(GB_ICE);
        BTN_ICE_TEST_ICE_OUT->setObjectName(QString::fromUtf8("BTN_ICE_TEST_ICE_OUT"));
        BTN_ICE_TEST_ICE_OUT->setGeometry(QRect(40, 420, 121, 51));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\355\225\250\354\264\210\353\241\254\353\217\213\354\233\200"));
        font2.setPointSize(10);
        font2.setBold(false);
        font2.setItalic(false);
        font2.setWeight(50);
        BTN_ICE_TEST_ICE_OUT->setFont(font2);
        line_3 = new QFrame(GB_ICE);
        line_3->setObjectName(QString::fromUtf8("line_3"));
        line_3->setGeometry(QRect(190, 60, 20, 851));
        line_3->setFrameShape(QFrame::VLine);
        line_3->setFrameShadow(QFrame::Sunken);
        CB_ICE_CUP_IGNORE = new QComboBox(GB_ICE);
        CB_ICE_CUP_IGNORE->addItem(QString());
        CB_ICE_CUP_IGNORE->addItem(QString());
        CB_ICE_CUP_IGNORE->setObjectName(QString::fromUtf8("CB_ICE_CUP_IGNORE"));
        CB_ICE_CUP_IGNORE->setGeometry(QRect(20, 800, 121, 22));
        CB_ICE_CUP_IGNORE->setFont(font2);
        label_9 = new QLabel(GB_ICE);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(20, 757, 91, 16));
        label_9->setFont(font2);
        BTN_ICE_TEST_REBOOT = new QPushButton(GB_ICE);
        BTN_ICE_TEST_REBOOT->setObjectName(QString::fromUtf8("BTN_ICE_TEST_REBOOT"));
        BTN_ICE_TEST_REBOOT->setGeometry(QRect(20, 840, 71, 61));
        BTN_ICE_TEST_REBOOT->setFont(font2);
        CB_ICE_COMM_MODE = new QComboBox(GB_ICE);
        CB_ICE_COMM_MODE->addItem(QString());
        CB_ICE_COMM_MODE->addItem(QString());
        CB_ICE_COMM_MODE->setObjectName(QString::fromUtf8("CB_ICE_COMM_MODE"));
        CB_ICE_COMM_MODE->setGeometry(QRect(20, 780, 81, 22));
        CB_ICE_COMM_MODE->setFont(font2);
        BTN_ICE_TEST_STATUS_CLEAR = new QPushButton(GB_ICE);
        BTN_ICE_TEST_STATUS_CLEAR->setObjectName(QString::fromUtf8("BTN_ICE_TEST_STATUS_CLEAR"));
        BTN_ICE_TEST_STATUS_CLEAR->setGeometry(QRect(110, 840, 71, 61));
        BTN_ICE_TEST_STATUS_CLEAR->setFont(font2);
        BTN_ICE_CHANGE_COMM_MODE = new QPushButton(GB_ICE);
        BTN_ICE_CHANGE_COMM_MODE->setObjectName(QString::fromUtf8("BTN_ICE_CHANGE_COMM_MODE"));
        BTN_ICE_CHANGE_COMM_MODE->setGeometry(QRect(130, 760, 51, 31));
        BTN_ICE_CHANGE_COMM_MODE->setFont(font2);
        line_5 = new QFrame(GB_ICE);
        line_5->setObjectName(QString::fromUtf8("line_5"));
        line_5->setGeometry(QRect(20, 720, 161, 20));
        line_5->setFont(font1);
        line_5->setFrameShape(QFrame::HLine);
        line_5->setFrameShadow(QFrame::Sunken);
        CB_ICE_COMM_MODE_2 = new QComboBox(GB_ICE);
        CB_ICE_COMM_MODE_2->addItem(QString());
        CB_ICE_COMM_MODE_2->addItem(QString());
        CB_ICE_COMM_MODE_2->setObjectName(QString::fromUtf8("CB_ICE_COMM_MODE_2"));
        CB_ICE_COMM_MODE_2->setGeometry(QRect(220, 780, 81, 22));
        CB_ICE_COMM_MODE_2->setFont(font2);
        CB_ICE_CUP_IGNORE_2 = new QComboBox(GB_ICE);
        CB_ICE_CUP_IGNORE_2->addItem(QString());
        CB_ICE_CUP_IGNORE_2->addItem(QString());
        CB_ICE_CUP_IGNORE_2->setObjectName(QString::fromUtf8("CB_ICE_CUP_IGNORE_2"));
        CB_ICE_CUP_IGNORE_2->setGeometry(QRect(220, 800, 121, 22));
        CB_ICE_CUP_IGNORE_2->setFont(font2);
        line_4 = new QFrame(GB_ICE);
        line_4->setObjectName(QString::fromUtf8("line_4"));
        line_4->setGeometry(QRect(220, 480, 161, 20));
        line_4->setFont(font1);
        line_4->setFrameShape(QFrame::HLine);
        line_4->setFrameShadow(QFrame::Sunken);
        BTN_ICE_TEST_STATUS_CLEAR_2 = new QPushButton(GB_ICE);
        BTN_ICE_TEST_STATUS_CLEAR_2->setObjectName(QString::fromUtf8("BTN_ICE_TEST_STATUS_CLEAR_2"));
        BTN_ICE_TEST_STATUS_CLEAR_2->setGeometry(QRect(310, 840, 71, 61));
        BTN_ICE_TEST_STATUS_CLEAR_2->setFont(font2);
        BTN_ICE_CHANGE_COMM_MODE_2 = new QPushButton(GB_ICE);
        BTN_ICE_CHANGE_COMM_MODE_2->setObjectName(QString::fromUtf8("BTN_ICE_CHANGE_COMM_MODE_2"));
        BTN_ICE_CHANGE_COMM_MODE_2->setGeometry(QRect(330, 760, 51, 31));
        BTN_ICE_CHANGE_COMM_MODE_2->setFont(font2);
        label_61 = new QLabel(GB_ICE);
        label_61->setObjectName(QString::fromUtf8("label_61"));
        label_61->setGeometry(QRect(220, 757, 91, 16));
        label_61->setFont(font2);
        BTN_ICE_TEST_REBOOT_2 = new QPushButton(GB_ICE);
        BTN_ICE_TEST_REBOOT_2->setObjectName(QString::fromUtf8("BTN_ICE_TEST_REBOOT_2"));
        BTN_ICE_TEST_REBOOT_2->setGeometry(QRect(220, 840, 71, 61));
        BTN_ICE_TEST_REBOOT_2->setFont(font2);
        line_6 = new QFrame(GB_ICE);
        line_6->setObjectName(QString::fromUtf8("line_6"));
        line_6->setGeometry(QRect(220, 720, 161, 20));
        line_6->setFont(font1);
        line_6->setFrameShape(QFrame::HLine);
        line_6->setFrameShadow(QFrame::Sunken);
        BTN_ICE_TEST_ICE_OUT_2 = new QPushButton(GB_ICE);
        BTN_ICE_TEST_ICE_OUT_2->setObjectName(QString::fromUtf8("BTN_ICE_TEST_ICE_OUT_2"));
        BTN_ICE_TEST_ICE_OUT_2->setGeometry(QRect(240, 420, 121, 51));
        BTN_ICE_TEST_ICE_OUT_2->setFont(font2);
        line_7 = new QFrame(GB_ICE);
        line_7->setObjectName(QString::fromUtf8("line_7"));
        line_7->setGeometry(QRect(20, 330, 161, 20));
        line_7->setFont(font1);
        line_7->setFrameShape(QFrame::HLine);
        line_7->setFrameShadow(QFrame::Sunken);
        line_8 = new QFrame(GB_ICE);
        line_8->setObjectName(QString::fromUtf8("line_8"));
        line_8->setGeometry(QRect(220, 330, 161, 20));
        line_8->setFont(font1);
        line_8->setFrameShape(QFrame::HLine);
        line_8->setFrameShadow(QFrame::Sunken);
        layoutWidget = new QWidget(GB_ICE);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 60, 181, 266));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label_28 = new QLabel(layoutWidget);
        label_28->setObjectName(QString::fromUtf8("label_28"));
        label_28->setFont(font2);
        label_28->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_28, 5, 0, 1, 1);

        LB_STATUS_GEAR_WORKING = new QLabel(layoutWidget);
        LB_STATUS_GEAR_WORKING->setObjectName(QString::fromUtf8("LB_STATUS_GEAR_WORKING"));
        LB_STATUS_GEAR_WORKING->setFont(font2);

        gridLayout->addWidget(LB_STATUS_GEAR_WORKING, 4, 1, 1, 1);

        LB_STATUS_CUP_LEVER_DETECT = new QLabel(layoutWidget);
        LB_STATUS_CUP_LEVER_DETECT->setObjectName(QString::fromUtf8("LB_STATUS_CUP_LEVER_DETECT"));
        LB_STATUS_CUP_LEVER_DETECT->setFont(font2);

        gridLayout->addWidget(LB_STATUS_CUP_LEVER_DETECT, 6, 1, 1, 1);

        LE_ICE_DATA_CONNECTION = new QLineEdit(layoutWidget);
        LE_ICE_DATA_CONNECTION->setObjectName(QString::fromUtf8("LE_ICE_DATA_CONNECTION"));
        LE_ICE_DATA_CONNECTION->setFont(font2);
        LE_ICE_DATA_CONNECTION->setReadOnly(true);

        gridLayout->addWidget(LE_ICE_DATA_CONNECTION, 1, 1, 1, 1);

        LB_STATUS_OUT_SOL_DETECT = new QLabel(layoutWidget);
        LB_STATUS_OUT_SOL_DETECT->setObjectName(QString::fromUtf8("LB_STATUS_OUT_SOL_DETECT"));
        LB_STATUS_OUT_SOL_DETECT->setFont(font2);

        gridLayout->addWidget(LB_STATUS_OUT_SOL_DETECT, 5, 1, 1, 1);

        label_26 = new QLabel(layoutWidget);
        label_26->setObjectName(QString::fromUtf8("label_26"));
        label_26->setFont(font2);
        label_26->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_26, 7, 0, 1, 1);

        label_111 = new QLabel(layoutWidget);
        label_111->setObjectName(QString::fromUtf8("label_111"));
        label_111->setFont(font2);
        label_111->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_111, 1, 0, 1, 1);

        label_110 = new QLabel(layoutWidget);
        label_110->setObjectName(QString::fromUtf8("label_110"));
        label_110->setFont(font2);
        label_110->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_110, 0, 0, 1, 1);

        LE_ICE_CONNECTION = new QLineEdit(layoutWidget);
        LE_ICE_CONNECTION->setObjectName(QString::fromUtf8("LE_ICE_CONNECTION"));
        LE_ICE_CONNECTION->setFont(font2);
        LE_ICE_CONNECTION->setReadOnly(true);

        gridLayout->addWidget(LE_ICE_CONNECTION, 0, 1, 1, 1);

        LB_STATUS_COMM_MODE = new QLabel(layoutWidget);
        LB_STATUS_COMM_MODE->setObjectName(QString::fromUtf8("LB_STATUS_COMM_MODE"));
        LB_STATUS_COMM_MODE->setFont(font2);

        gridLayout->addWidget(LB_STATUS_COMM_MODE, 2, 1, 1, 1);

        LB_STATUS_COMP_WORKING = new QLabel(layoutWidget);
        LB_STATUS_COMP_WORKING->setObjectName(QString::fromUtf8("LB_STATUS_COMP_WORKING"));
        LB_STATUS_COMP_WORKING->setFont(font2);

        gridLayout->addWidget(LB_STATUS_COMP_WORKING, 3, 1, 1, 1);

        label_41 = new QLabel(layoutWidget);
        label_41->setObjectName(QString::fromUtf8("label_41"));
        label_41->setFont(font2);
        label_41->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_41, 8, 0, 1, 1);

        label_27 = new QLabel(layoutWidget);
        label_27->setObjectName(QString::fromUtf8("label_27"));
        label_27->setFont(font2);
        label_27->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_27, 2, 0, 1, 1);

        label_30 = new QLabel(layoutWidget);
        label_30->setObjectName(QString::fromUtf8("label_30"));
        label_30->setFont(font2);
        label_30->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_30, 4, 0, 1, 1);

        LE_ICE_ERROR = new QLineEdit(layoutWidget);
        LE_ICE_ERROR->setObjectName(QString::fromUtf8("LE_ICE_ERROR"));
        LE_ICE_ERROR->setFont(font2);
        LE_ICE_ERROR->setAlignment(Qt::AlignCenter);
        LE_ICE_ERROR->setReadOnly(true);

        gridLayout->addWidget(LE_ICE_ERROR, 8, 1, 1, 1);

        LB_STATUS_FULL_ICE = new QLabel(layoutWidget);
        LB_STATUS_FULL_ICE->setObjectName(QString::fromUtf8("LB_STATUS_FULL_ICE"));
        LB_STATUS_FULL_ICE->setFont(font2);

        gridLayout->addWidget(LB_STATUS_FULL_ICE, 7, 1, 1, 1);

        label_25 = new QLabel(layoutWidget);
        label_25->setObjectName(QString::fromUtf8("label_25"));
        label_25->setFont(font2);
        label_25->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_25, 6, 0, 1, 1);

        label_29 = new QLabel(layoutWidget);
        label_29->setObjectName(QString::fromUtf8("label_29"));
        label_29->setFont(font2);
        label_29->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_29, 3, 0, 1, 1);

        LB_ERROR_TYPE = new QLabel(layoutWidget);
        LB_ERROR_TYPE->setObjectName(QString::fromUtf8("LB_ERROR_TYPE"));
        LB_ERROR_TYPE->setFont(font2);

        gridLayout->addWidget(LB_ERROR_TYPE, 9, 0, 1, 2);

        layoutWidget1 = new QWidget(GB_ICE);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(10, 500, 181, 209));
        gridLayout_2 = new QGridLayout(layoutWidget1);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        label_31 = new QLabel(layoutWidget1);
        label_31->setObjectName(QString::fromUtf8("label_31"));
        label_31->setFont(font2);
        label_31->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_31, 0, 0, 1, 1);

        LB_STATUS_LAST_ICE_TIME = new QLabel(layoutWidget1);
        LB_STATUS_LAST_ICE_TIME->setObjectName(QString::fromUtf8("LB_STATUS_LAST_ICE_TIME"));
        LB_STATUS_LAST_ICE_TIME->setFont(font2);

        gridLayout_2->addWidget(LB_STATUS_LAST_ICE_TIME, 0, 1, 1, 1);

        label_32 = new QLabel(layoutWidget1);
        label_32->setObjectName(QString::fromUtf8("label_32"));
        label_32->setFont(font2);

        gridLayout_2->addWidget(label_32, 0, 2, 1, 1);

        label_43 = new QLabel(layoutWidget1);
        label_43->setObjectName(QString::fromUtf8("label_43"));
        label_43->setFont(font2);
        label_43->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_43, 1, 0, 1, 1);

        LB_STATUS_LAST_WATER_TIME = new QLabel(layoutWidget1);
        LB_STATUS_LAST_WATER_TIME->setObjectName(QString::fromUtf8("LB_STATUS_LAST_WATER_TIME"));
        LB_STATUS_LAST_WATER_TIME->setFont(font2);

        gridLayout_2->addWidget(LB_STATUS_LAST_WATER_TIME, 1, 1, 1, 1);

        label_33 = new QLabel(layoutWidget1);
        label_33->setObjectName(QString::fromUtf8("label_33"));
        label_33->setFont(font2);

        gridLayout_2->addWidget(label_33, 1, 2, 1, 1);

        label_34 = new QLabel(layoutWidget1);
        label_34->setObjectName(QString::fromUtf8("label_34"));
        label_34->setFont(font2);
        label_34->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_34, 2, 0, 1, 1);

        LB_STATUS_AMBIENT_TEMP_LOW = new QLabel(layoutWidget1);
        LB_STATUS_AMBIENT_TEMP_LOW->setObjectName(QString::fromUtf8("LB_STATUS_AMBIENT_TEMP_LOW"));
        LB_STATUS_AMBIENT_TEMP_LOW->setFont(font2);

        gridLayout_2->addWidget(LB_STATUS_AMBIENT_TEMP_LOW, 2, 1, 1, 1);

        label_36 = new QLabel(layoutWidget1);
        label_36->setObjectName(QString::fromUtf8("label_36"));
        label_36->setFont(font2);
        label_36->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_36, 3, 0, 1, 1);

        LB_STATUS_AMBIENT_TEMP_HIGH = new QLabel(layoutWidget1);
        LB_STATUS_AMBIENT_TEMP_HIGH->setObjectName(QString::fromUtf8("LB_STATUS_AMBIENT_TEMP_HIGH"));
        LB_STATUS_AMBIENT_TEMP_HIGH->setFont(font2);

        gridLayout_2->addWidget(LB_STATUS_AMBIENT_TEMP_HIGH, 3, 1, 1, 1);

        label_44 = new QLabel(layoutWidget1);
        label_44->setObjectName(QString::fromUtf8("label_44"));
        label_44->setFont(font2);
        label_44->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_44, 4, 0, 1, 1);

        LB_STATUS_AMBIENT_TEMP_NOW = new QLabel(layoutWidget1);
        LB_STATUS_AMBIENT_TEMP_NOW->setObjectName(QString::fromUtf8("LB_STATUS_AMBIENT_TEMP_NOW"));
        LB_STATUS_AMBIENT_TEMP_NOW->setFont(font2);

        gridLayout_2->addWidget(LB_STATUS_AMBIENT_TEMP_NOW, 4, 1, 1, 1);

        label_45 = new QLabel(layoutWidget1);
        label_45->setObjectName(QString::fromUtf8("label_45"));
        label_45->setFont(font2);
        label_45->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_45, 5, 0, 1, 1);

        LB_STATUS_EVAPORATOR_TEMP = new QLabel(layoutWidget1);
        LB_STATUS_EVAPORATOR_TEMP->setObjectName(QString::fromUtf8("LB_STATUS_EVAPORATOR_TEMP"));
        LB_STATUS_EVAPORATOR_TEMP->setFont(font2);

        gridLayout_2->addWidget(LB_STATUS_EVAPORATOR_TEMP, 5, 1, 1, 1);

        label_46 = new QLabel(layoutWidget1);
        label_46->setObjectName(QString::fromUtf8("label_46"));
        label_46->setFont(font2);
        label_46->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_46, 6, 0, 1, 1);

        LB_STATUS_CONDENSOR_TEMP = new QLabel(layoutWidget1);
        LB_STATUS_CONDENSOR_TEMP->setObjectName(QString::fromUtf8("LB_STATUS_CONDENSOR_TEMP"));
        LB_STATUS_CONDENSOR_TEMP->setFont(font2);

        gridLayout_2->addWidget(LB_STATUS_CONDENSOR_TEMP, 6, 1, 1, 1);

        label_47 = new QLabel(layoutWidget1);
        label_47->setObjectName(QString::fromUtf8("label_47"));
        label_47->setFont(font2);
        label_47->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_47, 7, 0, 1, 1);

        LE_ICE_CHECK_COUNT = new QLineEdit(layoutWidget1);
        LE_ICE_CHECK_COUNT->setObjectName(QString::fromUtf8("LE_ICE_CHECK_COUNT"));
        LE_ICE_CHECK_COUNT->setFont(font2);
        LE_ICE_CHECK_COUNT->setAlignment(Qt::AlignCenter);
        LE_ICE_CHECK_COUNT->setReadOnly(true);

        gridLayout_2->addWidget(LE_ICE_CHECK_COUNT, 7, 1, 1, 2);

        layoutWidget2 = new QWidget(GB_ICE);
        layoutWidget2->setObjectName(QString::fromUtf8("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(210, 60, 181, 266));
        gridLayout_3 = new QGridLayout(layoutWidget2);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        LB_STATUS_COMP_WORKING_2 = new QLabel(layoutWidget2);
        LB_STATUS_COMP_WORKING_2->setObjectName(QString::fromUtf8("LB_STATUS_COMP_WORKING_2"));
        LB_STATUS_COMP_WORKING_2->setFont(font2);

        gridLayout_3->addWidget(LB_STATUS_COMP_WORKING_2, 3, 1, 1, 1);

        LB_STATUS_FULL_ICE_2 = new QLabel(layoutWidget2);
        LB_STATUS_FULL_ICE_2->setObjectName(QString::fromUtf8("LB_STATUS_FULL_ICE_2"));
        LB_STATUS_FULL_ICE_2->setFont(font2);

        gridLayout_3->addWidget(LB_STATUS_FULL_ICE_2, 7, 1, 1, 1);

        LB_STATUS_GEAR_WORKING_2 = new QLabel(layoutWidget2);
        LB_STATUS_GEAR_WORKING_2->setObjectName(QString::fromUtf8("LB_STATUS_GEAR_WORKING_2"));
        LB_STATUS_GEAR_WORKING_2->setFont(font2);

        gridLayout_3->addWidget(LB_STATUS_GEAR_WORKING_2, 4, 1, 1, 1);

        label_38 = new QLabel(layoutWidget2);
        label_38->setObjectName(QString::fromUtf8("label_38"));
        label_38->setFont(font2);
        label_38->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_3->addWidget(label_38, 6, 0, 1, 1);

        LB_STATUS_COMM_MODE_2 = new QLabel(layoutWidget2);
        LB_STATUS_COMM_MODE_2->setObjectName(QString::fromUtf8("LB_STATUS_COMM_MODE_2"));
        LB_STATUS_COMM_MODE_2->setFont(font2);

        gridLayout_3->addWidget(LB_STATUS_COMM_MODE_2, 2, 1, 1, 1);

        label_56 = new QLabel(layoutWidget2);
        label_56->setObjectName(QString::fromUtf8("label_56"));
        label_56->setFont(font2);
        label_56->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_3->addWidget(label_56, 5, 0, 1, 1);

        label_37 = new QLabel(layoutWidget2);
        label_37->setObjectName(QString::fromUtf8("label_37"));
        label_37->setFont(font2);
        label_37->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_3->addWidget(label_37, 2, 0, 1, 1);

        LE_ICE_ERROR_2 = new QLineEdit(layoutWidget2);
        LE_ICE_ERROR_2->setObjectName(QString::fromUtf8("LE_ICE_ERROR_2"));
        LE_ICE_ERROR_2->setFont(font2);
        LE_ICE_ERROR_2->setAlignment(Qt::AlignCenter);
        LE_ICE_ERROR_2->setReadOnly(true);

        gridLayout_3->addWidget(LE_ICE_ERROR_2, 8, 1, 1, 1);

        label_54 = new QLabel(layoutWidget2);
        label_54->setObjectName(QString::fromUtf8("label_54"));
        label_54->setFont(font2);
        label_54->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_3->addWidget(label_54, 8, 0, 1, 1);

        label_112 = new QLabel(layoutWidget2);
        label_112->setObjectName(QString::fromUtf8("label_112"));
        label_112->setFont(font2);
        label_112->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_3->addWidget(label_112, 1, 0, 1, 1);

        label_113 = new QLabel(layoutWidget2);
        label_113->setObjectName(QString::fromUtf8("label_113"));
        label_113->setFont(font2);
        label_113->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_3->addWidget(label_113, 0, 0, 1, 1);

        LE_ICE_DATA_CONNECTION_2 = new QLineEdit(layoutWidget2);
        LE_ICE_DATA_CONNECTION_2->setObjectName(QString::fromUtf8("LE_ICE_DATA_CONNECTION_2"));
        LE_ICE_DATA_CONNECTION_2->setFont(font2);
        LE_ICE_DATA_CONNECTION_2->setReadOnly(true);

        gridLayout_3->addWidget(LE_ICE_DATA_CONNECTION_2, 1, 1, 1, 1);

        LE_ICE_CONNECTION_2 = new QLineEdit(layoutWidget2);
        LE_ICE_CONNECTION_2->setObjectName(QString::fromUtf8("LE_ICE_CONNECTION_2"));
        LE_ICE_CONNECTION_2->setFont(font2);
        LE_ICE_CONNECTION_2->setReadOnly(true);

        gridLayout_3->addWidget(LE_ICE_CONNECTION_2, 0, 1, 1, 1);

        label_55 = new QLabel(layoutWidget2);
        label_55->setObjectName(QString::fromUtf8("label_55"));
        label_55->setFont(font2);
        label_55->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_3->addWidget(label_55, 4, 0, 1, 1);

        label_39 = new QLabel(layoutWidget2);
        label_39->setObjectName(QString::fromUtf8("label_39"));
        label_39->setFont(font2);
        label_39->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_3->addWidget(label_39, 7, 0, 1, 1);

        label_35 = new QLabel(layoutWidget2);
        label_35->setObjectName(QString::fromUtf8("label_35"));
        label_35->setFont(font2);
        label_35->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_3->addWidget(label_35, 3, 0, 1, 1);

        LB_STATUS_CUP_LEVER_DETECT_2 = new QLabel(layoutWidget2);
        LB_STATUS_CUP_LEVER_DETECT_2->setObjectName(QString::fromUtf8("LB_STATUS_CUP_LEVER_DETECT_2"));
        LB_STATUS_CUP_LEVER_DETECT_2->setFont(font2);

        gridLayout_3->addWidget(LB_STATUS_CUP_LEVER_DETECT_2, 6, 1, 1, 1);

        LB_STATUS_OUT_SOL_DETECT_2 = new QLabel(layoutWidget2);
        LB_STATUS_OUT_SOL_DETECT_2->setObjectName(QString::fromUtf8("LB_STATUS_OUT_SOL_DETECT_2"));
        LB_STATUS_OUT_SOL_DETECT_2->setFont(font2);

        gridLayout_3->addWidget(LB_STATUS_OUT_SOL_DETECT_2, 5, 1, 1, 1);

        LB_ERROR_TYPE_2 = new QLabel(layoutWidget2);
        LB_ERROR_TYPE_2->setObjectName(QString::fromUtf8("LB_ERROR_TYPE_2"));
        LB_ERROR_TYPE_2->setFont(font2);

        gridLayout_3->addWidget(LB_ERROR_TYPE_2, 9, 0, 1, 2);

        layoutWidget3 = new QWidget(GB_ICE);
        layoutWidget3->setObjectName(QString::fromUtf8("layoutWidget3"));
        layoutWidget3->setGeometry(QRect(210, 500, 181, 209));
        gridLayout_4 = new QGridLayout(layoutWidget3);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        gridLayout_4->setContentsMargins(0, 0, 0, 0);
        label_67 = new QLabel(layoutWidget3);
        label_67->setObjectName(QString::fromUtf8("label_67"));
        label_67->setFont(font2);
        label_67->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_4->addWidget(label_67, 0, 0, 1, 1);

        LB_STATUS_LAST_ICE_TIME_2 = new QLabel(layoutWidget3);
        LB_STATUS_LAST_ICE_TIME_2->setObjectName(QString::fromUtf8("LB_STATUS_LAST_ICE_TIME_2"));
        LB_STATUS_LAST_ICE_TIME_2->setFont(font2);

        gridLayout_4->addWidget(LB_STATUS_LAST_ICE_TIME_2, 0, 1, 1, 1);

        label_40 = new QLabel(layoutWidget3);
        label_40->setObjectName(QString::fromUtf8("label_40"));
        label_40->setFont(font2);

        gridLayout_4->addWidget(label_40, 0, 2, 1, 1);

        label_49 = new QLabel(layoutWidget3);
        label_49->setObjectName(QString::fromUtf8("label_49"));
        label_49->setFont(font2);
        label_49->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_4->addWidget(label_49, 1, 0, 1, 1);

        LB_STATUS_LAST_WATER_TIME_2 = new QLabel(layoutWidget3);
        LB_STATUS_LAST_WATER_TIME_2->setObjectName(QString::fromUtf8("LB_STATUS_LAST_WATER_TIME_2"));
        LB_STATUS_LAST_WATER_TIME_2->setFont(font2);

        gridLayout_4->addWidget(LB_STATUS_LAST_WATER_TIME_2, 1, 1, 1, 1);

        label_68 = new QLabel(layoutWidget3);
        label_68->setObjectName(QString::fromUtf8("label_68"));
        label_68->setFont(font2);

        gridLayout_4->addWidget(label_68, 1, 2, 1, 1);

        label_51 = new QLabel(layoutWidget3);
        label_51->setObjectName(QString::fromUtf8("label_51"));
        label_51->setFont(font2);
        label_51->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_4->addWidget(label_51, 2, 0, 1, 1);

        LB_STATUS_AMBIENT_TEMP_LOW_2 = new QLabel(layoutWidget3);
        LB_STATUS_AMBIENT_TEMP_LOW_2->setObjectName(QString::fromUtf8("LB_STATUS_AMBIENT_TEMP_LOW_2"));
        LB_STATUS_AMBIENT_TEMP_LOW_2->setFont(font2);

        gridLayout_4->addWidget(LB_STATUS_AMBIENT_TEMP_LOW_2, 2, 1, 1, 1);

        label_42 = new QLabel(layoutWidget3);
        label_42->setObjectName(QString::fromUtf8("label_42"));
        label_42->setFont(font2);
        label_42->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_4->addWidget(label_42, 3, 0, 1, 1);

        LB_STATUS_AMBIENT_TEMP_HIGH_2 = new QLabel(layoutWidget3);
        LB_STATUS_AMBIENT_TEMP_HIGH_2->setObjectName(QString::fromUtf8("LB_STATUS_AMBIENT_TEMP_HIGH_2"));
        LB_STATUS_AMBIENT_TEMP_HIGH_2->setFont(font2);

        gridLayout_4->addWidget(LB_STATUS_AMBIENT_TEMP_HIGH_2, 3, 1, 1, 1);

        label_66 = new QLabel(layoutWidget3);
        label_66->setObjectName(QString::fromUtf8("label_66"));
        label_66->setFont(font2);
        label_66->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_4->addWidget(label_66, 4, 0, 1, 1);

        LB_STATUS_AMBIENT_TEMP_NOW_2 = new QLabel(layoutWidget3);
        LB_STATUS_AMBIENT_TEMP_NOW_2->setObjectName(QString::fromUtf8("LB_STATUS_AMBIENT_TEMP_NOW_2"));
        LB_STATUS_AMBIENT_TEMP_NOW_2->setFont(font2);

        gridLayout_4->addWidget(LB_STATUS_AMBIENT_TEMP_NOW_2, 4, 1, 1, 1);

        label_64 = new QLabel(layoutWidget3);
        label_64->setObjectName(QString::fromUtf8("label_64"));
        label_64->setFont(font2);
        label_64->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_4->addWidget(label_64, 5, 0, 1, 1);

        LB_STATUS_EVAPORATOR_TEMP_2 = new QLabel(layoutWidget3);
        LB_STATUS_EVAPORATOR_TEMP_2->setObjectName(QString::fromUtf8("LB_STATUS_EVAPORATOR_TEMP_2"));
        LB_STATUS_EVAPORATOR_TEMP_2->setFont(font2);

        gridLayout_4->addWidget(LB_STATUS_EVAPORATOR_TEMP_2, 5, 1, 1, 1);

        label_59 = new QLabel(layoutWidget3);
        label_59->setObjectName(QString::fromUtf8("label_59"));
        label_59->setFont(font2);
        label_59->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_4->addWidget(label_59, 6, 0, 1, 1);

        LB_STATUS_CONDENSOR_TEMP_2 = new QLabel(layoutWidget3);
        LB_STATUS_CONDENSOR_TEMP_2->setObjectName(QString::fromUtf8("LB_STATUS_CONDENSOR_TEMP_2"));
        LB_STATUS_CONDENSOR_TEMP_2->setFont(font2);

        gridLayout_4->addWidget(LB_STATUS_CONDENSOR_TEMP_2, 6, 1, 1, 1);

        label_48 = new QLabel(layoutWidget3);
        label_48->setObjectName(QString::fromUtf8("label_48"));
        label_48->setFont(font2);
        label_48->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_4->addWidget(label_48, 7, 0, 1, 1);

        LE_ICE_CHECK_COUNT_2 = new QLineEdit(layoutWidget3);
        LE_ICE_CHECK_COUNT_2->setObjectName(QString::fromUtf8("LE_ICE_CHECK_COUNT_2"));
        LE_ICE_CHECK_COUNT_2->setFont(font2);
        LE_ICE_CHECK_COUNT_2->setAlignment(Qt::AlignCenter);
        LE_ICE_CHECK_COUNT_2->setReadOnly(true);

        gridLayout_4->addWidget(LE_ICE_CHECK_COUNT_2, 7, 1, 1, 2);

        layoutWidget4 = new QWidget(GB_ICE);
        layoutWidget4->setObjectName(QString::fromUtf8("layoutWidget4"));
        layoutWidget4->setGeometry(QRect(20, 350, 161, 58));
        gridLayout_5 = new QGridLayout(layoutWidget4);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        gridLayout_5->setContentsMargins(0, 0, 0, 0);
        LE_ICE_TEST_ICE_OUT_TIME = new QLineEdit(layoutWidget4);
        LE_ICE_TEST_ICE_OUT_TIME->setObjectName(QString::fromUtf8("LE_ICE_TEST_ICE_OUT_TIME"));
        LE_ICE_TEST_ICE_OUT_TIME->setFont(font2);
        LE_ICE_TEST_ICE_OUT_TIME->setAlignment(Qt::AlignCenter);

        gridLayout_5->addWidget(LE_ICE_TEST_ICE_OUT_TIME, 0, 0, 1, 1);

        label_22 = new QLabel(layoutWidget4);
        label_22->setObjectName(QString::fromUtf8("label_22"));
        label_22->setFont(font2);

        gridLayout_5->addWidget(label_22, 0, 1, 1, 1);

        LE_ICE_TEST_WATER_OUT_TIME = new QLineEdit(layoutWidget4);
        LE_ICE_TEST_WATER_OUT_TIME->setObjectName(QString::fromUtf8("LE_ICE_TEST_WATER_OUT_TIME"));
        LE_ICE_TEST_WATER_OUT_TIME->setFont(font2);
        LE_ICE_TEST_WATER_OUT_TIME->setAlignment(Qt::AlignCenter);

        gridLayout_5->addWidget(LE_ICE_TEST_WATER_OUT_TIME, 1, 0, 1, 1);

        label_21 = new QLabel(layoutWidget4);
        label_21->setObjectName(QString::fromUtf8("label_21"));
        label_21->setFont(font2);

        gridLayout_5->addWidget(label_21, 1, 1, 1, 1);

        layoutWidget5 = new QWidget(GB_ICE);
        layoutWidget5->setObjectName(QString::fromUtf8("layoutWidget5"));
        layoutWidget5->setGeometry(QRect(220, 350, 161, 58));
        gridLayout_6 = new QGridLayout(layoutWidget5);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        gridLayout_6->setContentsMargins(0, 0, 0, 0);
        LE_ICE_TEST_ICE_OUT_TIME_2 = new QLineEdit(layoutWidget5);
        LE_ICE_TEST_ICE_OUT_TIME_2->setObjectName(QString::fromUtf8("LE_ICE_TEST_ICE_OUT_TIME_2"));
        LE_ICE_TEST_ICE_OUT_TIME_2->setFont(font2);
        LE_ICE_TEST_ICE_OUT_TIME_2->setAlignment(Qt::AlignCenter);

        gridLayout_6->addWidget(LE_ICE_TEST_ICE_OUT_TIME_2, 0, 0, 1, 1);

        label_62 = new QLabel(layoutWidget5);
        label_62->setObjectName(QString::fromUtf8("label_62"));
        label_62->setFont(font2);

        gridLayout_6->addWidget(label_62, 0, 1, 1, 1);

        LE_ICE_TEST_WATER_OUT_TIME_2 = new QLineEdit(layoutWidget5);
        LE_ICE_TEST_WATER_OUT_TIME_2->setObjectName(QString::fromUtf8("LE_ICE_TEST_WATER_OUT_TIME_2"));
        LE_ICE_TEST_WATER_OUT_TIME_2->setFont(font2);
        LE_ICE_TEST_WATER_OUT_TIME_2->setAlignment(Qt::AlignCenter);

        gridLayout_6->addWidget(LE_ICE_TEST_WATER_OUT_TIME_2, 1, 0, 1, 1);

        label_63 = new QLabel(layoutWidget5);
        label_63->setObjectName(QString::fromUtf8("label_63"));
        label_63->setFont(font2);

        gridLayout_6->addWidget(label_63, 1, 1, 1, 1);


        retranslateUi(DialogIceDispenser);

        CB_ICE_CUP_IGNORE->setCurrentIndex(0);
        CB_ICE_COMM_MODE->setCurrentIndex(1);
        CB_ICE_COMM_MODE_2->setCurrentIndex(1);
        CB_ICE_CUP_IGNORE_2->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(DialogIceDispenser);
    } // setupUi

    void retranslateUi(QDialog *DialogIceDispenser)
    {
        DialogIceDispenser->setWindowTitle(QCoreApplication::translate("DialogIceDispenser", "Dialog", nullptr));
        GB_ICE->setTitle(QCoreApplication::translate("DialogIceDispenser", "\354\226\274\354\235\214 \353\224\224\354\212\244\355\216\234\354\204\234", nullptr));
        BTN_ICE_TEST_ICE_OUT->setText(QCoreApplication::translate("DialogIceDispenser", "\354\266\234\353\271\231 / \354\266\234\354\210\230", nullptr));
        CB_ICE_CUP_IGNORE->setItemText(0, QCoreApplication::translate("DialogIceDispenser", "\354\273\265\354\235\264\355\203\210\354\213\234\354\244\221\354\247\200", nullptr));
        CB_ICE_CUP_IGNORE->setItemText(1, QCoreApplication::translate("DialogIceDispenser", "\354\273\265\354\235\264\355\203\210\353\254\264\354\213\234", nullptr));

        label_9->setText(QCoreApplication::translate("DialogIceDispenser", "\355\206\265\354\213\240\353\252\250\353\223\234 \353\263\200\352\262\275", nullptr));
        BTN_ICE_TEST_REBOOT->setText(QCoreApplication::translate("DialogIceDispenser", "\353\246\254\354\205\213", nullptr));
        CB_ICE_COMM_MODE->setItemText(0, QCoreApplication::translate("DialogIceDispenser", "\354\235\274\353\260\230\353\252\250\353\223\234", nullptr));
        CB_ICE_COMM_MODE->setItemText(1, QCoreApplication::translate("DialogIceDispenser", "\355\206\265\354\213\240\353\252\250\353\223\234", nullptr));

        BTN_ICE_TEST_STATUS_CLEAR->setText(QCoreApplication::translate("DialogIceDispenser", "\355\201\264\353\246\254\354\226\264", nullptr));
        BTN_ICE_CHANGE_COMM_MODE->setText(QCoreApplication::translate("DialogIceDispenser", "\354\240\201\354\232\251", nullptr));
        CB_ICE_COMM_MODE_2->setItemText(0, QCoreApplication::translate("DialogIceDispenser", "\354\235\274\353\260\230\353\252\250\353\223\234", nullptr));
        CB_ICE_COMM_MODE_2->setItemText(1, QCoreApplication::translate("DialogIceDispenser", "\355\206\265\354\213\240\353\252\250\353\223\234", nullptr));

        CB_ICE_CUP_IGNORE_2->setItemText(0, QCoreApplication::translate("DialogIceDispenser", "\354\273\265\354\235\264\355\203\210\354\213\234\354\244\221\354\247\200", nullptr));
        CB_ICE_CUP_IGNORE_2->setItemText(1, QCoreApplication::translate("DialogIceDispenser", "\354\273\265\354\235\264\355\203\210\353\254\264\354\213\234", nullptr));

        BTN_ICE_TEST_STATUS_CLEAR_2->setText(QCoreApplication::translate("DialogIceDispenser", "\355\201\264\353\246\254\354\226\264", nullptr));
        BTN_ICE_CHANGE_COMM_MODE_2->setText(QCoreApplication::translate("DialogIceDispenser", "\354\240\201\354\232\251", nullptr));
        label_61->setText(QCoreApplication::translate("DialogIceDispenser", "\355\206\265\354\213\240\353\252\250\353\223\234 \353\263\200\352\262\275", nullptr));
        BTN_ICE_TEST_REBOOT_2->setText(QCoreApplication::translate("DialogIceDispenser", "\353\246\254\354\205\213", nullptr));
        BTN_ICE_TEST_ICE_OUT_2->setText(QCoreApplication::translate("DialogIceDispenser", "\354\266\234\353\271\231 / \354\266\234\354\210\230", nullptr));
        label_28->setText(QCoreApplication::translate("DialogIceDispenser", "\354\266\234\353\271\231SOL:", nullptr));
        LB_STATUS_GEAR_WORKING->setText(QCoreApplication::translate("DialogIceDispenser", "\353\217\231\354\236\221\354\244\221", nullptr));
        LB_STATUS_CUP_LEVER_DETECT->setText(QCoreApplication::translate("DialogIceDispenser", "\352\260\220\354\247\200", nullptr));
        LB_STATUS_OUT_SOL_DETECT->setText(QCoreApplication::translate("DialogIceDispenser", "\352\260\220\354\247\200", nullptr));
        label_26->setText(QCoreApplication::translate("DialogIceDispenser", "\353\247\214\353\271\231:", nullptr));
        label_111->setText(QCoreApplication::translate("DialogIceDispenser", "\353\215\260\354\235\264\355\204\260 \354\203\201\355\203\234", nullptr));
        label_110->setText(QCoreApplication::translate("DialogIceDispenser", "\354\236\245\354\271\230 \354\227\260\352\262\260 \354\203\201\355\203\234", nullptr));
        LB_STATUS_COMM_MODE->setText(QCoreApplication::translate("DialogIceDispenser", "RS232", nullptr));
        LB_STATUS_COMP_WORKING->setText(QCoreApplication::translate("DialogIceDispenser", "\353\217\231\354\236\221\354\244\221", nullptr));
        label_41->setText(QCoreApplication::translate("DialogIceDispenser", "\354\227\220\353\237\254", nullptr));
        label_27->setText(QCoreApplication::translate("DialogIceDispenser", "\355\206\265\354\213\240\353\252\250\353\223\234: ", nullptr));
        label_30->setText(QCoreApplication::translate("DialogIceDispenser", "\352\270\260\354\226\264\353\252\250\355\204\260:", nullptr));
        LB_STATUS_FULL_ICE->setText(QCoreApplication::translate("DialogIceDispenser", "ON", nullptr));
        label_25->setText(QCoreApplication::translate("DialogIceDispenser", "\354\273\265\353\240\210\353\262\204:", nullptr));
        label_29->setText(QCoreApplication::translate("DialogIceDispenser", "\354\275\244\355\221\270\353\240\210\354\205\224:", nullptr));
        LB_ERROR_TYPE->setText(QString());
        label_31->setText(QCoreApplication::translate("DialogIceDispenser", "\354\266\234\353\271\231 \354\213\234\352\260\204:", nullptr));
        LB_STATUS_LAST_ICE_TIME->setText(QCoreApplication::translate("DialogIceDispenser", "0", nullptr));
        label_32->setText(QCoreApplication::translate("DialogIceDispenser", "\354\264\210", nullptr));
        label_43->setText(QCoreApplication::translate("DialogIceDispenser", "\354\266\234\354\210\230 \354\213\234\352\260\204:", nullptr));
        LB_STATUS_LAST_WATER_TIME->setText(QCoreApplication::translate("DialogIceDispenser", "0", nullptr));
        label_33->setText(QCoreApplication::translate("DialogIceDispenser", "\354\264\210", nullptr));
        label_34->setText(QCoreApplication::translate("DialogIceDispenser", "\354\230\250\353\217\204 \354\204\244\354\240\225(\354\240\200):", nullptr));
        LB_STATUS_AMBIENT_TEMP_LOW->setText(QCoreApplication::translate("DialogIceDispenser", "0", nullptr));
        label_36->setText(QCoreApplication::translate("DialogIceDispenser", "\354\230\250\353\217\204 \354\204\244\354\240\225(\352\263\240):", nullptr));
        LB_STATUS_AMBIENT_TEMP_HIGH->setText(QCoreApplication::translate("DialogIceDispenser", "0", nullptr));
        label_44->setText(QCoreApplication::translate("DialogIceDispenser", "\354\230\250\353\217\204 \354\204\244\354\240\225(\355\230\204):", nullptr));
        LB_STATUS_AMBIENT_TEMP_NOW->setText(QCoreApplication::translate("DialogIceDispenser", "0", nullptr));
        label_45->setText(QCoreApplication::translate("DialogIceDispenser", "\354\246\235\353\260\234\352\270\260 \354\230\250\353\217\204:", nullptr));
        LB_STATUS_EVAPORATOR_TEMP->setText(QCoreApplication::translate("DialogIceDispenser", "0", nullptr));
        label_46->setText(QCoreApplication::translate("DialogIceDispenser", "\354\275\230\353\215\264\354\204\234 \354\230\250\353\217\204:", nullptr));
        LB_STATUS_CONDENSOR_TEMP->setText(QCoreApplication::translate("DialogIceDispenser", "0", nullptr));
        label_47->setText(QCoreApplication::translate("DialogIceDispenser", "\354\262\264\355\201\254\354\271\264\354\232\264\355\212\270:", nullptr));
        LE_ICE_CHECK_COUNT->setText(QCoreApplication::translate("DialogIceDispenser", "0", nullptr));
        LB_STATUS_COMP_WORKING_2->setText(QCoreApplication::translate("DialogIceDispenser", "\353\217\231\354\236\221\354\244\221", nullptr));
        LB_STATUS_FULL_ICE_2->setText(QCoreApplication::translate("DialogIceDispenser", "ON", nullptr));
        LB_STATUS_GEAR_WORKING_2->setText(QCoreApplication::translate("DialogIceDispenser", "\353\217\231\354\236\221\354\244\221", nullptr));
        label_38->setText(QCoreApplication::translate("DialogIceDispenser", "\354\273\265\353\240\210\353\262\204:", nullptr));
        LB_STATUS_COMM_MODE_2->setText(QCoreApplication::translate("DialogIceDispenser", "RS232", nullptr));
        label_56->setText(QCoreApplication::translate("DialogIceDispenser", "\354\266\234\353\271\231SOL:", nullptr));
        label_37->setText(QCoreApplication::translate("DialogIceDispenser", "\355\206\265\354\213\240\353\252\250\353\223\234: ", nullptr));
        label_54->setText(QCoreApplication::translate("DialogIceDispenser", "\354\227\220\353\237\254", nullptr));
        label_112->setText(QCoreApplication::translate("DialogIceDispenser", "\353\215\260\354\235\264\355\204\260 \354\203\201\355\203\234", nullptr));
        label_113->setText(QCoreApplication::translate("DialogIceDispenser", "\354\236\245\354\271\230 \354\227\260\352\262\260 \354\203\201\355\203\234", nullptr));
        label_55->setText(QCoreApplication::translate("DialogIceDispenser", "\352\270\260\354\226\264\353\252\250\355\204\260:", nullptr));
        label_39->setText(QCoreApplication::translate("DialogIceDispenser", "\353\247\214\353\271\231:", nullptr));
        label_35->setText(QCoreApplication::translate("DialogIceDispenser", "\354\275\244\355\221\270\353\240\210\354\205\224:", nullptr));
        LB_STATUS_CUP_LEVER_DETECT_2->setText(QCoreApplication::translate("DialogIceDispenser", "\352\260\220\354\247\200", nullptr));
        LB_STATUS_OUT_SOL_DETECT_2->setText(QCoreApplication::translate("DialogIceDispenser", "\352\260\220\354\247\200", nullptr));
        LB_ERROR_TYPE_2->setText(QString());
        label_67->setText(QCoreApplication::translate("DialogIceDispenser", "\354\266\234\353\271\231 \354\213\234\352\260\204:", nullptr));
        LB_STATUS_LAST_ICE_TIME_2->setText(QCoreApplication::translate("DialogIceDispenser", "0", nullptr));
        label_40->setText(QCoreApplication::translate("DialogIceDispenser", "\354\264\210", nullptr));
        label_49->setText(QCoreApplication::translate("DialogIceDispenser", "\354\266\234\354\210\230 \354\213\234\352\260\204:", nullptr));
        LB_STATUS_LAST_WATER_TIME_2->setText(QCoreApplication::translate("DialogIceDispenser", "0", nullptr));
        label_68->setText(QCoreApplication::translate("DialogIceDispenser", "\354\264\210", nullptr));
        label_51->setText(QCoreApplication::translate("DialogIceDispenser", "\354\230\250\353\217\204 \354\204\244\354\240\225(\354\240\200):", nullptr));
        LB_STATUS_AMBIENT_TEMP_LOW_2->setText(QCoreApplication::translate("DialogIceDispenser", "0", nullptr));
        label_42->setText(QCoreApplication::translate("DialogIceDispenser", "\354\230\250\353\217\204 \354\204\244\354\240\225(\352\263\240):", nullptr));
        LB_STATUS_AMBIENT_TEMP_HIGH_2->setText(QCoreApplication::translate("DialogIceDispenser", "0", nullptr));
        label_66->setText(QCoreApplication::translate("DialogIceDispenser", "\354\230\250\353\217\204 \354\204\244\354\240\225(\355\230\204):", nullptr));
        LB_STATUS_AMBIENT_TEMP_NOW_2->setText(QCoreApplication::translate("DialogIceDispenser", "0", nullptr));
        label_64->setText(QCoreApplication::translate("DialogIceDispenser", "\354\246\235\353\260\234\352\270\260 \354\230\250\353\217\204:", nullptr));
        LB_STATUS_EVAPORATOR_TEMP_2->setText(QCoreApplication::translate("DialogIceDispenser", "0", nullptr));
        label_59->setText(QCoreApplication::translate("DialogIceDispenser", "\354\275\230\353\215\264\354\204\234 \354\230\250\353\217\204:", nullptr));
        LB_STATUS_CONDENSOR_TEMP_2->setText(QCoreApplication::translate("DialogIceDispenser", "0", nullptr));
        label_48->setText(QCoreApplication::translate("DialogIceDispenser", "\354\262\264\355\201\254\354\271\264\354\232\264\355\212\270:", nullptr));
        LE_ICE_CHECK_COUNT_2->setText(QCoreApplication::translate("DialogIceDispenser", "0", nullptr));
        LE_ICE_TEST_ICE_OUT_TIME->setText(QCoreApplication::translate("DialogIceDispenser", "3", nullptr));
        label_22->setText(QCoreApplication::translate("DialogIceDispenser", "\354\264\210 (\354\226\274\354\235\214)", nullptr));
        LE_ICE_TEST_WATER_OUT_TIME->setText(QCoreApplication::translate("DialogIceDispenser", "0", nullptr));
        label_21->setText(QCoreApplication::translate("DialogIceDispenser", "\354\264\210 (\353\254\274)", nullptr));
        LE_ICE_TEST_ICE_OUT_TIME_2->setText(QCoreApplication::translate("DialogIceDispenser", "3", nullptr));
        label_62->setText(QCoreApplication::translate("DialogIceDispenser", "\354\264\210 (\354\226\274\354\235\214)", nullptr));
        LE_ICE_TEST_WATER_OUT_TIME_2->setText(QCoreApplication::translate("DialogIceDispenser", "0", nullptr));
        label_63->setText(QCoreApplication::translate("DialogIceDispenser", "\354\264\210 (\353\254\274)", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DialogIceDispenser: public Ui_DialogIceDispenser {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGICEDISPENSER_H
