/*  BEGIN_FILE_HDR
********************************************************************************
*   File Name       : CtApUss_Pdc.c
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
#include "Rte_CtApUss_Pdc.h"

/* CtApUss_PdcInput File User Code start*/

/* CtApUss_PdcInput File User Code end*/

/* CtApUss_Pdc.c Custom Code (#define variable etc.) User Code start*/

/* CtApUss_Pdc.c Custom Code (#define variable etc.) User Code end*/

/*******************************************************************************
*   Runnable Extended
*******************************************************************************/

#define CtApUss_Pdc_START_SEC_CODE
#include "CtApUss_Pdc_MemMap.h"

FUNC(void, CtApUss_Pdc_CODE) USS_Pdc_init
(
    void
)
{
    /* USS_Pdc_init_Start User Code start*/

    /* USS_Pdc_init_Start User Code end*/
    /* USS_Pdc_init Varaible Define User Code start*/

    /* USS_Pdc_init Varaible Define User Code end*/




    /* USS_Pdc_init_Feedback User Code start*/

    /* USS_Pdc_init_Feedback User Code end*/

}
#define CtApUss_Pdc_STOP_SEC_CODE
#include "CtApUss_Pdc_MemMap.h"


#define CtApUss_Pdc_START_SEC_CODE
#include "CtApUss_Pdc_MemMap.h"

FUNC(void, CtApUss_Pdc_CODE) TSK_Uss_Pdc_40ms
(
    void
)
{
    /* TSK_Uss_Pdc_40ms_Start User Code start*/

    /* TSK_Uss_Pdc_40ms_Start User Code end*/
    UssPdcInfo Write_PiUssPdcInfo_PiUssPdcInfo;
    WorkingStatus Write_PiUssPdcWorkingStatus_PiUssPdcWorkingStatus;
    CarInfoH Read_PiCarInfoH_PiCarInfoH;
    CarInfoL Read_PiCarInfoL_PiCarInfoL;
    GlobalPoseBuffer Read_PiGlobalPoseBuffer_PiGlobalPoseBuffer;
    UssStatusSet Read_PiUssStatusSet_PiUssStatusSet;
    Command Read_PiPdcCommand_PiPdcCommand;
    UssInfo Read_PiUssInfo_PiUssInfo;
    /* TSK_Uss_Pdc_40ms Varaible Define User Code start*/

    /* TSK_Uss_Pdc_40ms Varaible Define User Code end*/




    Rte_Write_PiUssPdcInfo_PiUssPdcInfo(&Write_PiUssPdcInfo_PiUssPdcInfo);
    /* Rte_Write_PiUssPdcInfo_PiUssPdcInfo User Code start*/

    /* Rte_Write_PiUssPdcInfo_PiUssPdcInfo User Code end*/
    Rte_Write_PiUssPdcWorkingStatus_PiUssPdcWorkingStatus(&Write_PiUssPdcWorkingStatus_PiUssPdcWorkingStatus);
    /* Rte_Write_PiUssPdcWorkingStatus_PiUssPdcWorkingStatus User Code start*/

    /* Rte_Write_PiUssPdcWorkingStatus_PiUssPdcWorkingStatus User Code end*/
    Rte_Read_PiCarInfoH_PiCarInfoH(&Read_PiCarInfoH_PiCarInfoH);
    /* Rte_Read_PiCarInfoH_PiCarInfoH User Code start*/

    /* Rte_Read_PiCarInfoH_PiCarInfoH User Code end*/
    Rte_Read_PiCarInfoL_PiCarInfoL(&Read_PiCarInfoL_PiCarInfoL);
    /* Rte_Read_PiCarInfoL_PiCarInfoL User Code start*/

    /* Rte_Read_PiCarInfoL_PiCarInfoL User Code end*/
    Rte_Read_PiGlobalPoseBuffer_PiGlobalPoseBuffer(&Read_PiGlobalPoseBuffer_PiGlobalPoseBuffer);
    /* Rte_Read_PiGlobalPoseBuffer_PiGlobalPoseBuffer User Code start*/

    /* Rte_Read_PiGlobalPoseBuffer_PiGlobalPoseBuffer User Code end*/
    Rte_Read_PiUssStatusSet_PiUssStatusSet(&Read_PiUssStatusSet_PiUssStatusSet);
    /* Rte_Read_PiUssStatusSet_PiUssStatusSet User Code start*/

    /* Rte_Read_PiUssStatusSet_PiUssStatusSet User Code end*/
    Rte_Read_PiPdcCommand_PiPdcCommand(&Read_PiPdcCommand_PiPdcCommand);
    /* Rte_Read_PiPdcCommand_PiPdcCommand User Code start*/

    /* Rte_Read_PiPdcCommand_PiPdcCommand User Code end*/
    Rte_Read_PiUssInfo_PiUssInfo(&Read_PiUssInfo_PiUssInfo);
    /* Rte_Read_PiUssInfo_PiUssInfo User Code start*/

    /* Rte_Read_PiUssInfo_PiUssInfo User Code end*/
    /* TSK_Uss_Pdc_40ms_Feedback User Code start*/

    /* TSK_Uss_Pdc_40ms_Feedback User Code end*/

}
#define CtApUss_Pdc_STOP_SEC_CODE
#include "CtApUss_Pdc_MemMap.h"




