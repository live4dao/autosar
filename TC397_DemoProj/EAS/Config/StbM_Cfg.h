/*  BEGIN_FILE_HDR
********************************************************************************
*   File Name       : StbM_Cfg.h
********************************************************************************
*   Project/Product : AUTOSAR BSW PROJECT
*   Title           : StbM module configuration File
*   Author          : Hirain
********************************************************************************
*   Description     : StbM module configuration File
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




#ifndef STBM_CFG_H
#define STBM_CFG_H

/*******************************************************************************
*   Includes
*******************************************************************************/
#include "ComStack_Types.h"

/*******************************************************************************
*   Common Macro
*******************************************************************************/
/*The configuration variant and version informations*/
#define STBM_CONFIG_VARIANTS                               STD_CONFIG_VARIANTS_PRECOMPILE
/* generate tool's version*/
#define STBM_SW_MAJOR_VERSION_CFG                          1
#define STBM_SW_MINOR_VERSION_CFG                          1
#define STBM_SW_PATCH_VERSION_CFG                          7
#define STBM_AR_RELEASE_MAJOR_VERSION_CFG                  4
#define STBM_AR_RELEASE_MINOR_VERSION_CFG                  2
#define STBM_AR_RELEASE_REVISION_VERSION_CFG               2

/*******************************************************************************
*   StbMGeneral ECUC_StbM_00002
*******************************************************************************/
/*ECUC_StbM_00012 StbMDevErrorDetect*/
#define STBM_DEV_ERROR_DETECT                              STD_ON
/*ECUC_StbM_00032 StbMGetCurrentTimeExtendedAvailable*/
#define STBM_GETCURRENTTIMEEXTENDED_AVAILABLE              STD_ON
/*ECUC_StbM_00027 StbMMainFunctionPeriod*/
#define STBM_MAIN_FUNCTION_PERIOD                          (5U)
/*ECUC_StbM_00013 StbMVersionInfo*/
#define STBM_VERSION_INFO_API                              STD_ON


#define STBM_VERSION_CHECK                                 STD_ON

#define STBM_NONVOLATILE_SUPPORT                           STD_ON
#define STBM_ETH_GLOBALTIME_USED                           STD_OFF
#define STBM_OFFSETTIMEBASE_USED                           STD_OFF
#define StbM_OS_ENABLED                                    STD_ON

#define STBM_RAW_COUNTER_REF                                0
#define STBM_RAW_TICK_TO_NS_FACTOR                          1000000
#define STBM_RAW_TICK_MAX_VALUE                             65535
#define STBM_RAW_OS_COUNTER_SUPPORT                         STD_ON
#define STBM_RAW_USER_COUNTER_SUPPORT                       STD_OFF
#define STBM_OS_GLOBALTIME_USED                             STD_ON
#define STBM_USERDEFCNT_USED                                STD_OFF

/*define the Time Base Identifier*/
#define STBM_NUM_OF_TIMEBASE                               1


#define STBM_TBID_StbMSynchronizedTimeBase                  0
/*define the Triggered Customer*/
#define STBM_NUM_OF_TRIGGEREDCUSTOMER                      0


#endif /*STBM_CFG_H*/





