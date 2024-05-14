/*  BEGIN_FILE_HDR
********************************************************************************
*   NOTICE
*   This software is the property of HiRain Technologies. Any information
*   contained in this doc should not be reproduced, or used, or disclosed
*   without the written authorization from HiRain Technologies.
********************************************************************************
* File Name:       Os_Cnt.c
********************************************************************************
* Project/Product: AUTOSAR OS PROJECT
* Title:           Os_Cnt.c
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

/*PRQA S 3119 EOF*/
/*
Some parameters will not be used in different configurations and hardware 
platforms, but they can not be deleted according to the requirements of 
AUTOSAR specification or compatibility. So we retain these parameters for 
compatibility and convert them with (void) to clean the warnings in compiler.
PRQA notices such statements as warning 3119, it has been suppressed here.
*/

/*****************************************************************************
* static variables define
******************************************************************************/
#define OS_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap.h"
#if(OS_ON == OS_CNT_TIMEPERBASE_GREAT1)
STATIC VAR(TickType, OS_VAR) OsCnt_PrivateCounterTick[OS_COUNTER_NUMBER];
#endif /*(OS_ON == OS_CNT_TIMEPERBASE_GREAT1)*/
STATIC VAR(Os_uint32, OS_VAR) OsCnt_TreeHead[OS_COUNTER_NUMBER];
#if(OS_SYSTICK_MODE == OS_HRT_MODE)
STATIC VAR(Os_uint32, OS_VAR) OsCnt_LastCounterTick[OS_COUNTER_NUMBER];
#endif/* (OS_SYSTICK_MODE == OS_HRT_MODE) */
#define OS_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap.h"

#define OS_START_SEC_CODE
#include "Os_MemMap.h"
/*****************************************************************************
* OS private code
******************************************************************************/
#if((OS_ALARM_NUMBER > 0) || (OS_SCHTBL_NUMBER > 0))
STATIC FUNC(Os_boolean, OS_CODE) OsCnt_Compare
(
    P2CONST(Os_CounterCfgType, AUTOMATIC, OS_CONST) cntCfgPtr,
    Os_uint32 NewEle,
    Os_uint32 OldEle,
    TickType CntVal
);

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: OsCnt_Compare
*
* Description:   A founction used to compare which alarm will expired first.
*
* Inputs:        cntCfgPtr,NewEle,OldEle,CntVal
*
* Outputs:       Os_boolean
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(Os_boolean, OS_CODE) OsCnt_Compare
(
    P2CONST(Os_CounterCfgType, AUTOMATIC, OS_CONST) cntCfgPtr,
    Os_uint32 NewEle,
    Os_uint32 OldEle,
    TickType CntVal
)
{
    TickType NewTime;
    TickType OldTime;
    Os_uint32 newObjID;
    Os_uint32 oldObjID;
    Os_boolean isNewFirst = OS_FALSE;

    /* get time from Alarm or Schtbl*/
    newObjID = cntCfgPtr->treeQue[NewEle].ObjId;
    oldObjID = cntCfgPtr->treeQue[OldEle].ObjId;
#if(OS_SCHTBL_NUMBER > 0)
    if(OS_FALSE == cntCfgPtr->treeQue[NewEle].isAlarm)
    {
        NewTime = Os_SchTblCBTable[newObjID].timeVal;
    }
    else
#endif /*(OS_SCHTBL_NUMBER > 0)*/
    {
#if(OS_ALARM_NUMBER > 0)
        NewTime = Os_AlarmCBTable[newObjID].timeVal;
#endif /*(OS_ALARM_NUMBER > 0)*/
    }
    

#if(OS_SCHTBL_NUMBER > 0)
    if(OS_FALSE == cntCfgPtr->treeQue[OldEle].isAlarm)
    {
        OldTime = Os_SchTblCBTable[oldObjID].timeVal;
    }
    else
#endif /*(OS_SCHTBL_NUMBER > 0)*/
    {
#if(OS_ALARM_NUMBER > 0)
        OldTime = Os_AlarmCBTable[oldObjID].timeVal;
#endif /*(OS_ALARM_NUMBER > 0)*/
    }


    if (OldTime < CntVal)
    {
        if ( (NewTime < OldTime) || (NewTime >= CntVal) )
        {
            isNewFirst = OS_TRUE; /*The new alarm will take place first.*/
        }
    }
    else
    {
        if ( (NewTime < OldTime) && (NewTime >= CntVal) )
        {
            isNewFirst = OS_TRUE; /*The new alarm will take place first.*/
        }
    }

    return isNewFirst;
}



