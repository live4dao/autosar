/*  BEGIN_FILE_HDR
********************************************************************************
*   NOTICE
*   This software is the property of HiRain Technologies. Any information
*   contained in this doc should not be reproduced, or used, or disclosed
*   without the written authorization from HiRain Technologies.
********************************************************************************
* File Name:       Os_SpinLock.c
********************************************************************************
* Project/Product: AUTOSAR OS PROJECT
* Title:           Os_SpinLock.c
* Author:          Hirain
********************************************************************************
* Description:     User spinlock related function
*
********************************************************************************
* Limitations     : Os internal spinlock is not define here
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

#if(OS_SPINLOCK_NUMBER > 0)
/*******************************************************************************
*   Macro
*******************************************************************************/

/*****************************************************************************
* static variables define
******************************************************************************/
#define OS_START_SEC_VAR_NOINIT_MULTICORE
#include "Os_MemMap.h"
/*
this store the order that spinlock locked in task or ISR
save the last spinklock occupy by same task or ISR
*/
STATIC VAR(SpinlockIdType, OS_VAR) OsSpinlock_Link[OS_SPINLOCK_NUMBER];

#define OS_STOP_SEC_VAR_NOINIT_MULTICORE
#include "Os_MemMap.h"

#define OS_START_SEC_CODE
#include "Os_MemMap.h"
/*****************************************************************************
* OS private code
******************************************************************************/
STATIC FUNC(Os_boolean, OS_CODE) OsSpinlock_GetEnvCheck
(
    CoreIdType CoreID,
    Os_SpinlockMethodType lockmethod
);

#if(OS_SPINLOCK_LINK_NUMBER > 0)
STATIC FUNC(Os_boolean, OS_CODE) OsSpinlock_CheckLinkOrder
(
    CoreIdType CoreID,
    SpinlockIdType SpinlockID
);
#endif /*(OS_SPINLOCK_LINK_NUMBER > 0)*/

#if(OS_STATUS_LEVEL == OS_EXTENDED)
STATIC FUNC(StatusType, OS_CODE) OsSpinlock_CheckTryToGetSpinlockCondition
(
    CoreIdType CoreID,
    SpinlockIdType SpinlockID,
    P2CONST(TryToGetSpinlockType, AUTOMATIC, OS_APPL_DATA) Success
);

STATIC FUNC(StatusType, OS_CODE) OsSpinlock_CheckReleaseSpinlockCondition
(
    CoreIdType CoreID,
    SpinlockIdType SpinlockID
);

STATIC FUNC(StatusType, OS_CODE) OsSpinlock_CheckGetSpinlockCondition
(
    CoreIdType CoreID,
    SpinlockIdType SpinlockID 
);
#endif /*(OS_STATUS_LEVEL == OS_EXTENDED)*/
/* BEGIN_FUNCTION_HDR
***********************************************************************************************
* Function Name: OsSpinlock_GetEnvCheck
*
* Description:   Check the call environment of get Spinlock
*
* Inputs:        CoreID,lockmethod
*
* Outputs:       TRUE: no error happen; False, error
*
* Limitations:   None
***********************************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(Os_boolean, OS_CODE) OsSpinlock_GetEnvCheck
(
    CoreIdType CoreID,
    Os_SpinlockMethodType lockmethod
)
{
    if((OS_LOCK_NOTHING == lockmethod) || (OS_LOCK_WITH_RES_SCHEDULER == lockmethod))
    {
        return OS_TRUE;
    }
    if(Os_IntAPIUsedFlag[CoreID] == OS_NO_API_USED)
    {
        return OS_TRUE;
    }

    if((Os_IntAPIUsedFlag[CoreID] == OS_SUS_ALL_API_USED) && (lockmethod == OS_LOCK_ALL_INTERRUPTS))
    {
        return OS_TRUE;
    }

    if((Os_IntAPIUsedFlag[CoreID] == OS_SUS_OS_API_USED) && (lockmethod == OS_LOCK_CAT2_INTERRUPTS))
    {
        return OS_TRUE;
    }

   /*
    if((Os_IntAPIUsedFlag[CoreID] == OS_DIS_ALL_API_USED) && (lockmethod == OS_LOCK_WITH_RES_SCHEDULER))
    {
        return OS_TRUE;
    }
   */

    return OS_FALSE;
}

