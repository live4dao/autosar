/*  BEGIN_FILE_HDR
********************************************************************************
*   File Name       : PduR_Cfg.h
********************************************************************************
*   Project/Product : AUTOSAR BSW PROJECT
*   Title           : PduR module configuration File
*   Author          : Hirain
********************************************************************************
*   Description     : PduR module configuration File
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
#ifndef PDUR_CFG_H
#define PDUR_CFG_H

/*******************************************************************************
*   Includes
*******************************************************************************/
#include "ComStack_Types.h"


/*******************************************************************************
*   Common Macro
*******************************************************************************/
/*The configuration variant and version informations*/
#define PDUR_CONFIG_VARIANTS                                STD_CONFIG_VARIANTS_PRECOMPILE

/*******************************************************************************
*   Non Autosar Standard
*******************************************************************************/
#define PDUR_VERSION_CHECK                                  STD_ON

/*******************************************************************************
*   PduRGeneral
*******************************************************************************/
/*ECUC_PduR_00302*/
#define PDUR_DEV_ERROR_DETECT                               STD_OFF
/*ECUC_PduR_00316*/
#define PDUR_VERSION_INFO_API                               STD_OFF
/*ECUC_PduR_00317*/
#define PDUR_ZERO_COST_OPERATION                            STD_OFF
/*ECUC_PduR_00347*/
#define PDUR_METADATA_SUPPORT                               STD_OFF
#define PDUR_TP_SUPPORT                                     STD_ON
#define PDUR_IF_SUPPORT                                     STD_ON
#define PDUR_GW_IF_SUPPORT                                  STD_OFF
#define PDUR_GW_TP_SUPPORT                                  STD_OFF
#define PDUR_CANCEL_RECEIVE_ENABLED                         STD_ON
#define PDUR_CANCEL_TRANSMIT_ENABLED                        STD_ON
#define PDUR_CHANGEPARAMETER_API_ENABLED                    STD_OFF


/*******************************************************************************
*   Moudle support configuration
*******************************************************************************/
/*Upper Layer*/
#define PDUR_DCM_MODULE_SUPPORT                             STD_ON
#define PDUR_J1939DCM_MODULE_SUPPORT                        STD_OFF
#define PDUR_COM_MODULE_SUPPORT                             STD_ON
#define PDUR_CDD_MODULE_SUPPORT                             STD_OFF
#define PDUR_J1939RM_MODULE_SUPPORT                         STD_OFF
#define PDUR_LDCOM_MODULE_SUPPORT                           STD_OFF
/*Lower & Lower Tp*/
#define PDUR_CANIF_MODULE_SUPPORT                           STD_ON
#define PDUR_CANTP_MODULE_SUPPORT                           STD_ON
#define PDUR_CANNM_MODULE_SUPPORT                           STD_OFF
#define PDUR_J1939TP_MODULE_SUPPORT                         STD_OFF
#define PDUR_LINIF_MODULE_SUPPORT                           STD_OFF
#define PDUR_LINTP_MODULE_SUPPORT                           STD_OFF
#define PDUR_FRIF_MODULE_SUPPORT                            STD_OFF
#define PDUR_FRTP_MODULE_SUPPORT                            STD_OFF
#define PDUR_DOIPIF_MODULE_SUPPORT                          STD_OFF
#define PDUR_DOIPTP_MODULE_SUPPORT                          STD_ON
#define PDUR_SOADIF_MODULE_SUPPORT                          STD_ON
#define PDUR_SOADTP_MODULE_SUPPORT                          STD_OFF
#define PDUR_CDDIF_MODULE_SUPPORT                           STD_OFF
#define PDUR_CDDTP_MODULE_SUPPORT                           STD_OFF
#define PDUR_SECOC_MODULE_SUPPORT                           STD_OFF
#define PDUR_UDPNM_MODULE_SUPPORT                           STD_OFF
#define PDUR_IPDUM_MODULE_SUPPORT                           STD_OFF
#define PDUR_IPDUMIF_MODULE_SUPPORT                         STD_OFF
#define PDUR_SECOCIF_MODULE_SUPPORT                         STD_OFF
#define PDUR_SECOCTP_MODULE_SUPPORT                         STD_OFF
#define PDUR_SOMEIP_MODULE_SUPPORT                          STD_OFF
#define PDUR_SOMEIPTP_MODULE_SUPPORT                        STD_OFF
/*******************************************************************************
    PduRRoutingTables
*******************************************************************************/

