/*  BEGIN_FILE_HDR
********************************************************************************
*   NOTICE                              
*   This software is the property of HiRain Technologies. Any information 
*   contained in this doc should not be reproduced, or used, or disclosed 
*   without the written authorization from HiRain Technologies.
********************************************************************************
*   File Name       : EthSM.c
********************************************************************************
*   Project/Product : AUTOSAR 4.2
*   Title           : Ethernet State Manager
*   Author          : Hirain
********************************************************************************
*   Description     : Implementation of EthSM Modules provided functionality
*
********************************************************************************
*   Limitations     : None
*
********************************************************************************
*
********************************************************************************
*   Revision History:
* 
*   Version       Date            Initials        CR#          Descriptions
*   ---------   ----------    -------------  ----------   ---------------
*   01.00.00    02/17/2018    mingqing.tang  N/A          Original
*   01.00.01    05/20/2020    tianrui.zhang  N/A          ETH422_EthSM_20200520_01
*   01.00.02    06/19/2020    tianrui.zhang  N/A          ETH422_EthSM_20200619_01
*   01.00.03    06/24/2020    tianrui.zhang  N/A          ETH422_EthSM_20200624_01
*   01.00.04    04/09/2020    beibei.xing    N/A          ETH422_EthSM_20200904_01
*   01.00.05    06/08/2021    jianzhe.cai    N/A          ETH422_EthSM_20210806_01
*   01.00.06    26/03/2022    zeyu.ren       N/A          ETH422_EthSM_20220326_01
*   01.00.07    17/03/2023    zeyu.ren       N/A          ETH422_EthSM_20230317_01
*   01.00.08    20/04/2023    lin.lv1        N/A          ETH422_EthSM_20230420_01
********************************************************************************
* END_FILE_HDR*/

/*******************************************************************************
*   Includes 
*******************************************************************************/
#include "EthSM.h"
#include "SchM_EthSM.h"
#include "EthSM_Cbk.h"

#if (ETHSM_BSWM_SUPPORT == STD_ON)
#include "BswM_EthSM.h"     /*for BswM_EthSM_CurrentState*/
#endif

#include "ComM_BusSM.h"     /*for BswM_EthSM_CurrentState*/

#if (ETHSM_DUMMY_MODE == STD_OFF)
#include "TcpIp.h"          /*for TcpIp_RequestComMode*/
#include "EthIf.h"          /*for EthIf_SetControllerMode and EthIf_SetTransceiverMode*/
#endif

#if (ETHSM_DEV_ERROR_DETECT == STD_ON)
#include "Det.h"            /*for DET_REPORT_ERROR*/
#endif

#if (ETHSM_DEM_ENABLED == STD_ON)
#include "Dem.h"            /*for DET_REPORT_ERROR*/
#endif



/*******************************************************************************
*   Local Macro
*******************************************************************************/


/*******************************************************************************
*   Version Check
*******************************************************************************/
#if ((ETHSM_AR_RELEASE_MAJOR_VERSION != ETHSM_AR_RELEASE_MAJOR_VERSION_CFG) \
	    || (ETHSM_AR_RELEASE_MINOR_VERSION != ETHSM_AR_RELEASE_MINOR_VERSION_CFG))
#error "AutoSar Version Numbers of EthSM and its cfg file are different."
#endif
	
#if ((ETHSM_SW_MAJOR_VERSION != ETHSM_SW_MAJOR_VERSION_CFG) \
        || (ETHSM_SW_MINOR_VERSION != ETHSM_SW_MINOR_VERSION_CFG))
#error "SW Version Numbers of EthSM and its cfg file are different."
#endif

/*******************************************************************************
*   Macro Check
*******************************************************************************/
/*SWS_EthSM_00061*/
#if ((ETHSM_CONFIG_VARIANTS != STD_CONFIG_VARIANTS_PRECOMPILE))
#error "The EthSM supports STD_CONFIG_VARIANTS_PRECOMPILE only."
#endif

#if ((ETHSM_NETWORK_HANDLE_NUM <= 0))
#error "ETHSM_NETWORK_HANDLE_NUM must be greater than Zero."
#endif

/*******************************************************************************
*   Macro
*******************************************************************************/
#if (STD_ON == ETHSM_DEV_ERROR_DETECT)	
#define ETHSM_DET_ERROR_DETECT(cond,ApiId,errcode)          DET_ERROR_DETECT((cond), \
                                                                                ETHSM_MODULE_ID, \
                                                                                ETHSM_INSTANCE_ID, \
                                                                                (ApiId), \
                                                                                (errcode))
#define ETHSM_DET_ERROR_DETECT_RET(cond,ApiId,errcode,ret)  DET_ERROR_DETECT_RET((cond), \
                                                                                    ETHSM_MODULE_ID, \
                                                                                    ETHSM_INSTANCE_ID, \
                                                                                    (ApiId), \
                                                                                    (errcode), \
                                                                                    (ret))	
#define ETHSM_DET_REPORT_ERROR(ApiId, errcode)              DET_REPORT_ERROR(ETHSM_MODULE_ID, \
                                                                                ETHSM_INSTANCE_ID, \
                                                                                (ApiId), \
                                                                                (errcode))	
#else
#define ETHSM_DET_ERROR_DETECT(cond,ApiId,errcode)
#define ETHSM_DET_ERROR_DETECT_RET(cond,ApiId,errcode,ret)
#define ETHSM_DET_REPORT_ERROR(ApiId, errcode)
#endif

/* there is not communication request, the previous request has been processed or is processing*/
#define ETHSM_NO_COMMUNICATION_REQUEST              ((ComM_ModeType)0xFF) 

#define ETHSM_SET_REQUEST_COM_MODE(network, mode)           ((network)->RequestComMode = (mode))
#define ETHSM_SET_PROCESSING_COM_MODE(network, mode)  ((network)->ProcessingComMode = (mode))

#define ETHSM_GET_NETWORK_STATE(network)            ((network)->NetworkState)
#define ETHSM_GET_CURRENT_COM_MODE(network)         (((network)->NetworkState < ETHSM_STATE_ONLINE) \
                                                        ? COMM_NO_COMMUNICATION: COMM_FULL_COMMUNICATION)

#if (ETHSM_DUMMY_MODE == STD_OFF)
#define ETHSM_SET_TCPIP_STATE(network, state)       ((network)->TcpIpState = (state))
#define ETHSM_SET_CTRL_MODE(network, mode)          ((network)->CtrlMode = (mode))
#define ETHSM_SET_TRCV_MODE(network, mode)          ((network)->TrcvMode = (mode))
#define ETHSM_SET_TRCV_LINK_STATE(network, state)   ((network)->TrcvLinkState = (state))


