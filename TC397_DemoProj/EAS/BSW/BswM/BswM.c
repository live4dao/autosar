/*  BEGIN_FILE_HDR
********************************************************************************
*   NOTICE
*   This software is the property of HiRain Technologies. Any information
*   contained in this doc should not be reproduced, or used, or disclosed
*   without the written authorization from HiRain Technologies.
********************************************************************************
*   File Name       : BswM.c
********************************************************************************
*   Project/Product : AUTOSAR 4.2
*   Title           : BswM.c
*   Author          : Hirain
********************************************************************************
*   Description     : Implementation of BswM provided functionality
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
*   01.00.00    08/10/2016    Boxue.Li      N/A          Beta
*   01.01.00    26/06/2018    Boxue.Li      N/A          Original
*   01.01.01    04/09/2018    Boxue.Li      N/A          EAS422_BswM_20180904_01
*   01.01.02    21/01/2019    Boxue.Li      N/A          EAS422_BswM_20190121_01
*   01.01.03    22/01/2019    Boxue.Li      N/A          EAS422_BswM_20190122_01
*   01.01.04    04/03/2019    Boxue.Li      N/A          EAS422_BswM_20190304_01
*   01.01.05    08/03/2019    Boxue.Li      N/A          EAS422_BswM_20190308_01
*   01.01.06    11/03/2019    Boxue.Li      N/A          EAS422_BswM_20190311_01
*   01.01.07    31/03/2020    Boxue.Li      N/A          EAS422_BswM_20200331_01
*   01.01.08    05/06/2020    Boxue.Li      N/A          EAS422_BswM_20200605_01
*   01.01.09    04/08/2020    Boxue.Li      N/A          EAS422_BswM_20200804_01
*   01.01.10    11/06/2021    Boxue.Li      N/A          EAS422_BswM_20210611_01
*   01.01.11    01/09/2021    Boxue.Li      N/A          EAS422_BswM_20210901_01
*   01.01.12    16/01/2023    Feixiang.Dong N/A          EAS422_BswM_20230116_01
********************************************************************************
* END_FILE_HDR*/

/*******************************************************************************
*   Includes
*******************************************************************************/
#include "BswM.h"
#include "ComStack_Types.h"
#include "SchM_BswM.h"

#if(STD_ON == BSWM_ECUM_ENABLED)
#include "EcuM.h"
#endif

#if(STD_ON == BSWM_COMM_ENABLED)
#include "ComM.h"
#endif

#if(STD_ON == BSWM_NVM_ENABLED)
#include "NvM.h"
#endif

#if(STD_ON == BSWM_CANSM_ENABLED)
#include "CanSM_BswM.h"
#endif

#if(STD_ON == BSWM_LINSM_ENABLED)
#include "LinSM.h"
#endif

#if(STD_ON == BSWM_FRSM_ENABLED)
#include "FrSM.h"
#endif

#if(STD_ON == BSWM_ETHSM_ENABLED)
#include "EthSM.h"
#endif

#if(STD_ON == BSWM_ECUM_ENABLED)
#include "EcuM.h"
#endif

#if(STD_ON == BSWM_LINTP_ENABLED)
#include "LinTp.h"
#endif

#if(STD_ON == BSWM_DEV_ERROR_DETECT)
#include "Det.h"
#endif

#if(STD_ON == BSWM_DCM_ENABLED)
#include "Dcm.h"
#endif

#if(STD_ON == BSWM_SD_ENABLED)
#include "Sd.h"
#endif

#if(STD_ON == BSWM_NM_ENABLED)
#include "Nm.h"
#endif

#if(STD_ON == BSWM_WDGM_ENABLED)
#include "WdgM.h"
#endif

/*******************************************************************************
*   Version Check
*******************************************************************************/
#if(STD_ON == BSWM_VERSION_CHECK)
/* check Version with other import module */



/* check Version with cfg file */
#if((BSWM_CONFIG_VARIANTS != STD_CONFIG_VARIANTS_PRECOMPILE) && \
    (BSWM_CONFIG_VARIANTS != STD_CONFIG_VARIANTS_LINKTIME))
#error "The BswM module only supports Pre-Compile and Link-Time Configuration."
#endif

#if((BSWM_AR_RELEASE_MAJOR_VERSION != BSWM_AR_RELEASE_MAJOR_VERSION_CFG) || \
   (BSWM_AR_RELEASE_MINOR_VERSION != BSWM_AR_RELEASE_MINOR_VERSION_CFG))
#error "AutoSar Version Numbers of BswM and its cfg file are incompatible"
#endif

#if((BSWM_SW_MAJOR_VERSION != BSWM_SW_MAJOR_VERSION_CFG) || \
   (BSWM_SW_MINOR_VERSION != BSWM_SW_MINOR_VERSION_CFG))
#error "SW Version Numbers of BswM and its cfg file are incompatible"
#endif


#endif/*#if(STD_ON == BSWM_VERSION_CHECK)*/



/*******************************************************************************
*   Macro
*******************************************************************************/
#if(STD_ON == BSWM_DEV_ERROR_DETECT)

#define  BSWM_DET_REPORT_ERROR(ApiId, errcode)  \
    DET_REPORT_ERROR(BSWM_MODULE_ID, BSWM_INSTANCE_ID, (ApiId), (errcode))

#else

#define  BSWM_DET_REPORT_ERROR(ApiId, errcode)

#endif


#define BSWM_RULE_IS_DEFERRED(RuleId)      (TRUE == BswM_RuleDeferredFlag[RuleId])
#define BSWM_RULE_SET_DEFERRED(RuleId)     (BswM_RuleDeferredFlag[RuleId] = TRUE)
#define BSWM_RULE_SET_UNDEFERRED(RuleId)   (BswM_RuleDeferredFlag[RuleId] = FALSE)

#define BSWM_IS_LOCKED()      (TRUE == BswM_ArbitrateLock)
#define BSWM_LOCK()           (BswM_ArbitrateLock = TRUE)
#define BSWM_UNLOCK()         (BswM_ArbitrateLock = FALSE)

/*******************************************************************************
*   Local Data Define
*******************************************************************************/
#define BSWM_START_SEC_VAR_INIT_8
#include "MemMap.h"

STATIC VAR(Std_InitStateType, BSWM_VAR)  BswM_InitStatus = STD_UNINITIALIZED;

#define BSWM_STOP_SEC_VAR_INIT_8
#include "MemMap.h"

#define BSWM_START_SEC_VAR_NOINIT_8
#include "MemMap.h"

STATIC VAR(boolean, BSWM_VAR) BswM_ArbitrateLock;
STATIC VAR(boolean, BSWM_VAR) BswM_RuleDeferredFlag[BSWM_MAX_RULE_NUM];
STATIC VAR(BswMRuleStateType, BSWM_VAR) BswMRuleState[BSWM_MAX_RULE_NUM];
STATIC VAR(uint8, BSWM_VAR) BswMRuleDeferredCnt;
#if(STD_ON == BSWM_TIMER_ENABLED)
STATIC VAR(uint8, BSWM_VAR) BswM_Timer;
#endif

#define BSWM_STOP_SEC_VAR_NOINIT_8
#include "MemMap.h"


#define BSWM_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h"

#if(BSWM_CONFIG_VARIANTS == STD_CONFIG_VARIANTS_POSTBUILD)
STATIC P2CONST(BswM_ConfigType, AUTOMATIC, BSWM_VAR_NOINIT) BswM_ConfigSet;
#endif

#define BSWM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h"


/*******************************************************************************
*   Private Functions
*******************************************************************************/
#define BSWM_START_SEC_CODE
#include "MemMap.h"
STATIC FUNC(void, BSWM_CODE) BswM_ImmediateRunRule
(
    BswMRuleType RuleIndex
);

STATIC FUNC(Std_ReturnType, BSWM_CODE) BswM_RunActionList
(
    BswMActionListIdType ActionListId
);

STATIC FUNC(void, BSWM_CODE) BswM_DeferRule
(
    BswMRuleType RuleIndex
);

