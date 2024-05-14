/*  BEGIN_FILE_HDR
********************************************************************************
*   NOTICE
*   This software is the property of HiRain Technologies. Any information
*   contained in this doc should not be reproduced, or used, or disclosed
*   without the written authorization from HiRain Technologies.
********************************************************************************
*   File Name       : WdgIf.c
********************************************************************************
*   Project/Product : AUTOSAR 4.2
*   Title           : WdgIf module Source File
*   Author          : Hirain
********************************************************************************
*   Description     : WdgIf module Source File
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
*   1.0.0       2017/02/08     Ning.Chen    N/A         Beta
*   1.1.0       2018/04/08     Ning.Chen    N/A         Original
*   1.2.0       2018/11/01     Ning.Chen    N/A         EAS422_WDGIF_20181101_01
********************************************************************************
* END_FILE_HDR*/

/*******************************************************************************
*   Includes
*******************************************************************************/
#include "WdgIf.h"
#if(STD_ON == WDGIF_DEV_ERROR_DETECT)
#include "Det.h"
#endif


/*******************************************************************************
*   Version Check
*******************************************************************************/
/*WDGIF005*/
#if(STD_ON == WDGIF_VERSION_CHECK)
/* check Version with other import module */


/* check Version with cfg file */
#if ((WDGIF_AR_RELEASE_MAJOR_VERSION != WDGIF_AR_RELEASE_MAJOR_VERSION_CFG) || \
   (WDGIF_AR_RELEASE_MINOR_VERSION != WDGIF_AR_RELEASE_MINOR_VERSION_CFG))
#error "AutoSar Version Numbers of WdgIf and its cfg file are different"
#endif

#if ((WDGIF_SW_MAJOR_VERSION != WDGIF_SW_MAJOR_VERSION_CFG) || \
   (WDGIF_SW_MINOR_VERSION != WDGIF_SW_MINOR_VERSION_CFG))
#error "SW Version Numbers of WdgIf and its cfg file are different"
#endif
#endif


/*******************************************************************************
*   Macro
*******************************************************************************/
#if(STD_ON == WDGIF_DEV_ERROR_DETECT)

#define  WDGIF_DET_ERROR_DETECT(cond, ApiId, errcode)  \
    DET_ERROR_DETECT((cond), WDGIF_MODULE_ID, WDGIF_INSTANCE_ID,(ApiId),(errcode))

#define  WDGIF_DET_ERROR_DETECT_RET(cond, ApiId, errcode, ret) \
    DET_ERROR_DETECT_RET((cond), WDGIF_MODULE_ID,WDGIF_INSTANCE_ID,(ApiId),(errcode), (ret))

#define  WDGIF_DET_REPORT_ERROR(ApiId, errcode)  \
    DET_REPORT_ERROR(WDGIF_MODULE_ID, WDGIF_INSTANCE_ID, (ApiId), (errcode))

#else

#define  WDGIF_DET_ERROR_DETECT(cond, ApiId, errcode)
#define  WDGIF_DET_ERROR_DETECT_RET(cond, ApiId, errcode, ret)
#define  WDGIF_DET_REPORT_ERROR(ApiId, errcode)

#endif

/*******************************************************************************
*   PUBLIC Function  Definition
*******************************************************************************/
#define WDGIF_START_SEC_CODE
#include "MemMap.h"

#if(WDGIF_NUMBER_OF_DEVICE > 1)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: WdgIf_SetMode SWS_WdgIf_00042
*
* Description:   This service calls the corresponding WDG Driver service for
*                changing of the MCU controller mode.
*
* Inputs:        DeviceIndex, WdgMode
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, WDGIF_CODE) WdgIf_SetMode
(
    uint8 DeviceIndex,
    WdgIf_ModeType WdgMode
)
{
    Std_ReturnType ret = E_OK;

    if(DeviceIndex >= ((uint8)WDGIF_NUMBER_OF_DEVICE))/*SWS_WdgIf_00028*/
    {
        WDGIF_DET_REPORT_ERROR(WDGIF_SETMODE_APIID, WDGIF_E_PARAM_DEVICE);
        ret = E_NOT_OK;
    }
    else
    {
        if(NULL_PTR != WdgSetModeFctPtrCfg[DeviceIndex])/* SWS_WdgIf_00057*/
        {
            ret = WdgSetModeFctPtrCfg[DeviceIndex](WdgMode);
        }
    }

    return ret;
}



/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: WdgIf_Trigger SWS_WdgIf_00044
*
* Description:   This service calls the corresponding WDG Driver service for
*                changing of the MCU controller mode.
*
* Inputs:        DeviceIndex, WdgMode
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, WDGIF_CODE) WdgIf_SetTriggerCondition
(
    uint8 DeviceIndex,
    uint16 Timeout
)
{
    if(DeviceIndex >= ((uint8)WDGIF_NUMBER_OF_DEVICE))/*SWS_WdgIf_00028*/
    {
        WDGIF_DET_REPORT_ERROR(WDGIF_SETTRIGGER_APIID, WDGIF_E_PARAM_DEVICE);
    }
    else
    {
        if(NULL_PTR != WdgTriggerFctPtrCfg[DeviceIndex])
        {
            WdgTriggerFctPtrCfg[DeviceIndex](Timeout);
        }
    }
}
#endif /* #if(WDGIF_NUMBER_OF_DEVICE > 1) */

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: WdgIf_GetVersionInfo SWS_WdgIf_00046
*
* Description:   Return the version information.
*
* Inputs:        VersionInfoPtr
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
#if(STD_ON ==  WDGIF_VERSION_INFO_API)
FUNC(void, WDGIF_CODE) WdgIf_GetVersionInfo
(
    P2VAR(Std_VersionInfoType, AUTOMATIC, WDGIF_APPL_DATA) VersionInfoPtr
)
{
    if(NULL_PTR == VersionInfoPtr)/*SWS_WdgIf_00058*/
    {
        WDGIF_DET_REPORT_ERROR(WDGIF_GETVERSIONINFO_APIID, WDGIF_E_INV_POINTER);
    }
    else
    {
        /* Copy the vendor Id */
        VersionInfoPtr->vendorID   = WDGIF_VENDOR_ID;
        /* Copy the module Id */
        VersionInfoPtr->moduleID   = WDGIF_MODULE_ID;
        /* Copy Software Major Version */
        VersionInfoPtr->sw_major_version = ((uint8)WDGIF_SW_MAJOR_VERSION);
        /* Copy Software Minor Version */
        VersionInfoPtr->sw_minor_version = ((uint8)WDGIF_SW_MINOR_VERSION);
        /* Copy Software Patch Version */
        VersionInfoPtr->sw_patch_version = ((uint8)WDGIF_SW_PATCH_VERSION);
    }

}
#endif

#define WDGIF_STOP_SEC_CODE
#include "MemMap.h"
