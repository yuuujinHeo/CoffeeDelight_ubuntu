/********************************************************************************
** Form generated from reading UI file 'DialogCoffee.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGCOFFEE_H
#define UI_DIALOGCOFFEE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DialogCoffee
{
public:
    QGroupBox *GB_COFFEE;
    QLineEdit *LE_COFFEE_CONNECTION;
    QLabel *label_110;
    QLabel *label_123;
    QPushButton *BTN_REQUEST_BUTTON_LIST;
    QPushButton *BTN_DRINK_OUT;
    QComboBox *CB_LIST;
    QLabel *label_163;
    QLineEdit *LE_MILK_WEIGHT;
    QPushButton *BTN_LC_GET_INITIAL;
    QWidget *layoutWidget_2;
    QVBoxLayout *verticalLayout_2;
    QGridLayout *gridLayout;
    QLineEdit *LE_MACHINE_STATUS_MAKING;
    QLineEdit *LE_MACHINE_STATUS_NOT_CONNECTED;
    QLabel *label_126;
    QLabel *label_127;
    QLabel *label_125;
    QLineEdit *LE_MACHINE_STATUS_ERROR_OCCURED;
    QLineEdit *LE_MACHINE_STATUS_PREPAREING;
    QLineEdit *LE_MACHINE_STATUS_ON_READY;
    QLabel *label_128;
    QLabel *label_124;
    QGridLayout *gridLayout_2;
    QLabel *label_129;
    QLabel *label_130;
    QLabel *label_131;
    QLineEdit *LE_MACHINE_STATUS_SYS_CLEANING;
    QLineEdit *LE_MACHINE_STATUS_MILK_CLEANING;
    QLineEdit *LE_MACHINE_STATUS_MILK_REPLACING;
    QWidget *layoutWidget_3;
    QGridLayout *gridLayout_3;
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
    QWidget *layoutWidget_4;
    QGridLayout *gridLayout_4;
    QLabel *label_133;
    QLineEdit *LE_LC_RAW_1;
    QLineEdit *LE_LC_RAW_2;
    QLineEdit *LE_LC_RAW_3;
    QLineEdit *LE_LC_RAW_4;
    QLabel *label_134;
    QLineEdit *LE_LC_SCALE_1;
    QLineEdit *LE_LC_SCALE_2;
    QLineEdit *LE_LC_SCALE_3;
    QLineEdit *LE_LC_SCALE_4;
    QLabel *label_162;
    QLineEdit *LE_LC_INITIAL_1;
    QLineEdit *LE_LC_INITIAL_2;
    QLineEdit *LE_LC_INITIAL_3;
    QLineEdit *LE_LC_INITIAL_4;
    QLabel *label_160;
    QLineEdit *LE_LC_WEIGHT_1;
    QLineEdit *LE_LC_WEIGHT_2;
    QLineEdit *LE_LC_WEIGHT_3;
    QLineEdit *LE_LC_WEIGHT_4;
    QLabel *label_132;
    QLineEdit *LE_LC_SET_SCALE_1;
    QLineEdit *LE_LC_SET_SCALE_2;
    QLineEdit *LE_LC_SET_SCALE_3;
    QLineEdit *LE_LC_SET_SCALE_4;
    QCheckBox *CB_MILK_LOCK;
    QPushButton *BTN_LC_SET_SCALE_1;
    QPushButton *BTN_LC_SET_SCALE_2;
    QPushButton *BTN_LC_SET_SCALE_3;
    QPushButton *BTN_LC_SET_SCALE_4;
    QLabel *label_161;
    QLineEdit *LE_LC_SET_INITIAL_1;
    QLineEdit *LE_LC_SET_INITIAL_2;
    QLineEdit *LE_LC_SET_INITIAL_3;
    QLineEdit *LE_LC_SET_INITIAL_4;
    QPushButton *BTN_LC_SET_INITIAL_1;
    QPushButton *BTN_LC_SET_INITIAL_2;
    QPushButton *BTN_LC_SET_INITIAL_3;
    QPushButton *BTN_LC_SET_INITIAL_4;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QRadioButton *RB_RINSE_ON;
    QRadioButton *RB_RINSE_OFF;
    QButtonGroup *buttonGroup;

    void setupUi(QDialog *DialogCoffee)
    {
        if (DialogCoffee->objectName().isEmpty())
            DialogCoffee->setObjectName(QString::fromUtf8("DialogCoffee"));
        DialogCoffee->resize(402, 931);
        GB_COFFEE = new QGroupBox(DialogCoffee);
        GB_COFFEE->setObjectName(QString::fromUtf8("GB_COFFEE"));
        GB_COFFEE->setGeometry(QRect(0, 0, 401, 971));
        QFont font;
        font.setFamily(QString::fromUtf8("\355\225\250\354\264\210\353\241\254\353\217\213\354\233\200"));
        font.setPointSize(20);
        font.setBold(false);
        font.setItalic(false);
        font.setWeight(50);
        GB_COFFEE->setFont(font);
        GB_COFFEE->setStyleSheet(QString::fromUtf8("QGroupBox  {\n"
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
        LE_COFFEE_CONNECTION = new QLineEdit(GB_COFFEE);
        LE_COFFEE_CONNECTION->setObjectName(QString::fromUtf8("LE_COFFEE_CONNECTION"));
        LE_COFFEE_CONNECTION->setGeometry(QRect(120, 70, 61, 21));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\355\225\250\354\264\210\353\241\254\353\217\213\354\233\200"));
        font1.setPointSize(10);
        font1.setBold(false);
        font1.setItalic(false);
        font1.setWeight(50);
        LE_COFFEE_CONNECTION->setFont(font1);
        LE_COFFEE_CONNECTION->setReadOnly(true);
        label_110 = new QLabel(GB_COFFEE);
        label_110->setObjectName(QString::fromUtf8("label_110"));
        label_110->setGeometry(QRect(20, 70, 91, 21));
        label_110->setFont(font1);
        label_110->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_123 = new QLabel(GB_COFFEE);
        label_123->setObjectName(QString::fromUtf8("label_123"));
        label_123->setGeometry(QRect(20, 160, 91, 21));
        label_123->setFont(font1);
        label_123->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        BTN_REQUEST_BUTTON_LIST = new QPushButton(GB_COFFEE);
        BTN_REQUEST_BUTTON_LIST->setObjectName(QString::fromUtf8("BTN_REQUEST_BUTTON_LIST"));
        BTN_REQUEST_BUTTON_LIST->setEnabled(false);
        BTN_REQUEST_BUTTON_LIST->setGeometry(QRect(200, 850, 121, 31));
        BTN_DRINK_OUT = new QPushButton(GB_COFFEE);
        BTN_DRINK_OUT->setObjectName(QString::fromUtf8("BTN_DRINK_OUT"));
        BTN_DRINK_OUT->setGeometry(QRect(170, 100, 89, 31));
        CB_LIST = new QComboBox(GB_COFFEE);
        CB_LIST->setObjectName(QString::fromUtf8("CB_LIST"));
        CB_LIST->setGeometry(QRect(20, 100, 141, 31));
        label_163 = new QLabel(GB_COFFEE);
        label_163->setObjectName(QString::fromUtf8("label_163"));
        label_163->setGeometry(QRect(30, 560, 81, 21));
        label_163->setFont(font1);
        label_163->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        LE_MILK_WEIGHT = new QLineEdit(GB_COFFEE);
        LE_MILK_WEIGHT->setObjectName(QString::fromUtf8("LE_MILK_WEIGHT"));
        LE_MILK_WEIGHT->setGeometry(QRect(120, 560, 61, 21));
        LE_MILK_WEIGHT->setFont(font1);
        LE_MILK_WEIGHT->setReadOnly(true);
        BTN_LC_GET_INITIAL = new QPushButton(GB_COFFEE);
        BTN_LC_GET_INITIAL->setObjectName(QString::fromUtf8("BTN_LC_GET_INITIAL"));
        BTN_LC_GET_INITIAL->setGeometry(QRect(110, 850, 61, 31));
        BTN_LC_GET_INITIAL->setFont(font1);
        layoutWidget_2 = new QWidget(GB_COFFEE);
        layoutWidget_2->setObjectName(QString::fromUtf8("layoutWidget_2"));
        layoutWidget_2->setGeometry(QRect(30, 190, 336, 104));
        verticalLayout_2 = new QVBoxLayout(layoutWidget_2);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        LE_MACHINE_STATUS_MAKING = new QLineEdit(layoutWidget_2);
        LE_MACHINE_STATUS_MAKING->setObjectName(QString::fromUtf8("LE_MACHINE_STATUS_MAKING"));
        LE_MACHINE_STATUS_MAKING->setMaximumSize(QSize(60, 16777215));
        LE_MACHINE_STATUS_MAKING->setFont(font1);
        LE_MACHINE_STATUS_MAKING->setReadOnly(true);

        gridLayout->addWidget(LE_MACHINE_STATUS_MAKING, 1, 5, 1, 1);

        LE_MACHINE_STATUS_NOT_CONNECTED = new QLineEdit(layoutWidget_2);
        LE_MACHINE_STATUS_NOT_CONNECTED->setObjectName(QString::fromUtf8("LE_MACHINE_STATUS_NOT_CONNECTED"));
        LE_MACHINE_STATUS_NOT_CONNECTED->setMaximumSize(QSize(60, 16777215));
        LE_MACHINE_STATUS_NOT_CONNECTED->setFont(font1);
        LE_MACHINE_STATUS_NOT_CONNECTED->setReadOnly(true);

        gridLayout->addWidget(LE_MACHINE_STATUS_NOT_CONNECTED, 1, 0, 1, 1);

        label_126 = new QLabel(layoutWidget_2);
        label_126->setObjectName(QString::fromUtf8("label_126"));
        label_126->setMaximumSize(QSize(60, 16777215));
        label_126->setFont(font1);
        label_126->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_126, 0, 4, 1, 1);

        label_127 = new QLabel(layoutWidget_2);
        label_127->setObjectName(QString::fromUtf8("label_127"));
        label_127->setMaximumSize(QSize(60, 16777215));
        label_127->setFont(font1);
        label_127->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_127, 0, 3, 1, 1);

        label_125 = new QLabel(layoutWidget_2);
        label_125->setObjectName(QString::fromUtf8("label_125"));
        label_125->setMaximumSize(QSize(60, 16777215));
        label_125->setFont(font1);
        label_125->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_125, 0, 1, 1, 2);

        LE_MACHINE_STATUS_ERROR_OCCURED = new QLineEdit(layoutWidget_2);
        LE_MACHINE_STATUS_ERROR_OCCURED->setObjectName(QString::fromUtf8("LE_MACHINE_STATUS_ERROR_OCCURED"));
        LE_MACHINE_STATUS_ERROR_OCCURED->setMaximumSize(QSize(60, 16777215));
        LE_MACHINE_STATUS_ERROR_OCCURED->setFont(font1);
        LE_MACHINE_STATUS_ERROR_OCCURED->setReadOnly(true);

        gridLayout->addWidget(LE_MACHINE_STATUS_ERROR_OCCURED, 1, 3, 1, 1);

        LE_MACHINE_STATUS_PREPAREING = new QLineEdit(layoutWidget_2);
        LE_MACHINE_STATUS_PREPAREING->setObjectName(QString::fromUtf8("LE_MACHINE_STATUS_PREPAREING"));
        LE_MACHINE_STATUS_PREPAREING->setMaximumSize(QSize(60, 16777215));
        LE_MACHINE_STATUS_PREPAREING->setFont(font1);
        LE_MACHINE_STATUS_PREPAREING->setReadOnly(true);

        gridLayout->addWidget(LE_MACHINE_STATUS_PREPAREING, 1, 1, 1, 2);

        LE_MACHINE_STATUS_ON_READY = new QLineEdit(layoutWidget_2);
        LE_MACHINE_STATUS_ON_READY->setObjectName(QString::fromUtf8("LE_MACHINE_STATUS_ON_READY"));
        LE_MACHINE_STATUS_ON_READY->setMaximumSize(QSize(60, 16777215));
        LE_MACHINE_STATUS_ON_READY->setFont(font1);
        LE_MACHINE_STATUS_ON_READY->setReadOnly(true);

        gridLayout->addWidget(LE_MACHINE_STATUS_ON_READY, 1, 4, 1, 1);

        label_128 = new QLabel(layoutWidget_2);
        label_128->setObjectName(QString::fromUtf8("label_128"));
        label_128->setMaximumSize(QSize(60, 16777215));
        label_128->setFont(font1);
        label_128->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_128, 0, 5, 1, 1);

        label_124 = new QLabel(layoutWidget_2);
        label_124->setObjectName(QString::fromUtf8("label_124"));
        label_124->setMaximumSize(QSize(60, 16777215));
        label_124->setFont(font1);
        label_124->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_124, 0, 0, 1, 1);


        verticalLayout_2->addLayout(gridLayout);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        label_129 = new QLabel(layoutWidget_2);
        label_129->setObjectName(QString::fromUtf8("label_129"));
        label_129->setMaximumSize(QSize(100, 16777215));
        label_129->setFont(font1);
        label_129->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label_129, 0, 0, 1, 1);

        label_130 = new QLabel(layoutWidget_2);
        label_130->setObjectName(QString::fromUtf8("label_130"));
        label_130->setMaximumSize(QSize(100, 16777215));
        label_130->setFont(font1);
        label_130->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label_130, 0, 1, 1, 1);

        label_131 = new QLabel(layoutWidget_2);
        label_131->setObjectName(QString::fromUtf8("label_131"));
        label_131->setMaximumSize(QSize(120, 16777215));
        label_131->setFont(font1);
        label_131->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label_131, 0, 2, 1, 1);

        LE_MACHINE_STATUS_SYS_CLEANING = new QLineEdit(layoutWidget_2);
        LE_MACHINE_STATUS_SYS_CLEANING->setObjectName(QString::fromUtf8("LE_MACHINE_STATUS_SYS_CLEANING"));
        LE_MACHINE_STATUS_SYS_CLEANING->setMaximumSize(QSize(100, 16777215));
        LE_MACHINE_STATUS_SYS_CLEANING->setFont(font1);
        LE_MACHINE_STATUS_SYS_CLEANING->setReadOnly(true);

        gridLayout_2->addWidget(LE_MACHINE_STATUS_SYS_CLEANING, 1, 0, 1, 1);

        LE_MACHINE_STATUS_MILK_CLEANING = new QLineEdit(layoutWidget_2);
        LE_MACHINE_STATUS_MILK_CLEANING->setObjectName(QString::fromUtf8("LE_MACHINE_STATUS_MILK_CLEANING"));
        LE_MACHINE_STATUS_MILK_CLEANING->setMaximumSize(QSize(100, 16777215));
        LE_MACHINE_STATUS_MILK_CLEANING->setFont(font1);
        LE_MACHINE_STATUS_MILK_CLEANING->setReadOnly(true);

        gridLayout_2->addWidget(LE_MACHINE_STATUS_MILK_CLEANING, 1, 1, 1, 1);

        LE_MACHINE_STATUS_MILK_REPLACING = new QLineEdit(layoutWidget_2);
        LE_MACHINE_STATUS_MILK_REPLACING->setObjectName(QString::fromUtf8("LE_MACHINE_STATUS_MILK_REPLACING"));
        LE_MACHINE_STATUS_MILK_REPLACING->setMaximumSize(QSize(120, 16777215));
        LE_MACHINE_STATUS_MILK_REPLACING->setFont(font1);
        LE_MACHINE_STATUS_MILK_REPLACING->setReadOnly(true);

        gridLayout_2->addWidget(LE_MACHINE_STATUS_MILK_REPLACING, 1, 2, 1, 1);


        verticalLayout_2->addLayout(gridLayout_2);

        layoutWidget_3 = new QWidget(GB_COFFEE);
        layoutWidget_3->setObjectName(QString::fromUtf8("layoutWidget_3"));
        layoutWidget_3->setGeometry(QRect(30, 320, 331, 83));
        gridLayout_3 = new QGridLayout(layoutWidget_3);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        label_111 = new QLabel(layoutWidget_3);
        label_111->setObjectName(QString::fromUtf8("label_111"));
        label_111->setFont(font1);
        label_111->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_3->addWidget(label_111, 0, 0, 1, 1);

        LE_SYS_CLEAN_TIME_HOUR = new QLineEdit(layoutWidget_3);
        LE_SYS_CLEAN_TIME_HOUR->setObjectName(QString::fromUtf8("LE_SYS_CLEAN_TIME_HOUR"));
        LE_SYS_CLEAN_TIME_HOUR->setMaximumSize(QSize(30, 16777215));
        LE_SYS_CLEAN_TIME_HOUR->setFont(font1);
        LE_SYS_CLEAN_TIME_HOUR->setReadOnly(true);

        gridLayout_3->addWidget(LE_SYS_CLEAN_TIME_HOUR, 0, 1, 1, 1);

        label_114 = new QLabel(layoutWidget_3);
        label_114->setObjectName(QString::fromUtf8("label_114"));
        label_114->setFont(font1);
        label_114->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(label_114, 0, 2, 1, 1);

        LE_SYS_CLEAN_TIME_MINUTE = new QLineEdit(layoutWidget_3);
        LE_SYS_CLEAN_TIME_MINUTE->setObjectName(QString::fromUtf8("LE_SYS_CLEAN_TIME_MINUTE"));
        LE_SYS_CLEAN_TIME_MINUTE->setMaximumSize(QSize(30, 16777215));
        LE_SYS_CLEAN_TIME_MINUTE->setFont(font1);
        LE_SYS_CLEAN_TIME_MINUTE->setReadOnly(true);

        gridLayout_3->addWidget(LE_SYS_CLEAN_TIME_MINUTE, 0, 3, 1, 1);

        label_115 = new QLabel(layoutWidget_3);
        label_115->setObjectName(QString::fromUtf8("label_115"));
        label_115->setFont(font1);
        label_115->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(label_115, 0, 4, 1, 1);

        LE_SYS_CLEAN_TIME_SECOND = new QLineEdit(layoutWidget_3);
        LE_SYS_CLEAN_TIME_SECOND->setObjectName(QString::fromUtf8("LE_SYS_CLEAN_TIME_SECOND"));
        LE_SYS_CLEAN_TIME_SECOND->setMaximumSize(QSize(30, 16777215));
        LE_SYS_CLEAN_TIME_SECOND->setFont(font1);
        LE_SYS_CLEAN_TIME_SECOND->setReadOnly(true);

        gridLayout_3->addWidget(LE_SYS_CLEAN_TIME_SECOND, 0, 5, 1, 1);

        label_116 = new QLabel(layoutWidget_3);
        label_116->setObjectName(QString::fromUtf8("label_116"));
        label_116->setFont(font1);
        label_116->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(label_116, 0, 6, 1, 1);

        label_112 = new QLabel(layoutWidget_3);
        label_112->setObjectName(QString::fromUtf8("label_112"));
        label_112->setFont(font1);
        label_112->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_3->addWidget(label_112, 1, 0, 1, 1);

        LE_MILK_CLEAN_TIME_HOUR = new QLineEdit(layoutWidget_3);
        LE_MILK_CLEAN_TIME_HOUR->setObjectName(QString::fromUtf8("LE_MILK_CLEAN_TIME_HOUR"));
        LE_MILK_CLEAN_TIME_HOUR->setMaximumSize(QSize(30, 16777215));
        LE_MILK_CLEAN_TIME_HOUR->setFont(font1);
        LE_MILK_CLEAN_TIME_HOUR->setReadOnly(true);

        gridLayout_3->addWidget(LE_MILK_CLEAN_TIME_HOUR, 1, 1, 1, 1);

        label_118 = new QLabel(layoutWidget_3);
        label_118->setObjectName(QString::fromUtf8("label_118"));
        label_118->setFont(font1);
        label_118->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(label_118, 1, 2, 1, 1);

        LE_MILK_CLEAN_TIME_MINUTE = new QLineEdit(layoutWidget_3);
        LE_MILK_CLEAN_TIME_MINUTE->setObjectName(QString::fromUtf8("LE_MILK_CLEAN_TIME_MINUTE"));
        LE_MILK_CLEAN_TIME_MINUTE->setMaximumSize(QSize(30, 16777215));
        LE_MILK_CLEAN_TIME_MINUTE->setFont(font1);
        LE_MILK_CLEAN_TIME_MINUTE->setReadOnly(true);

        gridLayout_3->addWidget(LE_MILK_CLEAN_TIME_MINUTE, 1, 3, 1, 1);

        label_119 = new QLabel(layoutWidget_3);
        label_119->setObjectName(QString::fromUtf8("label_119"));
        label_119->setFont(font1);
        label_119->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(label_119, 1, 4, 1, 1);

        LE_MILK_CLEAN_TIME_SECOND = new QLineEdit(layoutWidget_3);
        LE_MILK_CLEAN_TIME_SECOND->setObjectName(QString::fromUtf8("LE_MILK_CLEAN_TIME_SECOND"));
        LE_MILK_CLEAN_TIME_SECOND->setMaximumSize(QSize(30, 16777215));
        LE_MILK_CLEAN_TIME_SECOND->setFont(font1);
        LE_MILK_CLEAN_TIME_SECOND->setReadOnly(true);

        gridLayout_3->addWidget(LE_MILK_CLEAN_TIME_SECOND, 1, 5, 1, 1);

        label_117 = new QLabel(layoutWidget_3);
        label_117->setObjectName(QString::fromUtf8("label_117"));
        label_117->setFont(font1);
        label_117->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(label_117, 1, 6, 1, 1);

        label_113 = new QLabel(layoutWidget_3);
        label_113->setObjectName(QString::fromUtf8("label_113"));
        label_113->setFont(font1);
        label_113->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_3->addWidget(label_113, 2, 0, 1, 1);

        LE_MILK_REPLACE_TIME_HOUR = new QLineEdit(layoutWidget_3);
        LE_MILK_REPLACE_TIME_HOUR->setObjectName(QString::fromUtf8("LE_MILK_REPLACE_TIME_HOUR"));
        LE_MILK_REPLACE_TIME_HOUR->setMaximumSize(QSize(30, 16777215));
        LE_MILK_REPLACE_TIME_HOUR->setFont(font1);
        LE_MILK_REPLACE_TIME_HOUR->setReadOnly(true);

        gridLayout_3->addWidget(LE_MILK_REPLACE_TIME_HOUR, 2, 1, 1, 1);

        label_121 = new QLabel(layoutWidget_3);
        label_121->setObjectName(QString::fromUtf8("label_121"));
        label_121->setFont(font1);
        label_121->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(label_121, 2, 2, 1, 1);

        LE_MILK_REPLACE_TIME_MINUTE = new QLineEdit(layoutWidget_3);
        LE_MILK_REPLACE_TIME_MINUTE->setObjectName(QString::fromUtf8("LE_MILK_REPLACE_TIME_MINUTE"));
        LE_MILK_REPLACE_TIME_MINUTE->setMaximumSize(QSize(30, 16777215));
        LE_MILK_REPLACE_TIME_MINUTE->setFont(font1);
        LE_MILK_REPLACE_TIME_MINUTE->setReadOnly(true);

        gridLayout_3->addWidget(LE_MILK_REPLACE_TIME_MINUTE, 2, 3, 1, 1);

        label_122 = new QLabel(layoutWidget_3);
        label_122->setObjectName(QString::fromUtf8("label_122"));
        label_122->setFont(font1);
        label_122->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(label_122, 2, 4, 1, 1);

        LE_MILK_REPLACE_TIME_SECOND = new QLineEdit(layoutWidget_3);
        LE_MILK_REPLACE_TIME_SECOND->setObjectName(QString::fromUtf8("LE_MILK_REPLACE_TIME_SECOND"));
        LE_MILK_REPLACE_TIME_SECOND->setMaximumSize(QSize(30, 16777215));
        LE_MILK_REPLACE_TIME_SECOND->setFont(font1);
        LE_MILK_REPLACE_TIME_SECOND->setReadOnly(true);

        gridLayout_3->addWidget(LE_MILK_REPLACE_TIME_SECOND, 2, 5, 1, 1);

        label_120 = new QLabel(layoutWidget_3);
        label_120->setObjectName(QString::fromUtf8("label_120"));
        label_120->setFont(font1);
        label_120->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(label_120, 2, 6, 1, 1);

        layoutWidget_4 = new QWidget(GB_COFFEE);
        layoutWidget_4->setObjectName(QString::fromUtf8("layoutWidget_4"));
        layoutWidget_4->setGeometry(QRect(20, 600, 361, 232));
        gridLayout_4 = new QGridLayout(layoutWidget_4);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        gridLayout_4->setContentsMargins(0, 0, 0, 0);
        label_133 = new QLabel(layoutWidget_4);
        label_133->setObjectName(QString::fromUtf8("label_133"));
        label_133->setFont(font1);
        label_133->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_4->addWidget(label_133, 0, 0, 1, 1);

        LE_LC_RAW_1 = new QLineEdit(layoutWidget_4);
        LE_LC_RAW_1->setObjectName(QString::fromUtf8("LE_LC_RAW_1"));
        LE_LC_RAW_1->setMaximumSize(QSize(60, 16777215));
        LE_LC_RAW_1->setFont(font1);
        LE_LC_RAW_1->setReadOnly(true);

        gridLayout_4->addWidget(LE_LC_RAW_1, 0, 1, 1, 1);

        LE_LC_RAW_2 = new QLineEdit(layoutWidget_4);
        LE_LC_RAW_2->setObjectName(QString::fromUtf8("LE_LC_RAW_2"));
        LE_LC_RAW_2->setMaximumSize(QSize(60, 16777215));
        LE_LC_RAW_2->setFont(font1);
        LE_LC_RAW_2->setReadOnly(true);

        gridLayout_4->addWidget(LE_LC_RAW_2, 0, 2, 1, 1);

        LE_LC_RAW_3 = new QLineEdit(layoutWidget_4);
        LE_LC_RAW_3->setObjectName(QString::fromUtf8("LE_LC_RAW_3"));
        LE_LC_RAW_3->setMaximumSize(QSize(60, 16777215));
        LE_LC_RAW_3->setFont(font1);
        LE_LC_RAW_3->setReadOnly(true);

        gridLayout_4->addWidget(LE_LC_RAW_3, 0, 3, 1, 1);

        LE_LC_RAW_4 = new QLineEdit(layoutWidget_4);
        LE_LC_RAW_4->setObjectName(QString::fromUtf8("LE_LC_RAW_4"));
        LE_LC_RAW_4->setMaximumSize(QSize(60, 16777215));
        LE_LC_RAW_4->setFont(font1);
        LE_LC_RAW_4->setReadOnly(true);

        gridLayout_4->addWidget(LE_LC_RAW_4, 0, 4, 1, 1);

        label_134 = new QLabel(layoutWidget_4);
        label_134->setObjectName(QString::fromUtf8("label_134"));
        label_134->setFont(font1);
        label_134->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_4->addWidget(label_134, 1, 0, 1, 1);

        LE_LC_SCALE_1 = new QLineEdit(layoutWidget_4);
        LE_LC_SCALE_1->setObjectName(QString::fromUtf8("LE_LC_SCALE_1"));
        LE_LC_SCALE_1->setMaximumSize(QSize(60, 16777215));
        LE_LC_SCALE_1->setFont(font1);
        LE_LC_SCALE_1->setReadOnly(true);

        gridLayout_4->addWidget(LE_LC_SCALE_1, 1, 1, 1, 1);

        LE_LC_SCALE_2 = new QLineEdit(layoutWidget_4);
        LE_LC_SCALE_2->setObjectName(QString::fromUtf8("LE_LC_SCALE_2"));
        LE_LC_SCALE_2->setMaximumSize(QSize(60, 16777215));
        LE_LC_SCALE_2->setFont(font1);
        LE_LC_SCALE_2->setReadOnly(true);

        gridLayout_4->addWidget(LE_LC_SCALE_2, 1, 2, 1, 1);

        LE_LC_SCALE_3 = new QLineEdit(layoutWidget_4);
        LE_LC_SCALE_3->setObjectName(QString::fromUtf8("LE_LC_SCALE_3"));
        LE_LC_SCALE_3->setMaximumSize(QSize(60, 16777215));
        LE_LC_SCALE_3->setFont(font1);
        LE_LC_SCALE_3->setReadOnly(true);

        gridLayout_4->addWidget(LE_LC_SCALE_3, 1, 3, 1, 1);

        LE_LC_SCALE_4 = new QLineEdit(layoutWidget_4);
        LE_LC_SCALE_4->setObjectName(QString::fromUtf8("LE_LC_SCALE_4"));
        LE_LC_SCALE_4->setMaximumSize(QSize(60, 16777215));
        LE_LC_SCALE_4->setFont(font1);
        LE_LC_SCALE_4->setReadOnly(true);

        gridLayout_4->addWidget(LE_LC_SCALE_4, 1, 4, 1, 1);

        label_162 = new QLabel(layoutWidget_4);
        label_162->setObjectName(QString::fromUtf8("label_162"));
        label_162->setFont(font1);
        label_162->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_4->addWidget(label_162, 2, 0, 1, 1);

        LE_LC_INITIAL_1 = new QLineEdit(layoutWidget_4);
        LE_LC_INITIAL_1->setObjectName(QString::fromUtf8("LE_LC_INITIAL_1"));
        LE_LC_INITIAL_1->setMaximumSize(QSize(60, 16777215));
        LE_LC_INITIAL_1->setFont(font1);
        LE_LC_INITIAL_1->setReadOnly(true);

        gridLayout_4->addWidget(LE_LC_INITIAL_1, 2, 1, 1, 1);

        LE_LC_INITIAL_2 = new QLineEdit(layoutWidget_4);
        LE_LC_INITIAL_2->setObjectName(QString::fromUtf8("LE_LC_INITIAL_2"));
        LE_LC_INITIAL_2->setMaximumSize(QSize(60, 16777215));
        LE_LC_INITIAL_2->setFont(font1);
        LE_LC_INITIAL_2->setReadOnly(true);

        gridLayout_4->addWidget(LE_LC_INITIAL_2, 2, 2, 1, 1);

        LE_LC_INITIAL_3 = new QLineEdit(layoutWidget_4);
        LE_LC_INITIAL_3->setObjectName(QString::fromUtf8("LE_LC_INITIAL_3"));
        LE_LC_INITIAL_3->setMaximumSize(QSize(60, 16777215));
        LE_LC_INITIAL_3->setFont(font1);
        LE_LC_INITIAL_3->setReadOnly(true);

        gridLayout_4->addWidget(LE_LC_INITIAL_3, 2, 3, 1, 1);

        LE_LC_INITIAL_4 = new QLineEdit(layoutWidget_4);
        LE_LC_INITIAL_4->setObjectName(QString::fromUtf8("LE_LC_INITIAL_4"));
        LE_LC_INITIAL_4->setMaximumSize(QSize(60, 16777215));
        LE_LC_INITIAL_4->setFont(font1);
        LE_LC_INITIAL_4->setReadOnly(true);

        gridLayout_4->addWidget(LE_LC_INITIAL_4, 2, 4, 1, 1);

        label_160 = new QLabel(layoutWidget_4);
        label_160->setObjectName(QString::fromUtf8("label_160"));
        label_160->setFont(font1);
        label_160->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_4->addWidget(label_160, 3, 0, 1, 1);

        LE_LC_WEIGHT_1 = new QLineEdit(layoutWidget_4);
        LE_LC_WEIGHT_1->setObjectName(QString::fromUtf8("LE_LC_WEIGHT_1"));
        LE_LC_WEIGHT_1->setMaximumSize(QSize(60, 16777215));
        LE_LC_WEIGHT_1->setFont(font1);
        LE_LC_WEIGHT_1->setStyleSheet(QString::fromUtf8(""));
        LE_LC_WEIGHT_1->setReadOnly(true);

        gridLayout_4->addWidget(LE_LC_WEIGHT_1, 3, 1, 1, 1);

        LE_LC_WEIGHT_2 = new QLineEdit(layoutWidget_4);
        LE_LC_WEIGHT_2->setObjectName(QString::fromUtf8("LE_LC_WEIGHT_2"));
        LE_LC_WEIGHT_2->setMaximumSize(QSize(60, 16777215));
        LE_LC_WEIGHT_2->setFont(font1);
        LE_LC_WEIGHT_2->setStyleSheet(QString::fromUtf8(""));
        LE_LC_WEIGHT_2->setReadOnly(true);

        gridLayout_4->addWidget(LE_LC_WEIGHT_2, 3, 2, 1, 1);

        LE_LC_WEIGHT_3 = new QLineEdit(layoutWidget_4);
        LE_LC_WEIGHT_3->setObjectName(QString::fromUtf8("LE_LC_WEIGHT_3"));
        LE_LC_WEIGHT_3->setMaximumSize(QSize(60, 16777215));
        LE_LC_WEIGHT_3->setFont(font1);
        LE_LC_WEIGHT_3->setStyleSheet(QString::fromUtf8(""));
        LE_LC_WEIGHT_3->setReadOnly(true);

        gridLayout_4->addWidget(LE_LC_WEIGHT_3, 3, 3, 1, 1);

        LE_LC_WEIGHT_4 = new QLineEdit(layoutWidget_4);
        LE_LC_WEIGHT_4->setObjectName(QString::fromUtf8("LE_LC_WEIGHT_4"));
        LE_LC_WEIGHT_4->setMaximumSize(QSize(60, 16777215));
        LE_LC_WEIGHT_4->setFont(font1);
        LE_LC_WEIGHT_4->setStyleSheet(QString::fromUtf8(""));
        LE_LC_WEIGHT_4->setReadOnly(true);

        gridLayout_4->addWidget(LE_LC_WEIGHT_4, 3, 4, 1, 1);

        label_132 = new QLabel(layoutWidget_4);
        label_132->setObjectName(QString::fromUtf8("label_132"));
        label_132->setFont(font1);
        label_132->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_4->addWidget(label_132, 4, 0, 1, 1);

        LE_LC_SET_SCALE_1 = new QLineEdit(layoutWidget_4);
        LE_LC_SET_SCALE_1->setObjectName(QString::fromUtf8("LE_LC_SET_SCALE_1"));
        LE_LC_SET_SCALE_1->setMaximumSize(QSize(60, 16777215));
        LE_LC_SET_SCALE_1->setFont(font1);
        LE_LC_SET_SCALE_1->setReadOnly(false);

        gridLayout_4->addWidget(LE_LC_SET_SCALE_1, 4, 1, 1, 1);

        LE_LC_SET_SCALE_2 = new QLineEdit(layoutWidget_4);
        LE_LC_SET_SCALE_2->setObjectName(QString::fromUtf8("LE_LC_SET_SCALE_2"));
        LE_LC_SET_SCALE_2->setMaximumSize(QSize(60, 16777215));
        LE_LC_SET_SCALE_2->setFont(font1);
        LE_LC_SET_SCALE_2->setReadOnly(false);

        gridLayout_4->addWidget(LE_LC_SET_SCALE_2, 4, 2, 1, 1);

        LE_LC_SET_SCALE_3 = new QLineEdit(layoutWidget_4);
        LE_LC_SET_SCALE_3->setObjectName(QString::fromUtf8("LE_LC_SET_SCALE_3"));
        LE_LC_SET_SCALE_3->setMaximumSize(QSize(60, 16777215));
        LE_LC_SET_SCALE_3->setFont(font1);
        LE_LC_SET_SCALE_3->setReadOnly(false);

        gridLayout_4->addWidget(LE_LC_SET_SCALE_3, 4, 3, 1, 1);

        LE_LC_SET_SCALE_4 = new QLineEdit(layoutWidget_4);
        LE_LC_SET_SCALE_4->setObjectName(QString::fromUtf8("LE_LC_SET_SCALE_4"));
        LE_LC_SET_SCALE_4->setMaximumSize(QSize(60, 16777215));
        LE_LC_SET_SCALE_4->setFont(font1);
        LE_LC_SET_SCALE_4->setReadOnly(false);

        gridLayout_4->addWidget(LE_LC_SET_SCALE_4, 4, 4, 1, 1);

        CB_MILK_LOCK = new QCheckBox(layoutWidget_4);
        CB_MILK_LOCK->setObjectName(QString::fromUtf8("CB_MILK_LOCK"));
        CB_MILK_LOCK->setChecked(true);

        gridLayout_4->addWidget(CB_MILK_LOCK, 5, 0, 1, 1);

        BTN_LC_SET_SCALE_1 = new QPushButton(layoutWidget_4);
        BTN_LC_SET_SCALE_1->setObjectName(QString::fromUtf8("BTN_LC_SET_SCALE_1"));
        BTN_LC_SET_SCALE_1->setMaximumSize(QSize(60, 16777215));
        BTN_LC_SET_SCALE_1->setFont(font1);

        gridLayout_4->addWidget(BTN_LC_SET_SCALE_1, 5, 1, 1, 1);

        BTN_LC_SET_SCALE_2 = new QPushButton(layoutWidget_4);
        BTN_LC_SET_SCALE_2->setObjectName(QString::fromUtf8("BTN_LC_SET_SCALE_2"));
        BTN_LC_SET_SCALE_2->setMaximumSize(QSize(60, 16777215));
        BTN_LC_SET_SCALE_2->setFont(font1);

        gridLayout_4->addWidget(BTN_LC_SET_SCALE_2, 5, 2, 1, 1);

        BTN_LC_SET_SCALE_3 = new QPushButton(layoutWidget_4);
        BTN_LC_SET_SCALE_3->setObjectName(QString::fromUtf8("BTN_LC_SET_SCALE_3"));
        BTN_LC_SET_SCALE_3->setMaximumSize(QSize(60, 16777215));
        BTN_LC_SET_SCALE_3->setFont(font1);

        gridLayout_4->addWidget(BTN_LC_SET_SCALE_3, 5, 3, 1, 1);

        BTN_LC_SET_SCALE_4 = new QPushButton(layoutWidget_4);
        BTN_LC_SET_SCALE_4->setObjectName(QString::fromUtf8("BTN_LC_SET_SCALE_4"));
        BTN_LC_SET_SCALE_4->setMaximumSize(QSize(60, 16777215));
        BTN_LC_SET_SCALE_4->setFont(font1);

        gridLayout_4->addWidget(BTN_LC_SET_SCALE_4, 5, 4, 1, 1);

        label_161 = new QLabel(layoutWidget_4);
        label_161->setObjectName(QString::fromUtf8("label_161"));
        label_161->setFont(font1);
        label_161->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_4->addWidget(label_161, 6, 0, 1, 1);

        LE_LC_SET_INITIAL_1 = new QLineEdit(layoutWidget_4);
        LE_LC_SET_INITIAL_1->setObjectName(QString::fromUtf8("LE_LC_SET_INITIAL_1"));
        LE_LC_SET_INITIAL_1->setMaximumSize(QSize(60, 16777215));
        LE_LC_SET_INITIAL_1->setFont(font1);
        LE_LC_SET_INITIAL_1->setReadOnly(false);

        gridLayout_4->addWidget(LE_LC_SET_INITIAL_1, 6, 1, 1, 1);

        LE_LC_SET_INITIAL_2 = new QLineEdit(layoutWidget_4);
        LE_LC_SET_INITIAL_2->setObjectName(QString::fromUtf8("LE_LC_SET_INITIAL_2"));
        LE_LC_SET_INITIAL_2->setMaximumSize(QSize(60, 16777215));
        LE_LC_SET_INITIAL_2->setFont(font1);
        LE_LC_SET_INITIAL_2->setReadOnly(false);

        gridLayout_4->addWidget(LE_LC_SET_INITIAL_2, 6, 2, 1, 1);

        LE_LC_SET_INITIAL_3 = new QLineEdit(layoutWidget_4);
        LE_LC_SET_INITIAL_3->setObjectName(QString::fromUtf8("LE_LC_SET_INITIAL_3"));
        LE_LC_SET_INITIAL_3->setMaximumSize(QSize(60, 16777215));
        LE_LC_SET_INITIAL_3->setFont(font1);
        LE_LC_SET_INITIAL_3->setReadOnly(false);

        gridLayout_4->addWidget(LE_LC_SET_INITIAL_3, 6, 3, 1, 1);

        LE_LC_SET_INITIAL_4 = new QLineEdit(layoutWidget_4);
        LE_LC_SET_INITIAL_4->setObjectName(QString::fromUtf8("LE_LC_SET_INITIAL_4"));
        LE_LC_SET_INITIAL_4->setMaximumSize(QSize(60, 16777215));
        LE_LC_SET_INITIAL_4->setFont(font1);
        LE_LC_SET_INITIAL_4->setReadOnly(false);

        gridLayout_4->addWidget(LE_LC_SET_INITIAL_4, 6, 4, 1, 1);

        BTN_LC_SET_INITIAL_1 = new QPushButton(layoutWidget_4);
        BTN_LC_SET_INITIAL_1->setObjectName(QString::fromUtf8("BTN_LC_SET_INITIAL_1"));
        BTN_LC_SET_INITIAL_1->setMaximumSize(QSize(60, 16777215));
        BTN_LC_SET_INITIAL_1->setFont(font1);

        gridLayout_4->addWidget(BTN_LC_SET_INITIAL_1, 7, 1, 1, 1);

        BTN_LC_SET_INITIAL_2 = new QPushButton(layoutWidget_4);
        BTN_LC_SET_INITIAL_2->setObjectName(QString::fromUtf8("BTN_LC_SET_INITIAL_2"));
        BTN_LC_SET_INITIAL_2->setMaximumSize(QSize(60, 16777215));
        BTN_LC_SET_INITIAL_2->setFont(font1);

        gridLayout_4->addWidget(BTN_LC_SET_INITIAL_2, 7, 2, 1, 1);

        BTN_LC_SET_INITIAL_3 = new QPushButton(layoutWidget_4);
        BTN_LC_SET_INITIAL_3->setObjectName(QString::fromUtf8("BTN_LC_SET_INITIAL_3"));
        BTN_LC_SET_INITIAL_3->setMaximumSize(QSize(60, 16777215));
        BTN_LC_SET_INITIAL_3->setFont(font1);

        gridLayout_4->addWidget(BTN_LC_SET_INITIAL_3, 7, 3, 1, 1);

        BTN_LC_SET_INITIAL_4 = new QPushButton(layoutWidget_4);
        BTN_LC_SET_INITIAL_4->setObjectName(QString::fromUtf8("BTN_LC_SET_INITIAL_4"));
        BTN_LC_SET_INITIAL_4->setMaximumSize(QSize(60, 16777215));
        BTN_LC_SET_INITIAL_4->setFont(font1);

        gridLayout_4->addWidget(BTN_LC_SET_INITIAL_4, 7, 4, 1, 1);

        layoutWidget = new QWidget(GB_COFFEE);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(30, 420, 97, 54));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        RB_RINSE_ON = new QRadioButton(layoutWidget);
        buttonGroup = new QButtonGroup(DialogCoffee);
        buttonGroup->setObjectName(QString::fromUtf8("buttonGroup"));
        buttonGroup->addButton(RB_RINSE_ON);
        RB_RINSE_ON->setObjectName(QString::fromUtf8("RB_RINSE_ON"));
        RB_RINSE_ON->setChecked(false);

        verticalLayout->addWidget(RB_RINSE_ON);

        RB_RINSE_OFF = new QRadioButton(layoutWidget);
        buttonGroup->addButton(RB_RINSE_OFF);
        RB_RINSE_OFF->setObjectName(QString::fromUtf8("RB_RINSE_OFF"));
        RB_RINSE_OFF->setChecked(true);

        verticalLayout->addWidget(RB_RINSE_OFF);


        retranslateUi(DialogCoffee);

        QMetaObject::connectSlotsByName(DialogCoffee);
    } // setupUi

    void retranslateUi(QDialog *DialogCoffee)
    {
        DialogCoffee->setWindowTitle(QCoreApplication::translate("DialogCoffee", "Dialog", nullptr));
        GB_COFFEE->setTitle(QCoreApplication::translate("DialogCoffee", "\354\273\244\355\224\274 (WMF)", nullptr));
        label_110->setText(QCoreApplication::translate("DialogCoffee", "\354\236\245\354\271\230 \354\227\260\352\262\260 \354\203\201\355\203\234", nullptr));
        label_123->setText(QCoreApplication::translate("DialogCoffee", "\354\273\244\355\224\274 \353\250\270\354\213\240 \354\203\201\355\203\234", nullptr));
        BTN_REQUEST_BUTTON_LIST->setText(QCoreApplication::translate("DialogCoffee", "\353\262\204\355\212\274 \353\246\254\354\212\244\355\212\270 \354\232\224\354\262\255", nullptr));
        BTN_DRINK_OUT->setText(QCoreApplication::translate("DialogCoffee", "\355\210\254\354\266\234", nullptr));
        label_163->setText(QCoreApplication::translate("DialogCoffee", "\354\232\260\354\234\240 \353\254\264\352\262\214", nullptr));
        BTN_LC_GET_INITIAL->setText(QCoreApplication::translate("DialogCoffee", "\352\260\200\354\240\270\354\230\244\352\270\260", nullptr));
        label_126->setText(QCoreApplication::translate("DialogCoffee", "\354\244\200\353\271\204\354\231\204\353\243\214", nullptr));
        label_127->setText(QCoreApplication::translate("DialogCoffee", "\354\227\220\353\237\254\353\260\234\354\203\235", nullptr));
        label_125->setText(QCoreApplication::translate("DialogCoffee", "\354\244\200\353\271\204\354\244\221", nullptr));
        label_128->setText(QCoreApplication::translate("DialogCoffee", "\354\240\234\354\241\260\354\244\221", nullptr));
        label_124->setText(QCoreApplication::translate("DialogCoffee", "\354\227\260\352\262\260\354\225\210\353\220\250", nullptr));
        label_129->setText(QCoreApplication::translate("DialogCoffee", "\354\213\234\354\212\244\355\205\234\354\262\255\354\206\214\354\244\221", nullptr));
        label_130->setText(QCoreApplication::translate("DialogCoffee", "\354\232\260\354\234\240\354\262\255\354\206\214\354\244\221", nullptr));
        label_131->setText(QCoreApplication::translate("DialogCoffee", "\354\232\260\354\234\240\352\264\200\354\262\255\354\206\214\354\244\221", nullptr));
        label_111->setText(QCoreApplication::translate("DialogCoffee", "\354\213\234\354\212\244\355\205\234 \354\262\255\354\206\214 \353\202\250\354\235\200 \354\213\234\352\260\204", nullptr));
        label_114->setText(QCoreApplication::translate("DialogCoffee", "\354\213\234", nullptr));
        label_115->setText(QCoreApplication::translate("DialogCoffee", "\353\266\204", nullptr));
        label_116->setText(QCoreApplication::translate("DialogCoffee", "\354\264\210", nullptr));
        label_112->setText(QCoreApplication::translate("DialogCoffee", "\354\232\260\354\234\240 \354\262\255\354\206\214 \353\202\250\354\235\200 \354\213\234\352\260\204", nullptr));
        label_118->setText(QCoreApplication::translate("DialogCoffee", "\354\213\234", nullptr));
        label_119->setText(QCoreApplication::translate("DialogCoffee", "\353\266\204", nullptr));
        label_117->setText(QCoreApplication::translate("DialogCoffee", "\354\264\210", nullptr));
        label_113->setText(QCoreApplication::translate("DialogCoffee", "\354\232\260\354\234\240 \352\264\200 \354\262\255\354\206\214 \353\202\250\354\235\200 \354\213\234\352\260\204", nullptr));
        label_121->setText(QCoreApplication::translate("DialogCoffee", "\354\213\234", nullptr));
        label_122->setText(QCoreApplication::translate("DialogCoffee", "\353\266\204", nullptr));
        label_120->setText(QCoreApplication::translate("DialogCoffee", "\354\264\210", nullptr));
        label_133->setText(QCoreApplication::translate("DialogCoffee", "\353\241\234\353\223\234\354\205\200 raw", nullptr));
        label_134->setText(QCoreApplication::translate("DialogCoffee", "\353\241\234\353\223\234\354\205\200 scale", nullptr));
        label_162->setText(QCoreApplication::translate("DialogCoffee", "\353\241\234\353\223\234\354\205\200 initial", nullptr));
        label_160->setText(QCoreApplication::translate("DialogCoffee", "\353\241\234\353\223\234\354\205\200 \353\254\264\352\262\214", nullptr));
        label_132->setText(QCoreApplication::translate("DialogCoffee", "scale \354\204\244\354\240\225", nullptr));
        CB_MILK_LOCK->setText(QCoreApplication::translate("DialogCoffee", "LOCK", nullptr));
        BTN_LC_SET_SCALE_1->setText(QCoreApplication::translate("DialogCoffee", "\354\204\244\354\240\225", nullptr));
        BTN_LC_SET_SCALE_2->setText(QCoreApplication::translate("DialogCoffee", "\354\204\244\354\240\225", nullptr));
        BTN_LC_SET_SCALE_3->setText(QCoreApplication::translate("DialogCoffee", "\354\204\244\354\240\225", nullptr));
        BTN_LC_SET_SCALE_4->setText(QCoreApplication::translate("DialogCoffee", "\354\204\244\354\240\225", nullptr));
        label_161->setText(QCoreApplication::translate("DialogCoffee", "initial \354\204\244\354\240\225", nullptr));
        BTN_LC_SET_INITIAL_1->setText(QCoreApplication::translate("DialogCoffee", "\354\204\244\354\240\225", nullptr));
        BTN_LC_SET_INITIAL_2->setText(QCoreApplication::translate("DialogCoffee", "\354\204\244\354\240\225", nullptr));
        BTN_LC_SET_INITIAL_3->setText(QCoreApplication::translate("DialogCoffee", "\354\204\244\354\240\225", nullptr));
        BTN_LC_SET_INITIAL_4->setText(QCoreApplication::translate("DialogCoffee", "\354\204\244\354\240\225", nullptr));
        RB_RINSE_ON->setText(QCoreApplication::translate("DialogCoffee", "rinsing on", nullptr));
        RB_RINSE_OFF->setText(QCoreApplication::translate("DialogCoffee", "rinsing off", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DialogCoffee: public Ui_DialogCoffee {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGCOFFEE_H
