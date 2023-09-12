#include "DialogIceDispenser.h"
#include "ui_DialogIceDispenser.h"
#include "RBLAN2CAN.h"

extern RBLAN2CAN *plan;

DialogIceDispenser::DialogIceDispenser(QWidget *parent, DialogStock *_stock) :
    QDialog(parent), stock(_stock),
    ui(new Ui::DialogIceDispenser)
{
    ui->setupUi(this);


    FATAL_INFO_ICE_CONNECTION_ERROR_1 = 0;
    FATAL_INFO_ICE_CONNECTION_ERROR_2 = 0;
    FATAL_INFO_ICE_DEVICE_ERROR_1 = 0;
    FATAL_INFO_ICE_DEVICE_ERROR_2 = 0;

    FORCE_FATAL_ERROR_ICE_CONNECTION = 0;
    FORCE_FATAL_ERROR_ICE_DEVICE = 0;


    connect(&timer, SIGNAL(timeout()), this, SLOT(onTimer()));
    timer.start(200);
}

DialogIceDispenser::~DialogIceDispenser()
{
    delete ui;
}


void DialogIceDispenser::CheckFatalError(){
    // FATAL INFORMATION=============================================
    if(ICE_DATA[0].connection_status == 0 || ICE_DATA[0].data_connection == 0){
        FATAL_INFO_ICE_CONNECTION_ERROR_1 = 1;
    }else{
        FATAL_INFO_ICE_CONNECTION_ERROR_1 = 0;
    }
    if(ICE_DATA[1].connection_status == 0 || ICE_DATA[1].data_connection == 0){
        FATAL_INFO_ICE_CONNECTION_ERROR_2 = 1;
    }else{
        FATAL_INFO_ICE_CONNECTION_ERROR_2 = 0;
    }


    if((ICE_DATA[0].status.B[1] & 0x0F) != 0){
        FATAL_INFO_ICE_DEVICE_ERROR_1 = 1;
    }else{
        FATAL_INFO_ICE_DEVICE_ERROR_1 = 1;
    }
    if((ICE_DATA[1].status.B[1] & 0x0F) != 0){
        FATAL_INFO_ICE_DEVICE_ERROR_2 = 1;
    }else{
        FATAL_INFO_ICE_DEVICE_ERROR_2 = 1;
    }


//    // FATAL ERROR ===================================================
//    if(OP_STATUS_OPERATING == PLATFORM_OPERATION_ON_OPERATING_STATE){
//        if(FATAL_INFO_ICE_CONNECTION_ERROR == 1){
//            FORCE_FATAL_ERROR_ICE_CONNECTION = 1;
//        }
//        if(FATAL_INFO_ICE_DEVICE_ERROR == 1){
//            FORCE_FATAL_ERROR_ICE_DEVICE = 1;
//        }
//    }


    // stock device error handling
    if(IsIceAvailable(0) == 0){
        stock->SetDeviceError("ICE_1");
    }else{
        stock->ClearDeviceError("ICE_1");
    }
    if(IsIceAvailable(1) == 0){
        stock->SetDeviceError("ICE_2");
    }else{
        stock->ClearDeviceError("ICE_2");
    }
}


int DialogIceDispenser::IsIceAvailable(int dev){
    if(ICE_DATA[dev].connection_status == 1 && ICE_DATA[dev].data_connection == 1){
        // device available check
        if((ICE_DATA[dev].status.B[1] & 0x0F) == 0){
            return true;
        }else{
            return false;
        }
    }else{
        return false;
    }
}

