/*  BEGIN_FILE_HDR
********************************************************************************
*   NOTICE
*   This software is the property of HiRain Technologies. Any information
*   contained in this doc should not be reproduced, or used, or disclosed
*   without the written authorization from HiRain Technologies.
********************************************************************************
* File Name:       Os_GenCode.c
********************************************************************************
* Project/Product: AUTOSAR OS PROJECT
* Title:           Os_GenCode.c
* Author:          Hirain
********************************************************************************
* Description:     Define the variables used in different os modules
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

/*PRQA S 0862 EOF*/
/*
The code segment like:

#define XXX
#include "Os_MemMap.h"

is a part of AUTOSAR specification, but will be an error in PRQA.
*/

/*PRQA S 3408 EOF*/
/*
For TC3xx, trap functions are called by hardware, so no need to declaration.
*/

/*PRQA S 3116 EOF*/
/*
"#pragma section" directives are different for different compilers.
This part has been verified and has no problem.
*/

/*****************************************************************************
* Generated Isr functions
******************************************************************************/
#if defined(__TASKING__)
#pragma optimize 0
#endif

#define OS_START_SEC_CODE
#include "Os_MemMap.h"

/*
    Trap0 - MMU
    Trap1 - Internal Protection Traps
    Trap2 - Instruction Errors
    Trap3 - Context Management
    Trap4 - System Bus and Peripheral Errors
    Trap5 - Assertion Traps
    Trap6 - System Call -recoverable
    Trap7 - NMI -recoverable

*/



