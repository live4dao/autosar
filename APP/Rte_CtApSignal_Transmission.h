/*  BEGIN_FILE_HDR
********************************************************************************
*   File Name       : Rte_CtApSignal_Transmission.h
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
#ifndef RTE_CTAPSIGNAL_TRANSMISSION_H
#define RTE_CTAPSIGNAL_TRANSMISSION_H

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
#include "Rte_CtApSignal_Transmission_Type.h"
#include "Com.h"
/*******************************************************************************
*   define for a symbolic name of the RunnableEntity.
*******************************************************************************/
#define RTE_RUNNABLE_Signal_Transmission_init               Signal_Transmission_init
#define RTE_RUNNABLE_TSK_Signal_Transmission_10ms           TSK_Signal_Transmission_10ms

/*******************************************************************************
*   Instance Handle
*******************************************************************************/
#ifndef RTE_CORE
typedef CONSTP2CONST(Rte_CDS_CtApSignal_Transmission, AUTOMATIC, RTE_CONST) Rte_Instance;
#endif

/*******************************************************************************
*   Macro definition.
*******************************************************************************/
#define Rte_Write_ADAS_APA_LightReq_ADAS_APA_LightReq       Rte_Write_CtApSignal_Transmission_ADAS_APA_LightReq_ADAS_APA_LightReq
#define Rte_Write_ADAS_APA_SuggestedID_ADAS_APA_SuggestedID Rte_Write_CtApSignal_Transmission_ADAS_APA_SuggestedID_ADAS_APA_SuggestedID
#define Rte_Write_APA_ChimeRequest_APA_ChimeRequest         Rte_Write_CtApSignal_Transmission_APA_ChimeRequest_APA_ChimeRequest
#define Rte_Write_APA_EPS_AngReqSts_APA_EPS_AngReqSts       Rte_Write_CtApSignal_Transmission_APA_EPS_AngReqSts_APA_EPS_AngReqSts
#define Rte_Write_APA_EPS_TargetSteeringAngle_APA_EPS_TargetSteeringAngle       Rte_Write_CtApSignal_Transmission_APA_EPS_TargetSteeringAngle_APA_EPS_TargetSteeringAngle
#define Rte_Write_APA_FRegion1ObjectSts_APA_FRegion1ObjectSts         Rte_Write_CtApSignal_Transmission_APA_FRegion1ObjectSts_APA_FRegion1ObjectSts
#define Rte_Write_APA_FRegion2ObjectSts_APA_FRegion2ObjectSts         Rte_Write_CtApSignal_Transmission_APA_FRegion2ObjectSts_APA_FRegion2ObjectSts
#define Rte_Write_APA_FRegion3ObjectSts_APA_FRegion3ObjectSts         Rte_Write_CtApSignal_Transmission_APA_FRegion3ObjectSts_APA_FRegion3ObjectSts
#define Rte_Write_APA_FRegion4ObjectSts_APA_FRegion4ObjectSts         Rte_Write_CtApSignal_Transmission_APA_FRegion4ObjectSts_APA_FRegion4ObjectSts
#define Rte_Write_APA_FrontExtenedDistance_APA_FrontExtenedDistance   Rte_Write_CtApSignal_Transmission_APA_FrontExtenedDistance_APA_FrontExtenedDistance
#define Rte_Write_APA_ParkAssistRExtenedDistance_APA_ParkAssistRExtenedDistance Rte_Write_CtApSignal_Transmission_APA_ParkAssistRExtenedDistance_APA_ParkAssistRExtenedDistance
#define Rte_Write_APA_ParkAssistRRegion1ObjectSts_APA_ParkAssistRRegion1ObjectSts         Rte_Write_CtApSignal_Transmission_APA_ParkAssistRRegion1ObjectSts_APA_ParkAssistRRegion1ObjectSts
#define Rte_Write_APA_ParkAssistRRegion2ObjectSts_APA_ParkAssistRRegion2ObjectSts         Rte_Write_CtApSignal_Transmission_APA_ParkAssistRRegion2ObjectSts_APA_ParkAssistRRegion2ObjectSts
#define Rte_Write_APA_ParkAssistRRegion3ObjectSts_APA_ParkAssistRRegion3ObjectSts         Rte_Write_CtApSignal_Transmission_APA_ParkAssistRRegion3ObjectSts_APA_ParkAssistRRegion3ObjectSts
#define Rte_Write_APA_ParkAssistRRegion4ObjectSts_APA_ParkAssistRRegion4ObjectSts         Rte_Write_CtApSignal_Transmission_APA_ParkAssistRRegion4ObjectSts_APA_ParkAssistRRegion4ObjectSts
#define Rte_Write_APA_WCBS_BrakeMode_APA_WCBS_BrakeMode     Rte_Write_CtApSignal_Transmission_APA_WCBS_BrakeMode_APA_WCBS_BrakeMode
#define Rte_Write_APA_WCBS_ExpectedGearPosition_APA_WCBS_ExpectedGearPosition   Rte_Write_CtApSignal_Transmission_APA_WCBS_ExpectedGearPosition_APA_WCBS_ExpectedGearPosition
#define Rte_Write_APA_WCBS_SpeedLimitation_APA_WCBS_SpeedLimitation   Rte_Write_CtApSignal_Transmission_APA_WCBS_SpeedLimitation_APA_WCBS_SpeedLimitation
#define Rte_Write_APA_WCBS_TargetStopDistance_APA_WCBS_TargetStopDistance       Rte_Write_CtApSignal_Transmission_APA_WCBS_TargetStopDistance_APA_WCBS_TargetStopDistance
#define Rte_Write_APA_slot_10_APA_slot_10                   Rte_Write_CtApSignal_Transmission_APA_slot_10_APA_slot_10
#define Rte_Write_APA_slot_11_APA_slot_11                   Rte_Write_CtApSignal_Transmission_APA_slot_11_APA_slot_11
#define Rte_Write_APA_slot_12_APA_slot_12                   Rte_Write_CtApSignal_Transmission_APA_slot_12_APA_slot_12
#define Rte_Write_APA_slot_1_APA_slot_1                     Rte_Write_CtApSignal_Transmission_APA_slot_1_APA_slot_1
#define Rte_Write_APA_slot_2_APA_slot_2                     Rte_Write_CtApSignal_Transmission_APA_slot_2_APA_slot_2
#define Rte_Write_APA_slot_3_APA_slot_3                     Rte_Write_CtApSignal_Transmission_APA_slot_3_APA_slot_3
#define Rte_Write_APA_slot_4_APA_slot_4                     Rte_Write_CtApSignal_Transmission_APA_slot_4_APA_slot_4
#define Rte_Write_APA_slot_5_APA_slot_5                     Rte_Write_CtApSignal_Transmission_APA_slot_5_APA_slot_5
#define Rte_Write_APA_slot_6_APA_slot_6                     Rte_Write_CtApSignal_Transmission_APA_slot_6_APA_slot_6
#define Rte_Write_APA_slot_7_APA_slot_7                     Rte_Write_CtApSignal_Transmission_APA_slot_7_APA_slot_7
#define Rte_Write_APA_slot_8_APA_slot_8                     Rte_Write_CtApSignal_Transmission_APA_slot_8_APA_slot_8
#define Rte_Write_APA_slot_9_APA_slot_9                     Rte_Write_CtApSignal_Transmission_APA_slot_9_APA_slot_9
#define Rte_Write_APA_slot_ID_10_P0_X_APA_slot_ID_10_P0_X   Rte_Write_CtApSignal_Transmission_APA_slot_ID_10_P0_X_APA_slot_ID_10_P0_X
#define Rte_Write_APA_slot_ID_10_P0_Y_APA_slot_ID_10_P0_Y   Rte_Write_CtApSignal_Transmission_APA_slot_ID_10_P0_Y_APA_slot_ID_10_P0_Y
#define Rte_Write_APA_slot_ID_10_P1_X_APA_slot_ID_10_P1_X   Rte_Write_CtApSignal_Transmission_APA_slot_ID_10_P1_X_APA_slot_ID_10_P1_X
#define Rte_Write_APA_slot_ID_10_P1_Y_APA_slot_ID_10_P1_Y   Rte_Write_CtApSignal_Transmission_APA_slot_ID_10_P1_Y_APA_slot_ID_10_P1_Y
#define Rte_Write_APA_slot_ID_10_P2_X_APA_slot_ID_10_P2_X   Rte_Write_CtApSignal_Transmission_APA_slot_ID_10_P2_X_APA_slot_ID_10_P2_X
#define Rte_Write_APA_slot_ID_10_P2_Y_APA_slot_ID_10_P2_Y   Rte_Write_CtApSignal_Transmission_APA_slot_ID_10_P2_Y_APA_slot_ID_10_P2_Y
#define Rte_Write_APA_slot_ID_10_P3_X_APA_slot_ID_10_P3_X   Rte_Write_CtApSignal_Transmission_APA_slot_ID_10_P3_X_APA_slot_ID_10_P3_X
#define Rte_Write_APA_slot_ID_10_P3_Y_APA_slot_ID_10_P3_Y   Rte_Write_CtApSignal_Transmission_APA_slot_ID_10_P3_Y_APA_slot_ID_10_P3_Y
#define Rte_Write_APA_slot_ID_10_Type_APA_slot_ID_10_Type   Rte_Write_CtApSignal_Transmission_APA_slot_ID_10_Type_APA_slot_ID_10_Type
#define Rte_Write_APA_slot_ID_11_P0_X_APA_slot_ID_11_P0_X   Rte_Write_CtApSignal_Transmission_APA_slot_ID_11_P0_X_APA_slot_ID_11_P0_X
#define Rte_Write_APA_slot_ID_11_P0_Y_APA_slot_ID_11_P0_Y   Rte_Write_CtApSignal_Transmission_APA_slot_ID_11_P0_Y_APA_slot_ID_11_P0_Y
#define Rte_Write_APA_slot_ID_11_P1_X_APA_slot_ID_11_P1_X   Rte_Write_CtApSignal_Transmission_APA_slot_ID_11_P1_X_APA_slot_ID_11_P1_X
#define Rte_Write_APA_slot_ID_11_P1_Y_APA_slot_ID_11_P1_Y   Rte_Write_CtApSignal_Transmission_APA_slot_ID_11_P1_Y_APA_slot_ID_11_P1_Y
#define Rte_Write_APA_slot_ID_11_P2_X_APA_slot_ID_11_P2_X   Rte_Write_CtApSignal_Transmission_APA_slot_ID_11_P2_X_APA_slot_ID_11_P2_X
#define Rte_Write_APA_slot_ID_11_P2_Y_APA_slot_ID_11_P2_Y   Rte_Write_CtApSignal_Transmission_APA_slot_ID_11_P2_Y_APA_slot_ID_11_P2_Y
#define Rte_Write_APA_slot_ID_11_P3_X_APA_slot_ID_11_P3_X   Rte_Write_CtApSignal_Transmission_APA_slot_ID_11_P3_X_APA_slot_ID_11_P3_X
#define Rte_Write_APA_slot_ID_11_P3_Y_APA_slot_ID_11_P3_Y   Rte_Write_CtApSignal_Transmission_APA_slot_ID_11_P3_Y_APA_slot_ID_11_P3_Y
#define Rte_Write_APA_slot_ID_11_Type_APA_slot_ID_11_Type   Rte_Write_CtApSignal_Transmission_APA_slot_ID_11_Type_APA_slot_ID_11_Type
#define Rte_Write_APA_slot_ID_12_P0_X_APA_slot_ID_12_P0_X   Rte_Write_CtApSignal_Transmission_APA_slot_ID_12_P0_X_APA_slot_ID_12_P0_X
#define Rte_Write_APA_slot_ID_12_P0_Y_APA_slot_ID_12_P0_Y   Rte_Write_CtApSignal_Transmission_APA_slot_ID_12_P0_Y_APA_slot_ID_12_P0_Y
#define Rte_Write_APA_slot_ID_12_P1_X_APA_slot_ID_12_P1_X   Rte_Write_CtApSignal_Transmission_APA_slot_ID_12_P1_X_APA_slot_ID_12_P1_X
#define Rte_Write_APA_slot_ID_12_P1_Y_APA_slot_ID_12_P1_Y   Rte_Write_CtApSignal_Transmission_APA_slot_ID_12_P1_Y_APA_slot_ID_12_P1_Y
#define Rte_Write_APA_slot_ID_12_P2_X_APA_slot_ID_12_P2_X   Rte_Write_CtApSignal_Transmission_APA_slot_ID_12_P2_X_APA_slot_ID_12_P2_X
#define Rte_Write_APA_slot_ID_12_P2_Y_APA_slot_ID_12_P2_Y   Rte_Write_CtApSignal_Transmission_APA_slot_ID_12_P2_Y_APA_slot_ID_12_P2_Y
#define Rte_Write_APA_slot_ID_12_P3_X_APA_slot_ID_12_P3_X   Rte_Write_CtApSignal_Transmission_APA_slot_ID_12_P3_X_APA_slot_ID_12_P3_X
#define Rte_Write_APA_slot_ID_12_P3_Y_APA_slot_ID_12_P3_Y   Rte_Write_CtApSignal_Transmission_APA_slot_ID_12_P3_Y_APA_slot_ID_12_P3_Y
#define Rte_Write_APA_slot_ID_12_Type_APA_slot_ID_12_Type   Rte_Write_CtApSignal_Transmission_APA_slot_ID_12_Type_APA_slot_ID_12_Type
#define Rte_Write_APA_slot_ID_1_P0_X_APA_slot_ID_1_P0_X     Rte_Write_CtApSignal_Transmission_APA_slot_ID_1_P0_X_APA_slot_ID_1_P0_X
#define Rte_Write_APA_slot_ID_1_P0_Y_APA_slot_ID_1_P0_Y     Rte_Write_CtApSignal_Transmission_APA_slot_ID_1_P0_Y_APA_slot_ID_1_P0_Y
#define Rte_Write_APA_slot_ID_1_P1_X_APA_slot_ID_1_P1_X     Rte_Write_CtApSignal_Transmission_APA_slot_ID_1_P1_X_APA_slot_ID_1_P1_X
#define Rte_Write_APA_slot_ID_1_P1_Y_APA_slot_ID_1_P1_Y     Rte_Write_CtApSignal_Transmission_APA_slot_ID_1_P1_Y_APA_slot_ID_1_P1_Y
#define Rte_Write_APA_slot_ID_1_P2_X_APA_slot_ID_1_P2_X     Rte_Write_CtApSignal_Transmission_APA_slot_ID_1_P2_X_APA_slot_ID_1_P2_X
#define Rte_Write_APA_slot_ID_1_P2_Y_APA_slot_ID_1_P2_Y     Rte_Write_CtApSignal_Transmission_APA_slot_ID_1_P2_Y_APA_slot_ID_1_P2_Y
#define Rte_Write_APA_slot_ID_1_P3_X_APA_slot_ID_1_P3_X     Rte_Write_CtApSignal_Transmission_APA_slot_ID_1_P3_X_APA_slot_ID_1_P3_X
#define Rte_Write_APA_slot_ID_1_P3_Y_APA_slot_ID_1_P3_Y     Rte_Write_CtApSignal_Transmission_APA_slot_ID_1_P3_Y_APA_slot_ID_1_P3_Y
#define Rte_Write_APA_slot_ID_1_Type_APA_slot_ID_1_Type     Rte_Write_CtApSignal_Transmission_APA_slot_ID_1_Type_APA_slot_ID_1_Type
#define Rte_Write_APA_slot_ID_2_P0_X_APA_slot_ID_2_P0_X     Rte_Write_CtApSignal_Transmission_APA_slot_ID_2_P0_X_APA_slot_ID_2_P0_X
#define Rte_Write_APA_slot_ID_2_P0_Y_APA_slot_ID_2_P0_Y     Rte_Write_CtApSignal_Transmission_APA_slot_ID_2_P0_Y_APA_slot_ID_2_P0_Y
#define Rte_Write_APA_slot_ID_2_P1_X_APA_slot_ID_2_P1_X     Rte_Write_CtApSignal_Transmission_APA_slot_ID_2_P1_X_APA_slot_ID_2_P1_X
#define Rte_Write_APA_slot_ID_2_P1_Y_APA_slot_ID_2_P1_Y     Rte_Write_CtApSignal_Transmission_APA_slot_ID_2_P1_Y_APA_slot_ID_2_P1_Y
#define Rte_Write_APA_slot_ID_2_P2_X_APA_slot_ID_2_P2_X     Rte_Write_CtApSignal_Transmission_APA_slot_ID_2_P2_X_APA_slot_ID_2_P2_X
#define Rte_Write_APA_slot_ID_2_P2_Y_APA_slot_ID_2_P2_Y     Rte_Write_CtApSignal_Transmission_APA_slot_ID_2_P2_Y_APA_slot_ID_2_P2_Y
#define Rte_Write_APA_slot_ID_2_P3_X_APA_slot_ID_2_P3_X     Rte_Write_CtApSignal_Transmission_APA_slot_ID_2_P3_X_APA_slot_ID_2_P3_X
#define Rte_Write_APA_slot_ID_2_P3_Y_APA_slot_ID_2_P3_Y     Rte_Write_CtApSignal_Transmission_APA_slot_ID_2_P3_Y_APA_slot_ID_2_P3_Y
#define Rte_Write_APA_slot_ID_2_Type_APA_slot_ID_2_Type     Rte_Write_CtApSignal_Transmission_APA_slot_ID_2_Type_APA_slot_ID_2_Type
#define Rte_Write_APA_slot_ID_3_P0_X_APA_slot_ID_3_P0_X     Rte_Write_CtApSignal_Transmission_APA_slot_ID_3_P0_X_APA_slot_ID_3_P0_X
#define Rte_Write_APA_slot_ID_3_P0_Y_APA_slot_ID_3_P0_Y     Rte_Write_CtApSignal_Transmission_APA_slot_ID_3_P0_Y_APA_slot_ID_3_P0_Y
#define Rte_Write_APA_slot_ID_3_P1_X_APA_slot_ID_3_P1_X     Rte_Write_CtApSignal_Transmission_APA_slot_ID_3_P1_X_APA_slot_ID_3_P1_X
#define Rte_Write_APA_slot_ID_3_P1_Y_APA_slot_ID_3_P1_Y     Rte_Write_CtApSignal_Transmission_APA_slot_ID_3_P1_Y_APA_slot_ID_3_P1_Y
#define Rte_Write_APA_slot_ID_3_P2_X_APA_slot_ID_3_P2_X     Rte_Write_CtApSignal_Transmission_APA_slot_ID_3_P2_X_APA_slot_ID_3_P2_X
#define Rte_Write_APA_slot_ID_3_P2_Y_APA_slot_ID_3_P2_Y     Rte_Write_CtApSignal_Transmission_APA_slot_ID_3_P2_Y_APA_slot_ID_3_P2_Y
#define Rte_Write_APA_slot_ID_3_P3_X_APA_slot_ID_3_P3_X     Rte_Write_CtApSignal_Transmission_APA_slot_ID_3_P3_X_APA_slot_ID_3_P3_X
#define Rte_Write_APA_slot_ID_3_P3_Y_APA_slot_ID_3_P3_Y     Rte_Write_CtApSignal_Transmission_APA_slot_ID_3_P3_Y_APA_slot_ID_3_P3_Y
#define Rte_Write_APA_slot_ID_3_Type_APA_slot_ID_3_Type     Rte_Write_CtApSignal_Transmission_APA_slot_ID_3_Type_APA_slot_ID_3_Type
#define Rte_Write_APA_slot_ID_4_P0_X_APA_slot_ID_4_P0_X     Rte_Write_CtApSignal_Transmission_APA_slot_ID_4_P0_X_APA_slot_ID_4_P0_X
#define Rte_Write_APA_slot_ID_4_P0_Y_APA_slot_ID_4_P0_Y     Rte_Write_CtApSignal_Transmission_APA_slot_ID_4_P0_Y_APA_slot_ID_4_P0_Y
#define Rte_Write_APA_slot_ID_4_P1_X_APA_slot_ID_4_P1_X     Rte_Write_CtApSignal_Transmission_APA_slot_ID_4_P1_X_APA_slot_ID_4_P1_X
#define Rte_Write_APA_slot_ID_4_P1_Y_APA_slot_ID_4_P1_Y     Rte_Write_CtApSignal_Transmission_APA_slot_ID_4_P1_Y_APA_slot_ID_4_P1_Y
#define Rte_Write_APA_slot_ID_4_P2_X_APA_slot_ID_4_P2_X     Rte_Write_CtApSignal_Transmission_APA_slot_ID_4_P2_X_APA_slot_ID_4_P2_X
#define Rte_Write_APA_slot_ID_4_P2_Y_APA_slot_ID_4_P2_Y     Rte_Write_CtApSignal_Transmission_APA_slot_ID_4_P2_Y_APA_slot_ID_4_P2_Y
#define Rte_Write_APA_slot_ID_4_P3_X_APA_slot_ID_4_P3_X     Rte_Write_CtApSignal_Transmission_APA_slot_ID_4_P3_X_APA_slot_ID_4_P3_X
#define Rte_Write_APA_slot_ID_4_P3_Y_APA_slot_ID_4_P3_Y     Rte_Write_CtApSignal_Transmission_APA_slot_ID_4_P3_Y_APA_slot_ID_4_P3_Y
#define Rte_Write_APA_slot_ID_4_Type_APA_slot_ID_4_Type     Rte_Write_CtApSignal_Transmission_APA_slot_ID_4_Type_APA_slot_ID_4_Type
#define Rte_Write_APA_slot_ID_5_P0_X_APA_slot_ID_5_P0_X     Rte_Write_CtApSignal_Transmission_APA_slot_ID_5_P0_X_APA_slot_ID_5_P0_X
#define Rte_Write_APA_slot_ID_5_P0_Y_APA_slot_ID_5_P0_Y     Rte_Write_CtApSignal_Transmission_APA_slot_ID_5_P0_Y_APA_slot_ID_5_P0_Y
#define Rte_Write_APA_slot_ID_5_P1_X_APA_slot_ID_5_P1_X     Rte_Write_CtApSignal_Transmission_APA_slot_ID_5_P1_X_APA_slot_ID_5_P1_X
#define Rte_Write_APA_slot_ID_5_P1_Y_APA_slot_ID_5_P1_Y     Rte_Write_CtApSignal_Transmission_APA_slot_ID_5_P1_Y_APA_slot_ID_5_P1_Y
#define Rte_Write_APA_slot_ID_5_P2_X_APA_slot_ID_5_P2_X     Rte_Write_CtApSignal_Transmission_APA_slot_ID_5_P2_X_APA_slot_ID_5_P2_X
#define Rte_Write_APA_slot_ID_5_P2_Y_APA_slot_ID_5_P2_Y     Rte_Write_CtApSignal_Transmission_APA_slot_ID_5_P2_Y_APA_slot_ID_5_P2_Y
#define Rte_Write_APA_slot_ID_5_P3_X_APA_slot_ID_5_P3_X     Rte_Write_CtApSignal_Transmission_APA_slot_ID_5_P3_X_APA_slot_ID_5_P3_X
#define Rte_Write_APA_slot_ID_5_P3_Y_APA_slot_ID_5_P3_Y     Rte_Write_CtApSignal_Transmission_APA_slot_ID_5_P3_Y_APA_slot_ID_5_P3_Y
#define Rte_Write_APA_slot_ID_5_Type_APA_slot_ID_5_Type     Rte_Write_CtApSignal_Transmission_APA_slot_ID_5_Type_APA_slot_ID_5_Type
#define Rte_Write_APA_slot_ID_6_P0_X_APA_slot_ID_6_P0_X     Rte_Write_CtApSignal_Transmission_APA_slot_ID_6_P0_X_APA_slot_ID_6_P0_X
#define Rte_Write_APA_slot_ID_6_P0_Y_APA_slot_ID_6_P0_Y     Rte_Write_CtApSignal_Transmission_APA_slot_ID_6_P0_Y_APA_slot_ID_6_P0_Y
#define Rte_Write_APA_slot_ID_6_P1_X_APA_slot_ID_6_P1_X     Rte_Write_CtApSignal_Transmission_APA_slot_ID_6_P1_X_APA_slot_ID_6_P1_X
#define Rte_Write_APA_slot_ID_6_P1_Y_APA_slot_ID_6_P1_Y     Rte_Write_CtApSignal_Transmission_APA_slot_ID_6_P1_Y_APA_slot_ID_6_P1_Y
#define Rte_Write_APA_slot_ID_6_P2_X_APA_slot_ID_6_P2_X     Rte_Write_CtApSignal_Transmission_APA_slot_ID_6_P2_X_APA_slot_ID_6_P2_X
#define Rte_Write_APA_slot_ID_6_P2_Y_APA_slot_ID_6_P2_Y     Rte_Write_CtApSignal_Transmission_APA_slot_ID_6_P2_Y_APA_slot_ID_6_P2_Y
#define Rte_Write_APA_slot_ID_6_P3_X_APA_slot_ID_6_P3_X     Rte_Write_CtApSignal_Transmission_APA_slot_ID_6_P3_X_APA_slot_ID_6_P3_X
#define Rte_Write_APA_slot_ID_6_P3_Y_APA_slot_ID_6_P3_Y     Rte_Write_CtApSignal_Transmission_APA_slot_ID_6_P3_Y_APA_slot_ID_6_P3_Y
#define Rte_Write_APA_slot_ID_6_Type_APA_slot_ID_6_Type     Rte_Write_CtApSignal_Transmission_APA_slot_ID_6_Type_APA_slot_ID_6_Type
#define Rte_Write_APA_slot_ID_7_P0_X_APA_slot_ID_7_P0_X     Rte_Write_CtApSignal_Transmission_APA_slot_ID_7_P0_X_APA_slot_ID_7_P0_X
#define Rte_Write_APA_slot_ID_7_P0_Y_APA_slot_ID_7_P0_Y     Rte_Write_CtApSignal_Transmission_APA_slot_ID_7_P0_Y_APA_slot_ID_7_P0_Y
#define Rte_Write_APA_slot_ID_7_P1_X_APA_slot_ID_7_P1_X     Rte_Write_CtApSignal_Transmission_APA_slot_ID_7_P1_X_APA_slot_ID_7_P1_X
#define Rte_Write_APA_slot_ID_7_P1_Y_APA_slot_ID_7_P1_Y     Rte_Write_CtApSignal_Transmission_APA_slot_ID_7_P1_Y_APA_slot_ID_7_P1_Y
#define Rte_Write_APA_slot_ID_7_P2_X_APA_slot_ID_7_P2_X     Rte_Write_CtApSignal_Transmission_APA_slot_ID_7_P2_X_APA_slot_ID_7_P2_X
#define Rte_Write_APA_slot_ID_7_P2_Y_APA_slot_ID_7_P2_Y     Rte_Write_CtApSignal_Transmission_APA_slot_ID_7_P2_Y_APA_slot_ID_7_P2_Y
#define Rte_Write_APA_slot_ID_7_P3_X_APA_slot_ID_7_P3_X     Rte_Write_CtApSignal_Transmission_APA_slot_ID_7_P3_X_APA_slot_ID_7_P3_X
#define Rte_Write_APA_slot_ID_7_P3_Y_APA_slot_ID_7_P3_Y     Rte_Write_CtApSignal_Transmission_APA_slot_ID_7_P3_Y_APA_slot_ID_7_P3_Y
#define Rte_Write_APA_slot_ID_7_Type_APA_slot_ID_7_Type     Rte_Write_CtApSignal_Transmission_APA_slot_ID_7_Type_APA_slot_ID_7_Type
#define Rte_Write_APA_slot_ID_8_P0_X_APA_slot_ID_8_P0_X     Rte_Write_CtApSignal_Transmission_APA_slot_ID_8_P0_X_APA_slot_ID_8_P0_X
#define Rte_Write_APA_slot_ID_8_P0_Y_APA_slot_ID_8_P0_Y     Rte_Write_CtApSignal_Transmission_APA_slot_ID_8_P0_Y_APA_slot_ID_8_P0_Y
#define Rte_Write_APA_slot_ID_8_P1_X_APA_slot_ID_8_P1_X     Rte_Write_CtApSignal_Transmission_APA_slot_ID_8_P1_X_APA_slot_ID_8_P1_X
#define Rte_Write_APA_slot_ID_8_P1_Y_APA_slot_ID_8_P1_Y     Rte_Write_CtApSignal_Transmission_APA_slot_ID_8_P1_Y_APA_slot_ID_8_P1_Y
#define Rte_Write_APA_slot_ID_8_P2_X_APA_slot_ID_8_P2_X     Rte_Write_CtApSignal_Transmission_APA_slot_ID_8_P2_X_APA_slot_ID_8_P2_X
#define Rte_Write_APA_slot_ID_8_P2_Y_APA_slot_ID_8_P2_Y     Rte_Write_CtApSignal_Transmission_APA_slot_ID_8_P2_Y_APA_slot_ID_8_P2_Y
#define Rte_Write_APA_slot_ID_8_P3_X_APA_slot_ID_8_P3_X     Rte_Write_CtApSignal_Transmission_APA_slot_ID_8_P3_X_APA_slot_ID_8_P3_X
#define Rte_Write_APA_slot_ID_8_P3_Y_APA_slot_ID_8_P3_Y     Rte_Write_CtApSignal_Transmission_APA_slot_ID_8_P3_Y_APA_slot_ID_8_P3_Y
#define Rte_Write_APA_slot_ID_8_Type_APA_slot_ID_8_Type     Rte_Write_CtApSignal_Transmission_APA_slot_ID_8_Type_APA_slot_ID_8_Type
#define Rte_Write_APA_slot_ID_9_P0_X_APA_slot_ID_9_P0_X     Rte_Write_CtApSignal_Transmission_APA_slot_ID_9_P0_X_APA_slot_ID_9_P0_X
#define Rte_Write_APA_slot_ID_9_P0_Y_APA_slot_ID_9_P0_Y     Rte_Write_CtApSignal_Transmission_APA_slot_ID_9_P0_Y_APA_slot_ID_9_P0_Y
#define Rte_Write_APA_slot_ID_9_P1_X_APA_slot_ID_9_P1_X     Rte_Write_CtApSignal_Transmission_APA_slot_ID_9_P1_X_APA_slot_ID_9_P1_X
#define Rte_Write_APA_slot_ID_9_P1_Y_APA_slot_ID_9_P1_Y     Rte_Write_CtApSignal_Transmission_APA_slot_ID_9_P1_Y_APA_slot_ID_9_P1_Y
#define Rte_Write_APA_slot_ID_9_P2_X_APA_slot_ID_9_P2_X     Rte_Write_CtApSignal_Transmission_APA_slot_ID_9_P2_X_APA_slot_ID_9_P2_X
#define Rte_Write_APA_slot_ID_9_P2_Y_APA_slot_ID_9_P2_Y     Rte_Write_CtApSignal_Transmission_APA_slot_ID_9_P2_Y_APA_slot_ID_9_P2_Y
#define Rte_Write_APA_slot_ID_9_P3_X_APA_slot_ID_9_P3_X     Rte_Write_CtApSignal_Transmission_APA_slot_ID_9_P3_X_APA_slot_ID_9_P3_X
#define Rte_Write_APA_slot_ID_9_P3_Y_APA_slot_ID_9_P3_Y     Rte_Write_CtApSignal_Transmission_APA_slot_ID_9_P3_Y_APA_slot_ID_9_P3_Y
#define Rte_Write_APA_slot_ID_9_Type_APA_slot_ID_9_Type     Rte_Write_CtApSignal_Transmission_APA_slot_ID_9_Type_APA_slot_ID_9_Type
#define Rte_Write_FLC_ExtenedDistance_FLC_ExtenedDistance   Rte_Write_CtApSignal_Transmission_FLC_ExtenedDistance_FLC_ExtenedDistance
#define Rte_Write_FLM_ExtenedDistance_FLM_ExtenedDistance   Rte_Write_CtApSignal_Transmission_FLM_ExtenedDistance_FLM_ExtenedDistance
#define Rte_Write_FLS_ExtenedDistance_FLS_ExtenedDistance   Rte_Write_CtApSignal_Transmission_FLS_ExtenedDistance_FLS_ExtenedDistance
#define Rte_Write_FRC_ExtenedDistance_FRC_ExtenedDistance   Rte_Write_CtApSignal_Transmission_FRC_ExtenedDistance_FRC_ExtenedDistance
#define Rte_Write_FRM_ExtenedDistance_FRM_ExtenedDistance   Rte_Write_CtApSignal_Transmission_FRM_ExtenedDistance_FRM_ExtenedDistance
#define Rte_Write_FRS_ExtenedDistance_FRS_ExtenedDistance   Rte_Write_CtApSignal_Transmission_FRS_ExtenedDistance_FRS_ExtenedDistance
#define Rte_Write_PiCarInfoH_PiCarInfoH                     Rte_Write_CtApSignal_Transmission_PiCarInfoH_PiCarInfoH
#define Rte_Write_PiCarInfoL_PiCarInfoL                     Rte_Write_CtApSignal_Transmission_PiCarInfoL_PiCarInfoL
#define Rte_Write_PiImuInfo_PiIMUInfo                       Rte_Write_CtApSignal_Transmission_PiImuInfo_PiIMUInfo
#define Rte_Write_PiManualParkingSlotSet_PiManualParkingSlotSet       Rte_Write_CtApSignal_Transmission_PiManualParkingSlotSet_PiManualParkingSlotSet
#define Rte_Write_PiSignalTransWorkingStatus_PiSignalTransWorkingStatus         Rte_Write_CtApSignal_Transmission_PiSignalTransWorkingStatus_PiSignalTransWorkingStatus
#define Rte_Write_RLC_ExtenedDistance_RLC_ExtenedDistance   Rte_Write_CtApSignal_Transmission_RLC_ExtenedDistance_RLC_ExtenedDistance
#define Rte_Write_RLM_ExtenedDistance_RLM_ExtenedDistance   Rte_Write_CtApSignal_Transmission_RLM_ExtenedDistance_RLM_ExtenedDistance
#define Rte_Write_RLS_ExtenedDistance_RLS_ExtenedDistance   Rte_Write_CtApSignal_Transmission_RLS_ExtenedDistance_RLS_ExtenedDistance
#define Rte_Write_RRC_ExtenedDistance_RRC_ExtenedDistance   Rte_Write_CtApSignal_Transmission_RRC_ExtenedDistance_RRC_ExtenedDistance
#define Rte_Write_RRM_ExtenedDistance_RRM_ExtenedDistance   Rte_Write_CtApSignal_Transmission_RRM_ExtenedDistance_RRM_ExtenedDistance
#define Rte_Write_RRS_ExtenedDistance_RRS_ExtenedDistance   Rte_Write_CtApSignal_Transmission_RRS_ExtenedDistance_RRS_ExtenedDistance
#define Rte_Read_ABS_FLWheelDirection_ABS_FLWheelDirection  Rte_Read_CtApSignal_Transmission_ABS_FLWheelDirection_ABS_FLWheelDirection
#define Rte_Read_ABS_FLWheelSpeedKPH_ABS_FLWheelSpeedKPH    Rte_Read_CtApSignal_Transmission_ABS_FLWheelSpeedKPH_ABS_FLWheelSpeedKPH
#define Rte_Read_ABS_FLWheelSpeedRC_ABS_FLWheelSpeedRC      Rte_Read_CtApSignal_Transmission_ABS_FLWheelSpeedRC_ABS_FLWheelSpeedRC
#define Rte_Read_ABS_FRWheelDirection_ABS_FRWheelDirection  Rte_Read_CtApSignal_Transmission_ABS_FRWheelDirection_ABS_FRWheelDirection
#define Rte_Read_ABS_FRWheelSpeedKPH_ABS_FRWheelSpeedKPH    Rte_Read_CtApSignal_Transmission_ABS_FRWheelSpeedKPH_ABS_FRWheelSpeedKPH
#define Rte_Read_ABS_FRWheelSpeedRC_ABS_FRWheelSpeedRC      Rte_Read_CtApSignal_Transmission_ABS_FRWheelSpeedRC_ABS_FRWheelSpeedRC
#define Rte_Read_ABS_RLWheelDirection_ABS_RLWheelDirection  Rte_Read_CtApSignal_Transmission_ABS_RLWheelDirection_ABS_RLWheelDirection
#define Rte_Read_ABS_RLWheelSpeedKPH_ABS_RLWheelSpeedKPH    Rte_Read_CtApSignal_Transmission_ABS_RLWheelSpeedKPH_ABS_RLWheelSpeedKPH
#define Rte_Read_ABS_RLWheelSpeedRC_ABS_RLWheelSpeedRC      Rte_Read_CtApSignal_Transmission_ABS_RLWheelSpeedRC_ABS_RLWheelSpeedRC
#define Rte_Read_ABS_RRWheelDirection_ABS_RRWheelDirection  Rte_Read_CtApSignal_Transmission_ABS_RRWheelDirection_ABS_RRWheelDirection
#define Rte_Read_ABS_RRWheelSpeedKPH_ABS_RRWheelSpeedKPH    Rte_Read_CtApSignal_Transmission_ABS_RRWheelSpeedKPH_ABS_RRWheelSpeedKPH
#define Rte_Read_ABS_RRWheelSpeedRC_ABS_RRWheelSpeedRC      Rte_Read_CtApSignal_Transmission_ABS_RRWheelSpeedRC_ABS_RRWheelSpeedRC
#define Rte_Read_ABS_VehicleSpeed_ABS_VehicleSpeed          Rte_Read_CtApSignal_Transmission_ABS_VehicleSpeed_ABS_VehicleSpeed
#define Rte_Read_AB_BrkPedalSwSts_AB_BrkPedalSwSts          Rte_Read_CtApSignal_Transmission_AB_BrkPedalSwSts_AB_BrkPedalSwSts
#define Rte_Read_AB_BrkPedalTravel_AB_BrkPedalTravel        Rte_Read_CtApSignal_Transmission_AB_BrkPedalTravel_AB_BrkPedalTravel
#define Rte_Read_AB_Fault_Status_AB_Fault_Status            Rte_Read_CtApSignal_Transmission_AB_Fault_Status_AB_Fault_Status
#define Rte_Read_ACU_CoDSeatbeltBucklestatus_ACU_CoDSeatbeltBucklestatus        Rte_Read_CtApSignal_Transmission_ACU_CoDSeatbeltBucklestatus_ACU_CoDSeatbeltBucklestatus
#define Rte_Read_ACU_DSeatbeltBucklestatus_ACU_DSeatbeltBucklestatus  Rte_Read_CtApSignal_Transmission_ACU_DSeatbeltBucklestatus_ACU_DSeatbeltBucklestatus
#define Rte_Read_BCM_CodriversSideDoorAjarSts_BCM_CodriversSideDoorAjarSts      Rte_Read_CtApSignal_Transmission_BCM_CodriversSideDoorAjarSts_BCM_CodriversSideDoorAjarSts
#define Rte_Read_BCM_CoverAjarStatus_BCM_CoverAjarStatus    Rte_Read_CtApSignal_Transmission_BCM_CoverAjarStatus_BCM_CoverAjarStatus
#define Rte_Read_BCM_DriverSideDoorAjarSts_BCM_DriverSideDoorAjarSts  Rte_Read_CtApSignal_Transmission_BCM_DriverSideDoorAjarSts_BCM_DriverSideDoorAjarSts
#define Rte_Read_BCM_RearLeftDoorAjarStatus_BCM_RearLeftDoorAjarStatus          Rte_Read_CtApSignal_Transmission_BCM_RearLeftDoorAjarStatus_BCM_RearLeftDoorAjarStatus
#define Rte_Read_BCM_RearRightDoorAjarStatus_BCM_RearRightDoorAjarStatus        Rte_Read_CtApSignal_Transmission_BCM_RearRightDoorAjarStatus_BCM_RearRightDoorAjarStatus
#define Rte_Read_BCM_TrunckAjarStatus_BCM_TrunckAjarStatus  Rte_Read_CtApSignal_Transmission_BCM_TrunckAjarStatus_BCM_TrunckAjarStatus
#define Rte_Read_CCU_ExternalTemperature_CCU_ExternalTemperature      Rte_Read_CtApSignal_Transmission_CCU_ExternalTemperature_CCU_ExternalTemperature
#define Rte_Read_EPB_Sts_EPB_Sts                            Rte_Read_CtApSignal_Transmission_EPB_Sts_EPB_Sts
#define Rte_Read_EPS_APA_CtrlAbortFeedback_EPS_APA_CtrlAbortFeedback  Rte_Read_CtApSignal_Transmission_EPS_APA_CtrlAbortFeedback_EPS_APA_CtrlAbortFeedback
#define Rte_Read_EPS_APA_ModActv_EPS_APA_ModActv            Rte_Read_CtApSignal_Transmission_EPS_APA_ModActv_EPS_APA_ModActv
#define Rte_Read_EPS_APA_ModAvail_EPS_APA_ModAvail          Rte_Read_CtApSignal_Transmission_EPS_APA_ModAvail_EPS_APA_ModAvail
#define Rte_Read_EPS_DrStrTorqVal_EPS_DrStrTorqVal          Rte_Read_CtApSignal_Transmission_EPS_DrStrTorqVal_EPS_DrStrTorqVal
#define Rte_Read_ESC_LateralACC_ESC_LateralACC              Rte_Read_CtApSignal_Transmission_ESC_LateralACC_ESC_LateralACC
#define Rte_Read_ESC_LongitudeACC_ESC_LongitudeACC          Rte_Read_CtApSignal_Transmission_ESC_LongitudeACC_ESC_LongitudeACC
#define Rte_Read_ESC_MasterCylinderPressure_ESC_MasterCylinderPressure          Rte_Read_CtApSignal_Transmission_ESC_MasterCylinderPressure_ESC_MasterCylinderPressure
#define Rte_Read_ESC_SlopeGradeAngle_ESC_SlopeGradeAngle    Rte_Read_CtApSignal_Transmission_ESC_SlopeGradeAngle_ESC_SlopeGradeAngle
#define Rte_Read_ESC_VehDynYawRate_ESC_VehDynYawRate        Rte_Read_CtApSignal_Transmission_ESC_VehDynYawRate_ESC_VehDynYawRate
#define Rte_Read_MHU_APA_ParkingSpace_ID_MHU_APA_ParkingSpace_ID      Rte_Read_CtApSignal_Transmission_MHU_APA_ParkingSpace_ID_MHU_APA_ParkingSpace_ID
#define Rte_Read_MHU_UPAMuteSwitch_MHU_UPAMuteSwitch        Rte_Read_CtApSignal_Transmission_MHU_UPAMuteSwitch_MHU_UPAMuteSwitch
#define Rte_Read_PEPS_IGN1RelaySts_PEPS_IGN1RelaySts        Rte_Read_CtApSignal_Transmission_PEPS_IGN1RelaySts_PEPS_IGN1RelaySts
#define Rte_Read_PEPS_PowerMode_PEPS_PowerMode              Rte_Read_CtApSignal_Transmission_PEPS_PowerMode_PEPS_PowerMode
#define Rte_Read_PiAvmFusionParkingSlot_PiAvmFusionParkingSlot        Rte_Read_CtApSignal_Transmission_PiAvmFusionParkingSlot_PiAvmFusionParkingSlot
#define Rte_Read_PiCarControlCommandH_PiCarControlCommandH  Rte_Read_CtApSignal_Transmission_PiCarControlCommandH_PiCarControlCommandH
#define Rte_Read_PiCarControlCommandL_PiCarControlCommandL  Rte_Read_CtApSignal_Transmission_PiCarControlCommandL_PiCarControlCommandL
#define Rte_Read_PiGuideLine_PiGuideLine                    Rte_Read_CtApSignal_Transmission_PiGuideLine_PiGuideLine
#define Rte_Read_PiUssPdcInfo_PiUssPdcInfo                  Rte_Read_CtApSignal_Transmission_PiUssPdcInfo_PiUssPdcInfo
#define Rte_Read_SAS_SteerWheelAngle_SAS_SteerWheelAngle    Rte_Read_CtApSignal_Transmission_SAS_SteerWheelAngle_SAS_SteerWheelAngle
#define Rte_Read_SAS_SteerWhlRotSpdStatus_SAS_SteerWhlRotSpdStatus    Rte_Read_CtApSignal_Transmission_SAS_SteerWhlRotSpdStatus_SAS_SteerWhlRotSpdStatus
#define Rte_Read_SAS_SteerWhlRotSpd_SAS_SteerWhlRotSpd      Rte_Read_CtApSignal_Transmission_SAS_SteerWhlRotSpd_SAS_SteerWhlRotSpd
#define Rte_Read_TPMS_LFpressureSts_TPMS_LFpressureSts      Rte_Read_CtApSignal_Transmission_TPMS_LFpressureSts_TPMS_LFpressureSts
#define Rte_Read_TPMS_LFpressure_TPMS_LFpressure            Rte_Read_CtApSignal_Transmission_TPMS_LFpressure_TPMS_LFpressure
#define Rte_Read_TPMS_LRpressureSts_TPMS_LRpressureSts      Rte_Read_CtApSignal_Transmission_TPMS_LRpressureSts_TPMS_LRpressureSts
#define Rte_Read_TPMS_LRpressure_TPMS_LRpressure            Rte_Read_CtApSignal_Transmission_TPMS_LRpressure_TPMS_LRpressure
#define Rte_Read_TPMS_RFpressureSts_TPMS_RFpressureSts      Rte_Read_CtApSignal_Transmission_TPMS_RFpressureSts_TPMS_RFpressureSts
#define Rte_Read_TPMS_RFpressure_TPMS_RFpressure            Rte_Read_CtApSignal_Transmission_TPMS_RFpressure_TPMS_RFpressure
#define Rte_Read_TPMS_RRpressureSts_TPMS_RRpressureSts      Rte_Read_CtApSignal_Transmission_TPMS_RRpressureSts_TPMS_RRpressureSts
#define Rte_Read_TPMS_RRpressure_TPMS_RRpressure            Rte_Read_CtApSignal_Transmission_TPMS_RRpressure_TPMS_RRpressure
#define Rte_Read_TimeStamp_ABS_FrontWheelSpeMCUKPH_0x122_TimeStamp_ABS_FrontWheelSpeMCUKPH_0x122    Rte_Read_CtApSignal_Transmission_TimeStamp_ABS_FrontWheelSpeMCUKPH_0x122_TimeStamp_ABS_FrontWheelSpeMCUKPH_0x122
#define Rte_Read_TimeStamp_ABS_RearWheelSpeMCUKPH_0x123_TimeStamp_ABS_RearWheelSpeMCUKPH_0x123      Rte_Read_CtApSignal_Transmission_TimeStamp_ABS_RearWheelSpeMCUKPH_0x123_TimeStamp_ABS_RearWheelSpeMCUKPH_0x123
#define Rte_Read_TimeStamp_ABS_Status_0x125_TimeStamp_ABS_Status_0x125          Rte_Read_CtApSignal_Transmission_TimeStamp_ABS_Status_0x125_TimeStamp_ABS_Status_0x125
#define Rte_Read_TimeStamp_ABS_WheelSpeedRC_0x124_TimeStamp_ABS_WheelSpeedRC_0x124        Rte_Read_CtApSignal_Transmission_TimeStamp_ABS_WheelSpeedRC_0x124_TimeStamp_ABS_WheelSpeedRC_0x124
#define Rte_Read_TimeStamp_ESC_YawAngle_0x3E2_TimeStamp_ESC_YawAngle_0x3E2      Rte_Read_CtApSignal_Transmission_TimeStamp_ESC_YawAngle_0x3E2_TimeStamp_ESC_YawAngle_0x3E2
#define Rte_Read_TimeStamp_IBS_ADAS_Info_0x269_TimeStamp_IBS_ADAS_Info_0x269    Rte_Read_CtApSignal_Transmission_TimeStamp_IBS_ADAS_Info_0x269_TimeStamp_IBS_ADAS_Info_0x269
#define Rte_Read_TimeStamp_SAS_Sensor_0x17E_TimeStamp_SAS_Sensor_0x17E          Rte_Read_CtApSignal_Transmission_TimeStamp_SAS_Sensor_0x17E_TimeStamp_SAS_Sensor_0x17E
#define Rte_Read_TimeStamp_VCU_Ctrl_0x162_TimeStamp_VCU_Ctrl_0x162    Rte_Read_CtApSignal_Transmission_TimeStamp_VCU_Ctrl_0x162_TimeStamp_VCU_Ctrl_0x162
#define Rte_Read_VCU_AccPedalPosition_VCU_AccPedalPosition  Rte_Read_CtApSignal_Transmission_VCU_AccPedalPosition_VCU_AccPedalPosition
#define Rte_Read_VCU_ModeGearSts_VCU_ModeGearSts            Rte_Read_CtApSignal_Transmission_VCU_ModeGearSts_VCU_ModeGearSts
#define Rte_Read_VCU_StsSysFault_VCU_StsSysFault            Rte_Read_CtApSignal_Transmission_VCU_StsSysFault_VCU_StsSysFault
#define Rte_Read_WCBS_APA_CDD_Active_WCBS_APA_CDD_Active    Rte_Read_CtApSignal_Transmission_WCBS_APA_CDD_Active_WCBS_APA_CDD_Active
#define Rte_Read_WCBS_APA_VLC_Active_WCBS_APA_VLC_Active    Rte_Read_CtApSignal_Transmission_WCBS_APA_VLC_Active_WCBS_APA_VLC_Active
#define Rte_Read_WCBS_APA_VLC_Available_WCBS_APA_VLC_Available        Rte_Read_CtApSignal_Transmission_WCBS_APA_VLC_Available_WCBS_APA_VLC_Available
#define Rte_Read_WCBS_APA_VLC_FailureStatus_WCBS_APA_VLC_FailureStatus          Rte_Read_CtApSignal_Transmission_WCBS_APA_VLC_FailureStatus_WCBS_APA_VLC_FailureStatus
#define Rte_Read_WCBS_APA_VLC_Status_WCBS_APA_VLC_Status    Rte_Read_CtApSignal_Transmission_WCBS_APA_VLC_Status_WCBS_APA_VLC_Status
#define Rte_Read_WCBS_VStandstillSta_WCBS_VStandstillSta    Rte_Read_CtApSignal_Transmission_WCBS_VStandstillSta_WCBS_VStandstillSta
/*******************************************************************************
*   Extended
*******************************************************************************/
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtApSignal_Transmission_ADAS_APA_LightReq_ADAS_APA_LightReq
(
    VAR(ADAS_APA_LightReq_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtApSignal_Transmission_ADAS_APA_SuggestedID_ADAS_APA_SuggestedID
(
    VAR(ADAS_APA_SuggestedID_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtApSignal_Transmission_APA_ChimeRequest_APA_ChimeRequest
(
    VAR(APA_ChimeRequest_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtApSignal_Transmission_APA_EPS_AngReqSts_APA_EPS_AngReqSts
(
    VAR(APA_EPS_AngReqSts_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtApSignal_Transmission_APA_EPS_TargetSteeringAngle_APA_EPS_TargetSteeringAngle
(
    VAR(APA_EPS_TargetSteeringAngle_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtApSignal_Transmission_APA_FRegion1ObjectSts_APA_FRegion1ObjectSts
(
    VAR(APA_FRegion1ObjectSts_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtApSignal_Transmission_APA_FRegion2ObjectSts_APA_FRegion2ObjectSts
(
    VAR(APA_FRegion2ObjectSts_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtApSignal_Transmission_APA_FRegion3ObjectSts_APA_FRegion3ObjectSts
(
    VAR(APA_FRegion3ObjectSts_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtApSignal_Transmission_APA_FRegion4ObjectSts_APA_FRegion4ObjectSts
(
    VAR(APA_FRegion4ObjectSts_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtApSignal_Transmission_APA_FrontExtenedDistance_APA_FrontExtenedDistance
(
    VAR(APA_FrontExtenedDistance_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtApSignal_Transmission_APA_ParkAssistRExtenedDistance_APA_ParkAssistRExtenedDistance
(
    VAR(APA_ParkAssistRExtenedDistance_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtApSignal_Transmission_APA_ParkAssistRRegion1ObjectSts_APA_ParkAssistRRegion1ObjectSts
(
    VAR(APA_ParkAssistRRegion1ObjectSts_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtApSignal_Transmission_APA_ParkAssistRRegion2ObjectSts_APA_ParkAssistRRegion2ObjectSts
(
    VAR(APA_ParkAssistRRegion2ObjectSts_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtApSignal_Transmission_APA_ParkAssistRRegion3ObjectSts_APA_ParkAssistRRegion3ObjectSts
(
    VAR(APA_ParkAssistRRegion3ObjectSts_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtApSignal_Transmission_APA_ParkAssistRRegion4ObjectSts_APA_ParkAssistRRegion4ObjectSts
(
    VAR(APA_ParkAssistRRegion4ObjectSts_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtApSignal_Transmission_APA_WCBS_BrakeMode_APA_WCBS_BrakeMode
(
    VAR(APA_WCBS_BrakeMode_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtApSignal_Transmission_APA_WCBS_ExpectedGearPosition_APA_WCBS_ExpectedGearPosition
(
    VAR(APA_WCBS_ExpectedGearPosition_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtApSignal_Transmission_APA_WCBS_SpeedLimitation_APA_WCBS_SpeedLimitation
(
    VAR(APA_WCBS_SpeedLimitation_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtApSignal_Transmission_APA_WCBS_TargetStopDistance_APA_WCBS_TargetStopDistance
(
    VAR(APA_WCBS_TargetStopDistance_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtApSignal_Transmission_APA_slot_10_APA_slot_10
(
    VAR(APA_slot_10_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtApSignal_Transmission_APA_slot_11_APA_slot_11
(
    VAR(APA_slot_11_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtApSignal_Transmission_APA_slot_12_APA_slot_12
(
    VAR(APA_slot_12_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtApSignal_Transmission_APA_slot_1_APA_slot_1
(
    VAR(APA_slot_1_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtApSignal_Transmission_APA_slot_2_APA_slot_2
(
    VAR(APA_slot_2_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtApSignal_Transmission_APA_slot_3_APA_slot_3
(
    VAR(APA_slot_3_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtApSignal_Transmission_APA_slot_4_APA_slot_4
(
    VAR(APA_slot_4_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtApSignal_Transmission_APA_slot_5_APA_slot_5
(
    VAR(APA_slot_5_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtApSignal_Transmission_APA_slot_6_APA_slot_6
(
    VAR(APA_slot_6_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtApSignal_Transmission_APA_slot_7_APA_slot_7
(
    VAR(APA_slot_7_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtApSignal_Transmission_APA_slot_8_APA_slot_8
(
    VAR(APA_slot_8_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtApSignal_Transmission_APA_slot_9_APA_slot_9
(
    VAR(APA_slot_9_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtApSignal_Transmission_APA_slot_ID_10_P0_X_APA_slot_ID_10_P0_X
(
    VAR(APA_slot_ID_10_P0_X_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtApSignal_Transmission_APA_slot_ID_10_P0_Y_APA_slot_ID_10_P0_Y
(
    VAR(APA_slot_ID_10_P0_Y_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtApSignal_Transmission_APA_slot_ID_10_P1_X_APA_slot_ID_10_P1_X
(
    VAR(APA_slot_ID_10_P1_X_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtApSignal_Transmission_APA_slot_ID_10_P1_Y_APA_slot_ID_10_P1_Y
(
    VAR(APA_slot_ID_10_P1_Y_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtApSignal_Transmission_APA_slot_ID_10_P2_X_APA_slot_ID_10_P2_X
(
    VAR(APA_slot_ID_10_P2_X_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtApSignal_Transmission_APA_slot_ID_10_P2_Y_APA_slot_ID_10_P2_Y
(
    VAR(APA_slot_ID_10_P2_Y_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtApSignal_Transmission_APA_slot_ID_10_P3_X_APA_slot_ID_10_P3_X
(
    VAR(APA_slot_ID_10_P3_X_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtApSignal_Transmission_APA_slot_ID_10_P3_Y_APA_slot_ID_10_P3_Y
(
    VAR(APA_slot_ID_10_P3_Y_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtApSignal_Transmission_APA_slot_ID_10_Type_APA_slot_ID_10_Type
(
    VAR(APA_slot_ID_10_Type_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtApSignal_Transmission_APA_slot_ID_11_P0_X_APA_slot_ID_11_P0_X
(
    VAR(APA_slot_ID_11_P0_X_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtApSignal_Transmission_APA_slot_ID_11_P0_Y_APA_slot_ID_11_P0_Y
(
    VAR(APA_slot_ID_11_P0_Y_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtApSignal_Transmission_APA_slot_ID_11_P1_X_APA_slot_ID_11_P1_X
(
    VAR(APA_slot_ID_11_P1_X_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtApSignal_Transmission_APA_slot_ID_11_P1_Y_APA_slot_ID_11_P1_Y
(
    VAR(APA_slot_ID_11_P1_Y_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtApSignal_Transmission_APA_slot_ID_11_P2_X_APA_slot_ID_11_P2_X
(
    VAR(APA_slot_ID_11_P2_X_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtApSignal_Transmission_APA_slot_ID_11_P2_Y_APA_slot_ID_11_P2_Y
(
    VAR(APA_slot_ID_11_P2_Y_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtApSignal_Transmission_APA_slot_ID_11_P3_X_APA_slot_ID_11_P3_X
(
    VAR(APA_slot_ID_11_P3_X_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtApSignal_Transmission_APA_slot_ID_11_P3_Y_APA_slot_ID_11_P3_Y
(
    VAR(APA_slot_ID_11_P3_Y_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtApSignal_Transmission_APA_slot_ID_11_Type_APA_slot_ID_11_Type
(
    VAR(APA_slot_ID_11_Type_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtApSignal_Transmission_APA_slot_ID_12_P0_X_APA_slot_ID_12_P0_X
(
    VAR(APA_slot_ID_12_P0_X_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtApSignal_Transmission_APA_slot_ID_12_P0_Y_APA_slot_ID_12_P0_Y
(
    VAR(APA_slot_ID_12_P0_Y_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtApSignal_Transmission_APA_slot_ID_12_P1_X_APA_slot_ID_12_P1_X
(
    VAR(APA_slot_ID_12_P1_X_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtApSignal_Transmission_APA_slot_ID_12_P1_Y_APA_slot_ID_12_P1_Y
(
    VAR(APA_slot_ID_12_P1_Y_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtApSignal_Transmission_APA_slot_ID_12_P2_X_APA_slot_ID_12_P2_X
(
    VAR(APA_slot_ID_12_P2_X_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtApSignal_Transmission_APA_slot_ID_12_P2_Y_APA_slot_ID_12_P2_Y
(
    VAR(APA_slot_ID_12_P2_Y_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtApSignal_Transmission_APA_slot_ID_12_P3_X_APA_slot_ID_12_P3_X
(
    VAR(APA_slot_ID_12_P3_X_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtApSignal_Transmission_APA_slot_ID_12_P3_Y_APA_slot_ID_12_P3_Y
(
    VAR(APA_slot_ID_12_P3_Y_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtApSignal_Transmission_APA_slot_ID_12_Type_APA_slot_ID_12_Type
(
    VAR(APA_slot_ID_12_Type_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtApSignal_Transmission_APA_slot_ID_1_P0_X_APA_slot_ID_1_P0_X
(
    VAR(APA_slot_ID_1_P0_X_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtApSignal_Transmission_APA_slot_ID_1_P0_Y_APA_slot_ID_1_P0_Y
(
    VAR(APA_slot_ID_1_P0_Y_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtApSignal_Transmission_APA_slot_ID_1_P1_X_APA_slot_ID_1_P1_X
(
    VAR(APA_slot_ID_1_P1_X_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtApSignal_Transmission_APA_slot_ID_1_P1_Y_APA_slot_ID_1_P1_Y
(
    VAR(APA_slot_ID_1_P1_Y_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtApSignal_Transmission_APA_slot_ID_1_P2_X_APA_slot_ID_1_P2_X
(
    VAR(APA_slot_ID_1_P2_X_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtApSignal_Transmission_APA_slot_ID_1_P2_Y_APA_slot_ID_1_P2_Y
(
    VAR(APA_slot_ID_1_P2_Y_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtApSignal_Transmission_APA_slot_ID_1_P3_X_APA_slot_ID_1_P3_X
(
    VAR(APA_slot_ID_1_P3_X_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtApSignal_Transmission_APA_slot_ID_1_P3_Y_APA_slot_ID_1_P3_Y
(
    VAR(APA_slot_ID_1_P3_Y_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtApSignal_Transmission_APA_slot_ID_1_Type_APA_slot_ID_1_Type
(
    VAR(APA_slot_ID_1_Type_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtApSignal_Transmission_APA_slot_ID_2_P0_X_APA_slot_ID_2_P0_X
(
    VAR(APA_slot_ID_2_P0_X_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtApSignal_Transmission_APA_slot_ID_2_P0_Y_APA_slot_ID_2_P0_Y
(
    VAR(APA_slot_ID_2_P0_Y_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtApSignal_Transmission_APA_slot_ID_2_P1_X_APA_slot_ID_2_P1_X
(
    VAR(APA_slot_ID_2_P1_X_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtApSignal_Transmission_APA_slot_ID_2_P1_Y_APA_slot_ID_2_P1_Y
(
    VAR(APA_slot_ID_2_P1_Y_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtApSignal_Transmission_APA_slot_ID_2_P2_X_APA_slot_ID_2_P2_X
(
    VAR(APA_slot_ID_2_P2_X_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtApSignal_Transmission_APA_slot_ID_2_P2_Y_APA_slot_ID_2_P2_Y
(
    VAR(APA_slot_ID_2_P2_Y_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtApSignal_Transmission_APA_slot_ID_2_P3_X_APA_slot_ID_2_P3_X
(
    VAR(APA_slot_ID_2_P3_X_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtApSignal_Transmission_APA_slot_ID_2_P3_Y_APA_slot_ID_2_P3_Y
(
    VAR(APA_slot_ID_2_P3_Y_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtApSignal_Transmission_APA_slot_ID_2_Type_APA_slot_ID_2_Type
(
    VAR(APA_slot_ID_2_Type_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtApSignal_Transmission_APA_slot_ID_3_P0_X_APA_slot_ID_3_P0_X
(
    VAR(APA_slot_ID_3_P0_X_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtApSignal_Transmission_APA_slot_ID_3_P0_Y_APA_slot_ID_3_P0_Y
(
    VAR(APA_slot_ID_3_P0_Y_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtApSignal_Transmission_APA_slot_ID_3_P1_X_APA_slot_ID_3_P1_X
(
    VAR(APA_slot_ID_3_P1_X_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtApSignal_Transmission_APA_slot_ID_3_P1_Y_APA_slot_ID_3_P1_Y
(
    VAR(APA_slot_ID_3_P1_Y_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtApSignal_Transmission_APA_slot_ID_3_P2_X_APA_slot_ID_3_P2_X
(
    VAR(APA_slot_ID_3_P2_X_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtApSignal_Transmission_APA_slot_ID_3_P2_Y_APA_slot_ID_3_P2_Y
(
    VAR(APA_slot_ID_3_P2_Y_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtApSignal_Transmission_APA_slot_ID_3_P3_X_APA_slot_ID_3_P3_X
(
    VAR(APA_slot_ID_3_P3_X_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtApSignal_Transmission_APA_slot_ID_3_P3_Y_APA_slot_ID_3_P3_Y
(
    VAR(APA_slot_ID_3_P3_Y_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtApSignal_Transmission_APA_slot_ID_3_Type_APA_slot_ID_3_Type
(
    VAR(APA_slot_ID_3_Type_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtApSignal_Transmission_APA_slot_ID_4_P0_X_APA_slot_ID_4_P0_X
(
    VAR(APA_slot_ID_4_P0_X_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtApSignal_Transmission_APA_slot_ID_4_P0_Y_APA_slot_ID_4_P0_Y
(
    VAR(APA_slot_ID_4_P0_Y_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtApSignal_Transmission_APA_slot_ID_4_P1_X_APA_slot_ID_4_P1_X
(
    VAR(APA_slot_ID_4_P1_X_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtApSignal_Transmission_APA_slot_ID_4_P1_Y_APA_slot_ID_4_P1_Y
(
    VAR(APA_slot_ID_4_P1_Y_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtApSignal_Transmission_APA_slot_ID_4_P2_X_APA_slot_ID_4_P2_X
(
    VAR(APA_slot_ID_4_P2_X_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtApSignal_Transmission_APA_slot_ID_4_P2_Y_APA_slot_ID_4_P2_Y
(
    VAR(APA_slot_ID_4_P2_Y_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtApSignal_Transmission_APA_slot_ID_4_P3_X_APA_slot_ID_4_P3_X
(
    VAR(APA_slot_ID_4_P3_X_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtApSignal_Transmission_APA_slot_ID_4_P3_Y_APA_slot_ID_4_P3_Y
(
    VAR(APA_slot_ID_4_P3_Y_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtApSignal_Transmission_APA_slot_ID_4_Type_APA_slot_ID_4_Type
(
    VAR(APA_slot_ID_4_Type_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtApSignal_Transmission_APA_slot_ID_5_P0_X_APA_slot_ID_5_P0_X
(
    VAR(APA_slot_ID_5_P0_X_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtApSignal_Transmission_APA_slot_ID_5_P0_Y_APA_slot_ID_5_P0_Y
(
    VAR(APA_slot_ID_5_P0_Y_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtApSignal_Transmission_APA_slot_ID_5_P1_X_APA_slot_ID_5_P1_X
(
    VAR(APA_slot_ID_5_P1_X_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtApSignal_Transmission_APA_slot_ID_5_P1_Y_APA_slot_ID_5_P1_Y
(
    VAR(APA_slot_ID_5_P1_Y_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtApSignal_Transmission_APA_slot_ID_5_P2_X_APA_slot_ID_5_P2_X
(
    VAR(APA_slot_ID_5_P2_X_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtApSignal_Transmission_APA_slot_ID_5_P2_Y_APA_slot_ID_5_P2_Y
(
    VAR(APA_slot_ID_5_P2_Y_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtApSignal_Transmission_APA_slot_ID_5_P3_X_APA_slot_ID_5_P3_X
(
    VAR(APA_slot_ID_5_P3_X_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtApSignal_Transmission_APA_slot_ID_5_P3_Y_APA_slot_ID_5_P3_Y
(
    VAR(APA_slot_ID_5_P3_Y_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtApSignal_Transmission_APA_slot_ID_5_Type_APA_slot_ID_5_Type
(
    VAR(APA_slot_ID_5_Type_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtApSignal_Transmission_APA_slot_ID_6_P0_X_APA_slot_ID_6_P0_X
(
    VAR(APA_slot_ID_6_P0_X_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtApSignal_Transmission_APA_slot_ID_6_P0_Y_APA_slot_ID_6_P0_Y
(
    VAR(APA_slot_ID_6_P0_Y_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtApSignal_Transmission_APA_slot_ID_6_P1_X_APA_slot_ID_6_P1_X
(
    VAR(APA_slot_ID_6_P1_X_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtApSignal_Transmission_APA_slot_ID_6_P1_Y_APA_slot_ID_6_P1_Y
(
    VAR(APA_slot_ID_6_P1_Y_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtApSignal_Transmission_APA_slot_ID_6_P2_X_APA_slot_ID_6_P2_X
(
    VAR(APA_slot_ID_6_P2_X_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtApSignal_Transmission_APA_slot_ID_6_P2_Y_APA_slot_ID_6_P2_Y
(
    VAR(APA_slot_ID_6_P2_Y_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtApSignal_Transmission_APA_slot_ID_6_P3_X_APA_slot_ID_6_P3_X
(
    VAR(APA_slot_ID_6_P3_X_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtApSignal_Transmission_APA_slot_ID_6_P3_Y_APA_slot_ID_6_P3_Y
(
    VAR(APA_slot_ID_6_P3_Y_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtApSignal_Transmission_APA_slot_ID_6_Type_APA_slot_ID_6_Type
(
    VAR(APA_slot_ID_6_Type_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtApSignal_Transmission_APA_slot_ID_7_P0_X_APA_slot_ID_7_P0_X
(
    VAR(APA_slot_ID_7_P0_X_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtApSignal_Transmission_APA_slot_ID_7_P0_Y_APA_slot_ID_7_P0_Y
(
    VAR(APA_slot_ID_7_P0_Y_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtApSignal_Transmission_APA_slot_ID_7_P1_X_APA_slot_ID_7_P1_X
(
    VAR(APA_slot_ID_7_P1_X_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtApSignal_Transmission_APA_slot_ID_7_P1_Y_APA_slot_ID_7_P1_Y
(
    VAR(APA_slot_ID_7_P1_Y_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtApSignal_Transmission_APA_slot_ID_7_P2_X_APA_slot_ID_7_P2_X
(
    VAR(APA_slot_ID_7_P2_X_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtApSignal_Transmission_APA_slot_ID_7_P2_Y_APA_slot_ID_7_P2_Y
(
    VAR(APA_slot_ID_7_P2_Y_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtApSignal_Transmission_APA_slot_ID_7_P3_X_APA_slot_ID_7_P3_X
(
    VAR(APA_slot_ID_7_P3_X_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtApSignal_Transmission_APA_slot_ID_7_P3_Y_APA_slot_ID_7_P3_Y
(
    VAR(APA_slot_ID_7_P3_Y_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtApSignal_Transmission_APA_slot_ID_7_Type_APA_slot_ID_7_Type
(
    VAR(APA_slot_ID_7_Type_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtApSignal_Transmission_APA_slot_ID_8_P0_X_APA_slot_ID_8_P0_X
(
    VAR(APA_slot_ID_8_P0_X_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtApSignal_Transmission_APA_slot_ID_8_P0_Y_APA_slot_ID_8_P0_Y
(
    VAR(APA_slot_ID_8_P0_Y_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtApSignal_Transmission_APA_slot_ID_8_P1_X_APA_slot_ID_8_P1_X
(
    VAR(APA_slot_ID_8_P1_X_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtApSignal_Transmission_APA_slot_ID_8_P1_Y_APA_slot_ID_8_P1_Y
(
    VAR(APA_slot_ID_8_P1_Y_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtApSignal_Transmission_APA_slot_ID_8_P2_X_APA_slot_ID_8_P2_X
(
    VAR(APA_slot_ID_8_P2_X_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtApSignal_Transmission_APA_slot_ID_8_P2_Y_APA_slot_ID_8_P2_Y
(
    VAR(APA_slot_ID_8_P2_Y_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtApSignal_Transmission_APA_slot_ID_8_P3_X_APA_slot_ID_8_P3_X
(
    VAR(APA_slot_ID_8_P3_X_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtApSignal_Transmission_APA_slot_ID_8_P3_Y_APA_slot_ID_8_P3_Y
(
    VAR(APA_slot_ID_8_P3_Y_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtApSignal_Transmission_APA_slot_ID_8_Type_APA_slot_ID_8_Type
(
    VAR(APA_slot_ID_8_Type_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtApSignal_Transmission_APA_slot_ID_9_P0_X_APA_slot_ID_9_P0_X
(
    VAR(APA_slot_ID_9_P0_X_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtApSignal_Transmission_APA_slot_ID_9_P0_Y_APA_slot_ID_9_P0_Y
(
    VAR(APA_slot_ID_9_P0_Y_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtApSignal_Transmission_APA_slot_ID_9_P1_X_APA_slot_ID_9_P1_X
(
    VAR(APA_slot_ID_9_P1_X_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtApSignal_Transmission_APA_slot_ID_9_P1_Y_APA_slot_ID_9_P1_Y
(
    VAR(APA_slot_ID_9_P1_Y_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtApSignal_Transmission_APA_slot_ID_9_P2_X_APA_slot_ID_9_P2_X
(
    VAR(APA_slot_ID_9_P2_X_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtApSignal_Transmission_APA_slot_ID_9_P2_Y_APA_slot_ID_9_P2_Y
(
    VAR(APA_slot_ID_9_P2_Y_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtApSignal_Transmission_APA_slot_ID_9_P3_X_APA_slot_ID_9_P3_X
(
    VAR(APA_slot_ID_9_P3_X_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtApSignal_Transmission_APA_slot_ID_9_P3_Y_APA_slot_ID_9_P3_Y
(
    VAR(APA_slot_ID_9_P3_Y_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtApSignal_Transmission_APA_slot_ID_9_Type_APA_slot_ID_9_Type
(
    VAR(APA_slot_ID_9_Type_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtApSignal_Transmission_FLC_ExtenedDistance_FLC_ExtenedDistance
(
    VAR(FLC_ExtenedDistance_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtApSignal_Transmission_FLM_ExtenedDistance_FLM_ExtenedDistance
(
    VAR(FLM_ExtenedDistance_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtApSignal_Transmission_FLS_ExtenedDistance_FLS_ExtenedDistance
(
    VAR(FLS_ExtenedDistance_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtApSignal_Transmission_FRC_ExtenedDistance_FRC_ExtenedDistance
(
    VAR(FRC_ExtenedDistance_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtApSignal_Transmission_FRM_ExtenedDistance_FRM_ExtenedDistance
(
    VAR(FRM_ExtenedDistance_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtApSignal_Transmission_FRS_ExtenedDistance_FRS_ExtenedDistance
(
    VAR(FRS_ExtenedDistance_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtApSignal_Transmission_PiCarInfoH_PiCarInfoH
(
    P2VAR(CarInfoH, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtApSignal_Transmission_PiCarInfoL_PiCarInfoL
(
    P2VAR(CarInfoL, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtApSignal_Transmission_PiImuInfo_PiIMUInfo
(
    P2VAR(IMUInfo, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtApSignal_Transmission_PiManualParkingSlotSet_PiManualParkingSlotSet
(
    P2VAR(ParkingSlotSet, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtApSignal_Transmission_PiSignalTransWorkingStatus_PiSignalTransWorkingStatus
(
    P2VAR(WorkingStatus, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtApSignal_Transmission_RLC_ExtenedDistance_RLC_ExtenedDistance
(
    VAR(RLC_ExtenedDistance_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtApSignal_Transmission_RLM_ExtenedDistance_RLM_ExtenedDistance
(
    VAR(RLM_ExtenedDistance_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtApSignal_Transmission_RLS_ExtenedDistance_RLS_ExtenedDistance
(
    VAR(RLS_ExtenedDistance_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtApSignal_Transmission_RRC_ExtenedDistance_RRC_ExtenedDistance
(
    VAR(RRC_ExtenedDistance_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtApSignal_Transmission_RRM_ExtenedDistance_RRM_ExtenedDistance
(
    VAR(RRM_ExtenedDistance_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtApSignal_Transmission_RRS_ExtenedDistance_RRS_ExtenedDistance
(
    VAR(RRS_ExtenedDistance_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtApSignal_Transmission_ABS_FLWheelDirection_ABS_FLWheelDirection
(
    P2VAR(ABS_FLWheelDirection_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtApSignal_Transmission_ABS_FLWheelSpeedKPH_ABS_FLWheelSpeedKPH
(
    P2VAR(ABS_FLWheelSpeedKPH_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtApSignal_Transmission_ABS_FLWheelSpeedRC_ABS_FLWheelSpeedRC
(
    P2VAR(ABS_FLWheelSpeedRC_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtApSignal_Transmission_ABS_FRWheelDirection_ABS_FRWheelDirection
(
    P2VAR(ABS_FRWheelDirection_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtApSignal_Transmission_ABS_FRWheelSpeedKPH_ABS_FRWheelSpeedKPH
(
    P2VAR(ABS_FRWheelSpeedKPH_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtApSignal_Transmission_ABS_FRWheelSpeedRC_ABS_FRWheelSpeedRC
(
    P2VAR(ABS_FRWheelSpeedRC_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtApSignal_Transmission_ABS_RLWheelDirection_ABS_RLWheelDirection
(
    P2VAR(ABS_RLWheelDirection_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtApSignal_Transmission_ABS_RLWheelSpeedKPH_ABS_RLWheelSpeedKPH
(
    P2VAR(ABS_RLWheelSpeedKPH_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtApSignal_Transmission_ABS_RLWheelSpeedRC_ABS_RLWheelSpeedRC
(
    P2VAR(ABS_RLWheelSpeedRC_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtApSignal_Transmission_ABS_RRWheelDirection_ABS_RRWheelDirection
(
    P2VAR(ABS_RRWheelDirection_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtApSignal_Transmission_ABS_RRWheelSpeedKPH_ABS_RRWheelSpeedKPH
(
    P2VAR(ABS_RRWheelSpeedKPH_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtApSignal_Transmission_ABS_RRWheelSpeedRC_ABS_RRWheelSpeedRC
(
    P2VAR(ABS_RRWheelSpeedRC_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtApSignal_Transmission_ABS_VehicleSpeed_ABS_VehicleSpeed
(
    P2VAR(ABS_VehicleSpeed_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtApSignal_Transmission_AB_BrkPedalSwSts_AB_BrkPedalSwSts
(
    P2VAR(AB_BrkPedalSwSts_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtApSignal_Transmission_AB_BrkPedalTravel_AB_BrkPedalTravel
(
    P2VAR(AB_BrkPedalTravel_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtApSignal_Transmission_AB_Fault_Status_AB_Fault_Status
(
    P2VAR(AB_Fault_Status_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtApSignal_Transmission_ACU_CoDSeatbeltBucklestatus_ACU_CoDSeatbeltBucklestatus
(
    P2VAR(ACU_CoDSeatbeltBucklestatus_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtApSignal_Transmission_ACU_DSeatbeltBucklestatus_ACU_DSeatbeltBucklestatus
(
    P2VAR(ACU_DSeatbeltBucklestatus_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtApSignal_Transmission_BCM_CodriversSideDoorAjarSts_BCM_CodriversSideDoorAjarSts
(
    P2VAR(BCM_CodriversSideDoorAjarSts_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtApSignal_Transmission_BCM_CoverAjarStatus_BCM_CoverAjarStatus
(
    P2VAR(BCM_CoverAjarStatus_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtApSignal_Transmission_BCM_DriverSideDoorAjarSts_BCM_DriverSideDoorAjarSts
(
    P2VAR(BCM_DriverSideDoorAjarSts_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtApSignal_Transmission_BCM_RearLeftDoorAjarStatus_BCM_RearLeftDoorAjarStatus
(
    P2VAR(BCM_RearLeftDoorAjarStatus_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtApSignal_Transmission_BCM_RearRightDoorAjarStatus_BCM_RearRightDoorAjarStatus
(
    P2VAR(BCM_RearRightDoorAjarStatus_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtApSignal_Transmission_BCM_TrunckAjarStatus_BCM_TrunckAjarStatus
(
    P2VAR(BCM_TrunckAjarStatus_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtApSignal_Transmission_CCU_ExternalTemperature_CCU_ExternalTemperature
(
    P2VAR(CCU_ExternalTemperature_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtApSignal_Transmission_EPB_Sts_EPB_Sts
(
    P2VAR(EPB_Sts_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtApSignal_Transmission_EPS_APA_CtrlAbortFeedback_EPS_APA_CtrlAbortFeedback
(
    P2VAR(EPS_APA_CtrlAbortFeedback_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtApSignal_Transmission_EPS_APA_ModActv_EPS_APA_ModActv
(
    P2VAR(EPS_APA_ModActv_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtApSignal_Transmission_EPS_APA_ModAvail_EPS_APA_ModAvail
(
    P2VAR(EPS_APA_ModAvail_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtApSignal_Transmission_EPS_DrStrTorqVal_EPS_DrStrTorqVal
(
    P2VAR(EPS_DrStrTorqVal_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtApSignal_Transmission_ESC_LateralACC_ESC_LateralACC
(
    P2VAR(ESC_LateralACC_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtApSignal_Transmission_ESC_LongitudeACC_ESC_LongitudeACC
(
    P2VAR(ESC_LongitudeACC_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtApSignal_Transmission_ESC_MasterCylinderPressure_ESC_MasterCylinderPressure
(
    P2VAR(ESC_MasterCylinderPressure_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtApSignal_Transmission_ESC_SlopeGradeAngle_ESC_SlopeGradeAngle
(
    P2VAR(ESC_SlopeGradeAngle_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtApSignal_Transmission_ESC_VehDynYawRate_ESC_VehDynYawRate
(
    P2VAR(ESC_VehDynYawRate_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtApSignal_Transmission_MHU_APA_ParkingSpace_ID_MHU_APA_ParkingSpace_ID
(
    P2VAR(MHU_APA_ParkingSpace_ID_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtApSignal_Transmission_MHU_UPAMuteSwitch_MHU_UPAMuteSwitch
(
    P2VAR(MHU_UPAMuteSwitch_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtApSignal_Transmission_PEPS_IGN1RelaySts_PEPS_IGN1RelaySts
(
    P2VAR(PEPS_IGN1RelaySts_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtApSignal_Transmission_PEPS_PowerMode_PEPS_PowerMode
(
    P2VAR(PEPS_PowerMode_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtApSignal_Transmission_PiAvmFusionParkingSlot_PiAvmFusionParkingSlot
(
    P2VAR(ParkingSlotSet, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtApSignal_Transmission_PiCarControlCommandH_PiCarControlCommandH
(
    P2VAR(CarControlCommandH, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtApSignal_Transmission_PiCarControlCommandL_PiCarControlCommandL
(
    P2VAR(CarControlCommandL, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtApSignal_Transmission_PiGuideLine_PiGuideLine
(
    P2VAR(GuideLine, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtApSignal_Transmission_PiUssPdcInfo_PiUssPdcInfo
(
    P2VAR(UssPdcInfo, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtApSignal_Transmission_SAS_SteerWheelAngle_SAS_SteerWheelAngle
(
    P2VAR(SAS_SteerWheelAngle_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtApSignal_Transmission_SAS_SteerWhlRotSpdStatus_SAS_SteerWhlRotSpdStatus
(
    P2VAR(SAS_SteerWhlRotSpdStatus_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtApSignal_Transmission_SAS_SteerWhlRotSpd_SAS_SteerWhlRotSpd
(
    P2VAR(SAS_SteerWhlRotSpd_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtApSignal_Transmission_TPMS_LFpressureSts_TPMS_LFpressureSts
(
    P2VAR(TPMS_LFpressureSts_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtApSignal_Transmission_TPMS_LFpressure_TPMS_LFpressure
(
    P2VAR(TPMS_LFpressure_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtApSignal_Transmission_TPMS_LRpressureSts_TPMS_LRpressureSts
(
    P2VAR(TPMS_LRpressureSts_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtApSignal_Transmission_TPMS_LRpressure_TPMS_LRpressure
(
    P2VAR(TPMS_LRpressure_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtApSignal_Transmission_TPMS_RFpressureSts_TPMS_RFpressureSts
(
    P2VAR(TPMS_RFpressureSts_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtApSignal_Transmission_TPMS_RFpressure_TPMS_RFpressure
(
    P2VAR(TPMS_RFpressure_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtApSignal_Transmission_TPMS_RRpressureSts_TPMS_RRpressureSts
(
    P2VAR(TPMS_RRpressureSts_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtApSignal_Transmission_TPMS_RRpressure_TPMS_RRpressure
(
    P2VAR(TPMS_RRpressure_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtApSignal_Transmission_TimeStamp_ABS_FrontWheelSpeMCUKPH_0x122_TimeStamp_ABS_FrontWheelSpeMCUKPH_0x122
(
    P2VAR(uint64, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtApSignal_Transmission_TimeStamp_ABS_RearWheelSpeMCUKPH_0x123_TimeStamp_ABS_RearWheelSpeMCUKPH_0x123
(
    P2VAR(uint64, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtApSignal_Transmission_TimeStamp_ABS_Status_0x125_TimeStamp_ABS_Status_0x125
(
    P2VAR(uint64, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtApSignal_Transmission_TimeStamp_ABS_WheelSpeedRC_0x124_TimeStamp_ABS_WheelSpeedRC_0x124
(
    P2VAR(uint64, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtApSignal_Transmission_TimeStamp_ESC_YawAngle_0x3E2_TimeStamp_ESC_YawAngle_0x3E2
(
    P2VAR(uint64, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtApSignal_Transmission_TimeStamp_IBS_ADAS_Info_0x269_TimeStamp_IBS_ADAS_Info_0x269
(
    P2VAR(uint64, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtApSignal_Transmission_TimeStamp_SAS_Sensor_0x17E_TimeStamp_SAS_Sensor_0x17E
(
    P2VAR(uint64, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtApSignal_Transmission_TimeStamp_VCU_Ctrl_0x162_TimeStamp_VCU_Ctrl_0x162
(
    P2VAR(uint64, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtApSignal_Transmission_VCU_AccPedalPosition_VCU_AccPedalPosition
(
    P2VAR(VCU_AccPedalPosition_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtApSignal_Transmission_VCU_ModeGearSts_VCU_ModeGearSts
(
    P2VAR(VCU_ModeGearSts_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtApSignal_Transmission_VCU_StsSysFault_VCU_StsSysFault
(
    P2VAR(VCU_StsSysFault_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtApSignal_Transmission_WCBS_APA_CDD_Active_WCBS_APA_CDD_Active
(
    P2VAR(WCBS_APA_CDD_Active_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtApSignal_Transmission_WCBS_APA_VLC_Active_WCBS_APA_VLC_Active
(
    P2VAR(WCBS_APA_VLC_Active_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtApSignal_Transmission_WCBS_APA_VLC_Available_WCBS_APA_VLC_Available
(
    P2VAR(WCBS_APA_VLC_Available_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtApSignal_Transmission_WCBS_APA_VLC_FailureStatus_WCBS_APA_VLC_FailureStatus
(
    P2VAR(WCBS_APA_VLC_FailureStatus_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtApSignal_Transmission_WCBS_APA_VLC_Status_WCBS_APA_VLC_Status
(
    P2VAR(WCBS_APA_VLC_Status_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtApSignal_Transmission_WCBS_VStandstillSta_WCBS_VStandstillSta
(
    P2VAR(WCBS_VStandstillSta_IDT, AUTOMATIC, RTE_APPL_DATA) data
);

/*******************************************************************************
*   Runnable Extended
*******************************************************************************/

#define CtApSignal_Transmission_START_SEC_CODE
#include "CtApSignal_Transmission_MemMap.h"

extern FUNC(void, CtApSignal_Transmission_CODE) Signal_Transmission_init
(
    void
);
#define CtApSignal_Transmission_STOP_SEC_CODE
#include "CtApSignal_Transmission_MemMap.h"


#define CtApSignal_Transmission_START_SEC_CODE
#include "CtApSignal_Transmission_MemMap.h"

extern FUNC(void, CtApSignal_Transmission_CODE) TSK_Signal_Transmission_10ms
(
    void
);
#define CtApSignal_Transmission_STOP_SEC_CODE
#include "CtApSignal_Transmission_MemMap.h"


# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif  /*RTE_CTAPSIGNAL_TRANSMISSION_H*/


