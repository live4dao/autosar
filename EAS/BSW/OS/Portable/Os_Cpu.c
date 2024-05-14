/*  BEGIN_FILE_HDR
********************************************************************************
*   NOTICE
*   This software is the property of HiRain Technologies. Any information
*   contained in this doc should not be reproduced, or used, or disclosed
*   without the written authorization from HiRain Technologies.
********************************************************************************
* File Name:       Os_Cpu.c
********************************************************************************
* Project/Product: AUTOSAR OS PROJECT
* Title:           Os_Cpu.c
* Author:          Hirain
********************************************************************************
* Description:     Cpu Module of OS
*
********************************************************************************
* Limitations     : None
*
********************************************************************************
*
********************************************************************************
* Revision History:
*
* Version     Date          Initials        CR#          Descriptions
* ---------   ----------    ------------    ----------   ---------------
* 0.0.0.1       24/03/2021    Ning.Chen       N/A          Init version
* 0.0.0.2       18/04/2021    Feixiang.Dong   N/A          EAS422_OS_20210418_01
* 1.0.0.0       20/05/2021    Feixiang.Dong   N/A          EAS422_OS_20210520_01
* 1.1.1.0       18/09/2021    Yanan.zhao1     N/A          EAS422_OS_20210918_01
* 1.1.1.5       24/11/2021    Yanan.zhao1     N/A          EAS422_OS_20211124_01
* 1.1.1.6       29/04/2022    Yanan.zhao1     N/A          EAS422_OS_20220429_01
* 1.2.1.0       23/12/2022    Yanan.zhao1     N/A          EAS422_OS_20221223_01
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

/*PRQA S 0303,0306 EOF*/
/*
Not cast but access memory or registers by pointer.
*/

/*PRQA S 3119 EOF*/
/*
Some parameters will not be used in different configurations and hardware 
platforms, but they can not be deleted according to the requirements of 
AUTOSAR specification or compatibility. So we retain these parameters for 
compatibility and convert them with (void) to clean the warnings in compiler.
PRQA notices such statements as warning 3119, it has been suppressed here.
*/

/*PRQA S 0862 EOF*/
/*
The code segment like:

#define XXX
#include "Os_MemMap.h"

is a part of AUTOSAR specification, but will be an error in PRQA.
*/

#define OS_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap.h"


STATIC VAR(Os_AddrType, OS_VAR) OsCpu_FirstTaskCSA[OS_TASK_NUMBER];



#define OS_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap.h"


/*****************************************************************************
* MACRO
******************************************************************************/


/*****************************************************************************
* static const define
******************************************************************************/
#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
/*
* Set by MCAL 
*STATIC CONST(Os_uint32, OS_CONST) OsCpu_BaseAddr[OS_PL_MAX_CORE_NUMBER] =
*{
*    0xF8800000,
*    0xF8820000,
*    0xF8840000,
*    0xF8860000,
*    0xF8880000,
*    0xF88C0000
*};
*/
#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"

#define OS_START_SEC_CODE
#include "Os_MemMap.h"

/*****************************************************************************
* OS private code
******************************************************************************/
STATIC FUNC(void, OS_CODE)  OsCpu_TaskUnterminateProcess(void);



/* BEGIN_FUNCTION_HDR
***********************************************************************************************
* Function Name: OsCpu_TaskUnterminateProcess
*
* Description:   Call in OsCpu_TaskSwitch, when user task return
*
* Inputs:        None
*
* Outputs:       None
*
* Limitations:   None
***********************************************************************************************
END_FUNCTION_HDR*/
/*PRQA S 3219 ++*/
/*
This function be called by assembly instructions which PRQA can not parse.
*/
STATIC FUNC(void, OS_CODE) OsCpu_TaskUnterminateProcess
/*PRQA S 3219 --*/
(
    void
)
{
    CoreIdType CoreID;

    CoreID = OsCpu_GetCoreID();

    /*switch to kernel mpu set*/
    /*PRQA S 3200 ++*/
    /* Inline function "OsMpu_SetKernel" do not have return value. */
    OsMpu_SetKernel();
    /*PRQA S 3200 --*/

    /* no need to switch stack pointer here*/
    /*report error*/
    OsHook_ReportErrorDisInt(CoreID, E_OS_MISSINGEND, OSServiceId_OsCpu_TaskSwitch, OS_IE_NOMORE_INFO, (Os_uint32)Os_CurrentTaskId[CoreID], OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR);
    OsTask_InternalTerminateTask(CoreID);

    /* do not need to release CSA in this case, as user task has return, just jump to TaskSWitch*/
    OS_PL_JUMP(&OsCpu_TaskSwitch);
}


