/*  BEGIN_FILE_HDR
********************************************************************************
*   File Name       : CtApAPA_Control.c
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
#include "Rte_CtApAPA_Control.h"

/* CtApAPA_ControlInput File User Code start*/

/* CtApAPA_ControlInput File User Code end*/

/* CtApAPA_Control.c Custom Code (#define variable etc.) User Code start*/

/* CtApAPA_Control.c Custom Code (#define variable etc.) User Code end*/

/*******************************************************************************
*   Runnable Extended
*******************************************************************************/

#define CtApAPA_Control_START_SEC_CODE
#include "CtApAPA_Control_MemMap.h"

FUNC(void, CtApAPA_Control_CODE) CtApAPA_Control_init
(
    void
)
{
    /* CtApAPA_Control_init_Start User Code start*/

    /* CtApAPA_Control_init_Start User Code end*/
    /* CtApAPA_Control_init Varaible Define User Code start*/

    /* CtApAPA_Control_init Varaible Define User Code end*/




    /* CtApAPA_Control_init_Feedback User Code start*/

    /* CtApAPA_Control_init_Feedback User Code end*/

}
#define CtApAPA_Control_STOP_SEC_CODE
#include "CtApAPA_Control_MemMap.h"


#define CtApAPA_Control_START_SEC_CODE
#include "CtApAPA_Control_MemMap.h"

