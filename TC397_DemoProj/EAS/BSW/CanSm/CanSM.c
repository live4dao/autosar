/*  BEGIN_FILE_HDR
********************************************************************************
*   NOTICE
*   This software is the property of HiRain Technologies. Any information
*   contained in this doc should not be reproduced, or used, or disclosed
*   without the written authorization from HiRain Technologies.
********************************************************************************
*   File Name       : CanSM.c
********************************************************************************
*   Project/Product : AUTOSAR 4.2
*   Title           : CanSM module Source File
*   Author          : Hirain
********************************************************************************
*   Description     : Implementation of CAN State Manager provided functionality
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
*   01.00.00    17/08/2016    Ning.Chen     N/A          Beta
*   01.01.00    26/06/2018    Boxue.Li      N/A          Original
*   01.01.01    14/08/2018    Boxue.Li      N/A          EAS422_CanSM_20180814_01
*   01.01.02    29/08/2018    Boxue.Li      N/A          EAS422_CanSM_20180829_01
*   01.01.03    28/09/2018    Boxue.Li      N/A          EAS422_CanSM_20180928_01
*   01.01.04    21/01/2019    Boxue.Li      N/A          EAS422_CanSM_20190121_01
*   01.01.05    28/01/2019    Boxue.Li      N/A          EAS422_CanSM_20190128_01
*   01.01.06    26/03/2019    Boxue.Li      N/A          EAS422_CanSM_20190326_01
*   01.01.07    08/05/2019    Boxue.Li      N/A          EAS422_CanSM_20190508_01
*   01.01.08    21/10/2019    Boxue.Li      N/A          EAS422_CanSM_20191021_01
*   01.01.09    08/11/2021    Feixiang.Dong N/A          EAS422_CanSM_20211108_01
********************************************************************************
* END_FILE_HDR*/

/*******************************************************************************
*   Includes
*******************************************************************************/
#include "CanSM.h"

#if(STD_ON == CANSM_BSWM_SUPPORT)
#include "BswM_CanSM.h"
#endif

#if(STD_ON == CANSM_DEV_ERROR_DETECT)
#include "Det.h"/*SWS_CanSM_00015*/
#endif

#include "SchM_CanSM.h"
#if(STD_ON == CANSM_DEM_SUPPORT)
#include "Dem.h"
#endif

/*SWS_CanSM_00548*/
#if(STD_ON == CANSM_PNC_SUPPORT)
#include "CanNm_Cbk.h"
#endif

#if(STD_ON == CANSM_OSEKNM_SUPPORT)
#include "OsekNm_Cbk.h"
#endif

/*******************************************************************************
*   Version Check
*******************************************************************************/
/*SWS_CanSM_00025 */
#if(STD_ON == CANSM_PRIVATE_VERSION_CHECK)
/* check Version with other import module */


/* check Version with cfg file */
#if ((CANSM_AR_RELEASE_MAJOR_VERSION != CANSM_AR_RELEASE_MAJOR_VERSION_CFG) || \
   (CANSM_AR_RELEASE_MINOR_VERSION != CANSM_AR_RELEASE_MINOR_VERSION_CFG))
#error "AutoSar Version Numbers of CanSM and its cfg file are different"
#endif

#if ((CANSM_SW_MAJOR_VERSION != CANSM_SW_MAJOR_VERSION_CFG) || \
   (CANSM_SW_MINOR_VERSION != CANSM_SW_MINOR_VERSION_CFG))
#error "SW Version Numbers of CanSM and its cfg file are different"
#endif


#endif/*#if(STD_ON == CANSM_PRIVATE_AR_VERSION_CHECK)*/



/*******************************************************************************
*   Vars
*******************************************************************************/
#define CANSM_START_SEC_VAR_INIT_8
#include "MemMap.h"

STATIC VAR(CanSM_StateType, CANSM_VAR)  CanSM_InitStatus = CANSM_UNINITED;

#if(STD_ON == CANSM_TXOFFLINEACTIVE_SUPPORT)
STATIC VAR(boolean, CANSM_VAR)  CanSM_PassiveMode = FALSE;
#endif

#define CANSM_STOP_SEC_VAR_INIT_8
#include "MemMap.h"


#define CANSM_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h"

#if(CANSM_CONFIG_VARIANTS == STD_CONFIG_VARIANTS_POSTBUILD)
STATIC P2CONST(CanSM_ConfigType, AUTOMATIC, CANSM_APPL_CONST) CanSM_ConfigSet;
#endif

#define CANSM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h"



/*******************************************************************************
*   Macro
*******************************************************************************/
#if((CANSM_CONFIG_VARIANTS == STD_CONFIG_VARIANTS_PRECOMPILE) && (1 == CANSM_MAX_NETWORK_NUM))
#define CANSM_SINGLE_NETWORK_OPTIMIZE    STD_ON
#else
#define CANSM_SINGLE_NETWORK_OPTIMIZE    STD_OFF
#endif


#if(STD_ON == CANSM_SINGLE_NETWORK_OPTIMIZE)
#define CANSM_NETWORK_HANDLE         ((NetworkHandleType)0)
#define CANSM_COMM_NW_REF            (CANSM_UESD_NETWORKCFG_INFO[0].ComMNetworfRef)
#define CANSM_CANIF_CTRLID           ((uint8)CANSM_UESD_NETWORKCFG_INFO[0].CanIfCtrlId)
#if(STD_ON == CANSM_CANTRCV_SUPPORT)
#define CANSM_CANIF_TRCVID           (CANSM_UESD_NETWORKCFG_INFO[0].CanIfTrcvId)
#endif

#else

#define CANSM_NETWORK_HANDLE         (nwHandle)
#define CANSM_COMM_NW_REF            (CANSM_UESD_NETWORKCFG_INFO[nwHandle].ComMNetworfRef)

#if(STD_OFF == CANSM_CTRLOPT_SUPPORT)
#define CANSM_CANIF_CTRLID           ((uint8)CANSM_UESD_NETWORKCFG_INFO[nwHandle].CanIfCtrlId)
#else
#define CANSM_CANIF_CTRLID           (nwHandle)
#endif

#if(STD_ON == CANSM_CANTRCV_SUPPORT)
#define CANSM_CANIF_TRCVID           (CANSM_UESD_NETWORKCFG_INFO[nwHandle].CanIfTrcvId)
#endif

#endif


#if(STD_ON == CANSM_CTRLOPT_SUPPORT)
#define  CanSM_GetNetWorkHandleFromCtrlId(CtrlId)    (CtrlId)
#endif


#if(STD_ON == CANSM_DEV_ERROR_DETECT)

#define  CANSM_DET_REPORT_ERROR(ApiId, errcode)  \
    DET_REPORT_ERROR(CANSM_MODULE_ID, CANSM_INSTANCE_ID, (ApiId), (errcode))

#else

#define  CANSM_DET_REPORT_ERROR(ApiId, errcode)

#endif



#if(STD_ON == CANSM_BSWM_SUPPORT)
#define CANSM_BSWM_REPORT(Network, state)    BswM_CanSM_CurrentState(Network,(state))
#else
#define CANSM_BSWM_REPORT(Network, state)
#endif

/*SWS_CanSM_00266 SWS_CanSM_00284 */
#define CANSM_COMM_REPORT(state)    \
    do\
    {\
        CanSM_NetworkInfo[CANSM_NETWORK_HANDLE].ComMMode = (state);\
        ComM_BusSM_ModeIndication(CANSM_COMM_NW_REF, (&(state)));\
    }while(0)

#if(STD_ON == CANSM_DEM_SUPPORT)
#define CANSM_DEM_REPORT(event, state)  Dem_ReportErrorStatus((event), (state))
#else
#define CANSM_DEM_REPORT(event, state)
#endif

#define CANSM_NO_TRIGGER              ((uint8)0U)
#define CANSM_T_FULL_COM_MODE_REQUEST ((uint8)(1<<0))
#define CANSM_T_NO_COM_MODE_REQUEST   ((uint8)(1<<1))
#define CANSM_T_SILENT_COM_MODE_REQUEST   ((uint8)(1<<2))
#define CANSM_T_CHANGE_BR_REQUEST     ((uint8)(1<<3))
#define CANSM_T_BUS_OFF               ((uint8)(1<<4))
#define CANSM_T_START_WAKEUP_SOURCE   ((uint8)(1<<5))
#define CANSM_T_STOP_WAKEUP_SOURCE    ((uint8)(1<<6))
#define CANSM_T_CANSM_INIT            ((uint8)(1<<7))
#define CANSM_T_MODE_REQUEST_MASK     ((uint8)0x07)

#define CANSM_SET_TRIGGER(ch,trigger)  (CanSM_TriggerInfo[(ch)] |= (trigger))
#define CANSM_CLR_TRIGGER(ch,trigger)  (CanSM_TriggerInfo[(ch)] &= ~(trigger))
#define CANSM_CLEAR_ALL_TRIGGER(ch)    (CanSM_TriggerInfo[(ch)] = (uint8)0)
#define CANSM_CLEAR_MODE_REQUEST(ch)   (CANSM_CLR_TRIGGER(ch, CANSM_T_MODE_REQUEST_MASK))


/*******************************************************************************
*   Private Functions
*******************************************************************************/
#define CANSM_START_SEC_CODE
#include "MemMap.h"

STATIC FUNC(boolean, CANSM_CODE) CanSM_WaitProcess
(
    const NetworkHandleType nwHandle,
    const CanSM_subStateType resetState
);

STATIC FUNC(void, CANSM_CODE) CanSM_CanCtrlStateSwitchSeq
(
    const NetworkHandleType nwHandle,
    const CanIf_ControllerModeType mode,
    const CanSM_subStateType waitState
);
STATIC FUNC(void, CANSM_CODE) CanSM_TriggerStateSeq
(
    const NetworkHandleType nwHandle,
    const CanSM_subStateType nextState
);


#if(STD_ON == CANSM_CANTRCV_SUPPORT)
STATIC FUNC(void, CANSM_CODE) CanSM_CanTrcvStateSwitchSeq
(
    const NetworkHandleType nwHandle,
    const CanTrcv_TrcvModeType mode,
    const CanSM_subStateType waitState
);
#endif
STATIC FUNC(void, CANSM_CODE) CanSM_PreNoComProcess
(
    const NetworkHandleType nwHandle
);
STATIC FUNC(void, CANSM_CODE) CanSM_PreFullComProcess
(
    const NetworkHandleType nwHandle
);

STATIC FUNC(void, CANSM_CODE) CanSM_FullComProcess
(
    const NetworkHandleType nwHandle
);
#if(STD_OFF == CANSM_CTRLOPT_SUPPORT)
STATIC FUNC(NetworkHandleType, CANSM_CODE)  CanSM_GetNetWorkHandleFromCtrlId
(
    const uint8 CtrlId
);
#endif
#if(STD_ON == CANSM_CANTRCV_SUPPORT)
STATIC FUNC(NetworkHandleType, CANSM_CODE)  CanSM_GetNetWorkHandleFromTrcvId
(
    const uint8 TrcvId
);
#endif


#if(STD_ON == CANSM_SET_BAUDRATE_API)
STATIC FUNC(void, CANSM_CODE) CanSM_ChangeBDProcess
(
    const NetworkHandleType nwHandle
);
#endif

STATIC FUNC(void, CANSM_CODE) CanSM_SwitchState
(
    const NetworkHandleType nwHandle,
    const CanSM_MainStateType state,
    const CanSM_subStateType substate
);

STATIC FUNC(void, CANSM_CODE) CanSM_SwitchToSilentSeq
(
    const NetworkHandleType nwHandle
);
STATIC FUNC(void, CANSM_CODE) CanSM_SwitchToFullComSeq
(
    const NetworkHandleType nwHandle
);
STATIC FUNC(void, CANSM_CODE) CanSM_SwitchToPreNoComSeq
(
    const NetworkHandleType nwHandle
);

STATIC FUNC(void, CANSM_CODE) CanSM_ExitPreNoCom
(
    const NetworkHandleType nwHandle
);
STATIC FUNC(void, CANSM_CODE) CanSM_ExitWUValidation
(
    const NetworkHandleType nwHandle
);
STATIC FUNC(void, CANSM_CODE) CanSM_ExitSilentComBor
(
    const NetworkHandleType nwHandle
);

STATIC FUNC(void, CANSM_CODE) CanSM_TriggerProcess
(
    const NetworkHandleType nwHandle
);

STATIC FUNC(void, CANSM_CODE) CanSM_WUValidationProcess
(
    const NetworkHandleType nwHandle
);

STATIC FUNC(void, CANSM_CODE) CanSM_SilentComBorProcess
(
    const NetworkHandleType nwHandle
);

STATIC FUNC(void, CANSM_CODE) CanSM_SwitchToSilentComBorSeq
(
    const NetworkHandleType nwHandle
);


/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: CanSM_GetNetWorkHandleFromCtrlId
*
* Description:   get cansm channel handle from ctrlId coming from canif
*
* Inputs:        CtrlId
*
* Outputs:       NetworkHandleType
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
#if(STD_OFF == CANSM_CTRLOPT_SUPPORT)
STATIC FUNC(NetworkHandleType, CANSM_CODE)  CanSM_GetNetWorkHandleFromCtrlId
(
    const uint8 CtrlId
)
{
    NetworkHandleType nwHandle = COMSTACK_INVALID_NETWORK_HANDLE;
    uint8 i;

    for (i = (uint8)0; i < (uint8)CANSM_USED_NETWORK_NUM; i++)
    {
        if(CtrlId == CANSM_UESD_NETWORKCFG_INFO[i].CanIfCtrlId)
        {
            nwHandle = i;
            break;
        }
    }


    return nwHandle;

}
#endif

