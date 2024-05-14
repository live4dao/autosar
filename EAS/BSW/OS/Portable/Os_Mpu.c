/*  BEGIN_FILE_HDR
********************************************************************************
*   NOTICE
*   This software is the property of HiRain Technologies. Any information
*   contained in this doc should not be reproduced, or used, or disclosed
*   without the written authorization from HiRain Technologies.
********************************************************************************
* File Name:       Os_Mpu.c
********************************************************************************
* Project/Product: AUTOSAR OS PROJECT
* Title:           Os_Mpu.c
* Author:          Hirain
********************************************************************************
* Description:     Define the Mpu functions of OS
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

/*PRQA S 3119 EOF*/
/*
Some parameters will not be used in different configurations and hardware 
platforms, but they can not be deleted according to the requirements of 
AUTOSAR specification or compatibility. So we retain these parameters for 
compatibility and convert them with (void) to clean the warnings in compiler.
PRQA notices such statements as warning 3119, it has been suppressed here.
*/

#if(OS_ON == OS_MEM_PROTECTION_SUPPORT)
/*********************************************************************************************
register   memory              Set0(Kernel/Isr1)   Set1(task/Isr2)     
DPR0       all memory data     rw                  r                   
DPR1       Task data           rw                  rw 
DPR2       register            rw                  rw                                    
DPR3       task stack          rw                  rw    
DPR4~15    application data    rw                  rw 
DPR16      kernel variable     rw                  rw 
DPR17      os config variable  rw                  rw                    
CPR0       all flash code      x                   n 
CPR1       os code             x                   x
CPR2~9     application code    x                   x                  
*********************************************************************************************/

/*****************************************************************************
* Mpu private macro
******************************************************************************/
#define OS_PL_MPU_KERNEL_SET    ((Os_uint32)0)
#define OS_PL_MPU_TASK_ISR_SET  ((Os_uint32)0x00001000)


/*****************************************************************************
* Mpu private code
******************************************************************************/





/*****************************************************************************
* Os Internal code
******************************************************************************/

/* BEGIN_FUNCTION_HDR
***********************************************************************************************
* Function Name: OsMpu_Init
*
* Description:   Init mpu
*
* Inputs:        <CoreID> Reference to core,
*
*
* Outputs:       None
*
* Limitations:   None
***********************************************************************************************
END_FUNCTION_HDR*/
FUNC(void, OS_CODE) OsMpu_Init
(
    CoreIdType CoreID
)
{
    Os_uint32 val;
    Os_uint32 tempval;

    (void)CoreID;

    /* set DPR0 with whole memory range*/
    /*PRQA S 3120 ++*/
    /* These number are const. */
    OS_PL_MTCR(OS_PL_DPRL(0), 0);
    OS_PL_MTCR(OS_PL_DPRU(0), 0xFFFFFFFF);

    /* set CPR0 with whole code memory range, flash start address is 0x80000000
    * but code maybe run in RAM, so set 0 - 0xFFFFFFFF
    */
    OS_PL_MTCR(OS_PL_CPRL(0), 0x0);
    OS_PL_MTCR(OS_PL_CPRU(0), 0xFFFFFFFF);

    /* init set0*/
    OS_PL_MTCR(OS_PL_DPRE(0), 0xFFFFFFFF);
    OS_PL_MTCR(OS_PL_DPWE(0), 0xFFFFFFFF);
    OS_PL_MTCR(OS_PL_CPXE(0), 0xFFFFFFFF);

    /* init set1*/
    OS_PL_MTCR(OS_PL_DPRE(1), 0xFFFFFFFE);
    OS_PL_MTCR(OS_PL_DPWE(1), 0xFFFFFFFE);
    OS_PL_MTCR(OS_PL_CPXE(1), 0xFFFFFFFE);

    /* init set2*/
    OS_PL_MTCR(OS_PL_DPRE(2), 0x0000001F);
    OS_PL_MTCR(OS_PL_DPWE(2), 0x0000001F);
    OS_PL_MTCR(OS_PL_CPXE(2), 0x00000001);
    /*PRQA S 3120 --*/

    /* make sure set0 is running*/
    val = OS_PL_MFCR(OS_PL_CPU_PSW_REG);
    tempval = (val & OS_PL_PSW_PRS_MASK);
    if(tempval != OS_PL_MPU_KERNEL_SET)
    {
        val = val & OS_PL_PSW_PRS_CLEARMASK;
        OS_PL_MTCR(OS_PL_CPU_PSW_REG, val);
    }

    /* enable mpu */
    OsMpu_Enable(CoreID);
}

