
/*  BEGIN_FILE_HDR
********************************************************************************
*   File Name       : UdpNm_Cfg.h
********************************************************************************
*   Project/Product : AUTOSAR BSW PROJECT
*   Title           : UdpNm module configuration File
*   Author          : Hirain
********************************************************************************
*   Description     : UdpNm module configuration File
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


#ifndef UDPNM_CFG_H
#define UDPNM_CFG_H
/*******************************************************************************
*   Macro
*******************************************************************************/

/*The configuration variant and version informations*/
#define UDPNM_CONFIG_VARIANTS                               STD_CONFIG_VARIANTS_PRECOMPILE
/*ECUC_UdpNm_00006 UdpNmBusSynchronizationEnabled*/
#define UDPNM_BUS_SYNCHRONIZATION_ENABLED                   STD_OFF
/*ECUC_UdpNm_00013 UdpNmComControlEnabled*/
#define UDPNM_COM_CONTROL_ENABLED                           STD_ON
/*ECUC_UdpNm_00055 UdpNmComUserDataSupport*/
#define UDPNM_COM_USER_DATA_SUPPORT                         STD_OFF
/*ECUC_UdpNm_00059 UdpNmCoordinatorSyncSupport*/
#define UDPNM_COORDINATOR_SYNC_SUPPORT                      STD_OFF
/*ECUC_UdpNm_00040 UdpNmCoordinatorEnabled*/
#define UDPNM_COORDINATOR_ENABLE                            STD_OFF
/*ECUC_UdpNm_00002 UdpNmDevErrorDetect*/
#define UDPNM_DEV_ERROR_DETECT                              STD_ON
/*ECUC_UdpNm_00009 UdpNmImmediateRestartEnabled*/
#define UDPNM_IMMEDIATE_RESTART_ENABLED                     STD_OFF
/*ECUC_UdpNm_00007 UdpNmNodeDetectionEnabled*/
#define UDPNM_NODE_DETECTION_ENABLED                        STD_ON
/*ECUC_UdpNm_00008 UdpNmNodeIdEnabled*/
#define UDPNM_NODE_ID_ENABLED                               STD_ON
/*ECUC_UdpNm_00014 UdpNmNumberOfChannels*/
#define UDPNM_NUMBER_OF_CHANNELS                            ((uint8)1)
/*ECUC_UdpNm_00010 UdpNmPassiveModeEnabled*/
#define UDPNM_PASSIVE_MODE_ENABLED                          STD_OFF
/*ECUC_UdpNm_00011 UdpNmPduRxIndicationEnabled*/
#define UDPNM_PDU_RX_INDICATION_ENABLED                     STD_OFF
/*ECUC_UdpNm_00066 UdpNmPnEiraCalcEnabled*/
#define UDPNM_PN_EIRA_CALC_ENABLED                          STD_OFF
/*ECUC_UdpNm_00065 UdpNmPnResetTime*/
#define UDPNM_PN_RESET_TIME                                 ((uint16)1)
/*ECUC_UdpNm_00005 UdpNmRemoteSleepIndEnabled*/
#define UDPNM_REMOTE_SLEEP_IND_ENABLED                      STD_OFF
/*ECUC_UdpNm_00015 UdpNmRepeatMsgIndEnabled*/
#define UDPNM_REPEAT_MSG_IND_ENABLED                        STD_OFF
/*ECUC_UdpNm_00012 UdpNmStateChangeIndEnabled*/
#define UDPNM_STATE_CHANGE_IND_ENABLED                      STD_ON
/*ECUC_UdpNm_00004 UdpNmUserDataEnabled*/
#define UDPNM_USER_DATA_ENABLED                             STD_ON
/*ECUC_UdpNm_00003 UdpNmVersionInfoApi*/
#define UDPNM_VERSION_INFO_API                              STD_ON


#define UDPNM_GLOBAL_PN_SUPPORT                             STD_OFF


/*ECUC_UdpNm_00032 UdpNmMainFunctionPeriod: ms*/
#define UDPNM_MAIN_FUNCTION_PERIOD                          (uint8)5

/*ECUC_UdpNm_00050 UDPNM_DEM_ENABLED*/ 
#define UDPNM_DEM_ENABLED                                   STD_OFF


#define UDPNM_PRIVATE_VERSION_CHECK                         STD_ON


#define UDPNM_SW_MAJOR_VERSION_CFG                          1
#define UDPNM_SW_MINOR_VERSION_CFG                          0
#define UDPNM_SW_PATCH_VERSION_CFG                          6

#define UDPNM_AR_RELEASE_MAJOR_VERSION_CFG                  4
#define UDPNM_AR_RELEASE_MINOR_VERSION_CFG                  2
#define UDPNM_AR_RELEASE_REVISION_VERSION_CFG               2


/*UdpConnection  RxPdu*/
#define UdpNm_SoAd_UdpNm_Rx                                 (0)

/*UdpConnection  TxPdu*/
#define UdpNm_SoAd_UdpNm_Tx                                 (0)

/*UdpConnection  UserDataTxPdu*/

#define UDPNM_NUMBER_OF_TXPDUID                             (1)
#define UDPNM_NUMBER_OF_RXPDUID                             (1)

#define UdpNM_ComM_EthCtrl                                  (0)
#endif