/*****************************************************************************
* OS internal code
******************************************************************************/
/* BEGIN_FUNCTION_HDR
***********************************************************************************************
* Function Name: OsCpu_Init
*
* Description:   OsCpu_Init
*
* Inputs:        CoreID
*
* Outputs:       None
*
* Limitations:   None
***********************************************************************************************
END_FUNCTION_HDR*/
FUNC(void , OS_CODE) OsCpu_Init
(
    CoreIdType CoreID
)
{
    TaskType TaskId;
    TaskType TaskEnd;
    Os_uint32 *psw_temp;
    Os_uint32 mpupcxi_temp;
    Os_uint32 mpupcxo_temp;
    Os_uint32 mpupcxs_temp;

    TaskEnd = Os_CoreCfg[CoreID].startTaskId + Os_CoreCfg[CoreID].taskNum;

    for (TaskId = Os_CoreCfg[CoreID].startTaskId; TaskId < TaskEnd; TaskId++)
    {
        OsCpu_FirstTaskCSA[TaskId] = (Os_AddrType)0;
    }

    /* Get Saved PCXI*/
    mpupcxi_temp = (OS_PL_MFCR(OS_PL_CPU_PCX_REG));
    /* Get Saved PCXI.PCXO*/
    mpupcxo_temp = (OS_PL_PCX_PCXO_MASK & mpupcxi_temp) << OS_PL_PCX_PCXO_SHIFT;
    /* Get Saved PCXI.PCXS*/
    mpupcxs_temp = (OS_PL_PCX_PCXS_MASK & mpupcxi_temp) << OS_PL_PCX_PCXS_SHIFT;
    /* Get Saved Upper*/
    mpupcxi_temp = mpupcxo_temp | mpupcxs_temp;
    /* Get Saved PSW*/
    /*PRQA S 3383 ++*/
    /* Caculate address here so can not overflow. */
    psw_temp = (Os_uint32 *) (mpupcxi_temp + OS_PL_UPPER_PSW_SHIFT);
    /*PRQA S 3383 --*/
    /* Change Saved PSW.IS*/
    *psw_temp = ((*psw_temp) & (~(OS_PL_PSW_ISUSERMASK))) | OS_PL_PSW_ISUSERMASK;
    /* Return Saved PSW.IS*/
}

/* BEGIN_FUNCTION_HDR
***********************************************************************************************
* Function Name: OsCpu_FirstSchedule
*
* Description:   Call in Start OS, it should do following jobs:
*                1.since this is the 1st time os start scheduing, so clear all pre context
*                2.return to TaskSwitch to start schedule
*
* Inputs:        CoreID
*
* Outputs:       None
*
* Limitations:   None
***********************************************************************************************
END_FUNCTION_HDR*/
FUNC(void , OS_CODE)  OsCpu_FirstSchedule
(
    CoreIdType CoreID
)
{
    Os_uint32 pcx;
    Os_uint32 val;

    (void)CoreID;
    /* PRQA S 2982 ++ */
    /* pcx and var are necessary */
    pcx = (OS_PL_MFCR(OS_PL_CPU_PCX_REG));
    val = (pcx & OS_PL_PCX_PCX_MASK);



    /* clear all CDC, so that RFE can be used in OsCpu_TaskSwitch*/
    val = (OS_PL_MFCR(OS_PL_CPU_PSW_REG));
    val = val & OS_PL_PSW_CDC_CLEAR_MASK;
    OS_PL_MTCR(OS_PL_CPU_PSW_REG, val);
    /* PRQA S 2982 -- */

    OS_PL_JUMP(&OsCpu_TaskSwitch);
}