/* BEGIN_FUNCTION_HDR
***********************************************************************************************
* Function Name: OsSpinlock_CheckLinkOrder
*
* Description:   Check the link order
*
* Inputs:        CoreID,SpinlockID
*
* Outputs:       TRUE: no error happen; False, error
*
* Limitations:   None
***********************************************************************************************
END_FUNCTION_HDR*/
#if(OS_SPINLOCK_LINK_NUMBER > 0)
STATIC FUNC(Os_boolean, OS_CODE) OsSpinlock_CheckLinkOrder
(
    CoreIdType CoreID,
    SpinlockIdType SpinlockID
)
{
    SpinlockIdType grp = Os_SpinlockCfg[SpinlockID].LinkGrp;
    SpinlockIdType index = Os_SpinlockCfg[SpinlockID].LinkIndex;
    SpinlockIdType tmpGrp;
    SpinlockIdType tmpSpIdx = OS_INVALID_SPINLOCK;
    TaskType tempTaskID;
    ISRType tempIsrID;

    /* no link for this spinlock*/
    if(grp == OS_INVALID_SPINLOCK)
    {
        return OS_TRUE;
    }

    if(Os_CurrentContext[CoreID] == OS_CONTEXT_C2ISR)
    {
        tempIsrID = Os_CoreCfg[CoreID].nestIsrIdPtr[Os_IntNestDepth[CoreID]];
        tmpSpIdx = Os_ISRCBTable[tempIsrID].LastSpinLock;
    }
    else if(Os_CurrentContext[CoreID] == OS_CONTEXT_TASK)
    {
        /* code */
        tempTaskID = Os_CurrentTaskId[CoreID];
        tmpSpIdx = Os_TaskCBTable[tempTaskID].LastSpinLock;
    }
    else
    {
        /* do nothing err has checked before*/
    }

    while(tmpSpIdx != OS_INVALID_SPINLOCK) 
    {
        tmpGrp = Os_SpinlockCfg[tmpSpIdx].LinkGrp;
        if(tmpGrp == grp)
        {
            if(index > Os_SpinlockCfg[tmpSpIdx].LinkIndex)/* new spinlock is behind */
            {
                return OS_TRUE;
            }
            else
            {
                return OS_FALSE;
            }
        }
        else
        {
            tmpSpIdx = OsSpinlock_Link[tmpSpIdx];/* get last spinklock of this task or ISR*/
        }
    }

    return OS_TRUE;/* this is first spinlock of current Task or ISR*/
}
#endif /*(OS_SPINLOCK_LINK_NUMBER > 0)*/

#if(OS_STATUS_LEVEL == OS_EXTENDED)
/* BEGIN_FUNCTION_HDR
***********************************************************************************************
* Function Name: OsSpinlock_CheckTryToGetSpinlockCondition
*
* Description:   Check if conditions for trying to get spinlock are fulfilled
*
* Inputs:        CoreID,SpinlockID,Success
*
* Outputs:       None
*
* Limitations:   None
***********************************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(StatusType, OS_CODE) OsSpinlock_CheckTryToGetSpinlockCondition
(
    CoreIdType CoreID,
    SpinlockIdType SpinlockID,
    P2CONST(TryToGetSpinlockType, AUTOMATIC, OS_APPL_DATA) Success
)
{
    StatusType ret = E_OS_OK;

    if((CoreID >= (CoreIdType)OS_USED_CORE_NUMBER) || (Os_CoreState[CoreID] != OS_CORE_START))
    {
        /* can not record err in this state, as OS services can not be called*/
        ret = E_OS_CORE;
    }
    
    else if((Os_uint16)(Os_CurrentContext[CoreID] & Os_TryToGetSpinlockMask) == (Os_uint16)0)
    {
        OsHook_ReportError(CoreID, E_OS_CALLEVEL, OSServiceId_TryToGetSpinlock, OS_IE_NOMORE_INFO, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR);
        ret = E_OS_CALLEVEL;
    }

    /* SWS_Os_00711 It shall be allowed to call the function GetSpinlock while interrupts are disabled */

    /* Check SpinlockID valid or not*/
    else if(SpinlockID >= (SpinlockIdType)OS_SPINLOCK_NUMBER)
    {
        OsHook_ReportError(CoreID, E_OS_ID, OSServiceId_TryToGetSpinlock, OS_IE_SPINLOCK_ID, (Os_uint32)SpinlockID, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR);
        ret = E_OS_ID;
    }

    else if(Success == OS_NULL)
    {
        OsHook_ReportError(CoreID, E_OS_PARAM_POINTER, OSServiceId_TryToGetSpinlock, OS_IE_NOMORE_INFO, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR);
        ret = E_OS_PARAM_POINTER;
    }

#if(OS_APPLICATION_NUMBER > 0)
    /*  current application invalid, should not has this case*/
    else if(Os_CurrentApplicationId[CoreID] == OS_INVALID_OSAPPLICATION)
    {
        OsHook_ReportError (CoreID, E_OS_ACCESS, OSServiceId_TryToGetSpinlock, OS_IE_INVALID_OSAPPICATION, (Os_uint32)Os_CurrentApplicationId[CoreID], OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR);
        ret = E_OS_ACCESS;
    }

    else if((Os_ApplicationMaskType)0 == ( (((Os_ApplicationMaskType)1) << Os_CurrentApplicationId[CoreID]) & (Os_SpinlockCfg[SpinlockID].AppMask) ) )
    {
        OsHook_ReportError (CoreID, E_OS_ACCESS, OSServiceId_TryToGetSpinlock, OS_IE_NO_ACCESS_RIGHT, (Os_uint32)Os_CurrentApplicationId[CoreID], (Os_uint32)SpinlockID, OS_IE_NO_ERRPAR);
        ret = E_OS_ACCESS;
    }
