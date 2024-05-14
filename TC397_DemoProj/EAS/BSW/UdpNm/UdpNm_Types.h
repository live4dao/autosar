/*  BEGIN_FILE_HDR
********************************************************************************
*   NOTICE                              
*   This software is the property of HiRain Technologies. Any information 
*   contained in this doc should not be reproduced, or used, or disclosed 
*   without the written authorization from HiRain Technologies.
********************************************************************************
*   File Name       : UdpNm_Types.h
********************************************************************************
*   Project/Product : AUTOSAR 4.2
*   Title           : CAN Network Management module type definitions head File
*   Author          : Hirain
********************************************************************************
*   Description     : CAN Network Management module type definitions head File
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
********************************************************************************
* END_FILE_HDR*/
#ifndef _UDPNM_TYPES_H_
#define _UDPNM_TYPES_H_

/*******************************************************************************
*   Includes
*******************************************************************************/
#include "ComStack_Types.h"   
#include "NmStack_Types.h"
#include "UdpNm_Cfg.h" 
#include "UdpNm_Version.h"

typedef enum
{
    UDPNM_PDU_BYTE_0  = 0u,      
    UDPNM_PDU_BYTE_1  = 1u, 
    UDPNM_PDU_OFF     = 2u  
}UdpNm_PduBytePosType;

typedef enum
{
    UDPNM_NETWORK_RELEASED  = 0u, 
    UDPNM_NETWORK_REQUESTED = 1u  
}UdpNm_NetworkStateType;

typedef enum
{
    UDPNM_NULL_CMD            = 0u,
    UDPNM_NETWORK_REQUEST_CMD = 1u,      
    UDPNM_NETWORK_RELEASE_CMD = 2u,
    UDPNM_PASSIVE_STARTUP_CMD = 3u
}UdpNm_NetworkReqType;

typedef enum
{
    UDPNM_NO_RESTART      = 0u,
    UDPNM_ACTIVE_RESTART  = 1u,
    UDPNM_PASSIVE_RESTART = 2u
}UdpNm_NetworkRestartType;

typedef enum
{
    UDPNM_COM_ENABLED  = 0u,
    UDPNM_COM_DISABLED = 1u
}UdpNm_ComCtrlType;

#if(STD_ON == UDPNM_GLOBAL_PN_SUPPORT)
/*ECUC_UdpNm_00067 range(0-7)*/
typedef struct
{
    /*ECUC_UdpNm_00071*/
    uint8 UdpNmPnFilterMaskByteIndex;
    /*ECUC_UdpNm_00072*/
    uint8 UdpNmPnFilterMaskByteValue;
} UdpNm_PnFilterMaskByteType;

/*ECUC_UdpNm_00070 only one*/
typedef struct
{
    /*ECUC_UdpNm_00069*/
    uint8 UdpNmPnInfoLength;/*Range 1...7 Byte*/
    /*ECUC_UdpNm_00068*/
    uint8 UdpNmPnInfoOffset;/*Range 1...7 Byte*/
} UdpNm_PnInfoType;
#endif

