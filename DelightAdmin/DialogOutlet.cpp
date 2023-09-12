#include "DialogOutlet.h"
#include "ui_DialogOutlet.h"
#include "RBLAN2CAN.h"
#include <QMessageBox>
#include "Scheduler.h"

extern Scheduler *pschedule;
extern Logger *plog;
extern RBLAN2CAN *plan;

DialogOutlet::DialogOutlet(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogOutlet)
{
    ui->setupUi(this);

    db = QSqlDatabase::addDatabase("QSQLITE", "DB_OUTLET");
    db.setDatabaseName(DB_NAME_OUTLET);

    LoadDatabase();


    for(int i=0; i<NUMBER_OF_OUTLET; i++){
        is_door_ready[i] = false;
        is_spin_ready[i] = false;

        DEBUG_ENCODER_COUNT_SPIN[i] = 0;
        DEBUG_ENCODER_COUNT_DOOR[i] = 0;
        DEBUG_SONAR_COUNT[i] = 0;

        init_state_door[i] = OUTLET_INIT_IDLE;
        OUTLET_DISABLE[i] = 0;
    }


    FATAL_INFO_CONNECTION_ERROR_1 = 0;
    FATAL_INFO_CONNECTION_ERROR_2 = 0;

    FATAL_INFO_OUTLET_1_SENSOR_ERROR = 0;
    FATAL_INFO_OUTLET_2_SENSOR_ERROR = 0;
    FATAL_INFO_OUTLET_1_SENSOR_WRONG_VALUE = 0;
    FATAL_INFO_OUTLET_2_SENSOR_WRONG_VALUE = 0;

    FATAL_INFO_SPIN_1_CONTROL_ERROR = 0;
    FATAL_INFO_SPIN_2_CONTROL_ERROR = 0;
    FATAL_INFO_DOOR_1_CONTROL_ERROR = 0;
    FATAL_INFO_DOOR_2_CONTROL_ERROR = 0;

    SUPER_FATAL_ERROR_OUTLET_CONNECTION = 0;
    SUPER_FATAL_ERROR_OUTLET_SENSOR = 0;
    SUPER_FATAL_ERROR_OUTLET_CONTROL = 0;


    connect(&timer, SIGNAL(timeout()), this, SLOT(onTimer()));
    timer.start(DOOR_HANDLER_LOOP_TIME);
}

DialogOutlet::~DialogOutlet()
{
    delete ui;
}

void DialogOutlet::CheckFatalError(){

    // FATAL INFORMATION=============================================
    // connection error
    if(OUTLET_DATA[0].connection_status == 0 && OUTLET_DISABLE[0] == 0){
        if(FATAL_INFO_CONNECTION_ERROR_1 == 0)
            plog->write("[OUTLET] ERROR : Disconnected 1");
        FATAL_INFO_CONNECTION_ERROR_1 = 1;
    }else{
        FATAL_INFO_CONNECTION_ERROR_1 = 0;
    }
    if(OUTLET_DATA[1].connection_status == 0 && OUTLET_DISABLE[1] == 0){
        if(FATAL_INFO_CONNECTION_ERROR_2 == 0)
            plog->write("[OUTLET] ERROR : Disconnected 2");
        FATAL_INFO_CONNECTION_ERROR_2 = 1;
    }else{
        FATAL_INFO_CONNECTION_ERROR_2 = 0;
    }

    // sensor error
    if(OUTLET_DATA[0].sonar_sensor_error == 1 && OUTLET_DISABLE[0] == 0){
        if(FATAL_INFO_OUTLET_1_SENSOR_ERROR == 0)
            plog->write("[OUTLET] ERROR : Sonar Sensor Error 1");
        FATAL_INFO_OUTLET_1_SENSOR_ERROR = 1;
    }else{
        FATAL_INFO_OUTLET_1_SENSOR_ERROR = 0;
    }
    if(OUTLET_DATA[1].sonar_sensor_error == 1 && OUTLET_DISABLE[1] == 0){
        if(FATAL_INFO_OUTLET_2_SENSOR_ERROR == 0)
            plog->write("[OUTLET] ERROR : Sonar Sensor Error 2");
        FATAL_INFO_OUTLET_2_SENSOR_ERROR = 1;
    }else{
        FATAL_INFO_OUTLET_2_SENSOR_ERROR = 0;
    }

    // wrong value 1
    if((OUTLET_DATA[0].sonar_sensor_data > 50) && (OUTLET_DATA[0].sonar_sensor_data < 250)){
        DEBUG_SONAR_COUNT[0]++;
    }else{
        DEBUG_SONAR_COUNT[0] = 0;
    }
    if(DEBUG_SONAR_COUNT[0] > 3000/DOOR_HANDLER_LOOP_TIME && OUTLET_DISABLE[0] == 0){
        if(FATAL_INFO_OUTLET_1_SENSOR_WRONG_VALUE == 0)
            plog->write("[OUTLET] ERROR : Wrong Value 1 -> "+QString().sprintf("%d",OUTLET_DATA[0].sonar_sensor_data));
        FATAL_INFO_OUTLET_1_SENSOR_WRONG_VALUE = 1;
    }else{
        FATAL_INFO_OUTLET_1_SENSOR_WRONG_VALUE = 0;
    }

    // wrong value 2
    if((OUTLET_DATA[1].sonar_sensor_data > 50) && (OUTLET_DATA[1].sonar_sensor_data < 250)){
        DEBUG_SONAR_COUNT[1]++;
    }else{
        DEBUG_SONAR_COUNT[1] = 0;
    }
    if(DEBUG_SONAR_COUNT[1] > 3000/DOOR_HANDLER_LOOP_TIME && OUTLET_DISABLE[1] == 0){
        if(FATAL_INFO_OUTLET_2_SENSOR_WRONG_VALUE == 0)
            plog->write("[OUTLET] ERROR : Wrong Value 2 -> "+QString().sprintf("%d",OUTLET_DATA[1].sonar_sensor_data));
        FATAL_INFO_OUTLET_2_SENSOR_WRONG_VALUE = 1;
    }else{
        FATAL_INFO_OUTLET_2_SENSOR_WRONG_VALUE = 0;
    }

    // control error
    if(DEBUG_ENCODER_COUNT_SPIN[0] > 5 && OUTLET_DISABLE[0] == 0){
        if(FATAL_INFO_SPIN_1_CONTROL_ERROR == 0)
            plog->write("[OUTLET] ERROR : SPIN 1 CONTROL");
        FATAL_INFO_SPIN_1_CONTROL_ERROR = 1;
    }else{
        FATAL_INFO_SPIN_1_CONTROL_ERROR = 0;
    }
    if(DEBUG_ENCODER_COUNT_DOOR[0] > 5 && OUTLET_DISABLE[0] == 0){
        if(FATAL_INFO_DOOR_1_CONTROL_ERROR == 0)
            plog->write("[OUTLET] ERROR : DOOR 1 CONTROL");
        FATAL_INFO_DOOR_1_CONTROL_ERROR = 1;
    }else{
        FATAL_INFO_DOOR_1_CONTROL_ERROR = 0;
    }
    if(DEBUG_ENCODER_COUNT_SPIN[1] > 5 && OUTLET_DISABLE[1] == 0){
        if(FATAL_INFO_SPIN_2_CONTROL_ERROR == 0)
            plog->write("[OUTLET] ERROR : SPIN 2 CONTROL");
        FATAL_INFO_SPIN_2_CONTROL_ERROR = 1;
    }else{
        FATAL_INFO_SPIN_2_CONTROL_ERROR = 0;
    }
    if(DEBUG_ENCODER_COUNT_DOOR[1] > 5 && OUTLET_DISABLE[1] == 0){
        if(FATAL_INFO_DOOR_2_CONTROL_ERROR == 0)
            plog->write("[OUTLET] ERROR : DOOR 2 CONTROL");
        FATAL_INFO_DOOR_2_CONTROL_ERROR = 1;
    }else{
        FATAL_INFO_DOOR_2_CONTROL_ERROR = 0;
    }


    // FATAL ERROR ===================================================
    if(OP_STATUS_OPERATING == PLATFORM_OPERATION_ON_OPERATING_STATE){
        if(FATAL_INFO_CONNECTION_ERROR_1 == 1 || FATAL_INFO_CONNECTION_ERROR_2 == 1){
            SUPER_FATAL_ERROR_OUTLET_CONNECTION = 1;
        }

        if(FATAL_INFO_OUTLET_1_SENSOR_ERROR == 1 || FATAL_INFO_OUTLET_2_SENSOR_ERROR == 1 ||
            FATAL_INFO_OUTLET_1_SENSOR_WRONG_VALUE == 1 || FATAL_INFO_OUTLET_2_SENSOR_WRONG_VALUE == 1){
            SUPER_FATAL_ERROR_OUTLET_SENSOR = 1;
        }

        if(FATAL_INFO_SPIN_1_CONTROL_ERROR == 1 || FATAL_INFO_SPIN_2_CONTROL_ERROR == 1 ||
            FATAL_INFO_DOOR_1_CONTROL_ERROR == 1 || FATAL_INFO_DOOR_2_CONTROL_ERROR == 1){
            SUPER_FATAL_ERROR_OUTLET_CONTROL = 1;
        }
    }
}



