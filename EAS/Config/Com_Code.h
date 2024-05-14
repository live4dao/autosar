/*  BEGIN_FILE_HDR
********************************************************************************
*   File Name       : Com_Code.h
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
*   V1.0.2_3.5.5_AZ240046       10/05/2024    Eas           N/A          N/A
*
********************************************************************************
* END_FILE_HDR*/
#ifndef COM_CODE_H
#define COM_CODE_H

/*******************************************************************************
*   Includes
*******************************************************************************/
#include "Com_Types.h"
#include "Com_Lcfg.h"


#define COM_START_SEC_CODE
#include "MemMap.h"


extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Tx_ACAN_ADAS_01_ADAS_01_Checksum
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Tx_ACAN_ADAS_01_ADAS_01_RollingCounter
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Tx_ACAN_ADAS_01_ADAS_ACC_SpdUnit
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Tx_ACAN_ADAS_01_ADAS_ACC_TargetSpeed
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Tx_ACAN_ADAS_01_ADAS_ACC_OperatingSts
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Tx_ACAN_ADAS_01_ADAS_ACC_TimeGapLevel
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Tx_ACAN_ADAS_01_ADAS_ACC_DistanceLevel
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Tx_ACAN_ADAS_01_ADAS_ACC_ObjDispSts
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Tx_ACAN_ADAS_01_ADAS_ACC_TakeOverReq
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Tx_ACAN_ADAS_02_ADAS_02_Checksum
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Tx_ACAN_ADAS_02_ADAS_02_RollingCounter
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Tx_ACAN_ADAS_02_ADAS_LSS_AssidFormResp
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Tx_ACAN_ADAS_02_ADAS_LSS_AngCmdReqPortnValue
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Tx_ACAN_ADAS_02_ADAS_EPS_TargetSteeringAngle
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Tx_ACAN_ADAS_02_ADAS_EPS_Vibration_Req
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Tx_ACAN_ADAS_02_ADAS_LSS_VoiceWarn
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Tx_ACAN_ADAS_02_ADAS_LSS_HandsoffWarn
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Tx_ACAN_ADAS_02_ADAS_LSS_FuncResp
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Tx_ACAN_ADAS_02_ADAS_EPS_AngReqSts
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Tx_ACAN_ADAS_02_ADAS_LSS_LeLineTrackingSts
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Tx_ACAN_ADAS_02_ADAS_LSS_RiLineTrackingSts
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Tx_ACAN_ADAS_03_ADAS_03_Checksum
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Tx_ACAN_ADAS_03_ADAS_03_RollingCounter
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Tx_ACAN_ADAS_03_ADAS_AccelerationReq
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Tx_ACAN_ADAS_03_ADAS_AEB_TgtDecel_ReqValue
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Tx_ACAN_ADAS_03_ADAS_MaxSoftAcceleration
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Tx_ACAN_ADAS_03_ADAS_MinSoftAcceleration
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Tx_ACAN_ADAS_04_ADAS_IBS_StopReq
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Tx_ACAN_ADAS_04_ADAS_IBS_CarStarting
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Tx_ACAN_ADAS_04_ADAS_ACC_BrakePreferred
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Tx_ACAN_ADAS_04_ADAS_AEB_AbpReq
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Tx_ACAN_ADAS_04_ADAS_IBS_EBAReq
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Tx_ACAN_ADAS_04_ADAS_IBS_MinBreakReq
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Tx_ACAN_ADAS_04_ADAS_VLCShutDownReq
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Tx_ACAN_ADAS_04_ADAS_VLCModeReq
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Tx_ACAN_ADAS_04_AEB_AWB_Level
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Tx_ACAN_ADAS_04_AEB_ABA_Req
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Tx_ACAN_ADAS_04_AEB_VehHldReq
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Tx_ACAN_ADAS_04_AEB_TgtDecel_Req
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Tx_ACAN_ADAS_04_AEB_AWB_Req
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Tx_ACAN_ADAS_04_ADAS_AEB_AbaLevel
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Tx_ACAN_ADAS_04_ACC_AdtUpperJerkLimit
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Tx_ACAN_ADAS_04_ACC_AdtLowerJerkLimit
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Tx_ACAN_ADAS_06_ADAS_TSR_SWSts
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Tx_ACAN_ADAS_06_TSR_SLWSwtResp
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Tx_ACAN_ADAS_06_ADAS_TSR_OperationSts
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Tx_ACAN_ADAS_06_ADAS_TSR_SpeedLimit
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Tx_ACAN_ADAS_06_ADAS_LSS_Available
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Tx_ACAN_ADAS_06_ADAS_LSS_FunSts
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Tx_ACAN_ADAS_06_ADAS_LSS_ErrSts
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Tx_ACAN_ADAS_06_ADAS_LSS_WarnFromResp
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Tx_ACAN_ADAS_06_FC_CalibrationSts
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Tx_ACAN_ADAS_06_FC_BlockageSts
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Tx_ACAN_ADAS_07_ADAS_APA_OperationSts
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Tx_ACAN_ADAS_07_ADAS_APA_ModeSelect
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Tx_ACAN_ADAS_07_ADAS_APA_SystemSts
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Tx_ACAN_ADAS_07_ADAS_APA_OverspeedAlarm
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Tx_ACAN_ADAS_07_ADAS_APA_StartParkingReq
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Tx_ACAN_ADAS_07_ADAS_APA_RenewParkingReq
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Tx_ACAN_ADAS_07_ADAS_APA_PauseWarning
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Tx_ACAN_ADAS_07_ADAS_APA_AbortWarning
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Tx_ACAN_ADAS_07_ADAS_APA_ParkingType
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Tx_ACAN_ADAS_07_ADAS_APA_ParkingDirection
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Tx_ACAN_ADAS_07_ADAS_APA_SuggestedID
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Tx_ACAN_ADAS_08_ADAS_FrontCamera_Fault
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Tx_ACAN_ADAS_08_ADAS_RearCamera_Fault
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Tx_ACAN_ADAS_08_ADAS_LeftCamera_Fault
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Tx_ACAN_ADAS_08_ADAS_RightCamera_Fault
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Tx_ACAN_ADAS_08_ADAS_ECU_Fault
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Tx_ACAN_ADAS_08_ACC_TxtInfoForDriver
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Tx_ACAN_ADAS_08_ACC_DriveoffReq
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Tx_ACAN_ADAS_Info15_ADAS_AEB_FuncSWResp
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Tx_ACAN_ADAS_Info15_AEB_FuncSts
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Tx_ACAN_ADAS_Info15_AEB_VehActive
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Tx_ACAN_ADAS_Info15_AEB_VRUActive
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Tx_ACAN_ADAS_Info15_AEB_ErrorSts
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Tx_ACAN_ADAS_Info15_AEB_FCW_SnvtyResp
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Tx_ACAN_ADAS_Info15_TSR_TrafSign
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Tx_ACAN_ADAS_Info15_TSR_SpdAssistInfoDisp
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Tx_ACAN_ADAS_Info15_TSR_Warning_offset
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Tx_ACAN_ADAS_Info15_TSR_SLWVisualWarn
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Tx_ACAN_ADAS_Info15_TSR_SLWVoiceWarn
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Tx_ACAN_ADAS_Info15_AEB_FCW_Warning
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Tx_ACAN_ADAS_Info17_ADAS_APA_Soundremind
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Tx_ACAN_ADAS_Info17_ADAS_APA_ParkingModeReq
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Tx_ACAN_ADAS_Info17_ADAS_APA_OtherWarning
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Tx_ACAN_ADAS_Info17_ADAS_APA_RemindTxt1
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Tx_ACAN_ADAS_Info17_ADAS_APA_RemindTxt2
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Tx_ACAN_ADAS_Info17_ADAS_APA_LightReq
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Tx_ACAN_ADAS_Info17_ADAS_APA_SearchingWarning
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Tx_ACAN_ADAS_Info23_CheckSum_1F8
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Tx_ACAN_ADAS_Info23_RollingCounter_1F8
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Tx_ACAN_ADAS_Info23_APA_EPS_AngReqSts
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Tx_ACAN_ADAS_Info23_APA_EPS_TargetSteeringAngle
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Tx_ACAN_ADAS_Info23_ADAS_APA_BrakeModeSts
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Tx_ACAN_ADAS_Info23_APA_WCBS_BrakeFunctionMode
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Tx_ACAN_ADAS_Info23_APA_WCBS_BrakeMode
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Tx_ACAN_ADAS_Info23_APA_WCBS_TargetStopDistance
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Tx_ACAN_ADAS_Info23_APA_WCBS_ExpectedGearPosition
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Tx_ACAN_ADAS_Info23_APA_WCBS_SpeedLimitation
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info1_APA_slot_1
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info1_APA_slot_ID_1_P0_X
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info1_APA_slot_ID_1_P0_Y
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info1_APA_slot_ID_1_P1_X
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info1_APA_slot_ID_1_P1_Y
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info3_APA_slot_2
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info3_APA_slot_ID_2_P0_X
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info3_APA_slot_ID_2_P0_Y
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info3_APA_slot_ID_2_P1_X
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info3_APA_slot_ID_2_P1_Y
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info5_APA_slot_3
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info5_APA_slot_ID_3_P0_X
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info5_APA_slot_ID_3_P0_Y
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info5_APA_slot_ID_3_P1_X
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info5_APA_slot_ID_3_P1_Y
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info7_APA_slot_4
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info7_APA_slot_ID_4_P0_X
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info7_APA_slot_ID_4_P0_Y
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info7_APA_slot_ID_4_P1_X
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info7_APA_slot_ID_4_P1_Y
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info9_APA_slot_5
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info9_APA_slot_ID_5_P0_X
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info9_APA_slot_ID_5_P0_Y
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info9_APA_slot_ID_5_P1_X
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info9_APA_slot_ID_5_P1_Y
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info11_APA_slot_6
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info11_APA_slot_ID_6_P0_X
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info11_APA_slot_ID_6_P0_Y
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info11_APA_slot_ID_6_P1_X
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info11_APA_slot_ID_6_P1_Y
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info13_APA_slot_7
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info13_APA_slot_ID_7_P0_X
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info13_APA_slot_ID_7_P0_Y
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info13_APA_slot_ID_7_P1_X
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info13_APA_slot_ID_7_P1_Y
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info15_APA_slot_8
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info15_APA_slot_ID_8_P0_X
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info15_APA_slot_ID_8_P0_Y
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info15_APA_slot_ID_8_P1_X
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info15_APA_slot_ID_8_P1_Y
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info17_APA_slot_9
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info17_APA_slot_ID_9_P0_X
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info17_APA_slot_ID_9_P0_Y
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info17_APA_slot_ID_9_P1_X
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info17_APA_slot_ID_9_P1_Y
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info19_APA_slot_10
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info19_APA_slot_ID_10_P0_X
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info19_APA_slot_ID_10_P0_Y
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info19_APA_slot_ID_10_P1_X
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info19_APA_slot_ID_10_P1_Y
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info21_APA_slot_11
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info21_APA_slot_ID_11_P0_X
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info21_APA_slot_ID_11_P0_Y
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info21_APA_slot_ID_11_P1_X
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info21_APA_slot_ID_11_P1_Y
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info23_APA_slot_12
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info23_APA_slot_ID_12_P0_X
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info23_APA_slot_ID_12_P0_Y
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info23_APA_slot_ID_12_P1_X
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info23_APA_slot_ID_12_P1_Y
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info2_APA_slot_ID_1_Type
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info2_APA_slot_ID_1_P2_X
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info2_APA_slot_ID_1_P2_Y
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info2_APA_slot_ID_1_P3_X
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info2_APA_slot_ID_1_P3_Y
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info4_APA_slot_ID_2_Type
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info4_APA_slot_ID_2_P2_X
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info4_APA_slot_ID_2_P2_Y
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info4_APA_slot_ID_2_P3_X
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info4_APA_slot_ID_2_P3_Y
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info6_APA_slot_ID_3_Type
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info6_APA_slot_ID_3_P2_X
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info6_APA_slot_ID_3_P2_Y
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info6_APA_slot_ID_3_P3_X
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info6_APA_slot_ID_3_P3_Y
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info8_APA_slot_ID_4_Type
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info8_APA_slot_ID_4_P2_X
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info8_APA_slot_ID_4_P2_Y
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info8_APA_slot_ID_4_P3_X
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info8_APA_slot_ID_4_P3_Y
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info10_APA_slot_ID_5_Type
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info10_APA_slot_ID_5_P2_X
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info10_APA_slot_ID_5_P2_Y
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info10_APA_slot_ID_5_P3_X
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info10_APA_slot_ID_5_P3_Y
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info12_APA_slot_ID_6_Type
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info12_APA_slot_ID_6_P2_X
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info12_APA_slot_ID_6_P2_Y
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info12_APA_slot_ID_6_P3_X
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info12_APA_slot_ID_6_P3_Y
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info14_APA_slot_ID_7_Type
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info14_APA_slot_ID_7_P2_X
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info14_APA_slot_ID_7_P2_Y
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info14_APA_slot_ID_7_P3_X
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info14_APA_slot_ID_7_P3_Y
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info16_APA_slot_ID_8_Type
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info16_APA_slot_ID_8_P2_X
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info16_APA_slot_ID_8_P2_Y
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info16_APA_slot_ID_8_P3_X
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info16_APA_slot_ID_8_P3_Y
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info18_APA_slot_ID_9_Type
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info18_APA_slot_ID_9_P2_X
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info18_APA_slot_ID_9_P2_Y
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info18_APA_slot_ID_9_P3_X
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info18_APA_slot_ID_9_P3_Y
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info20_APA_slot_ID_10_Type
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info20_APA_slot_ID_10_P2_X
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info20_APA_slot_ID_10_P2_Y
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info20_APA_slot_ID_10_P3_X
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info20_APA_slot_ID_10_P3_Y
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info22_APA_slot_ID_11_Type
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info22_APA_slot_ID_11_P2_X
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info22_APA_slot_ID_11_P2_Y
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info22_APA_slot_ID_11_P3_X
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info22_APA_slot_ID_11_P3_Y
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info24_APA_slot_ID_12_Type
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info24_APA_slot_ID_12_P2_X
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info24_APA_slot_ID_12_P2_Y
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info24_APA_slot_ID_12_P3_X
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info24_APA_slot_ID_12_P3_Y
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Tx_ACAN_ADAS_Info20_APA_FrontSystemSts
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Tx_ACAN_ADAS_Info20_APA_RearSystemSts
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Tx_ACAN_ADAS_Info20_APA_ChimeRequest
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Tx_ACAN_ADAS_Info20_APA_FRegion1ObjectSts
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Tx_ACAN_ADAS_Info20_APA_FRegion2ObjectSts
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Tx_ACAN_ADAS_Info20_APA_FRegion3ObjectSts
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Tx_ACAN_ADAS_Info20_APA_FRegion4ObjectSts
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Tx_ACAN_ADAS_Info20_APA_FrontExtenedDistance
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Tx_ACAN_ADAS_Info20_APA_ParkAssistRRegion1ObjectSts
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Tx_ACAN_ADAS_Info20_APA_ParkAssistRRegion2ObjectSts
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Tx_ACAN_ADAS_Info20_APA_ParkAssistRRegion3ObjectSts
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Tx_ACAN_ADAS_Info20_APA_ParkAssistRRegion4ObjectSts
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Tx_ACAN_ADAS_Info20_APA_ParkAssistRExtenedDistance
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Tx_ACAN_ADAS_Info21_ADAS_USS_FaultFLI
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Tx_ACAN_ADAS_Info21_ADAS_USS_FaultFRI
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Tx_ACAN_ADAS_Info21_ADAS_USS_FaultFLO
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Tx_ACAN_ADAS_Info21_ADAS_USS_FaultFRO
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Tx_ACAN_ADAS_Info21_ADAS_USS_FaultFLS
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Tx_ACAN_ADAS_Info21_ADAS_USS_FaultFRS
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Tx_ACAN_ADAS_Info21_FLS_ExtenedDistance
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Tx_ACAN_ADAS_Info21_FRS_ExtenedDistance
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Tx_ACAN_ADAS_Info21_FLC_ExtenedDistance
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Tx_ACAN_ADAS_Info21_FLM_ExtenedDistance
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Tx_ACAN_ADAS_Info21_FRM_ExtenedDistance
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Tx_ACAN_ADAS_Info21_FRC_ExtenedDistance
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Tx_ACAN_ADAS_Info22_ADAS_USS_FaultRLI
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Tx_ACAN_ADAS_Info22_ADAS_USS_FaultRLO
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Tx_ACAN_ADAS_Info22_ADAS_USS_FaultRRI
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Tx_ACAN_ADAS_Info22_ADAS_USS_FaultRRO
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Tx_ACAN_ADAS_Info22_ADAS_USS_FaultRLS
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Tx_ACAN_ADAS_Info22_ADAS_USS_FaultRRS
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Tx_ACAN_ADAS_Info22_RLS_ExtenedDistance
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Tx_ACAN_ADAS_Info22_RRS_ExtenedDistance
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Tx_ACAN_ADAS_Info22_RLC_ExtenedDistance
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Tx_ACAN_ADAS_Info22_RLM_ExtenedDistance
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Tx_ACAN_ADAS_Info22_RRM_ExtenedDistance
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Tx_ACAN_ADAS_Info22_RRC_ExtenedDistance
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_Tcp_SendSignal
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_Udp_SendSignal
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_Udp_SendSignal_1501
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_Udp_SendSignal_1502
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_Udp_SendSignal_1503
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_Udp_SendSignal_1504
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_Udp_SendSignal_1505
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_Udp_SendSignal_1506
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_Udp_SendSignal_1507
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_ACAN_ACU_ChimeTelltaleReq_ACU_CoDSeatOccupSensorStat
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_ACAN_ACU_ChimeTelltaleReq_ACU_CoDSeatOccupSensorStat
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_ACAN_ACU_ChimeTelltaleReq_ACU_DSeatOccupSensorStat
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_ACAN_ACU_ChimeTelltaleReq_ACU_DSeatOccupSensorStat
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_ACAN_ACU_ChimeTelltaleReq_ACU_CoDSeatbeltBucklestatus
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_ACAN_ACU_ChimeTelltaleReq_ACU_CoDSeatbeltBucklestatus
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_ACAN_ACU_ChimeTelltaleReq_ACU_DSeatbeltBucklestatus
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_ACAN_ACU_ChimeTelltaleReq_ACU_DSeatbeltBucklestatus
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_ACAN_ACU_ChimeTelltaleReq_ACU_CoDAirbagStatus
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_ACAN_ACU_ChimeTelltaleReq_ACU_CoDAirbagStatus
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_ACAN_ACU_ChimeTelltaleReq_ACU_DAirbagStatus
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_ACAN_ACU_ChimeTelltaleReq_ACU_DAirbagStatus
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_ACAN_ACU_ChimeTelltaleReq_ACU_RPSeatOccupSensorStat
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_ACAN_ACU_ChimeTelltaleReq_ACU_RPSeatOccupSensorStat
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_ACAN_ACU_ChimeTelltaleReq_ACU_MPSeatOccupSensorStat
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_ACAN_ACU_ChimeTelltaleReq_ACU_MPSeatOccupSensorStat
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_ACAN_ACU_ChimeTelltaleReq_ACU_LPSeatOccupSensorStat
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_ACAN_ACU_ChimeTelltaleReq_ACU_LPSeatOccupSensorStat
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_ACAN_ACU_ChimeTelltaleReq_ACU_RCABsts
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_ACAN_ACU_ChimeTelltaleReq_ACU_RCABsts
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_ACAN_ACU_ChimeTelltaleReq_ACU_LCABsts
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_ACAN_ACU_ChimeTelltaleReq_ACU_LCABsts
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_ACAN_ACU_ChimeTelltaleReq_ACU_RSABsts
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_ACAN_ACU_ChimeTelltaleReq_ACU_RSABsts
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_ACAN_ACU_ChimeTelltaleReq_ACU_LSABsts
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_ACAN_ACU_ChimeTelltaleReq_ACU_LSABsts
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_ACAN_ACU_ChimeTelltaleReq_ACU_RPSeatbeltBucklestatus
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_ACAN_ACU_ChimeTelltaleReq_ACU_RPSeatbeltBucklestatus
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_ACAN_ACU_ChimeTelltaleReq_ACU_MPSeatbeltBucklestatus
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_ACAN_ACU_ChimeTelltaleReq_ACU_MPSeatbeltBucklestatus
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_ACAN_ACU_ChimeTelltaleReq_ACU_LPSeatbeltBucklestatus
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_ACAN_ACU_ChimeTelltaleReq_ACU_LPSeatbeltBucklestatus
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_ACAN_ACU_ChimeTelltaleReq_ACU_CrashSts
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_ACAN_ACU_ChimeTelltaleReq_ACU_CrashSts
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_ACAN_ACU_ChimeTelltaleReq_ACU_CrashRearOutputSts
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_ACAN_ACU_ChimeTelltaleReq_ACU_CrashRearOutputSts
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_ACAN_ACU_ChimeTelltaleReq_ACU_CrashRightOutputSts
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_ACAN_ACU_ChimeTelltaleReq_ACU_CrashRightOutputSts
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_ACAN_ACU_ChimeTelltaleReq_ACU_CrashLeftOutputSts
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_ACAN_ACU_ChimeTelltaleReq_ACU_CrashLeftOutputSts
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_ACAN_ACU_ChimeTelltaleReq_ACU_CrashFrontOutputSts
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_ACAN_ACU_ChimeTelltaleReq_ACU_CrashFrontOutputSts
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_ACAN_ACU_ChimeTelltaleReq_ACU_AirbagWarningStatus
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_ACAN_ACU_ChimeTelltaleReq_ACU_AirbagWarningStatus
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_ACAN_ACU_ChimeTelltaleReq_ACU_CoDSeatbletPTighten
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_ACAN_ACU_ChimeTelltaleReq_ACU_CoDSeatbletPTighten
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_ACAN_ACU_ChimeTelltaleReq_ACU_DSeatbletPTighten
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_ACAN_ACU_ChimeTelltaleReq_ACU_DSeatbletPTighten
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_ACAN_ACU_ChimeTelltaleReq_ACU_AliveCounter
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_ACAN_ACU_ChimeTelltaleReq_ACU_AliveCounter
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_ACAN_ACU_ChimeTelltaleReq_ACU_CheckSum
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_ACAN_ACU_ChimeTelltaleReq_ACU_CheckSum
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_ACAN_BCM_LIGHT_0x106_CheckSum_0x106
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_ACAN_BCM_LIGHT_0x106_CheckSum_0x106
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_ACAN_BCM_LIGHT_0x106_RollingCounter_0x106
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_ACAN_BCM_LIGHT_0x106_RollingCounter_0x106
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_ACAN_BCM_LIGHT_0x106_BCM_TurnIndicatorSts
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_ACAN_BCM_LIGHT_0x106_BCM_TurnIndicatorSts
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_ACAN_BCM_LIGHT_0x106_BCM_PosLmpSts
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_ACAN_BCM_LIGHT_0x106_BCM_PosLmpSts
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_ACAN_BCM_LIGHT_0x106_BCM_LowBeamSts
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_ACAN_BCM_LIGHT_0x106_BCM_LowBeamSts
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_ACAN_BCM_LIGHT_0x106_BCM_HighBeamSts
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_ACAN_BCM_LIGHT_0x106_BCM_HighBeamSts
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_ACAN_BCM_LIGHT_0x106_BCM_RearFogLampLightSts
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_ACAN_BCM_LIGHT_0x106_BCM_RearFogLampLightSts
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_ACAN_BCM_LIGHT_0x106_BCM_BrakeLightSts
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_ACAN_BCM_LIGHT_0x106_BCM_BrakeLightSts
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_ACAN_BCM_LIGHT_0x106_BCM_ReverseLightSts
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_ACAN_BCM_LIGHT_0x106_BCM_ReverseLightSts
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_ACAN_BCM_LIGHT_0x106_BCM_DayRunningLampSts
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_ACAN_BCM_LIGHT_0x106_BCM_DayRunningLampSts
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_ACAN_BCM_LIGHT_0x106_BCM_RMarkerLightSts
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_ACAN_BCM_LIGHT_0x106_BCM_RMarkerLightSts
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_ACAN_BCM_LIGHT_0x106_BCM_Rr_domelampSts
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_ACAN_BCM_LIGHT_0x106_BCM_Rr_domelampSts
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_ACAN_BCM_LIGHT_0x106_BCM_Fr_domelampSts
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_ACAN_BCM_LIGHT_0x106_BCM_Fr_domelampSts
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_ACAN_BCM_LIGHT_0x106_BCM_LicensePlateLightSts
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_ACAN_BCM_LIGHT_0x106_BCM_LicensePlateLightSts
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_ACAN_BCM_LIGHT_0x106_BCM_HeadLight_adjustSts
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_ACAN_BCM_LIGHT_0x106_BCM_HeadLight_adjustSts
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_ACAN_BCM_LIGHT_0x106_BCM_FrontFogLampLightSts
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_ACAN_BCM_LIGHT_0x106_BCM_FrontFogLampLightSts
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_ACAN_BCM_LIGHT_0x106_BCM_STAT_InteriorLight
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_ACAN_BCM_LIGHT_0x106_BCM_STAT_InteriorLight
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_ACAN_BCM_LIGHT_0x106_BCM_STAT_SwLightBrightness
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_ACAN_BCM_LIGHT_0x106_BCM_STAT_SwLightBrightness
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_ACAN_BCM_LIGHT_0x106_BCM_TurnLight_FaultSts
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_ACAN_BCM_LIGHT_0x106_BCM_TurnLight_FaultSts
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_ACAN_BCM_LIGHT_0x106_BCM_AmbeLightZone2Sts
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_ACAN_BCM_LIGHT_0x106_BCM_AmbeLightZone2Sts
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_ACAN_BCM_LIGHT_0x106_BCM_AmbeLightZone1Sts
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_ACAN_BCM_LIGHT_0x106_BCM_AmbeLightZone1Sts
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_ACAN_BCM_SwitchSts_0x109_CheckSum_0x109
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_ACAN_BCM_SwitchSts_0x109_CheckSum_0x109
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_ACAN_BCM_SwitchSts_0x109_RollingCounter_0x109
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_ACAN_BCM_SwitchSts_0x109_RollingCounter_0x109
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_ACAN_BCM_SwitchSts_0x109_BCM_STAT_Horn
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_ACAN_BCM_SwitchSts_0x109_BCM_STAT_Horn
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_ACAN_BCM_SwitchSts_0x109_BCM_STAT_HazardWarn
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_ACAN_BCM_SwitchSts_0x109_BCM_STAT_HazardWarn
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_ACAN_BCM_SwitchSts_0x109_BCM_LowBeamSWSts
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_ACAN_BCM_SwitchSts_0x109_BCM_LowBeamSWSts
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_ACAN_BCM_SwitchSts_0x109_BCM_TurnLightSWSts
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_ACAN_BCM_SwitchSts_0x109_BCM_TurnLightSWSts
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_ACAN_BCM_SwitchSts_0x109_BCM_Tail_MicroSW
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_ACAN_BCM_SwitchSts_0x109_BCM_Tail_MicroSW
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_ACAN_BCM_SwitchSts_0x109_STAT_Central_LockSts
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_ACAN_BCM_SwitchSts_0x109_STAT_Central_LockSts
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_ACAN_BCM_SwitchSts_0x109_BCM_RFogLampSWSts
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_ACAN_BCM_SwitchSts_0x109_BCM_RFogLampSWSts
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_ACAN_BCM_SwitchSts_0x109_BCM_FFogLampSWSts
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_ACAN_BCM_SwitchSts_0x109_BCM_FFogLampSWSts
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_ACAN_BCM_SwitchSts_0x109_BCM_HighBeamSWSts
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_ACAN_BCM_SwitchSts_0x109_BCM_HighBeamSWSts
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_ACAN_ABS_FrontWheelSpeMCUKPH_ABS_FLWheelSpeedInvalid
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_ACAN_ABS_FrontWheelSpeMCUKPH_ABS_FLWheelSpeedInvalid
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_ACAN_ABS_FrontWheelSpeMCUKPH_ABS_FLWheelSpeedKPH
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_ACAN_ABS_FrontWheelSpeMCUKPH_ABS_FLWheelSpeedKPH
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_ACAN_ABS_FrontWheelSpeMCUKPH_ABS_FRWheelSpeedInvalid
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_ACAN_ABS_FrontWheelSpeMCUKPH_ABS_FRWheelSpeedInvalid
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_ACAN_ABS_FrontWheelSpeMCUKPH_ABS_FRWheelSpeedKPH
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_ACAN_ABS_FrontWheelSpeMCUKPH_ABS_FRWheelSpeedKPH
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_ACAN_ABS_FrontWheelSpeMCUKPH_ABS_FRWheelDirection
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_ACAN_ABS_FrontWheelSpeMCUKPH_ABS_FRWheelDirection
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_ACAN_ABS_FrontWheelSpeMCUKPH_ABS_FLWheelDirection
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_ACAN_ABS_FrontWheelSpeMCUKPH_ABS_FLWheelDirection
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_ACAN_ABS_FrontWheelSpeMCUKPH_ABS_FWSpeMCUKPH_AliveCounter
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_ACAN_ABS_FrontWheelSpeMCUKPH_ABS_FWSpeMCUKPH_AliveCounter
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_ACAN_ABS_FrontWheelSpeMCUKPH_ABS_FWSpeMCUKPH_CheckSum
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_ACAN_ABS_FrontWheelSpeMCUKPH_ABS_FWSpeMCUKPH_CheckSum
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_ACAN_ABS_RearWheelSpeMCUKPH_ABS_RLWheelSpeedInvalid
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_ACAN_ABS_RearWheelSpeMCUKPH_ABS_RLWheelSpeedInvalid
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_ACAN_ABS_RearWheelSpeMCUKPH_ABS_RLWheelSpeedKPH
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_ACAN_ABS_RearWheelSpeMCUKPH_ABS_RLWheelSpeedKPH
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_ACAN_ABS_RearWheelSpeMCUKPH_ABS_RRWheelSpeedInvalid
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_ACAN_ABS_RearWheelSpeMCUKPH_ABS_RRWheelSpeedInvalid
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_ACAN_ABS_RearWheelSpeMCUKPH_ABS_RRWheelSpeedKPH
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_ACAN_ABS_RearWheelSpeMCUKPH_ABS_RRWheelSpeedKPH
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_ACAN_ABS_RearWheelSpeMCUKPH_ABS_RRWheelDirection
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_ACAN_ABS_RearWheelSpeMCUKPH_ABS_RRWheelDirection
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_ACAN_ABS_RearWheelSpeMCUKPH_ABS_RLWheelDirection
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_ACAN_ABS_RearWheelSpeMCUKPH_ABS_RLWheelDirection
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_ACAN_ABS_RearWheelSpeMCUKPH_ABS_RWSpeMCUKPH_AliveCounter
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_ACAN_ABS_RearWheelSpeMCUKPH_ABS_RWSpeMCUKPH_AliveCounter
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_ACAN_ABS_RearWheelSpeMCUKPH_ABS_RWSpeMCUKPH_CheckSum
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_ACAN_ABS_RearWheelSpeMCUKPH_ABS_RWSpeMCUKPH_CheckSum
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_ACAN_ABS_WheelSpeedRC_ABS_FLWheelSpeedRC
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_ACAN_ABS_WheelSpeedRC_ABS_FLWheelSpeedRC
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_ACAN_ABS_WheelSpeedRC_ABS_FRWheelSpeedRC
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_ACAN_ABS_WheelSpeedRC_ABS_FRWheelSpeedRC
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_ACAN_ABS_WheelSpeedRC_ABS_RLWheelSpeedRC
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_ACAN_ABS_WheelSpeedRC_ABS_RLWheelSpeedRC
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_ACAN_ABS_WheelSpeedRC_ABS_RRWheelSpeedRC
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_ACAN_ABS_WheelSpeedRC_ABS_RRWheelSpeedRC
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_ACAN_ABS_WheelSpeedRC_ABS_FLWheelSpeedRCSts
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_ACAN_ABS_WheelSpeedRC_ABS_FLWheelSpeedRCSts
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_ACAN_ABS_WheelSpeedRC_ABS_FRWheelSpeedRCSts
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_ACAN_ABS_WheelSpeedRC_ABS_FRWheelSpeedRCSts
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_ACAN_ABS_WheelSpeedRC_ABS_RLWheelSpeedRCSts
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_ACAN_ABS_WheelSpeedRC_ABS_RLWheelSpeedRCSts
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_ACAN_ABS_WheelSpeedRC_ABS_RRWheelSpeedRCSts
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_ACAN_ABS_WheelSpeedRC_ABS_RRWheelSpeedRCSts
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_ACAN_ABS_WheelSpeedRC_ABS_WheelSpeMCURC_AliveCounter
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_ACAN_ABS_WheelSpeedRC_ABS_WheelSpeMCURC_AliveCounter
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_ACAN_ABS_WheelSpeedRC_ABS_WheelSpeMCURC_CheckSum
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_ACAN_ABS_WheelSpeedRC_ABS_WheelSpeMCURC_CheckSum
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_ACAN_ABS_Status_ABSActive
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_ACAN_ABS_Status_ABSActive
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_ACAN_ABS_Status_ABS_EBDFailed
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_ACAN_ABS_Status_ABS_EBDFailed
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_ACAN_ABS_Status_ABSFailed
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_ACAN_ABS_Status_ABSFailed
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_ACAN_ABS_Status_ABS_LowBrakeFluid
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_ACAN_ABS_Status_ABS_LowBrakeFluid
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_ACAN_ABS_Status_ABS_VehicleSpeedInvalid
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_ACAN_ABS_Status_ABS_VehicleSpeedInvalid
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_ACAN_ABS_Status_ABS_VehicleSpeed
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_ACAN_ABS_Status_ABS_VehicleSpeed
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_ACAN_ABS_Status_ABS_Status_AliveCounter
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_ACAN_ABS_Status_ABS_Status_AliveCounter
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_ACAN_ABS_Status_ABS_HAZActive
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_ACAN_ABS_Status_ABS_HAZActive
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_ACAN_ABS_Status_ABS_Status_CheckSum
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_ACAN_ABS_Status_ABS_Status_CheckSum
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_ACAN_ESC_Status_0x132_Checksum_0x132
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_ACAN_ESC_Status_0x132_Checksum_0x132
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_ACAN_ESC_Status_0x132_RollingCounter_0x132
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_ACAN_ESC_Status_0x132_RollingCounter_0x132
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_ACAN_ESC_Status_0x132_ESC_SlopeGradeAngle
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_ACAN_ESC_Status_0x132_ESC_SlopeGradeAngle
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_ACAN_ESC_Status_0x132_ESC_MasterCylinderPressureV
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_ACAN_ESC_Status_0x132_ESC_MasterCylinderPressureV
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_ACAN_ESC_Status_0x132_ESC_MasterCylinderPressure
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_ACAN_ESC_Status_0x132_ESC_MasterCylinderPressure
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_ACAN_ESC_Status_0x132_ESC_HSA_Control_Status
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_ACAN_ESC_Status_0x132_ESC_HSA_Control_Status
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_ACAN_ESC_Status_0x132_ESC_HSA_Status_Fault
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_ACAN_ESC_Status_0x132_ESC_HSA_Status_Fault
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_ACAN_ESC_Status_0x132_ESC_TcsDisableSts
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_ACAN_ESC_Status_0x132_ESC_TcsDisableSts
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_ACAN_ESC_Status_0x132_ESC_EscCtrlActv
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_ACAN_ESC_Status_0x132_ESC_EscCtrlActv
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_ACAN_ESC_Status_0x132_ESC_TcsCtrlActv
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_ACAN_ESC_Status_0x132_ESC_TcsCtrlActv
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_ACAN_ESC_Status_0x132_ESC_EscFlgFlt
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_ACAN_ESC_Status_0x132_ESC_EscFlgFlt
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_ACAN_ESC_Status_0x132_ESC_TcsFlgFlt
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_ACAN_ESC_Status_0x132_ESC_TcsFlgFlt
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_ACAN_ESC_Status_0x132_ESC_EscDisableSts
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_ACAN_ESC_Status_0x132_ESC_EscDisableSts
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_ACAN_ESC_Status_0x132_ESC_HBAFlgFlt
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_ACAN_ESC_Status_0x132_ESC_HBAFlgFlt
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_ACAN_ESC_Status_0x132_ESC_HbaCtrlActv
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_ACAN_ESC_Status_0x132_ESC_HbaCtrlActv
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_ACAN_ESC_Status_0x132_BAS_FlgFlt
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_ACAN_ESC_Status_0x132_BAS_FlgFlt
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_ACAN_ESC_Status_0x132_BAS_CtrlActv
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_ACAN_ESC_Status_0x132_BAS_CtrlActv
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_ACAN_ESC_Status_0x132_IBS_ESCOFF_StsFB
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_ACAN_ESC_Status_0x132_IBS_ESCOFF_StsFB
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_ACAN_VCU_Ctrl_VCU_ModeGearSts
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_ACAN_VCU_Ctrl_VCU_ModeGearSts
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_ACAN_VCU_Ctrl_VCU_P_Sts
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_ACAN_VCU_Ctrl_VCU_P_Sts
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_ACAN_VCU_Ctrl_VCU_Warning_IMMO_Fail
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_ACAN_VCU_Ctrl_VCU_Warning_IMMO_Fail
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_ACAN_VCU_Ctrl_VCU_Ready
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_ACAN_VCU_Ctrl_VCU_Ready
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_ACAN_VCU_Ctrl_VCU_RegencyLevInd
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_ACAN_VCU_Ctrl_VCU_RegencyLevInd
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_ACAN_VCU_Ctrl_VCU_Ctrl_AliveCounter
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_ACAN_VCU_Ctrl_VCU_Ctrl_AliveCounter
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_ACAN_VCU_Ctrl_VCU_LimpHomeSts
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_ACAN_VCU_Ctrl_VCU_LimpHomeSts
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_ACAN_VCU_Ctrl_VCU_Ctrl_CheckSum
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_ACAN_VCU_Ctrl_VCU_Ctrl_CheckSum
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_ACAN_VCU_StsEpt_VCU_StsAccPedalFault
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_ACAN_VCU_StsEpt_VCU_StsAccPedalFault
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_ACAN_VCU_StsEpt_VCU_StsSysFault
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_ACAN_VCU_StsEpt_VCU_StsSysFault
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_ACAN_VCU_StsEpt_VCU_AccPedalPosition
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_ACAN_VCU_StsEpt_VCU_AccPedalPosition
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_ACAN_VCU_StsEpt_VCU_AccPedal_Valid
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_ACAN_VCU_StsEpt_VCU_AccPedal_Valid
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_ACAN_VCU_StsEpt_VCU_StsEpt_AliveCounter
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_ACAN_VCU_StsEpt_VCU_StsEpt_AliveCounter
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_ACAN_VCU_StsEpt_VCU_StsEpt_CheckSum
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_ACAN_VCU_StsEpt_VCU_StsEpt_CheckSum
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_ACAN_SAS_Sensor_0x17E_Checksum_0x17E
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_ACAN_SAS_Sensor_0x17E_Checksum_0x17E
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_ACAN_SAS_Sensor_0x17E_Rolling_counter_0x17E
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_ACAN_SAS_Sensor_0x17E_Rolling_counter_0x17E
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_ACAN_SAS_Sensor_0x17E_SAS_SASStsSnsr
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_ACAN_SAS_Sensor_0x17E_SAS_SASStsSnsr
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_ACAN_SAS_Sensor_0x17E_SAS_SteeringAngleValid
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_ACAN_SAS_Sensor_0x17E_SAS_SteeringAngleValid
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_ACAN_SAS_Sensor_0x17E_SAS_SteerWhlRotSpd
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_ACAN_SAS_Sensor_0x17E_SAS_SteerWhlRotSpd
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_ACAN_SAS_Sensor_0x17E_SAS_SASFailure
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_ACAN_SAS_Sensor_0x17E_SAS_SASFailure
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_ACAN_SAS_Sensor_0x17E_SAS_Calibrated
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_ACAN_SAS_Sensor_0x17E_SAS_Calibrated
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_ACAN_SAS_Sensor_0x17E_SAS_SteerWhlRotSpdStatus
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_ACAN_SAS_Sensor_0x17E_SAS_SteerWhlRotSpdStatus
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_ACAN_SAS_Sensor_0x17E_SAS_SteerWheelAngle
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_ACAN_SAS_Sensor_0x17E_SAS_SteerWheelAngle
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_ACAN_EPS_LKA_Sts_CheckSum_0x17F
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_ACAN_EPS_LKA_Sts_CheckSum_0x17F
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_ACAN_EPS_LKA_Sts_EPS_APA_CtrlAbortFeedback
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_ACAN_EPS_LKA_Sts_EPS_APA_CtrlAbortFeedback
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_ACAN_EPS_LKA_Sts_RollingCounter_0x17F
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_ACAN_EPS_LKA_Sts_RollingCounter_0x17F
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_ACAN_EPS_LKA_Sts_EPS_SterMod
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_ACAN_EPS_LKA_Sts_EPS_SterMod
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_ACAN_EPS_LKA_Sts_EPS_SterModV
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_ACAN_EPS_LKA_Sts_EPS_SterModV
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_ACAN_EPS_LKA_Sts_EPS_LKARespTorq
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_ACAN_EPS_LKA_Sts_EPS_LKARespTorq
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_ACAN_EPS_LKA_Sts_EPS_ADAS_CtrlAbortFeedback
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_ACAN_EPS_LKA_Sts_EPS_ADAS_CtrlAbortFeedback
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_ACAN_EPS_LKA_Sts_EPS_SterFltMod
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_ACAN_EPS_LKA_Sts_EPS_SterFltMod
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_ACAN_EPS_LKA_Sts_EPS_DrStrTorqV
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_ACAN_EPS_LKA_Sts_EPS_DrStrTorqV
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_ACAN_EPS_LKA_Sts_EPS_APA_ModAvail
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_ACAN_EPS_LKA_Sts_EPS_APA_ModAvail
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_ACAN_EPS_LKA_Sts_EPS_APA_ModActv
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_ACAN_EPS_LKA_Sts_EPS_APA_ModActv
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_ACAN_EPS_LKA_Sts_EPS_ADAS_ModActv
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_ACAN_EPS_LKA_Sts_EPS_ADAS_ModActv
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_ACAN_EPS_LKA_Sts_EPS_ADAS_ModAvail
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_ACAN_EPS_LKA_Sts_EPS_ADAS_ModAvail
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_ACAN_EPS_LKA_Sts_EPS_DrStrTorqVal
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_ACAN_EPS_LKA_Sts_EPS_DrStrTorqVal
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_ACAN_BCM_PEPS_Sts_PEPS_PowerModeValidity
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_ACAN_BCM_PEPS_Sts_PEPS_PowerModeValidity
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_ACAN_BCM_PEPS_Sts_PEPS_PowerMode
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_ACAN_BCM_PEPS_Sts_PEPS_PowerMode
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_ACAN_BCM_PEPS_Sts_PEPS_IGN1RelayValidity
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_ACAN_BCM_PEPS_Sts_PEPS_IGN1RelayValidity
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_ACAN_BCM_PEPS_Sts_PEPS_IGN1RelaySts
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_ACAN_BCM_PEPS_Sts_PEPS_IGN1RelaySts
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_ACAN_BCM_PEPS_Sts_PEPS_Learning_Status
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_ACAN_BCM_PEPS_Sts_PEPS_Learning_Status
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_ACAN_BCM_PEPS_Sts_BCM_WPC_Off_Req
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_ACAN_BCM_PEPS_Sts_BCM_WPC_Off_Req
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_ACAN_BCM_PEPS_Sts_PEPS_Message_Sts_AliveCounter
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_ACAN_BCM_PEPS_Sts_PEPS_Message_Sts_AliveCounter
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_ACAN_BCM_PEPS_Sts_PEPS_Message_Sts_CheckSum
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_ACAN_BCM_PEPS_Sts_PEPS_Message_Sts_CheckSum
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_ACAN_MHU_ADSA01_MHU_APA_Req
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_ACAN_MHU_ADSA01_MHU_APA_Req
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_ACAN_MHU_ADSA01_MHU_APA_ParkIn_Req
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_ACAN_MHU_ADSA01_MHU_APA_ParkIn_Req
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_ACAN_MHU_ADSA01_MHU_APA_ParkOut_Req
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_ACAN_MHU_ADSA01_MHU_APA_ParkOut_Req
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_ACAN_MHU_ADSA01_MHU_APA_ParkingStart_Req
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_ACAN_MHU_ADSA01_MHU_APA_ParkingStart_Req
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_ACAN_MHU_ADSA01_MHU_APA_ParkingReCover_Req
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_ACAN_MHU_ADSA01_MHU_APA_ParkingReCover_Req
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_ACAN_MHU_ADSA01_MHU_APA_ParkOut_Direction
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_ACAN_MHU_ADSA01_MHU_APA_ParkOut_Direction
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_ACAN_MHU_ADSA01_MHU_APA_ParkOut_Mode
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_ACAN_MHU_ADSA01_MHU_APA_ParkOut_Mode
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_ACAN_MHU_ADSA01_MHU_LSS_Req
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_ACAN_MHU_ADSA01_MHU_LSS_Req
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_ACAN_MHU_ADSA01_MHU_LSS_Mode
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_ACAN_MHU_ADSA01_MHU_LSS_Mode
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_ACAN_MHU_ADSA01_MHU_LSS_WarningMethod
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_ACAN_MHU_ADSA01_MHU_LSS_WarningMethod
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_ACAN_MHU_ADSA01_MHU_TSR_Req
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_ACAN_MHU_ADSA01_MHU_TSR_Req
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_ACAN_MHU_ADSA01_TSR_SpdWarningOffs_S
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_ACAN_MHU_ADSA01_TSR_SpdWarningOffs_S
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_ACAN_MHU_ADSA01_TSR_SLWFuncSwtReq
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_ACAN_MHU_ADSA01_TSR_SLWFuncSwtReq
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_ACAN_MHU_ADSA01_AEB_FuncSwtReq
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_ACAN_MHU_ADSA01_AEB_FuncSwtReq
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_ACAN_MHU_ADSA01_AEB_FCW_SnvtyReq
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_ACAN_MHU_ADSA01_AEB_FCW_SnvtyReq
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_ACAN_MHU_ADSA01_BSD_LCA_FuncSWReq
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_ACAN_MHU_ADSA01_BSD_LCA_FuncSWReq
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_ACAN_MHU_ADSA01_RCTA_FuncSWReq
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_ACAN_MHU_ADSA01_RCTA_FuncSWReq
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_ACAN_MHU_ADSA01_DOW_FuncSWReq
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_ACAN_MHU_ADSA01_DOW_FuncSWReq
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_ACAN_MHU_ADSA01_RCW_FuncSWReq
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_ACAN_MHU_ADSA01_RCW_FuncSWReq
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_ACAN_MHU_ADSA01_MHU_APA_ParkingSpace_ID
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_ACAN_MHU_ADSA01_MHU_APA_ParkingSpace_ID
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_ACAN_MHU_ADAS02_Nav_errorSts
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_ACAN_MHU_ADAS02_Nav_errorSts
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_ACAN_MHU_ADAS02_Nav_RoadType
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_ACAN_MHU_ADAS02_Nav_RoadType
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_ACAN_MHU_ADAS02_Nav_VehToTrafEyeDist
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_ACAN_MHU_ADAS02_Nav_VehToTrafEyeDist
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_ACAN_MHU_ADAS02_Nav_SpdLimValue
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_ACAN_MHU_ADAS02_Nav_SpdLimValue
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_ACAN_MHU_ADAS02_Nav_SpdLimType
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_ACAN_MHU_ADAS02_Nav_SpdLimType
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_ACAN_MHU_ADAS02_Nav_SpdLimUnit
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_ACAN_MHU_ADAS02_Nav_SpdLimUnit
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_ACAN_MHU_ADAS02_Nav_TSRTrafSign
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_ACAN_MHU_ADAS02_Nav_TSRTrafSign
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_ACAN_MHU_ADAS02_Nav_CtryType
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_ACAN_MHU_ADAS02_Nav_CtryType
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_ACAN_MHU_ADAS03_Nav_TimeMod
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_ACAN_MHU_ADAS03_Nav_TimeMod
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_ACAN_MHU_ADAS03_Nav_TimeIndcn
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_ACAN_MHU_ADAS03_Nav_TimeIndcn
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_ACAN_BCM_WindowSts_BCM_FLWin_Postion
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_ACAN_BCM_WindowSts_BCM_FLWin_Postion
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_ACAN_BCM_WindowSts_BCM_FRWin_Postion
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_ACAN_BCM_WindowSts_BCM_FRWin_Postion
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_ACAN_BCM_WindowSts_BCM_RLWinIN_Postion
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_ACAN_BCM_WindowSts_BCM_RLWinIN_Postion
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_ACAN_BCM_WindowSts_BCM_RRWin_Postion
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_ACAN_BCM_WindowSts_BCM_RRWin_Postion
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_ACAN_BCM_WindowSts_BCM_WinLockSts
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_ACAN_BCM_WindowSts_BCM_WinLockSts
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_ACAN_BCM_WindowSts_BCM_RLWinAntipinchSts
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_ACAN_BCM_WindowSts_BCM_RLWinAntipinchSts
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_ACAN_BCM_WindowSts_BCM_RRWinAntipinchSts
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_ACAN_BCM_WindowSts_BCM_RRWinAntipinchSts
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_ACAN_BCM_WindowSts_BCM_FLWinAntipinchSts
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_ACAN_BCM_WindowSts_BCM_FLWinAntipinchSts
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_ACAN_BCM_WindowSts_BCM_FRWinAntipinchSts
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_ACAN_BCM_WindowSts_BCM_FRWinAntipinchSts
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_ACAN_BCM_WindowSts_BCM_FrontWipeSWSts
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_ACAN_BCM_WindowSts_BCM_FrontWipeSWSts
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_ACAN_BCM_WindowSts_BCM_AutoWipeSts
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_ACAN_BCM_WindowSts_BCM_AutoWipeSts
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_ACAN_BCM_WindowSts_BCM_FrontWipeSts
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_ACAN_BCM_WindowSts_BCM_FrontWipeSts
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_ACAN_BCM_WindowSts_BCM_FrontWipeReturn
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_ACAN_BCM_WindowSts_BCM_FrontWipeReturn
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_ACAN_BCM_WindowSts_BCM_FrontWinWashSWSts
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_ACAN_BCM_WindowSts_BCM_FrontWinWashSWSts
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_ACAN_BCM_WindowSts_BCM_RearWipeSWSts
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_ACAN_BCM_WindowSts_BCM_RearWipeSWSts
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_ACAN_BCM_WindowSts_BCM_RearWipeSts
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_ACAN_BCM_WindowSts_BCM_RearWipeSts
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_ACAN_BCM_WindowSts_BCM_RearWipeReturn
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_ACAN_BCM_WindowSts_BCM_RearWipeReturn
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_ACAN_BCM_WindowSts_BCM_RearWinWashSWSts
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_ACAN_BCM_WindowSts_BCM_RearWinWashSWSts
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_ACAN_ESC_EPB_0x230_Checksum_230
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_ACAN_ESC_EPB_0x230_Checksum_230
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_ACAN_ESC_EPB_0x230_RollingCounter_230
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_ACAN_ESC_EPB_0x230_RollingCounter_230
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_ACAN_ESC_EPB_0x230_EPB_SysBrkLtsReq
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_ACAN_ESC_EPB_0x230_EPB_SysBrkLtsReq
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_ACAN_ESC_EPB_0x230_EPB_SysDspMsgReqV
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_ACAN_ESC_EPB_0x230_EPB_SysDspMsgReqV
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_ACAN_ESC_EPB_0x230_EPB_SysStatIndReqV
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_ACAN_ESC_EPB_0x230_EPB_SysStatIndReqV
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_ACAN_ESC_EPB_0x230_EPB_SysWrnIndReqV
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_ACAN_ESC_EPB_0x230_EPB_SysWrnIndReqV
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_ACAN_ESC_EPB_0x230_EPB_SysWrnIndReq
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_ACAN_ESC_EPB_0x230_EPB_SysWrnIndReq
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_ACAN_ESC_EPB_0x230_EPB_SysStatIndReq
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_ACAN_ESC_EPB_0x230_EPB_SysStatIndReq
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_ACAN_ESC_EPB_0x230_EPB_SysDspMsgReq
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_ACAN_ESC_EPB_0x230_EPB_SysDspMsgReq
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_ACAN_ESC_EPB_0x230_EPB_AVHWrnIndReq
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_ACAN_ESC_EPB_0x230_EPB_AVHWrnIndReq
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_ACAN_ESC_EPB_0x230_EPB_AVHWrnIndReqV
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_ACAN_ESC_EPB_0x230_EPB_AVHWrnIndReqV
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_ACAN_ESC_EPB_0x230_EPB_AVHStatIndReq
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_ACAN_ESC_EPB_0x230_EPB_AVHStatIndReq
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_ACAN_ESC_EPB_0x230_EPB_AVHStatIndReqV
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_ACAN_ESC_EPB_0x230_EPB_AVHStatIndReqV
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_ACAN_ESC_EPB_0x230_EPB_AVHFeedbackSts
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_ACAN_ESC_EPB_0x230_EPB_AVHFeedbackSts
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_ACAN_ESC_EPB_0x230_EPB_Sts
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_ACAN_ESC_EPB_0x230_EPB_Sts
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_ACAN_ESC_EPB_0x230_WCBS_Trailermode_Feedback
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_ACAN_ESC_EPB_0x230_WCBS_Trailermode_Feedback
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_ACAN_IBS_ADAS_Info_WCBS_ACC_VLC_Active
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_ACAN_IBS_ADAS_Info_WCBS_ACC_VLC_Active
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_ACAN_IBS_ADAS_Info_WCBS_ACC_CDD_Active
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_ACAN_IBS_ADAS_Info_WCBS_ACC_CDD_Active
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_ACAN_IBS_ADAS_Info_WCBS_ACC_VLC_Avl
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_ACAN_IBS_ADAS_Info_WCBS_ACC_VLC_Avl
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_ACAN_IBS_ADAS_Info_WCBS_ACC_CDD_Avl
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_ACAN_IBS_ADAS_Info_WCBS_ACC_CDD_Avl
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_ACAN_IBS_ADAS_Info_WCBS_ACC_VLC_AccInTar
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_ACAN_IBS_ADAS_Info_WCBS_ACC_VLC_AccInTar
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_ACAN_IBS_ADAS_Info_WCBS_ABAAtv
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_ACAN_IBS_ADAS_Info_WCBS_ABAAtv
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_ACAN_IBS_ADAS_Info_WCBS_ABAAva
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_ACAN_IBS_ADAS_Info_WCBS_ABAAva
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_ACAN_IBS_ADAS_Info_WCBS_ABPAtv
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_ACAN_IBS_ADAS_Info_WCBS_ABPAtv
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_ACAN_IBS_ADAS_Info_WCBS_ABPAva
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_ACAN_IBS_ADAS_Info_WCBS_ABPAva
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_ACAN_IBS_ADAS_Info_WCBS_AWBAtv
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_ACAN_IBS_ADAS_Info_WCBS_AWBAtv
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_ACAN_IBS_ADAS_Info_WCBS_AWBAvl
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_ACAN_IBS_ADAS_Info_WCBS_AWBAvl
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_ACAN_IBS_ADAS_Info_WCBS_AEBAtv
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_ACAN_IBS_ADAS_Info_WCBS_AEBAtv
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_ACAN_IBS_ADAS_Info_WCBS_AEBAva
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_ACAN_IBS_ADAS_Info_WCBS_AEBAva
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_ACAN_IBS_ADAS_Info_WCBS_VStandstillSta
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_ACAN_IBS_ADAS_Info_WCBS_VStandstillSta
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_ACAN_IBS_ADAS_Info_WCBS_BrkFrcSta
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_ACAN_IBS_ADAS_Info_WCBS_BrkFrcSta
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_ACAN_IBS_ADAS_Info_WCBS_ESCDeteACCErroSta
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_ACAN_IBS_ADAS_Info_WCBS_ESCDeteACCErroSta
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_ACAN_IBS_ADAS_Info_WCBS_APA_VLC_FailureStatus
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_ACAN_IBS_ADAS_Info_WCBS_APA_VLC_FailureStatus
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_ACAN_IBS_ADAS_Info_WCBS_APA_VLC_Status
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_ACAN_IBS_ADAS_Info_WCBS_APA_VLC_Status
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_ACAN_IBS_ADAS_Info_WCBS_APA_VLC_Available
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_ACAN_IBS_ADAS_Info_WCBS_APA_VLC_Available
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_ACAN_IBS_ADAS_Info_WCBS_APA_VLC_Active
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_ACAN_IBS_ADAS_Info_WCBS_APA_VLC_Active
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_ACAN_IBS_ADAS_Info_WCBS_APA_EmgyBrkAvlb
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_ACAN_IBS_ADAS_Info_WCBS_APA_EmgyBrkAvlb
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_ACAN_IBS_ADAS_Info_WCBS_APA_CDD_Active
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_ACAN_IBS_ADAS_Info_WCBS_APA_CDD_Active
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_ACAN_IBS_Info_AB_BrkPedalSwSts
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_ACAN_IBS_Info_AB_BrkPedalSwSts
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_ACAN_IBS_Info_AB_BrkPedalSwStsV
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_ACAN_IBS_Info_AB_BrkPedalSwStsV
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_ACAN_IBS_Info_AB_Fault_Status
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_ACAN_IBS_Info_AB_Fault_Status
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_ACAN_IBS_Info_AB_IBS_Sys_Fault_Sts
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_ACAN_IBS_Info_AB_IBS_Sys_Fault_Sts
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_ACAN_IBS_Info_AB_BrkPedalPct
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_ACAN_IBS_Info_AB_BrkPedalPct
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_ACAN_IBS_Info_AB_BrkPedalTravel
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_ACAN_IBS_Info_AB_BrkPedalTravel
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_ACAN_TBOX_DateTime1_Time_second
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_ACAN_TBOX_DateTime1_Time_second
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_ACAN_TBOX_DateTime1_GPSSystAtv
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_ACAN_TBOX_DateTime1_GPSSystAtv
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_ACAN_TBOX_DateTime1_Time_Minute
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_ACAN_TBOX_DateTime1_Time_Minute
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_ACAN_TBOX_DateTime1_Time_Hour
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_ACAN_TBOX_DateTime1_Time_Hour
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_ACAN_TBOX_DateTime1_Time_Day
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_ACAN_TBOX_DateTime1_Time_Day
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_ACAN_TBOX_DateTime1_Time_Month
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_ACAN_TBOX_DateTime1_Time_Month
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_ACAN_TBOX_DateTime1_Time_Year
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_ACAN_TBOX_DateTime1_Time_Year
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_ACAN_MHU_Status_Info_MHU_ESCOFF_SW_Sts
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_ACAN_MHU_Status_Info_MHU_ESCOFF_SW_Sts
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_ACAN_MHU_Status_Info_MHU_VCU_CreepDisable_stt
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_ACAN_MHU_Status_Info_MHU_VCU_CreepDisable_stt
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_ACAN_MHU_Status_Info_MHU_AVH_Req
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_ACAN_MHU_Status_Info_MHU_AVH_Req
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_ACAN_MHU_Status_Info_MHU_RegencyLevRequest
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_ACAN_MHU_Status_Info_MHU_RegencyLevRequest
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_ACAN_MHU_Status_Info_MHU_DM_SwitchModeSts
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_ACAN_MHU_Status_Info_MHU_DM_SwitchModeSts
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_ACAN_MHU_Status_Info_MHU_Trailermode_Req
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_ACAN_MHU_Status_Info_MHU_Trailermode_Req
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_ACAN_MHU_Status_Info_MHU_UPAMuteSwitch
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_ACAN_MHU_Status_Info_MHU_UPAMuteSwitch
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_ACAN_CCU_StsInfo1_CCU_PTCgear_Req_Reserve
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_ACAN_CCU_StsInfo1_CCU_PTCgear_Req_Reserve
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_ACAN_CCU_StsInfo1_CCU_Anion_Generator_Sts
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_ACAN_CCU_StsInfo1_CCU_Anion_Generator_Sts
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_ACAN_CCU_StsInfo1_CCU_AC_Req
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_ACAN_CCU_StsInfo1_CCU_AC_Req
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_ACAN_CCU_StsInfo1_CCU_Onoff_Sts
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_ACAN_CCU_StsInfo1_CCU_Onoff_Sts
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_ACAN_CCU_StsInfo1_CCU_AUTO_Status
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_ACAN_CCU_StsInfo1_CCU_AUTO_Status
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_ACAN_CCU_StsInfo1_CCU_FrontDefrostSts
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_ACAN_CCU_StsInfo1_CCU_FrontDefrostSts
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_ACAN_CCU_StsInfo1_CCU_AC_Sts
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_ACAN_CCU_StsInfo1_CCU_AC_Sts
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_ACAN_CCU_StsInfo1_CCU_Circulation_Sts
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_ACAN_CCU_StsInfo1_CCU_Circulation_Sts
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_ACAN_CCU_StsInfo1_CCU_ExternalTemperatureFailSts
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_ACAN_CCU_StsInfo1_CCU_ExternalTemperatureFailSts
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_ACAN_CCU_StsInfo1_CCU_PTC_Req
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_ACAN_CCU_StsInfo1_CCU_PTC_Req
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_ACAN_CCU_StsInfo1_CCU_Temp_Sync_Sts
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_ACAN_CCU_StsInfo1_CCU_Temp_Sync_Sts
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_ACAN_CCU_StsInfo1_CCU_evaporator_Temperature
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_ACAN_CCU_StsInfo1_CCU_evaporator_Temperature
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_ACAN_CCU_StsInfo1_CCU_PTCPwr_Req
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_ACAN_CCU_StsInfo1_CCU_PTCPwr_Req
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_ACAN_CCU_StsInfo1_CCU_CompSpdMEAS_Comp
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_ACAN_CCU_StsInfo1_CCU_CompSpdMEAS_Comp
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_ACAN_CCU_StsInfo1_CCU_ExternalTemperature
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_ACAN_CCU_StsInfo1_CCU_ExternalTemperature
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_ACAN_ESC_YawAngle_0x3E2_Checksum_0x3E2
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_ACAN_ESC_YawAngle_0x3E2_Checksum_0x3E2
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_ACAN_ESC_YawAngle_0x3E2_RollingCounter_0x3E2
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_ACAN_ESC_YawAngle_0x3E2_RollingCounter_0x3E2
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_ACAN_ESC_YawAngle_0x3E2_ESC_LateralACC_Valid
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_ACAN_ESC_YawAngle_0x3E2_ESC_LateralACC_Valid
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_ACAN_ESC_YawAngle_0x3E2_ESC_LongitudeACC_Valid
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_ACAN_ESC_YawAngle_0x3E2_ESC_LongitudeACC_Valid
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_ACAN_ESC_YawAngle_0x3E2_ESC_VehDynYawRate_Valid
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_ACAN_ESC_YawAngle_0x3E2_ESC_VehDynYawRate_Valid
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_ACAN_ESC_YawAngle_0x3E2_ESC_VehDynYawRate
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_ACAN_ESC_YawAngle_0x3E2_ESC_VehDynYawRate
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_ACAN_ESC_YawAngle_0x3E2_ESC_LateralACC
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_ACAN_ESC_YawAngle_0x3E2_ESC_LateralACC
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_ACAN_ESC_YawAngle_0x3E2_ESC_LongitudeACC
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_ACAN_ESC_YawAngle_0x3E2_ESC_LongitudeACC
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_ACAN_IPC_TotalOdometer_IPC_IPCTotalOdometer
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_ACAN_IPC_TotalOdometer_IPC_IPCTotalOdometer
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_ACAN_IPC_TotalOdometer_IPC_IPCTotalOdometerV
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_ACAN_IPC_TotalOdometer_IPC_IPCTotalOdometerV
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_ACAN_IPC_TotalOdometer_IPC_Remain_Maintenance
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_ACAN_IPC_TotalOdometer_IPC_Remain_Maintenance
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_ACAN_IPC_TotalOdometer_RollingCounter_0x3F1
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_ACAN_IPC_TotalOdometer_RollingCounter_0x3F1
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_ACAN_IPC_TotalOdometer_CheckSum_0x3F1
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_ACAN_IPC_TotalOdometer_CheckSum_0x3F1
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_ACAN_MFS_L_Control_Button2_0x3F7_CheckSum_0x3F7
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_ACAN_MFS_L_Control_Button2_0x3F7_CheckSum_0x3F7
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_ACAN_MFS_L_Control_Button2_0x3F7_RollingCounter_0x3F7
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_ACAN_MFS_L_Control_Button2_0x3F7_RollingCounter_0x3F7
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_ACAN_MFS_L_Control_Button2_0x3F7_MFS_ACC_CruiseSpdIncrease
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_ACAN_MFS_L_Control_Button2_0x3F7_MFS_ACC_CruiseSpdIncrease
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_ACAN_MFS_L_Control_Button2_0x3F7_MFS_ACC_CruiseOn_Off
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_ACAN_MFS_L_Control_Button2_0x3F7_MFS_ACC_CruiseOn_Off
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_ACAN_MFS_L_Control_Button2_0x3F7_MFS_L2_Failure
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_ACAN_MFS_L_Control_Button2_0x3F7_MFS_L2_Failure
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_ACAN_MFS_L_Control_Button2_0x3F7_MFS_ACC_CruiseGapSet
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_ACAN_MFS_L_Control_Button2_0x3F7_MFS_ACC_CruiseGapSet
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_ACAN_MFS_L_Control_Button2_0x3F7_MFS_ACC_CruiseSpdDecrease
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_ACAN_MFS_L_Control_Button2_0x3F7_MFS_ACC_CruiseSpdDecrease
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_ACAN_MFS_L_Control_Button2_0x3F7_MFS_ACC_CruiseCancel
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_ACAN_MFS_L_Control_Button2_0x3F7_MFS_ACC_CruiseCancel
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_ACAN_BCM_RLS_RLS_Solar_Right_PassgSide
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_ACAN_BCM_RLS_RLS_Solar_Right_PassgSide
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_ACAN_BCM_RLS_RLS_Solar_Left_Driveside
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_ACAN_BCM_RLS_RLS_Solar_Left_Driveside
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_ACAN_BCM_RLS_RLS_Rainfall_magnitude
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_ACAN_BCM_RLS_RLS_Rainfall_magnitude
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_ACAN_BCM_RLS_RLS_LightSensorError
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_ACAN_BCM_RLS_RLS_LightSensorError
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_ACAN_BCM_RLS_RLS_RainSensorError
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_ACAN_BCM_RLS_RLS_RainSensorError
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_ACAN_BCM_RLS_RLS_LightRequest
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_ACAN_BCM_RLS_RLS_LightRequest
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_ACAN_BCM_TPMS_Info2_TPMS_RFpressureSts
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_ACAN_BCM_TPMS_Info2_TPMS_RFpressureSts
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_ACAN_BCM_TPMS_Info2_TPMS_LFpressureSts
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_ACAN_BCM_TPMS_Info2_TPMS_LFpressureSts
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_ACAN_BCM_TPMS_Info2_TPMS_SysSts
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_ACAN_BCM_TPMS_Info2_TPMS_SysSts
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_ACAN_BCM_TPMS_Info2_TPMS_RRpressureSts
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_ACAN_BCM_TPMS_Info2_TPMS_RRpressureSts
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_ACAN_BCM_TPMS_Info2_TPMS_LRpressureSts
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_ACAN_BCM_TPMS_Info2_TPMS_LRpressureSts
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_ACAN_BCM_TPMS_Info2_TPMS_RRpressureV
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_ACAN_BCM_TPMS_Info2_TPMS_RRpressureV
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_ACAN_BCM_TPMS_Info2_TPMS_LRpressureV
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_ACAN_BCM_TPMS_Info2_TPMS_LRpressureV
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_ACAN_BCM_TPMS_Info2_TPMS_RFpressureV
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_ACAN_BCM_TPMS_Info2_TPMS_RFpressureV
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_ACAN_BCM_TPMS_Info2_TPMS_LFpressureV
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_ACAN_BCM_TPMS_Info2_TPMS_LFpressureV
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_ACAN_BCM_TPMS_Info2_TPMS_LFpressure
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_ACAN_BCM_TPMS_Info2_TPMS_LFpressure
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_ACAN_BCM_TPMS_Info2_TPMS_RFpressure
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_ACAN_BCM_TPMS_Info2_TPMS_RFpressure
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_ACAN_BCM_TPMS_Info2_TPMS_LRpressure
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_ACAN_BCM_TPMS_Info2_TPMS_LRpressure
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_ACAN_BCM_TPMS_Info2_TPMS_RRpressure
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_ACAN_BCM_TPMS_Info2_TPMS_RRpressure
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_ACAN_BCM_DoorState_0x4D4_BCM_CoverAjarStatus
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_ACAN_BCM_DoorState_0x4D4_BCM_CoverAjarStatus
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_ACAN_BCM_DoorState_0x4D4_BCM_TrunckAjarStatus
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_ACAN_BCM_DoorState_0x4D4_BCM_TrunckAjarStatus
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_ACAN_BCM_DoorState_0x4D4_BCM_DriverSideDoorAjarSts
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_ACAN_BCM_DoorState_0x4D4_BCM_DriverSideDoorAjarSts
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_ACAN_BCM_DoorState_0x4D4_BCM_CodriversSideDoorAjarSts
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_ACAN_BCM_DoorState_0x4D4_BCM_CodriversSideDoorAjarSts
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_ACAN_BCM_DoorState_0x4D4_BCM_RearLeftDoorAjarStatus
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_ACAN_BCM_DoorState_0x4D4_BCM_RearLeftDoorAjarStatus
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_ACAN_BCM_DoorState_0x4D4_BCM_RearRightDoorAjarStatus
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_ACAN_BCM_DoorState_0x4D4_BCM_RearRightDoorAjarStatus
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_ACAN_BCM_DoorState_0x4D4_BCM_DoorLockStatusRL
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_ACAN_BCM_DoorState_0x4D4_BCM_DoorLockStatusRL
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_ACAN_BCM_DoorState_0x4D4_BCM_DoorLockStatusRR
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_ACAN_BCM_DoorState_0x4D4_BCM_DoorLockStatusRR
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_ACAN_BCM_DoorState_0x4D4_BCM_DoorLockStatusCodrivres
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_ACAN_BCM_DoorState_0x4D4_BCM_DoorLockStatusCodrivres
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_ACAN_BCM_DoorState_0x4D4_BCM_DoorLockStatusDrv
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_ACAN_BCM_DoorState_0x4D4_BCM_DoorLockStatusDrv
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_ACAN_BCM_DoorState_0x4D4_BCM_ATWS_St
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_ACAN_BCM_DoorState_0x4D4_BCM_ATWS_St
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_ACAN_BCM_DoorState_0x4D4_BCM_TailGateSts
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_ACAN_BCM_DoorState_0x4D4_BCM_TailGateSts
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_Tcp_ReceiveSignal
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_Tcp_ReceiveSignal
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_Udp_ReceiveSignal
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_Udp_ReceiveSignal
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_TIME_SYNC_ARS_TSYNC_TimeStampGlobSec
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_TIME_SYNC_ARS_TSYNC_TimeStampGlobSec
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_TIME_SYNC_ARS_TSYNC_TimeStampGlobSec
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_TIME_SYNC_ARS_TSYNC_CRC16_Checksum
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_TIME_SYNC_ARS_TSYNC_CRC16_Checksum
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_TIME_SYNC_ARS_TSYNC_CRC16_Checksum
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_TIME_SYNC_ARS_TSYNC_TimeStampGlobNSec
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_TIME_SYNC_ARS_TSYNC_TimeStampGlobNSec
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_TIME_SYNC_ARS_TSYNC_TimeStampGlobNSec
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_TIME_SYNC_ARS_TSYNC_MaxTimeLeap
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_TIME_SYNC_ARS_TSYNC_MaxTimeLeap
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_TIME_SYNC_ARS_TSYNC_MaxTimeLeap
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_TIME_SYNC_ARS_TSYNC_LastTimeLeap
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_TIME_SYNC_ARS_TSYNC_LastTimeLeap
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_TIME_SYNC_ARS_TSYNC_LastTimeLeap
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_TIME_SYNC_ARS_TSYNC_MsgCounter
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_TIME_SYNC_ARS_TSYNC_MsgCounter
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_TIME_SYNC_ARS_TSYNC_MsgCounter
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_SYS_PERFORM_ARS_SP_TunnelFlag
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_SYS_PERFORM_ARS_SP_TunnelFlag
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_SYS_PERFORM_ARS_SP_CalibrationState
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_SYS_PERFORM_ARS_SP_CalibrationState
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_SYS_PERFORM_ARS_SP_OperationMode
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_SYS_PERFORM_ARS_SP_OperationMode
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_SYS_PERFORM_ARS_SP_AzimuthCorrection
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_SYS_PERFORM_ARS_SP_AzimuthCorrection
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_SYS_PERFORM_ARS_SP_ElevationCorrection
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_SYS_PERFORM_ARS_SP_ElevationCorrection
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_SYS_PERFORM_ARS_SP_ErrStateGroup_4
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_SYS_PERFORM_ARS_SP_ErrStateGroup_4
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_SYS_PERFORM_ARS_SP_VisibilityState
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_SYS_PERFORM_ARS_SP_VisibilityState
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_SYS_PERFORM_ARS_SP_VisibilityRange
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_SYS_PERFORM_ARS_SP_VisibilityRange
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_SYS_PERFORM_ARS_SP_MsgCounter
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_SYS_PERFORM_ARS_SP_MsgCounter
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_SYS_PERFORM_ARS_SP_MsgCounter
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_SYS_PERFORM_ARS_SP_CRC16_Checksum
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_SYS_PERFORM_ARS_SP_CRC16_Checksum
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_SYS_PERFORM_ARS_SP_CRC16_Checksum
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_SYS_PERFORM_ARS_SP_ErrStateGroup_1
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_SYS_PERFORM_ARS_SP_ErrStateGroup_1
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_SYS_PERFORM_ARS_SP_ErrStateGroup_1
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_SYS_PERFORM_ARS_SP_ErrStateGroup_2
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_SYS_PERFORM_ARS_SP_ErrStateGroup_2
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_SYS_PERFORM_ARS_SP_ErrStateGroup_2
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_SYS_PERFORM_ARS_SP_ErrStateGroup_3
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_SYS_PERFORM_ARS_SP_ErrStateGroup_3
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_SYS_PERFORM_ARS_SP_ErrStateGroup_3
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_Header_ARS_OD_TimeStampGlobSec
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_Header_ARS_OD_TimeStampGlobSec
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_Header_ARS_OD_TimeStampGlobSec
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_Header_ARS_OD_CycleCounter
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_Header_ARS_OD_CycleCounter
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_Header_ARS_OD_CycleCounter
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_Header_ARS_OD_NumOfObjects
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_Header_ARS_OD_NumOfObjects
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_Header_ARS_OD_NumOfObjects
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_Header_ARS_OD_TaskValidFlag
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_Header_ARS_OD_TaskValidFlag
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_Header_ARS_OD_TaskValidFlag
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_Header_ARS_OD_ExtendedCycleFlag
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_Header_ARS_OD_ExtendedCycleFlag
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_Header_ARS_OD_ExtendedCycleFlag
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_Header_ARS_OD_Latency
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_Header_ARS_OD_Latency
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_Header_ARS_OD_Latency
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_Header_ARS_OD_EgoVelocity
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_Header_ARS_OD_EgoVelocity
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_Header_ARS_OD_EgoVelocity
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_Header_ARS_OD_EgoYawRate
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_Header_ARS_OD_EgoYawRate
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_Header_ARS_OD_EgoYawRate
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_Header_ARS_OD_EgoVelocityStd
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_Header_ARS_OD_EgoVelocityStd
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_Header_ARS_OD_EgoVelocityStd
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_Header_ARS_OD_EgoAcceleration
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_Header_ARS_OD_EgoAcceleration
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_Header_ARS_OD_EgoAcceleration
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_Header_ARS_OD_EgoCurvature
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_Header_ARS_OD_EgoCurvature
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_Header_ARS_OD_EgoCurvature
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_Header_ARS_OD_MsgCounter_Header
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_Header_ARS_OD_MsgCounter_Header
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_Header_ARS_OD_MsgCounter_Header
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_Header_ARS_OD_CRC16_Checksum_Header
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_Header_ARS_OD_CRC16_Checksum_Header
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_Header_ARS_OD_CRC16_Checksum_Header
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_Header_ARS_OD_TimeStampGlobNanoSec
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_Header_ARS_OD_TimeStampGlobNanoSec
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_Header_ARS_OD_TimeStampGlobNanoSec
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_Header_ARS_OD_TimeStampLocal
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_Header_ARS_OD_TimeStampLocal
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_Header_ARS_OD_TimeStampLocal
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_Header_ARS_OD_MeasCounter
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_Header_ARS_OD_MeasCounter
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_Header_ARS_OD_MeasCounter
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_00_01_DistHeight_Obj_01
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_00_01_DistHeight_Obj_01
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_00_01_DistHeight_Obj_01
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_00_01_DistHeight_Obj_00
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_00_01_DistHeight_Obj_00
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_00_01_DistHeight_Obj_00
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_00_01_ARS_OD_DistX_Obj_00
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_00_01_ARS_OD_DistX_Obj_00
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_00_01_ARS_OD_DistX_Obj_00
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_00_01_ARS_OD_Classification_Obj_00
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_00_01_ARS_OD_Classification_Obj_00
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_00_01_ARS_OD_Classification_Obj_00
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_00_01_ARS_OD_AabsYStd_Obj_00
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_00_01_ARS_OD_AabsYStd_Obj_00
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_00_01_ARS_OD_AabsYStd_Obj_00
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_00_01_ARS_OD_ClassConf_Obj_00
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_00_01_ARS_OD_ClassConf_Obj_00
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_00_01_ARS_OD_ClassConf_Obj_00
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_00_01_ARS_OD_ProbOfExist_Obj_00
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_00_01_ARS_OD_ProbOfExist_Obj_00
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_00_01_ARS_OD_ProbOfExist_Obj_00
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_00_01_ARS_OD_DynConf_Obj_00
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_00_01_ARS_OD_DynConf_Obj_00
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_00_01_ARS_OD_DynConf_Obj_00
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_00_01_ARS_OD_VabsX_Obj_00
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_00_01_ARS_OD_VabsX_Obj_00
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_00_01_ARS_OD_VabsX_Obj_00
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_00_01_ARS_OD_DynProp_Obj_00
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_00_01_ARS_OD_DynProp_Obj_00
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_00_01_ARS_OD_DynProp_Obj_00
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_00_01_ARS_OD_MirrorProb_Obj_00
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_00_01_ARS_OD_MirrorProb_Obj_00
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_00_01_ARS_OD_MirrorProb_Obj_00
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_00_01_ARS_OD_Length_Obj_00
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_00_01_ARS_OD_Length_Obj_00
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_00_01_ARS_OD_Length_Obj_00
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_00_01_ARS_OD_MaintenanceState_Obj_00
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_00_01_ARS_OD_MaintenanceState_Obj_00
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_00_01_ARS_OD_MaintenanceState_Obj_00
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_00_01_ARS_OD_Width_Obj_00
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_00_01_ARS_OD_Width_Obj_00
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_00_01_ARS_OD_Width_Obj_00
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_00_01_ARS_OD_RCS_Obj_00
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_00_01_ARS_OD_RCS_Obj_00
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_00_01_ARS_OD_RCS_Obj_00
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_00_01_ARS_OD_Orientation_Obj_00
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_00_01_ARS_OD_Orientation_Obj_00
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_00_01_ARS_OD_Orientation_Obj_00
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_00_01_ARS_OD_YawRateAbs_Obj_00
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_00_01_ARS_OD_YawRateAbs_Obj_00
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_00_01_ARS_OD_YawRateAbs_Obj_00
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_00_01_ARS_OD_YawRateAbsStd_Obj_00
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_00_01_ARS_OD_YawRateAbsStd_Obj_00
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_00_01_ARS_OD_YawRateAbsStd_Obj_00
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_00_01_ARS_OD_RefPoint_Obj_00
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_00_01_ARS_OD_RefPoint_Obj_00
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_00_01_ARS_OD_RefPoint_Obj_00
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_00_01_ARS_OD_LifeCycle_Obj_00
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_00_01_ARS_OD_LifeCycle_Obj_00
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_00_01_ARS_OD_LifeCycle_Obj_00
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_00_01_ARS_OD_DistX_Obj_01
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_00_01_ARS_OD_DistX_Obj_01
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_00_01_ARS_OD_DistX_Obj_01
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_00_01_ARS_OD_VabsX_Obj_01
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_00_01_ARS_OD_VabsX_Obj_01
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_00_01_ARS_OD_VabsX_Obj_01
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_00_01_ARS_OD_AabsX_Obj_01
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_00_01_ARS_OD_AabsX_Obj_01
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_00_01_ARS_OD_AabsX_Obj_01
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_00_01_ARS_OD_AabsX_Obj_00
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_00_01_ARS_OD_AabsX_Obj_00
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_00_01_ARS_OD_AabsX_Obj_00
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_00_01_ARS_OD_DistY_Obj_01
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_00_01_ARS_OD_DistY_Obj_01
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_00_01_ARS_OD_DistY_Obj_01
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_00_01_ARS_OD_VabsY_Obj_01
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_00_01_ARS_OD_VabsY_Obj_01
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_00_01_ARS_OD_VabsY_Obj_01
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_00_01_ARS_OD_AabsY_Obj_01
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_00_01_ARS_OD_AabsY_Obj_01
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_00_01_ARS_OD_AabsY_Obj_01
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_00_01_ARS_OD_DistXStd_Obj_01
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_00_01_ARS_OD_DistXStd_Obj_01
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_00_01_ARS_OD_DistXStd_Obj_01
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_00_01_ARS_OD_DistYStd_Obj_01
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_00_01_ARS_OD_DistYStd_Obj_01
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_00_01_ARS_OD_DistYStd_Obj_01
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_00_01_ARS_OD_VabsXStd_Obj_01
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_00_01_ARS_OD_VabsXStd_Obj_01
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_00_01_ARS_OD_VabsXStd_Obj_01
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_00_01_ARS_OD_VabsYStd_Obj_01
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_00_01_ARS_OD_VabsYStd_Obj_01
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_00_01_ARS_OD_VabsYStd_Obj_01
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_00_01_ARS_OD_AabsXStd_Obj_01
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_00_01_ARS_OD_AabsXStd_Obj_01
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_00_01_ARS_OD_AabsXStd_Obj_01
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_00_01_ARS_OD_Classification_Obj_01
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_00_01_ARS_OD_Classification_Obj_01
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_00_01_ARS_OD_Classification_Obj_01
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_00_01_ARS_OD_AabsYStd_Obj_01
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_00_01_ARS_OD_AabsYStd_Obj_01
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_00_01_ARS_OD_AabsYStd_Obj_01
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_00_01_ARS_OD_ClassConf_Obj_01
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_00_01_ARS_OD_ClassConf_Obj_01
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_00_01_ARS_OD_ClassConf_Obj_01
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_00_01_ARS_OD_DistY_Obj_00
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_00_01_ARS_OD_DistY_Obj_00
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_00_01_ARS_OD_DistY_Obj_00
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_00_01_ARS_OD_ProbOfExist_Obj_01
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_00_01_ARS_OD_ProbOfExist_Obj_01
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_00_01_ARS_OD_ProbOfExist_Obj_01
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_00_01_ARS_OD_DynConf_Obj_01
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_00_01_ARS_OD_DynConf_Obj_01
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_00_01_ARS_OD_DynConf_Obj_01
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_00_01_ARS_OD_DynProp_Obj_01
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_00_01_ARS_OD_DynProp_Obj_01
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_00_01_ARS_OD_DynProp_Obj_01
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_00_01_ARS_OD_MirrorProb_Obj_01
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_00_01_ARS_OD_MirrorProb_Obj_01
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_00_01_ARS_OD_MirrorProb_Obj_01
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_00_01_ARS_OD_Length_Obj_01
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_00_01_ARS_OD_Length_Obj_01
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_00_01_ARS_OD_Length_Obj_01
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_00_01_ARS_OD_MaintenanceState_Obj_01
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_00_01_ARS_OD_MaintenanceState_Obj_01
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_00_01_ARS_OD_MaintenanceState_Obj_01
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_00_01_ARS_OD_Width_Obj_01
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_00_01_ARS_OD_Width_Obj_01
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_00_01_ARS_OD_Width_Obj_01
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_00_01_ARS_OD_RCS_Obj_01
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_00_01_ARS_OD_RCS_Obj_01
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_00_01_ARS_OD_RCS_Obj_01
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_00_01_ARS_OD_Orientation_Obj_01
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_00_01_ARS_OD_Orientation_Obj_01
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_00_01_ARS_OD_Orientation_Obj_01
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_00_01_ARS_OD_YawRateAbs_Obj_01
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_00_01_ARS_OD_YawRateAbs_Obj_01
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_00_01_ARS_OD_YawRateAbs_Obj_01
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_00_01_ARS_OD_YawRateAbsStd_Obj_01
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_00_01_ARS_OD_YawRateAbsStd_Obj_01
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_00_01_ARS_OD_YawRateAbsStd_Obj_01
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_00_01_ARS_OD_RefPoint_Obj_01
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_00_01_ARS_OD_RefPoint_Obj_01
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_00_01_ARS_OD_RefPoint_Obj_01
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_00_01_ARS_OD_LifeCycle_Obj_01
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_00_01_ARS_OD_LifeCycle_Obj_01
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_00_01_ARS_OD_LifeCycle_Obj_01
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_00_01_ARS_OD_OrientationStd_Obj_00
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_00_01_ARS_OD_OrientationStd_Obj_00
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_00_01_ARS_OD_OrientationStd_Obj_00
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_00_01_ARS_OD_OrientationStd_Obj_01
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_00_01_ARS_OD_OrientationStd_Obj_01
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_00_01_ARS_OD_OrientationStd_Obj_01
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_00_01_ARS_OD_ObstacleProb_Obj_00
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_00_01_ARS_OD_ObstacleProb_Obj_00
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_00_01_ARS_OD_ObstacleProb_Obj_00
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_00_01_ARS_OD_MicroDopplerFlag_00
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_00_01_ARS_OD_MicroDopplerFlag_00
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_00_01_ARS_OD_MicroDopplerFlag_00
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_00_01_ARS_OD_ObstacleProb_Obj_01
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_00_01_ARS_OD_ObstacleProb_Obj_01
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_00_01_ARS_OD_ObstacleProb_Obj_01
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_00_01_ARS_OD_VabsY_Obj_00
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_00_01_ARS_OD_VabsY_Obj_00
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_00_01_ARS_OD_VabsY_Obj_00
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_00_01_ARS_OD_MicroDopplerFlag_01
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_00_01_ARS_OD_MicroDopplerFlag_01
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_00_01_ARS_OD_MicroDopplerFlag_01
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_00_01_ARS_OD_ID_00
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_00_01_ARS_OD_ID_00
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_00_01_ARS_OD_ID_00
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_00_01_ARS_OD_ID_01
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_00_01_ARS_OD_ID_01
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_00_01_ARS_OD_ID_01
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_00_01_ARS_OD_MsgCounter_Obj_00_01
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_00_01_ARS_OD_MsgCounter_Obj_00_01
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_00_01_ARS_OD_MsgCounter_Obj_00_01
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_00_01_ARS_OD_CRC16_Checksum_Obj_00_01
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_00_01_ARS_OD_CRC16_Checksum_Obj_00_01
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_00_01_ARS_OD_CRC16_Checksum_Obj_00_01
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_00_01_ARS_OD_AabsY_Obj_00
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_00_01_ARS_OD_AabsY_Obj_00
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_00_01_ARS_OD_AabsY_Obj_00
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_00_01_ARS_OD_DistXStd_Obj_00
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_00_01_ARS_OD_DistXStd_Obj_00
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_00_01_ARS_OD_DistXStd_Obj_00
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_00_01_ARS_OD_DistYStd_Obj_00
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_00_01_ARS_OD_DistYStd_Obj_00
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_00_01_ARS_OD_DistYStd_Obj_00
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_00_01_ARS_OD_VabsXStd_Obj_00
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_00_01_ARS_OD_VabsXStd_Obj_00
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_00_01_ARS_OD_VabsXStd_Obj_00
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_00_01_ARS_OD_VabsYStd_Obj_00
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_00_01_ARS_OD_VabsYStd_Obj_00
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_00_01_ARS_OD_VabsYStd_Obj_00
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_00_01_ARS_OD_AabsXStd_Obj_00
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_00_01_ARS_OD_AabsXStd_Obj_00
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_00_01_ARS_OD_AabsXStd_Obj_00
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_02_03_DistHeight_Obj_02
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_02_03_DistHeight_Obj_02
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_02_03_DistHeight_Obj_02
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_02_03_DistHeight_Obj_03
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_02_03_DistHeight_Obj_03
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_02_03_DistHeight_Obj_03
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_02_03_ARS_OD_DistX_Obj_02
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_02_03_ARS_OD_DistX_Obj_02
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_02_03_ARS_OD_DistX_Obj_02
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_02_03_ARS_OD_Classification_Obj_02
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_02_03_ARS_OD_Classification_Obj_02
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_02_03_ARS_OD_Classification_Obj_02
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_02_03_ARS_OD_AabsYStd_Obj_02
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_02_03_ARS_OD_AabsYStd_Obj_02
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_02_03_ARS_OD_AabsYStd_Obj_02
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_02_03_ARS_OD_ClassConf_Obj_02
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_02_03_ARS_OD_ClassConf_Obj_02
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_02_03_ARS_OD_ClassConf_Obj_02
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_02_03_ARS_OD_ProbOfExist_Obj_02
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_02_03_ARS_OD_ProbOfExist_Obj_02
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_02_03_ARS_OD_ProbOfExist_Obj_02
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_02_03_ARS_OD_DynConf_Obj_02
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_02_03_ARS_OD_DynConf_Obj_02
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_02_03_ARS_OD_DynConf_Obj_02
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_02_03_ARS_OD_VabsX_Obj_02
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_02_03_ARS_OD_VabsX_Obj_02
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_02_03_ARS_OD_VabsX_Obj_02
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_02_03_ARS_OD_DynProp_Obj_02
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_02_03_ARS_OD_DynProp_Obj_02
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_02_03_ARS_OD_DynProp_Obj_02
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_02_03_ARS_OD_MirrorProb_Obj_02
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_02_03_ARS_OD_MirrorProb_Obj_02
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_02_03_ARS_OD_MirrorProb_Obj_02
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_02_03_ARS_OD_Length_Obj_02
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_02_03_ARS_OD_Length_Obj_02
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_02_03_ARS_OD_Length_Obj_02
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_02_03_ARS_OD_MaintenanceState_Obj_02
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_02_03_ARS_OD_MaintenanceState_Obj_02
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_02_03_ARS_OD_MaintenanceState_Obj_02
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_02_03_ARS_OD_Width_Obj_02
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_02_03_ARS_OD_Width_Obj_02
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_02_03_ARS_OD_Width_Obj_02
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_02_03_ARS_OD_RCS_Obj_02
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_02_03_ARS_OD_RCS_Obj_02
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_02_03_ARS_OD_RCS_Obj_02
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_02_03_ARS_OD_Orientation_Obj_02
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_02_03_ARS_OD_Orientation_Obj_02
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_02_03_ARS_OD_Orientation_Obj_02
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_02_03_ARS_OD_YawRateAbs_Obj_02
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_02_03_ARS_OD_YawRateAbs_Obj_02
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_02_03_ARS_OD_YawRateAbs_Obj_02
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_02_03_ARS_OD_YawRateAbsStd_Obj_02
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_02_03_ARS_OD_YawRateAbsStd_Obj_02
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_02_03_ARS_OD_YawRateAbsStd_Obj_02
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_02_03_ARS_OD_RefPoint_Obj_02
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_02_03_ARS_OD_RefPoint_Obj_02
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_02_03_ARS_OD_RefPoint_Obj_02
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_02_03_ARS_OD_LifeCycle_Obj_02
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_02_03_ARS_OD_LifeCycle_Obj_02
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_02_03_ARS_OD_LifeCycle_Obj_02
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_02_03_ARS_OD_DistX_Obj_03
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_02_03_ARS_OD_DistX_Obj_03
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_02_03_ARS_OD_DistX_Obj_03
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_02_03_ARS_OD_VabsX_Obj_03
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_02_03_ARS_OD_VabsX_Obj_03
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_02_03_ARS_OD_VabsX_Obj_03
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_02_03_ARS_OD_AabsX_Obj_03
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_02_03_ARS_OD_AabsX_Obj_03
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_02_03_ARS_OD_AabsX_Obj_03
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_02_03_ARS_OD_AabsX_Obj_02
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_02_03_ARS_OD_AabsX_Obj_02
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_02_03_ARS_OD_AabsX_Obj_02
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_02_03_ARS_OD_DistY_Obj_03
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_02_03_ARS_OD_DistY_Obj_03
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_02_03_ARS_OD_DistY_Obj_03
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_02_03_ARS_OD_VabsY_Obj_03
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_02_03_ARS_OD_VabsY_Obj_03
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_02_03_ARS_OD_VabsY_Obj_03
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_02_03_ARS_OD_AabsY_Obj_03
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_02_03_ARS_OD_AabsY_Obj_03
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_02_03_ARS_OD_AabsY_Obj_03
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_02_03_ARS_OD_DistXStd_Obj_03
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_02_03_ARS_OD_DistXStd_Obj_03
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_02_03_ARS_OD_DistXStd_Obj_03
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_02_03_ARS_OD_DistYStd_Obj_03
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_02_03_ARS_OD_DistYStd_Obj_03
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_02_03_ARS_OD_DistYStd_Obj_03
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_02_03_ARS_OD_VabsXStd_Obj_03
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_02_03_ARS_OD_VabsXStd_Obj_03
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_02_03_ARS_OD_VabsXStd_Obj_03
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_02_03_ARS_OD_VabsYStd_Obj_03
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_02_03_ARS_OD_VabsYStd_Obj_03
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_02_03_ARS_OD_VabsYStd_Obj_03
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_02_03_ARS_OD_AabsXStd_Obj_03
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_02_03_ARS_OD_AabsXStd_Obj_03
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_02_03_ARS_OD_AabsXStd_Obj_03
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_02_03_ARS_OD_Classification_Obj_03
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_02_03_ARS_OD_Classification_Obj_03
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_02_03_ARS_OD_Classification_Obj_03
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_02_03_ARS_OD_AabsYStd_Obj_03
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_02_03_ARS_OD_AabsYStd_Obj_03
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_02_03_ARS_OD_AabsYStd_Obj_03
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_02_03_ARS_OD_ClassConf_Obj_03
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_02_03_ARS_OD_ClassConf_Obj_03
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_02_03_ARS_OD_ClassConf_Obj_03
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_02_03_ARS_OD_DistY_Obj_02
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_02_03_ARS_OD_DistY_Obj_02
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_02_03_ARS_OD_DistY_Obj_02
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_02_03_ARS_OD_ProbOfExist_Obj_03
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_02_03_ARS_OD_ProbOfExist_Obj_03
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_02_03_ARS_OD_ProbOfExist_Obj_03
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_02_03_ARS_OD_DynConf_Obj_03
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_02_03_ARS_OD_DynConf_Obj_03
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_02_03_ARS_OD_DynConf_Obj_03
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_02_03_ARS_OD_DynProp_Obj_03
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_02_03_ARS_OD_DynProp_Obj_03
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_02_03_ARS_OD_DynProp_Obj_03
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_02_03_ARS_OD_MirrorProb_Obj_03
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_02_03_ARS_OD_MirrorProb_Obj_03
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_02_03_ARS_OD_MirrorProb_Obj_03
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_02_03_ARS_OD_Length_Obj_03
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_02_03_ARS_OD_Length_Obj_03
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_02_03_ARS_OD_Length_Obj_03
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_02_03_ARS_OD_MaintenanceState_Obj_03
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_02_03_ARS_OD_MaintenanceState_Obj_03
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_02_03_ARS_OD_MaintenanceState_Obj_03
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_02_03_ARS_OD_Width_Obj_03
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_02_03_ARS_OD_Width_Obj_03
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_02_03_ARS_OD_Width_Obj_03
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_02_03_ARS_OD_RCS_Obj_03
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_02_03_ARS_OD_RCS_Obj_03
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_02_03_ARS_OD_RCS_Obj_03
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_02_03_ARS_OD_Orientation_Obj_03
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_02_03_ARS_OD_Orientation_Obj_03
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_02_03_ARS_OD_Orientation_Obj_03
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_02_03_ARS_OD_YawRateAbs_Obj_03
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_02_03_ARS_OD_YawRateAbs_Obj_03
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_02_03_ARS_OD_YawRateAbs_Obj_03
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_02_03_ARS_OD_YawRateAbsStd_Obj_03
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_02_03_ARS_OD_YawRateAbsStd_Obj_03
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_02_03_ARS_OD_YawRateAbsStd_Obj_03
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_02_03_ARS_OD_RefPoint_Obj_03
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_02_03_ARS_OD_RefPoint_Obj_03
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_02_03_ARS_OD_RefPoint_Obj_03
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_02_03_ARS_OD_LifeCycle_Obj_03
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_02_03_ARS_OD_LifeCycle_Obj_03
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_02_03_ARS_OD_LifeCycle_Obj_03
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_02_03_ARS_OD_OrientationStd_Obj_02
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_02_03_ARS_OD_OrientationStd_Obj_02
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_02_03_ARS_OD_OrientationStd_Obj_02
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_02_03_ARS_OD_OrientationStd_Obj_03
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_02_03_ARS_OD_OrientationStd_Obj_03
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_02_03_ARS_OD_OrientationStd_Obj_03
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_02_03_ARS_OD_ObstacleProb_Obj_02
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_02_03_ARS_OD_ObstacleProb_Obj_02
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_02_03_ARS_OD_ObstacleProb_Obj_02
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_02_03_ARS_OD_MicroDopplerFlag_02
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_02_03_ARS_OD_MicroDopplerFlag_02
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_02_03_ARS_OD_MicroDopplerFlag_02
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_02_03_ARS_OD_ObstacleProb_Obj_03
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_02_03_ARS_OD_ObstacleProb_Obj_03
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_02_03_ARS_OD_ObstacleProb_Obj_03
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_02_03_ARS_OD_VabsY_Obj_02
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_02_03_ARS_OD_VabsY_Obj_02
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_02_03_ARS_OD_VabsY_Obj_02
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_02_03_ARS_OD_MicroDopplerFlag_03
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_02_03_ARS_OD_MicroDopplerFlag_03
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_02_03_ARS_OD_MicroDopplerFlag_03
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_02_03_ARS_OD_ID_02
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_02_03_ARS_OD_ID_02
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_02_03_ARS_OD_ID_02
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_02_03_ARS_OD_ID_03
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_02_03_ARS_OD_ID_03
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_02_03_ARS_OD_ID_03
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_02_03_ARS_OD_MsgCounter_Obj_02_03
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_02_03_ARS_OD_MsgCounter_Obj_02_03
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_02_03_ARS_OD_MsgCounter_Obj_02_03
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_02_03_ARS_OD_CRC16_Checksum_Obj_02_03
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_02_03_ARS_OD_CRC16_Checksum_Obj_02_03
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_02_03_ARS_OD_CRC16_Checksum_Obj_02_03
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_02_03_ARS_OD_AabsY_Obj_02
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_02_03_ARS_OD_AabsY_Obj_02
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_02_03_ARS_OD_AabsY_Obj_02
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_02_03_ARS_OD_DistXStd_Obj_02
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_02_03_ARS_OD_DistXStd_Obj_02
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_02_03_ARS_OD_DistXStd_Obj_02
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_02_03_ARS_OD_DistYStd_Obj_02
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_02_03_ARS_OD_DistYStd_Obj_02
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_02_03_ARS_OD_DistYStd_Obj_02
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_02_03_ARS_OD_VabsXStd_Obj_02
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_02_03_ARS_OD_VabsXStd_Obj_02
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_02_03_ARS_OD_VabsXStd_Obj_02
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_02_03_ARS_OD_VabsYStd_Obj_02
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_02_03_ARS_OD_VabsYStd_Obj_02
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_02_03_ARS_OD_VabsYStd_Obj_02
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_02_03_ARS_OD_AabsXStd_Obj_02
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_02_03_ARS_OD_AabsXStd_Obj_02
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_02_03_ARS_OD_AabsXStd_Obj_02
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_04_05_DistHeight_Obj_04
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_04_05_DistHeight_Obj_04
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_04_05_DistHeight_Obj_04
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_04_05_DistHeight_Obj_05
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_04_05_DistHeight_Obj_05
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_04_05_DistHeight_Obj_05
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_04_05_ARS_OD_DistX_Obj_04
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_04_05_ARS_OD_DistX_Obj_04
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_04_05_ARS_OD_DistX_Obj_04
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_04_05_ARS_OD_Classification_Obj_04
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_04_05_ARS_OD_Classification_Obj_04
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_04_05_ARS_OD_Classification_Obj_04
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_04_05_ARS_OD_AabsYStd_Obj_04
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_04_05_ARS_OD_AabsYStd_Obj_04
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_04_05_ARS_OD_AabsYStd_Obj_04
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_04_05_ARS_OD_ClassConf_Obj_04
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_04_05_ARS_OD_ClassConf_Obj_04
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_04_05_ARS_OD_ClassConf_Obj_04
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_04_05_ARS_OD_ProbOfExist_Obj_04
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_04_05_ARS_OD_ProbOfExist_Obj_04
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_04_05_ARS_OD_ProbOfExist_Obj_04
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_04_05_ARS_OD_DynConf_Obj_04
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_04_05_ARS_OD_DynConf_Obj_04
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_04_05_ARS_OD_DynConf_Obj_04
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_04_05_ARS_OD_VabsX_Obj_04
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_04_05_ARS_OD_VabsX_Obj_04
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_04_05_ARS_OD_VabsX_Obj_04
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_04_05_ARS_OD_DynProp_Obj_04
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_04_05_ARS_OD_DynProp_Obj_04
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_04_05_ARS_OD_DynProp_Obj_04
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_04_05_ARS_OD_MirrorProb_Obj_04
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_04_05_ARS_OD_MirrorProb_Obj_04
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_04_05_ARS_OD_MirrorProb_Obj_04
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_04_05_ARS_OD_Length_Obj_04
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_04_05_ARS_OD_Length_Obj_04
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_04_05_ARS_OD_Length_Obj_04
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_04_05_ARS_OD_MaintenanceState_Obj_04
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_04_05_ARS_OD_MaintenanceState_Obj_04
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_04_05_ARS_OD_MaintenanceState_Obj_04
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_04_05_ARS_OD_Width_Obj_04
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_04_05_ARS_OD_Width_Obj_04
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_04_05_ARS_OD_Width_Obj_04
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_04_05_ARS_OD_RCS_Obj_04
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_04_05_ARS_OD_RCS_Obj_04
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_04_05_ARS_OD_RCS_Obj_04
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_04_05_ARS_OD_Orientation_Obj_04
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_04_05_ARS_OD_Orientation_Obj_04
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_04_05_ARS_OD_Orientation_Obj_04
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_04_05_ARS_OD_YawRateAbs_Obj_04
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_04_05_ARS_OD_YawRateAbs_Obj_04
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_04_05_ARS_OD_YawRateAbs_Obj_04
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_04_05_ARS_OD_YawRateAbsStd_Obj_04
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_04_05_ARS_OD_YawRateAbsStd_Obj_04
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_04_05_ARS_OD_YawRateAbsStd_Obj_04
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_04_05_ARS_OD_RefPoint_Obj_04
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_04_05_ARS_OD_RefPoint_Obj_04
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_04_05_ARS_OD_RefPoint_Obj_04
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_04_05_ARS_OD_LifeCycle_Obj_04
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_04_05_ARS_OD_LifeCycle_Obj_04
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_04_05_ARS_OD_LifeCycle_Obj_04
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_04_05_ARS_OD_DistX_Obj_05
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_04_05_ARS_OD_DistX_Obj_05
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_04_05_ARS_OD_DistX_Obj_05
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_04_05_ARS_OD_VabsX_Obj_05
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_04_05_ARS_OD_VabsX_Obj_05
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_04_05_ARS_OD_VabsX_Obj_05
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_04_05_ARS_OD_AabsX_Obj_05
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_04_05_ARS_OD_AabsX_Obj_05
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_04_05_ARS_OD_AabsX_Obj_05
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_04_05_ARS_OD_AabsX_Obj_04
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_04_05_ARS_OD_AabsX_Obj_04
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_04_05_ARS_OD_AabsX_Obj_04
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_04_05_ARS_OD_DistY_Obj_05
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_04_05_ARS_OD_DistY_Obj_05
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_04_05_ARS_OD_DistY_Obj_05
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_04_05_ARS_OD_VabsY_Obj_05
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_04_05_ARS_OD_VabsY_Obj_05
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_04_05_ARS_OD_VabsY_Obj_05
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_04_05_ARS_OD_AabsY_Obj_05
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_04_05_ARS_OD_AabsY_Obj_05
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_04_05_ARS_OD_AabsY_Obj_05
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_04_05_ARS_OD_DistXStd_Obj_05
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_04_05_ARS_OD_DistXStd_Obj_05
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_04_05_ARS_OD_DistXStd_Obj_05
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_04_05_ARS_OD_DistYStd_Obj_05
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_04_05_ARS_OD_DistYStd_Obj_05
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_04_05_ARS_OD_DistYStd_Obj_05
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_04_05_ARS_OD_VabsXStd_Obj_05
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_04_05_ARS_OD_VabsXStd_Obj_05
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_04_05_ARS_OD_VabsXStd_Obj_05
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_04_05_ARS_OD_VabsYStd_Obj_05
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_04_05_ARS_OD_VabsYStd_Obj_05
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_04_05_ARS_OD_VabsYStd_Obj_05
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_04_05_ARS_OD_AabsXStd_Obj_05
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_04_05_ARS_OD_AabsXStd_Obj_05
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_04_05_ARS_OD_AabsXStd_Obj_05
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_04_05_ARS_OD_Classification_Obj_05
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_04_05_ARS_OD_Classification_Obj_05
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_04_05_ARS_OD_Classification_Obj_05
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_04_05_ARS_OD_AabsYStd_Obj_05
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_04_05_ARS_OD_AabsYStd_Obj_05
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_04_05_ARS_OD_AabsYStd_Obj_05
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_04_05_ARS_OD_ClassConf_Obj_05
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_04_05_ARS_OD_ClassConf_Obj_05
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_04_05_ARS_OD_ClassConf_Obj_05
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_04_05_ARS_OD_DistY_Obj_04
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_04_05_ARS_OD_DistY_Obj_04
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_04_05_ARS_OD_DistY_Obj_04
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_04_05_ARS_OD_ProbOfExist_Obj_05
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_04_05_ARS_OD_ProbOfExist_Obj_05
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_04_05_ARS_OD_ProbOfExist_Obj_05
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_04_05_ARS_OD_DynConf_Obj_05
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_04_05_ARS_OD_DynConf_Obj_05
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_04_05_ARS_OD_DynConf_Obj_05
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_04_05_ARS_OD_DynProp_Obj_05
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_04_05_ARS_OD_DynProp_Obj_05
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_04_05_ARS_OD_DynProp_Obj_05
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_04_05_ARS_OD_MirrorProb_Obj_05
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_04_05_ARS_OD_MirrorProb_Obj_05
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_04_05_ARS_OD_MirrorProb_Obj_05
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_04_05_ARS_OD_Length_Obj_05
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_04_05_ARS_OD_Length_Obj_05
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_04_05_ARS_OD_Length_Obj_05
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_04_05_ARS_OD_MaintenanceState_Obj_05
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_04_05_ARS_OD_MaintenanceState_Obj_05
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_04_05_ARS_OD_MaintenanceState_Obj_05
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_04_05_ARS_OD_Width_Obj_05
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_04_05_ARS_OD_Width_Obj_05
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_04_05_ARS_OD_Width_Obj_05
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_04_05_ARS_OD_RCS_Obj_05
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_04_05_ARS_OD_RCS_Obj_05
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_04_05_ARS_OD_RCS_Obj_05
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_04_05_ARS_OD_Orientation_Obj_05
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_04_05_ARS_OD_Orientation_Obj_05
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_04_05_ARS_OD_Orientation_Obj_05
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_04_05_ARS_OD_YawRateAbs_Obj_05
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_04_05_ARS_OD_YawRateAbs_Obj_05
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_04_05_ARS_OD_YawRateAbs_Obj_05
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_04_05_ARS_OD_YawRateAbsStd_Obj_05
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_04_05_ARS_OD_YawRateAbsStd_Obj_05
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_04_05_ARS_OD_YawRateAbsStd_Obj_05
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_04_05_ARS_OD_RefPoint_Obj_05
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_04_05_ARS_OD_RefPoint_Obj_05
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_04_05_ARS_OD_RefPoint_Obj_05
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_04_05_ARS_OD_LifeCycle_Obj_05
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_04_05_ARS_OD_LifeCycle_Obj_05
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_04_05_ARS_OD_LifeCycle_Obj_05
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_04_05_ARS_OD_OrientationStd_Obj_04
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_04_05_ARS_OD_OrientationStd_Obj_04
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_04_05_ARS_OD_OrientationStd_Obj_04
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_04_05_ARS_OD_OrientationStd_Obj_05
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_04_05_ARS_OD_OrientationStd_Obj_05
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_04_05_ARS_OD_OrientationStd_Obj_05
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_04_05_ARS_OD_ObstacleProb_Obj_04
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_04_05_ARS_OD_ObstacleProb_Obj_04
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_04_05_ARS_OD_ObstacleProb_Obj_04
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_04_05_ARS_OD_MicroDopplerFlag_04
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_04_05_ARS_OD_MicroDopplerFlag_04
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_04_05_ARS_OD_MicroDopplerFlag_04
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_04_05_ARS_OD_ObstacleProb_Obj_05
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_04_05_ARS_OD_ObstacleProb_Obj_05
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_04_05_ARS_OD_ObstacleProb_Obj_05
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_04_05_ARS_OD_VabsY_Obj_04
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_04_05_ARS_OD_VabsY_Obj_04
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_04_05_ARS_OD_VabsY_Obj_04
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_04_05_ARS_OD_MicroDopplerFlag_05
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_04_05_ARS_OD_MicroDopplerFlag_05
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_04_05_ARS_OD_MicroDopplerFlag_05
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_04_05_ARS_OD_ID_04
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_04_05_ARS_OD_ID_04
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_04_05_ARS_OD_ID_04
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_04_05_ARS_OD_ID_05
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_04_05_ARS_OD_ID_05
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_04_05_ARS_OD_ID_05
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_04_05_ARS_OD_MsgCounter_Obj_04_05
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_04_05_ARS_OD_MsgCounter_Obj_04_05
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_04_05_ARS_OD_MsgCounter_Obj_04_05
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_04_05_ARS_OD_CRC16_Checksum_Obj_04_05
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_04_05_ARS_OD_CRC16_Checksum_Obj_04_05
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_04_05_ARS_OD_CRC16_Checksum_Obj_04_05
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_04_05_ARS_OD_AabsY_Obj_04
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_04_05_ARS_OD_AabsY_Obj_04
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_04_05_ARS_OD_AabsY_Obj_04
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_04_05_ARS_OD_DistXStd_Obj_04
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_04_05_ARS_OD_DistXStd_Obj_04
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_04_05_ARS_OD_DistXStd_Obj_04
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_04_05_ARS_OD_DistYStd_Obj_04
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_04_05_ARS_OD_DistYStd_Obj_04
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_04_05_ARS_OD_DistYStd_Obj_04
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_04_05_ARS_OD_VabsXStd_Obj_04
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_04_05_ARS_OD_VabsXStd_Obj_04
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_04_05_ARS_OD_VabsXStd_Obj_04
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_04_05_ARS_OD_VabsYStd_Obj_04
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_04_05_ARS_OD_VabsYStd_Obj_04
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_04_05_ARS_OD_VabsYStd_Obj_04
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_04_05_ARS_OD_AabsXStd_Obj_04
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_04_05_ARS_OD_AabsXStd_Obj_04
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_04_05_ARS_OD_AabsXStd_Obj_04
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_06_07_DistHeight_Obj_07
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_06_07_DistHeight_Obj_07
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_06_07_DistHeight_Obj_07
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_06_07_DistHeight_Obj_06
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_06_07_DistHeight_Obj_06
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_06_07_DistHeight_Obj_06
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_06_07_ARS_OD_DistX_Obj_06
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_06_07_ARS_OD_DistX_Obj_06
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_06_07_ARS_OD_DistX_Obj_06
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_06_07_ARS_OD_Classification_Obj_06
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_06_07_ARS_OD_Classification_Obj_06
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_06_07_ARS_OD_Classification_Obj_06
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_06_07_ARS_OD_AabsYStd_Obj_06
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_06_07_ARS_OD_AabsYStd_Obj_06
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_06_07_ARS_OD_AabsYStd_Obj_06
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_06_07_ARS_OD_ClassConf_Obj_06
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_06_07_ARS_OD_ClassConf_Obj_06
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_06_07_ARS_OD_ClassConf_Obj_06
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_06_07_ARS_OD_ProbOfExist_Obj_06
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_06_07_ARS_OD_ProbOfExist_Obj_06
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_06_07_ARS_OD_ProbOfExist_Obj_06
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_06_07_ARS_OD_DynConf_Obj_06
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_06_07_ARS_OD_DynConf_Obj_06
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_06_07_ARS_OD_DynConf_Obj_06
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_06_07_ARS_OD_VabsX_Obj_06
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_06_07_ARS_OD_VabsX_Obj_06
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_06_07_ARS_OD_VabsX_Obj_06
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_06_07_ARS_OD_DynProp_Obj_06
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_06_07_ARS_OD_DynProp_Obj_06
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_06_07_ARS_OD_DynProp_Obj_06
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_06_07_ARS_OD_MirrorProb_Obj_06
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_06_07_ARS_OD_MirrorProb_Obj_06
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_06_07_ARS_OD_MirrorProb_Obj_06
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_06_07_ARS_OD_Length_Obj_06
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_06_07_ARS_OD_Length_Obj_06
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_06_07_ARS_OD_Length_Obj_06
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_06_07_ARS_OD_MaintenanceState_Obj_06
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_06_07_ARS_OD_MaintenanceState_Obj_06
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_06_07_ARS_OD_MaintenanceState_Obj_06
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_06_07_ARS_OD_Width_Obj_06
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_06_07_ARS_OD_Width_Obj_06
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_06_07_ARS_OD_Width_Obj_06
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_06_07_ARS_OD_RCS_Obj_06
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_06_07_ARS_OD_RCS_Obj_06
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_06_07_ARS_OD_RCS_Obj_06
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_06_07_ARS_OD_Orientation_Obj_06
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_06_07_ARS_OD_Orientation_Obj_06
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_06_07_ARS_OD_Orientation_Obj_06
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_06_07_ARS_OD_YawRateAbs_Obj_06
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_06_07_ARS_OD_YawRateAbs_Obj_06
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_06_07_ARS_OD_YawRateAbs_Obj_06
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_06_07_ARS_OD_YawRateAbsStd_Obj_06
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_06_07_ARS_OD_YawRateAbsStd_Obj_06
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_06_07_ARS_OD_YawRateAbsStd_Obj_06
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_06_07_ARS_OD_RefPoint_Obj_06
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_06_07_ARS_OD_RefPoint_Obj_06
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_06_07_ARS_OD_RefPoint_Obj_06
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_06_07_ARS_OD_LifeCycle_Obj_06
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_06_07_ARS_OD_LifeCycle_Obj_06
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_06_07_ARS_OD_LifeCycle_Obj_06
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_06_07_ARS_OD_DistX_Obj_07
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_06_07_ARS_OD_DistX_Obj_07
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_06_07_ARS_OD_DistX_Obj_07
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_06_07_ARS_OD_VabsX_Obj_07
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_06_07_ARS_OD_VabsX_Obj_07
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_06_07_ARS_OD_VabsX_Obj_07
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_06_07_ARS_OD_AabsX_Obj_07
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_06_07_ARS_OD_AabsX_Obj_07
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_06_07_ARS_OD_AabsX_Obj_07
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_06_07_ARS_OD_AabsX_Obj_06
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_06_07_ARS_OD_AabsX_Obj_06
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_06_07_ARS_OD_AabsX_Obj_06
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_06_07_ARS_OD_DistY_Obj_07
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_06_07_ARS_OD_DistY_Obj_07
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_06_07_ARS_OD_DistY_Obj_07
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_06_07_ARS_OD_VabsY_Obj_07
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_06_07_ARS_OD_VabsY_Obj_07
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_06_07_ARS_OD_VabsY_Obj_07
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_06_07_ARS_OD_AabsY_Obj_07
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_06_07_ARS_OD_AabsY_Obj_07
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_06_07_ARS_OD_AabsY_Obj_07
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_06_07_ARS_OD_DistXStd_Obj_07
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_06_07_ARS_OD_DistXStd_Obj_07
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_06_07_ARS_OD_DistXStd_Obj_07
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_06_07_ARS_OD_DistYStd_Obj_07
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_06_07_ARS_OD_DistYStd_Obj_07
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_06_07_ARS_OD_DistYStd_Obj_07
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_06_07_ARS_OD_VabsXStd_Obj_07
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_06_07_ARS_OD_VabsXStd_Obj_07
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_06_07_ARS_OD_VabsXStd_Obj_07
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_06_07_ARS_OD_VabsYStd_Obj_07
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_06_07_ARS_OD_VabsYStd_Obj_07
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_06_07_ARS_OD_VabsYStd_Obj_07
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_06_07_ARS_OD_AabsXStd_Obj_07
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_06_07_ARS_OD_AabsXStd_Obj_07
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_06_07_ARS_OD_AabsXStd_Obj_07
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_06_07_ARS_OD_Classification_Obj_07
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_06_07_ARS_OD_Classification_Obj_07
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_06_07_ARS_OD_Classification_Obj_07
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_06_07_ARS_OD_AabsYStd_Obj_07
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_06_07_ARS_OD_AabsYStd_Obj_07
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_06_07_ARS_OD_AabsYStd_Obj_07
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_06_07_ARS_OD_ClassConf_Obj_07
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_06_07_ARS_OD_ClassConf_Obj_07
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_06_07_ARS_OD_ClassConf_Obj_07
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_06_07_ARS_OD_DistY_Obj_06
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_06_07_ARS_OD_DistY_Obj_06
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_06_07_ARS_OD_DistY_Obj_06
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_06_07_ARS_OD_ProbOfExist_Obj_07
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_06_07_ARS_OD_ProbOfExist_Obj_07
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_06_07_ARS_OD_ProbOfExist_Obj_07
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_06_07_ARS_OD_DynConf_Obj_07
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_06_07_ARS_OD_DynConf_Obj_07
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_06_07_ARS_OD_DynConf_Obj_07
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_06_07_ARS_OD_DynProp_Obj_07
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_06_07_ARS_OD_DynProp_Obj_07
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_06_07_ARS_OD_DynProp_Obj_07
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_06_07_ARS_OD_MirrorProb_Obj_07
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_06_07_ARS_OD_MirrorProb_Obj_07
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_06_07_ARS_OD_MirrorProb_Obj_07
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_06_07_ARS_OD_Length_Obj_07
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_06_07_ARS_OD_Length_Obj_07
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_06_07_ARS_OD_Length_Obj_07
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_06_07_ARS_OD_MaintenanceState_Obj_07
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_06_07_ARS_OD_MaintenanceState_Obj_07
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_06_07_ARS_OD_MaintenanceState_Obj_07
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_06_07_ARS_OD_Width_Obj_07
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_06_07_ARS_OD_Width_Obj_07
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_06_07_ARS_OD_Width_Obj_07
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_06_07_ARS_OD_RCS_Obj_07
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_06_07_ARS_OD_RCS_Obj_07
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_06_07_ARS_OD_RCS_Obj_07
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_06_07_ARS_OD_Orientation_Obj_07
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_06_07_ARS_OD_Orientation_Obj_07
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_06_07_ARS_OD_Orientation_Obj_07
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_06_07_ARS_OD_YawRateAbs_Obj_07
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_06_07_ARS_OD_YawRateAbs_Obj_07
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_06_07_ARS_OD_YawRateAbs_Obj_07
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_06_07_ARS_OD_YawRateAbsStd_Obj_07
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_06_07_ARS_OD_YawRateAbsStd_Obj_07
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_06_07_ARS_OD_YawRateAbsStd_Obj_07
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_06_07_ARS_OD_RefPoint_Obj_07
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_06_07_ARS_OD_RefPoint_Obj_07
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_06_07_ARS_OD_RefPoint_Obj_07
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_06_07_ARS_OD_LifeCycle_Obj_07
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_06_07_ARS_OD_LifeCycle_Obj_07
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_06_07_ARS_OD_LifeCycle_Obj_07
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_06_07_ARS_OD_OrientationStd_Obj_06
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_06_07_ARS_OD_OrientationStd_Obj_06
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_06_07_ARS_OD_OrientationStd_Obj_06
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_06_07_ARS_OD_OrientationStd_Obj_07
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_06_07_ARS_OD_OrientationStd_Obj_07
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_06_07_ARS_OD_OrientationStd_Obj_07
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_06_07_ARS_OD_ObstacleProb_Obj_06
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_06_07_ARS_OD_ObstacleProb_Obj_06
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_06_07_ARS_OD_ObstacleProb_Obj_06
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_06_07_ARS_OD_MicroDopplerFlag_06
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_06_07_ARS_OD_MicroDopplerFlag_06
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_06_07_ARS_OD_MicroDopplerFlag_06
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_06_07_ARS_OD_ObstacleProb_Obj_07
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_06_07_ARS_OD_ObstacleProb_Obj_07
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_06_07_ARS_OD_ObstacleProb_Obj_07
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_06_07_ARS_OD_VabsY_Obj_06
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_06_07_ARS_OD_VabsY_Obj_06
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_06_07_ARS_OD_VabsY_Obj_06
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_06_07_ARS_OD_MicroDopplerFlag_07
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_06_07_ARS_OD_MicroDopplerFlag_07
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_06_07_ARS_OD_MicroDopplerFlag_07
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_06_07_ARS_OD_ID_06
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_06_07_ARS_OD_ID_06
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_06_07_ARS_OD_ID_06
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_06_07_ARS_OD_ID_07
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_06_07_ARS_OD_ID_07
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_06_07_ARS_OD_ID_07
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_06_07_ARS_OD_MsgCounter_Obj_06_07
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_06_07_ARS_OD_MsgCounter_Obj_06_07
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_06_07_ARS_OD_MsgCounter_Obj_06_07
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_06_07_ARS_OD_CRC16_Checksum_Obj_06_07
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_06_07_ARS_OD_CRC16_Checksum_Obj_06_07
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_06_07_ARS_OD_CRC16_Checksum_Obj_06_07
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_06_07_ARS_OD_AabsY_Obj_06
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_06_07_ARS_OD_AabsY_Obj_06
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_06_07_ARS_OD_AabsY_Obj_06
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_06_07_ARS_OD_DistXStd_Obj_06
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_06_07_ARS_OD_DistXStd_Obj_06
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_06_07_ARS_OD_DistXStd_Obj_06
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_06_07_ARS_OD_DistYStd_Obj_06
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_06_07_ARS_OD_DistYStd_Obj_06
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_06_07_ARS_OD_DistYStd_Obj_06
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_06_07_ARS_OD_VabsXStd_Obj_06
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_06_07_ARS_OD_VabsXStd_Obj_06
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_06_07_ARS_OD_VabsXStd_Obj_06
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_06_07_ARS_OD_VabsYStd_Obj_06
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_06_07_ARS_OD_VabsYStd_Obj_06
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_06_07_ARS_OD_VabsYStd_Obj_06
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_06_07_ARS_OD_AabsXStd_Obj_06
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_06_07_ARS_OD_AabsXStd_Obj_06
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_06_07_ARS_OD_AabsXStd_Obj_06
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_08_09_DistHeight_Obj_09
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_08_09_DistHeight_Obj_09
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_08_09_DistHeight_Obj_09
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_08_09_DistHeight_Obj_08
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_08_09_DistHeight_Obj_08
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_08_09_DistHeight_Obj_08
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_08_09_ARS_OD_DistX_Obj_08
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_08_09_ARS_OD_DistX_Obj_08
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_08_09_ARS_OD_DistX_Obj_08
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_08_09_ARS_OD_Classification_Obj_08
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_08_09_ARS_OD_Classification_Obj_08
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_08_09_ARS_OD_Classification_Obj_08
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_08_09_ARS_OD_AabsYStd_Obj_08
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_08_09_ARS_OD_AabsYStd_Obj_08
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_08_09_ARS_OD_AabsYStd_Obj_08
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_08_09_ARS_OD_ClassConf_Obj_08
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_08_09_ARS_OD_ClassConf_Obj_08
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_08_09_ARS_OD_ClassConf_Obj_08
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_08_09_ARS_OD_ProbOfExist_Obj_08
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_08_09_ARS_OD_ProbOfExist_Obj_08
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_08_09_ARS_OD_ProbOfExist_Obj_08
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_08_09_ARS_OD_DynConf_Obj_08
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_08_09_ARS_OD_DynConf_Obj_08
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_08_09_ARS_OD_DynConf_Obj_08
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_08_09_ARS_OD_VabsX_Obj_08
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_08_09_ARS_OD_VabsX_Obj_08
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_08_09_ARS_OD_VabsX_Obj_08
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_08_09_ARS_OD_DynProp_Obj_08
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_08_09_ARS_OD_DynProp_Obj_08
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_08_09_ARS_OD_DynProp_Obj_08
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_08_09_ARS_OD_MirrorProb_Obj_08
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_08_09_ARS_OD_MirrorProb_Obj_08
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_08_09_ARS_OD_MirrorProb_Obj_08
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_08_09_ARS_OD_Length_Obj_08
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_08_09_ARS_OD_Length_Obj_08
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_08_09_ARS_OD_Length_Obj_08
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_08_09_ARS_OD_MaintenanceState_Obj_08
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_08_09_ARS_OD_MaintenanceState_Obj_08
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_08_09_ARS_OD_MaintenanceState_Obj_08
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_08_09_ARS_OD_Width_Obj_08
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_08_09_ARS_OD_Width_Obj_08
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_08_09_ARS_OD_Width_Obj_08
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_08_09_ARS_OD_RCS_Obj_08
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_08_09_ARS_OD_RCS_Obj_08
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_08_09_ARS_OD_RCS_Obj_08
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_08_09_ARS_OD_Orientation_Obj_08
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_08_09_ARS_OD_Orientation_Obj_08
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_08_09_ARS_OD_Orientation_Obj_08
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_08_09_ARS_OD_YawRateAbs_Obj_08
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_08_09_ARS_OD_YawRateAbs_Obj_08
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_08_09_ARS_OD_YawRateAbs_Obj_08
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_08_09_ARS_OD_YawRateAbsStd_Obj_08
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_08_09_ARS_OD_YawRateAbsStd_Obj_08
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_08_09_ARS_OD_YawRateAbsStd_Obj_08
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_08_09_ARS_OD_RefPoint_Obj_08
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_08_09_ARS_OD_RefPoint_Obj_08
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_08_09_ARS_OD_RefPoint_Obj_08
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_08_09_ARS_OD_LifeCycle_Obj_08
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_08_09_ARS_OD_LifeCycle_Obj_08
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_08_09_ARS_OD_LifeCycle_Obj_08
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_08_09_ARS_OD_DistX_Obj_09
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_08_09_ARS_OD_DistX_Obj_09
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_08_09_ARS_OD_DistX_Obj_09
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_08_09_ARS_OD_VabsX_Obj_09
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_08_09_ARS_OD_VabsX_Obj_09
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_08_09_ARS_OD_VabsX_Obj_09
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_08_09_ARS_OD_AabsX_Obj_09
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_08_09_ARS_OD_AabsX_Obj_09
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_08_09_ARS_OD_AabsX_Obj_09
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_08_09_ARS_OD_AabsX_Obj_08
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_08_09_ARS_OD_AabsX_Obj_08
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_08_09_ARS_OD_AabsX_Obj_08
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_08_09_ARS_OD_DistY_Obj_09
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_08_09_ARS_OD_DistY_Obj_09
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_08_09_ARS_OD_DistY_Obj_09
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_08_09_ARS_OD_VabsY_Obj_09
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_08_09_ARS_OD_VabsY_Obj_09
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_08_09_ARS_OD_VabsY_Obj_09
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_08_09_ARS_OD_AabsY_Obj_09
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_08_09_ARS_OD_AabsY_Obj_09
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_08_09_ARS_OD_AabsY_Obj_09
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_08_09_ARS_OD_DistXStd_Obj_09
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_08_09_ARS_OD_DistXStd_Obj_09
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_08_09_ARS_OD_DistXStd_Obj_09
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_08_09_ARS_OD_DistYStd_Obj_09
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_08_09_ARS_OD_DistYStd_Obj_09
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_08_09_ARS_OD_DistYStd_Obj_09
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_08_09_ARS_OD_VabsXStd_Obj_09
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_08_09_ARS_OD_VabsXStd_Obj_09
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_08_09_ARS_OD_VabsXStd_Obj_09
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_08_09_ARS_OD_VabsYStd_Obj_09
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_08_09_ARS_OD_VabsYStd_Obj_09
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_08_09_ARS_OD_VabsYStd_Obj_09
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_08_09_ARS_OD_AabsXStd_Obj_09
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_08_09_ARS_OD_AabsXStd_Obj_09
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_08_09_ARS_OD_AabsXStd_Obj_09
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_08_09_ARS_OD_Classification_Obj_09
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_08_09_ARS_OD_Classification_Obj_09
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_08_09_ARS_OD_Classification_Obj_09
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_08_09_ARS_OD_AabsYStd_Obj_09
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_08_09_ARS_OD_AabsYStd_Obj_09
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_08_09_ARS_OD_AabsYStd_Obj_09
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_08_09_ARS_OD_ClassConf_Obj_09
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_08_09_ARS_OD_ClassConf_Obj_09
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_08_09_ARS_OD_ClassConf_Obj_09
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_08_09_ARS_OD_DistY_Obj_08
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_08_09_ARS_OD_DistY_Obj_08
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_08_09_ARS_OD_DistY_Obj_08
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_08_09_ARS_OD_ProbOfExist_Obj_09
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_08_09_ARS_OD_ProbOfExist_Obj_09
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_08_09_ARS_OD_ProbOfExist_Obj_09
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_08_09_ARS_OD_DynConf_Obj_09
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_08_09_ARS_OD_DynConf_Obj_09
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_08_09_ARS_OD_DynConf_Obj_09
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_08_09_ARS_OD_DynProp_Obj_09
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_08_09_ARS_OD_DynProp_Obj_09
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_08_09_ARS_OD_DynProp_Obj_09
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_08_09_ARS_OD_MirrorProb_Obj_09
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_08_09_ARS_OD_MirrorProb_Obj_09
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_08_09_ARS_OD_MirrorProb_Obj_09
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_08_09_ARS_OD_Length_Obj_09
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_08_09_ARS_OD_Length_Obj_09
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_08_09_ARS_OD_Length_Obj_09
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_08_09_ARS_OD_MaintenanceState_Obj_09
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_08_09_ARS_OD_MaintenanceState_Obj_09
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_08_09_ARS_OD_MaintenanceState_Obj_09
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_08_09_ARS_OD_Width_Obj_09
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_08_09_ARS_OD_Width_Obj_09
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_08_09_ARS_OD_Width_Obj_09
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_08_09_ARS_OD_RCS_Obj_09
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_08_09_ARS_OD_RCS_Obj_09
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_08_09_ARS_OD_RCS_Obj_09
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_08_09_ARS_OD_Orientation_Obj_09
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_08_09_ARS_OD_Orientation_Obj_09
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_08_09_ARS_OD_Orientation_Obj_09
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_08_09_ARS_OD_YawRateAbs_Obj_09
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_08_09_ARS_OD_YawRateAbs_Obj_09
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_08_09_ARS_OD_YawRateAbs_Obj_09
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_08_09_ARS_OD_YawRateAbsStd_Obj_09
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_08_09_ARS_OD_YawRateAbsStd_Obj_09
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_08_09_ARS_OD_YawRateAbsStd_Obj_09
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_08_09_ARS_OD_RefPoint_Obj_09
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_08_09_ARS_OD_RefPoint_Obj_09
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_08_09_ARS_OD_RefPoint_Obj_09
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_08_09_ARS_OD_LifeCycle_Obj_09
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_08_09_ARS_OD_LifeCycle_Obj_09
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_08_09_ARS_OD_LifeCycle_Obj_09
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_08_09_ARS_OD_OrientationStd_Obj_08
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_08_09_ARS_OD_OrientationStd_Obj_08
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_08_09_ARS_OD_OrientationStd_Obj_08
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_08_09_ARS_OD_OrientationStd_Obj_09
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_08_09_ARS_OD_OrientationStd_Obj_09
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_08_09_ARS_OD_OrientationStd_Obj_09
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_08_09_ARS_OD_ObstacleProb_Obj_08
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_08_09_ARS_OD_ObstacleProb_Obj_08
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_08_09_ARS_OD_ObstacleProb_Obj_08
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_08_09_ARS_OD_MicroDopplerFlag_08
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_08_09_ARS_OD_MicroDopplerFlag_08
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_08_09_ARS_OD_MicroDopplerFlag_08
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_08_09_ARS_OD_ObstacleProb_Obj_09
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_08_09_ARS_OD_ObstacleProb_Obj_09
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_08_09_ARS_OD_ObstacleProb_Obj_09
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_08_09_ARS_OD_VabsY_Obj_08
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_08_09_ARS_OD_VabsY_Obj_08
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_08_09_ARS_OD_VabsY_Obj_08
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_08_09_ARS_OD_MicroDopplerFlag_09
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_08_09_ARS_OD_MicroDopplerFlag_09
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_08_09_ARS_OD_MicroDopplerFlag_09
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_08_09_ARS_OD_ID_08
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_08_09_ARS_OD_ID_08
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_08_09_ARS_OD_ID_08
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_08_09_ARS_OD_ID_09
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_08_09_ARS_OD_ID_09
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_08_09_ARS_OD_ID_09
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_08_09_ARS_OD_MsgCounter_Obj_08_09
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_08_09_ARS_OD_MsgCounter_Obj_08_09
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_08_09_ARS_OD_MsgCounter_Obj_08_09
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_08_09_ARS_OD_CRC16_Checksum_Obj_08_09
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_08_09_ARS_OD_CRC16_Checksum_Obj_08_09
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_08_09_ARS_OD_CRC16_Checksum_Obj_08_09
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_08_09_ARS_OD_AabsY_Obj_08
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_08_09_ARS_OD_AabsY_Obj_08
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_08_09_ARS_OD_AabsY_Obj_08
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_08_09_ARS_OD_DistXStd_Obj_08
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_08_09_ARS_OD_DistXStd_Obj_08
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_08_09_ARS_OD_DistXStd_Obj_08
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_08_09_ARS_OD_DistYStd_Obj_08
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_08_09_ARS_OD_DistYStd_Obj_08
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_08_09_ARS_OD_DistYStd_Obj_08
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_08_09_ARS_OD_VabsXStd_Obj_08
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_08_09_ARS_OD_VabsXStd_Obj_08
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_08_09_ARS_OD_VabsXStd_Obj_08
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_08_09_ARS_OD_VabsYStd_Obj_08
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_08_09_ARS_OD_VabsYStd_Obj_08
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_08_09_ARS_OD_VabsYStd_Obj_08
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_08_09_ARS_OD_AabsXStd_Obj_08
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_08_09_ARS_OD_AabsXStd_Obj_08
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_08_09_ARS_OD_AabsXStd_Obj_08
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_10_11_DistHeight_Obj_11
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_10_11_DistHeight_Obj_11
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_10_11_DistHeight_Obj_11
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_10_11_DistHeight_Obj_10
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_10_11_DistHeight_Obj_10
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_10_11_DistHeight_Obj_10
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_10_11_ARS_OD_DistX_Obj_10
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_10_11_ARS_OD_DistX_Obj_10
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_10_11_ARS_OD_DistX_Obj_10
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_10_11_ARS_OD_Classification_Obj_10
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_10_11_ARS_OD_Classification_Obj_10
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_10_11_ARS_OD_Classification_Obj_10
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_10_11_ARS_OD_AabsYStd_Obj_10
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_10_11_ARS_OD_AabsYStd_Obj_10
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_10_11_ARS_OD_AabsYStd_Obj_10
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_10_11_ARS_OD_ClassConf_Obj_10
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_10_11_ARS_OD_ClassConf_Obj_10
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_10_11_ARS_OD_ClassConf_Obj_10
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_10_11_ARS_OD_ProbOfExist_Obj_10
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_10_11_ARS_OD_ProbOfExist_Obj_10
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_10_11_ARS_OD_ProbOfExist_Obj_10
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_10_11_ARS_OD_DynConf_Obj_10
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_10_11_ARS_OD_DynConf_Obj_10
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_10_11_ARS_OD_DynConf_Obj_10
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_10_11_ARS_OD_VabsX_Obj_10
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_10_11_ARS_OD_VabsX_Obj_10
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_10_11_ARS_OD_VabsX_Obj_10
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_10_11_ARS_OD_DynProp_Obj_10
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_10_11_ARS_OD_DynProp_Obj_10
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_10_11_ARS_OD_DynProp_Obj_10
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_10_11_ARS_OD_MirrorProb_Obj_10
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_10_11_ARS_OD_MirrorProb_Obj_10
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_10_11_ARS_OD_MirrorProb_Obj_10
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_10_11_ARS_OD_Length_Obj_10
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_10_11_ARS_OD_Length_Obj_10
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_10_11_ARS_OD_Length_Obj_10
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_10_11_ARS_OD_MaintenanceState_Obj_10
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_10_11_ARS_OD_MaintenanceState_Obj_10
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_10_11_ARS_OD_MaintenanceState_Obj_10
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_10_11_ARS_OD_Width_Obj_10
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_10_11_ARS_OD_Width_Obj_10
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_10_11_ARS_OD_Width_Obj_10
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_10_11_ARS_OD_RCS_Obj_10
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_10_11_ARS_OD_RCS_Obj_10
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_10_11_ARS_OD_RCS_Obj_10
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_10_11_ARS_OD_Orientation_Obj_10
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_10_11_ARS_OD_Orientation_Obj_10
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_10_11_ARS_OD_Orientation_Obj_10
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_10_11_ARS_OD_YawRateAbs_Obj_10
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_10_11_ARS_OD_YawRateAbs_Obj_10
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_10_11_ARS_OD_YawRateAbs_Obj_10
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_10_11_ARS_OD_YawRateAbsStd_Obj_10
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_10_11_ARS_OD_YawRateAbsStd_Obj_10
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_10_11_ARS_OD_YawRateAbsStd_Obj_10
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_10_11_ARS_OD_RefPoint_Obj_10
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_10_11_ARS_OD_RefPoint_Obj_10
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_10_11_ARS_OD_RefPoint_Obj_10
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_10_11_ARS_OD_LifeCycle_Obj_10
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_10_11_ARS_OD_LifeCycle_Obj_10
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_10_11_ARS_OD_LifeCycle_Obj_10
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_10_11_ARS_OD_DistX_Obj_11
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_10_11_ARS_OD_DistX_Obj_11
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_10_11_ARS_OD_DistX_Obj_11
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_10_11_ARS_OD_VabsX_Obj_11
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_10_11_ARS_OD_VabsX_Obj_11
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_10_11_ARS_OD_VabsX_Obj_11
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_10_11_ARS_OD_AabsX_Obj_11
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_10_11_ARS_OD_AabsX_Obj_11
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_10_11_ARS_OD_AabsX_Obj_11
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_10_11_ARS_OD_AabsX_Obj_10
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_10_11_ARS_OD_AabsX_Obj_10
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_10_11_ARS_OD_AabsX_Obj_10
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_10_11_ARS_OD_DistY_Obj_11
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_10_11_ARS_OD_DistY_Obj_11
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_10_11_ARS_OD_DistY_Obj_11
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_10_11_ARS_OD_VabsY_Obj_11
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_10_11_ARS_OD_VabsY_Obj_11
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_10_11_ARS_OD_VabsY_Obj_11
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_10_11_ARS_OD_AabsY_Obj_11
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_10_11_ARS_OD_AabsY_Obj_11
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_10_11_ARS_OD_AabsY_Obj_11
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_10_11_ARS_OD_DistXStd_Obj_11
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_10_11_ARS_OD_DistXStd_Obj_11
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_10_11_ARS_OD_DistXStd_Obj_11
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_10_11_ARS_OD_DistYStd_Obj_11
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_10_11_ARS_OD_DistYStd_Obj_11
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_10_11_ARS_OD_DistYStd_Obj_11
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_10_11_ARS_OD_VabsXStd_Obj_11
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_10_11_ARS_OD_VabsXStd_Obj_11
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_10_11_ARS_OD_VabsXStd_Obj_11
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_10_11_ARS_OD_VabsYStd_Obj_11
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_10_11_ARS_OD_VabsYStd_Obj_11
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_10_11_ARS_OD_VabsYStd_Obj_11
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_10_11_ARS_OD_AabsXStd_Obj_11
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_10_11_ARS_OD_AabsXStd_Obj_11
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_10_11_ARS_OD_AabsXStd_Obj_11
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_10_11_ARS_OD_Classification_Obj_11
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_10_11_ARS_OD_Classification_Obj_11
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_10_11_ARS_OD_Classification_Obj_11
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_10_11_ARS_OD_AabsYStd_Obj_11
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_10_11_ARS_OD_AabsYStd_Obj_11
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_10_11_ARS_OD_AabsYStd_Obj_11
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_10_11_ARS_OD_ClassConf_Obj_11
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_10_11_ARS_OD_ClassConf_Obj_11
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_10_11_ARS_OD_ClassConf_Obj_11
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_10_11_ARS_OD_DistY_Obj_10
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_10_11_ARS_OD_DistY_Obj_10
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_10_11_ARS_OD_DistY_Obj_10
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_10_11_ARS_OD_ProbOfExist_Obj_11
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_10_11_ARS_OD_ProbOfExist_Obj_11
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_10_11_ARS_OD_ProbOfExist_Obj_11
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_10_11_ARS_OD_DynConf_Obj_11
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_10_11_ARS_OD_DynConf_Obj_11
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_10_11_ARS_OD_DynConf_Obj_11
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_10_11_ARS_OD_DynProp_Obj_11
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_10_11_ARS_OD_DynProp_Obj_11
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_10_11_ARS_OD_DynProp_Obj_11
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_10_11_ARS_OD_MirrorProb_Obj_11
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_10_11_ARS_OD_MirrorProb_Obj_11
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_10_11_ARS_OD_MirrorProb_Obj_11
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_10_11_ARS_OD_Length_Obj_11
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_10_11_ARS_OD_Length_Obj_11
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_10_11_ARS_OD_Length_Obj_11
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_10_11_ARS_OD_MaintenanceState_Obj_11
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_10_11_ARS_OD_MaintenanceState_Obj_11
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_10_11_ARS_OD_MaintenanceState_Obj_11
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_10_11_ARS_OD_Width_Obj_11
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_10_11_ARS_OD_Width_Obj_11
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_10_11_ARS_OD_Width_Obj_11
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_10_11_ARS_OD_RCS_Obj_11
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_10_11_ARS_OD_RCS_Obj_11
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_10_11_ARS_OD_RCS_Obj_11
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_10_11_ARS_OD_Orientation_Obj_11
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_10_11_ARS_OD_Orientation_Obj_11
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_10_11_ARS_OD_Orientation_Obj_11
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_10_11_ARS_OD_YawRateAbs_Obj_11
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_10_11_ARS_OD_YawRateAbs_Obj_11
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_10_11_ARS_OD_YawRateAbs_Obj_11
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_10_11_ARS_OD_YawRateAbsStd_Obj_11
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_10_11_ARS_OD_YawRateAbsStd_Obj_11
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_10_11_ARS_OD_YawRateAbsStd_Obj_11
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_10_11_ARS_OD_RefPoint_Obj_11
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_10_11_ARS_OD_RefPoint_Obj_11
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_10_11_ARS_OD_RefPoint_Obj_11
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_10_11_ARS_OD_LifeCycle_Obj_11
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_10_11_ARS_OD_LifeCycle_Obj_11
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_10_11_ARS_OD_LifeCycle_Obj_11
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_10_11_ARS_OD_OrientationStd_Obj_10
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_10_11_ARS_OD_OrientationStd_Obj_10
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_10_11_ARS_OD_OrientationStd_Obj_10
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_10_11_ARS_OD_OrientationStd_Obj_11
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_10_11_ARS_OD_OrientationStd_Obj_11
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_10_11_ARS_OD_OrientationStd_Obj_11
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_10_11_ARS_OD_ObstacleProb_Obj_10
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_10_11_ARS_OD_ObstacleProb_Obj_10
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_10_11_ARS_OD_ObstacleProb_Obj_10
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_10_11_ARS_OD_MicroDopplerFlag_10
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_10_11_ARS_OD_MicroDopplerFlag_10
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_10_11_ARS_OD_MicroDopplerFlag_10
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_10_11_ARS_OD_ObstacleProb_Obj_11
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_10_11_ARS_OD_ObstacleProb_Obj_11
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_10_11_ARS_OD_ObstacleProb_Obj_11
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_10_11_ARS_OD_VabsY_Obj_10
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_10_11_ARS_OD_VabsY_Obj_10
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_10_11_ARS_OD_VabsY_Obj_10
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_10_11_ARS_OD_MicroDopplerFlag_11
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_10_11_ARS_OD_MicroDopplerFlag_11
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_10_11_ARS_OD_MicroDopplerFlag_11
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_10_11_ARS_OD_ID_10
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_10_11_ARS_OD_ID_10
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_10_11_ARS_OD_ID_10
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_10_11_ARS_OD_ID_11
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_10_11_ARS_OD_ID_11
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_10_11_ARS_OD_ID_11
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_10_11_ARS_OD_MsgCounter_Obj_10_11
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_10_11_ARS_OD_MsgCounter_Obj_10_11
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_10_11_ARS_OD_MsgCounter_Obj_10_11
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_10_11_ARS_OD_CRC16_Checksum_Obj_10_11
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_10_11_ARS_OD_CRC16_Checksum_Obj_10_11
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_10_11_ARS_OD_CRC16_Checksum_Obj_10_11
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_10_11_ARS_OD_AabsY_Obj_10
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_10_11_ARS_OD_AabsY_Obj_10
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_10_11_ARS_OD_AabsY_Obj_10
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_10_11_ARS_OD_DistXStd_Obj_10
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_10_11_ARS_OD_DistXStd_Obj_10
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_10_11_ARS_OD_DistXStd_Obj_10
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_10_11_ARS_OD_DistYStd_Obj_10
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_10_11_ARS_OD_DistYStd_Obj_10
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_10_11_ARS_OD_DistYStd_Obj_10
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_10_11_ARS_OD_VabsXStd_Obj_10
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_10_11_ARS_OD_VabsXStd_Obj_10
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_10_11_ARS_OD_VabsXStd_Obj_10
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_10_11_ARS_OD_VabsYStd_Obj_10
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_10_11_ARS_OD_VabsYStd_Obj_10
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_10_11_ARS_OD_VabsYStd_Obj_10
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_10_11_ARS_OD_AabsXStd_Obj_10
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_10_11_ARS_OD_AabsXStd_Obj_10
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_10_11_ARS_OD_AabsXStd_Obj_10
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_12_13_DistHeight_Obj_13
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_12_13_DistHeight_Obj_13
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_12_13_DistHeight_Obj_13
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_12_13_DistHeight_Obj_12
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_12_13_DistHeight_Obj_12
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_12_13_DistHeight_Obj_12
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_12_13_ARS_OD_DistX_Obj_12
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_12_13_ARS_OD_DistX_Obj_12
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_12_13_ARS_OD_DistX_Obj_12
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_12_13_ARS_OD_Classification_Obj_12
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_12_13_ARS_OD_Classification_Obj_12
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_12_13_ARS_OD_Classification_Obj_12
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_12_13_ARS_OD_AabsYStd_Obj_12
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_12_13_ARS_OD_AabsYStd_Obj_12
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_12_13_ARS_OD_AabsYStd_Obj_12
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_12_13_ARS_OD_ClassConf_Obj_12
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_12_13_ARS_OD_ClassConf_Obj_12
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_12_13_ARS_OD_ClassConf_Obj_12
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_12_13_ARS_OD_ProbOfExist_Obj_12
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_12_13_ARS_OD_ProbOfExist_Obj_12
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_12_13_ARS_OD_ProbOfExist_Obj_12
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_12_13_ARS_OD_DynConf_Obj_12
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_12_13_ARS_OD_DynConf_Obj_12
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_12_13_ARS_OD_DynConf_Obj_12
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_12_13_ARS_OD_VabsX_Obj_12
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_12_13_ARS_OD_VabsX_Obj_12
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_12_13_ARS_OD_VabsX_Obj_12
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_12_13_ARS_OD_DynProp_Obj_12
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_12_13_ARS_OD_DynProp_Obj_12
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_12_13_ARS_OD_DynProp_Obj_12
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_12_13_ARS_OD_MirrorProb_Obj_12
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_12_13_ARS_OD_MirrorProb_Obj_12
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_12_13_ARS_OD_MirrorProb_Obj_12
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_12_13_ARS_OD_Length_Obj_12
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_12_13_ARS_OD_Length_Obj_12
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_12_13_ARS_OD_Length_Obj_12
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_12_13_ARS_OD_MaintenanceState_Obj_12
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_12_13_ARS_OD_MaintenanceState_Obj_12
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_12_13_ARS_OD_MaintenanceState_Obj_12
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_12_13_ARS_OD_Width_Obj_12
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_12_13_ARS_OD_Width_Obj_12
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_12_13_ARS_OD_Width_Obj_12
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_12_13_ARS_OD_RCS_Obj_12
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_12_13_ARS_OD_RCS_Obj_12
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_12_13_ARS_OD_RCS_Obj_12
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_12_13_ARS_OD_Orientation_Obj_12
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_12_13_ARS_OD_Orientation_Obj_12
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_12_13_ARS_OD_Orientation_Obj_12
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_12_13_ARS_OD_YawRateAbs_Obj_12
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_12_13_ARS_OD_YawRateAbs_Obj_12
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_12_13_ARS_OD_YawRateAbs_Obj_12
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_12_13_ARS_OD_YawRateAbsStd_Obj_12
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_12_13_ARS_OD_YawRateAbsStd_Obj_12
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_12_13_ARS_OD_YawRateAbsStd_Obj_12
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_12_13_ARS_OD_RefPoint_Obj_12
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_12_13_ARS_OD_RefPoint_Obj_12
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_12_13_ARS_OD_RefPoint_Obj_12
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_12_13_ARS_OD_LifeCycle_Obj_12
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_12_13_ARS_OD_LifeCycle_Obj_12
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_12_13_ARS_OD_LifeCycle_Obj_12
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_12_13_ARS_OD_DistX_Obj_13
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_12_13_ARS_OD_DistX_Obj_13
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_12_13_ARS_OD_DistX_Obj_13
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_12_13_ARS_OD_VabsX_Obj_13
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_12_13_ARS_OD_VabsX_Obj_13
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_12_13_ARS_OD_VabsX_Obj_13
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_12_13_ARS_OD_AabsX_Obj_13
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_12_13_ARS_OD_AabsX_Obj_13
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_12_13_ARS_OD_AabsX_Obj_13
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_12_13_ARS_OD_AabsX_Obj_12
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_12_13_ARS_OD_AabsX_Obj_12
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_12_13_ARS_OD_AabsX_Obj_12
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_12_13_ARS_OD_DistY_Obj_13
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_12_13_ARS_OD_DistY_Obj_13
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_12_13_ARS_OD_DistY_Obj_13
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_12_13_ARS_OD_VabsY_Obj_13
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_12_13_ARS_OD_VabsY_Obj_13
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_12_13_ARS_OD_VabsY_Obj_13
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_12_13_ARS_OD_AabsY_Obj_13
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_12_13_ARS_OD_AabsY_Obj_13
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_12_13_ARS_OD_AabsY_Obj_13
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_12_13_ARS_OD_DistXStd_Obj_13
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_12_13_ARS_OD_DistXStd_Obj_13
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_12_13_ARS_OD_DistXStd_Obj_13
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_12_13_ARS_OD_DistYStd_Obj_13
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_12_13_ARS_OD_DistYStd_Obj_13
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_12_13_ARS_OD_DistYStd_Obj_13
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_12_13_ARS_OD_VabsXStd_Obj_13
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_12_13_ARS_OD_VabsXStd_Obj_13
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_12_13_ARS_OD_VabsXStd_Obj_13
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_12_13_ARS_OD_VabsYStd_Obj_13
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_12_13_ARS_OD_VabsYStd_Obj_13
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_12_13_ARS_OD_VabsYStd_Obj_13
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_12_13_ARS_OD_AabsXStd_Obj_13
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_12_13_ARS_OD_AabsXStd_Obj_13
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_12_13_ARS_OD_AabsXStd_Obj_13
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_12_13_ARS_OD_Classification_Obj_13
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_12_13_ARS_OD_Classification_Obj_13
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_12_13_ARS_OD_Classification_Obj_13
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_12_13_ARS_OD_AabsYStd_Obj_13
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_12_13_ARS_OD_AabsYStd_Obj_13
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_12_13_ARS_OD_AabsYStd_Obj_13
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_12_13_ARS_OD_ClassConf_Obj_13
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_12_13_ARS_OD_ClassConf_Obj_13
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_12_13_ARS_OD_ClassConf_Obj_13
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_12_13_ARS_OD_DistY_Obj_12
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_12_13_ARS_OD_DistY_Obj_12
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_12_13_ARS_OD_DistY_Obj_12
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_12_13_ARS_OD_ProbOfExist_Obj_13
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_12_13_ARS_OD_ProbOfExist_Obj_13
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_12_13_ARS_OD_ProbOfExist_Obj_13
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_12_13_ARS_OD_DynConf_Obj_13
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_12_13_ARS_OD_DynConf_Obj_13
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_12_13_ARS_OD_DynConf_Obj_13
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_12_13_ARS_OD_DynProp_Obj_13
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_12_13_ARS_OD_DynProp_Obj_13
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_12_13_ARS_OD_DynProp_Obj_13
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_12_13_ARS_OD_MirrorProb_Obj_13
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_12_13_ARS_OD_MirrorProb_Obj_13
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_12_13_ARS_OD_MirrorProb_Obj_13
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_12_13_ARS_OD_Length_Obj_13
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_12_13_ARS_OD_Length_Obj_13
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_12_13_ARS_OD_Length_Obj_13
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_12_13_ARS_OD_MaintenanceState_Obj_13
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_12_13_ARS_OD_MaintenanceState_Obj_13
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_12_13_ARS_OD_MaintenanceState_Obj_13
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_12_13_ARS_OD_Width_Obj_13
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_12_13_ARS_OD_Width_Obj_13
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_12_13_ARS_OD_Width_Obj_13
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_12_13_ARS_OD_RCS_Obj_13
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_12_13_ARS_OD_RCS_Obj_13
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_12_13_ARS_OD_RCS_Obj_13
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_12_13_ARS_OD_Orientation_Obj_13
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_12_13_ARS_OD_Orientation_Obj_13
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_12_13_ARS_OD_Orientation_Obj_13
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_12_13_ARS_OD_YawRateAbs_Obj_13
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_12_13_ARS_OD_YawRateAbs_Obj_13
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_12_13_ARS_OD_YawRateAbs_Obj_13
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_12_13_ARS_OD_YawRateAbsStd_Obj_13
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_12_13_ARS_OD_YawRateAbsStd_Obj_13
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_12_13_ARS_OD_YawRateAbsStd_Obj_13
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_12_13_ARS_OD_RefPoint_Obj_13
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_12_13_ARS_OD_RefPoint_Obj_13
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_12_13_ARS_OD_RefPoint_Obj_13
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_12_13_ARS_OD_LifeCycle_Obj_13
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_12_13_ARS_OD_LifeCycle_Obj_13
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_12_13_ARS_OD_LifeCycle_Obj_13
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_12_13_ARS_OD_OrientationStd_Obj_12
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_12_13_ARS_OD_OrientationStd_Obj_12
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_12_13_ARS_OD_OrientationStd_Obj_12
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_12_13_ARS_OD_OrientationStd_Obj_13
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_12_13_ARS_OD_OrientationStd_Obj_13
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_12_13_ARS_OD_OrientationStd_Obj_13
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_12_13_ARS_OD_ObstacleProb_Obj_12
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_12_13_ARS_OD_ObstacleProb_Obj_12
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_12_13_ARS_OD_ObstacleProb_Obj_12
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_12_13_ARS_OD_MicroDopplerFlag_12
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_12_13_ARS_OD_MicroDopplerFlag_12
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_12_13_ARS_OD_MicroDopplerFlag_12
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_12_13_ARS_OD_ObstacleProb_Obj_13
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_12_13_ARS_OD_ObstacleProb_Obj_13
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_12_13_ARS_OD_ObstacleProb_Obj_13
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_12_13_ARS_OD_VabsY_Obj_12
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_12_13_ARS_OD_VabsY_Obj_12
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_12_13_ARS_OD_VabsY_Obj_12
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_12_13_ARS_OD_MicroDopplerFlag_13
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_12_13_ARS_OD_MicroDopplerFlag_13
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_12_13_ARS_OD_MicroDopplerFlag_13
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_12_13_ARS_OD_ID_12
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_12_13_ARS_OD_ID_12
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_12_13_ARS_OD_ID_12
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_12_13_ARS_OD_ID_13
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_12_13_ARS_OD_ID_13
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_12_13_ARS_OD_ID_13
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_12_13_ARS_OD_MsgCounter_Obj_12_13
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_12_13_ARS_OD_MsgCounter_Obj_12_13
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_12_13_ARS_OD_MsgCounter_Obj_12_13
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_12_13_ARS_OD_CRC16_Checksum_Obj_12_13
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_12_13_ARS_OD_CRC16_Checksum_Obj_12_13
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_12_13_ARS_OD_CRC16_Checksum_Obj_12_13
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_12_13_ARS_OD_AabsY_Obj_12
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_12_13_ARS_OD_AabsY_Obj_12
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_12_13_ARS_OD_AabsY_Obj_12
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_12_13_ARS_OD_DistXStd_Obj_12
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_12_13_ARS_OD_DistXStd_Obj_12
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_12_13_ARS_OD_DistXStd_Obj_12
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_12_13_ARS_OD_DistYStd_Obj_12
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_12_13_ARS_OD_DistYStd_Obj_12
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_12_13_ARS_OD_DistYStd_Obj_12
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_12_13_ARS_OD_VabsXStd_Obj_12
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_12_13_ARS_OD_VabsXStd_Obj_12
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_12_13_ARS_OD_VabsXStd_Obj_12
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_12_13_ARS_OD_VabsYStd_Obj_12
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_12_13_ARS_OD_VabsYStd_Obj_12
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_12_13_ARS_OD_VabsYStd_Obj_12
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_12_13_ARS_OD_AabsXStd_Obj_12
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_12_13_ARS_OD_AabsXStd_Obj_12
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_12_13_ARS_OD_AabsXStd_Obj_12
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_14_15_DistHeight_Obj_15
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_14_15_DistHeight_Obj_15
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_14_15_DistHeight_Obj_15
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_14_15_DistHeight_Obj_14
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_14_15_DistHeight_Obj_14
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_14_15_DistHeight_Obj_14
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_14_15_ARS_OD_DistX_Obj_14
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_14_15_ARS_OD_DistX_Obj_14
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_14_15_ARS_OD_DistX_Obj_14
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_14_15_ARS_OD_Classification_Obj_14
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_14_15_ARS_OD_Classification_Obj_14
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_14_15_ARS_OD_Classification_Obj_14
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_14_15_ARS_OD_AabsYStd_Obj_14
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_14_15_ARS_OD_AabsYStd_Obj_14
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_14_15_ARS_OD_AabsYStd_Obj_14
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_14_15_ARS_OD_ClassConf_Obj_14
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_14_15_ARS_OD_ClassConf_Obj_14
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_14_15_ARS_OD_ClassConf_Obj_14
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_14_15_ARS_OD_ProbOfExist_Obj_14
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_14_15_ARS_OD_ProbOfExist_Obj_14
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_14_15_ARS_OD_ProbOfExist_Obj_14
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_14_15_ARS_OD_DynConf_Obj_14
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_14_15_ARS_OD_DynConf_Obj_14
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_14_15_ARS_OD_DynConf_Obj_14
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_14_15_ARS_OD_VabsX_Obj_14
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_14_15_ARS_OD_VabsX_Obj_14
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_14_15_ARS_OD_VabsX_Obj_14
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_14_15_ARS_OD_DynProp_Obj_14
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_14_15_ARS_OD_DynProp_Obj_14
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_14_15_ARS_OD_DynProp_Obj_14
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_14_15_ARS_OD_MirrorProb_Obj_14
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_14_15_ARS_OD_MirrorProb_Obj_14
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_14_15_ARS_OD_MirrorProb_Obj_14
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_14_15_ARS_OD_Length_Obj_14
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_14_15_ARS_OD_Length_Obj_14
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_14_15_ARS_OD_Length_Obj_14
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_14_15_ARS_OD_MaintenanceState_Obj_14
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_14_15_ARS_OD_MaintenanceState_Obj_14
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_14_15_ARS_OD_MaintenanceState_Obj_14
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_14_15_ARS_OD_Width_Obj_14
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_14_15_ARS_OD_Width_Obj_14
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_14_15_ARS_OD_Width_Obj_14
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_14_15_ARS_OD_RCS_Obj_14
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_14_15_ARS_OD_RCS_Obj_14
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_14_15_ARS_OD_RCS_Obj_14
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_14_15_ARS_OD_Orientation_Obj_14
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_14_15_ARS_OD_Orientation_Obj_14
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_14_15_ARS_OD_Orientation_Obj_14
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_14_15_ARS_OD_YawRateAbs_Obj_14
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_14_15_ARS_OD_YawRateAbs_Obj_14
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_14_15_ARS_OD_YawRateAbs_Obj_14
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_14_15_ARS_OD_YawRateAbsStd_Obj_14
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_14_15_ARS_OD_YawRateAbsStd_Obj_14
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_14_15_ARS_OD_YawRateAbsStd_Obj_14
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_14_15_ARS_OD_RefPoint_Obj_14
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_14_15_ARS_OD_RefPoint_Obj_14
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_14_15_ARS_OD_RefPoint_Obj_14
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_14_15_ARS_OD_LifeCycle_Obj_14
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_14_15_ARS_OD_LifeCycle_Obj_14
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_14_15_ARS_OD_LifeCycle_Obj_14
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_14_15_ARS_OD_DistX_Obj_15
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_14_15_ARS_OD_DistX_Obj_15
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_14_15_ARS_OD_DistX_Obj_15
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_14_15_ARS_OD_VabsX_Obj_15
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_14_15_ARS_OD_VabsX_Obj_15
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_14_15_ARS_OD_VabsX_Obj_15
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_14_15_ARS_OD_AabsX_Obj_15
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_14_15_ARS_OD_AabsX_Obj_15
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_14_15_ARS_OD_AabsX_Obj_15
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_14_15_ARS_OD_AabsX_Obj_14
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_14_15_ARS_OD_AabsX_Obj_14
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_14_15_ARS_OD_AabsX_Obj_14
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_14_15_ARS_OD_DistY_Obj_15
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_14_15_ARS_OD_DistY_Obj_15
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_14_15_ARS_OD_DistY_Obj_15
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_14_15_ARS_OD_VabsY_Obj_15
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_14_15_ARS_OD_VabsY_Obj_15
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_14_15_ARS_OD_VabsY_Obj_15
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_14_15_ARS_OD_AabsY_Obj_15
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_14_15_ARS_OD_AabsY_Obj_15
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_14_15_ARS_OD_AabsY_Obj_15
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_14_15_ARS_OD_DistXStd_Obj_15
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_14_15_ARS_OD_DistXStd_Obj_15
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_14_15_ARS_OD_DistXStd_Obj_15
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_14_15_ARS_OD_DistYStd_Obj_15
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_14_15_ARS_OD_DistYStd_Obj_15
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_14_15_ARS_OD_DistYStd_Obj_15
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_14_15_ARS_OD_VabsXStd_Obj_15
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_14_15_ARS_OD_VabsXStd_Obj_15
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_14_15_ARS_OD_VabsXStd_Obj_15
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_14_15_ARS_OD_VabsYStd_Obj_15
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_14_15_ARS_OD_VabsYStd_Obj_15
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_14_15_ARS_OD_VabsYStd_Obj_15
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_14_15_ARS_OD_AabsXStd_Obj_15
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_14_15_ARS_OD_AabsXStd_Obj_15
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_14_15_ARS_OD_AabsXStd_Obj_15
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_14_15_ARS_OD_Classification_Obj_15
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_14_15_ARS_OD_Classification_Obj_15
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_14_15_ARS_OD_Classification_Obj_15
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_14_15_ARS_OD_AabsYStd_Obj_15
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_14_15_ARS_OD_AabsYStd_Obj_15
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_14_15_ARS_OD_AabsYStd_Obj_15
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_14_15_ARS_OD_ClassConf_Obj_15
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_14_15_ARS_OD_ClassConf_Obj_15
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_14_15_ARS_OD_ClassConf_Obj_15
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_14_15_ARS_OD_DistY_Obj_14
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_14_15_ARS_OD_DistY_Obj_14
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_14_15_ARS_OD_DistY_Obj_14
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_14_15_ARS_OD_ProbOfExist_Obj_15
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_14_15_ARS_OD_ProbOfExist_Obj_15
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_14_15_ARS_OD_ProbOfExist_Obj_15
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_14_15_ARS_OD_DynConf_Obj_15
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_14_15_ARS_OD_DynConf_Obj_15
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_14_15_ARS_OD_DynConf_Obj_15
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_14_15_ARS_OD_DynProp_Obj_15
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_14_15_ARS_OD_DynProp_Obj_15
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_14_15_ARS_OD_DynProp_Obj_15
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_14_15_ARS_OD_MirrorProb_Obj_15
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_14_15_ARS_OD_MirrorProb_Obj_15
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_14_15_ARS_OD_MirrorProb_Obj_15
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_14_15_ARS_OD_Length_Obj_15
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_14_15_ARS_OD_Length_Obj_15
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_14_15_ARS_OD_Length_Obj_15
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_14_15_ARS_OD_MaintenanceState_Obj_15
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_14_15_ARS_OD_MaintenanceState_Obj_15
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_14_15_ARS_OD_MaintenanceState_Obj_15
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_14_15_ARS_OD_Width_Obj_15
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_14_15_ARS_OD_Width_Obj_15
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_14_15_ARS_OD_Width_Obj_15
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_14_15_ARS_OD_RCS_Obj_15
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_14_15_ARS_OD_RCS_Obj_15
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_14_15_ARS_OD_RCS_Obj_15
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_14_15_ARS_OD_Orientation_Obj_15
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_14_15_ARS_OD_Orientation_Obj_15
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_14_15_ARS_OD_Orientation_Obj_15
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_14_15_ARS_OD_YawRateAbs_Obj_15
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_14_15_ARS_OD_YawRateAbs_Obj_15
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_14_15_ARS_OD_YawRateAbs_Obj_15
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_14_15_ARS_OD_YawRateAbsStd_Obj_15
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_14_15_ARS_OD_YawRateAbsStd_Obj_15
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_14_15_ARS_OD_YawRateAbsStd_Obj_15
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_14_15_ARS_OD_RefPoint_Obj_15
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_14_15_ARS_OD_RefPoint_Obj_15
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_14_15_ARS_OD_RefPoint_Obj_15
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_14_15_ARS_OD_LifeCycle_Obj_15
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_14_15_ARS_OD_LifeCycle_Obj_15
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_14_15_ARS_OD_LifeCycle_Obj_15
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_14_15_ARS_OD_OrientationStd_Obj_14
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_14_15_ARS_OD_OrientationStd_Obj_14
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_14_15_ARS_OD_OrientationStd_Obj_14
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_14_15_ARS_OD_OrientationStd_Obj_15
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_14_15_ARS_OD_OrientationStd_Obj_15
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_14_15_ARS_OD_OrientationStd_Obj_15
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_14_15_ARS_OD_ObstacleProb_Obj_14
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_14_15_ARS_OD_ObstacleProb_Obj_14
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_14_15_ARS_OD_ObstacleProb_Obj_14
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_14_15_ARS_OD_MicroDopplerFlag_14
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_14_15_ARS_OD_MicroDopplerFlag_14
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_14_15_ARS_OD_MicroDopplerFlag_14
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_14_15_ARS_OD_ObstacleProb_Obj_15
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_14_15_ARS_OD_ObstacleProb_Obj_15
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_14_15_ARS_OD_ObstacleProb_Obj_15
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_14_15_ARS_OD_VabsY_Obj_14
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_14_15_ARS_OD_VabsY_Obj_14
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_14_15_ARS_OD_VabsY_Obj_14
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_14_15_ARS_OD_MicroDopplerFlag_15
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_14_15_ARS_OD_MicroDopplerFlag_15
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_14_15_ARS_OD_MicroDopplerFlag_15
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_14_15_ARS_OD_ID_14
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_14_15_ARS_OD_ID_14
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_14_15_ARS_OD_ID_14
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_14_15_ARS_OD_ID_15
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_14_15_ARS_OD_ID_15
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_14_15_ARS_OD_ID_15
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_14_15_ARS_OD_MsgCounter_Obj_14_15
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_14_15_ARS_OD_MsgCounter_Obj_14_15
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_14_15_ARS_OD_MsgCounter_Obj_14_15
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_14_15_ARS_OD_CRC16_Checksum_Obj_14_15
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_14_15_ARS_OD_CRC16_Checksum_Obj_14_15
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_14_15_ARS_OD_CRC16_Checksum_Obj_14_15
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_14_15_ARS_OD_AabsY_Obj_14
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_14_15_ARS_OD_AabsY_Obj_14
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_14_15_ARS_OD_AabsY_Obj_14
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_14_15_ARS_OD_DistXStd_Obj_14
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_14_15_ARS_OD_DistXStd_Obj_14
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_14_15_ARS_OD_DistXStd_Obj_14
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_14_15_ARS_OD_DistYStd_Obj_14
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_14_15_ARS_OD_DistYStd_Obj_14
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_14_15_ARS_OD_DistYStd_Obj_14
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_14_15_ARS_OD_VabsXStd_Obj_14
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_14_15_ARS_OD_VabsXStd_Obj_14
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_14_15_ARS_OD_VabsXStd_Obj_14
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_14_15_ARS_OD_VabsYStd_Obj_14
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_14_15_ARS_OD_VabsYStd_Obj_14
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_14_15_ARS_OD_VabsYStd_Obj_14
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_14_15_ARS_OD_AabsXStd_Obj_14
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_14_15_ARS_OD_AabsXStd_Obj_14
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_14_15_ARS_OD_AabsXStd_Obj_14
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_16_17_DistHeight_Obj_17
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_16_17_DistHeight_Obj_17
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_16_17_DistHeight_Obj_17
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_16_17_DistHeight_Obj_16
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_16_17_DistHeight_Obj_16
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_16_17_DistHeight_Obj_16
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_16_17_ARS_OD_DistX_Obj_16
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_16_17_ARS_OD_DistX_Obj_16
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_16_17_ARS_OD_DistX_Obj_16
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_16_17_ARS_OD_Classification_Obj_16
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_16_17_ARS_OD_Classification_Obj_16
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_16_17_ARS_OD_Classification_Obj_16
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_16_17_ARS_OD_AabsYStd_Obj_16
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_16_17_ARS_OD_AabsYStd_Obj_16
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_16_17_ARS_OD_AabsYStd_Obj_16
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_16_17_ARS_OD_ClassConf_Obj_16
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_16_17_ARS_OD_ClassConf_Obj_16
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_16_17_ARS_OD_ClassConf_Obj_16
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_16_17_ARS_OD_ProbOfExist_Obj_16
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_16_17_ARS_OD_ProbOfExist_Obj_16
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_16_17_ARS_OD_ProbOfExist_Obj_16
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_16_17_ARS_OD_DynConf_Obj_16
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_16_17_ARS_OD_DynConf_Obj_16
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_16_17_ARS_OD_DynConf_Obj_16
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_16_17_ARS_OD_VabsX_Obj_16
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_16_17_ARS_OD_VabsX_Obj_16
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_16_17_ARS_OD_VabsX_Obj_16
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_16_17_ARS_OD_DynProp_Obj_16
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_16_17_ARS_OD_DynProp_Obj_16
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_16_17_ARS_OD_DynProp_Obj_16
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_16_17_ARS_OD_MirrorProb_Obj_16
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_16_17_ARS_OD_MirrorProb_Obj_16
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_16_17_ARS_OD_MirrorProb_Obj_16
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_16_17_ARS_OD_Length_Obj_16
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_16_17_ARS_OD_Length_Obj_16
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_16_17_ARS_OD_Length_Obj_16
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_16_17_ARS_OD_MaintenanceState_Obj_16
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_16_17_ARS_OD_MaintenanceState_Obj_16
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_16_17_ARS_OD_MaintenanceState_Obj_16
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_16_17_ARS_OD_Width_Obj_16
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_16_17_ARS_OD_Width_Obj_16
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_16_17_ARS_OD_Width_Obj_16
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_16_17_ARS_OD_RCS_Obj_16
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_16_17_ARS_OD_RCS_Obj_16
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_16_17_ARS_OD_RCS_Obj_16
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_16_17_ARS_OD_Orientation_Obj_16
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_16_17_ARS_OD_Orientation_Obj_16
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_16_17_ARS_OD_Orientation_Obj_16
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_16_17_ARS_OD_YawRateAbs_Obj_16
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_16_17_ARS_OD_YawRateAbs_Obj_16
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_16_17_ARS_OD_YawRateAbs_Obj_16
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_16_17_ARS_OD_YawRateAbsStd_Obj_16
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_16_17_ARS_OD_YawRateAbsStd_Obj_16
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_16_17_ARS_OD_YawRateAbsStd_Obj_16
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_16_17_ARS_OD_RefPoint_Obj_16
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_16_17_ARS_OD_RefPoint_Obj_16
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_16_17_ARS_OD_RefPoint_Obj_16
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_16_17_ARS_OD_LifeCycle_Obj_16
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_16_17_ARS_OD_LifeCycle_Obj_16
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_16_17_ARS_OD_LifeCycle_Obj_16
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_16_17_ARS_OD_DistX_Obj_17
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_16_17_ARS_OD_DistX_Obj_17
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_16_17_ARS_OD_DistX_Obj_17
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_16_17_ARS_OD_VabsX_Obj_17
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_16_17_ARS_OD_VabsX_Obj_17
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_16_17_ARS_OD_VabsX_Obj_17
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_16_17_ARS_OD_AabsX_Obj_17
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_16_17_ARS_OD_AabsX_Obj_17
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_16_17_ARS_OD_AabsX_Obj_17
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_16_17_ARS_OD_AabsX_Obj_16
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_16_17_ARS_OD_AabsX_Obj_16
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_16_17_ARS_OD_AabsX_Obj_16
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_16_17_ARS_OD_DistY_Obj_17
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_16_17_ARS_OD_DistY_Obj_17
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_16_17_ARS_OD_DistY_Obj_17
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_16_17_ARS_OD_VabsY_Obj_17
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_16_17_ARS_OD_VabsY_Obj_17
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_16_17_ARS_OD_VabsY_Obj_17
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_16_17_ARS_OD_AabsY_Obj_17
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_16_17_ARS_OD_AabsY_Obj_17
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_16_17_ARS_OD_AabsY_Obj_17
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_16_17_ARS_OD_DistXStd_Obj_17
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_16_17_ARS_OD_DistXStd_Obj_17
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_16_17_ARS_OD_DistXStd_Obj_17
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_16_17_ARS_OD_DistYStd_Obj_17
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_16_17_ARS_OD_DistYStd_Obj_17
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_16_17_ARS_OD_DistYStd_Obj_17
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_16_17_ARS_OD_VabsXStd_Obj_17
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_16_17_ARS_OD_VabsXStd_Obj_17
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_16_17_ARS_OD_VabsXStd_Obj_17
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_16_17_ARS_OD_VabsYStd_Obj_17
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_16_17_ARS_OD_VabsYStd_Obj_17
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_16_17_ARS_OD_VabsYStd_Obj_17
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_16_17_ARS_OD_AabsXStd_Obj_17
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_16_17_ARS_OD_AabsXStd_Obj_17
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_16_17_ARS_OD_AabsXStd_Obj_17
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_16_17_ARS_OD_Classification_Obj_17
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_16_17_ARS_OD_Classification_Obj_17
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_16_17_ARS_OD_Classification_Obj_17
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_16_17_ARS_OD_AabsYStd_Obj_17
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_16_17_ARS_OD_AabsYStd_Obj_17
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_16_17_ARS_OD_AabsYStd_Obj_17
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_16_17_ARS_OD_ClassConf_Obj_17
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_16_17_ARS_OD_ClassConf_Obj_17
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_16_17_ARS_OD_ClassConf_Obj_17
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_16_17_ARS_OD_DistY_Obj_16
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_16_17_ARS_OD_DistY_Obj_16
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_16_17_ARS_OD_DistY_Obj_16
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_16_17_ARS_OD_ProbOfExist_Obj_17
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_16_17_ARS_OD_ProbOfExist_Obj_17
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_16_17_ARS_OD_ProbOfExist_Obj_17
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_16_17_ARS_OD_DynConf_Obj_17
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_16_17_ARS_OD_DynConf_Obj_17
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_16_17_ARS_OD_DynConf_Obj_17
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_16_17_ARS_OD_DynProp_Obj_17
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_16_17_ARS_OD_DynProp_Obj_17
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_16_17_ARS_OD_DynProp_Obj_17
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_16_17_ARS_OD_MirrorProb_Obj_17
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_16_17_ARS_OD_MirrorProb_Obj_17
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_16_17_ARS_OD_MirrorProb_Obj_17
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_16_17_ARS_OD_Length_Obj_17
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_16_17_ARS_OD_Length_Obj_17
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_16_17_ARS_OD_Length_Obj_17
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_16_17_ARS_OD_MaintenanceState_Obj_17
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_16_17_ARS_OD_MaintenanceState_Obj_17
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_16_17_ARS_OD_MaintenanceState_Obj_17
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_16_17_ARS_OD_Width_Obj_17
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_16_17_ARS_OD_Width_Obj_17
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_16_17_ARS_OD_Width_Obj_17
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_16_17_ARS_OD_RCS_Obj_17
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_16_17_ARS_OD_RCS_Obj_17
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_16_17_ARS_OD_RCS_Obj_17
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_16_17_ARS_OD_Orientation_Obj_17
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_16_17_ARS_OD_Orientation_Obj_17
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_16_17_ARS_OD_Orientation_Obj_17
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_16_17_ARS_OD_YawRateAbs_Obj_17
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_16_17_ARS_OD_YawRateAbs_Obj_17
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_16_17_ARS_OD_YawRateAbs_Obj_17
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_16_17_ARS_OD_YawRateAbsStd_Obj_17
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_16_17_ARS_OD_YawRateAbsStd_Obj_17
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_16_17_ARS_OD_YawRateAbsStd_Obj_17
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_16_17_ARS_OD_RefPoint_Obj_17
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_16_17_ARS_OD_RefPoint_Obj_17
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_16_17_ARS_OD_RefPoint_Obj_17
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_16_17_ARS_OD_LifeCycle_Obj_17
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_16_17_ARS_OD_LifeCycle_Obj_17
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_16_17_ARS_OD_LifeCycle_Obj_17
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_16_17_ARS_OD_OrientationStd_Obj_16
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_16_17_ARS_OD_OrientationStd_Obj_16
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_16_17_ARS_OD_OrientationStd_Obj_16
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_16_17_ARS_OD_OrientationStd_Obj_17
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_16_17_ARS_OD_OrientationStd_Obj_17
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_16_17_ARS_OD_OrientationStd_Obj_17
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_16_17_ARS_OD_ObstacleProb_Obj_16
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_16_17_ARS_OD_ObstacleProb_Obj_16
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_16_17_ARS_OD_ObstacleProb_Obj_16
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_16_17_ARS_OD_MicroDopplerFlag_16
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_16_17_ARS_OD_MicroDopplerFlag_16
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_16_17_ARS_OD_MicroDopplerFlag_16
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_16_17_ARS_OD_ObstacleProb_Obj_17
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_16_17_ARS_OD_ObstacleProb_Obj_17
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_16_17_ARS_OD_ObstacleProb_Obj_17
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_16_17_ARS_OD_VabsY_Obj_16
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_16_17_ARS_OD_VabsY_Obj_16
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_16_17_ARS_OD_VabsY_Obj_16
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_16_17_ARS_OD_MicroDopplerFlag_17
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_16_17_ARS_OD_MicroDopplerFlag_17
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_16_17_ARS_OD_MicroDopplerFlag_17
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_16_17_ARS_OD_ID_16
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_16_17_ARS_OD_ID_16
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_16_17_ARS_OD_ID_16
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_16_17_ARS_OD_ID_17
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_16_17_ARS_OD_ID_17
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_16_17_ARS_OD_ID_17
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_16_17_ARS_OD_MsgCounter_Obj_16_17
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_16_17_ARS_OD_MsgCounter_Obj_16_17
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_16_17_ARS_OD_MsgCounter_Obj_16_17
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_16_17_ARS_OD_CRC16_Checksum_Obj_16_17
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_16_17_ARS_OD_CRC16_Checksum_Obj_16_17
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_16_17_ARS_OD_CRC16_Checksum_Obj_16_17
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_16_17_ARS_OD_AabsY_Obj_16
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_16_17_ARS_OD_AabsY_Obj_16
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_16_17_ARS_OD_AabsY_Obj_16
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_16_17_ARS_OD_DistXStd_Obj_16
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_16_17_ARS_OD_DistXStd_Obj_16
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_16_17_ARS_OD_DistXStd_Obj_16
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_16_17_ARS_OD_DistYStd_Obj_16
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_16_17_ARS_OD_DistYStd_Obj_16
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_16_17_ARS_OD_DistYStd_Obj_16
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_16_17_ARS_OD_VabsXStd_Obj_16
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_16_17_ARS_OD_VabsXStd_Obj_16
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_16_17_ARS_OD_VabsXStd_Obj_16
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_16_17_ARS_OD_VabsYStd_Obj_16
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_16_17_ARS_OD_VabsYStd_Obj_16
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_16_17_ARS_OD_VabsYStd_Obj_16
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_16_17_ARS_OD_AabsXStd_Obj_16
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_16_17_ARS_OD_AabsXStd_Obj_16
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_16_17_ARS_OD_AabsXStd_Obj_16
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_18_19_DistHeight_Obj_19
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_18_19_DistHeight_Obj_19
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_18_19_DistHeight_Obj_19
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_18_19_DistHeight_Obj_18
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_18_19_DistHeight_Obj_18
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_18_19_DistHeight_Obj_18
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_18_19_ARS_OD_DistX_Obj_18
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_18_19_ARS_OD_DistX_Obj_18
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_18_19_ARS_OD_DistX_Obj_18
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_18_19_ARS_OD_Classification_Obj_18
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_18_19_ARS_OD_Classification_Obj_18
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_18_19_ARS_OD_Classification_Obj_18
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_18_19_ARS_OD_AabsYStd_Obj_18
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_18_19_ARS_OD_AabsYStd_Obj_18
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_18_19_ARS_OD_AabsYStd_Obj_18
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_18_19_ARS_OD_ClassConf_Obj_18
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_18_19_ARS_OD_ClassConf_Obj_18
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_18_19_ARS_OD_ClassConf_Obj_18
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_18_19_ARS_OD_ProbOfExist_Obj_18
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_18_19_ARS_OD_ProbOfExist_Obj_18
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_18_19_ARS_OD_ProbOfExist_Obj_18
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_18_19_ARS_OD_DynConf_Obj_18
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_18_19_ARS_OD_DynConf_Obj_18
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_18_19_ARS_OD_DynConf_Obj_18
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_18_19_ARS_OD_VabsX_Obj_18
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_18_19_ARS_OD_VabsX_Obj_18
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_18_19_ARS_OD_VabsX_Obj_18
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_18_19_ARS_OD_DynProp_Obj_18
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_18_19_ARS_OD_DynProp_Obj_18
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_18_19_ARS_OD_DynProp_Obj_18
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_18_19_ARS_OD_MirrorProb_Obj_18
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_18_19_ARS_OD_MirrorProb_Obj_18
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_18_19_ARS_OD_MirrorProb_Obj_18
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_18_19_ARS_OD_Length_Obj_18
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_18_19_ARS_OD_Length_Obj_18
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_18_19_ARS_OD_Length_Obj_18
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_18_19_ARS_OD_MaintenanceState_Obj_18
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_18_19_ARS_OD_MaintenanceState_Obj_18
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_18_19_ARS_OD_MaintenanceState_Obj_18
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_18_19_ARS_OD_Width_Obj_18
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_18_19_ARS_OD_Width_Obj_18
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_18_19_ARS_OD_Width_Obj_18
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_18_19_ARS_OD_RCS_Obj_18
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_18_19_ARS_OD_RCS_Obj_18
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_18_19_ARS_OD_RCS_Obj_18
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_18_19_ARS_OD_Orientation_Obj_18
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_18_19_ARS_OD_Orientation_Obj_18
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_18_19_ARS_OD_Orientation_Obj_18
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_18_19_ARS_OD_YawRateAbs_Obj_18
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_18_19_ARS_OD_YawRateAbs_Obj_18
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_18_19_ARS_OD_YawRateAbs_Obj_18
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_18_19_ARS_OD_YawRateAbsStd_Obj_18
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_18_19_ARS_OD_YawRateAbsStd_Obj_18
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_18_19_ARS_OD_YawRateAbsStd_Obj_18
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_18_19_ARS_OD_RefPoint_Obj_18
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_18_19_ARS_OD_RefPoint_Obj_18
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_18_19_ARS_OD_RefPoint_Obj_18
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_18_19_ARS_OD_LifeCycle_Obj_18
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_18_19_ARS_OD_LifeCycle_Obj_18
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_18_19_ARS_OD_LifeCycle_Obj_18
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_18_19_ARS_OD_DistX_Obj_19
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_18_19_ARS_OD_DistX_Obj_19
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_18_19_ARS_OD_DistX_Obj_19
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_18_19_ARS_OD_VabsX_Obj_19
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_18_19_ARS_OD_VabsX_Obj_19
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_18_19_ARS_OD_VabsX_Obj_19
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_18_19_ARS_OD_AabsX_Obj_19
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_18_19_ARS_OD_AabsX_Obj_19
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_18_19_ARS_OD_AabsX_Obj_19
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_18_19_ARS_OD_AabsX_Obj_18
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_18_19_ARS_OD_AabsX_Obj_18
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_18_19_ARS_OD_AabsX_Obj_18
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_18_19_ARS_OD_DistY_Obj_19
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_18_19_ARS_OD_DistY_Obj_19
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_18_19_ARS_OD_DistY_Obj_19
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_18_19_ARS_OD_VabsY_Obj_19
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_18_19_ARS_OD_VabsY_Obj_19
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_18_19_ARS_OD_VabsY_Obj_19
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_18_19_ARS_OD_AabsY_Obj_19
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_18_19_ARS_OD_AabsY_Obj_19
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_18_19_ARS_OD_AabsY_Obj_19
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_18_19_ARS_OD_DistXStd_Obj_19
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_18_19_ARS_OD_DistXStd_Obj_19
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_18_19_ARS_OD_DistXStd_Obj_19
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_18_19_ARS_OD_DistYStd_Obj_19
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_18_19_ARS_OD_DistYStd_Obj_19
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_18_19_ARS_OD_DistYStd_Obj_19
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_18_19_ARS_OD_VabsXStd_Obj_19
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_18_19_ARS_OD_VabsXStd_Obj_19
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_18_19_ARS_OD_VabsXStd_Obj_19
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_18_19_ARS_OD_VabsYStd_Obj_19
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_18_19_ARS_OD_VabsYStd_Obj_19
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_18_19_ARS_OD_VabsYStd_Obj_19
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_18_19_ARS_OD_AabsXStd_Obj_19
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_18_19_ARS_OD_AabsXStd_Obj_19
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_18_19_ARS_OD_AabsXStd_Obj_19
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_18_19_ARS_OD_Classification_Obj_19
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_18_19_ARS_OD_Classification_Obj_19
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_18_19_ARS_OD_Classification_Obj_19
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_18_19_ARS_OD_AabsYStd_Obj_19
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_18_19_ARS_OD_AabsYStd_Obj_19
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_18_19_ARS_OD_AabsYStd_Obj_19
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_18_19_ARS_OD_ClassConf_Obj_19
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_18_19_ARS_OD_ClassConf_Obj_19
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_18_19_ARS_OD_ClassConf_Obj_19
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_18_19_ARS_OD_DistY_Obj_18
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_18_19_ARS_OD_DistY_Obj_18
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_18_19_ARS_OD_DistY_Obj_18
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_18_19_ARS_OD_ProbOfExist_Obj_19
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_18_19_ARS_OD_ProbOfExist_Obj_19
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_18_19_ARS_OD_ProbOfExist_Obj_19
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_18_19_ARS_OD_DynConf_Obj_19
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_18_19_ARS_OD_DynConf_Obj_19
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_18_19_ARS_OD_DynConf_Obj_19
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_18_19_ARS_OD_DynProp_Obj_19
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_18_19_ARS_OD_DynProp_Obj_19
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_18_19_ARS_OD_DynProp_Obj_19
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_18_19_ARS_OD_MirrorProb_Obj_19
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_18_19_ARS_OD_MirrorProb_Obj_19
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_18_19_ARS_OD_MirrorProb_Obj_19
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_18_19_ARS_OD_Length_Obj_19
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_18_19_ARS_OD_Length_Obj_19
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_18_19_ARS_OD_Length_Obj_19
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_18_19_ARS_OD_MaintenanceState_Obj_19
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_18_19_ARS_OD_MaintenanceState_Obj_19
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_18_19_ARS_OD_MaintenanceState_Obj_19
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_18_19_ARS_OD_Width_Obj_19
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_18_19_ARS_OD_Width_Obj_19
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_18_19_ARS_OD_Width_Obj_19
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_18_19_ARS_OD_RCS_Obj_19
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_18_19_ARS_OD_RCS_Obj_19
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_18_19_ARS_OD_RCS_Obj_19
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_18_19_ARS_OD_Orientation_Obj_19
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_18_19_ARS_OD_Orientation_Obj_19
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_18_19_ARS_OD_Orientation_Obj_19
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_18_19_ARS_OD_YawRateAbs_Obj_19
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_18_19_ARS_OD_YawRateAbs_Obj_19
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_18_19_ARS_OD_YawRateAbs_Obj_19
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_18_19_ARS_OD_YawRateAbsStd_Obj_19
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_18_19_ARS_OD_YawRateAbsStd_Obj_19
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_18_19_ARS_OD_YawRateAbsStd_Obj_19
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_18_19_ARS_OD_RefPoint_Obj_19
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_18_19_ARS_OD_RefPoint_Obj_19
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_18_19_ARS_OD_RefPoint_Obj_19
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_18_19_ARS_OD_LifeCycle_Obj_19
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_18_19_ARS_OD_LifeCycle_Obj_19
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_18_19_ARS_OD_LifeCycle_Obj_19
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_18_19_ARS_OD_OrientationStd_Obj_18
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_18_19_ARS_OD_OrientationStd_Obj_18
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_18_19_ARS_OD_OrientationStd_Obj_18
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_18_19_ARS_OD_OrientationStd_Obj_19
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_18_19_ARS_OD_OrientationStd_Obj_19
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_18_19_ARS_OD_OrientationStd_Obj_19
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_18_19_ARS_OD_ObstacleProb_Obj_18
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_18_19_ARS_OD_ObstacleProb_Obj_18
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_18_19_ARS_OD_ObstacleProb_Obj_18
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_18_19_ARS_OD_MicroDopplerFlag_18
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_18_19_ARS_OD_MicroDopplerFlag_18
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_18_19_ARS_OD_MicroDopplerFlag_18
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_18_19_ARS_OD_ObstacleProb_Obj_19
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_18_19_ARS_OD_ObstacleProb_Obj_19
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_18_19_ARS_OD_ObstacleProb_Obj_19
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_18_19_ARS_OD_VabsY_Obj_18
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_18_19_ARS_OD_VabsY_Obj_18
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_18_19_ARS_OD_VabsY_Obj_18
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_18_19_ARS_OD_MicroDopplerFlag_19
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_18_19_ARS_OD_MicroDopplerFlag_19
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_18_19_ARS_OD_MicroDopplerFlag_19
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_18_19_ARS_OD_ID_18
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_18_19_ARS_OD_ID_18
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_18_19_ARS_OD_ID_18
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_18_19_ARS_OD_ID_19
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_18_19_ARS_OD_ID_19
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_18_19_ARS_OD_ID_19
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_18_19_ARS_OD_MsgCounter_Obj_18_19
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_18_19_ARS_OD_MsgCounter_Obj_18_19
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_18_19_ARS_OD_MsgCounter_Obj_18_19
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_18_19_ARS_OD_CRC16_Checksum_Obj_18_19
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_18_19_ARS_OD_CRC16_Checksum_Obj_18_19
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_18_19_ARS_OD_CRC16_Checksum_Obj_18_19
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_18_19_ARS_OD_AabsY_Obj_18
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_18_19_ARS_OD_AabsY_Obj_18
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_18_19_ARS_OD_AabsY_Obj_18
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_18_19_ARS_OD_DistXStd_Obj_18
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_18_19_ARS_OD_DistXStd_Obj_18
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_18_19_ARS_OD_DistXStd_Obj_18
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_18_19_ARS_OD_DistYStd_Obj_18
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_18_19_ARS_OD_DistYStd_Obj_18
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_18_19_ARS_OD_DistYStd_Obj_18
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_18_19_ARS_OD_VabsXStd_Obj_18
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_18_19_ARS_OD_VabsXStd_Obj_18
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_18_19_ARS_OD_VabsXStd_Obj_18
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_18_19_ARS_OD_VabsYStd_Obj_18
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_18_19_ARS_OD_VabsYStd_Obj_18
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_18_19_ARS_OD_VabsYStd_Obj_18
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_18_19_ARS_OD_AabsXStd_Obj_18
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_18_19_ARS_OD_AabsXStd_Obj_18
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_18_19_ARS_OD_AabsXStd_Obj_18
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_20_21_DistHeight_Obj_21
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_20_21_DistHeight_Obj_21
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_20_21_DistHeight_Obj_21
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_20_21_DistHeight_Obj_20
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_20_21_DistHeight_Obj_20
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_20_21_DistHeight_Obj_20
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_20_21_ARS_OD_DistX_Obj_20
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_20_21_ARS_OD_DistX_Obj_20
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_20_21_ARS_OD_DistX_Obj_20
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_20_21_ARS_OD_Classification_Obj_20
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_20_21_ARS_OD_Classification_Obj_20
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_20_21_ARS_OD_Classification_Obj_20
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_20_21_ARS_OD_AabsYStd_Obj_20
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_20_21_ARS_OD_AabsYStd_Obj_20
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_20_21_ARS_OD_AabsYStd_Obj_20
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_20_21_ARS_OD_ClassConf_Obj_20
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_20_21_ARS_OD_ClassConf_Obj_20
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_20_21_ARS_OD_ClassConf_Obj_20
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_20_21_ARS_OD_ProbOfExist_Obj_20
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_20_21_ARS_OD_ProbOfExist_Obj_20
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_20_21_ARS_OD_ProbOfExist_Obj_20
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_20_21_ARS_OD_DynConf_Obj_20
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_20_21_ARS_OD_DynConf_Obj_20
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_20_21_ARS_OD_DynConf_Obj_20
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_20_21_ARS_OD_VabsX_Obj_20
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_20_21_ARS_OD_VabsX_Obj_20
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_20_21_ARS_OD_VabsX_Obj_20
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_20_21_ARS_OD_DynProp_Obj_20
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_20_21_ARS_OD_DynProp_Obj_20
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_20_21_ARS_OD_DynProp_Obj_20
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_20_21_ARS_OD_MirrorProb_Obj_20
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_20_21_ARS_OD_MirrorProb_Obj_20
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_20_21_ARS_OD_MirrorProb_Obj_20
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_20_21_ARS_OD_Length_Obj_20
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_20_21_ARS_OD_Length_Obj_20
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_20_21_ARS_OD_Length_Obj_20
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_20_21_ARS_OD_MaintenanceState_Obj_20
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_20_21_ARS_OD_MaintenanceState_Obj_20
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_20_21_ARS_OD_MaintenanceState_Obj_20
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_20_21_ARS_OD_Width_Obj_20
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_20_21_ARS_OD_Width_Obj_20
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_20_21_ARS_OD_Width_Obj_20
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_20_21_ARS_OD_RCS_Obj_20
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_20_21_ARS_OD_RCS_Obj_20
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_20_21_ARS_OD_RCS_Obj_20
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_20_21_ARS_OD_Orientation_Obj_20
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_20_21_ARS_OD_Orientation_Obj_20
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_20_21_ARS_OD_Orientation_Obj_20
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_20_21_ARS_OD_YawRateAbs_Obj_20
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_20_21_ARS_OD_YawRateAbs_Obj_20
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_20_21_ARS_OD_YawRateAbs_Obj_20
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_20_21_ARS_OD_YawRateAbsStd_Obj_20
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_20_21_ARS_OD_YawRateAbsStd_Obj_20
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_20_21_ARS_OD_YawRateAbsStd_Obj_20
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_20_21_ARS_OD_RefPoint_Obj_20
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_20_21_ARS_OD_RefPoint_Obj_20
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_20_21_ARS_OD_RefPoint_Obj_20
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_20_21_ARS_OD_LifeCycle_Obj_20
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_20_21_ARS_OD_LifeCycle_Obj_20
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_20_21_ARS_OD_LifeCycle_Obj_20
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_20_21_ARS_OD_DistX_Obj_21
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_20_21_ARS_OD_DistX_Obj_21
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_20_21_ARS_OD_DistX_Obj_21
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_20_21_ARS_OD_VabsX_Obj_21
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_20_21_ARS_OD_VabsX_Obj_21
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_20_21_ARS_OD_VabsX_Obj_21
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_20_21_ARS_OD_AabsX_Obj_21
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_20_21_ARS_OD_AabsX_Obj_21
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_20_21_ARS_OD_AabsX_Obj_21
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_20_21_ARS_OD_AabsX_Obj_20
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_20_21_ARS_OD_AabsX_Obj_20
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_20_21_ARS_OD_AabsX_Obj_20
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_20_21_ARS_OD_DistY_Obj_21
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_20_21_ARS_OD_DistY_Obj_21
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_20_21_ARS_OD_DistY_Obj_21
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_20_21_ARS_OD_VabsY_Obj_21
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_20_21_ARS_OD_VabsY_Obj_21
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_20_21_ARS_OD_VabsY_Obj_21
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_20_21_ARS_OD_AabsY_Obj_21
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_20_21_ARS_OD_AabsY_Obj_21
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_20_21_ARS_OD_AabsY_Obj_21
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_20_21_ARS_OD_DistXStd_Obj_21
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_20_21_ARS_OD_DistXStd_Obj_21
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_20_21_ARS_OD_DistXStd_Obj_21
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_20_21_ARS_OD_DistYStd_Obj_21
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_20_21_ARS_OD_DistYStd_Obj_21
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_20_21_ARS_OD_DistYStd_Obj_21
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_20_21_ARS_OD_VabsXStd_Obj_21
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_20_21_ARS_OD_VabsXStd_Obj_21
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_20_21_ARS_OD_VabsXStd_Obj_21
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_20_21_ARS_OD_VabsYStd_Obj_21
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_20_21_ARS_OD_VabsYStd_Obj_21
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_20_21_ARS_OD_VabsYStd_Obj_21
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_20_21_ARS_OD_AabsXStd_Obj_21
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_20_21_ARS_OD_AabsXStd_Obj_21
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_20_21_ARS_OD_AabsXStd_Obj_21
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_20_21_ARS_OD_Classification_Obj_21
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_20_21_ARS_OD_Classification_Obj_21
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_20_21_ARS_OD_Classification_Obj_21
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_20_21_ARS_OD_AabsYStd_Obj_21
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_20_21_ARS_OD_AabsYStd_Obj_21
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_20_21_ARS_OD_AabsYStd_Obj_21
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_20_21_ARS_OD_ClassConf_Obj_21
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_20_21_ARS_OD_ClassConf_Obj_21
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_20_21_ARS_OD_ClassConf_Obj_21
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_20_21_ARS_OD_DistY_Obj_20
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_20_21_ARS_OD_DistY_Obj_20
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_20_21_ARS_OD_DistY_Obj_20
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_20_21_ARS_OD_ProbOfExist_Obj_21
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_20_21_ARS_OD_ProbOfExist_Obj_21
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_20_21_ARS_OD_ProbOfExist_Obj_21
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_20_21_ARS_OD_DynConf_Obj_21
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_20_21_ARS_OD_DynConf_Obj_21
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_20_21_ARS_OD_DynConf_Obj_21
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_20_21_ARS_OD_DynProp_Obj_21
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_20_21_ARS_OD_DynProp_Obj_21
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_20_21_ARS_OD_DynProp_Obj_21
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_20_21_ARS_OD_MirrorProb_Obj_21
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_20_21_ARS_OD_MirrorProb_Obj_21
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_20_21_ARS_OD_MirrorProb_Obj_21
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_20_21_ARS_OD_Length_Obj_21
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_20_21_ARS_OD_Length_Obj_21
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_20_21_ARS_OD_Length_Obj_21
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_20_21_ARS_OD_MaintenanceState_Obj_21
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_20_21_ARS_OD_MaintenanceState_Obj_21
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_20_21_ARS_OD_MaintenanceState_Obj_21
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_20_21_ARS_OD_Width_Obj_21
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_20_21_ARS_OD_Width_Obj_21
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_20_21_ARS_OD_Width_Obj_21
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_20_21_ARS_OD_RCS_Obj_21
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_20_21_ARS_OD_RCS_Obj_21
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_20_21_ARS_OD_RCS_Obj_21
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_20_21_ARS_OD_Orientation_Obj_21
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_20_21_ARS_OD_Orientation_Obj_21
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_20_21_ARS_OD_Orientation_Obj_21
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_20_21_ARS_OD_YawRateAbs_Obj_21
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_20_21_ARS_OD_YawRateAbs_Obj_21
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_20_21_ARS_OD_YawRateAbs_Obj_21
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_20_21_ARS_OD_YawRateAbsStd_Obj_21
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_20_21_ARS_OD_YawRateAbsStd_Obj_21
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_20_21_ARS_OD_YawRateAbsStd_Obj_21
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_20_21_ARS_OD_RefPoint_Obj_21
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_20_21_ARS_OD_RefPoint_Obj_21
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_20_21_ARS_OD_RefPoint_Obj_21
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_20_21_ARS_OD_LifeCycle_Obj_21
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_20_21_ARS_OD_LifeCycle_Obj_21
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_20_21_ARS_OD_LifeCycle_Obj_21
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_20_21_ARS_OD_OrientationStd_Obj_20
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_20_21_ARS_OD_OrientationStd_Obj_20
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_20_21_ARS_OD_OrientationStd_Obj_20
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_20_21_ARS_OD_OrientationStd_Obj_21
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_20_21_ARS_OD_OrientationStd_Obj_21
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_20_21_ARS_OD_OrientationStd_Obj_21
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_20_21_ARS_OD_ObstacleProb_Obj_20
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_20_21_ARS_OD_ObstacleProb_Obj_20
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_20_21_ARS_OD_ObstacleProb_Obj_20
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_20_21_ARS_OD_MicroDopplerFlag_20
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_20_21_ARS_OD_MicroDopplerFlag_20
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_20_21_ARS_OD_MicroDopplerFlag_20
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_20_21_ARS_OD_ObstacleProb_Obj_21
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_20_21_ARS_OD_ObstacleProb_Obj_21
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_20_21_ARS_OD_ObstacleProb_Obj_21
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_20_21_ARS_OD_VabsY_Obj_20
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_20_21_ARS_OD_VabsY_Obj_20
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_20_21_ARS_OD_VabsY_Obj_20
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_20_21_ARS_OD_MicroDopplerFlag_21
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_20_21_ARS_OD_MicroDopplerFlag_21
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_20_21_ARS_OD_MicroDopplerFlag_21
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_20_21_ARS_OD_ID_20
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_20_21_ARS_OD_ID_20
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_20_21_ARS_OD_ID_20
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_20_21_ARS_OD_ID_21
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_20_21_ARS_OD_ID_21
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_20_21_ARS_OD_ID_21
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_20_21_ARS_OD_MsgCounter_Obj_20_21
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_20_21_ARS_OD_MsgCounter_Obj_20_21
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_20_21_ARS_OD_MsgCounter_Obj_20_21
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_20_21_ARS_OD_CRC16_Checksum_Obj_20_21
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_20_21_ARS_OD_CRC16_Checksum_Obj_20_21
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_20_21_ARS_OD_CRC16_Checksum_Obj_20_21
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_20_21_ARS_OD_AabsY_Obj_20
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_20_21_ARS_OD_AabsY_Obj_20
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_20_21_ARS_OD_AabsY_Obj_20
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_20_21_ARS_OD_DistXStd_Obj_20
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_20_21_ARS_OD_DistXStd_Obj_20
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_20_21_ARS_OD_DistXStd_Obj_20
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_20_21_ARS_OD_DistYStd_Obj_20
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_20_21_ARS_OD_DistYStd_Obj_20
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_20_21_ARS_OD_DistYStd_Obj_20
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_20_21_ARS_OD_VabsXStd_Obj_20
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_20_21_ARS_OD_VabsXStd_Obj_20
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_20_21_ARS_OD_VabsXStd_Obj_20
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_20_21_ARS_OD_VabsYStd_Obj_20
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_20_21_ARS_OD_VabsYStd_Obj_20
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_20_21_ARS_OD_VabsYStd_Obj_20
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_20_21_ARS_OD_AabsXStd_Obj_20
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_20_21_ARS_OD_AabsXStd_Obj_20
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_20_21_ARS_OD_AabsXStd_Obj_20
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_22_23_DistHeight_Obj_23
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_22_23_DistHeight_Obj_23
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_22_23_DistHeight_Obj_23
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_22_23_DistHeight_Obj_22
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_22_23_DistHeight_Obj_22
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_22_23_DistHeight_Obj_22
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_22_23_ARS_OD_DistX_Obj_22
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_22_23_ARS_OD_DistX_Obj_22
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_22_23_ARS_OD_DistX_Obj_22
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_22_23_ARS_OD_Classification_Obj_22
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_22_23_ARS_OD_Classification_Obj_22
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_22_23_ARS_OD_Classification_Obj_22
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_22_23_ARS_OD_AabsYStd_Obj_22
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_22_23_ARS_OD_AabsYStd_Obj_22
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_22_23_ARS_OD_AabsYStd_Obj_22
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_22_23_ARS_OD_ClassConf_Obj_22
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_22_23_ARS_OD_ClassConf_Obj_22
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_22_23_ARS_OD_ClassConf_Obj_22
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_22_23_ARS_OD_ProbOfExist_Obj_22
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_22_23_ARS_OD_ProbOfExist_Obj_22
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_22_23_ARS_OD_ProbOfExist_Obj_22
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_22_23_ARS_OD_DynConf_Obj_22
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_22_23_ARS_OD_DynConf_Obj_22
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_22_23_ARS_OD_DynConf_Obj_22
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_22_23_ARS_OD_VabsX_Obj_22
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_22_23_ARS_OD_VabsX_Obj_22
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_22_23_ARS_OD_VabsX_Obj_22
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_22_23_ARS_OD_DynProp_Obj_22
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_22_23_ARS_OD_DynProp_Obj_22
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_22_23_ARS_OD_DynProp_Obj_22
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_22_23_ARS_OD_MirrorProb_Obj_22
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_22_23_ARS_OD_MirrorProb_Obj_22
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_22_23_ARS_OD_MirrorProb_Obj_22
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_22_23_ARS_OD_Length_Obj_22
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_22_23_ARS_OD_Length_Obj_22
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_22_23_ARS_OD_Length_Obj_22
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_22_23_ARS_OD_MaintenanceState_Obj_22
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_22_23_ARS_OD_MaintenanceState_Obj_22
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_22_23_ARS_OD_MaintenanceState_Obj_22
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_22_23_ARS_OD_Width_Obj_22
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_22_23_ARS_OD_Width_Obj_22
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_22_23_ARS_OD_Width_Obj_22
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_22_23_ARS_OD_RCS_Obj_22
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_22_23_ARS_OD_RCS_Obj_22
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_22_23_ARS_OD_RCS_Obj_22
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_22_23_ARS_OD_Orientation_Obj_22
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_22_23_ARS_OD_Orientation_Obj_22
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_22_23_ARS_OD_Orientation_Obj_22
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_22_23_ARS_OD_YawRateAbs_Obj_22
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_22_23_ARS_OD_YawRateAbs_Obj_22
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_22_23_ARS_OD_YawRateAbs_Obj_22
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_22_23_ARS_OD_YawRateAbsStd_Obj_22
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_22_23_ARS_OD_YawRateAbsStd_Obj_22
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_22_23_ARS_OD_YawRateAbsStd_Obj_22
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_22_23_ARS_OD_RefPoint_Obj_22
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_22_23_ARS_OD_RefPoint_Obj_22
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_22_23_ARS_OD_RefPoint_Obj_22
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_22_23_ARS_OD_LifeCycle_Obj_22
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_22_23_ARS_OD_LifeCycle_Obj_22
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_22_23_ARS_OD_LifeCycle_Obj_22
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_22_23_ARS_OD_DistX_Obj_23
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_22_23_ARS_OD_DistX_Obj_23
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_22_23_ARS_OD_DistX_Obj_23
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_22_23_ARS_OD_VabsX_Obj_23
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_22_23_ARS_OD_VabsX_Obj_23
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_22_23_ARS_OD_VabsX_Obj_23
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_22_23_ARS_OD_AabsX_Obj_23
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_22_23_ARS_OD_AabsX_Obj_23
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_22_23_ARS_OD_AabsX_Obj_23
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_22_23_ARS_OD_AabsX_Obj_22
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_22_23_ARS_OD_AabsX_Obj_22
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_22_23_ARS_OD_AabsX_Obj_22
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_22_23_ARS_OD_DistY_Obj_23
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_22_23_ARS_OD_DistY_Obj_23
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_22_23_ARS_OD_DistY_Obj_23
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_22_23_ARS_OD_VabsY_Obj_23
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_22_23_ARS_OD_VabsY_Obj_23
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_22_23_ARS_OD_VabsY_Obj_23
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_22_23_ARS_OD_AabsY_Obj_23
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_22_23_ARS_OD_AabsY_Obj_23
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_22_23_ARS_OD_AabsY_Obj_23
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_22_23_ARS_OD_DistXStd_Obj_23
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_22_23_ARS_OD_DistXStd_Obj_23
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_22_23_ARS_OD_DistXStd_Obj_23
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_22_23_ARS_OD_DistYStd_Obj_23
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_22_23_ARS_OD_DistYStd_Obj_23
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_22_23_ARS_OD_DistYStd_Obj_23
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_22_23_ARS_OD_VabsXStd_Obj_23
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_22_23_ARS_OD_VabsXStd_Obj_23
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_22_23_ARS_OD_VabsXStd_Obj_23
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_22_23_ARS_OD_VabsYStd_Obj_23
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_22_23_ARS_OD_VabsYStd_Obj_23
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_22_23_ARS_OD_VabsYStd_Obj_23
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_22_23_ARS_OD_AabsXStd_Obj_23
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_22_23_ARS_OD_AabsXStd_Obj_23
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_22_23_ARS_OD_AabsXStd_Obj_23
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_22_23_ARS_OD_Classification_Obj_23
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_22_23_ARS_OD_Classification_Obj_23
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_22_23_ARS_OD_Classification_Obj_23
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_22_23_ARS_OD_AabsYStd_Obj_23
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_22_23_ARS_OD_AabsYStd_Obj_23
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_22_23_ARS_OD_AabsYStd_Obj_23
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_22_23_ARS_OD_ClassConf_Obj_23
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_22_23_ARS_OD_ClassConf_Obj_23
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_22_23_ARS_OD_ClassConf_Obj_23
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_22_23_ARS_OD_DistY_Obj_22
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_22_23_ARS_OD_DistY_Obj_22
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_22_23_ARS_OD_DistY_Obj_22
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_22_23_ARS_OD_ProbOfExist_Obj_23
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_22_23_ARS_OD_ProbOfExist_Obj_23
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_22_23_ARS_OD_ProbOfExist_Obj_23
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_22_23_ARS_OD_DynConf_Obj_23
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_22_23_ARS_OD_DynConf_Obj_23
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_22_23_ARS_OD_DynConf_Obj_23
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_22_23_ARS_OD_DynProp_Obj_23
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_22_23_ARS_OD_DynProp_Obj_23
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_22_23_ARS_OD_DynProp_Obj_23
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_22_23_ARS_OD_MirrorProb_Obj_23
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_22_23_ARS_OD_MirrorProb_Obj_23
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_22_23_ARS_OD_MirrorProb_Obj_23
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_22_23_ARS_OD_Length_Obj_23
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_22_23_ARS_OD_Length_Obj_23
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_22_23_ARS_OD_Length_Obj_23
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_22_23_ARS_OD_MaintenanceState_Obj_23
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_22_23_ARS_OD_MaintenanceState_Obj_23
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_22_23_ARS_OD_MaintenanceState_Obj_23
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_22_23_ARS_OD_Width_Obj_23
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_22_23_ARS_OD_Width_Obj_23
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_22_23_ARS_OD_Width_Obj_23
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_22_23_ARS_OD_RCS_Obj_23
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_22_23_ARS_OD_RCS_Obj_23
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_22_23_ARS_OD_RCS_Obj_23
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_22_23_ARS_OD_Orientation_Obj_23
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_22_23_ARS_OD_Orientation_Obj_23
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_22_23_ARS_OD_Orientation_Obj_23
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_22_23_ARS_OD_YawRateAbs_Obj_23
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_22_23_ARS_OD_YawRateAbs_Obj_23
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_22_23_ARS_OD_YawRateAbs_Obj_23
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_22_23_ARS_OD_YawRateAbsStd_Obj_23
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_22_23_ARS_OD_YawRateAbsStd_Obj_23
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_22_23_ARS_OD_YawRateAbsStd_Obj_23
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_22_23_ARS_OD_RefPoint_Obj_23
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_22_23_ARS_OD_RefPoint_Obj_23
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_22_23_ARS_OD_RefPoint_Obj_23
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_22_23_ARS_OD_LifeCycle_Obj_23
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_22_23_ARS_OD_LifeCycle_Obj_23
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_22_23_ARS_OD_LifeCycle_Obj_23
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_22_23_ARS_OD_OrientationStd_Obj_22
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_22_23_ARS_OD_OrientationStd_Obj_22
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_22_23_ARS_OD_OrientationStd_Obj_22
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_22_23_ARS_OD_OrientationStd_Obj_23
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_22_23_ARS_OD_OrientationStd_Obj_23
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_22_23_ARS_OD_OrientationStd_Obj_23
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_22_23_ARS_OD_ObstacleProb_Obj_22
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_22_23_ARS_OD_ObstacleProb_Obj_22
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_22_23_ARS_OD_ObstacleProb_Obj_22
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_22_23_ARS_OD_MicroDopplerFlag_22
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_22_23_ARS_OD_MicroDopplerFlag_22
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_22_23_ARS_OD_MicroDopplerFlag_22
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_22_23_ARS_OD_ObstacleProb_Obj_23
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_22_23_ARS_OD_ObstacleProb_Obj_23
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_22_23_ARS_OD_ObstacleProb_Obj_23
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_22_23_ARS_OD_VabsY_Obj_22
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_22_23_ARS_OD_VabsY_Obj_22
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_22_23_ARS_OD_VabsY_Obj_22
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_22_23_ARS_OD_MicroDopplerFlag_23
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_22_23_ARS_OD_MicroDopplerFlag_23
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_22_23_ARS_OD_MicroDopplerFlag_23
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_22_23_ARS_OD_ID_22
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_22_23_ARS_OD_ID_22
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_22_23_ARS_OD_ID_22
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_22_23_ARS_OD_ID_23
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_22_23_ARS_OD_ID_23
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_22_23_ARS_OD_ID_23
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_22_23_ARS_OD_MsgCounter_Obj_22_23
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_22_23_ARS_OD_MsgCounter_Obj_22_23
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_22_23_ARS_OD_MsgCounter_Obj_22_23
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_22_23_ARS_OD_CRC16_Checksum_Obj_22_23
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_22_23_ARS_OD_CRC16_Checksum_Obj_22_23
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_22_23_ARS_OD_CRC16_Checksum_Obj_22_23
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_22_23_ARS_OD_AabsY_Obj_22
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_22_23_ARS_OD_AabsY_Obj_22
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_22_23_ARS_OD_AabsY_Obj_22
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_22_23_ARS_OD_DistXStd_Obj_22
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_22_23_ARS_OD_DistXStd_Obj_22
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_22_23_ARS_OD_DistXStd_Obj_22
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_22_23_ARS_OD_DistYStd_Obj_22
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_22_23_ARS_OD_DistYStd_Obj_22
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_22_23_ARS_OD_DistYStd_Obj_22
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_22_23_ARS_OD_VabsXStd_Obj_22
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_22_23_ARS_OD_VabsXStd_Obj_22
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_22_23_ARS_OD_VabsXStd_Obj_22
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_22_23_ARS_OD_VabsYStd_Obj_22
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_22_23_ARS_OD_VabsYStd_Obj_22
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_22_23_ARS_OD_VabsYStd_Obj_22
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_22_23_ARS_OD_AabsXStd_Obj_22
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_22_23_ARS_OD_AabsXStd_Obj_22
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_22_23_ARS_OD_AabsXStd_Obj_22
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_24_25_DistHeight_Obj_25
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_24_25_DistHeight_Obj_25
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_24_25_DistHeight_Obj_25
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_24_25_DistHeight_Obj_24
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_24_25_DistHeight_Obj_24
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_24_25_DistHeight_Obj_24
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_24_25_ARS_OD_DistX_Obj_24
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_24_25_ARS_OD_DistX_Obj_24
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_24_25_ARS_OD_DistX_Obj_24
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_24_25_ARS_OD_Classification_Obj_24
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_24_25_ARS_OD_Classification_Obj_24
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_24_25_ARS_OD_Classification_Obj_24
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_24_25_ARS_OD_AabsYStd_Obj_24
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_24_25_ARS_OD_AabsYStd_Obj_24
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_24_25_ARS_OD_AabsYStd_Obj_24
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_24_25_ARS_OD_ClassConf_Obj_24
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_24_25_ARS_OD_ClassConf_Obj_24
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_24_25_ARS_OD_ClassConf_Obj_24
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_24_25_ARS_OD_ProbOfExist_Obj_24
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_24_25_ARS_OD_ProbOfExist_Obj_24
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_24_25_ARS_OD_ProbOfExist_Obj_24
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_24_25_ARS_OD_DynConf_Obj_24
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_24_25_ARS_OD_DynConf_Obj_24
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_24_25_ARS_OD_DynConf_Obj_24
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_24_25_ARS_OD_VabsX_Obj_24
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_24_25_ARS_OD_VabsX_Obj_24
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_24_25_ARS_OD_VabsX_Obj_24
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_24_25_ARS_OD_DynProp_Obj_24
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_24_25_ARS_OD_DynProp_Obj_24
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_24_25_ARS_OD_DynProp_Obj_24
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_24_25_ARS_OD_MirrorProb_Obj_24
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_24_25_ARS_OD_MirrorProb_Obj_24
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_24_25_ARS_OD_MirrorProb_Obj_24
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_24_25_ARS_OD_Length_Obj_24
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_24_25_ARS_OD_Length_Obj_24
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_24_25_ARS_OD_Length_Obj_24
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_24_25_ARS_OD_MaintenanceState_Obj_24
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_24_25_ARS_OD_MaintenanceState_Obj_24
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_24_25_ARS_OD_MaintenanceState_Obj_24
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_24_25_ARS_OD_Width_Obj_24
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_24_25_ARS_OD_Width_Obj_24
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_24_25_ARS_OD_Width_Obj_24
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_24_25_ARS_OD_RCS_Obj_24
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_24_25_ARS_OD_RCS_Obj_24
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_24_25_ARS_OD_RCS_Obj_24
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_24_25_ARS_OD_Orientation_Obj_24
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_24_25_ARS_OD_Orientation_Obj_24
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_24_25_ARS_OD_Orientation_Obj_24
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_24_25_ARS_OD_YawRateAbs_Obj_24
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_24_25_ARS_OD_YawRateAbs_Obj_24
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_24_25_ARS_OD_YawRateAbs_Obj_24
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_24_25_ARS_OD_YawRateAbsStd_Obj_24
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_24_25_ARS_OD_YawRateAbsStd_Obj_24
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_24_25_ARS_OD_YawRateAbsStd_Obj_24
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_24_25_ARS_OD_RefPoint_Obj_24
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_24_25_ARS_OD_RefPoint_Obj_24
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_24_25_ARS_OD_RefPoint_Obj_24
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_24_25_ARS_OD_LifeCycle_Obj_24
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_24_25_ARS_OD_LifeCycle_Obj_24
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_24_25_ARS_OD_LifeCycle_Obj_24
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_24_25_ARS_OD_DistX_Obj_25
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_24_25_ARS_OD_DistX_Obj_25
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_24_25_ARS_OD_DistX_Obj_25
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_24_25_ARS_OD_VabsX_Obj_25
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_24_25_ARS_OD_VabsX_Obj_25
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_24_25_ARS_OD_VabsX_Obj_25
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_24_25_ARS_OD_AabsX_Obj_25
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_24_25_ARS_OD_AabsX_Obj_25
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_24_25_ARS_OD_AabsX_Obj_25
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_24_25_ARS_OD_AabsX_Obj_24
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_24_25_ARS_OD_AabsX_Obj_24
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_24_25_ARS_OD_AabsX_Obj_24
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_24_25_ARS_OD_DistY_Obj_25
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_24_25_ARS_OD_DistY_Obj_25
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_24_25_ARS_OD_DistY_Obj_25
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_24_25_ARS_OD_VabsY_Obj_25
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_24_25_ARS_OD_VabsY_Obj_25
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_24_25_ARS_OD_VabsY_Obj_25
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_24_25_ARS_OD_AabsY_Obj_25
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_24_25_ARS_OD_AabsY_Obj_25
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_24_25_ARS_OD_AabsY_Obj_25
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_24_25_ARS_OD_DistXStd_Obj_25
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_24_25_ARS_OD_DistXStd_Obj_25
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_24_25_ARS_OD_DistXStd_Obj_25
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_24_25_ARS_OD_DistYStd_Obj_25
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_24_25_ARS_OD_DistYStd_Obj_25
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_24_25_ARS_OD_DistYStd_Obj_25
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_24_25_ARS_OD_VabsXStd_Obj_25
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_24_25_ARS_OD_VabsXStd_Obj_25
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_24_25_ARS_OD_VabsXStd_Obj_25
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_24_25_ARS_OD_VabsYStd_Obj_25
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_24_25_ARS_OD_VabsYStd_Obj_25
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_24_25_ARS_OD_VabsYStd_Obj_25
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_24_25_ARS_OD_AabsXStd_Obj_25
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_24_25_ARS_OD_AabsXStd_Obj_25
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_24_25_ARS_OD_AabsXStd_Obj_25
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_24_25_ARS_OD_Classification_Obj_25
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_24_25_ARS_OD_Classification_Obj_25
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_24_25_ARS_OD_Classification_Obj_25
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_24_25_ARS_OD_AabsYStd_Obj_25
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_24_25_ARS_OD_AabsYStd_Obj_25
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_24_25_ARS_OD_AabsYStd_Obj_25
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_24_25_ARS_OD_ClassConf_Obj_25
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_24_25_ARS_OD_ClassConf_Obj_25
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_24_25_ARS_OD_ClassConf_Obj_25
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_24_25_ARS_OD_DistY_Obj_24
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_24_25_ARS_OD_DistY_Obj_24
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_24_25_ARS_OD_DistY_Obj_24
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_24_25_ARS_OD_ProbOfExist_Obj_25
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_24_25_ARS_OD_ProbOfExist_Obj_25
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_24_25_ARS_OD_ProbOfExist_Obj_25
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_24_25_ARS_OD_DynConf_Obj_25
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_24_25_ARS_OD_DynConf_Obj_25
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_24_25_ARS_OD_DynConf_Obj_25
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_24_25_ARS_OD_DynProp_Obj_25
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_24_25_ARS_OD_DynProp_Obj_25
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_24_25_ARS_OD_DynProp_Obj_25
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_24_25_ARS_OD_MirrorProb_Obj_25
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_24_25_ARS_OD_MirrorProb_Obj_25
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_24_25_ARS_OD_MirrorProb_Obj_25
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_24_25_ARS_OD_Length_Obj_25
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_24_25_ARS_OD_Length_Obj_25
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_24_25_ARS_OD_Length_Obj_25
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_24_25_ARS_OD_MaintenanceState_Obj_25
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_24_25_ARS_OD_MaintenanceState_Obj_25
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_24_25_ARS_OD_MaintenanceState_Obj_25
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_24_25_ARS_OD_Width_Obj_25
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_24_25_ARS_OD_Width_Obj_25
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_24_25_ARS_OD_Width_Obj_25
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_24_25_ARS_OD_RCS_Obj_25
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_24_25_ARS_OD_RCS_Obj_25
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_24_25_ARS_OD_RCS_Obj_25
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_24_25_ARS_OD_Orientation_Obj_25
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_24_25_ARS_OD_Orientation_Obj_25
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_24_25_ARS_OD_Orientation_Obj_25
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_24_25_ARS_OD_YawRateAbs_Obj_25
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_24_25_ARS_OD_YawRateAbs_Obj_25
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_24_25_ARS_OD_YawRateAbs_Obj_25
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_24_25_ARS_OD_YawRateAbsStd_Obj_25
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_24_25_ARS_OD_YawRateAbsStd_Obj_25
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_24_25_ARS_OD_YawRateAbsStd_Obj_25
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_24_25_ARS_OD_RefPoint_Obj_25
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_24_25_ARS_OD_RefPoint_Obj_25
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_24_25_ARS_OD_RefPoint_Obj_25
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_24_25_ARS_OD_LifeCycle_Obj_25
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_24_25_ARS_OD_LifeCycle_Obj_25
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_24_25_ARS_OD_LifeCycle_Obj_25
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_24_25_ARS_OD_OrientationStd_Obj_24
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_24_25_ARS_OD_OrientationStd_Obj_24
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_24_25_ARS_OD_OrientationStd_Obj_24
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_24_25_ARS_OD_OrientationStd_Obj_25
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_24_25_ARS_OD_OrientationStd_Obj_25
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_24_25_ARS_OD_OrientationStd_Obj_25
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_24_25_ARS_OD_ObstacleProb_Obj_24
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_24_25_ARS_OD_ObstacleProb_Obj_24
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_24_25_ARS_OD_ObstacleProb_Obj_24
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_24_25_ARS_OD_MicroDopplerFlag_24
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_24_25_ARS_OD_MicroDopplerFlag_24
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_24_25_ARS_OD_MicroDopplerFlag_24
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_24_25_ARS_OD_ObstacleProb_Obj_25
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_24_25_ARS_OD_ObstacleProb_Obj_25
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_24_25_ARS_OD_ObstacleProb_Obj_25
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_24_25_ARS_OD_VabsY_Obj_24
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_24_25_ARS_OD_VabsY_Obj_24
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_24_25_ARS_OD_VabsY_Obj_24
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_24_25_ARS_OD_MicroDopplerFlag_25
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_24_25_ARS_OD_MicroDopplerFlag_25
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_24_25_ARS_OD_MicroDopplerFlag_25
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_24_25_ARS_OD_ID_24
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_24_25_ARS_OD_ID_24
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_24_25_ARS_OD_ID_24
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_24_25_ARS_OD_ID_25
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_24_25_ARS_OD_ID_25
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_24_25_ARS_OD_ID_25
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_24_25_ARS_OD_MsgCounter_Obj_24_25
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_24_25_ARS_OD_MsgCounter_Obj_24_25
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_24_25_ARS_OD_MsgCounter_Obj_24_25
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_24_25_ARS_OD_CRC16_Checksum_Obj_24_25
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_24_25_ARS_OD_CRC16_Checksum_Obj_24_25
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_24_25_ARS_OD_CRC16_Checksum_Obj_24_25
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_24_25_ARS_OD_AabsY_Obj_24
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_24_25_ARS_OD_AabsY_Obj_24
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_24_25_ARS_OD_AabsY_Obj_24
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_24_25_ARS_OD_DistXStd_Obj_24
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_24_25_ARS_OD_DistXStd_Obj_24
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_24_25_ARS_OD_DistXStd_Obj_24
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_24_25_ARS_OD_DistYStd_Obj_24
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_24_25_ARS_OD_DistYStd_Obj_24
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_24_25_ARS_OD_DistYStd_Obj_24
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_24_25_ARS_OD_VabsXStd_Obj_24
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_24_25_ARS_OD_VabsXStd_Obj_24
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_24_25_ARS_OD_VabsXStd_Obj_24
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_24_25_ARS_OD_VabsYStd_Obj_24
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_24_25_ARS_OD_VabsYStd_Obj_24
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_24_25_ARS_OD_VabsYStd_Obj_24
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_24_25_ARS_OD_AabsXStd_Obj_24
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_24_25_ARS_OD_AabsXStd_Obj_24
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_24_25_ARS_OD_AabsXStd_Obj_24
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_26_27_DistHeight_Obj_27
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_26_27_DistHeight_Obj_27
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_26_27_DistHeight_Obj_27
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_26_27_DistHeight_Obj_26
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_26_27_DistHeight_Obj_26
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_26_27_DistHeight_Obj_26
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_26_27_ARS_OD_DistX_Obj_26
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_26_27_ARS_OD_DistX_Obj_26
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_26_27_ARS_OD_DistX_Obj_26
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_26_27_ARS_OD_Classification_Obj_26
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_26_27_ARS_OD_Classification_Obj_26
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_26_27_ARS_OD_Classification_Obj_26
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_26_27_ARS_OD_AabsYStd_Obj_26
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_26_27_ARS_OD_AabsYStd_Obj_26
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_26_27_ARS_OD_AabsYStd_Obj_26
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_26_27_ARS_OD_ClassConf_Obj_26
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_26_27_ARS_OD_ClassConf_Obj_26
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_26_27_ARS_OD_ClassConf_Obj_26
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_26_27_ARS_OD_ProbOfExist_Obj_26
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_26_27_ARS_OD_ProbOfExist_Obj_26
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_26_27_ARS_OD_ProbOfExist_Obj_26
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_26_27_ARS_OD_DynConf_Obj_26
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_26_27_ARS_OD_DynConf_Obj_26
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_26_27_ARS_OD_DynConf_Obj_26
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_26_27_ARS_OD_VabsX_Obj_26
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_26_27_ARS_OD_VabsX_Obj_26
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_26_27_ARS_OD_VabsX_Obj_26
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_26_27_ARS_OD_DynProp_Obj_26
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_26_27_ARS_OD_DynProp_Obj_26
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_26_27_ARS_OD_DynProp_Obj_26
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_26_27_ARS_OD_MirrorProb_Obj_26
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_26_27_ARS_OD_MirrorProb_Obj_26
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_26_27_ARS_OD_MirrorProb_Obj_26
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_26_27_ARS_OD_Length_Obj_26
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_26_27_ARS_OD_Length_Obj_26
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_26_27_ARS_OD_Length_Obj_26
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_26_27_ARS_OD_MaintenanceState_Obj_26
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_26_27_ARS_OD_MaintenanceState_Obj_26
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_26_27_ARS_OD_MaintenanceState_Obj_26
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_26_27_ARS_OD_Width_Obj_26
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_26_27_ARS_OD_Width_Obj_26
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_26_27_ARS_OD_Width_Obj_26
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_26_27_ARS_OD_RCS_Obj_26
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_26_27_ARS_OD_RCS_Obj_26
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_26_27_ARS_OD_RCS_Obj_26
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_26_27_ARS_OD_Orientation_Obj_26
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_26_27_ARS_OD_Orientation_Obj_26
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_26_27_ARS_OD_Orientation_Obj_26
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_26_27_ARS_OD_YawRateAbs_Obj_26
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_26_27_ARS_OD_YawRateAbs_Obj_26
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_26_27_ARS_OD_YawRateAbs_Obj_26
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_26_27_ARS_OD_YawRateAbsStd_Obj_26
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_26_27_ARS_OD_YawRateAbsStd_Obj_26
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_26_27_ARS_OD_YawRateAbsStd_Obj_26
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_26_27_ARS_OD_RefPoint_Obj_26
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_26_27_ARS_OD_RefPoint_Obj_26
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_26_27_ARS_OD_RefPoint_Obj_26
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_26_27_ARS_OD_LifeCycle_Obj_26
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_26_27_ARS_OD_LifeCycle_Obj_26
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_26_27_ARS_OD_LifeCycle_Obj_26
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_26_27_ARS_OD_DistX_Obj_27
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_26_27_ARS_OD_DistX_Obj_27
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_26_27_ARS_OD_DistX_Obj_27
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_26_27_ARS_OD_VabsX_Obj_27
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_26_27_ARS_OD_VabsX_Obj_27
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_26_27_ARS_OD_VabsX_Obj_27
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_26_27_ARS_OD_AabsX_Obj_27
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_26_27_ARS_OD_AabsX_Obj_27
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_26_27_ARS_OD_AabsX_Obj_27
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_26_27_ARS_OD_AabsX_Obj_26
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_26_27_ARS_OD_AabsX_Obj_26
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_26_27_ARS_OD_AabsX_Obj_26
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_26_27_ARS_OD_DistY_Obj_27
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_26_27_ARS_OD_DistY_Obj_27
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_26_27_ARS_OD_DistY_Obj_27
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_26_27_ARS_OD_VabsY_Obj_27
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_26_27_ARS_OD_VabsY_Obj_27
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_26_27_ARS_OD_VabsY_Obj_27
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_26_27_ARS_OD_AabsY_Obj_27
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_26_27_ARS_OD_AabsY_Obj_27
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_26_27_ARS_OD_AabsY_Obj_27
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_26_27_ARS_OD_DistXStd_Obj_27
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_26_27_ARS_OD_DistXStd_Obj_27
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_26_27_ARS_OD_DistXStd_Obj_27
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_26_27_ARS_OD_DistYStd_Obj_27
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_26_27_ARS_OD_DistYStd_Obj_27
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_26_27_ARS_OD_DistYStd_Obj_27
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_26_27_ARS_OD_VabsXStd_Obj_27
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_26_27_ARS_OD_VabsXStd_Obj_27
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_26_27_ARS_OD_VabsXStd_Obj_27
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_26_27_ARS_OD_VabsYStd_Obj_27
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_26_27_ARS_OD_VabsYStd_Obj_27
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_26_27_ARS_OD_VabsYStd_Obj_27
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_26_27_ARS_OD_AabsXStd_Obj_27
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_26_27_ARS_OD_AabsXStd_Obj_27
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_26_27_ARS_OD_AabsXStd_Obj_27
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_26_27_ARS_OD_Classification_Obj_27
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_26_27_ARS_OD_Classification_Obj_27
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_26_27_ARS_OD_Classification_Obj_27
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_26_27_ARS_OD_AabsYStd_Obj_27
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_26_27_ARS_OD_AabsYStd_Obj_27
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_26_27_ARS_OD_AabsYStd_Obj_27
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_26_27_ARS_OD_ClassConf_Obj_27
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_26_27_ARS_OD_ClassConf_Obj_27
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_26_27_ARS_OD_ClassConf_Obj_27
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_26_27_ARS_OD_DistY_Obj_26
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_26_27_ARS_OD_DistY_Obj_26
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_26_27_ARS_OD_DistY_Obj_26
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_26_27_ARS_OD_ProbOfExist_Obj_27
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_26_27_ARS_OD_ProbOfExist_Obj_27
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_26_27_ARS_OD_ProbOfExist_Obj_27
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_26_27_ARS_OD_DynConf_Obj_27
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_26_27_ARS_OD_DynConf_Obj_27
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_26_27_ARS_OD_DynConf_Obj_27
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_26_27_ARS_OD_DynProp_Obj_27
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_26_27_ARS_OD_DynProp_Obj_27
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_26_27_ARS_OD_DynProp_Obj_27
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_26_27_ARS_OD_MirrorProb_Obj_27
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_26_27_ARS_OD_MirrorProb_Obj_27
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_26_27_ARS_OD_MirrorProb_Obj_27
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_26_27_ARS_OD_Length_Obj_27
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_26_27_ARS_OD_Length_Obj_27
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_26_27_ARS_OD_Length_Obj_27
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_26_27_ARS_OD_MaintenanceState_Obj_27
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_26_27_ARS_OD_MaintenanceState_Obj_27
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_26_27_ARS_OD_MaintenanceState_Obj_27
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_26_27_ARS_OD_Width_Obj_27
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_26_27_ARS_OD_Width_Obj_27
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_26_27_ARS_OD_Width_Obj_27
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_26_27_ARS_OD_RCS_Obj_27
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_26_27_ARS_OD_RCS_Obj_27
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_26_27_ARS_OD_RCS_Obj_27
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_26_27_ARS_OD_Orientation_Obj_27
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_26_27_ARS_OD_Orientation_Obj_27
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_26_27_ARS_OD_Orientation_Obj_27
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_26_27_ARS_OD_YawRateAbs_Obj_27
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_26_27_ARS_OD_YawRateAbs_Obj_27
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_26_27_ARS_OD_YawRateAbs_Obj_27
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_26_27_ARS_OD_YawRateAbsStd_Obj_27
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_26_27_ARS_OD_YawRateAbsStd_Obj_27
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_26_27_ARS_OD_YawRateAbsStd_Obj_27
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_26_27_ARS_OD_RefPoint_Obj_27
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_26_27_ARS_OD_RefPoint_Obj_27
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_26_27_ARS_OD_RefPoint_Obj_27
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_26_27_ARS_OD_LifeCycle_Obj_27
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_26_27_ARS_OD_LifeCycle_Obj_27
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_26_27_ARS_OD_LifeCycle_Obj_27
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_26_27_ARS_OD_OrientationStd_Obj_26
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_26_27_ARS_OD_OrientationStd_Obj_26
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_26_27_ARS_OD_OrientationStd_Obj_26
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_26_27_ARS_OD_OrientationStd_Obj_27
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_26_27_ARS_OD_OrientationStd_Obj_27
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_26_27_ARS_OD_OrientationStd_Obj_27
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_26_27_ARS_OD_ObstacleProb_Obj_26
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_26_27_ARS_OD_ObstacleProb_Obj_26
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_26_27_ARS_OD_ObstacleProb_Obj_26
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_26_27_ARS_OD_MicroDopplerFlag_26
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_26_27_ARS_OD_MicroDopplerFlag_26
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_26_27_ARS_OD_MicroDopplerFlag_26
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_26_27_ARS_OD_ObstacleProb_Obj_27
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_26_27_ARS_OD_ObstacleProb_Obj_27
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_26_27_ARS_OD_ObstacleProb_Obj_27
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_26_27_ARS_OD_VabsY_Obj_26
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_26_27_ARS_OD_VabsY_Obj_26
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_26_27_ARS_OD_VabsY_Obj_26
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_26_27_ARS_OD_MicroDopplerFlag_27
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_26_27_ARS_OD_MicroDopplerFlag_27
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_26_27_ARS_OD_MicroDopplerFlag_27
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_26_27_ARS_OD_ID_26
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_26_27_ARS_OD_ID_26
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_26_27_ARS_OD_ID_26
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_26_27_ARS_OD_ID_27
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_26_27_ARS_OD_ID_27
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_26_27_ARS_OD_ID_27
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_26_27_ARS_OD_MsgCounter_Obj_26_27
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_26_27_ARS_OD_MsgCounter_Obj_26_27
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_26_27_ARS_OD_MsgCounter_Obj_26_27
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_26_27_ARS_OD_CRC16_Checksum_Obj_26_27
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_26_27_ARS_OD_CRC16_Checksum_Obj_26_27
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_26_27_ARS_OD_CRC16_Checksum_Obj_26_27
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_26_27_ARS_OD_AabsY_Obj_26
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_26_27_ARS_OD_AabsY_Obj_26
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_26_27_ARS_OD_AabsY_Obj_26
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_26_27_ARS_OD_DistXStd_Obj_26
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_26_27_ARS_OD_DistXStd_Obj_26
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_26_27_ARS_OD_DistXStd_Obj_26
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_26_27_ARS_OD_DistYStd_Obj_26
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_26_27_ARS_OD_DistYStd_Obj_26
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_26_27_ARS_OD_DistYStd_Obj_26
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_26_27_ARS_OD_VabsXStd_Obj_26
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_26_27_ARS_OD_VabsXStd_Obj_26
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_26_27_ARS_OD_VabsXStd_Obj_26
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_26_27_ARS_OD_VabsYStd_Obj_26
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_26_27_ARS_OD_VabsYStd_Obj_26
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_26_27_ARS_OD_VabsYStd_Obj_26
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_26_27_ARS_OD_AabsXStd_Obj_26
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_26_27_ARS_OD_AabsXStd_Obj_26
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_26_27_ARS_OD_AabsXStd_Obj_26
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_28_29_DistHeight_Obj_29
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_28_29_DistHeight_Obj_29
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_28_29_DistHeight_Obj_29
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_28_29_DistHeight_Obj_28
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_28_29_DistHeight_Obj_28
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_28_29_DistHeight_Obj_28
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_28_29_ARS_OD_DistX_Obj_28
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_28_29_ARS_OD_DistX_Obj_28
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_28_29_ARS_OD_DistX_Obj_28
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_28_29_ARS_OD_Classification_Obj_28
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_28_29_ARS_OD_Classification_Obj_28
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_28_29_ARS_OD_Classification_Obj_28
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_28_29_ARS_OD_AabsYStd_Obj_28
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_28_29_ARS_OD_AabsYStd_Obj_28
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_28_29_ARS_OD_AabsYStd_Obj_28
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_28_29_ARS_OD_ClassConf_Obj_28
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_28_29_ARS_OD_ClassConf_Obj_28
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_28_29_ARS_OD_ClassConf_Obj_28
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_28_29_ARS_OD_ProbOfExist_Obj_28
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_28_29_ARS_OD_ProbOfExist_Obj_28
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_28_29_ARS_OD_ProbOfExist_Obj_28
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_28_29_ARS_OD_DynConf_Obj_28
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_28_29_ARS_OD_DynConf_Obj_28
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_28_29_ARS_OD_DynConf_Obj_28
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_28_29_ARS_OD_VabsX_Obj_28
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_28_29_ARS_OD_VabsX_Obj_28
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_28_29_ARS_OD_VabsX_Obj_28
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_28_29_ARS_OD_DynProp_Obj_28
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_28_29_ARS_OD_DynProp_Obj_28
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_28_29_ARS_OD_DynProp_Obj_28
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_28_29_ARS_OD_MirrorProb_Obj_28
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_28_29_ARS_OD_MirrorProb_Obj_28
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_28_29_ARS_OD_MirrorProb_Obj_28
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_28_29_ARS_OD_Length_Obj_28
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_28_29_ARS_OD_Length_Obj_28
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_28_29_ARS_OD_Length_Obj_28
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_28_29_ARS_OD_MaintenanceState_Obj_28
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_28_29_ARS_OD_MaintenanceState_Obj_28
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_28_29_ARS_OD_MaintenanceState_Obj_28
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_28_29_ARS_OD_Width_Obj_28
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_28_29_ARS_OD_Width_Obj_28
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_28_29_ARS_OD_Width_Obj_28
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_28_29_ARS_OD_RCS_Obj_28
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_28_29_ARS_OD_RCS_Obj_28
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_28_29_ARS_OD_RCS_Obj_28
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_28_29_ARS_OD_Orientation_Obj_28
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_28_29_ARS_OD_Orientation_Obj_28
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_28_29_ARS_OD_Orientation_Obj_28
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_28_29_ARS_OD_YawRateAbs_Obj_28
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_28_29_ARS_OD_YawRateAbs_Obj_28
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_28_29_ARS_OD_YawRateAbs_Obj_28
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_28_29_ARS_OD_YawRateAbsStd_Obj_28
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_28_29_ARS_OD_YawRateAbsStd_Obj_28
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_28_29_ARS_OD_YawRateAbsStd_Obj_28
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_28_29_ARS_OD_RefPoint_Obj_28
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_28_29_ARS_OD_RefPoint_Obj_28
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_28_29_ARS_OD_RefPoint_Obj_28
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_28_29_ARS_OD_LifeCycle_Obj_28
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_28_29_ARS_OD_LifeCycle_Obj_28
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_28_29_ARS_OD_LifeCycle_Obj_28
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_28_29_ARS_OD_DistX_Obj_29
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_28_29_ARS_OD_DistX_Obj_29
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_28_29_ARS_OD_DistX_Obj_29
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_28_29_ARS_OD_VabsX_Obj_29
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_28_29_ARS_OD_VabsX_Obj_29
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_28_29_ARS_OD_VabsX_Obj_29
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_28_29_ARS_OD_AabsX_Obj_29
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_28_29_ARS_OD_AabsX_Obj_29
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_28_29_ARS_OD_AabsX_Obj_29
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_28_29_ARS_OD_AabsX_Obj_28
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_28_29_ARS_OD_AabsX_Obj_28
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_28_29_ARS_OD_AabsX_Obj_28
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_28_29_ARS_OD_DistY_Obj_29
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_28_29_ARS_OD_DistY_Obj_29
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_28_29_ARS_OD_DistY_Obj_29
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_28_29_ARS_OD_VabsY_Obj_29
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_28_29_ARS_OD_VabsY_Obj_29
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_28_29_ARS_OD_VabsY_Obj_29
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_28_29_ARS_OD_AabsY_Obj_29
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_28_29_ARS_OD_AabsY_Obj_29
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_28_29_ARS_OD_AabsY_Obj_29
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_28_29_ARS_OD_DistXStd_Obj_29
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_28_29_ARS_OD_DistXStd_Obj_29
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_28_29_ARS_OD_DistXStd_Obj_29
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_28_29_ARS_OD_DistYStd_Obj_29
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_28_29_ARS_OD_DistYStd_Obj_29
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_28_29_ARS_OD_DistYStd_Obj_29
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_28_29_ARS_OD_VabsXStd_Obj_29
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_28_29_ARS_OD_VabsXStd_Obj_29
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_28_29_ARS_OD_VabsXStd_Obj_29
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_28_29_ARS_OD_VabsYStd_Obj_29
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_28_29_ARS_OD_VabsYStd_Obj_29
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_28_29_ARS_OD_VabsYStd_Obj_29
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_28_29_ARS_OD_AabsXStd_Obj_29
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_28_29_ARS_OD_AabsXStd_Obj_29
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_28_29_ARS_OD_AabsXStd_Obj_29
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_28_29_ARS_OD_Classification_Obj_29
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_28_29_ARS_OD_Classification_Obj_29
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_28_29_ARS_OD_Classification_Obj_29
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_28_29_ARS_OD_AabsYStd_Obj_29
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_28_29_ARS_OD_AabsYStd_Obj_29
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_28_29_ARS_OD_AabsYStd_Obj_29
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_28_29_ARS_OD_ClassConf_Obj_29
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_28_29_ARS_OD_ClassConf_Obj_29
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_28_29_ARS_OD_ClassConf_Obj_29
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_28_29_ARS_OD_DistY_Obj_28
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_28_29_ARS_OD_DistY_Obj_28
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_28_29_ARS_OD_DistY_Obj_28
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_28_29_ARS_OD_ProbOfExist_Obj_29
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_28_29_ARS_OD_ProbOfExist_Obj_29
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_28_29_ARS_OD_ProbOfExist_Obj_29
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_28_29_ARS_OD_DynConf_Obj_29
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_28_29_ARS_OD_DynConf_Obj_29
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_28_29_ARS_OD_DynConf_Obj_29
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_28_29_ARS_OD_DynProp_Obj_29
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_28_29_ARS_OD_DynProp_Obj_29
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_28_29_ARS_OD_DynProp_Obj_29
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_28_29_ARS_OD_MirrorProb_Obj_29
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_28_29_ARS_OD_MirrorProb_Obj_29
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_28_29_ARS_OD_MirrorProb_Obj_29
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_28_29_ARS_OD_Length_Obj_29
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_28_29_ARS_OD_Length_Obj_29
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_28_29_ARS_OD_Length_Obj_29
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_28_29_ARS_OD_MaintenanceState_Obj_29
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_28_29_ARS_OD_MaintenanceState_Obj_29
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_28_29_ARS_OD_MaintenanceState_Obj_29
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_28_29_ARS_OD_Width_Obj_29
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_28_29_ARS_OD_Width_Obj_29
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_28_29_ARS_OD_Width_Obj_29
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_28_29_ARS_OD_RCS_Obj_29
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_28_29_ARS_OD_RCS_Obj_29
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_28_29_ARS_OD_RCS_Obj_29
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_28_29_ARS_OD_Orientation_Obj_29
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_28_29_ARS_OD_Orientation_Obj_29
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_28_29_ARS_OD_Orientation_Obj_29
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_28_29_ARS_OD_YawRateAbs_Obj_29
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_28_29_ARS_OD_YawRateAbs_Obj_29
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_28_29_ARS_OD_YawRateAbs_Obj_29
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_28_29_ARS_OD_YawRateAbsStd_Obj_29
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_28_29_ARS_OD_YawRateAbsStd_Obj_29
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_28_29_ARS_OD_YawRateAbsStd_Obj_29
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_28_29_ARS_OD_RefPoint_Obj_29
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_28_29_ARS_OD_RefPoint_Obj_29
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_28_29_ARS_OD_RefPoint_Obj_29
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_28_29_ARS_OD_LifeCycle_Obj_29
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_28_29_ARS_OD_LifeCycle_Obj_29
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_28_29_ARS_OD_LifeCycle_Obj_29
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_28_29_ARS_OD_OrientationStd_Obj_28
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_28_29_ARS_OD_OrientationStd_Obj_28
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_28_29_ARS_OD_OrientationStd_Obj_28
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_28_29_ARS_OD_OrientationStd_Obj_29
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_28_29_ARS_OD_OrientationStd_Obj_29
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_28_29_ARS_OD_OrientationStd_Obj_29
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_28_29_ARS_OD_ObstacleProb_Obj_28
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_28_29_ARS_OD_ObstacleProb_Obj_28
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_28_29_ARS_OD_ObstacleProb_Obj_28
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_28_29_ARS_OD_MicroDopplerFlag_28
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_28_29_ARS_OD_MicroDopplerFlag_28
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_28_29_ARS_OD_MicroDopplerFlag_28
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_28_29_ARS_OD_ObstacleProb_Obj_29
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_28_29_ARS_OD_ObstacleProb_Obj_29
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_28_29_ARS_OD_ObstacleProb_Obj_29
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_28_29_ARS_OD_VabsY_Obj_28
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_28_29_ARS_OD_VabsY_Obj_28
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_28_29_ARS_OD_VabsY_Obj_28
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_28_29_ARS_OD_MicroDopplerFlag_29
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_28_29_ARS_OD_MicroDopplerFlag_29
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_28_29_ARS_OD_MicroDopplerFlag_29
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_28_29_ARS_OD_ID_28
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_28_29_ARS_OD_ID_28
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_28_29_ARS_OD_ID_28
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_28_29_ARS_OD_ID_29
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_28_29_ARS_OD_ID_29
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_28_29_ARS_OD_ID_29
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_28_29_ARS_OD_MsgCounter_Obj_28_29
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_28_29_ARS_OD_MsgCounter_Obj_28_29
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_28_29_ARS_OD_MsgCounter_Obj_28_29
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_28_29_ARS_OD_CRC16_Checksum_Obj_28_29
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_28_29_ARS_OD_CRC16_Checksum_Obj_28_29
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_28_29_ARS_OD_CRC16_Checksum_Obj_28_29
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_28_29_ARS_OD_AabsY_Obj_28
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_28_29_ARS_OD_AabsY_Obj_28
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_28_29_ARS_OD_AabsY_Obj_28
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_28_29_ARS_OD_DistXStd_Obj_28
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_28_29_ARS_OD_DistXStd_Obj_28
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_28_29_ARS_OD_DistXStd_Obj_28
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_28_29_ARS_OD_DistYStd_Obj_28
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_28_29_ARS_OD_DistYStd_Obj_28
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_28_29_ARS_OD_DistYStd_Obj_28
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_28_29_ARS_OD_VabsXStd_Obj_28
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_28_29_ARS_OD_VabsXStd_Obj_28
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_28_29_ARS_OD_VabsXStd_Obj_28
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_28_29_ARS_OD_VabsYStd_Obj_28
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_28_29_ARS_OD_VabsYStd_Obj_28
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_28_29_ARS_OD_VabsYStd_Obj_28
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_28_29_ARS_OD_AabsXStd_Obj_28
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_28_29_ARS_OD_AabsXStd_Obj_28
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_28_29_ARS_OD_AabsXStd_Obj_28
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_30_31_DistHeight_Obj_31
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_30_31_DistHeight_Obj_31
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_30_31_DistHeight_Obj_31
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_30_31_DistHeight_Obj_30
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_30_31_DistHeight_Obj_30
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_30_31_DistHeight_Obj_30
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_30_31_ARS_OD_DistX_Obj_30
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_30_31_ARS_OD_DistX_Obj_30
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_30_31_ARS_OD_DistX_Obj_30
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_30_31_ARS_OD_Classification_Obj_30
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_30_31_ARS_OD_Classification_Obj_30
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_30_31_ARS_OD_Classification_Obj_30
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_30_31_ARS_OD_AabsYStd_Obj_30
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_30_31_ARS_OD_AabsYStd_Obj_30
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_30_31_ARS_OD_AabsYStd_Obj_30
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_30_31_ARS_OD_ClassConf_Obj_30
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_30_31_ARS_OD_ClassConf_Obj_30
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_30_31_ARS_OD_ClassConf_Obj_30
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_30_31_ARS_OD_ProbOfExist_Obj_30
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_30_31_ARS_OD_ProbOfExist_Obj_30
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_30_31_ARS_OD_ProbOfExist_Obj_30
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_30_31_ARS_OD_DynConf_Obj_30
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_30_31_ARS_OD_DynConf_Obj_30
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_30_31_ARS_OD_DynConf_Obj_30
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_30_31_ARS_OD_VabsX_Obj_30
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_30_31_ARS_OD_VabsX_Obj_30
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_30_31_ARS_OD_VabsX_Obj_30
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_30_31_ARS_OD_DynProp_Obj_30
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_30_31_ARS_OD_DynProp_Obj_30
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_30_31_ARS_OD_DynProp_Obj_30
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_30_31_ARS_OD_MirrorProb_Obj_30
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_30_31_ARS_OD_MirrorProb_Obj_30
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_30_31_ARS_OD_MirrorProb_Obj_30
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_30_31_ARS_OD_Length_Obj_30
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_30_31_ARS_OD_Length_Obj_30
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_30_31_ARS_OD_Length_Obj_30
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_30_31_ARS_OD_MaintenanceState_Obj_30
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_30_31_ARS_OD_MaintenanceState_Obj_30
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_30_31_ARS_OD_MaintenanceState_Obj_30
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_30_31_ARS_OD_Width_Obj_30
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_30_31_ARS_OD_Width_Obj_30
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_30_31_ARS_OD_Width_Obj_30
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_30_31_ARS_OD_RCS_Obj_30
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_30_31_ARS_OD_RCS_Obj_30
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_30_31_ARS_OD_RCS_Obj_30
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_30_31_ARS_OD_Orientation_Obj_30
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_30_31_ARS_OD_Orientation_Obj_30
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_30_31_ARS_OD_Orientation_Obj_30
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_30_31_ARS_OD_YawRateAbs_Obj_30
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_30_31_ARS_OD_YawRateAbs_Obj_30
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_30_31_ARS_OD_YawRateAbs_Obj_30
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_30_31_ARS_OD_YawRateAbsStd_Obj_30
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_30_31_ARS_OD_YawRateAbsStd_Obj_30
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_30_31_ARS_OD_YawRateAbsStd_Obj_30
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_30_31_ARS_OD_RefPoint_Obj_30
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_30_31_ARS_OD_RefPoint_Obj_30
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_30_31_ARS_OD_RefPoint_Obj_30
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_30_31_ARS_OD_LifeCycle_Obj_30
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_30_31_ARS_OD_LifeCycle_Obj_30
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_30_31_ARS_OD_LifeCycle_Obj_30
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_30_31_ARS_OD_DistX_Obj_31
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_30_31_ARS_OD_DistX_Obj_31
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_30_31_ARS_OD_DistX_Obj_31
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_30_31_ARS_OD_VabsX_Obj_31
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_30_31_ARS_OD_VabsX_Obj_31
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_30_31_ARS_OD_VabsX_Obj_31
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_30_31_ARS_OD_AabsX_Obj_31
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_30_31_ARS_OD_AabsX_Obj_31
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_30_31_ARS_OD_AabsX_Obj_31
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_30_31_ARS_OD_AabsX_Obj_30
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_30_31_ARS_OD_AabsX_Obj_30
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_30_31_ARS_OD_AabsX_Obj_30
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_30_31_ARS_OD_DistY_Obj_31
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_30_31_ARS_OD_DistY_Obj_31
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_30_31_ARS_OD_DistY_Obj_31
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_30_31_ARS_OD_VabsY_Obj_31
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_30_31_ARS_OD_VabsY_Obj_31
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_30_31_ARS_OD_VabsY_Obj_31
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_30_31_ARS_OD_AabsY_Obj_31
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_30_31_ARS_OD_AabsY_Obj_31
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_30_31_ARS_OD_AabsY_Obj_31
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_30_31_ARS_OD_DistXStd_Obj_31
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_30_31_ARS_OD_DistXStd_Obj_31
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_30_31_ARS_OD_DistXStd_Obj_31
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_30_31_ARS_OD_DistYStd_Obj_31
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_30_31_ARS_OD_DistYStd_Obj_31
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_30_31_ARS_OD_DistYStd_Obj_31
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_30_31_ARS_OD_VabsXStd_Obj_31
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_30_31_ARS_OD_VabsXStd_Obj_31
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_30_31_ARS_OD_VabsXStd_Obj_31
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_30_31_ARS_OD_VabsYStd_Obj_31
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_30_31_ARS_OD_VabsYStd_Obj_31
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_30_31_ARS_OD_VabsYStd_Obj_31
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_30_31_ARS_OD_AabsXStd_Obj_31
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_30_31_ARS_OD_AabsXStd_Obj_31
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_30_31_ARS_OD_AabsXStd_Obj_31
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_30_31_ARS_OD_Classification_Obj_31
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_30_31_ARS_OD_Classification_Obj_31
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_30_31_ARS_OD_Classification_Obj_31
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_30_31_ARS_OD_AabsYStd_Obj_31
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_30_31_ARS_OD_AabsYStd_Obj_31
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_30_31_ARS_OD_AabsYStd_Obj_31
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_30_31_ARS_OD_ClassConf_Obj_31
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_30_31_ARS_OD_ClassConf_Obj_31
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_30_31_ARS_OD_ClassConf_Obj_31
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_30_31_ARS_OD_DistY_Obj_30
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_30_31_ARS_OD_DistY_Obj_30
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_30_31_ARS_OD_DistY_Obj_30
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_30_31_ARS_OD_ProbOfExist_Obj_31
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_30_31_ARS_OD_ProbOfExist_Obj_31
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_30_31_ARS_OD_ProbOfExist_Obj_31
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_30_31_ARS_OD_DynConf_Obj_31
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_30_31_ARS_OD_DynConf_Obj_31
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_30_31_ARS_OD_DynConf_Obj_31
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_30_31_ARS_OD_DynProp_Obj_31
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_30_31_ARS_OD_DynProp_Obj_31
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_30_31_ARS_OD_DynProp_Obj_31
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_30_31_ARS_OD_MirrorProb_Obj_31
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_30_31_ARS_OD_MirrorProb_Obj_31
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_30_31_ARS_OD_MirrorProb_Obj_31
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_30_31_ARS_OD_Length_Obj_31
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_30_31_ARS_OD_Length_Obj_31
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_30_31_ARS_OD_Length_Obj_31
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_30_31_ARS_OD_MaintenanceState_Obj_31
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_30_31_ARS_OD_MaintenanceState_Obj_31
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_30_31_ARS_OD_MaintenanceState_Obj_31
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_30_31_ARS_OD_Width_Obj_31
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_30_31_ARS_OD_Width_Obj_31
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_30_31_ARS_OD_Width_Obj_31
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_30_31_ARS_OD_RCS_Obj_31
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_30_31_ARS_OD_RCS_Obj_31
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_30_31_ARS_OD_RCS_Obj_31
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_30_31_ARS_OD_Orientation_Obj_31
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_30_31_ARS_OD_Orientation_Obj_31
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_30_31_ARS_OD_Orientation_Obj_31
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_30_31_ARS_OD_YawRateAbs_Obj_31
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_30_31_ARS_OD_YawRateAbs_Obj_31
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_30_31_ARS_OD_YawRateAbs_Obj_31
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_30_31_ARS_OD_YawRateAbsStd_Obj_31
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_30_31_ARS_OD_YawRateAbsStd_Obj_31
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_30_31_ARS_OD_YawRateAbsStd_Obj_31
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_30_31_ARS_OD_RefPoint_Obj_31
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_30_31_ARS_OD_RefPoint_Obj_31
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_30_31_ARS_OD_RefPoint_Obj_31
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_30_31_ARS_OD_LifeCycle_Obj_31
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_30_31_ARS_OD_LifeCycle_Obj_31
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_30_31_ARS_OD_LifeCycle_Obj_31
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_30_31_ARS_OD_OrientationStd_Obj_30
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_30_31_ARS_OD_OrientationStd_Obj_30
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_30_31_ARS_OD_OrientationStd_Obj_30
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_30_31_ARS_OD_OrientationStd_Obj_31
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_30_31_ARS_OD_OrientationStd_Obj_31
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_30_31_ARS_OD_OrientationStd_Obj_31
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_30_31_ARS_OD_ObstacleProb_Obj_30
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_30_31_ARS_OD_ObstacleProb_Obj_30
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_30_31_ARS_OD_ObstacleProb_Obj_30
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_30_31_ARS_OD_MicroDopplerFlag_30
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_30_31_ARS_OD_MicroDopplerFlag_30
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_30_31_ARS_OD_MicroDopplerFlag_30
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_30_31_ARS_OD_ObstacleProb_Obj_31
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_30_31_ARS_OD_ObstacleProb_Obj_31
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_30_31_ARS_OD_ObstacleProb_Obj_31
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_30_31_ARS_OD_VabsY_Obj_30
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_30_31_ARS_OD_VabsY_Obj_30
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_30_31_ARS_OD_VabsY_Obj_30
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_30_31_ARS_OD_MicroDopplerFlag_31
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_30_31_ARS_OD_MicroDopplerFlag_31
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_30_31_ARS_OD_MicroDopplerFlag_31
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_30_31_ARS_OD_ID_30
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_30_31_ARS_OD_ID_30
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_30_31_ARS_OD_ID_30
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_30_31_ARS_OD_ID_31
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_30_31_ARS_OD_ID_31
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_30_31_ARS_OD_ID_31
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_30_31_ARS_OD_MsgCounter_Obj_30_31
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_30_31_ARS_OD_MsgCounter_Obj_30_31
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_30_31_ARS_OD_MsgCounter_Obj_30_31
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_30_31_ARS_OD_CRC16_Checksum_Obj_30_31
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_30_31_ARS_OD_CRC16_Checksum_Obj_30_31
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_30_31_ARS_OD_CRC16_Checksum_Obj_30_31
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_30_31_ARS_OD_AabsY_Obj_30
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_30_31_ARS_OD_AabsY_Obj_30
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_30_31_ARS_OD_AabsY_Obj_30
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_30_31_ARS_OD_DistXStd_Obj_30
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_30_31_ARS_OD_DistXStd_Obj_30
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_30_31_ARS_OD_DistXStd_Obj_30
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_30_31_ARS_OD_DistYStd_Obj_30
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_30_31_ARS_OD_DistYStd_Obj_30
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_30_31_ARS_OD_DistYStd_Obj_30
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_30_31_ARS_OD_VabsXStd_Obj_30
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_30_31_ARS_OD_VabsXStd_Obj_30
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_30_31_ARS_OD_VabsXStd_Obj_30
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_30_31_ARS_OD_VabsYStd_Obj_30
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_30_31_ARS_OD_VabsYStd_Obj_30
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_30_31_ARS_OD_VabsYStd_Obj_30
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_CanConfigSet_Rx_Radar_ARS_OD_30_31_ARS_OD_AabsXStd_Obj_30
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_CanConfigSet_Rx_Radar_ARS_OD_30_31_ARS_OD_AabsXStd_Obj_30
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_CopySig_CanConfigSet_Rx_Radar_ARS_OD_30_31_ARS_OD_AabsXStd_Obj_30
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) srcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) destPtr,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_Tcp_ReceiveSignal_1601
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_Tcp_ReceiveSignal_1601
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_Tcp_ReceiveSignal_1602
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_Tcp_ReceiveSignal_1602
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_Tcp_ReceiveSignal_1603
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_Tcp_ReceiveSignal_1603
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_Tcp_ReceiveSignal_1604
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_Tcp_ReceiveSignal_1604
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_Tcp_ReceiveSignal_1605
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_Tcp_ReceiveSignal_1605
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_Tcp_ReceiveSignal_1606
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_Tcp_ReceiveSignal_1606
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_Tcp_ReceiveSignal_1607
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_Tcp_ReceiveSignal_1607
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_WriteSig_Tcp_ReceiveSignal_1608
(
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);
extern FUNC(void, COM_CODE) Com_ReadSig_Tcp_ReceiveSignal_1608
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SigValue,
    P2VAR(void, AUTOMATIC, COM_VAR) buffer,
    PduLengthType Length
);

