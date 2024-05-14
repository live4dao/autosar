/*  BEGIN_FILE_HDR
********************************************************************************
*   NOTICE
*   This software is the property of HiRain Technologies. Any information
*   contained in this doc should not be reproduced, or used, or disclosed
*   without the written authorization from HiRain Technologies.
********************************************************************************
* File Name:       Os_Pl_Instruction.h
********************************************************************************
* Project/Product: AUTOSAR EAS
* Title:           Os_Pl_Instruction.h
* Author:          Hirain
********************************************************************************
* Description:     Instructions of os, may be different for different hw or compiler 
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

#ifndef OS_PL_INSTRUCTION_H
#define OS_PL_INSTRUCTION_H

/*****************************************************************************
* General QAC Suppression
******************************************************************************/
/*PRQA S 3453,3429 EOF*/
/*
Macro functions are allowed to use to access parameters and do some simple 
operations include assembly instructions.
*/

/*PRQA S 0602,0603 EOF*/
/*
This identifier will not be used by system library.
*/

#define __OS_STRINGIFY(x)    #x

#define __OS_MFCR	__mfcr

#define __OS_MTCR	__mtcr

#define OS_PL_MFCR(reg)         __OS_MFCR(reg)

#define OS_PL_MTCR(reg, val)    __OS_MTCR(reg, val)

#if defined(OS_QAC)
#define OS_PL_EnableInterrupts()    ((Os_uint32)1)
#define OS_PL_DisableInterrupts()   ((Os_uint32)1)
#define OS_PL_SET_REG(reg,val)      ((Os_uint32)(val))
#define OS_PL_RFE()                 ((Os_uint32)1)
#define OS_PL_RET()                 ((Os_uint32)1)
#define OS_PL_NOP()                 ((Os_uint32)1)
#define OS_PL_ISYNC()               ((Os_uint32)1)
#define OS_PL_DSYNC()               ((Os_uint32)1)
#define OS_PL_SVLCX()               ((Os_uint32)1)
#define OS_PL_RSLCX()               ((Os_uint32)1)
#define OS_PL_JUMP(fun)             ((Os_uint32)1)
#define OS_PL_CALL(fun)             ((Os_uint32)1)
#else
#define OS_PL_EnableInterrupts()     (__enable())
#define OS_PL_DisableInterrupts()    (__disable())


#define OS_PL_SET_REG(reg,val)  __set_sp(val)

#define OS_PL_RFE()          __asm("rfe")
#define OS_PL_RET()          __asm("ret")

#define OS_PL_NOP()     (__nop())

#define OS_PL_ISYNC()     (__isync())
#define OS_PL_DSYNC()     (__dsync())

#define OS_PL_SVLCX()       __asm("svlcx" ::: "memory")

#define OS_PL_RSLCX()     __asm("rslcx" ::: "memory", \
                                            "d0", "d1", "d2", "d3", "d4", "d5", "d6", "d7",\
                                            "a2", "a3", "a4", "a5", "a6", "a7", "a11")

#define OS_PL_JUMP(fun)  __asm("ji\t%0\n"::"a" (fun))


#define OS_PL_CALL(fun)   __asm__ volatile ("call " #fun)
#endif /* OS_QAC */

#define OS_SYSCALL_TIN          (255)
#define OS_SYSCALL_KERNEL_TIN   (254)
#define OS_SYSCALL_USER0_TIN    (253)

#define OS_MEMPROT_READ_TIN     (2)
#define OS_MEMPROT_WRITE_TIN    (3)
#define OS_MEMPROT_EXEC_TIN     (4)
#define OS_MEMPROT_PERP_TIN     (5)
#define OS_TIMEPROT_TIN         (7)

#if defined(OS_QAC)
#define OS_PL_SYSCALL(tin)      ((void)(tin))
#define OS_PL_GETTIN(tin)       ((Os_uint32)(tin))
/*PRQA S 3458 ++*/
/* Useless macro just for QAC to instead assembly instructions. */
#define imaskandldmst(address, insertvalue, position, width) \
    { \
        (void)(address); \
        (void)(insertvalue); \
        (void)(position); \
        (void)(width); \
    }
/*PRQA S 3458 --*/
#else
#define OS_PL_SYSCALL(tin)      __syscall(tin)

#define OS_PL_GETTIN(tin) \
{ \
  __asm("mov %0,d15" : "=d"(tin)); \
}

#define imaskandldmst(address,val,offset,bits) \
 __asm("imask e2,%0,%1,#" #bits  "\n ldmst [%2]0,e2" \
        : : "d" (val), "d" (offset), "a" (address) : "e2")
#endif /* OS_QAC */


#define OsCpu_ReleaseSpinlock(address)    imaskandldmst(address, OS_INVALID_COREID, 0, 8)

#if defined(OS_QAC)
/*PRQA S 0788,0286 ++*/
/* Those errors and wanings are caused by assembly instructions in PRQA. */
/* Useless macro just for QAC to instead assembly instructions. */
#define OS_PL_ISR_REGIST(ISR, vectabNum, prio)  void ISR(void)
#else
#define OS_PL_ISR_REGIST(isr, vectabNum, prio) \
                    void __interrupt(prio) __vector_table(vectabNum) isr(void)
/*PRQA S 0788,0286 --*/
#endif /* OS_QAC */

#endif /* OS_INSTRUCTION_H */