/*
 * for each trap, global interrupt has been disabled
 * if enter endless loop, it will cause wdg reset
 * */
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: OS_TRAP_0
*
* Description:  process Trap 0
*
* Inputs:        None
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, OS_CODE) OS_TRAP_0(void)
{
    /*PRQA S 3196 ++*/
    /* "tin" is used by assembly instructions. */
    Os_uint8 tin;
    /*PRQA S 3196 --*/
    OS_PL_GETTIN(tin);
    Os_PL_Trap0_Hook(tin);

    for (;;)
    {
    }
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: OS_TRAP_1
*
* Description:  process Trap 1
*
* Inputs:        None
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, OS_CODE) OS_TRAP_1(void)
{
    /*PRQA S 3196 ++*/
    /* "tin" is used by assembly instructions. */
    Os_uint8 tin;
    /*PRQA S 3196 --*/
    OS_PL_GETTIN(tin);

#if(OS_ON == OS_MEM_PROTECTION_SUPPORT)
    /* tin = 3 and tin = 4 is process by OS, other tin will dead here
     * as os only monitor the invalid write access*/
    if((tin == (Os_uint8)OS_MEMPROT_WRITE_TIN)||(tin == (Os_uint8)OS_MEMPROT_READ_TIN)||(tin == (Os_uint8)OS_MEMPROT_EXEC_TIN))
    {
        OS_PL_JUMP(&OsMpu_ProtectionISR);
    }
    else
#endif
    {
        /* If tin = 5, A program executing in User-0 mode attempted a load or 
         * store access to a segment is configured to be a peripheral segment. */
        Os_PL_Trap1_Hook(tin);  
        for (;;)
        {
        }
    }

}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: OS_TRAP_2
*
* Description:  process Trap 2
*
* Inputs:        None
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, OS_CODE) OS_TRAP_2(void)
{
    /*PRQA S 3196 ++*/
    /* "tin" is used by assembly instructions. */
    Os_uint8 tin;
    /*PRQA S 3196 --*/
    OS_PL_GETTIN(tin);
    Os_PL_Trap2_Hook(tin); 

    for (;;)
    {
    }
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: OS_TRAP_3
*
* Description:  process Trap 3
*
* Inputs:        None
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, OS_CODE) OS_TRAP_3(void)
{
    /*PRQA S 3196 ++*/
    /* "tin" is used by assembly instructions. */
    Os_uint8 tin;
    /*PRQA S 3196 --*/
    OS_PL_GETTIN(tin);
    Os_PL_Trap3_Hook(tin); 

    for (;;)
    {
    }
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: OS_TRAP_4
*
* Description:  process Trap 4
*
* Inputs:        None
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, OS_CODE) OS_TRAP_4(void)
{
    /*PRQA S 3196 ++*/
    /* "tin" is used by assembly instructions. */
    Os_uint8 tin;
    /*PRQA S 3196 --*/
    OS_PL_GETTIN(tin);

#if(OS_ON == OS_TP_TIMER_NEED)
    /* only tin = 7 is process by OS, other tin will dead here */
    if(tin == (Os_uint8)OS_TIMEPROT_TIN)
    {
        OS_PL_JUMP(&OsTpTimer_ISR);
    }
    else
#endif
    {
        Os_PL_Trap4_Hook(tin);
        for (;;)
        {
        }
    }


}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: OS_TRAP_5
*
* Description:  process Trap 5
*
* Inputs:        None
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, OS_CODE) OS_TRAP_5(void)
{
    /*PRQA S 3196 ++*/
    /* "tin" is used by assembly instructions. */
    Os_uint8 tin;
    /*PRQA S 3196 --*/
    OS_PL_GETTIN(tin);
    Os_PL_Trap5_Hook(tin); 

    for (;;)
    {
    }
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: OS_TRAP_6
*
* Description:  process Trap 6
*
* Inputs:        None
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, OS_CODE) OS_TRAP_6(void)
{
    /*PRQA S 3196 ++*/
    /* "tin" is used by assembly instructions. */
    Os_uint8 tin;
    /*PRQA S 3196 --*/
#if(OS_APPLICATION_NUMBER > 0)
    Os_uint32 *psw_temp;
    Os_uint32 mpupcxi_temp;
    Os_uint32 mpupcxo_temp;
    Os_uint32 mpupcxs_temp;
#endif
    /* Only save upper, when trap, so save lower, otherwise local var will change lower*/
    OS_PL_SVLCX();    
    
    OS_PL_GETTIN(tin);

    if(tin == (Os_uint8)OS_SYSCALL_TIN)
    {
        OS_PL_RSLCX();
        OS_PL_DSYNC();
        OS_PL_JUMP(&OsCpu_InternalTaskPreempt);
    }
#if(OS_APPLICATION_NUMBER > 0)
    else if(tin == (Os_uint8)OS_SYSCALL_KERNEL_TIN)
    {
        OS_PL_RSLCX();
        OS_PL_DSYNC();

        /* Get Saved PCXI*/
        mpupcxi_temp = (OS_PL_MFCR(OS_PL_CPU_PCX_REG));
        /* Get Saved PCXI.PCXO*/
        mpupcxo_temp = (OS_PL_PCX_PCXO_MASK & mpupcxi_temp) << OS_PL_PCX_PCXO_SHIFT;
        /* Get Saved PCXI.PCXS*/
        mpupcxs_temp = (OS_PL_PCX_PCXS_MASK & mpupcxi_temp) << OS_PL_PCX_PCXS_SHIFT;
        /* Get Saved Uper*/
        mpupcxi_temp = mpupcxo_temp | mpupcxs_temp;
        /*PRQA S 0306,3383,4397,4570 ++*/
        /*
        Cast to pointer after caculate address on value.
        No overflow here.
        Confirmed that types are correct here.
        */
        /* Get Saved PSW*/
        psw_temp = (Os_uint32 *) (mpupcxi_temp + OS_PL_UPPER_PSW_SHIFT);
        /* Change Saved PSW.PSR and PSW.IO*/
        *psw_temp = ((*psw_temp) & (~(OS_PL_PSW_PRS_MASK | OS_PL_PSW_IO_MASK))) | ((Os_uint32)ACCESSMODE_PRIVILEGED << OS_PL_PSW_IO_SHIFT);
        /*PRQA S 0306,3383,4397,4570 --*/
        /* Restore Upper, Return Saved PSW.PSR and PSW.IO*/
        OS_PL_RFE();
    }
    else if (tin == (Os_uint8)OS_SYSCALL_USER0_TIN)
    {
        OS_PL_RSLCX();
        OS_PL_DSYNC();
        mpupcxi_temp = (OS_PL_MFCR(OS_PL_CPU_PCX_REG));
        mpupcxi_temp |= OS_PL_PCX_PIE_MASK;
        OS_PL_MTCR(OS_PL_CPU_PCX_REG,mpupcxi_temp);
        OS_PL_RFE();/* restore uppler0*/
    }
#endif
    else
    {
        Os_PL_Trap6_Hook(tin);
        OS_PL_RSLCX();
        OS_PL_DSYNC();
        OS_PL_RFE();
    }
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: OS_TRAP_7
*
* Description:  process Trap 7
*
* Inputs:        None
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, OS_CODE) OS_TRAP_7(void)
{
    /*PRQA S 3196 ++*/
    /* "tin" is used by assembly instructions. */
    Os_uint8 tin;
    /*PRQA S 3196 --*/
    OS_PL_GETTIN(tin);
    Os_PL_Trap7_Hook(tin); 
    OS_PL_RFE();
}


#define OS_STOP_SEC_CODE
#include "Os_MemMap.h"


