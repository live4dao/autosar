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
*   Revision History:
*   Reference to Os_Cpu.c File
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

STATIC VAR(Os_boolean, OS_VAR) OsIntc_GlobalIntState_Backup[OS_USED_CORE_NUMBER];/* global interrupt state */
STATIC VAR(Os_PrioType, OS_VAR) OsIntc_IntPri_Backup[OS_USED_CORE_NUMBER];/* interrupt priority state */
VAR(Os_AddrType, OS_VAR) OsIntc_FirstISRCSA[OS_ISR_NUMBER];
#define OS_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap.h"

/*****************************************************************************
* MACRO
******************************************************************************/

#define OS_START_SEC_CODE
#include "Os_MemMap.h"
/*****************************************************************************
* OS internal code
******************************************************************************/
#if(OS_USED_CORE_NUMBER > 1)

STATIC FUNC(void, OS_CODE) OsIntc_CrossCoreIntInit
(
    CoreIdType CoreID
);
STATIC FUNC(void, OS_CODE) OsIntc_CrossCoreIntClear
(
    CoreIdType CoreID
);
#endif
/* BEGIN_FUNCTION_HDR
***********************************************************************************************
* Function Name: OsIntc_Init
*
* Description:   Do necessary init for intc
*
* Inputs:        CoreID
*
* Outputs:

*
* Limitations:   input CoreID is logical id, If needed , CoreID need to change to phy core id
***********************************************************************************************
END_FUNCTION_HDR*/
FUNC(void, OS_CODE) OsIntc_Init
(
    CoreIdType CoreID
)
{

#if(OS_USED_CORE_NUMBER > 1)

    OsIntc_CrossCoreIntInit(CoreID);

#else

    (void) CoreID;

#endif

}

#if(OS_USED_CORE_NUMBER > 1)
/* BEGIN_FUNCTION_HDR
***********************************************************************************************
* Function Name: OsIntc_Init
*
* Description:   Do necessary init for intc
*
* Inputs:        CoreID
*
* Outputs:

*
* Limitations:   input CoreID is logical id, If needed , CoreID need to change to phy core id
***********************************************************************************************
END_FUNCTION_HDR*/

/* Trigger SW ISR, to execute in target core*/
FUNC(void, OS_CODE) OsIntc_CrossCoreIntTrigger
(
    CoreIdType CoreID
)
{
    /*PRQA S 3383 ++*/
    /* Writing 1 to 32 bits register can not overflow. */
    OS_PL_SRC_GPSR0(CoreID).B.SETR = (Os_uint32)1;
    /*PRQA S 3383 --*/
}
#endif

/* BEGIN_FUNCTION_HDR
***********************************************************************************************
* Function Name: OsIntc_ReplaceIntPriority
*
* Description:   Set interrupt priority of current core
*
* Inputs:        CoreID, priority
*
* Outputs:       OS_INLINE_FUNC(Os_PrioType) OsIntc_GetIntPriority

*
* Limitations:   1.input CoreID is logical id, If needed , CoreID need to change to phy core id
***********************************************************************************************
END_FUNCTION_HDR*/
FUNC(void, OS_CODE) OsIntc_ReplaceIntPriority
(
    CoreIdType CoreID,
    Os_PrioType priority
)
{
    Os_uint32 val;
    Os_uint32 temp_val;
    Os_PrioType readbackPri;
    Os_uint8 cnt = (Os_uint8)0;

    val = (OS_PL_MFCR(OS_PL_CPU_ICR_REG));
    val &= (~OS_PL_ICR_CCPN_MASK);
    val |= priority;
    do
    {
        OS_PL_MTCR(OS_PL_CPU_ICR_REG, val);
        OS_PL_ISYNC();
        /* read back and check */
        temp_val = (OS_PL_MFCR(OS_PL_CPU_ICR_REG));
        readbackPri = (Os_PrioType)(temp_val & OS_PL_ICR_CCPN_MASK);

        /*PRQA S 3383 ++*/
        /* The value of "cnt" will be checked by "do...while..." loop. */
        cnt++;
        /*PRQA S 3383 --*/

    }while((readbackPri != priority) && (cnt < OS_PL_REG_RETRY_TIMES));

    if(cnt >= OS_PL_REG_RETRY_TIMES)
    {
        OsHook_FataErrReport(CoreID, E_OS_PL_SYSFATA_ACCESS_REG_ERR, OSServiceId_OsIntc_ReplaceIntPriority, OS_IE_NOMORE_INFO, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR);
    }
}