void DialogIceDispenser::onTimer(){
    if(IS_UI_LOCK){
        ui->GB_ICE->setEnabled(false);
    }else{
        ui->GB_ICE->setEnabled(true);
    }

    if(plan->sockConnectionStatus == false){
        SetLEColor(ui->LE_ICE_CONNECTION, COLOR_UNDETERMINED);
        ui->LB_STATUS_COMM_MODE->setText("-");

        ui->LB_STATUS_COMP_WORKING->setText("-");
        ui->LB_STATUS_GEAR_WORKING->setText("-");
        ui->LB_STATUS_OUT_SOL_DETECT->setText("-");
        ui->LB_STATUS_CUP_LEVER_DETECT->setText("-");
        ui->LB_STATUS_FULL_ICE->setText("-");
        ui->LE_ICE_ERROR->setText("-");
        ui->LB_ERROR_TYPE->setText("-");
        SetLEColor(ui->LE_ICE_ERROR, COLOR_UNDETERMINED);
        ui->LB_STATUS_LAST_ICE_TIME->setText("-");
        ui->LB_STATUS_LAST_WATER_TIME->setText("-");

        ui->LB_STATUS_AMBIENT_TEMP_LOW->setText("-");
        ui->LB_STATUS_AMBIENT_TEMP_HIGH->setText("-");
        ui->LB_STATUS_AMBIENT_TEMP_NOW->setText("-");

        ui->LB_STATUS_EVAPORATOR_TEMP->setText("-");
        ui->LB_STATUS_CONDENSOR_TEMP->setText("-");
        ui->LE_ICE_CHECK_COUNT->setText("-");

        //--------------------
        SetLEColor(ui->LE_ICE_CONNECTION_2, COLOR_UNDETERMINED);
        ui->LB_STATUS_COMM_MODE_2->setText("-");

        ui->LB_STATUS_COMP_WORKING_2->setText("-");
        ui->LB_STATUS_GEAR_WORKING_2->setText("-");
        ui->LB_STATUS_OUT_SOL_DETECT_2->setText("-");
        ui->LB_STATUS_CUP_LEVER_DETECT_2->setText("-");
        ui->LB_STATUS_FULL_ICE_2->setText("-");
        ui->LE_ICE_ERROR_2->setText("-");
        ui->LB_ERROR_TYPE_2->setText("-");
        SetLEColor(ui->LE_ICE_ERROR_2, COLOR_UNDETERMINED);
        ui->LB_STATUS_LAST_ICE_TIME_2->setText("-");
        ui->LB_STATUS_LAST_WATER_TIME_2->setText("-");

        ui->LB_STATUS_AMBIENT_TEMP_LOW_2->setText("-");
        ui->LB_STATUS_AMBIENT_TEMP_HIGH_2->setText("-");
        ui->LB_STATUS_AMBIENT_TEMP_NOW_2->setText("-");

        ui->LB_STATUS_EVAPORATOR_TEMP_2->setText("-");
        ui->LB_STATUS_CONDENSOR_TEMP_2->setText("-");
        ui->LE_ICE_CHECK_COUNT_2->setText("-");
    }else{

        CheckFatalError();


        if(ICE_DATA[0].connection_status == 1){
            SetLEColor(ui->LE_ICE_CONNECTION, COLOR_GOOD);
        }else{
            SetLEColor(ui->LE_ICE_CONNECTION, COLOR_BAD);
        }
        if(ICE_DATA[0].data_connection == 1){
            SetLEColor(ui->LE_ICE_DATA_CONNECTION, COLOR_GOOD);
        }else{
            SetLEColor(ui->LE_ICE_DATA_CONNECTION, COLOR_BAD);
        }



        if(ICE_DATA[0].connection_status == 1 && ICE_DATA[0].data_connection == 1){

            if(ICE_DATA[0].status.b.comm_mode == 1){
                ui->LB_STATUS_COMM_MODE->setText("RS232");
            }else{
                ui->LB_STATUS_COMM_MODE->setText("일반모드");
            }

            if(ICE_DATA[0].status.b.comp_working == 1){
                ui->LB_STATUS_COMP_WORKING->setText("동작중");
            }else{
                ui->LB_STATUS_COMP_WORKING->setText("정지상태");
            }

            if(ICE_DATA[0].status.b.gear_motor_working == 1){
                ui->LB_STATUS_GEAR_WORKING->setText("동작중");
            }else{
                ui->LB_STATUS_GEAR_WORKING->setText("정지상태");
            }

            if(ICE_DATA[0].status.b.out_sol_detected == 1){
                ui->LB_STATUS_OUT_SOL_DETECT->setText("감지");
            }else{
                ui->LB_STATUS_OUT_SOL_DETECT->setText("미감지");
            }

            if(ICE_DATA[0].status.b.cup_lever_detected == 1){
                ui->LB_STATUS_CUP_LEVER_DETECT->setText("감지");
            }else{
                ui->LB_STATUS_CUP_LEVER_DETECT->setText("미감지");
            }

            if(ICE_DATA[0].status.b.full_ice == 1){
                ui->LB_STATUS_FULL_ICE->setText("만빙");
            }else{
                ui->LB_STATUS_FULL_ICE->setText("만빙아님");
            }


            ui->LE_ICE_ERROR->setText(QString().sprintf("%1d%1d%1d%1d", ICE_DATA[0].status.b.err_code_4, ICE_DATA[0].status.b.err_code_3, ICE_DATA[0].status.b.err_code_2, ICE_DATA[0].status.b.err_code_1));
            int temp_error = ICE_DATA[0].status.B[1] & 0x0F;
            if(temp_error != 0){
                QString temp_ice_string = "";
                switch(temp_error){
                case 1:
                    temp_ice_string += "급수불량 /";
                    break;
                case 2:
                    temp_ice_string += "배수불량 /";
                    break;
                case 3:
                    temp_ice_string += "내부온도저온 /";
                    break;
                case 4:
                    temp_ice_string += "내부온도고온 /";
                    break;
                case 5:
                    temp_ice_string += "콘덴서과열 /";
                    break;
                case 6:
                    temp_ice_string += "증발기과냉 /";
                    break;
                case 7:
                    temp_ice_string += "제빙모터이상 /";
                    break;
                case 8:
                    temp_ice_string += "제빙기능불량 /";
                    break;
                case 9:
                    temp_ice_string += "정기점검알람 /";
                    break;
                case 15:
                    temp_ice_string += "팬모터이상 /";
                    break;
                default:
                    temp_ice_string += "원인불명 /";
                    break;
                }
                SetLEColor(ui->LE_ICE_ERROR, COLOR_BAD);
                ui->LB_ERROR_TYPE->setText(temp_ice_string);
                ice_1_error = temp_ice_string;
            }else{
                SetLEColor(ui->LE_ICE_ERROR, COLOR_GOOD);
                ui->LB_ERROR_TYPE->setText("에러없음");
                ice_1_error = "에러없음";
            }

            ui->LB_STATUS_LAST_ICE_TIME->setText(QString().sprintf("%.1f", float(ICE_DATA[0].last_ice_out_time/16*10 + ICE_DATA[0].last_ice_out_time%16)/10.0));
            ui->LB_STATUS_LAST_WATER_TIME->setText(QString().sprintf("%.1f", float(ICE_DATA[0].last_water_out_time/16*10 + ICE_DATA[0].last_water_out_time%16)/10.0));

            ui->LB_STATUS_AMBIENT_TEMP_LOW->setText(QString().sprintf("%d", ICE_DATA[0].setting_ambient_temp_low));
            ui->LB_STATUS_AMBIENT_TEMP_HIGH->setText(QString().sprintf("%d", ICE_DATA[0].setting_ambient_temp_high));
            ui->LB_STATUS_AMBIENT_TEMP_NOW->setText(QString().sprintf("%d", ICE_DATA[0].ambient_temp));

            ui->LB_STATUS_EVAPORATOR_TEMP->setText(QString().sprintf("%d", (char)(ICE_DATA[0].evaporator_temp)));
            ui->LB_STATUS_CONDENSOR_TEMP->setText(QString().sprintf("%d", ICE_DATA[0].condensor_temp));

            ui->LE_ICE_CHECK_COUNT->setText(QString().sprintf("%d", ICE_DATA[0].ice_out_count));
        }else{
            // device available check
            stock->SetDeviceError("ICE_1");

            ui->LB_STATUS_COMM_MODE->setText("-");

            ui->LB_STATUS_COMP_WORKING->setText("-");
            ui->LB_STATUS_GEAR_WORKING->setText("-");
            ui->LB_STATUS_OUT_SOL_DETECT->setText("-");
            ui->LB_STATUS_CUP_LEVER_DETECT->setText("-");
            ui->LB_STATUS_FULL_ICE->setText("-");
            ui->LE_ICE_ERROR->setText("-");
            ui->LB_ERROR_TYPE->setText("-");
            SetLEColor(ui->LE_ICE_ERROR, COLOR_UNDETERMINED);
            ui->LB_STATUS_LAST_ICE_TIME->setText("-");
            ui->LB_STATUS_LAST_WATER_TIME->setText("-");

            ui->LB_STATUS_AMBIENT_TEMP_LOW->setText("-");
            ui->LB_STATUS_AMBIENT_TEMP_HIGH->setText("-");
            ui->LB_STATUS_AMBIENT_TEMP_NOW->setText("-");

            ui->LB_STATUS_EVAPORATOR_TEMP->setText("-");
            ui->LB_STATUS_CONDENSOR_TEMP->setText("-");
            ui->LE_ICE_CHECK_COUNT->setText("-");
        }


        //-----------------------------------
        if(ICE_DATA[1].connection_status == 1){
            SetLEColor(ui->LE_ICE_CONNECTION_2, COLOR_GOOD);
        }else{
            SetLEColor(ui->LE_ICE_CONNECTION_2, COLOR_BAD);
        }
        if(ICE_DATA[1].data_connection == 1){
            SetLEColor(ui->LE_ICE_DATA_CONNECTION_2, COLOR_GOOD);
        }else{
            SetLEColor(ui->LE_ICE_DATA_CONNECTION_2, COLOR_BAD);
        }

        if(ICE_DATA[1].connection_status == 1 && ICE_DATA[1].data_connection == 1){

            if(ICE_DATA[1].status.b.comm_mode == 1){
                ui->LB_STATUS_COMM_MODE_2->setText("RS232");
            }else{
                ui->LB_STATUS_COMM_MODE_2->setText("일반모드");
            }

            if(ICE_DATA[1].status.b.comp_working == 1){
                ui->LB_STATUS_COMP_WORKING_2->setText("동작중");
            }else{
                ui->LB_STATUS_COMP_WORKING_2->setText("정지상태");
            }

            if(ICE_DATA[1].status.b.gear_motor_working == 1){
                ui->LB_STATUS_GEAR_WORKING_2->setText("동작중");
            }else{
                ui->LB_STATUS_GEAR_WORKING_2->setText("정지상태");
            }

            if(ICE_DATA[1].status.b.out_sol_detected == 1){
                ui->LB_STATUS_OUT_SOL_DETECT_2->setText("감지");
            }else{
                ui->LB_STATUS_OUT_SOL_DETECT_2->setText("미감지");
            }

            if(ICE_DATA[1].status.b.cup_lever_detected == 1){
                ui->LB_STATUS_CUP_LEVER_DETECT_2->setText("감지");
            }else{
                ui->LB_STATUS_CUP_LEVER_DETECT_2->setText("미감지");
            }

            if(ICE_DATA[1].status.b.full_ice == 1){
                ui->LB_STATUS_FULL_ICE_2->setText("만빙");
            }else{
                ui->LB_STATUS_FULL_ICE_2->setText("만빙아님");
            }


            ui->LE_ICE_ERROR_2->setText(QString().sprintf("%1d%1d%1d%1d", ICE_DATA[1].status.b.err_code_4, ICE_DATA[1].status.b.err_code_3, ICE_DATA[1].status.b.err_code_2, ICE_DATA[1].status.b.err_code_1));
            int temp_error2 = ICE_DATA[1].status.B[1] & 0x0F;
            if(temp_error2 != 0){
                QString temp_ice_string = "";
                switch(temp_error2){
                case 1:
                    temp_ice_string += "급수불량 /";
                    break;
                case 2:
                    temp_ice_string += "배수불량 /";
                    break;
                case 3:
                    temp_ice_string += "내부온도저온 /";
                    break;
                case 4:
                    temp_ice_string += "내부온도고온 /";
                    break;
                case 5:
                    temp_ice_string += "콘덴서과열 /";
                    break;
                case 6:
                    temp_ice_string += "증발기과냉 /";
                    break;
                case 7:
                    temp_ice_string += "제빙모터이상 /";
                    break;
                case 8:
                    temp_ice_string += "제빙기능불량 /";
                    break;
                case 9:
                    temp_ice_string += "정기점검알람 /";
                    break;
                case 15:
                    temp_ice_string += "팬모터이상 /";
                    break;
                default:
                    temp_ice_string += "원인불명 /";
                    break;
                }
                SetLEColor(ui->LE_ICE_ERROR_2, COLOR_BAD);
                ui->LB_ERROR_TYPE_2->setText(temp_ice_string);
                ice_2_error = temp_ice_string;
            }else{
                SetLEColor(ui->LE_ICE_ERROR_2, COLOR_GOOD);
                ui->LB_ERROR_TYPE_2->setText("에러없음");
                ice_2_error = "에러없음";
            }

            ui->LB_STATUS_LAST_ICE_TIME_2->setText(QString().sprintf("%.1f", float(ICE_DATA[1].last_ice_out_time/16*10 + ICE_DATA[0].last_ice_out_time%16)/10.0));
            ui->LB_STATUS_LAST_WATER_TIME_2->setText(QString().sprintf("%.1f", float(ICE_DATA[1].last_water_out_time/16*10 + ICE_DATA[0].last_water_out_time%16)/10.0));

            ui->LB_STATUS_AMBIENT_TEMP_LOW_2->setText(QString().sprintf("%d", ICE_DATA[1].setting_ambient_temp_low));
            ui->LB_STATUS_AMBIENT_TEMP_HIGH_2->setText(QString().sprintf("%d", ICE_DATA[1].setting_ambient_temp_high));
            ui->LB_STATUS_AMBIENT_TEMP_NOW_2->setText(QString().sprintf("%d", ICE_DATA[1].ambient_temp));

            ui->LB_STATUS_EVAPORATOR_TEMP_2->setText(QString().sprintf("%d", (char)(ICE_DATA[1].evaporator_temp)));
            ui->LB_STATUS_CONDENSOR_TEMP_2->setText(QString().sprintf("%d", ICE_DATA[1].condensor_temp));

            ui->LE_ICE_CHECK_COUNT_2->setText(QString().sprintf("%d", ICE_DATA[1].ice_out_count));
        }else{
            // device available check
            stock->SetDeviceError("ICE_2");

            ui->LB_STATUS_COMM_MODE_2->setText("-");

            ui->LB_STATUS_COMP_WORKING_2->setText("-");
            ui->LB_STATUS_GEAR_WORKING_2->setText("-");
            ui->LB_STATUS_OUT_SOL_DETECT_2->setText("-");
            ui->LB_STATUS_CUP_LEVER_DETECT_2->setText("-");
            ui->LB_STATUS_FULL_ICE_2->setText("-");
            ui->LE_ICE_ERROR_2->setText("-");
            ui->LB_ERROR_TYPE_2->setText("-");
            SetLEColor(ui->LE_ICE_ERROR_2, COLOR_UNDETERMINED);
            ui->LB_STATUS_LAST_ICE_TIME_2->setText("-");
            ui->LB_STATUS_LAST_WATER_TIME_2->setText("-");

            ui->LB_STATUS_AMBIENT_TEMP_LOW_2->setText("-");
            ui->LB_STATUS_AMBIENT_TEMP_HIGH_2->setText("-");
            ui->LB_STATUS_AMBIENT_TEMP_NOW_2->setText("-");

            ui->LB_STATUS_EVAPORATOR_TEMP_2->setText("-");
            ui->LB_STATUS_CONDENSOR_TEMP_2->setText("-");
            ui->LE_ICE_CHECK_COUNT_2->setText("-");
        }
    }
}


