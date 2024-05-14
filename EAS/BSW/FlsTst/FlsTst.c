/*  BEGIN_FILE_HDR
********************************************************************************
*   NOTICE
*   This software is the property of HiRain Technologies. Any information
*   contained in this doc should not be reproduced, or used, or disclosed
*   without the written authorization from HiRain Technologies.
********************************************************************************
*   File Name       : FlsTst.c
********************************************************************************
*   Project/Product : AUTOSAR 4.2
*   Title           : FlsTst.c
*   Author          : HiRain
********************************************************************************
*   Description     : Source of AUTOSAR Flash Test Module
*
********************************************************************************
*   Limitations     :
*
********************************************************************************
*
********************************************************************************
*   Revision History:
*
*   Version     Date          Initials      CR#          Descriptions
*   ---------   ----------    ------------  ----------   ---------------
*   01.00.00    24/10/2017    Jiemin.Chen   N/A          Beta
*   01.01.00    24/04/2018    Ning.Nhen     N/A          Original
*   01.02.00    06/11/2018    Ning.Nhen     N/A          EAS422_FLSTST_20181106_01
********************************************************************************
* END_FILE_HDR*/


/*******************************************************************************
*   Includes
*******************************************************************************/
#include "FlsTst.h"
#include "FlsTst_Callout.h"
#if (FLSTST_DEV_ERROR_DETECT == STD_ON)
#include "Det.h"
#endif

#if (FLSTST_DEM_SUPPORT == STD_ON)
#include "Dem.h"
#endif
#include "SchM_FlsTst.h"



/*******************************************************************************
*   Version Check
*******************************************************************************/
#if(STD_ON == FLSTST_PRIVATE_VERSION_CHECK)
/* check Version with other import module */


/* check Version with cfg file */
#if ((FLSTST_AR_RELEASE_MAJOR_VERSION != FLSTST_AR_RELEASE_MAJOR_VERSION_CFG) || \
   (FLSTST_AR_RELEASE_MINOR_VERSION != FLSTST_AR_RELEASE_MINOR_VERSION_CFG))
#error "AutoSar Version Numbers of FlsTst and its cfg file are different"
#endif

#if ((FLSTST_SW_MAJOR_VERSION != FLSTST_SW_MAJOR_VERSION_CFG) || \
   (FLSTST_SW_MINOR_VERSION != FLSTST_SW_MINOR_VERSION_CFG))
#error "SW Version Numbers of FlsTst and its cfg file are different"
#endif

#endif/*#if(STD_ON == FLSTST_PRIVATE_VERSION_CHECK)*/


/*******************************************************************************
*   Det Report
*******************************************************************************/
#if (FLSTST_DEV_ERROR_DETECT == STD_ON)
#define FLSTST_ERROR_DETECT(cond,apiCode,errCode)   DET_ERROR_DETECT((cond), FLSTST_MODULE_ID, FLSTST_INSTANCE_ID,(apiCode),(errCode))

#define FLSTST_ERROR_DETECT_RET(cond,apiCode,errCode,ret)     DET_ERROR_DETECT_RET((cond), FLSTST_MODULE_ID,FLSTST_INSTANCE_ID,(apiCode),(errCode), (ret))

#define FLSTST_DEVERR_DETECT(api,err)    DET_REPORT_ERROR(FLSTST_MODULE_ID, FLSTST_INSTANCE_ID, (api), (err)) 
#else
#define FLSTST_ERROR_DETECT(cond,apiCode,errCode)
#define FLSTST_ERROR_DETECT_RET(cond,apiCode,errCode,ret)
#define FLSTST_DEVERR_DETECT(apiCode,errCode)
#endif


#if(FLSTST_DEM_SUPPORT == STD_ON)
#define FLSTST_DEM_REPORT(State)  Dem_ReportErrorStatus(FLSTST_E_FLSTST_FAILURE, (State))
#else
#define FLSTST_DEM_REPORT(State)
#endif



/*******************************************************************************
*   TypeDef
*******************************************************************************/


#define FLSTST_START_SEC_VAR_INIT_8
#include "MemMap.h"
STATIC VAR(FlsTst_StateType, FLSTST_VAR) FlsTstState = FLSTST_UNINIT;
#define FLSTST_STOP_SEC_VAR_INIT_8
#include "MemMap.h"


#define FLSTST_START_SEC_VAR_NOINIT_8
#include "MemMap.h"

/*Fgnd*/
STATIC VAR(FlsTst_TestResultFgndType, FLSTST_VAR_NOINIT)  FlsTstFgndTestReslut;
/*Bgnd*/
STATIC VAR(FlsTst_TestResultType, FLSTST_VAR_NOINIT)  FlsTstBgndTestReslut;

