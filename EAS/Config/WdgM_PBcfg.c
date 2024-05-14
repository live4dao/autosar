/*  BEGIN_FILE_HDR
********************************************************************************
*   File Name       : WdgM_PBcfg.c
********************************************************************************
*   Project/Product : AUTOSAR BSW PROJECT
*   Title           : WdgM module configuration File
*   Author          : Hirain
********************************************************************************
*   Description     : WdgM module configuration File
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
*   V1.0.0_3.5.5_AZ240046       27/03/2024    Eas           N/A          N/A
*
********************************************************************************
* END_FILE_HDR*/
/*******************************************************************************
*   Include
*******************************************************************************/
#include "WdgM.h"
#include "Rte_WdgM.h"
/*******************************************************************************
*   Vars
*******************************************************************************/
#define WDGM_START_SEC_VAR_NOINIT_8
#include "MemMap.h"
VAR(WdgM_LocalStatusType, WDGM_VAR_NOINIT) WdgM_LocalMonitoringStatus[1];
VAR(uint8, WDGM_VAR_NOINIT) WdgM_ErrFlag[1];
VAR(uint8, WDGM_VAR_NOINIT) WdgM_LocalFailedCnt[1];
#define WDGM_STOP_SEC_VAR_NOINIT_8
#include "MemMap.h"
#define WDGM_START_SEC_VAR_NOINIT_16
#include "MemMap.h"
VAR(uint16, WDGM_VAR_NOINIT) WdgM_AliveCnt[2];
VAR(uint16, WDGM_VAR_NOINIT) WdgM_AliveCycle[2];
#define WDGM_STOP_SEC_VAR_NOINIT_16
#include "MemMap.h"
#define WDGM_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h"
#define WDGM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h"
/*******************************************************************************
*   Config parameter
*******************************************************************************/
#define WDGM_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "MemMap.h"
/* alive */
STATIC CONST(WdgM_AliveSupervisionType, WDGM_CONST)  WdgMAliveSupervision_WdgMConfigSet_WdgMMode0[2] =
{
    {
        (uint16)102, /* expexted + max */
        (uint16)2, /* expexted - min */
        (uint16)250,
        WDGM_CP_WdgMSupervisedEntity_SE0_CP0_Bsw_5ms
    },
    {
        (uint16)102, /* expexted + max */
        (uint16)2, /* expexted - min */
        (uint16)500,
        WDGM_CP_WdgMSupervisedEntity_SE0_CP1_App_10ms
    },
};
/* deadline */
/* flow */
/* cp */
CONST(WdgM_CheckPointCfgType, WDGM_CONST)  WdgMCheckPoint[2] =
{
    /* seid, troffset, trnum, flowptr, flowcpType, flowindex */
    {(WdgM_SupervisedEntityIdType)0, (uint16)0, (uint16)0, NULL_PTR, WDGM_CP_NO_FLOW, WDGM_INVALID_FLOW_INDEX},
    {(WdgM_SupervisedEntityIdType)0, (uint16)0, (uint16)0, NULL_PTR, WDGM_CP_NO_FLOW, WDGM_INVALID_FLOW_INDEX},
};
STATIC CONST(WdgM_CheckPointInModeCfgType, WDGM_CONST)  WdgMCheckPoint_WdgMConfigSet_WdgMMode0[2] =
{
    /* troffset, trnum, flowptr,flowCpType,flowindex,aliveIndex,deadnum, deadptr, deadcpType*/
    {(uint16)0, (uint16)0, NULL_PTR, WDGM_CP_NO_FLOW, (uint16)0, (uint16)0, (uint16)0, NULL_PTR, WDGM_CP_NO_DEADLINE},
    {(uint16)0, (uint16)0, NULL_PTR, WDGM_CP_NO_FLOW, (uint16)0, (uint16)1, (uint16)0, NULL_PTR, WDGM_CP_NO_DEADLINE},
};
/* se */
CONST(WdgM_SupervisedEntityType, WDGM_CONST)  WdgMSupervisedEntity[1] =
{
    /*WdgMEcucPartitionRef,OsApp,counter,callout */
    {&Rte_Switch_mode_WdgMSupervisedEntity_SE0_WdgM_Mode},
};
/* dog */
CONST(uint8, WDGM_CONST)  WdgMWatchdog[1] = {WdgIf_Device_Internal, };
STATIC CONST(WdgM_TriggerType, WDGM_CONST)  WdgMTrigger_WdgMConfigSet_WdgMMode0[1] =
{
    /* device, triggerValue, dogMode*/
    {WdgIf_Device_Internal, (uint16)10, WDGIF_FAST_MODE},
};
/* modes */
STATIC CONST(WdgM_LocalStatusParamsType, WDGM_CONST)  WdgMLocalStatusParams_WdgMConfigSet_WdgMMode0[1] =
{
    {(uint8)0, WDGM_SE_WdgMSupervisedEntity_SE0},
};
STATIC CONST(WdgM_ModeCfgType, WDGM_CONST)  WdgMMode_WdgMConfigSet[1] =
{
    {
        (uint16)0,/*WdgMExpiredSupervisionCycleTol*/
        WdgMCheckPoint_WdgMConfigSet_WdgMMode0,
        WdgMAliveSupervision_WdgMConfigSet_WdgMMode0,
        NULL_PTR,
        WdgMTrigger_WdgMConfigSet_WdgMMode0,
        WdgMLocalStatusParams_WdgMConfigSet_WdgMMode0,
        (uint16)2/* num of alive*/,
        (uint16)0/* num of deadline*/,
        (uint8)1/* num of dogtrigger*/,
        (WdgM_SupervisedEntityIdType)1/* num of seStatus*/
    },
};
/* CfgSet */
CONST(WdgM_ConfigType, WDGM_CONST)  WdgM_Config[1] =
{
    {
        WDGM_MODE_WdgMConfigSet_WdgMMode0, /*InitMode*/
        (uint8)1 /*num of mode*/,
        WdgMMode_WdgMConfigSet,
    },
};
CONST(WdgM_ModeIndFunPtrType, WDGM_CONST)  WdgM_GlobalStatusInd = &Rte_Switch_globalmode_WdgM_Mode;
#define WDGM_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "MemMap.h"