/*******************************************************************************
    PduRBswModules-CANIF
*******************************************************************************/
/*ECUC_PduR_00340*/
#define PDUR_CANIF_CANCELRECEIVE_ENABLED                    STD_OFF
/*ECUC_PduR_00297*/
#define PDUR_CANIF_CANCELTRANSMIT_ENABLED                   STD_OFF
/*ECUC_PduR_00326*/
#define PDUR_CANIF_CHANGEPARAMETER_API_ENABLED              STD_OFF
/*ECUC_PduR_00298*/
#define PDUR_CANIF_COMIF_ENABLED                            STD_ON
/*ECUC_PduR_00307*/
#define PDUR_CANIF_LOWER_MODULE                             STD_ON
/*ECUC_PduR_00332*/
#define PDUR_CANIF_RETRANSMISSION_ENABLED                   STD_OFF
/*ECUC_PduR_00312*/
#define PDUR_CANIF_TP_ENABLED                               STD_OFF
/*ECUC_PduR_00313*/
#define PDUR_CANIF_TRIGGER_TRANSMIT_ENABLED                 STD_OFF
/*ECUC_PduR_00314*/
#define PDUR_CANIF_TXCONF_ENABLED                           STD_ON
/*ECUC_PduR_00338*/
#define PDUR_CANIF_UPPER_MODULE                             STD_OFF
/*ECUC_PduR_00319*/
#define PDUR_CANIF_USETAG                                   STD_OFF
/*******************************************************************************
    PduRBswModules-CANTP
*******************************************************************************/
/*ECUC_PduR_00340*/
#define PDUR_CANTP_CANCELRECEIVE_ENABLED                    STD_OFF
/*ECUC_PduR_00297*/
#define PDUR_CANTP_CANCELTRANSMIT_ENABLED                   STD_OFF
/*ECUC_PduR_00326*/
#define PDUR_CANTP_CHANGEPARAMETER_API_ENABLED              STD_OFF
/*ECUC_PduR_00298*/
#define PDUR_CANTP_COMIF_ENABLED                            STD_OFF
/*ECUC_PduR_00307*/
#define PDUR_CANTP_LOWER_MODULE                             STD_ON
/*ECUC_PduR_00332*/
#define PDUR_CANTP_RETRANSMISSION_ENABLED                   STD_ON
/*ECUC_PduR_00312*/
#define PDUR_CANTP_TP_ENABLED                               STD_ON
/*ECUC_PduR_00313*/
#define PDUR_CANTP_TRIGGER_TRANSMIT_ENABLED                 STD_OFF
/*ECUC_PduR_00314*/
#define PDUR_CANTP_TXCONF_ENABLED                           STD_ON
/*ECUC_PduR_00338*/
#define PDUR_CANTP_UPPER_MODULE                             STD_OFF
/*ECUC_PduR_00319*/
#define PDUR_CANTP_USETAG                                   STD_OFF
/*******************************************************************************
    PduRBswModules-COM
*******************************************************************************/
/*ECUC_PduR_00340*/
#define PDUR_COM_CANCELRECEIVE_ENABLED                      STD_OFF
/*ECUC_PduR_00297*/
#define PDUR_COM_CANCELTRANSMIT_ENABLED                     STD_OFF
/*ECUC_PduR_00326*/
#define PDUR_COM_CHANGEPARAMETER_API_ENABLED                STD_OFF
/*ECUC_PduR_00298*/
#define PDUR_COM_COMIF_ENABLED                              STD_ON
/*ECUC_PduR_00307*/
#define PDUR_COM_LOWER_MODULE                               STD_OFF
/*ECUC_PduR_00332*/
#define PDUR_COM_RETRANSMISSION_ENABLED                     STD_OFF
/*ECUC_PduR_00312*/
#define PDUR_COM_TP_ENABLED                                 STD_ON
/*ECUC_PduR_00313*/
#define PDUR_COM_TRIGGER_TRANSMIT_ENABLED                   STD_ON
/*ECUC_PduR_00314*/
#define PDUR_COM_TXCONF_ENABLED                             STD_ON
/*ECUC_PduR_00338*/
#define PDUR_COM_UPPER_MODULE                               STD_ON
/*ECUC_PduR_00319*/
#define PDUR_COM_USETAG                                     STD_ON
/*******************************************************************************
    PduRBswModules-DCM
*******************************************************************************/
/*ECUC_PduR_00340*/
#define PDUR_DCM_CANCELRECEIVE_ENABLED                      STD_OFF
/*ECUC_PduR_00297*/
#define PDUR_DCM_CANCELTRANSMIT_ENABLED                     STD_OFF
/*ECUC_PduR_00326*/
#define PDUR_DCM_CHANGEPARAMETER_API_ENABLED                STD_OFF
/*ECUC_PduR_00298*/
#define PDUR_DCM_COMIF_ENABLED                              STD_OFF
/*ECUC_PduR_00307*/
#define PDUR_DCM_LOWER_MODULE                               STD_OFF
/*ECUC_PduR_00332*/
#define PDUR_DCM_RETRANSMISSION_ENABLED                     STD_OFF
/*ECUC_PduR_00312*/
#define PDUR_DCM_TP_ENABLED                                 STD_ON
/*ECUC_PduR_00313*/
#define PDUR_DCM_TRIGGER_TRANSMIT_ENABLED                   STD_ON
/*ECUC_PduR_00314*/
#define PDUR_DCM_TXCONF_ENABLED                             STD_ON
/*ECUC_PduR_00338*/
#define PDUR_DCM_UPPER_MODULE                               STD_ON
/*ECUC_PduR_00319*/
#define PDUR_DCM_USETAG                                     STD_ON
/*******************************************************************************
    PduRBswModules-SOADIF
*******************************************************************************/
/*ECUC_PduR_00340*/
#define PDUR_SOADIF_CANCELRECEIVE_ENABLED                   STD_OFF
/*ECUC_PduR_00297*/
#define PDUR_SOADIF_CANCELTRANSMIT_ENABLED                  STD_OFF
/*ECUC_PduR_00326*/
#define PDUR_SOADIF_CHANGEPARAMETER_API_ENABLED             STD_OFF
/*ECUC_PduR_00298*/
#define PDUR_SOADIF_COMIF_ENABLED                           STD_ON
/*ECUC_PduR_00307*/
#define PDUR_SOADIF_LOWER_MODULE                            STD_ON
/*ECUC_PduR_00332*/
#define PDUR_SOADIF_RETRANSMISSION_ENABLED                  STD_OFF
/*ECUC_PduR_00312*/
#define PDUR_SOADIF_TP_ENABLED                              STD_OFF
/*ECUC_PduR_00313*/
#define PDUR_SOADIF_TRIGGER_TRANSMIT_ENABLED                STD_OFF
/*ECUC_PduR_00314*/
#define PDUR_SOADIF_TXCONF_ENABLED                          STD_ON
/*ECUC_PduR_00338*/
#define PDUR_SOADIF_UPPER_MODULE                            STD_OFF
/*ECUC_PduR_00319*/
#define PDUR_SOADIF_USETAG                                  STD_OFF
/*******************************************************************************
    PduRBswModules-DOIPTP
*******************************************************************************/
/*ECUC_PduR_00340*/
#define PDUR_DOIPTP_CANCELRECEIVE_ENABLED                   STD_ON
/*ECUC_PduR_00297*/
#define PDUR_DOIPTP_CANCELTRANSMIT_ENABLED                  STD_ON
/*ECUC_PduR_00326*/
#define PDUR_DOIPTP_CHANGEPARAMETER_API_ENABLED             STD_OFF
/*ECUC_PduR_00298*/
#define PDUR_DOIPTP_COMIF_ENABLED                           STD_OFF
/*ECUC_PduR_00307*/
#define PDUR_DOIPTP_LOWER_MODULE                            STD_ON
/*ECUC_PduR_00332*/
#define PDUR_DOIPTP_RETRANSMISSION_ENABLED                  STD_OFF
/*ECUC_PduR_00312*/
#define PDUR_DOIPTP_TP_ENABLED                              STD_ON
/*ECUC_PduR_00313*/
#define PDUR_DOIPTP_TRIGGER_TRANSMIT_ENABLED                STD_OFF
/*ECUC_PduR_00314*/
#define PDUR_DOIPTP_TXCONF_ENABLED                          STD_ON
/*ECUC_PduR_00338*/
#define PDUR_DOIPTP_UPPER_MODULE                            STD_OFF
/*ECUC_PduR_00319*/
#define PDUR_DOIPTP_USETAG                                  STD_ON
/* generate tool's version*/
#define PDUR_SW_MAJOR_VERSION_CFG                           1
#define PDUR_SW_MINOR_VERSION_CFG                           1
#define PDUR_SW_PATCH_VERSION_CFG                           37
#define PDUR_AR_RELEASE_MAJOR_VERSION_CFG                   4
#define PDUR_AR_RELEASE_MINOR_VERSION_CFG                   2
#define PDUR_AR_RELEASE_REVISION_VERSION_CFG                2