void DialogOutlet::onTimer(){
    if(IS_UI_LOCK){
        ui->GB_OUTLET->setEnabled(false);
    }else{
        ui->GB_OUTLET->setEnabled(true);
    }

    InitOutletHandler();


    if(plan->sockConnectionStatus == false){
        SetLEColor(ui->LE_OUTLET_CONNECTION_1, COLOR_UNDETERMINED);
        SetLEColor(ui->LE_OUTLET_CONNECTION_2, COLOR_UNDETERMINED);

        SetLEColor(ui->LE_OUTLET_1_MOVING_OK, COLOR_UNDETERMINED);
        SetLEColor(ui->LE_OUTLET_1_MOVING_NOK, COLOR_UNDETERMINED);
        SetLEColor(ui->LE_OUTLET_1_CUP_OK, COLOR_UNDETERMINED);
        SetLEColor(ui->LE_OUTLET_1_CUP_NOK, COLOR_UNDETERMINED);

        SetLEColor(ui->LE_OUTLET_2_MOVING_OK, COLOR_UNDETERMINED);
        SetLEColor(ui->LE_OUTLET_2_MOVING_NOK, COLOR_UNDETERMINED);
        SetLEColor(ui->LE_OUTLET_2_CUP_OK, COLOR_UNDETERMINED);
        SetLEColor(ui->LE_OUTLET_2_CUP_NOK, COLOR_UNDETERMINED);

        SetLEColor(ui->LE_INIT_STAT_DOOR_1, COLOR_UNDETERMINED);
        SetLEColor(ui->LE_MOVING_STAT_DOOR_1, COLOR_UNDETERMINED);
        SetLEColor(ui->LE_INIT_STAT_SPIN_1, COLOR_UNDETERMINED);
        SetLEColor(ui->LE_MOVING_STAT_SPIN_1, COLOR_UNDETERMINED);

        SetLEColor(ui->LE_INIT_STAT_DOOR_2, COLOR_UNDETERMINED);
        SetLEColor(ui->LE_MOVING_STAT_DOOR_2, COLOR_UNDETERMINED);
        SetLEColor(ui->LE_INIT_STAT_SPIN_2, COLOR_UNDETERMINED);
        SetLEColor(ui->LE_MOVING_STAT_SPIN_2, COLOR_UNDETERMINED);

        ui->LE_POSITION_DOOR_1->setText("-");
        ui->LE_POSITION_SPIN_1->setText("-");
        ui->LE_POSITION_DOOR_2->setText("-");
        ui->LE_POSITION_SPIN_2->setText("-");

        ui->LE_CURRENT_DOOR_1->setText("-");
        ui->LE_CURRENT_SPIN_1->setText("-");
        ui->LE_CURRENT_DOOR_2->setText("-");
        ui->LE_CURRENT_SPIN_2->setText("-");

    }else{
        CheckFatalError();


        if(OUTLET_DATA[0].connection_status == 1){
            SetLEColor(ui->LE_OUTLET_CONNECTION_1, COLOR_GOOD);
        }else{
            SetLEColor(ui->LE_OUTLET_CONNECTION_1, COLOR_BAD);
        }
        if(OUTLET_DATA[1].connection_status == 1){
            SetLEColor(ui->LE_OUTLET_CONNECTION_2, COLOR_GOOD);
        }else{
            SetLEColor(ui->LE_OUTLET_CONNECTION_2, COLOR_BAD);
        }

        // TODO
        if(IsModuleMoving(0) == 1 || IsModuleRunning(0) == 1){
            SetLEColor(ui->LE_OUTLET_1_MOVING_OK, COLOR_BLUE);
            SetLEColor(ui->LE_OUTLET_1_MOVING_NOK, COLOR_NONE);
        }else{
            SetLEColor(ui->LE_OUTLET_1_MOVING_OK, COLOR_NONE);
            SetLEColor(ui->LE_OUTLET_1_MOVING_NOK, COLOR_BLUE);
        }

        if(IsModuleMoving(1) == 1 || IsModuleRunning(1) == 1){
            SetLEColor(ui->LE_OUTLET_2_MOVING_OK, COLOR_BLUE);
            SetLEColor(ui->LE_OUTLET_2_MOVING_NOK, COLOR_NONE);
        }else{
            SetLEColor(ui->LE_OUTLET_2_MOVING_OK, COLOR_NONE);
            SetLEColor(ui->LE_OUTLET_2_MOVING_NOK, COLOR_BLUE);
        }

        if(OUTLET_DATA[0].sonar_sensor_data < OUTLET_SONAR_SENSOR_THRESHOLD){
            SetLEColor(ui->LE_OUTLET_1_CUP_OK, COLOR_BLUE);
            SetLEColor(ui->LE_OUTLET_1_CUP_NOK, COLOR_NONE);
        }else{
            SetLEColor(ui->LE_OUTLET_1_CUP_OK, COLOR_NONE);
            SetLEColor(ui->LE_OUTLET_1_CUP_NOK, COLOR_BLUE);
        }
        if(OUTLET_DATA[1].sonar_sensor_data < OUTLET_SONAR_SENSOR_THRESHOLD){
            SetLEColor(ui->LE_OUTLET_2_CUP_OK, COLOR_BLUE);
            SetLEColor(ui->LE_OUTLET_2_CUP_NOK, COLOR_NONE);
        }else{
            SetLEColor(ui->LE_OUTLET_2_CUP_OK, COLOR_NONE);
            SetLEColor(ui->LE_OUTLET_2_CUP_NOK, COLOR_BLUE);
        }

        if(OUTLET_DATA[0].init_status[0] == 1){
            SetLEColor(ui->LE_INIT_STAT_SPIN_1, COLOR_GOOD);
        }else{
            SetLEColor(ui->LE_INIT_STAT_SPIN_1, COLOR_BAD);
        }
        if(OUTLET_DATA[0].init_status[1] == 1){
            SetLEColor(ui->LE_INIT_STAT_DOOR_1, COLOR_GOOD);
        }else{
            SetLEColor(ui->LE_INIT_STAT_DOOR_1, COLOR_BAD);
        }

        if(OUTLET_DATA[1].init_status[0] == 1){
            SetLEColor(ui->LE_INIT_STAT_SPIN_2, COLOR_GOOD);
        }else{
            SetLEColor(ui->LE_INIT_STAT_SPIN_2, COLOR_BAD);
        }
        if(OUTLET_DATA[1].init_status[1] == 1){
            SetLEColor(ui->LE_INIT_STAT_DOOR_2, COLOR_GOOD);
        }else{
            SetLEColor(ui->LE_INIT_STAT_DOOR_2, COLOR_BAD);
        }


        if(OUTLET_DATA[0].operating_status[0] == 1){
            SetLEColor(ui->LE_MOVING_STAT_SPIN_1, COLOR_BLUE);
        }else{
            SetLEColor(ui->LE_MOVING_STAT_SPIN_1, COLOR_NONE);
        }
        if(OUTLET_DATA[0].operating_status[1] == 1){
            SetLEColor(ui->LE_MOVING_STAT_DOOR_1, COLOR_BLUE);
        }else{
            SetLEColor(ui->LE_MOVING_STAT_DOOR_1, COLOR_NONE);
        }

        if(OUTLET_DATA[1].operating_status[0] == 1){
            SetLEColor(ui->LE_MOVING_STAT_SPIN_2, COLOR_BLUE);
        }else{
            SetLEColor(ui->LE_MOVING_STAT_SPIN_2, COLOR_NONE);
        }
        if(OUTLET_DATA[1].operating_status[1] == 1){
            SetLEColor(ui->LE_MOVING_STAT_DOOR_2, COLOR_BLUE);
        }else{
            SetLEColor(ui->LE_MOVING_STAT_DOOR_2, COLOR_NONE);
        }

        ui->LE_POSITION_SPIN_1->setText(QString().sprintf("%d", OUTLET_DATA[0].position[0]));
        ui->LE_POSITION_DOOR_1->setText(QString().sprintf("%d", OUTLET_DATA[0].position[1]));
        ui->LE_POSITION_SPIN_2->setText(QString().sprintf("%d", OUTLET_DATA[1].position[0]));
        ui->LE_POSITION_DOOR_2->setText(QString().sprintf("%d", OUTLET_DATA[1].position[1]));

        ui->LE_CURRENT_SPIN_1->setText(QString().sprintf("%d", OUTLET_DATA[0].current[0]));
        ui->LE_CURRENT_DOOR_1->setText(QString().sprintf("%d", OUTLET_DATA[0].current[1]));
        ui->LE_CURRENT_SPIN_2->setText(QString().sprintf("%d", OUTLET_DATA[1].current[0]));
        ui->LE_CURRENT_DOOR_2->setText(QString().sprintf("%d", OUTLET_DATA[1].current[1]));

        if(OUTLET_DATA[0].cell_state[0] == CELL_OCC){
            ui->LE_OCCUPY_OUTLET_1_CELL_1->setText(OUTLET_DATA[0].cell_occupy_pin[0]);
        }else{
            ui->LE_OCCUPY_OUTLET_1_CELL_1->setText("-");
        }
        if(OUTLET_DATA[0].cell_state[1] == CELL_OCC){
            ui->LE_OCCUPY_OUTLET_1_CELL_2->setText(OUTLET_DATA[0].cell_occupy_pin[1]);
        }else{
            ui->LE_OCCUPY_OUTLET_1_CELL_2->setText("-");
        }
        if(OUTLET_DATA[0].cell_state[2] == CELL_OCC){
            ui->LE_OCCUPY_OUTLET_1_CELL_3->setText(OUTLET_DATA[0].cell_occupy_pin[2]);
        }else{
            ui->LE_OCCUPY_OUTLET_1_CELL_3->setText("-");
        }

        if(OUTLET_DATA[1].cell_state[0] == CELL_OCC){
            ui->LE_OCCUPY_OUTLET_2_CELL_1->setText(OUTLET_DATA[1].cell_occupy_pin[0]);
        }else{
            ui->LE_OCCUPY_OUTLET_2_CELL_1->setText("-");
        }
        if(OUTLET_DATA[1].cell_state[1] == CELL_OCC){
            ui->LE_OCCUPY_OUTLET_2_CELL_2->setText(OUTLET_DATA[1].cell_occupy_pin[1]);
        }else{
            ui->LE_OCCUPY_OUTLET_2_CELL_2->setText("-");
        }
        if(OUTLET_DATA[1].cell_state[2] == CELL_OCC){
            ui->LE_OCCUPY_OUTLET_2_CELL_3->setText(OUTLET_DATA[1].cell_occupy_pin[2]);
        }else{
            ui->LE_OCCUPY_OUTLET_2_CELL_3->setText("-");
        }
    }

    if(OUTLET_DISABLE[0] == 1){
        SetBTNColor(ui->BTN_ENABLE_MODULE_1,COLOR_BAD);
        ui->BTN_ENABLE_MODULE_1->setText("사용안함");
    }else{
        SetBTNColor(ui->BTN_ENABLE_MODULE_1,COLOR_GOOD);
        ui->BTN_ENABLE_MODULE_1->setText("사용중");
    }

    if(OUTLET_DISABLE[1] == 1){
        SetBTNColor(ui->BTN_ENABLE_MODULE_2,COLOR_BAD);
        ui->BTN_ENABLE_MODULE_2->setText("사용안함");
    }else{
        SetBTNColor(ui->BTN_ENABLE_MODULE_2,COLOR_GOOD);
        ui->BTN_ENABLE_MODULE_2->setText("사용중");
    }
}


