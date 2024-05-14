/*  BEGIN_FILE_HDR
********************************************************************************
*   NOTICE
*   This software is the property of HiRain Technologies. Any information
*   contained in this doc should not be reproduced, or used, or disclosed
*   without the written authorization from HiRain Technologies.
********************************************************************************
*   File Name       : BswM_Dcm.h
********************************************************************************
*   Project/Product : AUTOSAR 4.2
*   Title           : BSWM module Dcm ralated header File
*   Author          : Hirain
********************************************************************************
*   Description     : The header file BswM_Dcm.h contains the declaration of
*                     functions which is called by the Dcm module
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

#ifndef BSWM_DCM_H
#define BSWM_DCM_H

/*******************************************************************************
*   Includes
*******************************************************************************/
#include "Dcm_Types.h"
#include "BswM_Cfg.h"
#include "BswM_Version.h"

/*******************************************************************************
*   API Declaration
*******************************************************************************/
#define BSWM_START_SEC_CODE
#include "MemMap.h"


#if(STD_ON == BSWM_DCM_ENABLED)
extern FUNC(void, BSWM_CODE) BswM_Dcm_CommunicationMode_CurrentState
(
    NetworkHandleType Network,
    Dcm_CommunicationModeType RequestedMode
);

extern FUNC(void, BSWM_CODE) BswM_Dcm_ApplicationUpdated
(
    void
);

#endif



#define BSWM_STOP_SEC_CODE
#include "MemMap.h"


#endif/* BSWM_DCM_H */

