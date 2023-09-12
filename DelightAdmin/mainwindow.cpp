#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QApplication>
#include <QDesktopWidget>

RBLAN2CAN *plan;


int IS_UI_LOCK = true;

int LOADCELL_SCALE_HOT_1 = 300;
int LOADCELL_SCALE_HOT_2 = 300;
int LOADCELL_SCALE_SYRUP = 300;
int LOADCELL_SCALE_SODA = 300;
int LOADCELL_SCALE_ICECREAM_1 = 300;
int LOADCELL_SCALE_ICECREAM_2 = 300;
int LOADCELL_SCALE_MILK_1 = 300;
int LOADCELL_SCALE_MILK_2 = 300;
int LOADCELL_SCALE_MILK_3 = 300;
int LOADCELL_SCALE_MILK_4 = 300;
int LOADCELL_INITIAL_MILK_1 = 10000;
int LOADCELL_INITIAL_MILK_2 = 10000;
int LOADCELL_INITIAL_MILK_3 = 10000;
int LOADCELL_INITIAL_MILK_4 = 10000;

CUP_DISPENSER_INFO      CUP_DATA[4];
ICE_DISPENSER_INFO      ICE_DATA[2];
SODA_DISPENSER_INFO     SODA_DATA[1];
HOT_DISPENSER_INFO      HOT_DATA[1];
ICECREAM_DISPENSER_INFO ICECREAM_DATA[1];
SYRUP_DISPENSER_INFO    SYRUP_DATA[1];
BARCODE_INFO            BARCODE_DATA[1];
OUTLET_INFO             OUTLET_DATA[NUMBER_OF_OUTLET];
DOOR_INFO               DOOR_DATA[1];
MILK_INFO               MILK_DATA[NUMBER_OF_MILK];


Scheduler *pschedule = NULL;
Logger    *plog;
DisplayDialog *pdisplay;
DialogRobot *probot;

int OP_STATUS_INITIALIZING = PLATFORM_INIT_IDLE;
int OP_STATUS_OPERATING = PLATFORM_OPERATION_IDLE;

int OP_COMMAND_STOP_OPERATING = 0;          // intended by user
int OP_COMMAND_SUPER_STOP_OPERATING = 0;    // unintended stop
int OP_COMMAND_FORCED_STOP_OPERATING = 0;   // unintended stop

int SUPER_FATAL_ERROR_PLATFORM_OPEN;
int PLATFORM_OPENED_WHEN_OPERATING_FLAG = 0;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    lan = new RBLAN2CAN();
    plan = lan;

    LoadLoadcellDB();
    LoadMailDB();

    logger = new Logger();
    plog = logger;

    stock = new DialogStock(ui->FRAME_DEVICE);
    stock->setWindowFlags(Qt::Widget);
    stock->move(0, 0);

    cup = new DialogCupDispenser(ui->FRAME_DEVICE, stock);
    cup->setWindowFlags(Qt::Widget);
    cup->move(0, 0);

    ice = new DialogIceDispenser(ui->FRAME_DEVICE, stock);
    ice->setWindowFlags(Qt::Widget);
    ice->move(0, 0);

    soda = new DialogSodaDispenser(ui->FRAME_DEVICE);
    soda->setWindowFlags(Qt::Widget);
    soda->move(0, 0);

    coffee = new DialogCoffee(ui->FRAME_DEVICE, stock);
    coffee->setWindowFlags(Qt::Widget);
    coffee->move(0, 0);

    syrup = new DialogSyrup(ui->FRAME_DEVICE);
    syrup->setWindowFlags(Qt::Widget);
    syrup->move(0, 0);

    robot = new DialogRobot(ui->FRAME_DEVICE, stock);
    robot->setWindowFlags(Qt::Widget);
    robot->move(0, 0);

    display = new DisplayDialog(nullptr, stock);
//    display->show();
//    display->move(-3000, 0);
//    display->showFullScreen();
    pdisplay = display;

    monitor = new DialogMonitor(ui->FRAME_DEVICE, stock);
    monitor->setWindowFlags(Qt::Widget);
    monitor->move(0, 0);


    door = new DialogDoor(ui->FRAME_DEVICE);
    door->setWindowFlags(Qt::Widget);
    door->move(0, 0);

    barcode = new DialogBarcode(ui->FRAME_DEVICE);
    barcode->setWindowFlags(Qt::Widget);
    barcode->move(0, 0);

    outlet = new DialogOutlet(ui->FRAME_DEVICE);
    outlet->setWindowFlags(Qt::Widget);
    outlet->move(0, 0);

    icecream = new DialogIcecream(ui->FRAME_DEVICE);
    icecream->setWindowFlags(Qt::Widget);
    icecream->move(0, 0);

    hot = new DialogHotDispenser(ui->FRAME_DEVICE);
    hot->setWindowFlags(Qt::Widget);
    hot->move(0, 0);

    kiosk = new DialogKiosk(ui->FRAME_DEVICE);
    kiosk->setStock(stock);
    kiosk->setWindowFlags(Qt::Widget);
    kiosk->move(0, 0);

    setting = new DialogSetting(ui->FRAME_DEVICE, stock, robot, cup, hot, coffee, soda, ice, syrup, icecream, outlet, barcode);
    setting->setWindowFlags(Qt::Widget);
    setting->move(0, 0);


    schedule = new Scheduler(stock, robot, cup, hot, coffee, soda, ice, syrup, icecream, outlet, barcode, monitor);
    pschedule = schedule;


    // Program Starts
    logger->write_space();
    logger->write("[SYSTEM] Core Program Start");



    SUPER_FATAL_ERROR_PLATFORM_OPEN = 0;


    ChangeDeviceDialog(DEV_DIALOG_ID_CUP);

    connect(&timer, SIGNAL(timeout()), this, SLOT(onTimer()));
    timer.start(MAINWINDOW_LOOP_TIME);
}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::LoadLoadcellDB(){
    db = QSqlDatabase::addDatabase("QSQLITE", "DB_LOADCELL");
    db.setDatabaseName(DB_NAME_LOADCELL);

    if(!db.open()){
        qDebug() << "Load Loadcell Database Fail";
        return;
    }

    QSqlQuery query(db);
    if(query.exec("SELECT * FROM Table_Loadcell")){
        while(query.next()){
            QString uses = query.value("uses").toString();
            int scale = query.value("scale").toInt();
            int initial = query.value("initial").toInt();
            if(uses == "HOT_1"){
                LOADCELL_SCALE_HOT_1 = scale;
            }else if(uses == "HOT_2"){
                LOADCELL_SCALE_HOT_2 = scale;
            }else if(uses == "SYRUP"){
                LOADCELL_SCALE_SYRUP = scale;
            }else if(uses == "SODA"){
                LOADCELL_SCALE_SODA = scale;
            }else if(uses == "ICECREAM_1"){
                LOADCELL_SCALE_ICECREAM_1 = scale;
            }else if(uses == "ICECREAM_2"){
                LOADCELL_SCALE_ICECREAM_2 = scale;
            }else if(uses == "MILK_1"){
                LOADCELL_SCALE_MILK_1 = scale;
                LOADCELL_INITIAL_MILK_1 = initial;
            }else if(uses == "MILK_2"){
                LOADCELL_SCALE_MILK_2 = scale;
                LOADCELL_INITIAL_MILK_2 = initial;
            }else if(uses == "MILK_3"){
                LOADCELL_SCALE_MILK_3 = scale;
                LOADCELL_INITIAL_MILK_3 = initial;
            }else if(uses == "MILK_4"){
                LOADCELL_SCALE_MILK_4 = scale;
                LOADCELL_INITIAL_MILK_4 = initial;
            }
        }
    }
    db.close();
}
void MainWindow::LoadMailDB(){
    db = QSqlDatabase::addDatabase("QSQLITE", "DB_MAIL");
    db.setDatabaseName(DB_NAME_MAIL);

    if(!db.open()){
        qDebug() << "Load Mail Database Fail";
        return;
    }

    QSqlQuery query(db);
    if(query.exec("SELECT * FROM Table_Mail")){
        while(query.next()){
            QString mail = query.value("email").toString();
            QString user = query.value("name").toString();
            int level = query.value("level").toInt();
            MAIL_INFO temp;
            temp.mail = mail;
            temp.user = user;
            temp.level = level;

            mail_infos.push_back(temp);
        }
    }
    db.close();
}

void MainWindow::onTimer(){

    if(QApplication::desktop()->screenCount() > 1){
        if(this->geometry().x() != 0){
            this->move(0,0);
        }
//        if(display->geometry().x() != 1920){
//            display->move(1920,0);
//            display->showFullScreen();
//        }
    }else{

    }
    if(IS_UI_LOCK){
        ui->GB_OP_CONTROL->setEnabled(false);
        ui->FRAME->setEnabled(false);
    }else{
        ui->GB_OP_CONTROL->setEnabled(true);
        ui->FRAME->setEnabled(true);
    }

    if(schedule->action_state == ACTION_STATE_CUP_ERROR){
        ui->BTN_CUP_ADD_DONE->setEnabled(true);
    }else{
        ui->BTN_CUP_ADD_DONE->setEnabled(false);
    }

    CoreLogic_Initializing();
    CoreLogic_Operating();

    UpdatePlatformOperationInfo();
    Update_Dev_CupInfo();
    Update_Dev_IceInfo();
    Update_Dev_SodaInfo();
    Update_Dev_CoffeeInfo();
    Update_Dev_SyrupInfo();
    Update_Dev_RobotInfo();
    Update_Dev_MonitorInfo();
    Update_Dev_DoorInfo();
    Update_Dev_BarcodeInfo();
    Update_Dev_OutletInfo();
    Update_Dev_Icecream();
    Update_Dev_HotInfo();
    Update_Dev_KioskInfo();
    Update_Dev_StockInfo();
}




