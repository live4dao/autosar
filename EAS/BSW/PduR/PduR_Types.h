/*  BEGIN_FILE_HDR
********************************************************************************
*     NOTICE
*     This software is the property of HiRain Technologies. Any information
*     contained in this doc should not be reproduced, or used, or disclosed
*     without the written authorization from HiRain Technologies.
********************************************************************************
*     File Name         : PduR_Types.h
********************************************************************************
*     Project/Product : AUTOSAR 4.2
*     Title             : PduR_Types.h
*     Author          : Hirain
********************************************************************************
*     Description     : The header file PduR_Types.h contains the declaration of
*                       types which is used by the PduR module
*
********************************************************************************
*     Limitations     : None
*
********************************************************************************
*
********************************************************************************
*     Revision History:
*     Reference to Core C File
********************************************************************************
* END_FILE_HDR*/
#ifndef PDUR_TYPES_H
#define PDUR_TYPES_H

/*******************************************************************************
*   Includes
*******************************************************************************/
#include "PduR_Cfg.h"

#define PDUR_UNUSED    ((uint16)65535U)

/*SWS_PduR_00771*/
typedef uint8 PduR_PBConfigIdType;
#define PDUR_INVALID_CONFIG_ID  (0xff)


/*SWS_PduR_00654*/
typedef uint16 PduR_RoutingPathGroupIdType;
#define PDUR_RPGROUP_NONE    ((uint16)(0xffff))

typedef struct
{
    uint8  BufState;
    PduLengthType TotalLen;
    PduLengthType ValidLen;
    PduLengthType ReceivedLen;
    PduLengthType AvailableLen;
    PduLengthType WritePos;
    PduLengthType ReadPos;
} PduRBuffInfoType;
typedef enum
{
    PDUR_DIRECT = 0,            /*not buffer the I-PDU*/
    PDUR_TRIGGERTRANSMIT = 1    /*The destination module will request the I-PDU using the
                                 triggerTransmit function. The I-PDU is shall be buffered.*/
} PduR_DestProvisionType;

#define PDUR_TPGW_TRIGGER_IND   ((uint16)2)
#define PDUR_TPGW_TRIGGER_FLY   ((uint16)1)

/*!!!IMPORTANT!!!
  PduRModuleType is in sequence. Index of each member will be used in the code
  So this enumation should be modified with PduR_ModuleFunctions*/
typedef enum
{
#if(STD_ON == PDUR_COM_MODULE_SUPPORT)
    MODULE_COM = 0,
#endif
#if(STD_ON == PDUR_LDCOM_MODULE_SUPPORT)
    MODULE_LDCOM,
#endif
#if(STD_ON == PDUR_DCM_MODULE_SUPPORT)
    MODULE_DCM,
#endif
#if(STD_ON == PDUR_DOIPGW_MODULE_SUPPORT)
    MODULE_DOIPGW,
#endif
#if(STD_ON == PDUR_J1939DCM_MODULE_SUPPORT)
    MODULE_J1939DCM,
#endif
#if(STD_ON == PDUR_J1939RM_MODULE_SUPPORT)
    MODULE_J1939RM,
#endif
#if(STD_ON == PDUR_CDD_MODULE_SUPPORT)
    MODULE_CDD,
#endif
#if(STD_ON == PDUR_IPDUM_MODULE_SUPPORT)
    MODULE_IPDUM,
#endif
#if(STD_ON == PDUR_IPDUMIF_MODULE_SUPPORT)
	MODULE_IPDUMIF,
#endif
#if(STD_ON == PDUR_SOMEIP_MODULE_SUPPORT)
    MODULE_SOMEIP,
#endif
#if(STD_ON == PDUR_SOMEIPTP_MODULE_SUPPORT)
	MODULE_SOMEIPTP,
#endif
#if(STD_ON == PDUR_CANIF_MODULE_SUPPORT)
    MODULE_CANIF,
#endif
#if(STD_ON == PDUR_CANTP_MODULE_SUPPORT)
    MODULE_CANTP,
#endif
#if(STD_ON == PDUR_CANNM_MODULE_SUPPORT)
    MODULE_CANNM,
#endif
#if(STD_ON == PDUR_UDPNM_MODULE_SUPPORT)
    MODULE_UDPNM,
#endif
#if(STD_ON == PDUR_LINIF_MODULE_SUPPORT)
    MODULE_LINIF,
#endif
#if(STD_ON == PDUR_LINTP_MODULE_SUPPORT)
    MODULE_LINTP,
#endif
#if(STD_ON == PDUR_FRIF_MODULE_SUPPORT)
    MODULE_FRIF,
#endif
#if(STD_ON == PDUR_FRTP_MODULE_SUPPORT)
    MODULE_FRTP,
#endif
#if(STD_ON == PDUR_DOIPIF_MODULE_SUPPORT)
    MODULE_DOIPIF,
#endif
#if(STD_ON == PDUR_DOIPTP_MODULE_SUPPORT)
    MODULE_DOIPTP,
#endif
#if(STD_ON == PDUR_J1939TP_MODULE_SUPPORT)
    MODULE_J1939TP,
#endif
#if(STD_ON == PDUR_SOADIF_MODULE_SUPPORT)
    MODULE_SOADIF,
#endif
#if(STD_ON == PDUR_SOADTP_MODULE_SUPPORT)
    MODULE_SOADTP,
#endif
#if(STD_ON == PDUR_CDDIF_MODULE_SUPPORT)
    MODULE_CDDIF,
#endif
#if(STD_ON == PDUR_CDDTP_MODULE_SUPPORT)
    MODULE_CDDTP,
#endif
#if(STD_ON == PDUR_SECOC_MODULE_SUPPORT)
    MODULE_SECOC,
#endif
#if(STD_ON == PDUR_SECOCIF_MODULE_SUPPORT)
	MODULE_SECOCIF,
#endif
#if(STD_ON == PDUR_SECOCTP_MODULE_SUPPORT)
	MODULE_SECOCTP,
#endif
    MODULE_NUM
} PduRModuleType;

