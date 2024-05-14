/*  BEGIN_FILE_HDR
********************************************************************************
*   NOTICE
*   This software is the property of HiRain Technologies. Any information
*   contained in this doc should not be reproduced, or used, or disclosed
*   without the written authorization from HiRain Technologies.
********************************************************************************
* File Name:       Os_Hook.c
********************************************************************************
* Project/Product: AUTOSAR OS PROJECT
* Title:           Os_Hook.c
* Author:          Hirain
********************************************************************************
* Description:     Counter implement of OS
*
********************************************************************************
* Limitations     : None
*
********************************************************************************
*
********************************************************************************
*   Revision History:
*   Reference to Core Os_Kernel.c File
********************************************************************************
* END_FILE_HDR*/
/*PRQA S 0857 EOF*/
/*
Number of macro definitions exceeds 1024
*/
#include "Os_Internal.h"

/*****************************************************************************
* General QAC Suppression
******************************************************************************/
/*PRQA S 0862 EOF*/
/*
The code segment like:

#define XXX
#include "Os_MemMap.h"

is a part of AUTOSAR specification, but will be an error in PRQA.
*/

/*****************************************************************************
* static macros define
******************************************************************************/
#define OS_HOOK_ERR_PAR_ZERO     0
#define OS_HOOK_ERR_PAR_ONE      1
#define OS_HOOK_ERR_PAR_TWO      2

#define OS_START_SEC_CODE
#include "Os_MemMap.h"
/*****************************************************************************
* OS private code
******************************************************************************/

/*****************************************************************************
* OS internal code
******************************************************************************/

/* BEGIN_FUNCTION_HDR
***********************************************************************************************
* Function Name: OsHook_Init
*
* Description:   init
*
* Inputs:        CoreID
*
* Outputs:       None
*
* Limitations:   None
***********************************************************************************************
END_FUNCTION_HDR*/
FUNC(void, OS_CODE) OsHook_Init
(
    CoreIdType CoreID
)
{
    Os_ErrRecord[CoreID].errCore = OS_INVALID_COREID;
    Os_ErrRecord[CoreID].errDescription = OS_IE_E_OK;
    Os_ErrRecord[CoreID].errPar[OS_HOOK_ERR_PAR_ZERO] = (Os_uint32)0;
    Os_ErrRecord[CoreID].errPar[OS_HOOK_ERR_PAR_ONE] = (Os_uint32)0;
    Os_ErrRecord[CoreID].errPar[OS_HOOK_ERR_PAR_TWO] = (Os_uint32)0;
    Os_ErrRecord[CoreID].error = E_OS_OK;
    Os_ErrRecord[CoreID].serviceId = OSServiceId_NO_SERVICE;

#if((OS_STATUS_LEVEL == OS_EXTENDED) || (OS_ERRORHOOK_SUPPORT == OS_ON))
    Os_ErrNestFlag[CoreID] = OS_FALSE;
#endif /*((OS_STATUS_LEVEL == OS_EXTENDED) || (OS_ERRORHOOK_SUPPORT == OS_ON))*/

}

