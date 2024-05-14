/*  BEGIN_FILE_HDR
********************************************************************************
*   NOTICE
*   This software is the property of HiRain Technologies. Any information
*   contained in this doc should not be reproduced, or used, or disclosed
*   without the written authorization from HiRain Technologies.
********************************************************************************
*   File Name       : BswM_WdgM.h
********************************************************************************
*   Project/Product : AUTOSAR 4.2
*   Title           : BSWM module WdgM ralated header File
*   Author          : Hirain
********************************************************************************
*   Description     : The header file BswM_WdgM.h contains the declaration of
*                     functions which is called by the WdgM module
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

#ifndef BSWM_WDGM_H
#define BSWM_WDGM_H

/*******************************************************************************
*   Includes
*******************************************************************************/
#if(STD_ON == BSWM_WDGM_ENABLED)
#include "WdgM_Types.h"
#endif
#include "BswM_Cfg.h"
#include "BswM_Version.h"

/*******************************************************************************
*   Function Declaration
*******************************************************************************/
#define BSWM_START_SEC_CODE
#include "MemMap.h"


#if(STD_ON == BSWM_WDGM_ENABLED)
extern FUNC(void, BSWM_CODE) BswM_WdgM_RequestPartitionReset
(
    ApplicationType Application
);

#endif



#define BSWM_STOP_SEC_CODE
#include "MemMap.h"


#endif/* BSWM_WDGM_H */

