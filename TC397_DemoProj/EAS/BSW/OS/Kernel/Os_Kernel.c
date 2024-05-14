/* BEGIN_FILE_HDR
********************************************************************************
* NOTICE
* This software is the property of HiRain Technologies. Any information
* contained in this doc should not be reproduced, or used, or disclosed
* without the written authorization from HiRain Technologies.
********************************************************************************
* File Name:       Os_Kernel.c
********************************************************************************
* Project/Product: AUTOSAR OS PROJECT
* Title:           Os_Kernel.c
* Author:          Hirain
********************************************************************************
* Description:     Kernel module of OS
*
********************************************************************************
* Limitations     : None
*
********************************************************************************
*
********************************************************************************
* Revision History:
*
* Version     Date          Initials                CR#          Descriptions
* ---------  ----------  -----------------------  ------  ---------------------
* 0.0.0.0.1  24/03/2021  Ning.Chen                N/A     Init version
* 0.0.0.0.2  06/04/2021  Feixiang.Dong            N/A     EAS422_OS_20210406_01
* 0.0.0.0.3  18/04/2021  Feixiang.Dong            N/A     EAS422_OS_20210418_01
* 0.0.0.0.4  20/04/2021  Ning.Chen                N/A     EAS422_OS_20210420_01
* 0.0.0.0.5  22/04/2021  Feixiang.Dong            N/A     EAS422_OS_20210422_01
* 0.0.0.0.6  28/04/2021  Feixiang.Dong            N/A     EAS422_OS_20210428_01
* 1.1.0.0.0  20/05/2021  Feixiang.Dong            N/A     EAS422_OS_20210520_01
* 1.1.1.1.0  18/09/2021  Yanan.Zhao1              N/A     EAS422_OS_20210918_01
* 1.1.1.1.1  31/10/2021  Yanan.Zhao1              N/A     EAS422_OS_20211031_01
* 1.1.1.1.5  23/11/2021  Yanan.Zhao1              N/A     EAS422_OS_20211123_01
* 1.1.1.1.6  29/04/2022  Yanan.Zhao1              N/A     EAS422_OS_20220429_01
* 1.1.1.1.7  05/07/2022  Yanan.Zhao1              N/A     EAS422_OS_20220705_01
* 1.1.2.1.0  05/09/2022  Yanan.Zhao1              N/A     EAS422_OS_20220905_01
* 1.1.2.1.1  04/11/2022  Yanan.Zhao1              N/A     EAS422_OS_20221104_01
* 1.1.2.1.2  22/12/2022  Yanan.Zhao1              N/A     EAS422_OS_20221222_01
* 1.1.2.1.3  09/01/2023  Yanan.Zhao1              N/A     EAS422_OS_20230109_01
* 1.1.2.1.4  14/03/2023  Longchuan.Pei            N/A     EAS422_OS_20230314_01
* 1.1.2.1.5  03/04/2023  Longchuan.Pei            N/A     EAS422_OS_20230403_01
* 1.1.3.1.0  24/04/2023  Longchuan.Pei            N/A     EAS422_OS_20230424_01
* 1.1.3.1.1  22/05/2023  Longchuan.Pei            N/A     EAS422_OS_20230522_01
* 1.1.3.1.2  02/06/2023  jie.wang12               N/A     EAS422_OS_20230602_01
* 1.1.4.2.0  18/08/2023  he.ma1                   N/A     EAS422_OS_20230818_01
* 1.1.4.2.1  30/10/2023  he.ma1                   N/A     EAS422_OS_20231030_01
********************************************************************************
* END_FILE_HDR*/

/*****************************************************************************
* include
******************************************************************************/
/*PRQA S 0857 EOF*/
/*
Number of macro definitions exceeds 1024
*/
#include "Os_Internal.h"

/*****************************************************************************
* General QAC Suppression
******************************************************************************/
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

/*PRQA S 3119 EOF*/
/*
Some parameters will not be used in different configurations and hardware 
platforms, but they can not be deleted according to the requirements of 
AUTOSAR specification or compatibility. So we retain these parameters for 
compatibility and convert them with (void) to clean the warnings in compiler.
PRQA notices such statements as warning 3119, it has been suppressed here.
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

/*PRQA S 0862 EOF*/
/*
The code segment like:

#define XXX
#include "Os_MemMap.h"

is a part of AUTOSAR specification, but will be an error in PRQA.
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

/*PRQA S 1006 EOF*/
/*
Inline assembler statement is essential.
*/

/*****************************************************************************
* Version check
******************************************************************************/
#if(OS_ON == OS_VERSION_CHECK)

#if((OS_AR_RELEASE_MAJOR_VERSION != OS_AR_RELEASE_MAJOR_VERSION_CFG) || \
    (OS_AR_RELEASE_MINOR_VERSION != OS_AR_RELEASE_MINOR_VERSION_CFG))
#error "AutoSar Version Numbers of OS and its cfg file are different"
#endif

#if((OS_SW_MAJOR_VERSION != OS_SW_MAJOR_VERSION_CFG) || \
    (OS_SW_TEC_VERSION != OS_SW_TEC_VERSION_CFG))
#error "SW Version Numbers of OS and its cfg file are different"
#endif

#if((OS_SW_MAJOR_VERSION != OS_PL_SW_MAJOR_VERSION) || \
    (OS_SW_EKPC_VERSION != OS_PL_SW_EKPC_VERSION))
#error "SW Version Numbers of OS and its portable file are different"
#endif

#if((OS_PL_SW_MAJOR_VERSION != OS_PL_SW_MAJOR_VERSION_CFG) || \
    (OS_PL_SW_TEC_VERSION != OS_PL_SW_TEC_VERSION_CFG))
#error "Portable Version Numbers of OS and its cfg file are different"
#endif

#if((OS_SW_MAJOR_VERSION_CFG != OS_PL_SW_MAJOR_VERSION_CFG) || \
    (OS_SW_TKPC_VERSION_CFG != OS_PL_SW_TKPC_VERSION_CFG))
#error "SW cfg Version Numbers and Portable cfg Version Numbers are different"
#endif

#endif /*(OS_ON == OS_VERSION_CHECK)*/

/*****************************************************************************
* static variables define
******************************************************************************/
#define OS_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap.h"

/* save the highest task priority in ready table */
STATIC VAR(Os_PrioType, OS_VAR) OsKernel_HighestTaskPri[OS_USED_CORE_NUMBER];
STATIC VAR(TaskType, OS_VAR) OsKernel_HighestTaskId[OS_USED_CORE_NUMBER];
#if(OS_CPULOAD_API == OS_ON)
STATIC VAR(Os_CpuLoadTickType, OS_VAR) OsKernel_IdleRunTime[OS_USED_CORE_NUMBER];
STATIC VAR(Os_CpuLoadTickType, OS_VAR) OsKernel_IdleStartTime[OS_USED_CORE_NUMBER];
#endif /*(OS_CPULOAD_API == OS_ON)*/

#define OS_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap.h"

#if(OS_OSAPP_STARTUPHOOK_SUPPORT == OS_ON)
#if (OS_USED_CORE_NUMBER == 1)
#define OS_START_SEC_VAR_NOINIT_UNSPECIFIED
#else
#define OS_START_SEC_VAR_NOINIT_MULTICORE
#endif /*(OS_USED_CORE_NUMBER == 1)*/
#include "Os_MemMap.h"

STATIC VAR(Os_CoreStateType, OS_VAR) OsKernel_CoreSynAppStartup[OS_USED_CORE_NUMBER];

#if (OS_USED_CORE_NUMBER == 1)
#define OS_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#else
#define OS_STOP_SEC_VAR_NOINIT_MULTICORE
#endif /*(OS_USED_CORE_NUMBER == 1)*/
#include "Os_MemMap.h"
#endif /*(OS_OSAPP_STARTUPHOOK_SUPPORT == OS_ON)*/

/*****************************************************************************
* static macro define
******************************************************************************/
#if(OS_CPULOAD_API == OS_ON)
#define OS_CPULOAD_PERCENTAGE    ((Os_uint32)100)
#endif /*(OS_CPULOAD_API == OS_ON)*/

#define OS_DATA_SHIFT_TWO        2
#define OS_DATA_SHIFT_FOUR       4
#define OS_DATA_SHIFT_EIGHT      8
#define OS_DATA_SHIFT_SIXTEEN    16

#define OS_DATA_MASK_000F        ((Os_uint32)0x000F)
#define OS_DATA_MASK_00FF        ((Os_uint32)0x00FF)
#define OS_DATA_MASK_FFFF        ((Os_uint32)0xFFFF)

#define OS_PRIO_MAP_SIZE         ((Os_uint8)16)
/*****************************************************************************
* static const define
******************************************************************************/
#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
STATIC CONST(Os_uint8, OS_CONST) OsKernel_PrioTransMap[OS_PRIO_MAP_SIZE] =
{
    (Os_uint8)0,  /* 0000 */
    (Os_uint8)0,  /* 0001 */
    (Os_uint8)1,  /* 0010 */
    (Os_uint8)0,  /* 0011 */
    (Os_uint8)2,  /* 0100 */
    (Os_uint8)0,  /* 0101 */
    (Os_uint8)1,  /* 0110 */
    (Os_uint8)0,  /* 0111 */
    (Os_uint8)3,  /* 1000 */
    (Os_uint8)0,  /* 1001 */
    (Os_uint8)1,  /* 1010 */
    (Os_uint8)0,  /* 1011 */
    (Os_uint8)2,  /* 1100 */
    (Os_uint8)0,  /* 1101 */
    (Os_uint8)1,  /* 1110 */
    (Os_uint8)0   /* 1111 */
};
#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"

#define OS_START_SEC_CODE
#include "Os_MemMap.h"
/*****************************************************************************
* kernel private code
******************************************************************************/
STATIC FUNC(void, OS_CODE) OsKernel_SynStartUp
(
    CoreIdType CoreID
);

STATIC FUNC(void, OS_CODE) OsKernel_SetTaskPriReadyTable
(
    CoreIdType CoreID,
    Os_PrioType priority
);

STATIC FUNC(void, OS_CODE) OsKernel_ClearTaskPriReadyTable
(
    CoreIdType CoreID,
    Os_PrioType priority
);

STATIC FUNC(Os_uint8, OS_CODE) OsKernel_GetHighestPriLine
(
    Os_uint32 value
);

STATIC FUNC(void, OS_CODE) OsKernel_UpdateTaskHighestPri
(
    CoreIdType CoreID,
    Os_PrioType removePri
);


