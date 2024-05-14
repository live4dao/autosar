/*  BEGIN_FILE_HDR
********************************************************************************
*   File Name       : BswM_Cfg.c
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
*   V1.0.2_3.5.5_AZ240046       09/05/2024    Eas           N/A          N/A
*
********************************************************************************
* END_FILE_HDR*/


/*******************************************************************************
*   Includes
*******************************************************************************/
#include "BswM_Lcfg.h"
#include "Rte_BswM.h"


#include "Nm.h"
#include "Com.h"
#include "ComM.h"
#include "CanSM.h"
#include "Os.h"
#include "Dcm.h"
#include "CanSM_BswM.h"

/*******************************************************************************
*   Macro
*******************************************************************************/
/*RuleExpressionIndex*/
#define BSWM_RULE_BswM_RuleInitBlockII                      (0)
#define BSWM_RULE_BswM_RuleWkupToReadNvM                    (1)
#define BSWM_RULE_BswM_RuleReadNvMToRun                     (2)
#define BSWM_RULE_BswM_RuleRunToPostRun                     (3)
#define BSWM_RULE_BswM_RulePostRunToRun                     (4)
#define BSWM_RULE_BswM_RulePostRunToPrep                    (5)
#define BSWM_RULE_BswM_RuleRunToPrep                        (6)
#define BSWM_RULE_BswM_RulePrepToRun                        (7)
#define BSWM_RULE_BswM_RulePrepToWriteNvM                   (8)
#define BSWM_RULE_BswM_RuleWriteNvMToSleep                  (9)
#define BSWM_RULE_BswM_RuleWriteNvMToRun                    (10)
#define BSWM_RULE_BswM_RuleComM0IpduGroupON                 (11)
#define BSWM_RULE_BswM_RuleComM1IpduGroupON                 (12)
#define BSWM_RULE_BswM_RuleDcmReqComRxTx                    (13)
#define BSWM_RULE_BswM_RuleDcmReqComRxNoTx                  (14)
#define BSWM_RULE_BswM_RuleDcmReqComTxNoRx                  (15)
#define BSWM_RULE_BswM_RuleDcmReqComNoRxTx                  (16)
#define BSWM_RULE_BswM_RuleDcmReqNmTx                       (17)
#define BSWM_RULE_BswM_RuleDcmReqNmNoTx                     (18)
/*BswMActionListIndex*/
#define BSWM_ACTIONLIST_BswM_ALInitBlockII                  (0)
#define BSWM_ACTIONLIST_BswM_ALWkupToReadNvM                (1)
#define BSWM_ACTIONLIST_BswM_ALReadNvMToRun                 (2)
#define BSWM_ACTIONLIST_BswM_ALRunToPostRun                 (3)
#define BSWM_ACTIONLIST_BswM_ALPostRunToRun                 (4)
#define BSWM_ACTIONLIST_BswM_ALPrepToRun                    (5)
#define BSWM_ACTIONLIST_BswM_ALPostRunToPrep                (6)
#define BSWM_ACTIONLIST_BswM_ALRunToPrep                    (7)
#define BSWM_ACTIONLIST_BswM_ALPrepToWriteNvM               (8)
#define BSWM_ACTIONLIST_BswM_ALWriteNvMToSleep              (9)
#define BSWM_ACTIONLIST_BswM_ALComM0IpduGroupON             (10)
#define BSWM_ACTIONLIST_BswM_ALComM1IpduGroupON             (11)
#define BSWM_ACTIONLIST_BswM_ALDcmReqComRxTx                (12)
#define BSWM_ACTIONLIST_BswM_ALDcmReqComRxNoTx              (13)
#define BSWM_ACTIONLIST_BswM_ALDcmReqComTxNoRx              (14)
#define BSWM_ACTIONLIST_BswM_ALDcmReqComNoRxTx              (15)
#define BSWM_ACTIONLIST_BswM_ALDcmReqNmTx                   (16)
#define BSWM_ACTIONLIST_BswM_ALDcmReqNmNoTx                 (17)

/*******************************************************************************
*   Global Vars
*******************************************************************************/

#define BSWM_START_SEC_CONFIG_DATA_8
#include "MemMap.h"

/*ECUC_BswM_00813*/
CONST(uint8, BSWM_CONST) BswMMainFunctionPeriod = 5;

#define BSWM_STOP_SEC_CONFIG_DATA_8
#include "MemMap.h"


#define BSWM_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"

/*ECUC_BswM_01043*/
VAR(EcuM_StateType, BSWM_VAR) BswM_EcuMRequestMode = ECUM_STATE_SHUTDOWN;

/*ECUC_BswM_00857*/
VAR(CanSM_BswMCurrentStateType, BSWM_VAR) BswM_CanSMMode[BSWM_CANSM_PORT_NUM] =
{
    CANSM_BSWM_NO_COMMUNICATION,
    CANSM_BSWM_NO_COMMUNICATION
};

/*ECUC_BswM_00880*/
VAR(ComM_ModeType, BSWM_VAR) BswM_ComMMode[BSWM_COMM_PORT_NUM] =
{
    COMM_NO_COMMUNICATION,
    COMM_NO_COMMUNICATION,
    COMM_NO_COMMUNICATION
};

/*ECUC_BswM_00956*/
VAR(NvM_RequestResultType, BSWM_VAR) BswM_NvMReadAllStatus = NVM_REQ_PENDING;
/*ECUC_BswM_00956*/
VAR(NvM_RequestResultType, BSWM_VAR) BswM_NvMWriteAllStatus = NVM_REQ_PENDING;

VAR(BswM_ModeType, BSWM_VAR) BswM_GeneralPortMode[BSWM_GENERAL_PORT_NUM] =
{
    BSWM_GENERIC_MODE_INIT
};

VAR(BswM_TimerState, BSWM_VAR) BswM_TimerMode = BSWM_TIMER_STOPPED;

#define BSWM_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"

