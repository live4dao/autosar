/*  BEGIN_FILE_HDR
********************************************************************************
*   File Name       : DoIP_Lcfg.h
********************************************************************************
*   Project/Product : AUTOSAR BSW PROJECT
*   Title           : DoIP module configuration File
*   Author          : Hirain
********************************************************************************
*   Description     : DoIP module configuration File
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
#ifndef DoIP_LCFG_H
#define DoIP_LCFG_H
/*******************************************************************************
*   Include files
*******************************************************************************/
#include "DoIP_Types.h"

#define DOIP_CHANNEL_3_IFPDU_INDEX 0

#define DOIP_START_SEC_CONFIG_DATA_8
#include "MemMap.h"

extern const uint8 DoIP_EID[6];
#define DOIP_STOP_SEC_CONFIG_DATA_8
#include "MemMap.h"

#define DOIP_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "MemMap.h"

extern const DoIP_ConfigType DoIP_Config;

#define DOIP_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "MemMap.h"




#endif

