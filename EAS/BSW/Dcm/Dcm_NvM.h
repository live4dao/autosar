/*  BEGIN_FILE_HDR
********************************************************************************
*   NOTICE
*   This software is the property of HiRain Technologies. Any information
*   contained in this doc should not be reproduced, or used, or disclosed
*   without the written authorization from HiRain Technologies.
********************************************************************************
*   File Name       : Dcm_NvM.h
********************************************************************************
*   Project/Product : AUTOSAR 4.2
*   Title           : Dcm_NvM.h
*   Author          : Hirain
********************************************************************************
*   Description: Callback header file of the AUTOSAR Dcm Module.
*
********************************************************************************
*   Limitations: None
*
********************************************************************************
*
********************************************************************************
*   Revision History:
*   Reference to Core C File
********************************************************************************
* END_FILE_HDR */

#ifndef DCM_NVM_H
#define DCM_NVM_H
/*******************************************************************************
* Include files
*******************************************************************************/
#include "Dcm_Types.h"
#include "Dcm_Version.h"
#if(STD_ON == DCM_NVM_SUPPORT)
#include "NvM_Types.h"
#endif


/*******************************************************************************
* Global Function Prototype
*******************************************************************************/

#define DCM_START_SEC_CODE
#include "MemMap.h"

#if((DCM_UDS_2C_SERVICE == STD_ON)&&(DCM_DDDID_STORAGE == STD_OFF))
extern FUNC(Std_ReturnType, Dcm_CODE) Dcm_NvM_InitStorageMem
(
    void
);

#if(STD_ON == DCM_NVM_SUPPORT)
extern FUNC(Std_ReturnType, Dcm_CODE) Dcm_NvM_JobResultInd
(
    uint8 ServiceId,
    NvM_RequestResultType JobResult
);
#endif
#endif
#define DCM_STOP_SEC_CODE
#include "MemMap.h"


#endif/*DCM_NVM_H*/


