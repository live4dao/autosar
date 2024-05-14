/*  BEGIN_FILE_HDR
********************************************************************************
*   File Name       : Det_Cfg.h
********************************************************************************
*   Project/Product : AUTOSAR BSW PROJECT
*   Title           : Det module configuration File
*   Author          : Hirain
********************************************************************************
*   Description     : Det module configuration File
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
#ifndef DET_CFG_H
#define DET_CFG_H
/*******************************************************************************
*   Include
*******************************************************************************/
/*******************************************************************************
*   General
*******************************************************************************/
/*The configuration variant and version informations*/
#define DET_CONFIG_VARIANTS                                 STD_CONFIG_VARIANTS_PRECOMPILE
#define DET_VERSION_CHECK                                   STD_ON
#define DET_VERSION_INFO_API                                STD_OFF
#define DET_ERROR_LOOP                                      STD_OFF
#define DET_FORWARD_TO_DLT                                  STD_OFF
#define DET_DEBUG                                           STD_OFF
#define DET_RUNTIME_ERROR_HOOK
#define DET_TRANSIENT_ERROR_HOOK

#define DET_SW_MAJOR_VERSION_CFG                            1
#define DET_SW_MINOR_VERSION_CFG                            2
#define DET_SW_PATCH_VERSION_CFG                            3
#define DET_AR_RELEASE_MAJOR_VERSION_CFG                    4
#define DET_AR_RELEASE_MINOR_VERSION_CFG                    2
#define DET_AR_RELEASE_REVISION_VERSION_CFG                 2

#endif /* DET_CFG_H */
