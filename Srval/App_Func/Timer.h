/******************************************************************************
;       Program     : Timer_Gpt12.h
;       Function    : Declare Timer GPT12 Function
;       Chip        : Infineon TC397
;       Clock       : Internal SYSPLL 300MHz
;       Date        : 2023 / 12 / 26
;       Author      : Fenderson Lu
******************************************************************************/
#ifndef __TIMER_H__
#define __TIMER_H__
//---------------------------- Library Support --------------------------------//
#include "IfxStm_reg.h"
#include "IfxSrc_reg.h"
#include "Gpt.h"
#include "Platform_Types.h"

//---------------------------- Define Constant --------------------------------//
#define GPT_START_SEC_CODE_ASIL_B_GLOBAL
#define GPT_STOP_SEC_CODE_ASIL_B_GLOBAL


//---------------------------- Declare Function -------------------------------//
extern void Timer_Gpt_Init(void);

#endif

