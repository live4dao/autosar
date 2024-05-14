/*  BEGIN_FILE_HDR
********************************************************************************
*   File Name       : SoAd_Cfg.h
********************************************************************************
*   Project/Product : AUTOSAR BSW PROJECT
*   Title           : SoAd module configuration File
*   Author          : Hirain
********************************************************************************
*   Description     : SoAd module configuration File
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
*   V1.0.2_3.5.5_AZ240046       09/05/2024    Eas           N/A          N/A
*
********************************************************************************
* END_FILE_HDR*/
#ifndef _SOAD_CFG_H_
#define _SOAD_CFG_H_

/*******************************************************************************
*   Macro
*******************************************************************************/
/*The configuration variant and version informations*/
#define SOAD_CONFIG_VARIANTS                                STD_CONFIG_VARIANTS_LINKTIME
#define SOAD_PRIVATE_VERSION_CHECK                          STD_ON
#define SOAD_SW_MAJOR_VERSION_CFG                           2
#define SOAD_SW_MINOR_VERSION_CFG                           0
#define SOAD_SW_PATCH_VERSION_CFG                           8
#define SOAD_AR_RELEASE_MAJOR_VERSION_CFG                   4
#define SOAD_AR_RELEASE_MINOR_VERSION_CFG                   2
#define SOAD_AR_RELEASE_REVISION_VERSION_CFG                2

/*ECUC_SoAd_00003 SoAd General Configurations*/
#define SOAD_DEV_ERROR_DETECT                               STD_OFF
#define SOAD_VERSION_INFO_API                               STD_OFF
#define SOAD_IPV6_ADDRESS_ENABLED                           STD_OFF
#define SOAD_MAIN_FUNCTION_PERIOD                           (5)  /*ms*/
#define SOAD_SOCON_MAX                                      (23)
#define SOAD_ROUTINGGROUP_MAX                               (1)
#define SOAD_IF_SUPPORTED                                   STD_ON
#define SOAD_IF_TRIGGER_TRANSMIT_SUPPORTED                  STD_ON
#define SOAD_IF_TXCONFIRMATION_SUPPORTED                    STD_ON
#define SOAD_TP_SUPPORTED                                   STD_ON
#define SOAD_SOCON_MODE_CHG_SUPPORTED                       STD_ON
#define SOAD_LOCAL_IPADDR_CHG_SUPPORTED                     STD_ON
#define SOAD_PDUHEADER_SUPPORTED                            STD_OFF
#define SOAD_ROUTINGGROUP_MASK_LEN                          (1)

/*SOAD PDU*/
#define SoAd_DoIP_DoIPDefaultConfig_DoIP_To_SoAd_UDP        (0)
#define SoAd_DoIP_DoIPDefaultConfig_DoIP_To_SoAd_TCP0       (1)
#define SoAd_DoIP_DoIPDefaultConfig_DoIP_To_SoAd_TCP1       (2)
#define SoAd_DoIP_DoIPDefaultConfig_DoIP_To_SoAd_TCP2       (3)
#define SoAd_PduR_Tcp_Send                                  (4)
#define SoAd_PduR_Udp_Send                                  (5)
#define SoAdIf_Xcp_Tx                                       (6)
#define SoAd_UdpNm_UdpNm_Tx                                 (7)
#define SoAd_PduR_Udp_Send_1501                             (8)
#define SoAd_PduR_Udp_Send_1502                             (9)
#define SoAd_PduR_Udp_Send_1503                             (10)
#define SoAd_PduR_Udp_Send_1504                             (11)
#define SoAd_PduR_Udp_Send_1505                             (12)
#define SoAd_PduR_Udp_Send_1506                             (13)
#define SoAd_PduR_Udp_Send_1507                             (14)

#define SoAd_DoIP_DoIPDefaultConfig_SoAd_To_DoIP_UDP        (0)
#define SoAd_DoIP_DoIPDefaultConfig_SoAd_To_DoIP_TCP0       (1)
#define SoAd_DoIP_DoIPDefaultConfig_SoAd_To_DoIP_TCP1       (2)
#define SoAd_DoIP_DoIPDefaultConfig_SoAd_To_DoIP_TCP2       (3)
#define SoAd_PduR_Tcp_Receive                               (4)
#define SoAd_PduR_Udp_Receive                               (5)
#define SoAdIf_Xcp_Rx                                       (6)
#define SoAd_UdpNm_UdpNm_Rx                                 (7)
#define SoAd_PduR_Tcp_Receive_1601                          (8)
#define SoAd_PduR_Tcp_Receive_1602                          (9)
#define SoAd_PduR_Tcp_Receive_1603                          (10)
#define SoAd_PduR_Tcp_Receive_1604                          (11)
#define SoAd_PduR_Tcp_Receive_1605                          (12)
#define SoAd_PduR_Tcp_Receive_1606                          (13)
#define SoAd_PduR_Tcp_Receive_1607                          (14)
#define SoAd_PduR_Tcp_Receive_1608                          (15)

#endif /*_SOAD_CFG_H_*/

