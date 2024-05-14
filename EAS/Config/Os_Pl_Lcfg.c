/*  BEGIN_FILE_HDR
********************************************************************************
*   File Name       : Os_Pl_Lcfg.c
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
#include "Os_Internal.h"

/*****************************************************************************
* General QAC Suppression
******************************************************************************/
/*PRQA S 0862 EOF*/
/*
The code segment like:

#define XXX
#include "Os_MemMap.h"

is a part of AUTOSAR specification, but will be an error in PRQA.
*/

/*PRQA S 3211 EOF*/
/*
There are global variables which were defined here to be used in other files.
*/

/*****************************************************************************
* Generated variables
******************************************************************************/
#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
CONST(CoreIdType, OS_CONST) Os_PhyCoreToLog[OS_PL_MAX_CORE_NUMBER] =
{
    (CoreIdType)0,
    (CoreIdType)1,
    (CoreIdType)2,
    (CoreIdType)3,
    (CoreIdType)4,
    (CoreIdType)5
};
/* autosar core must sort first*/
CONST(CoreIdType, OS_CONST) Os_LogCoreToPhy[OS_USED_CORE_NUMBER] = 
{
    (CoreIdType)0,
    (CoreIdType)1,
    (CoreIdType)2,
    (CoreIdType)3,
    (CoreIdType)4,
    (CoreIdType)5
};
CONST(Os_AddrType, OS_CONST) Os_CoreStartAddr[OS_USED_CORE_NUMBER] = 
{
    (Os_AddrType)0,
    (Os_AddrType)1,
    (Os_AddrType)2,
    (Os_AddrType)3,
    (Os_AddrType)4,
    (Os_AddrType)5
};
CONST(Os_Pl_TaskCfgType, OS_CONST) Os_Pl_TaskCfg[OS_TASK_NUMBER] = 
{
    {
        ACCESSMODE_PRIVILEGED
    },
    {
        ACCESSMODE_PRIVILEGED
    },
    {
        ACCESSMODE_PRIVILEGED
    },
    {
        ACCESSMODE_PRIVILEGED
    },
    {
        ACCESSMODE_PRIVILEGED
    },
    {
        ACCESSMODE_PRIVILEGED
    },
    {
        ACCESSMODE_PRIVILEGED
    },
    {
        ACCESSMODE_PRIVILEGED
    },
    {
        ACCESSMODE_PRIVILEGED
    },
    {
        ACCESSMODE_PRIVILEGED
    },
    {
        ACCESSMODE_PRIVILEGED
    },
    {
        ACCESSMODE_PRIVILEGED
    },
    {
        ACCESSMODE_PRIVILEGED
    },
    {
        ACCESSMODE_PRIVILEGED
    },
    {
        ACCESSMODE_PRIVILEGED
    },
    {
        ACCESSMODE_PRIVILEGED
    },
    {
        ACCESSMODE_PRIVILEGED
    },
    {
        ACCESSMODE_PRIVILEGED
    },
    {
        ACCESSMODE_PRIVILEGED
    },
    {
        ACCESSMODE_PRIVILEGED
    },
    {
        ACCESSMODE_PRIVILEGED
    },
    {
        ACCESSMODE_PRIVILEGED
    },
    {
        ACCESSMODE_PRIVILEGED
    },
    {
        ACCESSMODE_PRIVILEGED
    },
    {
        ACCESSMODE_PRIVILEGED
    },
    {
        ACCESSMODE_PRIVILEGED
    },
    {
        ACCESSMODE_PRIVILEGED
    },
    {
        ACCESSMODE_PRIVILEGED
    },
    {
        ACCESSMODE_PRIVILEGED
    },
    {
        ACCESSMODE_PRIVILEGED
    },
    {
        ACCESSMODE_PRIVILEGED
    },
    {
        ACCESSMODE_PRIVILEGED
    },
    {
        ACCESSMODE_PRIVILEGED
    },
    {
        ACCESSMODE_PRIVILEGED
    },
    {
        ACCESSMODE_PRIVILEGED
    },
    {
        ACCESSMODE_PRIVILEGED
    },
    {
        ACCESSMODE_PRIVILEGED
    }
};
#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
