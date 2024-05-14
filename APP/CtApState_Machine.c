/*  BEGIN_FILE_HDR
********************************************************************************
*   File Name       : CtApState_Machine.c
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
/*******************************************************************************
*   Includes.
*******************************************************************************/
#include "Rte_CtApState_Machine.h"

/* CtApState_MachineInput File User Code start*/

/* CtApState_MachineInput File User Code end*/

/* CtApState_Machine.c Custom Code (#define variable etc.) User Code start*/

/* CtApState_Machine.c Custom Code (#define variable etc.) User Code end*/

/*******************************************************************************
*   Runnable Extended
*******************************************************************************/

#define CtApState_Machine_START_SEC_CODE
#include "CtApState_Machine_MemMap.h"

FUNC(void, CtApState_Machine_CODE) State_Machinie_init
(
    void
)
{
    /* State_Machinie_init_Start User Code start*/

    /* State_Machinie_init_Start User Code end*/
    /* State_Machinie_init Varaible Define User Code start*/

    /* State_Machinie_init Varaible Define User Code end*/




    /* State_Machinie_init_Feedback User Code start*/

    /* State_Machinie_init_Feedback User Code end*/

}
#define CtApState_Machine_STOP_SEC_CODE
#include "CtApState_Machine_MemMap.h"


#define CtApState_Machine_START_SEC_CODE
#include "CtApState_Machine_MemMap.h"

