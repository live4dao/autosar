/*  BEGIN_FILE_HDR
********************************************************************************
*   File Name       : Rte_CC_TCP_Handler.h
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
#ifndef RTE_CC_TCP_HANDLER_H
#define RTE_CC_TCP_HANDLER_H

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
#include "Rte_CC_TCP_Handler_Type.h"
#include "Com.h"
/*******************************************************************************
*   define for a symbolic name of the RunnableEntity.
*******************************************************************************/
#define RTE_RUNNABLE_CC_TCP_Handler                         CC_TCP_Handler
#define RTE_RUNNABLE_CC_TCP_Handler_Init                    CC_TCP_Handler_Init

/*******************************************************************************
*   Instance Handle
*******************************************************************************/
#ifndef RTE_CORE
typedef CONSTP2CONST(Rte_CDS_CC_TCP_Handler, AUTOMATIC, RTE_CONST) Rte_Instance;
#endif

/*******************************************************************************
*   Macro definition.
*******************************************************************************/
#define Rte_Write_PiApaDesiredTrajectoryGeneral_PiApaDesiredTrajectoryGeneral   Rte_Write_CC_TCP_Handler_PiApaDesiredTrajectoryGeneral_PiApaDesiredTrajectoryGeneral
#define Rte_Write_PiAvmFusionParkingSlot_PiAvmFusionParkingSlot       Rte_Write_CC_TCP_Handler_PiAvmFusionParkingSlot_PiAvmFusionParkingSlot
#define Rte_Write_PiFusionFreespaceSet_PiFusionFreespaceSet Rte_Write_CC_TCP_Handler_PiFusionFreespaceSet_PiFusionFreespaceSet
#define Rte_Write_PiFusionParkingSlotSet_PiFusionParkingSlotSet       Rte_Write_CC_TCP_Handler_PiFusionParkingSlotSet_PiFusionParkingSlotSet
#define Rte_Write_PiFusionStatus_PiFusionStatus             Rte_Write_CC_TCP_Handler_PiFusionStatus_PiFusionStatus
#define Rte_Write_PiGuideLine_PiGuideLine                   Rte_Write_CC_TCP_Handler_PiGuideLine_PiGuideLine
#define Rte_Write_PiParkingSlotError_PiParkingSlotError     Rte_Write_CC_TCP_Handler_PiParkingSlotError_PiParkingSlotError
#define Rte_Write_PiPlanningWorkingStatus_PiPlanningWorkingStatus     Rte_Write_CC_TCP_Handler_PiPlanningWorkingStatus_PiPlanningWorkingStatus
#define Rte_Write_PiUssFsdWorkingStatus_PiUssFsdWorkingStatus         Rte_Write_CC_TCP_Handler_PiUssFsdWorkingStatus_PiUssFsdWorkingStatus
#define Rte_Write_PiVisionCal_PiVisionCal                   Rte_Write_CC_TCP_Handler_PiVisionCal_PiVisionCal
#define Rte_Write_PiVisionFailSafe_PiVisionFailSafe         Rte_Write_CC_TCP_Handler_PiVisionFailSafe_PiVisionFailSafe
#define Rte_Write_PiVisionLaneSet_PiVisionLaneSet           Rte_Write_CC_TCP_Handler_PiVisionLaneSet_PiVisionLaneSet
#define Rte_Write_PiVisionObjectSet_PiVisionObjectSet       Rte_Write_CC_TCP_Handler_PiVisionObjectSet_PiVisionObjectSet
#define Rte_Write_PiVisionStatus_PiVisionStatus             Rte_Write_CC_TCP_Handler_PiVisionStatus_PiVisionStatus
#define Rte_Write_PiVisionTrafficSignSet_PiVisionTrafficSignSet       Rte_Write_CC_TCP_Handler_PiVisionTrafficSignSet_PiVisionTrafficSignSet
#define Rte_Write_PiVision_WorkingStus_PiVision_WorkingStus Rte_Write_CC_TCP_Handler_PiVision_WorkingStus_PiVision_WorkingStus
#define Rte_Write_Udp_SendSignal_1501_Udp_SendSignal_1501   Rte_Write_CC_TCP_Handler_Udp_SendSignal_1501_Udp_SendSignal_1501
#define Rte_Write_Udp_SendSignal_1502_Udp_SendSignal_1502   Rte_Write_CC_TCP_Handler_Udp_SendSignal_1502_Udp_SendSignal_1502
#define Rte_Write_Udp_SendSignal_1503_Udp_SendSignal_1503   Rte_Write_CC_TCP_Handler_Udp_SendSignal_1503_Udp_SendSignal_1503
#define Rte_Write_Udp_SendSignal_1504_Udp_SendSignal_1504   Rte_Write_CC_TCP_Handler_Udp_SendSignal_1504_Udp_SendSignal_1504
#define Rte_Write_Udp_SendSignal_1505_Udp_SendSignal_1505   Rte_Write_CC_TCP_Handler_Udp_SendSignal_1505_Udp_SendSignal_1505
#define Rte_Write_Udp_SendSignal_1506_Udp_SendSignal_1506   Rte_Write_CC_TCP_Handler_Udp_SendSignal_1506_Udp_SendSignal_1506
#define Rte_Write_Udp_SendSignal_1507_Udp_SendSignal_1507   Rte_Write_CC_TCP_Handler_Udp_SendSignal_1507_Udp_SendSignal_1507
#define Rte_Read_PiAPAControlState_PiAPAControlState        Rte_Read_CC_TCP_Handler_PiAPAControlState_PiAPAControlState
#define Rte_Read_PiCarInfoH_PiCarInfoH                      Rte_Read_CC_TCP_Handler_PiCarInfoH_PiCarInfoH
#define Rte_Read_PiCarInfoL_PiCarInfoL                      Rte_Read_CC_TCP_Handler_PiCarInfoL_PiCarInfoL
#define Rte_Read_PiGlobalPoseBuffer_PiGlobalPoseBuffer      Rte_Read_CC_TCP_Handler_PiGlobalPoseBuffer_PiGlobalPoseBuffer
#define Rte_Read_PiManualParkingSlotSet_PiManualParkingSlotSet        Rte_Read_CC_TCP_Handler_PiManualParkingSlotSet_PiManualParkingSlotSet
#define Rte_Read_PiPerceptionCommand_PiPerceptionCommand    Rte_Read_CC_TCP_Handler_PiPerceptionCommand_PiPerceptionCommand
#define Rte_Read_PiUssInfo_PiUssInfo                        Rte_Read_CC_TCP_Handler_PiUssInfo_PiUssInfo
#define Rte_Read_PiUssRawDataSet_PiUssRawDataSet            Rte_Read_CC_TCP_Handler_PiUssRawDataSet_PiUssRawDataSet
#define Rte_Read_PiUssStatusSet_PiUssStatusSet              Rte_Read_CC_TCP_Handler_PiUssStatusSet_PiUssStatusSet
#define Rte_Read_PiVehicleInfo_PiVehicleInfo                Rte_Read_CC_TCP_Handler_PiVehicleInfo_PiVehicleInfo
#define Rte_Read_PiVisionPerceptionControl_PiVisionPerceptionControl  Rte_Read_CC_TCP_Handler_PiVisionPerceptionControl_PiVisionPerceptionControl
#define Rte_Read_Tcp_ReceiveSignal_1601_Tcp_ReceiveSignal_1601        Rte_Read_CC_TCP_Handler_Tcp_ReceiveSignal_1601_Tcp_ReceiveSignal_1601
#define Rte_Read_Tcp_ReceiveSignal_1602_Tcp_ReceiveSignal_1602        Rte_Read_CC_TCP_Handler_Tcp_ReceiveSignal_1602_Tcp_ReceiveSignal_1602
#define Rte_Read_Tcp_ReceiveSignal_1603_Tcp_ReceiveSignal_1603        Rte_Read_CC_TCP_Handler_Tcp_ReceiveSignal_1603_Tcp_ReceiveSignal_1603
#define Rte_Read_Tcp_ReceiveSignal_1604_Tcp_ReceiveSignal_1604        Rte_Read_CC_TCP_Handler_Tcp_ReceiveSignal_1604_Tcp_ReceiveSignal_1604
#define Rte_Read_Tcp_ReceiveSignal_1605_Tcp_ReceiveSignal_1605        Rte_Read_CC_TCP_Handler_Tcp_ReceiveSignal_1605_Tcp_ReceiveSignal_1605
#define Rte_Read_Tcp_ReceiveSignal_1606_Tcp_ReceiveSignal_1606        Rte_Read_CC_TCP_Handler_Tcp_ReceiveSignal_1606_Tcp_ReceiveSignal_1606
#define Rte_Read_Tcp_ReceiveSignal_1607_Tcp_ReceiveSignal_1607        Rte_Read_CC_TCP_Handler_Tcp_ReceiveSignal_1607_Tcp_ReceiveSignal_1607
#define Rte_Read_Tcp_ReceiveSignal_1608_Tcp_ReceiveSignal_1608        Rte_Read_CC_TCP_Handler_Tcp_ReceiveSignal_1608_Tcp_ReceiveSignal_1608
/*******************************************************************************
*   Extended
*******************************************************************************/
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CC_TCP_Handler_PiApaDesiredTrajectoryGeneral_PiApaDesiredTrajectoryGeneral
(
    P2VAR(DesiredTrajectoryGeneral, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CC_TCP_Handler_PiAvmFusionParkingSlot_PiAvmFusionParkingSlot
(
    P2VAR(ParkingSlotSet, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CC_TCP_Handler_PiFusionFreespaceSet_PiFusionFreespaceSet
(
    P2VAR(FreespaceSet, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CC_TCP_Handler_PiFusionParkingSlotSet_PiFusionParkingSlotSet
(
    P2VAR(ParkingSlotSet, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CC_TCP_Handler_PiFusionStatus_PiFusionStatus
(
    P2VAR(WorkingStatus, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CC_TCP_Handler_PiGuideLine_PiGuideLine
(
    P2VAR(GuideLine, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CC_TCP_Handler_PiParkingSlotError_PiParkingSlotError
(
    P2VAR(ParkingSlotError, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CC_TCP_Handler_PiPlanningWorkingStatus_PiPlanningWorkingStatus
(
    P2VAR(WorkingStatus, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CC_TCP_Handler_PiUssFsdWorkingStatus_PiUssFsdWorkingStatus
(
    P2VAR(WorkingStatus, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CC_TCP_Handler_PiVisionCal_PiVisionCal
(
    P2VAR(VisionCal, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CC_TCP_Handler_PiVisionFailSafe_PiVisionFailSafe
(
    P2VAR(VisionFailSafe, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CC_TCP_Handler_PiVisionLaneSet_PiVisionLaneSet
(
    P2VAR(VisionLaneSet, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CC_TCP_Handler_PiVisionObjectSet_PiVisionObjectSet
(
    P2VAR(VisionObjectSet, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CC_TCP_Handler_PiVisionStatus_PiVisionStatus
(
    P2VAR(WorkingStatus, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CC_TCP_Handler_PiVisionTrafficSignSet_PiVisionTrafficSignSet
(
    P2VAR(VisionTrafficSignSet, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CC_TCP_Handler_PiVision_WorkingStus_PiVision_WorkingStus
(
    P2VAR(Vision_WorkingStus, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CC_TCP_Handler_Udp_SendSignal_1501_Udp_SendSignal_1501
(
    VAR(Udp_SendSignal_1501_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CC_TCP_Handler_Udp_SendSignal_1502_Udp_SendSignal_1502
(
    VAR(Udp_SendSignal_1502_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CC_TCP_Handler_Udp_SendSignal_1503_Udp_SendSignal_1503
(
    VAR(Udp_SendSignal_1503_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CC_TCP_Handler_Udp_SendSignal_1504_Udp_SendSignal_1504
(
    VAR(Udp_SendSignal_1504_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CC_TCP_Handler_Udp_SendSignal_1505_Udp_SendSignal_1505
(
    VAR(Udp_SendSignal_1505_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CC_TCP_Handler_Udp_SendSignal_1506_Udp_SendSignal_1506
(
    VAR(Udp_SendSignal_1506_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CC_TCP_Handler_Udp_SendSignal_1507_Udp_SendSignal_1507
(
    VAR(Udp_SendSignal_1507_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CC_TCP_Handler_PiAPAControlState_PiAPAControlState
(
    P2VAR(APAControlState, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CC_TCP_Handler_PiCarInfoH_PiCarInfoH
(
    P2VAR(CarInfoH, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CC_TCP_Handler_PiCarInfoL_PiCarInfoL
(
    P2VAR(CarInfoL, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CC_TCP_Handler_PiGlobalPoseBuffer_PiGlobalPoseBuffer
(
    P2VAR(GlobalPoseBuffer, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CC_TCP_Handler_PiManualParkingSlotSet_PiManualParkingSlotSet
(
    P2VAR(ParkingSlotSet, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CC_TCP_Handler_PiPerceptionCommand_PiPerceptionCommand
(
    P2VAR(PerceptionCommand, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CC_TCP_Handler_PiUssInfo_PiUssInfo
(
    P2VAR(UssInfo, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CC_TCP_Handler_PiUssRawDataSet_PiUssRawDataSet
(
    P2VAR(UssRawDataSet, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CC_TCP_Handler_PiUssStatusSet_PiUssStatusSet
(
    P2VAR(UssStatusSet, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CC_TCP_Handler_PiVehicleInfo_PiVehicleInfo
(
    P2VAR(VehicleInfo, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CC_TCP_Handler_PiVisionPerceptionControl_PiVisionPerceptionControl
(
    P2VAR(VisionPerceptionControl, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CC_TCP_Handler_Tcp_ReceiveSignal_1601_Tcp_ReceiveSignal_1601
(
    VAR(Tcp_ReceiveSignal_1601_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CC_TCP_Handler_Tcp_ReceiveSignal_1602_Tcp_ReceiveSignal_1602
(
    VAR(Tcp_ReceiveSignal_1602_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CC_TCP_Handler_Tcp_ReceiveSignal_1603_Tcp_ReceiveSignal_1603
(
    VAR(Tcp_ReceiveSignal_1603_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CC_TCP_Handler_Tcp_ReceiveSignal_1604_Tcp_ReceiveSignal_1604
(
    VAR(Tcp_ReceiveSignal_1604_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CC_TCP_Handler_Tcp_ReceiveSignal_1605_Tcp_ReceiveSignal_1605
(
    VAR(Tcp_ReceiveSignal_1605_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CC_TCP_Handler_Tcp_ReceiveSignal_1606_Tcp_ReceiveSignal_1606
(
    VAR(Tcp_ReceiveSignal_1606_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CC_TCP_Handler_Tcp_ReceiveSignal_1607_Tcp_ReceiveSignal_1607
(
    VAR(Tcp_ReceiveSignal_1607_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CC_TCP_Handler_Tcp_ReceiveSignal_1608_Tcp_ReceiveSignal_1608
(
    VAR(Tcp_ReceiveSignal_1608_IDT, AUTOMATIC) data
);

/*******************************************************************************
*   Runnable Extended
*******************************************************************************/

#define CC_TCP_Handler_START_SEC_CODE
#include "CC_TCP_Handler_MemMap.h"

extern FUNC(void, CC_TCP_Handler_CODE) CC_TCP_Handler_Init
(
    void
);
#define CC_TCP_Handler_STOP_SEC_CODE
#include "CC_TCP_Handler_MemMap.h"


#define CC_TCP_Handler_START_SEC_CODE
#include "CC_TCP_Handler_MemMap.h"

extern FUNC(void, CC_TCP_Handler_CODE) CC_TCP_Handler
(
    void
);
#define CC_TCP_Handler_STOP_SEC_CODE
#include "CC_TCP_Handler_MemMap.h"


# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif  /*RTE_CC_TCP_HANDLER_H*/