/* BEGIN_FUNCTION_HDR
***********************************************************************************************
* Function Name: OsHook_FataErrReport
*
* Description:   report error
*
* Inputs:        CoreID,ErrorId,ServiceId,ErrInfo
*
* Outputs:       None
*
* Limitations:   None
***********************************************************************************************
END_FUNCTION_HDR*/
FUNC(void, OS_CODE) OsHook_FataErrReport
(
    CoreIdType CoreID,
    StatusType ErrorID,
    OSServiceIdType ServiceId,
    Os_uint16 ErrInfo,
    Os_uint32 par,
    Os_uint32 par1,
    Os_uint32 par2
)
{
#if(OS_OSAPP_ERRORHOOK_SUPPORT == OS_ON)
    ApplicationType ApplID;
#endif /*(OS_OSAPP_ERRORHOOK_SUPPORT == OS_ON)*/
    Os_ErrRecord[CoreID].errCore = CoreID;
    Os_ErrRecord[CoreID].errDescription = ErrInfo;
    Os_ErrRecord[CoreID].error = ErrorID;
    Os_ErrRecord[CoreID].serviceId = ServiceId;
    Os_ErrRecord[CoreID].errPar[OS_HOOK_ERR_PAR_ZERO] = par;
    Os_ErrRecord[CoreID].errPar[OS_HOOK_ERR_PAR_ONE] = par1;
    Os_ErrRecord[CoreID].errPar[OS_HOOK_ERR_PAR_TWO] = par2;
#if(OS_ERRORHOOK_SUPPORT == OS_ON)
    Os_CurrentContext[CoreID] = OS_CONTEXT_ERRHOOK;
    ErrorHook(ErrorID);
    Os_CurrentContext[CoreID] = OS_CONTEXT_KERNEL;/* Fatal error always return kernal context*/
#endif /*(OS_ERRORHOOK_SUPPORT == OS_ON)*/
#if(OS_OSAPP_ERRORHOOK_SUPPORT == OS_ON)
    ApplID = Os_CurrentApplicationId[CoreID];
    if(ApplID != OS_INVALID_OSAPPLICATION)
    {
        OsHook_AppErrorHook(CoreID, ErrorID, ApplID);
    }
#endif /*(OS_OSAPP_ERRORHOOK_SUPPORT == OS_ON)*/
#if(OS_USED_CORE_NUMBER > 1)
    OsMultiCore_InternalShutdownAllCores(CoreID, ErrorID);
#else
    OsKernel_InternalShutdown(CoreID, ErrorID, INDIVIDUAL_SHUTDOWN);
#endif /*(OS_USED_CORE_NUMBER > 1)*/
    /* dead loop */
    for(;;)
    {
    }
}

/* BEGIN_FUNCTION_HDR
***********************************************************************************************
* Function Name: OsHook_ReportError
*
* Description:   report error
*
* Inputs:        CoreID,ErrorId,ServiceId,ErrInfo
*
* Outputs:       None
*
* Limitations:   None
***********************************************************************************************
END_FUNCTION_HDR*/
#if((OS_STATUS_LEVEL == OS_EXTENDED) || (OS_ERRORHOOK_SUPPORT == OS_ON))
FUNC(void, OS_CODE) OsHook_ReportError
(
    CoreIdType CoreID,
    StatusType ErrorID,
    OSServiceIdType ServiceId,
    Os_uint16 ErrInfo,
    Os_uint32 par,
    Os_uint32 par1,
    Os_uint32 par2
)
{
    Os_boolean tempPri;
#if(OS_ERRORHOOK_SUPPORT == OS_ON)
    Os_uint16 tempCtx = Os_CurrentContext[CoreID];
#endif /*(OS_ERRORHOOK_SUPPORT == OS_ON)*/
#if(OS_OSAPP_ERRORHOOK_SUPPORT == OS_ON)
    ApplicationType ApplID;
#endif /*(OS_OSAPP_ERRORHOOK_SUPPORT == OS_ON)*/
    if(Os_ErrNestFlag[CoreID] == OS_TRUE)
    {
        /* nest call this err, for example, API called in errhook */
        return;
    }
    OsCpu_EnterCritical(CoreID, &tempPri);/*some cases may nest call OsCpu_EnterCritical here, but it's ok*/
    Os_ErrNestFlag[CoreID] = OS_TRUE;
    Os_ErrRecord[CoreID].errCore = CoreID;
    Os_ErrRecord[CoreID].errDescription = ErrInfo;
    Os_ErrRecord[CoreID].error = ErrorID;
    Os_ErrRecord[CoreID].serviceId = ServiceId;
    Os_ErrRecord[CoreID].errPar[OS_HOOK_ERR_PAR_ZERO] = par;
    Os_ErrRecord[CoreID].errPar[OS_HOOK_ERR_PAR_ONE] = par1;
    Os_ErrRecord[CoreID].errPar[OS_HOOK_ERR_PAR_TWO] = par2;
#if(OS_ERRORHOOK_SUPPORT == OS_ON)
    Os_CurrentContext[CoreID] = OS_CONTEXT_ERRHOOK;
    ErrorHook(ErrorID);
    Os_CurrentContext[CoreID] = tempCtx;
#endif /*f(OS_ERRORHOOK_SUPPORT == OS_ON)*/
#if(OS_OSAPP_ERRORHOOK_SUPPORT == OS_ON)
    ApplID = Os_CurrentApplicationId[CoreID];
    if(ApplID != OS_INVALID_OSAPPLICATION)
    {
        OsHook_AppErrorHook(CoreID, ErrorID, ApplID);
    }
#endif /*(OS_OSAPP_ERRORHOOK_SUPPORT == OS_ON)*/
    Os_ErrNestFlag[CoreID] = OS_FALSE;
    OsCpu_ExitCritical(CoreID, tempPri);
}

