#include "Scheduler.h"
#include <math.h>


#define SCHEDULER_TIME_INTERVAL 100
#define MOTION_RESPONSE_DELAY   10000
#define LOADCELL_TARE_DELAY     400
#define COFFEE_RESPONSE_DELAY   2000
#define COFFEE_LAST_DELAY       1500
#define COFFEE_DISPENSE_TIMEOUT 90000
#define SODA_WAIT_DELAY         7000
#define SODA_FLUSH_TIMEOUT      1800000
#define ICECREAM_WAIT_DELAY     3500


Scheduler::Scheduler(DialogStock *_stock, DialogRobot *_robot, DialogCupDispenser *_cup, DialogHotDispenser *_hot,
                     DialogCoffee *_coffee, DialogSodaDispenser *_soda, DialogIceDispenser *_ice,
                     DialogSyrup *_syrup, DialogIcecream *_icecream, DialogOutlet *_outlet,
                     DialogBarcode *_barcode,  DialogMonitor *_monitor) :
    stock(_stock), robot(_robot), cup(_cup) , hot(_hot),
    coffee(_coffee), soda(_soda), ice(_ice),
    syrup(_syrup), icecream(_icecream), outlet(_outlet),
    barcode(_barcode), monitor(_monitor)
{
    connect(&timer, SIGNAL(timeout()), this, SLOT(onTimer()));
    timer.start(SCHEDULER_TIME_INTERVAL);

    last_order_flag = false;

    action_state = ACTION_STATE_INIT;

    prev_made_drink.pin = "";
    prev_made_drink.menu_name = "";
    prev_made_drink.recipe.clear();
    // test menu
//    ST_RECIPE_INFO temp;
//    temp.pin = "1111";
//    temp.recipe = stock->menu["0001"].recipe;
//    temp.menu_id = stock->menu["0001"].menu_id;
//    temp.menu_name = stock->menu["0001"].menu_name;
//    list_waiting.push_back(temp);
//    action_state = ACTION_STATE_IDLE;

}

