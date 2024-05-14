/*  BEGIN_FILE_HDR
********************************************************************************
*   File Name       : EthTSyn_Cfg.h
********************************************************************************
*   Project/Product : AUTOSAR BSW PROJECT
*   Title           : EthTSyn module configuration File
*   Author          : Hirain
********************************************************************************
*   Description     : EthTSyn module configuration File
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
#ifndef ETHTSYN_CFG_H
#define ETHTSYN_CFG_H

#include "Std_Types.h"
/*******************************************************************************
*   Macros
*******************************************************************************/
#define ETHTSYN_CONFIG_VARIANTS                             STD_CONFIG_VARIANTS_PRECOMPILE

#define ETHTSYN_PRIVATE_VERSION_CHECK                       STD_ON

#define ETHTSYN_DEV_ERROR_DETECT                            STD_OFF

#define ETHTSYN_VERSION_INFO                                STD_OFF

#define ETHTSYN_HW_TIMESTAMP_SUPPORT                        STD_OFF

#define ETHTSYN_MAINFUNCTION_PERIOD                         ((uint8)5)

#define ETHTSYN_GT_TX_FOLLOWUP_OFFSET                       ((uint16)1000)

#define ETHTSYN_GET_MASTER_MAX_NUMBER                       (uint8)1

#define ETHTSYN_GET_SLAVE_MAX_NUMBER                        (uint8)0

#define ETHTSYN_PORT_SLAVE_SUPPORT                          STD_OFF

#define ETHTSYN_PORT_MASTER_SUPPORT                         STD_ON

#define ETHTSYN_SW_MAJOR_VERSION_CFG                        1
#define ETHTSYN_SW_MINOR_VERSION_CFG                        1
#define ETHTSYN_SW_PATCH_VERSION_CFG                        0

#define ETHTSYN_AR_RELEASE_MAJOR_VERSION_CFG                4
#define ETHTSYN_AR_RELEASE_MINOR_VERSION_CFG                2
#define ETHTSYN_AR_RELEASE_REVISION_VERSION_CFG             2

#endif
 /* ETHTSYN_LCFG_H */
