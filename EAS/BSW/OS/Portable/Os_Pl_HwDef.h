/*  BEGIN_FILE_HDR
********************************************************************************
*   NOTICE
*   This software is the property of HiRain Technologies. Any information
*   contained in this doc should not be reproduced, or used, or disclosed
*   without the written authorization from HiRain Technologies.
********************************************************************************
* File Name:       Os_Pl_HwDef.h
********************************************************************************
* Project/Product: AUTOSAR EAS
* Title:           Os_Pl_HwDef.h
* Author:          Hirain
********************************************************************************
* Description:     Define the parameters of hardware platform 
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

#ifndef OS_PL_HWDEF_H
#define OS_PL_HWDEF_H

/*****************************************************************************
* General QAC Suppression
******************************************************************************/
/*PRQA S 0750,3621 EOF*/
/*
Union type and bit-field are used to describe hardware memory map.
The way in which bit-fields are allocated in memory is confirmed.
*/

/*PRQA S 3453,3429 EOF*/
/*
Macro functions are allowed to use to access parameters and 
do some simple operations.
*/

/*****************************************************************************
* Compiler and chip name
******************************************************************************/
#define OS_PL_TC39X      (0) 
#define OS_PL_TC37X      (1) 
#define OS_PL_TC35X      (2) 


#define OS_PL_HIGHTEC    (0)
#define OS_PL_TASKING    (1)

/*****************************************************************************
* hw common feather define
******************************************************************************/
#define OS_PL_MASTER_COREID        ((CoreIdType)0)
#define OS_SAVE_CONTEXT_SIZE       ((uint32)32) /* in byte*/
#define OS_PL_LOWEST_ISR_PRI       ((Os_PrioType)0) /* in byte*/

/*core physical handle*/
#define OS_PL_PHY_CORE0       ((CoreIdType)0)
#define OS_PL_PHY_CORE1       ((CoreIdType)1)
#define OS_PL_PHY_CORE2       ((CoreIdType)2)
#define OS_PL_PHY_CORE3       ((CoreIdType)3)
#define OS_PL_PHY_CORE4       ((CoreIdType)4)
#define OS_PL_PHY_CORE5       ((CoreIdType)5)
#define OS_PL_HW_PHY_CORE6    ((CoreIdType)6)
#define OS_PL_STACK_GROW_DIR  OS_PL_STACK_GROW_DOWN

/*****************************************************************************
* Core Register define
******************************************************************************/
#define OS_PL_CPU_SYSCON_REG             (0xFE14)  /* SYSCON register */
#define OS_PL_SYSCON_PEN_MASK            ((Os_uint32)0x00000002)
#define OS_PL_SYSCON_TPEN_MASK           ((Os_uint32)0x00000004)
#define OS_PL_SYSCON_PEN_CLEAR_MASK      ((Os_uint32)0xFFFFFFFD)
#define OS_PL_SYSCON_TPEN_CLEAR_MASK     ((Os_uint32)0xFFFFFFFB)
#define OS_PL_SYSCON_BHALT_CLEAR_MASK    ((Os_uint32)0xFEFFFFFF)

#define OS_PL_CPU_COREID_REG    (0xFE1C)  /* core id register */

#define OS_PL_CPU_ICR_REG       (0xFE2C)  /*  CPUx Interrupt Control Register  */
#define OS_PL_ICR_IE_MASK       ((Os_uint32)0x00008000)
#define OS_PL_ICR_CCPN_MASK     ((Os_uint32)0x000000FF)


#define OS_PL_CPU_PCX_REG       (0xFE00)
#define OS_PL_PCX_PCX_MASK      ((Os_uint32)0x000FFFFF)
#define OS_PL_PCX_UL_MASK       ((Os_uint32)0x00100000)/* note this bit is not right in P1.6 tc1_6__architecture_vol1 */
#define OS_PL_PCX_PIE_MASK      ((Os_uint32)0x00200000)/* note this bit is not right in P1.6 tc1_6__architecture_vol1 */
#define OS_PL_PCX_UL_LOWMASK    ((Os_uint32)0xFFEFFFFF)/* note this bit is not right in P1.6 tc1_6__architecture_vol1 */
#define OS_PL_PCX_PIE_DISMASK   ((Os_uint32)0xFFDFFFFF)/* note this bit is not right in P1.6 tc1_6__architecture_vol1 */

#define OS_PL_PCX_PCXS_MASK     ((Os_uint32)0x000F0000)
#define OS_PL_PCX_PCXO_MASK     ((Os_uint32)0x0000FFFF)
#define OS_PL_PCX_PCXS_SHIFT    ((Os_uint32)12)
#define OS_PL_PCX_PCXO_SHIFT    ((Os_uint32)6)
#define OS_PL_UPPER_PSW_SHIFT   ((Os_uint32)4)