/* BEGIN_FUNCTION_HDR
***********************************************************************************************
* Function Name: OsCpu_TaskTerminateSchedule
*
* Description:   Called at the end of TerminateTask and ChainTask
*                release all user task ctx and start schedule
*
* Inputs:        CoreID,TaskId
*
* Outputs:       None
*
* Limitations:   None
***********************************************************************************************
END_FUNCTION_HDR*/
FUNC(void , OS_CODE)OsCpu_TaskTerminateSchedule
(
    CoreIdType CoreID,
    TaskType TaskID
)
{
    Os_uint32 pcx;
    Os_uint32 val;

    (void)CoreID;

    /* release all task CSA */
    /*PRQA S 2740 ++*/
    /* There's "break" controls the "while" loop. */
    while(1)/* loop until CSA arrive  or CSA = 0(ERROR STATE) */
    /*PRQA S 2740 --*/
    {
        pcx = (OS_PL_MFCR(OS_PL_CPU_PCX_REG));
        val = (pcx & OS_PL_PCX_PCX_MASK);

        if(val == (Os_uint32)0)
        {
            /*FATA error report*/
            OsHook_FataErrReport(CoreID, E_OS_PL_SYSFATA_CSA_ERR, OSServiceId_OsCpu_TaskTerminateSchedule, OS_IE_TASK_CSA_ERR, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR);

        }

        pcx = pcx & OS_PL_PCX_UL_LOWMASK; /* clear UL so that can use rslcx cmd below */
        pcx = pcx & OS_PL_PCX_PIE_DISMASK;/* clear PIE to avoid enable interrupt  */

        OS_PL_MTCR(OS_PL_CPU_PCX_REG, pcx);
        OS_PL_ISYNC();
        OS_PL_RSLCX(); /* release this level ctx*/


        if(val == (Os_uint32)OsCpu_FirstTaskCSA[TaskID])
        {
            OsCpu_FirstTaskCSA[TaskID] = (Os_AddrType)0;
            break;
        }

    }


    /* clear all CDC, so that RFE can be used in OsCpu_TaskSwitch*/
    val = (OS_PL_MFCR(OS_PL_CPU_PSW_REG));
    val = val & OS_PL_PSW_CDC_CLEAR_MASK;
    OS_PL_MTCR(OS_PL_CPU_PSW_REG, val);

    OS_PL_JUMP(&OsCpu_TaskSwitch);
}

/* BEGIN_FUNCTION_HDR
***********************************************************************************************
* Function Name: OsCpu_InternalTaskPreempt
*
* Description:   In TC3xx, jump from system call trap, this function can only be jump, can not be called,
*                to avoid CDC++, which cause RFE fail
*
*
* Inputs:        None
*
* Outputs:       None
*
* Limitations:   1.only can be trigger from task; InIsrC2 dont affect by this function
***********************************************************************************************
END_FUNCTION_HDR*/
FUNC(void, OS_CODE)  OsCpu_InternalTaskPreempt
(
    void
)
{
    CoreIdType CoreID;
    TaskType taskID;
    Os_uint32 pcx;
    Os_AddrType val;

    /* Step1, save context */
    /* upper ctx has been saved during syscall trap*/
    OS_PL_SVLCX();/* save lower*/
    OS_PL_ISYNC();

    CoreID = OsCpu_GetCoreID();

    taskID = Os_CurrentTaskId[CoreID];
    /* set current task invlaid*/
    Os_CurrentTaskId[CoreID] = OS_INVALID_TASK_ID;

    /*read out the saved ctx and record it into task vars*/
    pcx = (OS_PL_MFCR(OS_PL_CPU_PCX_REG));
    val = (pcx & OS_PL_PCX_PCX_MASK);
    Os_TaskCBTable[taskID].OsTaskCtxPtr = val;


#if(OS_CRC_SUPPORT == OS_ON)
    Os_TaskCBTable[taskID].crcResult = OsCrc_Calculate(val);
#endif

    OS_PL_JUMP(&OsCpu_TaskSwitch);
}