/*SWS_PduR_00324 SWS_PduR_00742*/
typedef enum
{
    PDUR_UNINIT  = 0,    /*PDU Router not initialised*/
    PDUR_ONLINE  = 1     /*PDU Router initialized successfully*/
} PduR_StateType;


typedef struct
{
    PduIdType                  PduRSrcPduHandleId;
    PduRModuleType             PduRSrcModuleType;
} PduRSrcPdu_Type;

typedef struct
{
    PduIdType                     PduRDestPduId;
    PduRModuleType                PduRDestModuleType;
    PduR_DestProvisionType        PduRDestPduDataProvision;
    uint16                        PduRTpThreshold;
    uint16                        PduRTpGWTrigger;
    uint16                        PduRDestTxBufferId;
    PduR_RoutingPathGroupIdType   PduRRoutingGroup;
} PduRDestPdu_Type;

typedef struct
{
#if(PDUR_CONFIG_VARIANTS == STD_CONFIG_VARIANTS_PRECOMPILE)
    PduIdType                     PduRDestPduId; /*ECUC_PduR_00322*/
    PduRModuleType                PduRDestModuleType;
    PduR_DestProvisionType        PduRDestPduDataProvision;
    uint16                        PduRDestTxBufferId;
#endif
    uint16                        PduRTpGWTrigger;
    uint16                        PduRTpThreshold;    /*ECUC_PduR_00320*/
    boolean                       PduRTxConfirmation; /*ECUC_PduR_00339*/

#if(PDUR_CONFIG_VARIANTS == STD_CONFIG_VARIANTS_PRECOMPILE)
    PduR_RoutingPathGroupIdType   PduRRoutingGroup;
#endif
} PduRDestPdu_PcType;

typedef struct
{
    CONST(PduRSrcPdu_Type, PDUR_CONST)  PduRSrcPdu;     /*for up-to-ower, id of TxPduId
                                                          for lower, id of RxPduId*/
    CONST(PduRDestPdu_Type, PDUR_CONST) PduRDestPdu;
    CONST(PduR_MulticastMaskType, PDUR_CONST) ConfMask; /*for up-to-lower, each dest of the same src takes one bit;
                                             for lower-to-up, always zero
                                             for lower-to-lower, each buffered dest of the same src takes one bit*/
} PduRRoutingPathInfoType;


