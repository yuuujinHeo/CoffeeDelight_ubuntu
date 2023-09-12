#include "displaydialog.h"
#include "ui_displaydialog.h"
#include <QTimer>
#include "GlobalHeader.h"
#include "mainwindow.h"
#include <QFontDatabase>

extern Scheduler *pschedule;
DisplayDialog::DisplayDialog(QWidget *parent, DialogStock *_stock) :
    QDialog(parent), stock(_stock),
    ui(new Ui::DisplayDialog)
{
    ui->setupUi(this);
    this->setWindowState(Qt::WindowFullScreen);
    timer = new QTimer();

    connect(timer, SIGNAL(timeout()),this,SLOT(updateDisplay()));
    timer->start(500);

    use_ad = false;
    display_mode = DISPLAY_MODE_IDLE;
    forced_display_mode = DISPLAY_MODE_IDLE;
    count_ad = 0;
    notice = "";
    notice_count = 0;

    call_num = "문의처 063-561-6323";
    wait_time = 0;
    //TEST
//    use_ad = true;
//    display_mode = DISPLAY_MODE_IN_OPERATION;

    settingUI();
}

DisplayDialog::~DisplayDialog()
{
    delete ui;
}

void DisplayDialog::Enalble_AD(){
    use_ad = true;
}

void DisplayDialog::Disable_AD(){
    use_ad = false;
}

void DisplayDialog::Set_Mode(int _mode){
    display_mode = _mode;
}
void DisplayDialog::Set_ForcedMode(int _mode){
    forced_display_mode = _mode;
}
void DisplayDialog::Set_Notice(QString _notice, int _count){
    if(notice == _notice){
        notice = _notice;
    }else{
        notice = _notice;
        notice_count = _count;
    }
}