void MainWindow::CoreLogic_Initializing()
{
    static int timeout = 0;
    static uint init_count = 0;
    static int try_count = 0;

    init_count++;
    switch(OP_STATUS_INITIALIZING){
    case PLATFORM_INIT_IDLE:
        ui->LE_PLATFORM_INITIALIZING->setText("");
        // Do nothing
        break;

    case PLATFORM_INIT_START:
        logger->write("[INIT PROCESS] Platform Initialization Start");
        ui->LE_PLATFORM_INITIALIZING->setText("0 %");
        try_count = 0;
        ClearForcedSuperError();
        // 220401 fix--------
        schedule->action_state = ACTION_STATE_INIT;
        robot->RobotMoving = false;
        schedule->remove_inprogress_list();
        schedule->ClearWaitingList();
        schedule->ClearCompletedList();
        robot->MotionHalt();
        // ------------------
        OP_STATUS_OPERATING = PLATFORM_OPERATION_IDLE;
        OP_STATUS_INITIALIZING = PLATFORM_INIT_CHECK_CONNECTION;
        break;

    case PLATFORM_INIT_CHECK_CONNECTION:
    {
        if(init_count%5 != 0){
            break;
        }
        ui->LE_PLATFORM_INITIALIZING->setText("10 %");

        int device_check_result = CheckDeviceConnection();
        if(device_check_result != 0){
            try_count++;
            if(try_count > 3){
                QString dev_type = "";
                if(device_check_result == 1){
                    dev_type = "Robot(CMD)";
                }else if(device_check_result == 2){
                    dev_type = "Robot(DATA)";
                }else if(device_check_result == 3){
                    dev_type = "Device(LAN)";
                }else if(device_check_result == 4){
                    dev_type = "Monitor";
                }
                logger->write("[INIT PROCESS] FAIL -- Device Connection Check Error");
                QMessageBox::warning(this, "초기화 실패", "<font size=4>장치 연결 에러 (" + dev_type + ")<font>");
                OP_STATUS_INITIALIZING = PLATFORM_INIT_ON_FAIL_STATE;
            }
            break;
        }
        logger->write("[INIT PROCESS] Check Connection Success");
        try_count = 0;
        OP_STATUS_INITIALIZING = PLATFORM_INIT_CHECK_ROBOT_IN_GOOD_POSTURE;
        timeout = 500/MAINWINDOW_LOOP_TIME;
        break;
    }

    case PLATFORM_INIT_CHECK_ROBOT_IN_GOOD_POSTURE:
        ui->LE_PLATFORM_INITIALIZING->setText("20 %");
        if(sys_status.sdata.jnt_ang[0] <= 0.0 && sys_status.sdata.jnt_ang[0] >= -120.0){
            if(sys_status.sdata.digital_out[15] == 1){
                logger->write("[INIT PROCESS] Robot Posture Success");
                OP_STATUS_INITIALIZING = PLATFORM_INIT_CHECK_ROBOT_CONNECTION;
            }else{
                logger->write("[INIT PROCESS] FAIL -- Robot Posture Error");
                QMessageBox::warning(this, "초기화 실패", "<font size=4>로봇 자세 에러<font>");
                OP_STATUS_INITIALIZING = PLATFORM_INIT_ON_FAIL_STATE;
            }
        }else{
            logger->write("[INIT PROCESS] FAIL -- Robot Base Angle Error (0 ~ -120)");
            QMessageBox::warning(this, "초기화 실패", "<font size=4>로봇 베이스 각도 에러 (0 ~ -120)<font>");
            OP_STATUS_INITIALIZING = PLATFORM_INIT_ON_FAIL_STATE;
        }
        break;

    case PLATFORM_INIT_CHECK_ROBOT_CONNECTION:
        ui->LE_PLATFORM_INITIALIZING->setText("30 %");
        if(--timeout > 0) break;

        if(robot->motionServer->RBConnectionStatus == false || sys_status.sdata.task_state != 3){
            try_count++;
            if(try_count > 5){
                logger->write("[INIT PROCESS] FAIL -- Robot Program Connection Fail");
                QMessageBox::warning(this, "초기화 실패", "<font size=4>로봇 프로그램 연결 실패<font>");
                OP_STATUS_INITIALIZING = PLATFORM_INIT_ON_FAIL_STATE;
                break;
            }
            robot->MotionHalt();
            timeout = 5000/MAINWINDOW_LOOP_TIME;
            logger->write("[INIT PROCESS] Robot Connection Fail -> Program Turn on");
            OP_STATUS_INITIALIZING = PLATFORM_INIT_ROBOT_PROGRAM_TURN_ON;
            break;
        }

        timeout = 1000/MAINWINDOW_LOOP_TIME;
        logger->write("[INIT PROCESS] Robot Connection Success");
        OP_STATUS_INITIALIZING = PLATFORM_INIT_OUTLET;
        break;

    case PLATFORM_INIT_ROBOT_PROGRAM_TURN_ON: // Branch
        ui->LE_PLATFORM_INITIALIZING->setText("40 %");
        if(--timeout > 0) break;

        robot->MotionPlay();
        timeout = 5000/MAINWINDOW_LOOP_TIME;
        OP_STATUS_INITIALIZING = PLATFORM_INIT_CHECK_ROBOT_CONNECTION;

        break;

    case PLATFORM_INIT_OUTLET:
        ui->LE_PLATFORM_INITIALIZING->setText("60 %");
        logger->write("[INIT PROCESS] Outlet Initialization Start...");
        for(int i=0; i<NUMBER_OF_OUTLET; i++){
            if(outlet->OUTLET_DISABLE[i] == 0){
                outlet->init_state_door[i] = OUTLET_INIT_START;
                outlet->init_state_spin[i] = OUTLET_INIT_START;
            }
        }
        timeout = 1000/MAINWINDOW_LOOP_TIME;
        OP_STATUS_INITIALIZING = PLATFORM_INIT_OUTLET_DONE;
        break;
    case PLATFORM_INIT_OUTLET_DONE:
    {
        ui->LE_PLATFORM_INITIALIZING->setText("70 %");
        if(--timeout > 0)
            break;

        int outlet_init_done = true;
        for(int i=0; i<NUMBER_OF_OUTLET; i++){
            if(outlet->OUTLET_DISABLE[i] == 0 && outlet->is_door_ready[i] == false){
                outlet_init_done = false;
                break;
            }
            if(outlet->OUTLET_DISABLE[i] == 0 && outlet->is_spin_ready[i] == false){
                outlet_init_done = false;
                break;
            }
        }
        if(outlet_init_done == false)
            break;

        logger->write("[INIT PROCESS] Outlet init Success");
        OP_STATUS_INITIALIZING = PLATFORM_INIT_DONE;
        break;
    }
    case PLATFORM_INIT_DONE:
        ui->LE_PLATFORM_INITIALIZING->setText("100 %");
        logger->write("[INIT PROCESS] SUCCESS -- Platform Initialization Success");
        OP_STATUS_INITIALIZING = PLATFORM_INIT_ON_SUCCESS_STATE;
        break;

    case PLATFORM_INIT_ON_SUCCESS_STATE:
        // in success state
        break;

    case PLATFORM_INIT_ON_FAIL_STATE:
        // in fail state
        break;

    default:
        break;
    }
}