#if(STD_ON == CANSM_CANTRCV_SUPPORT)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: CanSM_GetNetWorkHandleFromTrcvId
*
* Description:   get cansm channel handle from trcvid  coming from CanIf
*
* Inputs:        TrcvId
*
* Outputs:       NetworkHandleType
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(NetworkHandleType, CANSM_CODE)  CanSM_GetNetWorkHandleFromTrcvId
(
    const uint8 TrcvId
)
{
    NetworkHandleType nwHandle = COMSTACK_INVALID_NETWORK_HANDLE;
    uint8 i;

    for (i = 0; i < CANSM_USED_NETWORK_NUM; i++)
    {
        if(TrcvId == CANSM_UESD_NETWORKCFG_INFO[i].CanIfTrcvId)
        {
            nwHandle = i;
            break;
        }
    }


    return nwHandle;

}

#endif


/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: CanSM_WaitProcess
*
* Description:   process all kinds of wait State,like wait stop, wait sleep, wait start,
*                if repeat max, call func to process
*
* Inputs:        network, waitState,resetState,func
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(boolean, CANSM_CODE) CanSM_WaitProcess
(
    const NetworkHandleType nwHandle,
    const CanSM_subStateType resetState
)
{
    boolean loopFlag = FALSE;
    CanSM_MainStateType state;

    CanSM_NetworkInfo[CANSM_NETWORK_HANDLE].durationTime++;
    if(CanSM_NetworkInfo[CANSM_NETWORK_HANDLE].durationTime > (uint16)CANSM_USED_REQ_DURATION)
    {
        /*SWS_CanSM_00626 SWS_CanSM_00630 SWS_CanSM_00634 SWS_CanSM_00467 SWS_CanSM_00471
        SWS_CanSM_00475 SWS_CanSM_00479 SWS_CanSM_00602 SWS_CanSM_00486 SWS_CanSM_00490
        SWS_CanSM_00494 SWS_CanSM_00512 SWS_CanSM_00527 SWS_CanSM_00535 SWS_CanSM_00449
        SWS_CanSM_00454 SWS_CanSM_00457*/
        CanSM_NetworkInfo[CANSM_NETWORK_HANDLE].durationTime = (uint16)0;
        CanSM_NetworkInfo[CANSM_NETWORK_HANDLE].retryNum++;
        CanSM_NetworkInfo[CANSM_NETWORK_HANDLE].CanSMSubState = resetState;
        /* state reset, loop = true, call canif Api again at same main task */
        loopFlag = TRUE;
        if(CanSM_NetworkInfo[CANSM_NETWORK_HANDLE].retryNum > (uint8)CANSM_USED_MAX_REQ_CNT)
        {
            CanSM_NetworkInfo[CANSM_NETWORK_HANDLE].retryNum = (uint8)0;

            /* in the following cases , if T_REPEAT_MAX happened, start preNoCom
               1. when in PRE_NOCOM SWS_CanSM_00480
               2. when in PRE_FULLCOM SWS_CanSM_00495
               3. when in CHANGE_BAUDRATE SWS_CanSM_00536
            */
            state = CanSM_NetworkInfo[CANSM_NETWORK_HANDLE].CanSMState;
            if((state == CANSM_BSM_S_PRE_NOCOM)
                || (state == CANSM_BSM_S_PRE_FULLCOM)
                || (state == CANSM_BSM_S_CHANGE_BAUDRATE)
                || (state == CANSM_BSM_S_FULLCOM)
                || (state == CANSM_BSM_S_SILENTCOM_BOR))
            {
                CanSM_SwitchToPreNoComSeq(CANSM_NETWORK_HANDLE);
            }

            /*SWS_CanSM_00385*/
            CANSM_DET_REPORT_ERROR(CANSM_WAITPROCESS_SERVICE_ID, CANSM_E_MODE_REQUEST_TIMEOUT);
            loopFlag = FALSE;
        }
    }
    return loopFlag;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: CanSM_CanCtrlStateSwitchSeq
*
* Description:   call CanIf_SetControllerMode and switch to next state
*
* Inputs:        network, mode, tState, waitState,nextState
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, CANSM_CODE) CanSM_CanCtrlStateSwitchSeq
(
    const NetworkHandleType nwHandle,
    const CanIf_ControllerModeType mode,
    const CanSM_subStateType waitState
)
{
    /*SWS_CanSM_00464 SWS_CanSM_00468 SWS_CanSM_00627 SWS_CanSM_00631 SWS_CanSM_00487
      SWS_CanSM_00524 SWS_CanSM_00532 SWS_CanSM_00513 SWS_CanSM_00604*/
    CanSM_NetworkInfo[CANSM_NETWORK_HANDLE].CanSMSubState = waitState;

    (void)CanIf_SetControllerMode(CANSM_CANIF_CTRLID, mode);

    /* if CanIfApi Call return E_OK:
           if modeInd is syn get, after this function, the mainfunction will continue to process Ind State
           if modeInd is not syn get, keep wait state,mainfunction will wait for Ind
       if CanIfApi Call return E_NOT_OK:
           Treat it as No Syn Ind Get, keep wait state, after wait duration, api will call again
    */

}


/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: CanSM_TriggerStateSeq
*
* Description:   after ind is get from canif, switch to next state
*
* Inputs:        nwHandle, nextState, func
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, CANSM_CODE) CanSM_TriggerStateSeq
(
    const NetworkHandleType nwHandle,
    const CanSM_subStateType nextState
)
{
    CanSM_NetworkInfo[CANSM_NETWORK_HANDLE].CanSMSubState = nextState;
    CanSM_NetworkInfo[CANSM_NETWORK_HANDLE].durationTime = (uint16)0;
    CanSM_NetworkInfo[CANSM_NETWORK_HANDLE].retryNum = (uint8)0;
}


#if(STD_ON == CANSM_CANTRCV_SUPPORT)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: CanSM_CanTrcvStateSwitchSeq
*
* Description:   call CanIf_SetTrcvMode and switch to next state
*
* Inputs:        network, mode, tState, waitState
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, CANSM_CODE) CanSM_CanTrcvStateSwitchSeq
(
    const NetworkHandleType nwHandle,
    const CanTrcv_TrcvModeType mode,
    const CanSM_subStateType waitState
)
{
    /*SWS_CanSM_00472 SWS_CanSM_00476 SWS_CanSM_00623*/
    CanSM_NetworkInfo[CANSM_NETWORK_HANDLE].CanSMSubState = waitState;
    (void)CanIf_SetTrcvMode(CANSM_CANIF_TRCVID, mode);
    /* if CanIfApi Call return E_OK:
           if modeInd is syn get, after this function, the mainfunction will continue to process Ind State
           if modeInd is not syn get, keep wait state,mainfunction will wait for Ind
       if CanIfApi Call return E_NOT_OK:
           Treat it as No Syn Ind Get, keep wait state, after wait duration, api will call again
    */
}
#endif




/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: CanSM_PreNoComProcess
*
* Description:   schdule function to process PreNoCom State
*
* Inputs:        network
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, CANSM_CODE) CanSM_PreNoComProcess
(
    const NetworkHandleType nwHandle
)
{
    boolean loopFlag;
    /*
     ref to CANSM_BSM_DeinitPnNotSupported, sub state machine of CANSM_BSM_S_PRE_NOCOM
     SWS_CanSM_00556  SWS_CanSM_00557  SWS_CanSM_00464-SWS_CanSM_00480
    */
    do
    {
        loopFlag = FALSE;
        switch(CanSM_NetworkInfo[CANSM_NETWORK_HANDLE].CanSMSubState)
        {
        case CANSM_S_CC_STOPPED:
            /*SWS_CanSM_00464 SWS_CanSM_00465*/
            CanSM_CanCtrlStateSwitchSeq(CANSM_NETWORK_HANDLE, CANIF_CS_STOPPED, CANSM_S_CC_STOPPED_WAIT);
            loopFlag = TRUE;
            break;

        case CANSM_S_CC_STOPPED_WAIT:
#if((STD_ON == CANSM_PNC_SUPPORT) && (STD_ON == CANSM_CANTRCV_SUPPORT))
            loopFlag = CanSM_WaitProcess(CANSM_NETWORK_HANDLE, CANSM_S_PN_CC_STOPPED);
#else
            loopFlag = CanSM_WaitProcess(CANSM_NETWORK_HANDLE, CANSM_S_CC_STOPPED);
#endif
            break;

        case CANSM_S_CC_STOPPED_IND:
#if((STD_ON == CANSM_PNC_SUPPORT) && (STD_ON == CANSM_CANTRCV_SUPPORT))
            CanSM_TriggerStateSeq(CANSM_NETWORK_HANDLE, CANSM_S_TRCV_NORMAL);
#else
            CanSM_TriggerStateSeq(CANSM_NETWORK_HANDLE, CANSM_S_CC_SLEEP);
#endif
            loopFlag = TRUE;
            break;

        case CANSM_S_CC_SLEEP:
            /*SWS_CanSM_00453 SWS_CanSM_00455 SWS_CanSM_00456 SWS_CanSM_00468 SWS_CanSM_00469*/
            CanSM_CanCtrlStateSwitchSeq(CANSM_NETWORK_HANDLE, CANIF_CS_SLEEP, CANSM_S_CC_SLEEP_WAIT);
            loopFlag = TRUE;
            break;

        case CANSM_S_CC_SLEEP_WAIT:
#if((STD_ON == CANSM_PNC_SUPPORT) && (STD_ON == CANSM_CANTRCV_SUPPORT))
            /*SWS_CanSM_00445*/
            loopFlag = CanSM_WaitProcess(CANSM_NETWORK_HANDLE, CANSM_S_CHECK_WFLAG_IN_NOT_CC_SLEEP);
#else
            loopFlag = CanSM_WaitProcess(CANSM_NETWORK_HANDLE, CANSM_S_CC_SLEEP);
#endif
            break;

        case CANSM_S_CC_SLEEP_IND:
#if(STD_OFF == CANSM_CANTRCV_SUPPORT)
            /*SWS_CanSM_00560 SWS_CanSM_00556 SWS_CanSM_00557*/
            CanSM_ExitPreNoCom(CANSM_NETWORK_HANDLE);
            break;
#else
#if(STD_ON == CANSM_PNC_SUPPORT)
            CanSM_TriggerStateSeq(CANSM_NETWORK_HANDLE, CANSM_S_CHECK_WFLAG_IN_CC_SLEEP);
#else
            CanSM_TriggerStateSeq(CANSM_NETWORK_HANDLE, CANSM_S_TRCV_NORMAL);
#endif
            loopFlag = TRUE;
            break;

        case CANSM_S_TRCV_NORMAL:
            /*SWS_CanSM_00446 SWS_CanSM_00447 SWS_CanSM_00472 SWS_CanSM_00473*/
            CanSM_CanTrcvStateSwitchSeq(CANSM_NETWORK_HANDLE, CANTRCV_TRCVMODE_NORMAL, CANSM_S_TRCV_NORMAL_WAIT);
            loopFlag = TRUE;
            break;

        case CANSM_S_TRCV_NORMAL_WAIT:
            loopFlag = CanSM_WaitProcess(CANSM_NETWORK_HANDLE, CANSM_S_TRCV_NORMAL);
            break;

        case CANSM_S_TRCV_NORMAL_IND:
            CanSM_TriggerStateSeq(CANSM_NETWORK_HANDLE, CANSM_S_TRCV_STANDBY);
            loopFlag = TRUE;
            break;

        case CANSM_S_TRCV_STANDBY:
            /*SWS_CanSM_00451 SWS_CanSM_00452 SWS_CanSM_00476 SWS_CanSM_00477*/
            CanSM_CanTrcvStateSwitchSeq(CANSM_NETWORK_HANDLE, CANTRCV_TRCVMODE_STANDBY, CANSM_S_TRCV_STANDBY_WAIT);
            loopFlag = TRUE;
            break;

        case CANSM_S_TRCV_STANDBY_WAIT:
            loopFlag = CanSM_WaitProcess(CANSM_NETWORK_HANDLE, CANSM_S_TRCV_STANDBY);
            break;

        case CANSM_S_TRCV_STANDBY_IND:
#if(STD_ON == CANSM_PNC_SUPPORT)
            CanSM_TriggerStateSeq(CANSM_NETWORK_HANDLE, CANSM_S_CC_SLEEP);
            loopFlag = TRUE;
#else
            CanSM_ExitPreNoCom(CANSM_NETWORK_HANDLE);
#endif
            break;
#endif

#if(STD_ON == CANSM_PNC_SUPPORT)
        case CANSM_S_PN_CLEAR_WUF:
#if(STD_ON == CANSM_CANTRCV_SUPPORT)
            /*SWS_CanSM_00438 SWS_CanSM_00439*/
            CanSM_NetworkInfo[CANSM_NETWORK_HANDLE].CanSMSubState = CANSM_S_PN_CLEAR_WUF_WAIT;
            (void)CanIf_ClearTrcvWufFlag(CANSM_CANIF_TRCVID);
#else
            CanSM_NetworkInfo[CANSM_NETWORK_HANDLE].CanSMSubState = CANSM_S_PN_CC_STOPPED;
#endif
            loopFlag = TRUE;
            break;

#if(STD_ON == CANSM_CANTRCV_SUPPORT)
        case CANSM_S_PN_CLEAR_WUF_WAIT:
            /*SWS_CanSM_00443*/
            loopFlag = CanSM_WaitProcess(CANSM_NETWORK_HANDLE, CANSM_S_PN_CLEAR_WUF);
            break;

        case CANSM_S_PN_CLEAR_WUF_IND:
            CanSM_TriggerStateSeq(CANSM_NETWORK_HANDLE, CANSM_S_PN_CC_STOPPED);
            loopFlag = TRUE;
            break;
#endif
        case CANSM_S_PN_CC_STOPPED:
            /*SWS_CanSM_00441 SWS_CanSM_00442*/
            CanSM_CanCtrlStateSwitchSeq(CANSM_NETWORK_HANDLE, CANIF_CS_STOPPED, CANSM_S_CC_STOPPED_WAIT);
            loopFlag = TRUE;
            break;

#if(STD_ON == CANSM_CANTRCV_SUPPORT)
        case CANSM_S_CHECK_WFLAG_IN_NOT_CC_SLEEP:
            /*SWS_CanSM_00462*/
            CanSM_NetworkInfo[CANSM_NETWORK_HANDLE].CanSMSubState = CANSM_S_CHECK_WUF_IN_NOT_CC_SLEEP_WAIT;
            (void)CanIf_CheckTrcvWakeFlag(CANSM_CANIF_TRCVID);
            break;

        case CANSM_S_CHECK_WFLAG_IN_CC_SLEEP:
            /*SWS_CanSM_00458 SWS_CanSM_00459*/
            CanSM_NetworkInfo[CANSM_NETWORK_HANDLE].CanSMSubState = CANSM_S_CHECK_WUF_IN_CC_SLEEP_WAIT;
            (void)CanIf_CheckTrcvWakeFlag(CANSM_CANIF_TRCVID);
            loopFlag = TRUE;
            break;
#endif
        case CANSM_S_CHECK_WUF_IN_CC_SLEEP_WAIT:
            /*SWS_CanSM_00461*/
            loopFlag = CanSM_WaitProcess(CANSM_NETWORK_HANDLE, CANSM_S_CHECK_WFLAG_IN_CC_SLEEP);
            break;

        case CANSM_S_CHECK_WFLAG_IN_CC_SLEEP_IND:
            CanSM_ExitPreNoCom(CANSM_NETWORK_HANDLE);
            break;

        case CANSM_S_CHECK_WUF_IN_NOT_CC_SLEEP_WAIT:
            /*SWS_CanSM_00461*/
            loopFlag = CanSM_WaitProcess(CANSM_NETWORK_HANDLE, CANSM_S_CHECK_WFLAG_IN_NOT_CC_SLEEP);
            break;

        case CANSM_S_CHECK_WUF_IN_NOT_CC_SLEEP_IND:
            /*SWS_CanSM_00461*/
            CanSM_TriggerStateSeq(CANSM_NETWORK_HANDLE, CANSM_S_PN_CLEAR_WUF);
            loopFlag = TRUE;
            break;

#endif
        default:
            /* Intentionally Empty */
            break;
        }
    }
    while(TRUE == loopFlag);

}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: CanSM_WUValidationProcess
*
* Description:   schdule function to process WUValidation State
*
* Inputs:        network
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, CANSM_CODE) CanSM_WUValidationProcess
(
    const NetworkHandleType nwHandle
)
{
    boolean loopFlag;

    do
    {
        loopFlag = FALSE;
        switch(CanSM_NetworkInfo[CANSM_NETWORK_HANDLE].CanSMSubState)
        {
#if(STD_ON == CANSM_CANTRCV_SUPPORT)
        case CANSM_S_TRCV_NORMAL:
            /*SWS_CanSM_00623 SWS_CanSM_00624*/
            CanSM_CanTrcvStateSwitchSeq(CANSM_NETWORK_HANDLE, CANTRCV_TRCVMODE_NORMAL, CANSM_S_TRCV_NORMAL_WAIT);
            loopFlag = TRUE;
            break;

        case CANSM_S_TRCV_NORMAL_WAIT:
            loopFlag = CanSM_WaitProcess(CANSM_NETWORK_HANDLE, CANSM_S_TRCV_NORMAL);
            break;

        case CANSM_S_TRCV_NORMAL_IND:
            CanSM_TriggerStateSeq(CANSM_NETWORK_HANDLE, CANSM_S_CC_STOPPED);
            loopFlag = TRUE;
            break;
#endif
        /*SWS_CanSM_00560*/
        case CANSM_S_CC_STOPPED:
            /*SWS_CanSM_00627 SWS_CanSM_00628*/
            CanSM_CanCtrlStateSwitchSeq(CANSM_NETWORK_HANDLE, CANIF_CS_STOPPED, CANSM_S_CC_STOPPED_WAIT);
            loopFlag = TRUE;
            break;

        case CANSM_S_CC_STOPPED_WAIT:
            loopFlag = CanSM_WaitProcess(CANSM_NETWORK_HANDLE, CANSM_S_CC_STOPPED);
            break;

        case CANSM_S_CC_STOPPED_IND:
            CanSM_TriggerStateSeq(CANSM_NETWORK_HANDLE, CANSM_S_CC_STARTED);
            loopFlag = TRUE;
            break;

        case CANSM_S_CC_STARTED:
            /*SWS_CanSM_00631 SWS_CanSM_00632*/
            CanSM_CanCtrlStateSwitchSeq(CANSM_NETWORK_HANDLE, CANIF_CS_STARTED, CANSM_S_CC_STARTED_WAIT);
            loopFlag = TRUE;
            break;

        case CANSM_S_CC_STARTED_WAIT:
            loopFlag = CanSM_WaitProcess(CANSM_NETWORK_HANDLE, CANSM_S_CC_STARTED);
            break;

        case CANSM_S_CC_START_IND:
            CanSM_ExitWUValidation(CANSM_NETWORK_HANDLE);
            break;

        default:
            /* Intentionally Empty */
            break;
        }
    }
    while(TRUE == loopFlag);

}


