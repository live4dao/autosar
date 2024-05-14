/*  BEGIN_FILE_HDR
********************************************************************************
*   NOTICE
*   This software is the property of HiRain Technologies. Any information
*   contained in this doc should not be reproduced, or used, or disclosed
*   without the written authorization from HiRain Technologies.
********************************************************************************
*   File Name       : Os_ISR.c
********************************************************************************
*   Project/Product : AUTOSAR OS PROJECT
*   Title           : Os_ISR.c
*   Author          : Hirain
********************************************************************************
*   Description     : Definitions of OS prototypes.
*
********************************************************************************
*   Limitations     : None
*
********************************************************************************
*
********************************************************************************
*   Revision History:
*   Reference to Core Os_Kernel.c File
********************************************************************************
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

/*******************************************************************************
*   Static Function Define
*******************************************************************************/
#define OS_START_SEC_CODE
#include "Os_MemMap.h"
STATIC FUNC(void, OS_CODE)  OsIsr_EnterISR
(
    CoreIdType CoreID,
    ISRType ISRID,
    Os_boolean isRestore
);
STATIC FUNC(void, OS_CODE)  OsIsr_ExitISR
(
    CoreIdType CoreID,
    ISRType ISRID,
    Os_boolean isPreempt
);

STATIC FUNC(void, OS_CODE) OsIsr_InitISRCBT
(
    ISRType ISRID,
    Os_boolean isKill
);
/* BEGIN_FUNCTION_HDR
***********************************************************************************************
* Function Name: OsIsr_EnterISR
*
* Description:   called when enter an ISR
*
* Inputs:        CoreID, ISRID, isRestore
*
* Outputs:       None
*
* Limitations:  
***********************************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, OS_CODE)  OsIsr_EnterISR
(
    CoreIdType CoreID,
    ISRType ISRID,
    Os_boolean isRestore
)
{
#if(OS_CRC_SUPPORT == OS_ON)
#if(OS_ON == OS_ISR_NEST_SUPPORT)
    P2VAR(Os_ISRCBType, AUTOMATIC, OS_VAR) temp_Icb_vp;
    temp_Icb_vp = &(Os_ISRCBTable[ISRID]);
#endif /*(OS_ON == OS_ISR_NEST_SUPPORT)*/
#endif /*(OS_CRC_SUPPORT == OS_ON)*/

    /*start new ISR tp monitor*/
    if(isRestore == OS_FALSE)
    {
        OsTp_IsrExecutionBudgetStart(CoreID, ISRID);
        OsTp_IsrTimeFrameCheck(CoreID, ISRID);
    }
    else
    {
#if(OS_CRC_SUPPORT == OS_ON)
#if(OS_ON == OS_ISR_NEST_SUPPORT)
        /* check CRC of saved context*/
        /*PRQA S 3416 ++*/
        /* The side effect of "OsCrc_Calculate" is expected. */
        if(temp_Icb_vp->crcResult != OsCrc_Calculate(temp_Icb_vp->OsIsrCtxPtr))
        /*PRQA S 3416 --*/
        {
            OsHook_FataErrReport(CoreID, E_OS_SYSFATA_CONTEXTCRC_ERR, OSServiceId_OsIsr_EnterISR, OS_IE_NOMORE_INFO, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR);
        }
#endif /*(OS_ON == OS_ISR_NEST_SUPPORT)*/
#endif /*(OS_CRC_SUPPORT == OS_ON)*/

        OsTp_IsrRestore(CoreID, ISRID);
    }
    
    Os_CurrentContext[CoreID] = OS_CONTEXT_C2ISR;
#if(OS_APPLICATION_NUMBER > 0)
    Os_CurrentApplicationId[CoreID] = Os_ISRCfg[ISRID].ApplID;
#endif /*(OS_APPLICATION_NUMBER > 0)*/
    Os_ISRCBTable[ISRID].isrState = OS_ISR_RUNNING;

    OsHook_PreISRHook(CoreID);
}


/* BEGIN_FUNCTION_HDR
***********************************************************************************************
* Function Name: OsIsr_ExitISR
*
* Description:   called when leave current ISR
*                isPreempt = true: ISR is preempted by other high pririoty ISR
*                isPreempt = false:ISR end
*
*
* Inputs:        CoreID, ISRID, isPreempt
*
* Outputs:       None
*
* Limitations:  OutC2Isr do not call this function
***********************************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, OS_CODE)  OsIsr_ExitISR
(
    CoreIdType CoreID,
    ISRType ISRID,
    Os_boolean isPreempt
)
{
    ISRStateType nextState;

    if(OS_TRUE == isPreempt)
    {
        OsTp_IsrPause(CoreID, ISRID);
        nextState = OS_ISR_READY;
    }
    else
    {
        OsTp_IsrExecutionBudgetStop(CoreID, ISRID);
        nextState = OS_ISR_SUSPENDED;
    }

#ifndef OS_HW_CHK_STACK_SUPPORT
#if(OS_CHK_STACK == OS_ON)
    if(Os_ISRCfg[ISRID].OsIsrStkTop[0] != OS_STACKINIT_VALUE)
    {
        OsHook_FataErrReport(CoreID, E_OS_STACKFAULT, OSServiceId_OsIsr_ExitISR, OS_IE_NOMORE_INFO, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR);
    }
#endif /*(OS_CHK_STACK == OS_ON)*/
#endif

    OsHook_PostISRHook(CoreID);

#if(OS_APPLICATION_NUMBER > 0)
    Os_CurrentApplicationId[CoreID] = OS_INVALID_OSAPPLICATION;
#endif /*(OS_APPLICATION_NUMBER > 0)*/
    Os_CurrentContext[CoreID] = OS_CONTEXT_KERNEL;
    Os_ISRCBTable[ISRID].isrState = nextState;
}

/* BEGIN_FUNCTION_HDR
***********************************************************************************************
* Function Name: OsIsr_InitISRCBT
*
* Description:   Init ISR CBT 
*
* Inputs:        ISRID, isKill
*
* Outputs:       None
*
* Limitations:  None
***********************************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, OS_CODE) OsIsr_InitISRCBT
(
    ISRType ISRID,
    Os_boolean isKill
)
{
    P2VAR(Os_ISRCBType, AUTOMATIC, OS_VAR) Os_Tcb_vp_temp;

    Os_Tcb_vp_temp = &(Os_ISRCBTable[ISRID]);

#if(OS_ON == OS_ISR_NEST_SUPPORT)
    Os_Tcb_vp_temp->OsIsrCtxPtr = (Os_AddrType)0;
#endif /*(OS_ON == OS_ISR_NEST_SUPPORT)*/
#if(OS_RESOURCE_NUMBER > 0)
    Os_Tcb_vp_temp->LastResId = OS_INVALID_RES_ID;
#endif /*(OS_RESOURCE_NUMBER > 0)*/

#if(OS_SPINLOCK_NUMBER > 0)
    Os_Tcb_vp_temp->LastSpinLock = OS_INVALID_SPINLOCK;
#endif /*(OS_SPINLOCK_NUMBER > 0)*/

    /* init tp related vars */
#if(OS_ON == OS_TP_ISR_ANYBUDGET_SUPPORT)
    Os_Tcb_vp_temp->tpNestIndex = OS_TP_INVALID_NEST_LEVEL;
    Os_Tcb_vp_temp->tpStartTs = (Os_TpTickType)0;
#endif /*(OS_ON == OS_TP_ISR_ANYBUDGET_SUPPORT)*/

#if(OS_TP_ISR_TIMEFRAME_SUPPORT == OS_ON)
    Os_Tcb_vp_temp->timeFrameFirstFlag = OS_TRUE;
    Os_Tcb_vp_temp->frameLastTs = (Os_TpTickType)0;
#endif /*(OS_TP_ISR_TIMEFRAME_SUPPORT == OS_ON)*/

#if(OS_APPLICATION_NUMBER > 0)
    Os_Tcb_vp_temp->isKilled = isKill;
#else
    /*PRQA S 3119 ++*/
    /*Using useless statement to avoid QAC warns unused variable.*/
    (void)isKill;
    /*PRQA S 3119 --*/
#endif /*(OS_APPLICATION_NUMBER > 0)*/
    Os_Tcb_vp_temp->isrState = OS_ISR_SUSPENDED;
}


/*******************************************************************************
*   OS Internal Function Define
*******************************************************************************/

