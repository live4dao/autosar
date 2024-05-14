/*  BEGIN_FILE_HDR
********************************************************************************
*   File Name       : Os_Lcfg.h
********************************************************************************
*   Project/Product : AUTOSAR BSW PROJECT
*   Title           : OS module configuration File
*   Author          : Hirain
********************************************************************************
*   Description     : OS module configuration File
*
********************************************************************************
*   Limitations     : None
*
********************************************************************************
*
********************************************************************************
*   Revision History:
*
*   Version     Date          Initials      CR#          Descriptions
*   ---------   ----------    ------------  ----------   ---------------
*   V1.0.0_3.5.5_AZ240046       27/03/2024    Eas           N/A          N/A
*
********************************************************************************
* END_FILE_HDR*/

#ifndef OS_LCFG_H
#define OS_LCFG_H
#include "Os_Types.h"

#define OS_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Os_MemMap.h"
/* Task*/
extern CONST(Os_TaskCfgType, OS_CONST) Os_TaskCfg[OS_TASK_NUMBER];

/*ISR*/
extern CONST(Os_ISRCfgType, OS_CONST) Os_ISRCfg[OS_ISR_NUMBER];

/*Os App*/
extern CONST(Os_AppCfgType, OS_CONST) Os_AppCfg[OS_APPLICATION_NUMBER];


/*Counter*/
extern CONST(Os_CounterCfgType, OS_CONST) Os_CounterCfg[OS_COUNTER_NUMBER];


/*Alarm*/
extern CONST(Os_AlarmCfgType, OS_CONST) Os_AlarmCfg[OS_ALARM_NUMBER];


/*SCHTBL*/


/*Resource*/


/*Spinlock*/


/*Core*/
extern CONST(Os_CoreCfgType, OS_CONST) Os_CoreCfg[OS_USED_CORE_NUMBER];



#define OS_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Os_MemMap.h"
#endif
