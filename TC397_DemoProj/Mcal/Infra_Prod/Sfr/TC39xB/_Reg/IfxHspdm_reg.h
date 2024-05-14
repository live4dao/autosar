/**
 * \file IfxHspdm_reg.h
 * \brief
 * \copyright Copyright (c) 2021 Infineon Technologies AG. All rights reserved.
 *
 *
 * Version: TC39XB_UM_V2.0.0.R0
 * Specification: TC3xx User Manual V2.0.0
 * MAY BE CHANGED BY USER [yes/no]: No
 *
 *                                 IMPORTANT NOTICE
 *
 *
 * Use of this file is subject to the terms of use agreed between (i) you or 
 * the company in which ordinary course of business you are acting and (ii) 
 * Infineon Technologies AG or its licensees. If and as long as no such 
 * terms of use are agreed, use of this file is subject to following:


 * Boost Software License - Version 1.0 - August 17th, 2003

 * Permission is hereby granted, free of charge, to any person or 
 * organization obtaining a copy of the software and accompanying 
 * documentation covered by this license (the "Software") to use, reproduce,
 * display, distribute, execute, and transmit the Software, and to prepare
 * derivative works of the Software, and to permit third-parties to whom the 
 * Software is furnished to do so, all subject to the following:

 * The copyright notices in the Software and this entire statement, including
 * the above license grant, this restriction and the following disclaimer, must
 * be included in all copies of the Software, in whole or in part, and all
 * derivative works of the Software, unless such copies or derivative works are
 * solely in the form of machine-executable object code generated by a source
 * language processor.

 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR 
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO EVENT
 * SHALL THE COPYRIGHT HOLDERS OR ANYONE DISTRIBUTING THE SOFTWARE BE LIABLE 
 * FOR ANY DAMAGES OR OTHER LIABILITY, WHETHER IN CONTRACT, TORT OR OTHERWISE,
 * ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 *
 * \defgroup IfxSfr_Hspdm_Registers_Cfg Hspdm address
 * \ingroup IfxSfr_Hspdm_Registers
 * 
 * \defgroup IfxSfr_Hspdm_Registers_Cfg_BaseAddress Base address
 * \ingroup IfxSfr_Hspdm_Registers_Cfg
 *
 * \defgroup IfxSfr_Hspdm_Registers_Cfg_Hspdm 2-HSPDM
 * \ingroup IfxSfr_Hspdm_Registers_Cfg
 *
 *
 */
#ifndef IFXHSPDM_REG_H
#define IFXHSPDM_REG_H 1
/******************************************************************************/
#include "IfxHspdm_regdef.h"
/******************************************************************************/

/******************************************************************************/

/******************************************************************************/

/** \addtogroup IfxSfr_Hspdm_Registers_Cfg_BaseAddress
 * \{  */

/** \brief HSPDM object */
#define MODULE_HSPDM /*lint --e(923, 9078)*/ ((*(Ifx_HSPDM*)0xF0280000u))
/** \}  */


/******************************************************************************/
/******************************************************************************/
/** \addtogroup IfxSfr_Hspdm_Registers_Cfg_Hspdm
 * \{  */
/** \brief 0, SRAM  */
#define HSPDM_SRAM ((void*)0xF0280000u)
#define HSPDM_SRAM_SIZE (0x2000u)
/** \brief 0, Clock Control Register */
#define HSPDM_CLC /*lint --e(923, 9078)*/ (*(volatile Ifx_HSPDM_CLC*)0xF0282000u)

/** \brief 8, Module Identification Register */
#define HSPDM_ID /*lint --e(923, 9078)*/ (*(volatile Ifx_HSPDM_ID*)0xF0282008u)

/** \brief 10, RAM Buffer A Register 0 */
#define HSPDM_BUFA0 /*lint --e(923, 9078)*/ (*(volatile Ifx_HSPDM_BUFA0*)0xF0282010u)

/** \brief 18, RAM Buffer B Register 0 */
#define HSPDM_BUFB0 /*lint --e(923, 9078)*/ (*(volatile Ifx_HSPDM_BUFB0*)0xF0282018u)

/** \brief 1C, Current Address Register */
#define HSPDM_CURRAD /*lint --e(923, 9078)*/ (*(volatile Ifx_HSPDM_CURRAD*)0xF028201Cu)

/** \brief 20, MUTE0 Register */
#define HSPDM_MUTE0 /*lint --e(923, 9078)*/ (*(volatile Ifx_HSPDM_MUTE0*)0xF0282020u)

/** \brief 24, MUTE1 Register */
#define HSPDM_MUTE1 /*lint --e(923, 9078)*/ (*(volatile Ifx_HSPDM_MUTE1*)0xF0282024u)

/** \brief 30, ADC Trigger Register */
#define HSPDM_ADCTG /*lint --e(923, 9078)*/ (*(volatile Ifx_HSPDM_ADCTG*)0xF0282030u)

/** \brief 34, ADC Trigger Count Register */
#define HSPDM_ADCTGCNT /*lint --e(923, 9078)*/ (*(volatile Ifx_HSPDM_ADCTGCNT*)0xF0282034u)

/** \brief 38, Configuration Register */
#define HSPDM_CON /*lint --e(923, 9078)*/ (*(volatile Ifx_HSPDM_CON*)0xF0282038u)

/** \brief 44, Flags Register */
#define HSPDM_FLAGS /*lint --e(923, 9078)*/ (*(volatile Ifx_HSPDM_FLAGS*)0xF0282044u)

/** \brief 48, Flags Set Register */
#define HSPDM_FLAGSSET /*lint --e(923, 9078)*/ (*(volatile Ifx_HSPDM_FLAGSSET*)0xF0282048u)

/** \brief 4C, Flags Clear Register */
#define HSPDM_FLAGSCLEAR /*lint --e(923, 9078)*/ (*(volatile Ifx_HSPDM_FLAGSCLEAR*)0xF028204Cu)

/** \brief 50, Flags Enable Register */
#define HSPDM_FLAGSEN /*lint --e(923, 9078)*/ (*(volatile Ifx_HSPDM_FLAGSEN*)0xF0282050u)

/** \brief E8, OCDS Control and Status Register */
#define HSPDM_OCS /*lint --e(923, 9078)*/ (*(volatile Ifx_HSPDM_OCS*)0xF02820E8u)

/** \brief EC, Kernel Reset Status Clear Register */
#define HSPDM_KRSTCLR /*lint --e(923, 9078)*/ (*(volatile Ifx_HSPDM_KRSTCLR*)0xF02820ECu)

/** \brief F0, Kernel Reset Register 1 */
#define HSPDM_KRST1 /*lint --e(923, 9078)*/ (*(volatile Ifx_HSPDM_KRST1*)0xF02820F0u)

/** \brief F4, Kernel Reset Register 0 */
#define HSPDM_KRST0 /*lint --e(923, 9078)*/ (*(volatile Ifx_HSPDM_KRST0*)0xF02820F4u)

/** \brief F8, Access Enable Register 1 */
#define HSPDM_ACCEN1 /*lint --e(923, 9078)*/ (*(volatile Ifx_HSPDM_ACCEN1*)0xF02820F8u)

/** \brief FC, Access Enable Register 0 */
#define HSPDM_ACCEN0 /*lint --e(923, 9078)*/ (*(volatile Ifx_HSPDM_ACCEN0*)0xF02820FCu)


/** \}  */

/******************************************************************************/

/******************************************************************************/

#endif /* IFXHSPDM_REG_H */
