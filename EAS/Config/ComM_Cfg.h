/*  BEGIN_FILE_HDR
********************************************************************************
*   File Name       : ComM_Cfg.h
********************************************************************************
*   Project/Product : AUTOSAR BSW PROJECT
*   Title           : ComM module configuration File
*   Author          : Hirain
********************************************************************************
*   Description     : ComM module configuration File
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
#ifndef COMM_CFG_H
#define COMM_CFG_H

/*******************************************************************************
*   Includes
*******************************************************************************/
#include "ComM_Types.h"

/*******************************************************************************
*   Common Macro
*******************************************************************************/
/*The configuration variant and version informations*/
#define COMM_CONFIG_VARIANTS                                STD_CONFIG_VARIANTS_PRECOMPILE


/*******************************************************************************
*   Non Autosar Standard
*******************************************************************************/
/* only used when postbuild is selected  */

/* EAS special */
#define COMM_VERSION_CHECK                                  STD_ON
/* ECUC_ComM_00878 */
#define COMM_USED_PNC_ENABLED                               STD_OFF
#define COMM_DCM_SUPPORT                                    STD_ON
#define COMM_ECUM_SUPPORT                                   STD_ON
#define COMM_NVM_SUPPORT                                    STD_OFF

/*ECUC_ComM_00886*/
#define COMM_PNC_NM_REQUEST                                 STD_OFF
/*NM*/
/*ECUC_ComM_00889*/
#define COMM_NM_PASSIVE_MODE_ENABLED                        STD_OFF
#define COMM_NMVARIANT_ENABLED                              STD_ON
#define COMM_NM_SUPPORT                                     STD_ON
#define COMM_NMVARIANT_FULL_ENABLED                         STD_ON
#define COMM_NMVARIANT_PASSIVE_ENABLED                      STD_OFF
#define COMM_NMVARIANT_LIGHT_ENABLED                        STD_ON
#define COMM_NMVARIANT_NONE_ENABLED                         STD_OFF
/*Bus Type*/
#define COMM_NUM_OF_CAN_CHANNEL                             2
#define COMM_NUM_OF_CDD_CHANNEL                             0
#define COMM_NUM_OF_LIN_CHANNEL                             0
#define COMM_NUM_OF_FR_CHANNEL                              0
#define COMM_NUM_OF_ETH_CHANNEL                             1
#define COMM_NUM_OF_INTERNAL_CHANNEL                        0
#define COMM_NUM_OF_CHANNEL                                 3

#define COMM_NUM_OF_USER                                    1
#define COMM_MAX_USER_MAPPING_CHANNEL                       3
#define COMM_MAX_CHANNEL_MAPPING_USER                       3

/* generate tool's version*/
#define COMM_SW_MAJOR_VERSION_CFG                           1
#define COMM_SW_MINOR_VERSION_CFG                           1
#define COMM_SW_PATCH_VERSION_CFG                           20
#define COMM_AR_RELEASE_MAJOR_VERSION_CFG                   4
#define COMM_AR_RELEASE_MINOR_VERSION_CFG                   2
#define COMM_AR_RELEASE_REVISION_VERSION_CFG                2

/*******************************************************************************
*   ComMGeneral
*******************************************************************************/
/* ECUC_ComM_00560 */
#define COMM_MODE_LIMITATION_ENABLED                        STD_OFF
/* ECUC_ComM_00841 */
#define COMM_T_PNC_PREPARE_SLEEP                            (0)
/* ECUC_ComM_00839 */
#define COMM_PNC_SUPPORT                                    STD_OFF
/* ECUC_ComM_00558 */
#define COMM_RESET_AFTER_FORCING_NOCOMM                     STD_OFF
#define COMM_PNC_GW_ENABLED                                 STD_OFF
/* ECUC_ComM_00695 */
#define COMM_SYNCHRONOUS_WAKE_UP                            STD_OFF
/* ECUC_ComM_00555 */
#define COMM_DEV_ERROR_DETECT                               STD_ON
/* ECUC_ComM_00622 */
#define COMM_VERSION_INFO_API                               STD_ON
/* ECUC_ComM_00559 */
#define COMM_WAKEUP_INHIBITION_ENABLED                      STD_OFF

/*******************************************************************************
*   Access macro
*******************************************************************************/
/*ComM Handle*/
#define ComM_ComM_CanCtrl_0                                 0
#define ComM_ComM_CanCtrl_1                                 1
#define ComM_ComM_EthCtrl                                   2

/*User Handle*/
#define ComM_USERID_User                                    0

#define COMM_INVALID_BUSSM_CHANNEL                          0xff



/*******************************************************************************
*   Config Parameters declear
*******************************************************************************/
#define COMM_START_SEC_CONFIG_DATA_8
#include "MemMap.h"

extern CONST(ComM_InhibitionStatusType, COMM_CONST) ComMEcuGroupClassificationDefault;

/* ECUC_ComM_00568 */
extern CONST(uint8, COMM_CONST) ComMNmVariant[3];

/*ECUC_ComM_00567*/
extern CONST(ComM_BusType, COMM_CONST) ComMBusType[3];

/* ECUC_ComM_00657 ECUC_ComM_00658 */
extern CONST(uint8, COMM_CONST) ComMUserMappingChannelStart[1];
extern CONST(uint8, COMM_CONST) ComMUserMappingChannelNum[1];
extern CONST(NetworkHandleType, COMM_CONST) ComMUserMappingChannel[3];
/* channel mapping to actual user*/
extern CONST(uint8, COMM_CONST) ComMChannelMappingUserStart[3];
extern CONST(uint8, COMM_CONST) ComMChannelMappingUserNum[3];
extern CONST(ComM_UserHandleType, COMM_CONST) ComMChannelMappingUser[3];
/* ECUC_ComM_00556 */
extern CONST(uint8, COMM_CONST) ComMMainFunctionPeriod[3];

extern CONST(NetworkHandleType, COMM_CONST) ComMMappingChannelToBusSM[3];

extern CONST(NetworkHandleType, COMM_CONST) ComMMappingChannelToNm[3];


#define COMM_STOP_SEC_CONFIG_DATA_8
#include "MemMap.h"

#define COMM_START_SEC_CONFIG_DATA_16
#include "MemMap.h"

/* ECUC_ComM_00557 */
extern CONST(uint16, COMM_CONST) ComMTMinFullComModeDuration[3];

/* ECUC_ComM_00606 */
extern CONST(uint16, COMM_CONST) ComMNmLightTimeout[3];

#define COMM_STOP_SEC_CONFIG_DATA_16
#include "MemMap.h"

#define COMM_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "MemMap.h"

extern CONST(ComM_RteSwitchFctPtrType, COMM_CONST) ComM_RteSwitchFunction[COMM_NUM_OF_USER];

#define COMM_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "MemMap.h"
#endif /* COMM_CFG_H */