/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: CanSM_PreFullComProcess
*
* Description:   schdule function to process PreFullCom State
*
* Inputs:        network
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, CANSM_CODE) CanSM_PreFullComProcess
(
    const NetworkHandleType nwHandle
)
{
    boolean loopFlag;

    do
    {
        loopFlag = FALSE;
        switch(CanSM_NetworkInfo[CANSM_NETWORK_HANDLE].CanSMSubState)
        {
#if(STD_ON == CANSM_CANTRCV_SUPPORT)
        case CANSM_S_TRCV_NORMAL:
            /*SWS_CanSM_00483 SWS_CanSM_00484*/
            CanSM_CanTrcvStateSwitchSeq(CANSM_NETWORK_HANDLE, CANTRCV_TRCVMODE_NORMAL, CANSM_S_TRCV_NORMAL_WAIT);
            loopFlag = TRUE;
            break;

        case CANSM_S_TRCV_NORMAL_WAIT:
            loopFlag = CanSM_WaitProcess(CANSM_NETWORK_HANDLE, CANSM_S_TRCV_NORMAL);
            break;

        case CANSM_S_TRCV_NORMAL_IND:
            CanSM_TriggerStateSeq(CANSM_NETWORK_HANDLE, CANSM_S_CC_STOPPED);
            loopFlag = TRUE;
            break;
#endif
        /*SWS_CanSM_00558*/
        case CANSM_S_CC_STOPPED:
            /*SWS_CanSM_00487 SWS_CanSM_00488*/
            CanSM_CanCtrlStateSwitchSeq(CANSM_NETWORK_HANDLE, CANIF_CS_STOPPED, CANSM_S_CC_STOPPED_WAIT);
            loopFlag = TRUE;
            break;

        case CANSM_S_CC_STOPPED_WAIT:
            loopFlag = CanSM_WaitProcess(CANSM_NETWORK_HANDLE, CANSM_S_CC_STOPPED);
            break;

        case CANSM_S_CC_STOPPED_IND:
            CanSM_TriggerStateSeq(CANSM_NETWORK_HANDLE, CANSM_S_CC_STARTED);
            loopFlag = TRUE;
            break;

        case CANSM_S_CC_STARTED:
            /*SWS_CanSM_00491 SWS_CanSM_00492*/
            CanSM_CanCtrlStateSwitchSeq(CANSM_NETWORK_HANDLE, CANIF_CS_STARTED, CANSM_S_CC_STARTED_WAIT);
            loopFlag = TRUE;
            break;

        case CANSM_S_CC_STARTED_WAIT:
            loopFlag = CanSM_WaitProcess(CANSM_NETWORK_HANDLE, CANSM_S_CC_STARTED);
            break;

        case CANSM_S_CC_START_IND:
            CanSM_SwitchToFullComSeq(CANSM_NETWORK_HANDLE);
            break;

        default:
            /* Intentionally Empty */
            break;
        }
    }
    while(TRUE == loopFlag);
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: CanSM_FullComProcess
*
* Description:   schdule function to process FullCom State
*
* Inputs:        network
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, CANSM_CODE) CanSM_FullComProcess
(
    const NetworkHandleType nwHandle
)
{
    uint16 borDuration = (uint16)0;
    boolean loopFlag;
    ComM_ModeType ComMode;

    do
    {
        /* CANSM_BSM_S_FULLCOM, sub state machine of CANSM_BSM

        */
        loopFlag = FALSE;
        switch(CanSM_NetworkInfo[CANSM_NETWORK_HANDLE].CanSMSubState)
        {
        case CANSM_S_NO_BUS_OFF:
            break;

        case CANSM_S_RESTART_CC:
            /*SWS_CanSM_00509 SWS_CanSM_00510*/
            CanSM_CanCtrlStateSwitchSeq(CANSM_NETWORK_HANDLE, CANIF_CS_STARTED, CANSM_S_RESTART_CC_WAIT);
            loopFlag = TRUE;
            break;

        case CANSM_S_RESTART_CC_WAIT:
            loopFlag = CanSM_WaitProcess(CANSM_NETWORK_HANDLE, CANSM_S_RESTART_CC);
            break;

        case CANSM_S_RESTART_CC_IND:
            CanSM_TriggerStateSeq(CANSM_NETWORK_HANDLE, CANSM_S_TX_OFF);
            /*Effect: E_TX_OFF shall do nothing*/
            loopFlag = TRUE;/* directly step into txOff, cnt++*/
            break;

        case CANSM_S_TX_OFF:
            borDuration = CANSM_UESD_NETWORKCFG_INFO[CANSM_NETWORK_HANDLE].BorTimeL1;
            if(CanSM_NetworkInfo[CANSM_NETWORK_HANDLE].borCnt >= CANSM_UESD_NETWORKCFG_INFO[CANSM_NETWORK_HANDLE].cntL1toL2)
            {
                borDuration = CANSM_UESD_NETWORKCFG_INFO[CANSM_NETWORK_HANDLE].BorTimeL2;
                /*The first time fall into L2*/
                if((CanSM_NetworkInfo[CANSM_NETWORK_HANDLE].borCnt == CANSM_UESD_NETWORKCFG_INFO[CANSM_NETWORK_HANDLE].cntL1toL2)
                  && ((uint16)0 == CanSM_NetworkInfo[CANSM_NETWORK_HANDLE].borDurationTime))
                {
                    CanSM_EnterBorL2_Indication(CANSM_NETWORK_HANDLE);
                }
            }

            CanSM_NetworkInfo[CANSM_NETWORK_HANDLE].borDurationTime++;
            if(CanSM_NetworkInfo[CANSM_NETWORK_HANDLE].borDurationTime > borDuration)
            {
                /* time is arrive , try TxON
                   Effect: E_TX_ON CANSM516 CANSM517 CANSM518
                */
                CanSM_NetworkInfo[CANSM_NETWORK_HANDLE].borDurationTime = (uint16)0;
                /* add trybor cnt, if bigger than L1toL2, keep L1toL2+1 to avoid overflow */
                if(CanSM_NetworkInfo[CANSM_NETWORK_HANDLE].borCnt <= CANSM_UESD_NETWORKCFG_INFO[CANSM_NETWORK_HANDLE].cntL1toL2)
                {
                    CanSM_NetworkInfo[CANSM_NETWORK_HANDLE].borCnt++;
                }
                /*The state change should be put before CanIf_SetPduMode(CANSM_CANIF_CTRLID, CANIF_ONLINE).*/
                CanSM_NetworkInfo[CANSM_NETWORK_HANDLE].CanSMSubState = CANSM_S_BUS_OFF_CHECK;

#if(STD_ON == CANSM_TXOFFLINEACTIVE_SUPPORT)
                if(TRUE == CanSM_PassiveMode)
                {
                    /*SWS_CanSM_00648*/
                    (void)CanIf_SetPduMode(CANSM_CANIF_CTRLID, CANIF_TX_OFFLINE_ACTIVE);
                }
                else
#endif
                {
                    /*SWS_CanSM_00516*/
                    (void)CanIf_SetPduMode(CANSM_CANIF_CTRLID, CANIF_ONLINE);
                }
                /*SWS_CanSM_00517 SWS_CanSM_00518*/
                ComMode = COMM_FULL_COMMUNICATION;
                CANSM_BSWM_REPORT(nwHandle, CANSM_BSWM_FULL_COMMUNICATION);
                CANSM_COMM_REPORT(ComMode);
#if(STD_ON == CANSM_OSEKNM_SUPPORT)
                if(COMSTACK_INVALID_NETWORK_HANDLE != CANSM_UESD_NETWORKCFG_INFO[CANSM_NETWORK_HANDLE].OsekNmHandle)
                {
                    OsekNm_BusOffTimeout(CANSM_UESD_NETWORKCFG_INFO[CANSM_NETWORK_HANDLE].OsekNmHandle);
                }
#endif
                
                loopFlag = TRUE;
            }
            break;

        case CANSM_S_BUS_OFF_CHECK:
#if(STD_ON == CANSM_BOR_TX_CONFIRMATION_POLLING)      
            if(CANSM_UESD_NETWORKCFG_INFO[CANSM_NETWORK_HANDLE].BorTxConfirmationPoll == TRUE)
            {
                if(CANIF_TX_RX_NOTIFICATION == CanIf_GetTxConfirmationState(CANSM_CANIF_CTRLID))
                {
                    /* busoff rec succssed, reset all counters */
                    CanSM_SwitchState(CANSM_NETWORK_HANDLE, CANSM_BSM_S_FULLCOM, CANSM_S_NO_BUS_OFF);
                    CanSM_NetworkInfo[CANSM_NETWORK_HANDLE].borCnt = (uint8)0;
                    /*Effect: E_BUS_OFF_PASSIVE SWS_CanSM_00498*/
                    CANSM_DEM_REPORT(CANSM_UESD_NETWORKCFG_INFO[CANSM_NETWORK_HANDLE].BusOffEventId, DEM_EVENT_STATUS_PASSED);
                    CanSM_BORSuccess_Indication(CANSM_NETWORK_HANDLE);
#if(STD_ON == CANSM_OSEKNM_SUPPORT)
                    if(COMSTACK_INVALID_NETWORK_HANDLE != CANSM_UESD_NETWORKCFG_INFO[CANSM_NETWORK_HANDLE].OsekNmHandle)
                    {
                        OsekNm_BusOffRecovery(CANSM_UESD_NETWORKCFG_INFO[CANSM_NETWORK_HANDLE].OsekNmHandle);
                    }
#endif
                    loopFlag = TRUE;
                }
            }
            else
#endif        
            {
                CanSM_NetworkInfo[CANSM_NETWORK_HANDLE].borEnSureTime++;
                /*time is not arrive yet, keep CANSM_S_BUS_OFF_CHECK state */
                if(CanSM_NetworkInfo[CANSM_NETWORK_HANDLE].borEnSureTime > CANSM_UESD_NETWORKCFG_INFO[CANSM_NETWORK_HANDLE].BorTimeEnsure)  
                {
                    /* busoff rec succssed, reset all counters */
                    CanSM_SwitchState(CANSM_NETWORK_HANDLE, CANSM_BSM_S_FULLCOM, CANSM_S_NO_BUS_OFF);
                    CanSM_NetworkInfo[CANSM_NETWORK_HANDLE].borCnt = (uint8)0;
                    /*Effect: E_BUS_OFF_PASSIVE SWS_CanSM_00498*/
                    CANSM_DEM_REPORT(CANSM_UESD_NETWORKCFG_INFO[CANSM_NETWORK_HANDLE].BusOffEventId, DEM_EVENT_STATUS_PASSED);
                    CanSM_BORSuccess_Indication(CANSM_NETWORK_HANDLE);
#if(STD_ON == CANSM_OSEKNM_SUPPORT)
                    if(COMSTACK_INVALID_NETWORK_HANDLE != CANSM_UESD_NETWORKCFG_INFO[CANSM_NETWORK_HANDLE].OsekNmHandle)
                    {
                        OsekNm_BusOffRecovery(CANSM_UESD_NETWORKCFG_INFO[CANSM_NETWORK_HANDLE].OsekNmHandle);
                    }
#endif
                    loopFlag = TRUE;
                }
            }
            break;

        case CANSM_S_TX_TIMEOUT_EXCEPTION:
            /*not support yet, directly go to S_NO_BUS_OFF*/
            CanSM_SwitchState(CANSM_NETWORK_HANDLE, CANSM_BSM_S_FULLCOM, CANSM_S_NO_BUS_OFF);
            break;

        default:
            /* Intentionally Empty */
            break;
        }
    }
    while(TRUE == loopFlag);

}


