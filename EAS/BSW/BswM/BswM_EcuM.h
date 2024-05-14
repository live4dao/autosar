/*  BEGIN_FILE_HDR
********************************************************************************
*   NOTICE
*   This software is the property of HiRain Technologies. Any information
*   contained in this doc should not be reproduced, or used, or disclosed
*   without the written authorization from HiRain Technologies.
********************************************************************************
*   File Name       : BswM_EcuM.h
********************************************************************************
*   Project/Product : AUTOSAR 4.2
*   Title           : BswM_EcuM.h
*   Author          : Hirain
********************************************************************************
*   Description     : The header file BswM_EcuM.h contains the declaration of
*                     functions which is called by the EcuM module
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

#ifndef BSWM_ECUM_H
#define BSWM_ECUM_H

/*******************************************************************************
*   Includes
*******************************************************************************/
#include "EcuM.h"
#include "BswM_Cfg.h"
#include "BswM_Version.h"

/*******************************************************************************
*   Function Declaration
*******************************************************************************/
#define BSWM_START_SEC_CODE
#include "MemMap.h"


#if(STD_ON == BSWM_ECUM_ENABLED)
extern FUNC(void, BSWM_CODE) BswM_EcuM_CurrentState
(
    EcuM_StateType CurrentState
);

#if(STD_ON == BSWM_ECUM_WKUPSRC_ENABLED)
extern FUNC(void, BSWM_CODE) BswM_EcuM_CurrentWakeup
(
    EcuM_WakeupSourceType source,
    EcuM_WakeupStatusType state
);
#endif

extern FUNC(void, BSWM_CODE) BswM_EcuM_RequestedState
(
    EcuM_StateType State,
    EcuM_RunStatusType CurrentStatus
);
#endif



#define BSWM_STOP_SEC_CODE
#include "MemMap.h"

#endif/* BSWM_ECUM_H */