/* BEGIN_FUNCTION_HDR
***********************************************************************************************
* Function Name: OsCpu_TaskSwitch
*
* Description:   Task Switch function
*
*
* Inputs:        None
*
* Outputs:       None
*
* Limitations:   1.trigger from task or outISRC2
                 2.use old stack, before switch to next task, no system stack switch
                 3.must done all the process of old task or ISR, before call this fucntion, this function only do the new task switch job

***********************************************************************************************
END_FUNCTION_HDR*/
FUNC(void, OS_CODE) OsCpu_TaskSwitch
(
    void
)
{
    CoreIdType CoreID = OsCpu_GetCoreID();
    TaskStateType taskState;
    Os_uint32 cdc;

    OsKernel_CheckTaskSwitch(CoreID);

    /* check CDC in PSW reg, CDC must be 0, when do task switch*/
    cdc = (OS_PL_MFCR(OS_PL_CPU_PSW_REG));
    cdc = cdc & OS_PL_PSW_CDC_MASK;
    if(cdc != (Os_uint32)0)
    {
        OsHook_FataErrReport(CoreID, OS_IE_PL_CDC_ERR, OSServiceId_OsCpu_TaskSwitch, OS_IE_NOMORE_INFO, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR);
    }

    /* save the state as state will set to running in Enter Task before PreTaskHook*/
    taskState = Os_TaskCBTable[Os_CurrentTaskId[CoreID]].OsTaskState;
    
    if(taskState == OS_TASK_NEW)/* Start new Task */
    {
        OsKernel_EnterTask(CoreID, OS_FALSE);/* prepare for new task*/

        /* set interrupt priority to lowest so that any interrupt can generate when task running */
        OsIntc_ReplaceIntPriority(CoreID, OS_PL_LOWEST_ISR_PRI);

        /*save the next CSA, wich will be first used in next task,
         * so that, when task end, os will release CSA to this OsCpu_FirstTaskCSA
         * */
        OsCpu_FirstTaskCSA[Os_CurrentTaskId[CoreID]] = OS_PL_MFCR(OS_PL_CPU_FCX_REG);

        /*switch to task mpu set*/
        OsMpu_SetTask(CoreID, Os_CurrentTaskId[CoreID]);

        /* switch to new task's stack */
        OS_PL_SET_REG(sp, Os_TaskCfg[Os_CurrentTaskId[CoreID]].OsTaskStkBottom);
        
        /* Must after control interrupt, to change usermode  */
        /*PRQA S 3200 ++*/
        /* Inline function "OsMpu_SetTaskMode" do not have return value. */
        OsMpu_SetTaskMode(CoreID, Os_CurrentTaskId[CoreID]);
        /*PRQA S 3200 --*/

        Os_TaskCfg[Os_CurrentTaskId[CoreID]].OsTaskAddr();

        /* if user task return  SWS_OS_00069*/
        /* task not terminate detected */
        OS_PL_DisableInterrupts();
        /* as stack pointer has switch before, coreid can not be used any more,
         * so we jump to  OsCpu_TaskUnterminateProcess in which get core id again
         * can not call here,  as OsCpu_TaskUnterminateProcess will jump back to OsCpu_TaskSwitch*/
        OS_PL_JUMP(&OsCpu_TaskUnterminateProcess);
    }
    /* waiting task will set to ready when event set*/
    else if((taskState == OS_TASK_READY) || (taskState == OS_TASK_WAITING_TO_READY))/* waiting task will set to ready when event set*/
    {
        OsKernel_EnterTask(CoreID, OS_TRUE);/* prepare for restore task*/

        /*switch to task mpu set as mpu not saved in CSA*/
        OsMpu_SetTask(CoreID, Os_CurrentTaskId[CoreID]);
        /* restore old task*/

        /* PCX set to restore CSA addr,
         * PIE = 0, to keep disable interrupt
         * UL = 0, as restore lower first
         * PCPN, dont care, clear it to 0
         *  */
        OS_PL_MTCR (OS_PL_CPU_PCX_REG, (Os_TaskCBTable[Os_CurrentTaskId[CoreID]].OsTaskCtxPtr) );
        OS_PL_DSYNC();
        OS_PL_RSLCX();/* lower CSA restore*/

        /* upper CSA restore here
         * Stack pointer, global interrupt state , interrupt priority will all be restored here
         * MPU set1 (Task ISR Set) will also be restore here
         * */
        OS_PL_RFE();
    }
    else
    {
        OsHook_FataErrReport(CoreID, E_OS_SYSFATA_UNREACHABLE, OSServiceId_OsCpu_TaskSwitch, OS_IE_NOMORE_INFO, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR);
    }

}