void Scheduler::onTimer(){
    static unsigned int soda_flush_time_cnt = SODA_FLUSH_TIMEOUT;
    static int timeout = 0;
    static int timeout_coffee_dispense = 0;
    static int timeout_door[NUMBER_OF_OUTLET] = {0,0};

    static int option_shot_count = 0;

    static int cup_trycount = 0;
    static int cup_changed = 0;
    static int cup_selection = 0;
    static int cup_toggle_paper = 0;
    static int cup_toggle_pet = 0;

    static int sauce_shot_count = 0;

    static int syrup_start_loadcell = 0;
    static int icecream_start_loadcell = 0;

    static int coffee_milk_refill_message_flag = 0;
    static int coffee_command_check_count = 0;

    static int ice_toggle = 0;
    static int ice_dev_selection = 0;

    static int coffee_try_num = 0;

    static QDateTime startTime;
    static QDateTime prevTime;
    static int flag_takttime = 0;

//    static int tttt = 0;
//    if(tttt == 0){
//        ST_MENU t_menu = stock->menu["0001"];

//        qDebug() << t_menu.menu_id << ", " << t_menu.menu_name;
//        for(int j=0; j<t_menu.recipe.size(); j++){
//            qDebug() << "*****" << t_menu.recipe[j].ingredient << ", " << t_menu.recipe[j].amount;
//        }
//        tttt = 1;
//    }



    if(recall_order_flag == 1){
        recall_order_flag = 0;

//        for(int i=0; i<list_waiting.size(); i++){
//            pbarcode->recall_barcode_history(list_waiting[i].str_date, list_waiting[i].str_hour, list_waiting[i].trans_number);
//        }
//        list_waiting.clear();
    }

    if(recall_inprogressing_order_flag == 1){
        recall_inprogressing_order_flag = 0;

//        if(list_inprogress.size() > 0){
//            pbarcode->recall_barcode_history(list_inprogress[0].str_date, list_inprogress[0].str_hour, list_inprogress[0].trans_number);
//        }
//        list_inprogress.clear();
    }




    monitor->UpdateList_WaitingDrinks(list_waiting);
    monitor->UpdateList_InprogressDrinks(list_inprogress);
    monitor->UpdateList_CompletedDrinks(list_completed);
    monitor->UpdateList_DispensingDrinkgs(list_dispensing);

    soda_flush_time_cnt++;


    static unsigned int ext_coll_flag = 0;
    static unsigned int ext_coll_cnt = 0;
    if(OP_STATUS_OPERATING == PLATFORM_OPERATION_ON_OPERATING_STATE){
        if((sys_status.sdata.op_stat_collision_occur == 1) && (ext_coll_cnt < 3)){
            ext_coll_flag++;
            if(ext_coll_flag%10 == 0){
                robot->CollisionResume();
                ext_coll_cnt++;

                plog->write("[SCHEDULE OUTCOL] OUT COLLISION OCCUR " + QString::number(ext_coll_cnt));

            }
        }
    }

    switch(action_state){
    case ACTION_STATE_INIT:
        // For Initialization
        // Do Nothing
        break;
    case ACTION_STATE_IDLE:
        // In Operation
        ext_coll_flag = 0;
        ext_coll_cnt = 0;

        if(list_waiting.size() > 0){
            action_state = ACTION_STATE_GET_ORDER;
        }
        break;

    case ACTION_STATE_GET_ORDER:
        qDebug() << "ACTION_STATE_GET_ORDER";
        // New Order
        if(coffee->IsRefillMilkSoon()){
            // 우유 청소 중이거나 청소가 곧 임박할 경우
            coffee_milk_refill_message_flag = 1;
            monitor->display_msg = "위생적인 음료 제조를 위해 우유관을 청소하고 있습니다. 커피머신을 이용하지 않는 음료를 먼저 제조합니다.(5분 소요)";

            int order_selection = -1;
            for(int i=0; i<list_waiting.size(); i++){
                V_RECIPE temp_recipe = list_waiting[i].recipe;
                int recipe_no_coffee = true;
                for(int j=0; j<temp_recipe.size(); j++){
                    if(temp_recipe[j].ingredient == "COFFEE" || temp_recipe[j].ingredient == "MILK"){
                        recipe_no_coffee = false;
                        break;
                    }
                }
                if(recipe_no_coffee = true){
                    order_selection = i;
                    break;
                }
            }

            if(order_selection != -1){
                list_inprogress.push_back(list_waiting[order_selection]);
                list_waiting.remove(order_selection);
            }else{
                // keep waiting coffee milk refill finished
            }

        }else{
            if(coffee_milk_refill_message_flag == 1){
                coffee_milk_refill_message_flag = 0;
                monitor->display_msg = "";
            }
            list_inprogress.push_back(list_waiting[0]);
            list_waiting.pop_front();
        }

        plog->write("[SCHEDULE MOTION] START MAKING: PIN[" + list_inprogress[0].pin + "] / NAME[" + list_inprogress[0].menu_name + "]" );
        // Copy Recipes
        recipe_inprogress = list_inprogress[0].recipe;

        //check takttime
        plog->start_measure_takttime(list_inprogress[0].menu_name);
        startTime = QDateTime::currentDateTime();
        prevTime = QDateTime::currentDateTime();

        qDebug() << "List Inprogress: " << list_inprogress[0].menu_id;
        action_state = ACTION_STATE_MAKING_PROCESS;
        break;
    case ACTION_STATE_MAKING_PROCESS:
        // Define Next Action
        if(robot->RobotMoving == true)
            break;


        qDebug() << "ACTION_STATE_MAKING_PROCESS";

        if(recipe_inprogress.size() > 0){
            current_recipe_step = recipe_inprogress[0];

            recipe_inprogress.pop_front();

            QString next_type = current_recipe_step.ingredient;
            if(next_type == "PAPER_CUP"){
                action_state = ACTION_STATE_CUP_READY;
            }else if(next_type == "PET_CUP"){
                action_state = ACTION_STATE_CUP_READY;
            }else if(next_type == "ICECREAM"){
                action_state = ACTION_STATE_ICECREAM_READY;
            }else if(next_type.left(3) == "ICE"){
                action_state = ACTION_STATE_ICE_READY;
            }else if(next_type == "HOT_WATER"){
                action_state = ACTION_STATE_HOT_READY;
            }else if(next_type == "SODA"){
                action_state = ACTION_STATE_SODA_READY;
            }else if(next_type == "COFFEE"){
                action_state = ACTION_STATE_COFFEE_READY;
                QString temp_menu_id = list_inprogress[0].menu_id;
                if(stock->IsMenuOptionAvailable(temp_menu_id)){
                    if(list_inprogress[0].option == "001"){
                        option_shot_count = 1;
                    }else{
                        option_shot_count = 0;
                    }
                }else{
                    option_shot_count = 0;
                }
            }else if(next_type == "MILK"){
                action_state = ACTION_STATE_MILK_READY;
            }else if(next_type.left(5) == "SYRUP"){
                action_state = ACTION_STATE_SYRUP_READY;
            }else if(next_type.left(5) == "SAUCE"){
                action_state = ACTION_STATE_SAUCE_READY;
            }else if(next_type == "OUTLET"){
                action_state = ACTION_STATE_OUTLET_READY;
            }

        }else{
            if(last_order_flag == 1){
                last_order_flag = 0;
                action_state = ACTION_STATE_INIT;
            }else{
                action_state = ACTION_STATE_IDLE;
            }
        }
        break;

    //==========================================================================================
    case ACTION_STATE_CUP_READY:
        if(robot->RobotMoving == true)
            break;
        qDebug() << "ACTION_STATE_CUP_READY";
        plog->add_takttime("START CUP",prevTime.msecsTo(QDateTime::currentDateTime()));
        prevTime = QDateTime::currentDateTime();

        cup_changed = 0;
        cup_trycount = 0;

        keymotion = "READY_CUP";
        robot->RobotMoving = true;
        robot->MotionServerCommand(keymotion);

        action_state = ACTION_STATE_CUP_PLACE;
        break;

    case ACTION_STATE_CUP_PLACE:
        if(robot->RobotMoving == true)
            break;
        qDebug() << "ACTION_STATE_CUP_PLACE";

        if(current_recipe_step.ingredient == "PAPER_CUP"){
            int dev_available_1 = cup->IsCupAvailable(0);
            int dev_available_2 = cup->IsCupAvailable(1);
            if(dev_available_1 == 0 && dev_available_2 == 0){
                action_state = ACTION_STATE_CUP_ERROR;
                break;
            }else if(dev_available_2 == 0){
                keymotion = "SET_CUP_1";
                cup_selection = 0;
                cup_changed = 1;    // one port has problem
            }else if(dev_available_1 == 0){
                keymotion = "SET_CUP_2";
                cup_selection = 1;
                cup_changed = 1;    // one port has problem
            }else{
                cup_toggle_paper++;
                if(cup_toggle_paper%2 == 0){
                    keymotion = "SET_CUP_1";
                    cup_selection = 0;
                }else{
                    keymotion = "SET_CUP_2";
                    cup_selection = 1;
                }
            }
        }else if(current_recipe_step.ingredient == "PET_CUP"){
            int dev_available_1 = cup->IsCupAvailable(2);
            int dev_available_2 = cup->IsCupAvailable(3);
            if(dev_available_1 == 0 && dev_available_2 == 0){
                action_state = ACTION_STATE_CUP_ERROR;
                break;
            }else if(dev_available_2 == 0){
                keymotion = "SET_CUP_3";
                cup_selection = 2;
                cup_changed = 1;    // one port has problem
            }else if(dev_available_1 == 0){
                keymotion = "SET_CUP_4";
                cup_selection = 3;
                cup_changed = 1;    // one port has problem
            }else{
                cup_toggle_pet++;
                if(cup_toggle_pet%2 == 0){
                    keymotion = "SET_CUP_3";
                    cup_selection = 2;
                }else{
                    keymotion = "SET_CUP_4";
                    cup_selection = 3;
                }
            }
        }
        robot->RobotMoving = true;
        robot->MotionServerCommand(keymotion);

        action_state = ACTION_STATE_CUP_DISPENSE;
        break;

    case ACTION_STATE_CUP_DISPENSE:
        if(robot->RobotMoving == true)
            break;
        qDebug() << "ACTION_STATE_CUP_DISPENSE";

        plog->add_takttime("READY CUP",prevTime.msecsTo(QDateTime::currentDateTime()));
        prevTime = QDateTime::currentDateTime();

        if(CUP_DATA[cup_selection].dispense_op_flag == 0){
            cup->DispenseCup(cup_selection);
            action_state = ACTION_STATE_CUP_CHECK_IF_DISPENSED;
        }
        break;

    case ACTION_STATE_CUP_CHECK_IF_DISPENSED:
        if(CUP_DATA[cup_selection].prev_out_count != CUP_DATA[cup_selection].cup_out_count){
            int last_error = CUP_DATA[cup_selection].last_error;

            qDebug() << "ACTION_STATE_CUP_CHECK_IF_DISPENSED";
            if(last_error == 0){
                action_state = ACTION_STATE_CUP_GET;
            }else{
//                if(last_error == 1){
//                    // busy
//                }else if(last_error == 2){
//                    // cup already exist
//                }else if(last_error == 3){
//                    // dispense done, but cup not detected
//                }else if(last_error == 4){
//                    // timeout
//                }
                cup_trycount++;
                if(cup_trycount > 3){
                    action_state = ACTION_STATE_CUP_BACK_TO_READY;
                }else{
                    action_state = ACTION_STATE_CUP_DISPENSE;
                }
            }
        }
        break;

    case ACTION_STATE_CUP_GET:
        if(robot->RobotMoving == true)
            break;
        qDebug() << "ACTION_STATE_CUP_GET";
        plog->add_takttime("DISPENSE CUP",prevTime.msecsTo(QDateTime::currentDateTime()));
        prevTime = QDateTime::currentDateTime();

        if(cup_selection == 0){
            stock->UseStock("PAPER_CUP_1", 1);
            keymotion = "GET_CUP_1";
        }else if(cup_selection == 1){
            stock->UseStock("PAPER_CUP_2", 1);
            keymotion = "GET_CUP_2";
        }else if(cup_selection == 2){
            stock->UseStock("PET_CUP_1", 1);
            keymotion = "GET_CUP_3";
        }else if(cup_selection == 3){
            stock->UseStock("PET_CUP_2", 1);
            keymotion = "GET_CUP_4";
        }
        robot->RobotMoving = true;
        robot->MotionServerCommand(keymotion);

        action_state = ACTION_STATE_MAKING_PROCESS;
        break;

    case ACTION_STATE_CUP_BACK_TO_READY:
        if(robot->RobotMoving == true)
            break;
        qDebug() << "ACTION_STATE_CUP_BACK_TO_READY";

        if(cup_selection == 0){
            keymotion = "GET_CUP_1";
        }else if(cup_selection == 1){
            keymotion = "GET_CUP_2";
        }else if(cup_selection == 2){
            keymotion = "GET_CUP_3";
        }else if(cup_selection == 3){
            keymotion = "GET_CUP_4";
        }
        robot->RobotMoving = true;
        robot->MotionServerCommand(keymotion);

        action_state = ACTION_STATE_CUP_REPOSITIONING;
        break;

    case ACTION_STATE_CUP_REPOSITIONING:
        if(robot->RobotMoving == true)
            break;
        qDebug() << "ACTION_STATE_CUP_REPOSITIONING";

        if(cup_changed == 1){
            action_state = ACTION_STATE_CUP_ERROR;
            break;
        }

        if(current_recipe_step.ingredient == "PAPER_CUP"){
            cup_toggle_paper++;
            if(cup_toggle_paper%2 == 0){
                keymotion = "SET_CUP_1";
                cup_selection = 0;
            }else{
                keymotion = "SET_CUP_2";
                cup_selection = 1;
            }
        }else if(current_recipe_step.ingredient == "PET_CUP"){
            cup_toggle_pet++;
            if(cup_toggle_pet%2 == 0){
                keymotion = "SET_CUP_3";
                cup_selection = 2;
            }else{
                keymotion = "SET_CUP_4";
                cup_selection = 3;
            }
        }

        cup_changed = 1;
        robot->RobotMoving = true;
        robot->MotionServerCommand(keymotion);

        cup_trycount = 0;

        action_state = ACTION_STATE_CUP_DISPENSE;
        break;

    case ACTION_STATE_CUP_ERROR:
        qDebug() << "ACTION_STATE_CUP_ERROR";
        monitor->display_msg = "컵의 재고가 없습니다. 관리자를 호출해주세요^^";
        break;

    case ACTION_STATE_CUP_RECOVER:
        qDebug() << "ACTION_STATE_CUP_RECOVER";
        monitor->display_msg = "";
        cup_changed = 0;
        cup_trycount = 0;
        action_state = ACTION_STATE_CUP_PLACE;
        break;


    //==========================================================================================
    case ACTION_STATE_ICE_READY:
        if(robot->RobotMoving == true)
            break;
        qDebug() << "ACTION_STATE_ICE_READY";
        plog->add_takttime("START ICE",prevTime.msecsTo(QDateTime::currentDateTime()));
        prevTime = QDateTime::currentDateTime();


        if(ice_toggle < stock->ice_rotate_1){
            if(ice->IsIceDev_1_Available() == true){
                ice_dev_selection = 1;
            }else{
                if(ice->IsIceDev_2_Available() == true){
                    ice_dev_selection = 2;
                }else{
                    // no ice device available;
                    // fatal error
                    qDebug() << "no ice device available";
                    break;
                }
            }
        }else{
            if(ice->IsIceDev_2_Available() == true){
                ice_dev_selection = 2;
            }else{
                if(ice->IsIceDev_1_Available() == true){
                    ice_dev_selection = 1;
                }else{
                    // no ice device available;
                    // fatal error
                    qDebug() << "no ice device available";
                    break;
                }
            }
        }
        ice_toggle++;
        if(ice_toggle > stock->ice_rotate_1 + stock->ice_rotate_2 - 1)
            ice_toggle = 0;

        if(ice_dev_selection == 1){
            keymotion = "READY_ICE_1";
        }else if(ice_dev_selection == 2){
            keymotion = "READY_ICE_2";
        }
        robot->RobotMoving = true;
        robot->MotionServerCommand(keymotion);

        action_state = ACTION_STATE_ICE_PLACE;
        break;

    case ACTION_STATE_ICE_PLACE:
        if(robot->RobotMoving == true)
            break;
        qDebug() << "ACTION_STATE_ICE_PLACE";

        if(ice_dev_selection == 1){
            keymotion = "SET_ICE_1";
        }else if(ice_dev_selection == 2){
            keymotion = "SET_ICE_2";
        }
        robot->RobotMoving = true;
        robot->MotionServerCommand(keymotion);

        action_state = ACTION_STATE_ICE_DISPENSE;
        break;

    case ACTION_STATE_ICE_DISPENSE:
    {
        if(robot->RobotMoving == true)
            break;
        qDebug() << "ACTION_STATE_ICE_DISPENSE";

        plog->add_takttime("READY ICE",prevTime.msecsTo(QDateTime::currentDateTime()));
        prevTime = QDateTime::currentDateTime();

        int out_ms = 0;
        int out_ice_ms = 0;
        int out_water_ms = 0;
        if(ice_dev_selection == 1){
            QStringList amount = current_recipe_step.amount.split("/");
            ice->DispenseIceWater(0, int(amount[0].toFloat()*1000.0), int(amount[1].toFloat()*1000.0));
            out_ice_ms = int(amount[0].toFloat()*1000.0);
            out_water_ms = int(amount[1].toFloat()*1000.0);
        }else if(ice_dev_selection == 2){
            QStringList amount = current_recipe_step.amount.split("/");
            ice->DispenseIceWater(1, int(amount[0].toFloat()*1000.0), int(amount[1].toFloat()*1000.0));
            out_ice_ms = int(amount[0].toFloat()*1000.0);
            out_water_ms = int(amount[1].toFloat()*1000.0);
        }
        if(out_ice_ms > out_water_ms){
            out_ms = out_ice_ms;
        }else{
            out_ms = out_water_ms;
        }
        timeout = (out_ms+1000)/SCHEDULER_TIME_INTERVAL;

        action_state = ACTION_STATE_ICE_WAIT_DISPENSE_DONE;
        break;
    }

    case ACTION_STATE_ICE_WAIT_DISPENSE_DONE:
        if(--timeout > 0)
            break;
        qDebug() << "ACTION_STATE_ICE_WAIT_DISPENSE_DONE";

        if(ice_dev_selection == 1){
            if(ICE_DATA[0].prev_out_count != ICE_DATA[0].ice_out_count){
                action_state = ACTION_STATE_ICE_GET;
            }
        }else if(ice_dev_selection == 2){
            if(ICE_DATA[1].prev_out_count != ICE_DATA[1].ice_out_count){
                action_state = ACTION_STATE_ICE_GET;
            }
        }
        break;

    case ACTION_STATE_ICE_GET:
        if(robot->RobotMoving == true)
            break;
        qDebug() << "ACTION_STATE_ICE_GET";
        plog->add_takttime("DISPENSE ICE",prevTime.msecsTo(QDateTime::currentDateTime()));
        prevTime = QDateTime::currentDateTime();

        if(ice_dev_selection == 1){
            keymotion = "GET_ICE_1";
        }else if(ice_dev_selection == 2){
            keymotion = "GET_ICE_2";
        }
        robot->RobotMoving = true;
        robot->MotionServerCommand(keymotion);

        action_state = ACTION_STATE_MAKING_PROCESS;
        break;

    //==========================================================================================
    case ACTION_STATE_HOT_READY:
        if(robot->RobotMoving == true)
            break;
        qDebug() << "ACTION_STATE_HOT_READY";
        plog->add_takttime("START HOT",prevTime.msecsTo(QDateTime::currentDateTime()));
        prevTime = QDateTime::currentDateTime();

        keymotion = "READY_HOT";
        robot->RobotMoving = true;
        robot->MotionServerCommand(keymotion);

        action_state = ACTION_STATE_HOT_PLACE;
        break;

    case ACTION_STATE_HOT_PLACE:
        if(robot->RobotMoving == true)
            break;
        qDebug() << "ACTION_STATE_HOT_CUP_PLACE";

        keymotion = "SET_HOT";
        robot->RobotMoving = true;
        robot->MotionServerCommand(keymotion);

        action_state = ACTION_STATE_HOT_WAIT_PLACE;
//        action_state = ACTION_STATE_HOT_DISPENSE;
        break;

    case ACTION_STATE_HOT_WAIT_PLACE:
        if(robot->RobotMoving == true)
            break;
        qDebug() << "ACTION_STATE_HOT_WAIT_PLACE";

        // loadcell tare
        hot->Tare();
        timeout = LOADCELL_TARE_DELAY/SCHEDULER_TIME_INTERVAL;

        action_state = ACTION_STATE_HOT_WAIT_TARE;
        break;

    case ACTION_STATE_HOT_WAIT_TARE:
        if(robot->RobotMoving == true)
            break;
        if(--timeout > 0)
            break;
        qDebug() << "ACTION_STATE_HOT_WAIT_TARE";

        if(fabs(hot->LoadcellValue()) > 5){
            // tare error
            hot->Tare();
            timeout = LOADCELL_TARE_DELAY/SCHEDULER_TIME_INTERVAL;
        }else{
            action_state = ACTION_STATE_HOT_DISPENSE;
        }
        break;

    case ACTION_STATE_HOT_DISPENSE:
        if(robot->RobotMoving == true)
            break;
        qDebug() << "ACTION_STATE_HOT_DISPENSE";
        plog->add_takttime("READY HOT",prevTime.msecsTo(QDateTime::currentDateTime()));
        prevTime = QDateTime::currentDateTime();

        if(HOT_DATA[0].out_state == 0){
            hot->DispenseHotByWeight(current_recipe_step.amount.toInt());
            action_state = ACTION_STATE_HOT_WAIT_DISPENSE_DONE;
        }
        break;

    case ACTION_STATE_HOT_WAIT_DISPENSE_DONE:
        qDebug() << "ACTION_STATE_HOT_WAIT_DISPENSE_DONE";

        if(HOT_DATA[0].prev_out_count != HOT_DATA[0].out_count){
            int last_error = HOT_DATA[0].last_error;

            if(last_error == 0){
                action_state = ACTION_STATE_HOT_GET;
            }else{
                // hot dispenser error
                // set hot stock 0
                stock->SetDeviceError("HOT_WATER");
                action_state = ACTION_STATE_HOT_GET;
            }
        }
        break;

    case ACTION_STATE_HOT_GET:
        if(robot->RobotMoving == true)
            break;
        qDebug() << "ACTION_STATE_HOT_GET";
        plog->add_takttime("DISPENSE HOT",prevTime.msecsTo(QDateTime::currentDateTime()));
        prevTime = QDateTime::currentDateTime();

        keymotion = "GET_HOT";
        robot->RobotMoving = true;
        robot->MotionServerCommand(keymotion);

        action_state = ACTION_STATE_MAKING_PROCESS;
        break;

    //==========================================================================================
    case ACTION_STATE_SODA_READY:
        if(robot->RobotMoving == true)
            break;
        qDebug() << "ACTION_STATE_SODA_READY";

        plog->add_takttime("START SODA",prevTime.msecsTo(QDateTime::currentDateTime()));
        prevTime = QDateTime::currentDateTime();

        if(soda_flush_time_cnt > SODA_FLUSH_TIMEOUT/SCHEDULER_TIME_INTERVAL){
            soda->DispenseSodaByTime(3000);
            timeout = 3000/SCHEDULER_TIME_INTERVAL;
        }


        keymotion = "READY_SODA";
        robot->RobotMoving = true;
        robot->MotionServerCommand(keymotion);

        action_state = ACTION_STATE_SODA_PLACE;
        break;

    case ACTION_STATE_SODA_PLACE:
        if(robot->RobotMoving == true)
            break;
        if(--timeout > 0)
            break;
        qDebug() << "ACTION_STATE_SODA_PLACE";

        keymotion = "SET_SODA";
        robot->RobotMoving = true;
        robot->MotionServerCommand(keymotion);

        action_state = ACTION_STATE_SODA_WAIT_PLACE;
        break;

    case ACTION_STATE_SODA_WAIT_PLACE:
        if(robot->RobotMoving == true)
            break;
        qDebug() << "ACTION_STATE_SODA_WAIT_PLACE";

        // loadcell tare
        soda->Tare();
        timeout = LOADCELL_TARE_DELAY/SCHEDULER_TIME_INTERVAL;

        action_state = ACTION_STATE_SODA_WAIT_TARE;
        break;

    case ACTION_STATE_SODA_WAIT_TARE:
        if(robot->RobotMoving == true)
            break;
        if(--timeout > 0)
            break;
        qDebug() << "ACTION_STATE_SODA_WAIT_TARE";

        if(fabs(soda->LoadcellValue()) > 5){
            // tare error
            soda->Tare();
            timeout = LOADCELL_TARE_DELAY/SCHEDULER_TIME_INTERVAL;
        }else{
            action_state = ACTION_STATE_SODA_DISPENSE;
        }
        break;

    case ACTION_STATE_SODA_DISPENSE:
        if(robot->RobotMoving == true)
            break;
        qDebug() << "ACTION_STATE_SODA_DISPENSE";

        plog->add_takttime("READY SODA",prevTime.msecsTo(QDateTime::currentDateTime()));
        prevTime = QDateTime::currentDateTime();
        if(SODA_DATA[0].out_state == 0){
            soda->DispenseSodaByWeight(current_recipe_step.amount.toInt());
            soda_flush_time_cnt = 0;
            action_state = ACTION_STATE_SODA_WAIT_DISPENSE_DONE;
        }
        break;

    case ACTION_STATE_SODA_WAIT_DISPENSE_DONE:

        if(SODA_DATA[0].prev_out_count != SODA_DATA[0].out_count){
            qDebug() << "ACTION_STATE_SODA_WAIT_DISPENSE_DONE";
            int last_error = SODA_DATA[0].last_error;

            if(last_error == 0){
                timeout = SODA_WAIT_DELAY/SCHEDULER_TIME_INTERVAL;
                action_state = ACTION_STATE_SODA_GET;
            }else{
                // soda dispenser error
                // set soda stock 0
                stock->SetDeviceError("SODA");
                action_state = ACTION_STATE_SODA_GET;
            }
        }
        break;

    case ACTION_STATE_SODA_GET:
        if(robot->RobotMoving == true)
            break;
        if(--timeout > 0)
            break;
        qDebug() << "ACTION_STATE_SODA_GET";

        plog->add_takttime("DISPENSE SODA",prevTime.msecsTo(QDateTime::currentDateTime()));
        prevTime = QDateTime::currentDateTime();

        keymotion = "GET_SODA";
        robot->RobotMoving = true;
        robot->MotionServerCommand(keymotion);

        action_state = ACTION_STATE_MAKING_PROCESS;
        break;

    //==========================================================================================
    case ACTION_STATE_COFFEE_READY:
    case ACTION_STATE_MILK_READY:
        if(robot->RobotMoving == true)
            break;

        qDebug() << "ACTION_STATE_COFFEE_READY";

        plog->add_takttime("START COFFEE",prevTime.msecsTo(QDateTime::currentDateTime()));
        prevTime = QDateTime::currentDateTime();

        if(keymotion == "SET_COFFEE"){
            action_state = ACTION_STATE_COFFEE_DISPENSE;
        }else{
            keymotion = "READY_COFFEE";
            robot->RobotMoving = true;
            robot->MotionServerCommand(keymotion);

            action_state = ACTION_STATE_COFFEE_RINSE;
        }
        break;

    case ACTION_STATE_COFFEE_RINSE:
    {
        if(robot->RobotMoving == true)
            break;
        qDebug() << "ACTION_STATE_COFFEE_RINSE";

        if(current_recipe_step.amount == "ESP" && coffee->isRinseafterMilk){
            if(coffee->last_made_beverage != stock->coffee_key_btn["ESP"].toInt()){
                plog->write("[SCHEDULER] COFFEE RINSE : START!! BEFORE("+prev_made_drink.menu_name+")");
                coffee->startCleaning(COMMAND_FOAMER_RINSING);
                monitor->display_msg = "커피머신 청소중입니다. 잠시만 기다려주세요.";
                action_state = ACTION_STATE_COFFEE_RINSE_WAIT;
                timeout = 90000/SCHEDULER_TIME_INTERVAL;
                break;
            }
        }else{
            plog->write("[SCHEDULER] COFFEE RINSE : PASS!! BEFORE("+prev_made_drink.menu_name+")");
            action_state = ACTION_STATE_COFFEE_PLACE;
        }
        plog->write("[SCHEDULER] COFFEE RINSE : PASS!! BEFORE("+prev_made_drink.menu_name+")");
        action_state = ACTION_STATE_COFFEE_PLACE;
        break;
    }
    case ACTION_STATE_COFFEE_RINSE_WAIT:
    {
        if(coffee->cleaning_state==CLEANING_DONE){
            plog->write("[SCHEDULER] COFFEE RINSE : DONE");
            action_state = ACTION_STATE_COFFEE_PLACE;
            break;
        }else if(timeout-- < 0){
            plog->write("[SCHEDULER] COFFEE RINSE : TIMEOUT");
            action_state = ACTION_STATE_COFFEE_PLACE;
            break;
        }
        break;
    }
    case ACTION_STATE_COFFEE_PLACE:
        if(robot->RobotMoving == true)
            break;
        qDebug() << "ACTION_STATE_COFFEE_PLACE";

        if(coffee->status == MACHINE_MILK_REPLACEMENT || coffee->Machine.dueTimeMilkReplace < 40){
            plog->write("[COFFEE] RINSEEEEEEEEEEEEE"+QString::number(coffee->Machine.dueTimeMilkReplace));
            monitor->display_msg = "우유관을 청소하고 있습니다.(2-3분 소요)";
            break;
        }
        if(coffee->timeout_after_clean > 0 || coffee->status != MACHINE_READY){
            plog->write("[COFFEE] RINSE WAITTTTTTTTTTTT "+QString::number(coffee->timeout_after_clean));
            monitor->display_msg = "우유관을 청소하고 있습니다.(2-3분 소요)";
            break;
        }

        plog->write("[COFFEE] RINSE DONE "+QString::number(coffee->status));
        monitor->display_msg = "";


        keymotion = "SET_COFFEE";
        robot->RobotMoving = true;
        robot->MotionServerCommand(keymotion);
        timeout = 0;
        coffee_try_num = 0;
        action_state = ACTION_STATE_COFFEE_DISPENSE;
        break;

    case ACTION_STATE_COFFEE_DISPENSE:
        if(robot->RobotMoving == true)
            break;
        if(--timeout > 0)
            break;
        qDebug() << "ACTION_STATE_COFFEE_DISPENSE";

        plog->add_takttime("READY COFFEE",prevTime.msecsTo(QDateTime::currentDateTime()));
        prevTime = QDateTime::currentDateTime();

        coffee->makeBeverage(stock->coffee_key_btn[current_recipe_step.amount].toInt());
        qDebug() << "coffee dispense " << stock->coffee_key_btn[current_recipe_step.amount].toInt();
        timeout = COFFEE_RESPONSE_DELAY/SCHEDULER_TIME_INTERVAL;
        timeout_coffee_dispense = COFFEE_DISPENSE_TIMEOUT/SCHEDULER_TIME_INTERVAL;
        coffee_command_check_count = 0;

        action_state = ACTION_STATE_COFFEE_WAIT_DISPENSE_DONE;
        break;

    case ACTION_STATE_COFFEE_WAIT_DISPENSE_DONE:
        if(--timeout > 0)
            break;
//        qDebug() << "ACTION_STATE_COFFEE_WAIT_DISPENSE_DONE";

        coffee_command_check_count++;
        if(coffee_command_check_count > 10000/SCHEDULER_TIME_INTERVAL){
            if(coffee->coffee_command_flag == true){
                qDebug() << "COFFEE COMMAND FLAG NOT CLEARED!!!!";
                plog->write("[SCHEDULE COFFEE] COFFEE COMMAND FLAG NOT CLEARED!!!!");

                timeout = 1000/SCHEDULER_TIME_INTERVAL;
                action_state = ACTION_STATE_COFFEE_DISPENSE;
                break;
            }
        }

        if(coffee->beverage_state == BEVERAGE_DONE){
            plog->write("[SCHEDULER] ACTION_STATE_COFFEE_WAIT_DISPENSE_DONE");
            timeout = COFFEE_LAST_DELAY/SCHEDULER_TIME_INTERVAL;
            if(option_shot_count > 0){
                option_shot_count--;
                action_state = ACTION_STATE_COFFEE_SHOT_OPTION_DISPENSE;
            }else{
                action_state = ACTION_STATE_COFFEE_GET;
            }
        //}else if(coffee->beverage_state == BEVERAGE_DONE_BUT_NOT_READY || coffee->beverage_state == BEVERAGE_NONE){
        }else if(coffee->beverage_state == BEVERAGE_NONE){
            // coffee devicer error
            // set coffee stock 0
            if(coffee_try_num > 2){
                stock->SetDeviceError("COFFEE");
                action_state = ACTION_STATE_COFFEE_GET;
            }else{
                coffee_try_num++;
                timeout = 5000/SCHEDULER_TIME_INTERVAL;
                action_state = ACTION_STATE_COFFEE_DISPENSE;
            }
        }else if(coffee->beverage_state == BEVERAGE_DISPENSING){
            if(--timeout_coffee_dispense < 0){
                //Timeout
                plog->write("[SCHEDULER] ACTION_STATE_COFFEE_WAIT_DISPENSE_TIMEOUT_DONE");
                timeout = COFFEE_LAST_DELAY/SCHEDULER_TIME_INTERVAL;
                if(option_shot_count > 0){
                    option_shot_count--;
                    action_state = ACTION_STATE_COFFEE_SHOT_OPTION_DISPENSE;
                }else{
                    action_state = ACTION_STATE_COFFEE_GET;
                }
                //Clear Flag
                coffee->beverage_state = BEVERAGE_DONE;
                coffee->status = MACHINE_READY;
            }
        }
        break;

    case ACTION_STATE_COFFEE_SHOT_OPTION_DISPENSE:
    {
        if(robot->RobotMoving == true)
            break;


        plog->add_takttime("DISPENSE COFFEE AND SHOT",prevTime.msecsTo(QDateTime::currentDateTime()));
        prevTime = QDateTime::currentDateTime();

        qDebug() << "ACTION_STATE_COFFEE_SHOT_OPTION_DISPENSE";
        coffee->makeBeverage(stock->coffee_key_btn["ESP"].toInt());
        timeout = COFFEE_RESPONSE_DELAY/SCHEDULER_TIME_INTERVAL;

        action_state = ACTION_STATE_COFFEE_WAIT_DISPENSE_DONE;
        break;
    }
    case ACTION_STATE_COFFEE_GET:
    {
        if(recipe_inprogress.size() > 0){
            QString next_step = recipe_inprogress[0].ingredient;
            if(next_step == "COFFEE" || next_step == "MILK"){
                // do not move
                // next step also use coffee machine
                timeout = 0;
            }else{
                if(--timeout > 0)
                    break;
                keymotion = "GET_COFFEE";
                robot->RobotMoving = true;
                robot->MotionServerCommand(keymotion);
                plog->write("[SCHEDULER] GET COFFEE");

            }
        }else{
            if(--timeout > 0)
                break;
            keymotion = "GET_COFFEE";
            robot->RobotMoving = true;
            robot->MotionServerCommand(keymotion);
            plog->write("[SCHEDULER] GET COFFEE");
        }
        plog->add_takttime("DISPENSE COFFEE",prevTime.msecsTo(QDateTime::currentDateTime()));
        prevTime = QDateTime::currentDateTime();
        action_state = ACTION_STATE_MAKING_PROCESS;
        break;
    }
    //==========================================================================================
//    case ACTION_STATE_MILK_READY:
//        break;

    //==========================================================================================
    case ACTION_STATE_SYRUP_READY:
        if(robot->RobotMoving == true)
            break;
        qDebug() << "ACTION_STATE_SYRUP_READY";

        plog->add_takttime("START SYRUP",prevTime.msecsTo(QDateTime::currentDateTime()));
        prevTime = QDateTime::currentDateTime();
        if(keymotion == "SET_SYRUP"){
            // loadcell tare
            syrup->Tare();
            timeout = LOADCELL_TARE_DELAY/SCHEDULER_TIME_INTERVAL;

            action_state = ACTION_STATE_SYRUP_WAIT_TARE;
        }else{
            keymotion = "READY_SYRUP";
            robot->RobotMoving = true;
            robot->MotionServerCommand(keymotion);

            action_state = ACTION_STATE_SYRUP_PLACE;
        }
        break;

    case ACTION_STATE_SYRUP_PLACE:
        if(robot->RobotMoving == true)
            break;
        qDebug() << "ACTION_STATE_SYRUP_PLACE";

        keymotion = "SET_SYRUP";
        robot->RobotMoving = true;
        robot->MotionServerCommand(keymotion);

        action_state = ACTION_STATE_SYRUP_WAIT_PLACE;
        break;

    case ACTION_STATE_SYRUP_WAIT_PLACE:
        if(robot->RobotMoving == true)
            break;
        qDebug() << "ACTION_STATE_SYRUP_WAIT_PLACE";

        // loadcell tare
        syrup->Tare();
        timeout = LOADCELL_TARE_DELAY/SCHEDULER_TIME_INTERVAL;

        action_state = ACTION_STATE_SYRUP_WAIT_TARE;
        break;

    case ACTION_STATE_SYRUP_WAIT_TARE:
        if(robot->RobotMoving == true)
            break;
        if(--timeout > 0)
            break;
        qDebug() << "ACTION_STATE_SYRUP_WAIT_TARE";

        if(fabs(syrup->LoadcellValue()) > 5){
            // tare error
            syrup->Tare();
            timeout = LOADCELL_TARE_DELAY/SCHEDULER_TIME_INTERVAL;
        }else{
            action_state = ACTION_STATE_SYRUP_DISPENSE;
        }
        break;

    case ACTION_STATE_SYRUP_DISPENSE:
    {
        if(robot->RobotMoving == true)
            break;
        qDebug() << "ACTION_STATE_SYRUP_DISPENSE";

        plog->add_takttime("READY SYRUP",prevTime.msecsTo(QDateTime::currentDateTime()));
        prevTime = QDateTime::currentDateTime();
        int syrup_type = current_recipe_step.ingredient.split("_")[1].toInt()-1;
        int syrup_amount = current_recipe_step.amount.toInt();
        if(syrup_amount >= 100){
            syrup_amount = 100;
            qDebug() << "!!!! Wrong Syrup Amount";
        }
        syrup_start_loadcell = syrup->LoadcellValue();
        if(SYRUP_DATA[0].out_state == 0){
            syrup->DispenseSyrupByWeight(syrup_type, syrup_amount);
            action_state = ACTION_STATE_SYRUP_WAIT_DISPENSE_DONE;
        }
        break;
    }

    case ACTION_STATE_SYRUP_WAIT_DISPENSE_DONE:

        if(SYRUP_DATA[0].prev_out_count != SYRUP_DATA[0].out_count){
            qDebug() << "ACTION_STATE_SYRUP_WAIT_DISPENSE_DONE";

            int last_error = SYRUP_DATA[0].last_error;

            if(last_error == 0){
                action_state = ACTION_STATE_SYRUP_GET;
            }else{
                // syrup #X error
                // set syrup #X stock 0

                if(syrup->LoadcellValue() < 10)
                    stock->SetStock(current_recipe_step.ingredient, 0);
                action_state = ACTION_STATE_SYRUP_GET;
            }
        }
        break;

    case ACTION_STATE_SYRUP_GET:
    {
        if(robot->RobotMoving == true)
            break;
        qDebug() << "ACTION_STATE_SYRUP_GET";

        plog->add_takttime("DISPENSE SYRUP",prevTime.msecsTo(QDateTime::currentDateTime()));
        prevTime = QDateTime::currentDateTime();
        int current_loadcell = syrup->LoadcellValue();
        int used_amount = current_loadcell-syrup_start_loadcell;

        qDebug() << current_recipe_step.ingredient << " used " << used_amount;
        stock->UseStock(current_recipe_step.ingredient, used_amount);

        if(recipe_inprogress.size() > 0){
            QString next_step = recipe_inprogress[0].ingredient;
            if(next_step.left(5) == "SYRUP"){
                // do not move
                // next step also use syrup
            }else{
                keymotion = "GET_SYRUP";
                robot->RobotMoving = true;
                robot->MotionServerCommand(keymotion);
            }
        }else{
            keymotion = "GET_SYRUP";
            robot->RobotMoving = true;
            robot->MotionServerCommand(keymotion);
        }

        action_state = ACTION_STATE_MAKING_PROCESS;
        break;
    }

    //==========================================================================================
    case ACTION_STATE_SAUCE_READY:
        if(robot->RobotMoving == true)
            break;
        qDebug() << "ACTION_STATE_SAUCE_READY";

        plog->add_takttime("START BASE",prevTime.msecsTo(QDateTime::currentDateTime()));
        prevTime = QDateTime::currentDateTime();
        keymotion = "READY_BASE";
        robot->RobotMoving = true;
        robot->MotionServerCommand(keymotion);

        action_state = ACTION_STATE_SAUCE_PLACE;
        break;

    case ACTION_STATE_SAUCE_PLACE:
    {
        if(robot->RobotMoving == true)
            break;
        qDebug() << "ACTION_STATE_SAUCE_PLACE";

        int sauce_type = current_recipe_step.ingredient.split("_")[1].toInt();
        int sauce_amount = current_recipe_step.amount.toInt();
        sauce_shot_count = sauce_amount/20;

        keymotion = QString().sprintf("SET_BASE_%d", sauce_type);
        robot->RobotMoving = true;
        robot->MotionServerCommand(keymotion);

        action_state = ACTION_STATE_SAUCE_DISPENSE;
        break;
    }

    case ACTION_STATE_SAUCE_DISPENSE:
    {
        if(robot->RobotMoving == true)
            break;
        qDebug() << "ACTION_STATE_SAUCE_DISPENSE";

        plog->add_takttime("READY BASE",prevTime.msecsTo(QDateTime::currentDateTime()));
        prevTime = QDateTime::currentDateTime();
        int sauce_type = current_recipe_step.ingredient.split("_")[1].toInt();
        keymotion = "OUT_BASE";//QString().sprintf("OUT_BASE_%d", sauce_type);
        robot->RobotMoving = true;
        robot->MotionServerCommand(keymotion);

        sauce_shot_count--;
        if(sauce_shot_count > 0){
            action_state = ACTION_STATE_SAUCE_DISPENSE;
        }else{
            action_state = ACTION_STATE_SAUCE_GET;
        }
        break;
    }

    case ACTION_STATE_SAUCE_GET:
    {
        if(robot->RobotMoving == true)
            break;
        qDebug() << "ACTION_STATE_SAUCE_GET";

        plog->add_takttime("DISPENSE BASE",prevTime.msecsTo(QDateTime::currentDateTime()));
        prevTime = QDateTime::currentDateTime();
        stock->UseStock(current_recipe_step.ingredient, current_recipe_step.amount.toInt());

        int sauce_type = current_recipe_step.ingredient.split("_")[1].toInt();
        keymotion = QString().sprintf("GET_BASE_%d", sauce_type);
        robot->RobotMoving = true;
        robot->MotionServerCommand(keymotion);

        action_state = ACTION_STATE_MAKING_PROCESS;
        break;
    }

    //==========================================================================================
    case ACTION_STATE_ICECREAM_READY:
        if(robot->RobotMoving == true)
            break;
        qDebug() << "ACTION_STATE_ICECREAM_READY";

        plog->add_takttime("START ICECREAM",prevTime.msecsTo(QDateTime::currentDateTime()));
        prevTime = QDateTime::currentDateTime();
        keymotion = "READY_ICECREAM";
        robot->RobotMoving = true;
        robot->MotionServerCommand(keymotion);

        action_state = ACTION_STATE_ICECREAM_PLACE;
        break;

    case ACTION_STATE_ICECREAM_PLACE:
        if(robot->RobotMoving == true)
            break;
        qDebug() << "ACTION_STATE_ICECREAM_PLACE";

        keymotion = "SET_ICECREAM";
        robot->RobotMoving = true;
        robot->MotionServerCommand(keymotion);

        action_state = ACTION_STATE_ICECREAM_WAIT_PLACE;
        break;

    case ACTION_STATE_ICECREAM_WAIT_PLACE:
        if(robot->RobotMoving == true)
            break;
        qDebug() << "ACTION_STATE_ICECREAM_WAIT_PLACE";

        // loadcell tare
        icecream->Tare();
        timeout = LOADCELL_TARE_DELAY/SCHEDULER_TIME_INTERVAL;

        action_state = ACTION_STATE_ICECREAM_WAIT_TARE;
        break;

    case ACTION_STATE_ICECREAM_WAIT_TARE:
        if(robot->RobotMoving == true)
            break;
        if(--timeout > 0)
            break;
        qDebug() << "ACTION_STATE_ICECREAM_WAIT_TARE";

        if(fabs(icecream->LoadcellValue()) > 5){
            // tare error
            icecream->Tare();
            timeout = LOADCELL_TARE_DELAY/SCHEDULER_TIME_INTERVAL;
        }else{
            action_state = ACTION_STATE_ICECREAM_DISPENSE;
        }
        break;

    case ACTION_STATE_ICECREAM_DISPENSE:
        if(robot->RobotMoving == true)
            break;
        qDebug() << "ACTION_STATE_ICECREAM_DISPENSE";

        plog->add_takttime("READY ICECREAM",prevTime.msecsTo(QDateTime::currentDateTime()));
        prevTime = QDateTime::currentDateTime();
        icecream_start_loadcell = icecream->LoadcellValue();
        if(ICECREAM_DATA[0].out_state == 0){
            icecream->DispenseIcecreamByWeight(current_recipe_step.amount.toInt());
//            keymotion = "OUT_ICECREAM";
//            robot->RobotMoving = true;
//            robot->MotionServerCommand(keymotion);

            action_state = ACTION_STATE_ICECREAM_DISPENSE_DONE;
        }
        break;

    case ACTION_STATE_ICECREAM_DISPENSE_DONE:
        qDebug() << "ACTION_STATE_ICECREAM_DISPENSE_DONE";

        if(ICECREAM_DATA[0].prev_out_count != ICECREAM_DATA[0].out_count){
            int last_error = ICECREAM_DATA[0].last_error;

            if(last_error == 0){
                timeout = ICECREAM_WAIT_DELAY/SCHEDULER_TIME_INTERVAL;
                action_state = ACTION_STATE_ICECREAM_GET;
            }else{
                // icecream dispenser error
                // set icecream stock 0
                stock->SetDeviceError("ICECREAM");
                action_state = ACTION_STATE_ICECREAM_GET;
            }
        }
        break;

    case ACTION_STATE_ICECREAM_GET:
    {
        if(robot->RobotMoving == true)
            break;
        if(--timeout > 0)
            break;
        qDebug() << "ACTION_STATE_ICECREAM_GET";

        plog->add_takttime("DISPENSE ICECREAM",prevTime.msecsTo(QDateTime::currentDateTime()));
        prevTime = QDateTime::currentDateTime();
        int current_loadcell = icecream->LoadcellValue();
        int used_amount = current_loadcell-icecream_start_loadcell;

        qDebug() << current_recipe_step.ingredient << " used " << used_amount;
        stock->UseStock(current_recipe_step.ingredient, used_amount);

        keymotion = "GET_ICECREAM";
        robot->RobotMoving = true;
        robot->MotionServerCommand(keymotion);

        action_state = ACTION_STATE_MAKING_PROCESS;
        break;
    }


    //==========================================================================================
    case ACTION_STATE_OUTLET_READY:
        if(robot->RobotMoving == true)
            break;

        if(flag_takttime == 0){
            plog->add_takttime("START OUTLET",prevTime.msecsTo(QDateTime::currentDateTime()));
            prevTime = QDateTime::currentDateTime();
            flag_takttime = 1;
        }
//        if(outlet->IsOutletFull() == true){
//            // outlet is full --> put drink on the shelve
//        }else{
            outlet_cell_info = outlet->GetFreeCellInfo();
            if(outlet_cell_info.id_module == -1){
                qDebug()<<"ALL MODULES ARE RUNNiNG OR CELLS ARE OCCUPIED";
                monitor->display_msg = "모든 배출구에 음료가 찼습니다. 관리자를 호출해주세요^^";
                break;
            }

            if((outlet->IsModuleMoving(outlet_cell_info.id_module) == true) || (outlet->IsModuleRunning(outlet_cell_info.id_module) == true)){
                qDebug() << "Outlet is working.. Wait.." << outlet_cell_info.id_module;
                break;
            }
//            display->Set_Notice("");

            outlet->SetModuleRunning(outlet_cell_info.id_module, true);
            outlet->SetCellOccupancy(outlet_cell_info.id_module, outlet_cell_info.id_cell, CELL_OCC, list_inprogress[0].pin);

            outlet->SpinToLoad(outlet_cell_info.id_module, outlet_cell_info.id_cell);

            action_state = ACTION_STATE_OUTLET_MOVE_TO_MODULE;
            qDebug()<<"OUTLET READY: M:"<<outlet_cell_info.id_module<<" C:"<<outlet_cell_info.id_cell;
//        }
        break;

    case ACTION_STATE_OUTLET_MOVE_TO_MODULE:
        if(robot->RobotMoving == true)
            break;

        if(outlet_cell_info.id_module == 0)
            keymotion = "READY_OUTLET_1";
        else if(outlet_cell_info.id_module == 1)
            keymotion = "READY_OUTLET_2";

        robot->RobotMoving = true;
        robot->MotionServerCommand(keymotion);

        flag_takttime = 0;
        timeout = 500/SCHEDULER_TIME_INTERVAL;

        action_state = ACTION_STATE_OUTLET_CUP_PLACE;
        break;

    case ACTION_STATE_OUTLET_CUP_PLACE:
        if(robot->RobotMoving == true)
            break;
        if(--timeout > 0 )
            break;

        if(flag_takttime == 0){
            plog->add_takttime("READY OUTLET",prevTime.msecsTo(QDateTime::currentDateTime()));
            prevTime = QDateTime::currentDateTime();
            flag_takttime = 1;
        }

        if(outlet->IsModuleMoving(outlet_cell_info.id_module) == true)
            break;


        if(outlet->CheckSpinInLoadPos(outlet_cell_info.id_module, outlet_cell_info.id_cell) == false){   // new added by lim -- motion miss prevention
            timeout = 1000/SCHEDULER_TIME_INTERVAL;
            outlet->SpinToLoad(outlet_cell_info.id_module, outlet_cell_info.id_cell);
            break;
        }

        plog->add_takttime("READY OUTLET",prevTime.msecsTo(QDateTime::currentDateTime()));
        prevTime = QDateTime::currentDateTime();

        if(outlet_cell_info.id_module == 0) keymotion = "OUT_OUTLET_1";
        else if(outlet_cell_info.id_module == 1) keymotion = "OUT_OUTLET_2";

        robot->RobotMoving = true;
        robot->MotionServerCommand(keymotion);

        action_state = ACTION_STATE_OUTLET_DISPENSE_COMPLETED;
        qDebug()<<"OUTLET CUP PLACE: "<<keymotion;
        break;

    case ACTION_STATE_OUTLET_DISPENSE_COMPLETED:
        if(robot->RobotMoving == true) break;

//        outlet->SpinToExit(outlet_cell_info.id_module, outlet_cell_info.id_cell);

        plog->add_takttime("DISPENSE OUTLET",prevTime.msecsTo(QDateTime::currentDateTime()));
        prevTime = QDateTime::currentDateTime();

        if(outlet_cell_info.id_module == 0)
            keymotion = "INIT_POS";
        else if(outlet_cell_info.id_module == 1)
            keymotion = "INIT_POS";

        robot->RobotMoving = true;
        robot->MotionServerCommand(keymotion);


        qDebug()<<"OUTLET DISPENSE: "<< keymotion;
        action_state = ACTION_STATE_OUTLET_GET;
        break;

    case ACTION_STATE_OUTLET_GET:
    {
        if(robot->RobotMoving == true)
            break;
        if(--timeout > 0 )
            break;

        if(outlet->IsModuleMoving(outlet_cell_info.id_module) == true)
            break;


//        if(outlet->CheckSpinInExitPos(outlet_cell_info.id_module, outlet_cell_info.id_cell) == false){   // new added by lim -- motion miss prevention
//            timeout = 1000/SCHEDULER_TIME_INTERVAL;
//            outlet->SpinToExit(outlet_cell_info.id_module, outlet_cell_info.id_cell);
//            break;
//        }

        outlet->SetModuleRunning(outlet_cell_info.id_module, false);

        ST_COMPLETED_DRINK_INFO temp_info;
        temp_info.pin = list_inprogress[0].pin;
        temp_info.menu_id = list_inprogress[0].menu_id;
        temp_info.menu_name = list_inprogress[0].menu_name;
        temp_info.id_module = outlet_cell_info.id_module;
        temp_info.id_cell = outlet_cell_info.id_cell;

        prev_made_drink = list_inprogress[0];
        list_completed.push_back(temp_info);
        list_inprogress.clear();

        plog->write("[SCHEDULE MOTION] COMPLETE MAKING: PIN[" + temp_info.pin + "] / NAME[" + temp_info.menu_name +
                    "] --> OUTLET[" + QString::number(temp_info.id_module+1) + "/" + QString::number(temp_info.id_cell+1) + "]");

        plog->stop_measure_takttime(temp_info.menu_name, startTime.msecsTo(QDateTime::currentDateTime()));
        action_state = ACTION_STATE_MAKING_PROCESS;
        qDebug()<<"OUTLET GET: "<<keymotion;
        break;
    }


    default:
        break;
    }



    // Barcode Input for Dispensing Drinks
    if(barcode->NewInputNotification == true){
        barcode->NewInputNotification = false;
        QString barcode_pin = barcode->NewBarcodePin;

        if(barcode_pin.left(8) == "RBMASTER"){
            QStringList pin_masters = barcode_pin.split("_");
            if(pin_masters.size() > 2){
                int master_module = pin_masters[1].toInt()-1;
                int master_cell = pin_masters[2].toInt()-1;
                bool match = false;
                for(int i=0; i<list_completed.size();i++){
                    if(list_completed[i].id_module == master_module){
                        if(list_completed[i].id_cell == master_cell){
                            if(outlet->IsModuleMoving(master_module) == false && outlet->IsModuleRunning(master_module) == false){
                                list_dispensing[master_module].pin = list_completed[i].pin;
                                list_dispensing[master_module].menu_id = list_completed[i].menu_id;
                                list_dispensing[master_module].menu_name = list_completed[i].menu_name;

                                list_dispensing[master_module].id_module = list_completed[i].id_module;
                                list_dispensing[master_module].id_cell = list_completed[i].id_cell;
                                plog->write("[SCHEDULE OUTLET] DISPENSE REQUEST(FORCED) : PIN[" + list_completed[i].pin + "] / NAME[" + list_completed[i].menu_name +
                                            "] --> OUTLET[" + QString::number(list_completed[i].id_module+1) + "/" + QString::number(list_completed[i].id_cell+1) + "]");

                                outlet_state[master_module] = OUTLET_MODULE_READY;
                                list_completed.removeAt(i);
                                match  = true;
                                break;
                            }
                            else{
                                qDebug()<<"Module is Running: SOUNDS";
                            }
                        }
                    }
                }

                if(!match){
                    if(outlet->IsModuleMoving(master_module) == false && outlet->IsModuleRunning(master_module) == false){
                        SetForcedDispensing(master_module,master_cell);
                        plog->write("[SCHEDULE OUTLET] DISPENSE REQUEST(FORCED)--> OUTLET[" + QString::number(master_module+1) + "/" + QString::number(master_cell+1) + "]");
                    }
                    else{
                        qDebug()<<"Module is Running: SOUNDS";
                    }
                }
            }
        }
        for(int i=0; i<list_completed.size();i++){
            if(list_completed[i].pin == barcode_pin){

                int id_module = list_completed[i].id_module;
                if(outlet->IsModuleMoving(id_module) == false && outlet->IsModuleRunning(id_module) == false){

                    list_dispensing[id_module].pin = list_completed[i].pin;
                    list_dispensing[id_module].menu_id = list_completed[i].menu_id;
                    list_dispensing[id_module].menu_name = list_completed[i].menu_name;

                    list_dispensing[id_module].id_module = list_completed[i].id_module;
                    list_dispensing[id_module].id_cell = list_completed[i].id_cell;

                    plog->write("[SCHEDULE OUTLET] DISPENSE REQUEST: PIN[" + list_completed[i].pin + "] / NAME[" + list_completed[i].menu_name +
                                "] --> OUTLET[" + QString::number(list_completed[i].id_module+1) + "/" + QString::number(list_completed[i].id_cell+1) + "]");

                    outlet_state[id_module] = OUTLET_MODULE_READY;

                    list_completed.removeAt(i);
                    break;
                }
                else{
                    qDebug()<<"Module is Running: SOUNDS";
                }
            }
        }
    }





    // Outlet Schedule ========================================
    for(int i=0; i<NUMBER_OF_OUTLET; i++){
        switch(outlet_state[i]){
        case OUTLET_MODULE_IDLE:
            break;

        case OUTLET_MODULE_READY:
            outlet->SetModuleRunning(i, true);
            outlet_state[i] = OUTLET_MODULE_SPIN;
            qDebug()<<"OUTLET_READY"<<i;
            break;

        case OUTLET_MODULE_SPIN:
            outlet->SpinToExit(i, list_dispensing[i].id_cell);

            timeout_door[i] = 1500/SCHEDULER_TIME_INTERVAL;
            outlet_state[i] = OUTLET_MODULE_SPIN_WAIT;
            qDebug()<<"OUTLET_SPIN"<<i;
            break;

        case OUTLET_MODULE_SPIN_WAIT:
            if(--timeout_door[i] > 0)
                break;
            if(outlet->IsModuleMoving(i) == true)
                break;

            outlet_state[i] = OUTLET_MODULE_DOOR_OPEN;
            qDebug()<<"OUTLET_SPIN_WAIT"<<i;
            break;

        case OUTLET_MODULE_DOOR_OPEN:
            outlet->OpenDoor(i);
            timeout_door[i] = 1500/SCHEDULER_TIME_INTERVAL;

            outlet_state[i] = OUTLET_MODULE_DOOR_WAIT_IN_OPEN;
            qDebug()<<"OUTLET_OPEN"<<i;
            break;

        case OUTLET_MODULE_DOOR_WAIT_IN_OPEN:
            if(--timeout_door[i] > 0)
                break;
            if(outlet->IsModuleMoving(i) == true)
                break;

            if(outlet->CheckDoorInOpenPos(i) == false){  // new added by lim -- motion miss prevention
                outlet_state[i] = OUTLET_MODULE_DOOR_OPEN;
            }

            if(outlet->GetSonarSensor(i) < OUTLET_SONAR_SENSOR_THRESHOLD)
                break;
            else
                outlet_state[i] = OUTLET_MODULE_DOOR_CLOSE;

            timeout_door[i] = 3000/SCHEDULER_TIME_INTERVAL;
            break;

        case OUTLET_MODULE_DOOR_CLOSE:
            if(--timeout_door[i] >0)
                break;

            outlet->CloseDoor(i);
            timeout_door[i] = 1000/SCHEDULER_TIME_INTERVAL;

            outlet_state[i] = OUTLET_MODULE_DOOR_WAITE_IN_CLOSE;
            qDebug()<<"OUTLET_CLOSE"<<i;
            break;

        case OUTLET_MODULE_DOOR_WAITE_IN_CLOSE:
            if(outlet->GetSonarSensor(i) < OUTLET_SONAR_SENSOR_THRESHOLD){
                qDebug()<<"ULTRA SONIC Detected";
                outlet_state[i] = OUTLET_MODULE_DOOR_OPEN;
                break;
            }

            if(--timeout_door[i] >0)
                break;
            if(outlet->IsModuleMoving(i) == true)
                break;


            if(MOTOR_COL_ERROR(outlet->GetMotorStatus(i, OUTLET_DOOR)) == 1){
                qDebug()<<"OUTLET MODULE (DOOR): "<<i<<" COLLISION DETECTED"<<i;
                timeout_door[i] = 5000/SCHEDULER_TIME_INTERVAL;
                outlet_state[i] = OUTLET_MODULE_DOOR_CLOSE;
                break;
            }

            if(outlet->CheckDoorInClosePos(i) == false){  // new added by lim -- motion miss prevention
                outlet_state[i] = OUTLET_MODULE_DOOR_CLOSE;
            }

            timeout_door[i] = 500/SCHEDULER_TIME_INTERVAL;
            outlet_state[i] = OUTLET_MODULE_CHECK_CELL_OCC;
            break;

        case OUTLET_MODULE_CHECK_CELL_OCC:
            if(--timeout_door[i] >0)
                break;
            if(outlet->IsModuleMoving(i) == true)
                break;

            if(outlet->GetSonarSensor(i) < OUTLET_SONAR_SENSOR_THRESHOLD){
                //outlet->SetCellOccupancy(i, list_dispensing[i].id_cell, CELL_OCC);
            }
            else{
                outlet->SetCellOccupancy(i, list_dispensing[i].id_cell, CELL_EMP, "");
            }

            outlet->SetModuleRunning(i, false);
            outlet_state[i] = OUTLET_MODULE_COMPLETED;

            break;

        case OUTLET_MODULE_COMPLETED:
            plog->write("[SCHEDULE OUTLET] DISPENSE COMPLETE: PIN[" + list_dispensing[i].pin + "] / NAME[" + list_dispensing[i].menu_name +
                        "] --> OUTLET[" + QString::number(list_dispensing[i].id_module+1) + "/" + QString::number(list_dispensing[i].id_cell+1) + "]");

            list_dispensing[i].pin = "";
            qDebug()<<"OUTLET_COMPLETED"<<i;
            outlet_state[i] = OUTLET_MODULE_IDLE;
            break;
        }
    }




    // for test
//    robot->RobotMoving = false;
//    CUP_DATA[0].cup_out_count++;
//    CUP_DATA[1].cup_out_count++;
//    CUP_DATA[2].cup_out_count++;
//    CUP_DATA[3].cup_out_count++;
//    HOT_DATA[0].out_count++;
//    coffee->beverage_state = BEVERAGE_DONE;
}