/* BEGIN_FUNCTION_HDR
***********************************************************************************************
* Function Name: OsMpu_Enable
*
* Description:   Enable MPU
*
* Inputs:        <CoreID> Reference to core,
*
*
* Outputs:       None
*
* Limitations:   None
***********************************************************************************************
END_FUNCTION_HDR*/
FUNC(void, OS_CODE) OsMpu_Enable
(
    CoreIdType CoreID
)
{
    Os_uint32 val;

    (void)CoreID;

    val = OS_PL_MFCR(OS_PL_CPU_SYSCON_REG);
    val |= OS_PL_SYSCON_PEN_MASK;
    OS_PL_MTCR(OS_PL_CPU_SYSCON_REG, val);
}

/* BEGIN_FUNCTION_HDR
***********************************************************************************************
* Function Name: OsMpu_Disable
*
* Description:   Disable MPU
*
* Inputs:        <CoreID> Reference to core,
*
*
* Outputs:       None
*
* Limitations:   None
***********************************************************************************************
END_FUNCTION_HDR*/
FUNC(void, OS_CODE) OsMpu_Disable
(
    CoreIdType CoreID
)
{
    Os_uint32 val;

    (void)CoreID;

    val = OS_PL_MFCR(OS_PL_CPU_SYSCON_REG);
    val &= OS_PL_SYSCON_PEN_CLEAR_MASK;
    OS_PL_MTCR(OS_PL_CPU_SYSCON_REG, val);
}



/* BEGIN_FUNCTION_HDR
***********************************************************************************************
* Function Name: OsMpu_SetTask
*
* Description:   set mpu to task right, change the address range and set to set1
*
* Inputs:        CoreID, TaskID
*
*
* Outputs:       None
*
* Limitations:   None
***********************************************************************************************
END_FUNCTION_HDR*/

