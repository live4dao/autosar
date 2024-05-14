/*  BEGIN_FILE_HDR
********************************************************************************
*   NOTICE
*   This software is the property of HiRain Technologies. Any information
*   contained in this doc should not be reproduced, or used, or disclosed
*   without the written authorization from HiRain Technologies.
********************************************************************************
*   File Name       : BswM_Nm.h
********************************************************************************
*   Project/Product : AUTOSAR 4.2
*   Title           : BSWM module Nm ralated header File
*   Author          : Hirain
********************************************************************************
*   Description     : The header file BswM_Nm.h contains the declaration of
*                     functions which is called by the Nm module
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

#ifndef BSWM_NM_H
#define BSWM_NM_H

/*******************************************************************************
*   Includes
*******************************************************************************/
#include "NmStack_Types.h"
#include "BswM_Cfg.h"
#include "BswM_Version.h"

/*******************************************************************************
*   Function Declaration
*******************************************************************************/
#define BSWM_START_SEC_CODE
#include "MemMap.h"


#if(STD_ON == BSWM_NM_ENABLED)
extern FUNC(void, BSWM_CODE) BswM_NmIf_CarWakeUpIndication
(
    NetworkHandleType Network
);

#endif



#define BSWM_STOP_SEC_CODE
#include "MemMap.h"


#endif/* BSWM_NM_H */