/* BEGIN_FUNCTION_HDR
***********************************************************************************************
* Function Name: OsKernel_SynStartUp
*
* Description:   process multicore syn start of OS
*
*
* Inputs:        CoreID
*
* Outputs:       None
*
* Limitations:   None
***********************************************************************************************
END_FUNCTION_HDR*/
#if(OS_USED_CORE_NUMBER > 1)
STATIC FUNC(void, OS_CODE) OsKernel_SynStartUp
(
    CoreIdType CoreID
)
{
    CoreIdType i;
    Os_boolean SynFlag = OS_FALSE;
#if(OS_OSAPP_STARTUPHOOK_SUPPORT == OS_ON)
    ApplicationType appIndex; /* when mulicore used, application must be used*/
    ApplicationType endAppId;
#endif /*(OS_OSAPP_STARTUPHOOK_SUPPORT == OS_ON)*/

#if(OS_STATUS_LEVEL == OS_EXTENDED)
#if(OS_APPMODE_NUMBER > 1)
    Os_AppModeMaskType tempAppMode;
#endif /*(OS_APPMODE_NUMBER > 1)*/
#endif /*(OS_STATUS_LEVEL == OS_EXTENDED)*/

    if(CoreID != OS_PL_MASTER_COREID)
    {
        Os_CoreSyn[CoreID] = OS_CORE_START;
        /* synchronization before OS kernel first schedule */
        /* slave core only wait master core start, as master core has extra work to do
           if there is error in other core, this loop will endless
          timeout is not needed, as when OS not start,  error can not be report,  and shutdown/shutdown-all can not be called
          so we just loop here and wait for watch dog reset
        */
        /*PRQA S 2481,2488,3892 ++*/
        /* "Os_CoreState" will be modified by other cores for multicore. */
        while(Os_CoreState[OS_PL_MASTER_COREID] != OS_CORE_START) 
        {
            /* Use OS_PL_NOP() to avoid compiler optimize to dead cycle */
            OS_PL_NOP();
        }
        /*PRQA S 2481,2488,3892 --*/
    }
    else
    {
        Os_CoreSyn[CoreID] = OS_CORE_START;
        /* synchronization before OS kernel first schedule */
        /*first master wait for other start, if there is error in other core, this loop will endless
          timeout is not needed, as when OS not start,  error can not be report,  and shutdown/shutdownall can not be called 
          so we just loop here and wait for watchdog reset
        */
        SynFlag = OS_FALSE;

        while(OS_FALSE == SynFlag)
        {
            /* Use OS_PL_NOP() to avoid compiler optimize to dead cycle */
            OS_PL_NOP();
            SynFlag = OS_TRUE;
            for(i = (CoreIdType)0; i < (CoreIdType)OS_USED_CORE_NUMBER; i++)
            {
                if((Os_CoreSyn[i] != OS_CORE_START) && (i != OS_PL_MASTER_COREID))
                {
                    SynFlag = OS_FALSE;
                    break;
                }
            }
        }

        /* all slave core ready, check appmode of different core */
#if(OS_STATUS_LEVEL == OS_EXTENDED)
#if(OS_APPMODE_NUMBER > 1)
        tempAppMode = Os_ActiveAppMode[(Os_uint32)OS_PL_MASTER_COREID];
        for(i = (CoreIdType)0; i < (CoreIdType)OS_USED_CORE_NUMBER; i++)
        {
            if(Os_ActiveAppMode[i] != tempAppMode)
            {
                /* endless loop, in mulicore prj,  finally this will lead syn startup failed*/
                /*PRQA S 2740++*/
                /* Dead loop is acceptable here. */
                while(OS_TRUE)
                {
                }
                /*PRQA S 2740 ++*/
            }
        }
#endif /*(OS_APPMODE_NUMBER > 1)*/
#endif /*f(OS_STATUS_LEVEL == OS_EXTENDED)*/
        /* master core is last core start, after that, all cores begin to schedule*/
        Os_CoreState[CoreID] = OS_CORE_START;
    }
    OsHook_StartupHook(CoreID);
#if(OS_OSAPP_STARTUPHOOK_SUPPORT == OS_ON)
    endAppId = Os_CoreCfg[CoreID].startAppId + Os_CoreCfg[CoreID].appNum;
    for(appIndex = Os_CoreCfg[CoreID].startAppId; appIndex < endAppId; appIndex++)
    {
        OsHook_AppStartupHook(CoreID, appIndex);
    }

    OsKernel_CoreSynAppStartup[CoreID] = OS_CORE_START;
    SynFlag = OS_FALSE;
    while(OS_FALSE == SynFlag)
    {
        /* Use OS_PL_NOP() to avoid compiler optimize to dead cycle */
        OS_PL_NOP();
        SynFlag = OS_TRUE;
        for(i = (CoreIdType)0; i < (CoreIdType)OS_USED_CORE_NUMBER; i++)
        {
            if(OsKernel_CoreSynAppStartup[i] != OS_CORE_START) 
            {
                SynFlag = OS_FALSE;
                break;
            }
        }
    }
#endif /*(OS_OSAPP_STARTUPHOOK_SUPPORT == OS_ON)*/
}
#else
STATIC FUNC(void, OS_CODE) OsKernel_SynStartUp
(
    CoreIdType CoreID
)
{
#if(OS_OSAPP_STARTUPHOOK_SUPPORT == OS_ON)
    ApplicationType appIndex;
    ApplicationType endAppId = Os_CoreCfg[CoreID].startAppId + Os_CoreCfg[CoreID].appNum;
#endif /*(OS_OSAPP_STARTUPHOOK_SUPPORT == OS_ON)*/
    Os_CoreState[CoreID] = OS_CORE_START;
    OsHook_StartupHook(CoreID);
#if(OS_OSAPP_STARTUPHOOK_SUPPORT == OS_ON)
    for(appIndex = Os_CoreCfg[CoreID].startAppId;  appIndex < endAppId; appIndex++)
    {
        OsHook_AppStartupHook(CoreID, appIndex);
    }
#endif /*(OS_OSAPP_STARTUPHOOK_SUPPORT == OS_ON)*/
}
#endif /*(OS_USED_CORE_NUMBER > 1)*/


/* BEGIN_FUNCTION_HDR
***********************************************************************************************
* Function Name: OsKernel_SetTaskPriReadyTable
*
* Description:   Used in OsKernel_InsertTask
*
* Inputs:        CoreID,priority
*
* Outputs:       None
*
* Limitations:   None
***********************************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, OS_CODE) OsKernel_SetTaskPriReadyTable
(
    CoreIdType CoreID,
    Os_PrioType priority
)
{
    P2CONST(Os_TaskPriReadyTblCfgType, AUTOMATIC, OS_CONST) temp_pTable_cp = &Os_CoreCfg[CoreID].taskPriReadyTableCfg;
    Os_uint8 pTable_Index;
    Os_uint8 pTable_offset;

    pTable_Index = (Os_uint8)(priority >> OS_PRI_SHIFT_VALUE);
    pTable_offset = (Os_uint8)(priority & OS_PRI_MASK_VALUE);

    /* set priority ready table line bit 1*/
    *temp_pTable_cp->p_table_line |= ((Os_uint32)1 << pTable_Index);
    /* set priority ready table bit 1*/
    temp_pTable_cp->p_table[pTable_Index] |= ((Os_uint32)1 << pTable_offset);
}

/* BEGIN_FUNCTION_HDR
***********************************************************************************************
* Function Name: OsKernel_ClearTaskPriReadyTable
*
* Description:   Used in OsKernel_RemoveTask and OsKernel_KillTask
*
* Inputs:        CoreID,priority
*
* Outputs:       None
*
* Limitations:   None
***********************************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, OS_CODE) OsKernel_ClearTaskPriReadyTable
(
    CoreIdType CoreID,
    Os_PrioType priority
)
{
    P2CONST(Os_TaskPriReadyTblCfgType, AUTOMATIC, OS_CONST) temp_pTable_cp = &Os_CoreCfg[CoreID].taskPriReadyTableCfg;
    Os_uint8 pTable_Index;
    Os_uint8 pTable_offset;

    pTable_Index = (Os_uint8)(priority >> OS_PRI_SHIFT_VALUE);
    pTable_offset = (Os_uint8)(priority & OS_PRI_MASK_VALUE);

    /* set priority ready table bit 0*/
    temp_pTable_cp->p_table[pTable_Index] &= ~((Os_uint32)1 << pTable_offset);

    if(temp_pTable_cp->p_table[pTable_Index] == (Os_uint32)0)
    {
        /*if all pri of this line clear,  set priority ready table line bit 0*/
        *temp_pTable_cp->p_table_line &= ~((Os_uint32)1 << pTable_Index);
    }

}

/* BEGIN_FUNCTION_HDR
***********************************************************************************************
* Function Name: OsKernel_GetHighestPriLine
*
* Description:   update the highest task priority when task end
*
* Inputs:        CoreID
*
* Outputs:       None
*
* Limitations:   None
***********************************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(Os_uint8, OS_CODE) OsKernel_GetHighestPriLine
(
    Os_uint32 value
)
{
    Os_uint8 OsprioRow = (Os_uint8)0; /* Define a temporary variable to figure out the priority of certain row. */
    Os_uint32 tempValue = value;

    if ((Os_uint32)0 == (tempValue & OS_DATA_MASK_FFFF)) /* if no tasks hold the higher prioritie levels. */
    {
        /*MISRA RULE 12.8 not violated:
             this value is a 32bit integer, the operation aim to get its higher 16bit.*/
        tempValue >>= (Os_uint32)OS_DATA_SHIFT_SIXTEEN; /* Right shift of low priority bits (high bits in the row). */
        OsprioRow = (Os_uint8)OS_DATA_SHIFT_SIXTEEN;
    }

    tempValue &= OS_DATA_MASK_FFFF;

    /*PRQA S 3383 ++*/
    /* "OsprioRow" is (uint32)0 and add with macros that can not reach the limit. */
    if ((Os_uint32)0 == (tempValue & OS_DATA_MASK_00FF))
    {
        tempValue >>= (Os_uint32)OS_DATA_SHIFT_EIGHT;
        OsprioRow += ((Os_uint8)OS_DATA_SHIFT_EIGHT);
    }

    tempValue &= OS_DATA_MASK_00FF;

    if ((Os_uint32)0 == (tempValue & OS_DATA_MASK_000F))
    {
        tempValue >>= (Os_uint32)OS_DATA_SHIFT_FOUR;
        OsprioRow += ((Os_uint8)OS_DATA_SHIFT_FOUR);
    }
    /*PRQA S 3383 --*/

    tempValue &= OS_DATA_MASK_000F;

    return (OsprioRow + OsKernel_PrioTransMap[tempValue]);
}

