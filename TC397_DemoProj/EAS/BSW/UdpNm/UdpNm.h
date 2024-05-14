/*  BEGIN_FILE_HDR
********************************************************************************
*   NOTICE                              
*   This software is the property of HiRain Technologies. Any information 
*   contained in this doc should not be reproduced, or used, or disclosed 
*   without the written authorization from HiRain Technologies.
********************************************************************************
*   File Name       : UdpNm.h
********************************************************************************
*   Project/Product : AUTOSAR 4.2
*   Title           : UDP Network Management module head File
*   Author          : Hirain
********************************************************************************
*   Description     : UDP Network Management module head File
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
*   01.00.00    14/08/2017    junfei.chen   N/A          Original
*   01.00.02    05/08/2020    hao.liu       N/A          QAC and Function
********************************************************************************
* END_FILE_HDR*/
#ifndef _UDPNM_H_
#define _UDPNM_H_

/*******************************************************************************
*   Includes
*******************************************************************************/ 
#include "UdpNm_Lcfg.h"
#include "UdpNm_PBcfg.h"


/*Development error code*/
/*[SWS_UdpNm_00018]*/
#define UDPNM_E_NO_INIT                                 ((uint8)0x01u)
#define UDPNM_E_INVALID_CHANNEL                         ((uint8)0x02u)
#define UDPNM_E_INVALID_PDUID                           ((uint8)0x03u)
#define UDPNM_E_NET_START_IND                           ((uint8)0x04u)
#define UDPNM_E_INIT_FAILED                             ((uint8)0x05u)
#define UDPNM_E_PARAM_POINTER                           ((uint8)0x12u)

#define UDPNM_API_ID_INIT                               ((uint8)0x00U)
#define UDPNM_API_ID_PASSIVESTARTUP                     ((uint8)0x01U)
#define UDPNM_API_ID_NETWORKREQUEST                     ((uint8)0x02U)
#define UDPNM_API_ID_NETWORKRELEASE                     ((uint8)0x03U)
#define UDPNM_API_ID_SETUSERDATA                        ((uint8)0x04U)
#define UDPNM_API_ID_GETUSERDATA                        ((uint8)0x05U)
#define UDPNM_API_ID_GETNODEID                          ((uint8)0x06U)
#define UDPNM_API_ID_GETLOCALNODEID                     ((uint8)0x07U)
#define UDPNM_API_ID_RPTMSGREQ                          ((uint8)0x08U)
#define UDPNM_API_ID_GETPDUDATA                         ((uint8)0x0AU)
#define UDPNM_API_ID_GETSTATE                           ((uint8)0x0BU)
#define UDPNM_API_ID_DISABLECOMM                        ((uint8)0x0CU)
#define UDPNM_API_ID_ENABLECOMM                         ((uint8)0x0DU)
#define UDPNM_API_ID_MAINFUNC                           ((uint8)0x13U)
#define UDPNM_API_ID_TRANSMIT                           ((uint8)0x14U)
#define UDPNM_API_ID_TXCFM                              ((uint8)0x40U)
#define UDPNM_API_ID_RXIND                              ((uint8)0x42U)
#define UDPNM_API_ID_REQBUSSYNCH                        ((uint8)0xC0U)
#define UDPNM_API_ID_CHECKRMTSLEEPIND                   ((uint8)0xD0U)
#define UDPNM_API_ID_GETVERSIONINFO                     ((uint8)0xF1U)
#define UDPNM_NUMBER_7                                  (7)
#define UDPNM_NUMBER_8                                  (8)