#if (ETHSM_NETWORK_HANDLE_NUM > 1)
/*SWS_EthSM_00021*/
#define ETHSM_SET_CONTROLERMODE(network, state)     (void)EthIf_SetControllerMode((network)->ConfigPtr->EthIfCtrlId, (state))
/*SWS_EthSM_00023*/
#define ETHSM_SET_TRANSCEIVERMODE(network, state)   (void)EthIf_SetTransceiverMode((network)->ConfigPtr->EthIfCtrlId, (state))
#define ETHSM_TCPIP_REQUESTCOMMODE(network, state)  (void)TcpIp_RequestComMode((network)->ConfigPtr->EthIfCtrlId, (state))
#else /*ETHSM_NETWORK_HANDLE_NUM > 1*/
/*SWS_EthSM_00021*/
#define ETHSM_SET_CONTROLERMODE(network, state)     (void)EthIf_SetControllerMode((uint8)ETHSM_NETWORK_ETHCTRL_ID, (state))
/*SWS_EthSM_00023*/
#define ETHSM_SET_TRANSCEIVERMODE(network, state)   (void)EthIf_SetTransceiverMode(ETHSM_NETWORK_ETHCTRL_ID, (state))
#define ETHSM_TCPIP_REQUESTCOMMODE(network, state)  (void)TcpIp_RequestComMode((uint8)ETHSM_NETWORK_ETHCTRL_ID, (state))
#endif

#else /*ETHSM_DUMMY_MODE == STD_OFF*/
#define ETHSM_SET_TCPIP_STATE(network, state)       ((void)(state))
#define ETHSM_SET_CTRL_MODE(network, mode)          ((void)(mode))
#define ETHSM_SET_TRCV_MODE(network, mode)          ((void)(mode))
#define ETHSM_SET_TRCV_LINK_STATE(network, state)   ((void)(state))
#define ETHSM_SET_CONTROLERMODE(network, state)     ((void)(state))
#define ETHSM_SET_TRANSCEIVERMODE(network, state)   ((void)(state))
#define ETHSM_TCPIP_REQUESTCOMMODE(network, state)  ((void)(state))
#endif

#define ETHSM_IS_VALID_STATE(network)               (((network)->NetworkState < ETHSM_STATE_LIMIT) \
                                                        && ((network)->NetworkState >= ETHSM_STATE_OFFLINE))

#define ETHSM_STATE_SET_STATE(network, state)       ((network)->NetworkState = (state))
#define ETHSM_STATE_SET_OFFLINE(network)            ETHSM_STATE_SET_STATE(network, ETHSM_STATE_OFFLINE)
#define ETHSM_STATE_SET_WAIT_TRCVLINK(network)      ETHSM_STATE_SET_STATE(network, ETHSM_STATE_WAIT_TRCVLINK)
#define ETHSM_STATE_SET_WAIT_ONLINE(network)        ETHSM_STATE_SET_STATE(network, ETHSM_STATE_WAIT_ONLINE)
#define ETHSM_STATE_SET_ONLINE(network)             ETHSM_STATE_SET_STATE(network, ETHSM_STATE_ONLINE)
#define ETHSM_STATE_SET_ONHOLD(network)             ETHSM_STATE_SET_STATE(network, ETHSM_STATE_ONHOLD)
#define ETHSM_STATE_SET_WAIT_OFFLINE(network)       ETHSM_STATE_SET_STATE(network, ETHSM_STATE_WAIT_OFFLINE)


#define ETHSM_IS_ACTIVED_CTRL(network)              (ETH_MODE_ACTIVE == (network)->CtrlMode)
#define ETHSM_IS_ACTIVED_TRCV(network)              (ETHTRCV_MODE_ACTIVE == (network)->TrcvMode)
#define ETHSM_IS_ACTIVED_TRCVLINK(network)          (ETHTRCV_LINK_STATE_ACTIVE == (network)->TrcvLinkState)
#define ETHSM_IS_ACTIVED_LINK(network)              (ETHSM_IS_ACTIVED_CTRL(network) \
                                                        && ETHSM_IS_ACTIVED_TRCV(network) \
                                                        && ETHSM_IS_ACTIVED_TRCVLINK(network))
#define ETHSM_IS_TCPIP_ONLINE(network)              (TCPIP_STATE_ONLINE == (network)->TcpIpState)
#define ETHSM_IS_TCPIP_OFFLINE(network)             (TCPIP_STATE_OFFLINE == (network)->TcpIpState)


#if (ETHSM_NETWORK_HANDLE_NUM > 1)
#define ETHSM_CTRLID_TO_NETWORKID(ctrlid)           (EthSM_CtrlIdToNetworkId(ctrlid))
/*SWS_EthSM_00018*/
#define ETHSM_COMM_NOTIFIER(network, state)     {\
                                                        EthSM_ComMode = (state); \
                                                        ComM_BusSM_ModeIndication((network)->ConfigPtr->ComMNetworkHandle,(&EthSM_ComMode)); \
                                                       }
                                                    

#else
#define ETHSM_CTRLID_TO_NETWORKID(ctrlid)           (((ctrlid) == (uint8) ETHSM_NETWORK_ETHCTRL_ID) \
                                                        ? (uint8) 0: (uint8) ETHSM_NETWORK_HANDLE_NUM)
#define ETHSM_COMM_NOTIFIER(network, state)    {\
                                                        EthSM_ComMode = (state); \
                                                        ComM_BusSM_ModeIndication((uint8)ETHSM_NETWORK_HANDLE_ID, &EthSM_ComMode); \
                                                      }
#endif

#if (ETHSM_DEM_ENABLED == STD_ON)
#if (ETHSM_NETWORK_HANDLE_NUM > 1)
#define ETHSM_DEM_NOTIFIER(network, status)         if ((network)->ConfigPtr->DemEventId != DEM_EVENT_ID_INVALID) \
                                                     { \
                                                        Dem_ReportError((network)->ConfigPtr->DemEventId, (status)); \
                                                     }
#else /*ETHSM_NETWORK_HANDLE_NUM < 1*/
#define ETHSM_DEM_NOTIFIER(network, status)         (Dem_ReportError(ETHSM_NETWORK_DEMEVENT_ID, (status)))
#endif

#else /*ETHSM_DEM_ENABLED == STD_ON*/
#define ETHSM_DEM_NOTIFIER(network, status)
#endif



#if (ETHSM_BSWM_SUPPORT == STD_ON)
#define ETHSM_BSWM_NOTIFIER(network)                BswM_EthSM_CurrentState((network)->NetworkId, \
                                                                                (network)->NetworkState)
#else
#define ETHSM_BSWM_NOTIFIER(network)                                                                               
#endif
/*******************************************************************************
*   Local Function Declaration
*******************************************************************************/
#define ETHSM_START_SEC_CODE
#include "MemMap.h"

#if (ETHSM_NETWORK_HANDLE_NUM > 1)
STATIC FUNC(EthSM_NetworkIdType, ETHSM_CODE) EthSM_CtrlIdToNetworkId(uint8 CtrlIdx);
#endif

