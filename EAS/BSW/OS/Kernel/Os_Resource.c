/*  BEGIN_FILE_HDR
********************************************************************************
*   NOTICE
*   This software is the property of HiRain Technologies. Any information
*   contained in this doc should not be reproduced, or used, or disclosed
*   without the written authorization from HiRain Technologies.
********************************************************************************
*   File Name       : Os_Resource.c
********************************************************************************
*   Project/Product : AUTOSAR OS PROJECT
*   Title           : Os_Resource.c
*   Author          : Hirain
********************************************************************************
*   Description     : Define API of Resource module for users.
*
********************************************************************************
*   Limitations     : None
*
********************************************************************************
*
********************************************************************************
*   Revision History:
*   Reference to Core Os_Kernel.c File
******************************************************************************
* END_FILE_HDR*/

/*****************************************************************************
* files include
******************************************************************************/
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

/*PRQA S 3432 EOF*/
/*
P2VAR and other macros in the Compiler conforms to AUTOSAR standard.There's no
need to revise.
OR
Parameters in macros or functions are useless for some hardware platforms, 
but they can not be deleted according to the requirements of 
AUTOSAR specification or compatibility.
*/

/*PRQA S 3119 EOF*/
/*
Some parameters will not be used in different configurations and hardware 
platforms, but they can not be deleted according to the requirements of 
AUTOSAR specification or compatibility. So we retain these parameters for 
compatibility and convert them with (void) to clean the warnings in compiler.
PRQA notices such statements as warning 3119, it has been suppressed here.
*/
/*PRQA S 3112 EOF*/
/*
Many macros encapsulate assembly instructions which be used to operate 
specific registers or function as C code(inline assembly). 
But PRQA can not parse assembly instructions and notice them as errors. 
So we use: 
#if defined(OS_QAC)
    #define macro (number)
#else
    #define macros asm
#endif
in source code and a macro "OS_QAC" in PRQA config to demotion errors.
PRQA notices these fake macros as warning 3112, it has been suppressed here.
*/

/*PRQA S 0553 EOF*/
/*
Some files are empty because user do not enable this function.
*/

/*PRQA S 3138 EOF*/
/*
Some statements are "NULL" beacause of the configuration of OS.
User may not enable such functions.
*/

/*PRQA S 3141 EOF*/
/*
Some statements are "NULL" beacause of the configuration of OS.
User may not enable such functions.
*/

#if(OS_RESOURCE_NUMBER > 0)
/*****************************************************************************
* static variables define
******************************************************************************/

#define OS_START_SEC_CODE
#include "Os_MemMap.h"
/*****************************************************************************
* OS private code
******************************************************************************/
STATIC FUNC(ResourceType, OS_CODE) OsRes_CheckBelongs
(
    CoreIdType CoreID,
    ResourceType ResID,
    CONSTP2CONST(Os_TaskIsrResCfgType, AUTOMATIC, OS_CONST) resPtr,
    ResourceType resNum
);

#if(OS_STATUS_LEVEL == OS_EXTENDED)
STATIC FUNC(StatusType, OS_CODE) OsRes_CheckGetResCondition
(
    CoreIdType CoreID,
    ResourceType ResID
);