#define BSWM_START_SEC_INIT_8
#include "MemMap.h"


/*ECUC_BswM_00863*/
VAR(Dcm_CommunicationModeType, BSWM_VAR) BswM_DcmComMMode[BSWM_MAX_DCM_COMMUNICATION_REQUESTING_NETWORK] =
{
    DCM_ENABLE_RX_TX_NORM_NM
};


#define BSWM_STOP_SEC_INIT_8
#include "MemMap.h"


#define BSWM_START_SEC_CONFIG_DATA_32
#include "MemMap.h"


#define BSWM_STOP_SEC_CONFIG_DATA_32
#include "MemMap.h"


#define BSWM_START_SEC_CONFIG_DATA_8
#include "MemMap.h"


CONST(BswMRuleType, BSWM_CONST) BswMPortMappingRulesStart[BSWM_MAX_PORT_NUM] =
{
    0,
    8,
    11,
    14,
    20,
    28,
    36,
    41,
    42,
    44,
    57
};

CONST(BswMRuleType, BSWM_CONST) BswMPortMappingRulesNum[BSWM_MAX_PORT_NUM] =
{
    8,
    3,
    3,
    6,
    8,
    8,
    5,
    1,
    2,
    13,
    2
};

CONST(BswMRuleType, BSWM_CONST) BswMPortMappingRules[BSWM_MAX_PORT_MAPPING_RULE_NUM] =
{
    BSWM_RULE_BswM_RuleRunToPostRun,
    BSWM_RULE_BswM_RulePostRunToRun,
    BSWM_RULE_BswM_RulePostRunToPrep,
    BSWM_RULE_BswM_RuleRunToPrep,
    BSWM_RULE_BswM_RulePrepToRun,
    BSWM_RULE_BswM_RulePrepToWriteNvM,
    BSWM_RULE_BswM_RuleWriteNvMToSleep,
    BSWM_RULE_BswM_RuleWriteNvMToRun,

    BSWM_RULE_BswM_RulePrepToWriteNvM,
    BSWM_RULE_BswM_RuleWriteNvMToSleep,
    BSWM_RULE_BswM_RuleComM0IpduGroupON,

    BSWM_RULE_BswM_RulePrepToWriteNvM,
    BSWM_RULE_BswM_RuleWriteNvMToSleep,
    BSWM_RULE_BswM_RuleComM1IpduGroupON,

    BSWM_RULE_BswM_RuleDcmReqComRxTx,
    BSWM_RULE_BswM_RuleDcmReqComRxNoTx,
    BSWM_RULE_BswM_RuleDcmReqComTxNoRx,
    BSWM_RULE_BswM_RuleDcmReqComNoRxTx,
    BSWM_RULE_BswM_RuleDcmReqNmTx,
    BSWM_RULE_BswM_RuleDcmReqNmNoTx,

    BSWM_RULE_BswM_RuleRunToPostRun,
    BSWM_RULE_BswM_RulePostRunToPrep,
    BSWM_RULE_BswM_RuleRunToPrep,
    BSWM_RULE_BswM_RulePrepToRun,
    BSWM_RULE_BswM_RulePrepToWriteNvM,
    BSWM_RULE_BswM_RuleWriteNvMToSleep,
    BSWM_RULE_BswM_RuleWriteNvMToRun,
    BSWM_RULE_BswM_RuleComM0IpduGroupON,

    BSWM_RULE_BswM_RuleRunToPostRun,
    BSWM_RULE_BswM_RulePostRunToPrep,
    BSWM_RULE_BswM_RuleRunToPrep,
    BSWM_RULE_BswM_RulePrepToRun,
    BSWM_RULE_BswM_RulePrepToWriteNvM,
    BSWM_RULE_BswM_RuleWriteNvMToSleep,
    BSWM_RULE_BswM_RuleWriteNvMToRun,
    BSWM_RULE_BswM_RuleComM1IpduGroupON,

    BSWM_RULE_BswM_RuleRunToPostRun,
    BSWM_RULE_BswM_RulePostRunToPrep,
    BSWM_RULE_BswM_RuleRunToPrep,
    BSWM_RULE_BswM_RulePrepToWriteNvM,
    BSWM_RULE_BswM_RuleWriteNvMToSleep,

    BSWM_RULE_BswM_RuleReadNvMToRun,

    BSWM_RULE_BswM_RuleWriteNvMToSleep,
    BSWM_RULE_BswM_RuleWriteNvMToRun,

    BSWM_RULE_BswM_RuleInitBlockII,
    BSWM_RULE_BswM_RuleWkupToReadNvM,
    BSWM_RULE_BswM_RuleReadNvMToRun,
    BSWM_RULE_BswM_RuleRunToPostRun,
    BSWM_RULE_BswM_RulePostRunToRun,
    BSWM_RULE_BswM_RulePostRunToPrep,
    BSWM_RULE_BswM_RuleRunToPrep,
    BSWM_RULE_BswM_RulePrepToRun,
    BSWM_RULE_BswM_RulePrepToWriteNvM,
    BSWM_RULE_BswM_RuleWriteNvMToSleep,
    BSWM_RULE_BswM_RuleWriteNvMToRun,
    BSWM_RULE_BswM_RuleComM0IpduGroupON,
    BSWM_RULE_BswM_RuleComM1IpduGroupON,

    BSWM_RULE_BswM_RuleRunToPostRun,
    BSWM_RULE_BswM_RuleRunToPrep

};


#define BSWM_STOP_SEC_CONFIG_DATA_8
#include "MemMap.h"


#define BSWM_START_SEC_CODE
#include "MemMap.h"