void DialogIceDispenser::DispenseIceWater(int target, int ice_time_ms, int water_time_ms){
    ICE_DATA[target].prev_out_count = ICE_DATA[target].ice_out_count;
    plan->SendControlData(DEV_SEND_ID_ICE_DISPENSER, target, 0x00, ice_time_ms, water_time_ms);
}
void DialogIceDispenser::ChangeCommMode(int target, int comm_mode, int cup_ignore){
    plan->SendControlData(DEV_SEND_ID_ICE_DISPENSER, target, 0x01, comm_mode, cup_ignore);
}
void DialogIceDispenser::ClearStatus(int target){
    plan->SendControlData(DEV_SEND_ID_ICE_DISPENSER, target, 0x02, 0, 0);
}
void DialogIceDispenser::SetTimeout(int target, int timeout){
    plan->SendControlData(DEV_SEND_ID_ICE_DISPENSER, target, 0x03, timeout, 0);
}
void DialogIceDispenser::Reboot(int target){
    plan->SendControlData(DEV_SEND_ID_ICE_DISPENSER, target, 0x04, 0, 0);
}
void DialogIceDispenser::SetAmbientTemperature(int target, int tempL, int tempH){
    plan->SendControlData(DEV_SEND_ID_ICE_DISPENSER, target, 0x05, tempL, tempH);
}



