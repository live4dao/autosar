/*  BEGIN_FILE_HDR
********************************************************************************
*   NOTICE
*   This software is the property of HiRain Technologies. Any information
*   contained in this doc should not be reproduced, or used, or disclosed
*   without the written authorization from HiRain Technologies.
********************************************************************************
* File Name:       Os_Application.c
********************************************************************************
* Project/Product: AUTOSAR OS PROJECT
* Title:           Os_Application.c
* Author:          Hirain
********************************************************************************
* Description:     Application implement of OS
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

/*PRQA S 3119 EOF*/
/*
Some parameters will not be used in different configurations and hardware 
platforms, but they can not be deleted according to the requirements of 
AUTOSAR specification or compatibility. So we retain these parameters for 
compatibility and convert them with (void) to clean the warnings in compiler.
PRQA notices such statements as warning 3119, it has been suppressed here.
*/

#if(OS_APPLICATION_NUMBER > 0)
/*****************************************************************************
* static variables define
******************************************************************************/
#if(OS_TRUSTED_FUNCTION_NUMBER > 0)
#define OS_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap.h"
/* Used to store trust function's ApplID */
STATIC VAR(ApplicationType, OS_VAR)  OsApp_TrustFunApplicationId[OS_USED_CORE_NUMBER];
#define OS_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap.h"
#endif /*(OS_TRUSTED_FUNCTION_NUMBER > 0)*/

#define OS_START_SEC_CODE
#include "Os_MemMap.h"
/*****************************************************************************
* OS private code
******************************************************************************/
STATIC FUNC(Os_boolean, OS_CODE) OsApp_CheckObjectId
(
    ObjectTypeType ObjectType,
    Os_ObjectIdType ObjectId
);

/* BEGIN_FUNCTION_HDR
***********************************************************************************************
* Function Name: OsApp_CheckObjectId
*
* Description:   Th
*
* Inputs:        None
*
* Outputs:       TRUE: object valid; False:object not valid;
*
* Limitations:   None
***********************************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(Os_boolean, OS_CODE) OsApp_CheckObjectId
(
    ObjectTypeType ObjectType,
    Os_ObjectIdType ObjectId
)
{
    Os_boolean ret = OS_TRUE;

    switch (ObjectType)
    {
    case OBJECT_TASK:
        /*SWS_Os_00423*/
        if(ObjectId >= (Os_ObjectIdType)OS_TASK_NUMBER) /* Idle Task can also be checked*/
        {
            ret = OS_FALSE;
        }
        break;

    case OBJECT_ISR:
        /*SWS_Os_00423*/
        if(ObjectId >= (Os_ObjectIdType)OS_ISR_NUMBER)
        {
            ret = OS_FALSE;
        }
        break;
#if(OS_ALARM_NUMBER > 0)
    case OBJECT_ALARM:
        /*SWS_Os_00423*/
        if (ObjectId >= (Os_ObjectIdType)OS_ALARM_NUMBER)
        {
            ret = OS_FALSE;
        }
        break;
#endif /*(OS_ALARM_NUMBER > 0)*/

#if(OS_RESOURCE_NUMBER > 0)
    case OBJECT_RESOURCE:
        /*SWS_Os_00423*/
        if (ObjectId >= (Os_ObjectIdType)OS_RESOURCE_NUMBER)
        {
            ret = OS_FALSE;
        }
        break;
#endif /*(OS_RESOURCE_NUMBER > 0)*/

    case OBJECT_COUNTER:
        /*SWS_Os_00423*/
        if (ObjectId >= (Os_ObjectIdType)OS_COUNTER_NUMBER)
        {
            ret = OS_FALSE;
        }
        break;

#if(OS_SCHTBL_NUMBER > 0)
    case OBJECT_SCHEDULETABLE:
        /*SWS_Os_00423*/
        if (ObjectId >= (Os_ObjectIdType)OS_SCHTBL_NUMBER)
        {
            ret = OS_FALSE;
        }
        break;
#endif /*(OS_SCHTBL_NUMBER > 0)*/

    default:
        ret = OS_FALSE;
        break;
    }

    return ret;
}

/*****************************************************************************
* OS internal code
******************************************************************************/
/* BEGIN_FUNCTION_HDR
***********************************************************************************************
* Function Name: OsApp_Init
*
* Description:   Init function
*
* Inputs:        CoreID
*
* Outputs:       None
*
* Limitations:   None
***********************************************************************************************
END_FUNCTION_HDR*/
FUNC(void, OS_CODE) OsApp_Init
(
    CoreIdType CoreID
)
{
    ApplicationType appIdx;
    ApplicationType endAppId;

#if(OS_TRUSTED_FUNCTION_NUMBER > 0)
    OsApp_TrustFunApplicationId[CoreID] = OS_INVALID_OSAPPLICATION;
#endif /*(OS_TRUSTED_FUNCTION_NUMBER > 0)*/

    endAppId = Os_CoreCfg[CoreID].startAppId + Os_CoreCfg[CoreID].appNum;

    for(appIdx = Os_CoreCfg[CoreID].startAppId; appIdx < endAppId; appIdx++)
    {
        Os_AppCBTable[appIdx].appState = APPLICATION_ACCESSIBLE;
    }
}