STATIC FUNC(Std_ReturnType, BSWM_CODE) BswM_ALInitBlockIITrueFunc0(void)
{
    BswM_InitBlockIICallout();

    BswM_RequestMode(BswM_SysState, BSWM_GENERIC_MODE_WAKEUP);
    EcuM_SetState(ECUM_STATE_RUN);
    ComM_CommunicationAllowed(ComM_ComM_CanCtrl_0, TRUE);
    ComM_CommunicationAllowed(ComM_ComM_CanCtrl_1, TRUE);
    ComM_CommunicationAllowed(ComM_ComM_EthCtrl, TRUE);

    return E_OK;
}
STATIC FUNC(Std_ReturnType, BSWM_CODE) BswM_ALWkupToReadNvMTrueFunc0(void)
{
    BswM_NvMReadAllCallout();

    BswM_RequestMode(BswM_SysState, BSWM_GENERIC_MODE_READ_NVM);

    return E_OK;
}
STATIC FUNC(Std_ReturnType, BSWM_CODE) BswM_ALReadNvMToRunTrueFunc0(void)
{
    BswM_PostReadAllCallout();

    BswM_SetTimer(10);
    EcuM_SetState(ECUM_STATE_APP_RUN);
    BswM_RequestMode(BswM_SysState, BSWM_GENERIC_MODE_APP_RUN);

    return E_OK;
}
STATIC FUNC(Std_ReturnType, BSWM_CODE) BswM_ALRunToPostRunTrueFunc0(void)
{
    Com_IpduGroupStop(Com_ACANTx);
    Com_IpduGroupStop(Com_ACANRx);
    Com_IpduGroupStop(Com_RadarRx);

    EcuM_SetState(ECUM_STATE_APP_POST_RUN);
    BswM_RequestMode(BswM_SysState, BSWM_GENERIC_MODE_POST_RUN);

    return E_OK;
}
STATIC FUNC(Std_ReturnType, BSWM_CODE) BswM_ALPostRunToRunTrueFunc0(void)
{
    BswM_SetTimer(10);
    EcuM_SetState(ECUM_STATE_APP_RUN);
    BswM_RequestMode(BswM_SysState, BSWM_GENERIC_MODE_APP_RUN);

    return E_OK;
}
STATIC FUNC(Std_ReturnType, BSWM_CODE) BswM_ALPrepToRunTrueFunc0(void)
{
    BswM_SetTimer(10);
    EcuM_SetState(ECUM_STATE_APP_RUN);
    BswM_RequestMode(BswM_SysState, BSWM_GENERIC_MODE_APP_RUN);

    return E_OK;
}
STATIC FUNC(Std_ReturnType, BSWM_CODE) BswM_ALPostRunToPrepTrueFunc0(void)
{
    BswM_RequestMode(BswM_SysState, BSWM_GENERIC_MODE_PREP_SHUTDOWN);

    return E_OK;
}
STATIC FUNC(Std_ReturnType, BSWM_CODE) BswM_ALRunToPrepTrueFunc0(void)
{
    Com_IpduGroupStop(Com_ACANTx);
    Com_IpduGroupStop(Com_ACANRx);
    Com_IpduGroupStop(Com_RadarRx);

    BswM_RequestMode(BswM_SysState, BSWM_GENERIC_MODE_PREP_SHUTDOWN);

    return E_OK;
}
STATIC FUNC(Std_ReturnType, BSWM_CODE) BswM_ALPrepToWriteNvMTrueFunc0(void)
{
    BswM_NvMWriteAllCallout();

    BswM_RequestMode(BswM_SysState, BSWM_GENERIC_MODE_WRITE_NVM);

    return E_OK;
}
STATIC FUNC(Std_ReturnType, BSWM_CODE) BswM_ALWriteNvMToSleepTrueFunc0(void)
{
    EcuM_SetState(ECUM_STATE_SLEEP);
    BswM_WriteNvMToSleepCallout();


    return E_OK;
}
STATIC FUNC(Std_ReturnType, BSWM_CODE) BswM_ALComM0IpduGroupONTrueFunc0(void)
{
    Com_IpduGroupStart(Com_ACANRx, FALSE);
    Com_IpduGroupStart(Com_ACANTx, FALSE);


    return E_OK;
}
STATIC FUNC(Std_ReturnType, BSWM_CODE) BswM_ALComM1IpduGroupONTrueFunc0(void)
{
    Com_IpduGroupStart(Com_RadarRx, FALSE);


    return E_OK;
}
STATIC FUNC(Std_ReturnType, BSWM_CODE) BswM_ALDcmReqComRxTxTrueFunc0(void)
{
    Com_IpduGroupStart(Com_ACANRx, FALSE);
    Com_IpduGroupStart(Com_RadarRx, FALSE);
    Com_IpduGroupStart(Com_ACANTx, FALSE);


    return E_OK;
}
STATIC FUNC(Std_ReturnType, BSWM_CODE) BswM_ALDcmReqComRxNoTxTrueFunc0(void)
{
    Com_IpduGroupStop(Com_ACANTx);
    Com_IpduGroupStart(Com_ACANRx, FALSE);
    Com_IpduGroupStart(Com_RadarRx, FALSE);


    return E_OK;
}
STATIC FUNC(Std_ReturnType, BSWM_CODE) BswM_ALDcmReqComTxNoRxTrueFunc0(void)
{
    Com_IpduGroupStop(Com_ACANRx);
    Com_IpduGroupStop(Com_RadarRx);
    Com_IpduGroupStart(Com_ACANTx, FALSE);


    return E_OK;
}
STATIC FUNC(Std_ReturnType, BSWM_CODE) BswM_ALDcmReqComNoRxTxTrueFunc0(void)
{
    Com_IpduGroupStop(Com_ACANRx);
    Com_IpduGroupStop(Com_RadarRx);
    Com_IpduGroupStop(Com_ACANTx);


    return E_OK;
}
STATIC FUNC(Std_ReturnType, BSWM_CODE) BswM_ALDcmReqNmTxTrueFunc0(void)
{
    Nm_EnableCommunication(NM_Nm_CanCtrl_0);
    Nm_EnableCommunication(NM_NmEthCtrl);

    return E_OK;
}
STATIC FUNC(Std_ReturnType, BSWM_CODE) BswM_ALDcmReqNmNoTxTrueFunc0(void)
{
    Nm_DisableCommunication (NM_Nm_CanCtrl_0);
    Nm_DisableCommunication (NM_NmEthCtrl);

    return E_OK;
}
STATIC FUNC(BswMRuleStateType, BSWM_CODE) BswM_RuleInitBlockII(void)
{
    BswMRuleStateType ret;

    if(BswM_GeneralPortMode[0] == BSWM_GENERIC_MODE_INIT)
    {
        ret = BSWM_TRUE;
    }
    else
    {
        ret = BSWM_FALSE;
    }

    return ret;
}