void DialogOutlet::LoadDatabase(){
    if(!db.open()){
        qDebug() << "Load Outlet Database Fail";
        return;
    }

    QSqlQuery query(db);
    if(query.exec("SELECT * FROM Table_Outlet")){
        int outlet_num = 0;
        while(query.next()){
            int pos_exit1 = query.value("exit1").toInt();
            int pos_exit2 = query.value("exit2").toInt();
            int pos_exit3 = query.value("exit3").toInt();
            int pos_load1 = query.value("load1").toInt();
            int pos_load2 = query.value("load2").toInt();
            int pos_load3 = query.value("load3").toInt();
            int pos_open = query.value("open").toInt();
            int pos_close = query.value("close").toInt();

            CELL_POS_EXIT_1[outlet_num] = pos_exit1;
            CELL_POS_EXIT_2[outlet_num] = pos_exit2;
            CELL_POS_EXIT_3[outlet_num] = pos_exit3;

            CELL_POS_LOAD_1[outlet_num] = pos_load1;
            CELL_POS_LOAD_2[outlet_num] = pos_load2;
            CELL_POS_LOAD_3[outlet_num] = pos_load3;

            OPEN_POS_DOOR[outlet_num] = pos_open;
            CLOSE_POS_DOOR[outlet_num] = pos_close;

            outlet_num++;
        }
    }
    db.close();
}