/*****************************************************************************
* OS internal code
******************************************************************************/
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: OsCnt_TreeInsert
*
* Description:   Insert the actived alarm into the alarm array table.
*
* Inputs:        CoreID,CounterID,ObjId,isAlarm
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC (void, OS_CODE) OsCnt_TreeInsert
(
    CoreIdType CoreID,
    CounterType CounterID,
    Os_uint32 ObjID,
    Os_boolean isAlarm
)
{
    Os_uint32 OsFather;
    Os_uint32 OsPrex;
    Os_boolean needExchange;
    P2CONST(Os_CounterCfgType, AUTOMATIC, OS_CONST) cntCfgPtr = &Os_CounterCfg[CounterID];

#if(OS_SYSTICK_MODE == OS_HRT_MODE)
    Os_CounterTreeQueEleType originalFirst;
    Os_CounterTreeQueEleType newFirst;
    Os_uint32 originalTimeVal;
    Os_uint32 newTimeVal;
    Os_uint32 newCycle;

    if(OsCnt_TreeHead[CounterID] != 0)
    {
        originalFirst.ObjId = cntCfgPtr->treeQue[0].ObjId;
#if(OS_SCHTBL_NUMBER > 0)
        originalFirst.isAlarm = cntCfgPtr->treeQue[0].isAlarm;

        if(OS_FALSE == originalFirst.isAlarm)
        {
            originalTimeVal = Os_SchTblCBTable[originalFirst.ObjId].timeVal;  
        }
        else
#endif
        {
#if(OS_ALARM_NUMBER > 0)
            originalTimeVal = Os_AlarmCBTable[originalFirst.ObjId].timeVal; 
#endif
        }   
    }
#endif/* (OS_SYSTICK_MODE == OS_HRT_MODE) */



#if(OS_SCHTBL_NUMBER == 0)
    (void)isAlarm;
#endif /*(OS_SCHTBL_NUMBER == 0)*/
    OsPrex = OsCnt_TreeHead[CounterID]; /* The pointer of the alarm ready queue table is set to link the last element. */

    if(OsPrex >= cntCfgPtr->treeSize)
    {
        OsHook_FataErrReport(CoreID, E_OS_SYSFATA_CNTTREE, OSServiceId_OsCnt_TreeInsert, OS_IE_NOMORE_INFO, OsPrex, cntCfgPtr->treeSize, OS_IE_NO_ERRPAR);
    }

    while(OsPrex != (Os_uint32)0)
    {
        /* insert new element to the right position of tree*/
        cntCfgPtr->treeQue[OsPrex].ObjId = ObjID;
#if(OS_SCHTBL_NUMBER > 0)
        cntCfgPtr->treeQue[OsPrex].isAlarm = isAlarm;
#endif /*(OS_SCHTBL_NUMBER > 0)*/
        OsFather = (OsPrex - (Os_uint32)1) >> ((Os_uint32)1); /* Calculate the father node's number of the current inserted node. */
        needExchange = OsCnt_Compare(cntCfgPtr, OsPrex, OsFather, Os_CounterTick[CounterID]);

        if (OS_FALSE == needExchange)
        {
            break; /* the father node still takes place first after the new one is inserted. So no exchange. */
        }
         
        /* exchange the father node and new node*/
        cntCfgPtr->treeQue[OsPrex].ObjId = cntCfgPtr->treeQue[OsFather].ObjId;
#if(OS_SCHTBL_NUMBER > 0)
        cntCfgPtr->treeQue[OsPrex].isAlarm = cntCfgPtr->treeQue[OsFather].isAlarm;
#endif /*(OS_SCHTBL_NUMBER > 0)*/
        OsPrex = OsFather;
    }

    /* insert new element to the right position of tree*/
    cntCfgPtr->treeQue[OsPrex].ObjId = ObjID;
#if(OS_SCHTBL_NUMBER > 0)
    cntCfgPtr->treeQue[OsPrex].isAlarm = isAlarm;
#endif /*(OS_SCHTBL_NUMBER > 0)*/
    /*PRQA S 3383 ++*/
    /* Possibility of overflow has been checked by "OsPrex" before. */
    OsCnt_TreeHead[CounterID]++;
    /*PRQA S 3383 --*/

#if(OS_SYSTICK_MODE == OS_HRT_MODE)
    newFirst.ObjId = cntCfgPtr->treeQue[0].ObjId;
#if(OS_SCHTBL_NUMBER > 0)
    newFirst.isAlarm = cntCfgPtr->treeQue[0].isAlarm;

    if(OS_FALSE == newFirst.isAlarm)
    {
        if(SCHEDULETABLE_RUNNING == Os_SchTblCBTable[newFirst.ObjId].OsSchTblState)
        {
            newTimeVal = Os_SchTblCBTable[newFirst.ObjId].timeVal;
        }   
    }
    else
#endif /* (OS_SCHTBL_NUMBER > 0) */
    {
#if(OS_ALARM_NUMBER > 0)
        if(OS_TRUE == Os_AlarmCBTable[newFirst.ObjId].isAlive)
        {
            newTimeVal = Os_AlarmCBTable[newFirst.ObjId].timeVal;
            newCycle = Os_AlarmCBTable[newFirst.ObjId].alarmcycle;
        }
#endif/* (OS_ALARM_NUMBER > 0) */
    }
    
    OsSysTimer_UpdateReloadTimer(CoreID, CounterID, newTimeVal, originalTimeVal, OsCnt_LastCounterTick[CounterID],newCycle);

#endif/* (OS_SYSTICK_MODE == OS_HRT_MODE) */
}


