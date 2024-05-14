/*  BEGIN_FILE_HDR
********************************************************************************
*   File Name       : SchM_Dcm.h
********************************************************************************
*   Project/Product : AUTOSAR BSW PROJECT
*   Title           : SchM module configuration File
*   Author          : Hirain
********************************************************************************
*   Description     : SchM module configuration File
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
#ifndef SCHM_DCM_H
#define SCHM_DCM_H
/*******************************************************************************
*   Include
*******************************************************************************/
#include "SchM_Dcm_Type.h"
#include "Os.h"

/*PRQA S 3453,3429 EOF*/
/*
1.The unified requirement of EAS is that the error reporting functions of Det
and Dem moduls are accessed by macro functions.This part has been verified and
has no problem.
2.Macro functions are allowed to use to access parameters and do some simple operations.
*/

/*PRQA S 792,791 EOF*/
/*
Name of macros may not follow relevant naming rules.
*/

/*******************************************************************************
*   exclusive Area
*******************************************************************************/
#define SchM_Enter_Dcm_DCM_EXCLUSIVE_AREA_0()
#define SchM_Exit_Dcm_DCM_EXCLUSIVE_AREA_0()


#define SchM_Enter_Dcm_DCM_EXCLUSIVE_AREA_1()
#define SchM_Exit_Dcm_DCM_EXCLUSIVE_AREA_1()


#define SchM_Switch_DcmCommunicationControl_ComM_CanCtrl_0  SchM_Switch_Dcm_DcmCommunicationControl_ComM_CanCtrl_0
#define SchM_Switch_DcmCommunicationControl_ComM_CanCtrl_1  SchM_Switch_Dcm_DcmCommunicationControl_ComM_CanCtrl_1
#define SchM_Switch_DcmCommunicationControl_ComM_EthCtrl    SchM_Switch_Dcm_DcmCommunicationControl_ComM_EthCtrl
#define SchM_Switch_DcmControlDtcSetting                    SchM_Switch_Dcm_DcmControlDtcSetting
#define SchM_Switch_DcmDiagnosticSessionControl             SchM_Switch_Dcm_DcmDiagnosticSessionControl
#define SchM_Switch_DcmEcuReset                             SchM_Switch_Dcm_DcmEcuReset
extern FUNC(Std_ReturnType, RTE_CODE) SchM_Switch_Dcm_DcmCommunicationControl_ComM_CanCtrl_0
(
    VAR(Rte_ModeType_DcmCommunicationControl_ComM_CanCtrl_0, AUTOMATIC) nextMode
);
extern FUNC(Std_ReturnType, RTE_CODE) SchM_Switch_Dcm_DcmCommunicationControl_ComM_CanCtrl_1
(
    VAR(Rte_ModeType_DcmCommunicationControl_ComM_CanCtrl_1, AUTOMATIC) nextMode
);
extern FUNC(Std_ReturnType, RTE_CODE) SchM_Switch_Dcm_DcmCommunicationControl_ComM_EthCtrl
(
    VAR(Rte_ModeType_DcmCommunicationControl_ComM_EthCtrl, AUTOMATIC) nextMode
);
extern FUNC(Std_ReturnType, RTE_CODE) SchM_Switch_Dcm_DcmControlDtcSetting
(
    VAR(Rte_ModeType_DcmControlDtcSetting, AUTOMATIC) nextMode
);
extern FUNC(Std_ReturnType, RTE_CODE) SchM_Switch_Dcm_DcmDiagnosticSessionControl
(
    VAR(Rte_ModeType_DcmDiagnosticSessionControl, AUTOMATIC) nextMode
);
extern FUNC(Std_ReturnType, RTE_CODE) SchM_Switch_Dcm_DcmEcuReset
(
    VAR(Rte_ModeType_DcmEcuReset, AUTOMATIC) nextMode
);
#endif



