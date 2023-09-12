#ifndef GLOBALHEADER_H
#define GLOBALHEADER_H

#include <QLineEdit>
#include <QLabel>
#include <QPushButton>
#include "Logger.h"

inline void SetLEColor(QLineEdit *le, QString color){
    le->setStyleSheet("QLineEdit{background-color:"+color+"}");
}
inline void SetLBColor(QLabel *lb, QString color){
    lb->setStyleSheet("QLabel{background-color:"+color+"}");
}
inline void SetBTNColor(QPushButton *btn, QString color){
    btn->setStyleSheet("QPushButton{background-color:"+color+"}");
}
#define COLOR_NONE      "white"
#define COLOR_GOOD      "#178D56"
#define COLOR_BAD       "#CD1717"
#define COLOR_WEAKBAD   "#CD3737"
#define COLOR_BLUE      "#1766AD"
#define COLOR_UNDETERMINED "#746969"



#define NUMBER_OF_CUP       4

#define NUMBER_OF_OUTLET    2
#define NUMBER_OF_CELL      3

#define NUMBER_OF_MILK      1


extern int IS_UI_LOCK;

extern Logger    *plog;


enum{
    PLATFORM_INIT_IDLE = 0,
    PLATFORM_INIT_START,
    PLATFORM_INIT_CHECK_CONNECTION,
    PLATFORM_INIT_CHECK_ROBOT_IN_GOOD_POSTURE,
    PLATFORM_INIT_CHECK_ROBOT_CONNECTION,
    PLATFORM_INIT_ROBOT_PROGRAM_TURN_ON,
    PLATFORM_INIT_OUTLET,
    PLATFORM_INIT_OUTLET_DONE,
    PLATFORM_INIT_DONE,
    PLATFORM_INIT_ON_SUCCESS_STATE,
    PLATFORM_INIT_ON_FAIL_STATE
};

enum{
    PLATFORM_OPERATION_IDLE = 0,
    PLATFORM_OPERATION_START,
    PLATFORM_OPERATION_CHECK_ON_INIT_SUCCES_STATE,
    PLATFORM_OPERATION_CHECK_ROBOT_POSTURE,
    PLATFORM_OPERATION_CHECK_PLATFORM_CLOSED,
    PLATFORM_OPERATION_CHECK_OUTLET_OCCUPY,
    PLATFORM_OPERATION_CHECK_SCHEDULER,
    PLATFORM_OPERATION_ON_OPERATING_STATE,
    PLATFORM_OPERATION_ON_OPERATING_FAIL_STATE,
    PLATFORM_OPERATION_ON_ERROR_STATE,

    PLATFORM_OPERATION_FATAL_CHECK_ROBOT_DANGEROUS_POSITION,
    PLATFORM_OPERATION_FATAL_AVOID_ROBOT_DANGEROUS_POSITION,
    PLATFORM_OPERATION_PLATFORM_OPENED_DETECTED,

};
extern int OP_STATUS_INITIALIZING;
extern int OP_STATUS_OPERATING;

extern int SUPER_FATAL_ERROR_PLATFORM_OPEN;
extern int PLATFORM_OPENED_WHEN_OPERATING_FLAG;



typedef struct{
    QString type;       // 재고의 타입
    QString name;       // 재고의 이름
    int     current;
    int     maximum;
    int     minimum;

    int     reserved;
    int     error;      // device error
}ST_STOCK;

typedef struct{
    QString ingredient;     // 재고의 이름
    QString amount;
}ST_RECIPE_STEP;
typedef QVector<ST_RECIPE_STEP> V_RECIPE;


typedef struct{
    QString menu_id;
    QString menu_name;
    bool    option_available;
    bool    available;
    int     time;

    V_RECIPE recipe;
}ST_MENU;


typedef struct{
    QString pin;
    QString menu_id;
    QString menu_name;
    QString option;

    V_RECIPE recipe;
}ST_RECIPE_INFO;

typedef struct{
    QString pin;
    QString menu_id;
    QString menu_name;

    int id_module;
    int id_cell;
}ST_COMPLETED_DRINK_INFO;


typedef struct{
    int id_module;
    int id_cell;
}ST_OUTLET_CELL_INFO;