/* BEGIN_FUNCTION_HDR
***********************************************************************************************
* Function Name: OsApp_InternalTerminateApplication
*
* Description:   This service called in TerminateApplication, protection hook, and crosscore opration
*
* Inputs:        Application The identifier of the OS-Application to be terminated. If the caller
*                            belongs to <Application> the call results in a self termination.
*                RestartOption Either RESTART for doing a restart of the OS-Application or
*                              NO_RESTART if OS-Application shall not be restarted.
*
* Outputs:       None
*
* Limitations:   None
***********************************************************************************************
END_FUNCTION_HDR*/
FUNC(void, OS_CODE) OsApp_InternalTerminateApplication
(
    CoreIdType CoreID,
    ApplicationType Application,
    RestartType RestartOption
)
{
    AlarmType alarmIdx;
    TaskType  taskIdx;

    /*PRQA S 4643 ++*/
    /* Do not include <ctype.h> */
    ISRType   isrIdx;
    /*PRQA S 4643 --*/
    
    ISRType   tempCurIsr;
#if(OS_SCHTBL_NUMBER > 0)
    ScheduleTableType schTblIdx;
#endif /*(OS_SCHTBL_NUMBER > 0)*/

#if(OS_ON == OS_OSAPP_RESTARTTASK_SUPPORT)
    TaskType reTask;
#else
    (void)RestartOption;
#endif /*(OS_ON == OS_OSAPP_RESTARTTASK_SUPPORT)*/
    
    tempCurIsr = OS_INVALID_ISR;

    /* runtime check */
#if(OS_ALARM_NUMBER > 0)
    /* Kill all alarm of this APP*/
    for(alarmIdx = (AlarmType)0; alarmIdx < Os_AppCfg[Application].alarmNum; alarmIdx++)
    {
        OsAlarm_KillAlarm(CoreID, Os_AppCfg[Application].alarmOfApp[alarmIdx]);
    }
#else
    (void) alarmIdx;
#endif /*(OS_ALARM_NUMBER > 0)*/
#if(OS_SCHTBL_NUMBER > 0)
    /* Kill all schtbl of this APP*/
    for(schTblIdx = (ScheduleTableType)0; schTblIdx < Os_AppCfg[Application].schTblNum; schTblIdx++)
    {
        OsSchTbl_Kill(CoreID, Os_AppCfg[Application].schTblOfApp[schTblIdx]);
    } 
#endif /*(OS_SCHTBL_NUMBER > 0)*/
    if(Os_IntNestDepth[CoreID] != OS_INVALID_ISR)
    {
        tempCurIsr = Os_CoreCfg[CoreID].nestIsrIdPtr[Os_IntNestDepth[CoreID]];
    }
    
    /* kill all non running ISR of this app*/
    for(isrIdx = (ISRType)0; isrIdx < Os_AppCfg[Application].isrNum; isrIdx++)
    {
        /* this kill function will not process running state ISR*/
        OsIsr_KillISR(CoreID, Os_AppCfg[Application].isrOfApp[isrIdx]);
    }

    /* remove ISR from ISR nest queue, then resort queue*/
    /* this will remove all ISR of app from queue, including the current ISR, so must get current ISR before*/
    OsIsr_RemoveAndSortISRQueue(CoreID, Application);

    /* kill all non running task of this app*/
    for(taskIdx = (TaskType)0; taskIdx < Os_AppCfg[Application].taskNum; taskIdx++)
    {
        /* this kill function will not process running state Task*/
        OsTask_KillTask(CoreID, Os_AppCfg[Application].taskOfApp[taskIdx]);         
    }

#if(OS_ON == OS_OSAPP_RESTARTTASK_SUPPORT)
    if(RESTART == RestartOption)
    {
        /* when restart ,not call OsHook_AppShutdownHook */
        Os_AppCBTable[Application].appState = APPLICATION_RESTARTING;
        /* as the restart task must belong to the app, so it has been killed before.
           so this task is ok to be activate.( all task state and active times has been reset).
           but isKilled flag is True now, so we need set it false to make sure restart task can be active
           then the isKilled flag will set back to true, to avoid user active this task
        */
        /*
            if the restart task is running( for example, user call terminateApp in restart task again)
            then the restart task must be config to task which support more than 1 time activate
        */
        reTask = Os_AppCfg[Application].restartTask;
        if(reTask == OS_INVALID_TASK_ID)/* may call this function in prtection hook, so we need to check restart task id again here*/
        {
            Os_AppCBTable[Application].appState = APPLICATION_TERMINATED;
            OsHook_FataErrReport(CoreID, E_OS_SYSFATA_RESTART_TASK_INVALID, OSServiceId_OsApp_InternalTerminateApplication, OS_IE_NOMORE_INFO, (Os_uint32)Application, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR);
        }
        Os_TaskCBTable[reTask].isKilled = OS_FALSE;
        /*PRQA S 3416 ++*/
        /* The side effect of "OsTask_InternalActivateTask" is expected. */
        if(E_OS_OK != OsTask_InternalActivateTask(CoreID, reTask, OS_FALSE, OSServiceId_ActivateTask))
        {
        /*PRQA S 3416 --*/
            OsHook_FataErrReport(CoreID, E_OS_SYSFATA_RESTART_TASK_FAIL, OSServiceId_OsApp_InternalTerminateApplication, OS_IE_NOMORE_INFO, (Os_uint32)Application, (Os_uint32)reTask, OS_IE_NO_ERRPAR);
        }
        /* dont kill restart task, allow user to use this restart task to check condition */
    }
    else
#endif /*(OS_ON == OS_OSAPP_RESTARTTASK_SUPPORT)*/
    {
#if(OS_OSAPP_SHUTDOWNHOOK_SUPPORT == OS_ON)
        OsHook_AppShutdownHook(CoreID, E_OS_SYS_SHUTDOWN_BY_TERMINATE_APP, Application);
#endif /*(OS_OSAPP_SHUTDOWNHOOK_SUPPORT == OS_ON)*/
        Os_AppCBTable[Application].appState = APPLICATION_TERMINATED;
    }

    /* self killing, kill the current running Task or ISR at last*/
    if(Application == Os_CurrentApplicationId[CoreID])
    {
        /* get current running task or ISR */
        /* if tp using C1ISR, this function may called in C1ISR context
        so we do not use Os_CurrentContext to get current task or ISR
        */

        if(tempCurIsr != OS_INVALID_ISR) /* C2ISR is running*/
        {
            OsIsr_KillRunningISR(CoreID, tempCurIsr, OS_TRUE);
        }
        else /* task is running*/
        {
            OsTask_KillRunningTask(CoreID, OS_TRUE);
        }
        /* never reach here, as schedule will be done at the end of kill */
        OsHook_FataErrReport(CoreID, E_OS_SYSFATA_UNREACHABLE, OSServiceId_OsApp_InternalTerminateApplication, OS_IE_NOMORE_INFO, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR);
    }

}