/*CanConfigSet*/

#define PduR_CanIf_CanConfigSet_Rx_ACAN_ACU_ChimeTelltaleReq          (0)
#define PduR_CanIf_CanConfigSet_Rx_ACAN_BCM_LIGHT_0x106     (1)
#define PduR_CanIf_CanConfigSet_Rx_ACAN_BCM_SwitchSts_0x109 (2)
#define PduR_CanIf_CanConfigSet_Rx_ACAN_ABS_FrontWheelSpeMCUKPH       (3)
#define PduR_CanIf_CanConfigSet_Rx_ACAN_ABS_RearWheelSpeMCUKPH        (4)
#define PduR_CanIf_CanConfigSet_Rx_ACAN_ABS_WheelSpeedRC    (5)
#define PduR_CanIf_CanConfigSet_Rx_ACAN_ABS_Status          (6)
#define PduR_CanIf_CanConfigSet_Rx_ACAN_ESC_Status_0x132    (7)
#define PduR_CanIf_CanConfigSet_Rx_ACAN_VCU_Ctrl            (8)
#define PduR_CanIf_CanConfigSet_Rx_ACAN_VCU_StsEpt          (9)
#define PduR_CanIf_CanConfigSet_Rx_ACAN_SAS_Sensor_0x17E    (10)
#define PduR_CanIf_CanConfigSet_Rx_ACAN_EPS_LKA_Sts         (11)
#define PduR_CanIf_CanConfigSet_Rx_ACAN_BCM_PEPS_Sts        (12)
#define PduR_CanIf_CanConfigSet_Rx_ACAN_MHU_ADSA01          (13)
#define PduR_CanIf_CanConfigSet_Rx_ACAN_MHU_ADAS02          (14)
#define PduR_CanIf_CanConfigSet_Rx_ACAN_MHU_ADAS03          (15)
#define PduR_CanIf_CanConfigSet_Rx_ACAN_BCM_WindowSts       (16)
#define PduR_CanIf_CanConfigSet_Rx_ACAN_ESC_EPB_0x230       (17)
#define PduR_CanIf_CanConfigSet_Rx_ACAN_IBS_ADAS_Info       (18)
#define PduR_CanIf_CanConfigSet_Rx_ACAN_IBS_Info            (19)
#define PduR_CanIf_CanConfigSet_Rx_ACAN_TBOX_DateTime1      (20)
#define PduR_CanIf_CanConfigSet_Rx_ACAN_MHU_Status_Info     (21)
#define PduR_CanIf_CanConfigSet_Rx_ACAN_CCU_StsInfo1        (22)
#define PduR_CanIf_CanConfigSet_Rx_ACAN_ESC_YawAngle_0x3E2  (23)
#define PduR_CanIf_CanConfigSet_Rx_ACAN_IPC_TotalOdometer   (24)
#define PduR_CanIf_CanConfigSet_Rx_ACAN_MFS_L_Control_Button2_0x3F7   (25)
#define PduR_CanIf_CanConfigSet_Rx_ACAN_BCM_RLS             (26)
#define PduR_CanIf_CanConfigSet_Rx_ACAN_BCM_TPMS_Info2      (27)
#define PduR_CanIf_CanConfigSet_Rx_ACAN_BCM_DoorState_0x4D4 (28)
#define PduR_CanIf_CanConfigSet_Rx_Radar_ARS_TIME_SYNC      (29)
#define PduR_CanIf_CanConfigSet_Rx_Radar_ARS_SYS_PERFORM    (30)
#define PduR_CanIf_CanConfigSet_Rx_Radar_ARS_OD_Header      (31)
#define PduR_CanIf_CanConfigSet_Rx_Radar_ARS_OD_00_01       (32)
#define PduR_CanIf_CanConfigSet_Rx_Radar_ARS_OD_02_03       (33)
#define PduR_CanIf_CanConfigSet_Rx_Radar_ARS_OD_04_05       (34)
#define PduR_CanIf_CanConfigSet_Rx_Radar_ARS_OD_06_07       (35)
#define PduR_CanIf_CanConfigSet_Rx_Radar_ARS_OD_08_09       (36)
#define PduR_CanIf_CanConfigSet_Rx_Radar_ARS_OD_10_11       (37)
#define PduR_CanIf_CanConfigSet_Rx_Radar_ARS_OD_12_13       (38)
#define PduR_CanIf_CanConfigSet_Rx_Radar_ARS_OD_14_15       (39)
#define PduR_CanIf_CanConfigSet_Rx_Radar_ARS_OD_16_17       (40)
#define PduR_CanIf_CanConfigSet_Rx_Radar_ARS_OD_18_19       (41)
#define PduR_CanIf_CanConfigSet_Rx_Radar_ARS_OD_20_21       (42)
#define PduR_CanIf_CanConfigSet_Rx_Radar_ARS_OD_22_23       (43)
#define PduR_CanIf_CanConfigSet_Rx_Radar_ARS_OD_24_25       (44)
#define PduR_CanIf_CanConfigSet_Rx_Radar_ARS_OD_26_27       (45)
#define PduR_CanIf_CanConfigSet_Rx_Radar_ARS_OD_28_29       (46)
#define PduR_CanIf_CanConfigSet_Rx_Radar_ARS_OD_30_31       (47)