/* BEGIN_FUNCTION_HDR
***********************************************************************************************
* Function Name: OsIsr_Init
*
* Description:   Initilize interrupts
*
* Inputs:        CoreID
*
* Outputs:       None
*
* Limitations:   None
***********************************************************************************************
END_FUNCTION_HDR*/
FUNC(void, OS_CODE) OsIsr_Init
(
    CoreIdType CoreID
)
{
    ISRType i;
    ISRType endc2IsrId;

#ifndef OS_HW_CHK_STACK_SUPPORT
#if(OS_CHK_STACK == OS_ON)
    Os_uint16 stackIndex;
#endif /*(OS_CHK_STACK == OS_ON)*/
#endif

    OsISR_IntAPINesting[CoreID] = (Os_uint8)0;
    Os_IntAPIUsedFlag[CoreID] = OS_NO_API_USED;

    endc2IsrId = Os_CoreCfg[CoreID].startIsrId + Os_CoreCfg[CoreID].c2IsrNum;

    for(i = Os_CoreCfg[CoreID].startIsrId; i < endc2IsrId; i++)
    {
        OsIsr_InitISRCBT(i, OS_FALSE);

#ifndef OS_HW_CHK_STACK_SUPPORT
#if(OS_CHK_STACK == OS_ON)
        /* Initialization the system stack of current core. */
        for(stackIndex = (Os_uint16)0; stackIndex < Os_ISRCfg[i].OsIsrStkSize; stackIndex++)
        {
#if(OS_PL_STACK_GROW_DIR == OS_PL_STACK_GROW_DOWN)
            Os_ISRCfg[i].OsIsrStkTop[stackIndex] = OS_STACKINIT_VALUE;
#else
            Os_ISRCfg[i].OsIsrStkBottom[stackIndex] = OS_STACKINIT_VALUE;
#endif /*f(OS_PL_STACK_GROW_DIR == OS_PL_STACK_GROW_DOWN)*/
        }
#endif /*(OS_CHK_STACK == OS_ON)*/
#endif
    }

    Os_IntNestDepth[CoreID] = OS_INVALID_ISR;
    Os_C1IntNestDepth[CoreID] = OS_INVALID_ISR;
    for(i = (ISRType)0; i < Os_CoreCfg[CoreID].c2IsrNum; i++)
    {
        Os_CoreCfg[CoreID].nestIsrIdPtr[i] = OS_INVALID_ISR;
    }
}

/* BEGIN_FUNCTION_HDR
***********************************************************************************************
* Function Name: OsIsr_AutoResumeInterrupt
*
* Description:   auto resume interrupt when leaving task or ISR, used by service protection
*
* Inputs:        CoreID
*
* Outputs:       None
*
* Limitations:   None
***********************************************************************************************
END_FUNCTION_HDR*/
FUNC(Os_boolean, OS_CODE) OsIsr_AutoResumeInterrupt
(
    CoreIdType CoreID
)
{
    Os_boolean ret = OS_FALSE;
    
    /*as this function is called by OS internal, when task or ISR is terminate,  where gloabl interrupt is disabled by OS kernel
      so we only reset the Os_IntAPIUsedFlag and OsISR_IntAPINesting here , dont enable interrupt
      also tp of intlock will be released by tp module,not here.
    */
    
    OsISR_IntAPINesting[CoreID] = (Os_uint8)0;
    

    if(Os_IntAPIUsedFlag[CoreID] != OS_NO_API_USED)
    {
        if(OS_SUS_OS_API_USED == Os_IntAPIUsedFlag[CoreID])
        {
            OsIntc_ResumeOsInterrupts(CoreID);
        }
        ret = OS_TRUE;
        Os_IntAPIUsedFlag[CoreID] = OS_NO_API_USED;
    }

    return ret;
}




/* BEGIN_FUNCTION_HDR
***********************************************************************************************
* Function Name: OsIsr_InISR1
*
* Description:   Called in  OsIntc_InISR1. only process context and cpu load 
*
* Inputs:        CoreID
*
* Outputs:       None
*
* Limitations:   dont need to switch stack, MPU and global interrupt will be processed in portable layer
***********************************************************************************************
END_FUNCTION_HDR*/
FUNC(void, OS_CODE) OsIsr_InISR1
(
    CoreIdType CoreID
)
{
    /* first into C1 ISR */
    if(Os_C1IntNestDepth[CoreID] == OS_INVALID_ISR)
    {

#if(OS_CPULOAD_API == OS_ON)
        if((Os_CurrentContext[CoreID] == OS_CONTEXT_TASK) \
        && (Os_CurrentTaskId[CoreID] == Os_CoreCfg[CoreID].idleTaskId))
        {
            OsKernel_CheckCpuLoad(CoreID, OS_FALSE);
        }
#endif /*(OS_CPULOAD_API == OS_ON)*/
        Os_CurrentContext[CoreID] = OS_CONTEXT_C1ISR;
        Os_C1IntNestDepth[CoreID] = (ISRType)0;
    }
    else
    {
        /*PRQA S 3383 ++*/
        /*
        The limit of "Os_C1IntNestDepth" is ".c1IsrNum" which will be checked below.
        ".c1IsrNum" is generated by tool and can not overflow.
        */
        Os_C1IntNestDepth[CoreID]++;
        /*PRQA S 3383 --*/
        /* fata check*/
        if(Os_C1IntNestDepth[CoreID] >= Os_CoreCfg[CoreID].c1IsrNum)
        {
            OsHook_FataErrReport(CoreID, E_OS_SYSFATA_ISR_NEST_LIMIT_ERROR, OSServiceId_OsIsr_InISR1, OS_IE_NOMORE_INFO, (Os_uint32)Os_C1IntNestDepth[CoreID], OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR);
        }
    }
}

/* BEGIN_FUNCTION_HDR
***********************************************************************************************
* Function Name: OsIsr_OutISR1
*
* Description:   Called in  OsIntc_OutISR1. only process context and cpu load 
*
* Inputs:        CoreID
*
* Outputs:       None
*
* Limitations:   dont need to switch stack, MPU and global interrupt will be processed in portable layer
***********************************************************************************************
END_FUNCTION_HDR*/
FUNC(void, OS_CODE) OsIsr_OutISR1
(
    CoreIdType CoreID
)
{
    if(Os_C1IntNestDepth[CoreID] == OS_INVALID_ISR)
    {
        OsHook_FataErrReport(CoreID, E_OS_SYSFATA_ISR_NEST_LIMIT_ERROR, OSServiceId_OsIsr_OutISR1, OS_IE_NOMORE_INFO, (Os_uint32)Os_C1IntNestDepth[CoreID], OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR);
    }

    /* first */
    if(Os_C1IntNestDepth[CoreID] == (ISRType)0)
    {
        Os_C1IntNestDepth[CoreID] = OS_INVALID_ISR;
        if(Os_IntNestDepth[CoreID] != OS_INVALID_ISR)/* return to C2 ISR*/
        {
            Os_CurrentContext[CoreID] = OS_CONTEXT_C2ISR;
        }
        else
        {
            /* code */
            if(Os_CurrentTaskId[CoreID] == Os_CoreCfg[CoreID].idleTaskId) /* return to Idle Task*/
            {
                Os_CurrentContext[CoreID] = OS_CONTEXT_KERNEL;
#if(OS_CPULOAD_API == OS_ON)
                OsKernel_CheckCpuLoad(CoreID, OS_TRUE);
#endif /*(OS_CPULOAD_API == OS_ON)*/
            }
            else/* return to user task*/
            {
                Os_CurrentContext[CoreID] = OS_CONTEXT_TASK;
            }
        }
    }
    else
    {
        Os_C1IntNestDepth[CoreID]--;
    }
}

