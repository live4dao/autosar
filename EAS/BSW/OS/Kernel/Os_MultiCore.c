/*  BEGIN_FILE_HDR
********************************************************************************
*   NOTICE
*   This software is the property of HiRain Technologies. Any information
*   contained in this doc should not be reproduced, or used, or disclosed
*   without the written authorization from HiRain Technologies.
********************************************************************************
* File Name:       Os_MultiCore.c
********************************************************************************
* Project/Product: AUTOSAR OS PROJECT
* Title:           Os_MultiCore.c
* Author:          Hirain
********************************************************************************
* Description:     Multi Core implement of OS
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

/*PRQA S 1006 EOF*/
/*
Inline assembler statement is essential.
*/

#if(OS_USED_CORE_NUMBER > 1)
/*****************************************************************************
* Macro
******************************************************************************/
#define OS_MULTICORE_NOACTION                                ((Os_uint8)0)
#define OS_MULTICORE_ACTION_ACTIVATETASK                     ((Os_uint8)1)
#define OS_MULTICORE_ACTION_SETEVENT                         ((Os_uint8)2)
#define OS_MULTICORE_ACTION_SETABSALARM                      ((Os_uint8)3)
#define OS_MULTICORE_ACTION_SETRELALARM                      ((Os_uint8)4)
#define OS_MULTICORE_ACTION_CANCELALARM                      ((Os_uint8)5)
#define OS_MULTICORE_ACTION_SHUTDOWN                         ((Os_uint8)6)
#define OS_MULTICORE_ACTION_TERMINATEAPPLICATION             ((Os_uint8)7)
#define OS_MULTICORE_ACTION_CONTROLIDLE                      ((Os_uint8)8)

/*****************************************************************************
* Static variables define
******************************************************************************/
#define OS_START_SEC_VAR_NOINIT_MULTICORE
#include "Os_MemMap.h"

STATIC VAR(StatusType, OS_VAR) OsMultiCore_Result[OS_USED_CORE_NUMBER];
STATIC VAR(Os_uint8, OS_VAR) OsMultiCore_ActionType[OS_USED_CORE_NUMBER];
STATIC VAR(TaskType, OS_VAR) OsMultiCore_TaskId[OS_USED_CORE_NUMBER];
#if(OS_ALARM_NUMBER != 0)
STATIC VAR(AlarmType, OS_VAR) OsMultiCore_AlarmID[OS_USED_CORE_NUMBER];
STATIC VAR(TickType, OS_VAR) OsMultiCore_start[OS_USED_CORE_NUMBER];
STATIC VAR(TickType, OS_VAR) OsMultiCore_cycle[OS_USED_CORE_NUMBER];
STATIC VAR(TickType, OS_VAR) OsMultiCore_increment[OS_USED_CORE_NUMBER];
#endif /*(OS_ALARM_NUMBER != 0)*/
#if(OS_EXTENDED_TASK_NUMBER > 0)
STATIC VAR(EventMaskType, OS_VAR) OsMultiCore_EventMask[OS_USED_CORE_NUMBER];
#endif /*(OS_EXTENDED_TASK_NUMBER > 0)*/
STATIC VAR(CoreIdType, OS_VAR) OsMultiCore_ToCoreId[OS_USED_CORE_NUMBER];
STATIC VAR(CoreIdType, OS_VAR) OsMultiCore_FromCoreId[OS_USED_CORE_NUMBER];
STATIC VAR(StatusType, OS_VAR) OsMultiCore_Error[OS_USED_CORE_NUMBER];
#if(OS_APPLICATION_NUMBER > 0)
STATIC VAR(RestartType, OS_VAR) OsMultiCore_RestartOption[OS_USED_CORE_NUMBER];
STATIC VAR(ApplicationType, OS_VAR) OsMultiCore_Application[OS_USED_CORE_NUMBER];
#endif /*(OS_APPLICATION_NUMBER > 0)*/

#define OS_STOP_SEC_VAR_NOINIT_MULTICORE
#include "Os_MemMap.h"

#define OS_START_SEC_CODE
#include "Os_MemMap.h"

/*****************************************************************************
* OS private code
******************************************************************************/
STATIC FUNC(StatusType, OS_CODE) OsMultiCore_TriggerShutdown
(
    CoreIdType CoreID,
    CoreIdType toCoreID,
    StatusType Error
);

STATIC FUNC(StatusType, OS_CODE) OsMultiCore_TriggerSetMode
(
    CoreIdType CoreID,
    CoreIdType toCoreID
);

STATIC FUNC(void, OS_CODE) OsMultiCore_InternalSetMode
(
    CoreIdType CurrentCoreId,
    CoreIdType toCoreID
);