#define PduR_Com_CanConfigSet_Tx_ACAN_ADAS_01               (0)
#define PduR_Com_CanConfigSet_Tx_ACAN_ADAS_02               (1)
#define PduR_Com_CanConfigSet_Tx_ACAN_ADAS_03               (2)
#define PduR_Com_CanConfigSet_Tx_ACAN_ADAS_04               (3)
#define PduR_Com_CanConfigSet_Tx_ACAN_ADAS_06               (4)
#define PduR_Com_CanConfigSet_Tx_ACAN_ADAS_07               (5)
#define PduR_Com_CanConfigSet_Tx_ACAN_ADAS_08               (6)
#define PduR_Com_CanConfigSet_Tx_ACAN_ADAS_Info15           (7)
#define PduR_Com_CanConfigSet_Tx_ACAN_ADAS_Info17           (8)
#define PduR_Com_CanConfigSet_Tx_ACAN_ADAS_Info23           (9)
#define PduR_Com_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info1   (10)
#define PduR_Com_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info3   (11)
#define PduR_Com_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info5   (12)
#define PduR_Com_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info7   (13)
#define PduR_Com_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info9   (14)
#define PduR_Com_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info11  (15)
#define PduR_Com_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info13  (16)
#define PduR_Com_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info15  (17)
#define PduR_Com_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info17  (18)
#define PduR_Com_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info19  (19)
#define PduR_Com_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info21  (20)
#define PduR_Com_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info23  (21)
#define PduR_Com_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info2   (22)
#define PduR_Com_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info4   (23)
#define PduR_Com_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info6   (24)
#define PduR_Com_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info8   (25)
#define PduR_Com_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info10  (26)
#define PduR_Com_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info12  (27)
#define PduR_Com_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info14  (28)
#define PduR_Com_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info16  (29)
#define PduR_Com_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info18  (30)
#define PduR_Com_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info20  (31)
#define PduR_Com_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info22  (32)
#define PduR_Com_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info24  (33)
#define PduR_Com_CanConfigSet_Tx_ACAN_ADAS_Info20           (34)
#define PduR_Com_CanConfigSet_Tx_ACAN_ADAS_Info21           (35)
#define PduR_Com_CanConfigSet_Tx_ACAN_ADAS_Info22           (36)
#define PduR_Com_Tcp_Send                                   (37)
#define PduR_Com_Udp_Send                                   (38)
#define PduR_Com_Udp_Send_1501                              (39)
#define PduR_Com_Udp_Send_1502                              (40)
#define PduR_Com_Udp_Send_1503                              (41)
#define PduR_Com_Udp_Send_1504                              (42)
#define PduR_Com_Udp_Send_1505                              (43)
#define PduR_Com_Udp_Send_1506                              (44)
#define PduR_Com_Udp_Send_1507                              (45)

