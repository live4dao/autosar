/*  BEGIN_FILE_HDR
********************************************************************************
*   NOTICE
*   This software is the property of HiRain Technologies. Any information
*   contained in this doc should not be reproduced, or used, or disclosed
*   without the written authorization from HiRain Technologies.
********************************************************************************
*   File Name       : Det.c
********************************************************************************
*   Project/Product : AUTOSAR 4.2
*   Title           : Default Error Tracer Source File
*   Author          : Hirain
********************************************************************************
*   Description     : Implementation of Default Error Tracer   .
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
*   01.00.00    06/09/2016    Ning.Chen     N/A          Beta
*   01.01.00    26/06/2018    Boxue.Li      N/A          Original
*   01.02.00    01/11/2018    Boxue.Li      N/A          EAS422_DET_20181101_01
*   01.02.01    07/22/2022    ziyi.zhao     QAC          EAS422_DET_20220722_01
*   01.02.02    02/11/2022    Ning.Chen     N/A          EAS422_DET_20221102_01
********************************************************************************
* END_FILE_HDR*/

/*******************************************************************************
*   Includes
*******************************************************************************/
#include "Det.h"

#include "SchM_Det.h" /*SWS_Det_00033*/
#if(STD_ON == DET_FORWARD_TO_DLT)
#include "Dlt.h" /*SWS_Det_00042*/
#endif

/*******************************************************************************
*  General QAC Suppression
*******************************************************************************/
/*PRQA S 3614,3214,0862 EOF*/
/*
According to the requirements of AUTOSAR Specification,when locating address 
segments in the files of each module,#include "MemMap.h" is required.Defined 
XXX_START_SEC_ will undefine in MemMap.h
*/

/*PRQA S 3119 EOF*/
/*
No unified input parameter processing is used
*/

/*PRQA S 3432 EOF*/
/*
P2VAR and other macros in the Compiler conforms to AUTOSAR standard.There's no 
need to revise.
*/

/*******************************************************************************
*   Version Check
*******************************************************************************/
/*CANIF021  CANIF728*/
#if(STD_ON == DET_VERSION_CHECK)
/* check Version with other import module */


/* check Version with cfg file */
#if ((DET_AR_RELEASE_MAJOR_VERSION != DET_AR_RELEASE_MAJOR_VERSION_CFG) || \
   (DET_AR_RELEASE_MINOR_VERSION != DET_AR_RELEASE_MINOR_VERSION_CFG))
#error "AutoSar Version Numbers of Det and its cfg file are different"
#endif

#if ((DET_SW_MAJOR_VERSION != DET_SW_MAJOR_VERSION_CFG) || \
   (DET_SW_MINOR_VERSION != DET_SW_MINOR_VERSION_CFG))
#error "SW Version Numbers of Det and its cfg file are different"
#endif

#endif/*#if(STD_ON == DET_VERSION_CHECK)*/

#define DET_START_SEC_VAR_INIT_8
#include "MemMap.h"

/*used for DET */
STATIC VAR(Std_InitStateType, DET_VAR)  Det_InitStatus = STD_UNINITIALIZED;

#define DET_STOP_SEC_VAR_INIT_8
#include "MemMap.h"


/* Det_Error is only used for debug
   User must turn it off when debug is finish
*/
#if(STD_ON == DET_DEBUG)
STATIC VAR(uint16, DET_VAR_NOINIT)  Det_ModuleId;
STATIC VAR(uint8, DET_VAR_NOINIT)  Det_InstanceId;
STATIC VAR(uint8, DET_VAR_NOINIT)  Det_ApiId;
STATIC VAR(uint8, DET_VAR_NOINIT)  Det_ErrorId;
#endif

#define DET_START_SEC_CODE
#include "MemMap.h"/*SWS_Det_00006*/

/*******************************************************************************
*   Global Function Define
*******************************************************************************/
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Det_Init  SWS_Det_00008  SWS_Det_00019
*
* Description:   Service to initialize the Default Error Tracer..
*
* Inputs:        ConfigPtr Pointer to the selected configuration set
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, DET_CODE) Det_Init
(
    P2CONST(Det_ConfigType, AUTOMATIC, DET_CONST) ConfigPtr
)
{
    /*SWS_Det_00070*/
    (void)ConfigPtr;
    Det_InitStatus = STD_INITIALIZED;/*SWS_Det_00020*/
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Det_Start  SWS_Det_00010 SWS_Det_00025
*
* Description:   Service to start the Development Error Tracer.
*
* Inputs:        None
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, DET_CODE) Det_Start(void)
{
    /*empty funtion*/
}



/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Det_ReportError  SWS_Det_00009 SWS_Det_00013 SWS_Det_00061
*
* Description:   Service to report development errors.
*
* Inputs:        ModuleId InstanceId ApiId ErrorId
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/

