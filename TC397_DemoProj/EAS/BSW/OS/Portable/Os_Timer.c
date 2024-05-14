/*BEGIN_FILE_HDR
********************************************************************************
* NOTICE
* This software is the property of HiRain Technologies. Any information
* contained in this doc should not be reproduced, or used, or disclosed
* without the written authorization from HiRain Technologies.
********************************************************************************
* File Name:       Os_Timer.c
********************************************************************************
* Project/Product: AUTOSAR OS PROJECT
* Title:           Os_Timer.c
* Author:          Hirain
********************************************************************************
* Description:     System Timer and tp Timer Module of OS
*
********************************************************************************
* Limitations     : None
*
********************************************************************************
*
********************************************************************************
* Revision History:
* Reference to Os_Cpu.c File
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
/*PRQA S 0303 EOF*/
/*
Not cast but access memory or registers by pointer.
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

/*PRQA S 3119 EOF*/
/*
Some parameters will not be used in different configurations and hardware 
platforms, but they can not be deleted according to the requirements of 
AUTOSAR specification or compatibility. So we retain these parameters for 
compatibility and convert them with (void) to clean the warnings in compiler.
PRQA notices such statements as warning 3119, it has been suppressed here.
*/

/*PRQA S 3442 EOF*/
/*
They are essential operators to access registers.
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
STATIC VAR(Os_uint32, OS_VAR) Os_lastCnt[OS_PL_MAX_CORE_NUMBER];
STATIC VAR(Os_uint32, OS_VAR) Os_lastCmp[OS_PL_MAX_CORE_NUMBER];
#define OS_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap.h"


/*****************************************************************************
* MACRO
******************************************************************************/
#define OS_PL_STM_CMCON_MSIZE1_VAL  ((Os_uint32)0x0000001F)
#define OS_PL_STM_SR_TOS_OFFSET     ((Os_uint32)11)
#define OS_CNT_ADJUSTMENT           ((Os_uint32)300)/*adjustment time about 0.002ms-0.003ms*/
#define OS_CNT_MAXVALUE             (0xFFFFFFFF)
#define OS_SYS_TIMER_MAX_VALUE      (0xFFFFFFFF)
#if(OS_ON == OS_TP_FCTIMER_NEED)
#define OS_TP_FCTIMER_MAX_VALUE     (0xFFFFFFFF)
#endif
#define OS_START_SEC_CODE
#include "Os_MemMap.h"
/*****************************************************************************
* Os Internal Functions
******************************************************************************/

/* BEGIN_FUNCTION_HDR
***********************************************************************************************
* Function Name: OsSysTimer_Init
*
* Description:   Sys timer init
*
* Inputs:        CoreID
*
* Outputs:       None
*
* Limitations:   None
***********************************************************************************************
END_FUNCTION_HDR*/