/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: OsCnt_DelTreeElement
*
* Description:   delete alarm from the alarm tree. used in cancel and kill
*
* Inputs:        CoreID,CounterID,ObjId,isAlarm
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, OS_CODE) OsCnt_DelTreeElement
(
    CoreIdType CoreID,
    CounterType CounterID,
    Os_uint32  ObjID,
    Os_boolean isAlarm
)
{
    Os_uint32 OsChilD;
    Os_uint32 OsPrex;
    Os_uint32 OsFather;
    Os_uint32 OsHex;
    Os_boolean OsCompareValue;
    Os_uint32 tmpHead;

    P2CONST(Os_CounterCfgType, AUTOMATIC, OS_CONST) cntCfgPtr = &Os_CounterCfg[CounterID];
#if(OS_SCHTBL_NUMBER == 0)
    (void) isAlarm;
#endif /*(OS_SCHTBL_NUMBER == 0)*/
    for (OsPrex = (Os_uint32)0; OsPrex < OsCnt_TreeHead[CounterID]; OsPrex++) /* Find out the position of the alarm which is to be cancelled. */
    {
#if(OS_SCHTBL_NUMBER > 0)
        if((cntCfgPtr->treeQue[OsPrex].ObjId == ObjID) && (cntCfgPtr->treeQue[OsPrex].isAlarm == isAlarm))
#else 
        if(cntCfgPtr->treeQue[OsPrex].ObjId == ObjID)
#endif /*(OS_SCHTBL_NUMBER > 0)*/
        {
            break;
        }
    }

    /* not found the target node, error */
    if(OsPrex >= cntCfgPtr->treeSize)
    {
        OsHook_FataErrReport(CoreID, E_OS_SYSFATA_CNTTREE, OSServiceId_OsCnt_TreeDel, OS_IE_NOMORE_INFO, OsPrex, cntCfgPtr->treeSize, OS_IE_NO_ERRPAR);
        return;
    }


    OsHex = OsPrex; /* Label the position of the alarm in the alarm ready queue which is to be cancelled. */
    /*PRQA S 3383 ++*/
    /* Possibility of overflow has been checked by "OsPrex" before. */
    OsCnt_TreeHead[CounterID]--;
    /*PRQA S 3383 --*/
    tmpHead = OsCnt_TreeHead[CounterID];
    /* Replace the cancelled one in the alarm ready queue with the present last element. */
#if(OS_SCHTBL_NUMBER > 0)
    cntCfgPtr->treeQue[OsHex].isAlarm = cntCfgPtr->treeQue[tmpHead].isAlarm;
#endif /*(OS_SCHTBL_NUMBER > 0)*/
    cntCfgPtr->treeQue[OsHex].ObjId = cntCfgPtr->treeQue[tmpHead].ObjId;

    /* Compare with its father node. */
    while (OsPrex != (Os_uint32)0)
    {
        OsFather = ((OsPrex - (Os_uint32)1) >> (Os_uint32)1); /* Calculate the father node's number of the current processed node. */
        OsCompareValue = OsCnt_Compare(cntCfgPtr, OsPrex, OsFather, Os_CounterTick[CounterID]);

        if (OS_FALSE == OsCompareValue)
        {
            break; /* The alarm of the father node still takes place first after the new one is inserted. So no exchange. */
        }

        /* Exchanging between the father node and the new inserted one. */
        cntCfgPtr->treeQue[OsPrex].ObjId = cntCfgPtr->treeQue[OsFather].ObjId;
#if(OS_SCHTBL_NUMBER > 0)
        cntCfgPtr->treeQue[OsPrex].isAlarm = cntCfgPtr->treeQue[OsFather].isAlarm;
#endif /*(OS_SCHTBL_NUMBER > 0)*/

        OsPrex = OsFather;
    }

    /* move the last to the Prex position*/
    cntCfgPtr->treeQue[OsPrex].ObjId = cntCfgPtr->treeQue[tmpHead].ObjId;
#if(OS_SCHTBL_NUMBER > 0)
    cntCfgPtr->treeQue[OsPrex].isAlarm = cntCfgPtr->treeQue[tmpHead].isAlarm;
#endif /*(OS_SCHTBL_NUMBER > 0)*/

    /* Compare with its subnodes. */
    /*PRQA S 3383 ++*/
    /* Possibility of overflow has been checked by "OsPrex" before. */
    OsChilD = (OsHex << (Os_uint32)1) + (Os_uint32)1;
    /*PRQA S 3383 --*/

    while (OsChilD < tmpHead)
    {
        if (OsChilD >= cntCfgPtr->treeSize)
        {
            OsHook_FataErrReport(CoreID, E_OS_SYSFATA_CNTTREE, OSServiceId_OsCnt_TreeDel, OS_IE_NOMORE_INFO, OsChilD, cntCfgPtr->treeSize, OS_IE_NO_ERRPAR);
            return;
        }
        /*PRQA S 3383 ++*/
        /* Return value of "OsCnt_Compare" is "Os_boolean" which as same as "OsCompareValue". */
        OsCompareValue = OsCnt_Compare(cntCfgPtr, OsChilD, (OsChilD + (Os_uint32)1), Os_CounterTick[CounterID]);
        /*PRQA S 3383 --*/


        if (OS_FALSE == OsCompareValue) /* Compare the alarm time values of the two subnodes. */
        {
            OsChilD++;
        }

        OsCompareValue = OsCnt_Compare(cntCfgPtr, tmpHead, OsChilD, Os_CounterTick[CounterID]);


        if(OS_FALSE == OsCompareValue)
        {
            cntCfgPtr->treeQue[OsPrex].ObjId = cntCfgPtr->treeQue[OsChilD].ObjId;
#if(OS_SCHTBL_NUMBER > 0)
            cntCfgPtr->treeQue[OsPrex].isAlarm = cntCfgPtr->treeQue[OsChilD].isAlarm;
#endif /*(OS_SCHTBL_NUMBER > 0)*/
            OsPrex = OsChilD;
            /*PRQA S 3383 ++*/
            /* Possibility of overflow has been checked by "OsPrex" before. */
            OsChilD = (OsPrex << (Os_uint32)1) + (Os_uint32)1; /*Exchanging happens.*/
            /*PRQA S 3383 --*/
        }
        else
        {
            break;
        }
    }

    /* move the last to the Prex position*/
    cntCfgPtr->treeQue[OsPrex].ObjId = cntCfgPtr->treeQue[tmpHead].ObjId;
#if(OS_SCHTBL_NUMBER > 0)
    cntCfgPtr->treeQue[OsPrex].isAlarm = cntCfgPtr->treeQue[tmpHead].isAlarm;
#endif /*(OS_SCHTBL_NUMBER > 0)*/
}