void DialogOutlet::InitOutletHandler(){
    static int timeout_door[NUMBER_OF_OUTLET] = {0};
    static int timeout_spin[NUMBER_OF_OUTLET] = {0};
    static int cnt_repeat_door[NUMBER_OF_OUTLET] = {0};
    static int cnt_repeat_spin[NUMBER_OF_OUTLET] = {0};
    static int pos_cell[NUMBER_OF_OUTLET] = {0};

    for(int i=0; i<NUMBER_OF_OUTLET; i++){

        if(OUTLET_DISABLE[i] == 1)
            continue;

        switch(init_state_door[i]){
        case OUTLET_INIT_IDLE:
            break;

        case OUTLET_INIT_START:

            plog->write("[OUTLET] DOOR INIT PROCESS : START");
            is_door_ready[i] = 0;
            cnt_repeat_door[i] = 0;
            init_state_door[i] = OUTLET_INIT_FIND_HOME;
            break;

        case OUTLET_INIT_FIND_HOME:
            plog->write("[OUTLET] DOOR INIT PROCESS : FIND HOME");
            FindHome(i, OUTLET_DOOR);
            timeout_door[i] = 1000/DOOR_HANDLER_LOOP_TIME;
            init_state_door[i] = OUTLET_INIT_CHECK_FIND_HOME_DONE;
            break;

        case OUTLET_INIT_CHECK_FIND_HOME_DONE:
            if(--timeout_door[i] > 0)
                break;

            if(OUTLET_DATA[i].init_status[OUTLET_DOOR] == 0){
                if(MOTOR_COL_ERROR(OUTLET_DATA[i].status[OUTLET_DOOR]) == 1){
                    timeout_door[i] = 5000/DOOR_HANDLER_LOOP_TIME;
                    init_state_door[i] = OUTLET_INIT_FIND_HOME_COLLISION;
                    plog->write("[OUTLET] DOOR INIT PROCESS : DOOR COLLISION ERROR "+QString().sprintf("%d",i));
                    break;
                }
                break;
            }
            plog->write("[OUTLET] DOOR INIT PROCESS : FIND HOME SUCCESS "+QString().sprintf("%d",i));
            init_state_door[i] = OUTLET_INIT_DONE;
            break;

        case OUTLET_INIT_FIND_HOME_COLLISION:
            if(--timeout_door[i] > 0)
                break;

            if(cnt_repeat_door[i] > 3){
                plog->write("[OUTLET] DOOR INIT PROCESS : FAIL COLLISION "+QString().sprintf("%d",i));
                init_state_door[i] = OUTLET_INIT_CALL_MANAGER;
                break;
            }
            cnt_repeat_door[i]++;
            init_state_door[i] = OUTLET_INIT_FIND_HOME;
            break;

        case OUTLET_INIT_DONE:
            plog->write("[OUTLET] DOOR INIT PROCESS : SUCCESS "+QString().sprintf("%d",i));
            init_state_door[i] = OUTLET_INIT_IDLE;
            is_door_ready[i] = true;
            break;

        case OUTLET_INIT_CALL_MANAGER:
            is_door_ready[i] = false;
            break;

        default:
            break;
        }


        switch(init_state_spin[i]){
        case OUTLET_INIT_IDLE:
            break;
        case OUTLET_INIT_START:
            plog->write("[OUTLET] SPIN INIT PROCESS : START ");
            is_spin_ready[i] = 0;
            cnt_repeat_spin[i] = 0;
            init_state_spin[i] = OUTLET_INIT_FIND_HOME;
            break;

        case OUTLET_INIT_FIND_HOME:
            FindHome(i, OUTLET_SPIN);

            // reset pos_cell
            pos_cell[i] = 0;

            timeout_spin[i] = 1000/DOOR_HANDLER_LOOP_TIME;
            init_state_spin[i] = OUTLET_INIT_CHECK_FIND_HOME_DONE;
            break;

        case OUTLET_INIT_CHECK_FIND_HOME_DONE:
            if(--timeout_spin[i] > 0)
                break;

            if(OUTLET_DATA[i].init_status[OUTLET_SPIN] == 0){
                if(MOTOR_COL_ERROR(OUTLET_DATA[i].status[OUTLET_SPIN]) == 1){
                    plog->write("[OUTLET] SPIN INIT PROCESS : COLLISION "+QString().sprintf("%d",i));
                    timeout_spin[i] = 2000/DOOR_HANDLER_LOOP_TIME;
                    init_state_spin[i] = OUTLET_INIT_FIND_HOME_COLLISION;
                    break;
                }
                break;
            }
            plog->write("[OUTLET] SPIN INIT PROCESS : FINE HOME SUCCESS "+QString().sprintf("%d",i));
            init_state_spin[i] = OUTLET_INIT_ROTATE_TURNTABLE;
            break;

        case OUTLET_INIT_FIND_HOME_COLLISION:
            if(--timeout_spin[i] > 0)
                break;

            if(cnt_repeat_spin[i] > 3){
                plog->write("[OUTLET] SPIN INIT PROCESS : FAIL "+QString().sprintf("%d",i));
                init_state_spin[i] = OUTLET_INIT_CALL_MANAGER;
                break;
            }

            cnt_repeat_spin[i]++;
            init_state_spin[i] = OUTLET_INIT_FIND_HOME;
            break;

        case OUTLET_INIT_ROTATE_TURNTABLE:
            plog->write("[OUTLET] SPIN INIT PROCESS : CHECK TURNTABLE "+QString().sprintf("%d",i));
            SpinToExit(i, pos_cell[i]);
            timeout_spin[i] = 1000/DOOR_HANDLER_LOOP_TIME;
            init_state_spin[i] = OUTLET_INIT_CHECK_CELL_WAIT;
            break;

        case OUTLET_INIT_CHECK_CELL_WAIT:
            if(--timeout_spin[i] > 0)
                break;
            if(OUTLET_DATA[i].is_moving[OUTLET_SPIN] == true)
                break;

            timeout_spin[i] = 1000/DOOR_HANDLER_LOOP_TIME;
            init_state_spin[i] = OUTLET_INIT_CHECK_CELL;
            break;

        case OUTLET_INIT_CHECK_CELL:
            if(--timeout_spin[i] > 0)
                break;

            if(OUTLET_DATA[i].sonar_sensor_data < OUTLET_SONAR_SENSOR_THRESHOLD){
                plog->write("[OUTLET] SPIN INIT PROCESS "+QString().sprintf("%d",i)+QString().sprintf(" : CELL(%d) IS OCC ",pos_cell[i]));
                OUTLET_DATA[i].cell_state[pos_cell[i]] = CELL_OCC;
                OUTLET_DATA[i].cell_occupy_pin[pos_cell[i]] = "-9999";
            }else{
                OUTLET_DATA[i].cell_state[pos_cell[i]] = CELL_EMP;
                OUTLET_DATA[i].cell_occupy_pin[pos_cell[i]] = "";
            }

            if(pos_cell[i] >= NUMBER_OF_CELL-1){
                init_state_spin[i] = OUTLET_INIT_DONE;
            }else{
                pos_cell[i]++;
                init_state_spin[i] = OUTLET_INIT_ROTATE_TURNTABLE;
            }
            break;

        case OUTLET_INIT_DONE:
            plog->write("[OUTLET] SPIN INIT PROCESS "+QString().sprintf("%d",i)+" : SUCCESS");
            init_state_spin[i] = OUTLET_INIT_IDLE;
            is_spin_ready[i] = true;
            break;

        case OUTLET_INIT_CALL_MANAGER:
            is_spin_ready[i] = false;
            break;

        default:
            break;
        }
    }
}