#if(STD_ON == CANSM_SET_BAUDRATE_API)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: CanSM_ExitChangeBaudRate
*
* Description:   internal activation when exit from ChangeBaudRate
*
* Inputs:        network
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, CANSM_CODE) CanSM_ExitChangeBaudRate
(
    const NetworkHandleType nwHandle
)
{
    uint8 ModeReq = CanSM_TriggerInfo[CANSM_NETWORK_HANDLE] & CANSM_T_MODE_REQUEST_MASK;

    if(CANSM_T_NO_COM_MODE_REQUEST == ModeReq)
    {
        /* bdEnd -> NoCom, CanSM_SwitchToPreNoComSeq */
        CanSM_SwitchToPreNoComSeq(CANSM_NETWORK_HANDLE);/*SWS_CanSM_00542*/
    }
    else if(CANSM_T_SILENT_COM_MODE_REQUEST == ModeReq)
    {
        /*SWS_CanSM_00429*/
        /* bdEnd -> Silent, Syn Switch to Silent again */
        CanSM_SwitchToSilentSeq(CANSM_NETWORK_HANDLE);/*SWS_CanSM_00433 SWS_CanSM_00543*/
    }
    else
    {
        /*SWS_CanSM_00427*/
        /* no pending req or full req, bdEnd->Full, Syn Switch*/
        CanSM_SwitchToFullComSeq(CANSM_NETWORK_HANDLE);/*SWS_CanSM_00432 SWS_CanSM_00543*/
    }
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: CanSM_ChangeBDProcess
*
* Description:   schdule function to process change bd State
*
* Inputs:        nwHandle
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, CANSM_CODE) CanSM_ChangeBDProcess
(
    const NetworkHandleType nwHandle
)
{
    boolean loopFlag;
    Std_ReturnType ret = E_NOT_OK;
    ComM_ModeType ComMode;
    /*SWS_CanSM_00642*/
    do
    {
        /*ref CANSM_BSM_S_CHANGE_BAUDRATE, sub state machine of CANSM_BSM
        CANSM524 - CANSM527  CANSM532- CANSM536*/

        loopFlag = FALSE;
        switch(CanSM_NetworkInfo[CANSM_NETWORK_HANDLE].CanSMSubState)
        {
        case CANSM_S_CHANGE_BR_SYNC:
            /*SWS_CanSM_00639*/
            ret = CanIf_SetBaudrate(CANSM_CANIF_CTRLID, CanSM_NetworkInfo[CANSM_NETWORK_HANDLE].savedBDId);
            if(E_OK == ret)
            {
                /*SWS_CanSM_00641*/
                CanSM_ExitChangeBaudRate(CANSM_NETWORK_HANDLE);
            }
            else
            {
                CanSM_TriggerStateSeq(CANSM_NETWORK_HANDLE, CANSM_S_CC_STOPPED);
                loopFlag = TRUE;
            }
            break;
        case CANSM_S_CC_STOPPED:
            /*SWS_CanSM_00524 SWS_CanSM_00525*/
            CanSM_CanCtrlStateSwitchSeq(CANSM_NETWORK_HANDLE, CANIF_CS_STOPPED, CANSM_S_CC_STOPPED_WAIT);
            loopFlag = TRUE;
            break;

        case CANSM_S_CC_STOPPED_WAIT:
            loopFlag = CanSM_WaitProcess(CANSM_NETWORK_HANDLE, CANSM_S_CC_STOPPED);
            break;

        case CANSM_S_CC_STOPPED_IND:
            CanSM_TriggerStateSeq(CANSM_NETWORK_HANDLE, CANSM_S_CC_STARTED);
            /*Effect: E_CHANGE_BAUDRATE SWS_CanSM_00529 SWS_CanSM_00531*/
            ComMode = COMM_NO_COMMUNICATION;
            CANSM_COMM_REPORT(ComMode);
            (void)CanIf_SetBaudrate(CANSM_CANIF_CTRLID, CanSM_NetworkInfo[CANSM_NETWORK_HANDLE].savedBDId);
            loopFlag = TRUE;
            break;

        case CANSM_S_CC_STARTED:
            /*SWS_CanSM_00532 SWS_CanSM_00533*/
            CanSM_CanCtrlStateSwitchSeq(CANSM_NETWORK_HANDLE, CANIF_CS_STARTED, CANSM_S_CC_STARTED_WAIT);
            loopFlag = TRUE;
            break;

        case CANSM_S_CC_STARTED_WAIT:
            loopFlag = CanSM_WaitProcess(CANSM_NETWORK_HANDLE, CANSM_S_CC_STARTED);
            break;

        case CANSM_S_CC_START_IND:
            /* no need to protect area here, as the new req is processed nomatter
                form BD_End or full
            */
            CanSM_ExitChangeBaudRate(CANSM_NETWORK_HANDLE);
            break;

        default:
            break;

        }
    }
    while(TRUE == loopFlag);
}
#endif

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: CanSM_SilentComBorProcess
*
* Description:   schdule function to process SilentCom_Bor State
*
* Inputs:        network
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, CANSM_CODE) CanSM_SilentComBorProcess
(
    const NetworkHandleType nwHandle
)
{
    boolean loopFlag;

    do
    {
        loopFlag = FALSE;
        switch(CanSM_NetworkInfo[CANSM_NETWORK_HANDLE].CanSMSubState)
        {
        case CANSM_S_RESTART_CC:
            /*SWS_CanSM_00604 SWS_CanSM_00603*/
            CanSM_CanCtrlStateSwitchSeq(CANSM_NETWORK_HANDLE, CANIF_CS_STARTED, CANSM_S_RESTART_CC_WAIT);
            loopFlag = TRUE;
            break;

        case CANSM_S_RESTART_CC_WAIT:
            loopFlag = CanSM_WaitProcess(CANSM_NETWORK_HANDLE, CANSM_S_RESTART_CC);
            break;

        case CANSM_S_RESTART_CC_IND:
            /*Effect: E_TX_OFF shall do nothing*/
            CanSM_ExitSilentComBor(CANSM_NETWORK_HANDLE);
            break;

        default:
            /* Intentionally Empty */
            break;
        }
    }
    while(TRUE == loopFlag);

}


/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: CanSM_SwitchState
*
* Description:   internal state switch , clear all sw cnt
*
* Inputs:        network
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, CANSM_CODE) CanSM_SwitchState
(
    const NetworkHandleType nwHandle,
    const CanSM_MainStateType state,
    const CanSM_subStateType substate
)
{
    CanSM_NetworkInfo[CANSM_NETWORK_HANDLE].CanSMState = state;
    CanSM_NetworkInfo[CANSM_NETWORK_HANDLE].CanSMSubState = substate;
    CanSM_NetworkInfo[CANSM_NETWORK_HANDLE].durationTime = (uint16)0;
    CanSM_NetworkInfo[CANSM_NETWORK_HANDLE].retryNum = (uint8)0;
    CanSM_NetworkInfo[CANSM_NETWORK_HANDLE].borDurationTime = (uint16)0;
    CanSM_NetworkInfo[CANSM_NETWORK_HANDLE].borEnSureTime = (uint16)0;
    CanSM_NetworkInfo[CANSM_NETWORK_HANDLE].StateChangeFlag = TRUE;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: CanSM_SwitchToSilentSeq
*
* Description:   internal change state to Silentcom sequence
*
* Inputs:        nwHandle
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, CANSM_CODE) CanSM_SwitchToSilentSeq
(
    const NetworkHandleType nwHandle
)
{
    ComM_ModeType ComMode;

    CanSM_SwitchState(CANSM_NETWORK_HANDLE, CANSM_BSM_S_SILENTCOM, CANSM_NO_SUBSTATE);

    /*Effect: E_FULL_TO_SILENT_COM or E_BR_END_SILENT_COM
    SWS_CanSM_00434 SWS_CanSM_00541 SWS_CanSM_00538*/
    CANSM_BSWM_REPORT(nwHandle, CANSM_BSWM_SILENT_COMMUNICATION);
    (void)CanIf_SetPduMode(CANSM_CANIF_CTRLID, CANIF_TX_OFFLINE);
    ComMode = COMM_SILENT_COMMUNICATION;
    CANSM_COMM_REPORT(ComMode);
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: CanSM_SwitchToFullComSeq
*
* Description:   internal change state to fullcom sequence
*
* Inputs:        nwHandle
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, CANSM_CODE) CanSM_SwitchToFullComSeq
(
    const NetworkHandleType nwHandle
)
{
    ComM_ModeType ComMode;

    /*The state change should be put before CanIf_SetPduMode(CANSM_CANIF_CTRLID, CANIF_ONLINE).*/
    CanSM_SwitchState(CANSM_NETWORK_HANDLE, CANSM_BSM_S_FULLCOM, CANSM_S_BUS_OFF_CHECK);

    /*Effect: E_FULL_COM or E_BR_END_FULL_COM or E_SILENT_TO_FULL_COM
    SWS_CanSM_00432 SWS_CanSM_00550*/
#if(STD_ON == CANSM_TXOFFLINEACTIVE_SUPPORT)
    if(TRUE == CanSM_PassiveMode)
    {
        /*SWS_CanSM_00647*/
        (void)CanIf_SetPduMode(CANSM_CANIF_CTRLID, CANIF_TX_OFFLINE_ACTIVE);
    }
    else
#endif
    {
        /*SWS_CanSM_00539*/
        (void)CanIf_SetPduMode(CANSM_CANIF_CTRLID, CANIF_ONLINE);
    }

    /*SWS_CanSM_00435*/
    ComMode = COMM_FULL_COMMUNICATION;
    CANSM_COMM_REPORT(ComMode);

    /*SWS_CanSM_00540*/
    CANSM_BSWM_REPORT(nwHandle, CANSM_BSWM_FULL_COMMUNICATION);
    CanSM_NetworkInfo[CANSM_NETWORK_HANDLE].borCnt = (uint8)0;

}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: CanSM_SwitchToSilentComBorSeq
*
* Description:   internal change state to Silentcom BOR sequence
*
* Inputs:        nwHandle
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, CANSM_CODE) CanSM_SwitchToSilentComBorSeq
(
    const NetworkHandleType nwHandle
)
{
    CanSM_SwitchState(CANSM_NETWORK_HANDLE, CANSM_BSM_S_SILENTCOM_BOR, CANSM_S_RESTART_CC);

    /*Effect: E_BUS_OFF SWS_CanSM_00605*/
    CANSM_DEM_REPORT(CANSM_UESD_NETWORKCFG_INFO[CANSM_NETWORK_HANDLE].BusOffEventId, DEM_EVENT_STATUS_PREFAILED);
}


