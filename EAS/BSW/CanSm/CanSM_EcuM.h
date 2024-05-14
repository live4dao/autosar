/*  BEGIN_FILE_HDR
********************************************************************************
*   NOTICE
*   This software is the property of HiRain Technologies. Any information
*   contained in this doc should not be reproduced, or used, or disclosed
*   without the written authorization from HiRain Technologies.
********************************************************************************
*   File Name       : CanSM_EcuM.h
********************************************************************************
*   Project/Product : AUTOSAR 4.2
*   Title           : CanSM module Header File
*   Author          : Hirain
********************************************************************************
*   Description     : CanSM module Header File
*
********************************************************************************
*   Limitations     : None
*
********************************************************************************
*
********************************************************************************
*   Revision History:
*   Reference to Core C File
********************************************************************************
* END_FILE_HDR*/
#ifndef CANSM_ECUM_H
#define CANSM_ECUM_H

/*******************************************************************************
*   Includes
*******************************************************************************/
#include "CanSM_Types.h"

/*******************************************************************************
*   API Declare
*******************************************************************************/
#define CANSM_START_SEC_CODE
#include "MemMap.h"

extern FUNC(Std_ReturnType, CANSM_CODE) CanSM_StartWakeupSource
(
    NetworkHandleType  network
);

extern FUNC(Std_ReturnType, CANSM_CODE) CanSM_StopWakeupSource
(
    NetworkHandleType  network
);

#define CANSM_STOP_SEC_CODE
#include "MemMap.h"


#endif /*#ifndef CANSM_ECUM_H*/