/* BEGIN_FUNCTION_HDR
***********************************************************************************************
* Function Name: OsIsr_InISR2
*
* Description:   Called  in ISRC2
*
*
* Inputs:        CoreID, ISRID ,ctxAddr
*
* Outputs:       None
*
* Limitations:   Ctx save, mpu switch,  must be done before
***********************************************************************************************
END_FUNCTION_HDR*/
FUNC(void, OS_CODE)  OsIsr_InISR2
(
    CoreIdType CoreID,
    ISRType ISRID,
    Os_AddrType ctxAddr
)
{
#if(OS_ON == OS_ISR_NEST_SUPPORT)
    ISRType tempIsrId;
#endif /*(OS_ON == OS_ISR_NEST_SUPPORT)*/

    if(OS_INVALID_ISR == Os_IntNestDepth[CoreID])
    {
        Os_TaskCBTable[Os_CurrentTaskId[CoreID]].OsTaskCtxPtr = ctxAddr;

        /* when interrupted by ISR, task is also into ready state
           when ISR end, task restore to running , if ISR jump to other higheset task ,this task keep ready
        */
#if(OS_CRC_SUPPORT == OS_ON)
        Os_TaskCBTable[Os_CurrentTaskId[CoreID]].crcResult = OsCrc_Calculate(ctxAddr);
#endif /*(OS_CRC_SUPPORT == OS_ON)*/
        OsKernel_ExitTask(CoreID, OS_TRUE, OS_TASK_READY);
        Os_IntNestDepth[CoreID] = (ISRType)0;
    }
    else
    {
#if(OS_ON == OS_ISR_NEST_SUPPORT)
        tempIsrId = Os_CoreCfg[CoreID].nestIsrIdPtr[Os_IntNestDepth[CoreID]];
#if(OS_CRC_SUPPORT == OS_ON)
        Os_ISRCBTable[tempIsrId].crcResult = OsCrc_Calculate(ctxAddr);
#endif /*(OS_CRC_SUPPORT == OS_ON)*/
        OsIsr_ExitISR(CoreID, tempIsrId, OS_TRUE);

        /*PRQA S 3383 ++*/
        /*
        ".maxNestSize" is limit of "Os_IntNestDepth" and will be checked below.
        ".maxNestSize" is generated by tool and can not overflow.
        */
        Os_IntNestDepth[CoreID]++;
        /*PRQA S 3383 --*/

        Os_ISRCBTable[tempIsrId].OsIsrCtxPtr = ctxAddr;
#else
        /*fataerr*/
#endif /*(OS_ON == OS_ISR_NEST_SUPPORT)*/
    }

    if(Os_IntNestDepth[CoreID] >= Os_CoreCfg[CoreID].maxNestSize)
    {
        OsHook_FataErrReport(CoreID, E_OS_SYSFATA_ISR_NEST_LIMIT_ERROR, OSServiceId_OsIsr_InISR2, OS_IE_NOMORE_INFO, (Os_uint32)Os_IntNestDepth[CoreID], OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR);
    }

    Os_CoreCfg[CoreID].nestIsrIdPtr[Os_IntNestDepth[CoreID]] = ISRID;

    OsIsr_EnterISR(CoreID, ISRID, OS_FALSE);
}

/* BEGIN_FUNCTION_HDR
***********************************************************************************************
* Function Name: OsIsr_OutISR2
*
* Description:   Called  in ISRC2
*
*
* Inputs:        CoreID, ISRID
*
* Outputs:       Os_boolean: need schedule
*
* Limitations:   None
***********************************************************************************************
END_FUNCTION_HDR*/
FUNC(Os_boolean, OS_CODE)  OsIsr_OutISR2
(
    CoreIdType CoreID
)
{
    Os_boolean schFlag = OS_FALSE;
    ISRType currentIsrId = OS_INVALID_ISR;
    ISRType nextIsrId;
    ISRType nestIndex = Os_IntNestDepth[CoreID];


    /*Step1 check the ISR vars valid or not */
    if(nestIndex >= Os_CoreCfg[CoreID].maxNestSize) /* this condition include the queue empty state(nestIndex = OS_INVALID_ISR)*/
    {
        /*nest index err*/
        OsHook_FataErrReport(CoreID, E_OS_SYSFATA_ISR_NEST_LIMIT_ERROR, OSServiceId_OsIsr_OutISR2, OS_IE_NOMORE_INFO, (Os_uint32)nestIndex, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR);

    }
    else
    {
        currentIsrId = Os_CoreCfg[CoreID].nestIsrIdPtr[nestIndex];
        if(Os_IntNestDepth[CoreID] > (ISRType)0)
        {
            Os_IntNestDepth[CoreID]--;
        }
        else
        {
            Os_IntNestDepth[CoreID] = OS_INVALID_ISR;
        }
    }


    if((currentIsrId >= (Os_CoreCfg[CoreID].startIsrId + Os_CoreCfg[CoreID].c2IsrNum)) || (currentIsrId < Os_CoreCfg[CoreID].startIsrId))
    {
        OsHook_FataErrReport(CoreID, E_OS_SYSFATA_ISR_NEST_ID_ERROR, OSServiceId_OsIsr_OutISR2, OS_IE_NOMORE_INFO, (Os_uint32)currentIsrId, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR);
    }


    /*Step2 release all un-released locks  */
    /* [SWS_Os_00368] */
    /*PRQA S 3416 ++*/
    /* The side effect of "OsIsr_AutoResumeInterrupt" is expected. */
    if(OS_TRUE == OsIsr_AutoResumeInterrupt(CoreID))
    /*PRQA S 3416 --*/
    {
        OsHook_ReportErrorDisInt(CoreID, E_OS_DISABLEDINT, OSServiceId_OsIsr_OutISR2, OS_IE_NOMORE_INFO, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR);
    }

#if(OS_RESOURCE_NUMBER > 0)
    /*SWS_Os_00369*/
    /* check CRC of saved context*/
    /*PRQA S 3416 ++*/
    /* The side effect of "OsRes_AutoReleaseISRResource" is expected. */
    if(OS_TRUE == OsRes_AutoReleaseISRResource(CoreID, currentIsrId))
    /*PRQA S 3416 --*/
    {
        OsHook_ReportErrorDisInt(CoreID, E_OS_RESOURCE, OSServiceId_OsIsr_OutISR2, OS_IE_NOMORE_INFO, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR);
    }
#endif /*(OS_RESOURCE_NUMBER > 0)*/


#if(OS_SPINLOCK_NUMBER > 0)
    /*PRQA S 3416 ++*/
    /* The side effect of "OsSpinLock_AutoReleaseISR" is expected. */
    if(OS_TRUE == OsSpinLock_AutoReleaseISR(CoreID, currentIsrId))
    /*PRQA S 3416 --*/
    {
        OsHook_ReportErrorDisInt(CoreID, E_OS_SPINLOCK, OSServiceId_OsIsr_OutISR2, OS_IE_NOMORE_INFO, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR);
    }
#endif /*(OS_SPINLOCK_NUMBER > 0)*/

    /*Step3 stop the time monitor of current ISR */
    OsIsr_ExitISR(CoreID, currentIsrId, OS_FALSE);

    if(Os_IntNestDepth[CoreID] != OS_INVALID_ISR)
    {
        /* return to last ISR*/
        /* Os_CurrentContext keep C2 unchange*/
        nextIsrId = Os_CoreCfg[CoreID].nestIsrIdPtr[Os_IntNestDepth[CoreID]];
        OsIsr_EnterISR(CoreID, nextIsrId, OS_TRUE);
    }
    else
    {
        /* no nest or last ISR out, return to task */
        Os_CurrentContext[CoreID] = OS_CONTEXT_KERNEL;
        /*PRQA S 3416 ++*/
        /* The side effect of "OsKernel_NeedSchedule" is expected. */
        if(OS_TRUE == OsKernel_NeedSchedule(CoreID, OS_FALSE))
        /*PRQA S 3416 --*/
        {
            /* Task has exit when in ISR*/
            /* return to task switch */
            schFlag = OS_TRUE;
        }
        else
        {
            OsKernel_EnterTask(CoreID, OS_TRUE);/* ready to restore task*/
        }
    }

    return schFlag;
}

/* BEGIN_FUNCTION_HDR
***********************************************************************************************
* Function Name: OsIsr_InternalSuspendAllInterrupts
*
* Description:   suspend all Interrupts
*
*
* Inputs:        CoreID
*
* Outputs:       None
*
* Limitations:   This will also be used in spinklock module
***********************************************************************************************
END_FUNCTION_HDR*/
FUNC(void, OS_CODE) OsIsr_InternalSuspendAllInterrupts
(
    CoreIdType CoreID
)
{
    if((Os_uint8)0 == OsISR_IntAPINesting[CoreID])
    {
        OsIntc_DisableAllInterrupts(CoreID);
        Os_IntAPIUsedFlag[CoreID] = OS_SUS_ALL_API_USED;
        OsTp_IsrLockTimeStart(CoreID, OS_TRUE);
    }

    /*PRQA S 3383 ++*/
    /*
    The macro "OS_INTAPI_MAX_NEST_VALUE" is limit of "OsISR_IntAPINesting"
    and will be checked below.
    The macro "OS_INTAPI_MAX_NEST_VALUE" is generated by tool and can not
    overflow.
    */
    OsISR_IntAPINesting[CoreID]++;
    /*PRQA S 3383 --*/

    if(OsISR_IntAPINesting[CoreID] >= OS_INTAPI_MAX_NEST_VALUE)
    {
        OsHook_FataErrReport(CoreID, E_OS_SYSFATA_ISRAPI_NEST_LIMIT_ERROR, OSServiceId_SuspendAllInterrupts, OS_IE_NOMORE_INFO, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR);
    }
}

