/*  BEGIN_FILE_HDR
********************************************************************************
*   NOTICE                              
*   This software is the property of HiRain Technologies. Any information 
*   contained in this doc should not be reproduced, or used, or disclosed 
*   without the written authorization from HiRain Technologies.
********************************************************************************
*   File Name       : RamTst.c
********************************************************************************
*   Project/Product : AUTOSAR 4.2.2
*   Title           : RamTst module Source File
*   Author          : Hirain
********************************************************************************
*   Description     : Implementation of RamTst provided functionality
*
********************************************************************************
*   Limitations     : None
*
********************************************************************************
*
********************************************************************************
*   Revision History:
* 
*   Version     Date          Initials      CR#        Descriptions
*   ---------   ----------    ------------  ---------  ---------------
*   01.00.00    17/08/2017    JunchengLi    N/A        Beta
*   01.01.00    22/04/2018    JunchengLi    N/A        Original
*   01.01.01    21/09/2018    JunchengLi    N/A        EAS422_RamTst_20180921_01
*   01.01.02    25/09/2018    JunchengLi    N/A        EAS422_RamTst_20180925_01
*   01.01.03    25/09/2018    JunchengLi    N/A        EAS422_RamTst_20180925_02
*   01.02.00    05/11/2018    JunchengLi    N/A        EAS422_RamTst_20181105_01
********************************************************************************
* END_FILE_HDR*/

/*******************************************************************************
*   Includes 
*******************************************************************************/

#include "RamTst.h"
#include "SchM_RamTst.h"

#if (STD_ON == RAMTST_DEV_ERROR_DETECT)
#include "Det.h"
#endif

#if (STD_ON == RAMTST_DEM_REPORT_ERROR_STATUS)
#include "Dem.h"
#endif

/*******************************************************************************
*   Macro 
*******************************************************************************/
#if (STD_ON == RAMTST_DEV_ERROR_DETECT)

#define RAMTST_DET_ERROR_DETECT(cond,ApiId,errcode)   \
      DET_ERROR_DETECT((cond), RAMTST_MODULE_ID, RAMTST_INSTANCE_ID,(ApiId),(errcode))

#define RAMTST_DET_ERROR_DETECT_RET(cond,ApiId,errcode,ret)   \
      DET_ERROR_DETECT_RET((cond), RAMTST_MODULE_ID,RAMTST_INSTANCE_ID,(ApiId),(errcode), (ret))

#define RAMTST_DET_REPORT_ERROR(ApiId, errcode)  \
      DET_REPORT_ERROR(RAMTST_MODULE_ID, RAMTST_INSTANCE_ID, (ApiId), (errcode))

#else

#define RAMTST_DET_ERROR_DETECT(cond,ApiId,errcode)
#define RAMTST_DET_ERROR_DETECT_RET(cond,ApiId,errcode,ret)
#define RAMTST_DET_REPORT_ERROR(ApiId, errcode)

#endif

#if (STD_ON == RAMTST_DEM_REPORT_ERROR_STATUS)

#define RAMTST_DEM_REPORT_ERROR(event,state)  Dem_ReportErrorStatus(event,state)
                            
#else

#define RAMTST_DEM_REPORT_ERROR(event,state)

#endif

/*******************************************************************************
*   Version Check 
*******************************************************************************/
#if(STD_ON == RAMTST_PRIVATE_VERSION_CHECK)
/* check Version with other import module */


/* check Version with cfg file */
#if ((RAMTST_AR_RELEASE_MAJOR_VERSION != RAMTST_AR_RELEASE_MAJOR_VERSION_CFG) || \
   (RAMTST_AR_RELEASE_MINOR_VERSION != RAMTST_AR_RELEASE_MINOR_VERSION_CFG))
#error "AutoSar Version Numbers of RamTst and its cfg file are different"
#endif

#if ((RAMTST_SW_MAJOR_VERSION != RAMTST_SW_MAJOR_VERSION_CFG) || \
   (RAMTST_SW_MINOR_VERSION != RAMTST_SW_MINOR_VERSION_CFG))
#error "SW Version Numbers of RamTst and its cfg file are different"
#endif


#endif/*#if(STD_ON == RAMTST_PRIVATE_AR_VERSION_CHECK)*/


/*******************************************************************************
*   Local Data Declaration 
*******************************************************************************/
#define RAMTST_START_SEC_VAR_INIT_8
#include "MemMap.h"

STATIC VAR(RamTst_ExecutionStatusType,RAMTST_VAR) RamTst_ExecutionStatus = RAMTST_EXECUTION_UNINIT;


#define RAMTST_STOP_SEC_VAR_INIT_8
#include "MemMap.h"


#define RAMTST_START_SEC_VAR_NOINIT_8
#include "MemMap.h"

STATIC VAR(RamTst_TestResultType,RAMTST_VAR) RamTst_TestResult;
STATIC VAR(uint8,RAMTST_VAR)RamTst_ResultFlag;


#define RAMTST_STOP_SEC_VAR_NOINIT_8
#include "MemMap.h"


#define RAMTST_START_SEC_VAR_NOINIT_32
#include "MemMap.h"

STATIC VAR(RamTst_NumberOfTestedCellsType,RAMTST_VAR) RamTst_NumberOfCells;    

#define RAMTST_STOP_SEC_VAR_NOINIT_32
#include "MemMap.h"


#define RAMTST_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"

STATIC P2CONST(RamTst_ConfigAlgParamsType, RAMTST_VAR, RAMTST_CONST) RamTst_AlgParams = NULL_PTR;