void DisplayDialog::settingUI(){
    waiting[0].pin = ui->LB_WAIT_PIN;
    waiting[1].pin = ui->LB_WAIT_PIN_2;
    waiting[2].pin = ui->LB_WAIT_PIN_3;
    waiting[3].pin = ui->LB_WAIT_PIN_4;
    waiting[4].pin = ui->LB_WAIT_PIN_5;
    waiting[5].pin = ui->LB_WAIT_PIN_6;
    waiting[6].pin = ui->LB_WAIT_PIN_7;

    waiting[0].menu = ui->LE_WAIT_NAME;
    waiting[1].menu = ui->LE_WAIT_NAME_2;
    waiting[2].menu = ui->LE_WAIT_NAME_3;
    waiting[3].menu = ui->LE_WAIT_NAME_4;
    waiting[4].menu = ui->LE_WAIT_NAME_5;
    waiting[5].menu = ui->LE_WAIT_NAME_6;
    waiting[6].menu = ui->LE_WAIT_NAME_7;

    waiting[0].status = ui->LE_WAIT_STATUS;
    waiting[1].status = ui->LE_WAIT_STATUS_2;
    waiting[2].status = ui->LE_WAIT_STATUS_3;
    waiting[3].status = ui->LE_WAIT_STATUS_4;
    waiting[4].status = ui->LE_WAIT_STATUS_5;
    waiting[5].status = ui->LE_WAIT_STATUS_6;
    waiting[6].status = ui->LE_WAIT_STATUS_7;

    outlet[0][0].pin = ui->LE_OUTLET_PIN_1_1;
    outlet[0][1].pin = ui->LE_OUTLET_PIN_1_2;
    outlet[0][2].pin = ui->LE_OUTLET_PIN_1_3;
    outlet[1][0].pin = ui->LE_OUTLET_PIN_2_1;
    outlet[1][1].pin = ui->LE_OUTLET_PIN_2_2;
    outlet[1][2].pin = ui->LE_OUTLET_PIN_2_3;



    outlet[0][0].menu = ui->LE_OUTLET_MENU_1_1;
    outlet[0][1].menu = ui->LE_OUTLET_MENU_1_2;
    outlet[0][2].menu = ui->LE_OUTLET_MENU_1_3;
    outlet[1][0].menu = ui->LE_OUTLET_MENU_2_1;
    outlet[1][1].menu = ui->LE_OUTLET_MENU_2_2;
    outlet[1][2].menu = ui->LE_OUTLET_MENU_2_3;

    outlet[0][0].status = ui->LE_OUTLET_STATUS_1_1;
    outlet[0][1].status = ui->LE_OUTLET_STATUS_1_2;
    outlet[0][2].status = ui->LE_OUTLET_STATUS_1_3;
    outlet[1][0].status = ui->LE_OUTLET_STATUS_2_1;
    outlet[1][1].status = ui->LE_OUTLET_STATUS_2_2;
    outlet[1][2].status = ui->LE_OUTLET_STATUS_2_3;

    ui->FR_NOTICE->setVisible(false);

    qDebug() << QApplication::applicationDirPath();
    int font1 = QFontDatabase::addApplicationFont(QApplication::applicationDirPath()+"/font/lotteDreamBold.ttf");
    QString family1 = QFontDatabase::applicationFontFamilies(font1).at(0);

    QFont font_pin(family1);
    font_pin.setPointSize(35);

    QFont font_menu(family1);
    font_menu.setPointSize(28);

    QFont font_pin2(family1);
    font_pin2.setPointSize(35);

    QFont font_menu2(family1);
    font_menu2.setPointSize(25);

    for(int i=0; i<7; i++){
        waiting[i].pin->setFont(font_pin);
        waiting[i].menu->setFont(font_menu);
        waiting[i].pin->setText("");
        waiting[i].menu->setText("");
        waiting[i].status->setText("");
        waiting[i].status->setPixmap(QPixmap(""));
    }

    for(int i=0; i<2; i++){
        for(int j=0; j<3; j++){
            outlet[i][j].pin->setFont(font_pin2);
            outlet[i][j].menu->setFont(font_menu2);

            outlet[i][j].pin->setText("");
            outlet[i][j].menu->setText("");
            outlet[i][j].status->setVisible(false);
            outlet[i][j].status_flag = 0;
        }
    }

    wait_time = stock->ApproximateWaitingTime/60;
    ui->LE_CALL->setText(call_num);
    ui->LE_TIME->setText(QString().sprintf("%d",wait_time));
    ui->label->setPixmap(QPixmap(":/build/image/background.png"));
    ui->BACKGROUND_READY->setPixmap(QPixmap(":/build/image/background_prepare.png"));
    ui->LE_OUTLET_STATUS_1_1->setPixmap(QPixmap(":/build/image/outlet.png"));
    ui->LE_OUTLET_STATUS_1_2->setPixmap(QPixmap(":/build/image/outlet.png"));
    ui->LE_OUTLET_STATUS_1_3->setPixmap(QPixmap(":/build/image/outlet.png"));
    ui->LE_OUTLET_STATUS_2_1->setPixmap(QPixmap(":/build/image/outlet.png"));
    ui->LE_OUTLET_STATUS_2_2->setPixmap(QPixmap(":/build/image/outlet.png"));
    ui->LE_OUTLET_STATUS_2_3->setPixmap(QPixmap(":/build/image/outlet.png"));

}
void DisplayDialog::updateDisplay(){
    //Clear UI
    for(int i=0; i<7; i++){
        waiting[i].pin->setText("");
        waiting[i].menu->setText("");
        waiting[i].status->setText("");
        waiting[i].status->setPixmap(QPixmap(""));
        waiting[i].status->setVisible(false);
    }

    for(int i=0; i<2; i++){
        for(int j=0; j<3; j++){
            outlet[i][j].pin->setText("");
            outlet[i][j].menu->setText("");
            outlet[i][j].status->setVisible(false);
            outlet[i][j].status_flag = 0;
        }
    }

    static int n_cnt = 0;
    if(notice != ""){
        if(notice_count == 0){
            notice = "";
        }else{
            if(n_cnt == 0){
                ui->LB_NOTICE->setText(notice);
                ui->FR_NOTICE->setVisible(true);
                n_cnt++;
            }else if(n_cnt == 2){
                ui->LB_NOTICE->setText(notice);
                ui->FR_NOTICE->setVisible(false);
                notice_count--;
                n_cnt = 0;
//                n_cnt++;
            }else if(n_cnt == 3){
                notice_count--;
                n_cnt = 0;
            }else{
                n_cnt++;
            }
        }
    }else{
        notice_count = 0;
        ui->LB_NOTICE->setText("");
        ui->FR_NOTICE->setVisible(false);

    }
    //Read Waiting List
    if(forced_display_mode == DISPLAY_MODE_IN_READY){
        ui->BACKGROUND_READY->setVisible(true);
    }else if(forced_display_mode == DISPLAY_MODE_IN_OPERATION){
        ui->BACKGROUND_READY->setVisible(false);
        int index = 0;
        for(int i=0; i<pschedule->list_inprogress.size(); i++){
            waiting[index].pin->setText(pschedule->list_inprogress[i].pin);
            waiting[index].menu->setText(pschedule->list_inprogress[i].menu_name);
            waiting[index].status->setVisible(true);
            waiting[index].status->setPixmap(QPixmap(":/build/image/making.png"));
            index++;
        }
        for(int i=0; i<pschedule->list_waiting.size(); i++){
            if(index > 6)
                break;
            waiting[index].pin->setText(pschedule->list_waiting[i].pin);
            waiting[index].menu->setText(pschedule->list_waiting[i].menu_name);
            waiting[index].status->setVisible(true);
            waiting[index].status->setPixmap(QPixmap(":/build/image/waiting.png"));
            index++;

        }

        //Read Completed List
        for(int i=0; i<pschedule->list_completed.size(); i++){
            outlet[pschedule->list_completed[i].id_module][pschedule->list_completed[i].id_cell].pin->setText(pschedule->list_completed[i].pin);
            outlet[pschedule->list_completed[i].id_module][pschedule->list_completed[i].id_cell].menu->setText(pschedule->list_completed[i].menu_name);
        }


        for(int i=0; i<2; i++){
            if(pschedule->list_dispensing[i].pin != ""){
                outlet[pschedule->list_dispensing[i].id_module][pschedule->list_dispensing[i].id_cell].pin->setText(pschedule->list_dispensing[i].pin);
                outlet[pschedule->list_dispensing[i].id_module][pschedule->list_dispensing[i].id_cell].menu->setText(pschedule->list_dispensing[i].menu_name);
                outlet[pschedule->list_dispensing[i].id_module][pschedule->list_dispensing[i].id_cell].status_flag = 1;
            }
        }

        //Change UI state
        static int count_dispense = 0;
        count_dispense++;
        for(int j=0; j<3; j++){
            if(count_dispense > 2){
                count_dispense = 0;
                if(outlet[0][j].status_flag == 1){
                    if(outlet[0][j].status->isVisible()==true)
                        outlet[0][j].status->setVisible(false);
                    else
                        outlet[0][j].status->setVisible(true);
                }
                if(outlet[1][j].status_flag == 1){
                    if(outlet[1][j].status->isVisible()==true)
                        outlet[1][j].status->setVisible(false);
                    else
                        outlet[1][j].status->setVisible(true);
                }
            }

        }
    }else if(display_mode == DISPLAY_MODE_IN_READY){
        ui->BACKGROUND_READY->setVisible(true);
    }else{
        ui->BACKGROUND_READY->setVisible(false);
        int index = 0;
        for(int i=0; i<pschedule->list_inprogress.size(); i++){
            waiting[index].pin->setText(pschedule->list_inprogress[i].pin);
            waiting[index].menu->setText(pschedule->list_inprogress[i].menu_name);
            waiting[index].status->setVisible(true);
            waiting[index].status->setPixmap(QPixmap(":/build/image/making.png"));
            index++;
        }
        for(int i=0; i<pschedule->list_waiting.size(); i++){
            if(index > 6)
                break;
            waiting[index].pin->setText(pschedule->list_waiting[i].pin);
            waiting[index].menu->setText(pschedule->list_waiting[i].menu_name);
            waiting[index].status->setVisible(true);
            waiting[index].status->setPixmap(QPixmap(":/build/image/waiting.png"));
            index++;

        }

        //Read Completed List
        for(int i=0; i<pschedule->list_completed.size(); i++){
            outlet[pschedule->list_completed[i].id_module][pschedule->list_completed[i].id_cell].pin->setText(pschedule->list_completed[i].pin);
            outlet[pschedule->list_completed[i].id_module][pschedule->list_completed[i].id_cell].menu->setText(pschedule->list_completed[i].menu_name);
        }

        for(int i=0; i<2; i++){
            if(pschedule->list_dispensing[i].pin != ""){
                outlet[pschedule->list_dispensing[i].id_module][pschedule->list_dispensing[i].id_cell].pin->setText(pschedule->list_dispensing[i].pin);
                outlet[pschedule->list_dispensing[i].id_module][pschedule->list_dispensing[i].id_cell].menu->setText(pschedule->list_dispensing[i].menu_name);
                outlet[pschedule->list_dispensing[i].id_module][pschedule->list_dispensing[i].id_cell].status_flag = 1;
            }
        }

        //Change UI state
        static int count_dispense = 0;
        count_dispense++;
        for(int j=0; j<3; j++){
            if(count_dispense > 2){
                count_dispense = 0;
                if(outlet[0][j].status_flag == 1){
                    if(outlet[0][j].status->isVisible()==true)
                        outlet[0][j].status->setVisible(false);
                    else
                        outlet[0][j].status->setVisible(true);
                }
                if(outlet[1][j].status_flag == 1){
                    if(outlet[1][j].status->isVisible()==true)
                        outlet[1][j].status->setVisible(false);
                    else
                        outlet[1][j].status->setVisible(true);
                }
            }

        }
    }



    //AD
    if(use_ad == true && display_mode == DISPLAY_MODE_IN_OPERATION){
        if(pschedule->list_waiting.size() == 0 && pschedule->list_inprogress.size() == 0 && pschedule->list_completed.size() == 0 && pschedule->list_dispensing[0].pin == "" && pschedule->list_dispensing[1].pin == ""){
            if(count_ad==0){
                ui->BACKGROUND_1->setVisible(false);
                ui->BACKGROUND_2->setVisible(false);
                ui->BACKGROUND_3->setVisible(false);
            }else if(count_ad == 40){
                ui->BACKGROUND_1->setVisible(true);
                ui->BACKGROUND_1->raise();
                ui->BACKGROUND_1->raise();
                QPropertyAnimation *animation = new QPropertyAnimation(ui->BACKGROUND_1,"geometry");
                animation->setDuration(1000);
                animation->setStartValue(QRect(1920,0,ui->BACKGROUND_1->geometry().width(),ui->BACKGROUND_1->geometry().height()));
                animation->setEndValue(QRect(0,0,ui->BACKGROUND_1->geometry().width(),ui->BACKGROUND_1->geometry().height()));
                animation->setEasingCurve(QEasingCurve::InCubic);
                animation->start();
            }else if(count_ad == 80){
                ui->BACKGROUND_2->setVisible(true);
                ui->BACKGROUND_2->raise();
                ui->BACKGROUND_2->raise();
                QPropertyAnimation *animation = new QPropertyAnimation(ui->BACKGROUND_2,"geometry");
                animation->setDuration(1000);
                animation->setStartValue(QRect(0,-1080,ui->BACKGROUND_2->geometry().width(),ui->BACKGROUND_2->geometry().height()));
                animation->setEndValue(QRect(0,0,ui->BACKGROUND_2->geometry().width(),ui->BACKGROUND_2->geometry().height()));
                animation->setEasingCurve(QEasingCurve::OutBounce);
                animation->start();
            }else if(count_ad == 120){
                ui->BACKGROUND_3->setVisible(true);
                ui->BACKGROUND_3->raise();
                ui->BACKGROUND_3->raise();
                QPropertyAnimation *animation = new QPropertyAnimation(ui->BACKGROUND_3,"geometry");
                animation->setDuration(1000);
                animation->setStartValue(QRect(0,1080,ui->BACKGROUND_3->geometry().width(),ui->BACKGROUND_3->geometry().height()));
                animation->setEndValue(QRect(0,0,ui->BACKGROUND_3->geometry().width(),ui->BACKGROUND_3->geometry().height()));
                animation->setEasingCurve(QEasingCurve::InOutCirc);
                animation->start();
            }else if(count_ad > 160){
                count_ad = 39;
            }

            count_ad++;
        }else{
            count_ad = 0;
            ui->BACKGROUND_1->setVisible(false);
            ui->BACKGROUND_2->setVisible(false);
            ui->BACKGROUND_3->setVisible(false);
        }
    }else{
        count_ad = 0;
        ui->BACKGROUND_1->setVisible(false);
        ui->BACKGROUND_2->setVisible(false);
        ui->BACKGROUND_3->setVisible(false);
    }
}