STATIC FUNC(void, ETHSM_CODE) EthSM_StateProcess(P2VAR(EthSM_NetworkInfoType, AUTOMATIC, AUTOMATIC) NetworkPtr);
STATIC FUNC(void, ETHSM_CODE) EthSM_StateHandlerOffline(P2VAR(EthSM_NetworkInfoType, AUTOMATIC, AUTOMATIC) NetworkPtr);
STATIC FUNC(void, ETHSM_CODE) EthSM_StateHandlerWaitTrcvLink(P2VAR(EthSM_NetworkInfoType, AUTOMATIC, AUTOMATIC) NetworkPtr);
STATIC FUNC(void, ETHSM_CODE) EthSM_StateHandlerWaitOnline(P2VAR(EthSM_NetworkInfoType, AUTOMATIC, AUTOMATIC) NetworkPtr);
STATIC FUNC(void, ETHSM_CODE) EthSM_StateHandlerOnline(P2VAR(EthSM_NetworkInfoType, AUTOMATIC, AUTOMATIC) NetworkPtr);
STATIC FUNC(void, ETHSM_CODE) EthSM_StateHandlerOnhold(P2VAR(EthSM_NetworkInfoType, AUTOMATIC, AUTOMATIC) NetworkPtr);
STATIC FUNC(void, ETHSM_CODE) EthSM_StateHandlerWaitOffline(P2VAR(EthSM_NetworkInfoType, AUTOMATIC, AUTOMATIC) NetworkPtr);

#define ETHSM_STOP_SEC_CODE
#include "MemMap.h"
/*******************************************************************************
*   Local Data Define
*******************************************************************************/
#define ETHSM_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
STATIC CONST(EthSM_StateProcessFunc, ETHSM_CONST) EthSM_StateProcessHandler[ETHSM_STATE_LIMIT] =
{
    &EthSM_StateHandlerOffline,
    &EthSM_StateHandlerWaitTrcvLink,
    &EthSM_StateHandlerWaitOnline,
    &EthSM_StateHandlerOnline,
    &EthSM_StateHandlerOnhold,
    &EthSM_StateHandlerWaitOffline
};

#define ETHSM_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"


#define ETHSM_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h"
STATIC VAR(EthSM_NetworkInfoType ,ETHSM_VAR) EthSM_NetworkInfo[ETHSM_NETWORK_HANDLE_NUM];

#define ETHSM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h"


#define ETHSM_START_SEC_VAR_INIT_8
#include "MemMap.h"
STATIC VAR(Std_InitStateType, ETHSM_VAR) EthSM_InitState = STD_UNINITIALIZED;
STATIC VAR(ComM_ModeType, ETHSM_VAR) EthSM_ComMode = COMM_NO_COMMUNICATION;
#define ETHSM_STOP_SEC_VAR_INIT_8
#include "MemMap.h"

/*******************************************************************************
*   Function Define
*******************************************************************************/
#define ETHSM_START_SEC_CODE
#include "MemMap.h"
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: EthSM_Init
*                
* Description:   This function initialize the EthSM Modules.
*
* Inputs:        None
*                
* Outputs:       None
* 
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void,ETHSM_CODE) EthSM_Init
(
    void
)
{
    NetworkHandleType id = (uint8) 0;

    for(id = (uint8) 0; id < (uint8) ETHSM_NETWORK_HANDLE_NUM; id++)
    {
        /*SWS_EthSM_00025*/
        EthSM_NetworkInfo[id].NetworkId = id;
        EthSM_NetworkInfo[id].NetworkState = ETHSM_STATE_OFFLINE;
        EthSM_NetworkInfo[id].RequestComMode = ETHSM_NO_COMMUNICATION_REQUEST;   
        EthSM_NetworkInfo[id].ProcessingComMode = COMM_NO_COMMUNICATION;
#if (ETHSM_DUMMY_MODE == STD_OFF)
        EthSM_NetworkInfo[id].CtrlMode = ETH_MODE_DOWN;
        EthSM_NetworkInfo[id].TrcvMode = ETHTRCV_MODE_DOWN;
        EthSM_NetworkInfo[id].TrcvLinkState = ETHTRCV_LINK_STATE_DOWN;
        EthSM_NetworkInfo[id].TcpIpState = TCPIP_STATE_OFFLINE;
#else
        EthSM_NetworkInfo[id].CtrlMode = ETH_MODE_ACTIVE;
		EthSM_NetworkInfo[id].TrcvMode = ETHTRCV_MODE_ACTIVE;
        EthSM_NetworkInfo[id].TrcvLinkState = ETHTRCV_LINK_STATE_ACTIVE;
		EthSM_NetworkInfo[id].TcpIpState = TCPIP_STATE_ONLINE;
#endif

#if (ETHSM_NETWORK_HANDLE_NUM > 1)
        EthSM_NetworkInfo[id].ConfigPtr = &EthSM_NetworkConfig[id];
#endif       

    }
    EthSM_InitState = STD_INITIALIZED;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: EthSM_RequestComMode
*                
* Description:   Handles the communication mode and sets the Ethernet network
*                active or passive.
*
* Inputs:        NetworkHandle  - The network handler
*
* Outputs:       ComM_Mode      - The new mode of ethernet network.
*                
* Return:        If the request is accepted returns E_OK, otherwise returns E_NOT_OK.
* 
* Limitations:   The function reentrancy is limited to different network handles.
*                Reentrancy for the same network is not to be regarded here.
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, ETHSM_CODE) EthSM_RequestComMode
(
    NetworkHandleType NetworkHandle,
    ComM_ModeType ComM_Mode
)
{		
    Std_ReturnType result = E_NOT_OK;

    if (STD_INITIALIZED != EthSM_InitState)
    {
        /*SWS_EthSM_00054*/
        ETHSM_DET_REPORT_ERROR(ETHSM_REQUEST_COM_MODE_API_ID, ETHSM_E_UNINIT);
    }
    /*SWS_EthSM_00051*/
    else if (NetworkHandle >= (uint8) ETHSM_NETWORK_HANDLE_NUM)
    {
        /*SWS_EthSM_00052*/
        ETHSM_DET_REPORT_ERROR(ETHSM_REQUEST_COM_MODE_API_ID, ETHSM_E_INVALID_NETWORK_HANDLE);
    }
    else if ((ComM_Mode != COMM_FULL_COMMUNICATION) && (ComM_Mode != COMM_NO_COMMUNICATION))
    {
        if (ComM_Mode != COMM_SILENT_COMMUNICATION)
        {
            /*SWS_EthSM_00095*/
            ETHSM_DET_REPORT_ERROR(ETHSM_REQUEST_COM_MODE_API_ID, ETHSM_E_INVALID_NETWORK_MODE);
        }
        else
        {
            /*SWS_EthSM_00199, SWS_EthSM_00087*/
            result = E_OK;
        }
    }
    /*SWS_EthSM_00038*/
    else 
    {
        /*SWS_EthSM_00053*/
        ETHSM_SET_REQUEST_COM_MODE(&EthSM_NetworkInfo[NetworkHandle], ComM_Mode);
        result = E_OK;
    }

    return result;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: EthSM_GetCurrentComMode
*                
* Description:   This service shall put out the current communication mode of a
*                Ethernet network
*
* Inputs:        NetworkHandle  - Network handle whose current communication mode shall be put out
* 
* Outputs:       ComM_ModePtr   - Pointer where to put out the current communication mode.
*                
* Return:        If the request is accepted returns E_OK, otherwise returns E_NOT_OK.
* 
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, ETHSM_CODE) EthSM_GetCurrentComMode
(
    NetworkHandleType NetworkHandle,
    P2VAR(ComM_ModeType, AUTOMATIC, ETHSM_APPL_DATA) ComM_ModePtr
)
{
    Std_ReturnType result = E_NOT_OK;

    if (STD_INITIALIZED != EthSM_InitState) /*SWS_ETHSM_00060*/
    {
        ETHSM_DET_REPORT_ERROR(ETHSM_GET_CURRENT_COM_MODE_API_ID, ETHSM_E_UNINIT);	  
    }
    /*SWS_EthSM_00057*/
    else if (NetworkHandle >= (uint8) ETHSM_NETWORK_HANDLE_NUM)
    {
        /*SWS_EthSM_00058*/
        ETHSM_DET_REPORT_ERROR(ETHSM_GET_CURRENT_COM_MODE_API_ID, ETHSM_E_INVALID_NETWORK_HANDLE);
    }
    else if (NULL_PTR == ComM_ModePtr)
    {
        ETHSM_DET_REPORT_ERROR(ETHSM_GET_CURRENT_COM_MODE_API_ID, ETHSM_E_PARAM_POINTER);
    }
    else
    {
        /*SWS_EthSM_00059*/
        *ComM_ModePtr = ETHSM_GET_CURRENT_COM_MODE(&EthSM_NetworkInfo[NetworkHandle]);
        result = E_OK;
    }		
    return result;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: EthSM_GetCurrentInternalMode
*                
* Description:   This service shall put out the current internal mode of a Ethernet network.
*
* Inputs:        NetworkHandle      - Network handle whose current communication mode shall be put out
* 
* Outputs:       EthSM_InternalMode   - Pointer where to put out the current internal mode.
*                
* Return:        If the request is accepted returns E_OK, otherwise returns E_NOT_OK.
* 
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, ETHSM_CODE) EthSM_GetCurrentInternalMode
(
    NetworkHandleType NetworkHandle,
    P2VAR(EthSM_NetworkModeStateType, AUTOMATIC, ETHSM_APPL_DATA) EthSM_InternalMode
)
{
    Std_ReturnType result = E_NOT_OK;

    if (STD_INITIALIZED != EthSM_InitState)
    {
        /*SWS_ETHSM_00125*/
        ETHSM_DET_REPORT_ERROR(ETHSM_GET_CURRENT_INTERNAL_MODE_API_ID, ETHSM_E_UNINIT);	  
    }
    /*SWS_ETHSM_00122*/
    else if (NetworkHandle >= (uint8) ETHSM_NETWORK_HANDLE_NUM)
    {
        /*SWS_ETHSM_00123*/
        ETHSM_DET_REPORT_ERROR(ETHSM_GET_CURRENT_INTERNAL_MODE_API_ID, ETHSM_E_INVALID_NETWORK_HANDLE);
    }
    else if (NULL_PTR == EthSM_InternalMode)
    {
        ETHSM_DET_REPORT_ERROR(ETHSM_GET_CURRENT_INTERNAL_MODE_API_ID, ETHSM_E_PARAM_POINTER);
    }
    else
    {
        /*SWS_EthSM_00124*/
        *EthSM_InternalMode = ETHSM_GET_NETWORK_STATE(&EthSM_NetworkInfo[NetworkHandle]);
        result = E_OK;
    }
    return result;
}