#endif /*(OS_APPLICATION_NUMBER > 0)*/
    /*PRQA S 3416 ++*/
    /* The side effect of "OsSpinlock_GetEnvCheck" is expected. */
    else if(OS_FALSE == OsSpinlock_GetEnvCheck(CoreID, Os_SpinlockCfg[SpinlockID].SpinlockMethod))
    /*PRQA S 3416 --*/
    {
        OsHook_ReportError (CoreID, E_OS_SYS_SPINLOCKMETHOD, OSServiceId_TryToGetSpinlock, OS_IE_NOMORE_INFO, (Os_uint32)Os_IntAPIUsedFlag[CoreID], (Os_uint32)SpinlockID, OS_IE_NO_ERRPAR);
        ret = E_OS_SYS_SPINLOCKMETHOD;
    }

    /* SWS_Os_00708 if spinlock is already occupied on the same core */
    else if(Os_SpinlockState[SpinlockID] == CoreID)
    {
        OsHook_ReportError (CoreID, E_OS_INTERFERENCE_DEADLOCK, OSServiceId_TryToGetSpinlock, OS_IE_NOMORE_INFO, (Os_uint32)SpinlockID, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR);
        ret = E_OS_INTERFERENCE_DEADLOCK;
    }

    /* SWS_Os_00709 spin lock must lock in correct order */
#if(OS_SPINLOCK_LINK_NUMBER > 0)
    /*PRQA S 3416 ++*/
    /* The side effect of "OsSpinlock_CheckLinkOrder" is expected. */
    else if(OS_FALSE == OsSpinlock_CheckLinkOrder(CoreID, SpinlockID))
    /*PRQA S 3416 --*/
    {
        OsHook_ReportErrorDisInt(CoreID, E_OS_NESTING_DEADLOCK, OSServiceId_GetSpinlock, OS_IE_NOMORE_INFO, (Os_uint32)SpinlockID, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR);
        ret = E_OS_NESTING_DEADLOCK;
    }
#endif /*(OS_SPINLOCK_LINK_NUMBER > 0)*/
    else
    {
        /*do nothing*/
    }

    return ret;
}

/* BEGIN_FUNCTION_HDR
***********************************************************************************************
* Function Name: OsSpinlock_CheckReleaseSpinlockCondition
*
* Description:   Check if conditions for releasing spinlock are fulfilled
*
* Inputs:        CoreID,SpinlockID
*
* Outputs:       None
*
* Limitations:   None
***********************************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(StatusType, OS_CODE) OsSpinlock_CheckReleaseSpinlockCondition
(
    CoreIdType CoreID,
    SpinlockIdType SpinlockID
)
{
    TaskType tempTaskID;
    ISRType tempIsrID;
    StatusType ret = E_OS_OK;

    if((CoreID >= (CoreIdType)OS_USED_CORE_NUMBER) || (Os_CoreState[CoreID] != OS_CORE_START))
    {
        /* can not record err in this state, as OS services can not be called*/
        ret = E_OS_CORE;
    }
    
    else if((Os_uint16)(Os_CurrentContext[CoreID] & Os_ReleaseSpinlockMask) == (Os_uint16)0)
    {
        OsHook_ReportError(CoreID, E_OS_CALLEVEL, OSServiceId_ReleaseSpinlock, OS_IE_NOMORE_INFO, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR);
        ret = E_OS_CALLEVEL;
    }

    /* SWS_Os_00711 693, as spinlock can be called when  interrupts are disabled
       its same for release spinlock
     */

    /* Check SpinlockID valid or not*/
    else if(SpinlockID >= (SpinlockIdType)OS_SPINLOCK_NUMBER)
    {
        OsHook_ReportError(CoreID, E_OS_ID, OSServiceId_ReleaseSpinlock, OS_IE_SPINLOCK_ID, (Os_uint32)SpinlockID, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR);
        ret = E_OS_ID;
    }

#if(OS_APPLICATION_NUMBER > 0)
    /*  current application invalid, should not has this case*/
    else if(Os_CurrentApplicationId[CoreID] == OS_INVALID_OSAPPLICATION)
    {
        OsHook_ReportError (CoreID, E_OS_ACCESS, OSServiceId_ReleaseSpinlock, OS_IE_INVALID_OSAPPICATION, (Os_uint32)Os_CurrentApplicationId[CoreID], OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR);
        ret = E_OS_ACCESS;
    }

    else if((Os_ApplicationMaskType)0 == ( (((Os_ApplicationMaskType)1) << Os_CurrentApplicationId[CoreID]) & (Os_SpinlockCfg[SpinlockID].AppMask) ) )
    {
        OsHook_ReportError (CoreID, E_OS_ACCESS, OSServiceId_ReleaseSpinlock, OS_IE_NO_ACCESS_RIGHT, (Os_uint32)Os_CurrentApplicationId[CoreID], (Os_uint32)SpinlockID, OS_IE_NO_ERRPAR);
        ret = E_OS_ACCESS;
    }
