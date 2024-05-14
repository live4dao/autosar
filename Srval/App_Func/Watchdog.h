#ifndef __WATCHDOG_H__
#define __WATCHDOG_H__


//---------------------------- Include File ---------------------------------//
#include "Wdg_17_Scu.h"
#include "Smu.h"
#include "Stm.h"
#include "IfxSrc_reg.h"

//---------------------------- Define Constant ------------------------------//
// #define WDG_ENABLE

//---------------------------- Declare Function -----------------------------// 
extern void WDG_Init(void);
extern void feed_dog(void);

#endif