#if(OS_PL_MAX_CORE_NUMBER > 0)
#pragma section code="traptab_cpu0"
#pragma align 4
#pragma protect
/* BEGIN_FUNCTION_HDR
***********************************************************************************************
* Function Name: Os_Pl_CpuxTrap
*
* Description:   Vector table of  trap in different core
*
* Inputs:        None
*
* Outputs:       None
*
* Limitations:  None
***********************************************************************************************
END_FUNCTION_HDR*/
FUNC(void, OS_CODE) Os_Pl_Cpu0Trap (void)
{
    /* ; Special trap table used during the Trap test: */
#if defined(OS_QAC)
    OS_TRAP_0();
    OS_TRAP_1();
    OS_TRAP_2();
    OS_TRAP_3();
    OS_TRAP_4();
    OS_TRAP_5();
    OS_TRAP_6();
    OS_TRAP_7();
#else
    /* ; Class 0, MMU Traps: */
    __asm (".align 256");
    __asm("j       OS_TRAP_0"); /* Jump to the trap handler */

    /* ; Class 1, Internal Protection Traps: */
    __asm(".align 32");
    __asm("j       OS_TRAP_1"); /* Jump to the trap handler */

    /* ; Class 2, Instruction Error Traps: */
    __asm(".align 32");
    __asm("j       OS_TRAP_2"); /* Jump to the trap handler */

    /* ; Class 3, Context Management Traps: */
    __asm(".align 32");
    __asm("j       OS_TRAP_3"); /* Jump to the trap handler */

    /* ; Class 4, System Bus and Peripheral Error Traps: */
    __asm(".align 32");
    __asm("j       OS_TRAP_4"); /* Jump to the trap handler */

    /* ; Class 5, Assertion Traps: */
    __asm(".align 32");
    __asm("j       OS_TRAP_5"); /* Jump to the trap handler */

    /* ; Class 6, System Call Trap: */
    __asm(".align 32");
    __asm("j       OS_TRAP_6"); /* Jump to the trap handler */

    /* ; Class 7, Non Maskable Interrupt Traps: */
    __asm(".align 32");
    __asm("j       OS_TRAP_7"); /* Jump to the trap handler */
#endif /* OS_QAC */
}
#pragma section code restore
#pragma align 4
#pragma endprotect
#endif

#if(OS_PL_MAX_CORE_NUMBER > 1)
#pragma section code="traptab_cpu1"
#pragma align 4
#pragma protect
/* BEGIN_FUNCTION_HDR
***********************************************************************************************
* Function Name: Os_Pl_CpuxTrap
*
* Description:   Vector table of  trap in different core
*
* Inputs:        None
*
* Outputs:       None
*
* Limitations:  None
***********************************************************************************************
END_FUNCTION_HDR*/
FUNC(void, OS_CODE) Os_Pl_Cpu1Trap (void)
{
    /* ; Special trap table used during the Trap test: */
#if defined(OS_QAC)
    OS_TRAP_0();
    OS_TRAP_1();
    OS_TRAP_2();
    OS_TRAP_3();
    OS_TRAP_4();
    OS_TRAP_5();
    OS_TRAP_6();
    OS_TRAP_7();
#else
    /* ; Class 0, MMU Traps: */
    __asm (".align 256");
    __asm("j       OS_TRAP_0"); /* Jump to the trap handler */

    /* ; Class 1, Internal Protection Traps: */
    __asm(".align 32");
    __asm("j       OS_TRAP_1"); /* Jump to the trap handler */

    /* ; Class 2, Instruction Error Traps: */
    __asm(".align 32");
    __asm("j       OS_TRAP_2"); /* Jump to the trap handler */

    /* ; Class 3, Context Management Traps: */
    __asm(".align 32");
    __asm("j       OS_TRAP_3"); /* Jump to the trap handler */

    /* ; Class 4, System Bus and Peripheral Error Traps: */
    __asm(".align 32");
    __asm("j       OS_TRAP_4"); /* Jump to the trap handler */

    /* ; Class 5, Assertion Traps: */
    __asm(".align 32");
    __asm("j       OS_TRAP_5"); /* Jump to the trap handler */

    /* ; Class 6, System Call Trap: */
    __asm(".align 32");
    __asm("j       OS_TRAP_6"); /* Jump to the trap handler */

    /* ; Class 7, Non Maskable Interrupt Traps: */
    __asm(".align 32");
    __asm("j       OS_TRAP_7"); /* Jump to the trap handler */
#endif /* OS_QAC */
}
#pragma section code restore
#pragma align 4
#pragma endprotect
#endif