/* BEGIN_FUNCTION_HDR
***********************************************************************************************
* Function Name: OsKernel_UpdateTaskHighestPri
*
* Description:   update the highest task priority when task end. only call when remove and kill task
*
* Inputs:        CoreID,removePri
*
* Outputs:       StatusType
*
* Limitations:   None
***********************************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, OS_CODE) OsKernel_UpdateTaskHighestPri
(
    CoreIdType CoreID,
    Os_PrioType removePri
)
{
    P2CONST(Os_TaskPriReadyTblCfgType, AUTOMATIC, OS_CONST) temp_pTable_cp = &Os_CoreCfg[CoreID].taskPriReadyTableCfg;
    P2CONST(Os_TaskQueCfgType, AUTOMATIC, OS_CONST) temp_pQue_cp;


    Os_uint32 tempLineValue;
    Os_uint16 templine = (Os_uint16)0;
    Os_uint8 templineOffset;


    /* if task's priority just removed lower than the OsKernel_HighestTaskPri
     * dont need to update
     * */
    if(OsKernel_HighestTaskPri[CoreID] < removePri)
    {
        return;
    }

    tempLineValue = *(temp_pTable_cp->p_table_line);

    /*tempLineValue can noty be 0, as IDLE task always set */
    if((Os_uint32)0 == tempLineValue)
    {
        OsHook_FataErrReport(CoreID, E_OS_SYSFATA_READYQUEUE, OSServiceId_OsKernel_UpdateTaskHighestPri, OS_IE_READYQUEUE_EMPTY, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR);
        return;
    }

    if(temp_pTable_cp->p_table_size > (Os_uint8)1)
    {
        templine = OsKernel_GetHighestPriLine(tempLineValue);
    }

    tempLineValue = temp_pTable_cp->p_table[templine];

    if((Os_uint32)0 == tempLineValue)
    {
        OsHook_FataErrReport(CoreID, E_OS_SYSFATA_READYQUEUE, OSServiceId_OsKernel_UpdateTaskHighestPri, OS_IE_READYQUEUE_EMPTY, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR);
        return;
    }

    templineOffset = OsKernel_GetHighestPriLine(tempLineValue);

    /*PRQA S 4571,3383 ++*/
    /* Confirmed that overflow is impossible. */
    OsKernel_HighestTaskPri[CoreID] = (Os_PrioType)(templine << OS_PRI_SHIFT_VALUE);
    OsKernel_HighestTaskPri[CoreID] += (Os_PrioType)templineOffset;
    /*PRQA S 4571,3383 --*/

    temp_pQue_cp = &Os_CoreCfg[CoreID].taskQueCfg[OsKernel_HighestTaskPri[CoreID]];

#if(OS_RESOURCE_NUMBER > 0)
    if(temp_pQue_cp->cellingTaskPtr[0] != OS_INVALID_TASK_ID)
    {
        OsKernel_HighestTaskId[CoreID] = temp_pQue_cp->cellingTaskPtr[0];
    }

    else
#endif /*(OS_RESOURCE_NUMBER > 0)*/
    {
#if((OS_CC == OS_BCC2) || (OS_CC == OS_ECC2))
        if(temp_pQue_cp->Q_Ctl_Ptr == OS_NULL)
#endif /*((OS_CC == OS_BCC2) || (OS_CC == OS_ECC2))*/
        {
            OsKernel_HighestTaskId[CoreID] = temp_pQue_cp->Q_Buf[0];
        }
#if((OS_CC == OS_BCC2) || (OS_CC == OS_ECC2))
        else
        {
            OsKernel_HighestTaskId[CoreID] = temp_pQue_cp->Q_Buf[temp_pQue_cp->Q_Ctl_Ptr->Os_Q_rear];
        }
#endif /*((OS_CC == OS_BCC2) || (OS_CC == OS_ECC2))*/
    }
}

/*****************************************************************************
* OS internal code
******************************************************************************/

/* BEGIN_FUNCTION_HDR
***********************************************************************************************
* Function Name: OsKernel_CheckCpuLoad
*
* Description:   called when enter or leave idle Task
*
*
* Inputs:        CoreID, isPreempt, nextState
*
* Outputs:       None
*
* Limitations:  OutC2Isr do not call this function
***********************************************************************************************
END_FUNCTION_HDR*/
#if(OS_CPULOAD_API == OS_ON)
FUNC(void, OS_CODE) OsKernel_CheckCpuLoad
(
    CoreIdType CoreID,
    Os_boolean isIdleStart
)
{
    Os_CpuLoadTickType dtimerVal;

    /* enter idle start , just record the start time*/
    if(OS_TRUE == isIdleStart)
    {
        /*PRQA S 0303,3383 ++*/
        /*
        "OsCpuLoadTimer_GetTimer" will get access register, so must "volatile" inside.
        Value from register can not overflow.
        */
        OsKernel_IdleStartTime[CoreID] = (Os_CpuLoadTickType)OsCpuLoadTimer_GetTimer(CoreID);
        /*PRQA S 0303,3383 --*/
        return;
    }

    dtimerVal = (Os_CpuLoadTickType)OsCpuLoadTimer_GetElapsedTime(CoreID, OsKernel_IdleStartTime[CoreID]);

    /*PRQA S 3383 ++*/
    /* no need to check the overflow of OsKernel_IdleRunTime*/
    OsKernel_IdleRunTime[CoreID] = OsKernel_IdleRunTime[CoreID] + dtimerVal;
    /*PRQA S 3383 --*/
}
#endif /*(OS_CPULOAD_API == OS_ON)*/

/* BEGIN_FUNCTION_HDR
***********************************************************************************************
* Function Name: OsKernel_NeedSchedule
*
* Description:   Used in AutoStartTask, outISR,Task end and Schedule API. to check if need re-schedule
*
* Inputs:        CoreID,isEnforce
*
* Outputs:       None
*
* Limitations:   None
***********************************************************************************************
END_FUNCTION_HDR*/
FUNC(Os_boolean, OS_CODE) OsKernel_NeedSchedule
(
    CoreIdType CoreID,
    Os_boolean isEnforce
)
{
    P2CONST(Os_TaskCfgType, AUTOMATIC, OS_CONST) temp_Tcb_cp;

    Os_PrioType currentPri;

    /* this is necessary, in startos this function will also be called for auto start task
     * where can not trigger schedule
     * if in C2 or C1 ISR , cannot schedule either
     */
    if((Os_CoreState[CoreID] != OS_CORE_START) || (Os_CurrentContext[CoreID] == OS_CONTEXT_C2ISR) || \
    (Os_CurrentContext[CoreID] == OS_CONTEXT_C1ISR))
    {
        return OS_FALSE;
    }

    /* if int resource lock , cannot schedule*/
#if(OS_SHARE_RESOURCE_NUMBER > 0)
    if(Os_IntResLockDepth[CoreID] > (Os_uint8)0)
    {
        return OS_FALSE;
    }
#endif /*(OS_SHARE_RESOURCE_NUMBER > 0)*/

#if(OS_SPINKLOCK_LOCKSCH_SUPPORT == OS_ON)
    /* spinlock lock scheduler*/
    if(Os_SpinlockDepth[CoreID] > (Os_uint8)0)
    {
        return OS_FALSE;
    }
#endif /*(OS_SPINKLOCK_LOCKSCH_SUPPORT == OS_ON)*/

    /*after task removed or killed,  current task may invalid
     * in this case , like IDLE task running , this API should return true
     * */
    if(OS_INVALID_TASK_ID == Os_CurrentTaskId[CoreID])
    {
        return OS_TRUE;
    }

    temp_Tcb_cp = &Os_TaskCfg[Os_CurrentTaskId[CoreID]];

    currentPri = temp_Tcb_cp->OsTaskCfgPrio;

#if(OS_RESOURCE_NUMBER > 0)
    /* if has celling priority, set to it*/
    if(Os_TaskCBTable[Os_CurrentTaskId[CoreID]].OsCellingTaskPri < currentPri)
    {
        currentPri = Os_TaskCBTable[Os_CurrentTaskId[CoreID]].OsCellingTaskPri;
    }
#endif /*(OS_RESOURCE_NUMBER > 0)*/

    if(OS_FALSE == isEnforce)
    {
        if(temp_Tcb_cp->isPreemptable == OS_FALSE)
        {
            return OS_FALSE;
        }

        if(OsKernel_HighestTaskPri[CoreID] < currentPri)
        {
            return OS_TRUE;
        }
    }
    else
    {
        if(OsKernel_HighestTaskPri[CoreID] < currentPri)
        {
            return OS_TRUE;
        }
    }

    return OS_FALSE;
}


#if(OS_RESOURCE_NUMBER > 0)
/*
    Special process when get and release resouce, celling priorit related
*/

/* BEGIN_FUNCTION_HDR
***********************************************************************************************
* Function Name: OsKernel_InsertResCellingTask
*
* Description:   insert an virtual task into ready table when rising celling priority
*
* Inputs:        CoreID,TaskID,  taskPriority
*
* Outputs:       None
*
* Limitations:   None
***********************************************************************************************
END_FUNCTION_HDR*/
FUNC(void, OS_CODE) OsKernel_InsertResCellingTask
(
    CoreIdType CoreID,
    TaskType TaskID,
    Os_PrioType taskPriority 
)
{
    P2CONST(Os_TaskQueCfgType, AUTOMATIC, OS_CONST) temp_Q_cp = &Os_CoreCfg[CoreID].taskQueCfg[taskPriority];
    OsKernel_SetTaskPriReadyTable(CoreID, taskPriority);
    *temp_Q_cp->cellingTaskPtr = TaskID;
}

/* BEGIN_FUNCTION_HDR
***********************************************************************************************
* Function Name: OsKernel_RemoveResCellingTask
*
* Description:   remve an virtual task from ready table when falling celling priority
*
* Inputs:        CoreID,TaskID,  taskPriority
*
* Outputs:       None
*
* Limitations:   None
***********************************************************************************************
END_FUNCTION_HDR*/
FUNC(void, OS_CODE) OsKernel_RemoveResCellingTask
(
    CoreIdType CoreID,
    TaskType TaskID,
    Os_PrioType taskPriority 
)
{
    P2CONST(Os_TaskQueCfgType, AUTOMATIC, OS_CONST) temp_Q_cp = &Os_CoreCfg[CoreID].taskQueCfg[taskPriority];
#if((OS_CC == OS_ECC2) || (OS_CC == OS_BCC2))
    P2VAR(Os_TaskQueueCtlType, AUTOMATIC, OS_VAR) temp_Q_vp;
#endif /*((OS_CC == OS_ECC2) || (OS_CC == OS_BCC2))*/
    P2VAR(TaskType, AUTOMATIC, OS_VAR) temp_Q_buf;
#if((OS_CC == OS_ECC2) || (OS_CC == OS_BCC2))
    temp_Q_vp = temp_Q_cp->Q_Ctl_Ptr;
#endif /*((OS_CC == OS_ECC2) || (OS_CC == OS_BCC2))*/

    temp_Q_buf = temp_Q_cp->Q_Buf;
    /* when auto release, may not equal*/
    if(*temp_Q_cp->cellingTaskPtr == TaskID)
    {
        *temp_Q_cp->cellingTaskPtr = OS_INVALID_TASK_ID;
#if((OS_CC == OS_ECC2) || (OS_CC == OS_BCC2))
        if (temp_Q_vp != NULL_PTR) /* has queue for this priority*/
        {
            if(temp_Q_vp->Os_Q_rear == OS_TASK_QUEUE_INVALID_INDEX)
            {
                OsKernel_ClearTaskPriReadyTable(CoreID, taskPriority);
            }
        }
        else
#endif /*((OS_CC == OS_ECC2) || (OS_CC == OS_BCC2))*/
        {
            if(temp_Q_buf[0] == OS_INVALID_TASK_ID)
            {
                OsKernel_ClearTaskPriReadyTable(CoreID, taskPriority);
            }
        }
        OsKernel_UpdateTaskHighestPri(CoreID, taskPriority);
    }
}
#endif /*(OS_RESOURCE_NUMBER > 0)*/

