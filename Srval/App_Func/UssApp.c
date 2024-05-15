
//---------------------------- Include File ---------------------------------//
#include "UssApp.h"
#include "Uart_Demo.h"

#include "Rte_StbM_Type.h"
#include "ADC_Demo.h"

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

/*************************************************************************************
 ** @name:Uss_Power_Status_updata()                                           **
 ** @brief:need to pollling each 10ms.                                              **
 *************************************************************************************/
void Uss_Power_Status_updata(void){
    uint8 USS_Power_Status;
    static uint8 ADCInitTime=0;
    USS_Power_Status=(uint8)GetAdcStatus(iAN26_USS_PS);
    if(USS_Power_Status==0){
        ADCInitTime++;
    }
    if(ADCInitTime>250){
        ADCInitTime=0;
        USS_Power_Status=4;
    }
    int ret=(int)UssDrivers_Diag_Status_USS_Power(USS_Power_Status);
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
    static uint32 delaycnt=0;
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

            step++;
            break;
        }
        case 3:{
            delaycnt++;
            if(delaycnt>=500) //Delay 
            {
                delaycnt=0;    
                step=0;
            }
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

void Uss_API_Test(void){

#ifdef USS_API_TEST_WRITE_Thres
    int ret[SIZE_USS_SENSOR];
    static uint8 step=0;
    static int loop=0;
    static Uss_Thres_Data_t wThres[SIZE_USS_SENSOR];
    static Uss_Thres_Data_t rThres[SIZE_USS_SENSOR];
    int ussstart=8;
    int ussStop=12;

    switch (step)
    {
        case 0:
            if(loop<10){
                loop++;
                step++;
            }
            if(loop==10){
                debug_printf("Write test finish\n");
                step=6;
            }else{
                debug_printf("test loop:%d\n",loop);
            }
        break;
        case 1:{
            
            for(int i=ussstart;i<ussStop;i++){
                 UssDrivers_Thres_Default(&wThres[i]);
                wThres[i].u8Atg_Alpha=1;
                wThres[i].u8Atg_Cfg=3;
                wThres[i].u8Atg_Tau=3;
                wThres[i].u8Thresscale_Rec=3;
                wThres[i].u8Thsft_Cfg=3;
                wThres[i].u8Thval[0]=0x1f;
                wThres[i].u8Thval[1]=0x1f;
                wThres[i].u8Thval[2]=0x1f;
                wThres[i].u8Thval[3]=0x1f;
                wThres[i].u8Thval[4]=0x1f;
                wThres[i].u8Thval[5]=0x1f;
                wThres[i].u8Thval[6]=0x1f;
                wThres[i].u8Thval[7]=0x1f;
                wThres[i].u8Thval[8]=0x1f;
                wThres[i].u8Thval[9]=0x1f;
                wThres[i].u8Thval[10]=0x1f;
                wThres[i].u8Thval[11]=0x1f;
            }

            for(int i=ussstart;i<ussStop;i++){
                ret[i]=write_threshold(i,&wThres[i]);
            }
            for(int i=ussstart;i<ussStop;i++){
                if(ret[i]!=0)
                    debug_printf("[Error]:Loop=%d,USS#%d,w_thr ret=%d\n",loop,i,ret[i]);
            }
            step++;
            break;
        }
        case 2:{
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
        case 3:{
            for(int i=ussstart;i<ussStop;i++){
                ret[i]=get_threshold(i);
            }
            for(int i=ussstart;i<ussStop;i++){
                if(ret[i]!=0)
                    debug_printf("[Error]:Loop=%d,USS#%d,get_Thr ret=%d\n",loop,i,ret[i]);
            }
            step++;
            break;
        }
        case 4:{
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
        case 5:{
            memset(rThres,0,sizeof(rThres));
            for(int i=ussstart;i<ussStop;i++){
                ret[i]=read_threshold(i,&rThres[i]);
            }
            for(int i=ussstart;i<ussStop;i++){
                if(ret[i]!=0)
                    debug_printf("[Error]:Loop=%d,USS#%d,read_thr ret=%d\n",loop,i,ret[i]);
            }
            for(int i=ussstart;i<ussStop;i++){
                int retcmp=memcmp(&wThres[i],&rThres[i],sizeof(rThres[i]));
                if(retcmp!=0)
                    debug_printf("[Error]:Not same at Loop=%d,USS#%d,retcmp=%d\n",loop,i,retcmp);
            }
            step=0;
            break;
        }

        case 6:
            if(loop<1000){
                loop++;
                step++;
            }
            if(loop==1000){
                debug_printf("Read test finish\n");
                step=99;
            }else if((loop%100)==0){
                debug_printf("test loop:%d\n",loop);
            }
        break;

        case 7:{
            for(int i=ussstart;i<ussStop;i++){
                ret[i]=get_threshold(i);
            }
            for(int i=ussstart;i<ussStop;i++){
                if(ret[i]!=0)
                    debug_printf("[Error]:Loop=%d,USS#%d,get_Thr ret=%d\n",loop,i,ret[i]);
            }
            step++;
            break;
        }
        case 8:{
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
        case 9:{
            memset(rThres,0,sizeof(rThres));
            for(int i=ussstart;i<ussStop;i++){
                ret[i]=read_threshold(i,&rThres[i]);
            }
            for(int i=ussstart;i<ussStop;i++){
                if(ret[i]!=0)
                    debug_printf("[Error]:Loop=%d,USS#%d,read_thr ret=%d\n",loop,i,ret[i]);
            }
            for(int i=ussstart;i<ussStop;i++){
                int retcmp=memcmp(&wThres[i],&rThres[i],sizeof(rThres[i]));
                if(retcmp!=0)
                    debug_printf("[Error]:Not same at Loop=%d,USS#%d,retcmp=%d\n",loop,i,retcmp);
            }
            step=6;
            break;
        }
        case 99:
        break;
    }
#endif

#ifdef USS_API_TEST_WRITE_MEAS
    int ret[SIZE_USS_SENSOR];
    static uint8 step=0;
    static int loop=0;
    static Uss_Meas_Data_t wMeas[SIZE_USS_SENSOR];
    static Uss_Meas_Data_t rMeas[SIZE_USS_SENSOR];
    int ussstart=8;
    int ussStop=12;

    switch (step)
    {
        case 0:
            if(loop<10){
                loop++;
                step++;
            }
            if(loop==10){
                debug_printf("Write test finish\n");
                step=6;
            }else{
                debug_printf("test loop:%d\n",loop);
            }
        break;
        case 1:{
            
            for(int i=ussstart;i<ussStop;i++){
                 UssDrivers_Meas_Default(&wMeas[i]);
                wMeas[i].u8npulses_a=7;
	            wMeas[i].u8tmeas_a=7;
	            wMeas[i].u8thresscale_a=3;
	            wMeas[i].u8npulses_b=7;
	            wMeas[i].u8tmeas_b=7;
	            wMeas[i].u8thresscale_b=3;
	            wMeas[i].u8npulses_c=7;
	            wMeas[i].u8tmeas_c=7;
	            wMeas[i].u8thresscale_c=3;
	            wMeas[i].u8echo_deb=1;
	            wMeas[i].u8rt_cfg=1;
	            wMeas[i].u8nftg=1;
	            wMeas[i].u8ftc=1;
	            wMeas[i].u8epd=1;
	            wMeas[i].u8stc_cfg=3;
	            wMeas[i].u8stc_start=3;
	            wMeas[i].u8noise_cfg=3;
	            wMeas[i].u8filter_cfg=1;
            }

            for(int i=ussstart;i<ussStop;i++){
                ret[i]=write_meas(i,&wMeas[i]);
            }
            for(int i=ussstart;i<ussStop;i++){
                if(ret[i]!=0)
                    debug_printf("[Error]:Loop=%d,USS#%d,w_thr ret=%d\n",loop,i,ret[i]);
            }
            step++;
            break;
        }
        case 2:{
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
        case 3:{
            for(int i=ussstart;i<ussStop;i++){
                ret[i]=get_meas(i);
            }
            for(int i=ussstart;i<ussStop;i++){
                if(ret[i]!=0)
                    debug_printf("[Error]:Loop=%d,USS#%d,get_Thr ret=%d\n",loop,i,ret[i]);
            }
            step++;
            break;
        }
        case 4:{
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
        case 5:{
            memset(rMeas,0,sizeof(rMeas));
            for(int i=ussstart;i<ussStop;i++){
                ret[i]=read_meas(i,&rMeas[i]);
            }
            for(int i=ussstart;i<ussStop;i++){
                if(ret[i]!=0)
                    debug_printf("[Error]:Loop=%d,USS#%d,read_thr ret=%d\n",loop,i,ret[i]);
            }
            for(int i=ussstart;i<ussStop;i++){
                int retcmp=memcmp(&wMeas[i],&rMeas[i],sizeof(rMeas[i]));
                if(retcmp!=0)
                    debug_printf("[Error]:Not same at Loop=%d,USS#%d,retcmp=%d\n",loop,i,retcmp);
            }
            step=0;
            break;
        }

        case 6:
            if(loop<1000){
                loop++;
                step++;
            }
            if(loop==1000){
                debug_printf("Read test finish\n");
                step=99;
            }else if((loop%100)==0){
                debug_printf("test loop:%d\n",loop);
            }
        break;

        case 7:{
            for(int i=ussstart;i<ussStop;i++){
                ret[i]=get_meas(i);
            }
            for(int i=ussstart;i<ussStop;i++){
                if(ret[i]!=0)
                    debug_printf("[Error]:Loop=%d,USS#%d,get_Thr ret=%d\n",loop,i,ret[i]);
            }
            step++;
            break;
        }
        case 8:{
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
        case 9:{
            memset(rMeas,0,sizeof(rMeas));
            for(int i=ussstart;i<ussStop;i++){
                ret[i]=read_meas(i,&rMeas[i]);
            }
            for(int i=ussstart;i<ussStop;i++){
                if(ret[i]!=0)
                    debug_printf("[Error]:Loop=%d,USS#%d,read_thr ret=%d\n",loop,i,ret[i]);
            }
            for(int i=ussstart;i<ussStop;i++){
                int retcmp=memcmp(&wMeas[i],&rMeas[i],sizeof(rMeas[i]));
                if(retcmp!=0)
                    debug_printf("[Error]:Not same at Loop=%d,USS#%d,retcmp=%d\n",loop,i,retcmp);
            }
            step=6;
            break;
        }
        case 99:
        break;
    }
#endif

#ifdef USS_API_TEST_WRITE_Calib
    int ret[SIZE_USS_SENSOR];
    static uint8 step=0;
    static int loop=0;
    static Uss_Calib_Data_t wCalib[SIZE_USS_SENSOR];
    static Uss_Calib_Data_t rCalib[SIZE_USS_SENSOR];
    int ussstart=8;
    int ussStop=12;

    switch (step)
    {
        case 0:
            if(loop<10){
                loop++;
                step++;
            }
            if(loop==10){
                debug_printf("Write test finish\n");
                step=6;
            }else{
                debug_printf("test loop:%d\n",loop);
            }
        break;
        case 1:{
            
            for(int i=ussstart;i<ussStop;i++){
                 UssDrivers_Calib_Default(&wCalib[i]);
                wCalib[i].u8Osc_Trim=0xF;
                wCalib[i].u8Customer_Bits=0x7F;
                wCalib[i].u8G_Dig=0x7F;
                wCalib[i].u8G_Ana=0x07;
                wCalib[i].u8I_Drv=0x1F;
                wCalib[i].u8F_Drv=0xFF;

            }

            for(int i=ussstart;i<ussStop;i++){
                ret[i]=write_calibration(i,&wCalib[i]);
            }
            for(int i=ussstart;i<ussStop;i++){
                if(ret[i]!=0)
                    debug_printf("[Error]:Loop=%d,USS#%d,w_thr ret=%d\n",loop,i,ret[i]);
            }
            step++;
            break;
        }
        case 2:{
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
        case 3:{
            for(int i=ussstart;i<ussStop;i++){
                ret[i]=get_calibration(i);
            }
            for(int i=ussstart;i<ussStop;i++){
                if(ret[i]!=0)
                    debug_printf("[Error]:Loop=%d,USS#%d,get_Thr ret=%d\n",loop,i,ret[i]);
            }
            step++;
            break;
        }
        case 4:{
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
        case 5:{
            memset(rCalib,0,sizeof(rCalib));
            for(int i=ussstart;i<ussStop;i++){
                ret[i]=read_calibration(i,&rCalib[i]);
            }
            for(int i=ussstart;i<ussStop;i++){
                if(ret[i]!=0)
                    debug_printf("[Error]:Loop=%d,USS#%d,read_thr ret=%d\n",loop,i,ret[i]);
            }
            for(int i=ussstart;i<ussStop;i++){
                int retcmp=memcmp(&wCalib[i],&rCalib[i],sizeof(rCalib[i]));
                if(retcmp!=0)
                    debug_printf("[Error]:Not same at Loop=%d,USS#%d,retcmp=%d\n",loop,i,retcmp);
            }
            step=0;
            break;
        }

        case 6:
            if(loop<1000){
                loop++;
                step++;
            }
            if(loop==1000){
                debug_printf("Read test finish\n");
                step=99;
            }else if((loop%100)==0){
                debug_printf("test loop:%d\n",loop);
            }
        break;

        case 7:{
            for(int i=ussstart;i<ussStop;i++){
                ret[i]=get_calibration(i);
            }
            for(int i=ussstart;i<ussStop;i++){
                if(ret[i]!=0)
                    debug_printf("[Error]:Loop=%d,USS#%d,get_Thr ret=%d\n",loop,i,ret[i]);
            }
            step++;
            break;
        }
        case 8:{
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
        case 9:{
            memset(rCalib,0,sizeof(rCalib));
            for(int i=ussstart;i<ussStop;i++){
                ret[i]=read_calibration(i,&rCalib[i]);
            }
            for(int i=ussstart;i<ussStop;i++){
                if(ret[i]!=0)
                    debug_printf("[Error]:Loop=%d,USS#%d,read_thr ret=%d\n",loop,i,ret[i]);
            }
            for(int i=ussstart;i<ussStop;i++){
                int retcmp=memcmp(&wCalib[i],&rCalib[i],sizeof(rCalib[i]));
                if(retcmp!=0)
                    debug_printf("[Error]:Not same at Loop=%d,USS#%d,retcmp=%d\n",loop,i,retcmp);
            }
            step=6;
            break;
        }
        case 99:
        break;
    }
#endif

#ifdef USS_API_TEST_Read_EEPROM
    int ret[SIZE_USS_SENSOR];
    static Uss_Calib_Data_t rEEPROM[SIZE_USS_SENSOR];
    static uint8 step=0;
    static int loop=0;
    int ussstart=8;
    int ussStop=12;

    static Uss_Calib_Data_t r1stEEPROM[SIZE_USS_SENSOR];
    static boolean eeprom_1st=0;


    switch (step)
    {
        case 0:
            if(loop<1000){
                loop++;
                step++;
            }
            if(loop==1000){
                debug_printf("test finish\n");
                step=99;
            }else if((loop%100)==0){
                debug_printf("test loop:%d\n",loop);
            }
        break;
        case 1:{
            for(int i=ussstart;i<ussStop;i++){
                ret[i]=get_eeprom(i);
            }
            for(int i=ussstart;i<ussStop;i++){
                if(ret[i]!=0)
                    debug_printf("[Error]:Loop=%d,USS#%d,g_t ret=%d\n",loop,i,ret[i]);
            }
            step++;
            break;
        }
        case 2:{
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
        case 3:{
            memset(rEEPROM,0,sizeof(rEEPROM));
            int retCheck=0;
            if(eeprom_1st==0){
                for(int i=ussstart;i<ussStop;i++){
                    ret[i]=read_eeprom(i,&r1stEEPROM[i]);
                }
                memcpy(&rEEPROM,&r1stEEPROM,sizeof(rEEPROM));
                eeprom_1st=1;
            }else{
                for(int i=ussstart;i<ussStop;i++){
                    ret[i]=read_eeprom(i,&rEEPROM[i]);
                }
            }
            for(int i=ussstart;i<ussStop;i++){
                if(ret[i]!=0)
                    debug_printf("[Error]:Loop=%d,USS#%d,r_t ret=%d\n",loop,i,ret[i]);
            }

            for(int i=ussstart;i<ussStop;i++){
                int retcmp=memcmp(&r1stEEPROM[i],&rEEPROM[i],sizeof(rEEPROM[i]));
                if(retcmp!=0)
                    debug_printf("[Error]:Not same at Loop=%d,USS#%d,retcmp=%d\n",loop,i,retcmp);

                // debug_printf("USS#%d,u8Osc_Trim=%d\n",i,rEEPROM[i].u8Osc_Trim);
                // debug_printf("USS#%d,u8Customer_Bits=%d\n",i,rEEPROM[i].u8Customer_Bits);
                // debug_printf("USS#%d,u8G_Dig=%d\n",i,rEEPROM[i].u8G_Dig);
                // debug_printf("USS#%d,u8G_Ana=%d\n",i,rEEPROM[i].u8G_Ana);
                // debug_printf("USS#%d,u8I_Drv=%d\n",i,rEEPROM[i].u8I_Drv);
                // debug_printf("USS#%d,u8F_Drv=%d\n",i,rEEPROM[i].u8F_Drv);
                // debug_printf("USS#%d,u8Vprog_Status=%d\n",i,rEEPROM[i].u8Vprog_Status); 
            }


            step=0;
            break;
        }
        case 99:
        break;
    }
#endif

#ifdef USS_API_TEST_Tead_TEMP
    int ret[SIZE_USS_SENSOR];
    static uint8 step=0;
    static int loop=0;
    int ussstart=8;
    int ussStop=12;

    switch (step)
    {
        case 0:
            if(loop<1000){
                loop++;
                step++;
            }
            if(loop==1000){
                debug_printf("test finish\n");
                step=99;
            }else if((loop%100)==0){
                debug_printf("test loop:%d\n",loop);
            }
        break;
        case 1:{
            for(int i=ussstart;i<ussStop;i++){
                ret[i]=get_temp(i);
            }
            for(int i=ussstart;i<ussStop;i++){
                if(ret[i]!=0)
                    debug_printf("[Error]:Loop=%d,USS#%d,g_t ret=%d\n",loop,i,ret[i]);
            }
            step++;
            break;
        }
        case 2:{
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
        case 3:{
            uint16 rTemp[SIZE_USS_SENSOR];
            memset(rTemp,0,sizeof(rTemp));
            int retCheck=0;
            for(int i=ussstart;i<ussStop;i++){
                ret[i]=read_temp(i,&rTemp[i]);
            }
            for(int i=ussstart;i<ussStop;i++){
                if(ret[i]!=0)
                    debug_printf("[Error]:Loop=%d,USS#%d,r_t ret=%d\n",loop,i,ret[i]);
                if(rTemp[i]<400 || rTemp[i]>500)
                    debug_printf("[Error]:Loop=%d,USS#%d,r_t Value=%d\n",loop,i,rTemp[i]);
            }

            // for(int i=ussstart;i<ussStop;i++){
            //     debug_printf("#%02d,ret=%d,Temp:%d\n",i+1,ret[i],rTemp[i]);
            // }

            step=0;
            break;
        }
        case 99:
        break;
    }
#endif

#ifdef USS_API_TEST_READ_STATUS
    int ret[SIZE_USS_SENSOR];
    static uint8 step=0;
    static int loop=0;
    int ussstart=8;
    int ussStop=12;

    switch (step)
    {
        case 0:
            if(loop<1000){
                loop++;
                step++;
            }
            if(loop==1000){
                debug_printf("test finish\n");
                step=99;
            }else if((loop%100)==0){
                debug_printf("test loop:%d\n",loop);
            }
        break;
        case 1:{
            for(int i=ussstart;i<ussStop;i++){
                ret[i]=get_status(i);
            }
            for(int i=ussstart;i<ussStop;i++){
                if(ret[i]!=0)
                    debug_printf("[Error]:Loop=%d,USS#%d,g_t ret=%d\n",loop,i,ret[i]);
            }
            step++;
            break;
        }
        case 2:{
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
        case 3:{
            uint16 rStatus[SIZE_USS_SENSOR];
            memset(rStatus,0,sizeof(rStatus));
            int retCheck=0;
            for(int i=ussstart;i<ussStop;i++){
                ret[i]=read_status(i,&rStatus[i]);
            }
            for(int i=ussstart;i<ussStop;i++){
                if(ret[i]!=0)
                    debug_printf("[Error]:Loop=%d,USS#%d,r_t ret=%d\n",loop,i,ret[i]);

                
                if(rStatus[i]!=16)
                    debug_printf("[Error]:Loop=%d,USS#%d,r_t Value=%d\n",loop,i,rStatus[i]);
                // debug_printf("USS#%d,ret=%d,status=%d\n",loop,i,rStatus[i]);
            }

            // for(int i=ussstart;i<ussStop;i++){
            //     debug_printf("#%02d,ret=%d,Temp:%d\n",i+1,ret[i],rTemp[i]);
            // }

            step=0;
            break;
        }
        case 99:
        break;
    }
#endif

#ifdef USS_API_TEST_READ_CAL_PULSES
    int ret[SIZE_USS_SENSOR];
    static uint8 step=0;
    static int loop=0;
    int ussstart=8;
    int ussStop=12;

    switch (step)
    {
        case 0:
            if(loop<1000){
                loop++;
                step++;
            }
            if(loop==1000){
                debug_printf("test finish\n");
                step=99;
            }else if((loop%100)==0){
                debug_printf("test loop:%d\n",loop);
            }
        break;
        case 1:{
            for(int i=ussstart;i<ussStop;i++){
                ret[i]=get_cal_pulses(i);
            }
            for(int i=ussstart;i<ussStop;i++){
                if(ret[i]!=0)
                    debug_printf("[Error]:Loop=%d,USS#%d,g_t ret=%d\n",loop,i,ret[i]);
            }
            step++;
            break;
        }
        case 2:{
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
        case 3:{
            uint32 rCalPuls[SIZE_USS_SENSOR][4];
            memset(rCalPuls,0,sizeof(rCalPuls));
            int retCheck=0;
            for(int i=ussstart;i<ussStop;i++){
                ret[i]=read_cal_pulses(i,&rCalPuls[i]);
            }
            for(int i=ussstart;i<ussStop;i++){
                if(ret[i]!=0)
                    debug_printf("[Error]:Loop=%d,USS#%d,r_t ret=%d\n",loop,i,ret[i]);

                
                if( (rCalPuls[i][3]-rCalPuls[i][1])<7000 || (rCalPuls[i][3]-rCalPuls[i][1])>13000 )
                    debug_printf("[Error]:Loop=%d,USS#%d,r_t ValueError=%d,%d,%d,%d\n",loop,i,rCalPuls[i][0],rCalPuls[i][1],rCalPuls[i][2],rCalPuls[i][3]);
                // debug_printf("USS#%d,ret=%d,%d,%d,%d,%d\n",i,ret,rCalPuls[i][0],rCalPuls[i][1],rCalPuls[i][2],rCalPuls[i][3]);
            }

            // for(int i=ussstart;i<ussStop;i++){
            //     debug_printf("#%02d,ret=%d,Temp:%d\n",i+1,ret[i],rTemp[i]);
            // }

            step=0;
            break;
        }
        case 99:
        break;
    }
#endif

#ifdef USS_API_TEST_Read_ID
    int ret[SIZE_USS_SENSOR];
    static uint32 r1stID[SIZE_USS_SENSOR];
    static uint32 rID[SIZE_USS_SENSOR];
    static uint8 step=0;
    static int loop=0;
    int ussstart=8;
    int ussStop=12;

    static boolean ID_1st=0;


    switch (step)
    {
        case 0:
            if(loop<1000){
                loop++;
                step++;
            }
            if(loop==1000){
                debug_printf("test finish\n");
                step=99;
            }else if((loop%100)==0){
                debug_printf("test loop:%d\n",loop);
            }
        break;
        case 1:{
            for(int i=ussstart;i<ussStop;i++){
                ret[i]=get_id(i);
            }
            for(int i=ussstart;i<ussStop;i++){
                if(ret[i]!=0)
                    debug_printf("[Error]:Loop=%d,USS#%d,g_t ret=%d\n",loop,i,ret[i]);
            }
            step++;
            break;
        }
        case 2:{
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
        case 3:{
            memset(rID,0,sizeof(rID));
            if(ID_1st==0){
                for(int i=ussstart;i<ussStop;i++){
                    ret[i]=read_id(i,&r1stID[i]);
                }
                memcpy(&rID,&r1stID,sizeof(rID));
                ID_1st=1;
            }else{
                for(int i=ussstart;i<ussStop;i++){
                    ret[i]=read_id(i,&rID[i]);
                }
            }
            for(int i=ussstart;i<ussStop;i++){
                if(ret[i]!=0)
                    debug_printf("[Error]:Loop=%d,USS#%d,r_t ret=%d\n",loop,i,ret[i]);
            }

            for(int i=ussstart;i<ussStop;i++){
                int retcmp=memcmp(&r1stID[i],&rID[i],sizeof(rID[i]));
                if(retcmp!=0)
                    debug_printf("[Error]:Not same at Loop=%d,USS#%d,retcmp=%d,ID=%d\n",loop,i,retcmp,rID[i]);

                // debug_printf("USS#%d,u8Osc_Trim=%d\n",i,rEEPROM[i].u8Osc_Trim);
                // debug_printf("USS#%d,u8Customer_Bits=%d\n",i,rEEPROM[i].u8Customer_Bits);
                // debug_printf("USS#%d,u8G_Dig=%d\n",i,rEEPROM[i].u8G_Dig);
                // debug_printf("USS#%d,u8G_Ana=%d\n",i,rEEPROM[i].u8G_Ana);
                // debug_printf("USS#%d,u8I_Drv=%d\n",i,rEEPROM[i].u8I_Drv);
                // debug_printf("USS#%d,u8F_Drv=%d\n",i,rEEPROM[i].u8F_Drv);
                // debug_printf("USS#%d,u8Vprog_Status=%d\n",i,rEEPROM[i].u8Vprog_Status); 
            }
            // debug_printf("Loop=%d,USS#0,ID=%d\n",loop,rID[0]);

            step=0;
            break;
        }
        case 99:
        break;
    }
#endif

#ifdef USS_API_TEST_Diag
    int ret[SIZE_USS_SENSOR];
    static uint8 step=0;
    static uint32 DelayCnt=0;
    static uint32 DelayCnt2=0;
    static uint16 rDiag[SIZE_USS_SENSOR];
    int ussstart=0;
    int ussStop=12;

    switch (step)
    {
        case 0:{
            for(int i=ussstart;i<ussStop;i++){
                ret[i]=get_diag(i);
            }
            for(int i=ussstart;i<ussStop;i++){
                if(ret[i]!=0)
                    debug_printf("[Error]:USS#%d,g_t ret=%d\n",i,ret[i]);
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
            for(int i=ussstart;i<ussStop;i++){
                ret[i]=read_diag(i,&rDiag[i]);
            }
            for(int i=ussstart;i<ussStop;i++){
                if(rDiag[i]!=0){
                    debug_printf("USS#%d have error.ret=%d, Diag=%d\n",i,ret[i],rDiag[i]);
                }
                if(ret[i]!=0)
                    debug_printf("USS#%d ret=%d error\n",i,ret[i]);
            }
            step++;
            break;
        }
        case 3:
            DelayCnt++;
            if(DelayCnt>=100){
                // debug_printf("USS_Start\n");
                DelayCnt=0;
                step=0;
            }

        break;
    }
#endif

#ifdef API_TEST_Detect_Mode
    // static uint16 data_t=18000; //A
    // static uint16 data_t=13000; //B
    static uint16 data_t=40000;//C
    static uint8 step =0;
    static Uss_Detect_Mode_t mode_t=MODE_SEND_REC_C;
    static uint16 send, rec;
    uint32 print_data[SIZE_USS_SENSOR][128];
    static Uss_Cmds_SendRecEnv env=0;
    static uint32 status_dete,status_read[SIZE_USS_SENSOR];
    static Uss_Sensor_Id_t id ;
    static int k=0;
    static int delaycnt=0;
    static int testcnt=0;
    static int loop=0;

    int ussstart=8;
    int ussStop=12;

    switch(step){
        case 0:
            if(loop<1000){
                loop++;
                step++;
            }
            if(loop==1000){
                debug_printf("test finish\n");
                step=99;
            }else if((loop%100)==0){
                debug_printf("test loop:%d\n",loop);
            }
        break;
        case 1:
            // send = 0x0AAA; rec = (~send)&0x0FFF;
            send = 0x00A00; rec = 0x00500;
            status_dete = uss_detect(mode_t,send,rec,data_t);
            if(status_dete==0)
                step ++;  
            break;
        case 2:
        {
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
        case 3:{
            memset(print_data, 0, sizeof(print_data));

            for(int i=ussstart;i<ussStop;i++){
                if((send>>i)&0x0001)
                    status_read[i] =  read_bilateral_time(i,mode_t,print_data[i]);
                if((rec>>i)&0x0001)
                    status_read[i] =  read_bilateral_time(i,mode_t+3,print_data[i]);
            }
            for(int i=ussstart;i<ussStop;i++){
                if(status_read[i]!=0){
                    debug_printf("[Error]USS#%d,ret=%d\n",i,status_read);
                }
            }
            int zeroend=0;
            for(int uss_ch=ussstart;uss_ch<ussStop;uss_ch++){
                for(int i=0;i<128;i++){
                    if(print_data[uss_ch][i]==0)
                    {
                        zeroend=i+1;
                        break;
                    }
                }

                // debug_printf("#%d:",uss_ch+1);
                // for (int i = 0; i < zeroend; i++) {
                //     debug_printf("%d,", print_data[uss_ch][i]);
                // }
                // debug_printf("\n");
                if(zeroend<30){
                // if(zeroend<30){
                    debug_printf("[Error]USS#%d data too less,size=%d\n",uss_ch,zeroend);
                }
            }
            step=0;
            break;
        }
        case 4:{
            delaycnt++;
            if(delaycnt>=2000)
            {
                delaycnt=0;    
                testcnt++;
                step=0;
            }
            break;
        }
        default:
            //step=0;
        break;
     }

#endif

#ifdef USS_API_TEST_power
    int ret=0;
    static uint8 step=0;
    static uint8 ReadCnt=0;
    static Uss_Calib_Data_t rEEprom[SIZE_USS_SENSOR];
    static uint32 standby_cnt=0;
    switch (step)
    {
        case 0:{
            for(int i=0;i<SIZE_USS_SENSOR;i++){
                ret=UssDrivers_Standby(i);
            }
            if(ret==0){
                __nop();
                debug_printf("Standby\n");
                step++;
            }else{
                __nop();
            }
            break;
        }
        case 1:{
            standby_cnt++;
            if(standby_cnt>=10000){
                __nop();    
                step++;
                standby_cnt=0;
            }else{
                __nop();
            }
            break;
        }
        case 2:{
            for(int i=0;i<SIZE_USS_SENSOR;i++){
                ret=UssDrivers_Wakeup(i);
            }
            if(ret==0){
                __nop(); 
                debug_printf("Wakeup\n");   
                step++;
            }else{
                __nop();
            }
            break;
        }
        case 3:{
            standby_cnt++;
            if(standby_cnt>=10000){
                __nop();    
                step=0;
                standby_cnt=0;
            }else{
                __nop();
            }
            break;
        }
    }
#endif


#ifdef USS_API_TEST_Read_Thres
    int ret[SIZE_USS_SENSOR];
    static uint8 step=0;
    static int loop=0;
    static Uss_Thres_Data_t wThres[SIZE_USS_SENSOR];
    static Uss_Thres_Data_t rThres[SIZE_USS_SENSOR];
    int ussstart=0;
    int ussStop=12;

    for(int i=ussstart;i<ussStop;i++){
        UssDrivers_Thres_Default(&wThres[i]);
        // wThres[i].u8Atg_Alpha=1;
        // wThres[i].u8Atg_Cfg=3;
        // wThres[i].u8Atg_Tau=3;
        // wThres[i].u8Thresscale_Rec=3;
        // wThres[i].u8Thsft_Cfg=3;
        // wThres[i].u8Thval[0]=0x1f;
        // wThres[i].u8Thval[1]=0x1f;
        // wThres[i].u8Thval[2]=0x1f;
        // wThres[i].u8Thval[3]=0x1f;
        // wThres[i].u8Thval[4]=0x1f;
        // wThres[i].u8Thval[5]=0x1f;
        // wThres[i].u8Thval[6]=0x1f;
        // wThres[i].u8Thval[7]=0x1f;
        // wThres[i].u8Thval[8]=0x1f;
        // wThres[i].u8Thval[9]=0x1f;
        // wThres[i].u8Thval[10]=0x1f;
        // wThres[i].u8Thval[11]=0x1f;
    }

    switch (step)
    {
        case 0:
            if(loop<1000){
                loop++;
                step++;
            }
            if(loop==1000){
                debug_printf("test finish\n");
                step=99;
            }else if((loop%100)==0){
                debug_printf("test loop:%d\n",loop);
            }
        break;
        case 1:{
            for(int i=ussstart;i<ussStop;i++){
                ret[i]=get_threshold(i);
            }
            for(int i=ussstart;i<ussStop;i++){
                if(ret[i]!=0)
                    debug_printf("[Error]:Loop=%d,USS#%d,get_Thr ret=%d\n",loop,i,ret[i]);
            }
            step++;
            break;
        }
        case 2:{
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
        case 3:{
            memset(rThres,0,sizeof(rThres));
            for(int i=ussstart;i<ussStop;i++){
                ret[i]=read_threshold(i,&rThres[i]);
            }
            for(int i=ussstart;i<ussStop;i++){
                if(ret[i]!=0)
                    debug_printf("[Error]:Loop=%d,USS#%d,read_thr ret=%d\n",loop,i,ret[i]);
            }
            for(int i=ussstart;i<ussStop;i++){
                int retcmp=memcmp(&wThres[i],&rThres[i],sizeof(rThres[i]));
                if(retcmp!=0)
                    debug_printf("[Error]:Not same at Loop=%d,USS#%d,retcmp=%d\n",loop,i,retcmp);
            }
            step=0;
            break;
        }
        case 99:
        break;
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