/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: OsCnt_TreeRemove
*
* Description:   Remove the expired alarm from the alarm array table.
*
* Inputs:        CoreID,CounterID
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, OS_CODE) OsCnt_TreeRemove
(
    CoreIdType CoreID,
    CounterType CounterID
)
{
    Os_uint32 OsPrex = (Os_uint32)0;
    Os_uint32 OsChilD = (Os_uint32)1; /* (OsPrex << ((Os_uint32)1)) + (Os_uint32)1 */
    Os_boolean compareResult;
    Os_uint32 tempHead;
    P2CONST(Os_CounterCfgType, AUTOMATIC, OS_CONST) cntCfgPtr = &Os_CounterCfg[CounterID];

    /* PRQA S 3383 ++ */
    /*
    Sequence of execution is "OsCnt_InternalIncreaseCounter -> 
    OsSchTbl_Trigger/OsAlarm_Check -> OsCnt_TreeRemove", so OsCnt_TreeHead 
    will not be 0 which be ensured by "OsCnt_InternalIncreaseCounter".
    OsCnt_TreeHead will not underflow.
    */
    OsCnt_TreeHead[CounterID]--;
    /* PRQA S 3383 -- */
    tempHead = OsCnt_TreeHead[CounterID];
    if(tempHead == (Os_uint32)0)
    {
        /* no more alarm in tree, do nothing*/
        return;
    }

    /* move last ele to the header first*/
#if(OS_SCHTBL_NUMBER > 0)
    cntCfgPtr->treeQue[OsPrex].isAlarm = cntCfgPtr->treeQue[tempHead].isAlarm;
#endif /*(OS_SCHTBL_NUMBER > 0)*/
    cntCfgPtr->treeQue[OsPrex].ObjId = cntCfgPtr->treeQue[tempHead].ObjId;


    /*  if only 1 element in tree, this loop will not enter*/
    while (OsChilD < tempHead)
    {
        if ( (OsChilD >= cntCfgPtr->treeSize) || (OsPrex >= cntCfgPtr->treeSize) )
        {
            OsHook_FataErrReport(CoreID, E_OS_SYSFATA_CNTTREE, OSServiceId_OsCnt_TreeRemove, OS_IE_NOMORE_INFO, OsChilD, OsPrex, cntCfgPtr->treeSize);
            return;
        }

        /*If there are 2 more subnodes */
        /*PRQA S 3383 ++*/
        /*
        According to the "while" above, "OsChilD" is less than "tempHead", 
        so "OsChilD" will not overflow.
        */
        if(tempHead != (OsChilD + (Os_uint32)1))
        /*PRQA S 3383 --*/
        {
            /* Compare the alarm time values of the two subnodes. */
            /*PRQA S 3383 ++*/
            /* Return value of "OsCnt_Compare" is "Os_boolean" which as same as "compareResult". */
            compareResult = OsCnt_Compare(cntCfgPtr, OsChilD, (OsChilD + (Os_uint32)1), Os_CounterTick[CounterID]);
            /*PRQA S 3383 --*/
            if(OS_FALSE == compareResult) 
            {
                OsChilD++; /* The alarm of the second subnode will take place first, so "OsChilD will move to the second subnode". */
            }
        }

        compareResult = OsCnt_Compare(cntCfgPtr, OsPrex, OsChilD, Os_CounterTick[CounterID]);

        /* if prex is not the one first take place,  exchange OsPrex and OsChilD*/
        if(OS_FALSE == compareResult)
        {
            /* The values of the previous node and the smaller subnode exchange to each other.*/
#if(OS_SCHTBL_NUMBER > 0)
            cntCfgPtr->treeQue[OsPrex].isAlarm = cntCfgPtr->treeQue[OsChilD].isAlarm;
#endif /*(OS_SCHTBL_NUMBER > 0)*/
            cntCfgPtr->treeQue[OsPrex].ObjId = cntCfgPtr->treeQue[OsChilD].ObjId;


            OsPrex = OsChilD;
#if(OS_SCHTBL_NUMBER > 0)
            cntCfgPtr->treeQue[OsPrex].isAlarm = cntCfgPtr->treeQue[tempHead].isAlarm;
#endif /*(OS_SCHTBL_NUMBER > 0)*/
            cntCfgPtr->treeQue[OsPrex].ObjId = cntCfgPtr->treeQue[tempHead].ObjId;

            /*PRQA S 3383 ++*/
            /* According to "treeSize", here will not overflow. */
            OsChilD = (OsPrex << ((Os_uint32)1)) + (Os_uint32)1;
            /*PRQA S 3383 --*/
        }
        else
        {
            break;
        }
    }
}
#endif /*((OS_ALARM_NUMBER > 0) || (OS_SCHTBL_NUMBER > 0))*/