/*****************************************************************************
* OS internal code
******************************************************************************/
/* BEGIN_FUNCTION_HDR
***********************************************************************************************
* Function Name: OsMultiCore_TriggerActivateTask
*
* Description:   Called this function when crosscore active task
*
* Inputs:        CoreID,TaskID
*
* Outputs:       StatusType
*
* Limitations:   None
***********************************************************************************************
END_FUNCTION_HDR*/
FUNC(StatusType, OS_CODE) OsMultiCore_TriggerActivateTask
(
    CoreIdType CoreID,
    TaskType TaskID
)
{
    StatusType ret;
    Os_uint32 timeout = OS_MULTICORE_ACTION_TMEOUT;
    CoreIdType toCoreID = Os_TaskCfg[TaskID].objCoreId; 

    /* lock first*/
    OsCpu_GetSpinlock(&OsMultiCore_OpLock[toCoreID], CoreID);

    /* Record parameters */
    OsMultiCore_Result[toCoreID] = E_OS_SYS_CROSSCORE_WAITING;
    OsMultiCore_TaskId[toCoreID] = TaskID;
    OsMultiCore_ToCoreId[toCoreID] = toCoreID;
    OsMultiCore_FromCoreId[toCoreID] = CoreID;
    OsMultiCore_ActionType[toCoreID] = OS_MULTICORE_ACTION_ACTIVATETASK;

    /* Trigger SW ISR, to execute in target core*/
    OsIntc_CrossCoreIntTrigger(toCoreID);

    /* Wait until action finished in another core SWS_OS_00598*/
    while((E_OS_SYS_CROSSCORE_WAITING == OsMultiCore_Result[toCoreID]) \
        && (timeout > (Os_uint32)0))
    {
        /* Use OS_PL_NOP() to avoid compiler optimize to dead cycle */
        OS_PL_NOP();
        timeout--;
    }

    /* If timeout, shutdown OS */
    if((Os_uint32)0 == timeout)
    {
        OsHook_FataErrReport(CoreID, E_OS_SYSFATA_RES_CROSSCORE_TIMEOUT, OSServiceId_OsMultiCore_TriggerActivateTask, OS_IE_NOMORE_INFO, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR);
    }

    /* must save result to local ret here, to avoid these crosscore  functions reentrancy */
    ret = OsMultiCore_Result[toCoreID];

    /*
     * Reset cross core vars
     * */
    OsMultiCore_ActionType[toCoreID] = OS_MULTICORE_NOACTION;
    OsMultiCore_FromCoreId[toCoreID] = OS_INVALID_COREID;
    OsMultiCore_ToCoreId[toCoreID] = OS_INVALID_COREID;

    /*PRQA S 3109,3138 ++*/
    /*
    Assembly instructions replaced by null statement just for QAC prj, 
    because PRQA can not parse assembly instructions.
    */
    OsCpu_ReleaseSpinlock(&OsMultiCore_OpLock[toCoreID]);
    /*PRQA S 3109,3138 --*/
    return ret;
}

#if((OS_CC == OS_ECC1) || (OS_CC == OS_ECC2))
/* BEGIN_FUNCTION_HDR
***********************************************************************************************
* Function Name: OsMultiCore_TriggerSetEvent
*
* Description:   Called this function when crosscore SetEvent
*
* Inputs:        CoreID,TaskID,Mask
*
* Outputs:       StatusType
*
* Limitations:   None
***********************************************************************************************
END_FUNCTION_HDR*/
FUNC(StatusType, OS_CODE) OsMultiCore_TriggerSetEvent
(
    CoreIdType CoreID,
    TaskType TaskID,
    EventMaskType Mask
)
{
    StatusType ret;
    Os_uint32 timeout = OS_MULTICORE_ACTION_TMEOUT;
    CoreIdType toCoreID = Os_TaskCfg[TaskID].objCoreId;

    OsCpu_GetSpinlock(&OsMultiCore_OpLock[toCoreID], CoreID);
    /* Record parameters */
    OsMultiCore_Result[toCoreID] = E_OS_SYS_CROSSCORE_WAITING;
    OsMultiCore_TaskId[toCoreID] = TaskID;
    OsMultiCore_EventMask[toCoreID] = Mask;
    OsMultiCore_ToCoreId[toCoreID] = toCoreID;
    OsMultiCore_FromCoreId[toCoreID] = CoreID;
    OsMultiCore_ActionType[toCoreID] = OS_MULTICORE_ACTION_SETEVENT;

    /* Trigger SW ISR, to execute in target core*/
    OsIntc_CrossCoreIntTrigger(toCoreID);

    /*wait until action finished in another core SWS_OS_00598*/
    while((E_OS_SYS_CROSSCORE_WAITING == OsMultiCore_Result[toCoreID]) \
        && (timeout > (Os_uint32)0))
    {
        /* Use OS_PL_NOP() to avoid compiler optimize to dead cycle */
        OS_PL_NOP();
        timeout--;
    }

    /* If timeout, shutdown OS */
    if((Os_uint32)0 == timeout)
    {
        OsHook_FataErrReport(CoreID, E_OS_SYSFATA_RES_CROSSCORE_TIMEOUT, OSServiceId_OsMultiCore_TriggerSetEvent, OS_IE_NOMORE_INFO, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR);
    }

    /* must save result to local ret here, to avoid these crosscore  functions reentrancy */
    ret = OsMultiCore_Result[toCoreID];
    /*
     * Reset cross core vars
     * */
    OsMultiCore_ActionType[toCoreID] = OS_MULTICORE_NOACTION;
    OsMultiCore_FromCoreId[toCoreID] = OS_INVALID_COREID;
    OsMultiCore_ToCoreId[toCoreID] = OS_INVALID_COREID;
    /*PRQA S 3109,3138 ++*/
    /*
    Assembly instructions replaced by null statement just for QAC prj, 
    because PRQA can not parse assembly instructions.
    */
    OsCpu_ReleaseSpinlock(&OsMultiCore_OpLock[toCoreID]);
    /*PRQA S 3109,3138 --*/
    return ret;
}
#endif /*((OS_CC == OS_ECC1) || (OS_CC == OS_ECC2))*/