#endif /*(OS_APPLICATION_NUMBER > 0)*/

    else if(Os_CurrentContext[CoreID] == OS_CONTEXT_C2ISR)
    {
        tempIsrID = Os_CoreCfg[CoreID].nestIsrIdPtr[Os_IntNestDepth[CoreID]];

        /* SpinLock must relaeased LIFO */
        if(Os_ISRCBTable[tempIsrID].LastSpinLock != SpinlockID)
        {
            OsHook_ReportError(CoreID, E_OS_ACCESS, OSServiceId_ReleaseSpinlock, OS_IE_SPINLOCK_LIFO_ERROR, (Os_uint32)SpinlockID, (Os_uint32)tempIsrID, OS_IE_NO_ERRPAR);
            ret = E_OS_ACCESS;
        }

    }
    else if(Os_CurrentContext[CoreID] == OS_CONTEXT_TASK)
    {
        tempTaskID = Os_CurrentTaskId[CoreID];

        /* SpinLock must relaeased LIFO */
        if(Os_TaskCBTable[tempTaskID].LastSpinLock != SpinlockID)
        {
            OsHook_ReportError(CoreID, E_OS_NOFUNC, OSServiceId_ReleaseSpinlock, OS_IE_SPINLOCK_LIFO_ERROR, (Os_uint32)SpinlockID, (Os_uint32)tempTaskID, OS_IE_NO_ERRPAR);
            ret = E_OS_NOFUNC;
        }

    }
    else
    {
        /*do nothing*/
    }

    return ret;
}
/* BEGIN_FUNCTION_HDR
***********************************************************************************************
* Function Name: OsSpinlock_CheckGetSpinlockCondition
*
* Description:   Check if conditions for get spinlock are fulfilled
*
* Inputs:        CoreID,SpinlockID
*
* Outputs:       None
*
* Limitations:   None
***********************************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(StatusType, OS_CODE) OsSpinlock_CheckGetSpinlockCondition
(
    CoreIdType CoreID,
    SpinlockIdType SpinlockID 
)
{
    StatusType ret = E_OS_OK;

    if((CoreID >= (CoreIdType)OS_USED_CORE_NUMBER) || (Os_CoreState[CoreID] != OS_CORE_START))
    {
        /* can not record err in this state, as OS services can not be called*/
        ret = E_OS_CORE;
    }
    
    else if((Os_uint16)(Os_CurrentContext[CoreID] & Os_GetSpinlockMask) == (Os_uint16)0)
    {
        OsHook_ReportError(CoreID, E_OS_CALLEVEL, OSServiceId_GetSpinlock, OS_IE_NOMORE_INFO, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR);
        ret = E_OS_CALLEVEL;
    }

    /* SWS_Os_00693 It shall be allowed to call the function GetSpinlock while interrupts are disabled */

    /* Check SpinlockID valid or not*/
    else if(SpinlockID >= (SpinlockIdType)OS_SPINLOCK_NUMBER)
    {
        OsHook_ReportError(CoreID, E_OS_ID, OSServiceId_GetSpinlock, OS_IE_SPINLOCK_ID, (Os_uint32)SpinlockID, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR);
        ret = E_OS_ID;
    }

#if(OS_APPLICATION_NUMBER > 0)
    /*  Current application invalid, should not has this case*/
    else if(Os_CurrentApplicationId[CoreID] == OS_INVALID_OSAPPLICATION)
    {
        OsHook_ReportError (CoreID, E_OS_ACCESS, OSServiceId_GetSpinlock, OS_IE_INVALID_OSAPPICATION, (Os_uint32)Os_CurrentApplicationId[CoreID], OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR);
        ret = E_OS_ACCESS;
    }

    else if((Os_ApplicationMaskType)0 == ( (((Os_ApplicationMaskType)1) << Os_CurrentApplicationId[CoreID]) & (Os_SpinlockCfg[SpinlockID].AppMask) ) )
    {
        OsHook_ReportError (CoreID, E_OS_ACCESS, OSServiceId_GetSpinlock, OS_IE_NO_ACCESS_RIGHT, (Os_uint32)Os_CurrentApplicationId[CoreID], (Os_uint32)SpinlockID, OS_IE_NO_ERRPAR);
        ret = E_OS_ACCESS;
    }

#endif /*(OS_APPLICATION_NUMBER > 0)*/
    /* SWS_Os_00691 spin lock must lock in correct order */

#if(OS_SPINLOCK_LINK_NUMBER > 0)
    /*PRQA S 3416 ++*/
    /* The side effect of "OsSpinlock_CheckLinkOrder" is expected. */
    else if(OS_FALSE == OsSpinlock_CheckLinkOrder(CoreID, SpinlockID))
    {
    /*PRQA S 3416 --*/
        OsHook_ReportErrorDisInt(CoreID, E_OS_NESTING_DEADLOCK, OSServiceId_GetSpinlock, OS_IE_NOMORE_INFO, (Os_uint32)SpinlockID, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR);
        ret = E_OS_NESTING_DEADLOCK;
    }