/*****************************************************************************
* OS API code
******************************************************************************/
/* BEGIN_FUNCTION_HDR
***********************************************************************************************
* Function Name: OS_GetApplicationID    SWS_Os_00016
*
* Description:   This service determines the OS-Application (a unique identifier has to be allocated
*                to each application) where the caller originally belongs to (was configured to)
*
* Inputs:        None
*
* Outputs:       None
*
* Limitations:   None
***********************************************************************************************
END_FUNCTION_HDR*/
FUNC(ApplicationType, OS_CODE) Os_GetApplicationID
(
    void
)
{
    CoreIdType CoreID;
    ApplicationType ApplID = OS_INVALID_OSAPPLICATION;

    CoreID = OsCpu_GetCoreID();

#if(OS_STATUS_LEVEL == OS_EXTENDED)
    if((CoreID >= (CoreIdType)OS_USED_CORE_NUMBER) || (Os_CoreState[CoreID] != OS_CORE_START))
    {
        /* can not record err in this state, as OS services can not be called*/
    }

    else if((Os_uint16)(Os_CurrentContext[CoreID] & Os_GetApplicationIDMask) == (Os_uint16)0)
    {
        OsHook_ReportError(CoreID, E_OS_CALLEVEL, OSServiceId_GetApplicationID, OS_IE_NOMORE_INFO, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR);
    }

    /* Check whether this API is called between interrupt processing APIs*/
    else if(OS_NO_API_USED != Os_IntAPIUsedFlag[CoreID])
    {
        /* System error -- this API is called between interrupt processing function pairs */
        OsHook_ReportError(CoreID, E_OS_DISABLEDINT, OSServiceId_GetApplicationID, OS_IE_NOMORE_INFO, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR);
    }
    else    
#endif /*(OS_STATUS_LEVEL == OS_EXTENDED)*/
    {
        /*SWS_Os_00261*/
        ApplID = Os_CurrentApplicationId[CoreID];
    }

    return ApplID;
}

/* BEGIN_FUNCTION_HDR
***********************************************************************************************
* Function Name: GetCurrentApplicationID    SWS_Os_00797
*
* Description:   This service determines the OS-Application where the caller of the service is
*                currently executing.
*                Note that if the caller is not within a CallTrustedFunction() call the value is equal to
*                the result of GetApplicationID().
*
* Inputs:        None
*
* Outputs:       None
*
* Limitations:   None
***********************************************************************************************
END_FUNCTION_HDR*/
FUNC(ApplicationType, OS_CODE) Os_GetCurrentApplicationID
(
    void
)
{
    CoreIdType CoreID;
    Os_boolean tempPri;
    ApplicationType ApplID = OS_INVALID_OSAPPLICATION;

    CoreID = OsCpu_GetCoreID();

#if(OS_STATUS_LEVEL == OS_EXTENDED)
    if((CoreID >= (CoreIdType)OS_USED_CORE_NUMBER) || (Os_CoreState[CoreID] != OS_CORE_START))
    {
        /* can not record err in this state, as OS services can not be called*/
    }

    else if((Os_uint16)(Os_CurrentContext[CoreID] & Os_GetCurrentApplicationIDMask) == (Os_uint16)0)
    {
        OsHook_ReportError(CoreID, E_OS_CALLEVEL, OSServiceId_GetCurrentApplicationID, OS_IE_NOMORE_INFO, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR);
    }

    /* Check whether this API is called between interrupt processing APIs*/
    else if(OS_NO_API_USED != Os_IntAPIUsedFlag[CoreID])
    {
        /* System error -- this API is called between interrupt processing function pairs */
        OsHook_ReportError(CoreID, E_OS_DISABLEDINT, OSServiceId_GetCurrentApplicationID, OS_IE_NOMORE_INFO, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR);
    }
    else
#endif /*(OS_STATUS_LEVEL == OS_EXTENDED)*/
    {
        OsCpu_EnterCritical(CoreID, &tempPri);
#if(OS_TRUSTED_FUNCTION_NUMBER > 0)
        /*SWS_Os_00798*/
        if(OsApp_TrustFunApplicationId[CoreID] != OS_INVALID_OSAPPLICATION)
        {
            /* return AppaId which trust function belongs to, if now is within trust function call*/ 
            ApplID = OsApp_TrustFunApplicationId[CoreID];
        }
        else
#endif /*(OS_TRUSTED_FUNCTION_NUMBER > 0)*/
        {
            ApplID = Os_CurrentApplicationId[CoreID];
        }
        
        OsCpu_ExitCritical(CoreID, tempPri);

    }

    return ApplID;
}