STATIC FUNC(BswMRuleStateType, BSWM_CODE) BswM_ArbitrateRule
(
    BswMRuleType RuleIndex
);

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: BswM_RunActionList
*
* Description:   Immediate run an ActionList
*
* Inputs:        ActionListId
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(Std_ReturnType, BSWM_CODE) BswM_RunActionList
(
    BswMActionListIdType ActionListId
)
{
    Std_ReturnType ret = E_OK;
    P2CONST(BswM_ActionListItemType, AUTOMATIC, BSWM_CONST) ActionItem;

    if((BswMActionListIdType)BSWM_ACTIONLIST_NULL == ActionListId)
    {
        ret = E_OK;
    }
    else
    {
        ActionItem = BswMAvailableActionLists[ActionListId].ActionListHead;

        while(NULL_PTR != ActionItem)
        {
            switch(ActionItem->ActionType)
            {
            case BSWM_ACTION:
                if(NULL_PTR != ActionItem->ActionFunc)
                {
                    ret = ActionItem->ActionFunc();
                }
                break;

            case BSWM_ACTIONLIST:
                /* MISRA RULE 16.2 violated:
                The indirect recurisive call is necessary to process the cascaded action lists,
                and this recurisive call will return eventually.*/
                ret = BswM_RunActionList(ActionItem->ActionListId);
                break;

            case BSWM_RULE:
                /*SWS_BswM_00062*/
                /*locked now, run later*/
                if(BSWM_RULE_NULL != ActionItem->RuleId)
                {
                    BswM_ImmediateRunRule(ActionItem->RuleId);
                }
                ret = E_OK;
                break;

            default:
                ret = E_NOT_OK;
                break;
            }

            if(E_NOT_OK == ret)
            {
#if(STD_ON == BSWM_DEM_ENABLED)
                Dem_ReportErrorStatus(ActionItem->EventId, ActionItem->EventStatus);
#endif
#if(STD_ON == BSWM_ABORTONFAIL_ENABLED)
                if(ActionItem->AbortOnFail)
                {
                    break;
                }
#endif
            }

            ActionItem = ActionItem->next;

        }
    }

    return ret;
}


/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: BswM_ImmediateRunRule
*
* Description:   Immediate run a rule
*
* Inputs:        RuleIndex
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, BSWM_CODE) BswM_ImmediateRunRule
(
    BswMRuleType RuleIndex
)
{
    BswMRuleStateType RuleNewState;
    BswMRuleStateType RuleOldState = BswMRuleState[RuleIndex];
    RuleNewState = BswMAvailableRules[RuleIndex].RuleFunc();

    if(BSWM_TRUE == RuleNewState)
    {
        BswMRuleState[RuleIndex] = BSWM_TRUE;

        if((BswMActionListIdType)BSWM_ACTIONLIST_NULL == BswMAvailableRules[RuleIndex].RuleTrueActionList)
        {
            /*NULL ACTIONLIST do not need to process*/
        }
        else if(BswMAvailableActionLists[BswMAvailableRules[RuleIndex].RuleTrueActionList].Excution == BSWM_CONDITION)
        {
            /* Run True Action List */
            (void)BswM_RunActionList(BswMAvailableRules[RuleIndex].RuleTrueActionList);
        }
        else  /* True Action List is TRIGGER */
        {
            if(BSWM_TRUE != RuleOldState)
            {
                (void)BswM_RunActionList(BswMAvailableRules[RuleIndex].RuleTrueActionList);
            }
        }
    }
    else if(BSWM_FALSE == RuleNewState)
    {
        BswMRuleState[RuleIndex] = BSWM_FALSE;

        if((BswMActionListIdType)BSWM_ACTIONLIST_NULL == BswMAvailableRules[RuleIndex].RuleFalseActionList)
        {
            /*NULL ACTIONLIST do not need to process*/
        }
        else if(BswMAvailableActionLists[BswMAvailableRules[RuleIndex].RuleFalseActionList].Excution == BSWM_CONDITION)
        {
            /* Run False Action List */
            (void)BswM_RunActionList(BswMAvailableRules[RuleIndex].RuleFalseActionList);
        }
        else  /* False Action List is TRIGGER */
        {
            if(BSWM_FALSE != RuleOldState)
            {
                (void)BswM_RunActionList(BswMAvailableRules[RuleIndex].RuleFalseActionList);
            }
        }
    }
    else
    {
        BswMRuleState[RuleIndex] = BSWM_UNDEFINED;
        /*BSWM_UNDEFINED do not need to process*/
    }

    return;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: BswM_DeferRule
*
* Description:   Label a rule as deferred
*
* Inputs:        RuleIndex
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, BSWM_CODE) BswM_DeferRule
(
    BswMRuleType RuleIndex
)
{
    if(!BSWM_RULE_IS_DEFERRED(RuleIndex) )
    {
        BSWM_RULE_SET_DEFERRED(RuleIndex);
        BswMRuleDeferredCnt++;
    }
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: BswM_ArbitrateRule
*
* Description:   This function arbitrate the required rules either immediately or deferred to
*                main function
*
* Inputs:        RuleIndex  Id of the rule to be arbitrated
*
* Outputs:       BSWM_TRUE when complete
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(BswMRuleStateType, BSWM_CODE) BswM_ArbitrateRule
(
    BswMRuleType RuleIndex
)
{
    if(BswMAvailableRules[RuleIndex].RequestProcessing == BSWM_IMMEDIATE)
    {
        /*SWS_BswM_00069 not a TAS instruction, tbd*/
        if(BSWM_IS_LOCKED())
        {
            BswM_DeferRule(RuleIndex);
        }
        else
        {
            BSWM_LOCK();
            BswM_ImmediateRunRule(RuleIndex);
            BSWM_UNLOCK();
        }
    }
    else
    {
        BswM_DeferRule(RuleIndex);
    }

    return BSWM_TRUE;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: BswM_ArbitratePortMappingRules
*
* Description:   This function arbitrate rules mapping by given port
*
* Inputs:        Port  Id of the Port to be arbitrated
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, BSWM_CODE) BswM_ArbitratePortMappingRules
(
    BswMPortType Port
)
{
    BswMRuleType RuleIndex;
    BswMRuleType StartRuleId;
    BswMRuleType EndRuleId;

    StartRuleId = BswMPortMappingRulesStart[Port];
    EndRuleId = StartRuleId + BswMPortMappingRulesNum[Port];

    for(RuleIndex = StartRuleId; RuleIndex < EndRuleId; RuleIndex++)
    {
        (void)BswM_ArbitrateRule(BswMPortMappingRules[RuleIndex]);
    }
}

/*******************************************************************************
*   Public Functions
*******************************************************************************/

#if(STD_ON == BSWM_VERSION_INFO_API)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: BswM_GetVersionInfo  SWS_BswM_00003
*
* Description:   This service returns the version information of the called
*                BSW Mode Manager module
*
* Inputs:        None
*
* Outputs:       VersionInfo  Pointer to where to store the version information
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, BSWM_CODE) BswM_GetVersionInfo
(
    P2VAR(Std_VersionInfoType, AUTOMATIC, BSWM_APPL_DATA) VersionInfo
)
{
    if(NULL_PTR == VersionInfo)
    {
        BSWM_DET_REPORT_ERROR(BSWM_GETVERSIONINFO_APIID, BSWM_E_PARAM_POINTER);
    }
    else
    {
        VersionInfo->vendorID = BSWM_VENDOR_ID;
        VersionInfo->moduleID = BSWM_MODULE_ID;

        VersionInfo->sw_major_version = (uint8)BSWM_SW_MAJOR_VERSION;
        VersionInfo->sw_minor_version = (uint8)BSWM_SW_MINOR_VERSION;
        VersionInfo->sw_patch_version = (uint8)BSWM_SW_PATCH_VERSION;
    }
}
#endif

#if(STD_ON == BSWM_GENERIC_REQUEST_ENABLED)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: BswM_RequestMode  SWS_BswM_00046
*
* Description:   Generic function call to request modes. This function shall only be used by other
*                BSW module that does not have a specific mode reuqest interface
*
* Inputs:        requesting_user  The user that requests the mode
*                   requested_mode The requested mode
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, BSWM_CODE) BswM_RequestMode
(
    BswM_UserType requesting_user,
    BswM_ModeType requested_mode
)
{
    BswMPortType Port = BSWM_MAP_BSWM_GENERAL_TO_PORT(requesting_user);

    /*SWS_BswM_00077*/
    if(STD_INITIALIZED != BswM_InitStatus)
    {
        BSWM_DET_REPORT_ERROR(BSWM_REQUESTMODE_APIID, BSWM_E_NO_INIT);
    }
    /*SWS_BswM_00089*/
    /*Modes are user-defined, so no range chack can be peformed*/
    /*SWS_BswM_00090*/
    else if(requesting_user >= (BswM_UserType)BSWM_MAX_GENERAL_REQUESTING_USER)
    {
        BSWM_DET_REPORT_ERROR(BSWM_REQUESTMODE_APIID, BSWM_E_REQ_USER_OUT_OF_RANGE);
    }
    else
    {
#if(BSWM_GENERAL_PORT_NUM > 0)
        BswM_GeneralPortMode[requesting_user] = requested_mode;
        BswM_ArbitratePortMappingRules(Port);
#endif
    }
}

#endif