#if(OS_ALARM_NUMBER != 0)
/* BEGIN_FUNCTION_HDR
***********************************************************************************************
* Function Name: OsMultiCore_TriggerSetAbsAlarm
*
* Description:   Called this function when crosscore SetAbsAlarm
*
* Inputs:        CoreID,AlarmID,start,cycle
*
* Outputs:       StatusType
*
* Limitations:   None
***********************************************************************************************
END_FUNCTION_HDR*/
FUNC(StatusType, OS_CODE) OsMultiCore_TriggerSetAbsAlarm
(
    CoreIdType CoreID,
    AlarmType AlarmID,
    TickType start,
    TickType cycle
)
{
    StatusType ret;
    Os_uint32 timeout = OS_MULTICORE_ACTION_TMEOUT;
    CoreIdType toCoreID = Os_AlarmCfg[AlarmID].objCoreId;

    OsCpu_GetSpinlock(&OsMultiCore_OpLock[toCoreID], CoreID);
    /* Record parameters */
    OsMultiCore_Result[toCoreID] = E_OS_SYS_CROSSCORE_WAITING;
    OsMultiCore_AlarmID[toCoreID] = AlarmID;
    OsMultiCore_start[toCoreID] = start;
    OsMultiCore_cycle[toCoreID] = cycle;
    OsMultiCore_ToCoreId[toCoreID] = toCoreID;
    OsMultiCore_FromCoreId[toCoreID] = CoreID;
    OsMultiCore_ActionType[toCoreID] = OS_MULTICORE_ACTION_SETABSALARM;

    /* Trigger SW ISR, to execute in target core*/
    OsIntc_CrossCoreIntTrigger(toCoreID);

    /*wait until action finished in another core SWS_OS_00598*/
    while((E_OS_SYS_CROSSCORE_WAITING == OsMultiCore_Result[toCoreID]) \
        && (timeout > (Os_uint32)0))
    {
        /* Use OS_PL_NOP() to avoid compiler optimize to dead cycle */
        OS_PL_NOP();
        timeout--;
    }

    /* If timeout, shutdown OS */
    if((Os_uint32)0 == timeout)
    {
        OsHook_FataErrReport(CoreID, E_OS_SYSFATA_RES_CROSSCORE_TIMEOUT, OSServiceId_OsMultiCore_TriggerSetAbsAlarm, OS_IE_NOMORE_INFO, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR);
    }

    /* must save result to local ret here, to avoid these crosscore  functions reentrancy */
    ret = OsMultiCore_Result[toCoreID];
    /*
     * Reset cross core vars
     * */
    OsMultiCore_ActionType[toCoreID] = OS_MULTICORE_NOACTION;
    OsMultiCore_FromCoreId[toCoreID] = OS_INVALID_COREID;
    OsMultiCore_ToCoreId[toCoreID] = OS_INVALID_COREID;
    /*PRQA S 3109,3138 ++*/
    /*
    Assembly instructions replaced by null statement just for QAC prj, 
    because PRQA can not parse assembly instructions.
    */
    OsCpu_ReleaseSpinlock(&OsMultiCore_OpLock[toCoreID]);
    /*PRQA S 3109,3138 --*/
    return ret;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: OsMultiCore_TriggerSetRelAlarm
*
* Description:   Internal set Rel Alarm, called by Alarm and crosscore setAlarm
*
* Inputs:        CoreID,AlarmID,increment,cycle
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(StatusType, OS_CODE) OsMultiCore_TriggerSetRelAlarm
(
    CoreIdType CoreID,
    AlarmType AlarmID,
    TickType increment,
    TickType cycle
)
{
    StatusType ret;
    Os_uint32 timeout = OS_MULTICORE_ACTION_TMEOUT;
    CoreIdType toCoreID = Os_AlarmCfg[AlarmID].objCoreId;

    OsCpu_GetSpinlock(&OsMultiCore_OpLock[toCoreID], CoreID);
    /* Record parameters */
    OsMultiCore_Result[toCoreID] = E_OS_SYS_CROSSCORE_WAITING;
    OsMultiCore_AlarmID[toCoreID] = AlarmID;
    OsMultiCore_increment[toCoreID] = increment;
    OsMultiCore_cycle[toCoreID] = cycle;
    OsMultiCore_ToCoreId[toCoreID] = toCoreID;
    OsMultiCore_FromCoreId[toCoreID] = CoreID;
    OsMultiCore_ActionType[toCoreID] = OS_MULTICORE_ACTION_SETRELALARM;

    /* Trigger SW ISR, to execute in target core*/
    OsIntc_CrossCoreIntTrigger(toCoreID);

    /*wait until action finished in another core SWS_OS_00598*/
    while((E_OS_SYS_CROSSCORE_WAITING == OsMultiCore_Result[toCoreID]) \
        && (timeout > (Os_uint32)0))
    {
        /* Use OS_PL_NOP() to avoid compiler optimize to dead cycle */
        OS_PL_NOP();
        timeout--;
    }

    /* If timeout, shutdown OS */
    if((Os_uint32)0 == timeout)
    {
        OsHook_FataErrReport(CoreID, E_OS_SYSFATA_RES_CROSSCORE_TIMEOUT, OSServiceId_OsMultiCore_TriggerSetAbsAlarm, OS_IE_NOMORE_INFO, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR);
    }

    /* must save result to local ret here, to avoid these crosscore  functions reentrancy */
    ret = OsMultiCore_Result[toCoreID];

    /*
     * Reset cross core vars
     * */


    OsMultiCore_ActionType[toCoreID] = OS_MULTICORE_NOACTION;
    OsMultiCore_FromCoreId[toCoreID] = OS_INVALID_COREID;
    OsMultiCore_ToCoreId[toCoreID] = OS_INVALID_COREID;
    /*PRQA S 3109,3138 ++*/
    /*
    Assembly instructions replaced by null statement just for QAC prj, 
    because PRQA can not parse assembly instructions.
    */
    OsCpu_ReleaseSpinlock(&OsMultiCore_OpLock[toCoreID]);
    /*PRQA S 3109,3138 --*/
    return ret;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: OsMultiCore_TriggerCancelAlarm
*
* Description:   Called this function when crosscore Cancel Alarm
*
* Inputs:        CoreID,AlarmID
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(StatusType, OS_CODE) OsMultiCore_TriggerCancelAlarm
(
    CoreIdType CoreID,
    AlarmType AlarmID
)
{
    StatusType ret;
    Os_uint32 timeout = OS_MULTICORE_ACTION_TMEOUT;
    CoreIdType toCoreID = Os_AlarmCfg[AlarmID].objCoreId;

    OsCpu_GetSpinlock(&OsMultiCore_OpLock[toCoreID], CoreID);
    /* Record parameters */
    OsMultiCore_Result[toCoreID] = E_OS_SYS_CROSSCORE_WAITING;
    OsMultiCore_AlarmID[toCoreID] = AlarmID;
    OsMultiCore_ToCoreId[toCoreID] = toCoreID;
    OsMultiCore_FromCoreId[toCoreID] = CoreID;
    OsMultiCore_ActionType[toCoreID] = OS_MULTICORE_ACTION_CANCELALARM;

    /* Trigger SW ISR, to execute in target core*/
    OsIntc_CrossCoreIntTrigger(toCoreID);

    /*wait until action finished in another core SWS_OS_00598*/
    while((E_OS_SYS_CROSSCORE_WAITING == OsMultiCore_Result[toCoreID]) \
        && (timeout > (Os_uint32)0))
    {
        /* Use OS_PL_NOP() to avoid compiler optimize to dead cycle */
        OS_PL_NOP();
        timeout--;
    }

    /* If timeout, shutdown OS */
    if((Os_uint32)0 == timeout)
    {
        OsHook_FataErrReport(CoreID, E_OS_SYSFATA_RES_CROSSCORE_TIMEOUT, OSServiceId_OsMultiCore_TriggerCancelAlarm, OS_IE_NOMORE_INFO, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR);
    }

    /* must save result to local ret here, to avoid these crosscore  functions reentrancy */
    ret = OsMultiCore_Result[toCoreID];

    /*
     * Reset cross core vars
     * */

    OsMultiCore_ActionType[toCoreID] = OS_MULTICORE_NOACTION;
    OsMultiCore_FromCoreId[toCoreID] = OS_INVALID_COREID;
    OsMultiCore_ToCoreId[toCoreID] = OS_INVALID_COREID;
    /*PRQA S 3109,3138 ++*/
    /*
    Assembly instructions replaced by null statement just for QAC prj, 
    because PRQA can not parse assembly instructions.
    */
    OsCpu_ReleaseSpinlock(&OsMultiCore_OpLock[toCoreID]);
    /*PRQA S 3109,3138 --*/
    return ret;
}
#endif /*(OS_ALARM_NUMBER != 0)*/

/* BEGIN_FUNCTION_HDR
***********************************************************************************************
* Function Name: OsMultiCore_CrossCoreProcess
*
* Description:   Called this function in crosscore sw interrupt to process cross core actions
*
* Inputs:        None
*
* Outputs:       None
*
* Limitations:   None
***********************************************************************************************
END_FUNCTION_HDR*/
FUNC(void, OS_CODE) OsMultiCore_CrossCoreProcess
(
    CoreIdType CurrentCoreId
)
{
    Os_boolean isShutdown = OS_FALSE;
#if(OS_STATUS_LEVEL == OS_EXTENDED)
    if((CurrentCoreId >= (CoreIdType)OS_USED_CORE_NUMBER) || (Os_CoreState[CurrentCoreId] != OS_CORE_START))
    {
        /* Can not record err in this state, as OS services can not be called*/
        /* should not reach this code*/
        return;
    }

    if((OsMultiCore_ToCoreId[CurrentCoreId] != CurrentCoreId) || (OsMultiCore_FromCoreId[CurrentCoreId] != OsMultiCore_OpLock[CurrentCoreId]))
    {
        OsHook_ReportError(CurrentCoreId, E_OS_SYS_CROSSCORE_ERR, OSServiceId_OsMultiCore_CrossCoreProcess, OS_IE_NOMORE_INFO, \
            (Os_uint32)OsMultiCore_OpLock[CurrentCoreId], (Os_uint32)OsMultiCore_ToCoreId[CurrentCoreId], (Os_uint32)OsMultiCore_FromCoreId[CurrentCoreId]);
        OsMultiCore_Result[CurrentCoreId] = E_OS_SYS_CROSSCORE_ERR;
        return;
    }
#endif /*(OS_STATUS_LEVEL == OS_EXTENDED)*/

    switch(OsMultiCore_ActionType[CurrentCoreId])
    {
    case OS_MULTICORE_ACTION_ACTIVATETASK:
        OsMultiCore_Result[CurrentCoreId] =  OsTask_InternalActivateTask(CurrentCoreId, OsMultiCore_TaskId[CurrentCoreId], OS_FALSE, OSServiceId_ActivateTask);
        break;
#if(OS_EXTENDED_TASK_NUMBER > 0)
    case OS_MULTICORE_ACTION_SETEVENT:
        OsMultiCore_Result[CurrentCoreId] = OsEvent_InternalSetEvent(CurrentCoreId,OsMultiCore_TaskId[CurrentCoreId],OsMultiCore_EventMask[CurrentCoreId]);
        break;
#endif /*(OS_EXTENDED_TASK_NUMBER > 0)*/
#if(OS_ALARM_NUMBER > 0)
    case OS_MULTICORE_ACTION_SETABSALARM:
        OsMultiCore_Result[CurrentCoreId] = OsAlarm_InternalSetAbsAlarm(CurrentCoreId, OsMultiCore_AlarmID[CurrentCoreId], OsMultiCore_start[CurrentCoreId], OsMultiCore_cycle[CurrentCoreId]);
        break;
    case OS_MULTICORE_ACTION_SETRELALARM:
        OsMultiCore_Result[CurrentCoreId] = OsAlarm_InternalSetRelAlarm(CurrentCoreId,OsMultiCore_AlarmID[CurrentCoreId], OsMultiCore_increment[CurrentCoreId], OsMultiCore_cycle[CurrentCoreId]);
        break;
    case OS_MULTICORE_ACTION_CANCELALARM:
        OsMultiCore_Result[CurrentCoreId] = OsAlarm_InternalCancelAlarm(CurrentCoreId,OsMultiCore_AlarmID[CurrentCoreId]);
        break;
#endif /*(OS_ALARM_NUMBER > 0)*/
    case OS_MULTICORE_ACTION_SHUTDOWN:
        isShutdown = OS_TRUE;
        OsMultiCore_Result[CurrentCoreId] = E_OS_OK;
        OsKernel_InternalShutdown(CurrentCoreId, OsMultiCore_Error[CurrentCoreId], \
        SYNCHRONIZED_SHUTDOWN);
        break;
    case OS_MULTICORE_ACTION_CONTROLIDLE:
        OsMultiCore_Result[CurrentCoreId] = E_OS_OK;
        OsKernel_InternalSetMode(CurrentCoreId);
        break;
#if(OS_APPLICATION_NUMBER > 0)
    case OS_MULTICORE_ACTION_TERMINATEAPPLICATION:
        OsMultiCore_Result[CurrentCoreId] = E_OS_OK;
        OsApp_InternalTerminateApplication(CurrentCoreId,OsMultiCore_Application[CurrentCoreId],OsMultiCore_RestartOption[CurrentCoreId]);
        break;
#endif /*(OS_APPLICATION_NUMBER > 0)*/
    default:
        OsMultiCore_Result[CurrentCoreId] = E_OS_SYS_CROSSCORE_ERR;
        break;
    }
    /*PRQA S 2487 ++*/
    /* Dead loop is expected if "isShutdown" equal to "OS_TRUE" */
    while(OS_TRUE == isShutdown)
    {
        /* Use OS_PL_NOP() to avoid compiler optimize to dead cycle */
        OS_PL_NOP();
    }
    /*PRQA S 2487 --*/
}

/* BEGIN_FUNCTION_HDR
***********************************************************************************************
* Function Name: OsMultiCore_Init
*
* Description:   Called in start OS, init  module
*
* Inputs:        CoreID
*
* Outputs:       None
*
* Limitations:   None
***********************************************************************************************
END_FUNCTION_HDR*/
FUNC(void, OS_CODE) OsMultiCore_Init
(
    CoreIdType CoreID
)
{
    OsMultiCore_OpLock[CoreID] = (Os_uint32)OS_INVALID_COREID;
    OsMultiCore_Result[CoreID] = E_OS_OK;
    OsMultiCore_ActionType[CoreID] = OS_MULTICORE_NOACTION;
    OsMultiCore_FromCoreId[CoreID] = OS_INVALID_COREID;
    OsMultiCore_ToCoreId[CoreID] = OS_INVALID_COREID;
    OsMultiCore_TaskId[CoreID] = OS_INVALID_TASK_ID;
}

/* BEGIN_FUNCTION_HDR
***********************************************************************************************
* Function Name: OsMultiCore_TriggerShutdown
*
* Description:   Internal shutdown, called from shutdownAllCores
*
* Inputs:        CoreID, StatusType Error
*
* Outputs:       None
*
* Limitations:   None
***********************************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(StatusType, OS_CODE) OsMultiCore_TriggerShutdown
(
    CoreIdType CoreID,
    CoreIdType toCoreID,
    StatusType Error
)
{
    StatusType ret;
    Os_uint32 timeout = OS_MULTICORE_ACTION_TMEOUT;

    OsCpu_GetSpinlock(&OsMultiCore_OpLock[toCoreID], CoreID);
    /* Record parameters */
    OsMultiCore_Result[toCoreID] = E_OS_SYS_CROSSCORE_WAITING;
    OsMultiCore_ActionType[toCoreID] = OS_MULTICORE_ACTION_SHUTDOWN;
    OsMultiCore_FromCoreId[toCoreID] = CoreID;
    OsMultiCore_ToCoreId[toCoreID] = toCoreID;
    OsMultiCore_Error[toCoreID] = Error;

    /* Trigger SW ISR, to execute in target core*/
    OsIntc_CrossCoreIntTrigger(toCoreID);

    /*wait until action finished in another core SWS_OS_00598*/
    while((E_OS_SYS_CROSSCORE_WAITING == OsMultiCore_Result[toCoreID]) \
        && (timeout > (Os_uint32)0))
    {
        /* Use OS_PL_NOP() to avoid compiler optimize to dead cycle */
        OS_PL_NOP();
        timeout--;
    }

    /* If timeout, shutdown OS */
    if((Os_uint32)0 == timeout)
    {
        OsHook_FataErrReport(CoreID, E_OS_SYSFATA_RES_CROSSCORE_TIMEOUT, OSServiceId_OsMultiCore_TriggerShutdown, OS_IE_NOMORE_INFO, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR);
    }

    ret = OsMultiCore_Result[toCoreID];
    OsMultiCore_ActionType[toCoreID] = OS_MULTICORE_NOACTION;
    OsMultiCore_FromCoreId[toCoreID] = OS_INVALID_COREID;
    OsMultiCore_ToCoreId[toCoreID] = OS_INVALID_COREID;
    OsMultiCore_Error[toCoreID] = OS_INVALID_ERROR;
    /*PRQA S 3109,3138 ++*/
    /*
    Assembly instructions replaced by null statement just for QAC prj, 
    because PRQA can not parse assembly instructions.
    */
    OsCpu_ReleaseSpinlock(&OsMultiCore_OpLock[toCoreID]);
    /*PRQA S 3109,3138 --*/
    return ret;
}
#if(OS_APPLICATION_NUMBER > 0)
/* BEGIN_FUNCTION_HDR
***********************************************************************************************
* Function Name: OsMultiCore_TriggerTerminateApplication
*
* Description:   Internal shutdown, called from shutdown or shutdownAllCores
*
* Inputs:        CoreID, StatusType Error
*
* Outputs:       None
*
* Limitations:   None
***********************************************************************************************
END_FUNCTION_HDR*/
FUNC(StatusType, OS_CODE) OsMultiCore_TriggerTerminateApplication
(
    CoreIdType CoreID,
    ApplicationType Application,
    RestartType RestartOption
)
{
    StatusType ret;
    Os_uint32 timeout = OS_MULTICORE_ACTION_TMEOUT;
    CoreIdType toCoreID = Os_AppCfg[Application].objCoreId; 

    OsCpu_GetSpinlock(&OsMultiCore_OpLock[toCoreID], CoreID);
    /* Record parameters */
    OsMultiCore_Result[toCoreID] = E_OS_SYS_CROSSCORE_WAITING;
    OsMultiCore_ActionType[toCoreID] = OS_MULTICORE_ACTION_TERMINATEAPPLICATION;
    OsMultiCore_FromCoreId[toCoreID] = CoreID;
    OsMultiCore_ToCoreId[toCoreID] = toCoreID;
    OsMultiCore_Application[toCoreID] = Application;
    OsMultiCore_RestartOption[toCoreID] = RestartOption;

    /* Trigger SW ISR, to execute in target core*/
    OsIntc_CrossCoreIntTrigger(toCoreID);

    /*wait until action finished in another core SWS_OS_00598*/
    while((E_OS_SYS_CROSSCORE_WAITING == OsMultiCore_Result[toCoreID]) \
        && (timeout > (Os_uint32)0))
    {
        /* Use OS_PL_NOP() to avoid compiler optimize to dead cycle */
        OS_PL_NOP();
        timeout--;
    }

    /* If timeout, shutdown OS */
    if((Os_uint32)0 == timeout)
    {
        OsHook_FataErrReport(CoreID, E_OS_SYSFATA_RES_CROSSCORE_TIMEOUT, OSServiceId_OsMultiCore_TriggerShutdown, OS_IE_NOMORE_INFO, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR);
    }

    ret = OsMultiCore_Result[toCoreID];
    OsMultiCore_ActionType[toCoreID] = OS_MULTICORE_NOACTION;
    OsMultiCore_FromCoreId[toCoreID] = OS_INVALID_COREID;
    OsMultiCore_ToCoreId[toCoreID] = OS_INVALID_COREID;
    OsMultiCore_Application[toCoreID] = OS_INVALID_OSAPPLICATION;
    OsMultiCore_RestartOption[toCoreID] = RestartOption;
    /*PRQA S 3109,3138 ++*/
    /*
    Assembly instructions replaced by null statement just for QAC prj, 
    because PRQA can not parse assembly instructions.
    */
    OsCpu_ReleaseSpinlock(&OsMultiCore_OpLock[toCoreID]);
    /*PRQA S 3109,3138 --*/
    return ret;
}
#endif /*(OS_APPLICATION_NUMBER > 0)*/

/* BEGIN_FUNCTION_HDR
***********************************************************************************************
* Function Name: OsMultiCore_TriggerSetMode
*
* Description:   Internal shutdown, called from shutdown or shutdownAllCores
*
* Inputs:        CoreID, StatusType Error
*
* Outputs:       None
*
* Limitations:   None
***********************************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(StatusType, OS_CODE) OsMultiCore_TriggerSetMode
(
    CoreIdType CoreID,
    CoreIdType toCoreID
)
{
    StatusType ret;
    Os_uint32 timeout = OS_MULTICORE_ACTION_TMEOUT;

    OsCpu_GetSpinlock(&OsMultiCore_OpLock[toCoreID], CoreID);
    /* Record parameters */
    OsMultiCore_Result[toCoreID] = E_OS_SYS_CROSSCORE_WAITING;
    OsMultiCore_ActionType[toCoreID] = OS_MULTICORE_ACTION_CONTROLIDLE;
    OsMultiCore_FromCoreId[toCoreID] = CoreID;
    OsMultiCore_ToCoreId[toCoreID] = toCoreID;

    /* Trigger SW ISR, to execute in target core*/
    OsIntc_CrossCoreIntTrigger(toCoreID);

    /*wait until action finished in another core SWS_OS_00598*/
    while((E_OS_SYS_CROSSCORE_WAITING == OsMultiCore_Result[toCoreID]) \
        && (timeout > (Os_uint32)0))
    {
        /* Use OS_PL_NOP() to avoid compiler optimize to dead cycle */
        OS_PL_NOP();
        timeout--;
    }

    /* If timeout, shutdown OS */
    if((Os_uint32)0 == timeout)
    {
        OsHook_FataErrReport(CoreID, E_OS_SYSFATA_RES_CROSSCORE_TIMEOUT, OSServiceId_OsMultiCore_TriggerControlIdle, OS_IE_NOMORE_INFO, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR);
    }

    ret = OsMultiCore_Result[toCoreID];
    OsMultiCore_ActionType[toCoreID] = OS_MULTICORE_NOACTION;
    OsMultiCore_FromCoreId[toCoreID] = OS_INVALID_COREID;
    OsMultiCore_ToCoreId[toCoreID] = OS_INVALID_COREID;
    /*PRQA S 3109,3138 ++*/
    /*
    Assembly instructions replaced by null statement just for QAC prj, 
    because PRQA can not parse assembly instructions.
    */
    OsCpu_ReleaseSpinlock(&OsMultiCore_OpLock[toCoreID]);
    /*PRQA S 3109,3138 --*/
    return ret;
}