void MainWindow::CoreLogic_Operating(){
    static int platform_opening_detection_count = 0;
    static int platform_closing_detection_count = 0;
    static int platform_opened_flag = 0;
    static int platform_open_close_transition_flag = 0;
    static int timeout = 0;


    // OP_COMMAND_STOP_OPERATING only works when the OP_STATUS_OPERATING is on operating state
    if(OP_STATUS_OPERATING != PLATFORM_OPERATION_ON_OPERATING_STATE){
        if(OP_COMMAND_STOP_OPERATING == 1){
            OP_COMMAND_STOP_OPERATING = 0;
        }
        if(OP_COMMAND_FORCED_STOP_OPERATING == 1){
            OP_COMMAND_FORCED_STOP_OPERATING = 0;
        }
        if(OP_COMMAND_SUPER_STOP_OPERATING == 1){
            OP_COMMAND_SUPER_STOP_OPERATING = 0;
        }
    }



    switch(OP_STATUS_OPERATING){
    case PLATFORM_OPERATION_IDLE:
        // Do nothing
        break;

    case PLATFORM_OPERATION_START:
        qDebug() << "PLATFORM_OPERATION_START";
        logger->write("[OPERATING PROCESS] Platform Operation Sequence Start");
        ClearForcedSuperError();
        OP_STATUS_OPERATING = PLATFORM_OPERATION_CHECK_ON_INIT_SUCCES_STATE;
        break;

    case PLATFORM_OPERATION_CHECK_ON_INIT_SUCCES_STATE:
        qDebug() << "PLATFORM_OPERATION_CHECK_ON_INIT_SUCCES_STATE";
        if(OP_STATUS_INITIALIZING == PLATFORM_INIT_ON_SUCCESS_STATE){
            platform_closing_detection_count = 0;
            OP_STATUS_OPERATING = PLATFORM_OPERATION_CHECK_ROBOT_POSTURE;
        }else{
            logger->write("[OPERATING PROCESS] FAIL -- Do Initialize First");
            QMessageBox::warning(this, "운영시작 실패", "<font size=4>초기화를 먼저 수행하십시오.<font>");
            OP_STATUS_OPERATING = PLATFORM_OPERATION_ON_OPERATING_FAIL_STATE;
        }
        break;

    case PLATFORM_OPERATION_CHECK_ROBOT_POSTURE:
        if(sys_status.sdata.jnt_ang[0] <= 0.0 && sys_status.sdata.jnt_ang[0] >= -120.0){
            if(sys_status.sdata.digital_out[15] == 1){
                OP_STATUS_OPERATING = PLATFORM_OPERATION_CHECK_PLATFORM_CLOSED;
            }else{
                logger->write("[OPERATING PROCESS] FAIL -- Robot Posture Error");
                QMessageBox::warning(this, "운영시작 실패", "<font size=4>로봇 자세 에러<font>");
                OP_STATUS_OPERATING = PLATFORM_OPERATION_ON_OPERATING_FAIL_STATE;
            }
        }else{
            logger->write("[OPERATING PROCESS] FAIL -- Robot Base Angle Error");
            QMessageBox::warning(this, "운영시작 실패", "<font size=4>로봇 베이스 각도 에러 (-120 ~ 0)<font>");
            OP_STATUS_OPERATING = PLATFORM_OPERATION_ON_OPERATING_FAIL_STATE;
        }
        break;

    case PLATFORM_OPERATION_CHECK_PLATFORM_CLOSED:
        qDebug() << "PLATFORM_OPERATION_CHECK_PLATFORM_CLOSED";
        if(door->IsPlatformClosed() == 1){
            platform_closing_detection_count++;
        }else{
            logger->write("[OPERATING PROCESS] FAIL -- Platform is Opened");
            QMessageBox::warning(this, "운영시작 실패", "<font size=4>플랫폼 문이 열려 있습니다.<font>");
            OP_STATUS_OPERATING = PLATFORM_OPERATION_ON_OPERATING_FAIL_STATE;
        }
        if(platform_closing_detection_count > 10){
            OP_STATUS_OPERATING = PLATFORM_OPERATION_CHECK_OUTLET_OCCUPY;
        }
        break;

    case PLATFORM_OPERATION_CHECK_OUTLET_OCCUPY:
    {
        qDebug() << "PLATFORM_OPERATION_CHECK_OUTLET_OCCUPY";
        int occupy_num = 0;
        for(int i=0; i<NUMBER_OF_OUTLET; i++){
            for(int j=0; j<NUMBER_OF_CELL; j++){
                if(outlet->OUTLET_DISABLE[i] == 0 && OUTLET_DATA[i].cell_state[j] == CELL_OCC){
                    occupy_num++;
                }
            }
        }
        if(occupy_num > 0){
            logger->write("[OPERATING PROCESS] FAIL -- Dispense Outlet First");
            QMessageBox::warning(this, "운영시작 실패", "<font size=4>배출구에 음료가 있습니다. 먼저 배출하십시오.<font>");
            OP_STATUS_OPERATING = PLATFORM_OPERATION_ON_OPERATING_FAIL_STATE;
            break;
        }
        if(outlet->OUTLET_DISABLE[0] == 1 && outlet->OUTLET_DISABLE[1] == 1){
            logger->write("[OPERATING PROCESS] FAIL -- Outlet All Disable");
            QMessageBox::warning(this, "운영시작 실패", "<font size=4>배출구가 모두 비활성화 되었습니다.<font>");
            OP_STATUS_OPERATING = PLATFORM_OPERATION_ON_OPERATING_FAIL_STATE;
            break;
        }
        logger->write("[OPERATING PROCESS] Check Outlet occupy : Success");
        OP_STATUS_OPERATING = PLATFORM_OPERATION_CHECK_SCHEDULER;
        break;
    }

    case PLATFORM_OPERATION_CHECK_SCHEDULER:
        qDebug() << "PLATFORM_OPERATION_CHECK_SCHEDULER";
        schedule->action_state = ACTION_STATE_IDLE;

        // unblock the order
        kiosk->block_order = false;

        // clear platform opened flag
        platform_opened_flag = 0;
        platform_open_close_transition_flag = 0;

        // clear robot force stop flag
        robot->ClearSystemForcedStopFlag();

        // clear stop flags
        OP_COMMAND_SUPER_STOP_OPERATING = 0;
        OP_COMMAND_FORCED_STOP_OPERATING = 0;

        logger->write("[OPERATING PROCESS] Platform is in the Operation State");
        OP_STATUS_OPERATING = PLATFORM_OPERATION_ON_OPERATING_STATE;
        break;
    case PLATFORM_OPERATION_ON_OPERATING_STATE:
        // in operating state
        if(platform_opened_flag == 0){
            // platform closed
            // normal operation
            if(door->IsPlatformClosed() == 0){
                platform_opening_detection_count++;
            }else{
                platform_opening_detection_count = 0;
            }
            if(platform_opening_detection_count > 10){
                platform_closing_detection_count = 0;
                platform_open_close_transition_flag = 1;
                platform_opened_flag = 1;
            }

            // do it once
            if(platform_open_close_transition_flag == 1){
                platform_open_close_transition_flag = 0;

                // unblock the order
                kiosk->block_order = false;
            }else{
                // continuously work code

                // robot speed to normal
                if(PLATFORM_OPENED_WHEN_OPERATING_FLAG == 1){
                    if(fabs(sys_status.sdata.default_speed-ROBOT_STOP_SPPED) > 0.01){
                        robot->BaseSpeedChange(ROBOT_STOP_SPPED);
                    }
                }else{
                    if(fabs(sys_status.sdata.default_speed-ROBOT_NORMAL_SPEED) > 0.01){
                        robot->BaseSpeedChange(ROBOT_NORMAL_SPEED);
                    }
                }

                // unblock the order
                kiosk->block_order = false;
            }

        }else{
            // platform opened
            if(door->IsPlatformClosed() == 1){
                platform_closing_detection_count++;
            }else{
                platform_closing_detection_count = 0;
            }
            if(platform_closing_detection_count > 10){
                platform_opening_detection_count = 0;
                platform_open_close_transition_flag = 1;
                platform_opened_flag = 0;
            }

            // do it once
            if(platform_open_close_transition_flag == 1){
                platform_open_close_transition_flag = 0;

                // block the order
                kiosk->block_order = true;

                // fatal error check -- is robot in the unsafe position??
                if((schedule->action_state != ACTION_STATE_IDLE) && (schedule->action_state != ACTION_STATE_INIT)){
//                    logger->write("[SUPER STOP] DUE TO PLATFORM OPEN ERROR");
//                    SUPER_FATAL_ERROR_PLATFORM_OPEN = 1;
//                    OP_COMMAND_SUPER_STOP_OPERATING = 1;

                    logger->write("[GENTLE STOP] DUE TO PLATFORM OPEN ERROR");
                    PLATFORM_OPENED_WHEN_OPERATING_FLAG = 1;
                }

            }else{
                // continuously work code

                // robot speed to zero
                if(fabs(sys_status.sdata.default_speed-ROBOT_STOP_SPPED) > 0.01){
                    robot->BaseSpeedChange(ROBOT_STOP_SPPED);
                }

                // block the order
                kiosk->block_order = true;
            }

        }


        // FORCE STOP TRIGGER
//        if(loadcell->FORCE_FATAL_ERROR_LOADCELL_BOBA == 1){
////            logger->write("[FORCE STOP] DUE TO LOADCELL BOBA ERROR");
//            OP_COMMAND_FORCED_STOP_OPERATING = 1;
//        }

        // SUPER STOP TRIGGER
        if(lan->SUPER_FATAL_ERROR_CONNECTION_OF_LAN2CAN == 1){
            logger->write("[SUPER STOP] DUE TO LAN2CAN BOARD CONNECTION ERROR");
            OP_COMMAND_SUPER_STOP_OPERATING = 1;
        }

        if(robot->SUPER_FATAL_ERROR_ROBOT_DATA == 1){
            logger->write("[SUPER STOP] DUE TO ROBOT DATA ERROR");
            OP_COMMAND_SUPER_STOP_OPERATING = 1;
        }
        if(robot->SUPER_FATAL_ERROR_ROBOT_MISS_COMMAND_WORKING_CHECK == 1){
            logger->write("[SUPER STOP] DUE TO ROBOT MISS COMMAND CHECK ERROR");
            OP_COMMAND_SUPER_STOP_OPERATING = 1;
        }

        if(outlet->SUPER_FATAL_ERROR_OUTLET_CONNECTION == 1){
            logger->write("[SUPER STOP] DUE TO OUTLET CONNECTION ERROR");
            OP_COMMAND_SUPER_STOP_OPERATING = 1;
        }
        if(outlet->SUPER_FATAL_ERROR_OUTLET_CONTROL == 1){
            logger->write("[SUPER STOP] DUE TO OUTLET CONTROL ERROR");
            OP_COMMAND_SUPER_STOP_OPERATING = 1;
        }
        if(outlet->SUPER_FATAL_ERROR_OUTLET_SENSOR){
            logger->write("[SUPER STOP] DUE TO OUTLET SENSOR ERROR");
            OP_COMMAND_SUPER_STOP_OPERATING = 1;
        }



        // Super Operating Stop Command
        if(OP_COMMAND_SUPER_STOP_OPERATING == 1){
            // block the order
            kiosk->block_order = true;

            robot->SetSystemForcedStopFlag();

            schedule->SetRecallOrderFlag();
            schedule->SetRecallInprogressingOrderFlag();
            schedule->action_state = ACTION_STATE_INIT;
            OP_STATUS_OPERATING = PLATFORM_OPERATION_ON_ERROR_STATE;
            OP_STATUS_INITIALIZING = PLATFORM_INIT_IDLE;

            logger->write("[SUPER STOP] DO SUPER STOP");
        }
        // Forced Operating Stop Command
        else if(OP_COMMAND_FORCED_STOP_OPERATING == 1){
            // block the order
            kiosk->block_order = true;

            schedule->last_order_flag = true;
            OP_STATUS_OPERATING = PLATFORM_OPERATION_ON_ERROR_STATE;
            OP_STATUS_INITIALIZING = PLATFORM_INIT_IDLE;

            logger->write("[FORCED STOP] DO FORCED STOP");
        }
        // Operating Stop Command
        else if(OP_COMMAND_STOP_OPERATING == 1){
            // block the order
            kiosk->block_order = true;

            if((schedule->IsIdle()) && (schedule->action_state == ACTION_STATE_IDLE)){
                qDebug()<<"-- All outlets & orders are free, ACTION STATE IDLE, Motion Flag 0";

                schedule->action_state = ACTION_STATE_INIT;
                OP_STATUS_OPERATING = PLATFORM_OPERATION_IDLE;

                logger->write("[GENTLE STOP] DO GENTLE STOP");
            }
        }


        // check the robot in the safe region or not
        // todo lim

        //OP_STATUS_OPERATING = PLATFORM_OPERATION_PLATFORM_OPENED_DETECTED;

        break;

    case PLATFORM_OPERATION_ON_ERROR_STATE:
        // in error state
        break;

    case PLATFORM_OPERATION_ON_OPERATING_FAIL_STATE:
        // in init fail state
        break;

    case PLATFORM_OPERATION_FATAL_CHECK_ROBOT_DANGEROUS_POSITION:

        break;

    case PLATFORM_OPERATION_FATAL_AVOID_ROBOT_DANGEROUS_POSITION:
        break;

    case PLATFORM_OPERATION_PLATFORM_OPENED_DETECTED:

        break;

    default:
        break;
    }
}