/*[SWS_UdpNm_00202]*/
typedef struct
{
#if(UDPNM_PASSIVE_MODE_ENABLED == STD_OFF)
    /*ECUC_UdpNm_00074*/
    boolean UdpNmActiveWakeupBitEnabled;
#endif
    /*ECUC_UdpNm_00075*/
    uint8 UdpNmImmediateNmTransmissions;
#if(UDPNM_PASSIVE_MODE_ENABLED == STD_OFF) 
    /*ECUC_UdpNm_00029*/
    uint16 UdpNmMsgCycleOffset;
    /*ECUC_UdpNm_00028*/
    uint16 UdpNmMsgCycleTime;  
    /*ECUC_UdpNm_00030*/
    uint16 UdpNmMsgTimeoutTime;   
#endif
#if(UDPNM_PASSIVE_MODE_ENABLED == STD_OFF) 
#if(UDPNM_NODE_DETECTION_ENABLED == STD_ON)
    /*ECUC_UdpNm_00031*/
    uint8 UdpNmNodeId;
#endif
#endif
    /*ECUC_UdpNm_00025*/
    UdpNm_PduBytePosType UdpNmPduNidPosition;
    /*ECUC_UdpNm_00026*/
    UdpNm_PduBytePosType UdpNmPduCbvPosition;    
#if(UDPNM_PASSIVE_MODE_ENABLED == STD_OFF) 
#if(UDPNM_REMOTE_SLEEP_IND_ENABLED == STD_ON)
    /*ECUC_UdpNm_00023*/
    uint16 UdpNmRemoteSleepIndTime;
#endif
#endif
    /*ECUC_UdpNm_00022*/
    uint16 UdpNmRepeatMessageTime;
    /*ECUC_UdpNm_00020*/
    uint16 UdpNmTimeoutTime;
    /*ECUC_UdpNm_00021*/
    uint16 UdpNmWaitBusSleepTime;     
    /*ECUC_UdpNm_00018*/
    NetworkHandleType ComMNetworkHandleRef;
    /*ECUC_UdpNm_00024*/
    uint8 UdpNmPduLength;
    uint8 UdpNmPduStartIndex;      
    uint8 UdpNmPduNIDIndex;
    uint8 UdpNmPduCBVIndex; 
#if(UDPNM_USER_DATA_ENABLED == STD_ON || STD_ON == UDPNM_COM_USER_DATA_SUPPORT)
    /*Index in TxBuffer*/
    uint8 UdpNmPduUserDataStartIndex; 
    /*UderData Length*/
    uint8 UdpNmPduUserDataLength; 
#endif
    /*ECUC_UdpNm_00061*/
    boolean UdpNmPnEnabled;
#if(STD_ON == UDPNM_GLOBAL_PN_SUPPORT)     
    /*ECUC_UdpNm_00060*/
    boolean UdpNmPnEraCalcEnabled;
    /*ECUC_UdpNm_00063*/
    boolean UdpNmPnHandleMultipleNetworkRequests;   
    /*ECUC_UdpNm_00073*/
    PduIdType UdpNmPnEraRxNSduRef;
#endif    
#if(UDPNM_PASSIVE_MODE_ENABLED == STD_OFF)
    /*ECUC_UdpNm_00037*/
    PduIdType UdpNmTxPduId;
#if(UDPNM_COM_USER_DATA_SUPPORT == STD_ON)
    /*ECUC_UdpNm_00057*/
    PduIdType UdpNmUserDataTxPduId;
#endif
#endif    
}UdpNm_ChannelConfigType;

typedef struct
{
#if(UDPNM_PASSIVE_MODE_ENABLED == STD_OFF)
    uint16 MsgCycOffsetTimer;
    uint16 MsgCycTimer;
#if(UDPNM_IMMEDIATE_TXCONF_ENABLED == STD_OFF)
    uint16 TxTOTimer;
#endif
#endif
    uint16 NmTOTimer;
    uint16 RptMsgTimer;
    uint16 WbsTimer;
#if(UDPNM_PASSIVE_MODE_ENABLED == STD_OFF) 
#if(UDPNM_REMOTE_SLEEP_IND_ENABLED == STD_ON)
    /*ECUC_UdpNm_00023*/
    uint16 RmtSlpIndTimer;
#endif
#endif
}UdpNm_TimerType;

typedef struct
{
#if(STD_ON == UDPNM_GLOBAL_PN_SUPPORT)
    /*ECUC_UdpNm_00062*/
    PduIdType UdpNmPnEiraRxNSduRef;
#endif
    /*ECUC_UdpNm_00077*/
    uint8 UdpNmCarWakeUpFilterEnabled;  
    /*ECUC_UdpNm_00078*/
    uint8 UdpNmCarWakeUpFilterNodeId;
    /*ECUC_UdpNm_00076*/
    uint8 UdpNmCarWakeUpRxEnabled;
#if(UDPNM_COORDINATOR_ENABLE == STD_ON)    
    /*ECUC_UdpNm_00041*/
    uint8 UdpNmCoordinatorId;
#endif
#if(STD_ON == UDPNM_GLOBAL_PN_SUPPORT)
   /*ECUC_UdpNm_00067*/
   UdpNm_PnFilterMaskByteType* UdpNmPnFilterMask;    
#endif
}UdpNm_ConfigType;

#endif  /*_UDP_NM_TYPES_H_*/