/* BEGIN_FUNCTION_HDR
***********************************************************************************************
* Function Name: OsKernel_InsertTask
*
* Description:   Used when new task activate
*
* Inputs:        CoreID,TaskID-- TaskID is global task id.
*
* Outputs:       None
*
* Limitations:   None
***********************************************************************************************
END_FUNCTION_HDR*/
FUNC(void, OS_CODE) OsKernel_InsertTask
(
    CoreIdType CoreID,
    TaskType TaskID
)
{
    P2CONST(Os_TaskCfgType, AUTOMATIC, OS_CONST) temp_Tcb_cp = &Os_TaskCfg[TaskID];
    Os_PrioType taskPriority = temp_Tcb_cp->OsTaskCfgPrio;
    P2CONST(Os_TaskQueCfgType, AUTOMATIC, OS_CONST) temp_Q_cp = &Os_CoreCfg[CoreID].taskQueCfg[taskPriority];
    P2VAR(TaskType, AUTOMATIC, OS_VAR) temp_Q_buf = temp_Q_cp->Q_Buf;


#if((OS_CC == OS_ECC2) || (OS_CC == OS_BCC2))
    P2VAR(Os_TaskQueueCtlType, AUTOMATIC, OS_VAR) temp_Q_vp = temp_Q_cp->Q_Ctl_Ptr;
#endif /*((OS_CC == OS_ECC2) || (OS_CC == OS_BCC2))*/

 /* Add a task to ready queue */
#if((OS_CC == OS_ECC2) || (OS_CC == OS_BCC2))
    if (temp_Q_vp != NULL_PTR) /* has queue for this priority*/
    {
        /* check queue full or not*/
        if(temp_Q_vp->Os_Q_front == OS_TASK_QUEUE_INVALID_INDEX)
        {
            /* Error check. */
            OsHook_FataErrReport(CoreID, E_OS_SYSFATA_READYQUEUE, OSServiceId_OsKernel_InsertTask, OS_IE_READYQUEUE_FULL, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR);
        }

        /*if queue is empty before, set rear to 0 after add new task*/
        if(temp_Q_vp->Os_Q_rear == OS_TASK_QUEUE_INVALID_INDEX)
        {
            temp_Q_vp->Os_Q_rear = (Os_uint16)0;
        }

        temp_Q_buf[temp_Q_vp->Os_Q_front] = TaskID;/* insert new task*/
        OsKernel_SetTaskPriReadyTable(CoreID, taskPriority);

        if(taskPriority < OsKernel_HighestTaskPri[CoreID])
        {
            OsKernel_HighestTaskPri[CoreID] = taskPriority;
            OsKernel_HighestTaskId[CoreID] = temp_Q_buf[temp_Q_vp->Os_Q_rear];
        }

        /*
        move front, if exceed the que size, roll back
        check with rear, if full, set queue full
        */
        /*PRQA S 3383 ++*/
        /*
        Can not overflow because there is comparison with max value after this statement
        */
        temp_Q_vp->Os_Q_front++;
        /*PRQA S 3383 --*/
        if(temp_Q_vp->Os_Q_front >= temp_Q_cp->Q_Size)
        {
            temp_Q_vp->Os_Q_front = (Os_uint16)0;
        }
        if(temp_Q_vp->Os_Q_front == temp_Q_vp->Os_Q_rear)
        {
            temp_Q_vp->Os_Q_front = OS_TASK_QUEUE_INVALID_INDEX;
        }
    }
    else
#endif /*((OS_CC == OS_ECC2) || (OS_CC == OS_BCC2))*/
    /*task process when no queue for this priority*/
    {
        /*For OS class ECC1 and BCC1, one priority can only correspond to one task at most.*/
        if(temp_Q_buf[0] == OS_INVALID_TASK_ID)
        {
            temp_Q_buf[0] = TaskID;/* insert new task*/
            OsKernel_SetTaskPriReadyTable(CoreID, taskPriority);

            if(taskPriority < OsKernel_HighestTaskPri[CoreID])
            {
                OsKernel_HighestTaskPri[CoreID] = taskPriority;
                OsKernel_HighestTaskId[CoreID] = TaskID;
            }
        }
    }
}


/* BEGIN_FUNCTION_HDR
***********************************************************************************************
* Function Name: OsKernel_RemoveTask
*
* Description:   Used when running task end
*
* Inputs:        CoreID,TaskID-- TaskID is global task id.
*
* Outputs:       StatusType
*
* Limitations:   None
***********************************************************************************************
END_FUNCTION_HDR*/
FUNC(void, OS_CODE) OsKernel_RemoveTask
(
    CoreIdType CoreID,
    TaskType TaskID
)
{
    P2CONST(Os_TaskCfgType, AUTOMATIC, OS_CONST) temp_Tcb_cp;
    Os_PrioType taskPriority;
    P2CONST(Os_TaskQueCfgType, AUTOMATIC, OS_CONST) temp_Q_cp;
    P2VAR(TaskType, AUTOMATIC, OS_VAR) temp_Q_buf;

#if((OS_CC == OS_ECC2) || (OS_CC == OS_BCC2))
    P2VAR(Os_TaskQueueCtlType, AUTOMATIC, OS_VAR) temp_Q_vp;
#endif /*((OS_CC == OS_ECC2) || (OS_CC == OS_BCC2))*/

    temp_Tcb_cp = &Os_TaskCfg[TaskID];
    taskPriority = temp_Tcb_cp->OsTaskCfgPrio;
    temp_Q_cp = &Os_CoreCfg[CoreID].taskQueCfg[taskPriority];
    temp_Q_buf = temp_Q_cp->Q_Buf;

#if((OS_CC == OS_ECC2) || (OS_CC == OS_BCC2))
    temp_Q_vp = temp_Q_cp->Q_Ctl_Ptr;
#endif /*((OS_CC == OS_ECC2) || (OS_CC == OS_BCC2))*/

    /* not possible that the highest task pri > current task pri*/
    if(OsKernel_HighestTaskPri[CoreID] > taskPriority)
    {
        /* Error check. */
        OsHook_FataErrReport(CoreID, E_OS_SYSFATA_READYQUEUE, OSServiceId_OsKernel_RemoveTask, OS_IE_READYQUEUE_DATAERR, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR);
    }

    /* Remove a task from ready queue */
#if((OS_CC == OS_ECC2) || (OS_CC == OS_BCC2))
    if (temp_Q_vp != NULL_PTR) /* has queue for this priority*/
    {
        /* check queue empty or not*/
        if(temp_Q_vp->Os_Q_rear == OS_TASK_QUEUE_INVALID_INDEX)
        {
            OsHook_FataErrReport(CoreID, E_OS_SYSFATA_READYQUEUE, OSServiceId_OsKernel_RemoveTask, OS_IE_READYQUEUE_DATAERR, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR);
        }

        if(temp_Q_buf[temp_Q_vp->Os_Q_rear] != TaskID)
        {
            OsHook_FataErrReport(CoreID, E_OS_SYSFATA_READYQUEUE, OSServiceId_OsKernel_RemoveTask, OS_IE_READYQUEUE_DATAERR, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR);
        }

        /*if queue is full before, set front to rear after remove*/
        if(temp_Q_vp->Os_Q_front == OS_TASK_QUEUE_INVALID_INDEX)
        {
            temp_Q_vp->Os_Q_front = temp_Q_vp->Os_Q_rear;
        }
        /*PRQA S 3383 ++*/
        /*
        Can not overflow because there is comparison with max value after this statement
        */
        temp_Q_vp->Os_Q_rear++; /*remove task from queue*/
        /*PRQA S 3383 --*/
        if(temp_Q_vp->Os_Q_rear >= temp_Q_cp->Q_Size)
        {
            temp_Q_vp->Os_Q_rear = (Os_uint16)0;
        }
        /* if queue empty after remove, clear this priority and reset queue*/
        if(temp_Q_vp->Os_Q_front == temp_Q_vp->Os_Q_rear)
        {
            OsKernel_ClearTaskPriReadyTable(CoreID, taskPriority);
            temp_Q_vp->Os_Q_front = (Os_uint16)0;
            temp_Q_vp->Os_Q_rear = OS_TASK_QUEUE_INVALID_INDEX;
        }
        OsKernel_UpdateTaskHighestPri(CoreID, taskPriority);
    }
    else
#endif /*((OS_CC == OS_ECC2) || (OS_CC == OS_BCC2))*/
    {
        /*task process when no queue for this priority*/
        if(temp_Q_buf[0] == TaskID)
        {
            temp_Q_buf[0] = OS_INVALID_TASK_ID;
            OsKernel_ClearTaskPriReadyTable(CoreID, taskPriority);
            OsKernel_UpdateTaskHighestPri(CoreID, taskPriority);
        }
        else
        {
            /* err state*/
            OsHook_FataErrReport(CoreID, E_OS_SYSFATA_READYQUEUE, OSServiceId_OsKernel_RemoveTask, OS_IE_READYQUEUE_DATAERR, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR);
        }
    }
}

