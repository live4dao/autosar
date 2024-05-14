/*  BEGIN_FILE_HDR
********************************************************************************
*   NOTICE                              
*   This software is the property of HiRain Technologies. Any information 
*   contained in this doc should not be reproduced, or used, or disclosed 
*   without the written authorization from HiRain Technologies.
********************************************************************************
*   File Name       : EthSM.h
********************************************************************************
*   Project/Product : AUTOSAR 4.2.2
*   Title           : Ethernet State Manager
*   Author          : Hirain
********************************************************************************
*   Description     : The header file of Ethernet State Manager Module.                 
********************************************************************************
*   Limitations     : None
*
********************************************************************************
*
********************************************************************************
*   Revision History:
*   Reference to Core C File
********************************************************************************
 END_FILE_HDR*/
#ifndef _ETHSM_H_
#define _ETHSM_H_
/*******************************************************************************
*   Includes
*******************************************************************************/
#include "EthSM_Cfg.h"
#include "EthSM_Lcfg.h"
#include "EthSM_Version.h"

/*******************************************************************************
*   Macro
*******************************************************************************/
#define ETHSM_E_INVALID_NETWORK_MODE				(0x01)
#define ETHSM_E_UNINIT								(0x02)
#define ETHSM_E_PARAM_POINTER						(0x03)
#define ETHSM_E_INVALID_NETWORK_HANDLE				(0x04)
#define ETHSM_E_INVALID_TCP_IP_MODE					(0x05)
#define ETHSM_E_PARAM_INV							(0x06)
#define ETHSM_E_PARAM_CONTROLLER					(0x07)


#define ETHSM_INIT_API_ID							(0x07)
#define ETHSM_GET_VERSION_INFO_API_ID				(0x02)
#define ETHSM_GET_CURRENT_COM_MODE_API_ID			(0x04)
#define ETHSM_REQUEST_COM_MODE_API_ID				(0x05)
#define ETHSM_TCPIP_MODE_INDICATION_API_ID			(0x08)
#define ETHSM_GET_CURRENT_INTERNAL_MODE_API_ID		(0x03)
#define ETHSM_CTRL_MODE_INDICATION_API_ID			(0x09)
#define ETHSM_TRCV_MODE_INDICATION_API_ID			(0x0a)
#define ETHSM_TRCV_LINK_STATE_CHG_API_ID			(0x06)
#define ETHSM_MAIN_FUNCTION_API_ID					(0x01)

/*******************************************************************************
*   Global Function Declaration
*******************************************************************************/
#define ETHSM_START_SEC_CODE
#include "MemMap.h"

/*SWS_EthSM_00043*/
extern FUNC(void, ETHSM_CODE) EthSM_Init
(
	void
);

/*SWS_EthSM_00050, SWS_EthSM_00014*/
extern FUNC(Std_ReturnType, ETHSM_CODE) EthSM_RequestComMode
(
	NetworkHandleType NetworkHandle,
	ComM_ModeType ComM_Mode
);
/*SWS_EthSM_00055, SWS_EthSM_00017*/
extern FUNC(Std_ReturnType, ETHSM_CODE) EthSM_GetCurrentComMode
(
	NetworkHandleType NetworkHandle,
	P2VAR(ComM_ModeType, AUTOMATIC, ETHSM_APPL_DATA) ComM_ModePtr
);

/*SWS_EthSM_00121*/
extern FUNC(Std_ReturnType, ETHSM_CODE) EthSM_GetCurrentInternalMode
(
	NetworkHandleType NetworkHandle,
	P2VAR(EthSM_NetworkModeStateType, AUTOMATIC, ETHSM_APPL_DATA) EthSM_InternalMode
);
/*SWS_EthSM_00035*/
extern FUNC(void, ETHSM_CODE) EthSM_MainFunction
(
	void
);

#if (ETHSM_VERSION_INFO_API == STD_ON)
/*SWS_EthSM_00046*/
extern FUNC(void, ETHSM_CODE) EthSM_GetVersionInfo
(
	P2VAR(Std_VersionInfoType, AUTOMATIC, ETHSM_APPL_DATA) versioninfo
);
#endif




extern FUNC(void, ETHSM_CODE) EthSM_Handle_StopWakeupSources
(
    NetworkHandleType NetworkHandle,
    ComM_ModeType ComM_Mode
);



#define ETHSM_STOP_SEC_CODE
#include "MemMap.h"

#endif/*_ETHSM_H_*/