/* BEGIN_FUNCTION_HDR
***********************************************************************************************
* Function Name: OsCpu_GetIntEnState
*
* Description:   Get global interrupt state
*
* Inputs:        CoreID
*
* Outputs:       Os_boolean
*
* Limitations:   input CoreID is logical id, If needed , CoreID need to change to phy core id
***********************************************************************************************
END_FUNCTION_HDR*/
FUNC(Os_boolean, OS_CODE) OsIntc_GetGlobalIntState
(
    CoreIdType CoreID
)
{
    Os_uint32 val;
    Os_boolean state = OS_FALSE;


    (void)CoreID;
    val = (OS_PL_MFCR(OS_PL_CPU_ICR_REG));

    if((Os_uint32)0 != (val & OS_PL_ICR_IE_MASK))
    {
        state = OS_TRUE;
    }

    return state;


}


/* BEGIN_FUNCTION_HDR
***********************************************************************************************
* Function Name: OsIntc_SetIntEnState
*
* Description:   Set global interrupt state
*
* Inputs:        CoreID, gIntState
*
* Outputs:       None
*
* Limitations:   input CoreID is logical id, If needed , CoreID need to change to phy core id
***********************************************************************************************
END_FUNCTION_HDR*/
FUNC(void, OS_CODE) OsIntc_SetGlobalIntState
(
    CoreIdType CoreID,
    Os_boolean gIntState
)
{
    (void)CoreID;


    if(gIntState == OS_TRUE)
    {
        OS_PL_EnableInterrupts();
    }
    else
    {
        /* code */
        OS_PL_DisableInterrupts();
    }

}

/* BEGIN_FUNCTION_HDR
***********************************************************************************************
* Function Name: OsIntc_DisableAllInterrupts
*
* Description:  save current state and disable all interrupts
*
* Inputs:       CoreID
*
* Outputs:      None
*
* Limitations:   input CoreID is logical id, If needed , CoreID need to change to phy core id
***********************************************************************************************
END_FUNCTION_HDR*/
FUNC(void, OS_CODE) OsIntc_DisableAllInterrupts
(
    CoreIdType CoreID
)
{
    VAR(Os_boolean, OS_VAR) IntState_Backup;
    /* in TC3xx, we use trap for time protection so no need to consider tp here*/
    IntState_Backup = OsIntc_GetGlobalIntState(CoreID);
    OS_PL_DisableInterrupts();
    OsIntc_GlobalIntState_Backup[CoreID] = IntState_Backup;
}


/* BEGIN_FUNCTION_HDR
***********************************************************************************************
* Function Name: OsIntc_ResumeAllInterrupts
*
* Description:  resume saved global int state
*
* Inputs:       CoreID
*
* Outputs:      None
*
* Limitations:   input CoreID is logical id, If needed , CoreID need to change to phy core id
***********************************************************************************************
END_FUNCTION_HDR*/
FUNC(void, OS_CODE) OsIntc_ResumeAllInterrupts
(
    CoreIdType CoreID
)
{
    OsIntc_SetGlobalIntState(CoreID, OsIntc_GlobalIntState_Backup[CoreID]);
}


/* BEGIN_FUNCTION_HDR
***********************************************************************************************
* Function Name: OsIntc_SuspendOsInterrupts
*
* Description:  save current C2 state and disable C2 interrupts
*
* Inputs:       CoreID
*
* Outputs:      None
*
* Limitations:   input CoreID is logical id, If needed , CoreID need to change to phy core id
***********************************************************************************************
END_FUNCTION_HDR*/
FUNC(void, OS_CODE) OsIntc_SuspendOsInterrupts
(
    CoreIdType CoreID
)
{
    OsIntc_IntPri_Backup[CoreID] = OsIntc_GetIntPriority(CoreID);
    OsIntc_ReplaceIntPriority(CoreID, Os_CoreCfg[CoreID].topC2IsrPri);
}