#define PduR_CanTp_CanConfigSet_Rx_ACAN_UDS_PhyDiagReq_ADAS (0)
#define PduR_CanTp_CanConfigSet_Rx_ACAN_UDS_FuncDiagReq     (1)

#define PduR_Dcm_CanConfigSet_Tx_ACAN_UDS_DiagResp_ADAS     (0)
#define PduR_Dcm_DoIPDefaultConfig_Dcm_To_DoIP              (1)

#define PduR_SoAd_Tcp_Receive                               (0)
#define PduR_SoAd_Udp_Receive                               (1)
#define PduR_SoAd_Tcp_Receive_1601                          (2)
#define PduR_SoAd_Tcp_Receive_1602                          (3)
#define PduR_SoAd_Tcp_Receive_1604                          (4)
#define PduR_SoAd_Tcp_Receive_1605                          (5)
#define PduR_SoAd_Udp_Send_1501                             (6)
#define PduR_SoAd_Udp_Send_1502                             (7)
#define PduR_SoAd_Udp_Send_1504                             (8)
#define PduR_SoAd_Udp_Send_1505                             (9)
#define PduR_SoAd_Udp_Send_1506                             (10)
#define PduR_SoAd_Udp_Send_1507                             (11)
#define PduR_SoAd_Tcp_Receive_1603                          (12)
#define PduR_SoAd_Tcp_Receive_1606                          (13)
#define PduR_SoAd_Tcp_Receive_1607                          (14)
#define PduR_SoAd_Tcp_Receive_1608                          (15)
#define PduR_SoAd_Udp_Send_1503                             (16)

#define PduR_DoIP_DoIPDefaultConfig_DoIP_To_Dcm_Phy         (0)
#define PduR_DoIP_DoIPDefaultConfig_DoIP_To_Dcm_Fun         (1)