FUNC(void, CtApAPA_Control_CODE) TSK_APA_Control_20ms
(
    void
)
{
    /* TSK_APA_Control_20ms_Start User Code start*/

    /* TSK_APA_Control_20ms_Start User Code end*/
    APAControlState Write_PiApaControlState_PiAPAControlState;
    CarControlCommandH Write_PiCarControlCommandH_PiCarControlCommandH;
    CarControlCommandL Write_PiCarControlCommandL_PiCarControlCommandL;
    GlobalPoseBuffer Write_PiGlobalPoseBuffer_PiGlobalPoseBuffer;
    WorkingStatus Write_PiLocalizationWorkingStatus_PiLocalizationWorkingStatus;
    CarInfoH Read_PiCarInfoH_PiCarInfoH;
    CarInfoL Read_PiCarInfoL_PiCarInfoL;
    DesiredTrajectoryGeneral Read_PiApaDesiredTrajectoryGeneral_PiApaDesiredTrajectoryGeneral;
    Command Read_PiLocalizationCommand_PiLocalizationCommand;
    ParkingSlotError Read_PiParkingSlotError_PiParkingSlotError;
    PerceptionCommand Read_PiPerceptionCommand_PiPerceptionCommand;
    Command Read_PiControlCommand_PiControlCommand;
    FreespaceSet Read_PiFusionFreespaceSet_PiFusionFreespaceSet;
    ParkingSlotSet Read_PiFusionParkingSlotSet_PiFusionParkingSlotSet;
    IMUInfo Read_PiImuInfo_PiIMUInfo;
    Command Read_PiPlanningCommand_PiPlanningCommand;
    UssInfo Read_PiUssInfo_PiUssInfo;
    /* TSK_APA_Control_20ms Varaible Define User Code start*/

    /* TSK_APA_Control_20ms Varaible Define User Code end*/




    Rte_Write_PiApaControlState_PiAPAControlState(&Write_PiApaControlState_PiAPAControlState);
    /* Rte_Write_PiApaControlState_PiAPAControlState User Code start*/

    /* Rte_Write_PiApaControlState_PiAPAControlState User Code end*/
    Rte_Write_PiCarControlCommandH_PiCarControlCommandH(&Write_PiCarControlCommandH_PiCarControlCommandH);
    /* Rte_Write_PiCarControlCommandH_PiCarControlCommandH User Code start*/

    /* Rte_Write_PiCarControlCommandH_PiCarControlCommandH User Code end*/
    Rte_Write_PiCarControlCommandL_PiCarControlCommandL(&Write_PiCarControlCommandL_PiCarControlCommandL);
    /* Rte_Write_PiCarControlCommandL_PiCarControlCommandL User Code start*/

    /* Rte_Write_PiCarControlCommandL_PiCarControlCommandL User Code end*/
    Rte_Write_PiGlobalPoseBuffer_PiGlobalPoseBuffer(&Write_PiGlobalPoseBuffer_PiGlobalPoseBuffer);
    /* Rte_Write_PiGlobalPoseBuffer_PiGlobalPoseBuffer User Code start*/

    /* Rte_Write_PiGlobalPoseBuffer_PiGlobalPoseBuffer User Code end*/
    Rte_Write_PiLocalizationWorkingStatus_PiLocalizationWorkingStatus(&Write_PiLocalizationWorkingStatus_PiLocalizationWorkingStatus);
    /* Rte_Write_PiLocalizationWorkingStatus_PiLocalizationWorkingStatus User Code start*/

    /* Rte_Write_PiLocalizationWorkingStatus_PiLocalizationWorkingStatus User Code end*/
    Rte_Read_PiCarInfoH_PiCarInfoH(&Read_PiCarInfoH_PiCarInfoH);
    /* Rte_Read_PiCarInfoH_PiCarInfoH User Code start*/

    /* Rte_Read_PiCarInfoH_PiCarInfoH User Code end*/
    Rte_Read_PiCarInfoL_PiCarInfoL(&Read_PiCarInfoL_PiCarInfoL);
    /* Rte_Read_PiCarInfoL_PiCarInfoL User Code start*/

    /* Rte_Read_PiCarInfoL_PiCarInfoL User Code end*/
    Rte_Read_PiApaDesiredTrajectoryGeneral_PiApaDesiredTrajectoryGeneral(&Read_PiApaDesiredTrajectoryGeneral_PiApaDesiredTrajectoryGeneral);
    /* Rte_Read_PiApaDesiredTrajectoryGeneral_PiApaDesiredTrajectoryGeneral User Code start*/

    /* Rte_Read_PiApaDesiredTrajectoryGeneral_PiApaDesiredTrajectoryGeneral User Code end*/
    Rte_Read_PiLocalizationCommand_PiLocalizationCommand(&Read_PiLocalizationCommand_PiLocalizationCommand);
    /* Rte_Read_PiLocalizationCommand_PiLocalizationCommand User Code start*/

    /* Rte_Read_PiLocalizationCommand_PiLocalizationCommand User Code end*/
    Rte_Read_PiParkingSlotError_PiParkingSlotError(&Read_PiParkingSlotError_PiParkingSlotError);
    /* Rte_Read_PiParkingSlotError_PiParkingSlotError User Code start*/

    /* Rte_Read_PiParkingSlotError_PiParkingSlotError User Code end*/
    Rte_Read_PiPerceptionCommand_PiPerceptionCommand(&Read_PiPerceptionCommand_PiPerceptionCommand);
    /* Rte_Read_PiPerceptionCommand_PiPerceptionCommand User Code start*/

    /* Rte_Read_PiPerceptionCommand_PiPerceptionCommand User Code end*/
    Rte_Read_PiControlCommand_PiControlCommand(&Read_PiControlCommand_PiControlCommand);
    /* Rte_Read_PiControlCommand_PiControlCommand User Code start*/

    /* Rte_Read_PiControlCommand_PiControlCommand User Code end*/
    Rte_Read_PiFusionFreespaceSet_PiFusionFreespaceSet(&Read_PiFusionFreespaceSet_PiFusionFreespaceSet);
    /* Rte_Read_PiFusionFreespaceSet_PiFusionFreespaceSet User Code start*/

    /* Rte_Read_PiFusionFreespaceSet_PiFusionFreespaceSet User Code end*/
    Rte_Read_PiFusionParkingSlotSet_PiFusionParkingSlotSet(&Read_PiFusionParkingSlotSet_PiFusionParkingSlotSet);
    /* Rte_Read_PiFusionParkingSlotSet_PiFusionParkingSlotSet User Code start*/

    /* Rte_Read_PiFusionParkingSlotSet_PiFusionParkingSlotSet User Code end*/
    Rte_Read_PiImuInfo_PiIMUInfo(&Read_PiImuInfo_PiIMUInfo);
    /* Rte_Read_PiImuInfo_PiIMUInfo User Code start*/

    /* Rte_Read_PiImuInfo_PiIMUInfo User Code end*/
    Rte_Read_PiPlanningCommand_PiPlanningCommand(&Read_PiPlanningCommand_PiPlanningCommand);
    /* Rte_Read_PiPlanningCommand_PiPlanningCommand User Code start*/

    /* Rte_Read_PiPlanningCommand_PiPlanningCommand User Code end*/
    Rte_Read_PiUssInfo_PiUssInfo(&Read_PiUssInfo_PiUssInfo);
    /* Rte_Read_PiUssInfo_PiUssInfo User Code start*/

    /* Rte_Read_PiUssInfo_PiUssInfo User Code end*/
    /* TSK_APA_Control_20ms_Feedback User Code start*/

    /* TSK_APA_Control_20ms_Feedback User Code end*/

}
#define CtApAPA_Control_STOP_SEC_CODE
#include "CtApAPA_Control_MemMap.h"




