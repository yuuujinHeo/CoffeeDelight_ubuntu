/********************************************************************************
** Form generated from reading UI file 'displaydialog.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DISPLAYDIALOG_H
#define UI_DISPLAYDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_DisplayDialog
{
public:
    QLabel *LE_WAIT_STATUS_2;
    QLabel *LE_OUTLET_PIN_2_2;
    QLabel *LE_OUTLET_STATUS_1_3;
    QLabel *LE_OUTLET_PIN_1_3;
    QLabel *LE_OUTLET_PIN_1_2;
    QLabel *LB_WAIT_PIN_4;
    QLabel *LB_WAIT_PIN_6;
    QLabel *LE_OUTLET_MENU_2_2;
    QLabel *LE_WAIT_STATUS_7;
    QLabel *LE_OUTLET_MENU_2_3;
    QLabel *LB_WAIT_PIN;
    QLabel *LE_OUTLET_PIN_2_1;
    QLabel *LE_OUTLET_MENU_1_2;
    QLabel *LE_OUTLET_STATUS_1_1;
    QLabel *LE_WAIT_NAME_5;
    QLabel *LB_WAIT_PIN_2;
    QLabel *LB_WAIT_PIN_5;
    QLabel *LE_WAIT_STATUS_5;
    QLabel *LE_WAIT_STATUS;
    QLabel *LE_WAIT_NAME_3;
    QLabel *LE_WAIT_NAME_6;
    QLabel *LE_OUTLET_MENU_1_3;
    QLabel *LE_OUTLET_STATUS_1_2;
    QLabel *LE_WAIT_NAME_4;
    QLabel *LE_OUTLET_STATUS_2_1;
    QLabel *LB_WAIT_PIN_3;
    QLabel *LE_OUTLET_PIN_1_1;
    QLabel *LE_OUTLET_MENU_2_1;
    QLabel *LE_OUTLET_STATUS_2_3;
    QLabel *LE_WAIT_NAME_7;
    QLabel *LE_OUTLET_STATUS_2_2;
    QLabel *LE_WAIT_STATUS_4;
    QLabel *label;
    QLabel *LE_WAIT_NAME_2;
    QLabel *LE_WAIT_NAME;
    QLabel *LE_WAIT_STATUS_6;
    QLabel *LB_WAIT_PIN_7;
    QLabel *LE_OUTLET_MENU_1_1;
    QLabel *LE_OUTLET_PIN_2_3;
    QLabel *LE_WAIT_STATUS_3;
    QLabel *BACKGROUND_READY;
    QLabel *BACKGROUND_1;
    QLabel *BACKGROUND_2;
    QLabel *BACKGROUND_3;
    QLabel *LE_CALL;
    QLabel *LE_TIME;
    QFrame *FR_NOTICE;
    QLabel *LB_NOTICE;

    void setupUi(QDialog *DisplayDialog)
    {
        if (DisplayDialog->objectName().isEmpty())
            DisplayDialog->setObjectName(QString::fromUtf8("DisplayDialog"));
        DisplayDialog->resize(1920, 1080);
        LE_WAIT_STATUS_2 = new QLabel(DisplayDialog);
        LE_WAIT_STATUS_2->setObjectName(QString::fromUtf8("LE_WAIT_STATUS_2"));
        LE_WAIT_STATUS_2->setGeometry(QRect(940, 517, 40, 40));
        QFont font;
        font.setFamily(QString::fromUtf8("Yrsa SemiBold"));
        font.setPointSize(30);
        LE_WAIT_STATUS_2->setFont(font);
        LE_WAIT_STATUS_2->setPixmap(QPixmap(QString::fromUtf8(":/build/image/waiting.png")));
        LE_WAIT_STATUS_2->setScaledContents(true);
        LE_WAIT_STATUS_2->setAlignment(Qt::AlignCenter);
        LE_OUTLET_PIN_2_2 = new QLabel(DisplayDialog);
        LE_OUTLET_PIN_2_2->setObjectName(QString::fromUtf8("LE_OUTLET_PIN_2_2"));
        LE_OUTLET_PIN_2_2->setGeometry(QRect(1527, 640, 301, 71));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Yrsa SemiBold"));
        font1.setPointSize(45);
        font1.setBold(true);
        font1.setWeight(75);
        LE_OUTLET_PIN_2_2->setFont(font1);
        LE_OUTLET_PIN_2_2->setAlignment(Qt::AlignCenter);
        LE_OUTLET_STATUS_1_3 = new QLabel(DisplayDialog);
        LE_OUTLET_STATUS_1_3->setObjectName(QString::fromUtf8("LE_OUTLET_STATUS_1_3"));
        LE_OUTLET_STATUS_1_3->setGeometry(QRect(1199, 787, 301, 181));
        LE_OUTLET_STATUS_1_3->setPixmap(QPixmap(QString::fromUtf8(":/build/image/outlet.png")));
        LE_OUTLET_STATUS_1_3->setScaledContents(true);
        LE_OUTLET_PIN_1_3 = new QLabel(DisplayDialog);
        LE_OUTLET_PIN_1_3->setObjectName(QString::fromUtf8("LE_OUTLET_PIN_1_3"));
        LE_OUTLET_PIN_1_3->setGeometry(QRect(1200, 820, 301, 71));
        LE_OUTLET_PIN_1_3->setFont(font1);
        LE_OUTLET_PIN_1_3->setAlignment(Qt::AlignCenter);
        LE_OUTLET_PIN_1_2 = new QLabel(DisplayDialog);
        LE_OUTLET_PIN_1_2->setObjectName(QString::fromUtf8("LE_OUTLET_PIN_1_2"));
        LE_OUTLET_PIN_1_2->setGeometry(QRect(1200, 640, 301, 71));
        LE_OUTLET_PIN_1_2->setFont(font1);
        LE_OUTLET_PIN_1_2->setAlignment(Qt::AlignCenter);
        LB_WAIT_PIN_4 = new QLabel(DisplayDialog);
        LB_WAIT_PIN_4->setObjectName(QString::fromUtf8("LB_WAIT_PIN_4"));
        LB_WAIT_PIN_4->setGeometry(QRect(110, 658, 251, 71));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Yrsa SemiBold"));
        font2.setPointSize(35);
        font2.setBold(true);
        font2.setWeight(75);
        LB_WAIT_PIN_4->setFont(font2);
        LB_WAIT_PIN_4->setAlignment(Qt::AlignCenter);
        LB_WAIT_PIN_6 = new QLabel(DisplayDialog);
        LB_WAIT_PIN_6->setObjectName(QString::fromUtf8("LB_WAIT_PIN_6"));
        LB_WAIT_PIN_6->setGeometry(QRect(110, 815, 251, 71));
        LB_WAIT_PIN_6->setFont(font2);
        LB_WAIT_PIN_6->setAlignment(Qt::AlignCenter);
        LE_OUTLET_MENU_2_2 = new QLabel(DisplayDialog);
        LE_OUTLET_MENU_2_2->setObjectName(QString::fromUtf8("LE_OUTLET_MENU_2_2"));
        LE_OUTLET_MENU_2_2->setGeometry(QRect(1527, 700, 301, 61));
        QFont font3;
        font3.setFamily(QString::fromUtf8("Yrsa SemiBold"));
        font3.setPointSize(20);
        LE_OUTLET_MENU_2_2->setFont(font3);
        LE_OUTLET_MENU_2_2->setAlignment(Qt::AlignCenter);
        LE_WAIT_STATUS_7 = new QLabel(DisplayDialog);
        LE_WAIT_STATUS_7->setObjectName(QString::fromUtf8("LE_WAIT_STATUS_7"));
        LE_WAIT_STATUS_7->setGeometry(QRect(940, 910, 40, 40));
        LE_WAIT_STATUS_7->setFont(font);
        LE_WAIT_STATUS_7->setPixmap(QPixmap(QString::fromUtf8(":/build/image/waiting.png")));
        LE_WAIT_STATUS_7->setScaledContents(true);
        LE_WAIT_STATUS_7->setAlignment(Qt::AlignCenter);
        LE_OUTLET_MENU_2_3 = new QLabel(DisplayDialog);
        LE_OUTLET_MENU_2_3->setObjectName(QString::fromUtf8("LE_OUTLET_MENU_2_3"));
        LE_OUTLET_MENU_2_3->setGeometry(QRect(1527, 880, 301, 61));
        LE_OUTLET_MENU_2_3->setFont(font3);
        LE_OUTLET_MENU_2_3->setAlignment(Qt::AlignCenter);
        LB_WAIT_PIN = new QLabel(DisplayDialog);
        LB_WAIT_PIN->setObjectName(QString::fromUtf8("LB_WAIT_PIN"));
        LB_WAIT_PIN->setGeometry(QRect(110, 420, 251, 71));
        LB_WAIT_PIN->setFont(font2);
        LB_WAIT_PIN->setAlignment(Qt::AlignCenter);
        LE_OUTLET_PIN_2_1 = new QLabel(DisplayDialog);
        LE_OUTLET_PIN_2_1->setObjectName(QString::fromUtf8("LE_OUTLET_PIN_2_1"));
        LE_OUTLET_PIN_2_1->setGeometry(QRect(1527, 450, 301, 71));
        LE_OUTLET_PIN_2_1->setFont(font1);
        LE_OUTLET_PIN_2_1->setAlignment(Qt::AlignCenter);
        LE_OUTLET_MENU_1_2 = new QLabel(DisplayDialog);
        LE_OUTLET_MENU_1_2->setObjectName(QString::fromUtf8("LE_OUTLET_MENU_1_2"));
        LE_OUTLET_MENU_1_2->setGeometry(QRect(1200, 700, 301, 61));
        LE_OUTLET_MENU_1_2->setFont(font3);
        LE_OUTLET_MENU_1_2->setAlignment(Qt::AlignCenter);
        LE_OUTLET_STATUS_1_1 = new QLabel(DisplayDialog);
        LE_OUTLET_STATUS_1_1->setObjectName(QString::fromUtf8("LE_OUTLET_STATUS_1_1"));
        LE_OUTLET_STATUS_1_1->setGeometry(QRect(1199, 420, 301, 181));
        LE_OUTLET_STATUS_1_1->setPixmap(QPixmap(QString::fromUtf8(":/build/image/outlet.png")));
        LE_OUTLET_STATUS_1_1->setScaledContents(true);
        LE_WAIT_NAME_5 = new QLabel(DisplayDialog);
        LE_WAIT_NAME_5->setObjectName(QString::fromUtf8("LE_WAIT_NAME_5"));
        LE_WAIT_NAME_5->setGeometry(QRect(370, 736, 451, 71));
        QFont font4;
        font4.setFamily(QString::fromUtf8("Yrsa SemiBold"));
        font4.setPointSize(25);
        font4.setBold(true);
        font4.setWeight(75);
        LE_WAIT_NAME_5->setFont(font4);
        LE_WAIT_NAME_5->setAlignment(Qt::AlignCenter);
        LB_WAIT_PIN_2 = new QLabel(DisplayDialog);
        LB_WAIT_PIN_2->setObjectName(QString::fromUtf8("LB_WAIT_PIN_2"));
        LB_WAIT_PIN_2->setGeometry(QRect(110, 500, 251, 71));
        LB_WAIT_PIN_2->setFont(font2);
        LB_WAIT_PIN_2->setAlignment(Qt::AlignCenter);
        LB_WAIT_PIN_5 = new QLabel(DisplayDialog);
        LB_WAIT_PIN_5->setObjectName(QString::fromUtf8("LB_WAIT_PIN_5"));
        LB_WAIT_PIN_5->setGeometry(QRect(110, 736, 251, 71));
        LB_WAIT_PIN_5->setFont(font2);
        LB_WAIT_PIN_5->setAlignment(Qt::AlignCenter);
        LE_WAIT_STATUS_5 = new QLabel(DisplayDialog);
        LE_WAIT_STATUS_5->setObjectName(QString::fromUtf8("LE_WAIT_STATUS_5"));
        LE_WAIT_STATUS_5->setGeometry(QRect(940, 754, 40, 40));
        LE_WAIT_STATUS_5->setFont(font);
        LE_WAIT_STATUS_5->setPixmap(QPixmap(QString::fromUtf8(":/build/image/waiting.png")));
        LE_WAIT_STATUS_5->setScaledContents(true);
        LE_WAIT_STATUS_5->setAlignment(Qt::AlignCenter);
        LE_WAIT_STATUS = new QLabel(DisplayDialog);
        LE_WAIT_STATUS->setObjectName(QString::fromUtf8("LE_WAIT_STATUS"));
        LE_WAIT_STATUS->setGeometry(QRect(940, 436, 40, 40));
        LE_WAIT_STATUS->setFont(font);
        LE_WAIT_STATUS->setPixmap(QPixmap(QString::fromUtf8(":/build/image/making.png")));
        LE_WAIT_STATUS->setScaledContents(true);
        LE_WAIT_STATUS->setAlignment(Qt::AlignCenter);
        LE_WAIT_NAME_3 = new QLabel(DisplayDialog);
        LE_WAIT_NAME_3->setObjectName(QString::fromUtf8("LE_WAIT_NAME_3"));
        LE_WAIT_NAME_3->setGeometry(QRect(370, 580, 451, 71));
        LE_WAIT_NAME_3->setFont(font4);
        LE_WAIT_NAME_3->setAlignment(Qt::AlignCenter);
        LE_WAIT_NAME_6 = new QLabel(DisplayDialog);
        LE_WAIT_NAME_6->setObjectName(QString::fromUtf8("LE_WAIT_NAME_6"));
        LE_WAIT_NAME_6->setGeometry(QRect(370, 814, 451, 71));
        LE_WAIT_NAME_6->setFont(font4);
        LE_WAIT_NAME_6->setAlignment(Qt::AlignCenter);
        LE_OUTLET_MENU_1_3 = new QLabel(DisplayDialog);
        LE_OUTLET_MENU_1_3->setObjectName(QString::fromUtf8("LE_OUTLET_MENU_1_3"));
        LE_OUTLET_MENU_1_3->setGeometry(QRect(1200, 880, 301, 61));
        LE_OUTLET_MENU_1_3->setFont(font3);
        LE_OUTLET_MENU_1_3->setAlignment(Qt::AlignCenter);
        LE_OUTLET_STATUS_1_2 = new QLabel(DisplayDialog);
        LE_OUTLET_STATUS_1_2->setObjectName(QString::fromUtf8("LE_OUTLET_STATUS_1_2"));
        LE_OUTLET_STATUS_1_2->setGeometry(QRect(1199, 604, 301, 181));
        LE_OUTLET_STATUS_1_2->setPixmap(QPixmap(QString::fromUtf8(":/build/image/outlet.png")));
        LE_OUTLET_STATUS_1_2->setScaledContents(true);
        LE_WAIT_NAME_4 = new QLabel(DisplayDialog);
        LE_WAIT_NAME_4->setObjectName(QString::fromUtf8("LE_WAIT_NAME_4"));
        LE_WAIT_NAME_4->setGeometry(QRect(370, 657, 451, 71));
        LE_WAIT_NAME_4->setFont(font4);
        LE_WAIT_NAME_4->setAlignment(Qt::AlignCenter);
        LE_OUTLET_STATUS_2_1 = new QLabel(DisplayDialog);
        LE_OUTLET_STATUS_2_1->setObjectName(QString::fromUtf8("LE_OUTLET_STATUS_2_1"));
        LE_OUTLET_STATUS_2_1->setGeometry(QRect(1526, 421, 301, 181));
        LE_OUTLET_STATUS_2_1->setPixmap(QPixmap(QString::fromUtf8(":/build/image/outlet.png")));
        LE_OUTLET_STATUS_2_1->setScaledContents(true);
        LB_WAIT_PIN_3 = new QLabel(DisplayDialog);
        LB_WAIT_PIN_3->setObjectName(QString::fromUtf8("LB_WAIT_PIN_3"));
        LB_WAIT_PIN_3->setGeometry(QRect(110, 580, 251, 71));
        LB_WAIT_PIN_3->setFont(font2);
        LB_WAIT_PIN_3->setAlignment(Qt::AlignCenter);
        LE_OUTLET_PIN_1_1 = new QLabel(DisplayDialog);
        LE_OUTLET_PIN_1_1->setObjectName(QString::fromUtf8("LE_OUTLET_PIN_1_1"));
        LE_OUTLET_PIN_1_1->setGeometry(QRect(1200, 450, 301, 71));
        LE_OUTLET_PIN_1_1->setFont(font1);
        LE_OUTLET_PIN_1_1->setAlignment(Qt::AlignCenter);
        LE_OUTLET_MENU_2_1 = new QLabel(DisplayDialog);
        LE_OUTLET_MENU_2_1->setObjectName(QString::fromUtf8("LE_OUTLET_MENU_2_1"));
        LE_OUTLET_MENU_2_1->setGeometry(QRect(1527, 510, 301, 61));
        LE_OUTLET_MENU_2_1->setFont(font3);
        LE_OUTLET_MENU_2_1->setAlignment(Qt::AlignCenter);
        LE_OUTLET_STATUS_2_3 = new QLabel(DisplayDialog);
        LE_OUTLET_STATUS_2_3->setObjectName(QString::fromUtf8("LE_OUTLET_STATUS_2_3"));
        LE_OUTLET_STATUS_2_3->setGeometry(QRect(1526, 788, 301, 181));
        LE_OUTLET_STATUS_2_3->setPixmap(QPixmap(QString::fromUtf8(":/build/image/outlet.png")));
        LE_OUTLET_STATUS_2_3->setScaledContents(true);
        LE_WAIT_NAME_7 = new QLabel(DisplayDialog);
        LE_WAIT_NAME_7->setObjectName(QString::fromUtf8("LE_WAIT_NAME_7"));
        LE_WAIT_NAME_7->setGeometry(QRect(370, 893, 451, 71));
        LE_WAIT_NAME_7->setFont(font4);
        LE_WAIT_NAME_7->setAlignment(Qt::AlignCenter);
        LE_OUTLET_STATUS_2_2 = new QLabel(DisplayDialog);
        LE_OUTLET_STATUS_2_2->setObjectName(QString::fromUtf8("LE_OUTLET_STATUS_2_2"));
        LE_OUTLET_STATUS_2_2->setGeometry(QRect(1526, 605, 301, 181));
        LE_OUTLET_STATUS_2_2->setPixmap(QPixmap(QString::fromUtf8(":/build/image/outlet.png")));
        LE_OUTLET_STATUS_2_2->setScaledContents(true);
        LE_WAIT_STATUS_4 = new QLabel(DisplayDialog);
        LE_WAIT_STATUS_4->setObjectName(QString::fromUtf8("LE_WAIT_STATUS_4"));
        LE_WAIT_STATUS_4->setGeometry(QRect(940, 674, 40, 40));
        LE_WAIT_STATUS_4->setFont(font);
        LE_WAIT_STATUS_4->setPixmap(QPixmap(QString::fromUtf8(":/build/image/waiting.png")));
        LE_WAIT_STATUS_4->setScaledContents(true);
        LE_WAIT_STATUS_4->setAlignment(Qt::AlignCenter);
        label = new QLabel(DisplayDialog);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(0, 0, 1920, 1080));
        label->setPixmap(QPixmap(QString::fromUtf8(":/build/image/background.png")));
        label->setScaledContents(true);
        LE_WAIT_NAME_2 = new QLabel(DisplayDialog);
        LE_WAIT_NAME_2->setObjectName(QString::fromUtf8("LE_WAIT_NAME_2"));
        LE_WAIT_NAME_2->setGeometry(QRect(370, 500, 451, 71));
        LE_WAIT_NAME_2->setFont(font4);
        LE_WAIT_NAME_2->setAlignment(Qt::AlignCenter);
        LE_WAIT_NAME = new QLabel(DisplayDialog);
        LE_WAIT_NAME->setObjectName(QString::fromUtf8("LE_WAIT_NAME"));
        LE_WAIT_NAME->setGeometry(QRect(370, 420, 451, 71));
        LE_WAIT_NAME->setFont(font4);
        LE_WAIT_NAME->setAlignment(Qt::AlignCenter);
        LE_WAIT_STATUS_6 = new QLabel(DisplayDialog);
        LE_WAIT_STATUS_6->setObjectName(QString::fromUtf8("LE_WAIT_STATUS_6"));
        LE_WAIT_STATUS_6->setGeometry(QRect(940, 833, 40, 40));
        LE_WAIT_STATUS_6->setFont(font);
        LE_WAIT_STATUS_6->setPixmap(QPixmap(QString::fromUtf8(":/build/image/waiting.png")));
        LE_WAIT_STATUS_6->setScaledContents(true);
        LE_WAIT_STATUS_6->setAlignment(Qt::AlignCenter);
        LB_WAIT_PIN_7 = new QLabel(DisplayDialog);
        LB_WAIT_PIN_7->setObjectName(QString::fromUtf8("LB_WAIT_PIN_7"));
        LB_WAIT_PIN_7->setGeometry(QRect(110, 894, 251, 71));
        LB_WAIT_PIN_7->setFont(font2);
        LB_WAIT_PIN_7->setAlignment(Qt::AlignCenter);
        LE_OUTLET_MENU_1_1 = new QLabel(DisplayDialog);
        LE_OUTLET_MENU_1_1->setObjectName(QString::fromUtf8("LE_OUTLET_MENU_1_1"));
        LE_OUTLET_MENU_1_1->setGeometry(QRect(1200, 510, 301, 61));
        LE_OUTLET_MENU_1_1->setFont(font3);
        LE_OUTLET_MENU_1_1->setAlignment(Qt::AlignCenter);
        LE_OUTLET_PIN_2_3 = new QLabel(DisplayDialog);
        LE_OUTLET_PIN_2_3->setObjectName(QString::fromUtf8("LE_OUTLET_PIN_2_3"));
        LE_OUTLET_PIN_2_3->setGeometry(QRect(1527, 820, 301, 71));
        LE_OUTLET_PIN_2_3->setFont(font1);
        LE_OUTLET_PIN_2_3->setAlignment(Qt::AlignCenter);
        LE_WAIT_STATUS_3 = new QLabel(DisplayDialog);
        LE_WAIT_STATUS_3->setObjectName(QString::fromUtf8("LE_WAIT_STATUS_3"));
        LE_WAIT_STATUS_3->setGeometry(QRect(940, 595, 40, 40));
        LE_WAIT_STATUS_3->setFont(font);
        LE_WAIT_STATUS_3->setPixmap(QPixmap(QString::fromUtf8(":/build/image/waiting.png")));
        LE_WAIT_STATUS_3->setScaledContents(true);
        LE_WAIT_STATUS_3->setAlignment(Qt::AlignCenter);
        BACKGROUND_READY = new QLabel(DisplayDialog);
        BACKGROUND_READY->setObjectName(QString::fromUtf8("BACKGROUND_READY"));
        BACKGROUND_READY->setEnabled(true);
        BACKGROUND_READY->setGeometry(QRect(0, 0, 1920, 1080));
        BACKGROUND_READY->setPixmap(QPixmap(QString::fromUtf8(":/build/image/background_prepare.png")));
        BACKGROUND_READY->setScaledContents(true);
        BACKGROUND_1 = new QLabel(DisplayDialog);
        BACKGROUND_1->setObjectName(QString::fromUtf8("BACKGROUND_1"));
        BACKGROUND_1->setGeometry(QRect(1920, 0, 1920, 1080));
        BACKGROUND_1->setPixmap(QPixmap(QString::fromUtf8(":/build/image/display_page1.png")));
        BACKGROUND_1->setScaledContents(true);
        BACKGROUND_2 = new QLabel(DisplayDialog);
        BACKGROUND_2->setObjectName(QString::fromUtf8("BACKGROUND_2"));
        BACKGROUND_2->setGeometry(QRect(1920, 0, 1920, 1080));
        BACKGROUND_2->setPixmap(QPixmap(QString::fromUtf8(":/build/image/display_page2.png")));
        BACKGROUND_2->setScaledContents(true);
        BACKGROUND_3 = new QLabel(DisplayDialog);
        BACKGROUND_3->setObjectName(QString::fromUtf8("BACKGROUND_3"));
        BACKGROUND_3->setEnabled(true);
        BACKGROUND_3->setGeometry(QRect(1920, 0, 1920, 1080));
        BACKGROUND_3->setPixmap(QPixmap(QString::fromUtf8(":/build/image/display_page3.png")));
        BACKGROUND_3->setScaledContents(true);
        LE_CALL = new QLabel(DisplayDialog);
        LE_CALL->setObjectName(QString::fromUtf8("LE_CALL"));
        LE_CALL->setGeometry(QRect(410, 55, 431, 71));
        QFont font5;
        font5.setFamily(QString::fromUtf8("Yrsa SemiBold"));
        font5.setPointSize(30);
        font5.setBold(true);
        font5.setWeight(75);
        LE_CALL->setFont(font5);
        LE_CALL->setAlignment(Qt::AlignCenter);
        LE_TIME = new QLabel(DisplayDialog);
        LE_TIME->setObjectName(QString::fromUtf8("LE_TIME"));
        LE_TIME->setGeometry(QRect(770, 970, 71, 71));
        LE_TIME->setFont(font4);
        LE_TIME->setAlignment(Qt::AlignCenter);
        FR_NOTICE = new QFrame(DisplayDialog);
        FR_NOTICE->setObjectName(QString::fromUtf8("FR_NOTICE"));
        FR_NOTICE->setGeometry(QRect(0, 134, 1920, 200));
        FR_NOTICE->setAutoFillBackground(false);
        FR_NOTICE->setStyleSheet(QString::fromUtf8("QFrame{\n"
"	background-color: rgb(239, 41, 41);\n"
"}\n"
"QLabel{\n"
"	color: white;\n"
"	font: 70pt \"\355\225\250\354\264\210\353\241\254\353\217\213\354\233\200\";\n"
"}"));
        FR_NOTICE->setFrameShape(QFrame::NoFrame);
        FR_NOTICE->setFrameShadow(QFrame::Raised);
        LB_NOTICE = new QLabel(FR_NOTICE);
        LB_NOTICE->setObjectName(QString::fromUtf8("LB_NOTICE"));
        LB_NOTICE->setGeometry(QRect(0, 0, 1921, 200));
        LB_NOTICE->setToolTipDuration(0);
        LB_NOTICE->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	border:2px solid #D1BCED;\n"
"	font: 30pt \"\355\225\250\354\264\210\353\241\254\353\217\213\354\233\200\"; \n"
" 	color: white;\\n}"));
        LB_NOTICE->setAlignment(Qt::AlignCenter);
        label->raise();
        LE_WAIT_STATUS_2->raise();
        LE_OUTLET_PIN_2_2->raise();
        LE_OUTLET_PIN_1_3->raise();
        LE_OUTLET_PIN_1_2->raise();
        LB_WAIT_PIN_4->raise();
        LB_WAIT_PIN_6->raise();
        LE_OUTLET_MENU_2_2->raise();
        LE_WAIT_STATUS_7->raise();
        LE_OUTLET_MENU_2_3->raise();
        LB_WAIT_PIN->raise();
        LE_OUTLET_PIN_2_1->raise();
        LE_OUTLET_MENU_1_2->raise();
        LE_WAIT_NAME_5->raise();
        LB_WAIT_PIN_5->raise();
        LE_WAIT_STATUS_5->raise();
        LE_WAIT_STATUS->raise();
        LE_WAIT_NAME_3->raise();
        LE_WAIT_NAME_6->raise();
        LE_OUTLET_MENU_1_3->raise();
        LE_WAIT_NAME_4->raise();
        LE_OUTLET_PIN_1_1->raise();
        LE_OUTLET_MENU_2_1->raise();
        LE_WAIT_NAME_7->raise();
        LE_WAIT_STATUS_4->raise();
        LE_WAIT_NAME_2->raise();
        LE_WAIT_NAME->raise();
        LE_WAIT_STATUS_6->raise();
        LB_WAIT_PIN_7->raise();
        LE_OUTLET_MENU_1_1->raise();
        LE_OUTLET_PIN_2_3->raise();
        LE_WAIT_STATUS_3->raise();
        LB_WAIT_PIN_2->raise();
        LB_WAIT_PIN_3->raise();
        LE_OUTLET_STATUS_2_2->raise();
        LE_OUTLET_STATUS_1_3->raise();
        LE_OUTLET_STATUS_1_1->raise();
        LE_OUTLET_STATUS_1_2->raise();
        LE_OUTLET_STATUS_2_3->raise();
        LE_OUTLET_STATUS_2_1->raise();
        BACKGROUND_1->raise();
        BACKGROUND_2->raise();
        BACKGROUND_3->raise();
        LE_CALL->raise();
        LE_TIME->raise();
        FR_NOTICE->raise();
        BACKGROUND_READY->raise();

        retranslateUi(DisplayDialog);

        QMetaObject::connectSlotsByName(DisplayDialog);
    } // setupUi

    void retranslateUi(QDialog *DisplayDialog)
    {
        DisplayDialog->setWindowTitle(QCoreApplication::translate("DisplayDialog", "Dialog", nullptr));
        LE_WAIT_STATUS_2->setText(QString());
        LE_OUTLET_PIN_2_2->setText(QCoreApplication::translate("DisplayDialog", "22222", nullptr));
        LE_OUTLET_STATUS_1_3->setText(QString());
        LE_OUTLET_PIN_1_3->setText(QCoreApplication::translate("DisplayDialog", "22222", nullptr));
        LE_OUTLET_PIN_1_2->setText(QCoreApplication::translate("DisplayDialog", "22222", nullptr));
        LB_WAIT_PIN_4->setText(QCoreApplication::translate("DisplayDialog", "22222", nullptr));
        LB_WAIT_PIN_6->setText(QCoreApplication::translate("DisplayDialog", "22222", nullptr));
        LE_OUTLET_MENU_2_2->setText(QCoreApplication::translate("DisplayDialog", "ICE AMERICANO", nullptr));
        LE_WAIT_STATUS_7->setText(QString());
        LE_OUTLET_MENU_2_3->setText(QCoreApplication::translate("DisplayDialog", "ICE AMERICANO", nullptr));
        LB_WAIT_PIN->setText(QCoreApplication::translate("DisplayDialog", "22222", nullptr));
        LE_OUTLET_PIN_2_1->setText(QCoreApplication::translate("DisplayDialog", "22222", nullptr));
        LE_OUTLET_MENU_1_2->setText(QCoreApplication::translate("DisplayDialog", "ICE AMERICANO", nullptr));
        LE_OUTLET_STATUS_1_1->setText(QString());
        LE_WAIT_NAME_5->setText(QCoreApplication::translate("DisplayDialog", "ICE AMERICANO", nullptr));
        LB_WAIT_PIN_2->setText(QCoreApplication::translate("DisplayDialog", "22222", nullptr));
        LB_WAIT_PIN_5->setText(QCoreApplication::translate("DisplayDialog", "22222", nullptr));
        LE_WAIT_STATUS_5->setText(QString());
        LE_WAIT_STATUS->setText(QString());
        LE_WAIT_NAME_3->setText(QCoreApplication::translate("DisplayDialog", "ICE AMERICANO", nullptr));
        LE_WAIT_NAME_6->setText(QCoreApplication::translate("DisplayDialog", "ICE AMERICANO", nullptr));
        LE_OUTLET_MENU_1_3->setText(QCoreApplication::translate("DisplayDialog", "ICE AMERICANO", nullptr));
        LE_OUTLET_STATUS_1_2->setText(QString());
        LE_WAIT_NAME_4->setText(QCoreApplication::translate("DisplayDialog", "ICE AMERICANO", nullptr));
        LE_OUTLET_STATUS_2_1->setText(QString());
        LB_WAIT_PIN_3->setText(QCoreApplication::translate("DisplayDialog", "22222", nullptr));
        LE_OUTLET_PIN_1_1->setText(QCoreApplication::translate("DisplayDialog", "22222", nullptr));
        LE_OUTLET_MENU_2_1->setText(QCoreApplication::translate("DisplayDialog", "ICE AMERICANO", nullptr));
        LE_OUTLET_STATUS_2_3->setText(QString());
        LE_WAIT_NAME_7->setText(QCoreApplication::translate("DisplayDialog", "ICE AMERICANO", nullptr));
        LE_OUTLET_STATUS_2_2->setText(QString());
        LE_WAIT_STATUS_4->setText(QString());
        label->setText(QString());
        LE_WAIT_NAME_2->setText(QCoreApplication::translate("DisplayDialog", "ICE AMERICANO", nullptr));
        LE_WAIT_NAME->setText(QCoreApplication::translate("DisplayDialog", "ICE AMERICANO", nullptr));
        LE_WAIT_STATUS_6->setText(QString());
        LB_WAIT_PIN_7->setText(QCoreApplication::translate("DisplayDialog", "22222", nullptr));
        LE_OUTLET_MENU_1_1->setText(QCoreApplication::translate("DisplayDialog", "ICE AMERICANO", nullptr));
        LE_OUTLET_PIN_2_3->setText(QCoreApplication::translate("DisplayDialog", "22222", nullptr));
        LE_WAIT_STATUS_3->setText(QString());
        BACKGROUND_READY->setText(QString());
        BACKGROUND_1->setText(QString());
        BACKGROUND_2->setText(QString());
        BACKGROUND_3->setText(QString());
        LE_CALL->setText(QCoreApplication::translate("DisplayDialog", "\354\227\260\352\262\260\353\220\230\354\247\200 \354\225\212\354\235\214", nullptr));
        LE_TIME->setText(QCoreApplication::translate("DisplayDialog", "0", nullptr));
        LB_NOTICE->setText(QCoreApplication::translate("DisplayDialog", "hello", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DisplayDialog: public Ui_DisplayDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DISPLAYDIALOG_H