/* BEGIN_FUNCTION_HDR
***********************************************************************************************
* Function Name: OsMultiCore_InternalShutdownAllCores
*
* Description:   shutdown all cores
*
* Inputs:        CurrentCoreId, Error
*
* Outputs:       None
*
* Limitations:   None
***********************************************************************************************
END_FUNCTION_HDR*/
FUNC(void, OS_CODE) OsMultiCore_InternalShutdownAllCores
(
    CoreIdType CurrentCoreId,
    StatusType Error
)
{
    CoreIdType index;

    for (index = (CoreIdType)0; index < (CoreIdType)OS_USED_CORE_NUMBER; index++)
    {
        if (index != CurrentCoreId)
        {
            /* 
             * Shutdown other cores firstly to avoid dead loop in synchronization step 
             * of local core. 
             */
            (void)OsMultiCore_TriggerShutdown(CurrentCoreId, index, Error);
        }
    }
    /* Then shutdown local core. */
    OsKernel_InternalShutdown(CurrentCoreId, Error, SYNCHRONIZED_SHUTDOWN);
    /* Endless loop should be mode in the calling env of this function */
}

/* BEGIN_FUNCTION_HDR
***********************************************************************************************
* Function Name: OsMultiCore_InternalSetMode
*
* Description:   shutdown all cores
*
* Inputs:        CurrentCoreId, Error
*
* Outputs:       None
*
* Limitations:   None
***********************************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, OS_CODE) OsMultiCore_InternalSetMode
(
    CoreIdType CurrentCoreId,
    CoreIdType toCoreID
)
{

    if(CurrentCoreId == toCoreID)
    {
        OsKernel_InternalSetMode(CurrentCoreId);
    }
    else
    {
        (void)OsMultiCore_TriggerSetMode(CurrentCoreId, toCoreID);
    }
}

/*****************************************************************************
* API code
******************************************************************************/