/* BEGIN_FUNCTION_HDR
***********************************************************************************************
* Function Name: OsIntc_ResumeOsInterrupts
*
* Description:  resume saved C2 state
*
* Inputs:       CoreID
*
* Outputs:      None
*
* Limitations:   input CoreID is logical id, If needed , CoreID need to change to phy core id
***********************************************************************************************
END_FUNCTION_HDR*/
FUNC(void, OS_CODE) OsIntc_ResumeOsInterrupts
(
    CoreIdType CoreID
)
{
    OsIntc_ReplaceIntPriority(CoreID, OsIntc_IntPri_Backup[CoreID]);
}

/*****************************************************************************
* cross core interrupt
******************************************************************************/
#if(OS_USED_CORE_NUMBER > 1)
/* BEGIN_FUNCTION_HDR
***********************************************************************************************
* Function Name: OsIntc_CrossCoreIntInit
*
* Description:   Cross Core Interrupt Init
*
* Inputs:        None
*
* Outputs:       None
*
* Limitations:   Called in generated ISR, interrupt must be disabled before call this API, Ctx must be saved
***********************************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, OS_CODE) OsIntc_CrossCoreIntInit
(
    CoreIdType CoreID
)
{
    if(CoreID == (CoreIdType)0)
    {
        /*PRQA S 3383 ++*/
        /* Writing 0 to 32 bits register can not overflow. */
        OS_PL_SRC_GPSR0(CoreID).B.TOS = (Os_uint32)0;
        /*PRQA S 3383 --*/
    }
    else
    {
        /*PRQA S 3383 ++*/
        /* Writing u8 value to 32 bits register can not overflow. */
        OS_PL_SRC_GPSR0(CoreID).B.TOS = (Os_uint32)(CoreID) + (Os_uint32)1;
        /*PRQA S 3383 --*/
    }
    /*PRQA S 3383,4599 ++*/
    /* Writing u32 type number to 32 bits register can not overflow. */
    OS_PL_SRC_GPSR0(CoreID).B.SRPN = (Os_uint32)(Os_ISRCfg[Os_CoreCfg[CoreID].crossCoreIsrId].Prio); 
    OS_PL_SRC_GPSR0(CoreID).B.SRE = (Os_uint32)1;
    /*PRQA S 3383,4599 --*/

    /* Check register val */
    /*PRQA S 3345,3383,3442 ++*/
    /* Just read value from register and compare them here. */
    if(((Os_uint32)OS_PL_SRC_GPSR0(CoreID).B.SRPN != (Os_uint32)(Os_ISRCfg[Os_CoreCfg[CoreID].crossCoreIsrId].Prio)) ||\
        ((Os_uint32)OS_PL_SRC_GPSR0(CoreID).B.SRE != (Os_uint32)1))
    /*PRQA S 3345,3383,3442 --*/
    {
        OsHook_FataErrReport(CoreID, E_OS_PL_SYSFATA_REG_ERR, OSServiceId_OsIntc_CrossCoreIntInit,\
                OS_IE_NOMORE_INFO, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR);
    }
}

/* BEGIN_FUNCTION_HDR
***********************************************************************************************
* Function Name: OsIntc_CrossCoreIntClear
*
* Description:   Clear CrossCore interrupt
*
* Inputs:        None
*
* Outputs:       None
*
* Limitations:   None
***********************************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, OS_CODE) OsIntc_CrossCoreIntClear
(
    CoreIdType CoreID
)
{
    /*PRQA S 3383 ++*/
    /* Writing u32 type number to 32 bits register can not overflow. */
    OS_PL_SRC_GPSR0(CoreID).B.CLRR = (Os_uint32)1;
    /*PRQA S 3383 --*/
}

/* BEGIN_FUNCTION_HDR
***********************************************************************************************
* Function Name: OsIntc_CrossCoreISR
*
* Description:   Entering a CrossCoreISR
*
* Inputs:        None
*
* Outputs:       None
*
* Limitations:   Called in generated ISR, interrupt must be disabled before call this API, Ctx must be saved
***********************************************************************************************
END_FUNCTION_HDR*/
FUNC(void, OS_CODE) OsIntc_CrossCoreISR(void)
{
    CoreIdType CoreID;
    CoreID = OsCpu_GetCoreID();
    OsMultiCore_CrossCoreProcess(CoreID);
    OsIntc_CrossCoreIntClear(CoreID);
}
#endif/*#if(OS_USED_CORE_NUMBER > 1)*/

