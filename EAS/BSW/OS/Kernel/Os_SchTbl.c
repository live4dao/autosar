/*  BEGIN_FILE_HDR
********************************************************************************
*   NOTICE
*   This software is the property of HiRain Technologies. Any information
*   contained in this doc should not be reproduced, or used, or disclosed
*   without the written authorization from HiRain Technologies.
********************************************************************************
* File Name:       Os_SchTbl.c
********************************************************************************
* Project/Product: AUTOSAR OS PROJECT
* Title:           Os_SchTbl.c
* Author:          Hirain
********************************************************************************
* Description:     Schedule Table implement of OS
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

/*PRQA S 0553 EOF*/
/*
Some files are empty because user do not enable this function.
*/

#if(OS_SCHTBL_NUMBER > 0)
/*****************************************************************************
* private marco
******************************************************************************/
#define OS_SCHTBL_START   ((Os_uint8)0xFF)

/*****************************************************************************
* static variables define
******************************************************************************/

#define OS_START_SEC_CODE
#include "Os_MemMap.h"
/*****************************************************************************
* OS private code
******************************************************************************/
STATIC FUNC(StatusType, OS_CODE) OsSchTbl_InternalNext
(
    CoreIdType CoreID,
    ScheduleTableType ScheduleTableID_From,
    ScheduleTableType ScheduleTableID_To
);

/*****************************************************************************
* OS internal code
******************************************************************************/
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: OsSchTbl_Trigger
*
* Description:   A founction used to check if there are sch table will expried.
*
* Inputs:        CoreID,CounterID, SchId
*
* Outputs:       return if schtbl expire
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Os_boolean, OS_CODE) OsSchTbl_Trigger
(
    CoreIdType CoreID,
    CounterType CounterID,
    ScheduleTableType SchId
)
{
    /*must enter critical area before call this function */
    TickType maxCntVal = Os_CounterCfg[CounterID].alarmBase.maxallowedvalue;
    ScheduleTableType toSchId;
    Os_boolean isExpire = OS_FALSE;

    P2CONST(Os_SchTblCfgType, AUTOMATIC, OS_CONST) schCfgPtr = &Os_SchTblCfg[SchId];

    Os_uint8 epIndex;
    Os_uint8 nextEpIndex;
    Os_uint8 epActIndex;
    P2CONST(Os_SchTblEpActionCfgType, AUTOMATIC, OS_CONST) epActCfgPtr;


    if(Os_CounterTick[CounterID] == Os_SchTblCBTable[SchId].timeVal)
    {
        isExpire = OS_TRUE;
        /*after read, header can be removed*/
        OsCnt_TreeRemove(CoreID, CounterID);/* remove the header element in  tree*/

        epIndex = Os_SchTblCBTable[SchId].OsSchTblNextEP;


        /* check and move to next ep */
        /* last EP is not user EP, it is OS internal EP, to handle the schtbl end event*/
        if(epIndex == (schCfgPtr->EpNum - (Os_uint8)1))/*last ep?*/
        {
            if(Os_SchTblCBTable[SchId].toTable != OS_INVALID_SCHTBL)
            {
                /*has next sch table, stop current sch table, start next table */
                toSchId = Os_SchTblCBTable[SchId].toTable;

                /*stop this table */
                Os_SchTblCBTable[SchId].OsSchTblState = SCHEDULETABLE_STOPPED;
                Os_SchTblCBTable[SchId].OsSchTblNextEP = OS_SCHTBL_START;
                Os_SchTblCBTable[SchId].fromTable = OS_INVALID_SCHTBL;
                Os_SchTblCBTable[SchId].toTable = OS_INVALID_SCHTBL;
                Os_SchTblCBTable[SchId].timeVal = (TickType)0;


                /* start next table */
                Os_SchTblCBTable[toSchId].fromTable = OS_INVALID_SCHTBL;/*clear from table*/
                (void)OsSchTbl_InternalStartRel(CoreID, toSchId, (TickType)0, OS_TRUE);

            }
            else if(OS_TRUE == schCfgPtr->isRepeat)
            {
                /* repeat sch table, restart it. */
                (void)OsSchTbl_InternalStartRel(CoreID, SchId, (TickType)0, OS_TRUE);
            }
            else
            {
                /* no next, no repeat, just stop this table */
                Os_SchTblCBTable[SchId].OsSchTblState = SCHEDULETABLE_STOPPED;
                Os_SchTblCBTable[SchId].OsSchTblNextEP = OS_SCHTBL_START;
                Os_SchTblCBTable[SchId].fromTable = OS_INVALID_SCHTBL;
                Os_SchTblCBTable[SchId].toTable = OS_INVALID_SCHTBL;
                Os_SchTblCBTable[SchId].timeVal = (TickType)0;
            }
        }
        else
        {
            if(Os_SchTblCBTable[SchId].OsSchTblNextEP == OS_SCHTBL_START)
            {
                /*The schedule table starts to run, the next EP is 0*/
                Os_SchTblCBTable[SchId].OsSchTblNextEP = (Os_uint8)0;
            }
            else
            {
                /* not last ep, move to next ep and inset new element to tree */
                /*PRQA S 3383 ++*/
                /* "epIndex" before confirms that overflow will not happen. */
                Os_SchTblCBTable[SchId].OsSchTblNextEP++;
                /*PRQA S 3383 --*/
            }
            nextEpIndex = Os_SchTblCBTable[SchId].OsSchTblNextEP;

            /* here must use maxCntVal - CntValue  as  CntValue + cycle may exceed*/
            /*PRQA S 3383,3384 ++*/
            /* The "if..." here confirms that overflow/underflow will not happen. */
            if((maxCntVal - Os_CounterTick[CounterID]) < schCfgPtr->epList[nextEpIndex].OsEpOffset)
            {
                Os_SchTblCBTable[SchId].timeVal = (schCfgPtr->epList[nextEpIndex].OsEpOffset - (maxCntVal - Os_CounterTick[CounterID]) - (TickType)1);
                
            }
            else
            {
                Os_SchTblCBTable[SchId].timeVal += schCfgPtr->epList[nextEpIndex].OsEpOffset;
            }
            /*PRQA S 3383,3384 --*/
            OsCnt_TreeInsert(CoreID, CounterID, (Os_uint32)SchId, OS_FALSE);
        }

        if(epIndex != OS_SCHTBL_START)
        {
            /* Carry out the all ep operations */
            for(epActIndex = (Os_uint8)0; epActIndex < schCfgPtr->epList[epIndex].EpActionNum; epActIndex++)
            {
                epActCfgPtr = &(schCfgPtr->epList[epIndex].epActionList[epActIndex]);
                switch (epActCfgPtr->EpAction)
                {
                case OS_EP_TASK:
#if(OS_USED_CORE_NUMBER > 1)
                    /* Check whether crosscore opration*/
                    if (CoreID != Os_TaskCfg[epActCfgPtr->TaskID].objCoreId)
                    {
                        (void)OsMultiCore_TriggerActivateTask(CoreID, epActCfgPtr->TaskID);
                    }
                    else
#endif /*(OS_USED_CORE_NUMBER > 1)*/
                    {
                        /* can not call ActivateTask API here, as too much err check may waste time,
                        * and also in ActivateTask, this will be OsCpu_ExitCritical
                        *  */
                        (void)OsTask_InternalActivateTask(CoreID, epActCfgPtr->TaskID, OS_FALSE, OSServiceId_ActivateTask);
                    }

                    break;

#if(OS_SCHTBL_SETEVENT_NUMBER > 0)
                case OS_EP_EVENT:
#if(OS_USED_CORE_NUMBER > 1)
                    /* Check whether crosscore opration*/
                    if (CoreID != Os_TaskCfg[epActCfgPtr->TaskID].objCoreId)
                    {
                        (void)OsMultiCore_TriggerSetEvent(CoreID, epActCfgPtr->TaskID, epActCfgPtr->Event);
                    }
                    else
#endif /*(OS_USED_CORE_NUMBER > 1)*/
                    {
                        (void)OsEvent_InternalSetEvent(CoreID, epActCfgPtr->TaskID, epActCfgPtr->Event);
                    }
                    break;
#endif /*(OS_SCHTBL_SETEVENT_NUMBER > 0)*/

                default:
                    /*should never enter this branch*/
                    break;
                }
            }
        }/*if(epIndex != OS_SCHTBL_START)*/

    }
    return isExpire;
}