void MainWindow::UpdatePlatformOperationInfo(){
    static int blink_count = 0;
    static int platform_physically_opened_or_not = -1;

    blink_count++;

    // Operating Status for Initializing
    if(OP_STATUS_INITIALIZING == PLATFORM_INIT_ON_SUCCESS_STATE){
        SetLEColor(ui->LE_PLATFORM_INITIALIZING, COLOR_GOOD);
    }else if(OP_STATUS_INITIALIZING == PLATFORM_INIT_ON_FAIL_STATE){
        SetLEColor(ui->LE_PLATFORM_INITIALIZING, COLOR_BAD);
    }else if(OP_STATUS_INITIALIZING == PLATFORM_INIT_IDLE){
        SetLEColor(ui->LE_PLATFORM_INITIALIZING, "white");
    }else{
        SetLEColor(ui->LE_PLATFORM_INITIALIZING, "yellow");
    }


    if(OP_STATUS_OPERATING == PLATFORM_OPERATION_ON_OPERATING_STATE){
        SetLEColor(ui->LE_PLATFORM_OPERATING, COLOR_GOOD);
    }else if(OP_STATUS_OPERATING == PLATFORM_OPERATION_ON_ERROR_STATE){
        SetLEColor(ui->LE_PLATFORM_OPERATING, COLOR_BAD);
    }else if(OP_STATUS_OPERATING == PLATFORM_OPERATION_IDLE || OP_STATUS_OPERATING == PLATFORM_OPERATION_ON_OPERATING_FAIL_STATE){
        SetLEColor(ui->LE_PLATFORM_OPERATING, "white");
    }else{
        SetLEColor(ui->LE_PLATFORM_OPERATING, "yellow");
    }


    if(door->IsPlatformClosed() == 1){
        SetLEColor(ui->LE_PLATFORM_CLOSED, COLOR_GOOD);
    }else{
        SetLEColor(ui->LE_PLATFORM_CLOSED, COLOR_BAD);
    }

    if(door->IsPlatformClosed() != platform_physically_opened_or_not){
        platform_physically_opened_or_not = door->IsPlatformClosed();
        if(platform_physically_opened_or_not == 1){
            logger->write("[SYSTEM] PLATFORM PHYSICALLY CLOSED NOW");
        }else{
            logger->write("[SYSTEM] PLATFORM PHYSICALLY OPENED NOW");
        }
    }



    if(OP_COMMAND_STOP_OPERATING == 1){
        if(blink_count%10 == 0){
            SetLEColor(ui->LE_PLATFORM_WAITING_STOP, "yellow");
        }else if(blink_count%10 == 5){
            SetLEColor(ui->LE_PLATFORM_WAITING_STOP, "white");
        }
    }else{
        SetLEColor(ui->LE_PLATFORM_WAITING_STOP, "white");
    }


    if(PLATFORM_OPENED_WHEN_OPERATING_FLAG == 1){
        if(blink_count%10 == 0){
            SetLEColor(ui->LE_PLATFORM_OPENED_WHEN_OPERATING, "yellow");
        }else if(blink_count%10 == 5){
            SetLEColor(ui->LE_PLATFORM_OPENED_WHEN_OPERATING, "white");
        }
    }else{
        SetLEColor(ui->LE_PLATFORM_OPENED_WHEN_OPERATING, "white");
    }
}


void MainWindow::Update_Dev_CupInfo(){
    if(lan->sockConnectionStatus == false){
        SetBTNColor(ui->BTN_DEV_INFO_CUP, COLOR_UNDETERMINED);
        ui->LB_CUP_1_LAST_ERROR->setText("-");
        ui->LB_CUP_2_LAST_ERROR->setText("-");
        ui->LB_CUP_3_LAST_ERROR->setText("-");
        ui->LB_CUP_4_LAST_ERROR->setText("-");
        ui->LB_CUP_1_OP_STATE->setText("-");
        ui->LB_CUP_2_OP_STATE->setText("-");
        ui->LB_CUP_3_OP_STATE->setText("-");
        ui->LB_CUP_4_OP_STATE->setText("-");
    }else{
        if(CUP_DATA[0].connection_status == 1 &&
            CUP_DATA[1].connection_status == 1 &&
            CUP_DATA[2].connection_status == 1 &&
            CUP_DATA[3].connection_status == 1){
            SetBTNColor(ui->BTN_DEV_INFO_CUP, COLOR_GOOD);
        }else{
            SetBTNColor(ui->BTN_DEV_INFO_CUP, COLOR_WEAKBAD);
        }

        if(CUP_DATA[0].connection_status == 1){
            ui->LB_CUP_1_LAST_ERROR->setText(cup->cup_1_error);
            if(CUP_DATA[0].dispense_op_flag == 0){
                ui->LB_CUP_1_OP_STATE->setText("준비");
            }else{
                ui->LB_CUP_1_OP_STATE->setText("동작중");
            }
        }else{
            ui->LB_CUP_1_LAST_ERROR->setText("-");
            ui->LB_CUP_1_OP_STATE->setText("-");
        }

        if(CUP_DATA[1].connection_status == 1){
            ui->LB_CUP_2_LAST_ERROR->setText(cup->cup_2_error);
            if(CUP_DATA[1].dispense_op_flag == 0){
                ui->LB_CUP_2_OP_STATE->setText("준비");
            }else{
                ui->LB_CUP_2_OP_STATE->setText("동작중");
            }
        }else{
            ui->LB_CUP_2_LAST_ERROR->setText("-");
            ui->LB_CUP_2_OP_STATE->setText("-");
        }

        if(CUP_DATA[2].connection_status == 1){
            ui->LB_CUP_3_LAST_ERROR->setText(cup->cup_3_error);
            if(CUP_DATA[2].dispense_op_flag == 0){
                ui->LB_CUP_3_OP_STATE->setText("준비");
            }else{
                ui->LB_CUP_3_OP_STATE->setText("동작중");
            }
        }else{
            ui->LB_CUP_3_LAST_ERROR->setText("-");
            ui->LB_CUP_3_OP_STATE->setText("-");
        }

        if(CUP_DATA[3].connection_status == 1){
            ui->LB_CUP_4_LAST_ERROR->setText(cup->cup_4_error);
            if(CUP_DATA[3].dispense_op_flag == 0){
                ui->LB_CUP_4_OP_STATE->setText("준비");
            }else{
                ui->LB_CUP_4_OP_STATE->setText("동작중");
            }
        }else{
            ui->LB_CUP_4_LAST_ERROR->setText("-");
            ui->LB_CUP_4_OP_STATE->setText("-");
        }
    }
}

