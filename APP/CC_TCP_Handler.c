/*  BEGIN_FILE_HDR
********************************************************************************
*   File Name       : CC_TCP_Handler.c
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
#include "Rte_CC_TCP_Handler.h"

/* CC_TCP_HandlerInput File User Code start*/

/* CC_TCP_HandlerInput File User Code end*/

/* CC_TCP_Handler.c Custom Code (#define variable etc.) User Code start*/

/* CC_TCP_Handler.c Custom Code (#define variable etc.) User Code end*/

/*******************************************************************************
*   Runnable Extended
*******************************************************************************/

#define CC_TCP_Handler_START_SEC_CODE
#include "CC_TCP_Handler_MemMap.h"

FUNC(void, CC_TCP_Handler_CODE) CC_TCP_Handler_Init
(
    void
)
{
    /* CC_TCP_Handler_Init_Start User Code start*/

    /* CC_TCP_Handler_Init_Start User Code end*/
    /* CC_TCP_Handler_Init Varaible Define User Code start*/

    /* CC_TCP_Handler_Init Varaible Define User Code end*/




    /* CC_TCP_Handler_Init_Feedback User Code start*/

    /* CC_TCP_Handler_Init_Feedback User Code end*/

}
#define CC_TCP_Handler_STOP_SEC_CODE
#include "CC_TCP_Handler_MemMap.h"


#define CC_TCP_Handler_START_SEC_CODE
#include "CC_TCP_Handler_MemMap.h"