bool DialogOutlet::isError(int id_module){
    if(OUTLET_DISABLE[id_module] == 0){
        if(OUTLET_DATA[id_module].connection_status == 0 || OUTLET_DATA[id_module].sonar_sensor_error == 1)
            return true;

        if(DEBUG_ENCODER_COUNT_SPIN[id_module] > 5 || DEBUG_ENCODER_COUNT_DOOR[id_module] > 5 || DEBUG_SONAR_COUNT[id_module] > 30)
            return true;
    }

    return false;
}

void DialogOutlet::ErrorClear(){
    FATAL_INFO_CONNECTION_ERROR_1 = 0;
    FATAL_INFO_CONNECTION_ERROR_2 = 0;

    FATAL_INFO_OUTLET_1_SENSOR_ERROR = 0;
    FATAL_INFO_OUTLET_2_SENSOR_ERROR = 0;
    FATAL_INFO_OUTLET_1_SENSOR_WRONG_VALUE = 0;
    FATAL_INFO_OUTLET_2_SENSOR_WRONG_VALUE = 0;

    FATAL_INFO_SPIN_1_CONTROL_ERROR = 0;
    FATAL_INFO_SPIN_2_CONTROL_ERROR = 0;
    FATAL_INFO_DOOR_1_CONTROL_ERROR = 0;
    FATAL_INFO_DOOR_2_CONTROL_ERROR = 0;

    SUPER_FATAL_ERROR_OUTLET_CONNECTION = 0;
    SUPER_FATAL_ERROR_OUTLET_SENSOR = 0;
    SUPER_FATAL_ERROR_OUTLET_CONTROL = 0;

    DEBUG_ENCODER_COUNT_SPIN[0] = 0;
    DEBUG_ENCODER_COUNT_SPIN[1] = 0;
    DEBUG_ENCODER_COUNT_DOOR[0] = 0;
    DEBUG_ENCODER_COUNT_DOOR[1] = 0;
    DEBUG_SONAR_COUNT[0] = 0;
    DEBUG_SONAR_COUNT[1] = 0;

}
void DialogOutlet::FindHome(int target, int spin_door){
    plog->write("[OUTLET] FIND HOME "+QString().sprintf(" : target(%d) spin_door(%d)",target, spin_door));
    if(spin_door == OUTLET_SPIN){
        plan->SendControlData(DEV_SEND_ID_OUTLET, target, 0x01, spin_door, 0);
    }else{
        plan->SendControlData(DEV_SEND_ID_OUTLET, target, 0x01, spin_door, OPEN_POS_DOOR[target]);
    }
}

void DialogOutlet::GoPosition(int target, int spin_door, int position){
    plog->write("[OUTLET] GoPosition "+QString().sprintf(" : target(%d) spin_door(%d) position(%d)",target, spin_door,position));
    plan->SendControlData(DEV_SEND_ID_OUTLET, target, 0x02, spin_door, position);
}