int Scheduler::IsIdle(){
    if(list_waiting.size() > 0)
        return false;
    if(list_completed.size() > 0)
        return false;
    if(list_inprogress.size() > 0)
        return false;
    for(int i=0; i<NUMBER_OF_OUTLET; i++){
        if(list_dispensing[i].pin != ""){
            return false;
        }
    }
    return true;
}


void Scheduler::SetForcedDispensing(int id_module, int id_cell){
    if(outlet->IsModuleMoving(id_module) == false && outlet->IsModuleRunning(id_module) == false){
        list_dispensing[id_module].pin = OUTLET_DATA[id_module].cell_occupy_pin[id_cell];
        list_dispensing[id_module].id_module = id_module;
        list_dispensing[id_module].id_cell = id_cell;
        outlet_state[id_module] = OUTLET_MODULE_READY;


        // new fixed by lim -- error occurs when dispense initially occupied drinks
        // list_completed_info.removeAt(id_cell);
        for(int i=0; i<list_completed.size(); i++){
            if(list_completed[i].id_module == id_module && list_completed[i].id_cell == id_cell){
                list_completed.removeAt(i);
            }
        }
    }else{
        qDebug()<<"Module is Running: SOUNDS";
    }
}

void Scheduler::ClearWaitingList(){
//    if(list_inprogress.size() > 0){
//        list_inprogress.clear();
//    }
    list_waiting.clear();
}

void Scheduler::ClearCompletedList(){
    list_completed.clear();
}

void Scheduler::remove_inprogress_list(){
    if(list_inprogress.size() > 0){
        list_inprogress.clear();
    }
}

int Scheduler::get_waiting_size(){
    return list_waiting.size();
}

int Scheduler::get_complete_size(){
    int size = list_completed.size();

    return size;
}
void Scheduler::remove_waiting_list(int index){
    if(index < list_waiting.size()){
        list_waiting.remove(index);
    }
}

void Scheduler::SetRecallOrderFlag(){
    recall_order_flag = 1;
}
void Scheduler::SetRecallInprogressingOrderFlag(){
    recall_inprogressing_order_flag = 1;
}
