/*******************************************************************************
**                                                                            **
** Copyright (C) Infineon Technologies (2016)                                 **
**                                                                            **
** All rights reserved.                                                       **
**                                                                            **
** This document contains proprietary information belonging to Infineon       **
** Technologies. Passing on and copying of this document, and communication   **
** of its contents is not permitted without prior written authorization.      **
**                                                                            **
********************************************************************************
**                                                                            **
**  FILENAME     : Cpu0_Main.c                                                **
**                                                                            **
**  VERSION      : 0.0.1                                                      **
**                                                                            **
**  DATE         : 2016-08-17                                                 **
**                                                                            **
**  VARIANT      : NA                                                         **
**                                                                            **
**  PLATFORM     : Infineon AURIX2G                                           **
**                                                                            **
**  AUTHOR       : DL-AUTOSAR-Engineering                                     **
**                                                                            **
**  VENDOR       : Infineon Technologies                                      **
**                                                                            **
**  DESCRIPTION  : Example Cpu0 Main startup file                             **
**                                                                            **
**  SPECIFICATION(S) : NA                                                     **
**                                                                            **
**  MAY BE CHANGED BY USER : yes                                              **
**                                                                            **
*******************************************************************************/
/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
#include "Ifx_Ssw_Infra.h"
#include "IFX_Os.h"
//#include "Port.h"
#include "Dio.h"
#include "McalLib.h" //for CAN_T_START define
#ifdef AURIX2G_MCAL_DEMOAPP
#include "DemoApp.h"
#endif
#include "IfxStm_reg.h"

#include "EcuM.h"
#include "Mcu.h"
#include "Port.h"

/*******************************************************************************
**                      Imported Compiler Switch Check                        **
*******************************************************************************/

/*******************************************************************************
**                      Private Macro Definitions                             **
*******************************************************************************/
#define STM_Timer1      (1U)
#define STM_0_Cmp0      (0U)

//#define CAN_T_START 0
/*******************************************************************************
**                      Private Type Definitions                              **
*******************************************************************************/

/*******************************************************************************
**                      Private Function Declarations                         **
*******************************************************************************/
//static void Stm_DemoAppCbk(void);

// extern void Bsw_MainFunction_5ms(void);
/*******************************************************************************
**                      Global Constant Definitions                           **
*******************************************************************************/

/*******************************************************************************
**                      Global Variable Definitions                           **
*******************************************************************************/
volatile uint32 Stm_Toggle = 0;

volatile uint8 counterForTask5ms = 0;

volatile uint8 core0_Counter = 0;

/*******************************************************************************
**                      Private Constant Definitions                          **
*******************************************************************************/

/*******************************************************************************
**                      Private Variable Definitions                          **
*******************************************************************************/

/*******************************************************************************
**                      Global Functon Definitions                            **
*******************************************************************************/

/*********************************************************************************
** Syntax : void Stm_DemoAppCbk(void)                                           **
**                                                                              **
** Service ID:   : NA                                                           **
**                                                                              **
** Sync/Async:   : Synchronous                                                  **
**                                                                              **
** Reentrancy:   : NA                                                           **
**                                                                              **
** Parameters (in): none                                                        **
**                                                                              **
** Parameters (out): none                                                       **
**                                                                              **
** Return value: none                                                           **
**                                                                              **
** Description : This is a CallBack Function Invoked when an interrupt is raised**
**                                                                              **
*********************************************************************************/
void Stm_Cycle_1ms_Cbk(void)
{
	counterForTask5ms++;
}
/*******************************************************************************
** Syntax : void delay_ms(uint32 ms)                                          **
**                                                                            **
** Service ID:   : NA                                                         **
**                                                                            **
** Sync/Async:   : Synchronous                                                **
**                                                                            **
** Reentrancy:   : Non Reentrant                                              **
**                                                                            **
** Parameters (in): ms                                                        **
**                                                                            **
** Parameters (out): none                                                     **
**                                                                            **
** Return value: none                                                         **
**                                                                            **
** Description : delay times ms stm 100MHZ ticks 0.00000001s, 1s 100000000    **
**                                                                            **
*******************************************************************************/
uint32 CurrSTMTick=0;
uint32 BaseSTMTick=0;
//stm 100MHZ ticks 0.00000001s, 1s 100000000
void delay_ms(uint32 ms)
{
  CurrSTMTick = Mcal_DelayGetTick();
  BaseSTMTick = CurrSTMTick;
  while ((uint32)((CurrSTMTick - BaseSTMTick) & 0xffffffff) <
           ms * 100000)
  {
    CurrSTMTick = Mcal_DelayGetTick();
  }
}

void core0_main (void)
{
  volatile unsigned short LoopFlag = 1U;
  unsigned short cpuWdtPassword;
  unsigned short safetyWdtPassword;

  ENABLE();
  /*
   * !!WATCHDOG0 AND SAFETY WATCHDOG ARE DISABLED HERE!!
   * Enable the watchdog in the demo if it is required and also service the watchdog periodically
   * */
  cpuWdtPassword = Ifx_Ssw_getCpuWatchdogPassword(&MODULE_SCU.WDTCPU[0]);
  safetyWdtPassword = Ifx_Ssw_getSafetyWatchdogPassword();
  Ifx_Ssw_disableCpuWatchdog(&MODULE_SCU.WDTCPU[0], cpuWdtPassword);
  Ifx_Ssw_disableSafetyWatchdog(safetyWdtPassword);

  EcuM_Init();

  while (LoopFlag == 1U)
  {
	  ;
  }

}
