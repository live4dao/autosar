/*  BEGIN_FILE_HDR
********************************************************************************
*   NOTICE
*   This software is the property of HiRain Technologies. Any information
*   contained in this doc should not be reproduced, or used, or disclosed
*   without the written authorization from HiRain Technologies.
********************************************************************************
* File Name:       Os_PL_Types.h
********************************************************************************
* Project/Product: AUTOSAR EAS
* Title:           Os_Intc.h
* Author:          Hirain
********************************************************************************
* Description:     Declare of intc functions
*
********************************************************************************
* Limitations     : None
*
********************************************************************************
*
********************************************************************************
*   Revision History:
*   Reference to Os_Cpu.c File
********************************************************************************
* END_FILE_HDR*/

#ifndef OS_PL_TYPES_H
#define OS_PL_TYPES_H

#include "Os_BasicTypes.h"
#include "Os_Cfg.h"
/* Stack direction of growth 
   only used in precompile level, so no type of value
*/
#define OS_PL_STACK_GROW_DOWN  (0x0F)
#define OS_PL_STACK_GROW_UP    (0xF0)


/* Tp tick depends on the hw timer used by tp*/
typedef Os_uint32 Os_TpTickType;
typedef Os_uint32 Os_SysTickType;
typedef Os_SysTickType Os_CpuLoadTickType;
#if(OS_USED_CORE_NUMBER > 1)
typedef Os_uint32 Os_Pl_SpinlockType;
#endif
#if(OS_APPLICATION_NUMBER > 0)
typedef enum
{
    ACCESSMODE_USER_0 = 0,
    ACCESSMODE_USER_1 = 1,
    ACCESSMODE_PRIVILEGED = 2
} Os_Pl_AccessModeType;

/* Constants definition of task control block */
typedef struct
{
    Os_Pl_AccessModeType AccessMode;
} Os_Pl_TaskCfgType;
typedef Os_uint32  Os_Pl_AppMaskType;      
#endif
/******************************************************************************/
/******************************************************************************/


#endif/*OS_PL_TYPES_H*/