#if (ETHSM_DUMMY_MODE == STD_OFF)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: EthSM_TcpIpModeIndication
*                
* Description:   This service is called by the TcpIp to report the actual TcpIp
*                state (e.g. online, offline).
*
* Inputs:        CtrlIdx    - EthIf controller index to identify the communication 
*                             network where the TcpIp state is changed
*                TcpIpState - Actual TcpIp state of the specific network handle.
*                
* Outputs:       None
*       
* Return:        If the request is accepted returns E_OK, otherwise returns E_NOT_OK.
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, ETHSM_CODE) EthSM_TcpIpModeIndication
(
	uint8 CtrlIdx,
	TcpIp_StateType TcpIpState
)
{
    Std_ReturnType result = E_NOT_OK;
    NetworkHandleType id = ETHSM_CTRLID_TO_NETWORKID(CtrlIdx);

    if (STD_INITIALIZED != EthSM_InitState)
    {
        /*SWS_ETHSM_00120*/
        ETHSM_DET_REPORT_ERROR(ETHSM_TCPIP_MODE_INDICATION_API_ID, ETHSM_E_UNINIT);	  
    }
    else if (id >= (uint8) ETHSM_NETWORK_HANDLE_NUM)
    {
        /*SWS_ETHSM_00116*/
        ETHSM_DET_REPORT_ERROR(ETHSM_TCPIP_MODE_INDICATION_API_ID, ETHSM_E_PARAM_CONTROLLER);
    }
    else if ((TcpIpState != TCPIP_STATE_OFFLINE)
               && (TcpIpState != TCPIP_STATE_ONLINE)
               && (TcpIpState != TCPIP_STATE_ONHOLD))            
    {
        /*SWS_ETHSM_00118*/
        ETHSM_DET_REPORT_ERROR(ETHSM_TCPIP_MODE_INDICATION_API_ID, ETHSM_E_INVALID_TCP_IP_MODE);
    }	
    else
    {
        /*SWS_ETHSM_00119*/
        ETHSM_SET_TCPIP_STATE(&EthSM_NetworkInfo[id], TcpIpState);
        result = E_OK;
    }

    return result;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: EthSM_CtrlModeIndication
*                
* Description:   Called when mode has been read out. Either triggered by previous
*                EthIf_GetControllerMode or by EthIf_SetControllerMode call.
*                Eth directly be called within the trigger functions.
*
* Inputs:        CtrlIdx    - Ethernet controller whose mode has changed
*                CtrlMode   - Notified Ethernet controller mode
*                
* Outputs:       None
* 
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, ETHSM_CODE) EthSM_CtrlModeIndication
(
    uint8 CtrlIdx, 
    Eth_ModeType CtrlMode
)
{
    NetworkHandleType id = ETHSM_CTRLID_TO_NETWORKID(CtrlIdx);
		
    if (STD_INITIALIZED != EthSM_InitState)
    {
        /*SWS_ETHSM_00192*/
        ETHSM_DET_REPORT_ERROR(ETHSM_CTRL_MODE_INDICATION_API_ID, ETHSM_E_UNINIT);	  
    }
    /*SWS_ETHSM_00191*/
    else if (id >= (uint8) ETHSM_NETWORK_HANDLE_NUM)
    {
        ETHSM_DET_REPORT_ERROR(ETHSM_CTRL_MODE_INDICATION_API_ID, ETHSM_E_PARAM_CONTROLLER);
    }
    else if ((CtrlMode != ETH_MODE_DOWN) && (CtrlMode != ETH_MODE_ACTIVE))
    {
        ETHSM_DET_REPORT_ERROR(ETHSM_CTRL_MODE_INDICATION_API_ID, ETHSM_E_PARAM_INV);
    }
    else
    {
        SchM_Enter_EthSM_ETHSM_EXCLUSIVE_AREA_0();
        ETHSM_SET_CTRL_MODE(&EthSM_NetworkInfo[id], CtrlMode);
        SchM_Exit_EthSM_ETHSM_EXCLUSIVE_AREA_0();
    }
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: EthSM_TrcvModeIndication
*                
* Description:   Called when mode has been read out. Either triggered by previous
*                EthIf_GetTransceiverMode or by EthIf_SetTransceiverMode call.
*                Eth directly be called within the trigger functions.
*
* Inputs:        CtrlIdx    - Index of the Ethernet controller within the context of the Ethernet Interface
*                TrcvMode   - Notified Ethernet transceiver mode
*                
* Outputs:       None
* 
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, ETHSM_CODE) EthSM_TrcvModeIndication
(
	uint8 CtrlIdx, 
	EthTrcv_ModeType TrcvMode
)
{
    NetworkHandleType id = ETHSM_CTRLID_TO_NETWORKID(CtrlIdx);

    if (STD_INITIALIZED != EthSM_InitState)
    {
        /*SWS_ETHSM_00195*/
        ETHSM_DET_REPORT_ERROR(ETHSM_TRCV_MODE_INDICATION_API_ID, ETHSM_E_UNINIT);	  
    }
    else if (id >= (uint8) ETHSM_NETWORK_HANDLE_NUM)
    {
        /*SWS_ETHSM_00194*/
        ETHSM_DET_REPORT_ERROR(ETHSM_TRCV_MODE_INDICATION_API_ID, ETHSM_E_PARAM_CONTROLLER);
    }
    else if ((TrcvMode != ETHTRCV_MODE_DOWN) && (TrcvMode != ETHTRCV_MODE_ACTIVE))
    {
        ETHSM_DET_REPORT_ERROR(ETHSM_TRCV_MODE_INDICATION_API_ID, ETHSM_E_PARAM_INV);
    }
    else
    {
        SchM_Enter_EthSM_ETHSM_EXCLUSIVE_AREA_1();
        ETHSM_SET_TRCV_MODE(&EthSM_NetworkInfo[id], TrcvMode);
        SchM_Exit_EthSM_ETHSM_EXCLUSIVE_AREA_1();
    }
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: EthSM_TrcvLinkStateChg
*                
* Description:   Called when mode has been read out. Either triggered by previous
*                EthIf_GetTransceiverMode or by EthIf_SetTransceiverMode call.
*                Eth directly be called within the trigger functions.
*
* Inputs:        CtrlIdx        - EthIf controller index
*                TrcvLinkState  - Notified Ethernet transceiver mode
*                
* Outputs:       None
* 
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, ETHSM_CODE) EthSM_TrcvLinkStateChg
(
	uint8 CtrlIdx, 
	EthTrcv_LinkStateType TransceiverLinkState
)
{
    NetworkHandleType id = ETHSM_CTRLID_TO_NETWORKID(CtrlIdx);
	
    if (STD_INITIALIZED != EthSM_InitState)
    {
        /*SWS_ETHSM_00115*/
        ETHSM_DET_REPORT_ERROR(ETHSM_TRCV_LINK_STATE_CHG_API_ID, ETHSM_E_UNINIT);	  
    }
    else if (id >= (uint8) ETHSM_NETWORK_HANDLE_NUM)
    {
        /*SWS_ETHSM_00112*/
        ETHSM_DET_REPORT_ERROR(ETHSM_TRCV_LINK_STATE_CHG_API_ID, ETHSM_E_PARAM_CONTROLLER);	  
    }
    else if ((TransceiverLinkState != ETHTRCV_LINK_STATE_DOWN) && (TransceiverLinkState != ETHTRCV_LINK_STATE_ACTIVE))
    {
        ETHSM_DET_REPORT_ERROR(ETHSM_TRCV_MODE_INDICATION_API_ID, ETHSM_E_PARAM_INV);
    }
    else
    {      
        /*SWS_EthSM_00114*/
        ETHSM_SET_TRCV_LINK_STATE(&EthSM_NetworkInfo[id], TransceiverLinkState);
    }
}
#endif

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: EthSM_MainFunction
*                
* Description:   Cyclic Main Function which is called from the Scheduler.
*
* Inputs:        None
*                
* Outputs:       None
* 
* Limitations:   SWS_EthSM_00093
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, ETHSM_CODE) EthSM_MainFunction
(
    void
)
{
    EthSM_NetworkIdType id = (uint8) 0;

    if (STD_INITIALIZED == EthSM_InitState)
    {
        /*SWS_EthSM_00197*/
        for(id = (uint8) 0; id < (uint8) ETHSM_NETWORK_HANDLE_NUM; id++)
        {
            /*SWS_EthSM_00015, SWS_EthSM_00016, SWS_EthSM_00024*/
            EthSM_StateProcess(&EthSM_NetworkInfo[id]);
        }
    }
    else
    {
        ETHSM_DET_REPORT_ERROR(ETHSM_MAIN_FUNCTION_API_ID, ETHSM_E_UNINIT);
    }
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: EthSM_GetVersionInfo
*                
* Description:   This service puts out the version information of this module.
*               
* Inputs:        versioninfo    - Pointer where to put out the version information. 
*                   
* Outputs:       None
* 
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
#if (ETHSM_VERSION_INFO_API == STD_ON)
FUNC(void, ETHSM_CODE) EthSM_GetVersionInfo 
(
    P2VAR(Std_VersionInfoType, AUTOMATIC, ETHSM_APPL_DATA) versioninfo
)
{
    if(NULL_PTR != versioninfo)
    {
        versioninfo->vendorID = ETHSM_VENDOR_ID;
        versioninfo->moduleID = ETHSM_MODULE_ID;
        versioninfo->sw_major_version = (uint8) ETHSM_SW_MAJOR_VERSION;
        versioninfo->sw_minor_version = (uint8) ETHSM_SW_MINOR_VERSION;
        versioninfo->sw_patch_version = (uint8) ETHSM_SW_PATCH_VERSION;
    }
    else
    {
        ETHSM_DET_REPORT_ERROR(ETHSM_GET_VERSION_INFO_API_ID, ETHSM_E_PARAM_POINTER);
    }		
}
#endif
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: EthSM_Handle_StopWakeupSources
*                
* Description:   This service is Sync handle status.
*               
* Inputs:        NetworkHandle  - The network handler
*                ModePtr        - The current mode of ethernet network.
*                   
* Outputs:       None
* 
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, ETHSM_CODE) EthSM_Handle_StopWakeupSources
(
    NetworkHandleType NetworkHandle,
    ComM_ModeType ComM_Mode
)
{
    if(ComM_Mode == COMM_NO_COMMUNICATION)
    {
        EthSM_NetworkInfo[NetworkHandle].ProcessingComMode = COMM_NO_COMMUNICATION;
        /*SWS_EthSM_00053*/
        ETHSM_SET_REQUEST_COM_MODE(&EthSM_NetworkInfo[NetworkHandle], COMM_NO_COMMUNICATION);
        /*SWS_EthSM_00157*/
        ETHSM_TCPIP_REQUESTCOMMODE(&EthSM_NetworkInfo[NetworkHandle], TCPIP_STATE_OFFLINE);
        /*SWS_EthSM_00160*/
        ETHSM_STATE_SET_OFFLINE(&EthSM_NetworkInfo[NetworkHandle]);
        /*SWS_EthSM_00161*/
        ETHSM_SET_CONTROLERMODE(&EthSM_NetworkInfo[NetworkHandle], ETH_MODE_DOWN);
        /*SWS_EthSM_00162*/
        ETHSM_SET_TRANSCEIVERMODE(&EthSM_NetworkInfo[NetworkHandle], ETHTRCV_MODE_DOWN);
        /*SWS_EthSM_00163*/
        ETHSM_BSWM_NOTIFIER(&EthSM_NetworkInfo[NetworkHandle]);
        /*SWS_EthSM_00165*/
        ETHSM_COMM_NOTIFIER(&EthSM_NetworkInfo[NetworkHandle], COMM_NO_COMMUNICATION);
    }
}
/*******************************************************************************
*   Local Functions define
*******************************************************************************/
#if (ETHSM_NETWORK_HANDLE_NUM > 1)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: EthSM_CtrlIdToNetworkId
*                
* Description:   Finds the network id used by EthSM.
*               
* Inputs:        CtrlIdx    - The EthIf controller index
*                   
* Outputs:       network id or ETHSM_NETWORK_HANDLE_NUM.
* 
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(EthSM_NetworkIdType, ETHSM_CODE) EthSM_CtrlIdToNetworkId
(
   uint8 CtrlIdx
)
{	
    EthSM_NetworkIdType id = 0;

    for(id = 0; id < ETHSM_NETWORK_HANDLE_NUM; id++)
    {
		if(EthSM_NetworkConfig[id].EthIfCtrlId == CtrlIdx)
        {
            break;
        }
    }

	return id;
}
#endif

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: EthSM_StateProcess
*                
* Description:   The porcesser of network mode state machine
*               
* Inputs:        NetworkPtr    - The network
*                   
* Outputs:       None
* 
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, ETHSM_CODE) EthSM_StateProcess
(
    P2VAR(EthSM_NetworkInfoType, AUTOMATIC, AUTOMATIC) NetworkPtr
)
{
    if (ETHSM_IS_VALID_STATE(NetworkPtr))
    {
        EthSM_StateProcessHandler[NetworkPtr->NetworkState](NetworkPtr);
    }
    else
    {
        ETHSM_DET_REPORT_ERROR(ETHSM_MAIN_FUNCTION_API_ID, ETHSM_E_INVALID_NETWORK_MODE);
    }
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: EthSM_StateHandlerOffline
*                
* Description:   The OFFLINE state's porcesser
*               
* Inputs:        NetworkPtr - The network
*                   
* Outputs:       None
* 
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, ETHSM_CODE) EthSM_StateHandlerOffline
(
    P2VAR(EthSM_NetworkInfoType, AUTOMATIC, AUTOMATIC) NetworkPtr
)
{  
    if(COMM_FULL_COMMUNICATION == NetworkPtr->RequestComMode)
    {
        if(COMM_NO_COMMUNICATION == NetworkPtr->ProcessingComMode)
        {
            /*SWS_EthSM_00088*/
            ETHSM_SET_CONTROLERMODE(NetworkPtr, ETH_MODE_ACTIVE);
            /*SWS_EthSM_00089*/
            ETHSM_SET_TRANSCEIVERMODE(NetworkPtr, ETHTRCV_MODE_ACTIVE);
            NetworkPtr->ProcessingComMode = COMM_FULL_COMMUNICATION;
        }
        else
        {
            /* do nothing, just waiting for transceiver and controller active*/
        }
        /*clear the request*/
        NetworkPtr->RequestComMode = ETHSM_NO_COMMUNICATION_REQUEST;        
    }
    else if (COMM_NO_COMMUNICATION == NetworkPtr->RequestComMode)
    {
        /*SWS_EthSM_00198*/
        if(ETH_MODE_ACTIVE == NetworkPtr->CtrlMode)
        {
            ETHSM_SET_CONTROLERMODE(NetworkPtr, ETH_MODE_DOWN);
        }

        if(ETHTRCV_MODE_ACTIVE == NetworkPtr->TrcvMode)
        {
            ETHSM_SET_TRANSCEIVERMODE(NetworkPtr, ETHTRCV_MODE_DOWN);
        }
        NetworkPtr->ProcessingComMode = COMM_NO_COMMUNICATION;
        NetworkPtr->RequestComMode = ETHSM_NO_COMMUNICATION_REQUEST;        
    }
    else /*no mode request*/
    {
        /* do nothing */
    }

    if(COMM_FULL_COMMUNICATION == NetworkPtr->ProcessingComMode)
    {
        if((ETH_MODE_ACTIVE == NetworkPtr->CtrlMode)&&
            (ETHTRCV_MODE_ACTIVE == NetworkPtr->TrcvMode))
        {
            /*SWS_EthSM_00026*//*SWS_EthSM_00085*/
            ETHSM_STATE_SET_WAIT_TRCVLINK(NetworkPtr);
            /*SWS_EthSM_00097*/
            ETHSM_BSWM_NOTIFIER(NetworkPtr);
        }
    }
    else
    {
        /* do nothing */
    }
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: EthSM_StateHandlerOffline
*                
* Description:   The WAITTRCVLINK state's porcesser
*               
* Inputs:        NetworkPtr - The network
*                   
* Outputs:       None
* 
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, ETHSM_CODE) EthSM_StateHandlerWaitTrcvLink
(
    P2VAR(EthSM_NetworkInfoType, AUTOMATIC, AUTOMATIC) NetworkPtr
)
{
    if(COMM_FULL_COMMUNICATION == NetworkPtr->RequestComMode)
    {
        if(COMM_FULL_COMMUNICATION == NetworkPtr->ProcessingComMode)
        {            
            /*clear the request, just waiting for the link*/
            NetworkPtr->RequestComMode = ETHSM_NO_COMMUNICATION_REQUEST;
        }
        else
        {
            /* previous no com hasn't been done, pending the full com request and process it in offline state*/
        }            
    }
    else if (COMM_NO_COMMUNICATION == NetworkPtr->RequestComMode)
    {
        if(COMM_FULL_COMMUNICATION == NetworkPtr->ProcessingComMode)
        {
            /*SWS_EthSM_00129*/
            ETHSM_SET_TRANSCEIVERMODE(NetworkPtr, ETHTRCV_MODE_DOWN);
            /*SWS_EthSM_00086*//*SWS_EthSM_00128*/
            ETHSM_SET_CONTROLERMODE(NetworkPtr, ETH_MODE_DOWN);
            NetworkPtr->ProcessingComMode = COMM_NO_COMMUNICATION;            
        }
        else
        {
            /*clear the request, just waiting for controller and transceive down*/
        }
        /*clear the request, just waiting for the link*/
        NetworkPtr->RequestComMode = ETHSM_NO_COMMUNICATION_REQUEST;
    }
    else /*no mode request*/
    {
        /* do nothing */
    }

    if(COMM_FULL_COMMUNICATION == NetworkPtr->ProcessingComMode)
    {
        /*SWS_EthSM_00085*/
        if(ETHSM_IS_ACTIVED_LINK(NetworkPtr))
        {
            /*SWS_EthSM_00132*/
            ETHSM_STATE_SET_WAIT_ONLINE(NetworkPtr);
            /*SWS_EthSM_00133*/
            ETHSM_TCPIP_REQUESTCOMMODE(NetworkPtr, TCPIP_STATE_ONLINE);
            /*SWS_EthSM_00134*/
            ETHSM_BSWM_NOTIFIER(NetworkPtr);
        }
        else
        {
            /*wait for actived link*/
        }
    }
    else
    {
        if((ETH_MODE_DOWN == NetworkPtr->CtrlMode)&&
            (ETHTRCV_MODE_DOWN == NetworkPtr->TrcvMode))
        {      
            /*SWS_EthSM_00127*/
            ETHSM_STATE_SET_OFFLINE(NetworkPtr);
            /*SWS_EthSM_00130*/
            ETHSM_BSWM_NOTIFIER(NetworkPtr);
        }
        else
        {
            /*waiting for controller and transceive down*/
        }
    }    
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: EthSM_StateHandlerWaitOnline
*                
* Description:   The WAITONLINE state's porcesser
*               
* Inputs:        NetworkPtr - The network
*                   
* Outputs:       None
* 
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, ETHSM_CODE) EthSM_StateHandlerWaitOnline
(
    P2VAR(EthSM_NetworkInfoType, AUTOMATIC, AUTOMATIC) NetworkPtr
)
{
    if(COMM_FULL_COMMUNICATION == NetworkPtr->RequestComMode)
    {
        if(COMM_FULL_COMMUNICATION == NetworkPtr->ProcessingComMode)
        {
            /*clear the request, just waiting for the tcpip online*/
            NetworkPtr->RequestComMode = ETHSM_NO_COMMUNICATION_REQUEST;
        }
        else
        {
            /* previous no com hasn't been done, pending the full com request and process it in offline state*/
        } 
    }
    else if (COMM_NO_COMMUNICATION == NetworkPtr->RequestComMode)
    {
        if(COMM_FULL_COMMUNICATION == NetworkPtr->ProcessingComMode)
        {
            /*SWS_EthSM_00143*/
            ETHSM_TCPIP_REQUESTCOMMODE(NetworkPtr, TCPIP_STATE_OFFLINE);
            /*SWS_EthSM_00142*/
            ETHSM_SET_TRANSCEIVERMODE(NetworkPtr, ETHTRCV_MODE_DOWN);
            /*SWS_EthSM_00141*/
            ETHSM_SET_CONTROLERMODE(NetworkPtr, ETH_MODE_DOWN);

            NetworkPtr->ProcessingComMode = COMM_NO_COMMUNICATION;            
        }
        else
        {
            /*clear the request, just waiting for controller and transceive down*/
        }
        /*clear the request, just waiting for the link*/
        NetworkPtr->RequestComMode = ETHSM_NO_COMMUNICATION_REQUEST;
    }
    else /*no mode request*/
    {
        /* do nothing */
    }

    if(COMM_FULL_COMMUNICATION == NetworkPtr->ProcessingComMode)
    {
        if(!ETHSM_IS_ACTIVED_TRCVLINK(NetworkPtr))
        {
            /*SWS_EthSM_00136*/
            ETHSM_STATE_SET_WAIT_TRCVLINK(NetworkPtr);
            /*SWS_EthSM_00137*/
            ETHSM_TCPIP_REQUESTCOMMODE(NetworkPtr, TCPIP_STATE_OFFLINE);
            /*SWS_EthSM_00138*/
            ETHSM_BSWM_NOTIFIER(NetworkPtr);
        }
        else if(ETHSM_IS_TCPIP_ONLINE(NetworkPtr))
        {
            /*SWS_EthSM_00146*/
            ETHSM_STATE_SET_ONLINE(NetworkPtr);
            /*SWS_EthSM_00148*/
            ETHSM_BSWM_NOTIFIER(NetworkPtr);
            /*SWS_EthSM_00150*/
            ETHSM_COMM_NOTIFIER(NetworkPtr, COMM_FULL_COMMUNICATION);
        }
        else
        {
            /*wait for tcpip online*/
        }
    }
    else
    {
        if((ETH_MODE_DOWN == NetworkPtr->CtrlMode)&&
            (ETHTRCV_MODE_DOWN == NetworkPtr->TrcvMode)&&
                (ETHSM_IS_TCPIP_OFFLINE(NetworkPtr)))
        {   
            /*SWS_EthSM_00140*/
            ETHSM_STATE_SET_OFFLINE(NetworkPtr);
            /*SWS_EthSM_00144*/
            ETHSM_BSWM_NOTIFIER(NetworkPtr);            
        }  
        else
        {
            /*do nothing*/
        }
    }    
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: EthSM_StateHandlerOnline
*                
* Description:   The ONLINE state's porcesser
*               
* Inputs:        NetworkPtr - The network
*                   
* Outputs:       None
* 
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, ETHSM_CODE) EthSM_StateHandlerOnline
(
    P2VAR(EthSM_NetworkInfoType, AUTOMATIC, AUTOMATIC) NetworkPtr
)
{
    if(COMM_FULL_COMMUNICATION == NetworkPtr->RequestComMode)
    {
        if(COMM_FULL_COMMUNICATION == NetworkPtr->ProcessingComMode)
        {
            /*clear the request, just waiting for the link*/
            NetworkPtr->RequestComMode = ETHSM_NO_COMMUNICATION_REQUEST;
        }
        else
        {
            /* previous no com hasn't been done, pending the full com request and process it in offline state*/
        } 
    }
    else if (COMM_NO_COMMUNICATION == NetworkPtr->RequestComMode)
    {
        if(COMM_FULL_COMMUNICATION == NetworkPtr->ProcessingComMode)
        {
            /*SWS_EthSM_00157*/
            ETHSM_TCPIP_REQUESTCOMMODE(NetworkPtr, TCPIP_STATE_OFFLINE);
            /*SWS_EthSM_00155*/
            ETHSM_STATE_SET_WAIT_OFFLINE(NetworkPtr);
            /*SWS_EthSM_00158*/
            ETHSM_BSWM_NOTIFIER(NetworkPtr);

            NetworkPtr->ProcessingComMode = COMM_NO_COMMUNICATION;            
        }
        else
        {
            /*clear the request, just waiting for controller and transceive down*/
        }
        /*clear the request, just waiting for the link*/
        NetworkPtr->RequestComMode = ETHSM_NO_COMMUNICATION_REQUEST;
    }
    else /*no mode request*/
    {
        /* do nothing */
    }

    if(COMM_FULL_COMMUNICATION == NetworkPtr->ProcessingComMode)
    {
        if (ETHSM_IS_TCPIP_OFFLINE(NetworkPtr))
        {
            /*SWS_EthSM_00151*/
            ETHSM_STATE_SET_WAIT_ONLINE(NetworkPtr);
            /*SWS_EthSM_00152*/
            ETHSM_BSWM_NOTIFIER(NetworkPtr);
            /*SWS_EthSM_00154*/
            ETHSM_COMM_NOTIFIER(NetworkPtr, COMM_NO_COMMUNICATION);
        }
        else if (!ETHSM_IS_ACTIVED_TRCVLINK(NetworkPtr))
        {
            /*SWS_EthSM_00166*/
            ETHSM_STATE_SET_ONHOLD(NetworkPtr);
            /*SWS_EthSM_00167*/
            ETHSM_TCPIP_REQUESTCOMMODE(NetworkPtr, TCPIP_STATE_ONHOLD);
            /*SWS_EthSM_00168*/
            ETHSM_BSWM_NOTIFIER(NetworkPtr);
            /*SWS_EthSM_00188*/
            ETHSM_DEM_NOTIFIER(NetworkPtr, DEM_EVENT_STATUS_FAILED);
        }
        else
        {
            /*do nothing*/
        }        
    }

    else
    {
        /*do nothing*/
    } 
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: EthSM_StateHandlerOnhold
*                
* Description:   The ONHOLD state's porcesser
*               
* Inputs:        NetworkPtr - The network
*                   
* Outputs:       None
* 
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, ETHSM_CODE) EthSM_StateHandlerOnhold
(
    P2VAR(EthSM_NetworkInfoType, AUTOMATIC, AUTOMATIC) NetworkPtr
)
{
    if(COMM_FULL_COMMUNICATION == NetworkPtr->RequestComMode)
    {
        if(COMM_FULL_COMMUNICATION == NetworkPtr->ProcessingComMode)
        {
            /*clear the request, just waiting for the link*/
            NetworkPtr->RequestComMode = ETHSM_NO_COMMUNICATION_REQUEST;
        }
        else
        {
            /* previous no com hasn't been done, pending the full com request and process it in offline state*/
        } 
    }
    else if (COMM_NO_COMMUNICATION == NetworkPtr->RequestComMode)
    {
        if(COMM_FULL_COMMUNICATION == NetworkPtr->ProcessingComMode)
        {
            /*SWS_EthSM_00181*/
            ETHSM_TCPIP_REQUESTCOMMODE(NetworkPtr, TCPIP_STATE_OFFLINE);
            /*SWS_EthSM_00179*/
            ETHSM_SET_CONTROLERMODE(NetworkPtr, ETH_MODE_DOWN);
            /*SWS_EthSM_00180*/
            ETHSM_SET_TRANSCEIVERMODE(NetworkPtr, ETHTRCV_MODE_DOWN);

            NetworkPtr->ProcessingComMode = COMM_NO_COMMUNICATION;            
        }
        else
        {
            /*clear the request, just waiting for controller and transceive down*/
        }
        /*clear the request, just waiting for the link*/
        NetworkPtr->RequestComMode = ETHSM_NO_COMMUNICATION_REQUEST;
    }
    else /*no mode request*/
    {
        /* do nothing */
    }

    if(COMM_FULL_COMMUNICATION == NetworkPtr->ProcessingComMode)
    {
        if (ETHSM_IS_TCPIP_OFFLINE(NetworkPtr))
        {
            /*SWS_EthSM_00174*/
            ETHSM_STATE_SET_WAIT_TRCVLINK(NetworkPtr);
            /*SWS_EthSM_00175*/
            ETHSM_BSWM_NOTIFIER(NetworkPtr);
            /*SWS_EthSM_00177*/
            ETHSM_COMM_NOTIFIER(NetworkPtr, COMM_NO_COMMUNICATION);
        }
        else if (ETHSM_IS_ACTIVED_TRCVLINK(NetworkPtr))
        {
            /*SWS_EthSM_00170*/
            ETHSM_STATE_SET_ONLINE(NetworkPtr);
            /*SWS_EthSM_00171*/
            ETHSM_TCPIP_REQUESTCOMMODE(NetworkPtr, TCPIP_STATE_ONLINE);
            /*SWS_EthSM_00172*/
            ETHSM_BSWM_NOTIFIER(NetworkPtr);
            /*SWS_EthSM_00196*/
            ETHSM_DEM_NOTIFIER(NetworkPtr, DEM_EVENT_STATUS_PASSED);
        }
        else
        {
            /*nothing*/
        }         
    }
    else
    {        
        if((ETH_MODE_DOWN == NetworkPtr->CtrlMode)&&
            (ETHTRCV_MODE_DOWN == NetworkPtr->TrcvMode)&&
              (ETHSM_IS_TCPIP_OFFLINE(NetworkPtr)))
        {  
            /*SWS_EthSM_00178*/
            ETHSM_STATE_SET_OFFLINE(NetworkPtr);
            /*SWS_EthSM_00182*/
            ETHSM_BSWM_NOTIFIER(NetworkPtr);
            /*SWS_EthSM_00184*/
            ETHSM_COMM_NOTIFIER(NetworkPtr, COMM_NO_COMMUNICATION);
        }
    }      
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: EthSM_StateHandlerWaitOffline
*                
* Description:   The WAITOFFLINE state's porcesser
*               
* Inputs:        NetworkPtr - The network
*                   
* Outputs:       None
* 
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, ETHSM_CODE) EthSM_StateHandlerWaitOffline
(
    P2VAR(EthSM_NetworkInfoType, AUTOMATIC, AUTOMATIC) NetworkPtr
)
{
    if (COMM_NO_COMMUNICATION == NetworkPtr->RequestComMode)
    {
        /*clear the request, just waiting for controller and transceive down*/
        NetworkPtr->RequestComMode = ETHSM_NO_COMMUNICATION_REQUEST;
    }
    else /*no mode request or full com request */
    {
        /* previous no com hasn't been done, pending the full com request and process it in offline state*/  
        /* do nothing */
    }

    if (ETHSM_IS_TCPIP_OFFLINE(NetworkPtr))
    {
        if((ETH_MODE_DOWN == NetworkPtr->CtrlMode)&&
            (ETHTRCV_MODE_DOWN == NetworkPtr->TrcvMode))
        {
            /*SWS_EthSM_00160*/
            ETHSM_STATE_SET_OFFLINE(NetworkPtr);
            /*SWS_EthSM_00163*/
            ETHSM_BSWM_NOTIFIER(NetworkPtr);
            /*SWS_EthSM_00165*/
            ETHSM_COMM_NOTIFIER(NetworkPtr, COMM_NO_COMMUNICATION);
        }
        else
        {
            /*SWS_EthSM_00161*/
            ETHSM_SET_CONTROLERMODE(NetworkPtr, ETH_MODE_DOWN);
            /*SWS_EthSM_00162*/
            ETHSM_SET_TRANSCEIVERMODE(NetworkPtr, ETHTRCV_MODE_DOWN);
        }
    }
}

#define ETHSM_STOP_SEC_CODE
#include "MemMap.h"
