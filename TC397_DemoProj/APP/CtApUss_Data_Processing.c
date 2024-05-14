/*  BEGIN_FILE_HDR
********************************************************************************
*   File Name       : CtApUss_Data_Processing.c
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
#include "Rte_CtApUss_Data_Processing.h"

/* CtApUss_Data_ProcessingInput File User Code start*/

/* CtApUss_Data_ProcessingInput File User Code end*/

/* CtApUss_Data_Processing.c Custom Code (#define variable etc.) User Code start*/

/* CtApUss_Data_Processing.c Custom Code (#define variable etc.) User Code end*/

/*******************************************************************************
*   Runnable Extended
*******************************************************************************/

#define CtApUss_Data_Processing_START_SEC_CODE
#include "CtApUss_Data_Processing_MemMap.h"

FUNC(void, CtApUss_Data_Processing_CODE) Uss_Data_Processing_init
(
    void
)
{
    /* Uss_Data_Processing_init_Start User Code start*/

    /* Uss_Data_Processing_init_Start User Code end*/
    /* Uss_Data_Processing_init Varaible Define User Code start*/

    /* Uss_Data_Processing_init Varaible Define User Code end*/




    /* Uss_Data_Processing_init_Feedback User Code start*/

    /* Uss_Data_Processing_init_Feedback User Code end*/

}
#define CtApUss_Data_Processing_STOP_SEC_CODE
#include "CtApUss_Data_Processing_MemMap.h"


#define CtApUss_Data_Processing_START_SEC_CODE
#include "CtApUss_Data_Processing_MemMap.h"

FUNC(void, CtApUss_Data_Processing_CODE) TSK_Uss_Data_Processing_40ms
(
    void
)
{
    /* TSK_Uss_Data_Processing_40ms_Start User Code start*/

    /* TSK_Uss_Data_Processing_40ms_Start User Code end*/
    UssDataFeedBack Write_PiUssDataFeedback_P_PiUssDataFeedback;
    UssInfo Write_PiUssInfo_PiUssInfo;
    WorkingStatus Write_PiUssDataProWorkingStatus_P_PiUssDataProWorkingStatus;
    GlobalPoseBuffer Read_PiGlobalPoseBuffer_PiGlobalPoseBuffer;
    UssStatusSet Read_PiUssStatusSet_PiUssStatusSet;
    CarInfoH Read_PiCarInfoH_PiCarInfoH;
    CarInfoL Read_PiCarInfoL_PiCarInfoL;
    PerceptionCommand Read_PiPerceptionCommand_PiPerceptionCommand;
    UssRawDataSet Read_PiUssRawDataSet_PiUssRawDataSet;
    /* TSK_Uss_Data_Processing_40ms Varaible Define User Code start*/

    /* TSK_Uss_Data_Processing_40ms Varaible Define User Code end*/




    Rte_Write_PiUssDataFeedback_P_PiUssDataFeedback(&Write_PiUssDataFeedback_P_PiUssDataFeedback);
    /* Rte_Write_PiUssDataFeedback_P_PiUssDataFeedback User Code start*/

    /* Rte_Write_PiUssDataFeedback_P_PiUssDataFeedback User Code end*/
    Rte_Write_PiUssInfo_PiUssInfo(&Write_PiUssInfo_PiUssInfo);
    /* Rte_Write_PiUssInfo_PiUssInfo User Code start*/

    /* Rte_Write_PiUssInfo_PiUssInfo User Code end*/
    Rte_Write_PiUssDataProWorkingStatus_P_PiUssDataProWorkingStatus(&Write_PiUssDataProWorkingStatus_P_PiUssDataProWorkingStatus);
    /* Rte_Write_PiUssDataProWorkingStatus_P_PiUssDataProWorkingStatus User Code start*/

    /* Rte_Write_PiUssDataProWorkingStatus_P_PiUssDataProWorkingStatus User Code end*/
    Rte_Read_PiGlobalPoseBuffer_PiGlobalPoseBuffer(&Read_PiGlobalPoseBuffer_PiGlobalPoseBuffer);
    /* Rte_Read_PiGlobalPoseBuffer_PiGlobalPoseBuffer User Code start*/

    /* Rte_Read_PiGlobalPoseBuffer_PiGlobalPoseBuffer User Code end*/
    Rte_Read_PiUssStatusSet_PiUssStatusSet(&Read_PiUssStatusSet_PiUssStatusSet);
    /* Rte_Read_PiUssStatusSet_PiUssStatusSet User Code start*/

    /* Rte_Read_PiUssStatusSet_PiUssStatusSet User Code end*/
    Rte_Read_PiCarInfoH_PiCarInfoH(&Read_PiCarInfoH_PiCarInfoH);
    /* Rte_Read_PiCarInfoH_PiCarInfoH User Code start*/

    /* Rte_Read_PiCarInfoH_PiCarInfoH User Code end*/
    Rte_Read_PiCarInfoL_PiCarInfoL(&Read_PiCarInfoL_PiCarInfoL);
    /* Rte_Read_PiCarInfoL_PiCarInfoL User Code start*/

    /* Rte_Read_PiCarInfoL_PiCarInfoL User Code end*/
    Rte_Read_PiPerceptionCommand_PiPerceptionCommand(&Read_PiPerceptionCommand_PiPerceptionCommand);
    /* Rte_Read_PiPerceptionCommand_PiPerceptionCommand User Code start*/

    /* Rte_Read_PiPerceptionCommand_PiPerceptionCommand User Code end*/
    Rte_Read_PiUssRawDataSet_PiUssRawDataSet(&Read_PiUssRawDataSet_PiUssRawDataSet);
    /* Rte_Read_PiUssRawDataSet_PiUssRawDataSet User Code start*/

    /* Rte_Read_PiUssRawDataSet_PiUssRawDataSet User Code end*/
    /* TSK_Uss_Data_Processing_40ms_Feedback User Code start*/

    /* TSK_Uss_Data_Processing_40ms_Feedback User Code end*/

}
#define CtApUss_Data_Processing_STOP_SEC_CODE
#include "CtApUss_Data_Processing_MemMap.h"