#endif /*(OS_SPINLOCK_LINK_NUMBER > 0)*/
    /*PRQA S 3416 ++*/
    /* The side effect of "OsSpinlock_GetEnvCheck" is expected. */
    else if(OS_FALSE == OsSpinlock_GetEnvCheck(CoreID, Os_SpinlockCfg[SpinlockID].SpinlockMethod))
    {
    /*PRQA S 3416 --*/
        OsHook_ReportError (CoreID, E_OS_SYS_SPINLOCKMETHOD, OSServiceId_GetSpinlock, OS_IE_NOMORE_INFO, (Os_uint32)Os_IntAPIUsedFlag[CoreID], (Os_uint32)SpinlockID, OS_IE_NO_ERRPAR);
        ret = E_OS_SYS_SPINLOCKMETHOD;
    }

    /* SWS_Os_00690 if spinlock is already occupied on the same core */
    else if(Os_SpinlockState[SpinlockID] == CoreID)
    {
        OsHook_ReportErrorDisInt (CoreID, E_OS_INTERFERENCE_DEADLOCK, OSServiceId_GetSpinlock, OS_IE_NOMORE_INFO, (Os_uint32)SpinlockID, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR);
        ret = E_OS_INTERFERENCE_DEADLOCK;
    }
    else
    {
        /*do nothing*/
    }
    return ret;
}
#endif /*(OS_STATUS_LEVEL == OS_EXTENDED)*/
/*****************************************************************************
* OS Internal code
******************************************************************************/
/* BEGIN_FUNCTION_HDR
***********************************************************************************************
* Function Name: OsSpinlock_Init
*
* Description:   Initialize SpinLock
*
* Inputs:        None
*
* Outputs:       None
*
* Limitations:   None
***********************************************************************************************
END_FUNCTION_HDR*/
FUNC(void, OS_CODE) OsSpinlock_Init(void)
{
    SpinlockIdType i = (SpinlockIdType)0;

    for (i = (SpinlockIdType)0; i < (SpinlockIdType)OS_SPINLOCK_NUMBER; i++)
    {
        Os_SpinlockState[i] = (SpinlockType)OS_INVALID_COREID;
        OsSpinlock_Link[i] = OS_INVALID_SPINLOCK;
    }
}

/* BEGIN_FUNCTION_HDR
***********************************************************************************************
* Function Name: OsSpinLock_AutoReleaseISR
*
* Description:   Used to release spinlock locked by ISR in outISR,  killISR..
*
* Inputs:        CoreID,ISRID
*
* Outputs:       Os_boolean: has locked res?
*
* Limitations:   None
***********************************************************************************************
END_FUNCTION_HDR*/
FUNC(Os_boolean, OS_CODE) OsSpinLock_AutoReleaseISR
(
    CoreIdType CoreID,
    ISRType ISRID
)
{
    SpinlockIdType tempSpID;
    SpinlockIdType nextSpID;
    Os_boolean ret = OS_FALSE;
#if(OS_SPINKLOCK_LOCKSCH_SUPPORT != OS_ON)
    (void)CoreID;
#endif /*(OS_SPINKLOCK_LOCKSCH_SUPPORT != OS_ON)*/

    nextSpID = Os_ISRCBTable[ISRID].LastSpinLock;
    if(nextSpID != OS_INVALID_SPINLOCK)
    {
        ret = OS_TRUE;
        Os_ISRCBTable[ISRID].LastSpinLock = OS_INVALID_SPINLOCK;

        while(nextSpID != OS_INVALID_SPINLOCK)
        {
            Os_SpinlockState[nextSpID] = (SpinlockType)OS_INVALID_COREID;
            tempSpID = OsSpinlock_Link[nextSpID];
            OsSpinlock_Link[nextSpID] = OS_INVALID_SPINLOCK;
#if(OS_SPINKLOCK_LOCKSCH_SUPPORT == OS_ON)
            if(Os_SpinlockCfg[nextSpID].SpinlockMethod == OS_LOCK_WITH_RES_SCHEDULER)
            {
                if(Os_SpinlockDepth[CoreID] > (Os_uint8)0)
                {
                    Os_SpinlockDepth[CoreID]--;
                }
            }
#endif /*(OS_SPINKLOCK_LOCKSCH_SUPPORT == OS_ON)*/
            nextSpID = tempSpID;
        }
    }

    /* no need to release interrupt lock by spin lock here, as the OS kernel will release them in other place */

    return ret;
}