/* BEGIN_FUNCTION_HDR
***********************************************************************************************
* Function Name: OsKernel_KillTask
*
* Description:   Used when kill task or application
*
* Inputs:        CoreID,TaskID-- TaskID is global task id.
*
* Outputs:       StatusType
*
* Limitations:   None
***********************************************************************************************
END_FUNCTION_HDR*/
FUNC(void, OS_CODE) OsKernel_KillTask
(
    CoreIdType CoreID,
    TaskType TaskID
)
{
    P2CONST(Os_TaskCfgType, AUTOMATIC, OS_CONST) temp_Tcb_cp;
    Os_PrioType taskPriority;
    P2CONST(Os_TaskQueCfgType, AUTOMATIC, OS_CONST) temp_Q_cp;
    P2VAR(TaskType, AUTOMATIC, OS_VAR) temp_Q_buf;

#if((OS_CC == OS_ECC2) || (OS_CC == OS_BCC2))
    Os_uint16 tempPutQueIndex;
    Os_uint16 tempQueIndex;
#endif /*((OS_CC == OS_ECC2) || (OS_CC == OS_BCC2))*/

#if((OS_CC == OS_ECC2) || (OS_CC == OS_BCC2))
    P2VAR(Os_TaskQueueCtlType, AUTOMATIC, OS_VAR) temp_Q_vp;
#endif /*((OS_CC == OS_ECC2) || (OS_CC == OS_BCC2))*/

    temp_Tcb_cp = &Os_TaskCfg[TaskID];
    taskPriority = temp_Tcb_cp->OsTaskCfgPrio;
    temp_Q_cp = &Os_CoreCfg[CoreID].taskQueCfg[taskPriority];
    temp_Q_buf = temp_Q_cp->Q_Buf;

#if((OS_CC == OS_ECC2) || (OS_CC == OS_BCC2))
    temp_Q_vp = temp_Q_cp->Q_Ctl_Ptr;
#endif /*((OS_CC == OS_ECC2) || (OS_CC == OS_BCC2))*/

    /* Remove a task from ready queue */
#if((OS_CC == OS_ECC2) || (OS_CC == OS_BCC2))
    if (temp_Q_vp != NULL_PTR) /* has queue for this priority*/
    {
        /* check queue empty or not*/
        if(temp_Q_vp->Os_Q_rear == OS_TASK_QUEUE_INVALID_INDEX)
        {
            /* task not ready, no need kill */
            return;
        }

        if(temp_Q_vp->Os_Q_front == OS_TASK_QUEUE_INVALID_INDEX)
        {
            /* task queue full, set front to rear */
            temp_Q_vp->Os_Q_front = temp_Q_vp->Os_Q_rear;
        }

        /* seach all queue, if has the TaskID, delete it*/
        tempQueIndex = temp_Q_vp->Os_Q_rear;
        tempPutQueIndex = temp_Q_vp->Os_Q_rear;
        do
        {
            if(temp_Q_buf[tempQueIndex] == TaskID)
            {
                /*PRQA S 3383 ++*/
                /*
                Can not overflow because there is comparison with max value after this statement
                */
                tempQueIndex++;
                /*PRQA S 3383 --*/
            }
            else
            {
                temp_Q_buf[tempPutQueIndex] = temp_Q_buf[tempQueIndex];
                /*PRQA S 3383 ++*/
                /*
                Can not overflow because there is comparison with max value after this statement
                */
                tempQueIndex++;
                tempPutQueIndex++;
                /*PRQA S 3383 --*/
            }

            if(tempQueIndex >= temp_Q_cp->Q_Size)
            {
                tempQueIndex = (Os_uint16)0;
            }
            if(tempPutQueIndex >= temp_Q_cp->Q_Size)
            {
                tempPutQueIndex = (Os_uint16)0;
            }
        }while(tempQueIndex != temp_Q_vp->Os_Q_front);
        /*if delete all reset queue*/
        if(tempPutQueIndex == temp_Q_vp->Os_Q_rear)
        {
            OsKernel_ClearTaskPriReadyTable(CoreID, taskPriority);
            temp_Q_vp->Os_Q_front = (Os_uint16)0;
            temp_Q_vp->Os_Q_rear = OS_TASK_QUEUE_INVALID_INDEX;
        }
        else
        {
            temp_Q_vp->Os_Q_front = tempPutQueIndex;
        }
        /* re caculate the highest pri after kill*/
        OsKernel_UpdateTaskHighestPri(CoreID, taskPriority);
    }
    else
#endif /*((OS_CC == OS_ECC2) || (OS_CC == OS_BCC2))*/
    /*task process when no queue for this priority*/
    {
        if(temp_Q_buf[0] == TaskID)
        {
            temp_Q_buf[0] = OS_INVALID_TASK_ID;
            OsKernel_ClearTaskPriReadyTable(CoreID, taskPriority);
            OsKernel_UpdateTaskHighestPri(CoreID, taskPriority);
        }
    }
    /* task not ready, no need kill */
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: OsKernel_InternalShutdown
*
* Description:   Internal shutdown, called from shutdown or shutdownAllCores
*
* Inputs:        CoreID, Error
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, OS_CODE) OsKernel_InternalShutdown
(
    CoreIdType CoreID,
    StatusType Error,
    ShutdownConceptType ShutdownType
)
{

#if(OS_OSAPP_SHUTDOWNHOOK_SUPPORT == OS_ON)
    ApplicationType appIndex;
    ApplicationType endAppId;
#endif /*(OS_OSAPP_SHUTDOWNHOOK_SUPPORT == OS_ON)*/
#if(OS_USED_CORE_NUMBER > 1)
    CoreIdType index;
    Os_boolean SynFlag;
#endif /* (OS_USED_CORE_NUMBER > 1) */

#if(OS_USED_CORE_NUMBER > 1)
    SynFlag = OS_FALSE;
#endif /* (OS_USED_CORE_NUMBER > 1) */
    /*PRQA S 0303,3383,3442 ++*/
    /* "OsSysTimer_Stop" will access register, so must be "volatile" inside. */
    OsSysTimer_Stop(CoreID);
    /*PRQA S 0303,3383,3442 --*/
#if(OS_ON == OS_TP_TIMER_NEED)
    OsTpTimer_Stop(CoreID);
#endif /*(OS_ON == OS_TP_TIMER_NEED)*/
#if(OS_ON == OS_TP_FCTIMER_NEED)
    OsTpFcTimer_Stop(CoreID);
#endif /*(OS_ON == OS_TP_FCTIMER_NEED)*/
#if(OS_CPULOAD_API == OS_ON)
    OsCpuLoadTimer_Stop(CoreID);
#endif /*(OS_CPULOAD_API == OS_ON)*/

    OsMpu_Disable(CoreID);

#if(OS_OSAPP_SHUTDOWNHOOK_SUPPORT == OS_ON)
    endAppId = Os_CoreCfg[CoreID].startAppId + Os_CoreCfg[CoreID].appNum;

    for(appIndex = Os_CoreCfg[CoreID].startAppId; appIndex < endAppId; appIndex++)
    {
        OsHook_AppShutdownHook(CoreID, E_OS_SYS_SHUTDOWN_BY_TERMINATE_APP, appIndex);
    }
#endif /*(OS_OSAPP_SHUTDOWNHOOK_SUPPORT == OS_ON)*/
#if(OS_USED_CORE_NUMBER > 1)
    /* SWS_Os_00587 */
    if (SYNCHRONIZED_SHUTDOWN == ShutdownType)
    {
        if (CoreID != OS_PL_MASTER_COREID)
        {
            Os_CoreSyn[CoreID] = OS_CORE_IDLE;

            /*PRQA S 2481,2488,3892 ++*/
            /* "Os_CoreState" will be modified by other cores for multicore. */
            while (Os_CoreSyn[OS_PL_MASTER_COREID] != OS_CORE_IDLE) 
            {
                /* Use OS_PL_NOP() to avoid compiler optimize to dead cycle. */
                OS_PL_NOP();
            }
            /*PRQA S 2481,2488,3892 --*/
        }
        else
        {
            SynFlag = OS_FALSE;

            while (OS_FALSE == SynFlag)
            {
                /* Use OS_PL_NOP() to avoid compiler optimize to dead cycle. */
                OS_PL_NOP();
                SynFlag = OS_TRUE;
                for (index = (CoreIdType)0; index < (CoreIdType)OS_USED_CORE_NUMBER; index++)
                {
                    if ((Os_CoreSyn[index] != OS_CORE_IDLE) && (index != OS_PL_MASTER_COREID))
                    {
                        SynFlag = OS_FALSE;
                        break;
                    }
                }
            }
            Os_CoreSyn[CoreID] = OS_CORE_IDLE;
        }
    }
#else
    (void)ShutdownType;
#endif /* (OS_USED_CORE_NUMBER > 1) */
    
    OsHook_ShutdownHook(CoreID,Error);
    /* SWS_Os_00425 */
    /* Shutdown, just Disable interrupt */
    OsIntc_DisableGlobalInterrupt(CoreID);
    Os_CoreState[CoreID] = OS_CORE_IDLE;

#if(OS_SHUTDOWN_RESTART_SUPPORT == OS_ON)
    /* Reversed. */
#endif /* (OS_SHUTDOWN_RESTART_SUPPORT == OS_ON) */
    /* Endless loop should be mode in the calling env of this function. */
}

/* BEGIN_FUNCTION_HDR
***********************************************************************************************
* Function Name: OsKernel_InternalSetMode
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
FUNC(void, OS_CODE) OsKernel_InternalSetMode
(
    CoreIdType CoreID
)
{

    Os_boolean tempPri;
    OsCpu_EnterCritical(CoreID, &tempPri);

    if(Os_PhyCoreToLog[CoreID] != OS_INVALID_COREID)
    {
        Os_CoreState[Os_PhyCoreToLog[CoreID]] = OS_CORE_IDLE;
    }

    OsCpu_SetMode(CoreID, OS_HW_CORE_STOP);

    OsCpu_ExitCritical(CoreID, tempPri);
}

/* BEGIN_FUNCTION_HDR
***********************************************************************************************
* Function Name: OsKernel_EnterTask
*
* Description:   called when enter current task thread
*                isRestore = true: TaskSwitch or OutISR2 need to restore task
*                isRestore = false: TaskSwitch need to start a new task
*                
*
* Inputs:        CoreID, isRestore
*
* Outputs:       None
*
* Limitations:  OutC2Isr do not call this function
***********************************************************************************************
END_FUNCTION_HDR*/
FUNC(void, OS_CODE) OsKernel_EnterTask
(
    CoreIdType CoreID,
    Os_boolean isRestore
)
{
    P2VAR(Os_TaskCBType, AUTOMATIC, OS_VAR) temp_Tcb_vp;
    TaskType taskId = Os_CurrentTaskId[CoreID];

    temp_Tcb_vp = &Os_TaskCBTable[taskId]; 

#if(OS_CRC_SUPPORT == OS_ON)
    if(isRestore == OS_TRUE)
    {
        /* check CRC of saved context*/
        /*PRQA S 3416 ++*/
        /* The side effect of "OsCrc_Calculate" is expected. */
        if(temp_Tcb_vp->crcResult != OsCrc_Calculate(temp_Tcb_vp->OsTaskCtxPtr))
        /*PRQA S 3416 --*/
        {
            OsHook_FataErrReport(CoreID, E_OS_SYSFATA_CONTEXTCRC_ERR, OSServiceId_OsKernel_EnterTask, OS_IE_NOMORE_INFO, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR);
        }

    }
#endif /*(OS_CRC_SUPPORT == OS_ON)*/

    if(taskId == Os_CoreCfg[CoreID].idleTaskId)
    {
        /* for IDLE task , no time protection,  keep kernel MPU settings*/
#if(OS_APPLICATION_NUMBER > 0)
        Os_CurrentApplicationId[CoreID] = OS_INVALID_OSAPPLICATION;
#endif /*(OS_APPLICATION_NUMBER > 0)*/
        Os_CurrentContext[CoreID] = OS_CONTEXT_KERNEL;

#if(OS_CPULOAD_API == OS_ON)
        OsKernel_CheckCpuLoad(CoreID, OS_TRUE);
#endif /*(OS_CPULOAD_API == OS_ON)*/
    }
    else
    {
        if(isRestore == OS_FALSE)
        {
            OsTp_TskExecutionBudgetStart(CoreID, taskId);
            OsTp_TskTimeFrameCheck(CoreID, taskId);
        }
        else
        {            
#if((OS_CC == OS_ECC1) || (OS_CC == OS_ECC2))
            if((Os_TaskCBTable[taskId].OsTaskState == OS_TASK_WAITING_TO_READY) && \
                                (Os_TaskCfg[taskId].isExtendTask == OS_TRUE)) 
            {
                Os_TaskCBTable[taskId].OsTaskState = OS_TASK_RUNNING;
                OsTp_TskTimeFrameCheck(CoreID, taskId);
            }
#endif /*((OS_CC == OS_ECC1) || (OS_CC == OS_ECC2))*/
            OsTp_TskRestore(CoreID, taskId);
        }

#if(OS_APPLICATION_NUMBER > 0)
        Os_CurrentApplicationId[CoreID] = Os_TaskCfg[Os_CurrentTaskId[CoreID]].ApplID;
#endif /*(OS_APPLICATION_NUMBER > 0)*/
        Os_CurrentContext[CoreID] = OS_CONTEXT_TASK;
    }

    /* must set running first , then call PreTaskHook*/
    temp_Tcb_vp->OsTaskState = OS_TASK_RUNNING;
    OsHook_PreTaskHook(CoreID);/* IDLE Task also enter this hook*/
}

