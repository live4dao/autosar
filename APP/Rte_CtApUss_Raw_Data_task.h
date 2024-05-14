/*  BEGIN_FILE_HDR
********************************************************************************
*   File Name       : Rte_CtApUss_Raw_Data_task.h
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
#ifndef RTE_CTAPUSS_RAW_DATA_TASK_H
#define RTE_CTAPUSS_RAW_DATA_TASK_H

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
#include "Rte_CtApUss_Raw_Data_task_Type.h"
#include "Dem.h"
/*******************************************************************************
*   define for a symbolic name of the RunnableEntity.
*******************************************************************************/
#define RTE_RUNNABLE_TSK_Uss_task_1ms                       TSK_Uss_task_1ms
#define RTE_RUNNABLE_TSK_Uss_task_1s                        TSK_Uss_task_1s
#define RTE_RUNNABLE_TSK_Uss_task_5ms                       TSK_Uss_task_5ms
#define RTE_RUNNABLE_Uss_Task_init                          Uss_Task_init

/*******************************************************************************
*   Instance Handle
*******************************************************************************/
#ifndef RTE_CORE
typedef CONSTP2CONST(Rte_CDS_CtApUss_Raw_Data_task, AUTOMATIC, RTE_CONST) Rte_Instance;
#endif

/*******************************************************************************
*   Macro definition.
*******************************************************************************/
#define Rte_Write_PiUssNvmData_CC_WriteData_PiUssNvmDataWrite         Rte_Write_CtApUss_Raw_Data_task_PiUssNvmData_CC_WriteData_PiUssNvmDataWrite
#define Rte_Write_PiUssRawDataSet_PiUssRawDataSet           Rte_Write_CtApUss_Raw_Data_task_PiUssRawDataSet_PiUssRawDataSet
#define Rte_Write_PiUssStatusSet_PiUssStatusSet             Rte_Write_CtApUss_Raw_Data_task_PiUssStatusSet_PiUssStatusSet
#define Rte_Write_PiUssTaskWorkingStatus_PiUssTaskWorkingStatus       Rte_Write_CtApUss_Raw_Data_task_PiUssTaskWorkingStatus_PiUssTaskWorkingStatus
#define Rte_Read_PiCarInfoH_PiCarInfoH                      Rte_Read_CtApUss_Raw_Data_task_PiCarInfoH_PiCarInfoH
#define Rte_Read_PiCarInfoL_PiCarInfoL                      Rte_Read_CtApUss_Raw_Data_task_PiCarInfoL_PiCarInfoL
#define Rte_Read_PiNvmValidFlg_PiNvmValidFlg                Rte_Read_CtApUss_Raw_Data_task_PiNvmValidFlg_PiNvmValidFlg
#define Rte_Read_PiUssNvmData_CC_ReadData_PiUssNvmDataRead  Rte_Read_CtApUss_Raw_Data_task_PiUssNvmData_CC_ReadData_PiUssNvmDataRead
#define Rte_Read_PiUssDataFeedback_P_PiUssDataFeedback      Rte_Read_CtApUss_Raw_Data_task_PiUssDataFeedback_P_PiUssDataFeedback
#define Rte_Read_PiPerceptionCommand_PiPerceptionCommand    Rte_Read_CtApUss_Raw_Data_task_PiPerceptionCommand_PiPerceptionCommand
#define Rte_Call_Event_Event_0x940009_SetEventStatus(EventStatus)     NULL_PTR
#define Rte_Call_Event_Event_0x940109_SetEventStatus(EventStatus)     NULL_PTR
#define Rte_Call_Event_Event_0x940709_SetEventStatus(EventStatus)     NULL_PTR
/*******************************************************************************
*   Extended
*******************************************************************************/
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtApUss_Raw_Data_task_PiUssNvmData_CC_WriteData_PiUssNvmDataWrite
(
    P2VAR(UssNvmData, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtApUss_Raw_Data_task_PiUssRawDataSet_PiUssRawDataSet
(
    P2VAR(UssRawDataSet, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtApUss_Raw_Data_task_PiUssStatusSet_PiUssStatusSet
(
    P2VAR(UssStatusSet, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtApUss_Raw_Data_task_PiUssTaskWorkingStatus_PiUssTaskWorkingStatus
(
    P2VAR(WorkingStatus, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtApUss_Raw_Data_task_PiCarInfoH_PiCarInfoH
(
    P2VAR(CarInfoH, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtApUss_Raw_Data_task_PiCarInfoL_PiCarInfoL
(
    P2VAR(CarInfoL, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtApUss_Raw_Data_task_PiNvmValidFlg_PiNvmValidFlg
(
    P2VAR(boolean, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtApUss_Raw_Data_task_PiUssNvmData_CC_ReadData_PiUssNvmDataRead
(
    P2VAR(UssNvmData, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtApUss_Raw_Data_task_PiUssDataFeedback_P_PiUssDataFeedback
(
    P2VAR(UssDataFeedBack, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtApUss_Raw_Data_task_PiPerceptionCommand_PiPerceptionCommand
(
    P2VAR(PerceptionCommand, AUTOMATIC, RTE_APPL_DATA) data
);

/*******************************************************************************
*   Runnable Extended
*******************************************************************************/

#define CtApUss_Raw_Data_task_START_SEC_CODE
#include "CtApUss_Raw_Data_task_MemMap.h"

extern FUNC(void, CtApUss_Raw_Data_task_CODE) Uss_Task_init
(
    void
);
#define CtApUss_Raw_Data_task_STOP_SEC_CODE
#include "CtApUss_Raw_Data_task_MemMap.h"


#define CtApUss_Raw_Data_task_START_SEC_CODE
#include "CtApUss_Raw_Data_task_MemMap.h"

extern FUNC(void, CtApUss_Raw_Data_task_CODE) TSK_Uss_task_1ms
(
    void
);
#define CtApUss_Raw_Data_task_STOP_SEC_CODE
#include "CtApUss_Raw_Data_task_MemMap.h"


#define CtApUss_Raw_Data_task_START_SEC_CODE
#include "CtApUss_Raw_Data_task_MemMap.h"

extern FUNC(void, CtApUss_Raw_Data_task_CODE) TSK_Uss_task_1s
(
    void
);
#define CtApUss_Raw_Data_task_STOP_SEC_CODE
#include "CtApUss_Raw_Data_task_MemMap.h"


#define CtApUss_Raw_Data_task_START_SEC_CODE
#include "CtApUss_Raw_Data_task_MemMap.h"

extern FUNC(void, CtApUss_Raw_Data_task_CODE) TSK_Uss_task_5ms
(
    void
);
#define CtApUss_Raw_Data_task_STOP_SEC_CODE
#include "CtApUss_Raw_Data_task_MemMap.h"


# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif  /*RTE_CTAPUSS_RAW_DATA_TASK_H*/