FUNC(Std_ReturnType, DET_CODE) Det_ReportError
(
    uint16 ModuleId,
    uint8 InstanceId,
    uint8 ApiId,
    uint8 ErrorId
)
{
    if(STD_UNINITIALIZED != Det_InitStatus)/*SWS_Det_00024*/
    {
#ifdef DET_ERROR_HOOK
        DET_ERROR_HOOK;/*SWS_Det_00027 SWS_Det_00052*//*SWS_Det_00035 SWS_Det_00014 SWS_Det_00018 SWS_Det_00017*/
#endif


#if(STD_ON == DET_FORWARD_TO_DLT)
        Dlt_DetForwardErrorTrace(ModuleId, InstanceId, ApiId, ErrorId);
#endif

#if(STD_ON == DET_DEBUG)
        Det_ModuleId = ModuleId;
        Det_InstanceId = InstanceId;
        Det_ApiId = ApiId;
        Det_ErrorId = ErrorId;
#endif

#if(STD_ON == DET_ERROR_LOOP)/*SWS_Det_00015*/
        for(;;)
        {
            /* loop forever */
        }
#endif
    }

    return E_OK;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Det_ReportRuntimeError  SWS_Det_01001 SWS_Det_00013 SWS_Det_00062
*
* Description:   Service to report runtime errors.
*
* Inputs:        ModuleId InstanceId ApiId ErrorId
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/

FUNC(Std_ReturnType, DET_CODE) Det_ReportRuntimeError
(
    uint16 ModuleId,
    uint8 InstanceId,
    uint8 ApiId,
    uint8 ErrorId
)
{
    if(STD_UNINITIALIZED != Det_InitStatus)/*SWS_Det_00024*/
    {
#ifdef DET_RUNTIME_ERROR_HOOK
        DET_RUNTIME_ERROR_HOOK;/*SWS_Det_00027 SWS_Det_00052*//*SWS_Det_00035 SWS_Det_00014 SWS_Det_00018 SWS_Det_00017*/
#endif


#if(STD_ON == DET_FORWARD_TO_DLT)
        Dlt_DetForwardErrorTrace(ModuleId, InstanceId, ApiId, ErrorId);
#endif

#if(STD_ON == DET_DEBUG)
        Det_ModuleId = ModuleId;
        Det_InstanceId = InstanceId;
        Det_ApiId = ApiId;
        Det_ErrorId = ErrorId;
#endif

#if(STD_ON == DET_ERROR_LOOP)/*SWS_Det_00015*/
        for(;;)
        {
            /* loop forever */
        }
#endif
    }

    return E_OK;
}


/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Det_ReportTransientError  SWS_Det_01003 SWS_Det_00013 SWS_Det_00063
*
* Description:   Service to report transient faults.
*
* Inputs:        ModuleId InstanceId ApiId ErrorId
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/

FUNC(Std_ReturnType, DET_CODE) Det_ReportTransientError
(
    uint16 ModuleId,
    uint8 InstanceId,
    uint8 ApiId,
    uint8 FaultId
)
{
    if(STD_UNINITIALIZED != Det_InitStatus)/*SWS_Det_00024*/
    {
#ifdef DET_TRANSIENT_ERROR_HOOK
        DET_TRANSIENT_ERROR_HOOK;/*SWS_Det_00027 SWS_Det_00052*//*SWS_Det_00035 SWS_Det_00014 SWS_Det_00018 SWS_Det_00017*/
#endif


#if(STD_ON == DET_FORWARD_TO_DLT)
        Dlt_DetForwardErrorTrace(ModuleId, InstanceId, ApiId, FaultId);
#endif

#if(STD_ON == DET_DEBUG)
        Det_ModuleId = ModuleId;
        Det_InstanceId = InstanceId;
        Det_ApiId = ApiId;
        Det_ErrorId = FaultId;
#endif

#if(STD_ON == DET_ERROR_LOOP)/*SWS_Det_00015*/
        for(;;)
        {
            /* loop forever */
        }
#endif
    }

    return E_OK;
}


/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Det_GetVersionInfo  SWS_Det_00011  SWS_Det_00022 SWS_Det_00012
*
* Description:   Returns the version information of this module.
*
* Inputs:        VersionInfo Pointer to where to store the version information of this module
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
#if(STD_ON == DET_VERSION_INFO_API)/*SWS_Det_00028*/
FUNC(void, DET_CODE) Det_GetVersionInfo
(
    P2VAR(Std_VersionInfoType, AUTOMATIC, DET_APPL_DATA) VersionInfo
)
{

    if(NULL_PTR == VersionInfo)
    {
        (void)Det_ReportError(DET_MODULE_ID, DET_INSTANCE_ID, DET_GETVERSION_APIID, DET_E_PARAM_POINTER);
        /*SWS_Det_00023 SWS_Det_00051*/
    }
    else
    {
        VersionInfo->vendorID = DET_VENDOR_ID;
        VersionInfo->moduleID = DET_MODULE_ID;

        VersionInfo->sw_major_version = (uint8)DET_SW_MAJOR_VERSION;
        VersionInfo->sw_minor_version = (uint8)DET_SW_MINOR_VERSION;
        VersionInfo->sw_patch_version = (uint8)DET_SW_PATCH_VERSION;
    }

}
#endif


#define DET_STOP_SEC_CODE
#include "MemMap.h"


