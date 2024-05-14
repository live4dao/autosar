/*  BEGIN_FILE_HDR
********************************************************************************
*   NOTICE
*   This software is the property of HiRain Technologies. Any information
*   contained in this doc should not be reproduced, or used, or disclosed
*   without the written authorization from HiRain Technologies.
********************************************************************************
*   File Name       : ComM_BusSM.h
********************************************************************************
*   Project/Product : AUTOSAR 4.2
*   Title           : ComM_BusSM.h
*   Author          : Hirain
********************************************************************************
*   Description     : The header file ComM_BusSM.h contains the declaration of
*                     functions which is called by the CanSM, LinSM .etc module
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

#ifndef COMM_BUSSM_H
#define COMM_BUSSM_H

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


extern FUNC(void, COMM_CODE) ComM_BusSM_ModeIndication
(
    NetworkHandleType Channel,
    P2VAR(ComM_ModeType, AUTOMATIC, COMM_VAR) ComMode
);


#define COMM_STOP_SEC_CODE
#include "MemMap.h"


#endif/* COMM_BUSSM_H */