FUNC(void, CC_TCP_Handler_CODE) CC_TCP_Handler
(
    void
)
{
    /* CC_TCP_Handler_Start User Code start*/

    /* CC_TCP_Handler_Start User Code end*/
    DesiredTrajectoryGeneral Write_PiApaDesiredTrajectoryGeneral_PiApaDesiredTrajectoryGeneral;
    ParkingSlotSet Write_PiAvmFusionParkingSlot_PiAvmFusionParkingSlot;
    FreespaceSet Write_PiFusionFreespaceSet_PiFusionFreespaceSet;
    ParkingSlotSet Write_PiFusionParkingSlotSet_PiFusionParkingSlotSet;
    WorkingStatus Write_PiFusionStatus_PiFusionStatus;
    GuideLine Write_PiGuideLine_PiGuideLine;
    ParkingSlotError Write_PiParkingSlotError_PiParkingSlotError;
    WorkingStatus Write_PiPlanningWorkingStatus_PiPlanningWorkingStatus;
    WorkingStatus Write_PiUssFsdWorkingStatus_PiUssFsdWorkingStatus;
    VisionCal Write_PiVisionCal_PiVisionCal;
    VisionFailSafe Write_PiVisionFailSafe_PiVisionFailSafe;
    VisionLaneSet Write_PiVisionLaneSet_PiVisionLaneSet;
    VisionObjectSet Write_PiVisionObjectSet_PiVisionObjectSet;
    WorkingStatus Write_PiVisionStatus_PiVisionStatus;
    VisionTrafficSignSet Write_PiVisionTrafficSignSet_PiVisionTrafficSignSet;
    Vision_WorkingStus Write_PiVision_WorkingStus_PiVision_WorkingStus;
    Udp_SendSignal_1501_IDT Write_Udp_SendSignal_1501_Udp_SendSignal_1501;
    Udp_SendSignal_1502_IDT Write_Udp_SendSignal_1502_Udp_SendSignal_1502;
    Udp_SendSignal_1503_IDT Write_Udp_SendSignal_1503_Udp_SendSignal_1503;
    Udp_SendSignal_1504_IDT Write_Udp_SendSignal_1504_Udp_SendSignal_1504;
    Udp_SendSignal_1505_IDT Write_Udp_SendSignal_1505_Udp_SendSignal_1505;
    Udp_SendSignal_1506_IDT Write_Udp_SendSignal_1506_Udp_SendSignal_1506;
    Udp_SendSignal_1507_IDT Write_Udp_SendSignal_1507_Udp_SendSignal_1507;
    APAControlState Read_PiAPAControlState_PiAPAControlState;
    CarInfoH Read_PiCarInfoH_PiCarInfoH;
    CarInfoL Read_PiCarInfoL_PiCarInfoL;
    GlobalPoseBuffer Read_PiGlobalPoseBuffer_PiGlobalPoseBuffer;
    ParkingSlotSet Read_PiManualParkingSlotSet_PiManualParkingSlotSet;
    PerceptionCommand Read_PiPerceptionCommand_PiPerceptionCommand;
    UssInfo Read_PiUssInfo_PiUssInfo;
    UssRawDataSet Read_PiUssRawDataSet_PiUssRawDataSet;
    UssStatusSet Read_PiUssStatusSet_PiUssStatusSet;
    VehicleInfo Read_PiVehicleInfo_PiVehicleInfo;
    VisionPerceptionControl Read_PiVisionPerceptionControl_PiVisionPerceptionControl;
    Tcp_ReceiveSignal_1601_IDT Read_Tcp_ReceiveSignal_1601_Tcp_ReceiveSignal_1601;
    Tcp_ReceiveSignal_1602_IDT Read_Tcp_ReceiveSignal_1602_Tcp_ReceiveSignal_1602;
    Tcp_ReceiveSignal_1603_IDT Read_Tcp_ReceiveSignal_1603_Tcp_ReceiveSignal_1603;
    Tcp_ReceiveSignal_1604_IDT Read_Tcp_ReceiveSignal_1604_Tcp_ReceiveSignal_1604;
    Tcp_ReceiveSignal_1605_IDT Read_Tcp_ReceiveSignal_1605_Tcp_ReceiveSignal_1605;
    Tcp_ReceiveSignal_1606_IDT Read_Tcp_ReceiveSignal_1606_Tcp_ReceiveSignal_1606;
    Tcp_ReceiveSignal_1607_IDT Read_Tcp_ReceiveSignal_1607_Tcp_ReceiveSignal_1607;
    Tcp_ReceiveSignal_1608_IDT Read_Tcp_ReceiveSignal_1608_Tcp_ReceiveSignal_1608;
    /* CC_TCP_Handler Varaible Define User Code start*/

    /* CC_TCP_Handler Varaible Define User Code end*/




    Rte_Write_PiApaDesiredTrajectoryGeneral_PiApaDesiredTrajectoryGeneral(&Write_PiApaDesiredTrajectoryGeneral_PiApaDesiredTrajectoryGeneral);
    /* Rte_Write_PiApaDesiredTrajectoryGeneral_PiApaDesiredTrajectoryGeneral User Code start*/

    /* Rte_Write_PiApaDesiredTrajectoryGeneral_PiApaDesiredTrajectoryGeneral User Code end*/
    Rte_Write_PiAvmFusionParkingSlot_PiAvmFusionParkingSlot(&Write_PiAvmFusionParkingSlot_PiAvmFusionParkingSlot);
    /* Rte_Write_PiAvmFusionParkingSlot_PiAvmFusionParkingSlot User Code start*/

    /* Rte_Write_PiAvmFusionParkingSlot_PiAvmFusionParkingSlot User Code end*/
    Rte_Write_PiFusionFreespaceSet_PiFusionFreespaceSet(&Write_PiFusionFreespaceSet_PiFusionFreespaceSet);
    /* Rte_Write_PiFusionFreespaceSet_PiFusionFreespaceSet User Code start*/

    /* Rte_Write_PiFusionFreespaceSet_PiFusionFreespaceSet User Code end*/
    Rte_Write_PiFusionParkingSlotSet_PiFusionParkingSlotSet(&Write_PiFusionParkingSlotSet_PiFusionParkingSlotSet);
    /* Rte_Write_PiFusionParkingSlotSet_PiFusionParkingSlotSet User Code start*/

    /* Rte_Write_PiFusionParkingSlotSet_PiFusionParkingSlotSet User Code end*/
    Rte_Write_PiFusionStatus_PiFusionStatus(&Write_PiFusionStatus_PiFusionStatus);
    /* Rte_Write_PiFusionStatus_PiFusionStatus User Code start*/

    /* Rte_Write_PiFusionStatus_PiFusionStatus User Code end*/
    Rte_Write_PiGuideLine_PiGuideLine(&Write_PiGuideLine_PiGuideLine);
    /* Rte_Write_PiGuideLine_PiGuideLine User Code start*/

    /* Rte_Write_PiGuideLine_PiGuideLine User Code end*/
    Rte_Write_PiParkingSlotError_PiParkingSlotError(&Write_PiParkingSlotError_PiParkingSlotError);
    /* Rte_Write_PiParkingSlotError_PiParkingSlotError User Code start*/

    /* Rte_Write_PiParkingSlotError_PiParkingSlotError User Code end*/
    Rte_Write_PiPlanningWorkingStatus_PiPlanningWorkingStatus(&Write_PiPlanningWorkingStatus_PiPlanningWorkingStatus);
    /* Rte_Write_PiPlanningWorkingStatus_PiPlanningWorkingStatus User Code start*/

    /* Rte_Write_PiPlanningWorkingStatus_PiPlanningWorkingStatus User Code end*/
    Rte_Write_PiUssFsdWorkingStatus_PiUssFsdWorkingStatus(&Write_PiUssFsdWorkingStatus_PiUssFsdWorkingStatus);
    /* Rte_Write_PiUssFsdWorkingStatus_PiUssFsdWorkingStatus User Code start*/

    /* Rte_Write_PiUssFsdWorkingStatus_PiUssFsdWorkingStatus User Code end*/
    Rte_Write_PiVisionCal_PiVisionCal(&Write_PiVisionCal_PiVisionCal);
    /* Rte_Write_PiVisionCal_PiVisionCal User Code start*/

    /* Rte_Write_PiVisionCal_PiVisionCal User Code end*/
    Rte_Write_PiVisionFailSafe_PiVisionFailSafe(&Write_PiVisionFailSafe_PiVisionFailSafe);
    /* Rte_Write_PiVisionFailSafe_PiVisionFailSafe User Code start*/

    /* Rte_Write_PiVisionFailSafe_PiVisionFailSafe User Code end*/
    Rte_Write_PiVisionLaneSet_PiVisionLaneSet(&Write_PiVisionLaneSet_PiVisionLaneSet);
    /* Rte_Write_PiVisionLaneSet_PiVisionLaneSet User Code start*/

    /* Rte_Write_PiVisionLaneSet_PiVisionLaneSet User Code end*/
    Rte_Write_PiVisionObjectSet_PiVisionObjectSet(&Write_PiVisionObjectSet_PiVisionObjectSet);
    /* Rte_Write_PiVisionObjectSet_PiVisionObjectSet User Code start*/

    /* Rte_Write_PiVisionObjectSet_PiVisionObjectSet User Code end*/
    Rte_Write_PiVisionStatus_PiVisionStatus(&Write_PiVisionStatus_PiVisionStatus);
    /* Rte_Write_PiVisionStatus_PiVisionStatus User Code start*/

    /* Rte_Write_PiVisionStatus_PiVisionStatus User Code end*/
    Rte_Write_PiVisionTrafficSignSet_PiVisionTrafficSignSet(&Write_PiVisionTrafficSignSet_PiVisionTrafficSignSet);
    /* Rte_Write_PiVisionTrafficSignSet_PiVisionTrafficSignSet User Code start*/

    /* Rte_Write_PiVisionTrafficSignSet_PiVisionTrafficSignSet User Code end*/
    Rte_Write_PiVision_WorkingStus_PiVision_WorkingStus(&Write_PiVision_WorkingStus_PiVision_WorkingStus);
    /* Rte_Write_PiVision_WorkingStus_PiVision_WorkingStus User Code start*/

    /* Rte_Write_PiVision_WorkingStus_PiVision_WorkingStus User Code end*/
    Rte_Write_Udp_SendSignal_1501_Udp_SendSignal_1501(Write_Udp_SendSignal_1501_Udp_SendSignal_1501);
    /* Rte_Write_Udp_SendSignal_1501_Udp_SendSignal_1501 User Code start*/

    /* Rte_Write_Udp_SendSignal_1501_Udp_SendSignal_1501 User Code end*/
    Rte_Write_Udp_SendSignal_1502_Udp_SendSignal_1502(Write_Udp_SendSignal_1502_Udp_SendSignal_1502);
    /* Rte_Write_Udp_SendSignal_1502_Udp_SendSignal_1502 User Code start*/

    /* Rte_Write_Udp_SendSignal_1502_Udp_SendSignal_1502 User Code end*/
    Rte_Write_Udp_SendSignal_1503_Udp_SendSignal_1503(Write_Udp_SendSignal_1503_Udp_SendSignal_1503);
    /* Rte_Write_Udp_SendSignal_1503_Udp_SendSignal_1503 User Code start*/

    /* Rte_Write_Udp_SendSignal_1503_Udp_SendSignal_1503 User Code end*/
    Rte_Write_Udp_SendSignal_1504_Udp_SendSignal_1504(Write_Udp_SendSignal_1504_Udp_SendSignal_1504);
    /* Rte_Write_Udp_SendSignal_1504_Udp_SendSignal_1504 User Code start*/

    /* Rte_Write_Udp_SendSignal_1504_Udp_SendSignal_1504 User Code end*/
    Rte_Write_Udp_SendSignal_1505_Udp_SendSignal_1505(Write_Udp_SendSignal_1505_Udp_SendSignal_1505);
    /* Rte_Write_Udp_SendSignal_1505_Udp_SendSignal_1505 User Code start*/

    /* Rte_Write_Udp_SendSignal_1505_Udp_SendSignal_1505 User Code end*/
    Rte_Write_Udp_SendSignal_1506_Udp_SendSignal_1506(Write_Udp_SendSignal_1506_Udp_SendSignal_1506);
    /* Rte_Write_Udp_SendSignal_1506_Udp_SendSignal_1506 User Code start*/

    /* Rte_Write_Udp_SendSignal_1506_Udp_SendSignal_1506 User Code end*/
    Rte_Write_Udp_SendSignal_1507_Udp_SendSignal_1507(Write_Udp_SendSignal_1507_Udp_SendSignal_1507);
    /* Rte_Write_Udp_SendSignal_1507_Udp_SendSignal_1507 User Code start*/

    /* Rte_Write_Udp_SendSignal_1507_Udp_SendSignal_1507 User Code end*/
    Rte_Read_PiAPAControlState_PiAPAControlState(&Read_PiAPAControlState_PiAPAControlState);
    /* Rte_Read_PiAPAControlState_PiAPAControlState User Code start*/

    /* Rte_Read_PiAPAControlState_PiAPAControlState User Code end*/
    Rte_Read_PiCarInfoH_PiCarInfoH(&Read_PiCarInfoH_PiCarInfoH);
    /* Rte_Read_PiCarInfoH_PiCarInfoH User Code start*/

    /* Rte_Read_PiCarInfoH_PiCarInfoH User Code end*/
    Rte_Read_PiCarInfoL_PiCarInfoL(&Read_PiCarInfoL_PiCarInfoL);
    /* Rte_Read_PiCarInfoL_PiCarInfoL User Code start*/

    /* Rte_Read_PiCarInfoL_PiCarInfoL User Code end*/
    Rte_Read_PiGlobalPoseBuffer_PiGlobalPoseBuffer(&Read_PiGlobalPoseBuffer_PiGlobalPoseBuffer);
    /* Rte_Read_PiGlobalPoseBuffer_PiGlobalPoseBuffer User Code start*/

    /* Rte_Read_PiGlobalPoseBuffer_PiGlobalPoseBuffer User Code end*/
    Rte_Read_PiManualParkingSlotSet_PiManualParkingSlotSet(&Read_PiManualParkingSlotSet_PiManualParkingSlotSet);
    /* Rte_Read_PiManualParkingSlotSet_PiManualParkingSlotSet User Code start*/

    /* Rte_Read_PiManualParkingSlotSet_PiManualParkingSlotSet User Code end*/
    Rte_Read_PiPerceptionCommand_PiPerceptionCommand(&Read_PiPerceptionCommand_PiPerceptionCommand);
    /* Rte_Read_PiPerceptionCommand_PiPerceptionCommand User Code start*/

    /* Rte_Read_PiPerceptionCommand_PiPerceptionCommand User Code end*/
    Rte_Read_PiUssInfo_PiUssInfo(&Read_PiUssInfo_PiUssInfo);
    /* Rte_Read_PiUssInfo_PiUssInfo User Code start*/

    /* Rte_Read_PiUssInfo_PiUssInfo User Code end*/
    Rte_Read_PiUssRawDataSet_PiUssRawDataSet(&Read_PiUssRawDataSet_PiUssRawDataSet);
    /* Rte_Read_PiUssRawDataSet_PiUssRawDataSet User Code start*/

    /* Rte_Read_PiUssRawDataSet_PiUssRawDataSet User Code end*/
    Rte_Read_PiUssStatusSet_PiUssStatusSet(&Read_PiUssStatusSet_PiUssStatusSet);
    /* Rte_Read_PiUssStatusSet_PiUssStatusSet User Code start*/

    /* Rte_Read_PiUssStatusSet_PiUssStatusSet User Code end*/
    Rte_Read_PiVehicleInfo_PiVehicleInfo(&Read_PiVehicleInfo_PiVehicleInfo);
    /* Rte_Read_PiVehicleInfo_PiVehicleInfo User Code start*/

    /* Rte_Read_PiVehicleInfo_PiVehicleInfo User Code end*/
    Rte_Read_PiVisionPerceptionControl_PiVisionPerceptionControl(&Read_PiVisionPerceptionControl_PiVisionPerceptionControl);
    /* Rte_Read_PiVisionPerceptionControl_PiVisionPerceptionControl User Code start*/

    /* Rte_Read_PiVisionPerceptionControl_PiVisionPerceptionControl User Code end*/
    Rte_Read_Tcp_ReceiveSignal_1601_Tcp_ReceiveSignal_1601(Read_Tcp_ReceiveSignal_1601_Tcp_ReceiveSignal_1601);
    /* Rte_Read_Tcp_ReceiveSignal_1601_Tcp_ReceiveSignal_1601 User Code start*/

    /* Rte_Read_Tcp_ReceiveSignal_1601_Tcp_ReceiveSignal_1601 User Code end*/
    Rte_Read_Tcp_ReceiveSignal_1602_Tcp_ReceiveSignal_1602(Read_Tcp_ReceiveSignal_1602_Tcp_ReceiveSignal_1602);
    /* Rte_Read_Tcp_ReceiveSignal_1602_Tcp_ReceiveSignal_1602 User Code start*/

    /* Rte_Read_Tcp_ReceiveSignal_1602_Tcp_ReceiveSignal_1602 User Code end*/
    Rte_Read_Tcp_ReceiveSignal_1603_Tcp_ReceiveSignal_1603(Read_Tcp_ReceiveSignal_1603_Tcp_ReceiveSignal_1603);
    /* Rte_Read_Tcp_ReceiveSignal_1603_Tcp_ReceiveSignal_1603 User Code start*/

    /* Rte_Read_Tcp_ReceiveSignal_1603_Tcp_ReceiveSignal_1603 User Code end*/
    Rte_Read_Tcp_ReceiveSignal_1604_Tcp_ReceiveSignal_1604(Read_Tcp_ReceiveSignal_1604_Tcp_ReceiveSignal_1604);
    /* Rte_Read_Tcp_ReceiveSignal_1604_Tcp_ReceiveSignal_1604 User Code start*/

    /* Rte_Read_Tcp_ReceiveSignal_1604_Tcp_ReceiveSignal_1604 User Code end*/
    Rte_Read_Tcp_ReceiveSignal_1605_Tcp_ReceiveSignal_1605(Read_Tcp_ReceiveSignal_1605_Tcp_ReceiveSignal_1605);
    /* Rte_Read_Tcp_ReceiveSignal_1605_Tcp_ReceiveSignal_1605 User Code start*/

    /* Rte_Read_Tcp_ReceiveSignal_1605_Tcp_ReceiveSignal_1605 User Code end*/
    Rte_Read_Tcp_ReceiveSignal_1606_Tcp_ReceiveSignal_1606(Read_Tcp_ReceiveSignal_1606_Tcp_ReceiveSignal_1606);
    /* Rte_Read_Tcp_ReceiveSignal_1606_Tcp_ReceiveSignal_1606 User Code start*/

    /* Rte_Read_Tcp_ReceiveSignal_1606_Tcp_ReceiveSignal_1606 User Code end*/
    Rte_Read_Tcp_ReceiveSignal_1607_Tcp_ReceiveSignal_1607(Read_Tcp_ReceiveSignal_1607_Tcp_ReceiveSignal_1607);
    /* Rte_Read_Tcp_ReceiveSignal_1607_Tcp_ReceiveSignal_1607 User Code start*/

    /* Rte_Read_Tcp_ReceiveSignal_1607_Tcp_ReceiveSignal_1607 User Code end*/
    Rte_Read_Tcp_ReceiveSignal_1608_Tcp_ReceiveSignal_1608(Read_Tcp_ReceiveSignal_1608_Tcp_ReceiveSignal_1608);
    /* Rte_Read_Tcp_ReceiveSignal_1608_Tcp_ReceiveSignal_1608 User Code start*/

    /* Rte_Read_Tcp_ReceiveSignal_1608_Tcp_ReceiveSignal_1608 User Code end*/
    /* CC_TCP_Handler_Feedback User Code start*/

    /* CC_TCP_Handler_Feedback User Code end*/

}
#define CC_TCP_Handler_STOP_SEC_CODE
#include "CC_TCP_Handler_MemMap.h"