/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: CanSM_SwitchToPreNoComSeq
*
* Description:   internal start preNoCom
*
* Inputs:        nwHandle
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, CANSM_CODE) CanSM_SwitchToPreNoComSeq
(
    const NetworkHandleType nwHandle
)
{
    /*SWS_CanSM_00436 SWS_CanSM_00437*/
#if((STD_ON == CANSM_PNC_SUPPORT) && (STD_ON == CANSM_CANTRCV_SUPPORT))
    CanSM_SwitchState(CANSM_NETWORK_HANDLE, CANSM_BSM_S_PRE_NOCOM, CANSM_S_PN_CLEAR_WUF);
#else
    CanSM_SwitchState(CANSM_NETWORK_HANDLE, CANSM_BSM_S_PRE_NOCOM, CANSM_S_CC_STOPPED);
#endif

    /*SWS_CanSM_00431 Effect: E_PRE_NOCOM*/
    CANSM_BSWM_REPORT(nwHandle, CANSM_BSWM_NO_COMMUNICATION);

}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: CanSM_ExitPreNoCom
*
* Description:   internal activation when exit from pronoCom
*
* Inputs:        network
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, CANSM_CODE) CanSM_ExitPreNoCom
(
    const NetworkHandleType nwHandle
)
{
    ComM_ModeType ComMode;
    uint8 Trigger = CanSM_TriggerInfo[CANSM_NETWORK_HANDLE];

    if((uint8)0 != (Trigger & CANSM_T_START_WAKEUP_SOURCE))
    {
        SchM_Enter_CanSM_CANSM_EXCLUSIVE_AREA_3();
        CANSM_CLR_TRIGGER(CANSM_NETWORK_HANDLE, CANSM_T_START_WAKEUP_SOURCE);
        SchM_Exit_CanSM_CANSM_EXCLUSIVE_AREA_3();
#if(STD_ON == CANSM_CANTRCV_SUPPORT)
        CanSM_SwitchState(CANSM_NETWORK_HANDLE, CANSM_BSM_S_WUVALIDATION, CANSM_S_TRCV_NORMAL);
#else
        CanSM_SwitchState(CANSM_NETWORK_HANDLE, CANSM_BSM_S_WUVALIDATION, CANSM_S_CC_STOPPED);
#endif
    }
    else
    {
        CanSM_SwitchState(CANSM_NETWORK_HANDLE, CANSM_BSM_S_NOCOM, CANSM_NO_SUBSTATE);

        /*SWS_CanSM_00430 SWS_CanSM_00651 Effect: E_NOCOM*/
        ComMode = COMM_NO_COMMUNICATION;
        CANSM_COMM_REPORT(ComMode);
        /*Dont need to report to bswM*/
    }

}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: CanSM_ExitWUValidation
*
* Description:   internal activation when exit from WUValidation
*
* Inputs:        network
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, CANSM_CODE) CanSM_ExitWUValidation
(
    const NetworkHandleType nwHandle
)
{
    uint8 Trigger = CanSM_TriggerInfo[CANSM_NETWORK_HANDLE];
    uint8 ModeReq = Trigger & CANSM_T_MODE_REQUEST_MASK;
    /*which is priority*/
    if((uint8)0 != (Trigger & CANSM_T_STOP_WAKEUP_SOURCE))
    {
        SchM_Enter_CanSM_CANSM_EXCLUSIVE_AREA_3();
        CANSM_CLR_TRIGGER(CANSM_NETWORK_HANDLE, CANSM_T_STOP_WAKEUP_SOURCE);
        SchM_Exit_CanSM_CANSM_EXCLUSIVE_AREA_3();
        /*little conflict with spec*/
        CanSM_SwitchToPreNoComSeq(CANSM_NETWORK_HANDLE);
    }
    else if(CANSM_T_FULL_COM_MODE_REQUEST == ModeReq)
    {
#if(STD_ON == CANSM_CANTRCV_SUPPORT)
        CanSM_SwitchState(CANSM_NETWORK_HANDLE, CANSM_BSM_S_PRE_FULLCOM, CANSM_S_TRCV_NORMAL);
#else
        CanSM_SwitchState(CANSM_NETWORK_HANDLE, CANSM_BSM_S_PRE_FULLCOM, CANSM_S_CC_STOPPED);
#endif
    }
    else if(CANSM_T_SILENT_COM_MODE_REQUEST == ModeReq)
    {
        /*Illegal request*/
        SchM_Enter_CanSM_CANSM_EXCLUSIVE_AREA_3();
        CANSM_CLEAR_MODE_REQUEST(CANSM_NETWORK_HANDLE);
        SchM_Exit_CanSM_CANSM_EXCLUSIVE_AREA_3();
    }
    else
    {
        /*stay in WUVALIDATION until we get T_FULL_COM or T_STOP_WKUP_SRC*/
    }

}


/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: CanSM_ExitSilentComBor
*
* Description:   internal activation when exit from SilentCom_Bor
*
* Inputs:        network
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, CANSM_CODE) CanSM_ExitSilentComBor
(
    const NetworkHandleType nwHandle
)
{
    uint8 ModeReq = CanSM_TriggerInfo[CANSM_NETWORK_HANDLE] & CANSM_T_MODE_REQUEST_MASK;

    if(CANSM_T_NO_COM_MODE_REQUEST == ModeReq)
    {
        /* SilentCom_Bor -> NoCom, CanSM_SwitchToPreNoComSeq */
        CanSM_SwitchToPreNoComSeq(CANSM_NETWORK_HANDLE);
    }
    else
    {
        /* SilentCom_Bor -> Silent */
        CanSM_SwitchState(CANSM_NETWORK_HANDLE, CANSM_BSM_S_SILENTCOM, CANSM_NO_SUBSTATE);
    }

}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: CanSM_TriggerProcess
*
* Description:   Used in mainfunction, collect all request from CommRequest,Busoff and ChengeBD
*                analay them and init the state/substate, further process will be done in mainfuntion
*
* Inputs:        network
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, CANSM_CODE) CanSM_TriggerProcess
(
    const NetworkHandleType nwHandle
)
{
    /*
      when get into mainfuntion, state can only be
      NOT_INITIALIZED
      NoCom
      FullCom-NoBusOff
      FullCom-CheckBusoff
      FullCom-txOff
      Silent

      Any Wait state
      Any WaitIndication State
    */
    uint8 Trigger;
    uint8 ModeReq;
    ComM_ModeType ComMode;

    /* save  trigger information in local state */
    SchM_Enter_CanSM_CANSM_EXCLUSIVE_AREA_3();
    Trigger = CanSM_TriggerInfo[CANSM_NETWORK_HANDLE];
    ModeReq = CanSM_TriggerInfo[CANSM_NETWORK_HANDLE] & CANSM_T_MODE_REQUEST_MASK;
    SchM_Exit_CanSM_CANSM_EXCLUSIVE_AREA_3();

    switch(CanSM_NetworkInfo[CANSM_NETWORK_HANDLE].CanSMState)
    {
    case CANSM_BSM_S_NOT_INITALIZED:
        if((uint8)0 != (Trigger & CANSM_T_CANSM_INIT))
        {
            SchM_Enter_CanSM_CANSM_EXCLUSIVE_AREA_3();
            CANSM_CLR_TRIGGER(CANSM_NETWORK_HANDLE, CANSM_T_CANSM_INIT);
            SchM_Exit_CanSM_CANSM_EXCLUSIVE_AREA_3();
            /*SWS_CanSM_00436 SWS_CanSM_00437*/
#if((STD_ON == CANSM_PNC_SUPPORT) && (STD_ON == CANSM_CANTRCV_SUPPORT))
            CanSM_SwitchState(CANSM_NETWORK_HANDLE, CANSM_BSM_S_PRE_NOCOM, CANSM_S_PN_CLEAR_WUF);
#else
            CanSM_SwitchState(CANSM_NETWORK_HANDLE, CANSM_BSM_S_PRE_NOCOM, CANSM_S_CC_STOPPED);
#endif
        }
        else
        {
            /*CanSM_MainFunction run before CanSM_Init, ERROR*/
            CANSM_DET_REPORT_ERROR(CANSM_MAINFUNCTION_SERVICE_ID, CANSM_E_INVALID_NETWORK_STATE);
        }
        break;

    case CANSM_BSM_S_FULLCOM:
        if(CANSM_T_FULL_COM_MODE_REQUEST == ModeReq)
        {
            SchM_Enter_CanSM_CANSM_EXCLUSIVE_AREA_3();
            CANSM_CLEAR_MODE_REQUEST(CANSM_NETWORK_HANDLE);
            SchM_Exit_CanSM_CANSM_EXCLUSIVE_AREA_3();
        }
        else if(CANSM_T_NO_COM_MODE_REQUEST == ModeReq)
        {
            /*full -> No*/
            CanSM_SwitchToPreNoComSeq(CANSM_NETWORK_HANDLE);
        }
        else if(CANSM_T_SILENT_COM_MODE_REQUEST == ModeReq)
        {
            /*full -> silent */
            CanSM_SwitchToSilentSeq(CANSM_NETWORK_HANDLE);
        }
        else
            /* if changeBd is Request, changeBd will be process first */
#if(STD_ON == CANSM_SET_BAUDRATE_API)
            if((CANSM_S_NO_BUS_OFF == CanSM_NetworkInfo[CANSM_NETWORK_HANDLE].CanSMSubState)
                && (0 != (Trigger & CANSM_T_CHANGE_BR_REQUEST)))
        {
            SchM_Enter_CanSM_CANSM_EXCLUSIVE_AREA_3();
            CANSM_CLR_TRIGGER(CANSM_NETWORK_HANDLE, CANSM_T_CHANGE_BR_REQUEST);
            SchM_Exit_CanSM_CANSM_EXCLUSIVE_AREA_3();
            /*CanSM_StartChangeBDSeq*/
            CanSM_SwitchState(CANSM_NETWORK_HANDLE, CANSM_BSM_S_CHANGE_BAUDRATE, CANSM_S_CHANGE_BR_SYNC);
            /* Effect: E_CHANGE_BR_BSWM_MODE SWS_CanSM_00528*/
            CANSM_BSWM_REPORT(nwHandle, CANSM_BSWM_CHANGE_BAUDRATE);
        }
        else
#endif
        if((CANSM_S_NO_BUS_OFF == CanSM_NetworkInfo[CANSM_NETWORK_HANDLE].CanSMSubState)
            || (CANSM_S_BUS_OFF_CHECK == CanSM_NetworkInfo[CANSM_NETWORK_HANDLE].CanSMSubState))
        {
            if((uint8)0 != (Trigger & CANSM_T_BUS_OFF))
            {
                SchM_Enter_CanSM_CANSM_EXCLUSIVE_AREA_3();
                CANSM_CLR_TRIGGER(CANSM_NETWORK_HANDLE, CANSM_T_BUS_OFF);
                SchM_Exit_CanSM_CANSM_EXCLUSIVE_AREA_3();
                /* do restart CC */
                CanSM_SwitchState(CANSM_NETWORK_HANDLE, CANSM_BSM_S_FULLCOM, CANSM_S_RESTART_CC);
                /*SWS_CanSM_00500*/
                /*Effect: E_BUS_OFF, SWS_CanSM_00508 SWS_CanSM_00521 SWS_CanSM_00522 SWS_CanSM_00638*/
                /*Geely BaseTech: First time to start recovery, report to app*/
                if(CanSM_NetworkInfo[CANSM_NETWORK_HANDLE].borCnt == 0)
                {
                    CanSM_EnterBorL1_Indication(CANSM_NETWORK_HANDLE);
                }
                CANSM_BSWM_REPORT(nwHandle, CANSM_BSWM_BUS_OFF);
                ComMode = COMM_SILENT_COMMUNICATION;
                CANSM_COMM_REPORT(ComMode);
                CANSM_DEM_REPORT(CANSM_UESD_NETWORKCFG_INFO[CANSM_NETWORK_HANDLE].BusOffEventId, DEM_EVENT_STATUS_PREFAILED);
            }
            else
            {
            }
        }
        else
        {
            /* else ignore busoff and req_Full continue to do the bor*/
        }
        break;

    case CANSM_BSM_S_NOCOM:
        /* in NoCom, changeBD, BusOff is ignored*/
        CANSM_CLR_TRIGGER(CANSM_NETWORK_HANDLE, CANSM_T_CHANGE_BR_REQUEST | CANSM_T_BUS_OFF);
        if((CANSM_T_NO_COM_MODE_REQUEST == ModeReq) || (CANSM_T_SILENT_COM_MODE_REQUEST == ModeReq))
        {
            SchM_Enter_CanSM_CANSM_EXCLUSIVE_AREA_3();
            CANSM_CLEAR_MODE_REQUEST(CANSM_NETWORK_HANDLE);
            SchM_Exit_CanSM_CANSM_EXCLUSIVE_AREA_3();
        }
        if((uint8)0 != (Trigger & CANSM_T_START_WAKEUP_SOURCE))
        {
            SchM_Enter_CanSM_CANSM_EXCLUSIVE_AREA_3();
            CANSM_CLR_TRIGGER(CANSM_NETWORK_HANDLE, CANSM_T_START_WAKEUP_SOURCE);
            SchM_Exit_CanSM_CANSM_EXCLUSIVE_AREA_3();
#if(STD_ON == CANSM_CANTRCV_SUPPORT)
            CanSM_SwitchState(CANSM_NETWORK_HANDLE, CANSM_BSM_S_WUVALIDATION, CANSM_S_TRCV_NORMAL);
#else
            CanSM_SwitchState(CANSM_NETWORK_HANDLE, CANSM_BSM_S_WUVALIDATION, CANSM_S_CC_STOPPED);
#endif
        }
        else if(CANSM_T_FULL_COM_MODE_REQUEST == ModeReq)
        {
            /* startPreFullCom*/
#if(STD_ON == CANSM_CANTRCV_SUPPORT)
            CanSM_SwitchState(CANSM_NETWORK_HANDLE, CANSM_BSM_S_PRE_FULLCOM, CANSM_S_TRCV_NORMAL);
#else
            CanSM_SwitchState(CANSM_NETWORK_HANDLE, CANSM_BSM_S_PRE_FULLCOM, CANSM_S_CC_STOPPED);
#endif
        }
        else
        {
            /* Intentionally Empty */
        }
        break;

    case CANSM_BSM_S_SILENTCOM:
        /* in Silent, changeBD is ignored*/
        if(CANSM_T_SILENT_COM_MODE_REQUEST == ModeReq)
        {
            SchM_Enter_CanSM_CANSM_EXCLUSIVE_AREA_3();
            CANSM_CLEAR_MODE_REQUEST(CANSM_NETWORK_HANDLE);
            SchM_Exit_CanSM_CANSM_EXCLUSIVE_AREA_3();
        }
        if(CANSM_T_FULL_COM_MODE_REQUEST == ModeReq)
        {
            /* Silent->Full, Syn Switch*/
            CanSM_SwitchToFullComSeq(CANSM_NETWORK_HANDLE);/*SWS_CanSM_00550*/
        }
        else if(CANSM_T_NO_COM_MODE_REQUEST == ModeReq)
        {
            /* Silent -> NoCom, CanSM_SwitchToPreNoComSeq */
            CanSM_SwitchToPreNoComSeq(CANSM_NETWORK_HANDLE);
        }
        else if((uint8)0 != (Trigger & CANSM_T_BUS_OFF))
        {
            SchM_Enter_CanSM_CANSM_EXCLUSIVE_AREA_3();
            CANSM_CLR_TRIGGER(CANSM_NETWORK_HANDLE, CANSM_T_BUS_OFF);
            SchM_Exit_CanSM_CANSM_EXCLUSIVE_AREA_3();
            /* Busoff */
            CanSM_SwitchToSilentComBorSeq(CANSM_NETWORK_HANDLE);
        }
        else if((uint8)0 != (Trigger & CANSM_T_CHANGE_BR_REQUEST))
        {
            CANSM_DET_REPORT_ERROR(CANSM_MAINFUNCTION_SERVICE_ID, CANSM_E_INVALID_COMM_REQUEST);
        }
        else
        {
            /* Intentionally Empty */
        }
        break;

#if(STD_ON == CANSM_SET_BAUDRATE_API)
    case CANSM_BSM_S_CHANGE_BAUDRATE:
        break;
#endif

    default:
        /* Intentionally Empty */
        break;

    }

}