/* BEGIN_FUNCTION_HDR
***********************************************************************************************
* Function Name: OsHook_ReportErrorDisInt
*
* Description:   report error
*
* Inputs:        CoreID,ErrorId,ServiceId,ErrInfo
*
* Outputs:       None
*
* Limitations:   None
***********************************************************************************************
END_FUNCTION_HDR*/
FUNC(void, OS_CODE) OsHook_ReportErrorDisInt
(
    CoreIdType CoreID,
    StatusType ErrorID,
    OSServiceIdType ServiceId,
    Os_uint16 ErrInfo,
    Os_uint32 par,
    Os_uint32 par1,
    Os_uint32 par2
)
{
#if(OS_ERRORHOOK_SUPPORT == OS_ON)
    Os_uint16 tempCtx = Os_CurrentContext[CoreID];
#endif /*(OS_ERRORHOOK_SUPPORT == OS_ON)*/
#if(OS_OSAPP_ERRORHOOK_SUPPORT == OS_ON)
    ApplicationType ApplID;
#endif /*(OS_OSAPP_ERRORHOOK_SUPPORT == OS_ON)*/
    if(Os_ErrNestFlag[CoreID] == OS_TRUE)
    {
        /* nest call this err, for example, API called in errhook */
        return;
    }
    Os_ErrNestFlag[CoreID] = OS_TRUE;
    Os_ErrRecord[CoreID].errCore = CoreID;
    Os_ErrRecord[CoreID].errDescription = ErrInfo;
    Os_ErrRecord[CoreID].error = ErrorID;
    Os_ErrRecord[CoreID].serviceId = ServiceId;
    Os_ErrRecord[CoreID].errPar[OS_HOOK_ERR_PAR_ZERO] = par;
    Os_ErrRecord[CoreID].errPar[OS_HOOK_ERR_PAR_ONE] = par1;
    Os_ErrRecord[CoreID].errPar[OS_HOOK_ERR_PAR_TWO] = par2;
#if(OS_ERRORHOOK_SUPPORT == OS_ON)
    Os_CurrentContext[CoreID] = OS_CONTEXT_ERRHOOK;
    ErrorHook(ErrorID);
    Os_CurrentContext[CoreID] = tempCtx;
#endif /*(OS_ERRORHOOK_SUPPORT == OS_ON)*/
#if(OS_OSAPP_ERRORHOOK_SUPPORT == OS_ON)
    ApplID = Os_CurrentApplicationId[CoreID];
    if(ApplID != OS_INVALID_OSAPPLICATION)
    {
        OsHook_AppErrorHook(CoreID, ErrorID, ApplID);
    }
#endif /*(OS_OSAPP_ERRORHOOK_SUPPORT == OS_ON)*/
    Os_ErrNestFlag[CoreID] = OS_FALSE;
}
#endif /*((OS_STATUS_LEVEL == OS_EXTENDED) || (OS_ERRORHOOK_SUPPORT == OS_ON))*/

/* BEGIN_FUNCTION_HDR
***********************************************************************************************
* Function Name: OsHook_StartupHook
*
* Description:   StartupHook
*
* Inputs:        CoreID
*
* Outputs:       None
*
* Limitations:   None
***********************************************************************************************
END_FUNCTION_HDR*/
#if(OS_STARTUPHOOK_SUPPORT == OS_ON)
FUNC(void, OS_CODE) OsHook_StartupHook
(
    CoreIdType CoreID
)
{
    Os_uint16 tempCtx = Os_CurrentContext[CoreID];

    Os_CurrentContext[CoreID] = OS_CONTEXT_STARTUPHOOK;
    StartupHook();
    Os_CurrentContext[CoreID] = tempCtx;
}
#endif /*(OS_STARTUPHOOK_SUPPORT == OS_ON)*/

