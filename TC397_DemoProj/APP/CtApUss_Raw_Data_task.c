/*  BEGIN_FILE_HDR
********************************************************************************
*   File Name       : CtApUss_Raw_Data_task.c
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
#include "Rte_CtApUss_Raw_Data_task.h"

/* CtApUss_Raw_Data_taskInput File User Code start*/

/* CtApUss_Raw_Data_taskInput File User Code end*/

/* CtApUss_Raw_Data_task.c Custom Code (#define variable etc.) User Code start*/

/* CtApUss_Raw_Data_task.c Custom Code (#define variable etc.) User Code end*/

/*******************************************************************************
*   Runnable Extended
*******************************************************************************/

#define CtApUss_Raw_Data_task_START_SEC_CODE
#include "CtApUss_Raw_Data_task_MemMap.h"

FUNC(void, CtApUss_Raw_Data_task_CODE) Uss_Task_init
(
    void
)
{
    /* Uss_Task_init_Start User Code start*/

    /* Uss_Task_init_Start User Code end*/
    /* Uss_Task_init Varaible Define User Code start*/

    /* Uss_Task_init Varaible Define User Code end*/




    /* Uss_Task_init_Feedback User Code start*/

    /* Uss_Task_init_Feedback User Code end*/

}
#define CtApUss_Raw_Data_task_STOP_SEC_CODE
#include "CtApUss_Raw_Data_task_MemMap.h"


#define CtApUss_Raw_Data_task_START_SEC_CODE
#include "CtApUss_Raw_Data_task_MemMap.h"

FUNC(void, CtApUss_Raw_Data_task_CODE) TSK_Uss_task_1ms
(
    void
)
{
    /* TSK_Uss_task_1ms_Start User Code start*/

    /* TSK_Uss_task_1ms_Start User Code end*/
    /* TSK_Uss_task_1ms Varaible Define User Code start*/

    /* TSK_Uss_task_1ms Varaible Define User Code end*/




    /* TSK_Uss_task_1ms_Feedback User Code start*/

    /* TSK_Uss_task_1ms_Feedback User Code end*/

}
#define CtApUss_Raw_Data_task_STOP_SEC_CODE
#include "CtApUss_Raw_Data_task_MemMap.h"


#define CtApUss_Raw_Data_task_START_SEC_CODE
#include "CtApUss_Raw_Data_task_MemMap.h"

FUNC(void, CtApUss_Raw_Data_task_CODE) TSK_Uss_task_1s
(
    void
)
{
    /* TSK_Uss_task_1s_Start User Code start*/

    /* TSK_Uss_task_1s_Start User Code end*/
    /* TSK_Uss_task_1s Varaible Define User Code start*/

    /* TSK_Uss_task_1s Varaible Define User Code end*/




    /* TSK_Uss_task_1s_Feedback User Code start*/

    /* TSK_Uss_task_1s_Feedback User Code end*/

}
#define CtApUss_Raw_Data_task_STOP_SEC_CODE
#include "CtApUss_Raw_Data_task_MemMap.h"


#define CtApUss_Raw_Data_task_START_SEC_CODE
#include "CtApUss_Raw_Data_task_MemMap.h"