/* BEGIN_FUNCTION_HDR
***********************************************************************************************
* Function Name: OsKernel_ExitTask
*
* Description:   called when leave current task
*                isPreempt = true: activeTask, SetEvent, releaseRes, Schedule, InIsr2
*                isPreempt = false:TeminateTask, ChainTask, WaitEvent
*
*
* Inputs:        CoreID, isPreempt, nextState
*
* Outputs:       None
*
* Limitations:  OutC2Isr do not call this function
***********************************************************************************************
END_FUNCTION_HDR*/
FUNC(void, OS_CODE) OsKernel_ExitTask
(
    CoreIdType CoreID,
    Os_boolean isPreempt,
    TaskStateType nextState
)
{
    P2VAR(Os_TaskCBType, AUTOMATIC, OS_VAR) temp_Tcb_vp;
    TaskType taskId = Os_CurrentTaskId[CoreID];
    temp_Tcb_vp = &Os_TaskCBTable[taskId];

    /*When the task exits due to preemption, the CRC of the context needs to be calculated
      and saved. This operation is implemented by the portable layer.*/

    if(taskId == Os_CoreCfg[CoreID].idleTaskId)
    {
#if(OS_CPULOAD_API == OS_ON)
        OsKernel_CheckCpuLoad(CoreID, OS_FALSE);
#endif /*(OS_CPULOAD_API == OS_ON)*/
    }
    else
    {
        if(OS_FALSE == isPreempt)
        {
            OsTp_TskExecutionBudgetStop(CoreID, taskId);
        }
        else
        {
            OsTp_TskPause(CoreID, taskId);
        }
    }

#ifndef OS_HW_CHK_STACK_SUPPORT
#if(OS_CHK_STACK == OS_ON)
    if(Os_TaskCfg[taskId].OsTaskStkTop[0] != OS_STACKINIT_VALUE)
    {
        OsHook_FataErrReport(CoreID, E_OS_STACKFAULT, OSServiceId_OsKernel_ExitTask, OS_IE_NOMORE_INFO, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR);
    }
#endif /*(OS_CHK_STACK == OS_ON)*/
#endif

    OsHook_PostTaskHook(CoreID);

#if(OS_APPLICATION_NUMBER > 0)
    Os_CurrentApplicationId[CoreID] = OS_INVALID_OSAPPLICATION;
#endif /*f(OS_APPLICATION_NUMBER > 0)*/
    Os_CurrentContext[CoreID] = OS_CONTEXT_KERNEL;

    temp_Tcb_vp->OsTaskState = nextState;

    /* current task id will be set invalid seprately, not here*/
}

/* BEGIN_FUNCTION_HDR
***********************************************************************************************
* Function Name: OsKernel_CheckTaskSwitch
*
* Description:   called when Task need switch, check the task queue and update current taskId
*
*
* Inputs:        CoreID
*
* Outputs:       None
*
* Limitations:   None
***********************************************************************************************
END_FUNCTION_HDR*/
FUNC(void, OS_CODE) OsKernel_CheckTaskSwitch
(
    CoreIdType CoreID
)
{
    /*#Step1 check Task queue */
    if((OsKernel_HighestTaskId[CoreID] < Os_CoreCfg[CoreID].startTaskId) || \
        (OsKernel_HighestTaskId[CoreID] >= (Os_CoreCfg[CoreID].startTaskId + Os_CoreCfg[CoreID].taskNum)))
    {
        OsHook_FataErrReport(CoreID, E_OS_SYSFATA_READYQUEUE, OSServiceId_OsKernel_CheckTaskSwitch, OS_IE_NOMORE_INFO, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR);
    }

    /*#Step2 update the task*/
    Os_CurrentTaskId[CoreID] = OsKernel_HighestTaskId[CoreID];
}

/*****************************************************************************
* API code
******************************************************************************/
/* BEGIN_FUNCTION_HDR
***********************************************************************************************
* Function Name: OS_Init
*
* Description:   User should call this system service to init memory and variables befor call
*                StartOS.
*
* Inputs:        None
*
* Outputs:       None
*
* Limitations:   Call this service befor either StartOS or EcuM_Init.
***********************************************************************************************
END_FUNCTION_HDR*/
FUNC(void, OS_CODE) OS_Init
(
    void
)
{
    CoreIdType localCoreId;
    CoreIdType coreIndex;

    localCoreId = OsCpu_GetCoreID();

    if (OS_PL_MASTER_COREID == localCoreId)
    {
        /* 
         * Portable part init memory sections. 
         * ex. Clear bss sections and initialize data sections by copy. 
         * If no need to do so(ex. has been done by start-up code), just return.
         */
        /* Reserved for future. */
        /* OsCpu_MemoryInit(OS_PL_MASTER_COREID); */

        for (coreIndex = (CoreIdType)0; coreIndex < OS_USED_CORE_NUMBER; coreIndex++)
        {
            /* Kernel initialize */
            Os_CoreState[coreIndex] = OS_CORE_IDLE;
#if(OS_USED_CORE_NUMBER > 1)
            Os_CoreSyn[coreIndex] = OS_CORE_IDLE;
#endif /* (OS_USED_CORE_NUMBER > 1) */

            Os_IntNestDepth[coreIndex] = OS_INVALID_ISR;
            Os_C1IntNestDepth[coreIndex] = OS_INVALID_ISR;

            Os_IntAPIUsedFlag[coreIndex] = OS_NO_API_USED;
            OsISR_IntAPINesting[coreIndex] = (Os_uint8)0;

            Os_CurrentTaskId[coreIndex] = OS_INVALID_TASK_ID;
#if(OS_APPLICATION_NUMBER > 0)
            Os_CurrentApplicationId[coreIndex] = OS_INVALID_OSAPPLICATION;
#endif /* (OS_APPLICATION_NUMBER > 0) */

#if((OS_STATUS_LEVEL == OS_EXTENDED) || (OS_ERRORHOOK_SUPPORT == OS_ON))
            Os_ErrNestFlag[coreIndex] = OS_FALSE;
#endif /*((OS_STATUS_LEVEL == OS_EXTENDED) || (OS_ERRORHOOK_SUPPORT == OS_ON))*/

            /* Portable part init variables. */
            /* Reserved for future. */
            /* OsCpu_VariablesInit(coreIndex); */
        }
    }
}