FUNC(void, OS_CODE) OsMpu_SetTask	
(
    CoreIdType CoreID,
    TaskType TaskID
)
{
    Os_uint32 val;
#if(OS_APPLICATION_NUMBER > 0)
    ApplicationType ApplID;
#endif
    Os_uint32 *psw_temp;
    Os_uint32 mpupcxi_temp;
    Os_uint32 mpupcxo_temp;
    Os_uint32 mpupcxs_temp;

    Os_uint32 DPWE_val = 0;
    Os_uint32 DPRE_val = 0;
    Os_uint32 CPXE_val = 0;
    Os_uint32 tempI = 0;

    (void)CoreID;
#if(OS_APPLICATION_NUMBER > 0)
    ApplID = Os_TaskCfg[TaskID].ApplID;

    /* if trusted application, just set to kernel set*/
    if ((TaskID == Os_CoreCfg[CoreID].idleTaskId) || (OS_TRUE == Os_AppCfg[ApplID].isTrusted))
    {
        val = OS_PL_MFCR(OS_PL_CPU_PSW_REG);
        val &= OS_PL_PSW_PRS_CLEARMASK;/* just clear all bit, which means set to set0*/
        OS_PL_MTCR(OS_PL_CPU_PSW_REG, val);
        return;
    }

    switch (Os_AppCfg[ApplID].mpuDataNum)
    {
        case 12:
            OS_PL_MTCR(OS_PL_DPRL(15), Os_AppCfg[ApplID].lowAddr[11]);
            OS_PL_MTCR(OS_PL_DPRU(15), Os_AppCfg[ApplID].highAddr[11]);
        case 11:
            OS_PL_MTCR(OS_PL_DPRL(14), Os_AppCfg[ApplID].lowAddr[10]);
            OS_PL_MTCR(OS_PL_DPRU(14), Os_AppCfg[ApplID].highAddr[10]);
        case 10:
            OS_PL_MTCR(OS_PL_DPRL(13), Os_AppCfg[ApplID].lowAddr[9]);
            OS_PL_MTCR(OS_PL_DPRU(13), Os_AppCfg[ApplID].highAddr[9]);
        case 9:
            OS_PL_MTCR(OS_PL_DPRL(12), Os_AppCfg[ApplID].lowAddr[8]);
            OS_PL_MTCR(OS_PL_DPRU(12),  Os_AppCfg[ApplID].highAddr[8]);
        case 8: 
            OS_PL_MTCR(OS_PL_DPRL(11), Os_AppCfg[ApplID].lowAddr[7]);  
            OS_PL_MTCR(OS_PL_DPRU(11), Os_AppCfg[ApplID].highAddr[7]);
        case 7:
            OS_PL_MTCR(OS_PL_DPRL(10), Os_AppCfg[ApplID].lowAddr[6]);
            OS_PL_MTCR(OS_PL_DPRU(10), Os_AppCfg[ApplID].highAddr[6]);
        case 6:
            OS_PL_MTCR(OS_PL_DPRL(9), Os_AppCfg[ApplID].lowAddr[5]);
            OS_PL_MTCR(OS_PL_DPRU(9), Os_AppCfg[ApplID].highAddr[5]);
        case 5:
            OS_PL_MTCR(OS_PL_DPRL(8), Os_AppCfg[ApplID].lowAddr[4]);
            OS_PL_MTCR(OS_PL_DPRU(8), Os_AppCfg[ApplID].highAddr[4]);
        case 4:
            OS_PL_MTCR(OS_PL_DPRL(7), Os_AppCfg[ApplID].lowAddr[3]);
            OS_PL_MTCR(OS_PL_DPRU(7),  Os_AppCfg[ApplID].highAddr[3]);
        case 3: 
            OS_PL_MTCR(OS_PL_DPRL(6), Os_AppCfg[ApplID].lowAddr[2]);  
            OS_PL_MTCR(OS_PL_DPRU(6), Os_AppCfg[ApplID].highAddr[2]);
        case 2:
            OS_PL_MTCR(OS_PL_DPRL(5), Os_AppCfg[ApplID].lowAddr[1]);
            OS_PL_MTCR(OS_PL_DPRU(5), Os_AppCfg[ApplID].highAddr[1]);
        case 1:
            OS_PL_MTCR(OS_PL_DPRL(4), Os_AppCfg[ApplID].lowAddr[0]);
            OS_PL_MTCR(OS_PL_DPRU(4), Os_AppCfg[ApplID].highAddr[0]);
            break;
        default:
            break;
    }

    for((tempI = (Os_AppCfg[ApplID].mpuDataNum+3)); tempI>0 ;tempI--)
    {
        DPWE_val += (1 << tempI);
    }
    /* read permission require two more section(DPR16 and DPR17) than write permission, */
    DPRE_val = (DPWE_val | (Os_uint32)0x30000);

#if(OS_MEM_PROTECTION_CODE_APPLICATION_SUPPORT == OS_ON) 

    OS_PL_MTCR(OS_PL_CPRL(1), Os_AppCfg[ApplID].osCodeLowAddr);  
    OS_PL_MTCR(OS_PL_CPRU(1), Os_AppCfg[ApplID].osCodeHighAddr);

    if(Os_AppCfg[ApplID].mpuCodeNum != 0)
    {
        switch (Os_AppCfg[ApplID].mpuCodeNum)
        {
            case 8:
                OS_PL_MTCR(OS_PL_CPRL(9), Os_AppCfg[ApplID].appCodeLowAddr[7]);
                OS_PL_MTCR(OS_PL_CPRU(9), Os_AppCfg[ApplID].appCodeHighAddr[7]);
            case 7:
                OS_PL_MTCR(OS_PL_CPRL(8), Os_AppCfg[ApplID].appCodeLowAddr[6]);
                OS_PL_MTCR(OS_PL_CPRU(8), Os_AppCfg[ApplID].appCodeHighAddr[6]);
            case 6: 
                OS_PL_MTCR(OS_PL_CPRL(7), Os_AppCfg[ApplID].appCodeLowAddr[5]);  
                OS_PL_MTCR(OS_PL_CPRU(7), Os_AppCfg[ApplID].appCodeHighAddr[5]);
            case 5:
                OS_PL_MTCR(OS_PL_CPRL(6), Os_AppCfg[ApplID].appCodeLowAddr[4]);
                OS_PL_MTCR(OS_PL_CPRU(6), Os_AppCfg[ApplID].appCodeHighAddr[4]);
            case 4:
                OS_PL_MTCR(OS_PL_CPRL(5), Os_AppCfg[ApplID].appCodeLowAddr[3]);
                OS_PL_MTCR(OS_PL_CPRU(5), Os_AppCfg[ApplID].appCodeHighAddr[3]);
            case 3: 
                OS_PL_MTCR(OS_PL_CPRL(4), Os_AppCfg[ApplID].appCodeLowAddr[2]);  
                OS_PL_MTCR(OS_PL_CPRU(4), Os_AppCfg[ApplID].appCodeHighAddr[2]);
            case 2:
                OS_PL_MTCR(OS_PL_CPRL(3), Os_AppCfg[ApplID].appCodeLowAddr[1]);
                OS_PL_MTCR(OS_PL_CPRU(3), Os_AppCfg[ApplID].appCodeHighAddr[1]);
            case 1:
                OS_PL_MTCR(OS_PL_CPRL(2), Os_AppCfg[ApplID].appCodeLowAddr[0]);
                OS_PL_MTCR(OS_PL_CPRU(2), Os_AppCfg[ApplID].appCodeHighAddr[0]);
                break;
            default:
                break;
        }

    }
    for((tempI = (Os_AppCfg[ApplID].mpuCodeNum+1)); tempI>0 ;tempI--)
    {
        CPXE_val += (1 << tempI);
    }
#else/* (OS_MEM_PROTECTION_CODE_APPLICATION_SUPPORT == OS_ON) */
    CPXE_val = (Os_uint32)0x3;
#endif/* (OS_MEM_PROTECTION_CODE_APPLICATION_SUPPORT == OS_ON) */

#else/* (OS_APPLICATION_NUMBER > 0) */
    CPXE_val = (Os_uint32)0x1;
    DPRE_val = (Os_uint32)0x1;
    DPWE_val = (Os_uint32)0xE;
#endif/* (OS_APPLICATION_NUMBER > 0) */


    /* set DPR1 for task data */
    OS_PL_MTCR(OS_PL_DPRL(1), Os_TaskCfg[TaskID].lowAddr);
    OS_PL_MTCR(OS_PL_DPRU(1), Os_TaskCfg[TaskID].highAddr);

    /* set DPR2 for peripheral */
    OS_PL_MTCR(OS_PL_DPRL(2), OS_PL_PERI_ADDR_LOW);
    OS_PL_MTCR(OS_PL_DPRU(2), OS_PL_PERI_ADDR_HIGH);

    /*PRQA S 0306 ++*/
    /* set DPR3 for task data's stack */
    OS_PL_MTCR(OS_PL_DPRL(3), (Os_AddrType)Os_TaskCfg[TaskID].OsTaskStkTop);
    OS_PL_MTCR(OS_PL_DPRU(3), (Os_AddrType)Os_TaskCfg[TaskID].OsTaskStkBottom);
    /*PRQA S 0306 --*/

    /* set DPR16 for os kernel variable */
    OS_PL_MTCR(OS_PL_DPRL(16), OS_KERNEL_NOINIT_Start);
    OS_PL_MTCR(OS_PL_DPRU(16), OS_KERNEL_NOINIT_End);

    /* set DPR17 for os config variable */
    OS_PL_MTCR(OS_PL_DPRL(17), OS_CONST_Start);
    OS_PL_MTCR(OS_PL_DPRU(17), OS_CONST_End);

    /* set protection set1*/
    OS_PL_MTCR(OS_PL_CPXE(1), CPXE_val);
    OS_PL_MTCR(OS_PL_DPWE(1), DPWE_val);
    OS_PL_MTCR(OS_PL_DPRE(1), DPRE_val);

    /* Get Saved PCXI*/
    mpupcxi_temp = (OS_PL_MFCR(OS_PL_CPU_PCX_REG));
    /* Get Saved PCXI.PCXO*/
    mpupcxo_temp = (OS_PL_PCX_PCXO_MASK & mpupcxi_temp) << OS_PL_PCX_PCXO_SHIFT;
    /* Get Saved PCXI.PCXS*/
    mpupcxs_temp = (OS_PL_PCX_PCXS_MASK & mpupcxi_temp) << OS_PL_PCX_PCXS_SHIFT;
    /* Get Saved Uper*/
    mpupcxi_temp = mpupcxo_temp | mpupcxs_temp;
    /* Get Saved PSW*/
    /*PRQA S 0306,3383 ++*/
    /* Caculate to get address. */
    psw_temp = (Os_uint32 *) (mpupcxi_temp + OS_PL_UPPER_PSW_SHIFT);
    /*PRQA S 0306,3383 --*/
    /* Change Saved PSW.PSR*/
    *psw_temp = ((*psw_temp) & (~(OS_PL_PSW_PRS_MASK))) | OS_PL_MPU_TASK_ISR_SET;
    /* Return Saved PSW.PSR*/
}


