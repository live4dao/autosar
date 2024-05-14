/*  BEGIN_FILE_HDR
********************************************************************************
*   File Name       : Rte_Driving_Control.h
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
#ifndef RTE_DRIVING_CONTROL_H
#define RTE_DRIVING_CONTROL_H

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
#include "Rte_Driving_Control_Type.h"
/*******************************************************************************
*   define for a symbolic name of the RunnableEntity.
*******************************************************************************/
#define RTE_RUNNABLE_Driving_Control_BG_V                   Driving_Control_BG_V
#define RTE_RUNNABLE_Driving_Cotrol_Init_V                  Driving_Cotrol_Init_V
#define RTE_RUNNABLE_Task_Driving_Control_10ms              Task_Driving_Control_10ms

/*******************************************************************************
*   Instance Handle
*******************************************************************************/
#ifndef RTE_CORE
typedef CONSTP2CONST(Rte_CDS_Driving_Control, AUTOMATIC, RTE_CONST) Rte_Instance;
#endif

/*******************************************************************************
*   Macro definition.
*******************************************************************************/
#define Rte_Write_PiADAS_CAN_Output_ADAS_CAN_Output         Rte_Write_Driving_Control_PiADAS_CAN_Output_ADAS_CAN_Output
#define Rte_Write_PiDriv_ControlDiagStatus_PiDriv_ControlDiagStatus   Rte_Write_Driving_Control_PiDriv_ControlDiagStatus_PiDriv_ControlDiagStatus
#define Rte_Write_PiVisionPerceptionControl_PiVisionPerceptionControl Rte_Write_Driving_Control_PiVisionPerceptionControl_PiVisionPerceptionControl
#define Rte_Read_PiVision_WorkingStus_PiVision_WorkingStus  Rte_Read_Driving_Control_PiVision_WorkingStus_PiVision_WorkingStus
#define Rte_Read_PiFUSION_HEADER_ST_FUSION_HEADER_ST        Rte_Read_Driving_Control_PiFUSION_HEADER_ST_FUSION_HEADER_ST
#define Rte_Read_PiFUSION_OBJECT_ST_FUSION_OBJECT_ST        Rte_Read_Driving_Control_PiFUSION_OBJECT_ST_FUSION_OBJECT_ST
#define Rte_Read_PiFusion_Status_Fusion_Status              Rte_Read_Driving_Control_PiFusion_Status_Fusion_Status
#define Rte_Read_PiVisionCal_PiVisionCal                    Rte_Read_Driving_Control_PiVisionCal_PiVisionCal
#define Rte_Read_PiVisionTrafficSignSet_PiVisionTrafficSignSet        Rte_Read_Driving_Control_PiVisionTrafficSignSet_PiVisionTrafficSignSet
#define Rte_Read_PiVehicleInfo_PiVehicleInfo                Rte_Read_Driving_Control_PiVehicleInfo_PiVehicleInfo
#define Rte_Read_PiVisionFailSafe_PiVisionFailSafe          Rte_Read_Driving_Control_PiVisionFailSafe_PiVisionFailSafe
#define Rte_Read_PiVisionLaneSet_PiVisionLaneSet            Rte_Read_Driving_Control_PiVisionLaneSet_PiVisionLaneSet
#define Rte_Read_PiVisionObjectSet_PiVisionObjectSet        Rte_Read_Driving_Control_PiVisionObjectSet_PiVisionObjectSet
/*******************************************************************************
*   Extended
*******************************************************************************/
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Driving_Control_PiADAS_CAN_Output_ADAS_CAN_Output
(
    P2VAR(ADAS_CAN_Output, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Driving_Control_PiDriv_ControlDiagStatus_PiDriv_ControlDiagStatus
(
    VAR(uint64, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Driving_Control_PiVisionPerceptionControl_PiVisionPerceptionControl
(
    P2VAR(VisionPerceptionControl, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Driving_Control_PiVision_WorkingStus_PiVision_WorkingStus
(
    P2VAR(Vision_WorkingStus, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Driving_Control_PiFUSION_HEADER_ST_FUSION_HEADER_ST
(
    P2VAR(Fusion_Header_ST, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Driving_Control_PiFUSION_OBJECT_ST_FUSION_OBJECT_ST
(
    P2VAR(Fusion_Object_ST, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Driving_Control_PiFusion_Status_Fusion_Status
(
    P2VAR(Fusion_Status, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Driving_Control_PiVisionCal_PiVisionCal
(
    P2VAR(VisionCal, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Driving_Control_PiVisionTrafficSignSet_PiVisionTrafficSignSet
(
    P2VAR(VisionTrafficSignSet, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Driving_Control_PiVehicleInfo_PiVehicleInfo
(
    P2VAR(VehicleInfo, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Driving_Control_PiVisionFailSafe_PiVisionFailSafe
(
    P2VAR(VisionFailSafe, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Driving_Control_PiVisionLaneSet_PiVisionLaneSet
(
    P2VAR(VisionLaneSet, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Driving_Control_PiVisionObjectSet_PiVisionObjectSet
(
    P2VAR(VisionObjectSet, AUTOMATIC, RTE_APPL_DATA) data
);

/*******************************************************************************
*   Runnable Extended
*******************************************************************************/

#define Driving_Control_START_SEC_CODE
#include "Driving_Control_MemMap.h"

extern FUNC(void, Driving_Control_CODE) Driving_Cotrol_Init_V
(
    void
);
#define Driving_Control_STOP_SEC_CODE
#include "Driving_Control_MemMap.h"


#define Driving_Control_START_SEC_CODE
#include "Driving_Control_MemMap.h"

extern FUNC(void, Driving_Control_CODE) Driving_Control_BG_V
(
    void
);
#define Driving_Control_STOP_SEC_CODE
#include "Driving_Control_MemMap.h"


#define Driving_Control_START_SEC_CODE
#include "Driving_Control_MemMap.h"

extern FUNC(void, Driving_Control_CODE) Task_Driving_Control_10ms
(
    void
);
#define Driving_Control_STOP_SEC_CODE
#include "Driving_Control_MemMap.h"


# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif  /*RTE_DRIVING_CONTROL_H*/


