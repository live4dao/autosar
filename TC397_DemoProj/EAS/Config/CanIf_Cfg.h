/*  BEGIN_FILE_HDR
********************************************************************************
*   File Name       : CanIf_Cfg.h
********************************************************************************
*   Project/Product : AUTOSAR BSW PROJECT
*   Title           : CanIf module configuration File
*   Author          : Hirain
********************************************************************************
*   Description     : CanIf module configuration File
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
#ifndef CANIF_CFG_H
#define CANIF_CFG_H

/*******************************************************************************
*   Common Macro
*******************************************************************************/
#define CANIF_FILTER_TYPE_BINARY                            1
#define CANIF_FILTER_TYPE_INDEX                             2
#define CANIF_FILTER_TYPE_LINEAR                            3
#define CANIF_FILTER_TYPE_TABLE                             4
/* CanIf Dlc Check Type*/
#define CANIF_DLC_CHECK_AUTOSAR                             0
#define CANIF_DLC_CHECK_USER                                1
/*******************************************************************************
*   Non Autosar Standard
*******************************************************************************/
#define CANIF_CONFIG_VARIANTS                               STD_CONFIG_VARIANTS_PRECOMPILE
#define CANIF_MAX_CONTROLLER_NUM                            2
#define CANIF_MAX_TRCV_NUM                                  0
#define CANIF_MAX_TXPDU_NUM                                 40
#define CANIF_MAX_RXPDU_NUM                                 51
#define CANIF_MAX_HTH_NUM                                   33
#define CANIF_MAX_HRH_NUM                                   51
#define CANIF_MAX_TXBUF_NUM                                 14
#define CANIF_MAX_DYNTXPDU_NUM                              0
#define CANIF_MAX_TXNOTIFY_NUM                              0
#define CANIF_MAX_RXBUF_NUM                                 0
#define CANIF_MAX_RXNOTIFY_NUM                              0
#define CANIF_MAX_TXTRIGGER_NUM                             0

#define CANIF_DLC_CHECK_TYPE                                CANIF_DLC_CHECK_AUTOSAR
#define CANIF_HRH_RANGE_FILTER_SUPPORT                      STD_ON
#define CANIF_PRIVATE_VERSION_CHECK                         STD_ON
#define CANIF_HOH_OPTIMIZE_SUPPORT                          STD_OFF
#define CANIF_PUBLIC_MULTIPLE_TRCVDRV_SUPPORT               STD_OFF
#define CANIF_PRIVATE_CANFD_SUPPORT                         STD_ON

