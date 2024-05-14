/*  BEGIN_FILE_HDR
********************************************************************************
*   File Name       : Os_Pl_Lcfg.h
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
*   V1.0.2_3.5.5_AZ240046       09/05/2024    Eas           N/A          N/A
*
********************************************************************************
* END_FILE_HDR*/

#ifndef OS_PL_LCFG_H
#define OS_PL_LCFG_H
#include "Os_Types.h"
/*****************************************************************************
* Generated variables
******************************************************************************/
#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
extern CONST(CoreIdType, OS_CONST) Os_PhyCoreToLog[OS_PL_MAX_CORE_NUMBER];
extern CONST(CoreIdType, OS_CONST) Os_LogCoreToPhy[OS_USED_CORE_NUMBER];
extern CONST(Os_AddrType, OS_CONST) Os_CoreStartAddr[OS_USED_CORE_NUMBER];
extern CONST(Os_Pl_TaskCfgType, OS_CONST) Os_Pl_TaskCfg[OS_TASK_NUMBER];

#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
extern Os_uint32 *_lc_gb_OS_CODE;
extern Os_uint32 *_lc_ge_OS_CODE;
extern Os_uint32 *_lc_gb_OS_KERNEL_NOINIT;
extern Os_uint32 *_lc_ge_OS_KERNEL_NOINIT;
extern Os_uint32 *_lc_gb_OS_KERNEL_INIT;
extern Os_uint32 *_lc_ge_OS_KERNEL_INIT;
extern Os_uint32 *_lc_gb_OS_CONST;
extern Os_uint32 *_lc_ge_OS_CONST;
#define __OS_CODE_start             (Os_uint32)&_lc_gb_OS_CODE
#define __OS_CODE_end               (Os_uint32)&_lc_ge_OS_CODE
#define OS_KERNEL_NOINIT_Start      (Os_uint32)&_lc_gb_OS_KERNEL_NOINIT
#define OS_KERNEL_NOINIT_End        (Os_uint32)&_lc_ge_OS_KERNEL_NOINIT
#define OS_KERNEL_INIT_Start        (Os_uint32)&_lc_gb_OS_KERNEL_INIT
#define OS_KERNEL_INIT_End          (Os_uint32)&_lc_ge_OS_KERNEL_INIT
#define OS_CONST_Start              (Os_uint32)&_lc_gb_OS_CONST
#define OS_CONST_End                (Os_uint32)&_lc_ge_OS_CONST

#endif