/* BEGIN_FUNCTION_HDR
***********************************************************************************************
* Function Name: Os_ShutdownAllCores
*
* Description:   After this service the OS on all AUTOSAR cores is shut down
*
* Inputs:        None
*
* Outputs:       None
*
* Limitations:   None
***********************************************************************************************
END_FUNCTION_HDR*/
FUNC(void, OS_CODE)Os_ShutdownAllCores
(
    StatusType Error
)
{

    CoreIdType CurrentCoreId;

    CurrentCoreId = OsCpu_GetCoreID();

#if(OS_STATUS_LEVEL == OS_EXTENDED)
    if(CurrentCoreId >= (CoreIdType)OS_USED_CORE_NUMBER)
    {
        /* can not record err in this state, as OS services can not be called*/
    }

    else if((Os_uint16)(Os_CurrentContext[CurrentCoreId] & Os_ShutdownAllCoresMask) == (Os_uint16)0)
    {
        OsHook_ReportError(CurrentCoreId, E_OS_CALLEVEL, OSServiceId_ShutdownAllCores, OS_IE_NOMORE_INFO, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR);
    }

    /* Check whether this API is called between interrupt processing APIs*/
    else if(OS_NO_API_USED != Os_IntAPIUsedFlag[CurrentCoreId])
    {
        OsHook_ReportError(CurrentCoreId, E_OS_DISABLEDINT, OSServiceId_ShutdownAllCores, OS_IE_NOMORE_INFO, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR);
    }


#if(OS_APPLICATION_NUMBER > 0)
    /*  current application invalid, should not has this case*/
    else if(Os_CurrentApplicationId[CurrentCoreId] == OS_INVALID_OSAPPLICATION)
    {
        OsHook_ReportError (CurrentCoreId, E_OS_ACCESS, OSServiceId_ShutdownAllCores, OS_IE_INVALID_OSAPPICATION, (Os_uint32)Os_CurrentApplicationId[CurrentCoreId], OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR);
    }

    /* SWS_Os_00716 can not be called by untrusted app */
    else if(OS_FALSE == Os_AppCfg[Os_CurrentApplicationId[CurrentCoreId]].isTrusted)
    {
        OsHook_ReportError(CurrentCoreId, E_OS_ACCESS, OSServiceId_ShutdownOS,\
                OS_IE_SHUTDOWN_BY_UNTRUST_APP, (Os_uint32)Os_CurrentApplicationId[CurrentCoreId], OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR);
    }

#endif /*(OS_APPLICATION_NUMBER > 0)*/
    else
#endif /*(OS_STATUS_LEVEL == OS_EXTENDED)*/
    {

        OsMultiCore_InternalShutdownAllCores(CurrentCoreId, Error);
        /* SWS_Os_00715 never return*/
        for(;;)
        {
            /* the function will never return*/
        }
    }
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Os_StartCore
*
* Description:   The function starts the core specified by the parameter CoreID
*
* Inputs:        CoreID -- logcoreId
*
* Outputs:       Status
*
* Limitations:   Normally called by matser core to start slave cores, called in 
*                master core EcuM_Init, before StartOs. Also this API can be 
*                called only by master core. SWS_Os_00681: As Os has not been 
*                started when call this API, so all error will not call errhook 
*                or record.
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, OS_CODE) Os_StartCore
( 
    CoreIdType CoreID, 
    P2VAR(StatusType, AUTOMATIC, OS_APPL_DATA) Status
)
{
    CoreIdType CurrentCoreId;
    CoreIdType coreIndex;

    CurrentCoreId = OsCpu_GetCoreID();

#if(OS_STATUS_LEVEL == OS_EXTENDED)
    if (Status == OS_NULL)
    {
        /* do nothing */
    }
    
    /* can not call this API to start master core*/
    else if((CoreID >= (CoreIdType)OS_USED_CORE_NUMBER) || (CoreID == OS_PL_MASTER_COREID))
    {
        *Status = E_OS_ID;
    }

    /* only can be called by master core */
    else if (CurrentCoreId != OS_PL_MASTER_COREID)
    {
        *Status = E_OS_ID;
    }

    /* 
     * only can be called before master and slave core StartOs
     * SWS_Os_00678
     */
    else if (Os_CoreState[CurrentCoreId] != OS_CORE_IDLE)
    {
        *Status = E_OS_ACCESS;
    }

    /* SWS_Os_00679 */
    else if (Os_CoreState[CoreID] != OS_CORE_IDLE)
    {
        *Status = E_OS_STATE;
    }

    /* no need to check context for this API */
    else
#endif /* (OS_STATUS_LEVEL == OS_EXTENDED) */
    {
        /* switch log core id to phy core id */
        OsCpu_SetMode(Os_LogCoreToPhy[CoreID], OS_HW_CORE_START);
        /* do not change core state here, as core state will change to start after StartOs */
        /* set slave core start first */
        Os_CoreState[CoreID] = OS_CORE_START;
        *Status = E_OS_OK;
    }
}