/*******************************************************************************
*   Public Functions
*******************************************************************************/

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: CanSM_Init  SWS_CanSM_00023
*
* Description:   This service initializes the CanSM module.
*
* Inputs:        ConfigPtr: Pointer to configuration parameter set,
*                           used e.g. for post build parameters
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, CANSM_CODE) CanSM_Init
(
    P2CONST(CanSM_ConfigType, AUTOMATIC, CANSM_APPL_CONST) ConfigPtr
)
{
#if(STD_OFF == CANSM_SINGLE_NETWORK_OPTIMIZE)
    NetworkHandleType nwHandle;
#endif


#if(CANSM_CONFIG_VARIANTS == STD_CONFIG_VARIANTS_POSTBUILD)
    if(NULL_PTR == ConfigPtr)
    {
        /*SWS_CanSM_00179*/
        CANSM_DET_REPORT_ERROR(CANSM_INIT_SERVICE_ID, CANSM_E_PARAM_POINTER);
    }
    else
#else
    (void)ConfigPtr;
#endif
    {
#if(CANSM_CONFIG_VARIANTS == STD_CONFIG_VARIANTS_POSTBUILD)
        CanSM_ConfigSet = ConfigPtr;
#endif

#if(STD_OFF == CANSM_SINGLE_NETWORK_OPTIMIZE)
        for (nwHandle = 0; nwHandle < CANSM_USED_NETWORK_NUM; nwHandle++)
#endif
        {
            CANSM_CLEAR_ALL_TRIGGER(CANSM_NETWORK_HANDLE);
            CanSM_NetworkInfo[CANSM_NETWORK_HANDLE].ComMMode = COMM_NO_COMMUNICATION;
            /*SWS_CanSM_00424*/
            CanSM_SwitchState(CANSM_NETWORK_HANDLE, CANSM_BSM_S_NOT_INITALIZED, CANSM_NO_SUBSTATE);
            /*SWS_CanSM_00423*/
            CANSM_SET_TRIGGER(CANSM_NETWORK_HANDLE, CANSM_T_CANSM_INIT);
        }
        CanSM_InitStatus = CANSM_INITED;
    }
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: CanSM_RequestComMode  SWS_CanSM_00062
*
* Description:   This service shall change the communication mode of a CAN network to the
*                requested one
*
* Inputs:        network Handle of destined communication network for request
*                ComM_Mode Requested communication mode
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, CANSM_CODE) CanSM_RequestComMode
(
    NetworkHandleType network,
    ComM_ModeType ComM_Mode
)
{
    Std_ReturnType ret = E_NOT_OK;
    NetworkHandleType nwHandle;

    /*SWS_CanSM_00278 SWS_CanSM_00369 SWS_CanSM_00182*/
    if(CANSM_INITED != CanSM_InitStatus)
    {
        /*SWS_CanSM_00555 SWS_CanSM_00184*/
        CANSM_DET_REPORT_ERROR(CANSM_REQUESTCOMMODE_SERVICE_ID, CANSM_E_UNINIT);
    }
    else if(network >= CANSM_MAX_NETWORK_NUM)
    {
        /*SWS_CanSM_00370 SWS_CanSM_00183*/
        CANSM_DET_REPORT_ERROR(CANSM_REQUESTCOMMODE_SERVICE_ID, CANSM_E_INVALID_NETWORK_HANDLE);
    }
    else
    {
        nwHandle = network;      
        SchM_Enter_CanSM_CANSM_EXCLUSIVE_AREA_0();
        /*  SWS_CanSM_00427 SWS_CanSM_00429
        SWS_CanSM_00375 SWS_CanSM_00376 SWS_CanSM_00377*/
        CANSM_CLEAR_MODE_REQUEST(CANSM_NETWORK_HANDLE);/*clear first*/

#if(STD_ON == CANSM_NOREQ_IN_WAIT)
        /* dont accept new request when last state switch is not finish yet
            but in changeBd can accept new req
        */
        if((CanSM_NetworkInfo[CANSM_NETWORK_HANDLE].CanSMState > CANSM_BSM_S_CHANGE_BAUDRATE)
                || ((CANSM_BSM_S_FULLCOM == CanSM_NetworkInfo[CANSM_NETWORK_HANDLE].CanSMState)
                    && (CanSM_NetworkInfo[CANSM_NETWORK_HANDLE].CanSMSubState > CANSM_S_TX_OFF)))
        {
            /* last canif api call is not indicated , deny this req SWS_CanSM_00395
                to avoid err state switch
            */
            CANSM_DET_REPORT_ERROR(CANSM_REQUESTCOMMODE_SERVICE_ID, CANSM_E_WAIT_MODE_INDICATION);
        }
        else
#endif
        {
            /*SWS_CanSM_00635*/
            if(COMM_NO_COMMUNICATION == ComM_Mode)
            {
#if(STD_OFF == CANSM_LIGHTNM_SUPPORT)
                if(CANSM_BSM_S_FULLCOM == CanSM_NetworkInfo[CANSM_NETWORK_HANDLE].CanSMState)
                {
                    /*SWS_CanSM_00554*/
                    CANSM_SET_TRIGGER(CANSM_NETWORK_HANDLE, CANSM_T_SILENT_COM_MODE_REQUEST);
                }
                else
#endif
                {
                    /*SWS_CanSM_00426*/
                    CANSM_SET_TRIGGER(CANSM_NETWORK_HANDLE, CANSM_T_NO_COM_MODE_REQUEST);
                }
                ret = E_OK;
            }
            else if(COMM_FULL_COMMUNICATION == ComM_Mode)
            {
                /*SWS_CanSM_00425*/
                CANSM_SET_TRIGGER(CANSM_NETWORK_HANDLE, CANSM_T_FULL_COM_MODE_REQUEST);
                ret = E_OK;
            }
            else if(COMM_SILENT_COMMUNICATION == ComM_Mode)
            {
                /* nocom/preNoCom/PreFullCom -> silent is invalid CANSM402 CANSM403
                busoff->silent is allowed as used also need to sleep when busoff happened
                */
                if((CANSM_BSM_S_NOCOM == CanSM_NetworkInfo[CANSM_NETWORK_HANDLE].CanSMState)\
                    || (CANSM_BSM_S_PRE_NOCOM == CanSM_NetworkInfo[CANSM_NETWORK_HANDLE].CanSMState)\
                    || (CANSM_BSM_S_PRE_FULLCOM == CanSM_NetworkInfo[CANSM_NETWORK_HANDLE].CanSMState))
                {
                    CANSM_DET_REPORT_ERROR(CANSM_REQUESTCOMMODE_SERVICE_ID, CANSM_E_INVALID_COMM_REQUEST);
                }
                else
                {
                    /*SWS_CanSM_00499*/
                    CANSM_SET_TRIGGER(CANSM_NETWORK_HANDLE, CANSM_T_SILENT_COM_MODE_REQUEST);
                    ret = E_OK;
                }
            }
            else
            {
                CANSM_DET_REPORT_ERROR(CANSM_REQUESTCOMMODE_SERVICE_ID, CANSM_E_INVALID_COMM_REQUEST);
            }

        }

        SchM_Exit_CanSM_CANSM_EXCLUSIVE_AREA_0();
        
    }

    return ret;
}


/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: CanSM_GetCurrentComMode  SWS_CanSM_00063
*
* Description:   This service shall put out the current communication mode of a CAN network.
*
* Inputs:        network Network handle, whose current communication mode shall be put out
*
* Outputs:       ComM_ModePtr Network handle, whose current communication mode shall be put out
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, CANSM_CODE) CanSM_GetCurrentComMode
(
    NetworkHandleType  network,
    P2VAR(ComM_ModeType, AUTOMATIC, CANSM_APPL_DATA) ComM_ModePtr
)
{
    Std_ReturnType ret = E_NOT_OK;
    NetworkHandleType nwHandle;

    if(CANSM_INITED != CanSM_InitStatus)
    {
        /*SWS_CanSM_00282 SWS_CanSM_00188*/
        CANSM_DET_REPORT_ERROR(CANSM_GETCURRENTCOMMODE_SERVICE_ID, CANSM_E_UNINIT);
    }
    else if(NULL_PTR == ComM_ModePtr)
    {
        /*SWS_CanSM_00360*/
        CANSM_DET_REPORT_ERROR(CANSM_GETCURRENTCOMMODE_SERVICE_ID, CANSM_E_PARAM_POINTER);
    }
    else if(network >= CANSM_MAX_NETWORK_NUM)
    {
        /*SWS_CanSM_00371 SWS_CanSM_00372 SWS_CanSM_00187*/
        CANSM_DET_REPORT_ERROR(CANSM_GETCURRENTCOMMODE_SERVICE_ID, CANSM_E_INVALID_NETWORK_HANDLE);
    }
    else
    {
        nwHandle = network; 
        /*SWS_CanSM_00186*/
        *ComM_ModePtr = CanSM_NetworkInfo[CANSM_NETWORK_HANDLE].ComMMode;
        ret = E_OK;
        
    }

    return ret;
}



/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: CanSM_MainFunction  SWS_CanSM_00065
*
* Description:   Scheduled function of the CanSM
*
* Inputs:        None
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, CANSM_CODE) CanSM_MainFunction
(
    void
)
{
#if(STD_OFF == CANSM_SINGLE_NETWORK_OPTIMIZE)
    NetworkHandleType nwHandle;
#endif


    if(CANSM_INITED != CanSM_InitStatus)
    {
        CANSM_DET_REPORT_ERROR(CANSM_MAINFUNCTION_SERVICE_ID, CANSM_E_UNINIT);
    }
    else
    {

#if(STD_OFF == CANSM_SINGLE_NETWORK_OPTIMIZE)
        for (nwHandle = 0; nwHandle < CANSM_USED_NETWORK_NUM; nwHandle++)
#endif
        {
            /*SWS_CanSM_00167 */
            /* Request Process */
            if((uint8)0 != CanSM_TriggerInfo[CANSM_NETWORK_HANDLE])
            {
                CanSM_TriggerProcess(CANSM_NETWORK_HANDLE);
            }

            /*state substate process*/
            if((CanSM_NetworkInfo[CANSM_NETWORK_HANDLE].CanSMState > CANSM_BSM_S_FULLCOM)
                    || ((CanSM_NetworkInfo[CANSM_NETWORK_HANDLE].CanSMState == CANSM_BSM_S_FULLCOM)
                        && (CanSM_NetworkInfo[CANSM_NETWORK_HANDLE].CanSMSubState > CANSM_S_NO_BUS_OFF)))
            {
                do
                {
                    CanSM_NetworkInfo[CANSM_NETWORK_HANDLE].StateChangeFlag = FALSE;
                    switch (CanSM_NetworkInfo[CANSM_NETWORK_HANDLE].CanSMState)
                    {
                    case CANSM_BSM_S_PRE_NOCOM:
                        CanSM_PreNoComProcess(CANSM_NETWORK_HANDLE);
                        break;
                    case CANSM_BSM_S_WUVALIDATION:
                        CanSM_WUValidationProcess(CANSM_NETWORK_HANDLE);
                        break;
                    case CANSM_BSM_S_PRE_FULLCOM:
                        CanSM_PreFullComProcess(CANSM_NETWORK_HANDLE);
                        break;
                    case CANSM_BSM_S_FULLCOM:
                        CanSM_FullComProcess(CANSM_NETWORK_HANDLE);
                        break;
#if(STD_ON == CANSM_SET_BAUDRATE_API)
                    case CANSM_BSM_S_CHANGE_BAUDRATE:
                        CanSM_ChangeBDProcess(CANSM_NETWORK_HANDLE);
                        break;
#endif
                    case CANSM_BSM_S_SILENTCOM_BOR:
                        CanSM_SilentComBorProcess(CANSM_NETWORK_HANDLE);
                        break;
                    default:
                        CanSM_TriggerProcess(CANSM_NETWORK_HANDLE);
                        break;
                    }
                }while(TRUE == CanSM_NetworkInfo[CANSM_NETWORK_HANDLE].StateChangeFlag);
            }
        }
    }
}



