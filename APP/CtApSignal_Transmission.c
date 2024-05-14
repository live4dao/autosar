/*  BEGIN_FILE_HDR
********************************************************************************
*   File Name       : CtApSignal_Transmission.c
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
#include "Rte_CtApSignal_Transmission.h"

/* CtApSignal_TransmissionInput File User Code start*/

/* CtApSignal_TransmissionInput File User Code end*/

/* CtApSignal_Transmission.c Custom Code (#define variable etc.) User Code start*/

/* CtApSignal_Transmission.c Custom Code (#define variable etc.) User Code end*/

/*******************************************************************************
*   Runnable Extended
*******************************************************************************/

#define CtApSignal_Transmission_START_SEC_CODE
#include "CtApSignal_Transmission_MemMap.h"

FUNC(void, CtApSignal_Transmission_CODE) Signal_Transmission_init
(
    void
)
{
    /* Signal_Transmission_init_Start User Code start*/

    /* Signal_Transmission_init_Start User Code end*/
    /* Signal_Transmission_init Varaible Define User Code start*/

    /* Signal_Transmission_init Varaible Define User Code end*/




    /* Signal_Transmission_init_Feedback User Code start*/

    /* Signal_Transmission_init_Feedback User Code end*/

}
#define CtApSignal_Transmission_STOP_SEC_CODE
#include "CtApSignal_Transmission_MemMap.h"


#define CtApSignal_Transmission_START_SEC_CODE
#include "CtApSignal_Transmission_MemMap.h"