STATIC FUNC(BswMRuleStateType, BSWM_CODE) BswM_RuleWkupToReadNvM(void)
{
    BswMRuleStateType ret;

    if(BswM_GeneralPortMode[0] == BSWM_GENERIC_MODE_WAKEUP)
    {
        ret = BSWM_TRUE;
    }
    else
    {
        ret = BSWM_FALSE;
    }

    return ret;
}

STATIC FUNC(BswMRuleStateType, BSWM_CODE) BswM_RuleReadNvMToRun(void)
{
    BswMRuleStateType ret;

    if(((BswM_NvMReadAllStatus == NVM_REQ_OK)
       || (BswM_NvMReadAllStatus == NVM_REQ_NOT_OK))
       && (BswM_GeneralPortMode[0] == BSWM_GENERIC_MODE_READ_NVM)
      )
    {
        ret = BSWM_TRUE;
    }
    else
    {
        ret = BSWM_FALSE;
    }

    return ret;
}

STATIC FUNC(BswMRuleStateType, BSWM_CODE) BswM_RuleRunToPostRun(void)
{
    BswMRuleStateType ret;

    if((BswM_EcuMRequestMode == ECUM_STATE_APP_POST_RUN)
       && (BswM_ComMMode[0] == COMM_NO_COMMUNICATION)
       && (BswM_ComMMode[1] == COMM_NO_COMMUNICATION)
       && (BswM_ComMMode[2] == COMM_NO_COMMUNICATION)
       && (BswM_GeneralPortMode[0] == BSWM_GENERIC_MODE_APP_RUN)
       && (BswM_TimerMode == BSWM_TIMER_EXPIRED)
      )
    {
        ret = BSWM_TRUE;
    }
    else
    {
        ret = BSWM_FALSE;
    }

    return ret;
}

STATIC FUNC(BswMRuleStateType, BSWM_CODE) BswM_RulePostRunToRun(void)
{
    BswMRuleStateType ret;

    if((BswM_EcuMRequestMode == ECUM_STATE_APP_RUN)
       && (BswM_GeneralPortMode[0] == BSWM_GENERIC_MODE_POST_RUN)
      )
    {
        ret = BSWM_TRUE;
    }
    else
    {
        ret = BSWM_FALSE;
    }

    return ret;
}

STATIC FUNC(BswMRuleStateType, BSWM_CODE) BswM_RulePostRunToPrep(void)
{
    BswMRuleStateType ret;

    if((BswM_EcuMRequestMode == ECUM_STATE_SHUTDOWN)
       && (BswM_ComMMode[0] == COMM_NO_COMMUNICATION)
       && (BswM_ComMMode[1] == COMM_NO_COMMUNICATION)
       && (BswM_ComMMode[2] == COMM_NO_COMMUNICATION)
       && (BswM_GeneralPortMode[0] == BSWM_GENERIC_MODE_POST_RUN)
      )
    {
        ret = BSWM_TRUE;
    }
    else
    {
        ret = BSWM_FALSE;
    }

    return ret;
}

STATIC FUNC(BswMRuleStateType, BSWM_CODE) BswM_RuleRunToPrep(void)
{
    BswMRuleStateType ret;

    if((BswM_EcuMRequestMode == ECUM_STATE_SHUTDOWN)
       && (BswM_ComMMode[0] == COMM_NO_COMMUNICATION)
       && (BswM_ComMMode[1] == COMM_NO_COMMUNICATION)
       && (BswM_ComMMode[2] == COMM_NO_COMMUNICATION)
       && (BswM_GeneralPortMode[0] == BSWM_GENERIC_MODE_APP_RUN)
       && (BswM_TimerMode == BSWM_TIMER_EXPIRED)
      )
    {
        ret = BSWM_TRUE;
    }
    else
    {
        ret = BSWM_FALSE;
    }

    return ret;
}

STATIC FUNC(BswMRuleStateType, BSWM_CODE) BswM_RulePrepToRun(void)
{
    BswMRuleStateType ret;

    if(((BswM_EcuMRequestMode == ECUM_STATE_APP_RUN)
       || (BswM_ComMMode[0] == COMM_FULL_COMMUNICATION)
       || (BswM_ComMMode[1] == COMM_FULL_COMMUNICATION))
       && (BswM_GeneralPortMode[0] == BSWM_GENERIC_MODE_PREP_SHUTDOWN)
      )
    {
        ret = BSWM_TRUE;
    }
    else
    {
        ret = BSWM_FALSE;
    }

    return ret;
}

STATIC FUNC(BswMRuleStateType, BSWM_CODE) BswM_RulePrepToWriteNvM(void)
{
    BswMRuleStateType ret;

    if((BswM_EcuMRequestMode == ECUM_STATE_SHUTDOWN)
       && (BswM_CanSMMode[0] == CANSM_BSWM_NO_COMMUNICATION)
       && (BswM_CanSMMode[1] == CANSM_BSWM_NO_COMMUNICATION)
       && (BswM_ComMMode[0] == COMM_NO_COMMUNICATION)
       && (BswM_ComMMode[1] == COMM_NO_COMMUNICATION)
       && (BswM_ComMMode[2] == COMM_NO_COMMUNICATION)
       && (BswM_GeneralPortMode[0] == BSWM_GENERIC_MODE_PREP_SHUTDOWN)
      )
    {
        ret = BSWM_TRUE;
    }
    else
    {
        ret = BSWM_FALSE;
    }

    return ret;
}

