#ifndef DIALOGCOFFEE_H
#define DIALOGCOFFEE_H

#include <QDialog>
#include <QWebSocket>
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonParseError>
#include <QTimer>
#include <QList>

#include <QtSql/QSql>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>

#include "DialogStock.h"
#include "GlobalHeader.h"


#define WMF_IP_ADDR     "192.168.100.20"

#define DB_NAME_LOADCELL  "DB/loadcell"


// Delight WMF Setting
// 01| Espresso30    02| Espresso35    03| Espresso40    04| Espresso45    05| Espresso50    06| Espresso55    07| Espresso60    08| Espresso30    09| MilkFoamIce100    10| MilkFoamIce180
// 11| Milk100       12| Milk120       13| Milk140       14| Milk160       15| Milk180       16| Milk200       17| Milk220       18| Espresso30    19| MilkFoamIce120    20| MilkFoamIce200
// 21| MilkIce100    22| MilkIce120    23| MilkIce140    24| MilkIce160    25| MilkIce180    26| MilkIce200    27| MilkIce220    28| X             29| MilkFoamIce140    30| MilkFoamIce220
// 31| MilkFoam100   32| MilkFoam120   33| MilkFoam140   34| MilkFoam160   35| MilkFoam180   36| MilkFoam200   37| MilkFoam220   38| X             39| MilkFoamIce160




//********************** Machine Error Definition *********************//
#define MACHINE_ERROR_NO_TRASH_BASKET   68
#define MACHINE_ERROR_OPENED_PANEL      74

//********************** Machine Status Definition *********************//
enum{
    MACHINE_NOT_CONNECTED = 0,      // Machine is offline or Socket is not connected
    MACHINE_NOT_READY,              // Machine is connected but not ready yet. (initialize)
    MACHINE_READY,                  // Machine is ready. (Idle)
    MACHINE_ERROR_OCCURRED,         // Machine has any error. (Blocked)
    MACHINE_MAKING_BEVERAGE,        // Machine makes beverage
    MACHINE_SYSTEM_CLEANING,        // Machine in System Cleaning (need man's support, 5 minite)
    MACHINE_MILK_CLEANING,          // Machine in Milk Cleaning (need man's support, 5 minite)
    MACHINE_MILK_REPLACEMENT,       // Machine in Milk Replacement (automatically, 15-20 second)
    MACHINE_FOARMER_RINSING         // Machine in Foarmer Rinsing
};
//******************** Beverage State Definition **********************//
enum{
    BEVERAGE_NONE = 0,              // No Making Beverage
    BEVERAGE_READY,                 // Send Making Beverage Command (Machine accept not yet)
    BEVERAGE_DISPENSING,            // Machine making Beverage start
    BEVERAGE_DONE,                  // Machine finish making Beverage
    BEVERAGE_DONE_BUT_NOT_READY,    // Machine finish making Beverage but now has an error (e.g. heating)
    BEVERAGE_FORCED_STOP            // Machine finish making Beverage (Stop Command)
};
//********************* Cleaning State Definition *********************//
enum{
    CLEANING_NONE = 0,              // No Cleaning
    CLEANING_READY,                 // Send Cleaning Start Command (Machine accept not yet)
    CLEANING_AUTO_START,            // Machine cleaning start
    CLEANING_START,                 // Machine cleaning start
    CLEANING_DONE                   // Cleaning Done
};
//********************* Cleaning Command Definition *********************//
enum{
    COMMAND_SYS_CLEANING = 0,
    COMMAND_MILK_CLEANING,
    COMMAND_MILK_REPLACEMENT,
    COMMAND_FOAMER_RINSING
};
//*********************** Menu Definition ******************************//
enum{
    RECIPE_ESPRESSO = 1,
    RECIPE_LATTE
};
//******************* Machine Return Value Definition ******************//
enum{
    RETURN_NONE = -2,               //
    RETURN_WAITING,
    RETURN_ACCEPT_SUCCESS,          // Function returns success
    RETURN_OFFLINE,                 // Machine is offline
    RETURN_NOT_READY,               // Machine is not ready, e.g. error is present
    RETURN_NOT_INITIALIZED,         // Machine is not ready, e.g. initialization
    RETURN_BLOCKING_ERROR,          // Machine has an error, e.g. beans empty
    RETURN_START_NOT_SUCCESS,       // Machine has an error, e.g. skim milk was chosen, although this is not configured
    RETURN_OTHER_BEVERAGE_RUNNING,  // Machine blocked, beverage is running
    RETURN_PARAMETER_ERROR,         // A parameter is wrong, e.g. BtnNbr is out of range
    RETURN_NO_BEVERAGE_RUNNING,     // No beverage is running
    RETURN_NOT_SUCCESS,             // Function was not successful for any reason
    RETURN_FUNCTION_BUSY,           // Function is currently blocked due to internal reasons
    RETURN_FUNCTION_NOT_AVAILABLE,  // Function is not available due to machine configuration or initialization issues
    RETURN_TIMEOUT
};

