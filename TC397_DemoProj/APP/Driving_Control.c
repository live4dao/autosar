/*  BEGIN_FILE_HDR
********************************************************************************
*   File Name       : Driving_Control.c
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
#include "Rte_Driving_Control.h"

/* Driving_ControlInput File User Code start*/

/* Driving_ControlInput File User Code end*/

/* Driving_Control.c Custom Code (#define variable etc.) User Code start*/

/* Driving_Control.c Custom Code (#define variable etc.) User Code end*/

/*******************************************************************************
*   Runnable Extended
*******************************************************************************/

#define Driving_Control_START_SEC_CODE
#include "Driving_Control_MemMap.h"

FUNC(void, Driving_Control_CODE) Driving_Cotrol_Init_V
(
    void
)
{
    /* Driving_Cotrol_Init_V_Start User Code start*/

    /* Driving_Cotrol_Init_V_Start User Code end*/
    /* Driving_Cotrol_Init_V Varaible Define User Code start*/

    /* Driving_Cotrol_Init_V Varaible Define User Code end*/




    /* Driving_Cotrol_Init_V_Feedback User Code start*/

    /* Driving_Cotrol_Init_V_Feedback User Code end*/

}
#define Driving_Control_STOP_SEC_CODE
#include "Driving_Control_MemMap.h"


#define Driving_Control_START_SEC_CODE
#include "Driving_Control_MemMap.h"

FUNC(void, Driving_Control_CODE) Driving_Control_BG_V
(
    void
)
{
    /* Driving_Control_BG_V_Start User Code start*/

    /* Driving_Control_BG_V_Start User Code end*/
    /* Driving_Control_BG_V Varaible Define User Code start*/

    /* Driving_Control_BG_V Varaible Define User Code end*/




    /* Driving_Control_BG_V_Feedback User Code start*/

    /* Driving_Control_BG_V_Feedback User Code end*/

}
#define Driving_Control_STOP_SEC_CODE
#include "Driving_Control_MemMap.h"


#define Driving_Control_START_SEC_CODE
#include "Driving_Control_MemMap.h"