FUNC(void, CtApUss_Raw_Data_task_CODE) TSK_Uss_task_5ms
(
    void
)
{
    /* TSK_Uss_task_5ms_Start User Code start*/

    /* TSK_Uss_task_5ms_Start User Code end*/
    UssNvmData Write_PiUssNvmData_CC_WriteData_PiUssNvmDataWrite;
    UssRawDataSet Write_PiUssRawDataSet_PiUssRawDataSet;
    UssStatusSet Write_PiUssStatusSet_PiUssStatusSet;
    WorkingStatus Write_PiUssTaskWorkingStatus_PiUssTaskWorkingStatus;
    CarInfoH Read_PiCarInfoH_PiCarInfoH;
    CarInfoL Read_PiCarInfoL_PiCarInfoL;
    boolean Read_PiNvmValidFlg_PiNvmValidFlg;
    UssNvmData Read_PiUssNvmData_CC_ReadData_PiUssNvmDataRead;
    UssDataFeedBack Read_PiUssDataFeedback_P_PiUssDataFeedback;
    PerceptionCommand Read_PiPerceptionCommand_PiPerceptionCommand;
    Dem_EventStatusType Call_Event_Event_0x940009_SetEventStatus_EventStatus;
    Dem_EventStatusType Call_Event_Event_0x940109_SetEventStatus_EventStatus;
    Dem_EventStatusType Call_Event_Event_0x940709_SetEventStatus_EventStatus;
    /* TSK_Uss_task_5ms Varaible Define User Code start*/

    /* TSK_Uss_task_5ms Varaible Define User Code end*/




    Rte_Write_PiUssNvmData_CC_WriteData_PiUssNvmDataWrite(&Write_PiUssNvmData_CC_WriteData_PiUssNvmDataWrite);
    /* Rte_Write_PiUssNvmData_CC_WriteData_PiUssNvmDataWrite User Code start*/

    /* Rte_Write_PiUssNvmData_CC_WriteData_PiUssNvmDataWrite User Code end*/
    Rte_Write_PiUssRawDataSet_PiUssRawDataSet(&Write_PiUssRawDataSet_PiUssRawDataSet);
    /* Rte_Write_PiUssRawDataSet_PiUssRawDataSet User Code start*/

    /* Rte_Write_PiUssRawDataSet_PiUssRawDataSet User Code end*/
    Rte_Write_PiUssStatusSet_PiUssStatusSet(&Write_PiUssStatusSet_PiUssStatusSet);
    /* Rte_Write_PiUssStatusSet_PiUssStatusSet User Code start*/

    /* Rte_Write_PiUssStatusSet_PiUssStatusSet User Code end*/
    Rte_Write_PiUssTaskWorkingStatus_PiUssTaskWorkingStatus(&Write_PiUssTaskWorkingStatus_PiUssTaskWorkingStatus);
    /* Rte_Write_PiUssTaskWorkingStatus_PiUssTaskWorkingStatus User Code start*/

    /* Rte_Write_PiUssTaskWorkingStatus_PiUssTaskWorkingStatus User Code end*/
    Rte_Read_PiCarInfoH_PiCarInfoH(&Read_PiCarInfoH_PiCarInfoH);
    /* Rte_Read_PiCarInfoH_PiCarInfoH User Code start*/

    /* Rte_Read_PiCarInfoH_PiCarInfoH User Code end*/
    Rte_Read_PiCarInfoL_PiCarInfoL(&Read_PiCarInfoL_PiCarInfoL);
    /* Rte_Read_PiCarInfoL_PiCarInfoL User Code start*/

    /* Rte_Read_PiCarInfoL_PiCarInfoL User Code end*/
    Rte_Read_PiNvmValidFlg_PiNvmValidFlg(&Read_PiNvmValidFlg_PiNvmValidFlg);
    /* Rte_Read_PiNvmValidFlg_PiNvmValidFlg User Code start*/

    /* Rte_Read_PiNvmValidFlg_PiNvmValidFlg User Code end*/
    Rte_Read_PiUssNvmData_CC_ReadData_PiUssNvmDataRead(&Read_PiUssNvmData_CC_ReadData_PiUssNvmDataRead);
    /* Rte_Read_PiUssNvmData_CC_ReadData_PiUssNvmDataRead User Code start*/

    /* Rte_Read_PiUssNvmData_CC_ReadData_PiUssNvmDataRead User Code end*/
    Rte_Read_PiUssDataFeedback_P_PiUssDataFeedback(&Read_PiUssDataFeedback_P_PiUssDataFeedback);
    /* Rte_Read_PiUssDataFeedback_P_PiUssDataFeedback User Code start*/

    /* Rte_Read_PiUssDataFeedback_P_PiUssDataFeedback User Code end*/
    Rte_Read_PiPerceptionCommand_PiPerceptionCommand(&Read_PiPerceptionCommand_PiPerceptionCommand);
    /* Rte_Read_PiPerceptionCommand_PiPerceptionCommand User Code start*/

    /* Rte_Read_PiPerceptionCommand_PiPerceptionCommand User Code end*/
    Rte_Call_Event_Event_0x940009_SetEventStatus(Call_Event_Event_0x940009_SetEventStatus_EventStatus);
    /* Rte_Call_Event_Event_0x940009_SetEventStatus User Code start*/

    /* Rte_Call_Event_Event_0x940009_SetEventStatus User Code end*/
    Rte_Call_Event_Event_0x940109_SetEventStatus(Call_Event_Event_0x940109_SetEventStatus_EventStatus);
    /* Rte_Call_Event_Event_0x940109_SetEventStatus User Code start*/

    /* Rte_Call_Event_Event_0x940109_SetEventStatus User Code end*/
    Rte_Call_Event_Event_0x940709_SetEventStatus(Call_Event_Event_0x940709_SetEventStatus_EventStatus);
    /* Rte_Call_Event_Event_0x940709_SetEventStatus User Code start*/

    /* Rte_Call_Event_Event_0x940709_SetEventStatus User Code end*/
    /* TSK_Uss_task_5ms_Feedback User Code start*/

    /* TSK_Uss_task_5ms_Feedback User Code end*/

}
#define CtApUss_Raw_Data_task_STOP_SEC_CODE
#include "CtApUss_Raw_Data_task_MemMap.h"




