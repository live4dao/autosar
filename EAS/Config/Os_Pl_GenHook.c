/*  BEGIN_FILE_HDR
********************************************************************************
*   File Name       : Os_Pl_GenHook.c
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
#include "Os.h"

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

/*PRQA S 3206 EOF*/
/* Some parameters which are not used in OS code are reserved for users. */

#define OS_START_SEC_CALLOUT_CODE
#include "Os_MemMap.h"
void Os_PL_Trap0_Hook(Os_uint8 tin)
{

}
void Os_PL_Trap1_Hook(Os_uint8 tin)
{

}
void Os_PL_Trap2_Hook(Os_uint8 tin)
{

}
void Os_PL_Trap3_Hook(Os_uint8 tin)
{

}
void Os_PL_Trap4_Hook(Os_uint8 tin)
{

}
void Os_PL_Trap5_Hook(Os_uint8 tin)
{

}
void Os_PL_Trap6_Hook(Os_uint8 tin)
{

}
void Os_PL_Trap7_Hook(Os_uint8 tin)
{

}
#define OS_STOP_SEC_CALLOUT_CODE
#include "Os_MemMap.h"
