/*  BEGIN_FILE_HDR
********************************************************************************
*   NOTICE
*   This software is the property of HiRain Technologies. Any information
*   contained in this doc should not be reproduced, or used, or disclosed
*   without the written authorization from HiRain Technologies.
********************************************************************************
*   File Name       : BswM_FrSM.h
********************************************************************************
*   Project/Product : AUTOSAR 4.2
*   Title           : BSWM module FrSM ralated header File
*   Author          : Hirain
********************************************************************************
*   Description     : The header file BswM_FrSM.h contains the declaration of
*                     functions which is called by the FrSM module
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

#ifndef BSWM_FRSM_H
#define BSWM_FRSM_H

/*******************************************************************************
*   Includes
*******************************************************************************/
#include "FrSM_Types.h"
#include "BswM_Cfg.h"
#include "BswM_Version.h"

/*******************************************************************************
*   Function Declaration
*******************************************************************************/
#define BSWM_START_SEC_CODE
#include "MemMap.h"


#if(STD_ON == BSWM_FRSM_ENABLED)
extern FUNC(void, BSWM_CODE) BswM_FrSM_CurrentState
(
    NetworkHandleType Network,
    FrSM_BswM_StateType CurrentState
);

#endif



#define BSWM_STOP_SEC_CODE
#include "MemMap.h"


#endif/* BSWM_FRSM_H */

