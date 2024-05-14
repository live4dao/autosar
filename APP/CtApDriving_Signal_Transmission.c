/*  BEGIN_FILE_HDR
********************************************************************************
*   File Name       : CtApDriving_Signal_Transmission.c
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
#include "Rte_CtApDriving_Signal_Transmission.h"

/* CtApDriving_Signal_TransmissionInput File User Code start*/

/* CtApDriving_Signal_TransmissionInput File User Code end*/

/* CtApDriving_Signal_Transmission.c Custom Code (#define variable etc.) User Code start*/

/* CtApDriving_Signal_Transmission.c Custom Code (#define variable etc.) User Code end*/

/*******************************************************************************
*   Runnable Extended
*******************************************************************************/

#define CtApDriving_Signal_Transmission_START_SEC_CODE
#include "CtApDriving_Signal_Transmission_MemMap.h"

FUNC(void, CtApDriving_Signal_Transmission_CODE) Driving_Signal_Transmission_Init
(
    void
)
{
    /* Driving_Signal_Transmission_Init_Start User Code start*/

    /* Driving_Signal_Transmission_Init_Start User Code end*/
    /* Driving_Signal_Transmission_Init Varaible Define User Code start*/

    /* Driving_Signal_Transmission_Init Varaible Define User Code end*/




    /* Driving_Signal_Transmission_Init_Feedback User Code start*/

    /* Driving_Signal_Transmission_Init_Feedback User Code end*/

}
#define CtApDriving_Signal_Transmission_STOP_SEC_CODE
#include "CtApDriving_Signal_Transmission_MemMap.h"


#define CtApDriving_Signal_Transmission_START_SEC_CODE
#include "CtApDriving_Signal_Transmission_MemMap.h"