/* BEGIN_FUNCTION_HDR
***********************************************************************************************
* Function Name: OsCpu_TaskPreemptSchedule
*
* Description:   Implement as macro in this platform, to trigger syscall trap
*
* Inputs:        None
*
* Outputs:       None
*
* Limitations:   None
***********************************************************************************************
END_FUNCTION_HDR*/

/* BEGIN_FUNCTION_HDR
***********************************************************************************************
* Function Name: OsCpu_EnterCritical
*
* Description:   Disable global interrupt to enter Critical area
*
* Inputs:        CoreID
*
* Outputs:       gIntState
*
* Limitations:   1.input CoreID is logical id, If needed , CoreID need to change to phy core id
*                2.can not use ISR priority to enter and leave Critical area, as in resouce API, need to change celling priority
*                3.This function must be inline code. as Call and RET cmd may change the global interrupt state
***********************************************************************************************
END_FUNCTION_HDR*/
FUNC(void, OS_CODE) OsCpu_EnterCritical
(
    CoreIdType CoreID,
    /*PRQA S 3432 ++*/
    /*
    P2VAR and other macros in the Compiler conforms to AUTOSAR standard.
    There's no need to revise.
    */
    P2VAR(Os_boolean, AUTOMATIC, AUTOMATIC) gIntState
    /*PRQA S 3432 --*/
)
{
    Os_boolean state = OS_FALSE;
    Os_uint32 val;

    (void)CoreID;
    val = (OS_PL_MFCR(OS_PL_CPU_ICR_REG));
    if((Os_uint32)0 != (val & OS_PL_ICR_IE_MASK))
    {
        state = OS_TRUE;
    }

    *gIntState = state;
    OS_PL_DisableInterrupts();
}

/* BEGIN_FUNCTION_HDR
***********************************************************************************************
* Function Name: OsCpu_GetCoreID
*
* Description:   Get current logical core Id
*
* Inputs:        None
*
* Outputs:       CoreID
*
* Limitations:   None
***********************************************************************************************
END_FUNCTION_HDR*/
FUNC(CoreIdType, OS_CODE) OsCpu_GetCoreID
(
    void
)
{
    CoreIdType CoreID;
    CoreID = (CoreIdType)(OS_PL_MFCR(OS_PL_CPU_COREID_REG));

    if(CoreID == OS_PL_HW_PHY_CORE6)
    {
        CoreID = OS_PL_PHY_CORE5;
    }

    if(CoreID < (CoreIdType)OS_PL_MAX_CORE_NUMBER)
    {
        CoreID = Os_PhyCoreToLog[CoreID];
    }
    else
    {
        CoreID = OS_INVALID_COREID;
    }

    return CoreID;
}

/* BEGIN_FUNCTION_HDR
***********************************************************************************************
* Function Name: OsCpu_GetPhyCoreId
*
* Description:    Implement as macro in this platform
*                 Get current physical core Id, used when non autosar core read coreid
*
* Inputs:        None
*
* Outputs:       None
*
* Limitations:   None
***********************************************************************************************
END_FUNCTION_HDR*/