FUNC(void, CtApState_Machine_CODE) TSK_State_Machine_40ms
(
    void
)
{
    /* TSK_State_Machine_40ms_Start User Code start*/

    /* TSK_State_Machine_40ms_Start User Code end*/
    ADAS_APA_AbortWarning_IDT Write_ADAS_APA_AbortWarning_ADAS_APA_AbortWarning;
    ADAS_APA_BrakeModeSts_IDT Write_ADAS_APA_BrakeModeSts_ADAS_APA_BrakeModeSts;
    ADAS_APA_ModeSelect_IDT Write_ADAS_APA_ModeSelect_ADAS_APA_ModeSelect;
    ADAS_APA_OperationSts_IDT Write_ADAS_APA_OperationSts_ADAS_APA_OperationSts;
    ADAS_APA_OtherWarning_IDT Write_ADAS_APA_OtherWarning_ADAS_APA_OtherWarning;
    ADAS_APA_OverspeedAlarm_IDT Write_ADAS_APA_OverspeedAlarm_ADAS_APA_OverspeedAlarm;
    ADAS_APA_ParkingDirection_IDT Write_ADAS_APA_ParkingDirection_ADAS_APA_ParkingDirection;
    ADAS_APA_ParkingModeReq_IDT Write_ADAS_APA_ParkingModeReq_ADAS_APA_ParkingModeReq;
    ADAS_APA_ParkingType_IDT Write_ADAS_APA_ParkingType_ADAS_APA_ParkingType;
    ADAS_APA_PauseWarning_IDT Write_ADAS_APA_PauseWarning_ADAS_APA_PauseWarning;
    ADAS_APA_RemindTxt1_IDT Write_ADAS_APA_RemindTxt1_ADAS_APA_RemindTxt1;
    ADAS_APA_RemindTxt2_IDT Write_ADAS_APA_RemindTxt2_ADAS_APA_RemindTxt2;
    ADAS_APA_RenewParkingReq_IDT Write_ADAS_APA_RenewParkingReq_ADAS_APA_RenewParkingReq;
    ADAS_APA_SearchingWarning_IDT Write_ADAS_APA_SearchingWarning_ADAS_APA_SearchingWarning;
    ADAS_APA_Soundremind_IDT Write_ADAS_APA_Soundremind_ADAS_APA_Soundremind;
    ADAS_APA_StartParkingReq_IDT Write_ADAS_APA_StartParkingReq_ADAS_APA_StartParkingReq;
    ADAS_APA_SystemSts_IDT Write_ADAS_APA_SystemSts_ADAS_APA_SystemSts;
    ADAS_USS_FaultFLI_IDT Write_ADAS_USS_FaultFLI_ADAS_USS_FaultFLI;
    ADAS_USS_FaultFLO_IDT Write_ADAS_USS_FaultFLO_ADAS_USS_FaultFLO;
    ADAS_USS_FaultFLS_IDT Write_ADAS_USS_FaultFLS_ADAS_USS_FaultFLS;
    ADAS_USS_FaultFRI_IDT Write_ADAS_USS_FaultFRI_ADAS_USS_FaultFRI;
    ADAS_USS_FaultFRO_IDT Write_ADAS_USS_FaultFRO_ADAS_USS_FaultFRO;
    ADAS_USS_FaultFRS_IDT Write_ADAS_USS_FaultFRS_ADAS_USS_FaultFRS;
    ADAS_USS_FaultRLI_IDT Write_ADAS_USS_FaultRLI_ADAS_USS_FaultRLI;
    ADAS_USS_FaultRLO_IDT Write_ADAS_USS_FaultRLO_ADAS_USS_FaultRLO;
    ADAS_USS_FaultRLS_IDT Write_ADAS_USS_FaultRLS_ADAS_USS_FaultRLS;
    ADAS_USS_FaultRRI_IDT Write_ADAS_USS_FaultRRI_ADAS_USS_FaultRRI;
    ADAS_USS_FaultRRO_IDT Write_ADAS_USS_FaultRRO_ADAS_USS_FaultRRO;
    ADAS_USS_FaultRRS_IDT Write_ADAS_USS_FaultRRS_ADAS_USS_FaultRRS;
    APA_FrontSystemSts_IDT Write_APA_FrontSystemSts_APA_FrontSystemSts;
    APA_RearSystemSts_IDT Write_APA_RearSystemSts_APA_RearSystemSts;
    APA_WCBS_BrakeFunctionMode_IDT Write_APA_WCBS_BrakeFunctionMode_APA_WCBS_BrakeFunctionMode;
    Command Write_PiControlCommand_PiControlCommand;
    Command Write_PiLocalizationCommand_PiLocalizationCommand;
    Command Write_PiPdcCommand_PiPdcCommand;
    PerceptionCommand Write_PiPerceptionCommand_PiPerceptionCommand;
    Command Write_PiPlanningCommand_PiPlanningCommand;
    ADAS_ACC_OperatingSts_IDT Read_ADAS_ACC_OperatingSts_ADAS_ACC_OperatingSts;
    AEB_TgtDecel_Req_IDT Read_AEB_TgtDecel_Req_AEB_TgtDecel_Req;
    EPB_SysWrnIndReq_IDT Read_EPB_SysWrnIndReq_EPB_SysWrnIndReq;
    EPS_APA_CtrlAbortFeedback_IDT Read_EPS_APA_CtrlAbortFeedback_EPS_APA_CtrlAbortFeedback;
    EPS_SterFltMod_IDT Read_EPS_SterFltMod_EPS_SterFltMod;
    ESC_TcsCtrlActv_IDT Read_ESC_TcsCtrlActv_ESC_TcsCtrlActv;
    MHU_APA_ParkIn_Req_IDT Read_MHU_APA_ParkIn_Req_MHU_APA_ParkIn_Req;
    MHU_APA_ParkOut_Direction_IDT Read_MHU_APA_ParkOut_Direction_MHU_APA_ParkOut_Direction;
    MHU_APA_ParkOut_Mode_IDT Read_MHU_APA_ParkOut_Mode_MHU_APA_ParkOut_Mode;
    MHU_APA_ParkOut_Req_IDT Read_MHU_APA_ParkOut_Req_MHU_APA_ParkOut_Req;
    MHU_APA_ParkingReCover_Req_IDT Read_MHU_APA_ParkingReCover_Req_MHU_APA_ParkingReCover_Req;
    MHU_APA_ParkingStart_Req_IDT Read_MHU_APA_ParkingStart_Req_MHU_APA_ParkingStart_Req;
    MHU_APA_Req_IDT Read_MHU_APA_Req_MHU_APA_Req;
    PEPS_IGN1RelaySts_IDT Read_PEPS_IGN1RelaySts_PEPS_IGN1RelaySts;
    PEPS_PowerMode_IDT Read_PEPS_PowerMode_PEPS_PowerMode;
    APAControlState Read_PiApaControlState_PiAPAControlState;
    CarInfoH Read_PiCarInfoH_PiCarInfoH;
    CarInfoL Read_PiCarInfoL_PiCarInfoL;
    WorkingStatus Read_PiFusionStatus_PiFusionStatus;
    GlobalPoseBuffer Read_PiGlobalPoseBuffer_PiGlobalPoseBuffer;
    WorkingStatus Read_PiLocalizationWorkingStatus_PiLocalizationWorkingStatus;
    WorkingStatus Read_PiPlanningWorkingStatus_PiPlanningWorkingStatus;
    WorkingStatus Read_PiSignalTransWorkingStatus_PiSignalTransWorkingStatus;
    WorkingStatus Read_PiUssDataProWorkingStatus_P_PiUssDataProWorkingStatus;
    WorkingStatus Read_PiUssFsdWorkingStatus_PiUssFsdWorkingStatus;
    WorkingStatus Read_PiUssPdcWorkingStatus_PiUssPdcWorkingStatus;
    UssStatusSet Read_PiUssStatusSet_PiUssStatusSet;
    WorkingStatus Read_PiUssTaskWorkingStatus_PiUssTaskWorkingStatus;
    WorkingStatus Read_PiVisionStatus_PiVisionStatus;
    SAS_Calibrated_IDT Read_SAS_Calibrated_SAS_Calibrated;
    SAS_SASFailure_IDT Read_SAS_SASFailure_SAS_SASFailure;
    TPMS_SysSts_IDT Read_TPMS_SysSts_TPMS_SysSts;
    VCU_Ready_IDT Read_VCU_Ready_VCU_Ready;
    WCBS_APA_EmgyBrkAvlb_IDT Read_WCBS_APA_EmgyBrkAvlb_WCBS_APA_EmgyBrkAvlb;
    WCBS_APA_VLC_FailureStatus_IDT Read_WCBS_APA_VLC_FailureStatus_WCBS_APA_VLC_FailureStatus;
    /* TSK_State_Machine_40ms Varaible Define User Code start*/

    /* TSK_State_Machine_40ms Varaible Define User Code end*/




    Rte_Write_ADAS_APA_AbortWarning_ADAS_APA_AbortWarning(Write_ADAS_APA_AbortWarning_ADAS_APA_AbortWarning);
    /* Rte_Write_ADAS_APA_AbortWarning_ADAS_APA_AbortWarning User Code start*/

    /* Rte_Write_ADAS_APA_AbortWarning_ADAS_APA_AbortWarning User Code end*/
    Rte_Write_ADAS_APA_BrakeModeSts_ADAS_APA_BrakeModeSts(Write_ADAS_APA_BrakeModeSts_ADAS_APA_BrakeModeSts);
    /* Rte_Write_ADAS_APA_BrakeModeSts_ADAS_APA_BrakeModeSts User Code start*/

    /* Rte_Write_ADAS_APA_BrakeModeSts_ADAS_APA_BrakeModeSts User Code end*/
    Rte_Write_ADAS_APA_ModeSelect_ADAS_APA_ModeSelect(Write_ADAS_APA_ModeSelect_ADAS_APA_ModeSelect);
    /* Rte_Write_ADAS_APA_ModeSelect_ADAS_APA_ModeSelect User Code start*/

    /* Rte_Write_ADAS_APA_ModeSelect_ADAS_APA_ModeSelect User Code end*/
    Rte_Write_ADAS_APA_OperationSts_ADAS_APA_OperationSts(Write_ADAS_APA_OperationSts_ADAS_APA_OperationSts);
    /* Rte_Write_ADAS_APA_OperationSts_ADAS_APA_OperationSts User Code start*/

    /* Rte_Write_ADAS_APA_OperationSts_ADAS_APA_OperationSts User Code end*/
    Rte_Write_ADAS_APA_OtherWarning_ADAS_APA_OtherWarning(Write_ADAS_APA_OtherWarning_ADAS_APA_OtherWarning);
    /* Rte_Write_ADAS_APA_OtherWarning_ADAS_APA_OtherWarning User Code start*/

    /* Rte_Write_ADAS_APA_OtherWarning_ADAS_APA_OtherWarning User Code end*/
    Rte_Write_ADAS_APA_OverspeedAlarm_ADAS_APA_OverspeedAlarm(Write_ADAS_APA_OverspeedAlarm_ADAS_APA_OverspeedAlarm);
    /* Rte_Write_ADAS_APA_OverspeedAlarm_ADAS_APA_OverspeedAlarm User Code start*/

    /* Rte_Write_ADAS_APA_OverspeedAlarm_ADAS_APA_OverspeedAlarm User Code end*/
    Rte_Write_ADAS_APA_ParkingDirection_ADAS_APA_ParkingDirection(Write_ADAS_APA_ParkingDirection_ADAS_APA_ParkingDirection);
    /* Rte_Write_ADAS_APA_ParkingDirection_ADAS_APA_ParkingDirection User Code start*/

    /* Rte_Write_ADAS_APA_ParkingDirection_ADAS_APA_ParkingDirection User Code end*/
    Rte_Write_ADAS_APA_ParkingModeReq_ADAS_APA_ParkingModeReq(Write_ADAS_APA_ParkingModeReq_ADAS_APA_ParkingModeReq);
    /* Rte_Write_ADAS_APA_ParkingModeReq_ADAS_APA_ParkingModeReq User Code start*/

    /* Rte_Write_ADAS_APA_ParkingModeReq_ADAS_APA_ParkingModeReq User Code end*/
    Rte_Write_ADAS_APA_ParkingType_ADAS_APA_ParkingType(Write_ADAS_APA_ParkingType_ADAS_APA_ParkingType);
    /* Rte_Write_ADAS_APA_ParkingType_ADAS_APA_ParkingType User Code start*/

    /* Rte_Write_ADAS_APA_ParkingType_ADAS_APA_ParkingType User Code end*/
    Rte_Write_ADAS_APA_PauseWarning_ADAS_APA_PauseWarning(Write_ADAS_APA_PauseWarning_ADAS_APA_PauseWarning);
    /* Rte_Write_ADAS_APA_PauseWarning_ADAS_APA_PauseWarning User Code start*/

    /* Rte_Write_ADAS_APA_PauseWarning_ADAS_APA_PauseWarning User Code end*/
    Rte_Write_ADAS_APA_RemindTxt1_ADAS_APA_RemindTxt1(Write_ADAS_APA_RemindTxt1_ADAS_APA_RemindTxt1);
    /* Rte_Write_ADAS_APA_RemindTxt1_ADAS_APA_RemindTxt1 User Code start*/

    /* Rte_Write_ADAS_APA_RemindTxt1_ADAS_APA_RemindTxt1 User Code end*/
    Rte_Write_ADAS_APA_RemindTxt2_ADAS_APA_RemindTxt2(Write_ADAS_APA_RemindTxt2_ADAS_APA_RemindTxt2);
    /* Rte_Write_ADAS_APA_RemindTxt2_ADAS_APA_RemindTxt2 User Code start*/

    /* Rte_Write_ADAS_APA_RemindTxt2_ADAS_APA_RemindTxt2 User Code end*/
    Rte_Write_ADAS_APA_RenewParkingReq_ADAS_APA_RenewParkingReq(Write_ADAS_APA_RenewParkingReq_ADAS_APA_RenewParkingReq);
    /* Rte_Write_ADAS_APA_RenewParkingReq_ADAS_APA_RenewParkingReq User Code start*/

    /* Rte_Write_ADAS_APA_RenewParkingReq_ADAS_APA_RenewParkingReq User Code end*/
    Rte_Write_ADAS_APA_SearchingWarning_ADAS_APA_SearchingWarning(Write_ADAS_APA_SearchingWarning_ADAS_APA_SearchingWarning);
    /* Rte_Write_ADAS_APA_SearchingWarning_ADAS_APA_SearchingWarning User Code start*/

    /* Rte_Write_ADAS_APA_SearchingWarning_ADAS_APA_SearchingWarning User Code end*/
    Rte_Write_ADAS_APA_Soundremind_ADAS_APA_Soundremind(Write_ADAS_APA_Soundremind_ADAS_APA_Soundremind);
    /* Rte_Write_ADAS_APA_Soundremind_ADAS_APA_Soundremind User Code start*/

    /* Rte_Write_ADAS_APA_Soundremind_ADAS_APA_Soundremind User Code end*/
    Rte_Write_ADAS_APA_StartParkingReq_ADAS_APA_StartParkingReq(Write_ADAS_APA_StartParkingReq_ADAS_APA_StartParkingReq);
    /* Rte_Write_ADAS_APA_StartParkingReq_ADAS_APA_StartParkingReq User Code start*/

    /* Rte_Write_ADAS_APA_StartParkingReq_ADAS_APA_StartParkingReq User Code end*/
    Rte_Write_ADAS_APA_SystemSts_ADAS_APA_SystemSts(Write_ADAS_APA_SystemSts_ADAS_APA_SystemSts);
    /* Rte_Write_ADAS_APA_SystemSts_ADAS_APA_SystemSts User Code start*/

    /* Rte_Write_ADAS_APA_SystemSts_ADAS_APA_SystemSts User Code end*/
    Rte_Write_ADAS_USS_FaultFLI_ADAS_USS_FaultFLI(Write_ADAS_USS_FaultFLI_ADAS_USS_FaultFLI);
    /* Rte_Write_ADAS_USS_FaultFLI_ADAS_USS_FaultFLI User Code start*/

    /* Rte_Write_ADAS_USS_FaultFLI_ADAS_USS_FaultFLI User Code end*/
    Rte_Write_ADAS_USS_FaultFLO_ADAS_USS_FaultFLO(Write_ADAS_USS_FaultFLO_ADAS_USS_FaultFLO);
    /* Rte_Write_ADAS_USS_FaultFLO_ADAS_USS_FaultFLO User Code start*/

    /* Rte_Write_ADAS_USS_FaultFLO_ADAS_USS_FaultFLO User Code end*/
    Rte_Write_ADAS_USS_FaultFLS_ADAS_USS_FaultFLS(Write_ADAS_USS_FaultFLS_ADAS_USS_FaultFLS);
    /* Rte_Write_ADAS_USS_FaultFLS_ADAS_USS_FaultFLS User Code start*/

    /* Rte_Write_ADAS_USS_FaultFLS_ADAS_USS_FaultFLS User Code end*/
    Rte_Write_ADAS_USS_FaultFRI_ADAS_USS_FaultFRI(Write_ADAS_USS_FaultFRI_ADAS_USS_FaultFRI);
    /* Rte_Write_ADAS_USS_FaultFRI_ADAS_USS_FaultFRI User Code start*/

    /* Rte_Write_ADAS_USS_FaultFRI_ADAS_USS_FaultFRI User Code end*/
    Rte_Write_ADAS_USS_FaultFRO_ADAS_USS_FaultFRO(Write_ADAS_USS_FaultFRO_ADAS_USS_FaultFRO);
    /* Rte_Write_ADAS_USS_FaultFRO_ADAS_USS_FaultFRO User Code start*/

    /* Rte_Write_ADAS_USS_FaultFRO_ADAS_USS_FaultFRO User Code end*/
    Rte_Write_ADAS_USS_FaultFRS_ADAS_USS_FaultFRS(Write_ADAS_USS_FaultFRS_ADAS_USS_FaultFRS);
    /* Rte_Write_ADAS_USS_FaultFRS_ADAS_USS_FaultFRS User Code start*/

    /* Rte_Write_ADAS_USS_FaultFRS_ADAS_USS_FaultFRS User Code end*/
    Rte_Write_ADAS_USS_FaultRLI_ADAS_USS_FaultRLI(Write_ADAS_USS_FaultRLI_ADAS_USS_FaultRLI);
    /* Rte_Write_ADAS_USS_FaultRLI_ADAS_USS_FaultRLI User Code start*/

    /* Rte_Write_ADAS_USS_FaultRLI_ADAS_USS_FaultRLI User Code end*/
    Rte_Write_ADAS_USS_FaultRLO_ADAS_USS_FaultRLO(Write_ADAS_USS_FaultRLO_ADAS_USS_FaultRLO);
    /* Rte_Write_ADAS_USS_FaultRLO_ADAS_USS_FaultRLO User Code start*/

    /* Rte_Write_ADAS_USS_FaultRLO_ADAS_USS_FaultRLO User Code end*/
    Rte_Write_ADAS_USS_FaultRLS_ADAS_USS_FaultRLS(Write_ADAS_USS_FaultRLS_ADAS_USS_FaultRLS);
    /* Rte_Write_ADAS_USS_FaultRLS_ADAS_USS_FaultRLS User Code start*/

    /* Rte_Write_ADAS_USS_FaultRLS_ADAS_USS_FaultRLS User Code end*/
    Rte_Write_ADAS_USS_FaultRRI_ADAS_USS_FaultRRI(Write_ADAS_USS_FaultRRI_ADAS_USS_FaultRRI);
    /* Rte_Write_ADAS_USS_FaultRRI_ADAS_USS_FaultRRI User Code start*/

    /* Rte_Write_ADAS_USS_FaultRRI_ADAS_USS_FaultRRI User Code end*/
    Rte_Write_ADAS_USS_FaultRRO_ADAS_USS_FaultRRO(Write_ADAS_USS_FaultRRO_ADAS_USS_FaultRRO);
    /* Rte_Write_ADAS_USS_FaultRRO_ADAS_USS_FaultRRO User Code start*/

    /* Rte_Write_ADAS_USS_FaultRRO_ADAS_USS_FaultRRO User Code end*/
    Rte_Write_ADAS_USS_FaultRRS_ADAS_USS_FaultRRS(Write_ADAS_USS_FaultRRS_ADAS_USS_FaultRRS);
    /* Rte_Write_ADAS_USS_FaultRRS_ADAS_USS_FaultRRS User Code start*/

    /* Rte_Write_ADAS_USS_FaultRRS_ADAS_USS_FaultRRS User Code end*/
    Rte_Write_APA_FrontSystemSts_APA_FrontSystemSts(Write_APA_FrontSystemSts_APA_FrontSystemSts);
    /* Rte_Write_APA_FrontSystemSts_APA_FrontSystemSts User Code start*/

    /* Rte_Write_APA_FrontSystemSts_APA_FrontSystemSts User Code end*/
    Rte_Write_APA_RearSystemSts_APA_RearSystemSts(Write_APA_RearSystemSts_APA_RearSystemSts);
    /* Rte_Write_APA_RearSystemSts_APA_RearSystemSts User Code start*/

    /* Rte_Write_APA_RearSystemSts_APA_RearSystemSts User Code end*/
    Rte_Write_APA_WCBS_BrakeFunctionMode_APA_WCBS_BrakeFunctionMode(Write_APA_WCBS_BrakeFunctionMode_APA_WCBS_BrakeFunctionMode);
    /* Rte_Write_APA_WCBS_BrakeFunctionMode_APA_WCBS_BrakeFunctionMode User Code start*/

    /* Rte_Write_APA_WCBS_BrakeFunctionMode_APA_WCBS_BrakeFunctionMode User Code end*/
    Rte_Write_PiControlCommand_PiControlCommand(&Write_PiControlCommand_PiControlCommand);
    /* Rte_Write_PiControlCommand_PiControlCommand User Code start*/

    /* Rte_Write_PiControlCommand_PiControlCommand User Code end*/
    Rte_Write_PiLocalizationCommand_PiLocalizationCommand(&Write_PiLocalizationCommand_PiLocalizationCommand);
    /* Rte_Write_PiLocalizationCommand_PiLocalizationCommand User Code start*/

    /* Rte_Write_PiLocalizationCommand_PiLocalizationCommand User Code end*/
    Rte_Write_PiPdcCommand_PiPdcCommand(&Write_PiPdcCommand_PiPdcCommand);
    /* Rte_Write_PiPdcCommand_PiPdcCommand User Code start*/

    /* Rte_Write_PiPdcCommand_PiPdcCommand User Code end*/
    Rte_Write_PiPerceptionCommand_PiPerceptionCommand(&Write_PiPerceptionCommand_PiPerceptionCommand);
    /* Rte_Write_PiPerceptionCommand_PiPerceptionCommand User Code start*/

    /* Rte_Write_PiPerceptionCommand_PiPerceptionCommand User Code end*/
    Rte_Write_PiPlanningCommand_PiPlanningCommand(&Write_PiPlanningCommand_PiPlanningCommand);
    /* Rte_Write_PiPlanningCommand_PiPlanningCommand User Code start*/

    /* Rte_Write_PiPlanningCommand_PiPlanningCommand User Code end*/
    Rte_Read_ADAS_ACC_OperatingSts_ADAS_ACC_OperatingSts(&Read_ADAS_ACC_OperatingSts_ADAS_ACC_OperatingSts);
    /* Rte_Read_ADAS_ACC_OperatingSts_ADAS_ACC_OperatingSts User Code start*/

    /* Rte_Read_ADAS_ACC_OperatingSts_ADAS_ACC_OperatingSts User Code end*/
    Rte_Read_AEB_TgtDecel_Req_AEB_TgtDecel_Req(&Read_AEB_TgtDecel_Req_AEB_TgtDecel_Req);
    /* Rte_Read_AEB_TgtDecel_Req_AEB_TgtDecel_Req User Code start*/

    /* Rte_Read_AEB_TgtDecel_Req_AEB_TgtDecel_Req User Code end*/
    Rte_Read_EPB_SysWrnIndReq_EPB_SysWrnIndReq(&Read_EPB_SysWrnIndReq_EPB_SysWrnIndReq);
    /* Rte_Read_EPB_SysWrnIndReq_EPB_SysWrnIndReq User Code start*/

    /* Rte_Read_EPB_SysWrnIndReq_EPB_SysWrnIndReq User Code end*/
    Rte_Read_EPS_APA_CtrlAbortFeedback_EPS_APA_CtrlAbortFeedback(&Read_EPS_APA_CtrlAbortFeedback_EPS_APA_CtrlAbortFeedback);
    /* Rte_Read_EPS_APA_CtrlAbortFeedback_EPS_APA_CtrlAbortFeedback User Code start*/

    /* Rte_Read_EPS_APA_CtrlAbortFeedback_EPS_APA_CtrlAbortFeedback User Code end*/
    Rte_Read_EPS_SterFltMod_EPS_SterFltMod(&Read_EPS_SterFltMod_EPS_SterFltMod);
    /* Rte_Read_EPS_SterFltMod_EPS_SterFltMod User Code start*/

    /* Rte_Read_EPS_SterFltMod_EPS_SterFltMod User Code end*/
    Rte_Read_ESC_TcsCtrlActv_ESC_TcsCtrlActv(&Read_ESC_TcsCtrlActv_ESC_TcsCtrlActv);
    /* Rte_Read_ESC_TcsCtrlActv_ESC_TcsCtrlActv User Code start*/

    /* Rte_Read_ESC_TcsCtrlActv_ESC_TcsCtrlActv User Code end*/
    Rte_Read_MHU_APA_ParkIn_Req_MHU_APA_ParkIn_Req(&Read_MHU_APA_ParkIn_Req_MHU_APA_ParkIn_Req);
    /* Rte_Read_MHU_APA_ParkIn_Req_MHU_APA_ParkIn_Req User Code start*/

    /* Rte_Read_MHU_APA_ParkIn_Req_MHU_APA_ParkIn_Req User Code end*/
    Rte_Read_MHU_APA_ParkOut_Direction_MHU_APA_ParkOut_Direction(&Read_MHU_APA_ParkOut_Direction_MHU_APA_ParkOut_Direction);
    /* Rte_Read_MHU_APA_ParkOut_Direction_MHU_APA_ParkOut_Direction User Code start*/

    /* Rte_Read_MHU_APA_ParkOut_Direction_MHU_APA_ParkOut_Direction User Code end*/
    Rte_Read_MHU_APA_ParkOut_Mode_MHU_APA_ParkOut_Mode(&Read_MHU_APA_ParkOut_Mode_MHU_APA_ParkOut_Mode);
    /* Rte_Read_MHU_APA_ParkOut_Mode_MHU_APA_ParkOut_Mode User Code start*/

    /* Rte_Read_MHU_APA_ParkOut_Mode_MHU_APA_ParkOut_Mode User Code end*/
    Rte_Read_MHU_APA_ParkOut_Req_MHU_APA_ParkOut_Req(&Read_MHU_APA_ParkOut_Req_MHU_APA_ParkOut_Req);
    /* Rte_Read_MHU_APA_ParkOut_Req_MHU_APA_ParkOut_Req User Code start*/

    /* Rte_Read_MHU_APA_ParkOut_Req_MHU_APA_ParkOut_Req User Code end*/
    Rte_Read_MHU_APA_ParkingReCover_Req_MHU_APA_ParkingReCover_Req(&Read_MHU_APA_ParkingReCover_Req_MHU_APA_ParkingReCover_Req);
    /* Rte_Read_MHU_APA_ParkingReCover_Req_MHU_APA_ParkingReCover_Req User Code start*/

    /* Rte_Read_MHU_APA_ParkingReCover_Req_MHU_APA_ParkingReCover_Req User Code end*/
    Rte_Read_MHU_APA_ParkingStart_Req_MHU_APA_ParkingStart_Req(&Read_MHU_APA_ParkingStart_Req_MHU_APA_ParkingStart_Req);
    /* Rte_Read_MHU_APA_ParkingStart_Req_MHU_APA_ParkingStart_Req User Code start*/

    /* Rte_Read_MHU_APA_ParkingStart_Req_MHU_APA_ParkingStart_Req User Code end*/
    Rte_Read_MHU_APA_Req_MHU_APA_Req(&Read_MHU_APA_Req_MHU_APA_Req);
    /* Rte_Read_MHU_APA_Req_MHU_APA_Req User Code start*/

    /* Rte_Read_MHU_APA_Req_MHU_APA_Req User Code end*/
    Rte_Read_PEPS_IGN1RelaySts_PEPS_IGN1RelaySts(&Read_PEPS_IGN1RelaySts_PEPS_IGN1RelaySts);
    /* Rte_Read_PEPS_IGN1RelaySts_PEPS_IGN1RelaySts User Code start*/

    /* Rte_Read_PEPS_IGN1RelaySts_PEPS_IGN1RelaySts User Code end*/
    Rte_Read_PEPS_PowerMode_PEPS_PowerMode(&Read_PEPS_PowerMode_PEPS_PowerMode);
    /* Rte_Read_PEPS_PowerMode_PEPS_PowerMode User Code start*/

    /* Rte_Read_PEPS_PowerMode_PEPS_PowerMode User Code end*/
    Rte_Read_PiApaControlState_PiAPAControlState(&Read_PiApaControlState_PiAPAControlState);
    /* Rte_Read_PiApaControlState_PiAPAControlState User Code start*/

    /* Rte_Read_PiApaControlState_PiAPAControlState User Code end*/
    Rte_Read_PiCarInfoH_PiCarInfoH(&Read_PiCarInfoH_PiCarInfoH);
    /* Rte_Read_PiCarInfoH_PiCarInfoH User Code start*/

    /* Rte_Read_PiCarInfoH_PiCarInfoH User Code end*/
    Rte_Read_PiCarInfoL_PiCarInfoL(&Read_PiCarInfoL_PiCarInfoL);
    /* Rte_Read_PiCarInfoL_PiCarInfoL User Code start*/

    /* Rte_Read_PiCarInfoL_PiCarInfoL User Code end*/
    Rte_Read_PiFusionStatus_PiFusionStatus(&Read_PiFusionStatus_PiFusionStatus);
    /* Rte_Read_PiFusionStatus_PiFusionStatus User Code start*/

    /* Rte_Read_PiFusionStatus_PiFusionStatus User Code end*/
    Rte_Read_PiGlobalPoseBuffer_PiGlobalPoseBuffer(&Read_PiGlobalPoseBuffer_PiGlobalPoseBuffer);
    /* Rte_Read_PiGlobalPoseBuffer_PiGlobalPoseBuffer User Code start*/

    /* Rte_Read_PiGlobalPoseBuffer_PiGlobalPoseBuffer User Code end*/
    Rte_Read_PiLocalizationWorkingStatus_PiLocalizationWorkingStatus(&Read_PiLocalizationWorkingStatus_PiLocalizationWorkingStatus);
    /* Rte_Read_PiLocalizationWorkingStatus_PiLocalizationWorkingStatus User Code start*/

    /* Rte_Read_PiLocalizationWorkingStatus_PiLocalizationWorkingStatus User Code end*/
    Rte_Read_PiPlanningWorkingStatus_PiPlanningWorkingStatus(&Read_PiPlanningWorkingStatus_PiPlanningWorkingStatus);
    /* Rte_Read_PiPlanningWorkingStatus_PiPlanningWorkingStatus User Code start*/

    /* Rte_Read_PiPlanningWorkingStatus_PiPlanningWorkingStatus User Code end*/
    Rte_Read_PiSignalTransWorkingStatus_PiSignalTransWorkingStatus(&Read_PiSignalTransWorkingStatus_PiSignalTransWorkingStatus);
    /* Rte_Read_PiSignalTransWorkingStatus_PiSignalTransWorkingStatus User Code start*/

    /* Rte_Read_PiSignalTransWorkingStatus_PiSignalTransWorkingStatus User Code end*/
    Rte_Read_PiUssDataProWorkingStatus_P_PiUssDataProWorkingStatus(&Read_PiUssDataProWorkingStatus_P_PiUssDataProWorkingStatus);
    /* Rte_Read_PiUssDataProWorkingStatus_P_PiUssDataProWorkingStatus User Code start*/

    /* Rte_Read_PiUssDataProWorkingStatus_P_PiUssDataProWorkingStatus User Code end*/
    Rte_Read_PiUssFsdWorkingStatus_PiUssFsdWorkingStatus(&Read_PiUssFsdWorkingStatus_PiUssFsdWorkingStatus);
    /* Rte_Read_PiUssFsdWorkingStatus_PiUssFsdWorkingStatus User Code start*/

    /* Rte_Read_PiUssFsdWorkingStatus_PiUssFsdWorkingStatus User Code end*/
    Rte_Read_PiUssPdcWorkingStatus_PiUssPdcWorkingStatus(&Read_PiUssPdcWorkingStatus_PiUssPdcWorkingStatus);
    /* Rte_Read_PiUssPdcWorkingStatus_PiUssPdcWorkingStatus User Code start*/

    /* Rte_Read_PiUssPdcWorkingStatus_PiUssPdcWorkingStatus User Code end*/
    Rte_Read_PiUssStatusSet_PiUssStatusSet(&Read_PiUssStatusSet_PiUssStatusSet);
    /* Rte_Read_PiUssStatusSet_PiUssStatusSet User Code start*/

    /* Rte_Read_PiUssStatusSet_PiUssStatusSet User Code end*/
    Rte_Read_PiUssTaskWorkingStatus_PiUssTaskWorkingStatus(&Read_PiUssTaskWorkingStatus_PiUssTaskWorkingStatus);
    /* Rte_Read_PiUssTaskWorkingStatus_PiUssTaskWorkingStatus User Code start*/

    /* Rte_Read_PiUssTaskWorkingStatus_PiUssTaskWorkingStatus User Code end*/
    Rte_Read_PiVisionStatus_PiVisionStatus(&Read_PiVisionStatus_PiVisionStatus);
    /* Rte_Read_PiVisionStatus_PiVisionStatus User Code start*/

    /* Rte_Read_PiVisionStatus_PiVisionStatus User Code end*/
    Rte_Read_SAS_Calibrated_SAS_Calibrated(&Read_SAS_Calibrated_SAS_Calibrated);
    /* Rte_Read_SAS_Calibrated_SAS_Calibrated User Code start*/

    /* Rte_Read_SAS_Calibrated_SAS_Calibrated User Code end*/
    Rte_Read_SAS_SASFailure_SAS_SASFailure(&Read_SAS_SASFailure_SAS_SASFailure);
    /* Rte_Read_SAS_SASFailure_SAS_SASFailure User Code start*/

    /* Rte_Read_SAS_SASFailure_SAS_SASFailure User Code end*/
    Rte_Read_TPMS_SysSts_TPMS_SysSts(&Read_TPMS_SysSts_TPMS_SysSts);
    /* Rte_Read_TPMS_SysSts_TPMS_SysSts User Code start*/

    /* Rte_Read_TPMS_SysSts_TPMS_SysSts User Code end*/
    Rte_Read_VCU_Ready_VCU_Ready(&Read_VCU_Ready_VCU_Ready);
    /* Rte_Read_VCU_Ready_VCU_Ready User Code start*/

    /* Rte_Read_VCU_Ready_VCU_Ready User Code end*/
    Rte_Read_WCBS_APA_EmgyBrkAvlb_WCBS_APA_EmgyBrkAvlb(&Read_WCBS_APA_EmgyBrkAvlb_WCBS_APA_EmgyBrkAvlb);
    /* Rte_Read_WCBS_APA_EmgyBrkAvlb_WCBS_APA_EmgyBrkAvlb User Code start*/

    /* Rte_Read_WCBS_APA_EmgyBrkAvlb_WCBS_APA_EmgyBrkAvlb User Code end*/
    Rte_Read_WCBS_APA_VLC_FailureStatus_WCBS_APA_VLC_FailureStatus(&Read_WCBS_APA_VLC_FailureStatus_WCBS_APA_VLC_FailureStatus);
    /* Rte_Read_WCBS_APA_VLC_FailureStatus_WCBS_APA_VLC_FailureStatus User Code start*/

    /* Rte_Read_WCBS_APA_VLC_FailureStatus_WCBS_APA_VLC_FailureStatus User Code end*/
    /* TSK_State_Machine_40ms_Feedback User Code start*/

    /* TSK_State_Machine_40ms_Feedback User Code end*/

}
#define CtApState_Machine_STOP_SEC_CODE
#include "CtApState_Machine_MemMap.h"