void DialogIceDispenser::on_BTN_ICE_TEST_ICE_OUT_clicked(){
    int ice_time = (int)(ui->LE_ICE_TEST_ICE_OUT_TIME->text().toFloat()*1000.0);
    int water_time = (int)(ui->LE_ICE_TEST_WATER_OUT_TIME->text().toFloat()*1000.0);
    DispenseIceWater(0, ice_time, water_time);
    plog->write("[UI OPERATION - ICE] 출빙-출수 1");
}

void DialogIceDispenser::on_BTN_ICE_CHANGE_COMM_MODE_clicked(){
    int comm_mode = ui->CB_ICE_COMM_MODE->currentIndex();
    int cup_ignore = ui->CB_ICE_CUP_IGNORE->currentIndex();
    ChangeCommMode(0, comm_mode, cup_ignore);
    plog->write("[UI OPERATION - ICE] 통신모드변경 1");
}

void DialogIceDispenser::on_BTN_ICE_TEST_STATUS_CLEAR_clicked(){
    ClearStatus(0);
    plog->write("[UI OPERATION - ICE] 상태클리어 1");
}

void DialogIceDispenser::on_BTN_ICE_CHANGE_ICE_OUT_TIME_clicked(){
//    int sec = ui->LE_ICE_SETTING_ICE_OUT_TIME_MIN->text().toInt()*60 + ui->LE_ICE_SETTING_ICE_OUT_TIME_SEC->text().toInt();
//    if(sec > 255){
//        sec = 255;
//    }
//    SetTimeout(0, sec);
    plog->write("[UI OPERATION - ICE] 타임아웃 세팅 1");
}