/* BEGIN_FUNCTION_HDR
***********************************************************************************************
* Function Name: OsIsr_InternalResumeAllInterrupts
*
* Description:   resume all Interrupts
*
*
* Inputs:        CoreID
*
* Outputs:       None
*
* Limitations:   This will also be used in spinklock module
***********************************************************************************************
END_FUNCTION_HDR*/
FUNC(void, OS_CODE) OsIsr_InternalResumeAllInterrupts
(
    CoreIdType CoreID
)
{
    if(OsISR_IntAPINesting[CoreID] > (ISRType)0)
    {
        OsISR_IntAPINesting[CoreID]--;
        if((Os_uint8)0 == OsISR_IntAPINesting[CoreID])
        {
            Os_IntAPIUsedFlag[CoreID] = OS_NO_API_USED;
            OsTp_IsrLockTimeStop(CoreID, OS_TRUE);
            OsIntc_ResumeAllInterrupts(CoreID);
        }
    }
    else
    {
        OsHook_FataErrReport(CoreID, E_OS_SYSFATA_ISRAPI_NEST_LIMIT_ERROR, OSServiceId_ResumeAllInterrupts, OS_IE_NOMORE_INFO, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR);
    }
}

/* BEGIN_FUNCTION_HDR
***********************************************************************************************
* Function Name: OsIsr_InternalSuspendOsInterrupts
*
* Description:   suspend C2 Interrupts
*
*
* Inputs:        CoreID
*
* Outputs:       None
*
* Limitations:   This will also be used in spinklock module
***********************************************************************************************
END_FUNCTION_HDR*/
FUNC(void, OS_CODE) OsIsr_InternalSuspendOsInterrupts
(
    CoreIdType CoreID
)
{
    if((Os_uint8)0 == OsISR_IntAPINesting[CoreID])
    {
        /* when tp enable, tp timer ISR can not be disabled */
        OsIntc_SuspendOsInterrupts(CoreID);
        OsTp_IsrLockTimeStart(CoreID, OS_FALSE);
        Os_IntAPIUsedFlag[CoreID] = OS_SUS_OS_API_USED;

    }

    /*PRQA S 3383 ++*/
    /*
    The macro "OS_INTAPI_MAX_NEST_VALUE" is limit of "OsISR_IntAPINesting"
    and will be checked below.
    The macro "OS_INTAPI_MAX_NEST_VALUE" is generated by tool and can not
    overflow.
    */
    OsISR_IntAPINesting[CoreID]++;
    /*PRQA S 3383 --*/

    if(OsISR_IntAPINesting[CoreID] >= OS_INTAPI_MAX_NEST_VALUE)
    {
        OsHook_FataErrReport(CoreID, E_OS_SYSFATA_ISRAPI_NEST_LIMIT_ERROR, OSServiceId_SuspendOSInterrupts, OS_IE_NOMORE_INFO, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR);
    }
}

/* BEGIN_FUNCTION_HDR
***********************************************************************************************
* Function Name: OsIsr_InternalResumeOsInterrupts
*
* Description:   resume C2 Interrupts
*
*
* Inputs:        CoreID
*
* Outputs:       None
*
* Limitations:   This will also be used in spinklock module
***********************************************************************************************
END_FUNCTION_HDR*/
FUNC(void, OS_CODE) OsIsr_InternalResumeOsInterrupts
(
    CoreIdType CoreID
)
{
    if((Os_uint8)0 != OsISR_IntAPINesting[CoreID])
    {
        OsISR_IntAPINesting[CoreID]--;
        if((Os_uint8)0 == OsISR_IntAPINesting[CoreID])
        {
            Os_IntAPIUsedFlag[CoreID] = OS_NO_API_USED;
            OsTp_IsrLockTimeStop(CoreID, OS_FALSE);
            OsIntc_ResumeOsInterrupts(CoreID);
        }
    }
    else
    {
        OsHook_FataErrReport(CoreID, E_OS_SYSFATA_ISRAPI_NEST_LIMIT_ERROR, OSServiceId_ResumeOSInterrupts, OS_IE_NOMORE_INFO, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR);
    }
}

#if(OS_APPLICATION_NUMBER > 0)
/* BEGIN_FUNCTION_HDR
***********************************************************************************************
* Function Name: OsISR_RemoveAndSortISRQueue
*
* Description:   Called  in TerminateApp, when ISR to be killed nested in queue, remove it
*
* Inputs:        None
*
* Outputs:       None
*
* Limitations:   None
***********************************************************************************************
END_FUNCTION_HDR*/
FUNC(void, OS_CODE) OsIsr_RemoveAndSortISRQueue
(
    CoreIdType CoreID,
    ApplicationType ApplID
)
{
    /*PRQA S 4643 ++*/
    /* Do not include <ctype.h> */
    ISRType isrIdx;
    /*PRQA S 4643 --*/
    ISRType emptyIdx = OS_INVALID_ISR;
    ISRType tmpIsrId;
    P2VAR(ISRType, AUTOMATIC, OS_VAR) nestPtr;


    if(OS_INVALID_ISR == Os_IntNestDepth[CoreID])/* no ISR nested*/
    {
        return;
    }

    nestPtr = Os_CoreCfg[CoreID].nestIsrIdPtr;

    /* loop and remove all ISR belongs to this app, at same time re-sort the queue*/
    for(isrIdx = (ISRType)0; isrIdx <= Os_IntNestDepth[CoreID]; isrIdx++)
    {
        tmpIsrId = nestPtr[isrIdx];

        if(Os_ISRCfg[tmpIsrId].ApplID == ApplID)/* need remove it*/
        {
            nestPtr[isrIdx] = OS_INVALID_ISR;
            /* set 1st empty position */
            if(emptyIdx == OS_INVALID_ISR)
            {
                emptyIdx = isrIdx;
            }
        }
        else
        {
            if(emptyIdx != OS_INVALID_ISR)
            {
                nestPtr[emptyIdx] = tmpIsrId;/* shift current to empty position*/
                /*current is new empty position*/
                nestPtr[isrIdx] = OS_INVALID_ISR;

                /* move emptyIdx to next empty position
                just add emptyIdx. as next position must be empty, old non empty element ahs been shifted*/
                /*PRQA S 3383 ++*/
                /* The max value of "emptyIdx" is controlled by "for" loop. */
                emptyIdx++;
                /*PRQA S 3383 --*/
            }
        }
    }

    /* finally update the Os_IntNestDepth*/
    if(emptyIdx != OS_INVALID_ISR)
    {
        if(emptyIdx == (ISRType)0)/* queue is empty*/
        {
            Os_IntNestDepth[CoreID] = OS_INVALID_ISR;
        }
        else
        {
            Os_IntNestDepth[CoreID] = emptyIdx - (ISRType)1;
        }

    }
    /* if emptyIdx = OS_INVALID_ISR, means no ISR removed, keep Os_IntNestDepth unchange*/
}

/* BEGIN_FUNCTION_HDR
***********************************************************************************************
* Function Name: OsIsr_KillISR
*
* Description:   None
*
* Inputs:        None
*
* Outputs:       None
*
* Limitations:   None
***********************************************************************************************
END_FUNCTION_HDR*/
FUNC(void, OS_CODE) OsIsr_KillISR
(
    CoreIdType CoreID,
    ISRType ISRID
)
{
    /*PRQA S 4643 ++*/
    /* Do not include <ctype.h> */
    ISRStateType isrState = Os_ISRCBTable[ISRID].isrState;
    /*PRQA S 4643 --*/

    if(isrState == OS_ISR_RUNNING)
    {
        /* do not process running ISR here*/
        return;
    }

    if(isrState == OS_ISR_READY)
    {

        /* auto release, as this kill process , no need to report error*/
        /* No need to call OsIsr_AutoResumeInterrupt, as if ISR is not running thread, its not possible that interrupt is locked by it*/

#if(OS_RESOURCE_NUMBER > 0)
        (void)OsRes_AutoReleaseISRResource(CoreID,ISRID);
#endif /*(OS_RESOURCE_NUMBER > 0)*/
#if(OS_SPINLOCK_NUMBER > 0)
        (void)OsSpinLock_AutoReleaseISR(CoreID,ISRID);
#endif /*(OS_SPINLOCK_NUMBER > 0)*/
        /* ready state ISR may have pause tp*/
        OsTp_IsrExecutionBudgetStop(CoreID, ISRID);

        /* no post hook here, as it has been called when ISR is premmpted*/

        /*free CSA of ISR*/
        OsIntc_FreeISRCSA(CoreID, ISRID);/* free CSA of ISR */
    }

    OsIsr_InitISRCBT(ISRID, OS_TRUE);
    OsIntc_DisableISR(CoreID,ISRID); /* disable hw interrupt if hw support */

}
#endif /*(OS_APPLICATION_NUMBER > 0)*/

