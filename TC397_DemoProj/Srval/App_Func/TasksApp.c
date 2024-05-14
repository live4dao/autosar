/******************************************************************************
;       Program     :TasksApp.c
;       Function    :Simulate TASK function
;       Chip        :Infineon TC397
;       Clock       :Internal SYSPLL 300MHz
;       Date        :2023 / 12 / 26
;       Author      :Fenderson Lu
;       Describe: 
******************************************************************************/
//--------------------- Include File ----------------------------------//
// #include "Cpu0_Main.h"
#include "TasksApp.h"
#include "Uart_Demo.h"
//#include "Ethernet.h"
#include "Watchdog.h"

#include "UssApp.h"
#include "Icu_17_TimerIp.h"
// #include "Platform_Types.h"
// #include "UssDrivers.h"
// #include <stdio.h>

//--------------------- Declare Global Variable -----------------------//
//const uint8 gu8McuVer[SIZE_MCU_VER] __attribute__((section(".mcu_version"))) = {0x56, 0x31, 0x2E, 0x30, 0x30, 0x2E, 0x30, 0x31};            // MCU Version is V0.00.01
//const uint8 gu8McuChecksum[SIZE_MCU_CHKSUM] __attribute__((section(".mcu_checksum"))) = {0x0F, 0xB7, 0x6F, 0x1D};
uint32 gu32Val[3]={1,2,3};
uint16 u16Status;
uint8 tri=1;

// static uint32 gRxTimestampBuf[100];
uint32 NewSTMTick=0;
uint32 OldSTMTick=0;
//--------------------- Start Program ---------------------------------//
void TasksApp_1ms(void)
{
    Uss_MainFunction();
    // Uss_Demo();

}
//---------------------------------------------------------------------//
void TasksApp_100ms(void)
{    

}
//---------------------------------------------------------------------//
void TasksApp_1s(void)
{
    // feed_dog();
    // // TransmitArpFrame(); //FIXME It will let WDG reset.
    // // debug_printf("Task_1s\n");
    
    // //Check time value=1 sec cycle.
    // char uartBuffer[32];
    // NewSTMTick = Mcal_DelayGetTick(); //100=1us
    // int length = snprintf(uartBuffer, 32, "t:%u\n", (NewSTMTick-OldSTMTick));
    // debug_printf(uartBuffer);
    // OldSTMTick=NewSTMTick;
    // /*---------------------------------------------------------------------------*/
    Uss_Demo();
    debug_printf("GPT 1s Task...\n");
	    
}
//---------------------------------------------------------------------//
void TasksApp_3s(void)
{
    // memset(gRxTimestampBuf,0,sizeof(gRxTimestampBuf));
    // Icu_17_TimerIp_StartTimestamp(IcuConf_IcuChannel_IcuChannel_1,gRxTimestampBuf[0],100,1);
    // debug_printf("The core3 3s Task...\n");
}
//---------------------------------------------------------------------//


