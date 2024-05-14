/*  BEGIN_FILE_HDR
********************************************************************************
*   NOTICE
*   This software is the property of HiRain Technologies. Any information
*   contained in this doc should not be reproduced, or used, or disclosed
*   without the written authorization from HiRain Technologies.
********************************************************************************
*   File Name       : BswM_LinSM.h
********************************************************************************
*   Project/Product : AUTOSAR 4.2
*   Title           : BSWM module LinSM ralated header File
*   Author          : Hirain
********************************************************************************
*   Description     : The header file BswM_LinSM.h contains the declaration of
*                     functions which is called by the LinSM module
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

#ifndef BSWM_LINSM_H
#define BSWM_LINSM_H

/*******************************************************************************
*   Includes
*******************************************************************************/
#include "LinSM.h"
#include "BswM_Cfg.h"
#include "BswM_Version.h"

/*******************************************************************************
*   Function Declaration
*******************************************************************************/
#define BSWM_START_SEC_CODE
#include "MemMap.h"


#if(STD_ON == BSWM_LINSM_ENABLED)
extern FUNC(void, BSWM_CODE) BswM_LinSM_CurrentState
(
    NetworkHandleType Network,
    LinSM_ModeType CurrentState
);

extern FUNC(void, BSWM_CODE) BswM_LinSM_CurrentSchedule
(
    NetworkHandleType Network,
    LinIf_SchHandleType CurrentSchedule
);

#endif



#define BSWM_STOP_SEC_CODE
#include "MemMap.h"


#endif/* BSWM_LINSM_H */