#define CANIF_CAN_VERSION_NEWER_THAN_422                    STD_ON
#define CANIF_SW_MAJOR_VERSION_CFG                          1
#define CANIF_SW_MINOR_VERSION_CFG                          3
#define CANIF_SW_PATCH_VERSION_CFG                          2
#define CANIF_AR_RELEASE_MAJOR_VERSION_CFG                  4
#define CANIF_AR_RELEASE_MINOR_VERSION_CFG                  2
#define CANIF_AR_RELEASE_REVISION_VERSION_CFG               2
/*******************************************************************************
*   CanIfPrivateCfg
*******************************************************************************/
#define CANIF_PRIVATE_DLC_CHECK                             STD_OFF
#define CANIF_PRIVATE_SOFTWARE_FILTER_TYPE                  CANIF_FILTER_TYPE_INDEX
#define CANIF_SUPPORT_TTCAN                                 STD_OFF
#define CANIF_FIXED_BUFFER                                  STD_ON
#define CANIF_OSEKNM_SUPPORT                                STD_OFF
#define CANIF_PRIVATE_SWTXFIFO_SUPPORT                      STD_OFF
#define CANIF_PRIVATE_SWTXFIFO_DEBUG                        STD_OFF
#define CANIF_PRIVATE_SWTXFIFO_RETRY                        STD_OFF
#define CANIF_PRIVATE_SWTXFIFO_TXTIMEOUT_VAL                3
/*******************************************************************************
*   CanIfPublicCfg
*******************************************************************************/
#define CANIF_METADATA_SUPPORT                              STD_OFF
#define CANIF_PUBLIC_CANCEL_TRANSMIT_SUPPORT                STD_ON
#define CANIF_SET_BAUDRATE_API                              STD_OFF
#define CANIF_PUBLIC_DEV_ERROR_DETECT                       STD_ON
#define CANIF_PUBLIC_MULTIPLE_DRV_SUPPORT                   STD_OFF
#define CANIF_PUBLIC_NUMBER_OF_CAN_HW_UNITS                 2
#define CANIF_PUBLIC_READRXPDU_DATA_API                     STD_OFF
#define CANIF_PUBLIC_READRXPDU_NOTIFY_STATUS_API            STD_OFF
#define CANIF_PUBLIC_READTXPDU_NOTIFY_STATUS_API            STD_OFF
#define CANIF_PUBLIC_SETDYNAMICTXID_API                     STD_OFF
#define CANIF_PUBLIC_TX_BUFFERING                           STD_ON
#define CANIF_PUBLIC_VERSION_INFO_API                       STD_OFF
#define CANIF_PUBLIC_WAKEUP_CHECK_VALIDATION_SUPPORT        STD_OFF
#define CANIF_PUBLIC_PN_SUPPORT                             STD_OFF
#define CANIF_PUBLIC_TXCONFIRM_POLLING_SUPPORT              STD_OFF
#define CANIF_PUBLIC_WAKEUP_CHECK_VALID_BY_NM               STD_OFF
#define CANIF_PUBLIC_WAKEUP_CHECK_VALID_BY_OSEKNM           STD_OFF
#define CANIF_PUBLIC_ICOM_SUPPORT                           STD_OFF
#define CANIF_TRIGGER_TRANSMIT_SUPPORT                      STD_OFF
#define CANIF_TXOFF_ACTIVE_SUPPORT                          STD_OFF
#define CANIF_WAKEUP_SUPPORT                                STD_OFF
#define CANIF_PUBLIC_WAKEUP_CHECK_VALID_BY_PNNM             STD_OFF
/*******************************************************************************
*   ConfigSet handle
*******************************************************************************/
#define CanIf_CanConfigSet                                  ((uint8)0)
/*******************************************************************************
*   CanIfTxPduCfg
*******************************************************************************/
/*CanConfigSet*/
#define CanIf_CanConfigSet_Tx_Radar_ADCU_SYNC_FUP           ((PduIdType)0)
#define CanIf_CanConfigSet_Tx_ACAN_ADAS_01                  ((PduIdType)1)
#define CanIf_CanConfigSet_Tx_ACAN_ADAS_02                  ((PduIdType)2)
#define CanIf_CanConfigSet_Tx_ACAN_ADAS_03                  ((PduIdType)3)
#define CanIf_CanConfigSet_Tx_ACAN_ADAS_04                  ((PduIdType)4)
#define CanIf_CanConfigSet_Tx_ACAN_ADAS_06                  ((PduIdType)5)
#define CanIf_CanConfigSet_Tx_ACAN_ADAS_07                  ((PduIdType)6)
#define CanIf_CanConfigSet_Tx_ACAN_ADAS_08                  ((PduIdType)7)
#define CanIf_CanConfigSet_Tx_ACAN_ADAS_Info15              ((PduIdType)8)
#define CanIf_CanConfigSet_Tx_ACAN_ADAS_Info17              ((PduIdType)9)
#define CanIf_CanConfigSet_Tx_ACAN_ADAS_Info23              ((PduIdType)10)
#define CanIf_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info1      ((PduIdType)11)
#define CanIf_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info3      ((PduIdType)12)
#define CanIf_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info5      ((PduIdType)13)
#define CanIf_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info7      ((PduIdType)14)
#define CanIf_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info9      ((PduIdType)15)
#define CanIf_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info11     ((PduIdType)16)
#define CanIf_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info13     ((PduIdType)17)
#define CanIf_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info15     ((PduIdType)18)
#define CanIf_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info17     ((PduIdType)19)
#define CanIf_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info19     ((PduIdType)20)
#define CanIf_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info21     ((PduIdType)21)
#define CanIf_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info23     ((PduIdType)22)
#define CanIf_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info2      ((PduIdType)23)
#define CanIf_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info4      ((PduIdType)24)
#define CanIf_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info6      ((PduIdType)25)
#define CanIf_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info8      ((PduIdType)26)
#define CanIf_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info10     ((PduIdType)27)
#define CanIf_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info12     ((PduIdType)28)
#define CanIf_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info14     ((PduIdType)29)
#define CanIf_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info16     ((PduIdType)30)
#define CanIf_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info18     ((PduIdType)31)
#define CanIf_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info20     ((PduIdType)32)
#define CanIf_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info22     ((PduIdType)33)
#define CanIf_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info24     ((PduIdType)34)
#define CanIf_CanConfigSet_Tx_ACAN_ADAS_Info20              ((PduIdType)35)
#define CanIf_CanConfigSet_Tx_ACAN_ADAS_Info21              ((PduIdType)36)
#define CanIf_CanConfigSet_Tx_ACAN_ADAS_Info22              ((PduIdType)37)
#define CanIf_CanConfigSet_Tx_ACAN_ADAS_NM                  ((PduIdType)38)
#define CanIf_CanConfigSet_Tx_ACAN_UDS_DiagResp_ADAS        ((PduIdType)39)
/*******************************************************************************
*   CanIfRxPduCfg
*******************************************************************************/
/*CanConfigSet*/
#define CanIf_CanConfigSet_Rx_Radar_ARS_TIME_SYNC           ((PduIdType)0)
#define CanIf_CanConfigSet_Rx_Radar_ARS_SYS_PERFORM         ((PduIdType)1)
#define CanIf_CanConfigSet_Rx_ACAN_ACU_ChimeTelltaleReq     ((PduIdType)2)
#define CanIf_CanConfigSet_Rx_ACAN_BCM_LIGHT_0x106          ((PduIdType)3)
#define CanIf_CanConfigSet_Rx_ACAN_BCM_SwitchSts_0x109      ((PduIdType)4)
#define CanIf_CanConfigSet_Rx_ACAN_ABS_FrontWheelSpeMCUKPH  ((PduIdType)5)
#define CanIf_CanConfigSet_Rx_ACAN_ABS_RearWheelSpeMCUKPH   ((PduIdType)6)
#define CanIf_CanConfigSet_Rx_ACAN_ABS_WheelSpeedRC         ((PduIdType)7)
#define CanIf_CanConfigSet_Rx_ACAN_ABS_Status               ((PduIdType)8)
#define CanIf_CanConfigSet_Rx_ACAN_ESC_Status_0x132         ((PduIdType)9)
#define CanIf_CanConfigSet_Rx_ACAN_VCU_Ctrl                 ((PduIdType)10)
#define CanIf_CanConfigSet_Rx_ACAN_VCU_StsEpt               ((PduIdType)11)
#define CanIf_CanConfigSet_Rx_ACAN_SAS_Sensor_0x17E         ((PduIdType)12)
#define CanIf_CanConfigSet_Rx_ACAN_EPS_LKA_Sts              ((PduIdType)13)
#define CanIf_CanConfigSet_Rx_ACAN_BCM_PEPS_Sts             ((PduIdType)14)
#define CanIf_CanConfigSet_Rx_ACAN_MHU_ADSA01               ((PduIdType)15)
#define CanIf_CanConfigSet_Rx_ACAN_MHU_ADAS02               ((PduIdType)16)
#define CanIf_CanConfigSet_Rx_ACAN_MHU_ADAS03               ((PduIdType)17)
#define CanIf_CanConfigSet_Rx_Radar_ARS_OD_Header           ((PduIdType)18)
#define CanIf_CanConfigSet_Rx_Radar_ARS_OD_00_01            ((PduIdType)19)
#define CanIf_CanConfigSet_Rx_ACAN_BCM_WindowSts            ((PduIdType)20)
#define CanIf_CanConfigSet_Rx_Radar_ARS_OD_02_03            ((PduIdType)21)
#define CanIf_CanConfigSet_Rx_Radar_ARS_OD_04_05            ((PduIdType)22)
#define CanIf_CanConfigSet_Rx_Radar_ARS_OD_06_07            ((PduIdType)23)
#define CanIf_CanConfigSet_Rx_Radar_ARS_OD_08_09            ((PduIdType)24)
#define CanIf_CanConfigSet_Rx_Radar_ARS_OD_10_11            ((PduIdType)25)
#define CanIf_CanConfigSet_Rx_Radar_ARS_OD_12_13            ((PduIdType)26)
#define CanIf_CanConfigSet_Rx_Radar_ARS_OD_14_15            ((PduIdType)27)
#define CanIf_CanConfigSet_Rx_Radar_ARS_OD_16_17            ((PduIdType)28)
#define CanIf_CanConfigSet_Rx_Radar_ARS_OD_18_19            ((PduIdType)29)
#define CanIf_CanConfigSet_Rx_Radar_ARS_OD_20_21            ((PduIdType)30)
#define CanIf_CanConfigSet_Rx_Radar_ARS_OD_22_23            ((PduIdType)31)
#define CanIf_CanConfigSet_Rx_Radar_ARS_OD_24_25            ((PduIdType)32)
#define CanIf_CanConfigSet_Rx_Radar_ARS_OD_26_27            ((PduIdType)33)
#define CanIf_CanConfigSet_Rx_Radar_ARS_OD_28_29            ((PduIdType)34)
#define CanIf_CanConfigSet_Rx_Radar_ARS_OD_30_31            ((PduIdType)35)
#define CanIf_CanConfigSet_Rx_ACAN_ESC_EPB_0x230            ((PduIdType)36)
#define CanIf_CanConfigSet_Rx_ACAN_IBS_ADAS_Info            ((PduIdType)37)
#define CanIf_CanConfigSet_Rx_ACAN_IBS_Info                 ((PduIdType)38)
#define CanIf_CanConfigSet_Rx_ACAN_TBOX_DateTime1           ((PduIdType)39)
#define CanIf_CanConfigSet_Rx_ACAN_MHU_Status_Info          ((PduIdType)40)
#define CanIf_CanConfigSet_Rx_ACAN_CCU_StsInfo1             ((PduIdType)41)
#define CanIf_CanConfigSet_Rx_ACAN_ESC_YawAngle_0x3E2       ((PduIdType)42)
#define CanIf_CanConfigSet_Rx_ACAN_IPC_TotalOdometer        ((PduIdType)43)
#define CanIf_CanConfigSet_Rx_ACAN_MFS_L_Control_Button2_0x3F7        ((PduIdType)44)
#define CanIf_CanConfigSet_Rx_ACAN_BCM_RLS                  ((PduIdType)45)
#define CanIf_CanConfigSet_Rx_ACAN_BCM_TPMS_Info2           ((PduIdType)46)
#define CanIf_CanConfigSet_Rx_ACAN_BCM_DoorState_0x4D4      ((PduIdType)47)
#define CanIf_CanConfigSet_Rx_ACAN_VCA_NM                   ((PduIdType)48)
#define CanIf_CanConfigSet_Rx_ACAN_UDS_PhyDiagReq_ADAS      ((PduIdType)49)
#define CanIf_CanConfigSet_Rx_ACAN_UDS_FuncDiagReq          ((PduIdType)50)
/*******************************************************************************
*   CanIfCtrl Trcv Cfg
*******************************************************************************/
#define CANIF_CTRL_WAKEUP_SUPPORT                           STD_OFF
#define CANIF_TRCV_WAKEUP_SUPPORT                           STD_OFF
/*Ctrl Handles*/
#define CanIf_CanIf_CanCtrl_0                               ((uint8)0)
#define CanIf_CanIf_CanCtrl_1                               ((uint8)1)
/*Trcv Handles*/
/*******************************************************************************
*   Access macro
*******************************************************************************/
#define CANIF_USED_CONTROLLER_NUM                           ((uint8)2)
#define CANIF_USED_TRCV_NUM                                 ((uint8)0)
#define CANIF_USED_TXPDU_NUM                                ((PduIdType)40)
#define CANIF_USED_RXPDU_NUM                                ((PduIdType)51)
#define CANIF_USED_HTH_NUM                                  ((Can_HwHandleType)33)
#define CANIF_USED_HRH_NUM                                  ((Can_HwHandleType)51)
#define CANIF_USED_TXBUF_NUM                                ((PduIdType)14)
#define CANIF_USED_DYNTXPDU_NUM                             ((PduIdType)0)
#define CANIF_USED_TXNOTIFY_NUM                             ((PduIdType)0)
#define CANIF_USED_RXBUF_NUM                                ((PduIdType)0)
#define CANIF_USED_RXNOTIFY_NUM                             ((PduIdType)0)
#define CANIF_USED_WAKRUPSRC_NUM                            ((uint8)0)
#define CANIF_DISPATCH_USERCTRLBUSOFF_NAME                  CanSM_ControllerBusOff(ControllerId)
#define CANIF_DISPATCH_USERCTRLMODEINDICATION_NAME          CanSM_ControllerModeIndication(ControllerId, (CanIf_ControllerModeType)ControllerMode)

#endif /* CANIF_CFG_H */