/* BEGIN_FUNCTION_HDR
***********************************************************************************************
* Function Name: OsSpinLock_AutoReleaseTask
*
* Description:   Used to release spinlock locked by Task in terminateTask,  killtask.
*
* Inputs:        CoreID,TaskID
*
* Outputs:       Os_boolean: has locked res?
*
* Limitations:   None
***********************************************************************************************
END_FUNCTION_HDR*/
FUNC(Os_boolean, OS_CODE) OsSpinLock_AutoReleaseTask
(
    CoreIdType CoreID,
    TaskType TaskID
)
{
    SpinlockIdType tempSpID;
    SpinlockIdType nextSpID;
    Os_boolean ret = OS_FALSE;
#if(OS_SPINKLOCK_LOCKSCH_SUPPORT != OS_ON)
    (void)CoreID;
#endif /*(OS_SPINKLOCK_LOCKSCH_SUPPORT != OS_ON)*/

    nextSpID = Os_TaskCBTable[TaskID].LastSpinLock;
    if(nextSpID != OS_INVALID_SPINLOCK)
    {
        ret = OS_TRUE;
        Os_TaskCBTable[TaskID].LastSpinLock = OS_INVALID_SPINLOCK;

        while(nextSpID != OS_INVALID_SPINLOCK)
        {
            Os_SpinlockState[nextSpID] = (SpinlockType)OS_INVALID_COREID;
            tempSpID = OsSpinlock_Link[nextSpID];
            OsSpinlock_Link[nextSpID] = OS_INVALID_SPINLOCK;
#if(OS_SPINKLOCK_LOCKSCH_SUPPORT == OS_ON)
            if(Os_SpinlockCfg[nextSpID].SpinlockMethod == OS_LOCK_WITH_RES_SCHEDULER)
            {
                if(Os_SpinlockDepth[CoreID] > (Os_uint8)0)
                {
                    Os_SpinlockDepth[CoreID]--;
                }
            }
#endif /*(OS_SPINKLOCK_LOCKSCH_SUPPORT == OS_ON)*/
            nextSpID = tempSpID;
        }
    }

    /* no need to release interrupt lock by spin lock here, as the OS kernel will release them in other place */

    return ret;
}

/*****************************************************************************
* OS API code
******************************************************************************/
/* BEGIN_FUNCTION_HDR
***********************************************************************************************
* Function Name: Os_GetSpinlock
*
* Description:   Os_GetSpinlock tries to occupy a spin-lock variable
*
* Inputs:        SpinlockId
*
* Outputs:       StatusType
*
* Limitations:   None
***********************************************************************************************
END_FUNCTION_HDR*/
FUNC(StatusType, OS_CODE) Os_GetSpinlock
( 
    SpinlockIdType SpinlockID 
)
{
    CoreIdType CoreID;
    Os_boolean tempPri;
    Os_SpinlockMethodType lockMethod;
    TaskType tempTaskID;
    ISRType tempIsrID;
    StatusType ret = E_OS_OK;

    CoreID = OsCpu_GetCoreID();

    ret = OsSpinlock_CheckGetSpinlockCondition(CoreID, SpinlockID);
    if(ret != E_OS_OK)
    {
        /* can not record err in this state, as OS services can not be called*/
        return ret;
    }

    lockMethod = Os_SpinlockCfg[SpinlockID].SpinlockMethod;

        /* enter Critical section here to protect this API */
    if(lockMethod == OS_LOCK_ALL_INTERRUPTS)
    {
        OsIsr_InternalSuspendAllInterrupts(CoreID);/* also start tp if enabled*/
    }
    else if(lockMethod == OS_LOCK_CAT2_INTERRUPTS)
    {
        OsIsr_InternalSuspendOsInterrupts(CoreID);/* also start tp if enabled*/
    }
    else
    {
        /* lock nothing, or lock sch*/
        OsCpu_EnterCritical(CoreID, &tempPri);
    }

    /*lock schedule can be done within the Critical section*/
#if(OS_SPINKLOCK_LOCKSCH_SUPPORT == OS_ON)
    if(lockMethod == OS_LOCK_WITH_RES_SCHEDULER)
    {
        /*PRQA S 3383 ++*/
        /* Possibility of overflow has been checked  before. */
        Os_SpinlockDepth[CoreID]++;
        /*PRQA S 3383 --*/
        if(Os_SpinlockDepth[CoreID] > OS_SPINLOCK_INVALD_NEST_LEVEL)
        {
            OsHook_FataErrReport(CoreID, E_OS_SYS_SPINLOCK_NEST_LIMIT_ERROR, OSServiceId_GetSpinlock, OS_IE_NOMORE_INFO, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR);
        }
    }
#endif /*(OS_SPINKLOCK_LOCKSCH_SUPPORT == OS_ON)*/
        
    /*SWS_Os_00687*/
    /*If the spinlock is already occupied, GetSpinlock shall keep on trying to occupy the spinlock until it succeeds*/
    OsCpu_GetSpinlock(&Os_SpinlockState[SpinlockID], CoreID);

    if(Os_CurrentContext[CoreID] == OS_CONTEXT_C2ISR)
    {

        tempIsrID = Os_CoreCfg[CoreID].nestIsrIdPtr[Os_IntNestDepth[CoreID]];


        OsSpinlock_Link[SpinlockID] = Os_ISRCBTable[tempIsrID].LastSpinLock;
        Os_ISRCBTable[tempIsrID].LastSpinLock = SpinlockID;
    }
    else if(Os_CurrentContext[CoreID] == OS_CONTEXT_TASK)
    {
        /* code */
        tempTaskID = Os_CurrentTaskId[CoreID];
        OsSpinlock_Link[SpinlockID] = Os_TaskCBTable[tempTaskID].LastSpinLock;
        Os_TaskCBTable[tempTaskID].LastSpinLock = SpinlockID;
    }
    else
    {
        /* do nothing err has checked before*/
    }
        
    if((lockMethod != OS_LOCK_ALL_INTERRUPTS) && (lockMethod != OS_LOCK_CAT2_INTERRUPTS))
    {
        OsCpu_ExitCritical(CoreID, tempPri);
    }

    return ret;
}