/*****************************************************************************
* OS ISR in out process function
******************************************************************************/

/* BEGIN_FUNCTION_HDR
***********************************************************************************************
* Function Name: OsIsr_OutISR2
*
* Description:   Leaving a Category 2 interrupt
*
* Inputs:        None
*
* Outputs:       None
*
* Limitations:   Called in generated ISR, after user ISR hook
***********************************************************************************************
END_FUNCTION_HDR*/
FUNC(void, OS_CODE) OsIntc_OutISR2(void)
{
    Os_boolean tempReSchFlag;
    Os_AddrType tempRetAddr;
    CoreIdType CoreID;
    Os_uint32 pcx;
    Os_uint32 val;
    CoreID = OsCpu_GetCoreID();
    OsIntc_DisableGlobalInterrupt(CoreID);/* User ISR may enable interrupt nest, so we must disable it here*/
    
    /*PRQA S 3200 ++*/
    /* "OsMpu_SetKernel" is an inline function without return value. */
    OsMpu_SetKernel();/* switch mpu from user ISR  to kernel*/
    /*PRQA S 3200 --*/

    tempReSchFlag = OsIsr_OutISR2(CoreID);
    /* outIsr2 is jump from the end of ISR, so no need to consider CDC and release CSA*/
    if(tempReSchFlag == OS_TRUE)
    {
        OS_PL_JUMP(&OsCpu_TaskSwitch);
    }
    else/*return to saved context*/
    {
        if(Os_IntNestDepth[CoreID] != OS_INVALID_ISR)
        {
#if(OS_ON == OS_ISR_NEST_SUPPORT)
            tempRetAddr = Os_ISRCBTable[Os_CoreCfg[CoreID].nestIsrIdPtr[Os_IntNestDepth[CoreID]]].OsIsrCtxPtr;
            OsMpu_SetISR(CoreID, Os_CoreCfg[CoreID].nestIsrIdPtr[Os_IntNestDepth[CoreID]]);
#else
            /*fata err*/
            tempRetAddr = 0;
#endif
        }
        else
        {
            tempRetAddr = Os_TaskCBTable[Os_CurrentTaskId[CoreID]].OsTaskCtxPtr;
            OsMpu_SetTask(CoreID, Os_CurrentTaskId[CoreID]);
        }
        /* here check the tempRetAddr, as there is no way to restore to another task or ISR which is not interrupted by this ISR*/
        pcx = (OS_PL_MFCR(OS_PL_CPU_PCX_REG));
        val = (pcx & OS_PL_PCX_PCX_MASK);
        if((Os_uint32)tempRetAddr != val)
        {
            /*error*/
            OsHook_FataErrReport(CoreID, E_OS_PL_SYSFATA_CSA_ERR, OSServiceId_OsIntc_OutISR2,\
                OS_IE_NOMORE_INFO, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR);
        }
        OS_PL_DSYNC();
        OS_PL_RSLCX(); /* restore lower*/
        OS_PL_RFE();/* restore uppler0*/
    }
}

/* BEGIN_FUNCTION_HDR
***********************************************************************************************
* Function Name: OsIntc_InISR1
*
* Description:   Entering a Category 1 interrupt
*
* Inputs:        CoreID,ISRID
*
* Outputs:       None
*
* Limitations:   Called in generated ISR, interrupt must be disabled before call this API, Ctx must be saved
***********************************************************************************************
END_FUNCTION_HDR*/
FUNC (void, OS_CODE) OsIntc_InISR1
(
    CoreIdType CoreID,
    ISRType ISRID
)
{
    /* up and low context has been saved before this function*/
    /* interrupt has been disabled, interrupt priority has been set to current ISR*/
    /* MPU has been set to set0, which is kernel set*/
    OsIsr_InISR1(CoreID);
#if(OS_ON == OS_ISR_NEST_SUPPORT)
    if(Os_ISRCfg[ISRID].enNest == OS_TRUE)
    {
        OsIntc_EnableGlobalInterrupt(CoreID);
    }
#else
    (void) ISRID;
#endif
}