void MainWindow::Update_Dev_IceInfo(){
    if(lan->sockConnectionStatus == false){
        SetBTNColor(ui->BTN_DEV_INFO_ICE_1, COLOR_UNDETERMINED);
        SetBTNColor(ui->BTN_DEV_INFO_ICE_2, COLOR_UNDETERMINED);
        ui->LB_ICE_1_FULL->setText("-");
        ui->LB_ICE_2_FULL->setText("-");
        ui->LB_ICE_1_ERROR->setText("-");
        ui->LB_ICE_2_ERROR->setText("-");
    }else{
        if(ICE_DATA[0].connection_status == 1 && ICE_DATA[0].data_connection == 1){
            SetBTNColor(ui->BTN_DEV_INFO_ICE_1, COLOR_GOOD);

            if(ICE_DATA[0].status.b.full_ice == 1){
                ui->LB_ICE_1_FULL->setText("만빙");
            }else{
                ui->LB_ICE_1_FULL->setText("만빙아님");
            }
            ui->LB_ICE_1_ERROR->setText(ice->ice_1_error);
        }else{
            SetBTNColor(ui->BTN_DEV_INFO_ICE_1, COLOR_WEAKBAD);
            ui->LB_ICE_1_FULL->setText("-");
            ui->LB_ICE_1_ERROR->setText("-");
        }
        if(ICE_DATA[1].connection_status == 1 && ICE_DATA[1].data_connection == 1){
            SetBTNColor(ui->BTN_DEV_INFO_ICE_2, COLOR_GOOD);

            if(ICE_DATA[1].status.b.full_ice == 1){
                ui->LB_ICE_2_FULL->setText("만빙");
            }else{
                ui->LB_ICE_2_FULL->setText("만빙아님");
            }
            ui->LB_ICE_2_ERROR->setText(ice->ice_2_error);
        }else{
            SetBTNColor(ui->BTN_DEV_INFO_ICE_2, COLOR_WEAKBAD);
            ui->LB_ICE_2_FULL->setText("-");
            ui->LB_ICE_2_ERROR->setText("-");
        }
    }
}

void MainWindow::Update_Dev_SodaInfo(){
    if(lan->sockConnectionStatus == false){
        SetBTNColor(ui->BTN_DEV_INFO_SODA, COLOR_UNDETERMINED);
        ui->LB_SODA_LOADCELL->setText("-");
        ui->LB_SODA_LAST_ERROR->setText("-");
        ui->LB_SODA_OP_STATE->setText("-");
    }else{
        if(SODA_DATA[0].connection_status == 1){
            SetBTNColor(ui->BTN_DEV_INFO_SODA, COLOR_GOOD);
            ui->LB_SODA_LOADCELL->setText(QString().sprintf("%d", soda->LoadcellValue()));
            ui->LB_SODA_LAST_ERROR->setText(soda->soda_error);
            if(SODA_DATA[0].out_state == 0){
                ui->LB_SODA_OP_STATE->setText("준비");
            }else{
                ui->LB_SODA_OP_STATE->setText("동작중");
            }
        }else{
            SetBTNColor(ui->BTN_DEV_INFO_SODA, COLOR_WEAKBAD);
            ui->LB_SODA_LOADCELL->setText("-");
            ui->LB_SODA_LAST_ERROR->setText("-");
            ui->LB_SODA_OP_STATE->setText("-");
        }
    }
}

void MainWindow::Update_Dev_CoffeeInfo(){
    if(coffee->getCurrentStatus() == MACHINE_NOT_CONNECTED){
        SetBTNColor(ui->BTN_DEV_INFO_COFFEE, COLOR_WEAKBAD);
    }else{
        SetBTNColor(ui->BTN_DEV_INFO_COFFEE, COLOR_GOOD);
    }

    SetLEColor(ui->LE_MACHINE_STATUS_NOT_CONNECTED, COLOR_NONE);
    SetLEColor(ui->LE_MACHINE_STATUS_PREPAREING, COLOR_NONE);
    SetLEColor(ui->LE_MACHINE_STATUS_ERROR_OCCURED, COLOR_NONE);
    SetLEColor(ui->LE_MACHINE_STATUS_ON_READY, COLOR_NONE);
    SetLEColor(ui->LE_MACHINE_STATUS_MAKING, COLOR_NONE);
    SetLEColor(ui->LE_MACHINE_STATUS_SYS_CLEANING, COLOR_NONE);
    SetLEColor(ui->LE_MACHINE_STATUS_MILK_CLEANING, COLOR_NONE);
    SetLEColor(ui->LE_MACHINE_STATUS_MILK_REPLACING, COLOR_NONE);
    if(coffee->status == MACHINE_NOT_CONNECTED){
        SetLEColor(ui->LE_MACHINE_STATUS_NOT_CONNECTED, COLOR_BAD);
    }else if(coffee->status == MACHINE_NOT_READY){
        SetLEColor(ui->LE_MACHINE_STATUS_PREPAREING, COLOR_BAD);
    }else if(coffee->status == MACHINE_ERROR_OCCURRED){
        SetLEColor(ui->LE_MACHINE_STATUS_ERROR_OCCURED, COLOR_BAD);
    }else if(coffee->status == MACHINE_READY){
        SetLEColor(ui->LE_MACHINE_STATUS_ON_READY, COLOR_BLUE);
    }else if(coffee->status == MACHINE_MAKING_BEVERAGE){
        SetLEColor(ui->LE_MACHINE_STATUS_MAKING, COLOR_BLUE);
    }else if(coffee->status == MACHINE_SYSTEM_CLEANING){
        SetLEColor(ui->LE_MACHINE_STATUS_SYS_CLEANING, COLOR_WEAKBAD);
    }else if(coffee->status == MACHINE_MILK_CLEANING){
        SetLEColor(ui->LE_MACHINE_STATUS_MILK_CLEANING, COLOR_WEAKBAD);
    }else if(coffee->status == MACHINE_MILK_REPLACEMENT){
        SetLEColor(ui->LE_MACHINE_STATUS_MILK_REPLACING, COLOR_WEAKBAD);
    }

    int syscleantime = coffee->Machine.dueTimeSysClean;
    int milkcleantime = coffee->Machine.dueTimeMilkClean;
    int milkreplacetime = coffee->Machine.dueTimeMilkReplace;

    if(syscleantime < 0){
        ui->LE_SYS_CLEAN_TIME_HOUR->setText("-");
        ui->LE_SYS_CLEAN_TIME_MINUTE->setText("-");
        ui->LE_SYS_CLEAN_TIME_SECOND->setText("-");
    }else{
        int hour = syscleantime/3600;
        int min = (syscleantime-hour*3600)/60;
        int sec = syscleantime%60;
        ui->LE_SYS_CLEAN_TIME_HOUR->setText(QString().sprintf("%d", hour));
        ui->LE_SYS_CLEAN_TIME_MINUTE->setText(QString().sprintf("%d", min));
        ui->LE_SYS_CLEAN_TIME_SECOND->setText(QString().sprintf("%d", sec));
    }

    if(milkcleantime < 0){
        ui->LE_MILK_CLEAN_TIME_HOUR->setText("-");
        ui->LE_MILK_CLEAN_TIME_MINUTE->setText("-");
        ui->LE_MILK_CLEAN_TIME_SECOND->setText("-");
    }else{
        int hour = milkcleantime/3600;
        int min = (milkcleantime-hour*3600)/60;
        int sec = milkcleantime%60;
        ui->LE_MILK_CLEAN_TIME_HOUR->setText(QString().sprintf("%d", hour));
        ui->LE_MILK_CLEAN_TIME_MINUTE->setText(QString().sprintf("%d", min));
        ui->LE_MILK_CLEAN_TIME_SECOND->setText(QString().sprintf("%d", sec));
    }

    if(milkreplacetime < 0){
        ui->LE_MILK_REPLACE_TIME_HOUR->setText("-");
        ui->LE_MILK_REPLACE_TIME_MINUTE->setText("-");
        ui->LE_MILK_REPLACE_TIME_SECOND->setText("-");
    }else{
        int hour = milkreplacetime/3600;
        int min = (milkreplacetime-hour*3600)/60;
        int sec = milkreplacetime%60;
        ui->LE_MILK_REPLACE_TIME_HOUR->setText(QString().sprintf("%d", hour));
        ui->LE_MILK_REPLACE_TIME_MINUTE->setText(QString().sprintf("%d", min));
        ui->LE_MILK_REPLACE_TIME_SECOND->setText(QString().sprintf("%d", sec));
    }
}

void MainWindow::Update_Dev_SyrupInfo(){
    if(lan->sockConnectionStatus == false){
        SetBTNColor(ui->BTN_DEV_INFO_SYRUP, COLOR_UNDETERMINED);
        ui->LB_SYRUP_LOADCELL->setText("-");
        ui->LB_SYRUP_LAST_ERROR->setText("-");
        ui->LB_SYRUP_OP_STATE->setText("-");
    }else{
        if(SYRUP_DATA[0].connection_status == 1){
            SetBTNColor(ui->BTN_DEV_INFO_SYRUP, COLOR_GOOD);
            ui->LB_SYRUP_LOADCELL->setText(QString().sprintf("%d", syrup->LoadcellValue()));
            ui->LB_SYRUP_LAST_ERROR->setText(syrup->syrup_error);
            if(SYRUP_DATA[0].out_state == 0){
                ui->LB_SYRUP_OP_STATE->setText("준비");
            }else{
                ui->LB_SYRUP_OP_STATE->setText("동작중");
            }
        }else{
            SetBTNColor(ui->BTN_DEV_INFO_SYRUP, COLOR_WEAKBAD);
            ui->LB_SYRUP_LOADCELL->setText("-");
            ui->LB_SYRUP_LAST_ERROR->setText("-");
            ui->LB_SYRUP_OP_STATE->setText("-");
        }
    }
}