void DialogOutlet::SetVelocity(int target, int spin_door, int velocity){
    plog->write("[OUTLET] SetVelocity "+QString().sprintf(" : target(%d) spin_door(%d) velocity(%d)",target, spin_door,velocity));
    plan->SendControlData(DEV_SEND_ID_OUTLET, target, 0x03, spin_door, velocity);
}

void DialogOutlet::EncoderZero(int target, int spin_door){
    plog->write("[OUTLET] EncoderZero "+QString().sprintf(" : target(%d) spin_door(%d)",target, spin_door));
    plan->SendControlData(DEV_SEND_ID_OUTLET, target,  0x04, spin_door, 0);
}


void DialogOutlet::on_BTN_FIND_HOME_SPIN_1_clicked(){
    FindHome(0, OUTLET_SPIN);
    plog->write("[UI OPERATION - OUTLET] 모터 원점 스핀 1");
}
void DialogOutlet::on_BTN_FIND_HOME_DOOR_1_clicked(){
    FindHome(0, OUTLET_DOOR);
    plog->write("[UI OPERATION - OUTLET] 모터 원점 문 1");
}
void DialogOutlet::on_BTN_FIND_HOME_SPIN_2_clicked(){
    FindHome(1, OUTLET_SPIN);
    plog->write("[UI OPERATION - OUTLET] 모터 원점 스핀 2");
}
void DialogOutlet::on_BTN_FIND_HOME_DOOR_2_clicked(){
    FindHome(1, OUTLET_DOOR);
    plog->write("[UI OPERATION - OUTLET] 모터 원점 문 2");
}

void DialogOutlet::on_BTN_MOVE_SPIN_1_TO_CELL_LOAD_1_clicked(){
    GoPosition(0, OUTLET_SPIN, CELL_POS_LOAD_1[0]);
    plog->write("[UI OPERATION - OUTLET] 스핀 1-1 로드");
}
void DialogOutlet::on_BTN_MOVE_SPIN_1_TO_CELL_LOAD_2_clicked(){
    GoPosition(0, OUTLET_SPIN, CELL_POS_LOAD_2[0]);
    plog->write("[UI OPERATION - OUTLET] 스핀 1-2 로드");
}
void DialogOutlet::on_BTN_MOVE_SPIN_1_TO_CELL_LOAD_3_clicked(){
    GoPosition(0, OUTLET_SPIN, CELL_POS_LOAD_3[0]);
    plog->write("[UI OPERATION - OUTLET] 스핀 1-3 로드");
}

void DialogOutlet::on_BTN_MOVE_SPIN_1_TO_CELL_OUT_1_clicked(){
    GoPosition(0, OUTLET_SPIN, CELL_POS_EXIT_1[0]);
    plog->write("[UI OPERATION - OUTLET] 스핀 1-1 배출");
}
void DialogOutlet::on_BTN_MOVE_SPIN_1_TO_CELL_OUT_2_clicked(){
    GoPosition(0, OUTLET_SPIN, CELL_POS_EXIT_2[0]);
    plog->write("[UI OPERATION - OUTLET] 스핀 1-2 배출");
}
void DialogOutlet::on_BTN_MOVE_SPIN_1_TO_CELL_OUT_3_clicked(){
    GoPosition(0, OUTLET_SPIN, CELL_POS_EXIT_3[0]);
    plog->write("[UI OPERATION - OUTLET] 스핀 1-3 배출");
}

void DialogOutlet::on_BTN_MOVE_SPIN_2_TO_CELL_LOAD_1_clicked(){
    GoPosition(1, OUTLET_SPIN, CELL_POS_LOAD_1[1]);
    plog->write("[UI OPERATION - OUTLET] 스핀 2-1 로드");
}
void DialogOutlet::on_BTN_MOVE_SPIN_2_TO_CELL_LOAD_2_clicked(){
    GoPosition(1, OUTLET_SPIN, CELL_POS_LOAD_2[1]);
    plog->write("[UI OPERATION - OUTLET] 스핀 2-2 로드");
}
void DialogOutlet::on_BTN_MOVE_SPIN_2_TO_CELL_LOAD_3_clicked(){
    GoPosition(1, OUTLET_SPIN, CELL_POS_LOAD_3[1]);
    plog->write("[UI OPERATION - OUTLET] 스핀 2-3 로드");
}

void DialogOutlet::on_BTN_MOVE_SPIN_2_TO_CELL_OUT_1_clicked(){
    GoPosition(1, OUTLET_SPIN, CELL_POS_EXIT_1[1]);
    plog->write("[UI OPERATION - OUTLET] 스핀 2-1 배출");
}
void DialogOutlet::on_BTN_MOVE_SPIN_2_TO_CELL_OUT_2_clicked(){
    GoPosition(1, OUTLET_SPIN, CELL_POS_EXIT_2[1]);
    plog->write("[UI OPERATION - OUTLET] 스핀 2-2 배출");
}
void DialogOutlet::on_BTN_MOVE_SPIN_2_TO_CELL_OUT_3_clicked(){
    GoPosition(1, OUTLET_SPIN, CELL_POS_EXIT_3[1]);
    plog->write("[UI OPERATION - OUTLET] 스핀 2-3 배출");
}

void DialogOutlet::on_BTN_MOVE_DOOR_1_TO_OPEN_POS_clicked(){
    GoPosition(0, OUTLET_DOOR, OPEN_POS_DOOR[0]);
    plog->write("[UI OPERATION - OUTLET] 문 1 열기");
}
void DialogOutlet::on_BTN_MOVE_DOOR_1_TO_CLOSE_POS_clicked(){
    GoPosition(0, OUTLET_DOOR, CLOSE_POS_DOOR[0]);
    plog->write("[UI OPERATION - OUTLET] 문 1 닫기");
}
void DialogOutlet::on_BTN_MOVE_DOOR_2_TO_OPEN_POS_clicked(){
    GoPosition(1, OUTLET_DOOR, OPEN_POS_DOOR[1]);
    plog->write("[UI OPERATION - OUTLET] 문 2 열기");
}
void DialogOutlet::on_BTN_MOVE_DOOR_2_TO_CLOSE_POS_clicked(){
    GoPosition(1, OUTLET_DOOR, CLOSE_POS_DOOR[1]);
    plog->write("[UI OPERATION - OUTLET] 문 2 닫기");
}




int DialogOutlet::IsOutletFull(){
    int count = 0;
    for(int i=0; i<NUMBER_OF_OUTLET; i++){
        for(int j=0; j<NUMBER_OF_CELL; j++){
            if(OUTLET_DATA[i].cell_state[j] == CELL_OCC){
                count++;
            }
        }
    }
    if(count >= 5){ // one cell for shelve drink out
        return true;
    }else{
        return false;
    }
}