/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: CanSM_StartWakeupSource  SWS_CanSM_00609
*
* Description:   This function shall be called by EcuM when a wakeup source shall be started.
*
* Inputs:        network Affected CAN network
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, CANSM_CODE) CanSM_StartWakeupSource
(
    NetworkHandleType  network
)
{
    Std_ReturnType ret = E_NOT_OK;
    NetworkHandleType nwHandle;

    if(CANSM_INITED != CanSM_InitStatus)
    {
        /*SWS_CanSM_00611 SWS_CanSM_00617*/
        CANSM_DET_REPORT_ERROR(CANSM_STARTWAKEUPSOURCE_SERVICE_ID, CANSM_E_UNINIT);
    }
    else if(network >= CANSM_MAX_NETWORK_NUM)
    {
        /*SWS_CanSM_00612 SWS_CanSM_00613*/
        CANSM_DET_REPORT_ERROR(CANSM_STARTWAKEUPSOURCE_SERVICE_ID, CANSM_E_INVALID_NETWORK_HANDLE);
    }
    else
    {
        nwHandle = network;   
        /*SWS_CanSM_00607 SWS_CanSM_00616*/
        if((CanSM_NetworkInfo[CANSM_NETWORK_HANDLE].CanSMState == CANSM_BSM_S_NOCOM) 
            || (CanSM_NetworkInfo[CANSM_NETWORK_HANDLE].CanSMState == CANSM_BSM_S_PRE_NOCOM))
        { 
            CANSM_SET_TRIGGER(CANSM_NETWORK_HANDLE, CANSM_T_START_WAKEUP_SOURCE);
        }
        ret = E_OK;
        
    }

    return ret;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: CanSM_StopWakeupSource  SWS_CanSM_00610
*
* Description:   This function shall be called by EcuM when a wakeup source shall be stopped
*
* Inputs:        network Affected CAN network
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, CANSM_CODE) CanSM_StopWakeupSource
(
    NetworkHandleType  network
)
{
    Std_ReturnType ret = E_NOT_OK;
    NetworkHandleType nwHandle;

    if(CANSM_INITED != CanSM_InitStatus)
    {
        /*SWS_CanSM_00618 SWS_CanSM_00619*/
        CANSM_DET_REPORT_ERROR(CANSM_STOPWAKEUPSOURCE_SERVICE_ID, CANSM_E_UNINIT);
    }
    else if(network >= CANSM_MAX_NETWORK_NUM)
    {
        /*SWS_CanSM_00620 SWS_CanSM_00621*/
        CANSM_DET_REPORT_ERROR(CANSM_STOPWAKEUPSOURCE_SERVICE_ID, CANSM_E_INVALID_NETWORK_HANDLE);
    }
    else
    {
        nwHandle = network;
        /*SWS_CanSM_00608 SWS_CanSM_00622*/
        /* In common, StopWakeupSource happened in WUVALIDATION state
                otherwise, the indication will be ignored
            */
        if(CanSM_NetworkInfo[CANSM_NETWORK_HANDLE].CanSMState == CANSM_BSM_S_WUVALIDATION)               
        {
            CANSM_SET_TRIGGER(CANSM_NETWORK_HANDLE, CANSM_T_STOP_WAKEUP_SOURCE);
        }
        ret = E_OK;
        
    }

    return ret;
}


/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: CanSM_ControllerBusOff  SWS_CanSM_00064
*
* Description:   This callback function notifies the CanSM about a bus-off event on a certain CAN
*                  controller, which needs to be considered with the specified bus-off recovery
*                  handling for the impacted CAN network.
*
* Inputs:        ControllerId CAN controller, which detected a bus-off event
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, CANSM_CODE) CanSM_ControllerBusOff
(
    uint8 ControllerId
)
{
    NetworkHandleType nwHandle;

    if(CANSM_INITED != CanSM_InitStatus)
    {
        /*SWS_CanSM_00190*/
        CANSM_DET_REPORT_ERROR(CANSM_CONTROLLERBUSOFF_SERVICE_ID, CANSM_E_UNINIT);
    }
    else
    {
        nwHandle = CanSM_GetNetWorkHandleFromCtrlId(ControllerId);
        if(nwHandle >= CANSM_MAX_NETWORK_NUM)
        {
            /*SWS_CanSM_00189*/
            CANSM_DET_REPORT_ERROR(CANSM_CONTROLLERBUSOFF_SERVICE_ID, CANSM_E_PARAM_CONTROLLER);
        }
        else
        {
            SchM_Enter_CanSM_CANSM_EXCLUSIVE_AREA_2();
            /* ONLY SET BUSOFF WHEN IN FULL MODE SWS_CanSM_00235*/
            if(CANSM_BSM_S_FULLCOM == CanSM_NetworkInfo[CANSM_NETWORK_HANDLE].CanSMState)
            {
                if((CANSM_S_BUS_OFF_CHECK == CanSM_NetworkInfo[CANSM_NETWORK_HANDLE].CanSMSubState)
                        || (CANSM_S_NO_BUS_OFF == CanSM_NetworkInfo[CANSM_NETWORK_HANDLE].CanSMSubState))
                {
                    /*SWS_CanSM_00606 SWS_CanSM_00500*/
                    CANSM_SET_TRIGGER(CANSM_NETWORK_HANDLE, CANSM_T_BUS_OFF);
#if(STD_ON == CANSM_OSEKNM_SUPPORT)
                    if(COMSTACK_INVALID_NETWORK_HANDLE != CANSM_UESD_NETWORKCFG_INFO[CANSM_NETWORK_HANDLE].OsekNmHandle)
                    {
                        OsekNm_BusOff(CANSM_UESD_NETWORKCFG_INFO[CANSM_NETWORK_HANDLE].OsekNmHandle);
                    }
#endif
                }
                else
                {
                    /*Det*/
                    CANSM_DET_REPORT_ERROR(CANSM_CONTROLLERBUSOFF_SERVICE_ID, CANSM_E_INVALID_NETWORK_STATE);
                }
            }
            if(CANSM_BSM_S_SILENTCOM == CanSM_NetworkInfo[CANSM_NETWORK_HANDLE].CanSMState)
            {
                CANSM_SET_TRIGGER(CANSM_NETWORK_HANDLE, CANSM_T_BUS_OFF);
            }
            SchM_Exit_CanSM_CANSM_EXCLUSIVE_AREA_2();
        }
    }

}



/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: CanSM_ControllerModeIndication  SWS_CanSM_00396
*
* Description:   This callback shall notify the CanSM module about a CAN controller mode change
*
* Inputs:        ControllerId CAN controller, whose mode has changed
*                ControllerMode Notified CAN controller mode
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, CANSM_CODE) CanSM_ControllerModeIndication
(
    uint8 ControllerId,
    CanIf_ControllerModeType ControllerMode
)
{
    NetworkHandleType nwHandle;


    if(CANSM_INITED != CanSM_InitStatus)
    {
        /*SWS_CanSM_00398*/
        CANSM_DET_REPORT_ERROR(CANSM_CTRLMODEIND_SERVICE_ID, CANSM_E_UNINIT);
    }
    else
    {
        nwHandle = CanSM_GetNetWorkHandleFromCtrlId(ControllerId);
        if(nwHandle >= CANSM_MAX_NETWORK_NUM)
        {
            /*SWS_CanSM_00397*/
            CANSM_DET_REPORT_ERROR(CANSM_CTRLMODEIND_SERVICE_ID, CANSM_E_PARAM_CONTROLLER);
        }
        else
        {
            /* In common, Indication can only happened in wait state
               if the substate is not wait, the indication will be ignored
            */
            if(CanSM_NetworkInfo[CANSM_NETWORK_HANDLE].CanSMSubState >= CANSM_S_CC_STOPPED_WAIT)
            {
                /* here only change state, the process will be done in next main task */
                SchM_Enter_CanSM_CANSM_EXCLUSIVE_AREA_4();
                switch(ControllerMode)
                {
                case CANIF_CS_STOPPED:
                    /*SWS_CanSM_00444 SWS_CanSM_00466 SWS_CanSM_00629 SWS_CanSM_00489 SWS_CanSM_00526*/
                    CanSM_NetworkInfo[CANSM_NETWORK_HANDLE].CanSMSubState = CANSM_S_CC_STOPPED_IND;
                    break;

                case CANIF_CS_STARTED:
                    if(CANSM_S_CC_STARTED_WAIT == CanSM_NetworkInfo[CANSM_NETWORK_HANDLE].CanSMSubState)
                    {
                        /*SWS_CanSM_00633 SWS_CanSM_00493 SWS_CanSM_00534*/
                        CanSM_NetworkInfo[CANSM_NETWORK_HANDLE].CanSMSubState = CANSM_S_CC_START_IND;
                    }
                    else if(CANSM_S_RESTART_CC_WAIT == CanSM_NetworkInfo[CANSM_NETWORK_HANDLE].CanSMSubState)
                    {
                        /*SWS_CanSM_00511 SWS_CanSM_00600*/
                        CanSM_NetworkInfo[CANSM_NETWORK_HANDLE].CanSMSubState = CANSM_S_RESTART_CC_IND;
                    }
                    else
                    {
                        /* Intentionally Empty */
                    }
                    break;

                case CANIF_CS_SLEEP:
                    /*SWS_CanSM_00470*/
                    CanSM_NetworkInfo[CANSM_NETWORK_HANDLE].CanSMSubState = CANSM_S_CC_SLEEP_IND;
                    break;

                default:
                    /* Intentionally Empty */
                    break;
                }
                SchM_Exit_CanSM_CANSM_EXCLUSIVE_AREA_4();
            }
        }
    }
}



#if(STD_ON == CANSM_CANTRCV_SUPPORT)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: CanSM_TransceiverModeIndication  SWS_CanSM_00399
*
* Description:   This callback shall notify the CanSM module about a CAN transceiver mode change
*
* Inputs:        TransceiverId CAN transceiver, whose mode has changed
*                TransceiverMode Notified CAN transceiver mode
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, CANSM_CODE) CanSM_TransceiverModeIndication
(
    uint8 TransceiverId,
    CanTrcv_TrcvModeType TransceiverMode
)
{
    NetworkHandleType nwHandle;

    if(CANSM_INITED != CanSM_InitStatus)
    {
        /*SWS_CanSM_00401*/
        CANSM_DET_REPORT_ERROR(CANSM_TRCVMODEIND_SERVICE_ID, CANSM_E_UNINIT);
    }
    else
    {
        nwHandle = CanSM_GetNetWorkHandleFromTrcvId(TransceiverId);
        if(nwHandle >= CANSM_MAX_NETWORK_NUM)
        {
            /*SWS_CanSM_00400*/
            CANSM_DET_REPORT_ERROR(CANSM_TRCVMODEIND_SERVICE_ID, CANSM_E_PARAM_TRANSCEIVER);
        }
        else
        {
            /* In common, Indication can only happened in wait state
               if the substate is not wait, the indication will be ignored
            */
            if(CanSM_NetworkInfo[CANSM_NETWORK_HANDLE].CanSMSubState >= CANSM_S_CC_STOPPED_WAIT)
            {
                /* here only change state, the process will be done in next main task */
                SchM_Enter_CanSM_CANSM_EXCLUSIVE_AREA_4();
                switch(TransceiverMode)
                {
                case CANTRCV_TRCVMODE_NORMAL:
                    /*SWS_CanSM_00448 SWS_CanSM_00474 SWS_CanSM_00625 SWS_CanSM_00485*/
                    CanSM_NetworkInfo[CANSM_NETWORK_HANDLE].CanSMSubState = CANSM_S_TRCV_NORMAL_IND;
                    break;
                case CANTRCV_TRCVMODE_STANDBY:
                    /*SWS_CanSM_00478*/
                    CanSM_NetworkInfo[CANSM_NETWORK_HANDLE].CanSMSubState = CANSM_S_TRCV_STANDBY_IND;
                    break;
                case CANTRCV_TRCVMODE_SLEEP:
                    break;
                default:
                    break;
                }
                SchM_Exit_CanSM_CANSM_EXCLUSIVE_AREA_4();
            }
        }
    }
}

#endif/*#if(STD_ON == CANSM_CANTRCV_SUPPORT)*/



