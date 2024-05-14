/*  BEGIN_FILE_HDR
********************************************************************************
*   NOTICE
*   This software is the property of HiRain Technologies. Any information
*   contained in this doc should not be reproduced, or used, or disclosed
*   without the written authorization from HiRain Technologies.
********************************************************************************
*   File Name       : ComM_BswMEcuM.h
********************************************************************************
*   Project/Product : AUTOSAR 4.2
*   Title           : ComM_BswMEcuM.h
*   Author          : Hirain
********************************************************************************
*   Description     : The header file ComM_BswMEcuM.h contains the declaration of
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

#ifndef COMM_ECUM_BSWM_H
#define COMM_ECUM_BSWM_H

/*SWS_ComM_00463*/
/*******************************************************************************
*   Includes
*******************************************************************************/
#include "ComM_Cfg.h"
#include "ComM_Version.h"

/*******************************************************************************
*   Function Declaration
*******************************************************************************/
#define COMM_START_SEC_CODE
#include "MemMap.h"


#if(STD_ON == COMM_ECUM_SUPPORT)
extern FUNC(void, COMM_CODE) ComM_EcuM_WakeUpIndication
(
    NetworkHandleType Channel
);

#endif

extern FUNC(void, COMM_CODE) ComM_CommunicationAllowed
(
    NetworkHandleType Channel,
    boolean Allowed
);



#define COMM_STOP_SEC_CODE
#include "MemMap.h"

#endif/* COMM_ECUM_BSWM_H */