STATIC FUNC(StatusType, OS_CODE) OsRes_CheckReleaseResCondition
(
    CoreIdType CoreID,
    ResourceType ResID
);
#endif /*(OS_STATUS_LEVEL == OS_EXTENDED)*/
/* BEGIN_FUNCTION_HDR
***********************************************************************************************
* Function Name: OsRes_CheckBelongs
*
* Description:   Check if res belongs to task or ISR?
*
* Inputs:        CoreID
*
* Outputs:       ResourceType offset index
*
* Limitations:   None
***********************************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(ResourceType, OS_CODE) OsRes_CheckBelongs
(
    CoreIdType CoreID,
    ResourceType ResID,
    CONSTP2CONST(Os_TaskIsrResCfgType, AUTOMATIC, OS_CONST) resPtr,
    ResourceType resNum
)
{
    ResourceType i;

    (void)CoreID;
    for(i = (ResourceType)0; i < resNum; i++)
    {
        if(resPtr[i].ResId == ResID)
        {
            return i;
        }
    }

    return OS_INVALID_RES_ID;
}

#if(OS_STATUS_LEVEL == OS_EXTENDED)
/* BEGIN_FUNCTION_HDR
***********************************************************************************************
* Function Name: OsRes_CheckGetResCondition
*
* Description:   Check if conditions for getting resource are fulfilled
*
* Inputs:        CoreID,ResID
*
* Outputs:       None
*
* Limitations:   None
***********************************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(StatusType, OS_CODE) OsRes_CheckGetResCondition
(
    CoreIdType CoreID,
    ResourceType ResID
)
{
    ISRType tempIsrId;
    TaskType tempTaskId;
    ResourceType offsetIndex;
    StatusType ret = E_OS_OK;

    if((CoreID >= (CoreIdType)OS_USED_CORE_NUMBER) || (Os_CoreState[CoreID] != OS_CORE_START))
    {
        /* can not record err in this state, as OS services can not be called*/
        ret = E_OS_CORE;
    }
    
    else if((Os_uint16)(Os_CurrentContext[CoreID] & Os_GetResouceMask) == (Os_uint16)0)
    {
        OsHook_ReportError(CoreID, E_OS_CALLEVEL, OSServiceId_GetResource, OS_IE_NOMORE_INFO, (Os_uint32)ResID, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR);
        ret = E_OS_CALLEVEL;
    }

    /* Check whether this API is called between interrupt processing APIs*/
    else if(OS_NO_API_USED != Os_IntAPIUsedFlag[CoreID])
    {
        /* System error -- this API is called between interrupt processing function pairs */
        OsHook_ReportError(CoreID, E_OS_DISABLEDINT, OSServiceId_GetResource, OS_IE_NOMORE_INFO, (Os_uint32)ResID, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR);
        ret = E_OS_DISABLEDINT;
    }

    /* Check ResId valid or not*/
    else if(ResID >= (ResourceType)OS_RESOURCE_NUMBER)
    {
        OsHook_ReportError(CoreID, E_OS_ID, OSServiceId_GetResource, OS_IE_ALARM_ID, (Os_uint32)ResID, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR);
        ret = E_OS_ID;
    }

#if(OS_USED_CORE_NUMBER > 1)
    /* Check whether this API is called from diifferent core*/
    else if(CoreID != Os_ResourceCfg[ResID].objCoreId)
    {
        OsHook_ReportError(CoreID, E_OS_SYS_SERVICE_NOTSUPPORT_CROSSCORE, OSServiceId_GetResource, OS_IE_NOMORE_INFO, (Os_uint32)ResID, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR);
        ret = E_OS_SYS_SERVICE_NOTSUPPORT_CROSSCORE;
    }
#endif /*(OS_USED_CORE_NUMBER > 1)*/

#if(OS_APPLICATION_NUMBER > 0)
    /*  current application invalid, should not has this case*/
    else if(Os_CurrentApplicationId[CoreID] == OS_INVALID_OSAPPLICATION)
    {
        OsHook_ReportError (CoreID, E_OS_ACCESS, OSServiceId_GetResource, OS_IE_INVALID_OSAPPICATION, (Os_uint32)Os_CurrentApplicationId[CoreID], OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR);
        ret = E_OS_ACCESS;
    }

    else if((Os_ApplicationMaskType)0 == ( (((Os_ApplicationMaskType)1) << Os_CurrentApplicationId[CoreID]) & Os_ResourceCfg[ResID].AppMask) )
    {
        OsHook_ReportError (CoreID, E_OS_ACCESS, OSServiceId_GetResource, OS_IE_NO_ACCESS_RIGHT, (Os_uint32)ResID, (Os_uint32)Os_CurrentApplicationId[CoreID], OS_IE_NO_ERRPAR);
        ret = E_OS_ACCESS;
    }
