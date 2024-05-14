/*  BEGIN_FILE_HDR
********************************************************************************
*   NOTICE
*   This software is the property of HiRain Technologies. Any information
*   contained in this doc should not be reproduced, or used, or disclosed
*   without the written authorization from HiRain Technologies.
********************************************************************************
*   File Name       : Xcp.c
********************************************************************************
*   Project/Product : AUTOSAR 4.2
*   Title           : Xcp module source File
*   Author          : Hirain
********************************************************************************
*   Description     : Implementation of Xcp provided functionality
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
*   01.00.00    18/01/2017    Ning.Chen     N/A          Original
*   01.00.01    14/10/2020    Ning.Chen     N/A          EAS422_XCP_20201014_01
*   01.00.02    20/01/2021    Xin.Yang1     N/A          EAS422_XCP_20210120_01
*   01.00.03    01/02/2021    Xin.Yang1     N/A          EAS422_XCP_20210201_01
*   01.00.04    08/02/2021    Xin.Yang1     N/A          EAS422_XCP_20210208_01
********************************************************************************

* END_FILE_HDR*/
/*******************************************************************************
*   Includes
*******************************************************************************/
#include "Xcp.h"

/*******************************************************************************
*   Version Check
*******************************************************************************/
#if(STD_ON == XCP_VERSION_CHECK)
/* check Version with other import module */


/* check Version with cfg file */
#if ((XCP_AR_RELEASE_MAJOR_VERSION != XCP_AR_RELEASE_MAJOR_VERSION_CFG) || \
   (XCP_AR_RELEASE_MINOR_VERSION != XCP_AR_RELEASE_MINOR_VERSION_CFG))
#error "AutoSar Version Numbers of Xcp and its cfg file are different"
#endif

#if ((XCP_SW_MAJOR_VERSION != XCP_SW_MAJOR_VERSION_CFG) || \
   (XCP_SW_MINOR_VERSION != XCP_SW_MINOR_VERSION_CFG))
#error "SW Version Numbers of Xcp  and its cfg file are different"
#endif

#endif

/*******************************************************************************
*   local Data Define
*******************************************************************************/
#define XCP_START_SEC_VAR_INIT_8
#include "MemMap.h"
VAR (Std_InitStateType, XCP_VAR) Xcp_State = STD_UNINITIALIZED;
#define XCP_STOP_SEC_VAR_INIT_8
#include "MemMap.h"

#define XCP_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h"

P2CONST (Xcp_ConfigType, AUTOMATIC, XCP_CONST) XcpConfigInfoPtr;

#define XCP_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h"


/*******************************************************************************
*   Global Function Define
*******************************************************************************/
#define XCP_START_SEC_CODE
#include "MemMap.h"

#if(STD_ON == XCP_VERSION_INFO_API)/*Xcp809*/
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name : Xcp_GetVersionInfo Xcp807
*
* Description   : Returns the version information of this module.
*
* Inputs        : versioninfo:a pointer to where to store the version information of this module.

* Outputs       : None
*
* Limitations   : None
********************************************************************************
END_FUNCTION_HDR */
FUNC(void, XCP_CODE) Xcp_GetVersionInfo
(
    P2VAR (Std_VersionInfoType, AUTOMATIC, XCP_APPL_DATA) versioninfo
)
{
    if (NULL_PTR == versioninfo)
    {
        /* XCP_E_INV_POINTER Xcp825*/
        XCP_DET_REPORT_ERROR (XCP_GETVERSION_APIID, XCP_E_INV_POINTER);
    }
    else
    {
        /*Xcp808*/
        versioninfo->vendorID = XCP_VENDOR_ID;
        versioninfo->moduleID = XCP_MODULE_ID;
        versioninfo->sw_major_version = XCP_SW_MAJOR_VERSION;
        versioninfo->sw_minor_version = XCP_SW_MINOR_VERSION;
        versioninfo->sw_patch_version = XCP_SW_PATCH_VERSION;
    }

}
#endif



/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name : Xcp_Init Xcp803
*
* Description   : This service initializes interfaces and variables of the AUTOSAR XCP layer.
*
* Inputs        : Xcp_ConfigPtr:a pointer to a selected configuration structure

* Outputs       : None
*
* Limitations   : None
********************************************************************************
END_FUNCTION_HDR */
FUNC(void, XCP_CODE) Xcp_Init
(
    P2CONST (Xcp_ConfigType, AUTOMATIC, XCP_CONST) Xcp_ConfigPtr
)
{
#if(STD_CONFIG_VARIANTS_POSTBUILD == XCP_CONFIG_VARIANTS)

    if (NULL_PTR == Xcp_ConfigPtr) /*Xcp834*/
    {
        XCP_DET_REPORT_ERROR (XCP_INIT_APIID, XCP_E_INV_POINTER);
    }
    else
#endif
    {
        /*Xcp802*/
        Xcp_State = STD_INITIALIZED;
#if(STD_CONFIG_VARIANTS_POSTBUILD == XCP_CONFIG_VARIANTS)
        XcpConfigInfoPtr = Xcp_ConfigPtr;
#else
        (void) Xcp_ConfigPtr;
        XcpConfigInfoPtr = &Xcp_Config[0];
#endif
        Xcp_ProcessInit();

    }
}


/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name : Xcp_MainFunction Xcp824 Xcp823
*
* Description   : Scheduled function of the XCP module
*
* Inputs        : None

* Outputs       : None
*
* Limitations   : None
********************************************************************************
END_FUNCTION_HDR */
FUNC(void, XCP_CODE) Xcp_MainFunction (void)
{
    if (STD_INITIALIZED == Xcp_State)
    {
        Xcp_InternalProcessing();
    }
    else
    {
        XCP_DET_REPORT_ERROR (XCP_MAIN_APIID, XCP_E_NOT_INITIALIZED);
    }

}



#define XCP_STOP_SEC_CODE
#include "MemMap.h"

