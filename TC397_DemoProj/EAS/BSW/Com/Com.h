/*  BEGIN_FILE_HDR
********************************************************************************
*   NOTICE
*   This software is the property of HiRain Technologies. Any information
*   contained in this doc should not be reproduced, or used, or disclosed
*   without the written authorization from HiRain Technologies.
********************************************************************************
*   File Name      : Com.h
********************************************************************************
*   Project/Product: AUTOSAR 4.2
*   Title          : com.h
*   Author         : Hirain
********************************************************************************
*   Description:     Com module head File
*
********************************************************************************
*   Limitations:      None
*
********************************************************************************
*
********************************************************************************
*   Revision History:
*   Reference to Core C File
********************************************************************************
*END_FILE_HDR*/

#ifndef COM_H
#define COM_H
/*******************************************************************************
*   Includes
*******************************************************************************/
#include "Bsw_Common.h"

#include "Com_Lcfg.h"
#include "Com_Code.h"
#include "Com_PBcfg.h"

#include "PduR_Com.h"


/*******************************************************************************
*   Macro
*******************************************************************************/
/* Det Error SWS_Com_00804 804 805 837 864*/
#define COM_E_PARAM                    ((uint8)0x01)
#define COM_E_UNINIT                   ((uint8)0x02)
#define COM_E_PARAM_POINTER            ((uint8)0x03)
#define COM_E_INIT_FAILED              ((uint8)0x04)
#define COM_E_SKIP_TRANSMISSION        ((uint8)0x05)


/* API ID*/
#define COMServiceId_Init                                ((uint8)0x01)
#define COMServiceId_DeInit                              ((uint8)0x02)
#if (STD_ON == COM_IPDU_GROUP_FUN)
#define COMServiceId_IpduGroupControl                    ((uint8)0x03)
#define COMServiceId_ReceptionDMControl                  ((uint8)0x06)
#endif

#define COMServiceId_GetStatus                           ((uint8)0x07)
#define COMServiceId_GetConfigurationId                  ((uint8)0x08)
#define COMServiceId_GetVersionInfo                      ((uint8)0x09)
#define COMServiceId_SendSignal                          ((uint8)0x0A)
#define COMServiceId_ReceiveSignal                       ((uint8)0x0B)
#define COMServiceId_UpdateShadowSignal                  ((uint8)0x0C)
#define COMServiceId_SendSignalGroup                     ((uint8)0x0D)
#define COMServiceId_ReceiveSignalGroup                  ((uint8)0x0E)
#define COMServiceId_ReceiveShadowSignal                 ((uint8)0x0F)
#define COMServiceId_InvalidateSignal                    ((uint8)0x10)
#define COMServiceId_InvalidateShadowSignal              ((uint8)0x16)
#define COMServiceId_TriggerIPDUSend                     ((uint8)0x17)
#define COMServiceId_MainFunctionRx                      ((uint8)0x18)
#define COMServiceId_MainFunctionTx                      ((uint8)0x19)
#define COMServiceId_MainFunctionRouteSignals            ((uint8)0x1A)
#define COMServiceId_InvalidateSignalGroup               ((uint8)0x1B)

#define COMServiceId_ReceiveSignalGroupArray             ((uint8)0x24)
#define COMServiceId_SendSignalGroupArray                ((uint8)0x23)

#if (STD_ON == COM_IPDU_GROUP_FUN)
#define COMServiceId_ClearIpduGroupVector                ((uint8)0x1C)
#define COMServiceId_SetIpduGroup                        ((uint8)0x1D)
#endif
#define COMServiceId_TpRxIndication                      ((uint8)0x1E)
#define COMServiceId_SendDynSignal                       ((uint8)0x21)
#define COMServiceId_ReceiveDynSignal                    ((uint8)0x22)
#define COMServiceId_CopyRxData                          ((uint8)0x23)
#define COMServiceId_CopyTxData                          ((uint8)0x24)
#define COMServiceId_StartOfReception                    ((uint8)0x25)
#define COMServiceId_TpTxConfirmation                    ((uint8)0x26)
#define COMServiceId_SwitchIpduTxMode                    ((uint8)0x27)
#define COMServiceId_TxConfirmation                      ((uint8)0x40)
#define COMServiceId_TriggerTransmit                     ((uint8)0x41)
#define COMServiceId_RxIndication                        ((uint8)0x42)

