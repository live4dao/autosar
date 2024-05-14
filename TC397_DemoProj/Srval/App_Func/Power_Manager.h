/******************************************************************************
;       Program     : Power_Manager.h
;       Function    : Power Control Module
;       Chip        : Infineon TC397
;       Clock       : Internal SYSPLL 300MHz
;       Date        : 2023 / 12 / 28
;       Author      : Fenderson Lu
******************************************************************************/
#ifndef __POWER_MANAGER_H__
#define __POWER_MANAGER_H__




//---------------------------- Library Support ------------------------------//
#include "Dio.h"
#include "Port.h"

//---------------------------- Declare Constant -----------------------------//

//---------------------------- Declare Function -----------------------------// 

/** @brief: Power turn ON function **/
extern void PinIO_Pwr_On_Sequence(void);

#endif