#if(OS_PL_MAX_CORE_NUMBER > 2)
#pragma section code="traptab_cpu2"
#pragma align 4
#pragma protect
/* BEGIN_FUNCTION_HDR
***********************************************************************************************
* Function Name: Os_Pl_CpuxTrap
*
* Description:   Vector table of  trap in different core
*
* Inputs:        None
*
* Outputs:       None
*
* Limitations:  None
***********************************************************************************************
END_FUNCTION_HDR*/
FUNC(void, OS_CODE) Os_Pl_Cpu2Trap (void)
{
    /* ; Special trap table used during the Trap test: */
#if defined(OS_QAC)
    OS_TRAP_0();
    OS_TRAP_1();
    OS_TRAP_2();
    OS_TRAP_3();
    OS_TRAP_4();
    OS_TRAP_5();
    OS_TRAP_6();
    OS_TRAP_7();
#else
    /* ; Class 0, MMU Traps: */
    __asm (".align 256");
    __asm("j       OS_TRAP_0"); /* Jump to the trap handler */

    /* ; Class 1, Internal Protection Traps: */
    __asm(".align 32");
    __asm("j       OS_TRAP_1"); /* Jump to the trap handler */

    /* ; Class 2, Instruction Error Traps: */
    __asm(".align 32");
    __asm("j       OS_TRAP_2"); /* Jump to the trap handler */

    /* ; Class 3, Context Management Traps: */
    __asm(".align 32");
    __asm("j       OS_TRAP_3"); /* Jump to the trap handler */

    /* ; Class 4, System Bus and Peripheral Error Traps: */
    __asm(".align 32");
    __asm("j       OS_TRAP_4"); /* Jump to the trap handler */

    /* ; Class 5, Assertion Traps: */
    __asm(".align 32");
    __asm("j       OS_TRAP_5"); /* Jump to the trap handler */

    /* ; Class 6, System Call Trap: */
    __asm(".align 32");
    __asm("j       OS_TRAP_6"); /* Jump to the trap handler */

    /* ; Class 7, Non Maskable Interrupt Traps: */
    __asm(".align 32");
    __asm("j       OS_TRAP_7"); /* Jump to the trap handler */
#endif /* OS_QAC */
}
#pragma section code restore
#pragma align 4
#pragma endprotect
#endif


#if(OS_PL_MAX_CORE_NUMBER > 3)
#pragma section code="traptab_cpu3"
#pragma align 4
#pragma protect
/* BEGIN_FUNCTION_HDR
***********************************************************************************************
* Function Name: Os_Pl_CpuxTrap
*
* Description:   Vector table of  trap in different core
*
* Inputs:        None
*
* Outputs:       None
*
* Limitations:  None
***********************************************************************************************
END_FUNCTION_HDR*/
FUNC(void, OS_CODE) Os_Pl_Cpu3Trap (void)
{
    /* ; Special trap table used during the Trap test: */
#if defined(OS_QAC)
    OS_TRAP_0();
    OS_TRAP_1();
    OS_TRAP_2();
    OS_TRAP_3();
    OS_TRAP_4();
    OS_TRAP_5();
    OS_TRAP_6();
    OS_TRAP_7();
#else
    /* ; Class 0, MMU Traps: */
    __asm (".align 256");
    __asm("j       OS_TRAP_0"); /* Jump to the trap handler */

    /* ; Class 1, Internal Protection Traps: */
    __asm(".align 32");
    __asm("j       OS_TRAP_1"); /* Jump to the trap handler */

    /* ; Class 2, Instruction Error Traps: */
    __asm(".align 32");
    __asm("j       OS_TRAP_2"); /* Jump to the trap handler */

    /* ; Class 3, Context Management Traps: */
    __asm(".align 32");
    __asm("j       OS_TRAP_3"); /* Jump to the trap handler */

    /* ; Class 4, System Bus and Peripheral Error Traps: */
    __asm(".align 32");
    __asm("j       OS_TRAP_4"); /* Jump to the trap handler */

    /* ; Class 5, Assertion Traps: */
    __asm(".align 32");
    __asm("j       OS_TRAP_5"); /* Jump to the trap handler */

    /* ; Class 6, System Call Trap: */
    __asm(".align 32");
    __asm("j       OS_TRAP_6"); /* Jump to the trap handler */

    /* ; Class 7, Non Maskable Interrupt Traps: */
    __asm(".align 32");
    __asm("j       OS_TRAP_7"); /* Jump to the trap handler */
#endif /* OS_QAC */
}
#pragma section code restore
#pragma align 4
#pragma endprotect
#endif