#if(STD_ON == BSWM_COMM_ENABLED)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: BswM_ComM_CurrentMode  SWS_BswM_00047
*
* Description:   Function called by ComM to indicate the current communication mode of a
*                  ComM channel.
*
* Inputs:        NetworkHandleType  The ComM communication channel that the indicated state corresponds to.
*                   RequestedMode The current state of the ComM communication channel
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, BSWM_CODE) BswM_ComM_CurrentMode
(
    NetworkHandleType Network,
    ComM_ModeType RequestedMode
)
{
    BswMPortType Port = BSWM_MAP_COMM_TO_PORT(Network);

    /*SWS_BswM_00078*/
    if(STD_INITIALIZED != BswM_InitStatus)
    {
        BSWM_DET_REPORT_ERROR(BSWM_COMM_CURRENTMODE_APIID, BSWM_E_NO_INIT);
    }
    /*SWS_BswM_00091*/
    else if( (COMM_NO_COMMUNICATION != RequestedMode) && (COMM_SILENT_COMMUNICATION != RequestedMode) && \
             (COMM_FULL_COMMUNICATION != RequestedMode) )
    {
        BSWM_DET_REPORT_ERROR(BSWM_COMM_CURRENTMODE_APIID, BSWM_E_REQ_MODE_OUT_OF_RANGE);
    }
    /*SWS_BswM_00090*/
    else if(Network >= (NetworkHandleType)BSWM_COMM_PORT_NUM)
    {
        BSWM_DET_REPORT_ERROR(BSWM_COMM_CURRENTMODE_APIID, BSWM_E_REQ_USER_OUT_OF_RANGE);
    }
    else
    {
#if(BSWM_COMM_PORT_NUM > 0)
        BswM_ComMMode[Network] = RequestedMode;
        BswM_ArbitratePortMappingRules(Port);
#endif
    }
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: BswM_ComM_CurrentPNCMode  SWS_BswM_00148
*
* Description:   Function called by ComM to indicate the current mode of the PNC.
*
* Inputs:        PNC  The handle of the PNC for which the current state is reported.
*                   RequestedMode The current mode of the PNC.
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, BSWM_CODE) BswM_ComM_CurrentPNCMode
(
    PNCHandleType PNC,
    ComM_PncModeType RequestedMode
)
{
#if(BSWM_COMM_PNC_PORT_NUM > 0)
    BswMPortType Port = BSWM_MAP_COMM_PNC_TO_PORT(PNC);
#endif

    /*SWS_BswM_00149*/
    if(STD_INITIALIZED != BswM_InitStatus)
    {
        BSWM_DET_REPORT_ERROR(BSWM_COMM_CURRENTPNCMODE_APIID, BSWM_E_NO_INIT);
    }
    /*SWS_BswM_00150*/
    else if( (RequestedMode != COMM_PNC_REQUESTED)
             && (RequestedMode != COMM_PNC_READY_SLEEP)
             && (RequestedMode != COMM_PNC_PREPARE_SLEEP)
             && (RequestedMode != COMM_PNC_NO_COMMUNICATION) )
    {
        BSWM_DET_REPORT_ERROR(BSWM_COMM_CURRENTPNCMODE_APIID, BSWM_E_REQ_MODE_OUT_OF_RANGE);
    }
#if(BSWM_COMM_PNC_PORT_NUM > 0)
    else if(PNC >= (PNCHandleType)BSWM_COMM_PNC_PORT_NUM)
    {
        BSWM_DET_REPORT_ERROR(BSWM_COMM_CURRENTPNCMODE_APIID, BSWM_E_REQ_USER_OUT_OF_RANGE);
    }
#endif
    else
    {
#if(BSWM_COMM_PNC_PORT_NUM > 0)
        BswM_ComMPNCMode[PNC] = RequestedMode;
        BswM_ArbitratePortMappingRules(Port);
#endif
    }
}

#if(STD_ON == BSWM_COMM_RESET_ENABLED)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: BswM_ComM_InitiateReset  SWS_BswM_00217
*
* Description:   Function called by ComM to signal a shutdown.
*
* Inputs:        None
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, BSWM_CODE) BswM_ComM_InitiateReset
(
    void
)
{
    BswMPortType Port = BSWM_MAP_COMM_RESET_TO_PORT();

    if(STD_INITIALIZED != BswM_InitStatus)
    {
        BSWM_DET_REPORT_ERROR(BSWM_COMM_INITIATERESET_APIID, BSWM_E_NO_INIT);
    }
    else
    {
#if(BSWM_COMM_RESET_PORT_NUM > 0)
        BswM_ComMInitiateReset = TRUE;
        BswM_ArbitratePortMappingRules(Port);
#endif
    }
}
#endif

#endif

#if(STD_ON == BSWM_SD_ENABLED)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: BswM_Sd_ClientServiceCurrentState  SWS_BswM_00204
*
* Description:   Function called by Service Discovery to indicate current state of the Client Service
*                (available/down).
*
* Inputs:        SdClientServiceHandleId HandleId to identify the ClientService
*                CurrentClientState Current state of the ClientService
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, BSWM_CODE) BswM_Sd_ClientServiceCurrentState
(
    uint16 SdClientServiceHandleId,
    Sd_ClientServiceCurrentStateType CurrentClientState
)
{
    BswMPortType Port = BSWM_MAP_SD_CS_TO_PORT(SdClientServiceHandleId);

    /*SWS_BswM_00205*/
    if(STD_INITIALIZED != BswM_InitStatus)
    {
        BSWM_DET_REPORT_ERROR(BSWM_SD_CLENTSERVICECURRENTSTATE_APIID, BSWM_E_NO_INIT);
    }
    /*SWS_BswM_00090*/
    else if(SdClientServiceHandleId >= (uint16)BSWM_MAX_SD_CS_USER)
    {
        BSWM_DET_REPORT_ERROR(BSWM_SD_CLENTSERVICECURRENTSTATE_APIID, BSWM_E_REQ_USER_OUT_OF_RANGE);
    }
    else
    {
#if(BSWM_SD_CS_PORT_NUM > 0)
        BswM_SdCSState[SdClientServiceHandleId] = CurrentClientState;
        BswM_ArbitratePortMappingRules(Port);
#endif
    }
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: BswM_Sd_ConsumedEventGroupCurrentState  SWS_BswM_00207
*
* Description:   Function called by Service Discovery to indicate current status of the Consumed
*                Eventgroup (available/down).
*
* Inputs:        SdConsumedEventGroupHandleId HandleId to identify the Consumed Eventgroup
*                ConsumedEventGroupState Status of the Consumed Eventgroup
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, BSWM_CODE) BswM_Sd_ConsumedEventGroupCurrentState
(
    uint16 SdConsumedEventGroupHandleId,
    Sd_ConsumedEventGroupCurrentStateType ConsumedEventGroupState
)
{
    BswMPortType Port = BSWM_MAP_SD_EVENTGROUP_TO_PORT(SdConsumedEventGroupHandleId);

    /*SWS_BswM_00208*/
    if(STD_INITIALIZED != BswM_InitStatus)
    {
        BSWM_DET_REPORT_ERROR(BSWM_SD_CONSUMEDEVENTGROUPCURRENTSTATE_APIID, BSWM_E_NO_INIT);
    }
    else if(SdConsumedEventGroupHandleId >= (uint16)BSWM_MAX_SD_EVENTGROUP_ID)
    {
        BSWM_DET_REPORT_ERROR(BSWM_SD_CONSUMEDEVENTGROUPCURRENTSTATE_APIID, BSWM_E_REQ_USER_OUT_OF_RANGE);
    }
    else
    {
#if(BSWM_SD_EVENTGROUP_PORT_NUM > 0)
        BswM_SdEventGroupState[SdConsumedEventGroupHandleId] = ConsumedEventGroupState;
        BswM_ArbitratePortMappingRules(Port);
#endif
    }
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: BswM_Sd_EventHandlerCurrentState  SWS_BswM_00210
*
* Description:   Function called by Service Discovery to indicate current status of the
*                EventHandler (requested/released).
*
* Inputs:        SdEventHandlerHandleId HandleId to identify the EventHandler
*                EventHandlerStatus Status of the EventHandler
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, BSWM_CODE) BswM_Sd_EventHandlerCurrentState
(
    uint16 SdEventHandlerHandleId,
    Sd_EventHandlerCurrentStateType EventHandlerStatus
)
{
    BswMPortType Port = BSWM_MAP_SD_EVENTHANDLER_TO_PORT(SdEventHandlerHandleId);

    /*SWS_BswM_00211*/
    if(STD_INITIALIZED != BswM_InitStatus)
    {
        BSWM_DET_REPORT_ERROR(BSWM_SD_EVENTHANDLERCURRENTSTATE_APIID, BSWM_E_NO_INIT);
    }
    else if(SdEventHandlerHandleId >= (uint16)BSWM_MAX_SD_EVENTHANDLER_USER)
    {
        BSWM_DET_REPORT_ERROR(BSWM_SD_EVENTHANDLERCURRENTSTATE_APIID, BSWM_E_REQ_USER_OUT_OF_RANGE);
    }
    else
    {
#if(BSWM_SD_EVENTHANDLER_PORT_NUM > 0)
        BswM_SdEventHandlerState[SdEventHandlerHandleId] = EventHandlerStatus;
        BswM_ArbitratePortMappingRules(Port);
#endif
    }
}