STATIC VAR(FlsTst_StateType, FLSTST_VAR_NOINIT) FlsTstStateBackUp;

#define FLSTST_STOP_SEC_VAR_NOINIT_8
#include "MemMap.h"


#define FLSTST_START_SEC_VAR_NOINIT_32
#include "MemMap.h"

STATIC VAR(FlsTst_IntervalIdType, FLSTST_VAR_NOINIT)  FlsTstBgndTestIntervalId;
STATIC VAR(FlsTst_SignatureType, FLSTST_VAR_NOINIT)   FlsTstBgndTestSignature;
STATIC VAR(FlsTst_BlockIdBgndType, FLSTST_VAR_NOINIT) FlsTstBgndErrBlockCnt;
STATIC VAR(FlsTst_BlockIdBgndType, FLSTST_VAR_NOINIT) FlsTstBgndErrBlockId;



#define FLSTST_STOP_SEC_VAR_NOINIT_32
#include "MemMap.h"


#define FLSTST_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h"
STATIC P2CONST(FlsTst_ConfigType, FLSTST_VAR_NOINIT, FLSTST_CONST) FlsTstConfigPtr;
STATIC VAR(FlsTst_TestContextType, FLSTST_VAR_NOINIT)  FlsTstBgndTestContext;
STATIC VAR(FlsTst_ErrorDetailsType, FLSTST_VAR_NOINIT)  FlsTstErrorDetails;

/*Fgnd*/
STATIC VAR(FlsTst_TestSignatureFgndType, FLSTST_VAR_NOINIT)  FlsTstFgndSignature;
#define FLSTST_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h"


/*******************************************************************************
*   Code
*******************************************************************************/

#define FLSTST_START_SEC_CODE
#include "MemMap.h"

STATIC FUNC(void, FLSTST_CODE) FlsTst__InitTestContext
(
    FlsTst_BlockIdBgndType BlockId
);


STATIC FUNC(Std_ReturnType, FLSTST_CODE) FlsTst__CheckBlockSignature
(
    FlsTst_SignatureType sig,
    boolean isBgnd,
    uint32 BlockId
);


STATIC FUNC(void, FLSTST_CODE) FlsTst__GetBlockSignature
(
    void
);


STATIC FUNC(void, FLSTST_CODE) FlsTst__TestBgndBlock(void);

STATIC FUNC(void, FLSTST_CODE) FlsTst__InternalInit(void);


/*******************************************************************************
*   Public API
*******************************************************************************/


/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name : FlsTst__InternalInit
*
* Description   : Init funtion of FlsTst
*
* Inputs        : ConfigPtr
*
* Outputs       : None
*
* Limitations   : None
********************************************************************************
END_FUNCTION_HDR */
STATIC FUNC(void, FLSTST_CODE) FlsTst__InternalInit(void)
{
    /* Bgnd */
    FlsTstBgndTestIntervalId = (FlsTst_IntervalIdType)0;
    FlsTstBgndTestSignature = (FlsTst_SignatureType)0;

    FlsTstBgndTestContext.First = FALSE;
    FlsTstBgndTestContext.Address = (uint32)0;
    FlsTstBgndTestContext.RemainSize = (uint32)0;
    FlsTstBgndTestContext.Signature = (FlsTst_SignatureType)0;
    FlsTstBgndTestContext.BlockIndex = (FlsTst_BlockIdBgndType)0;

    FlsTstBgndTestReslut = FLSTST_RESULT_NOT_TESTED;

    FlsTstErrorDetails.ErrBgndBlockId = FLSTST_INVALID_BLOCKID;
    FlsTstErrorDetails.ErrBgndIntervalId = (FlsTst_IntervalIdType)0;
    FlsTstErrorDetails.ErrBgndCnt = (FlsTst_BlockIdBgndType)0;
    FlsTstBgndErrBlockCnt = (FlsTst_BlockIdBgndType)0;
    FlsTstBgndErrBlockId = FLSTST_INVALID_BLOCKID;


    /* Fgnd*/
    FlsTstFgndTestReslut = FLSTST_NOT_TESTED;
    FlsTstFgndSignature.FgndBlockId = FLSTST_INVALID_BLOCKID;
    FlsTstFgndSignature.Signature = (FlsTst_SignatureType)0;
    FlsTstErrorDetails.ErrFgndBlockId = FLSTST_INVALID_BLOCKID;

    FlsTstStateBackUp = FLSTST_UNINIT;

}





