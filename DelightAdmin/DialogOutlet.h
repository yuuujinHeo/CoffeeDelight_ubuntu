#ifndef DIALOGOUTLET_H
#define DIALOGOUTLET_H

#include <QDialog>
#include <QTimer>

#include <QtSql/QSql>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>

#include "GlobalHeader.h"


#define OUTLET_SPIN     0
#define OUTLET_DOOR     1

#define OUTLET_SONAR_SENSOR_THRESHOLD   12


#define POSITION_ERROR_PULSE_SPIN   300
#define POSITION_ERROR_PULSE_DOOR   300


#define MOTOR_JAM_ERROR(x)      ((x>>2)&0x01)
#define MOTOR_CUR_ERROR(x)      ((x>>3)&0x01)
#define MOTOR_BIG_ERROR(x)      ((x>>4)&0x01)
#define MOTOR_INP_ERROR(x)      ((x>>5)&0x01)
#define MOTOR_COL_ERROR(x)      ((x>>7)&0x01)

#define DOOR_HANDLER_LOOP_TIME      100


enum{
    OUTLET_INIT_IDLE = 0,
    OUTLET_INIT_START,
    OUTLET_INIT_FIND_HOME,
    OUTLET_INIT_CHECK_FIND_HOME_DONE,

    OUTLET_INIT_FIND_HOME_COLLISION,

    OUTLET_INIT_ROTATE_TURNTABLE,
    OUTLET_INIT_CHECK_CELL_WAIT,
    OUTLET_INIT_CHECK_CELL,
    OUTLET_INIT_DONE,
    OUTLET_INIT_CALL_MANAGER
};

enum{
    DOOR_IN_OPEN_POS = 0,
    DOOR_IN_CLOSE_POS,
    DOOR_IN_UNKNOWN_POS
};

#define DB_NAME_OUTLET  "DB/outlet"

namespace Ui {
class DialogOutlet;
}

class DialogOutlet : public QDialog
{
    Q_OBJECT

public:
    explicit DialogOutlet(QWidget *parent = nullptr);
    ~DialogOutlet();

    void LoadDatabase();

    void InitOutletHandler();
    int init_state_door[NUMBER_OF_OUTLET];
    int init_state_spin[NUMBER_OF_OUTLET];
    int is_door_ready[NUMBER_OF_OUTLET];
    int is_spin_ready[NUMBER_OF_OUTLET];

    bool isError(int id_module);
    void ErrorClear();


    void FindHome(int target, int spin_door);
    void GoPosition(int target, int spin_door, int position);
    void SetVelocity(int target, int spin_door, int velocity);
    void EncoderZero(int target, int spin_door);


    int     OPEN_POS_DOOR[NUMBER_OF_OUTLET];
    int     CLOSE_POS_DOOR[NUMBER_OF_OUTLET];

    int     CELL_POS_LOAD_1[NUMBER_OF_OUTLET];
    int     CELL_POS_LOAD_2[NUMBER_OF_OUTLET];
    int     CELL_POS_LOAD_3[NUMBER_OF_OUTLET];

    int     CELL_POS_EXIT_1[NUMBER_OF_OUTLET];
    int     CELL_POS_EXIT_2[NUMBER_OF_OUTLET];
    int     CELL_POS_EXIT_3[NUMBER_OF_OUTLET];

    int     OUTLET_DISABLE[NUMBER_OF_OUTLET];

    ST_OUTLET_CELL_INFO     GetFreeCellInfo();
    int     GetFreeModuleInfo();

    void    SetModuleRunning(int id_module, bool is_running);
    bool    IsModuleRunning(int id_module);
    bool    IsModuleMoving(int id_module);
    void    SetCellOccupancy(int id_module, int id_cell, int occupancy, QString pin);

    void    SpinToLoad(int id_module, int id_cell);
    void    SpinToExit(int id_module, int id_cell);
    void    OpenDoor(int id_module);
    void    CloseDoor(int id_module);

    bool    CheckSpinInLoadPos(int id_module, int id_cell);
    bool    CheckSpinInExitPos(int id_module, int id_cell);
    bool    CheckDoorInOpenPos(int id_module);
    bool    CheckDoorInClosePos(int id_module);

