/*  BEGIN_FILE_HDR
********************************************************************************
*   File Name       : WdgM_PBcfg.h
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
#ifndef WDGM_PBCFG_H
#define WDGM_PBCFG_H
/*******************************************************************************
*   Include
*******************************************************************************/
#include "WdgM_Types.h"
/*******************************************************************************
*   Vars
*******************************************************************************/
#define WDGM_START_SEC_VAR_NOINIT_8
#include "MemMap.h"
extern VAR(WdgM_LocalStatusType, WDGM_VAR_NOINIT) WdgM_LocalMonitoringStatus[];
extern VAR(uint8, WDGM_VAR_NOINIT) WdgM_ErrFlag[];
extern VAR(uint8, WDGM_VAR_NOINIT) WdgM_LocalFailedCnt[];
#define WDGM_STOP_SEC_VAR_NOINIT_8
#include "MemMap.h"
#define WDGM_START_SEC_VAR_NOINIT_16
#include "MemMap.h"
extern VAR(uint16, WDGM_VAR_NOINIT) WdgM_AliveCnt[];
extern VAR(uint16, WDGM_VAR_NOINIT) WdgM_AliveCycle[];
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
extern CONST(WdgM_SupervisedEntityType, WDGM_CONST)   WdgMSupervisedEntity[];
extern CONST(uint8, WDGM_CONST)  WdgMWatchdog[];
extern CONST(WdgM_CheckPointCfgType, WDGM_CONST)  WdgMCheckPoint[];
extern CONST(WdgM_ConfigType, WDGM_CONST)  WdgM_Config[];
extern CONST(WdgM_ModeIndFunPtrType, WDGM_CONST)  WdgM_GlobalStatusInd;
#define WDGM_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "MemMap.h"
/*******************************************************************************
*   Access macro
*******************************************************************************/

#endif /* WDGM_PBCFG_H */