/* BEGIN_FUNCTION_HDR
***********************************************************************************************
* Function Name: OsIntc_OutISR1
*
* Description:   Leaving a Category 1 interrupt
*
* Inputs:        None
*
* Outputs:       None
*
* Limitations:   None
***********************************************************************************************
END_FUNCTION_HDR*/
FUNC(void, OS_CODE) OsIntc_OutISR1(void)
{
    CoreIdType CoreID;
    
    CoreID = OsCpu_GetCoreID();
    OsIntc_DisableGlobalInterrupt(CoreID);

    OsIsr_OutISR1(CoreID);

    OS_PL_DSYNC();
    OS_PL_RSLCX(); /* restore lower*/
    OS_PL_RFE();/* restore uppler0*/
}


/* BEGIN_FUNCTION_HDR
***********************************************************************************************
* Function Name: OsIntc_KillISRSchedule
*
* Description:   After running C2ISR is killed, call this function to schedule
*
* Inputs:        None
*
* Outputs:       None
*
* Limitations:   Called in generated ISR, after user ISR hook
***********************************************************************************************
END_FUNCTION_HDR*/
FUNC(void, OS_CODE) OsIntc_KillISRSchedule
(
    CoreIdType CoreID,
    ISRType ISRID,
    Os_boolean needSchedule
)
{
#if(OS_ON == OS_ISR_NEST_SUPPORT)
    ISRType tempISRID;
#endif
    Os_AddrType tempRetAddr;
    Os_uint32 pcx;
    Os_AddrType val;

    /* free CSA of current running ISR*/
    /*PRQA S 2740 ++*/
    /* There's "break" in "while" loop so can not be dead loop. */
    while(1)/* loop until CSA arrive  or CSA = 0(ERROR STATE) */
    /*PRQA S 2740 --*/
    {
        pcx = (OS_PL_MFCR(OS_PL_CPU_PCX_REG));
        val = (pcx & OS_PL_PCX_PCX_MASK);

        if(val == (Os_AddrType)0)
        {
            /*FATA error report*/
        }

        pcx = pcx & OS_PL_PCX_UL_LOWMASK; /* clear UL so that can use rslcx cmd below */
        pcx = pcx & OS_PL_PCX_PIE_DISMASK;/* clear PIE to avoid enable interrupt  */

        OS_PL_MTCR(OS_PL_CPU_PCX_REG, pcx);
        OS_PL_ISYNC();
        OS_PL_DSYNC();
        OS_PL_RSLCX(); /* release this level ctx*/


        if(val == OsIntc_FirstISRCSA[ISRID])
        {
            OsIntc_FirstISRCSA[ISRID] = (Os_AddrType)0;
            break;
        }

    }

    /* clear all CDC, so that RFE can be used in OsCpu_TaskSwitch*/
    val = (OS_PL_MFCR(OS_PL_CPU_PSW_REG));
    val = val & OS_PL_PSW_CDC_CLEAR_MASK;
    OS_PL_MTCR(OS_PL_CPU_PSW_REG, val);
    OS_PL_ISYNC();  
    if(needSchedule == OS_TRUE)
    {
        OS_PL_JUMP(&OsCpu_TaskSwitch);
    }
    else/*return to saved context*/
    {
        if(Os_IntNestDepth[CoreID] != OS_INVALID_ISR)
        {
#if(OS_ON == OS_ISR_NEST_SUPPORT)
            tempISRID = Os_CoreCfg[CoreID].nestIsrIdPtr[Os_IntNestDepth[CoreID]];
            tempRetAddr = Os_ISRCBTable[tempISRID].OsIsrCtxPtr;
            /*switch to task mpu set as mpu not saved in CSA*/
            OsMpu_SetISR(CoreID, tempISRID);
#else
            /*Fata err*/
            OsHook_FataErrReport(CoreID, E_OS_PL_SYSFATA_ISRNEST_ERR, OSServiceId_OsIntc_KillISRSchedule,\
                OS_IE_NOMORE_INFO, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR);
            return;
#endif
        }
        else
        {
            tempRetAddr = Os_TaskCBTable[Os_CurrentTaskId[CoreID]].OsTaskCtxPtr;
            /*switch to task mpu set as mpu not saved in CSA*/
            OsMpu_SetTask(CoreID, Os_CurrentTaskId[CoreID]);
        }

        /* dont need check tempRetAddr here*/

        /* PCX set to restore CSA addr,
         * PIE = 0, to keep disable interrupt
         * UL = 0, as restore lower first
         * PCPN, dont care, clear it to 0
         *  */
        OS_PL_MTCR(OS_PL_CPU_PCX_REG, tempRetAddr);
        OS_PL_ISYNC();
        OS_PL_DSYNC();
        OS_PL_RSLCX();/* lower CSA restore*/

        /* upper CSA restore here
         * Stack pointer, global interrupt state , interrupt priority will all be restored here
         * MPU set1 (Task ISR Set) will also be restore here
         * */
        OS_PL_RFE();
    }
}