    int     GetSonarSensor(int id_module);
    unsigned char GetMotorStatus(int id_module, int spin_door);

    int GetDoorPosition(int id_module);

    int IsOutletFull();

    void CheckFatalError();

    int FATAL_INFO_CONNECTION_ERROR_1;
    int FATAL_INFO_CONNECTION_ERROR_2;

    int FATAL_INFO_OUTLET_1_SENSOR_ERROR;
    int FATAL_INFO_OUTLET_2_SENSOR_ERROR;
    int FATAL_INFO_OUTLET_1_SENSOR_WRONG_VALUE;
    int FATAL_INFO_OUTLET_2_SENSOR_WRONG_VALUE;

    int FATAL_INFO_SPIN_1_CONTROL_ERROR;
    int FATAL_INFO_SPIN_2_CONTROL_ERROR;
    int FATAL_INFO_DOOR_1_CONTROL_ERROR;
    int FATAL_INFO_DOOR_2_CONTROL_ERROR;

    int SUPER_FATAL_ERROR_OUTLET_CONNECTION;
    int SUPER_FATAL_ERROR_OUTLET_SENSOR;
    int SUPER_FATAL_ERROR_OUTLET_CONTROL;



    int DEBUG_ENCODER_COUNT_SPIN[NUMBER_OF_OUTLET];
    int DEBUG_ENCODER_COUNT_DOOR[NUMBER_OF_OUTLET];
    int DEBUG_SONAR_COUNT[NUMBER_OF_OUTLET];

public slots:
    void onTimer();

private slots:
    void on_BTN_FIND_HOME_SPIN_1_clicked();
    void on_BTN_FIND_HOME_DOOR_1_clicked();
    void on_BTN_FIND_HOME_SPIN_2_clicked();
    void on_BTN_FIND_HOME_DOOR_2_clicked();

    void on_BTN_MOVE_SPIN_1_TO_CELL_LOAD_1_clicked();
    void on_BTN_MOVE_SPIN_1_TO_CELL_LOAD_2_clicked();
    void on_BTN_MOVE_SPIN_1_TO_CELL_LOAD_3_clicked();

    void on_BTN_MOVE_SPIN_1_TO_CELL_OUT_1_clicked();
    void on_BTN_MOVE_SPIN_1_TO_CELL_OUT_2_clicked();
    void on_BTN_MOVE_SPIN_1_TO_CELL_OUT_3_clicked();

    void on_BTN_MOVE_SPIN_2_TO_CELL_LOAD_1_clicked();
    void on_BTN_MOVE_SPIN_2_TO_CELL_LOAD_2_clicked();
    void on_BTN_MOVE_SPIN_2_TO_CELL_LOAD_3_clicked();

    void on_BTN_MOVE_SPIN_2_TO_CELL_OUT_1_clicked();
    void on_BTN_MOVE_SPIN_2_TO_CELL_OUT_2_clicked();
    void on_BTN_MOVE_SPIN_2_TO_CELL_OUT_3_clicked();

    void on_BTN_MOVE_DOOR_1_TO_OPEN_POS_clicked();
    void on_BTN_MOVE_DOOR_1_TO_CLOSE_POS_clicked();

    void on_BTN_MOVE_DOOR_2_TO_OPEN_POS_clicked();
    void on_BTN_MOVE_DOOR_2_TO_CLOSE_POS_clicked();

    void on_BTN_INIT_MODULE_1_clicked();

    void on_BTN_INIT_MODULE_2_clicked();

    void on_BTN_OUTLET_1_DISPENSE_CELL_1_clicked();

    void on_BTN_OUTLET_1_DISPENSE_CELL_2_clicked();

    void on_BTN_OUTLET_1_DISPENSE_CELL_3_clicked();

    void on_BTN_OUTLET_2_DISPENSE_CELL_1_clicked();

    void on_BTN_OUTLET_2_DISPENSE_CELL_2_clicked();

    void on_BTN_OUTLET_2_DISPENSE_CELL_3_clicked();

    void on_BTN_ENABLE_MODULE_1_clicked();

    void on_BTN_ENABLE_MODULE_2_clicked();

private:
    Ui::DialogOutlet *ui;
    QTimer timer;

    QSqlDatabase    db;

};

#endif // DIALOGOUTLET_H
