/*  BEGIN_FILE_HDR
********************************************************************************
*   NOTICE
*   This software is the property of HiRain Technologies. Any information
*   contained in this doc should not be reproduced, or used, or disclosed
*   without the written authorization from HiRain Technologies.
********************************************************************************
*   File Name       : PduR.h
********************************************************************************
*   Project/Product : AUTOSAR 4.2
*   Title           : PduR.h
*   Author          : Hirain
********************************************************************************
*   Description     : PduR.h
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
#ifndef PDUR_H
#define PDUR_H

/*******************************************************************************
*   Includes
*******************************************************************************/
#include "PduR_PBcfg.h"
#include "PduR_Version.h"


#if(STD_OFF == PDUR_ZERO_COST_OPERATION)
/*******************************************************************************
*   Macro
*******************************************************************************/
/* Development Error */

/*SWS_PduR_00100 SWS_PDUR_00816*/
#define PDUR_E_CONFIG_PTR_INVALID               ((uint8)0x00)
#define PDUR_E_INVALID_REQUEST                  ((uint8)0x01)
#define PDUR_E_PDU_ID_INVALID                   ((uint8)0x02)
#define PDUR_E_TP_TX_REQ_REJECTED               ((uint8)0x03)
#define PDUR_E_PARAM_INVALID                    ((uint8)0x04)
#define PDUR_E_DUPLICATE_IPDU_ID                ((uint8)0x06)
#define PDUR_E_IPDU_TOO_LONG                    ((uint8)0x07)
#define PDUR_E_ROUTING_PATH_GROUP_ID_INVALID    ((uint8)0x08)
#define PDUR_E_PARAM_POINTER                    ((uint8)0x09)
#define PDUR_E_PDU_INSTANCES_LOST               ((uint8)0x0a)
#define PDUR_E_INIT_FAILED                      ((uint8)0x0b)

/* Non Autosar Standard */
#define PDUR_E_DEST_TXBUF_ID_INVALID            ((uint8)0x0c)
#define PDUR_E_DEST_NUM_TOO_MUCH                ((uint8)0x0d)
#define PDUR_E_DEST_TRIGGER_INVALID             ((uint8)0x0e)

/*API ID*/
/*******************************************************************************
Up APIID: 0x<UpModId>9, 0x<UpModId>a, 0x<UpModId>b, 0x<UpModId>c
LoIf APIID: 0x<LoIfModId>1, 0x<UpModId>2, 0x<UpModId>3
LoTp APIID: 0x<LoTpModId>4, 0x<LoTpModId>5, 0x<LoTpModId>6, 0x<LoTpModId>7, 0x<LoTpModId>8

ModId:  0      1      2      3      4      5      6      7      8      9      a
Up:                SomeIpTp                     LdCom          Com    Dcm   IpduM
LoIf: CanIf  CanNm  IpduM   FrIf   FrNm  LinIf  SoAd   CddIf  UdpNm   DoIP
LoTp: CanTp 1939Tp SomeIpTp FrTp         LinTp  SoAd   CddTp          DoIP


ModId:  b      c      d      e      f
Up:           Cdd   SecOC J1939Rm J1939Dcm
LoIf:               SecOC          PduR
LoTp:               SecOC          PduR
*******************************************************************************/
#define PDUR_INIT_APIID                          ((uint8)0xf0)
#define PDUR_GETVERSIONINFO_APIID                ((uint8)0xf1)
#define PDUR_GETCONFIGURATIONID_APIID            ((uint8)0xf2)
#define PDUR_ENABLE_ROUTING_APIID                ((uint8)0xf3)
#define PDUR_DISABLE_ROUTING_APIID               ((uint8)0xf4)

#define PDUR_COM_TRANSMIT_APIID                  ((uint8)0x89)
#define PDUR_COM_CANCEL_TRANSMIT_APIID           ((uint8)0x8a)
#define PDUR_COM_CANCEL_RECEIVE_APIID            ((uint8)0x8c)

#define PDUR_LDCOM_TRANSMIT_APIID                ((uint8)0x69)

#define PDUR_DCM_TRANSMIT_APIID                  ((uint8)0x99)
#define PDUR_DCM_CANCEL_TRANSMIT_APIID           ((uint8)0x9a)
#define PDUR_DCM_CHANGEPARAMETER_APIID           ((uint8)0x9b)
#define PDUR_DCM_CANCEL_RECEIVE_APIID            ((uint8)0x9c)

#define PDUR_J1939DCM_TRANSMIT_APIID             ((uint8)0xf9)
#define PDUR_J1939DCM_CANCEL_TRANSMIT_APIID      ((uint8)0xfa)
#define PDUR_J1939DCM_CANCEL_RECEIVE_APIID       ((uint8)0xfc)