#define OS_PL_PERI_ADDR_LOW     ((Os_uint32)0xF0000000)
#define OS_PL_PERI_ADDR_HIGH    ((Os_uint32)0xFFFFFFFF)

#define OS_PL_CPU_FCX_REG           (0xFE38)
#define OS_PL_CPU_PSW_REG           (0xFE04)
#define OS_PL_CPU_PSW_INIT_VAL      ((Os_uint32)0x00000B80)/* note this bit is not right in P1.6 tc1_6__architecture_vol1 */
#define OS_PL_PSW_ISUSERMASK        ((Os_uint32)0x00000200)/* note this bit is not right in P1.6 tc1_6__architecture_vol1 */
#define OS_PL_PSW_CDC_CLEAR_MASK    ((Os_uint32)0xFFFFFF80)/* note this bit is not right in P1.6 tc1_6__architecture_vol1 */
#define OS_PL_PSW_CDC_MASK          ((Os_uint32)0x0000007F)/* note this bit is not right in P1.6 tc1_6__architecture_vol1 */
#define OS_PL_PSW_IO_MASK           ((Os_uint32)0x00000C00)    
#define OS_PL_PSW_IO_SHIFT          ((Os_uint32)10) 

#define OS_PL_PSW_PRS_CLEARMASK    ((Os_uint32)0xFFFF4FFF)/* note this bit is not right in P1.6 tc1_6__architecture_vol1 */
#define OS_PL_PSW_PRS_MASK         ((Os_uint32)0x0000B000)/* note this bit is not right in P1.6 tc1_6__architecture_vol1 */
#define OS_PL_PSW_PRS_SHIFT        ((Os_uint32)12) 

/*Mpu*/
#define OS_PL_DPRL(x)     (0xC000 + (x)*8)
#define OS_PL_DPRU(x)     (0xC004 + (x)*8)
#define OS_PL_CPRL(x)     (0xD000 + (x)*8)
#define OS_PL_CPRU(x)     (0xD004 + (x)*8)
#define OS_PL_DPRE(x)     (0xE010 + (x)*4)
#define OS_PL_DPWE(x)     (0xE020 + (x)*4)
#define OS_PL_CPXE(x)     (0xE000 + (x)*4)


/*timing prot*/
#define OS_PL_TPS_CON_REG             (0xE400)
#define OS_PL_TPS_CON_TIMER0_MASK     ((Os_uint32)0x00000001)
#define OS_PL_TPS_CON_TIMER1_MASK     ((Os_uint32)0x00000002)
#define OS_PL_TPS_CON_TIMER2_MASK     ((Os_uint32)0x00000004)

#define OS_TPTIMER_CHANNEL      (0)
#define OS_TPFCTIMER_CHANNEL    (1)



#define OS_PL_TPS_TIMER(x)     (0xE404 + (x)*4)
#define OS_TWO_NBITS 2
#define OS_THREE_NBITS 3
#define OS_FIVE_NBITS 5
#define OS_EIGHT_NBITS 8
/*****************************************************************************
* Peripheral Register define
******************************************************************************/

/*PRQA S 0602 ++*/
/* This identifier will not be used by system library. */
typedef struct _Os_SRC_SRCR_Bits
/*PRQA S 0602 --*/
{
    Os_uint32 SRPN:OS_EIGHT_NBITS;            /**< \brief [7:0] Service Request Priority Number (rw) */
    Os_uint32 reserved_8:OS_TWO_NBITS;      /**< \brief [9:8] \internal Reserved */
    Os_uint32 SRE:1;             /**< \brief [10:10] Service Request Enable (rw) */
    Os_uint32 TOS:OS_THREE_NBITS;             /**< \brief [13:11] Type of Service Control (rw) */
    Os_uint32 reserved_14:OS_TWO_NBITS;     /**< \brief [15:14] \internal Reserved */
    /*PRQA S 4641 ++*/
    /* Do not included <errno.h> */
    Os_uint32 ECC:OS_FIVE_NBITS;             /**< \brief [20:16] Error Correction Code (rwh) */
    /*PRQA S 4641 --*/
    Os_uint32 reserved_21:OS_THREE_NBITS;     /**< \brief [23:21] \internal Reserved */
    Os_uint32 SRR:1;             /**< \brief [24:24] Service Request Flag (rh) */
    Os_uint32 CLRR:1;            /**< \brief [25:25] Request Clear Bit (w) */
    Os_uint32 SETR:1;            /**< \brief [26:26] Request Set Bit (w) */
    Os_uint32 IOV:1;             /**< \brief [27:27] Interrupt Trigger Overflow Bit (rh) */
    Os_uint32 IOVCLR:1;          /**< \brief [28:28] Interrupt Trigger Overflow Clear Bit (w) */
    Os_uint32 SWS:1;             /**< \brief [29:29] SW Sticky Bit (rh) */
    Os_uint32 SWSCLR:1;          /**< \brief [30:30] SW Sticky Clear Bit (w) */
    Os_uint32 reserved_31:1;     /**< \brief [31:31] \internal Reserved */
} Os_SRC_SRCR_Bits;

