/*  BEGIN_FILE_HDR
********************************************************************************
*   File Name       : Rte_Driving_Fusion.h
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
#ifndef RTE_DRIVING_FUSION_H
#define RTE_DRIVING_FUSION_H

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
#include "Rte_Driving_Fusion_Type.h"
/*******************************************************************************
*   define for a symbolic name of the RunnableEntity.
*******************************************************************************/
#define RTE_RUNNABLE_FUS_BG_V                               FUS_BG_V
#define RTE_RUNNABLE_Fus_Init_V                             Fus_Init_V
#define RTE_RUNNABLE_Task_Driving_Fus_10ms                  Task_Driving_Fus_10ms

/*******************************************************************************
*   Instance Handle
*******************************************************************************/
#ifndef RTE_CORE
typedef CONSTP2CONST(Rte_CDS_Driving_Fusion, AUTOMATIC, RTE_CONST) Rte_Instance;
#endif

/*******************************************************************************
*   Macro definition.
*******************************************************************************/
#define Rte_Write_PiFUSION_HEADER_ST_FUSION_HEADER_ST       Rte_Write_Driving_Fusion_PiFUSION_HEADER_ST_FUSION_HEADER_ST
#define Rte_Write_PiFUSION_OBJECT_ST_FUSION_OBJECT_ST       Rte_Write_Driving_Fusion_PiFUSION_OBJECT_ST_FUSION_OBJECT_ST
#define Rte_Read_PiFrontRadarInfo_PiFrontRadarInfo          Rte_Read_Driving_Fusion_PiFrontRadarInfo_PiFrontRadarInfo
#define Rte_Read_PiVehicleInfo_PiVehicleInfo                Rte_Read_Driving_Fusion_PiVehicleInfo_PiVehicleInfo
#define Rte_Read_PiVisionLaneSet_PiVisionLaneSet            Rte_Read_Driving_Fusion_PiVisionLaneSet_PiVisionLaneSet
#define Rte_Read_PiVisionObjectSet_PiVisionObjectSet        Rte_Read_Driving_Fusion_PiVisionObjectSet_PiVisionObjectSet
/*******************************************************************************
*   Extended
*******************************************************************************/
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Driving_Fusion_PiFUSION_HEADER_ST_FUSION_HEADER_ST
(
    P2VAR(Fusion_Header_ST, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Driving_Fusion_PiFUSION_OBJECT_ST_FUSION_OBJECT_ST
(
    P2VAR(Fusion_Object_ST, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Driving_Fusion_PiFrontRadarInfo_PiFrontRadarInfo
(
    P2VAR(FrontRadarInfo, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Driving_Fusion_PiVehicleInfo_PiVehicleInfo
(
    P2VAR(VehicleInfo, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Driving_Fusion_PiVisionLaneSet_PiVisionLaneSet
(
    P2VAR(VisionLaneSet, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Driving_Fusion_PiVisionObjectSet_PiVisionObjectSet
(
    P2VAR(VisionObjectSet, AUTOMATIC, RTE_APPL_DATA) data
);

/*******************************************************************************
*   Runnable Extended
*******************************************************************************/

#define Driving_Fusion_START_SEC_CODE
#include "Driving_Fusion_MemMap.h"

extern FUNC(void, Driving_Fusion_CODE) Fus_Init_V
(
    void
);
#define Driving_Fusion_STOP_SEC_CODE
#include "Driving_Fusion_MemMap.h"


#define Driving_Fusion_START_SEC_CODE
#include "Driving_Fusion_MemMap.h"

extern FUNC(void, Driving_Fusion_CODE) FUS_BG_V
(
    void
);
#define Driving_Fusion_STOP_SEC_CODE
#include "Driving_Fusion_MemMap.h"


#define Driving_Fusion_START_SEC_CODE
#include "Driving_Fusion_MemMap.h"

extern FUNC(void, Driving_Fusion_CODE) Task_Driving_Fus_10ms
(
    void
);
#define Driving_Fusion_STOP_SEC_CODE
#include "Driving_Fusion_MemMap.h"


# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif  /*RTE_DRIVING_FUSION_H*/


