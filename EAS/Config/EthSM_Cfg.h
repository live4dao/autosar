/*  BEGIN_FILE_HDR
********************************************************************************
*   File Name       : EthSM_Cfg.h
********************************************************************************
*   Project/Product : AUTOSAR BSW PROJECT
*   Title           : EthSM module configuration File
*   Author          : Hirain
********************************************************************************
*   Description     : EthSM module configuration File
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

#ifndef ETHSM_CFG_H
#define ETHSM_CFG_H
/*******************************************************************************
*   General
*******************************************************************************/
#define ETHSM_CONFIG_VARIANTS                               STD_CONFIG_VARIANTS_PRECOMPILE
#define ETHSM_VERSION_CHECK                                 STD_ON
/*ECUC_EthSM_00065*/
#define ETHSM_DEV_ERROR_DETECT                              STD_OFF
/*ECUC_EthSM_00092*/
#define ETHSM_VERSION_INFO_API                              STD_OFF
/*ECUC_EthSM_00066*/
#define ETHSM_MAIN_FUNCTION_TIME_PERIOD                     5
/*ECUC_EthSM_00079*/
#define ETHSM_DUMMY_MODE                                    STD_OFF
#define ETHSM_SW_MAJOR_VERSION_CFG                          1
#define ETHSM_SW_MINOR_VERSION_CFG                          0
#define ETHSM_SW_PATCH_VERSION_CFG                          8
#define ETHSM_AR_RELEASE_MAJOR_VERSION_CFG                  4
#define ETHSM_AR_RELEASE_MINOR_VERSION_CFG                  2
#define ETHSM_AR_RELEASE_REVISION_VERSION_CFG               2
/*******************************************************************************
*   EAS Special
*******************************************************************************/
/*user cfg*/
#define ETHSM_BSWM_SUPPORT                                  STD_OFF
/*auto get*/
#define ETHSM_MAX_NETWORK_NUM                               1
/*ECUC_EthSM_00105*/

#define ETHSM_DEM_ENABLED                                   STD_OFF
/*******************************************************************************
*   Access
*******************************************************************************/

/*SWS_EthSM_00019*/
#define ETHSM_NETWORK_ETHCTRL_ID                            EthIf_EthIfController0
#define ETHSM_NETWORK_HANDLE_ID                             ComM_ComM_EthCtrl
#define ETHSM_NETWORK_HANDLE_NUM                            1
#define EthSM_ComM_EthCtrl                                    0
#endif /* ETHSM_CFG_H */