//*********************************************************************//
typedef struct{
    int dueTimeSysClean = -1;
    int dueTimeMilkClean = -1;
    int dueTimeMilkReplace = -1;
}Machine_Status;
//*********************************************************************//


namespace Ui {
class DialogCoffee;
}

class DialogCoffee : public QDialog
{
    Q_OBJECT

public:
    explicit DialogCoffee(QWidget *parent = nullptr, DialogStock *_stock = nullptr);
    ~DialogCoffee();


    void SetComboBox();


    bool isRinseafterMilk;
    int last_made_beverage;

    //WMF커피머신 서버와 연결*
    void connect_server(QString _ip, QString _port);
    bool isConnectedServer();

    //사용자가 call하는 명령 함수들*
    void makeBeverage(int _recipe);
    void stopBeverage();
    void startCleaning(int _method);

    //각 cleaning duetime 순차적으로 물어봄
    void requestCurrentStatus();

    //에러 관련 함수들
    void requestError(bool _onoff);
    void requestErrorCount();
    void requestActiveError();
    void ErrorClear(int _errCode);

    //기기전원 관련 함수
    void restartMachine();
    void shutdownMachine();

    //각 변수 get함수들*
    Machine_Status getMachineStatus();
    int getCurrentStatus();
    int getBeverageState();
    int getCleaningState();
    QList<int> getMachineError();
    int getReturnValue();



    int coffee_command_flag;


    // 기기 동작 상태 변수
    int status = MACHINE_NOT_CONNECTED;
    // 음료 제조 상태 변수
    int beverage_state = BEVERAGE_NONE;
    // 청소 상태 변수
    int cleaning_state = CLEANING_NONE;

    int timeout_after_clean = 0;

    // 기기 상태 변수
    Machine_Status Machine;


    int IsRefillMilkSoon();


private:
    //socket write 함수
    void sendCommand(QString _function);
    void sendCommand(QString _function, int _recipe);
    void requestStatus(QString _function);
    int hasError(int _errCode);

signals:
    void connected();
    void disconnected();
    void gotError();

public slots:
    void onConnected();
    void onDisconnected();
    void onSendMsg();
    void onReceivedMsg(QString message);
    void onGotError();
    void onTimer();

private slots:
    void on_BTN_REQUEST_BUTTON_LIST_clicked();
    void on_BTN_DRINK_OUT_clicked();


    void on_BTN_LC_SET_SCALE_1_clicked();

    void on_BTN_LC_SET_SCALE_2_clicked();

    void on_BTN_LC_SET_SCALE_3_clicked();

    void on_BTN_LC_SET_SCALE_4_clicked();

    void on_BTN_LC_SET_INITIAL_1_clicked();

    void on_BTN_LC_SET_INITIAL_2_clicked();

    void on_BTN_LC_SET_INITIAL_3_clicked();

    void on_BTN_LC_SET_INITIAL_4_clicked();

    void on_BTN_LC_GET_INITIAL_clicked();

private:
    Ui::DialogCoffee *ui;
    QTimer timer;

    QSqlDatabase    db;


    DialogStock *stock;
    QMap<QString, QString> coffee_desc_btn;

    // 기기 에러 변수
    QList<int> machine_error;
    // 기기로 부터 받은 통신 반환 변수
    int return_value = RETURN_NONE;

    int timeout_count = 0;

    // 상태 요청 순서 변수 (순차적으로 하나씩 요청)
    int stepRequestStatus;



    // 웹 소켓 관련 변수
    QWebSocket socket;
    QUrl url;
    // 마지막으로 보낸 메시지
    QString last_send_msg;
    // 보낼 메시지 큐
    QList<QString> queue_CMD;
    QList<QString> queue_Status;

    QTimer sendMsgTimer;
};

#endif // DIALOGCOFFEE_H
