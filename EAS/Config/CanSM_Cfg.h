/*  BEGIN_FILE_HDR
********************************************************************************
*   File Name       : CanSM_Cfg.h
********************************************************************************
*   Project/Product : AUTOSAR BSW PROJECT
*   Title           : CanSM module configuration File
*   Author          : Hirain
********************************************************************************
*   Description     : CanSM module configuration File
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
#ifndef CANSM_CFG_H
#define CANSM_CFG_H

/*******************************************************************************
*   General
*******************************************************************************/

#define CANSM_CONFIG_VARIANTS                               STD_CONFIG_VARIANTS_PRECOMPILE

/*ECUC_CanSM_00133*/
#define CANSM_DEV_ERROR_DETECT                              STD_ON
/*ECUC_CanSM_00311*/
#define CANSM_VERSION_INFO_API                              STD_OFF
/*ECUC_CanSM_00312*/
#define CANSM_MAIN_FUNCTION_TIME_PERIOD                     5
#define CANSM_BOR_TX_CONFIRMATION_POLLING                   STD_OFF
/*ECUC_CanSM_00343*/
#define CANSM_SET_BAUDRATE_API                              STD_OFF
/*ECUC_CanSM_00344*/
#define CANSM_PNC_SUPPORT                                   STD_OFF
/*ECUC_CanSM_00345*/
#define CANSM_ICOM_SUPPORT                                  STD_OFF
/*ECUC_CanSM_00349*/
#define CANSM_TXOFFLINEACTIVE_SUPPORT                       STD_OFF

#define CANSM_SW_MAJOR_VERSION_CFG                          1
#define CANSM_SW_MINOR_VERSION_CFG                          1
#define CANSM_SW_PATCH_VERSION_CFG                          17
#define CANSM_AR_RELEASE_MAJOR_VERSION_CFG                  4
#define CANSM_AR_RELEASE_MINOR_VERSION_CFG                  2
#define CANSM_AR_RELEASE_REVISION_VERSION_CFG               2
#define CANSM_PRIVATE_VERSION_CHECK                         STD_ON

/*******************************************************************************
*   EAS Special
*******************************************************************************/
/*user cfg*/
#define CANSM_CANTRCV_SUPPORT                               STD_OFF
#define CANSM_CTRLOPT_SUPPORT                               STD_ON
#define CANSM_COMMNWOPT_SUPPORT                             STD_ON

#define CANSM_NOREQ_IN_WAIT                                 STD_OFF
#define CANSM_LIGHTNM_SUPPORT                               STD_OFF
#define CANSM_BSWM_SUPPORT                                  STD_ON
/*auto get*/
#define CANSM_MAX_NETWORK_NUM                               2
#define CANSM_DEM_SUPPORT                                   STD_ON
#define CANSM_OSEKNM_SUPPORT                                STD_OFF

/*******************************************************************************
*   Access
*******************************************************************************/

#define CANSM_USED_NETWORK_NUM                              2
/*ECUC_CanSM_00335*/
#define CANSM_USED_MAX_REQ_CNT                              1
/*ECUC_CanSM_00336*/
#define CANSM_USED_REQ_DURATION                             2

#define CANSM_CanConfigSet                                  0

#define CanSM_ComM_CanCtrl_0                                0
#define CanSM_ComM_CanCtrl_1                                1

#endif /* CANSM_CFG_H */

