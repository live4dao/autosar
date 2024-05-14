/*  BEGIN_FILE_HDR
********************************************************************************
*   NOTICE
*   This software is the property of HiRain Technologies. Any information
*   contained in this doc should not be reproduced, or used, or disclosed
*   without the written authorization from HiRain Technologies.
********************************************************************************
*   File Name       : BswM_NvM.h
********************************************************************************
*   Project/Product : AUTOSAR 4.2
*   Title           : BswM_NvM.h
*   Author          : Hirain
********************************************************************************
*   Description     : The header file BswM_NvM.h contains the declaration of
*                     functions which is called by the NvM module
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

#ifndef BSWM_NVM_H
#define BSWM_NVM_H

/*******************************************************************************
*   Includes
*******************************************************************************/
#include "NvM_Types.h"
#include "BswM_Cfg.h"
#include "BswM_Version.h"

/*******************************************************************************
*   Function Declaration
*******************************************************************************/
#define BSWM_START_SEC_CODE
#include "MemMap.h"

#if(STD_ON == BSWM_NVM_ENABLED)
extern FUNC(void, BSWM_CODE) BswM_NvM_CurrentBlockMode
(
    NvM_BlockIdType Block,
    NvM_RequestResultType CurrentBlockMode
);

extern FUNC(void, BSWM_CODE) BswM_NvM_CurrentJobMode
(
    uint8 ServiceId,
    NvM_RequestResultType CurrentJobMode
);
#endif




#define BSWM_STOP_SEC_CODE
#include "MemMap.h"

#endif/* BSWM_NVM_H */