STATIC FUNC(BswMRuleStateType, BSWM_CODE) BswM_RuleWriteNvMToSleep(void)
{
    BswMRuleStateType ret;

    if(((BswM_NvMWriteAllStatus == NVM_REQ_OK)
       || (BswM_NvMWriteAllStatus == NVM_REQ_NOT_OK))
       && (BswM_EcuMRequestMode == ECUM_STATE_SHUTDOWN)
       && (BswM_CanSMMode[0] == CANSM_BSWM_NO_COMMUNICATION)
       && (BswM_CanSMMode[1] == CANSM_BSWM_NO_COMMUNICATION)
       && (BswM_ComMMode[0] == COMM_NO_COMMUNICATION)
       && (BswM_ComMMode[1] == COMM_NO_COMMUNICATION)
       && (BswM_ComMMode[2] == COMM_NO_COMMUNICATION)
       && (BswM_GeneralPortMode[0] == BSWM_GENERIC_MODE_WRITE_NVM)
      )
    {
        ret = BSWM_TRUE;
    }
    else
    {
        ret = BSWM_FALSE;
    }

    return ret;
}

STATIC FUNC(BswMRuleStateType, BSWM_CODE) BswM_RuleWriteNvMToRun(void)
{
    BswMRuleStateType ret;

    if(((BswM_EcuMRequestMode == ECUM_STATE_APP_RUN)
       || (BswM_ComMMode[0] == COMM_FULL_COMMUNICATION)
       || (BswM_ComMMode[1] == COMM_FULL_COMMUNICATION))
           && ((BswM_NvMWriteAllStatus == NVM_REQ_OK)
       || (BswM_NvMWriteAllStatus == NVM_REQ_NOT_OK))
       && (BswM_GeneralPortMode[0] == BSWM_GENERIC_MODE_WRITE_NVM)
      )
    {
        ret = BSWM_TRUE;
    }
    else
    {
        ret = BSWM_FALSE;
    }

    return ret;
}

STATIC FUNC(BswMRuleStateType, BSWM_CODE) BswM_RuleComM0IpduGroupON(void)
{
    BswMRuleStateType ret;

    if((BswM_CanSMMode[0] == CANSM_BSWM_FULL_COMMUNICATION)
       && (BswM_ComMMode[0] == COMM_FULL_COMMUNICATION)
       && (BswM_GeneralPortMode[0] == BSWM_GENERIC_MODE_APP_RUN)
      )
    {
        ret = BSWM_TRUE;
    }
    else
    {
        ret = BSWM_FALSE;
    }

    return ret;
}

STATIC FUNC(BswMRuleStateType, BSWM_CODE) BswM_RuleComM1IpduGroupON(void)
{
    BswMRuleStateType ret;

    if((BswM_CanSMMode[1] == CANSM_BSWM_FULL_COMMUNICATION)
       && (BswM_ComMMode[1] == COMM_FULL_COMMUNICATION)
       && (BswM_GeneralPortMode[0] == BSWM_GENERIC_MODE_APP_RUN)
      )
    {
        ret = BSWM_TRUE;
    }
    else
    {
        ret = BSWM_FALSE;
    }

    return ret;
}

STATIC FUNC(BswMRuleStateType, BSWM_CODE) BswM_RuleDcmReqComRxTx(void)
{
    BswMRuleStateType ret;

    if((BswM_DcmComMMode[0] == DCM_ENABLE_RX_TX_NORM)
       || (BswM_DcmComMMode[0] == DCM_ENABLE_RX_TX_NORM_NM)
      )
    {
        ret = BSWM_TRUE;
    }
    else
    {
        ret = BSWM_FALSE;
    }

    return ret;
}

STATIC FUNC(BswMRuleStateType, BSWM_CODE) BswM_RuleDcmReqComRxNoTx(void)
{
    BswMRuleStateType ret;

    if((BswM_DcmComMMode[0] == DCM_ENABLE_RX_DISABLE_TX_NORM)
       || (BswM_DcmComMMode[0] == DCM_ENABLE_RX_DISABLE_TX_NORM_NM)
      )
    {
        ret = BSWM_TRUE;
    }
    else
    {
        ret = BSWM_FALSE;
    }

    return ret;
}

STATIC FUNC(BswMRuleStateType, BSWM_CODE) BswM_RuleDcmReqComTxNoRx(void)
{
    BswMRuleStateType ret;

    if((BswM_DcmComMMode[0] == DCM_DISABLE_RX_ENABLE_TX_NORM)
       || (BswM_DcmComMMode[0] == DCM_DISABLE_RX_ENABLE_TX_NORM_NM)
      )
    {
        ret = BSWM_TRUE;
    }
    else
    {
        ret = BSWM_FALSE;
    }

    return ret;
}

STATIC FUNC(BswMRuleStateType, BSWM_CODE) BswM_RuleDcmReqComNoRxTx(void)
{
    BswMRuleStateType ret;

    if((BswM_DcmComMMode[0] == DCM_DISABLE_RX_TX_NORMAL)
       || (BswM_DcmComMMode[0] == DCM_DISABLE_RX_TX_NORM_NM)
      )
    {
        ret = BSWM_TRUE;
    }
    else
    {
        ret = BSWM_FALSE;
    }

    return ret;
}

STATIC FUNC(BswMRuleStateType, BSWM_CODE) BswM_RuleDcmReqNmTx(void)
{
    BswMRuleStateType ret;

    if((BswM_DcmComMMode[0] == DCM_ENABLE_RX_TX_NM)
       || (BswM_DcmComMMode[0] == DCM_DISABLE_RX_ENABLE_TX_NM)
       || (BswM_DcmComMMode[0] == DCM_ENABLE_RX_TX_NORM_NM)
       || (BswM_DcmComMMode[0] == DCM_DISABLE_RX_ENABLE_TX_NORM_NM)
      )
    {
        ret = BSWM_TRUE;
    }
    else
    {
        ret = BSWM_FALSE;
    }

    return ret;
}

