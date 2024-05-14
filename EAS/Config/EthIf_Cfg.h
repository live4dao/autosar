/*  BEGIN_FILE_HDR
********************************************************************************
*   File Name       : EthIf_Cfg.h
********************************************************************************
*   Project/Product : AUTOSAR BSW PROJECT
*   Title           : EthIf module configuration File
*   Author          : Hirain
********************************************************************************
*   Description     : EthIf module configuration File
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
#ifndef EthIf_CFG_H
#define EthIf_CFG_H
/*******************************************************************************
*   Includes
*******************************************************************************/
#include "Std_Types.h"
/*[ECUC_EthIf_00003]*/
#define ETHIF_MAX_TRCVS_TOTAL                               8
/*[ECUC_EthIf_00004]*/
#define ETHIF_DEV_ERROR_DETECT                              STD_OFF
/*[ECUC_EthIf_00005]*/
#define ETHIF_ENABLE_RX_INTERRUPT                           STD_OFF
/*[ECUC_EthIf_00006]*/
#define ETHIF_ENABLE_TX_INTERRUPT                           STD_OFF
/*[ECUC_EthIf_00007]*/
#define ETHIF_VERSION_INFO_API                              STD_OFF
/*[ECUC_EthIf_00008]*/
#define ETHIF_VERSIONINFO_API_MACRO                         STD_OFF
/*[ECUC_EthIf_00009]*/
#define ETHIF_TRCV_LINKSTATECHG_MAIN_RELOAD                 8
/*[ECUC_EthIf_000023]*/
#define ETHIF_MAIN_FUNCTION_PERIOD                          5
/*[ECUC_EthIf_00030]*/
#define ETHIF_RX_INDICATION_ITERATIONS                      8
/*[ECUC_EthIf_00034]*/
#define ETHIF_GET_BAUD_RATE                                 STD_OFF
/*[ECUC_EthIf_00040]*/
#define ETHIF_WAKEUP_SUPPORT                                STD_OFF
/*[ECUC_EthIf_00041]*/
#define ETHIF_GET_TRANSCEIVER_WAKEUP_MODE_API               STD_OFF
/*[SWS_EthIf_00192],[SWS_EthIf_00204],[SWS_EthIf_00216],[SWS_EthIf_00221]*/

#define ETHIF_SWITCH_SUPPORT                                STD_OFF

#define ETHIF_ETHSM_SUPPORT                                 STD_ON

#define ETHIF_MULTIPLE_DRV_SUPPORT                          STD_OFF

#define ETHIF_WAKEUPMAP_NUM                                 0

#define ETHIF_LINKCHEK_NUM_PER_MAIN                         1u

#define ETHIF_DEFAULT_CONFIGURATION_PTR                     &EthIf_ConfigSet

#define ETHIF_CONFIG_VARIANTS                               STD_CONFIG_VARIANTS_PRECOMPILE

#define ETHIF_PRIVATE_VERSION_CHECK                         STD_ON

#define ETHIF_SW_MAJOR_VERSION_CFG                          1
#define ETHIF_SW_MINOR_VERSION_CFG                          1
#define ETHIF_SW_PATCH_VERSION_CFG                          1

#define ETHIF_AR_RELEASE_MAJOR_VERSION_CFG                  4
#define ETHIF_AR_RELEASE_MINOR_VERSION_CFG                  2
#define ETHIF_AR_RELEASE_REVISION_VERSION_CFG               2

#define ETHIF_CALLUP_CTRLMODE_INDICATION(CtrlIdx, CtrlMode) EthSM_CtrlModeIndication(CtrlIdx, CtrlMode)

#define ETHIF_CALLUP_TRCVMODE_INDICATION(CtrlIdx, TrcvMode) EthSM_TrcvModeIndication(CtrlIdx, TrcvMode)

#define EthIf_EthIfController0                              0

#endif 