#if(OS_TRUSTED_FUNCTION_NUMBER > 0)
/* BEGIN_FUNCTION_HDR
***********************************************************************************************
* Function Name: Os_CallTrustedFunction
*
* Description:     API function called by Application.This call serves to enter critical sections
*                 in the code that are assigned to the resource.
*
* Inputs:         <FunctionIndex> the index of callfunction.
*                 <FunctionParams> the Parameter of callfunction.
*
* Outputs:         None
*
* Limitations:     None
***********************************************************************************************
END_FUNCTION_HDR*/
FUNC(StatusType, OS_CODE) Os_CallTrustedFunction
(
    TrustedFunctionIndexType FunctionIndex,
    TrustedFunctionParameterRefType FunctionParams
)
{
    CoreIdType CoreID;
    StatusType ret = E_OS_OK;

    CoreID = OsCpu_GetCoreID();

#if(OS_STATUS_LEVEL == OS_EXTENDED)
    if((CoreID >= (CoreIdType)OS_USED_CORE_NUMBER) || (Os_CoreState[CoreID] != OS_CORE_START))
    {
        /* can not record err in this state, as OS services can not be called*/
        ret = E_OS_CORE;
    }

    else if((Os_uint16)(Os_CurrentContext[CoreID] & Os_CallTrustedFuntionMask) == (Os_uint16)0)
    {
        OsHook_ReportError(CoreID, E_OS_CALLEVEL, OSServiceId_CallTrustedFunction, OS_IE_NOMORE_INFO, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR);
        ret = E_OS_CALLEVEL;
    }

    /* Check whether this API is called between interrupt processing APIs*/
    else if(OS_NO_API_USED != Os_IntAPIUsedFlag[CoreID])
    {
        /* System error -- this API is called between interrupt processing function pairs */
        OsHook_ReportError(CoreID, E_OS_DISABLEDINT, OSServiceId_CallTrustedFunction, OS_IE_NOMORE_INFO, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR);
        ret = E_OS_DISABLEDINT;
    }

    else if (FunctionIndex >= (Os_uint8)OS_TRUSTED_FUNCTION_NUMBER)
    {
        OsHook_ReportError(CoreID, E_OS_ID, OSServiceId_CallTrustedFunction, OS_IE_TRUSTFUN_ID, (Os_uint32)FunctionIndex, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR);
        ret = E_OS_ID;
    }
    else
#endif /*(OS_STATUS_LEVEL == OS_EXTENDED)*/
    {
        /*
        CPU has been set to kernel permission when call this API,
        when out of API, permission will restore,
        so dont need to switch any permission in trust function
        */
        /*
        modify OsApp_TrustFunApplicationId to support Os_GetCurrentApplicationID
        */
        OsApp_TrustFunApplicationId[CoreID] = Os_TrustFunCfg[FunctionIndex].ApplID;
        Os_TrustFunCfg[FunctionIndex].FunPtr(FunctionParams);
        OsApp_TrustFunApplicationId[CoreID] = OS_INVALID_OSAPPLICATION;
    }
    return ret;
}
#endif /*(OS_TRUSTED_FUNCTION_NUMBER > 0)*/

