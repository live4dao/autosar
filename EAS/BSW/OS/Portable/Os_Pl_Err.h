/*  BEGIN_FILE_HDR
********************************************************************************
*   NOTICE
*   This software is the property of HiRain Technologies. Any information
*   contained in this doc should not be reproduced, or used, or disclosed
*   without the written authorization from HiRain Technologies.
********************************************************************************
* File Name:       Os_PL_err.h
********************************************************************************
* Project/Product: AUTOSAR OS PROJECT
* Title:           Os_PL_err.h
* Author:          Hirain
********************************************************************************
* Description:     Define the Macro for error handling.
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

#ifndef OS_PL_ERR_H
#define OS_PL_ERR_H

/*****************************************************************************
* files include
******************************************************************************/


/*****************************************************************************
* hw non fatal OS self define error code,  start from 0xC0
******************************************************************************/
#define OS_IE_PL_CDC_ERR                   ((StatusType)0xE0)

/*****************************************************************************
* hw fatal OS self define error code,  start from 0xE0
******************************************************************************/
#define E_OS_PL_SYSFATA_CSA_ERR            ((StatusType)0xE0)
#define E_OS_PL_SYSFATA_ACCESS_REG_ERR     ((StatusType)0xE1)
#define E_OS_PL_SYSFATA_TP_TIMER_ERROR     ((StatusType)0xE2)
#define E_OS_PL_SYSFATA_REG_ERR            ((StatusType)0xE3)
#define E_OS_PL_SYSFATA_ISRNEST_ERR        ((StatusType)0xE4)

/*****************************************************************************
* internal Service Id
******************************************************************************/
/*Cpu*/
#define OSServiceId_OsCpu_TaskSwitch                   ((OSServiceIdType)0x8050)
#define OSServiceId_OsCpu_TaskTerminateSchedule        ((OSServiceIdType)0x8051)
#define OSServiceId_OsCpu_FreeTaskCSA                  ((OSServiceIdType)0x8052)

/*Intc*/
#define OSServiceId_OsIntc_InISR2                      ((OSServiceIdType)0x8150)
#define OSServiceId_OsIntc_OutISR2                     ((OSServiceIdType)0x8151)
#define OSServiceId_OsIntc_ReplaceIntPriority          ((OSServiceIdType)0x8152)
#define OSServiceId_OsIntc_FreeISRCSA                  ((OSServiceIdType)0x8153)
#define OSServiceId_OsIntc_CrossCoreIntInit            ((OSServiceIdType)0x8154)
#define OSServiceId_OsIntc_KillISRSchedule             ((OSServiceIdType)0x8155)

/*Timer*/
#define OSServiceId_OsTpTimer_GetElapsedTime           ((OSServiceIdType)0x8250)
#define OSServiceId_OsSysTimer_Init                    ((OSServiceIdType)0x8251)

/*****************************************************************************
* PL Error Info
******************************************************************************/

/*E_OS_SYS_UNREACHABLE*/
#define OS_IE_TASK_CSA_ERR     ((Os_uint16)0xE001)
#define OS_IE_ISR_CSA_ERR      ((Os_uint16)0xE002)

#endif