#endif /*(OS_APPLICATION_NUMBER > 0)*/

    else if(Os_CurrentContext[CoreID] == OS_CONTEXT_C2ISR)
    {
        tempIsrId = Os_CoreCfg[CoreID].nestIsrIdPtr[Os_IntNestDepth[CoreID]];
#if((OS_ISR_RESOURCE_NUMBER > 0) || (OS_SHARE_RESOURCE_NUMBER > 0))
        offsetIndex =  OsRes_CheckBelongs(CoreID, ResID, Os_ISRCfg[tempIsrId].resPtr, Os_ISRCfg[tempIsrId].resNum);
        if(OS_INVALID_RES_ID == offsetIndex)
#endif /*((OS_ISR_RESOURCE_NUMBER > 0) || (OS_SHARE_RESOURCE_NUMBER > 0))*/
        {
            OsHook_ReportError(CoreID, E_OS_ACCESS, OSServiceId_GetResource, OS_IE_TASKRES_ACCBY_ISR, (Os_uint32)ResID, (Os_uint32)tempIsrId, OS_IE_NO_ERRPAR);
            ret = E_OS_ACCESS;
        }
    }
    else if(Os_CurrentContext[CoreID] == OS_CONTEXT_TASK)
    {
        tempTaskId = Os_CurrentTaskId[CoreID];
#if((OS_TASK_RESOURCE_NUMBER > 0) || (OS_SHARE_RESOURCE_NUMBER > 0))
        offsetIndex = OsRes_CheckBelongs(CoreID, ResID, Os_TaskCfg[tempTaskId].resPtr, Os_TaskCfg[tempTaskId].resNum);
        if(OS_INVALID_RES_ID == offsetIndex)
#endif /*((OS_TASK_RESOURCE_NUMBER > 0) || (OS_SHARE_RESOURCE_NUMBER > 0))*/
        {
            OsHook_ReportError(CoreID, E_OS_ACCESS, OSServiceId_GetResource, OS_IE_TASKRES_ACCBY_ISR, (Os_uint32)ResID, (Os_uint32)tempTaskId, OS_IE_NO_ERRPAR);
            ret = E_OS_ACCESS;
        }
    }
    else
    {
        OsHook_ReportError(CoreID, E_OS_CALLEVEL, OSServiceId_GetResource, OS_IE_NOMORE_INFO, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR);
        ret = E_OS_CALLEVEL;
    }

    return ret;
}

/* BEGIN_FUNCTION_HDR
***********************************************************************************************
* Function Name: OsRes_CheckReleaseResCondition
*
* Description:   Check if conditions for releasing resource are fulfilled
*
* Inputs:        CoreID,ResID
*
* Outputs:       None
*
* Limitations:   None
***********************************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(StatusType, OS_CODE) OsRes_CheckReleaseResCondition
(
    CoreIdType CoreID,
    ResourceType ResID
)
{
    ISRType tempIsrId;
    TaskType tempTaskId;
    StatusType ret = E_OS_OK;

    if((CoreID >= (CoreIdType)OS_USED_CORE_NUMBER) || (Os_CoreState[CoreID] != OS_CORE_START))
    {
        /* can not record err in this state, as OS services can not be called*/
        ret = E_OS_CORE;
    }
    
    else if((Os_uint16)(Os_CurrentContext[CoreID] & Os_GetResouceMask) == (Os_uint16)0)
    {
        OsHook_ReportError(CoreID, E_OS_CALLEVEL, OSServiceId_ReleaseResource, OS_IE_NOMORE_INFO, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR);
        ret = E_OS_CALLEVEL;
    } 

    /* Check whether this API is called between interrupt processing APIs*/
    else if(OS_NO_API_USED != Os_IntAPIUsedFlag[CoreID])
    {
        OsHook_ReportError(CoreID, E_OS_DISABLEDINT, OSServiceId_ReleaseResource, OS_IE_NOMORE_INFO, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR);
        ret = E_OS_DISABLEDINT;
    }

    /* Check ResId valid or not*/
    else if(ResID >= (ResourceType)OS_RESOURCE_NUMBER)
    {
        OsHook_ReportError(CoreID, E_OS_ID, OSServiceId_ReleaseResource, OS_IE_ALARM_ID, (Os_uint32)ResID, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR);
        ret = E_OS_ID;
    }

#if(OS_USED_CORE_NUMBER > 1)
    /* Check whether this API is called from diifferent core*/
    else if(CoreID != Os_ResourceCfg[ResID].objCoreId)
    {
        OsHook_ReportError(CoreID, E_OS_SYS_SERVICE_NOTSUPPORT_CROSSCORE, OSServiceId_ReleaseResource, OS_IE_NOMORE_INFO, (Os_uint32)ResID, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR);
        ret = E_OS_SYS_SERVICE_NOTSUPPORT_CROSSCORE;
    }
#endif /*(OS_USED_CORE_NUMBER > 1)*/

#if(OS_APPLICATION_NUMBER > 0)
    /*  current application invalid, should not has this case*/
    else if(Os_CurrentApplicationId[CoreID] == OS_INVALID_OSAPPLICATION)
    {
        OsHook_ReportError (CoreID, E_OS_ACCESS, OSServiceId_ReleaseResource, OS_IE_INVALID_OSAPPICATION, (Os_uint32)Os_CurrentApplicationId[CoreID], OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR);
        ret = E_OS_ACCESS;
    }

    else if((Os_ApplicationMaskType)0 == ( (((Os_ApplicationMaskType)1) << Os_CurrentApplicationId[CoreID]) & Os_ResourceCfg[ResID].AppMask) )
    {
        OsHook_ReportError (CoreID, E_OS_ACCESS, OSServiceId_ReleaseResource, OS_IE_NO_ACCESS_RIGHT, (Os_uint32)ResID, (Os_uint32)Os_CurrentApplicationId[CoreID], OS_IE_NO_ERRPAR);
        ret = E_OS_ACCESS;
    }