#define PDUR_J1939RM_TRANSMIT_APIID              ((uint8)0xe9)
#define PDUR_J1939RM_CANCEL_TRANSMIT_APIID       ((uint8)0xea)
#define PDUR_J1939RM_CANCEL_RECEIVE_APIID        ((uint8)0xec)

#define PDUR_CDD_TRANSMIT_APIID                  ((uint8)0xc9)
#define PDUR_CDD_CANCEL_TRANSMIT_APIID           ((uint8)0xca)
#define PDUR_CDD_CHANGEPARAMETER_APIID           ((uint8)0xcb)
#define PDUR_CDD_CANCEL_RECEIVE_APIID            ((uint8)0xcc)

#define PDUR_IPDUM_TRANSMIT_APIID                ((uint8)0xa9)
#define PDUR_IPDUM_RXINDICATION_APIID            ((uint8)0x21)
#define PDUR_IPDUM_TXCONFIRMATION_APIID          ((uint8)0x22)
#define PDUR_IPDUM_TRIGGERTRANSMIT_APIID         ((uint8)0x23)

#define PDUR_CANIF_RXINDICATION_APIID            ((uint8)0x01)
#define PDUR_CANIF_TXCONFIRMATION_APIID          ((uint8)0x02)
#define PDUR_CANIF_TRIGGERTRANSMIT_APIID         ((uint8)0x03)

#define PDUR_CANTP_COPYRXDATA_APIID              ((uint8)0x04)
#define PDUR_CANTP_RXINDICATION_APIID            ((uint8)0x05)
#define PDUR_CANTP_STARTOFRECEPTION_APIID        ((uint8)0x06)
#define PDUR_CANTP_COPYTXDATA_APIID              ((uint8)0x07)
#define PDUR_CANTP_TXCONFIRMATION_APIID          ((uint8)0x08)
#define PDUR_CANTP_CHANGEPARAMETER_CONF_APIID    ((uint8)0x09)

#define PDUR_CANNM_RXINDICATION_APIID            ((uint8)0x11)
#define PDUR_CANNM_TXCONFIRMATION_APIID          ((uint8)0x12)
#define PDUR_CANNM_TRIGGERTRANSMIT_APIID         ((uint8)0x13)

#define PDUR_UDPNM_RXINDICATION_APIID            ((uint8)0x81)
#define PDUR_UDPNM_TXCONFIRMATION_APIID          ((uint8)0x82)
#define PDUR_UDPNM_TRIGGERTRANSMIT_APIID         ((uint8)0x83)

#define PDUR_J1939TP_COPYRXDATA_APIID            ((uint8)0x14)
#define PDUR_J1939TP_RXINDICATION_APIID          ((uint8)0x15)
#define PDUR_J1939TP_STARTOFRECEPTION_APIID      ((uint8)0x16)
#define PDUR_J1939TP_COPYTXDATA_APIID            ((uint8)0x17)
#define PDUR_J1939TP_TXCONFIRMATION_APIID        ((uint8)0x18)

#define PDUR_FRIF_RXINDICATION_APIID             ((uint8)0x31)
#define PDUR_FRIF_TXCONFIRMATION_APIID           ((uint8)0x32)
#define PDUR_FRIF_TRIGGERTRANSMIT_APIID          ((uint8)0x33)

#define PDUR_FRTP_COPYRXDATA_APIID               ((uint8)0x34)
#define PDUR_FRTP_RXINDICATION_APIID             ((uint8)0x35)
#define PDUR_FRTP_STARTOFRECEPTION_APIID         ((uint8)0x36)
#define PDUR_FRTP_COPYTXDATA_APIID               ((uint8)0x37)
#define PDUR_FRTP_TXCONFIRMATION_APIID           ((uint8)0x38)

#define PDUR_FRNM_RXINDICATION_APIID             ((uint8)0x41)

#define PDUR_LINIF_RXINDICATION_APIID            ((uint8)0x51)
#define PDUR_LINIF_TXCONFIRMATION_APIID          ((uint8)0x52)
#define PDUR_LINIF_TRIGGERTRANSMIT_APIID         ((uint8)0x53)

#define PDUR_LINTP_COPYRXDATA_APIID              ((uint8)0x54)
#define PDUR_LINTP_RXINDICATION_APIID            ((uint8)0x55)
#define PDUR_LINTP_STARTOFRECEPTION_APIID        ((uint8)0x56)
#define PDUR_LINTP_COPYTXDATA_APIID              ((uint8)0x57)
#define PDUR_LINTP_TXCONFIRMATION_APIID          ((uint8)0x58)