typedef struct
{
    CONST(PduR_RoutingPathIdType, PDUR_CONST)  NumPaths;
    P2CONST(PduR_RoutingPathIdType, AUTOMATIC, PDUR_CONST) PathIdx;  /*pointer to an array containning path ids*/
    CONST(PduR_MulticastMaskType, PDUR_CONST)  ConfMask; /*sum of paths' ConfMask*/
} PduRRoutingPduInfoType;


typedef struct
{
    PduR_RoutingPathIdType PathId;    /*ECUC_PduR_00322*/
    PduIdType              UpperPduId;
} PduRTxConfMapping_Type;

typedef struct
{
    PduR_RoutingPathIdType PathId;
} PduRRxCancelMapping_Type;


/*SWS_PduR_00743 SWS_PduR_00241*/
typedef struct
{
    CONST(PduR_PBConfigIdType, PDUR_CONST)          PBConfigId;  /*ECUC_PduR_00327*/
    CONST(PduR_RoutingPathIdType, PDUR_CONST)       RoutingPathNum;
    CONST(uint16, PDUR_CONST)                       BufferNum;
    CONSTP2CONST(PduRRoutingPathInfoType, AUTOMATIC, PDUR_CONST) pRoutingTbl;
    CONST(PduR_RoutingPathGroupIdType, PDUR_CONST)  RoutingPathGroupNum;
    P2CONST(boolean, AUTOMATIC, PDUR_CONST)         RPGroupEnabledAtInit;
#if(STD_ON == PDUR_COM_MODULE_SUPPORT)
    CONST(PduR_RoutingPathIdType, PDUR_CONST)       ComTxPathNum;
    CONSTP2CONST(PduRRoutingPduInfoType, AUTOMATIC, PDUR_CONST) pComTxPduInfo;
#endif
#if(STD_ON == PDUR_LDCOM_MODULE_SUPPORT)
    CONST(PduR_RoutingPathIdType, PDUR_CONST)       LdComTxPathNum;
    CONSTP2CONST(PduRRoutingPduInfoType, AUTOMATIC, PDUR_CONST) pLdComTxPduInfo;
#endif
#if(STD_ON == PDUR_DCM_MODULE_SUPPORT)
    CONST(PduR_RoutingPathIdType, PDUR_CONST)       DcmTxPathNum;
    CONSTP2CONST(PduRRoutingPduInfoType, AUTOMATIC, PDUR_CONST) pDcmTxPduInfo;
    CONST(PduR_RoutingPathIdType, PDUR_CONST)       DcmRxPathNum;
    CONSTP2CONST(PduRRxCancelMapping_Type, AUTOMATIC, PDUR_CONST) pDcmCancelRxPduInfo;
#endif
#if(STD_ON == PDUR_DOIPGW_MODULE_SUPPORT)
    CONST(PduR_RoutingPathIdType, PDUR_CONST)       DoIPGWRxPathNum;
    CONSTP2CONST(PduRRxCancelMapping_Type, AUTOMATIC, PDUR_CONST) pDoIPGWCancelRxPduInfo;
#endif
#if(STD_ON == PDUR_J1939DCM_MODULE_SUPPORT)
    CONST(PduR_RoutingPathIdType, PDUR_CONST)       J1939DcmTxPathNum;
    CONSTP2CONST(PduRRoutingPduInfoType, AUTOMATIC, PDUR_CONST) pJ1939DcmTxPduInfo;
    CONST(PduR_RoutingPathIdType, PDUR_CONST)       J1939DcmRxPathNum;
    CONSTP2CONST(PduRRxCancelMapping_Type, AUTOMATIC, PDUR_CONST) pJ1939DcmCancelRxPduInfo;
#endif
#if(STD_ON == PDUR_J1939RM_MODULE_SUPPORT)
    CONST(PduR_RoutingPathIdType, PDUR_CONST)       J1939RmTxPathNum;
    CONSTP2CONST(PduRRoutingPduInfoType, AUTOMATIC, PDUR_CONST) pJ1939RmTxPduInfo;
#endif
#if(STD_ON == PDUR_CDD_MODULE_SUPPORT)
    CONST(PduR_RoutingPathIdType, PDUR_CONST)       CddRxPathNum;
    CONSTP2CONST(PduRRxCancelMapping_Type, AUTOMATIC, PDUR_CONST) pCddCancelRxPduInfo;
    CONST(PduR_RoutingPathIdType, PDUR_CONST)       CddTxPathNum;
    CONSTP2CONST(PduRRoutingPduInfoType, AUTOMATIC, PDUR_CONST) pCddTxPduInfo;
#endif
#if(STD_ON == PDUR_IPDUM_MODULE_SUPPORT)
    CONST(PduR_RoutingPathIdType, PDUR_CONST)       IpduMTxConfPathNum;
    CONSTP2CONST(PduRTxConfMapping_Type, AUTOMATIC, PDUR_CONST) pIpduMTxConfPduInfo;
#endif
#if(STD_ON == PDUR_IPDUMIF_MODULE_SUPPORT)
    CONST(PduR_RoutingPathIdType, PDUR_CONST)       IpduMIfRxPathNum;
    CONSTP2CONST(PduRRoutingPduInfoType, AUTOMATIC, PDUR_CONST) pIpduMIfRxPduInfo;
    CONST(PduR_RoutingPathIdType, PDUR_CONST)       IpduMIfTxConfPathNum;
    CONSTP2CONST(PduRTxConfMapping_Type, AUTOMATIC, PDUR_CONST) pIpduMIfTxConfPduInfo;
#endif
#if(STD_ON == PDUR_SOMEIP_MODULE_SUPPORT)
    CONST(PduR_RoutingPathIdType, PDUR_CONST)       SomeIpTxConfPathNum;
    CONSTP2CONST(PduRTxConfMapping_Type, AUTOMATIC, PDUR_CONST) pSomeIpTxConfPduInfo;
#endif
#if(STD_ON == PDUR_SOMEIPTP_MODULE_SUPPORT)
    CONST(PduR_RoutingPathIdType, PDUR_CONST)       SomeIpTpRxPathNum;
    CONSTP2CONST(PduRRoutingPduInfoType, AUTOMATIC, PDUR_CONST) pSomeIpTpRxPduInfo;
    CONST(PduR_RoutingPathIdType, PDUR_CONST)       SomeIpTpTxConfPathNum;
    CONSTP2CONST(PduRTxConfMapping_Type, AUTOMATIC, PDUR_CONST) pSomeIpTpTxConfPduInfo;
#endif
#if(STD_ON == PDUR_CANIF_MODULE_SUPPORT)
    CONST(PduR_RoutingPathIdType, PDUR_CONST)       CanIfRxPathNum;
    CONSTP2CONST(PduRRoutingPduInfoType, AUTOMATIC, PDUR_CONST) pCanIfRxPduInfo;
    CONST(PduR_RoutingPathIdType, PDUR_CONST)       CanIfTxConfPathNum;
    CONSTP2CONST(PduRTxConfMapping_Type, AUTOMATIC, PDUR_CONST) pCanIfTxConfPduInfo;
#endif
#if(STD_ON == PDUR_CANTP_MODULE_SUPPORT)
    CONST(PduR_RoutingPathIdType, PDUR_CONST)       CanTpRxPathNum;
    CONSTP2CONST(PduRRoutingPduInfoType, AUTOMATIC, PDUR_CONST) pCanTpRxPduInfo;
    CONST(PduR_RoutingPathIdType, PDUR_CONST)       CanTpTxConfPathNum;
    CONSTP2CONST(PduRTxConfMapping_Type, AUTOMATIC, PDUR_CONST) pCanTpTxConfPduInfo;
#endif
#if(STD_ON == PDUR_CANNM_MODULE_SUPPORT)
    CONST(PduR_RoutingPathIdType, PDUR_CONST)       CanNmRxPathNum;
    CONSTP2CONST(PduRRoutingPduInfoType, AUTOMATIC, PDUR_CONST) pCanNmRxPduInfo;
    CONST(PduR_RoutingPathIdType, PDUR_CONST)       CanNmTxConfPathNum;
    CONSTP2CONST(PduRTxConfMapping_Type, AUTOMATIC, PDUR_CONST) pCanNmTxConfPduInfo;
#endif
#if(STD_ON == PDUR_UDPNM_MODULE_SUPPORT)
    CONST(PduR_RoutingPathIdType, PDUR_CONST)       UdpNmRxPathNum;
    CONSTP2CONST(PduRRoutingPduInfoType, AUTOMATIC, PDUR_CONST) pUdpNmRxPduInfo;
    CONST(PduR_RoutingPathIdType, PDUR_CONST)       UdpNmTxConfPathNum;
    CONSTP2CONST(PduRTxConfMapping_Type, AUTOMATIC, PDUR_CONST) pUdpNmTxConfPduInfo;
#endif
#if(STD_ON == PDUR_LINIF_MODULE_SUPPORT)
    CONST(PduR_RoutingPathIdType, PDUR_CONST)       LinIfRxPathNum;
    CONSTP2CONST(PduRRoutingPduInfoType, AUTOMATIC, PDUR_CONST) pLinIfRxPduInfo;
    CONST(PduR_RoutingPathIdType, PDUR_CONST)       LinIfTxConfPathNum;
    CONSTP2CONST(PduRTxConfMapping_Type, AUTOMATIC, PDUR_CONST) pLinIfTxConfPduInfo;
#endif
#if(STD_ON == PDUR_LINTP_MODULE_SUPPORT)
    CONST(PduR_RoutingPathIdType, PDUR_CONST)       LinTpRxPathNum;
    CONSTP2CONST(PduRRoutingPduInfoType, AUTOMATIC, PDUR_CONST) pLinTpRxPduInfo;
    CONST(PduR_RoutingPathIdType, PDUR_CONST)       LinTpTxConfPathNum;
    CONSTP2CONST(PduRTxConfMapping_Type, AUTOMATIC, PDUR_CONST) pLinTpTxConfPduInfo;
#endif
#if(STD_ON == PDUR_FRIF_MODULE_SUPPORT)
    CONST(PduR_RoutingPathIdType, PDUR_CONST)       FrIfRxPathNum;
    CONSTP2CONST(PduRRoutingPduInfoType, AUTOMATIC, PDUR_CONST) pFrIfRxPduInfo;
    CONST(PduR_RoutingPathIdType, PDUR_CONST)       FrIfTxConfPathNum;
    CONSTP2CONST(PduRTxConfMapping_Type, AUTOMATIC, PDUR_CONST) pFrIfTxConfPduInfo;
#endif
#if(STD_ON == PDUR_FRTP_MODULE_SUPPORT)
    CONST(PduR_RoutingPathIdType, PDUR_CONST)       FrTpRxPathNum;
    CONSTP2CONST(PduRRoutingPduInfoType, AUTOMATIC, PDUR_CONST) pFrTpRxPduInfo;
    CONST(PduR_RoutingPathIdType, PDUR_CONST)       FrTpTxConfPathNum;
    CONSTP2CONST(PduRTxConfMapping_Type, AUTOMATIC, PDUR_CONST) pFrTpTxConfPduInfo;
#endif
#if(STD_ON == PDUR_SOADIF_MODULE_SUPPORT)
    CONST(PduR_RoutingPathIdType, PDUR_CONST)       SoAdIfRxPathNum;
    CONSTP2CONST(PduRRoutingPduInfoType, AUTOMATIC, PDUR_CONST) pSoAdIfRxPduInfo;
    CONST(PduR_RoutingPathIdType, PDUR_CONST)       SoAdIfTxConfPathNum;
    CONSTP2CONST(PduRTxConfMapping_Type, AUTOMATIC, PDUR_CONST) pSoAdIfTxConfPduInfo;
#endif
#if(STD_ON == PDUR_SOADTP_MODULE_SUPPORT)
    CONST(PduR_RoutingPathIdType, PDUR_CONST)       SoAdTpRxPathNum;
    CONSTP2CONST(PduRRoutingPduInfoType, AUTOMATIC, PDUR_CONST) pSoAdTpRxPduInfo;
    CONST(PduR_RoutingPathIdType, PDUR_CONST)       SoAdTpTxConfPathNum;
    CONSTP2CONST(PduRTxConfMapping_Type, AUTOMATIC, PDUR_CONST) pSoAdTpTxConfPduInfo;
#endif
#if(STD_ON == PDUR_DOIPIF_MODULE_SUPPORT)
    CONST(PduR_RoutingPathIdType, PDUR_CONST)       DoIPIfTxConfPathNum;
    CONSTP2CONST(PduRTxConfMapping_Type, AUTOMATIC, PDUR_CONST) pDoIPIfTxConfPduInfo;
#endif
#if(STD_ON == PDUR_DOIPTP_MODULE_SUPPORT)
    CONST(PduR_RoutingPathIdType, PDUR_CONST)       DoIPTpRxPathNum;
    CONSTP2CONST(PduRRoutingPduInfoType, AUTOMATIC, PDUR_CONST) pDoIPTpRxPduInfo;
    CONST(PduR_RoutingPathIdType, PDUR_CONST)       DoIPTpTxConfPathNum;
    CONSTP2CONST(PduRTxConfMapping_Type, AUTOMATIC, PDUR_CONST) pDoIPTpTxConfPduInfo;
#endif
#if(STD_ON == PDUR_J1939TP_MODULE_SUPPORT)
    CONST(PduR_RoutingPathIdType, PDUR_CONST)       J1939TpRxPathNum;
    CONSTP2CONST(PduRRoutingPduInfoType, AUTOMATIC, PDUR_CONST) pJ1939TpRxPduInfo;
    CONST(PduR_RoutingPathIdType, PDUR_CONST)       J1939TpTxConfPathNum;
    CONSTP2CONST(PduRTxConfMapping_Type, AUTOMATIC, PDUR_CONST) pJ1939TpTxConfPduInfo;
#endif
#if(STD_ON == PDUR_CDDIF_MODULE_SUPPORT)
    CONST(PduR_RoutingPathIdType, PDUR_CONST)       CddIfRxPathNum;
    CONSTP2CONST(PduRRoutingPduInfoType, AUTOMATIC, PDUR_CONST) pCddIfRxPduInfo;
    CONST(PduR_RoutingPathIdType, PDUR_CONST)       CddIfTxConfPathNum;
    CONSTP2CONST(PduRTxConfMapping_Type, AUTOMATIC, PDUR_CONST) pCddIfTxConfPduInfo;
#endif
#if(STD_ON == PDUR_CDDTP_MODULE_SUPPORT)
    CONST(PduR_RoutingPathIdType, PDUR_CONST)       CddTpRxPathNum;
    CONSTP2CONST(PduRRoutingPduInfoType, AUTOMATIC, PDUR_CONST) pCddTpRxPduInfo;
    CONST(PduR_RoutingPathIdType, PDUR_CONST)       CddTpTxConfPathNum;
    CONSTP2CONST(PduRTxConfMapping_Type, AUTOMATIC, PDUR_CONST) pCddTpTxConfPduInfo;
#endif
#if(STD_ON == PDUR_SECOC_MODULE_SUPPORT)
    CONST(PduR_RoutingPathIdType, PDUR_CONST)       SecOCRxPathNum;
    CONSTP2CONST(PduRRoutingPduInfoType, AUTOMATIC, PDUR_CONST) pSecOCRxPduInfo;
    CONST(PduR_RoutingPathIdType, PDUR_CONST)       SecOCTxConfPathNum;
    CONSTP2CONST(PduRTxConfMapping_Type, AUTOMATIC, PDUR_CONST) pSecOCTxConfPduInfo;
    CONSTP2CONST(PduRRxCancelMapping_Type, AUTOMATIC, PDUR_CONST) pSecOCCancelRxPduInfo;
#endif
#if(STD_ON == PDUR_SECOCIF_MODULE_SUPPORT)
    CONST(PduR_RoutingPathIdType, PDUR_CONST)       SecOCIfRxPathNum;
    CONSTP2CONST(PduRRoutingPduInfoType, AUTOMATIC, PDUR_CONST) pSecOCIfRxPduInfo;
    CONST(PduR_RoutingPathIdType, PDUR_CONST)       SecOCIfTxConfPathNum;
    CONSTP2CONST(PduRTxConfMapping_Type, AUTOMATIC, PDUR_CONST) pSecOCIfTxConfPduInfo;
#endif
#if(STD_ON == PDUR_SECOCTP_MODULE_SUPPORT)
    CONST(PduR_RoutingPathIdType, PDUR_CONST)       SecOCTpRxPathNum;
    CONSTP2CONST(PduRRoutingPduInfoType, AUTOMATIC, PDUR_CONST) pSecOCTpRxPduInfo;
    CONST(PduR_RoutingPathIdType, PDUR_CONST)       SecOCTpTxConfPathNum;
    CONSTP2CONST(PduRTxConfMapping_Type, AUTOMATIC, PDUR_CONST) pSecOCTpTxConfPduInfo;
#endif
} PduR_PBConfigType;