ST_OUTLET_CELL_INFO DialogOutlet::GetFreeCellInfo(){
    static unsigned int cnt = 0;

    ST_OUTLET_CELL_INFO outlet_cell_info;

    for(int i=0; i<NUMBER_OF_OUTLET; i++){
        int index = (cnt+i)%NUMBER_OF_OUTLET;
        if(OUTLET_DISABLE[index] == 0 && OUTLET_DATA[index].is_moving[0] == false && OUTLET_DATA[index].is_moving[1] == false && OUTLET_DATA[index].is_running == false){
            for(int j=0; j<NUMBER_OF_CELL; j++){
                if(OUTLET_DATA[index].cell_state[j] == CELL_EMP){
                    outlet_cell_info.id_module = index;
                    outlet_cell_info.id_cell = j;
                    cnt++;
                    return outlet_cell_info;
                }
            }
        }
    }

    outlet_cell_info.id_module = -1;
    outlet_cell_info.id_cell = -1;
    return outlet_cell_info;
}

int DialogOutlet::GetFreeModuleInfo(){
    for(int i=0; i<NUMBER_OF_OUTLET; i++){
        int is_module_empty = true;
        for(int j=0; j<NUMBER_OF_CELL; j++){
            if(OUTLET_DATA[i].cell_state[j] == CELL_OCC){
                is_module_empty = false;
                break;
            }
        }

        if(is_module_empty)
            return i;
    }

    return -1;
}

void DialogOutlet::SetModuleRunning(int id_module, bool is_running){
    OUTLET_DATA[id_module].is_running = is_running;
}
bool DialogOutlet::IsModuleRunning(int id_module){
    return OUTLET_DATA[id_module].is_running;
}
bool DialogOutlet::IsModuleMoving(int id_module){
    return (OUTLET_DATA[id_module].is_moving[0] || OUTLET_DATA[id_module].is_moving[1]);
}
void DialogOutlet::SetCellOccupancy(int id_module, int id_cell, int occupancy, QString pin){
    OUTLET_DATA[id_module].cell_state[id_cell] = occupancy;
    OUTLET_DATA[id_module].cell_occupy_pin[id_cell] = pin;
}

void DialogOutlet::SpinToLoad(int id_module, int id_cell){
    if(id_cell == 0){
        GoPosition(id_module, OUTLET_SPIN, CELL_POS_LOAD_1[id_module]);
    }else if(id_cell == 1){
        GoPosition(id_module, OUTLET_SPIN, CELL_POS_LOAD_2[id_module]);
    }else if(id_cell == 2){
        GoPosition(id_module, OUTLET_SPIN, CELL_POS_LOAD_3[id_module]);
    }
}
void DialogOutlet::SpinToExit(int id_module, int id_cell){
    if(id_cell == 0){
        GoPosition(id_module, OUTLET_SPIN, CELL_POS_EXIT_1[id_module]);
    }else if(id_cell == 1){
        GoPosition(id_module, OUTLET_SPIN, CELL_POS_EXIT_2[id_module]);
    }else if(id_cell == 2){
        GoPosition(id_module, OUTLET_SPIN, CELL_POS_EXIT_3[id_module]);
    }
}

void DialogOutlet::OpenDoor(int id_module){
    GoPosition(id_module, OUTLET_DOOR, OPEN_POS_DOOR[id_module]);
}
void DialogOutlet::CloseDoor(int id_module){
    GoPosition(id_module, OUTLET_DOOR, CLOSE_POS_DOOR[id_module]);
}

bool DialogOutlet::CheckSpinInLoadPos(int id_module, int id_cell){
    int load_pos;
    if(id_cell == 0){
        load_pos = CELL_POS_LOAD_1[id_module];
    }else if(id_cell == 1){
        load_pos = CELL_POS_LOAD_2[id_module];
    }else if(id_cell == 2){
        load_pos = CELL_POS_LOAD_3[id_module];
    }

    if(abs(load_pos - OUTLET_DATA[id_module].position[OUTLET_SPIN]) < POSITION_ERROR_PULSE_SPIN){
//        DEBUG_ENCODER_COUNT_SPIN[id_module]--;
//        if(DEBUG_ENCODER_COUNT_SPIN[id_module] < 0){
            DEBUG_ENCODER_COUNT_SPIN[id_module] = 0;
//        }
        return true;
    }else{
        DEBUG_ENCODER_COUNT_SPIN[id_module]++;
        return false;
    }
}

bool DialogOutlet::CheckSpinInExitPos(int id_module, int id_cell){
    int exit_pos;
    if(id_cell == 0){
        exit_pos = CELL_POS_EXIT_1[id_module];
    }else if(id_cell == 1){
        exit_pos = CELL_POS_EXIT_2[id_module];
    }else if(id_cell == 2){
        exit_pos = CELL_POS_EXIT_3[id_module];
    }

    if(abs(exit_pos - OUTLET_DATA[id_module].position[OUTLET_SPIN]) < POSITION_ERROR_PULSE_SPIN){
//        DEBUG_ENCODER_COUNT_SPIN[id_module]--;
//        if(DEBUG_ENCODER_COUNT_SPIN[id_module] < 0){
            DEBUG_ENCODER_COUNT_SPIN[id_module] = 0;
//        }
        return true;
    }else{
        DEBUG_ENCODER_COUNT_SPIN[id_module]++;
        return false;
    }
}

bool DialogOutlet::CheckDoorInOpenPos(int id_module){
    if(abs(OPEN_POS_DOOR[id_module] - OUTLET_DATA[id_module].position[OUTLET_DOOR]) < POSITION_ERROR_PULSE_DOOR){
//        DEBUG_ENCODER_COUNT_DOOR[id_module]--;
//        if(DEBUG_ENCODER_COUNT_DOOR[id_module] < 0){
            DEBUG_ENCODER_COUNT_DOOR[id_module] = 0;
//        }
        return true;
    }else{
        DEBUG_ENCODER_COUNT_DOOR[id_module]++;
        return false;
    }
}
bool DialogOutlet::CheckDoorInClosePos(int id_module){
    if(abs(CLOSE_POS_DOOR[id_module] - OUTLET_DATA[id_module].position[OUTLET_DOOR]) < POSITION_ERROR_PULSE_DOOR){
//        DEBUG_ENCODER_COUNT_DOOR[id_module]--;
//        if(DEBUG_ENCODER_COUNT_DOOR[id_module] < 0){
            DEBUG_ENCODER_COUNT_DOOR[id_module] = 0;
//        }
        return true;
    }else{
        DEBUG_ENCODER_COUNT_DOOR[id_module]++;
        return false;
    }
}

