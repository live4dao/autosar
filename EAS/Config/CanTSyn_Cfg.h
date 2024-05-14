/*  BEGIN_FILE_HDR
********************************************************************************
*   File Name       : CanTSyn_Cfg.h
********************************************************************************
*   Project/Product : AUTOSAR BSW PROJECT
*   Title           : CanTSyn module configuration File
*   Author          : Hirain
********************************************************************************
*   Description     : CanTSyn module configuration File
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
#ifndef CanTSyn_CFG_H
#define CanTSyn_CFG_H



/*******************************************************************************
*   CanTSynGeneral
*******************************************************************************/
#define CANTSYN_CONFIG_VARIANTS                             STD_CONFIG_VARIANTS_PRECOMPILE
#define CANTSYN_DEV_ERROR_DETECT                            STD_OFF
#define CANTSYN_MAIN_FUNCTION_PERIOD                        5
#define CANTSYN_VERSION_INFO                                STD_ON
#define CANTSYN_CRC_ENABLED                                 STD_OFF
#define CANTSYN_CRC_START_VALUE                             (uint8)0xFF
#define CANTSYN_TXPDU_NUM                                   1
#define CANTSYN_RXPDU_NUM                                   0


/*****************************************************************************
* numbers of object
******************************************************************************/
#define CANTSYN_SYNC_MASTER_NUM                             1
#define CANTSYN_OFS_MASTER_NUM                              0
#define CANTSYN_SYNC_SLAVE_NUM                              0
#define CANTSYN_OFS_SLAVE_NUM                               0


/*****************************************************************************
* Object Handles
******************************************************************************/
/*Master */
#define CanTSyn_CanConfigSet_Tx_Radar_ADCU_SYNC_FUP         ((PduIdType)0)
/*Slave*/


/*****************************************************************************
* generate tool's version
******************************************************************************/
#define CANTSYN_PRIVATE_VERSION_CHECK                       STD_ON
#define CANTSYN_SW_MAJOR_VERSION_CFG                        1
#define CANTSYN_SW_MINOR_VERSION_CFG                        1
#define CANTSYN_SW_PATCH_VERSION_CFG                        4
#define CANTSYN_AR_RELEASE_MAJOR_VERSION_CFG                4
#define CANTSYN_AR_RELEASE_MINOR_VERSION_CFG                2
#define CANTSYN_AR_RELEASE_REVISION_VERSION_CFG             2


#endif