extern int LOADCELL_SCALE_HOT_1;
extern int LOADCELL_SCALE_HOT_2;
extern int LOADCELL_SCALE_SYRUP;
extern int LOADCELL_SCALE_SODA;
extern int LOADCELL_SCALE_ICECREAM_1;
extern int LOADCELL_SCALE_ICECREAM_2;
extern int LOADCELL_SCALE_MILK_1;
extern int LOADCELL_SCALE_MILK_2;
extern int LOADCELL_SCALE_MILK_3;
extern int LOADCELL_SCALE_MILK_4;
extern int LOADCELL_INITIAL_MILK_1;
extern int LOADCELL_INITIAL_MILK_2;
extern int LOADCELL_INITIAL_MILK_3;
extern int LOADCELL_INITIAL_MILK_4;
// ==========================================================



typedef enum{
    DEV_DIALOG_ID_SETTING = 0,
    DEV_DIALOG_ID_CUP,
    DEV_DIALOG_ID_ICE,
    DEV_DIALOG_ID_SODA,
    DEV_DIALOG_ID_COFFEE,
    DEV_DIALOG_ID_ROBOT,
    DEV_DIALOG_ID_SYRUP,
    DEV_DIALOG_ID_MONITOR,
    DEV_DIALOG_ID_DOOR,
    DEV_DIALOG_ID_BARCODE,
    DEV_DIALOG_ID_OUTLET,
    DEV_DIALOG_ID_ICECREAM,
    DEV_DIALOG_ID_HOT,
    DEV_DIALOG_ID_KIOSK,
    DEV_DIALOG_ID_STOCK
}DEVICE_DIALOG_ID;


#define DEV_SEND_ID_CUP_DISPENSER   0x01
#define DEV_SEND_ID_ICE_DISPENSER   0x02
#define DEV_SEND_ID_SYRUP           0x03
#define DEV_SEND_ID_BARCODE         0x04
#define DEV_SEND_ID_OUTLET          0x05
#define DEV_SEND_ID_SODA_DISPENSER  0x06
#define DEV_SEND_ID_HOT_DISPENSER   0x07
#define DEV_SEND_ID_ICECREAM        0x08


typedef struct{
    unsigned char connection_status;
    unsigned char ultra_sonic_data;     // cm unit
    unsigned char status;               // (LIMIT_ROTATE<<3) | (LIMIT_EMPTY<<2) | (ULTRA_SONIC_ERROR<<1) | CUP_DETECT
    unsigned char cup_out_count;        //
    unsigned char last_error;           // 0: no error      other: error
    unsigned char dispense_op_flag;     // 0: idle          other: working

    unsigned char prev_out_count;
}CUP_DISPENSER_INFO;
extern CUP_DISPENSER_INFO   CUP_DATA[4];


typedef union{
    struct{
        unsigned    last_no_ice:1;          // 직전출빙에서 얼음 미감지된 경우
        unsigned    last_yes_ice:1;         // 직전출빙에서 얼음 감지된 경우
        unsigned    comp_working:1;         // 콤푸 동작중 (1)
        unsigned    gear_motor_working:1;   // 기어모터 동작중 (1)
        unsigned    out_sol_detected:1;     // 출빙 SOL 감지 (1)
        unsigned    cup_lever_detected:1;   // 컴레버 감지 (1)
        unsigned    comm_mode:1;            // 통신모드 (1)
        unsigned    full_ice:1;             // 만빙 (1)

        unsigned    err_code_1:1;           // 에러코드1
        unsigned    err_code_2:1;           // 에러코드2
        unsigned    err_code_3:1;           // 에러코드3
        unsigned    err_code_4:1;           // 에러코드4
        unsigned    cur_state:1;            // 1:출빙명령 대기  2: 출빙완료/타임아웃
        unsigned    rsvd:3;

        unsigned    rsvd2:8;
        unsigned    rsvd3:8;
    }b;
    unsigned char B[4];
}U_ICEVAN_STAT;
typedef struct{
    unsigned char connection_status;
    unsigned char data_connection;
    unsigned char comm_mode;
    unsigned char cup_ignore;
    unsigned char setting_ambient_temp_high;
    unsigned char setting_ambient_temp_low;
    unsigned char ambient_temp;
    unsigned char evaporator_temp;
    unsigned char condensor_temp;
    unsigned char timeout_sec;
    unsigned char last_ice_out_time;
    unsigned char last_water_out_time;
    unsigned char ice_out_count;
    U_ICEVAN_STAT status;

    unsigned char prev_out_count;
}ICE_DISPENSER_INFO;
extern ICE_DISPENSER_INFO   ICE_DATA[2];