FUNC(void, OS_CODE) OsSysTimer_Init
(
    CoreIdType CoreID
)
{
    CoreIdType phyCoreId = Os_LogCoreToPhy[CoreID];
    Os_uint32 stmsr_tos = phyCoreId;
    Os_uint32 stm_pri;
    Os_uint16 cpuWdtPassword;

    /* here tos must be physical core id*/
    /* tos is in bit11:13, and 001 is used for DMA,so when coreid >1, need to stmsr_tos++*/
    if(stmsr_tos > (Os_uint32)0)
    {
        /*PRQA S 3383 ++*/
        /*
        "stmsr_tos"(u32) get value from "phyCoreId" which type is u8.
        Can not overflow here.
        */
        stmsr_tos = stmsr_tos + (Os_uint32)1;
        /*PRQA S 3383 --*/
    }

    stmsr_tos = stmsr_tos << OS_PL_STM_SR_TOS_OFFSET;

    stm_pri = Os_ISRCfg[Os_CoreCfg[CoreID].sysCntIsrId].Prio;

    cpuWdtPassword = OsCpu_GetCpuWatchdogPassword(phyCoreId);
    OsCpu_ClearCpuEndinit(phyCoreId, cpuWdtPassword);

    /*PRQA S 3383 ++*/
    /*
    Writing u32 type number to 32 bits registers and 
    bit operation can not overflow.
    */
    OS_PL_STM_CLC(CoreID) = (Os_uint32)0;
    OS_PL_STM_CMP0(CoreID) = (Os_uint32)0;
    OS_PL_STM_CMP1(CoreID) = (Os_uint32)0;
    OS_PL_STM_CMCON(CoreID) = OS_PL_STM_CMCON_MSIZE1_VAL;

    /* MUST USE |=, as ICR reseved bit can not be write 0, it will cause trap*/
    OS_PL_STM_ICR(CoreID) = OS_PL_STM_CMCOM_CM0EN_MASK; /* enable cmp0en*/

    OS_PL_STM_SR(CoreID, 0) &= OS_PL_STM_SR_SRE_CLEAR_MASK;/* 1st disable stm*/
    OS_PL_STM_SR(CoreID, 0) |= stmsr_tos;
    OS_PL_STM_SR(CoreID, 0) |= stm_pri;
    OS_PL_STM_SR(CoreID, 0) |= OS_PL_STM_SR_CLRR_MASK; /*CLEAR INT FLAG*/
    /*PRQA S 3383 --*/
    
    OsCpu_SetCpuEndinit(phyCoreId, cpuWdtPassword);

    /*PRQA S 3345,3383 ++*/
    /*
    This statement contains more than one access to objects that are 'volatile'.
    This part has been verified and has no problem.
    Reading u32 type number from 32 bits register and bit operation can not overflow.
    */
    if((OS_PL_STM_CLC(CoreID) != (Os_uint32)0) || (OS_PL_STM_CMP0(CoreID) != (Os_uint32)0) || (OS_PL_STM_CMP1(CoreID) != (Os_uint32)0) ||\
        ((OS_PL_STM_ICR(CoreID) & OS_PL_STM_CMCOM_CM0EN_MASK) == (Os_uint32)0 ) )
    /*PRQA S 3345,3383 --*/
    /* Check register val */
    {
        OsHook_FataErrReport(CoreID, E_OS_PL_SYSFATA_REG_ERR, OSServiceId_OsSysTimer_Init,\
                OS_IE_NOMORE_INFO, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR);
    }
}

/* BEGIN_FUNCTION_HDR
***********************************************************************************************
* Function Name: OsSysTimer_Run
*
* Description:   start system timer
*
* Inputs:        CoreID
*
* Outputs:       None
*
* Limitations:   None
***********************************************************************************************
END_FUNCTION_HDR*/
FUNC(void, OS_CODE) OsSysTimer_Run
(
    CoreIdType CoreID
)
{
    /*PRQA S 3345,3383 ++*/
    /*
    This statement contains more than one access to objects that are 'volatile'.
    This part has been verified and has no problem.
    Do not care overflow here.
    */
    OS_PL_STM_CMP0(CoreID) = OS_PL_STM_TIM0(CoreID) + OS_PL_SYSTIMER_RELOAD_VAL;
    /*PRQA S 3345,3383 --*/

    /*PRQA S 3383 ++*/
    /* Reading u32 type number from 32 bits register can not overflow. */
    OS_PL_STM_SR(CoreID, 0) |= (OS_PL_STM_SR_CLRR_MASK|OS_PL_STM_SR_SRE_MASK); /*CLEAR INT FLAG, enable int*/
    /*PRQA S 3383 --*/
    Os_lastCnt[CoreID] = OS_PL_STM_TIM0(CoreID);
    Os_lastCmp[CoreID] = OS_PL_STM_CMP0(CoreID);
}


/* BEGIN_FUNCTION_HDR
***********************************************************************************************
* Function Name: OsSysTimer_Stop
*
* Description:   stop system timer SRC_STM0SR0.B.SRE = 0;
*
* Inputs:        CoreID
*
* Outputs:       None
*
* Limitations:   None
***********************************************************************************************
END_FUNCTION_HDR*/ 
/*Has been implemented in the form of macro definitions in the Os_Pl_InternalCode.h file*/


