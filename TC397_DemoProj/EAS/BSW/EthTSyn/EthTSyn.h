/*  BEGIN_FILE_HDR
********************************************************************************
*   NOTICE
*   This software is the property of HiRain Technologies. Any information
*   contained in this doc should not be reproduced, or used, or disclosed
*   without the written authorization from HiRain Technologies.
********************************************************************************
*   File Name       : EthTSyn.h
********************************************************************************
*   Project/Product : AUTOSAR 4.2
*   Title           : EthTSyn  module Header File
*   Author          : Hirain
********************************************************************************
*   Description     : EthTSyn module Header File
*
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

/*PRQA S 3432,4640 EOF*/
#ifndef ETHTSYN_H
#define ETHTSYN_H

/*******************************************************************************
*   Includes
*******************************************************************************/
#include "EthTSyn_Cfg.h"
#include "EthTSyn_Lcfg.h"
#include "EthTSyn_Version.h"
/*******************************************************************************
*   Macro define
*******************************************************************************/
#define ETHTSYN_SERVICEID_INIT                                           ((uint8)0x01)
#define ETHTSYN_SERVICEID_GETVERSIONINFO                                 ((uint8)0x02)
#define ETHTSYN_SERVICEID_GETCURRENTTIME                                 ((uint8)0x03)
#define ETHTSYN_SERVICEID_SETGLOBALTIME                                  ((uint8)0x04)
#define ETHTSYN_SERVICEID_SETTRANSMISSIONMODE                            ((uint8)0x05)
#define ETHTSYN_SERVICEID_RXINDICATION                                   ((uint8)0x06)
#define ETHTSYN_SERVICEID_TXCONFIRMATION                                 ((uint8)0x07)
#define ETHTSYN_SERVICEID_TRCVLINKSTATECHG                               ((uint8)0x08)
#define ETHTSYN_SERVICEID_MAINFUNCTION                                   ((uint8)0x09)

/* SWS_EthTSyn_00030*/
#define ETHTSYN_E_NOT_INITIALIZED                                        ((uint8)0x20)
#define ETHTSYN_E_PARAM_POINTER                                          ((uint8)0x23)
#define ETHTSYN_E_PARAM                                                  ((uint8)0x24)


/*******************************************************************************
*  Global Function Declaration
*******************************************************************************/
#define ETHTSYN_START_SEC_CODE
#include "EthTSyn_MemMap.h"

extern FUNC(void, ETHTSYN_CODE) EthTSyn_Init
( 
    P2CONST(EthTSyn_ConfigType, AUTOMATIC, ETHTSYN_CONST) CfgPtr
);

#if(STD_ON == ETHTSYN_VERSION_INFO)
extern FUNC(void, ETHTSYN_CODE) EthTSyn_GetVersionInfo
(
	P2VAR(Std_VersionInfoType, AUTOMATIC, ETHTSYN_APPL_DATA) versionInfo
);
#endif

extern FUNC(void, ETHTSYN_CODE) EthTSyn_SetTransmissionMode
(
    uint8 CtrlIdx,
    EthTSyn_TransmissionModeType Mode
);

extern FUNC(Std_ReturnType, ETHTSYN_CODE) EthTSyn_GetCurrentTime
(
    StbM_SynchronizedTimeBaseType timeBaseId,
    P2VAR(StbM_TimeStampType, AUTOMATIC, ETHTSYN_APPL_DATA) timeStampPtr,
    P2VAR(EthTSyn_SyncStateType, AUTOMATIC, ETHTSYN_APPL_DATA) syncState
);

extern FUNC(Std_ReturnType, ETHTSYN_CODE) EthTSyn_SetGlobalTime
(
    StbM_SynchronizedTimeBaseType timeBaseId,
    P2CONST(StbM_TimeStampType, AUTOMATIC, ETHTSYN_APPL_DATA) timeStampPtr
);

extern FUNC(void, ETHTSYN_CODE) EthTSyn_MainFunction
(
    void
);

#define ETHTSYN_STOP_SEC_CODE
#include "EthTSyn_MemMap.h"

#endif/* ETHTSYN_H */