#define PduR_CanIf_CanConfigSet_Tx_ACAN_ADAS_01             (0)
#define PduR_CanIf_CanConfigSet_Tx_ACAN_ADAS_02             (1)
#define PduR_CanIf_CanConfigSet_Tx_ACAN_ADAS_03             (2)
#define PduR_CanIf_CanConfigSet_Tx_ACAN_ADAS_04             (3)
#define PduR_CanIf_CanConfigSet_Tx_ACAN_ADAS_06             (4)
#define PduR_CanIf_CanConfigSet_Tx_ACAN_ADAS_07             (5)
#define PduR_CanIf_CanConfigSet_Tx_ACAN_ADAS_08             (6)
#define PduR_CanIf_CanConfigSet_Tx_ACAN_ADAS_Info15         (7)
#define PduR_CanIf_CanConfigSet_Tx_ACAN_ADAS_Info17         (8)
#define PduR_CanIf_CanConfigSet_Tx_ACAN_ADAS_Info23         (9)
#define PduR_CanIf_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info1 (10)
#define PduR_CanIf_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info3 (11)
#define PduR_CanIf_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info5 (12)
#define PduR_CanIf_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info7 (13)
#define PduR_CanIf_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info9 (14)
#define PduR_CanIf_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info11          (15)
#define PduR_CanIf_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info13          (16)
#define PduR_CanIf_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info15          (17)
#define PduR_CanIf_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info17          (18)
#define PduR_CanIf_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info19          (19)
#define PduR_CanIf_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info21          (20)
#define PduR_CanIf_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info23          (21)
#define PduR_CanIf_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info2 (22)
#define PduR_CanIf_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info4 (23)
#define PduR_CanIf_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info6 (24)
#define PduR_CanIf_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info8 (25)
#define PduR_CanIf_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info10          (26)
#define PduR_CanIf_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info12          (27)
#define PduR_CanIf_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info14          (28)
#define PduR_CanIf_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info16          (29)
#define PduR_CanIf_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info18          (30)
#define PduR_CanIf_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info20          (31)
#define PduR_CanIf_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info22          (32)
#define PduR_CanIf_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info24          (33)
#define PduR_CanIf_CanConfigSet_Tx_ACAN_ADAS_Info20         (34)
#define PduR_CanIf_CanConfigSet_Tx_ACAN_ADAS_Info21         (35)
#define PduR_CanIf_CanConfigSet_Tx_ACAN_ADAS_Info22         (36)

#define PduR_CanTp_CanConfigSet_Tx_ACAN_UDS_DiagResp_ADAS   (0)

#define PduR_SoAd_Tcp_Send                                  (0)
#define PduR_SoAd_Udp_Send                                  (1)
#define PduR_SoAd_Tcp_Send                                  (2)
#define PduR_SoAd_Udp_Send                                  (3)
#define PduR_SoAd_Udp_Send_1501                             (4)
#define PduR_SoAd_Udp_Send_1502                             (5)
#define PduR_SoAd_Udp_Send_1503                             (6)
#define PduR_SoAd_Udp_Send_1504                             (7)
#define PduR_SoAd_Udp_Send_1505                             (8)
#define PduR_SoAd_Udp_Send_1506                             (9)
#define PduR_SoAd_Udp_Send_1507                             (10)

#define PduR_DoIP_DoIPDefaultConfig_Dcm_To_DoIP             (0)

#define PDUR_NUMPDURROUTPATH                                (129)

#define PDUR_MAX_NUMPDURROUTPATH                            PDUR_NUMPDURROUTPATH

/*COM    TX*/
#define PDUR_NUMOFCOMTXPDU                                  (46)
/*DCM    TX*/
#define PDUR_NUMOFDCMTXPDU                                  (2)
/*J1939DCM    TX*/
#define PDUR_NUMOFJ1939DCMTXPDU                             (0)
/*J1939RM    TX*/
#define PDUR_NUMOFJ1939RMTXPDU                              (0)
/*CDD    TX*/
#define PDUR_NUMOFCDDTXPDU                                  (0)
/*IPDUM    TX*/
#define PDUR_NUMOFIPDUMTXPDU                                (0)
/*SECOC    TX*/
#define PDUR_NUMOFSECOCTXPDU                                (0)
/*CANTP    TX*/
#define PDUR_NUMOFCANTPTXPDU                                (1)
/*J1939TP    TX*/
#define PDUR_NUMOFJ1939TPTXPDU                              (0)
/*LINTP    TX*/
#define PDUR_NUMOFLINTPTXPDU                                (0)
/*FRTP    TX*/
#define PDUR_NUMOFFRTPTXPDU                                 (0)
/*SOADTP    TX*/
#define PDUR_NUMOFSOADTPTXPDU                               (0)
/*DOIP    TX*/
#define PDUR_NUMOFDOIPTPTXPDU                               (1)
/*CDDTP    TX*/
#define PDUR_NUMOFCDDTPTXPDU                                (0)
/*CANIF    TX*/
#define PDUR_NUMOFCANIFTXPDU                                (37)
/*LINIF    TX*/
#define PDUR_NUMOFLINIFTXPDU                                (0)
/*FRIF    TX*/
#define PDUR_NUMOFFRIFTXPDU                                 (0)
/*CANNM    TX*/
#define PDUR_NUMOFCANNMTXPDU                                (0)
/*UDPNM    TX*/
#define PDUR_NUMOFUDPNMTXPDU                                (0)
/*LDCOM    TX*/
#define PDUR_NUMOFLDCOMTXPDU                                (0)
/*SOMEIP    TX*/
#define PDUR_NUMOFSOMEIPTXPDU                               (0)