#if((OS_TIMING_PROTECTION_SUPPORT == OS_ON)||(OS_MEM_PROTECTION_SUPPORT == OS_ON)||(OS_APPLICATION_NUMBER > 0))
/* BEGIN_FUNCTION_HDR
***********************************************************************************************
* Function Name: OsISR_KillRunningISR
*
* Description:   Kill running ISR
*
* Inputs:        None
*
* Outputs:       None
*
* Limitations:   None
***********************************************************************************************
END_FUNCTION_HDR*/
FUNC (void, OS_CODE) OsIsr_KillRunningISR
(
    CoreIdType CoreID,
    ISRType ISRID,
    Os_boolean isKillAll
)
{
    Os_boolean schFlag = OS_FALSE;
    ISRType nextIsrId;
#if(OS_ON == OS_TP_ISR_ANYBUDGET_SUPPORT)
    /*PRQA S 4643 ++*/
    /* Do not include <ctype.h> */
    P2VAR(Os_ISRCBType, AUTOMATIC, OS_VAR) isr_vp;
    /*PRQA S 4643 --*/

    isr_vp = &Os_ISRCBTable[ISRID];
#endif /*(OS_ON == OS_TP_ISR_ANYBUDGET_SUPPORT)*/
    (void)OsIsr_AutoResumeInterrupt(CoreID);
#if(OS_RESOURCE_NUMBER > 0)
    (void)OsRes_AutoReleaseISRResource(CoreID,ISRID);
#endif /*(OS_RESOURCE_NUMBER > 0)*/
#if(OS_SPINLOCK_NUMBER > 0)
    (void)OsSpinLock_AutoReleaseISR(CoreID,ISRID);
#endif /*(OS_SPINLOCK_NUMBER > 0)*/

#if(OS_ON == OS_TP_ISR_ANYBUDGET_SUPPORT)
    isr_vp->tpNestIndex = OS_TP_INVALID_NEST_LEVEL;
    isr_vp->tpStartTs = (Os_TpTickType)0;
    OsTpTimer_Stop(CoreID);/* stop tp timer */
#endif /*(OS_ON == OS_TP_ISR_ANYBUDGET_SUPPORT)*/

    /* no need to check stack here*/
    OsHook_PostISRHook(CoreID);
#if(OS_APPLICATION_NUMBER > 0)
    Os_CurrentApplicationId[CoreID] = OS_INVALID_OSAPPLICATION;
#endif /*f(OS_APPLICATION_NUMBER > 0)*/
    Os_CurrentContext[CoreID] = OS_CONTEXT_KERNEL;

    /* If only kill once, no need to set kill flag, ISR can be activate again*/
    /* this init will not affect the ctx related vars, which saved in portable layer, and CSA can be free in following code*/
    OsIsr_InitISRCBT(ISRID, isKillAll);
    if(OS_TRUE == isKillAll)
    {
        OsIntc_DisableISR(CoreID,ISRID); /* disable hw interrupt if hw support */
    }
    else
    {
        OsIntc_ClearPendingISR(CoreID,ISRID);
    }

    if( (Os_IntNestDepth[CoreID] > (ISRType)0)&&(Os_IntNestDepth[CoreID] != OS_INVALID_ISR) )
    {
        Os_IntNestDepth[CoreID]--;
    }
    else
    {
        Os_IntNestDepth[CoreID] = OS_INVALID_ISR;
    }
    if(Os_IntNestDepth[CoreID] != OS_INVALID_ISR)
    {
        /* return to last ISR*/
        /* Os_CurrentContext keep C2 unchange*/
        nextIsrId = Os_CoreCfg[CoreID].nestIsrIdPtr[Os_IntNestDepth[CoreID]];
        OsIsr_EnterISR(CoreID, nextIsrId, OS_TRUE);

    }
    else
    {
        /* no nest or last ISR out, return to task */
        Os_CurrentContext[CoreID] = OS_CONTEXT_KERNEL;
        /*PRQA S 3416 ++*/
        /* The side effect of "OsKernel_NeedSchedule" is expected. */
        if(OS_TRUE == OsKernel_NeedSchedule(CoreID, OS_FALSE))
        /*PRQA S 3416 --*/
        {
            /* Task has exit when in ISR*/
            /* return to task switch */
            schFlag = OS_TRUE;
        }
        else
        {
            OsKernel_EnterTask(CoreID, OS_TRUE);/* ready to restore task*/
        }
    }

    OsIntc_KillISRSchedule(CoreID, ISRID, schFlag);
}
#endif /*((OS_TIMING_PROTECTION_SUPPORT == OS_ON)||(OS_MEM_PROTECTION_SUPPORT == OS_ON)||(OS_APPLICATION_NUMBER > 0))*/

/*******************************************************************************
*   Global Function Define
*******************************************************************************/

/* BEGIN_FUNCTION_HDR
***********************************************************************************************
* Function Name: Os_DisableAllInterrupts
*
* Description:   API function called by Application.Used to disables all interrupts for which the 
*                hardware supports disabling.
*
* Inputs:        None
*
* Outputs:       None
*
* Limitations:   None
***********************************************************************************************
END_FUNCTION_HDR*/
FUNC(void, OS_CODE) Os_DisableAllInterrupts
(
    void
)
{
    CoreIdType CoreID;

    CoreID = OsCpu_GetCoreID();

#if(OS_STATUS_LEVEL == OS_EXTENDED)
    if(CoreID >= (CoreIdType)OS_USED_CORE_NUMBER)
    {
        /* can not record err in this state, as OS services can not be called*/
        return;
    }
#endif /*(OS_STATUS_LEVEL == OS_EXTENDED)*/
    /* no need to check context , as this API can be called in any context, See AUTOSAR 7.7.3.2.1,
     *  this is different of OSEK, in OSEK, these API can not be called in hooks
     * */

    /* Check whether this API is called between interrupt processing APIs*/
    /* do not change check order to get better process speed*/
    if(OS_NO_API_USED == Os_IntAPIUsedFlag[CoreID])
    {
        /*
        * how to implement global interrupts may depends on hw and time protection timer
        * so put it in portable layer
        * */
        OsIntc_DisableAllInterrupts(CoreID);
        Os_IntAPIUsedFlag[CoreID] = OS_DIS_ALL_API_USED;
        OsTp_IsrLockTimeStart(CoreID, OS_TRUE);

    }
    else if(OS_SUS_OS_API_USED  == Os_IntAPIUsedFlag[CoreID])
    {
        OsHook_ReportError(CoreID, E_OS_DISABLEDINT, OSServiceId_DisableAllInterrupts, OS_IE_NOMORE_INFO, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR);
    }
    else
    {
        /* OS_DIS_ALL_API_USED or OS_SUS_ALL_API_USED or other error state*/
        /*global interrupt already disabled, so call  OsHook_ReportErrorDisInt here*/
        OsHook_ReportErrorDisInt(CoreID, E_OS_DISABLEDINT, OSServiceId_DisableAllInterrupts, OS_IE_NOMORE_INFO, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR);
    }
}

/* BEGIN_FUNCTION_HDR
***********************************************************************************************
* Function Name: Os_EnableAllInterrupts
*
* Description:   API function called by Application.Used to restores the state saved by DisableAllInterrupts.
*
* Inputs:        None
*
* Outputs:       None
*
* Limitations:   None
***********************************************************************************************
END_FUNCTION_HDR*/
FUNC(void, OS_CODE) Os_EnableAllInterrupts
(
    void
)
{
    CoreIdType CoreID;

    CoreID = OsCpu_GetCoreID();

#if(OS_STATUS_LEVEL == OS_EXTENDED)
    if(CoreID >= (CoreIdType)OS_USED_CORE_NUMBER)
    {
        /* can not record err in this state, as OS services can not be called*/
        return;
    }
#endif /*(OS_STATUS_LEVEL == OS_EXTENDED)*/
    /* 
     * no need to check context , as this API can be called in any context, See AUTOSAR 7.7.3.2.1,
     * this is different of OSEK, in OSEK, these API can not be called in hooks 
     */

    /* Check whether this API is called between interrupt processing APIs*/
    /* do not change check order to get better process speed*/
    if(OS_DIS_ALL_API_USED == Os_IntAPIUsedFlag[CoreID])
    {
        Os_IntAPIUsedFlag[CoreID] = OS_NO_API_USED;
        OsTp_IsrLockTimeStop(CoreID, OS_TRUE);
        OsIntc_ResumeAllInterrupts(CoreID);
    }
    else if (OS_SUS_ALL_API_USED  == Os_IntAPIUsedFlag[CoreID])
    {
        /*global interrupt already disabled, so call  OsHook_ReportErrorDisInt here*/
        OsHook_ReportErrorDisInt(CoreID, E_OS_DISABLEDINT, OSServiceId_EnableAllInterrupts, OS_IE_NOMORE_INFO, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR);
    }
    else
    {
        /* OS_SUS_OS_API_USED or OS_NO_API_USED or other */
        OsHook_ReportError(CoreID, E_OS_DISABLEDINT, OSServiceId_EnableAllInterrupts, OS_IE_NOMORE_INFO, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR);
    }
}

