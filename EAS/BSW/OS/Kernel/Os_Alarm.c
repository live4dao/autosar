/* BEGIN_FILE_HDR
********************************************************************************
* NOTICE
* This software is the property of HiRain Technologies. Any information
* contained in this doc should not be reproduced, or used, or disclosed
* without the written authorization from HiRain Technologies.
********************************************************************************
* File Name:       Os_Alarm.c
********************************************************************************
* Project/Product: AUTOSAR OS PROJECT
* Title:           Os_Alarm.c
* Author:          Hirain
********************************************************************************
* Description:     Alarm implement of OS
*
********************************************************************************
* Limitations     : None
*
********************************************************************************
*
********************************************************************************
* Revision History:
* Reference to Core Os_Kernel.c File
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

#if(OS_ALARM_NUMBER > 0)
/*****************************************************************************
* static variables define
******************************************************************************/


#define OS_START_SEC_CODE
#include "Os_MemMap.h"
/*****************************************************************************
* OS private code
******************************************************************************/

/*****************************************************************************
* OS internal code
******************************************************************************/
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: OsAlarmArray_Check
*
* Description:   A function used to check if there are alarms will expried.
*
* Inputs:        CoreID, CounterID, AlarmID
*
* Outputs:       Os_boolean: return if alarms expried
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Os_boolean, OS_CODE) OsAlarm_Check
(
    CoreIdType CoreID,
    CounterType CounterID,
    AlarmType AlarmID
)
{
    /* Must enter critical area before call this function. */
    TickType maxCntVal = Os_CounterCfg[CounterID].alarmBase.maxallowedvalue;
    P2CONST(Os_AlarmCfgType, AUTOMATIC, OS_CONST) alarmCfgPtr;
    Os_boolean isExpire = OS_FALSE;
#if(OS_ALARM_CALLBACK_NUMBER != 0)
    Os_uint16 tempCtx = Os_CurrentContext[CoreID];
#endif /* (OS_ALARM_CALLBACK_NUMBER != 0) */
    if(Os_CounterTick[CounterID] == Os_AlarmCBTable[AlarmID].timeVal)
    {
        isExpire = OS_TRUE;
        /* After read, header can be removed. */
        OsCnt_TreeRemove(CoreID, CounterID);/* Remove the header element in alarm tree. */

        /* Cyclic alarm reinsert this alarm. */
        if(Os_AlarmCBTable[AlarmID].alarmcycle != (TickType)0)
        {
            /* Here must use maxCntVal - CntValue as CntValue + cycle may exceed. */
            /*PRQA S 3383,3384 ++*/
            /*
             * OsAlarm_Check is always called by OsCnt_InternalIncreaseCounter which 
             * has ensued that "maxCntVal" is always larger than "Os_CounterTick[CounterID]". 
             * The "if..." here eliminates possibility of underflow and overflow below.
             */
            if((maxCntVal - Os_CounterTick[CounterID]) < Os_AlarmCBTable[AlarmID].alarmcycle)
            {
                Os_AlarmCBTable[AlarmID].timeVal = (Os_AlarmCBTable[AlarmID].alarmcycle - \
                    (maxCntVal - Os_CounterTick[CounterID]) - (TickType)1);
            }
            else
            {   
                Os_AlarmCBTable[AlarmID].timeVal += Os_AlarmCBTable[AlarmID].alarmcycle;
            }
            /*PRQA S 3383,3384 --*/
            OsCnt_TreeInsert(CoreID, CounterID, (Os_uint32)AlarmID, OS_TRUE);
        }
        else
        {
            /* set alarm not alive*/
            Os_AlarmCBTable[AlarmID].isAlive = OS_FALSE;
        }

        alarmCfgPtr = &Os_AlarmCfg[AlarmID];

        /* Carry out the alarm operations */
        /*PRQA S 3352 ++*/
        /* Because of configuration, the branch of switch may less than 3. */
        switch(alarmCfgPtr->OsAlarmAction)
        {
#if(OS_ALARM_ACTIVETASK_NUMBER != 0)
        case OS_ALARM_TASK:
#if(OS_USED_CORE_NUMBER > 1)
            /* Check whether crosscore operation*/
            if (CoreID != Os_TaskCfg[alarmCfgPtr->TaskID].objCoreId)
            {
                (void)OsMultiCore_TriggerActivateTask(CoreID, alarmCfgPtr->TaskID);
            }
            else
#endif /*(OS_USED_CORE_NUMBER > 1)*/
            {
                /* can not call ActivateTask API here, as too much err check may waste time,
                    * and also in ActivateTask, it will enter and exit protect section which may enable interrupt
                    *  */
                (void)OsTask_InternalActivateTask(CoreID, alarmCfgPtr->TaskID, OS_FALSE, OSServiceId_ActivateTask); /*[OS321]*/
            }
            break;
#endif /*(OS_ALARM_ACTIVETASK_NUMBER != 0)*/
#if(OS_ALARM_SETEVENT_NUMBER != 0)

        case OS_ALARM_EVENT:
#if(OS_USED_CORE_NUMBER > 1)
            /* Check whether crosscore opration*/
            if (CoreID != Os_TaskCfg[alarmCfgPtr->TaskID].objCoreId)
            {
                (void)OsMultiCore_TriggerSetEvent(CoreID, alarmCfgPtr->TaskID, alarmCfgPtr->Event);
            }
            else
#endif /*(OS_USED_CORE_NUMBER > 1)*/
            {
                (void)OsEvent_InternalSetEvent(CoreID, alarmCfgPtr->TaskID, alarmCfgPtr->Event); /*[OS321]*/
            }
            break;
#endif /*(OS_ALARM_SETEVENT_NUMBER != 0)*/
#if(OS_ALARM_CALLBACK_NUMBER != 0)

        case OS_ALARM_CALLBACK:
            Os_CurrentContext[CoreID] = OS_CONTEXT_ALARMCALLBACK;
            alarmCfgPtr->callback();  /*[OS321]*/
            Os_CurrentContext[CoreID] = tempCtx ;

            break;
#endif /*(OS_ALARM_CALLBACK_NUMBER != 0)*/
#if(OS_ALARM_INCREMENTCOUNTER_NUMBER != 0)
        case OS_ALARM_INCREMENTCOUNTER:
            /* Warning: this may cause Recursion!!!*/
            OsCnt_InternalIncreaseCounter(CoreID, alarmCfgPtr->CounterID); /*[OS321]*/
            break;
#endif /*(OS_ALARM_INCREMENTCOUNTER_NUMBER != 0)*/

        default:
            /*should never enter this branch*/
            break;
        }
        /*PRQA S 3352 --*/
    }

    return isExpire;

}

