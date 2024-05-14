/*  BEGIN_FILE_HDR
********************************************************************************
*   File Name       : Rte_CtApDriving_Signal_Transmission.h
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
#ifndef RTE_CTAPDRIVING_SIGNAL_TRANSMISSION_H
#define RTE_CTAPDRIVING_SIGNAL_TRANSMISSION_H

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
#include "Rte_CtApDriving_Signal_Transmission_Type.h"
#include "Com.h"
/*******************************************************************************
*   define for a symbolic name of the RunnableEntity.
*******************************************************************************/
#define RTE_RUNNABLE_Driving_Signal_Transmission_Init       Driving_Signal_Transmission_Init
#define RTE_RUNNABLE_Task_Driving_Signal_Transmission_10ms  Task_Driving_Signal_Transmission_10ms

/*******************************************************************************
*   Instance Handle
*******************************************************************************/
#ifndef RTE_CORE
typedef CONSTP2CONST(Rte_CDS_CtApDriving_Signal_Transmission, AUTOMATIC, RTE_CONST) Rte_Instance;
#endif

/*******************************************************************************
*   Macro definition.
*******************************************************************************/
#define Rte_Write_ACC_AdtLowerJerkLimit_ACC_AdtLowerJerkLimit         Rte_Write_CtApDriving_Signal_Transmission_ACC_AdtLowerJerkLimit_ACC_AdtLowerJerkLimit
#define Rte_Write_ACC_AdtUpperJerkLimit_ACC_AdtUpperJerkLimit         Rte_Write_CtApDriving_Signal_Transmission_ACC_AdtUpperJerkLimit_ACC_AdtUpperJerkLimit
#define Rte_Write_ACC_DriveoffReq_ACC_DriveoffReq           Rte_Write_CtApDriving_Signal_Transmission_ACC_DriveoffReq_ACC_DriveoffReq
#define Rte_Write_ACC_TxtInfoForDriver_ACC_TxtInfoForDriver Rte_Write_CtApDriving_Signal_Transmission_ACC_TxtInfoForDriver_ACC_TxtInfoForDriver
#define Rte_Write_ADAS_ACC_BrakePreferred_ADAS_ACC_BrakePreferred     Rte_Write_CtApDriving_Signal_Transmission_ADAS_ACC_BrakePreferred_ADAS_ACC_BrakePreferred
#define Rte_Write_ADAS_ACC_DistanceLevel_ADAS_ACC_DistanceLevel       Rte_Write_CtApDriving_Signal_Transmission_ADAS_ACC_DistanceLevel_ADAS_ACC_DistanceLevel
#define Rte_Write_ADAS_ACC_ObjDispSts_ADAS_ACC_ObjDispSts   Rte_Write_CtApDriving_Signal_Transmission_ADAS_ACC_ObjDispSts_ADAS_ACC_ObjDispSts
#define Rte_Write_ADAS_ACC_OperatingSts_ADAS_ACC_OperatingSts         Rte_Write_CtApDriving_Signal_Transmission_ADAS_ACC_OperatingSts_ADAS_ACC_OperatingSts
#define Rte_Write_ADAS_ACC_SpdUnit_ADAS_ACC_SpdUnit         Rte_Write_CtApDriving_Signal_Transmission_ADAS_ACC_SpdUnit_ADAS_ACC_SpdUnit
#define Rte_Write_ADAS_ACC_TakeOverReq_ADAS_ACC_TakeOverReq Rte_Write_CtApDriving_Signal_Transmission_ADAS_ACC_TakeOverReq_ADAS_ACC_TakeOverReq
#define Rte_Write_ADAS_ACC_TargetSpeed_ADAS_ACC_TargetSpeed Rte_Write_CtApDriving_Signal_Transmission_ADAS_ACC_TargetSpeed_ADAS_ACC_TargetSpeed
#define Rte_Write_ADAS_ACC_TimeGapLevel_ADAS_ACC_TimeGapLevel         Rte_Write_CtApDriving_Signal_Transmission_ADAS_ACC_TimeGapLevel_ADAS_ACC_TimeGapLevel
#define Rte_Write_ADAS_AEB_AbaLevel_ADAS_AEB_AbaLevel       Rte_Write_CtApDriving_Signal_Transmission_ADAS_AEB_AbaLevel_ADAS_AEB_AbaLevel
#define Rte_Write_ADAS_AEB_AbpReq_ADAS_AEB_AbpReq           Rte_Write_CtApDriving_Signal_Transmission_ADAS_AEB_AbpReq_ADAS_AEB_AbpReq
#define Rte_Write_ADAS_AEB_FuncSWResp_ADAS_AEB_FuncSWResp   Rte_Write_CtApDriving_Signal_Transmission_ADAS_AEB_FuncSWResp_ADAS_AEB_FuncSWResp
#define Rte_Write_ADAS_AEB_TgtDecel_ReqValue_ADAS_AEB_TgtDecel_ReqValue         Rte_Write_CtApDriving_Signal_Transmission_ADAS_AEB_TgtDecel_ReqValue_ADAS_AEB_TgtDecel_ReqValue
#define Rte_Write_ADAS_AccelerationReq_ADAS_AccelerationReq Rte_Write_CtApDriving_Signal_Transmission_ADAS_AccelerationReq_ADAS_AccelerationReq
#define Rte_Write_ADAS_EPS_AngReqSts_ADAS_EPS_AngReqSts     Rte_Write_CtApDriving_Signal_Transmission_ADAS_EPS_AngReqSts_ADAS_EPS_AngReqSts
#define Rte_Write_ADAS_EPS_TargetSteeringAngle_ADAS_EPS_TargetSteeringAngle     Rte_Write_CtApDriving_Signal_Transmission_ADAS_EPS_TargetSteeringAngle_ADAS_EPS_TargetSteeringAngle
#define Rte_Write_ADAS_EPS_Vibration_Req_ADAS_EPS_Vibration_Req       Rte_Write_CtApDriving_Signal_Transmission_ADAS_EPS_Vibration_Req_ADAS_EPS_Vibration_Req
#define Rte_Write_ADAS_IBS_CarStarting_ADAS_IBS_CarStarting Rte_Write_CtApDriving_Signal_Transmission_ADAS_IBS_CarStarting_ADAS_IBS_CarStarting
#define Rte_Write_ADAS_IBS_EBAReq_ADAS_IBS_EBAReq           Rte_Write_CtApDriving_Signal_Transmission_ADAS_IBS_EBAReq_ADAS_IBS_EBAReq
#define Rte_Write_ADAS_IBS_MinBreakReq_ADAS_IBS_MinBreakReq Rte_Write_CtApDriving_Signal_Transmission_ADAS_IBS_MinBreakReq_ADAS_IBS_MinBreakReq
#define Rte_Write_ADAS_IBS_StopReq_ADAS_IBS_StopReq         Rte_Write_CtApDriving_Signal_Transmission_ADAS_IBS_StopReq_ADAS_IBS_StopReq
#define Rte_Write_ADAS_LSS_AngCmdReqPortnValue_ADAS_LSS_AngCmdReqPortnValue     Rte_Write_CtApDriving_Signal_Transmission_ADAS_LSS_AngCmdReqPortnValue_ADAS_LSS_AngCmdReqPortnValue
#define Rte_Write_ADAS_LSS_AssidFormResp_ADAS_LSS_AssidFormResp       Rte_Write_CtApDriving_Signal_Transmission_ADAS_LSS_AssidFormResp_ADAS_LSS_AssidFormResp
#define Rte_Write_ADAS_LSS_Available_ADAS_LSS_Available     Rte_Write_CtApDriving_Signal_Transmission_ADAS_LSS_Available_ADAS_LSS_Available
#define Rte_Write_ADAS_LSS_ErrSts_ADAS_LSS_ErrSts           Rte_Write_CtApDriving_Signal_Transmission_ADAS_LSS_ErrSts_ADAS_LSS_ErrSts
#define Rte_Write_ADAS_LSS_FunSts_ADAS_LSS_FunSts           Rte_Write_CtApDriving_Signal_Transmission_ADAS_LSS_FunSts_ADAS_LSS_FunSts
#define Rte_Write_ADAS_LSS_FuncResp_ADAS_LSS_FuncResp       Rte_Write_CtApDriving_Signal_Transmission_ADAS_LSS_FuncResp_ADAS_LSS_FuncResp
#define Rte_Write_ADAS_LSS_HandsoffWarn_ADAS_LSS_HandsoffWarn         Rte_Write_CtApDriving_Signal_Transmission_ADAS_LSS_HandsoffWarn_ADAS_LSS_HandsoffWarn
#define Rte_Write_ADAS_LSS_LeLineTrackingSts_ADAS_LSS_LeLineTrackingSts         Rte_Write_CtApDriving_Signal_Transmission_ADAS_LSS_LeLineTrackingSts_ADAS_LSS_LeLineTrackingSts
#define Rte_Write_ADAS_LSS_RiLineTrackingSts_ADAS_LSS_RiLineTrackingSts         Rte_Write_CtApDriving_Signal_Transmission_ADAS_LSS_RiLineTrackingSts_ADAS_LSS_RiLineTrackingSts
#define Rte_Write_ADAS_LSS_VoiceWarn_ADAS_LSS_VoiceWarn     Rte_Write_CtApDriving_Signal_Transmission_ADAS_LSS_VoiceWarn_ADAS_LSS_VoiceWarn
#define Rte_Write_ADAS_LSS_WarnFromResp_ADAS_LSS_WarnFromResp         Rte_Write_CtApDriving_Signal_Transmission_ADAS_LSS_WarnFromResp_ADAS_LSS_WarnFromResp
#define Rte_Write_ADAS_MaxSoftAcceleration_ADAS_MaxSoftAcceleration   Rte_Write_CtApDriving_Signal_Transmission_ADAS_MaxSoftAcceleration_ADAS_MaxSoftAcceleration
#define Rte_Write_ADAS_MinSoftAcceleration_ADAS_MinSoftAcceleration   Rte_Write_CtApDriving_Signal_Transmission_ADAS_MinSoftAcceleration_ADAS_MinSoftAcceleration
#define Rte_Write_ADAS_TSR_OperationSts_ADAS_TSR_OperationSts         Rte_Write_CtApDriving_Signal_Transmission_ADAS_TSR_OperationSts_ADAS_TSR_OperationSts
#define Rte_Write_ADAS_TSR_SWSts_ADAS_TSR_SWSts             Rte_Write_CtApDriving_Signal_Transmission_ADAS_TSR_SWSts_ADAS_TSR_SWSts
#define Rte_Write_ADAS_TSR_SpeedLimit_ADAS_TSR_SpeedLimit   Rte_Write_CtApDriving_Signal_Transmission_ADAS_TSR_SpeedLimit_ADAS_TSR_SpeedLimit
#define Rte_Write_ADAS_VLCModeReq_ADAS_VLCModeReq           Rte_Write_CtApDriving_Signal_Transmission_ADAS_VLCModeReq_ADAS_VLCModeReq
#define Rte_Write_ADAS_VLCShutDownReq_ADAS_VLCShutDownReq   Rte_Write_CtApDriving_Signal_Transmission_ADAS_VLCShutDownReq_ADAS_VLCShutDownReq
#define Rte_Write_AEB_ABA_Req_AEB_ABA_Req                   Rte_Write_CtApDriving_Signal_Transmission_AEB_ABA_Req_AEB_ABA_Req
#define Rte_Write_AEB_AWB_Level_AEB_AWB_Level               Rte_Write_CtApDriving_Signal_Transmission_AEB_AWB_Level_AEB_AWB_Level
#define Rte_Write_AEB_AWB_Req_AEB_AWB_Req                   Rte_Write_CtApDriving_Signal_Transmission_AEB_AWB_Req_AEB_AWB_Req
#define Rte_Write_AEB_ErrorSts_AEB_ErrorSts                 Rte_Write_CtApDriving_Signal_Transmission_AEB_ErrorSts_AEB_ErrorSts
#define Rte_Write_AEB_FCW_Warning_AEB_FCW_Warning           Rte_Write_CtApDriving_Signal_Transmission_AEB_FCW_Warning_AEB_FCW_Warning
#define Rte_Write_AEB_FuncSts_AEB_FuncSts                   Rte_Write_CtApDriving_Signal_Transmission_AEB_FuncSts_AEB_FuncSts
#define Rte_Write_AEB_TgtDecel_Req_AEB_TgtDecel_Req         Rte_Write_CtApDriving_Signal_Transmission_AEB_TgtDecel_Req_AEB_TgtDecel_Req
#define Rte_Write_AEB_VRUActive_AEB_VRUActive               Rte_Write_CtApDriving_Signal_Transmission_AEB_VRUActive_AEB_VRUActive
#define Rte_Write_AEB_VehActive_AEB_VehActive               Rte_Write_CtApDriving_Signal_Transmission_AEB_VehActive_AEB_VehActive
#define Rte_Write_AEB_VehHldReq_AEB_VehHldReq               Rte_Write_CtApDriving_Signal_Transmission_AEB_VehHldReq_AEB_VehHldReq
#define Rte_Write_AEB_FCW_SnvtyResp_AEB_FCW_SnvtyResp       Rte_Write_CtApDriving_Signal_Transmission_AEB_FCW_SnvtyResp_AEB_FCW_SnvtyResp
#define Rte_Write_FC_BlockageSts_FC_BlockageSts             Rte_Write_CtApDriving_Signal_Transmission_FC_BlockageSts_FC_BlockageSts
#define Rte_Write_FC_CalibrationSts_FC_CalibrationSts       Rte_Write_CtApDriving_Signal_Transmission_FC_CalibrationSts_FC_CalibrationSts
#define Rte_Write_PiFrontRadarInfo_PiFrontRadarInfo         Rte_Write_CtApDriving_Signal_Transmission_PiFrontRadarInfo_PiFrontRadarInfo
#define Rte_Write_TSR_SLWSwtResp_TSR_SLWSwtResp             Rte_Write_CtApDriving_Signal_Transmission_TSR_SLWSwtResp_TSR_SLWSwtResp
#define Rte_Write_TSR_SLWVisualWarn_TSR_SLWVisualWarn       Rte_Write_CtApDriving_Signal_Transmission_TSR_SLWVisualWarn_TSR_SLWVisualWarn
#define Rte_Write_TSR_SLWVoiceWarn_TSR_SLWVoiceWarn         Rte_Write_CtApDriving_Signal_Transmission_TSR_SLWVoiceWarn_TSR_SLWVoiceWarn
#define Rte_Write_TSR_SpdAssistInfoDisp_TSR_SpdAssistInfoDisp         Rte_Write_CtApDriving_Signal_Transmission_TSR_SpdAssistInfoDisp_TSR_SpdAssistInfoDisp
#define Rte_Write_TSR_TrafSign_TSR_TrafSign                 Rte_Write_CtApDriving_Signal_Transmission_TSR_TrafSign_TSR_TrafSign
#define Rte_Write_TSR_Warning_offset_TSR_Warning_offset     Rte_Write_CtApDriving_Signal_Transmission_TSR_Warning_offset_TSR_Warning_offset
#define Rte_Write_PiVehicleInfo_PiVehicleInfo               Rte_Write_CtApDriving_Signal_Transmission_PiVehicleInfo_PiVehicleInfo
#define Rte_Read_ABSActive_ABSActive                        Rte_Read_CtApDriving_Signal_Transmission_ABSActive_ABSActive
#define Rte_Read_ABS_FLWheelDirection_ABS_FLWheelDirection  Rte_Read_CtApDriving_Signal_Transmission_ABS_FLWheelDirection_ABS_FLWheelDirection
#define Rte_Read_ABS_FLWheelSpeedInvalid_ABS_FLWheelSpeedInvalid      Rte_Read_CtApDriving_Signal_Transmission_ABS_FLWheelSpeedInvalid_ABS_FLWheelSpeedInvalid
#define Rte_Read_ABS_FLWheelSpeedKPH_ABS_FLWheelSpeedKPH    Rte_Read_CtApDriving_Signal_Transmission_ABS_FLWheelSpeedKPH_ABS_FLWheelSpeedKPH
#define Rte_Read_ABS_FRWheelDirection_ABS_FRWheelDirection  Rte_Read_CtApDriving_Signal_Transmission_ABS_FRWheelDirection_ABS_FRWheelDirection
#define Rte_Read_ABS_FRWheelSpeedInvalid_ABS_FRWheelSpeedInvalid      Rte_Read_CtApDriving_Signal_Transmission_ABS_FRWheelSpeedInvalid_ABS_FRWheelSpeedInvalid
#define Rte_Read_ABS_FRWheelSpeedKPH_ABS_FRWheelSpeedKPH    Rte_Read_CtApDriving_Signal_Transmission_ABS_FRWheelSpeedKPH_ABS_FRWheelSpeedKPH
#define Rte_Read_ABS_RLWheelDirection_ABS_RLWheelDirection  Rte_Read_CtApDriving_Signal_Transmission_ABS_RLWheelDirection_ABS_RLWheelDirection
#define Rte_Read_ABS_RLWheelSpeedInvalid_ABS_RLWheelSpeedInvalid      Rte_Read_CtApDriving_Signal_Transmission_ABS_RLWheelSpeedInvalid_ABS_RLWheelSpeedInvalid
#define Rte_Read_ABS_RLWheelSpeedKPH_ABS_RLWheelSpeedKPH    Rte_Read_CtApDriving_Signal_Transmission_ABS_RLWheelSpeedKPH_ABS_RLWheelSpeedKPH
#define Rte_Read_ABS_RRWheelDirection_ABS_RRWheelDirection  Rte_Read_CtApDriving_Signal_Transmission_ABS_RRWheelDirection_ABS_RRWheelDirection
#define Rte_Read_ABS_RRWheelSpeedInvalid_ABS_RRWheelSpeedInvalid      Rte_Read_CtApDriving_Signal_Transmission_ABS_RRWheelSpeedInvalid_ABS_RRWheelSpeedInvalid
#define Rte_Read_ABS_RRWheelSpeedKPH_ABS_RRWheelSpeedKPH    Rte_Read_CtApDriving_Signal_Transmission_ABS_RRWheelSpeedKPH_ABS_RRWheelSpeedKPH
#define Rte_Read_ABS_VehicleSpeedInvalid_ABS_VehicleSpeedInvalid      Rte_Read_CtApDriving_Signal_Transmission_ABS_VehicleSpeedInvalid_ABS_VehicleSpeedInvalid
#define Rte_Read_ABS_VehicleSpeed_ABS_VehicleSpeed          Rte_Read_CtApDriving_Signal_Transmission_ABS_VehicleSpeed_ABS_VehicleSpeed
#define Rte_Read_AB_BrkPedalPct_AB_BrkPedalPct              Rte_Read_CtApDriving_Signal_Transmission_AB_BrkPedalPct_AB_BrkPedalPct
#define Rte_Read_AB_BrkPedalSwStsV_AB_BrkPedalSwStsV        Rte_Read_CtApDriving_Signal_Transmission_AB_BrkPedalSwStsV_AB_BrkPedalSwStsV
#define Rte_Read_AB_BrkPedalSwSts_AB_BrkPedalSwSts          Rte_Read_CtApDriving_Signal_Transmission_AB_BrkPedalSwSts_AB_BrkPedalSwSts
#define Rte_Read_AB_BrkPedalTravel_AB_BrkPedalTravel        Rte_Read_CtApDriving_Signal_Transmission_AB_BrkPedalTravel_AB_BrkPedalTravel
#define Rte_Read_AB_Fault_Status_AB_Fault_Status            Rte_Read_CtApDriving_Signal_Transmission_AB_Fault_Status_AB_Fault_Status
#define Rte_Read_ACU_CoDSeatbeltBucklestatus_ACU_CoDSeatbeltBucklestatus        Rte_Read_CtApDriving_Signal_Transmission_ACU_CoDSeatbeltBucklestatus_ACU_CoDSeatbeltBucklestatus
#define Rte_Read_ACU_DSeatbeltBucklestatus_ACU_DSeatbeltBucklestatus  Rte_Read_CtApDriving_Signal_Transmission_ACU_DSeatbeltBucklestatus_ACU_DSeatbeltBucklestatus
#define Rte_Read_ADAS_APA_SystemSts_ADAS_APA_SystemSts      Rte_Read_CtApDriving_Signal_Transmission_ADAS_APA_SystemSts_ADAS_APA_SystemSts
#define Rte_Read_AEB_FCW_SnvtyReq_AEB_FCW_SnvtyReq          Rte_Read_CtApDriving_Signal_Transmission_AEB_FCW_SnvtyReq_AEB_FCW_SnvtyReq
#define Rte_Read_AEB_FuncSwtReq_AEB_FuncSwtReq              Rte_Read_CtApDriving_Signal_Transmission_AEB_FuncSwtReq_AEB_FuncSwtReq
#define Rte_Read_ADAS_APA_OperationSts_ADAS_APA_OperationSts          Rte_Read_CtApDriving_Signal_Transmission_ADAS_APA_OperationSts_ADAS_APA_OperationSts
#define Rte_Read_BCM_AutoWipeSts_BCM_AutoWipeSts            Rte_Read_CtApDriving_Signal_Transmission_BCM_AutoWipeSts_BCM_AutoWipeSts
#define Rte_Read_BCM_CodriversSideDoorAjarSts_BCM_CodriversSideDoorAjarSts      Rte_Read_CtApDriving_Signal_Transmission_BCM_CodriversSideDoorAjarSts_BCM_CodriversSideDoorAjarSts
#define Rte_Read_BCM_CoverAjarStatus_BCM_CoverAjarStatus    Rte_Read_CtApDriving_Signal_Transmission_BCM_CoverAjarStatus_BCM_CoverAjarStatus
#define Rte_Read_BCM_DoorLockStatusCodrivres_BCM_DoorLockStatusCodrivres        Rte_Read_CtApDriving_Signal_Transmission_BCM_DoorLockStatusCodrivres_BCM_DoorLockStatusCodrivres
#define Rte_Read_BCM_DoorLockStatusDrv_BCM_DoorLockStatusDrv          Rte_Read_CtApDriving_Signal_Transmission_BCM_DoorLockStatusDrv_BCM_DoorLockStatusDrv
#define Rte_Read_BCM_DoorLockStatusRL_BCM_DoorLockStatusRL  Rte_Read_CtApDriving_Signal_Transmission_BCM_DoorLockStatusRL_BCM_DoorLockStatusRL
#define Rte_Read_BCM_DoorLockStatusRR_BCM_DoorLockStatusRR  Rte_Read_CtApDriving_Signal_Transmission_BCM_DoorLockStatusRR_BCM_DoorLockStatusRR
#define Rte_Read_BCM_DriverSideDoorAjarSts_BCM_DriverSideDoorAjarSts  Rte_Read_CtApDriving_Signal_Transmission_BCM_DriverSideDoorAjarSts_BCM_DriverSideDoorAjarSts
#define Rte_Read_BCM_FrontFogLampLightSts_BCM_FrontFogLampLightSts    Rte_Read_CtApDriving_Signal_Transmission_BCM_FrontFogLampLightSts_BCM_FrontFogLampLightSts
#define Rte_Read_BCM_FrontWipeSWSts_BCM_FrontWipeSWSts      Rte_Read_CtApDriving_Signal_Transmission_BCM_FrontWipeSWSts_BCM_FrontWipeSWSts
#define Rte_Read_BCM_FrontWipeSts_BCM_FrontWipeSts          Rte_Read_CtApDriving_Signal_Transmission_BCM_FrontWipeSts_BCM_FrontWipeSts
#define Rte_Read_BCM_RearLeftDoorAjarStatus_BCM_RearLeftDoorAjarStatus          Rte_Read_CtApDriving_Signal_Transmission_BCM_RearLeftDoorAjarStatus_BCM_RearLeftDoorAjarStatus
#define Rte_Read_BCM_RearRightDoorAjarStatus_BCM_RearRightDoorAjarStatus        Rte_Read_CtApDriving_Signal_Transmission_BCM_RearRightDoorAjarStatus_BCM_RearRightDoorAjarStatus
#define Rte_Read_BCM_TrunckAjarStatus_BCM_TrunckAjarStatus  Rte_Read_CtApDriving_Signal_Transmission_BCM_TrunckAjarStatus_BCM_TrunckAjarStatus
#define Rte_Read_BCM_TurnIndicatorSts_BCM_TurnIndicatorSts  Rte_Read_CtApDriving_Signal_Transmission_BCM_TurnIndicatorSts_BCM_TurnIndicatorSts
#define Rte_Read_BCM_TurnLightSWSts_BCM_TurnLightSWSts      Rte_Read_CtApDriving_Signal_Transmission_BCM_TurnLightSWSts_BCM_TurnLightSWSts
#define Rte_Read_BCM_TurnLight_FaultSts_BCM_TurnLight_FaultSts        Rte_Read_CtApDriving_Signal_Transmission_BCM_TurnLight_FaultSts_BCM_TurnLight_FaultSts
#define Rte_Read_BSD_LCA_FuncSWReq_BSD_LCA_FuncSWReq        Rte_Read_CtApDriving_Signal_Transmission_BSD_LCA_FuncSWReq_BSD_LCA_FuncSWReq
#define Rte_Read_CCU_ExternalTemperature_CCU_ExternalTemperature      Rte_Read_CtApDriving_Signal_Transmission_CCU_ExternalTemperature_CCU_ExternalTemperature
#define Rte_Read_ESC_TcsDisableSts_ESC_TcsDisableSts        Rte_Read_CtApDriving_Signal_Transmission_ESC_TcsDisableSts_ESC_TcsDisableSts
#define Rte_Read_DOW_FuncSWReq_DOW_FuncSWReq                Rte_Read_CtApDriving_Signal_Transmission_DOW_FuncSWReq_DOW_FuncSWReq
#define Rte_Read_EPB_AVHFeedbackSts_EPB_AVHFeedbackSts      Rte_Read_CtApDriving_Signal_Transmission_EPB_AVHFeedbackSts_EPB_AVHFeedbackSts
#define Rte_Read_EPB_AVHStatIndReqV_EPB_AVHStatIndReqV      Rte_Read_CtApDriving_Signal_Transmission_EPB_AVHStatIndReqV_EPB_AVHStatIndReqV
#define Rte_Read_EPS_ADAS_CtrlAbortFeedback_EPS_ADAS_CtrlAbortFeedback          Rte_Read_CtApDriving_Signal_Transmission_EPS_ADAS_CtrlAbortFeedback_EPS_ADAS_CtrlAbortFeedback
#define Rte_Read_EPS_ADAS_ModActv_EPS_ADAS_ModActv          Rte_Read_CtApDriving_Signal_Transmission_EPS_ADAS_ModActv_EPS_ADAS_ModActv
#define Rte_Read_EPS_ADAS_ModAvail_EPS_ADAS_ModAvail        Rte_Read_CtApDriving_Signal_Transmission_EPS_ADAS_ModAvail_EPS_ADAS_ModAvail
#define Rte_Read_EPS_DrStrTorqV_EPS_DrStrTorqV              Rte_Read_CtApDriving_Signal_Transmission_EPS_DrStrTorqV_EPS_DrStrTorqV
#define Rte_Read_EPS_DrStrTorqVal_EPS_DrStrTorqVal          Rte_Read_CtApDriving_Signal_Transmission_EPS_DrStrTorqVal_EPS_DrStrTorqVal
#define Rte_Read_EPS_LKARespTorq_EPS_LKARespTorq            Rte_Read_CtApDriving_Signal_Transmission_EPS_LKARespTorq_EPS_LKARespTorq
#define Rte_Read_EPS_SterFltMod_EPS_SterFltMod              Rte_Read_CtApDriving_Signal_Transmission_EPS_SterFltMod_EPS_SterFltMod
#define Rte_Read_ESC_EscCtrlActv_ESC_EscCtrlActv            Rte_Read_CtApDriving_Signal_Transmission_ESC_EscCtrlActv_ESC_EscCtrlActv
#define Rte_Read_ESC_EscDisableSts_ESC_EscDisableSts        Rte_Read_CtApDriving_Signal_Transmission_ESC_EscDisableSts_ESC_EscDisableSts
#define Rte_Read_ESC_HSA_Control_Status_ESC_HSA_Control_Status        Rte_Read_CtApDriving_Signal_Transmission_ESC_HSA_Control_Status_ESC_HSA_Control_Status
#define Rte_Read_ESC_LateralACC_ESC_LateralACC              Rte_Read_CtApDriving_Signal_Transmission_ESC_LateralACC_ESC_LateralACC
#define Rte_Read_ESC_LateralACC_Valid_ESC_LateralACC_Valid  Rte_Read_CtApDriving_Signal_Transmission_ESC_LateralACC_Valid_ESC_LateralACC_Valid
#define Rte_Read_ESC_LongitudeACC_ESC_LongitudeACC          Rte_Read_CtApDriving_Signal_Transmission_ESC_LongitudeACC_ESC_LongitudeACC
#define Rte_Read_ESC_LongitudeACC_Valid_ESC_LongitudeACC_Valid        Rte_Read_CtApDriving_Signal_Transmission_ESC_LongitudeACC_Valid_ESC_LongitudeACC_Valid
#define Rte_Read_ESC_MasterCylinderPressureV_ESC_MasterCylinderPressureV        Rte_Read_CtApDriving_Signal_Transmission_ESC_MasterCylinderPressureV_ESC_MasterCylinderPressureV
#define Rte_Read_ESC_MasterCylinderPressure_ESC_MasterCylinderPressure          Rte_Read_CtApDriving_Signal_Transmission_ESC_MasterCylinderPressure_ESC_MasterCylinderPressure
#define Rte_Read_ESC_TcsCtrlActv_ESC_TcsCtrlActv            Rte_Read_CtApDriving_Signal_Transmission_ESC_TcsCtrlActv_ESC_TcsCtrlActv
#define Rte_Read_ESC_VehDynYawRate_ESC_VehDynYawRate        Rte_Read_CtApDriving_Signal_Transmission_ESC_VehDynYawRate_ESC_VehDynYawRate
#define Rte_Read_ESC_VehDynYawRate_Valid_ESC_VehDynYawRate_Valid      Rte_Read_CtApDriving_Signal_Transmission_ESC_VehDynYawRate_Valid_ESC_VehDynYawRate_Valid
#define Rte_Read_GPSSystAtv_GPSSystAtv                      Rte_Read_CtApDriving_Signal_Transmission_GPSSystAtv_GPSSystAtv
#define Rte_Read_IBS_ESCOFF_StsFB_IBS_ESCOFF_StsFB          Rte_Read_CtApDriving_Signal_Transmission_IBS_ESCOFF_StsFB_IBS_ESCOFF_StsFB
#define Rte_Read_IPC_IPCTotalOdometerV_IPC_IPCTotalOdometerV          Rte_Read_CtApDriving_Signal_Transmission_IPC_IPCTotalOdometerV_IPC_IPCTotalOdometerV
#define Rte_Read_IPC_IPCTotalOdometer_IPC_IPCTotalOdometer  Rte_Read_CtApDriving_Signal_Transmission_IPC_IPCTotalOdometer_IPC_IPCTotalOdometer
#define Rte_Read_MFS_ACC_CruiseCancel_MFS_ACC_CruiseCancel  Rte_Read_CtApDriving_Signal_Transmission_MFS_ACC_CruiseCancel_MFS_ACC_CruiseCancel
#define Rte_Read_MFS_ACC_CruiseGapSet_MFS_ACC_CruiseGapSet  Rte_Read_CtApDriving_Signal_Transmission_MFS_ACC_CruiseGapSet_MFS_ACC_CruiseGapSet
#define Rte_Read_MFS_ACC_CruiseOn_Off_MFS_ACC_CruiseOn_Off  Rte_Read_CtApDriving_Signal_Transmission_MFS_ACC_CruiseOn_Off_MFS_ACC_CruiseOn_Off
#define Rte_Read_MFS_ACC_CruiseSpdDecrease_MFS_ACC_CruiseSpdDecrease  Rte_Read_CtApDriving_Signal_Transmission_MFS_ACC_CruiseSpdDecrease_MFS_ACC_CruiseSpdDecrease
#define Rte_Read_MFS_ACC_CruiseSpdIncrease_MFS_ACC_CruiseSpdIncrease  Rte_Read_CtApDriving_Signal_Transmission_MFS_ACC_CruiseSpdIncrease_MFS_ACC_CruiseSpdIncrease
#define Rte_Read_MHU_DM_SwitchModeSts_MHU_DM_SwitchModeSts  Rte_Read_CtApDriving_Signal_Transmission_MHU_DM_SwitchModeSts_MHU_DM_SwitchModeSts
#define Rte_Read_MHU_LSS_Mode_MHU_LSS_Mode                  Rte_Read_CtApDriving_Signal_Transmission_MHU_LSS_Mode_MHU_LSS_Mode
#define Rte_Read_MHU_LSS_Req_MHU_LSS_Req                    Rte_Read_CtApDriving_Signal_Transmission_MHU_LSS_Req_MHU_LSS_Req
#define Rte_Read_MHU_LSS_WarningMethod_MHU_LSS_WarningMethod          Rte_Read_CtApDriving_Signal_Transmission_MHU_LSS_WarningMethod_MHU_LSS_WarningMethod
#define Rte_Read_MHU_TSR_Req_MHU_TSR_Req                    Rte_Read_CtApDriving_Signal_Transmission_MHU_TSR_Req_MHU_TSR_Req
#define Rte_Read_MHU_Trailermode_Req_MHU_Trailermode_Req    Rte_Read_CtApDriving_Signal_Transmission_MHU_Trailermode_Req_MHU_Trailermode_Req
#define Rte_Read_Nav_CtryType_Nav_CtryType                  Rte_Read_CtApDriving_Signal_Transmission_Nav_CtryType_Nav_CtryType
#define Rte_Read_Nav_RoadType_Nav_RoadType                  Rte_Read_CtApDriving_Signal_Transmission_Nav_RoadType_Nav_RoadType
#define Rte_Read_Nav_SpdLimType_Nav_SpdLimType              Rte_Read_CtApDriving_Signal_Transmission_Nav_SpdLimType_Nav_SpdLimType
#define Rte_Read_Nav_SpdLimUnit_Nav_SpdLimUnit              Rte_Read_CtApDriving_Signal_Transmission_Nav_SpdLimUnit_Nav_SpdLimUnit
#define Rte_Read_Nav_SpdLimValue_Nav_SpdLimValue            Rte_Read_CtApDriving_Signal_Transmission_Nav_SpdLimValue_Nav_SpdLimValue
#define Rte_Read_Nav_TSRTrafSign_Nav_TSRTrafSign            Rte_Read_CtApDriving_Signal_Transmission_Nav_TSRTrafSign_Nav_TSRTrafSign
#define Rte_Read_Nav_VehToTrafEyeDist_Nav_VehToTrafEyeDist  Rte_Read_CtApDriving_Signal_Transmission_Nav_VehToTrafEyeDist_Nav_VehToTrafEyeDist
#define Rte_Read_Nav_errorSts_Nav_errorSts                  Rte_Read_CtApDriving_Signal_Transmission_Nav_errorSts_Nav_errorSts
#define Rte_Read_PEPS_PowerModeValidity_PEPS_PowerModeValidity        Rte_Read_CtApDriving_Signal_Transmission_PEPS_PowerModeValidity_PEPS_PowerModeValidity
#define Rte_Read_PEPS_PowerMode_PEPS_PowerMode              Rte_Read_CtApDriving_Signal_Transmission_PEPS_PowerMode_PEPS_PowerMode
#define Rte_Read_PiADAS_CAN_Output_ADAS_CAN_Output          Rte_Read_CtApDriving_Signal_Transmission_PiADAS_CAN_Output_ADAS_CAN_Output
#define Rte_Read_RCTA_FuncSWReq_RCTA_FuncSWReq              Rte_Read_CtApDriving_Signal_Transmission_RCTA_FuncSWReq_RCTA_FuncSWReq
#define Rte_Read_RCW_FuncSWReq_RCW_FuncSWReq                Rte_Read_CtApDriving_Signal_Transmission_RCW_FuncSWReq_RCW_FuncSWReq
#define Rte_Read_RLS_Rainfall_magnitude_RLS_Rainfall_magnitude        Rte_Read_CtApDriving_Signal_Transmission_RLS_Rainfall_magnitude_RLS_Rainfall_magnitude
#define Rte_Read_SAS_Calibrated_SAS_Calibrated              Rte_Read_CtApDriving_Signal_Transmission_SAS_Calibrated_SAS_Calibrated
#define Rte_Read_SAS_SASFailure_SAS_SASFailure              Rte_Read_CtApDriving_Signal_Transmission_SAS_SASFailure_SAS_SASFailure
#define Rte_Read_SAS_SteerWheelAngle_SAS_SteerWheelAngle    Rte_Read_CtApDriving_Signal_Transmission_SAS_SteerWheelAngle_SAS_SteerWheelAngle
#define Rte_Read_SAS_SteerWhlRotSpdStatus_SAS_SteerWhlRotSpdStatus    Rte_Read_CtApDriving_Signal_Transmission_SAS_SteerWhlRotSpdStatus_SAS_SteerWhlRotSpdStatus
#define Rte_Read_SAS_SteerWhlRotSpd_SAS_SteerWhlRotSpd      Rte_Read_CtApDriving_Signal_Transmission_SAS_SteerWhlRotSpd_SAS_SteerWhlRotSpd
#define Rte_Read_SAS_SteeringAngleValid_SAS_SteeringAngleValid        Rte_Read_CtApDriving_Signal_Transmission_SAS_SteeringAngleValid_SAS_SteeringAngleValid
#define Rte_Read_Signal_Group_ARS_OD_00_01_Signal_Group_ARS_OD_00_01  Rte_Read_CtApDriving_Signal_Transmission_Signal_Group_ARS_OD_00_01_Signal_Group_ARS_OD_00_01
#define Rte_Read_Signal_Group_ARS_OD_02_03_Signal_Group_ARS_OD_02_03  Rte_Read_CtApDriving_Signal_Transmission_Signal_Group_ARS_OD_02_03_Signal_Group_ARS_OD_02_03
#define Rte_Read_Signal_Group_ARS_OD_04_05_Signal_Group_ARS_OD_04_05  Rte_Read_CtApDriving_Signal_Transmission_Signal_Group_ARS_OD_04_05_Signal_Group_ARS_OD_04_05
#define Rte_Read_Signal_Group_ARS_OD_06_07_Signal_Group_ARS_OD_06_07  Rte_Read_CtApDriving_Signal_Transmission_Signal_Group_ARS_OD_06_07_Signal_Group_ARS_OD_06_07
#define Rte_Read_Signal_Group_ARS_OD_08_09_Signal_Group_ARS_OD_08_09  Rte_Read_CtApDriving_Signal_Transmission_Signal_Group_ARS_OD_08_09_Signal_Group_ARS_OD_08_09
#define Rte_Read_Signal_Group_ARS_OD_10_11_Signal_Group_ARS_OD_10_11  Rte_Read_CtApDriving_Signal_Transmission_Signal_Group_ARS_OD_10_11_Signal_Group_ARS_OD_10_11
#define Rte_Read_Signal_Group_ARS_OD_12_13_Signal_Group_ARS_OD_12_13  Rte_Read_CtApDriving_Signal_Transmission_Signal_Group_ARS_OD_12_13_Signal_Group_ARS_OD_12_13
#define Rte_Read_Signal_Group_ARS_OD_14_15_Signal_Group_ARS_OD_14_15  Rte_Read_CtApDriving_Signal_Transmission_Signal_Group_ARS_OD_14_15_Signal_Group_ARS_OD_14_15
#define Rte_Read_Signal_Group_ARS_OD_16_17_Signal_Group_ARS_OD_16_17  Rte_Read_CtApDriving_Signal_Transmission_Signal_Group_ARS_OD_16_17_Signal_Group_ARS_OD_16_17
#define Rte_Read_Signal_Group_ARS_OD_18_19_Signal_Group_ARS_OD_18_19  Rte_Read_CtApDriving_Signal_Transmission_Signal_Group_ARS_OD_18_19_Signal_Group_ARS_OD_18_19
#define Rte_Read_Signal_Group_ARS_OD_20_21_Signal_Group_ARS_OD_20_21  Rte_Read_CtApDriving_Signal_Transmission_Signal_Group_ARS_OD_20_21_Signal_Group_ARS_OD_20_21
#define Rte_Read_Signal_Group_ARS_OD_22_23_Signal_Group_ARS_OD_22_23  Rte_Read_CtApDriving_Signal_Transmission_Signal_Group_ARS_OD_22_23_Signal_Group_ARS_OD_22_23
#define Rte_Read_Signal_Group_ARS_OD_24_25_Signal_Group_ARS_OD_24_25  Rte_Read_CtApDriving_Signal_Transmission_Signal_Group_ARS_OD_24_25_Signal_Group_ARS_OD_24_25
#define Rte_Read_Signal_Group_ARS_OD_26_27_Signal_Group_ARS_OD_26_27  Rte_Read_CtApDriving_Signal_Transmission_Signal_Group_ARS_OD_26_27_Signal_Group_ARS_OD_26_27
#define Rte_Read_Signal_Group_ARS_OD_28_29_Signal_Group_ARS_OD_28_29  Rte_Read_CtApDriving_Signal_Transmission_Signal_Group_ARS_OD_28_29_Signal_Group_ARS_OD_28_29
#define Rte_Read_Signal_Group_ARS_OD_30_31_Signal_Group_ARS_OD_30_31  Rte_Read_CtApDriving_Signal_Transmission_Signal_Group_ARS_OD_30_31_Signal_Group_ARS_OD_30_31
#define Rte_Read_TSR_SLWFuncSwtReq_TSR_SLWFuncSwtReq        Rte_Read_CtApDriving_Signal_Transmission_TSR_SLWFuncSwtReq_TSR_SLWFuncSwtReq
#define Rte_Read_TSR_SpdWarningOffs_S_TSR_SpdWarningOffs_S  Rte_Read_CtApDriving_Signal_Transmission_TSR_SpdWarningOffs_S_TSR_SpdWarningOffs_S
#define Rte_Read_Time_Day_Time_Day                          Rte_Read_CtApDriving_Signal_Transmission_Time_Day_Time_Day
#define Rte_Read_Time_Hour_Time_Hour                        Rte_Read_CtApDriving_Signal_Transmission_Time_Hour_Time_Hour
#define Rte_Read_Time_Minute_Time_Minute                    Rte_Read_CtApDriving_Signal_Transmission_Time_Minute_Time_Minute
#define Rte_Read_Time_Month_Time_Month                      Rte_Read_CtApDriving_Signal_Transmission_Time_Month_Time_Month
#define Rte_Read_Time_Year_Time_Year                        Rte_Read_CtApDriving_Signal_Transmission_Time_Year_Time_Year
#define Rte_Read_Time_second_Time_second                    Rte_Read_CtApDriving_Signal_Transmission_Time_second_Time_second
#define Rte_Read_VCU_AccPedalPosition_VCU_AccPedalPosition  Rte_Read_CtApDriving_Signal_Transmission_VCU_AccPedalPosition_VCU_AccPedalPosition
#define Rte_Read_VCU_AccPedal_Valid_VCU_AccPedal_Valid      Rte_Read_CtApDriving_Signal_Transmission_VCU_AccPedal_Valid_VCU_AccPedal_Valid
#define Rte_Read_VCU_LimpHomeSts_VCU_LimpHomeSts            Rte_Read_CtApDriving_Signal_Transmission_VCU_LimpHomeSts_VCU_LimpHomeSts
#define Rte_Read_VCU_ModeGearSts_VCU_ModeGearSts            Rte_Read_CtApDriving_Signal_Transmission_VCU_ModeGearSts_VCU_ModeGearSts
#define Rte_Read_VCU_Ready_VCU_Ready                        Rte_Read_CtApDriving_Signal_Transmission_VCU_Ready_VCU_Ready
#define Rte_Read_VCU_StsAccPedalFault_VCU_StsAccPedalFault  Rte_Read_CtApDriving_Signal_Transmission_VCU_StsAccPedalFault_VCU_StsAccPedalFault
#define Rte_Read_VCU_StsSysFault_VCU_StsSysFault            Rte_Read_CtApDriving_Signal_Transmission_VCU_StsSysFault_VCU_StsSysFault
#define Rte_Read_WCBS_ABAAtv_WCBS_ABAAtv                    Rte_Read_CtApDriving_Signal_Transmission_WCBS_ABAAtv_WCBS_ABAAtv
#define Rte_Read_WCBS_ABAAva_WCBS_ABAAva                    Rte_Read_CtApDriving_Signal_Transmission_WCBS_ABAAva_WCBS_ABAAva
#define Rte_Read_WCBS_ABPAtv_WCBS_ABPAtv                    Rte_Read_CtApDriving_Signal_Transmission_WCBS_ABPAtv_WCBS_ABPAtv
#define Rte_Read_WCBS_ABPAva_WCBS_ABPAva                    Rte_Read_CtApDriving_Signal_Transmission_WCBS_ABPAva_WCBS_ABPAva
#define Rte_Read_WCBS_ACC_CDD_Active_WCBS_ACC_CDD_Active    Rte_Read_CtApDriving_Signal_Transmission_WCBS_ACC_CDD_Active_WCBS_ACC_CDD_Active
#define Rte_Read_WCBS_ACC_CDD_Avl_WCBS_ACC_CDD_Avl          Rte_Read_CtApDriving_Signal_Transmission_WCBS_ACC_CDD_Avl_WCBS_ACC_CDD_Avl
#define Rte_Read_WCBS_ACC_VLC_Active_WCBS_ACC_VLC_Active    Rte_Read_CtApDriving_Signal_Transmission_WCBS_ACC_VLC_Active_WCBS_ACC_VLC_Active
#define Rte_Read_WCBS_ACC_VLC_Avl_WCBS_ACC_VLC_Avl          Rte_Read_CtApDriving_Signal_Transmission_WCBS_ACC_VLC_Avl_WCBS_ACC_VLC_Avl
#define Rte_Read_WCBS_AEBAtv_WCBS_AEBAtv                    Rte_Read_CtApDriving_Signal_Transmission_WCBS_AEBAtv_WCBS_AEBAtv
#define Rte_Read_WCBS_AEBAva_WCBS_AEBAva                    Rte_Read_CtApDriving_Signal_Transmission_WCBS_AEBAva_WCBS_AEBAva
#define Rte_Read_WCBS_AWBAtv_WCBS_AWBAtv                    Rte_Read_CtApDriving_Signal_Transmission_WCBS_AWBAtv_WCBS_AWBAtv
#define Rte_Read_WCBS_AWBAvl_WCBS_AWBAvl                    Rte_Read_CtApDriving_Signal_Transmission_WCBS_AWBAvl_WCBS_AWBAvl
#define Rte_Read_WCBS_BrkFrcSta_WCBS_BrkFrcSta              Rte_Read_CtApDriving_Signal_Transmission_WCBS_BrkFrcSta_WCBS_BrkFrcSta
#define Rte_Read_WCBS_ESCDeteACCErroSta_WCBS_ESCDeteACCErroSta        Rte_Read_CtApDriving_Signal_Transmission_WCBS_ESCDeteACCErroSta_WCBS_ESCDeteACCErroSta
#define Rte_Read_WCBS_VStandstillSta_WCBS_VStandstillSta    Rte_Read_CtApDriving_Signal_Transmission_WCBS_VStandstillSta_WCBS_VStandstillSta
/*******************************************************************************
*   Extended
*******************************************************************************/
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtApDriving_Signal_Transmission_ACC_AdtLowerJerkLimit_ACC_AdtLowerJerkLimit
(
    VAR(ACC_AdtLowerJerkLimit_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtApDriving_Signal_Transmission_ACC_AdtUpperJerkLimit_ACC_AdtUpperJerkLimit
(
    VAR(ACC_AdtUpperJerkLimit_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtApDriving_Signal_Transmission_ACC_DriveoffReq_ACC_DriveoffReq
(
    VAR(ACC_DriveoffReq_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtApDriving_Signal_Transmission_ACC_TxtInfoForDriver_ACC_TxtInfoForDriver
(
    VAR(ACC_TxtInfoForDriver_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtApDriving_Signal_Transmission_ADAS_ACC_BrakePreferred_ADAS_ACC_BrakePreferred
(
    VAR(ADAS_ACC_BrakePreferred_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtApDriving_Signal_Transmission_ADAS_ACC_DistanceLevel_ADAS_ACC_DistanceLevel
(
    VAR(ADAS_ACC_DistanceLevel_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtApDriving_Signal_Transmission_ADAS_ACC_ObjDispSts_ADAS_ACC_ObjDispSts
(
    VAR(ADAS_ACC_ObjDispSts_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtApDriving_Signal_Transmission_ADAS_ACC_OperatingSts_ADAS_ACC_OperatingSts
(
    VAR(ADAS_ACC_OperatingSts_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtApDriving_Signal_Transmission_ADAS_ACC_SpdUnit_ADAS_ACC_SpdUnit
(
    VAR(ADAS_ACC_SpdUnit_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtApDriving_Signal_Transmission_ADAS_ACC_TakeOverReq_ADAS_ACC_TakeOverReq
(
    VAR(ADAS_ACC_TakeOverReq_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtApDriving_Signal_Transmission_ADAS_ACC_TargetSpeed_ADAS_ACC_TargetSpeed
(
    VAR(ADAS_ACC_TargetSpeed_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtApDriving_Signal_Transmission_ADAS_ACC_TimeGapLevel_ADAS_ACC_TimeGapLevel
(
    VAR(ADAS_ACC_TimeGapLevel_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtApDriving_Signal_Transmission_ADAS_AEB_AbaLevel_ADAS_AEB_AbaLevel
(
    VAR(ADAS_AEB_AbaLevel_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtApDriving_Signal_Transmission_ADAS_AEB_AbpReq_ADAS_AEB_AbpReq
(
    VAR(ADAS_AEB_AbpReq_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtApDriving_Signal_Transmission_ADAS_AEB_FuncSWResp_ADAS_AEB_FuncSWResp
(
    VAR(ADAS_AEB_FuncSWResp_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtApDriving_Signal_Transmission_ADAS_AEB_TgtDecel_ReqValue_ADAS_AEB_TgtDecel_ReqValue
(
    VAR(ADAS_AEB_TgtDecel_ReqValue_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtApDriving_Signal_Transmission_ADAS_AccelerationReq_ADAS_AccelerationReq
(
    VAR(ADAS_AccelerationReq_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtApDriving_Signal_Transmission_ADAS_EPS_AngReqSts_ADAS_EPS_AngReqSts
(
    VAR(ADAS_EPS_AngReqSts_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtApDriving_Signal_Transmission_ADAS_EPS_TargetSteeringAngle_ADAS_EPS_TargetSteeringAngle
(
    VAR(ADAS_EPS_TargetSteeringAngle_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtApDriving_Signal_Transmission_ADAS_EPS_Vibration_Req_ADAS_EPS_Vibration_Req
(
    VAR(ADAS_EPS_Vibration_Req_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtApDriving_Signal_Transmission_ADAS_IBS_CarStarting_ADAS_IBS_CarStarting
(
    VAR(ADAS_IBS_CarStarting_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtApDriving_Signal_Transmission_ADAS_IBS_EBAReq_ADAS_IBS_EBAReq
(
    VAR(ADAS_IBS_EBAReq_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtApDriving_Signal_Transmission_ADAS_IBS_MinBreakReq_ADAS_IBS_MinBreakReq
(
    VAR(ADAS_IBS_MinBreakReq_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtApDriving_Signal_Transmission_ADAS_IBS_StopReq_ADAS_IBS_StopReq
(
    VAR(ADAS_IBS_StopReq_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtApDriving_Signal_Transmission_ADAS_LSS_AngCmdReqPortnValue_ADAS_LSS_AngCmdReqPortnValue
(
    VAR(ADAS_LSS_AngCmdReqPortnValue_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtApDriving_Signal_Transmission_ADAS_LSS_AssidFormResp_ADAS_LSS_AssidFormResp
(
    VAR(ADAS_LSS_AssidFormResp_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtApDriving_Signal_Transmission_ADAS_LSS_Available_ADAS_LSS_Available
(
    VAR(ADAS_LSS_Available_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtApDriving_Signal_Transmission_ADAS_LSS_ErrSts_ADAS_LSS_ErrSts
(
    VAR(ADAS_LSS_ErrSts_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtApDriving_Signal_Transmission_ADAS_LSS_FunSts_ADAS_LSS_FunSts
(
    VAR(ADAS_LSS_FunSts_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtApDriving_Signal_Transmission_ADAS_LSS_FuncResp_ADAS_LSS_FuncResp
(
    VAR(ADAS_LSS_FuncResp_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtApDriving_Signal_Transmission_ADAS_LSS_HandsoffWarn_ADAS_LSS_HandsoffWarn
(
    VAR(ADAS_LSS_HandsoffWarn_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtApDriving_Signal_Transmission_ADAS_LSS_LeLineTrackingSts_ADAS_LSS_LeLineTrackingSts
(
    VAR(ADAS_LSS_LeLineTrackingSts_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtApDriving_Signal_Transmission_ADAS_LSS_RiLineTrackingSts_ADAS_LSS_RiLineTrackingSts
(
    VAR(ADAS_LSS_RiLineTrackingSts_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtApDriving_Signal_Transmission_ADAS_LSS_VoiceWarn_ADAS_LSS_VoiceWarn
(
    VAR(ADAS_LSS_VoiceWarn_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtApDriving_Signal_Transmission_ADAS_LSS_WarnFromResp_ADAS_LSS_WarnFromResp
(
    VAR(ADAS_LSS_WarnFromResp_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtApDriving_Signal_Transmission_ADAS_MaxSoftAcceleration_ADAS_MaxSoftAcceleration
(
    VAR(ADAS_MaxSoftAcceleration_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtApDriving_Signal_Transmission_ADAS_MinSoftAcceleration_ADAS_MinSoftAcceleration
(
    VAR(ADAS_MinSoftAcceleration_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtApDriving_Signal_Transmission_ADAS_TSR_OperationSts_ADAS_TSR_OperationSts
(
    VAR(ADAS_TSR_OperationSts_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtApDriving_Signal_Transmission_ADAS_TSR_SWSts_ADAS_TSR_SWSts
(
    VAR(ADAS_TSR_SWSts_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtApDriving_Signal_Transmission_ADAS_TSR_SpeedLimit_ADAS_TSR_SpeedLimit
(
    VAR(ADAS_TSR_SpeedLimit_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtApDriving_Signal_Transmission_ADAS_VLCModeReq_ADAS_VLCModeReq
(
    VAR(ADAS_VLCModeReq_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtApDriving_Signal_Transmission_ADAS_VLCShutDownReq_ADAS_VLCShutDownReq
(
    VAR(ADAS_VLCShutDownReq_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtApDriving_Signal_Transmission_AEB_ABA_Req_AEB_ABA_Req
(
    VAR(AEB_ABA_Req_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtApDriving_Signal_Transmission_AEB_AWB_Level_AEB_AWB_Level
(
    VAR(AEB_AWB_Level_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtApDriving_Signal_Transmission_AEB_AWB_Req_AEB_AWB_Req
(
    VAR(AEB_AWB_Req_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtApDriving_Signal_Transmission_AEB_ErrorSts_AEB_ErrorSts
(
    VAR(AEB_ErrorSts_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtApDriving_Signal_Transmission_AEB_FCW_Warning_AEB_FCW_Warning
(
    VAR(AEB_FCW_Warning_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtApDriving_Signal_Transmission_AEB_FuncSts_AEB_FuncSts
(
    VAR(AEB_FuncSts_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtApDriving_Signal_Transmission_AEB_TgtDecel_Req_AEB_TgtDecel_Req
(
    VAR(AEB_TgtDecel_Req_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtApDriving_Signal_Transmission_AEB_VRUActive_AEB_VRUActive
(
    VAR(AEB_VRUActive_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtApDriving_Signal_Transmission_AEB_VehActive_AEB_VehActive
(
    VAR(AEB_VehActive_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtApDriving_Signal_Transmission_AEB_VehHldReq_AEB_VehHldReq
(
    VAR(AEB_VehHldReq_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtApDriving_Signal_Transmission_AEB_FCW_SnvtyResp_AEB_FCW_SnvtyResp
(
    VAR(AEB_FCW_SnvtyResp_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtApDriving_Signal_Transmission_FC_BlockageSts_FC_BlockageSts
(
    VAR(FC_BlockageSts_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtApDriving_Signal_Transmission_FC_CalibrationSts_FC_CalibrationSts
(
    VAR(FC_CalibrationSts_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtApDriving_Signal_Transmission_PiFrontRadarInfo_PiFrontRadarInfo
(
    P2VAR(FrontRadarInfo, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtApDriving_Signal_Transmission_TSR_SLWSwtResp_TSR_SLWSwtResp
(
    VAR(TSR_SLWSwtResp_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtApDriving_Signal_Transmission_TSR_SLWVisualWarn_TSR_SLWVisualWarn
(
    VAR(TSR_SLWVisualWarn_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtApDriving_Signal_Transmission_TSR_SLWVoiceWarn_TSR_SLWVoiceWarn
(
    VAR(TSR_SLWVoiceWarn_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtApDriving_Signal_Transmission_TSR_SpdAssistInfoDisp_TSR_SpdAssistInfoDisp
(
    VAR(TSR_SpdAssistInfoDisp_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtApDriving_Signal_Transmission_TSR_TrafSign_TSR_TrafSign
(
    VAR(TSR_TrafSign_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtApDriving_Signal_Transmission_TSR_Warning_offset_TSR_Warning_offset
(
    VAR(TSR_Warning_offset_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtApDriving_Signal_Transmission_PiVehicleInfo_PiVehicleInfo
(
    P2VAR(VehicleInfo, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtApDriving_Signal_Transmission_ABSActive_ABSActive
(
    P2VAR(ABSActive_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtApDriving_Signal_Transmission_ABS_FLWheelDirection_ABS_FLWheelDirection
(
    P2VAR(ABS_FLWheelDirection_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtApDriving_Signal_Transmission_ABS_FLWheelSpeedInvalid_ABS_FLWheelSpeedInvalid
(
    P2VAR(ABS_FLWheelSpeedInvalid_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtApDriving_Signal_Transmission_ABS_FLWheelSpeedKPH_ABS_FLWheelSpeedKPH
(
    P2VAR(ABS_FLWheelSpeedKPH_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtApDriving_Signal_Transmission_ABS_FRWheelDirection_ABS_FRWheelDirection
(
    P2VAR(ABS_FRWheelDirection_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtApDriving_Signal_Transmission_ABS_FRWheelSpeedInvalid_ABS_FRWheelSpeedInvalid
(
    P2VAR(ABS_FRWheelSpeedInvalid_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtApDriving_Signal_Transmission_ABS_FRWheelSpeedKPH_ABS_FRWheelSpeedKPH
(
    P2VAR(ABS_FRWheelSpeedKPH_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtApDriving_Signal_Transmission_ABS_RLWheelDirection_ABS_RLWheelDirection
(
    P2VAR(ABS_RLWheelDirection_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtApDriving_Signal_Transmission_ABS_RLWheelSpeedInvalid_ABS_RLWheelSpeedInvalid
(
    P2VAR(ABS_RLWheelSpeedInvalid_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtApDriving_Signal_Transmission_ABS_RLWheelSpeedKPH_ABS_RLWheelSpeedKPH
(
    P2VAR(ABS_RLWheelSpeedKPH_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtApDriving_Signal_Transmission_ABS_RRWheelDirection_ABS_RRWheelDirection
(
    P2VAR(ABS_RRWheelDirection_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtApDriving_Signal_Transmission_ABS_RRWheelSpeedInvalid_ABS_RRWheelSpeedInvalid
(
    P2VAR(ABS_RRWheelSpeedInvalid_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtApDriving_Signal_Transmission_ABS_RRWheelSpeedKPH_ABS_RRWheelSpeedKPH
(
    P2VAR(ABS_RRWheelSpeedKPH_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtApDriving_Signal_Transmission_ABS_VehicleSpeedInvalid_ABS_VehicleSpeedInvalid
(
    P2VAR(ABS_VehicleSpeedInvalid_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtApDriving_Signal_Transmission_ABS_VehicleSpeed_ABS_VehicleSpeed
(
    P2VAR(ABS_VehicleSpeed_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtApDriving_Signal_Transmission_AB_BrkPedalPct_AB_BrkPedalPct
(
    P2VAR(AB_BrkPedalPct_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtApDriving_Signal_Transmission_AB_BrkPedalSwStsV_AB_BrkPedalSwStsV
(
    P2VAR(AB_BrkPedalSwStsV_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtApDriving_Signal_Transmission_AB_BrkPedalSwSts_AB_BrkPedalSwSts
(
    P2VAR(AB_BrkPedalSwSts_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtApDriving_Signal_Transmission_AB_BrkPedalTravel_AB_BrkPedalTravel
(
    P2VAR(AB_BrkPedalTravel_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtApDriving_Signal_Transmission_AB_Fault_Status_AB_Fault_Status
(
    P2VAR(AB_Fault_Status_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtApDriving_Signal_Transmission_ACU_CoDSeatbeltBucklestatus_ACU_CoDSeatbeltBucklestatus
(
    P2VAR(ACU_CoDSeatbeltBucklestatus_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtApDriving_Signal_Transmission_ACU_DSeatbeltBucklestatus_ACU_DSeatbeltBucklestatus
(
    P2VAR(ACU_DSeatbeltBucklestatus_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtApDriving_Signal_Transmission_ADAS_APA_SystemSts_ADAS_APA_SystemSts
(
    P2VAR(ADAS_APA_SystemSts_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtApDriving_Signal_Transmission_AEB_FCW_SnvtyReq_AEB_FCW_SnvtyReq
(
    P2VAR(AEB_FCW_SnvtyReq_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtApDriving_Signal_Transmission_AEB_FuncSwtReq_AEB_FuncSwtReq
(
    P2VAR(AEB_FuncSwtReq_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtApDriving_Signal_Transmission_ADAS_APA_OperationSts_ADAS_APA_OperationSts
(
    P2VAR(ADAS_APA_OperationSts_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtApDriving_Signal_Transmission_BCM_AutoWipeSts_BCM_AutoWipeSts
(
    P2VAR(BCM_AutoWipeSts_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtApDriving_Signal_Transmission_BCM_CodriversSideDoorAjarSts_BCM_CodriversSideDoorAjarSts
(
    P2VAR(BCM_CodriversSideDoorAjarSts_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtApDriving_Signal_Transmission_BCM_CoverAjarStatus_BCM_CoverAjarStatus
(
    P2VAR(BCM_CoverAjarStatus_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtApDriving_Signal_Transmission_BCM_DoorLockStatusCodrivres_BCM_DoorLockStatusCodrivres
(
    P2VAR(BCM_DoorLockStatusCodrivres_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtApDriving_Signal_Transmission_BCM_DoorLockStatusDrv_BCM_DoorLockStatusDrv
(
    P2VAR(BCM_DoorLockStatusDrv_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtApDriving_Signal_Transmission_BCM_DoorLockStatusRL_BCM_DoorLockStatusRL
(
    P2VAR(BCM_DoorLockStatusRL_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtApDriving_Signal_Transmission_BCM_DoorLockStatusRR_BCM_DoorLockStatusRR
(
    P2VAR(BCM_DoorLockStatusRR_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtApDriving_Signal_Transmission_BCM_DriverSideDoorAjarSts_BCM_DriverSideDoorAjarSts
(
    P2VAR(BCM_DriverSideDoorAjarSts_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtApDriving_Signal_Transmission_BCM_FrontFogLampLightSts_BCM_FrontFogLampLightSts
(
    P2VAR(BCM_FrontFogLampLightSts_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtApDriving_Signal_Transmission_BCM_FrontWipeSWSts_BCM_FrontWipeSWSts
(
    P2VAR(BCM_FrontWipeSWSts_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtApDriving_Signal_Transmission_BCM_FrontWipeSts_BCM_FrontWipeSts
(
    P2VAR(BCM_FrontWipeSts_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtApDriving_Signal_Transmission_BCM_RearLeftDoorAjarStatus_BCM_RearLeftDoorAjarStatus
(
    P2VAR(BCM_RearLeftDoorAjarStatus_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtApDriving_Signal_Transmission_BCM_RearRightDoorAjarStatus_BCM_RearRightDoorAjarStatus
(
    P2VAR(BCM_RearRightDoorAjarStatus_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtApDriving_Signal_Transmission_BCM_TrunckAjarStatus_BCM_TrunckAjarStatus
(
    P2VAR(BCM_TrunckAjarStatus_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtApDriving_Signal_Transmission_BCM_TurnIndicatorSts_BCM_TurnIndicatorSts
(
    P2VAR(BCM_TurnIndicatorSts_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtApDriving_Signal_Transmission_BCM_TurnLightSWSts_BCM_TurnLightSWSts
(
    P2VAR(BCM_TurnLightSWSts_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtApDriving_Signal_Transmission_BCM_TurnLight_FaultSts_BCM_TurnLight_FaultSts
(
    P2VAR(BCM_TurnLight_FaultSts_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtApDriving_Signal_Transmission_BSD_LCA_FuncSWReq_BSD_LCA_FuncSWReq
(
    P2VAR(BSD_LCA_FuncSWReq_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtApDriving_Signal_Transmission_CCU_ExternalTemperature_CCU_ExternalTemperature
(
    P2VAR(CCU_ExternalTemperature_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtApDriving_Signal_Transmission_ESC_TcsDisableSts_ESC_TcsDisableSts
(
    P2VAR(ESC_TcsDisableSts_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtApDriving_Signal_Transmission_DOW_FuncSWReq_DOW_FuncSWReq
(
    P2VAR(DOW_FuncSWReq_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtApDriving_Signal_Transmission_EPB_AVHFeedbackSts_EPB_AVHFeedbackSts
(
    P2VAR(EPB_AVHFeedbackSts_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtApDriving_Signal_Transmission_EPB_AVHStatIndReqV_EPB_AVHStatIndReqV
(
    P2VAR(EPB_AVHStatIndReqV_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtApDriving_Signal_Transmission_EPS_ADAS_CtrlAbortFeedback_EPS_ADAS_CtrlAbortFeedback
(
    P2VAR(EPS_ADAS_CtrlAbortFeedback_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtApDriving_Signal_Transmission_EPS_ADAS_ModActv_EPS_ADAS_ModActv
(
    P2VAR(EPS_ADAS_ModActv_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtApDriving_Signal_Transmission_EPS_ADAS_ModAvail_EPS_ADAS_ModAvail
(
    P2VAR(EPS_ADAS_ModAvail_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtApDriving_Signal_Transmission_EPS_DrStrTorqV_EPS_DrStrTorqV
(
    P2VAR(EPS_DrStrTorqV_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtApDriving_Signal_Transmission_EPS_DrStrTorqVal_EPS_DrStrTorqVal
(
    P2VAR(EPS_DrStrTorqVal_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtApDriving_Signal_Transmission_EPS_LKARespTorq_EPS_LKARespTorq
(
    P2VAR(EPS_LKARespTorq_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtApDriving_Signal_Transmission_EPS_SterFltMod_EPS_SterFltMod
(
    P2VAR(EPS_SterFltMod_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtApDriving_Signal_Transmission_ESC_EscCtrlActv_ESC_EscCtrlActv
(
    P2VAR(ESC_EscCtrlActv_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtApDriving_Signal_Transmission_ESC_EscDisableSts_ESC_EscDisableSts
(
    P2VAR(ESC_EscDisableSts_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtApDriving_Signal_Transmission_ESC_HSA_Control_Status_ESC_HSA_Control_Status
(
    P2VAR(ESC_HSA_Control_Status_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtApDriving_Signal_Transmission_ESC_LateralACC_ESC_LateralACC
(
    P2VAR(ESC_LateralACC_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtApDriving_Signal_Transmission_ESC_LateralACC_Valid_ESC_LateralACC_Valid
(
    P2VAR(ESC_LateralACC_Valid_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtApDriving_Signal_Transmission_ESC_LongitudeACC_ESC_LongitudeACC
(
    P2VAR(ESC_LongitudeACC_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtApDriving_Signal_Transmission_ESC_LongitudeACC_Valid_ESC_LongitudeACC_Valid
(
    P2VAR(ESC_LongitudeACC_Valid_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtApDriving_Signal_Transmission_ESC_MasterCylinderPressureV_ESC_MasterCylinderPressureV
(
    P2VAR(ESC_MasterCylinderPressureV_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtApDriving_Signal_Transmission_ESC_MasterCylinderPressure_ESC_MasterCylinderPressure
(
    P2VAR(ESC_MasterCylinderPressure_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtApDriving_Signal_Transmission_ESC_TcsCtrlActv_ESC_TcsCtrlActv
(
    P2VAR(ESC_TcsCtrlActv_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtApDriving_Signal_Transmission_ESC_VehDynYawRate_ESC_VehDynYawRate
(
    P2VAR(ESC_VehDynYawRate_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtApDriving_Signal_Transmission_ESC_VehDynYawRate_Valid_ESC_VehDynYawRate_Valid
(
    P2VAR(ESC_VehDynYawRate_Valid_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtApDriving_Signal_Transmission_GPSSystAtv_GPSSystAtv
(
    P2VAR(GPSSystAtv_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtApDriving_Signal_Transmission_IBS_ESCOFF_StsFB_IBS_ESCOFF_StsFB
(
    P2VAR(IBS_ESCOFF_StsFB_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtApDriving_Signal_Transmission_IPC_IPCTotalOdometerV_IPC_IPCTotalOdometerV
(
    P2VAR(IPC_IPCTotalOdometerV_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtApDriving_Signal_Transmission_IPC_IPCTotalOdometer_IPC_IPCTotalOdometer
(
    P2VAR(IPC_IPCTotalOdometer_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtApDriving_Signal_Transmission_MFS_ACC_CruiseCancel_MFS_ACC_CruiseCancel
(
    P2VAR(MFS_ACC_CruiseCancel_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtApDriving_Signal_Transmission_MFS_ACC_CruiseGapSet_MFS_ACC_CruiseGapSet
(
    P2VAR(MFS_ACC_CruiseGapSet_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtApDriving_Signal_Transmission_MFS_ACC_CruiseOn_Off_MFS_ACC_CruiseOn_Off
(
    P2VAR(MFS_ACC_CruiseOn_Off_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtApDriving_Signal_Transmission_MFS_ACC_CruiseSpdDecrease_MFS_ACC_CruiseSpdDecrease
(
    P2VAR(MFS_ACC_CruiseSpdDecrease_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtApDriving_Signal_Transmission_MFS_ACC_CruiseSpdIncrease_MFS_ACC_CruiseSpdIncrease
(
    P2VAR(MFS_ACC_CruiseSpdIncrease_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtApDriving_Signal_Transmission_MHU_DM_SwitchModeSts_MHU_DM_SwitchModeSts
(
    P2VAR(MHU_DM_SwitchModeSts_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtApDriving_Signal_Transmission_MHU_LSS_Mode_MHU_LSS_Mode
(
    P2VAR(MHU_LSS_Mode_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtApDriving_Signal_Transmission_MHU_LSS_Req_MHU_LSS_Req
(
    P2VAR(MHU_LSS_Req_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtApDriving_Signal_Transmission_MHU_LSS_WarningMethod_MHU_LSS_WarningMethod
(
    P2VAR(MHU_LSS_WarningMethod_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtApDriving_Signal_Transmission_MHU_TSR_Req_MHU_TSR_Req
(
    P2VAR(MHU_TSR_Req_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtApDriving_Signal_Transmission_MHU_Trailermode_Req_MHU_Trailermode_Req
(
    P2VAR(MHU_Trailermode_Req_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtApDriving_Signal_Transmission_Nav_CtryType_Nav_CtryType
(
    P2VAR(Nav_CtryType_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtApDriving_Signal_Transmission_Nav_RoadType_Nav_RoadType
(
    P2VAR(Nav_RoadType_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtApDriving_Signal_Transmission_Nav_SpdLimType_Nav_SpdLimType
(
    P2VAR(Nav_SpdLimType_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtApDriving_Signal_Transmission_Nav_SpdLimUnit_Nav_SpdLimUnit
(
    P2VAR(Nav_SpdLimUnit_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtApDriving_Signal_Transmission_Nav_SpdLimValue_Nav_SpdLimValue
(
    P2VAR(Nav_SpdLimValue_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtApDriving_Signal_Transmission_Nav_TSRTrafSign_Nav_TSRTrafSign
(
    P2VAR(Nav_TSRTrafSign_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtApDriving_Signal_Transmission_Nav_VehToTrafEyeDist_Nav_VehToTrafEyeDist
(
    P2VAR(Nav_VehToTrafEyeDist_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtApDriving_Signal_Transmission_Nav_errorSts_Nav_errorSts
(
    P2VAR(Nav_errorSts_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtApDriving_Signal_Transmission_PEPS_PowerModeValidity_PEPS_PowerModeValidity
(
    P2VAR(PEPS_PowerModeValidity_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtApDriving_Signal_Transmission_PEPS_PowerMode_PEPS_PowerMode
(
    P2VAR(PEPS_PowerMode_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtApDriving_Signal_Transmission_PiADAS_CAN_Output_ADAS_CAN_Output
(
    P2VAR(ADAS_CAN_Output, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtApDriving_Signal_Transmission_RCTA_FuncSWReq_RCTA_FuncSWReq
(
    P2VAR(RCTA_FuncSWReq_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtApDriving_Signal_Transmission_RCW_FuncSWReq_RCW_FuncSWReq
(
    P2VAR(RCW_FuncSWReq_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtApDriving_Signal_Transmission_RLS_Rainfall_magnitude_RLS_Rainfall_magnitude
(
    P2VAR(RLS_Rainfall_magnitude_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtApDriving_Signal_Transmission_SAS_Calibrated_SAS_Calibrated
(
    P2VAR(SAS_Calibrated_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtApDriving_Signal_Transmission_SAS_SASFailure_SAS_SASFailure
(
    P2VAR(SAS_SASFailure_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtApDriving_Signal_Transmission_SAS_SteerWheelAngle_SAS_SteerWheelAngle
(
    P2VAR(SAS_SteerWheelAngle_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtApDriving_Signal_Transmission_SAS_SteerWhlRotSpdStatus_SAS_SteerWhlRotSpdStatus
(
    P2VAR(SAS_SteerWhlRotSpdStatus_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtApDriving_Signal_Transmission_SAS_SteerWhlRotSpd_SAS_SteerWhlRotSpd
(
    P2VAR(SAS_SteerWhlRotSpd_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtApDriving_Signal_Transmission_SAS_SteeringAngleValid_SAS_SteeringAngleValid
(
    P2VAR(SAS_SteeringAngleValid_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtApDriving_Signal_Transmission_Signal_Group_ARS_OD_00_01_Signal_Group_ARS_OD_00_01
(
    P2VAR(Signal_Group_ARS_OD_00_01_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtApDriving_Signal_Transmission_Signal_Group_ARS_OD_02_03_Signal_Group_ARS_OD_02_03
(
    P2VAR(Signal_Group_ARS_OD_02_03_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtApDriving_Signal_Transmission_Signal_Group_ARS_OD_04_05_Signal_Group_ARS_OD_04_05
(
    P2VAR(Signal_Group_ARS_OD_04_05_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtApDriving_Signal_Transmission_Signal_Group_ARS_OD_06_07_Signal_Group_ARS_OD_06_07
(
    P2VAR(Signal_Group_ARS_OD_06_07_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtApDriving_Signal_Transmission_Signal_Group_ARS_OD_08_09_Signal_Group_ARS_OD_08_09
(
    P2VAR(Signal_Group_ARS_OD_08_09_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtApDriving_Signal_Transmission_Signal_Group_ARS_OD_10_11_Signal_Group_ARS_OD_10_11
(
    P2VAR(Signal_Group_ARS_OD_10_11_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtApDriving_Signal_Transmission_Signal_Group_ARS_OD_12_13_Signal_Group_ARS_OD_12_13
(
    P2VAR(Signal_Group_ARS_OD_12_13_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtApDriving_Signal_Transmission_Signal_Group_ARS_OD_14_15_Signal_Group_ARS_OD_14_15
(
    P2VAR(Signal_Group_ARS_OD_14_15_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtApDriving_Signal_Transmission_Signal_Group_ARS_OD_16_17_Signal_Group_ARS_OD_16_17
(
    P2VAR(Signal_Group_ARS_OD_16_17_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtApDriving_Signal_Transmission_Signal_Group_ARS_OD_18_19_Signal_Group_ARS_OD_18_19
(
    P2VAR(Signal_Group_ARS_OD_18_19_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtApDriving_Signal_Transmission_Signal_Group_ARS_OD_20_21_Signal_Group_ARS_OD_20_21
(
    P2VAR(Signal_Group_ARS_OD_20_21_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtApDriving_Signal_Transmission_Signal_Group_ARS_OD_22_23_Signal_Group_ARS_OD_22_23
(
    P2VAR(Signal_Group_ARS_OD_22_23_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtApDriving_Signal_Transmission_Signal_Group_ARS_OD_24_25_Signal_Group_ARS_OD_24_25
(
    P2VAR(Signal_Group_ARS_OD_24_25_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtApDriving_Signal_Transmission_Signal_Group_ARS_OD_26_27_Signal_Group_ARS_OD_26_27
(
    P2VAR(Signal_Group_ARS_OD_26_27_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtApDriving_Signal_Transmission_Signal_Group_ARS_OD_28_29_Signal_Group_ARS_OD_28_29
(
    P2VAR(Signal_Group_ARS_OD_28_29_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtApDriving_Signal_Transmission_Signal_Group_ARS_OD_30_31_Signal_Group_ARS_OD_30_31
(
    P2VAR(Signal_Group_ARS_OD_30_31_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtApDriving_Signal_Transmission_TSR_SLWFuncSwtReq_TSR_SLWFuncSwtReq
(
    P2VAR(TSR_SLWFuncSwtReq_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtApDriving_Signal_Transmission_TSR_SpdWarningOffs_S_TSR_SpdWarningOffs_S
(
    P2VAR(TSR_SpdWarningOffs_S_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtApDriving_Signal_Transmission_Time_Day_Time_Day
(
    P2VAR(Time_Day_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtApDriving_Signal_Transmission_Time_Hour_Time_Hour
(
    P2VAR(Time_Hour_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtApDriving_Signal_Transmission_Time_Minute_Time_Minute
(
    P2VAR(Time_Minute_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtApDriving_Signal_Transmission_Time_Month_Time_Month
(
    P2VAR(Time_Month_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtApDriving_Signal_Transmission_Time_Year_Time_Year
(
    P2VAR(Time_Year_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtApDriving_Signal_Transmission_Time_second_Time_second
(
    P2VAR(Time_second_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtApDriving_Signal_Transmission_VCU_AccPedalPosition_VCU_AccPedalPosition
(
    P2VAR(VCU_AccPedalPosition_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtApDriving_Signal_Transmission_VCU_AccPedal_Valid_VCU_AccPedal_Valid
(
    P2VAR(VCU_AccPedal_Valid_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtApDriving_Signal_Transmission_VCU_LimpHomeSts_VCU_LimpHomeSts
(
    P2VAR(VCU_LimpHomeSts_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtApDriving_Signal_Transmission_VCU_ModeGearSts_VCU_ModeGearSts
(
    P2VAR(VCU_ModeGearSts_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtApDriving_Signal_Transmission_VCU_Ready_VCU_Ready
(
    P2VAR(VCU_Ready_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtApDriving_Signal_Transmission_VCU_StsAccPedalFault_VCU_StsAccPedalFault
(
    P2VAR(VCU_StsAccPedalFault_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtApDriving_Signal_Transmission_VCU_StsSysFault_VCU_StsSysFault
(
    P2VAR(VCU_StsSysFault_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtApDriving_Signal_Transmission_WCBS_ABAAtv_WCBS_ABAAtv
(
    P2VAR(WCBS_ABAAtv_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtApDriving_Signal_Transmission_WCBS_ABAAva_WCBS_ABAAva
(
    P2VAR(WCBS_ABAAva_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtApDriving_Signal_Transmission_WCBS_ABPAtv_WCBS_ABPAtv
(
    P2VAR(WCBS_ABPAtv_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtApDriving_Signal_Transmission_WCBS_ABPAva_WCBS_ABPAva
(
    P2VAR(WCBS_ABPAva_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtApDriving_Signal_Transmission_WCBS_ACC_CDD_Active_WCBS_ACC_CDD_Active
(
    P2VAR(WCBS_ACC_CDD_Active_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtApDriving_Signal_Transmission_WCBS_ACC_CDD_Avl_WCBS_ACC_CDD_Avl
(
    P2VAR(WCBS_ACC_CDD_Avl_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtApDriving_Signal_Transmission_WCBS_ACC_VLC_Active_WCBS_ACC_VLC_Active
(
    P2VAR(WCBS_ACC_VLC_Active_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtApDriving_Signal_Transmission_WCBS_ACC_VLC_Avl_WCBS_ACC_VLC_Avl
(
    P2VAR(WCBS_ACC_VLC_Avl_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtApDriving_Signal_Transmission_WCBS_AEBAtv_WCBS_AEBAtv
(
    P2VAR(WCBS_AEBAtv_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtApDriving_Signal_Transmission_WCBS_AEBAva_WCBS_AEBAva
(
    P2VAR(WCBS_AEBAva_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtApDriving_Signal_Transmission_WCBS_AWBAtv_WCBS_AWBAtv
(
    P2VAR(WCBS_AWBAtv_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtApDriving_Signal_Transmission_WCBS_AWBAvl_WCBS_AWBAvl
(
    P2VAR(WCBS_AWBAvl_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtApDriving_Signal_Transmission_WCBS_BrkFrcSta_WCBS_BrkFrcSta
(
    P2VAR(WCBS_BrkFrcSta_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtApDriving_Signal_Transmission_WCBS_ESCDeteACCErroSta_WCBS_ESCDeteACCErroSta
(
    P2VAR(WCBS_ESCDeteACCErroSta_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtApDriving_Signal_Transmission_WCBS_VStandstillSta_WCBS_VStandstillSta
(
    P2VAR(WCBS_VStandstillSta_IDT, AUTOMATIC, RTE_APPL_DATA) data
);

/*******************************************************************************
*   Runnable Extended
*******************************************************************************/

#define CtApDriving_Signal_Transmission_START_SEC_CODE
#include "CtApDriving_Signal_Transmission_MemMap.h"

extern FUNC(void, CtApDriving_Signal_Transmission_CODE) Driving_Signal_Transmission_Init
(
    void
);
#define CtApDriving_Signal_Transmission_STOP_SEC_CODE
#include "CtApDriving_Signal_Transmission_MemMap.h"


#define CtApDriving_Signal_Transmission_START_SEC_CODE
#include "CtApDriving_Signal_Transmission_MemMap.h"

extern FUNC(void, CtApDriving_Signal_Transmission_CODE) Task_Driving_Signal_Transmission_10ms
(
    void
);
#define CtApDriving_Signal_Transmission_STOP_SEC_CODE
#include "CtApDriving_Signal_Transmission_MemMap.h"


# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif  /*RTE_CTAPDRIVING_SIGNAL_TRANSMISSION_H*/