/* BEGIN_FUNCTION_HDR
***********************************************************************************************
* Function Name: GetCoreID
*
* Description:   The function return CoreID of current core. 
*
* Inputs:        None
*
* Outputs:       CoreIdType
*
* Limitations:   return logical CoreID, not allow call this API from non autosar CORE
***********************************************************************************************
END_FUNCTION_HDR*/
FUNC(CoreIdType, OS_CODE) Os_GetCoreID(void)
{
    CoreIdType CoreID;

    CoreID = OsCpu_GetCoreID();

#if(OS_STATUS_LEVEL == OS_EXTENDED)
    if(CoreID >= (CoreIdType)OS_USED_CORE_NUMBER)
    {
        /* can not record err in this state, as OS services can not be called*/
        CoreID = OS_INVALID_COREID;
    }

    /* Get CoreID can be called in ant context, so ne need to check context */

    /* Check whether this API is called between interrupt processing APIs*/
    else if (OS_NO_API_USED != Os_IntAPIUsedFlag[CoreID])
    {
        OsHook_ReportError(CoreID, E_OS_DISABLEDINT, OSServiceId_GetCoreID, OS_IE_NOMORE_INFO, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR);
        CoreID = OS_INVALID_COREID;
    }
    else
    {
        /*do nothing*/
    }
#endif /*(OS_STATUS_LEVEL == OS_EXTENDED)*/

    return CoreID;
}

