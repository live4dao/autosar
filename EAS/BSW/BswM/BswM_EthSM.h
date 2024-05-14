/*  BEGIN_FILE_HDR
********************************************************************************
*   NOTICE
*   This software is the property of HiRain Technologies. Any information
*   contained in this doc should not be reproduced, or used, or disclosed
*   without the written authorization from HiRain Technologies.
********************************************************************************
*   File Name       : BswM_EthSM.h
********************************************************************************
*   Project/Product : AUTOSAR 4.2
*   Title           : BSWM module EthSM ralated header File
*   Author          : Hirain
********************************************************************************
*   Description     : The header file BswM_EthSM.h contains the declaration of
*                     functions which is called by the EthSM module
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

#ifndef BSWM_ETHSM_H
#define BSWM_ETHSM_H

/*******************************************************************************
*   Includes
*******************************************************************************/
#include "EthSM_Types.h"
#include "BswM_Cfg.h"
#include "BswM_Version.h"

/*******************************************************************************
*   Function Declaration
*******************************************************************************/
#define BSWM_START_SEC_CODE
#include "MemMap.h"


#if(STD_ON == BSWM_ETHSM_ENABLED)
extern FUNC(void, BSWM_CODE) BswM_EthSM_CurrentState
(
    NetworkHandleType Network,
    EthSM_NetworkModeStateType CurrentState
);

#endif



#define BSWM_STOP_SEC_CODE
#include "MemMap.h"


#endif/* BSWM_ETHSM_H */