/* BEGIN_FUNCTION_HDR
***********************************************************************************************
* Function Name: Os_StartOS
*
* Description:   The user can call this system service to start the operating system 
*                in a specific mode.
*
* Inputs:        OsAppMode: application mode
*
* Outputs:       None
*
* Limitations:   This API do not record any error, if error happens, 
*                this API will enter endless loop
***********************************************************************************************
END_FUNCTION_HDR*/
FUNC(void, OS_CODE) Os_StartOS
(
    AppModeType OsAppMode
)
{
    CoreIdType CoreID;

    CoreID = OsCpu_GetCoreID();
    /* enter critical area
     * global int will not be enable until first task is running
     * */
    OsIntc_DisableGlobalInterrupt(CoreID);

    /* can not record err in this state, as OS internal vars may not be init*/
#if(OS_STATUS_LEVEL == OS_EXTENDED)
    /*PRQA S 2740 ++*/
    /* Dead loop is acceptable here. */
    if(CoreID >= (CoreIdType)OS_USED_CORE_NUMBER)
    {
        while(OS_TRUE)
        {
        }/* endless loop*/
    }

    if((Os_uint8)OsAppMode >= (Os_uint8)OS_APPMODE_NUMBER)
    {
        /* endless loop, in mulicore prj,  finally this will lead syn startup failed*/
        while(OS_TRUE)
        {
        }
    }
    /*PRQA S 2740 --*/

    /* 
     * do not check Os_CurrentContext and Os_IntAPIUsedFlag and other errors
     * as Os is not start yet, variables are not valid now
     * User must ensure that call StartOS in correct context
     */
#endif /*(OS_STATUS_LEVEL == OS_EXTENDED)*/
    /*hw init, called in each core to init every core*/
    /* must call cpu and mp init first*/
    OsCpu_Init(CoreID);  /* Setup the system stack pointer here */
    OsIntc_Init(CoreID);
    OsSysTimer_Init(CoreID);

#if(OS_ON == OS_TP_TIMER_NEED)
    OsTpTimer_Init(CoreID);
#endif /*(OS_ON == OS_TP_TIMER_NEED)*/
#if(OS_ON == OS_TP_FCTIMER_NEED)
    OsTpFcTimer_Init(CoreID);
#endif /*(OS_ON == OS_TP_FCTIMER_NEED)*/
#if(OS_ON == OS_MEM_PROTECTION_SUPPORT)
    OsMpu_Init(CoreID);   /* enable mpu here*/
#endif /*(OS_ON == OS_MEM_PROTECTION_SUPPORT)*/

    /* kernel module private var init */
#if(OS_APPMODE_NUMBER > 1)
    Os_ActiveAppMode[CoreID] = ((Os_AppModeMaskType)1 << (Os_uint32)OsAppMode);
#endif /*(OS_APPMODE_NUMBER > 1)*/
    OsKernel_HighestTaskPri[CoreID] = OS_INVALID_PRIO;
    OsKernel_HighestTaskId[CoreID] = OS_INVALID_TASK_ID;
#if(OS_CPULOAD_API == OS_ON)
    OsKernel_IdleRunTime[CoreID] = (Os_CpuLoadTickType)0;
    OsKernel_IdleStartTime[CoreID] = (Os_CpuLoadTickType)0;

    OsCpuLoadTimer_Init(CoreID);
#endif /*(OS_CPULOAD_API == OS_ON)*/

    /* core module init*/
    OsTask_Init(CoreID);
#if(OS_ALARM_NUMBER > 0)
    OsAlarm_Init(CoreID);
#endif /*(OS_ALARM_NUMBER > 0)*/
#if(OS_RESOURCE_NUMBER > 0)
    OsRes_Init(CoreID);
#endif /*(OS_RESOURCE_NUMBER > 0)*/
    OsIsr_Init(CoreID);
#if(OS_SCHTBL_NUMBER > 0)
    OsSchTbl_Init(CoreID);
#endif /*(OS_SCHTBL_NUMBER > 0)*/
    OsCnt_Init(CoreID);

#if(OS_APPLICATION_NUMBER > 0)
    OsApp_Init(CoreID);
#endif /*(OS_APPLICATION_NUMBER > 0)*/

#if(OS_IOC_NUMBER > 0)
    OsIoc_Init(CoreID);
#endif /*(OS_IOC_NUMBER > 0)*/

#if(OS_ON == OS_TIMING_PROTECTION_SUPPORT)
    OsTp_Init(CoreID);
#endif /*(OS_ON == OS_TIMING_PROTECTION_SUPPORT)*/
    OsHook_Init(CoreID);

#if(OS_USED_CORE_NUMBER > 1)
    /* cross core operation vars are independt in each core*/
    OsMultiCore_Init(CoreID);
#endif /*(OS_USED_CORE_NUMBER > 1)*/

#if(OS_SPINLOCK_NUMBER > 0)
    if(CoreID == OS_PL_MASTER_COREID)
    {
        OsSpinlock_Init();
    }
#endif /*(OS_SPINLOCK_NUMBER > 0)*/

   /* insert IDLE task, IDLE task is always auto start task */
    /* Startup the auto-start tasks. */
    OsTask_AutoStart(CoreID);

#if(OS_AUTO_ALARM_NUMBER > 0)
    OsAlarm_AutoStart(CoreID);
#endif /*(OS_AUTO_ALARM_NUMBER > 0)*/

#if(OS_AUTO_SCHTBL_NUMBER > 0)
    OsSchTbl_AutoStart(CoreID);
#endif /*(OS_AUTO_SCHTBL_NUMBER > 0)*/

    OsKernel_SynStartUp(CoreID);
#if(OS_STATUS_LEVEL == OS_EXTENDED)
    /*PRQA S 2740 ++*/
    /* Dead loop is acceptable here. */
    if(Os_CoreState[CoreID] != OS_CORE_START)
    {
        /* endless loop*/
        while(OS_TRUE)
        {
        }
    }
    /*PRQA S 2740 --*/
#endif /*(OS_STATUS_LEVEL == OS_EXTENDED)*/
    /*do not enable interrupt until first task is running*/
    /* Startup the system counter. */
    OsSysTimer_Run(CoreID);

    /* First Task scheduling */
    OsCpu_FirstSchedule(CoreID);
    OsHook_FataErrReport(CoreID, E_OS_SYSFATA_UNREACHABLE, OSServiceId_StartOS, OS_IE_NOMORE_INFO, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR);
}

/* BEGIN_FUNCTION_HDR
***********************************************************************************************
* Function Name: Os_ShutdownOS
*
* Description:   The user can call this system service to shutdown the operating system 
*
* Inputs:        StatusType Error
*
* Outputs:       None
*
* Limitations:   None
***********************************************************************************************
END_FUNCTION_HDR*/
FUNC(void, OS_CODE) Os_ShutdownOS
(
    StatusType Error
)
{
    CoreIdType CoreID;

    CoreID = OsCpu_GetCoreID();

#if(OS_STATUS_LEVEL == OS_EXTENDED)
    if((CoreID >= (CoreIdType)OS_USED_CORE_NUMBER) || (Os_CoreState[CoreID] != OS_CORE_START))
    {
        /* can not record err in this state, as OS services can not be called*/
    }

    else if((Os_uint16)(Os_CurrentContext[CoreID] & Os_ShutdownOSMask) == (Os_uint16)0)
    {
        OsHook_ReportError(CoreID, E_OS_CALLEVEL, OSServiceId_ShutdownOS, OS_IE_NOMORE_INFO, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR);
    }

        /* Check whether this API is called between interrupt processing APIs*/
    else if(OS_NO_API_USED != Os_IntAPIUsedFlag[CoreID])
    {
        OsHook_ReportError(CoreID, E_OS_DISABLEDINT, OSServiceId_ShutdownOS, OS_IE_NOMORE_INFO, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR);
    }

#if(OS_APPLICATION_NUMBER > 0)
    /*  current application invalid, should not has this case*/
    else if(Os_CurrentApplicationId[CoreID] == OS_INVALID_OSAPPLICATION)
    {
        OsHook_ReportError(CoreID, E_OS_ACCESS, OSServiceId_ShutdownOS, OS_IE_INVALID_OSAPPICATION, (Os_uint32)Os_CurrentApplicationId[CoreID], OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR);
    }

    /*SWS_Os_00054*/
    else if (OS_FALSE == Os_AppCfg[Os_CurrentApplicationId[CoreID]].isTrusted)
    {
        OsHook_ReportError(CoreID, E_OS_ACCESS, OSServiceId_ShutdownOS, OS_IE_SHUTDOWN_BY_UNTRUST_APP, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR);
    }
#endif /*(OS_APPLICATION_NUMBER > 0)*/
    else
#endif /*(OS_STATUS_LEVEL == OS_EXTENDED)*/
    {

        OsKernel_InternalShutdown(CoreID, Error, INDIVIDUAL_SHUTDOWN);

        /* endless loop */
        for(;;)
        {
        }
    }
}

#if(OS_STACK_USEAGE_API == OS_ON)
/* BEGIN_FUNCTION_HDR
***********************************************************************************************
* Function Name: Os_GetTaskStackUsage
*
* Description:   Get task stack usage of current core
*
* Inputs:        TaskID
*
* Outputs:       Os_uint16, return stack usage in byte
*
* Limitations:   None
***********************************************************************************************
END_FUNCTION_HDR*/
FUNC(StatusType, OS_CODE) Os_GetTaskStackUsage
(
    TaskType TaskID,
    CONSTP2VAR(Os_uint16, AUTOMATIC, OS_APPL_DATA) Value
)
{
    CoreIdType CoreID;
    Os_boolean tempPri;
    Os_uint16 index;
    StatusType ret = E_OS_OK;

    CoreID = OsCpu_GetCoreID();

#if(OS_STATUS_LEVEL == OS_EXTENDED)
    if((CoreID >= (CoreIdType)OS_USED_CORE_NUMBER) || (Os_CoreState[CoreID] != OS_CORE_START))
    {
        /* can not record err in this state, as OS services can not be called*/
        ret = E_OS_CORE;
    }
    
    else if((Os_uint16)(Os_CurrentContext[CoreID] & Os_GetTaskStackUsageMask) == (Os_uint16)0)
    {
        OsHook_ReportError(CoreID, E_OS_CALLEVEL, OSServiceId_GetTaskStackUsage, OS_IE_NOMORE_INFO, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR);
        ret = E_OS_CALLEVEL;
    }

    /* Check the validity of Value:Value cannot be NULL */
    else if(NULL_PTR == Value)
    {
        OsHook_ReportError(CoreID, E_OS_PARAM_POINTER, OSServiceId_GetTaskStackUsage, OS_IE_NOMORE_INFO, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR);
        ret = E_OS_PARAM_POINTER;
    }

    /* Check whether this API is called between interrupt processing APIs*/
    else if(OS_NO_API_USED != Os_IntAPIUsedFlag[CoreID])
    {
        OsHook_ReportError(CoreID, E_OS_DISABLEDINT, OSServiceId_GetTaskStackUsage, OS_IE_NOMORE_INFO, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR);
        ret = E_OS_DISABLEDINT;
    }

    /* Check TaskID valid or not*/
    else if(TaskID >= (TaskType)OS_TASK_NUMBER)
    {
        OsHook_ReportError(CoreID, E_OS_ID, OSServiceId_GetTaskStackUsage, OS_IE_TASK_ID, (Os_uint32)TaskID, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR);
        ret = E_OS_ID;
    }

#if(OS_USED_CORE_NUMBER > 1)
    /* Check whether cross core*/
    else if (CoreID != Os_TaskCfg[TaskID].objCoreId)
    {
        OsHook_ReportError(CoreID, E_OS_SYS_SERVICE_NOTSUPPORT_CROSSCORE, OSServiceId_GetTaskStackUsage, OS_IE_NOMORE_INFO, (Os_uint32)TaskID, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR);
        ret = E_OS_SYS_SERVICE_NOTSUPPORT_CROSSCORE;
    }
#endif /*(OS_USED_CORE_NUMBER > 1)*/
    else
#endif /*(OS_STATUS_LEVEL == OS_EXTENDED)*/
    {
        /*enter critical area*/
        OsCpu_EnterCritical(CoreID, &tempPri);

        for(index = (Os_uint16)0; index < Os_TaskCfg[TaskID].OsTaskStkSize; index++)
        {
#if(OS_PL_STACK_GROW_DIR == OS_PL_STACK_GROW_DOWN)
            if(OS_STACKINIT_VALUE != Os_TaskCfg[TaskID].OsTaskStkTop[index])
#else
            if(OS_STACKINIT_VALUE == Os_TaskCfg[TaskID].OsTaskStkBottom[index])
#endif /*(OS_PL_STACK_GROW_DIR == OS_PL_STACK_GROW_DOWN)*/
            {
                break;
            }
        }

#if(OS_PL_STACK_GROW_DIR == OS_PL_STACK_GROW_DOWN)
        index = Os_TaskCfg[TaskID].OsTaskStkSize - index;
#endif /*(OS_PL_STACK_GROW_DIR == OS_PL_STACK_GROW_DOWN)*/
        /* 4 byte per address*/
        /*PRQA S 4571 ++*/
        /* "uint16" here is expected and will not overflow. */
        *Value = index << (Os_uint16)OS_DATA_SHIFT_TWO;
        /*PRQA S 4571 --*/
        OsCpu_ExitCritical(CoreID, tempPri);
    }
    return ret;
}