/*******************************************************************************
* Functions
*******************************************************************************/
#define UDPNM_START_SEC_CODE
#include "MemMap.h"
/*[SWS_UdpNm_00208]*/
extern FUNC(void, UDPNM_CODE) UdpNm_Init
( 
    P2CONST(UdpNm_ConfigType, AUTOMATIC, UDPNM_APPL_DATA) UdpNmConfigPtr 
);
/*[SWS_UdpNm_00211]*/
extern FUNC(Std_ReturnType, UDPNM_CODE) UdpNm_PassiveStartUp
(
    NetworkHandleType nmChannelHandle
);
/*[SWS_UdpNm_00257]*//*[SWS_UdpNm_00260]*/
#if(UDPNM_PASSIVE_MODE_ENABLED == STD_OFF)
/*[SWS_UdpNm_00213]*/
extern FUNC(Std_ReturnType, UDPNM_CODE) UdpNm_NetworkRequest
(
    NetworkHandleType nmChannelHandle
);
/*[SWS_UdpNm_00214]*/
extern FUNC(Std_ReturnType, UDPNM_CODE) UdpNm_NetworkRelease
(
    NetworkHandleType nmChannelHandle
);
#endif
/*[SWS_UdpNm_00262]*//*[SWS_UdpNm_00264]*/
#if(UDPNM_COM_CONTROL_ENABLED == STD_ON)
/*[SWS_UdpNm_00215]*/
extern FUNC(Std_ReturnType, UDPNM_CODE) UdpNm_DisableCommunication
(
    NetworkHandleType nmChannelHandle
);
/*[SWS_UdpNm_00216]*/
extern FUNC(Std_ReturnType, UDPNM_CODE) UdpNm_EnableCommunication
(
    NetworkHandleType nmChannelHandle
);
#endif
/*[SWS_UdpNm_00266]*/
#if(UDPNM_PASSIVE_MODE_ENABLED == STD_OFF)
/*[SWS_UdpNm_00158]*/
#if(UDPNM_USER_DATA_ENABLED == STD_ON)
/*[SWS_UdpNm_00327]*/
#if(UDPNM_COM_USER_DATA_SUPPORT == STD_OFF)
/*[SWS_UdpNm_00217]*/
extern FUNC(Std_ReturnType, UDPNM_CODE) UdpNm_SetUserData
(
    NetworkHandleType nmChannelHandle, 
    P2CONST(uint8, AUTOMATIC, UDPNM_APPL_DATA) nmUserDataPtr
);
#endif
#endif
#endif
/*[SWS_UdpNm_00268]*/
/*[SWS_UdpNm_00158]*/
#if(UDPNM_USER_DATA_ENABLED == STD_ON)
/*[SWS_UdpNm_00218]*/
extern FUNC(Std_ReturnType, UDPNM_CODE) UdpNm_GetUserData
(
    NetworkHandleType nmChannelHandle, 
    P2VAR(uint8, AUTOMATIC, UDPNM_APPL_DATA) nmUserDataPtr
);
#endif
/*[SWS_UdpNm_00330]*/
#if(UDPNM_COM_USER_DATA_SUPPORT == STD_ON)
/*[SWS_UdpNm_00331]*/
extern FUNC(Std_ReturnType, UDPNM_CODE) UdpNm_Transmit
(
    PduIdType UdpNmTxPduId,
    P2CONST(PduInfoType, AUTOMATIC, UDPNM_APPL_DATA) UdpNmSrcPduInfoPtr
);
#endif
/*[SWS_UdpNm_00270]*//*[SWS_UdpNm_00272]*/
#if(UDPNM_NODE_ID_ENABLED == STD_ON)
/*[SWS_UdpNm_00219]*/
extern FUNC(Std_ReturnType, UDPNM_CODE) UdpNm_GetNodeIdentifier
(
    NetworkHandleType nmChannelHandle,
    P2VAR(uint8, AUTOMATIC, UDPNM_APPL_DATA) nmNodeIdPtr
);
/*[SWS_UdpNm_00220]*/
extern FUNC(Std_ReturnType, UDPNM_CODE) UdpNm_GetLocalNodeIdentifier 
(
    NetworkHandleType nmChannelHandle, 
    P2VAR(uint8, AUTOMATIC, UDPNM_APPL_DATA) nmNodeIdPtr
);
#endif
#if(UDPNM_PASSIVE_MODE_ENABLED == STD_OFF)
/*[SWS_UdpNm_00274]*/
/*[SWS_UdpNm_00135]*/
#if(UDPNM_NODE_DETECTION_ENABLED == STD_ON)
/*[SWS_UdpNm_00221]*/
extern FUNC(Std_ReturnType, UDPNM_CODE) UdpNm_RepeatMessageRequest 
(
    NetworkHandleType nmChannelHandle
);
#endif
#endif
/*[SWS_UdpNm_00276]*/
#if((UDPNM_NODE_DETECTION_ENABLED == STD_ON)||(UDPNM_USER_DATA_ENABLED == STD_ON)||(UDPNM_NODE_ID_ENABLED == STD_ON))
/*[SWS_UdpNm_00222]*/
extern FUNC(Std_ReturnType, UDPNM_CODE) UdpNm_GetPduData
(
    NetworkHandleType nmChannelHandle,
    P2VAR(uint8, AUTOMATIC, UDPNM_APPL_DATA) nmPduDataPtr
);
#endif
/*[SWS_UdpNm_00223]*/
extern FUNC(Std_ReturnType, UDPNM_CODE) UdpNm_GetState
(
    NetworkHandleType nmChannelHandle, 
    P2VAR(Nm_StateType, AUTOMATIC, UDPNM_APPL_DATA) nmStatePtr,
    P2VAR(Nm_ModeType, AUTOMATIC, UDPNM_APPL_DATA) nmModePtr
);
#if(UDPNM_VERSION_INFO_API == STD_ON)
/*[SWS_UdpNm_00224]*/
extern FUNC(void, UDPNM_CODE) UdpNm_GetVersionInfo
(
    P2VAR(Std_VersionInfoType, AUTOMATIC, UDPNM_APPL_DATA) versioninfo
);
#endif
/*[SWS_UdpNm_00280]*/
#if(UDPNM_PASSIVE_MODE_ENABLED == STD_OFF)
#if(UDPNM_BUS_SYNCHRONIZATION_ENABLED == STD_ON)
/*[SWS_UdpNm_00226]*/
extern FUNC(Std_ReturnType, UDPNM_CODE) UdpNm_RequestBusSynchronization
(
    NetworkHandleType nmChannelHandle
);
#endif

/*[SWS_UdpNm_00282]*/
#if(UDPNM_REMOTE_SLEEP_IND_ENABLED == STD_ON)
/*[SWS_UdpNm_00227]*/
extern FUNC(Std_ReturnType, UDPNM_CODE) UdpNm_CheckRemoteSleepIndication
(
    NetworkHandleType nmChannelHandle, 
    P2VAR(boolean, AUTOMATIC, UDPNM_APPL_DATA) nmRemoteSleepIndPtr
);
#endif
#endif

extern FUNC(void, UDPNM_CODE) UdpNm_MainFunction
(
    const NetworkHandleType nmChannelHandle
);
#define UDPNM_STOP_SEC_CODE
#include "MemMap.h"

#endif/*_UDPNM_H_*/

