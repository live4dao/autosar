/*  BEGIN_FILE_HDR
********************************************************************************
*   File Name       : WdgM_Cfg.h
********************************************************************************
*   Project/Product : AUTOSAR BSW PROJECT
*   Title           : WdgM module configuration File
*   Author          : Hirain
********************************************************************************
*   Description     : WdgM module configuration File
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
#ifndef WDGM_CFG_H
#define WDGM_CFG_H
/*******************************************************************************
*   Include
*******************************************************************************/
/*******************************************************************************
*   General
*******************************************************************************/
#define WDGM_CONFIG_VARIANTS                                STD_CONFIG_VARIANTS_PRECOMPILE
#define WDGM_DEM_ALIVE_SUPERVISION_REPORT                   STD_OFF
#define WDGM_DEV_ERROR_DETECT                               STD_ON
#define WDGM_IMMEDIATE_RESET                                STD_OFF
#define WDGM_OFF_MODE_ENABLED                               STD_OFF
#define WDGM_VERSION_INFO_API                               STD_ON
#define WDGM_PRIVATE_VERSION_CHECK                          STD_ON
#define WdgM_GetElapsedValue                                GetElapsedValue

#define WDGM_BSWM_USED                                      STD_OFF
#define WDGM_OS_USED                                        STD_OFF
#define WDGM_DEM_USED                                       STD_OFF

#define WDGM_SW_MAJOR_VERSION_CFG                           1
#define WDGM_SW_MINOR_VERSION_CFG                           2
#define WDGM_SW_PATCH_VERSION_CFG                           10
#define WDGM_AR_RELEASE_MAJOR_VERSION_CFG                   4
#define WDGM_AR_RELEASE_MINOR_VERSION_CFG                   2
#define WDGM_AR_RELEASE_REVISION_VERSION_CFG                2

#define WDGM_TOTAL_FLOW_NUM                                 0
#define WDGM_TOTAL_ALIVE_NUM                                2
#define WDGM_TOTAL_DEADLINE_NUM                             0
/*******************************************************************************
*   Handles
*******************************************************************************/
#define WDGM_WdgMConfigSet                                  ((uint8)0)

#define WDGM_SE_WdgMSupervisedEntity_SE0                    ((WdgM_SupervisedEntityIdType)0)

#define WDGM_CP_WdgMSupervisedEntity_SE0_CP0_Bsw_5ms        ((WdgM_CheckpointIdType)0)
#define WDGM_CP_WdgMSupervisedEntity_SE0_CP1_App_10ms       ((WdgM_CheckpointIdType)1)

#define WDGM_MODE_WdgMConfigSet_WdgMMode0                   ((uint8)0)
/*******************************************************************************
*   Access macro
*******************************************************************************/
#define WDGM_TOTAL_SE_NUM                                   ((WdgM_SupervisedEntityIdType)1)
#define WDGM_TOTAL_CP_NUM                                   ((WdgM_SupervisedEntityIdType)2)
#define WDGM_WDG_DEVICE_NUM                                 (1)
#define WDGM_USED_FLOW_NUM                                  ((uint16)0)
#define WDGM_USED_ALIVE_NUM                                 ((uint16)2)
#define WDGM_USED_DEADLINE_NUM                              ((uint16)0)

#endif /* WDGM_CFG_H */


