
/*  BEGIN_FILE_HDR
********************************************************************************
*   File Name       : FiM_Cfg.h
********************************************************************************
*   Project/Product : AUTOSAR BSW PROJECT
*   Title           : FiM module configuration File
*   Author          : Hirain
********************************************************************************
*   Description     : FiM module configuration File
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
#ifndef FIM_CFG_H
#define FIM_CFG_H


/*******************************************************************************
*   Macro
*******************************************************************************/
#define FIM_CONFIG_VARIANTS                                 STD_CONFIG_VARIANTS_PRECOMPILE
#define FIM_AVAILABILITY_SUPPORT                            STD_OFF
#define FIM_DEV_ERROR_DETECT                                STD_OFF
#define FIM_EVENT_UPDATE_TRIGGERED_BY_DEM                   STD_ON
#define FIM_VERSION_INFO_API                                STD_ON
#define FIM_DEM_COMPONENT_SUPPORT                           STD_OFF
#define FIM_QUARY_MODE                                      FIM_CYCLICALLY

#define FIM_FUNCTION_NUM_CFG                                ((uint16)1)
#define FIM_FUNCTION_ID_MAX                                 ((FiM_FunctionIdType)0)
#define FIM_FUNCTION_ID_MIN                                 ((FiM_FunctionIdType)0)
#define FIM_EVENT_NUM_CFG                                   ((uint16)1)
#define FIM_EVENT_ID_MAX                                    ((Dem_EventIdType)0)
#define FIM_EVENT_ID_MIN                                    ((Dem_EventIdType)0)
#define FIM_COMPONENT_NUM_CFG                               ((uint16)0)
#define FIM_COMPONENT_ID_MAX                                ((Dem_ComponentIdType)0)
#define FIM_COMPONENT_ID_MIN                                ((Dem_ComponentIdType)0)
#define FiM_FiMFID                                          ((FiM_FunctionIdType)0)


/*version check*/
#define FIM_PRIVATE_VERSION_CHECK                           STD_ON
#define FIM_SW_MAJOR_VERSION_CFG                            1
#define FIM_SW_MINOR_VERSION_CFG                            0
#define FIM_SW_PATCH_VERSION_CFG                            11
#define FIM_AR_RELEASE_MAJOR_VERSION_CFG                    4
#define FIM_AR_RELEASE_MINOR_VERSION_CFG                    2
#define FIM_AR_RELEASE_REVISION_VERSION_CFG                 2

#endif /*FIM_CFG_H*/