#endif /*(OS_APPLICATION_NUMBER > 0)*/

    else if(Os_ResCBTable[ResID].OsResSemaphore != OS_TRUE)
    {
        OsHook_ReportError (CoreID, E_OS_NOFUNC, OSServiceId_ReleaseResource, OS_IE_NOMORE_INFO, (Os_uint32)ResID, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR);
        ret = E_OS_NOFUNC;
    }

    else if(Os_CurrentContext[CoreID] == OS_CONTEXT_C2ISR)
    {
        tempIsrId = Os_CoreCfg[CoreID].nestIsrIdPtr[Os_IntNestDepth[CoreID]];


        /* If this Res is the last res locked by current ISR
         * This check can cover following error:
         * res is not released LIFO,
         * res can be accessed by ISR
         *
         * */
        if(Os_ISRCBTable[tempIsrId].LastResId != ResID)
        {
            OsHook_ReportError(CoreID, E_OS_ACCESS, OSServiceId_ReleaseResource, OS_IE_RES_LIFO_ERROR, (Os_uint32)ResID, (Os_uint32)tempIsrId, OS_IE_NO_ERRPAR);
            ret = E_OS_ACCESS;
        }

    }
    else if(Os_CurrentContext[CoreID] == OS_CONTEXT_TASK)
    {
        tempTaskId = Os_CurrentTaskId[CoreID];

        /* If this Res is the last res locked by current Task
         * This check can cover following error:
         * res is not released LIFO
         *res can be accessed by task
         * */
        if(Os_TaskCBTable[tempTaskId].LastResId != ResID)
        {
            OsHook_ReportError(CoreID, E_OS_ACCESS, OSServiceId_ReleaseResource, OS_IE_RES_LIFO_ERROR, (Os_uint32)ResID, (Os_uint32)tempTaskId, OS_IE_NO_ERRPAR);
            ret = E_OS_ACCESS;
        }

    }
    else
    {
        OsHook_ReportError(CoreID, E_OS_CALLEVEL, OSServiceId_ReleaseResource, OS_IE_NOMORE_INFO, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR);
        ret = E_OS_CALLEVEL;
    }

    return ret;
}
#endif /*(OS_STATUS_LEVEL == OS_EXTENDED)*/
/*****************************************************************************
* OS internal code
******************************************************************************/

/* BEGIN_FUNCTION_HDR
***********************************************************************************************
* Function Name: OsRes_Init
*
* Description:   Resource initialization.
*
* Inputs:        CoreID
*
* Outputs:       None
*
* Limitations:   None
***********************************************************************************************
END_FUNCTION_HDR*/
FUNC(void, OS_CODE) OsRes_Init
(
    CoreIdType CoreID
)
{
    ResourceType i;
    ResourceType endResId;
#if(OS_SHARE_RESOURCE_NUMBER > 0)
    Os_IntResLockDepth[CoreID] = (Os_uint8)0;
#endif /*(OS_SHARE_RESOURCE_NUMBER > 0)*/
    endResId = Os_CoreCfg[CoreID].startResId + Os_CoreCfg[CoreID].resNum;

    for(i = Os_CoreCfg[CoreID].startResId; i < endResId; i++)
    {
        Os_ResCBTable[i].OsResSemaphore = OS_FALSE;
        Os_ResCBTable[i].LastResId = OS_INVALID_RES_ID;
        Os_ResCBTable[i].SavedISRPri = OS_INVALID_PRIO;
        Os_ResCBTable[i].SavedTaskPri = OS_INVALID_PRIO;
    }
}