#define COMServiceId_StartGroup                          ((uint8)0x51)
#define COMServiceId_StopGroup                           ((uint8)0x52)
#define COMServiceId_StartRXDMGroup                      ((uint8)0x53)
#define COMServiceId_StopRXDMGroup                       ((uint8)0x54)

#define COMServiceId_GetIpduGroupState                   ((uint8)0xF0)
#define COMServiceId_GetTxIpduState                      ((uint8)0xF1)
#define COMServiceId_GetRxIpduState                      ((uint8)0xF2)

/* SWS_Com_00865 */
#define COM_SERVICE_NOT_AVAILABLE    ((uint8)0x80)
#define COM_BUSY                     ((uint8)0x81)

#define COM_TIMER_STOP_VAL                              ((uint16)0xFFFF)
#define COM_INVALID_SIG_INDEX                           ((Com_SignalIdType)0xFFFF)


#define COM_RX_SIGNAL_OK                                ((uint8)0)
#define COM_RX_SIGNAL_INVALD                            ((uint8)1)
#define COM_RX_SIGNAL_NOT_PASS_FILTER                   ((uint8)2)


#define COM_GET_BYTEINX_SHIFT_VALUE                     ((uint16)3)
#define COM_GET_BITPOS_RES_VALUE                        ((uint16)8)


#define COM_EVENT_TX_NONE       ((uint8)0)
#define COM_EVENT_NOTX_REP      ((uint8)1)
#define COM_EVENT_TX_ONCE       ((uint8)2)
#define COM_EVENT_TX_REP        ((uint8)3)



/*******************************************************************************
*   Api
*******************************************************************************/
#define COM_START_SEC_CODE
#include "MemMap.h"


extern FUNC(void, COM_CODE) Com_Init
(
    P2CONST(Com_ConfigType, AUTOMATIC, COM_CONST) ConfigPtr
);

extern FUNC(void, COM_CODE) Com_DeInit
(
    void
);

extern FUNC(Com_StatusType, COM_CODE) Com_GetStatus
(
    void
);

extern FUNC(uint8, COM_CODE) Com_SendSignal
(
    Com_SignalIdType SignalId,
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);
extern FUNC(uint8, COM_CODE) Com_SendDynSignal
(
    Com_SignalIdType SignalId,
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr,
    uint16 Length
);
extern FUNC(uint8, COM_CODE) Com_InvalidateSignal
(
    Com_SignalIdType SignalId
);
extern FUNC(Std_ReturnType, COM_CODE) Com_TriggerIPDUSend
(
    PduIdType PduId
);
extern FUNC(void, COM_CODE) Com_SwitchIpduTxMode
(
    PduIdType PduId,
    boolean Mode
);