/* BEGIN_FUNCTION_HDR
***********************************************************************************************
* Function Name: Os_TryToGetSpinlock
*
* Description:   try to get spinlock once, not blocking
*
* Inputs:        SpinlockId
*
* Outputs:       Success, StatusType
*
* Limitations:   None
***********************************************************************************************
END_FUNCTION_HDR*/
FUNC(StatusType, OS_CODE) Os_TryToGetSpinlock
(    
    SpinlockIdType SpinlockID, 
    P2VAR(TryToGetSpinlockType, AUTOMATIC, OS_APPL_DATA) Success
)
{
    CoreIdType CoreID;
    Os_boolean tempPri;
    Os_SpinlockMethodType lockMethod;
    TaskType tempTaskID;
    ISRType tempIsrID;
#if(OS_STATUS_LEVEL == OS_EXTENDED)
    StatusType ret = E_OS_OK;
#endif /*(OS_STATUS_LEVEL == OS_EXTENDED)*/
    CoreID = OsCpu_GetCoreID();

#if(OS_STATUS_LEVEL == OS_EXTENDED)
    ret = OsSpinlock_CheckTryToGetSpinlockCondition(CoreID, SpinlockID, Success);
    if(ret != E_OS_OK)
    {
        return ret;
    }
#endif /*(OS_STATUS_LEVEL == OS_EXTENDED)*/

    lockMethod = Os_SpinlockCfg[SpinlockID].SpinlockMethod;

    /* enter Critical section here to protect this API */
    if(lockMethod == OS_LOCK_ALL_INTERRUPTS)
    {
        OsIsr_InternalSuspendAllInterrupts(CoreID);/* also start tp if enabled*/
    }
    else if(lockMethod == OS_LOCK_CAT2_INTERRUPTS)
    {
        OsIsr_InternalSuspendOsInterrupts(CoreID);/* also start tp if enabled*/
    }
    else
    {
        /* lock nothing, or lock sch*/
        OsCpu_EnterCritical(CoreID, &tempPri);
    }


    /* try to get spin lock first, and if success, do lock method*/
    /*PRQA S 3416 ++*/
    /* The side effect of "OsCpu_TryToGetSpinlock" is expected. */
    if(OS_TRUE == OsCpu_TryToGetSpinlock(&Os_SpinlockState[SpinlockID],CoreID))
    /*PRQA S 3416 --*/
    {
        /* if lock success, can lock the sch*/
#if(OS_SPINKLOCK_LOCKSCH_SUPPORT == OS_ON)
        if(lockMethod == OS_LOCK_WITH_RES_SCHEDULER)
        {
            /*PRQA S 3383 ++*/
            /*
            Can not overflow because there is comparison with max value after this statement
            */
            Os_SpinlockDepth[CoreID]++;
            /*PRQA S 3383 --*/
            if(Os_SpinlockDepth[CoreID] > OS_SPINLOCK_INVALD_NEST_LEVEL)
            {
                OsHook_FataErrReport(CoreID, E_OS_SYS_SPINLOCK_NEST_LIMIT_ERROR, OSServiceId_TryToGetSpinlock, OS_IE_NOMORE_INFO, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR);
            }
        }
#endif /*(OS_SPINKLOCK_LOCKSCH_SUPPORT == OS_ON)*/
        
        if(Os_CurrentContext[CoreID] == OS_CONTEXT_C2ISR)
        {

            tempIsrID = Os_CoreCfg[CoreID].nestIsrIdPtr[Os_IntNestDepth[CoreID]];


            OsSpinlock_Link[SpinlockID] = Os_ISRCBTable[tempIsrID].LastSpinLock;
            Os_ISRCBTable[tempIsrID].LastSpinLock = SpinlockID;
        }
        else if(Os_CurrentContext[CoreID] == OS_CONTEXT_TASK)
        {
            /* code */
            tempTaskID = Os_CurrentTaskId[CoreID];
            OsSpinlock_Link[SpinlockID] = Os_TaskCBTable[tempTaskID].LastSpinLock;
            Os_TaskCBTable[tempTaskID].LastSpinLock = SpinlockID;
        }
        else
        {
            /* do nothing err has checked before*/
        }

        *Success = TRYTOGETSPINLOCK_SUCCESS;

        /**/
        if((lockMethod != OS_LOCK_ALL_INTERRUPTS) && (lockMethod != OS_LOCK_CAT2_INTERRUPTS))
        {
            OsCpu_ExitCritical(CoreID, tempPri);
        }
    }
    else
    {
        /* lock fail */
        *Success = TRYTOGETSPINLOCK_NOSUCCESS;

        /* if lock interrpt method used, release the interrpt*/
        if(lockMethod == OS_LOCK_ALL_INTERRUPTS)
        {
            OsIsr_InternalResumeAllInterrupts(CoreID);/* also start tp if enabled*/
        }
        else if(lockMethod == OS_LOCK_CAT2_INTERRUPTS)
        {
            OsIsr_InternalResumeOsInterrupts(CoreID);/* also start tp if enabled*/
        }
        else
        {
            OsCpu_ExitCritical(CoreID, tempPri);
        }

    }
    return E_OS_OK;
}