#endif


#if(STD_ON == BSWM_DCM_ENABLED)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: BswM_Dcm_ApplicationUpdated  SWS_BswM_00158
*
* Description:   This function is called by the DCM in order to report an updated application.
*
* Inputs:        None
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, BSWM_CODE) BswM_Dcm_ApplicationUpdated
(
    void
)
{
#if(BSWM_DCM_APP_UPDATE_PORT_NUM > 0)
    BswMPortType Port = BSWM_MAP_DCM_APP_UPDATE_TO_PORT();
#endif

    /*SWS_BswM_00159*/
    if(STD_INITIALIZED != BswM_InitStatus)
    {
        BSWM_DET_REPORT_ERROR(BSWM_DCM_APPLICATIONUPDATED_APIID, BSWM_E_NO_INIT);
    }
    else
    {
#if(BSWM_DCM_APP_UPDATE_PORT_NUM > 0)
        BswM_DcmAppUpdated = TRUE;
        BswM_ArbitratePortMappingRules(Port);
#endif
    }

}


/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: BswM_Dcm_CommunicationMode_CurrentState  SWS_BswM_00048
*
* Description:   Function called by DCM to inform the BswM about the current state of the
*                   communication mode.
*
* Inputs:        Network  The communication channel that the diagnostic mode corresponds to.
*                   RequestedMode The requested diagnostic communication mode.
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, BSWM_CODE) BswM_Dcm_CommunicationMode_CurrentState
(
    NetworkHandleType Network,
    Dcm_CommunicationModeType RequestedMode
)
{
#if(BSWM_DCM_PORT_NUM > 0)
    BswMPortType Port = BSWM_MAP_DCM_TO_PORT(Network);
#endif

    /*SWS_BswM_00079*/
    if(STD_INITIALIZED != BswM_InitStatus)
    {
        BSWM_DET_REPORT_ERROR(BSWM_DCM_COMMUNICATIONMODE_CURRENTSTATE_APIID, BSWM_E_NO_INIT);
    }
    /*SWS_BswM_00093*/
    else if( (RequestedMode != DCM_ENABLE_RX_TX_NORM)
             && (RequestedMode != DCM_ENABLE_RX_DISABLE_TX_NORM)
             && (RequestedMode != DCM_DISABLE_RX_ENABLE_TX_NORM)
             && (RequestedMode != DCM_DISABLE_RX_TX_NORMAL)
             && (RequestedMode != DCM_ENABLE_RX_TX_NM)
             && (RequestedMode != DCM_ENABLE_RX_DISABLE_TX_NM)
             && (RequestedMode != DCM_DISABLE_RX_ENABLE_TX_NM)
             && (RequestedMode != DCM_DISABLE_RX_TX_NM)
             && (RequestedMode != DCM_ENABLE_RX_TX_NORM_NM)
             && (RequestedMode != DCM_ENABLE_RX_DISABLE_TX_NORM_NM)
             && (RequestedMode != DCM_DISABLE_RX_ENABLE_TX_NORM_NM)
             && (RequestedMode != DCM_DISABLE_RX_TX_NORM_NM) )
    {
        BSWM_DET_REPORT_ERROR(BSWM_DCM_COMMUNICATIONMODE_CURRENTSTATE_APIID, BSWM_E_REQ_MODE_OUT_OF_RANGE);
    }
#if(BSWM_MAX_DCM_COMMUNICATION_REQUESTING_NETWORK > 0)
    else if(Network >= (NetworkHandleType)BSWM_MAX_DCM_COMMUNICATION_REQUESTING_NETWORK)
    {
        BSWM_DET_REPORT_ERROR(BSWM_DCM_COMMUNICATIONMODE_CURRENTSTATE_APIID, BSWM_E_REQ_USER_OUT_OF_RANGE);
    }
#endif
    else
    {
#if(BSWM_DCM_PORT_NUM > 0)
        BswM_DcmComMMode[Network] = RequestedMode;
        BswM_ArbitratePortMappingRules(Port);
#endif
    }

}

#endif


#if(STD_ON == BSWM_CANSM_ICOM_ENABLED)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: BswM_CanSM_CurrentIcomConfiguration  SWS_BswM_00164
*
* Description:   Function to inform BswM about the switch of Icom Configuration.
*
* Inputs:       ActiveConfiguration The configuration Id of the Icom configuration
*               Error ICOM_SWITCH_E_OK: No Error
*                     ICOM_SWITCH_E_FAILED: Switch to requestedConfiguration failed. Severe Error.
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, BSWM_CODE) BswM_CanSM_CurrentIcomConfiguration
(
    NetworkHandleType Network,
    IcomConfigIdType ActiveConfiguration,
    IcomSwitch_ErrorType Error
)
{
    BswMPortType Port = BSWM_MAP_CANSM_ICOM_TO_PORT(Network);

    /*SWS_BswM_00080*/
    if(STD_INITIALIZED != BswM_InitStatus)
    {
        BSWM_DET_REPORT_ERROR(BSWM_CANSM_CURRENTICOMCONF_APIID, BSWM_E_NO_INIT);
    }
    else if(Network >= (NetworkHandleType)BSWM_CANSM_PORT_NUM)
    {
        BSWM_DET_REPORT_ERROR(BSWM_CANSM_CURRENTICOMCONF_APIID, BSWM_E_REQ_USER_OUT_OF_RANGE);
    }
    else
    {
#if(BSWM_CANSM_ICOM_PORT_NUM > 0)
        BswM_CanSMIcom[Network] = ActiveConfiguration;
        BswM_ArbitratePortMappingRules(Port);
#endif
    }
}
#endif

#if(STD_ON == BSWM_CANSM_ENABLED)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: BswM_CanSM_CurrentState  SWS_BswM_00049
*
* Description:   Function called by CanSM to indicate its current state.
*
* Inputs:        Network  The CAN channel that the indicated state corresponds to.
*                   CurrentState The current state of the CAN channel.
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, BSWM_CODE) BswM_CanSM_CurrentState
(
    NetworkHandleType Network,
    CanSM_BswMCurrentStateType CurrentState
)
{
    BswMPortType Port = BSWM_MAP_CANSM_TO_PORT(Network);

    /*SWS_BswM_00080*/
    if(STD_INITIALIZED != BswM_InitStatus)
    {
        BSWM_DET_REPORT_ERROR(BSWM_CANSM_CURRENTSTATE_APIID, BSWM_E_NO_INIT);
    }
    /*SWS_BswM_00095*/
    else if((CurrentState != CANSM_BSWM_NO_COMMUNICATION)
            && (CurrentState != CANSM_BSWM_SILENT_COMMUNICATION)
            && (CurrentState != CANSM_BSWM_FULL_COMMUNICATION)
            && (CurrentState != CANSM_BSWM_BUS_OFF)
            && (CurrentState != CANSM_BSWM_CHANGE_BAUDRATE))
    {
        BSWM_DET_REPORT_ERROR(BSWM_CANSM_CURRENTSTATE_APIID, BSWM_E_REQ_MODE_OUT_OF_RANGE);
    }
    else if(Network >= (NetworkHandleType)BSWM_CANSM_PORT_NUM)
    {
        BSWM_DET_REPORT_ERROR(BSWM_CANSM_CURRENTSTATE_APIID, BSWM_E_REQ_USER_OUT_OF_RANGE);
    }
    else
    {
#if(BSWM_CANSM_PORT_NUM > 0)
        BswM_CanSMMode[Network] = CurrentState;
        BswM_ArbitratePortMappingRules(Port);
#endif
    }
}

#endif