#if(OS_SYSTICK_MODE == OS_HRT_MODE)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: OsCnt_CheckCounter
*
* Description:   Check if counter needs to be updated  
*
* Inputs:        CoreID, CounterID
*
* Outputs:       Os_uint32
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC (Os_uint32, OS_CODE) OsCnt_CheckCounter
(
    CoreIdType CoreID,
    CounterType CounterID
)
{
    P2CONST(Os_CounterCfgType, AUTOMATIC, OS_CONST) cntCfgPtr = &Os_CounterCfg[CounterID];

#if((OS_SCHTBL_NUMBER == 0) && (OS_ALARM_NUMBER == 0))
    (void)CoreID;
#endif /*((OS_SCHTBL_NUMBER == 0) && (OS_ALARM_NUMBER == 0))*/

    if(cntCfgPtr->treeQue != NULL_PTR)
    {
        while(OsCnt_TreeHead[CounterID] != (Os_uint32)0)
        {
#if(OS_SCHTBL_NUMBER > 0)
            if(OS_FALSE == cntCfgPtr->treeQue[0].isAlarm)
            {
                /*PRQA S 3416 ++*/
                /* The side effect of "OsSchTbl_Trigger" is expected. */
                if(OS_FALSE == OsSchTbl_Trigger(CoreID, CounterID, (ScheduleTableType)(cntCfgPtr->treeQue[0].ObjId)))
                /*PRQA S 3416 --*/
                {
                    break;/* no EP of schedule table reach, dont loop any more*/
                }
            }
            else
#endif /*(OS_SCHTBL_NUMBER > 0)*/
            {
#if(OS_ALARM_NUMBER > 0)
                /*PRQA S 3416 ++*/
                /* The side effect of "OsAlarm_Check" is expected. */
                if(OS_FALSE == OsAlarm_Check(CoreID, CounterID, (AlarmType)(cntCfgPtr->treeQue[0].ObjId)))
                /*PRQA S 3416 --*/
                {
                    /*PRQA S 0771 ++*/
                    /*
                    Multiple "break" in this "while" loop is essential 
                    to support both schedule table and alarm.
                    */
                    break;/* no alarm expire, dont loop any more*/
                    /*PRQA S 0771 --*/
                }
#endif /*(OS_ALARM_NUMBER > 0)*/
            }
        }
    }
    OsCnt_LastCounterTick[CounterID] = Os_CounterTick[CounterID];

    return OsCnt_TreeHead[CounterID];
}
#endif/*(OS_SYSTICK_MODE == OS_HRT_MODE)*/

/* BEGIN_FUNCTION_HDR
***********************************************************************************************
* Function Name: OsCnt_InternalIncreaseCounter
*
* Description:   counter tick add, trigger alarm or schedule table actions
*
* Inputs:        CoreID,CounterID
*
* Outputs:       None
*
* Limitations:   None
***********************************************************************************************
END_FUNCTION_HDR*/
FUNC(void, OS_CODE) OsCnt_InternalIncreaseCounter
(
    CoreIdType CoreID,
    CounterType CounterID
)
{
    P2CONST(Os_CounterCfgType, AUTOMATIC, OS_CONST) cntCfgPtr = &Os_CounterCfg[CounterID];

#if((OS_SCHTBL_NUMBER == 0) && (OS_ALARM_NUMBER == 0))
    (void)CoreID;
#endif /*((OS_SCHTBL_NUMBER == 0) && (OS_ALARM_NUMBER == 0))*/
#if(OS_ON == OS_CNT_TIMEPERBASE_GREAT1)
    /*PRQA S 3383 ++*/
    /* 
    "OsCnt_PrivateCounterTick" increases from 0, "if..." and "ticksperbase" below
    limit its value. It will never overflow.
    */
    OsCnt_PrivateCounterTick[CounterID]++;
    /*PRQA S 3383 --*/
    if(OsCnt_PrivateCounterTick[CounterID] >= Os_CounterCfg[CounterID].alarmBase.ticksperbase)
#endif /*(OS_ON == OS_CNT_TIMEPERBASE_GREAT1)*/
    {
#if(OS_ON == OS_CNT_TIMEPERBASE_GREAT1)
        /*Clear the time base counter to 0.*/
        OsCnt_PrivateCounterTick[CounterID] = (TickType)0;
#endif /*(OS_ON == OS_CNT_TIMEPERBASE_GREAT1)*/
        /*The real-time value of Counter can be equal to the configured maximum value.*/
        if(Os_CounterTick[CounterID] >= Os_CounterCfg[CounterID].alarmBase.maxallowedvalue)
        {
            Os_CounterTick[CounterID] = (TickType)0;
        }
        else
        {
            /*PRQA S 3383 ++*/
            /* According to the "if..." above, "Os_CounterTick" here will never overflow. */
            Os_CounterTick[CounterID]++;
            /*PRQA S 3383 --*/
        }
    }

    if(cntCfgPtr->treeQue != NULL_PTR)
    {
        while(OsCnt_TreeHead[CounterID] != (Os_uint32)0)
        {
#if(OS_SCHTBL_NUMBER > 0)
            if(OS_FALSE == cntCfgPtr->treeQue[0].isAlarm)
            {
                /*PRQA S 3416 ++*/
                /* The side effect of "OsSchTbl_Trigger" is expected. */
                if(OS_FALSE == OsSchTbl_Trigger(CoreID, CounterID, (ScheduleTableType)(cntCfgPtr->treeQue[0].ObjId)))
                /*PRQA S 3416 --*/
                {
                    break;/* no EP of schedule table reach, dont loop any more*/
                }
            }
            else
#endif /*(OS_SCHTBL_NUMBER > 0)*/
            {
#if(OS_ALARM_NUMBER > 0)
                /*PRQA S 3416 ++*/
                /* The side effect of "OsAlarm_Check" is expected. */
                if(OS_FALSE == OsAlarm_Check(CoreID, CounterID, (AlarmType)(cntCfgPtr->treeQue[0].ObjId)))
                /*PRQA S 3416 --*/
                {
                    /*PRQA S 0771 ++*/
                    /*
                    Multiple "break" in this "while" loop is essential 
                    to support both schedule table and alarm.
                    */
                    break;/* no alarm expire, dont loop any more*/
                    /*PRQA S 0771 --*/
                }
#endif /*(OS_ALARM_NUMBER > 0)*/
            }
        }
    }
}