/* BEGIN_FUNCTION_HDR
***********************************************************************************************
* Function Name: Os_SuspendAllInterrupts
*
* Description:   API function called by Application.Used to saves the recognition status of all
*                interrupts and disables all interrupts for which the hardware supports disabling
*
* Inputs:        None
*
* Outputs:       None
*
* Limitations:   None
***********************************************************************************************
END_FUNCTION_HDR*/
FUNC(void, OS_CODE) Os_SuspendAllInterrupts
(
    void
)
{
    CoreIdType CoreID;

    CoreID = OsCpu_GetCoreID();

#if(OS_STATUS_LEVEL == OS_EXTENDED)
    if((CoreID >= (CoreIdType)OS_USED_CORE_NUMBER) || (Os_CoreState[CoreID] != OS_CORE_START))
    {
        /* can not record err in this state, as OS services can not be called*/
        return;
    }
#endif /*(OS_STATUS_LEVEL == OS_EXTENDED)*/
    /* no need to check context , as this API can be called in any context, See AUTOSAR 7.7.3.2.1,
     *  this is different of OSEK, in OSEK, these API can not be called in hooks
     * */

    /* Check whether this API is called between interrupt processing APIs*/
    /* do not change check order to get better process speed*/
    if((OS_NO_API_USED == Os_IntAPIUsedFlag[CoreID]) || (OS_SUS_ALL_API_USED == Os_IntAPIUsedFlag[CoreID]))
    {
        OsIsr_InternalSuspendAllInterrupts(CoreID);
    }
    else if(OS_SUS_OS_API_USED  == Os_IntAPIUsedFlag[CoreID])
    {
        OsHook_ReportError(CoreID, E_OS_DISABLEDINT, OSServiceId_SuspendAllInterrupts, OS_IE_NOMORE_INFO, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR);
    }
    else
    {
        /* OS_DIS_ALL_API_USED or other error state*/
        /*global interrupt already disabled, so call  OsHook_ReportErrorDisInt here*/
        OsHook_ReportErrorDisInt(CoreID, E_OS_DISABLEDINT, OSServiceId_SuspendAllInterrupts, OS_IE_NOMORE_INFO, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR);
    }
}

/* BEGIN_FUNCTION_HDR
***********************************************************************************************
* Function Name: Os_ResumeAllInterrupts
*
* Description:   API function called by Application.Used to restores the recognition status of
*                all interrupts saved by the SuspendAllInterrupts service
*
* Inputs:        None
*
* Outputs:       None
*
* Limitations:   None
***********************************************************************************************
END_FUNCTION_HDR*/
FUNC(void, OS_CODE) Os_ResumeAllInterrupts
(
    void
)
{
    CoreIdType CoreID;

    CoreID = OsCpu_GetCoreID();

#if(OS_STATUS_LEVEL == OS_EXTENDED)
    if((CoreID >= (CoreIdType)OS_USED_CORE_NUMBER) || (Os_CoreState[CoreID] != OS_CORE_START))
    {
        /* can not record err in this state, as OS services can not be called*/
        return;
    }
#endif /*(OS_STATUS_LEVEL == OS_EXTENDED)*/
    /* 
     * no need to check context , as this API can be called in any context, See AUTOSAR 7.7.3.2.1,
     * this is different of OSEK, in OSEK, these API can not be called in hooks
     */

    /* Check whether this API is called between interrupt processing APIs*/
    /* do not change check order to get better process speed*/
    if(OS_SUS_ALL_API_USED == Os_IntAPIUsedFlag[CoreID])
    {
        OsIsr_InternalResumeAllInterrupts(CoreID);
    }
    else if(OS_DIS_ALL_API_USED  == Os_IntAPIUsedFlag[CoreID])
    {
        /*global interrupt already disabled, so call  OsHook_ReportErrorDisInt here*/
        OsHook_ReportErrorDisInt(CoreID, E_OS_DISABLEDINT, OSServiceId_ResumeAllInterrupts, OS_IE_NOMORE_INFO, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR);

    }
    else
    {
        /* OS_SUS_OS_API_USED or OS_NO_API_USED or other */
        OsHook_ReportError(CoreID, E_OS_DISABLEDINT, OSServiceId_ResumeAllInterrupts, OS_IE_NOMORE_INFO, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR);

    }
}

/* BEGIN_FUNCTION_HDR
***********************************************************************************************
* Function Name: Os_SuspendOSInterrupts
*
* Description:   API function called by Application.Used to saves the recognition status of
*                interrupts of category 2 and disables the recognition of these interrupts
*
* Inputs:        None
*
* Outputs:       None
*
* Limitations:   None
***********************************************************************************************
END_FUNCTION_HDR*/
FUNC(void, OS_CODE) Os_SuspendOSInterrupts
(
    void
)
{
    CoreIdType CoreID;

    CoreID = OsCpu_GetCoreID();

#if(OS_STATUS_LEVEL == OS_EXTENDED)
    if((CoreID >= (CoreIdType)OS_USED_CORE_NUMBER) || (Os_CoreState[CoreID] != OS_CORE_START))
    {
        /* can not record err in this state, as OS services can not be called*/
        return;
    }
#endif /*(OS_STATUS_LEVEL == OS_EXTENDED)*/
    /* no need to check context , as this API can be called in any context, See AUTOSAR 7.7.3.2.1,
     *  this is different of OSEK, in OSEK, these API can not be called in hooks
     * */

    /* Check whether this API is called between interrupt processing APIs*/
    /* do not change check order to get better process speed*/
    if((OS_NO_API_USED == Os_IntAPIUsedFlag[CoreID]) || (OS_SUS_OS_API_USED == Os_IntAPIUsedFlag[CoreID]))
    {
        OsIsr_InternalSuspendOsInterrupts(CoreID);
    }
    else 
    {
        /* OS_SUS_ALL_API_USED or OS_DIS_ALL_API_USED or other*/
        /*global interrupt already disabled, so call  OsHook_ReportErrorDisInt here*/
        OsHook_ReportErrorDisInt(CoreID, E_OS_DISABLEDINT, OSServiceId_SuspendOSInterrupts, OS_IE_NOMORE_INFO, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR);

    }
}

/* BEGIN_FUNCTION_HDR
***********************************************************************************************
* Function Name: Os_ResumeOSInterrupts
*
* Description:   API function called by Application.Used to restores the recognition status of
*                all interrupts saved by the SuspendOSInterrupts service
*
* Inputs:        None
*
* Outputs:       None
*
* Limitations:   None
***********************************************************************************************
END_FUNCTION_HDR*/
FUNC(void, OS_CODE) Os_ResumeOSInterrupts
(
    void
)
{

    CoreIdType CoreID;

    CoreID = OsCpu_GetCoreID();

#if(OS_STATUS_LEVEL == OS_EXTENDED)
    if((CoreID >= (CoreIdType)OS_USED_CORE_NUMBER) || (Os_CoreState[CoreID] != OS_CORE_START))
    {
        /* can not record err in this state, as OS services can not be called*/
        return;
    }
#endif /*(OS_STATUS_LEVEL == OS_EXTENDED)*/
    /* 
     * no need to check context , as this API can be called in any context, See AUTOSAR 7.7.3.2.1,
     * this is different of OSEK, in OSEK, these API can not be called in hooks
     */

    /* Check whether this API is called between interrupt processing APIs*/
    /* do not change check order to get better process speed*/
    if(OS_SUS_OS_API_USED == Os_IntAPIUsedFlag[CoreID])
    {
        OsIsr_InternalResumeOsInterrupts(CoreID);
    }
    else if(OS_NO_API_USED  == Os_IntAPIUsedFlag[CoreID])
    {
        OsHook_ReportError(CoreID, E_OS_DISABLEDINT, OSServiceId_ResumeOSInterrupts, OS_IE_NOMORE_INFO, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR);
    }
    else
    {
           /* OS_SUS_ALL_API_USED or OS_DIS_ALL_API_USED or other*/
        /*global interrupt already disabled, so call  OsHook_ReportErrorDisInt here*/
        OsHook_ReportErrorDisInt(CoreID, E_OS_DISABLEDINT, OSServiceId_ResumeOSInterrupts, OS_IE_NOMORE_INFO, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR);
    }
}