void MainWindow::Update_Dev_RobotInfo(){
    if(robot->cmdConnectionStatus == true && robot->dataConnectionStatus == true){
        SetBTNColor(ui->BTN_DEV_INFO_ROBOT, COLOR_GOOD);

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

        if(robot->motionServer->RBConnectionStatus == true){
            SetLEColor(ui->LE_ROBOT_PRG_CONNECT, COLOR_GOOD);
        }else{
            SetLEColor(ui->LE_ROBOT_PRG_CONNECT, COLOR_BAD);
        }

        if(OP_STATUS_OPERATING != PLATFORM_OPERATION_ON_OPERATING_STATE){
            if(sys_status.sdata.jnt_ang[0] < 0 && sys_status.sdata.jnt_ang[0] > -120){
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
    }else{
        SetBTNColor(ui->BTN_DEV_INFO_ROBOT, COLOR_WEAKBAD);

        SetLEColor(ui->LE_PG_MODE_REAL, COLOR_UNDETERMINED);
        SetLEColor(ui->LE_PG_MODE_SIMULATION, COLOR_UNDETERMINED);

        SetLEColor(ui->LE_ROBOT_STATE_IDLE, COLOR_UNDETERMINED);
        SetLEColor(ui->LE_ROBOT_STATE_MOVING, COLOR_UNDETERMINED);

        SetLEColor(ui->LE_ROBOT_STATUS_TEACHING, COLOR_UNDETERMINED);
        SetLEColor(ui->LE_ROBOT_STATUS_EXT_COLLISION, COLOR_UNDETERMINED);
        SetLEColor(ui->LE_ROBOT_STATUS_SELF_COLLISION, COLOR_UNDETERMINED);
        SetLEColor(ui->LE_ROBOT_STATUS_PAUSED, COLOR_UNDETERMINED);
        SetLEColor(ui->LE_ROBOT_STATUS_EMS, COLOR_UNDETERMINED);
        SetLEColor(ui->LE_ROBOT_STATUS_SOS, COLOR_UNDETERMINED);

        SetLEColor(ui->LE_ROBOT_PRG_WORKING_STATUS, COLOR_UNDETERMINED);
        SetLEColor(ui->LE_ROBOT_PRG_CONNECT, COLOR_UNDETERMINED);

        SetLEColor(ui->LE_ROBOT_INIT_BASE_ANGLE, COLOR_UNDETERMINED);
        SetLEColor(ui->LE_ROBOT_INIT_POSITION, COLOR_UNDETERMINED);
    }
}

void MainWindow::Update_Dev_MonitorInfo(){
    if(monitor->displayConnectionStatus == true){
        SetBTNColor(ui->BTN_DEV_INFO_MONITOR, COLOR_GOOD);
        ui->LB_MONITOR_INPROGRESS->setText(QString().sprintf("%d", schedule->list_inprogress.size()));
        ui->LB_MONITOR_WAITING->setText(QString().sprintf("%d", schedule->get_waiting_size()));
        ui->LB_MONITOR_COMPLETED->setText(QString().sprintf("%d", schedule->get_complete_size()));

        if(OP_STATUS_OPERATING == PLATFORM_OPERATION_ON_OPERATING_STATE){
            monitor->set_display_mode(DISPLAY_MODE_IN_OPERATION);
        }else if(OP_STATUS_OPERATING == PLATFORM_OPERATION_ON_ERROR_STATE){
            monitor->set_display_mode(DISPLAY_MODE_IN_OPERATION);
            monitor->display_msg = "에러가 발생하였습니다. 관리자를 호출해주세요.";
        }else{
            monitor->display_msg = "";
            monitor->set_display_mode(DISPLAY_MODE_IN_READY);
        }
   }else{
        SetBTNColor(ui->BTN_DEV_INFO_MONITOR, COLOR_WEAKBAD);
        ui->LB_MONITOR_INPROGRESS->setText("-");
        ui->LB_MONITOR_WAITING->setText("-");
        ui->LB_MONITOR_COMPLETED->setText("-");
    }
}

void MainWindow::Update_Dev_DoorInfo(){
    if(lan->sockConnectionStatus == false){
        SetBTNColor(ui->BTN_DEV_INFO_DOOR, COLOR_UNDETERMINED);
        SetLEColor(ui->LE_DOOR_OPENED, COLOR_UNDETERMINED);
        SetLEColor(ui->LE_DOOR_CLOSED, COLOR_UNDETERMINED);
    }else{
        //test
//        DOOR_DATA[0].connection_status = 1;
//        DOOR_DATA[0].platform_sensorA = 1;
//        DOOR_DATA[0].platform_sensorB = 1;


        if(DOOR_DATA[0].connection_status == 1){
            SetBTNColor(ui->BTN_DEV_INFO_DOOR, COLOR_GOOD);
            if(door->IsPlatformClosed() == 1){
                SetLEColor(ui->LE_DOOR_OPENED, COLOR_NONE);
                SetLEColor(ui->LE_DOOR_CLOSED, COLOR_BLUE);
            }else{
                SetLEColor(ui->LE_DOOR_OPENED, COLOR_BLUE);
                SetLEColor(ui->LE_DOOR_CLOSED, COLOR_NONE);
            }
        }else{
            SetBTNColor(ui->BTN_DEV_INFO_DOOR, COLOR_WEAKBAD);
            SetLEColor(ui->LE_DOOR_OPENED, COLOR_UNDETERMINED);
            SetLEColor(ui->LE_DOOR_CLOSED, COLOR_UNDETERMINED);
        }
    }
}

void MainWindow::Update_Dev_BarcodeInfo(){
    if(lan->sockConnectionStatus == false){
        SetBTNColor(ui->BTN_DEV_INFO_BARCODE, COLOR_UNDETERMINED);
        ui->LB_BARCODE_LAST_DATA->setText("-");
    }else{
        SetBTNColor(ui->BTN_DEV_INFO_BARCODE, COLOR_GOOD);
        ui->LB_BARCODE_LAST_DATA->setText(barcode->NewBarcodePin);
    }
}

void MainWindow::Update_Dev_OutletInfo(){
    if(lan->sockConnectionStatus == false){
        SetBTNColor(ui->BTN_DEV_INFO_OUTLET, COLOR_UNDETERMINED);
        SetLEColor(ui->LE_OUTLET_M_1_DOOR_OPEN, COLOR_UNDETERMINED);
        SetLEColor(ui->LE_OUTLET_M_1_DOOR_CLOSE, COLOR_UNDETERMINED);
        SetLEColor(ui->LE_OUTLET_M_1_CUP_DETECT, COLOR_UNDETERMINED);
        SetLEColor(ui->LE_OUTLET_M_2_DOOR_OPEN, COLOR_UNDETERMINED);
        SetLEColor(ui->LE_OUTLET_M_2_DOOR_CLOSE, COLOR_UNDETERMINED);
        SetLEColor(ui->LE_OUTLET_M_2_CUP_DETECT, COLOR_UNDETERMINED);
        ui->LB_OUTLET_M_1_CELL_1->setText("-");
        ui->LB_OUTLET_M_1_CELL_2->setText("-");
        ui->LB_OUTLET_M_1_CELL_3->setText("-");
        ui->LB_OUTLET_M_2_CELL_1->setText("-");
        ui->LB_OUTLET_M_2_CELL_2->setText("-");
        ui->LB_OUTLET_M_2_CELL_3->setText("-");
    }else{
        if(OUTLET_DATA[0].connection_status == 1 && OUTLET_DATA[1].connection_status == 1){
            SetBTNColor(ui->BTN_DEV_INFO_OUTLET, COLOR_GOOD);
        }else{
            SetBTNColor(ui->BTN_DEV_INFO_OUTLET, COLOR_WEAKBAD);
        }

        if(OUTLET_DATA[0].connection_status == 1){
            if(outlet->GetDoorPosition(0) == DOOR_IN_OPEN_POS){
                SetLEColor(ui->LE_OUTLET_M_1_DOOR_OPEN, COLOR_BLUE);
                SetLEColor(ui->LE_OUTLET_M_1_DOOR_CLOSE, COLOR_NONE);
            }else if(outlet->GetDoorPosition(0) == DOOR_IN_CLOSE_POS){
                SetLEColor(ui->LE_OUTLET_M_1_DOOR_OPEN, COLOR_NONE);
                SetLEColor(ui->LE_OUTLET_M_1_DOOR_CLOSE, COLOR_BLUE);
            }else{
                SetLEColor(ui->LE_OUTLET_M_1_DOOR_OPEN, COLOR_NONE);
                SetLEColor(ui->LE_OUTLET_M_1_DOOR_CLOSE, COLOR_NONE);
            }

            if(OUTLET_DATA[0].sonar_sensor_data < OUTLET_SONAR_SENSOR_THRESHOLD){
                SetLEColor(ui->LE_OUTLET_M_1_CUP_DETECT, COLOR_BLUE);
            }else{
                SetLEColor(ui->LE_OUTLET_M_1_CUP_DETECT, COLOR_NONE);
            }

            if(OUTLET_DATA[0].cell_state[0] == CELL_OCC){
                ui->LB_OUTLET_M_1_CELL_1->setText(OUTLET_DATA[0].cell_occupy_pin[0]);
            }else{
                ui->LB_OUTLET_M_1_CELL_1->setText("-");
            }
            if(OUTLET_DATA[0].cell_state[1] == CELL_OCC){
                ui->LB_OUTLET_M_1_CELL_2->setText(OUTLET_DATA[0].cell_occupy_pin[1]);
            }else{
                ui->LB_OUTLET_M_1_CELL_2->setText("-");
            }
            if(OUTLET_DATA[0].cell_state[2] == CELL_OCC){
                ui->LB_OUTLET_M_1_CELL_3->setText(OUTLET_DATA[0].cell_occupy_pin[2]);
            }else{
                ui->LB_OUTLET_M_1_CELL_3->setText("-");
            }
        }else{
            SetLEColor(ui->LE_OUTLET_M_1_DOOR_OPEN, COLOR_UNDETERMINED);
            SetLEColor(ui->LE_OUTLET_M_1_DOOR_CLOSE, COLOR_UNDETERMINED);
            SetLEColor(ui->LE_OUTLET_M_1_CUP_DETECT, COLOR_UNDETERMINED);
            ui->LB_OUTLET_M_1_CELL_1->setText("-");
            ui->LB_OUTLET_M_1_CELL_2->setText("-");
            ui->LB_OUTLET_M_1_CELL_3->setText("-");
        }

        if(OUTLET_DATA[1].connection_status == 1){
            if(outlet->GetDoorPosition(1) == DOOR_IN_OPEN_POS){
                SetLEColor(ui->LE_OUTLET_M_2_DOOR_OPEN, COLOR_BLUE);
                SetLEColor(ui->LE_OUTLET_M_2_DOOR_CLOSE, COLOR_NONE);
            }else if(outlet->GetDoorPosition(1) == DOOR_IN_CLOSE_POS){
                SetLEColor(ui->LE_OUTLET_M_2_DOOR_OPEN, COLOR_NONE);
                SetLEColor(ui->LE_OUTLET_M_2_DOOR_CLOSE, COLOR_BLUE);
            }else{
                SetLEColor(ui->LE_OUTLET_M_2_DOOR_OPEN, COLOR_NONE);
                SetLEColor(ui->LE_OUTLET_M_2_DOOR_CLOSE, COLOR_NONE);
            }

            if(OUTLET_DATA[1].sonar_sensor_data < OUTLET_SONAR_SENSOR_THRESHOLD){
                SetLEColor(ui->LE_OUTLET_M_2_CUP_DETECT, COLOR_BLUE);
            }else{
                SetLEColor(ui->LE_OUTLET_M_2_CUP_DETECT, COLOR_NONE);
            }     

            if(OUTLET_DATA[1].cell_state[0] == CELL_OCC){
                ui->LB_OUTLET_M_2_CELL_1->setText(OUTLET_DATA[1].cell_occupy_pin[0]);
            }else{
                ui->LB_OUTLET_M_2_CELL_1->setText("-");
            }
            if(OUTLET_DATA[1].cell_state[1] == CELL_OCC){
                ui->LB_OUTLET_M_2_CELL_2->setText(OUTLET_DATA[1].cell_occupy_pin[1]);
            }else{
                ui->LB_OUTLET_M_2_CELL_2->setText("-");
            }
            if(OUTLET_DATA[1].cell_state[2] == CELL_OCC){
                ui->LB_OUTLET_M_2_CELL_3->setText(OUTLET_DATA[1].cell_occupy_pin[2]);
            }else{
                ui->LB_OUTLET_M_2_CELL_3->setText("-");
            }
        }else{
            SetLEColor(ui->LE_OUTLET_M_2_DOOR_OPEN, COLOR_UNDETERMINED);
            SetLEColor(ui->LE_OUTLET_M_2_DOOR_CLOSE, COLOR_UNDETERMINED);
            SetLEColor(ui->LE_OUTLET_M_2_CUP_DETECT, COLOR_UNDETERMINED);            
            ui->LB_OUTLET_M_2_CELL_1->setText("-");
            ui->LB_OUTLET_M_2_CELL_2->setText("-");
            ui->LB_OUTLET_M_2_CELL_3->setText("-");
        }
    }
}

void MainWindow::Update_Dev_Icecream(){
    if(lan->sockConnectionStatus == false){
        SetBTNColor(ui->BTN_DEV_INFO_ICECREAM, COLOR_UNDETERMINED);
        ui->LB_ICECREAM_LOADCELL->setText("-");
        ui->LB_ICECREAM_LAST_ERROR->setText("-");
        ui->LB_ICECREAM_OP_STATE->setText("-");
    }else{
        if(ICECREAM_DATA[0].connection_status == 1){
            SetBTNColor(ui->BTN_DEV_INFO_ICECREAM, COLOR_GOOD);
            ui->LB_ICECREAM_LOADCELL->setText(QString().sprintf("%d", icecream->LoadcellValue()));
            ui->LB_ICECREAM_LAST_ERROR->setText(icecream->icecream_error);
            if(ICECREAM_DATA[0].out_state == 0){
                ui->LB_ICECREAM_OP_STATE->setText("준비");
            }else{
                ui->LB_ICECREAM_OP_STATE->setText("동작중");
            }
        }else{
            SetBTNColor(ui->BTN_DEV_INFO_ICECREAM, COLOR_WEAKBAD);
            ui->LB_ICECREAM_LOADCELL->setText("-");
            ui->LB_ICECREAM_LAST_ERROR->setText("-");
            ui->LB_ICECREAM_OP_STATE->setText("-");
        }
    }
}

void MainWindow::Update_Dev_HotInfo(){
    if(lan->sockConnectionStatus == false){
        SetBTNColor(ui->BTN_DEV_INFO_HOT, COLOR_UNDETERMINED);
        ui->LB_HOT_LOADCELL->setText("-");
        ui->LB_HOT_LAST_ERROR->setText("-");
        ui->LB_HOT_OP_STATE->setText("-");
    }else{
        if(HOT_DATA[0].connection_status == 1){
            SetBTNColor(ui->BTN_DEV_INFO_HOT, COLOR_GOOD);
            ui->LB_HOT_LOADCELL->setText(QString().sprintf("%d", hot->LoadcellValue()));
            ui->LB_HOT_LAST_ERROR->setText(hot->hot_error);
            if(HOT_DATA[0].out_state == 0){
                ui->LB_HOT_OP_STATE->setText("준비");
            }else{
                ui->LB_HOT_OP_STATE->setText("동작중");
            }
        }else{
            SetBTNColor(ui->BTN_DEV_INFO_HOT, COLOR_WEAKBAD);
            ui->LB_HOT_LOADCELL->setText("-");
            ui->LB_HOT_LAST_ERROR->setText("-");
            ui->LB_HOT_OP_STATE->setText("-");
        }
    }
}

void MainWindow::Update_Dev_KioskInfo(){
    if(kiosk->connection_status == false){
        SetBTNColor(ui->BTN_DEV_INFO_KIOSK, COLOR_WEAKBAD);
        ui->LB_KIOSK_BLOCK_ORDER->setText("주문차단");
    }else{
        SetBTNColor(ui->BTN_DEV_INFO_KIOSK, COLOR_GOOD);
        if(kiosk->block_order == true){
            ui->LB_KIOSK_BLOCK_ORDER->setText("주문차단");
        }else{
            ui->LB_KIOSK_BLOCK_ORDER->setText("주문허용");
        }
    }
}

void MainWindow::Update_Dev_StockInfo(){

}


void MainWindow::ChangeDeviceDialog(DEVICE_DIALOG_ID id){
    setting->hide();
    cup->hide();
    ice->hide();
    soda->hide();
    coffee->hide();
    robot->hide();
    syrup->hide();
    monitor->hide();
    door->hide();
    barcode->hide();
    outlet->hide();
    icecream->hide();
    hot->hide();
    kiosk->hide();
    stock->hide();


    switch(id){
    case DEV_DIALOG_ID_SETTING:
        setting->show();
        break;
    case DEV_DIALOG_ID_CUP:
        cup->show();
        break;
    case DEV_DIALOG_ID_ICE:
        ice->show();
        break;
    case DEV_DIALOG_ID_SODA:
        soda->show();
        break;
    case DEV_DIALOG_ID_COFFEE:
        coffee->show();
        break;
    case DEV_DIALOG_ID_ROBOT:
        robot->show();
        break;
    case DEV_DIALOG_ID_SYRUP:
        syrup->show();
        break;
    case DEV_DIALOG_ID_MONITOR:
        monitor->show();
        break;
    case DEV_DIALOG_ID_DOOR:
        door->show();
        break;
    case DEV_DIALOG_ID_BARCODE:
        barcode->show();
        break;
    case DEV_DIALOG_ID_OUTLET:
        outlet->show();
        break;
    case DEV_DIALOG_ID_ICECREAM:
        icecream->show();
        break;
    case DEV_DIALOG_ID_HOT:
        hot->show();
        break;
    case DEV_DIALOG_ID_KIOSK:
        kiosk->show();
        break;
    case DEV_DIALOG_ID_STOCK:
        stock->show();
        break;
    default:
        break;
    }
}

void MainWindow::on_BTN_DEV_INFO_CUP_clicked(){
    ChangeDeviceDialog(DEV_DIALOG_ID_CUP);
}


void MainWindow::on_BTN_DEV_INFO_SODA_clicked(){
    ChangeDeviceDialog(DEV_DIALOG_ID_SODA);
}

void MainWindow::on_BTN_DEV_INFO_COFFEE_clicked(){
    ChangeDeviceDialog(DEV_DIALOG_ID_COFFEE);
}

void MainWindow::on_BTN_DEV_INFO_ICE_1_clicked(){
    ChangeDeviceDialog(DEV_DIALOG_ID_ICE);
}
void MainWindow::on_BTN_DEV_INFO_ICE_2_clicked(){
    ChangeDeviceDialog(DEV_DIALOG_ID_ICE);
}

void MainWindow::on_BTN_DEV_INFO_ROBOT_clicked(){
    ChangeDeviceDialog(DEV_DIALOG_ID_ROBOT);
}

void MainWindow::on_BTN_DEV_INFO_SYRUP_clicked(){
    ChangeDeviceDialog(DEV_DIALOG_ID_SYRUP);
}

void MainWindow::on_BTN_DEV_INFO_MONITOR_clicked(){
    ChangeDeviceDialog(DEV_DIALOG_ID_MONITOR);
}

void MainWindow::on_BTN_DEV_INFO_DOOR_clicked(){
    ChangeDeviceDialog(DEV_DIALOG_ID_DOOR);
}

void MainWindow::on_BTN_DEV_INFO_BARCODE_clicked(){
    ChangeDeviceDialog(DEV_DIALOG_ID_BARCODE);
}

void MainWindow::on_BTN_DEV_INFO_OUTLET_clicked(){
    ChangeDeviceDialog(DEV_DIALOG_ID_OUTLET);
}

void MainWindow::on_BTN_DEV_INFO_ICECREAM_clicked(){
    ChangeDeviceDialog(DEV_DIALOG_ID_ICECREAM);
}

void MainWindow::on_BTN_DEV_INFO_HOT_clicked(){
    ChangeDeviceDialog(DEV_DIALOG_ID_HOT);
}

void MainWindow::on_BTN_DEV_INFO_KIOSK_clicked(){
    ChangeDeviceDialog(DEV_DIALOG_ID_KIOSK);
}

void MainWindow::on_BTN_DEV_INFO_STOCK_clicked(){
    ChangeDeviceDialog(DEV_DIALOG_ID_STOCK);
}



void MainWindow::ClearForcedSuperError(){
    lan->SUPER_FATAL_ERROR_CONNECTION_OF_LAN2CAN = 0;

    robot->SUPER_FATAL_ERROR_ROBOT_DATA = 0;
    robot->SUPER_FATAL_ERROR_ROBOT_MISS_COMMAND_WORKING_CHECK = 0;
    outlet->SUPER_FATAL_ERROR_OUTLET_CONNECTION = 0;
    outlet->SUPER_FATAL_ERROR_OUTLET_CONTROL = 0;
    outlet->SUPER_FATAL_ERROR_OUTLET_SENSOR = 0;
    SUPER_FATAL_ERROR_PLATFORM_OPEN = 0;

    PLATFORM_OPENED_WHEN_OPERATING_FLAG = 0;
}

int MainWindow::CheckDeviceConnection(){
    if(robot->cmdConnectionStatus == false){
        return 1;
    }
    if(robot->dataConnectionStatus == false){
        return 2;
    }
    if(lan->sockConnectionStatus == false){
        return 3;
    }
    if(monitor->displayConnectionStatus == false){
        return 4;
    }
    return 0;
}

void MainWindow::on_BTN_DO_INITIALIZING_clicked(){
    QMessageBox::StandardButton msgBox;
    msgBox = QMessageBox::question(this,"초기화 시작",
                                   "초기화를 시작하시겠습니까?\n"
                                   "모든 음료 대기열이 사라집니다.");

    if(msgBox == QMessageBox::Yes){
        logger->write("[USER INPUT] INIT START");
        OP_STATUS_INITIALIZING = PLATFORM_INIT_START;
    }else{
        logger->write("[USER INPUT] INIT START CANCLE");
    }
}

void MainWindow::on_BTN_DO_OPERATING_clicked(){
    // Operate normally
    QMessageBox::StandardButton msgBox;
    msgBox = QMessageBox::question(this,"영업 시작",
                                   "영업을 시작하시겠습니까?\n");

    if(msgBox == QMessageBox::Yes){
        logger->write("[USER INPUT] PLATFORM OPERATION START");
        OP_STATUS_OPERATING = PLATFORM_OPERATION_START;
    }else{
        logger->write("[USER INPUT] PLATFORM OPERATION CANCLE");
    }
}

void MainWindow::on_BTN_STOP_OPERATING_clicked(){
    logger->write("[UI OPERATION] DO STOP OPERATION CLICKED");
    OP_COMMAND_STOP_OPERATING = 1;
}

void MainWindow::on_BTN_CANCEL_STOP_clicked(){
    logger->write("[UI OPERATION] CANCEL STOP OPERATION CLICKED");
    OP_COMMAND_STOP_OPERATING = 0;
}

void MainWindow::on_BTN_RESUME_clicked(){
    logger->write("[UI OPERATION] RESUME OPERATION CLICKED");
    PLATFORM_OPENED_WHEN_OPERATING_FLAG = 0;
}


void MainWindow::on_BTN_SETTING_clicked(){
    ChangeDeviceDialog(DEV_DIALOG_ID_SETTING);
}

void MainWindow::on_BTN_EXIT_clicked(){
    QMessageBox msgBox;
    msgBox.setText("프로그램을 종료하시겠습니까?");
    msgBox.setWindowTitle("프로그램 종료");
    msgBox.setStandardButtons(QMessageBox::Apply | QMessageBox::Retry | QMessageBox::Cancel);
    msgBox.setButtonText(QMessageBox::Apply, "종료");
    msgBox.setButtonText(QMessageBox::Retry, "다시 시작");
    msgBox.setButtonText(QMessageBox::Cancel, "취소");
    msgBox.setIcon(QMessageBox::Warning);
    msgBox.setStyleSheet("QLabel {font: 15pt \"함초롬돋움\";}"
                         "QComboBox{font: 10pt \"함초롬돋움\";\n	background-color: #ffffff\n}\n"
                         "QPushButton{\n	border-width: 2px; min-width: 100px; min-height: 50px; font: 13pt \"함초롬돋움\";\n	background-color: #ffffff\n}"
                         "QLineEdit{\n	font: 10pt \"함초롬돋움\";\n	background-color: #ffffff\n}");
    QTextCodec *codec = QTextCodec::codecForName("UTF-8");

    int ret = msgBox.exec();
    if(ret == QMessageBox::Apply){
        logger->write("[USER INPUT] EXIT : TERMINATE PROGRAM");
        QApplication::quit();
    }else if(ret == QMessageBox::Retry){
        logger->write("[USER INPUT] EXIT : RESTART PROGRAM");
        logger->write("[SYSTEM] RESTART CORE PROGRAM CLICKED");
        QProcess::startDetached(QApplication::applicationFilePath());
        QApplication::exit(12);
    }else{
        logger->write("[USER INPUT] EXIT : CANCEL");

    }
}

void MainWindow::on_BTN_UI_LOCK_clicked(){
    if(IS_UI_LOCK == true){
        logger->write("[USER INPUT] UI : UNLOCK");
        IS_UI_LOCK = false;
        ui->BTN_UI_LOCK->setIcon(QIcon(":/build/image/unlockw.png"));
    }else{
        logger->write("[USER INPUT] UI : LOCK");
        IS_UI_LOCK = true;
        ui->BTN_UI_LOCK->setIcon(QIcon(":/build/image/lockw.png"));
    }
}

void MainWindow::on_BTN_UI_UNLOCK_clicked(){
    IS_UI_LOCK = false;
}




void MainWindow::SendMail(QString content){
//    SmtpClient smtp("smtp.gmail.com", 587, SmtpClient::TlsConnection);//SmtpClient::SslConnection);
//    smtp.setUser("rainbow.coffeedelight@gmail.com");
//    smtp.setPassword("wuipgquhdqpthhxg");//"rainbow2011!");

//    MimeMessage message;

//    EmailAddress sender("rainbow.coffeedelight@gmail.com");
//    message.setSender(&sender);

//    EmailAddress to1("aa.com", "aa");
//    EmailAddress to2("bb.com", "bb");
//    EmailAddress to3("cc.com", "cc");
//    if(mail_infos.size() >= 1){
//        to1.setAddress(mail_infos[0].mail);
//        to1.setName(mail_infos[0].user);
//        message.addRecipient(&to1);
//    }
//    if(mail_infos.size() >= 2){
//        to2.setAddress(mail_infos[1].mail);
//        to2.setName(mail_infos[1].user);
//        message.addRecipient(&to2);
//    }
//    if(mail_infos.size() >= 3){
//        to3.setAddress(mail_infos[2].mail);
//        to3.setName(mail_infos[2].user);
//        message.addRecipient(&to3);
//    }
////    for(int i=0; i<mail_infos.size(); i++){
////        EmailAddress to_temp(mail_infos[i].mail, mail_infos[i].user);
////        message.addRecipient(&to_temp);
////        qDebug() << mail_infos[i].mail << mail_infos[i].user;
////    }

//    message.setSubject("[Coffee Delight 부산타워점] 에러리포트");
//    MimeText text;

//    text.setText(content);

//    message.addPart(&text);

//    if (!smtp.connectToHost()) {
//        qDebug() << "Failed to connect to host!" << endl;
//        return ;
//    }

//    if (!smtp.login()) {
//        qDebug() << "Failed to login!" << endl;
//        return ;
//    }

//    if (!smtp.sendMail(message)) {
//        qDebug() << "Failed to send mail!" << endl;
//        return ;
//    }
}



void MainWindow::on_BTN_CUP_ADD_DONE_clicked(){
    if(schedule->action_state == ACTION_STATE_CUP_ERROR){
        schedule->action_state = ACTION_STATE_CUP_RECOVER;
        logger->write("[UI OPERATION] CUP ADD DONE CLICKED");
    }
}