/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name : FlsTst_Init     SWS_FlsTst_00017
*
* Description   : Init funtion of FlsTst
*
* Inputs        : ConfigPtr
*
* Outputs       : None
*
* Limitations   : None
********************************************************************************
END_FUNCTION_HDR */
FUNC(void, FLSTST_CODE) FlsTst_Init
(
    P2CONST(FlsTst_ConfigType, AUTOMATIC, AUTOMATIC) ConfigPtr
)
{
    if(FlsTstState != FLSTST_UNINIT) /*SWS_FlsTst_00025*/
    {
        FLSTST_DEVERR_DETECT(FLSTST_INIT_API_ID, FLSTST_E_ALREADY_INITIALIZED);
    }
#if(STD_CONFIG_VARIANTS_POSTBUILD == FLSTST_CONFIG_VARIANTS)
    else if(NULL_PTR == ConfigPtr)
    {
        FLSTST_DEVERR_DETECT(FLSTST_INIT_API_ID, FLSTST_E_PARAM_POINTER);
    }
#endif
    else
    {
        /*SWS_FlsTst_00020 SWS_FlsTst_00022*/
#if(FLSTST_CONFIG_VARIANTS == STD_CONFIG_VARIANTS_POSTBUILD)
        FlsTstConfigPtr = ConfigPtr;
#else
        (void)ConfigPtr;
        FlsTstConfigPtr = &FlsTstConfig;
#endif

        FlsTst__InternalInit();

        FlsTstState = FLSTST_INIT;

    }
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name : FlsTst_DeInit SWS_FlsTst_00027
*
* Description   : DeInit funtion of FlsTst
*
* Inputs        : None
*
* Outputs       : None
*
* Limitations   : None
********************************************************************************
END_FUNCTION_HDR */
FUNC(void, FLSTST_CODE) FlsTst_DeInit
(
    void
)
{

    if(FlsTstState == FLSTST_UNINIT)
    {
        FLSTST_DEVERR_DETECT(FLSTST_DEINIT_API_ID, FLSTST_E_UNINIT);
    }
    else
    {
        if(FlsTstState == FLSTST_ABORTED)
        {
            /*SWS_FlsTst_00028 29*/
            SchM_Enter_FlsTst_FLSTST_EXCLUSIVE_AREA_0();
            FlsTstConfigPtr = NULL_PTR;
            FlsTstState = FLSTST_UNINIT;
            FlsTst__InternalInit();
            SchM_Exit_FlsTst_FLSTST_EXCLUSIVE_AREA_0();
        }
    }

}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name : FlsTst_MainFunction  SWS_FlsTst_00066
*
* Description   : Mainfunction of FlsTst
*
* Inputs        : None
*
* Outputs       : None
*
* Limitations   : None
********************************************************************************
END_FUNCTION_HDR */
FUNC(void, FLSTST_CODE) FlsTst_MainFunction
(
    void
)
{
    if((FlsTstState == FLSTST_UNINIT) || (NULL_PTR == FlsTstConfigPtr))
    {
        FLSTST_DEVERR_DETECT(FLSTST_MAINFUNCTION_API_ID, FLSTST_E_UNINIT);
    }
    else if((FlsTstConfigPtr->BlockNumberBgnd == (FlsTst_BlockIdBgndType)0) || (NULL_PTR == FlsTstConfigPtr->BlockBgnd))
    {
        /* No Bgnd Block do nothing */
    }
    else
    {
        /* init or running SWS_FlsTst_00139 SWS_FlsTst_00032*/
        /*SWS_FlsTst_00067*/
        if(FlsTstState < FLSTST_ABORTED)
        {
            if (FLSTST_INIT == FlsTstState)
            {
                FlsTstBgndTestContext.BlockIndex = (FlsTst_BlockIdBgndType)0;
                FlsTst__InitTestContext((FlsTst_BlockIdBgndType)0);

                FlsTstState = FLSTST_RUNNING;   /*SWS_FlsTst_00068*/
            }
    
            /* only running is possible here, just call BgndProcess*/
            FlsTst__TestBgndBlock();
            
        }

    }

}


/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name : FlsTst_Abort  SWS_FlsTst_00030
*
* Description   : Mainfunction of FlsTst
*
* Inputs        : None
*
* Outputs       : None
*
* Limitations   : None
********************************************************************************
END_FUNCTION_HDR */
FUNC(void, FLSTST_CODE) FlsTst_Abort
(
    void
)
{
    if(FlsTstState == FLSTST_UNINIT)
    {
        FLSTST_DEVERR_DETECT(FLSTST_ABORT_API_ID, FLSTST_E_UNINIT);
    }
    else
    {
        SchM_Enter_FlsTst_FLSTST_EXCLUSIVE_AREA_0();
        FlsTstState = FLSTST_ABORTED; /*SWS_FlsTst_00031*/
        SchM_Exit_FlsTst_FLSTST_EXCLUSIVE_AREA_0();

    }
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name : FlsTst_StartFgnd   SWS_FlsTst_00149
*
* Description   : start fgnd block test
*
* Inputs        : FgndBlockId
*
* Outputs       : None
*
* Limitations   : None
********************************************************************************
END_FUNCTION_HDR */
#if (FLSTST_START_FGND_API == STD_ON)   /*SWS_FlsTst_00051*/
FUNC(Std_ReturnType, FLSTST_CODE) FlsTst_StartFgnd
(
    FlsTst_BlockIdFgndType FgndBlockId
)
{
    Std_ReturnType ret = E_NOT_OK;
    uint32 Addr = (uint32)0;
    uint32 Size = (uint32)0;
    FlsTst_SignatureType Sig = (FlsTst_SignatureType)0;

    uint8 AlgIndex = (uint8)0;
    FlsTst_AlgorithmFunType algorithm = NULL_PTR;


    if((FlsTstState == FLSTST_UNINIT)
            || (FlsTstConfigPtr == NULL_PTR))
    {
        FLSTST_DEVERR_DETECT(FLSTST_START_FGND_API_ID, FLSTST_E_UNINIT);
    }
    else if((FgndBlockId >= FlsTstConfigPtr->BlockNumberFgnd) || (NULL_PTR == FlsTstConfigPtr->BlockFgnd)) /*SWS_FlsTst_00033*/
    {
        FLSTST_DEVERR_DETECT(FLSTST_START_FGND_API_ID, FLSTST_E_PARAM_INVALID);
    }
    else
    {

        /*SWS_FlsTst_00143  SWS_FlsTst_00050*/
        SchM_Enter_FlsTst_FLSTST_EXCLUSIVE_AREA_0();

        FlsTstFgndTestReslut = FLSTST_NOT_TESTED;

        Addr = FlsTstConfigPtr->BlockFgnd[FgndBlockId].Address;
        Size = FlsTstConfigPtr->BlockFgnd[FgndBlockId].Size;
        AlgIndex = FlsTstConfigPtr->BlockFgnd[FgndBlockId].Algorithm;
        algorithm = FlsTstAlgorithm[AlgIndex];

        algorithm(Addr, Size, TRUE, &Sig);

        if(E_OK == FlsTst__CheckBlockSignature(Sig, TRUE, FgndBlockId))
        {
            FlsTstFgndTestReslut = FLSTST_OK;
            if(FlsTstErrorDetails.ErrFgndBlockId == FgndBlockId)
            {
                FlsTstErrorDetails.ErrFgndBlockId = FLSTST_INVALID_BLOCKID;
            }
        }
        else
        {
            FlsTstFgndTestReslut = FLSTST_NOT_OK;
            FlsTstErrorDetails.ErrFgndBlockId = FgndBlockId;
        }
        FlsTstFgndSignature.FgndBlockId = FgndBlockId;
        FlsTstFgndSignature.Signature = Sig;

        SchM_Exit_FlsTst_FLSTST_EXCLUSIVE_AREA_0();

        ret = E_OK;

    }

    return ret;
}
#endif

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name : FlsTst_Suspend  SWS_FlsTst_00034
*
* Description   : Suspend bgnd block test
*
* Inputs        : None
*
* Outputs       : None
*
* Limitations   : None
********************************************************************************
END_FUNCTION_HDR */
#if (FLSTST_SUSPEND_RESUME_API == STD_ON) /*SWS_FlsTst_00038*/
FUNC(void, FLSTST_CODE) FlsTst_Suspend
(
    void
)
{

    if(FlsTstState == FLSTST_UNINIT)
    {
        FLSTST_DEVERR_DETECT(FLSTST_SUSPEND_API_ID, FLSTST_E_UNINIT);
    }
    else
    {
        /*SWS_FlsTst_00037 36*/
        SchM_Enter_FlsTst_FLSTST_EXCLUSIVE_AREA_0();
        if ((FLSTST_INIT == FlsTstState)
                || (FLSTST_RUNNING == FlsTstState))
        {
            FlsTstStateBackUp =  FlsTstState;
            FlsTstState = FLSTST_SUSPENDED;
        }
        SchM_Exit_FlsTst_FLSTST_EXCLUSIVE_AREA_0();

    }

}
#endif

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name : FlsTst_Resume   SWS_FlsTst_00035
*
* Description   : resume bgnd block test
*
* Inputs        : None
*
* Outputs       : None
*
* Limitations   : None
********************************************************************************
END_FUNCTION_HDR */
#if (FLSTST_SUSPEND_RESUME_API == STD_ON) /*SWS_FlsTst_00089*/
FUNC(void, FLSTST_CODE) FlsTst_Resume
(
    void
)
{
    if(FlsTstState == FLSTST_UNINIT)
    {
        FLSTST_DEVERR_DETECT(FLSTST_RESUME_API_ID, FLSTST_E_UNINIT);
    }
    else
    {
        SchM_Enter_FlsTst_FLSTST_EXCLUSIVE_AREA_0();
        if (FLSTST_SUSPENDED == FlsTstState)
        {
            FlsTstState = FlsTstStateBackUp;  /*SWS_FlsTst_00038*/
        }
        else
        {
            /*SWS_FlsTst_00039*/
            FLSTST_DEVERR_DETECT(FLSTST_RESUME_API_ID, FLSTST_E_STATE_FAILURE);
        }
        SchM_Exit_FlsTst_FLSTST_EXCLUSIVE_AREA_0();

    }

}
#endif

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name : FlsTst_GetCurrentState   SWS_FlsTst_00040
*
* Description   : get FlsTst State
*
* Inputs        : None
*
* Outputs       : FlsTst_StateType
*
* Limitations   : None
********************************************************************************
END_FUNCTION_HDR */
#if (FLSTST_GET_CURRENT_STATE_API == STD_ON)    /*SWS_FlsTst_00091*/
FUNC(FlsTst_StateType, FLSTST_CODE) FlsTst_GetCurrentState
(
    void
)
{
    return FlsTstState; /*SWS_FlsTst_00011 SWS_FlsTst_00041*/
}
#endif

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name : FlsTst_GetTestResultBgnd SWS_FlsTst_00042
*
* Description   : get  Bgnd test result
*
* Inputs        : None
*
* Outputs       : FlsTst_TestResultBgndType
*
* Limitations   : None
********************************************************************************
END_FUNCTION_HDR */
#if (FLSTST_GET_TEST_RESULT_BGND_API == STD_ON)/*SWS_FlsTst_00093*/
FUNC(FlsTst_TestResultBgndType, FLSTST_CODE) FlsTst_GetTestResultBgnd
(
    void
)
{
    FlsTst_TestResultBgndType result = {(FlsTst_IntervalIdType)0, FLSTST_RESULT_NOT_TESTED};

    if(FlsTstState == FLSTST_UNINIT)
    {
        FLSTST_DEVERR_DETECT(FLSTST_GET_TEST_RESULT_BGND_API_ID, FLSTST_E_UNINIT);
    }
    else
    {
        /*SWS_FlsTst_00043*/
        SchM_Enter_FlsTst_FLSTST_EXCLUSIVE_AREA_0();
        result.IntervalId = FlsTstBgndTestIntervalId;
        result.Result = FlsTstBgndTestReslut;
        SchM_Exit_FlsTst_FLSTST_EXCLUSIVE_AREA_0();
    }

    return result;
}
#endif

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name : FlsTst_GetTestResultFgnd  SWS_FlsTst_00112
*
* Description   : get  Fgnd test result
*
* Inputs        : None
*
* Outputs       : FlsTst_TestResultFgndType
*
* Limitations   : None
********************************************************************************
END_FUNCTION_HDR */
#if (FLSTST_GET_TEST_RESULT_FGND_API == STD_ON) /*SWS_FlsTst_00113*/
FUNC(FlsTst_TestResultFgndType, FLSTST_CODE) FlsTst_GetTestResultFgnd
(
    void
)
{
    FlsTst_TestResultFgndType result = FLSTST_NOT_TESTED;

    if(FlsTstState == FLSTST_UNINIT)
    {
        FLSTST_DEVERR_DETECT(FLSTST_GET_TEST_RESULT_FGND_API_ID, FLSTST_E_UNINIT);
    }
    else
    {
        SchM_Enter_FlsTst_FLSTST_EXCLUSIVE_AREA_0();
        result = FlsTstFgndTestReslut;  /*SWS_FlsTst_00113*/
        SchM_Exit_FlsTst_FLSTST_EXCLUSIVE_AREA_0();
    }

    return result;
}
#endif


/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name : FlsTst_GetVersionInfo SWS_FlsTst_00044
*
* Description   : get  version information
*
* Inputs        : None
*
* Outputs       : VersionInfoPtr
*
* Limitations   : None
********************************************************************************
END_FUNCTION_HDR */
#if (FLSTST_VERSION_INFO_API == STD_ON)
FUNC(void, FLSTST_CODE) FlsTst_GetVersionInfo
(
    P2VAR(Std_VersionInfoType, AUTOMATIC, AUTOMATIC) VersionInfoPtr
)
{
    if(VersionInfoPtr == NULL_PTR)
    {
        FLSTST_DEVERR_DETECT(FLSTST_VERSION_INFO_API_ID, FLSTST_E_PARAM_POINTER);
    }
    else
    {
        VersionInfoPtr->vendorID = FLSTST_VENDOR_ID;
        VersionInfoPtr->moduleID = FLSTST_MODULE_ID;
        VersionInfoPtr->sw_major_version = (uint8)FLSTST_SW_MAJOR_VERSION;
        VersionInfoPtr->sw_minor_version = (uint8)FLSTST_SW_MINOR_VERSION;
        VersionInfoPtr->sw_patch_version = (uint8)FLSTST_SW_PATCH_VERSION;
    }
}
#endif

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name : FlsTst_GetTestSignatureBgnd SWS_FlsTst_00054
*
* Description   : get  test signature bgnd
*
* Inputs        : None
*
* Outputs       : FlsTst_TestSignatureBgndType
*
* Limitations   : None
********************************************************************************
END_FUNCTION_HDR */
#if (FLSTST_GET_TEST_SIGNATURE_BGND_API == STD_ON) /*SWS_FlsTst_00056*/
FUNC(FlsTst_TestSignatureBgndType, FLSTST_CODE) FlsTst_GetTestSignatureBgnd
(
    void
)
{
    FlsTst_TestSignatureBgndType signature = {(FlsTst_IntervalIdType)0, (FlsTst_SignatureType)0}; /*SWS_FlsTst_00115*/

    if(FlsTstState == FLSTST_UNINIT)
    {
        FLSTST_DEVERR_DETECT(FLSTST_GET_TEST_SIGNATURE_BGND_API_ID, FLSTST_E_UNINIT);
    }
    else
    {
        /*SWS_FlsTst_00055*/
        SchM_Enter_FlsTst_FLSTST_EXCLUSIVE_AREA_0();
        signature.IntervalId = FlsTstBgndTestIntervalId;
        signature.Signature = FlsTstBgndTestSignature;
        SchM_Exit_FlsTst_FLSTST_EXCLUSIVE_AREA_0();

    }

    return signature;
}
#endif

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name : FlsTst_GetTestSignatureFgnd  SWS_FlsTst_00057
*
* Description   : get  test signature Fgnd
*
* Inputs        : None
*
* Outputs       : FlsTst_TestSignatureFgndType
*
* Limitations   : None
********************************************************************************
END_FUNCTION_HDR */
#if (FLSTST_GET_TEST_SIGNATURE_FGND_API == STD_ON)/*SWS_FlsTst_00058*/
FUNC(FlsTst_TestSignatureFgndType, FLSTST_CODE) FlsTst_GetTestSignatureFgnd
(
    void
)
{
    FlsTst_TestSignatureFgndType signature = {FLSTST_INVALID_BLOCKID, (FlsTst_SignatureType)0}; /*SWS_FlsTst_00059*/

    if(FlsTstState == FLSTST_UNINIT)
    {
        FLSTST_DEVERR_DETECT(FLSTST_GET_TEST_SIGNATURE_FGND_API_ID, FLSTST_E_UNINIT);
    }
    else
    {
        /*SWS_FlsTst_00058*/
        SchM_Enter_FlsTst_FLSTST_EXCLUSIVE_AREA_0();
        signature.Signature = FlsTstFgndSignature.Signature;
        signature.FgndBlockId = FlsTstFgndSignature.FgndBlockId;
        SchM_Exit_FlsTst_FLSTST_EXCLUSIVE_AREA_0();
    }

    return signature;
}
#endif

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name : FlsTst_GetErrorDetails   SWS_FlsTst_00060
*
* Description   : get  test signature Fgnd
*
* Inputs        : None
*
* Outputs       : FlsTst_ErrorDetailsType
*
* Limitations   : None
********************************************************************************
END_FUNCTION_HDR */
#if (FLSTST_GET_ERROR_DETAILS_API == STD_ON)  /*SWS_FlsTst_00062*/
FUNC(FlsTst_ErrorDetailsType, FLSTST_CODE) FlsTst_GetErrorDetails
(
    void
)
{
    if(FlsTstState == FLSTST_UNINIT)
    {
        FLSTST_DEVERR_DETECT(FLSTST_GET_ERROR_DETAILS_API_ID, FLSTST_E_UNINIT);
    }

    return FlsTstErrorDetails;/*SWS_FlsTst_00061*/
}
#endif


/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name : FlsTst_TestEcc    SWS_FlsTst_00063
*
* Description   : Not Support yet
*
* Inputs        : None
*
* Outputs       : Std_ReturnType
*
* Limitations   : None
********************************************************************************
END_FUNCTION_HDR */
#if (FLSTST_TEST_ECC_API == STD_ON)     /*SWS_FlsTst_00065*/
FUNC(Std_ReturnType, FLSTST_CODE) FlsTst_TestEcc
(
    void
)
{
    return E_NOT_OK;
}
#endif



/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name : FlsTst__InitTestContext
*
* Description   : Init Block Test of Bgnd
*
* Inputs        : BlockId
*
* Outputs       : None
*
* Limitations   : None
********************************************************************************
END_FUNCTION_HDR */
STATIC FUNC(void, FLSTST_CODE) FlsTst__InitTestContext
(
    FlsTst_BlockIdBgndType BlockId
)
{
    FlsTstBgndTestContext.First = TRUE;
    FlsTstBgndTestContext.Address = FlsTstConfigPtr->BlockBgnd[BlockId].Address;
    FlsTstBgndTestContext.RemainSize = FlsTstConfigPtr->BlockBgnd[BlockId].Size;
    FlsTstBgndTestContext.Signature = (FlsTst_SignatureType)0;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name : FlsTst__CheckBlockSignature
*
* Description   : check signature right or not
*
* Inputs        : sig  isBgnd  BlockId
*
* Outputs       : None
*
* Limitations   : None
********************************************************************************
END_FUNCTION_HDR */
STATIC FUNC(Std_ReturnType, FLSTST_CODE) FlsTst__CheckBlockSignature
(
    FlsTst_SignatureType sig,
    boolean isBgnd,
    uint32 BlockId
)
{
    FlsTst_SignatureType SavedSig = (FlsTst_SignatureType)0;
    Std_ReturnType ret = E_NOT_OK;
    uint32 SigAddr = (uint32)0;

    if(TRUE == isBgnd)
    {
        SigAddr = FlsTstConfigPtr->BlockFgnd[BlockId].SignatureAddress;
    }
    else
    {
        SigAddr = FlsTstConfigPtr->BlockBgnd[BlockId].SignatureAddress;
    }

#if(STD_ON == FLSTST_GET_SIG_CALLOUT_SUPPORTED)
    SavedSig = FlsTst_GetSignatureCallout(isBgnd, BlockId, SigAddr) ;
#else
    SavedSig = *((FlsTst_SignatureType *)SigAddr);
#endif


    if(sig == SavedSig)
    {
        ret = E_OK;
    }
    return ret;

}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name : FlsTst__GetBlockSignature
*
* Description   : caculate signature
*
* Inputs        : None
*
* Outputs       : None
*
* Limitations   : None
********************************************************************************
END_FUNCTION_HDR */
STATIC FUNC(void, FLSTST_CODE) FlsTst__GetBlockSignature
(
    void
)
{
    
    uint32 cycleSize = FLSTST_NUMBER_OF_TESTED_CELLS;
    uint32 testedSize = (uint32)0;
    uint8  AlgFunIndex = FlsTstConfigPtr->BlockBgnd[FlsTstBgndTestContext.BlockIndex].Algorithm;
    const FlsTst_AlgorithmFunType algorithm = FlsTstAlgorithm[AlgFunIndex];

    /*SWS_FlsTst_00071 117*/
    if(FlsTstBgndTestContext.RemainSize < FLSTST_NUMBER_OF_TESTED_CELLS)
    {
        cycleSize = FlsTstBgndTestContext.RemainSize;
    }

    while((cycleSize > (uint32)0) && (FlsTstState == FLSTST_RUNNING)) /*SWS_FlsTst_00031*/
    {
        /* cells_atomic can not be interrupted by other isr or task
           if FLSTST_NUMBER_OF_TESTED_CELLS_ATOMIC = 0, means all process can not be interrupted
           SWS_FlsTst_00142
        */
#if(FLSTST_NUMBER_OF_TESTED_CELLS_ATOMIC > 0)
        if(cycleSize > (uint32)FLSTST_NUMBER_OF_TESTED_CELLS_ATOMIC)
        {
            testedSize = (uint32)FLSTST_NUMBER_OF_TESTED_CELLS_ATOMIC;
        }
        else
#endif
        {
            testedSize = cycleSize;
        }

        SchM_Enter_FlsTst_FLSTST_EXCLUSIVE_AREA_0();
        algorithm(FlsTstBgndTestContext.Address, testedSize, FlsTstBgndTestContext.First, &FlsTstBgndTestContext.Signature);
        SchM_Exit_FlsTst_FLSTST_EXCLUSIVE_AREA_0();

        FlsTstBgndTestContext.Address += testedSize;
        FlsTstBgndTestContext.RemainSize -= testedSize;
        cycleSize -= testedSize;
        FlsTstBgndTestContext.First = FALSE;

    }

}



/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name : FlsTst__TestBgndBlock
*
* Description   : Test  Block in Bgnd mode
*
* Inputs        : None
*
* Outputs       : None
*
* Limitations   : None
********************************************************************************
END_FUNCTION_HDR */
STATIC FUNC(void, FLSTST_CODE) FlsTst__TestBgndBlock
(
    void
)
{

    FlsTst__GetBlockSignature();

    if ((uint32)0 == FlsTstBgndTestContext.RemainSize)
    {
        if(E_NOT_OK == FlsTst__CheckBlockSignature(FlsTstBgndTestContext.Signature, FALSE, FlsTstBgndTestContext.BlockIndex))
        {
            /* save err infomation*/
            FlsTstBgndErrBlockCnt++;
            if(FlsTstBgndErrBlockId == FLSTST_INVALID_BLOCKID)
            {
                FlsTstBgndErrBlockId =  FlsTstBgndTestContext.BlockIndex;
            }
        }

        FlsTstBgndTestContext.BlockIndex++;
        if (FlsTstBgndTestContext.BlockIndex < FlsTstConfigPtr->BlockNumberBgnd)
        {
            FlsTst__InitTestContext(FlsTstBgndTestContext.BlockIndex);  /*SWS_FlsTst_00070*/
        }
        else
        {
            /* cycle finish */
            SchM_Enter_FlsTst_FLSTST_EXCLUSIVE_AREA_0();

            /* if NotTested, means this the first cycle, dont add IntervalId
            SWS_FlsTst_00156  SWS_FlsTst_00121*/
            if(FlsTstBgndTestReslut != FLSTST_RESULT_NOT_TESTED)
            {
                if(FlsTstBgndTestIntervalId <= FLSTST_TEST_INTERVAL_ID_END_VALUE)
                {
                    FlsTstBgndTestIntervalId++;
                }              
                if(FlsTstBgndTestIntervalId > FLSTST_TEST_INTERVAL_ID_END_VALUE)
                {
                    FlsTstBgndTestIntervalId = (FlsTst_IntervalIdType)0;
                }
            }

            /*SWS_FlsTst_00161 167*/
            if(FlsTstBgndErrBlockCnt > (FlsTst_BlockIdBgndType)0)
            {
                FlsTstBgndTestReslut = FLSTST_RESULT_NOT_OK;
                FlsTstErrorDetails.ErrBgndCnt = FlsTstBgndErrBlockCnt;
                FlsTstErrorDetails.ErrBgndIntervalId = FlsTstBgndTestIntervalId;
                FlsTstErrorDetails.ErrBgndBlockId = FlsTstBgndErrBlockId;

                FlsTstBgndTestSignature = FlsTstBgndErrBlockCnt;
                FLSTST_DEM_REPORT(DEM_EVENT_STATUS_FAILED);/*SWS_FlsTst_00168*/
            }
            else
            {
                FlsTstBgndTestReslut = FLSTST_RESULT_OK;
                FlsTstBgndTestSignature = (FlsTst_SignatureType)0;/* if ok, BgndSig reset to 0 */
                FLSTST_DEM_REPORT(DEM_EVENT_STATUS_PASSED); /*SWS_FlsTst_00168*/
            }

            FlsTstBgndErrBlockCnt = (FlsTst_BlockIdBgndType)0;
            FlsTstBgndErrBlockId = FLSTST_INVALID_BLOCKID;
            FlsTstState = FLSTST_INIT;

            /*FlsTstBgndTestContext.BlockIndex will reset in mainfuntion */

            SchM_Exit_FlsTst_FLSTST_EXCLUSIVE_AREA_0();

            if (FlsTstConfigPtr->CompletedNotification != NULL_PTR)
            {
                FlsTstConfigPtr->CompletedNotification();
            }



        }

    }
}

#define FLSTST_STOP_SEC_CODE
#include "MemMap.h"
