/*  BEGIN_FILE_HDR
********************************************************************************
*   File Name       : Dcm_Callout.h
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

#ifndef DCM_CALLOUT_H
#define DCM_CALLOUT_H

/*******************************************************************************
* Include files
*******************************************************************************/
#include "Dcm_Types.h"

#define DCM_START_SEC_CODE
#include "MemMap.h"
extern FUNC(Std_ReturnType, DCM_CALLOUT_CODE)  Dcm_SetProgConditions
(
    Dcm_OpStatusType OpStatus, 
    Dcm_ProgConditionsType *ProgConditions
);
extern FUNC(Dcm_EcuStartModeType, DCM_CALLOUT_CODE) Dcm_GetProgConditions
(
    Dcm_ProgConditionsType *ProgConditions
);

#define DCM_STOP_SEC_CODE
#include "MemMap.h"
#endif/*DCM_CALLOUT_H*/