/* BEGIN_FUNCTION_HDR
***********************************************************************************************
* Function Name: CheckObjectAccess    SWS_Os_00256
*
* Description:   This service determines if the OS-Applications, given by ApplID, is allowed to use
*                the IDs of a Task, Resource, Counter, Alarm or Schedule Table in API calls.
*
* Inputs:        ApplID OS-Application identifier
*                ObjectType Type of the following parameter
*                ObjectId The object to be examined
*
* Outputs:       None
*
* Limitations:   None
***********************************************************************************************
END_FUNCTION_HDR*/
FUNC(ObjectAccessType, OS_CODE) Os_CheckObjectAccess
(
    ApplicationType ApplID,
    ObjectTypeType ObjectType,
    Os_ObjectIdType ObjectId
)
{
    Os_ApplicationMaskType tmpAppMask;
    Os_ApplicationMaskType temp;
    CoreIdType CoreID;
    Os_boolean tempPri;
    ObjectAccessType ret = NO_ACCESS;

    CoreID = OsCpu_GetCoreID();
#if(OS_STATUS_LEVEL == OS_EXTENDED)
    if((CoreID >= (CoreIdType)OS_USED_CORE_NUMBER) || (Os_CoreState[CoreID] != OS_CORE_START))
    {
        /* can not record err in this state, as OS services can not be called*/
    }

    else if((Os_uint16)(Os_CurrentContext[CoreID] & Os_CheckObjectAccessMask) == (Os_uint16)0)
    {
        OsHook_ReportError(CoreID, E_OS_CALLEVEL, OSServiceId_CheckObjectAccess, OS_IE_NOMORE_INFO, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR);
    }

    /* Check whether this API is called between interrupt processing APIs*/
    else if(OS_NO_API_USED != Os_IntAPIUsedFlag[CoreID])
    {
        /* System error -- this API is called between interrupt processing function pairs */
        OsHook_ReportError(CoreID, E_OS_DISABLEDINT, OSServiceId_CheckObjectAccess, OS_IE_NOMORE_INFO, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR);
    }

        /*SWS_Os_00423*/
    else if(ApplID >= (ApplicationType)OS_APPLICATION_NUMBER)
    {
        OsHook_ReportError(CoreID, E_OS_ID, OSServiceId_CheckObjectAccess, OS_IE_OSAPP_ID, (Os_uint32)ApplID, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR);
    }

    /*PRQA S 3416 ++*/
    /* "OsApp_CheckObjectId" do not have any side effects. */
    else if(OS_FALSE == OsApp_CheckObjectId(ObjectType, ObjectId))
    /*PRQA S 3416 --*/
    {
        OsHook_ReportError(CoreID, E_OS_ID, OSServiceId_CheckObjectAccess, OS_IE_OBJECT_ID, (Os_uint32)ObjectType, ObjectId, OS_IE_NO_ERRPAR);
    }
    /* this API can check object of other core, as it only read some const parameters ,no modify of RAM*/

    else
#endif /*(OS_STATUS_LEVEL == OS_EXTENDED)*/
    {
        OsCpu_EnterCritical(CoreID, &tempPri);
        tmpAppMask = (Os_ApplicationMaskType)0;

        switch (ObjectType)
        {
        case OBJECT_TASK:
            tmpAppMask = Os_TaskCfg[ObjectId].AppMask;
            break;

        case OBJECT_ISR:
            tmpAppMask = OS_APP_ALL_MASK;/* ISR can be accessed by any ISR*/
            break;
#if(OS_ALARM_NUMBER > 0)
        case OBJECT_ALARM:
            tmpAppMask = Os_AlarmCfg[ObjectId].AppMask;
            break;
#endif /*(OS_ALARM_NUMBER > 0)*/
#if(OS_RESOURCE_NUMBER > 0)
        case OBJECT_RESOURCE:
            tmpAppMask = Os_ResourceCfg[ObjectId].AppMask;
            break;
#endif /*(OS_RESOURCE_NUMBER > 0)*/

        case OBJECT_COUNTER:
            tmpAppMask = Os_CounterCfg[ObjectId].AppMask;
            break;

#if(OS_SCHTBL_NUMBER > 0)
        case OBJECT_SCHEDULETABLE:
            tmpAppMask = Os_SchTblCfg[ObjectId].AppMask;
            break;
#endif /*(OS_SCHTBL_NUMBER > 0)*/

        default:
            /* nothing to do, return NO_ACCESS*/
            break;
        }
        temp = (Os_ApplicationMaskType)(((Os_ApplicationMaskType)1) << ApplID);

        if((Os_ApplicationMaskType)0 != (tmpAppMask & temp ))
        {
            ret = ACCESS;
        }
        OsCpu_ExitCritical(CoreID, tempPri);
    }
    return ret;
}

/* BEGIN_FUNCTION_HDR
***********************************************************************************************
* Function Name: CheckObjectOwnership    SWS_Os_00017
*
* Description:   This service determines to which OS-Application a given Task, ISR, Counter,
*                Alarm or Schedule Table belongs
*
* Inputs:        ObjectType Type of the following parameter
*                ObjectId The object to be examined
*
* Outputs:       None
*
* Limitations:   None
***********************************************************************************************
END_FUNCTION_HDR*/
FUNC(ApplicationType, OS_CODE) Os_CheckObjectOwnership
(
    ObjectTypeType ObjectType,
    Os_ObjectIdType ObjectId
)
{
    CoreIdType CoreID;
    Os_boolean tempPri;
    ApplicationType ApplID = OS_INVALID_OSAPPLICATION;

    CoreID = OsCpu_GetCoreID();
#if(OS_STATUS_LEVEL == OS_EXTENDED)
    if((CoreID >= (CoreIdType)OS_USED_CORE_NUMBER) || (Os_CoreState[CoreID] != OS_CORE_START))
    {
        /* can not record err in this state, as OS services can not be called*/
    }

    else if((Os_uint16)(Os_CurrentContext[CoreID] & Os_CheckObjectOwnershipMask) == (Os_uint16)0)
    {
        OsHook_ReportError(CoreID, E_OS_CALLEVEL, OSServiceId_CheckObjectOwnership, OS_IE_NOMORE_INFO, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR);
    }

    /* Check whether this API is called between interrupt processing APIs*/
    else if(OS_NO_API_USED != Os_IntAPIUsedFlag[CoreID])
    {
        /* System error -- this API is called between interrupt processing function pairs */
        OsHook_ReportError(CoreID, E_OS_DISABLEDINT, OSServiceId_CheckObjectOwnership, OS_IE_NOMORE_INFO, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR);
    }

    else if(ObjectType == OBJECT_RESOURCE)/*resource dont belong to any app*/
    {
        OsHook_ReportError(CoreID, E_OS_ID, OSServiceId_CheckObjectOwnership, OS_IE_OBJECT_ID, (Os_uint32)ObjectType, ObjectId, OS_IE_NO_ERRPAR);
    }

    /*PRQA S 3416 ++*/
    /* "OsApp_CheckObjectId" do not have any side effects. */
    else if(OS_FALSE == OsApp_CheckObjectId(ObjectType, ObjectId))
    /*PRQA S 3416 --*/
    {
        OsHook_ReportError(CoreID, E_OS_ID, OSServiceId_CheckObjectOwnership, OS_IE_OBJECT_ID, (Os_uint32)ObjectType, ObjectId, OS_IE_NO_ERRPAR);
    }
    /* this API can check object of other core, as it only read some const parameters ,no modify of RAM*/
    else
#endif /*(OS_STATUS_LEVEL == OS_EXTENDED)*/
    {
        OsCpu_EnterCritical(CoreID, &tempPri);

        switch(ObjectType)
        {
        case OBJECT_TASK:
            ApplID = Os_TaskCfg[ObjectId].ApplID;
            break;

        case OBJECT_ISR:
            ApplID = Os_ISRCfg[ObjectId].ApplID;
            break;
#if(OS_ALARM_NUMBER > 0)
        case OBJECT_ALARM:
            ApplID = Os_AlarmCfg[ObjectId].ApplID;
            break;
#endif /*(OS_ALARM_NUMBER > 0)*/
        case OBJECT_COUNTER:
            ApplID = Os_CounterCfg[ObjectId].ApplID;
            break;

#if(OS_SCHTBL_NUMBER > 0)
        case OBJECT_SCHEDULETABLE:
            ApplID = Os_SchTblCfg[ObjectId].ApplID;
            break;
#endif /*(OS_SCHTBL_NUMBER > 0)*/

        default:
            /* nothing to do, return NO_ACCESS*/
            break;
        }

        OsCpu_ExitCritical(CoreID, tempPri);
    }
    return ApplID;
}