/* BEGIN_FUNCTION_HDR
***********************************************************************************************
* Function Name: OsIntc_FreeISRCSA
*
* Description:   free ISR CSA, only used in terminate App
*
* Inputs:        CoreID,ISRID
*
* Outputs:       None
*
* Limitations:   None
***********************************************************************************************
END_FUNCTION_HDR*/
FUNC(void, OS_CODE) OsIntc_FreeISRCSA
(
    CoreIdType CoreID,
    ISRType ISRID
)
{
    /*PRQA S 4643 ++*/
    /* Do not include <ctype.h>. */
    ISRType isrIdx;
    /*PRQA S 4643 --*/
    ISRType tmpIsrId;
#if(OS_ON == OS_ISR_NEST_SUPPORT)
    Os_uint32 val;
    Os_uint32 val_1;
    Os_uint32 mpupcxo_temp;
    Os_uint32 mpupcxs_temp;
    Os_uint32 mpupcxi_temp;
    Os_uint32 mpupcxo_temp1;
    Os_uint32 mpupcxs_temp1;
    Os_uint32 mpupcxi_temp1;
    Os_uint32 i;
#endif
    /*PRQA S 3432 ++*/
    /*
    P2VAR and other macros in the Compiler conforms to AUTOSAR standard.
    There's no need to revise.
    */
    P2VAR(ISRType, AUTOMATIC, OS_VAR) nestPtr;
    /*PRQA S 3432 --*/

    nestPtr = Os_CoreCfg[CoreID].nestIsrIdPtr;

    /* loop and remove all ISR belongs to this app, at same time re-sort the queue*/
    for(isrIdx = (ISRType)0; isrIdx < Os_IntNestDepth[CoreID]; isrIdx++)
    {
        tmpIsrId = nestPtr[isrIdx];
        if(ISRID == tmpIsrId)
        {
#if(OS_ON == OS_ISR_NEST_SUPPORT)
            i = (Os_uint32)0;
            val = (Os_uint32)OsIntc_FirstISRCSA[nestPtr[isrIdx]];
            do
            {
                /*PRQA S 3383 ++*/
                /*
                Can not overflow because of "for" and "do...while..." loop.
                */
                i ++;
                val_1 = (Os_uint32)OsIntc_FirstISRCSA[nestPtr[isrIdx + i]];
                /*PRQA S 3383 --*/
            } while (val_1 == (Os_uint32)0);

            
            val_1 &=  OS_PL_PCX_PCX_MASK;
            /* Get Saved PCXI.PCXO*/
            mpupcxo_temp = (OS_PL_PCX_PCXO_MASK & val) << OS_PL_PCX_PCXO_SHIFT;
            /* Get Saved PCXI.PCXS*/
            mpupcxs_temp = (OS_PL_PCX_PCXS_MASK & val) << OS_PL_PCX_PCXS_SHIFT;
            /* Get Saved Upper*/
            mpupcxi_temp = mpupcxo_temp | mpupcxs_temp;

            /* Get Saved PCXI.PCXO*/
            mpupcxo_temp1 = (OS_PL_PCX_PCXO_MASK & val_1) << OS_PL_PCX_PCXO_SHIFT;
            /* Get Saved PCXI.PCXS*/
            mpupcxs_temp1 = (OS_PL_PCX_PCXS_MASK & val_1) << OS_PL_PCX_PCXS_SHIFT;
            /* Get Saved Upper*/
            mpupcxi_temp1 = mpupcxo_temp1 | mpupcxs_temp1;

            (*(Os_uint32*)mpupcxi_temp1) = (*(Os_uint32*)mpupcxi_temp);
#endif
            OsIntc_FirstISRCSA[nestPtr[isrIdx]] = (Os_AddrType)0;
            break;
        }
    }
}

