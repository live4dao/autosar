/*  BEGIN_FILE_HDR
********************************************************************************
*   File Name       : SchM.c
********************************************************************************
*   Project/Product : AUTOSAR BSW PROJECT
*   Title           : Rte module configuration File
*   Author          : Hirain
********************************************************************************
*   Description     : Rte module configuration File
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
*   Includes.
*******************************************************************************/

#include "SchM.h"

/*******************************************************************************
*   Rte Api
*******************************************************************************/
#define RTE_START_SEC_CODE
#include "MemMap.h"

FUNC(void, RTE_CODE) SchM_Init(void)
{
}


FUNC(void, RTE_CODE) SchM_Deinit(void)
{
}



FUNC(Std_ReturnType, RTE_CODE) SchM_Switch_Dcm_DcmCommunicationControl_ComM_CanCtrl_0
(
    VAR(Rte_ModeType_DcmCommunicationControl_ComM_CanCtrl_0, AUTOMATIC) nextMode
)
{
    return RTE_E_OK;
}
FUNC(Std_ReturnType, RTE_CODE) SchM_Switch_Dcm_DcmCommunicationControl_ComM_CanCtrl_1
(
    VAR(Rte_ModeType_DcmCommunicationControl_ComM_CanCtrl_1, AUTOMATIC) nextMode
)
{
    return RTE_E_OK;
}
FUNC(Std_ReturnType, RTE_CODE) SchM_Switch_Dcm_DcmCommunicationControl_ComM_EthCtrl
(
    VAR(Rte_ModeType_DcmCommunicationControl_ComM_EthCtrl, AUTOMATIC) nextMode
)
{
    return RTE_E_OK;
}
FUNC(Std_ReturnType, RTE_CODE) SchM_Switch_Dcm_DcmControlDtcSetting
(
    VAR(Rte_ModeType_DcmControlDtcSetting, AUTOMATIC) nextMode
)
{
    return RTE_E_OK;
}
FUNC(Std_ReturnType, RTE_CODE) SchM_Switch_Dcm_DcmDiagnosticSessionControl
(
    VAR(Rte_ModeType_DcmDiagnosticSessionControl, AUTOMATIC) nextMode
)
{
    return RTE_E_OK;
}
FUNC(Std_ReturnType, RTE_CODE) SchM_Switch_Dcm_DcmEcuReset
(
    VAR(Rte_ModeType_DcmEcuReset, AUTOMATIC) nextMode
)
{
    return RTE_E_OK;
}
#define RTE_STOP_SEC_CODE
#include "MemMap.h"