/* BEGIN_FUNCTION_HDR
***********************************************************************************************
* Function Name: Os_GetApplicationState
*
* Description:   This service get state of target application 
*
* Inputs:        Application The OS-Application from which the state is requested
*
* Outputs:       Value The current state of the application
*
* Limitations:   None
***********************************************************************************************
END_FUNCTION_HDR*/
FUNC(StatusType, OS_CODE) Os_GetApplicationState
(
    ApplicationType Application,
    ApplicationStateRefType Value
)
{
    CoreIdType CoreID;
    Os_boolean tempPri;
    StatusType ret = E_OS_OK;

    CoreID = OsCpu_GetCoreID();

#if(OS_STATUS_LEVEL == OS_EXTENDED)
    if((CoreID >= (CoreIdType)OS_USED_CORE_NUMBER) || (Os_CoreState[CoreID] != OS_CORE_START))
    {
        /* can not record err in this state, as OS services can not be called*/
        ret = E_OS_CORE;
    }
    
    else if((Os_uint16)(Os_CurrentContext[CoreID] & Os_GetApplicationStateMask) == (Os_uint16)0)
    {
        OsHook_ReportError(CoreID, E_OS_CALLEVEL, OSServiceId_GetApplicationState, OS_IE_NOMORE_INFO, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR);
        ret = E_OS_CALLEVEL;
    }

    /* Check whether this API is called between interrupt processing APIs*/
    else if(OS_NO_API_USED != Os_IntAPIUsedFlag[CoreID])
    {
        /* System error -- this API is called between interrupt processing function pairs */
        OsHook_ReportError(CoreID, E_OS_DISABLEDINT, OSServiceId_GetApplicationState, OS_IE_NOMORE_INFO, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR);
        ret = E_OS_DISABLEDINT;
    }

    /*SWS_Os_00495*/
    else if(Application >= (ApplicationType) OS_APPLICATION_NUMBER)
    {
        OsHook_ReportError(CoreID, E_OS_ID, OSServiceId_GetApplicationState, OS_IE_OSAPP_ID, (Os_uint32)Application, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR);
        ret = E_OS_ID;
    }
    else if(OS_NULL == Value)
    {
        OsHook_ReportError(CoreID, E_OS_PARAM_POINTER, OSServiceId_GetApplicationState, OS_IE_NOMORE_INFO, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR);
        ret = E_OS_PARAM_POINTER;
    }

#if(OS_USED_CORE_NUMBER > 1)
    /* not support crosscore 
        when reading the state and other core is changing the state, it may cause read out a invalid value
        so we dont suppot cross core in this version
    */
    else if(Os_AppCfg[Application].objCoreId != CoreID)
    {
        OsHook_ReportError(CoreID, E_OS_SYS_SERVICE_NOTSUPPORT_CROSSCORE, OSServiceId_GetApplicationState, OS_IE_NOMORE_INFO, (Os_uint32)Application, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR);
        ret = E_OS_SYS_SERVICE_NOTSUPPORT_CROSSCORE;
    }
#endif /*(OS_USED_CORE_NUMBER > 1)*/
    else
#endif /*(OS_STATUS_LEVEL == OS_EXTENDED)*/
    {
        OsCpu_EnterCritical(CoreID, &tempPri); 
        /*SWS_Os_00496*/
        *Value = Os_AppCBTable[Application].appState;
        OsCpu_ExitCritical(CoreID, tempPri);
    }

    return ret;
}


