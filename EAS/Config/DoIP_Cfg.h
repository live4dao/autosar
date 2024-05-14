/*  BEGIN_FILE_HDR
********************************************************************************
*   File Name       : DoIP_Cfg.h
********************************************************************************
*   Project/Product : AUTOSAR BSW PROJECT
*   Title           : DoIP module configuration File
*   Author          : Hirain
********************************************************************************
*   Description     : DoIP module configuration File
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
*   V1.0.0_3.5.5_AZ240046       27/03/2024    Eas           N/A          N/A
*
********************************************************************************
* END_FILE_HDR*/
#ifndef DoIP_CFG_H
#define DoIP_CFG_H

#include "PduR_DoIP.h"
#include "Rte_DoIP.h"


#define DOIP_CONFIG_VARIANTS                                STD_CONFIG_VARIANTS_PRECOMPILE
#define DOIP_PRIVATE_VERSION_CHECK                          STD_ON
#define DOIP_SW_MAJOR_VERSION_CFG                           1
#define DOIP_SW_MINOR_VERSION_CFG                           2
#define DOIP_SW_PATCH_VERSION_CFG                           5
#define DOIP_AR_RELEASE_MAJOR_VERSION_CFG                   4
#define DOIP_AR_RELEASE_MINOR_VERSION_CFG                   2
#define DOIP_AR_RELEASE_REVISION_VERSION_CFG                2


#define DOIP_CPU_ENDIAN_TYPE                                HIGH_BYTE_FIRST

/* DoIP general configuration */
#define DOIP_OEM_PLATFORM                                   DOIP_NO_PLATFORM
#define DOIP_DEV_ERROR_DETECT                               STD_OFF
#define DOIP_DHCP_OPTION_VIN_USE                            STD_OFF
#define DOIP_VERSION_INFO_API                               STD_ON
#define DOIP_ENTITY_STATUS_MAX_BYTE_FIELD_USE               STD_ON
#define DOIP_USE_MAC_FOR_IDENTIFICATION                     STD_ON
#define DOIP_USE_VEHICLE_IDENTIFICATION_SYNC_STATUS         STD_ON

#define DOIP_VIN_GID_MASTER                                 STD_OFF
#define DOIP_USE_EID_AS_GID                                 STD_ON
#define DOIP_GID_CONFIGURED                                 STD_OFF


#define DOIP_ALIVE_CHECK_RES_TIMEOUT                        ((uint16)500)
#define DOIP_GEN_INACTIVE_TIMEOUT                           ((uint32)300000)
#define DOIP_INITIAL_INACTIVE_TIMEOUT                       ((uint16)2000)
#define DOIP_INITIAL_VEHICLE_ANNOUNCEMENT_TIME              ((uint16)200)
#define DOIP_VEHICLE_ANNOUNCEMENT_INTERVAL                  ((uint16)500)
#define DOIP_VEHICLE_ANNOUNCEMENT_REPETITION                ((uint8)3)
#define DOIP_MAINFUNCTION_PERIOD                            ((uint8)5)
#define DOIP_GID_INVALIDATIY_PATTERN                        0x55
#define DOIP_VIN_INVALIDATIY_PATTERN                        0x55
#define DOIP_HOST_NAME_SIZE_MAX                             5
#define DOIP_MAX_REQUEST_BYTES                              128
#define DOIP_MAX_TESTER_CONNECTION_NUM                      ((uint8)2)
#define DOIP_MAX_UDP_REQ_PER_MESSAGE                        ((uint8)2)

#define DOIP_MAX_BYTES_DIAG_ACK_NACK                        ((uint8)1)

#define DOIP_NODE_TYPE                                      DOIP_NODE

#define DOIP_UDP_CON_NUM                                    1
#define DOIP_TCP_CON_NUM                                    3
#define DOIP_CHANNEL_NUM                                    ((uint8)2)
#define DOIP_TARGET_ADDRESS_NUM                             2
#define DOIP_TESTER_NUM                                     1
#define DOIP_ROUTING_ACTIVATION_NUM                         1
#define DOIP_TCP_TX_IF_PDU_BUF_NUM                          0

#define DoIPTp_PduR_CanConfigSet_Tx_DBC_TEST_Uds_Resp       0u

#define DOIP_CURRENT_ACTIVATION_LINE_STATUS()                                 Rte_Mode_DoIPActivationLineSwitchNotification_currentDoIPActivationLineStatus()
#define DOIP_CALL_GET_VIN_FUNC(vin)                                           Dcm_GetVin(vin)

#define DOIP_CALL_UL_DOIP_TP_START_OF_RECEPTION(id, info, sdulength, bufsize) PduR_DoIPTpStartOfReception(id, info, sdulength, bufsize)
#define DOIP_CALL_UL_DOIP_TP_COPY_RX_DATA(id, info, bufsizeptr)               PduR_DoIPTpCopyRxData(id, info, bufsizeptr)
#define DOIP_CALL_UL_DOIP_TP_RX_INDICATION(id, result)                        PduR_DoIPTpRxIndication(id, result)
#define DOIP_CALL_UL_DOIP_TP_COPY_TX_DATA(id, info, retry, avalibe)           PduR_DoIPTpCopyTxData(id, info, retry, avalibe)
#define DOIP_CALL_UL_DOIP_TP_TX_CONFIRMATION(id, result)                      PduR_DoIPTpTxConfirmation(id, result)
#define DOIP_CALL_UL_DOIP_IF_TX_CONFIRMATION(id)

/*channel  RxPdu*/
#define DoIP_PduR_DoIPDefaultConfig_DoIP_To_Dcm_Phy         0
#define DoIP_PduR_DoIPDefaultConfig_DoIP_To_Dcm_Fun         1
/*channel  TxPdu*/
#define DoIP_PduR_DoIPDefaultConfig_Dcm_To_DoIP             0

/*TcpConnection  RxPdu*/
#define DoIP_SoAd_DoIPDefaultConfig_SoAd_To_DoIP_TCP0       0
#define DoIP_SoAd_DoIPDefaultConfig_SoAd_To_DoIP_TCP1       1
#define DoIP_SoAd_DoIPDefaultConfig_SoAd_To_DoIP_TCP2       2
/*TcpConnection  TxPdu*/
#define DoIP_SoAd_DoIPDefaultConfig_DoIP_To_SoAd_TCP0       0
#define DoIP_SoAd_DoIPDefaultConfig_DoIP_To_SoAd_TCP1       1
#define DoIP_SoAd_DoIPDefaultConfig_DoIP_To_SoAd_TCP2       2

/*UdpConnection  RxPdu*/
#define DoIP_SoAd_DoIPDefaultConfig_SoAd_To_DoIP_UDP        0
/*UdpConnection  TxPdu*/
#define DoIP_SoAd_DoIPDefaultConfig_DoIP_To_SoAd_UDP        0

#endif