/* BEGIN_FUNCTION_HDR
***********************************************************************************************
* Function Name: Os_GetISRID
*
* Description:   API function called by Application. The ISRID of the current running ISR
*                will be returned.
*
* Inputs:        None
*
* Outputs:       ISRType
*
* Limitations:   See SWS_OS_00511, only can be called in C2 ISR, other wise return OS_INVALID_ISR
***********************************************************************************************
END_FUNCTION_HDR*/
FUNC (ISRType, OS_CODE) Os_GetISRID
(
    void
)
{
    Os_boolean tempPri;
    CoreIdType CoreID;
    ISRType tempId = OS_INVALID_ISR;

    CoreID = OsCpu_GetCoreID();

#if(OS_STATUS_LEVEL == OS_EXTENDED)
    if((CoreID >= (CoreIdType)OS_USED_CORE_NUMBER) || (Os_CoreState[CoreID] != OS_CORE_START))
    {
        /* can not record err in this state, as OS services can not be called*/
        return  OS_INVALID_ISR;
    }

    if ((Os_uint16)(Os_CurrentContext[CoreID] & Os_GetISRIDMask) == (Os_uint16)0)
    {
        OsHook_ReportError(CoreID, E_OS_CALLEVEL, OSServiceId_GetISRID, OS_IE_NOMORE_INFO, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR);
        return OS_INVALID_ISR;
    }

    /* Check whether this API is called between interrupt processing APIs*/
    if (OS_NO_API_USED != Os_IntAPIUsedFlag[CoreID])
    {
        OsHook_ReportError(CoreID, E_OS_DISABLEDINT, OSServiceId_GetISRID, OS_IE_NOMORE_INFO, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR);
        return OS_INVALID_ISR;
    }

#endif /*(OS_STATUS_LEVEL == OS_EXTENDED)*/

    OsCpu_EnterCritical(CoreID, &tempPri);

    if((Os_uint16)0 != (Os_uint16)(Os_CurrentContext[CoreID] & OS_CONTEXT_C2ISR))/*SWS_OS_00511*/
    {
        if(Os_IntNestDepth[CoreID] != OS_INVALID_ISR)
        {
            tempId = Os_CoreCfg[CoreID].nestIsrIdPtr[Os_IntNestDepth[CoreID]];
        }

    }

    OsCpu_ExitCritical(CoreID, tempPri);

    return tempId;
}

/* BEGIN_FUNCTION_HDR
****************************************************************************************************
* Function Name: Os_EnableInterruptSource  SWS_Os_91020
*
* Description:   Enables the interrupt source by modifying the interrupt controller registers. 
*                Additionally it may clear the interrupt pending flag.
*
* Inputs:        ISRID: The ID of a category 2 ISR.
*                ClearPending: Defines whether the pending flag shall be 
*                              cleared (TRUE) or not (FALSE).
*
* Outputs:       None.
*
* Limitations:   Only for category 2 ISR.
****************************************************************************************************
END_FUNCTION_HDR*/
FUNC(StatusType, OS_CODE) Os_EnableInterruptSource
(
    ISRType ISRID,
    boolean ClearPending
)
{
    CoreIdType currentCoreID;
    Os_boolean tempPri;

    currentCoreID = OsCpu_GetCoreID();
    /* SWS_Os_00810 */
    if ((currentCoreID >= (CoreIdType)OS_USED_CORE_NUMBER) || (Os_CoreState[currentCoreID] != OS_CORE_START))
    {
        /* Can not record err in this state, as OS services can not be called. */
        return E_OS_CORE;
    }

    if (OS_NO_API_USED != Os_IntAPIUsedFlag[currentCoreID])
    {
        /* System error -- this API is called between interrupt processing function pairs. */
        OsHook_ReportError(currentCoreID, E_OS_DISABLEDINT, OSServiceId_EnableInterruptSource, \
        OS_IE_NOMORE_INFO, (Os_uint32)ISRID, (Os_uint32)Os_IntAPIUsedFlag[currentCoreID], \
        OS_IE_NO_ERRPAR);
        return E_OS_DISABLEDINT;
    }

#if(OS_STATUS_LEVEL == OS_EXTENDED)
    if ((Os_uint16)(Os_CurrentContext[currentCoreID] & Os_EnableInterruptSourceMask) \
        == (Os_uint16)0)
    {
        OsHook_ReportError(currentCoreID, E_OS_CALLEVEL, OSServiceId_EnableInterruptSource, \
            OS_IE_NOMORE_INFO, (Os_uint32)ISRID, (Os_uint32)Os_CurrentContext[currentCoreID], \
            OS_IE_NO_ERRPAR);
        return E_OS_CALLEVEL;
    }

    if (ISRID >= Os_CoreCfg[currentCoreID].c2IsrNum)
    {
        OsHook_ReportError(currentCoreID, E_OS_ID, OSServiceId_EnableInterruptSource, \
            OS_IE_ISR_ID, (Os_uint32)ISRID, (Os_uint32)Os_CoreCfg[currentCoreID].c2IsrNum, \
            OS_IE_NO_ERRPAR);
        return E_OS_ID;
    }

    /* SWS_Os_00809 */
    if (OS_TRUE == OsIntc_CheckISREnabled(currentCoreID, ISRID))
    {
        OsHook_ReportErrorDisInt(currentCoreID, E_OS_NOFUNC, OSServiceId_EnableInterruptSource, \
            OS_IE_NOMORE_INFO, (Os_uint32)ISRID, (Os_uint32)OS_TRUE, OS_IE_NO_ERRPAR);
        return E_OS_NOFUNC;
    }
#else /* (OS_STATUS_LEVEL == OS_EXTENDED) */
#if(OS_USED_CORE_NUMBER > 1)
    /* Do not support the operation of crossing core. */
    /*
     * If OS_EXTENDED, this situation has been checked by 
     * "else if(ISRID >= Os_CoreCfg[currentCoreID].c2IsrNum)".
     */
    if (currentCoreID != Os_ISRCfg[ISRID].objCoreId)
    {
        OsHook_ReportError(currentCoreID, E_OS_ID, OSServiceId_EnableInterruptSource, \
            OS_IE_ISR_ID, (Os_uint32)ISRID, (Os_uint32)Os_ISRCfg[ISRID].objCoreId, OS_IE_NO_ERRPAR);
        return E_OS_ID;
    }
#endif /* (OS_USED_CORE_NUMBER > 1) */
#endif /* (OS_STATUS_LEVEL == OS_EXTENDED) */

#if(OS_APPLICATION_NUMBER > 0)
    if (Os_CurrentApplicationId[currentCoreID] != Os_ISRCfg[ISRID].ApplID)
    {
        OsHook_ReportError(currentCoreID, E_OS_ACCESS, OSServiceId_EnableInterruptSource, \
            OS_IE_NO_ACCESS_RIGHT, (Os_uint32)ISRID, (Os_uint32)Os_ISRCfg[ISRID].ApplID, \
            (Os_uint32)Os_CurrentApplicationId[currentCoreID]);
        return E_OS_ACCESS;
    }
#endif /* (OS_APPLICATION_NUMBER > 0) */

    /* SWS_Os_00811 */
    /* Enter critical section. */
    OsCpu_EnterCritical(currentCoreID, &tempPri);

    if (OS_TRUE == ClearPending)
    {
        OsIntc_ClearPendingISR(currentCoreID, ISRID);
    }
    OsIntc_EnableISR(currentCoreID, ISRID);

    /* Exit critical section. */
    OsCpu_ExitCritical(currentCoreID, tempPri);

    return E_OS_OK;
}