/* BEGIN_FUNCTION_HDR
***********************************************************************************************
* Function Name: OsHook_ShutdownHook
*
* Description:   ShutdownHook
*
* Inputs:        CoreID, Error
*
* Outputs:       None
*
* Limitations:   None
***********************************************************************************************
END_FUNCTION_HDR*/
#if(OS_SHUTDOWNHOOK_SUPPORT == OS_ON)
FUNC(void, OS_CODE) OsHook_ShutdownHook
(
    CoreIdType CoreID,
    StatusType Error
)
{
    Os_uint16 tempCtx = Os_CurrentContext[CoreID];

    Os_CurrentContext[CoreID] = OS_CONTEXT_SHUTDOWNHOOK;
    ShutdownHook(Error);
    Os_CurrentContext[CoreID] = tempCtx;
}
#endif /*(OS_SHUTDOWNHOOK_SUPPORT == OS_ON)*/

/* BEGIN_FUNCTION_HDR
***********************************************************************************************
* Function Name: OsHook_PreTaskHook
*
* Description:   PreTaskHook
*
* Inputs:        CoreID
*
* Outputs:       None
*
* Limitations:   None
***********************************************************************************************
END_FUNCTION_HDR*/
#if(OS_PRETASKHOOK_SUPPORT == OS_ON)
FUNC(void, OS_CODE) OsHook_PreTaskHook
(
    CoreIdType CoreID
)
{
    Os_uint16 tempCtx = Os_CurrentContext[CoreID];

    Os_CurrentContext[CoreID] = OS_CONTEXT_PRETASKHOOK;
    PreTaskHook();
    Os_CurrentContext[CoreID] = tempCtx;
}
#endif /*(OS_PRETASKHOOK_SUPPORT == OS_ON)*/

/* BEGIN_FUNCTION_HDR
***********************************************************************************************
* Function Name: OsHook_PostTaskHook
*
* Description:   OsHook_PostTaskHook
*
* Inputs:        CoreID
*
* Outputs:       None
*
* Limitations:   None
***********************************************************************************************
END_FUNCTION_HDR*/
#if(OS_POSTTASKHOOK_SUPPORT == OS_ON)
FUNC(void, OS_CODE) OsHook_PostTaskHook
(
    CoreIdType CoreID
)
{
    Os_uint16 tempCtx = Os_CurrentContext[CoreID];

    Os_CurrentContext[CoreID] = OS_CONTEXT_POSTTASKHOOK;
    PostTaskHook();
    Os_CurrentContext[CoreID] = tempCtx;
}
#endif /*(OS_POSTTASKHOOK_SUPPORT == OS_ON)*/

/* BEGIN_FUNCTION_HDR
***********************************************************************************************
* Function Name: OsHook_PreISRHook
*
* Description:   PreISRHook
*
* Inputs:        CoreID
*
* Outputs:       None
*
* Limitations:   None
***********************************************************************************************
END_FUNCTION_HDR*/
#if(OS_PREISRHOOK_SUPPORT == OS_ON)
FUNC(void, OS_CODE) OsHook_PreISRHook
(
    CoreIdType CoreID
)
{
    Os_uint16 tempCtx = Os_CurrentContext[CoreID];

    Os_CurrentContext[CoreID] = OS_CONTEXT_PREISRHOOK;
    PreISRHook();
    Os_CurrentContext[CoreID] = tempCtx;
}
#endif /*(OS_PREISRHOOK_SUPPORT == OS_ON)*/

/* BEGIN_FUNCTION_HDR
***********************************************************************************************
* Function Name: OsHook_PostISRHook
*
* Description:   OsHook_PostISRHook
*
* Inputs:        CoreID
*
* Outputs:       None
*
* Limitations:   None
***********************************************************************************************
END_FUNCTION_HDR*/
#if(OS_POSTISRHOOK_SUPPORT == OS_ON)
FUNC(void, OS_CODE) OsHook_PostISRHook
(
    CoreIdType CoreID
)
{
    Os_uint16 tempCtx = Os_CurrentContext[CoreID];

    Os_CurrentContext[CoreID] = OS_CONTEXT_POSTISRHOOK;
    PostISRHook();
    Os_CurrentContext[CoreID] = tempCtx;
}
#endif /*(OS_POSTISRHOOK_SUPPORT == OS_ON)*/