/*CANTP    RX*/
#define PDUR_NUMOFCANTPRXPDU                                (2)
/*J1939TP    RX*/
#define PDUR_NUMOFJ1939TPRXPDU                              (0)
/*LINTP    RX*/
#define PDUR_NUMOFLINTPRXPDU                                (0)
/*FRTP    RX*/
#define PDUR_NUMOFFRTPRXPDU                                 (0)
/*CDDTP    RX*/
#define PDUR_NUMOFCDDTPRXPDU                                (0)
/*SOADTP    RX*/
#define PDUR_NUMOFSOADTPRXPDU                               (0)
/*DOIP    RX*/
#define PDUR_NUMOFDOIPTPRXPDU                               (2)
/*CANIF    RX*/
#define PDUR_NUMOFCANIFRXPDU                                (48)
/*LINIF    RX*/
#define PDUR_NUMOFLINIFRXPDU                                (0)
/*FRIF    RX*/
#define PDUR_NUMOFFRIFRXPDU                                 (0)
/*CANNM    RX*/
#define PDUR_NUMOFCANNMRXPDU                                (0)
/*UDPNM    RX*/
#define PDUR_NUMOFUDPNMRXPDU                                (0)
/*DOIPIF    RX*/
#define PDUR_NUMOFDOIPIFRXPDU                               (0)
/*SOAD    RX*/
#define PDUR_NUMOFSOADIFRXPDU                               (17)
/*SOAD    TX*/
#define PDUR_NUMOFSOADIFTXPDU                               (11)
/*DOIP    TX*/
#define PDUR_NUMOFDOIPIFTXPDU                               (0)
/*DCM    RX*/
#define PDUR_NUMOFDCMRXPDU                                  (4)
/*J1939DCM    RX*/
#define PDUR_NUMOFJ1939DCMRXPDU                             (0)
/*J1939RM    RX*/
#define PDUR_NUMOFJ1939RMRXPDU                              (0)
/*CDD    RX*/
#define PDUR_NUMOFCDDRXPDU                                  (0)
/*IPDUM    RX*/
#define PDUR_NUMOFIPDUMRXPDU                                (0)
/*SECOC    RX*/
#define PDUR_NUMOFSECOCRXPDU                                (0)
/*CDDIF    RX*/
#define PDUR_NUMOFCDDIFRXPDU                                (0)
/*CDDIF    TX*/
#define PDUR_NUMOFCDDIFTXPDU                                (0)
/*IPDUMIF    RX*/
#define PDUR_NUMOFIPDUMIFRXPDU                              (0)
/*IPDUMIF    TX*/
#define PDUR_NUMOFIPDUMIFTXPDU                              (0)
/*SECOCIF    RX*/
#define PDUR_NUMOFSECOCIFRXPDU                              (0)
/*SECOCIF    TX*/
#define PDUR_NUMOFSECOCIFTXPDU                              (0)
/*SOMEIPTP    RX*/
#define PDUR_NUMOFSOMEIPTPRXPDU                             (0)
/*SOMEIPTP    TX*/
#define PDUR_NUMOFSOMEIPTPTXPDU                             (0)

