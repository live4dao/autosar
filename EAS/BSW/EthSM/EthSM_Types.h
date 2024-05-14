/*  BEGIN_FILE_HDR
********************************************************************************
*   NOTICE                              
*   This software is the property of HiRain Technologies. Any information 
*   contained in this doc should not be reproduced, or used, or disclosed 
*   without the written authorization from HiRain Technologies.
********************************************************************************
*   File Name       : EthSM_Types.h
********************************************************************************
*   Project/Product : AUTOSAR 4.2.2
*   Title             : EthSM mode types File
*   Author          : Hirain
********************************************************************************
*   Description     : EthSM mode types File                     
********************************************************************************
*   Limitations     : None
*
********************************************************************************
*
********************************************************************************
*   Revision History:
*   Reference to Core C File
********************************************************************************
* END_FILE_HDR*/
#ifndef _ETHSM_TYPES_H_
#define _ETHSM_TYPES_H_
/*******************************************************************************
*   Includes
*******************************************************************************/
#include "EthSM_Cfg.h"
#include "ComStack_Types.h"
#include "EthIf_Types.h"
#include "TcpIp_Types.h"
#include "ComM_Types.h"

typedef uint8 EthSM_BswMCurrentStateType;
typedef uint8 EthSM_NetworkIdType;

/*SWS_EthSM_00041*/
typedef enum
{
    ETHSM_STATE_OFFLINE = 0,
    ETHSM_STATE_WAIT_TRCVLINK,
    ETHSM_STATE_WAIT_ONLINE,
    ETHSM_STATE_ONLINE,
    ETHSM_STATE_ONHOLD,
    ETHSM_STATE_WAIT_OFFLINE,
    /*only used to check if the state is vaild.*/
    ETHSM_STATE_LIMIT
}EthSM_NetworkModeStateType;

typedef struct
{
    /*ECUC_EthSM_00068*/
    NetworkHandleType ComMNetworkHandle;
    /*ECUC_EthSM_00105, SWS_EthSM_00019*/
    uint8 EthIfCtrlId;
#if (ETHSM_DEM_ENABLED == STD_ON)
    /*ECUC_EthSM_00106, only ETHSM_E_LINK_DOWN*/
    Dem_EventIdType   DemEventId;
#endif
} EthSM_NetworkConfigType;


typedef struct
{
    NetworkHandleType               NetworkId;
    EthSM_NetworkModeStateType	    NetworkState;
    ComM_ModeType				    RequestComMode;
    ComM_ModeType				    ProcessingComMode;
    TcpIp_StateType                 TcpIpState;
    Eth_ModeType		            CtrlMode;
	EthTrcv_ModeType                TrcvMode;
	EthTrcv_LinkStateType           TrcvLinkState;
#if (ETHSM_NETWORK_HANDLE_NUM > 1)
	P2CONST(EthSM_NetworkConfigType, AUTOMATIC, AUTOMATIC) ConfigPtr;
#endif
} EthSM_NetworkInfoType;


typedef void (*EthSM_StateProcessFunc)(EthSM_NetworkInfoType *NetworkPtr);


#endif