#if((OS_TIMING_PROTECTION_SUPPORT == OS_ON)||(OS_MEM_PROTECTION_SUPPORT == OS_ON)||(OS_APPLICATION_NUMBER > 0))
/* BEGIN_FUNCTION_HDR
***********************************************************************************************
* Function Name: OsIntc_EnableISR
*
* Description:   Enable the ISR
*
* Inputs:        CoreID,ISRID
*
* Outputs:       None
*
* Limitations:   None
***********************************************************************************************
END_FUNCTION_HDR*/
FUNC(void, OS_CODE) OsIntc_EnableISR(CoreIdType CoreID, ISRType ISRID)
{
    (void) CoreID;
    /*PRQA S 3383 ++*/
    /* Writing u32 type number to 32 bits register can not overflow. */
    OS_PL_SRC(Os_ISRCfg[ISRID].vectorIndex).B.SRE = (Os_uint32)1; /* enable interrupt */
    /*PRQA S 3383 --*/
}

/* BEGIN_FUNCTION_HDR
***********************************************************************************************
* Function Name: OsIntc_DisableISR
*
* Description:   Disable the ISR
*
* Inputs:        CoreID,ISRID
*
* Outputs:       None
*
* Limitations:   None
***********************************************************************************************
END_FUNCTION_HDR*/
FUNC(void, OS_CODE) OsIntc_DisableISR(CoreIdType CoreID, ISRType ISRID)
{
    (void) CoreID;
    /*PRQA S 3383 ++*/
    /* Writing u32 type number to 32 bits register can not overflow. */
    /* disable interrupt */
    OS_PL_SRC(Os_ISRCfg[ISRID].vectorIndex).B.SRE = (Os_uint32)0;
    /* clear pending interrupt */
    OS_PL_SRC(Os_ISRCfg[ISRID].vectorIndex).B.CLRR = (Os_uint32)1;
    /*PRQA S 3383 --*/
}

/* BEGIN_FUNCTION_HDR
***********************************************************************************************
* Function Name: OsIntc_ClearPendingISR
*
* Description:   Clear the Pending ISR
*
* Inputs:        CoreID,ISRID
*
* Outputs:       None
*
* Limitations:   None
***********************************************************************************************
END_FUNCTION_HDR*/
FUNC(void, OS_CODE) OsIntc_ClearPendingISR(CoreIdType CoreID, ISRType ISRID)
{
    (void) CoreID;
    /* clear pending interrupt */
    /*PRQA S 3383 ++*/
    /* Writing u32 type number to 32 bits register can not overflow. */
    OS_PL_SRC(Os_ISRCfg[ISRID].vectorIndex).B.CLRR = (Os_uint32)1;
    /*PRQA S 3383 --*/
}
#endif

/* BEGIN_FUNCTION_HDR
***********************************************************************************************
* Function Name: OsIntc_CheckISREnabled
*
* Description:   Check whether the interrupt is enable
*
* Inputs:        CoreID,ISRID
*
* Outputs:       None
*
* Limitations:   None
***********************************************************************************************
END_FUNCTION_HDR*/
FUNC(Os_boolean, OS_CODE) OsIntc_CheckISREnabled
(
    CoreIdType CoreID, 
    ISRType ISRID
)
{
    (void) CoreID;
    Os_boolean isEnable;

    if(OS_PL_SRC(Os_ISRCfg[ISRID].vectorIndex).B.SRE == (Os_uint32)1)
    {
        isEnable = OS_TRUE;
    }
    else
    {
        isEnable = OS_FALSE;
    }

    return isEnable;
}
#define OS_STOP_SEC_CODE
#include "Os_MemMap.h"

