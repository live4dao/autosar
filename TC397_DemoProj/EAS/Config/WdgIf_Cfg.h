/*  BEGIN_FILE_HDR
********************************************************************************
*   File Name       : WdgIf_Cfg.h
********************************************************************************
*   Project/Product : AUTOSAR BSW PROJECT
*   Title           : WdgIf module configuration File
*   Author          : Hirain
********************************************************************************
*   Description     : WdgIf module configuration File
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

#ifndef WDGIF_CFG_H
#define WDGIF_CFG_H

/*******************************************************************************
    Includes
*******************************************************************************/
#include "Wdg_17_Scu.h"

/*******************************************************************************
    Macro Definition
*******************************************************************************/
#define WDGIF_DEV_ERROR_DETECT                              STD_ON
#define WDGIF_VERSION_INFO_API                              STD_ON
#define WDGIF_NUMBER_OF_DEVICE                              1
#define WDGIF_VERSION_CHECK                                 STD_ON
#define WDGIF_SW_MAJOR_VERSION_CFG                          1
#define WDGIF_SW_MINOR_VERSION_CFG                          2
#define WDGIF_SW_PATCH_VERSION_CFG                          1
#define WDGIF_AR_RELEASE_MAJOR_VERSION_CFG                  4
#define WDGIF_AR_RELEASE_MINOR_VERSION_CFG                  2
#define WDGIF_AR_RELEASE_REVISION_VERSION_CFG               2
#define WdgIf_Device_Internal                               ((uint8)0)

/*******************************************************************************
    Prototype Definition WDGIF019
*******************************************************************************/
#define WdgIf_SetMode(DeviceIndex, WdgMode) \
    Wdg_17_Scu_SetMode((WdgMode))
#define WdgIf_SetTriggerCondition(DeviceIndex, Timeout) \
    Wdg_17_Scu_SetTriggerCondition((Timeout))

#endif /* #ifndef WDGIF_CFG_H */