/* BEGIN_FUNCTION_HDR
***********************************************************************************************
* Function Name: OsCnt_Init
*
* Description:   called in start OS, init counter module
*
* Inputs:        CoreID
*
* Outputs:       None
*
* Limitations:   None
***********************************************************************************************
END_FUNCTION_HDR*/
FUNC(void, OS_CODE) OsCnt_Init
(
    CoreIdType CoreID
)
{
    CounterType cntID = (CounterType)0;
    CounterType endCntId = Os_CoreCfg[CoreID].startCntId + Os_CoreCfg[CoreID].cntNum;

    for(cntID = Os_CoreCfg[CoreID].startCntId; cntID < endCntId; cntID++)
    {
        Os_CounterTick[cntID] = (TickType)0;
        OsCnt_TreeHead[cntID] = (Os_uint32)0;
#if(OS_ON == OS_CNT_TIMEPERBASE_GREAT1)
        OsCnt_PrivateCounterTick[cntID] = (TickType)0;
#endif /*(OS_ON == OS_CNT_TIMEPERBASE_GREAT1)*/
    }
}

/*****************************************************************************
* API code
******************************************************************************/

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Os_IncrementCounter
*
* Description:   The function called by users to trigger user-defined counters.
*                
* Inputs:        <CounterID> Reference to counter.
*
* Outputs:       None
* 
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
#if(OS_USER_COUNTER_NUMBER > 0)
FUNC(StatusType, OS_CODE) Os_IncrementCounter
(
    CounterType CounterID
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
    
    else if((Os_uint16)(Os_CurrentContext[CoreID] & Os_IncrementCounterMask) == (Os_uint16)0)
    {
        OsHook_ReportError(CoreID, E_OS_CALLEVEL, OSServiceId_IncrementCounter, OS_IE_NOMORE_INFO, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR);
        ret = E_OS_CALLEVEL;
    }

    /* Check whether this API is called between interrupt processing APIs*/
    else if(OS_NO_API_USED != Os_IntAPIUsedFlag[CoreID])
    {
        /* System error -- this API is called between interrupt processing function pairs */
        OsHook_ReportError(CoreID, E_OS_DISABLEDINT, OSServiceId_IncrementCounter, OS_IE_NOMORE_INFO, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR);
        ret = E_OS_DISABLEDINT;
    }

    /* check id CounterID is valid, system counter can not be add by this API*/
    else if((CounterID >= (CounterType)OS_COUNTER_NUMBER) || (CounterID ==  Os_CoreCfg[CoreID].startCntId))
    {
        OsHook_ReportError(CoreID, E_OS_ID, OSServiceId_IncrementCounter, OS_IE_COUNTER_ID, (Os_uint32)CounterID, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR);
        ret = E_OS_ID; 
    }

#if(OS_USED_CORE_NUMBER > 1)
    /* Check whether Cross core job SWS_Os_00629 Counter can not be added by other core*/
    else if(CoreID != Os_CounterCfg[CounterID].objCoreId)
    {
        OsHook_ReportError(CoreID, E_OS_SYS_SERVICE_NOTSUPPORT_CROSSCORE, OSServiceId_IncrementCounter, OS_IE_NOMORE_INFO, (Os_uint32)CounterID, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR);
        ret = E_OS_SYS_SERVICE_NOTSUPPORT_CROSSCORE;
    }
#endif /*(OS_USED_CORE_NUMBER > 1)*/

#if(OS_APPLICATION_NUMBER > 0)
    /*  current application invalid, should not has this case*/
    else if(Os_CurrentApplicationId[CoreID] == OS_INVALID_OSAPPLICATION)
    {
        OsHook_ReportError(CoreID, E_OS_ACCESS, OSServiceId_IncrementCounter, OS_IE_INVALID_OSAPPICATION, (Os_uint32)Os_CurrentApplicationId[CoreID], OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR);
        ret = E_OS_ACCESS;
    }

    else if((Os_ApplicationMaskType)0 == ( (((Os_ApplicationMaskType)1) << Os_CurrentApplicationId[CoreID]) & Os_CounterCfg[CounterID].AppMask))
    {
        OsHook_ReportError(CoreID, E_OS_ACCESS, OSServiceId_IncrementCounter, OS_IE_NO_ACCESS_RIGHT, (Os_uint32)Os_CurrentApplicationId[CoreID], (Os_uint32)CounterID, OS_IE_NO_ERRPAR);
        ret = E_OS_ACCESS;
    }
#endif /*(OS_APPLICATION_NUMBER > 0)*/
    else
#endif /*(OS_STATUS_LEVEL == OS_EXTENDED)*/
    {
        /* Enter critical section */
        OsCpu_EnterCritical(CoreID, &tempPri);

        OsCnt_InternalIncreaseCounter(CoreID, CounterID);

        /* Exit critical section */
        OsCpu_ExitCritical(CoreID, tempPri);
    }
    return ret;
}
#endif /*(OS_USER_COUNTER_NUMBER > 0)*/