#define PDUR_SOADIF_RXINDICATION_APIID           ((uint8)0x61)
#define PDUR_SOADIF_TXCONFIRMATION_APIID         ((uint8)0x62)
#define PDUR_SOADIF_TRIGGERTRANSMIT_APIID        ((uint8)0x63)

#define PDUR_SOADTP_COPYRXDATA_APIID             ((uint8)0x64)
#define PDUR_SOADTP_RXINDICATION_APIID           ((uint8)0x65)
#define PDUR_SOADTP_STARTOFRECEPTION_APIID       ((uint8)0x66)
#define PDUR_SOADTP_COPYTXDATA_APIID             ((uint8)0x67)
#define PDUR_SOADTP_TXCONFIRMATION_APIID         ((uint8)0x68)

#define PDUR_CDDIF_RXINDICATION_APIID            ((uint8)0x71)
#define PDUR_CDDIF_TXCONFIRMATION_APIID          ((uint8)0x72)
#define PDUR_CDDIF_TRIGGERTRANSMIT_APIID         ((uint8)0x73)

#define PDUR_CDDTP_COPYRXDATA_APIID              ((uint8)0x74)
#define PDUR_CDDTP_RXINDICATION_APIID            ((uint8)0x75)
#define PDUR_CDDTP_STARTOFRECEPTION_APIID        ((uint8)0x76)
#define PDUR_CDDTP_COPYTXDATA_APIID              ((uint8)0x77)
#define PDUR_CDDTP_TXCONFIRMATION_APIID          ((uint8)0x78)

#define PDUR_DOIPIF_TXCONFIRMATION_APIID         ((uint8)0x92)

#define PDUR_DOIPTP_COPYRXDATA_APIID             ((uint8)0x94)
#define PDUR_DOIPTP_RXINDICATION_APIID           ((uint8)0x95)
#define PDUR_DOIPTP_STARTOFRECEPTION_APIID       ((uint8)0x96)
#define PDUR_DOIPTP_COPYTXDATA_APIID             ((uint8)0x97)
#define PDUR_DOIPTP_TXCONFIRMATION_APIID         ((uint8)0x98)

#define PDUR_SECOC_TRANSMIT_APIID                ((uint8)0xd9)
#define PDUR_SECOC_CANCELTRANSMIT_APIID          ((uint8)0xda)
#define PDUR_SECOC_CANCELRECEIVE_APIID           ((uint8)0xdc)

#define PDUR_SECOCIF_RXINDICATION_APIID          ((uint8)0xd1)
#define PDUR_SECOCIF_TXCONFIRMATION_APIID        ((uint8)0xd2)

#define PDUR_SECOCTP_COPYTXDATA_APIID            ((uint8)0xd4)
#define PDUR_SECOCTP_RXINDICATION_APIID          ((uint8)0xd5)
#define PDUR_SECOCTP_STARTOFRECEPTION_APIID      ((uint8)0xd6)
#define PDUR_SECOCTP_COPYRXDATA_APIID            ((uint8)0xd7)
#define PDUR_SECOCTP_TXCONFIRMATION_APIID        ((uint8)0xd8)

#define PDUR_SOMEIPTP_TRANSMIT_APIID             ((uint8)0x29)

#define PDUR_SOMEIPTP_COPYTXDATA_APIID           ((uint8)0x24)
#define PDUR_SOMEIPTP_RXINDICATION_APIID         ((uint8)0x25)
#define PDUR_SOMEIPTP_STARTOFRECEPTION_APIID     ((uint8)0x26)
#define PDUR_SOMEIPTP_COPYRXDATA_APIID           ((uint8)0x27)
#define PDUR_SOMEIPTP_TXCONFIRMATION_APIID       ((uint8)0x28)

/*******************************************************************************
*   Global Function Declaration
*******************************************************************************/
#define PDUR_START_SEC_CODE
#include "MemMap.h"

extern FUNC(void, PDUR_CODE) PduR_Init
(
    P2CONST(PduR_PBConfigType, AUTOMATIC, PDUR_CONST) ConfigPtr
);

extern FUNC(void, PDUR_CODE) PduR_GetVersionInfo
(
    P2VAR(Std_VersionInfoType, AUTOMATIC, PDUR_APPL_DATA) versionInfo
);

extern FUNC(PduR_PBConfigIdType, PDUR_CODE) PduR_GetConfigurationId
(
    void
);

extern FUNC(void, PDUR_CODE) PduR_EnableRouting
(
    PduR_RoutingPathGroupIdType id
);

extern FUNC(void, PDUR_CODE) PduR_DisableRouting
(
    PduR_RoutingPathGroupIdType id,
    boolean initialize
);

#define PDUR_STOP_SEC_CODE
#include "MemMap.h"

#else
#define PduR_Init(ConfigPtr)
#endif

#endif /*PDUR_H */