/* BEGIN_FUNCTION_HDR
***********************************************************************************************
* Function Name: Os_GetISRStackUsage
*
* Description:   Get ISR stack usage of current core
*
* Inputs:        ISRId
*
* Outputs:       Os_uint16, return stack usage in byte
*
* Limitations:   None
***********************************************************************************************
END_FUNCTION_HDR*/
FUNC(StatusType, OS_CODE) Os_GetISRStackUsage
(
    ISRType ISRId,
    CONSTP2VAR(Os_uint16, AUTOMATIC, OS_APPL_DATA) Value
)
{
    CoreIdType CoreID;
    Os_boolean tempPri;
    Os_uint16 index;
    StatusType ret = E_OS_OK;

    CoreID = OsCpu_GetCoreID();

#if(OS_STATUS_LEVEL == OS_EXTENDED)
    if((CoreID >= (CoreIdType)OS_USED_CORE_NUMBER) || (Os_CoreState[CoreID] != OS_CORE_START))
    {
        /* can not record err in this state, as OS services can not be called*/
        ret = E_OS_CORE;
    }
    
    else if((Os_uint16)(Os_CurrentContext[CoreID] & Os_GetISRStackUsageMask) == (Os_uint16)0)
    {
        OsHook_ReportError(CoreID, E_OS_CALLEVEL, OSServiceId_GetISRStackUsage, OS_IE_NOMORE_INFO, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR);
        ret = E_OS_CALLEVEL;
    }

    /* Check the validity of Value:Value cannot be NULL */
    else if(NULL_PTR == Value)
    {
        OsHook_ReportError(CoreID, E_OS_PARAM_POINTER, OSServiceId_GetISRStackUsage, OS_IE_NOMORE_INFO, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR);
        ret = E_OS_PARAM_POINTER;
    }

    /* Check whether this API is called between interrupt processing APIs*/
    else if(OS_NO_API_USED != Os_IntAPIUsedFlag[CoreID])
    {
        OsHook_ReportError(CoreID, E_OS_DISABLEDINT, OSServiceId_GetISRStackUsage, OS_IE_NOMORE_INFO, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR);
        ret = E_OS_DISABLEDINT;
    }

    /* Check ISRId valid or not*/
    else if (ISRId >= (ISRType)OS_ISR_NUMBER)
    {
        OsHook_ReportError(CoreID, E_OS_ID, OSServiceId_GetISRStackUsage, OS_IE_ISR_ID, (Os_uint32)ISRId, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR);
        ret = E_OS_ID;
    }

#if(OS_USED_CORE_NUMBER > 1)
    /* Check whether this API is called from diifferent core*/
    else if (CoreID != Os_ISRCfg[ISRId].objCoreId)
    {
        OsHook_ReportError(CoreID, E_OS_SYS_SERVICE_NOTSUPPORT_CROSSCORE, OSServiceId_GetTaskStackUsage, OS_IE_NOMORE_INFO, (Os_uint32)ISRId, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR);
        ret = E_OS_SYS_SERVICE_NOTSUPPORT_CROSSCORE;
    }
#endif /*(OS_USED_CORE_NUMBER > 1)*/
    else
#endif /*(OS_STATUS_LEVEL == OS_EXTENDED)*/
    {
        /*enter critical area*/
        OsCpu_EnterCritical(CoreID, &tempPri);

        for(index = (Os_uint16)0; index < Os_ISRCfg[ISRId].OsIsrStkSize; index++)
        {
#if(OS_PL_STACK_GROW_DIR == OS_PL_STACK_GROW_DOWN)
            if(OS_STACKINIT_VALUE != Os_ISRCfg[ISRId].OsIsrStkTop[index])
#else
            if(OS_STACKINIT_VALUE == Os_ISRCfg[ISRId].OsIsrStkBottom[index])
#endif /*(OS_PL_STACK_GROW_DIR == OS_PL_STACK_GROW_DOWN)*/
            {
                break;
            }
        }

#if(OS_PL_STACK_GROW_DIR == OS_PL_STACK_GROW_DOWN)
        index = Os_ISRCfg[ISRId].OsIsrStkSize - index;
#endif /*(OS_PL_STACK_GROW_DIR == OS_PL_STACK_GROW_DOWN)*/
        /* 4 byte per address*/
        /*PRQA S 4571 ++*/
        /* "uint16" here is expected and will not overflow. */
        *Value = index << (Os_uint16)OS_DATA_SHIFT_TWO;
        /*PRQA S 4571 --*/
        OsCpu_ExitCritical(CoreID, tempPri);
    }
    return ret;
}
#endif /*(OS_STACK_USEAGE_API == OS_ON)*/

#if(OS_CPULOAD_API == OS_ON)
/* BEGIN_FUNCTION_HDR
***********************************************************************************************
* Function Name: Os_GetCpuLoadValue
*
* Description:   can only be called in target cycle(100ms) task, to output cpuload of last 100ms
*
* Inputs:        None
*
* Outputs:       StatusType, Value
*
* Limitations:   None
***********************************************************************************************
END_FUNCTION_HDR*/
FUNC(StatusType, OS_CODE) Os_GetCpuLoadValue
(
    CONSTP2VAR(Os_uint8, AUTOMATIC, OS_APPL_DATA) Value
)
{
    CoreIdType CoreID;
    Os_boolean tempPri;
    Os_CpuLoadTickType idletime;
    Os_uint8 result = (Os_uint8)0;
    StatusType ret = E_OS_OK;

    CoreID = OsCpu_GetCoreID();

#if(OS_STATUS_LEVEL == OS_EXTENDED)
    if((CoreID >= (CoreIdType)OS_USED_CORE_NUMBER) || (Os_CoreState[CoreID] != OS_CORE_START))
    {
        /* can not record err in this state, as OS services can not be called*/
        ret = E_OS_CORE;
    }
    
    else if((Os_uint16)(Os_CurrentContext[CoreID] & Os_GetCpuLoadValueMask) == (Os_uint16)0)
    {
        OsHook_ReportError(CoreID, E_OS_CALLEVEL, OSServiceId_GetCpuLoadValue, OS_IE_NOMORE_INFO, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR);
        ret = E_OS_CALLEVEL;
    }

    /* Check the validity of Value:Value cannot be NULL */
    else if(NULL_PTR == Value)
    {
        OsHook_ReportError(CoreID, E_OS_PARAM_POINTER, OSServiceId_GetCpuLoadValue, OS_IE_NOMORE_INFO, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR);
        ret = E_OS_PARAM_POINTER;
    }

    /* Check whether this API is called between interrupt processing APIs*/
    else if(OS_NO_API_USED != Os_IntAPIUsedFlag[CoreID])
    {
        OsHook_ReportError(CoreID, E_OS_DISABLEDINT, OSServiceId_GetCpuLoadValue, OS_IE_NOMORE_INFO, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR);
        ret = E_OS_DISABLEDINT;
    }
    else
#endif /*(OS_STATUS_LEVEL == OS_EXTENDED)*/
    {
        /*enter critical area*/
        OsCpu_EnterCritical(CoreID, &tempPri);

        idletime = OsKernel_IdleRunTime[CoreID];

        if(idletime > OS_CPULOAD_BASE_TIME)
        {
            /*Report Error*/
            ret = E_OS_SYS_IDLETIME_OVERFLOW;
        }
        else
        {
            result = (Os_uint8)((OS_CPULOAD_BASE_TIME - idletime) / (OS_CPULOAD_BASE_TIME / OS_CPULOAD_PERCENTAGE));
        }
        OsKernel_IdleRunTime[CoreID] = (Os_CpuLoadTickType)0;
        *Value = result;
        OsCpu_ExitCritical(CoreID, tempPri);
    }
    return ret;
}
#endif /*(OS_CPULOAD_API == OS_ON)*/

/* BEGIN_FUNCTION_HDR
***********************************************************************************************
* Function Name: Os_GetActiveApplicationMode
*
* Description:   This service returns the current application mode. 
*                It may be used to write mode dependent code.
*
* Inputs:        None
*
* Outputs:       None
*
* Limitations:   None
***********************************************************************************************
END_FUNCTION_HDR*/
FUNC(AppModeType, OS_CODE) Os_GetActiveApplicationMode
(
    void
)
{
#if(OS_APPMODE_NUMBER > 1)
    Os_uint32 appModeIndex;
#endif /*(OS_APPMODE_NUMBER > 1)*/
    AppModeType ret;
#if((OS_APPMODE_NUMBER > 1) || (OS_STATUS_LEVEL == OS_EXTENDED))
    CoreIdType CoreID;

    CoreID = OsCpu_GetCoreID();
#endif

#if(OS_STATUS_LEVEL == OS_EXTENDED)
    if((CoreID >= (CoreIdType)OS_USED_CORE_NUMBER) || (Os_CoreState[CoreID] != OS_CORE_START))
    {
        /* can not record err in this state, as OS services can not be called*/
        ret =  OS_INVALID_APPMODE;
    }
    
    else if((Os_uint16)(Os_CurrentContext[CoreID] & Os_GetActiveApplicationModeMask) == (Os_uint16)0)
    {
        OsHook_ReportError(CoreID, E_OS_CALLEVEL, OSServiceId_GetActiveApplicationMode, OS_IE_NOMORE_INFO, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR);
        ret =  OS_INVALID_APPMODE;
    }

    /* Check whether this API is called between interrupt processing APIs*/
    else if(OS_NO_API_USED != Os_IntAPIUsedFlag[CoreID])
    {
        OsHook_ReportError(CoreID, E_OS_DISABLEDINT, OSServiceId_GetActiveApplicationMode, OS_IE_NOMORE_INFO, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR);
        ret =  OS_INVALID_APPMODE;
    }
    else
#endif /*(OS_STATUS_LEVEL == OS_EXTENDED)*/
    {
#if(OS_APPMODE_NUMBER > 1)

        for (appModeIndex = (Os_uint32)1; appModeIndex <= (Os_uint32)OS_APPMODE_NUMBER; appModeIndex++)
        {
            if ((Os_ActiveAppMode[CoreID] >> appModeIndex) == (Os_uint32)0)
            {
                /*PRQA S 3383, 1482, 4342, 4394 ++*/
                /*
                 * Wraparound is avoided by the "for" statement above.
                 * Converting mask to appMode whitch is enum type.
                 */
                ret =  (AppModeType)(appModeIndex - (Os_uint32)1);
                /*PRQA S 3383, 1482, 4342, 4394 --*/
                break;
            }
        }
#else
        ret = OSDEFAULTAPPMODE;
#endif /*(OS_APPMODE_NUMBER > 1)*/
    }

    return ret;
}

#define OS_STOP_SEC_CODE
#include "Os_MemMap.h"
