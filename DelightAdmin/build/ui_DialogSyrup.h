/********************************************************************************
** Form generated from reading UI file 'DialogSyrup.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGSYRUP_H
#define UI_DIALOGSYRUP_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DialogSyrup
{
public:
    QGroupBox *GB_SYRUP;
    QLineEdit *LE_SYRUP_CONNECTION;
    QLabel *label_110;
    QFrame *line_37;
    QPushButton *BTN_DISPENSE_SYRUP_BY_TIME_1;
    QFrame *line_38;
    QLineEdit *LE_SYRUP_DISPENSE_COUNT;
    QLabel *label_112;
    QLineEdit *LE_LAST_DISPENSE_ERROR;
    QLabel *label_113;
    QLabel *label_114;
    QLineEdit *LE_OP_STATE;
    QLabel *label;
    QLabel *label_2;
    QPushButton *BTN_DISPENSE_SYRUP_BY_WEIGHT_1;
    QLabel *label_22;
    QLineEdit *LE_SYRUP_OUT_TIME;
    QLabel *label_116;
    QLabel *label_117;
    QLabel *label_118;
    QLineEdit *LE_LOADCELL_WEIGHT;
    QLineEdit *LE_LOADCELL_SCALE;
    QLineEdit *LE_LOADCELL_ERROR;
    QLabel *label_119;
    QLineEdit *LE_LOADCELL_SET_SCALE;
    QPushButton *BTN_SET_SCALE;
    QPushButton *BTN_TARE;
    QLineEdit *LE_SYRUP_OUT_WEIGHT;
    QLabel *label_27;
    QPushButton *BTN_DISPENSE_SYRUP_BY_TIME_2;
    QPushButton *BTN_DISPENSE_SYRUP_BY_TIME_3;
    QPushButton *BTN_DISPENSE_SYRUP_BY_TIME_4;
    QPushButton *BTN_DISPENSE_SYRUP_BY_TIME_5;
    QPushButton *BTN_DISPENSE_SYRUP_BY_TIME_6;
    QPushButton *BTN_DISPENSE_SYRUP_BY_TIME_7;
    QPushButton *BTN_DISPENSE_SYRUP_BY_TIME_8;
    QLabel *label_111;
    QLabel *label_121;
    QPushButton *BTN_DISPENSE_SYRUP_BY_WEIGHT_2;
    QPushButton *BTN_DISPENSE_SYRUP_BY_WEIGHT_3;
    QPushButton *BTN_DISPENSE_SYRUP_BY_WEIGHT_4;
    QPushButton *BTN_DISPENSE_SYRUP_BY_WEIGHT_5;
    QPushButton *BTN_DISPENSE_SYRUP_BY_WEIGHT_6;
    QPushButton *BTN_DISPENSE_SYRUP_BY_WEIGHT_7;
    QPushButton *BTN_DISPENSE_SYRUP_BY_WEIGHT_8;
    QFrame *line_39;
    QCheckBox *CB_SCALE_TEST;
    QFrame *line_40;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QLineEdit *LE_SYRUP_OUT_TIME_2;
    QLabel *label_23;
    QPushButton *BTN_CLEANING;

    void setupUi(QDialog *DialogSyrup)
    {
        if (DialogSyrup->objectName().isEmpty())
            DialogSyrup->setObjectName(QString::fromUtf8("DialogSyrup"));
        DialogSyrup->resize(402, 931);
        GB_SYRUP = new QGroupBox(DialogSyrup);
        GB_SYRUP->setObjectName(QString::fromUtf8("GB_SYRUP"));
        GB_SYRUP->setGeometry(QRect(0, 0, 401, 971));
        QFont font;
        font.setFamily(QString::fromUtf8("\355\225\250\354\264\210\353\241\254\353\217\213\354\233\200"));
        font.setPointSize(20);
        font.setBold(false);
        font.setItalic(false);
        font.setWeight(50);
        GB_SYRUP->setFont(font);
        GB_SYRUP->setStyleSheet(QString::fromUtf8("QGroupBox  {\n"
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
        LE_SYRUP_CONNECTION = new QLineEdit(GB_SYRUP);
        LE_SYRUP_CONNECTION->setObjectName(QString::fromUtf8("LE_SYRUP_CONNECTION"));
        LE_SYRUP_CONNECTION->setGeometry(QRect(130, 60, 61, 21));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\355\225\250\354\264\210\353\241\254\353\217\213\354\233\200"));
        font1.setPointSize(10);
        font1.setBold(false);
        font1.setItalic(false);
        font1.setWeight(50);
        LE_SYRUP_CONNECTION->setFont(font1);
        LE_SYRUP_CONNECTION->setReadOnly(true);
        label_110 = new QLabel(GB_SYRUP);
        label_110->setObjectName(QString::fromUtf8("label_110"));
        label_110->setGeometry(QRect(20, 60, 101, 21));
        label_110->setFont(font1);
        label_110->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        line_37 = new QFrame(GB_SYRUP);
        line_37->setObjectName(QString::fromUtf8("line_37"));
        line_37->setGeometry(QRect(10, 80, 361, 16));
        QFont font2;
        font2.setPointSize(11);
        line_37->setFont(font2);
        line_37->setFrameShape(QFrame::HLine);
        line_37->setFrameShadow(QFrame::Sunken);
        BTN_DISPENSE_SYRUP_BY_TIME_1 = new QPushButton(GB_SYRUP);
        BTN_DISPENSE_SYRUP_BY_TIME_1->setObjectName(QString::fromUtf8("BTN_DISPENSE_SYRUP_BY_TIME_1"));
        BTN_DISPENSE_SYRUP_BY_TIME_1->setGeometry(QRect(20, 130, 81, 41));
        BTN_DISPENSE_SYRUP_BY_TIME_1->setFont(font1);
        line_38 = new QFrame(GB_SYRUP);
        line_38->setObjectName(QString::fromUtf8("line_38"));
        line_38->setGeometry(QRect(10, 230, 361, 16));
        line_38->setFont(font2);
        line_38->setFrameShape(QFrame::HLine);
        line_38->setFrameShadow(QFrame::Sunken);
        LE_SYRUP_DISPENSE_COUNT = new QLineEdit(GB_SYRUP);
        LE_SYRUP_DISPENSE_COUNT->setObjectName(QString::fromUtf8("LE_SYRUP_DISPENSE_COUNT"));
        LE_SYRUP_DISPENSE_COUNT->setGeometry(QRect(110, 790, 61, 21));
        LE_SYRUP_DISPENSE_COUNT->setFont(font1);
        LE_SYRUP_DISPENSE_COUNT->setReadOnly(true);
        label_112 = new QLabel(GB_SYRUP);
        label_112->setObjectName(QString::fromUtf8("label_112"));
        label_112->setGeometry(QRect(30, 790, 71, 21));
        label_112->setFont(font1);
        label_112->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        LE_LAST_DISPENSE_ERROR = new QLineEdit(GB_SYRUP);
        LE_LAST_DISPENSE_ERROR->setObjectName(QString::fromUtf8("LE_LAST_DISPENSE_ERROR"));
        LE_LAST_DISPENSE_ERROR->setGeometry(QRect(110, 820, 61, 21));
        LE_LAST_DISPENSE_ERROR->setFont(font1);
        LE_LAST_DISPENSE_ERROR->setReadOnly(true);
        label_113 = new QLabel(GB_SYRUP);
        label_113->setObjectName(QString::fromUtf8("label_113"));
        label_113->setGeometry(QRect(20, 820, 81, 21));
        label_113->setFont(font1);
        label_113->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_114 = new QLabel(GB_SYRUP);
        label_114->setObjectName(QString::fromUtf8("label_114"));
        label_114->setGeometry(QRect(20, 850, 81, 21));
        label_114->setFont(font1);
        label_114->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        LE_OP_STATE = new QLineEdit(GB_SYRUP);
        LE_OP_STATE->setObjectName(QString::fromUtf8("LE_OP_STATE"));
        LE_OP_STATE->setGeometry(QRect(110, 850, 61, 21));
        LE_OP_STATE->setFont(font1);
        LE_OP_STATE->setReadOnly(true);
        label = new QLabel(GB_SYRUP);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 880, 311, 17));
        label->setFont(font1);
        label_2 = new QLabel(GB_SYRUP);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(20, 900, 311, 17));
        label_2->setFont(font1);
        BTN_DISPENSE_SYRUP_BY_WEIGHT_1 = new QPushButton(GB_SYRUP);
        BTN_DISPENSE_SYRUP_BY_WEIGHT_1->setObjectName(QString::fromUtf8("BTN_DISPENSE_SYRUP_BY_WEIGHT_1"));
        BTN_DISPENSE_SYRUP_BY_WEIGHT_1->setGeometry(QRect(20, 280, 81, 41));
        BTN_DISPENSE_SYRUP_BY_WEIGHT_1->setFont(font1);
        label_22 = new QLabel(GB_SYRUP);
        label_22->setObjectName(QString::fromUtf8("label_22"));
        label_22->setGeometry(QRect(150, 100, 21, 21));
        label_22->setFont(font1);
        LE_SYRUP_OUT_TIME = new QLineEdit(GB_SYRUP);
        LE_SYRUP_OUT_TIME->setObjectName(QString::fromUtf8("LE_SYRUP_OUT_TIME"));
        LE_SYRUP_OUT_TIME->setGeometry(QRect(100, 100, 41, 21));
        LE_SYRUP_OUT_TIME->setFont(font1);
        LE_SYRUP_OUT_TIME->setAlignment(Qt::AlignCenter);
        label_116 = new QLabel(GB_SYRUP);
        label_116->setObjectName(QString::fromUtf8("label_116"));
        label_116->setGeometry(QRect(20, 610, 81, 21));
        label_116->setFont(font1);
        label_116->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_117 = new QLabel(GB_SYRUP);
        label_117->setObjectName(QString::fromUtf8("label_117"));
        label_117->setGeometry(QRect(20, 640, 81, 21));
        label_117->setFont(font1);
        label_117->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_118 = new QLabel(GB_SYRUP);
        label_118->setObjectName(QString::fromUtf8("label_118"));
        label_118->setGeometry(QRect(20, 670, 81, 21));
        label_118->setFont(font1);
        label_118->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        LE_LOADCELL_WEIGHT = new QLineEdit(GB_SYRUP);
        LE_LOADCELL_WEIGHT->setObjectName(QString::fromUtf8("LE_LOADCELL_WEIGHT"));
        LE_LOADCELL_WEIGHT->setGeometry(QRect(110, 610, 61, 21));
        LE_LOADCELL_WEIGHT->setFont(font1);
        LE_LOADCELL_WEIGHT->setReadOnly(true);
        LE_LOADCELL_SCALE = new QLineEdit(GB_SYRUP);
        LE_LOADCELL_SCALE->setObjectName(QString::fromUtf8("LE_LOADCELL_SCALE"));
        LE_LOADCELL_SCALE->setGeometry(QRect(110, 640, 61, 21));
        LE_LOADCELL_SCALE->setFont(font1);
        LE_LOADCELL_SCALE->setReadOnly(true);
        LE_LOADCELL_ERROR = new QLineEdit(GB_SYRUP);
        LE_LOADCELL_ERROR->setObjectName(QString::fromUtf8("LE_LOADCELL_ERROR"));
        LE_LOADCELL_ERROR->setGeometry(QRect(110, 670, 61, 21));
        LE_LOADCELL_ERROR->setFont(font1);
        LE_LOADCELL_ERROR->setReadOnly(true);
        label_119 = new QLabel(GB_SYRUP);
        label_119->setObjectName(QString::fromUtf8("label_119"));
        label_119->setGeometry(QRect(20, 710, 81, 21));
        label_119->setFont(font1);
        label_119->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        LE_LOADCELL_SET_SCALE = new QLineEdit(GB_SYRUP);
        LE_LOADCELL_SET_SCALE->setObjectName(QString::fromUtf8("LE_LOADCELL_SET_SCALE"));
        LE_LOADCELL_SET_SCALE->setGeometry(QRect(110, 710, 61, 21));
        LE_LOADCELL_SET_SCALE->setFont(font1);
        LE_LOADCELL_SET_SCALE->setReadOnly(false);
        BTN_SET_SCALE = new QPushButton(GB_SYRUP);
        BTN_SET_SCALE->setObjectName(QString::fromUtf8("BTN_SET_SCALE"));
        BTN_SET_SCALE->setGeometry(QRect(110, 740, 61, 31));
        BTN_SET_SCALE->setFont(font1);
        BTN_TARE = new QPushButton(GB_SYRUP);
        BTN_TARE->setObjectName(QString::fromUtf8("BTN_TARE"));
        BTN_TARE->setGeometry(QRect(180, 610, 61, 31));
        BTN_TARE->setFont(font1);
        LE_SYRUP_OUT_WEIGHT = new QLineEdit(GB_SYRUP);
        LE_SYRUP_OUT_WEIGHT->setObjectName(QString::fromUtf8("LE_SYRUP_OUT_WEIGHT"));
        LE_SYRUP_OUT_WEIGHT->setGeometry(QRect(100, 250, 51, 21));
        LE_SYRUP_OUT_WEIGHT->setFont(font1);
        LE_SYRUP_OUT_WEIGHT->setAlignment(Qt::AlignCenter);
        label_27 = new QLabel(GB_SYRUP);
        label_27->setObjectName(QString::fromUtf8("label_27"));
        label_27->setGeometry(QRect(160, 250, 21, 21));
        label_27->setFont(font1);
        BTN_DISPENSE_SYRUP_BY_TIME_2 = new QPushButton(GB_SYRUP);
        BTN_DISPENSE_SYRUP_BY_TIME_2->setObjectName(QString::fromUtf8("BTN_DISPENSE_SYRUP_BY_TIME_2"));
        BTN_DISPENSE_SYRUP_BY_TIME_2->setGeometry(QRect(110, 130, 81, 41));
        BTN_DISPENSE_SYRUP_BY_TIME_2->setFont(font1);
        BTN_DISPENSE_SYRUP_BY_TIME_3 = new QPushButton(GB_SYRUP);
        BTN_DISPENSE_SYRUP_BY_TIME_3->setObjectName(QString::fromUtf8("BTN_DISPENSE_SYRUP_BY_TIME_3"));
        BTN_DISPENSE_SYRUP_BY_TIME_3->setGeometry(QRect(200, 130, 81, 41));
        BTN_DISPENSE_SYRUP_BY_TIME_3->setFont(font1);
        BTN_DISPENSE_SYRUP_BY_TIME_4 = new QPushButton(GB_SYRUP);
        BTN_DISPENSE_SYRUP_BY_TIME_4->setObjectName(QString::fromUtf8("BTN_DISPENSE_SYRUP_BY_TIME_4"));
        BTN_DISPENSE_SYRUP_BY_TIME_4->setGeometry(QRect(290, 130, 81, 41));
        BTN_DISPENSE_SYRUP_BY_TIME_4->setFont(font1);
        BTN_DISPENSE_SYRUP_BY_TIME_5 = new QPushButton(GB_SYRUP);
        BTN_DISPENSE_SYRUP_BY_TIME_5->setObjectName(QString::fromUtf8("BTN_DISPENSE_SYRUP_BY_TIME_5"));
        BTN_DISPENSE_SYRUP_BY_TIME_5->setEnabled(true);
        BTN_DISPENSE_SYRUP_BY_TIME_5->setGeometry(QRect(20, 180, 81, 41));
        BTN_DISPENSE_SYRUP_BY_TIME_5->setFont(font1);
        BTN_DISPENSE_SYRUP_BY_TIME_6 = new QPushButton(GB_SYRUP);
        BTN_DISPENSE_SYRUP_BY_TIME_6->setObjectName(QString::fromUtf8("BTN_DISPENSE_SYRUP_BY_TIME_6"));
        BTN_DISPENSE_SYRUP_BY_TIME_6->setGeometry(QRect(110, 180, 81, 41));
        BTN_DISPENSE_SYRUP_BY_TIME_6->setFont(font1);
        BTN_DISPENSE_SYRUP_BY_TIME_7 = new QPushButton(GB_SYRUP);
        BTN_DISPENSE_SYRUP_BY_TIME_7->setObjectName(QString::fromUtf8("BTN_DISPENSE_SYRUP_BY_TIME_7"));
        BTN_DISPENSE_SYRUP_BY_TIME_7->setEnabled(true);
        BTN_DISPENSE_SYRUP_BY_TIME_7->setGeometry(QRect(200, 180, 81, 41));
        BTN_DISPENSE_SYRUP_BY_TIME_7->setFont(font1);
        BTN_DISPENSE_SYRUP_BY_TIME_8 = new QPushButton(GB_SYRUP);
        BTN_DISPENSE_SYRUP_BY_TIME_8->setObjectName(QString::fromUtf8("BTN_DISPENSE_SYRUP_BY_TIME_8"));
        BTN_DISPENSE_SYRUP_BY_TIME_8->setEnabled(true);
        BTN_DISPENSE_SYRUP_BY_TIME_8->setGeometry(QRect(290, 180, 81, 41));
        BTN_DISPENSE_SYRUP_BY_TIME_8->setFont(font1);
        label_111 = new QLabel(GB_SYRUP);
        label_111->setObjectName(QString::fromUtf8("label_111"));
        label_111->setGeometry(QRect(20, 100, 81, 21));
        label_111->setFont(font1);
        label_111->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        label_121 = new QLabel(GB_SYRUP);
        label_121->setObjectName(QString::fromUtf8("label_121"));
        label_121->setGeometry(QRect(20, 250, 81, 21));
        label_121->setFont(font1);
        label_121->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        BTN_DISPENSE_SYRUP_BY_WEIGHT_2 = new QPushButton(GB_SYRUP);
        BTN_DISPENSE_SYRUP_BY_WEIGHT_2->setObjectName(QString::fromUtf8("BTN_DISPENSE_SYRUP_BY_WEIGHT_2"));
        BTN_DISPENSE_SYRUP_BY_WEIGHT_2->setGeometry(QRect(110, 280, 81, 41));
        BTN_DISPENSE_SYRUP_BY_WEIGHT_2->setFont(font1);
        BTN_DISPENSE_SYRUP_BY_WEIGHT_3 = new QPushButton(GB_SYRUP);
        BTN_DISPENSE_SYRUP_BY_WEIGHT_3->setObjectName(QString::fromUtf8("BTN_DISPENSE_SYRUP_BY_WEIGHT_3"));
        BTN_DISPENSE_SYRUP_BY_WEIGHT_3->setGeometry(QRect(200, 280, 81, 41));
        BTN_DISPENSE_SYRUP_BY_WEIGHT_3->setFont(font1);
        BTN_DISPENSE_SYRUP_BY_WEIGHT_4 = new QPushButton(GB_SYRUP);
        BTN_DISPENSE_SYRUP_BY_WEIGHT_4->setObjectName(QString::fromUtf8("BTN_DISPENSE_SYRUP_BY_WEIGHT_4"));
        BTN_DISPENSE_SYRUP_BY_WEIGHT_4->setGeometry(QRect(290, 280, 81, 41));
        BTN_DISPENSE_SYRUP_BY_WEIGHT_4->setFont(font1);
        BTN_DISPENSE_SYRUP_BY_WEIGHT_5 = new QPushButton(GB_SYRUP);
        BTN_DISPENSE_SYRUP_BY_WEIGHT_5->setObjectName(QString::fromUtf8("BTN_DISPENSE_SYRUP_BY_WEIGHT_5"));
        BTN_DISPENSE_SYRUP_BY_WEIGHT_5->setEnabled(true);
        BTN_DISPENSE_SYRUP_BY_WEIGHT_5->setGeometry(QRect(20, 330, 81, 41));
        BTN_DISPENSE_SYRUP_BY_WEIGHT_5->setFont(font1);
        BTN_DISPENSE_SYRUP_BY_WEIGHT_6 = new QPushButton(GB_SYRUP);
        BTN_DISPENSE_SYRUP_BY_WEIGHT_6->setObjectName(QString::fromUtf8("BTN_DISPENSE_SYRUP_BY_WEIGHT_6"));
        BTN_DISPENSE_SYRUP_BY_WEIGHT_6->setGeometry(QRect(110, 330, 81, 41));
        BTN_DISPENSE_SYRUP_BY_WEIGHT_6->setFont(font1);
        BTN_DISPENSE_SYRUP_BY_WEIGHT_7 = new QPushButton(GB_SYRUP);
        BTN_DISPENSE_SYRUP_BY_WEIGHT_7->setObjectName(QString::fromUtf8("BTN_DISPENSE_SYRUP_BY_WEIGHT_7"));
        BTN_DISPENSE_SYRUP_BY_WEIGHT_7->setEnabled(true);
        BTN_DISPENSE_SYRUP_BY_WEIGHT_7->setGeometry(QRect(200, 330, 81, 41));
        BTN_DISPENSE_SYRUP_BY_WEIGHT_7->setFont(font1);
        BTN_DISPENSE_SYRUP_BY_WEIGHT_8 = new QPushButton(GB_SYRUP);
        BTN_DISPENSE_SYRUP_BY_WEIGHT_8->setObjectName(QString::fromUtf8("BTN_DISPENSE_SYRUP_BY_WEIGHT_8"));
        BTN_DISPENSE_SYRUP_BY_WEIGHT_8->setEnabled(true);
        BTN_DISPENSE_SYRUP_BY_WEIGHT_8->setGeometry(QRect(290, 330, 81, 41));
        BTN_DISPENSE_SYRUP_BY_WEIGHT_8->setFont(font1);
        line_39 = new QFrame(GB_SYRUP);
        line_39->setObjectName(QString::fromUtf8("line_39"));
        line_39->setGeometry(QRect(20, 580, 351, 16));
        line_39->setFont(font2);
        line_39->setFrameShape(QFrame::HLine);
        line_39->setFrameShadow(QFrame::Sunken);
        CB_SCALE_TEST = new QCheckBox(GB_SYRUP);
        CB_SCALE_TEST->setObjectName(QString::fromUtf8("CB_SCALE_TEST"));
        CB_SCALE_TEST->setGeometry(QRect(180, 710, 81, 23));
        line_40 = new QFrame(GB_SYRUP);
        line_40->setObjectName(QString::fromUtf8("line_40"));
        line_40->setGeometry(QRect(20, 390, 351, 16));
        line_40->setFont(font2);
        line_40->setFrameShape(QFrame::HLine);
        line_40->setFrameShadow(QFrame::Sunken);
        layoutWidget = new QWidget(GB_SYRUP);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(70, 440, 231, 42));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        LE_SYRUP_OUT_TIME_2 = new QLineEdit(layoutWidget);
        LE_SYRUP_OUT_TIME_2->setObjectName(QString::fromUtf8("LE_SYRUP_OUT_TIME_2"));
        LE_SYRUP_OUT_TIME_2->setMaximumSize(QSize(100, 16777215));
        LE_SYRUP_OUT_TIME_2->setFont(font1);
        LE_SYRUP_OUT_TIME_2->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(LE_SYRUP_OUT_TIME_2);

        label_23 = new QLabel(layoutWidget);
        label_23->setObjectName(QString::fromUtf8("label_23"));
        label_23->setFont(font1);

        horizontalLayout->addWidget(label_23);

        BTN_CLEANING = new QPushButton(layoutWidget);
        BTN_CLEANING->setObjectName(QString::fromUtf8("BTN_CLEANING"));
        BTN_CLEANING->setMinimumSize(QSize(0, 40));
        BTN_CLEANING->setFont(font1);

        horizontalLayout->addWidget(BTN_CLEANING);

        BTN_DISPENSE_SYRUP_BY_WEIGHT_4->raise();
        LE_SYRUP_CONNECTION->raise();
        label_110->raise();
        line_37->raise();
        BTN_DISPENSE_SYRUP_BY_TIME_1->raise();
        line_38->raise();
        LE_SYRUP_DISPENSE_COUNT->raise();
        label_112->raise();
        LE_LAST_DISPENSE_ERROR->raise();
        label_113->raise();
        label_114->raise();
        LE_OP_STATE->raise();
        label->raise();
        label_2->raise();
        BTN_DISPENSE_SYRUP_BY_WEIGHT_1->raise();
        label_22->raise();
        LE_SYRUP_OUT_TIME->raise();
        label_116->raise();
        label_117->raise();
        label_118->raise();
        LE_LOADCELL_WEIGHT->raise();
        LE_LOADCELL_SCALE->raise();
        LE_LOADCELL_ERROR->raise();
        label_119->raise();
        LE_LOADCELL_SET_SCALE->raise();
        BTN_SET_SCALE->raise();
        BTN_TARE->raise();
        LE_SYRUP_OUT_WEIGHT->raise();
        label_27->raise();
        BTN_DISPENSE_SYRUP_BY_TIME_2->raise();
        BTN_DISPENSE_SYRUP_BY_TIME_3->raise();
        BTN_DISPENSE_SYRUP_BY_TIME_4->raise();
        BTN_DISPENSE_SYRUP_BY_TIME_5->raise();
        BTN_DISPENSE_SYRUP_BY_TIME_6->raise();
        BTN_DISPENSE_SYRUP_BY_TIME_7->raise();
        BTN_DISPENSE_SYRUP_BY_TIME_8->raise();
        label_111->raise();
        label_121->raise();
        BTN_DISPENSE_SYRUP_BY_WEIGHT_2->raise();
        BTN_DISPENSE_SYRUP_BY_WEIGHT_3->raise();
        BTN_DISPENSE_SYRUP_BY_WEIGHT_5->raise();
        BTN_DISPENSE_SYRUP_BY_WEIGHT_6->raise();
        BTN_DISPENSE_SYRUP_BY_WEIGHT_7->raise();
        BTN_DISPENSE_SYRUP_BY_WEIGHT_8->raise();
        line_39->raise();
        CB_SCALE_TEST->raise();
        line_40->raise();
        layoutWidget->raise();

        retranslateUi(DialogSyrup);

        QMetaObject::connectSlotsByName(DialogSyrup);
    } // setupUi

    void retranslateUi(QDialog *DialogSyrup)
    {
        DialogSyrup->setWindowTitle(QCoreApplication::translate("DialogSyrup", "Dialog", nullptr));
        GB_SYRUP->setTitle(QCoreApplication::translate("DialogSyrup", "\354\213\234\353\237\275 \353\224\224\354\212\244\355\216\234\354\204\234", nullptr));
        label_110->setText(QCoreApplication::translate("DialogSyrup", "\354\236\245\354\271\230 \354\227\260\352\262\260 \354\203\201\355\203\234", nullptr));
        BTN_DISPENSE_SYRUP_BY_TIME_1->setText(QCoreApplication::translate("DialogSyrup", "\354\213\234\353\237\2751", nullptr));
        label_112->setText(QCoreApplication::translate("DialogSyrup", "\354\266\234\354\210\230 \354\271\264\354\232\264\355\212\270", nullptr));
        label_113->setText(QCoreApplication::translate("DialogSyrup", "\354\265\234\354\242\205 \353\260\260\354\266\234\354\227\220\353\237\254", nullptr));
        label_114->setText(QCoreApplication::translate("DialogSyrup", "\355\230\204\354\236\254 \353\217\231\354\236\221\354\203\201\355\203\234", nullptr));
        label->setText(QCoreApplication::translate("DialogSyrup", "E1: \352\270\260\354\241\264 \353\260\260\354\266\234 \353\217\231\354\236\221\354\235\264 \353\201\235\353\202\230\354\247\200 \354\225\212\354\225\230\353\212\224\353\215\260 \353\252\205\353\240\271 \353\260\233\354\235\214", nullptr));
        label_2->setText(QCoreApplication::translate("DialogSyrup", "E2: \354\265\234\353\214\200 \354\266\234\354\210\230 \354\213\234\352\260\204 \354\264\210\352\263\274", nullptr));
        BTN_DISPENSE_SYRUP_BY_WEIGHT_1->setText(QCoreApplication::translate("DialogSyrup", "\354\213\234\353\237\2751", nullptr));
        label_22->setText(QCoreApplication::translate("DialogSyrup", "\354\264\210", nullptr));
        LE_SYRUP_OUT_TIME->setText(QCoreApplication::translate("DialogSyrup", "3", nullptr));
        label_116->setText(QCoreApplication::translate("DialogSyrup", "\353\241\234\353\223\234\354\205\200 \353\254\264\352\262\214", nullptr));
        label_117->setText(QCoreApplication::translate("DialogSyrup", "\353\241\234\353\223\234\354\205\200 scale", nullptr));
        label_118->setText(QCoreApplication::translate("DialogSyrup", "\353\241\234\353\223\234\354\205\200 \354\227\220\353\237\254", nullptr));
        label_119->setText(QCoreApplication::translate("DialogSyrup", "scale \354\204\244\354\240\225", nullptr));
        BTN_SET_SCALE->setText(QCoreApplication::translate("DialogSyrup", "\354\204\244\354\240\225", nullptr));
        BTN_TARE->setText(QCoreApplication::translate("DialogSyrup", "\354\230\201\354\240\220", nullptr));
        LE_SYRUP_OUT_WEIGHT->setText(QCoreApplication::translate("DialogSyrup", "20", nullptr));
        label_27->setText(QCoreApplication::translate("DialogSyrup", "g", nullptr));
        BTN_DISPENSE_SYRUP_BY_TIME_2->setText(QCoreApplication::translate("DialogSyrup", "\354\213\234\353\237\2752", nullptr));
        BTN_DISPENSE_SYRUP_BY_TIME_3->setText(QCoreApplication::translate("DialogSyrup", "\354\213\234\353\237\2753", nullptr));
        BTN_DISPENSE_SYRUP_BY_TIME_4->setText(QCoreApplication::translate("DialogSyrup", "\354\213\234\353\237\2754", nullptr));
        BTN_DISPENSE_SYRUP_BY_TIME_5->setText(QCoreApplication::translate("DialogSyrup", "\354\213\234\353\237\2755", nullptr));
        BTN_DISPENSE_SYRUP_BY_TIME_6->setText(QCoreApplication::translate("DialogSyrup", "\354\213\234\353\237\2756", nullptr));
        BTN_DISPENSE_SYRUP_BY_TIME_7->setText(QCoreApplication::translate("DialogSyrup", "\354\213\234\353\237\2757", nullptr));
        BTN_DISPENSE_SYRUP_BY_TIME_8->setText(QCoreApplication::translate("DialogSyrup", "\354\213\234\353\237\2758", nullptr));
        label_111->setText(QCoreApplication::translate("DialogSyrup", "\354\213\234\352\260\204 \353\260\260\354\266\234", nullptr));
        label_121->setText(QCoreApplication::translate("DialogSyrup", "\353\254\264\352\262\214 \353\260\260\354\266\234", nullptr));
        BTN_DISPENSE_SYRUP_BY_WEIGHT_2->setText(QCoreApplication::translate("DialogSyrup", "\354\213\234\353\237\2752", nullptr));
        BTN_DISPENSE_SYRUP_BY_WEIGHT_3->setText(QCoreApplication::translate("DialogSyrup", "\354\213\234\353\237\2753", nullptr));
        BTN_DISPENSE_SYRUP_BY_WEIGHT_4->setText(QCoreApplication::translate("DialogSyrup", "\354\213\234\353\237\2754", nullptr));
        BTN_DISPENSE_SYRUP_BY_WEIGHT_5->setText(QCoreApplication::translate("DialogSyrup", "\354\213\234\353\237\2755", nullptr));
        BTN_DISPENSE_SYRUP_BY_WEIGHT_6->setText(QCoreApplication::translate("DialogSyrup", "\354\213\234\353\237\2756", nullptr));
        BTN_DISPENSE_SYRUP_BY_WEIGHT_7->setText(QCoreApplication::translate("DialogSyrup", "\354\213\234\353\237\2757", nullptr));
        BTN_DISPENSE_SYRUP_BY_WEIGHT_8->setText(QCoreApplication::translate("DialogSyrup", "\354\213\234\353\237\2758", nullptr));
        CB_SCALE_TEST->setText(QCoreApplication::translate("DialogSyrup", "\355\205\214\354\212\244\355\212\270", nullptr));
        LE_SYRUP_OUT_TIME_2->setText(QCoreApplication::translate("DialogSyrup", "1", nullptr));
        label_23->setText(QCoreApplication::translate("DialogSyrup", "\354\264\210", nullptr));
        BTN_CLEANING->setText(QCoreApplication::translate("DialogSyrup", "\354\262\255\354\206\214\354\213\234\354\236\221", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DialogSyrup: public Ui_DialogSyrup {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGSYRUP_H