STATIC FUNC(BswMRuleStateType, BSWM_CODE) BswM_RuleDcmReqNmNoTx(void)
{
    BswMRuleStateType ret;

    if((BswM_DcmComMMode[0] == DCM_DISABLE_RX_TX_NM)
       || (BswM_DcmComMMode[0] == DCM_ENABLE_RX_DISABLE_TX_NM)
       || (BswM_DcmComMMode[0] == DCM_DISABLE_RX_TX_NORM_NM)
       || (BswM_DcmComMMode[0] == DCM_ENABLE_RX_DISABLE_TX_NORM_NM)
      )
    {
        ret = BSWM_TRUE;
    }
    else
    {
        ret = BSWM_FALSE;
    }

    return ret;
}


#define BSWM_STOP_SEC_CODE
#include "MemMap.h"

#define BSWM_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "MemMap.h"


STATIC CONST(BswM_ActionListItemType, BSWM_CONST)BswM_ALInitBlockIITrueHead0;
STATIC CONST(BswM_ActionListItemType, BSWM_CONST)BswM_ALWkupToReadNvMTrueHead0;
STATIC CONST(BswM_ActionListItemType, BSWM_CONST)BswM_ALReadNvMToRunTrueHead0;
STATIC CONST(BswM_ActionListItemType, BSWM_CONST)BswM_ALRunToPostRunTrueHead0;
STATIC CONST(BswM_ActionListItemType, BSWM_CONST)BswM_ALPostRunToRunTrueHead0;
STATIC CONST(BswM_ActionListItemType, BSWM_CONST)BswM_ALPrepToRunTrueHead0;
STATIC CONST(BswM_ActionListItemType, BSWM_CONST)BswM_ALPostRunToPrepTrueHead0;
STATIC CONST(BswM_ActionListItemType, BSWM_CONST)BswM_ALRunToPrepTrueHead0;
STATIC CONST(BswM_ActionListItemType, BSWM_CONST)BswM_ALPrepToWriteNvMTrueHead0;
STATIC CONST(BswM_ActionListItemType, BSWM_CONST)BswM_ALWriteNvMToSleepTrueHead0;
STATIC CONST(BswM_ActionListItemType, BSWM_CONST)BswM_ALComM0IpduGroupONTrueHead0;
STATIC CONST(BswM_ActionListItemType, BSWM_CONST)BswM_ALComM1IpduGroupONTrueHead0;
STATIC CONST(BswM_ActionListItemType, BSWM_CONST)BswM_ALDcmReqComRxTxTrueHead0;
STATIC CONST(BswM_ActionListItemType, BSWM_CONST)BswM_ALDcmReqComRxNoTxTrueHead0;
STATIC CONST(BswM_ActionListItemType, BSWM_CONST)BswM_ALDcmReqComTxNoRxTrueHead0;
STATIC CONST(BswM_ActionListItemType, BSWM_CONST)BswM_ALDcmReqComNoRxTxTrueHead0;
STATIC CONST(BswM_ActionListItemType, BSWM_CONST)BswM_ALDcmReqNmTxTrueHead0;
STATIC CONST(BswM_ActionListItemType, BSWM_CONST)BswM_ALDcmReqNmNoTxTrueHead0;

