/*  BEGIN_FILE_HDR
********************************************************************************
*   NOTICE
*   This software is the property of HiRain Technologies. Any information
*   contained in this doc should not be reproduced, or used, or disclosed
*   without the written authorization from HiRain Technologies.
********************************************************************************
* File Name:       Os_Pl_Inl.h
********************************************************************************
* Project/Product: AUTOSAR OS PROJECT
* Title:           Os_Pl_Inl.h
* Author:          Hirain
********************************************************************************
* Description:     Define the inline functions of os
*
********************************************************************************
* Limitations     : If inline is used, must be always inline
*
********************************************************************************
*
********************************************************************************
*   Revision History:
*   Reference to Os_Cpu.c File
********************************************************************************
* END_FILE_HDR*/

#ifndef OS_PL_INL_H
#define OS_PL_INL_H

/*****************************************************************************
* files include
******************************************************************************/
#include "Os_Var.h"
#include "Os_InternalCode.h"
#include "Os_Pl_InternalCode.h"
#include "Os_Lcfg.h"

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

/*PRQA S 3432 EOF*/
/*
Parameters in macros or functions are useless for some hardware platforms, 
but they can not be deleted according to the requirements of 
AUTOSAR specification or compatibility.
*/

/*PRQA S 1055 EOF*/
/*
'inline' functions are a feature of ISO:C99 and compiler for TC3xx supports
ISO:C99.
*/

/*PRQA S 3114,2050 EOF*/
/*
Those 'inline' functions do not have return value.
*/

/*****************************************************************************

******************************************************************************/
extern VAR(Os_AddrType, OS_VAR) OsIntc_FirstISRCSA[OS_ISR_NUMBER];
#if(OS_ON == OS_MEM_PROTECTION_SUPPORT)
/* BEGIN_FUNCTION_HDR
***********************************************************************************************
* Function Name: OsMpu_SetKernel
*
* Description:   set mpu to kernel right, in 3xx, just set back to set0
*
* Inputs:        <CoreID> Reference to core,
*
*
* Outputs:       None
*
* Limitations:   None
***********************************************************************************************
END_FUNCTION_HDR*/
OS_INLINE_FUNC(void, OS_CODE) OsMpu_SetKernel
(
    void
)
{
    Os_uint32 val;

    val = OS_PL_MFCR(OS_PL_CPU_PSW_REG);
    val &= OS_PL_PSW_PRS_CLEARMASK;/* just clear all bit, which means set to set0*/
    OS_PL_MTCR(OS_PL_CPU_PSW_REG, val);
}
#else

#define OsMpu_SetKernel()
#endif

#if(OS_APPLICATION_NUMBER > 0)
/*****************************************************************************
* Cpu
* Function Name: OsCpu_PreAPI
*
* Description:   Change sys mode, PSW will be restorn when return, so OS_INLINE_FUNC
*
*
* Inputs:        None
*
* Outputs:       None
*
* Limitations:   Used in OsPl_Api.c
***********************************************************************************************
******************************************************************************/
OS_INLINE_FUNC(void, OS_CODE) OsCpu_PreAPI(void)
{
    Os_uint32 tempMode;
    tempMode = (Os_uint32)OS_PL_MFCR(OS_PL_CPU_PSW_REG);
    tempMode = (tempMode & OS_PL_PSW_IO_MASK);
    tempMode = tempMode >> OS_PL_PSW_IO_SHIFT;

    if(tempMode != (Os_uint32)ACCESSMODE_PRIVILEGED)
    {
        OS_PL_SYSCALL(OS_SYSCALL_KERNEL_TIN);
    }
	else
    {
        OsMpu_SetKernel();
    }
}
#endif

/*****************************************************************************
* MPU
******************************************************************************/
/* BEGIN_FUNCTION_HDR
***********************************************************************************************
* Function Name: OsMpu_SetTaskMode
*
* Description:   Change sys mode, PSW will be restorn when return, so OS_INLINE_FUNC
*
*
* Inputs:        None
*
* Outputs:       None
*
* Limitations:   Used in Task Switch
***********************************************************************************************
END_FUNCTION_HDR*/
OS_INLINE_FUNC(void, OS_CODE)OsMpu_SetTaskMode
(
    CoreIdType CoreID,
    TaskType TaskID
)
{
#if(OS_APPLICATION_NUMBER > 0)
    ApplicationType ApplID;
    Os_uint32 tempMode = (Os_uint32)0;
    Os_uint32 userMode = (Os_uint32)0;

    ApplID = Os_TaskCfg[TaskID].ApplID;

    /* if trusted application or idle task, just set to kernel set*/
    if ( TaskID == Os_CoreCfg[CoreID].idleTaskId )
    {
        OS_PL_EnableInterrupts();
    }
    else if(OS_TRUE != Os_AppCfg[ApplID].isTrusted)
    {

        userMode = (Os_uint32)Os_Pl_TaskCfg[TaskID].AccessMode;
        tempMode = OS_PL_MFCR(OS_PL_CPU_PSW_REG);
        tempMode = (tempMode & (~OS_PL_PSW_IO_MASK));
        tempMode = (tempMode | (userMode << OS_PL_PSW_IO_SHIFT));
        
        OS_PL_MTCR(OS_PL_CPU_PSW_REG, tempMode);
        if(userMode == (Os_uint32)ACCESSMODE_USER_1)
        {
            OS_PL_EnableInterrupts();
        }
        else if(userMode == (Os_uint32)ACCESSMODE_USER_0)
        {
            OS_PL_SYSCALL(OS_SYSCALL_USER0_TIN);
        }
        else
        {
            /*do nothing*/
        }
    }
    else
#else
    (void)CoreID;
    (void)TaskID;
#endif
    {
        OS_PL_EnableInterrupts();
    }    
}


