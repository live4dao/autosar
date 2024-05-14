
//---------------------------- Include File ---------------------------------//
#include "UssApp.h"
#include "Uart_Demo.h"

//---------------------------- Start Program --------------------------------//
void Uss_Init(void){
    USS_Rx_Init();
    // USS_Rx_Init_Muilt_core();
    debug_printf("USS System Start.\n");
    Uss_VerInfoType USS_Ver;
    UssDrivers_GetVersionInfo(&USS_Ver);
    debug_printf("USSDriverVer=v%d.%d.%d\n",USS_Ver.sw_major_version,USS_Ver.sw_minor_version,USS_Ver.sw_patch_version);
}

// void UssDriverVerPrint(void){
//     // USS_Rx_Init();
//     USS_Rx_Init_Muilt_core();
//     debug_printf("USS System Start.\n");
//     Uss_VerInfoType USS_Ver;
//     UssDrivers_GetVersionInfo(&USS_Ver);
//     debug_printf("USSDriverVer=v%d.%d.%d\n",USS_Ver.sw_major_version,USS_Ver.sw_minor_version,USS_Ver.sw_patch_version);
// }

void Uss_MainFunction(void){
    UssDrivers_DetectTime_Hander();
    UssDriver_Diagnostic_Hander();
    USS_Rx_Handler();
}