typedef P2FUNC(Std_ReturnType, PDUR_APPL_CODE, PduR_TransmitFctPtrType) (PduIdType, P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA));
typedef P2FUNC(Std_ReturnType, PDUR_APPL_CODE, PduR_TriggerTransmitFctPtrType) (PduIdType, P2VAR(PduInfoType, AUTOMATIC, PDUR_APPL_DATA));
typedef P2FUNC(void, PDUR_APPL_CODE, PduR_IfRxIndicationType) (PduIdType, P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA));
typedef P2FUNC(void, PDUR_APPL_CODE, PduR_IfTxConfirmationFctPtrType) (PduIdType);

typedef P2FUNC(BufReq_ReturnType, PDUR_APPL_CODE, PduR_StartOfReceptionFctPtrType) (PduIdType, P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA), PduLengthType, P2VAR(PduLengthType, AUTOMATIC, PDUR_APPL_DATA));
typedef P2FUNC(BufReq_ReturnType, PDUR_APPL_CODE, PduR_CopyRxDataFctPtrType) (PduIdType, P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA), P2VAR(PduLengthType, AUTOMATIC, PDUR_APPL_DATA));
typedef P2FUNC(BufReq_ReturnType, PDUR_APPL_CODE, PduR_CopyTxDataFctPtrType) (PduIdType, P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA), P2VAR(RetryInfoType, AUTOMATIC, PDUR_APPL_DATA), P2VAR(PduLengthType, AUTOMATIC, PDUR_APPL_DATA));
typedef P2FUNC(void, PDUR_APPL_CODE, PduR_TpRxIndicationFctPtrType) (PduIdType, Std_ReturnType);
typedef P2FUNC(void, PDUR_APPL_CODE, PduR_TpTxConfirmationFctPtrType) (PduIdType, Std_ReturnType);