/* BEGIN_FUNCTION_HDR
***********************************************************************************************
* Function Name: Os_ControlIdle
*
* Description:   make the core to idle mode
*
* Inputs:        CoreID, -- must phyid of core
*                IdleMode -- no use now
*
* Outputs:       None
*
* Limitations:   not allow call this API from non autosar CORE
***********************************************************************************************
END_FUNCTION_HDR*/
FUNC(StatusType, OS_CODE) Os_ControlIdle
(
    CoreIdType CoreID, 
    IdleModeType IdleMode 
)
{
    CoreIdType currentCoreId;

    StatusType ret = E_OS_OK;

    currentCoreId = OsCpu_GetCoreID();
    (void)IdleMode;/* IdleMode is not used in current version sw*/

#if(OS_STATUS_LEVEL == OS_EXTENDED)
    if(CoreID >= (CoreIdType)OS_PL_MAX_CORE_NUMBER)
    {
        OsHook_ReportError(currentCoreId, E_OS_ID, OSServiceId_ControlIdle, OS_IE_COREID, (Os_uint32)CoreID, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR);
        ret = E_OS_ID;
    }

    /* see table in autosar, this API need check CONTEXT*/
    else if((currentCoreId >= (CoreIdType)OS_USED_CORE_NUMBER) || (Os_CoreState[currentCoreId] != OS_CORE_START) || (Os_CoreState[CoreID] != OS_CORE_START))
    {
        /* can not record err in this state, as OS services can not be called*/
        ret = E_OS_CORE;
    }
    
    else if((Os_uint16)(Os_CurrentContext[currentCoreId] & Os_ControlIdleMask) == (Os_uint16)0)
    {
        OsHook_ReportError(currentCoreId, E_OS_CALLEVEL, OSServiceId_ControlIdle, OS_IE_NOMORE_INFO, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR);
        ret = E_OS_CALLEVEL;
    }

    /* Check whether this API is called between interrupt processing APIs*/
    else if(OS_NO_API_USED != Os_IntAPIUsedFlag[currentCoreId])
    {
        /* System error -- this API is called between interrupt processing function pairs */
        OsHook_ReportError(currentCoreId, E_OS_DISABLEDINT, OSServiceId_ControlIdle, OS_IE_NOMORE_INFO, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR);
        ret = E_OS_DISABLEDINT;
    }
    /*SWS_Os_00771 IdleMode is not used now , so not check here*/
    
    else
#endif /*OS_STATUS_LEVEL == OS_EXTENDED)*/
    {
        OsMultiCore_InternalSetMode(currentCoreId, CoreID);

    }
    return ret;
}