#if(OS_PL_MAX_CORE_NUMBER > 4)
#pragma section code="traptab_cpu4"
#pragma align 4
#pragma protect
/* BEGIN_FUNCTION_HDR
***********************************************************************************************
* Function Name: Os_Pl_CpuxTrap
*
* Description:   Vector table of  trap in different core
*
* Inputs:        None
*
* Outputs:       None
*
* Limitations:  None
***********************************************************************************************
END_FUNCTION_HDR*/
FUNC(void, OS_CODE) Os_Pl_Cpu4Trap (void)
{
    /* ; Special trap table used during the Trap test: */
#if defined(OS_QAC)
    OS_TRAP_0();
    OS_TRAP_1();
    OS_TRAP_2();
    OS_TRAP_3();
    OS_TRAP_4();
    OS_TRAP_5();
    OS_TRAP_6();
    OS_TRAP_7();
#else
    /* ; Class 0, MMU Traps: */
    __asm (".align 256");
    __asm("j       OS_TRAP_0"); /* Jump to the trap handler */

    /* ; Class 1, Internal Protection Traps: */
    __asm(".align 32");
    __asm("j       OS_TRAP_1"); /* Jump to the trap handler */

    /* ; Class 2, Instruction Error Traps: */
    __asm(".align 32");
    __asm("j       OS_TRAP_2"); /* Jump to the trap handler */

    /* ; Class 3, Context Management Traps: */
    __asm(".align 32");
    __asm("j       OS_TRAP_3"); /* Jump to the trap handler */

    /* ; Class 4, System Bus and Peripheral Error Traps: */
    __asm(".align 32");
    __asm("j       OS_TRAP_4"); /* Jump to the trap handler */

    /* ; Class 5, Assertion Traps: */
    __asm(".align 32");
    __asm("j       OS_TRAP_5"); /* Jump to the trap handler */

    /* ; Class 6, System Call Trap: */
    __asm(".align 32");
    __asm("j       OS_TRAP_6"); /* Jump to the trap handler */

    /* ; Class 7, Non Maskable Interrupt Traps: */
    __asm(".align 32");
    __asm("j       OS_TRAP_7"); /* Jump to the trap handler */
#endif /* OS_QAC */
}
#pragma section code restore
#pragma align 4
#pragma endprotect
#endif

#if(OS_PL_MAX_CORE_NUMBER > 5)
#pragma section code="traptab_cpu5"
#pragma align 4
#pragma protect
/* BEGIN_FUNCTION_HDR
***********************************************************************************************
* Function Name: Os_Pl_CpuxTrap
*
* Description:   Vector table of  trap in different core
*
* Inputs:        None
*
* Outputs:       None
*
* Limitations:  None
***********************************************************************************************
END_FUNCTION_HDR*/
FUNC(void, OS_CODE) Os_Pl_Cpu5Trap (void)
{
    /* ; Special trap table used during the Trap test: */
#if defined(OS_QAC)
    OS_TRAP_0();
    OS_TRAP_1();
    OS_TRAP_2();
    OS_TRAP_3();
    OS_TRAP_4();
    OS_TRAP_5();
    OS_TRAP_6();
    OS_TRAP_7();
#else
    /* ; Class 0, MMU Traps: */
    __asm (".align 256");
    __asm("j       OS_TRAP_0"); /* Jump to the trap handler */

    /* ; Class 1, Internal Protection Traps: */
    __asm(".align 32");
    __asm("j       OS_TRAP_1"); /* Jump to the trap handler */

    /* ; Class 2, Instruction Error Traps: */
    __asm(".align 32");
    __asm("j       OS_TRAP_2"); /* Jump to the trap handler */

    /* ; Class 3, Context Management Traps: */
    __asm(".align 32");
    __asm("j       OS_TRAP_3"); /* Jump to the trap handler */

    /* ; Class 4, System Bus and Peripheral Error Traps: */
    __asm(".align 32");
    __asm("j       OS_TRAP_4"); /* Jump to the trap handler */

    /* ; Class 5, Assertion Traps: */
    __asm(".align 32");
    __asm("j       OS_TRAP_5"); /* Jump to the trap handler */

    /* ; Class 6, System Call Trap: */
    __asm(".align 32");
    __asm("j       OS_TRAP_6"); /* Jump to the trap handler */

    /* ; Class 7, Non Maskable Interrupt Traps: */
    __asm(".align 32");
    __asm("j       OS_TRAP_7"); /* Jump to the trap handler */
#endif /* OS_QAC */
}
#pragma section code restore
#pragma align 4
#pragma endprotect
#endif

#if defined(__TASKING__)
#pragma endoptimize
#endif
