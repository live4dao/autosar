/*  BEGIN_FILE_HDR
********************************************************************************
*   File Name       : Rte_CtApState_Machine.h
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
*   V1.0.2_3.5.5_AZ240046       10/05/2024    Eas           N/A          N/A
*
********************************************************************************
* END_FILE_HDR*/
#ifndef RTE_CTAPSTATE_MACHINE_H
#define RTE_CTAPSTATE_MACHINE_H

#ifndef RTE_CORE
#ifdef RTE_APPLICATION_HEADER_FILE
#error Multiple application header files included.
#endif /* RTE_APPLICATION_HEADER_FILE */
#define RTE_APPLICATION_HEADER_FILE
#endif
# ifdef __cplusplus
extern "C"
{
# endif /* __cplusplus */

/*******************************************************************************
*   Includes.
*******************************************************************************/
#include "Rte_CtApState_Machine_Type.h"
#include "Com.h"
/*******************************************************************************
*   define for a symbolic name of the RunnableEntity.
*******************************************************************************/
#define RTE_RUNNABLE_State_Machinie_init                    State_Machinie_init
#define RTE_RUNNABLE_TSK_State_Machine_40ms                 TSK_State_Machine_40ms

/*******************************************************************************
*   Instance Handle
*******************************************************************************/
#ifndef RTE_CORE
typedef CONSTP2CONST(Rte_CDS_CtApState_Machine, AUTOMATIC, RTE_CONST) Rte_Instance;
#endif

/*******************************************************************************
*   Macro definition.
*******************************************************************************/
#define Rte_Write_ADAS_APA_AbortWarning_ADAS_APA_AbortWarning         Rte_Write_CtApState_Machine_ADAS_APA_AbortWarning_ADAS_APA_AbortWarning
#define Rte_Write_ADAS_APA_BrakeModeSts_ADAS_APA_BrakeModeSts         Rte_Write_CtApState_Machine_ADAS_APA_BrakeModeSts_ADAS_APA_BrakeModeSts
#define Rte_Write_ADAS_APA_ModeSelect_ADAS_APA_ModeSelect   Rte_Write_CtApState_Machine_ADAS_APA_ModeSelect_ADAS_APA_ModeSelect
#define Rte_Write_ADAS_APA_OperationSts_ADAS_APA_OperationSts         Rte_Write_CtApState_Machine_ADAS_APA_OperationSts_ADAS_APA_OperationSts
#define Rte_Write_ADAS_APA_OtherWarning_ADAS_APA_OtherWarning         Rte_Write_CtApState_Machine_ADAS_APA_OtherWarning_ADAS_APA_OtherWarning
#define Rte_Write_ADAS_APA_OverspeedAlarm_ADAS_APA_OverspeedAlarm     Rte_Write_CtApState_Machine_ADAS_APA_OverspeedAlarm_ADAS_APA_OverspeedAlarm
#define Rte_Write_ADAS_APA_ParkingDirection_ADAS_APA_ParkingDirection Rte_Write_CtApState_Machine_ADAS_APA_ParkingDirection_ADAS_APA_ParkingDirection
#define Rte_Write_ADAS_APA_ParkingModeReq_ADAS_APA_ParkingModeReq     Rte_Write_CtApState_Machine_ADAS_APA_ParkingModeReq_ADAS_APA_ParkingModeReq
#define Rte_Write_ADAS_APA_ParkingType_ADAS_APA_ParkingType Rte_Write_CtApState_Machine_ADAS_APA_ParkingType_ADAS_APA_ParkingType
#define Rte_Write_ADAS_APA_PauseWarning_ADAS_APA_PauseWarning         Rte_Write_CtApState_Machine_ADAS_APA_PauseWarning_ADAS_APA_PauseWarning
#define Rte_Write_ADAS_APA_RemindTxt1_ADAS_APA_RemindTxt1   Rte_Write_CtApState_Machine_ADAS_APA_RemindTxt1_ADAS_APA_RemindTxt1
#define Rte_Write_ADAS_APA_RemindTxt2_ADAS_APA_RemindTxt2   Rte_Write_CtApState_Machine_ADAS_APA_RemindTxt2_ADAS_APA_RemindTxt2
#define Rte_Write_ADAS_APA_RenewParkingReq_ADAS_APA_RenewParkingReq   Rte_Write_CtApState_Machine_ADAS_APA_RenewParkingReq_ADAS_APA_RenewParkingReq
#define Rte_Write_ADAS_APA_SearchingWarning_ADAS_APA_SearchingWarning Rte_Write_CtApState_Machine_ADAS_APA_SearchingWarning_ADAS_APA_SearchingWarning
#define Rte_Write_ADAS_APA_Soundremind_ADAS_APA_Soundremind Rte_Write_CtApState_Machine_ADAS_APA_Soundremind_ADAS_APA_Soundremind
#define Rte_Write_ADAS_APA_StartParkingReq_ADAS_APA_StartParkingReq   Rte_Write_CtApState_Machine_ADAS_APA_StartParkingReq_ADAS_APA_StartParkingReq
#define Rte_Write_ADAS_APA_SystemSts_ADAS_APA_SystemSts     Rte_Write_CtApState_Machine_ADAS_APA_SystemSts_ADAS_APA_SystemSts
#define Rte_Write_ADAS_USS_FaultFLI_ADAS_USS_FaultFLI       Rte_Write_CtApState_Machine_ADAS_USS_FaultFLI_ADAS_USS_FaultFLI
#define Rte_Write_ADAS_USS_FaultFLO_ADAS_USS_FaultFLO       Rte_Write_CtApState_Machine_ADAS_USS_FaultFLO_ADAS_USS_FaultFLO
#define Rte_Write_ADAS_USS_FaultFLS_ADAS_USS_FaultFLS       Rte_Write_CtApState_Machine_ADAS_USS_FaultFLS_ADAS_USS_FaultFLS
#define Rte_Write_ADAS_USS_FaultFRI_ADAS_USS_FaultFRI       Rte_Write_CtApState_Machine_ADAS_USS_FaultFRI_ADAS_USS_FaultFRI
#define Rte_Write_ADAS_USS_FaultFRO_ADAS_USS_FaultFRO       Rte_Write_CtApState_Machine_ADAS_USS_FaultFRO_ADAS_USS_FaultFRO
#define Rte_Write_ADAS_USS_FaultFRS_ADAS_USS_FaultFRS       Rte_Write_CtApState_Machine_ADAS_USS_FaultFRS_ADAS_USS_FaultFRS
#define Rte_Write_ADAS_USS_FaultRLI_ADAS_USS_FaultRLI       Rte_Write_CtApState_Machine_ADAS_USS_FaultRLI_ADAS_USS_FaultRLI
#define Rte_Write_ADAS_USS_FaultRLO_ADAS_USS_FaultRLO       Rte_Write_CtApState_Machine_ADAS_USS_FaultRLO_ADAS_USS_FaultRLO
#define Rte_Write_ADAS_USS_FaultRLS_ADAS_USS_FaultRLS       Rte_Write_CtApState_Machine_ADAS_USS_FaultRLS_ADAS_USS_FaultRLS
#define Rte_Write_ADAS_USS_FaultRRI_ADAS_USS_FaultRRI       Rte_Write_CtApState_Machine_ADAS_USS_FaultRRI_ADAS_USS_FaultRRI
#define Rte_Write_ADAS_USS_FaultRRO_ADAS_USS_FaultRRO       Rte_Write_CtApState_Machine_ADAS_USS_FaultRRO_ADAS_USS_FaultRRO
#define Rte_Write_ADAS_USS_FaultRRS_ADAS_USS_FaultRRS       Rte_Write_CtApState_Machine_ADAS_USS_FaultRRS_ADAS_USS_FaultRRS
#define Rte_Write_APA_FrontSystemSts_APA_FrontSystemSts     Rte_Write_CtApState_Machine_APA_FrontSystemSts_APA_FrontSystemSts
#define Rte_Write_APA_RearSystemSts_APA_RearSystemSts       Rte_Write_CtApState_Machine_APA_RearSystemSts_APA_RearSystemSts
#define Rte_Write_APA_WCBS_BrakeFunctionMode_APA_WCBS_BrakeFunctionMode         Rte_Write_CtApState_Machine_APA_WCBS_BrakeFunctionMode_APA_WCBS_BrakeFunctionMode
#define Rte_Write_PiControlCommand_PiControlCommand         Rte_Write_CtApState_Machine_PiControlCommand_PiControlCommand
#define Rte_Write_PiLocalizationCommand_PiLocalizationCommand         Rte_Write_CtApState_Machine_PiLocalizationCommand_PiLocalizationCommand
#define Rte_Write_PiPdcCommand_PiPdcCommand                 Rte_Write_CtApState_Machine_PiPdcCommand_PiPdcCommand
#define Rte_Write_PiPerceptionCommand_PiPerceptionCommand   Rte_Write_CtApState_Machine_PiPerceptionCommand_PiPerceptionCommand
#define Rte_Write_PiPlanningCommand_PiPlanningCommand       Rte_Write_CtApState_Machine_PiPlanningCommand_PiPlanningCommand
#define Rte_Read_ADAS_ACC_OperatingSts_ADAS_ACC_OperatingSts          Rte_Read_CtApState_Machine_ADAS_ACC_OperatingSts_ADAS_ACC_OperatingSts
#define Rte_Read_AEB_TgtDecel_Req_AEB_TgtDecel_Req          Rte_Read_CtApState_Machine_AEB_TgtDecel_Req_AEB_TgtDecel_Req
#define Rte_Read_EPB_SysWrnIndReq_EPB_SysWrnIndReq          Rte_Read_CtApState_Machine_EPB_SysWrnIndReq_EPB_SysWrnIndReq
#define Rte_Read_EPS_APA_CtrlAbortFeedback_EPS_APA_CtrlAbortFeedback  Rte_Read_CtApState_Machine_EPS_APA_CtrlAbortFeedback_EPS_APA_CtrlAbortFeedback
#define Rte_Read_EPS_SterFltMod_EPS_SterFltMod              Rte_Read_CtApState_Machine_EPS_SterFltMod_EPS_SterFltMod
#define Rte_Read_ESC_TcsCtrlActv_ESC_TcsCtrlActv            Rte_Read_CtApState_Machine_ESC_TcsCtrlActv_ESC_TcsCtrlActv
#define Rte_Read_MHU_APA_ParkIn_Req_MHU_APA_ParkIn_Req      Rte_Read_CtApState_Machine_MHU_APA_ParkIn_Req_MHU_APA_ParkIn_Req
#define Rte_Read_MHU_APA_ParkOut_Direction_MHU_APA_ParkOut_Direction  Rte_Read_CtApState_Machine_MHU_APA_ParkOut_Direction_MHU_APA_ParkOut_Direction
#define Rte_Read_MHU_APA_ParkOut_Mode_MHU_APA_ParkOut_Mode  Rte_Read_CtApState_Machine_MHU_APA_ParkOut_Mode_MHU_APA_ParkOut_Mode
#define Rte_Read_MHU_APA_ParkOut_Req_MHU_APA_ParkOut_Req    Rte_Read_CtApState_Machine_MHU_APA_ParkOut_Req_MHU_APA_ParkOut_Req
#define Rte_Read_MHU_APA_ParkingReCover_Req_MHU_APA_ParkingReCover_Req          Rte_Read_CtApState_Machine_MHU_APA_ParkingReCover_Req_MHU_APA_ParkingReCover_Req
#define Rte_Read_MHU_APA_ParkingStart_Req_MHU_APA_ParkingStart_Req    Rte_Read_CtApState_Machine_MHU_APA_ParkingStart_Req_MHU_APA_ParkingStart_Req
#define Rte_Read_MHU_APA_Req_MHU_APA_Req                    Rte_Read_CtApState_Machine_MHU_APA_Req_MHU_APA_Req
#define Rte_Read_PEPS_IGN1RelaySts_PEPS_IGN1RelaySts        Rte_Read_CtApState_Machine_PEPS_IGN1RelaySts_PEPS_IGN1RelaySts
#define Rte_Read_PEPS_PowerMode_PEPS_PowerMode              Rte_Read_CtApState_Machine_PEPS_PowerMode_PEPS_PowerMode
#define Rte_Read_PiApaControlState_PiAPAControlState        Rte_Read_CtApState_Machine_PiApaControlState_PiAPAControlState
#define Rte_Read_PiCarInfoH_PiCarInfoH                      Rte_Read_CtApState_Machine_PiCarInfoH_PiCarInfoH
#define Rte_Read_PiCarInfoL_PiCarInfoL                      Rte_Read_CtApState_Machine_PiCarInfoL_PiCarInfoL
#define Rte_Read_PiFusionStatus_PiFusionStatus              Rte_Read_CtApState_Machine_PiFusionStatus_PiFusionStatus
#define Rte_Read_PiGlobalPoseBuffer_PiGlobalPoseBuffer      Rte_Read_CtApState_Machine_PiGlobalPoseBuffer_PiGlobalPoseBuffer
#define Rte_Read_PiLocalizationWorkingStatus_PiLocalizationWorkingStatus        Rte_Read_CtApState_Machine_PiLocalizationWorkingStatus_PiLocalizationWorkingStatus
#define Rte_Read_PiPlanningWorkingStatus_PiPlanningWorkingStatus      Rte_Read_CtApState_Machine_PiPlanningWorkingStatus_PiPlanningWorkingStatus
#define Rte_Read_PiSignalTransWorkingStatus_PiSignalTransWorkingStatus          Rte_Read_CtApState_Machine_PiSignalTransWorkingStatus_PiSignalTransWorkingStatus
#define Rte_Read_PiUssDataProWorkingStatus_P_PiUssDataProWorkingStatus          Rte_Read_CtApState_Machine_PiUssDataProWorkingStatus_P_PiUssDataProWorkingStatus
#define Rte_Read_PiUssFsdWorkingStatus_PiUssFsdWorkingStatus          Rte_Read_CtApState_Machine_PiUssFsdWorkingStatus_PiUssFsdWorkingStatus
#define Rte_Read_PiUssPdcWorkingStatus_PiUssPdcWorkingStatus          Rte_Read_CtApState_Machine_PiUssPdcWorkingStatus_PiUssPdcWorkingStatus
#define Rte_Read_PiUssStatusSet_PiUssStatusSet              Rte_Read_CtApState_Machine_PiUssStatusSet_PiUssStatusSet
#define Rte_Read_PiUssTaskWorkingStatus_PiUssTaskWorkingStatus        Rte_Read_CtApState_Machine_PiUssTaskWorkingStatus_PiUssTaskWorkingStatus
#define Rte_Read_PiVisionStatus_PiVisionStatus              Rte_Read_CtApState_Machine_PiVisionStatus_PiVisionStatus
#define Rte_Read_SAS_Calibrated_SAS_Calibrated              Rte_Read_CtApState_Machine_SAS_Calibrated_SAS_Calibrated
#define Rte_Read_SAS_SASFailure_SAS_SASFailure              Rte_Read_CtApState_Machine_SAS_SASFailure_SAS_SASFailure
#define Rte_Read_TPMS_SysSts_TPMS_SysSts                    Rte_Read_CtApState_Machine_TPMS_SysSts_TPMS_SysSts
#define Rte_Read_VCU_Ready_VCU_Ready                        Rte_Read_CtApState_Machine_VCU_Ready_VCU_Ready
#define Rte_Read_WCBS_APA_EmgyBrkAvlb_WCBS_APA_EmgyBrkAvlb  Rte_Read_CtApState_Machine_WCBS_APA_EmgyBrkAvlb_WCBS_APA_EmgyBrkAvlb
#define Rte_Read_WCBS_APA_VLC_FailureStatus_WCBS_APA_VLC_FailureStatus          Rte_Read_CtApState_Machine_WCBS_APA_VLC_FailureStatus_WCBS_APA_VLC_FailureStatus
/*******************************************************************************
*   Extended
*******************************************************************************/
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtApState_Machine_ADAS_APA_AbortWarning_ADAS_APA_AbortWarning
(
    VAR(ADAS_APA_AbortWarning_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtApState_Machine_ADAS_APA_BrakeModeSts_ADAS_APA_BrakeModeSts
(
    VAR(ADAS_APA_BrakeModeSts_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtApState_Machine_ADAS_APA_ModeSelect_ADAS_APA_ModeSelect
(
    VAR(ADAS_APA_ModeSelect_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtApState_Machine_ADAS_APA_OperationSts_ADAS_APA_OperationSts
(
    VAR(ADAS_APA_OperationSts_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtApState_Machine_ADAS_APA_OtherWarning_ADAS_APA_OtherWarning
(
    VAR(ADAS_APA_OtherWarning_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtApState_Machine_ADAS_APA_OverspeedAlarm_ADAS_APA_OverspeedAlarm
(
    VAR(ADAS_APA_OverspeedAlarm_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtApState_Machine_ADAS_APA_ParkingDirection_ADAS_APA_ParkingDirection
(
    VAR(ADAS_APA_ParkingDirection_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtApState_Machine_ADAS_APA_ParkingModeReq_ADAS_APA_ParkingModeReq
(
    VAR(ADAS_APA_ParkingModeReq_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtApState_Machine_ADAS_APA_ParkingType_ADAS_APA_ParkingType
(
    VAR(ADAS_APA_ParkingType_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtApState_Machine_ADAS_APA_PauseWarning_ADAS_APA_PauseWarning
(
    VAR(ADAS_APA_PauseWarning_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtApState_Machine_ADAS_APA_RemindTxt1_ADAS_APA_RemindTxt1
(
    VAR(ADAS_APA_RemindTxt1_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtApState_Machine_ADAS_APA_RemindTxt2_ADAS_APA_RemindTxt2
(
    VAR(ADAS_APA_RemindTxt2_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtApState_Machine_ADAS_APA_RenewParkingReq_ADAS_APA_RenewParkingReq
(
    VAR(ADAS_APA_RenewParkingReq_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtApState_Machine_ADAS_APA_SearchingWarning_ADAS_APA_SearchingWarning
(
    VAR(ADAS_APA_SearchingWarning_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtApState_Machine_ADAS_APA_Soundremind_ADAS_APA_Soundremind
(
    VAR(ADAS_APA_Soundremind_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtApState_Machine_ADAS_APA_StartParkingReq_ADAS_APA_StartParkingReq
(
    VAR(ADAS_APA_StartParkingReq_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtApState_Machine_ADAS_APA_SystemSts_ADAS_APA_SystemSts
(
    VAR(ADAS_APA_SystemSts_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtApState_Machine_ADAS_USS_FaultFLI_ADAS_USS_FaultFLI
(
    VAR(ADAS_USS_FaultFLI_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtApState_Machine_ADAS_USS_FaultFLO_ADAS_USS_FaultFLO
(
    VAR(ADAS_USS_FaultFLO_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtApState_Machine_ADAS_USS_FaultFLS_ADAS_USS_FaultFLS
(
    VAR(ADAS_USS_FaultFLS_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtApState_Machine_ADAS_USS_FaultFRI_ADAS_USS_FaultFRI
(
    VAR(ADAS_USS_FaultFRI_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtApState_Machine_ADAS_USS_FaultFRO_ADAS_USS_FaultFRO
(
    VAR(ADAS_USS_FaultFRO_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtApState_Machine_ADAS_USS_FaultFRS_ADAS_USS_FaultFRS
(
    VAR(ADAS_USS_FaultFRS_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtApState_Machine_ADAS_USS_FaultRLI_ADAS_USS_FaultRLI
(
    VAR(ADAS_USS_FaultRLI_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtApState_Machine_ADAS_USS_FaultRLO_ADAS_USS_FaultRLO
(
    VAR(ADAS_USS_FaultRLO_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtApState_Machine_ADAS_USS_FaultRLS_ADAS_USS_FaultRLS
(
    VAR(ADAS_USS_FaultRLS_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtApState_Machine_ADAS_USS_FaultRRI_ADAS_USS_FaultRRI
(
    VAR(ADAS_USS_FaultRRI_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtApState_Machine_ADAS_USS_FaultRRO_ADAS_USS_FaultRRO
(
    VAR(ADAS_USS_FaultRRO_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtApState_Machine_ADAS_USS_FaultRRS_ADAS_USS_FaultRRS
(
    VAR(ADAS_USS_FaultRRS_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtApState_Machine_APA_FrontSystemSts_APA_FrontSystemSts
(
    VAR(APA_FrontSystemSts_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtApState_Machine_APA_RearSystemSts_APA_RearSystemSts
(
    VAR(APA_RearSystemSts_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtApState_Machine_APA_WCBS_BrakeFunctionMode_APA_WCBS_BrakeFunctionMode
(
    VAR(APA_WCBS_BrakeFunctionMode_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtApState_Machine_PiControlCommand_PiControlCommand
(
    P2VAR(Command, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtApState_Machine_PiLocalizationCommand_PiLocalizationCommand
(
    P2VAR(Command, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtApState_Machine_PiPdcCommand_PiPdcCommand
(
    P2VAR(Command, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtApState_Machine_PiPerceptionCommand_PiPerceptionCommand
(
    P2VAR(PerceptionCommand, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtApState_Machine_PiPlanningCommand_PiPlanningCommand
(
    P2VAR(Command, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtApState_Machine_ADAS_ACC_OperatingSts_ADAS_ACC_OperatingSts
(
    P2VAR(ADAS_ACC_OperatingSts_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtApState_Machine_AEB_TgtDecel_Req_AEB_TgtDecel_Req
(
    P2VAR(AEB_TgtDecel_Req_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtApState_Machine_EPB_SysWrnIndReq_EPB_SysWrnIndReq
(
    P2VAR(EPB_SysWrnIndReq_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtApState_Machine_EPS_APA_CtrlAbortFeedback_EPS_APA_CtrlAbortFeedback
(
    P2VAR(EPS_APA_CtrlAbortFeedback_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtApState_Machine_EPS_SterFltMod_EPS_SterFltMod
(
    P2VAR(EPS_SterFltMod_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtApState_Machine_ESC_TcsCtrlActv_ESC_TcsCtrlActv
(
    P2VAR(ESC_TcsCtrlActv_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtApState_Machine_MHU_APA_ParkIn_Req_MHU_APA_ParkIn_Req
(
    P2VAR(MHU_APA_ParkIn_Req_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtApState_Machine_MHU_APA_ParkOut_Direction_MHU_APA_ParkOut_Direction
(
    P2VAR(MHU_APA_ParkOut_Direction_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtApState_Machine_MHU_APA_ParkOut_Mode_MHU_APA_ParkOut_Mode
(
    P2VAR(MHU_APA_ParkOut_Mode_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtApState_Machine_MHU_APA_ParkOut_Req_MHU_APA_ParkOut_Req
(
    P2VAR(MHU_APA_ParkOut_Req_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtApState_Machine_MHU_APA_ParkingReCover_Req_MHU_APA_ParkingReCover_Req
(
    P2VAR(MHU_APA_ParkingReCover_Req_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtApState_Machine_MHU_APA_ParkingStart_Req_MHU_APA_ParkingStart_Req
(
    P2VAR(MHU_APA_ParkingStart_Req_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtApState_Machine_MHU_APA_Req_MHU_APA_Req
(
    P2VAR(MHU_APA_Req_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtApState_Machine_PEPS_IGN1RelaySts_PEPS_IGN1RelaySts
(
    P2VAR(PEPS_IGN1RelaySts_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtApState_Machine_PEPS_PowerMode_PEPS_PowerMode
(
    P2VAR(PEPS_PowerMode_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtApState_Machine_PiApaControlState_PiAPAControlState
(
    P2VAR(APAControlState, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtApState_Machine_PiCarInfoH_PiCarInfoH
(
    P2VAR(CarInfoH, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtApState_Machine_PiCarInfoL_PiCarInfoL
(
    P2VAR(CarInfoL, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtApState_Machine_PiFusionStatus_PiFusionStatus
(
    P2VAR(WorkingStatus, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtApState_Machine_PiGlobalPoseBuffer_PiGlobalPoseBuffer
(
    P2VAR(GlobalPoseBuffer, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtApState_Machine_PiLocalizationWorkingStatus_PiLocalizationWorkingStatus
(
    P2VAR(WorkingStatus, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtApState_Machine_PiPlanningWorkingStatus_PiPlanningWorkingStatus
(
    P2VAR(WorkingStatus, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtApState_Machine_PiSignalTransWorkingStatus_PiSignalTransWorkingStatus
(
    P2VAR(WorkingStatus, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtApState_Machine_PiUssDataProWorkingStatus_P_PiUssDataProWorkingStatus
(
    P2VAR(WorkingStatus, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtApState_Machine_PiUssFsdWorkingStatus_PiUssFsdWorkingStatus
(
    P2VAR(WorkingStatus, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtApState_Machine_PiUssPdcWorkingStatus_PiUssPdcWorkingStatus
(
    P2VAR(WorkingStatus, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtApState_Machine_PiUssStatusSet_PiUssStatusSet
(
    P2VAR(UssStatusSet, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtApState_Machine_PiUssTaskWorkingStatus_PiUssTaskWorkingStatus
(
    P2VAR(WorkingStatus, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtApState_Machine_PiVisionStatus_PiVisionStatus
(
    P2VAR(WorkingStatus, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtApState_Machine_SAS_Calibrated_SAS_Calibrated
(
    P2VAR(SAS_Calibrated_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtApState_Machine_SAS_SASFailure_SAS_SASFailure
(
    P2VAR(SAS_SASFailure_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtApState_Machine_TPMS_SysSts_TPMS_SysSts
(
    P2VAR(TPMS_SysSts_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtApState_Machine_VCU_Ready_VCU_Ready
(
    P2VAR(VCU_Ready_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtApState_Machine_WCBS_APA_EmgyBrkAvlb_WCBS_APA_EmgyBrkAvlb
(
    P2VAR(WCBS_APA_EmgyBrkAvlb_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtApState_Machine_WCBS_APA_VLC_FailureStatus_WCBS_APA_VLC_FailureStatus
(
    P2VAR(WCBS_APA_VLC_FailureStatus_IDT, AUTOMATIC, RTE_APPL_DATA) data
);

/*******************************************************************************
*   Runnable Extended
*******************************************************************************/

#define CtApState_Machine_START_SEC_CODE
#include "CtApState_Machine_MemMap.h"

extern FUNC(void, CtApState_Machine_CODE) State_Machinie_init
(
    void
);
#define CtApState_Machine_STOP_SEC_CODE
#include "CtApState_Machine_MemMap.h"


#define CtApState_Machine_START_SEC_CODE
#include "CtApState_Machine_MemMap.h"

extern FUNC(void, CtApState_Machine_CODE) TSK_State_Machine_40ms
(
    void
);
#define CtApState_Machine_STOP_SEC_CODE
#include "CtApState_Machine_MemMap.h"


# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif  /*RTE_CTAPSTATE_MACHINE_H*/