void DialogIceDispenser::on_BTN_ICE_TEST_REBOOT_clicked(){
    Reboot(0);
    plog->write("[UI OPERATION - ICE] 제빙기 리셋 1");
}

void DialogIceDispenser::on_BTN_ICE_CHANGE_AMBIENT_TEMP_clicked(){
//    SetAmbientTemperature(0, ui->LE_ICE_SETTING_AMBIENT_TEMP_LOW->text().toInt(), ui->LE_ICE_SETTING_AMBIENT_TEMP_HIGH->text().toInt());
    plog->write("[UI OPERATION - ICE] 온도 세팅 1");
}


void DialogIceDispenser::on_BTN_ICE_TEST_ICE_OUT_2_clicked(){
    int ice_time = (int)(ui->LE_ICE_TEST_ICE_OUT_TIME_2->text().toFloat()*1000.0);
    int water_time = (int)(ui->LE_ICE_TEST_WATER_OUT_TIME_2->text().toFloat()*1000.0);
    DispenseIceWater(1, ice_time, water_time);
    plog->write("[UI OPERATION - ICE] 출빙-출수 2");
}

void DialogIceDispenser::on_BTN_ICE_CHANGE_COMM_MODE_2_clicked(){
    int comm_mode = ui->CB_ICE_COMM_MODE_2->currentIndex();
    int cup_ignore = ui->CB_ICE_CUP_IGNORE_2->currentIndex();
    ChangeCommMode(1, comm_mode, cup_ignore);
    plog->write("[UI OPERATION - ICE] 통신모드변경 2");
}

