/*  BEGIN_FILE_HDR
********************************************************************************
*   File Name       : Nm_Cfg.h
********************************************************************************
*   Project/Product : AUTOSAR BSW PROJECT
*   Title           : Nm module configuration File
*   Author          : Hirain
********************************************************************************
*   Description     : Nm module configuration File
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

#ifndef NM_CFG_H
#define NM_CFG_H
/*******************************************************************************
*   Includes
*******************************************************************************/
#include "ComStack_Types.h"

/*******************************************************************************
*   Common Macro
*******************************************************************************/
/*The configuration variant and version informations*/
#define NM_CONFIG_VARIANTS                                  STD_CONFIG_VARIANTS_PRECOMPILE


/*******************************************************************************
*   Non Autosar Standard
*******************************************************************************/

/* EAS special */
#define NM_VERSION_CHECK                                    STD_ON

/*Bus Type*/
#define NM_NUM_OF_CANNM_CHANNEL              (1)
#define NM_NUM_OF_OSEKNM_CHANNEL              (0)
#define NM_NUM_OF_CDD_CHANNEL              (0)
#define NM_NUM_OF_LIN_CHANNEL              (0)
#define NM_NUM_OF_FR_CHANNEL               (0)
#define NM_NUM_OF_ETH_CHANNEL              (1)
#define NM_NUM_OF_INTERNAL_CHANNEL         (0)

/* generate tool's version*/
#define NM_SW_MAJOR_VERSION_CFG                             1
#define NM_SW_MINOR_VERSION_CFG                             0
#define NM_SW_PATCH_VERSION_CFG                             10
#define NM_AR_RELEASE_MAJOR_VERSION_CFG                     4
#define NM_AR_RELEASE_MINOR_VERSION_CFG                     2
#define NM_AR_RELEASE_REVISION_VERSION_CFG                  2

/*******************************************************************************
*   NmGlobalConstants
*******************************************************************************/
/*Nm201_Conf*/
#define NM_NUM_OF_CHANNELS           (2) /*sum of above channel numbers*/


/*******************************************************************************
*   NmGlobalProperties
*******************************************************************************/
/*Nm205_Conf*/
#define NM_CYCLETIME_MAINFUNCTION    (10)
/*Nm203_Conf*/
#define NM_DEV_ERROR_DETECT                                 STD_ON
/*Nm204_Conf*/
#define NM_VERSION_INFO_API                                 STD_ON


/*******************************************************************************
*   NmGlobalFeatures
*******************************************************************************/
/*Nm208_Conf*/
#define NM_BUS_SYNC_ENABLED                                 STD_OFF
/*Nm235_Conf*/
#define NM_CAR_WAKEUP_RX_ENABLED                            STD_OFF



/*Nm210_Conf*/
#define NM_COM_CONTROL_ENABLED                              STD_ON
/*Nm230_Conf*/
#define NM_COM_USER_DATA_SUPPORT                            STD_OFF
/*Nm206_Conf*/
#define NM_COORDINATOR_SUPPORT                              STD_OFF
/*Nm237_Conf*/
#define NM_GLOBAL_COORDINATOR_TIME   (10)
/*Nm212_Conf*/
#define NM_NODE_DETECTION_ENABLED                           STD_OFF
/*Nm213_Conf*/
#define NM_NODE_ID_ENABLED                                  STD_ON
/*Nm214_Conf*/
#define NM_PDU_RXINDICATION_ENABLED                         STD_ON
/*Nm207_Conf*/
#define NM_REMOTE_SLEEP_IND_ENABLED                         STD_OFF
/*Nm229_Conf*/
#define NM_REPEAT_MSG_IND_ENABLED                           STD_ON
/*Nm215_Conf*/
#define NM_STATE_CHANGE_IND_ENABLED                         STD_ON
/*Nm211_Conf*/
#define NM_USER_DATA_ENABLED                                STD_ON
/*Nm234_Conf*/
#define NM_STATE_CHANGE_IND_CALLOUT            NmStateChangeIndCallout
#define NM_ComM_CanCtrl_0            (0)
#define NM_ComM_EthCtrl            (1)
#define NM_Nm_CanCtrl_0            (NM_ComM_CanCtrl_0)
#define NM_NmEthCtrl            (NM_ComM_EthCtrl)

#define NM_INVALID_CHANNEL           (NM_NUM_OF_CHANNELS)


#define NM_PASSIVEMODE_VARIES                  (0)
#define NM_PASSIVEMODE_ENABLED_ONLY            (1)
#define NM_PASSIVEMODE_DISABLED_ONLY           (2)

#define NM_PASSIVEMODE                         NM_PASSIVEMODE_DISABLED_ONLY


#endif /* NM_CFG_H */