/* BEGIN_FUNCTION_HDR
***********************************************************************************************
* Function Name: OsSysTimer_GetTimer
*
* Description:   get system timer, read TIM0
*
* Inputs:        CoreID
*
* Outputs:       None
*
* Limitations:   None
***********************************************************************************************
END_FUNCTION_HDR*/
/*Has been implemented in the form of macro definitions in the Os_Pl_InternalCode.h file*/


/* BEGIN_FUNCTION_HDR
***********************************************************************************************
* Function Name: OsSysTimer_GetElapsedTime
*
* Description:   get elapsed time of system timer
*
* Inputs:        CoreID
*
* Outputs:       None
*
* Limitations:   None
***********************************************************************************************
END_FUNCTION_HDR*/
FUNC(Os_SysTickType, OS_CODE) OsSysTimer_GetElapsedTime
(
    CoreIdType CoreID,
    Os_SysTickType startTime
)
{
    Os_SysTickType dtime;
    /*PRQA S 4603,3383 ++*/
    /* Do not include <time.h>. */
    /* Reading u32 type number from 32 bits register can not overflow. */
    Os_SysTickType ctime = OS_PL_STM_TIM0(CoreID);
    /*PRQA S 4603,3383 --*/

    if(startTime < ctime)
    {
        /*PRQA S 3383 ++*/
        /* The "if..." here confirms that underflow will not happen. */
        dtime = ctime - startTime;
        /*PRQA S 3383 --*/
    }
    else
    {
        dtime = OS_SYS_TIMER_MAX_VALUE - (startTime - ctime);
    }

    return dtime;
}


/* BEGIN_FUNCTION_HDR
***********************************************************************************************
* Function Name: OsSystemTimer_ISR
*
* Description:   called when system timer interrupt triggered
*
* Inputs:        None
*
* Outputs:       None
*
* Limitations:   None
***********************************************************************************************
END_FUNCTION_HDR*/
FUNC(void, OS_CODE) OsSysTimer_ISR(void)
{
    CoreIdType CoreID;

    CoreID = OsCpu_GetCoreID();
    Os_uint32 dCnt;
    Os_uint32 dCmp_Cnt;
    Os_uint32 Os_addcmp_ideal;
    if(Os_lastCnt[CoreID] <= OS_PL_STM_TIM0(CoreID))
    {
    	dCnt = OS_PL_STM_TIM0(CoreID) - Os_lastCnt[CoreID];
    }
    else
    {
    	dCnt = OS_PL_STM_TIM0(CoreID) + (OS_CNT_MAXVALUE - Os_lastCnt[CoreID]);
    }
    if(dCnt > (OS_PL_SYSTIMER_RELOAD_VAL*2))
    {
    	OS_PL_STM_CMP0(CoreID) = OS_PL_STM_TIM0(CoreID) + OS_CNT_ADJUSTMENT;
    	Os_addcmp_ideal = (dCnt / OS_PL_SYSTIMER_RELOAD_VAL -1)*OS_PL_SYSTIMER_RELOAD_VAL;
    	Os_lastCmp[CoreID] = Os_lastCmp[CoreID] + Os_addcmp_ideal;
    }
    else
    {
    	OS_PL_STM_CMP0(CoreID) = Os_lastCmp[CoreID] + OS_PL_SYSTIMER_RELOAD_VAL;
    	if(OS_PL_STM_CMP0(CoreID) > OS_PL_STM_TIM0(CoreID))
    	{
    		dCmp_Cnt = OS_PL_STM_CMP0(CoreID) - OS_PL_STM_TIM0(CoreID);
    	}
    	else
    	{
    		dCmp_Cnt = OS_PL_STM_CMP0(CoreID) + (OS_CNT_MAXVALUE- OS_PL_STM_TIM0(CoreID));
    	}
    	if(dCmp_Cnt < OS_CNT_ADJUSTMENT)
    	{
    		OS_PL_STM_CMP0(CoreID) = OS_PL_STM_CMP0(CoreID) + OS_CNT_ADJUSTMENT;
    	}
    	Os_lastCmp[CoreID] = OS_PL_STM_CMP0(CoreID);
    }
    Os_lastCnt[CoreID] = OS_PL_STM_TIM0(CoreID);
    /*
    STM5_CMP0.U = (STM5_TIM0.U + OS_PL_SYSTIMER_RELOAD_VAL);
    SRC_STM5SR0.B.CLRR = 1;
    STM5_ISCR.B.CMP0IRR = 1;
    SRC_STM5SR0.B.SRE = 1;
    */
    /*PRQA S 3345,3383 ++*/
    /*
    This statement contains more than one access to objects that are 'volatile'.
    This part has been verified and has no problem.
    */
    /* Writing 32 bits register with u32 type number can not overflow. */

    OS_PL_STM_ISCR(CoreID) = OS_PL_STM_ISCR_CMP0IRR_MASK;/* clear CMP0IRR */
    OS_PL_STM_SR(CoreID, 0) |= (OS_PL_STM_SR_CLRR_MASK|OS_PL_STM_SR_SRE_MASK); /*CLEAR INT FLAG, enable int*/

    OsCnt_InternalIncreaseCounter(CoreID, Os_CoreCfg[CoreID].startCntId);

    /*STM5_ICR.B.CMP0EN = 1;*/
    /* Writing 32 bits register with u32 type number can not overflow. */
    OS_PL_STM_ICR(CoreID) = OS_PL_STM_CMCOM_CM0EN_MASK;
    /*PRQA S 3345,3383 --*/
}