/* BEGIN_FUNCTION_HDR
***********************************************************************************************
* Function Name: OsRes_AutoReleaseTaskResource
*
* Description:   Used to release resources locked by task in terminate Task, ChainTask, WaitEvent killTask..
*
* Inputs:        CoreID,TaskID
*
* Outputs:       Os_boolean: has locked res?
*
* Limitations:   None
***********************************************************************************************
END_FUNCTION_HDR*/
FUNC(Os_boolean, OS_CODE) OsRes_AutoReleaseTaskResource
(
    CoreIdType CoreID,
    TaskType TaskID
)
{
    ResourceType tempResId;
    ResourceType nextResId;
#if(OS_SHARE_RESOURCE_NUMBER > 0)
    Os_ResAccessype resAccType;
#endif /*(OS_SHARE_RESOURCE_NUMBER > 0)*/
    Os_boolean ret = OS_FALSE;
    (void)CoreID;
    nextResId = Os_TaskCBTable[TaskID].LastResId;
    if(nextResId != OS_INVALID_RES_ID)
    {
        ret = OS_TRUE;
        Os_TaskCBTable[TaskID].LastResId = OS_INVALID_RES_ID;
        Os_TaskCBTable[TaskID].OsCellingTaskPri = Os_TaskCfg[TaskID].OsTaskCfgPrio;

        do
        {
            OsKernel_RemoveResCellingTask(CoreID, TaskID, Os_ResourceCfg[nextResId].ResCeilingPri_Task);
            Os_ResCBTable[nextResId].OsResSemaphore = OS_FALSE;
            tempResId = Os_ResCBTable[nextResId].LastResId;
            Os_ResCBTable[nextResId].LastResId = OS_INVALID_RES_ID;
            Os_ResCBTable[nextResId].SavedISRPri = OS_INVALID_PRIO;
            Os_ResCBTable[nextResId].SavedTaskPri = OS_INVALID_PRIO;

#if(OS_SHARE_RESOURCE_NUMBER > 0)
            resAccType = Os_ResourceCfg[nextResId].resAccessType;
            if(OS_RES_SHARE == resAccType)
            {
                /*PRQA S 3383 ++*/
                /*
                Because of the "if..." which before "do... while" loop, 
                "Os_IntResLockDepth" is larger than 0 here, so will not
                underflow.
                */
                Os_IntResLockDepth[CoreID] --;
                /*PRQA S 3383 --*/
            }
#endif /*(OS_SHARE_RESOURCE_NUMBER > 0)*/

            nextResId = tempResId;
        }while(nextResId != OS_INVALID_RES_ID);
    }
    return ret;
}

/* BEGIN_FUNCTION_HDR
***********************************************************************************************
* Function Name: OsRes_AutoReleaseISRResource
*
* Description:   Used to release resources locked by ISR in outISR,  killISR.
*
* Inputs:        CoreID,ISRID
*
* Outputs:       Os_boolean: has locked res?
*
* Limitations:   None
***********************************************************************************************
END_FUNCTION_HDR*/
FUNC(Os_boolean, OS_CODE) OsRes_AutoReleaseISRResource
(
    CoreIdType CoreID,
    ISRType ISRID
)
{
    ResourceType tempResId;
    ResourceType nextResId;
    Os_boolean ret = OS_FALSE;

    (void)CoreID;

    nextResId = Os_ISRCBTable[ISRID].LastResId;
    if(nextResId != OS_INVALID_RES_ID)
    {
        ret = OS_TRUE;
        Os_ISRCBTable[ISRID].LastResId = OS_INVALID_RES_ID;

        do
        {
            Os_ResCBTable[nextResId].OsResSemaphore = OS_FALSE;
            tempResId = Os_ResCBTable[nextResId].LastResId;
            Os_ResCBTable[nextResId].LastResId = OS_INVALID_RES_ID;
            if (OS_INVALID_PRIO != Os_ResCBTable[nextResId].SavedISRPri)
            {
                OsIntc_ReplaceIntPriority(CoreID, Os_ResCBTable[nextResId].SavedISRPri);
                Os_ResCBTable[nextResId].SavedISRPri = OS_INVALID_PRIO;
            }
            Os_ResCBTable[nextResId].SavedTaskPri = OS_INVALID_PRIO;
            nextResId = tempResId;
        }while(nextResId != OS_INVALID_RES_ID);
    }

    return ret;
}

/*****************************************************************************
* OS API code
******************************************************************************/