#define PDUR_MAX_NUMOFCOMTXPDU                              PDUR_NUMOFCOMTXPDU
#define PDUR_MAX_NUMOFDCMTXPDU                              PDUR_NUMOFDCMTXPDU
#define PDUR_MAX_NUMOFDCMRXPDU                              PDUR_NUMOFDCMRXPDU
#define PDUR_MAX_NUMOFJ1939DCMTXPDU                         PDUR_NUMOFJ1939DCMTXPDU
#define PDUR_MAX_NUMOFJ1939DCMRXPDU                         PDUR_NUMOFJ1939DCMRXPDU
#define PDUR_MAX_NUMOFJ1939RMTXPDU                          PDUR_NUMOFJ1939RMTXPDU
#define PDUR_MAX_NUMOFCDDTXPDU                              PDUR_NUMOFCDDTXPDU
#define PDUR_MAX_NUMOFCDDTPTXPDU                            PDUR_NUMOFCDDTPTXPDU
#define PDUR_MAX_NUMOFCDDTPRXPDU                            PDUR_NUMOFCDDTPRXPDU
#define PDUR_MAX_NUMOFSOADTPRXPDU                           PDUR_NUMOFSOADTPRXPDU
#define PDUR_MAX_NUMOFCANIFTXPDU                            PDUR_NUMOFCANIFTXPDU
#define PDUR_MAX_NUMOFCANIFRXPDU                            PDUR_NUMOFCANIFRXPDU
#define PDUR_MAX_NUMOFCANTPTXPDU                            PDUR_NUMOFCANTPTXPDU
#define PDUR_MAX_NUMOFCANTPRXPDU                            PDUR_NUMOFCANTPRXPDU
#define PDUR_MAX_NUMOFCANNMTXPDU                            PDUR_NUMOFCANNMTXPDU
#define PDUR_MAX_NUMOFCANNMRXPDU                            PDUR_NUMOFCANNMRXPDU
#define PDUR_MAX_NUMOFUDPNMTXPDU                            PDUR_NUMOFUDPNMTXPDU
#define PDUR_MAX_NUMOFUDPNMRXPDU                            PDUR_NUMOFUDPNMRXPDU
#define PDUR_MAX_NUMOFJ1939TPTXPDU                          PDUR_NUMOFJ1939TPTXPDU
#define PDUR_MAX_NUMOFJ1939TPRXPDU                          PDUR_NUMOFJ1939TPRXPDU
#define PDUR_MAX_NUMOFLINIFTXPDU                            PDUR_NUMOFLINIFTXPDU
#define PDUR_MAX_NUMOFLINIFRXPDU                            PDUR_NUMOFLINIFRXPDU
#define PDUR_MAX_NUMOFLINTPTXPDU                            PDUR_NUMOFLINTPTXPDU
#define PDUR_MAX_NUMOFLINTPRXPDU                            PDUR_NUMOFLINTPRXPDU
#define PDUR_MAX_NUMOFFRIFTXPDU                             PDUR_NUMOFFRIFTXPDU
#define PDUR_MAX_NUMOFFRIFRXPDU                             PDUR_NUMOFFRIFRXPDU
#define PDUR_MAX_NUMOFFRTPTXPDU                             PDUR_NUMOFFRTPTXPDU
#define PDUR_MAX_NUMOFFRTPRXPDU                             PDUR_NUMOFFRTPRXPDU
#define PDUR_MAX_NUMOFDOIPIFRXPDU                           PDUR_NUMOFDOIPIFRXPDU
#define PDUR_MAX_NUMOFDOIPTPTXPDU                           PDUR_NUMOFDOIPTPTXPDU
#define PDUR_MAX_NUMOFDOIPTPRXPDU                           PDUR_NUMOFDOIPTPRXPDU
#define PDUR_MAX_NUMOFSOADIFRXPDU                           PDUR_NUMOFSOADIFRXPDU
#define PDUR_MAX_NUMOFSOADIFTXPDU                           PDUR_NUMOFSOADIFTXPDU
#define PDUR_MAX_NUMOFCDDIFRXPDU                            PDUR_NUMOFCDDIFRXPDU
#define PDUR_MAX_NUMOFCDDIFTXPDU                            PDUR_NUMOFCDDIFTXPDU
#define PDUR_MAX_NUMOFIPDUMRXPDU                            PDUR_NUMOFIPDUMRXPDU
#define PDUR_MAX_NUMOFIPDUMTXPDU                            PDUR_NUMOFIPDUMTXPDU
#define PDUR_MAX_NUMOFSECOCRXPDU                            PDUR_NUMOFSECOCRXPDU
#define PDUR_MAX_NUMOFSECOCTXPDU                            PDUR_NUMOFSECOCTXPDU
#define PDUR_MAX_NUMOFIPDUMIFRXPDU                          PDUR_NUMOFIPDUMIFRXPDU
#define PDUR_MAX_NUMOFIPDUMIFTXPDU                          PDUR_NUMOFIPDUMIFTXPDU
#define PDUR_MAX_NUMOFSECOCIFRXPDU                          PDUR_NUMOFSECOCIFRXPDU
#define PDUR_MAX_NUMOFSECOCIFTXPDU                          PDUR_NUMOFSECOCIFTXPDU
#define PDUR_MAX_NUMOFSOMEIPTXPDU                           PDUR_NUMOFSOMEIPTXPDU
#define PDUR_MAX_NUMOFLDCOMTXPDU                            PDUR_NUMOFLDCOMTXPDU
#define PDUR_MAX_NUMOFSOMEIPTPRXPDU                         PDUR_NUMOFSOMEIPTPRXPDU
#define PDUR_MAX_NUMOFSOMEIPTPTXPDU                         PDUR_NUMOFSOMEIPTPTXPDU

#define PDUR_NUMOFROUTINGPATHGROUP                          (1)
#define PDUR_MAX_NUMOFROUTINGPATHGROUP                      PDUR_NUMOFROUTINGPATHGROUP

#define PDUR_NUMOFBUFFER                                    (0)
#define PDUR_MAX_NUMOFBUFFER                                PDUR_NUMOFBUFFER

typedef uint8 PduR_MulticastMaskType;
typedef uint8 PduR_RoutingPathIdType;


#define PDUR_START_SEC_CONFIG_DATA_8
#include "MemMap.h"

/*PDUR329_Conf*/
extern CONST(boolean, PDUR_CONST) PduR_RPGroupEnabledAtInit[PDUR_NUMOFROUTINGPATHGROUP];

#define PDUR_STOP_SEC_CONFIG_DATA_8
#include "MemMap.h"



#endif