/* BEGIN_FUNCTION_HDR
***********************************************************************************************
* Function Name: TerminateApplication
*
* Description:   This service terminates the OS-Application to which the calling Task/Category 2
*                ISR/application specific error hook belongs.
*
* Inputs:        Application The identifier of the OS-Application to be terminated. If the caller
*                            belongs to <Application> the call results in a self termination.
*                RestartOption Either RESTART for doing a restart of the OS-Application or
*                              NO_RESTART if OS-Application shall not be restarted.
*
* Outputs:       None
*
* Limitations:   None
***********************************************************************************************
END_FUNCTION_HDR*/
FUNC(StatusType, OS_CODE) Os_TerminateApplication
(
    ApplicationType Application,
    RestartType RestartOption
)
{
    CoreIdType CoreID;
    Os_boolean tempPri;
    StatusType ret = E_OS_OK;

    CoreID = OsCpu_GetCoreID();

#if(OS_STATUS_LEVEL == OS_EXTENDED)
    if((CoreID >= (CoreIdType)OS_USED_CORE_NUMBER) || (Os_CoreState[CoreID] != OS_CORE_START))
    {
        /* can not record err in this state, as OS services can not be called*/
        ret = E_OS_CORE;
    }
    
    else if((Os_uint16)(Os_CurrentContext[CoreID] & Os_TerminateApplicationMask) == (Os_uint16)0)
    {
        OsHook_ReportError(CoreID, E_OS_CALLEVEL, OSServiceId_TerminateApplication, OS_IE_NOMORE_INFO, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR);
        ret = E_OS_CALLEVEL;
    }

    /* Check whether this API is called between interrupt processing APIs*/
    else if(OS_NO_API_USED != Os_IntAPIUsedFlag[CoreID])
    {
        /* System error -- this API is called between interrupt processing function pairs */
        OsHook_ReportError(CoreID, E_OS_DISABLEDINT, OSServiceId_TerminateApplication, OS_IE_NOMORE_INFO, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR);
        ret = E_OS_DISABLEDINT;
    }
    /*SWS_Os_00493 SWS_Os_00459
      RestartOption is enum type do not need to check
    */
    else if(Application >= (ApplicationType) OS_APPLICATION_NUMBER)
    {
        OsHook_ReportError(CoreID, E_OS_ID, OSServiceId_TerminateApplication, OS_IE_OSAPP_ID, (Os_uint32)Application, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR);
        ret = E_OS_ID;
    }

    /*  current application invalid, should not has this case*/
    else if(Os_CurrentApplicationId[CoreID] == OS_INVALID_OSAPPLICATION)
    {
        OsHook_ReportError (CoreID, E_OS_ACCESS, OSServiceId_TerminateApplication, OS_IE_INVALID_OSAPPICATION, (Os_uint32)Os_CurrentApplicationId[CoreID], OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR);
        ret = E_OS_ACCESS;
    }

    /*SWS_Os_00507*/
    else if(Os_AppCBTable[Application].appState == APPLICATION_TERMINATED)
    {
        OsHook_ReportError(CoreID, E_OS_STATE, OSServiceId_TerminateApplication, OS_IE_APP_ALREADY_TERMINATE, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR);
        ret = E_OS_STATE;
    }

    /* need restart, but restart task not config */
#if(OS_ON == OS_OSAPP_RESTARTTASK_SUPPORT)
    else if(( Os_AppCfg[Application].restartTask == OS_INVALID_TASK_ID) && (RestartOption == RESTART))
    {
        OsHook_ReportError(CoreID, E_OS_STATE, OSServiceId_TerminateApplication, OS_IE_APP_NO_RESTART_TASK, (Os_uint32)RestartOption, (Os_uint32)Application, OS_IE_NO_ERRPAR);
        ret = E_OS_STATE;
    }
#endif /*(OS_ON == OS_OSAPP_RESTARTTASK_SUPPORT)*/

    /*SWS_Os_00508*/
    else if((Os_AppCBTable[Application].appState == APPLICATION_RESTARTING) && (Os_CurrentApplicationId[CoreID] != Application))
    {
        OsHook_ReportError(CoreID, E_OS_STATE, OSServiceId_TerminateApplication, OS_IE_APP_RESTART_TERMINATE, (Os_uint32)Os_CurrentApplicationId[CoreID], (Os_uint32)Application, OS_IE_NO_ERRPAR);
        ret = E_OS_STATE;
    }

    /*SWS_Os_00548*/
    else if((Os_AppCBTable[Application].appState == APPLICATION_RESTARTING) && (RestartOption == RESTART))
    {
        OsHook_ReportError(CoreID, E_OS_STATE, OSServiceId_TerminateApplication, OS_IE_APP_ALREADY_RESTART, (Os_uint32)RestartOption, (Os_uint32)Application, OS_IE_NO_ERRPAR);
        ret = E_OS_STATE;
    }

    /*SWS_Os_00494*/
    else if((Os_AppCfg[Os_CurrentApplicationId[CoreID]].isTrusted == OS_FALSE) && (Os_CurrentApplicationId[CoreID] != Application))
    {
        OsHook_ReportError(CoreID, E_OS_ACCESS, OSServiceId_TerminateApplication, OS_IE_TERMINATEAPP_BY_UNTRUST_APP, (Os_uint32)Application, (Os_uint32)Os_CurrentApplicationId[CoreID], OS_IE_NO_ERRPAR);
        ret = E_OS_ACCESS;
    }
    else
#endif /*(OS_STATUS_LEVEL == OS_EXTENDED)*/
    {
        OsCpu_EnterCritical(CoreID, &tempPri);

#if(OS_USED_CORE_NUMBER > 1)
        /* Check whether this API is called from diifferent core*/
        if (CoreID != Os_AppCfg[Application].objCoreId)
        {
            ret = OsMultiCore_TriggerTerminateApplication(CoreID, Application, RestartOption);
        }
        else
#endif /*(OS_USED_CORE_NUMBER > 1)*/
        {
            OsApp_InternalTerminateApplication(CoreID, Application, RestartOption);
        }

        OsCpu_ExitCritical(CoreID, tempPri);
    }
    return ret;
}