#if(STD_ON == BSWM_ETHSM_ENABLED)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: BswM_EthSM_CurrentState  SWS_BswM_00050
*
* Description:   Function called by EthSM to indicate its current state.
*
* Inputs:        Network  The Ethernet channel that the indicated state corresponds to.
*                   CurrentState The current state of the Ethernet channel.
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, BSWM_CODE) BswM_EthSM_CurrentState
(
    NetworkHandleType Network,
    EthSM_NetworkModeStateType CurrentState
)
{
    BswMPortType Port = BSWM_MAP_ETHSM_TO_PORT(Network);

    /*SWS_BswM_00081*/
    if(STD_INITIALIZED != BswM_InitStatus)
    {
        BSWM_DET_REPORT_ERROR(BSWM_ETHSM_CURRENTSTATE_APIID, BSWM_E_NO_INIT);
    }
    /*SWS_BswM_00097*/
    else if((CurrentState != ETHSM_STATE_OFFLINE)
            && (CurrentState != ETHSM_STATE_WAIT_TRCVLINK)
            && (CurrentState != ETHSM_STATE_WAIT_ONLINE)
            && (CurrentState != ETHSM_STATE_ONLINE)
            && (CurrentState != ETHSM_STATE_ONHOLD)
            && (CurrentState != ETHSM_STATE_WAIT_OFFLINE))
    {
        BSWM_DET_REPORT_ERROR(BSWM_ETHSM_CURRENTSTATE_APIID, BSWM_E_REQ_MODE_OUT_OF_RANGE);
    }
    else if(Network >= (NetworkHandleType)BSWM_MAX_ETHSM_REQUESTING_USER)
    {
        BSWM_DET_REPORT_ERROR(BSWM_ETHSM_CURRENTSTATE_APIID, BSWM_E_REQ_USER_OUT_OF_RANGE);
    }
    else
    {
#if(BSWM_ETHSM_PORT_NUM > 0)
        BswM_EthSMMode[Network] = CurrentState;
        BswM_ArbitratePortMappingRules(Port);
#endif
    }

}
#endif

#if(STD_ON == BSWM_FRSM_ENABLED)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: BswM_FrSM_CurrentState  SWS_BswM_00051
*
* Description:   Function called by FrSM to indicate its current state.
*
* Inputs:        Network  The FlexRay cluster that the indicated state corresponds to.
*                   CurrentState The current state of the FlexRay cluster.
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, BSWM_CODE) BswM_FrSM_CurrentState
(
    NetworkHandleType Network,
    FrSM_BswM_StateType CurrentState
)
{
    BswMPortType Port = BSWM_MAP_FRSM_TO_PORT(Network);

    /*SWS_BswM_00082*/
    if(STD_INITIALIZED != BswM_InitStatus)
    {
        BSWM_DET_REPORT_ERROR(BSWM_FRSM_CURRENTSTATE_APIID, BSWM_E_NO_INIT);
    }
    /*SWS_BswM_00099*/
    else if( (CurrentState != FRSM_BSWM_READY)
             && (CurrentState != FRSM_BSWM_READY_ECU_PASSIVE)
             && (CurrentState != FRSM_BSWM_STARTUP)
             && (CurrentState != FRSM_BSWM_STARTUP_ECU_PASSIVE)
             && (CurrentState != FRSM_BSWM_WAKEUP)
             && (CurrentState != FRSM_BSWM_WAKEUP_ECU_PASSIVE)
             && (CurrentState != FRSM_BSWM_HALT_REQ)
             && (CurrentState != FRSM_BSWM_HALT_REQ_ECU_PASSIVE)
             && (CurrentState != FRSM_BSWM_KEYSLOT_ONLY)
             && (CurrentState != FRSM_BSWM_KEYSLOT_ONLY_ECU_PASSIVE)
             && (CurrentState != FRSM_BSWM_ONLINE)
             && (CurrentState != FRSM_BSWM_ONLINE_ECU_PASSIVE)
             && (CurrentState != FRSM_BSWM_ONLINE_PASSIVE)
             && (CurrentState != FRSM_BSWM_ONLINE_PASSIVE_ECU_PASSIVE)
             && (CurrentState != FRSM_LOW_NUMBER_OF_COLDSTARTERS)
             && (CurrentState != FRSM_LOW_NUMBER_OF_COLDSTARTERS_ECU_PASSIVE) )
    {
        BSWM_DET_REPORT_ERROR(BSWM_FRSM_CURRENTSTATE_APIID, BSWM_E_REQ_MODE_OUT_OF_RANGE);
    }
    else if(Network >= (NetworkHandleType)BSWM_MAX_FRSM_REQUESTING_USER)
    {
        BSWM_DET_REPORT_ERROR(BSWM_FRSM_CURRENTSTATE_APIID, BSWM_E_REQ_USER_OUT_OF_RANGE);
    }
    else
    {
#if(BSWM_FRSM_PORT_NUM > 0)
        BswM_FrSMMode[Network] = CurrentState;
        BswM_ArbitratePortMappingRules(Port);
#endif
    }

}
#endif

#if(STD_ON == BSWM_LINSM_ENABLED)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: BswM_LinSM_CurrentState  SWS_BswM_00052
*
* Description:   Function called by LinSM to indicate its current state.
*
* Inputs:        Network  The LIN channel that the indicated state corresponds to.
*                CurrentState The current state of the LIN channel.
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, BSWM_CODE) BswM_LinSM_CurrentState
(
    NetworkHandleType Network,
    LinSM_ModeType CurrentState
)
{
    BswMPortType Port = BSWM_MAP_LINSM_TO_PORT(Network);

    /*SWS_BswM_00083*/
    if(STD_INITIALIZED != BswM_InitStatus)
    {
        BSWM_DET_REPORT_ERROR(BSWM_LINSM_CURRENTSTATE_APIID, BSWM_E_NO_INIT);
    }
    /*SWS_BswM_00101*/
    else if( (CurrentState != LINSM_FULL_COM)
             && (CurrentState != LINSM_NO_COM) )
    {
        BSWM_DET_REPORT_ERROR(BSWM_LINSM_CURRENTSTATE_APIID, BSWM_E_REQ_MODE_OUT_OF_RANGE);
    }
    else if(Network >= (NetworkHandleType)BSWM_MAX_LINSM_REQUESTING_USER)
    {
        BSWM_DET_REPORT_ERROR(BSWM_LINSM_CURRENTSTATE_APIID, BSWM_E_REQ_USER_OUT_OF_RANGE);
    }
    else
    {
#if(BSWM_LINSM_PORT_NUM > 0)
        BswM_LinSMMode[Network] = CurrentState;
        BswM_ArbitratePortMappingRules(Port);
#endif
    }

}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: BswM_LinSM_CurrentSchedule  SWS_BswM_00058
*
* Description:   Function called by LinSM to indicate the currently active schedule table for a
*                   specific LIN channel.
*
* Inputs:        Network  The LIN channel that the schedule table switch have occurred on.l
*                   CurrentSchedule The currently active schedule table of the LIN channel
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, BSWM_CODE) BswM_LinSM_CurrentSchedule
(
    NetworkHandleType Network,
    LinIf_SchHandleType CurrentSchedule
)
{
#if(BSWM_LINSM_SCH_PORT_NUM > 0)
    BswMPortType Port = BSWM_MAP_LINSM_SCH_TO_PORT(Network);
#endif

    /*SWS_BswM_00086*/
    if(STD_INITIALIZED != BswM_InitStatus)
    {
        BSWM_DET_REPORT_ERROR(BSWM_LINSM_CURRENTSCHEDULE_APIID, BSWM_E_NO_INIT);
    }
    else if(CurrentSchedule >= (LinIf_SchHandleType)BSWM_MAX_LINSM_REQUESTED_SCHEDULE)
    {
        BSWM_DET_REPORT_ERROR(BSWM_LINSM_CURRENTSCHEDULE_APIID, BSWM_E_REQ_MODE_OUT_OF_RANGE);
    }
    else if(Network >= (NetworkHandleType)BSWM_MAX_LINSM_REQUESTING_USER)
    {
        BSWM_DET_REPORT_ERROR(BSWM_LINSM_CURRENTSCHEDULE_APIID, BSWM_E_REQ_USER_OUT_OF_RANGE);
    }
    else
    {
#if(BSWM_LINSM_SCH_PORT_NUM > 0)
        BswM_LinSMSch[Network] = CurrentSchedule;
        BswM_ArbitratePortMappingRules(Port);
#endif
    }

}

#endif