/* BEGIN_FUNCTION_HDR
***********************************************************************************************
* Function Name: Os_GetResource
*
* Description:   API function called by Application.This call serves to enter critical sections
*                in the code that are assigned to the resource.
*
* Inputs:        <ResID> Reference to resource.
*
* Outputs:       None
*
* Limitations:   None
***********************************************************************************************
END_FUNCTION_HDR*/
FUNC(StatusType, OS_CODE) Os_GetResource
(
    ResourceType ResID
)
{
    CoreIdType CoreID;
    Os_boolean tempPri;
    Os_ResAccessype resAccType;
    ISRType tempIsrId;
    TaskType tempTaskId;
    Os_PrioType tempCurrentPri;
#if((OS_TASK_RESOURCE_NUMBER > 0) || (OS_SHARE_RESOURCE_NUMBER > 0) || (OS_ISR_RESOURCE_NUMBER > 0))
    ResourceType offsetIndex;
#endif /*((OS_TASK_RESOURCE_NUMBER > 0) || (OS_SHARE_RESOURCE_NUMBER > 0) || (OS_ISR_RESOURCE_NUMBER > 0))*/
#if(OS_STATUS_LEVEL == OS_EXTENDED)
    StatusType ret = E_OS_OK;
#endif /*(OS_STATUS_LEVEL == OS_EXTENDED)*/
    CoreID = OsCpu_GetCoreID();
#if(OS_STATUS_LEVEL == OS_EXTENDED)
    ret = OsRes_CheckGetResCondition(CoreID, ResID);
    if(ret != E_OS_OK)
    {
        return ret;
    }
#endif /*(OS_STATUS_LEVEL == OS_EXTENDED)*/
    /* runtime error*/
    if(Os_ResCBTable[ResID].OsResSemaphore == OS_TRUE)
    {
        return E_OS_ACCESS;
    }
    /* check end can lock this resource */
    OsCpu_EnterCritical(CoreID, &tempPri);
    Os_ResCBTable[ResID].OsResSemaphore = OS_TRUE;
    /*If ISR get resource, dont need to rise task's celling pri, as any task will not run until res release
     *  */
    if(Os_CurrentContext[CoreID] == OS_CONTEXT_C2ISR)
    {
        tempIsrId = Os_CoreCfg[CoreID].nestIsrIdPtr[Os_IntNestDepth[CoreID]];
        if(Os_ISRCBTable[tempIsrId].LastResId != OS_INVALID_RES_ID)
        {
            Os_ResCBTable[ResID].LastResId = Os_ISRCBTable[tempIsrId].LastResId;
        }
        Os_ISRCBTable[tempIsrId].LastResId = ResID;
        tempCurrentPri = (Os_PrioType)(OsIntc_GetIntPriority(CoreID));
        if(tempCurrentPri < Os_ResourceCfg[ResID].ResCeilingPri_ISR)
        {
            /* Modify the current interrupt level in the system */
            OsIntc_ReplaceIntPriority(CoreID, Os_ResourceCfg[ResID].ResCeilingPri_ISR);
            Os_ResCBTable[ResID].SavedISRPri = tempCurrentPri;
        }
#if((OS_ISR_RESOURCE_NUMBER > 0) || (OS_SHARE_RESOURCE_NUMBER > 0))
        offsetIndex =  OsRes_CheckBelongs(CoreID, ResID, Os_ISRCfg[tempIsrId].resPtr, Os_ISRCfg[tempIsrId].resNum);
        OsTp_IsrResourceLocktimeStart(CoreID, tempIsrId, offsetIndex);
#endif /*((OS_ISR_RESOURCE_NUMBER > 0) || (OS_SHARE_RESOURCE_NUMBER > 0))*/
    }
    else if(Os_CurrentContext[CoreID] == OS_CONTEXT_TASK)
    {
        /* rise the celling pri*/
        tempTaskId = Os_CurrentTaskId[CoreID];
        /* may get more than 1 resource*/
        if(Os_TaskCBTable[tempTaskId].OsCellingTaskPri > Os_ResourceCfg[ResID].ResCeilingPri_Task)
        {
            OsKernel_InsertResCellingTask(CoreID, tempTaskId, Os_ResourceCfg[ResID].ResCeilingPri_Task);
            Os_TaskCBTable[tempTaskId].OsCellingTaskPri = Os_ResourceCfg[ResID].ResCeilingPri_Task;
        }
        if(Os_TaskCBTable[tempTaskId].LastResId != OS_INVALID_RES_ID)
        {
            Os_ResCBTable[ResID].LastResId = Os_TaskCBTable[tempTaskId].LastResId;
        }
        Os_TaskCBTable[tempTaskId].LastResId = ResID;
        Os_ResCBTable[ResID].SavedTaskPri = Os_TaskCBTable[tempTaskId].OsCellingTaskPri;

        resAccType = Os_ResourceCfg[ResID].resAccessType;
        /*share res lock schedule*/
        if(OS_RES_SHARE == resAccType)
        {
            tempCurrentPri = OsIntc_GetIntPriority(CoreID);

            if(tempCurrentPri < Os_ResourceCfg[ResID].ResCeilingPri_ISR)
            {
                OsIntc_ReplaceIntPriority(CoreID, Os_ResourceCfg[ResID].ResCeilingPri_ISR);  /* Modify the current interrupt level in the system */
            }

            Os_ResCBTable[ResID].SavedISRPri = tempCurrentPri;
#if(OS_SHARE_RESOURCE_NUMBER > 0)
            /*PRQA S 3383 ++*/
            /* "OsRes_CheckGetResCondition" has checked before. */
            Os_IntResLockDepth[CoreID]++;
            /*PRQA S 3383 --*/
            if(Os_IntResLockDepth[CoreID] > OS_INTRES_MAX_NEST_VALUE)
#endif /*(OS_SHARE_RESOURCE_NUMBER > 0)*/
            {
                OsHook_FataErrReport(CoreID, E_OS_SYSFATA_RES_NEST_LIMIT_ERROR, OSServiceId_GetResource, OS_IE_NOMORE_INFO, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR);
            }
        }
#if((OS_TASK_RESOURCE_NUMBER > 0) || (OS_SHARE_RESOURCE_NUMBER > 0))
        offsetIndex = OsRes_CheckBelongs(CoreID, ResID, Os_TaskCfg[tempTaskId].resPtr, Os_TaskCfg[tempTaskId].resNum);
        OsTp_TskResourceLocktimeStart(CoreID, tempTaskId, offsetIndex);
#endif /*((OS_TASK_RESOURCE_NUMBER > 0) || (OS_SHARE_RESOURCE_NUMBER > 0))*/
    }
    else
    {
        /* do nothing err has checked before*/
    }

    OsCpu_ExitCritical(CoreID, tempPri);

    return E_OS_OK;
}