/* BEGIN_FUNCTION_HDR
***********************************************************************************************
* Function Name: Os_GetCounterValue
*
* Description:   The function called by users to get the current value of the referenced counter.
*                
* Inputs:        <CounterID> The Counter whose tick value is read.
*
* Outputs:       <Value> Contains the current tick value of the counter.
*
* Limitations:   None
***********************************************************************************************
END_FUNCTION_HDR*/
FUNC(StatusType, OS_CODE) Os_GetCounterValue
(
    CounterType CounterID,
    TickRefType Value
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
    
    else if((Os_uint16)(Os_CurrentContext[CoreID] & Os_GetCounterValueMask) == (Os_uint16)0)
    {
        OsHook_ReportError(CoreID, E_OS_CALLEVEL, OSServiceId_GetCounterValue, OS_IE_NOMORE_INFO, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR);
        ret = E_OS_CALLEVEL;
    }

    /* Check whether this API is called between interrupt processing APIs*/
    else if(OS_NO_API_USED != Os_IntAPIUsedFlag[CoreID])
    {
        /* System error -- this API is called between interrupt processing function pairs */
        OsHook_ReportError(CoreID, E_OS_DISABLEDINT, OSServiceId_GetCounterValue, OS_IE_NOMORE_INFO, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR);
        ret = E_OS_DISABLEDINT;
    }

    /* Check the validity of Value:Value cannot be NULL */
    else if(NULL_PTR == Value)
    {
        OsHook_ReportError(CoreID, E_OS_PARAM_POINTER, OSServiceId_GetCounterValue, OS_IE_NOMORE_INFO, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR);
        ret = E_OS_PARAM_POINTER;
    }

    /* check id CounterID is valid, system counter can not be add by this API*/
    else if(CounterID >= (CounterType)OS_COUNTER_NUMBER)
    {
        OsHook_ReportError(CoreID, E_OS_ID, OSServiceId_GetCounterValue, OS_IE_COUNTER_ID, (Os_uint32)CounterID, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR);
        ret = E_OS_ID; 
    }

#if(OS_USED_CORE_NUMBER > 1)
    /* Check whether this API is called from diifferent core*/
    else if(CoreID != Os_CounterCfg[CounterID].objCoreId)
    {
        OsHook_ReportError(CoreID, E_OS_SYS_SERVICE_NOTSUPPORT_CROSSCORE, OSServiceId_GetCounterValue, OS_IE_NOMORE_INFO, (Os_uint32)CounterID, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR);
        ret = E_OS_SYS_SERVICE_NOTSUPPORT_CROSSCORE;
    }
#endif /*(OS_USED_CORE_NUMBER > 1)*/

#if(OS_APPLICATION_NUMBER > 0)
    /*  current application invalid, should not has this case*/
    else if(Os_CurrentApplicationId[CoreID] == OS_INVALID_OSAPPLICATION)
    {
        OsHook_ReportError(CoreID, E_OS_ACCESS, OSServiceId_GetCounterValue, OS_IE_INVALID_OSAPPICATION, (Os_uint32)Os_CurrentApplicationId[CoreID], OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR);
        ret = E_OS_ACCESS;
    }
            
    else if((OS_FALSE == (Os_AppCfg[Os_CurrentApplicationId[CoreID]].isTrusted))&&((Os_ApplicationMaskType)0 == ( (((Os_ApplicationMaskType)1) << Os_CurrentApplicationId[CoreID]) & Os_CounterCfg[CounterID].AppMask)))
    {
        OsHook_ReportError(CoreID, E_OS_ACCESS, OSServiceId_GetCounterValue, OS_IE_NO_ACCESS_RIGHT, (Os_uint32)Os_CurrentApplicationId[CoreID], (Os_uint32)CounterID, OS_IE_NO_ERRPAR);
        ret = E_OS_ACCESS;
    }
#endif /*(OS_APPLICATION_NUMBER > 0)*/
    else
#endif /*(OS_STATUS_LEVEL == OS_EXTENDED)*/
    {
        /* Os_CounterTick can not be protected by spinlock, so this API do not support cross core opration */

        /* Enter critical section */
        OsCpu_EnterCritical(CoreID, &tempPri);

#if(OS_SYSTICK_MODE == OS_HRT_MODE)
        if(CounterID == Os_CoreCfg[CoreID].startCntId)
        {
            *Value = OsSysTimer_UpdateCounter(CoreID,Os_CoreCfg[CoreID].startCntId);
        }
        else
#endif/* (OS_SYSTICK_MODE == OS_HRT_MODE) */
        {
            *Value = Os_CounterTick[CounterID];
        }

        /* Exit critical section */
        OsCpu_ExitCritical(CoreID, tempPri);
    }
    return ret;
}