#if(STD_ON == BSWM_ECUM_ENABLED)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: BswM_EcuM_CurrentState  SWS_BswM_00056
*
* Description:   Function called by EcuM to indicate the currentECU Operation Mode.
*
* Inputs:        CurrentState The requested ECU Operation Mode
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, BSWM_CODE) BswM_EcuM_CurrentState
(
    EcuM_StateType CurrentState
)
{
    /*SWS_BswM_00084*/
    if(STD_INITIALIZED != BswM_InitStatus)
    {
        BSWM_DET_REPORT_ERROR(BSWM_ECUM_CURRENTSTATE_APIID, BSWM_E_NO_INIT);
    }
    /*SWS_BswM_00103*/
    else if( (CurrentState != ECUM_STATE_APP_RUN)
             && (CurrentState != ECUM_STATE_APP_POST_RUN)
             && (CurrentState != ECUM_STATE_SLEEP)
             && (CurrentState != ECUM_STATE_SHUTDOWN)
             && (CurrentState != ECUM_STATE_PREP_SHUTDOWN)
             && (CurrentState != ECUM_STATE_STARTUP)
             && (CurrentState != ECUM_STATE_STARTUP_ONE)
             && (CurrentState != ECUM_STATE_STARTUP_TWO)
             && (CurrentState != ECUM_STATE_WAKEUP)
             && (CurrentState != ECUM_STATE_RUN)
             && (CurrentState != ECUM_STATE_WAKEUP_ONE)
             && (CurrentState != ECUM_STATE_WAKEUP_VALIDATION)
             && (CurrentState != ECUM_STATE_WAKEUP_REACTION)
             && (CurrentState != ECUM_STATE_WAKEUP_TWO)
             && (CurrentState != ECUM_STATE_WAKEUP_WAKESLEEP)
             && (CurrentState != ECUM_STATE_WAKEUP_TTII)
             && (CurrentState != ECUM_STATE_GO_SLEEP)
             && (CurrentState != ECUM_STATE_GO_OFF_ONE)
             && (CurrentState != ECUM_STATE_GO_OFF_TWO)
             && (CurrentState != ECUM_STATE_RESET)
             && (CurrentState != ECUM_STATE_OFF) )
    {
        BSWM_DET_REPORT_ERROR(BSWM_ECUM_CURRENTSTATE_APIID, BSWM_E_REQ_MODE_OUT_OF_RANGE);
    }
    else
    {
        /*Not supported now*/
        /*BswM_EcuMState = CurrentState;
        BswM_ArbitratePortMappingRules(Port);*/
    }

}

#if(STD_ON == BSWM_ECUM_WKUPSRC_ENABLED)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: BswM_EcuM_CurrentWakeup  SWS_BswM_00131
*
* Description:   Function called by EcuM to indicate the current state of a wakeup source
*
* Inputs:        source  Wakeup source(s) that changed state
*                   state The new state of the wakeup source(s)
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, BSWM_CODE) BswM_EcuM_CurrentWakeup
(
    EcuM_WakeupSourceType source,
    EcuM_WakeupStatusType state
)
{
    BswMPortType Port;
    uint8 src;

    /*SWS_BswM_00132*/
    if(STD_INITIALIZED != BswM_InitStatus)
    {
        BSWM_DET_REPORT_ERROR(BSWM_ECUM_CURRENTWAKEUP_APIID, BSWM_E_NO_INIT);
    }
    /*SWS_BswM_00133*/
    else if(state >= (EcuM_WakeupStatusType)ECUM_WKSTATUS_MAX)
    {
        BSWM_DET_REPORT_ERROR(BSWM_ECUM_CURRENTWAKEUP_APIID, BSWM_E_REQ_MODE_OUT_OF_RANGE);
    }
    else
    {
        for(src = (uint8)0; src < (uint8)BSWM_MAX_WKUPSRC_NUM; src++)
        {
            if(ECUM_IS_WAKEUPSOURCE(source, BswM_WkupSrc[src]))
            {
                Port = BSWM_MAP_ECUM_WKUPSRC_TO_PORT(src);
                BswM_EcuMWkupSrcStatus[src] = state;
                BswM_ArbitratePortMappingRules(Port);
            }
        }
    }

    return;
}
#endif

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: BswM_EcuM_RequestedState  SWS_BswM_00226
*
* Description:   Function called by EcuM to notify about current Status of the
*                Run Request Protocol.
*
* Inputs:        State - The requested state by EcuMFlex.
*                CurrentStatus - Result of the Run Request Protocol
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, BSWM_CODE) BswM_EcuM_RequestedState
(
    EcuM_StateType State,
    EcuM_RunStatusType CurrentStatus
)
{
    BswMPortType Port = BSWM_MAP_ECUM_TO_PORT();

    /*SWS_BswM_00227*/
    if(STD_INITIALIZED != BswM_InitStatus)
    {
        BSWM_DET_REPORT_ERROR(BSWM_ECUM_REQUESTEDSTATE_APIID, BSWM_E_NO_INIT);
    }
    /*SWS_BswM_00228*/
    else if( (State != ECUM_STATE_SHUTDOWN)
             && (State != ECUM_STATE_APP_POST_RUN)
             && (State != ECUM_STATE_APP_RUN) )
    {
        BSWM_DET_REPORT_ERROR(BSWM_ECUM_REQUESTEDSTATE_APIID, BSWM_E_REQ_MODE_OUT_OF_RANGE);
    }
    /*SWS_BswM_00229*/
    else if( (CurrentStatus != ECUM_RUNSTATUS_RELEASED)
             && (CurrentStatus != ECUM_RUNSTATUS_REQUESTED) )
    {
        BSWM_DET_REPORT_ERROR(BSWM_ECUM_REQUESTEDSTATE_APIID, BSWM_E_REQ_MODE_OUT_OF_RANGE);
    }
    else
    {
#if(BSWM_ECUM_PORT_NUM > 0)      
        if( (ECUM_STATE_SHUTDOWN == State) && (ECUM_RUNSTATUS_RELEASED == CurrentStatus) )
        {
            /**/
            BswM_EcuMRequestMode = State;
            BswM_ArbitratePortMappingRules(Port);
        }
        else if( (ECUM_STATE_APP_POST_RUN == State) && (ECUM_RUNSTATUS_RELEASED == CurrentStatus) )
        {
            BswM_EcuMRequestMode = State;
            BswM_ArbitratePortMappingRules(Port);
        }
        else if( (ECUM_STATE_APP_RUN == State) && (ECUM_RUNSTATUS_REQUESTED == CurrentStatus) )
        {
            BswM_EcuMRequestMode = State;
            BswM_ArbitratePortMappingRules(Port);
        }
        else
        {
            BSWM_DET_REPORT_ERROR(BSWM_ECUM_REQUESTEDSTATE_APIID, BSWM_E_REQ_MODE_OUT_OF_RANGE);
        }
#endif
    }

    return;
}

#endif

#if(STD_ON == BSWM_J1939DCM_ENABLED)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: BswM_J1939DcmBroadcastStatus  SWS_BswM_00165
*
* Description:   This API tells the BswM the desired communication status of the available
*                networks. The status will typically be activated via COM I-PDU group switches.
*
* Inputs:        NetworkMask Mask containing one bit for each available network.
*                            1: Network enabled 0: Network disabled
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, BSWM_CODE) BswM_J1939DcmBroadcastStatus
(
    uint16 NetworkMask
)
{
    BswMPortType Port = BSWM_MAP_J1939_DCM_TO_PORT();

    if(STD_INITIALIZED != BswM_InitStatus)
    {
        BSWM_DET_REPORT_ERROR(BSWM_J1938DCMBROADCASTSTATUS_APIID, BSWM_E_NO_INIT);
    }
    else
    {
#if(BSWM_J1939DCM_PORT_NUM > 0)
        BswM_J1939DcmBroadcast[NetworkMask] = TRUE;
        BswM_ArbitratePortMappingRules(Port);
#endif
    }
}
#endif

#if(STD_ON == BSWM_J1939NM_ENABLED)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: BswM_J1939Nm_StateChangeNotification  SWS_BswM_00194
*
* Description:   Notification of current J1939Nm state after state changes
*
* Inputs:        Network Identification of the J1939 channel
*                Node Identification of the J1939 node
*                NmState Current (new) state of the J1939 node
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, BSWM_CODE) BswM_J1939Nm_StateChangeNotification
(
    NetworkHandleType Network,
    uint8 Node,
    Nm_StateType NmState
)
{
    BswMPortType Port = BSWM_MAP_J1939NM_TO_PORT(Network);

    if(STD_INITIALIZED != BswM_InitStatus)
    {
        BSWM_DET_REPORT_ERROR(BSWM_J1938NM_STATECHANGENOTIFICATION_APIID, BSWM_E_NO_INIT);
    }
    else if(Network >= (NetworkHandleType)BSWM_J1939NM_PORT_NUM)
    {
        BSWM_DET_REPORT_ERROR(BSWM_J1938NM_STATECHANGENOTIFICATION_APIID, BSWM_E_REQ_USER_OUT_OF_RANGE);
    }
    else if( (NmState != NM_STATE_UNINIT)
             && (NmState != NM_STATE_BUS_SLEEP)
             && (NmState != NM_STATE_PREPARE_BUS_SLEEP)
             && (NmState != NM_STATE_READY_SLEEP)
             && (NmState != NM_STATE_NORMAL_OPERATION)
             && (NmState != NM_STATE_REPEAT_MESSAGE)
             && (NmState != NM_STATE_SYNCHRONIZE)
             && (NmState != NM_STATE_OFFLINE) )
    {
        BSWM_DET_REPORT_ERROR(BSWM_J1938NM_STATECHANGENOTIFICATION_APIID, BSWM_E_REQ_MODE_OUT_OF_RANGE);
    }
    else
    {
#if(BSWM_J1939NM_PORT_NUM > 0)
        BswM_J1939NmState[Network] = NmState;
        BswM_ArbitratePortMappingRules(Port);
#endif
    }
}