#if(STD_ON == CANSM_PNC_SUPPORT)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: CanSM_TxTimeoutException  SWS_CanSM_00410
*
* Description:   This function shall notify the CanSM module, that the CanNm has detected for the
*                 affected partial CAN network a tx timeout exception, which shall be recovered by
*                 the CanSM module with a transition to no communication and back to the
*                 requested communication mode again.
*
* Inputs:        Channel Affected CAN network
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, CANSM_CODE) CanSM_TxTimeoutException
(
    NetworkHandleType Channel
)
{
    NetworkHandleType nwHandle;


    if(CANSM_INITED != CanSM_InitStatus)
    {
        /*SWS_CanSM_00411*/
        CANSM_DET_REPORT_ERROR(CANSM_TXTIMEOUTEX_SERVICE_ID, CANSM_E_UNINIT);
    }
    else if (Channel >= CANSM_MAX_NETWORK_NUM)
    {
        /*SWS_CanSM_00412*/
        CANSM_DET_REPORT_ERROR(CANSM_TXTIMEOUTEX_SERVICE_ID, CANSM_E_INVALID_NETWORK_HANDLE);
    }
    else
    {
        nwHandle = Channel;
        if((CanSM_NetworkInfo[CANSM_NETWORK_HANDLE].CanSMState == CANSM_BSM_S_FULLCOM)
                && (CanSM_NetworkInfo[CANSM_NETWORK_HANDLE].CanSMSubState == CANSM_S_NO_BUS_OFF))
        {
            /*SWS_CanSM_00584*/
            SchM_Enter_CanSM_CANSM_EXCLUSIVE_AREA_4();
            CanSM_NetworkInfo[CANSM_NETWORK_HANDLE].CanSMSubState = CANSM_S_TX_TIMEOUT_EXCEPTION;
            SchM_Exit_CanSM_CANSM_EXCLUSIVE_AREA_4();
        }
        
    }
}
#if(STD_ON == CANSM_CANTRCV_SUPPORT)

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: CanSM_ClearTrcvWufFlagIndication  SWS_CanSM_00413
*
* Description:   This callback function shall indicate the CanIf_ClearTrcvWufFlag API process end
*                for the notified CAN Transceiver.
*
* Inputs:        Transceiver Requested Transceiver
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, CANSM_CODE) CanSM_ClearTrcvWufFlagIndication
(
    uint8 Transceiver
)
{
    NetworkHandleType nwHandle;

    if(CANSM_INITED != CanSM_InitStatus)
    {
        /*SWS_CanSM_00415*/
        CANSM_DET_REPORT_ERROR(CANSM_CLEARTRCVWUFFLAG_SERVICE_ID, CANSM_E_UNINIT);
    }
    else
    {
        nwHandle = CanSM_GetNetWorkHandleFromTrcvId(Transceiver);
        if(nwHandle >= CANSM_MAX_NETWORK_NUM)
        {
            /*SWS_CanSM_00414*/
            CANSM_DET_REPORT_ERROR(CANSM_CLEARTRCVWUFFLAG_SERVICE_ID, CANSM_E_PARAM_TRANSCEIVER);
        }
        else
        {
            /* In common, Indication can only happened in wait state
               if the substate is not wait, the indication will be ignored
            */
            if(CanSM_NetworkInfo[CANSM_NETWORK_HANDLE].CanSMSubState == CANSM_S_PN_CLEAR_WUF_WAIT)
            {
                /* here only change state, the process will be done in next main task */
                SchM_Enter_CanSM_CANSM_EXCLUSIVE_AREA_4();
                /*SWS_CanSM_00440*/
                CanSM_NetworkInfo[CANSM_NETWORK_HANDLE].CanSMSubState = CANSM_S_PN_CLEAR_WUF_IND;
                SchM_Exit_CanSM_CANSM_EXCLUSIVE_AREA_4();
            }
        }
    }
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: CanSM_CheckTransceiverWakeFlagIndication  SWS_CanSM_00416
*
* Description:   This callback function indicates the CheckTransceiverWakeFlag API process end
*                 for the notified CAN Transceiver.
*
* Inputs:        Transceiver Requested Transceiver
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, CANSM_CODE) CanSM_CheckTransceiverWakeFlagIndication
(
    uint8 Transceiver
)
{
    NetworkHandleType nwHandle;

    if(CANSM_INITED != CanSM_InitStatus)
    {
        /*SWS_CanSM_00417*/
        CANSM_DET_REPORT_ERROR(CANSM_CHECKTRCVWUKFLAGIND_SERVICE_ID, CANSM_E_UNINIT);
    }
    else
    {
        nwHandle = CanSM_GetNetWorkHandleFromTrcvId(Transceiver);
        if(nwHandle >= CANSM_MAX_NETWORK_NUM)
        {
            /*SWS_CanSM_00418*/
            CANSM_DET_REPORT_ERROR(CANSM_CHECKTRCVWUKFLAGIND_SERVICE_ID, CANSM_E_PARAM_TRANSCEIVER);
        }
        else
        {
            /* In common, Indication can only happened in wait state
               if the substate is not wait, the indication will be ignored
            */
            if(CanSM_NetworkInfo[CANSM_NETWORK_HANDLE].CanSMSubState == CANSM_S_CHECK_WFLAG_IN_CC_SLEEP_WAIT)
            {
                /* here only change state, the process will be done in next main task */
                SchM_Enter_CanSM_CANSM_EXCLUSIVE_AREA_4();
                /*SWS_CanSM_00460*/
                CanSM_NetworkInfo[CANSM_NETWORK_HANDLE].CanSMSubState = CANSM_S_CHECK_WFLAG_IN_CC_SLEEP_IND;
                SchM_Exit_CanSM_CANSM_EXCLUSIVE_AREA_4();
            }
        }
    }
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: CanSM_ConfirmPnAvailability  SWS_CanSM_00419
*
* Description:   This callback function indicates that the transceiver is running in PN
*                 communication mode.
*
* Inputs:        TransceiverId CAN transceiver, which was checked for PN availability
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, CANSM_CODE) CanSM_ConfirmPnAvailability
(
    uint8 TransceiverId
)
{
    NetworkHandleType nwHandle;

    if(CANSM_INITED != CanSM_InitStatus)
    {
        /*SWS_CanSM_00420*/
        CANSM_DET_REPORT_ERROR(CANSM_CONFPN_SERVICE_ID, CANSM_E_UNINIT);
    }
    else
    {
        nwHandle = CanSM_GetNetWorkHandleFromTrcvId(TransceiverId);
        if(nwHandle >= CANSM_MAX_NETWORK_NUM)
        {
            /*SWS_CanSM_00421*/
            CANSM_DET_REPORT_ERROR(CANSM_CONFPN_SERVICE_ID, CANSM_E_PARAM_TRANSCEIVER);
        }
        else
        {
            /*SWS_CanSM_00422 SWS_CanSM_00546*/
            CanNm_ConfirmPnAvailability(CANSM_UESD_NETWORKCFG_INFO[CANSM_NETWORK_HANDLE].CanNmHandle);
        }
    }
}


#endif/*#if(STD_ON == CANSM_CANTRCV_SUPPORT)*/


#endif/*#if(STD_ON == CANSM_PNC_SUPPORT)*/


/* BEGIN_FUNCTION_HDR
************************************************************************************************
* Function Name : CanSM_GetVersionInfo SWS_CanSM_00024
*
* Description   : This service returns the version information of this module.
*
* Inputs        : None
*
* Outputs       : versioninfo
*                 Pointer to where to store the version information of this module.
*
* Limitations   : none
************************************************************************************************
END_FUNCTION_HDR */
#if(STD_ON ==  CANSM_VERSION_INFO_API)/*SWS_CanSM_00367 SWS_CanSM_00368*/
FUNC(void, CANSM_CODE) CanSM_GetVersionInfo
(
    P2VAR(Std_VersionInfoType, AUTOMATIC, CANSM_APPL_DATA) VersionInfo
)
{
    if(NULL_PTR == VersionInfo)
    {
        /*SWS_CanSM_00374*/
        CANSM_DET_REPORT_ERROR(CANSM_GETVERSIONINFO_SERVICE_ID, CANSM_E_PARAM_POINTER);
    }
    else
    {
        /*SWS_CanSM_00244*/
        VersionInfo->vendorID = CANSM_VENDOR_ID;
        VersionInfo->moduleID = CANSM_MODULE_ID;
        VersionInfo->sw_major_version = CANSM_SW_MAJOR_VERSION;
        VersionInfo->sw_minor_version = CANSM_SW_MINOR_VERSION;
        VersionInfo->sw_patch_version = CANSM_SW_PATCH_VERSION;
    }

}
#endif

#if(STD_ON == CANSM_SET_BAUDRATE_API)/*SWS_CanSM_00569 SWS_CanSM_00570*/
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: CanSM_SetBaudrate  SWS_CanSM_00561
*
* Description:   This service shall start an asynchronous process to change the
*                baud rate for the configured CAN controllers of a certain CAN network.
*                Depending on necessary baud rate modifications the controllers might have to reset.
*
* Inputs:        network Handle of the addressed CAN network for the baud rate change
*                BaudRateConfigID references a baud rate configuration by ID
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, CANSM_CODE) CanSM_SetBaudrate
(
    NetworkHandleType  network,
    uint16 BaudRateConfigID
)
{
    Std_ReturnType ret = E_NOT_OK;
    NetworkHandleType nwHandle;


    if(CANSM_INITED != CanSM_InitStatus)
    {
        /*SWS_CanSM_00530 SWS_CanSM_00506*/
        CANSM_DET_REPORT_ERROR(CANSM_SETBAUDRATE_SERVICE_ID, CANSM_E_UNINIT);
    }
    else if(network >= CANSM_MAX_NETWORK_NUM)
    {
        /*SWS_CanSM_00502 SWS_CanSM_00504*/
        CANSM_DET_REPORT_ERROR(CANSM_SETBAUDRATE_SERVICE_ID, CANSM_E_INVALID_NETWORK_HANDLE);
    }
    else
    {
        nwHandle = network;   
        SchM_Enter_CanSM_CANSM_EXCLUSIVE_AREA_1();
        /*
            if busoff happened at same time with change bd , this will be process in mainfuntion
            changebd will be handled first, than process the busoff
            CANSM377 CANSM375 CANSM376
        */
        if((CANSM_BSM_S_FULLCOM != CanSM_NetworkInfo[CANSM_NETWORK_HANDLE].CanSMState)
                || (CANSM_S_NO_BUS_OFF != CanSM_NetworkInfo[CANSM_NETWORK_HANDLE].CanSMSubState))
        {
            /*SWS_CanSM_00505*/
            CANSM_DET_REPORT_ERROR(CANSM_SETBAUDRATE_SERVICE_ID, CANSM_E_INVALID_COMM_REQUEST);
        }
        else
        {
            /*SWS_CanSM_00503 SWS_CanSM_00507*/
            CanSM_NetworkInfo[CANSM_NETWORK_HANDLE].savedBDId = BaudRateConfigID;
            CANSM_SET_TRIGGER(CANSM_NETWORK_HANDLE, CANSM_T_CHANGE_BR_REQUEST);
            ret = E_OK;
        }

        SchM_Exit_CanSM_CANSM_EXCLUSIVE_AREA_1();
        
    }
    return ret;

}
#endif/* #if(STD_ON == CANSM_SET_BAUDRATE_API) */

#if(STD_ON == CANSM_ICOM_SUPPORT)/*SWS_CanSM_00599*/
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: CanSM_SetIcomConfiguration  SWS_CanSM_00561
*
* Description:   This service shall change the Icom Configuration of a CAN network to the
*                requested one.
*
* Inputs:        network Handle of the addressed CAN network for the baud rate change
*                ConfigurationId Requested Configuration
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, CANSM_CODE) CanSM_SetIcomConfiguration
(
    NetworkHandleType  network,
    IcomConfigIdType ConfigurationId
)
{
    Std_ReturnType ret = E_NOT_OK;
    NetworkHandleType nwHandle;


    if(CANSM_INITED != CanSM_InitStatus)
    {
        CANSM_DET_REPORT_ERROR(CANSM_SETICOMCONIFGURATION_SERVICE_ID, CANSM_E_UNINIT);
    }
    else if(network >= CANSM_MAX_NETWORK_NUM)
    {
        /*SWS_CanSM_00594*/
        CANSM_DET_REPORT_ERROR(CANSM_SETICOMCONIFGURATION_SERVICE_ID, CANSM_E_INVALID_NETWORK_HANDLE);
    }
    else
    {
        nwHandle = network;    
        /*SWS_CanSM_00593 SWS_CanSM_00588 SWS_CanSM_00589 SWS_CanSM_00590 SWS_CanSM_00591*/
        ret = CanIf_SetIcomConfiguration(CANSM_CANIF_CTRLID, ConfigurationId);
        

    }
    return ret;

}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: CanSM_CurrentIcomConfiguration  SWS_CanSM_00587
*
* Description:   This service shall inform about the change of the Icom Configuration
*                of a CAN network.
*
* Inputs:        ControllerId CAN Controller Id, whose configuration has changed.
*                ConfigurationId Changed Configuration Id
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, CANSM_CODE) CanSM_CurrentIcomConfiguration
(
    uint8 ControllerId,
    IcomConfigIdType ConfigurationId,
    IcomSwitch_ErrorType Error
)
{
    NetworkHandleType nwHandle;

    if(CANSM_INITED != CanSM_InitStatus)
    {
        CANSM_DET_REPORT_ERROR(CANSM_CURRENTICOMCONFIGURATION_SERVICE_ID, CANSM_E_UNINIT);
    }
    else
    {
        nwHandle = CanSM_GetNetWorkHandleFromCtrlId(ControllerId);
        if(nwHandle >= CANSM_MAX_NETWORK_NUM )
        {
            CANSM_DET_REPORT_ERROR(CANSM_CURRENTICOMCONFIGURATION_SERVICE_ID, CANSM_E_INVALID_NETWORK_HANDLE);
        }
        else
        {
            /*SWS_CanSM_00595*/
            BswM_CanSM_CurrentIcomConfiguration(nwHandle, ConfigurationId, Error);
        }

    }

}

#endif/* #if(STD_ON == CANSM_ICOM_SUPPORT) */

#if(STD_ON == CANSM_TXOFFLINEACTIVE_SUPPORT)/*SWS_CanSM_00645*/
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name:  CanSM_SetEcuPassive  SWS_CanSM_00644
*
* Description:   This function can be used to set all CanSM channels of the ECU to
*                a receive only mode. This mode will be kept either until it is set
*                back, or the ECU is reset
*
* Inputs:        CanSM_Passive TRUE: set all CanSM channels to passive, i.e. receive only
*                              FALSE: set all CanSM channels back to non-passive
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, CANSM_CODE) CanSM_SetEcuPassive
(
    boolean CanSM_Passive
)
{
    Std_ReturnType ret = E_NOT_OK;
    NetworkHandleType nwHandle;
    CanIf_PduGetModeType PduMode;

    if(CANSM_INITED != CanSM_InitStatus)
    {
        CANSM_DET_REPORT_ERROR(CANSM_SETECUPASSIVE_SERVICE_ID, CANSM_E_UNINIT);
    }
    else
    {
        /*SWS_CanSM_00646 SWS_CanSM_00588*/
        CanSM_PassiveMode = CanSM_Passive;

#if(STD_OFF == CANSM_SINGLE_NETWORK_OPTIMIZE)
        for (nwHandle = 0; nwHandle < CANSM_USED_NETWORK_NUM; nwHandle++)
#endif
        {
            CanIf_GetPduMode(CANSM_CANIF_CTRLID, &PduMode);
            if(CANIF_ONLINE == PduMode)
            {
                (void)CanIf_SetPduMode(CANSM_CANIF_CTRLID, CANIF_TX_OFFLINE_ACTIVE);
            }
        }
    }
    return ret;

}
#endif/* #if(STD_ON == CANSM_TXOFFLINEACTIVE_SUPPORT) */



#define CANSM_STOP_SEC_CODE
#include "MemMap.h"