/*****************************************************************************
* INTC
******************************************************************************/

/* BEGIN_FUNCTION_HDR
***********************************************************************************************
* Function Name: OsIntc_InISR2
*
* Description:   Entering a Category 2 interrupt
*
* Inputs:        None
*
* Outputs:       None
*
* Limitations:   Called in generated ISR, interrupt must be disabled before call this API, Ctx must be saved
***********************************************************************************************
END_FUNCTION_HDR*/
OS_INLINE_FUNC(void, OS_CODE) OsIntc_InISR2
(
    CoreIdType CoreID,
    ISRType ISRID,
    Os_uint32 val,
    Os_uint32 fcx
)
{
    /* up and low context has been saved before this function*/
    /* global interrupt has been disabled by hw before this function*/
    /*in TC3XX when enter ISR, MPU has been set to Set0, which is kernel set
     * so we dont need to change mpu here
     * */
    OsIsr_InISR2(CoreID, ISRID, val);



    /*switch to user ISR stack */
    /*PRQA S 0306 ++*/
    /* Fake macro for QAC to instead assembly instructions. */
    OS_PL_SET_REG(sp, Os_ISRCfg[ISRID].OsIsrStkBottom);
    /*PRQA S 0306 --*/

    OsIntc_FirstISRCSA[ISRID] = (Os_AddrType)fcx;
    OsMpu_SetISR(CoreID, ISRID);
#if(OS_ON == OS_ISR_NEST_SUPPORT)
    if(Os_ISRCfg[ISRID].enNest == OS_TRUE)
    {
        OsIntc_EnableGlobalInterrupt(CoreID);
    }
#endif
}

/* BEGIN_FUNCTION_HDR
***********************************************************************************************
* Function Name: OsIntc_C2ISRPreProcess
*
* Description:   Entering a Category 2 interrupt
*
* Inputs:        None
*
* Outputs:       None
*
* Limitations:   Called in generated ISR, must be inline function
***********************************************************************************************
END_FUNCTION_HDR*/
OS_INLINE_FUNC(void, OS_CODE) OsIntc_C2ISRPreProcess
(
    CoreIdType CoreID,
    ISRType ISRID
)
{
    Os_uint32 pcx;
    Os_uint32 val;
    Os_uint32 fcx;
    /* up and low context has been saved before this function*/
    /* global interrupt has been disabled by hw before this function*/
    /*in TC3XX when enter ISR, MPU has been set to Set0, which is kernel set
     * so we dont need to change mpu here
     * */
#if(OS_APPLICATION_NUMBER > 0)
    if(Os_ISRCBTable[ISRID].isKilled == OS_TRUE) 
    {
        /* ISR killed do nothing, just return*/
        OS_PL_RSLCX(); /* restore lower*/
        OS_PL_RFE();/* restore uppler0*/
    }
#endif

    fcx = OS_PL_MFCR(OS_PL_CPU_FCX_REG);

    pcx = (OS_PL_MFCR(OS_PL_CPU_PCX_REG));
    val = (pcx & OS_PL_PCX_PCX_MASK);

    /*PRQA S 3200 ++*/
    /* Inline function "OsIntc_InISR2" do not have return value. */
    OsIntc_InISR2(CoreID, ISRID, val, fcx);
    /*PRQA S 3200 --*/
}

/* BEGIN_FUNCTION_HDR
***********************************************************************************************
* Function Name: OsIntc_C1ISRPreProcess
*
* Description:   Entering a Category 1 interrupt
*
* Inputs:        None
*
* Outputs:       None
*
* Limitations:   Called in generated ISR, must be inline function
***********************************************************************************************
END_FUNCTION_HDR*/
OS_INLINE_FUNC(void, OS_CODE) OsIntc_C1ISRPreProcess
(
    CoreIdType CoreID,
    ISRType ISRID
)
{
    /* up and low context has been saved before this function*/
    /* global interrupt has been disabled by hw before this function*/
    /*in TC3XX when enter ISR, MPU has been set to Set0, which is kernel set
     * so we dont need to change mpu here
     * */
#if(OS_APPLICATION_NUMBER > 0)
    if(Os_ISRCBTable[ISRID].isKilled == OS_TRUE)
    {
        /* ISR killed do nothing, just return*/
        OS_PL_RSLCX(); /* restore lower*/
        OS_PL_RFE();/* restore uppler0*/
    }
#endif

    OsIntc_InISR1(CoreID, ISRID);
}

/*PRQA S 3120,3206,3397,3401,3971,4446 ++*/
/* Those errors and wanings are caused by assembly instructions in PRQA. */
OS_INLINE_FUNC(Os_uint32, OS_CODE) OsCpu_CmpandSwap (Os_uint32 *address, Os_uint32 value, Os_uint32 condition)
{
#if defined(OS_QAC)
    Os_uint64 reg64 = value | (Os_uint64) condition << (Os_uint32)32;

#else
    return __cmpswapw(address,value,condition);
#endif /* OS_QAC */
}
/*PRQA S 3120,3206,3397,3401,3971,4446 --*/
#endif