/* BEGIN_FUNCTION_HDR
***********************************************************************************************
* Function Name: OsAlarm_Init
*
* Description:   Called in StartOS, init alarm module
*
* Inputs:        CoreID
*
* Outputs:       None
*
* Limitations:   None
***********************************************************************************************
END_FUNCTION_HDR*/
FUNC(void, OS_CODE) OsAlarm_Init
(
    CoreIdType CoreID
)
{
    AlarmType i;
    AlarmType endAlarmId;

    endAlarmId = Os_CoreCfg[CoreID].startAlarmId + Os_CoreCfg[CoreID].alarmNum;

    /* Alarm must sort, auto alarms first*/
    for(i = Os_CoreCfg[CoreID].startAlarmId; i < endAlarmId; i++)
    {
        Os_AlarmCBTable[i].isAlive = OS_FALSE;
        Os_AlarmCBTable[i].alarmcycle = (TickType)0;
        Os_AlarmCBTable[i].timeVal = (TickType)0;
#if(OS_APPLICATION_NUMBER > 0)
        Os_AlarmCBTable[i].isKilled = OS_FALSE;
#endif /*(OS_APPLICATION_NUMBER > 0)*/

    }
}


/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: OsAlarm_AutoStart
*
* Description:   Called in StartOS, active all auto start alarm of this core
*
* Inputs:        CoreID
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
#if(OS_AUTO_ALARM_NUMBER > 0)
FUNC(void, OS_CODE) OsAlarm_AutoStart
(
    CoreIdType CoreID
)
{
    AlarmType i;
    AlarmType endAlarmId = Os_CoreCfg[CoreID].startAlarmId + Os_CoreCfg[CoreID].alarmNum;

    /* Start all the auto start alarm*/
    for(i = Os_CoreCfg[CoreID].startAlarmId; i < endAlarmId; i++)
    {
        if(OS_TRUE == Os_AlarmCfg[i].isAutoStart)
        {
#if(OS_APPMODE_NUMBER > 1)
            if((Os_AppModeMaskType)0 != (Os_ActiveAppMode[CoreID] & Os_AlarmCfg[i].appModeMask))
#endif /*(OS_APPMODE_NUMBER > 1)*/
            {

                if(OS_TRUE == Os_AlarmCfg[i].isAbsAlarm)
                {
                    (void)OsAlarm_InternalSetAbsAlarm(CoreID, i, Os_AlarmCfg[i].OsAlarmTime,Os_AlarmCfg[i].OsAlarmCycle);
                }
                else
                {
                    /* code */
                    (void)OsAlarm_InternalSetRelAlarm(CoreID, i, Os_AlarmCfg[i].OsAlarmTime,Os_AlarmCfg[i].OsAlarmCycle);

                }
            }
        }
    }
}
#endif /*(OS_AUTO_ALARM_NUMBER > 0)*/

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: OsAlarm_KillAlarm
*
* Description:   Call in TerminateApplication, set alarm in-active and delete it from tree
*
* Inputs:        CoreID,AlarmID
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
#if(OS_APPLICATION_NUMBER > 0)
FUNC(void, OS_CODE) OsAlarm_KillAlarm
(
    CoreIdType CoreID,
    AlarmType AlarmID
)
{
    CounterType cntId;

    /* alarm already killed, do nothing*/
    if(Os_AlarmCBTable[AlarmID].isKilled == OS_TRUE)
    {
        return;
    }

    Os_AlarmCBTable[AlarmID].isKilled = OS_TRUE;
    /* alarm not alive, just set state kill*/
    if(Os_AlarmCBTable[AlarmID].isAlive == OS_FALSE)
    {
        return;
    }

    /*if alarm alive , delete it from tree*/

    cntId = Os_AlarmCfg[AlarmID].OsAlarmCounter;
    OsCnt_DelTreeElement(CoreID, cntId, (Os_uint32)AlarmID, OS_TRUE); /*Cancel the current alarm. */
    Os_AlarmCBTable[AlarmID].isAlive = OS_FALSE; /* Clear the alive flag of the current alarm. */

}
#endif /*(OS_APPLICATION_NUMBER > 0)*/