/* BEGIN_FUNCTION_HDR
***********************************************************************************************
* Function Name: OsSchTbl_Init
*
* Description:   called in start OS, init schedule table module
*
* Inputs:        None
*
* Outputs:       None
*
* Limitations:   None
***********************************************************************************************
END_FUNCTION_HDR*/
FUNC(void, OS_CODE) OsSchTbl_Init
(
    CoreIdType CoreID
)
{
    ScheduleTableType i;
    ScheduleTableType endSchId;

    endSchId = Os_CoreCfg[CoreID].startSchId + Os_CoreCfg[CoreID].schNum;
    /* Alarm must sort, auto alarms first*/
    for(i = Os_CoreCfg[CoreID].startSchId; i < endSchId; i++)
    {
        Os_SchTblCBTable[i].OsSchTblState = SCHEDULETABLE_STOPPED;
        Os_SchTblCBTable[i].fromTable = OS_INVALID_SCHTBL;
        Os_SchTblCBTable[i].toTable = OS_INVALID_SCHTBL;
        Os_SchTblCBTable[i].timeVal = (TickType)0;
        Os_SchTblCBTable[i].OsSchTblNextEP = OS_SCHTBL_START;

#if(OS_APPLICATION_NUMBER > 0)
        Os_SchTblCBTable[i].isKilled = OS_FALSE;
#endif /*(OS_APPLICATION_NUMBER > 0)*/
    }
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: OsSchTbl_AutoStart
*
* Description:   Call in startOS, active all auto start table of this core
*
* Inputs:        CoreID
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
#if(OS_AUTO_SCHTBL_NUMBER > 0)
FUNC(void, OS_CODE) OsSchTbl_AutoStart
(
    CoreIdType CoreID
)
{
    ScheduleTableType i;
    ScheduleTableType endSchId = Os_CoreCfg[CoreID].startSchId + Os_CoreCfg[CoreID].schNum;

    /* Sch must sort, auto sch first*/
    for(i = Os_CoreCfg[CoreID].startSchId; i < endSchId; i++)
    {
        if(OS_TRUE == Os_SchTblCfg[i].isAutoStart)
        {
#if(OS_APPMODE_NUMBER > 1)
            if((Os_AppModeMaskType)0 != (Os_ActiveAppMode[CoreID] & Os_SchTblCfg[i].appModeMask))
#endif /*(OS_APPMODE_NUMBER > 1)*/
            {
                if(OS_TRUE == Os_SchTblCfg[i].isAbsSchTbl)
                {
                    (void)OsSchTbl_InternalStartAbs(CoreID, i, Os_SchTblCfg[i].startTimeValue);
                }
                else
                {
                    /* code */
                    (void)OsSchTbl_InternalStartRel(CoreID, i, Os_SchTblCfg[i].startTimeValue, OS_FALSE);

                }
            }
        }
    }
}
#endif /*(OS_AUTO_SCHTBL_NUMBER > 0)*/

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: OsSchTbl_Kill
*
* Description:   Call in TerminateApplication, set sch in-active and delete it from tree
*
* Inputs:        CoreID,SchId
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
#if(OS_APPLICATION_NUMBER > 0)
FUNC(void, OS_CODE) OsSchTbl_Kill
(
    CoreIdType CoreID,
    ScheduleTableType SchId
)
{
    /* Schedule table already killed, do nothing*/
    if(Os_SchTblCBTable[SchId].isKilled == OS_TRUE)
    {
        return;
    }


    /* Schedule table is alive, should be stopped*/
    if(Os_SchTblCBTable[SchId].OsSchTblState != SCHEDULETABLE_STOPPED)
    {
        /*if sch running , delete it from tree*/
        (void)OsSchTbl_InternalStop(CoreID, SchId);
    }

    Os_SchTblCBTable[SchId].isKilled = OS_TRUE;

}
#endif /*(OS_APPLICATION_NUMBER > 0)*/

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: OsSchTbl_InternalStartAbs
*
* Description:   Internal start Abs sch table, called by sch and crosscore startSchTable
*
* Inputs:        CoreID,ScheduleTableID,start
*
* Outputs:       StatusType
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(StatusType, OS_CODE) OsSchTbl_InternalStartAbs
(
    CoreIdType CoreID,
    ScheduleTableType ScheduleTableID,
    TickType start
)
{
    CounterType CounterID = Os_SchTblCfg[ScheduleTableID].refCounter;
    P2CONST(Os_CounterCfgType, AUTOMATIC, OS_CONST) cntCfgPtr = &Os_CounterCfg[CounterID];

    TickType firstExpireTime;


    /* following checks not include by OS_STATUS_LEVEL
     * as these errors are runtime errors
     * */
    /*
     * check if sch table is killed,  can be killed only when teminateApplication called
     * */
#if(OS_APPLICATION_NUMBER > 0)
    if(Os_SchTblCBTable[ScheduleTableID].isKilled == OS_TRUE)
    {
        OsHook_ReportErrorDisInt (CoreID, E_OS_ACCESS, OSServiceId_OsSchTbl_InternalStartAbs, OS_IE_OBJECT_KILLED, (Os_uint32)ScheduleTableID, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR);
        return E_OS_ACCESS;    /* the schedule table has been killed */
    }
#endif /*(OS_APPLICATION_NUMBER > 0)*/

    /* check if sch table is alive, alive sch table can not be set again SWS_Os_00350*/
    if(Os_SchTblCBTable[ScheduleTableID].OsSchTblState != SCHEDULETABLE_STOPPED)
    {
        OsHook_ReportErrorDisInt (CoreID, E_OS_STATE, OSServiceId_OsSchTbl_InternalStartAbs, OS_IE_SCHTBL_ALREADY_ALIVE, (Os_uint32)ScheduleTableID, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR);
        return E_OS_STATE;
    }

    if((TickType)0 == Os_SchTblCfg[ScheduleTableID].epList[0].OsEpOffset)
    {
        Os_SchTblCBTable[ScheduleTableID].OsSchTblNextEP = (Os_uint8)0;
    }
    else
    {
        Os_SchTblCBTable[ScheduleTableID].OsSchTblNextEP = OS_SCHTBL_START;
    }

    /* Calculate the first expire time*/
    if(Os_CounterTick[CounterID] == start)
    {
        if(start == cntCfgPtr->alarmBase.maxallowedvalue)
        {
            firstExpireTime = (TickType)0;
        }
        else
        {
            /*PRQA S 3383 ++*/
            /* The "if..." confirms that "start+1" will not overflow. */
            firstExpireTime = start + (TickType)1;
            /*PRQA S 3383 --*/
        }
    }
    else
    {
        firstExpireTime = start;
    }

    Os_SchTblCBTable[ScheduleTableID].timeVal = firstExpireTime;
    Os_SchTblCBTable[ScheduleTableID].OsSchTblState = SCHEDULETABLE_RUNNING;/* Set the State of schTable. */
    OsCnt_TreeInsert(CoreID, CounterID, (Os_uint32)ScheduleTableID, OS_FALSE); /* Insert the activated sch table to the ready queue. */

    return E_OS_OK;
}


/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: OsSchTbl_InternalStartRel
*
* Description:   Internal start Rel sch table, called by sch and crosscore startSchTable
*
* Inputs:        CoreID,ScheduleTableID,offset, internalStart
                 only when call this api in OsSchTbl_Trigger, internalStart = true,  means that:
                 (1) repeat sch table restarted
                 (2) next sch table started when last table end
*
* Outputs:       StatusType
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(StatusType, OS_CODE) OsSchTbl_InternalStartRel
(
    CoreIdType CoreID,
    ScheduleTableType ScheduleTableID,
    TickType offset,
    Os_boolean internalStart
)
{
    CounterType CounterID = Os_SchTblCfg[ScheduleTableID].refCounter;
    P2CONST(Os_CounterCfgType, AUTOMATIC, OS_CONST) cntCfgPtr = &Os_CounterCfg[CounterID];

    TickType firstExpireTime;
    StatusType ret = E_OS_OK;

    /* following checks not include by OS_STATUS_LEVEL
     * as these errors are runtime errors
     * */
    /*
     * check if sch table is killed,  can be killed only when teminateApplication called
     * */
#if(OS_APPLICATION_NUMBER > 0)
    if(Os_SchTblCBTable[ScheduleTableID].isKilled == OS_TRUE)
    {
        OsHook_ReportErrorDisInt(CoreID, E_OS_ACCESS, OSServiceId_OsSchTbl_InternalStartRel, OS_IE_OBJECT_KILLED, (Os_uint32)ScheduleTableID, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR);
        ret = E_OS_ACCESS;    /* the schedule table has been killed */
    }
    else
#endif /*(OS_APPLICATION_NUMBER > 0)*/

    /* check if sch table is alive, alive sch table can not be set again SWS_Os_0277*/
    if((OS_FALSE == internalStart) \
        && (Os_SchTblCBTable[ScheduleTableID].OsSchTblState != SCHEDULETABLE_STOPPED))
    {
        OsHook_ReportErrorDisInt(CoreID, E_OS_STATE, OSServiceId_OsSchTbl_InternalStartRel, OS_IE_SCHTBL_ALREADY_ALIVE, (Os_uint32)ScheduleTableID, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR);
        ret = E_OS_STATE;
    }
    else
    {

        if((TickType)0 == Os_SchTblCfg[ScheduleTableID].epList[0].OsEpOffset)
        {
            Os_SchTblCBTable[ScheduleTableID].OsSchTblNextEP = (Os_uint8)0;
        }
        else
        {
            Os_SchTblCBTable[ScheduleTableID].OsSchTblNextEP = OS_SCHTBL_START;
        }

        /* caculate the first expire time, start + offset
        if overflow, no problem
        */
        /*PRQA S 3383 ++*/
        /* Overflow is useful here. */
        firstExpireTime = Os_CounterTick[CounterID] + offset;
        /*PRQA S 3383 --*/

        if(firstExpireTime > cntCfgPtr->alarmBase.maxallowedvalue)
        {
            /*PRQA S 3383,3384 ++*/
            /* "if..." confirm that underflow will not happen here. */
            firstExpireTime = firstExpireTime - cntCfgPtr->alarmBase.maxallowedvalue - (TickType)1;
            /*PRQA S 3383,3384 --*/
        }
        /*
        * if offset is 0 and internalStart is TRUE, take the last EP as the start of next ScheduleTable, 
        * Use OsCnt_TreeInsert set OsCnt_TreeHead, next priod check, then update new EP time.
        */

        Os_SchTblCBTable[ScheduleTableID].timeVal = firstExpireTime;
        Os_SchTblCBTable[ScheduleTableID].OsSchTblState = SCHEDULETABLE_RUNNING;/* Set the State of schTable. */
        OsCnt_TreeInsert(CoreID, CounterID, (Os_uint32)ScheduleTableID, OS_FALSE); /* Insert the activated sch table to the ready queue. */
    }
    return ret;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: OsSchTbl_InternalNext
*
* Description:   Internal next sch table, called by sch and crosscore nextSchTable
*
* Inputs:        CoreID,ScheduleTableID_From,ScheduleTableID_To
*
* Outputs:       StatusType
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(StatusType, OS_CODE) OsSchTbl_InternalNext
(
    CoreIdType CoreID,
    ScheduleTableType ScheduleTableID_From,
    ScheduleTableType ScheduleTableID_To
)
{
    ScheduleTableType tempTbl;

    /* following checks not include by OS_STATUS_LEVEL
     * as these errors are runtime errors
     * */
    /*
     * check if sch table is killed,  can be killed only when teminateApplication called
     * */
    (void)CoreID;

#if(OS_APPLICATION_NUMBER > 0)
    if((Os_SchTblCBTable[ScheduleTableID_From].isKilled == OS_TRUE) || (Os_SchTblCBTable[ScheduleTableID_To].isKilled == OS_TRUE))
    {
        OsHook_ReportErrorDisInt (CoreID, E_OS_ACCESS, OSServiceId_OsSchTbl_InternalNext, OS_IE_OBJECT_KILLED, (Os_uint32)ScheduleTableID_From, (Os_uint32)ScheduleTableID_To, OS_IE_NO_ERRPAR);
        return E_OS_ACCESS;    /* the table has been killed */
    }
#endif /*(OS_APPLICATION_NUMBER > 0)*/

    /* SWS_Os_00324 change old next to stop*/
    tempTbl = Os_SchTblCBTable[ScheduleTableID_From].toTable;
    if(tempTbl != OS_INVALID_SCHTBL)
    {
        Os_SchTblCBTable[tempTbl].fromTable = OS_INVALID_SCHTBL;
        Os_SchTblCBTable[tempTbl].OsSchTblState = SCHEDULETABLE_STOPPED;
    }

    Os_SchTblCBTable[ScheduleTableID_From].toTable = ScheduleTableID_To;
    Os_SchTblCBTable[ScheduleTableID_To].fromTable = ScheduleTableID_From;
    /*Set the state of schedule table to NEXT*/
    Os_SchTblCBTable[ScheduleTableID_To].OsSchTblState = SCHEDULETABLE_NEXT;

    return E_OS_OK;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: OsSchTbl_InternalStop
*
* Description:   Internal stop sch table, called by sch and crosscore stop
*
* Inputs:        CoreID,ScheduleTableID
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(StatusType, OS_CODE) OsSchTbl_InternalStop
(
    CoreIdType CoreID,
    ScheduleTableType ScheduleTableID
)
{
    CounterType CounterID = Os_SchTblCfg[ScheduleTableID].refCounter;
    ScheduleTableType fromTbl;
    ScheduleTableType toTbl;

#if(OS_SYSTICK_MODE == OS_HRT_MODE)
    Os_CounterTick[CounterID] = OsSysTimer_UpdateCounter(CoreID, CounterID);
#endif/* (OS_SYSTICK_MODE == OS_HRT_MODE) */

    /* following checks not include by OS_STATUS_LEVEL
     * as these errors are runtime errors
     * */
    /*
     * check if schedule table is killed, schedule table can be killed only when teminateApplication called
     * */
#if(OS_APPLICATION_NUMBER > 0)
    if(Os_SchTblCBTable[ScheduleTableID].isKilled == OS_TRUE)
    {
        OsHook_ReportErrorDisInt (CoreID, E_OS_ACCESS, OSServiceId_OsSchTbl_InternalStop, OS_IE_OBJECT_KILLED, (Os_uint32)ScheduleTableID, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR);
        return E_OS_ACCESS;    /* the schedule table has been killed */
    }
#endif /*(OS_APPLICATION_NUMBER > 0)*/

    if(Os_SchTblCBTable[ScheduleTableID].OsSchTblState == SCHEDULETABLE_RUNNING)
    {
        OsCnt_DelTreeElement(CoreID, CounterID, (Os_uint32)ScheduleTableID, OS_FALSE); /*remove the current table. */
        toTbl = Os_SchTblCBTable[ScheduleTableID].toTable;

        if(toTbl != OS_INVALID_SCHTBL)
        {
            /* reset to table*/
            Os_SchTblCBTable[toTbl].OsSchTblState = SCHEDULETABLE_STOPPED; 
            Os_SchTblCBTable[toTbl].OsSchTblNextEP = OS_SCHTBL_START;
            Os_SchTblCBTable[toTbl].fromTable = OS_INVALID_SCHTBL;
            Os_SchTblCBTable[toTbl].toTable = OS_INVALID_SCHTBL;
            Os_SchTblCBTable[toTbl].timeVal = (TickType)0;
        }

    }
    else if(Os_SchTblCBTable[ScheduleTableID].OsSchTblState == SCHEDULETABLE_NEXT)
    {
        fromTbl = Os_SchTblCBTable[ScheduleTableID].fromTable;
        if(fromTbl != OS_INVALID_SCHTBL)
        {
            Os_SchTblCBTable[fromTbl].toTable = OS_INVALID_SCHTBL;
        }
    }
    else
    {
        /*waiting or SCHEDULETABLE_RUNNING_AND_SYNCHRONOUS state, not support yet*/
    }
    
    /* reset current table*/
    Os_SchTblCBTable[ScheduleTableID].OsSchTblState = SCHEDULETABLE_STOPPED; 
    Os_SchTblCBTable[ScheduleTableID].OsSchTblNextEP = OS_SCHTBL_START;
    Os_SchTblCBTable[ScheduleTableID].fromTable = OS_INVALID_SCHTBL;
    Os_SchTblCBTable[ScheduleTableID].toTable = OS_INVALID_SCHTBL;
    Os_SchTblCBTable[ScheduleTableID].timeVal = (TickType)0;

    return E_OS_OK;
}


/*****************************************************************************
* API code
******************************************************************************/
/* BEGIN_FUNCTION_HDR
***********************************************************************************************
* Function Name: Os_GetScheduleTableStatus
*
* Description:   API function called by Application.Return the status of the schedule table.
*                [OS227]
* Inputs:        <ScheduleTableID>  Schedule table for which status is requested.
*
* Outputs:       <ScheduleStatus> Reference to ScheduleTableStatusType.
*
* Limitations:   None
***********************************************************************************************
END_FUNCTION_HDR*/
FUNC(StatusType, OS_CODE) Os_GetScheduleTableStatus
(
    ScheduleTableType ScheduleTableID,
    ScheduleTableStatusRefType ScheduleStatus
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
    
    else if((Os_uint16)(Os_CurrentContext[CoreID] & Os_GetScheduleTableStatusMask) == (Os_uint16)0)
    {
        OsHook_ReportError(CoreID, E_OS_CALLEVEL, OSServiceId_GetScheduleTableStatus, OS_IE_NOMORE_INFO, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR);
        ret = E_OS_CALLEVEL;
    }

    /* Check the validity of Value:Value cannot be NULL */
    else if(NULL_PTR == ScheduleStatus)
    {
        OsHook_ReportError(CoreID, E_OS_PARAM_POINTER, OSServiceId_GetScheduleTableStatus, OS_IE_NOMORE_INFO, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR);
        ret = E_OS_PARAM_POINTER;
    }

    /* Check whether this API is called between interrupt processing APIs*/
    else if(OS_NO_API_USED != Os_IntAPIUsedFlag[CoreID])
    {
        /* System error -- this API is called between interrupt processing function pairs */
        OsHook_ReportError(CoreID, E_OS_DISABLEDINT, OSServiceId_GetScheduleTableStatus, OS_IE_NOMORE_INFO, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR);
        ret = E_OS_DISABLEDINT;
    }

    /* Check TaskID valid or not*/
    else if(ScheduleTableID >= (ScheduleTableType)OS_SCHTBL_NUMBER)
    {
        OsHook_ReportError(CoreID, E_OS_ID, OSServiceId_GetScheduleTableStatus, OS_IE_SCHTBL_ID, (Os_uint32)ScheduleTableID, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR);
        ret = E_OS_ID;
    }

#if(OS_USED_CORE_NUMBER > 1)
    /* Not support cross-core yet*/
    /* Check whether this API is called from different core*/
    else if(CoreID != Os_SchTblCfg[ScheduleTableID].objCoreId)
    {
        OsHook_ReportError(CoreID, E_OS_SYS_SERVICE_NOTSUPPORT_CROSSCORE, OSServiceId_GetScheduleTableStatus, OS_IE_NOMORE_INFO, (Os_uint32)ScheduleTableID, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR);
        ret = E_OS_SYS_SERVICE_NOTSUPPORT_CROSSCORE;
    }
#endif /*(OS_USED_CORE_NUMBER > 1)*/


#if(OS_APPLICATION_NUMBER > 0)
    /*  current application invalid, should not has this case*/
    else if(Os_CurrentApplicationId[CoreID] == OS_INVALID_OSAPPLICATION)
    {
        OsHook_ReportError(CoreID, E_OS_ACCESS, OSServiceId_GetScheduleTableStatus, OS_IE_INVALID_OSAPPICATION, (Os_uint32)Os_CurrentApplicationId[CoreID], OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR);
        ret = E_OS_ACCESS;
    }

    /* has no access right from current application*/
    else if((Os_ApplicationMaskType)0 == ((((Os_ApplicationMaskType)1) << Os_CurrentApplicationId[CoreID]) & ((Os_SchTblCfg[ScheduleTableID].AppMask))))
    {
        OsHook_ReportError(CoreID, E_OS_ACCESS, OSServiceId_GetScheduleTableStatus, OS_IE_NO_ACCESS_RIGHT, (Os_uint32)Os_CurrentApplicationId[CoreID], (Os_uint32)ScheduleTableID, OS_IE_NO_ERRPAR);
        ret = E_OS_ACCESS;
    }
#endif /*(OS_APPLICATION_NUMBER > 0)*/
    else
#endif /*(OS_STATUS_LEVEL == OS_EXTENDED)*/
    {
        /* no need to check killed or not, when killed, this API will return stop */

        /* Enter critical section */
        /* must disable int of current core first, to avoid calling spinlock at same core*/
        OsCpu_EnterCritical(CoreID, &tempPri);

        *ScheduleStatus = Os_SchTblCBTable[ScheduleTableID].OsSchTblState;

        OsCpu_ExitCritical(CoreID, tempPri);
    }
    
    return ret;
}/*end of Os_GetScheduleTableStatus*/


/* BEGIN_FUNCTION_HDR
***********************************************************************************************
* Function Name: Os_StartScheduleTableAbs
*
* Description:   API function called by Application.This call serves to start a schedule table.
*                [OS358]
* Inputs:        <ScheduleTableID>  Schedule table to be started.
*                <Start> Absolute counter tick value at which the schedule table is started
*
* Outputs:       None
*
* Limitations:   None
***********************************************************************************************
END_FUNCTION_HDR*/
FUNC(StatusType, OS_CODE) Os_StartScheduleTableAbs
(
    ScheduleTableType ScheduleTableID,
    TickType Start
)
{
    CoreIdType CoreID;
    P2CONST(Os_CounterCfgType, AUTOMATIC, OS_CONST) cntCfgPtr;
    Os_boolean tempPri;
    CounterType CounterID;
    StatusType ret = E_OS_OK;

    CoreID = OsCpu_GetCoreID();
    CounterID = Os_SchTblCfg[ScheduleTableID].refCounter;
    cntCfgPtr = &Os_CounterCfg[CounterID];

#if(OS_SYSTICK_MODE == OS_HRT_MODE)
    Os_CounterTick[CounterID] = OsSysTimer_UpdateCounter(CoreID, CounterID);
#endif/* (OS_SYSTICK_MODE == OS_HRT_MODE) */

#if(OS_STATUS_LEVEL == OS_EXTENDED)
    if((CoreID >= (CoreIdType)OS_USED_CORE_NUMBER) || (Os_CoreState[CoreID] != OS_CORE_START))
    {
        /* can not record err in this state, as OS services can not be called*/
        ret = E_OS_CORE;
    }
    
    else if((Os_uint16)(Os_CurrentContext[CoreID] & Os_StartScheduleTableAbsMask) == (Os_uint16)0)
    {
        OsHook_ReportError(CoreID, E_OS_CALLEVEL, OSServiceId_StartScheduleTableAbs, OS_IE_NOMORE_INFO, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR);
        ret = E_OS_CALLEVEL;
    }
   
    /* Check whether this API is called between interrupt processing APIs*/
    else if(OS_NO_API_USED != Os_IntAPIUsedFlag[CoreID])
    {
        /* System error -- this API is called between interrupt processing function pairs */
        OsHook_ReportError(CoreID, E_OS_DISABLEDINT, OSServiceId_StartScheduleTableAbs, OS_IE_NOMORE_INFO, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR);
        ret = E_OS_DISABLEDINT;
    }

    /* Check TaskID valid or not*/
    else if(ScheduleTableID >= (ScheduleTableType)OS_SCHTBL_NUMBER)
    {
        OsHook_ReportError(CoreID, E_OS_ID, OSServiceId_StartScheduleTableAbs, OS_IE_SCHTBL_ID, (Os_uint32)ScheduleTableID, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR);
        ret = E_OS_ID;
    }

#if(OS_USED_CORE_NUMBER > 1)
    /* Not support cross-core yet*/
    /* Check whether this API is called from diifferent core*/
    else if(CoreID != Os_SchTblCfg[ScheduleTableID].objCoreId)
    {
        OsHook_ReportError(CoreID, E_OS_SYS_SERVICE_NOTSUPPORT_CROSSCORE, OSServiceId_StartScheduleTableAbs, OS_IE_NOMORE_INFO, (Os_uint32)ScheduleTableID, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR);
        ret = E_OS_SYS_SERVICE_NOTSUPPORT_CROSSCORE;
    }
#endif /*(OS_USED_CORE_NUMBER > 1)*/

    else if(Start > cntCfgPtr->alarmBase.maxallowedvalue)
    {

        OsHook_ReportError(CoreID, E_OS_VALUE, OSServiceId_StartScheduleTableAbs, OS_IE_SCHTBL_START, Start, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR);
        ret = E_OS_VALUE;/*[OS349]*/
    }

#if(OS_APPLICATION_NUMBER > 0)
    /*  current application invalid, should not has this case*/
    else if(Os_CurrentApplicationId[CoreID] == OS_INVALID_OSAPPLICATION)
    {
        OsHook_ReportError(CoreID, E_OS_ACCESS, OSServiceId_StartScheduleTableAbs, OS_IE_INVALID_OSAPPICATION, (Os_uint32)Os_CurrentApplicationId[CoreID], OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR);
        ret = E_OS_ACCESS;
    }

    else if((Os_ApplicationMaskType)0 == ( (((Os_ApplicationMaskType)1) << Os_CurrentApplicationId[CoreID]) & (Os_SchTblCfg[ScheduleTableID].AppMask) ) )
    {
        OsHook_ReportError(CoreID, E_OS_ACCESS, OSServiceId_StartScheduleTableAbs, OS_IE_NO_ACCESS_RIGHT, (Os_uint32)Os_CurrentApplicationId[CoreID], (Os_uint32)ScheduleTableID, OS_IE_NO_ERRPAR);
        ret = E_OS_ACCESS;
    }

#endif /*(OS_APPLICATION_NUMBER > 0)*/
    else
#endif /*(OS_STATUS_LEVEL == OS_EXTENDED)*/
    {
        /* Enter critical section */
        /* must disable int of current core first, to avoid calling spinlock at same core*/
        OsCpu_EnterCritical(CoreID, &tempPri);

        ret = OsSchTbl_InternalStartAbs(CoreID, ScheduleTableID, Start);

        OsCpu_ExitCritical(CoreID, tempPri);
    }
    return ret;
}/*end of Os_StartScheduleTableAbs*/

/* BEGIN_FUNCTION_HDR
***********************************************************************************************
* Function Name: Os_StartScheduleTableRel
*
* Description:   API function called by Application.This call serves to start a schedule table.
*                [OS347]
* Inputs:        <ScheduleTableID>  Schedule table to be started.
*                <Offset> Number of ticks on the counter before the the schedule table processing is started
*
* Outputs:       None
*
* Limitations:   None
***********************************************************************************************
END_FUNCTION_HDR*/
FUNC(StatusType, OS_CODE) Os_StartScheduleTableRel
(
    ScheduleTableType ScheduleTableID,
    TickType Offset
)
{
    CoreIdType CoreID;
    P2CONST(Os_CounterCfgType, AUTOMATIC, OS_CONST) cntCfgPtr;
    Os_boolean tempPri;
    CounterType CounterID;
    StatusType ret = E_OS_OK;

    CoreID = OsCpu_GetCoreID();
    CounterID = Os_SchTblCfg[ScheduleTableID].refCounter;
    cntCfgPtr = &Os_CounterCfg[CounterID];

#if(OS_SYSTICK_MODE == OS_HRT_MODE)
    Os_CounterTick[CounterID] = OsSysTimer_UpdateCounter(CoreID, CounterID);
#endif/* (OS_SYSTICK_MODE == OS_HRT_MODE) */

#if(OS_STATUS_LEVEL == OS_EXTENDED)
    if((CoreID >= (CoreIdType)OS_USED_CORE_NUMBER) || (Os_CoreState[CoreID] != OS_CORE_START))
    {
        /* can not record err in this state, as OS services can not be called*/
        ret = E_OS_CORE;
    }
    
    else if((Os_uint16)(Os_CurrentContext[CoreID] & Os_StartScheduleTableRelMask) == (Os_uint16)0)
    {
        OsHook_ReportError(CoreID, E_OS_CALLEVEL, OSServiceId_StartScheduleTableRel, OS_IE_NOMORE_INFO, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR);
        ret = E_OS_CALLEVEL;
    }

    /* Check whether this API is called between interrupt processing APIs*/
    else if(OS_NO_API_USED != Os_IntAPIUsedFlag[CoreID])
    {
        /* System error -- this API is called between interrupt processing function pairs */
        OsHook_ReportError(CoreID, E_OS_DISABLEDINT, OSServiceId_StartScheduleTableRel, OS_IE_NOMORE_INFO, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR);
        ret = E_OS_DISABLEDINT;
    }

    /* Check TaskID valid or not*/
    else if(ScheduleTableID >= (ScheduleTableType)OS_SCHTBL_NUMBER)
    {
        OsHook_ReportError(CoreID, E_OS_ID, OSServiceId_StartScheduleTableRel, OS_IE_SCHTBL_ID, (Os_uint32)ScheduleTableID, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR);
        ret = E_OS_ID;
    }

#if(OS_USED_CORE_NUMBER > 1)
    /* Not support cross-core yet*/
    /* Check whether this API is called from diifferent core*/
    else if(CoreID != Os_SchTblCfg[ScheduleTableID].objCoreId)
    {
        OsHook_ReportError(CoreID, E_OS_SYS_SERVICE_NOTSUPPORT_CROSSCORE, OSServiceId_StartScheduleTableRel, OS_IE_NOMORE_INFO, \
            (Os_uint32)ScheduleTableID, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR);
        ret = E_OS_SYS_SERVICE_NOTSUPPORT_CROSSCORE;
    }
#endif /*(OS_USED_CORE_NUMBER > 1)*/

    else if((Offset == (TickType)0) || (Offset > cntCfgPtr->alarmBase.maxallowedvalue))
    {
        OsHook_ReportError(CoreID, E_OS_VALUE, OSServiceId_StartScheduleTableRel, OS_IE_SCHTBL_OFFSET, Offset, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR);
        ret = E_OS_VALUE;/*[OS332,OS276]*/
    }

#if(OS_APPLICATION_NUMBER > 0)
    /*  current application invalid, should not has this case*/
    else if(Os_CurrentApplicationId[CoreID] == OS_INVALID_OSAPPLICATION)
    {
        OsHook_ReportError(CoreID, E_OS_ACCESS, OSServiceId_StartScheduleTableRel, OS_IE_INVALID_OSAPPICATION, (Os_uint32)Os_CurrentApplicationId[CoreID], OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR);
        ret = E_OS_ACCESS;
    }

    else if((Os_ApplicationMaskType)0 == ( (((Os_ApplicationMaskType)1) << Os_CurrentApplicationId[CoreID]) & (Os_SchTblCfg[ScheduleTableID].AppMask) ) )
    {
        OsHook_ReportError(CoreID, E_OS_ACCESS, OSServiceId_StartScheduleTableRel, OS_IE_NO_ACCESS_RIGHT, (Os_uint32)ScheduleTableID, (Os_uint32)Os_CurrentApplicationId[CoreID], OS_IE_NO_ERRPAR);
        ret = E_OS_ACCESS;
    }

#endif /*(OS_APPLICATION_NUMBER > 0)*/
    else
#endif /*(OS_STATUS_LEVEL == OS_EXTENDED)*/
    {
        /* Enter critical section */
        /* must disable int of current core first, to avoid calling spinlock at same core*/
        OsCpu_EnterCritical(CoreID, &tempPri);

        ret = OsSchTbl_InternalStartRel(CoreID, ScheduleTableID, Offset, OS_FALSE);

        OsCpu_ExitCritical(CoreID, tempPri);
    }
    return ret;
}

/* BEGIN_FUNCTION_HDR
***********************************************************************************************
* Function Name: Os_NextScheduleTable
*
* Description:   API function called by Application.This call serves to switch two schedule tables.
*
* Inputs:        <ScheduleTableID_From>  Currently processed schedule table.
*                <ScheduleTableID_To> Schedule table that provides its series of expiry points
*
* Outputs:       None
*
* Limitations:   None
***********************************************************************************************
END_FUNCTION_HDR*/
FUNC(StatusType, OS_CODE) Os_NextScheduleTable
(
    ScheduleTableType ScheduleTableID_From,
    ScheduleTableType ScheduleTableID_To
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
    
    else if((Os_uint16)(Os_CurrentContext[CoreID] & Os_NextScheduleTableMask) == (Os_uint16)0)
    {
        OsHook_ReportError(CoreID, E_OS_CALLEVEL, OSServiceId_NextScheduleTable, OS_IE_NOMORE_INFO, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR);
        ret = E_OS_CALLEVEL;
    }

    /* Check whether this API is called between interrupt processing APIs*/
    else if(OS_NO_API_USED != Os_IntAPIUsedFlag[CoreID])
    {
        /* System error -- this API is called between interrupt processing function pairs */
        OsHook_ReportError(CoreID, E_OS_DISABLEDINT, OSServiceId_NextScheduleTable, OS_IE_NOMORE_INFO, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR);
        ret = E_OS_DISABLEDINT;
    }

    /* Check schedule table valid or not*/
    else if((ScheduleTableID_From >= (ScheduleTableType)OS_SCHTBL_NUMBER) || (ScheduleTableID_To >= (ScheduleTableType)OS_SCHTBL_NUMBER))
    {
        OsHook_ReportError(CoreID, E_OS_ID, OSServiceId_NextScheduleTable, OS_IE_SCHTBL_ID, (Os_uint32)ScheduleTableID_From, (Os_uint32)ScheduleTableID_To, OS_IE_NO_ERRPAR);
        ret = E_OS_ID;
    }

    /*SWS_Os_00330*/
    else if(Os_SchTblCfg[ScheduleTableID_From].refCounter != Os_SchTblCfg[ScheduleTableID_To].refCounter)
    {
        OsHook_ReportError(CoreID, E_OS_ID, OSServiceId_NextScheduleTable, OS_IE_SCHTBL_ID, (Os_uint32)ScheduleTableID_From, (Os_uint32)ScheduleTableID_To, OS_IE_NO_ERRPAR);
        ret = E_OS_ID;
    }

    /*SWS_Os_00283*/
    else if((Os_SchTblCBTable[ScheduleTableID_From].OsSchTblState == SCHEDULETABLE_STOPPED) \
        || (Os_SchTblCBTable[ScheduleTableID_From].OsSchTblState == SCHEDULETABLE_NEXT))
    {
        OsHook_ReportError(CoreID, E_OS_NOFUNC, OSServiceId_NextScheduleTable, OS_IE_NOMORE_INFO, (Os_uint32)ScheduleTableID_From, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR);
        ret = E_OS_NOFUNC;
    }

    /*SWS_Os_00309*/
    else if(Os_SchTblCBTable[ScheduleTableID_To].OsSchTblState != SCHEDULETABLE_STOPPED)
    {
        OsHook_ReportError(CoreID, E_OS_STATE, OSServiceId_NextScheduleTable, OS_IE_NOMORE_INFO, (Os_uint32)ScheduleTableID_To, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR);
        ret = E_OS_STATE;
    }

#if(OS_USED_CORE_NUMBER > 1)
    /* Not support cross-core yet*/
    /* Check whether this API is called from different core*/
    else if((Os_SchTblCfg[ScheduleTableID_From].objCoreId != Os_SchTblCfg[ScheduleTableID_To].objCoreId) \
        || (CoreID != Os_SchTblCfg[ScheduleTableID_To].objCoreId))
    {
        OsHook_ReportError(CoreID, E_OS_SYS_SERVICE_NOTSUPPORT_CROSSCORE, OSServiceId_NextScheduleTable, OS_IE_NOMORE_INFO, (Os_uint32)ScheduleTableID_From, \
            (Os_uint32)ScheduleTableID_To, OS_IE_NO_ERRPAR);
        ret = E_OS_SYS_SERVICE_NOTSUPPORT_CROSSCORE;
    }
#endif /*(OS_USED_CORE_NUMBER > 1)*/

#if(OS_APPLICATION_NUMBER > 0)
    /*  current application invalid, should not has this case*/
    else if(Os_CurrentApplicationId[CoreID] == OS_INVALID_OSAPPLICATION)
    {
        OsHook_ReportError(CoreID, E_OS_ACCESS, OSServiceId_NextScheduleTable, OS_IE_INVALID_OSAPPICATION, (Os_uint32)Os_CurrentApplicationId[CoreID], OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR);
        ret = E_OS_ACCESS;
    }


    /* current application must has access right for both schedule table*/
    else if(((Os_ApplicationMaskType)0 == ( (((Os_ApplicationMaskType)1) << Os_CurrentApplicationId[CoreID]) & (Os_SchTblCfg[ScheduleTableID_From].AppMask) ) ) \
        || ((Os_ApplicationMaskType)0 == ( (((Os_ApplicationMaskType)1) << Os_CurrentApplicationId[CoreID]) & (Os_SchTblCfg[ScheduleTableID_To].AppMask) ) ))
    {
        OsHook_ReportError(CoreID, E_OS_ACCESS, OSServiceId_NextScheduleTable, OS_IE_NO_ACCESS_RIGHT, (Os_uint32)Os_CurrentApplicationId[CoreID], \
            (Os_uint32)ScheduleTableID_From, (Os_uint32)ScheduleTableID_To);
        ret = E_OS_ACCESS;
    }

#endif /*(OS_APPLICATION_NUMBER > 0)*/
    else
#endif /*(OS_STATUS_LEVEL == OS_EXTENDED)*/
    {
        /* Enter critical section */
        /* must disable int of current core first, to avoid calling spinlock at same core*/
        OsCpu_EnterCritical(CoreID, &tempPri);

        ret = OsSchTbl_InternalNext(CoreID, ScheduleTableID_From, ScheduleTableID_To);

        OsCpu_ExitCritical(CoreID, tempPri);
    }
    return ret;
}

/* BEGIN_FUNCTION_HDR
***********************************************************************************************
* Function Name: Os_StopScheduleTable
*
* Description:   API function called by Application.This call serves to stop one schedule table.
*                [OS006]
* Inputs:        <ScheduleTableID>  Schedule table to be stopped.
*
* Outputs:       None
*
* Limitations:   None
***********************************************************************************************
END_FUNCTION_HDR*/
FUNC(StatusType, OS_CODE) Os_StopScheduleTable
(
    ScheduleTableType ScheduleTableID
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
    
    else if((Os_uint16)(Os_CurrentContext[CoreID] & Os_StopScheduleTableMask) == (Os_uint16)0)
    {
        OsHook_ReportError(CoreID, E_OS_CALLEVEL, OSServiceId_StopScheduleTable, OS_IE_NOMORE_INFO, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR);
        ret = E_OS_CALLEVEL;
    }

    /* Check whether this API is called between interrupt processing APIs*/
    else if(OS_NO_API_USED != Os_IntAPIUsedFlag[CoreID])
    {
        /* System error -- this API is called between interrupt processing function pairs */
        OsHook_ReportError(CoreID, E_OS_DISABLEDINT, OSServiceId_StopScheduleTable, OS_IE_NOMORE_INFO, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR);
        ret = E_OS_DISABLEDINT;
    }

    /* Check TaskID valid or not*/
    else if(ScheduleTableID >= (ScheduleTableType)OS_SCHTBL_NUMBER)
    {
        OsHook_ReportError(CoreID, E_OS_ID, OSServiceId_StopScheduleTable, OS_IE_SCHTBL_ID, (Os_uint32)ScheduleTableID, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR);
        ret = E_OS_ID;
    }

    /*SWS_Os_00280*/
    else if(Os_SchTblCBTable[ScheduleTableID].OsSchTblState == SCHEDULETABLE_STOPPED)
    {
        OsHook_ReportError(CoreID, E_OS_NOFUNC, OSServiceId_StopScheduleTable, OS_IE_NOMORE_INFO, (Os_uint32)ScheduleTableID, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR);
        ret = E_OS_NOFUNC;
    }

#if(OS_USED_CORE_NUMBER > 1)
    /* Not support cross-core yet*/
    /* Check whether this API is called from different core*/
    else if(CoreID != Os_SchTblCfg[ScheduleTableID].objCoreId)
    {
        OsHook_ReportError(CoreID, E_OS_SYS_SERVICE_NOTSUPPORT_CROSSCORE, OSServiceId_StopScheduleTable, OS_IE_NOMORE_INFO, (Os_uint32)ScheduleTableID, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR);
        ret = E_OS_SYS_SERVICE_NOTSUPPORT_CROSSCORE;
    }
#endif /*(OS_USED_CORE_NUMBER > 1)*/

#if(OS_APPLICATION_NUMBER > 0)
    /*  current application invalid, should not has this case*/
    else if(Os_CurrentApplicationId[CoreID] == OS_INVALID_OSAPPLICATION)
    {
        OsHook_ReportError(CoreID, E_OS_ACCESS, OSServiceId_StopScheduleTable, OS_IE_INVALID_OSAPPICATION, (Os_uint32)Os_CurrentApplicationId[CoreID], OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR);
        ret = E_OS_ACCESS;
    }


    /* current application must has access right for both schedule table*/
    else if((Os_ApplicationMaskType)0 == ( (((Os_ApplicationMaskType)1) << Os_CurrentApplicationId[CoreID]) & (Os_SchTblCfg[ScheduleTableID].AppMask) ) )
    {
        OsHook_ReportError(CoreID, E_OS_ACCESS, OSServiceId_StopScheduleTable, OS_IE_NO_ACCESS_RIGHT, (Os_uint32)Os_CurrentApplicationId[CoreID], (Os_uint32)ScheduleTableID, OS_IE_NO_ERRPAR);
        ret = E_OS_ACCESS;
    }

#endif /*(OS_APPLICATION_NUMBER > 0)*/
    else
#endif /*(OS_STATUS_LEVEL == OS_EXTENDED)*/
    {
        /* Enter critical section */
        /* must disable int of current core first, to avoid calling spinlock at same core*/
        OsCpu_EnterCritical(CoreID, &tempPri);

        ret = OsSchTbl_InternalStop(CoreID, ScheduleTableID);

        OsCpu_ExitCritical(CoreID, tempPri);
    }
    return ret;
}


#define OS_STOP_SEC_CODE
#include "Os_MemMap.h"


#endif /*(OS_SCHTBL_NUMBER > 0)*/