/*****************************************************************************
* Os TP timer
******************************************************************************/
#if(OS_ON == OS_TP_TIMER_NEED)


/* BEGIN_FUNCTION_HDR
***********************************************************************************************
* Function Name: OsTpTimer_Init
*
* Description:   Init timer used by time protection
*
* Inputs:        CoreID
*
* Outputs:       None
*
* Limitations:   None
***********************************************************************************************
END_FUNCTION_HDR*/
FUNC (void, OS_CODE) OsTpTimer_Init 
(
    CoreIdType CoreID
)
{
    Os_uint32 val;

    (void)CoreID;

    val = OS_PL_MFCR(OS_PL_CPU_SYSCON_REG);
    val |= OS_PL_SYSCON_TPEN_MASK; /* enable tproten bit*/
    OS_PL_MTCR(OS_PL_CPU_SYSCON_REG, val);

}


/* BEGIN_FUNCTION_HDR
***********************************************************************************************
* Function Name: OsTpTimer_Set
*
* Description:   Set the time value and start tp timer, If timer value reached, may generate interrupt
*
* Inputs:        CoreID, value
*
* Outputs:       Os_uint32, return the current timer val
*
* Limitations:   the value is delta valus, if nessary, this funtion need to read current value and add to rel value
***********************************************************************************************
END_FUNCTION_HDR*/
FUNC(Os_TpTickType, OS_CODE) OsTpTimer_Set
(
    CoreIdType CoreID,
    Os_TpTickType value
)
{
    (void)CoreID;
    /* set non zero value to start tp timer, and then timer will--*/
    OS_PL_MTCR(OS_PL_TPS_TIMER(OS_TPTIMER_CHANNEL), value);
    return value;
}


/* BEGIN_FUNCTION_HDR
***********************************************************************************************
* Function Name: OsTpTimer_Stop
*
* Description:   Stop the tp timer , implement as macro
*
* Inputs:        CoreID, channel
*
* Outputs:       None
*
* Limitations:   None
***********************************************************************************************
END_FUNCTION_HDR*/
/*Has been implemented in the form of macro definitions in the Os_Pl_InternalCode.h file*/


