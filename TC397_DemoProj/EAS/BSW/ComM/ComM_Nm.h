/*  BEGIN_FILE_HDR
********************************************************************************
*   NOTICE
*   This software is the property of HiRain Technologies. Any information
*   contained in this doc should not be reproduced, or used, or disclosed
*   without the written authorization from HiRain Technologies.
********************************************************************************
*   File Name       : ComM_Nm.h
********************************************************************************
*   Project/Product : AUTOSAR 4.2
*   Title           : COMM module Nm ralated header File
*   Author          : Hirain
********************************************************************************
*   Description     : The header file ComM_Nm.h contains the declaration of
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

#ifndef COMM_NM_H
#define COMM_NM_H

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


#if(STD_ON == COMM_NM_SUPPORT)

extern FUNC(void, COMM_CODE) ComM_Nm_NetworkStartIndication
(
    NetworkHandleType Channel
);

extern FUNC(void, COMM_CODE) ComM_Nm_NetworkMode
(
    NetworkHandleType Channel
);

extern FUNC(void, COMM_CODE) ComM_Nm_PrepareBusSleepMode
(
    NetworkHandleType Channel
);

extern FUNC(void, COMM_CODE) ComM_Nm_BusSleepMode
(
    NetworkHandleType Channel
);

extern FUNC(void, COMM_CODE) ComM_Nm_RestartIndication
(
    NetworkHandleType Channel
);

#endif


#define COMM_STOP_SEC_CODE
#include "MemMap.h"


#endif/* COMM_NM_H */