extern FUNC(uint8, COM_CODE) Com_ReceiveSignal
(
    Com_SignalIdType SignalId,
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

extern FUNC(uint8, COM_CODE) Com_ReceiveDynSignal
(
    Com_SignalIdType SignalId,
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr,
    P2VAR(uint16, AUTOMATIC, COM_APPL_DATA) Length
);

extern FUNC(void, COM_CODE) Com_MainFunctionRx
(
    void
);

extern FUNC(void, COM_CODE) Com_MainFunctionTx
(
    void
);
extern FUNC(void, COM_CODE) Com_MainFunctionRouteSignals
(
    void
);



#if(STD_ON == COM_IPDU_GROUP_FUN)
extern FUNC(void, COM_CODE) Com_IpduGroupControl
(
    Com_IpduGroupVector ipduGroupVector,
    boolean Initialize
);

#if(STD_ON == COM_RX_TIMEOUT_MONITOR)
extern FUNC(void, COM_CODE) Com_ReceptionDMControl
(
    Com_IpduGroupVector ipduGroupVector
);
#endif

extern FUNC(void, COM_CODE) Com_ClearIpduGroupVector
(
    Com_IpduGroupVector ipduGroupVector
);
extern FUNC(void, COM_CODE) Com_SetIpduGroup
(
    Com_IpduGroupVector ipduGroupVector,
    Com_IpduGroupIdType ipduGroupId,
    boolean bitval
);

extern FUNC(boolean, COM_CODE) Com_GetIpduGroupState
(
    Com_IpduGroupIdType IpduGroupId
);

#endif


#if(STD_ON == COM_PUBLIC_VERSION_INFO_API)
extern FUNC(void, COM_CODE) Com_GetVersionInfo
(
    P2VAR(Std_VersionInfoType, AUTOMATIC, COM_APPL_DATA) VersionInfo
);
#endif




#if (STD_ON == COM_IPDU_GROUP_FUN)

extern FUNC(boolean, COM_CODE) Com_GetIpduGroupState
(
    Com_IpduGroupIdType IpduGroupId
);

#if (STD_ON == COM_GROUP_API_R3_SUPPORT)
extern FUNC(void, COM_CODE) Com_IpduGroupStart
(
    Com_IpduGroupIdType IpduGroupId,
    boolean Initialize
);

extern FUNC(void, COM_CODE) Com_IpduGroupStop
(
    Com_IpduGroupIdType IpduGroupId
);

#if(STD_ON == COM_RX_TIMEOUT_MONITOR)
extern FUNC(void, COM_CODE) Com_EnableReceptionDM
(
    Com_IpduGroupIdType IpduGroupId
);
extern FUNC(void, COM_CODE) Com_DisableReceptionDM
(
    Com_IpduGroupIdType IpduGroupId
);
#endif
#endif

#endif


extern FUNC(uint8, COM_CODE) Com_SendSignalGroup
(
    Com_SignalGroupIdType SignalGroupId
);

extern FUNC(uint8, COM_CODE) Com_InvalidateSignalGroup
(
    Com_SignalGroupIdType SignalGroupId
);

#if((STD_ON == COM_Enable_SignalGroupArrayApi) && (STD_ON == COM_TX_SIGNAL_GROUP_SUPPORT))
extern FUNC(uint8, COM_CODE) Com_SendSignalGroupArray
(
    Com_SignalGroupIdType SignalGroupId,
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA)  SignalGroupArrayPtr
);
#endif


extern FUNC(uint8, COM_CODE) Com_ReceiveSignalGroup
(
    Com_SignalGroupIdType SignalGroupId
);


#if((STD_ON == COM_Enable_SignalGroupArrayApi) && (STD_ON == COM_RX_SIGNAL_GROUP_SUPPORT))
extern FUNC(uint8, COM_CODE) Com_ReceiveSignalGroupArray
(
    Com_SignalGroupIdType SignalGroupId,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA)  SignalGroupArrayPtr
);
#endif

#if(STD_ON == COM_TXPDU_FUN)
extern FUNC(uint8, COM_CODE) Com_WriteSignal_Internal
(
    Com_SignalIdType SignalId,
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr,
    PduLengthType length
);
#endif


#if(STD_ON == COM_TXPDU_FUN)
extern FUNC(boolean, COM_CODE) Com_GetTxIpduState
(
     PduIdType TxPduId
);
#endif

#if(STD_ON == COM_RXPDU_FUN)
extern FUNC(boolean, COM_CODE) Com_GetRxIpduState
(
     PduIdType RxPduId
);
#endif


#define COM_STOP_SEC_CODE
#include "MemMap.h"


#endif/*#ifndef _COM_H_*/