void DialogIceDispenser::on_BTN_ICE_CHANGE_ICE_OUT_TIME_2_clicked(){
//    int sec = ui->LE_ICE_SETTING_ICE_OUT_TIME_MIN_2->text().toInt()*60 + ui->LE_ICE_SETTING_ICE_OUT_TIME_SEC_2->text().toInt();
//    if(sec > 255){
//        sec = 255;
//    }
//    SetTimeout(1, sec);
    plog->write("[UI OPERATION - ICE] 타임아웃 세팅 2");
}

void DialogIceDispenser::on_BTN_ICE_TEST_REBOOT_2_clicked(){
    Reboot(1);
    plog->write("[UI OPERATION - ICE] 제빙기 리셋 2");
}

void DialogIceDispenser::on_BTN_ICE_TEST_STATUS_CLEAR_2_clicked(){
    ClearStatus(1);
    plog->write("[UI OPERATION - ICE] 상태클리어 2");
}

void DialogIceDispenser::on_BTN_ICE_CHANGE_AMBIENT_TEMP_2_clicked(){
//    SetAmbientTemperature(1, ui->LE_ICE_SETTING_AMBIENT_TEMP_LOW_2->text().toInt(), ui->LE_ICE_SETTING_AMBIENT_TEMP_HIGH_2->text().toInt());
    plog->write("[UI OPERATION - ICE] 온도 세팅 2");
}


int DialogIceDispenser::IsIceDev_1_Available(){
    if(ICE_DATA[0].connection_status == 1 && ICE_DATA[0].data_connection == 1){
        // device available check
        if((ICE_DATA[0].status.B[1] & 0x0F) == 0){
            return true;
        }else{
            return false;
        }
    }else{
        return false;
    }
}

int DialogIceDispenser::IsIceDev_2_Available(){
    if(ICE_DATA[1].connection_status == 1 && ICE_DATA[1].data_connection == 1){
        // device available check
        if((ICE_DATA[1].status.B[1] & 0x0F) == 0){
            return true;
        }else{
            return false;
        }
    }else{
        return false;
    }
}