typedef struct{
    short value;
    short calib_param;
    int raw;
    unsigned char error;
}ST_LOADCELL_DATA;

typedef struct{
    unsigned char       connection_status;
    ST_LOADCELL_DATA    loadcell[2];
    unsigned char       out_state;
    unsigned char       out_count;
    unsigned char       last_error;

    unsigned char       prev_out_count;
}SODA_DISPENSER_INFO;
extern SODA_DISPENSER_INFO  SODA_DATA[1];

typedef struct{
    unsigned char       connection_status;
    ST_LOADCELL_DATA    loadcell[2];
    unsigned char       out_state;
    unsigned char       out_count;
    unsigned char       last_error;

    unsigned char       prev_out_count;
}HOT_DISPENSER_INFO;
extern HOT_DISPENSER_INFO  HOT_DATA[1];

typedef struct{
    unsigned char       connection_status;
    ST_LOADCELL_DATA    loadcell[2];
    unsigned char       out_state;
    unsigned char       out_count;
    unsigned char       last_error;

    unsigned char       prev_out_count;
}ICECREAM_DISPENSER_INFO;
extern ICECREAM_DISPENSER_INFO  ICECREAM_DATA[1];

typedef struct{
    unsigned char       connection_status;
    ST_LOADCELL_DATA    loadcell;
    unsigned char       out_state;
    unsigned char       out_count;
    unsigned char       last_error;

    unsigned char       prev_out_count;
}SYRUP_DISPENSER_INFO;
extern SYRUP_DISPENSER_INFO SYRUP_DATA[1];

#define MAX_BARCODE_LENGTH      24
typedef struct{
    unsigned char       connection_status;
    unsigned char       barcode_count;
    unsigned char       barcode_data[MAX_BARCODE_LENGTH];

    unsigned char       prev_barcode_count;
}BARCODE_INFO;
extern BARCODE_INFO BARCODE_DATA[1];


typedef struct{
    unsigned char       connection_status;
    int                 position[2];
    int                 current[2];
    unsigned char       status[2];
    unsigned char       init_status[2];
    unsigned char       operating_status[2];
    unsigned char       sonar_sensor_data;
    unsigned char       sonar_sensor_error;
    int                 open_position[2];
    unsigned char       velocity[2];


    unsigned char       is_moving[2];   // motor
    unsigned char       is_running;     // module
    unsigned char       cell_state[NUMBER_OF_CELL]; // occupy / empty
    QString             cell_occupy_pin[NUMBER_OF_CELL];
}OUTLET_INFO;
extern OUTLET_INFO  OUTLET_DATA[NUMBER_OF_OUTLET];

enum{
    CELL_EMP = 0,
    CELL_OCC,
};

typedef struct{
    unsigned char   connection_status;
    unsigned char   platform_sensorA;
    unsigned char   platform_sensorB;
}DOOR_INFO;
extern DOOR_INFO    DOOR_DATA[1];

typedef struct{
    unsigned char       connection_status;
    int                 loadcell_raw[4];
}MILK_INFO;
extern MILK_INFO    MILK_DATA[NUMBER_OF_MILK];
//====================================================================================


#define MAX_SHARED_DATA 128
#define MAX_CONFIG_DATA 157

