/*  BEGIN_FILE_HDR
********************************************************************************
*   File Name       : Com_Lcfg.h
********************************************************************************
*   Project/Product : AUTOSAR BSW PROJECT
*   Title           : Com module configuration File
*   Author          : Hirain
********************************************************************************
*   Description     : Com module configuration File
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
*   V1.0.2_3.5.5_AZ240046       09/05/2024    Eas           N/A          N/A
*
********************************************************************************
* END_FILE_HDR*/
#ifndef COM_LCFG_H
#define COM_LCFG_H

/*******************************************************************************
*   Includes
*******************************************************************************/
#include "Com_Types.h"

/*******************************************************************************
*   Com Internal Vars
*******************************************************************************/
#define COM_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h"
extern VAR(Com_RxPduType, COM_VAR) Com_RxPduTable[];
extern VAR(Com_TxPduType, COM_VAR) Com_TxPduTable[];
#define COM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h"

#define COM_START_SEC_VAR_NOINIT_8
#include "MemMap.h"
extern VAR(Com_TxPduStateType, COM_VAR) Com_TxPduState[];
extern VAR(uint8, COM_VAR) Com_PDUTrigRepFlag[];
extern VAR(boolean, COM_VAR) Com_TriggerPDUSendFlag[];
extern VAR(Com_RxPduStateType, COM_VAR) Com_RxPduState[];
extern VAR(boolean, COM_VAR) Com_IpduGroupStartFlag[];
extern VAR(boolean, COM_VAR) Com_IpduGroupDMEnableFlag[];
#define COM_STOP_SEC_VAR_NOINIT_8
#include "MemMap.h"
#define COM_START_SEC_VAR_NOINIT_16
#include "MemMap.h"
#define COM_STOP_SEC_VAR_NOINIT_16
#include "MemMap.h"

/******************************************************************************
*    Typedef
******************************************************************************/
typedef uint8 Com_IpduGroupVector[1];

/******************************************************************************
*    Send Signal structures
******************************************************************************/
/*CanConfigSet*/
typedef struct
{
    uint8 CanConfigSet_Tx_ACAN_ADAS_01_ADAS_01_Checksum : 8;
    uint8 CanConfigSet_Tx_ACAN_ADAS_01_ADAS_01_RollingCounter : 4;
    uint8 unused0_Byte0 : 4;
    uint8 unused0_Byte1 : 7;
    uint8 CanConfigSet_Tx_ACAN_ADAS_01_ADAS_ACC_SpdUnit : 1;
    uint8 CanConfigSet_Tx_ACAN_ADAS_01_ADAS_ACC_TargetSpeed : 8;
    uint8 unused1 : 4;
    uint8 CanConfigSet_Tx_ACAN_ADAS_01_ADAS_ACC_OperatingSts : 4;
    uint8 CanConfigSet_Tx_ACAN_ADAS_01_ADAS_ACC_TimeGapLevel : 3;
    uint8 unused2 : 1;
    uint8 CanConfigSet_Tx_ACAN_ADAS_01_ADAS_ACC_DistanceLevel : 3;
    uint8 unused3_Byte0 : 1;
    uint8 unused3_Byte1 : 8;
    uint8 CanConfigSet_Tx_ACAN_ADAS_01_ADAS_ACC_ObjDispSts : 1;
    uint8 CanConfigSet_Tx_ACAN_ADAS_01_ADAS_ACC_TakeOverReq : 1;
    uint8 unused4 : 6;
} TxPdu_CanConfigSet_Tx_ACAN_ADAS_01_BufType;
extern VAR(TxPdu_CanConfigSet_Tx_ACAN_ADAS_01_BufType, COM_VAR_NOINIT) Com_TxPdu_CanConfigSet_Tx_ACAN_ADAS_01 ;

typedef struct
{
    uint8 CanConfigSet_Tx_ACAN_ADAS_02_ADAS_02_Checksum : 8;
    uint8 CanConfigSet_Tx_ACAN_ADAS_02_ADAS_02_RollingCounter : 4;
    uint8 unused0 : 4;
    uint8 CanConfigSet_Tx_ACAN_ADAS_02_ADAS_LSS_AngCmdReqPortnValue_Byte1 : 6;
    uint8 CanConfigSet_Tx_ACAN_ADAS_02_ADAS_LSS_AssidFormResp : 2;
    uint8 CanConfigSet_Tx_ACAN_ADAS_02_ADAS_LSS_AngCmdReqPortnValue_Byte0 : 8;
    uint8 CanConfigSet_Tx_ACAN_ADAS_02_ADAS_EPS_TargetSteeringAngle_Byte1 : 8;
    uint8 CanConfigSet_Tx_ACAN_ADAS_02_ADAS_EPS_TargetSteeringAngle_Byte0 : 8;
    uint8 CanConfigSet_Tx_ACAN_ADAS_02_ADAS_EPS_Vibration_Req : 2;
    uint8 CanConfigSet_Tx_ACAN_ADAS_02_ADAS_LSS_VoiceWarn : 2;
    uint8 CanConfigSet_Tx_ACAN_ADAS_02_ADAS_LSS_HandsoffWarn : 3;
    uint8 CanConfigSet_Tx_ACAN_ADAS_02_ADAS_LSS_FuncResp : 1;
    uint8 unused1 : 2;
    uint8 CanConfigSet_Tx_ACAN_ADAS_02_ADAS_EPS_AngReqSts : 2;
    uint8 CanConfigSet_Tx_ACAN_ADAS_02_ADAS_LSS_LeLineTrackingSts : 2;
    uint8 CanConfigSet_Tx_ACAN_ADAS_02_ADAS_LSS_RiLineTrackingSts : 2;
} TxPdu_CanConfigSet_Tx_ACAN_ADAS_02_BufType;
extern VAR(TxPdu_CanConfigSet_Tx_ACAN_ADAS_02_BufType, COM_VAR_NOINIT) Com_TxPdu_CanConfigSet_Tx_ACAN_ADAS_02 ;

typedef struct
{
    uint8 CanConfigSet_Tx_ACAN_ADAS_03_ADAS_03_Checksum : 8;
    uint8 CanConfigSet_Tx_ACAN_ADAS_03_ADAS_AccelerationReq_Byte1 : 4;
    uint8 CanConfigSet_Tx_ACAN_ADAS_03_ADAS_03_RollingCounter : 4;
    uint8 CanConfigSet_Tx_ACAN_ADAS_03_ADAS_AccelerationReq_Byte0 : 8;
    uint8 CanConfigSet_Tx_ACAN_ADAS_03_ADAS_AEB_TgtDecel_ReqValue_Byte1 : 8;
    uint8 CanConfigSet_Tx_ACAN_ADAS_03_ADAS_AEB_TgtDecel_ReqValue_Byte0 : 8;
    uint8 CanConfigSet_Tx_ACAN_ADAS_03_ADAS_MaxSoftAcceleration_Byte1 : 8;
    uint8 CanConfigSet_Tx_ACAN_ADAS_03_ADAS_MinSoftAcceleration_Byte1 : 4;
    uint8 CanConfigSet_Tx_ACAN_ADAS_03_ADAS_MaxSoftAcceleration_Byte0 : 4;
    uint8 CanConfigSet_Tx_ACAN_ADAS_03_ADAS_MinSoftAcceleration_Byte0 : 8;
} TxPdu_CanConfigSet_Tx_ACAN_ADAS_03_BufType;
extern VAR(TxPdu_CanConfigSet_Tx_ACAN_ADAS_03_BufType, COM_VAR_NOINIT) Com_TxPdu_CanConfigSet_Tx_ACAN_ADAS_03 ;

typedef struct
{
    uint8 unused0_Byte0 : 8;
    uint8 unused0_Byte1 : 8;
    uint8 unused0_Byte2 : 2;
    uint8 CanConfigSet_Tx_ACAN_ADAS_04_ADAS_IBS_StopReq : 1;
    uint8 unused1 : 1;
    uint8 CanConfigSet_Tx_ACAN_ADAS_04_ADAS_IBS_CarStarting : 1;
    uint8 CanConfigSet_Tx_ACAN_ADAS_04_ADAS_ACC_BrakePreferred : 1;
    uint8 unused2 : 2;
    uint8 CanConfigSet_Tx_ACAN_ADAS_04_ADAS_AEB_AbpReq : 1;
    uint8 unused3 : 1;
    uint8 CanConfigSet_Tx_ACAN_ADAS_04_ADAS_IBS_EBAReq : 1;
    uint8 CanConfigSet_Tx_ACAN_ADAS_04_ADAS_IBS_MinBreakReq : 1;
    uint8 unused4 : 2;
    uint8 CanConfigSet_Tx_ACAN_ADAS_04_ADAS_VLCShutDownReq : 2;
    uint8 CanConfigSet_Tx_ACAN_ADAS_04_ADAS_VLCModeReq : 4;
    uint8 CanConfigSet_Tx_ACAN_ADAS_04_AEB_AWB_Level : 4;
    uint8 CanConfigSet_Tx_ACAN_ADAS_04_AEB_ABA_Req : 1;
    uint8 CanConfigSet_Tx_ACAN_ADAS_04_AEB_VehHldReq : 1;
    uint8 CanConfigSet_Tx_ACAN_ADAS_04_AEB_TgtDecel_Req : 1;
    uint8 CanConfigSet_Tx_ACAN_ADAS_04_AEB_AWB_Req : 1;
    uint8 CanConfigSet_Tx_ACAN_ADAS_04_ADAS_AEB_AbaLevel : 2;
    uint8 unused5 : 2;
    uint8 CanConfigSet_Tx_ACAN_ADAS_04_ACC_AdtUpperJerkLimit : 8;
    uint8 CanConfigSet_Tx_ACAN_ADAS_04_ACC_AdtLowerJerkLimit : 8;
} TxPdu_CanConfigSet_Tx_ACAN_ADAS_04_BufType;
extern VAR(TxPdu_CanConfigSet_Tx_ACAN_ADAS_04_BufType, COM_VAR_NOINIT) Com_TxPdu_CanConfigSet_Tx_ACAN_ADAS_04 ;

typedef struct
{
    uint8 unused0_Byte0 : 8;
    uint8 unused0_Byte1 : 8;
    uint8 unused0_Byte2 : 1;
    uint8 CanConfigSet_Tx_ACAN_ADAS_06_ADAS_TSR_SWSts : 1;
    uint8 CanConfigSet_Tx_ACAN_ADAS_06_TSR_SLWSwtResp : 1;
    uint8 unused1 : 1;
    uint8 CanConfigSet_Tx_ACAN_ADAS_06_ADAS_TSR_OperationSts : 3;
    uint8 unused2 : 1;
    uint8 CanConfigSet_Tx_ACAN_ADAS_06_ADAS_TSR_SpeedLimit : 6;
    uint8 unused3_Byte0 : 2;
    uint8 unused3_Byte1 : 1;
    uint8 CanConfigSet_Tx_ACAN_ADAS_06_ADAS_LSS_Available : 1;
    uint8 CanConfigSet_Tx_ACAN_ADAS_06_ADAS_LSS_FunSts : 2;
    uint8 unused4 : 3;
    uint8 CanConfigSet_Tx_ACAN_ADAS_06_ADAS_LSS_ErrSts : 1;
    uint8 unused5_Byte0 : 8;
    uint8 unused5_Byte1 : 2;
    uint8 CanConfigSet_Tx_ACAN_ADAS_06_ADAS_LSS_WarnFromResp : 2;
    uint8 CanConfigSet_Tx_ACAN_ADAS_06_FC_CalibrationSts : 2;
    uint8 CanConfigSet_Tx_ACAN_ADAS_06_FC_BlockageSts : 1;
    uint8 unused6_Byte0 : 1;
    uint8 unused6_Byte1 : 8;
} TxPdu_CanConfigSet_Tx_ACAN_ADAS_06_BufType;
extern VAR(TxPdu_CanConfigSet_Tx_ACAN_ADAS_06_BufType, COM_VAR_NOINIT) Com_TxPdu_CanConfigSet_Tx_ACAN_ADAS_06 ;

typedef struct
{
    uint8 unused0_Byte0 : 8;
    uint8 unused0_Byte1 : 8;
    uint8 CanConfigSet_Tx_ACAN_ADAS_07_ADAS_APA_OperationSts : 3;
    uint8 CanConfigSet_Tx_ACAN_ADAS_07_ADAS_APA_ModeSelect : 2;
    uint8 CanConfigSet_Tx_ACAN_ADAS_07_ADAS_APA_SystemSts : 3;
    uint8 CanConfigSet_Tx_ACAN_ADAS_07_ADAS_APA_OverspeedAlarm : 1;
    uint8 CanConfigSet_Tx_ACAN_ADAS_07_ADAS_APA_StartParkingReq : 1;
    uint8 CanConfigSet_Tx_ACAN_ADAS_07_ADAS_APA_RenewParkingReq : 1;
    uint8 unused1 : 1;
    uint8 CanConfigSet_Tx_ACAN_ADAS_07_ADAS_APA_PauseWarning : 4;
    uint8 CanConfigSet_Tx_ACAN_ADAS_07_ADAS_APA_AbortWarning : 8;
    uint8 CanConfigSet_Tx_ACAN_ADAS_07_ADAS_APA_ParkingType : 2;
    uint8 CanConfigSet_Tx_ACAN_ADAS_07_ADAS_APA_ParkingDirection : 2;
    uint8 unused2 : 4;
    uint8 CanConfigSet_Tx_ACAN_ADAS_07_ADAS_APA_SuggestedID : 8;
    uint8 unused3 : 8;
} TxPdu_CanConfigSet_Tx_ACAN_ADAS_07_BufType;
extern VAR(TxPdu_CanConfigSet_Tx_ACAN_ADAS_07_BufType, COM_VAR_NOINIT) Com_TxPdu_CanConfigSet_Tx_ACAN_ADAS_07 ;

typedef struct
{
    uint8 unused0_Byte0 : 8;
    uint8 unused0_Byte1 : 8;
    uint8 CanConfigSet_Tx_ACAN_ADAS_08_ADAS_FrontCamera_Fault : 1;
    uint8 CanConfigSet_Tx_ACAN_ADAS_08_ADAS_RearCamera_Fault : 1;
    uint8 CanConfigSet_Tx_ACAN_ADAS_08_ADAS_LeftCamera_Fault : 1;
    uint8 CanConfigSet_Tx_ACAN_ADAS_08_ADAS_RightCamera_Fault : 1;
    uint8 CanConfigSet_Tx_ACAN_ADAS_08_ADAS_ECU_Fault : 1;
    uint8 unused1_Byte0 : 3;
    uint8 unused1_Byte1 : 8;
    uint8 unused1_Byte2 : 8;
    uint8 unused1_Byte3 : 8;
    uint8 CanConfigSet_Tx_ACAN_ADAS_08_ACC_TxtInfoForDriver : 5;
    uint8 CanConfigSet_Tx_ACAN_ADAS_08_ACC_DriveoffReq : 3;
    uint8 unused2 : 8;
} TxPdu_CanConfigSet_Tx_ACAN_ADAS_08_BufType;
extern VAR(TxPdu_CanConfigSet_Tx_ACAN_ADAS_08_BufType, COM_VAR_NOINIT) Com_TxPdu_CanConfigSet_Tx_ACAN_ADAS_08 ;

typedef struct
{
    uint8 unused0_Byte0 : 8;
    uint8 unused0_Byte1 : 8;
    uint8 CanConfigSet_Tx_ACAN_ADAS_Info15_ADAS_AEB_FuncSWResp : 1;
    uint8 CanConfigSet_Tx_ACAN_ADAS_Info15_AEB_FuncSts : 1;
    uint8 CanConfigSet_Tx_ACAN_ADAS_Info15_AEB_VehActive : 1;
    uint8 CanConfigSet_Tx_ACAN_ADAS_Info15_AEB_VRUActive : 1;
    uint8 CanConfigSet_Tx_ACAN_ADAS_Info15_AEB_ErrorSts : 2;
    uint8 CanConfigSet_Tx_ACAN_ADAS_Info15_AEB_FCW_SnvtyResp : 2;
    uint8 CanConfigSet_Tx_ACAN_ADAS_Info15_TSR_TrafSign : 8;
    uint8 CanConfigSet_Tx_ACAN_ADAS_Info15_TSR_SpdAssistInfoDisp : 8;
    uint8 CanConfigSet_Tx_ACAN_ADAS_Info15_TSR_Warning_offset : 4;
    uint8 CanConfigSet_Tx_ACAN_ADAS_Info15_TSR_SLWVisualWarn : 1;
    uint8 CanConfigSet_Tx_ACAN_ADAS_Info15_TSR_SLWVoiceWarn : 1;
    uint8 CanConfigSet_Tx_ACAN_ADAS_Info15_AEB_FCW_Warning : 2;
    uint8 unused1_Byte0 : 8;
    uint8 unused1_Byte1 : 8;
} TxPdu_CanConfigSet_Tx_ACAN_ADAS_Info15_BufType;
extern VAR(TxPdu_CanConfigSet_Tx_ACAN_ADAS_Info15_BufType, COM_VAR_NOINIT) Com_TxPdu_CanConfigSet_Tx_ACAN_ADAS_Info15 ;

typedef struct
{
    uint8 unused0_Byte0 : 8;
    uint8 unused0_Byte1 : 8;
    uint8 CanConfigSet_Tx_ACAN_ADAS_Info17_ADAS_APA_Soundremind : 3;
    uint8 CanConfigSet_Tx_ACAN_ADAS_Info17_ADAS_APA_ParkingModeReq : 1;
    uint8 CanConfigSet_Tx_ACAN_ADAS_Info17_ADAS_APA_OtherWarning : 3;
    uint8 unused1 : 1;
    uint8 CanConfigSet_Tx_ACAN_ADAS_Info17_ADAS_APA_RemindTxt1 : 4;
    uint8 CanConfigSet_Tx_ACAN_ADAS_Info17_ADAS_APA_RemindTxt2 : 4;
    uint8 CanConfigSet_Tx_ACAN_ADAS_Info17_ADAS_APA_LightReq : 2;
    uint8 unused2 : 2;
    uint8 CanConfigSet_Tx_ACAN_ADAS_Info17_ADAS_APA_SearchingWarning : 4;
    uint8 unused3_Byte0 : 8;
    uint8 unused3_Byte1 : 8;
    uint8 unused3_Byte2 : 8;
} TxPdu_CanConfigSet_Tx_ACAN_ADAS_Info17_BufType;
extern VAR(TxPdu_CanConfigSet_Tx_ACAN_ADAS_Info17_BufType, COM_VAR_NOINIT) Com_TxPdu_CanConfigSet_Tx_ACAN_ADAS_Info17 ;

typedef struct
{
    uint8 CanConfigSet_Tx_ACAN_ADAS_Info23_CheckSum_1F8 : 8;
    uint8 CanConfigSet_Tx_ACAN_ADAS_Info23_RollingCounter_1F8 : 4;
    uint8 CanConfigSet_Tx_ACAN_ADAS_Info23_APA_EPS_AngReqSts : 1;
    uint8 unused0 : 3;
    uint8 CanConfigSet_Tx_ACAN_ADAS_Info23_APA_EPS_TargetSteeringAngle_Byte1 : 8;
    uint8 CanConfigSet_Tx_ACAN_ADAS_Info23_APA_EPS_TargetSteeringAngle_Byte0 : 8;
    uint8 CanConfigSet_Tx_ACAN_ADAS_Info23_ADAS_APA_BrakeModeSts : 3;
    uint8 unused1 : 1;
    uint8 CanConfigSet_Tx_ACAN_ADAS_Info23_APA_WCBS_BrakeFunctionMode : 3;
    uint8 unused2 : 1;
    uint8 CanConfigSet_Tx_ACAN_ADAS_Info23_APA_WCBS_TargetStopDistance_Byte1 : 4;
    uint8 CanConfigSet_Tx_ACAN_ADAS_Info23_APA_WCBS_BrakeMode : 3;
    uint8 unused3 : 1;
    uint8 CanConfigSet_Tx_ACAN_ADAS_Info23_APA_WCBS_TargetStopDistance_Byte0 : 8;
    uint8 CanConfigSet_Tx_ACAN_ADAS_Info23_APA_WCBS_ExpectedGearPosition : 3;
    uint8 CanConfigSet_Tx_ACAN_ADAS_Info23_APA_WCBS_SpeedLimitation : 5;
} TxPdu_CanConfigSet_Tx_ACAN_ADAS_Info23_BufType;
extern VAR(TxPdu_CanConfigSet_Tx_ACAN_ADAS_Info23_BufType, COM_VAR_NOINIT) Com_TxPdu_CanConfigSet_Tx_ACAN_ADAS_Info23 ;

typedef struct
{
    uint8 CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info1_APA_slot_1 : 8;
    uint8 CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info1_APA_slot_ID_1_P0_X_Byte1 : 8;
    uint8 CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info1_APA_slot_ID_1_P0_Y_Byte2 : 2;
    uint8 CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info1_APA_slot_ID_1_P0_X_Byte0 : 6;
    uint8 CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info1_APA_slot_ID_1_P0_Y_Byte1 : 8;
    uint8 CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info1_APA_slot_ID_1_P1_X_Byte2 : 4;
    uint8 CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info1_APA_slot_ID_1_P0_Y_Byte0 : 4;
    uint8 CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info1_APA_slot_ID_1_P1_X_Byte1 : 8;
    uint8 CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info1_APA_slot_ID_1_P1_Y_Byte1 : 6;
    uint8 CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info1_APA_slot_ID_1_P1_X_Byte0 : 2;
    uint8 CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info1_APA_slot_ID_1_P1_Y_Byte0 : 8;
} TxPdu_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info1_BufType;
extern VAR(TxPdu_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info1_BufType, COM_VAR_NOINIT) Com_TxPdu_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info1 ;

typedef struct
{
    uint8 CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info3_APA_slot_2 : 8;
    uint8 CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info3_APA_slot_ID_2_P0_X_Byte1 : 8;
    uint8 CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info3_APA_slot_ID_2_P0_Y_Byte2 : 2;
    uint8 CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info3_APA_slot_ID_2_P0_X_Byte0 : 6;
    uint8 CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info3_APA_slot_ID_2_P0_Y_Byte1 : 8;
    uint8 CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info3_APA_slot_ID_2_P1_X_Byte2 : 4;
    uint8 CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info3_APA_slot_ID_2_P0_Y_Byte0 : 4;
    uint8 CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info3_APA_slot_ID_2_P1_X_Byte1 : 8;
    uint8 CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info3_APA_slot_ID_2_P1_Y_Byte1 : 6;
    uint8 CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info3_APA_slot_ID_2_P1_X_Byte0 : 2;
    uint8 CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info3_APA_slot_ID_2_P1_Y_Byte0 : 8;
} TxPdu_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info3_BufType;
extern VAR(TxPdu_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info3_BufType, COM_VAR_NOINIT) Com_TxPdu_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info3 ;

typedef struct
{
    uint8 CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info5_APA_slot_3 : 8;
    uint8 CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info5_APA_slot_ID_3_P0_X_Byte1 : 8;
    uint8 CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info5_APA_slot_ID_3_P0_Y_Byte2 : 2;
    uint8 CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info5_APA_slot_ID_3_P0_X_Byte0 : 6;
    uint8 CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info5_APA_slot_ID_3_P0_Y_Byte1 : 8;
    uint8 CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info5_APA_slot_ID_3_P1_X_Byte2 : 4;
    uint8 CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info5_APA_slot_ID_3_P0_Y_Byte0 : 4;
    uint8 CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info5_APA_slot_ID_3_P1_X_Byte1 : 8;
    uint8 CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info5_APA_slot_ID_3_P1_Y_Byte1 : 6;
    uint8 CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info5_APA_slot_ID_3_P1_X_Byte0 : 2;
    uint8 CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info5_APA_slot_ID_3_P1_Y_Byte0 : 8;
} TxPdu_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info5_BufType;
extern VAR(TxPdu_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info5_BufType, COM_VAR_NOINIT) Com_TxPdu_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info5 ;

typedef struct
{
    uint8 CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info7_APA_slot_4 : 8;
    uint8 CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info7_APA_slot_ID_4_P0_X_Byte1 : 8;
    uint8 CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info7_APA_slot_ID_4_P0_Y_Byte2 : 2;
    uint8 CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info7_APA_slot_ID_4_P0_X_Byte0 : 6;
    uint8 CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info7_APA_slot_ID_4_P0_Y_Byte1 : 8;
    uint8 CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info7_APA_slot_ID_4_P1_X_Byte2 : 4;
    uint8 CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info7_APA_slot_ID_4_P0_Y_Byte0 : 4;
    uint8 CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info7_APA_slot_ID_4_P1_X_Byte1 : 8;
    uint8 CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info7_APA_slot_ID_4_P1_Y_Byte1 : 6;
    uint8 CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info7_APA_slot_ID_4_P1_X_Byte0 : 2;
    uint8 CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info7_APA_slot_ID_4_P1_Y_Byte0 : 8;
} TxPdu_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info7_BufType;
extern VAR(TxPdu_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info7_BufType, COM_VAR_NOINIT) Com_TxPdu_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info7 ;

typedef struct
{
    uint8 CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info9_APA_slot_5 : 8;
    uint8 CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info9_APA_slot_ID_5_P0_X_Byte1 : 8;
    uint8 CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info9_APA_slot_ID_5_P0_Y_Byte2 : 2;
    uint8 CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info9_APA_slot_ID_5_P0_X_Byte0 : 6;
    uint8 CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info9_APA_slot_ID_5_P0_Y_Byte1 : 8;
    uint8 CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info9_APA_slot_ID_5_P1_X_Byte2 : 4;
    uint8 CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info9_APA_slot_ID_5_P0_Y_Byte0 : 4;
    uint8 CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info9_APA_slot_ID_5_P1_X_Byte1 : 8;
    uint8 CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info9_APA_slot_ID_5_P1_Y_Byte1 : 6;
    uint8 CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info9_APA_slot_ID_5_P1_X_Byte0 : 2;
    uint8 CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info9_APA_slot_ID_5_P1_Y_Byte0 : 8;
} TxPdu_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info9_BufType;
extern VAR(TxPdu_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info9_BufType, COM_VAR_NOINIT) Com_TxPdu_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info9 ;

typedef struct
{
    uint8 CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info11_APA_slot_6 : 8;
    uint8 CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info11_APA_slot_ID_6_P0_X_Byte1 : 8;
    uint8 CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info11_APA_slot_ID_6_P0_Y_Byte2 : 2;
    uint8 CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info11_APA_slot_ID_6_P0_X_Byte0 : 6;
    uint8 CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info11_APA_slot_ID_6_P0_Y_Byte1 : 8;
    uint8 CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info11_APA_slot_ID_6_P1_X_Byte2 : 4;
    uint8 CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info11_APA_slot_ID_6_P0_Y_Byte0 : 4;
    uint8 CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info11_APA_slot_ID_6_P1_X_Byte1 : 8;
    uint8 CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info11_APA_slot_ID_6_P1_Y_Byte1 : 6;
    uint8 CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info11_APA_slot_ID_6_P1_X_Byte0 : 2;
    uint8 CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info11_APA_slot_ID_6_P1_Y_Byte0 : 8;
} TxPdu_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info11_BufType;
extern VAR(TxPdu_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info11_BufType, COM_VAR_NOINIT) Com_TxPdu_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info11 ;

typedef struct
{
    uint8 CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info13_APA_slot_7 : 8;
    uint8 CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info13_APA_slot_ID_7_P0_X_Byte1 : 8;
    uint8 CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info13_APA_slot_ID_7_P0_Y_Byte2 : 2;
    uint8 CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info13_APA_slot_ID_7_P0_X_Byte0 : 6;
    uint8 CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info13_APA_slot_ID_7_P0_Y_Byte1 : 8;
    uint8 CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info13_APA_slot_ID_7_P1_X_Byte2 : 4;
    uint8 CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info13_APA_slot_ID_7_P0_Y_Byte0 : 4;
    uint8 CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info13_APA_slot_ID_7_P1_X_Byte1 : 8;
    uint8 CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info13_APA_slot_ID_7_P1_Y_Byte1 : 6;
    uint8 CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info13_APA_slot_ID_7_P1_X_Byte0 : 2;
    uint8 CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info13_APA_slot_ID_7_P1_Y_Byte0 : 8;
} TxPdu_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info13_BufType;
extern VAR(TxPdu_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info13_BufType, COM_VAR_NOINIT) Com_TxPdu_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info13 ;

typedef struct
{
    uint8 CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info15_APA_slot_8 : 8;
    uint8 CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info15_APA_slot_ID_8_P0_X_Byte1 : 8;
    uint8 CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info15_APA_slot_ID_8_P0_Y_Byte2 : 2;
    uint8 CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info15_APA_slot_ID_8_P0_X_Byte0 : 6;
    uint8 CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info15_APA_slot_ID_8_P0_Y_Byte1 : 8;
    uint8 CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info15_APA_slot_ID_8_P1_X_Byte2 : 4;
    uint8 CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info15_APA_slot_ID_8_P0_Y_Byte0 : 4;
    uint8 CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info15_APA_slot_ID_8_P1_X_Byte1 : 8;
    uint8 CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info15_APA_slot_ID_8_P1_Y_Byte1 : 6;
    uint8 CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info15_APA_slot_ID_8_P1_X_Byte0 : 2;
    uint8 CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info15_APA_slot_ID_8_P1_Y_Byte0 : 8;
} TxPdu_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info15_BufType;
extern VAR(TxPdu_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info15_BufType, COM_VAR_NOINIT) Com_TxPdu_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info15 ;

typedef struct
{
    uint8 CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info17_APA_slot_9 : 8;
    uint8 CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info17_APA_slot_ID_9_P0_X_Byte1 : 8;
    uint8 CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info17_APA_slot_ID_9_P0_Y_Byte2 : 2;
    uint8 CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info17_APA_slot_ID_9_P0_X_Byte0 : 6;
    uint8 CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info17_APA_slot_ID_9_P0_Y_Byte1 : 8;
    uint8 CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info17_APA_slot_ID_9_P1_X_Byte2 : 4;
    uint8 CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info17_APA_slot_ID_9_P0_Y_Byte0 : 4;
    uint8 CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info17_APA_slot_ID_9_P1_X_Byte1 : 8;
    uint8 CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info17_APA_slot_ID_9_P1_Y_Byte1 : 6;
    uint8 CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info17_APA_slot_ID_9_P1_X_Byte0 : 2;
    uint8 CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info17_APA_slot_ID_9_P1_Y_Byte0 : 8;
} TxPdu_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info17_BufType;
extern VAR(TxPdu_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info17_BufType, COM_VAR_NOINIT) Com_TxPdu_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info17 ;

typedef struct
{
    uint8 CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info19_APA_slot_10 : 8;
    uint8 CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info19_APA_slot_ID_10_P0_X_Byte1 : 8;
    uint8 CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info19_APA_slot_ID_10_P0_Y_Byte2 : 2;
    uint8 CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info19_APA_slot_ID_10_P0_X_Byte0 : 6;
    uint8 CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info19_APA_slot_ID_10_P0_Y_Byte1 : 8;
    uint8 CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info19_APA_slot_ID_10_P1_X_Byte2 : 4;
    uint8 CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info19_APA_slot_ID_10_P0_Y_Byte0 : 4;
    uint8 CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info19_APA_slot_ID_10_P1_X_Byte1 : 8;
    uint8 CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info19_APA_slot_ID_10_P1_Y_Byte1 : 6;
    uint8 CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info19_APA_slot_ID_10_P1_X_Byte0 : 2;
    uint8 CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info19_APA_slot_ID_10_P1_Y_Byte0 : 8;
} TxPdu_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info19_BufType;
extern VAR(TxPdu_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info19_BufType, COM_VAR_NOINIT) Com_TxPdu_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info19 ;

typedef struct
{
    uint8 CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info21_APA_slot_11 : 8;
    uint8 CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info21_APA_slot_ID_11_P0_X_Byte1 : 8;
    uint8 CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info21_APA_slot_ID_11_P0_Y_Byte2 : 2;
    uint8 CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info21_APA_slot_ID_11_P0_X_Byte0 : 6;
    uint8 CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info21_APA_slot_ID_11_P0_Y_Byte1 : 8;
    uint8 CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info21_APA_slot_ID_11_P1_X_Byte2 : 4;
    uint8 CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info21_APA_slot_ID_11_P0_Y_Byte0 : 4;
    uint8 CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info21_APA_slot_ID_11_P1_X_Byte1 : 8;
    uint8 CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info21_APA_slot_ID_11_P1_Y_Byte1 : 6;
    uint8 CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info21_APA_slot_ID_11_P1_X_Byte0 : 2;
    uint8 CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info21_APA_slot_ID_11_P1_Y_Byte0 : 8;
} TxPdu_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info21_BufType;
extern VAR(TxPdu_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info21_BufType, COM_VAR_NOINIT) Com_TxPdu_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info21 ;

typedef struct
{
    uint8 CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info23_APA_slot_12 : 8;
    uint8 CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info23_APA_slot_ID_12_P0_X_Byte1 : 8;
    uint8 CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info23_APA_slot_ID_12_P0_Y_Byte2 : 2;
    uint8 CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info23_APA_slot_ID_12_P0_X_Byte0 : 6;
    uint8 CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info23_APA_slot_ID_12_P0_Y_Byte1 : 8;
    uint8 CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info23_APA_slot_ID_12_P1_X_Byte2 : 4;
    uint8 CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info23_APA_slot_ID_12_P0_Y_Byte0 : 4;
    uint8 CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info23_APA_slot_ID_12_P1_X_Byte1 : 8;
    uint8 CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info23_APA_slot_ID_12_P1_Y_Byte1 : 6;
    uint8 CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info23_APA_slot_ID_12_P1_X_Byte0 : 2;
    uint8 CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info23_APA_slot_ID_12_P1_Y_Byte0 : 8;
} TxPdu_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info23_BufType;
extern VAR(TxPdu_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info23_BufType, COM_VAR_NOINIT) Com_TxPdu_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info23 ;

typedef struct
{
    uint8 CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info2_APA_slot_ID_1_P2_X_Byte1 : 6;
    uint8 CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info2_APA_slot_ID_1_Type : 2;
    uint8 CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info2_APA_slot_ID_1_P2_X_Byte0 : 8;
    uint8 CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info2_APA_slot_ID_1_P2_Y_Byte1 : 6;
    uint8 unused0 : 2;
    uint8 CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info2_APA_slot_ID_1_P2_Y_Byte0 : 8;
    uint8 CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info2_APA_slot_ID_1_P3_X_Byte1 : 6;
    uint8 unused1 : 2;
    uint8 CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info2_APA_slot_ID_1_P3_X_Byte0 : 8;
    uint8 CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info2_APA_slot_ID_1_P3_Y_Byte1 : 6;
    uint8 unused2 : 2;
    uint8 CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info2_APA_slot_ID_1_P3_Y_Byte0 : 8;
} TxPdu_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info2_BufType;
extern VAR(TxPdu_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info2_BufType, COM_VAR_NOINIT) Com_TxPdu_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info2 ;

typedef struct
{
    uint8 CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info4_APA_slot_ID_2_P2_X_Byte1 : 6;
    uint8 CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info4_APA_slot_ID_2_Type : 2;
    uint8 CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info4_APA_slot_ID_2_P2_X_Byte0 : 8;
    uint8 CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info4_APA_slot_ID_2_P2_Y_Byte1 : 6;
    uint8 unused0 : 2;
    uint8 CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info4_APA_slot_ID_2_P2_Y_Byte0 : 8;
    uint8 CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info4_APA_slot_ID_2_P3_X_Byte1 : 6;
    uint8 unused1 : 2;
    uint8 CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info4_APA_slot_ID_2_P3_X_Byte0 : 8;
    uint8 CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info4_APA_slot_ID_2_P3_Y_Byte1 : 6;
    uint8 unused2 : 2;
    uint8 CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info4_APA_slot_ID_2_P3_Y_Byte0 : 8;
} TxPdu_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info4_BufType;
extern VAR(TxPdu_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info4_BufType, COM_VAR_NOINIT) Com_TxPdu_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info4 ;

typedef struct
{
    uint8 CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info6_APA_slot_ID_3_P2_X_Byte1 : 6;
    uint8 CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info6_APA_slot_ID_3_Type : 2;
    uint8 CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info6_APA_slot_ID_3_P2_X_Byte0 : 8;
    uint8 CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info6_APA_slot_ID_3_P2_Y_Byte1 : 6;
    uint8 unused0 : 2;
    uint8 CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info6_APA_slot_ID_3_P2_Y_Byte0 : 8;
    uint8 CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info6_APA_slot_ID_3_P3_X_Byte1 : 6;
    uint8 unused1 : 2;
    uint8 CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info6_APA_slot_ID_3_P3_X_Byte0 : 8;
    uint8 CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info6_APA_slot_ID_3_P3_Y_Byte1 : 6;
    uint8 unused2 : 2;
    uint8 CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info6_APA_slot_ID_3_P3_Y_Byte0 : 8;
} TxPdu_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info6_BufType;
extern VAR(TxPdu_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info6_BufType, COM_VAR_NOINIT) Com_TxPdu_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info6 ;

typedef struct
{
    uint8 CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info8_APA_slot_ID_4_P2_X_Byte1 : 6;
    uint8 CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info8_APA_slot_ID_4_Type : 2;
    uint8 CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info8_APA_slot_ID_4_P2_X_Byte0 : 8;
    uint8 CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info8_APA_slot_ID_4_P2_Y_Byte1 : 6;
    uint8 unused0 : 2;
    uint8 CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info8_APA_slot_ID_4_P2_Y_Byte0 : 8;
    uint8 CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info8_APA_slot_ID_4_P3_X_Byte1 : 6;
    uint8 unused1 : 2;
    uint8 CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info8_APA_slot_ID_4_P3_X_Byte0 : 8;
    uint8 CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info8_APA_slot_ID_4_P3_Y_Byte1 : 6;
    uint8 unused2 : 2;
    uint8 CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info8_APA_slot_ID_4_P3_Y_Byte0 : 8;
} TxPdu_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info8_BufType;
extern VAR(TxPdu_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info8_BufType, COM_VAR_NOINIT) Com_TxPdu_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info8 ;

typedef struct
{
    uint8 CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info10_APA_slot_ID_5_P2_X_Byte1 : 6;
    uint8 CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info10_APA_slot_ID_5_Type : 2;
    uint8 CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info10_APA_slot_ID_5_P2_X_Byte0 : 8;
    uint8 CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info10_APA_slot_ID_5_P2_Y_Byte1 : 6;
    uint8 unused0 : 2;
    uint8 CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info10_APA_slot_ID_5_P2_Y_Byte0 : 8;
    uint8 CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info10_APA_slot_ID_5_P3_X_Byte1 : 6;
    uint8 unused1 : 2;
    uint8 CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info10_APA_slot_ID_5_P3_X_Byte0 : 8;
    uint8 CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info10_APA_slot_ID_5_P3_Y_Byte1 : 6;
    uint8 unused2 : 2;
    uint8 CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info10_APA_slot_ID_5_P3_Y_Byte0 : 8;
} TxPdu_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info10_BufType;
extern VAR(TxPdu_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info10_BufType, COM_VAR_NOINIT) Com_TxPdu_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info10 ;

typedef struct
{
    uint8 CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info12_APA_slot_ID_6_P2_X_Byte1 : 6;
    uint8 CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info12_APA_slot_ID_6_Type : 2;
    uint8 CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info12_APA_slot_ID_6_P2_X_Byte0 : 8;
    uint8 CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info12_APA_slot_ID_6_P2_Y_Byte1 : 6;
    uint8 unused0 : 2;
    uint8 CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info12_APA_slot_ID_6_P2_Y_Byte0 : 8;
    uint8 CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info12_APA_slot_ID_6_P3_X_Byte1 : 6;
    uint8 unused1 : 2;
    uint8 CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info12_APA_slot_ID_6_P3_X_Byte0 : 8;
    uint8 CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info12_APA_slot_ID_6_P3_Y_Byte1 : 6;
    uint8 unused2 : 2;
    uint8 CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info12_APA_slot_ID_6_P3_Y_Byte0 : 8;
} TxPdu_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info12_BufType;
extern VAR(TxPdu_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info12_BufType, COM_VAR_NOINIT) Com_TxPdu_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info12 ;

typedef struct
{
    uint8 CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info14_APA_slot_ID_7_P2_X_Byte1 : 6;
    uint8 CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info14_APA_slot_ID_7_Type : 2;
    uint8 CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info14_APA_slot_ID_7_P2_X_Byte0 : 8;
    uint8 CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info14_APA_slot_ID_7_P2_Y_Byte1 : 6;
    uint8 unused0 : 2;
    uint8 CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info14_APA_slot_ID_7_P2_Y_Byte0 : 8;
    uint8 CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info14_APA_slot_ID_7_P3_X_Byte1 : 6;
    uint8 unused1 : 2;
    uint8 CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info14_APA_slot_ID_7_P3_X_Byte0 : 8;
    uint8 CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info14_APA_slot_ID_7_P3_Y_Byte1 : 6;
    uint8 unused2 : 2;
    uint8 CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info14_APA_slot_ID_7_P3_Y_Byte0 : 8;
} TxPdu_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info14_BufType;
extern VAR(TxPdu_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info14_BufType, COM_VAR_NOINIT) Com_TxPdu_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info14 ;

typedef struct
{
    uint8 CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info16_APA_slot_ID_8_P2_X_Byte1 : 6;
    uint8 CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info16_APA_slot_ID_8_Type : 2;
    uint8 CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info16_APA_slot_ID_8_P2_X_Byte0 : 8;
    uint8 CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info16_APA_slot_ID_8_P2_Y_Byte1 : 6;
    uint8 unused0 : 2;
    uint8 CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info16_APA_slot_ID_8_P2_Y_Byte0 : 8;
    uint8 CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info16_APA_slot_ID_8_P3_X_Byte1 : 6;
    uint8 unused1 : 2;
    uint8 CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info16_APA_slot_ID_8_P3_X_Byte0 : 8;
    uint8 CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info16_APA_slot_ID_8_P3_Y_Byte1 : 6;
    uint8 unused2 : 2;
    uint8 CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info16_APA_slot_ID_8_P3_Y_Byte0 : 8;
} TxPdu_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info16_BufType;
extern VAR(TxPdu_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info16_BufType, COM_VAR_NOINIT) Com_TxPdu_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info16 ;

typedef struct
{
    uint8 CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info18_APA_slot_ID_9_P2_X_Byte1 : 6;
    uint8 CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info18_APA_slot_ID_9_Type : 2;
    uint8 CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info18_APA_slot_ID_9_P2_X_Byte0 : 8;
    uint8 CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info18_APA_slot_ID_9_P2_Y_Byte1 : 6;
    uint8 unused0 : 2;
    uint8 CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info18_APA_slot_ID_9_P2_Y_Byte0 : 8;
    uint8 CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info18_APA_slot_ID_9_P3_X_Byte1 : 6;
    uint8 unused1 : 2;
    uint8 CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info18_APA_slot_ID_9_P3_X_Byte0 : 8;
    uint8 CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info18_APA_slot_ID_9_P3_Y_Byte1 : 6;
    uint8 unused2 : 2;
    uint8 CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info18_APA_slot_ID_9_P3_Y_Byte0 : 8;
} TxPdu_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info18_BufType;
extern VAR(TxPdu_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info18_BufType, COM_VAR_NOINIT) Com_TxPdu_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info18 ;

typedef struct
{
    uint8 CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info20_APA_slot_ID_10_P2_X_Byte1 : 6;
    uint8 CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info20_APA_slot_ID_10_Type : 2;
    uint8 CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info20_APA_slot_ID_10_P2_X_Byte0 : 8;
    uint8 CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info20_APA_slot_ID_10_P2_Y_Byte1 : 6;
    uint8 unused0 : 2;
    uint8 CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info20_APA_slot_ID_10_P2_Y_Byte0 : 8;
    uint8 CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info20_APA_slot_ID_10_P3_X_Byte1 : 6;
    uint8 unused1 : 2;
    uint8 CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info20_APA_slot_ID_10_P3_X_Byte0 : 8;
    uint8 CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info20_APA_slot_ID_10_P3_Y_Byte1 : 6;
    uint8 unused2 : 2;
    uint8 CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info20_APA_slot_ID_10_P3_Y_Byte0 : 8;
} TxPdu_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info20_BufType;
extern VAR(TxPdu_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info20_BufType, COM_VAR_NOINIT) Com_TxPdu_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info20 ;

typedef struct
{
    uint8 CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info22_APA_slot_ID_11_P2_X_Byte1 : 6;
    uint8 CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info22_APA_slot_ID_11_Type : 2;
    uint8 CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info22_APA_slot_ID_11_P2_X_Byte0 : 8;
    uint8 CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info22_APA_slot_ID_11_P2_Y_Byte1 : 6;
    uint8 unused0 : 2;
    uint8 CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info22_APA_slot_ID_11_P2_Y_Byte0 : 8;
    uint8 CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info22_APA_slot_ID_11_P3_X_Byte1 : 6;
    uint8 unused1 : 2;
    uint8 CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info22_APA_slot_ID_11_P3_X_Byte0 : 8;
    uint8 CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info22_APA_slot_ID_11_P3_Y_Byte1 : 6;
    uint8 unused2 : 2;
    uint8 CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info22_APA_slot_ID_11_P3_Y_Byte0 : 8;
} TxPdu_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info22_BufType;
extern VAR(TxPdu_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info22_BufType, COM_VAR_NOINIT) Com_TxPdu_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info22 ;

typedef struct
{
    uint8 CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info24_APA_slot_ID_12_P2_X_Byte1 : 6;
    uint8 CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info24_APA_slot_ID_12_Type : 2;
    uint8 CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info24_APA_slot_ID_12_P2_X_Byte0 : 8;
    uint8 CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info24_APA_slot_ID_12_P2_Y_Byte1 : 6;
    uint8 unused0 : 2;
    uint8 CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info24_APA_slot_ID_12_P2_Y_Byte0 : 8;
    uint8 CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info24_APA_slot_ID_12_P3_X_Byte1 : 6;
    uint8 unused1 : 2;
    uint8 CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info24_APA_slot_ID_12_P3_X_Byte0 : 8;
    uint8 CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info24_APA_slot_ID_12_P3_Y_Byte1 : 6;
    uint8 unused2 : 2;
    uint8 CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info24_APA_slot_ID_12_P3_Y_Byte0 : 8;
} TxPdu_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info24_BufType;
extern VAR(TxPdu_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info24_BufType, COM_VAR_NOINIT) Com_TxPdu_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info24 ;

typedef struct
{
    uint8 CanConfigSet_Tx_ACAN_ADAS_Info20_APA_FrontSystemSts : 2;
    uint8 CanConfigSet_Tx_ACAN_ADAS_Info20_APA_RearSystemSts : 2;
    uint8 CanConfigSet_Tx_ACAN_ADAS_Info20_APA_ChimeRequest : 4;
    uint8 CanConfigSet_Tx_ACAN_ADAS_Info20_APA_FRegion1ObjectSts : 3;
    uint8 unused0 : 1;
    uint8 CanConfigSet_Tx_ACAN_ADAS_Info20_APA_FRegion2ObjectSts : 3;
    uint8 unused1 : 1;
    uint8 CanConfigSet_Tx_ACAN_ADAS_Info20_APA_FRegion3ObjectSts : 3;
    uint8 unused2 : 1;
    uint8 CanConfigSet_Tx_ACAN_ADAS_Info20_APA_FRegion4ObjectSts : 3;
    uint8 unused3 : 1;
    uint8 CanConfigSet_Tx_ACAN_ADAS_Info20_APA_FrontExtenedDistance : 8;
    uint8 CanConfigSet_Tx_ACAN_ADAS_Info20_APA_ParkAssistRRegion1ObjectSts : 3;
    uint8 unused4 : 1;
    uint8 CanConfigSet_Tx_ACAN_ADAS_Info20_APA_ParkAssistRRegion2ObjectSts : 3;
    uint8 unused5 : 1;
    uint8 CanConfigSet_Tx_ACAN_ADAS_Info20_APA_ParkAssistRRegion3ObjectSts : 3;
    uint8 unused6 : 1;
    uint8 CanConfigSet_Tx_ACAN_ADAS_Info20_APA_ParkAssistRRegion4ObjectSts : 3;
    uint8 unused7 : 1;
    uint8 CanConfigSet_Tx_ACAN_ADAS_Info20_APA_ParkAssistRExtenedDistance : 8;
    uint8 unused8 : 8;
} TxPdu_CanConfigSet_Tx_ACAN_ADAS_Info20_BufType;
extern VAR(TxPdu_CanConfigSet_Tx_ACAN_ADAS_Info20_BufType, COM_VAR_NOINIT) Com_TxPdu_CanConfigSet_Tx_ACAN_ADAS_Info20 ;

typedef struct
{
    uint8 CanConfigSet_Tx_ACAN_ADAS_Info21_FLS_ExtenedDistance_Byte1 : 8;
    uint8 CanConfigSet_Tx_ACAN_ADAS_Info21_ADAS_USS_FaultFLI : 1;
    uint8 CanConfigSet_Tx_ACAN_ADAS_Info21_ADAS_USS_FaultFRI : 1;
    uint8 CanConfigSet_Tx_ACAN_ADAS_Info21_ADAS_USS_FaultFLO : 1;
    uint8 CanConfigSet_Tx_ACAN_ADAS_Info21_ADAS_USS_FaultFRO : 1;
    uint8 CanConfigSet_Tx_ACAN_ADAS_Info21_ADAS_USS_FaultFLS : 1;
    uint8 CanConfigSet_Tx_ACAN_ADAS_Info21_ADAS_USS_FaultFRS : 1;
    uint8 unused0 : 1;
    uint8 CanConfigSet_Tx_ACAN_ADAS_Info21_FLS_ExtenedDistance_Byte0 : 1;
    uint8 CanConfigSet_Tx_ACAN_ADAS_Info21_FRS_ExtenedDistance_Byte1 : 1;
    uint8 unused1 : 7;
    uint8 CanConfigSet_Tx_ACAN_ADAS_Info21_FRS_ExtenedDistance_Byte0 : 8;
    uint8 CanConfigSet_Tx_ACAN_ADAS_Info21_FLC_ExtenedDistance : 8;
    uint8 CanConfigSet_Tx_ACAN_ADAS_Info21_FLM_ExtenedDistance : 8;
    uint8 CanConfigSet_Tx_ACAN_ADAS_Info21_FRM_ExtenedDistance : 8;
    uint8 CanConfigSet_Tx_ACAN_ADAS_Info21_FRC_ExtenedDistance : 8;
} TxPdu_CanConfigSet_Tx_ACAN_ADAS_Info21_BufType;
extern VAR(TxPdu_CanConfigSet_Tx_ACAN_ADAS_Info21_BufType, COM_VAR_NOINIT) Com_TxPdu_CanConfigSet_Tx_ACAN_ADAS_Info21 ;

typedef struct
{
    uint8 CanConfigSet_Tx_ACAN_ADAS_Info22_RLS_ExtenedDistance_Byte1 : 8;
    uint8 CanConfigSet_Tx_ACAN_ADAS_Info22_ADAS_USS_FaultRLI : 1;
    uint8 CanConfigSet_Tx_ACAN_ADAS_Info22_ADAS_USS_FaultRLO : 1;
    uint8 CanConfigSet_Tx_ACAN_ADAS_Info22_ADAS_USS_FaultRRI : 1;
    uint8 CanConfigSet_Tx_ACAN_ADAS_Info22_ADAS_USS_FaultRRO : 1;
    uint8 CanConfigSet_Tx_ACAN_ADAS_Info22_ADAS_USS_FaultRLS : 1;
    uint8 CanConfigSet_Tx_ACAN_ADAS_Info22_ADAS_USS_FaultRRS : 1;
    uint8 unused0 : 1;
    uint8 CanConfigSet_Tx_ACAN_ADAS_Info22_RLS_ExtenedDistance_Byte0 : 1;
    uint8 CanConfigSet_Tx_ACAN_ADAS_Info22_RRS_ExtenedDistance_Byte1 : 1;
    uint8 unused1 : 7;
    uint8 CanConfigSet_Tx_ACAN_ADAS_Info22_RRS_ExtenedDistance_Byte0 : 8;
    uint8 CanConfigSet_Tx_ACAN_ADAS_Info22_RLC_ExtenedDistance : 8;
    uint8 CanConfigSet_Tx_ACAN_ADAS_Info22_RLM_ExtenedDistance : 8;
    uint8 CanConfigSet_Tx_ACAN_ADAS_Info22_RRM_ExtenedDistance : 8;
    uint8 CanConfigSet_Tx_ACAN_ADAS_Info22_RRC_ExtenedDistance : 8;
} TxPdu_CanConfigSet_Tx_ACAN_ADAS_Info22_BufType;
extern VAR(TxPdu_CanConfigSet_Tx_ACAN_ADAS_Info22_BufType, COM_VAR_NOINIT) Com_TxPdu_CanConfigSet_Tx_ACAN_ADAS_Info22 ;

typedef struct
{
    uint8 Tcp_SendSignal[9];
} TxPdu_Tcp_Send_BufType;
extern VAR(TxPdu_Tcp_Send_BufType, COM_VAR_NOINIT) Com_TxPdu_Tcp_Send ;

typedef struct
{
    uint8 Udp_SendSignal[9];
} TxPdu_Udp_Send_BufType;
extern VAR(TxPdu_Udp_Send_BufType, COM_VAR_NOINIT) Com_TxPdu_Udp_Send ;

typedef struct
{
    uint8 Udp_SendSignal_1501[594];
} TxPdu_Udp_Send_1501_BufType;
extern VAR(TxPdu_Udp_Send_1501_BufType, COM_VAR_NOINIT) Com_TxPdu_Udp_Send_1501 ;

typedef struct
{
    uint8 Udp_SendSignal_1502[1294];
} TxPdu_Udp_Send_1502_BufType;
extern VAR(TxPdu_Udp_Send_1502_BufType, COM_VAR_NOINIT) Com_TxPdu_Udp_Send_1502 ;

typedef struct
{
    uint8 Udp_SendSignal_1503[23];
} TxPdu_Udp_Send_1503_BufType;
extern VAR(TxPdu_Udp_Send_1503_BufType, COM_VAR_NOINIT) Com_TxPdu_Udp_Send_1503 ;

typedef struct
{
    uint8 Udp_SendSignal_1504[423];
} TxPdu_Udp_Send_1504_BufType;
extern VAR(TxPdu_Udp_Send_1504_BufType, COM_VAR_NOINIT) Com_TxPdu_Udp_Send_1504 ;

typedef struct
{
    uint8 Udp_SendSignal_1505[942];
} TxPdu_Udp_Send_1505_BufType;
extern VAR(TxPdu_Udp_Send_1505_BufType, COM_VAR_NOINIT) Com_TxPdu_Udp_Send_1505 ;

typedef struct
{
    uint8 Udp_SendSignal_1506[13];
} TxPdu_Udp_Send_1506_BufType;
extern VAR(TxPdu_Udp_Send_1506_BufType, COM_VAR_NOINIT) Com_TxPdu_Udp_Send_1506 ;

typedef struct
{
    uint8 Udp_SendSignal_1507[208];
} TxPdu_Udp_Send_1507_BufType;
extern VAR(TxPdu_Udp_Send_1507_BufType, COM_VAR_NOINIT) Com_TxPdu_Udp_Send_1507 ;


/******************************************************************************
*    Receive Signal structures
******************************************************************************/
/*CanConfigSet*/
typedef struct
{
    uint8 CanConfigSet_Rx_ACAN_ACU_ChimeTelltaleReq_ACU_CoDSeatOccupSensorStat : 2;
    uint8 CanConfigSet_Rx_ACAN_ACU_ChimeTelltaleReq_ACU_DSeatOccupSensorStat : 2;
    uint8 CanConfigSet_Rx_ACAN_ACU_ChimeTelltaleReq_ACU_CoDSeatbeltBucklestatus : 1;
    uint8 CanConfigSet_Rx_ACAN_ACU_ChimeTelltaleReq_ACU_DSeatbeltBucklestatus : 1;
    uint8 CanConfigSet_Rx_ACAN_ACU_ChimeTelltaleReq_ACU_CoDAirbagStatus : 1;
    uint8 CanConfigSet_Rx_ACAN_ACU_ChimeTelltaleReq_ACU_DAirbagStatus : 1;
    uint8 CanConfigSet_Rx_ACAN_ACU_ChimeTelltaleReq_ACU_RPSeatOccupSensorStat : 2;
    uint8 CanConfigSet_Rx_ACAN_ACU_ChimeTelltaleReq_ACU_MPSeatOccupSensorStat : 2;
    uint8 CanConfigSet_Rx_ACAN_ACU_ChimeTelltaleReq_ACU_LPSeatOccupSensorStat : 2;
    uint8 unused0 : 2;
    uint8 CanConfigSet_Rx_ACAN_ACU_ChimeTelltaleReq_ACU_RCABsts : 1;
    uint8 CanConfigSet_Rx_ACAN_ACU_ChimeTelltaleReq_ACU_LCABsts : 1;
    uint8 CanConfigSet_Rx_ACAN_ACU_ChimeTelltaleReq_ACU_RSABsts : 1;
    uint8 CanConfigSet_Rx_ACAN_ACU_ChimeTelltaleReq_ACU_LSABsts : 1;
    uint8 CanConfigSet_Rx_ACAN_ACU_ChimeTelltaleReq_ACU_RPSeatbeltBucklestatus : 1;
    uint8 CanConfigSet_Rx_ACAN_ACU_ChimeTelltaleReq_ACU_MPSeatbeltBucklestatus : 1;
    uint8 CanConfigSet_Rx_ACAN_ACU_ChimeTelltaleReq_ACU_LPSeatbeltBucklestatus : 1;
    uint8 unused1 : 1;
    uint8 CanConfigSet_Rx_ACAN_ACU_ChimeTelltaleReq_ACU_CrashSts : 1;
    uint8 unused2 : 3;
    uint8 CanConfigSet_Rx_ACAN_ACU_ChimeTelltaleReq_ACU_CrashRearOutputSts : 1;
    uint8 CanConfigSet_Rx_ACAN_ACU_ChimeTelltaleReq_ACU_CrashRightOutputSts : 1;
    uint8 CanConfigSet_Rx_ACAN_ACU_ChimeTelltaleReq_ACU_CrashLeftOutputSts : 1;
    uint8 CanConfigSet_Rx_ACAN_ACU_ChimeTelltaleReq_ACU_CrashFrontOutputSts : 1;
    uint8 unused3 : 4;
    uint8 CanConfigSet_Rx_ACAN_ACU_ChimeTelltaleReq_ACU_AirbagWarningStatus : 2;
    uint8 unused4_Byte0 : 2;
    uint8 unused4_Byte1 : 4;
    uint8 CanConfigSet_Rx_ACAN_ACU_ChimeTelltaleReq_ACU_CoDSeatbletPTighten : 2;
    uint8 CanConfigSet_Rx_ACAN_ACU_ChimeTelltaleReq_ACU_DSeatbletPTighten : 2;
    uint8 CanConfigSet_Rx_ACAN_ACU_ChimeTelltaleReq_ACU_AliveCounter : 4;
    uint8 unused5 : 4;
    uint8 CanConfigSet_Rx_ACAN_ACU_ChimeTelltaleReq_ACU_CheckSum : 8;
} RxPdu_CanConfigSet_Rx_ACAN_ACU_ChimeTelltaleReq_BufType;
extern VAR(RxPdu_CanConfigSet_Rx_ACAN_ACU_ChimeTelltaleReq_BufType, COM_VAR_NOINIT) Com_RxPduSignal_CanConfigSet_Rx_ACAN_ACU_ChimeTelltaleReq ;

typedef struct
{
    uint8 CanConfigSet_Rx_ACAN_BCM_LIGHT_0x106_CheckSum_0x106 : 8;
    uint8 CanConfigSet_Rx_ACAN_BCM_LIGHT_0x106_RollingCounter_0x106 : 4;
    uint8 unused0 : 4;
    uint8 CanConfigSet_Rx_ACAN_BCM_LIGHT_0x106_BCM_TurnIndicatorSts : 2;
    uint8 CanConfigSet_Rx_ACAN_BCM_LIGHT_0x106_BCM_PosLmpSts : 2;
    uint8 CanConfigSet_Rx_ACAN_BCM_LIGHT_0x106_BCM_LowBeamSts : 2;
    uint8 CanConfigSet_Rx_ACAN_BCM_LIGHT_0x106_BCM_HighBeamSts : 2;
    uint8 CanConfigSet_Rx_ACAN_BCM_LIGHT_0x106_BCM_RearFogLampLightSts : 2;
    uint8 CanConfigSet_Rx_ACAN_BCM_LIGHT_0x106_BCM_BrakeLightSts : 2;
    uint8 CanConfigSet_Rx_ACAN_BCM_LIGHT_0x106_BCM_ReverseLightSts : 2;
    uint8 CanConfigSet_Rx_ACAN_BCM_LIGHT_0x106_BCM_DayRunningLampSts : 2;
    uint8 CanConfigSet_Rx_ACAN_BCM_LIGHT_0x106_BCM_RMarkerLightSts : 2;
    uint8 CanConfigSet_Rx_ACAN_BCM_LIGHT_0x106_BCM_Rr_domelampSts : 2;
    uint8 CanConfigSet_Rx_ACAN_BCM_LIGHT_0x106_BCM_Fr_domelampSts : 2;
    uint8 CanConfigSet_Rx_ACAN_BCM_LIGHT_0x106_BCM_LicensePlateLightSts : 2;
    uint8 CanConfigSet_Rx_ACAN_BCM_LIGHT_0x106_BCM_HeadLight_adjustSts : 4;
    uint8 CanConfigSet_Rx_ACAN_BCM_LIGHT_0x106_BCM_FrontFogLampLightSts : 2;
    uint8 CanConfigSet_Rx_ACAN_BCM_LIGHT_0x106_BCM_STAT_InteriorLight : 2;
    uint8 CanConfigSet_Rx_ACAN_BCM_LIGHT_0x106_BCM_STAT_SwLightBrightness : 7;
    uint8 unused1_Byte0 : 1;
    uint8 unused1_Byte1 : 2;
    uint8 CanConfigSet_Rx_ACAN_BCM_LIGHT_0x106_BCM_TurnLight_FaultSts : 2;
    uint8 CanConfigSet_Rx_ACAN_BCM_LIGHT_0x106_BCM_AmbeLightZone2Sts : 2;
    uint8 CanConfigSet_Rx_ACAN_BCM_LIGHT_0x106_BCM_AmbeLightZone1Sts : 2;
} RxPdu_CanConfigSet_Rx_ACAN_BCM_LIGHT_0x106_BufType;
extern VAR(RxPdu_CanConfigSet_Rx_ACAN_BCM_LIGHT_0x106_BufType, COM_VAR_NOINIT) Com_RxPduSignal_CanConfigSet_Rx_ACAN_BCM_LIGHT_0x106 ;

typedef struct
{
    uint8 CanConfigSet_Rx_ACAN_BCM_SwitchSts_0x109_CheckSum_0x109 : 8;
    uint8 CanConfigSet_Rx_ACAN_BCM_SwitchSts_0x109_RollingCounter_0x109 : 4;
    uint8 unused0_Byte0 : 4;
    uint8 unused0_Byte1 : 2;
    uint8 CanConfigSet_Rx_ACAN_BCM_SwitchSts_0x109_BCM_STAT_Horn : 2;
    uint8 CanConfigSet_Rx_ACAN_BCM_SwitchSts_0x109_BCM_STAT_HazardWarn : 2;
    uint8 unused1 : 2;
    uint8 CanConfigSet_Rx_ACAN_BCM_SwitchSts_0x109_BCM_LowBeamSWSts : 2;
    uint8 CanConfigSet_Rx_ACAN_BCM_SwitchSts_0x109_BCM_TurnLightSWSts : 2;
    uint8 CanConfigSet_Rx_ACAN_BCM_SwitchSts_0x109_BCM_Tail_MicroSW : 1;
    uint8 unused2 : 1;
    uint8 CanConfigSet_Rx_ACAN_BCM_SwitchSts_0x109_STAT_Central_LockSts : 2;
    uint8 unused3 : 4;
    uint8 CanConfigSet_Rx_ACAN_BCM_SwitchSts_0x109_BCM_RFogLampSWSts : 1;
    uint8 CanConfigSet_Rx_ACAN_BCM_SwitchSts_0x109_BCM_FFogLampSWSts : 1;
    uint8 CanConfigSet_Rx_ACAN_BCM_SwitchSts_0x109_BCM_HighBeamSWSts : 2;
    uint8 unused4_Byte0 : 8;
    uint8 unused4_Byte1 : 8;
    uint8 unused4_Byte2 : 8;
} RxPdu_CanConfigSet_Rx_ACAN_BCM_SwitchSts_0x109_BufType;
extern VAR(RxPdu_CanConfigSet_Rx_ACAN_BCM_SwitchSts_0x109_BufType, COM_VAR_NOINIT) Com_RxPduSignal_CanConfigSet_Rx_ACAN_BCM_SwitchSts_0x109 ;

typedef struct
{
    uint8 CanConfigSet_Rx_ACAN_ABS_FrontWheelSpeMCUKPH_ABS_FLWheelSpeedKPH_Byte1 : 8;
    uint8 CanConfigSet_Rx_ACAN_ABS_FrontWheelSpeMCUKPH_ABS_FLWheelSpeedInvalid : 1;
    uint8 unused0 : 2;
    uint8 CanConfigSet_Rx_ACAN_ABS_FrontWheelSpeMCUKPH_ABS_FLWheelSpeedKPH_Byte0 : 5;
    uint8 CanConfigSet_Rx_ACAN_ABS_FrontWheelSpeMCUKPH_ABS_FRWheelSpeedKPH_Byte1 : 8;
    uint8 CanConfigSet_Rx_ACAN_ABS_FrontWheelSpeMCUKPH_ABS_FRWheelSpeedInvalid : 1;
    uint8 unused1 : 2;
    uint8 CanConfigSet_Rx_ACAN_ABS_FrontWheelSpeMCUKPH_ABS_FRWheelSpeedKPH_Byte0 : 5;
    uint8 CanConfigSet_Rx_ACAN_ABS_FrontWheelSpeMCUKPH_ABS_FRWheelDirection : 2;
    uint8 unused2 : 2;
    uint8 CanConfigSet_Rx_ACAN_ABS_FrontWheelSpeMCUKPH_ABS_FLWheelDirection : 2;
    uint8 unused3_Byte0 : 2;
    uint8 unused3_Byte1 : 8;
    uint8 CanConfigSet_Rx_ACAN_ABS_FrontWheelSpeMCUKPH_ABS_FWSpeMCUKPH_AliveCounter : 4;
    uint8 unused4 : 4;
    uint8 CanConfigSet_Rx_ACAN_ABS_FrontWheelSpeMCUKPH_ABS_FWSpeMCUKPH_CheckSum : 8;
} RxPdu_CanConfigSet_Rx_ACAN_ABS_FrontWheelSpeMCUKPH_BufType;
extern VAR(RxPdu_CanConfigSet_Rx_ACAN_ABS_FrontWheelSpeMCUKPH_BufType, COM_VAR_NOINIT) Com_RxPduSignal_CanConfigSet_Rx_ACAN_ABS_FrontWheelSpeMCUKPH ;

typedef struct
{
    uint8 CanConfigSet_Rx_ACAN_ABS_RearWheelSpeMCUKPH_ABS_RLWheelSpeedKPH_Byte1 : 8;
    uint8 CanConfigSet_Rx_ACAN_ABS_RearWheelSpeMCUKPH_ABS_RLWheelSpeedInvalid : 1;
    uint8 unused0 : 2;
    uint8 CanConfigSet_Rx_ACAN_ABS_RearWheelSpeMCUKPH_ABS_RLWheelSpeedKPH_Byte0 : 5;
    uint8 CanConfigSet_Rx_ACAN_ABS_RearWheelSpeMCUKPH_ABS_RRWheelSpeedKPH_Byte1 : 8;
    uint8 CanConfigSet_Rx_ACAN_ABS_RearWheelSpeMCUKPH_ABS_RRWheelSpeedInvalid : 1;
    uint8 unused1 : 2;
    uint8 CanConfigSet_Rx_ACAN_ABS_RearWheelSpeMCUKPH_ABS_RRWheelSpeedKPH_Byte0 : 5;
    uint8 CanConfigSet_Rx_ACAN_ABS_RearWheelSpeMCUKPH_ABS_RRWheelDirection : 2;
    uint8 unused2 : 2;
    uint8 CanConfigSet_Rx_ACAN_ABS_RearWheelSpeMCUKPH_ABS_RLWheelDirection : 2;
    uint8 unused3_Byte0 : 2;
    uint8 unused3_Byte1 : 8;
    uint8 CanConfigSet_Rx_ACAN_ABS_RearWheelSpeMCUKPH_ABS_RWSpeMCUKPH_AliveCounter : 4;
    uint8 unused4 : 4;
    uint8 CanConfigSet_Rx_ACAN_ABS_RearWheelSpeMCUKPH_ABS_RWSpeMCUKPH_CheckSum : 8;
} RxPdu_CanConfigSet_Rx_ACAN_ABS_RearWheelSpeMCUKPH_BufType;
extern VAR(RxPdu_CanConfigSet_Rx_ACAN_ABS_RearWheelSpeMCUKPH_BufType, COM_VAR_NOINIT) Com_RxPduSignal_CanConfigSet_Rx_ACAN_ABS_RearWheelSpeMCUKPH ;

typedef struct
{
    uint8 CanConfigSet_Rx_ACAN_ABS_WheelSpeedRC_ABS_FLWheelSpeedRC_Byte1 : 8;
    uint8 CanConfigSet_Rx_ACAN_ABS_WheelSpeedRC_ABS_FRWheelSpeedRC_Byte1 : 4;
    uint8 CanConfigSet_Rx_ACAN_ABS_WheelSpeedRC_ABS_FLWheelSpeedRC_Byte0 : 4;
    uint8 CanConfigSet_Rx_ACAN_ABS_WheelSpeedRC_ABS_FRWheelSpeedRC_Byte0 : 8;
    uint8 CanConfigSet_Rx_ACAN_ABS_WheelSpeedRC_ABS_RLWheelSpeedRC_Byte1 : 8;
    uint8 CanConfigSet_Rx_ACAN_ABS_WheelSpeedRC_ABS_RRWheelSpeedRC_Byte1 : 4;
    uint8 CanConfigSet_Rx_ACAN_ABS_WheelSpeedRC_ABS_RLWheelSpeedRC_Byte0 : 4;
    uint8 CanConfigSet_Rx_ACAN_ABS_WheelSpeedRC_ABS_RRWheelSpeedRC_Byte0 : 8;
    uint8 CanConfigSet_Rx_ACAN_ABS_WheelSpeedRC_ABS_FLWheelSpeedRCSts : 1;
    uint8 CanConfigSet_Rx_ACAN_ABS_WheelSpeedRC_ABS_FRWheelSpeedRCSts : 1;
    uint8 CanConfigSet_Rx_ACAN_ABS_WheelSpeedRC_ABS_RLWheelSpeedRCSts : 1;
    uint8 CanConfigSet_Rx_ACAN_ABS_WheelSpeedRC_ABS_RRWheelSpeedRCSts : 1;
    uint8 CanConfigSet_Rx_ACAN_ABS_WheelSpeedRC_ABS_WheelSpeMCURC_AliveCounter : 4;
    uint8 CanConfigSet_Rx_ACAN_ABS_WheelSpeedRC_ABS_WheelSpeMCURC_CheckSum : 8;
} RxPdu_CanConfigSet_Rx_ACAN_ABS_WheelSpeedRC_BufType;
extern VAR(RxPdu_CanConfigSet_Rx_ACAN_ABS_WheelSpeedRC_BufType, COM_VAR_NOINIT) Com_RxPduSignal_CanConfigSet_Rx_ACAN_ABS_WheelSpeedRC ;

typedef struct
{
    uint8 CanConfigSet_Rx_ACAN_ABS_Status_ABSActive : 1;
    uint8 unused0 : 1;
    uint8 CanConfigSet_Rx_ACAN_ABS_Status_ABS_EBDFailed : 1;
    uint8 CanConfigSet_Rx_ACAN_ABS_Status_ABSFailed : 1;
    uint8 unused1 : 4;
    uint8 CanConfigSet_Rx_ACAN_ABS_Status_ABS_VehicleSpeed_Byte1 : 8;
    uint8 CanConfigSet_Rx_ACAN_ABS_Status_ABS_LowBrakeFluid : 1;
    uint8 unused2 : 1;
    uint8 CanConfigSet_Rx_ACAN_ABS_Status_ABS_VehicleSpeedInvalid : 1;
    uint8 CanConfigSet_Rx_ACAN_ABS_Status_ABS_VehicleSpeed_Byte0 : 5;
    uint8 unused3_Byte0 : 8;
    uint8 unused3_Byte1 : 8;
    uint8 unused3_Byte2 : 8;
    uint8 CanConfigSet_Rx_ACAN_ABS_Status_ABS_Status_AliveCounter : 4;
    uint8 CanConfigSet_Rx_ACAN_ABS_Status_ABS_HAZActive : 1;
    uint8 unused4 : 3;
    uint8 CanConfigSet_Rx_ACAN_ABS_Status_ABS_Status_CheckSum : 8;
} RxPdu_CanConfigSet_Rx_ACAN_ABS_Status_BufType;
extern VAR(RxPdu_CanConfigSet_Rx_ACAN_ABS_Status_BufType, COM_VAR_NOINIT) Com_RxPduSignal_CanConfigSet_Rx_ACAN_ABS_Status ;

typedef struct
{
    uint8 CanConfigSet_Rx_ACAN_ESC_Status_0x132_Checksum_0x132 : 8;
    uint8 CanConfigSet_Rx_ACAN_ESC_Status_0x132_RollingCounter_0x132 : 4;
    uint8 unused0 : 4;
    uint8 CanConfigSet_Rx_ACAN_ESC_Status_0x132_ESC_SlopeGradeAngle : 8;
    uint8 CanConfigSet_Rx_ACAN_ESC_Status_0x132_ESC_MasterCylinderPressure_Byte1 : 4;
    uint8 CanConfigSet_Rx_ACAN_ESC_Status_0x132_ESC_MasterCylinderPressureV : 1;
    uint8 unused1 : 3;
    uint8 CanConfigSet_Rx_ACAN_ESC_Status_0x132_ESC_MasterCylinderPressure_Byte0 : 8;
    uint8 CanConfigSet_Rx_ACAN_ESC_Status_0x132_ESC_HSA_Control_Status : 1;
    uint8 CanConfigSet_Rx_ACAN_ESC_Status_0x132_ESC_HSA_Status_Fault : 1;
    uint8 CanConfigSet_Rx_ACAN_ESC_Status_0x132_ESC_TcsDisableSts : 1;
    uint8 CanConfigSet_Rx_ACAN_ESC_Status_0x132_ESC_EscCtrlActv : 1;
    uint8 CanConfigSet_Rx_ACAN_ESC_Status_0x132_ESC_TcsCtrlActv : 1;
    uint8 CanConfigSet_Rx_ACAN_ESC_Status_0x132_ESC_EscFlgFlt : 1;
    uint8 CanConfigSet_Rx_ACAN_ESC_Status_0x132_ESC_TcsFlgFlt : 1;
    uint8 CanConfigSet_Rx_ACAN_ESC_Status_0x132_ESC_EscDisableSts : 1;
    uint8 CanConfigSet_Rx_ACAN_ESC_Status_0x132_ESC_HBAFlgFlt : 1;
    uint8 CanConfigSet_Rx_ACAN_ESC_Status_0x132_ESC_HbaCtrlActv : 1;
    uint8 CanConfigSet_Rx_ACAN_ESC_Status_0x132_BAS_FlgFlt : 1;
    uint8 CanConfigSet_Rx_ACAN_ESC_Status_0x132_BAS_CtrlActv : 1;
    uint8 CanConfigSet_Rx_ACAN_ESC_Status_0x132_IBS_ESCOFF_StsFB : 1;
    uint8 unused2_Byte0 : 3;
    uint8 unused2_Byte1 : 8;
} RxPdu_CanConfigSet_Rx_ACAN_ESC_Status_0x132_BufType;
extern VAR(RxPdu_CanConfigSet_Rx_ACAN_ESC_Status_0x132_BufType, COM_VAR_NOINIT) Com_RxPduSignal_CanConfigSet_Rx_ACAN_ESC_Status_0x132 ;

typedef struct
{
    uint8 unused0_Byte0 : 8;
    uint8 unused0_Byte1 : 8;
    uint8 unused0_Byte2 : 2;
    uint8 CanConfigSet_Rx_ACAN_VCU_Ctrl_VCU_ModeGearSts : 3;
    uint8 unused1 : 1;
    uint8 CanConfigSet_Rx_ACAN_VCU_Ctrl_VCU_P_Sts : 1;
    uint8 unused2_Byte0 : 1;
    uint8 unused2_Byte1 : 3;
    uint8 CanConfigSet_Rx_ACAN_VCU_Ctrl_VCU_Warning_IMMO_Fail : 2;
    uint8 unused3 : 2;
    uint8 CanConfigSet_Rx_ACAN_VCU_Ctrl_VCU_Ready : 1;
    uint8 unused4_Byte0 : 8;
    uint8 unused4_Byte1 : 2;
    uint8 CanConfigSet_Rx_ACAN_VCU_Ctrl_VCU_RegencyLevInd : 3;
    uint8 unused5 : 3;
    uint8 CanConfigSet_Rx_ACAN_VCU_Ctrl_VCU_Ctrl_AliveCounter : 4;
    uint8 unused6 : 1;
    uint8 CanConfigSet_Rx_ACAN_VCU_Ctrl_VCU_LimpHomeSts : 1;
    uint8 unused7 : 2;
    uint8 CanConfigSet_Rx_ACAN_VCU_Ctrl_VCU_Ctrl_CheckSum : 8;
} RxPdu_CanConfigSet_Rx_ACAN_VCU_Ctrl_BufType;
extern VAR(RxPdu_CanConfigSet_Rx_ACAN_VCU_Ctrl_BufType, COM_VAR_NOINIT) Com_RxPduSignal_CanConfigSet_Rx_ACAN_VCU_Ctrl ;

typedef struct
{
    uint8 CanConfigSet_Rx_ACAN_VCU_StsEpt_VCU_StsAccPedalFault : 1;
    uint8 unused0 : 3;
    uint8 CanConfigSet_Rx_ACAN_VCU_StsEpt_VCU_StsSysFault : 4;
    uint8 CanConfigSet_Rx_ACAN_VCU_StsEpt_VCU_AccPedalPosition : 8;
    uint8 CanConfigSet_Rx_ACAN_VCU_StsEpt_VCU_AccPedal_Valid : 1;
    uint8 unused1_Byte0 : 7;
    uint8 unused1_Byte1 : 8;
    uint8 unused1_Byte2 : 8;
    uint8 unused1_Byte3 : 8;
    uint8 CanConfigSet_Rx_ACAN_VCU_StsEpt_VCU_StsEpt_AliveCounter : 4;
    uint8 unused2 : 4;
    uint8 CanConfigSet_Rx_ACAN_VCU_StsEpt_VCU_StsEpt_CheckSum : 8;
} RxPdu_CanConfigSet_Rx_ACAN_VCU_StsEpt_BufType;
extern VAR(RxPdu_CanConfigSet_Rx_ACAN_VCU_StsEpt_BufType, COM_VAR_NOINIT) Com_RxPduSignal_CanConfigSet_Rx_ACAN_VCU_StsEpt ;

typedef struct
{
    uint8 CanConfigSet_Rx_ACAN_SAS_Sensor_0x17E_Checksum_0x17E : 8;
    uint8 CanConfigSet_Rx_ACAN_SAS_Sensor_0x17E_Rolling_counter_0x17E : 4;
    uint8 unused0 : 4;
    uint8 CanConfigSet_Rx_ACAN_SAS_Sensor_0x17E_SAS_SteerWhlRotSpd_Byte1 : 6;
    uint8 CanConfigSet_Rx_ACAN_SAS_Sensor_0x17E_SAS_SASStsSnsr : 1;
    uint8 CanConfigSet_Rx_ACAN_SAS_Sensor_0x17E_SAS_SteeringAngleValid : 1;
    uint8 CanConfigSet_Rx_ACAN_SAS_Sensor_0x17E_SAS_SteerWhlRotSpd_Byte0 : 8;
    uint8 CanConfigSet_Rx_ACAN_SAS_Sensor_0x17E_SAS_SASFailure : 1;
    uint8 CanConfigSet_Rx_ACAN_SAS_Sensor_0x17E_SAS_Calibrated : 1;
    uint8 CanConfigSet_Rx_ACAN_SAS_Sensor_0x17E_SAS_SteerWhlRotSpdStatus : 1;
    uint8 unused1_Byte0 : 5;
    uint8 unused1_Byte1 : 8;
    uint8 CanConfigSet_Rx_ACAN_SAS_Sensor_0x17E_SAS_SteerWheelAngle_Byte1 : 8;
    uint8 CanConfigSet_Rx_ACAN_SAS_Sensor_0x17E_SAS_SteerWheelAngle_Byte0 : 8;
} RxPdu_CanConfigSet_Rx_ACAN_SAS_Sensor_0x17E_BufType;
extern VAR(RxPdu_CanConfigSet_Rx_ACAN_SAS_Sensor_0x17E_BufType, COM_VAR_NOINIT) Com_RxPduSignal_CanConfigSet_Rx_ACAN_SAS_Sensor_0x17E ;

typedef struct
{
    uint8 CanConfigSet_Rx_ACAN_EPS_LKA_Sts_CheckSum_0x17F : 8;
    uint8 CanConfigSet_Rx_ACAN_EPS_LKA_Sts_EPS_APA_CtrlAbortFeedback : 4;
    uint8 CanConfigSet_Rx_ACAN_EPS_LKA_Sts_RollingCounter_0x17F : 4;
    uint8 CanConfigSet_Rx_ACAN_EPS_LKA_Sts_EPS_LKARespTorq_Byte1 : 3;
    uint8 unused0 : 3;
    uint8 CanConfigSet_Rx_ACAN_EPS_LKA_Sts_EPS_SterMod : 1;
    uint8 CanConfigSet_Rx_ACAN_EPS_LKA_Sts_EPS_SterModV : 1;
    uint8 CanConfigSet_Rx_ACAN_EPS_LKA_Sts_EPS_LKARespTorq_Byte0 : 8;
    uint8 CanConfigSet_Rx_ACAN_EPS_LKA_Sts_EPS_ADAS_CtrlAbortFeedback : 4;
    uint8 unused1 : 3;
    uint8 CanConfigSet_Rx_ACAN_EPS_LKA_Sts_EPS_SterFltMod : 1;
    uint8 CanConfigSet_Rx_ACAN_EPS_LKA_Sts_EPS_DrStrTorqV : 1;
    uint8 CanConfigSet_Rx_ACAN_EPS_LKA_Sts_EPS_APA_ModAvail : 1;
    uint8 CanConfigSet_Rx_ACAN_EPS_LKA_Sts_EPS_APA_ModActv : 2;
    uint8 CanConfigSet_Rx_ACAN_EPS_LKA_Sts_EPS_ADAS_ModActv : 3;
    uint8 CanConfigSet_Rx_ACAN_EPS_LKA_Sts_EPS_ADAS_ModAvail : 1;
    uint8 CanConfigSet_Rx_ACAN_EPS_LKA_Sts_EPS_DrStrTorqVal : 8;
    uint8 unused2 : 8;
} RxPdu_CanConfigSet_Rx_ACAN_EPS_LKA_Sts_BufType;
extern VAR(RxPdu_CanConfigSet_Rx_ACAN_EPS_LKA_Sts_BufType, COM_VAR_NOINIT) Com_RxPduSignal_CanConfigSet_Rx_ACAN_EPS_LKA_Sts ;

typedef struct
{
    uint8 CanConfigSet_Rx_ACAN_BCM_PEPS_Sts_PEPS_PowerModeValidity : 2;
    uint8 CanConfigSet_Rx_ACAN_BCM_PEPS_Sts_PEPS_PowerMode : 3;
    uint8 unused0_Byte0 : 3;
    uint8 unused0_Byte1 : 1;
    uint8 CanConfigSet_Rx_ACAN_BCM_PEPS_Sts_PEPS_IGN1RelayValidity : 1;
    uint8 unused1 : 1;
    uint8 CanConfigSet_Rx_ACAN_BCM_PEPS_Sts_PEPS_IGN1RelaySts : 1;
    uint8 unused2_Byte0 : 4;
    uint8 unused2_Byte1 : 5;
    uint8 CanConfigSet_Rx_ACAN_BCM_PEPS_Sts_PEPS_Learning_Status : 2;
    uint8 unused3 : 1;
    uint8 CanConfigSet_Rx_ACAN_BCM_PEPS_Sts_BCM_WPC_Off_Req : 2;
    uint8 unused4_Byte0 : 6;
    uint8 unused4_Byte1 : 8;
    uint8 unused4_Byte2 : 8;
    uint8 CanConfigSet_Rx_ACAN_BCM_PEPS_Sts_PEPS_Message_Sts_AliveCounter : 4;
    uint8 unused5 : 4;
    uint8 CanConfigSet_Rx_ACAN_BCM_PEPS_Sts_PEPS_Message_Sts_CheckSum : 8;
} RxPdu_CanConfigSet_Rx_ACAN_BCM_PEPS_Sts_BufType;
extern VAR(RxPdu_CanConfigSet_Rx_ACAN_BCM_PEPS_Sts_BufType, COM_VAR_NOINIT) Com_RxPduSignal_CanConfigSet_Rx_ACAN_BCM_PEPS_Sts ;

typedef struct
{
    uint8 CanConfigSet_Rx_ACAN_MHU_ADSA01_MHU_APA_Req : 2;
    uint8 CanConfigSet_Rx_ACAN_MHU_ADSA01_MHU_APA_ParkIn_Req : 2;
    uint8 CanConfigSet_Rx_ACAN_MHU_ADSA01_MHU_APA_ParkOut_Req : 2;
    uint8 CanConfigSet_Rx_ACAN_MHU_ADSA01_MHU_APA_ParkingStart_Req : 2;
    uint8 CanConfigSet_Rx_ACAN_MHU_ADSA01_MHU_APA_ParkingReCover_Req : 2;
    uint8 CanConfigSet_Rx_ACAN_MHU_ADSA01_MHU_APA_ParkOut_Direction : 2;
    uint8 CanConfigSet_Rx_ACAN_MHU_ADSA01_MHU_APA_ParkOut_Mode : 3;
    uint8 unused0_Byte0 : 1;
    uint8 unused0_Byte1 : 8;
    uint8 unused0_Byte2 : 4;
    uint8 CanConfigSet_Rx_ACAN_MHU_ADSA01_MHU_LSS_Req : 2;
    uint8 CanConfigSet_Rx_ACAN_MHU_ADSA01_MHU_LSS_Mode : 2;
    uint8 CanConfigSet_Rx_ACAN_MHU_ADSA01_MHU_LSS_WarningMethod : 2;
    uint8 CanConfigSet_Rx_ACAN_MHU_ADSA01_MHU_TSR_Req : 2;
    uint8 CanConfigSet_Rx_ACAN_MHU_ADSA01_TSR_SpdWarningOffs_S : 4;
    uint8 CanConfigSet_Rx_ACAN_MHU_ADSA01_TSR_SLWFuncSwtReq : 2;
    uint8 CanConfigSet_Rx_ACAN_MHU_ADSA01_AEB_FuncSwtReq : 2;
    uint8 CanConfigSet_Rx_ACAN_MHU_ADSA01_AEB_FCW_SnvtyReq : 3;
    uint8 unused1 : 1;
    uint8 CanConfigSet_Rx_ACAN_MHU_ADSA01_BSD_LCA_FuncSWReq : 2;
    uint8 CanConfigSet_Rx_ACAN_MHU_ADSA01_RCTA_FuncSWReq : 2;
    uint8 CanConfigSet_Rx_ACAN_MHU_ADSA01_DOW_FuncSWReq : 2;
    uint8 CanConfigSet_Rx_ACAN_MHU_ADSA01_RCW_FuncSWReq : 2;
    uint8 CanConfigSet_Rx_ACAN_MHU_ADSA01_MHU_APA_ParkingSpace_ID : 8;
} RxPdu_CanConfigSet_Rx_ACAN_MHU_ADSA01_BufType;
extern VAR(RxPdu_CanConfigSet_Rx_ACAN_MHU_ADSA01_BufType, COM_VAR_NOINIT) Com_RxPduSignal_CanConfigSet_Rx_ACAN_MHU_ADSA01 ;

typedef struct
{
    uint8 CanConfigSet_Rx_ACAN_MHU_ADAS02_Nav_VehToTrafEyeDist_Byte1 : 2;
    uint8 unused0 : 1;
    uint8 CanConfigSet_Rx_ACAN_MHU_ADAS02_Nav_errorSts : 1;
    uint8 CanConfigSet_Rx_ACAN_MHU_ADAS02_Nav_RoadType : 4;
    uint8 CanConfigSet_Rx_ACAN_MHU_ADAS02_Nav_VehToTrafEyeDist_Byte0 : 8;
    uint8 CanConfigSet_Rx_ACAN_MHU_ADAS02_Nav_SpdLimValue : 6;
    uint8 CanConfigSet_Rx_ACAN_MHU_ADAS02_Nav_SpdLimType : 2;
    uint8 CanConfigSet_Rx_ACAN_MHU_ADAS02_Nav_SpdLimUnit : 2;
    uint8 unused1 : 6;
    uint8 CanConfigSet_Rx_ACAN_MHU_ADAS02_Nav_TSRTrafSign : 6;
    uint8 unused2 : 2;
    uint8 CanConfigSet_Rx_ACAN_MHU_ADAS02_Nav_CtryType : 8;
    uint8 unused3_Byte0 : 8;
    uint8 unused3_Byte1 : 8;
} RxPdu_CanConfigSet_Rx_ACAN_MHU_ADAS02_BufType;
extern VAR(RxPdu_CanConfigSet_Rx_ACAN_MHU_ADAS02_BufType, COM_VAR_NOINIT) Com_RxPduSignal_CanConfigSet_Rx_ACAN_MHU_ADAS02 ;

typedef struct
{
    uint8 CanConfigSet_Rx_ACAN_MHU_ADAS03_Nav_TimeMod : 1;
    uint8 unused0 : 3;
    uint8 CanConfigSet_Rx_ACAN_MHU_ADAS03_Nav_TimeIndcn : 2;
    uint8 unused1_Byte0 : 2;
    uint8 unused1_Byte1 : 8;
    uint8 unused1_Byte2 : 8;
    uint8 unused1_Byte3 : 8;
    uint8 unused1_Byte4 : 8;
    uint8 unused1_Byte5 : 8;
    uint8 unused1_Byte6 : 8;
    uint8 unused1_Byte7 : 8;
} RxPdu_CanConfigSet_Rx_ACAN_MHU_ADAS03_BufType;
extern VAR(RxPdu_CanConfigSet_Rx_ACAN_MHU_ADAS03_BufType, COM_VAR_NOINIT) Com_RxPduSignal_CanConfigSet_Rx_ACAN_MHU_ADAS03 ;

typedef struct
{
    uint8 unused0_Byte0 : 8;
    uint8 unused0_Byte1 : 8;
    uint8 CanConfigSet_Rx_ACAN_BCM_WindowSts_BCM_FLWin_Postion : 4;
    uint8 CanConfigSet_Rx_ACAN_BCM_WindowSts_BCM_FRWin_Postion : 4;
    uint8 CanConfigSet_Rx_ACAN_BCM_WindowSts_BCM_RLWinIN_Postion : 4;
    uint8 CanConfigSet_Rx_ACAN_BCM_WindowSts_BCM_RRWin_Postion : 4;
    uint8 unused1 : 4;
    uint8 CanConfigSet_Rx_ACAN_BCM_WindowSts_BCM_WinLockSts : 1;
    uint8 unused2 : 3;
    uint8 CanConfigSet_Rx_ACAN_BCM_WindowSts_BCM_RLWinAntipinchSts : 1;
    uint8 unused3 : 1;
    uint8 CanConfigSet_Rx_ACAN_BCM_WindowSts_BCM_RRWinAntipinchSts : 1;
    uint8 unused4 : 1;
    uint8 CanConfigSet_Rx_ACAN_BCM_WindowSts_BCM_FLWinAntipinchSts : 1;
    uint8 unused5 : 1;
    uint8 CanConfigSet_Rx_ACAN_BCM_WindowSts_BCM_FRWinAntipinchSts : 1;
    uint8 unused6 : 1;
    uint8 CanConfigSet_Rx_ACAN_BCM_WindowSts_BCM_FrontWipeSWSts : 3;
    uint8 CanConfigSet_Rx_ACAN_BCM_WindowSts_BCM_AutoWipeSts : 1;
    uint8 CanConfigSet_Rx_ACAN_BCM_WindowSts_BCM_FrontWipeSts : 2;
    uint8 CanConfigSet_Rx_ACAN_BCM_WindowSts_BCM_FrontWipeReturn : 1;
    uint8 CanConfigSet_Rx_ACAN_BCM_WindowSts_BCM_FrontWinWashSWSts : 1;
    uint8 CanConfigSet_Rx_ACAN_BCM_WindowSts_BCM_RearWipeSWSts : 3;
    uint8 unused7 : 1;
    uint8 CanConfigSet_Rx_ACAN_BCM_WindowSts_BCM_RearWipeSts : 2;
    uint8 CanConfigSet_Rx_ACAN_BCM_WindowSts_BCM_RearWipeReturn : 1;
    uint8 CanConfigSet_Rx_ACAN_BCM_WindowSts_BCM_RearWinWashSWSts : 1;
} RxPdu_CanConfigSet_Rx_ACAN_BCM_WindowSts_BufType;
extern VAR(RxPdu_CanConfigSet_Rx_ACAN_BCM_WindowSts_BufType, COM_VAR_NOINIT) Com_RxPduSignal_CanConfigSet_Rx_ACAN_BCM_WindowSts ;

typedef struct
{
    uint8 CanConfigSet_Rx_ACAN_ESC_EPB_0x230_Checksum_230 : 8;
    uint8 CanConfigSet_Rx_ACAN_ESC_EPB_0x230_RollingCounter_230 : 4;
    uint8 unused0_Byte0 : 4;
    uint8 unused0_Byte1 : 2;
    uint8 CanConfigSet_Rx_ACAN_ESC_EPB_0x230_EPB_SysBrkLtsReq : 1;
    uint8 CanConfigSet_Rx_ACAN_ESC_EPB_0x230_EPB_SysDspMsgReqV : 1;
    uint8 CanConfigSet_Rx_ACAN_ESC_EPB_0x230_EPB_SysStatIndReqV : 1;
    uint8 CanConfigSet_Rx_ACAN_ESC_EPB_0x230_EPB_SysWrnIndReqV : 1;
    uint8 CanConfigSet_Rx_ACAN_ESC_EPB_0x230_EPB_SysWrnIndReq : 2;
    uint8 CanConfigSet_Rx_ACAN_ESC_EPB_0x230_EPB_SysStatIndReq : 2;
    uint8 unused1 : 2;
    uint8 CanConfigSet_Rx_ACAN_ESC_EPB_0x230_EPB_SysDspMsgReq : 3;
    uint8 unused2_Byte0 : 1;
    uint8 unused2_Byte1 : 1;
    uint8 CanConfigSet_Rx_ACAN_ESC_EPB_0x230_EPB_AVHWrnIndReq : 1;
    uint8 CanConfigSet_Rx_ACAN_ESC_EPB_0x230_EPB_AVHWrnIndReqV : 1;
    uint8 CanConfigSet_Rx_ACAN_ESC_EPB_0x230_EPB_AVHStatIndReq : 1;
    uint8 CanConfigSet_Rx_ACAN_ESC_EPB_0x230_EPB_AVHStatIndReqV : 1;
    uint8 CanConfigSet_Rx_ACAN_ESC_EPB_0x230_EPB_AVHFeedbackSts : 1;
    uint8 unused3_Byte0 : 2;
    uint8 unused3_Byte1 : 8;
    uint8 unused3_Byte2 : 1;
    uint8 CanConfigSet_Rx_ACAN_ESC_EPB_0x230_EPB_Sts : 3;
    uint8 CanConfigSet_Rx_ACAN_ESC_EPB_0x230_WCBS_Trailermode_Feedback : 1;
    uint8 unused4_Byte0 : 3;
    uint8 unused4_Byte1 : 8;
} RxPdu_CanConfigSet_Rx_ACAN_ESC_EPB_0x230_BufType;
extern VAR(RxPdu_CanConfigSet_Rx_ACAN_ESC_EPB_0x230_BufType, COM_VAR_NOINIT) Com_RxPduSignal_CanConfigSet_Rx_ACAN_ESC_EPB_0x230 ;

typedef struct
{
    uint8 CanConfigSet_Rx_ACAN_IBS_ADAS_Info_WCBS_ACC_VLC_AccInTar_Byte1 : 4;
    uint8 CanConfigSet_Rx_ACAN_IBS_ADAS_Info_WCBS_ACC_VLC_Active : 1;
    uint8 CanConfigSet_Rx_ACAN_IBS_ADAS_Info_WCBS_ACC_CDD_Active : 1;
    uint8 CanConfigSet_Rx_ACAN_IBS_ADAS_Info_WCBS_ACC_VLC_Avl : 1;
    uint8 CanConfigSet_Rx_ACAN_IBS_ADAS_Info_WCBS_ACC_CDD_Avl : 1;
    uint8 CanConfigSet_Rx_ACAN_IBS_ADAS_Info_WCBS_ACC_VLC_AccInTar_Byte0 : 8;
    uint8 unused0_Byte0 : 8;
    uint8 unused0_Byte1 : 4;
    uint8 CanConfigSet_Rx_ACAN_IBS_ADAS_Info_WCBS_ABAAtv : 1;
    uint8 CanConfigSet_Rx_ACAN_IBS_ADAS_Info_WCBS_ABAAva : 1;
    uint8 CanConfigSet_Rx_ACAN_IBS_ADAS_Info_WCBS_ABPAtv : 1;
    uint8 CanConfigSet_Rx_ACAN_IBS_ADAS_Info_WCBS_ABPAva : 1;
    uint8 CanConfigSet_Rx_ACAN_IBS_ADAS_Info_WCBS_AWBAtv : 1;
    uint8 CanConfigSet_Rx_ACAN_IBS_ADAS_Info_WCBS_AWBAvl : 1;
    uint8 CanConfigSet_Rx_ACAN_IBS_ADAS_Info_WCBS_AEBAtv : 1;
    uint8 CanConfigSet_Rx_ACAN_IBS_ADAS_Info_WCBS_AEBAva : 1;
    uint8 CanConfigSet_Rx_ACAN_IBS_ADAS_Info_WCBS_VStandstillSta : 2;
    uint8 CanConfigSet_Rx_ACAN_IBS_ADAS_Info_WCBS_BrkFrcSta : 1;
    uint8 unused1_Byte0 : 1;
    uint8 unused1_Byte1 : 6;
    uint8 CanConfigSet_Rx_ACAN_IBS_ADAS_Info_WCBS_ESCDeteACCErroSta : 2;
    uint8 CanConfigSet_Rx_ACAN_IBS_ADAS_Info_WCBS_APA_VLC_FailureStatus : 4;
    uint8 CanConfigSet_Rx_ACAN_IBS_ADAS_Info_WCBS_APA_VLC_Status : 3;
    uint8 unused2 : 1;
    uint8 CanConfigSet_Rx_ACAN_IBS_ADAS_Info_WCBS_APA_VLC_Available : 1;
    uint8 CanConfigSet_Rx_ACAN_IBS_ADAS_Info_WCBS_APA_VLC_Active : 1;
    uint8 CanConfigSet_Rx_ACAN_IBS_ADAS_Info_WCBS_APA_EmgyBrkAvlb : 1;
    uint8 CanConfigSet_Rx_ACAN_IBS_ADAS_Info_WCBS_APA_CDD_Active : 1;
    uint8 unused3 : 4;
} RxPdu_CanConfigSet_Rx_ACAN_IBS_ADAS_Info_BufType;
extern VAR(RxPdu_CanConfigSet_Rx_ACAN_IBS_ADAS_Info_BufType, COM_VAR_NOINIT) Com_RxPduSignal_CanConfigSet_Rx_ACAN_IBS_ADAS_Info ;

typedef struct
{
    uint8 unused0 : 8;
    uint8 CanConfigSet_Rx_ACAN_IBS_Info_AB_BrkPedalSwSts : 1;
    uint8 unused1 : 1;
    uint8 CanConfigSet_Rx_ACAN_IBS_Info_AB_BrkPedalSwStsV : 1;
    uint8 unused2 : 1;
    uint8 CanConfigSet_Rx_ACAN_IBS_Info_AB_Fault_Status : 3;
    uint8 CanConfigSet_Rx_ACAN_IBS_Info_AB_IBS_Sys_Fault_Sts : 1;
    uint8 CanConfigSet_Rx_ACAN_IBS_Info_AB_BrkPedalPct : 8;
    uint8 CanConfigSet_Rx_ACAN_IBS_Info_AB_BrkPedalTravel_Byte1 : 8;
    uint8 unused3 : 6;
    uint8 CanConfigSet_Rx_ACAN_IBS_Info_AB_BrkPedalTravel_Byte0 : 2;
    uint8 unused4_Byte0 : 8;
    uint8 unused4_Byte1 : 8;
    uint8 unused4_Byte2 : 8;
} RxPdu_CanConfigSet_Rx_ACAN_IBS_Info_BufType;
extern VAR(RxPdu_CanConfigSet_Rx_ACAN_IBS_Info_BufType, COM_VAR_NOINIT) Com_RxPduSignal_CanConfigSet_Rx_ACAN_IBS_Info ;

typedef struct
{
    uint8 CanConfigSet_Rx_ACAN_TBOX_DateTime1_Time_second : 6;
    uint8 unused0 : 1;
    uint8 CanConfigSet_Rx_ACAN_TBOX_DateTime1_GPSSystAtv : 1;
    uint8 CanConfigSet_Rx_ACAN_TBOX_DateTime1_Time_Minute : 6;
    uint8 unused1 : 2;
    uint8 CanConfigSet_Rx_ACAN_TBOX_DateTime1_Time_Hour : 5;
    uint8 unused2 : 3;
    uint8 CanConfigSet_Rx_ACAN_TBOX_DateTime1_Time_Day : 5;
    uint8 unused3 : 3;
    uint8 CanConfigSet_Rx_ACAN_TBOX_DateTime1_Time_Month : 4;
    uint8 unused4 : 4;
    uint8 CanConfigSet_Rx_ACAN_TBOX_DateTime1_Time_Year : 8;
    uint8 unused5_Byte0 : 8;
    uint8 unused5_Byte1 : 8;
} RxPdu_CanConfigSet_Rx_ACAN_TBOX_DateTime1_BufType;
extern VAR(RxPdu_CanConfigSet_Rx_ACAN_TBOX_DateTime1_BufType, COM_VAR_NOINIT) Com_RxPduSignal_CanConfigSet_Rx_ACAN_TBOX_DateTime1 ;

typedef struct
{
    uint8 unused0_Byte0 : 8;
    uint8 unused0_Byte1 : 8;
    uint8 unused0_Byte2 : 4;
    uint8 CanConfigSet_Rx_ACAN_MHU_Status_Info_MHU_ESCOFF_SW_Sts : 2;
    uint8 CanConfigSet_Rx_ACAN_MHU_Status_Info_MHU_VCU_CreepDisable_stt : 2;
    uint8 CanConfigSet_Rx_ACAN_MHU_Status_Info_MHU_AVH_Req : 2;
    uint8 CanConfigSet_Rx_ACAN_MHU_Status_Info_MHU_RegencyLevRequest : 2;
    uint8 CanConfigSet_Rx_ACAN_MHU_Status_Info_MHU_DM_SwitchModeSts : 3;
    uint8 unused1 : 1;
    uint8 CanConfigSet_Rx_ACAN_MHU_Status_Info_MHU_Trailermode_Req : 2;
    uint8 CanConfigSet_Rx_ACAN_MHU_Status_Info_MHU_UPAMuteSwitch : 2;
    uint8 unused2_Byte0 : 4;
    uint8 unused2_Byte1 : 8;
    uint8 unused2_Byte2 : 8;
    uint8 unused2_Byte3 : 8;
} RxPdu_CanConfigSet_Rx_ACAN_MHU_Status_Info_BufType;
extern VAR(RxPdu_CanConfigSet_Rx_ACAN_MHU_Status_Info_BufType, COM_VAR_NOINIT) Com_RxPduSignal_CanConfigSet_Rx_ACAN_MHU_Status_Info ;

typedef struct
{
    uint8 CanConfigSet_Rx_ACAN_CCU_StsInfo1_CCU_PTCgear_Req_Reserve : 4;
    uint8 CanConfigSet_Rx_ACAN_CCU_StsInfo1_CCU_Anion_Generator_Sts : 2;
    uint8 CanConfigSet_Rx_ACAN_CCU_StsInfo1_CCU_AC_Req : 2;
    uint8 unused0 : 3;
    uint8 CanConfigSet_Rx_ACAN_CCU_StsInfo1_CCU_Onoff_Sts : 1;
    uint8 CanConfigSet_Rx_ACAN_CCU_StsInfo1_CCU_AUTO_Status : 1;
    uint8 CanConfigSet_Rx_ACAN_CCU_StsInfo1_CCU_FrontDefrostSts : 1;
    uint8 CanConfigSet_Rx_ACAN_CCU_StsInfo1_CCU_AC_Sts : 1;
    uint8 CanConfigSet_Rx_ACAN_CCU_StsInfo1_CCU_Circulation_Sts : 1;
    uint8 CanConfigSet_Rx_ACAN_CCU_StsInfo1_CCU_ExternalTemperatureFailSts : 1;
    uint8 unused1 : 5;
    uint8 CanConfigSet_Rx_ACAN_CCU_StsInfo1_CCU_PTC_Req : 2;
    uint8 CanConfigSet_Rx_ACAN_CCU_StsInfo1_CCU_Temp_Sync_Sts : 2;
    uint8 unused2 : 1;
    uint8 CanConfigSet_Rx_ACAN_CCU_StsInfo1_CCU_evaporator_Temperature : 5;
    uint8 CanConfigSet_Rx_ACAN_CCU_StsInfo1_CCU_PTCPwr_Req : 8;
    uint8 CanConfigSet_Rx_ACAN_CCU_StsInfo1_CCU_CompSpdMEAS_Comp_Byte1 : 5;
    uint8 unused3 : 3;
    uint8 CanConfigSet_Rx_ACAN_CCU_StsInfo1_CCU_CompSpdMEAS_Comp_Byte0 : 8;
    uint8 CanConfigSet_Rx_ACAN_CCU_StsInfo1_CCU_ExternalTemperature : 8;
} RxPdu_CanConfigSet_Rx_ACAN_CCU_StsInfo1_BufType;
extern VAR(RxPdu_CanConfigSet_Rx_ACAN_CCU_StsInfo1_BufType, COM_VAR_NOINIT) Com_RxPduSignal_CanConfigSet_Rx_ACAN_CCU_StsInfo1 ;

typedef struct
{
    uint8 CanConfigSet_Rx_ACAN_ESC_YawAngle_0x3E2_Checksum_0x3E2 : 8;
    uint8 CanConfigSet_Rx_ACAN_ESC_YawAngle_0x3E2_RollingCounter_0x3E2 : 4;
    uint8 unused0 : 4;
    uint8 CanConfigSet_Rx_ACAN_ESC_YawAngle_0x3E2_ESC_LateralACC_Valid : 1;
    uint8 CanConfigSet_Rx_ACAN_ESC_YawAngle_0x3E2_ESC_LongitudeACC_Valid : 1;
    uint8 CanConfigSet_Rx_ACAN_ESC_YawAngle_0x3E2_ESC_VehDynYawRate_Valid : 1;
    uint8 unused1 : 5;
    uint8 CanConfigSet_Rx_ACAN_ESC_YawAngle_0x3E2_ESC_VehDynYawRate_Byte1 : 6;
    uint8 unused2 : 2;
    uint8 CanConfigSet_Rx_ACAN_ESC_YawAngle_0x3E2_ESC_VehDynYawRate_Byte0 : 8;
    uint8 CanConfigSet_Rx_ACAN_ESC_YawAngle_0x3E2_ESC_LateralACC_Byte1 : 8;
    uint8 CanConfigSet_Rx_ACAN_ESC_YawAngle_0x3E2_ESC_LongitudeACC_Byte1 : 4;
    uint8 CanConfigSet_Rx_ACAN_ESC_YawAngle_0x3E2_ESC_LateralACC_Byte0 : 4;
    uint8 CanConfigSet_Rx_ACAN_ESC_YawAngle_0x3E2_ESC_LongitudeACC_Byte0 : 8;
} RxPdu_CanConfigSet_Rx_ACAN_ESC_YawAngle_0x3E2_BufType;
extern VAR(RxPdu_CanConfigSet_Rx_ACAN_ESC_YawAngle_0x3E2_BufType, COM_VAR_NOINIT) Com_RxPduSignal_CanConfigSet_Rx_ACAN_ESC_YawAngle_0x3E2 ;

typedef struct
{
    uint8 CanConfigSet_Rx_ACAN_IPC_TotalOdometer_IPC_IPCTotalOdometer_Byte2 : 8;
    uint8 CanConfigSet_Rx_ACAN_IPC_TotalOdometer_IPC_IPCTotalOdometer_Byte1 : 8;
    uint8 CanConfigSet_Rx_ACAN_IPC_TotalOdometer_IPC_IPCTotalOdometer_Byte0 : 8;
    uint8 CanConfigSet_Rx_ACAN_IPC_TotalOdometer_IPC_IPCTotalOdometerV : 1;
    uint8 unused0 : 7;
    uint8 CanConfigSet_Rx_ACAN_IPC_TotalOdometer_IPC_Remain_Maintenance_Byte1 : 8;
    uint8 CanConfigSet_Rx_ACAN_IPC_TotalOdometer_IPC_Remain_Maintenance_Byte0 : 8;
    uint8 CanConfigSet_Rx_ACAN_IPC_TotalOdometer_RollingCounter_0x3F1 : 4;
    uint8 unused1 : 4;
    uint8 CanConfigSet_Rx_ACAN_IPC_TotalOdometer_CheckSum_0x3F1 : 8;
} RxPdu_CanConfigSet_Rx_ACAN_IPC_TotalOdometer_BufType;
extern VAR(RxPdu_CanConfigSet_Rx_ACAN_IPC_TotalOdometer_BufType, COM_VAR_NOINIT) Com_RxPduSignal_CanConfigSet_Rx_ACAN_IPC_TotalOdometer ;

typedef struct
{
    uint8 CanConfigSet_Rx_ACAN_MFS_L_Control_Button2_0x3F7_CheckSum_0x3F7 : 8;
    uint8 CanConfigSet_Rx_ACAN_MFS_L_Control_Button2_0x3F7_RollingCounter_0x3F7 : 4;
    uint8 unused0 : 4;
    uint8 CanConfigSet_Rx_ACAN_MFS_L_Control_Button2_0x3F7_MFS_ACC_CruiseSpdIncrease : 3;
    uint8 unused1 : 1;
    uint8 CanConfigSet_Rx_ACAN_MFS_L_Control_Button2_0x3F7_MFS_ACC_CruiseOn_Off : 3;
    uint8 CanConfigSet_Rx_ACAN_MFS_L_Control_Button2_0x3F7_MFS_L2_Failure : 1;
    uint8 CanConfigSet_Rx_ACAN_MFS_L_Control_Button2_0x3F7_MFS_ACC_CruiseGapSet : 3;
    uint8 unused2 : 1;
    uint8 CanConfigSet_Rx_ACAN_MFS_L_Control_Button2_0x3F7_MFS_ACC_CruiseSpdDecrease : 3;
    uint8 unused3_Byte0 : 1;
    uint8 unused3_Byte1 : 4;
    uint8 CanConfigSet_Rx_ACAN_MFS_L_Control_Button2_0x3F7_MFS_ACC_CruiseCancel : 3;
    uint8 unused4_Byte0 : 1;
    uint8 unused4_Byte1 : 8;
    uint8 unused4_Byte2 : 8;
    uint8 unused4_Byte3 : 8;
} RxPdu_CanConfigSet_Rx_ACAN_MFS_L_Control_Button2_0x3F7_BufType;
extern VAR(RxPdu_CanConfigSet_Rx_ACAN_MFS_L_Control_Button2_0x3F7_BufType, COM_VAR_NOINIT) Com_RxPduSignal_CanConfigSet_Rx_ACAN_MFS_L_Control_Button2_0x3F7 ;

typedef struct
{
    uint8 unused0_Byte0 : 8;
    uint8 unused0_Byte1 : 8;
    uint8 CanConfigSet_Rx_ACAN_BCM_RLS_RLS_Solar_Right_PassgSide : 8;
    uint8 CanConfigSet_Rx_ACAN_BCM_RLS_RLS_Solar_Left_Driveside : 8;
    uint8 unused1 : 4;
    uint8 CanConfigSet_Rx_ACAN_BCM_RLS_RLS_Rainfall_magnitude : 2;
    uint8 CanConfigSet_Rx_ACAN_BCM_RLS_RLS_LightSensorError : 1;
    uint8 CanConfigSet_Rx_ACAN_BCM_RLS_RLS_RainSensorError : 1;
    uint8 unused2 : 7;
    uint8 CanConfigSet_Rx_ACAN_BCM_RLS_RLS_LightRequest : 1;
    uint8 unused3_Byte0 : 8;
    uint8 unused3_Byte1 : 8;
} RxPdu_CanConfigSet_Rx_ACAN_BCM_RLS_BufType;
extern VAR(RxPdu_CanConfigSet_Rx_ACAN_BCM_RLS_BufType, COM_VAR_NOINIT) Com_RxPduSignal_CanConfigSet_Rx_ACAN_BCM_RLS ;

typedef struct
{
    uint8 CanConfigSet_Rx_ACAN_BCM_TPMS_Info2_TPMS_RFpressureSts : 3;
    uint8 unused0 : 1;
    uint8 CanConfigSet_Rx_ACAN_BCM_TPMS_Info2_TPMS_LFpressureSts : 3;
    uint8 CanConfigSet_Rx_ACAN_BCM_TPMS_Info2_TPMS_SysSts : 1;
    uint8 CanConfigSet_Rx_ACAN_BCM_TPMS_Info2_TPMS_RRpressureSts : 3;
    uint8 unused1 : 1;
    uint8 CanConfigSet_Rx_ACAN_BCM_TPMS_Info2_TPMS_LRpressureSts : 3;
    uint8 unused2_Byte0 : 1;
    uint8 unused2_Byte1 : 8;
    uint8 CanConfigSet_Rx_ACAN_BCM_TPMS_Info2_TPMS_RRpressureV : 1;
    uint8 CanConfigSet_Rx_ACAN_BCM_TPMS_Info2_TPMS_LRpressureV : 1;
    uint8 CanConfigSet_Rx_ACAN_BCM_TPMS_Info2_TPMS_RFpressureV : 1;
    uint8 CanConfigSet_Rx_ACAN_BCM_TPMS_Info2_TPMS_LFpressureV : 1;
    uint8 unused3 : 4;
    uint8 CanConfigSet_Rx_ACAN_BCM_TPMS_Info2_TPMS_LFpressure : 8;
    uint8 CanConfigSet_Rx_ACAN_BCM_TPMS_Info2_TPMS_RFpressure : 8;
    uint8 CanConfigSet_Rx_ACAN_BCM_TPMS_Info2_TPMS_LRpressure : 8;
    uint8 CanConfigSet_Rx_ACAN_BCM_TPMS_Info2_TPMS_RRpressure : 8;
} RxPdu_CanConfigSet_Rx_ACAN_BCM_TPMS_Info2_BufType;
extern VAR(RxPdu_CanConfigSet_Rx_ACAN_BCM_TPMS_Info2_BufType, COM_VAR_NOINIT) Com_RxPduSignal_CanConfigSet_Rx_ACAN_BCM_TPMS_Info2 ;

typedef struct
{
    uint8 unused0 : 2;
    uint8 CanConfigSet_Rx_ACAN_BCM_DoorState_0x4D4_BCM_CoverAjarStatus : 1;
    uint8 CanConfigSet_Rx_ACAN_BCM_DoorState_0x4D4_BCM_TrunckAjarStatus : 1;
    uint8 CanConfigSet_Rx_ACAN_BCM_DoorState_0x4D4_BCM_DriverSideDoorAjarSts : 1;
    uint8 CanConfigSet_Rx_ACAN_BCM_DoorState_0x4D4_BCM_CodriversSideDoorAjarSts : 1;
    uint8 CanConfigSet_Rx_ACAN_BCM_DoorState_0x4D4_BCM_RearLeftDoorAjarStatus : 1;
    uint8 CanConfigSet_Rx_ACAN_BCM_DoorState_0x4D4_BCM_RearRightDoorAjarStatus : 1;
    uint8 unused1 : 8;
    uint8 CanConfigSet_Rx_ACAN_BCM_DoorState_0x4D4_BCM_DoorLockStatusRL : 2;
    uint8 CanConfigSet_Rx_ACAN_BCM_DoorState_0x4D4_BCM_DoorLockStatusRR : 2;
    uint8 CanConfigSet_Rx_ACAN_BCM_DoorState_0x4D4_BCM_DoorLockStatusCodrivres : 2;
    uint8 CanConfigSet_Rx_ACAN_BCM_DoorState_0x4D4_BCM_DoorLockStatusDrv : 2;
    uint8 unused2 : 2;
    uint8 CanConfigSet_Rx_ACAN_BCM_DoorState_0x4D4_BCM_ATWS_St : 3;
    uint8 CanConfigSet_Rx_ACAN_BCM_DoorState_0x4D4_BCM_TailGateSts : 3;
    uint8 unused3_Byte0 : 8;
    uint8 unused3_Byte1 : 8;
    uint8 unused3_Byte2 : 8;
    uint8 unused3_Byte3 : 8;
} RxPdu_CanConfigSet_Rx_ACAN_BCM_DoorState_0x4D4_BufType;
extern VAR(RxPdu_CanConfigSet_Rx_ACAN_BCM_DoorState_0x4D4_BufType, COM_VAR_NOINIT) Com_RxPduSignal_CanConfigSet_Rx_ACAN_BCM_DoorState_0x4D4 ;

typedef struct
{
    uint8 Tcp_ReceiveSignal[9];
} RxPdu_Tcp_Receive_BufType;
extern VAR(RxPdu_Tcp_Receive_BufType, COM_VAR_NOINIT) Com_RxPduSignal_Tcp_Receive ;

typedef struct
{
    uint8 Udp_ReceiveSignal[9];
} RxPdu_Udp_Receive_BufType;
extern VAR(RxPdu_Udp_Receive_BufType, COM_VAR_NOINIT) Com_RxPduSignal_Udp_Receive ;

typedef struct
{
    uint8 CanConfigSet_Rx_Radar_ARS_TIME_SYNC_ARS_TSYNC_TimeStampGlobSec_Byte3 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_TIME_SYNC_ARS_TSYNC_TimeStampGlobSec_Byte2 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_TIME_SYNC_ARS_TSYNC_TimeStampGlobSec_Byte1 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_TIME_SYNC_ARS_TSYNC_TimeStampGlobSec_Byte0 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_TIME_SYNC_ARS_TSYNC_TimeStampGlobNSec_Byte3 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_TIME_SYNC_ARS_TSYNC_TimeStampGlobNSec_Byte2 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_TIME_SYNC_ARS_TSYNC_TimeStampGlobNSec_Byte1 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_TIME_SYNC_ARS_TSYNC_TimeStampGlobNSec_Byte0 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_TIME_SYNC_ARS_TSYNC_MaxTimeLeap_Byte1 : 8;
    uint8 unused0 : 4;
    uint8 CanConfigSet_Rx_Radar_ARS_TIME_SYNC_ARS_TSYNC_MaxTimeLeap_Byte0 : 4;
    uint8 CanConfigSet_Rx_Radar_ARS_TIME_SYNC_ARS_TSYNC_LastTimeLeap_Byte1 : 8;
    uint8 unused1 : 4;
    uint8 CanConfigSet_Rx_Radar_ARS_TIME_SYNC_ARS_TSYNC_LastTimeLeap_Byte0 : 4;
    uint8 unused2 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_TIME_SYNC_ARS_TSYNC_MsgCounter : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_TIME_SYNC_ARS_TSYNC_CRC16_Checksum_Byte1 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_TIME_SYNC_ARS_TSYNC_CRC16_Checksum_Byte0 : 8;
} RxPdu_CanConfigSet_Rx_Radar_ARS_TIME_SYNC_BufType;
extern VAR(RxPdu_CanConfigSet_Rx_Radar_ARS_TIME_SYNC_BufType, COM_VAR_NOINIT) Com_RxPduSignal_CanConfigSet_Rx_Radar_ARS_TIME_SYNC ;

typedef struct
{
    uint8 CanConfigSet_Rx_Radar_ARS_SYS_PERFORM_ARS_SP_TunnelFlag : 1;
    uint8 CanConfigSet_Rx_Radar_ARS_SYS_PERFORM_ARS_SP_CalibrationState : 3;
    uint8 CanConfigSet_Rx_Radar_ARS_SYS_PERFORM_ARS_SP_OperationMode : 4;
    uint8 CanConfigSet_Rx_Radar_ARS_SYS_PERFORM_ARS_SP_AzimuthCorrection : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_SYS_PERFORM_ARS_SP_ElevationCorrection : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_SYS_PERFORM_ARS_SP_ErrStateGroup_1 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_SYS_PERFORM_ARS_SP_ErrStateGroup_2 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_SYS_PERFORM_ARS_SP_ErrStateGroup_3 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_SYS_PERFORM_ARS_SP_ErrStateGroup_4 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_SYS_PERFORM_ARS_SP_VisibilityRange_Byte1 : 8;
    uint8 unused0 : 5;
    uint8 CanConfigSet_Rx_Radar_ARS_SYS_PERFORM_ARS_SP_VisibilityState : 2;
    uint8 CanConfigSet_Rx_Radar_ARS_SYS_PERFORM_ARS_SP_VisibilityRange_Byte0 : 1;
    uint8 unused1_Byte0 : 8;
    uint8 unused1_Byte1 : 8;
    uint8 unused1_Byte2 : 8;
    uint8 unused1_Byte3 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_SYS_PERFORM_ARS_SP_MsgCounter : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_SYS_PERFORM_ARS_SP_CRC16_Checksum_Byte1 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_SYS_PERFORM_ARS_SP_CRC16_Checksum_Byte0 : 8;
} RxPdu_CanConfigSet_Rx_Radar_ARS_SYS_PERFORM_BufType;
extern VAR(RxPdu_CanConfigSet_Rx_Radar_ARS_SYS_PERFORM_BufType, COM_VAR_NOINIT) Com_RxPduSignal_CanConfigSet_Rx_Radar_ARS_SYS_PERFORM ;

typedef struct
{
    uint8 CanConfigSet_Rx_Radar_ARS_OD_Header_ARS_OD_TimeStampGlobSec_Byte3 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_Header_ARS_OD_TimeStampGlobSec_Byte2 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_Header_ARS_OD_TimeStampGlobSec_Byte1 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_Header_ARS_OD_TimeStampGlobSec_Byte0 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_Header_ARS_OD_TimeStampGlobNanoSec_Byte3 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_Header_ARS_OD_TimeStampGlobNanoSec_Byte2 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_Header_ARS_OD_TimeStampGlobNanoSec_Byte1 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_Header_ARS_OD_TimeStampGlobNanoSec_Byte0 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_Header_ARS_OD_TimeStampLocal_Byte3 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_Header_ARS_OD_TimeStampLocal_Byte2 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_Header_ARS_OD_TimeStampLocal_Byte1 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_Header_ARS_OD_TimeStampLocal_Byte0 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_Header_ARS_OD_MeasCounter_Byte1 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_Header_ARS_OD_MeasCounter_Byte0 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_Header_ARS_OD_CycleCounter_Byte1 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_Header_ARS_OD_CycleCounter_Byte0 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_Header_ARS_OD_ExtendedCycleFlag : 1;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_Header_ARS_OD_TaskValidFlag : 1;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_Header_ARS_OD_NumOfObjects : 6;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_Header_ARS_OD_Latency_Byte1 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_Header_ARS_OD_EgoVelocity_Byte1 : 5;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_Header_ARS_OD_Latency_Byte0 : 3;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_Header_ARS_OD_EgoYawRate_Byte1 : 2;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_Header_ARS_OD_EgoVelocity_Byte0 : 6;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_Header_ARS_OD_EgoYawRate_Byte0 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_Header_ARS_OD_EgoAcceleration_Byte1 : 1;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_Header_ARS_OD_EgoVelocityStd : 7;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_Header_ARS_OD_EgoAcceleration_Byte0 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_Header_ARS_OD_EgoCurvature : 8;
    uint8 unused0_Byte0 : 8;
    uint8 unused0_Byte1 : 8;
    uint8 unused0_Byte2 : 8;
    uint8 unused0_Byte3 : 8;
    uint8 unused0_Byte4 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_Header_ARS_OD_MsgCounter_Header : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_Header_ARS_OD_CRC16_Checksum_Header_Byte1 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_Header_ARS_OD_CRC16_Checksum_Header_Byte0 : 8;
} RxPdu_CanConfigSet_Rx_Radar_ARS_OD_Header_BufType;
extern VAR(RxPdu_CanConfigSet_Rx_Radar_ARS_OD_Header_BufType, COM_VAR_NOINIT) Com_RxPduSignal_CanConfigSet_Rx_Radar_ARS_OD_Header ;

typedef struct
{
    uint8 CanConfigSet_Rx_Radar_ARS_OD_00_01_ARS_OD_DistX_Obj_00_Byte1 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_00_01_ARS_OD_VabsX_Obj_00_Byte1 : 4;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_00_01_ARS_OD_DistX_Obj_00_Byte0 : 4;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_00_01_ARS_OD_AabsX_Obj_00_Byte1 : 1;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_00_01_ARS_OD_VabsX_Obj_00_Byte0 : 7;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_00_01_ARS_OD_AabsX_Obj_00_Byte0 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_00_01_ARS_OD_DistY_Obj_00_Byte1 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_00_01_ARS_OD_VabsY_Obj_00_Byte1 : 4;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_00_01_ARS_OD_DistY_Obj_00_Byte0 : 4;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_00_01_ARS_OD_AabsY_Obj_00_Byte1 : 1;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_00_01_ARS_OD_VabsY_Obj_00_Byte0 : 7;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_00_01_ARS_OD_AabsY_Obj_00_Byte0 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_00_01_ARS_OD_DistXStd_Obj_00 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_00_01_ARS_OD_DistYStd_Obj_00 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_00_01_ARS_OD_VabsYStd_Obj_00_Byte1 : 1;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_00_01_ARS_OD_VabsXStd_Obj_00 : 7;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_00_01_ARS_OD_AabsXStd_Obj_00_Byte1 : 2;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_00_01_ARS_OD_VabsYStd_Obj_00_Byte0 : 6;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_00_01_ARS_OD_Classification_Obj_00 : 3;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_00_01_ARS_OD_AabsXStd_Obj_00_Byte0 : 5;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_00_01_ARS_OD_AabsYStd_Obj_00 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_00_01_ARS_OD_ProbOfExist_Obj_00_Byte1 : 1;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_00_01_ARS_OD_ClassConf_Obj_00 : 7;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_00_01_ARS_OD_DynConf_Obj_00_Byte1 : 2;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_00_01_ARS_OD_ProbOfExist_Obj_00_Byte0 : 6;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_00_01_ARS_OD_DynProp_Obj_00 : 3;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_00_01_ARS_OD_DynConf_Obj_00_Byte0 : 5;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_00_01_ARS_OD_Length_Obj_00_Byte1 : 1;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_00_01_ARS_OD_MirrorProb_Obj_00 : 7;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_00_01_ARS_OD_MaintenanceState_Obj_00 : 2;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_00_01_ARS_OD_Length_Obj_00_Byte0 : 6;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_00_01_ARS_OD_RCS_Obj_00_Byte1 : 1;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_00_01_ARS_OD_Width_Obj_00 : 7;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_00_01_ARS_OD_RCS_Obj_00_Byte0 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_00_01_ARS_OD_Orientation_Obj_00_Byte1 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_00_01_ARS_OD_YawRateAbs_Obj_00_Byte1 : 6;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_00_01_ARS_OD_Orientation_Obj_00_Byte0 : 2;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_00_01_ARS_OD_YawRateAbsStd_Obj_00_Byte1 : 4;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_00_01_ARS_OD_YawRateAbs_Obj_00_Byte0 : 4;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_00_01_ARS_OD_RefPoint_Obj_00 : 2;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_00_01_ARS_OD_YawRateAbsStd_Obj_00_Byte0 : 6;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_00_01_ARS_OD_LifeCycle_Obj_00_Byte1 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_00_01_ARS_OD_LifeCycle_Obj_00_Byte0 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_00_01_ARS_OD_DistX_Obj_01_Byte1 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_00_01_ARS_OD_VabsX_Obj_01_Byte1 : 4;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_00_01_ARS_OD_DistX_Obj_01_Byte0 : 4;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_00_01_ARS_OD_AabsX_Obj_01_Byte1 : 1;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_00_01_ARS_OD_VabsX_Obj_01_Byte0 : 7;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_00_01_ARS_OD_AabsX_Obj_01_Byte0 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_00_01_ARS_OD_DistY_Obj_01_Byte1 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_00_01_ARS_OD_VabsY_Obj_01_Byte1 : 4;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_00_01_ARS_OD_DistY_Obj_01_Byte0 : 4;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_00_01_ARS_OD_AabsY_Obj_01_Byte1 : 1;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_00_01_ARS_OD_VabsY_Obj_01_Byte0 : 7;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_00_01_ARS_OD_AabsY_Obj_01_Byte0 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_00_01_ARS_OD_DistXStd_Obj_01 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_00_01_ARS_OD_DistYStd_Obj_01 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_00_01_ARS_OD_VabsYStd_Obj_01_Byte1 : 1;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_00_01_ARS_OD_VabsXStd_Obj_01 : 7;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_00_01_ARS_OD_AabsXStd_Obj_01_Byte1 : 2;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_00_01_ARS_OD_VabsYStd_Obj_01_Byte0 : 6;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_00_01_ARS_OD_Classification_Obj_01 : 3;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_00_01_ARS_OD_AabsXStd_Obj_01_Byte0 : 5;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_00_01_ARS_OD_AabsYStd_Obj_01 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_00_01_ARS_OD_ProbOfExist_Obj_01_Byte1 : 1;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_00_01_ARS_OD_ClassConf_Obj_01 : 7;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_00_01_ARS_OD_DynConf_Obj_01_Byte1 : 2;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_00_01_ARS_OD_ProbOfExist_Obj_01_Byte0 : 6;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_00_01_ARS_OD_DynProp_Obj_01 : 3;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_00_01_ARS_OD_DynConf_Obj_01_Byte0 : 5;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_00_01_ARS_OD_Length_Obj_01_Byte1 : 1;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_00_01_ARS_OD_MirrorProb_Obj_01 : 7;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_00_01_ARS_OD_MaintenanceState_Obj_01 : 2;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_00_01_ARS_OD_Length_Obj_01_Byte0 : 6;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_00_01_ARS_OD_RCS_Obj_01_Byte1 : 1;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_00_01_ARS_OD_Width_Obj_01 : 7;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_00_01_ARS_OD_RCS_Obj_01_Byte0 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_00_01_ARS_OD_Orientation_Obj_01_Byte1 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_00_01_ARS_OD_YawRateAbs_Obj_01_Byte1 : 6;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_00_01_ARS_OD_Orientation_Obj_01_Byte0 : 2;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_00_01_ARS_OD_YawRateAbsStd_Obj_01_Byte1 : 4;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_00_01_ARS_OD_YawRateAbs_Obj_01_Byte0 : 4;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_00_01_ARS_OD_RefPoint_Obj_01 : 2;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_00_01_ARS_OD_YawRateAbsStd_Obj_01_Byte0 : 6;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_00_01_ARS_OD_LifeCycle_Obj_01_Byte1 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_00_01_ARS_OD_LifeCycle_Obj_01_Byte0 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_00_01_ARS_OD_OrientationStd_Obj_01 : 4;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_00_01_ARS_OD_OrientationStd_Obj_00 : 4;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_00_01_ARS_OD_MicroDopplerFlag_00 : 1;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_00_01_ARS_OD_ObstacleProb_Obj_00 : 7;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_00_01_ARS_OD_MicroDopplerFlag_01 : 1;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_00_01_ARS_OD_ObstacleProb_Obj_01 : 7;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_00_01_ARS_OD_ID_00 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_00_01_ARS_OD_ID_01 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_00_01_DistHeight_Obj_00 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_00_01_DistHeight_Obj_01 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_00_01_ARS_OD_MsgCounter_Obj_00_01 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_00_01_ARS_OD_CRC16_Checksum_Obj_00_01_Byte1 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_00_01_ARS_OD_CRC16_Checksum_Obj_00_01_Byte0 : 8;
} RxPdu_CanConfigSet_Rx_Radar_ARS_OD_00_01_BufType;
extern VAR(RxPdu_CanConfigSet_Rx_Radar_ARS_OD_00_01_BufType, COM_VAR_NOINIT) Com_RxPduSignal_CanConfigSet_Rx_Radar_ARS_OD_00_01 ;

typedef struct
{
    uint8 CanConfigSet_Rx_Radar_ARS_OD_02_03_ARS_OD_DistX_Obj_02_Byte1 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_02_03_ARS_OD_VabsX_Obj_02_Byte1 : 4;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_02_03_ARS_OD_DistX_Obj_02_Byte0 : 4;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_02_03_ARS_OD_AabsX_Obj_02_Byte1 : 1;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_02_03_ARS_OD_VabsX_Obj_02_Byte0 : 7;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_02_03_ARS_OD_AabsX_Obj_02_Byte0 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_02_03_ARS_OD_DistY_Obj_02_Byte1 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_02_03_ARS_OD_VabsY_Obj_02_Byte1 : 4;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_02_03_ARS_OD_DistY_Obj_02_Byte0 : 4;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_02_03_ARS_OD_AabsY_Obj_02_Byte1 : 1;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_02_03_ARS_OD_VabsY_Obj_02_Byte0 : 7;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_02_03_ARS_OD_AabsY_Obj_02_Byte0 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_02_03_ARS_OD_DistXStd_Obj_02 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_02_03_ARS_OD_DistYStd_Obj_02 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_02_03_ARS_OD_VabsYStd_Obj_02_Byte1 : 1;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_02_03_ARS_OD_VabsXStd_Obj_02 : 7;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_02_03_ARS_OD_AabsXStd_Obj_02_Byte1 : 2;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_02_03_ARS_OD_VabsYStd_Obj_02_Byte0 : 6;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_02_03_ARS_OD_Classification_Obj_02 : 3;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_02_03_ARS_OD_AabsXStd_Obj_02_Byte0 : 5;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_02_03_ARS_OD_AabsYStd_Obj_02 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_02_03_ARS_OD_ProbOfExist_Obj_02_Byte1 : 1;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_02_03_ARS_OD_ClassConf_Obj_02 : 7;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_02_03_ARS_OD_DynConf_Obj_02_Byte1 : 2;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_02_03_ARS_OD_ProbOfExist_Obj_02_Byte0 : 6;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_02_03_ARS_OD_DynProp_Obj_02 : 3;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_02_03_ARS_OD_DynConf_Obj_02_Byte0 : 5;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_02_03_ARS_OD_Length_Obj_02_Byte1 : 1;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_02_03_ARS_OD_MirrorProb_Obj_02 : 7;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_02_03_ARS_OD_MaintenanceState_Obj_02 : 2;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_02_03_ARS_OD_Length_Obj_02_Byte0 : 6;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_02_03_ARS_OD_RCS_Obj_02_Byte1 : 1;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_02_03_ARS_OD_Width_Obj_02 : 7;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_02_03_ARS_OD_RCS_Obj_02_Byte0 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_02_03_ARS_OD_Orientation_Obj_02_Byte1 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_02_03_ARS_OD_YawRateAbs_Obj_02_Byte1 : 6;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_02_03_ARS_OD_Orientation_Obj_02_Byte0 : 2;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_02_03_ARS_OD_YawRateAbsStd_Obj_02_Byte1 : 4;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_02_03_ARS_OD_YawRateAbs_Obj_02_Byte0 : 4;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_02_03_ARS_OD_RefPoint_Obj_02 : 2;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_02_03_ARS_OD_YawRateAbsStd_Obj_02_Byte0 : 6;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_02_03_ARS_OD_LifeCycle_Obj_02_Byte1 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_02_03_ARS_OD_LifeCycle_Obj_02_Byte0 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_02_03_ARS_OD_DistX_Obj_03_Byte1 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_02_03_ARS_OD_VabsX_Obj_03_Byte1 : 4;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_02_03_ARS_OD_DistX_Obj_03_Byte0 : 4;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_02_03_ARS_OD_AabsX_Obj_03_Byte1 : 1;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_02_03_ARS_OD_VabsX_Obj_03_Byte0 : 7;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_02_03_ARS_OD_AabsX_Obj_03_Byte0 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_02_03_ARS_OD_DistY_Obj_03_Byte1 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_02_03_ARS_OD_VabsY_Obj_03_Byte1 : 4;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_02_03_ARS_OD_DistY_Obj_03_Byte0 : 4;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_02_03_ARS_OD_AabsY_Obj_03_Byte1 : 1;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_02_03_ARS_OD_VabsY_Obj_03_Byte0 : 7;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_02_03_ARS_OD_AabsY_Obj_03_Byte0 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_02_03_ARS_OD_DistXStd_Obj_03 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_02_03_ARS_OD_DistYStd_Obj_03 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_02_03_ARS_OD_VabsYStd_Obj_03_Byte1 : 1;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_02_03_ARS_OD_VabsXStd_Obj_03 : 7;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_02_03_ARS_OD_AabsXStd_Obj_03_Byte1 : 2;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_02_03_ARS_OD_VabsYStd_Obj_03_Byte0 : 6;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_02_03_ARS_OD_Classification_Obj_03 : 3;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_02_03_ARS_OD_AabsXStd_Obj_03_Byte0 : 5;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_02_03_ARS_OD_AabsYStd_Obj_03 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_02_03_ARS_OD_ProbOfExist_Obj_03_Byte1 : 1;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_02_03_ARS_OD_ClassConf_Obj_03 : 7;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_02_03_ARS_OD_DynConf_Obj_03_Byte1 : 2;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_02_03_ARS_OD_ProbOfExist_Obj_03_Byte0 : 6;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_02_03_ARS_OD_DynProp_Obj_03 : 3;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_02_03_ARS_OD_DynConf_Obj_03_Byte0 : 5;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_02_03_ARS_OD_Length_Obj_03_Byte1 : 1;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_02_03_ARS_OD_MirrorProb_Obj_03 : 7;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_02_03_ARS_OD_MaintenanceState_Obj_03 : 2;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_02_03_ARS_OD_Length_Obj_03_Byte0 : 6;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_02_03_ARS_OD_RCS_Obj_03_Byte1 : 1;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_02_03_ARS_OD_Width_Obj_03 : 7;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_02_03_ARS_OD_RCS_Obj_03_Byte0 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_02_03_ARS_OD_Orientation_Obj_03_Byte1 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_02_03_ARS_OD_YawRateAbs_Obj_03_Byte1 : 6;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_02_03_ARS_OD_Orientation_Obj_03_Byte0 : 2;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_02_03_ARS_OD_YawRateAbsStd_Obj_03_Byte1 : 4;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_02_03_ARS_OD_YawRateAbs_Obj_03_Byte0 : 4;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_02_03_ARS_OD_RefPoint_Obj_03 : 2;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_02_03_ARS_OD_YawRateAbsStd_Obj_03_Byte0 : 6;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_02_03_ARS_OD_LifeCycle_Obj_03_Byte1 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_02_03_ARS_OD_LifeCycle_Obj_03_Byte0 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_02_03_ARS_OD_OrientationStd_Obj_03 : 4;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_02_03_ARS_OD_OrientationStd_Obj_02 : 4;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_02_03_ARS_OD_MicroDopplerFlag_02 : 1;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_02_03_ARS_OD_ObstacleProb_Obj_02 : 7;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_02_03_ARS_OD_MicroDopplerFlag_03 : 1;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_02_03_ARS_OD_ObstacleProb_Obj_03 : 7;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_02_03_ARS_OD_ID_02 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_02_03_ARS_OD_ID_03 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_02_03_DistHeight_Obj_02 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_02_03_DistHeight_Obj_03 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_02_03_ARS_OD_MsgCounter_Obj_02_03 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_02_03_ARS_OD_CRC16_Checksum_Obj_02_03_Byte1 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_02_03_ARS_OD_CRC16_Checksum_Obj_02_03_Byte0 : 8;
} RxPdu_CanConfigSet_Rx_Radar_ARS_OD_02_03_BufType;
extern VAR(RxPdu_CanConfigSet_Rx_Radar_ARS_OD_02_03_BufType, COM_VAR_NOINIT) Com_RxPduSignal_CanConfigSet_Rx_Radar_ARS_OD_02_03 ;

typedef struct
{
    uint8 CanConfigSet_Rx_Radar_ARS_OD_04_05_ARS_OD_DistX_Obj_04_Byte1 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_04_05_ARS_OD_VabsX_Obj_04_Byte1 : 4;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_04_05_ARS_OD_DistX_Obj_04_Byte0 : 4;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_04_05_ARS_OD_AabsX_Obj_04_Byte1 : 1;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_04_05_ARS_OD_VabsX_Obj_04_Byte0 : 7;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_04_05_ARS_OD_AabsX_Obj_04_Byte0 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_04_05_ARS_OD_DistY_Obj_04_Byte1 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_04_05_ARS_OD_VabsY_Obj_04_Byte1 : 4;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_04_05_ARS_OD_DistY_Obj_04_Byte0 : 4;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_04_05_ARS_OD_AabsY_Obj_04_Byte1 : 1;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_04_05_ARS_OD_VabsY_Obj_04_Byte0 : 7;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_04_05_ARS_OD_AabsY_Obj_04_Byte0 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_04_05_ARS_OD_DistXStd_Obj_04 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_04_05_ARS_OD_DistYStd_Obj_04 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_04_05_ARS_OD_VabsYStd_Obj_04_Byte1 : 1;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_04_05_ARS_OD_VabsXStd_Obj_04 : 7;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_04_05_ARS_OD_AabsXStd_Obj_04_Byte1 : 2;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_04_05_ARS_OD_VabsYStd_Obj_04_Byte0 : 6;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_04_05_ARS_OD_Classification_Obj_04 : 3;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_04_05_ARS_OD_AabsXStd_Obj_04_Byte0 : 5;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_04_05_ARS_OD_AabsYStd_Obj_04 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_04_05_ARS_OD_ProbOfExist_Obj_04_Byte1 : 1;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_04_05_ARS_OD_ClassConf_Obj_04 : 7;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_04_05_ARS_OD_DynConf_Obj_04_Byte1 : 2;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_04_05_ARS_OD_ProbOfExist_Obj_04_Byte0 : 6;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_04_05_ARS_OD_DynProp_Obj_04 : 3;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_04_05_ARS_OD_DynConf_Obj_04_Byte0 : 5;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_04_05_ARS_OD_Length_Obj_04_Byte1 : 1;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_04_05_ARS_OD_MirrorProb_Obj_04 : 7;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_04_05_ARS_OD_MaintenanceState_Obj_04 : 2;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_04_05_ARS_OD_Length_Obj_04_Byte0 : 6;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_04_05_ARS_OD_RCS_Obj_04_Byte1 : 1;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_04_05_ARS_OD_Width_Obj_04 : 7;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_04_05_ARS_OD_RCS_Obj_04_Byte0 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_04_05_ARS_OD_Orientation_Obj_04_Byte1 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_04_05_ARS_OD_YawRateAbs_Obj_04_Byte1 : 6;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_04_05_ARS_OD_Orientation_Obj_04_Byte0 : 2;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_04_05_ARS_OD_YawRateAbsStd_Obj_04_Byte1 : 4;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_04_05_ARS_OD_YawRateAbs_Obj_04_Byte0 : 4;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_04_05_ARS_OD_RefPoint_Obj_04 : 2;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_04_05_ARS_OD_YawRateAbsStd_Obj_04_Byte0 : 6;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_04_05_ARS_OD_LifeCycle_Obj_04_Byte1 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_04_05_ARS_OD_LifeCycle_Obj_04_Byte0 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_04_05_ARS_OD_DistX_Obj_05_Byte1 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_04_05_ARS_OD_VabsX_Obj_05_Byte1 : 4;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_04_05_ARS_OD_DistX_Obj_05_Byte0 : 4;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_04_05_ARS_OD_AabsX_Obj_05_Byte1 : 1;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_04_05_ARS_OD_VabsX_Obj_05_Byte0 : 7;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_04_05_ARS_OD_AabsX_Obj_05_Byte0 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_04_05_ARS_OD_DistY_Obj_05_Byte1 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_04_05_ARS_OD_VabsY_Obj_05_Byte1 : 4;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_04_05_ARS_OD_DistY_Obj_05_Byte0 : 4;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_04_05_ARS_OD_AabsY_Obj_05_Byte1 : 1;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_04_05_ARS_OD_VabsY_Obj_05_Byte0 : 7;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_04_05_ARS_OD_AabsY_Obj_05_Byte0 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_04_05_ARS_OD_DistXStd_Obj_05 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_04_05_ARS_OD_DistYStd_Obj_05 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_04_05_ARS_OD_VabsYStd_Obj_05_Byte1 : 1;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_04_05_ARS_OD_VabsXStd_Obj_05 : 7;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_04_05_ARS_OD_AabsXStd_Obj_05_Byte1 : 2;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_04_05_ARS_OD_VabsYStd_Obj_05_Byte0 : 6;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_04_05_ARS_OD_Classification_Obj_05 : 3;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_04_05_ARS_OD_AabsXStd_Obj_05_Byte0 : 5;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_04_05_ARS_OD_AabsYStd_Obj_05 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_04_05_ARS_OD_ProbOfExist_Obj_05_Byte1 : 1;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_04_05_ARS_OD_ClassConf_Obj_05 : 7;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_04_05_ARS_OD_DynConf_Obj_05_Byte1 : 2;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_04_05_ARS_OD_ProbOfExist_Obj_05_Byte0 : 6;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_04_05_ARS_OD_DynProp_Obj_05 : 3;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_04_05_ARS_OD_DynConf_Obj_05_Byte0 : 5;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_04_05_ARS_OD_Length_Obj_05_Byte1 : 1;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_04_05_ARS_OD_MirrorProb_Obj_05 : 7;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_04_05_ARS_OD_MaintenanceState_Obj_05 : 2;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_04_05_ARS_OD_Length_Obj_05_Byte0 : 6;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_04_05_ARS_OD_RCS_Obj_05_Byte1 : 1;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_04_05_ARS_OD_Width_Obj_05 : 7;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_04_05_ARS_OD_RCS_Obj_05_Byte0 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_04_05_ARS_OD_Orientation_Obj_05_Byte1 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_04_05_ARS_OD_YawRateAbs_Obj_05_Byte1 : 6;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_04_05_ARS_OD_Orientation_Obj_05_Byte0 : 2;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_04_05_ARS_OD_YawRateAbsStd_Obj_05_Byte1 : 4;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_04_05_ARS_OD_YawRateAbs_Obj_05_Byte0 : 4;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_04_05_ARS_OD_RefPoint_Obj_05 : 2;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_04_05_ARS_OD_YawRateAbsStd_Obj_05_Byte0 : 6;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_04_05_ARS_OD_LifeCycle_Obj_05_Byte1 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_04_05_ARS_OD_LifeCycle_Obj_05_Byte0 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_04_05_ARS_OD_OrientationStd_Obj_05 : 4;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_04_05_ARS_OD_OrientationStd_Obj_04 : 4;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_04_05_ARS_OD_MicroDopplerFlag_04 : 1;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_04_05_ARS_OD_ObstacleProb_Obj_04 : 7;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_04_05_ARS_OD_MicroDopplerFlag_05 : 1;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_04_05_ARS_OD_ObstacleProb_Obj_05 : 7;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_04_05_ARS_OD_ID_04 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_04_05_ARS_OD_ID_05 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_04_05_DistHeight_Obj_04 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_04_05_DistHeight_Obj_05 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_04_05_ARS_OD_MsgCounter_Obj_04_05 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_04_05_ARS_OD_CRC16_Checksum_Obj_04_05_Byte1 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_04_05_ARS_OD_CRC16_Checksum_Obj_04_05_Byte0 : 8;
} RxPdu_CanConfigSet_Rx_Radar_ARS_OD_04_05_BufType;
extern VAR(RxPdu_CanConfigSet_Rx_Radar_ARS_OD_04_05_BufType, COM_VAR_NOINIT) Com_RxPduSignal_CanConfigSet_Rx_Radar_ARS_OD_04_05 ;

typedef struct
{
    uint8 CanConfigSet_Rx_Radar_ARS_OD_06_07_ARS_OD_DistX_Obj_06_Byte1 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_06_07_ARS_OD_VabsX_Obj_06_Byte1 : 4;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_06_07_ARS_OD_DistX_Obj_06_Byte0 : 4;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_06_07_ARS_OD_AabsX_Obj_06_Byte1 : 1;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_06_07_ARS_OD_VabsX_Obj_06_Byte0 : 7;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_06_07_ARS_OD_AabsX_Obj_06_Byte0 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_06_07_ARS_OD_DistY_Obj_06_Byte1 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_06_07_ARS_OD_VabsY_Obj_06_Byte1 : 4;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_06_07_ARS_OD_DistY_Obj_06_Byte0 : 4;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_06_07_ARS_OD_AabsY_Obj_06_Byte1 : 1;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_06_07_ARS_OD_VabsY_Obj_06_Byte0 : 7;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_06_07_ARS_OD_AabsY_Obj_06_Byte0 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_06_07_ARS_OD_DistXStd_Obj_06 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_06_07_ARS_OD_DistYStd_Obj_06 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_06_07_ARS_OD_VabsYStd_Obj_06_Byte1 : 1;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_06_07_ARS_OD_VabsXStd_Obj_06 : 7;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_06_07_ARS_OD_AabsXStd_Obj_06_Byte1 : 2;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_06_07_ARS_OD_VabsYStd_Obj_06_Byte0 : 6;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_06_07_ARS_OD_Classification_Obj_06 : 3;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_06_07_ARS_OD_AabsXStd_Obj_06_Byte0 : 5;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_06_07_ARS_OD_AabsYStd_Obj_06 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_06_07_ARS_OD_ProbOfExist_Obj_06_Byte1 : 1;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_06_07_ARS_OD_ClassConf_Obj_06 : 7;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_06_07_ARS_OD_DynConf_Obj_06_Byte1 : 2;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_06_07_ARS_OD_ProbOfExist_Obj_06_Byte0 : 6;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_06_07_ARS_OD_DynProp_Obj_06 : 3;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_06_07_ARS_OD_DynConf_Obj_06_Byte0 : 5;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_06_07_ARS_OD_Length_Obj_06_Byte1 : 1;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_06_07_ARS_OD_MirrorProb_Obj_06 : 7;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_06_07_ARS_OD_MaintenanceState_Obj_06 : 2;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_06_07_ARS_OD_Length_Obj_06_Byte0 : 6;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_06_07_ARS_OD_RCS_Obj_06_Byte1 : 1;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_06_07_ARS_OD_Width_Obj_06 : 7;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_06_07_ARS_OD_RCS_Obj_06_Byte0 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_06_07_ARS_OD_Orientation_Obj_06_Byte1 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_06_07_ARS_OD_YawRateAbs_Obj_06_Byte1 : 6;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_06_07_ARS_OD_Orientation_Obj_06_Byte0 : 2;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_06_07_ARS_OD_YawRateAbsStd_Obj_06_Byte1 : 4;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_06_07_ARS_OD_YawRateAbs_Obj_06_Byte0 : 4;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_06_07_ARS_OD_RefPoint_Obj_06 : 2;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_06_07_ARS_OD_YawRateAbsStd_Obj_06_Byte0 : 6;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_06_07_ARS_OD_LifeCycle_Obj_06_Byte1 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_06_07_ARS_OD_LifeCycle_Obj_06_Byte0 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_06_07_ARS_OD_DistX_Obj_07_Byte1 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_06_07_ARS_OD_VabsX_Obj_07_Byte1 : 4;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_06_07_ARS_OD_DistX_Obj_07_Byte0 : 4;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_06_07_ARS_OD_AabsX_Obj_07_Byte1 : 1;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_06_07_ARS_OD_VabsX_Obj_07_Byte0 : 7;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_06_07_ARS_OD_AabsX_Obj_07_Byte0 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_06_07_ARS_OD_DistY_Obj_07_Byte1 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_06_07_ARS_OD_VabsY_Obj_07_Byte1 : 4;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_06_07_ARS_OD_DistY_Obj_07_Byte0 : 4;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_06_07_ARS_OD_AabsY_Obj_07_Byte1 : 1;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_06_07_ARS_OD_VabsY_Obj_07_Byte0 : 7;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_06_07_ARS_OD_AabsY_Obj_07_Byte0 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_06_07_ARS_OD_DistXStd_Obj_07 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_06_07_ARS_OD_DistYStd_Obj_07 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_06_07_ARS_OD_VabsYStd_Obj_07_Byte1 : 1;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_06_07_ARS_OD_VabsXStd_Obj_07 : 7;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_06_07_ARS_OD_AabsXStd_Obj_07_Byte1 : 2;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_06_07_ARS_OD_VabsYStd_Obj_07_Byte0 : 6;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_06_07_ARS_OD_Classification_Obj_07 : 3;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_06_07_ARS_OD_AabsXStd_Obj_07_Byte0 : 5;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_06_07_ARS_OD_AabsYStd_Obj_07 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_06_07_ARS_OD_ProbOfExist_Obj_07_Byte1 : 1;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_06_07_ARS_OD_ClassConf_Obj_07 : 7;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_06_07_ARS_OD_DynConf_Obj_07_Byte1 : 2;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_06_07_ARS_OD_ProbOfExist_Obj_07_Byte0 : 6;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_06_07_ARS_OD_DynProp_Obj_07 : 3;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_06_07_ARS_OD_DynConf_Obj_07_Byte0 : 5;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_06_07_ARS_OD_Length_Obj_07_Byte1 : 1;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_06_07_ARS_OD_MirrorProb_Obj_07 : 7;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_06_07_ARS_OD_MaintenanceState_Obj_07 : 2;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_06_07_ARS_OD_Length_Obj_07_Byte0 : 6;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_06_07_ARS_OD_RCS_Obj_07_Byte1 : 1;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_06_07_ARS_OD_Width_Obj_07 : 7;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_06_07_ARS_OD_RCS_Obj_07_Byte0 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_06_07_ARS_OD_Orientation_Obj_07_Byte1 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_06_07_ARS_OD_YawRateAbs_Obj_07_Byte1 : 6;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_06_07_ARS_OD_Orientation_Obj_07_Byte0 : 2;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_06_07_ARS_OD_YawRateAbsStd_Obj_07_Byte1 : 4;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_06_07_ARS_OD_YawRateAbs_Obj_07_Byte0 : 4;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_06_07_ARS_OD_RefPoint_Obj_07 : 2;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_06_07_ARS_OD_YawRateAbsStd_Obj_07_Byte0 : 6;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_06_07_ARS_OD_LifeCycle_Obj_07_Byte1 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_06_07_ARS_OD_LifeCycle_Obj_07_Byte0 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_06_07_ARS_OD_OrientationStd_Obj_07 : 4;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_06_07_ARS_OD_OrientationStd_Obj_06 : 4;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_06_07_ARS_OD_MicroDopplerFlag_06 : 1;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_06_07_ARS_OD_ObstacleProb_Obj_06 : 7;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_06_07_ARS_OD_MicroDopplerFlag_07 : 1;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_06_07_ARS_OD_ObstacleProb_Obj_07 : 7;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_06_07_ARS_OD_ID_06 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_06_07_ARS_OD_ID_07 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_06_07_DistHeight_Obj_06 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_06_07_DistHeight_Obj_07 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_06_07_ARS_OD_MsgCounter_Obj_06_07 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_06_07_ARS_OD_CRC16_Checksum_Obj_06_07_Byte1 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_06_07_ARS_OD_CRC16_Checksum_Obj_06_07_Byte0 : 8;
} RxPdu_CanConfigSet_Rx_Radar_ARS_OD_06_07_BufType;
extern VAR(RxPdu_CanConfigSet_Rx_Radar_ARS_OD_06_07_BufType, COM_VAR_NOINIT) Com_RxPduSignal_CanConfigSet_Rx_Radar_ARS_OD_06_07 ;

typedef struct
{
    uint8 CanConfigSet_Rx_Radar_ARS_OD_08_09_ARS_OD_DistX_Obj_08_Byte1 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_08_09_ARS_OD_VabsX_Obj_08_Byte1 : 4;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_08_09_ARS_OD_DistX_Obj_08_Byte0 : 4;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_08_09_ARS_OD_AabsX_Obj_08_Byte1 : 1;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_08_09_ARS_OD_VabsX_Obj_08_Byte0 : 7;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_08_09_ARS_OD_AabsX_Obj_08_Byte0 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_08_09_ARS_OD_DistY_Obj_08_Byte1 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_08_09_ARS_OD_VabsY_Obj_08_Byte1 : 4;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_08_09_ARS_OD_DistY_Obj_08_Byte0 : 4;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_08_09_ARS_OD_AabsY_Obj_08_Byte1 : 1;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_08_09_ARS_OD_VabsY_Obj_08_Byte0 : 7;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_08_09_ARS_OD_AabsY_Obj_08_Byte0 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_08_09_ARS_OD_DistXStd_Obj_08 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_08_09_ARS_OD_DistYStd_Obj_08 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_08_09_ARS_OD_VabsYStd_Obj_08_Byte1 : 1;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_08_09_ARS_OD_VabsXStd_Obj_08 : 7;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_08_09_ARS_OD_AabsXStd_Obj_08_Byte1 : 2;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_08_09_ARS_OD_VabsYStd_Obj_08_Byte0 : 6;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_08_09_ARS_OD_Classification_Obj_08 : 3;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_08_09_ARS_OD_AabsXStd_Obj_08_Byte0 : 5;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_08_09_ARS_OD_AabsYStd_Obj_08 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_08_09_ARS_OD_ProbOfExist_Obj_08_Byte1 : 1;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_08_09_ARS_OD_ClassConf_Obj_08 : 7;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_08_09_ARS_OD_DynConf_Obj_08_Byte1 : 2;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_08_09_ARS_OD_ProbOfExist_Obj_08_Byte0 : 6;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_08_09_ARS_OD_DynProp_Obj_08 : 3;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_08_09_ARS_OD_DynConf_Obj_08_Byte0 : 5;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_08_09_ARS_OD_Length_Obj_08_Byte1 : 1;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_08_09_ARS_OD_MirrorProb_Obj_08 : 7;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_08_09_ARS_OD_MaintenanceState_Obj_08 : 2;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_08_09_ARS_OD_Length_Obj_08_Byte0 : 6;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_08_09_ARS_OD_RCS_Obj_08_Byte1 : 1;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_08_09_ARS_OD_Width_Obj_08 : 7;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_08_09_ARS_OD_RCS_Obj_08_Byte0 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_08_09_ARS_OD_Orientation_Obj_08_Byte1 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_08_09_ARS_OD_YawRateAbs_Obj_08_Byte1 : 6;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_08_09_ARS_OD_Orientation_Obj_08_Byte0 : 2;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_08_09_ARS_OD_YawRateAbsStd_Obj_08_Byte1 : 4;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_08_09_ARS_OD_YawRateAbs_Obj_08_Byte0 : 4;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_08_09_ARS_OD_RefPoint_Obj_08 : 2;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_08_09_ARS_OD_YawRateAbsStd_Obj_08_Byte0 : 6;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_08_09_ARS_OD_LifeCycle_Obj_08_Byte1 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_08_09_ARS_OD_LifeCycle_Obj_08_Byte0 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_08_09_ARS_OD_DistX_Obj_09_Byte1 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_08_09_ARS_OD_VabsX_Obj_09_Byte1 : 4;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_08_09_ARS_OD_DistX_Obj_09_Byte0 : 4;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_08_09_ARS_OD_AabsX_Obj_09_Byte1 : 1;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_08_09_ARS_OD_VabsX_Obj_09_Byte0 : 7;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_08_09_ARS_OD_AabsX_Obj_09_Byte0 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_08_09_ARS_OD_DistY_Obj_09_Byte1 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_08_09_ARS_OD_VabsY_Obj_09_Byte1 : 4;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_08_09_ARS_OD_DistY_Obj_09_Byte0 : 4;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_08_09_ARS_OD_AabsY_Obj_09_Byte1 : 1;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_08_09_ARS_OD_VabsY_Obj_09_Byte0 : 7;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_08_09_ARS_OD_AabsY_Obj_09_Byte0 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_08_09_ARS_OD_DistXStd_Obj_09 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_08_09_ARS_OD_DistYStd_Obj_09 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_08_09_ARS_OD_VabsYStd_Obj_09_Byte1 : 1;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_08_09_ARS_OD_VabsXStd_Obj_09 : 7;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_08_09_ARS_OD_AabsXStd_Obj_09_Byte1 : 2;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_08_09_ARS_OD_VabsYStd_Obj_09_Byte0 : 6;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_08_09_ARS_OD_Classification_Obj_09 : 3;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_08_09_ARS_OD_AabsXStd_Obj_09_Byte0 : 5;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_08_09_ARS_OD_AabsYStd_Obj_09 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_08_09_ARS_OD_ProbOfExist_Obj_09_Byte1 : 1;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_08_09_ARS_OD_ClassConf_Obj_09 : 7;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_08_09_ARS_OD_DynConf_Obj_09_Byte1 : 2;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_08_09_ARS_OD_ProbOfExist_Obj_09_Byte0 : 6;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_08_09_ARS_OD_DynProp_Obj_09 : 3;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_08_09_ARS_OD_DynConf_Obj_09_Byte0 : 5;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_08_09_ARS_OD_Length_Obj_09_Byte1 : 1;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_08_09_ARS_OD_MirrorProb_Obj_09 : 7;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_08_09_ARS_OD_MaintenanceState_Obj_09 : 2;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_08_09_ARS_OD_Length_Obj_09_Byte0 : 6;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_08_09_ARS_OD_RCS_Obj_09_Byte1 : 1;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_08_09_ARS_OD_Width_Obj_09 : 7;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_08_09_ARS_OD_RCS_Obj_09_Byte0 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_08_09_ARS_OD_Orientation_Obj_09_Byte1 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_08_09_ARS_OD_YawRateAbs_Obj_09_Byte1 : 6;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_08_09_ARS_OD_Orientation_Obj_09_Byte0 : 2;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_08_09_ARS_OD_YawRateAbsStd_Obj_09_Byte1 : 4;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_08_09_ARS_OD_YawRateAbs_Obj_09_Byte0 : 4;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_08_09_ARS_OD_RefPoint_Obj_09 : 2;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_08_09_ARS_OD_YawRateAbsStd_Obj_09_Byte0 : 6;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_08_09_ARS_OD_LifeCycle_Obj_09_Byte1 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_08_09_ARS_OD_LifeCycle_Obj_09_Byte0 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_08_09_ARS_OD_OrientationStd_Obj_09 : 4;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_08_09_ARS_OD_OrientationStd_Obj_08 : 4;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_08_09_ARS_OD_MicroDopplerFlag_08 : 1;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_08_09_ARS_OD_ObstacleProb_Obj_08 : 7;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_08_09_ARS_OD_MicroDopplerFlag_09 : 1;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_08_09_ARS_OD_ObstacleProb_Obj_09 : 7;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_08_09_ARS_OD_ID_08 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_08_09_ARS_OD_ID_09 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_08_09_DistHeight_Obj_08 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_08_09_DistHeight_Obj_09 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_08_09_ARS_OD_MsgCounter_Obj_08_09 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_08_09_ARS_OD_CRC16_Checksum_Obj_08_09_Byte1 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_08_09_ARS_OD_CRC16_Checksum_Obj_08_09_Byte0 : 8;
} RxPdu_CanConfigSet_Rx_Radar_ARS_OD_08_09_BufType;
extern VAR(RxPdu_CanConfigSet_Rx_Radar_ARS_OD_08_09_BufType, COM_VAR_NOINIT) Com_RxPduSignal_CanConfigSet_Rx_Radar_ARS_OD_08_09 ;

typedef struct
{
    uint8 CanConfigSet_Rx_Radar_ARS_OD_10_11_ARS_OD_DistX_Obj_10_Byte1 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_10_11_ARS_OD_VabsX_Obj_10_Byte1 : 4;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_10_11_ARS_OD_DistX_Obj_10_Byte0 : 4;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_10_11_ARS_OD_AabsX_Obj_10_Byte1 : 1;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_10_11_ARS_OD_VabsX_Obj_10_Byte0 : 7;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_10_11_ARS_OD_AabsX_Obj_10_Byte0 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_10_11_ARS_OD_DistY_Obj_10_Byte1 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_10_11_ARS_OD_VabsY_Obj_10_Byte1 : 4;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_10_11_ARS_OD_DistY_Obj_10_Byte0 : 4;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_10_11_ARS_OD_AabsY_Obj_10_Byte1 : 1;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_10_11_ARS_OD_VabsY_Obj_10_Byte0 : 7;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_10_11_ARS_OD_AabsY_Obj_10_Byte0 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_10_11_ARS_OD_DistXStd_Obj_10 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_10_11_ARS_OD_DistYStd_Obj_10 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_10_11_ARS_OD_VabsYStd_Obj_10_Byte1 : 1;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_10_11_ARS_OD_VabsXStd_Obj_10 : 7;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_10_11_ARS_OD_AabsXStd_Obj_10_Byte1 : 2;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_10_11_ARS_OD_VabsYStd_Obj_10_Byte0 : 6;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_10_11_ARS_OD_Classification_Obj_10 : 3;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_10_11_ARS_OD_AabsXStd_Obj_10_Byte0 : 5;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_10_11_ARS_OD_AabsYStd_Obj_10 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_10_11_ARS_OD_ProbOfExist_Obj_10_Byte1 : 1;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_10_11_ARS_OD_ClassConf_Obj_10 : 7;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_10_11_ARS_OD_DynConf_Obj_10_Byte1 : 2;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_10_11_ARS_OD_ProbOfExist_Obj_10_Byte0 : 6;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_10_11_ARS_OD_DynProp_Obj_10 : 3;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_10_11_ARS_OD_DynConf_Obj_10_Byte0 : 5;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_10_11_ARS_OD_Length_Obj_10_Byte1 : 1;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_10_11_ARS_OD_MirrorProb_Obj_10 : 7;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_10_11_ARS_OD_MaintenanceState_Obj_10 : 2;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_10_11_ARS_OD_Length_Obj_10_Byte0 : 6;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_10_11_ARS_OD_RCS_Obj_10_Byte1 : 1;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_10_11_ARS_OD_Width_Obj_10 : 7;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_10_11_ARS_OD_RCS_Obj_10_Byte0 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_10_11_ARS_OD_Orientation_Obj_10_Byte1 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_10_11_ARS_OD_YawRateAbs_Obj_10_Byte1 : 6;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_10_11_ARS_OD_Orientation_Obj_10_Byte0 : 2;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_10_11_ARS_OD_YawRateAbsStd_Obj_10_Byte1 : 4;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_10_11_ARS_OD_YawRateAbs_Obj_10_Byte0 : 4;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_10_11_ARS_OD_RefPoint_Obj_10 : 2;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_10_11_ARS_OD_YawRateAbsStd_Obj_10_Byte0 : 6;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_10_11_ARS_OD_LifeCycle_Obj_10_Byte1 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_10_11_ARS_OD_LifeCycle_Obj_10_Byte0 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_10_11_ARS_OD_DistX_Obj_11_Byte1 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_10_11_ARS_OD_VabsX_Obj_11_Byte1 : 4;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_10_11_ARS_OD_DistX_Obj_11_Byte0 : 4;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_10_11_ARS_OD_AabsX_Obj_11_Byte1 : 1;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_10_11_ARS_OD_VabsX_Obj_11_Byte0 : 7;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_10_11_ARS_OD_AabsX_Obj_11_Byte0 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_10_11_ARS_OD_DistY_Obj_11_Byte1 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_10_11_ARS_OD_VabsY_Obj_11_Byte1 : 4;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_10_11_ARS_OD_DistY_Obj_11_Byte0 : 4;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_10_11_ARS_OD_AabsY_Obj_11_Byte1 : 1;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_10_11_ARS_OD_VabsY_Obj_11_Byte0 : 7;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_10_11_ARS_OD_AabsY_Obj_11_Byte0 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_10_11_ARS_OD_DistXStd_Obj_11 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_10_11_ARS_OD_DistYStd_Obj_11 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_10_11_ARS_OD_VabsYStd_Obj_11_Byte1 : 1;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_10_11_ARS_OD_VabsXStd_Obj_11 : 7;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_10_11_ARS_OD_AabsXStd_Obj_11_Byte1 : 2;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_10_11_ARS_OD_VabsYStd_Obj_11_Byte0 : 6;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_10_11_ARS_OD_Classification_Obj_11 : 3;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_10_11_ARS_OD_AabsXStd_Obj_11_Byte0 : 5;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_10_11_ARS_OD_AabsYStd_Obj_11 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_10_11_ARS_OD_ProbOfExist_Obj_11_Byte1 : 1;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_10_11_ARS_OD_ClassConf_Obj_11 : 7;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_10_11_ARS_OD_DynConf_Obj_11_Byte1 : 2;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_10_11_ARS_OD_ProbOfExist_Obj_11_Byte0 : 6;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_10_11_ARS_OD_DynProp_Obj_11 : 3;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_10_11_ARS_OD_DynConf_Obj_11_Byte0 : 5;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_10_11_ARS_OD_Length_Obj_11_Byte1 : 1;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_10_11_ARS_OD_MirrorProb_Obj_11 : 7;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_10_11_ARS_OD_MaintenanceState_Obj_11 : 2;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_10_11_ARS_OD_Length_Obj_11_Byte0 : 6;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_10_11_ARS_OD_RCS_Obj_11_Byte1 : 1;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_10_11_ARS_OD_Width_Obj_11 : 7;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_10_11_ARS_OD_RCS_Obj_11_Byte0 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_10_11_ARS_OD_Orientation_Obj_11_Byte1 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_10_11_ARS_OD_YawRateAbs_Obj_11_Byte1 : 6;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_10_11_ARS_OD_Orientation_Obj_11_Byte0 : 2;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_10_11_ARS_OD_YawRateAbsStd_Obj_11_Byte1 : 4;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_10_11_ARS_OD_YawRateAbs_Obj_11_Byte0 : 4;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_10_11_ARS_OD_RefPoint_Obj_11 : 2;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_10_11_ARS_OD_YawRateAbsStd_Obj_11_Byte0 : 6;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_10_11_ARS_OD_LifeCycle_Obj_11_Byte1 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_10_11_ARS_OD_LifeCycle_Obj_11_Byte0 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_10_11_ARS_OD_OrientationStd_Obj_11 : 4;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_10_11_ARS_OD_OrientationStd_Obj_10 : 4;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_10_11_ARS_OD_MicroDopplerFlag_10 : 1;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_10_11_ARS_OD_ObstacleProb_Obj_10 : 7;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_10_11_ARS_OD_MicroDopplerFlag_11 : 1;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_10_11_ARS_OD_ObstacleProb_Obj_11 : 7;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_10_11_ARS_OD_ID_10 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_10_11_ARS_OD_ID_11 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_10_11_DistHeight_Obj_10 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_10_11_DistHeight_Obj_11 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_10_11_ARS_OD_MsgCounter_Obj_10_11 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_10_11_ARS_OD_CRC16_Checksum_Obj_10_11_Byte1 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_10_11_ARS_OD_CRC16_Checksum_Obj_10_11_Byte0 : 8;
} RxPdu_CanConfigSet_Rx_Radar_ARS_OD_10_11_BufType;
extern VAR(RxPdu_CanConfigSet_Rx_Radar_ARS_OD_10_11_BufType, COM_VAR_NOINIT) Com_RxPduSignal_CanConfigSet_Rx_Radar_ARS_OD_10_11 ;

typedef struct
{
    uint8 CanConfigSet_Rx_Radar_ARS_OD_12_13_ARS_OD_DistX_Obj_12_Byte1 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_12_13_ARS_OD_VabsX_Obj_12_Byte1 : 4;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_12_13_ARS_OD_DistX_Obj_12_Byte0 : 4;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_12_13_ARS_OD_AabsX_Obj_12_Byte1 : 1;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_12_13_ARS_OD_VabsX_Obj_12_Byte0 : 7;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_12_13_ARS_OD_AabsX_Obj_12_Byte0 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_12_13_ARS_OD_DistY_Obj_12_Byte1 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_12_13_ARS_OD_VabsY_Obj_12_Byte1 : 4;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_12_13_ARS_OD_DistY_Obj_12_Byte0 : 4;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_12_13_ARS_OD_AabsY_Obj_12_Byte1 : 1;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_12_13_ARS_OD_VabsY_Obj_12_Byte0 : 7;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_12_13_ARS_OD_AabsY_Obj_12_Byte0 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_12_13_ARS_OD_DistXStd_Obj_12 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_12_13_ARS_OD_DistYStd_Obj_12 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_12_13_ARS_OD_VabsYStd_Obj_12_Byte1 : 1;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_12_13_ARS_OD_VabsXStd_Obj_12 : 7;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_12_13_ARS_OD_AabsXStd_Obj_12_Byte1 : 2;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_12_13_ARS_OD_VabsYStd_Obj_12_Byte0 : 6;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_12_13_ARS_OD_Classification_Obj_12 : 3;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_12_13_ARS_OD_AabsXStd_Obj_12_Byte0 : 5;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_12_13_ARS_OD_AabsYStd_Obj_12 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_12_13_ARS_OD_ProbOfExist_Obj_12_Byte1 : 1;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_12_13_ARS_OD_ClassConf_Obj_12 : 7;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_12_13_ARS_OD_DynConf_Obj_12_Byte1 : 2;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_12_13_ARS_OD_ProbOfExist_Obj_12_Byte0 : 6;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_12_13_ARS_OD_DynProp_Obj_12 : 3;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_12_13_ARS_OD_DynConf_Obj_12_Byte0 : 5;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_12_13_ARS_OD_Length_Obj_12_Byte1 : 1;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_12_13_ARS_OD_MirrorProb_Obj_12 : 7;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_12_13_ARS_OD_MaintenanceState_Obj_12 : 2;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_12_13_ARS_OD_Length_Obj_12_Byte0 : 6;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_12_13_ARS_OD_RCS_Obj_12_Byte1 : 1;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_12_13_ARS_OD_Width_Obj_12 : 7;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_12_13_ARS_OD_RCS_Obj_12_Byte0 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_12_13_ARS_OD_Orientation_Obj_12_Byte1 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_12_13_ARS_OD_YawRateAbs_Obj_12_Byte1 : 6;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_12_13_ARS_OD_Orientation_Obj_12_Byte0 : 2;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_12_13_ARS_OD_YawRateAbsStd_Obj_12_Byte1 : 4;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_12_13_ARS_OD_YawRateAbs_Obj_12_Byte0 : 4;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_12_13_ARS_OD_RefPoint_Obj_12 : 2;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_12_13_ARS_OD_YawRateAbsStd_Obj_12_Byte0 : 6;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_12_13_ARS_OD_LifeCycle_Obj_12_Byte1 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_12_13_ARS_OD_LifeCycle_Obj_12_Byte0 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_12_13_ARS_OD_DistX_Obj_13_Byte1 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_12_13_ARS_OD_VabsX_Obj_13_Byte1 : 4;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_12_13_ARS_OD_DistX_Obj_13_Byte0 : 4;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_12_13_ARS_OD_AabsX_Obj_13_Byte1 : 1;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_12_13_ARS_OD_VabsX_Obj_13_Byte0 : 7;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_12_13_ARS_OD_AabsX_Obj_13_Byte0 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_12_13_ARS_OD_DistY_Obj_13_Byte1 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_12_13_ARS_OD_VabsY_Obj_13_Byte1 : 4;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_12_13_ARS_OD_DistY_Obj_13_Byte0 : 4;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_12_13_ARS_OD_AabsY_Obj_13_Byte1 : 1;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_12_13_ARS_OD_VabsY_Obj_13_Byte0 : 7;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_12_13_ARS_OD_AabsY_Obj_13_Byte0 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_12_13_ARS_OD_DistXStd_Obj_13 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_12_13_ARS_OD_DistYStd_Obj_13 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_12_13_ARS_OD_VabsYStd_Obj_13_Byte1 : 1;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_12_13_ARS_OD_VabsXStd_Obj_13 : 7;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_12_13_ARS_OD_AabsXStd_Obj_13_Byte1 : 2;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_12_13_ARS_OD_VabsYStd_Obj_13_Byte0 : 6;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_12_13_ARS_OD_Classification_Obj_13 : 3;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_12_13_ARS_OD_AabsXStd_Obj_13_Byte0 : 5;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_12_13_ARS_OD_AabsYStd_Obj_13 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_12_13_ARS_OD_ProbOfExist_Obj_13_Byte1 : 1;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_12_13_ARS_OD_ClassConf_Obj_13 : 7;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_12_13_ARS_OD_DynConf_Obj_13_Byte1 : 2;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_12_13_ARS_OD_ProbOfExist_Obj_13_Byte0 : 6;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_12_13_ARS_OD_DynProp_Obj_13 : 3;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_12_13_ARS_OD_DynConf_Obj_13_Byte0 : 5;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_12_13_ARS_OD_Length_Obj_13_Byte1 : 1;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_12_13_ARS_OD_MirrorProb_Obj_13 : 7;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_12_13_ARS_OD_MaintenanceState_Obj_13 : 2;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_12_13_ARS_OD_Length_Obj_13_Byte0 : 6;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_12_13_ARS_OD_RCS_Obj_13_Byte1 : 1;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_12_13_ARS_OD_Width_Obj_13 : 7;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_12_13_ARS_OD_RCS_Obj_13_Byte0 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_12_13_ARS_OD_Orientation_Obj_13_Byte1 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_12_13_ARS_OD_YawRateAbs_Obj_13_Byte1 : 6;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_12_13_ARS_OD_Orientation_Obj_13_Byte0 : 2;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_12_13_ARS_OD_YawRateAbsStd_Obj_13_Byte1 : 4;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_12_13_ARS_OD_YawRateAbs_Obj_13_Byte0 : 4;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_12_13_ARS_OD_RefPoint_Obj_13 : 2;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_12_13_ARS_OD_YawRateAbsStd_Obj_13_Byte0 : 6;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_12_13_ARS_OD_LifeCycle_Obj_13_Byte1 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_12_13_ARS_OD_LifeCycle_Obj_13_Byte0 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_12_13_ARS_OD_OrientationStd_Obj_13 : 4;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_12_13_ARS_OD_OrientationStd_Obj_12 : 4;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_12_13_ARS_OD_MicroDopplerFlag_12 : 1;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_12_13_ARS_OD_ObstacleProb_Obj_12 : 7;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_12_13_ARS_OD_MicroDopplerFlag_13 : 1;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_12_13_ARS_OD_ObstacleProb_Obj_13 : 7;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_12_13_ARS_OD_ID_12 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_12_13_ARS_OD_ID_13 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_12_13_DistHeight_Obj_12 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_12_13_DistHeight_Obj_13 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_12_13_ARS_OD_MsgCounter_Obj_12_13 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_12_13_ARS_OD_CRC16_Checksum_Obj_12_13_Byte1 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_12_13_ARS_OD_CRC16_Checksum_Obj_12_13_Byte0 : 8;
} RxPdu_CanConfigSet_Rx_Radar_ARS_OD_12_13_BufType;
extern VAR(RxPdu_CanConfigSet_Rx_Radar_ARS_OD_12_13_BufType, COM_VAR_NOINIT) Com_RxPduSignal_CanConfigSet_Rx_Radar_ARS_OD_12_13 ;

typedef struct
{
    uint8 CanConfigSet_Rx_Radar_ARS_OD_14_15_ARS_OD_DistX_Obj_14_Byte1 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_14_15_ARS_OD_VabsX_Obj_14_Byte1 : 4;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_14_15_ARS_OD_DistX_Obj_14_Byte0 : 4;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_14_15_ARS_OD_AabsX_Obj_14_Byte1 : 1;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_14_15_ARS_OD_VabsX_Obj_14_Byte0 : 7;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_14_15_ARS_OD_AabsX_Obj_14_Byte0 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_14_15_ARS_OD_DistY_Obj_14_Byte1 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_14_15_ARS_OD_VabsY_Obj_14_Byte1 : 4;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_14_15_ARS_OD_DistY_Obj_14_Byte0 : 4;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_14_15_ARS_OD_AabsY_Obj_14_Byte1 : 1;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_14_15_ARS_OD_VabsY_Obj_14_Byte0 : 7;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_14_15_ARS_OD_AabsY_Obj_14_Byte0 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_14_15_ARS_OD_DistXStd_Obj_14 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_14_15_ARS_OD_DistYStd_Obj_14 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_14_15_ARS_OD_VabsYStd_Obj_14_Byte1 : 1;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_14_15_ARS_OD_VabsXStd_Obj_14 : 7;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_14_15_ARS_OD_AabsXStd_Obj_14_Byte1 : 2;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_14_15_ARS_OD_VabsYStd_Obj_14_Byte0 : 6;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_14_15_ARS_OD_Classification_Obj_14 : 3;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_14_15_ARS_OD_AabsXStd_Obj_14_Byte0 : 5;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_14_15_ARS_OD_AabsYStd_Obj_14 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_14_15_ARS_OD_ProbOfExist_Obj_14_Byte1 : 1;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_14_15_ARS_OD_ClassConf_Obj_14 : 7;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_14_15_ARS_OD_DynConf_Obj_14_Byte1 : 2;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_14_15_ARS_OD_ProbOfExist_Obj_14_Byte0 : 6;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_14_15_ARS_OD_DynProp_Obj_14 : 3;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_14_15_ARS_OD_DynConf_Obj_14_Byte0 : 5;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_14_15_ARS_OD_Length_Obj_14_Byte1 : 1;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_14_15_ARS_OD_MirrorProb_Obj_14 : 7;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_14_15_ARS_OD_MaintenanceState_Obj_14 : 2;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_14_15_ARS_OD_Length_Obj_14_Byte0 : 6;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_14_15_ARS_OD_RCS_Obj_14_Byte1 : 1;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_14_15_ARS_OD_Width_Obj_14 : 7;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_14_15_ARS_OD_RCS_Obj_14_Byte0 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_14_15_ARS_OD_Orientation_Obj_14_Byte1 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_14_15_ARS_OD_YawRateAbs_Obj_14_Byte1 : 6;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_14_15_ARS_OD_Orientation_Obj_14_Byte0 : 2;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_14_15_ARS_OD_YawRateAbsStd_Obj_14_Byte1 : 4;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_14_15_ARS_OD_YawRateAbs_Obj_14_Byte0 : 4;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_14_15_ARS_OD_RefPoint_Obj_14 : 2;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_14_15_ARS_OD_YawRateAbsStd_Obj_14_Byte0 : 6;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_14_15_ARS_OD_LifeCycle_Obj_14_Byte1 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_14_15_ARS_OD_LifeCycle_Obj_14_Byte0 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_14_15_ARS_OD_DistX_Obj_15_Byte1 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_14_15_ARS_OD_VabsX_Obj_15_Byte1 : 4;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_14_15_ARS_OD_DistX_Obj_15_Byte0 : 4;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_14_15_ARS_OD_AabsX_Obj_15_Byte1 : 1;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_14_15_ARS_OD_VabsX_Obj_15_Byte0 : 7;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_14_15_ARS_OD_AabsX_Obj_15_Byte0 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_14_15_ARS_OD_DistY_Obj_15_Byte1 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_14_15_ARS_OD_VabsY_Obj_15_Byte1 : 4;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_14_15_ARS_OD_DistY_Obj_15_Byte0 : 4;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_14_15_ARS_OD_AabsY_Obj_15_Byte1 : 1;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_14_15_ARS_OD_VabsY_Obj_15_Byte0 : 7;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_14_15_ARS_OD_AabsY_Obj_15_Byte0 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_14_15_ARS_OD_DistXStd_Obj_15 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_14_15_ARS_OD_DistYStd_Obj_15 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_14_15_ARS_OD_VabsYStd_Obj_15_Byte1 : 1;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_14_15_ARS_OD_VabsXStd_Obj_15 : 7;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_14_15_ARS_OD_AabsXStd_Obj_15_Byte1 : 2;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_14_15_ARS_OD_VabsYStd_Obj_15_Byte0 : 6;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_14_15_ARS_OD_Classification_Obj_15 : 3;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_14_15_ARS_OD_AabsXStd_Obj_15_Byte0 : 5;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_14_15_ARS_OD_AabsYStd_Obj_15 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_14_15_ARS_OD_ProbOfExist_Obj_15_Byte1 : 1;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_14_15_ARS_OD_ClassConf_Obj_15 : 7;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_14_15_ARS_OD_DynConf_Obj_15_Byte1 : 2;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_14_15_ARS_OD_ProbOfExist_Obj_15_Byte0 : 6;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_14_15_ARS_OD_DynProp_Obj_15 : 3;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_14_15_ARS_OD_DynConf_Obj_15_Byte0 : 5;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_14_15_ARS_OD_Length_Obj_15_Byte1 : 1;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_14_15_ARS_OD_MirrorProb_Obj_15 : 7;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_14_15_ARS_OD_MaintenanceState_Obj_15 : 2;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_14_15_ARS_OD_Length_Obj_15_Byte0 : 6;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_14_15_ARS_OD_RCS_Obj_15_Byte1 : 1;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_14_15_ARS_OD_Width_Obj_15 : 7;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_14_15_ARS_OD_RCS_Obj_15_Byte0 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_14_15_ARS_OD_Orientation_Obj_15_Byte1 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_14_15_ARS_OD_YawRateAbs_Obj_15_Byte1 : 6;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_14_15_ARS_OD_Orientation_Obj_15_Byte0 : 2;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_14_15_ARS_OD_YawRateAbsStd_Obj_15_Byte1 : 4;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_14_15_ARS_OD_YawRateAbs_Obj_15_Byte0 : 4;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_14_15_ARS_OD_RefPoint_Obj_15 : 2;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_14_15_ARS_OD_YawRateAbsStd_Obj_15_Byte0 : 6;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_14_15_ARS_OD_LifeCycle_Obj_15_Byte1 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_14_15_ARS_OD_LifeCycle_Obj_15_Byte0 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_14_15_ARS_OD_OrientationStd_Obj_15 : 4;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_14_15_ARS_OD_OrientationStd_Obj_14 : 4;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_14_15_ARS_OD_MicroDopplerFlag_14 : 1;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_14_15_ARS_OD_ObstacleProb_Obj_14 : 7;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_14_15_ARS_OD_MicroDopplerFlag_15 : 1;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_14_15_ARS_OD_ObstacleProb_Obj_15 : 7;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_14_15_ARS_OD_ID_14 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_14_15_ARS_OD_ID_15 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_14_15_DistHeight_Obj_14 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_14_15_DistHeight_Obj_15 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_14_15_ARS_OD_MsgCounter_Obj_14_15 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_14_15_ARS_OD_CRC16_Checksum_Obj_14_15_Byte1 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_14_15_ARS_OD_CRC16_Checksum_Obj_14_15_Byte0 : 8;
} RxPdu_CanConfigSet_Rx_Radar_ARS_OD_14_15_BufType;
extern VAR(RxPdu_CanConfigSet_Rx_Radar_ARS_OD_14_15_BufType, COM_VAR_NOINIT) Com_RxPduSignal_CanConfigSet_Rx_Radar_ARS_OD_14_15 ;

typedef struct
{
    uint8 CanConfigSet_Rx_Radar_ARS_OD_16_17_ARS_OD_DistX_Obj_16_Byte1 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_16_17_ARS_OD_VabsX_Obj_16_Byte1 : 4;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_16_17_ARS_OD_DistX_Obj_16_Byte0 : 4;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_16_17_ARS_OD_AabsX_Obj_16_Byte1 : 1;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_16_17_ARS_OD_VabsX_Obj_16_Byte0 : 7;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_16_17_ARS_OD_AabsX_Obj_16_Byte0 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_16_17_ARS_OD_DistY_Obj_16_Byte1 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_16_17_ARS_OD_VabsY_Obj_16_Byte1 : 4;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_16_17_ARS_OD_DistY_Obj_16_Byte0 : 4;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_16_17_ARS_OD_AabsY_Obj_16_Byte1 : 1;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_16_17_ARS_OD_VabsY_Obj_16_Byte0 : 7;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_16_17_ARS_OD_AabsY_Obj_16_Byte0 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_16_17_ARS_OD_DistXStd_Obj_16 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_16_17_ARS_OD_DistYStd_Obj_16 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_16_17_ARS_OD_VabsYStd_Obj_16_Byte1 : 1;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_16_17_ARS_OD_VabsXStd_Obj_16 : 7;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_16_17_ARS_OD_AabsXStd_Obj_16_Byte1 : 2;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_16_17_ARS_OD_VabsYStd_Obj_16_Byte0 : 6;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_16_17_ARS_OD_Classification_Obj_16 : 3;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_16_17_ARS_OD_AabsXStd_Obj_16_Byte0 : 5;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_16_17_ARS_OD_AabsYStd_Obj_16 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_16_17_ARS_OD_ProbOfExist_Obj_16_Byte1 : 1;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_16_17_ARS_OD_ClassConf_Obj_16 : 7;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_16_17_ARS_OD_DynConf_Obj_16_Byte1 : 2;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_16_17_ARS_OD_ProbOfExist_Obj_16_Byte0 : 6;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_16_17_ARS_OD_DynProp_Obj_16 : 3;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_16_17_ARS_OD_DynConf_Obj_16_Byte0 : 5;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_16_17_ARS_OD_Length_Obj_16_Byte1 : 1;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_16_17_ARS_OD_MirrorProb_Obj_16 : 7;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_16_17_ARS_OD_MaintenanceState_Obj_16 : 2;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_16_17_ARS_OD_Length_Obj_16_Byte0 : 6;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_16_17_ARS_OD_RCS_Obj_16_Byte1 : 1;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_16_17_ARS_OD_Width_Obj_16 : 7;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_16_17_ARS_OD_RCS_Obj_16_Byte0 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_16_17_ARS_OD_Orientation_Obj_16_Byte1 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_16_17_ARS_OD_YawRateAbs_Obj_16_Byte1 : 6;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_16_17_ARS_OD_Orientation_Obj_16_Byte0 : 2;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_16_17_ARS_OD_YawRateAbsStd_Obj_16_Byte1 : 4;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_16_17_ARS_OD_YawRateAbs_Obj_16_Byte0 : 4;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_16_17_ARS_OD_RefPoint_Obj_16 : 2;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_16_17_ARS_OD_YawRateAbsStd_Obj_16_Byte0 : 6;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_16_17_ARS_OD_LifeCycle_Obj_16_Byte1 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_16_17_ARS_OD_LifeCycle_Obj_16_Byte0 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_16_17_ARS_OD_DistX_Obj_17_Byte1 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_16_17_ARS_OD_VabsX_Obj_17_Byte1 : 4;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_16_17_ARS_OD_DistX_Obj_17_Byte0 : 4;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_16_17_ARS_OD_AabsX_Obj_17_Byte1 : 1;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_16_17_ARS_OD_VabsX_Obj_17_Byte0 : 7;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_16_17_ARS_OD_AabsX_Obj_17_Byte0 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_16_17_ARS_OD_DistY_Obj_17_Byte1 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_16_17_ARS_OD_VabsY_Obj_17_Byte1 : 4;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_16_17_ARS_OD_DistY_Obj_17_Byte0 : 4;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_16_17_ARS_OD_AabsY_Obj_17_Byte1 : 1;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_16_17_ARS_OD_VabsY_Obj_17_Byte0 : 7;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_16_17_ARS_OD_AabsY_Obj_17_Byte0 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_16_17_ARS_OD_DistXStd_Obj_17 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_16_17_ARS_OD_DistYStd_Obj_17 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_16_17_ARS_OD_VabsYStd_Obj_17_Byte1 : 1;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_16_17_ARS_OD_VabsXStd_Obj_17 : 7;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_16_17_ARS_OD_AabsXStd_Obj_17_Byte1 : 2;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_16_17_ARS_OD_VabsYStd_Obj_17_Byte0 : 6;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_16_17_ARS_OD_Classification_Obj_17 : 3;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_16_17_ARS_OD_AabsXStd_Obj_17_Byte0 : 5;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_16_17_ARS_OD_AabsYStd_Obj_17 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_16_17_ARS_OD_ProbOfExist_Obj_17_Byte1 : 1;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_16_17_ARS_OD_ClassConf_Obj_17 : 7;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_16_17_ARS_OD_DynConf_Obj_17_Byte1 : 2;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_16_17_ARS_OD_ProbOfExist_Obj_17_Byte0 : 6;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_16_17_ARS_OD_DynProp_Obj_17 : 3;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_16_17_ARS_OD_DynConf_Obj_17_Byte0 : 5;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_16_17_ARS_OD_Length_Obj_17_Byte1 : 1;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_16_17_ARS_OD_MirrorProb_Obj_17 : 7;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_16_17_ARS_OD_MaintenanceState_Obj_17 : 2;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_16_17_ARS_OD_Length_Obj_17_Byte0 : 6;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_16_17_ARS_OD_RCS_Obj_17_Byte1 : 1;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_16_17_ARS_OD_Width_Obj_17 : 7;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_16_17_ARS_OD_RCS_Obj_17_Byte0 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_16_17_ARS_OD_Orientation_Obj_17_Byte1 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_16_17_ARS_OD_YawRateAbs_Obj_17_Byte1 : 6;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_16_17_ARS_OD_Orientation_Obj_17_Byte0 : 2;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_16_17_ARS_OD_YawRateAbsStd_Obj_17_Byte1 : 4;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_16_17_ARS_OD_YawRateAbs_Obj_17_Byte0 : 4;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_16_17_ARS_OD_RefPoint_Obj_17 : 2;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_16_17_ARS_OD_YawRateAbsStd_Obj_17_Byte0 : 6;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_16_17_ARS_OD_LifeCycle_Obj_17_Byte1 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_16_17_ARS_OD_LifeCycle_Obj_17_Byte0 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_16_17_ARS_OD_OrientationStd_Obj_17 : 4;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_16_17_ARS_OD_OrientationStd_Obj_16 : 4;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_16_17_ARS_OD_MicroDopplerFlag_16 : 1;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_16_17_ARS_OD_ObstacleProb_Obj_16 : 7;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_16_17_ARS_OD_MicroDopplerFlag_17 : 1;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_16_17_ARS_OD_ObstacleProb_Obj_17 : 7;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_16_17_ARS_OD_ID_16 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_16_17_ARS_OD_ID_17 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_16_17_DistHeight_Obj_16 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_16_17_DistHeight_Obj_17 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_16_17_ARS_OD_MsgCounter_Obj_16_17 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_16_17_ARS_OD_CRC16_Checksum_Obj_16_17_Byte1 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_16_17_ARS_OD_CRC16_Checksum_Obj_16_17_Byte0 : 8;
} RxPdu_CanConfigSet_Rx_Radar_ARS_OD_16_17_BufType;
extern VAR(RxPdu_CanConfigSet_Rx_Radar_ARS_OD_16_17_BufType, COM_VAR_NOINIT) Com_RxPduSignal_CanConfigSet_Rx_Radar_ARS_OD_16_17 ;

typedef struct
{
    uint8 CanConfigSet_Rx_Radar_ARS_OD_18_19_ARS_OD_DistX_Obj_18_Byte1 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_18_19_ARS_OD_VabsX_Obj_18_Byte1 : 4;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_18_19_ARS_OD_DistX_Obj_18_Byte0 : 4;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_18_19_ARS_OD_AabsX_Obj_18_Byte1 : 1;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_18_19_ARS_OD_VabsX_Obj_18_Byte0 : 7;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_18_19_ARS_OD_AabsX_Obj_18_Byte0 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_18_19_ARS_OD_DistY_Obj_18_Byte1 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_18_19_ARS_OD_VabsY_Obj_18_Byte1 : 4;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_18_19_ARS_OD_DistY_Obj_18_Byte0 : 4;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_18_19_ARS_OD_AabsY_Obj_18_Byte1 : 1;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_18_19_ARS_OD_VabsY_Obj_18_Byte0 : 7;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_18_19_ARS_OD_AabsY_Obj_18_Byte0 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_18_19_ARS_OD_DistXStd_Obj_18 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_18_19_ARS_OD_DistYStd_Obj_18 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_18_19_ARS_OD_VabsYStd_Obj_18_Byte1 : 1;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_18_19_ARS_OD_VabsXStd_Obj_18 : 7;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_18_19_ARS_OD_AabsXStd_Obj_18_Byte1 : 2;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_18_19_ARS_OD_VabsYStd_Obj_18_Byte0 : 6;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_18_19_ARS_OD_Classification_Obj_18 : 3;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_18_19_ARS_OD_AabsXStd_Obj_18_Byte0 : 5;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_18_19_ARS_OD_AabsYStd_Obj_18 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_18_19_ARS_OD_ProbOfExist_Obj_18_Byte1 : 1;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_18_19_ARS_OD_ClassConf_Obj_18 : 7;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_18_19_ARS_OD_DynConf_Obj_18_Byte1 : 2;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_18_19_ARS_OD_ProbOfExist_Obj_18_Byte0 : 6;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_18_19_ARS_OD_DynProp_Obj_18 : 3;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_18_19_ARS_OD_DynConf_Obj_18_Byte0 : 5;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_18_19_ARS_OD_Length_Obj_18_Byte1 : 1;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_18_19_ARS_OD_MirrorProb_Obj_18 : 7;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_18_19_ARS_OD_MaintenanceState_Obj_18 : 2;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_18_19_ARS_OD_Length_Obj_18_Byte0 : 6;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_18_19_ARS_OD_RCS_Obj_18_Byte1 : 1;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_18_19_ARS_OD_Width_Obj_18 : 7;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_18_19_ARS_OD_RCS_Obj_18_Byte0 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_18_19_ARS_OD_Orientation_Obj_18_Byte1 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_18_19_ARS_OD_YawRateAbs_Obj_18_Byte1 : 6;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_18_19_ARS_OD_Orientation_Obj_18_Byte0 : 2;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_18_19_ARS_OD_YawRateAbsStd_Obj_18_Byte1 : 4;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_18_19_ARS_OD_YawRateAbs_Obj_18_Byte0 : 4;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_18_19_ARS_OD_RefPoint_Obj_18 : 2;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_18_19_ARS_OD_YawRateAbsStd_Obj_18_Byte0 : 6;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_18_19_ARS_OD_LifeCycle_Obj_18_Byte1 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_18_19_ARS_OD_LifeCycle_Obj_18_Byte0 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_18_19_ARS_OD_DistX_Obj_19_Byte1 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_18_19_ARS_OD_VabsX_Obj_19_Byte1 : 4;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_18_19_ARS_OD_DistX_Obj_19_Byte0 : 4;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_18_19_ARS_OD_AabsX_Obj_19_Byte1 : 1;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_18_19_ARS_OD_VabsX_Obj_19_Byte0 : 7;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_18_19_ARS_OD_AabsX_Obj_19_Byte0 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_18_19_ARS_OD_DistY_Obj_19_Byte1 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_18_19_ARS_OD_VabsY_Obj_19_Byte1 : 4;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_18_19_ARS_OD_DistY_Obj_19_Byte0 : 4;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_18_19_ARS_OD_AabsY_Obj_19_Byte1 : 1;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_18_19_ARS_OD_VabsY_Obj_19_Byte0 : 7;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_18_19_ARS_OD_AabsY_Obj_19_Byte0 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_18_19_ARS_OD_DistXStd_Obj_19 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_18_19_ARS_OD_DistYStd_Obj_19 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_18_19_ARS_OD_VabsYStd_Obj_19_Byte1 : 1;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_18_19_ARS_OD_VabsXStd_Obj_19 : 7;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_18_19_ARS_OD_AabsXStd_Obj_19_Byte1 : 2;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_18_19_ARS_OD_VabsYStd_Obj_19_Byte0 : 6;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_18_19_ARS_OD_Classification_Obj_19 : 3;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_18_19_ARS_OD_AabsXStd_Obj_19_Byte0 : 5;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_18_19_ARS_OD_AabsYStd_Obj_19 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_18_19_ARS_OD_ProbOfExist_Obj_19_Byte1 : 1;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_18_19_ARS_OD_ClassConf_Obj_19 : 7;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_18_19_ARS_OD_DynConf_Obj_19_Byte1 : 2;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_18_19_ARS_OD_ProbOfExist_Obj_19_Byte0 : 6;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_18_19_ARS_OD_DynProp_Obj_19 : 3;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_18_19_ARS_OD_DynConf_Obj_19_Byte0 : 5;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_18_19_ARS_OD_Length_Obj_19_Byte1 : 1;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_18_19_ARS_OD_MirrorProb_Obj_19 : 7;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_18_19_ARS_OD_MaintenanceState_Obj_19 : 2;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_18_19_ARS_OD_Length_Obj_19_Byte0 : 6;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_18_19_ARS_OD_RCS_Obj_19_Byte1 : 1;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_18_19_ARS_OD_Width_Obj_19 : 7;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_18_19_ARS_OD_RCS_Obj_19_Byte0 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_18_19_ARS_OD_Orientation_Obj_19_Byte1 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_18_19_ARS_OD_YawRateAbs_Obj_19_Byte1 : 6;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_18_19_ARS_OD_Orientation_Obj_19_Byte0 : 2;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_18_19_ARS_OD_YawRateAbsStd_Obj_19_Byte1 : 4;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_18_19_ARS_OD_YawRateAbs_Obj_19_Byte0 : 4;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_18_19_ARS_OD_RefPoint_Obj_19 : 2;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_18_19_ARS_OD_YawRateAbsStd_Obj_19_Byte0 : 6;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_18_19_ARS_OD_LifeCycle_Obj_19_Byte1 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_18_19_ARS_OD_LifeCycle_Obj_19_Byte0 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_18_19_ARS_OD_OrientationStd_Obj_19 : 4;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_18_19_ARS_OD_OrientationStd_Obj_18 : 4;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_18_19_ARS_OD_MicroDopplerFlag_18 : 1;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_18_19_ARS_OD_ObstacleProb_Obj_18 : 7;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_18_19_ARS_OD_MicroDopplerFlag_19 : 1;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_18_19_ARS_OD_ObstacleProb_Obj_19 : 7;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_18_19_ARS_OD_ID_18 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_18_19_ARS_OD_ID_19 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_18_19_DistHeight_Obj_18 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_18_19_DistHeight_Obj_19 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_18_19_ARS_OD_MsgCounter_Obj_18_19 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_18_19_ARS_OD_CRC16_Checksum_Obj_18_19_Byte1 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_18_19_ARS_OD_CRC16_Checksum_Obj_18_19_Byte0 : 8;
} RxPdu_CanConfigSet_Rx_Radar_ARS_OD_18_19_BufType;
extern VAR(RxPdu_CanConfigSet_Rx_Radar_ARS_OD_18_19_BufType, COM_VAR_NOINIT) Com_RxPduSignal_CanConfigSet_Rx_Radar_ARS_OD_18_19 ;

typedef struct
{
    uint8 CanConfigSet_Rx_Radar_ARS_OD_20_21_ARS_OD_DistX_Obj_20_Byte1 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_20_21_ARS_OD_VabsX_Obj_20_Byte1 : 4;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_20_21_ARS_OD_DistX_Obj_20_Byte0 : 4;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_20_21_ARS_OD_AabsX_Obj_20_Byte1 : 1;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_20_21_ARS_OD_VabsX_Obj_20_Byte0 : 7;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_20_21_ARS_OD_AabsX_Obj_20_Byte0 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_20_21_ARS_OD_DistY_Obj_20_Byte1 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_20_21_ARS_OD_VabsY_Obj_20_Byte1 : 4;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_20_21_ARS_OD_DistY_Obj_20_Byte0 : 4;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_20_21_ARS_OD_AabsY_Obj_20_Byte1 : 1;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_20_21_ARS_OD_VabsY_Obj_20_Byte0 : 7;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_20_21_ARS_OD_AabsY_Obj_20_Byte0 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_20_21_ARS_OD_DistXStd_Obj_20 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_20_21_ARS_OD_DistYStd_Obj_20 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_20_21_ARS_OD_VabsYStd_Obj_20_Byte1 : 1;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_20_21_ARS_OD_VabsXStd_Obj_20 : 7;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_20_21_ARS_OD_AabsXStd_Obj_20_Byte1 : 2;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_20_21_ARS_OD_VabsYStd_Obj_20_Byte0 : 6;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_20_21_ARS_OD_Classification_Obj_20 : 3;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_20_21_ARS_OD_AabsXStd_Obj_20_Byte0 : 5;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_20_21_ARS_OD_AabsYStd_Obj_20 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_20_21_ARS_OD_ProbOfExist_Obj_20_Byte1 : 1;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_20_21_ARS_OD_ClassConf_Obj_20 : 7;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_20_21_ARS_OD_DynConf_Obj_20_Byte1 : 2;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_20_21_ARS_OD_ProbOfExist_Obj_20_Byte0 : 6;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_20_21_ARS_OD_DynProp_Obj_20 : 3;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_20_21_ARS_OD_DynConf_Obj_20_Byte0 : 5;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_20_21_ARS_OD_Length_Obj_20_Byte1 : 1;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_20_21_ARS_OD_MirrorProb_Obj_20 : 7;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_20_21_ARS_OD_MaintenanceState_Obj_20 : 2;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_20_21_ARS_OD_Length_Obj_20_Byte0 : 6;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_20_21_ARS_OD_RCS_Obj_20_Byte1 : 1;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_20_21_ARS_OD_Width_Obj_20 : 7;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_20_21_ARS_OD_RCS_Obj_20_Byte0 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_20_21_ARS_OD_Orientation_Obj_20_Byte1 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_20_21_ARS_OD_YawRateAbs_Obj_20_Byte1 : 6;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_20_21_ARS_OD_Orientation_Obj_20_Byte0 : 2;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_20_21_ARS_OD_YawRateAbsStd_Obj_20_Byte1 : 4;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_20_21_ARS_OD_YawRateAbs_Obj_20_Byte0 : 4;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_20_21_ARS_OD_RefPoint_Obj_20 : 2;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_20_21_ARS_OD_YawRateAbsStd_Obj_20_Byte0 : 6;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_20_21_ARS_OD_LifeCycle_Obj_20_Byte1 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_20_21_ARS_OD_LifeCycle_Obj_20_Byte0 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_20_21_ARS_OD_DistX_Obj_21_Byte1 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_20_21_ARS_OD_VabsX_Obj_21_Byte1 : 4;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_20_21_ARS_OD_DistX_Obj_21_Byte0 : 4;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_20_21_ARS_OD_AabsX_Obj_21_Byte1 : 1;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_20_21_ARS_OD_VabsX_Obj_21_Byte0 : 7;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_20_21_ARS_OD_AabsX_Obj_21_Byte0 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_20_21_ARS_OD_DistY_Obj_21_Byte1 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_20_21_ARS_OD_VabsY_Obj_21_Byte1 : 4;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_20_21_ARS_OD_DistY_Obj_21_Byte0 : 4;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_20_21_ARS_OD_AabsY_Obj_21_Byte1 : 1;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_20_21_ARS_OD_VabsY_Obj_21_Byte0 : 7;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_20_21_ARS_OD_AabsY_Obj_21_Byte0 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_20_21_ARS_OD_DistXStd_Obj_21 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_20_21_ARS_OD_DistYStd_Obj_21 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_20_21_ARS_OD_VabsYStd_Obj_21_Byte1 : 1;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_20_21_ARS_OD_VabsXStd_Obj_21 : 7;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_20_21_ARS_OD_AabsXStd_Obj_21_Byte1 : 2;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_20_21_ARS_OD_VabsYStd_Obj_21_Byte0 : 6;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_20_21_ARS_OD_Classification_Obj_21 : 3;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_20_21_ARS_OD_AabsXStd_Obj_21_Byte0 : 5;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_20_21_ARS_OD_AabsYStd_Obj_21 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_20_21_ARS_OD_ProbOfExist_Obj_21_Byte1 : 1;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_20_21_ARS_OD_ClassConf_Obj_21 : 7;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_20_21_ARS_OD_DynConf_Obj_21_Byte1 : 2;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_20_21_ARS_OD_ProbOfExist_Obj_21_Byte0 : 6;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_20_21_ARS_OD_DynProp_Obj_21 : 3;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_20_21_ARS_OD_DynConf_Obj_21_Byte0 : 5;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_20_21_ARS_OD_Length_Obj_21_Byte1 : 1;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_20_21_ARS_OD_MirrorProb_Obj_21 : 7;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_20_21_ARS_OD_MaintenanceState_Obj_21 : 2;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_20_21_ARS_OD_Length_Obj_21_Byte0 : 6;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_20_21_ARS_OD_RCS_Obj_21_Byte1 : 1;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_20_21_ARS_OD_Width_Obj_21 : 7;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_20_21_ARS_OD_RCS_Obj_21_Byte0 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_20_21_ARS_OD_Orientation_Obj_21_Byte1 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_20_21_ARS_OD_YawRateAbs_Obj_21_Byte1 : 6;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_20_21_ARS_OD_Orientation_Obj_21_Byte0 : 2;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_20_21_ARS_OD_YawRateAbsStd_Obj_21_Byte1 : 4;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_20_21_ARS_OD_YawRateAbs_Obj_21_Byte0 : 4;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_20_21_ARS_OD_RefPoint_Obj_21 : 2;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_20_21_ARS_OD_YawRateAbsStd_Obj_21_Byte0 : 6;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_20_21_ARS_OD_LifeCycle_Obj_21_Byte1 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_20_21_ARS_OD_LifeCycle_Obj_21_Byte0 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_20_21_ARS_OD_OrientationStd_Obj_21 : 4;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_20_21_ARS_OD_OrientationStd_Obj_20 : 4;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_20_21_ARS_OD_MicroDopplerFlag_20 : 1;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_20_21_ARS_OD_ObstacleProb_Obj_20 : 7;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_20_21_ARS_OD_MicroDopplerFlag_21 : 1;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_20_21_ARS_OD_ObstacleProb_Obj_21 : 7;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_20_21_ARS_OD_ID_20 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_20_21_ARS_OD_ID_21 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_20_21_DistHeight_Obj_20 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_20_21_DistHeight_Obj_21 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_20_21_ARS_OD_MsgCounter_Obj_20_21 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_20_21_ARS_OD_CRC16_Checksum_Obj_20_21_Byte1 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_20_21_ARS_OD_CRC16_Checksum_Obj_20_21_Byte0 : 8;
} RxPdu_CanConfigSet_Rx_Radar_ARS_OD_20_21_BufType;
extern VAR(RxPdu_CanConfigSet_Rx_Radar_ARS_OD_20_21_BufType, COM_VAR_NOINIT) Com_RxPduSignal_CanConfigSet_Rx_Radar_ARS_OD_20_21 ;

typedef struct
{
    uint8 CanConfigSet_Rx_Radar_ARS_OD_22_23_ARS_OD_DistX_Obj_22_Byte1 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_22_23_ARS_OD_VabsX_Obj_22_Byte1 : 4;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_22_23_ARS_OD_DistX_Obj_22_Byte0 : 4;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_22_23_ARS_OD_AabsX_Obj_22_Byte1 : 1;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_22_23_ARS_OD_VabsX_Obj_22_Byte0 : 7;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_22_23_ARS_OD_AabsX_Obj_22_Byte0 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_22_23_ARS_OD_DistY_Obj_22_Byte1 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_22_23_ARS_OD_VabsY_Obj_22_Byte1 : 4;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_22_23_ARS_OD_DistY_Obj_22_Byte0 : 4;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_22_23_ARS_OD_AabsY_Obj_22_Byte1 : 1;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_22_23_ARS_OD_VabsY_Obj_22_Byte0 : 7;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_22_23_ARS_OD_AabsY_Obj_22_Byte0 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_22_23_ARS_OD_DistXStd_Obj_22 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_22_23_ARS_OD_DistYStd_Obj_22 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_22_23_ARS_OD_VabsYStd_Obj_22_Byte1 : 1;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_22_23_ARS_OD_VabsXStd_Obj_22 : 7;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_22_23_ARS_OD_AabsXStd_Obj_22_Byte1 : 2;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_22_23_ARS_OD_VabsYStd_Obj_22_Byte0 : 6;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_22_23_ARS_OD_Classification_Obj_22 : 3;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_22_23_ARS_OD_AabsXStd_Obj_22_Byte0 : 5;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_22_23_ARS_OD_AabsYStd_Obj_22 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_22_23_ARS_OD_ProbOfExist_Obj_22_Byte1 : 1;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_22_23_ARS_OD_ClassConf_Obj_22 : 7;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_22_23_ARS_OD_DynConf_Obj_22_Byte1 : 2;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_22_23_ARS_OD_ProbOfExist_Obj_22_Byte0 : 6;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_22_23_ARS_OD_DynProp_Obj_22 : 3;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_22_23_ARS_OD_DynConf_Obj_22_Byte0 : 5;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_22_23_ARS_OD_Length_Obj_22_Byte1 : 1;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_22_23_ARS_OD_MirrorProb_Obj_22 : 7;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_22_23_ARS_OD_MaintenanceState_Obj_22 : 2;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_22_23_ARS_OD_Length_Obj_22_Byte0 : 6;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_22_23_ARS_OD_RCS_Obj_22_Byte1 : 1;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_22_23_ARS_OD_Width_Obj_22 : 7;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_22_23_ARS_OD_RCS_Obj_22_Byte0 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_22_23_ARS_OD_Orientation_Obj_22_Byte1 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_22_23_ARS_OD_YawRateAbs_Obj_22_Byte1 : 6;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_22_23_ARS_OD_Orientation_Obj_22_Byte0 : 2;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_22_23_ARS_OD_YawRateAbsStd_Obj_22_Byte1 : 4;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_22_23_ARS_OD_YawRateAbs_Obj_22_Byte0 : 4;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_22_23_ARS_OD_RefPoint_Obj_22 : 2;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_22_23_ARS_OD_YawRateAbsStd_Obj_22_Byte0 : 6;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_22_23_ARS_OD_LifeCycle_Obj_22_Byte1 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_22_23_ARS_OD_LifeCycle_Obj_22_Byte0 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_22_23_ARS_OD_DistX_Obj_23_Byte1 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_22_23_ARS_OD_VabsX_Obj_23_Byte1 : 4;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_22_23_ARS_OD_DistX_Obj_23_Byte0 : 4;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_22_23_ARS_OD_AabsX_Obj_23_Byte1 : 1;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_22_23_ARS_OD_VabsX_Obj_23_Byte0 : 7;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_22_23_ARS_OD_AabsX_Obj_23_Byte0 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_22_23_ARS_OD_DistY_Obj_23_Byte1 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_22_23_ARS_OD_VabsY_Obj_23_Byte1 : 4;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_22_23_ARS_OD_DistY_Obj_23_Byte0 : 4;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_22_23_ARS_OD_AabsY_Obj_23_Byte1 : 1;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_22_23_ARS_OD_VabsY_Obj_23_Byte0 : 7;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_22_23_ARS_OD_AabsY_Obj_23_Byte0 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_22_23_ARS_OD_DistXStd_Obj_23 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_22_23_ARS_OD_DistYStd_Obj_23 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_22_23_ARS_OD_VabsYStd_Obj_23_Byte1 : 1;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_22_23_ARS_OD_VabsXStd_Obj_23 : 7;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_22_23_ARS_OD_AabsXStd_Obj_23_Byte1 : 2;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_22_23_ARS_OD_VabsYStd_Obj_23_Byte0 : 6;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_22_23_ARS_OD_Classification_Obj_23 : 3;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_22_23_ARS_OD_AabsXStd_Obj_23_Byte0 : 5;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_22_23_ARS_OD_AabsYStd_Obj_23 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_22_23_ARS_OD_ProbOfExist_Obj_23_Byte1 : 1;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_22_23_ARS_OD_ClassConf_Obj_23 : 7;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_22_23_ARS_OD_DynConf_Obj_23_Byte1 : 2;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_22_23_ARS_OD_ProbOfExist_Obj_23_Byte0 : 6;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_22_23_ARS_OD_DynProp_Obj_23 : 3;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_22_23_ARS_OD_DynConf_Obj_23_Byte0 : 5;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_22_23_ARS_OD_Length_Obj_23_Byte1 : 1;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_22_23_ARS_OD_MirrorProb_Obj_23 : 7;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_22_23_ARS_OD_MaintenanceState_Obj_23 : 2;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_22_23_ARS_OD_Length_Obj_23_Byte0 : 6;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_22_23_ARS_OD_RCS_Obj_23_Byte1 : 1;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_22_23_ARS_OD_Width_Obj_23 : 7;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_22_23_ARS_OD_RCS_Obj_23_Byte0 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_22_23_ARS_OD_Orientation_Obj_23_Byte1 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_22_23_ARS_OD_YawRateAbs_Obj_23_Byte1 : 6;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_22_23_ARS_OD_Orientation_Obj_23_Byte0 : 2;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_22_23_ARS_OD_YawRateAbsStd_Obj_23_Byte1 : 4;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_22_23_ARS_OD_YawRateAbs_Obj_23_Byte0 : 4;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_22_23_ARS_OD_RefPoint_Obj_23 : 2;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_22_23_ARS_OD_YawRateAbsStd_Obj_23_Byte0 : 6;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_22_23_ARS_OD_LifeCycle_Obj_23_Byte1 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_22_23_ARS_OD_LifeCycle_Obj_23_Byte0 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_22_23_ARS_OD_OrientationStd_Obj_23 : 4;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_22_23_ARS_OD_OrientationStd_Obj_22 : 4;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_22_23_ARS_OD_MicroDopplerFlag_22 : 1;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_22_23_ARS_OD_ObstacleProb_Obj_22 : 7;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_22_23_ARS_OD_MicroDopplerFlag_23 : 1;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_22_23_ARS_OD_ObstacleProb_Obj_23 : 7;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_22_23_ARS_OD_ID_22 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_22_23_ARS_OD_ID_23 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_22_23_DistHeight_Obj_22 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_22_23_DistHeight_Obj_23 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_22_23_ARS_OD_MsgCounter_Obj_22_23 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_22_23_ARS_OD_CRC16_Checksum_Obj_22_23_Byte1 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_22_23_ARS_OD_CRC16_Checksum_Obj_22_23_Byte0 : 8;
} RxPdu_CanConfigSet_Rx_Radar_ARS_OD_22_23_BufType;
extern VAR(RxPdu_CanConfigSet_Rx_Radar_ARS_OD_22_23_BufType, COM_VAR_NOINIT) Com_RxPduSignal_CanConfigSet_Rx_Radar_ARS_OD_22_23 ;

typedef struct
{
    uint8 CanConfigSet_Rx_Radar_ARS_OD_24_25_ARS_OD_DistX_Obj_24_Byte1 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_24_25_ARS_OD_VabsX_Obj_24_Byte1 : 4;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_24_25_ARS_OD_DistX_Obj_24_Byte0 : 4;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_24_25_ARS_OD_AabsX_Obj_24_Byte1 : 1;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_24_25_ARS_OD_VabsX_Obj_24_Byte0 : 7;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_24_25_ARS_OD_AabsX_Obj_24_Byte0 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_24_25_ARS_OD_DistY_Obj_24_Byte1 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_24_25_ARS_OD_VabsY_Obj_24_Byte1 : 4;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_24_25_ARS_OD_DistY_Obj_24_Byte0 : 4;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_24_25_ARS_OD_AabsY_Obj_24_Byte1 : 1;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_24_25_ARS_OD_VabsY_Obj_24_Byte0 : 7;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_24_25_ARS_OD_AabsY_Obj_24_Byte0 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_24_25_ARS_OD_DistXStd_Obj_24 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_24_25_ARS_OD_DistYStd_Obj_24 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_24_25_ARS_OD_VabsYStd_Obj_24_Byte1 : 1;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_24_25_ARS_OD_VabsXStd_Obj_24 : 7;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_24_25_ARS_OD_AabsXStd_Obj_24_Byte1 : 2;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_24_25_ARS_OD_VabsYStd_Obj_24_Byte0 : 6;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_24_25_ARS_OD_Classification_Obj_24 : 3;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_24_25_ARS_OD_AabsXStd_Obj_24_Byte0 : 5;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_24_25_ARS_OD_AabsYStd_Obj_24 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_24_25_ARS_OD_ProbOfExist_Obj_24_Byte1 : 1;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_24_25_ARS_OD_ClassConf_Obj_24 : 7;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_24_25_ARS_OD_DynConf_Obj_24_Byte1 : 2;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_24_25_ARS_OD_ProbOfExist_Obj_24_Byte0 : 6;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_24_25_ARS_OD_DynProp_Obj_24 : 3;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_24_25_ARS_OD_DynConf_Obj_24_Byte0 : 5;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_24_25_ARS_OD_Length_Obj_24_Byte1 : 1;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_24_25_ARS_OD_MirrorProb_Obj_24 : 7;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_24_25_ARS_OD_MaintenanceState_Obj_24 : 2;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_24_25_ARS_OD_Length_Obj_24_Byte0 : 6;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_24_25_ARS_OD_RCS_Obj_24_Byte1 : 1;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_24_25_ARS_OD_Width_Obj_24 : 7;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_24_25_ARS_OD_RCS_Obj_24_Byte0 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_24_25_ARS_OD_Orientation_Obj_24_Byte1 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_24_25_ARS_OD_YawRateAbs_Obj_24_Byte1 : 6;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_24_25_ARS_OD_Orientation_Obj_24_Byte0 : 2;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_24_25_ARS_OD_YawRateAbsStd_Obj_24_Byte1 : 4;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_24_25_ARS_OD_YawRateAbs_Obj_24_Byte0 : 4;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_24_25_ARS_OD_RefPoint_Obj_24 : 2;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_24_25_ARS_OD_YawRateAbsStd_Obj_24_Byte0 : 6;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_24_25_ARS_OD_LifeCycle_Obj_24_Byte1 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_24_25_ARS_OD_LifeCycle_Obj_24_Byte0 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_24_25_ARS_OD_DistX_Obj_25_Byte1 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_24_25_ARS_OD_VabsX_Obj_25_Byte1 : 4;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_24_25_ARS_OD_DistX_Obj_25_Byte0 : 4;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_24_25_ARS_OD_AabsX_Obj_25_Byte1 : 1;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_24_25_ARS_OD_VabsX_Obj_25_Byte0 : 7;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_24_25_ARS_OD_AabsX_Obj_25_Byte0 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_24_25_ARS_OD_DistY_Obj_25_Byte1 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_24_25_ARS_OD_VabsY_Obj_25_Byte1 : 4;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_24_25_ARS_OD_DistY_Obj_25_Byte0 : 4;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_24_25_ARS_OD_AabsY_Obj_25_Byte1 : 1;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_24_25_ARS_OD_VabsY_Obj_25_Byte0 : 7;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_24_25_ARS_OD_AabsY_Obj_25_Byte0 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_24_25_ARS_OD_DistXStd_Obj_25 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_24_25_ARS_OD_DistYStd_Obj_25 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_24_25_ARS_OD_VabsYStd_Obj_25_Byte1 : 1;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_24_25_ARS_OD_VabsXStd_Obj_25 : 7;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_24_25_ARS_OD_AabsXStd_Obj_25_Byte1 : 2;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_24_25_ARS_OD_VabsYStd_Obj_25_Byte0 : 6;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_24_25_ARS_OD_Classification_Obj_25 : 3;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_24_25_ARS_OD_AabsXStd_Obj_25_Byte0 : 5;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_24_25_ARS_OD_AabsYStd_Obj_25 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_24_25_ARS_OD_ProbOfExist_Obj_25_Byte1 : 1;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_24_25_ARS_OD_ClassConf_Obj_25 : 7;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_24_25_ARS_OD_DynConf_Obj_25_Byte1 : 2;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_24_25_ARS_OD_ProbOfExist_Obj_25_Byte0 : 6;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_24_25_ARS_OD_DynProp_Obj_25 : 3;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_24_25_ARS_OD_DynConf_Obj_25_Byte0 : 5;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_24_25_ARS_OD_Length_Obj_25_Byte1 : 1;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_24_25_ARS_OD_MirrorProb_Obj_25 : 7;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_24_25_ARS_OD_MaintenanceState_Obj_25 : 2;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_24_25_ARS_OD_Length_Obj_25_Byte0 : 6;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_24_25_ARS_OD_RCS_Obj_25_Byte1 : 1;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_24_25_ARS_OD_Width_Obj_25 : 7;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_24_25_ARS_OD_RCS_Obj_25_Byte0 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_24_25_ARS_OD_Orientation_Obj_25_Byte1 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_24_25_ARS_OD_YawRateAbs_Obj_25_Byte1 : 6;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_24_25_ARS_OD_Orientation_Obj_25_Byte0 : 2;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_24_25_ARS_OD_YawRateAbsStd_Obj_25_Byte1 : 4;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_24_25_ARS_OD_YawRateAbs_Obj_25_Byte0 : 4;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_24_25_ARS_OD_RefPoint_Obj_25 : 2;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_24_25_ARS_OD_YawRateAbsStd_Obj_25_Byte0 : 6;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_24_25_ARS_OD_LifeCycle_Obj_25_Byte1 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_24_25_ARS_OD_LifeCycle_Obj_25_Byte0 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_24_25_ARS_OD_OrientationStd_Obj_25 : 4;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_24_25_ARS_OD_OrientationStd_Obj_24 : 4;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_24_25_ARS_OD_MicroDopplerFlag_24 : 1;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_24_25_ARS_OD_ObstacleProb_Obj_24 : 7;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_24_25_ARS_OD_MicroDopplerFlag_25 : 1;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_24_25_ARS_OD_ObstacleProb_Obj_25 : 7;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_24_25_ARS_OD_ID_24 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_24_25_ARS_OD_ID_25 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_24_25_DistHeight_Obj_24 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_24_25_DistHeight_Obj_25 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_24_25_ARS_OD_MsgCounter_Obj_24_25 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_24_25_ARS_OD_CRC16_Checksum_Obj_24_25_Byte1 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_24_25_ARS_OD_CRC16_Checksum_Obj_24_25_Byte0 : 8;
} RxPdu_CanConfigSet_Rx_Radar_ARS_OD_24_25_BufType;
extern VAR(RxPdu_CanConfigSet_Rx_Radar_ARS_OD_24_25_BufType, COM_VAR_NOINIT) Com_RxPduSignal_CanConfigSet_Rx_Radar_ARS_OD_24_25 ;

typedef struct
{
    uint8 CanConfigSet_Rx_Radar_ARS_OD_26_27_ARS_OD_DistX_Obj_26_Byte1 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_26_27_ARS_OD_VabsX_Obj_26_Byte1 : 4;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_26_27_ARS_OD_DistX_Obj_26_Byte0 : 4;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_26_27_ARS_OD_AabsX_Obj_26_Byte1 : 1;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_26_27_ARS_OD_VabsX_Obj_26_Byte0 : 7;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_26_27_ARS_OD_AabsX_Obj_26_Byte0 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_26_27_ARS_OD_DistY_Obj_26_Byte1 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_26_27_ARS_OD_VabsY_Obj_26_Byte1 : 4;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_26_27_ARS_OD_DistY_Obj_26_Byte0 : 4;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_26_27_ARS_OD_AabsY_Obj_26_Byte1 : 1;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_26_27_ARS_OD_VabsY_Obj_26_Byte0 : 7;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_26_27_ARS_OD_AabsY_Obj_26_Byte0 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_26_27_ARS_OD_DistXStd_Obj_26 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_26_27_ARS_OD_DistYStd_Obj_26 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_26_27_ARS_OD_VabsYStd_Obj_26_Byte1 : 1;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_26_27_ARS_OD_VabsXStd_Obj_26 : 7;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_26_27_ARS_OD_AabsXStd_Obj_26_Byte1 : 2;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_26_27_ARS_OD_VabsYStd_Obj_26_Byte0 : 6;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_26_27_ARS_OD_Classification_Obj_26 : 3;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_26_27_ARS_OD_AabsXStd_Obj_26_Byte0 : 5;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_26_27_ARS_OD_AabsYStd_Obj_26 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_26_27_ARS_OD_ProbOfExist_Obj_26_Byte1 : 1;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_26_27_ARS_OD_ClassConf_Obj_26 : 7;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_26_27_ARS_OD_DynConf_Obj_26_Byte1 : 2;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_26_27_ARS_OD_ProbOfExist_Obj_26_Byte0 : 6;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_26_27_ARS_OD_DynProp_Obj_26 : 3;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_26_27_ARS_OD_DynConf_Obj_26_Byte0 : 5;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_26_27_ARS_OD_Length_Obj_26_Byte1 : 1;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_26_27_ARS_OD_MirrorProb_Obj_26 : 7;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_26_27_ARS_OD_MaintenanceState_Obj_26 : 2;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_26_27_ARS_OD_Length_Obj_26_Byte0 : 6;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_26_27_ARS_OD_RCS_Obj_26_Byte1 : 1;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_26_27_ARS_OD_Width_Obj_26 : 7;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_26_27_ARS_OD_RCS_Obj_26_Byte0 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_26_27_ARS_OD_Orientation_Obj_26_Byte1 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_26_27_ARS_OD_YawRateAbs_Obj_26_Byte1 : 6;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_26_27_ARS_OD_Orientation_Obj_26_Byte0 : 2;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_26_27_ARS_OD_YawRateAbsStd_Obj_26_Byte1 : 4;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_26_27_ARS_OD_YawRateAbs_Obj_26_Byte0 : 4;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_26_27_ARS_OD_RefPoint_Obj_26 : 2;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_26_27_ARS_OD_YawRateAbsStd_Obj_26_Byte0 : 6;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_26_27_ARS_OD_LifeCycle_Obj_26_Byte1 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_26_27_ARS_OD_LifeCycle_Obj_26_Byte0 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_26_27_ARS_OD_DistX_Obj_27_Byte1 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_26_27_ARS_OD_VabsX_Obj_27_Byte1 : 4;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_26_27_ARS_OD_DistX_Obj_27_Byte0 : 4;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_26_27_ARS_OD_AabsX_Obj_27_Byte1 : 1;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_26_27_ARS_OD_VabsX_Obj_27_Byte0 : 7;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_26_27_ARS_OD_AabsX_Obj_27_Byte0 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_26_27_ARS_OD_DistY_Obj_27_Byte1 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_26_27_ARS_OD_VabsY_Obj_27_Byte1 : 4;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_26_27_ARS_OD_DistY_Obj_27_Byte0 : 4;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_26_27_ARS_OD_AabsY_Obj_27_Byte1 : 1;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_26_27_ARS_OD_VabsY_Obj_27_Byte0 : 7;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_26_27_ARS_OD_AabsY_Obj_27_Byte0 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_26_27_ARS_OD_DistXStd_Obj_27 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_26_27_ARS_OD_DistYStd_Obj_27 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_26_27_ARS_OD_VabsYStd_Obj_27_Byte1 : 1;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_26_27_ARS_OD_VabsXStd_Obj_27 : 7;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_26_27_ARS_OD_AabsXStd_Obj_27_Byte1 : 2;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_26_27_ARS_OD_VabsYStd_Obj_27_Byte0 : 6;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_26_27_ARS_OD_Classification_Obj_27 : 3;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_26_27_ARS_OD_AabsXStd_Obj_27_Byte0 : 5;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_26_27_ARS_OD_AabsYStd_Obj_27 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_26_27_ARS_OD_ProbOfExist_Obj_27_Byte1 : 1;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_26_27_ARS_OD_ClassConf_Obj_27 : 7;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_26_27_ARS_OD_DynConf_Obj_27_Byte1 : 2;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_26_27_ARS_OD_ProbOfExist_Obj_27_Byte0 : 6;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_26_27_ARS_OD_DynProp_Obj_27 : 3;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_26_27_ARS_OD_DynConf_Obj_27_Byte0 : 5;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_26_27_ARS_OD_Length_Obj_27_Byte1 : 1;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_26_27_ARS_OD_MirrorProb_Obj_27 : 7;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_26_27_ARS_OD_MaintenanceState_Obj_27 : 2;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_26_27_ARS_OD_Length_Obj_27_Byte0 : 6;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_26_27_ARS_OD_RCS_Obj_27_Byte1 : 1;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_26_27_ARS_OD_Width_Obj_27 : 7;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_26_27_ARS_OD_RCS_Obj_27_Byte0 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_26_27_ARS_OD_Orientation_Obj_27_Byte1 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_26_27_ARS_OD_YawRateAbs_Obj_27_Byte1 : 6;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_26_27_ARS_OD_Orientation_Obj_27_Byte0 : 2;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_26_27_ARS_OD_YawRateAbsStd_Obj_27_Byte1 : 4;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_26_27_ARS_OD_YawRateAbs_Obj_27_Byte0 : 4;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_26_27_ARS_OD_RefPoint_Obj_27 : 2;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_26_27_ARS_OD_YawRateAbsStd_Obj_27_Byte0 : 6;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_26_27_ARS_OD_LifeCycle_Obj_27_Byte1 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_26_27_ARS_OD_LifeCycle_Obj_27_Byte0 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_26_27_ARS_OD_OrientationStd_Obj_27 : 4;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_26_27_ARS_OD_OrientationStd_Obj_26 : 4;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_26_27_ARS_OD_MicroDopplerFlag_26 : 1;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_26_27_ARS_OD_ObstacleProb_Obj_26 : 7;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_26_27_ARS_OD_MicroDopplerFlag_27 : 1;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_26_27_ARS_OD_ObstacleProb_Obj_27 : 7;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_26_27_ARS_OD_ID_26 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_26_27_ARS_OD_ID_27 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_26_27_DistHeight_Obj_26 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_26_27_DistHeight_Obj_27 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_26_27_ARS_OD_MsgCounter_Obj_26_27 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_26_27_ARS_OD_CRC16_Checksum_Obj_26_27_Byte1 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_26_27_ARS_OD_CRC16_Checksum_Obj_26_27_Byte0 : 8;
} RxPdu_CanConfigSet_Rx_Radar_ARS_OD_26_27_BufType;
extern VAR(RxPdu_CanConfigSet_Rx_Radar_ARS_OD_26_27_BufType, COM_VAR_NOINIT) Com_RxPduSignal_CanConfigSet_Rx_Radar_ARS_OD_26_27 ;

typedef struct
{
    uint8 CanConfigSet_Rx_Radar_ARS_OD_28_29_ARS_OD_DistX_Obj_28_Byte1 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_28_29_ARS_OD_VabsX_Obj_28_Byte1 : 4;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_28_29_ARS_OD_DistX_Obj_28_Byte0 : 4;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_28_29_ARS_OD_AabsX_Obj_28_Byte1 : 1;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_28_29_ARS_OD_VabsX_Obj_28_Byte0 : 7;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_28_29_ARS_OD_AabsX_Obj_28_Byte0 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_28_29_ARS_OD_DistY_Obj_28_Byte1 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_28_29_ARS_OD_VabsY_Obj_28_Byte1 : 4;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_28_29_ARS_OD_DistY_Obj_28_Byte0 : 4;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_28_29_ARS_OD_AabsY_Obj_28_Byte1 : 1;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_28_29_ARS_OD_VabsY_Obj_28_Byte0 : 7;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_28_29_ARS_OD_AabsY_Obj_28_Byte0 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_28_29_ARS_OD_DistXStd_Obj_28 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_28_29_ARS_OD_DistYStd_Obj_28 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_28_29_ARS_OD_VabsYStd_Obj_28_Byte1 : 1;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_28_29_ARS_OD_VabsXStd_Obj_28 : 7;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_28_29_ARS_OD_AabsXStd_Obj_28_Byte1 : 2;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_28_29_ARS_OD_VabsYStd_Obj_28_Byte0 : 6;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_28_29_ARS_OD_Classification_Obj_28 : 3;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_28_29_ARS_OD_AabsXStd_Obj_28_Byte0 : 5;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_28_29_ARS_OD_AabsYStd_Obj_28 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_28_29_ARS_OD_ProbOfExist_Obj_28_Byte1 : 1;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_28_29_ARS_OD_ClassConf_Obj_28 : 7;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_28_29_ARS_OD_DynConf_Obj_28_Byte1 : 2;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_28_29_ARS_OD_ProbOfExist_Obj_28_Byte0 : 6;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_28_29_ARS_OD_DynProp_Obj_28 : 3;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_28_29_ARS_OD_DynConf_Obj_28_Byte0 : 5;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_28_29_ARS_OD_Length_Obj_28_Byte1 : 1;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_28_29_ARS_OD_MirrorProb_Obj_28 : 7;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_28_29_ARS_OD_MaintenanceState_Obj_28 : 2;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_28_29_ARS_OD_Length_Obj_28_Byte0 : 6;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_28_29_ARS_OD_RCS_Obj_28_Byte1 : 1;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_28_29_ARS_OD_Width_Obj_28 : 7;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_28_29_ARS_OD_RCS_Obj_28_Byte0 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_28_29_ARS_OD_Orientation_Obj_28_Byte1 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_28_29_ARS_OD_YawRateAbs_Obj_28_Byte1 : 6;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_28_29_ARS_OD_Orientation_Obj_28_Byte0 : 2;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_28_29_ARS_OD_YawRateAbsStd_Obj_28_Byte1 : 4;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_28_29_ARS_OD_YawRateAbs_Obj_28_Byte0 : 4;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_28_29_ARS_OD_RefPoint_Obj_28 : 2;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_28_29_ARS_OD_YawRateAbsStd_Obj_28_Byte0 : 6;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_28_29_ARS_OD_LifeCycle_Obj_28_Byte1 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_28_29_ARS_OD_LifeCycle_Obj_28_Byte0 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_28_29_ARS_OD_DistX_Obj_29_Byte1 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_28_29_ARS_OD_VabsX_Obj_29_Byte1 : 4;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_28_29_ARS_OD_DistX_Obj_29_Byte0 : 4;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_28_29_ARS_OD_AabsX_Obj_29_Byte1 : 1;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_28_29_ARS_OD_VabsX_Obj_29_Byte0 : 7;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_28_29_ARS_OD_AabsX_Obj_29_Byte0 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_28_29_ARS_OD_DistY_Obj_29_Byte1 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_28_29_ARS_OD_VabsY_Obj_29_Byte1 : 4;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_28_29_ARS_OD_DistY_Obj_29_Byte0 : 4;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_28_29_ARS_OD_AabsY_Obj_29_Byte1 : 1;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_28_29_ARS_OD_VabsY_Obj_29_Byte0 : 7;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_28_29_ARS_OD_AabsY_Obj_29_Byte0 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_28_29_ARS_OD_DistXStd_Obj_29 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_28_29_ARS_OD_DistYStd_Obj_29 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_28_29_ARS_OD_VabsYStd_Obj_29_Byte1 : 1;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_28_29_ARS_OD_VabsXStd_Obj_29 : 7;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_28_29_ARS_OD_AabsXStd_Obj_29_Byte1 : 2;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_28_29_ARS_OD_VabsYStd_Obj_29_Byte0 : 6;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_28_29_ARS_OD_Classification_Obj_29 : 3;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_28_29_ARS_OD_AabsXStd_Obj_29_Byte0 : 5;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_28_29_ARS_OD_AabsYStd_Obj_29 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_28_29_ARS_OD_ProbOfExist_Obj_29_Byte1 : 1;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_28_29_ARS_OD_ClassConf_Obj_29 : 7;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_28_29_ARS_OD_DynConf_Obj_29_Byte1 : 2;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_28_29_ARS_OD_ProbOfExist_Obj_29_Byte0 : 6;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_28_29_ARS_OD_DynProp_Obj_29 : 3;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_28_29_ARS_OD_DynConf_Obj_29_Byte0 : 5;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_28_29_ARS_OD_Length_Obj_29_Byte1 : 1;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_28_29_ARS_OD_MirrorProb_Obj_29 : 7;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_28_29_ARS_OD_MaintenanceState_Obj_29 : 2;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_28_29_ARS_OD_Length_Obj_29_Byte0 : 6;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_28_29_ARS_OD_RCS_Obj_29_Byte1 : 1;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_28_29_ARS_OD_Width_Obj_29 : 7;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_28_29_ARS_OD_RCS_Obj_29_Byte0 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_28_29_ARS_OD_Orientation_Obj_29_Byte1 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_28_29_ARS_OD_YawRateAbs_Obj_29_Byte1 : 6;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_28_29_ARS_OD_Orientation_Obj_29_Byte0 : 2;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_28_29_ARS_OD_YawRateAbsStd_Obj_29_Byte1 : 4;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_28_29_ARS_OD_YawRateAbs_Obj_29_Byte0 : 4;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_28_29_ARS_OD_RefPoint_Obj_29 : 2;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_28_29_ARS_OD_YawRateAbsStd_Obj_29_Byte0 : 6;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_28_29_ARS_OD_LifeCycle_Obj_29_Byte1 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_28_29_ARS_OD_LifeCycle_Obj_29_Byte0 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_28_29_ARS_OD_OrientationStd_Obj_29 : 4;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_28_29_ARS_OD_OrientationStd_Obj_28 : 4;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_28_29_ARS_OD_MicroDopplerFlag_28 : 1;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_28_29_ARS_OD_ObstacleProb_Obj_28 : 7;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_28_29_ARS_OD_MicroDopplerFlag_29 : 1;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_28_29_ARS_OD_ObstacleProb_Obj_29 : 7;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_28_29_ARS_OD_ID_28 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_28_29_ARS_OD_ID_29 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_28_29_DistHeight_Obj_28 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_28_29_DistHeight_Obj_29 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_28_29_ARS_OD_MsgCounter_Obj_28_29 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_28_29_ARS_OD_CRC16_Checksum_Obj_28_29_Byte1 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_28_29_ARS_OD_CRC16_Checksum_Obj_28_29_Byte0 : 8;
} RxPdu_CanConfigSet_Rx_Radar_ARS_OD_28_29_BufType;
extern VAR(RxPdu_CanConfigSet_Rx_Radar_ARS_OD_28_29_BufType, COM_VAR_NOINIT) Com_RxPduSignal_CanConfigSet_Rx_Radar_ARS_OD_28_29 ;

typedef struct
{
    uint8 CanConfigSet_Rx_Radar_ARS_OD_30_31_ARS_OD_DistX_Obj_30_Byte1 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_30_31_ARS_OD_VabsX_Obj_30_Byte1 : 4;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_30_31_ARS_OD_DistX_Obj_30_Byte0 : 4;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_30_31_ARS_OD_AabsX_Obj_30_Byte1 : 1;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_30_31_ARS_OD_VabsX_Obj_30_Byte0 : 7;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_30_31_ARS_OD_AabsX_Obj_30_Byte0 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_30_31_ARS_OD_DistY_Obj_30_Byte1 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_30_31_ARS_OD_VabsY_Obj_30_Byte1 : 4;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_30_31_ARS_OD_DistY_Obj_30_Byte0 : 4;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_30_31_ARS_OD_AabsY_Obj_30_Byte1 : 1;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_30_31_ARS_OD_VabsY_Obj_30_Byte0 : 7;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_30_31_ARS_OD_AabsY_Obj_30_Byte0 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_30_31_ARS_OD_DistXStd_Obj_30 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_30_31_ARS_OD_DistYStd_Obj_30 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_30_31_ARS_OD_VabsYStd_Obj_30_Byte1 : 1;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_30_31_ARS_OD_VabsXStd_Obj_30 : 7;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_30_31_ARS_OD_AabsXStd_Obj_30_Byte1 : 2;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_30_31_ARS_OD_VabsYStd_Obj_30_Byte0 : 6;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_30_31_ARS_OD_Classification_Obj_30 : 3;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_30_31_ARS_OD_AabsXStd_Obj_30_Byte0 : 5;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_30_31_ARS_OD_AabsYStd_Obj_30 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_30_31_ARS_OD_ProbOfExist_Obj_30_Byte1 : 1;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_30_31_ARS_OD_ClassConf_Obj_30 : 7;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_30_31_ARS_OD_DynConf_Obj_30_Byte1 : 2;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_30_31_ARS_OD_ProbOfExist_Obj_30_Byte0 : 6;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_30_31_ARS_OD_DynProp_Obj_30 : 3;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_30_31_ARS_OD_DynConf_Obj_30_Byte0 : 5;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_30_31_ARS_OD_Length_Obj_30_Byte1 : 1;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_30_31_ARS_OD_MirrorProb_Obj_30 : 7;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_30_31_ARS_OD_MaintenanceState_Obj_30 : 2;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_30_31_ARS_OD_Length_Obj_30_Byte0 : 6;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_30_31_ARS_OD_RCS_Obj_30_Byte1 : 1;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_30_31_ARS_OD_Width_Obj_30 : 7;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_30_31_ARS_OD_RCS_Obj_30_Byte0 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_30_31_ARS_OD_Orientation_Obj_30_Byte1 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_30_31_ARS_OD_YawRateAbs_Obj_30_Byte1 : 6;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_30_31_ARS_OD_Orientation_Obj_30_Byte0 : 2;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_30_31_ARS_OD_YawRateAbsStd_Obj_30_Byte1 : 4;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_30_31_ARS_OD_YawRateAbs_Obj_30_Byte0 : 4;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_30_31_ARS_OD_RefPoint_Obj_30 : 2;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_30_31_ARS_OD_YawRateAbsStd_Obj_30_Byte0 : 6;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_30_31_ARS_OD_LifeCycle_Obj_30_Byte1 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_30_31_ARS_OD_LifeCycle_Obj_30_Byte0 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_30_31_ARS_OD_DistX_Obj_31_Byte1 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_30_31_ARS_OD_VabsX_Obj_31_Byte1 : 4;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_30_31_ARS_OD_DistX_Obj_31_Byte0 : 4;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_30_31_ARS_OD_AabsX_Obj_31_Byte1 : 1;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_30_31_ARS_OD_VabsX_Obj_31_Byte0 : 7;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_30_31_ARS_OD_AabsX_Obj_31_Byte0 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_30_31_ARS_OD_DistY_Obj_31_Byte1 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_30_31_ARS_OD_VabsY_Obj_31_Byte1 : 4;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_30_31_ARS_OD_DistY_Obj_31_Byte0 : 4;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_30_31_ARS_OD_AabsY_Obj_31_Byte1 : 1;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_30_31_ARS_OD_VabsY_Obj_31_Byte0 : 7;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_30_31_ARS_OD_AabsY_Obj_31_Byte0 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_30_31_ARS_OD_DistXStd_Obj_31 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_30_31_ARS_OD_DistYStd_Obj_31 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_30_31_ARS_OD_VabsYStd_Obj_31_Byte1 : 1;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_30_31_ARS_OD_VabsXStd_Obj_31 : 7;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_30_31_ARS_OD_AabsXStd_Obj_31_Byte1 : 2;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_30_31_ARS_OD_VabsYStd_Obj_31_Byte0 : 6;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_30_31_ARS_OD_Classification_Obj_31 : 3;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_30_31_ARS_OD_AabsXStd_Obj_31_Byte0 : 5;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_30_31_ARS_OD_AabsYStd_Obj_31 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_30_31_ARS_OD_ProbOfExist_Obj_31_Byte1 : 1;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_30_31_ARS_OD_ClassConf_Obj_31 : 7;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_30_31_ARS_OD_DynConf_Obj_31_Byte1 : 2;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_30_31_ARS_OD_ProbOfExist_Obj_31_Byte0 : 6;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_30_31_ARS_OD_DynProp_Obj_31 : 3;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_30_31_ARS_OD_DynConf_Obj_31_Byte0 : 5;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_30_31_ARS_OD_Length_Obj_31_Byte1 : 1;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_30_31_ARS_OD_MirrorProb_Obj_31 : 7;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_30_31_ARS_OD_MaintenanceState_Obj_31 : 2;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_30_31_ARS_OD_Length_Obj_31_Byte0 : 6;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_30_31_ARS_OD_RCS_Obj_31_Byte1 : 1;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_30_31_ARS_OD_Width_Obj_31 : 7;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_30_31_ARS_OD_RCS_Obj_31_Byte0 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_30_31_ARS_OD_Orientation_Obj_31_Byte1 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_30_31_ARS_OD_YawRateAbs_Obj_31_Byte1 : 6;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_30_31_ARS_OD_Orientation_Obj_31_Byte0 : 2;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_30_31_ARS_OD_YawRateAbsStd_Obj_31_Byte1 : 4;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_30_31_ARS_OD_YawRateAbs_Obj_31_Byte0 : 4;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_30_31_ARS_OD_RefPoint_Obj_31 : 2;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_30_31_ARS_OD_YawRateAbsStd_Obj_31_Byte0 : 6;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_30_31_ARS_OD_LifeCycle_Obj_31_Byte1 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_30_31_ARS_OD_LifeCycle_Obj_31_Byte0 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_30_31_ARS_OD_OrientationStd_Obj_31 : 4;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_30_31_ARS_OD_OrientationStd_Obj_30 : 4;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_30_31_ARS_OD_MicroDopplerFlag_30 : 1;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_30_31_ARS_OD_ObstacleProb_Obj_30 : 7;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_30_31_ARS_OD_MicroDopplerFlag_31 : 1;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_30_31_ARS_OD_ObstacleProb_Obj_31 : 7;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_30_31_ARS_OD_ID_30 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_30_31_ARS_OD_ID_31 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_30_31_DistHeight_Obj_30 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_30_31_DistHeight_Obj_31 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_30_31_ARS_OD_MsgCounter_Obj_30_31 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_30_31_ARS_OD_CRC16_Checksum_Obj_30_31_Byte1 : 8;
    uint8 CanConfigSet_Rx_Radar_ARS_OD_30_31_ARS_OD_CRC16_Checksum_Obj_30_31_Byte0 : 8;
} RxPdu_CanConfigSet_Rx_Radar_ARS_OD_30_31_BufType;
extern VAR(RxPdu_CanConfigSet_Rx_Radar_ARS_OD_30_31_BufType, COM_VAR_NOINIT) Com_RxPduSignal_CanConfigSet_Rx_Radar_ARS_OD_30_31 ;

typedef struct
{
    uint8 Tcp_ReceiveSignal_1601[1017];
} RxPdu_Tcp_Receive_Pdu_1601_BufType;
extern VAR(RxPdu_Tcp_Receive_Pdu_1601_BufType, COM_VAR_NOINIT) Com_RxPduSignal_Tcp_Receive_Pdu_1601 ;

typedef struct
{
    uint8 Tcp_ReceiveSignal_1602[10643];
} RxPdu_Tcp_Receive_Pdu_1602_BufType;
extern VAR(RxPdu_Tcp_Receive_Pdu_1602_BufType, COM_VAR_NOINIT) Com_RxPduSignal_Tcp_Receive_Pdu_1602 ;

typedef struct
{
    uint8 Tcp_ReceiveSignal_1603[4857];
} RxPdu_Tcp_Receive_Pdu_1603_BufType;
extern VAR(RxPdu_Tcp_Receive_Pdu_1603_BufType, COM_VAR_NOINIT) Com_RxPduSignal_Tcp_Receive_Pdu_1603 ;

typedef struct
{
    uint8 Tcp_ReceiveSignal_1604[84];
} RxPdu_Tcp_Receive_Pdu_1604_BufType;
extern VAR(RxPdu_Tcp_Receive_Pdu_1604_BufType, COM_VAR_NOINIT) Com_RxPduSignal_Tcp_Receive_Pdu_1604 ;

typedef struct
{
    uint8 Tcp_ReceiveSignal_1605[6788];
} RxPdu_Tcp_Receive_Pdu_1605_BufType;
extern VAR(RxPdu_Tcp_Receive_Pdu_1605_BufType, COM_VAR_NOINIT) Com_RxPduSignal_Tcp_Receive_Pdu_1605 ;

typedef struct
{
    uint8 Tcp_ReceiveSignal_1606[713];
} RxPdu_Tcp_Receive_Pdu_1606_BufType;
extern VAR(RxPdu_Tcp_Receive_Pdu_1606_BufType, COM_VAR_NOINIT) Com_RxPduSignal_Tcp_Receive_Pdu_1606 ;

typedef struct
{
    uint8 Tcp_ReceiveSignal_1607[4248];
} RxPdu_Tcp_Receive_Pdu_1607_BufType;
extern VAR(RxPdu_Tcp_Receive_Pdu_1607_BufType, COM_VAR_NOINIT) Com_RxPduSignal_Tcp_Receive_Pdu_1607 ;

typedef struct
{
    uint8 Tcp_ReceiveSignal_1608[406];
} RxPdu_Tcp_Receive_Pdu_1608_BufType;
extern VAR(RxPdu_Tcp_Receive_Pdu_1608_BufType, COM_VAR_NOINIT) Com_RxPduSignal_Tcp_Receive_Pdu_1608 ;


/*******************************************************************************
*   Config Parameters
*******************************************************************************/

#define COM_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "MemMap.h"

extern CONST(Com_CfgTxPduTableType, COM_CONST)              ComTxPduCfgTable[];
extern CONST(Com_CfgTxSigTableType, COM_CONST)              ComTxSigCfgTable[];

extern CONST(Com_CfgRxPduTableType, COM_CONST)              ComRxPduCfgTable[];
extern CONST(Com_CfgRxSigTableType, COM_CONST)              ComRxSigCfgTable[];

extern CONST(Com_CfgPduGroupTableType, COM_CONST)           ComPduGroupCfgTable[];

extern CONST(Com_CfgSigGroupType, COM_CONST)                ComCfgRxSignalGroup[];
#define COM_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "MemMap.h"

/*******************************************************************************
*   Access macro
*******************************************************************************/



/*CanConfigSet*/

#define Com_CbkRxAck_CanConfigSet_Rx_ACAN_ACU_ChimeTelltaleReq_ACU_CoDSeatOccupSensorStat Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_ACU_ChimeTelltaleReq_ACU_CoDSeatOccupSensorStat
#define Com_CbkRxAck_CanConfigSet_Rx_ACAN_ACU_ChimeTelltaleReq_ACU_DSeatOccupSensorStat   Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_ACU_ChimeTelltaleReq_ACU_DSeatOccupSensorStat
#define Com_CbkRxAck_CanConfigSet_Rx_ACAN_ACU_ChimeTelltaleReq_ACU_CoDSeatbeltBucklestatus          Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_ACU_ChimeTelltaleReq_ACU_CoDSeatbeltBucklestatus
#define Com_CbkRxAck_CanConfigSet_Rx_ACAN_ACU_ChimeTelltaleReq_ACU_DSeatbeltBucklestatus  Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_ACU_ChimeTelltaleReq_ACU_DSeatbeltBucklestatus
#define Com_CbkRxAck_CanConfigSet_Rx_ACAN_ACU_ChimeTelltaleReq_ACU_CoDAirbagStatus        Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_ACU_ChimeTelltaleReq_ACU_CoDAirbagStatus
#define Com_CbkRxAck_CanConfigSet_Rx_ACAN_ACU_ChimeTelltaleReq_ACU_DAirbagStatus          Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_ACU_ChimeTelltaleReq_ACU_DAirbagStatus
#define Com_CbkRxAck_CanConfigSet_Rx_ACAN_ACU_ChimeTelltaleReq_ACU_RPSeatOccupSensorStat  Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_ACU_ChimeTelltaleReq_ACU_RPSeatOccupSensorStat
#define Com_CbkRxAck_CanConfigSet_Rx_ACAN_ACU_ChimeTelltaleReq_ACU_MPSeatOccupSensorStat  Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_ACU_ChimeTelltaleReq_ACU_MPSeatOccupSensorStat
#define Com_CbkRxAck_CanConfigSet_Rx_ACAN_ACU_ChimeTelltaleReq_ACU_LPSeatOccupSensorStat  Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_ACU_ChimeTelltaleReq_ACU_LPSeatOccupSensorStat
#define Com_CbkRxAck_CanConfigSet_Rx_ACAN_ACU_ChimeTelltaleReq_ACU_RCABsts      Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_ACU_ChimeTelltaleReq_ACU_RCABsts
#define Com_CbkRxAck_CanConfigSet_Rx_ACAN_ACU_ChimeTelltaleReq_ACU_LCABsts      Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_ACU_ChimeTelltaleReq_ACU_LCABsts
#define Com_CbkRxAck_CanConfigSet_Rx_ACAN_ACU_ChimeTelltaleReq_ACU_RSABsts      Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_ACU_ChimeTelltaleReq_ACU_RSABsts
#define Com_CbkRxAck_CanConfigSet_Rx_ACAN_ACU_ChimeTelltaleReq_ACU_LSABsts      Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_ACU_ChimeTelltaleReq_ACU_LSABsts
#define Com_CbkRxAck_CanConfigSet_Rx_ACAN_ACU_ChimeTelltaleReq_ACU_RPSeatbeltBucklestatus Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_ACU_ChimeTelltaleReq_ACU_RPSeatbeltBucklestatus
#define Com_CbkRxAck_CanConfigSet_Rx_ACAN_ACU_ChimeTelltaleReq_ACU_MPSeatbeltBucklestatus Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_ACU_ChimeTelltaleReq_ACU_MPSeatbeltBucklestatus
#define Com_CbkRxAck_CanConfigSet_Rx_ACAN_ACU_ChimeTelltaleReq_ACU_LPSeatbeltBucklestatus Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_ACU_ChimeTelltaleReq_ACU_LPSeatbeltBucklestatus
#define Com_CbkRxAck_CanConfigSet_Rx_ACAN_ACU_ChimeTelltaleReq_ACU_CrashSts     Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_ACU_ChimeTelltaleReq_ACU_CrashSts
#define Com_CbkRxAck_CanConfigSet_Rx_ACAN_ACU_ChimeTelltaleReq_ACU_CrashRearOutputSts     Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_ACU_ChimeTelltaleReq_ACU_CrashRearOutputSts
#define Com_CbkRxAck_CanConfigSet_Rx_ACAN_ACU_ChimeTelltaleReq_ACU_CrashRightOutputSts    Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_ACU_ChimeTelltaleReq_ACU_CrashRightOutputSts
#define Com_CbkRxAck_CanConfigSet_Rx_ACAN_ACU_ChimeTelltaleReq_ACU_CrashLeftOutputSts     Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_ACU_ChimeTelltaleReq_ACU_CrashLeftOutputSts
#define Com_CbkRxAck_CanConfigSet_Rx_ACAN_ACU_ChimeTelltaleReq_ACU_CrashFrontOutputSts    Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_ACU_ChimeTelltaleReq_ACU_CrashFrontOutputSts
#define Com_CbkRxAck_CanConfigSet_Rx_ACAN_ACU_ChimeTelltaleReq_ACU_AirbagWarningStatus    Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_ACU_ChimeTelltaleReq_ACU_AirbagWarningStatus
#define Com_CbkRxAck_CanConfigSet_Rx_ACAN_ACU_ChimeTelltaleReq_ACU_CoDSeatbletPTighten    Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_ACU_ChimeTelltaleReq_ACU_CoDSeatbletPTighten
#define Com_CbkRxAck_CanConfigSet_Rx_ACAN_ACU_ChimeTelltaleReq_ACU_DSeatbletPTighten      Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_ACU_ChimeTelltaleReq_ACU_DSeatbletPTighten
#define Com_CbkRxAck_CanConfigSet_Rx_ACAN_ACU_ChimeTelltaleReq_ACU_AliveCounter Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_ACU_ChimeTelltaleReq_ACU_AliveCounter
#define Com_CbkRxAck_CanConfigSet_Rx_ACAN_ACU_ChimeTelltaleReq_ACU_CheckSum     Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_ACU_ChimeTelltaleReq_ACU_CheckSum
#define Com_CbkRxAck_CanConfigSet_Rx_ACAN_BCM_LIGHT_0x106_CheckSum_0x106        Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_BCM_LIGHT_0x106_CheckSum_0x106
#define Com_CbkRxAck_CanConfigSet_Rx_ACAN_BCM_LIGHT_0x106_RollingCounter_0x106  Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_BCM_LIGHT_0x106_RollingCounter_0x106
#define Com_CbkRxAck_CanConfigSet_Rx_ACAN_BCM_LIGHT_0x106_BCM_TurnIndicatorSts  Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_BCM_LIGHT_0x106_BCM_TurnIndicatorSts
#define Com_CbkRxAck_CanConfigSet_Rx_ACAN_BCM_LIGHT_0x106_BCM_PosLmpSts         Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_BCM_LIGHT_0x106_BCM_PosLmpSts
#define Com_CbkRxAck_CanConfigSet_Rx_ACAN_BCM_LIGHT_0x106_BCM_LowBeamSts        Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_BCM_LIGHT_0x106_BCM_LowBeamSts
#define Com_CbkRxAck_CanConfigSet_Rx_ACAN_BCM_LIGHT_0x106_BCM_HighBeamSts       Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_BCM_LIGHT_0x106_BCM_HighBeamSts
#define Com_CbkRxAck_CanConfigSet_Rx_ACAN_BCM_LIGHT_0x106_BCM_RearFogLampLightSts         Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_BCM_LIGHT_0x106_BCM_RearFogLampLightSts
#define Com_CbkRxAck_CanConfigSet_Rx_ACAN_BCM_LIGHT_0x106_BCM_BrakeLightSts     Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_BCM_LIGHT_0x106_BCM_BrakeLightSts
#define Com_CbkRxAck_CanConfigSet_Rx_ACAN_BCM_LIGHT_0x106_BCM_ReverseLightSts   Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_BCM_LIGHT_0x106_BCM_ReverseLightSts
#define Com_CbkRxAck_CanConfigSet_Rx_ACAN_BCM_LIGHT_0x106_BCM_DayRunningLampSts Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_BCM_LIGHT_0x106_BCM_DayRunningLampSts
#define Com_CbkRxAck_CanConfigSet_Rx_ACAN_BCM_LIGHT_0x106_BCM_RMarkerLightSts   Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_BCM_LIGHT_0x106_BCM_RMarkerLightSts
#define Com_CbkRxAck_CanConfigSet_Rx_ACAN_BCM_LIGHT_0x106_BCM_Rr_domelampSts    Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_BCM_LIGHT_0x106_BCM_Rr_domelampSts
#define Com_CbkRxAck_CanConfigSet_Rx_ACAN_BCM_LIGHT_0x106_BCM_Fr_domelampSts    Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_BCM_LIGHT_0x106_BCM_Fr_domelampSts
#define Com_CbkRxAck_CanConfigSet_Rx_ACAN_BCM_LIGHT_0x106_BCM_LicensePlateLightSts        Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_BCM_LIGHT_0x106_BCM_LicensePlateLightSts
#define Com_CbkRxAck_CanConfigSet_Rx_ACAN_BCM_LIGHT_0x106_BCM_HeadLight_adjustSts         Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_BCM_LIGHT_0x106_BCM_HeadLight_adjustSts
#define Com_CbkRxAck_CanConfigSet_Rx_ACAN_BCM_LIGHT_0x106_BCM_FrontFogLampLightSts        Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_BCM_LIGHT_0x106_BCM_FrontFogLampLightSts
#define Com_CbkRxAck_CanConfigSet_Rx_ACAN_BCM_LIGHT_0x106_BCM_STAT_InteriorLight          Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_BCM_LIGHT_0x106_BCM_STAT_InteriorLight
#define Com_CbkRxAck_CanConfigSet_Rx_ACAN_BCM_LIGHT_0x106_BCM_STAT_SwLightBrightness      Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_BCM_LIGHT_0x106_BCM_STAT_SwLightBrightness
#define Com_CbkRxAck_CanConfigSet_Rx_ACAN_BCM_LIGHT_0x106_BCM_TurnLight_FaultSts          Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_BCM_LIGHT_0x106_BCM_TurnLight_FaultSts
#define Com_CbkRxAck_CanConfigSet_Rx_ACAN_BCM_LIGHT_0x106_BCM_AmbeLightZone2Sts Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_BCM_LIGHT_0x106_BCM_AmbeLightZone2Sts
#define Com_CbkRxAck_CanConfigSet_Rx_ACAN_BCM_LIGHT_0x106_BCM_AmbeLightZone1Sts Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_BCM_LIGHT_0x106_BCM_AmbeLightZone1Sts
#define Com_CbkRxAck_CanConfigSet_Rx_ACAN_BCM_SwitchSts_0x109_CheckSum_0x109    Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_BCM_SwitchSts_0x109_CheckSum_0x109
#define Com_CbkRxAck_CanConfigSet_Rx_ACAN_BCM_SwitchSts_0x109_RollingCounter_0x109        Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_BCM_SwitchSts_0x109_RollingCounter_0x109
#define Com_CbkRxAck_CanConfigSet_Rx_ACAN_BCM_SwitchSts_0x109_BCM_STAT_Horn     Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_BCM_SwitchSts_0x109_BCM_STAT_Horn
#define Com_CbkRxAck_CanConfigSet_Rx_ACAN_BCM_SwitchSts_0x109_BCM_STAT_HazardWarn         Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_BCM_SwitchSts_0x109_BCM_STAT_HazardWarn
#define Com_CbkRxAck_CanConfigSet_Rx_ACAN_BCM_SwitchSts_0x109_BCM_LowBeamSWSts  Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_BCM_SwitchSts_0x109_BCM_LowBeamSWSts
#define Com_CbkRxAck_CanConfigSet_Rx_ACAN_BCM_SwitchSts_0x109_BCM_TurnLightSWSts          Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_BCM_SwitchSts_0x109_BCM_TurnLightSWSts
#define Com_CbkRxAck_CanConfigSet_Rx_ACAN_BCM_SwitchSts_0x109_BCM_Tail_MicroSW  Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_BCM_SwitchSts_0x109_BCM_Tail_MicroSW
#define Com_CbkRxAck_CanConfigSet_Rx_ACAN_BCM_SwitchSts_0x109_STAT_Central_LockSts        Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_BCM_SwitchSts_0x109_STAT_Central_LockSts
#define Com_CbkRxAck_CanConfigSet_Rx_ACAN_BCM_SwitchSts_0x109_BCM_RFogLampSWSts Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_BCM_SwitchSts_0x109_BCM_RFogLampSWSts
#define Com_CbkRxAck_CanConfigSet_Rx_ACAN_BCM_SwitchSts_0x109_BCM_FFogLampSWSts Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_BCM_SwitchSts_0x109_BCM_FFogLampSWSts
#define Com_CbkRxAck_CanConfigSet_Rx_ACAN_BCM_SwitchSts_0x109_BCM_HighBeamSWSts Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_BCM_SwitchSts_0x109_BCM_HighBeamSWSts
#define Com_CbkRxAck_CanConfigSet_Rx_ACAN_ABS_FrontWheelSpeMCUKPH_ABS_FLWheelSpeedInvalid Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_ABS_FrontWheelSpeMCUKPH_ABS_FLWheelSpeedInvalid
#define Com_CbkRxAck_CanConfigSet_Rx_ACAN_ABS_FrontWheelSpeMCUKPH_ABS_FLWheelSpeedKPH     Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_ABS_FrontWheelSpeMCUKPH_ABS_FLWheelSpeedKPH
#define Com_CbkRxAck_CanConfigSet_Rx_ACAN_ABS_FrontWheelSpeMCUKPH_ABS_FRWheelSpeedInvalid Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_ABS_FrontWheelSpeMCUKPH_ABS_FRWheelSpeedInvalid
#define Com_CbkRxAck_CanConfigSet_Rx_ACAN_ABS_FrontWheelSpeMCUKPH_ABS_FRWheelSpeedKPH     Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_ABS_FrontWheelSpeMCUKPH_ABS_FRWheelSpeedKPH
#define Com_CbkRxAck_CanConfigSet_Rx_ACAN_ABS_FrontWheelSpeMCUKPH_ABS_FRWheelDirection    Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_ABS_FrontWheelSpeMCUKPH_ABS_FRWheelDirection
#define Com_CbkRxAck_CanConfigSet_Rx_ACAN_ABS_FrontWheelSpeMCUKPH_ABS_FLWheelDirection    Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_ABS_FrontWheelSpeMCUKPH_ABS_FLWheelDirection
#define Com_CbkRxAck_CanConfigSet_Rx_ACAN_ABS_FrontWheelSpeMCUKPH_ABS_FWSpeMCUKPH_AliveCounter      Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_ABS_FrontWheelSpeMCUKPH_ABS_FWSpeMCUKPH_AliveCounter
#define Com_CbkRxAck_CanConfigSet_Rx_ACAN_ABS_FrontWheelSpeMCUKPH_ABS_FWSpeMCUKPH_CheckSum          Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_ABS_FrontWheelSpeMCUKPH_ABS_FWSpeMCUKPH_CheckSum
#define Com_CbkRxAck_CanConfigSet_Rx_ACAN_ABS_RearWheelSpeMCUKPH_ABS_RLWheelSpeedInvalid  Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_ABS_RearWheelSpeMCUKPH_ABS_RLWheelSpeedInvalid
#define Com_CbkRxAck_CanConfigSet_Rx_ACAN_ABS_RearWheelSpeMCUKPH_ABS_RLWheelSpeedKPH      Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_ABS_RearWheelSpeMCUKPH_ABS_RLWheelSpeedKPH
#define Com_CbkRxAck_CanConfigSet_Rx_ACAN_ABS_RearWheelSpeMCUKPH_ABS_RRWheelSpeedInvalid  Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_ABS_RearWheelSpeMCUKPH_ABS_RRWheelSpeedInvalid
#define Com_CbkRxAck_CanConfigSet_Rx_ACAN_ABS_RearWheelSpeMCUKPH_ABS_RRWheelSpeedKPH      Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_ABS_RearWheelSpeMCUKPH_ABS_RRWheelSpeedKPH
#define Com_CbkRxAck_CanConfigSet_Rx_ACAN_ABS_RearWheelSpeMCUKPH_ABS_RRWheelDirection     Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_ABS_RearWheelSpeMCUKPH_ABS_RRWheelDirection
#define Com_CbkRxAck_CanConfigSet_Rx_ACAN_ABS_RearWheelSpeMCUKPH_ABS_RLWheelDirection     Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_ABS_RearWheelSpeMCUKPH_ABS_RLWheelDirection
#define Com_CbkRxAck_CanConfigSet_Rx_ACAN_ABS_RearWheelSpeMCUKPH_ABS_RWSpeMCUKPH_AliveCounter       Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_ABS_RearWheelSpeMCUKPH_ABS_RWSpeMCUKPH_AliveCounter
#define Com_CbkRxAck_CanConfigSet_Rx_ACAN_ABS_RearWheelSpeMCUKPH_ABS_RWSpeMCUKPH_CheckSum Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_ABS_RearWheelSpeMCUKPH_ABS_RWSpeMCUKPH_CheckSum
#define Com_CbkRxAck_CanConfigSet_Rx_ACAN_ABS_WheelSpeedRC_ABS_FLWheelSpeedRC   Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_ABS_WheelSpeedRC_ABS_FLWheelSpeedRC
#define Com_CbkRxAck_CanConfigSet_Rx_ACAN_ABS_WheelSpeedRC_ABS_FRWheelSpeedRC   Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_ABS_WheelSpeedRC_ABS_FRWheelSpeedRC
#define Com_CbkRxAck_CanConfigSet_Rx_ACAN_ABS_WheelSpeedRC_ABS_RLWheelSpeedRC   Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_ABS_WheelSpeedRC_ABS_RLWheelSpeedRC
#define Com_CbkRxAck_CanConfigSet_Rx_ACAN_ABS_WheelSpeedRC_ABS_RRWheelSpeedRC   Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_ABS_WheelSpeedRC_ABS_RRWheelSpeedRC
#define Com_CbkRxAck_CanConfigSet_Rx_ACAN_ABS_WheelSpeedRC_ABS_FLWheelSpeedRCSts          Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_ABS_WheelSpeedRC_ABS_FLWheelSpeedRCSts
#define Com_CbkRxAck_CanConfigSet_Rx_ACAN_ABS_WheelSpeedRC_ABS_FRWheelSpeedRCSts          Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_ABS_WheelSpeedRC_ABS_FRWheelSpeedRCSts
#define Com_CbkRxAck_CanConfigSet_Rx_ACAN_ABS_WheelSpeedRC_ABS_RLWheelSpeedRCSts          Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_ABS_WheelSpeedRC_ABS_RLWheelSpeedRCSts
#define Com_CbkRxAck_CanConfigSet_Rx_ACAN_ABS_WheelSpeedRC_ABS_RRWheelSpeedRCSts          Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_ABS_WheelSpeedRC_ABS_RRWheelSpeedRCSts
#define Com_CbkRxAck_CanConfigSet_Rx_ACAN_ABS_WheelSpeedRC_ABS_WheelSpeMCURC_AliveCounter Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_ABS_WheelSpeedRC_ABS_WheelSpeMCURC_AliveCounter
#define Com_CbkRxAck_CanConfigSet_Rx_ACAN_ABS_WheelSpeedRC_ABS_WheelSpeMCURC_CheckSum     Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_ABS_WheelSpeedRC_ABS_WheelSpeMCURC_CheckSum
#define Com_CbkRxAck_CanConfigSet_Rx_ACAN_ABS_Status_ABSActive        Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_ABS_Status_ABSActive
#define Com_CbkRxAck_CanConfigSet_Rx_ACAN_ABS_Status_ABS_EBDFailed    Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_ABS_Status_ABS_EBDFailed
#define Com_CbkRxAck_CanConfigSet_Rx_ACAN_ABS_Status_ABSFailed        Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_ABS_Status_ABSFailed
#define Com_CbkRxAck_CanConfigSet_Rx_ACAN_ABS_Status_ABS_LowBrakeFluid          Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_ABS_Status_ABS_LowBrakeFluid
#define Com_CbkRxAck_CanConfigSet_Rx_ACAN_ABS_Status_ABS_VehicleSpeedInvalid    Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_ABS_Status_ABS_VehicleSpeedInvalid
#define Com_CbkRxAck_CanConfigSet_Rx_ACAN_ABS_Status_ABS_VehicleSpeed Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_ABS_Status_ABS_VehicleSpeed
#define Com_CbkRxAck_CanConfigSet_Rx_ACAN_ABS_Status_ABS_Status_AliveCounter    Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_ABS_Status_ABS_Status_AliveCounter
#define Com_CbkRxAck_CanConfigSet_Rx_ACAN_ABS_Status_ABS_HAZActive    Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_ABS_Status_ABS_HAZActive
#define Com_CbkRxAck_CanConfigSet_Rx_ACAN_ABS_Status_ABS_Status_CheckSum        Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_ABS_Status_ABS_Status_CheckSum
#define Com_CbkRxAck_CanConfigSet_Rx_ACAN_ESC_Status_0x132_Checksum_0x132       Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_ESC_Status_0x132_Checksum_0x132
#define Com_CbkRxAck_CanConfigSet_Rx_ACAN_ESC_Status_0x132_RollingCounter_0x132 Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_ESC_Status_0x132_RollingCounter_0x132
#define Com_CbkRxAck_CanConfigSet_Rx_ACAN_ESC_Status_0x132_ESC_SlopeGradeAngle  Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_ESC_Status_0x132_ESC_SlopeGradeAngle
#define Com_CbkRxAck_CanConfigSet_Rx_ACAN_ESC_Status_0x132_ESC_MasterCylinderPressureV    Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_ESC_Status_0x132_ESC_MasterCylinderPressureV
#define Com_CbkRxAck_CanConfigSet_Rx_ACAN_ESC_Status_0x132_ESC_MasterCylinderPressure     Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_ESC_Status_0x132_ESC_MasterCylinderPressure
#define Com_CbkRxAck_CanConfigSet_Rx_ACAN_ESC_Status_0x132_ESC_HSA_Control_Status         Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_ESC_Status_0x132_ESC_HSA_Control_Status
#define Com_CbkRxAck_CanConfigSet_Rx_ACAN_ESC_Status_0x132_ESC_HSA_Status_Fault Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_ESC_Status_0x132_ESC_HSA_Status_Fault
#define Com_CbkRxAck_CanConfigSet_Rx_ACAN_ESC_Status_0x132_ESC_TcsDisableSts    Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_ESC_Status_0x132_ESC_TcsDisableSts
#define Com_CbkRxAck_CanConfigSet_Rx_ACAN_ESC_Status_0x132_ESC_EscCtrlActv      Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_ESC_Status_0x132_ESC_EscCtrlActv
#define Com_CbkRxAck_CanConfigSet_Rx_ACAN_ESC_Status_0x132_ESC_TcsCtrlActv      Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_ESC_Status_0x132_ESC_TcsCtrlActv
#define Com_CbkRxAck_CanConfigSet_Rx_ACAN_ESC_Status_0x132_ESC_EscFlgFlt        Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_ESC_Status_0x132_ESC_EscFlgFlt
#define Com_CbkRxAck_CanConfigSet_Rx_ACAN_ESC_Status_0x132_ESC_TcsFlgFlt        Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_ESC_Status_0x132_ESC_TcsFlgFlt
#define Com_CbkRxAck_CanConfigSet_Rx_ACAN_ESC_Status_0x132_ESC_EscDisableSts    Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_ESC_Status_0x132_ESC_EscDisableSts
#define Com_CbkRxAck_CanConfigSet_Rx_ACAN_ESC_Status_0x132_ESC_HBAFlgFlt        Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_ESC_Status_0x132_ESC_HBAFlgFlt
#define Com_CbkRxAck_CanConfigSet_Rx_ACAN_ESC_Status_0x132_ESC_HbaCtrlActv      Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_ESC_Status_0x132_ESC_HbaCtrlActv
#define Com_CbkRxAck_CanConfigSet_Rx_ACAN_ESC_Status_0x132_BAS_FlgFlt Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_ESC_Status_0x132_BAS_FlgFlt
#define Com_CbkRxAck_CanConfigSet_Rx_ACAN_ESC_Status_0x132_BAS_CtrlActv         Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_ESC_Status_0x132_BAS_CtrlActv
#define Com_CbkRxAck_CanConfigSet_Rx_ACAN_ESC_Status_0x132_IBS_ESCOFF_StsFB     Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_ESC_Status_0x132_IBS_ESCOFF_StsFB
#define Com_CbkRxAck_CanConfigSet_Rx_ACAN_VCU_Ctrl_VCU_ModeGearSts    Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_VCU_Ctrl_VCU_ModeGearSts
#define Com_CbkRxAck_CanConfigSet_Rx_ACAN_VCU_Ctrl_VCU_P_Sts          Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_VCU_Ctrl_VCU_P_Sts
#define Com_CbkRxAck_CanConfigSet_Rx_ACAN_VCU_Ctrl_VCU_Warning_IMMO_Fail        Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_VCU_Ctrl_VCU_Warning_IMMO_Fail
#define Com_CbkRxAck_CanConfigSet_Rx_ACAN_VCU_Ctrl_VCU_Ready          Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_VCU_Ctrl_VCU_Ready
#define Com_CbkRxAck_CanConfigSet_Rx_ACAN_VCU_Ctrl_VCU_RegencyLevInd  Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_VCU_Ctrl_VCU_RegencyLevInd
#define Com_CbkRxAck_CanConfigSet_Rx_ACAN_VCU_Ctrl_VCU_Ctrl_AliveCounter        Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_VCU_Ctrl_VCU_Ctrl_AliveCounter
#define Com_CbkRxAck_CanConfigSet_Rx_ACAN_VCU_Ctrl_VCU_LimpHomeSts    Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_VCU_Ctrl_VCU_LimpHomeSts
#define Com_CbkRxAck_CanConfigSet_Rx_ACAN_VCU_Ctrl_VCU_Ctrl_CheckSum  Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_VCU_Ctrl_VCU_Ctrl_CheckSum
#define Com_CbkRxAck_CanConfigSet_Rx_ACAN_VCU_StsEpt_VCU_StsAccPedalFault       Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_VCU_StsEpt_VCU_StsAccPedalFault
#define Com_CbkRxAck_CanConfigSet_Rx_ACAN_VCU_StsEpt_VCU_StsSysFault  Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_VCU_StsEpt_VCU_StsSysFault
#define Com_CbkRxAck_CanConfigSet_Rx_ACAN_VCU_StsEpt_VCU_AccPedalPosition       Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_VCU_StsEpt_VCU_AccPedalPosition
#define Com_CbkRxAck_CanConfigSet_Rx_ACAN_VCU_StsEpt_VCU_AccPedal_Valid         Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_VCU_StsEpt_VCU_AccPedal_Valid
#define Com_CbkRxAck_CanConfigSet_Rx_ACAN_VCU_StsEpt_VCU_StsEpt_AliveCounter    Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_VCU_StsEpt_VCU_StsEpt_AliveCounter
#define Com_CbkRxAck_CanConfigSet_Rx_ACAN_VCU_StsEpt_VCU_StsEpt_CheckSum        Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_VCU_StsEpt_VCU_StsEpt_CheckSum
#define Com_CbkRxAck_CanConfigSet_Rx_ACAN_SAS_Sensor_0x17E_Checksum_0x17E       Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_SAS_Sensor_0x17E_Checksum_0x17E
#define Com_CbkRxAck_CanConfigSet_Rx_ACAN_SAS_Sensor_0x17E_Rolling_counter_0x17E          Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_SAS_Sensor_0x17E_Rolling_counter_0x17E
#define Com_CbkRxAck_CanConfigSet_Rx_ACAN_SAS_Sensor_0x17E_SAS_SASStsSnsr       Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_SAS_Sensor_0x17E_SAS_SASStsSnsr
#define Com_CbkRxAck_CanConfigSet_Rx_ACAN_SAS_Sensor_0x17E_SAS_SteeringAngleValid         Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_SAS_Sensor_0x17E_SAS_SteeringAngleValid
#define Com_CbkRxAck_CanConfigSet_Rx_ACAN_SAS_Sensor_0x17E_SAS_SteerWhlRotSpd   Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_SAS_Sensor_0x17E_SAS_SteerWhlRotSpd
#define Com_CbkRxAck_CanConfigSet_Rx_ACAN_SAS_Sensor_0x17E_SAS_SASFailure       Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_SAS_Sensor_0x17E_SAS_SASFailure
#define Com_CbkRxAck_CanConfigSet_Rx_ACAN_SAS_Sensor_0x17E_SAS_Calibrated       Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_SAS_Sensor_0x17E_SAS_Calibrated
#define Com_CbkRxAck_CanConfigSet_Rx_ACAN_SAS_Sensor_0x17E_SAS_SteerWhlRotSpdStatus       Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_SAS_Sensor_0x17E_SAS_SteerWhlRotSpdStatus
#define Com_CbkRxAck_CanConfigSet_Rx_ACAN_SAS_Sensor_0x17E_SAS_SteerWheelAngle  Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_SAS_Sensor_0x17E_SAS_SteerWheelAngle
#define Com_CbkRxAck_CanConfigSet_Rx_ACAN_EPS_LKA_Sts_CheckSum_0x17F  Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_EPS_LKA_Sts_CheckSum_0x17F
#define Com_CbkRxAck_CanConfigSet_Rx_ACAN_EPS_LKA_Sts_EPS_APA_CtrlAbortFeedback Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_EPS_LKA_Sts_EPS_APA_CtrlAbortFeedback
#define Com_CbkRxAck_CanConfigSet_Rx_ACAN_EPS_LKA_Sts_RollingCounter_0x17F      Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_EPS_LKA_Sts_RollingCounter_0x17F
#define Com_CbkRxAck_CanConfigSet_Rx_ACAN_EPS_LKA_Sts_EPS_SterMod     Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_EPS_LKA_Sts_EPS_SterMod
#define Com_CbkRxAck_CanConfigSet_Rx_ACAN_EPS_LKA_Sts_EPS_SterModV    Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_EPS_LKA_Sts_EPS_SterModV
#define Com_CbkRxAck_CanConfigSet_Rx_ACAN_EPS_LKA_Sts_EPS_LKARespTorq Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_EPS_LKA_Sts_EPS_LKARespTorq
#define Com_CbkRxAck_CanConfigSet_Rx_ACAN_EPS_LKA_Sts_EPS_ADAS_CtrlAbortFeedback          Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_EPS_LKA_Sts_EPS_ADAS_CtrlAbortFeedback
#define Com_CbkRxAck_CanConfigSet_Rx_ACAN_EPS_LKA_Sts_EPS_SterFltMod  Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_EPS_LKA_Sts_EPS_SterFltMod
#define Com_CbkRxAck_CanConfigSet_Rx_ACAN_EPS_LKA_Sts_EPS_DrStrTorqV  Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_EPS_LKA_Sts_EPS_DrStrTorqV
#define Com_CbkRxAck_CanConfigSet_Rx_ACAN_EPS_LKA_Sts_EPS_APA_ModAvail          Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_EPS_LKA_Sts_EPS_APA_ModAvail
#define Com_CbkRxAck_CanConfigSet_Rx_ACAN_EPS_LKA_Sts_EPS_APA_ModActv Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_EPS_LKA_Sts_EPS_APA_ModActv
#define Com_CbkRxAck_CanConfigSet_Rx_ACAN_EPS_LKA_Sts_EPS_ADAS_ModActv          Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_EPS_LKA_Sts_EPS_ADAS_ModActv
#define Com_CbkRxAck_CanConfigSet_Rx_ACAN_EPS_LKA_Sts_EPS_ADAS_ModAvail         Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_EPS_LKA_Sts_EPS_ADAS_ModAvail
#define Com_CbkRxAck_CanConfigSet_Rx_ACAN_EPS_LKA_Sts_EPS_DrStrTorqVal          Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_EPS_LKA_Sts_EPS_DrStrTorqVal
#define Com_CbkRxAck_CanConfigSet_Rx_ACAN_BCM_PEPS_Sts_PEPS_PowerModeValidity   Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_BCM_PEPS_Sts_PEPS_PowerModeValidity
#define Com_CbkRxAck_CanConfigSet_Rx_ACAN_BCM_PEPS_Sts_PEPS_PowerMode Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_BCM_PEPS_Sts_PEPS_PowerMode
#define Com_CbkRxAck_CanConfigSet_Rx_ACAN_BCM_PEPS_Sts_PEPS_IGN1RelayValidity   Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_BCM_PEPS_Sts_PEPS_IGN1RelayValidity
#define Com_CbkRxAck_CanConfigSet_Rx_ACAN_BCM_PEPS_Sts_PEPS_IGN1RelaySts        Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_BCM_PEPS_Sts_PEPS_IGN1RelaySts
#define Com_CbkRxAck_CanConfigSet_Rx_ACAN_BCM_PEPS_Sts_PEPS_Learning_Status     Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_BCM_PEPS_Sts_PEPS_Learning_Status
#define Com_CbkRxAck_CanConfigSet_Rx_ACAN_BCM_PEPS_Sts_BCM_WPC_Off_Req          Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_BCM_PEPS_Sts_BCM_WPC_Off_Req
#define Com_CbkRxAck_CanConfigSet_Rx_ACAN_BCM_PEPS_Sts_PEPS_Message_Sts_AliveCounter      Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_BCM_PEPS_Sts_PEPS_Message_Sts_AliveCounter
#define Com_CbkRxAck_CanConfigSet_Rx_ACAN_BCM_PEPS_Sts_PEPS_Message_Sts_CheckSum          Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_BCM_PEPS_Sts_PEPS_Message_Sts_CheckSum
#define Com_CbkRxAck_CanConfigSet_Rx_ACAN_MHU_ADSA01_MHU_APA_Req      Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_MHU_ADSA01_MHU_APA_Req
#define Com_CbkRxAck_CanConfigSet_Rx_ACAN_MHU_ADSA01_MHU_APA_ParkIn_Req         Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_MHU_ADSA01_MHU_APA_ParkIn_Req
#define Com_CbkRxAck_CanConfigSet_Rx_ACAN_MHU_ADSA01_MHU_APA_ParkOut_Req        Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_MHU_ADSA01_MHU_APA_ParkOut_Req
#define Com_CbkRxAck_CanConfigSet_Rx_ACAN_MHU_ADSA01_MHU_APA_ParkingStart_Req   Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_MHU_ADSA01_MHU_APA_ParkingStart_Req
#define Com_CbkRxAck_CanConfigSet_Rx_ACAN_MHU_ADSA01_MHU_APA_ParkingReCover_Req Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_MHU_ADSA01_MHU_APA_ParkingReCover_Req
#define Com_CbkRxAck_CanConfigSet_Rx_ACAN_MHU_ADSA01_MHU_APA_ParkOut_Direction  Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_MHU_ADSA01_MHU_APA_ParkOut_Direction
#define Com_CbkRxAck_CanConfigSet_Rx_ACAN_MHU_ADSA01_MHU_APA_ParkOut_Mode       Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_MHU_ADSA01_MHU_APA_ParkOut_Mode
#define Com_CbkRxAck_CanConfigSet_Rx_ACAN_MHU_ADSA01_MHU_LSS_Req      Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_MHU_ADSA01_MHU_LSS_Req
#define Com_CbkRxAck_CanConfigSet_Rx_ACAN_MHU_ADSA01_MHU_LSS_Mode     Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_MHU_ADSA01_MHU_LSS_Mode
#define Com_CbkRxAck_CanConfigSet_Rx_ACAN_MHU_ADSA01_MHU_LSS_WarningMethod      Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_MHU_ADSA01_MHU_LSS_WarningMethod
#define Com_CbkRxAck_CanConfigSet_Rx_ACAN_MHU_ADSA01_MHU_TSR_Req      Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_MHU_ADSA01_MHU_TSR_Req
#define Com_CbkRxAck_CanConfigSet_Rx_ACAN_MHU_ADSA01_TSR_SpdWarningOffs_S       Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_MHU_ADSA01_TSR_SpdWarningOffs_S
#define Com_CbkRxAck_CanConfigSet_Rx_ACAN_MHU_ADSA01_TSR_SLWFuncSwtReq          Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_MHU_ADSA01_TSR_SLWFuncSwtReq
#define Com_CbkRxAck_CanConfigSet_Rx_ACAN_MHU_ADSA01_AEB_FuncSwtReq   Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_MHU_ADSA01_AEB_FuncSwtReq
#define Com_CbkRxAck_CanConfigSet_Rx_ACAN_MHU_ADSA01_AEB_FCW_SnvtyReq Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_MHU_ADSA01_AEB_FCW_SnvtyReq
#define Com_CbkRxAck_CanConfigSet_Rx_ACAN_MHU_ADSA01_BSD_LCA_FuncSWReq          Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_MHU_ADSA01_BSD_LCA_FuncSWReq
#define Com_CbkRxAck_CanConfigSet_Rx_ACAN_MHU_ADSA01_RCTA_FuncSWReq   Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_MHU_ADSA01_RCTA_FuncSWReq
#define Com_CbkRxAck_CanConfigSet_Rx_ACAN_MHU_ADSA01_DOW_FuncSWReq    Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_MHU_ADSA01_DOW_FuncSWReq
#define Com_CbkRxAck_CanConfigSet_Rx_ACAN_MHU_ADSA01_RCW_FuncSWReq    Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_MHU_ADSA01_RCW_FuncSWReq
#define Com_CbkRxAck_CanConfigSet_Rx_ACAN_MHU_ADSA01_MHU_APA_ParkingSpace_ID    Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_MHU_ADSA01_MHU_APA_ParkingSpace_ID
#define Com_CbkRxAck_CanConfigSet_Rx_ACAN_MHU_ADAS02_Nav_errorSts     Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_MHU_ADAS02_Nav_errorSts
#define Com_CbkRxAck_CanConfigSet_Rx_ACAN_MHU_ADAS02_Nav_RoadType     Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_MHU_ADAS02_Nav_RoadType
#define Com_CbkRxAck_CanConfigSet_Rx_ACAN_MHU_ADAS02_Nav_VehToTrafEyeDist       Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_MHU_ADAS02_Nav_VehToTrafEyeDist
#define Com_CbkRxAck_CanConfigSet_Rx_ACAN_MHU_ADAS02_Nav_SpdLimValue  Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_MHU_ADAS02_Nav_SpdLimValue
#define Com_CbkRxAck_CanConfigSet_Rx_ACAN_MHU_ADAS02_Nav_SpdLimType   Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_MHU_ADAS02_Nav_SpdLimType
#define Com_CbkRxAck_CanConfigSet_Rx_ACAN_MHU_ADAS02_Nav_SpdLimUnit   Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_MHU_ADAS02_Nav_SpdLimUnit
#define Com_CbkRxAck_CanConfigSet_Rx_ACAN_MHU_ADAS02_Nav_TSRTrafSign  Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_MHU_ADAS02_Nav_TSRTrafSign
#define Com_CbkRxAck_CanConfigSet_Rx_ACAN_MHU_ADAS02_Nav_CtryType     Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_MHU_ADAS02_Nav_CtryType
#define Com_CbkRxAck_CanConfigSet_Rx_ACAN_MHU_ADAS03_Nav_TimeMod      Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_MHU_ADAS03_Nav_TimeMod
#define Com_CbkRxAck_CanConfigSet_Rx_ACAN_MHU_ADAS03_Nav_TimeIndcn    Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_MHU_ADAS03_Nav_TimeIndcn
#define Com_CbkRxAck_CanConfigSet_Rx_ACAN_BCM_WindowSts_BCM_FLWin_Postion       Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_BCM_WindowSts_BCM_FLWin_Postion
#define Com_CbkRxAck_CanConfigSet_Rx_ACAN_BCM_WindowSts_BCM_FRWin_Postion       Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_BCM_WindowSts_BCM_FRWin_Postion
#define Com_CbkRxAck_CanConfigSet_Rx_ACAN_BCM_WindowSts_BCM_RLWinIN_Postion     Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_BCM_WindowSts_BCM_RLWinIN_Postion
#define Com_CbkRxAck_CanConfigSet_Rx_ACAN_BCM_WindowSts_BCM_RRWin_Postion       Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_BCM_WindowSts_BCM_RRWin_Postion
#define Com_CbkRxAck_CanConfigSet_Rx_ACAN_BCM_WindowSts_BCM_WinLockSts          Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_BCM_WindowSts_BCM_WinLockSts
#define Com_CbkRxAck_CanConfigSet_Rx_ACAN_BCM_WindowSts_BCM_RLWinAntipinchSts   Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_BCM_WindowSts_BCM_RLWinAntipinchSts
#define Com_CbkRxAck_CanConfigSet_Rx_ACAN_BCM_WindowSts_BCM_RRWinAntipinchSts   Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_BCM_WindowSts_BCM_RRWinAntipinchSts
#define Com_CbkRxAck_CanConfigSet_Rx_ACAN_BCM_WindowSts_BCM_FLWinAntipinchSts   Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_BCM_WindowSts_BCM_FLWinAntipinchSts
#define Com_CbkRxAck_CanConfigSet_Rx_ACAN_BCM_WindowSts_BCM_FRWinAntipinchSts   Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_BCM_WindowSts_BCM_FRWinAntipinchSts
#define Com_CbkRxAck_CanConfigSet_Rx_ACAN_BCM_WindowSts_BCM_FrontWipeSWSts      Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_BCM_WindowSts_BCM_FrontWipeSWSts
#define Com_CbkRxAck_CanConfigSet_Rx_ACAN_BCM_WindowSts_BCM_AutoWipeSts         Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_BCM_WindowSts_BCM_AutoWipeSts
#define Com_CbkRxAck_CanConfigSet_Rx_ACAN_BCM_WindowSts_BCM_FrontWipeSts        Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_BCM_WindowSts_BCM_FrontWipeSts
#define Com_CbkRxAck_CanConfigSet_Rx_ACAN_BCM_WindowSts_BCM_FrontWipeReturn     Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_BCM_WindowSts_BCM_FrontWipeReturn
#define Com_CbkRxAck_CanConfigSet_Rx_ACAN_BCM_WindowSts_BCM_FrontWinWashSWSts   Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_BCM_WindowSts_BCM_FrontWinWashSWSts
#define Com_CbkRxAck_CanConfigSet_Rx_ACAN_BCM_WindowSts_BCM_RearWipeSWSts       Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_BCM_WindowSts_BCM_RearWipeSWSts
#define Com_CbkRxAck_CanConfigSet_Rx_ACAN_BCM_WindowSts_BCM_RearWipeSts         Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_BCM_WindowSts_BCM_RearWipeSts
#define Com_CbkRxAck_CanConfigSet_Rx_ACAN_BCM_WindowSts_BCM_RearWipeReturn      Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_BCM_WindowSts_BCM_RearWipeReturn
#define Com_CbkRxAck_CanConfigSet_Rx_ACAN_BCM_WindowSts_BCM_RearWinWashSWSts    Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_BCM_WindowSts_BCM_RearWinWashSWSts
#define Com_CbkRxAck_CanConfigSet_Rx_ACAN_ESC_EPB_0x230_Checksum_230  Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_ESC_EPB_0x230_Checksum_230
#define Com_CbkRxAck_CanConfigSet_Rx_ACAN_ESC_EPB_0x230_RollingCounter_230      Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_ESC_EPB_0x230_RollingCounter_230
#define Com_CbkRxAck_CanConfigSet_Rx_ACAN_ESC_EPB_0x230_EPB_SysBrkLtsReq        Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_ESC_EPB_0x230_EPB_SysBrkLtsReq
#define Com_CbkRxAck_CanConfigSet_Rx_ACAN_ESC_EPB_0x230_EPB_SysDspMsgReqV       Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_ESC_EPB_0x230_EPB_SysDspMsgReqV
#define Com_CbkRxAck_CanConfigSet_Rx_ACAN_ESC_EPB_0x230_EPB_SysStatIndReqV      Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_ESC_EPB_0x230_EPB_SysStatIndReqV
#define Com_CbkRxAck_CanConfigSet_Rx_ACAN_ESC_EPB_0x230_EPB_SysWrnIndReqV       Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_ESC_EPB_0x230_EPB_SysWrnIndReqV
#define Com_CbkRxAck_CanConfigSet_Rx_ACAN_ESC_EPB_0x230_EPB_SysWrnIndReq        Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_ESC_EPB_0x230_EPB_SysWrnIndReq
#define Com_CbkRxAck_CanConfigSet_Rx_ACAN_ESC_EPB_0x230_EPB_SysStatIndReq       Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_ESC_EPB_0x230_EPB_SysStatIndReq
#define Com_CbkRxAck_CanConfigSet_Rx_ACAN_ESC_EPB_0x230_EPB_SysDspMsgReq        Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_ESC_EPB_0x230_EPB_SysDspMsgReq
#define Com_CbkRxAck_CanConfigSet_Rx_ACAN_ESC_EPB_0x230_EPB_AVHWrnIndReq        Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_ESC_EPB_0x230_EPB_AVHWrnIndReq
#define Com_CbkRxAck_CanConfigSet_Rx_ACAN_ESC_EPB_0x230_EPB_AVHWrnIndReqV       Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_ESC_EPB_0x230_EPB_AVHWrnIndReqV
#define Com_CbkRxAck_CanConfigSet_Rx_ACAN_ESC_EPB_0x230_EPB_AVHStatIndReq       Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_ESC_EPB_0x230_EPB_AVHStatIndReq
#define Com_CbkRxAck_CanConfigSet_Rx_ACAN_ESC_EPB_0x230_EPB_AVHStatIndReqV      Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_ESC_EPB_0x230_EPB_AVHStatIndReqV
#define Com_CbkRxAck_CanConfigSet_Rx_ACAN_ESC_EPB_0x230_EPB_AVHFeedbackSts      Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_ESC_EPB_0x230_EPB_AVHFeedbackSts
#define Com_CbkRxAck_CanConfigSet_Rx_ACAN_ESC_EPB_0x230_EPB_Sts       Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_ESC_EPB_0x230_EPB_Sts
#define Com_CbkRxAck_CanConfigSet_Rx_ACAN_ESC_EPB_0x230_WCBS_Trailermode_Feedback         Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_ESC_EPB_0x230_WCBS_Trailermode_Feedback
#define Com_CbkRxAck_CanConfigSet_Rx_ACAN_IBS_ADAS_Info_WCBS_ACC_VLC_Active     Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_IBS_ADAS_Info_WCBS_ACC_VLC_Active
#define Com_CbkRxAck_CanConfigSet_Rx_ACAN_IBS_ADAS_Info_WCBS_ACC_CDD_Active     Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_IBS_ADAS_Info_WCBS_ACC_CDD_Active
#define Com_CbkRxAck_CanConfigSet_Rx_ACAN_IBS_ADAS_Info_WCBS_ACC_VLC_Avl        Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_IBS_ADAS_Info_WCBS_ACC_VLC_Avl
#define Com_CbkRxAck_CanConfigSet_Rx_ACAN_IBS_ADAS_Info_WCBS_ACC_CDD_Avl        Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_IBS_ADAS_Info_WCBS_ACC_CDD_Avl
#define Com_CbkRxAck_CanConfigSet_Rx_ACAN_IBS_ADAS_Info_WCBS_ACC_VLC_AccInTar   Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_IBS_ADAS_Info_WCBS_ACC_VLC_AccInTar
#define Com_CbkRxAck_CanConfigSet_Rx_ACAN_IBS_ADAS_Info_WCBS_ABAAtv   Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_IBS_ADAS_Info_WCBS_ABAAtv
#define Com_CbkRxAck_CanConfigSet_Rx_ACAN_IBS_ADAS_Info_WCBS_ABAAva   Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_IBS_ADAS_Info_WCBS_ABAAva
#define Com_CbkRxAck_CanConfigSet_Rx_ACAN_IBS_ADAS_Info_WCBS_ABPAtv   Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_IBS_ADAS_Info_WCBS_ABPAtv
#define Com_CbkRxAck_CanConfigSet_Rx_ACAN_IBS_ADAS_Info_WCBS_ABPAva   Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_IBS_ADAS_Info_WCBS_ABPAva
#define Com_CbkRxAck_CanConfigSet_Rx_ACAN_IBS_ADAS_Info_WCBS_AWBAtv   Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_IBS_ADAS_Info_WCBS_AWBAtv
#define Com_CbkRxAck_CanConfigSet_Rx_ACAN_IBS_ADAS_Info_WCBS_AWBAvl   Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_IBS_ADAS_Info_WCBS_AWBAvl
#define Com_CbkRxAck_CanConfigSet_Rx_ACAN_IBS_ADAS_Info_WCBS_AEBAtv   Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_IBS_ADAS_Info_WCBS_AEBAtv
#define Com_CbkRxAck_CanConfigSet_Rx_ACAN_IBS_ADAS_Info_WCBS_AEBAva   Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_IBS_ADAS_Info_WCBS_AEBAva
#define Com_CbkRxAck_CanConfigSet_Rx_ACAN_IBS_ADAS_Info_WCBS_VStandstillSta     Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_IBS_ADAS_Info_WCBS_VStandstillSta
#define Com_CbkRxAck_CanConfigSet_Rx_ACAN_IBS_ADAS_Info_WCBS_BrkFrcSta          Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_IBS_ADAS_Info_WCBS_BrkFrcSta
#define Com_CbkRxAck_CanConfigSet_Rx_ACAN_IBS_ADAS_Info_WCBS_ESCDeteACCErroSta  Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_IBS_ADAS_Info_WCBS_ESCDeteACCErroSta
#define Com_CbkRxAck_CanConfigSet_Rx_ACAN_IBS_ADAS_Info_WCBS_APA_VLC_FailureStatus        Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_IBS_ADAS_Info_WCBS_APA_VLC_FailureStatus
#define Com_CbkRxAck_CanConfigSet_Rx_ACAN_IBS_ADAS_Info_WCBS_APA_VLC_Status     Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_IBS_ADAS_Info_WCBS_APA_VLC_Status
#define Com_CbkRxAck_CanConfigSet_Rx_ACAN_IBS_ADAS_Info_WCBS_APA_VLC_Available  Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_IBS_ADAS_Info_WCBS_APA_VLC_Available
#define Com_CbkRxAck_CanConfigSet_Rx_ACAN_IBS_ADAS_Info_WCBS_APA_VLC_Active     Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_IBS_ADAS_Info_WCBS_APA_VLC_Active
#define Com_CbkRxAck_CanConfigSet_Rx_ACAN_IBS_ADAS_Info_WCBS_APA_EmgyBrkAvlb    Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_IBS_ADAS_Info_WCBS_APA_EmgyBrkAvlb
#define Com_CbkRxAck_CanConfigSet_Rx_ACAN_IBS_ADAS_Info_WCBS_APA_CDD_Active     Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_IBS_ADAS_Info_WCBS_APA_CDD_Active
#define Com_CbkRxAck_CanConfigSet_Rx_ACAN_IBS_Info_AB_BrkPedalSwSts   Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_IBS_Info_AB_BrkPedalSwSts
#define Com_CbkRxAck_CanConfigSet_Rx_ACAN_IBS_Info_AB_BrkPedalSwStsV  Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_IBS_Info_AB_BrkPedalSwStsV
#define Com_CbkRxAck_CanConfigSet_Rx_ACAN_IBS_Info_AB_Fault_Status    Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_IBS_Info_AB_Fault_Status
#define Com_CbkRxAck_CanConfigSet_Rx_ACAN_IBS_Info_AB_IBS_Sys_Fault_Sts         Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_IBS_Info_AB_IBS_Sys_Fault_Sts
#define Com_CbkRxAck_CanConfigSet_Rx_ACAN_IBS_Info_AB_BrkPedalPct     Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_IBS_Info_AB_BrkPedalPct
#define Com_CbkRxAck_CanConfigSet_Rx_ACAN_IBS_Info_AB_BrkPedalTravel  Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_IBS_Info_AB_BrkPedalTravel
#define Com_CbkRxAck_CanConfigSet_Rx_ACAN_TBOX_DateTime1_Time_second  Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_TBOX_DateTime1_Time_second
#define Com_CbkRxAck_CanConfigSet_Rx_ACAN_TBOX_DateTime1_GPSSystAtv   Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_TBOX_DateTime1_GPSSystAtv
#define Com_CbkRxAck_CanConfigSet_Rx_ACAN_TBOX_DateTime1_Time_Minute  Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_TBOX_DateTime1_Time_Minute
#define Com_CbkRxAck_CanConfigSet_Rx_ACAN_TBOX_DateTime1_Time_Hour    Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_TBOX_DateTime1_Time_Hour
#define Com_CbkRxAck_CanConfigSet_Rx_ACAN_TBOX_DateTime1_Time_Day     Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_TBOX_DateTime1_Time_Day
#define Com_CbkRxAck_CanConfigSet_Rx_ACAN_TBOX_DateTime1_Time_Month   Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_TBOX_DateTime1_Time_Month
#define Com_CbkRxAck_CanConfigSet_Rx_ACAN_TBOX_DateTime1_Time_Year    Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_TBOX_DateTime1_Time_Year
#define Com_CbkRxAck_CanConfigSet_Rx_ACAN_MHU_Status_Info_MHU_ESCOFF_SW_Sts     Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_MHU_Status_Info_MHU_ESCOFF_SW_Sts
#define Com_CbkRxAck_CanConfigSet_Rx_ACAN_MHU_Status_Info_MHU_VCU_CreepDisable_stt        Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_MHU_Status_Info_MHU_VCU_CreepDisable_stt
#define Com_CbkRxAck_CanConfigSet_Rx_ACAN_MHU_Status_Info_MHU_AVH_Req Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_MHU_Status_Info_MHU_AVH_Req
#define Com_CbkRxAck_CanConfigSet_Rx_ACAN_MHU_Status_Info_MHU_RegencyLevRequest Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_MHU_Status_Info_MHU_RegencyLevRequest
#define Com_CbkRxAck_CanConfigSet_Rx_ACAN_MHU_Status_Info_MHU_DM_SwitchModeSts  Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_MHU_Status_Info_MHU_DM_SwitchModeSts
#define Com_CbkRxAck_CanConfigSet_Rx_ACAN_MHU_Status_Info_MHU_Trailermode_Req   Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_MHU_Status_Info_MHU_Trailermode_Req
#define Com_CbkRxAck_CanConfigSet_Rx_ACAN_MHU_Status_Info_MHU_UPAMuteSwitch     Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_MHU_Status_Info_MHU_UPAMuteSwitch
#define Com_CbkRxAck_CanConfigSet_Rx_ACAN_CCU_StsInfo1_CCU_PTCgear_Req_Reserve  Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_CCU_StsInfo1_CCU_PTCgear_Req_Reserve
#define Com_CbkRxAck_CanConfigSet_Rx_ACAN_CCU_StsInfo1_CCU_Anion_Generator_Sts  Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_CCU_StsInfo1_CCU_Anion_Generator_Sts
#define Com_CbkRxAck_CanConfigSet_Rx_ACAN_CCU_StsInfo1_CCU_AC_Req     Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_CCU_StsInfo1_CCU_AC_Req
#define Com_CbkRxAck_CanConfigSet_Rx_ACAN_CCU_StsInfo1_CCU_Onoff_Sts  Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_CCU_StsInfo1_CCU_Onoff_Sts
#define Com_CbkRxAck_CanConfigSet_Rx_ACAN_CCU_StsInfo1_CCU_AUTO_Status          Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_CCU_StsInfo1_CCU_AUTO_Status
#define Com_CbkRxAck_CanConfigSet_Rx_ACAN_CCU_StsInfo1_CCU_FrontDefrostSts      Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_CCU_StsInfo1_CCU_FrontDefrostSts
#define Com_CbkRxAck_CanConfigSet_Rx_ACAN_CCU_StsInfo1_CCU_AC_Sts     Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_CCU_StsInfo1_CCU_AC_Sts
#define Com_CbkRxAck_CanConfigSet_Rx_ACAN_CCU_StsInfo1_CCU_Circulation_Sts      Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_CCU_StsInfo1_CCU_Circulation_Sts
#define Com_CbkRxAck_CanConfigSet_Rx_ACAN_CCU_StsInfo1_CCU_ExternalTemperatureFailSts     Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_CCU_StsInfo1_CCU_ExternalTemperatureFailSts
#define Com_CbkRxAck_CanConfigSet_Rx_ACAN_CCU_StsInfo1_CCU_PTC_Req    Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_CCU_StsInfo1_CCU_PTC_Req
#define Com_CbkRxAck_CanConfigSet_Rx_ACAN_CCU_StsInfo1_CCU_Temp_Sync_Sts        Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_CCU_StsInfo1_CCU_Temp_Sync_Sts
#define Com_CbkRxAck_CanConfigSet_Rx_ACAN_CCU_StsInfo1_CCU_evaporator_Temperature         Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_CCU_StsInfo1_CCU_evaporator_Temperature
#define Com_CbkRxAck_CanConfigSet_Rx_ACAN_CCU_StsInfo1_CCU_PTCPwr_Req Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_CCU_StsInfo1_CCU_PTCPwr_Req
#define Com_CbkRxAck_CanConfigSet_Rx_ACAN_CCU_StsInfo1_CCU_CompSpdMEAS_Comp     Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_CCU_StsInfo1_CCU_CompSpdMEAS_Comp
#define Com_CbkRxAck_CanConfigSet_Rx_ACAN_CCU_StsInfo1_CCU_ExternalTemperature  Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_CCU_StsInfo1_CCU_ExternalTemperature
#define Com_CbkRxAck_CanConfigSet_Rx_ACAN_ESC_YawAngle_0x3E2_Checksum_0x3E2     Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_ESC_YawAngle_0x3E2_Checksum_0x3E2
#define Com_CbkRxAck_CanConfigSet_Rx_ACAN_ESC_YawAngle_0x3E2_RollingCounter_0x3E2         Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_ESC_YawAngle_0x3E2_RollingCounter_0x3E2
#define Com_CbkRxAck_CanConfigSet_Rx_ACAN_ESC_YawAngle_0x3E2_ESC_LateralACC_Valid         Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_ESC_YawAngle_0x3E2_ESC_LateralACC_Valid
#define Com_CbkRxAck_CanConfigSet_Rx_ACAN_ESC_YawAngle_0x3E2_ESC_LongitudeACC_Valid       Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_ESC_YawAngle_0x3E2_ESC_LongitudeACC_Valid
#define Com_CbkRxAck_CanConfigSet_Rx_ACAN_ESC_YawAngle_0x3E2_ESC_VehDynYawRate_Valid      Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_ESC_YawAngle_0x3E2_ESC_VehDynYawRate_Valid
#define Com_CbkRxAck_CanConfigSet_Rx_ACAN_ESC_YawAngle_0x3E2_ESC_VehDynYawRate  Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_ESC_YawAngle_0x3E2_ESC_VehDynYawRate
#define Com_CbkRxAck_CanConfigSet_Rx_ACAN_ESC_YawAngle_0x3E2_ESC_LateralACC     Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_ESC_YawAngle_0x3E2_ESC_LateralACC
#define Com_CbkRxAck_CanConfigSet_Rx_ACAN_ESC_YawAngle_0x3E2_ESC_LongitudeACC   Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_ESC_YawAngle_0x3E2_ESC_LongitudeACC
#define Com_CbkRxAck_CanConfigSet_Rx_ACAN_IPC_TotalOdometer_IPC_IPCTotalOdometer          Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_IPC_TotalOdometer_IPC_IPCTotalOdometer
#define Com_CbkRxAck_CanConfigSet_Rx_ACAN_IPC_TotalOdometer_IPC_IPCTotalOdometerV         Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_IPC_TotalOdometer_IPC_IPCTotalOdometerV
#define Com_CbkRxAck_CanConfigSet_Rx_ACAN_IPC_TotalOdometer_IPC_Remain_Maintenance        Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_IPC_TotalOdometer_IPC_Remain_Maintenance
#define Com_CbkRxAck_CanConfigSet_Rx_ACAN_IPC_TotalOdometer_RollingCounter_0x3F1          Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_IPC_TotalOdometer_RollingCounter_0x3F1
#define Com_CbkRxAck_CanConfigSet_Rx_ACAN_IPC_TotalOdometer_CheckSum_0x3F1      Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_IPC_TotalOdometer_CheckSum_0x3F1
#define Com_CbkRxAck_CanConfigSet_Rx_ACAN_MFS_L_Control_Button2_0x3F7_CheckSum_0x3F7      Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_MFS_L_Control_Button2_0x3F7_CheckSum_0x3F7
#define Com_CbkRxAck_CanConfigSet_Rx_ACAN_MFS_L_Control_Button2_0x3F7_RollingCounter_0x3F7          Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_MFS_L_Control_Button2_0x3F7_RollingCounter_0x3F7
#define Com_CbkRxAck_CanConfigSet_Rx_ACAN_MFS_L_Control_Button2_0x3F7_MFS_ACC_CruiseSpdIncrease     Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_MFS_L_Control_Button2_0x3F7_MFS_ACC_CruiseSpdIncrease
#define Com_CbkRxAck_CanConfigSet_Rx_ACAN_MFS_L_Control_Button2_0x3F7_MFS_ACC_CruiseOn_Off          Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_MFS_L_Control_Button2_0x3F7_MFS_ACC_CruiseOn_Off
#define Com_CbkRxAck_CanConfigSet_Rx_ACAN_MFS_L_Control_Button2_0x3F7_MFS_L2_Failure      Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_MFS_L_Control_Button2_0x3F7_MFS_L2_Failure
#define Com_CbkRxAck_CanConfigSet_Rx_ACAN_MFS_L_Control_Button2_0x3F7_MFS_ACC_CruiseGapSet          Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_MFS_L_Control_Button2_0x3F7_MFS_ACC_CruiseGapSet
#define Com_CbkRxAck_CanConfigSet_Rx_ACAN_MFS_L_Control_Button2_0x3F7_MFS_ACC_CruiseSpdDecrease     Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_MFS_L_Control_Button2_0x3F7_MFS_ACC_CruiseSpdDecrease
#define Com_CbkRxAck_CanConfigSet_Rx_ACAN_MFS_L_Control_Button2_0x3F7_MFS_ACC_CruiseCancel          Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_MFS_L_Control_Button2_0x3F7_MFS_ACC_CruiseCancel
#define Com_CbkRxAck_CanConfigSet_Rx_ACAN_BCM_RLS_RLS_Solar_Right_PassgSide     Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_BCM_RLS_RLS_Solar_Right_PassgSide
#define Com_CbkRxAck_CanConfigSet_Rx_ACAN_BCM_RLS_RLS_Solar_Left_Driveside      Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_BCM_RLS_RLS_Solar_Left_Driveside
#define Com_CbkRxAck_CanConfigSet_Rx_ACAN_BCM_RLS_RLS_Rainfall_magnitude        Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_BCM_RLS_RLS_Rainfall_magnitude
#define Com_CbkRxAck_CanConfigSet_Rx_ACAN_BCM_RLS_RLS_LightSensorError          Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_BCM_RLS_RLS_LightSensorError
#define Com_CbkRxAck_CanConfigSet_Rx_ACAN_BCM_RLS_RLS_RainSensorError Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_BCM_RLS_RLS_RainSensorError
#define Com_CbkRxAck_CanConfigSet_Rx_ACAN_BCM_RLS_RLS_LightRequest    Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_BCM_RLS_RLS_LightRequest
#define Com_CbkRxAck_CanConfigSet_Rx_ACAN_BCM_TPMS_Info2_TPMS_RFpressureSts     Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_BCM_TPMS_Info2_TPMS_RFpressureSts
#define Com_CbkRxAck_CanConfigSet_Rx_ACAN_BCM_TPMS_Info2_TPMS_LFpressureSts     Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_BCM_TPMS_Info2_TPMS_LFpressureSts
#define Com_CbkRxAck_CanConfigSet_Rx_ACAN_BCM_TPMS_Info2_TPMS_SysSts  Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_BCM_TPMS_Info2_TPMS_SysSts
#define Com_CbkRxAck_CanConfigSet_Rx_ACAN_BCM_TPMS_Info2_TPMS_RRpressureSts     Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_BCM_TPMS_Info2_TPMS_RRpressureSts
#define Com_CbkRxAck_CanConfigSet_Rx_ACAN_BCM_TPMS_Info2_TPMS_LRpressureSts     Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_BCM_TPMS_Info2_TPMS_LRpressureSts
#define Com_CbkRxAck_CanConfigSet_Rx_ACAN_BCM_TPMS_Info2_TPMS_RRpressureV       Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_BCM_TPMS_Info2_TPMS_RRpressureV
#define Com_CbkRxAck_CanConfigSet_Rx_ACAN_BCM_TPMS_Info2_TPMS_LRpressureV       Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_BCM_TPMS_Info2_TPMS_LRpressureV
#define Com_CbkRxAck_CanConfigSet_Rx_ACAN_BCM_TPMS_Info2_TPMS_RFpressureV       Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_BCM_TPMS_Info2_TPMS_RFpressureV
#define Com_CbkRxAck_CanConfigSet_Rx_ACAN_BCM_TPMS_Info2_TPMS_LFpressureV       Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_BCM_TPMS_Info2_TPMS_LFpressureV
#define Com_CbkRxAck_CanConfigSet_Rx_ACAN_BCM_TPMS_Info2_TPMS_LFpressure        Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_BCM_TPMS_Info2_TPMS_LFpressure
#define Com_CbkRxAck_CanConfigSet_Rx_ACAN_BCM_TPMS_Info2_TPMS_RFpressure        Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_BCM_TPMS_Info2_TPMS_RFpressure
#define Com_CbkRxAck_CanConfigSet_Rx_ACAN_BCM_TPMS_Info2_TPMS_LRpressure        Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_BCM_TPMS_Info2_TPMS_LRpressure
#define Com_CbkRxAck_CanConfigSet_Rx_ACAN_BCM_TPMS_Info2_TPMS_RRpressure        Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_BCM_TPMS_Info2_TPMS_RRpressure
#define Com_CbkRxAck_CanConfigSet_Rx_ACAN_BCM_DoorState_0x4D4_BCM_CoverAjarStatus         Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_BCM_DoorState_0x4D4_BCM_CoverAjarStatus
#define Com_CbkRxAck_CanConfigSet_Rx_ACAN_BCM_DoorState_0x4D4_BCM_TrunckAjarStatus        Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_BCM_DoorState_0x4D4_BCM_TrunckAjarStatus
#define Com_CbkRxAck_CanConfigSet_Rx_ACAN_BCM_DoorState_0x4D4_BCM_DriverSideDoorAjarSts   Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_BCM_DoorState_0x4D4_BCM_DriverSideDoorAjarSts
#define Com_CbkRxAck_CanConfigSet_Rx_ACAN_BCM_DoorState_0x4D4_BCM_CodriversSideDoorAjarSts          Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_BCM_DoorState_0x4D4_BCM_CodriversSideDoorAjarSts
#define Com_CbkRxAck_CanConfigSet_Rx_ACAN_BCM_DoorState_0x4D4_BCM_RearLeftDoorAjarStatus  Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_BCM_DoorState_0x4D4_BCM_RearLeftDoorAjarStatus
#define Com_CbkRxAck_CanConfigSet_Rx_ACAN_BCM_DoorState_0x4D4_BCM_RearRightDoorAjarStatus Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_BCM_DoorState_0x4D4_BCM_RearRightDoorAjarStatus
#define Com_CbkRxAck_CanConfigSet_Rx_ACAN_BCM_DoorState_0x4D4_BCM_DoorLockStatusRL        Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_BCM_DoorState_0x4D4_BCM_DoorLockStatusRL
#define Com_CbkRxAck_CanConfigSet_Rx_ACAN_BCM_DoorState_0x4D4_BCM_DoorLockStatusRR        Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_BCM_DoorState_0x4D4_BCM_DoorLockStatusRR
#define Com_CbkRxAck_CanConfigSet_Rx_ACAN_BCM_DoorState_0x4D4_BCM_DoorLockStatusCodrivres Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_BCM_DoorState_0x4D4_BCM_DoorLockStatusCodrivres
#define Com_CbkRxAck_CanConfigSet_Rx_ACAN_BCM_DoorState_0x4D4_BCM_DoorLockStatusDrv       Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_BCM_DoorState_0x4D4_BCM_DoorLockStatusDrv
#define Com_CbkRxAck_CanConfigSet_Rx_ACAN_BCM_DoorState_0x4D4_BCM_ATWS_St       Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_BCM_DoorState_0x4D4_BCM_ATWS_St
#define Com_CbkRxAck_CanConfigSet_Rx_ACAN_BCM_DoorState_0x4D4_BCM_TailGateSts   Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_BCM_DoorState_0x4D4_BCM_TailGateSts
#define Com_CbkRxAck_Tcp_ReceiveSignal                      Rte_COMCbk_Com_Tcp_ReceiveSignal
#define Com_CbkRxAck_Udp_ReceiveSignal                      Rte_COMCbk_Com_Udp_ReceiveSignal
#define Com_CbkRxAck_CanConfigSet_Rx_Radar_ARS_TIME_SYNC_Signal_Group_ARS_TIME_SYNC       Rte_COMCbk_Com_CanConfigSet_Rx_Radar_ARS_TIME_SYNC_Signal_Group_ARS_TIME_SYNC
#define Com_CbkRxAck_CanConfigSet_Rx_Radar_ARS_SYS_PERFORM_ARS_SP_TunnelFlag    Rte_COMCbk_Com_CanConfigSet_Rx_Radar_ARS_SYS_PERFORM_ARS_SP_TunnelFlag
#define Com_CbkRxAck_CanConfigSet_Rx_Radar_ARS_SYS_PERFORM_ARS_SP_CalibrationState        Rte_COMCbk_Com_CanConfigSet_Rx_Radar_ARS_SYS_PERFORM_ARS_SP_CalibrationState
#define Com_CbkRxAck_CanConfigSet_Rx_Radar_ARS_SYS_PERFORM_ARS_SP_OperationMode Rte_COMCbk_Com_CanConfigSet_Rx_Radar_ARS_SYS_PERFORM_ARS_SP_OperationMode
#define Com_CbkRxAck_CanConfigSet_Rx_Radar_ARS_SYS_PERFORM_ARS_SP_AzimuthCorrection       Rte_COMCbk_Com_CanConfigSet_Rx_Radar_ARS_SYS_PERFORM_ARS_SP_AzimuthCorrection
#define Com_CbkRxAck_CanConfigSet_Rx_Radar_ARS_SYS_PERFORM_ARS_SP_ElevationCorrection     Rte_COMCbk_Com_CanConfigSet_Rx_Radar_ARS_SYS_PERFORM_ARS_SP_ElevationCorrection
#define Com_CbkRxAck_CanConfigSet_Rx_Radar_ARS_SYS_PERFORM_ARS_SP_ErrStateGroup_4         Rte_COMCbk_Com_CanConfigSet_Rx_Radar_ARS_SYS_PERFORM_ARS_SP_ErrStateGroup_4
#define Com_CbkRxAck_CanConfigSet_Rx_Radar_ARS_SYS_PERFORM_ARS_SP_VisibilityState         Rte_COMCbk_Com_CanConfigSet_Rx_Radar_ARS_SYS_PERFORM_ARS_SP_VisibilityState
#define Com_CbkRxAck_CanConfigSet_Rx_Radar_ARS_SYS_PERFORM_ARS_SP_VisibilityRange         Rte_COMCbk_Com_CanConfigSet_Rx_Radar_ARS_SYS_PERFORM_ARS_SP_VisibilityRange
#define Com_CbkRxAck_CanConfigSet_Rx_Radar_ARS_SYS_PERFORM_Signal_Group_ARS_SYS_PERFORM   Rte_COMCbk_Com_CanConfigSet_Rx_Radar_ARS_SYS_PERFORM_Signal_Group_ARS_SYS_PERFORM
#define Com_CbkRxAck_CanConfigSet_Rx_Radar_ARS_OD_Header_Signal_Group_ARS_OD_Header       Rte_COMCbk_Com_CanConfigSet_Rx_Radar_ARS_OD_Header_Signal_Group_ARS_OD_Header
#define Com_CbkRxAck_CanConfigSet_Rx_Radar_ARS_OD_00_01_Signal_Group_ARS_OD_00_01         Rte_COMCbk_Com_CanConfigSet_Rx_Radar_ARS_OD_00_01_Signal_Group_ARS_OD_00_01
#define Com_CbkRxAck_CanConfigSet_Rx_Radar_ARS_OD_02_03_Signal_Group_ARS_OD_02_03         Rte_COMCbk_Com_CanConfigSet_Rx_Radar_ARS_OD_02_03_Signal_Group_ARS_OD_02_03
#define Com_CbkRxAck_CanConfigSet_Rx_Radar_ARS_OD_04_05_Signal_Group_ARS_OD_04_05         Rte_COMCbk_Com_CanConfigSet_Rx_Radar_ARS_OD_04_05_Signal_Group_ARS_OD_04_05
#define Com_CbkRxAck_CanConfigSet_Rx_Radar_ARS_OD_06_07_Signal_Group_ARS_OD_06_07         Rte_COMCbk_Com_CanConfigSet_Rx_Radar_ARS_OD_06_07_Signal_Group_ARS_OD_06_07
#define Com_CbkRxAck_CanConfigSet_Rx_Radar_ARS_OD_08_09_Signal_Group_ARS_OD_08_09         Rte_COMCbk_Com_CanConfigSet_Rx_Radar_ARS_OD_08_09_Signal_Group_ARS_OD_08_09
#define Com_CbkRxAck_CanConfigSet_Rx_Radar_ARS_OD_10_11_Signal_Group_ARS_OD_10_11         Rte_COMCbk_Com_CanConfigSet_Rx_Radar_ARS_OD_10_11_Signal_Group_ARS_OD_10_11
#define Com_CbkRxAck_CanConfigSet_Rx_Radar_ARS_OD_12_13_Signal_Group_ARS_OD_12_13         Rte_COMCbk_Com_CanConfigSet_Rx_Radar_ARS_OD_12_13_Signal_Group_ARS_OD_12_13
#define Com_CbkRxAck_CanConfigSet_Rx_Radar_ARS_OD_14_15_Signal_Group_ARS_OD_14_15         Rte_COMCbk_Com_CanConfigSet_Rx_Radar_ARS_OD_14_15_Signal_Group_ARS_OD_14_15
#define Com_CbkRxAck_CanConfigSet_Rx_Radar_ARS_OD_16_17_Signal_Group_ARS_OD_16_17         Rte_COMCbk_Com_CanConfigSet_Rx_Radar_ARS_OD_16_17_Signal_Group_ARS_OD_16_17
#define Com_CbkRxAck_CanConfigSet_Rx_Radar_ARS_OD_18_19_Signal_Group_ARS_OD_18_19         Rte_COMCbk_Com_CanConfigSet_Rx_Radar_ARS_OD_18_19_Signal_Group_ARS_OD_18_19
#define Com_CbkRxAck_CanConfigSet_Rx_Radar_ARS_OD_20_21_Signal_Group_ARS_OD_20_21         Rte_COMCbk_Com_CanConfigSet_Rx_Radar_ARS_OD_20_21_Signal_Group_ARS_OD_20_21
#define Com_CbkRxAck_CanConfigSet_Rx_Radar_ARS_OD_22_23_Signal_Group_ARS_OD_22_23         Rte_COMCbk_Com_CanConfigSet_Rx_Radar_ARS_OD_22_23_Signal_Group_ARS_OD_22_23
#define Com_CbkRxAck_CanConfigSet_Rx_Radar_ARS_OD_24_25_Signal_Group_ARS_OD_24_25         Rte_COMCbk_Com_CanConfigSet_Rx_Radar_ARS_OD_24_25_Signal_Group_ARS_OD_24_25
#define Com_CbkRxAck_CanConfigSet_Rx_Radar_ARS_OD_26_27_Signal_Group_ARS_OD_26_27         Rte_COMCbk_Com_CanConfigSet_Rx_Radar_ARS_OD_26_27_Signal_Group_ARS_OD_26_27
#define Com_CbkRxAck_CanConfigSet_Rx_Radar_ARS_OD_28_29_Signal_Group_ARS_OD_28_29         Rte_COMCbk_Com_CanConfigSet_Rx_Radar_ARS_OD_28_29_Signal_Group_ARS_OD_28_29
#define Com_CbkRxAck_CanConfigSet_Rx_Radar_ARS_OD_30_31_Signal_Group_ARS_OD_30_31         Rte_COMCbk_Com_CanConfigSet_Rx_Radar_ARS_OD_30_31_Signal_Group_ARS_OD_30_31
#define Com_CbkRxAck_Tdp_ReceiveSignal_1601                 Rte_COMCbk_Com_Tcp_ReceiveSignal_1601
#define Com_CbkRxAck_Tcp_ReceiveSignal_1602                 Rte_COMCbk_Com_Tcp_ReceiveSignal_1602
#define Com_CbkRxAck_Tcp_ReceiveSignal_1603                 Rte_COMCbk_Com_Tcp_ReceiveSignal_1603
#define Com_CbkRxAck_Tcp_ReceiveSignal_1604                 Rte_COMCbk_Com_Tcp_ReceiveSignal_1604
#define Com_CbkRxAck_Tcp_ReceiveSignal_1605                 Rte_COMCbk_Com_Tcp_ReceiveSignal_1605
#define Com_CbkRxAck_Tcp_ReceiveSignal_1606                 Rte_COMCbk_Com_Tcp_ReceiveSignal_1606
#define Com_CbkRxAck_Tcp_ReceiveSignal_1607                 Rte_COMCbk_Com_Tcp_ReceiveSignal_1607
#define Com_CbkRxAck_Tcp_ReceiveSignal_1608                 Rte_COMCbk_Com_Tcp_ReceiveSignal_1608
#define Com_CbkRxTOut_CanConfigSet_Rx_ACAN_ACU_ChimeTelltaleReq_ACU_CoDSeatOccupSensorStat          Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_ACU_ChimeTelltaleReq_ACU_CoDSeatOccupSensorStat
#define Com_CbkRxTOut_CanConfigSet_Rx_ACAN_ACU_ChimeTelltaleReq_ACU_DSeatOccupSensorStat  Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_ACU_ChimeTelltaleReq_ACU_DSeatOccupSensorStat
#define Com_CbkRxTOut_CanConfigSet_Rx_ACAN_ACU_ChimeTelltaleReq_ACU_CoDSeatbeltBucklestatus         Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_ACU_ChimeTelltaleReq_ACU_CoDSeatbeltBucklestatus
#define Com_CbkRxTOut_CanConfigSet_Rx_ACAN_ACU_ChimeTelltaleReq_ACU_DSeatbeltBucklestatus Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_ACU_ChimeTelltaleReq_ACU_DSeatbeltBucklestatus
#define Com_CbkRxTOut_CanConfigSet_Rx_ACAN_ACU_ChimeTelltaleReq_ACU_CoDAirbagStatus       Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_ACU_ChimeTelltaleReq_ACU_CoDAirbagStatus
#define Com_CbkRxTOut_CanConfigSet_Rx_ACAN_ACU_ChimeTelltaleReq_ACU_DAirbagStatus         Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_ACU_ChimeTelltaleReq_ACU_DAirbagStatus
#define Com_CbkRxTOut_CanConfigSet_Rx_ACAN_ACU_ChimeTelltaleReq_ACU_RPSeatOccupSensorStat Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_ACU_ChimeTelltaleReq_ACU_RPSeatOccupSensorStat
#define Com_CbkRxTOut_CanConfigSet_Rx_ACAN_ACU_ChimeTelltaleReq_ACU_MPSeatOccupSensorStat Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_ACU_ChimeTelltaleReq_ACU_MPSeatOccupSensorStat
#define Com_CbkRxTOut_CanConfigSet_Rx_ACAN_ACU_ChimeTelltaleReq_ACU_LPSeatOccupSensorStat Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_ACU_ChimeTelltaleReq_ACU_LPSeatOccupSensorStat
#define Com_CbkRxTOut_CanConfigSet_Rx_ACAN_ACU_ChimeTelltaleReq_ACU_RCABsts     Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_ACU_ChimeTelltaleReq_ACU_RCABsts
#define Com_CbkRxTOut_CanConfigSet_Rx_ACAN_ACU_ChimeTelltaleReq_ACU_LCABsts     Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_ACU_ChimeTelltaleReq_ACU_LCABsts
#define Com_CbkRxTOut_CanConfigSet_Rx_ACAN_ACU_ChimeTelltaleReq_ACU_RSABsts     Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_ACU_ChimeTelltaleReq_ACU_RSABsts
#define Com_CbkRxTOut_CanConfigSet_Rx_ACAN_ACU_ChimeTelltaleReq_ACU_LSABsts     Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_ACU_ChimeTelltaleReq_ACU_LSABsts
#define Com_CbkRxTOut_CanConfigSet_Rx_ACAN_ACU_ChimeTelltaleReq_ACU_RPSeatbeltBucklestatus          Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_ACU_ChimeTelltaleReq_ACU_RPSeatbeltBucklestatus
#define Com_CbkRxTOut_CanConfigSet_Rx_ACAN_ACU_ChimeTelltaleReq_ACU_MPSeatbeltBucklestatus          Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_ACU_ChimeTelltaleReq_ACU_MPSeatbeltBucklestatus
#define Com_CbkRxTOut_CanConfigSet_Rx_ACAN_ACU_ChimeTelltaleReq_ACU_LPSeatbeltBucklestatus          Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_ACU_ChimeTelltaleReq_ACU_LPSeatbeltBucklestatus
#define Com_CbkRxTOut_CanConfigSet_Rx_ACAN_ACU_ChimeTelltaleReq_ACU_CrashSts    Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_ACU_ChimeTelltaleReq_ACU_CrashSts
#define Com_CbkRxTOut_CanConfigSet_Rx_ACAN_ACU_ChimeTelltaleReq_ACU_CrashRearOutputSts    Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_ACU_ChimeTelltaleReq_ACU_CrashRearOutputSts
#define Com_CbkRxTOut_CanConfigSet_Rx_ACAN_ACU_ChimeTelltaleReq_ACU_CrashRightOutputSts   Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_ACU_ChimeTelltaleReq_ACU_CrashRightOutputSts
#define Com_CbkRxTOut_CanConfigSet_Rx_ACAN_ACU_ChimeTelltaleReq_ACU_CrashLeftOutputSts    Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_ACU_ChimeTelltaleReq_ACU_CrashLeftOutputSts
#define Com_CbkRxTOut_CanConfigSet_Rx_ACAN_ACU_ChimeTelltaleReq_ACU_CrashFrontOutputSts   Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_ACU_ChimeTelltaleReq_ACU_CrashFrontOutputSts
#define Com_CbkRxTOut_CanConfigSet_Rx_ACAN_ACU_ChimeTelltaleReq_ACU_AirbagWarningStatus   Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_ACU_ChimeTelltaleReq_ACU_AirbagWarningStatus
#define Com_CbkRxTOut_CanConfigSet_Rx_ACAN_ACU_ChimeTelltaleReq_ACU_CoDSeatbletPTighten   Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_ACU_ChimeTelltaleReq_ACU_CoDSeatbletPTighten
#define Com_CbkRxTOut_CanConfigSet_Rx_ACAN_ACU_ChimeTelltaleReq_ACU_DSeatbletPTighten     Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_ACU_ChimeTelltaleReq_ACU_DSeatbletPTighten
#define Com_CbkRxTOut_CanConfigSet_Rx_ACAN_ACU_ChimeTelltaleReq_ACU_AliveCounter          Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_ACU_ChimeTelltaleReq_ACU_AliveCounter
#define Com_CbkRxTOut_CanConfigSet_Rx_ACAN_ACU_ChimeTelltaleReq_ACU_CheckSum    Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_ACU_ChimeTelltaleReq_ACU_CheckSum
#define Com_CbkRxTOut_CanConfigSet_Rx_ACAN_BCM_LIGHT_0x106_CheckSum_0x106       Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_BCM_LIGHT_0x106_CheckSum_0x106
#define Com_CbkRxTOut_CanConfigSet_Rx_ACAN_BCM_LIGHT_0x106_RollingCounter_0x106 Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_BCM_LIGHT_0x106_RollingCounter_0x106
#define Com_CbkRxTOut_CanConfigSet_Rx_ACAN_BCM_LIGHT_0x106_BCM_TurnIndicatorSts Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_BCM_LIGHT_0x106_BCM_TurnIndicatorSts
#define Com_CbkRxTOut_CanConfigSet_Rx_ACAN_BCM_LIGHT_0x106_BCM_PosLmpSts        Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_BCM_LIGHT_0x106_BCM_PosLmpSts
#define Com_CbkRxTOut_CanConfigSet_Rx_ACAN_BCM_LIGHT_0x106_BCM_LowBeamSts       Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_BCM_LIGHT_0x106_BCM_LowBeamSts
#define Com_CbkRxTOut_CanConfigSet_Rx_ACAN_BCM_LIGHT_0x106_BCM_HighBeamSts      Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_BCM_LIGHT_0x106_BCM_HighBeamSts
#define Com_CbkRxTOut_CanConfigSet_Rx_ACAN_BCM_LIGHT_0x106_BCM_RearFogLampLightSts        Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_BCM_LIGHT_0x106_BCM_RearFogLampLightSts
#define Com_CbkRxTOut_CanConfigSet_Rx_ACAN_BCM_LIGHT_0x106_BCM_BrakeLightSts    Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_BCM_LIGHT_0x106_BCM_BrakeLightSts
#define Com_CbkRxTOut_CanConfigSet_Rx_ACAN_BCM_LIGHT_0x106_BCM_ReverseLightSts  Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_BCM_LIGHT_0x106_BCM_ReverseLightSts
#define Com_CbkRxTOut_CanConfigSet_Rx_ACAN_BCM_LIGHT_0x106_BCM_DayRunningLampSts          Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_BCM_LIGHT_0x106_BCM_DayRunningLampSts
#define Com_CbkRxTOut_CanConfigSet_Rx_ACAN_BCM_LIGHT_0x106_BCM_RMarkerLightSts  Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_BCM_LIGHT_0x106_BCM_RMarkerLightSts
#define Com_CbkRxTOut_CanConfigSet_Rx_ACAN_BCM_LIGHT_0x106_BCM_Rr_domelampSts   Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_BCM_LIGHT_0x106_BCM_Rr_domelampSts
#define Com_CbkRxTOut_CanConfigSet_Rx_ACAN_BCM_LIGHT_0x106_BCM_Fr_domelampSts   Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_BCM_LIGHT_0x106_BCM_Fr_domelampSts
#define Com_CbkRxTOut_CanConfigSet_Rx_ACAN_BCM_LIGHT_0x106_BCM_LicensePlateLightSts       Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_BCM_LIGHT_0x106_BCM_LicensePlateLightSts
#define Com_CbkRxTOut_CanConfigSet_Rx_ACAN_BCM_LIGHT_0x106_BCM_HeadLight_adjustSts        Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_BCM_LIGHT_0x106_BCM_HeadLight_adjustSts
#define Com_CbkRxTOut_CanConfigSet_Rx_ACAN_BCM_LIGHT_0x106_BCM_FrontFogLampLightSts       Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_BCM_LIGHT_0x106_BCM_FrontFogLampLightSts
#define Com_CbkRxTOut_CanConfigSet_Rx_ACAN_BCM_LIGHT_0x106_BCM_STAT_InteriorLight         Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_BCM_LIGHT_0x106_BCM_STAT_InteriorLight
#define Com_CbkRxTOut_CanConfigSet_Rx_ACAN_BCM_LIGHT_0x106_BCM_STAT_SwLightBrightness     Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_BCM_LIGHT_0x106_BCM_STAT_SwLightBrightness
#define Com_CbkRxTOut_CanConfigSet_Rx_ACAN_BCM_LIGHT_0x106_BCM_TurnLight_FaultSts         Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_BCM_LIGHT_0x106_BCM_TurnLight_FaultSts
#define Com_CbkRxTOut_CanConfigSet_Rx_ACAN_BCM_LIGHT_0x106_BCM_AmbeLightZone2Sts          Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_BCM_LIGHT_0x106_BCM_AmbeLightZone2Sts
#define Com_CbkRxTOut_CanConfigSet_Rx_ACAN_BCM_LIGHT_0x106_BCM_AmbeLightZone1Sts          Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_BCM_LIGHT_0x106_BCM_AmbeLightZone1Sts
#define Com_CbkRxTOut_CanConfigSet_Rx_ACAN_BCM_SwitchSts_0x109_CheckSum_0x109   Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_BCM_SwitchSts_0x109_CheckSum_0x109
#define Com_CbkRxTOut_CanConfigSet_Rx_ACAN_BCM_SwitchSts_0x109_RollingCounter_0x109       Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_BCM_SwitchSts_0x109_RollingCounter_0x109
#define Com_CbkRxTOut_CanConfigSet_Rx_ACAN_BCM_SwitchSts_0x109_BCM_STAT_Horn    Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_BCM_SwitchSts_0x109_BCM_STAT_Horn
#define Com_CbkRxTOut_CanConfigSet_Rx_ACAN_BCM_SwitchSts_0x109_BCM_STAT_HazardWarn        Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_BCM_SwitchSts_0x109_BCM_STAT_HazardWarn
#define Com_CbkRxTOut_CanConfigSet_Rx_ACAN_BCM_SwitchSts_0x109_BCM_LowBeamSWSts Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_BCM_SwitchSts_0x109_BCM_LowBeamSWSts
#define Com_CbkRxTOut_CanConfigSet_Rx_ACAN_BCM_SwitchSts_0x109_BCM_TurnLightSWSts         Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_BCM_SwitchSts_0x109_BCM_TurnLightSWSts
#define Com_CbkRxTOut_CanConfigSet_Rx_ACAN_BCM_SwitchSts_0x109_BCM_Tail_MicroSW Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_BCM_SwitchSts_0x109_BCM_Tail_MicroSW
#define Com_CbkRxTOut_CanConfigSet_Rx_ACAN_BCM_SwitchSts_0x109_STAT_Central_LockSts       Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_BCM_SwitchSts_0x109_STAT_Central_LockSts
#define Com_CbkRxTOut_CanConfigSet_Rx_ACAN_BCM_SwitchSts_0x109_BCM_RFogLampSWSts          Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_BCM_SwitchSts_0x109_BCM_RFogLampSWSts
#define Com_CbkRxTOut_CanConfigSet_Rx_ACAN_BCM_SwitchSts_0x109_BCM_FFogLampSWSts          Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_BCM_SwitchSts_0x109_BCM_FFogLampSWSts
#define Com_CbkRxTOut_CanConfigSet_Rx_ACAN_BCM_SwitchSts_0x109_BCM_HighBeamSWSts          Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_BCM_SwitchSts_0x109_BCM_HighBeamSWSts
#define Com_CbkRxTOut_CanConfigSet_Rx_ACAN_ABS_FrontWheelSpeMCUKPH_ABS_FLWheelSpeedInvalid          Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_ABS_FrontWheelSpeMCUKPH_ABS_FLWheelSpeedInvalid
#define Com_CbkRxTOut_CanConfigSet_Rx_ACAN_ABS_FrontWheelSpeMCUKPH_ABS_FLWheelSpeedKPH    Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_ABS_FrontWheelSpeMCUKPH_ABS_FLWheelSpeedKPH
#define Com_CbkRxTOut_CanConfigSet_Rx_ACAN_ABS_FrontWheelSpeMCUKPH_ABS_FRWheelSpeedInvalid          Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_ABS_FrontWheelSpeMCUKPH_ABS_FRWheelSpeedInvalid
#define Com_CbkRxTOut_CanConfigSet_Rx_ACAN_ABS_FrontWheelSpeMCUKPH_ABS_FRWheelSpeedKPH    Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_ABS_FrontWheelSpeMCUKPH_ABS_FRWheelSpeedKPH
#define Com_CbkRxTOut_CanConfigSet_Rx_ACAN_ABS_FrontWheelSpeMCUKPH_ABS_FRWheelDirection   Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_ABS_FrontWheelSpeMCUKPH_ABS_FRWheelDirection
#define Com_CbkRxTOut_CanConfigSet_Rx_ACAN_ABS_FrontWheelSpeMCUKPH_ABS_FLWheelDirection   Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_ABS_FrontWheelSpeMCUKPH_ABS_FLWheelDirection
#define Com_CbkRxTOut_CanConfigSet_Rx_ACAN_ABS_FrontWheelSpeMCUKPH_ABS_FWSpeMCUKPH_AliveCounter     Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_ABS_FrontWheelSpeMCUKPH_ABS_FWSpeMCUKPH_AliveCounter
#define Com_CbkRxTOut_CanConfigSet_Rx_ACAN_ABS_FrontWheelSpeMCUKPH_ABS_FWSpeMCUKPH_CheckSum         Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_ABS_FrontWheelSpeMCUKPH_ABS_FWSpeMCUKPH_CheckSum
#define Com_CbkRxTOut_CanConfigSet_Rx_ACAN_ABS_RearWheelSpeMCUKPH_ABS_RLWheelSpeedInvalid Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_ABS_RearWheelSpeMCUKPH_ABS_RLWheelSpeedInvalid
#define Com_CbkRxTOut_CanConfigSet_Rx_ACAN_ABS_RearWheelSpeMCUKPH_ABS_RLWheelSpeedKPH     Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_ABS_RearWheelSpeMCUKPH_ABS_RLWheelSpeedKPH
#define Com_CbkRxTOut_CanConfigSet_Rx_ACAN_ABS_RearWheelSpeMCUKPH_ABS_RRWheelSpeedInvalid Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_ABS_RearWheelSpeMCUKPH_ABS_RRWheelSpeedInvalid
#define Com_CbkRxTOut_CanConfigSet_Rx_ACAN_ABS_RearWheelSpeMCUKPH_ABS_RRWheelSpeedKPH     Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_ABS_RearWheelSpeMCUKPH_ABS_RRWheelSpeedKPH
#define Com_CbkRxTOut_CanConfigSet_Rx_ACAN_ABS_RearWheelSpeMCUKPH_ABS_RRWheelDirection    Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_ABS_RearWheelSpeMCUKPH_ABS_RRWheelDirection
#define Com_CbkRxTOut_CanConfigSet_Rx_ACAN_ABS_RearWheelSpeMCUKPH_ABS_RLWheelDirection    Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_ABS_RearWheelSpeMCUKPH_ABS_RLWheelDirection
#define Com_CbkRxTOut_CanConfigSet_Rx_ACAN_ABS_RearWheelSpeMCUKPH_ABS_RWSpeMCUKPH_AliveCounter      Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_ABS_RearWheelSpeMCUKPH_ABS_RWSpeMCUKPH_AliveCounter
#define Com_CbkRxTOut_CanConfigSet_Rx_ACAN_ABS_RearWheelSpeMCUKPH_ABS_RWSpeMCUKPH_CheckSum          Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_ABS_RearWheelSpeMCUKPH_ABS_RWSpeMCUKPH_CheckSum
#define Com_CbkRxTOut_CanConfigSet_Rx_ACAN_ABS_WheelSpeedRC_ABS_FLWheelSpeedRC  Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_ABS_WheelSpeedRC_ABS_FLWheelSpeedRC
#define Com_CbkRxTOut_CanConfigSet_Rx_ACAN_ABS_WheelSpeedRC_ABS_FRWheelSpeedRC  Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_ABS_WheelSpeedRC_ABS_FRWheelSpeedRC
#define Com_CbkRxTOut_CanConfigSet_Rx_ACAN_ABS_WheelSpeedRC_ABS_RLWheelSpeedRC  Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_ABS_WheelSpeedRC_ABS_RLWheelSpeedRC
#define Com_CbkRxTOut_CanConfigSet_Rx_ACAN_ABS_WheelSpeedRC_ABS_RRWheelSpeedRC  Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_ABS_WheelSpeedRC_ABS_RRWheelSpeedRC
#define Com_CbkRxTOut_CanConfigSet_Rx_ACAN_ABS_WheelSpeedRC_ABS_FLWheelSpeedRCSts         Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_ABS_WheelSpeedRC_ABS_FLWheelSpeedRCSts
#define Com_CbkRxTOut_CanConfigSet_Rx_ACAN_ABS_WheelSpeedRC_ABS_FRWheelSpeedRCSts         Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_ABS_WheelSpeedRC_ABS_FRWheelSpeedRCSts
#define Com_CbkRxTOut_CanConfigSet_Rx_ACAN_ABS_WheelSpeedRC_ABS_RLWheelSpeedRCSts         Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_ABS_WheelSpeedRC_ABS_RLWheelSpeedRCSts
#define Com_CbkRxTOut_CanConfigSet_Rx_ACAN_ABS_WheelSpeedRC_ABS_RRWheelSpeedRCSts         Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_ABS_WheelSpeedRC_ABS_RRWheelSpeedRCSts
#define Com_CbkRxTOut_CanConfigSet_Rx_ACAN_ABS_WheelSpeedRC_ABS_WheelSpeMCURC_AliveCounter          Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_ABS_WheelSpeedRC_ABS_WheelSpeMCURC_AliveCounter
#define Com_CbkRxTOut_CanConfigSet_Rx_ACAN_ABS_WheelSpeedRC_ABS_WheelSpeMCURC_CheckSum    Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_ABS_WheelSpeedRC_ABS_WheelSpeMCURC_CheckSum
#define Com_CbkRxTOut_CanConfigSet_Rx_ACAN_ABS_Status_ABSActive       Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_ABS_Status_ABSActive
#define Com_CbkRxTOut_CanConfigSet_Rx_ACAN_ABS_Status_ABS_EBDFailed   Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_ABS_Status_ABS_EBDFailed
#define Com_CbkRxTOut_CanConfigSet_Rx_ACAN_ABS_Status_ABSFailed       Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_ABS_Status_ABSFailed
#define Com_CbkRxTOut_CanConfigSet_Rx_ACAN_ABS_Status_ABS_LowBrakeFluid         Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_ABS_Status_ABS_LowBrakeFluid
#define Com_CbkRxTOut_CanConfigSet_Rx_ACAN_ABS_Status_ABS_VehicleSpeedInvalid   Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_ABS_Status_ABS_VehicleSpeedInvalid
#define Com_CbkRxTOut_CanConfigSet_Rx_ACAN_ABS_Status_ABS_VehicleSpeed          Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_ABS_Status_ABS_VehicleSpeed
#define Com_CbkRxTOut_CanConfigSet_Rx_ACAN_ABS_Status_ABS_Status_AliveCounter   Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_ABS_Status_ABS_Status_AliveCounter
#define Com_CbkRxTOut_CanConfigSet_Rx_ACAN_ABS_Status_ABS_HAZActive   Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_ABS_Status_ABS_HAZActive
#define Com_CbkRxTOut_CanConfigSet_Rx_ACAN_ABS_Status_ABS_Status_CheckSum       Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_ABS_Status_ABS_Status_CheckSum
#define Com_CbkRxTOut_CanConfigSet_Rx_ACAN_ESC_Status_0x132_Checksum_0x132      Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_ESC_Status_0x132_Checksum_0x132
#define Com_CbkRxTOut_CanConfigSet_Rx_ACAN_ESC_Status_0x132_RollingCounter_0x132          Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_ESC_Status_0x132_RollingCounter_0x132
#define Com_CbkRxTOut_CanConfigSet_Rx_ACAN_ESC_Status_0x132_ESC_SlopeGradeAngle Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_ESC_Status_0x132_ESC_SlopeGradeAngle
#define Com_CbkRxTOut_CanConfigSet_Rx_ACAN_ESC_Status_0x132_ESC_MasterCylinderPressureV   Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_ESC_Status_0x132_ESC_MasterCylinderPressureV
#define Com_CbkRxTOut_CanConfigSet_Rx_ACAN_ESC_Status_0x132_ESC_MasterCylinderPressure    Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_ESC_Status_0x132_ESC_MasterCylinderPressure
#define Com_CbkRxTOut_CanConfigSet_Rx_ACAN_ESC_Status_0x132_ESC_HSA_Control_Status        Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_ESC_Status_0x132_ESC_HSA_Control_Status
#define Com_CbkRxTOut_CanConfigSet_Rx_ACAN_ESC_Status_0x132_ESC_HSA_Status_Fault          Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_ESC_Status_0x132_ESC_HSA_Status_Fault
#define Com_CbkRxTOut_CanConfigSet_Rx_ACAN_ESC_Status_0x132_ESC_TcsDisableSts   Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_ESC_Status_0x132_ESC_TcsDisableSts
#define Com_CbkRxTOut_CanConfigSet_Rx_ACAN_ESC_Status_0x132_ESC_EscCtrlActv     Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_ESC_Status_0x132_ESC_EscCtrlActv
#define Com_CbkRxTOut_CanConfigSet_Rx_ACAN_ESC_Status_0x132_ESC_TcsCtrlActv     Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_ESC_Status_0x132_ESC_TcsCtrlActv
#define Com_CbkRxTOut_CanConfigSet_Rx_ACAN_ESC_Status_0x132_ESC_EscFlgFlt       Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_ESC_Status_0x132_ESC_EscFlgFlt
#define Com_CbkRxTOut_CanConfigSet_Rx_ACAN_ESC_Status_0x132_ESC_TcsFlgFlt       Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_ESC_Status_0x132_ESC_TcsFlgFlt
#define Com_CbkRxTOut_CanConfigSet_Rx_ACAN_ESC_Status_0x132_ESC_EscDisableSts   Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_ESC_Status_0x132_ESC_EscDisableSts
#define Com_CbkRxTOut_CanConfigSet_Rx_ACAN_ESC_Status_0x132_ESC_HBAFlgFlt       Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_ESC_Status_0x132_ESC_HBAFlgFlt
#define Com_CbkRxTOut_CanConfigSet_Rx_ACAN_ESC_Status_0x132_ESC_HbaCtrlActv     Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_ESC_Status_0x132_ESC_HbaCtrlActv
#define Com_CbkRxTOut_CanConfigSet_Rx_ACAN_ESC_Status_0x132_BAS_FlgFlt          Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_ESC_Status_0x132_BAS_FlgFlt
#define Com_CbkRxTOut_CanConfigSet_Rx_ACAN_ESC_Status_0x132_BAS_CtrlActv        Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_ESC_Status_0x132_BAS_CtrlActv
#define Com_CbkRxTOut_CanConfigSet_Rx_ACAN_ESC_Status_0x132_IBS_ESCOFF_StsFB    Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_ESC_Status_0x132_IBS_ESCOFF_StsFB
#define Com_CbkRxTOut_CanConfigSet_Rx_ACAN_VCU_Ctrl_VCU_ModeGearSts   Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_VCU_Ctrl_VCU_ModeGearSts
#define Com_CbkRxTOut_CanConfigSet_Rx_ACAN_VCU_Ctrl_VCU_P_Sts         Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_VCU_Ctrl_VCU_P_Sts
#define Com_CbkRxTOut_CanConfigSet_Rx_ACAN_VCU_Ctrl_VCU_Warning_IMMO_Fail       Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_VCU_Ctrl_VCU_Warning_IMMO_Fail
#define Com_CbkRxTOut_CanConfigSet_Rx_ACAN_VCU_Ctrl_VCU_Ready         Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_VCU_Ctrl_VCU_Ready
#define Com_CbkRxTOut_CanConfigSet_Rx_ACAN_VCU_Ctrl_VCU_RegencyLevInd Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_VCU_Ctrl_VCU_RegencyLevInd
#define Com_CbkRxTOut_CanConfigSet_Rx_ACAN_VCU_Ctrl_VCU_Ctrl_AliveCounter       Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_VCU_Ctrl_VCU_Ctrl_AliveCounter
#define Com_CbkRxTOut_CanConfigSet_Rx_ACAN_VCU_Ctrl_VCU_LimpHomeSts   Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_VCU_Ctrl_VCU_LimpHomeSts
#define Com_CbkRxTOut_CanConfigSet_Rx_ACAN_VCU_Ctrl_VCU_Ctrl_CheckSum Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_VCU_Ctrl_VCU_Ctrl_CheckSum
#define Com_CbkRxTOut_CanConfigSet_Rx_ACAN_VCU_StsEpt_VCU_StsAccPedalFault      Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_VCU_StsEpt_VCU_StsAccPedalFault
#define Com_CbkRxTOut_CanConfigSet_Rx_ACAN_VCU_StsEpt_VCU_StsSysFault Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_VCU_StsEpt_VCU_StsSysFault
#define Com_CbkRxTOut_CanConfigSet_Rx_ACAN_VCU_StsEpt_VCU_AccPedalPosition      Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_VCU_StsEpt_VCU_AccPedalPosition
#define Com_CbkRxTOut_CanConfigSet_Rx_ACAN_VCU_StsEpt_VCU_AccPedal_Valid        Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_VCU_StsEpt_VCU_AccPedal_Valid
#define Com_CbkRxTOut_CanConfigSet_Rx_ACAN_VCU_StsEpt_VCU_StsEpt_AliveCounter   Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_VCU_StsEpt_VCU_StsEpt_AliveCounter
#define Com_CbkRxTOut_CanConfigSet_Rx_ACAN_VCU_StsEpt_VCU_StsEpt_CheckSum       Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_VCU_StsEpt_VCU_StsEpt_CheckSum
#define Com_CbkRxTOut_CanConfigSet_Rx_ACAN_SAS_Sensor_0x17E_Checksum_0x17E      Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_SAS_Sensor_0x17E_Checksum_0x17E
#define Com_CbkRxTOut_CanConfigSet_Rx_ACAN_SAS_Sensor_0x17E_Rolling_counter_0x17E         Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_SAS_Sensor_0x17E_Rolling_counter_0x17E
#define Com_CbkRxTOut_CanConfigSet_Rx_ACAN_SAS_Sensor_0x17E_SAS_SASStsSnsr      Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_SAS_Sensor_0x17E_SAS_SASStsSnsr
#define Com_CbkRxTOut_CanConfigSet_Rx_ACAN_SAS_Sensor_0x17E_SAS_SteeringAngleValid        Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_SAS_Sensor_0x17E_SAS_SteeringAngleValid
#define Com_CbkRxTOut_CanConfigSet_Rx_ACAN_SAS_Sensor_0x17E_SAS_SteerWhlRotSpd  Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_SAS_Sensor_0x17E_SAS_SteerWhlRotSpd
#define Com_CbkRxTOut_CanConfigSet_Rx_ACAN_SAS_Sensor_0x17E_SAS_SASFailure      Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_SAS_Sensor_0x17E_SAS_SASFailure
#define Com_CbkRxTOut_CanConfigSet_Rx_ACAN_SAS_Sensor_0x17E_SAS_Calibrated      Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_SAS_Sensor_0x17E_SAS_Calibrated
#define Com_CbkRxTOut_CanConfigSet_Rx_ACAN_SAS_Sensor_0x17E_SAS_SteerWhlRotSpdStatus      Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_SAS_Sensor_0x17E_SAS_SteerWhlRotSpdStatus
#define Com_CbkRxTOut_CanConfigSet_Rx_ACAN_SAS_Sensor_0x17E_SAS_SteerWheelAngle Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_SAS_Sensor_0x17E_SAS_SteerWheelAngle
#define Com_CbkRxTOut_CanConfigSet_Rx_ACAN_EPS_LKA_Sts_CheckSum_0x17F Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_EPS_LKA_Sts_CheckSum_0x17F
#define Com_CbkRxTOut_CanConfigSet_Rx_ACAN_EPS_LKA_Sts_EPS_APA_CtrlAbortFeedback          Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_EPS_LKA_Sts_EPS_APA_CtrlAbortFeedback
#define Com_CbkRxTOut_CanConfigSet_Rx_ACAN_EPS_LKA_Sts_RollingCounter_0x17F     Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_EPS_LKA_Sts_RollingCounter_0x17F
#define Com_CbkRxTOut_CanConfigSet_Rx_ACAN_EPS_LKA_Sts_EPS_SterMod    Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_EPS_LKA_Sts_EPS_SterMod
#define Com_CbkRxTOut_CanConfigSet_Rx_ACAN_EPS_LKA_Sts_EPS_SterModV   Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_EPS_LKA_Sts_EPS_SterModV
#define Com_CbkRxTOut_CanConfigSet_Rx_ACAN_EPS_LKA_Sts_EPS_LKARespTorq          Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_EPS_LKA_Sts_EPS_LKARespTorq
#define Com_CbkRxTOut_CanConfigSet_Rx_ACAN_EPS_LKA_Sts_EPS_ADAS_CtrlAbortFeedback         Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_EPS_LKA_Sts_EPS_ADAS_CtrlAbortFeedback
#define Com_CbkRxTOut_CanConfigSet_Rx_ACAN_EPS_LKA_Sts_EPS_SterFltMod Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_EPS_LKA_Sts_EPS_SterFltMod
#define Com_CbkRxTOut_CanConfigSet_Rx_ACAN_EPS_LKA_Sts_EPS_DrStrTorqV Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_EPS_LKA_Sts_EPS_DrStrTorqV
#define Com_CbkRxTOut_CanConfigSet_Rx_ACAN_EPS_LKA_Sts_EPS_APA_ModAvail         Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_EPS_LKA_Sts_EPS_APA_ModAvail
#define Com_CbkRxTOut_CanConfigSet_Rx_ACAN_EPS_LKA_Sts_EPS_APA_ModActv          Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_EPS_LKA_Sts_EPS_APA_ModActv
#define Com_CbkRxTOut_CanConfigSet_Rx_ACAN_EPS_LKA_Sts_EPS_ADAS_ModActv         Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_EPS_LKA_Sts_EPS_ADAS_ModActv
#define Com_CbkRxTOut_CanConfigSet_Rx_ACAN_EPS_LKA_Sts_EPS_ADAS_ModAvail        Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_EPS_LKA_Sts_EPS_ADAS_ModAvail
#define Com_CbkRxTOut_CanConfigSet_Rx_ACAN_EPS_LKA_Sts_EPS_DrStrTorqVal         Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_EPS_LKA_Sts_EPS_DrStrTorqVal
#define Com_CbkRxTOut_CanConfigSet_Rx_ACAN_MHU_ADAS02_Nav_errorSts    Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_MHU_ADAS02_Nav_errorSts
#define Com_CbkRxTOut_CanConfigSet_Rx_ACAN_MHU_ADAS02_Nav_RoadType    Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_MHU_ADAS02_Nav_RoadType
#define Com_CbkRxTOut_CanConfigSet_Rx_ACAN_MHU_ADAS02_Nav_VehToTrafEyeDist      Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_MHU_ADAS02_Nav_VehToTrafEyeDist
#define Com_CbkRxTOut_CanConfigSet_Rx_ACAN_MHU_ADAS02_Nav_SpdLimValue Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_MHU_ADAS02_Nav_SpdLimValue
#define Com_CbkRxTOut_CanConfigSet_Rx_ACAN_MHU_ADAS02_Nav_SpdLimType  Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_MHU_ADAS02_Nav_SpdLimType
#define Com_CbkRxTOut_CanConfigSet_Rx_ACAN_MHU_ADAS02_Nav_SpdLimUnit  Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_MHU_ADAS02_Nav_SpdLimUnit
#define Com_CbkRxTOut_CanConfigSet_Rx_ACAN_MHU_ADAS02_Nav_TSRTrafSign Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_MHU_ADAS02_Nav_TSRTrafSign
#define Com_CbkRxTOut_CanConfigSet_Rx_ACAN_MHU_ADAS02_Nav_CtryType    Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_MHU_ADAS02_Nav_CtryType
#define Com_CbkRxTOut_CanConfigSet_Rx_ACAN_MHU_ADAS03_Nav_TimeMod     Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_MHU_ADAS03_Nav_TimeMod
#define Com_CbkRxTOut_CanConfigSet_Rx_ACAN_MHU_ADAS03_Nav_TimeIndcn   Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_MHU_ADAS03_Nav_TimeIndcn
#define Com_CbkRxTOut_CanConfigSet_Rx_ACAN_ESC_EPB_0x230_Checksum_230 Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_ESC_EPB_0x230_Checksum_230
#define Com_CbkRxTOut_CanConfigSet_Rx_ACAN_ESC_EPB_0x230_RollingCounter_230     Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_ESC_EPB_0x230_RollingCounter_230
#define Com_CbkRxTOut_CanConfigSet_Rx_ACAN_ESC_EPB_0x230_EPB_SysBrkLtsReq       Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_ESC_EPB_0x230_EPB_SysBrkLtsReq
#define Com_CbkRxTOut_CanConfigSet_Rx_ACAN_ESC_EPB_0x230_EPB_SysDspMsgReqV      Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_ESC_EPB_0x230_EPB_SysDspMsgReqV
#define Com_CbkRxTOut_CanConfigSet_Rx_ACAN_ESC_EPB_0x230_EPB_SysStatIndReqV     Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_ESC_EPB_0x230_EPB_SysStatIndReqV
#define Com_CbkRxTOut_CanConfigSet_Rx_ACAN_ESC_EPB_0x230_EPB_SysWrnIndReqV      Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_ESC_EPB_0x230_EPB_SysWrnIndReqV
#define Com_CbkRxTOut_CanConfigSet_Rx_ACAN_ESC_EPB_0x230_EPB_SysWrnIndReq       Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_ESC_EPB_0x230_EPB_SysWrnIndReq
#define Com_CbkRxTOut_CanConfigSet_Rx_ACAN_ESC_EPB_0x230_EPB_SysStatIndReq      Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_ESC_EPB_0x230_EPB_SysStatIndReq
#define Com_CbkRxTOut_CanConfigSet_Rx_ACAN_ESC_EPB_0x230_EPB_SysDspMsgReq       Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_ESC_EPB_0x230_EPB_SysDspMsgReq
#define Com_CbkRxTOut_CanConfigSet_Rx_ACAN_ESC_EPB_0x230_EPB_AVHWrnIndReq       Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_ESC_EPB_0x230_EPB_AVHWrnIndReq
#define Com_CbkRxTOut_CanConfigSet_Rx_ACAN_ESC_EPB_0x230_EPB_AVHWrnIndReqV      Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_ESC_EPB_0x230_EPB_AVHWrnIndReqV
#define Com_CbkRxTOut_CanConfigSet_Rx_ACAN_ESC_EPB_0x230_EPB_AVHStatIndReq      Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_ESC_EPB_0x230_EPB_AVHStatIndReq
#define Com_CbkRxTOut_CanConfigSet_Rx_ACAN_ESC_EPB_0x230_EPB_AVHStatIndReqV     Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_ESC_EPB_0x230_EPB_AVHStatIndReqV
#define Com_CbkRxTOut_CanConfigSet_Rx_ACAN_ESC_EPB_0x230_EPB_AVHFeedbackSts     Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_ESC_EPB_0x230_EPB_AVHFeedbackSts
#define Com_CbkRxTOut_CanConfigSet_Rx_ACAN_ESC_EPB_0x230_EPB_Sts      Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_ESC_EPB_0x230_EPB_Sts
#define Com_CbkRxTOut_CanConfigSet_Rx_ACAN_ESC_EPB_0x230_WCBS_Trailermode_Feedback        Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_ESC_EPB_0x230_WCBS_Trailermode_Feedback
#define Com_CbkRxTOut_CanConfigSet_Rx_ACAN_IBS_ADAS_Info_WCBS_ACC_VLC_Active    Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_IBS_ADAS_Info_WCBS_ACC_VLC_Active
#define Com_CbkRxTOut_CanConfigSet_Rx_ACAN_IBS_ADAS_Info_WCBS_ACC_CDD_Active    Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_IBS_ADAS_Info_WCBS_ACC_CDD_Active
#define Com_CbkRxTOut_CanConfigSet_Rx_ACAN_IBS_ADAS_Info_WCBS_ACC_VLC_Avl       Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_IBS_ADAS_Info_WCBS_ACC_VLC_Avl
#define Com_CbkRxTOut_CanConfigSet_Rx_ACAN_IBS_ADAS_Info_WCBS_ACC_CDD_Avl       Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_IBS_ADAS_Info_WCBS_ACC_CDD_Avl
#define Com_CbkRxTOut_CanConfigSet_Rx_ACAN_IBS_ADAS_Info_WCBS_ACC_VLC_AccInTar  Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_IBS_ADAS_Info_WCBS_ACC_VLC_AccInTar
#define Com_CbkRxTOut_CanConfigSet_Rx_ACAN_IBS_ADAS_Info_WCBS_ABAAtv  Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_IBS_ADAS_Info_WCBS_ABAAtv
#define Com_CbkRxTOut_CanConfigSet_Rx_ACAN_IBS_ADAS_Info_WCBS_ABAAva  Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_IBS_ADAS_Info_WCBS_ABAAva
#define Com_CbkRxTOut_CanConfigSet_Rx_ACAN_IBS_ADAS_Info_WCBS_ABPAtv  Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_IBS_ADAS_Info_WCBS_ABPAtv
#define Com_CbkRxTOut_CanConfigSet_Rx_ACAN_IBS_ADAS_Info_WCBS_ABPAva  Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_IBS_ADAS_Info_WCBS_ABPAva
#define Com_CbkRxTOut_CanConfigSet_Rx_ACAN_IBS_ADAS_Info_WCBS_AWBAtv  Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_IBS_ADAS_Info_WCBS_AWBAtv
#define Com_CbkRxTOut_CanConfigSet_Rx_ACAN_IBS_ADAS_Info_WCBS_AWBAvl  Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_IBS_ADAS_Info_WCBS_AWBAvl
#define Com_CbkRxTOut_CanConfigSet_Rx_ACAN_IBS_ADAS_Info_WCBS_AEBAtv  Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_IBS_ADAS_Info_WCBS_AEBAtv
#define Com_CbkRxTOut_CanConfigSet_Rx_ACAN_IBS_ADAS_Info_WCBS_AEBAva  Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_IBS_ADAS_Info_WCBS_AEBAva
#define Com_CbkRxTOut_CanConfigSet_Rx_ACAN_IBS_ADAS_Info_WCBS_VStandstillSta    Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_IBS_ADAS_Info_WCBS_VStandstillSta
#define Com_CbkRxTOut_CanConfigSet_Rx_ACAN_IBS_ADAS_Info_WCBS_BrkFrcSta         Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_IBS_ADAS_Info_WCBS_BrkFrcSta
#define Com_CbkRxTOut_CanConfigSet_Rx_ACAN_IBS_ADAS_Info_WCBS_ESCDeteACCErroSta Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_IBS_ADAS_Info_WCBS_ESCDeteACCErroSta
#define Com_CbkRxTOut_CanConfigSet_Rx_ACAN_IBS_ADAS_Info_WCBS_APA_VLC_FailureStatus       Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_IBS_ADAS_Info_WCBS_APA_VLC_FailureStatus
#define Com_CbkRxTOut_CanConfigSet_Rx_ACAN_IBS_ADAS_Info_WCBS_APA_VLC_Status    Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_IBS_ADAS_Info_WCBS_APA_VLC_Status
#define Com_CbkRxTOut_CanConfigSet_Rx_ACAN_IBS_ADAS_Info_WCBS_APA_VLC_Available Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_IBS_ADAS_Info_WCBS_APA_VLC_Available
#define Com_CbkRxTOut_CanConfigSet_Rx_ACAN_IBS_ADAS_Info_WCBS_APA_VLC_Active    Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_IBS_ADAS_Info_WCBS_APA_VLC_Active
#define Com_CbkRxTOut_CanConfigSet_Rx_ACAN_IBS_ADAS_Info_WCBS_APA_EmgyBrkAvlb   Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_IBS_ADAS_Info_WCBS_APA_EmgyBrkAvlb
#define Com_CbkRxTOut_CanConfigSet_Rx_ACAN_IBS_ADAS_Info_WCBS_APA_CDD_Active    Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_IBS_ADAS_Info_WCBS_APA_CDD_Active
#define Com_CbkRxTOut_CanConfigSet_Rx_ACAN_IBS_Info_AB_BrkPedalSwSts  Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_IBS_Info_AB_BrkPedalSwSts
#define Com_CbkRxTOut_CanConfigSet_Rx_ACAN_IBS_Info_AB_BrkPedalSwStsV Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_IBS_Info_AB_BrkPedalSwStsV
#define Com_CbkRxTOut_CanConfigSet_Rx_ACAN_IBS_Info_AB_Fault_Status   Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_IBS_Info_AB_Fault_Status
#define Com_CbkRxTOut_CanConfigSet_Rx_ACAN_IBS_Info_AB_IBS_Sys_Fault_Sts        Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_IBS_Info_AB_IBS_Sys_Fault_Sts
#define Com_CbkRxTOut_CanConfigSet_Rx_ACAN_IBS_Info_AB_BrkPedalPct    Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_IBS_Info_AB_BrkPedalPct
#define Com_CbkRxTOut_CanConfigSet_Rx_ACAN_IBS_Info_AB_BrkPedalTravel Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_IBS_Info_AB_BrkPedalTravel
#define Com_CbkRxTOut_CanConfigSet_Rx_ACAN_TBOX_DateTime1_Time_second Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_TBOX_DateTime1_Time_second
#define Com_CbkRxTOut_CanConfigSet_Rx_ACAN_TBOX_DateTime1_GPSSystAtv  Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_TBOX_DateTime1_GPSSystAtv
#define Com_CbkRxTOut_CanConfigSet_Rx_ACAN_TBOX_DateTime1_Time_Minute Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_TBOX_DateTime1_Time_Minute
#define Com_CbkRxTOut_CanConfigSet_Rx_ACAN_TBOX_DateTime1_Time_Hour   Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_TBOX_DateTime1_Time_Hour
#define Com_CbkRxTOut_CanConfigSet_Rx_ACAN_TBOX_DateTime1_Time_Day    Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_TBOX_DateTime1_Time_Day
#define Com_CbkRxTOut_CanConfigSet_Rx_ACAN_TBOX_DateTime1_Time_Month  Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_TBOX_DateTime1_Time_Month
#define Com_CbkRxTOut_CanConfigSet_Rx_ACAN_TBOX_DateTime1_Time_Year   Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_TBOX_DateTime1_Time_Year
#define Com_CbkRxTOut_CanConfigSet_Rx_ACAN_CCU_StsInfo1_CCU_PTCgear_Req_Reserve Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_CCU_StsInfo1_CCU_PTCgear_Req_Reserve
#define Com_CbkRxTOut_CanConfigSet_Rx_ACAN_CCU_StsInfo1_CCU_Anion_Generator_Sts Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_CCU_StsInfo1_CCU_Anion_Generator_Sts
#define Com_CbkRxTOut_CanConfigSet_Rx_ACAN_CCU_StsInfo1_CCU_AC_Req    Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_CCU_StsInfo1_CCU_AC_Req
#define Com_CbkRxTOut_CanConfigSet_Rx_ACAN_CCU_StsInfo1_CCU_Onoff_Sts Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_CCU_StsInfo1_CCU_Onoff_Sts
#define Com_CbkRxTOut_CanConfigSet_Rx_ACAN_CCU_StsInfo1_CCU_AUTO_Status         Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_CCU_StsInfo1_CCU_AUTO_Status
#define Com_CbkRxTOut_CanConfigSet_Rx_ACAN_CCU_StsInfo1_CCU_FrontDefrostSts     Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_CCU_StsInfo1_CCU_FrontDefrostSts
#define Com_CbkRxTOut_CanConfigSet_Rx_ACAN_CCU_StsInfo1_CCU_AC_Sts    Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_CCU_StsInfo1_CCU_AC_Sts
#define Com_CbkRxTOut_CanConfigSet_Rx_ACAN_CCU_StsInfo1_CCU_Circulation_Sts     Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_CCU_StsInfo1_CCU_Circulation_Sts
#define Com_CbkRxTOut_CanConfigSet_Rx_ACAN_CCU_StsInfo1_CCU_ExternalTemperatureFailSts    Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_CCU_StsInfo1_CCU_ExternalTemperatureFailSts
#define Com_CbkRxTOut_CanConfigSet_Rx_ACAN_CCU_StsInfo1_CCU_PTC_Req   Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_CCU_StsInfo1_CCU_PTC_Req
#define Com_CbkRxTOut_CanConfigSet_Rx_ACAN_CCU_StsInfo1_CCU_Temp_Sync_Sts       Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_CCU_StsInfo1_CCU_Temp_Sync_Sts
#define Com_CbkRxTOut_CanConfigSet_Rx_ACAN_CCU_StsInfo1_CCU_evaporator_Temperature        Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_CCU_StsInfo1_CCU_evaporator_Temperature
#define Com_CbkRxTOut_CanConfigSet_Rx_ACAN_CCU_StsInfo1_CCU_PTCPwr_Req          Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_CCU_StsInfo1_CCU_PTCPwr_Req
#define Com_CbkRxTOut_CanConfigSet_Rx_ACAN_CCU_StsInfo1_CCU_CompSpdMEAS_Comp    Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_CCU_StsInfo1_CCU_CompSpdMEAS_Comp
#define Com_CbkRxTOut_CanConfigSet_Rx_ACAN_CCU_StsInfo1_CCU_ExternalTemperature Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_CCU_StsInfo1_CCU_ExternalTemperature
#define Com_CbkRxTOut_CanConfigSet_Rx_ACAN_ESC_YawAngle_0x3E2_Checksum_0x3E2    Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_ESC_YawAngle_0x3E2_Checksum_0x3E2
#define Com_CbkRxTOut_CanConfigSet_Rx_ACAN_ESC_YawAngle_0x3E2_RollingCounter_0x3E2        Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_ESC_YawAngle_0x3E2_RollingCounter_0x3E2
#define Com_CbkRxTOut_CanConfigSet_Rx_ACAN_ESC_YawAngle_0x3E2_ESC_LateralACC_Valid        Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_ESC_YawAngle_0x3E2_ESC_LateralACC_Valid
#define Com_CbkRxTOut_CanConfigSet_Rx_ACAN_ESC_YawAngle_0x3E2_ESC_LongitudeACC_Valid      Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_ESC_YawAngle_0x3E2_ESC_LongitudeACC_Valid
#define Com_CbkRxTOut_CanConfigSet_Rx_ACAN_ESC_YawAngle_0x3E2_ESC_VehDynYawRate_Valid     Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_ESC_YawAngle_0x3E2_ESC_VehDynYawRate_Valid
#define Com_CbkRxTOut_CanConfigSet_Rx_ACAN_ESC_YawAngle_0x3E2_ESC_VehDynYawRate Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_ESC_YawAngle_0x3E2_ESC_VehDynYawRate
#define Com_CbkRxTOut_CanConfigSet_Rx_ACAN_ESC_YawAngle_0x3E2_ESC_LateralACC    Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_ESC_YawAngle_0x3E2_ESC_LateralACC
#define Com_CbkRxTOut_CanConfigSet_Rx_ACAN_ESC_YawAngle_0x3E2_ESC_LongitudeACC  Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_ESC_YawAngle_0x3E2_ESC_LongitudeACC
#define Com_CbkRxTOut_CanConfigSet_Rx_ACAN_MFS_L_Control_Button2_0x3F7_CheckSum_0x3F7     Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_MFS_L_Control_Button2_0x3F7_CheckSum_0x3F7
#define Com_CbkRxTOut_CanConfigSet_Rx_ACAN_MFS_L_Control_Button2_0x3F7_RollingCounter_0x3F7         Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_MFS_L_Control_Button2_0x3F7_RollingCounter_0x3F7
#define Com_CbkRxTOut_CanConfigSet_Rx_ACAN_MFS_L_Control_Button2_0x3F7_MFS_ACC_CruiseSpdIncrease    Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_MFS_L_Control_Button2_0x3F7_MFS_ACC_CruiseSpdIncrease
#define Com_CbkRxTOut_CanConfigSet_Rx_ACAN_MFS_L_Control_Button2_0x3F7_MFS_ACC_CruiseOn_Off         Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_MFS_L_Control_Button2_0x3F7_MFS_ACC_CruiseOn_Off
#define Com_CbkRxTOut_CanConfigSet_Rx_ACAN_MFS_L_Control_Button2_0x3F7_MFS_L2_Failure     Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_MFS_L_Control_Button2_0x3F7_MFS_L2_Failure
#define Com_CbkRxTOut_CanConfigSet_Rx_ACAN_MFS_L_Control_Button2_0x3F7_MFS_ACC_CruiseGapSet         Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_MFS_L_Control_Button2_0x3F7_MFS_ACC_CruiseGapSet
#define Com_CbkRxTOut_CanConfigSet_Rx_ACAN_MFS_L_Control_Button2_0x3F7_MFS_ACC_CruiseSpdDecrease    Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_MFS_L_Control_Button2_0x3F7_MFS_ACC_CruiseSpdDecrease
#define Com_CbkRxTOut_CanConfigSet_Rx_ACAN_MFS_L_Control_Button2_0x3F7_MFS_ACC_CruiseCancel         Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_MFS_L_Control_Button2_0x3F7_MFS_ACC_CruiseCancel
#define Com_CbkRxTOut_CanConfigSet_Rx_ACAN_BCM_DoorState_0x4D4_BCM_CoverAjarStatus        Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_BCM_DoorState_0x4D4_BCM_CoverAjarStatus
#define Com_CbkRxTOut_CanConfigSet_Rx_ACAN_BCM_DoorState_0x4D4_BCM_TrunckAjarStatus       Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_BCM_DoorState_0x4D4_BCM_TrunckAjarStatus
#define Com_CbkRxTOut_CanConfigSet_Rx_ACAN_BCM_DoorState_0x4D4_BCM_DriverSideDoorAjarSts  Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_BCM_DoorState_0x4D4_BCM_DriverSideDoorAjarSts
#define Com_CbkRxTOut_CanConfigSet_Rx_ACAN_BCM_DoorState_0x4D4_BCM_CodriversSideDoorAjarSts         Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_BCM_DoorState_0x4D4_BCM_CodriversSideDoorAjarSts
#define Com_CbkRxTOut_CanConfigSet_Rx_ACAN_BCM_DoorState_0x4D4_BCM_RearLeftDoorAjarStatus Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_BCM_DoorState_0x4D4_BCM_RearLeftDoorAjarStatus
#define Com_CbkRxTOut_CanConfigSet_Rx_ACAN_BCM_DoorState_0x4D4_BCM_RearRightDoorAjarStatus          Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_BCM_DoorState_0x4D4_BCM_RearRightDoorAjarStatus
#define Com_CbkRxTOut_CanConfigSet_Rx_ACAN_BCM_DoorState_0x4D4_BCM_DoorLockStatusRL       Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_BCM_DoorState_0x4D4_BCM_DoorLockStatusRL
#define Com_CbkRxTOut_CanConfigSet_Rx_ACAN_BCM_DoorState_0x4D4_BCM_DoorLockStatusRR       Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_BCM_DoorState_0x4D4_BCM_DoorLockStatusRR
#define Com_CbkRxTOut_CanConfigSet_Rx_ACAN_BCM_DoorState_0x4D4_BCM_DoorLockStatusCodrivres          Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_BCM_DoorState_0x4D4_BCM_DoorLockStatusCodrivres
#define Com_CbkRxTOut_CanConfigSet_Rx_ACAN_BCM_DoorState_0x4D4_BCM_DoorLockStatusDrv      Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_BCM_DoorState_0x4D4_BCM_DoorLockStatusDrv
#define Com_CbkRxTOut_CanConfigSet_Rx_ACAN_BCM_DoorState_0x4D4_BCM_ATWS_St      Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_BCM_DoorState_0x4D4_BCM_ATWS_St
#define Com_CbkRxTOut_CanConfigSet_Rx_ACAN_BCM_DoorState_0x4D4_BCM_TailGateSts  Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_BCM_DoorState_0x4D4_BCM_TailGateSts
#define Com_CbkTxAck_CanConfigSet_Tx_ACAN_ADAS_01_ADAS_01_Checksum    Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_01_ADAS_01_Checksum
#define Com_CbkTxAck_CanConfigSet_Tx_ACAN_ADAS_01_ADAS_01_RollingCounter        Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_01_ADAS_01_RollingCounter
#define Com_CbkTxAck_CanConfigSet_Tx_ACAN_ADAS_01_ADAS_ACC_SpdUnit    Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_01_ADAS_ACC_SpdUnit
#define Com_CbkTxAck_CanConfigSet_Tx_ACAN_ADAS_01_ADAS_ACC_TargetSpeed          Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_01_ADAS_ACC_TargetSpeed
#define Com_CbkTxAck_CanConfigSet_Tx_ACAN_ADAS_01_ADAS_ACC_OperatingSts         Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_01_ADAS_ACC_OperatingSts
#define Com_CbkTxAck_CanConfigSet_Tx_ACAN_ADAS_01_ADAS_ACC_TimeGapLevel         Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_01_ADAS_ACC_TimeGapLevel
#define Com_CbkTxAck_CanConfigSet_Tx_ACAN_ADAS_01_ADAS_ACC_DistanceLevel        Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_01_ADAS_ACC_DistanceLevel
#define Com_CbkTxAck_CanConfigSet_Tx_ACAN_ADAS_01_ADAS_ACC_ObjDispSts Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_01_ADAS_ACC_ObjDispSts
#define Com_CbkTxAck_CanConfigSet_Tx_ACAN_ADAS_01_ADAS_ACC_TakeOverReq          Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_01_ADAS_ACC_TakeOverReq
#define Com_CbkTxAck_CanConfigSet_Tx_ACAN_ADAS_02_ADAS_02_Checksum    Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_02_ADAS_02_Checksum
#define Com_CbkTxAck_CanConfigSet_Tx_ACAN_ADAS_02_ADAS_02_RollingCounter        Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_02_ADAS_02_RollingCounter
#define Com_CbkTxAck_CanConfigSet_Tx_ACAN_ADAS_02_ADAS_LSS_AssidFormResp        Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_02_ADAS_LSS_AssidFormResp
#define Com_CbkTxAck_CanConfigSet_Tx_ACAN_ADAS_02_ADAS_LSS_AngCmdReqPortnValue  Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_02_ADAS_LSS_AngCmdReqPortnValue
#define Com_CbkTxAck_CanConfigSet_Tx_ACAN_ADAS_02_ADAS_EPS_TargetSteeringAngle  Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_02_ADAS_EPS_TargetSteeringAngle
#define Com_CbkTxAck_CanConfigSet_Tx_ACAN_ADAS_02_ADAS_EPS_Vibration_Req        Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_02_ADAS_EPS_Vibration_Req
#define Com_CbkTxAck_CanConfigSet_Tx_ACAN_ADAS_02_ADAS_LSS_VoiceWarn  Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_02_ADAS_LSS_VoiceWarn
#define Com_CbkTxAck_CanConfigSet_Tx_ACAN_ADAS_02_ADAS_LSS_HandsoffWarn         Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_02_ADAS_LSS_HandsoffWarn
#define Com_CbkTxAck_CanConfigSet_Tx_ACAN_ADAS_02_ADAS_LSS_FuncResp   Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_02_ADAS_LSS_FuncResp
#define Com_CbkTxAck_CanConfigSet_Tx_ACAN_ADAS_02_ADAS_EPS_AngReqSts  Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_02_ADAS_EPS_AngReqSts
#define Com_CbkTxAck_CanConfigSet_Tx_ACAN_ADAS_02_ADAS_LSS_LeLineTrackingSts    Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_02_ADAS_LSS_LeLineTrackingSts
#define Com_CbkTxAck_CanConfigSet_Tx_ACAN_ADAS_02_ADAS_LSS_RiLineTrackingSts    Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_02_ADAS_LSS_RiLineTrackingSts
#define Com_CbkTxAck_CanConfigSet_Tx_ACAN_ADAS_03_ADAS_03_Checksum    Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_03_ADAS_03_Checksum
#define Com_CbkTxAck_CanConfigSet_Tx_ACAN_ADAS_03_ADAS_03_RollingCounter        Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_03_ADAS_03_RollingCounter
#define Com_CbkTxAck_CanConfigSet_Tx_ACAN_ADAS_03_ADAS_AccelerationReq          Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_03_ADAS_AccelerationReq
#define Com_CbkTxAck_CanConfigSet_Tx_ACAN_ADAS_03_ADAS_AEB_TgtDecel_ReqValue    Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_03_ADAS_AEB_TgtDecel_ReqValue
#define Com_CbkTxAck_CanConfigSet_Tx_ACAN_ADAS_03_ADAS_MaxSoftAcceleration      Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_03_ADAS_MaxSoftAcceleration
#define Com_CbkTxAck_CanConfigSet_Tx_ACAN_ADAS_03_ADAS_MinSoftAcceleration      Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_03_ADAS_MinSoftAcceleration
#define Com_CbkTxAck_CanConfigSet_Tx_ACAN_ADAS_04_ADAS_IBS_StopReq    Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_04_ADAS_IBS_StopReq
#define Com_CbkTxAck_CanConfigSet_Tx_ACAN_ADAS_04_ADAS_IBS_CarStarting          Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_04_ADAS_IBS_CarStarting
#define Com_CbkTxAck_CanConfigSet_Tx_ACAN_ADAS_04_ADAS_ACC_BrakePreferred       Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_04_ADAS_ACC_BrakePreferred
#define Com_CbkTxAck_CanConfigSet_Tx_ACAN_ADAS_04_ADAS_AEB_AbpReq     Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_04_ADAS_AEB_AbpReq
#define Com_CbkTxAck_CanConfigSet_Tx_ACAN_ADAS_04_ADAS_IBS_EBAReq     Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_04_ADAS_IBS_EBAReq
#define Com_CbkTxAck_CanConfigSet_Tx_ACAN_ADAS_04_ADAS_IBS_MinBreakReq          Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_04_ADAS_IBS_MinBreakReq
#define Com_CbkTxAck_CanConfigSet_Tx_ACAN_ADAS_04_ADAS_VLCShutDownReq Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_04_ADAS_VLCShutDownReq
#define Com_CbkTxAck_CanConfigSet_Tx_ACAN_ADAS_04_ADAS_VLCModeReq     Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_04_ADAS_VLCModeReq
#define Com_CbkTxAck_CanConfigSet_Tx_ACAN_ADAS_04_AEB_AWB_Level       Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_04_AEB_AWB_Level
#define Com_CbkTxAck_CanConfigSet_Tx_ACAN_ADAS_04_AEB_ABA_Req         Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_04_AEB_ABA_Req
#define Com_CbkTxAck_CanConfigSet_Tx_ACAN_ADAS_04_AEB_VehHldReq       Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_04_AEB_VehHldReq
#define Com_CbkTxAck_CanConfigSet_Tx_ACAN_ADAS_04_AEB_TgtDecel_Req    Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_04_AEB_TgtDecel_Req
#define Com_CbkTxAck_CanConfigSet_Tx_ACAN_ADAS_04_AEB_AWB_Req         Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_04_AEB_AWB_Req
#define Com_CbkTxAck_CanConfigSet_Tx_ACAN_ADAS_04_ADAS_AEB_AbaLevel   Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_04_ADAS_AEB_AbaLevel
#define Com_CbkTxAck_CanConfigSet_Tx_ACAN_ADAS_04_ACC_AdtUpperJerkLimit         Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_04_ACC_AdtUpperJerkLimit
#define Com_CbkTxAck_CanConfigSet_Tx_ACAN_ADAS_04_ACC_AdtLowerJerkLimit         Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_04_ACC_AdtLowerJerkLimit
#define Com_CbkTxAck_CanConfigSet_Tx_ACAN_ADAS_06_ADAS_TSR_SWSts      Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_06_ADAS_TSR_SWSts
#define Com_CbkTxAck_CanConfigSet_Tx_ACAN_ADAS_06_TSR_SLWSwtResp      Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_06_TSR_SLWSwtResp
#define Com_CbkTxAck_CanConfigSet_Tx_ACAN_ADAS_06_ADAS_TSR_OperationSts         Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_06_ADAS_TSR_OperationSts
#define Com_CbkTxAck_CanConfigSet_Tx_ACAN_ADAS_06_ADAS_TSR_SpeedLimit Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_06_ADAS_TSR_SpeedLimit
#define Com_CbkTxAck_CanConfigSet_Tx_ACAN_ADAS_06_ADAS_LSS_Available  Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_06_ADAS_LSS_Available
#define Com_CbkTxAck_CanConfigSet_Tx_ACAN_ADAS_06_ADAS_LSS_FunSts     Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_06_ADAS_LSS_FunSts
#define Com_CbkTxAck_CanConfigSet_Tx_ACAN_ADAS_06_ADAS_LSS_ErrSts     Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_06_ADAS_LSS_ErrSts
#define Com_CbkTxAck_CanConfigSet_Tx_ACAN_ADAS_06_ADAS_LSS_WarnFromResp         Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_06_ADAS_LSS_WarnFromResp
#define Com_CbkTxAck_CanConfigSet_Tx_ACAN_ADAS_06_FC_CalibrationSts   Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_06_FC_CalibrationSts
#define Com_CbkTxAck_CanConfigSet_Tx_ACAN_ADAS_06_FC_BlockageSts      Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_06_FC_BlockageSts
#define Com_CbkTxAck_CanConfigSet_Tx_ACAN_ADAS_07_ADAS_APA_OperationSts         Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_07_ADAS_APA_OperationSts
#define Com_CbkTxAck_CanConfigSet_Tx_ACAN_ADAS_07_ADAS_APA_ModeSelect Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_07_ADAS_APA_ModeSelect
#define Com_CbkTxAck_CanConfigSet_Tx_ACAN_ADAS_07_ADAS_APA_SystemSts  Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_07_ADAS_APA_SystemSts
#define Com_CbkTxAck_CanConfigSet_Tx_ACAN_ADAS_07_ADAS_APA_OverspeedAlarm       Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_07_ADAS_APA_OverspeedAlarm
#define Com_CbkTxAck_CanConfigSet_Tx_ACAN_ADAS_07_ADAS_APA_StartParkingReq      Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_07_ADAS_APA_StartParkingReq
#define Com_CbkTxAck_CanConfigSet_Tx_ACAN_ADAS_07_ADAS_APA_RenewParkingReq      Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_07_ADAS_APA_RenewParkingReq
#define Com_CbkTxAck_CanConfigSet_Tx_ACAN_ADAS_07_ADAS_APA_PauseWarning         Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_07_ADAS_APA_PauseWarning
#define Com_CbkTxAck_CanConfigSet_Tx_ACAN_ADAS_07_ADAS_APA_AbortWarning         Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_07_ADAS_APA_AbortWarning
#define Com_CbkTxAck_CanConfigSet_Tx_ACAN_ADAS_07_ADAS_APA_ParkingType          Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_07_ADAS_APA_ParkingType
#define Com_CbkTxAck_CanConfigSet_Tx_ACAN_ADAS_07_ADAS_APA_ParkingDirection     Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_07_ADAS_APA_ParkingDirection
#define Com_CbkTxAck_CanConfigSet_Tx_ACAN_ADAS_07_ADAS_APA_SuggestedID          Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_07_ADAS_APA_SuggestedID
#define Com_CbkTxAck_CanConfigSet_Tx_ACAN_ADAS_08_ADAS_FrontCamera_Fault        Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_08_ADAS_FrontCamera_Fault
#define Com_CbkTxAck_CanConfigSet_Tx_ACAN_ADAS_08_ADAS_RearCamera_Fault         Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_08_ADAS_RearCamera_Fault
#define Com_CbkTxAck_CanConfigSet_Tx_ACAN_ADAS_08_ADAS_LeftCamera_Fault         Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_08_ADAS_LeftCamera_Fault
#define Com_CbkTxAck_CanConfigSet_Tx_ACAN_ADAS_08_ADAS_RightCamera_Fault        Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_08_ADAS_RightCamera_Fault
#define Com_CbkTxAck_CanConfigSet_Tx_ACAN_ADAS_08_ADAS_ECU_Fault      Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_08_ADAS_ECU_Fault
#define Com_CbkTxAck_CanConfigSet_Tx_ACAN_ADAS_08_ACC_TxtInfoForDriver          Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_08_ACC_TxtInfoForDriver
#define Com_CbkTxAck_CanConfigSet_Tx_ACAN_ADAS_08_ACC_DriveoffReq     Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_08_ACC_DriveoffReq
#define Com_CbkTxAck_CanConfigSet_Tx_ACAN_ADAS_Info15_ADAS_AEB_FuncSWResp       Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_Info15_ADAS_AEB_FuncSWResp
#define Com_CbkTxAck_CanConfigSet_Tx_ACAN_ADAS_Info15_AEB_FuncSts     Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_Info15_AEB_FuncSts
#define Com_CbkTxAck_CanConfigSet_Tx_ACAN_ADAS_Info15_AEB_VehActive   Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_Info15_AEB_VehActive
#define Com_CbkTxAck_CanConfigSet_Tx_ACAN_ADAS_Info15_AEB_VRUActive   Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_Info15_AEB_VRUActive
#define Com_CbkTxAck_CanConfigSet_Tx_ACAN_ADAS_Info15_AEB_ErrorSts    Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_Info15_AEB_ErrorSts
#define Com_CbkTxAck_CanConfigSet_Tx_ACAN_ADAS_Info15_AEB_FCW_SnvtyResp         Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_Info15_AEB_FCW_SnvtyResp
#define Com_CbkTxAck_CanConfigSet_Tx_ACAN_ADAS_Info15_TSR_TrafSign    Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_Info15_TSR_TrafSign
#define Com_CbkTxAck_CanConfigSet_Tx_ACAN_ADAS_Info15_TSR_SpdAssistInfoDisp     Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_Info15_TSR_SpdAssistInfoDisp
#define Com_CbkTxAck_CanConfigSet_Tx_ACAN_ADAS_Info15_TSR_Warning_offset        Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_Info15_TSR_Warning_offset
#define Com_CbkTxAck_CanConfigSet_Tx_ACAN_ADAS_Info15_TSR_SLWVisualWarn         Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_Info15_TSR_SLWVisualWarn
#define Com_CbkTxAck_CanConfigSet_Tx_ACAN_ADAS_Info15_TSR_SLWVoiceWarn          Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_Info15_TSR_SLWVoiceWarn
#define Com_CbkTxAck_CanConfigSet_Tx_ACAN_ADAS_Info15_AEB_FCW_Warning Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_Info15_AEB_FCW_Warning
#define Com_CbkTxAck_CanConfigSet_Tx_ACAN_ADAS_Info17_ADAS_APA_Soundremind      Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_Info17_ADAS_APA_Soundremind
#define Com_CbkTxAck_CanConfigSet_Tx_ACAN_ADAS_Info17_ADAS_APA_ParkingModeReq   Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_Info17_ADAS_APA_ParkingModeReq
#define Com_CbkTxAck_CanConfigSet_Tx_ACAN_ADAS_Info17_ADAS_APA_OtherWarning     Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_Info17_ADAS_APA_OtherWarning
#define Com_CbkTxAck_CanConfigSet_Tx_ACAN_ADAS_Info17_ADAS_APA_RemindTxt1       Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_Info17_ADAS_APA_RemindTxt1
#define Com_CbkTxAck_CanConfigSet_Tx_ACAN_ADAS_Info17_ADAS_APA_RemindTxt2       Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_Info17_ADAS_APA_RemindTxt2
#define Com_CbkTxAck_CanConfigSet_Tx_ACAN_ADAS_Info17_ADAS_APA_LightReq         Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_Info17_ADAS_APA_LightReq
#define Com_CbkTxAck_CanConfigSet_Tx_ACAN_ADAS_Info17_ADAS_APA_SearchingWarning Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_Info17_ADAS_APA_SearchingWarning
#define Com_CbkTxAck_CanConfigSet_Tx_ACAN_ADAS_Info23_CheckSum_1F8    Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_Info23_CheckSum_1F8
#define Com_CbkTxAck_CanConfigSet_Tx_ACAN_ADAS_Info23_RollingCounter_1F8        Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_Info23_RollingCounter_1F8
#define Com_CbkTxAck_CanConfigSet_Tx_ACAN_ADAS_Info23_APA_EPS_AngReqSts         Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_Info23_APA_EPS_AngReqSts
#define Com_CbkTxAck_CanConfigSet_Tx_ACAN_ADAS_Info23_APA_EPS_TargetSteeringAngle         Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_Info23_APA_EPS_TargetSteeringAngle
#define Com_CbkTxAck_CanConfigSet_Tx_ACAN_ADAS_Info23_ADAS_APA_BrakeModeSts     Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_Info23_ADAS_APA_BrakeModeSts
#define Com_CbkTxAck_CanConfigSet_Tx_ACAN_ADAS_Info23_APA_WCBS_BrakeFunctionMode          Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_Info23_APA_WCBS_BrakeFunctionMode
#define Com_CbkTxAck_CanConfigSet_Tx_ACAN_ADAS_Info23_APA_WCBS_BrakeMode        Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_Info23_APA_WCBS_BrakeMode
#define Com_CbkTxAck_CanConfigSet_Tx_ACAN_ADAS_Info23_APA_WCBS_TargetStopDistance         Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_Info23_APA_WCBS_TargetStopDistance
#define Com_CbkTxAck_CanConfigSet_Tx_ACAN_ADAS_Info23_APA_WCBS_ExpectedGearPosition       Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_Info23_APA_WCBS_ExpectedGearPosition
#define Com_CbkTxAck_CanConfigSet_Tx_ACAN_ADAS_Info23_APA_WCBS_SpeedLimitation  Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_Info23_APA_WCBS_SpeedLimitation
#define Com_CbkTxAck_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info1_APA_slot_1        Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info1_APA_slot_1
#define Com_CbkTxAck_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info1_APA_slot_ID_1_P0_X          Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info1_APA_slot_ID_1_P0_X
#define Com_CbkTxAck_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info1_APA_slot_ID_1_P0_Y          Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info1_APA_slot_ID_1_P0_Y
#define Com_CbkTxAck_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info1_APA_slot_ID_1_P1_X          Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info1_APA_slot_ID_1_P1_X
#define Com_CbkTxAck_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info1_APA_slot_ID_1_P1_Y          Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info1_APA_slot_ID_1_P1_Y
#define Com_CbkTxAck_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info3_APA_slot_2        Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info3_APA_slot_2
#define Com_CbkTxAck_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info3_APA_slot_ID_2_P0_X          Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info3_APA_slot_ID_2_P0_X
#define Com_CbkTxAck_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info3_APA_slot_ID_2_P0_Y          Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info3_APA_slot_ID_2_P0_Y
#define Com_CbkTxAck_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info3_APA_slot_ID_2_P1_X          Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info3_APA_slot_ID_2_P1_X
#define Com_CbkTxAck_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info3_APA_slot_ID_2_P1_Y          Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info3_APA_slot_ID_2_P1_Y
#define Com_CbkTxAck_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info5_APA_slot_3        Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info5_APA_slot_3
#define Com_CbkTxAck_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info5_APA_slot_ID_3_P0_X          Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info5_APA_slot_ID_3_P0_X
#define Com_CbkTxAck_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info5_APA_slot_ID_3_P0_Y          Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info5_APA_slot_ID_3_P0_Y
#define Com_CbkTxAck_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info5_APA_slot_ID_3_P1_X          Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info5_APA_slot_ID_3_P1_X
#define Com_CbkTxAck_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info5_APA_slot_ID_3_P1_Y          Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info5_APA_slot_ID_3_P1_Y
#define Com_CbkTxAck_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info7_APA_slot_4        Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info7_APA_slot_4
#define Com_CbkTxAck_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info7_APA_slot_ID_4_P0_X          Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info7_APA_slot_ID_4_P0_X
#define Com_CbkTxAck_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info7_APA_slot_ID_4_P0_Y          Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info7_APA_slot_ID_4_P0_Y
#define Com_CbkTxAck_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info7_APA_slot_ID_4_P1_X          Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info7_APA_slot_ID_4_P1_X
#define Com_CbkTxAck_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info7_APA_slot_ID_4_P1_Y          Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info7_APA_slot_ID_4_P1_Y
#define Com_CbkTxAck_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info9_APA_slot_5        Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info9_APA_slot_5
#define Com_CbkTxAck_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info9_APA_slot_ID_5_P0_X          Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info9_APA_slot_ID_5_P0_X
#define Com_CbkTxAck_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info9_APA_slot_ID_5_P0_Y          Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info9_APA_slot_ID_5_P0_Y
#define Com_CbkTxAck_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info9_APA_slot_ID_5_P1_X          Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info9_APA_slot_ID_5_P1_X
#define Com_CbkTxAck_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info9_APA_slot_ID_5_P1_Y          Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info9_APA_slot_ID_5_P1_Y
#define Com_CbkTxAck_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info11_APA_slot_6       Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info11_APA_slot_6
#define Com_CbkTxAck_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info11_APA_slot_ID_6_P0_X         Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info11_APA_slot_ID_6_P0_X
#define Com_CbkTxAck_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info11_APA_slot_ID_6_P0_Y         Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info11_APA_slot_ID_6_P0_Y
#define Com_CbkTxAck_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info11_APA_slot_ID_6_P1_X         Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info11_APA_slot_ID_6_P1_X
#define Com_CbkTxAck_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info11_APA_slot_ID_6_P1_Y         Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info11_APA_slot_ID_6_P1_Y
#define Com_CbkTxAck_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info13_APA_slot_7       Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info13_APA_slot_7
#define Com_CbkTxAck_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info13_APA_slot_ID_7_P0_X         Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info13_APA_slot_ID_7_P0_X
#define Com_CbkTxAck_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info13_APA_slot_ID_7_P0_Y         Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info13_APA_slot_ID_7_P0_Y
#define Com_CbkTxAck_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info13_APA_slot_ID_7_P1_X         Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info13_APA_slot_ID_7_P1_X
#define Com_CbkTxAck_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info13_APA_slot_ID_7_P1_Y         Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info13_APA_slot_ID_7_P1_Y
#define Com_CbkTxAck_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info15_APA_slot_8       Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info15_APA_slot_8
#define Com_CbkTxAck_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info15_APA_slot_ID_8_P0_X         Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info15_APA_slot_ID_8_P0_X
#define Com_CbkTxAck_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info15_APA_slot_ID_8_P0_Y         Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info15_APA_slot_ID_8_P0_Y
#define Com_CbkTxAck_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info15_APA_slot_ID_8_P1_X         Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info15_APA_slot_ID_8_P1_X
#define Com_CbkTxAck_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info15_APA_slot_ID_8_P1_Y         Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info15_APA_slot_ID_8_P1_Y
#define Com_CbkTxAck_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info17_APA_slot_9       Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info17_APA_slot_9
#define Com_CbkTxAck_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info17_APA_slot_ID_9_P0_X         Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info17_APA_slot_ID_9_P0_X
#define Com_CbkTxAck_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info17_APA_slot_ID_9_P0_Y         Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info17_APA_slot_ID_9_P0_Y
#define Com_CbkTxAck_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info17_APA_slot_ID_9_P1_X         Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info17_APA_slot_ID_9_P1_X
#define Com_CbkTxAck_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info17_APA_slot_ID_9_P1_Y         Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info17_APA_slot_ID_9_P1_Y
#define Com_CbkTxAck_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info19_APA_slot_10      Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info19_APA_slot_10
#define Com_CbkTxAck_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info19_APA_slot_ID_10_P0_X        Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info19_APA_slot_ID_10_P0_X
#define Com_CbkTxAck_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info19_APA_slot_ID_10_P0_Y        Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info19_APA_slot_ID_10_P0_Y
#define Com_CbkTxAck_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info19_APA_slot_ID_10_P1_X        Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info19_APA_slot_ID_10_P1_X
#define Com_CbkTxAck_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info19_APA_slot_ID_10_P1_Y        Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info19_APA_slot_ID_10_P1_Y
#define Com_CbkTxAck_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info21_APA_slot_11      Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info21_APA_slot_11
#define Com_CbkTxAck_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info21_APA_slot_ID_11_P0_X        Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info21_APA_slot_ID_11_P0_X
#define Com_CbkTxAck_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info21_APA_slot_ID_11_P0_Y        Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info21_APA_slot_ID_11_P0_Y
#define Com_CbkTxAck_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info21_APA_slot_ID_11_P1_X        Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info21_APA_slot_ID_11_P1_X
#define Com_CbkTxAck_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info21_APA_slot_ID_11_P1_Y        Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info21_APA_slot_ID_11_P1_Y
#define Com_CbkTxAck_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info23_APA_slot_12      Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info23_APA_slot_12
#define Com_CbkTxAck_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info23_APA_slot_ID_12_P0_X        Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info23_APA_slot_ID_12_P0_X
#define Com_CbkTxAck_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info23_APA_slot_ID_12_P0_Y        Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info23_APA_slot_ID_12_P0_Y
#define Com_CbkTxAck_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info23_APA_slot_ID_12_P1_X        Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info23_APA_slot_ID_12_P1_X
#define Com_CbkTxAck_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info23_APA_slot_ID_12_P1_Y        Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info23_APA_slot_ID_12_P1_Y
#define Com_CbkTxAck_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info2_APA_slot_ID_1_Type          Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info2_APA_slot_ID_1_Type
#define Com_CbkTxAck_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info2_APA_slot_ID_1_P2_X          Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info2_APA_slot_ID_1_P2_X
#define Com_CbkTxAck_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info2_APA_slot_ID_1_P2_Y          Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info2_APA_slot_ID_1_P2_Y
#define Com_CbkTxAck_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info2_APA_slot_ID_1_P3_X          Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info2_APA_slot_ID_1_P3_X
#define Com_CbkTxAck_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info2_APA_slot_ID_1_P3_Y          Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info2_APA_slot_ID_1_P3_Y
#define Com_CbkTxAck_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info4_APA_slot_ID_2_Type          Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info4_APA_slot_ID_2_Type
#define Com_CbkTxAck_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info4_APA_slot_ID_2_P2_X          Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info4_APA_slot_ID_2_P2_X
#define Com_CbkTxAck_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info4_APA_slot_ID_2_P2_Y          Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info4_APA_slot_ID_2_P2_Y
#define Com_CbkTxAck_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info4_APA_slot_ID_2_P3_X          Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info4_APA_slot_ID_2_P3_X
#define Com_CbkTxAck_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info4_APA_slot_ID_2_P3_Y          Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info4_APA_slot_ID_2_P3_Y
#define Com_CbkTxAck_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info6_APA_slot_ID_3_Type          Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info6_APA_slot_ID_3_Type
#define Com_CbkTxAck_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info6_APA_slot_ID_3_P2_X          Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info6_APA_slot_ID_3_P2_X
#define Com_CbkTxAck_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info6_APA_slot_ID_3_P2_Y          Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info6_APA_slot_ID_3_P2_Y
#define Com_CbkTxAck_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info6_APA_slot_ID_3_P3_X          Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info6_APA_slot_ID_3_P3_X
#define Com_CbkTxAck_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info6_APA_slot_ID_3_P3_Y          Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info6_APA_slot_ID_3_P3_Y
#define Com_CbkTxAck_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info8_APA_slot_ID_4_Type          Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info8_APA_slot_ID_4_Type
#define Com_CbkTxAck_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info8_APA_slot_ID_4_P2_X          Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info8_APA_slot_ID_4_P2_X
#define Com_CbkTxAck_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info8_APA_slot_ID_4_P2_Y          Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info8_APA_slot_ID_4_P2_Y
#define Com_CbkTxAck_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info8_APA_slot_ID_4_P3_X          Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info8_APA_slot_ID_4_P3_X
#define Com_CbkTxAck_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info8_APA_slot_ID_4_P3_Y          Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info8_APA_slot_ID_4_P3_Y
#define Com_CbkTxAck_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info10_APA_slot_ID_5_Type         Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info10_APA_slot_ID_5_Type
#define Com_CbkTxAck_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info10_APA_slot_ID_5_P2_X         Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info10_APA_slot_ID_5_P2_X
#define Com_CbkTxAck_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info10_APA_slot_ID_5_P2_Y         Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info10_APA_slot_ID_5_P2_Y
#define Com_CbkTxAck_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info10_APA_slot_ID_5_P3_X         Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info10_APA_slot_ID_5_P3_X
#define Com_CbkTxAck_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info10_APA_slot_ID_5_P3_Y         Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info10_APA_slot_ID_5_P3_Y
#define Com_CbkTxAck_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info12_APA_slot_ID_6_Type         Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info12_APA_slot_ID_6_Type
#define Com_CbkTxAck_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info12_APA_slot_ID_6_P2_X         Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info12_APA_slot_ID_6_P2_X
#define Com_CbkTxAck_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info12_APA_slot_ID_6_P2_Y         Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info12_APA_slot_ID_6_P2_Y
#define Com_CbkTxAck_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info12_APA_slot_ID_6_P3_X         Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info12_APA_slot_ID_6_P3_X
#define Com_CbkTxAck_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info12_APA_slot_ID_6_P3_Y         Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info12_APA_slot_ID_6_P3_Y
#define Com_CbkTxAck_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info14_APA_slot_ID_7_Type         Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info14_APA_slot_ID_7_Type
#define Com_CbkTxAck_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info14_APA_slot_ID_7_P2_X         Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info14_APA_slot_ID_7_P2_X
#define Com_CbkTxAck_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info14_APA_slot_ID_7_P2_Y         Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info14_APA_slot_ID_7_P2_Y
#define Com_CbkTxAck_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info14_APA_slot_ID_7_P3_X         Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info14_APA_slot_ID_7_P3_X
#define Com_CbkTxAck_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info14_APA_slot_ID_7_P3_Y         Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info14_APA_slot_ID_7_P3_Y
#define Com_CbkTxAck_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info16_APA_slot_ID_8_Type         Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info16_APA_slot_ID_8_Type
#define Com_CbkTxAck_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info16_APA_slot_ID_8_P2_X         Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info16_APA_slot_ID_8_P2_X
#define Com_CbkTxAck_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info16_APA_slot_ID_8_P2_Y         Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info16_APA_slot_ID_8_P2_Y
#define Com_CbkTxAck_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info16_APA_slot_ID_8_P3_X         Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info16_APA_slot_ID_8_P3_X
#define Com_CbkTxAck_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info16_APA_slot_ID_8_P3_Y         Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info16_APA_slot_ID_8_P3_Y
#define Com_CbkTxAck_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info18_APA_slot_ID_9_Type         Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info18_APA_slot_ID_9_Type
#define Com_CbkTxAck_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info18_APA_slot_ID_9_P2_X         Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info18_APA_slot_ID_9_P2_X
#define Com_CbkTxAck_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info18_APA_slot_ID_9_P2_Y         Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info18_APA_slot_ID_9_P2_Y
#define Com_CbkTxAck_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info18_APA_slot_ID_9_P3_X         Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info18_APA_slot_ID_9_P3_X
#define Com_CbkTxAck_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info18_APA_slot_ID_9_P3_Y         Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info18_APA_slot_ID_9_P3_Y
#define Com_CbkTxAck_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info20_APA_slot_ID_10_Type        Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info20_APA_slot_ID_10_Type
#define Com_CbkTxAck_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info20_APA_slot_ID_10_P2_X        Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info20_APA_slot_ID_10_P2_X
#define Com_CbkTxAck_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info20_APA_slot_ID_10_P2_Y        Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info20_APA_slot_ID_10_P2_Y
#define Com_CbkTxAck_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info20_APA_slot_ID_10_P3_X        Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info20_APA_slot_ID_10_P3_X
#define Com_CbkTxAck_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info20_APA_slot_ID_10_P3_Y        Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info20_APA_slot_ID_10_P3_Y
#define Com_CbkTxAck_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info22_APA_slot_ID_11_Type        Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info22_APA_slot_ID_11_Type
#define Com_CbkTxAck_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info22_APA_slot_ID_11_P2_X        Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info22_APA_slot_ID_11_P2_X
#define Com_CbkTxAck_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info22_APA_slot_ID_11_P2_Y        Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info22_APA_slot_ID_11_P2_Y
#define Com_CbkTxAck_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info22_APA_slot_ID_11_P3_X        Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info22_APA_slot_ID_11_P3_X
#define Com_CbkTxAck_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info22_APA_slot_ID_11_P3_Y        Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info22_APA_slot_ID_11_P3_Y
#define Com_CbkTxAck_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info24_APA_slot_ID_12_Type        Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info24_APA_slot_ID_12_Type
#define Com_CbkTxAck_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info24_APA_slot_ID_12_P2_X        Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info24_APA_slot_ID_12_P2_X
#define Com_CbkTxAck_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info24_APA_slot_ID_12_P2_Y        Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info24_APA_slot_ID_12_P2_Y
#define Com_CbkTxAck_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info24_APA_slot_ID_12_P3_X        Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info24_APA_slot_ID_12_P3_X
#define Com_CbkTxAck_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info24_APA_slot_ID_12_P3_Y        Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info24_APA_slot_ID_12_P3_Y
#define Com_CbkTxAck_CanConfigSet_Tx_ACAN_ADAS_Info20_APA_FrontSystemSts        Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_Info20_APA_FrontSystemSts
#define Com_CbkTxAck_CanConfigSet_Tx_ACAN_ADAS_Info20_APA_RearSystemSts         Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_Info20_APA_RearSystemSts
#define Com_CbkTxAck_CanConfigSet_Tx_ACAN_ADAS_Info20_APA_ChimeRequest          Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_Info20_APA_ChimeRequest
#define Com_CbkTxAck_CanConfigSet_Tx_ACAN_ADAS_Info20_APA_FRegion1ObjectSts     Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_Info20_APA_FRegion1ObjectSts
#define Com_CbkTxAck_CanConfigSet_Tx_ACAN_ADAS_Info20_APA_FRegion2ObjectSts     Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_Info20_APA_FRegion2ObjectSts
#define Com_CbkTxAck_CanConfigSet_Tx_ACAN_ADAS_Info20_APA_FRegion3ObjectSts     Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_Info20_APA_FRegion3ObjectSts
#define Com_CbkTxAck_CanConfigSet_Tx_ACAN_ADAS_Info20_APA_FRegion4ObjectSts     Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_Info20_APA_FRegion4ObjectSts
#define Com_CbkTxAck_CanConfigSet_Tx_ACAN_ADAS_Info20_APA_FrontExtenedDistance  Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_Info20_APA_FrontExtenedDistance
#define Com_CbkTxAck_CanConfigSet_Tx_ACAN_ADAS_Info20_APA_ParkAssistRRegion1ObjectSts     Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_Info20_APA_ParkAssistRRegion1ObjectSts
#define Com_CbkTxAck_CanConfigSet_Tx_ACAN_ADAS_Info20_APA_ParkAssistRRegion2ObjectSts     Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_Info20_APA_ParkAssistRRegion2ObjectSts
#define Com_CbkTxAck_CanConfigSet_Tx_ACAN_ADAS_Info20_APA_ParkAssistRRegion3ObjectSts     Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_Info20_APA_ParkAssistRRegion3ObjectSts
#define Com_CbkTxAck_CanConfigSet_Tx_ACAN_ADAS_Info20_APA_ParkAssistRRegion4ObjectSts     Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_Info20_APA_ParkAssistRRegion4ObjectSts
#define Com_CbkTxAck_CanConfigSet_Tx_ACAN_ADAS_Info20_APA_ParkAssistRExtenedDistance      Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_Info20_APA_ParkAssistRExtenedDistance
#define Com_CbkTxAck_CanConfigSet_Tx_ACAN_ADAS_Info21_ADAS_USS_FaultFLI         Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_Info21_ADAS_USS_FaultFLI
#define Com_CbkTxAck_CanConfigSet_Tx_ACAN_ADAS_Info21_ADAS_USS_FaultFRI         Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_Info21_ADAS_USS_FaultFRI
#define Com_CbkTxAck_CanConfigSet_Tx_ACAN_ADAS_Info21_ADAS_USS_FaultFLO         Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_Info21_ADAS_USS_FaultFLO
#define Com_CbkTxAck_CanConfigSet_Tx_ACAN_ADAS_Info21_ADAS_USS_FaultFRO         Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_Info21_ADAS_USS_FaultFRO
#define Com_CbkTxAck_CanConfigSet_Tx_ACAN_ADAS_Info21_ADAS_USS_FaultFLS         Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_Info21_ADAS_USS_FaultFLS
#define Com_CbkTxAck_CanConfigSet_Tx_ACAN_ADAS_Info21_ADAS_USS_FaultFRS         Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_Info21_ADAS_USS_FaultFRS
#define Com_CbkTxAck_CanConfigSet_Tx_ACAN_ADAS_Info21_FLS_ExtenedDistance       Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_Info21_FLS_ExtenedDistance
#define Com_CbkTxAck_CanConfigSet_Tx_ACAN_ADAS_Info21_FRS_ExtenedDistance       Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_Info21_FRS_ExtenedDistance
#define Com_CbkTxAck_CanConfigSet_Tx_ACAN_ADAS_Info21_FLC_ExtenedDistance       Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_Info21_FLC_ExtenedDistance
#define Com_CbkTxAck_CanConfigSet_Tx_ACAN_ADAS_Info21_FLM_ExtenedDistance       Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_Info21_FLM_ExtenedDistance
#define Com_CbkTxAck_CanConfigSet_Tx_ACAN_ADAS_Info21_FRM_ExtenedDistance       Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_Info21_FRM_ExtenedDistance
#define Com_CbkTxAck_CanConfigSet_Tx_ACAN_ADAS_Info21_FRC_ExtenedDistance       Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_Info21_FRC_ExtenedDistance
#define Com_CbkTxAck_CanConfigSet_Tx_ACAN_ADAS_Info22_ADAS_USS_FaultRLI         Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_Info22_ADAS_USS_FaultRLI
#define Com_CbkTxAck_CanConfigSet_Tx_ACAN_ADAS_Info22_ADAS_USS_FaultRLO         Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_Info22_ADAS_USS_FaultRLO
#define Com_CbkTxAck_CanConfigSet_Tx_ACAN_ADAS_Info22_ADAS_USS_FaultRRI         Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_Info22_ADAS_USS_FaultRRI
#define Com_CbkTxAck_CanConfigSet_Tx_ACAN_ADAS_Info22_ADAS_USS_FaultRRO         Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_Info22_ADAS_USS_FaultRRO
#define Com_CbkTxAck_CanConfigSet_Tx_ACAN_ADAS_Info22_ADAS_USS_FaultRLS         Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_Info22_ADAS_USS_FaultRLS
#define Com_CbkTxAck_CanConfigSet_Tx_ACAN_ADAS_Info22_ADAS_USS_FaultRRS         Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_Info22_ADAS_USS_FaultRRS
#define Com_CbkTxAck_CanConfigSet_Tx_ACAN_ADAS_Info22_RLS_ExtenedDistance       Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_Info22_RLS_ExtenedDistance
#define Com_CbkTxAck_CanConfigSet_Tx_ACAN_ADAS_Info22_RRS_ExtenedDistance       Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_Info22_RRS_ExtenedDistance
#define Com_CbkTxAck_CanConfigSet_Tx_ACAN_ADAS_Info22_RLC_ExtenedDistance       Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_Info22_RLC_ExtenedDistance
#define Com_CbkTxAck_CanConfigSet_Tx_ACAN_ADAS_Info22_RLM_ExtenedDistance       Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_Info22_RLM_ExtenedDistance
#define Com_CbkTxAck_CanConfigSet_Tx_ACAN_ADAS_Info22_RRM_ExtenedDistance       Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_Info22_RRM_ExtenedDistance
#define Com_CbkTxAck_CanConfigSet_Tx_ACAN_ADAS_Info22_RRC_ExtenedDistance       Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_Info22_RRC_ExtenedDistance
#define Com_CbkTxAck_Tcp_SendSignal                         Rte_COMCbkTAck_Com_Tcp_SendSignal
#define Com_CbkTxAck_Udp_SendSignal                         Rte_COMCbkTAck_Com_Udp_SendSignal
#define Com_CbkTxAck_Udp_SendSignal_1501                    Rte_COMCbkTAck_Com_Udp_SendSignal_1501
#define Com_CbkTxAck_Udp_SendSignal_1502                    Rte_COMCbkTAck_Com_Udp_SendSignal_1502
#define Com_CbkTxAck_Udp_SendSignal_1503                    Rte_COMCbkTAck_Com_Udp_SendSignal_1503
#define Com_CbkTxAck_Udp_SendSignal_1504                    Rte_COMCbkTAck_Com_Udp_SendSignal_1504
#define Com_CbkTxAck_Udp_SendSignal_1505                    Rte_COMCbkTAck_Com_Udp_SendSignal_1505
#define Com_CbkTxAck_Udp_SendSignal_1506                    Rte_COMCbkTAck_Com_Udp_SendSignal_1506
#define Com_CbkTxAck_Udp_SendSignal_1507                    Rte_COMCbkTAck_Com_Udp_SendSignal_1507



#endif