typedef P2FUNC(Std_ReturnType, PDUR_APPL_CODE, PduR_CancelTransmitFctPtrType)(PduIdType);
typedef P2FUNC(Std_ReturnType, PDUR_APPL_CODE, PduR_ChangeParameterFctPtrType) (PduIdType, TPParameterType, uint16);


typedef P2FUNC(Std_ReturnType, PDUR_APPL_CODE, PduR_TpCancelReceiveFctPtrType) (PduIdType);

typedef struct
{
#if(STD_ON == PDUR_CANCEL_TRANSMIT_ENABLED)
    PduR_CancelTransmitFctPtrType IfCancelTransmitFunc;
#endif
    PduR_TransmitFctPtrType IfTransmitFunc;
#if(STD_ON == PDUR_CANCEL_RECEIVE_ENABLED)
    PduR_TpCancelReceiveFctPtrType TpCancelReceiveFunc;
#endif
#if(STD_ON == PDUR_CANCEL_TRANSMIT_ENABLED)
    PduR_CancelTransmitFctPtrType TpCancelTransmitFunc;
#endif
    PduR_TransmitFctPtrType TpTransmitFunc;
#if(STD_ON == PDUR_CHANGEPARAMETER_API_ENABLED)
    PduR_ChangeParameterFctPtrType TpChangeParameterFunc;
#endif
    PduR_IfRxIndicationType UpIfRxIndicationFunc;
    PduR_TriggerTransmitFctPtrType UpIfTriggerTransmitFunc;
    PduR_IfTxConfirmationFctPtrType UpIfTxConfirmationFunc;
    PduR_CopyRxDataFctPtrType UpTpCopyRxDataFunc;
    PduR_CopyTxDataFctPtrType UpTpCopyTxDataFunc;
    PduR_StartOfReceptionFctPtrType UpTpStartOfReceptionFunc;
    PduR_TpRxIndicationFctPtrType UpTpRxIndicationFunc;
    PduR_TpTxConfirmationFctPtrType UpTpTxConfirmationFunc;
} PduR_ModuleFunc;
#endif /* PDUR_TYPES_H */