#define RAMTST_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"


#define RAMTST_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h"

STATIC VAR(RamTst_TestContextType,RAMTST_VAR) RamTst_Context;    

#define RAMTST_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h"


/*******************************************************************************
*   Local Functions declare
*******************************************************************************/
#define RAMTST_START_SEC_CODE
#include "MemMap.h"


#if (STD_ON == RAMTST_GET_TEST_RESULT_PER_BLOCK_API)
STATIC FUNC(Std_ReturnType, RAMTST_CODE) RamTst_CheckBlockId
(
    RamTst_NumberOfBlocksType BlockId
);
#endif

STATIC FUNC(Std_ReturnType, RAMTST_CODE) RamTst_CheckAlgParamsConfig
(
    RamTst_AlgParamsIdType AlgParamsId
);
 
STATIC FUNC(void, RAMTST_CODE) RamTst_TestRam
(
    P2CONST(RamTst_TestContextType, AUTOMATIC, AUTOMATIC) CtxPtr,
    uint32 NumberOfCells
);

STATIC FUNC(void, RAMTST_CODE) RamTst_UpdateContext
(
    P2VAR(RamTst_TestContextType, AUTOMATIC, AUTOMATIC) TestCtxPtr
);

#if (STD_ON == RAMTST_RUN_FULL_TEST_API)
STATIC FUNC(void, RAMTST_CODE) RamTst_RunBlockTest
(
    RamTst_NumberOfBlocksType algParamsBlockId
);
#endif

STATIC FUNC(void, RAMTST_CODE) RamTst_InitResult
(
    void
);

#if (STD_ON == RAMTST_RUN_PARTIAL_TEST_API)
STATIC FUNC(RamTst_NumberOfBlocksType, RAMTST_CODE) RamTst_GetAlgParamsBlockId
(
    RamTst_NumberOfBlocksType blockId
);
#endif

STATIC FUNC(RamTst_NumberOfBlocksType, RAMTST_CODE) RamTst_GetBlockId
(
    RamTst_NumberOfBlocksType algParamsBlockId,
    P2CONST(RamTst_ConfigAlgParamsType, AUTOMATIC, RAMTST_CONST) AlgParamPtr
);



/*******************************************************************************
*   Local Functions define
*******************************************************************************/

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: RamTst_Init
*                
* Description:   Service for RAM Test initialization.  
*               
* Inputs:        ConfigPtr: Pointer to the selected configuration set.The 
*                             Configuration pointer ConfigPtr shall always have 
*                            a NULL_PTR value. 
*                   
* Outputs:       None
* 
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/

