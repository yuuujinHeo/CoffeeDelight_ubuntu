/********************************************************************************
** Form generated from reading UI file 'DialogSetting.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGSETTING_H
#define UI_DIALOGSETTING_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DialogSetting
{
public:
    QGroupBox *GB_SETTING;
    QTabWidget *tabWidget;
    QWidget *tab;
    QLabel *label_148;
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QLabel *label_152;
    QLabel *label_158;
    QPushButton *BTN_ERROR_CLEAR_PAPER_CUP_1;
    QLineEdit *LE_DEVICE_ERROR_ICECREAM;
    QLabel *label_150;
    QPushButton *BTN_ERROR_CLEAR_ICECREAM;
    QPushButton *BTN_ERROR_CLEAR_PET_CUP_1;
    QLabel *label_156;
    QLabel *label_155;
    QLineEdit *LE_DEVICE_ERROR_HOT_WATER;
    QLineEdit *LE_DEVICE_ERROR_ICE_1;
    QLabel *label_154;
    QLineEdit *LE_DEVICE_ERROR_PAPER_CUP_2;
    QLineEdit *LE_DEVICE_ERROR_PET_CUP_2;
    QPushButton *BTN_ERROR_CLEAR_ICE_1;
    QLineEdit *LE_DEVICE_ERROR_PET_CUP_1;
    QLineEdit *LE_DEVICE_ERROR_SODA;
    QLabel *label_149;
    QLabel *label_153;
    QPushButton *BTN_ERROR_CLEAR_HOT_WATER;
    QPushButton *BTN_ERROR_CLEAR_PAPER_CUP_2;
    QPushButton *BTN_ERROR_CLEAR_PET_CUP_2;
    QLineEdit *LE_DEVICE_ERROR_COFFEE;
    QPushButton *BTN_ERROR_CLEAR_SODA;
    QLineEdit *LE_DEVICE_ERROR_PAPER_CUP_1;
    QPushButton *BTN_ERROR_CLEAR_COFFEE;
    QLabel *label_157;
    QLabel *label_151;
    QLineEdit *LE_DEVICE_ERROR_ICE_2;
    QPushButton *BTN_ERROR_CLEAR_ICE_2;
    QGroupBox *GB_SUPER_STOP;
    QLabel *label_203;
    QLineEdit *LE_SUPER_STOP_BOARD_CONNECTION;
    QLabel *label_209;
    QLineEdit *LE_SUPER_STOP_ROBOT_DATA;
    QLabel *label_210;
    QLineEdit *LE_SUPER_STOP_ROBOT_MISS_COMMAND_CHECK;
    QLineEdit *LE_SUPER_STOP_OUTLET_CONNECTION;
    QLabel *label_211;
    QLabel *label_212;
    QLineEdit *LE_SUPER_STOP_OUTLET_CONTROL;
    QLabel *label_213;
    QLineEdit *LE_SUPER_STOP_OUTLET_SENSOR;
    QLabel *label_214;
    QLineEdit *LE_SUPER_STOP_PLATFORM_OPEN;
    QWidget *tab_2;
    QTableWidget *TW_TEST_MENU;
    QPushButton *BTN_TEST_ORDER;
    QPushButton *BTN_DB_RELOAD;
    QCheckBox *CB_ADD_SHOT;

    void setupUi(QDialog *DialogSetting)
    {
        if (DialogSetting->objectName().isEmpty())
            DialogSetting->setObjectName(QString::fromUtf8("DialogSetting"));
        DialogSetting->resize(402, 931);
        GB_SETTING = new QGroupBox(DialogSetting);
        GB_SETTING->setObjectName(QString::fromUtf8("GB_SETTING"));
        GB_SETTING->setGeometry(QRect(0, 0, 401, 971));
        QFont font;
        font.setFamily(QString::fromUtf8("\355\225\250\354\264\210\353\241\254\353\217\213\354\233\200"));
        font.setPointSize(20);
        font.setBold(false);
        font.setItalic(false);
        font.setWeight(50);
        GB_SETTING->setFont(font);
        GB_SETTING->setStyleSheet(QString::fromUtf8("QGroupBox  {\n"
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
        tabWidget = new QTabWidget(GB_SETTING);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(10, 60, 381, 821));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        label_148 = new QLabel(tab);
        label_148->setObjectName(QString::fromUtf8("label_148"));
        label_148->setGeometry(QRect(0, 0, 71, 21));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\355\225\250\354\264\210\353\241\254\353\217\213\354\233\200"));
        font1.setPointSize(10);
        font1.setBold(false);
        font1.setItalic(false);
        font1.setWeight(50);
        label_148->setFont(font1);
        label_148->setAlignment(Qt::AlignCenter);
        layoutWidget = new QWidget(tab);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(60, 40, 251, 306));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label_152 = new QLabel(layoutWidget);
        label_152->setObjectName(QString::fromUtf8("label_152"));
        label_152->setFont(font1);
        label_152->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_152, 4, 0, 1, 1);

        label_158 = new QLabel(layoutWidget);
        label_158->setObjectName(QString::fromUtf8("label_158"));
        label_158->setFont(font1);
        label_158->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_158, 9, 0, 1, 1);

        BTN_ERROR_CLEAR_PAPER_CUP_1 = new QPushButton(layoutWidget);
        BTN_ERROR_CLEAR_PAPER_CUP_1->setObjectName(QString::fromUtf8("BTN_ERROR_CLEAR_PAPER_CUP_1"));

        gridLayout->addWidget(BTN_ERROR_CLEAR_PAPER_CUP_1, 3, 2, 1, 1);

        LE_DEVICE_ERROR_ICECREAM = new QLineEdit(layoutWidget);
        LE_DEVICE_ERROR_ICECREAM->setObjectName(QString::fromUtf8("LE_DEVICE_ERROR_ICECREAM"));
        LE_DEVICE_ERROR_ICECREAM->setFont(font1);
        LE_DEVICE_ERROR_ICECREAM->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        LE_DEVICE_ERROR_ICECREAM->setReadOnly(true);

        gridLayout->addWidget(LE_DEVICE_ERROR_ICECREAM, 9, 1, 1, 1);

        label_150 = new QLabel(layoutWidget);
        label_150->setObjectName(QString::fromUtf8("label_150"));
        label_150->setFont(font1);
        label_150->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_150, 1, 0, 1, 1);

        BTN_ERROR_CLEAR_ICECREAM = new QPushButton(layoutWidget);
        BTN_ERROR_CLEAR_ICECREAM->setObjectName(QString::fromUtf8("BTN_ERROR_CLEAR_ICECREAM"));

        gridLayout->addWidget(BTN_ERROR_CLEAR_ICECREAM, 9, 2, 1, 1);

        BTN_ERROR_CLEAR_PET_CUP_1 = new QPushButton(layoutWidget);
        BTN_ERROR_CLEAR_PET_CUP_1->setObjectName(QString::fromUtf8("BTN_ERROR_CLEAR_PET_CUP_1"));

        gridLayout->addWidget(BTN_ERROR_CLEAR_PET_CUP_1, 5, 2, 1, 1);

        label_156 = new QLabel(layoutWidget);
        label_156->setObjectName(QString::fromUtf8("label_156"));
        label_156->setFont(font1);
        label_156->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_156, 7, 0, 1, 1);

        label_155 = new QLabel(layoutWidget);
        label_155->setObjectName(QString::fromUtf8("label_155"));
        label_155->setFont(font1);
        label_155->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_155, 6, 0, 1, 1);

        LE_DEVICE_ERROR_HOT_WATER = new QLineEdit(layoutWidget);
        LE_DEVICE_ERROR_HOT_WATER->setObjectName(QString::fromUtf8("LE_DEVICE_ERROR_HOT_WATER"));
        LE_DEVICE_ERROR_HOT_WATER->setFont(font1);
        LE_DEVICE_ERROR_HOT_WATER->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        LE_DEVICE_ERROR_HOT_WATER->setReadOnly(true);

        gridLayout->addWidget(LE_DEVICE_ERROR_HOT_WATER, 7, 1, 1, 1);

        LE_DEVICE_ERROR_ICE_1 = new QLineEdit(layoutWidget);
        LE_DEVICE_ERROR_ICE_1->setObjectName(QString::fromUtf8("LE_DEVICE_ERROR_ICE_1"));
        LE_DEVICE_ERROR_ICE_1->setFont(font1);
        LE_DEVICE_ERROR_ICE_1->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        LE_DEVICE_ERROR_ICE_1->setReadOnly(true);

        gridLayout->addWidget(LE_DEVICE_ERROR_ICE_1, 1, 1, 1, 1);

        label_154 = new QLabel(layoutWidget);
        label_154->setObjectName(QString::fromUtf8("label_154"));
        label_154->setFont(font1);
        label_154->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_154, 5, 0, 1, 1);

        LE_DEVICE_ERROR_PAPER_CUP_2 = new QLineEdit(layoutWidget);
        LE_DEVICE_ERROR_PAPER_CUP_2->setObjectName(QString::fromUtf8("LE_DEVICE_ERROR_PAPER_CUP_2"));
        LE_DEVICE_ERROR_PAPER_CUP_2->setFont(font1);
        LE_DEVICE_ERROR_PAPER_CUP_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        LE_DEVICE_ERROR_PAPER_CUP_2->setReadOnly(true);

        gridLayout->addWidget(LE_DEVICE_ERROR_PAPER_CUP_2, 4, 1, 1, 1);

        LE_DEVICE_ERROR_PET_CUP_2 = new QLineEdit(layoutWidget);
        LE_DEVICE_ERROR_PET_CUP_2->setObjectName(QString::fromUtf8("LE_DEVICE_ERROR_PET_CUP_2"));
        LE_DEVICE_ERROR_PET_CUP_2->setFont(font1);
        LE_DEVICE_ERROR_PET_CUP_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        LE_DEVICE_ERROR_PET_CUP_2->setReadOnly(true);

        gridLayout->addWidget(LE_DEVICE_ERROR_PET_CUP_2, 6, 1, 1, 1);

        BTN_ERROR_CLEAR_ICE_1 = new QPushButton(layoutWidget);
        BTN_ERROR_CLEAR_ICE_1->setObjectName(QString::fromUtf8("BTN_ERROR_CLEAR_ICE_1"));

        gridLayout->addWidget(BTN_ERROR_CLEAR_ICE_1, 1, 2, 1, 1);

        LE_DEVICE_ERROR_PET_CUP_1 = new QLineEdit(layoutWidget);
        LE_DEVICE_ERROR_PET_CUP_1->setObjectName(QString::fromUtf8("LE_DEVICE_ERROR_PET_CUP_1"));
        LE_DEVICE_ERROR_PET_CUP_1->setFont(font1);
        LE_DEVICE_ERROR_PET_CUP_1->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        LE_DEVICE_ERROR_PET_CUP_1->setReadOnly(true);

        gridLayout->addWidget(LE_DEVICE_ERROR_PET_CUP_1, 5, 1, 1, 1);

        LE_DEVICE_ERROR_SODA = new QLineEdit(layoutWidget);
        LE_DEVICE_ERROR_SODA->setObjectName(QString::fromUtf8("LE_DEVICE_ERROR_SODA"));
        LE_DEVICE_ERROR_SODA->setFont(font1);
        LE_DEVICE_ERROR_SODA->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        LE_DEVICE_ERROR_SODA->setReadOnly(true);

        gridLayout->addWidget(LE_DEVICE_ERROR_SODA, 8, 1, 1, 1);

        label_149 = new QLabel(layoutWidget);
        label_149->setObjectName(QString::fromUtf8("label_149"));
        label_149->setFont(font1);
        label_149->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_149, 0, 0, 1, 1);

        label_153 = new QLabel(layoutWidget);
        label_153->setObjectName(QString::fromUtf8("label_153"));
        label_153->setFont(font1);
        label_153->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_153, 3, 0, 1, 1);

        BTN_ERROR_CLEAR_HOT_WATER = new QPushButton(layoutWidget);
        BTN_ERROR_CLEAR_HOT_WATER->setObjectName(QString::fromUtf8("BTN_ERROR_CLEAR_HOT_WATER"));

        gridLayout->addWidget(BTN_ERROR_CLEAR_HOT_WATER, 7, 2, 1, 1);

        BTN_ERROR_CLEAR_PAPER_CUP_2 = new QPushButton(layoutWidget);
        BTN_ERROR_CLEAR_PAPER_CUP_2->setObjectName(QString::fromUtf8("BTN_ERROR_CLEAR_PAPER_CUP_2"));

        gridLayout->addWidget(BTN_ERROR_CLEAR_PAPER_CUP_2, 4, 2, 1, 1);

        BTN_ERROR_CLEAR_PET_CUP_2 = new QPushButton(layoutWidget);
        BTN_ERROR_CLEAR_PET_CUP_2->setObjectName(QString::fromUtf8("BTN_ERROR_CLEAR_PET_CUP_2"));

        gridLayout->addWidget(BTN_ERROR_CLEAR_PET_CUP_2, 6, 2, 1, 1);

        LE_DEVICE_ERROR_COFFEE = new QLineEdit(layoutWidget);
        LE_DEVICE_ERROR_COFFEE->setObjectName(QString::fromUtf8("LE_DEVICE_ERROR_COFFEE"));
        LE_DEVICE_ERROR_COFFEE->setFont(font1);
        LE_DEVICE_ERROR_COFFEE->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        LE_DEVICE_ERROR_COFFEE->setReadOnly(true);

        gridLayout->addWidget(LE_DEVICE_ERROR_COFFEE, 0, 1, 1, 1);

        BTN_ERROR_CLEAR_SODA = new QPushButton(layoutWidget);
        BTN_ERROR_CLEAR_SODA->setObjectName(QString::fromUtf8("BTN_ERROR_CLEAR_SODA"));

        gridLayout->addWidget(BTN_ERROR_CLEAR_SODA, 8, 2, 1, 1);

        LE_DEVICE_ERROR_PAPER_CUP_1 = new QLineEdit(layoutWidget);
        LE_DEVICE_ERROR_PAPER_CUP_1->setObjectName(QString::fromUtf8("LE_DEVICE_ERROR_PAPER_CUP_1"));
        LE_DEVICE_ERROR_PAPER_CUP_1->setFont(font1);
        LE_DEVICE_ERROR_PAPER_CUP_1->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        LE_DEVICE_ERROR_PAPER_CUP_1->setReadOnly(true);

        gridLayout->addWidget(LE_DEVICE_ERROR_PAPER_CUP_1, 3, 1, 1, 1);

        BTN_ERROR_CLEAR_COFFEE = new QPushButton(layoutWidget);
        BTN_ERROR_CLEAR_COFFEE->setObjectName(QString::fromUtf8("BTN_ERROR_CLEAR_COFFEE"));

        gridLayout->addWidget(BTN_ERROR_CLEAR_COFFEE, 0, 2, 1, 1);

        label_157 = new QLabel(layoutWidget);
        label_157->setObjectName(QString::fromUtf8("label_157"));
        label_157->setFont(font1);
        label_157->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_157, 8, 0, 1, 1);

        label_151 = new QLabel(layoutWidget);
        label_151->setObjectName(QString::fromUtf8("label_151"));
        label_151->setFont(font1);
        label_151->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_151, 2, 0, 1, 1);

        LE_DEVICE_ERROR_ICE_2 = new QLineEdit(layoutWidget);
        LE_DEVICE_ERROR_ICE_2->setObjectName(QString::fromUtf8("LE_DEVICE_ERROR_ICE_2"));
        LE_DEVICE_ERROR_ICE_2->setFont(font1);
        LE_DEVICE_ERROR_ICE_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        LE_DEVICE_ERROR_ICE_2->setReadOnly(true);

        gridLayout->addWidget(LE_DEVICE_ERROR_ICE_2, 2, 1, 1, 1);

        BTN_ERROR_CLEAR_ICE_2 = new QPushButton(layoutWidget);
        BTN_ERROR_CLEAR_ICE_2->setObjectName(QString::fromUtf8("BTN_ERROR_CLEAR_ICE_2"));

        gridLayout->addWidget(BTN_ERROR_CLEAR_ICE_2, 2, 2, 1, 1);

        GB_SUPER_STOP = new QGroupBox(tab);
        GB_SUPER_STOP->setObjectName(QString::fromUtf8("GB_SUPER_STOP"));
        GB_SUPER_STOP->setGeometry(QRect(10, 440, 361, 241));
        GB_SUPER_STOP->setStyleSheet(QString::fromUtf8("QGroupBox  {\n"
"    border: 1px solid gray;\n"
"    border-color: #FF5D1717;\n"
"    margin-top: 10px;\n"
"    font-size: 12px;\n"
"    border-radius: 1px;\n"
"}\n"
"\n"
"QGroupBox::title  {\n"
"    subcontrol-origin: margin;\n"
"    subcontrol-position: top center;\n"
"    padding: 5px 8000px 5px 8000px;\n"
"    background-color: #FF5D1717;\n"
"    color: rgb(255, 255, 255);\n"
"}"));
        label_203 = new QLabel(GB_SUPER_STOP);
        label_203->setObjectName(QString::fromUtf8("label_203"));
        label_203->setGeometry(QRect(40, 60, 251, 21));
        label_203->setFont(font1);
        LE_SUPER_STOP_BOARD_CONNECTION = new QLineEdit(GB_SUPER_STOP);
        LE_SUPER_STOP_BOARD_CONNECTION->setObjectName(QString::fromUtf8("LE_SUPER_STOP_BOARD_CONNECTION"));
        LE_SUPER_STOP_BOARD_CONNECTION->setGeometry(QRect(10, 60, 21, 21));
        LE_SUPER_STOP_BOARD_CONNECTION->setFont(font1);
        LE_SUPER_STOP_BOARD_CONNECTION->setReadOnly(true);
        label_209 = new QLabel(GB_SUPER_STOP);
        label_209->setObjectName(QString::fromUtf8("label_209"));
        label_209->setGeometry(QRect(40, 90, 251, 21));
        label_209->setFont(font1);
        LE_SUPER_STOP_ROBOT_DATA = new QLineEdit(GB_SUPER_STOP);
        LE_SUPER_STOP_ROBOT_DATA->setObjectName(QString::fromUtf8("LE_SUPER_STOP_ROBOT_DATA"));
        LE_SUPER_STOP_ROBOT_DATA->setGeometry(QRect(10, 90, 21, 21));
        LE_SUPER_STOP_ROBOT_DATA->setFont(font1);
        LE_SUPER_STOP_ROBOT_DATA->setReadOnly(true);
        label_210 = new QLabel(GB_SUPER_STOP);
        label_210->setObjectName(QString::fromUtf8("label_210"));
        label_210->setGeometry(QRect(40, 120, 251, 21));
        label_210->setFont(font1);
        LE_SUPER_STOP_ROBOT_MISS_COMMAND_CHECK = new QLineEdit(GB_SUPER_STOP);
        LE_SUPER_STOP_ROBOT_MISS_COMMAND_CHECK->setObjectName(QString::fromUtf8("LE_SUPER_STOP_ROBOT_MISS_COMMAND_CHECK"));
        LE_SUPER_STOP_ROBOT_MISS_COMMAND_CHECK->setGeometry(QRect(10, 120, 21, 21));
        LE_SUPER_STOP_ROBOT_MISS_COMMAND_CHECK->setFont(font1);
        LE_SUPER_STOP_ROBOT_MISS_COMMAND_CHECK->setReadOnly(true);
        LE_SUPER_STOP_OUTLET_CONNECTION = new QLineEdit(GB_SUPER_STOP);
        LE_SUPER_STOP_OUTLET_CONNECTION->setObjectName(QString::fromUtf8("LE_SUPER_STOP_OUTLET_CONNECTION"));
        LE_SUPER_STOP_OUTLET_CONNECTION->setGeometry(QRect(10, 150, 21, 21));
        LE_SUPER_STOP_OUTLET_CONNECTION->setFont(font1);
        LE_SUPER_STOP_OUTLET_CONNECTION->setReadOnly(true);
        label_211 = new QLabel(GB_SUPER_STOP);
        label_211->setObjectName(QString::fromUtf8("label_211"));
        label_211->setGeometry(QRect(40, 150, 251, 21));
        label_211->setFont(font1);
        label_212 = new QLabel(GB_SUPER_STOP);
        label_212->setObjectName(QString::fromUtf8("label_212"));
        label_212->setGeometry(QRect(40, 180, 251, 21));
        label_212->setFont(font1);
        LE_SUPER_STOP_OUTLET_CONTROL = new QLineEdit(GB_SUPER_STOP);
        LE_SUPER_STOP_OUTLET_CONTROL->setObjectName(QString::fromUtf8("LE_SUPER_STOP_OUTLET_CONTROL"));
        LE_SUPER_STOP_OUTLET_CONTROL->setGeometry(QRect(10, 180, 21, 21));
        LE_SUPER_STOP_OUTLET_CONTROL->setFont(font1);
        LE_SUPER_STOP_OUTLET_CONTROL->setReadOnly(true);
        label_213 = new QLabel(GB_SUPER_STOP);
        label_213->setObjectName(QString::fromUtf8("label_213"));
        label_213->setGeometry(QRect(40, 210, 251, 21));
        label_213->setFont(font1);
        LE_SUPER_STOP_OUTLET_SENSOR = new QLineEdit(GB_SUPER_STOP);
        LE_SUPER_STOP_OUTLET_SENSOR->setObjectName(QString::fromUtf8("LE_SUPER_STOP_OUTLET_SENSOR"));
        LE_SUPER_STOP_OUTLET_SENSOR->setGeometry(QRect(10, 210, 21, 21));
        LE_SUPER_STOP_OUTLET_SENSOR->setFont(font1);
        LE_SUPER_STOP_OUTLET_SENSOR->setReadOnly(true);
        label_214 = new QLabel(GB_SUPER_STOP);
        label_214->setObjectName(QString::fromUtf8("label_214"));
        label_214->setGeometry(QRect(40, 30, 251, 21));
        label_214->setFont(font1);
        LE_SUPER_STOP_PLATFORM_OPEN = new QLineEdit(GB_SUPER_STOP);
        LE_SUPER_STOP_PLATFORM_OPEN->setObjectName(QString::fromUtf8("LE_SUPER_STOP_PLATFORM_OPEN"));
        LE_SUPER_STOP_PLATFORM_OPEN->setGeometry(QRect(10, 30, 21, 21));
        LE_SUPER_STOP_PLATFORM_OPEN->setFont(font1);
        LE_SUPER_STOP_PLATFORM_OPEN->setReadOnly(true);
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        TW_TEST_MENU = new QTableWidget(tab_2);
        TW_TEST_MENU->setObjectName(QString::fromUtf8("TW_TEST_MENU"));
        TW_TEST_MENU->setGeometry(QRect(20, 10, 331, 371));
        TW_TEST_MENU->horizontalHeader()->setDefaultSectionSize(140);
        BTN_TEST_ORDER = new QPushButton(tab_2);
        BTN_TEST_ORDER->setObjectName(QString::fromUtf8("BTN_TEST_ORDER"));
        BTN_TEST_ORDER->setGeometry(QRect(150, 410, 89, 51));
        BTN_DB_RELOAD = new QPushButton(tab_2);
        BTN_DB_RELOAD->setObjectName(QString::fromUtf8("BTN_DB_RELOAD"));
        BTN_DB_RELOAD->setGeometry(QRect(20, 680, 89, 51));
        CB_ADD_SHOT = new QCheckBox(tab_2);
        CB_ADD_SHOT->setObjectName(QString::fromUtf8("CB_ADD_SHOT"));
        CB_ADD_SHOT->setGeometry(QRect(40, 420, 92, 23));
        tabWidget->addTab(tab_2, QString());

        retranslateUi(DialogSetting);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(DialogSetting);
    } // setupUi

    void retranslateUi(QDialog *DialogSetting)
    {
        DialogSetting->setWindowTitle(QCoreApplication::translate("DialogSetting", "Dialog", nullptr));
        GB_SETTING->setTitle(QCoreApplication::translate("DialogSetting", "\354\204\244\354\240\225", nullptr));
        label_148->setText(QCoreApplication::translate("DialogSetting", "\354\236\245\353\271\204 \354\227\220\353\237\254", nullptr));
        label_152->setText(QCoreApplication::translate("DialogSetting", "\354\242\205\354\235\264\354\273\2652", nullptr));
        label_158->setText(QCoreApplication::translate("DialogSetting", "\354\225\204\354\235\264\354\212\244\355\201\254\353\246\274", nullptr));
        BTN_ERROR_CLEAR_PAPER_CUP_1->setText(QCoreApplication::translate("DialogSetting", "\354\227\220\353\237\254 \355\201\264\353\246\254\354\226\264", nullptr));
        LE_DEVICE_ERROR_ICECREAM->setText(QString());
        label_150->setText(QCoreApplication::translate("DialogSetting", "\354\240\234\353\271\231\352\270\2601", nullptr));
        BTN_ERROR_CLEAR_ICECREAM->setText(QCoreApplication::translate("DialogSetting", "\354\227\220\353\237\254 \355\201\264\353\246\254\354\226\264", nullptr));
        BTN_ERROR_CLEAR_PET_CUP_1->setText(QCoreApplication::translate("DialogSetting", "\354\227\220\353\237\254 \355\201\264\353\246\254\354\226\264", nullptr));
        label_156->setText(QCoreApplication::translate("DialogSetting", "\354\230\250\354\210\230\352\270\260", nullptr));
        label_155->setText(QCoreApplication::translate("DialogSetting", "PET\354\273\2652", nullptr));
        LE_DEVICE_ERROR_HOT_WATER->setText(QString());
        LE_DEVICE_ERROR_ICE_1->setText(QString());
        label_154->setText(QCoreApplication::translate("DialogSetting", "PET\354\273\2651", nullptr));
        LE_DEVICE_ERROR_PAPER_CUP_2->setText(QString());
        LE_DEVICE_ERROR_PET_CUP_2->setText(QString());
        BTN_ERROR_CLEAR_ICE_1->setText(QCoreApplication::translate("DialogSetting", "\354\227\220\353\237\254 \355\201\264\353\246\254\354\226\264", nullptr));
        LE_DEVICE_ERROR_PET_CUP_1->setText(QString());
        LE_DEVICE_ERROR_SODA->setText(QString());
        label_149->setText(QCoreApplication::translate("DialogSetting", "\354\273\244\355\224\274\353\250\270\354\213\240", nullptr));
        label_153->setText(QCoreApplication::translate("DialogSetting", "\354\242\205\354\235\264\354\273\2651", nullptr));
        BTN_ERROR_CLEAR_HOT_WATER->setText(QCoreApplication::translate("DialogSetting", "\354\227\220\353\237\254 \355\201\264\353\246\254\354\226\264", nullptr));
        BTN_ERROR_CLEAR_PAPER_CUP_2->setText(QCoreApplication::translate("DialogSetting", "\354\227\220\353\237\254 \355\201\264\353\246\254\354\226\264", nullptr));
        BTN_ERROR_CLEAR_PET_CUP_2->setText(QCoreApplication::translate("DialogSetting", "\354\227\220\353\237\254 \355\201\264\353\246\254\354\226\264", nullptr));
        LE_DEVICE_ERROR_COFFEE->setText(QString());
        BTN_ERROR_CLEAR_SODA->setText(QCoreApplication::translate("DialogSetting", "\354\227\220\353\237\254 \355\201\264\353\246\254\354\226\264", nullptr));
        LE_DEVICE_ERROR_PAPER_CUP_1->setText(QString());
        BTN_ERROR_CLEAR_COFFEE->setText(QCoreApplication::translate("DialogSetting", "\354\227\220\353\237\254 \355\201\264\353\246\254\354\226\264", nullptr));
        label_157->setText(QCoreApplication::translate("DialogSetting", "\355\203\204\354\202\260\354\210\230", nullptr));
        label_151->setText(QCoreApplication::translate("DialogSetting", "\354\240\234\353\271\231\352\270\2602", nullptr));
        LE_DEVICE_ERROR_ICE_2->setText(QString());
        BTN_ERROR_CLEAR_ICE_2->setText(QCoreApplication::translate("DialogSetting", "\354\227\220\353\237\254 \355\201\264\353\246\254\354\226\264", nullptr));
        GB_SUPER_STOP->setTitle(QCoreApplication::translate("DialogSetting", "SUPER STOP", nullptr));
        label_203->setText(QCoreApplication::translate("DialogSetting", "Board Connection Error (LAN2CAN)", nullptr));
        label_209->setText(QCoreApplication::translate("DialogSetting", "Robot Data Error", nullptr));
        label_210->setText(QCoreApplication::translate("DialogSetting", "Robot Miss Command Check Error", nullptr));
        label_211->setText(QCoreApplication::translate("DialogSetting", "Outlet Connection Error", nullptr));
        label_212->setText(QCoreApplication::translate("DialogSetting", "Outlet Control Error", nullptr));
        label_213->setText(QCoreApplication::translate("DialogSetting", "Outlet Sensor Error", nullptr));
        label_214->setText(QCoreApplication::translate("DialogSetting", "Platform Open Error", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("DialogSetting", "\354\227\220\353\237\254", nullptr));
        BTN_TEST_ORDER->setText(QCoreApplication::translate("DialogSetting", "\355\205\214\354\212\244\355\212\270 \354\243\274\353\254\270", nullptr));
        BTN_DB_RELOAD->setText(QCoreApplication::translate("DialogSetting", "DB reload", nullptr));
        CB_ADD_SHOT->setText(QCoreApplication::translate("DialogSetting", "add Shot", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("DialogSetting", "\355\205\214\354\212\244\355\212\270", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DialogSetting: public Ui_DialogSetting {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGSETTING_H