/* BEGIN_FUNCTION_HDR
***********************************************************************************************
* Function Name: OsHook_ProtectionHook
*
* Description:   ProtectionHook
*
* Inputs:        CoreID,FatalError
*
* Outputs:       None
*
* Limitations:   None
***********************************************************************************************
END_FUNCTION_HDR*/
FUNC(void, OS_CODE) OsHook_ProtectionHook
(
    CoreIdType CoreID,
    StatusType FatalError
)
{
#if(OS_PROTECTIONHOOK_SUPPORT == OS_ON)
    Os_boolean shutdownFlag = OS_FALSE;
    Os_uint16 tempCtx = Os_CurrentContext[CoreID];
    ProtectionReturnType err;
#endif /*(OS_PROTECTIONHOOK_SUPPORT == OS_ON)*/

#if(OS_PROTECTIONHOOK_SUPPORT == OS_ON)
    Os_CurrentContext[CoreID] = OS_CONTEXT_PROTECTIONHOOK;
    err = ProtectionHook(FatalError);
    Os_CurrentContext[CoreID] = OS_CONTEXT_KERNEL;

    switch(err)
    {
    case PRO_IGNORE:
        /*SWS_Os_00106*/
        if(FatalError != E_OS_PROTECTION_ARRIVAL)
        {
            /* Based on AUTOSAR_SWS_OS chapter 7.8.1 ignor only allowed in OS_TP_FRAMECHECK*/
            /* if user return ignor in other case , current OS can not make sure the system can run normally
               so we just shutdown here
            */
            shutdownFlag = OS_TRUE;
        }
        else
        {
            /* do nothing*/
            Os_CurrentContext[CoreID] = tempCtx;
        }
        break;

    case PRO_TERMINATETASKISR:
        /* SWS_Os_00506 */
        if(FatalError == E_OS_PROTECTION_ARRIVAL)
        {
            shutdownFlag = OS_TRUE;
        }
        else
        {
            if((Os_IntNestDepth[CoreID] == OS_INVALID_ISR)&&(Os_CurrentTaskId[CoreID] == OS_INVALID_TASK_ID))
            {
                shutdownFlag = OS_TRUE;
            }

            else
            {
                if(Os_IntNestDepth[CoreID] != OS_INVALID_ISR)/* C2ISR is running*/
                {
                    OsIsr_KillRunningISR(CoreID, Os_CoreCfg[CoreID].nestIsrIdPtr[Os_IntNestDepth[CoreID]], OS_FALSE);
                }
                else
                {
                    OsTask_KillRunningTask(CoreID, OS_FALSE);  
                }
            }

        }
        break;

    case PRO_TERMINATEAPPL:
#if(OS_APPLICATION_NUMBER > 0)
        if(FatalError == E_OS_PROTECTION_ARRIVAL)
        {
            shutdownFlag = OS_TRUE;
        }
        else
        {
            OsApp_InternalTerminateApplication(CoreID, Os_CurrentApplicationId[CoreID], NO_RESTART);
        }
#else
        /*SWS_Os_00244*/
        shutdownFlag = OS_TRUE;
#endif /*(OS_APPLICATION_NUMBER > 0)*/
        break;

    case PRO_TERMINATEAPPL_RESTART:
#if(OS_APPLICATION_NUMBER > 0)
        if(FatalError == E_OS_PROTECTION_ARRIVAL)
        {
            shutdownFlag = OS_TRUE;
        }
        else
        {
            /* if restart task not configure, this fucntion will report fatal errot and shutdown OS*/
            OsApp_InternalTerminateApplication(CoreID, Os_CurrentApplicationId[CoreID], RESTART);
        }
#else
        /*SWS_Os_00244*/
        shutdownFlag = OS_TRUE;
#endif /*(OS_APPLICATION_NUMBER > 0)*/
        break;

    default:
        /* in case user return PRO_SHUTDOWN or other invalid value , we just shutdown here*/
        shutdownFlag = OS_TRUE;
        break;
    }

    if(OS_TRUE == shutdownFlag)
#endif /*(OS_PROTECTIONHOOK_SUPPORT == OS_ON)*/
    {
        /* if do not support protection hook, just shutdown here */
#if(OS_USED_CORE_NUMBER > 1)
        OsMultiCore_InternalShutdownAllCores(CoreID, FatalError);
#else
        OsKernel_InternalShutdown(CoreID, FatalError, INDIVIDUAL_SHUTDOWN);
#endif /*(OS_USED_CORE_NUMBER > 1)*/
        for(;;)
        {
        }
    }
}

