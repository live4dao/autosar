/*  BEGIN_FILE_HDR
********************************************************************************
*   File Name       : NvM_Lcfg.h
********************************************************************************
*   Project/Product : AUTOSAR BSW PROJECT
*   Title           : NvM module configuration File
*   Author          : Hirain
********************************************************************************
*   Description     : NvM module configuration File
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
#ifndef NVM_LCFG_H
#define NVM_LCFG_H
/*******************************************************************************
*   Includes
*******************************************************************************/
#include "NvM_Types.h"
#include "MemIf.h"

/*******************************************************************************
*   Global Vars
*******************************************************************************/
#define NVM_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h"
extern VAR(NvM_RamBlock_Type, NVM_VAR_NOINIT)  NvM_AdmBlock[];
extern VAR(NvM_QueBuf_Type, NVM_VAR_NOINIT) NvM_QueBuf[];
#define NVM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h"

#define NVM_START_SEC_VAR_NOINIT_8
#include "MemMap.h"
#define NVM_STOP_SEC_VAR_NOINIT_8
#include "MemMap.h"

/*******************************************************************************
*   Config parameters
*******************************************************************************/
#define NVM_START_SEC_CONFIG_DATA_8
#include "MemMap.h"
extern CONST(uint8, NVM_CONST) NvM_CompiledConfigId[];
#define NVM_STOP_SEC_CONFIG_DATA_8
#include "MemMap.h"

#define NVM_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "MemMap.h"

extern CONST(NvM_BlockConfigType, NVM_CONST) NvM_Config[];
extern CONST(NvM_SingleCallBackFun, NVM_CONST) NvM_SingleCallBackFunPtr[];
extern CONST(NvM_InitBlockCallBackFun, NVM_CONST) NvM_InitBlockCallBackFunPtr[];
extern CONST(NvM_MultiCallBackFun, NVM_CONST) NvM_MultiCallBackFunPtr;
#define NVM_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "MemMap.h"
#define NVM_START_SEC_CODE
#include "MemMap.h"

/*******************************************************************************
*   Callout declare
*******************************************************************************/
extern FUNC(uint8, NVM_CALLOUT_CODE) NvM_Crc8CalculateCallout
(
    P2CONST(uint8, AUTOMATIC, NVM_APPL_DATA) Crc_DataPtr,
    uint32 Crc_Length,
    uint8 Crc_StartValue8,
    boolean Crc_IsFirstCall
);
#define NVM_STOP_SEC_CODE
#include "MemMap.h"

/*******************************************************************************
*   Access
*******************************************************************************/

#endif /* #ifndef NVM_LCFG_H */

