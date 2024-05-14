/*  BEGIN_FILE_HDR
********************************************************************************
*   File Name       : FiM_Lcfg.h
********************************************************************************
*   Project/Product : AUTOSAR BSW PROJECT
*   Title           : FiM module configuration File
*   Author          : Hirain
********************************************************************************
*   Description     : FiM module configuration File
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

#ifndef FIM_LCFG_H
#define FIM_LCFG_H

#include "FiM_Types.h"
#define FIM_START_SEC_CONFIG_DATA_8
#include "MemMap.h"
extern VAR(boolean, FIM_VAR) FiM_Permission[FIM_FUNCTION_NUM_CFG];
extern CONST(boolean, FIM_VAR) FiM_AvailabilityCfg[FIM_FUNCTION_NUM_CFG];
extern VAR(boolean, FIM_VAR) FiM_Availability[FIM_FUNCTION_NUM_CFG];
#define FIM_STOP_SEC_CONFIG_DATA_8
#include "MemMap.h"

#define FIM_START_SEC_CONFIG_DATA_16
#include "MemMap.h"





#define FIM_STOP_SEC_CONFIG_DATA_16
#include "MemMap.h"

#define FIM_START_SEC_CONFIG_DATA_32
#include "MemMap.h"
extern VAR(uint32,FIM_VAR) FiM_EventAsBitArray1[1];
#define FIM_STOP_SEC_CONFIG_DATA_32
#include "MemMap.h"

#define FIM_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "MemMap.h"
extern CONST(FiM_ConfigType, FIM_CONST) FiM_Config;
extern CONST(FiM_EventCfgType,FIM_CONST) FiM_EventCfg[FIM_EVENT_NUM_CFG];
#define FIM_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "MemMap.h"

#endif/*FIM_LCFG_H*/