STATIC CONST(BswM_ActionListItemType, BSWM_CONST) BswM_ALInitBlockIITrueHead0 =
{
    BSWM_ACTION,
    BswM_ALInitBlockIITrueFunc0,
    BSWM_ACTIONLIST_NULL,
    BSWM_RULE_NULL,
    NULL_PTR
};
STATIC CONST(BswM_ActionListItemType, BSWM_CONST) BswM_ALWkupToReadNvMTrueHead0 =
{
    BSWM_ACTION,
    BswM_ALWkupToReadNvMTrueFunc0,
    BSWM_ACTIONLIST_NULL,
    BSWM_RULE_NULL,
    NULL_PTR
};
STATIC CONST(BswM_ActionListItemType, BSWM_CONST) BswM_ALReadNvMToRunTrueHead0 =
{
    BSWM_ACTION,
    BswM_ALReadNvMToRunTrueFunc0,
    BSWM_ACTIONLIST_NULL,
    BSWM_RULE_NULL,
    NULL_PTR
};
STATIC CONST(BswM_ActionListItemType, BSWM_CONST) BswM_ALRunToPostRunTrueHead0 =
{
    BSWM_ACTION,
    BswM_ALRunToPostRunTrueFunc0,
    BSWM_ACTIONLIST_NULL,
    BSWM_RULE_NULL,
    NULL_PTR
};
STATIC CONST(BswM_ActionListItemType, BSWM_CONST) BswM_ALPostRunToRunTrueHead0 =
{
    BSWM_ACTION,
    BswM_ALPostRunToRunTrueFunc0,
    BSWM_ACTIONLIST_NULL,
    BSWM_RULE_NULL,
    NULL_PTR
};
STATIC CONST(BswM_ActionListItemType, BSWM_CONST) BswM_ALPrepToRunTrueHead0 =
{
    BSWM_ACTION,
    BswM_ALPrepToRunTrueFunc0,
    BSWM_ACTIONLIST_NULL,
    BSWM_RULE_NULL,
    NULL_PTR
};
STATIC CONST(BswM_ActionListItemType, BSWM_CONST) BswM_ALPostRunToPrepTrueHead0 =
{
    BSWM_ACTION,
    BswM_ALPostRunToPrepTrueFunc0,
    BSWM_ACTIONLIST_NULL,
    BSWM_RULE_NULL,
    NULL_PTR
};
STATIC CONST(BswM_ActionListItemType, BSWM_CONST) BswM_ALRunToPrepTrueHead0 =
{
    BSWM_ACTION,
    BswM_ALRunToPrepTrueFunc0,
    BSWM_ACTIONLIST_NULL,
    BSWM_RULE_NULL,
    NULL_PTR
};
STATIC CONST(BswM_ActionListItemType, BSWM_CONST) BswM_ALPrepToWriteNvMTrueHead0 =
{
    BSWM_ACTION,
    BswM_ALPrepToWriteNvMTrueFunc0,
    BSWM_ACTIONLIST_NULL,
    BSWM_RULE_NULL,
    NULL_PTR
};
STATIC CONST(BswM_ActionListItemType, BSWM_CONST) BswM_ALWriteNvMToSleepTrueHead0 =
{
    BSWM_ACTION,
    BswM_ALWriteNvMToSleepTrueFunc0,
    BSWM_ACTIONLIST_NULL,
    BSWM_RULE_NULL,
    NULL_PTR
};
STATIC CONST(BswM_ActionListItemType, BSWM_CONST) BswM_ALComM0IpduGroupONTrueHead0 =
{
    BSWM_ACTION,
    BswM_ALComM0IpduGroupONTrueFunc0,
    BSWM_ACTIONLIST_NULL,
    BSWM_RULE_NULL,
    NULL_PTR
};
STATIC CONST(BswM_ActionListItemType, BSWM_CONST) BswM_ALComM1IpduGroupONTrueHead0 =
{
    BSWM_ACTION,
    BswM_ALComM1IpduGroupONTrueFunc0,
    BSWM_ACTIONLIST_NULL,
    BSWM_RULE_NULL,
    NULL_PTR
};
STATIC CONST(BswM_ActionListItemType, BSWM_CONST) BswM_ALDcmReqComRxTxTrueHead0 =
{
    BSWM_ACTION,
    BswM_ALDcmReqComRxTxTrueFunc0,
    BSWM_ACTIONLIST_NULL,
    BSWM_RULE_NULL,
    NULL_PTR
};
STATIC CONST(BswM_ActionListItemType, BSWM_CONST) BswM_ALDcmReqComRxNoTxTrueHead0 =
{
    BSWM_ACTION,
    BswM_ALDcmReqComRxNoTxTrueFunc0,
    BSWM_ACTIONLIST_NULL,
    BSWM_RULE_NULL,
    NULL_PTR
};
STATIC CONST(BswM_ActionListItemType, BSWM_CONST) BswM_ALDcmReqComTxNoRxTrueHead0 =
{
    BSWM_ACTION,
    BswM_ALDcmReqComTxNoRxTrueFunc0,
    BSWM_ACTIONLIST_NULL,
    BSWM_RULE_NULL,
    NULL_PTR
};
STATIC CONST(BswM_ActionListItemType, BSWM_CONST) BswM_ALDcmReqComNoRxTxTrueHead0 =
{
    BSWM_ACTION,
    BswM_ALDcmReqComNoRxTxTrueFunc0,
    BSWM_ACTIONLIST_NULL,
    BSWM_RULE_NULL,
    NULL_PTR
};
STATIC CONST(BswM_ActionListItemType, BSWM_CONST) BswM_ALDcmReqNmTxTrueHead0 =
{
    BSWM_ACTION,
    BswM_ALDcmReqNmTxTrueFunc0,
    BSWM_ACTIONLIST_NULL,
    BSWM_RULE_NULL,
    NULL_PTR
};
STATIC CONST(BswM_ActionListItemType, BSWM_CONST) BswM_ALDcmReqNmNoTxTrueHead0 =
{
    BSWM_ACTION,
    BswM_ALDcmReqNmNoTxTrueFunc0,
    BSWM_ACTIONLIST_NULL,
    BSWM_RULE_NULL,
    NULL_PTR
};
CONST(BswM_RuleCfgType, BSWM_CONST) BswMAvailableRules[BSWM_MAX_RULE_NUM] =
{
    /*BswM_RuleInitBlockII*/
    {
        BSWM_FALSE,
        BswM_RuleInitBlockII,
        BSWM_ACTIONLIST_BswM_ALInitBlockII,
        BSWM_ACTIONLIST_NULL,
        BSWM_IMMEDIATE
    },
    /*BswM_RuleWkupToReadNvM*/
    {
        BSWM_FALSE,
        BswM_RuleWkupToReadNvM,
        BSWM_ACTIONLIST_BswM_ALWkupToReadNvM,
        BSWM_ACTIONLIST_NULL,
        BSWM_IMMEDIATE
    },
    /*BswM_RuleReadNvMToRun*/
    {
        BSWM_FALSE,
        BswM_RuleReadNvMToRun,
        BSWM_ACTIONLIST_BswM_ALReadNvMToRun,
        BSWM_ACTIONLIST_NULL,
        BSWM_IMMEDIATE
    },
    /*BswM_RuleRunToPostRun*/
    {
        BSWM_FALSE,
        BswM_RuleRunToPostRun,
        BSWM_ACTIONLIST_BswM_ALRunToPostRun,
        BSWM_ACTIONLIST_NULL,
        BSWM_DEFERRED
    },
    /*BswM_RulePostRunToRun*/
    {
        BSWM_FALSE,
        BswM_RulePostRunToRun,
        BSWM_ACTIONLIST_BswM_ALPostRunToRun,
        BSWM_ACTIONLIST_NULL,
        BSWM_DEFERRED
    },
    /*BswM_RulePostRunToPrep*/
    {
        BSWM_FALSE,
        BswM_RulePostRunToPrep,
        BSWM_ACTIONLIST_BswM_ALPostRunToPrep,
        BSWM_ACTIONLIST_NULL,
        BSWM_DEFERRED
    },
    /*BswM_RuleRunToPrep*/
    {
        BSWM_FALSE,
        BswM_RuleRunToPrep,
        BSWM_ACTIONLIST_BswM_ALRunToPrep,
        BSWM_ACTIONLIST_NULL,
        BSWM_DEFERRED
    },
    /*BswM_RulePrepToRun*/
    {
        BSWM_FALSE,
        BswM_RulePrepToRun,
        BSWM_ACTIONLIST_BswM_ALPrepToRun,
        BSWM_ACTIONLIST_NULL,
        BSWM_DEFERRED
    },
    /*BswM_RulePrepToWriteNvM*/
    {
        BSWM_FALSE,
        BswM_RulePrepToWriteNvM,
        BSWM_ACTIONLIST_BswM_ALPrepToWriteNvM,
        BSWM_ACTIONLIST_NULL,
        BSWM_DEFERRED
    },
    /*BswM_RuleWriteNvMToSleep*/
    {
        BSWM_FALSE,
        BswM_RuleWriteNvMToSleep,
        BSWM_ACTIONLIST_BswM_ALWriteNvMToSleep,
        BSWM_ACTIONLIST_NULL,
        BSWM_DEFERRED
    },
    /*BswM_RuleWriteNvMToRun*/
    {
        BSWM_FALSE,
        BswM_RuleWriteNvMToRun,
        BSWM_ACTIONLIST_BswM_ALReadNvMToRun,
        BSWM_ACTIONLIST_NULL,
        BSWM_DEFERRED
    },
    /*BswM_RuleComM0IpduGroupON*/
    {
        BSWM_FALSE,
        BswM_RuleComM0IpduGroupON,
        BSWM_ACTIONLIST_BswM_ALComM0IpduGroupON,
        BSWM_ACTIONLIST_NULL,
        BSWM_DEFERRED
    },
    /*BswM_RuleComM1IpduGroupON*/
    {
        BSWM_FALSE,
        BswM_RuleComM1IpduGroupON,
        BSWM_ACTIONLIST_BswM_ALComM1IpduGroupON,
        BSWM_ACTIONLIST_NULL,
        BSWM_DEFERRED
    },
    /*BswM_RuleDcmReqComRxTx*/
    {
        BSWM_FALSE,
        BswM_RuleDcmReqComRxTx,
        BSWM_ACTIONLIST_BswM_ALDcmReqComRxTx,
        BSWM_ACTIONLIST_NULL,
        BSWM_DEFERRED
    },
    /*BswM_RuleDcmReqComRxNoTx*/
    {
        BSWM_FALSE,
        BswM_RuleDcmReqComRxNoTx,
        BSWM_ACTIONLIST_BswM_ALDcmReqComRxNoTx,
        BSWM_ACTIONLIST_NULL,
        BSWM_DEFERRED
    },
    /*BswM_RuleDcmReqComTxNoRx*/
    {
        BSWM_FALSE,
        BswM_RuleDcmReqComTxNoRx,
        BSWM_ACTIONLIST_BswM_ALDcmReqComTxNoRx,
        BSWM_ACTIONLIST_NULL,
        BSWM_DEFERRED
    },
    /*BswM_RuleDcmReqComNoRxTx*/
    {
        BSWM_FALSE,
        BswM_RuleDcmReqComNoRxTx,
        BSWM_ACTIONLIST_BswM_ALDcmReqComNoRxTx,
        BSWM_ACTIONLIST_NULL,
        BSWM_DEFERRED
    },
    /*BswM_RuleDcmReqNmTx*/
    {
        BSWM_FALSE,
        BswM_RuleDcmReqNmTx,
        BSWM_ACTIONLIST_BswM_ALDcmReqNmTx,
        BSWM_ACTIONLIST_NULL,
        BSWM_DEFERRED
    },
    /*BswM_RuleDcmReqNmNoTx*/
    {
        BSWM_FALSE,
        BswM_RuleDcmReqNmNoTx,
        BSWM_ACTIONLIST_BswM_ALDcmReqNmNoTx,
        BSWM_ACTIONLIST_NULL,
        BSWM_DEFERRED
    }
};
CONST(BswMActionList, BSWM_CONST) BswMAvailableActionLists[BSWM_MAX_ACTIONLIST_NUM] =
{
    {
        BSWM_CONDITION,
        &BswM_ALInitBlockIITrueHead0
    },
    {
        BSWM_TRIGGER,
        &BswM_ALWkupToReadNvMTrueHead0
    },
    {
        BSWM_TRIGGER,
        &BswM_ALReadNvMToRunTrueHead0
    },
    {
        BSWM_TRIGGER,
        &BswM_ALRunToPostRunTrueHead0
    },
    {
        BSWM_TRIGGER,
        &BswM_ALPostRunToRunTrueHead0
    },
    {
        BSWM_TRIGGER,
        &BswM_ALPrepToRunTrueHead0
    },
    {
        BSWM_TRIGGER,
        &BswM_ALPostRunToPrepTrueHead0
    },
    {
        BSWM_TRIGGER,
        &BswM_ALRunToPrepTrueHead0
    },
    {
        BSWM_TRIGGER,
        &BswM_ALPrepToWriteNvMTrueHead0
    },
    {
        BSWM_TRIGGER,
        &BswM_ALWriteNvMToSleepTrueHead0
    },
    {
        BSWM_CONDITION,
        &BswM_ALComM0IpduGroupONTrueHead0
    },
    {
        BSWM_CONDITION,
        &BswM_ALComM1IpduGroupONTrueHead0
    },
    {
        BSWM_CONDITION,
        &BswM_ALDcmReqComRxTxTrueHead0
    },
    {
        BSWM_CONDITION,
        &BswM_ALDcmReqComRxNoTxTrueHead0
    },
    {
        BSWM_CONDITION,
        &BswM_ALDcmReqComTxNoRxTrueHead0
    },
    {
        BSWM_CONDITION,
        &BswM_ALDcmReqComNoRxTxTrueHead0
    },
    {
        BSWM_CONDITION,
        &BswM_ALDcmReqNmTxTrueHead0
    },
    {
        BSWM_CONDITION,
        &BswM_ALDcmReqNmNoTxTrueHead0
    }
};

#define BSWM_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "MemMap.h"




