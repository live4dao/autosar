/*  BEGIN_FILE_HDR
********************************************************************************
*   NOTICE
*   This software is the property of HiRain Technologies. Any information
*   contained in this doc should not be reproduced, or used, or disclosed
*   without the written authorization from HiRain Technologies.
********************************************************************************
*   File Name       : Crc_GetVersionInfo.c
********************************************************************************
*   Project/Product : AUTOSAR 4.2.2
*   Title           : Get CRC module Version information
*   Author          : Hirain
********************************************************************************
*   Description     : This service returns the version information of this module.
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
*   01.00.00    18/08/2017    Jingwei.Xi    N/A          Beta
*   01.01.00    13/11/2018    Qiang.Yang    N/A          Original
*   01.01.01    20/11/2018    Qiang.Yang    N/A          EAS422_Crc_20181120_01
*   01.02.00    06/12/2018    Qiang.Yang    N/A          EAS422_Crc_20181206_01
********************************************************************************
* END_FILE_HDR*/


/*******************************************************************************
*   Includes
*******************************************************************************/
#include "Crc.h"
#include "Std_Types.h"
#include "Crc_Version.h"


/*******************************************************************************
*   Version Check
*******************************************************************************/
#if(STD_ON == CRC_PRIVATE_VERSION_CHECK)
/* check Version with other import module */


/* check Version with cfg file */
#if ((CRC_AR_RELEASE_MAJOR_VERSION != CRC_AR_RELEASE_MAJOR_VERSION_CFG) || \
   (CRC_AR_RELEASE_MINOR_VERSION != CRC_AR_RELEASE_MINOR_VERSION_CFG))
#error "AutoSar Version Numbers of CRC and its cfg file are different"
#endif

#if ((CRC_SW_MAJOR_VERSION != CRC_SW_MAJOR_VERSION_CFG) || \
   (CRC_SW_MINOR_VERSION != CRC_SW_MINOR_VERSION_CFG))
#error "SW Version Numbers of CRC and its cfg file are different"
#endif


#endif/*#if(STD_ON == CRC_PRIVATE_AR_VERSION_CHECK)*/

#define CRC_START_SEC_CODE
#include "MemMap.h"

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Crc_GetVersionInfo
*
* Description:   This service returns the version information of this module.
*
*
* Inputs:        None
*
* Outputs:       Versioninfo: Pointer to where to store the version information of this module.
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
/*CRC21,CRC11,CRC17,CRC18*/
FUNC(void, CRC_CODE) Crc_GetVersionInfo
(
    P2VAR(Std_VersionInfoType, AUTOMATIC, CRC_APPL_DATA) Versioninfo
)
{
    if(Versioninfo != NULL_PTR)
    {
        Versioninfo->vendorID = CRC_VENDOR_ID;
        Versioninfo->moduleID = CRC_MODULE_ID;
        Versioninfo->sw_major_version = (uint8)CRC_SW_MAJOR_VERSION;
        Versioninfo->sw_minor_version = (uint8)CRC_SW_MINOR_VERSION;
        Versioninfo->sw_patch_version = (uint8)CRC_SW_PATCH_VERSION;
    }
}

#define CRC_STOP_SEC_CODE
#include "MemMap.h"