/* BEGIN_FUNCTION_HDR
***********************************************************************************************
* Function Name: OsCpu_SetMode
*
* Description:   Start or stop core running
*
* Inputs:        CoreID(must be physical core id), mode
*
* Outputs:       None
*
* Limitations:   None
***********************************************************************************************
END_FUNCTION_HDR*/
FUNC(void, OS_CODE) OsCpu_SetMode
(
    CoreIdType CoreID,
    Os_uint8 mode
)
{
    Os_uint16 cpuWdtPassword;
    CoreIdType phyCoreId;
    if(mode == OS_HW_CORE_STOP) /* set idle*/
    {
        phyCoreId = Os_LogCoreToPhy[CoreID];
        cpuWdtPassword = OsCpu_GetCpuWatchdogPassword(phyCoreId);
        OsCpu_ClearCpuEndinit(phyCoreId, cpuWdtPassword);

        /*SCU_PMCSR0.B.REQSLP = 1U;*/
        /*PRQA S 3383,3442 ++*/
        /* Reading(Writing) u32 type number from(to) 32 bits register can not overflow. */
        /* Read and write register in one statement. */
        OS_PL_PMCSR(phyCoreId) |= OS_PL_PMCSR_IDLE_MASK;
        /*PRQA S 3383,3442 --*/

        OsCpu_SetCpuEndinit(phyCoreId, cpuWdtPassword);
    }
    else
    {
        /*
        * Set by MCAL 
        * OS_PL_PC(CoreID) = Os_CoreStartAddr[CoreID];
        * OS_PL_SYSCON(CoreID) &= OS_PL_SYSCON_BHALT_CLEAR_MASK;
        */
    }

}

#if(OS_CRC_SUPPORT == OS_ON)
/* BEGIN_FUNCTION_HDR
***********************************************************************************************
* Function Name: OsCpu_ConvertAddr
*
* Description:   Convert Addr from PCX to real phy addr
*
* Inputs:        pcxAddr
*
* Outputs:       Os_AddrType
*
* Limitations:   None
***********************************************************************************************
END_FUNCTION_HDR*/
FUNC(Os_AddrType, OS_CODE) OsCpu_ConvertAddr
(
    Os_AddrType pcxAddr
)
{
    Os_AddrType pcxs;
    Os_AddrType pcxo;
    Os_AddrType addr = pcxAddr;

    pcxs = addr & OS_PL_PCX_PCXS_MASK;
    pcxo = addr & OS_PL_PCX_PCXO_MASK;

    pcxo = pcxo << OS_PL_PCX_PCXO_SHIFT;
    pcxs = pcxs << OS_PL_PCX_PCXS_SHIFT;

    addr = pcxs|pcxo;

    return addr;
}
#endif


/* BEGIN_FUNCTION_HDR
***********************************************************************************************
* Function Name: OsCpu_GetSpinlock
*
* Description:   use cmpswap to set spinlock
*
* Inputs:        address, value, condition
*
* Outputs:       None
*
* Limitations:   None
***********************************************************************************************
END_FUNCTION_HDR*/
FUNC(void, OS_CODE) OsCpu_GetSpinlock (Os_uint32 *address, CoreIdType value)
{
    /*PRQA S 0314,0316,3416,4471 ++*/
    /* Cast to fullfill the need of assembly instructions. */
    while(OS_INVALID_COREID != (CoreIdType)OsCpu_CmpandSwap((Os_uint32 *)(void *)(address), value, OS_INVALID_COREID))
    /*PRQA S 0314,0316,3416,4471 --*/
    {
        OS_PL_NOP();
    }
}

/* BEGIN_FUNCTION_HDR
***********************************************************************************************
* Function Name: OsCpu_TryToGetSpinlock
*
* Description:   Try To GetSpinlock
*
* Inputs:        value
*
* Outputs:       None
*
* Limitations:   None
***********************************************************************************************
END_FUNCTION_HDR*/
FUNC (Os_boolean, OS_CODE) OsCpu_TryToGetSpinlock (Os_uint32 *address, CoreIdType value)
{
    Os_boolean ret;
    /*PRQA S 0314,0316,3416,4471 ++*/
    /* Cast to fullfill the need of assembly instructions. */
    if(OS_INVALID_COREID == (CoreIdType)OsCpu_CmpandSwap((Os_uint32 *)(void *)(address), value, OS_INVALID_COREID))
    /*PRQA S 0314,0316,3416,4471 --*/
    {
        ret = OS_TRUE;
    }
    else
    {
        ret = OS_FALSE;
    }

    return ret;
}