/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: OsAlarm_InternalSetRelAlarm
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
FUNC(StatusType, OS_CODE) OsAlarm_InternalSetRelAlarm
(
    CoreIdType CoreID,
    AlarmType AlarmID,
    TickType increment,
    TickType cycle
)
{
    CounterType CounterID = Os_AlarmCfg[AlarmID].OsAlarmCounter;
    P2CONST(Os_CounterCfgType, AUTOMATIC, OS_CONST) cntCfgPtr = &Os_CounterCfg[CounterID];
    StatusType ret = E_OS_OK;

    /* following checks not include by OS_STATUS_LEVEL
     * as these errors are runtime errors
     * */
    /*
     * check if alarm is killed, alarm can be killed only when teminateApplication called
     * */
#if(OS_APPLICATION_NUMBER > 0)
    if(Os_AlarmCBTable[AlarmID].isKilled == OS_TRUE)
    {
        OsHook_ReportErrorDisInt (CoreID, E_OS_ACCESS, OSServiceId_OsAlarm_InternalSetRelAlarm, OS_IE_OBJECT_KILLED, (Os_uint32)AlarmID, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR);
        ret = E_OS_ACCESS;    /* the alarm has been killed */
    }
    else
#endif /*(OS_APPLICATION_NUMBER > 0)*/

    /* check if alarm is alive, alive alarm can not be set again*/
    if(Os_AlarmCBTable[AlarmID].isAlive == OS_TRUE)
    {
        OsHook_ReportErrorDisInt (CoreID, E_OS_STATE, OSServiceId_SetRelAlarm, OS_IE_ALARM_ALREADY_ALIVE, (Os_uint32)AlarmID, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR);
        ret = E_OS_STATE;
    }
    else
    {
        /* Alarm values setting */
        /*PRQA S 3383,3384 ++*/
        /*
        "Os_CounterTick" was increased by "OsCnt_InternalIncreaseCounter" which restricted it on
        value that less than or equal to ".maxallowedvalue". Underflow can not happen.
        The "if..." in here eliminates the possibility of undflow and overflow below.
        */
        if(increment > ((cntCfgPtr->alarmBase.maxallowedvalue) - Os_CounterTick[CounterID]))
        {
            Os_AlarmCBTable[AlarmID].timeVal = increment - (cntCfgPtr->alarmBase.maxallowedvalue - Os_CounterTick[CounterID]) - (TickType)1;
        }
        else
        {
            Os_AlarmCBTable[AlarmID].timeVal = increment + Os_CounterTick[CounterID];
        }
        /*PRQA S 3383,3384 --*/

        Os_AlarmCBTable[AlarmID].alarmcycle = cycle;


        Os_AlarmCBTable[AlarmID].isAlive = OS_TRUE; /* Set the alive flag of the alarm. */
        OsCnt_TreeInsert(CoreID, CounterID, (Os_uint32)AlarmID, OS_TRUE); /* Insert the activated alarm to the alarm ready queue. */
    }
    return ret;
}


