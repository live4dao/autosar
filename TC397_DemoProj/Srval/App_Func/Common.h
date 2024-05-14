/******************************************************************************
;       Program     : Common.h
;       Function    : Declare Common Function & Variable
;       Chip        : Infineon TC397
;       Clock       : Internal SYSPLL 300MHz
;       Date        : 2023 / 12 / 25
;       Author      : Fenderson Lu
******************************************************************************/
#ifndef __COMMON_H__
#define __COMMON_H__
//---------------------------- Support Library ------------------------------//
#include "McalLib.h"
// #include "Bsp.h"            // Time delay function

//---------------------------- Define Constant ------------------------------//
enum TimeUnit
{
    UNIT_MILLISECOND,
    UNIT_MICROSEOND
};


//---------------------------- Declare Function -----------------------------//
extern void Common_Delay(uint8 u8DelayUnit, uint32 u32DelayTime);
extern boolean Common_Debounce_Counter(uint32 *u32CountValues);
#endif




