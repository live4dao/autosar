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
**  FILENAME     : Cpu4_Main.c                                                **
**                                                                            **
**  VERSION      : 0.0.2                                                      **
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
**  DESCRIPTION  : Example Cpu4 Main startup file                             **
**                                                                            **
**  SPECIFICATION(S) : NA                                                     **
**                                                                            **
**  MAY BE CHANGED BY USER : yes                                              **
**                                                                            **
*******************************************************************************/

#include "Mcal_Compiler.h"
#include "Ifx_Ssw_Infra.h"
#include "IFX_Os.h"
#include "McalLib.h"
#include "EcuM.h"

volatile uint32 ledBlink4 = 0;

#if (MCAL_NO_OF_CORES >= 5)

void core4_main (void)
{
  volatile unsigned short LoopFlag = 1U;
  unsigned short cpuWdtPassword;
  ENABLE();
  /*
   * !!WATCHDOG2 IS DISABLED HERE!!
   * Enable the watchdog in the demo if it is required and also service the watchdog periodically
   * */
  cpuWdtPassword = Ifx_Ssw_getCpuWatchdogPassword(&MODULE_SCU.WDTCPU[4]);
  Ifx_Ssw_disableCpuWatchdog(&MODULE_SCU.WDTCPU[4], cpuWdtPassword);

  EcuM_Init();
  while (LoopFlag == 1U)
  {
  }

}
#endif

