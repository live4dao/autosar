/**
 * \file IfxSrc_bf.h
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
 * \defgroup IfxSfr_Src_Registers_BitfieldsMask Bitfields mask and offset
 * \ingroup IfxSfr_Src_Registers
 * 
 */
#ifndef IFXSRC_BF_H
#define IFXSRC_BF_H 1

/******************************************************************************/

/******************************************************************************/

/** \addtogroup IfxSfr_Src_Registers_BitfieldsMask
 * \{  */
/** \brief Length for Ifx_SRC_SRCR_Bits.SRPN */
#define IFX_SRC_SRCR_SRPN_LEN (8u)

/** \brief Mask for Ifx_SRC_SRCR_Bits.SRPN */
#define IFX_SRC_SRCR_SRPN_MSK (0xffu)

/** \brief Offset for Ifx_SRC_SRCR_Bits.SRPN */
#define IFX_SRC_SRCR_SRPN_OFF (0u)

/** \brief Length for Ifx_SRC_SRCR_Bits.SRE */
#define IFX_SRC_SRCR_SRE_LEN (1u)

/** \brief Mask for Ifx_SRC_SRCR_Bits.SRE */
#define IFX_SRC_SRCR_SRE_MSK (0x1u)

/** \brief Offset for Ifx_SRC_SRCR_Bits.SRE */
#define IFX_SRC_SRCR_SRE_OFF (10u)

/** \brief Length for Ifx_SRC_SRCR_Bits.TOS */
#define IFX_SRC_SRCR_TOS_LEN (3u)

/** \brief Mask for Ifx_SRC_SRCR_Bits.TOS */
#define IFX_SRC_SRCR_TOS_MSK (0x7u)

/** \brief Offset for Ifx_SRC_SRCR_Bits.TOS */
#define IFX_SRC_SRCR_TOS_OFF (11u)

/** \brief Length for Ifx_SRC_SRCR_Bits.ECC */
#define IFX_SRC_SRCR_ECC_LEN (5u)

/** \brief Mask for Ifx_SRC_SRCR_Bits.ECC */
#define IFX_SRC_SRCR_ECC_MSK (0x1fu)

/** \brief Offset for Ifx_SRC_SRCR_Bits.ECC */
#define IFX_SRC_SRCR_ECC_OFF (16u)

/** \brief Length for Ifx_SRC_SRCR_Bits.SRR */
#define IFX_SRC_SRCR_SRR_LEN (1u)

/** \brief Mask for Ifx_SRC_SRCR_Bits.SRR */
#define IFX_SRC_SRCR_SRR_MSK (0x1u)

/** \brief Offset for Ifx_SRC_SRCR_Bits.SRR */
#define IFX_SRC_SRCR_SRR_OFF (24u)

/** \brief Length for Ifx_SRC_SRCR_Bits.CLRR */
#define IFX_SRC_SRCR_CLRR_LEN (1u)

/** \brief Mask for Ifx_SRC_SRCR_Bits.CLRR */
#define IFX_SRC_SRCR_CLRR_MSK (0x1u)

/** \brief Offset for Ifx_SRC_SRCR_Bits.CLRR */
#define IFX_SRC_SRCR_CLRR_OFF (25u)

/** \brief Length for Ifx_SRC_SRCR_Bits.SETR */
#define IFX_SRC_SRCR_SETR_LEN (1u)

/** \brief Mask for Ifx_SRC_SRCR_Bits.SETR */
#define IFX_SRC_SRCR_SETR_MSK (0x1u)

/** \brief Offset for Ifx_SRC_SRCR_Bits.SETR */
#define IFX_SRC_SRCR_SETR_OFF (26u)

/** \brief Length for Ifx_SRC_SRCR_Bits.IOV */
#define IFX_SRC_SRCR_IOV_LEN (1u)

/** \brief Mask for Ifx_SRC_SRCR_Bits.IOV */
#define IFX_SRC_SRCR_IOV_MSK (0x1u)

/** \brief Offset for Ifx_SRC_SRCR_Bits.IOV */
#define IFX_SRC_SRCR_IOV_OFF (27u)

/** \brief Length for Ifx_SRC_SRCR_Bits.IOVCLR */
#define IFX_SRC_SRCR_IOVCLR_LEN (1u)

/** \brief Mask for Ifx_SRC_SRCR_Bits.IOVCLR */
#define IFX_SRC_SRCR_IOVCLR_MSK (0x1u)

/** \brief Offset for Ifx_SRC_SRCR_Bits.IOVCLR */
#define IFX_SRC_SRCR_IOVCLR_OFF (28u)

/** \brief Length for Ifx_SRC_SRCR_Bits.SWS */
#define IFX_SRC_SRCR_SWS_LEN (1u)

/** \brief Mask for Ifx_SRC_SRCR_Bits.SWS */
#define IFX_SRC_SRCR_SWS_MSK (0x1u)

/** \brief Offset for Ifx_SRC_SRCR_Bits.SWS */
#define IFX_SRC_SRCR_SWS_OFF (29u)

/** \brief Length for Ifx_SRC_SRCR_Bits.SWSCLR */
#define IFX_SRC_SRCR_SWSCLR_LEN (1u)

/** \brief Mask for Ifx_SRC_SRCR_Bits.SWSCLR */
#define IFX_SRC_SRCR_SWSCLR_MSK (0x1u)

/** \brief Offset for Ifx_SRC_SRCR_Bits.SWSCLR */
#define IFX_SRC_SRCR_SWSCLR_OFF (30u)

/** \}  */

/******************************************************************************/

/******************************************************************************/

#endif /* IFXSRC_BF_H */