/* BEGIN_FUNCTION_HDR
***********************************************************************************************
* Function Name: Os_GetElapsedValue
*
* Description:   This service calculates the number of ticks between the current tick value
*                and a previously read tick value.
*                
* Inputs:        <CounterID> The Counter whose tick value is read.
*                <Value> The previously read tick value of the referenced counter.
*
* Outputs:       <ElapsedValue> The difference from the current tick value to the previous
*                read value.
*
* Limitations:   If the counter already passed the <Value> value a second (or multiple) time,
*                the result returned is wrong. That is because the service is not able to
*                detect such a relative overflow.
***********************************************************************************************
END_FUNCTION_HDR*/
FUNC(StatusType, OS_CODE) Os_GetElapsedValue
(
    CounterType CounterID,
    TickRefType Value,
    TickRefType ElapsedValue
)
{
    CoreIdType CoreID;
    Os_boolean tempPri;

    TickType prevVal;
    TickType currentVal;
    TickType dVal;
    StatusType ret = E_OS_OK;

    CoreID = OsCpu_GetCoreID();

#if(OS_STATUS_LEVEL == OS_EXTENDED)
    if((CoreID >= (CoreIdType)OS_USED_CORE_NUMBER) || (Os_CoreState[CoreID] != OS_CORE_START))
    {
        /* can not record err in this state, as OS services can not be called*/
        ret = E_OS_CORE;
    }
    
    else if((Os_uint16)(Os_CurrentContext[CoreID] & Os_GetElapsedValueMask) == (Os_uint16)0)
    {
        OsHook_ReportError(CoreID, E_OS_CALLEVEL, OSServiceId_GetElapsedValue, OS_IE_NOMORE_INFO, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR);
        ret = E_OS_CALLEVEL;
    }

    /* Check whether this API is called between interrupt processing APIs*/
    else if(OS_NO_API_USED != Os_IntAPIUsedFlag[CoreID])
    {
        /* System error -- this API is called between interrupt processing function pairs */
        OsHook_ReportError(CoreID, E_OS_DISABLEDINT, OSServiceId_GetElapsedValue, OS_IE_NOMORE_INFO, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR);
        ret = E_OS_DISABLEDINT;
    }

    /* Check the validity of Value:Value cannot be NULL */
    else if((NULL_PTR == Value) || (NULL_PTR == ElapsedValue))
    {
        OsHook_ReportError(CoreID, E_OS_PARAM_POINTER, OSServiceId_GetElapsedValue, OS_IE_NOMORE_INFO, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR);
        ret = E_OS_PARAM_POINTER;
    }

    /* check id CounterID is valid, system counter can not be add by this API*/
    else if(CounterID >= (CounterType)OS_COUNTER_NUMBER)
    {
        OsHook_ReportError(CoreID, E_OS_ID, OSServiceId_GetElapsedValue, OS_IE_COUNTER_ID, (Os_uint32)CounterID, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR);
        ret = E_OS_ID; 
    }

#if(OS_USED_CORE_NUMBER > 1)
    /* Check whether this API is called from diifferent core*/
    else if(CoreID != Os_CounterCfg[CounterID].objCoreId)
    {
        OsHook_ReportError(CoreID, E_OS_SYS_SERVICE_NOTSUPPORT_CROSSCORE, OSServiceId_GetElapsedValue, OS_IE_NOMORE_INFO, (Os_uint32)CounterID, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR);
        ret = E_OS_SYS_SERVICE_NOTSUPPORT_CROSSCORE;
    }
#endif /*(OS_USED_CORE_NUMBER > 1)*/

#if(OS_APPLICATION_NUMBER > 0)
    /*  current application invalid, should not has this case*/
    else if(Os_CurrentApplicationId[CoreID] == OS_INVALID_OSAPPLICATION)
    {
        OsHook_ReportError(CoreID, E_OS_ACCESS, OSServiceId_GetElapsedValue, OS_IE_INVALID_OSAPPICATION, (Os_uint32)Os_CurrentApplicationId[CoreID], OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR);
        ret = E_OS_ACCESS;
    }
           
    else if((OS_FALSE == (Os_AppCfg[Os_CurrentApplicationId[CoreID]].isTrusted))&&((Os_ApplicationMaskType)0 == ( (((Os_ApplicationMaskType)1) << Os_CurrentApplicationId[CoreID]) & Os_CounterCfg[CounterID].AppMask)))
    {
        OsHook_ReportError(CoreID, E_OS_ACCESS, OSServiceId_GetElapsedValue, OS_IE_NO_ACCESS_RIGHT, (Os_uint32)Os_CurrentApplicationId[CoreID], (Os_uint32)CounterID, OS_IE_NO_ERRPAR);
        ret = E_OS_ACCESS;
    }
#endif /*(OS_APPLICATION_NUMBER > 0)*/
    else
#endif /*(OS_STATUS_LEVEL == OS_EXTENDED)*/
    {
        /* Os_CounterTick can not be protected by spinlock, so this API do not support cross core opration */


        /* Enter critical section */
        OsCpu_EnterCritical(CoreID, &tempPri);

        prevVal = *Value;
#if(OS_SYSTICK_MODE == OS_HRT_MODE)        
        if(CounterID == Os_CoreCfg[CoreID].startCntId)
        {
            currentVal = OsSysTimer_UpdateCounter(CoreID,Os_CoreCfg[CoreID].startCntId);
        }
        else
#endif/* (OS_SYSTICK_MODE == OS_HRT_MODE) */        
        {
            currentVal = Os_CounterTick[CounterID];
        }
        
        if(currentVal >= prevVal)
        {
            dVal = currentVal - prevVal;
        }
        else
        {
            /* code */
            /*PRQA S 3383,3384 ++*/
            /*
            The "if..." before make sure that "currentVal" is less than "prevVal", 
            so the right value below will less than or equal to "maxallowedvalue"
            which means overflow or underflow will not happen.
            */
            dVal = currentVal + (TickType)1 +(Os_CounterCfg[CounterID].alarmBase.maxallowedvalue - prevVal);
            /*PRQA S 3383,3384 --*/
        }
        

        *ElapsedValue = dVal;
#if(OS_SYSTICK_MODE == OS_HRT_MODE)
        if(CounterID == Os_CoreCfg[CoreID].startCntId)
        {
            *Value = OsSysTimer_UpdateCounter(CoreID,Os_CoreCfg[CoreID].startCntId);
        }
        else
#endif/* (OS_SYSTICK_MODE == OS_HRT_MODE) */        
        {
            *Value = Os_CounterTick[CounterID];
        }

        /* Exit critical section */
        OsCpu_ExitCritical(CoreID, tempPri);
    }
    return ret;
}


#define OS_STOP_SEC_CODE
#include "Os_MemMap.h"