/* BEGIN_FUNCTION_HDR
***********************************************************************************************
* Function Name: OsCpu_FreeTaskCSA
*
* Description:   free Task CSA, only used in terminate App
*
* Inputs:        CoreID,TaskId
*
* Outputs:       None
*
* Limitations:   None
***********************************************************************************************
END_FUNCTION_HDR*/
FUNC(void, OS_CODE) OsCpu_FreeTaskCSA
(
    CoreIdType CoreID,
    TaskType TaskID
)
{
    Os_uint32 pcx;
    Os_AddrType val;
    Os_uint32 mpupcxo_temp;
    Os_uint32 mpupcxs_temp;
    Os_uint32 mpupcxi_temp;
    Os_uint32 mpupcxi_temp1;
    pcx = (OS_PL_MFCR(OS_PL_CPU_PCX_REG));
    val = (pcx & OS_PL_PCX_PCX_MASK);
    /*PRQA S 2740 ++*/
    /* There's "break" controls the "while" loop. */
    while(1)
    /*PRQA S 2740 --*/
    {
        if(val < OsCpu_FirstTaskCSA[TaskID])
        {
            OsCpu_FirstTaskCSA[TaskID] = (Os_AddrType)0;
            break;
        }
        if(val == (Os_uint32)0)
        {
            /*FATA error report*/
            OsHook_FataErrReport(CoreID, E_OS_PL_SYSFATA_CSA_ERR, OSServiceId_OsCpu_FreeTaskCSA, OS_IE_TASK_CSA_ERR, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR);
        }
        if(val == OsCpu_FirstTaskCSA[TaskID])
        {
            OsCpu_FirstTaskCSA[TaskID] = (Os_AddrType)0;
            /* Get Saved PCXI.PCXO*/
            mpupcxo_temp = (OS_PL_PCX_PCXO_MASK & val) << OS_PL_PCX_PCXO_SHIFT;
            /* Get Saved PCXI.PCXS*/
            mpupcxs_temp = (OS_PL_PCX_PCXS_MASK & val) << OS_PL_PCX_PCXS_SHIFT;
            /* Get Saved Upper*/
            mpupcxi_temp1 = mpupcxo_temp | mpupcxs_temp;
            val = (*(Os_uint32*)mpupcxi_temp1) & OS_PL_PCX_PCX_MASK;
            (*(Os_uint32*)mpupcxi_temp) = ((*(Os_uint32*)mpupcxi_temp) & (~OS_PL_PCX_PCX_MASK)) | val;
            /*PRQA S 0771 ++*/
            /* Multiple "break" are necessary for this loop. */
            break;
            /*PRQA S 0771 --*/
        }
        
        /* Get Saved PCXI.PCXO*/
        mpupcxo_temp = (OS_PL_PCX_PCXO_MASK & val) << OS_PL_PCX_PCXO_SHIFT;
        /* Get Saved PCXI.PCXS*/
        mpupcxs_temp = (OS_PL_PCX_PCXS_MASK & val) << OS_PL_PCX_PCXS_SHIFT;
        /* Get Saved Upper*/
        mpupcxi_temp = mpupcxo_temp | mpupcxs_temp;
        val = (*(Os_uint32*)mpupcxi_temp) & OS_PL_PCX_PCX_MASK;

    }
}
/* BEGIN_FUNCTION_HDR
***********************************************************************************************
* Function Name: OsCpu_GetCpuWatchdogPassword
*
* Description:   get watchdog password
*
* Inputs:        phyCoreID
*
* Outputs:       password
*
* Limitations:   None
***********************************************************************************************
END_FUNCTION_HDR*/