typedef union
{
    Os_uint32 U;                 /**< \brief Unsigned access */
    Os_uint32 I;                 /**< \brief Signed access */
    Os_SRC_SRCR_Bits B;              /**< \brief Bitfield access */
} OS_SRC_SRCR;

/*x:0-5*/
#define OS_PL_STM_TIM0(x)       (*((volatile Os_uint32*)(0xF0001000 + ((Os_uint32)(x)*(Os_uint32)0x100) + (Os_uint32)0x10)))
#define OS_PL_STM_CLC(x)        (*((volatile Os_uint32*)(0xF0001000 + ((Os_uint32)(x)*(Os_uint32)0x100) + (Os_uint32)0)))
#define OS_PL_STM_CMP0(x)       (*((volatile Os_uint32*)(0xF0001000 + ((Os_uint32)(x)*(Os_uint32)0x100) + (Os_uint32)0x30)))
#define OS_PL_STM_CMP1(x)       (*((volatile Os_uint32*)(0xF0001000 + ((Os_uint32)(x)*(Os_uint32)0x100) + (Os_uint32)0x34)))
#define OS_PL_STM_CMCON(x)      (*((volatile Os_uint32*)(0xF0001000 + ((Os_uint32)(x)*(Os_uint32)0x100) + (Os_uint32)0x38)))
#define OS_PL_STM_ICR(x)        (*((volatile Os_uint32*)(0xF0001000 + ((Os_uint32)(x)*(Os_uint32)0x100) + (Os_uint32)0x3c)))
#define OS_PL_STM_ISCR(x)       (*((volatile Os_uint32*)(0xF0001000 + ((Os_uint32)(x)*(Os_uint32)0x100) + (Os_uint32)0x40)))



#define OS_PL_STM_CMCOM_CM0EN_MASK        ((Os_uint32)0x00000001)
#define OS_PL_STM_ISCR_CMP0IRR_MASK       ((Os_uint32)0x00000001)


/*System Timer x(0-5) Service Request y, y can only be 0/1*/
#define OS_PL_STM_SR(x, y)              (*((volatile Os_uint32*)(0xF0038300 + ((Os_uint32)8*(Os_uint32)(x)) + ((Os_uint32)4*(Os_uint32)(y)))))


#define OS_PL_STM_SR_SRE_CLEAR_MASK     (0xFFFFFBFF)
#define OS_PL_STM_SR_CLRR_MASK          ((Os_uint32)0x02000000)
#define OS_PL_STM_SR_SRE_MASK           ((Os_uint32)0x00000400)

/* Cross Core int */
#define OS_PL_SRC_GPSR0(x)              (*(volatile OS_SRC_SRCR*)(0xF0038990 + ((Os_uint32)4*(Os_uint32)(x))))

/*Disable/Enable ISR*/
#define OS_PL_SRC(x)                    (*(volatile OS_SRC_SRCR*)(0xF0038000 + ((Os_uint32)4*(Os_uint32)(x))))

/*x(0-5)*/
#define OS_PL_WDTCPU_CON0(x)            (*((volatile Os_uint32*)(0xF003624C + ((Os_uint32)12*(Os_uint32)(x)))))

#define OS_PL_WDTCPU_PW_MASK            ((Os_uint32)0x0000FFFC)
#define OS_PL_WDTCPU_PW_SHIFT_VAL       ((Os_uint32)2)

#define OS_PL_WDT_PASSWORD_INVERT_MSK   ((Os_uint16)0x003F)
#define OS_PL_WDTCPU_LCK_MASK           ((Os_uint32)0x00000002)
#define OS_PL_WDTCPU_REL_MASK           (0xFFFF0000)
#define OS_PL_WDTCPU_ENDINIT_MASK       ((Os_uint32)0x00000001)


#define OS_PL_PMCSR(x)                  (*(volatile Os_uint32*)(0xF00360C8 + ((Os_uint32)4*(Os_uint32)(x))))
#define OS_PL_PMCSR_IDLE_MASK           ((Os_uint32)0x00000001)



/*Cpu related*/
/*
* Set by MCAL
* #define OS_PL_SYSCON(x)            (*(volatile Os_uint32*)(OsCpu_BaseAddr[(x)] + (Os_uint32)0x1FE14))
* #define OS_PL_PC(x)                (*(volatile Os_uint32*)(OsCpu_BaseAddr[(x)] + (Os_uint32)0x1FE08))
*/


#endif /* OS_PL_HWDEF_H */