#endif

#if(STD_ON == BSWM_NVM_ENABLED)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: BswM_NvM_CurrentBlockMode  SWS_BswM_00104
*
* Description:   Function called by NvM to indicate the current block mode of an NvM block.
*
* Inputs:        Block  The Block that the new NvM Mode corresponds to.
*                   CurrentBlockMode The current block mode of the NvM block.
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, BSWM_CODE) BswM_NvM_CurrentBlockMode
(
    NvM_BlockIdType Block,
    NvM_RequestResultType CurrentBlockMode
)
{
#if(BSWM_NVM_BLOCK_PORT_NUM > 0)
    BswMPortType Port = BSWM_MAP_NVM_BLOCK_TO_PORT(Block);
#endif

    /*SWS_BswM_00109*/
    if(STD_INITIALIZED != BswM_InitStatus)
    {
        BSWM_DET_REPORT_ERROR(BSWM_NVM_CURRENTBLOCKMODE_APIID, BSWM_E_NO_INIT);
    }
    /*SWS_BswM_00110*/
    else if( (CurrentBlockMode != NVM_REQ_OK)
             && (CurrentBlockMode != NVM_REQ_NOT_OK)
             && (CurrentBlockMode != NVM_REQ_PENDING)
             && (CurrentBlockMode != NVM_REQ_INTEGRITY_FAILED)
             && (CurrentBlockMode != NVM_REQ_BLOCK_SKIPPED)
             && (CurrentBlockMode != NVM_REQ_NV_INVALIDATED)
             && (CurrentBlockMode != NVM_REQ_CANCELLED)
             && (CurrentBlockMode != NVM_REQ_VERIFY_FAILED)
             && (CurrentBlockMode != NVM_REQ_WRONGID)
             && (CurrentBlockMode != NVM_REQ_RESTORED_FROM_ROM) )
    {
        BSWM_DET_REPORT_ERROR(BSWM_NVM_CURRENTBLOCKMODE_APIID, BSWM_E_REQ_MODE_OUT_OF_RANGE);
    }
    else if(Block >= (NvM_BlockIdType)BSWM_NVM_BLOCK_PORT_NUM)
    {
        BSWM_DET_REPORT_ERROR(BSWM_NVM_CURRENTBLOCKMODE_APIID, BSWM_E_REQ_USER_OUT_OF_RANGE);
    }
    else
    {
#if(BSWM_NVM_BLOCK_PORT_NUM > 0)
        BswM_NvMBlockMode[Block] = CurrentBlockMode;
        BswM_ArbitratePortMappingRules(Port);
#endif
    }

    return;
}


/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: BswM_NvM_CurrentJobMode  SWS_BswM_00152
*
* Description:   Function called by NvM to inform the BswM about the current state of a multi
*                    block job.
*
* Inputs:        ServiceId  Indicates whether the callback refers to multi block services NvM_ReadAll
*                  or NvM_WriteAll
*                   CurrentJobMode Current state of the multi block job indicated by parameter ServiceId.
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, BSWM_CODE) BswM_NvM_CurrentJobMode
(
    uint8 ServiceId,
    NvM_RequestResultType CurrentJobMode
)
{
#if((STD_ON == BSWM_NVM_READALL_SUPPORT) || (STD_ON == BSWM_NVM_WRITEALL_SUPPORT))
    BswMPortType Port;
#endif

    /*SWS_BswM_00153*/
    if(STD_INITIALIZED != BswM_InitStatus)
    {
        BSWM_DET_REPORT_ERROR(BSWM_NVM_CURRENTJOBMODE_APIID, BSWM_E_NO_INIT);
    }
    /*SWS_BswM_00154*/
    else if( (CurrentJobMode != NVM_REQ_OK)
             && (CurrentJobMode != NVM_REQ_NOT_OK)
             && (CurrentJobMode != NVM_REQ_PENDING)
             && (CurrentJobMode != NVM_REQ_INTEGRITY_FAILED)
             && (CurrentJobMode != NVM_REQ_BLOCK_SKIPPED)
             && (CurrentJobMode != NVM_REQ_NV_INVALIDATED)
             && (CurrentJobMode != NVM_REQ_CANCELLED)
             && (CurrentJobMode != NVM_REQ_VERIFY_FAILED)
             && (CurrentJobMode != NVM_REQ_WRONGID)
             && (CurrentJobMode != NVM_REQ_RESTORED_FROM_ROM) )
    {
        BSWM_DET_REPORT_ERROR(BSWM_NVM_CURRENTJOBMODE_APIID, BSWM_E_REQ_MODE_OUT_OF_RANGE);
    }
    else if( (ServiceId != NVM_READ_ALL) && ( (ServiceId != NVM_WRITE_ALL) ) )
    {
        BSWM_DET_REPORT_ERROR(BSWM_NVM_CURRENTJOBMODE_APIID, BSWM_E_REQ_USER_OUT_OF_RANGE);
    }
    else
    {
#if(STD_ON == BSWM_NVM_READALL_SUPPORT)
        if(ServiceId == NVM_READ_ALL)
        {
            Port = BSWM_MAP_NVM_READ_ALL_JOB_TO_PORT();
            BswM_NvMReadAllStatus = CurrentJobMode;
            BswM_ArbitratePortMappingRules(Port);
        }
#endif
#if(STD_ON == BSWM_NVM_WRITEALL_SUPPORT)
        if(ServiceId == NVM_WRITE_ALL)
        {
            Port = BSWM_MAP_NVM_WRITE_ALL_JOB_TO_PORT();
            BswM_NvMWriteAllStatus = CurrentJobMode;
            BswM_ArbitratePortMappingRules(Port);
        }
#endif
    }
}
#endif

#if(STD_ON == BSWM_LINTP_ENABLED)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: BswM_LinTp_RequestMode  SWS_BswM_00156
*
* Description:   Function called by LinTP to request a mode for the corresponding LIN channel.
*                   The LinTp_Mode mainly correlates to the LIN schedule table that should be used.
*
* Inputs:        Network  The LIN channel that the schedule table switch have occurred on.l
*                   CurrentSchedule The currently active schedule table of the LIN channel
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, BSWM_CODE) BswM_LinTp_RequestMode
(
    NetworkHandleType Network,
    LinTp_Mode LinTpRequestMode
)
{
#if(BSWM_LINTP_PORT_NUM > 0)
    BswMPortType Port = (BswMPortType)BSWM_MAP_LINTP_TO_PORT(Network);
#endif

    /*SWS_BswM_00112*/
    if(STD_INITIALIZED != BswM_InitStatus)
    {
        BSWM_DET_REPORT_ERROR(BSWM_LINTP_REQUESTMODE_APIID, BSWM_E_NO_INIT);
    }
    /*SWS_BswM_00113*/
    else if( (LinTpRequestMode != LINTP_APPLICATIVE_SCHEDULE)
             && (LinTpRequestMode != LINTP_DIAG_REQUEST)
             && (LinTpRequestMode != LINTP_DIAG_RESPONSE) )
    {
        BSWM_DET_REPORT_ERROR(BSWM_LINTP_REQUESTMODE_APIID, BSWM_E_REQ_MODE_OUT_OF_RANGE);
    }
    else if(Network >= (NetworkHandleType)BSWM_MAX_LINSM_REQUESTING_USER)
    {
        BSWM_DET_REPORT_ERROR(BSWM_LINTP_REQUESTMODE_APIID, BSWM_E_REQ_USER_OUT_OF_RANGE);
    }
    else
    {
#if(BSWM_LINTP_PORT_NUM > 0)
        BswM_LinTpMode[Network] = LinTpRequestMode;
        BswM_ArbitratePortMappingRules(Port);
#endif
    }

}
#endif