FUNC(void, Driving_Control_CODE) Task_Driving_Control_10ms
(
    void
)
{
    /* Task_Driving_Control_10ms_Start User Code start*/

    /* Task_Driving_Control_10ms_Start User Code end*/
    ADAS_CAN_Output Write_PiADAS_CAN_Output_ADAS_CAN_Output;
    uint64 Write_PiDriv_ControlDiagStatus_PiDriv_ControlDiagStatus;
    VisionPerceptionControl Write_PiVisionPerceptionControl_PiVisionPerceptionControl;
    Vision_WorkingStus Read_PiVision_WorkingStus_PiVision_WorkingStus;
    Fusion_Header_ST Read_PiFUSION_HEADER_ST_FUSION_HEADER_ST;
    Fusion_Object_ST Read_PiFUSION_OBJECT_ST_FUSION_OBJECT_ST;
    Fusion_Status Read_PiFusion_Status_Fusion_Status;
    VisionCal Read_PiVisionCal_PiVisionCal;
    VisionTrafficSignSet Read_PiVisionTrafficSignSet_PiVisionTrafficSignSet;
    VehicleInfo Read_PiVehicleInfo_PiVehicleInfo;
    VisionFailSafe Read_PiVisionFailSafe_PiVisionFailSafe;
    VisionLaneSet Read_PiVisionLaneSet_PiVisionLaneSet;
    VisionObjectSet Read_PiVisionObjectSet_PiVisionObjectSet;
    /* Task_Driving_Control_10ms Varaible Define User Code start*/

    /* Task_Driving_Control_10ms Varaible Define User Code end*/




    Rte_Write_PiADAS_CAN_Output_ADAS_CAN_Output(&Write_PiADAS_CAN_Output_ADAS_CAN_Output);
    /* Rte_Write_PiADAS_CAN_Output_ADAS_CAN_Output User Code start*/

    /* Rte_Write_PiADAS_CAN_Output_ADAS_CAN_Output User Code end*/
    Rte_Write_PiDriv_ControlDiagStatus_PiDriv_ControlDiagStatus(Write_PiDriv_ControlDiagStatus_PiDriv_ControlDiagStatus);
    /* Rte_Write_PiDriv_ControlDiagStatus_PiDriv_ControlDiagStatus User Code start*/

    /* Rte_Write_PiDriv_ControlDiagStatus_PiDriv_ControlDiagStatus User Code end*/
    Rte_Write_PiVisionPerceptionControl_PiVisionPerceptionControl(&Write_PiVisionPerceptionControl_PiVisionPerceptionControl);
    /* Rte_Write_PiVisionPerceptionControl_PiVisionPerceptionControl User Code start*/

    /* Rte_Write_PiVisionPerceptionControl_PiVisionPerceptionControl User Code end*/
    Rte_Read_PiVision_WorkingStus_PiVision_WorkingStus(&Read_PiVision_WorkingStus_PiVision_WorkingStus);
    /* Rte_Read_PiVision_WorkingStus_PiVision_WorkingStus User Code start*/

    /* Rte_Read_PiVision_WorkingStus_PiVision_WorkingStus User Code end*/
    Rte_Read_PiFUSION_HEADER_ST_FUSION_HEADER_ST(&Read_PiFUSION_HEADER_ST_FUSION_HEADER_ST);
    /* Rte_Read_PiFUSION_HEADER_ST_FUSION_HEADER_ST User Code start*/

    /* Rte_Read_PiFUSION_HEADER_ST_FUSION_HEADER_ST User Code end*/
    Rte_Read_PiFUSION_OBJECT_ST_FUSION_OBJECT_ST(&Read_PiFUSION_OBJECT_ST_FUSION_OBJECT_ST);
    /* Rte_Read_PiFUSION_OBJECT_ST_FUSION_OBJECT_ST User Code start*/

    /* Rte_Read_PiFUSION_OBJECT_ST_FUSION_OBJECT_ST User Code end*/
    Rte_Read_PiFusion_Status_Fusion_Status(&Read_PiFusion_Status_Fusion_Status);
    /* Rte_Read_PiFusion_Status_Fusion_Status User Code start*/

    /* Rte_Read_PiFusion_Status_Fusion_Status User Code end*/
    Rte_Read_PiVisionCal_PiVisionCal(&Read_PiVisionCal_PiVisionCal);
    /* Rte_Read_PiVisionCal_PiVisionCal User Code start*/

    /* Rte_Read_PiVisionCal_PiVisionCal User Code end*/
    Rte_Read_PiVisionTrafficSignSet_PiVisionTrafficSignSet(&Read_PiVisionTrafficSignSet_PiVisionTrafficSignSet);
    /* Rte_Read_PiVisionTrafficSignSet_PiVisionTrafficSignSet User Code start*/

    /* Rte_Read_PiVisionTrafficSignSet_PiVisionTrafficSignSet User Code end*/
    Rte_Read_PiVehicleInfo_PiVehicleInfo(&Read_PiVehicleInfo_PiVehicleInfo);
    /* Rte_Read_PiVehicleInfo_PiVehicleInfo User Code start*/

    /* Rte_Read_PiVehicleInfo_PiVehicleInfo User Code end*/
    Rte_Read_PiVisionFailSafe_PiVisionFailSafe(&Read_PiVisionFailSafe_PiVisionFailSafe);
    /* Rte_Read_PiVisionFailSafe_PiVisionFailSafe User Code start*/

    /* Rte_Read_PiVisionFailSafe_PiVisionFailSafe User Code end*/
    Rte_Read_PiVisionLaneSet_PiVisionLaneSet(&Read_PiVisionLaneSet_PiVisionLaneSet);
    /* Rte_Read_PiVisionLaneSet_PiVisionLaneSet User Code start*/

    /* Rte_Read_PiVisionLaneSet_PiVisionLaneSet User Code end*/
    Rte_Read_PiVisionObjectSet_PiVisionObjectSet(&Read_PiVisionObjectSet_PiVisionObjectSet);
    /* Rte_Read_PiVisionObjectSet_PiVisionObjectSet User Code start*/

    /* Rte_Read_PiVisionObjectSet_PiVisionObjectSet User Code end*/
    /* Task_Driving_Control_10ms_Feedback User Code start*/

    /* Task_Driving_Control_10ms_Feedback User Code end*/

}
#define Driving_Control_STOP_SEC_CODE
#include "Driving_Control_MemMap.h"




