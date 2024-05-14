/*  BEGIN_FILE_HDR
********************************************************************************
*   NOTICE
*   This software is the property of HiRain Technologies. Any information
*   contained in this doc should not be reproduced, or used, or disclosed
*   without the written authorization from HiRain Technologies.
********************************************************************************
*   File Name       : NvM_Cbk.h
********************************************************************************
*   Project/Product : AUTOSAR BSW
*   Title           : NvM module header File
*   Author          : Hirain
********************************************************************************
*   Description     : Implementation of Non-Volatile RAM manager.
*
********************************************************************************
*   Limitations     :
*
********************************************************************************
*
********************************************************************************
*   Revision History:
********************************************************************************
* END_FILE_HDR*/
#ifndef NVM_CBK_H
#define NVM_CBK_H
/*******************************************************************************
*   Include
*******************************************************************************/
#include "NvM_Types.h"

#define NVM_START_SEC_CODE
#include "MemMap.h"
/*******************************************************************************
*   Function  Declaration
*******************************************************************************/

#if (NVM_POLLING_MODE == STD_OFF)
extern FUNC(void, NVM_CODE) NvM_JobEndNotification(void);

extern FUNC(void, NVM_CODE) NvM_JobErrorNotification(void);
#endif

#define NVM_STOP_SEC_CODE
#include "MemMap.h"

#endif /*  #ifndef _NVM_CBK_H */