/* BEGIN_FUNCTION_HDR
***********************************************************************************************
* Function Name: AllowAccess    SWS_Os_00501
*
* Description:   This service sets the own state of an OS-Application from APPLICATION_RESTARTING
*                to APPLICATION_ACCESSIBLE
*
* Inputs:        None
*
* Outputs:       None
*
* Limitations:   None
***********************************************************************************************
END_FUNCTION_HDR*/
#if(OS_ON == OS_OSAPP_RESTARTTASK_SUPPORT)
FUNC(StatusType, OS_CODE) Os_AllowAccess
(
    void
)
{
    ApplicationType Application;
    CoreIdType CoreID;
    Os_boolean tempPri;
#if(OS_ALARM_NUMBER > 0)

    AlarmType alarmIdx;
#endif /*(OS_ALARM_NUMBER > 0)*/
    TaskType  taskIdx;
    /*PRQA S 4643 ++*/
    /* Do not include <ctype.h> */
    ISRType   isrIdx;
    /*PRQA S 4643 --*/
    ISRType   ISRID;
#if(OS_SCHTBL_NUMBER > 0)
    ScheduleTableType schTblIdx;
#endif /*(OS_SCHTBL_NUMBER > 0)*/
    StatusType ret = E_OS_OK;

    CoreID = OsCpu_GetCoreID();

#if(OS_STATUS_LEVEL == OS_EXTENDED)
    if((CoreID >= (CoreIdType)OS_USED_CORE_NUMBER) || (Os_CoreState[CoreID] != OS_CORE_START))
    {
        /* can not record err in this state, as OS services can not be called*/
        ret = E_OS_CORE;
    }

    else if((Os_uint16)(Os_CurrentContext[CoreID] & Os_AllowAccessMask) == (Os_uint16)0)
    {
        OsHook_ReportError(CoreID, E_OS_CALLEVEL, OSServiceId_AllowAccess, OS_IE_NOMORE_INFO, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR);
        ret = E_OS_CALLEVEL;
    }

    /* Check whether this API is called between interrupt processing APIs*/
    else if(OS_NO_API_USED != Os_IntAPIUsedFlag[CoreID])
    {
        /* System error -- this API is called between interrupt processing function pairs */
        OsHook_ReportError(CoreID, E_OS_DISABLEDINT, OSServiceId_AllowAccess, OS_IE_NOMORE_INFO, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR);
        ret = E_OS_DISABLEDINT;
    }

    /*  current application invalid, should not has this case*/
    else if(Os_CurrentApplicationId[CoreID] == OS_INVALID_OSAPPLICATION)
    {
        OsHook_ReportError (CoreID, E_OS_ACCESS, OSServiceId_AllowAccess, OS_IE_INVALID_OSAPPICATION, (Os_uint32)Os_CurrentApplicationId[CoreID], OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR);
        ret = E_OS_ACCESS;
    }

    /*SWS_Os_00497*/
    else if(Os_AppCBTable[Os_CurrentApplicationId[CoreID]].appState != APPLICATION_RESTARTING)
    {
        OsHook_ReportError (CoreID, E_OS_STATE, OSServiceId_AllowAccess, OS_IE_APP_RESTART_STATE_ERR, (Os_uint32)Os_CurrentApplicationId[CoreID], 
                            (Os_uint32)Os_AppCBTable[Os_CurrentApplicationId[CoreID]].appState, OS_IE_NO_ERRPAR);
        ret = E_OS_STATE;
    }
    
    /* only alow to be called in restart task*/
    else if(Os_CurrentTaskId[CoreID] !=  Os_AppCfg[Os_CurrentApplicationId[CoreID]].restartTask)
    {
        OsHook_ReportError (CoreID, E_OS_STATE, OSServiceId_AllowAccess, OS_IE_APP_RESTART_TASK_ERR, (Os_uint32)Os_CurrentTaskId[CoreID], OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR);
        ret = E_OS_STATE;
    }
    else
#endif /*(OS_STATUS_LEVEL == OS_EXTENDED)*/
    {
        OsCpu_EnterCritical(CoreID, &tempPri);

        Application = Os_CurrentApplicationId[CoreID];

        Os_AppCBTable[Application].appState = APPLICATION_ACCESSIBLE;

#if(OS_ALARM_NUMBER > 0)
        /* kill all alarm of this app*/
        for(alarmIdx = (Os_uint8)0; alarmIdx < Os_AppCfg[Application].alarmNum; alarmIdx++)
        {
            Os_AlarmCBTable[Os_AppCfg[Application].alarmOfApp[alarmIdx]].isKilled = OS_FALSE;
        }
#endif /*(OS_ALARM_NUMBER > 0)*/

#if(OS_SCHTBL_NUMBER > 0)
        /* kill all schtbl of this app*/
        for(schTblIdx = (Os_uint8)0; schTblIdx < Os_AppCfg[Application].schTblNum; schTblIdx++)
        {
            Os_SchTblCBTable[Os_AppCfg[Application].schTblOfApp[schTblIdx]].isKilled = OS_FALSE;
        } 
#endif /*(OS_SCHTBL_NUMBER > 0)*/

        /* kill all non running ISR of this app*/
        for(isrIdx = (Os_uint8)0; isrIdx < Os_AppCfg[Application].isrNum; isrIdx++)
        {
            ISRID = Os_AppCfg[Application].isrOfApp[isrIdx];
            Os_ISRCBTable[ISRID].isKilled = OS_FALSE;
            OsIntc_EnableISR(CoreID,ISRID); /* enable hw interrupt if hw support */
        }

        /* kill all non running task of this app*/
        for(taskIdx = (Os_uint8)0; taskIdx < Os_AppCfg[Application].taskNum; taskIdx++)
        {
            Os_TaskCBTable[Os_AppCfg[Application].taskOfApp[taskIdx]].isKilled = OS_FALSE;
        }
        OsCpu_ExitCritical(CoreID, tempPri);
    }
    return ret;
}

#endif /*(OS_ON == OS_OSAPP_RESTARTTASK_SUPPORT)*/


#define OS_STOP_SEC_CODE
#include "Os_MemMap.h"

#endif /*(OS_APPLICATION_NUMBER > 0)*/