int DialogOutlet::GetSonarSensor(int id_module){
    return OUTLET_DATA[id_module].sonar_sensor_data;
}

unsigned char DialogOutlet::GetMotorStatus(int id_module, int spin_door){
    return OUTLET_DATA[id_module].status[spin_door];
}

int DialogOutlet::GetDoorPosition(int id_module){
    if(fabs(OPEN_POS_DOOR[id_module]-OUTLET_DATA[id_module].position[1]) < POSITION_ERROR_PULSE_DOOR){
        return DOOR_IN_OPEN_POS;
    }else if(fabs(CLOSE_POS_DOOR[id_module]-OUTLET_DATA[id_module].position[1]) < POSITION_ERROR_PULSE_DOOR){
        return DOOR_IN_CLOSE_POS;
    }else{
        return DOOR_IN_UNKNOWN_POS;
    }
}

void DialogOutlet::on_BTN_INIT_MODULE_1_clicked(){
    init_state_door[0] = OUTLET_INIT_START;
    init_state_spin[0] = OUTLET_INIT_START;
    plog->write("[UI OPERATION - OUTLET] 모듈 초기화 1");
}

void DialogOutlet::on_BTN_INIT_MODULE_2_clicked(){
    init_state_door[1] = OUTLET_INIT_START;
    init_state_spin[1] = OUTLET_INIT_START;
    plog->write("[UI OPERATION - OUTLET] 모듈 초기화 2");
}


void DialogOutlet::on_BTN_OUTLET_1_DISPENSE_CELL_1_clicked(){
    if(IsModuleRunning(0)){
        qDebug()<<"Module is reserved";
    }else{
        pschedule->SetForcedDispensing(0, 0);
    }
    plog->write("[UI OPERATION - OUTLET] 음료 배출 1-1");
}
void DialogOutlet::on_BTN_OUTLET_1_DISPENSE_CELL_2_clicked(){
    if(IsModuleRunning(0)){
        qDebug()<<"Module is reserved";
    }else{
        pschedule->SetForcedDispensing(0, 1);
    }
    plog->write("[UI OPERATION - OUTLET] 음료 배출 1-2");
}
void DialogOutlet::on_BTN_OUTLET_1_DISPENSE_CELL_3_clicked(){
    if(IsModuleRunning(0)){
        qDebug()<<"Module is reserved";
    }else{
        pschedule->SetForcedDispensing(0, 2);
    }
    plog->write("[UI OPERATION - OUTLET] 음료 배출 1-3");
}

void DialogOutlet::on_BTN_OUTLET_2_DISPENSE_CELL_1_clicked(){
    if(IsModuleRunning(1)){
        qDebug()<<"Module is reserved";
    }else{
        pschedule->SetForcedDispensing(1, 0);
    }
    plog->write("[UI OPERATION - OUTLET] 음료 배출 2-1");
}
void DialogOutlet::on_BTN_OUTLET_2_DISPENSE_CELL_2_clicked(){
    if(IsModuleRunning(1)){
        qDebug()<<"Module is reserved";
    }else{
        pschedule->SetForcedDispensing(1, 1);
    }
    plog->write("[UI OPERATION - OUTLET] 음료 배출 2-2");
}
void DialogOutlet::on_BTN_OUTLET_2_DISPENSE_CELL_3_clicked(){
    if(IsModuleRunning(1)){
        qDebug()<<"Module is reserved";
    }else{
        pschedule->SetForcedDispensing(1, 2);
    }
    plog->write("[UI OPERATION - OUTLET] 음료 배출 2-3");
}

void DialogOutlet::on_BTN_ENABLE_MODULE_1_clicked()
{
    if(OUTLET_DISABLE[0] == 0){
        QMessageBox::StandardButton reply;
        reply = QMessageBox::question(this, "배출구 1 비활성화",
                                          "<font size=6>배출구를 비활성화 하시겠습니까?</font>");
        if(reply == QMessageBox::Yes){
            if(OP_STATUS_OPERATING == PLATFORM_OPERATION_ON_OPERATING_STATE){
                QMessageBox::warning(this, "비활성화 실패", "<font size=4>운영 종료 후 다시 시도해 주시기 바랍니다.</font>");
            }else{
                OUTLET_DISABLE[0] = 1;
                plog->write("[UI OUTLET] DISABLE OUTLET 1 clicked");
            }
        }
    }else{
        QMessageBox::StandardButton reply;
        reply = QMessageBox::question(this, "배출구 1 활성화",
                                          "<font size=6>배출구를 활성화 하시겠습니까?</font>");
        if(reply == QMessageBox::Yes){
            if(OP_STATUS_OPERATING == PLATFORM_OPERATION_ON_OPERATING_STATE){
                    QMessageBox::warning(this, "활성화 실패", "<font size=4>운영 종료 후 다시 시도해 주시기 바랍니다.</font>");
            }else{
                OUTLET_DISABLE[0] = 0;
                plog->write("[UI OUTLET] ENABLE OUTLET 1 clicked");
            }
        }
    }
}

void DialogOutlet::on_BTN_ENABLE_MODULE_2_clicked()
{
    if(OUTLET_DISABLE[1] == 0){
        QMessageBox::StandardButton reply;
        reply = QMessageBox::question(this, "배출구 2 비활성화",
                                          "<font size=6>배출구를 비활성화 하시겠습니까?</font>");
        if(reply == QMessageBox::Yes){
            if(OP_STATUS_OPERATING == PLATFORM_OPERATION_ON_OPERATING_STATE){
                QMessageBox::warning(this, "비활성화 실패", "<font size=4>운영 종료 후 다시 시도해 주시기 바랍니다.</font>");
            }else{
                OUTLET_DISABLE[1] = 1;
                plog->write("[UI OUTLET] DISABLE OUTLET 2 clicked",true);
            }
        }
    }else{
        QMessageBox::StandardButton reply;
        reply = QMessageBox::question(this, "배출구 2 활성화",
                                          "<font size=6>배출구를 활성화 하시겠습니까?</font>");
        if(reply == QMessageBox::Yes){
            if(OP_STATUS_OPERATING == PLATFORM_OPERATION_ON_OPERATING_STATE){
                    QMessageBox::warning(this, "활성화 실패", "<font size=4>운영 종료 후 다시 시도해 주시기 바랍니다.</font>");
            }else{
                OUTLET_DISABLE[1] = 0;
                plog->write("[UI OUTLET] ENABLE OUTLET 2 clicked",true);
            }
        }
    }
}