#if(STD_ON == BSWM_NM_ENABLED)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: BswM_NmIf_CarWakeUpIndication  SWS_BswM_00235
*
* Description:   Function called by NmIf to indicate a CarWakeup
*
* Inputs:        Network  Identification of the Nm-Channel
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, BSWM_CODE) BswM_NmIf_CarWakeUpIndication
(
    NetworkHandleType Network
)
{
#if(BSWM_NM_CAR_WKUP_PORT_NUM > 0)
    BswMPortType Port = BSWM_MAP_NM_CAR_WKUP_TO_PORT(Network);
#endif

    if(STD_INITIALIZED != BswM_InitStatus)
    {
        BSWM_DET_REPORT_ERROR(BSWM_NMIF_CARWAKEUPINDICATION_APIID, BSWM_E_NO_INIT);
    }
#if(BSWM_MAX_NM_CHANNEL > 0)
    else if(Network >= (NetworkHandleType)BSWM_MAX_NM_CHANNEL)
    {
        BSWM_DET_REPORT_ERROR(BSWM_NMIF_CARWAKEUPINDICATION_APIID, BSWM_E_REQ_USER_OUT_OF_RANGE);
    }
#endif
    else
    {
#if(BSWM_NM_CAR_WKUP_PORT_NUM > 0)
        BswM_NmInd[Network] = TRUE;
        BswM_ArbitratePortMappingRules(Port);
#endif
    }

}
#endif


#if(STD_ON == BSWM_WDGM_ENABLED)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: BswM_WdgM_RequestPartitionReset  SWS_BswM_00157
*
* Description:   Function called by WdgM to request a partition reset.
*
* Inputs:        Application The identifier of an OS-Application
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, BSWM_CODE) BswM_WdgM_RequestPartitionReset
(
    ApplicationType Application
)
{
#if(BSWM_WDGM_RESET_PORT_NUM > 0)
    BswMPortType Port = BSWM_MAP_WDGM_RESET_TO_PORT(Application);
#endif

    /*SWS_BswM_00134*/
    if(STD_INITIALIZED != BswM_InitStatus)
    {
        BSWM_DET_REPORT_ERROR(BSWM_WDGM_REQUESTPARTITIONRESET_APIID, BSWM_E_NO_INIT);
    }
#if(BSWM_WDGM_RESET_PORT_NUM > 0)
    else if(Application >= (ApplicationType)BSWM_WDGM_RESET_PORT_NUM)
    {
        BSWM_DET_REPORT_ERROR(BSWM_WDGM_REQUESTPARTITIONRESET_APIID, BSWM_E_REQ_MODE_OUT_OF_RANGE);
    }
#endif
    else
    {
#if(BSWM_WDGM_RESET_PORT_NUM > 0)
        BswM_WdgMRequestReset[Application] = TRUE;
        BswM_ArbitratePortMappingRules(Port);
#endif
    }

}
#endif


#if(STD_ON == BSWM_MULTIPATITION_ENABLED)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: BswM_BswMPartitionRestarted  SWS_BswM_00193
*
* Description:   Function called by Restart Task if the partition containing the BswM has been
*                restarted.
*
* Inputs:        BswM_ModeGroupType switched_modeGroup,
*                BswM_ModeType switched_mode
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, BSWM_CODE) BswM_BswMPartitionRestarted
(
    void
)
{
    /*SWS_BswM_00077*/
    if(STD_INITIALIZED != BswM_InitStatus)
    {
        BSWM_DET_REPORT_ERROR(BSWM_BSWMPARTITIONRESTARTED_APIID, BSWM_E_NO_INIT);
    }
    /*SWS_BswM_00089 SWS_BswM_00090*/
    else
    {
    }
}
#endif

#if(STD_ON == BSWM_TIMER_ENABLED)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: BswM_SetTimer
*
* Description:   This routine set the BswM internal timer.
*
* Inputs:        TimerValue: Timer value to be set.
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, BSWM_CODE) BswM_SetTimer
(
    uint8 TimerValue
)
{
    BswM_Timer = TimerValue;
    BswM_TimerMode = BSWM_TIMER_STARTED;
}
#endif

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: BswM_Init  SWS_BswM_00002
*
* Description:   This routine Initializes the BSW Mode Manager for the further processing.
*
* Inputs:        ConfigPtr: Pointer to configuration parameter set,
*                           used e.g. for post build parameters
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, BSWM_CODE) BswM_Init
(
    P2CONST(BswM_ConfigType, AUTOMATIC, BSWM_CONST) ConfigPtr
)
{
    BswMRuleType RuleIndex;
    BswMPortType PortId;

#if(STD_ON == BSWM_DEV_ERROR_DETECT)
    for(PortId = (BswMPortType)0; PortId < (BswMPortType)BSWM_MAX_PORT_NUM; PortId++)
    {
        if((BswMPortMappingRulesStart[PortId] + BswMPortMappingRulesNum[PortId]) > BSWM_MAX_PORT_MAPPING_RULE_NUM)
        {
            BSWM_DET_REPORT_ERROR(BSWM_INIT_APIID, BSWM_E_PARAM_CONFIG);
        }
    }
#endif

#if(BSWM_CONFIG_VARIANTS == STD_CONFIG_VARIANTS_POSTBUILD)
    if(NULL_PTR == ConfigPtr)
    {
        BSWM_DET_REPORT_ERROR(BSWM_INIT_APIID, BSWM_E_PARAM_POINTER);
    }
    else
    {
        BswM_ConfigSet = ConfigPtr;
        (void)BswM_ConfigSet;
#else
    (void) ConfigPtr;
#endif

        /*SWS_BswM_00044*/
        for(RuleIndex = (BswMRuleType)0; RuleIndex < (BswMRuleType)BSWM_MAX_RULE_NUM; RuleIndex++)
        {
            BswMRuleState[RuleIndex] = BswMAvailableRules[RuleIndex].RuleInitState;
            BSWM_RULE_SET_UNDEFERRED(RuleIndex);
        }


#if(STD_ON == BSWM_TIMER_ENABLED)
        BswM_Timer = (uint8)0;
#endif

        BSWM_UNLOCK();
        BswMRuleDeferredCnt = (uint8)0;

        BswM_InitStatus = STD_INITIALIZED;

        /*Arbitrate all rules with their default value*/
        for(RuleIndex = (BswMRuleType)0; RuleIndex < (BswMRuleType)BSWM_MAX_RULE_NUM; RuleIndex++)
        {
            (void)BswM_ArbitrateRule(RuleIndex);
        }
#if(BSWM_CONFIG_VARIANTS == STD_CONFIG_VARIANTS_POSTBUILD)
    }

#endif
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: BswM_Deinit  SWS_BswM_00119
*
* Description:   This routine Deinitializes the BSW Mode Manager.
*
* Inputs:        None
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, BSWM_CODE) BswM_Deinit
(
    void
)
{
    /*SWS_BswM_00120*/
    BswM_InitStatus = STD_UNINITIALIZED;
}


/*******************************************************************************
*   Callback Functions
*******************************************************************************/

/*******************************************************************************
*    Scheduled Functions
*******************************************************************************/

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: BswM_MainFunction  SWS_BswM_00053
*
* Description:   Main function of the BswM
*
* Inputs:         None
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, BSWM_CODE) BswM_MainFunction
(
    void
)
{
    BswMRuleType RuleIndex;
#if(STD_ON == BSWM_TIMER_ENABLED)
    BswMPortType Port = BSWM_MAP_TIMER_TO_PORT();
#endif

    /*SWS_BswM_00076*/
    if(STD_INITIALIZED != BswM_InitStatus)
    {
        /*return immediately without performing any action and without reporting an error*/
    }
    else
    {
#if(STD_ON == BSWM_TIMER_ENABLED)
        if(BswM_Timer > (uint8)0)
        {
            BswM_Timer--;

            if(BswM_Timer == (uint8)0)
            {
                BswM_TimerMode = BSWM_TIMER_EXPIRED;
                BswM_ArbitratePortMappingRules(Port);
            }
        }
#endif
        /*SWS_BswM_00068*/
        BSWM_LOCK();

        /*Loop control variable in this 'while' statement, BswMRuleDeferredCnt, has file scope.
          This is a must, since the BswM_ImmediateRunRule may increase BswMRuleDeferredCnt, and 
          this while loop can only exit after the BswMRuleDeferredCnt decreased to zero*/
        while(BswMRuleDeferredCnt > (uint8)0)
        {
            for(RuleIndex = (BswMRuleType)0; RuleIndex < (BswMRuleType)BSWM_MAX_RULE_NUM; RuleIndex++)
            {
                if(BSWM_RULE_IS_DEFERRED(RuleIndex) )
                {
                    BSWM_RULE_SET_UNDEFERRED(RuleIndex);
                    BswMRuleDeferredCnt--;
                    BswM_ImmediateRunRule(RuleIndex);
                }
            }
        }

        BSWM_UNLOCK();
    }

    return;
}


#define BSWM_STOP_SEC_CODE
#include "MemMap.h"

