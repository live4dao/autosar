/*  BEGIN_FILE_HDR
********************************************************************************
*   File Name       : Dcm_Callout.c
********************************************************************************
*   Project/Product : AUTOSAR BSW PROJECT
*   Title           : Dcm module configuration File
*   Author          : Hirain
********************************************************************************
*   Description     : Dcm module configuration File
*
********************************************************************************
*   Limitations     : None
*
********************************************************************************
*
********************************************************************************
*   Revision History:
*
*   Version     Date          Initials      CR#          Descriptions
*   ---------   ----------    ------------  ----------   ---------------
*   V1.0.0_3.5.5_AZ240046       27/03/2024    Eas           N/A          N/A
*
********************************************************************************
* END_FILE_HDR*/

/*******************************************************************************
* Include files
*******************************************************************************/
#include "Dcm_Callout.h"

/* Input File User Code start*/

/* Input File User Code end*/
#define DCM_START_SEC_CODE
#include "MemMap.h"

FUNC(Std_ReturnType, DCM_CALLOUT_CODE)  Dcm_SetProgConditions
(
    Dcm_OpStatusType OpStatus, 
    Dcm_ProgConditionsType *ProgConditions
)
{
    Std_ReturnType ret = E_OK;
    /* Dcm_SetProgConditions User Code start*/

    /* Dcm_SetProgConditions User Code end*/
    return ret;
}
FUNC(Dcm_EcuStartModeType, DCM_CALLOUT_CODE) Dcm_GetProgConditions
(
    Dcm_ProgConditionsType *ProgConditions
)
{
    Dcm_EcuStartModeType ret = DCM_COLD_START;
    /*progConditions must be Inited here ,if DCM_WARM_START is return*/
    /* Dcm_GetProgConditions User Code start*/

    /* Dcm_GetProgConditions User Code end*/
    return ret;
}
#define DCM_STOP_SEC_CODE
#include "MemMap.h"