FUNC(void, CtApDriving_Signal_Transmission_CODE) Task_Driving_Signal_Transmission_10ms
(
    void
)
{
    /* Task_Driving_Signal_Transmission_10ms_Start User Code start*/

    /* Task_Driving_Signal_Transmission_10ms_Start User Code end*/
    ACC_AdtLowerJerkLimit_IDT Write_ACC_AdtLowerJerkLimit_ACC_AdtLowerJerkLimit;
    ACC_AdtUpperJerkLimit_IDT Write_ACC_AdtUpperJerkLimit_ACC_AdtUpperJerkLimit;
    ACC_DriveoffReq_IDT Write_ACC_DriveoffReq_ACC_DriveoffReq;
    ACC_TxtInfoForDriver_IDT Write_ACC_TxtInfoForDriver_ACC_TxtInfoForDriver;
    ADAS_ACC_BrakePreferred_IDT Write_ADAS_ACC_BrakePreferred_ADAS_ACC_BrakePreferred;
    ADAS_ACC_DistanceLevel_IDT Write_ADAS_ACC_DistanceLevel_ADAS_ACC_DistanceLevel;
    ADAS_ACC_ObjDispSts_IDT Write_ADAS_ACC_ObjDispSts_ADAS_ACC_ObjDispSts;
    ADAS_ACC_OperatingSts_IDT Write_ADAS_ACC_OperatingSts_ADAS_ACC_OperatingSts;
    ADAS_ACC_SpdUnit_IDT Write_ADAS_ACC_SpdUnit_ADAS_ACC_SpdUnit;
    ADAS_ACC_TakeOverReq_IDT Write_ADAS_ACC_TakeOverReq_ADAS_ACC_TakeOverReq;
    ADAS_ACC_TargetSpeed_IDT Write_ADAS_ACC_TargetSpeed_ADAS_ACC_TargetSpeed;
    ADAS_ACC_TimeGapLevel_IDT Write_ADAS_ACC_TimeGapLevel_ADAS_ACC_TimeGapLevel;
    ADAS_AEB_AbaLevel_IDT Write_ADAS_AEB_AbaLevel_ADAS_AEB_AbaLevel;
    ADAS_AEB_AbpReq_IDT Write_ADAS_AEB_AbpReq_ADAS_AEB_AbpReq;
    ADAS_AEB_FuncSWResp_IDT Write_ADAS_AEB_FuncSWResp_ADAS_AEB_FuncSWResp;
    ADAS_AEB_TgtDecel_ReqValue_IDT Write_ADAS_AEB_TgtDecel_ReqValue_ADAS_AEB_TgtDecel_ReqValue;
    ADAS_AccelerationReq_IDT Write_ADAS_AccelerationReq_ADAS_AccelerationReq;
    ADAS_EPS_AngReqSts_IDT Write_ADAS_EPS_AngReqSts_ADAS_EPS_AngReqSts;
    ADAS_EPS_TargetSteeringAngle_IDT Write_ADAS_EPS_TargetSteeringAngle_ADAS_EPS_TargetSteeringAngle;
    ADAS_EPS_Vibration_Req_IDT Write_ADAS_EPS_Vibration_Req_ADAS_EPS_Vibration_Req;
    ADAS_IBS_CarStarting_IDT Write_ADAS_IBS_CarStarting_ADAS_IBS_CarStarting;
    ADAS_IBS_EBAReq_IDT Write_ADAS_IBS_EBAReq_ADAS_IBS_EBAReq;
    ADAS_IBS_MinBreakReq_IDT Write_ADAS_IBS_MinBreakReq_ADAS_IBS_MinBreakReq;
    ADAS_IBS_StopReq_IDT Write_ADAS_IBS_StopReq_ADAS_IBS_StopReq;
    ADAS_LSS_AngCmdReqPortnValue_IDT Write_ADAS_LSS_AngCmdReqPortnValue_ADAS_LSS_AngCmdReqPortnValue;
    ADAS_LSS_AssidFormResp_IDT Write_ADAS_LSS_AssidFormResp_ADAS_LSS_AssidFormResp;
    ADAS_LSS_Available_IDT Write_ADAS_LSS_Available_ADAS_LSS_Available;
    ADAS_LSS_ErrSts_IDT Write_ADAS_LSS_ErrSts_ADAS_LSS_ErrSts;
    ADAS_LSS_FunSts_IDT Write_ADAS_LSS_FunSts_ADAS_LSS_FunSts;
    ADAS_LSS_FuncResp_IDT Write_ADAS_LSS_FuncResp_ADAS_LSS_FuncResp;
    ADAS_LSS_HandsoffWarn_IDT Write_ADAS_LSS_HandsoffWarn_ADAS_LSS_HandsoffWarn;
    ADAS_LSS_LeLineTrackingSts_IDT Write_ADAS_LSS_LeLineTrackingSts_ADAS_LSS_LeLineTrackingSts;
    ADAS_LSS_RiLineTrackingSts_IDT Write_ADAS_LSS_RiLineTrackingSts_ADAS_LSS_RiLineTrackingSts;
    ADAS_LSS_VoiceWarn_IDT Write_ADAS_LSS_VoiceWarn_ADAS_LSS_VoiceWarn;
    ADAS_LSS_WarnFromResp_IDT Write_ADAS_LSS_WarnFromResp_ADAS_LSS_WarnFromResp;
    ADAS_MaxSoftAcceleration_IDT Write_ADAS_MaxSoftAcceleration_ADAS_MaxSoftAcceleration;
    ADAS_MinSoftAcceleration_IDT Write_ADAS_MinSoftAcceleration_ADAS_MinSoftAcceleration;
    ADAS_TSR_OperationSts_IDT Write_ADAS_TSR_OperationSts_ADAS_TSR_OperationSts;
    ADAS_TSR_SWSts_IDT Write_ADAS_TSR_SWSts_ADAS_TSR_SWSts;
    ADAS_TSR_SpeedLimit_IDT Write_ADAS_TSR_SpeedLimit_ADAS_TSR_SpeedLimit;
    ADAS_VLCModeReq_IDT Write_ADAS_VLCModeReq_ADAS_VLCModeReq;
    ADAS_VLCShutDownReq_IDT Write_ADAS_VLCShutDownReq_ADAS_VLCShutDownReq;
    AEB_ABA_Req_IDT Write_AEB_ABA_Req_AEB_ABA_Req;
    AEB_AWB_Level_IDT Write_AEB_AWB_Level_AEB_AWB_Level;
    AEB_AWB_Req_IDT Write_AEB_AWB_Req_AEB_AWB_Req;
    AEB_ErrorSts_IDT Write_AEB_ErrorSts_AEB_ErrorSts;
    AEB_FCW_Warning_IDT Write_AEB_FCW_Warning_AEB_FCW_Warning;
    AEB_FuncSts_IDT Write_AEB_FuncSts_AEB_FuncSts;
    AEB_TgtDecel_Req_IDT Write_AEB_TgtDecel_Req_AEB_TgtDecel_Req;
    AEB_VRUActive_IDT Write_AEB_VRUActive_AEB_VRUActive;
    AEB_VehActive_IDT Write_AEB_VehActive_AEB_VehActive;
    AEB_VehHldReq_IDT Write_AEB_VehHldReq_AEB_VehHldReq;
    AEB_FCW_SnvtyResp_IDT Write_AEB_FCW_SnvtyResp_AEB_FCW_SnvtyResp;
    FC_BlockageSts_IDT Write_FC_BlockageSts_FC_BlockageSts;
    FC_CalibrationSts_IDT Write_FC_CalibrationSts_FC_CalibrationSts;
    FrontRadarInfo Write_PiFrontRadarInfo_PiFrontRadarInfo;
    TSR_SLWSwtResp_IDT Write_TSR_SLWSwtResp_TSR_SLWSwtResp;
    TSR_SLWVisualWarn_IDT Write_TSR_SLWVisualWarn_TSR_SLWVisualWarn;
    TSR_SLWVoiceWarn_IDT Write_TSR_SLWVoiceWarn_TSR_SLWVoiceWarn;
    TSR_SpdAssistInfoDisp_IDT Write_TSR_SpdAssistInfoDisp_TSR_SpdAssistInfoDisp;
    TSR_TrafSign_IDT Write_TSR_TrafSign_TSR_TrafSign;
    TSR_Warning_offset_IDT Write_TSR_Warning_offset_TSR_Warning_offset;
    VehicleInfo Write_PiVehicleInfo_PiVehicleInfo;
    ABSActive_IDT Read_ABSActive_ABSActive;
    ABS_FLWheelDirection_IDT Read_ABS_FLWheelDirection_ABS_FLWheelDirection;
    ABS_FLWheelSpeedInvalid_IDT Read_ABS_FLWheelSpeedInvalid_ABS_FLWheelSpeedInvalid;
    ABS_FLWheelSpeedKPH_IDT Read_ABS_FLWheelSpeedKPH_ABS_FLWheelSpeedKPH;
    ABS_FRWheelDirection_IDT Read_ABS_FRWheelDirection_ABS_FRWheelDirection;
    ABS_FRWheelSpeedInvalid_IDT Read_ABS_FRWheelSpeedInvalid_ABS_FRWheelSpeedInvalid;
    ABS_FRWheelSpeedKPH_IDT Read_ABS_FRWheelSpeedKPH_ABS_FRWheelSpeedKPH;
    ABS_RLWheelDirection_IDT Read_ABS_RLWheelDirection_ABS_RLWheelDirection;
    ABS_RLWheelSpeedInvalid_IDT Read_ABS_RLWheelSpeedInvalid_ABS_RLWheelSpeedInvalid;
    ABS_RLWheelSpeedKPH_IDT Read_ABS_RLWheelSpeedKPH_ABS_RLWheelSpeedKPH;
    ABS_RRWheelDirection_IDT Read_ABS_RRWheelDirection_ABS_RRWheelDirection;
    ABS_RRWheelSpeedInvalid_IDT Read_ABS_RRWheelSpeedInvalid_ABS_RRWheelSpeedInvalid;
    ABS_RRWheelSpeedKPH_IDT Read_ABS_RRWheelSpeedKPH_ABS_RRWheelSpeedKPH;
    ABS_VehicleSpeedInvalid_IDT Read_ABS_VehicleSpeedInvalid_ABS_VehicleSpeedInvalid;
    ABS_VehicleSpeed_IDT Read_ABS_VehicleSpeed_ABS_VehicleSpeed;
    AB_BrkPedalPct_IDT Read_AB_BrkPedalPct_AB_BrkPedalPct;
    AB_BrkPedalSwStsV_IDT Read_AB_BrkPedalSwStsV_AB_BrkPedalSwStsV;
    AB_BrkPedalSwSts_IDT Read_AB_BrkPedalSwSts_AB_BrkPedalSwSts;
    AB_BrkPedalTravel_IDT Read_AB_BrkPedalTravel_AB_BrkPedalTravel;
    AB_Fault_Status_IDT Read_AB_Fault_Status_AB_Fault_Status;
    ACU_CoDSeatbeltBucklestatus_IDT Read_ACU_CoDSeatbeltBucklestatus_ACU_CoDSeatbeltBucklestatus;
    ACU_DSeatbeltBucklestatus_IDT Read_ACU_DSeatbeltBucklestatus_ACU_DSeatbeltBucklestatus;
    ADAS_APA_SystemSts_IDT Read_ADAS_APA_SystemSts_ADAS_APA_SystemSts;
    AEB_FCW_SnvtyReq_IDT Read_AEB_FCW_SnvtyReq_AEB_FCW_SnvtyReq;
    AEB_FuncSwtReq_IDT Read_AEB_FuncSwtReq_AEB_FuncSwtReq;
    ADAS_APA_OperationSts_IDT Read_ADAS_APA_OperationSts_ADAS_APA_OperationSts;
    BCM_AutoWipeSts_IDT Read_BCM_AutoWipeSts_BCM_AutoWipeSts;
    BCM_CodriversSideDoorAjarSts_IDT Read_BCM_CodriversSideDoorAjarSts_BCM_CodriversSideDoorAjarSts;
    BCM_CoverAjarStatus_IDT Read_BCM_CoverAjarStatus_BCM_CoverAjarStatus;
    BCM_DoorLockStatusCodrivres_IDT Read_BCM_DoorLockStatusCodrivres_BCM_DoorLockStatusCodrivres;
    BCM_DoorLockStatusDrv_IDT Read_BCM_DoorLockStatusDrv_BCM_DoorLockStatusDrv;
    BCM_DoorLockStatusRL_IDT Read_BCM_DoorLockStatusRL_BCM_DoorLockStatusRL;
    BCM_DoorLockStatusRR_IDT Read_BCM_DoorLockStatusRR_BCM_DoorLockStatusRR;
    BCM_DriverSideDoorAjarSts_IDT Read_BCM_DriverSideDoorAjarSts_BCM_DriverSideDoorAjarSts;
    BCM_FrontFogLampLightSts_IDT Read_BCM_FrontFogLampLightSts_BCM_FrontFogLampLightSts;
    BCM_FrontWipeSWSts_IDT Read_BCM_FrontWipeSWSts_BCM_FrontWipeSWSts;
    BCM_FrontWipeSts_IDT Read_BCM_FrontWipeSts_BCM_FrontWipeSts;
    BCM_RearLeftDoorAjarStatus_IDT Read_BCM_RearLeftDoorAjarStatus_BCM_RearLeftDoorAjarStatus;
    BCM_RearRightDoorAjarStatus_IDT Read_BCM_RearRightDoorAjarStatus_BCM_RearRightDoorAjarStatus;
    BCM_TrunckAjarStatus_IDT Read_BCM_TrunckAjarStatus_BCM_TrunckAjarStatus;
    BCM_TurnIndicatorSts_IDT Read_BCM_TurnIndicatorSts_BCM_TurnIndicatorSts;
    BCM_TurnLightSWSts_IDT Read_BCM_TurnLightSWSts_BCM_TurnLightSWSts;
    BCM_TurnLight_FaultSts_IDT Read_BCM_TurnLight_FaultSts_BCM_TurnLight_FaultSts;
    BSD_LCA_FuncSWReq_IDT Read_BSD_LCA_FuncSWReq_BSD_LCA_FuncSWReq;
    CCU_ExternalTemperature_IDT Read_CCU_ExternalTemperature_CCU_ExternalTemperature;
    ESC_TcsDisableSts_IDT Read_ESC_TcsDisableSts_ESC_TcsDisableSts;
    DOW_FuncSWReq_IDT Read_DOW_FuncSWReq_DOW_FuncSWReq;
    EPB_AVHFeedbackSts_IDT Read_EPB_AVHFeedbackSts_EPB_AVHFeedbackSts;
    EPB_AVHStatIndReqV_IDT Read_EPB_AVHStatIndReqV_EPB_AVHStatIndReqV;
    EPS_ADAS_CtrlAbortFeedback_IDT Read_EPS_ADAS_CtrlAbortFeedback_EPS_ADAS_CtrlAbortFeedback;
    EPS_ADAS_ModActv_IDT Read_EPS_ADAS_ModActv_EPS_ADAS_ModActv;
    EPS_ADAS_ModAvail_IDT Read_EPS_ADAS_ModAvail_EPS_ADAS_ModAvail;
    EPS_DrStrTorqV_IDT Read_EPS_DrStrTorqV_EPS_DrStrTorqV;
    EPS_DrStrTorqVal_IDT Read_EPS_DrStrTorqVal_EPS_DrStrTorqVal;
    EPS_LKARespTorq_IDT Read_EPS_LKARespTorq_EPS_LKARespTorq;
    EPS_SterFltMod_IDT Read_EPS_SterFltMod_EPS_SterFltMod;
    ESC_EscCtrlActv_IDT Read_ESC_EscCtrlActv_ESC_EscCtrlActv;
    ESC_EscDisableSts_IDT Read_ESC_EscDisableSts_ESC_EscDisableSts;
    ESC_HSA_Control_Status_IDT Read_ESC_HSA_Control_Status_ESC_HSA_Control_Status;
    ESC_LateralACC_IDT Read_ESC_LateralACC_ESC_LateralACC;
    ESC_LateralACC_Valid_IDT Read_ESC_LateralACC_Valid_ESC_LateralACC_Valid;
    ESC_LongitudeACC_IDT Read_ESC_LongitudeACC_ESC_LongitudeACC;
    ESC_LongitudeACC_Valid_IDT Read_ESC_LongitudeACC_Valid_ESC_LongitudeACC_Valid;
    ESC_MasterCylinderPressureV_IDT Read_ESC_MasterCylinderPressureV_ESC_MasterCylinderPressureV;
    ESC_MasterCylinderPressure_IDT Read_ESC_MasterCylinderPressure_ESC_MasterCylinderPressure;
    ESC_TcsCtrlActv_IDT Read_ESC_TcsCtrlActv_ESC_TcsCtrlActv;
    ESC_VehDynYawRate_IDT Read_ESC_VehDynYawRate_ESC_VehDynYawRate;
    ESC_VehDynYawRate_Valid_IDT Read_ESC_VehDynYawRate_Valid_ESC_VehDynYawRate_Valid;
    GPSSystAtv_IDT Read_GPSSystAtv_GPSSystAtv;
    IBS_ESCOFF_StsFB_IDT Read_IBS_ESCOFF_StsFB_IBS_ESCOFF_StsFB;
    IPC_IPCTotalOdometerV_IDT Read_IPC_IPCTotalOdometerV_IPC_IPCTotalOdometerV;
    IPC_IPCTotalOdometer_IDT Read_IPC_IPCTotalOdometer_IPC_IPCTotalOdometer;
    MFS_ACC_CruiseCancel_IDT Read_MFS_ACC_CruiseCancel_MFS_ACC_CruiseCancel;
    MFS_ACC_CruiseGapSet_IDT Read_MFS_ACC_CruiseGapSet_MFS_ACC_CruiseGapSet;
    MFS_ACC_CruiseOn_Off_IDT Read_MFS_ACC_CruiseOn_Off_MFS_ACC_CruiseOn_Off;
    MFS_ACC_CruiseSpdDecrease_IDT Read_MFS_ACC_CruiseSpdDecrease_MFS_ACC_CruiseSpdDecrease;
    MFS_ACC_CruiseSpdIncrease_IDT Read_MFS_ACC_CruiseSpdIncrease_MFS_ACC_CruiseSpdIncrease;
    MHU_DM_SwitchModeSts_IDT Read_MHU_DM_SwitchModeSts_MHU_DM_SwitchModeSts;
    MHU_LSS_Mode_IDT Read_MHU_LSS_Mode_MHU_LSS_Mode;
    MHU_LSS_Req_IDT Read_MHU_LSS_Req_MHU_LSS_Req;
    MHU_LSS_WarningMethod_IDT Read_MHU_LSS_WarningMethod_MHU_LSS_WarningMethod;
    MHU_TSR_Req_IDT Read_MHU_TSR_Req_MHU_TSR_Req;
    MHU_Trailermode_Req_IDT Read_MHU_Trailermode_Req_MHU_Trailermode_Req;
    Nav_CtryType_IDT Read_Nav_CtryType_Nav_CtryType;
    Nav_RoadType_IDT Read_Nav_RoadType_Nav_RoadType;
    Nav_SpdLimType_IDT Read_Nav_SpdLimType_Nav_SpdLimType;
    Nav_SpdLimUnit_IDT Read_Nav_SpdLimUnit_Nav_SpdLimUnit;
    Nav_SpdLimValue_IDT Read_Nav_SpdLimValue_Nav_SpdLimValue;
    Nav_TSRTrafSign_IDT Read_Nav_TSRTrafSign_Nav_TSRTrafSign;
    Nav_VehToTrafEyeDist_IDT Read_Nav_VehToTrafEyeDist_Nav_VehToTrafEyeDist;
    Nav_errorSts_IDT Read_Nav_errorSts_Nav_errorSts;
    PEPS_PowerModeValidity_IDT Read_PEPS_PowerModeValidity_PEPS_PowerModeValidity;
    PEPS_PowerMode_IDT Read_PEPS_PowerMode_PEPS_PowerMode;
    ADAS_CAN_Output Read_PiADAS_CAN_Output_ADAS_CAN_Output;
    RCTA_FuncSWReq_IDT Read_RCTA_FuncSWReq_RCTA_FuncSWReq;
    RCW_FuncSWReq_IDT Read_RCW_FuncSWReq_RCW_FuncSWReq;
    RLS_Rainfall_magnitude_IDT Read_RLS_Rainfall_magnitude_RLS_Rainfall_magnitude;
    SAS_Calibrated_IDT Read_SAS_Calibrated_SAS_Calibrated;
    SAS_SASFailure_IDT Read_SAS_SASFailure_SAS_SASFailure;
    SAS_SteerWheelAngle_IDT Read_SAS_SteerWheelAngle_SAS_SteerWheelAngle;
    SAS_SteerWhlRotSpdStatus_IDT Read_SAS_SteerWhlRotSpdStatus_SAS_SteerWhlRotSpdStatus;
    SAS_SteerWhlRotSpd_IDT Read_SAS_SteerWhlRotSpd_SAS_SteerWhlRotSpd;
    SAS_SteeringAngleValid_IDT Read_SAS_SteeringAngleValid_SAS_SteeringAngleValid;
    Signal_Group_ARS_OD_00_01_IDT Read_Signal_Group_ARS_OD_00_01_Signal_Group_ARS_OD_00_01;
    Signal_Group_ARS_OD_02_03_IDT Read_Signal_Group_ARS_OD_02_03_Signal_Group_ARS_OD_02_03;
    Signal_Group_ARS_OD_04_05_IDT Read_Signal_Group_ARS_OD_04_05_Signal_Group_ARS_OD_04_05;
    Signal_Group_ARS_OD_06_07_IDT Read_Signal_Group_ARS_OD_06_07_Signal_Group_ARS_OD_06_07;
    Signal_Group_ARS_OD_08_09_IDT Read_Signal_Group_ARS_OD_08_09_Signal_Group_ARS_OD_08_09;
    Signal_Group_ARS_OD_10_11_IDT Read_Signal_Group_ARS_OD_10_11_Signal_Group_ARS_OD_10_11;
    Signal_Group_ARS_OD_12_13_IDT Read_Signal_Group_ARS_OD_12_13_Signal_Group_ARS_OD_12_13;
    Signal_Group_ARS_OD_14_15_IDT Read_Signal_Group_ARS_OD_14_15_Signal_Group_ARS_OD_14_15;
    Signal_Group_ARS_OD_16_17_IDT Read_Signal_Group_ARS_OD_16_17_Signal_Group_ARS_OD_16_17;
    Signal_Group_ARS_OD_18_19_IDT Read_Signal_Group_ARS_OD_18_19_Signal_Group_ARS_OD_18_19;
    Signal_Group_ARS_OD_20_21_IDT Read_Signal_Group_ARS_OD_20_21_Signal_Group_ARS_OD_20_21;
    Signal_Group_ARS_OD_22_23_IDT Read_Signal_Group_ARS_OD_22_23_Signal_Group_ARS_OD_22_23;
    Signal_Group_ARS_OD_24_25_IDT Read_Signal_Group_ARS_OD_24_25_Signal_Group_ARS_OD_24_25;
    Signal_Group_ARS_OD_26_27_IDT Read_Signal_Group_ARS_OD_26_27_Signal_Group_ARS_OD_26_27;
    Signal_Group_ARS_OD_28_29_IDT Read_Signal_Group_ARS_OD_28_29_Signal_Group_ARS_OD_28_29;
    Signal_Group_ARS_OD_30_31_IDT Read_Signal_Group_ARS_OD_30_31_Signal_Group_ARS_OD_30_31;
    TSR_SLWFuncSwtReq_IDT Read_TSR_SLWFuncSwtReq_TSR_SLWFuncSwtReq;
    TSR_SpdWarningOffs_S_IDT Read_TSR_SpdWarningOffs_S_TSR_SpdWarningOffs_S;
    Time_Day_IDT Read_Time_Day_Time_Day;
    Time_Hour_IDT Read_Time_Hour_Time_Hour;
    Time_Minute_IDT Read_Time_Minute_Time_Minute;
    Time_Month_IDT Read_Time_Month_Time_Month;
    Time_Year_IDT Read_Time_Year_Time_Year;
    Time_second_IDT Read_Time_second_Time_second;
    VCU_AccPedalPosition_IDT Read_VCU_AccPedalPosition_VCU_AccPedalPosition;
    VCU_AccPedal_Valid_IDT Read_VCU_AccPedal_Valid_VCU_AccPedal_Valid;
    VCU_LimpHomeSts_IDT Read_VCU_LimpHomeSts_VCU_LimpHomeSts;
    VCU_ModeGearSts_IDT Read_VCU_ModeGearSts_VCU_ModeGearSts;
    VCU_Ready_IDT Read_VCU_Ready_VCU_Ready;
    VCU_StsAccPedalFault_IDT Read_VCU_StsAccPedalFault_VCU_StsAccPedalFault;
    VCU_StsSysFault_IDT Read_VCU_StsSysFault_VCU_StsSysFault;
    WCBS_ABAAtv_IDT Read_WCBS_ABAAtv_WCBS_ABAAtv;
    WCBS_ABAAva_IDT Read_WCBS_ABAAva_WCBS_ABAAva;
    WCBS_ABPAtv_IDT Read_WCBS_ABPAtv_WCBS_ABPAtv;
    WCBS_ABPAva_IDT Read_WCBS_ABPAva_WCBS_ABPAva;
    WCBS_ACC_CDD_Active_IDT Read_WCBS_ACC_CDD_Active_WCBS_ACC_CDD_Active;
    WCBS_ACC_CDD_Avl_IDT Read_WCBS_ACC_CDD_Avl_WCBS_ACC_CDD_Avl;
    WCBS_ACC_VLC_Active_IDT Read_WCBS_ACC_VLC_Active_WCBS_ACC_VLC_Active;
    WCBS_ACC_VLC_Avl_IDT Read_WCBS_ACC_VLC_Avl_WCBS_ACC_VLC_Avl;
    WCBS_AEBAtv_IDT Read_WCBS_AEBAtv_WCBS_AEBAtv;
    WCBS_AEBAva_IDT Read_WCBS_AEBAva_WCBS_AEBAva;
    WCBS_AWBAtv_IDT Read_WCBS_AWBAtv_WCBS_AWBAtv;
    WCBS_AWBAvl_IDT Read_WCBS_AWBAvl_WCBS_AWBAvl;
    WCBS_BrkFrcSta_IDT Read_WCBS_BrkFrcSta_WCBS_BrkFrcSta;
    WCBS_ESCDeteACCErroSta_IDT Read_WCBS_ESCDeteACCErroSta_WCBS_ESCDeteACCErroSta;
    WCBS_VStandstillSta_IDT Read_WCBS_VStandstillSta_WCBS_VStandstillSta;
    /* Task_Driving_Signal_Transmission_10ms Varaible Define User Code start*/

    /* Task_Driving_Signal_Transmission_10ms Varaible Define User Code end*/




    Rte_Write_ACC_AdtLowerJerkLimit_ACC_AdtLowerJerkLimit(Write_ACC_AdtLowerJerkLimit_ACC_AdtLowerJerkLimit);
    /* Rte_Write_ACC_AdtLowerJerkLimit_ACC_AdtLowerJerkLimit User Code start*/

    /* Rte_Write_ACC_AdtLowerJerkLimit_ACC_AdtLowerJerkLimit User Code end*/
    Rte_Write_ACC_AdtUpperJerkLimit_ACC_AdtUpperJerkLimit(Write_ACC_AdtUpperJerkLimit_ACC_AdtUpperJerkLimit);
    /* Rte_Write_ACC_AdtUpperJerkLimit_ACC_AdtUpperJerkLimit User Code start*/

    /* Rte_Write_ACC_AdtUpperJerkLimit_ACC_AdtUpperJerkLimit User Code end*/
    Rte_Write_ACC_DriveoffReq_ACC_DriveoffReq(Write_ACC_DriveoffReq_ACC_DriveoffReq);
    /* Rte_Write_ACC_DriveoffReq_ACC_DriveoffReq User Code start*/

    /* Rte_Write_ACC_DriveoffReq_ACC_DriveoffReq User Code end*/
    Rte_Write_ACC_TxtInfoForDriver_ACC_TxtInfoForDriver(Write_ACC_TxtInfoForDriver_ACC_TxtInfoForDriver);
    /* Rte_Write_ACC_TxtInfoForDriver_ACC_TxtInfoForDriver User Code start*/

    /* Rte_Write_ACC_TxtInfoForDriver_ACC_TxtInfoForDriver User Code end*/
    Rte_Write_ADAS_ACC_BrakePreferred_ADAS_ACC_BrakePreferred(Write_ADAS_ACC_BrakePreferred_ADAS_ACC_BrakePreferred);
    /* Rte_Write_ADAS_ACC_BrakePreferred_ADAS_ACC_BrakePreferred User Code start*/

    /* Rte_Write_ADAS_ACC_BrakePreferred_ADAS_ACC_BrakePreferred User Code end*/
    Rte_Write_ADAS_ACC_DistanceLevel_ADAS_ACC_DistanceLevel(Write_ADAS_ACC_DistanceLevel_ADAS_ACC_DistanceLevel);
    /* Rte_Write_ADAS_ACC_DistanceLevel_ADAS_ACC_DistanceLevel User Code start*/

    /* Rte_Write_ADAS_ACC_DistanceLevel_ADAS_ACC_DistanceLevel User Code end*/
    Rte_Write_ADAS_ACC_ObjDispSts_ADAS_ACC_ObjDispSts(Write_ADAS_ACC_ObjDispSts_ADAS_ACC_ObjDispSts);
    /* Rte_Write_ADAS_ACC_ObjDispSts_ADAS_ACC_ObjDispSts User Code start*/

    /* Rte_Write_ADAS_ACC_ObjDispSts_ADAS_ACC_ObjDispSts User Code end*/
    Rte_Write_ADAS_ACC_OperatingSts_ADAS_ACC_OperatingSts(Write_ADAS_ACC_OperatingSts_ADAS_ACC_OperatingSts);
    /* Rte_Write_ADAS_ACC_OperatingSts_ADAS_ACC_OperatingSts User Code start*/

    /* Rte_Write_ADAS_ACC_OperatingSts_ADAS_ACC_OperatingSts User Code end*/
    Rte_Write_ADAS_ACC_SpdUnit_ADAS_ACC_SpdUnit(Write_ADAS_ACC_SpdUnit_ADAS_ACC_SpdUnit);
    /* Rte_Write_ADAS_ACC_SpdUnit_ADAS_ACC_SpdUnit User Code start*/

    /* Rte_Write_ADAS_ACC_SpdUnit_ADAS_ACC_SpdUnit User Code end*/
    Rte_Write_ADAS_ACC_TakeOverReq_ADAS_ACC_TakeOverReq(Write_ADAS_ACC_TakeOverReq_ADAS_ACC_TakeOverReq);
    /* Rte_Write_ADAS_ACC_TakeOverReq_ADAS_ACC_TakeOverReq User Code start*/

    /* Rte_Write_ADAS_ACC_TakeOverReq_ADAS_ACC_TakeOverReq User Code end*/
    Rte_Write_ADAS_ACC_TargetSpeed_ADAS_ACC_TargetSpeed(Write_ADAS_ACC_TargetSpeed_ADAS_ACC_TargetSpeed);
    /* Rte_Write_ADAS_ACC_TargetSpeed_ADAS_ACC_TargetSpeed User Code start*/

    /* Rte_Write_ADAS_ACC_TargetSpeed_ADAS_ACC_TargetSpeed User Code end*/
    Rte_Write_ADAS_ACC_TimeGapLevel_ADAS_ACC_TimeGapLevel(Write_ADAS_ACC_TimeGapLevel_ADAS_ACC_TimeGapLevel);
    /* Rte_Write_ADAS_ACC_TimeGapLevel_ADAS_ACC_TimeGapLevel User Code start*/

    /* Rte_Write_ADAS_ACC_TimeGapLevel_ADAS_ACC_TimeGapLevel User Code end*/
    Rte_Write_ADAS_AEB_AbaLevel_ADAS_AEB_AbaLevel(Write_ADAS_AEB_AbaLevel_ADAS_AEB_AbaLevel);
    /* Rte_Write_ADAS_AEB_AbaLevel_ADAS_AEB_AbaLevel User Code start*/

    /* Rte_Write_ADAS_AEB_AbaLevel_ADAS_AEB_AbaLevel User Code end*/
    Rte_Write_ADAS_AEB_AbpReq_ADAS_AEB_AbpReq(Write_ADAS_AEB_AbpReq_ADAS_AEB_AbpReq);
    /* Rte_Write_ADAS_AEB_AbpReq_ADAS_AEB_AbpReq User Code start*/

    /* Rte_Write_ADAS_AEB_AbpReq_ADAS_AEB_AbpReq User Code end*/
    Rte_Write_ADAS_AEB_FuncSWResp_ADAS_AEB_FuncSWResp(Write_ADAS_AEB_FuncSWResp_ADAS_AEB_FuncSWResp);
    /* Rte_Write_ADAS_AEB_FuncSWResp_ADAS_AEB_FuncSWResp User Code start*/

    /* Rte_Write_ADAS_AEB_FuncSWResp_ADAS_AEB_FuncSWResp User Code end*/
    Rte_Write_ADAS_AEB_TgtDecel_ReqValue_ADAS_AEB_TgtDecel_ReqValue(Write_ADAS_AEB_TgtDecel_ReqValue_ADAS_AEB_TgtDecel_ReqValue);
    /* Rte_Write_ADAS_AEB_TgtDecel_ReqValue_ADAS_AEB_TgtDecel_ReqValue User Code start*/

    /* Rte_Write_ADAS_AEB_TgtDecel_ReqValue_ADAS_AEB_TgtDecel_ReqValue User Code end*/
    Rte_Write_ADAS_AccelerationReq_ADAS_AccelerationReq(Write_ADAS_AccelerationReq_ADAS_AccelerationReq);
    /* Rte_Write_ADAS_AccelerationReq_ADAS_AccelerationReq User Code start*/

    /* Rte_Write_ADAS_AccelerationReq_ADAS_AccelerationReq User Code end*/
    Rte_Write_ADAS_EPS_AngReqSts_ADAS_EPS_AngReqSts(Write_ADAS_EPS_AngReqSts_ADAS_EPS_AngReqSts);
    /* Rte_Write_ADAS_EPS_AngReqSts_ADAS_EPS_AngReqSts User Code start*/

    /* Rte_Write_ADAS_EPS_AngReqSts_ADAS_EPS_AngReqSts User Code end*/
    Rte_Write_ADAS_EPS_TargetSteeringAngle_ADAS_EPS_TargetSteeringAngle(Write_ADAS_EPS_TargetSteeringAngle_ADAS_EPS_TargetSteeringAngle);
    /* Rte_Write_ADAS_EPS_TargetSteeringAngle_ADAS_EPS_TargetSteeringAngle User Code start*/

    /* Rte_Write_ADAS_EPS_TargetSteeringAngle_ADAS_EPS_TargetSteeringAngle User Code end*/
    Rte_Write_ADAS_EPS_Vibration_Req_ADAS_EPS_Vibration_Req(Write_ADAS_EPS_Vibration_Req_ADAS_EPS_Vibration_Req);
    /* Rte_Write_ADAS_EPS_Vibration_Req_ADAS_EPS_Vibration_Req User Code start*/

    /* Rte_Write_ADAS_EPS_Vibration_Req_ADAS_EPS_Vibration_Req User Code end*/
    Rte_Write_ADAS_IBS_CarStarting_ADAS_IBS_CarStarting(Write_ADAS_IBS_CarStarting_ADAS_IBS_CarStarting);
    /* Rte_Write_ADAS_IBS_CarStarting_ADAS_IBS_CarStarting User Code start*/

    /* Rte_Write_ADAS_IBS_CarStarting_ADAS_IBS_CarStarting User Code end*/
    Rte_Write_ADAS_IBS_EBAReq_ADAS_IBS_EBAReq(Write_ADAS_IBS_EBAReq_ADAS_IBS_EBAReq);
    /* Rte_Write_ADAS_IBS_EBAReq_ADAS_IBS_EBAReq User Code start*/

    /* Rte_Write_ADAS_IBS_EBAReq_ADAS_IBS_EBAReq User Code end*/
    Rte_Write_ADAS_IBS_MinBreakReq_ADAS_IBS_MinBreakReq(Write_ADAS_IBS_MinBreakReq_ADAS_IBS_MinBreakReq);
    /* Rte_Write_ADAS_IBS_MinBreakReq_ADAS_IBS_MinBreakReq User Code start*/

    /* Rte_Write_ADAS_IBS_MinBreakReq_ADAS_IBS_MinBreakReq User Code end*/
    Rte_Write_ADAS_IBS_StopReq_ADAS_IBS_StopReq(Write_ADAS_IBS_StopReq_ADAS_IBS_StopReq);
    /* Rte_Write_ADAS_IBS_StopReq_ADAS_IBS_StopReq User Code start*/

    /* Rte_Write_ADAS_IBS_StopReq_ADAS_IBS_StopReq User Code end*/
    Rte_Write_ADAS_LSS_AngCmdReqPortnValue_ADAS_LSS_AngCmdReqPortnValue(Write_ADAS_LSS_AngCmdReqPortnValue_ADAS_LSS_AngCmdReqPortnValue);
    /* Rte_Write_ADAS_LSS_AngCmdReqPortnValue_ADAS_LSS_AngCmdReqPortnValue User Code start*/

    /* Rte_Write_ADAS_LSS_AngCmdReqPortnValue_ADAS_LSS_AngCmdReqPortnValue User Code end*/
    Rte_Write_ADAS_LSS_AssidFormResp_ADAS_LSS_AssidFormResp(Write_ADAS_LSS_AssidFormResp_ADAS_LSS_AssidFormResp);
    /* Rte_Write_ADAS_LSS_AssidFormResp_ADAS_LSS_AssidFormResp User Code start*/

    /* Rte_Write_ADAS_LSS_AssidFormResp_ADAS_LSS_AssidFormResp User Code end*/
    Rte_Write_ADAS_LSS_Available_ADAS_LSS_Available(Write_ADAS_LSS_Available_ADAS_LSS_Available);
    /* Rte_Write_ADAS_LSS_Available_ADAS_LSS_Available User Code start*/

    /* Rte_Write_ADAS_LSS_Available_ADAS_LSS_Available User Code end*/
    Rte_Write_ADAS_LSS_ErrSts_ADAS_LSS_ErrSts(Write_ADAS_LSS_ErrSts_ADAS_LSS_ErrSts);
    /* Rte_Write_ADAS_LSS_ErrSts_ADAS_LSS_ErrSts User Code start*/

    /* Rte_Write_ADAS_LSS_ErrSts_ADAS_LSS_ErrSts User Code end*/
    Rte_Write_ADAS_LSS_FunSts_ADAS_LSS_FunSts(Write_ADAS_LSS_FunSts_ADAS_LSS_FunSts);
    /* Rte_Write_ADAS_LSS_FunSts_ADAS_LSS_FunSts User Code start*/

    /* Rte_Write_ADAS_LSS_FunSts_ADAS_LSS_FunSts User Code end*/
    Rte_Write_ADAS_LSS_FuncResp_ADAS_LSS_FuncResp(Write_ADAS_LSS_FuncResp_ADAS_LSS_FuncResp);
    /* Rte_Write_ADAS_LSS_FuncResp_ADAS_LSS_FuncResp User Code start*/

    /* Rte_Write_ADAS_LSS_FuncResp_ADAS_LSS_FuncResp User Code end*/
    Rte_Write_ADAS_LSS_HandsoffWarn_ADAS_LSS_HandsoffWarn(Write_ADAS_LSS_HandsoffWarn_ADAS_LSS_HandsoffWarn);
    /* Rte_Write_ADAS_LSS_HandsoffWarn_ADAS_LSS_HandsoffWarn User Code start*/

    /* Rte_Write_ADAS_LSS_HandsoffWarn_ADAS_LSS_HandsoffWarn User Code end*/
    Rte_Write_ADAS_LSS_LeLineTrackingSts_ADAS_LSS_LeLineTrackingSts(Write_ADAS_LSS_LeLineTrackingSts_ADAS_LSS_LeLineTrackingSts);
    /* Rte_Write_ADAS_LSS_LeLineTrackingSts_ADAS_LSS_LeLineTrackingSts User Code start*/

    /* Rte_Write_ADAS_LSS_LeLineTrackingSts_ADAS_LSS_LeLineTrackingSts User Code end*/
    Rte_Write_ADAS_LSS_RiLineTrackingSts_ADAS_LSS_RiLineTrackingSts(Write_ADAS_LSS_RiLineTrackingSts_ADAS_LSS_RiLineTrackingSts);
    /* Rte_Write_ADAS_LSS_RiLineTrackingSts_ADAS_LSS_RiLineTrackingSts User Code start*/

    /* Rte_Write_ADAS_LSS_RiLineTrackingSts_ADAS_LSS_RiLineTrackingSts User Code end*/
    Rte_Write_ADAS_LSS_VoiceWarn_ADAS_LSS_VoiceWarn(Write_ADAS_LSS_VoiceWarn_ADAS_LSS_VoiceWarn);
    /* Rte_Write_ADAS_LSS_VoiceWarn_ADAS_LSS_VoiceWarn User Code start*/

    /* Rte_Write_ADAS_LSS_VoiceWarn_ADAS_LSS_VoiceWarn User Code end*/
    Rte_Write_ADAS_LSS_WarnFromResp_ADAS_LSS_WarnFromResp(Write_ADAS_LSS_WarnFromResp_ADAS_LSS_WarnFromResp);
    /* Rte_Write_ADAS_LSS_WarnFromResp_ADAS_LSS_WarnFromResp User Code start*/

    /* Rte_Write_ADAS_LSS_WarnFromResp_ADAS_LSS_WarnFromResp User Code end*/
    Rte_Write_ADAS_MaxSoftAcceleration_ADAS_MaxSoftAcceleration(Write_ADAS_MaxSoftAcceleration_ADAS_MaxSoftAcceleration);
    /* Rte_Write_ADAS_MaxSoftAcceleration_ADAS_MaxSoftAcceleration User Code start*/

    /* Rte_Write_ADAS_MaxSoftAcceleration_ADAS_MaxSoftAcceleration User Code end*/
    Rte_Write_ADAS_MinSoftAcceleration_ADAS_MinSoftAcceleration(Write_ADAS_MinSoftAcceleration_ADAS_MinSoftAcceleration);
    /* Rte_Write_ADAS_MinSoftAcceleration_ADAS_MinSoftAcceleration User Code start*/

    /* Rte_Write_ADAS_MinSoftAcceleration_ADAS_MinSoftAcceleration User Code end*/
    Rte_Write_ADAS_TSR_OperationSts_ADAS_TSR_OperationSts(Write_ADAS_TSR_OperationSts_ADAS_TSR_OperationSts);
    /* Rte_Write_ADAS_TSR_OperationSts_ADAS_TSR_OperationSts User Code start*/

    /* Rte_Write_ADAS_TSR_OperationSts_ADAS_TSR_OperationSts User Code end*/
    Rte_Write_ADAS_TSR_SWSts_ADAS_TSR_SWSts(Write_ADAS_TSR_SWSts_ADAS_TSR_SWSts);
    /* Rte_Write_ADAS_TSR_SWSts_ADAS_TSR_SWSts User Code start*/

    /* Rte_Write_ADAS_TSR_SWSts_ADAS_TSR_SWSts User Code end*/
    Rte_Write_ADAS_TSR_SpeedLimit_ADAS_TSR_SpeedLimit(Write_ADAS_TSR_SpeedLimit_ADAS_TSR_SpeedLimit);
    /* Rte_Write_ADAS_TSR_SpeedLimit_ADAS_TSR_SpeedLimit User Code start*/

    /* Rte_Write_ADAS_TSR_SpeedLimit_ADAS_TSR_SpeedLimit User Code end*/
    Rte_Write_ADAS_VLCModeReq_ADAS_VLCModeReq(Write_ADAS_VLCModeReq_ADAS_VLCModeReq);
    /* Rte_Write_ADAS_VLCModeReq_ADAS_VLCModeReq User Code start*/

    /* Rte_Write_ADAS_VLCModeReq_ADAS_VLCModeReq User Code end*/
    Rte_Write_ADAS_VLCShutDownReq_ADAS_VLCShutDownReq(Write_ADAS_VLCShutDownReq_ADAS_VLCShutDownReq);
    /* Rte_Write_ADAS_VLCShutDownReq_ADAS_VLCShutDownReq User Code start*/

    /* Rte_Write_ADAS_VLCShutDownReq_ADAS_VLCShutDownReq User Code end*/
    Rte_Write_AEB_ABA_Req_AEB_ABA_Req(Write_AEB_ABA_Req_AEB_ABA_Req);
    /* Rte_Write_AEB_ABA_Req_AEB_ABA_Req User Code start*/

    /* Rte_Write_AEB_ABA_Req_AEB_ABA_Req User Code end*/
    Rte_Write_AEB_AWB_Level_AEB_AWB_Level(Write_AEB_AWB_Level_AEB_AWB_Level);
    /* Rte_Write_AEB_AWB_Level_AEB_AWB_Level User Code start*/

    /* Rte_Write_AEB_AWB_Level_AEB_AWB_Level User Code end*/
    Rte_Write_AEB_AWB_Req_AEB_AWB_Req(Write_AEB_AWB_Req_AEB_AWB_Req);
    /* Rte_Write_AEB_AWB_Req_AEB_AWB_Req User Code start*/

    /* Rte_Write_AEB_AWB_Req_AEB_AWB_Req User Code end*/
    Rte_Write_AEB_ErrorSts_AEB_ErrorSts(Write_AEB_ErrorSts_AEB_ErrorSts);
    /* Rte_Write_AEB_ErrorSts_AEB_ErrorSts User Code start*/

    /* Rte_Write_AEB_ErrorSts_AEB_ErrorSts User Code end*/
    Rte_Write_AEB_FCW_Warning_AEB_FCW_Warning(Write_AEB_FCW_Warning_AEB_FCW_Warning);
    /* Rte_Write_AEB_FCW_Warning_AEB_FCW_Warning User Code start*/

    /* Rte_Write_AEB_FCW_Warning_AEB_FCW_Warning User Code end*/
    Rte_Write_AEB_FuncSts_AEB_FuncSts(Write_AEB_FuncSts_AEB_FuncSts);
    /* Rte_Write_AEB_FuncSts_AEB_FuncSts User Code start*/

    /* Rte_Write_AEB_FuncSts_AEB_FuncSts User Code end*/
    Rte_Write_AEB_TgtDecel_Req_AEB_TgtDecel_Req(Write_AEB_TgtDecel_Req_AEB_TgtDecel_Req);
    /* Rte_Write_AEB_TgtDecel_Req_AEB_TgtDecel_Req User Code start*/

    /* Rte_Write_AEB_TgtDecel_Req_AEB_TgtDecel_Req User Code end*/
    Rte_Write_AEB_VRUActive_AEB_VRUActive(Write_AEB_VRUActive_AEB_VRUActive);
    /* Rte_Write_AEB_VRUActive_AEB_VRUActive User Code start*/

    /* Rte_Write_AEB_VRUActive_AEB_VRUActive User Code end*/
    Rte_Write_AEB_VehActive_AEB_VehActive(Write_AEB_VehActive_AEB_VehActive);
    /* Rte_Write_AEB_VehActive_AEB_VehActive User Code start*/

    /* Rte_Write_AEB_VehActive_AEB_VehActive User Code end*/
    Rte_Write_AEB_VehHldReq_AEB_VehHldReq(Write_AEB_VehHldReq_AEB_VehHldReq);
    /* Rte_Write_AEB_VehHldReq_AEB_VehHldReq User Code start*/

    /* Rte_Write_AEB_VehHldReq_AEB_VehHldReq User Code end*/
    Rte_Write_AEB_FCW_SnvtyResp_AEB_FCW_SnvtyResp(Write_AEB_FCW_SnvtyResp_AEB_FCW_SnvtyResp);
    /* Rte_Write_AEB_FCW_SnvtyResp_AEB_FCW_SnvtyResp User Code start*/

    /* Rte_Write_AEB_FCW_SnvtyResp_AEB_FCW_SnvtyResp User Code end*/
    Rte_Write_FC_BlockageSts_FC_BlockageSts(Write_FC_BlockageSts_FC_BlockageSts);
    /* Rte_Write_FC_BlockageSts_FC_BlockageSts User Code start*/

    /* Rte_Write_FC_BlockageSts_FC_BlockageSts User Code end*/
    Rte_Write_FC_CalibrationSts_FC_CalibrationSts(Write_FC_CalibrationSts_FC_CalibrationSts);
    /* Rte_Write_FC_CalibrationSts_FC_CalibrationSts User Code start*/

    /* Rte_Write_FC_CalibrationSts_FC_CalibrationSts User Code end*/
    Rte_Write_PiFrontRadarInfo_PiFrontRadarInfo(&Write_PiFrontRadarInfo_PiFrontRadarInfo);
    /* Rte_Write_PiFrontRadarInfo_PiFrontRadarInfo User Code start*/

    /* Rte_Write_PiFrontRadarInfo_PiFrontRadarInfo User Code end*/
    Rte_Write_TSR_SLWSwtResp_TSR_SLWSwtResp(Write_TSR_SLWSwtResp_TSR_SLWSwtResp);
    /* Rte_Write_TSR_SLWSwtResp_TSR_SLWSwtResp User Code start*/

    /* Rte_Write_TSR_SLWSwtResp_TSR_SLWSwtResp User Code end*/
    Rte_Write_TSR_SLWVisualWarn_TSR_SLWVisualWarn(Write_TSR_SLWVisualWarn_TSR_SLWVisualWarn);
    /* Rte_Write_TSR_SLWVisualWarn_TSR_SLWVisualWarn User Code start*/

    /* Rte_Write_TSR_SLWVisualWarn_TSR_SLWVisualWarn User Code end*/
    Rte_Write_TSR_SLWVoiceWarn_TSR_SLWVoiceWarn(Write_TSR_SLWVoiceWarn_TSR_SLWVoiceWarn);
    /* Rte_Write_TSR_SLWVoiceWarn_TSR_SLWVoiceWarn User Code start*/

    /* Rte_Write_TSR_SLWVoiceWarn_TSR_SLWVoiceWarn User Code end*/
    Rte_Write_TSR_SpdAssistInfoDisp_TSR_SpdAssistInfoDisp(Write_TSR_SpdAssistInfoDisp_TSR_SpdAssistInfoDisp);
    /* Rte_Write_TSR_SpdAssistInfoDisp_TSR_SpdAssistInfoDisp User Code start*/

    /* Rte_Write_TSR_SpdAssistInfoDisp_TSR_SpdAssistInfoDisp User Code end*/
    Rte_Write_TSR_TrafSign_TSR_TrafSign(Write_TSR_TrafSign_TSR_TrafSign);
    /* Rte_Write_TSR_TrafSign_TSR_TrafSign User Code start*/

    /* Rte_Write_TSR_TrafSign_TSR_TrafSign User Code end*/
    Rte_Write_TSR_Warning_offset_TSR_Warning_offset(Write_TSR_Warning_offset_TSR_Warning_offset);
    /* Rte_Write_TSR_Warning_offset_TSR_Warning_offset User Code start*/

    /* Rte_Write_TSR_Warning_offset_TSR_Warning_offset User Code end*/
    Rte_Write_PiVehicleInfo_PiVehicleInfo(&Write_PiVehicleInfo_PiVehicleInfo);
    /* Rte_Write_PiVehicleInfo_PiVehicleInfo User Code start*/

    /* Rte_Write_PiVehicleInfo_PiVehicleInfo User Code end*/
    Rte_Read_ABSActive_ABSActive(&Read_ABSActive_ABSActive);
    /* Rte_Read_ABSActive_ABSActive User Code start*/

    /* Rte_Read_ABSActive_ABSActive User Code end*/
    Rte_Read_ABS_FLWheelDirection_ABS_FLWheelDirection(&Read_ABS_FLWheelDirection_ABS_FLWheelDirection);
    /* Rte_Read_ABS_FLWheelDirection_ABS_FLWheelDirection User Code start*/

    /* Rte_Read_ABS_FLWheelDirection_ABS_FLWheelDirection User Code end*/
    Rte_Read_ABS_FLWheelSpeedInvalid_ABS_FLWheelSpeedInvalid(&Read_ABS_FLWheelSpeedInvalid_ABS_FLWheelSpeedInvalid);
    /* Rte_Read_ABS_FLWheelSpeedInvalid_ABS_FLWheelSpeedInvalid User Code start*/

    /* Rte_Read_ABS_FLWheelSpeedInvalid_ABS_FLWheelSpeedInvalid User Code end*/
    Rte_Read_ABS_FLWheelSpeedKPH_ABS_FLWheelSpeedKPH(&Read_ABS_FLWheelSpeedKPH_ABS_FLWheelSpeedKPH);
    /* Rte_Read_ABS_FLWheelSpeedKPH_ABS_FLWheelSpeedKPH User Code start*/

    /* Rte_Read_ABS_FLWheelSpeedKPH_ABS_FLWheelSpeedKPH User Code end*/
    Rte_Read_ABS_FRWheelDirection_ABS_FRWheelDirection(&Read_ABS_FRWheelDirection_ABS_FRWheelDirection);
    /* Rte_Read_ABS_FRWheelDirection_ABS_FRWheelDirection User Code start*/

    /* Rte_Read_ABS_FRWheelDirection_ABS_FRWheelDirection User Code end*/
    Rte_Read_ABS_FRWheelSpeedInvalid_ABS_FRWheelSpeedInvalid(&Read_ABS_FRWheelSpeedInvalid_ABS_FRWheelSpeedInvalid);
    /* Rte_Read_ABS_FRWheelSpeedInvalid_ABS_FRWheelSpeedInvalid User Code start*/

    /* Rte_Read_ABS_FRWheelSpeedInvalid_ABS_FRWheelSpeedInvalid User Code end*/
    Rte_Read_ABS_FRWheelSpeedKPH_ABS_FRWheelSpeedKPH(&Read_ABS_FRWheelSpeedKPH_ABS_FRWheelSpeedKPH);
    /* Rte_Read_ABS_FRWheelSpeedKPH_ABS_FRWheelSpeedKPH User Code start*/

    /* Rte_Read_ABS_FRWheelSpeedKPH_ABS_FRWheelSpeedKPH User Code end*/
    Rte_Read_ABS_RLWheelDirection_ABS_RLWheelDirection(&Read_ABS_RLWheelDirection_ABS_RLWheelDirection);
    /* Rte_Read_ABS_RLWheelDirection_ABS_RLWheelDirection User Code start*/

    /* Rte_Read_ABS_RLWheelDirection_ABS_RLWheelDirection User Code end*/
    Rte_Read_ABS_RLWheelSpeedInvalid_ABS_RLWheelSpeedInvalid(&Read_ABS_RLWheelSpeedInvalid_ABS_RLWheelSpeedInvalid);
    /* Rte_Read_ABS_RLWheelSpeedInvalid_ABS_RLWheelSpeedInvalid User Code start*/

    /* Rte_Read_ABS_RLWheelSpeedInvalid_ABS_RLWheelSpeedInvalid User Code end*/
    Rte_Read_ABS_RLWheelSpeedKPH_ABS_RLWheelSpeedKPH(&Read_ABS_RLWheelSpeedKPH_ABS_RLWheelSpeedKPH);
    /* Rte_Read_ABS_RLWheelSpeedKPH_ABS_RLWheelSpeedKPH User Code start*/

    /* Rte_Read_ABS_RLWheelSpeedKPH_ABS_RLWheelSpeedKPH User Code end*/
    Rte_Read_ABS_RRWheelDirection_ABS_RRWheelDirection(&Read_ABS_RRWheelDirection_ABS_RRWheelDirection);
    /* Rte_Read_ABS_RRWheelDirection_ABS_RRWheelDirection User Code start*/

    /* Rte_Read_ABS_RRWheelDirection_ABS_RRWheelDirection User Code end*/
    Rte_Read_ABS_RRWheelSpeedInvalid_ABS_RRWheelSpeedInvalid(&Read_ABS_RRWheelSpeedInvalid_ABS_RRWheelSpeedInvalid);
    /* Rte_Read_ABS_RRWheelSpeedInvalid_ABS_RRWheelSpeedInvalid User Code start*/

    /* Rte_Read_ABS_RRWheelSpeedInvalid_ABS_RRWheelSpeedInvalid User Code end*/
    Rte_Read_ABS_RRWheelSpeedKPH_ABS_RRWheelSpeedKPH(&Read_ABS_RRWheelSpeedKPH_ABS_RRWheelSpeedKPH);
    /* Rte_Read_ABS_RRWheelSpeedKPH_ABS_RRWheelSpeedKPH User Code start*/

    /* Rte_Read_ABS_RRWheelSpeedKPH_ABS_RRWheelSpeedKPH User Code end*/
    Rte_Read_ABS_VehicleSpeedInvalid_ABS_VehicleSpeedInvalid(&Read_ABS_VehicleSpeedInvalid_ABS_VehicleSpeedInvalid);
    /* Rte_Read_ABS_VehicleSpeedInvalid_ABS_VehicleSpeedInvalid User Code start*/

    /* Rte_Read_ABS_VehicleSpeedInvalid_ABS_VehicleSpeedInvalid User Code end*/
    Rte_Read_ABS_VehicleSpeed_ABS_VehicleSpeed(&Read_ABS_VehicleSpeed_ABS_VehicleSpeed);
    /* Rte_Read_ABS_VehicleSpeed_ABS_VehicleSpeed User Code start*/

    /* Rte_Read_ABS_VehicleSpeed_ABS_VehicleSpeed User Code end*/
    Rte_Read_AB_BrkPedalPct_AB_BrkPedalPct(&Read_AB_BrkPedalPct_AB_BrkPedalPct);
    /* Rte_Read_AB_BrkPedalPct_AB_BrkPedalPct User Code start*/

    /* Rte_Read_AB_BrkPedalPct_AB_BrkPedalPct User Code end*/
    Rte_Read_AB_BrkPedalSwStsV_AB_BrkPedalSwStsV(&Read_AB_BrkPedalSwStsV_AB_BrkPedalSwStsV);
    /* Rte_Read_AB_BrkPedalSwStsV_AB_BrkPedalSwStsV User Code start*/

    /* Rte_Read_AB_BrkPedalSwStsV_AB_BrkPedalSwStsV User Code end*/
    Rte_Read_AB_BrkPedalSwSts_AB_BrkPedalSwSts(&Read_AB_BrkPedalSwSts_AB_BrkPedalSwSts);
    /* Rte_Read_AB_BrkPedalSwSts_AB_BrkPedalSwSts User Code start*/

    /* Rte_Read_AB_BrkPedalSwSts_AB_BrkPedalSwSts User Code end*/
    Rte_Read_AB_BrkPedalTravel_AB_BrkPedalTravel(&Read_AB_BrkPedalTravel_AB_BrkPedalTravel);
    /* Rte_Read_AB_BrkPedalTravel_AB_BrkPedalTravel User Code start*/

    /* Rte_Read_AB_BrkPedalTravel_AB_BrkPedalTravel User Code end*/
    Rte_Read_AB_Fault_Status_AB_Fault_Status(&Read_AB_Fault_Status_AB_Fault_Status);
    /* Rte_Read_AB_Fault_Status_AB_Fault_Status User Code start*/

    /* Rte_Read_AB_Fault_Status_AB_Fault_Status User Code end*/
    Rte_Read_ACU_CoDSeatbeltBucklestatus_ACU_CoDSeatbeltBucklestatus(&Read_ACU_CoDSeatbeltBucklestatus_ACU_CoDSeatbeltBucklestatus);
    /* Rte_Read_ACU_CoDSeatbeltBucklestatus_ACU_CoDSeatbeltBucklestatus User Code start*/

    /* Rte_Read_ACU_CoDSeatbeltBucklestatus_ACU_CoDSeatbeltBucklestatus User Code end*/
    Rte_Read_ACU_DSeatbeltBucklestatus_ACU_DSeatbeltBucklestatus(&Read_ACU_DSeatbeltBucklestatus_ACU_DSeatbeltBucklestatus);
    /* Rte_Read_ACU_DSeatbeltBucklestatus_ACU_DSeatbeltBucklestatus User Code start*/

    /* Rte_Read_ACU_DSeatbeltBucklestatus_ACU_DSeatbeltBucklestatus User Code end*/
    Rte_Read_ADAS_APA_SystemSts_ADAS_APA_SystemSts(&Read_ADAS_APA_SystemSts_ADAS_APA_SystemSts);
    /* Rte_Read_ADAS_APA_SystemSts_ADAS_APA_SystemSts User Code start*/

    /* Rte_Read_ADAS_APA_SystemSts_ADAS_APA_SystemSts User Code end*/
    Rte_Read_AEB_FCW_SnvtyReq_AEB_FCW_SnvtyReq(&Read_AEB_FCW_SnvtyReq_AEB_FCW_SnvtyReq);
    /* Rte_Read_AEB_FCW_SnvtyReq_AEB_FCW_SnvtyReq User Code start*/

    /* Rte_Read_AEB_FCW_SnvtyReq_AEB_FCW_SnvtyReq User Code end*/
    Rte_Read_AEB_FuncSwtReq_AEB_FuncSwtReq(&Read_AEB_FuncSwtReq_AEB_FuncSwtReq);
    /* Rte_Read_AEB_FuncSwtReq_AEB_FuncSwtReq User Code start*/

    /* Rte_Read_AEB_FuncSwtReq_AEB_FuncSwtReq User Code end*/
    Rte_Read_ADAS_APA_OperationSts_ADAS_APA_OperationSts(&Read_ADAS_APA_OperationSts_ADAS_APA_OperationSts);
    /* Rte_Read_ADAS_APA_OperationSts_ADAS_APA_OperationSts User Code start*/

    /* Rte_Read_ADAS_APA_OperationSts_ADAS_APA_OperationSts User Code end*/
    Rte_Read_BCM_AutoWipeSts_BCM_AutoWipeSts(&Read_BCM_AutoWipeSts_BCM_AutoWipeSts);
    /* Rte_Read_BCM_AutoWipeSts_BCM_AutoWipeSts User Code start*/

    /* Rte_Read_BCM_AutoWipeSts_BCM_AutoWipeSts User Code end*/
    Rte_Read_BCM_CodriversSideDoorAjarSts_BCM_CodriversSideDoorAjarSts(&Read_BCM_CodriversSideDoorAjarSts_BCM_CodriversSideDoorAjarSts);
    /* Rte_Read_BCM_CodriversSideDoorAjarSts_BCM_CodriversSideDoorAjarSts User Code start*/

    /* Rte_Read_BCM_CodriversSideDoorAjarSts_BCM_CodriversSideDoorAjarSts User Code end*/
    Rte_Read_BCM_CoverAjarStatus_BCM_CoverAjarStatus(&Read_BCM_CoverAjarStatus_BCM_CoverAjarStatus);
    /* Rte_Read_BCM_CoverAjarStatus_BCM_CoverAjarStatus User Code start*/

    /* Rte_Read_BCM_CoverAjarStatus_BCM_CoverAjarStatus User Code end*/
    Rte_Read_BCM_DoorLockStatusCodrivres_BCM_DoorLockStatusCodrivres(&Read_BCM_DoorLockStatusCodrivres_BCM_DoorLockStatusCodrivres);
    /* Rte_Read_BCM_DoorLockStatusCodrivres_BCM_DoorLockStatusCodrivres User Code start*/

    /* Rte_Read_BCM_DoorLockStatusCodrivres_BCM_DoorLockStatusCodrivres User Code end*/
    Rte_Read_BCM_DoorLockStatusDrv_BCM_DoorLockStatusDrv(&Read_BCM_DoorLockStatusDrv_BCM_DoorLockStatusDrv);
    /* Rte_Read_BCM_DoorLockStatusDrv_BCM_DoorLockStatusDrv User Code start*/

    /* Rte_Read_BCM_DoorLockStatusDrv_BCM_DoorLockStatusDrv User Code end*/
    Rte_Read_BCM_DoorLockStatusRL_BCM_DoorLockStatusRL(&Read_BCM_DoorLockStatusRL_BCM_DoorLockStatusRL);
    /* Rte_Read_BCM_DoorLockStatusRL_BCM_DoorLockStatusRL User Code start*/

    /* Rte_Read_BCM_DoorLockStatusRL_BCM_DoorLockStatusRL User Code end*/
    Rte_Read_BCM_DoorLockStatusRR_BCM_DoorLockStatusRR(&Read_BCM_DoorLockStatusRR_BCM_DoorLockStatusRR);
    /* Rte_Read_BCM_DoorLockStatusRR_BCM_DoorLockStatusRR User Code start*/

    /* Rte_Read_BCM_DoorLockStatusRR_BCM_DoorLockStatusRR User Code end*/
    Rte_Read_BCM_DriverSideDoorAjarSts_BCM_DriverSideDoorAjarSts(&Read_BCM_DriverSideDoorAjarSts_BCM_DriverSideDoorAjarSts);
    /* Rte_Read_BCM_DriverSideDoorAjarSts_BCM_DriverSideDoorAjarSts User Code start*/

    /* Rte_Read_BCM_DriverSideDoorAjarSts_BCM_DriverSideDoorAjarSts User Code end*/
    Rte_Read_BCM_FrontFogLampLightSts_BCM_FrontFogLampLightSts(&Read_BCM_FrontFogLampLightSts_BCM_FrontFogLampLightSts);
    /* Rte_Read_BCM_FrontFogLampLightSts_BCM_FrontFogLampLightSts User Code start*/

    /* Rte_Read_BCM_FrontFogLampLightSts_BCM_FrontFogLampLightSts User Code end*/
    Rte_Read_BCM_FrontWipeSWSts_BCM_FrontWipeSWSts(&Read_BCM_FrontWipeSWSts_BCM_FrontWipeSWSts);
    /* Rte_Read_BCM_FrontWipeSWSts_BCM_FrontWipeSWSts User Code start*/

    /* Rte_Read_BCM_FrontWipeSWSts_BCM_FrontWipeSWSts User Code end*/
    Rte_Read_BCM_FrontWipeSts_BCM_FrontWipeSts(&Read_BCM_FrontWipeSts_BCM_FrontWipeSts);
    /* Rte_Read_BCM_FrontWipeSts_BCM_FrontWipeSts User Code start*/

    /* Rte_Read_BCM_FrontWipeSts_BCM_FrontWipeSts User Code end*/
    Rte_Read_BCM_RearLeftDoorAjarStatus_BCM_RearLeftDoorAjarStatus(&Read_BCM_RearLeftDoorAjarStatus_BCM_RearLeftDoorAjarStatus);
    /* Rte_Read_BCM_RearLeftDoorAjarStatus_BCM_RearLeftDoorAjarStatus User Code start*/

    /* Rte_Read_BCM_RearLeftDoorAjarStatus_BCM_RearLeftDoorAjarStatus User Code end*/
    Rte_Read_BCM_RearRightDoorAjarStatus_BCM_RearRightDoorAjarStatus(&Read_BCM_RearRightDoorAjarStatus_BCM_RearRightDoorAjarStatus);
    /* Rte_Read_BCM_RearRightDoorAjarStatus_BCM_RearRightDoorAjarStatus User Code start*/

    /* Rte_Read_BCM_RearRightDoorAjarStatus_BCM_RearRightDoorAjarStatus User Code end*/
    Rte_Read_BCM_TrunckAjarStatus_BCM_TrunckAjarStatus(&Read_BCM_TrunckAjarStatus_BCM_TrunckAjarStatus);
    /* Rte_Read_BCM_TrunckAjarStatus_BCM_TrunckAjarStatus User Code start*/

    /* Rte_Read_BCM_TrunckAjarStatus_BCM_TrunckAjarStatus User Code end*/
    Rte_Read_BCM_TurnIndicatorSts_BCM_TurnIndicatorSts(&Read_BCM_TurnIndicatorSts_BCM_TurnIndicatorSts);
    /* Rte_Read_BCM_TurnIndicatorSts_BCM_TurnIndicatorSts User Code start*/

    /* Rte_Read_BCM_TurnIndicatorSts_BCM_TurnIndicatorSts User Code end*/
    Rte_Read_BCM_TurnLightSWSts_BCM_TurnLightSWSts(&Read_BCM_TurnLightSWSts_BCM_TurnLightSWSts);
    /* Rte_Read_BCM_TurnLightSWSts_BCM_TurnLightSWSts User Code start*/

    /* Rte_Read_BCM_TurnLightSWSts_BCM_TurnLightSWSts User Code end*/
    Rte_Read_BCM_TurnLight_FaultSts_BCM_TurnLight_FaultSts(&Read_BCM_TurnLight_FaultSts_BCM_TurnLight_FaultSts);
    /* Rte_Read_BCM_TurnLight_FaultSts_BCM_TurnLight_FaultSts User Code start*/

    /* Rte_Read_BCM_TurnLight_FaultSts_BCM_TurnLight_FaultSts User Code end*/
    Rte_Read_BSD_LCA_FuncSWReq_BSD_LCA_FuncSWReq(&Read_BSD_LCA_FuncSWReq_BSD_LCA_FuncSWReq);
    /* Rte_Read_BSD_LCA_FuncSWReq_BSD_LCA_FuncSWReq User Code start*/

    /* Rte_Read_BSD_LCA_FuncSWReq_BSD_LCA_FuncSWReq User Code end*/
    Rte_Read_CCU_ExternalTemperature_CCU_ExternalTemperature(&Read_CCU_ExternalTemperature_CCU_ExternalTemperature);
    /* Rte_Read_CCU_ExternalTemperature_CCU_ExternalTemperature User Code start*/

    /* Rte_Read_CCU_ExternalTemperature_CCU_ExternalTemperature User Code end*/
    Rte_Read_ESC_TcsDisableSts_ESC_TcsDisableSts(&Read_ESC_TcsDisableSts_ESC_TcsDisableSts);
    /* Rte_Read_ESC_TcsDisableSts_ESC_TcsDisableSts User Code start*/

    /* Rte_Read_ESC_TcsDisableSts_ESC_TcsDisableSts User Code end*/
    Rte_Read_DOW_FuncSWReq_DOW_FuncSWReq(&Read_DOW_FuncSWReq_DOW_FuncSWReq);
    /* Rte_Read_DOW_FuncSWReq_DOW_FuncSWReq User Code start*/

    /* Rte_Read_DOW_FuncSWReq_DOW_FuncSWReq User Code end*/
    Rte_Read_EPB_AVHFeedbackSts_EPB_AVHFeedbackSts(&Read_EPB_AVHFeedbackSts_EPB_AVHFeedbackSts);
    /* Rte_Read_EPB_AVHFeedbackSts_EPB_AVHFeedbackSts User Code start*/

    /* Rte_Read_EPB_AVHFeedbackSts_EPB_AVHFeedbackSts User Code end*/
    Rte_Read_EPB_AVHStatIndReqV_EPB_AVHStatIndReqV(&Read_EPB_AVHStatIndReqV_EPB_AVHStatIndReqV);
    /* Rte_Read_EPB_AVHStatIndReqV_EPB_AVHStatIndReqV User Code start*/

    /* Rte_Read_EPB_AVHStatIndReqV_EPB_AVHStatIndReqV User Code end*/
    Rte_Read_EPS_ADAS_CtrlAbortFeedback_EPS_ADAS_CtrlAbortFeedback(&Read_EPS_ADAS_CtrlAbortFeedback_EPS_ADAS_CtrlAbortFeedback);
    /* Rte_Read_EPS_ADAS_CtrlAbortFeedback_EPS_ADAS_CtrlAbortFeedback User Code start*/

    /* Rte_Read_EPS_ADAS_CtrlAbortFeedback_EPS_ADAS_CtrlAbortFeedback User Code end*/
    Rte_Read_EPS_ADAS_ModActv_EPS_ADAS_ModActv(&Read_EPS_ADAS_ModActv_EPS_ADAS_ModActv);
    /* Rte_Read_EPS_ADAS_ModActv_EPS_ADAS_ModActv User Code start*/

    /* Rte_Read_EPS_ADAS_ModActv_EPS_ADAS_ModActv User Code end*/
    Rte_Read_EPS_ADAS_ModAvail_EPS_ADAS_ModAvail(&Read_EPS_ADAS_ModAvail_EPS_ADAS_ModAvail);
    /* Rte_Read_EPS_ADAS_ModAvail_EPS_ADAS_ModAvail User Code start*/

    /* Rte_Read_EPS_ADAS_ModAvail_EPS_ADAS_ModAvail User Code end*/
    Rte_Read_EPS_DrStrTorqV_EPS_DrStrTorqV(&Read_EPS_DrStrTorqV_EPS_DrStrTorqV);
    /* Rte_Read_EPS_DrStrTorqV_EPS_DrStrTorqV User Code start*/

    /* Rte_Read_EPS_DrStrTorqV_EPS_DrStrTorqV User Code end*/
    Rte_Read_EPS_DrStrTorqVal_EPS_DrStrTorqVal(&Read_EPS_DrStrTorqVal_EPS_DrStrTorqVal);
    /* Rte_Read_EPS_DrStrTorqVal_EPS_DrStrTorqVal User Code start*/

    /* Rte_Read_EPS_DrStrTorqVal_EPS_DrStrTorqVal User Code end*/
    Rte_Read_EPS_LKARespTorq_EPS_LKARespTorq(&Read_EPS_LKARespTorq_EPS_LKARespTorq);
    /* Rte_Read_EPS_LKARespTorq_EPS_LKARespTorq User Code start*/

    /* Rte_Read_EPS_LKARespTorq_EPS_LKARespTorq User Code end*/
    Rte_Read_EPS_SterFltMod_EPS_SterFltMod(&Read_EPS_SterFltMod_EPS_SterFltMod);
    /* Rte_Read_EPS_SterFltMod_EPS_SterFltMod User Code start*/

    /* Rte_Read_EPS_SterFltMod_EPS_SterFltMod User Code end*/
    Rte_Read_ESC_EscCtrlActv_ESC_EscCtrlActv(&Read_ESC_EscCtrlActv_ESC_EscCtrlActv);
    /* Rte_Read_ESC_EscCtrlActv_ESC_EscCtrlActv User Code start*/

    /* Rte_Read_ESC_EscCtrlActv_ESC_EscCtrlActv User Code end*/
    Rte_Read_ESC_EscDisableSts_ESC_EscDisableSts(&Read_ESC_EscDisableSts_ESC_EscDisableSts);
    /* Rte_Read_ESC_EscDisableSts_ESC_EscDisableSts User Code start*/

    /* Rte_Read_ESC_EscDisableSts_ESC_EscDisableSts User Code end*/
    Rte_Read_ESC_HSA_Control_Status_ESC_HSA_Control_Status(&Read_ESC_HSA_Control_Status_ESC_HSA_Control_Status);
    /* Rte_Read_ESC_HSA_Control_Status_ESC_HSA_Control_Status User Code start*/

    /* Rte_Read_ESC_HSA_Control_Status_ESC_HSA_Control_Status User Code end*/
    Rte_Read_ESC_LateralACC_ESC_LateralACC(&Read_ESC_LateralACC_ESC_LateralACC);
    /* Rte_Read_ESC_LateralACC_ESC_LateralACC User Code start*/

    /* Rte_Read_ESC_LateralACC_ESC_LateralACC User Code end*/
    Rte_Read_ESC_LateralACC_Valid_ESC_LateralACC_Valid(&Read_ESC_LateralACC_Valid_ESC_LateralACC_Valid);
    /* Rte_Read_ESC_LateralACC_Valid_ESC_LateralACC_Valid User Code start*/

    /* Rte_Read_ESC_LateralACC_Valid_ESC_LateralACC_Valid User Code end*/
    Rte_Read_ESC_LongitudeACC_ESC_LongitudeACC(&Read_ESC_LongitudeACC_ESC_LongitudeACC);
    /* Rte_Read_ESC_LongitudeACC_ESC_LongitudeACC User Code start*/

    /* Rte_Read_ESC_LongitudeACC_ESC_LongitudeACC User Code end*/
    Rte_Read_ESC_LongitudeACC_Valid_ESC_LongitudeACC_Valid(&Read_ESC_LongitudeACC_Valid_ESC_LongitudeACC_Valid);
    /* Rte_Read_ESC_LongitudeACC_Valid_ESC_LongitudeACC_Valid User Code start*/

    /* Rte_Read_ESC_LongitudeACC_Valid_ESC_LongitudeACC_Valid User Code end*/
    Rte_Read_ESC_MasterCylinderPressureV_ESC_MasterCylinderPressureV(&Read_ESC_MasterCylinderPressureV_ESC_MasterCylinderPressureV);
    /* Rte_Read_ESC_MasterCylinderPressureV_ESC_MasterCylinderPressureV User Code start*/

    /* Rte_Read_ESC_MasterCylinderPressureV_ESC_MasterCylinderPressureV User Code end*/
    Rte_Read_ESC_MasterCylinderPressure_ESC_MasterCylinderPressure(&Read_ESC_MasterCylinderPressure_ESC_MasterCylinderPressure);
    /* Rte_Read_ESC_MasterCylinderPressure_ESC_MasterCylinderPressure User Code start*/

    /* Rte_Read_ESC_MasterCylinderPressure_ESC_MasterCylinderPressure User Code end*/
    Rte_Read_ESC_TcsCtrlActv_ESC_TcsCtrlActv(&Read_ESC_TcsCtrlActv_ESC_TcsCtrlActv);
    /* Rte_Read_ESC_TcsCtrlActv_ESC_TcsCtrlActv User Code start*/

    /* Rte_Read_ESC_TcsCtrlActv_ESC_TcsCtrlActv User Code end*/
    Rte_Read_ESC_VehDynYawRate_ESC_VehDynYawRate(&Read_ESC_VehDynYawRate_ESC_VehDynYawRate);
    /* Rte_Read_ESC_VehDynYawRate_ESC_VehDynYawRate User Code start*/

    /* Rte_Read_ESC_VehDynYawRate_ESC_VehDynYawRate User Code end*/
    Rte_Read_ESC_VehDynYawRate_Valid_ESC_VehDynYawRate_Valid(&Read_ESC_VehDynYawRate_Valid_ESC_VehDynYawRate_Valid);
    /* Rte_Read_ESC_VehDynYawRate_Valid_ESC_VehDynYawRate_Valid User Code start*/

    /* Rte_Read_ESC_VehDynYawRate_Valid_ESC_VehDynYawRate_Valid User Code end*/
    Rte_Read_GPSSystAtv_GPSSystAtv(&Read_GPSSystAtv_GPSSystAtv);
    /* Rte_Read_GPSSystAtv_GPSSystAtv User Code start*/

    /* Rte_Read_GPSSystAtv_GPSSystAtv User Code end*/
    Rte_Read_IBS_ESCOFF_StsFB_IBS_ESCOFF_StsFB(&Read_IBS_ESCOFF_StsFB_IBS_ESCOFF_StsFB);
    /* Rte_Read_IBS_ESCOFF_StsFB_IBS_ESCOFF_StsFB User Code start*/

    /* Rte_Read_IBS_ESCOFF_StsFB_IBS_ESCOFF_StsFB User Code end*/
    Rte_Read_IPC_IPCTotalOdometerV_IPC_IPCTotalOdometerV(&Read_IPC_IPCTotalOdometerV_IPC_IPCTotalOdometerV);
    /* Rte_Read_IPC_IPCTotalOdometerV_IPC_IPCTotalOdometerV User Code start*/

    /* Rte_Read_IPC_IPCTotalOdometerV_IPC_IPCTotalOdometerV User Code end*/
    Rte_Read_IPC_IPCTotalOdometer_IPC_IPCTotalOdometer(&Read_IPC_IPCTotalOdometer_IPC_IPCTotalOdometer);
    /* Rte_Read_IPC_IPCTotalOdometer_IPC_IPCTotalOdometer User Code start*/

    /* Rte_Read_IPC_IPCTotalOdometer_IPC_IPCTotalOdometer User Code end*/
    Rte_Read_MFS_ACC_CruiseCancel_MFS_ACC_CruiseCancel(&Read_MFS_ACC_CruiseCancel_MFS_ACC_CruiseCancel);
    /* Rte_Read_MFS_ACC_CruiseCancel_MFS_ACC_CruiseCancel User Code start*/

    /* Rte_Read_MFS_ACC_CruiseCancel_MFS_ACC_CruiseCancel User Code end*/
    Rte_Read_MFS_ACC_CruiseGapSet_MFS_ACC_CruiseGapSet(&Read_MFS_ACC_CruiseGapSet_MFS_ACC_CruiseGapSet);
    /* Rte_Read_MFS_ACC_CruiseGapSet_MFS_ACC_CruiseGapSet User Code start*/

    /* Rte_Read_MFS_ACC_CruiseGapSet_MFS_ACC_CruiseGapSet User Code end*/
    Rte_Read_MFS_ACC_CruiseOn_Off_MFS_ACC_CruiseOn_Off(&Read_MFS_ACC_CruiseOn_Off_MFS_ACC_CruiseOn_Off);
    /* Rte_Read_MFS_ACC_CruiseOn_Off_MFS_ACC_CruiseOn_Off User Code start*/

    /* Rte_Read_MFS_ACC_CruiseOn_Off_MFS_ACC_CruiseOn_Off User Code end*/
    Rte_Read_MFS_ACC_CruiseSpdDecrease_MFS_ACC_CruiseSpdDecrease(&Read_MFS_ACC_CruiseSpdDecrease_MFS_ACC_CruiseSpdDecrease);
    /* Rte_Read_MFS_ACC_CruiseSpdDecrease_MFS_ACC_CruiseSpdDecrease User Code start*/

    /* Rte_Read_MFS_ACC_CruiseSpdDecrease_MFS_ACC_CruiseSpdDecrease User Code end*/
    Rte_Read_MFS_ACC_CruiseSpdIncrease_MFS_ACC_CruiseSpdIncrease(&Read_MFS_ACC_CruiseSpdIncrease_MFS_ACC_CruiseSpdIncrease);
    /* Rte_Read_MFS_ACC_CruiseSpdIncrease_MFS_ACC_CruiseSpdIncrease User Code start*/

    /* Rte_Read_MFS_ACC_CruiseSpdIncrease_MFS_ACC_CruiseSpdIncrease User Code end*/
    Rte_Read_MHU_DM_SwitchModeSts_MHU_DM_SwitchModeSts(&Read_MHU_DM_SwitchModeSts_MHU_DM_SwitchModeSts);
    /* Rte_Read_MHU_DM_SwitchModeSts_MHU_DM_SwitchModeSts User Code start*/

    /* Rte_Read_MHU_DM_SwitchModeSts_MHU_DM_SwitchModeSts User Code end*/
    Rte_Read_MHU_LSS_Mode_MHU_LSS_Mode(&Read_MHU_LSS_Mode_MHU_LSS_Mode);
    /* Rte_Read_MHU_LSS_Mode_MHU_LSS_Mode User Code start*/

    /* Rte_Read_MHU_LSS_Mode_MHU_LSS_Mode User Code end*/
    Rte_Read_MHU_LSS_Req_MHU_LSS_Req(&Read_MHU_LSS_Req_MHU_LSS_Req);
    /* Rte_Read_MHU_LSS_Req_MHU_LSS_Req User Code start*/

    /* Rte_Read_MHU_LSS_Req_MHU_LSS_Req User Code end*/
    Rte_Read_MHU_LSS_WarningMethod_MHU_LSS_WarningMethod(&Read_MHU_LSS_WarningMethod_MHU_LSS_WarningMethod);
    /* Rte_Read_MHU_LSS_WarningMethod_MHU_LSS_WarningMethod User Code start*/

    /* Rte_Read_MHU_LSS_WarningMethod_MHU_LSS_WarningMethod User Code end*/
    Rte_Read_MHU_TSR_Req_MHU_TSR_Req(&Read_MHU_TSR_Req_MHU_TSR_Req);
    /* Rte_Read_MHU_TSR_Req_MHU_TSR_Req User Code start*/

    /* Rte_Read_MHU_TSR_Req_MHU_TSR_Req User Code end*/
    Rte_Read_MHU_Trailermode_Req_MHU_Trailermode_Req(&Read_MHU_Trailermode_Req_MHU_Trailermode_Req);
    /* Rte_Read_MHU_Trailermode_Req_MHU_Trailermode_Req User Code start*/

    /* Rte_Read_MHU_Trailermode_Req_MHU_Trailermode_Req User Code end*/
    Rte_Read_Nav_CtryType_Nav_CtryType(&Read_Nav_CtryType_Nav_CtryType);
    /* Rte_Read_Nav_CtryType_Nav_CtryType User Code start*/

    /* Rte_Read_Nav_CtryType_Nav_CtryType User Code end*/
    Rte_Read_Nav_RoadType_Nav_RoadType(&Read_Nav_RoadType_Nav_RoadType);
    /* Rte_Read_Nav_RoadType_Nav_RoadType User Code start*/

    /* Rte_Read_Nav_RoadType_Nav_RoadType User Code end*/
    Rte_Read_Nav_SpdLimType_Nav_SpdLimType(&Read_Nav_SpdLimType_Nav_SpdLimType);
    /* Rte_Read_Nav_SpdLimType_Nav_SpdLimType User Code start*/

    /* Rte_Read_Nav_SpdLimType_Nav_SpdLimType User Code end*/
    Rte_Read_Nav_SpdLimUnit_Nav_SpdLimUnit(&Read_Nav_SpdLimUnit_Nav_SpdLimUnit);
    /* Rte_Read_Nav_SpdLimUnit_Nav_SpdLimUnit User Code start*/

    /* Rte_Read_Nav_SpdLimUnit_Nav_SpdLimUnit User Code end*/
    Rte_Read_Nav_SpdLimValue_Nav_SpdLimValue(&Read_Nav_SpdLimValue_Nav_SpdLimValue);
    /* Rte_Read_Nav_SpdLimValue_Nav_SpdLimValue User Code start*/

    /* Rte_Read_Nav_SpdLimValue_Nav_SpdLimValue User Code end*/
    Rte_Read_Nav_TSRTrafSign_Nav_TSRTrafSign(&Read_Nav_TSRTrafSign_Nav_TSRTrafSign);
    /* Rte_Read_Nav_TSRTrafSign_Nav_TSRTrafSign User Code start*/

    /* Rte_Read_Nav_TSRTrafSign_Nav_TSRTrafSign User Code end*/
    Rte_Read_Nav_VehToTrafEyeDist_Nav_VehToTrafEyeDist(&Read_Nav_VehToTrafEyeDist_Nav_VehToTrafEyeDist);
    /* Rte_Read_Nav_VehToTrafEyeDist_Nav_VehToTrafEyeDist User Code start*/

    /* Rte_Read_Nav_VehToTrafEyeDist_Nav_VehToTrafEyeDist User Code end*/
    Rte_Read_Nav_errorSts_Nav_errorSts(&Read_Nav_errorSts_Nav_errorSts);
    /* Rte_Read_Nav_errorSts_Nav_errorSts User Code start*/

    /* Rte_Read_Nav_errorSts_Nav_errorSts User Code end*/
    Rte_Read_PEPS_PowerModeValidity_PEPS_PowerModeValidity(&Read_PEPS_PowerModeValidity_PEPS_PowerModeValidity);
    /* Rte_Read_PEPS_PowerModeValidity_PEPS_PowerModeValidity User Code start*/

    /* Rte_Read_PEPS_PowerModeValidity_PEPS_PowerModeValidity User Code end*/
    Rte_Read_PEPS_PowerMode_PEPS_PowerMode(&Read_PEPS_PowerMode_PEPS_PowerMode);
    /* Rte_Read_PEPS_PowerMode_PEPS_PowerMode User Code start*/

    /* Rte_Read_PEPS_PowerMode_PEPS_PowerMode User Code end*/
    Rte_Read_PiADAS_CAN_Output_ADAS_CAN_Output(&Read_PiADAS_CAN_Output_ADAS_CAN_Output);
    /* Rte_Read_PiADAS_CAN_Output_ADAS_CAN_Output User Code start*/

    /* Rte_Read_PiADAS_CAN_Output_ADAS_CAN_Output User Code end*/
    Rte_Read_RCTA_FuncSWReq_RCTA_FuncSWReq(&Read_RCTA_FuncSWReq_RCTA_FuncSWReq);
    /* Rte_Read_RCTA_FuncSWReq_RCTA_FuncSWReq User Code start*/

    /* Rte_Read_RCTA_FuncSWReq_RCTA_FuncSWReq User Code end*/
    Rte_Read_RCW_FuncSWReq_RCW_FuncSWReq(&Read_RCW_FuncSWReq_RCW_FuncSWReq);
    /* Rte_Read_RCW_FuncSWReq_RCW_FuncSWReq User Code start*/

    /* Rte_Read_RCW_FuncSWReq_RCW_FuncSWReq User Code end*/
    Rte_Read_RLS_Rainfall_magnitude_RLS_Rainfall_magnitude(&Read_RLS_Rainfall_magnitude_RLS_Rainfall_magnitude);
    /* Rte_Read_RLS_Rainfall_magnitude_RLS_Rainfall_magnitude User Code start*/

    /* Rte_Read_RLS_Rainfall_magnitude_RLS_Rainfall_magnitude User Code end*/
    Rte_Read_SAS_Calibrated_SAS_Calibrated(&Read_SAS_Calibrated_SAS_Calibrated);
    /* Rte_Read_SAS_Calibrated_SAS_Calibrated User Code start*/

    /* Rte_Read_SAS_Calibrated_SAS_Calibrated User Code end*/
    Rte_Read_SAS_SASFailure_SAS_SASFailure(&Read_SAS_SASFailure_SAS_SASFailure);
    /* Rte_Read_SAS_SASFailure_SAS_SASFailure User Code start*/

    /* Rte_Read_SAS_SASFailure_SAS_SASFailure User Code end*/
    Rte_Read_SAS_SteerWheelAngle_SAS_SteerWheelAngle(&Read_SAS_SteerWheelAngle_SAS_SteerWheelAngle);
    /* Rte_Read_SAS_SteerWheelAngle_SAS_SteerWheelAngle User Code start*/

    /* Rte_Read_SAS_SteerWheelAngle_SAS_SteerWheelAngle User Code end*/
    Rte_Read_SAS_SteerWhlRotSpdStatus_SAS_SteerWhlRotSpdStatus(&Read_SAS_SteerWhlRotSpdStatus_SAS_SteerWhlRotSpdStatus);
    /* Rte_Read_SAS_SteerWhlRotSpdStatus_SAS_SteerWhlRotSpdStatus User Code start*/

    /* Rte_Read_SAS_SteerWhlRotSpdStatus_SAS_SteerWhlRotSpdStatus User Code end*/
    Rte_Read_SAS_SteerWhlRotSpd_SAS_SteerWhlRotSpd(&Read_SAS_SteerWhlRotSpd_SAS_SteerWhlRotSpd);
    /* Rte_Read_SAS_SteerWhlRotSpd_SAS_SteerWhlRotSpd User Code start*/

    /* Rte_Read_SAS_SteerWhlRotSpd_SAS_SteerWhlRotSpd User Code end*/
    Rte_Read_SAS_SteeringAngleValid_SAS_SteeringAngleValid(&Read_SAS_SteeringAngleValid_SAS_SteeringAngleValid);
    /* Rte_Read_SAS_SteeringAngleValid_SAS_SteeringAngleValid User Code start*/

    /* Rte_Read_SAS_SteeringAngleValid_SAS_SteeringAngleValid User Code end*/
    Rte_Read_Signal_Group_ARS_OD_00_01_Signal_Group_ARS_OD_00_01(&Read_Signal_Group_ARS_OD_00_01_Signal_Group_ARS_OD_00_01);
    /* Rte_Read_Signal_Group_ARS_OD_00_01_Signal_Group_ARS_OD_00_01 User Code start*/

    /* Rte_Read_Signal_Group_ARS_OD_00_01_Signal_Group_ARS_OD_00_01 User Code end*/
    Rte_Read_Signal_Group_ARS_OD_02_03_Signal_Group_ARS_OD_02_03(&Read_Signal_Group_ARS_OD_02_03_Signal_Group_ARS_OD_02_03);
    /* Rte_Read_Signal_Group_ARS_OD_02_03_Signal_Group_ARS_OD_02_03 User Code start*/

    /* Rte_Read_Signal_Group_ARS_OD_02_03_Signal_Group_ARS_OD_02_03 User Code end*/
    Rte_Read_Signal_Group_ARS_OD_04_05_Signal_Group_ARS_OD_04_05(&Read_Signal_Group_ARS_OD_04_05_Signal_Group_ARS_OD_04_05);
    /* Rte_Read_Signal_Group_ARS_OD_04_05_Signal_Group_ARS_OD_04_05 User Code start*/

    /* Rte_Read_Signal_Group_ARS_OD_04_05_Signal_Group_ARS_OD_04_05 User Code end*/
    Rte_Read_Signal_Group_ARS_OD_06_07_Signal_Group_ARS_OD_06_07(&Read_Signal_Group_ARS_OD_06_07_Signal_Group_ARS_OD_06_07);
    /* Rte_Read_Signal_Group_ARS_OD_06_07_Signal_Group_ARS_OD_06_07 User Code start*/

    /* Rte_Read_Signal_Group_ARS_OD_06_07_Signal_Group_ARS_OD_06_07 User Code end*/
    Rte_Read_Signal_Group_ARS_OD_08_09_Signal_Group_ARS_OD_08_09(&Read_Signal_Group_ARS_OD_08_09_Signal_Group_ARS_OD_08_09);
    /* Rte_Read_Signal_Group_ARS_OD_08_09_Signal_Group_ARS_OD_08_09 User Code start*/

    /* Rte_Read_Signal_Group_ARS_OD_08_09_Signal_Group_ARS_OD_08_09 User Code end*/
    Rte_Read_Signal_Group_ARS_OD_10_11_Signal_Group_ARS_OD_10_11(&Read_Signal_Group_ARS_OD_10_11_Signal_Group_ARS_OD_10_11);
    /* Rte_Read_Signal_Group_ARS_OD_10_11_Signal_Group_ARS_OD_10_11 User Code start*/

    /* Rte_Read_Signal_Group_ARS_OD_10_11_Signal_Group_ARS_OD_10_11 User Code end*/
    Rte_Read_Signal_Group_ARS_OD_12_13_Signal_Group_ARS_OD_12_13(&Read_Signal_Group_ARS_OD_12_13_Signal_Group_ARS_OD_12_13);
    /* Rte_Read_Signal_Group_ARS_OD_12_13_Signal_Group_ARS_OD_12_13 User Code start*/

    /* Rte_Read_Signal_Group_ARS_OD_12_13_Signal_Group_ARS_OD_12_13 User Code end*/
    Rte_Read_Signal_Group_ARS_OD_14_15_Signal_Group_ARS_OD_14_15(&Read_Signal_Group_ARS_OD_14_15_Signal_Group_ARS_OD_14_15);
    /* Rte_Read_Signal_Group_ARS_OD_14_15_Signal_Group_ARS_OD_14_15 User Code start*/

    /* Rte_Read_Signal_Group_ARS_OD_14_15_Signal_Group_ARS_OD_14_15 User Code end*/
    Rte_Read_Signal_Group_ARS_OD_16_17_Signal_Group_ARS_OD_16_17(&Read_Signal_Group_ARS_OD_16_17_Signal_Group_ARS_OD_16_17);
    /* Rte_Read_Signal_Group_ARS_OD_16_17_Signal_Group_ARS_OD_16_17 User Code start*/

    /* Rte_Read_Signal_Group_ARS_OD_16_17_Signal_Group_ARS_OD_16_17 User Code end*/
    Rte_Read_Signal_Group_ARS_OD_18_19_Signal_Group_ARS_OD_18_19(&Read_Signal_Group_ARS_OD_18_19_Signal_Group_ARS_OD_18_19);
    /* Rte_Read_Signal_Group_ARS_OD_18_19_Signal_Group_ARS_OD_18_19 User Code start*/

    /* Rte_Read_Signal_Group_ARS_OD_18_19_Signal_Group_ARS_OD_18_19 User Code end*/
    Rte_Read_Signal_Group_ARS_OD_20_21_Signal_Group_ARS_OD_20_21(&Read_Signal_Group_ARS_OD_20_21_Signal_Group_ARS_OD_20_21);
    /* Rte_Read_Signal_Group_ARS_OD_20_21_Signal_Group_ARS_OD_20_21 User Code start*/

    /* Rte_Read_Signal_Group_ARS_OD_20_21_Signal_Group_ARS_OD_20_21 User Code end*/
    Rte_Read_Signal_Group_ARS_OD_22_23_Signal_Group_ARS_OD_22_23(&Read_Signal_Group_ARS_OD_22_23_Signal_Group_ARS_OD_22_23);
    /* Rte_Read_Signal_Group_ARS_OD_22_23_Signal_Group_ARS_OD_22_23 User Code start*/

    /* Rte_Read_Signal_Group_ARS_OD_22_23_Signal_Group_ARS_OD_22_23 User Code end*/
    Rte_Read_Signal_Group_ARS_OD_24_25_Signal_Group_ARS_OD_24_25(&Read_Signal_Group_ARS_OD_24_25_Signal_Group_ARS_OD_24_25);
    /* Rte_Read_Signal_Group_ARS_OD_24_25_Signal_Group_ARS_OD_24_25 User Code start*/

    /* Rte_Read_Signal_Group_ARS_OD_24_25_Signal_Group_ARS_OD_24_25 User Code end*/
    Rte_Read_Signal_Group_ARS_OD_26_27_Signal_Group_ARS_OD_26_27(&Read_Signal_Group_ARS_OD_26_27_Signal_Group_ARS_OD_26_27);
    /* Rte_Read_Signal_Group_ARS_OD_26_27_Signal_Group_ARS_OD_26_27 User Code start*/

    /* Rte_Read_Signal_Group_ARS_OD_26_27_Signal_Group_ARS_OD_26_27 User Code end*/
    Rte_Read_Signal_Group_ARS_OD_28_29_Signal_Group_ARS_OD_28_29(&Read_Signal_Group_ARS_OD_28_29_Signal_Group_ARS_OD_28_29);
    /* Rte_Read_Signal_Group_ARS_OD_28_29_Signal_Group_ARS_OD_28_29 User Code start*/

    /* Rte_Read_Signal_Group_ARS_OD_28_29_Signal_Group_ARS_OD_28_29 User Code end*/
    Rte_Read_Signal_Group_ARS_OD_30_31_Signal_Group_ARS_OD_30_31(&Read_Signal_Group_ARS_OD_30_31_Signal_Group_ARS_OD_30_31);
    /* Rte_Read_Signal_Group_ARS_OD_30_31_Signal_Group_ARS_OD_30_31 User Code start*/

    /* Rte_Read_Signal_Group_ARS_OD_30_31_Signal_Group_ARS_OD_30_31 User Code end*/
    Rte_Read_TSR_SLWFuncSwtReq_TSR_SLWFuncSwtReq(&Read_TSR_SLWFuncSwtReq_TSR_SLWFuncSwtReq);
    /* Rte_Read_TSR_SLWFuncSwtReq_TSR_SLWFuncSwtReq User Code start*/

    /* Rte_Read_TSR_SLWFuncSwtReq_TSR_SLWFuncSwtReq User Code end*/
    Rte_Read_TSR_SpdWarningOffs_S_TSR_SpdWarningOffs_S(&Read_TSR_SpdWarningOffs_S_TSR_SpdWarningOffs_S);
    /* Rte_Read_TSR_SpdWarningOffs_S_TSR_SpdWarningOffs_S User Code start*/

    /* Rte_Read_TSR_SpdWarningOffs_S_TSR_SpdWarningOffs_S User Code end*/
    Rte_Read_Time_Day_Time_Day(&Read_Time_Day_Time_Day);
    /* Rte_Read_Time_Day_Time_Day User Code start*/

    /* Rte_Read_Time_Day_Time_Day User Code end*/
    Rte_Read_Time_Hour_Time_Hour(&Read_Time_Hour_Time_Hour);
    /* Rte_Read_Time_Hour_Time_Hour User Code start*/

    /* Rte_Read_Time_Hour_Time_Hour User Code end*/
    Rte_Read_Time_Minute_Time_Minute(&Read_Time_Minute_Time_Minute);
    /* Rte_Read_Time_Minute_Time_Minute User Code start*/

    /* Rte_Read_Time_Minute_Time_Minute User Code end*/
    Rte_Read_Time_Month_Time_Month(&Read_Time_Month_Time_Month);
    /* Rte_Read_Time_Month_Time_Month User Code start*/

    /* Rte_Read_Time_Month_Time_Month User Code end*/
    Rte_Read_Time_Year_Time_Year(&Read_Time_Year_Time_Year);
    /* Rte_Read_Time_Year_Time_Year User Code start*/

    /* Rte_Read_Time_Year_Time_Year User Code end*/
    Rte_Read_Time_second_Time_second(&Read_Time_second_Time_second);
    /* Rte_Read_Time_second_Time_second User Code start*/

    /* Rte_Read_Time_second_Time_second User Code end*/
    Rte_Read_VCU_AccPedalPosition_VCU_AccPedalPosition(&Read_VCU_AccPedalPosition_VCU_AccPedalPosition);
    /* Rte_Read_VCU_AccPedalPosition_VCU_AccPedalPosition User Code start*/

    /* Rte_Read_VCU_AccPedalPosition_VCU_AccPedalPosition User Code end*/
    Rte_Read_VCU_AccPedal_Valid_VCU_AccPedal_Valid(&Read_VCU_AccPedal_Valid_VCU_AccPedal_Valid);
    /* Rte_Read_VCU_AccPedal_Valid_VCU_AccPedal_Valid User Code start*/

    /* Rte_Read_VCU_AccPedal_Valid_VCU_AccPedal_Valid User Code end*/
    Rte_Read_VCU_LimpHomeSts_VCU_LimpHomeSts(&Read_VCU_LimpHomeSts_VCU_LimpHomeSts);
    /* Rte_Read_VCU_LimpHomeSts_VCU_LimpHomeSts User Code start*/

    /* Rte_Read_VCU_LimpHomeSts_VCU_LimpHomeSts User Code end*/
    Rte_Read_VCU_ModeGearSts_VCU_ModeGearSts(&Read_VCU_ModeGearSts_VCU_ModeGearSts);
    /* Rte_Read_VCU_ModeGearSts_VCU_ModeGearSts User Code start*/

    /* Rte_Read_VCU_ModeGearSts_VCU_ModeGearSts User Code end*/
    Rte_Read_VCU_Ready_VCU_Ready(&Read_VCU_Ready_VCU_Ready);
    /* Rte_Read_VCU_Ready_VCU_Ready User Code start*/

    /* Rte_Read_VCU_Ready_VCU_Ready User Code end*/
    Rte_Read_VCU_StsAccPedalFault_VCU_StsAccPedalFault(&Read_VCU_StsAccPedalFault_VCU_StsAccPedalFault);
    /* Rte_Read_VCU_StsAccPedalFault_VCU_StsAccPedalFault User Code start*/

    /* Rte_Read_VCU_StsAccPedalFault_VCU_StsAccPedalFault User Code end*/
    Rte_Read_VCU_StsSysFault_VCU_StsSysFault(&Read_VCU_StsSysFault_VCU_StsSysFault);
    /* Rte_Read_VCU_StsSysFault_VCU_StsSysFault User Code start*/

    /* Rte_Read_VCU_StsSysFault_VCU_StsSysFault User Code end*/
    Rte_Read_WCBS_ABAAtv_WCBS_ABAAtv(&Read_WCBS_ABAAtv_WCBS_ABAAtv);
    /* Rte_Read_WCBS_ABAAtv_WCBS_ABAAtv User Code start*/

    /* Rte_Read_WCBS_ABAAtv_WCBS_ABAAtv User Code end*/
    Rte_Read_WCBS_ABAAva_WCBS_ABAAva(&Read_WCBS_ABAAva_WCBS_ABAAva);
    /* Rte_Read_WCBS_ABAAva_WCBS_ABAAva User Code start*/

    /* Rte_Read_WCBS_ABAAva_WCBS_ABAAva User Code end*/
    Rte_Read_WCBS_ABPAtv_WCBS_ABPAtv(&Read_WCBS_ABPAtv_WCBS_ABPAtv);
    /* Rte_Read_WCBS_ABPAtv_WCBS_ABPAtv User Code start*/

    /* Rte_Read_WCBS_ABPAtv_WCBS_ABPAtv User Code end*/
    Rte_Read_WCBS_ABPAva_WCBS_ABPAva(&Read_WCBS_ABPAva_WCBS_ABPAva);
    /* Rte_Read_WCBS_ABPAva_WCBS_ABPAva User Code start*/

    /* Rte_Read_WCBS_ABPAva_WCBS_ABPAva User Code end*/
    Rte_Read_WCBS_ACC_CDD_Active_WCBS_ACC_CDD_Active(&Read_WCBS_ACC_CDD_Active_WCBS_ACC_CDD_Active);
    /* Rte_Read_WCBS_ACC_CDD_Active_WCBS_ACC_CDD_Active User Code start*/

    /* Rte_Read_WCBS_ACC_CDD_Active_WCBS_ACC_CDD_Active User Code end*/
    Rte_Read_WCBS_ACC_CDD_Avl_WCBS_ACC_CDD_Avl(&Read_WCBS_ACC_CDD_Avl_WCBS_ACC_CDD_Avl);
    /* Rte_Read_WCBS_ACC_CDD_Avl_WCBS_ACC_CDD_Avl User Code start*/

    /* Rte_Read_WCBS_ACC_CDD_Avl_WCBS_ACC_CDD_Avl User Code end*/
    Rte_Read_WCBS_ACC_VLC_Active_WCBS_ACC_VLC_Active(&Read_WCBS_ACC_VLC_Active_WCBS_ACC_VLC_Active);
    /* Rte_Read_WCBS_ACC_VLC_Active_WCBS_ACC_VLC_Active User Code start*/

    /* Rte_Read_WCBS_ACC_VLC_Active_WCBS_ACC_VLC_Active User Code end*/
    Rte_Read_WCBS_ACC_VLC_Avl_WCBS_ACC_VLC_Avl(&Read_WCBS_ACC_VLC_Avl_WCBS_ACC_VLC_Avl);
    /* Rte_Read_WCBS_ACC_VLC_Avl_WCBS_ACC_VLC_Avl User Code start*/

    /* Rte_Read_WCBS_ACC_VLC_Avl_WCBS_ACC_VLC_Avl User Code end*/
    Rte_Read_WCBS_AEBAtv_WCBS_AEBAtv(&Read_WCBS_AEBAtv_WCBS_AEBAtv);
    /* Rte_Read_WCBS_AEBAtv_WCBS_AEBAtv User Code start*/

    /* Rte_Read_WCBS_AEBAtv_WCBS_AEBAtv User Code end*/
    Rte_Read_WCBS_AEBAva_WCBS_AEBAva(&Read_WCBS_AEBAva_WCBS_AEBAva);
    /* Rte_Read_WCBS_AEBAva_WCBS_AEBAva User Code start*/

    /* Rte_Read_WCBS_AEBAva_WCBS_AEBAva User Code end*/
    Rte_Read_WCBS_AWBAtv_WCBS_AWBAtv(&Read_WCBS_AWBAtv_WCBS_AWBAtv);
    /* Rte_Read_WCBS_AWBAtv_WCBS_AWBAtv User Code start*/

    /* Rte_Read_WCBS_AWBAtv_WCBS_AWBAtv User Code end*/
    Rte_Read_WCBS_AWBAvl_WCBS_AWBAvl(&Read_WCBS_AWBAvl_WCBS_AWBAvl);
    /* Rte_Read_WCBS_AWBAvl_WCBS_AWBAvl User Code start*/

    /* Rte_Read_WCBS_AWBAvl_WCBS_AWBAvl User Code end*/
    Rte_Read_WCBS_BrkFrcSta_WCBS_BrkFrcSta(&Read_WCBS_BrkFrcSta_WCBS_BrkFrcSta);
    /* Rte_Read_WCBS_BrkFrcSta_WCBS_BrkFrcSta User Code start*/

    /* Rte_Read_WCBS_BrkFrcSta_WCBS_BrkFrcSta User Code end*/
    Rte_Read_WCBS_ESCDeteACCErroSta_WCBS_ESCDeteACCErroSta(&Read_WCBS_ESCDeteACCErroSta_WCBS_ESCDeteACCErroSta);
    /* Rte_Read_WCBS_ESCDeteACCErroSta_WCBS_ESCDeteACCErroSta User Code start*/

    /* Rte_Read_WCBS_ESCDeteACCErroSta_WCBS_ESCDeteACCErroSta User Code end*/
    Rte_Read_WCBS_VStandstillSta_WCBS_VStandstillSta(&Read_WCBS_VStandstillSta_WCBS_VStandstillSta);
    /* Rte_Read_WCBS_VStandstillSta_WCBS_VStandstillSta User Code start*/

    /* Rte_Read_WCBS_VStandstillSta_WCBS_VStandstillSta User Code end*/
    /* Task_Driving_Signal_Transmission_10ms_Feedback User Code start*/

    /* Task_Driving_Signal_Transmission_10ms_Feedback User Code end*/

}
#define CtApDriving_Signal_Transmission_STOP_SEC_CODE
#include "CtApDriving_Signal_Transmission_MemMap.h"