/* BEGIN_FUNCTION_HDR
***********************************************************************************************
* Function Name: OsHook_AppStartupHook
*
* Description:   StartupHook of application
*
* Inputs:        CoreID,ApplID
*
* Outputs:       None
*
* Limitations:   None
***********************************************************************************************
END_FUNCTION_HDR*/
#if(OS_OSAPP_STARTUPHOOK_SUPPORT == OS_ON)
FUNC(void, OS_CODE) OsHook_AppStartupHook
(
    CoreIdType CoreID,
    ApplicationType ApplID
)
{
    Os_uint16 tempCtx = Os_CurrentContext[CoreID];

    if(Os_AppCfg[ApplID].StartupHookFunc != OS_NULL)
    {
        Os_CurrentContext[CoreID] = OS_CONTEXT_STARTUPHOOK;
        Os_AppCfg[ApplID].StartupHookFunc();
        Os_CurrentContext[CoreID] = tempCtx;
    }
}
#endif /*(OS_OSAPP_STARTUPHOOK_SUPPORT == OS_ON)*/

/* BEGIN_FUNCTION_HDR
***********************************************************************************************
* Function Name: OsHook_AppShutdownHook
*
* Description:   ShutdownHook of application
*
* Inputs:        CoreID,ApplID
*
* Outputs:       None
*
* Limitations:   None
***********************************************************************************************
END_FUNCTION_HDR*/
#if(OS_OSAPP_SHUTDOWNHOOK_SUPPORT == OS_ON)
FUNC(void, OS_CODE) OsHook_AppShutdownHook
(
    CoreIdType CoreID,
    StatusType ErrorID,
    ApplicationType ApplID
)
{
    Os_uint16 tempCtx = Os_CurrentContext[CoreID];
    if(Os_AppCfg[ApplID].ShutdownHookFunc != OS_NULL)
    {
        Os_CurrentContext[CoreID] = OS_CONTEXT_SHUTDOWNHOOK;
        Os_AppCfg[ApplID].ShutdownHookFunc(ErrorID);
        Os_CurrentContext[CoreID] = tempCtx;
    }
}
#endif /*(OS_OSAPP_SHUTDOWNHOOK_SUPPORT == OS_ON)*/

/* BEGIN_FUNCTION_HDR
***********************************************************************************************
* Function Name: OsHook_AppErrorHook
*
* Description:   ErrorHook of application
*
* Inputs:        CoreID, ApplID
*
* Outputs:       None
*
* Limitations:   None
***********************************************************************************************
END_FUNCTION_HDR*/
#if(OS_OSAPP_ERRORHOOK_SUPPORT == OS_ON)
FUNC(void, OS_CODE) OsHook_AppErrorHook
(
    CoreIdType CoreID,
    StatusType ErrorID,
    ApplicationType ApplID
)
{
    Os_uint16 tempCtx = Os_CurrentContext[CoreID];

    if(Os_AppCfg[ApplID].ErrorHookFunc != OS_NULL)
    {
        Os_CurrentContext[CoreID] = OS_CONTEXT_ERRHOOK;
        Os_AppCfg[ApplID].ErrorHookFunc(ErrorID);
        Os_CurrentContext[CoreID] = tempCtx;
    }
}
#endif /*(OS_OSAPP_ERRORHOOK_SUPPORT == OS_ON)*/

/*****************************************************************************
* API code
******************************************************************************/

#define OS_STOP_SEC_CODE
#include "Os_MemMap.h"