/* BEGIN_FUNCTION_HDR
****************************************************************************************************
* Function Name: Os_DisableInterruptSource  SWS_Os_91019
*
* Description:   Disables the interrupt source by modifying the interrupt controller registers.
*
* Inputs:        ISRID: The ID of a category 2 ISR.
*
* Outputs:       None.
*
* Limitations:   Only for category 2 ISR.
****************************************************************************************************
END_FUNCTION_HDR*/
FUNC(StatusType, OS_CODE) Os_DisableInterruptSource
(
    ISRType ISRID
)
{
    CoreIdType currentCoreID;
    Os_boolean tempPri;

    currentCoreID = OsCpu_GetCoreID();
    /* SWS_Os_00810 */
    if ((currentCoreID >= (CoreIdType)OS_USED_CORE_NUMBER) || (Os_CoreState[currentCoreID] \
        != OS_CORE_START))
    {
        /* Can not record err in this state, as OS services can not be called. */
        return E_OS_CORE;
    }

    if (OS_NO_API_USED != Os_IntAPIUsedFlag[currentCoreID])
    {
        /* System error -- this API is called between interrupt processing function pairs */
        OsHook_ReportError(currentCoreID, E_OS_DISABLEDINT, OSServiceId_DisableInterruptSource, \
            OS_IE_NOMORE_INFO, (Os_uint32)ISRID, (Os_uint32)Os_IntAPIUsedFlag[currentCoreID], \
            OS_IE_NO_ERRPAR);
        return E_OS_DISABLEDINT;
    }

#if(OS_STATUS_LEVEL == OS_EXTENDED)
    if ((Os_uint16)(Os_CurrentContext[currentCoreID] & Os_DisableInterruptSourceMask) \
        == (Os_uint16)0)
    {
        OsHook_ReportError(currentCoreID, E_OS_CALLEVEL, OSServiceId_DisableInterruptSource, \
            OS_IE_NOMORE_INFO, (Os_uint32)ISRID, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR);
        return E_OS_CALLEVEL;
    }

    if (ISRID >= Os_CoreCfg[currentCoreID].c2IsrNum)
    {
        OsHook_ReportError(currentCoreID, E_OS_ID, OSServiceId_DisableInterruptSource, \
            OS_IE_ISR_ID, (Os_uint32)ISRID, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR);
        return E_OS_ID;
    }

    /* SWS_Os_00809 */
    if (OS_FALSE == OsIntc_CheckISREnabled(currentCoreID, ISRID))
    {
        OsHook_ReportErrorDisInt(currentCoreID, E_OS_NOFUNC, OSServiceId_DisableInterruptSource, \
            OS_IE_NOMORE_INFO, (Os_uint32)ISRID, (Os_uint32)OS_FALSE, OS_IE_NO_ERRPAR);
        return E_OS_NOFUNC;
    }
#else /* (OS_STATUS_LEVEL == OS_EXTENDED) */
#if(OS_USED_CORE_NUMBER > 1)
    /* Do not support the operation of crossing core. */
    /*
     * If OS_EXTENDED, this situation has been checked by 
     * "else if(ISRID >= Os_CoreCfg[currentCoreID].c2IsrNum)".
     */
    if (currentCoreID != Os_ISRCfg[ISRID].objCoreId)
    {
        OsHook_ReportError(currentCoreID, E_OS_ID, OSServiceId_DisableInterruptSource, \
            OS_IE_ISR_ID, (Os_uint32)ISRID, (Os_uint32)Os_ISRCfg[ISRID].objCoreId, OS_IE_NO_ERRPAR);
        return E_OS_ID;
    }
#endif /* (OS_USED_CORE_NUMBER > 1) */
#endif /* (OS_STATUS_LEVEL == OS_EXTENDED) */

#if(OS_APPLICATION_NUMBER > 0)
    if (Os_CurrentApplicationId[currentCoreID] != Os_ISRCfg[ISRID].ApplID)
    {
        OsHook_ReportError(currentCoreID, E_OS_ACCESS, OSServiceId_DisableInterruptSource, \
            OS_IE_NO_ACCESS_RIGHT, (Os_uint32)ISRID, (Os_uint32)Os_ISRCfg[ISRID].ApplID, \
            (Os_uint32)Os_CurrentApplicationId[currentCoreID]);
        return E_OS_ACCESS;
    }
#endif /* (OS_APPLICATION_NUMBER > 0) */
    
    /* SWS_Os_00812 */
    /* Enter critical section. */
    OsCpu_EnterCritical(currentCoreID, &tempPri);

    OsIntc_DisableISR(currentCoreID, ISRID);

    /* Exit critical section. */
    OsCpu_ExitCritical(currentCoreID, tempPri);

    return E_OS_OK;
}

/* BEGIN_FUNCTION_HDR
****************************************************************************************************
* Function Name: ClearPendingInterrupt  SWS_Os_91021
*
* Description:   Clears the interrupt pending flag by modifying the interrupt controller 
*                registers.
*
* Inputs:        ISRID: The ID of a category 2 ISR.
*
* Outputs:       None.
*
* Limitations:   Only for category 2 ISR.
*                This does not necessarily guarantee that the interrupt request is cleared 
*                successfully. SWS_Os_00814
****************************************************************************************************
END_FUNCTION_HDR*/
FUNC(StatusType, OS_CODE) Os_ClearPendingInterrupt
(
    ISRType ISRID
)
{
    CoreIdType currentCoreID;
    Os_boolean tempPri;

    currentCoreID = OsCpu_GetCoreID();
    /* SWS_Os_00810 */
    if ((currentCoreID >= (CoreIdType)OS_USED_CORE_NUMBER) || \
        (Os_CoreState[currentCoreID] != OS_CORE_START))
    {
        /* Can not record err in this state, as OS services can not be called. */
        return E_OS_CORE;
    }

    if (OS_NO_API_USED != Os_IntAPIUsedFlag[currentCoreID])
    {
        /* System error -- this API is called between interrupt processing function pairs. */
        OsHook_ReportError(currentCoreID, E_OS_DISABLEDINT, OSServiceId_ClearPendingInterrupt, \
            OS_IE_NOMORE_INFO, (Os_uint32)ISRID, (Os_uint32)Os_IntAPIUsedFlag[currentCoreID], \
            OS_IE_NO_ERRPAR);
        return E_OS_DISABLEDINT;
    }

#if(OS_STATUS_LEVEL == OS_EXTENDED)
    if ((Os_uint16)(Os_CurrentContext[currentCoreID] & Os_ClearPendingInterruptMask) \
        == (Os_uint16)0)
    {
        OsHook_ReportError(currentCoreID, E_OS_CALLEVEL, OSServiceId_ClearPendingInterrupt, \
            OS_IE_NOMORE_INFO, (Os_uint32)ISRID, (Os_uint32)Os_CurrentContext[currentCoreID], \
            OS_IE_NO_ERRPAR);
        return E_OS_CALLEVEL;
    }

    if (ISRID >= Os_CoreCfg[currentCoreID].c2IsrNum)
    {
        OsHook_ReportError(currentCoreID, E_OS_ID, OSServiceId_ClearPendingInterrupt, \
            OS_IE_ISR_ID, (Os_uint32)ISRID, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR);
        return E_OS_ID;
    }
#else /* (OS_STATUS_LEVEL == OS_EXTENDED) */
#if(OS_USED_CORE_NUMBER > 1)
    /* Do not support the operation of crossing core. */
    /*
     * If OS_EXTENDED, this situation has been checked by 
     * "else if(ISRID >= Os_CoreCfg[currentCoreID].c2IsrNum)".
     */
    if (currentCoreID != Os_ISRCfg[ISRID].objCoreId)
    {
        OsHook_ReportError(currentCoreID, E_OS_ID, OSServiceId_ClearPendingInterrupt, \
            OS_IE_ISR_ID, (Os_uint32)ISRID, (Os_uint32)Os_ISRCfg[ISRID].objCoreId, OS_IE_NO_ERRPAR);
        return E_OS_ID;
    }
#endif /* (OS_USED_CORE_NUMBER > 1) */
#endif /* (OS_STATUS_LEVEL == OS_EXTENDED) */

#if(OS_APPLICATION_NUMBER > 0)
    if (Os_CurrentApplicationId[currentCoreID] != Os_ISRCfg[ISRID].ApplID)
    {
        OsHook_ReportError(currentCoreID, E_OS_ACCESS, OSServiceId_ClearPendingInterrupt, \
            OS_IE_NO_ACCESS_RIGHT, (Os_uint32)ISRID, (Os_uint32)Os_ISRCfg[ISRID].ApplID, \
            (Os_uint32)Os_CurrentApplicationId[currentCoreID]);
        return E_OS_ACCESS;
    }
#endif /* (OS_APPLICATION_NUMBER > 0) */
    
    /* SWS_Os_00813 */
    /* Enter critical section. */
    OsCpu_EnterCritical(currentCoreID, &tempPri);

    OsIntc_ClearPendingISR(currentCoreID, ISRID);

    /* Exit critical section. */
    OsCpu_ExitCritical(currentCoreID, tempPri);

    return E_OS_OK;
}

#define OS_STOP_SEC_CODE
#include "Os_MemMap.h"


