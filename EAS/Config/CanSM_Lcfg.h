/*  BEGIN_FILE_HDR
********************************************************************************
*   File Name       : CanSM_Lcfg.h
********************************************************************************
*   Project/Product : AUTOSAR BSW PROJECT
*   Title           : CanSM module configuration File
*   Author          : Hirain
********************************************************************************
*   Description     : CanSM module configuration File
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
#ifndef CANSM_LCFG_H
#define CANSM_LCFG_H

/*******************************************************************************
*   Includes
*******************************************************************************/

#include "CanSM_Types.h"
#define CANSM_START_SEC_VAR_NOINIT_8

#include "MemMap.h"
extern VAR(uint8, CANSM_VAR)  CanSM_TriggerInfo[CANSM_MAX_NETWORK_NUM];
#define CANSM_STOP_SEC_VAR_NOINIT_8

#include "MemMap.h"

#define CANSM_START_SEC_VAR_NOINIT_UNSPECIFIED

#include "MemMap.h"
extern VAR(CanSM_NeworkInfoType, CANSM_VAR)  CanSM_NetworkInfo[CANSM_MAX_NETWORK_NUM];
#define CANSM_STOP_SEC_VAR_NOINIT_UNSPECIFIED

#include "MemMap.h"
#define CANSM_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "MemMap.h"
extern CONST(CanSM_NetworkCfgType, CANSM_CONST)  CanSM_NetworkCfg[CANSM_MAX_NETWORK_NUM];
#define CANSM_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "MemMap.h"

/*******************************************************************************
*   Access 
*******************************************************************************/
#define CANSM_UESD_NETWORKCFG_INFO      CanSM_NetworkCfg

#define CANSM_START_SEC_CONFIG_CODE
#include "MemMap.h"
extern FUNC(void, CANSM_CODE) CanSM_EnterBorL1_Indication
(
    NetworkHandleType Channel
);

extern FUNC(void, CANSM_CODE) CanSM_EnterBorL2_Indication
(
    NetworkHandleType Channel
);

extern FUNC(void, CANSM_CODE) CanSM_BORSuccess_Indication
(
    NetworkHandleType Channel
);

#define CANSM_STOP_SEC_CONFIG_CODE
#include "MemMap.h"
#endif /* CANSM_LCFG_H */


