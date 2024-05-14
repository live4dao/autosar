/*  BEGIN_FILE_HDR
********************************************************************************
*   File Name       : BswM_Lcfg.h
********************************************************************************
*   Project/Product : AUTOSAR BSW PROJECT
*   Title           : BswM module configuration File
*   Author          : Hirain
********************************************************************************
*   Description     : BswM module configuration File
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
#ifndef BSWM_LCFG_H
#define BSWM_LCFG_H

/*******************************************************************************
*   Includes
*******************************************************************************/

#include "BswM_Types.h"
#include "EcuM.h"
#include "CanSM_BswM.h"
#include "ComM_EcuMBswM.h"
#include "NvM.h"
#include "Dcm.h"
#include "EthSM.h"


/*******************************************************************************
*   Global Vars
*******************************************************************************/

#define BSWM_START_SEC_CONFIG_DATA_8
#include "MemMap.h"

extern CONST(BswMRuleType, BSWM_CONST) BswMPortMappingRulesStart[BSWM_MAX_PORT_NUM];
extern CONST(BswMRuleType, BSWM_CONST) BswMPortMappingRulesNum[BSWM_MAX_PORT_NUM];
extern CONST(BswMRuleType, BSWM_CONST) BswMPortMappingRules[BSWM_MAX_PORT_MAPPING_RULE_NUM];

#define BSWM_STOP_SEC_CONFIG_DATA_8
#include "MemMap.h"

#define BSWM_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "MemMap.h"

extern CONST(BswMActionList, BSWM_CONST) BswMAvailableActionLists[BSWM_MAX_ACTIONLIST_NUM];
extern CONST(BswM_RuleCfgType, BSWM_CONST) BswMAvailableRules[BSWM_MAX_RULE_NUM];

#define BSWM_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "MemMap.h"


#define BSWM_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"

extern VAR(EcuM_StateType, BSWM_VAR) BswM_EcuMRequestMode;

extern VAR(CanSM_BswMCurrentStateType, BSWM_VAR) BswM_CanSMMode[BSWM_CANSM_PORT_NUM];

extern VAR(ComM_ModeType, BSWM_VAR) BswM_ComMMode[BSWM_COMM_PORT_NUM];

extern VAR(NvM_RequestResultType, BSWM_VAR) BswM_NvMReadAllStatus;

extern VAR(NvM_RequestResultType, BSWM_VAR) BswM_NvMWriteAllStatus;


extern VAR(BswM_ModeType, BSWM_VAR) BswM_GeneralPortMode[BSWM_GENERAL_PORT_NUM];

extern VAR(BswM_TimerState, BSWM_VAR) BswM_TimerMode;
#define BSWM_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"

#define BSWM_START_SEC_INIT_8
#include "MemMap.h"


/*ECUC_BswM_00863*/
extern VAR(Dcm_CommunicationModeType, BSWM_VAR) BswM_DcmComMMode[BSWM_MAX_DCM_COMMUNICATION_REQUESTING_NETWORK];


#define BSWM_STOP_SEC_INIT_8
#include "MemMap.h"





#define BSWM_START_SEC_CODE
#include "MemMap.h"

extern FUNC(void, BSWM_CODE)  BswM_InitBlockIICallout(void);
extern FUNC(void, BSWM_CODE)  BswM_PostReadAllCallout(void);
extern FUNC(void, BSWM_CODE)  BswM_WriteNvMToSleepCallout(void);
extern FUNC(void, BSWM_CODE)  BswM_NvMWriteAllCallout(void);
extern FUNC(void, BSWM_CODE)  BswM_NvMReadAllCallout(void);

#define BSWM_STOP_SEC_CODE
#include "MemMap.h"


#endif /* BSWM_LCFG_H */