/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: OsAlarm_InternalSetAbsAlarm
*
* Description:   Internal set Abs Alarm, called by Alarm and crosscore setAlarm
*
* Inputs:        CoreID,AlarmID,start,cycle
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(StatusType, OS_CODE) OsAlarm_InternalSetAbsAlarm
(
    CoreIdType CoreID,
    AlarmType AlarmID,
    TickType start,
    TickType cycle
)
{
    CounterType CounterID = Os_AlarmCfg[AlarmID].OsAlarmCounter;
    P2CONST(Os_CounterCfgType, AUTOMATIC, OS_CONST) cntCfgPtr = &Os_CounterCfg[CounterID];
    StatusType ret = E_OS_OK;

    /* following checks not include by OS_STATUS_LEVEL
     * as these errors are runtime errors
     * */
    /*
     * check if alarm is killed, alarm can be killed only when teminateApplication called
     * */
#if(OS_APPLICATION_NUMBER > 0)
    if(Os_AlarmCBTable[AlarmID].isKilled == OS_TRUE)
    {
        OsHook_ReportErrorDisInt (CoreID, E_OS_ACCESS, OSServiceId_OsAlarm_InternalSetAbsAlarm, OS_IE_OBJECT_KILLED, (Os_uint32)AlarmID, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR);
        ret = E_OS_ACCESS;    /* the alarm has been killed */
    }
    else
#endif /*(OS_APPLICATION_NUMBER > 0)*/

    /* check if alarm is alive, alive alarm can not be set again*/
    if(Os_AlarmCBTable[AlarmID].isAlive == OS_TRUE)
    {
        OsHook_ReportErrorDisInt (CoreID, E_OS_STATE, OSServiceId_SetAbsAlarm, OS_IE_ALARM_ALREADY_ALIVE, (Os_uint32)AlarmID, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR);
        ret = E_OS_STATE;
    }
    else
    {
        if(Os_CounterTick[CounterID] == start)
        {
            if(start == cntCfgPtr->alarmBase.maxallowedvalue)
            {
                Os_AlarmCBTable[AlarmID].timeVal = (TickType)0;
            }
            else
            {
                /*PRQA S 3383 ++*/
                /*
                The "if..." above make sure that here will not overflow 
                because "start" is less than ".maxallowedvalue".
                */
                Os_AlarmCBTable[AlarmID].timeVal = start + (TickType)1;
                /*PRQA S 3383 --*/
            }
        }
        else
        {
            Os_AlarmCBTable[AlarmID].timeVal = start;
        }
        Os_AlarmCBTable[AlarmID].alarmcycle = cycle;
        Os_AlarmCBTable[AlarmID].isAlive = OS_TRUE;/* Set the alive flag of the alarm. */
        OsCnt_TreeInsert(CoreID, CounterID, (Os_uint32)AlarmID, OS_TRUE); /* Insert the activated alarm to the alarm ready queue. */
    }
    return ret;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: OsAlarm_InternalCancelAlarm
*
* Description:   Internal cancel Alarm, called by Alarm and crosscore cancelAlarm
*
* Inputs:        CoreID,AlarmID
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(StatusType, OS_CODE) OsAlarm_InternalCancelAlarm
(
    CoreIdType CoreID,
    AlarmType AlarmID
)
{
    CounterType CounterID = Os_AlarmCfg[AlarmID].OsAlarmCounter;
    StatusType ret = E_OS_OK;

    /* following checks not include by OS_STATUS_LEVEL
     * as these errors are runtime errors
     * */
    /*
     * check if alarm is killed, alarm can be killed only when teminateApplication called
     * */
#if(OS_APPLICATION_NUMBER > 0)
    if(Os_AlarmCBTable[AlarmID].isKilled == OS_TRUE)
    {
        OsHook_ReportErrorDisInt (CoreID, E_OS_ACCESS, OSServiceId_OsAlarm_InternalCancelAlarm, OS_IE_OBJECT_KILLED, (Os_uint32)AlarmID, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR);
        ret = E_OS_ACCESS;    /* the alarm has been killed */
    }
    else
#endif /*(OS_APPLICATION_NUMBER > 0)*/

    /* check if alarm is alive, only alive alarm can be cancel */
    if(Os_AlarmCBTable[AlarmID].isAlive == OS_FALSE)
    {
        OsHook_ReportErrorDisInt (CoreID, E_OS_NOFUNC, OSServiceId_CancelAlarm, OS_IE_NOMORE_INFO, (Os_uint32)AlarmID, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR);
        ret = E_OS_NOFUNC;
    }
    else
    {
        OsCnt_DelTreeElement(CoreID, CounterID, (Os_uint32)AlarmID,  OS_TRUE); /*Cancel the current alarm. */
        Os_AlarmCBTable[AlarmID].isAlive = OS_FALSE; /* Clear the alive flag of the current alarm. */
    }

    return ret;

}


/*****************************************************************************
* API code
******************************************************************************/
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Os_GetAlarm
*
* Description:   API function called by Application.returns the relative value in ticks before the alarm expires.
*
* Inputs:        <AlarmID> Reference to the alarm element.
*
* Outputs:       <Tick> Relative value in ticks before the alarm expires.
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(StatusType, OS_CODE) Os_GetAlarm
(
    AlarmType AlarmID,
    TickRefType Tick
)
{
    CoreIdType CoreID;
    Os_boolean tempPri;
    CounterType CounterID;
    TickType alarmTime;
    StatusType ret = E_OS_OK;

    CoreID = OsCpu_GetCoreID();

#if(OS_STATUS_LEVEL == OS_EXTENDED)
    if((CoreID >= (CoreIdType)OS_USED_CORE_NUMBER) || (Os_CoreState[CoreID] != OS_CORE_START))
    {
        /* can not record err in this state, as OS services can not be called*/
        ret = E_OS_CORE;
    }

    else if((Os_uint16)(Os_CurrentContext[CoreID] & Os_GetAlarmMask) == (Os_uint16)0)
    {
        OsHook_ReportError(CoreID, E_OS_CALLEVEL, OSServiceId_GetAlarm, OS_IE_NOMORE_INFO, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR);
        ret = E_OS_CALLEVEL;
    }

    /* Check the validity of Value:Value cannot be NULL */
    else if(NULL_PTR == Tick)
    {
        OsHook_ReportError(CoreID, E_OS_PARAM_POINTER, OSServiceId_GetAlarm, OS_IE_NOMORE_INFO, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR);
        ret = E_OS_PARAM_POINTER;
    }

    /* Check whether this API is called between interrupt processing APIs*/
    else if(OS_NO_API_USED != Os_IntAPIUsedFlag[CoreID])
    {
        /* System error -- this API is called between interrupt processing function pairs */
        OsHook_ReportError(CoreID, E_OS_DISABLEDINT, OSServiceId_GetAlarm, OS_IE_NOMORE_INFO, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR);
        ret = E_OS_DISABLEDINT;
    }

    /* Check TaskID valid or not*/
    else if(AlarmID >= (AlarmType)OS_ALARM_NUMBER)
    {
        OsHook_ReportError(CoreID, E_OS_ID, OSServiceId_GetAlarm, OS_IE_ALARM_ID, (Os_uint32)AlarmID, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR);
        ret = E_OS_ID;
    }

#if(OS_USED_CORE_NUMBER > 1)
    /* Check whether this API is called from different core*/
    else if(CoreID != Os_AlarmCfg[AlarmID].objCoreId)
    {
        OsHook_ReportError(CoreID, E_OS_SYS_SERVICE_NOTSUPPORT_CROSSCORE, OSServiceId_GetAlarm, OS_IE_NOMORE_INFO, (Os_uint32)AlarmID, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR);
        ret = E_OS_SYS_SERVICE_NOTSUPPORT_CROSSCORE;
    }
#endif /*(OS_USED_CORE_NUMBER > 1)*/

#if(OS_APPLICATION_NUMBER > 0)
    /*  current application invalid, should not has this case*/
    else if(Os_CurrentApplicationId[CoreID] == OS_INVALID_OSAPPLICATION)
    {
        OsHook_ReportError(CoreID, E_OS_ACCESS, OSServiceId_GetAlarm, OS_IE_INVALID_OSAPPICATION, (Os_uint32)Os_CurrentApplicationId[CoreID], OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR);
        ret = E_OS_ACCESS;
    }

    /* has no access right from current application*/
    else if((Os_ApplicationMaskType)0 == ((((Os_ApplicationMaskType)1) << Os_CurrentApplicationId[CoreID]) & ((Os_AlarmCfg[AlarmID].AppMask))))
    {
        OsHook_ReportError(CoreID, E_OS_ACCESS, OSServiceId_GetAlarm, OS_IE_NO_ACCESS_RIGHT, (Os_uint32)Os_CurrentApplicationId[CoreID], OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR);
        ret = E_OS_ACCESS;
    }
#endif /*(OS_APPLICATION_NUMBER > 0)*/
    else
#endif /*(OS_STATUS_LEVEL == OS_EXTENDED)*/


    /* following checks not include by OS_STATUS_LEVEL
    * as these errors are runtime errors
    * */
    /*
    * check if alarm is killed, alarm can be killed only when teminateApplication called
    * */
#if(OS_APPLICATION_NUMBER > 0)
    if(Os_AlarmCBTable[AlarmID].isKilled == OS_TRUE)/* SWS_OS_00509*/
    {
        OsHook_ReportError(CoreID, E_OS_ACCESS, OSServiceId_GetAlarm, OS_IE_OBJECT_KILLED, (Os_uint32)AlarmID, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR);
        ret = E_OS_ACCESS;    /* the alarm has been killed */
    }
    else
#endif /*(OS_APPLICATION_NUMBER > 0)*/

    /* check if alarm is alive*/
    if(Os_AlarmCBTable[AlarmID].isAlive == OS_FALSE)
    {
        OsHook_ReportError(CoreID, E_OS_NOFUNC, OSServiceId_GetAlarm, OS_IE_NOMORE_INFO, (Os_uint32)AlarmID, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR);
        ret = E_OS_NOFUNC;    /* the alarm is not alive */
    }
    else
    {
        /* Os_CounterTick can not be protected by spinlock, so this API do not support cross core opration */

        /* Enter critical section */
        /* must disable int of current core first, to avoid calling spinlock at same core*/
        OsCpu_EnterCritical(CoreID, &tempPri);

        CounterID = Os_AlarmCfg[AlarmID].OsAlarmCounter;

        /* Set the alarmtime value of the processed alarm to "auhOsAlarmTime". */
        alarmTime = Os_AlarmCBTable[AlarmID].timeVal;

        if(alarmTime >= Os_CounterTick[CounterID])
        {
            *Tick = alarmTime - Os_CounterTick[CounterID];
        }
        else
        {
            /*PRQA S 3383,3384 ++*/
            /*
            "Os_CounterTick" was increased by "OsCnt_InternalIncreaseCounter" which restricted it on
            value that less than or equal to ".maxallowedvalue". Underflow can not happen.
            Overflow can not happen because "Os_CounterTick" is larger than "alarmTime".
            */
            *Tick = alarmTime + (TickType)1 + (Os_CounterCfg[CounterID].alarmBase.maxallowedvalue - Os_CounterTick[CounterID]);
            /*PRQA S 3383,3384 --*/
        }

        OsCpu_ExitCritical(CoreID, tempPri);
    }

    return ret;

}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Os_GetAlarmBase
*
* Description:   API function called by Application.Reads the alarm base characteristics.
*
* Inputs:        <AlarmID> Reference to the alarm element.
*
* Outputs:       <Info> Reference to structure with constants of the alarm base.
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(StatusType, OS_CODE) Os_GetAlarmBase
(
    AlarmType AlarmID,
    AlarmBaseRefType Info
)
{
    CoreIdType CoreID;
    Os_boolean tempPri;
    CounterType CounterID;
    StatusType ret = E_OS_OK;

    CoreID = OsCpu_GetCoreID();

#if(OS_STATUS_LEVEL == OS_EXTENDED)
    if((CoreID >= (CoreIdType)OS_USED_CORE_NUMBER) || (Os_CoreState[CoreID] != OS_CORE_START))
    {
        /* can not record err in this state, as OS services can not be called*/
        ret = E_OS_CORE;
    }

    else if((Os_uint16)(Os_CurrentContext[CoreID] & Os_GetAlarmBaseMask) == (Os_uint16)0)
    {
        OsHook_ReportError(CoreID, E_OS_CALLEVEL, OSServiceId_GetAlarmBase, OS_IE_NOMORE_INFO, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR);
        ret = E_OS_CALLEVEL;
    }

    /* Check the validity of Value:Value cannot be NULL */
    else if(NULL_PTR == Info)
    {
        OsHook_ReportError(CoreID, E_OS_PARAM_POINTER, OSServiceId_GetAlarmBase, OS_IE_NOMORE_INFO, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR);
        ret = E_OS_PARAM_POINTER;
    }

    /* Check whether this API is called between interrupt processing APIs*/
    else if(OS_NO_API_USED != Os_IntAPIUsedFlag[CoreID])
    {
        /* System error -- this API is called between interrupt processing function pairs */
        OsHook_ReportError(CoreID, E_OS_DISABLEDINT, OSServiceId_GetAlarmBase, OS_IE_NOMORE_INFO, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR);
        ret = E_OS_DISABLEDINT;
    }

    /* Check TaskID valid or not*/
    else if(AlarmID >= (AlarmType)OS_ALARM_NUMBER)
    {
        OsHook_ReportError(CoreID, E_OS_ID, OSServiceId_GetAlarmBase, OS_IE_ALARM_ID, (Os_uint32)AlarmID, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR);
        ret = E_OS_ID;
    }

#if(OS_APPLICATION_NUMBER > 0)
    /*  current application invalid, should not has this case*/
    else if(Os_CurrentApplicationId[CoreID] == OS_INVALID_OSAPPLICATION)
    {
        OsHook_ReportError(CoreID, E_OS_ACCESS, OSServiceId_GetAlarmBase, OS_IE_INVALID_OSAPPICATION, (Os_uint32)Os_CurrentApplicationId[CoreID], OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR);
        ret = E_OS_ACCESS;
    }


    else if((Os_ApplicationMaskType)0 == ( (((Os_ApplicationMaskType)1) << Os_CurrentApplicationId[CoreID]) & ((Os_AlarmCfg[AlarmID].AppMask) ) ))
    {
        OsHook_ReportError(CoreID, E_OS_ACCESS, OSServiceId_GetAlarmBase, OS_IE_NO_ACCESS_RIGHT, (Os_uint32)Os_CurrentApplicationId[CoreID], OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR);
        ret = E_OS_ACCESS;
    }

#endif /*(OS_APPLICATION_NUMBER > 0)*/
    else
#endif /*(OS_STATUS_LEVEL == OS_EXTENDED)*/
    {
        /*
        This API only read data from config parameters
        so no need to check if alarm is killed
        no need to lock internal spinlock
        */

        /* Enter critical section */
        OsCpu_EnterCritical(CoreID, &tempPri);

        CounterID = Os_AlarmCfg[AlarmID].OsAlarmCounter;

        /*Check write access rights*/
        Info->maxallowedvalue = Os_CounterCfg[CounterID].alarmBase.maxallowedvalue;
        Info->ticksperbase = Os_CounterCfg[CounterID].alarmBase.ticksperbase;
        Info->mincycle = Os_CounterCfg[CounterID].alarmBase.mincycle;

        OsCpu_ExitCritical(CoreID, tempPri);
    }
    return ret;
}


/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Os_SetRelAlarm
*
* Description:   API function called by Application. Uses to Activate an alarm.
*
* Inputs:        <AlarmID> Reference to the alarm element
*                <increment> increment value in ticks from now
*                <cycle> Cycle value in case of cyclic alarm.
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(StatusType, OS_CODE) Os_SetRelAlarm
(
    AlarmType AlarmID,
    TickType increment,
    TickType cycle
)
{
    CoreIdType CoreID;
    Os_boolean tempPri;
#if(OS_STATUS_LEVEL == OS_EXTENDED)
    P2CONST(Os_CounterCfgType, AUTOMATIC, OS_CONST) cntCfgPtr;
    CounterType CounterID;
#endif /*(OS_STATUS_LEVEL == OS_EXTENDED)*/
    StatusType ret = E_OS_OK;
    CoreID = OsCpu_GetCoreID();

#if(OS_STATUS_LEVEL == OS_EXTENDED)
    /* Check TaskID valid or not*/
    if(AlarmID >= (AlarmType)OS_ALARM_NUMBER)
    {
        OsHook_ReportError(CoreID, E_OS_ID, OSServiceId_SetRelAlarm, OS_IE_ALARM_ID, (Os_uint32)AlarmID, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR);
        ret = E_OS_ID;
        return ret;
    }
    CounterID = Os_AlarmCfg[AlarmID].OsAlarmCounter;
    cntCfgPtr = &Os_CounterCfg[CounterID];
#if(OS_SYSTICK_MODE == OS_HRT_MODE)
    Os_CounterTick[CounterID] = OsSysTimer_UpdateCounter(CoreID,CounterID);
#endif
    if((CoreID >= (CoreIdType)OS_USED_CORE_NUMBER) || (Os_CoreState[CoreID] != OS_CORE_START))
    {
        /* can not record err in this state, as OS services can not be called*/
        ret = E_OS_CORE;
    }

    else if((Os_uint16)(Os_CurrentContext[CoreID] & Os_SetRelAlarmMask) == (Os_uint16)0)
    {
        OsHook_ReportError(CoreID, E_OS_CALLEVEL, OSServiceId_SetRelAlarm, OS_IE_NOMORE_INFO, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR);
        ret = E_OS_CALLEVEL;
    }

    /* Check whether this API is called between interrupt processing APIs*/
    else if(OS_NO_API_USED != Os_IntAPIUsedFlag[CoreID])
    {
        /* System error -- this API is called between interrupt processing function pairs */
        OsHook_ReportError(CoreID, E_OS_DISABLEDINT, OSServiceId_SetRelAlarm, OS_IE_NOMORE_INFO, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR);
        ret = E_OS_DISABLEDINT;
    }

    else if(((TickType)0 == increment) || (increment > cntCfgPtr->alarmBase.maxallowedvalue))
    {
        OsHook_ReportError(CoreID, E_OS_VALUE, OSServiceId_SetRelAlarm, OS_IE_ALARM_INCREAMENT, (Os_uint32)AlarmID, increment, cycle);
        ret = E_OS_VALUE;/*[OS304]*/
    }

    else if(((TickType)0 != cycle) && ((cycle > cntCfgPtr->alarmBase.maxallowedvalue) || (cycle < cntCfgPtr->alarmBase.mincycle)))
    {
        OsHook_ReportError(CoreID, E_OS_VALUE, OSServiceId_SetRelAlarm, OS_IE_ALARM_CYCLE, (Os_uint32)AlarmID, increment, cycle);
        ret = E_OS_VALUE;/*[OS304]*/
    }


#if(OS_APPLICATION_NUMBER > 0)
    /*  current application invalid, should not has this case*/
    else if(Os_CurrentApplicationId[CoreID] == OS_INVALID_OSAPPLICATION)
    {
        OsHook_ReportError(CoreID, E_OS_ACCESS, OSServiceId_SetRelAlarm, OS_IE_INVALID_OSAPPICATION, (Os_uint32)Os_CurrentApplicationId[CoreID], OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR);
        ret = E_OS_ACCESS;
    }


    else if((Os_ApplicationMaskType)0 == ( (((Os_ApplicationMaskType)1) << Os_CurrentApplicationId[CoreID]) & Os_AlarmCfg[AlarmID].AppMask) )
    {
        OsHook_ReportError(CoreID, E_OS_ACCESS, OSServiceId_SetRelAlarm, OS_IE_NO_ACCESS_RIGHT, (Os_uint32)Os_CurrentApplicationId[CoreID], (Os_uint32)AlarmID, OS_IE_NO_ERRPAR);
        ret = E_OS_ACCESS;
    }

#endif /*(OS_APPLICATION_NUMBER > 0)*/
    else
#endif /*(OS_STATUS_LEVEL == OS_EXTENDED)*/
    {
        /* Enter critical section */
        OsCpu_EnterCritical(CoreID, &tempPri);

#if(OS_USED_CORE_NUMBER > 1)
        /* Check whether this API is called from diifferent core*/
        if(CoreID != Os_AlarmCfg[AlarmID].objCoreId)
        {
            ret = OsMultiCore_TriggerSetRelAlarm(CoreID, AlarmID, increment, cycle);
        }
        else
#endif /*(OS_USED_CORE_NUMBER > 1)*/
        {
            ret = OsAlarm_InternalSetRelAlarm(CoreID, AlarmID, increment, cycle);
        }

        /* Exit critical section */
        OsCpu_ExitCritical(CoreID, tempPri);
    }
    return ret;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Os_SetAbsAlarm
*
* Description:   API function called by Application. Uses to Activate an alarm.
*
* Inputs:        <AlarmID> Reference to the alarm element
*                <start> Absolute value in ticks
*                <cycle> Cycle value in case of cyclic alarm.
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(StatusType, OS_CODE) Os_SetAbsAlarm
(
    AlarmType AlarmID,
    TickType start,
    TickType cycle
)
{
    CoreIdType CoreID;
    Os_boolean tempPri;
#if(OS_STATUS_LEVEL == OS_EXTENDED)
    P2CONST(Os_CounterCfgType, AUTOMATIC, OS_CONST) cntCfgPtr;
    CounterType CounterID;
#endif /*(OS_STATUS_LEVEL == OS_EXTENDED)*/
    StatusType ret = E_OS_OK;
    CoreID = OsCpu_GetCoreID();
    
#if(OS_STATUS_LEVEL == OS_EXTENDED)
    /* Check TaskID valid or not*/
    if(AlarmID >= (AlarmType)OS_ALARM_NUMBER)
    {
        OsHook_ReportError(CoreID, E_OS_ID, OSServiceId_SetAbsAlarm, OS_IE_ALARM_ID, (Os_uint32)AlarmID, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR);
        ret = E_OS_ID;
        return ret;
    }
    CounterID = Os_AlarmCfg[AlarmID].OsAlarmCounter;
    cntCfgPtr = &Os_CounterCfg[CounterID];
#if(OS_SYSTICK_MODE == OS_HRT_MODE)
    Os_CounterTick[CounterID] = OsSysTimer_UpdateCounter(CoreID,CounterID);
#endif
    if((CoreID >= (CoreIdType)OS_USED_CORE_NUMBER) || (Os_CoreState[CoreID] != OS_CORE_START))
    {
        /* can not record err in this state, as OS services can not be called*/
        ret = E_OS_CORE;
    }

    else if((Os_uint16)(Os_CurrentContext[CoreID] & Os_SetAbsAlarmMask) == (Os_uint16)0)
    {
        OsHook_ReportError(CoreID, E_OS_CALLEVEL, OSServiceId_SetAbsAlarm, OS_IE_NOMORE_INFO, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR);
        ret = E_OS_CALLEVEL;
    }

    /* Check whether this API is called between interrupt processing APIs*/
    else if(OS_NO_API_USED != Os_IntAPIUsedFlag[CoreID])
    {
        OsHook_ReportError(CoreID, E_OS_DISABLEDINT, OSServiceId_SetAbsAlarm, OS_IE_NOMORE_INFO, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR);
        ret = E_OS_DISABLEDINT;
    }

    else if(start > cntCfgPtr->alarmBase.maxallowedvalue)
    {
        OsHook_ReportError(CoreID, E_OS_VALUE, OSServiceId_SetAbsAlarm, OS_IE_ALARM_START, (Os_uint32)AlarmID, start, cycle);
        ret = E_OS_VALUE;/*[OS304]*/
    }

    else if(((TickType)0 != cycle) && ((cycle > cntCfgPtr->alarmBase.maxallowedvalue) || (cycle < cntCfgPtr->alarmBase.mincycle)))
    {
        OsHook_ReportError(CoreID, E_OS_VALUE, OSServiceId_SetAbsAlarm, OS_IE_ALARM_CYCLE, (Os_uint32)AlarmID, start, cycle);
        ret = E_OS_VALUE;/*[OS304]*/
    }

#if(OS_APPLICATION_NUMBER > 0)
    /*  current application invalid, should not has this case*/
    else if(Os_CurrentApplicationId[CoreID] == OS_INVALID_OSAPPLICATION)
    {
        OsHook_ReportError(CoreID, E_OS_ACCESS, OSServiceId_SetAbsAlarm, OS_IE_INVALID_OSAPPICATION, (Os_uint32)Os_CurrentApplicationId[CoreID], OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR);
        ret = E_OS_ACCESS;
    }

    else if((Os_ApplicationMaskType)0 == ( (((Os_ApplicationMaskType)1) << Os_CurrentApplicationId[CoreID]) & (Os_AlarmCfg[AlarmID].AppMask) ) )
    {
        OsHook_ReportError(CoreID, E_OS_ACCESS, OSServiceId_SetAbsAlarm, OS_IE_NO_ACCESS_RIGHT, (Os_uint32)Os_CurrentApplicationId[CoreID], (Os_uint32)AlarmID, OS_IE_NO_ERRPAR);
        ret = E_OS_ACCESS;
    }

#endif /*(OS_APPLICATION_NUMBER > 0)*/
    else
#endif /*(OS_STATUS_LEVEL == OS_EXTENDED)*/
    {
        /* Enter critical section */
        OsCpu_EnterCritical(CoreID, &tempPri);

#if(OS_USED_CORE_NUMBER > 1)
        /* Check whether this API is called from diifferent core*/
        if (CoreID != Os_AlarmCfg[AlarmID].objCoreId)
        {
            ret = OsMultiCore_TriggerSetAbsAlarm(CoreID, AlarmID, start, cycle);
        }
        else
#endif /*(OS_USED_CORE_NUMBER > 1)*/
        {
            ret = OsAlarm_InternalSetAbsAlarm(CoreID, AlarmID, start, cycle);
        }

        /*Exit critical section */
        OsCpu_ExitCritical(CoreID, tempPri);
    }
    return ret;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Os_CancelAlarm
*
* Description:   API function called by Application. Uses to Cancel the alarm.
*
* Inputs:        <AlarmID> Reference to the alarm element
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(StatusType, OS_CODE) Os_CancelAlarm
(
    AlarmType AlarmID
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

    else if((Os_uint16)(Os_CurrentContext[CoreID] & Os_CancelAlarmMask) == (Os_uint16)0)
    {
        OsHook_ReportError(CoreID, E_OS_CALLEVEL, OSServiceId_CancelAlarm, OS_IE_NOMORE_INFO, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR);
        ret = E_OS_CALLEVEL;
    }

    /* Check whether this API is called between interrupt processing APIs*/
    else if(OS_NO_API_USED != Os_IntAPIUsedFlag[CoreID])
    {
        /* System error -- this API is called between interrupt processing function pairs */
        OsHook_ReportError(CoreID, E_OS_DISABLEDINT, OSServiceId_CancelAlarm, OS_IE_NOMORE_INFO, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR);
        ret = E_OS_DISABLEDINT;
    }

    /* Check TaskID valid or not*/
    else if(AlarmID >= (AlarmType)OS_ALARM_NUMBER)
    {
        OsHook_ReportError(CoreID, E_OS_ID, OSServiceId_CancelAlarm, OS_IE_ALARM_ID, (Os_uint32)AlarmID, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR);
        ret = E_OS_ID;
    }

#if(OS_APPLICATION_NUMBER > 0)
    /*  current application invalid, should not has this case*/
    else if(Os_CurrentApplicationId[CoreID] == OS_INVALID_OSAPPLICATION)
    {
        OsHook_ReportError(CoreID, E_OS_ACCESS, OSServiceId_CancelAlarm, OS_IE_INVALID_OSAPPICATION, (Os_uint32)Os_CurrentApplicationId[CoreID], OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR);
        ret = E_OS_ACCESS;
    }

    else if((Os_ApplicationMaskType)0 == ( (((Os_ApplicationMaskType)1) << Os_CurrentApplicationId[CoreID]) & Os_AlarmCfg[AlarmID].AppMask))
    {
        OsHook_ReportError(CoreID, E_OS_ACCESS, OSServiceId_CancelAlarm, OS_IE_NO_ACCESS_RIGHT, (Os_uint32)Os_CurrentApplicationId[CoreID], (Os_uint32)AlarmID, OS_IE_NO_ERRPAR);
        ret = E_OS_ACCESS;
    }

#endif /*(OS_APPLICATION_NUMBER > 0)*/
    else
#endif /*(OS_STATUS_LEVEL == OS_EXTENDED)*/
    {
        /* Enter critical section */
        OsCpu_EnterCritical(CoreID, &tempPri);

#if(OS_USED_CORE_NUMBER > 1)
        /* Check whether this API is called from diifferent core*/
        if(CoreID != Os_AlarmCfg[AlarmID].objCoreId)
        {
            ret = OsMultiCore_TriggerCancelAlarm(CoreID, AlarmID);
        }
        else
#endif /*(OS_USED_CORE_NUMBER > 1)*/
        {
            ret = OsAlarm_InternalCancelAlarm(CoreID, AlarmID);
        }

        /* Exit critical section */
        OsCpu_ExitCritical(CoreID, tempPri);
    }
    return ret;
}




#define OS_STOP_SEC_CODE
#include "Os_MemMap.h"

#endif /*(OS_ALARM_NUMBER > 0)*/