FUNC(void, CtApSignal_Transmission_CODE) TSK_Signal_Transmission_10ms
(
    void
)
{
    /* TSK_Signal_Transmission_10ms_Start User Code start*/

    /* TSK_Signal_Transmission_10ms_Start User Code end*/
    ADAS_APA_LightReq_IDT Write_ADAS_APA_LightReq_ADAS_APA_LightReq;
    ADAS_APA_SuggestedID_IDT Write_ADAS_APA_SuggestedID_ADAS_APA_SuggestedID;
    APA_ChimeRequest_IDT Write_APA_ChimeRequest_APA_ChimeRequest;
    APA_EPS_AngReqSts_IDT Write_APA_EPS_AngReqSts_APA_EPS_AngReqSts;
    APA_EPS_TargetSteeringAngle_IDT Write_APA_EPS_TargetSteeringAngle_APA_EPS_TargetSteeringAngle;
    APA_FRegion1ObjectSts_IDT Write_APA_FRegion1ObjectSts_APA_FRegion1ObjectSts;
    APA_FRegion2ObjectSts_IDT Write_APA_FRegion2ObjectSts_APA_FRegion2ObjectSts;
    APA_FRegion3ObjectSts_IDT Write_APA_FRegion3ObjectSts_APA_FRegion3ObjectSts;
    APA_FRegion4ObjectSts_IDT Write_APA_FRegion4ObjectSts_APA_FRegion4ObjectSts;
    APA_FrontExtenedDistance_IDT Write_APA_FrontExtenedDistance_APA_FrontExtenedDistance;
    APA_ParkAssistRExtenedDistance_IDT Write_APA_ParkAssistRExtenedDistance_APA_ParkAssistRExtenedDistance;
    APA_ParkAssistRRegion1ObjectSts_IDT Write_APA_ParkAssistRRegion1ObjectSts_APA_ParkAssistRRegion1ObjectSts;
    APA_ParkAssistRRegion2ObjectSts_IDT Write_APA_ParkAssistRRegion2ObjectSts_APA_ParkAssistRRegion2ObjectSts;
    APA_ParkAssistRRegion3ObjectSts_IDT Write_APA_ParkAssistRRegion3ObjectSts_APA_ParkAssistRRegion3ObjectSts;
    APA_ParkAssistRRegion4ObjectSts_IDT Write_APA_ParkAssistRRegion4ObjectSts_APA_ParkAssistRRegion4ObjectSts;
    APA_WCBS_BrakeMode_IDT Write_APA_WCBS_BrakeMode_APA_WCBS_BrakeMode;
    APA_WCBS_ExpectedGearPosition_IDT Write_APA_WCBS_ExpectedGearPosition_APA_WCBS_ExpectedGearPosition;
    APA_WCBS_SpeedLimitation_IDT Write_APA_WCBS_SpeedLimitation_APA_WCBS_SpeedLimitation;
    APA_WCBS_TargetStopDistance_IDT Write_APA_WCBS_TargetStopDistance_APA_WCBS_TargetStopDistance;
    APA_slot_10_IDT Write_APA_slot_10_APA_slot_10;
    APA_slot_11_IDT Write_APA_slot_11_APA_slot_11;
    APA_slot_12_IDT Write_APA_slot_12_APA_slot_12;
    APA_slot_1_IDT Write_APA_slot_1_APA_slot_1;
    APA_slot_2_IDT Write_APA_slot_2_APA_slot_2;
    APA_slot_3_IDT Write_APA_slot_3_APA_slot_3;
    APA_slot_4_IDT Write_APA_slot_4_APA_slot_4;
    APA_slot_5_IDT Write_APA_slot_5_APA_slot_5;
    APA_slot_6_IDT Write_APA_slot_6_APA_slot_6;
    APA_slot_7_IDT Write_APA_slot_7_APA_slot_7;
    APA_slot_8_IDT Write_APA_slot_8_APA_slot_8;
    APA_slot_9_IDT Write_APA_slot_9_APA_slot_9;
    APA_slot_ID_10_P0_X_IDT Write_APA_slot_ID_10_P0_X_APA_slot_ID_10_P0_X;
    APA_slot_ID_10_P0_Y_IDT Write_APA_slot_ID_10_P0_Y_APA_slot_ID_10_P0_Y;
    APA_slot_ID_10_P1_X_IDT Write_APA_slot_ID_10_P1_X_APA_slot_ID_10_P1_X;
    APA_slot_ID_10_P1_Y_IDT Write_APA_slot_ID_10_P1_Y_APA_slot_ID_10_P1_Y;
    APA_slot_ID_10_P2_X_IDT Write_APA_slot_ID_10_P2_X_APA_slot_ID_10_P2_X;
    APA_slot_ID_10_P2_Y_IDT Write_APA_slot_ID_10_P2_Y_APA_slot_ID_10_P2_Y;
    APA_slot_ID_10_P3_X_IDT Write_APA_slot_ID_10_P3_X_APA_slot_ID_10_P3_X;
    APA_slot_ID_10_P3_Y_IDT Write_APA_slot_ID_10_P3_Y_APA_slot_ID_10_P3_Y;
    APA_slot_ID_10_Type_IDT Write_APA_slot_ID_10_Type_APA_slot_ID_10_Type;
    APA_slot_ID_11_P0_X_IDT Write_APA_slot_ID_11_P0_X_APA_slot_ID_11_P0_X;
    APA_slot_ID_11_P0_Y_IDT Write_APA_slot_ID_11_P0_Y_APA_slot_ID_11_P0_Y;
    APA_slot_ID_11_P1_X_IDT Write_APA_slot_ID_11_P1_X_APA_slot_ID_11_P1_X;
    APA_slot_ID_11_P1_Y_IDT Write_APA_slot_ID_11_P1_Y_APA_slot_ID_11_P1_Y;
    APA_slot_ID_11_P2_X_IDT Write_APA_slot_ID_11_P2_X_APA_slot_ID_11_P2_X;
    APA_slot_ID_11_P2_Y_IDT Write_APA_slot_ID_11_P2_Y_APA_slot_ID_11_P2_Y;
    APA_slot_ID_11_P3_X_IDT Write_APA_slot_ID_11_P3_X_APA_slot_ID_11_P3_X;
    APA_slot_ID_11_P3_Y_IDT Write_APA_slot_ID_11_P3_Y_APA_slot_ID_11_P3_Y;
    APA_slot_ID_11_Type_IDT Write_APA_slot_ID_11_Type_APA_slot_ID_11_Type;
    APA_slot_ID_12_P0_X_IDT Write_APA_slot_ID_12_P0_X_APA_slot_ID_12_P0_X;
    APA_slot_ID_12_P0_Y_IDT Write_APA_slot_ID_12_P0_Y_APA_slot_ID_12_P0_Y;
    APA_slot_ID_12_P1_X_IDT Write_APA_slot_ID_12_P1_X_APA_slot_ID_12_P1_X;
    APA_slot_ID_12_P1_Y_IDT Write_APA_slot_ID_12_P1_Y_APA_slot_ID_12_P1_Y;
    APA_slot_ID_12_P2_X_IDT Write_APA_slot_ID_12_P2_X_APA_slot_ID_12_P2_X;
    APA_slot_ID_12_P2_Y_IDT Write_APA_slot_ID_12_P2_Y_APA_slot_ID_12_P2_Y;
    APA_slot_ID_12_P3_X_IDT Write_APA_slot_ID_12_P3_X_APA_slot_ID_12_P3_X;
    APA_slot_ID_12_P3_Y_IDT Write_APA_slot_ID_12_P3_Y_APA_slot_ID_12_P3_Y;
    APA_slot_ID_12_Type_IDT Write_APA_slot_ID_12_Type_APA_slot_ID_12_Type;
    APA_slot_ID_1_P0_X_IDT Write_APA_slot_ID_1_P0_X_APA_slot_ID_1_P0_X;
    APA_slot_ID_1_P0_Y_IDT Write_APA_slot_ID_1_P0_Y_APA_slot_ID_1_P0_Y;
    APA_slot_ID_1_P1_X_IDT Write_APA_slot_ID_1_P1_X_APA_slot_ID_1_P1_X;
    APA_slot_ID_1_P1_Y_IDT Write_APA_slot_ID_1_P1_Y_APA_slot_ID_1_P1_Y;
    APA_slot_ID_1_P2_X_IDT Write_APA_slot_ID_1_P2_X_APA_slot_ID_1_P2_X;
    APA_slot_ID_1_P2_Y_IDT Write_APA_slot_ID_1_P2_Y_APA_slot_ID_1_P2_Y;
    APA_slot_ID_1_P3_X_IDT Write_APA_slot_ID_1_P3_X_APA_slot_ID_1_P3_X;
    APA_slot_ID_1_P3_Y_IDT Write_APA_slot_ID_1_P3_Y_APA_slot_ID_1_P3_Y;
    APA_slot_ID_1_Type_IDT Write_APA_slot_ID_1_Type_APA_slot_ID_1_Type;
    APA_slot_ID_2_P0_X_IDT Write_APA_slot_ID_2_P0_X_APA_slot_ID_2_P0_X;
    APA_slot_ID_2_P0_Y_IDT Write_APA_slot_ID_2_P0_Y_APA_slot_ID_2_P0_Y;
    APA_slot_ID_2_P1_X_IDT Write_APA_slot_ID_2_P1_X_APA_slot_ID_2_P1_X;
    APA_slot_ID_2_P1_Y_IDT Write_APA_slot_ID_2_P1_Y_APA_slot_ID_2_P1_Y;
    APA_slot_ID_2_P2_X_IDT Write_APA_slot_ID_2_P2_X_APA_slot_ID_2_P2_X;
    APA_slot_ID_2_P2_Y_IDT Write_APA_slot_ID_2_P2_Y_APA_slot_ID_2_P2_Y;
    APA_slot_ID_2_P3_X_IDT Write_APA_slot_ID_2_P3_X_APA_slot_ID_2_P3_X;
    APA_slot_ID_2_P3_Y_IDT Write_APA_slot_ID_2_P3_Y_APA_slot_ID_2_P3_Y;
    APA_slot_ID_2_Type_IDT Write_APA_slot_ID_2_Type_APA_slot_ID_2_Type;
    APA_slot_ID_3_P0_X_IDT Write_APA_slot_ID_3_P0_X_APA_slot_ID_3_P0_X;
    APA_slot_ID_3_P0_Y_IDT Write_APA_slot_ID_3_P0_Y_APA_slot_ID_3_P0_Y;
    APA_slot_ID_3_P1_X_IDT Write_APA_slot_ID_3_P1_X_APA_slot_ID_3_P1_X;
    APA_slot_ID_3_P1_Y_IDT Write_APA_slot_ID_3_P1_Y_APA_slot_ID_3_P1_Y;
    APA_slot_ID_3_P2_X_IDT Write_APA_slot_ID_3_P2_X_APA_slot_ID_3_P2_X;
    APA_slot_ID_3_P2_Y_IDT Write_APA_slot_ID_3_P2_Y_APA_slot_ID_3_P2_Y;
    APA_slot_ID_3_P3_X_IDT Write_APA_slot_ID_3_P3_X_APA_slot_ID_3_P3_X;
    APA_slot_ID_3_P3_Y_IDT Write_APA_slot_ID_3_P3_Y_APA_slot_ID_3_P3_Y;
    APA_slot_ID_3_Type_IDT Write_APA_slot_ID_3_Type_APA_slot_ID_3_Type;
    APA_slot_ID_4_P0_X_IDT Write_APA_slot_ID_4_P0_X_APA_slot_ID_4_P0_X;
    APA_slot_ID_4_P0_Y_IDT Write_APA_slot_ID_4_P0_Y_APA_slot_ID_4_P0_Y;
    APA_slot_ID_4_P1_X_IDT Write_APA_slot_ID_4_P1_X_APA_slot_ID_4_P1_X;
    APA_slot_ID_4_P1_Y_IDT Write_APA_slot_ID_4_P1_Y_APA_slot_ID_4_P1_Y;
    APA_slot_ID_4_P2_X_IDT Write_APA_slot_ID_4_P2_X_APA_slot_ID_4_P2_X;
    APA_slot_ID_4_P2_Y_IDT Write_APA_slot_ID_4_P2_Y_APA_slot_ID_4_P2_Y;
    APA_slot_ID_4_P3_X_IDT Write_APA_slot_ID_4_P3_X_APA_slot_ID_4_P3_X;
    APA_slot_ID_4_P3_Y_IDT Write_APA_slot_ID_4_P3_Y_APA_slot_ID_4_P3_Y;
    APA_slot_ID_4_Type_IDT Write_APA_slot_ID_4_Type_APA_slot_ID_4_Type;
    APA_slot_ID_5_P0_X_IDT Write_APA_slot_ID_5_P0_X_APA_slot_ID_5_P0_X;
    APA_slot_ID_5_P0_Y_IDT Write_APA_slot_ID_5_P0_Y_APA_slot_ID_5_P0_Y;
    APA_slot_ID_5_P1_X_IDT Write_APA_slot_ID_5_P1_X_APA_slot_ID_5_P1_X;
    APA_slot_ID_5_P1_Y_IDT Write_APA_slot_ID_5_P1_Y_APA_slot_ID_5_P1_Y;
    APA_slot_ID_5_P2_X_IDT Write_APA_slot_ID_5_P2_X_APA_slot_ID_5_P2_X;
    APA_slot_ID_5_P2_Y_IDT Write_APA_slot_ID_5_P2_Y_APA_slot_ID_5_P2_Y;
    APA_slot_ID_5_P3_X_IDT Write_APA_slot_ID_5_P3_X_APA_slot_ID_5_P3_X;
    APA_slot_ID_5_P3_Y_IDT Write_APA_slot_ID_5_P3_Y_APA_slot_ID_5_P3_Y;
    APA_slot_ID_5_Type_IDT Write_APA_slot_ID_5_Type_APA_slot_ID_5_Type;
    APA_slot_ID_6_P0_X_IDT Write_APA_slot_ID_6_P0_X_APA_slot_ID_6_P0_X;
    APA_slot_ID_6_P0_Y_IDT Write_APA_slot_ID_6_P0_Y_APA_slot_ID_6_P0_Y;
    APA_slot_ID_6_P1_X_IDT Write_APA_slot_ID_6_P1_X_APA_slot_ID_6_P1_X;
    APA_slot_ID_6_P1_Y_IDT Write_APA_slot_ID_6_P1_Y_APA_slot_ID_6_P1_Y;
    APA_slot_ID_6_P2_X_IDT Write_APA_slot_ID_6_P2_X_APA_slot_ID_6_P2_X;
    APA_slot_ID_6_P2_Y_IDT Write_APA_slot_ID_6_P2_Y_APA_slot_ID_6_P2_Y;
    APA_slot_ID_6_P3_X_IDT Write_APA_slot_ID_6_P3_X_APA_slot_ID_6_P3_X;
    APA_slot_ID_6_P3_Y_IDT Write_APA_slot_ID_6_P3_Y_APA_slot_ID_6_P3_Y;
    APA_slot_ID_6_Type_IDT Write_APA_slot_ID_6_Type_APA_slot_ID_6_Type;
    APA_slot_ID_7_P0_X_IDT Write_APA_slot_ID_7_P0_X_APA_slot_ID_7_P0_X;
    APA_slot_ID_7_P0_Y_IDT Write_APA_slot_ID_7_P0_Y_APA_slot_ID_7_P0_Y;
    APA_slot_ID_7_P1_X_IDT Write_APA_slot_ID_7_P1_X_APA_slot_ID_7_P1_X;
    APA_slot_ID_7_P1_Y_IDT Write_APA_slot_ID_7_P1_Y_APA_slot_ID_7_P1_Y;
    APA_slot_ID_7_P2_X_IDT Write_APA_slot_ID_7_P2_X_APA_slot_ID_7_P2_X;
    APA_slot_ID_7_P2_Y_IDT Write_APA_slot_ID_7_P2_Y_APA_slot_ID_7_P2_Y;
    APA_slot_ID_7_P3_X_IDT Write_APA_slot_ID_7_P3_X_APA_slot_ID_7_P3_X;
    APA_slot_ID_7_P3_Y_IDT Write_APA_slot_ID_7_P3_Y_APA_slot_ID_7_P3_Y;
    APA_slot_ID_7_Type_IDT Write_APA_slot_ID_7_Type_APA_slot_ID_7_Type;
    APA_slot_ID_8_P0_X_IDT Write_APA_slot_ID_8_P0_X_APA_slot_ID_8_P0_X;
    APA_slot_ID_8_P0_Y_IDT Write_APA_slot_ID_8_P0_Y_APA_slot_ID_8_P0_Y;
    APA_slot_ID_8_P1_X_IDT Write_APA_slot_ID_8_P1_X_APA_slot_ID_8_P1_X;
    APA_slot_ID_8_P1_Y_IDT Write_APA_slot_ID_8_P1_Y_APA_slot_ID_8_P1_Y;
    APA_slot_ID_8_P2_X_IDT Write_APA_slot_ID_8_P2_X_APA_slot_ID_8_P2_X;
    APA_slot_ID_8_P2_Y_IDT Write_APA_slot_ID_8_P2_Y_APA_slot_ID_8_P2_Y;
    APA_slot_ID_8_P3_X_IDT Write_APA_slot_ID_8_P3_X_APA_slot_ID_8_P3_X;
    APA_slot_ID_8_P3_Y_IDT Write_APA_slot_ID_8_P3_Y_APA_slot_ID_8_P3_Y;
    APA_slot_ID_8_Type_IDT Write_APA_slot_ID_8_Type_APA_slot_ID_8_Type;
    APA_slot_ID_9_P0_X_IDT Write_APA_slot_ID_9_P0_X_APA_slot_ID_9_P0_X;
    APA_slot_ID_9_P0_Y_IDT Write_APA_slot_ID_9_P0_Y_APA_slot_ID_9_P0_Y;
    APA_slot_ID_9_P1_X_IDT Write_APA_slot_ID_9_P1_X_APA_slot_ID_9_P1_X;
    APA_slot_ID_9_P1_Y_IDT Write_APA_slot_ID_9_P1_Y_APA_slot_ID_9_P1_Y;
    APA_slot_ID_9_P2_X_IDT Write_APA_slot_ID_9_P2_X_APA_slot_ID_9_P2_X;
    APA_slot_ID_9_P2_Y_IDT Write_APA_slot_ID_9_P2_Y_APA_slot_ID_9_P2_Y;
    APA_slot_ID_9_P3_X_IDT Write_APA_slot_ID_9_P3_X_APA_slot_ID_9_P3_X;
    APA_slot_ID_9_P3_Y_IDT Write_APA_slot_ID_9_P3_Y_APA_slot_ID_9_P3_Y;
    APA_slot_ID_9_Type_IDT Write_APA_slot_ID_9_Type_APA_slot_ID_9_Type;
    FLC_ExtenedDistance_IDT Write_FLC_ExtenedDistance_FLC_ExtenedDistance;
    FLM_ExtenedDistance_IDT Write_FLM_ExtenedDistance_FLM_ExtenedDistance;
    FLS_ExtenedDistance_IDT Write_FLS_ExtenedDistance_FLS_ExtenedDistance;
    FRC_ExtenedDistance_IDT Write_FRC_ExtenedDistance_FRC_ExtenedDistance;
    FRM_ExtenedDistance_IDT Write_FRM_ExtenedDistance_FRM_ExtenedDistance;
    FRS_ExtenedDistance_IDT Write_FRS_ExtenedDistance_FRS_ExtenedDistance;
    CarInfoH Write_PiCarInfoH_PiCarInfoH;
    CarInfoL Write_PiCarInfoL_PiCarInfoL;
    IMUInfo Write_PiImuInfo_PiIMUInfo;
    ParkingSlotSet Write_PiManualParkingSlotSet_PiManualParkingSlotSet;
    WorkingStatus Write_PiSignalTransWorkingStatus_PiSignalTransWorkingStatus;
    RLC_ExtenedDistance_IDT Write_RLC_ExtenedDistance_RLC_ExtenedDistance;
    RLM_ExtenedDistance_IDT Write_RLM_ExtenedDistance_RLM_ExtenedDistance;
    RLS_ExtenedDistance_IDT Write_RLS_ExtenedDistance_RLS_ExtenedDistance;
    RRC_ExtenedDistance_IDT Write_RRC_ExtenedDistance_RRC_ExtenedDistance;
    RRM_ExtenedDistance_IDT Write_RRM_ExtenedDistance_RRM_ExtenedDistance;
    RRS_ExtenedDistance_IDT Write_RRS_ExtenedDistance_RRS_ExtenedDistance;
    ABS_FLWheelDirection_IDT Read_ABS_FLWheelDirection_ABS_FLWheelDirection;
    ABS_FLWheelSpeedKPH_IDT Read_ABS_FLWheelSpeedKPH_ABS_FLWheelSpeedKPH;
    ABS_FLWheelSpeedRC_IDT Read_ABS_FLWheelSpeedRC_ABS_FLWheelSpeedRC;
    ABS_FRWheelDirection_IDT Read_ABS_FRWheelDirection_ABS_FRWheelDirection;
    ABS_FRWheelSpeedKPH_IDT Read_ABS_FRWheelSpeedKPH_ABS_FRWheelSpeedKPH;
    ABS_FRWheelSpeedRC_IDT Read_ABS_FRWheelSpeedRC_ABS_FRWheelSpeedRC;
    ABS_RLWheelDirection_IDT Read_ABS_RLWheelDirection_ABS_RLWheelDirection;
    ABS_RLWheelSpeedKPH_IDT Read_ABS_RLWheelSpeedKPH_ABS_RLWheelSpeedKPH;
    ABS_RLWheelSpeedRC_IDT Read_ABS_RLWheelSpeedRC_ABS_RLWheelSpeedRC;
    ABS_RRWheelDirection_IDT Read_ABS_RRWheelDirection_ABS_RRWheelDirection;
    ABS_RRWheelSpeedKPH_IDT Read_ABS_RRWheelSpeedKPH_ABS_RRWheelSpeedKPH;
    ABS_RRWheelSpeedRC_IDT Read_ABS_RRWheelSpeedRC_ABS_RRWheelSpeedRC;
    ABS_VehicleSpeed_IDT Read_ABS_VehicleSpeed_ABS_VehicleSpeed;
    AB_BrkPedalSwSts_IDT Read_AB_BrkPedalSwSts_AB_BrkPedalSwSts;
    AB_BrkPedalTravel_IDT Read_AB_BrkPedalTravel_AB_BrkPedalTravel;
    AB_Fault_Status_IDT Read_AB_Fault_Status_AB_Fault_Status;
    ACU_CoDSeatbeltBucklestatus_IDT Read_ACU_CoDSeatbeltBucklestatus_ACU_CoDSeatbeltBucklestatus;
    ACU_DSeatbeltBucklestatus_IDT Read_ACU_DSeatbeltBucklestatus_ACU_DSeatbeltBucklestatus;
    BCM_CodriversSideDoorAjarSts_IDT Read_BCM_CodriversSideDoorAjarSts_BCM_CodriversSideDoorAjarSts;
    BCM_CoverAjarStatus_IDT Read_BCM_CoverAjarStatus_BCM_CoverAjarStatus;
    BCM_DriverSideDoorAjarSts_IDT Read_BCM_DriverSideDoorAjarSts_BCM_DriverSideDoorAjarSts;
    BCM_RearLeftDoorAjarStatus_IDT Read_BCM_RearLeftDoorAjarStatus_BCM_RearLeftDoorAjarStatus;
    BCM_RearRightDoorAjarStatus_IDT Read_BCM_RearRightDoorAjarStatus_BCM_RearRightDoorAjarStatus;
    BCM_TrunckAjarStatus_IDT Read_BCM_TrunckAjarStatus_BCM_TrunckAjarStatus;
    CCU_ExternalTemperature_IDT Read_CCU_ExternalTemperature_CCU_ExternalTemperature;
    EPB_Sts_IDT Read_EPB_Sts_EPB_Sts;
    EPS_APA_CtrlAbortFeedback_IDT Read_EPS_APA_CtrlAbortFeedback_EPS_APA_CtrlAbortFeedback;
    EPS_APA_ModActv_IDT Read_EPS_APA_ModActv_EPS_APA_ModActv;
    EPS_APA_ModAvail_IDT Read_EPS_APA_ModAvail_EPS_APA_ModAvail;
    EPS_DrStrTorqVal_IDT Read_EPS_DrStrTorqVal_EPS_DrStrTorqVal;
    ESC_LateralACC_IDT Read_ESC_LateralACC_ESC_LateralACC;
    ESC_LongitudeACC_IDT Read_ESC_LongitudeACC_ESC_LongitudeACC;
    ESC_MasterCylinderPressure_IDT Read_ESC_MasterCylinderPressure_ESC_MasterCylinderPressure;
    ESC_SlopeGradeAngle_IDT Read_ESC_SlopeGradeAngle_ESC_SlopeGradeAngle;
    ESC_VehDynYawRate_IDT Read_ESC_VehDynYawRate_ESC_VehDynYawRate;
    MHU_APA_ParkingSpace_ID_IDT Read_MHU_APA_ParkingSpace_ID_MHU_APA_ParkingSpace_ID;
    MHU_UPAMuteSwitch_IDT Read_MHU_UPAMuteSwitch_MHU_UPAMuteSwitch;
    PEPS_IGN1RelaySts_IDT Read_PEPS_IGN1RelaySts_PEPS_IGN1RelaySts;
    PEPS_PowerMode_IDT Read_PEPS_PowerMode_PEPS_PowerMode;
    ParkingSlotSet Read_PiAvmFusionParkingSlot_PiAvmFusionParkingSlot;
    CarControlCommandH Read_PiCarControlCommandH_PiCarControlCommandH;
    CarControlCommandL Read_PiCarControlCommandL_PiCarControlCommandL;
    GuideLine Read_PiGuideLine_PiGuideLine;
    UssPdcInfo Read_PiUssPdcInfo_PiUssPdcInfo;
    SAS_SteerWheelAngle_IDT Read_SAS_SteerWheelAngle_SAS_SteerWheelAngle;
    SAS_SteerWhlRotSpdStatus_IDT Read_SAS_SteerWhlRotSpdStatus_SAS_SteerWhlRotSpdStatus;
    SAS_SteerWhlRotSpd_IDT Read_SAS_SteerWhlRotSpd_SAS_SteerWhlRotSpd;
    TPMS_LFpressureSts_IDT Read_TPMS_LFpressureSts_TPMS_LFpressureSts;
    TPMS_LFpressure_IDT Read_TPMS_LFpressure_TPMS_LFpressure;
    TPMS_LRpressureSts_IDT Read_TPMS_LRpressureSts_TPMS_LRpressureSts;
    TPMS_LRpressure_IDT Read_TPMS_LRpressure_TPMS_LRpressure;
    TPMS_RFpressureSts_IDT Read_TPMS_RFpressureSts_TPMS_RFpressureSts;
    TPMS_RFpressure_IDT Read_TPMS_RFpressure_TPMS_RFpressure;
    TPMS_RRpressureSts_IDT Read_TPMS_RRpressureSts_TPMS_RRpressureSts;
    TPMS_RRpressure_IDT Read_TPMS_RRpressure_TPMS_RRpressure;
    uint64 Read_TimeStamp_ABS_FrontWheelSpeMCUKPH_0x122_TimeStamp_ABS_FrontWheelSpeMCUKPH_0x122;
    uint64 Read_TimeStamp_ABS_RearWheelSpeMCUKPH_0x123_TimeStamp_ABS_RearWheelSpeMCUKPH_0x123;
    uint64 Read_TimeStamp_ABS_Status_0x125_TimeStamp_ABS_Status_0x125;
    uint64 Read_TimeStamp_ABS_WheelSpeedRC_0x124_TimeStamp_ABS_WheelSpeedRC_0x124;
    uint64 Read_TimeStamp_ESC_YawAngle_0x3E2_TimeStamp_ESC_YawAngle_0x3E2;
    uint64 Read_TimeStamp_IBS_ADAS_Info_0x269_TimeStamp_IBS_ADAS_Info_0x269;
    uint64 Read_TimeStamp_SAS_Sensor_0x17E_TimeStamp_SAS_Sensor_0x17E;
    uint64 Read_TimeStamp_VCU_Ctrl_0x162_TimeStamp_VCU_Ctrl_0x162;
    VCU_AccPedalPosition_IDT Read_VCU_AccPedalPosition_VCU_AccPedalPosition;
    VCU_ModeGearSts_IDT Read_VCU_ModeGearSts_VCU_ModeGearSts;
    VCU_StsSysFault_IDT Read_VCU_StsSysFault_VCU_StsSysFault;
    WCBS_APA_CDD_Active_IDT Read_WCBS_APA_CDD_Active_WCBS_APA_CDD_Active;
    WCBS_APA_VLC_Active_IDT Read_WCBS_APA_VLC_Active_WCBS_APA_VLC_Active;
    WCBS_APA_VLC_Available_IDT Read_WCBS_APA_VLC_Available_WCBS_APA_VLC_Available;
    WCBS_APA_VLC_FailureStatus_IDT Read_WCBS_APA_VLC_FailureStatus_WCBS_APA_VLC_FailureStatus;
    WCBS_APA_VLC_Status_IDT Read_WCBS_APA_VLC_Status_WCBS_APA_VLC_Status;
    WCBS_VStandstillSta_IDT Read_WCBS_VStandstillSta_WCBS_VStandstillSta;
    /* TSK_Signal_Transmission_10ms Varaible Define User Code start*/

    /* TSK_Signal_Transmission_10ms Varaible Define User Code end*/




    Rte_Write_ADAS_APA_LightReq_ADAS_APA_LightReq(Write_ADAS_APA_LightReq_ADAS_APA_LightReq);
    /* Rte_Write_ADAS_APA_LightReq_ADAS_APA_LightReq User Code start*/

    /* Rte_Write_ADAS_APA_LightReq_ADAS_APA_LightReq User Code end*/
    Rte_Write_ADAS_APA_SuggestedID_ADAS_APA_SuggestedID(Write_ADAS_APA_SuggestedID_ADAS_APA_SuggestedID);
    /* Rte_Write_ADAS_APA_SuggestedID_ADAS_APA_SuggestedID User Code start*/

    /* Rte_Write_ADAS_APA_SuggestedID_ADAS_APA_SuggestedID User Code end*/
    Rte_Write_APA_ChimeRequest_APA_ChimeRequest(Write_APA_ChimeRequest_APA_ChimeRequest);
    /* Rte_Write_APA_ChimeRequest_APA_ChimeRequest User Code start*/

    /* Rte_Write_APA_ChimeRequest_APA_ChimeRequest User Code end*/
    Rte_Write_APA_EPS_AngReqSts_APA_EPS_AngReqSts(Write_APA_EPS_AngReqSts_APA_EPS_AngReqSts);
    /* Rte_Write_APA_EPS_AngReqSts_APA_EPS_AngReqSts User Code start*/

    /* Rte_Write_APA_EPS_AngReqSts_APA_EPS_AngReqSts User Code end*/
    Rte_Write_APA_EPS_TargetSteeringAngle_APA_EPS_TargetSteeringAngle(Write_APA_EPS_TargetSteeringAngle_APA_EPS_TargetSteeringAngle);
    /* Rte_Write_APA_EPS_TargetSteeringAngle_APA_EPS_TargetSteeringAngle User Code start*/

    /* Rte_Write_APA_EPS_TargetSteeringAngle_APA_EPS_TargetSteeringAngle User Code end*/
    Rte_Write_APA_FRegion1ObjectSts_APA_FRegion1ObjectSts(Write_APA_FRegion1ObjectSts_APA_FRegion1ObjectSts);
    /* Rte_Write_APA_FRegion1ObjectSts_APA_FRegion1ObjectSts User Code start*/

    /* Rte_Write_APA_FRegion1ObjectSts_APA_FRegion1ObjectSts User Code end*/
    Rte_Write_APA_FRegion2ObjectSts_APA_FRegion2ObjectSts(Write_APA_FRegion2ObjectSts_APA_FRegion2ObjectSts);
    /* Rte_Write_APA_FRegion2ObjectSts_APA_FRegion2ObjectSts User Code start*/

    /* Rte_Write_APA_FRegion2ObjectSts_APA_FRegion2ObjectSts User Code end*/
    Rte_Write_APA_FRegion3ObjectSts_APA_FRegion3ObjectSts(Write_APA_FRegion3ObjectSts_APA_FRegion3ObjectSts);
    /* Rte_Write_APA_FRegion3ObjectSts_APA_FRegion3ObjectSts User Code start*/

    /* Rte_Write_APA_FRegion3ObjectSts_APA_FRegion3ObjectSts User Code end*/
    Rte_Write_APA_FRegion4ObjectSts_APA_FRegion4ObjectSts(Write_APA_FRegion4ObjectSts_APA_FRegion4ObjectSts);
    /* Rte_Write_APA_FRegion4ObjectSts_APA_FRegion4ObjectSts User Code start*/

    /* Rte_Write_APA_FRegion4ObjectSts_APA_FRegion4ObjectSts User Code end*/
    Rte_Write_APA_FrontExtenedDistance_APA_FrontExtenedDistance(Write_APA_FrontExtenedDistance_APA_FrontExtenedDistance);
    /* Rte_Write_APA_FrontExtenedDistance_APA_FrontExtenedDistance User Code start*/

    /* Rte_Write_APA_FrontExtenedDistance_APA_FrontExtenedDistance User Code end*/
    Rte_Write_APA_ParkAssistRExtenedDistance_APA_ParkAssistRExtenedDistance(Write_APA_ParkAssistRExtenedDistance_APA_ParkAssistRExtenedDistance);
    /* Rte_Write_APA_ParkAssistRExtenedDistance_APA_ParkAssistRExtenedDistance User Code start*/

    /* Rte_Write_APA_ParkAssistRExtenedDistance_APA_ParkAssistRExtenedDistance User Code end*/
    Rte_Write_APA_ParkAssistRRegion1ObjectSts_APA_ParkAssistRRegion1ObjectSts(Write_APA_ParkAssistRRegion1ObjectSts_APA_ParkAssistRRegion1ObjectSts);
    /* Rte_Write_APA_ParkAssistRRegion1ObjectSts_APA_ParkAssistRRegion1ObjectSts User Code start*/

    /* Rte_Write_APA_ParkAssistRRegion1ObjectSts_APA_ParkAssistRRegion1ObjectSts User Code end*/
    Rte_Write_APA_ParkAssistRRegion2ObjectSts_APA_ParkAssistRRegion2ObjectSts(Write_APA_ParkAssistRRegion2ObjectSts_APA_ParkAssistRRegion2ObjectSts);
    /* Rte_Write_APA_ParkAssistRRegion2ObjectSts_APA_ParkAssistRRegion2ObjectSts User Code start*/

    /* Rte_Write_APA_ParkAssistRRegion2ObjectSts_APA_ParkAssistRRegion2ObjectSts User Code end*/
    Rte_Write_APA_ParkAssistRRegion3ObjectSts_APA_ParkAssistRRegion3ObjectSts(Write_APA_ParkAssistRRegion3ObjectSts_APA_ParkAssistRRegion3ObjectSts);
    /* Rte_Write_APA_ParkAssistRRegion3ObjectSts_APA_ParkAssistRRegion3ObjectSts User Code start*/

    /* Rte_Write_APA_ParkAssistRRegion3ObjectSts_APA_ParkAssistRRegion3ObjectSts User Code end*/
    Rte_Write_APA_ParkAssistRRegion4ObjectSts_APA_ParkAssistRRegion4ObjectSts(Write_APA_ParkAssistRRegion4ObjectSts_APA_ParkAssistRRegion4ObjectSts);
    /* Rte_Write_APA_ParkAssistRRegion4ObjectSts_APA_ParkAssistRRegion4ObjectSts User Code start*/

    /* Rte_Write_APA_ParkAssistRRegion4ObjectSts_APA_ParkAssistRRegion4ObjectSts User Code end*/
    Rte_Write_APA_WCBS_BrakeMode_APA_WCBS_BrakeMode(Write_APA_WCBS_BrakeMode_APA_WCBS_BrakeMode);
    /* Rte_Write_APA_WCBS_BrakeMode_APA_WCBS_BrakeMode User Code start*/

    /* Rte_Write_APA_WCBS_BrakeMode_APA_WCBS_BrakeMode User Code end*/
    Rte_Write_APA_WCBS_ExpectedGearPosition_APA_WCBS_ExpectedGearPosition(Write_APA_WCBS_ExpectedGearPosition_APA_WCBS_ExpectedGearPosition);
    /* Rte_Write_APA_WCBS_ExpectedGearPosition_APA_WCBS_ExpectedGearPosition User Code start*/

    /* Rte_Write_APA_WCBS_ExpectedGearPosition_APA_WCBS_ExpectedGearPosition User Code end*/
    Rte_Write_APA_WCBS_SpeedLimitation_APA_WCBS_SpeedLimitation(Write_APA_WCBS_SpeedLimitation_APA_WCBS_SpeedLimitation);
    /* Rte_Write_APA_WCBS_SpeedLimitation_APA_WCBS_SpeedLimitation User Code start*/

    /* Rte_Write_APA_WCBS_SpeedLimitation_APA_WCBS_SpeedLimitation User Code end*/
    Rte_Write_APA_WCBS_TargetStopDistance_APA_WCBS_TargetStopDistance(Write_APA_WCBS_TargetStopDistance_APA_WCBS_TargetStopDistance);
    /* Rte_Write_APA_WCBS_TargetStopDistance_APA_WCBS_TargetStopDistance User Code start*/

    /* Rte_Write_APA_WCBS_TargetStopDistance_APA_WCBS_TargetStopDistance User Code end*/
    Rte_Write_APA_slot_10_APA_slot_10(Write_APA_slot_10_APA_slot_10);
    /* Rte_Write_APA_slot_10_APA_slot_10 User Code start*/

    /* Rte_Write_APA_slot_10_APA_slot_10 User Code end*/
    Rte_Write_APA_slot_11_APA_slot_11(Write_APA_slot_11_APA_slot_11);
    /* Rte_Write_APA_slot_11_APA_slot_11 User Code start*/

    /* Rte_Write_APA_slot_11_APA_slot_11 User Code end*/
    Rte_Write_APA_slot_12_APA_slot_12(Write_APA_slot_12_APA_slot_12);
    /* Rte_Write_APA_slot_12_APA_slot_12 User Code start*/

    /* Rte_Write_APA_slot_12_APA_slot_12 User Code end*/
    Rte_Write_APA_slot_1_APA_slot_1(Write_APA_slot_1_APA_slot_1);
    /* Rte_Write_APA_slot_1_APA_slot_1 User Code start*/

    /* Rte_Write_APA_slot_1_APA_slot_1 User Code end*/
    Rte_Write_APA_slot_2_APA_slot_2(Write_APA_slot_2_APA_slot_2);
    /* Rte_Write_APA_slot_2_APA_slot_2 User Code start*/

    /* Rte_Write_APA_slot_2_APA_slot_2 User Code end*/
    Rte_Write_APA_slot_3_APA_slot_3(Write_APA_slot_3_APA_slot_3);
    /* Rte_Write_APA_slot_3_APA_slot_3 User Code start*/

    /* Rte_Write_APA_slot_3_APA_slot_3 User Code end*/
    Rte_Write_APA_slot_4_APA_slot_4(Write_APA_slot_4_APA_slot_4);
    /* Rte_Write_APA_slot_4_APA_slot_4 User Code start*/

    /* Rte_Write_APA_slot_4_APA_slot_4 User Code end*/
    Rte_Write_APA_slot_5_APA_slot_5(Write_APA_slot_5_APA_slot_5);
    /* Rte_Write_APA_slot_5_APA_slot_5 User Code start*/

    /* Rte_Write_APA_slot_5_APA_slot_5 User Code end*/
    Rte_Write_APA_slot_6_APA_slot_6(Write_APA_slot_6_APA_slot_6);
    /* Rte_Write_APA_slot_6_APA_slot_6 User Code start*/

    /* Rte_Write_APA_slot_6_APA_slot_6 User Code end*/
    Rte_Write_APA_slot_7_APA_slot_7(Write_APA_slot_7_APA_slot_7);
    /* Rte_Write_APA_slot_7_APA_slot_7 User Code start*/

    /* Rte_Write_APA_slot_7_APA_slot_7 User Code end*/
    Rte_Write_APA_slot_8_APA_slot_8(Write_APA_slot_8_APA_slot_8);
    /* Rte_Write_APA_slot_8_APA_slot_8 User Code start*/

    /* Rte_Write_APA_slot_8_APA_slot_8 User Code end*/
    Rte_Write_APA_slot_9_APA_slot_9(Write_APA_slot_9_APA_slot_9);
    /* Rte_Write_APA_slot_9_APA_slot_9 User Code start*/

    /* Rte_Write_APA_slot_9_APA_slot_9 User Code end*/
    Rte_Write_APA_slot_ID_10_P0_X_APA_slot_ID_10_P0_X(Write_APA_slot_ID_10_P0_X_APA_slot_ID_10_P0_X);
    /* Rte_Write_APA_slot_ID_10_P0_X_APA_slot_ID_10_P0_X User Code start*/

    /* Rte_Write_APA_slot_ID_10_P0_X_APA_slot_ID_10_P0_X User Code end*/
    Rte_Write_APA_slot_ID_10_P0_Y_APA_slot_ID_10_P0_Y(Write_APA_slot_ID_10_P0_Y_APA_slot_ID_10_P0_Y);
    /* Rte_Write_APA_slot_ID_10_P0_Y_APA_slot_ID_10_P0_Y User Code start*/

    /* Rte_Write_APA_slot_ID_10_P0_Y_APA_slot_ID_10_P0_Y User Code end*/
    Rte_Write_APA_slot_ID_10_P1_X_APA_slot_ID_10_P1_X(Write_APA_slot_ID_10_P1_X_APA_slot_ID_10_P1_X);
    /* Rte_Write_APA_slot_ID_10_P1_X_APA_slot_ID_10_P1_X User Code start*/

    /* Rte_Write_APA_slot_ID_10_P1_X_APA_slot_ID_10_P1_X User Code end*/
    Rte_Write_APA_slot_ID_10_P1_Y_APA_slot_ID_10_P1_Y(Write_APA_slot_ID_10_P1_Y_APA_slot_ID_10_P1_Y);
    /* Rte_Write_APA_slot_ID_10_P1_Y_APA_slot_ID_10_P1_Y User Code start*/

    /* Rte_Write_APA_slot_ID_10_P1_Y_APA_slot_ID_10_P1_Y User Code end*/
    Rte_Write_APA_slot_ID_10_P2_X_APA_slot_ID_10_P2_X(Write_APA_slot_ID_10_P2_X_APA_slot_ID_10_P2_X);
    /* Rte_Write_APA_slot_ID_10_P2_X_APA_slot_ID_10_P2_X User Code start*/

    /* Rte_Write_APA_slot_ID_10_P2_X_APA_slot_ID_10_P2_X User Code end*/
    Rte_Write_APA_slot_ID_10_P2_Y_APA_slot_ID_10_P2_Y(Write_APA_slot_ID_10_P2_Y_APA_slot_ID_10_P2_Y);
    /* Rte_Write_APA_slot_ID_10_P2_Y_APA_slot_ID_10_P2_Y User Code start*/

    /* Rte_Write_APA_slot_ID_10_P2_Y_APA_slot_ID_10_P2_Y User Code end*/
    Rte_Write_APA_slot_ID_10_P3_X_APA_slot_ID_10_P3_X(Write_APA_slot_ID_10_P3_X_APA_slot_ID_10_P3_X);
    /* Rte_Write_APA_slot_ID_10_P3_X_APA_slot_ID_10_P3_X User Code start*/

    /* Rte_Write_APA_slot_ID_10_P3_X_APA_slot_ID_10_P3_X User Code end*/
    Rte_Write_APA_slot_ID_10_P3_Y_APA_slot_ID_10_P3_Y(Write_APA_slot_ID_10_P3_Y_APA_slot_ID_10_P3_Y);
    /* Rte_Write_APA_slot_ID_10_P3_Y_APA_slot_ID_10_P3_Y User Code start*/

    /* Rte_Write_APA_slot_ID_10_P3_Y_APA_slot_ID_10_P3_Y User Code end*/
    Rte_Write_APA_slot_ID_10_Type_APA_slot_ID_10_Type(Write_APA_slot_ID_10_Type_APA_slot_ID_10_Type);
    /* Rte_Write_APA_slot_ID_10_Type_APA_slot_ID_10_Type User Code start*/

    /* Rte_Write_APA_slot_ID_10_Type_APA_slot_ID_10_Type User Code end*/
    Rte_Write_APA_slot_ID_11_P0_X_APA_slot_ID_11_P0_X(Write_APA_slot_ID_11_P0_X_APA_slot_ID_11_P0_X);
    /* Rte_Write_APA_slot_ID_11_P0_X_APA_slot_ID_11_P0_X User Code start*/

    /* Rte_Write_APA_slot_ID_11_P0_X_APA_slot_ID_11_P0_X User Code end*/
    Rte_Write_APA_slot_ID_11_P0_Y_APA_slot_ID_11_P0_Y(Write_APA_slot_ID_11_P0_Y_APA_slot_ID_11_P0_Y);
    /* Rte_Write_APA_slot_ID_11_P0_Y_APA_slot_ID_11_P0_Y User Code start*/

    /* Rte_Write_APA_slot_ID_11_P0_Y_APA_slot_ID_11_P0_Y User Code end*/
    Rte_Write_APA_slot_ID_11_P1_X_APA_slot_ID_11_P1_X(Write_APA_slot_ID_11_P1_X_APA_slot_ID_11_P1_X);
    /* Rte_Write_APA_slot_ID_11_P1_X_APA_slot_ID_11_P1_X User Code start*/

    /* Rte_Write_APA_slot_ID_11_P1_X_APA_slot_ID_11_P1_X User Code end*/
    Rte_Write_APA_slot_ID_11_P1_Y_APA_slot_ID_11_P1_Y(Write_APA_slot_ID_11_P1_Y_APA_slot_ID_11_P1_Y);
    /* Rte_Write_APA_slot_ID_11_P1_Y_APA_slot_ID_11_P1_Y User Code start*/

    /* Rte_Write_APA_slot_ID_11_P1_Y_APA_slot_ID_11_P1_Y User Code end*/
    Rte_Write_APA_slot_ID_11_P2_X_APA_slot_ID_11_P2_X(Write_APA_slot_ID_11_P2_X_APA_slot_ID_11_P2_X);
    /* Rte_Write_APA_slot_ID_11_P2_X_APA_slot_ID_11_P2_X User Code start*/

    /* Rte_Write_APA_slot_ID_11_P2_X_APA_slot_ID_11_P2_X User Code end*/
    Rte_Write_APA_slot_ID_11_P2_Y_APA_slot_ID_11_P2_Y(Write_APA_slot_ID_11_P2_Y_APA_slot_ID_11_P2_Y);
    /* Rte_Write_APA_slot_ID_11_P2_Y_APA_slot_ID_11_P2_Y User Code start*/

    /* Rte_Write_APA_slot_ID_11_P2_Y_APA_slot_ID_11_P2_Y User Code end*/
    Rte_Write_APA_slot_ID_11_P3_X_APA_slot_ID_11_P3_X(Write_APA_slot_ID_11_P3_X_APA_slot_ID_11_P3_X);
    /* Rte_Write_APA_slot_ID_11_P3_X_APA_slot_ID_11_P3_X User Code start*/

    /* Rte_Write_APA_slot_ID_11_P3_X_APA_slot_ID_11_P3_X User Code end*/
    Rte_Write_APA_slot_ID_11_P3_Y_APA_slot_ID_11_P3_Y(Write_APA_slot_ID_11_P3_Y_APA_slot_ID_11_P3_Y);
    /* Rte_Write_APA_slot_ID_11_P3_Y_APA_slot_ID_11_P3_Y User Code start*/

    /* Rte_Write_APA_slot_ID_11_P3_Y_APA_slot_ID_11_P3_Y User Code end*/
    Rte_Write_APA_slot_ID_11_Type_APA_slot_ID_11_Type(Write_APA_slot_ID_11_Type_APA_slot_ID_11_Type);
    /* Rte_Write_APA_slot_ID_11_Type_APA_slot_ID_11_Type User Code start*/

    /* Rte_Write_APA_slot_ID_11_Type_APA_slot_ID_11_Type User Code end*/
    Rte_Write_APA_slot_ID_12_P0_X_APA_slot_ID_12_P0_X(Write_APA_slot_ID_12_P0_X_APA_slot_ID_12_P0_X);
    /* Rte_Write_APA_slot_ID_12_P0_X_APA_slot_ID_12_P0_X User Code start*/

    /* Rte_Write_APA_slot_ID_12_P0_X_APA_slot_ID_12_P0_X User Code end*/
    Rte_Write_APA_slot_ID_12_P0_Y_APA_slot_ID_12_P0_Y(Write_APA_slot_ID_12_P0_Y_APA_slot_ID_12_P0_Y);
    /* Rte_Write_APA_slot_ID_12_P0_Y_APA_slot_ID_12_P0_Y User Code start*/

    /* Rte_Write_APA_slot_ID_12_P0_Y_APA_slot_ID_12_P0_Y User Code end*/
    Rte_Write_APA_slot_ID_12_P1_X_APA_slot_ID_12_P1_X(Write_APA_slot_ID_12_P1_X_APA_slot_ID_12_P1_X);
    /* Rte_Write_APA_slot_ID_12_P1_X_APA_slot_ID_12_P1_X User Code start*/

    /* Rte_Write_APA_slot_ID_12_P1_X_APA_slot_ID_12_P1_X User Code end*/
    Rte_Write_APA_slot_ID_12_P1_Y_APA_slot_ID_12_P1_Y(Write_APA_slot_ID_12_P1_Y_APA_slot_ID_12_P1_Y);
    /* Rte_Write_APA_slot_ID_12_P1_Y_APA_slot_ID_12_P1_Y User Code start*/

    /* Rte_Write_APA_slot_ID_12_P1_Y_APA_slot_ID_12_P1_Y User Code end*/
    Rte_Write_APA_slot_ID_12_P2_X_APA_slot_ID_12_P2_X(Write_APA_slot_ID_12_P2_X_APA_slot_ID_12_P2_X);
    /* Rte_Write_APA_slot_ID_12_P2_X_APA_slot_ID_12_P2_X User Code start*/

    /* Rte_Write_APA_slot_ID_12_P2_X_APA_slot_ID_12_P2_X User Code end*/
    Rte_Write_APA_slot_ID_12_P2_Y_APA_slot_ID_12_P2_Y(Write_APA_slot_ID_12_P2_Y_APA_slot_ID_12_P2_Y);
    /* Rte_Write_APA_slot_ID_12_P2_Y_APA_slot_ID_12_P2_Y User Code start*/

    /* Rte_Write_APA_slot_ID_12_P2_Y_APA_slot_ID_12_P2_Y User Code end*/
    Rte_Write_APA_slot_ID_12_P3_X_APA_slot_ID_12_P3_X(Write_APA_slot_ID_12_P3_X_APA_slot_ID_12_P3_X);
    /* Rte_Write_APA_slot_ID_12_P3_X_APA_slot_ID_12_P3_X User Code start*/

    /* Rte_Write_APA_slot_ID_12_P3_X_APA_slot_ID_12_P3_X User Code end*/
    Rte_Write_APA_slot_ID_12_P3_Y_APA_slot_ID_12_P3_Y(Write_APA_slot_ID_12_P3_Y_APA_slot_ID_12_P3_Y);
    /* Rte_Write_APA_slot_ID_12_P3_Y_APA_slot_ID_12_P3_Y User Code start*/

    /* Rte_Write_APA_slot_ID_12_P3_Y_APA_slot_ID_12_P3_Y User Code end*/
    Rte_Write_APA_slot_ID_12_Type_APA_slot_ID_12_Type(Write_APA_slot_ID_12_Type_APA_slot_ID_12_Type);
    /* Rte_Write_APA_slot_ID_12_Type_APA_slot_ID_12_Type User Code start*/

    /* Rte_Write_APA_slot_ID_12_Type_APA_slot_ID_12_Type User Code end*/
    Rte_Write_APA_slot_ID_1_P0_X_APA_slot_ID_1_P0_X(Write_APA_slot_ID_1_P0_X_APA_slot_ID_1_P0_X);
    /* Rte_Write_APA_slot_ID_1_P0_X_APA_slot_ID_1_P0_X User Code start*/

    /* Rte_Write_APA_slot_ID_1_P0_X_APA_slot_ID_1_P0_X User Code end*/
    Rte_Write_APA_slot_ID_1_P0_Y_APA_slot_ID_1_P0_Y(Write_APA_slot_ID_1_P0_Y_APA_slot_ID_1_P0_Y);
    /* Rte_Write_APA_slot_ID_1_P0_Y_APA_slot_ID_1_P0_Y User Code start*/

    /* Rte_Write_APA_slot_ID_1_P0_Y_APA_slot_ID_1_P0_Y User Code end*/
    Rte_Write_APA_slot_ID_1_P1_X_APA_slot_ID_1_P1_X(Write_APA_slot_ID_1_P1_X_APA_slot_ID_1_P1_X);
    /* Rte_Write_APA_slot_ID_1_P1_X_APA_slot_ID_1_P1_X User Code start*/

    /* Rte_Write_APA_slot_ID_1_P1_X_APA_slot_ID_1_P1_X User Code end*/
    Rte_Write_APA_slot_ID_1_P1_Y_APA_slot_ID_1_P1_Y(Write_APA_slot_ID_1_P1_Y_APA_slot_ID_1_P1_Y);
    /* Rte_Write_APA_slot_ID_1_P1_Y_APA_slot_ID_1_P1_Y User Code start*/

    /* Rte_Write_APA_slot_ID_1_P1_Y_APA_slot_ID_1_P1_Y User Code end*/
    Rte_Write_APA_slot_ID_1_P2_X_APA_slot_ID_1_P2_X(Write_APA_slot_ID_1_P2_X_APA_slot_ID_1_P2_X);
    /* Rte_Write_APA_slot_ID_1_P2_X_APA_slot_ID_1_P2_X User Code start*/

    /* Rte_Write_APA_slot_ID_1_P2_X_APA_slot_ID_1_P2_X User Code end*/
    Rte_Write_APA_slot_ID_1_P2_Y_APA_slot_ID_1_P2_Y(Write_APA_slot_ID_1_P2_Y_APA_slot_ID_1_P2_Y);
    /* Rte_Write_APA_slot_ID_1_P2_Y_APA_slot_ID_1_P2_Y User Code start*/

    /* Rte_Write_APA_slot_ID_1_P2_Y_APA_slot_ID_1_P2_Y User Code end*/
    Rte_Write_APA_slot_ID_1_P3_X_APA_slot_ID_1_P3_X(Write_APA_slot_ID_1_P3_X_APA_slot_ID_1_P3_X);
    /* Rte_Write_APA_slot_ID_1_P3_X_APA_slot_ID_1_P3_X User Code start*/

    /* Rte_Write_APA_slot_ID_1_P3_X_APA_slot_ID_1_P3_X User Code end*/
    Rte_Write_APA_slot_ID_1_P3_Y_APA_slot_ID_1_P3_Y(Write_APA_slot_ID_1_P3_Y_APA_slot_ID_1_P3_Y);
    /* Rte_Write_APA_slot_ID_1_P3_Y_APA_slot_ID_1_P3_Y User Code start*/

    /* Rte_Write_APA_slot_ID_1_P3_Y_APA_slot_ID_1_P3_Y User Code end*/
    Rte_Write_APA_slot_ID_1_Type_APA_slot_ID_1_Type(Write_APA_slot_ID_1_Type_APA_slot_ID_1_Type);
    /* Rte_Write_APA_slot_ID_1_Type_APA_slot_ID_1_Type User Code start*/

    /* Rte_Write_APA_slot_ID_1_Type_APA_slot_ID_1_Type User Code end*/
    Rte_Write_APA_slot_ID_2_P0_X_APA_slot_ID_2_P0_X(Write_APA_slot_ID_2_P0_X_APA_slot_ID_2_P0_X);
    /* Rte_Write_APA_slot_ID_2_P0_X_APA_slot_ID_2_P0_X User Code start*/

    /* Rte_Write_APA_slot_ID_2_P0_X_APA_slot_ID_2_P0_X User Code end*/
    Rte_Write_APA_slot_ID_2_P0_Y_APA_slot_ID_2_P0_Y(Write_APA_slot_ID_2_P0_Y_APA_slot_ID_2_P0_Y);
    /* Rte_Write_APA_slot_ID_2_P0_Y_APA_slot_ID_2_P0_Y User Code start*/

    /* Rte_Write_APA_slot_ID_2_P0_Y_APA_slot_ID_2_P0_Y User Code end*/
    Rte_Write_APA_slot_ID_2_P1_X_APA_slot_ID_2_P1_X(Write_APA_slot_ID_2_P1_X_APA_slot_ID_2_P1_X);
    /* Rte_Write_APA_slot_ID_2_P1_X_APA_slot_ID_2_P1_X User Code start*/

    /* Rte_Write_APA_slot_ID_2_P1_X_APA_slot_ID_2_P1_X User Code end*/
    Rte_Write_APA_slot_ID_2_P1_Y_APA_slot_ID_2_P1_Y(Write_APA_slot_ID_2_P1_Y_APA_slot_ID_2_P1_Y);
    /* Rte_Write_APA_slot_ID_2_P1_Y_APA_slot_ID_2_P1_Y User Code start*/

    /* Rte_Write_APA_slot_ID_2_P1_Y_APA_slot_ID_2_P1_Y User Code end*/
    Rte_Write_APA_slot_ID_2_P2_X_APA_slot_ID_2_P2_X(Write_APA_slot_ID_2_P2_X_APA_slot_ID_2_P2_X);
    /* Rte_Write_APA_slot_ID_2_P2_X_APA_slot_ID_2_P2_X User Code start*/

    /* Rte_Write_APA_slot_ID_2_P2_X_APA_slot_ID_2_P2_X User Code end*/
    Rte_Write_APA_slot_ID_2_P2_Y_APA_slot_ID_2_P2_Y(Write_APA_slot_ID_2_P2_Y_APA_slot_ID_2_P2_Y);
    /* Rte_Write_APA_slot_ID_2_P2_Y_APA_slot_ID_2_P2_Y User Code start*/

    /* Rte_Write_APA_slot_ID_2_P2_Y_APA_slot_ID_2_P2_Y User Code end*/
    Rte_Write_APA_slot_ID_2_P3_X_APA_slot_ID_2_P3_X(Write_APA_slot_ID_2_P3_X_APA_slot_ID_2_P3_X);
    /* Rte_Write_APA_slot_ID_2_P3_X_APA_slot_ID_2_P3_X User Code start*/

    /* Rte_Write_APA_slot_ID_2_P3_X_APA_slot_ID_2_P3_X User Code end*/
    Rte_Write_APA_slot_ID_2_P3_Y_APA_slot_ID_2_P3_Y(Write_APA_slot_ID_2_P3_Y_APA_slot_ID_2_P3_Y);
    /* Rte_Write_APA_slot_ID_2_P3_Y_APA_slot_ID_2_P3_Y User Code start*/

    /* Rte_Write_APA_slot_ID_2_P3_Y_APA_slot_ID_2_P3_Y User Code end*/
    Rte_Write_APA_slot_ID_2_Type_APA_slot_ID_2_Type(Write_APA_slot_ID_2_Type_APA_slot_ID_2_Type);
    /* Rte_Write_APA_slot_ID_2_Type_APA_slot_ID_2_Type User Code start*/

    /* Rte_Write_APA_slot_ID_2_Type_APA_slot_ID_2_Type User Code end*/
    Rte_Write_APA_slot_ID_3_P0_X_APA_slot_ID_3_P0_X(Write_APA_slot_ID_3_P0_X_APA_slot_ID_3_P0_X);
    /* Rte_Write_APA_slot_ID_3_P0_X_APA_slot_ID_3_P0_X User Code start*/

    /* Rte_Write_APA_slot_ID_3_P0_X_APA_slot_ID_3_P0_X User Code end*/
    Rte_Write_APA_slot_ID_3_P0_Y_APA_slot_ID_3_P0_Y(Write_APA_slot_ID_3_P0_Y_APA_slot_ID_3_P0_Y);
    /* Rte_Write_APA_slot_ID_3_P0_Y_APA_slot_ID_3_P0_Y User Code start*/

    /* Rte_Write_APA_slot_ID_3_P0_Y_APA_slot_ID_3_P0_Y User Code end*/
    Rte_Write_APA_slot_ID_3_P1_X_APA_slot_ID_3_P1_X(Write_APA_slot_ID_3_P1_X_APA_slot_ID_3_P1_X);
    /* Rte_Write_APA_slot_ID_3_P1_X_APA_slot_ID_3_P1_X User Code start*/

    /* Rte_Write_APA_slot_ID_3_P1_X_APA_slot_ID_3_P1_X User Code end*/
    Rte_Write_APA_slot_ID_3_P1_Y_APA_slot_ID_3_P1_Y(Write_APA_slot_ID_3_P1_Y_APA_slot_ID_3_P1_Y);
    /* Rte_Write_APA_slot_ID_3_P1_Y_APA_slot_ID_3_P1_Y User Code start*/

    /* Rte_Write_APA_slot_ID_3_P1_Y_APA_slot_ID_3_P1_Y User Code end*/
    Rte_Write_APA_slot_ID_3_P2_X_APA_slot_ID_3_P2_X(Write_APA_slot_ID_3_P2_X_APA_slot_ID_3_P2_X);
    /* Rte_Write_APA_slot_ID_3_P2_X_APA_slot_ID_3_P2_X User Code start*/

    /* Rte_Write_APA_slot_ID_3_P2_X_APA_slot_ID_3_P2_X User Code end*/
    Rte_Write_APA_slot_ID_3_P2_Y_APA_slot_ID_3_P2_Y(Write_APA_slot_ID_3_P2_Y_APA_slot_ID_3_P2_Y);
    /* Rte_Write_APA_slot_ID_3_P2_Y_APA_slot_ID_3_P2_Y User Code start*/

    /* Rte_Write_APA_slot_ID_3_P2_Y_APA_slot_ID_3_P2_Y User Code end*/
    Rte_Write_APA_slot_ID_3_P3_X_APA_slot_ID_3_P3_X(Write_APA_slot_ID_3_P3_X_APA_slot_ID_3_P3_X);
    /* Rte_Write_APA_slot_ID_3_P3_X_APA_slot_ID_3_P3_X User Code start*/

    /* Rte_Write_APA_slot_ID_3_P3_X_APA_slot_ID_3_P3_X User Code end*/
    Rte_Write_APA_slot_ID_3_P3_Y_APA_slot_ID_3_P3_Y(Write_APA_slot_ID_3_P3_Y_APA_slot_ID_3_P3_Y);
    /* Rte_Write_APA_slot_ID_3_P3_Y_APA_slot_ID_3_P3_Y User Code start*/

    /* Rte_Write_APA_slot_ID_3_P3_Y_APA_slot_ID_3_P3_Y User Code end*/
    Rte_Write_APA_slot_ID_3_Type_APA_slot_ID_3_Type(Write_APA_slot_ID_3_Type_APA_slot_ID_3_Type);
    /* Rte_Write_APA_slot_ID_3_Type_APA_slot_ID_3_Type User Code start*/

    /* Rte_Write_APA_slot_ID_3_Type_APA_slot_ID_3_Type User Code end*/
    Rte_Write_APA_slot_ID_4_P0_X_APA_slot_ID_4_P0_X(Write_APA_slot_ID_4_P0_X_APA_slot_ID_4_P0_X);
    /* Rte_Write_APA_slot_ID_4_P0_X_APA_slot_ID_4_P0_X User Code start*/

    /* Rte_Write_APA_slot_ID_4_P0_X_APA_slot_ID_4_P0_X User Code end*/
    Rte_Write_APA_slot_ID_4_P0_Y_APA_slot_ID_4_P0_Y(Write_APA_slot_ID_4_P0_Y_APA_slot_ID_4_P0_Y);
    /* Rte_Write_APA_slot_ID_4_P0_Y_APA_slot_ID_4_P0_Y User Code start*/

    /* Rte_Write_APA_slot_ID_4_P0_Y_APA_slot_ID_4_P0_Y User Code end*/
    Rte_Write_APA_slot_ID_4_P1_X_APA_slot_ID_4_P1_X(Write_APA_slot_ID_4_P1_X_APA_slot_ID_4_P1_X);
    /* Rte_Write_APA_slot_ID_4_P1_X_APA_slot_ID_4_P1_X User Code start*/

    /* Rte_Write_APA_slot_ID_4_P1_X_APA_slot_ID_4_P1_X User Code end*/
    Rte_Write_APA_slot_ID_4_P1_Y_APA_slot_ID_4_P1_Y(Write_APA_slot_ID_4_P1_Y_APA_slot_ID_4_P1_Y);
    /* Rte_Write_APA_slot_ID_4_P1_Y_APA_slot_ID_4_P1_Y User Code start*/

    /* Rte_Write_APA_slot_ID_4_P1_Y_APA_slot_ID_4_P1_Y User Code end*/
    Rte_Write_APA_slot_ID_4_P2_X_APA_slot_ID_4_P2_X(Write_APA_slot_ID_4_P2_X_APA_slot_ID_4_P2_X);
    /* Rte_Write_APA_slot_ID_4_P2_X_APA_slot_ID_4_P2_X User Code start*/

    /* Rte_Write_APA_slot_ID_4_P2_X_APA_slot_ID_4_P2_X User Code end*/
    Rte_Write_APA_slot_ID_4_P2_Y_APA_slot_ID_4_P2_Y(Write_APA_slot_ID_4_P2_Y_APA_slot_ID_4_P2_Y);
    /* Rte_Write_APA_slot_ID_4_P2_Y_APA_slot_ID_4_P2_Y User Code start*/

    /* Rte_Write_APA_slot_ID_4_P2_Y_APA_slot_ID_4_P2_Y User Code end*/
    Rte_Write_APA_slot_ID_4_P3_X_APA_slot_ID_4_P3_X(Write_APA_slot_ID_4_P3_X_APA_slot_ID_4_P3_X);
    /* Rte_Write_APA_slot_ID_4_P3_X_APA_slot_ID_4_P3_X User Code start*/

    /* Rte_Write_APA_slot_ID_4_P3_X_APA_slot_ID_4_P3_X User Code end*/
    Rte_Write_APA_slot_ID_4_P3_Y_APA_slot_ID_4_P3_Y(Write_APA_slot_ID_4_P3_Y_APA_slot_ID_4_P3_Y);
    /* Rte_Write_APA_slot_ID_4_P3_Y_APA_slot_ID_4_P3_Y User Code start*/

    /* Rte_Write_APA_slot_ID_4_P3_Y_APA_slot_ID_4_P3_Y User Code end*/
    Rte_Write_APA_slot_ID_4_Type_APA_slot_ID_4_Type(Write_APA_slot_ID_4_Type_APA_slot_ID_4_Type);
    /* Rte_Write_APA_slot_ID_4_Type_APA_slot_ID_4_Type User Code start*/

    /* Rte_Write_APA_slot_ID_4_Type_APA_slot_ID_4_Type User Code end*/
    Rte_Write_APA_slot_ID_5_P0_X_APA_slot_ID_5_P0_X(Write_APA_slot_ID_5_P0_X_APA_slot_ID_5_P0_X);
    /* Rte_Write_APA_slot_ID_5_P0_X_APA_slot_ID_5_P0_X User Code start*/

    /* Rte_Write_APA_slot_ID_5_P0_X_APA_slot_ID_5_P0_X User Code end*/
    Rte_Write_APA_slot_ID_5_P0_Y_APA_slot_ID_5_P0_Y(Write_APA_slot_ID_5_P0_Y_APA_slot_ID_5_P0_Y);
    /* Rte_Write_APA_slot_ID_5_P0_Y_APA_slot_ID_5_P0_Y User Code start*/

    /* Rte_Write_APA_slot_ID_5_P0_Y_APA_slot_ID_5_P0_Y User Code end*/
    Rte_Write_APA_slot_ID_5_P1_X_APA_slot_ID_5_P1_X(Write_APA_slot_ID_5_P1_X_APA_slot_ID_5_P1_X);
    /* Rte_Write_APA_slot_ID_5_P1_X_APA_slot_ID_5_P1_X User Code start*/

    /* Rte_Write_APA_slot_ID_5_P1_X_APA_slot_ID_5_P1_X User Code end*/
    Rte_Write_APA_slot_ID_5_P1_Y_APA_slot_ID_5_P1_Y(Write_APA_slot_ID_5_P1_Y_APA_slot_ID_5_P1_Y);
    /* Rte_Write_APA_slot_ID_5_P1_Y_APA_slot_ID_5_P1_Y User Code start*/

    /* Rte_Write_APA_slot_ID_5_P1_Y_APA_slot_ID_5_P1_Y User Code end*/
    Rte_Write_APA_slot_ID_5_P2_X_APA_slot_ID_5_P2_X(Write_APA_slot_ID_5_P2_X_APA_slot_ID_5_P2_X);
    /* Rte_Write_APA_slot_ID_5_P2_X_APA_slot_ID_5_P2_X User Code start*/

    /* Rte_Write_APA_slot_ID_5_P2_X_APA_slot_ID_5_P2_X User Code end*/
    Rte_Write_APA_slot_ID_5_P2_Y_APA_slot_ID_5_P2_Y(Write_APA_slot_ID_5_P2_Y_APA_slot_ID_5_P2_Y);
    /* Rte_Write_APA_slot_ID_5_P2_Y_APA_slot_ID_5_P2_Y User Code start*/

    /* Rte_Write_APA_slot_ID_5_P2_Y_APA_slot_ID_5_P2_Y User Code end*/
    Rte_Write_APA_slot_ID_5_P3_X_APA_slot_ID_5_P3_X(Write_APA_slot_ID_5_P3_X_APA_slot_ID_5_P3_X);
    /* Rte_Write_APA_slot_ID_5_P3_X_APA_slot_ID_5_P3_X User Code start*/

    /* Rte_Write_APA_slot_ID_5_P3_X_APA_slot_ID_5_P3_X User Code end*/
    Rte_Write_APA_slot_ID_5_P3_Y_APA_slot_ID_5_P3_Y(Write_APA_slot_ID_5_P3_Y_APA_slot_ID_5_P3_Y);
    /* Rte_Write_APA_slot_ID_5_P3_Y_APA_slot_ID_5_P3_Y User Code start*/

    /* Rte_Write_APA_slot_ID_5_P3_Y_APA_slot_ID_5_P3_Y User Code end*/
    Rte_Write_APA_slot_ID_5_Type_APA_slot_ID_5_Type(Write_APA_slot_ID_5_Type_APA_slot_ID_5_Type);
    /* Rte_Write_APA_slot_ID_5_Type_APA_slot_ID_5_Type User Code start*/

    /* Rte_Write_APA_slot_ID_5_Type_APA_slot_ID_5_Type User Code end*/
    Rte_Write_APA_slot_ID_6_P0_X_APA_slot_ID_6_P0_X(Write_APA_slot_ID_6_P0_X_APA_slot_ID_6_P0_X);
    /* Rte_Write_APA_slot_ID_6_P0_X_APA_slot_ID_6_P0_X User Code start*/

    /* Rte_Write_APA_slot_ID_6_P0_X_APA_slot_ID_6_P0_X User Code end*/
    Rte_Write_APA_slot_ID_6_P0_Y_APA_slot_ID_6_P0_Y(Write_APA_slot_ID_6_P0_Y_APA_slot_ID_6_P0_Y);
    /* Rte_Write_APA_slot_ID_6_P0_Y_APA_slot_ID_6_P0_Y User Code start*/

    /* Rte_Write_APA_slot_ID_6_P0_Y_APA_slot_ID_6_P0_Y User Code end*/
    Rte_Write_APA_slot_ID_6_P1_X_APA_slot_ID_6_P1_X(Write_APA_slot_ID_6_P1_X_APA_slot_ID_6_P1_X);
    /* Rte_Write_APA_slot_ID_6_P1_X_APA_slot_ID_6_P1_X User Code start*/

    /* Rte_Write_APA_slot_ID_6_P1_X_APA_slot_ID_6_P1_X User Code end*/
    Rte_Write_APA_slot_ID_6_P1_Y_APA_slot_ID_6_P1_Y(Write_APA_slot_ID_6_P1_Y_APA_slot_ID_6_P1_Y);
    /* Rte_Write_APA_slot_ID_6_P1_Y_APA_slot_ID_6_P1_Y User Code start*/

    /* Rte_Write_APA_slot_ID_6_P1_Y_APA_slot_ID_6_P1_Y User Code end*/
    Rte_Write_APA_slot_ID_6_P2_X_APA_slot_ID_6_P2_X(Write_APA_slot_ID_6_P2_X_APA_slot_ID_6_P2_X);
    /* Rte_Write_APA_slot_ID_6_P2_X_APA_slot_ID_6_P2_X User Code start*/

    /* Rte_Write_APA_slot_ID_6_P2_X_APA_slot_ID_6_P2_X User Code end*/
    Rte_Write_APA_slot_ID_6_P2_Y_APA_slot_ID_6_P2_Y(Write_APA_slot_ID_6_P2_Y_APA_slot_ID_6_P2_Y);
    /* Rte_Write_APA_slot_ID_6_P2_Y_APA_slot_ID_6_P2_Y User Code start*/

    /* Rte_Write_APA_slot_ID_6_P2_Y_APA_slot_ID_6_P2_Y User Code end*/
    Rte_Write_APA_slot_ID_6_P3_X_APA_slot_ID_6_P3_X(Write_APA_slot_ID_6_P3_X_APA_slot_ID_6_P3_X);
    /* Rte_Write_APA_slot_ID_6_P3_X_APA_slot_ID_6_P3_X User Code start*/

    /* Rte_Write_APA_slot_ID_6_P3_X_APA_slot_ID_6_P3_X User Code end*/
    Rte_Write_APA_slot_ID_6_P3_Y_APA_slot_ID_6_P3_Y(Write_APA_slot_ID_6_P3_Y_APA_slot_ID_6_P3_Y);
    /* Rte_Write_APA_slot_ID_6_P3_Y_APA_slot_ID_6_P3_Y User Code start*/

    /* Rte_Write_APA_slot_ID_6_P3_Y_APA_slot_ID_6_P3_Y User Code end*/
    Rte_Write_APA_slot_ID_6_Type_APA_slot_ID_6_Type(Write_APA_slot_ID_6_Type_APA_slot_ID_6_Type);
    /* Rte_Write_APA_slot_ID_6_Type_APA_slot_ID_6_Type User Code start*/

    /* Rte_Write_APA_slot_ID_6_Type_APA_slot_ID_6_Type User Code end*/
    Rte_Write_APA_slot_ID_7_P0_X_APA_slot_ID_7_P0_X(Write_APA_slot_ID_7_P0_X_APA_slot_ID_7_P0_X);
    /* Rte_Write_APA_slot_ID_7_P0_X_APA_slot_ID_7_P0_X User Code start*/

    /* Rte_Write_APA_slot_ID_7_P0_X_APA_slot_ID_7_P0_X User Code end*/
    Rte_Write_APA_slot_ID_7_P0_Y_APA_slot_ID_7_P0_Y(Write_APA_slot_ID_7_P0_Y_APA_slot_ID_7_P0_Y);
    /* Rte_Write_APA_slot_ID_7_P0_Y_APA_slot_ID_7_P0_Y User Code start*/

    /* Rte_Write_APA_slot_ID_7_P0_Y_APA_slot_ID_7_P0_Y User Code end*/
    Rte_Write_APA_slot_ID_7_P1_X_APA_slot_ID_7_P1_X(Write_APA_slot_ID_7_P1_X_APA_slot_ID_7_P1_X);
    /* Rte_Write_APA_slot_ID_7_P1_X_APA_slot_ID_7_P1_X User Code start*/

    /* Rte_Write_APA_slot_ID_7_P1_X_APA_slot_ID_7_P1_X User Code end*/
    Rte_Write_APA_slot_ID_7_P1_Y_APA_slot_ID_7_P1_Y(Write_APA_slot_ID_7_P1_Y_APA_slot_ID_7_P1_Y);
    /* Rte_Write_APA_slot_ID_7_P1_Y_APA_slot_ID_7_P1_Y User Code start*/

    /* Rte_Write_APA_slot_ID_7_P1_Y_APA_slot_ID_7_P1_Y User Code end*/
    Rte_Write_APA_slot_ID_7_P2_X_APA_slot_ID_7_P2_X(Write_APA_slot_ID_7_P2_X_APA_slot_ID_7_P2_X);
    /* Rte_Write_APA_slot_ID_7_P2_X_APA_slot_ID_7_P2_X User Code start*/

    /* Rte_Write_APA_slot_ID_7_P2_X_APA_slot_ID_7_P2_X User Code end*/
    Rte_Write_APA_slot_ID_7_P2_Y_APA_slot_ID_7_P2_Y(Write_APA_slot_ID_7_P2_Y_APA_slot_ID_7_P2_Y);
    /* Rte_Write_APA_slot_ID_7_P2_Y_APA_slot_ID_7_P2_Y User Code start*/

    /* Rte_Write_APA_slot_ID_7_P2_Y_APA_slot_ID_7_P2_Y User Code end*/
    Rte_Write_APA_slot_ID_7_P3_X_APA_slot_ID_7_P3_X(Write_APA_slot_ID_7_P3_X_APA_slot_ID_7_P3_X);
    /* Rte_Write_APA_slot_ID_7_P3_X_APA_slot_ID_7_P3_X User Code start*/

    /* Rte_Write_APA_slot_ID_7_P3_X_APA_slot_ID_7_P3_X User Code end*/
    Rte_Write_APA_slot_ID_7_P3_Y_APA_slot_ID_7_P3_Y(Write_APA_slot_ID_7_P3_Y_APA_slot_ID_7_P3_Y);
    /* Rte_Write_APA_slot_ID_7_P3_Y_APA_slot_ID_7_P3_Y User Code start*/

    /* Rte_Write_APA_slot_ID_7_P3_Y_APA_slot_ID_7_P3_Y User Code end*/
    Rte_Write_APA_slot_ID_7_Type_APA_slot_ID_7_Type(Write_APA_slot_ID_7_Type_APA_slot_ID_7_Type);
    /* Rte_Write_APA_slot_ID_7_Type_APA_slot_ID_7_Type User Code start*/

    /* Rte_Write_APA_slot_ID_7_Type_APA_slot_ID_7_Type User Code end*/
    Rte_Write_APA_slot_ID_8_P0_X_APA_slot_ID_8_P0_X(Write_APA_slot_ID_8_P0_X_APA_slot_ID_8_P0_X);
    /* Rte_Write_APA_slot_ID_8_P0_X_APA_slot_ID_8_P0_X User Code start*/

    /* Rte_Write_APA_slot_ID_8_P0_X_APA_slot_ID_8_P0_X User Code end*/
    Rte_Write_APA_slot_ID_8_P0_Y_APA_slot_ID_8_P0_Y(Write_APA_slot_ID_8_P0_Y_APA_slot_ID_8_P0_Y);
    /* Rte_Write_APA_slot_ID_8_P0_Y_APA_slot_ID_8_P0_Y User Code start*/

    /* Rte_Write_APA_slot_ID_8_P0_Y_APA_slot_ID_8_P0_Y User Code end*/
    Rte_Write_APA_slot_ID_8_P1_X_APA_slot_ID_8_P1_X(Write_APA_slot_ID_8_P1_X_APA_slot_ID_8_P1_X);
    /* Rte_Write_APA_slot_ID_8_P1_X_APA_slot_ID_8_P1_X User Code start*/

    /* Rte_Write_APA_slot_ID_8_P1_X_APA_slot_ID_8_P1_X User Code end*/
    Rte_Write_APA_slot_ID_8_P1_Y_APA_slot_ID_8_P1_Y(Write_APA_slot_ID_8_P1_Y_APA_slot_ID_8_P1_Y);
    /* Rte_Write_APA_slot_ID_8_P1_Y_APA_slot_ID_8_P1_Y User Code start*/

    /* Rte_Write_APA_slot_ID_8_P1_Y_APA_slot_ID_8_P1_Y User Code end*/
    Rte_Write_APA_slot_ID_8_P2_X_APA_slot_ID_8_P2_X(Write_APA_slot_ID_8_P2_X_APA_slot_ID_8_P2_X);
    /* Rte_Write_APA_slot_ID_8_P2_X_APA_slot_ID_8_P2_X User Code start*/

    /* Rte_Write_APA_slot_ID_8_P2_X_APA_slot_ID_8_P2_X User Code end*/
    Rte_Write_APA_slot_ID_8_P2_Y_APA_slot_ID_8_P2_Y(Write_APA_slot_ID_8_P2_Y_APA_slot_ID_8_P2_Y);
    /* Rte_Write_APA_slot_ID_8_P2_Y_APA_slot_ID_8_P2_Y User Code start*/

    /* Rte_Write_APA_slot_ID_8_P2_Y_APA_slot_ID_8_P2_Y User Code end*/
    Rte_Write_APA_slot_ID_8_P3_X_APA_slot_ID_8_P3_X(Write_APA_slot_ID_8_P3_X_APA_slot_ID_8_P3_X);
    /* Rte_Write_APA_slot_ID_8_P3_X_APA_slot_ID_8_P3_X User Code start*/

    /* Rte_Write_APA_slot_ID_8_P3_X_APA_slot_ID_8_P3_X User Code end*/
    Rte_Write_APA_slot_ID_8_P3_Y_APA_slot_ID_8_P3_Y(Write_APA_slot_ID_8_P3_Y_APA_slot_ID_8_P3_Y);
    /* Rte_Write_APA_slot_ID_8_P3_Y_APA_slot_ID_8_P3_Y User Code start*/

    /* Rte_Write_APA_slot_ID_8_P3_Y_APA_slot_ID_8_P3_Y User Code end*/
    Rte_Write_APA_slot_ID_8_Type_APA_slot_ID_8_Type(Write_APA_slot_ID_8_Type_APA_slot_ID_8_Type);
    /* Rte_Write_APA_slot_ID_8_Type_APA_slot_ID_8_Type User Code start*/

    /* Rte_Write_APA_slot_ID_8_Type_APA_slot_ID_8_Type User Code end*/
    Rte_Write_APA_slot_ID_9_P0_X_APA_slot_ID_9_P0_X(Write_APA_slot_ID_9_P0_X_APA_slot_ID_9_P0_X);
    /* Rte_Write_APA_slot_ID_9_P0_X_APA_slot_ID_9_P0_X User Code start*/

    /* Rte_Write_APA_slot_ID_9_P0_X_APA_slot_ID_9_P0_X User Code end*/
    Rte_Write_APA_slot_ID_9_P0_Y_APA_slot_ID_9_P0_Y(Write_APA_slot_ID_9_P0_Y_APA_slot_ID_9_P0_Y);
    /* Rte_Write_APA_slot_ID_9_P0_Y_APA_slot_ID_9_P0_Y User Code start*/

    /* Rte_Write_APA_slot_ID_9_P0_Y_APA_slot_ID_9_P0_Y User Code end*/
    Rte_Write_APA_slot_ID_9_P1_X_APA_slot_ID_9_P1_X(Write_APA_slot_ID_9_P1_X_APA_slot_ID_9_P1_X);
    /* Rte_Write_APA_slot_ID_9_P1_X_APA_slot_ID_9_P1_X User Code start*/

    /* Rte_Write_APA_slot_ID_9_P1_X_APA_slot_ID_9_P1_X User Code end*/
    Rte_Write_APA_slot_ID_9_P1_Y_APA_slot_ID_9_P1_Y(Write_APA_slot_ID_9_P1_Y_APA_slot_ID_9_P1_Y);
    /* Rte_Write_APA_slot_ID_9_P1_Y_APA_slot_ID_9_P1_Y User Code start*/

    /* Rte_Write_APA_slot_ID_9_P1_Y_APA_slot_ID_9_P1_Y User Code end*/
    Rte_Write_APA_slot_ID_9_P2_X_APA_slot_ID_9_P2_X(Write_APA_slot_ID_9_P2_X_APA_slot_ID_9_P2_X);
    /* Rte_Write_APA_slot_ID_9_P2_X_APA_slot_ID_9_P2_X User Code start*/

    /* Rte_Write_APA_slot_ID_9_P2_X_APA_slot_ID_9_P2_X User Code end*/
    Rte_Write_APA_slot_ID_9_P2_Y_APA_slot_ID_9_P2_Y(Write_APA_slot_ID_9_P2_Y_APA_slot_ID_9_P2_Y);
    /* Rte_Write_APA_slot_ID_9_P2_Y_APA_slot_ID_9_P2_Y User Code start*/

    /* Rte_Write_APA_slot_ID_9_P2_Y_APA_slot_ID_9_P2_Y User Code end*/
    Rte_Write_APA_slot_ID_9_P3_X_APA_slot_ID_9_P3_X(Write_APA_slot_ID_9_P3_X_APA_slot_ID_9_P3_X);
    /* Rte_Write_APA_slot_ID_9_P3_X_APA_slot_ID_9_P3_X User Code start*/

    /* Rte_Write_APA_slot_ID_9_P3_X_APA_slot_ID_9_P3_X User Code end*/
    Rte_Write_APA_slot_ID_9_P3_Y_APA_slot_ID_9_P3_Y(Write_APA_slot_ID_9_P3_Y_APA_slot_ID_9_P3_Y);
    /* Rte_Write_APA_slot_ID_9_P3_Y_APA_slot_ID_9_P3_Y User Code start*/

    /* Rte_Write_APA_slot_ID_9_P3_Y_APA_slot_ID_9_P3_Y User Code end*/
    Rte_Write_APA_slot_ID_9_Type_APA_slot_ID_9_Type(Write_APA_slot_ID_9_Type_APA_slot_ID_9_Type);
    /* Rte_Write_APA_slot_ID_9_Type_APA_slot_ID_9_Type User Code start*/

    /* Rte_Write_APA_slot_ID_9_Type_APA_slot_ID_9_Type User Code end*/
    Rte_Write_FLC_ExtenedDistance_FLC_ExtenedDistance(Write_FLC_ExtenedDistance_FLC_ExtenedDistance);
    /* Rte_Write_FLC_ExtenedDistance_FLC_ExtenedDistance User Code start*/

    /* Rte_Write_FLC_ExtenedDistance_FLC_ExtenedDistance User Code end*/
    Rte_Write_FLM_ExtenedDistance_FLM_ExtenedDistance(Write_FLM_ExtenedDistance_FLM_ExtenedDistance);
    /* Rte_Write_FLM_ExtenedDistance_FLM_ExtenedDistance User Code start*/

    /* Rte_Write_FLM_ExtenedDistance_FLM_ExtenedDistance User Code end*/
    Rte_Write_FLS_ExtenedDistance_FLS_ExtenedDistance(Write_FLS_ExtenedDistance_FLS_ExtenedDistance);
    /* Rte_Write_FLS_ExtenedDistance_FLS_ExtenedDistance User Code start*/

    /* Rte_Write_FLS_ExtenedDistance_FLS_ExtenedDistance User Code end*/
    Rte_Write_FRC_ExtenedDistance_FRC_ExtenedDistance(Write_FRC_ExtenedDistance_FRC_ExtenedDistance);
    /* Rte_Write_FRC_ExtenedDistance_FRC_ExtenedDistance User Code start*/

    /* Rte_Write_FRC_ExtenedDistance_FRC_ExtenedDistance User Code end*/
    Rte_Write_FRM_ExtenedDistance_FRM_ExtenedDistance(Write_FRM_ExtenedDistance_FRM_ExtenedDistance);
    /* Rte_Write_FRM_ExtenedDistance_FRM_ExtenedDistance User Code start*/

    /* Rte_Write_FRM_ExtenedDistance_FRM_ExtenedDistance User Code end*/
    Rte_Write_FRS_ExtenedDistance_FRS_ExtenedDistance(Write_FRS_ExtenedDistance_FRS_ExtenedDistance);
    /* Rte_Write_FRS_ExtenedDistance_FRS_ExtenedDistance User Code start*/

    /* Rte_Write_FRS_ExtenedDistance_FRS_ExtenedDistance User Code end*/
    Rte_Write_PiCarInfoH_PiCarInfoH(&Write_PiCarInfoH_PiCarInfoH);
    /* Rte_Write_PiCarInfoH_PiCarInfoH User Code start*/

    /* Rte_Write_PiCarInfoH_PiCarInfoH User Code end*/
    Rte_Write_PiCarInfoL_PiCarInfoL(&Write_PiCarInfoL_PiCarInfoL);
    /* Rte_Write_PiCarInfoL_PiCarInfoL User Code start*/

    /* Rte_Write_PiCarInfoL_PiCarInfoL User Code end*/
    Rte_Write_PiImuInfo_PiIMUInfo(&Write_PiImuInfo_PiIMUInfo);
    /* Rte_Write_PiImuInfo_PiIMUInfo User Code start*/

    /* Rte_Write_PiImuInfo_PiIMUInfo User Code end*/
    Rte_Write_PiManualParkingSlotSet_PiManualParkingSlotSet(&Write_PiManualParkingSlotSet_PiManualParkingSlotSet);
    /* Rte_Write_PiManualParkingSlotSet_PiManualParkingSlotSet User Code start*/

    /* Rte_Write_PiManualParkingSlotSet_PiManualParkingSlotSet User Code end*/
    Rte_Write_PiSignalTransWorkingStatus_PiSignalTransWorkingStatus(&Write_PiSignalTransWorkingStatus_PiSignalTransWorkingStatus);
    /* Rte_Write_PiSignalTransWorkingStatus_PiSignalTransWorkingStatus User Code start*/

    /* Rte_Write_PiSignalTransWorkingStatus_PiSignalTransWorkingStatus User Code end*/
    Rte_Write_RLC_ExtenedDistance_RLC_ExtenedDistance(Write_RLC_ExtenedDistance_RLC_ExtenedDistance);
    /* Rte_Write_RLC_ExtenedDistance_RLC_ExtenedDistance User Code start*/

    /* Rte_Write_RLC_ExtenedDistance_RLC_ExtenedDistance User Code end*/
    Rte_Write_RLM_ExtenedDistance_RLM_ExtenedDistance(Write_RLM_ExtenedDistance_RLM_ExtenedDistance);
    /* Rte_Write_RLM_ExtenedDistance_RLM_ExtenedDistance User Code start*/

    /* Rte_Write_RLM_ExtenedDistance_RLM_ExtenedDistance User Code end*/
    Rte_Write_RLS_ExtenedDistance_RLS_ExtenedDistance(Write_RLS_ExtenedDistance_RLS_ExtenedDistance);
    /* Rte_Write_RLS_ExtenedDistance_RLS_ExtenedDistance User Code start*/

    /* Rte_Write_RLS_ExtenedDistance_RLS_ExtenedDistance User Code end*/
    Rte_Write_RRC_ExtenedDistance_RRC_ExtenedDistance(Write_RRC_ExtenedDistance_RRC_ExtenedDistance);
    /* Rte_Write_RRC_ExtenedDistance_RRC_ExtenedDistance User Code start*/

    /* Rte_Write_RRC_ExtenedDistance_RRC_ExtenedDistance User Code end*/
    Rte_Write_RRM_ExtenedDistance_RRM_ExtenedDistance(Write_RRM_ExtenedDistance_RRM_ExtenedDistance);
    /* Rte_Write_RRM_ExtenedDistance_RRM_ExtenedDistance User Code start*/

    /* Rte_Write_RRM_ExtenedDistance_RRM_ExtenedDistance User Code end*/
    Rte_Write_RRS_ExtenedDistance_RRS_ExtenedDistance(Write_RRS_ExtenedDistance_RRS_ExtenedDistance);
    /* Rte_Write_RRS_ExtenedDistance_RRS_ExtenedDistance User Code start*/

    /* Rte_Write_RRS_ExtenedDistance_RRS_ExtenedDistance User Code end*/
    Rte_Read_ABS_FLWheelDirection_ABS_FLWheelDirection(&Read_ABS_FLWheelDirection_ABS_FLWheelDirection);
    /* Rte_Read_ABS_FLWheelDirection_ABS_FLWheelDirection User Code start*/

    /* Rte_Read_ABS_FLWheelDirection_ABS_FLWheelDirection User Code end*/
    Rte_Read_ABS_FLWheelSpeedKPH_ABS_FLWheelSpeedKPH(&Read_ABS_FLWheelSpeedKPH_ABS_FLWheelSpeedKPH);
    /* Rte_Read_ABS_FLWheelSpeedKPH_ABS_FLWheelSpeedKPH User Code start*/

    /* Rte_Read_ABS_FLWheelSpeedKPH_ABS_FLWheelSpeedKPH User Code end*/
    Rte_Read_ABS_FLWheelSpeedRC_ABS_FLWheelSpeedRC(&Read_ABS_FLWheelSpeedRC_ABS_FLWheelSpeedRC);
    /* Rte_Read_ABS_FLWheelSpeedRC_ABS_FLWheelSpeedRC User Code start*/

    /* Rte_Read_ABS_FLWheelSpeedRC_ABS_FLWheelSpeedRC User Code end*/
    Rte_Read_ABS_FRWheelDirection_ABS_FRWheelDirection(&Read_ABS_FRWheelDirection_ABS_FRWheelDirection);
    /* Rte_Read_ABS_FRWheelDirection_ABS_FRWheelDirection User Code start*/

    /* Rte_Read_ABS_FRWheelDirection_ABS_FRWheelDirection User Code end*/
    Rte_Read_ABS_FRWheelSpeedKPH_ABS_FRWheelSpeedKPH(&Read_ABS_FRWheelSpeedKPH_ABS_FRWheelSpeedKPH);
    /* Rte_Read_ABS_FRWheelSpeedKPH_ABS_FRWheelSpeedKPH User Code start*/

    /* Rte_Read_ABS_FRWheelSpeedKPH_ABS_FRWheelSpeedKPH User Code end*/
    Rte_Read_ABS_FRWheelSpeedRC_ABS_FRWheelSpeedRC(&Read_ABS_FRWheelSpeedRC_ABS_FRWheelSpeedRC);
    /* Rte_Read_ABS_FRWheelSpeedRC_ABS_FRWheelSpeedRC User Code start*/

    /* Rte_Read_ABS_FRWheelSpeedRC_ABS_FRWheelSpeedRC User Code end*/
    Rte_Read_ABS_RLWheelDirection_ABS_RLWheelDirection(&Read_ABS_RLWheelDirection_ABS_RLWheelDirection);
    /* Rte_Read_ABS_RLWheelDirection_ABS_RLWheelDirection User Code start*/

    /* Rte_Read_ABS_RLWheelDirection_ABS_RLWheelDirection User Code end*/
    Rte_Read_ABS_RLWheelSpeedKPH_ABS_RLWheelSpeedKPH(&Read_ABS_RLWheelSpeedKPH_ABS_RLWheelSpeedKPH);
    /* Rte_Read_ABS_RLWheelSpeedKPH_ABS_RLWheelSpeedKPH User Code start*/

    /* Rte_Read_ABS_RLWheelSpeedKPH_ABS_RLWheelSpeedKPH User Code end*/
    Rte_Read_ABS_RLWheelSpeedRC_ABS_RLWheelSpeedRC(&Read_ABS_RLWheelSpeedRC_ABS_RLWheelSpeedRC);
    /* Rte_Read_ABS_RLWheelSpeedRC_ABS_RLWheelSpeedRC User Code start*/

    /* Rte_Read_ABS_RLWheelSpeedRC_ABS_RLWheelSpeedRC User Code end*/
    Rte_Read_ABS_RRWheelDirection_ABS_RRWheelDirection(&Read_ABS_RRWheelDirection_ABS_RRWheelDirection);
    /* Rte_Read_ABS_RRWheelDirection_ABS_RRWheelDirection User Code start*/

    /* Rte_Read_ABS_RRWheelDirection_ABS_RRWheelDirection User Code end*/
    Rte_Read_ABS_RRWheelSpeedKPH_ABS_RRWheelSpeedKPH(&Read_ABS_RRWheelSpeedKPH_ABS_RRWheelSpeedKPH);
    /* Rte_Read_ABS_RRWheelSpeedKPH_ABS_RRWheelSpeedKPH User Code start*/

    /* Rte_Read_ABS_RRWheelSpeedKPH_ABS_RRWheelSpeedKPH User Code end*/
    Rte_Read_ABS_RRWheelSpeedRC_ABS_RRWheelSpeedRC(&Read_ABS_RRWheelSpeedRC_ABS_RRWheelSpeedRC);
    /* Rte_Read_ABS_RRWheelSpeedRC_ABS_RRWheelSpeedRC User Code start*/

    /* Rte_Read_ABS_RRWheelSpeedRC_ABS_RRWheelSpeedRC User Code end*/
    Rte_Read_ABS_VehicleSpeed_ABS_VehicleSpeed(&Read_ABS_VehicleSpeed_ABS_VehicleSpeed);
    /* Rte_Read_ABS_VehicleSpeed_ABS_VehicleSpeed User Code start*/

    /* Rte_Read_ABS_VehicleSpeed_ABS_VehicleSpeed User Code end*/
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
    Rte_Read_BCM_CodriversSideDoorAjarSts_BCM_CodriversSideDoorAjarSts(&Read_BCM_CodriversSideDoorAjarSts_BCM_CodriversSideDoorAjarSts);
    /* Rte_Read_BCM_CodriversSideDoorAjarSts_BCM_CodriversSideDoorAjarSts User Code start*/

    /* Rte_Read_BCM_CodriversSideDoorAjarSts_BCM_CodriversSideDoorAjarSts User Code end*/
    Rte_Read_BCM_CoverAjarStatus_BCM_CoverAjarStatus(&Read_BCM_CoverAjarStatus_BCM_CoverAjarStatus);
    /* Rte_Read_BCM_CoverAjarStatus_BCM_CoverAjarStatus User Code start*/

    /* Rte_Read_BCM_CoverAjarStatus_BCM_CoverAjarStatus User Code end*/
    Rte_Read_BCM_DriverSideDoorAjarSts_BCM_DriverSideDoorAjarSts(&Read_BCM_DriverSideDoorAjarSts_BCM_DriverSideDoorAjarSts);
    /* Rte_Read_BCM_DriverSideDoorAjarSts_BCM_DriverSideDoorAjarSts User Code start*/

    /* Rte_Read_BCM_DriverSideDoorAjarSts_BCM_DriverSideDoorAjarSts User Code end*/
    Rte_Read_BCM_RearLeftDoorAjarStatus_BCM_RearLeftDoorAjarStatus(&Read_BCM_RearLeftDoorAjarStatus_BCM_RearLeftDoorAjarStatus);
    /* Rte_Read_BCM_RearLeftDoorAjarStatus_BCM_RearLeftDoorAjarStatus User Code start*/

    /* Rte_Read_BCM_RearLeftDoorAjarStatus_BCM_RearLeftDoorAjarStatus User Code end*/
    Rte_Read_BCM_RearRightDoorAjarStatus_BCM_RearRightDoorAjarStatus(&Read_BCM_RearRightDoorAjarStatus_BCM_RearRightDoorAjarStatus);
    /* Rte_Read_BCM_RearRightDoorAjarStatus_BCM_RearRightDoorAjarStatus User Code start*/

    /* Rte_Read_BCM_RearRightDoorAjarStatus_BCM_RearRightDoorAjarStatus User Code end*/
    Rte_Read_BCM_TrunckAjarStatus_BCM_TrunckAjarStatus(&Read_BCM_TrunckAjarStatus_BCM_TrunckAjarStatus);
    /* Rte_Read_BCM_TrunckAjarStatus_BCM_TrunckAjarStatus User Code start*/

    /* Rte_Read_BCM_TrunckAjarStatus_BCM_TrunckAjarStatus User Code end*/
    Rte_Read_CCU_ExternalTemperature_CCU_ExternalTemperature(&Read_CCU_ExternalTemperature_CCU_ExternalTemperature);
    /* Rte_Read_CCU_ExternalTemperature_CCU_ExternalTemperature User Code start*/

    /* Rte_Read_CCU_ExternalTemperature_CCU_ExternalTemperature User Code end*/
    Rte_Read_EPB_Sts_EPB_Sts(&Read_EPB_Sts_EPB_Sts);
    /* Rte_Read_EPB_Sts_EPB_Sts User Code start*/

    /* Rte_Read_EPB_Sts_EPB_Sts User Code end*/
    Rte_Read_EPS_APA_CtrlAbortFeedback_EPS_APA_CtrlAbortFeedback(&Read_EPS_APA_CtrlAbortFeedback_EPS_APA_CtrlAbortFeedback);
    /* Rte_Read_EPS_APA_CtrlAbortFeedback_EPS_APA_CtrlAbortFeedback User Code start*/

    /* Rte_Read_EPS_APA_CtrlAbortFeedback_EPS_APA_CtrlAbortFeedback User Code end*/
    Rte_Read_EPS_APA_ModActv_EPS_APA_ModActv(&Read_EPS_APA_ModActv_EPS_APA_ModActv);
    /* Rte_Read_EPS_APA_ModActv_EPS_APA_ModActv User Code start*/

    /* Rte_Read_EPS_APA_ModActv_EPS_APA_ModActv User Code end*/
    Rte_Read_EPS_APA_ModAvail_EPS_APA_ModAvail(&Read_EPS_APA_ModAvail_EPS_APA_ModAvail);
    /* Rte_Read_EPS_APA_ModAvail_EPS_APA_ModAvail User Code start*/

    /* Rte_Read_EPS_APA_ModAvail_EPS_APA_ModAvail User Code end*/
    Rte_Read_EPS_DrStrTorqVal_EPS_DrStrTorqVal(&Read_EPS_DrStrTorqVal_EPS_DrStrTorqVal);
    /* Rte_Read_EPS_DrStrTorqVal_EPS_DrStrTorqVal User Code start*/

    /* Rte_Read_EPS_DrStrTorqVal_EPS_DrStrTorqVal User Code end*/
    Rte_Read_ESC_LateralACC_ESC_LateralACC(&Read_ESC_LateralACC_ESC_LateralACC);
    /* Rte_Read_ESC_LateralACC_ESC_LateralACC User Code start*/

    /* Rte_Read_ESC_LateralACC_ESC_LateralACC User Code end*/
    Rte_Read_ESC_LongitudeACC_ESC_LongitudeACC(&Read_ESC_LongitudeACC_ESC_LongitudeACC);
    /* Rte_Read_ESC_LongitudeACC_ESC_LongitudeACC User Code start*/

    /* Rte_Read_ESC_LongitudeACC_ESC_LongitudeACC User Code end*/
    Rte_Read_ESC_MasterCylinderPressure_ESC_MasterCylinderPressure(&Read_ESC_MasterCylinderPressure_ESC_MasterCylinderPressure);
    /* Rte_Read_ESC_MasterCylinderPressure_ESC_MasterCylinderPressure User Code start*/

    /* Rte_Read_ESC_MasterCylinderPressure_ESC_MasterCylinderPressure User Code end*/
    Rte_Read_ESC_SlopeGradeAngle_ESC_SlopeGradeAngle(&Read_ESC_SlopeGradeAngle_ESC_SlopeGradeAngle);
    /* Rte_Read_ESC_SlopeGradeAngle_ESC_SlopeGradeAngle User Code start*/

    /* Rte_Read_ESC_SlopeGradeAngle_ESC_SlopeGradeAngle User Code end*/
    Rte_Read_ESC_VehDynYawRate_ESC_VehDynYawRate(&Read_ESC_VehDynYawRate_ESC_VehDynYawRate);
    /* Rte_Read_ESC_VehDynYawRate_ESC_VehDynYawRate User Code start*/

    /* Rte_Read_ESC_VehDynYawRate_ESC_VehDynYawRate User Code end*/
    Rte_Read_MHU_APA_ParkingSpace_ID_MHU_APA_ParkingSpace_ID(&Read_MHU_APA_ParkingSpace_ID_MHU_APA_ParkingSpace_ID);
    /* Rte_Read_MHU_APA_ParkingSpace_ID_MHU_APA_ParkingSpace_ID User Code start*/

    /* Rte_Read_MHU_APA_ParkingSpace_ID_MHU_APA_ParkingSpace_ID User Code end*/
    Rte_Read_MHU_UPAMuteSwitch_MHU_UPAMuteSwitch(&Read_MHU_UPAMuteSwitch_MHU_UPAMuteSwitch);
    /* Rte_Read_MHU_UPAMuteSwitch_MHU_UPAMuteSwitch User Code start*/

    /* Rte_Read_MHU_UPAMuteSwitch_MHU_UPAMuteSwitch User Code end*/
    Rte_Read_PEPS_IGN1RelaySts_PEPS_IGN1RelaySts(&Read_PEPS_IGN1RelaySts_PEPS_IGN1RelaySts);
    /* Rte_Read_PEPS_IGN1RelaySts_PEPS_IGN1RelaySts User Code start*/

    /* Rte_Read_PEPS_IGN1RelaySts_PEPS_IGN1RelaySts User Code end*/
    Rte_Read_PEPS_PowerMode_PEPS_PowerMode(&Read_PEPS_PowerMode_PEPS_PowerMode);
    /* Rte_Read_PEPS_PowerMode_PEPS_PowerMode User Code start*/

    /* Rte_Read_PEPS_PowerMode_PEPS_PowerMode User Code end*/
    Rte_Read_PiAvmFusionParkingSlot_PiAvmFusionParkingSlot(&Read_PiAvmFusionParkingSlot_PiAvmFusionParkingSlot);
    /* Rte_Read_PiAvmFusionParkingSlot_PiAvmFusionParkingSlot User Code start*/

    /* Rte_Read_PiAvmFusionParkingSlot_PiAvmFusionParkingSlot User Code end*/
    Rte_Read_PiCarControlCommandH_PiCarControlCommandH(&Read_PiCarControlCommandH_PiCarControlCommandH);
    /* Rte_Read_PiCarControlCommandH_PiCarControlCommandH User Code start*/

    /* Rte_Read_PiCarControlCommandH_PiCarControlCommandH User Code end*/
    Rte_Read_PiCarControlCommandL_PiCarControlCommandL(&Read_PiCarControlCommandL_PiCarControlCommandL);
    /* Rte_Read_PiCarControlCommandL_PiCarControlCommandL User Code start*/

    /* Rte_Read_PiCarControlCommandL_PiCarControlCommandL User Code end*/
    Rte_Read_PiGuideLine_PiGuideLine(&Read_PiGuideLine_PiGuideLine);
    /* Rte_Read_PiGuideLine_PiGuideLine User Code start*/

    /* Rte_Read_PiGuideLine_PiGuideLine User Code end*/
    Rte_Read_PiUssPdcInfo_PiUssPdcInfo(&Read_PiUssPdcInfo_PiUssPdcInfo);
    /* Rte_Read_PiUssPdcInfo_PiUssPdcInfo User Code start*/

    /* Rte_Read_PiUssPdcInfo_PiUssPdcInfo User Code end*/
    Rte_Read_SAS_SteerWheelAngle_SAS_SteerWheelAngle(&Read_SAS_SteerWheelAngle_SAS_SteerWheelAngle);
    /* Rte_Read_SAS_SteerWheelAngle_SAS_SteerWheelAngle User Code start*/

    /* Rte_Read_SAS_SteerWheelAngle_SAS_SteerWheelAngle User Code end*/
    Rte_Read_SAS_SteerWhlRotSpdStatus_SAS_SteerWhlRotSpdStatus(&Read_SAS_SteerWhlRotSpdStatus_SAS_SteerWhlRotSpdStatus);
    /* Rte_Read_SAS_SteerWhlRotSpdStatus_SAS_SteerWhlRotSpdStatus User Code start*/

    /* Rte_Read_SAS_SteerWhlRotSpdStatus_SAS_SteerWhlRotSpdStatus User Code end*/
    Rte_Read_SAS_SteerWhlRotSpd_SAS_SteerWhlRotSpd(&Read_SAS_SteerWhlRotSpd_SAS_SteerWhlRotSpd);
    /* Rte_Read_SAS_SteerWhlRotSpd_SAS_SteerWhlRotSpd User Code start*/

    /* Rte_Read_SAS_SteerWhlRotSpd_SAS_SteerWhlRotSpd User Code end*/
    Rte_Read_TPMS_LFpressureSts_TPMS_LFpressureSts(&Read_TPMS_LFpressureSts_TPMS_LFpressureSts);
    /* Rte_Read_TPMS_LFpressureSts_TPMS_LFpressureSts User Code start*/

    /* Rte_Read_TPMS_LFpressureSts_TPMS_LFpressureSts User Code end*/
    Rte_Read_TPMS_LFpressure_TPMS_LFpressure(&Read_TPMS_LFpressure_TPMS_LFpressure);
    /* Rte_Read_TPMS_LFpressure_TPMS_LFpressure User Code start*/

    /* Rte_Read_TPMS_LFpressure_TPMS_LFpressure User Code end*/
    Rte_Read_TPMS_LRpressureSts_TPMS_LRpressureSts(&Read_TPMS_LRpressureSts_TPMS_LRpressureSts);
    /* Rte_Read_TPMS_LRpressureSts_TPMS_LRpressureSts User Code start*/

    /* Rte_Read_TPMS_LRpressureSts_TPMS_LRpressureSts User Code end*/
    Rte_Read_TPMS_LRpressure_TPMS_LRpressure(&Read_TPMS_LRpressure_TPMS_LRpressure);
    /* Rte_Read_TPMS_LRpressure_TPMS_LRpressure User Code start*/

    /* Rte_Read_TPMS_LRpressure_TPMS_LRpressure User Code end*/
    Rte_Read_TPMS_RFpressureSts_TPMS_RFpressureSts(&Read_TPMS_RFpressureSts_TPMS_RFpressureSts);
    /* Rte_Read_TPMS_RFpressureSts_TPMS_RFpressureSts User Code start*/

    /* Rte_Read_TPMS_RFpressureSts_TPMS_RFpressureSts User Code end*/
    Rte_Read_TPMS_RFpressure_TPMS_RFpressure(&Read_TPMS_RFpressure_TPMS_RFpressure);
    /* Rte_Read_TPMS_RFpressure_TPMS_RFpressure User Code start*/

    /* Rte_Read_TPMS_RFpressure_TPMS_RFpressure User Code end*/
    Rte_Read_TPMS_RRpressureSts_TPMS_RRpressureSts(&Read_TPMS_RRpressureSts_TPMS_RRpressureSts);
    /* Rte_Read_TPMS_RRpressureSts_TPMS_RRpressureSts User Code start*/

    /* Rte_Read_TPMS_RRpressureSts_TPMS_RRpressureSts User Code end*/
    Rte_Read_TPMS_RRpressure_TPMS_RRpressure(&Read_TPMS_RRpressure_TPMS_RRpressure);
    /* Rte_Read_TPMS_RRpressure_TPMS_RRpressure User Code start*/

    /* Rte_Read_TPMS_RRpressure_TPMS_RRpressure User Code end*/
    Rte_Read_TimeStamp_ABS_FrontWheelSpeMCUKPH_0x122_TimeStamp_ABS_FrontWheelSpeMCUKPH_0x122(&Read_TimeStamp_ABS_FrontWheelSpeMCUKPH_0x122_TimeStamp_ABS_FrontWheelSpeMCUKPH_0x122);
    /* Rte_Read_TimeStamp_ABS_FrontWheelSpeMCUKPH_0x122_TimeStamp_ABS_FrontWheelSpeMCUKPH_0x122 User Code start*/

    /* Rte_Read_TimeStamp_ABS_FrontWheelSpeMCUKPH_0x122_TimeStamp_ABS_FrontWheelSpeMCUKPH_0x122 User Code end*/
    Rte_Read_TimeStamp_ABS_RearWheelSpeMCUKPH_0x123_TimeStamp_ABS_RearWheelSpeMCUKPH_0x123(&Read_TimeStamp_ABS_RearWheelSpeMCUKPH_0x123_TimeStamp_ABS_RearWheelSpeMCUKPH_0x123);
    /* Rte_Read_TimeStamp_ABS_RearWheelSpeMCUKPH_0x123_TimeStamp_ABS_RearWheelSpeMCUKPH_0x123 User Code start*/

    /* Rte_Read_TimeStamp_ABS_RearWheelSpeMCUKPH_0x123_TimeStamp_ABS_RearWheelSpeMCUKPH_0x123 User Code end*/
    Rte_Read_TimeStamp_ABS_Status_0x125_TimeStamp_ABS_Status_0x125(&Read_TimeStamp_ABS_Status_0x125_TimeStamp_ABS_Status_0x125);
    /* Rte_Read_TimeStamp_ABS_Status_0x125_TimeStamp_ABS_Status_0x125 User Code start*/

    /* Rte_Read_TimeStamp_ABS_Status_0x125_TimeStamp_ABS_Status_0x125 User Code end*/
    Rte_Read_TimeStamp_ABS_WheelSpeedRC_0x124_TimeStamp_ABS_WheelSpeedRC_0x124(&Read_TimeStamp_ABS_WheelSpeedRC_0x124_TimeStamp_ABS_WheelSpeedRC_0x124);
    /* Rte_Read_TimeStamp_ABS_WheelSpeedRC_0x124_TimeStamp_ABS_WheelSpeedRC_0x124 User Code start*/

    /* Rte_Read_TimeStamp_ABS_WheelSpeedRC_0x124_TimeStamp_ABS_WheelSpeedRC_0x124 User Code end*/
    Rte_Read_TimeStamp_ESC_YawAngle_0x3E2_TimeStamp_ESC_YawAngle_0x3E2(&Read_TimeStamp_ESC_YawAngle_0x3E2_TimeStamp_ESC_YawAngle_0x3E2);
    /* Rte_Read_TimeStamp_ESC_YawAngle_0x3E2_TimeStamp_ESC_YawAngle_0x3E2 User Code start*/

    /* Rte_Read_TimeStamp_ESC_YawAngle_0x3E2_TimeStamp_ESC_YawAngle_0x3E2 User Code end*/
    Rte_Read_TimeStamp_IBS_ADAS_Info_0x269_TimeStamp_IBS_ADAS_Info_0x269(&Read_TimeStamp_IBS_ADAS_Info_0x269_TimeStamp_IBS_ADAS_Info_0x269);
    /* Rte_Read_TimeStamp_IBS_ADAS_Info_0x269_TimeStamp_IBS_ADAS_Info_0x269 User Code start*/

    /* Rte_Read_TimeStamp_IBS_ADAS_Info_0x269_TimeStamp_IBS_ADAS_Info_0x269 User Code end*/
    Rte_Read_TimeStamp_SAS_Sensor_0x17E_TimeStamp_SAS_Sensor_0x17E(&Read_TimeStamp_SAS_Sensor_0x17E_TimeStamp_SAS_Sensor_0x17E);
    /* Rte_Read_TimeStamp_SAS_Sensor_0x17E_TimeStamp_SAS_Sensor_0x17E User Code start*/

    /* Rte_Read_TimeStamp_SAS_Sensor_0x17E_TimeStamp_SAS_Sensor_0x17E User Code end*/
    Rte_Read_TimeStamp_VCU_Ctrl_0x162_TimeStamp_VCU_Ctrl_0x162(&Read_TimeStamp_VCU_Ctrl_0x162_TimeStamp_VCU_Ctrl_0x162);
    /* Rte_Read_TimeStamp_VCU_Ctrl_0x162_TimeStamp_VCU_Ctrl_0x162 User Code start*/

    /* Rte_Read_TimeStamp_VCU_Ctrl_0x162_TimeStamp_VCU_Ctrl_0x162 User Code end*/
    Rte_Read_VCU_AccPedalPosition_VCU_AccPedalPosition(&Read_VCU_AccPedalPosition_VCU_AccPedalPosition);
    /* Rte_Read_VCU_AccPedalPosition_VCU_AccPedalPosition User Code start*/

    /* Rte_Read_VCU_AccPedalPosition_VCU_AccPedalPosition User Code end*/
    Rte_Read_VCU_ModeGearSts_VCU_ModeGearSts(&Read_VCU_ModeGearSts_VCU_ModeGearSts);
    /* Rte_Read_VCU_ModeGearSts_VCU_ModeGearSts User Code start*/

    /* Rte_Read_VCU_ModeGearSts_VCU_ModeGearSts User Code end*/
    Rte_Read_VCU_StsSysFault_VCU_StsSysFault(&Read_VCU_StsSysFault_VCU_StsSysFault);
    /* Rte_Read_VCU_StsSysFault_VCU_StsSysFault User Code start*/

    /* Rte_Read_VCU_StsSysFault_VCU_StsSysFault User Code end*/
    Rte_Read_WCBS_APA_CDD_Active_WCBS_APA_CDD_Active(&Read_WCBS_APA_CDD_Active_WCBS_APA_CDD_Active);
    /* Rte_Read_WCBS_APA_CDD_Active_WCBS_APA_CDD_Active User Code start*/

    /* Rte_Read_WCBS_APA_CDD_Active_WCBS_APA_CDD_Active User Code end*/
    Rte_Read_WCBS_APA_VLC_Active_WCBS_APA_VLC_Active(&Read_WCBS_APA_VLC_Active_WCBS_APA_VLC_Active);
    /* Rte_Read_WCBS_APA_VLC_Active_WCBS_APA_VLC_Active User Code start*/

    /* Rte_Read_WCBS_APA_VLC_Active_WCBS_APA_VLC_Active User Code end*/
    Rte_Read_WCBS_APA_VLC_Available_WCBS_APA_VLC_Available(&Read_WCBS_APA_VLC_Available_WCBS_APA_VLC_Available);
    /* Rte_Read_WCBS_APA_VLC_Available_WCBS_APA_VLC_Available User Code start*/

    /* Rte_Read_WCBS_APA_VLC_Available_WCBS_APA_VLC_Available User Code end*/
    Rte_Read_WCBS_APA_VLC_FailureStatus_WCBS_APA_VLC_FailureStatus(&Read_WCBS_APA_VLC_FailureStatus_WCBS_APA_VLC_FailureStatus);
    /* Rte_Read_WCBS_APA_VLC_FailureStatus_WCBS_APA_VLC_FailureStatus User Code start*/

    /* Rte_Read_WCBS_APA_VLC_FailureStatus_WCBS_APA_VLC_FailureStatus User Code end*/
    Rte_Read_WCBS_APA_VLC_Status_WCBS_APA_VLC_Status(&Read_WCBS_APA_VLC_Status_WCBS_APA_VLC_Status);
    /* Rte_Read_WCBS_APA_VLC_Status_WCBS_APA_VLC_Status User Code start*/

    /* Rte_Read_WCBS_APA_VLC_Status_WCBS_APA_VLC_Status User Code end*/
    Rte_Read_WCBS_VStandstillSta_WCBS_VStandstillSta(&Read_WCBS_VStandstillSta_WCBS_VStandstillSta);
    /* Rte_Read_WCBS_VStandstillSta_WCBS_VStandstillSta User Code start*/

    /* Rte_Read_WCBS_VStandstillSta_WCBS_VStandstillSta User Code end*/
    /* TSK_Signal_Transmission_10ms_Feedback User Code start*/

    /* TSK_Signal_Transmission_10ms_Feedback User Code end*/

}
#define CtApSignal_Transmission_STOP_SEC_CODE
#include "CtApSignal_Transmission_MemMap.h"