#define COM_STOP_SEC_CODE
#include "MemMap.h"


extern boolean CC_ACAN_ACU_ChimeTelltaleReq_E2E(PduIdType PduId, PduInfoType *PduInfoPtr);
extern boolean CC_ACAN_BCM_LIGHT_0x106_E2E(PduIdType PduId, PduInfoType *PduInfoPtr);
extern boolean CC_ACAN_BCM_SwitchSts_0x109_E2E(PduIdType PduId, PduInfoType *PduInfoPtr);
extern boolean CC_ACAN_ABS_FrontWheelSpeMCUKPH_E2E(PduIdType PduId, PduInfoType *PduInfoPtr);
extern boolean CC_ACAN_ABS_RearWheelSpeMCUKPH_E2E(PduIdType PduId, PduInfoType *PduInfoPtr);
extern boolean CC_ACAN_ABS_WheelSpeedRC_E2E(PduIdType PduId, PduInfoType *PduInfoPtr);
extern boolean CC_ACAN_ABS_Status_E2E(PduIdType PduId, PduInfoType *PduInfoPtr);
extern boolean CC_ACAN_ESC_Status_0x132_E2E(PduIdType PduId, PduInfoType *PduInfoPtr);
extern boolean CC_ACAN_VCU_Ctrl_E2E(PduIdType PduId, PduInfoType *PduInfoPtr);
extern boolean CC_ACAN_VCU_StsEpt_E2E(PduIdType PduId, PduInfoType *PduInfoPtr);
extern boolean CC_ACAN_SAS_Sensor_0x17E_E2E(PduIdType PduId, PduInfoType *PduInfoPtr);
extern boolean CC_ACAN_EPS_LKA_Sts_E2E(PduIdType PduId, PduInfoType *PduInfoPtr);
extern boolean CC_ACAN_BCM_PEPS_Sts_E2E(PduIdType PduId, PduInfoType *PduInfoPtr);
extern boolean CC_ACAN_ESC_EPB_0x230_E2E(PduIdType PduId, PduInfoType *PduInfoPtr);
extern boolean CC_ACAN_ESC_YawAngle_0x3E2_E2E(PduIdType PduId, PduInfoType *PduInfoPtr);
extern boolean CC_ACAN_IPC_TotalOdometer_E2E(PduIdType PduId, PduInfoType *PduInfoPtr);
extern boolean CC_ACAN_MFS_L_Control_Button2_0x3F7_E2E(PduIdType PduId, PduInfoType *PduInfoPtr);

//TX
extern boolean CC_ACAN_ADAS_01_E2E(PduIdType PduId, PduInfoType *PduInfoPtr);
extern boolean CC_ACAN_ADAS_02_E2E(PduIdType PduId, PduInfoType *PduInfoPtr);
extern boolean CC_ACAN_ADAS_03_E2E(PduIdType PduId, PduInfoType *PduInfoPtr);
extern boolean CC_ACAN_ADAS_Info23_E2E(PduIdType PduId, PduInfoType *PduInfoPtr);
#endif