/* BEGIN_FUNCTION_HDR
***********************************************************************************************
* Function Name: Os_ReleaseSpinlock
*
* Description:   Os_ReleaseSpinlock releases a spinlock variable that was occupied before
*
* Inputs:        SpinlockId
*
* Outputs:       StatusType
*
* Limitations:   None
***********************************************************************************************
END_FUNCTION_HDR*/
FUNC(StatusType, OS_CODE) Os_ReleaseSpinlock
(
    SpinlockIdType SpinlockID 
)
{
    CoreIdType CoreID;
    Os_boolean tempPri;
    Os_SpinlockMethodType lockMethod;
    TaskType tempTaskID;
    ISRType tempIsrID;
#if(OS_STATUS_LEVEL == OS_EXTENDED)
    StatusType ret = E_OS_OK;
#endif /*(OS_STATUS_LEVEL == OS_EXTENDED)*/
    CoreID = OsCpu_GetCoreID();

#if(OS_STATUS_LEVEL == OS_EXTENDED)
    ret = OsSpinlock_CheckReleaseSpinlockCondition(CoreID, SpinlockID);

    if(ret != E_OS_OK)
    {
        return ret;
    }
#endif /*(OS_STATUS_LEVEL == OS_EXTENDED)*/

    lockMethod = Os_SpinlockCfg[SpinlockID].SpinlockMethod;

    if((lockMethod != OS_LOCK_ALL_INTERRUPTS) && (lockMethod != OS_LOCK_CAT2_INTERRUPTS))
    {
        OsCpu_EnterCritical(CoreID, &tempPri);
    }

    /*PRQA S 3109,3138 ++*/
    /*
    Assembly instructions replaced by null statement just for QAC prj, 
    because PRQA can not parse assembly instructions.
    */
    OsCpu_ReleaseSpinlock(&Os_SpinlockState[SpinlockID]);
    /*PRQA S 3109,3138 --*/

    if(Os_CurrentContext[CoreID] == OS_CONTEXT_C2ISR)
    {

        tempIsrID = Os_CoreCfg[CoreID].nestIsrIdPtr[Os_IntNestDepth[CoreID]];


        Os_ISRCBTable[tempIsrID].LastSpinLock = OsSpinlock_Link[SpinlockID];
        OsSpinlock_Link[SpinlockID] = OS_INVALID_SPINLOCK;
    }
    else if(Os_CurrentContext[CoreID] == OS_CONTEXT_TASK)
    {
        tempTaskID = Os_CurrentTaskId[CoreID];
        Os_TaskCBTable[tempTaskID].LastSpinLock = OsSpinlock_Link[SpinlockID];
        OsSpinlock_Link[SpinlockID] = OS_INVALID_SPINLOCK;
    }
    else
    {
        /*do nothing*/
    }

    /* if lock interrpt method used, release the interrpt*/
    if(lockMethod == OS_LOCK_ALL_INTERRUPTS)
    {
        OsIsr_InternalResumeAllInterrupts(CoreID);/* also start tp if enabled*/
    }
    else if(lockMethod == OS_LOCK_CAT2_INTERRUPTS)
    {
        OsIsr_InternalResumeOsInterrupts(CoreID);/* also start tp if enabled*/
    }
    else
    {

#if(OS_SPINKLOCK_LOCKSCH_SUPPORT == OS_ON)
        if(lockMethod == OS_LOCK_WITH_RES_SCHEDULER)
        {
            if(Os_SpinlockDepth[CoreID] > (Os_uint8)0)
            {
                Os_SpinlockDepth[CoreID]--;
            }
        }
#endif /*(OS_SPINKLOCK_LOCKSCH_SUPPORT == OS_ON)*/

        OsCpu_ExitCritical(CoreID, tempPri);
    }

    return E_OS_OK;
}

#define OS_STOP_SEC_CODE
#include "Os_MemMap.h"

#endif /*(OS_SPINLOCK_NUMBER > 0)*/