/* BEGIN_FUNCTION_HDR
***********************************************************************************************
* Function Name: GetNumberOfActivatedCores
*
* Description:   The function returns the number of cores activated by the StartCore function.
*
* Inputs:        None
*
* Outputs:       None
*
* Limitations:   None
***********************************************************************************************
END_FUNCTION_HDR*/
FUNC(Os_uint32, OS_CODE) Os_GetNumberOfActivatedCores(void)
{
    Os_uint32 CoreNum = (Os_uint32)OS_INVALID_COREID;
    CoreIdType i;
    CoreIdType CoreID;

    CoreID = OsCpu_GetCoreID();

    if(Os_CoreState[CoreID] != OS_CORE_START)
    {
        /* AUTOSAR functions shall not be called on NONAUTOSAR cores */
    }

    else if((Os_uint16)(Os_CurrentContext[CoreID] & Os_GetNumberOfActivatedCoresMask) == (Os_uint16)0)
    {
        OsHook_ReportError(CoreID, E_OS_CALLEVEL, OSServiceId_GetNumberOfActivatedCores, OS_IE_NOMORE_INFO, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR);
    }
    else
    {
        CoreNum = (Os_uint32)0;

        for(i = (CoreIdType)0; i < (CoreIdType)OS_USED_CORE_NUMBER; i ++)
        {
            if(Os_CoreState[i] == OS_CORE_START)
            {
                /*PRQA S 3383 ++*/
                /* The "for" loop outside has identified wraparound guard for "CoreNum" */
                CoreNum++;
                /*PRQA S 3383 --*/
            }
        }
    }
    return CoreNum;
}

#define OS_STOP_SEC_CODE
#include "Os_MemMap.h"

#endif /*(OS_USED_CORE_NUMBER > 1)*/

#if (OS_PL_MAX_CORE_NUMBER > 1)
#define OS_START_SEC_CODE
#include "Os_MemMap.h"
/* following API can be used for non autosar core*/
/* BEGIN_FUNCTION_HDR
***********************************************************************************************
* Function Name: Os_StartNonAutosarCore
*
* Description:   The function starts the core specified by the parameter CoreID
*
* Inputs:        CoreID, must be hw phisical id for this API
*
* Outputs:       Status
*
* Limitations:   Normally called by user to start non autosar core,
                 can not call errhook or do error record for non autosar core
***********************************************************************************************
END_FUNCTION_HDR*/
FUNC (void, OS_CODE) Os_StartNonAutosarCore
( 
    CoreIdType CoreID, 
    P2VAR(StatusType, AUTOMATIC, OS_APPL_DATA) Status
)
{
    CoreIdType CurrentCoreId;
    CurrentCoreId = OsCpu_GetCoreID();


#if(OS_STATUS_LEVEL == OS_EXTENDED)
    if(Status == OS_NULL)
    {
        /* do nothing */
    }
    
    /* can not call this API non autosar core*/
    else if(CurrentCoreId >= (CoreIdType)OS_USED_CORE_NUMBER)
    {
        *Status = E_OS_ID;
    }

    /* can not call this API to start autosar core*/
    else if((CoreID < (CoreIdType)OS_USED_CORE_NUMBER) || (CoreID >= (CoreIdType)OS_PL_MAX_CORE_NUMBER))
    {
        *Status = E_OS_ID;
    }

    /* no Core State check for this API, as Os_CoreState has no state of non autosar core*/

    /* no need to check context for this API */
    else
#endif /*(OS_STATUS_LEVEL == OS_EXTENDED)*/
    {
        OsCpu_SetMode(CoreID, OS_HW_CORE_START);

        /* do not change core state here, as core state will change to start after StartOs*/
        *Status = E_OS_OK;
    }
}

#define OS_STOP_SEC_CODE
#include "Os_MemMap.h"

#endif /*(OS_PL_MAX_CORE_NUMBER > 1)*/
