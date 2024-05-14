/*  BEGIN_FILE_HDR
********************************************************************************
*   File Name       : Rte_CtApAPA_Control.h
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
#ifndef RTE_CTAPAPA_CONTROL_H
#define RTE_CTAPAPA_CONTROL_H

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
#include "Rte_CtApAPA_Control_Type.h"
/*******************************************************************************
*   define for a symbolic name of the RunnableEntity.
*******************************************************************************/
#define RTE_RUNNABLE_CtApAPA_Control_init                   CtApAPA_Control_init
#define RTE_RUNNABLE_TSK_APA_Control_20ms                   TSK_APA_Control_20ms

/*******************************************************************************
*   Instance Handle
*******************************************************************************/
#ifndef RTE_CORE
typedef CONSTP2CONST(Rte_CDS_CtApAPA_Control, AUTOMATIC, RTE_CONST) Rte_Instance;
#endif

/*******************************************************************************
*   Macro definition.
*******************************************************************************/
#define Rte_Write_PiApaControlState_PiAPAControlState       Rte_Write_CtApAPA_Control_PiApaControlState_PiAPAControlState
#define Rte_Write_PiCarControlCommandH_PiCarControlCommandH Rte_Write_CtApAPA_Control_PiCarControlCommandH_PiCarControlCommandH
#define Rte_Write_PiCarControlCommandL_PiCarControlCommandL Rte_Write_CtApAPA_Control_PiCarControlCommandL_PiCarControlCommandL
#define Rte_Write_PiGlobalPoseBuffer_PiGlobalPoseBuffer     Rte_Write_CtApAPA_Control_PiGlobalPoseBuffer_PiGlobalPoseBuffer
#define Rte_Write_PiLocalizationWorkingStatus_PiLocalizationWorkingStatus       Rte_Write_CtApAPA_Control_PiLocalizationWorkingStatus_PiLocalizationWorkingStatus
#define Rte_Read_PiCarInfoH_PiCarInfoH                      Rte_Read_CtApAPA_Control_PiCarInfoH_PiCarInfoH
#define Rte_Read_PiCarInfoL_PiCarInfoL                      Rte_Read_CtApAPA_Control_PiCarInfoL_PiCarInfoL
#define Rte_Read_PiApaDesiredTrajectoryGeneral_PiApaDesiredTrajectoryGeneral    Rte_Read_CtApAPA_Control_PiApaDesiredTrajectoryGeneral_PiApaDesiredTrajectoryGeneral
#define Rte_Read_PiLocalizationCommand_PiLocalizationCommand          Rte_Read_CtApAPA_Control_PiLocalizationCommand_PiLocalizationCommand
#define Rte_Read_PiParkingSlotError_PiParkingSlotError      Rte_Read_CtApAPA_Control_PiParkingSlotError_PiParkingSlotError
#define Rte_Read_PiPerceptionCommand_PiPerceptionCommand    Rte_Read_CtApAPA_Control_PiPerceptionCommand_PiPerceptionCommand
#define Rte_Read_PiControlCommand_PiControlCommand          Rte_Read_CtApAPA_Control_PiControlCommand_PiControlCommand
#define Rte_Read_PiFusionFreespaceSet_PiFusionFreespaceSet  Rte_Read_CtApAPA_Control_PiFusionFreespaceSet_PiFusionFreespaceSet
#define Rte_Read_PiFusionParkingSlotSet_PiFusionParkingSlotSet        Rte_Read_CtApAPA_Control_PiFusionParkingSlotSet_PiFusionParkingSlotSet
#define Rte_Read_PiImuInfo_PiIMUInfo                        Rte_Read_CtApAPA_Control_PiImuInfo_PiIMUInfo
#define Rte_Read_PiPlanningCommand_PiPlanningCommand        Rte_Read_CtApAPA_Control_PiPlanningCommand_PiPlanningCommand
#define Rte_Read_PiUssInfo_PiUssInfo                        Rte_Read_CtApAPA_Control_PiUssInfo_PiUssInfo
/*******************************************************************************
*   Extended
*******************************************************************************/
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtApAPA_Control_PiApaControlState_PiAPAControlState
(
    P2VAR(APAControlState, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtApAPA_Control_PiCarControlCommandH_PiCarControlCommandH
(
    P2VAR(CarControlCommandH, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtApAPA_Control_PiCarControlCommandL_PiCarControlCommandL
(
    P2VAR(CarControlCommandL, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtApAPA_Control_PiGlobalPoseBuffer_PiGlobalPoseBuffer
(
    P2VAR(GlobalPoseBuffer, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtApAPA_Control_PiLocalizationWorkingStatus_PiLocalizationWorkingStatus
(
    P2VAR(WorkingStatus, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtApAPA_Control_PiCarInfoH_PiCarInfoH
(
    P2VAR(CarInfoH, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtApAPA_Control_PiCarInfoL_PiCarInfoL
(
    P2VAR(CarInfoL, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtApAPA_Control_PiApaDesiredTrajectoryGeneral_PiApaDesiredTrajectoryGeneral
(
    P2VAR(DesiredTrajectoryGeneral, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtApAPA_Control_PiLocalizationCommand_PiLocalizationCommand
(
    P2VAR(Command, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtApAPA_Control_PiParkingSlotError_PiParkingSlotError
(
    P2VAR(ParkingSlotError, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtApAPA_Control_PiPerceptionCommand_PiPerceptionCommand
(
    P2VAR(PerceptionCommand, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtApAPA_Control_PiControlCommand_PiControlCommand
(
    P2VAR(Command, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtApAPA_Control_PiFusionFreespaceSet_PiFusionFreespaceSet
(
    P2VAR(FreespaceSet, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtApAPA_Control_PiFusionParkingSlotSet_PiFusionParkingSlotSet
(
    P2VAR(ParkingSlotSet, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtApAPA_Control_PiImuInfo_PiIMUInfo
(
    P2VAR(IMUInfo, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtApAPA_Control_PiPlanningCommand_PiPlanningCommand
(
    P2VAR(Command, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtApAPA_Control_PiUssInfo_PiUssInfo
(
    P2VAR(UssInfo, AUTOMATIC, RTE_APPL_DATA) data
);

/*******************************************************************************
*   Runnable Extended
*******************************************************************************/

#define CtApAPA_Control_START_SEC_CODE
#include "CtApAPA_Control_MemMap.h"

extern FUNC(void, CtApAPA_Control_CODE) CtApAPA_Control_init
(
    void
);
#define CtApAPA_Control_STOP_SEC_CODE
#include "CtApAPA_Control_MemMap.h"


#define CtApAPA_Control_START_SEC_CODE
#include "CtApAPA_Control_MemMap.h"

extern FUNC(void, CtApAPA_Control_CODE) TSK_APA_Control_20ms
(
    void
);
#define CtApAPA_Control_STOP_SEC_CODE
#include "CtApAPA_Control_MemMap.h"


# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif  /*RTE_CTAPAPA_CONTROL_H*/