/* BEGIN_FUNCTION_HDR
***********************************************************************************************
* Function Name: Os_ReleaseResource
*
* Description:   API function called by Application.This call serves to leave critical sections
*                in the code that are assigned to the resource.
*
* Inputs:        <ResID> Reference to resource.
*
* Outputs:       None
*
* Limitations:   None
***********************************************************************************************
END_FUNCTION_HDR*/
FUNC(StatusType, OS_CODE) Os_ReleaseResource
(
    ResourceType ResID
)
{
    CoreIdType CoreID;
    Os_boolean tempPri;
    ISRType tempIsrId;
    TaskType tempTaskId;
    ResourceType lastRes;
#if((OS_TASK_RESOURCE_NUMBER > 0) || (OS_SHARE_RESOURCE_NUMBER > 0) || (OS_ISR_RESOURCE_NUMBER > 0))
    ResourceType offsetIndex;
#endif /*((OS_TASK_RESOURCE_NUMBER > 0) || (OS_SHARE_RESOURCE_NUMBER > 0) || (OS_ISR_RESOURCE_NUMBER > 0))*/
    Os_ResAccessype resAccType;
    Os_PrioType tempCurrentPri;
#if(OS_STATUS_LEVEL == OS_EXTENDED)
    StatusType ret = E_OS_OK;
#endif /*(OS_STATUS_LEVEL == OS_EXTENDED)*/
    CoreID = OsCpu_GetCoreID();

#if(OS_STATUS_LEVEL == OS_EXTENDED)
    ret = OsRes_CheckReleaseResCondition(CoreID, ResID);
    if(ret != E_OS_OK)
    {
        /* can not record err in this state, as OS services can not be called*/
        return ret;
    }
#endif /*(OS_STATUS_LEVEL == OS_EXTENDED)*/

    /* check end, can unlock this resource */
    OsCpu_EnterCritical(CoreID, &tempPri);

    Os_ResCBTable[ResID].OsResSemaphore = OS_FALSE;

    Os_ResCBTable[ResID].SavedTaskPri = OS_INVALID_PRIO;

    if(Os_CurrentContext[CoreID] == OS_CONTEXT_C2ISR)
    {
        tempIsrId = Os_CoreCfg[CoreID].nestIsrIdPtr[Os_IntNestDepth[CoreID]];
#if((OS_ISR_RESOURCE_NUMBER > 0) || (OS_SHARE_RESOURCE_NUMBER > 0))
        offsetIndex =  OsRes_CheckBelongs(CoreID, ResID, Os_ISRCfg[tempIsrId].resPtr, Os_ISRCfg[tempIsrId].resNum);
#endif /*((OS_ISR_RESOURCE_NUMBER > 0) || (OS_SHARE_RESOURCE_NUMBER > 0))*/
        lastRes = Os_ResCBTable[ResID].LastResId;
        if(lastRes != OS_INVALID_RES_ID)
        {
            Os_ISRCBTable[tempIsrId].LastResId = lastRes;
        }
        else
        {
            /*no more res locked*/
            Os_ISRCBTable[tempIsrId].LastResId = OS_INVALID_RES_ID;
            /* when the priority restore, 
            pengding ISR using this Resource may generate when this API return(interrupt enabled).*/
        }

        if(OS_INVALID_PRIO != Os_ResCBTable[ResID].SavedISRPri)
        {
            /* Modify the current interrupt level in the system */
            OsIntc_ReplaceIntPriority(CoreID, Os_ResCBTable[ResID].SavedISRPri);
        }
#if(OS_TP_ISR_RESOURCE_LOCKTIME_SUPPORT == OS_ON)
        OsTp_IsrResourceLocktimeStop(CoreID, tempIsrId, offsetIndex);
#endif /*(OS_TP_ISR_RESOURCE_LOCKTIME_SUPPORT == OS_ON)*/
    }
    else if(Os_CurrentContext[CoreID] == OS_CONTEXT_TASK)
    {
        /* rise the celling pri*/
        tempTaskId = Os_CurrentTaskId[CoreID];
#if((OS_TASK_RESOURCE_NUMBER > 0) || (OS_SHARE_RESOURCE_NUMBER > 0))
        offsetIndex = OsRes_CheckBelongs(CoreID, ResID, Os_TaskCfg[tempTaskId].resPtr, Os_TaskCfg[tempTaskId].resNum);
#endif /*((OS_TASK_RESOURCE_NUMBER > 0) || (OS_SHARE_RESOURCE_NUMBER > 0))*/
        lastRes = Os_ResCBTable[ResID].LastResId;
        OsKernel_RemoveResCellingTask(CoreID, tempTaskId, Os_ResourceCfg[ResID].ResCeilingPri_Task);

        if(lastRes != OS_INVALID_RES_ID)
        {
            Os_TaskCBTable[tempTaskId].LastResId = lastRes;
            Os_TaskCBTable[tempTaskId].OsCellingTaskPri = Os_ResCBTable[lastRes].SavedTaskPri;
        }
        else
        {
            /*no more res locked*/
            Os_TaskCBTable[tempTaskId].LastResId = OS_INVALID_RES_ID;
            /* restore the priority of Task*/
            Os_TaskCBTable[tempTaskId].OsCellingTaskPri = Os_TaskCfg[tempTaskId].OsTaskCfgPrio;
        }
        resAccType = Os_ResourceCfg[ResID].resAccessType;
        /*share res lock schedule*/
        if(OS_RES_SHARE == resAccType)
        {
            tempCurrentPri = OsIntc_GetIntPriority(CoreID);

            if(tempCurrentPri > Os_ResCBTable[ResID].SavedISRPri)
            {
                OsIntc_ReplaceIntPriority(CoreID,Os_ResCBTable[ResID].SavedISRPri);
            }
#if(OS_SHARE_RESOURCE_NUMBER > 0)
            /*PRQA S 3383 ++*/
            /* "OsRes_CheckReleaseResCondition" has checked before. */
            Os_IntResLockDepth[CoreID] --;
            /*PRQA S 3383 --*/
#endif /*(OS_SHARE_RESOURCE_NUMBER > 0)*/
        }

        /* celling pri restore, reschedule*/
        /*PRQA S 3416 ++*/
        /* The side effect of "OsKernel_NeedSchedule" is expected. */
        if((OsKernel_NeedSchedule(CoreID, OS_FALSE) == OS_TRUE))
        /*PRQA S 3416 --*/
        {
            OsKernel_ExitTask(CoreID, OS_TRUE, OS_TASK_READY);
            /* Task scheduling*/
            OsCpu_TaskPreemptSchedule(CoreID, Os_CurrentTaskId[CoreID]);
            /* here is the task restore point*/
        }

        OsTp_TskResourceLocktimeStop(CoreID, tempTaskId, offsetIndex);
    }
    else
    {
        /* do nothing err has checked before*/
    }
    Os_ResCBTable[ResID].SavedISRPri = OS_INVALID_PRIO;
    OsCpu_ExitCritical(CoreID, tempPri);

    return E_OS_OK;
}

#define OS_STOP_SEC_CODE
#include "Os_MemMap.h"

#endif /*(OS_RESOURCE_NUMBER > 0)*/