/* BEGIN_FUNCTION_HDR
***********************************************************************************************
* Function Name: OsTpTimer_GetElapsedTime
*
* Description:   Get Elapsed time from start
*
* Inputs:        CoreID, startTime
*
* Outputs:       Os_TpTickType
*
* Limitations:   Not possible if timer overflow/underflow twice
***********************************************************************************************
END_FUNCTION_HDR*/
FUNC(Os_TpTickType, OS_CODE) OsTpTimer_GetElapsedTime
(
    CoreIdType CoreID,
    Os_TpTickType startTime
)
{
    (void)CoreID;
    /*PRQA S 4603,0604 ++*/
    /* Do not include <time.h>. */
    /* This operation is allowed in C99. */
    Os_TpTickType ctime = OS_PL_MFCR(OS_PL_TPS_TIMER(OS_TPTIMER_CHANNEL));
    /*PRQA S 4603,0604 --*/

    if(startTime < ctime)
    {
        /* FATA not possible */
        OsHook_FataErrReport(CoreID, E_OS_PL_SYSFATA_TP_TIMER_ERROR, OSServiceId_OsTpTimer_GetElapsedTime, OS_IE_NOMORE_INFO, startTime, ctime, OS_IE_NO_ERRPAR);
    }

    return (startTime - ctime);
}


/* BEGIN_FUNCTION_HDR
***********************************************************************************************
* Function Name: OsTpTimer_Get
*
* Description:   Get Current time ,implement as macro
*
* Inputs:        CoreID,
*
* Outputs:       Os_uint32
*
* Limitations:   None
***********************************************************************************************
END_FUNCTION_HDR*/
/*Has been implemented in the form of macro definitions in the Os_Pl_InternalCode.h file*/


/* BEGIN_FUNCTION_HDR
***********************************************************************************************
* Function Name: OsTpTimer_ISR
*
* Description:  process timing protection error
*
* Inputs:        None
*
* Outputs:       None
*
* Limitations:   None
***********************************************************************************************
END_FUNCTION_HDR*/
FUNC(void, OS_CODE) OsTpTimer_ISR(void)
{
    Os_uint32 val;

    /* Step1, save context */
    /* upper ctx has been saved during trap*/
    /* ctx is only used if user ignore this protection event*/
    OS_PL_SVLCX();/* save lower*/
    OS_PL_ISYNC();

    val = OS_PL_MFCR(OS_PL_TPS_CON_REG);
    /*Tp Timer expire*/
    if((Os_uint32)0 != (val & OS_PL_TPS_CON_TIMER0_MASK))
    {
        OS_PL_MTCR(OS_PL_TPS_TIMER(OS_TPTIMER_CHANNEL), 0);
    }
#if(OS_ON == OS_TP_FCTIMER_NEED)
    /*Fc Timer expire, do nothing, reset to max value*/
    if((Os_uint32)0 != (val & OS_PL_TPS_CON_TIMER1_MASK))
    {
        OS_PL_MTCR(OS_PL_TPS_TIMER(OS_TPFCTIMER_CHANNEL), 0);
        OS_PL_MTCR(OS_PL_TPS_TIMER(OS_TPFCTIMER_CHANNEL), OS_TP_FCTIMER_MAX_VALUE);
    }
#endif
    OS_PL_MTCR(OS_PL_TPS_CON_REG, 0);/* write dummy to clear TPS_CON_REG*/
    if((Os_uint32)0 != (val & OS_PL_TPS_CON_TIMER0_MASK))
    {
        OsTp_ProtectionProcess();
    }


    /* if user do not ignore, all process will be done in OsTp_ProtectionProcess
     * OsTp_ProtectionProcess will not return here
     * */

    /* if user ignore, restore the context*/
    OS_PL_RSLCX();
    OS_PL_RFE();

}

#endif

#if(OS_ON == OS_TP_FCTIMER_NEED)



/* BEGIN_FUNCTION_HDR
***********************************************************************************************
* Function Name: OsTpFcTimer_Init
*
* Description:   init fc timer
*
* Inputs:        CoreID
*
* Outputs:       None
*
* Limitations:   None
***********************************************************************************************
END_FUNCTION_HDR*/
FUNC(void, OS_CODE) OsTpFcTimer_Init
(
    CoreIdType CoreID
)
{
    (void)CoreID;

    /* take channel 2 as free run timer, so write max value to start it*/
    OS_PL_MTCR(OS_PL_TPS_TIMER(OS_TPFCTIMER_CHANNEL), OS_TP_FCTIMER_MAX_VALUE);

}

