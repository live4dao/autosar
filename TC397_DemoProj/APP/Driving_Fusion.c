/*  BEGIN_FILE_HDR
********************************************************************************
*   File Name       : Driving_Fusion.c
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
#include "Rte_Driving_Fusion.h"

/* Driving_FusionInput File User Code start*/

/* Driving_FusionInput File User Code end*/

/* Driving_Fusion.c Custom Code (#define variable etc.) User Code start*/

/* Driving_Fusion.c Custom Code (#define variable etc.) User Code end*/

/*******************************************************************************
*   Runnable Extended
*******************************************************************************/

#define Driving_Fusion_START_SEC_CODE
#include "Driving_Fusion_MemMap.h"

FUNC(void, Driving_Fusion_CODE) Fus_Init_V
(
    void
)
{
    /* Fus_Init_V_Start User Code start*/

    /* Fus_Init_V_Start User Code end*/
    /* Fus_Init_V Varaible Define User Code start*/

    /* Fus_Init_V Varaible Define User Code end*/




    /* Fus_Init_V_Feedback User Code start*/

    /* Fus_Init_V_Feedback User Code end*/

}
#define Driving_Fusion_STOP_SEC_CODE
#include "Driving_Fusion_MemMap.h"


#define Driving_Fusion_START_SEC_CODE
#include "Driving_Fusion_MemMap.h"

FUNC(void, Driving_Fusion_CODE) FUS_BG_V
(
    void
)
{
    /* FUS_BG_V_Start User Code start*/

    /* FUS_BG_V_Start User Code end*/
    /* FUS_BG_V Varaible Define User Code start*/

    /* FUS_BG_V Varaible Define User Code end*/




    /* FUS_BG_V_Feedback User Code start*/

    /* FUS_BG_V_Feedback User Code end*/

}
#define Driving_Fusion_STOP_SEC_CODE
#include "Driving_Fusion_MemMap.h"


#define Driving_Fusion_START_SEC_CODE
#include "Driving_Fusion_MemMap.h"

FUNC(void, Driving_Fusion_CODE) Task_Driving_Fus_10ms
(
    void
)
{
    /* Task_Driving_Fus_10ms_Start User Code start*/

    /* Task_Driving_Fus_10ms_Start User Code end*/
    Fusion_Header_ST Write_PiFUSION_HEADER_ST_FUSION_HEADER_ST;
    Fusion_Object_ST Write_PiFUSION_OBJECT_ST_FUSION_OBJECT_ST;
    FrontRadarInfo Read_PiFrontRadarInfo_PiFrontRadarInfo;
    VehicleInfo Read_PiVehicleInfo_PiVehicleInfo;
    VisionLaneSet Read_PiVisionLaneSet_PiVisionLaneSet;
    VisionObjectSet Read_PiVisionObjectSet_PiVisionObjectSet;
    /* Task_Driving_Fus_10ms Varaible Define User Code start*/

    /* Task_Driving_Fus_10ms Varaible Define User Code end*/




    Rte_Write_PiFUSION_HEADER_ST_FUSION_HEADER_ST(&Write_PiFUSION_HEADER_ST_FUSION_HEADER_ST);
    /* Rte_Write_PiFUSION_HEADER_ST_FUSION_HEADER_ST User Code start*/

    /* Rte_Write_PiFUSION_HEADER_ST_FUSION_HEADER_ST User Code end*/
    Rte_Write_PiFUSION_OBJECT_ST_FUSION_OBJECT_ST(&Write_PiFUSION_OBJECT_ST_FUSION_OBJECT_ST);
    /* Rte_Write_PiFUSION_OBJECT_ST_FUSION_OBJECT_ST User Code start*/

    /* Rte_Write_PiFUSION_OBJECT_ST_FUSION_OBJECT_ST User Code end*/
    Rte_Read_PiFrontRadarInfo_PiFrontRadarInfo(&Read_PiFrontRadarInfo_PiFrontRadarInfo);
    /* Rte_Read_PiFrontRadarInfo_PiFrontRadarInfo User Code start*/

    /* Rte_Read_PiFrontRadarInfo_PiFrontRadarInfo User Code end*/
    Rte_Read_PiVehicleInfo_PiVehicleInfo(&Read_PiVehicleInfo_PiVehicleInfo);
    /* Rte_Read_PiVehicleInfo_PiVehicleInfo User Code start*/

    /* Rte_Read_PiVehicleInfo_PiVehicleInfo User Code end*/
    Rte_Read_PiVisionLaneSet_PiVisionLaneSet(&Read_PiVisionLaneSet_PiVisionLaneSet);
    /* Rte_Read_PiVisionLaneSet_PiVisionLaneSet User Code start*/

    /* Rte_Read_PiVisionLaneSet_PiVisionLaneSet User Code end*/
    Rte_Read_PiVisionObjectSet_PiVisionObjectSet(&Read_PiVisionObjectSet_PiVisionObjectSet);
    /* Rte_Read_PiVisionObjectSet_PiVisionObjectSet User Code start*/

    /* Rte_Read_PiVisionObjectSet_PiVisionObjectSet User Code end*/
    /* Task_Driving_Fus_10ms_Feedback User Code start*/

    /* Task_Driving_Fus_10ms_Feedback User Code end*/

}
#define Driving_Fusion_STOP_SEC_CODE
#include "Driving_Fusion_MemMap.h"