void Uss_Demo(void){

#ifdef USS_API_TEST_WRITE_ONLY
    int ret=0;
    static uint8 step=0;
    static uint32 delaycnt=0;
    switch (step)
    {
        case 0:{
            Uss_Calib_Data_t wCalib[SIZE_USS_SENSOR];
            UssDrivers_Calib_Default(&wCalib[USS_ID_IO1_TXRX_FLC]);
            // wCalib[USS_ID_IO1_TXRX_FLC].u8F_Drv=25; //change F_DRV value
            // wCalib[USS_ID_IO1_TXRX_FLC].u8G_Ana=1; //change G_ANA value
            ret=write_calibration(USS_ID_IO1_TXRX_FLC,&wCalib[USS_ID_IO1_TXRX_FLC]);
            if(ret==0){
                __nop();
                step++;
            }else{
                __nop();
            }

            break;
        }
        case 1:{
            delaycnt++;
            if(delaycnt>=2000)
            {
                debug_printf("write finsh\n");
                delaycnt=0;    
                step=0;
            }
            break;
        }
        default:
            step=0;
        break;
     }
#endif

#ifndef USS_API_TEST_TEMP
    int ret[SIZE_USS_SENSOR];
    static uint32 ReadTempCount=0;
    static uint32 ReadErrorCount=0;
    static uint8 step=0;
    int ussstart=0;
    int ussStop=12;
    switch (step)
    {
        case 0:{
            for(int i=ussstart;i<ussStop;i++){
                ret[i]=get_temp(i);
            }
            step++;
            break;
        }
        case 1:{
            int uss_busy_all_flag=0; //0:Idle, 1:Busy
            for(int i=ussstart;i<ussStop;i++){
                int work_status=read_uss_working_status(i);
                uss_busy_all_flag|=work_status;
            }
            if(uss_busy_all_flag==0){
                step++;
            }
            break;
        }
        case 2:{
            uint16 rTemp[SIZE_USS_SENSOR];

            int retCheck=0;
            for(int i=ussstart;i<ussStop;i++){
                ret[i]=read_temp(i,&rTemp[i]);
                retCheck|=ret[i];
            }

            for(int i=ussstart;i<ussStop;i++){
                debug_printf("#%02d,ret=%d,Temp:%d\n",i+1,ret[i],rTemp[i]);
            }

            step=0;
            break;
        }
    }
#endif

#ifdef API_TEST_Detect_Mode
    // static uint16 data_t=18000; //A
    static uint16 data_t=13000; //B
    // static uint16 data_t=40000;//C
    static uint8 timer =0;
    static Uss_Detect_Mode_t mode_t=MODE_SEND_REC_B;
    uint16 send, rec;
    uint32 print_data[SIZE_USS_SENSOR][128];
    static Uss_Cmds_SendRecEnv env=0;
    static uint32 status_dete,status_read[SIZE_USS_SENSOR];
    static Uss_Sensor_Id_t id ;
    static int k=0;
    static int delaycnt=0;
    static int testcnt=0;

    switch(timer){
        case 0:
            send = 0xFFF; rec = 0x0;
            status_dete = uss_detect(mode_t,send,rec,data_t);
            if(status_dete==0)
                timer ++;  
            break;
        case 1:
        {
            int uss_busy_all_flag=0; //0:Idle, 1:Busy
            for(int i=0;i<SIZE_USS_SENSOR;i++){
                int work_status=read_uss_working_status(i);
                uss_busy_all_flag|=work_status;
            }
            if(uss_busy_all_flag==0){
                timer++;
            }
            break;
        }
        case 2:
            memset(print_data, 0, sizeof(print_data));

//            status_read[0] =  read_bilateral_time(0,CMDS_SEND_B,print_data[0]);
            for(int i=0;i<12;i++)
                status_read[i] =  read_bilateral_time(i,CMDS_SEND_B,print_data[i]);
            timer++;

            break;
        case 3:{
            char uartBuffer[32];
            int zeroend=0;

            for(int uss_ch=0;uss_ch<SIZE_USS_SENSOR;uss_ch++){
                for(int i=0;i<128;i++){
                    if(print_data[uss_ch][i]==0)
                    {
                        zeroend=i+1;
                        break;
                    }
                }

                debug_printf("#%d:",uss_ch+1);
                for (int i = 0; i < zeroend; i++) {
                    int length = snprintf(uartBuffer, 32, "%u,", print_data[uss_ch][i]);
                    debug_printf(uartBuffer);
                }
                debug_printf("\n");
            }


            timer++;
            break;
            }
        case 4:{
            delaycnt++;
            if(delaycnt>=2000)
            {
                delaycnt=0;    
                testcnt++;
                timer=0;
            }
            break;
        }
        case 5:
            // if(testcnt==400){
            //     timer=5;
            // }else{
                timer=0;
            // }
        break;
        default:
            timer=0;
        break;
     }

#endif

#ifdef USS_API_TEST_ID
    int ret[SIZE_USS_SENSOR];
    static uint8 step=0;
    static uint32 DelayCnt=0;
    static uint32 rID[SIZE_USS_SENSOR];
    switch (step)
    {
        case 0:{
            int retCheck=0;
            for(int i=0;i<SIZE_USS_SENSOR;i++){
                ret[i]=get_id(i);
                retCheck|=ret[i];
            }
            
            // if(retCheck==0){
                step++;
            // }else{
                // __nop();
            // }

            break;
        }
        case 1:{
            int uss_busy_all_flag=0; //0:Idle, 1:Busy
            for(int i=0;i<SIZE_USS_SENSOR;i++){
                int work_status=read_uss_working_status(i);
                uss_busy_all_flag|=work_status;
            }
            if(uss_busy_all_flag==0){
                step++;
            }
            break;
        }
        case 2:{
            int retCheck=0;
            for(int i=0;i<SIZE_USS_SENSOR;i++){
                ret[i]=read_id(i,&rID[i]);
                retCheck|=ret[i];
            }
            // if(retCheck==0){  
                step++;
            // }else{
                // __nop();
                // step=4;
            // }
            break;
        }
        case 3:{
            char uartBuffer[32];
            for(int i=0;i<SIZE_USS_SENSOR;i++){
                debug_printf("#%02d,ret=%d,ID:",i+1,ret[i]);
                int length = snprintf(uartBuffer, 32, "%u,", rID[i]);
                debug_printf(uartBuffer);
                debug_printf("\n");
            }
            step++;
            break;
        }
        case 4:{
            DelayCnt++;
            if(DelayCnt>=1000){
                DelayCnt=0;
                step=0;
            }
            break;
        }
    }
#endif

#ifdef USS_API_TEST_ID
    int ret=0;
    static uint8 step=0;
    static uint32 DelayCnt=0;
    static uint32 rID;
    switch (step)
    {
        case 0:{
            ret=get_id(USS_ID_IO1_TXRX_FLC);
            if(ret==0){
                // debug_printf("gID\n");
                step++;
            }else{
                __nop();
            }

            break;
        }
        case 1:{
            int uss_busy_all_flag=0; //0:Idle, 1:Busy
            for(int i=0;i<SIZE_USS_SENSOR;i++){
                int work_status=read_uss_working_status(i);
                uss_busy_all_flag|=work_status;
            }
            if(uss_busy_all_flag==0){
                step++;
            }
            break;
        }
        case 2:{
            // Uss_Calib_Data_t rEEprom[SIZE_USS_SENSOR];
            ret=read_id(USS_ID_IO1_TXRX_FLC,&rID);
            // step++;
            // if(ret==0){
                // __nop();    
                step++;
            // }else if(ret==2){
            //     __nop();
            // }else{
            //     __nop();
            // }
            break;
        }
        case 3:{

            // char uartBuffer[32];
            // debug_printf("ID:");
            // int length = snprintf(uartBuffer, 32, "%u,", rID);
            // debug_printf(uartBuffer);
            // debug_printf("ret=%d",ret);
            // debug_printf("\n");
            debug_printf("r=%d,ID:%d\n",ret,rID);
            step++;
            break;
        }
        case 4:{
            DelayCnt++;
            if(DelayCnt>=1000){
                DelayCnt=0;
                step=0;
            }
            break;
        }
    }
#endif

#ifdef USS_API_TEST_Status
    int ret=0;
    static uint8 step=0;
    static uint32 DelayCnt=0;
    static uint16 rStatus;
    switch (step)
    {
        case 0:{
            ret=get_status(USS_ID_IO1_TXRX_FLC);
            if(ret==0){
                __nop();
                step++;
            }else{
                __nop();
            }

            break;
        }
        case 1:{
            // Uss_Calib_Data_t rEEprom[SIZE_USS_SENSOR];
            ret=read_status(USS_ID_IO1_TXRX_FLC,&rStatus);
            if(ret==0){
                __nop();    
                step++;
            }else{
                __nop();
            }
            break;
        }
        case 2:{
            char uartBuffer[32];
            debug_printf("Status:");
            int length = snprintf(uartBuffer, 32, "%u,", rStatus);
            debug_printf(uartBuffer);
            debug_printf("\n");
            step++;
            break;
        }
        case 3:{
            DelayCnt++;
            if(DelayCnt>=1000){
                DelayCnt=0;
                step=0;
            }

            break;
        }
    }
#endif

}


void IoHwAb_GptNotification_50us(void)
{
    USS_TX_IQR_50us();
}

void IcuTimestampNotification_USS_RX1(void)
{
    USS_RX1_IQR();
}

void IcuTimestampNotification_USS_RX2(void){
    USS_RX2_IQR();
}
void IcuTimestampNotification_USS_RX3(void){
    USS_RX3_IQR();
}
void IcuTimestampNotification_USS_RX4(void){
    USS_RX4_IQR();
}
void IcuTimestampNotification_USS_RX5(void){
    USS_RX5_IQR();
}
void IcuTimestampNotification_USS_RX6(void){
    USS_RX6_IQR();
}
void IcuTimestampNotification_USS_RX7(void){
    USS_RX7_IQR();
}
void IcuTimestampNotification_USS_RX8(void){
    USS_RX8_IQR();
}
void IcuTimestampNotification_USS_RX9(void){
    USS_RX9_IQR();
}
void IcuTimestampNotification_USS_RX10(void){
    USS_RX10_IQR();
}
void IcuTimestampNotification_USS_RX11(void){
    USS_RX11_IQR();
}
void IcuTimestampNotification_USS_RX12(void){
    USS_RX12_IQR();
}