/* BEGIN_FUNCTION_HDR
***********************************************************************************************
* Function Name: OsTpFcTimer_Stop
*
* Description:   Stop the fc tp timer , implement as macro
*
* Inputs:        CoreID,
*
* Outputs:       None
*
* Limitations:   None
***********************************************************************************************
END_FUNCTION_HDR*/
/*Has been implemented in the form of macro definitions in the Os_Pl_InternalCode.h file*/


/* BEGIN_FUNCTION_HDR
***********************************************************************************************
* Function Name: OsTpFcTimer_GetElapsedTime
*
* Description:   Get elapsed time used by frame check
*
* Inputs:        CoreID,startTime
*
* Outputs:       Os_TpTickType
*
* Limitations:   None
***********************************************************************************************
END_FUNCTION_HDR*/
FUNC(Os_TpTickType, OS_CODE) OsTpFcTimer_GetElapsedTime
(
    CoreIdType CoreID,
    Os_TpTickType startTime
)
{
    Os_TpTickType dtime;
    /*PRQA S 4603 ++*/
    /* Do not include <time.h>. */
    Os_TpTickType ctime = OS_PL_MFCR(OS_PL_TPS_TIMER(OS_TPFCTIMER_CHANNEL));
    /*PRQA S 4603 --*/

    (void)CoreID;


    if(startTime > ctime)
    {
        /*PRQA S 3383 ++*/
        /* The "if..." here confirms that overflow/underflow will not happen. */
        dtime = startTime - ctime;
        /*PRQA S 3383 --*/
    }
    else
    {
        dtime = OS_TP_FCTIMER_MAX_VALUE - (ctime - startTime);
    }


    return dtime;
}


/* BEGIN_FUNCTION_HDR
***********************************************************************************************
* Function Name: OsTpFcTimer_Get
*
* Description:   Get Current time user by frame check, implement as macro
*
* Inputs:        CoreID,
*
* Outputs:       Os_uint32
*
* Limitations:   None
***********************************************************************************************
END_FUNCTION_HDR*/
/*Has been implemented in the form of macro definitions in the Os_Pl_InternalCode.h file*/


#endif/*#if(OS_ON == OS_TIMING_PROTECTION_SUPPORT)*/


#if(OS_ON == OS_CPULOAD_API)
/* BEGIN_FUNCTION_HDR
***********************************************************************************************
* Function Name: OsCpuLoadTimer_Init
*
* Description:   Initialization of the timer used to calculate the CPU load
*
* Inputs:        CoreID
*
* Outputs:       None
*
* Limitations:   None
***********************************************************************************************
END_FUNCTION_HDR*/

/*In this version of the software, CpuLoadTimer and the system timer use the same hardware.
No need to initialize again.*/


/* BEGIN_FUNCTION_HDR
***********************************************************************************************
* Function Name: OsCpuLoadTimer_GetTimer
*
* Description:   Get current time value of the CPU load timer.
*
* Inputs:        CoreID
*
* Outputs:       Os_CpuLoadTickType
*
* Limitations:   None
***********************************************************************************************
END_FUNCTION_HDR*/
/*Has been implemented in the form of macro definitions in the Os_Pl_InternalCode.h file*/

/* BEGIN_FUNCTION_HDR
***********************************************************************************************
* Function Name: OsCpuLoadTimer_GetElapsedTime
*
* Description:   Get elapsed time of CPU load timer
*
* Inputs:        CoreID,startTime
*
* Outputs:       Os_CpuLoadTickType
*
* Limitations:   None
***********************************************************************************************
END_FUNCTION_HDR*/
/*Has been implemented in the form of macro definitions in the Os_Pl_InternalCode.h file*/

/* BEGIN_FUNCTION_HDR
***********************************************************************************************
* Function Name: OsCpuLoadTimer_Stop
*
* Description:   Stop the CPU load timer
*
* Inputs:        CoreID
*
* Outputs:       None
*
* Limitations:   None
***********************************************************************************************
END_FUNCTION_HDR*/

/*In this version of the software, CpuLoadTimer and the system timer use the same hardware.
    No need to stop here.*/


#endif



#define OS_STOP_SEC_CODE
#include "Os_MemMap.h"