typedef union{
    struct{
        char    header[4];
        // 0
        float   time;                   // time [sec]
        float   jnt_ref[6];             // joint reference [deg]
        float   jnt_ang[6];             // joint encoder value [deg]
        float   cur[6];                 // joint current value [mA]
        // 19
        float   tcp_ref[6];             // calculated tool center point from reference [mm, deg]
        float   tcp_pos[6];             // calculated tool center point from encoder [mm, deg]
        // 31
        float   analog_in[4];           // analog input value of control box [V]
        float   analog_out[4];          // analog output value of control box [V]
        int     digital_in[16];         // digital input value of control box [0 or 1]
        int     digital_out[16];        // digital input value of control box [0 or 1]
        // 71
        float   temperature_mc[6];      // board temperature of each joint [celcius]
        // 77
        int     task_pc;                // (ignore)
        int     task_repeat;            // (ignore)
        int     task_run_id;            // (ignore)
        int     task_run_num;           // (ignore)
        float   task_run_time;          // (ignore)
        int     task_state;             // (ignore)
        // 83
        float   default_speed;          // overriding speed [0~1]
        int     robot_state;            // state of robot motion [1:idle  2:paused or stopped by accident  3: moving]
        int     power_state;            // power state
        // 86
        float   tcp_target[6];          // (ignore)
        int     jnt_info[6];            // joint information (look mSTAT)
        // 98
        int     collision_detect_onoff; // collision detect onoff [0:off  1:on]
        int     is_freedrive_mode;      // current freedrive status [0:off  1:on]
        int     program_mode;           // current program mode [0:real mode  1:simulation mode]
        // 101
        int     init_state_info;        // status information of robot initialization process
        int     init_error;             // error code of robot initialization process
        // 103
        float   tfb_analog_in[2];       // analog input value of tool flange board [V]
        int     tfb_digital_in[2];      // digital input value of tool flange board [0 or 1]
        int     tfb_digital_out[2];     // digital output value of tool flange board [0 or 1]
        float   tfb_voltage_out;        // reference voltage of tool flange board [0, 12, 24]
        // 110
        int     op_stat_collision_occur;
        int     op_stat_sos_flag;
        int     op_stat_self_collision;
        int     op_stat_soft_estop_occur;
        int     op_stat_ems_flag;
        // 115
        int     digital_in_config[2];
        // 117
        int     inbox_trap_flag[2];
        int     inbox_check_mode[2];
        // 121
        float eft_fx;
        float eft_fy;
        float eft_fz;
        float eft_mx;
        float eft_my;
        float eft_mz;
        // 127


    }sdata;
    float fdata[MAX_SHARED_DATA];
    int idata[MAX_SHARED_DATA];
}systemSTAT;

typedef union{
    struct{
        char    header[4];
        // 0
        float   sensitivity;            // collision threshold [0~1]
        float   work_x_min;             // (ignore)
        float   work_x_max;             // (ignore)
        float   work_y_min;             // (ignore)
        float   work_y_max;             // (ignore)
        float   work_z_min;             // (ignore)
        float   work_z_max;             // (ignore)
        int     work_onoff;
        float   mount_rotate[3];        // direction of gravity [normalized vector]
        // 11
        float   toolbox_size[3];        // virtual collision box size of tool [mm]
        float   toolbox_center_pos[3];  // virtual collision box position of tool [mm]
        float   tool_mass;              // tool mass [kg]
        float   tool_mass_center_pos[3];// center of mass position of tool [mm]
        float   tool_ee_pos[3];         // tool position [mm]
        // 24
        int     usb_detected_flag;
        int     usb_copy_done_flag;
        // 26
        int     rs485_tool_baud;
        int     rs485_tool_stopbit;
        int     rs485_tool_paritybit;
        int     rs485_box_baud;
        int     rs485_box_stopbit;
        int     rs485_box_paritybit;
        // 32
        int     io_function_in[16];
        int     io_function_out[16];
        // 64
        int     ip_addr[4];
        int     netmask[4];
        int     gateway[4];
        // 76
        int     version;
        // 77
        char    default_script[64];    // 16*4
        // 93
        int     auto_init;
        float   inbox0_size[3];
        float   inbox0_pos[3];
        float   inbox1_size[3];
        float   inbox1_pos[3];
        // 106
        int     default_repeat_num;
        // 107
        float   direct_teaching_sensitivity[6];
        // 113
        float   tool_ee_ori[3];
        // 116
        float   user_coord_0[6];
        float   user_coord_1[6];
        float   user_coord_2[6];
        // 134
        char    dio_begin_box_dout[16]; // 4*4
        float   dio_begin_box_aout[4];
        char    dio_end_box_dout[16];   // 4*4
        float   dio_end_box_aout[4];
        int     dio_begin_tool_voltage; // 1
        int     dio_end_tool_voltage;   // 1
        char    dio_begin_tool_dout[2]; // 1
        char    dio_end_tool_dout[2];   // -
        // 153
        int     ext_ft_model_info;
        // 154
        int     robot_model_type;
        // 155
        int     collision_stop_mode;
        // 156

    }sdata;
    float fdata[MAX_CONFIG_DATA];
}systemCONFIG;

typedef struct{
    char    header[4];
    char    type;
    char    msg[1000];
    int     len;
}systemPOPUP;

extern systemSTAT   sys_status;
extern systemCONFIG sys_config;
extern systemPOPUP  sys_popup;


#endif // GLOBALHEADER_H