FUNC(void, RAMTST_CODE) RamTst_Init /*RamTst099*/
(
    P2CONST(RamTst_ConfigType, AUTOMATIC, AUTOMATIC) ConfigPtr
)
{
    RamTst_AlgParamsIdType index;

    (void)ConfigPtr;
        
    
    if(RAMTST_EXECUTION_UNINIT == RamTst_ExecutionStatus)
    {
        /*initialized to use the default test parameter set*/
        if(E_OK == RamTst_CheckAlgParamsConfig(RamTstConfig.DefaultAlgParamsId)) /*RamTst007*/
        {
            index = (RamTstConfig.DefaultAlgParamsId)-(RamTst_AlgParamsIdType)1;
            RamTst_AlgParams = &RamTstConfig.AlgParamSets[index];
            RamTst_NumberOfCells = RamTst_AlgParams->NumberOfTestedCells;
            RamTst_InitResult();
            
            RamTst_ExecutionStatus = RAMTST_EXECUTION_STOPPED;
        }
        else
        {
            RamTst_NumberOfCells = (RamTst_NumberOfTestedCellsType)0;
        }
    }
    else
    {
        RAMTST_DET_REPORT_ERROR(RAMTST_INIT_API_ID,RAMTST_E_STATUS_FAILURE);
    }

    return ;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: RamTst_DeInit
*                
* Description:   Service for RAM Test deinitialization.
*                
* Inputs:        None
*                   
* Outputs:       None
* 
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/

FUNC(void, RAMTST_CODE) RamTst_DeInit /*RamTst146,RamTst147*/
(
    void
)
{
    RamTst_AlgParams = NULL_PTR;
    RamTst_NumberOfCells = (RamTst_NumberOfTestedCellsType)0;
    RamTst_InitResult();
    
    RamTst_ExecutionStatus = RAMTST_EXECUTION_UNINIT;

    return ;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: RamTst_Stop
*                
* Description:   Service for stopping the RAM Test.
*                
* Inputs:        None
*                   
* Outputs:       None
* 
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
#if (STD_ON == RAMTST_STOP_API)
FUNC(void, RAMTST_CODE) RamTst_Stop /*RamTst100*/
(
    void
)
{
    if((RAMTST_EXECUTION_RUNNING == RamTst_ExecutionStatus)
        || (RAMTST_EXECUTION_SUSPENDED == RamTst_ExecutionStatus))
    {
        RamTst_ExecutionStatus = RAMTST_EXECUTION_STOPPED; /*RamTst014*/
    }
    else if(RAMTST_EXECUTION_UNINIT == RamTst_ExecutionStatus)
    {
        RAMTST_DET_REPORT_ERROR(RAMTST_STOP_API_ID,RAMTST_E_UNINIT);
    }
    else
    {
        RAMTST_DET_REPORT_ERROR(RAMTST_STOP_API_ID,RAMTST_E_STATUS_FAILURE);/*RamTst033*/
    }
    
    return ;
}
#endif

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: RamTst_Allow
*                
* Description:   Service for continuing the RAM Test after calling 'RamTst_Stop.
*                
* Inputs:        None
*                   
* Outputs:       None
* 
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
#if (STD_ON == RAMTST_ALLOW_API)
FUNC(void, RAMTST_CODE) RamTst_Allow /*RamTst149*/
(
    void
)
{
    if(RAMTST_EXECUTION_STOPPED == RamTst_ExecutionStatus)
    {
        RamTst_ExecutionStatus = RAMTST_EXECUTION_RUNNING;/*RamTst169*/

        /*reset relevant variables*/
        RamTst_Context.AlgParamsBlockId = (RamTst_NumberOfBlocksType)0;
        RamTst_UpdateContext(&RamTst_Context);
        RamTst_ResultFlag = TRUE;
    }
    else if(RAMTST_EXECUTION_UNINIT == RamTst_ExecutionStatus)
    {
        RAMTST_DET_REPORT_ERROR(RAMTST_ALLOW_API_ID,RAMTST_E_UNINIT);
    }
    else
    {
        RAMTST_DET_REPORT_ERROR(RAMTST_ALLOW_API_ID,RAMTST_E_STATUS_FAILURE);/*RamTst170*/
    }

    return ;
}
#endif

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: RamTst_Suspend
*                
* Description:  Service for suspending current operation of background RAM Test,
*                until RESUME is called.
*                
* Inputs:        None
*                   
* Outputs:       None
* 
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
#if (STD_ON == RAMTST_SUSPEND_API)
FUNC(void, RAMTST_CODE) RamTst_Suspend/*RamTst150*/
(
    void
)
{
    if(RAMTST_EXECUTION_RUNNING == RamTst_ExecutionStatus)
    {
        RamTst_ExecutionStatus = RAMTST_EXECUTION_SUSPENDED;/*RamTst171*/
    }
    else if(RAMTST_EXECUTION_UNINIT == RamTst_ExecutionStatus)
    {
        RAMTST_DET_REPORT_ERROR(RAMTST_SUSPEND_API_ID,RAMTST_E_UNINIT);
    }
    else
    {
        RAMTST_DET_REPORT_ERROR(RAMTST_SUSPEND_API_ID,RAMTST_E_STATUS_FAILURE);/*RamTst172*/
    }
    
    return ;
}
#endif

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: RamTst_Resume
*                
* Description:   Service for allowing to continue the background RAM Test at 
*                 the point is was suspended.
*                
* Inputs:        None
*                   
* Outputs:       None
* 
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
#if (STD_ON == RAMTST_RESUME_API)
FUNC(void, RAMTST_CODE) RamTst_Resume/*RamTst101*/
(
    void
)
{
    if(RAMTST_EXECUTION_SUSPENDED == RamTst_ExecutionStatus)
    {
        RamTst_ExecutionStatus = RAMTST_EXECUTION_RUNNING;/*RamTst018*/
    }
    else if(RAMTST_EXECUTION_UNINIT == RamTst_ExecutionStatus)
    {
        RAMTST_DET_REPORT_ERROR(RAMTST_RESUME_API_ID,RAMTST_E_UNINIT);
    }
    else
    {
        RAMTST_DET_REPORT_ERROR(RAMTST_RESUME_API_ID,RAMTST_E_STATUS_FAILURE);/*RamTst037*/
    }
    
    return ;
}
#endif

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: RamTst_GetExecutionStatus
*                
* Description:   Service returns the current RAM Test execution status.
*                
* Inputs:        None
*                   
* Outputs:       RamTst_ExecutionStatusType:Exection status
* 
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
#if (STD_ON == RAMTST_GET_EXECUTION_STATUS_API)
FUNC(RamTst_ExecutionStatusType, RAMTST_CODE) RamTst_GetExecutionStatus/*RamTst102*/
(
    void
)
{
    if(RAMTST_EXECUTION_UNINIT == RamTst_ExecutionStatus)
    {
        RAMTST_DET_REPORT_ERROR(RAMTST_GET_EXECUTION_STATUS_API_ID,RAMTST_E_UNINIT);
    }
    
    return RamTst_ExecutionStatus;
}
#endif

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: RamTst_GetTestResult
*                
* Description:   Service returns the current RAM Test result.
*                
* Inputs:        None
*                   
* Outputs:       RamTst_TestResultType:Test result
* 
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
#if (STD_ON == RAMTST_GET_TEST_RESULT_API)
FUNC(RamTst_TestResultType, RAMTST_CODE) RamTst_GetTestResult/*RamTst103*/
(
    void
)
{
    if(RAMTST_EXECUTION_UNINIT == RamTst_ExecutionStatus)
    {
        RAMTST_DET_REPORT_ERROR(RAMTST_GET_TEST_RESULT_API_ID,RAMTST_E_UNINIT);
        RamTst_TestResult = RAMTST_RESULT_UNDEFINED;
    }
    
    return RamTst_TestResult;/*RamTst024*/
}
#endif

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: RamTst_GetTestResultPerBlock
*                
* Description:   Service returns the current RAM Test result for the specified block.
*                
* Inputs:        BlockId
*                  
* Outputs:       RamTst_TestResultType:The specific bolck test result
* 
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
#if (STD_ON == RAMTST_GET_TEST_RESULT_PER_BLOCK_API)
FUNC(RamTst_TestResultType, RAMTST_CODE) RamTst_GetTestResultPerBlock/*RamTst104*/
(
    RamTst_NumberOfBlocksType BlockId
)
{
    RamTst_TestResultType result = RAMTST_RESULT_UNDEFINED;
    
    if(RAMTST_EXECUTION_UNINIT == RamTst_ExecutionStatus)
    {
        RAMTST_DET_REPORT_ERROR(RAMTST_GET_TEST_RESULT_PER_BLOCK_API_ID,RAMTST_E_UNINIT);
    }
    else
    {
        if(E_OK == RamTst_CheckBlockId(BlockId))
        {
            result = RamTstBlockTestResult[(BlockId-(RamTst_NumberOfBlocksType)1)];
        }
        else
        {
            RAMTST_DET_REPORT_ERROR(RAMTST_GET_TEST_RESULT_PER_BLOCK_API_ID,RAMTST_E_OUT_OF_RANGE);
        }
    }
    
    return result;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: RamTst_CheckBlockId
*                
* Description:   Check the BlockId if or not in the range
*                
* Inputs:        BlockId:BlockId of RAM
*                   
* Outputs:       E_OK:in the range
*                 E_NOT_OK:out of range
* 
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(Std_ReturnType, RAMTST_CODE) RamTst_CheckBlockId
(
    RamTst_NumberOfBlocksType BlockId
)
{
    Std_ReturnType ret = E_NOT_OK;
    RamTst_NumberOfBlocksType i;
    
    if (NULL_PTR != RamTst_AlgParams)
    {
        /*get the AlgParamsBlockId from BlockId*/
        for(i = (RamTst_NumberOfBlocksType)0; i < RamTst_AlgParams->NumberOfBlocks; i++)
        {
            if(BlockId == RamTst_GetBlockId(i,RamTst_AlgParams))
            {
                ret = E_OK;
                break;
            }
        }
    }
    
    return ret;
}

#endif

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: RamTst_GetVersionInfo
*                
* Description:   Get version information
*                
* Inputs:        VersionInfoPtr:Pointer to the location / address where to store
*                                 the version information of this module.
*                   
* Outputs:       None
* 
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
#if (STD_ON == RAMTST_GET_VERSION_INFO_API)
FUNC(void, RAMTST_CODE) RamTst_GetVersionInfo/*RamTst109*/
(
    P2VAR(Std_VersionInfoType, AUTOMATIC, AUTOMATIC) VersionInfoPtr
)
{
    if(NULL_PTR != VersionInfoPtr)
    {
        VersionInfoPtr->vendorID = RAMTST_VENDOR_ID;
        VersionInfoPtr->moduleID = RAMTST_MODULE_ID;
        VersionInfoPtr->sw_major_version = (uint8)RAMTST_SW_MAJOR_VERSION;
        VersionInfoPtr->sw_minor_version = (uint8)RAMTST_SW_MINOR_VERSION;
        VersionInfoPtr->sw_patch_version = (uint8)RAMTST_SW_PATCH_VERSION;
    }
    else
    {
        RAMTST_DET_REPORT_ERROR(RAMTST_GET_VERSION_INFO_API_ID,RAMTST_E_PARAM_POINTER);/*RamTst222*/
    }

    return ;
}
#endif

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: RamTst_GetAlgParams
*                
* Description:   Service returns the ID of the current RAM Test algorithm 
*                 parameter set.
*                
* Inputs:        None
*                   
* Outputs:       RamTst_AlgParamsIdType:ID of the current RAM Test algorithm parameter set
* 
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
#if (STD_ON == RAMTST_GET_ALG_PARAMS_API)
FUNC(RamTst_AlgParamsIdType, RAMTST_CODE) RamTst_GetAlgParams/*RamTst193*/
(
    void
)
{
    RamTst_AlgParamsIdType id = (RamTst_AlgParamsIdType)0;
    
    if(RAMTST_EXECUTION_UNINIT == RamTst_ExecutionStatus)
    {
        RAMTST_DET_REPORT_ERROR(RAMTST_GET_ALG_PARAMS_API_ID,RAMTST_E_UNINIT);
    }
    else
    {
        if (NULL_PTR != RamTst_AlgParams)
        {
            id = RamTst_AlgParams->AlgParamsId;
        }
    }

    return id;
}
#endif

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: RamTst_GetTestAlgorithm
*                
* Description:   Service returns the current RAM Test algorithm
*                
* Inputs:        None
*                   
* Outputs:       RamTst_AlgorithmType:Algorithm
* 
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
#if (STD_ON == RAMTST_GET_TEST_ALGORITHM_API)
FUNC(RamTst_AlgorithmType, RAMTST_CODE) RamTst_GetTestAlgorithm/*RamTst106*/
(
    void
)
{
    RamTst_AlgorithmType alg = RAMTST_ALGORITHM_UNDEFINED;

    if(RAMTST_EXECUTION_UNINIT == RamTst_ExecutionStatus)
    {
        RAMTST_DET_REPORT_ERROR(RAMTST_GET_TEST_ALGORITHM_API_ID,RAMTST_E_UNINIT);
    }
    else
    {
        if (NULL_PTR != RamTst_AlgParams)
        {
            alg = RamTst_AlgParams->Algorithm;
        }
    }

    return alg;
}
#endif

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: RamTst_GetNumberOfTestedCells
*                
* Description:   Service returns the current number of tested cells per 
*                 main-function cycle
*                
* Inputs:        None
*                   
* Outputs:       RamTst_NumberOfTestedCellsType:number of tested cells
* 
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
#if (STD_ON == RAMTST_GET_NUMBER_OF_TESTED_CELLS_API)
FUNC(RamTst_NumberOfTestedCellsType, RAMTST_CODE) RamTst_GetNumberOfTestedCells/*RamTst108*/
(
    void
)
{
    if(RAMTST_EXECUTION_UNINIT == RamTst_ExecutionStatus)
    {
        RAMTST_DET_REPORT_ERROR(RAMTST_GET_NUMBER_OF_TESTED_CELLS_API_ID,RAMTST_E_UNINIT);
        RamTst_NumberOfCells = (RamTst_NumberOfTestedCellsType)0;
    }
    
    return RamTst_NumberOfCells;/*RamTst034*/
}
#endif

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: RamTst_SelectAlgParams
*                
* Description:   Service used to set the test algorithm and its parameter set
*                
* Inputs:        NewAlgParamsId:Identifies the parameter set to be used
*                   
* Outputs:       None
* 
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
#if (STD_ON == RAMTST_SELECT_ALG_PARAMS_API)
FUNC(void, RAMTST_CODE) RamTst_SelectAlgParams/*RamTst105*/
(
    RamTst_AlgParamsIdType NewAlgParamsId
)
{    
    RamTst_NumberOfBlocksType i;
    RamTst_NumberOfBlocksType blockId;
    
    P2CONST(RamTst_ConfigAlgParamsType, AUTOMATIC, AUTOMATIC) algParamPtr;

    if(RAMTST_EXECUTION_STOPPED == RamTst_ExecutionStatus)
    {
        if(E_OK == RamTst_CheckAlgParamsConfig(NewAlgParamsId))
        {
            algParamPtr = &RamTstConfig.AlgParamSets[(NewAlgParamsId-(RamTst_AlgParamsIdType)1)];
             
            RamTst_NumberOfCells = algParamPtr->NumberOfTestedCells;

            /*get the BlockId from AlgParamsBlockId and reset the test result*/
            for (i = (RamTst_NumberOfBlocksType)0; i < algParamPtr->NumberOfBlocks; i++)
            {
                blockId = RamTst_GetBlockId(i,algParamPtr);
                
                RamTstBlockTestResult[(blockId-(RamTst_NumberOfBlocksType)1)] = RAMTST_RESULT_NOT_TESTED;
            }
            RamTst_TestResult = RAMTST_RESULT_NOT_TESTED;

            RamTst_AlgParams = algParamPtr;
        }
        else
        {
            RAMTST_DET_REPORT_ERROR(RAMTST_SELECT_ALG_PARAMS_API_ID, RAMTST_E_OUT_OF_RANGE);/*RamTst084*/
        }
    }
    else if(RAMTST_EXECUTION_UNINIT == RamTst_ExecutionStatus)
    {
        RAMTST_DET_REPORT_ERROR(RAMTST_SELECT_ALG_PARAMS_API_ID,RAMTST_E_UNINIT);
    }
    else
    {
        RAMTST_DET_REPORT_ERROR(RAMTST_SELECT_ALG_PARAMS_API_ID,RAMTST_E_STATUS_FAILURE);/*RamTst097*/
    }
    
    return ;
}
#endif

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: RamTst_ChangeNumberOfTestedCells
*                
* Description:   Service changes the current number of tested cells
*                
* Inputs:        NewNumberOfTestedCells
*                   
* Outputs:       None
* 
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
#if (RAMTST_CHANGE_NUMBER_OF_TESTED_CELLS_API == STD_ON)
FUNC(void, RAMTST_CODE) RamTst_ChangeNumberOfTestedCells/*RamTst107*/
(
    RamTst_NumberOfTestedCellsType NewNumberOfTestedCells
)
{
    if(RAMTST_EXECUTION_STOPPED == RamTst_ExecutionStatus)
    {
        if((uint32)0 != (NewNumberOfTestedCells%RAMTST_CELL_SIZE))
        {
            RAMTST_DET_REPORT_ERROR(RAMTST_CHANGE_NUMBER_OF_TESTED_CELLS_API_ID,RAMTST_E_OUT_OF_RANGE);
        }
        else 
        {
            if (NULL_PTR != RamTst_AlgParams)
            {
                /*check the NewNumberOfTestedCells in the range and set RamTst_NumberOfCells*/
                if((NewNumberOfTestedCells > RamTstConfig.MinNumberOfTestedCells)
                && (NewNumberOfTestedCells < RamTst_AlgParams->MaxNumberOfTestedCells))
                {
                    RamTst_NumberOfCells = NewNumberOfTestedCells;
                }
                else
                {    
                    RAMTST_DET_REPORT_ERROR(RAMTST_CHANGE_NUMBER_OF_TESTED_CELLS_API_ID,RAMTST_E_OUT_OF_RANGE);/*RamTst040*/
                }
            }
        }
    }
    else if(RAMTST_EXECUTION_UNINIT == RamTst_ExecutionStatus)
    {
        RAMTST_DET_REPORT_ERROR(RAMTST_CHANGE_NUMBER_OF_TESTED_CELLS_API_ID,RAMTST_E_UNINIT);
    }
    else
    {
        RAMTST_DET_REPORT_ERROR(RAMTST_CHANGE_NUMBER_OF_TESTED_CELLS_API_ID,RAMTST_E_STATUS_FAILURE);/*RamTst095*/
    }

    return ;
}
#endif

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: RamTst_RunFullTest
*                
* Description:   Service for executing the full RAM Test in the foreground
*                
* Inputs:        None
*                   
* Outputs:       None
* 
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
#if (STD_ON == RAMTST_RUN_FULL_TEST_API)
FUNC(void, RAMTST_CODE) RamTst_RunFullTest/*RamTst195*/
(
    void
)
{    
    RamTst_NumberOfBlocksType i;
    RamTst_NumberOfBlocksType BlockId;
    uint8 Flag = TRUE;
    
    if(RAMTST_EXECUTION_STOPPED == RamTst_ExecutionStatus)
    {
        
        RamTst_ExecutionStatus = RAMTST_EXECUTION_RUNNING;/*RamTst211*/
        if (RAMTST_RESULT_NOT_TESTED == RamTst_TestResult)
        {
            RamTst_TestResult = RAMTST_RESULT_UNDEFINED;
        }

        /*test all block in the AlgParams set*/
        for (i = (RamTst_NumberOfBlocksType)0; i < RamTst_AlgParams->NumberOfBlocks; i++)
        {
            RamTst_RunBlockTest(i);
            BlockId = RamTst_GetBlockId(i,RamTst_AlgParams);
            if(RAMTST_RESULT_NOT_OK != RamTstBlockTestResult[(BlockId-(RamTst_NumberOfBlocksType)1)])
            {
                RamTstBlockTestResult[(BlockId-(RamTst_NumberOfBlocksType)1)] = RAMTST_RESULT_OK;
            }
            else
            {
                RamTst_TestResult = RAMTST_RESULT_NOT_OK;
                Flag = FALSE;
            }
        }
        
        if (TRUE == Flag)
        {
            RamTst_TestResult = RAMTST_RESULT_OK;
            RAMTST_DEM_REPORT_ERROR(RAMTST_RUNFL_RAM_FAILURE,RAMTST_E_RAM_PASSED);
        }
        else
        {
            RAMTST_DEM_REPORT_ERROR(RAMTST_RUNFL_RAM_FAILURE,RAMTST_E_RAM_FAILURE);
        }
        RamTst_ExecutionStatus = RAMTST_EXECUTION_STOPPED;/*RamTst211*/
        
    }
    else if(RAMTST_EXECUTION_UNINIT == RamTst_ExecutionStatus)
    {
        RAMTST_DET_REPORT_ERROR(RAMTST_RUN_FULL_TEST_API_ID,RAMTST_E_UNINIT);
    }
    else
    {
        RAMTST_DET_REPORT_ERROR(RAMTST_RUN_FULL_TEST_API_ID,RAMTST_E_STATUS_FAILURE);/*RamTst210*/
    }

    return ;
}
#endif

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: RamTst_RunPartialTest
*                
* Description:   Service for testing one RAM block in the foreground
*                
* Inputs:        BlockId:Identifies the single RAM block to be tested in the 
*                 selected set of RamTstAlgParams
*                   
* Outputs:       None
* 
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
#if (STD_ON == RAMTST_RUN_PARTIAL_TEST_API)
FUNC(void, RAMTST_CODE) RamTst_RunPartialTest/*RamTst197*/
(
    RamTst_NumberOfBlocksType BlockId
)
{
    RamTst_NumberOfBlocksType algParamsBlockId;
    RamTst_ExecutionStatusType status;
    
    if ((RAMTST_EXECUTION_STOPPED == RamTst_ExecutionStatus)
        || (RAMTST_EXECUTION_SUSPENDED == RamTst_ExecutionStatus))
    {
        /*check the block in the range and test it*/
        if (E_OK == RamTst_CheckBlockId(BlockId))
        {
            status = RamTst_ExecutionStatus;
    
            RamTst_ExecutionStatus = RAMTST_EXECUTION_RUNNING;
            if (RAMTST_RESULT_NOT_TESTED == RamTst_TestResult)
            {
                RamTst_TestResult = RAMTST_RESULT_UNDEFINED;
            }
            algParamsBlockId = RamTst_GetAlgParamsBlockId(BlockId);
            RamTst_RunBlockTest(algParamsBlockId);

            if(RAMTST_RESULT_NOT_OK != RamTstBlockTestResult[(BlockId-(RamTst_NumberOfBlocksType)1)])
            {
                RamTstBlockTestResult[(BlockId-(RamTst_NumberOfBlocksType)1)] = RAMTST_RESULT_OK;
                RAMTST_DEM_REPORT_ERROR(RAMTST_PART_RAM_FAILURE,RAMTST_E_RAM_PASSED);
            }
            else
            {
                RamTst_TestResult = RAMTST_RESULT_NOT_OK;
                RAMTST_DEM_REPORT_ERROR(RAMTST_PART_RAM_FAILURE,RAMTST_E_RAM_FAILURE);
            }
             
            RamTst_ExecutionStatus = status;/*RamTst215*/
        }
        else
        {
            RAMTST_DET_REPORT_ERROR(RAMTST_RUN_PARTIAL_TEST_API_ID,RAMTST_E_OUT_OF_RANGE);
        }
    }
    else if(RAMTST_EXECUTION_UNINIT == RamTst_ExecutionStatus)
    {
        RAMTST_DET_REPORT_ERROR(RAMTST_RUN_PARTIAL_TEST_API_ID,RAMTST_E_UNINIT);
    }
    else
    {
        RAMTST_DET_REPORT_ERROR(RAMTST_RUN_PARTIAL_TEST_API_ID,RAMTST_E_STATUS_FAILURE);/*RamTst214*/
    }
    
    return ;
}
#endif

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: RamTst_MainFunction
*                
* Description:   Scheduled function for executing the RAM Test in the background
*                
* Inputs:        None
*                   
* Outputs:       None
* 
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, RAMTST_CODE) RamTst_MainFunction/*RamTst110*/
(
    void
)
{
    uint32 numberOfCells;
    uint32 testedNumber;
        
    if (RAMTST_EXECUTION_RUNNING == RamTst_ExecutionStatus)
    {
        numberOfCells = RamTst_NumberOfCells;

        if (RAMTST_RESULT_NOT_TESTED == RamTst_TestResult)
        {
            RamTst_TestResult = RAMTST_RESULT_UNDEFINED;
        }

        /*test numberofCells of a cycle*/
        while(numberOfCells > (uint32)0)
        {
            if (numberOfCells > RamTst_Context.RemainCells)
            {
                testedNumber = RamTst_Context.RemainCells;
            }
            else
            {
                testedNumber = numberOfCells;
            }

            RamTst_TestRam(&RamTst_Context,testedNumber);

            numberOfCells -= testedNumber;
            RamTst_Context.RemainCells -= testedNumber;

            if(RAMTST_RESULT_NOT_OK == RamTstBlockTestResult[(RamTst_Context.BlockId -(RamTst_NumberOfBlocksType)1)])
            {
                RamTst_Context.RemainCells = (uint32)0;
                RamTst_TestResult = RAMTST_RESULT_NOT_OK;
                RamTst_ResultFlag = FALSE;
            }

            /*if a block end of test should test next block,if the block is the last 
            one,it should test begin with the first block*/
            if((uint32)0 == RamTst_Context.RemainCells)
            {
                if(RAMTST_RESULT_NOT_OK != RamTstBlockTestResult[(RamTst_Context.BlockId -(RamTst_NumberOfBlocksType)1)])
                {
                    RamTstBlockTestResult[(RamTst_Context.BlockId -(RamTst_NumberOfBlocksType)1)] = RAMTST_RESULT_OK;
                }
                if(RamTst_Context.AlgParamsBlockId < RamTst_AlgParams->NumberOfBlocks)
                {
                    RamTst_Context.AlgParamsBlockId++;
                }
                if(RamTst_Context.AlgParamsBlockId >= RamTst_AlgParams->NumberOfBlocks) 
                {
                    if (TRUE == RamTst_ResultFlag)
                    { 
                        RamTst_TestResult = RAMTST_RESULT_OK;
                        RAMTST_DEM_REPORT_ERROR(RAMTST_MAIN_RAM_FAILURE,RAMTST_E_RAM_PASSED);
                    }
                    else
                    {
                        RAMTST_DEM_REPORT_ERROR(RAMTST_MAIN_RAM_FAILURE,RAMTST_E_RAM_FAILURE);
                    }
                    
                    if (NULL_PTR != RamTstConfig.TestCompletedNotification)
                    {
                        RamTstConfig.TestCompletedNotification();
                    }
                    RamTst_ResultFlag = TRUE;
                }
                RamTst_UpdateContext(&RamTst_Context);
            }
            else
            {
                RamTst_Context.Address += testedNumber;
            }
        }
    }

    return ;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: RamTst_CheckAlgParamsConfig
*                
* Description:   Check specific Id of AlgParams  
*                
* Inputs:        AlgParamsId 
*                   
* Outputs:       E_OK:in the range 
*                 E_NOT_OK:out of the range 
* 
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(Std_ReturnType, RAMTST_CODE) RamTst_CheckAlgParamsConfig
(
    RamTst_AlgParamsIdType AlgParamsId
)
{
    Std_ReturnType ret = E_NOT_OK;
    
    if((AlgParamsId > (RamTst_AlgParamsIdType)0) && (AlgParamsId <= RamTstConfig.NumberOfAlgParamSets))
    {
        ret = E_OK;
    }

    return ret;
}


/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: RamTst_TestRam
*                
* Description:   service to test specified appointed memory address 
*                
* Inputs:        RamTst_TestContextType
*                 RamTst_NumberOfTestedCellsType
*                   
* Outputs:       None
* 
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, RAMTST_CODE) RamTst_TestRam
(
    P2CONST(RamTst_TestContextType, AUTOMATIC, AUTOMATIC) CtxPtr,
    uint32 NumberOfCells
)
{
    RamTst_TestResultType result;
    const RamTst_AlgorithmFunType algorithm = RamTstAlgorithm[RamTst_AlgParams->Algorithm];
    uint32 number;
    uint32 address = CtxPtr->Address;
    uint32 tempNumberOfCells = NumberOfCells;

    /*use the algorithm test NumberOfCells of block*/
    do
    {
        SchM_Enter_RamTst_RAMTST_EXCLUSIVE_AREA_0();
        result = algorithm(address,&number);
        SchM_Exit_RamTst_RAMTST_EXCLUSIVE_AREA_0();
        if (result != RAMTST_RESULT_OK)
        {
            RamTstBlockTestResult[((CtxPtr->BlockId)-(RamTst_NumberOfBlocksType)1)] = RAMTST_RESULT_NOT_OK;
            if (RamTstConfig.TestErrorNotification != NULL_PTR)
            {
                RamTstConfig.TestErrorNotification();
            }
            break;
        }
        
        if(tempNumberOfCells < number)
        {
            tempNumberOfCells = (uint32)0;
        }
        else
        {
            tempNumberOfCells -= number;
            address += number;
        }
    }
    while((RamTst_ExecutionStatus == RAMTST_EXECUTION_RUNNING) && (tempNumberOfCells > (uint32)0));

    return ;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: RamTst_UpdateContext
*                
* Description:   service updata the test's start address and  remain cells
*                
* Inputs:        RamTst_TestContextType
*                   
* Outputs:       None
* 
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/

STATIC FUNC(void, RAMTST_CODE) RamTst_UpdateContext
(
    P2VAR(RamTst_TestContextType, AUTOMATIC, AUTOMATIC) TestCtxPtr
)
{
    uint32 address;
    uint32 size;
    RamTst_NumberOfBlocksType blockId;
    RamTst_NumberOfBlocksType algParamsBlockId;

    if (TestCtxPtr->AlgParamsBlockId < RamTst_AlgParams->NumberOfBlocks)
    {
        algParamsBlockId = TestCtxPtr->AlgParamsBlockId;
    }
    else
    {
        algParamsBlockId = (RamTst_NumberOfBlocksType)0;
    }

    address = RamTst_AlgParams->BlockParams[algParamsBlockId].StartAddress;
    size = (RamTst_AlgParams->BlockParams[algParamsBlockId].EndAddress + (uint32)1) - address; 
    blockId = RamTst_GetBlockId(algParamsBlockId,RamTst_AlgParams);

    TestCtxPtr->BlockId = blockId;
    TestCtxPtr->Address = address;
    TestCtxPtr->RemainCells = size;
    TestCtxPtr->AlgParamsBlockId = algParamsBlockId;
    
    RamTstBlockTestResult[(blockId-(RamTst_NumberOfBlocksType)1)] = RAMTST_RESULT_UNDEFINED;

    return ;
}

#if (STD_ON == RAMTST_RUN_PARTIAL_TEST_API)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: RamTst_GetAlgParamsBlockId
*                
* Description:   get the BiockId of AlgParams set
*                
* Inputs:        blockId
*                   
* Outputs:       None
* 
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/

STATIC FUNC(RamTst_NumberOfBlocksType, RAMTST_CODE) RamTst_GetAlgParamsBlockId
(
    RamTst_NumberOfBlocksType blockId
)
{
    RamTst_NumberOfBlocksType algParamsBlockId = (RamTst_NumberOfBlocksType)0;
    RamTst_NumberOfBlocksType i;
    
    for(i = (RamTst_NumberOfBlocksType)0; i < RamTst_AlgParams->NumberOfBlocks; i++)
    {
        if(blockId == RamTst_AlgParams->BlockParams[i].BlockId)
        {
            algParamsBlockId = i;
            break;
        }
    }
    return algParamsBlockId; 
}
#endif

#if (STD_ON == RAMTST_RUN_FULL_TEST_API)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: RamTst_RunBlockTest
*                
* Description:   service to test of one block in foreground test 
*                
* Inputs:        BlockId
*                   
* Outputs:       None
* 
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, RAMTST_CODE) RamTst_RunBlockTest
(
    RamTst_NumberOfBlocksType algParamsBlockId
)
{
    RamTst_TestContextType ctx;
    RamTst_TestResultType result;
    const RamTst_AlgorithmFunType algorithm = RamTstAlgorithm[RamTst_AlgParams->Algorithm];/*call the algorithm*/ 
    uint32 number;
    uint32 address;
    
    ctx.AlgParamsBlockId = algParamsBlockId;
    RamTst_UpdateContext(&ctx);

    address = ctx.Address;
    
    /*use the algorithm test NumberOfCells of block*/
    do
    {
        SchM_Enter_RamTst_RAMTST_EXCLUSIVE_AREA_0();
        result = algorithm(address,&number);
        SchM_Exit_RamTst_RAMTST_EXCLUSIVE_AREA_0();
        if (result != RAMTST_RESULT_OK)
        {
            RamTstBlockTestResult[((ctx.BlockId)-(RamTst_NumberOfBlocksType)1)] = RAMTST_RESULT_NOT_OK;
            break;
        }
        
        if(ctx.RemainCells < number)
        {
            ctx.RemainCells = (uint32)0;
        }
        else
        {
            ctx.RemainCells -= number;
            address += number;
        }
    }while((RamTst_ExecutionStatus == RAMTST_EXECUTION_RUNNING) && (ctx.RemainCells > (uint32)0));
    
    return ;
}
#endif
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: RamTst_InitResult
*                
* Description:   service for Test Result initialization
*                
* Inputs:        none
*                   
* Outputs:       None
* 
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/

STATIC FUNC(void, RAMTST_CODE) RamTst_InitResult
(
    void
)
{
    RamTst_NumberOfBlocksType i;

    for (i = (RamTst_NumberOfBlocksType)0; i < RAMTST_MAX_NUMBER_OF_BLOCKS; i++)
    {
        RamTstBlockTestResult[i] = RAMTST_RESULT_NOT_TESTED;
    }
    RamTst_ResultFlag = FALSE;
    RamTst_TestResult = RAMTST_RESULT_NOT_TESTED;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: RamTst_GetBlockId
*                
* Description:   service for Get BlockId of RAM
*                
* Inputs:        algParamsBlockId:BlockId of current AlgParams set
*                 AlgParamPtr:current AlgParams set pointer
*                   
* Outputs:       None
* 
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/

STATIC FUNC(RamTst_NumberOfBlocksType, RAMTST_CODE) RamTst_GetBlockId
(
    RamTst_NumberOfBlocksType algParamsBlockId,
    P2CONST(RamTst_ConfigAlgParamsType, AUTOMATIC, RAMTST_CONST) AlgParamPtr
)
{
    RamTst_NumberOfBlocksType blockId;
    
    blockId = AlgParamPtr->BlockParams[algParamsBlockId].BlockId;

    return blockId;
}


#define RAMTST_STOP_SEC_CODE
#include "MemMap.h"