FUNC(Os_uint16, OS_CODE) OsCpu_GetCpuWatchdogPassword
(
    CoreIdType phyCoreID
)
{
    Os_uint32 tmpVal;
    Os_uint16 password;
    
    /*PRQA S 3383 ++*/
    /* Reading(Writing) u32 type number from(to) 32 bits register can not overflow. */
    tmpVal = OS_PL_WDTCPU_CON0(phyCoreID);
    /*PRQA S 3383 --*/
    tmpVal = tmpVal & OS_PL_WDTCPU_PW_MASK;
    password = (Os_uint16)(tmpVal >> OS_PL_WDTCPU_PW_SHIFT_VAL);
    password ^= OS_PL_WDT_PASSWORD_INVERT_MSK;

    return password;

}


/* BEGIN_FUNCTION_HDR
***********************************************************************************************
* Function Name: OsCpu_ClearCpuEndinit
*
* Description:   Unlock access to registers.
*
* Inputs:        phyCoreID, password
*
* Outputs:       None
*
* Limitations:   None
***********************************************************************************************
END_FUNCTION_HDR*/
FUNC(void, OS_CODE) OsCpu_ClearCpuEndinit
(
    CoreIdType phyCoreID,
    Os_uint16 password
)
{
    Os_uint32 tmpVal;
    Os_uint32 tmpPw = (Os_uint32)password << OS_PL_WDTCPU_PW_SHIFT_VAL;
    Os_uint32 tmpRel;

    /*PRQA S 3383 ++*/
    /* Reading(Writing) u32 type number from(to) 32 bits register can not overflow. */
    tmpVal = OS_PL_WDTCPU_CON0(phyCoreID);
    tmpRel = tmpVal & OS_PL_WDTCPU_REL_MASK;

    if(OS_PL_WDTCPU_LCK_MASK == (tmpVal & OS_PL_WDTCPU_LCK_MASK))
    {
        OS_PL_WDTCPU_CON0(phyCoreID) = (tmpPw|OS_PL_WDTCPU_ENDINIT_MASK|tmpRel);
    }

    OS_PL_WDTCPU_CON0(phyCoreID) = (tmpPw|OS_PL_WDTCPU_LCK_MASK|tmpRel);

    /* Read back of the register is mandatory to ensure the register update  */
    OS_PL_WDTCPU_CON0(phyCoreID); /*suppress("Statement has no effect")*/
    /*PRQA S 3383 --*/
}
/* BEGIN_FUNCTION_HDR
***********************************************************************************************
* Function Name: OsCpu_SetCpuEndinit
*
* Description:   Lock the registers
*
* Inputs:        phyCoreID, password
*
* Outputs:       None
*
* Limitations:   None
***********************************************************************************************
END_FUNCTION_HDR*/

FUNC(void, OS_CODE) OsCpu_SetCpuEndinit
(
    CoreIdType phyCoreID,
    Os_uint16 password
)
{
    Os_uint32 tmpVal;
    Os_uint32 tmpPw = (Os_uint32)password << OS_PL_WDTCPU_PW_SHIFT_VAL;
    Os_uint32 tmpRel;

    /*PRQA S 3383 ++*/
    /* Reading(Writing) u32 type number from(to) 32 bits register can not overflow. */
    tmpVal = OS_PL_WDTCPU_CON0(phyCoreID);
    tmpRel = tmpVal & OS_PL_WDTCPU_REL_MASK;

    if((Os_uint32)0 != (tmpVal & OS_PL_WDTCPU_LCK_MASK))
    {
        OS_PL_WDTCPU_CON0(phyCoreID) = (tmpPw|OS_PL_WDTCPU_ENDINIT_MASK|tmpRel);
    }

    OS_PL_WDTCPU_CON0(phyCoreID) = (tmpPw|OS_PL_WDTCPU_LCK_MASK|OS_PL_WDTCPU_ENDINIT_MASK|tmpRel);

    /* Read back of the register is mandatory to ensure the register update  */
    tmpVal = OS_PL_WDTCPU_CON0(phyCoreID);
    /*PRQA S 3383 --*/
}
#define OS_STOP_SEC_CODE
#include "Os_MemMap.h"