/* BEGIN_FUNCTION_HDR
***********************************************************************************************
* Function Name: OsMpu_SetISR
*
* Description:   Set mpu to ISR right, change the address range and set to set1
*
* Inputs:        CoreID, TaskId
*
*
* Outputs:       None
*
* Limitations:   None
***********************************************************************************************
END_FUNCTION_HDR*/
FUNC(void, OS_CODE) OsMpu_SetISR
(
    CoreIdType CoreID,
    ISRType ISRID
)
{
    Os_uint32 val;
#if(OS_APPLICATION_NUMBER > 0)
    ApplicationType ApplID;
#endif
    Os_uint32 *psw_temp;
    Os_uint32 mpupcxi_temp;
    Os_uint32 mpupcxo_temp;
    Os_uint32 mpupcxs_temp;

    Os_uint32 DPWE_val = 0;
    Os_uint32 DPRE_val = 0;
    Os_uint32 CPXE_val = 0;
    Os_uint32 tempI = 0;

    (void)CoreID;

#if(OS_APPLICATION_NUMBER > 0)
    ApplID = Os_ISRCfg[ISRID].ApplID;

    /* if trusted application, just set to kernel set*/
    if((ApplID == OS_INVALID_OSAPPLICATION) || (OS_TRUE == Os_AppCfg[ApplID].isTrusted))
    {
        val = OS_PL_MFCR(OS_PL_CPU_PSW_REG);
        val &= OS_PL_PSW_PRS_CLEARMASK;/* just clear all bit, which means set to set0*/
        OS_PL_MTCR(OS_PL_CPU_PSW_REG, val);
        return;
    }

    switch (Os_AppCfg[ApplID].mpuDataNum)
    {
        case 12:
            OS_PL_MTCR(OS_PL_DPRL(15), Os_AppCfg[ApplID].lowAddr[11]);
            OS_PL_MTCR(OS_PL_DPRU(15), Os_AppCfg[ApplID].highAddr[11]);
        case 11:
            OS_PL_MTCR(OS_PL_DPRL(14), Os_AppCfg[ApplID].lowAddr[10]);
            OS_PL_MTCR(OS_PL_DPRU(14), Os_AppCfg[ApplID].highAddr[10]);
        case 10:
            OS_PL_MTCR(OS_PL_DPRL(13), Os_AppCfg[ApplID].lowAddr[9]);
            OS_PL_MTCR(OS_PL_DPRU(13), Os_AppCfg[ApplID].highAddr[9]);
        case 9:
            OS_PL_MTCR(OS_PL_DPRL(12), Os_AppCfg[ApplID].lowAddr[8]);
            OS_PL_MTCR(OS_PL_DPRU(12),  Os_AppCfg[ApplID].highAddr[8]);
        case 8: 
            OS_PL_MTCR(OS_PL_DPRL(11), Os_AppCfg[ApplID].lowAddr[7]);  
            OS_PL_MTCR(OS_PL_DPRU(11), Os_AppCfg[ApplID].highAddr[7]);
        case 7:
            OS_PL_MTCR(OS_PL_DPRL(10), Os_AppCfg[ApplID].lowAddr[6]);
            OS_PL_MTCR(OS_PL_DPRU(10), Os_AppCfg[ApplID].highAddr[6]);
        case 6:
            OS_PL_MTCR(OS_PL_DPRL(9), Os_AppCfg[ApplID].lowAddr[5]);
            OS_PL_MTCR(OS_PL_DPRU(9), Os_AppCfg[ApplID].highAddr[5]);
        case 5:
            OS_PL_MTCR(OS_PL_DPRL(8), Os_AppCfg[ApplID].lowAddr[4]);
            OS_PL_MTCR(OS_PL_DPRU(8), Os_AppCfg[ApplID].highAddr[4]);
        case 4:
            OS_PL_MTCR(OS_PL_DPRL(7), Os_AppCfg[ApplID].lowAddr[3]);
            OS_PL_MTCR(OS_PL_DPRU(7),  Os_AppCfg[ApplID].highAddr[3]);
        case 3: 
            OS_PL_MTCR(OS_PL_DPRL(6), Os_AppCfg[ApplID].lowAddr[2]);  
            OS_PL_MTCR(OS_PL_DPRU(6), Os_AppCfg[ApplID].highAddr[2]);
        case 2:
            OS_PL_MTCR(OS_PL_DPRL(5), Os_AppCfg[ApplID].lowAddr[1]);
            OS_PL_MTCR(OS_PL_DPRU(5), Os_AppCfg[ApplID].highAddr[1]);
        case 1:
            OS_PL_MTCR(OS_PL_DPRL(4), Os_AppCfg[ApplID].lowAddr[0]);
            OS_PL_MTCR(OS_PL_DPRU(4), Os_AppCfg[ApplID].highAddr[0]);
            break;
        default:
            break;
    }
    for((tempI = (Os_AppCfg[ApplID].mpuDataNum+3)); tempI>0 ;tempI--)
    {
        DPWE_val += (1 << tempI);
    }
    /* read permission require two more section(DPR16 and DPR17) than write permission, */
    DPRE_val = (DPWE_val | (Os_uint32)0x30000);

#if(OS_MEM_PROTECTION_CODE_APPLICATION_SUPPORT == OS_ON) 

    OS_PL_MTCR(OS_PL_CPRL(1), Os_AppCfg[ApplID].osCodeLowAddr);  
    OS_PL_MTCR(OS_PL_CPRU(1), Os_AppCfg[ApplID].osCodeHighAddr);

    if(Os_AppCfg[ApplID].mpuCodeNum != 0)
    {
        switch (Os_AppCfg[ApplID].mpuCodeNum)
        {
            case 8:
                OS_PL_MTCR(OS_PL_CPRL(9), Os_AppCfg[ApplID].appCodeLowAddr[7]);
                OS_PL_MTCR(OS_PL_CPRU(9), Os_AppCfg[ApplID].appCodeHighAddr[7]);
            case 7:
                OS_PL_MTCR(OS_PL_CPRL(8), Os_AppCfg[ApplID].appCodeLowAddr[6]);
                OS_PL_MTCR(OS_PL_CPRU(8), Os_AppCfg[ApplID].appCodeHighAddr[6]);
            case 6: 
                OS_PL_MTCR(OS_PL_CPRL(7), Os_AppCfg[ApplID].appCodeLowAddr[5]);  
                OS_PL_MTCR(OS_PL_CPRU(7), Os_AppCfg[ApplID].appCodeHighAddr[5]);
            case 5:
                OS_PL_MTCR(OS_PL_CPRL(6), Os_AppCfg[ApplID].appCodeLowAddr[4]);
                OS_PL_MTCR(OS_PL_CPRU(6), Os_AppCfg[ApplID].appCodeHighAddr[4]);
            case 4:
                OS_PL_MTCR(OS_PL_CPRL(5), Os_AppCfg[ApplID].appCodeLowAddr[3]);
                OS_PL_MTCR(OS_PL_CPRU(5), Os_AppCfg[ApplID].appCodeHighAddr[3]);
            case 3: 
                OS_PL_MTCR(OS_PL_CPRL(4), Os_AppCfg[ApplID].appCodeLowAddr[2]);  
                OS_PL_MTCR(OS_PL_CPRU(4), Os_AppCfg[ApplID].appCodeHighAddr[2]);
            case 2:
                OS_PL_MTCR(OS_PL_CPRL(3), Os_AppCfg[ApplID].appCodeLowAddr[1]);
                OS_PL_MTCR(OS_PL_CPRU(3), Os_AppCfg[ApplID].appCodeHighAddr[1]);
            case 1:
                OS_PL_MTCR(OS_PL_CPRL(2), Os_AppCfg[ApplID].appCodeLowAddr[0]);
                OS_PL_MTCR(OS_PL_CPRU(2), Os_AppCfg[ApplID].appCodeHighAddr[0]);
                break;
            default:
                break;
        }

    }
    for((tempI = (Os_AppCfg[ApplID].mpuCodeNum+1)); tempI>0 ;tempI--)
    {
        CPXE_val += (1 << tempI);
    }
#else/* (OS_MEM_PROTECTION_CODE_APPLICATION_SUPPORT == OS_ON)  */
    CPXE_val = (Os_uint32)0x3;    
#endif/* (OS_MEM_PROTECTION_CODE_APPLICATION_SUPPORT == OS_ON)  */

#else/* (OS_APPLICATION_NUMBER > 0) */
    CPXE_val = (Os_uint32)0x1;
    DPRE_val = (Os_uint32)0x1;
    DPWE_val = (Os_uint32)0xE;
#endif/* (OS_APPLICATION_NUMBER > 0) */

    /* set DPR1 for task data */
    OS_PL_MTCR(OS_PL_DPRL(1), Os_ISRCfg[ISRID].lowAddr);
    OS_PL_MTCR(OS_PL_DPRU(1), Os_ISRCfg[ISRID].highAddr);

    /* set DPR2 for peripheral */
    OS_PL_MTCR(OS_PL_DPRL(2), OS_PL_PERI_ADDR_LOW);
    OS_PL_MTCR(OS_PL_DPRU(2), OS_PL_PERI_ADDR_HIGH);

    /*PRQA S 0306 ++*/
    /* set DPR3 for task data's stack */
    OS_PL_MTCR(OS_PL_DPRL(3), (Os_AddrType)Os_ISRCfg[ISRID].OsIsrStkTop);
    OS_PL_MTCR(OS_PL_DPRU(3), (Os_AddrType)Os_ISRCfg[ISRID].OsIsrStkBottom);
    /*PRQA S 0306 --*/

    /* set DPR16 for os kernel variable */
    OS_PL_MTCR(OS_PL_DPRL(16), OS_KERNEL_NOINIT_Start);
    OS_PL_MTCR(OS_PL_DPRU(16), OS_KERNEL_NOINIT_End);

    /* set DPR17 for os config variable */
    OS_PL_MTCR(OS_PL_DPRL(17), OS_CONST_Start);
    OS_PL_MTCR(OS_PL_DPRU(17), OS_CONST_End);
    
    /* set protection set1*/
    OS_PL_MTCR(OS_PL_CPXE(1), CPXE_val);
    OS_PL_MTCR(OS_PL_DPWE(1), DPWE_val);
    OS_PL_MTCR(OS_PL_DPRE(1), DPRE_val); 

    /* Get Saved PCXI*/
    mpupcxi_temp = (OS_PL_MFCR(OS_PL_CPU_PCX_REG));
    /* Get Saved PCXI.PCXO*/
    mpupcxo_temp = (OS_PL_PCX_PCXO_MASK & mpupcxi_temp) << OS_PL_PCX_PCXO_SHIFT;
    /* Get Saved PCXI.PCXS*/
    mpupcxs_temp = (OS_PL_PCX_PCXS_MASK & mpupcxi_temp) << OS_PL_PCX_PCXS_SHIFT;
    /* Get Saved Uper*/
    mpupcxi_temp = mpupcxo_temp | mpupcxs_temp;
    /* Get Saved PSW*/
    /*PRQA S 0306,3383 ++*/
    /* Caculate to get address. */
    psw_temp = (Os_uint32 *) (mpupcxi_temp + OS_PL_UPPER_PSW_SHIFT);
    /*PRQA S 0306,3383 --*/
    /* Change Saved PSW.PSR*/
    *psw_temp = ((*psw_temp) & (~(OS_PL_PSW_PRS_MASK))) | OS_PL_MPU_TASK_ISR_SET;
    /* Return Saved PSW.PSR*/
}

/* BEGIN_FUNCTION_HDR
***********************************************************************************************
* Function Name: OsMpu_ProtectionISR
*
* Description:   set mpu to task right, change the address range and set to set1
*
* Inputs:        CoreID, TaskId
*
*
* Outputs:       None
*
* Limitations:   None
***********************************************************************************************
END_FUNCTION_HDR*/
FUNC(void, OS_CODE) OsMpu_ProtectionISR(void)
{

    CoreIdType CoreID;
    /* Step1, save context */
    /* upper ctx has been saved during trap*/
    /* ctx is only used if user ignore this protection event*/
    OS_PL_SVLCX();/* save lower*/
    OS_PL_ISYNC();

    CoreID = OsCpu_GetCoreID();

    OsHook_ProtectionHook(CoreID, E_OS_PROTECTION_MEMORY);

    /* if user do not ignore, all process will be done in OsHook_ProtectionHook
     * OsHook_ProtectionHook will not return here
     * */

    /* if user ignore, restore the context*/
    OS_PL_RSLCX();
    OS_PL_RFE();

}



#endif/*#if(OS_ON == OS_MEM_PROTECTION_SUPPORT)*/

