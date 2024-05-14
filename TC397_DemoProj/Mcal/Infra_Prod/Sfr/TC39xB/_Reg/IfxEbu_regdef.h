/**
 * \file IfxEbu_regdef.h
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
 * \defgroup IfxSfr_Ebu_Registers Ebu Registers
 * \ingroup IfxSfr
 * 
 * \defgroup IfxSfr_Ebu_Registers_Bitfields Bitfields
 * \ingroup IfxSfr_Ebu_Registers
 * 
 * \defgroup IfxSfr_Ebu_Registers_union Register unions
 * \ingroup IfxSfr_Ebu_Registers
 * 
 * \defgroup IfxSfr_Ebu_Registers_struct Memory map
 * \ingroup IfxSfr_Ebu_Registers
 */
#ifndef IFXEBU_REGDEF_H
#define IFXEBU_REGDEF_H 1
/******************************************************************************/
#include "Ifx_TypesReg.h"
/******************************************************************************/

/******************************************************************************/

/******************************************************************************/


/** \addtogroup IfxSfr_Ebu_Registers_Bitfields
 * \{  */
/** \brief EBU Access Enable Register 0 */
typedef struct _Ifx_EBU_ACCEN0_Bits
{
    Ifx_Strict_32Bit EN0:1;           /**< \brief [0:0] Access Enable for Master TAG ID 0 - ENn (rw) */
    Ifx_Strict_32Bit EN1:1;           /**< \brief [1:1] Access Enable for Master TAG ID 1 - ENn (rw) */
    Ifx_Strict_32Bit EN2:1;           /**< \brief [2:2] Access Enable for Master TAG ID 2 - ENn (rw) */
    Ifx_Strict_32Bit EN3:1;           /**< \brief [3:3] Access Enable for Master TAG ID 3 - ENn (rw) */
    Ifx_Strict_32Bit EN4:1;           /**< \brief [4:4] Access Enable for Master TAG ID 4 - ENn (rw) */
    Ifx_Strict_32Bit EN5:1;           /**< \brief [5:5] Access Enable for Master TAG ID 5 - ENn (rw) */
    Ifx_Strict_32Bit EN6:1;           /**< \brief [6:6] Access Enable for Master TAG ID 6 - ENn (rw) */
    Ifx_Strict_32Bit EN7:1;           /**< \brief [7:7] Access Enable for Master TAG ID 7 - ENn (rw) */
    Ifx_Strict_32Bit EN8:1;           /**< \brief [8:8] Access Enable for Master TAG ID 8 - ENn (rw) */
    Ifx_Strict_32Bit EN9:1;           /**< \brief [9:9] Access Enable for Master TAG ID 9 - ENn (rw) */
    Ifx_Strict_32Bit EN10:1;          /**< \brief [10:10] Access Enable for Master TAG ID 10 - ENn (rw) */
    Ifx_Strict_32Bit EN11:1;          /**< \brief [11:11] Access Enable for Master TAG ID 11 - ENn (rw) */
    Ifx_Strict_32Bit EN12:1;          /**< \brief [12:12] Access Enable for Master TAG ID 12 - ENn (rw) */
    Ifx_Strict_32Bit EN13:1;          /**< \brief [13:13] Access Enable for Master TAG ID 13 - ENn (rw) */
    Ifx_Strict_32Bit EN14:1;          /**< \brief [14:14] Access Enable for Master TAG ID 14 - ENn (rw) */
    Ifx_Strict_32Bit EN15:1;          /**< \brief [15:15] Access Enable for Master TAG ID 15 - ENn (rw) */
    Ifx_Strict_32Bit EN16:1;          /**< \brief [16:16] Access Enable for Master TAG ID 16 - ENn (rw) */
    Ifx_Strict_32Bit EN17:1;          /**< \brief [17:17] Access Enable for Master TAG ID 17 - ENn (rw) */
    Ifx_Strict_32Bit EN18:1;          /**< \brief [18:18] Access Enable for Master TAG ID 18 - ENn (rw) */
    Ifx_Strict_32Bit EN19:1;          /**< \brief [19:19] Access Enable for Master TAG ID 19 - ENn (rw) */
    Ifx_Strict_32Bit EN20:1;          /**< \brief [20:20] Access Enable for Master TAG ID 20 - ENn (rw) */
    Ifx_Strict_32Bit EN21:1;          /**< \brief [21:21] Access Enable for Master TAG ID 21 - ENn (rw) */
    Ifx_Strict_32Bit EN22:1;          /**< \brief [22:22] Access Enable for Master TAG ID 22 - ENn (rw) */
    Ifx_Strict_32Bit EN23:1;          /**< \brief [23:23] Access Enable for Master TAG ID 23 - ENn (rw) */
    Ifx_Strict_32Bit EN24:1;          /**< \brief [24:24] Access Enable for Master TAG ID 24 - ENn (rw) */
    Ifx_Strict_32Bit EN25:1;          /**< \brief [25:25] Access Enable for Master TAG ID 25 - ENn (rw) */
    Ifx_Strict_32Bit EN26:1;          /**< \brief [26:26] Access Enable for Master TAG ID 26 - ENn (rw) */
    Ifx_Strict_32Bit EN27:1;          /**< \brief [27:27] Access Enable for Master TAG ID 27 - ENn (rw) */
    Ifx_Strict_32Bit EN28:1;          /**< \brief [28:28] Access Enable for Master TAG ID 28 - ENn (rw) */
    Ifx_Strict_32Bit EN29:1;          /**< \brief [29:29] Access Enable for Master TAG ID 29 - ENn (rw) */
    Ifx_Strict_32Bit EN30:1;          /**< \brief [30:30] Access Enable for Master TAG ID 30 - ENn (rw) */
    Ifx_Strict_32Bit EN31:1;          /**< \brief [31:31] Access Enable for Master TAG ID 31 - ENn (rw) */
} Ifx_EBU_ACCEN0_Bits;

/** \brief EBU Access Enable Register 1 */
typedef struct _Ifx_EBU_ACCEN1_Bits
{
    Ifx_Strict_32Bit reserved_0:32;    /**< \brief [31:0] \internal Reserved */
} Ifx_EBU_ACCEN1_Bits;

/** \brief EBU Address Select Register ${x} */
typedef struct _Ifx_EBU_ADDRSEL_Bits
{
    Ifx_Strict_32Bit REGENAB:1;       /**< \brief [0:0] Memory Region Enable - REGENAB (rw) */
    Ifx_Strict_32Bit ALTENAB:1;       /**< \brief [1:1] Alternate Segment Comparison Enable - ALTENAB (rw) */
    Ifx_Strict_32Bit WPROT:1;         /**< \brief [2:2] Memory Region Write Protect - WPROT (rw) */
    Ifx_Strict_32Bit GLOBALCS:1;      /**< \brief [3:3] Combined Chip Select Control - GLOBALCS (rw) */
    Ifx_Strict_32Bit MASK:4;          /**< \brief [7:4] Memory Region Address Mask - MASK (rw) */
    Ifx_Strict_32Bit ALTSEG:4;        /**< \brief [11:8] Memory Region Alternate Segment - ALTSEG (rw) */
    Ifx_Strict_32Bit BASE:20;         /**< \brief [31:12] Memory Region Base Address - BASE (rw) */
} Ifx_EBU_ADDRSEL_Bits;

/** \brief EBU Bus Read Access Parameter Register */
typedef struct _Ifx_EBU_BUS_RAP_Bits
{
    Ifx_Strict_32Bit RDDTACS:4;       /**< \brief [3:0] Recovery Cycles between Different Regions - RDDTACS (rw) */
    Ifx_Strict_32Bit RDRECOVC:3;      /**< \brief [6:4] Recovery Cycles after Read Accesses - RDRECOVC (rw) */
    Ifx_Strict_32Bit WAITRDC:5;       /**< \brief [11:7] Programmed Wait States for read accesses - WAITRDC (rw) */
    Ifx_Strict_32Bit DATAC:4;         /**< \brief [15:12] Data Hold Cycles for Read Accesses - DATAC (rw) */
    Ifx_Strict_32Bit EXTCLOCK:2;      /**< \brief [17:16] Frequency of external clock at pin BFCLKO or SDCLKO - EXTCLOCK (rw) */
    Ifx_Strict_32Bit EXTDATA:2;       /**< \brief [19:18] Extended data - EXTDATA (rw) */
    Ifx_Strict_32Bit CMDDELAY:4;      /**< \brief [23:20] Command Delay Cycles - CMDDELAY (rw) */
    Ifx_Strict_32Bit AHOLDC:4;        /**< \brief [27:24] Address Hold Cycles - AHOLDC (rw) */
    Ifx_Strict_32Bit ADDRC:4;         /**< \brief [31:28] Address Cycles - ADDRC (rw) */
} Ifx_EBU_BUS_RAP_Bits;

/** \brief EBU Bus Configuration Register */
typedef struct _Ifx_EBU_BUS_RCON_Bits
{
    Ifx_Strict_32Bit FETBLEN:3;       /**< \brief [2:0] Burst Length for Synchronous Burst - FETBLEN (rw) */
    Ifx_Strict_32Bit FBBMSEL:1;       /**< \brief [3:3] Synchronous burst buffer mode select - FBBMSEL (rw) */
    Ifx_Strict_32Bit reserved_4:1;    /**< \brief [4:4] \internal Reserved */
    Ifx_Strict_32Bit FDBKEN:1;        /**< \brief [5:5] Burst FLASH Clock Feedback Enable - FDBKEN (rw) */
    Ifx_Strict_32Bit BFCMSEL:1;       /**< \brief [6:6] Burst Flash Clock Mode Select - BFCMSEL (rw) */
    Ifx_Strict_32Bit NAA:1;           /**< \brief [7:7] Enable flash non-array access workaround - NAA (rw) */
    Ifx_Strict_32Bit reserved_8:8;    /**< \brief [15:8] \internal Reserved */
    Ifx_Strict_32Bit ECSE:1;          /**< \brief [16:16] Early Chip Select for Synchronous Burst - ECSE (rw) */
    Ifx_Strict_32Bit EBSE:1;          /**< \brief [17:17] Early Burst Signal Enable for Synchronous Burst - EBSE (rw) */
    Ifx_Strict_32Bit DBA:1;           /**< \brief [18:18] Disable Burst Address Wrapping - DBA (rw) */
    Ifx_Strict_32Bit WAITINV:1;       /**< \brief [19:19] Reversed polarity at WAIT - WAITINV (rw) */
    Ifx_Strict_32Bit BCGEN:2;         /**< \brief [21:20] Byte Control Signal Control - BCGEN (rw) */
    Ifx_Strict_32Bit PORTW:2;         /**< \brief [23:22] Device Addressing Mode - PORTW (rw) */
    Ifx_Strict_32Bit WAIT:2;          /**< \brief [25:24] External Wait Control - WAIT (rw) */
    Ifx_Strict_32Bit AAP:1;           /**< \brief [26:26] Asynchronous Address phase: - AAP (rw) */
    Ifx_Strict_32Bit LCKABRT:1;       /**< \brief [27:27] Lock Abort - LCKABRT (rwh) */
    Ifx_Strict_32Bit AGEN:4;          /**< \brief [31:28] Device Type for Region - AGEN (rw) */
} Ifx_EBU_BUS_RCON_Bits;

/** \brief EBU Bus Write Access Parameter Register */
typedef struct _Ifx_EBU_BUS_WAP_Bits
{
    Ifx_Strict_32Bit WRDTACS:4;       /**< \brief [3:0] Recovery Cycles between Different Regions - WRDTACS (rw) */
    Ifx_Strict_32Bit WRRECOVC:3;      /**< \brief [6:4] Recovery Cycles after Write Accesses - WRRECOVC (rw) */
    Ifx_Strict_32Bit WAITWRC:5;       /**< \brief [11:7] Programmed Wait States for write accesses - WAITWRC (rw) */
    Ifx_Strict_32Bit DATAC:4;         /**< \brief [15:12] Data Hold Cycles for Write Accesses - DATAC (rw) */
    Ifx_Strict_32Bit EXTCLOCK:2;      /**< \brief [17:16] Frequency of external clock at pin BFCLKO or SDCLKO - EXTCLOCK (rw) */
    Ifx_Strict_32Bit EXTDATA:2;       /**< \brief [19:18] Extended data - EXTDATA (rw) */
    Ifx_Strict_32Bit CMDDELAY:4;      /**< \brief [23:20] Command Delay Cycles - CMDDELAY (rw) */
    Ifx_Strict_32Bit AHOLDC:4;        /**< \brief [27:24] Address Hold Cycles - AHOLDC (rw) */
    Ifx_Strict_32Bit ADDRC:4;         /**< \brief [31:28] Address Cycles - ADDRC (rw) */
} Ifx_EBU_BUS_WAP_Bits;

/** \brief EBU Bus Write Configuration Register */
typedef struct _Ifx_EBU_BUS_WCON_Bits
{
    Ifx_Strict_32Bit FETBLEN:3;       /**< \brief [2:0] Burst Length for Synchronous Burst - FETBLEN (rw) */
    Ifx_Strict_32Bit FBBMSEL:1;       /**< \brief [3:3] Synchronous burst buffer mode select - FBBMSEL (rw) */
    Ifx_Strict_32Bit reserved_4:3;    /**< \brief [6:4] \internal Reserved */
    Ifx_Strict_32Bit NAA:1;           /**< \brief [7:7] Enable flash non-array access workaround - NAA (r) */
    Ifx_Strict_32Bit reserved_8:8;    /**< \brief [15:8] \internal Reserved */
    Ifx_Strict_32Bit ECSE:1;          /**< \brief [16:16] Early Chip Select for Synchronous Burst - ECSE (rw) */
    Ifx_Strict_32Bit EBSE:1;          /**< \brief [17:17] Early Burst Signal Enable for Synchronous Burst - EBSE (rw) */
    Ifx_Strict_32Bit reserved_18:1;    /**< \brief [18:18] \internal Reserved */
    Ifx_Strict_32Bit WAITINV:1;       /**< \brief [19:19] Reversed polarity at WAIT - WAITINV (rw) */
    Ifx_Strict_32Bit BCGEN:2;         /**< \brief [21:20] Byte Control Signal Control - BCGEN (rw) */
    Ifx_Strict_32Bit PORTW:2;         /**< \brief [23:22] Device Addressing Mode - PORTW (r) */
    Ifx_Strict_32Bit WAIT:2;          /**< \brief [25:24] External Wait Control - WAIT (rw) */
    Ifx_Strict_32Bit AAP:1;           /**< \brief [26:26] Asynchronous Address phase: - AAP (rw) */
    Ifx_Strict_32Bit LOCKCS:1;        /**< \brief [27:27] Lock Chip Select - LOCKCS (rw) */
    Ifx_Strict_32Bit AGEN:4;          /**< \brief [31:28] Device Type for Region - AGEN (rw) */
} Ifx_EBU_BUS_WCON_Bits;

/** \brief EBU Clock Control Register */
typedef struct _Ifx_EBU_CLC_Bits
{
    Ifx_Strict_32Bit DISR:1;          /**< \brief [0:0] EBU Disable Request Bit - DISR (rw) */
    Ifx_Strict_32Bit DISS:1;          /**< \brief [1:1] EBU Disable Status Bit - DISS (r) */
    Ifx_Strict_32Bit reserved_2:6;    /**< \brief [7:2] \internal Reserved */
    Ifx_Strict_32Bit EPE:1;           /**< \brief [8:8] Endinit Protection Enable - EPE (rw) */
    Ifx_Strict_32Bit reserved_9:7;    /**< \brief [15:9] \internal Reserved */
    Ifx_Strict_32Bit SYNC:1;          /**< \brief [16:16] EBU Clocking Mode - SYNC (rw) */
    Ifx_Strict_32Bit DIV2:1;          /**< \brief [17:17] DIV2 Clocking Mode - DIV2 (rw) */
    Ifx_Strict_32Bit EBUDIV:2;        /**< \brief [19:18] EBU Clock Divide Ratio - EBUDIV (rw) */
    Ifx_Strict_32Bit SYNCACK:1;       /**< \brief [20:20] EBU Clocking Mode Status - SYNCACK (r) */
    Ifx_Strict_32Bit DIV2ACK:1;       /**< \brief [21:21] DIV2 Clocking Mode Status - DIV2ACK (r) */
    Ifx_Strict_32Bit EBUDIVACK:2;     /**< \brief [23:22] EBU Clock Divide Ratio Status - EBUDIVACK (r) */
    Ifx_Strict_32Bit reserved_24:8;    /**< \brief [31:24] \internal Reserved */
} Ifx_EBU_CLC_Bits;

/** \brief EBU External Boot Configuration Register */
typedef struct _Ifx_EBU_EXTBOOT_Bits
{
    Ifx_Strict_32Bit CFGEND:1;        /**< \brief [0:0] Configuration End - CFGEND (rh) */
    Ifx_Strict_32Bit CFGERR:1;        /**< \brief [1:1] Configuration Fetch Error - CFGERR (rh) */
    Ifx_Strict_32Bit reserved_2:29;    /**< \brief [30:2] \internal Reserved */
    Ifx_Strict_32Bit EBUCFG:1;        /**< \brief [31:31] Configuration Word Fetch - EBUCFG (w) */
} Ifx_EBU_EXTBOOT_Bits;

/** \brief EBU Configuration Register */
typedef struct _Ifx_EBU_MODCON_Bits
{
    Ifx_Strict_32Bit STS:1;           /**< \brief [0:0] Memory Status Bit - STS (r) */
    Ifx_Strict_32Bit LCKABRT:1;       /**< \brief [1:1] Lock Abort - LCKABRT (rwh) */
    Ifx_Strict_32Bit SDTRI:1;         /**< \brief [2:2] SDRAM Tristate - SDTRI (rw) */
    Ifx_Strict_32Bit CLK_COMB:1;      /**< \brief [3:3] Combined External Bus Clock - CLK_COMB (rw) */
    Ifx_Strict_32Bit EXTLOCK:1;       /**< \brief [4:4] External Bus Lock Control - EXTLOCK (rw) */
    Ifx_Strict_32Bit ARBSYNC:1;       /**< \brief [5:5] Arbitration Signal Synchronization Control - ARBSYNC (rw) */
    Ifx_Strict_32Bit ARBMODE:2;       /**< \brief [7:6] Arbitration Mode Selection - ARBMODE (rw) */
    Ifx_Strict_32Bit TIMEOUTC:8;      /**< \brief [15:8] Bus Time-out Control - TIMEOUTC (rw) */
    Ifx_Strict_32Bit LOCKTIMEOUT:8;    /**< \brief [23:16] Lock Timeout Counter Preload - LOCKTIMEOUT (rw) */
    Ifx_Strict_32Bit FIFO_BYPASS:1;    /**< \brief [24:24] Reserved - FIFO_BYPASS (rw) */
    Ifx_Strict_32Bit FAST_SRI:1;      /**< \brief [25:25] Clock Cycles used for SRI Address Decode - FAST_SRI (rw) */
    Ifx_Strict_32Bit OCDS_SUSP_DIS:1;    /**< \brief [26:26] OCDS SUSPEND Disable - OCDS_SUSP_DIS (rw) */
    Ifx_Strict_32Bit reserved_27:3;    /**< \brief [29:27] \internal Reserved */
    Ifx_Strict_32Bit BUSSTATE:1;      /**< \brief [30:30] External Bus State - BUSSTATE (rh) */
    Ifx_Strict_32Bit ALE:1;           /**< \brief [31:31] ALE Mode - ALE (rw) */
} Ifx_EBU_MODCON_Bits;

/** \brief EBU Module Identification Register */
typedef struct _Ifx_EBU_MODID_Bits
{
    Ifx_Strict_32Bit ID_VALUE:32;     /**< \brief [31:0] Module Identification Value - ID_VALUE (r) */
} Ifx_EBU_MODID_Bits;

/** \brief EBU SDRAM Control Register */
typedef struct _Ifx_EBU_SDRMCON_Bits
{
    Ifx_Strict_32Bit CRAS:4;          /**< \brief [3:0] Row to precharge delay counter - CRAS (rw) */
    Ifx_Strict_32Bit CRFSH:4;         /**< \brief [7:4] Initialization refresh commands counter - CRFSH (rw) */
    Ifx_Strict_32Bit CRSC:2;          /**< \brief [9:8] Mode register set-up time - CRSC (rw) */
    Ifx_Strict_32Bit CRP:2;           /**< \brief [11:10] Row precharge time counter - CRP (rw) */
    Ifx_Strict_32Bit AWIDTH:2;        /**< \brief [13:12] Width of column address - AWIDTH (rw) */
    Ifx_Strict_32Bit CRCD:2;          /**< \brief [15:14] Row to column delay counter - CRCD (rw) */
    Ifx_Strict_32Bit CRC:6;           /**< \brief [21:16] Refresh cycle time counter - CRC (rw) */
    Ifx_Strict_32Bit BANKM:3;         /**< \brief [24:22] Mask for bank tag - BANKM (rw) */
    Ifx_Strict_32Bit reserved_25:3;    /**< \brief [27:25] \internal Reserved */
    Ifx_Strict_32Bit CLKDIS:1;        /**< \brief [28:28] Disable SDRAM clock output - CLKDIS (rw) */
    Ifx_Strict_32Bit PWR_MODE:2;      /**< \brief [30:29] Power Save Mode used for gated clock mode - PWR_MODE (rw) */
    Ifx_Strict_32Bit SDCMSEL:1;       /**< \brief [31:31] SDRAM clock mode select - SDCMSEL (rw) */
} Ifx_EBU_SDRMCON_Bits;

/** \brief EBU SDRAM Mode Register */
typedef struct _Ifx_EBU_SDRMOD_Bits
{
    Ifx_Strict_32Bit BURSTL:3;        /**< \brief [2:0] Burst length - BURSTL (rw) */
    Ifx_Strict_32Bit BTYP:1;          /**< \brief [3:3] Burst type - BTYP (rw) */
    Ifx_Strict_32Bit CASLAT:3;        /**< \brief [6:4] CAS latency - CASLAT (rw) */
    Ifx_Strict_32Bit OPMODE:7;        /**< \brief [13:7] Operation Mode - OPMODE (rw) */
    Ifx_Strict_32Bit reserved_14:1;    /**< \brief [14:14] \internal Reserved */
    Ifx_Strict_32Bit COLDSTART:1;     /**< \brief [15:15] SDRAM coldstart - COLDSTART (w) */
    Ifx_Strict_32Bit XOPM:14;         /**< \brief [29:16] Extended Operation Mode - XOPM (rw) */
    Ifx_Strict_32Bit XBA:2;           /**< \brief [31:30] Extended Operation Bank Select - XBA (rw) */
} Ifx_EBU_SDRMOD_Bits;

/** \brief EBU SDRAM Refresh Control Register */
typedef struct _Ifx_EBU_SDRMREF_Bits
{
    Ifx_Strict_32Bit REFRESHC:6;      /**< \brief [5:0] Refresh counter period - REFRESHC (rw) */
    Ifx_Strict_32Bit REFRESHR:3;      /**< \brief [8:6] Number of refresh commands - REFRESHR (rw) */
    Ifx_Strict_32Bit SELFREXST:1;     /**< \brief [9:9] Self Refresh Exit Status. - SELFREXST (rh) */
    Ifx_Strict_32Bit SELFREX:1;       /**< \brief [10:10] Self Refresh Exit (Power Up). - SELFREX (rw) */
    Ifx_Strict_32Bit SELFRENST:1;     /**< \brief [11:11] Self Refresh Entry Status. - SELFRENST (rh) */
    Ifx_Strict_32Bit SELFREN:1;       /**< \brief [12:12] Self Refresh Entry - SELFREN (rw) */
    Ifx_Strict_32Bit AUTOSELFR:1;     /**< \brief [13:13] Automatic Self Refresh - AUTOSELFR (rw) */
    Ifx_Strict_32Bit ERFSHC:2;        /**< \brief [15:14] Extended Refresh Counter Period - ERFSHC (rw) */
    Ifx_Strict_32Bit SELFREX_DLY:8;    /**< \brief [23:16] Self Refresh Exit Delay - SELFREX_DLY (rw) */
    Ifx_Strict_32Bit ARFSH:1;         /**< \brief [24:24] Auto Refresh on Self refresh Exit - ARFSH (rw) */
    Ifx_Strict_32Bit RES_DLY:3;       /**< \brief [27:25] Delay on Power Down Exit - RES_DLY (rw) */
    Ifx_Strict_32Bit reserved_28:4;    /**< \brief [31:28] \internal Reserved */
} Ifx_EBU_SDRMREF_Bits;

/** \brief EBU SDRAM Status Register */
typedef struct _Ifx_EBU_SDRSTAT_Bits
{
    Ifx_Strict_32Bit REFERR:1;        /**< \brief [0:0] SDRAM Refresh Error - REFERR (rwh) */
    Ifx_Strict_32Bit SDRMBUSY:1;      /**< \brief [1:1] SDRAM Busy - SDRMBUSY (rh) */
    Ifx_Strict_32Bit SDERR:1;         /**< \brief [2:2] SDRAM read error - SDERR (rwh) */
    Ifx_Strict_32Bit reserved_3:29;    /**< \brief [31:3] \internal Reserved */
} Ifx_EBU_SDRSTAT_Bits;

/** \brief EBU Test/Control Configuration Register */
typedef struct _Ifx_EBU_USERCON_Bits
{
    Ifx_Strict_32Bit DIP:1;           /**< \brief [0:0] Disable Internal Pipelining - DIP (rw) */
    Ifx_Strict_32Bit NAF:7;           /**< \brief [7:1] No Assigned Function - NAF (rw) */
    Ifx_Strict_32Bit reserved_8:8;    /**< \brief [15:8] \internal Reserved */
    Ifx_Strict_32Bit ADDIO:4;         /**< \brief [19:16] Address Pins to GPIO Mode - ADDIO (rw) */
    Ifx_Strict_32Bit reserved_20:8;    /**< \brief [27:20] \internal Reserved */
    Ifx_Strict_32Bit BCEN:2;          /**< \brief [29:28] Byte Control Enable - BCEN (rw) */
    Ifx_Strict_32Bit ADVIO:1;         /**< \brief [30:30] ADV Pin to GPIO Mode - ADVIO (rw) */
    Ifx_Strict_32Bit ADDLSW:1;        /**< \brief [31:31] Enable Address LSW, A(15:0) for GPIO - ADDLSW (rw) */
} Ifx_EBU_USERCON_Bits;

/** \}  */
/******************************************************************************/
/******************************************************************************/
/** \addtogroup IfxSfr_ebu_Registers_union
 * \{   */
/** \brief EBU Access Enable Register 0   */
typedef union
{
    Ifx_UReg_32Bit U;                 /**< \brief Unsigned access */
    Ifx_SReg_32Bit I;                 /**< \brief Signed access */
    Ifx_EBU_ACCEN0_Bits B;            /**< \brief Bitfield access */
} Ifx_EBU_ACCEN0;

/** \brief EBU Access Enable Register 1   */
typedef union
{
    Ifx_UReg_32Bit U;                 /**< \brief Unsigned access */
    Ifx_SReg_32Bit I;                 /**< \brief Signed access */
    Ifx_EBU_ACCEN1_Bits B;            /**< \brief Bitfield access */
} Ifx_EBU_ACCEN1;

/** \brief EBU Address Select Register ${x}   */
typedef union
{
    Ifx_UReg_32Bit U;                 /**< \brief Unsigned access */
    Ifx_SReg_32Bit I;                 /**< \brief Signed access */
    Ifx_EBU_ADDRSEL_Bits B;           /**< \brief Bitfield access */
} Ifx_EBU_ADDRSEL;

/** \brief EBU Bus Read Access Parameter Register   */
typedef union
{
    Ifx_UReg_32Bit U;                 /**< \brief Unsigned access */
    Ifx_SReg_32Bit I;                 /**< \brief Signed access */
    Ifx_EBU_BUS_RAP_Bits B;           /**< \brief Bitfield access */
} Ifx_EBU_BUS_RAP;

/** \brief EBU Bus Configuration Register   */
typedef union
{
    Ifx_UReg_32Bit U;                 /**< \brief Unsigned access */
    Ifx_SReg_32Bit I;                 /**< \brief Signed access */
    Ifx_EBU_BUS_RCON_Bits B;          /**< \brief Bitfield access */
} Ifx_EBU_BUS_RCON;

/** \brief EBU Bus Write Access Parameter Register   */
typedef union
{
    Ifx_UReg_32Bit U;                 /**< \brief Unsigned access */
    Ifx_SReg_32Bit I;                 /**< \brief Signed access */
    Ifx_EBU_BUS_WAP_Bits B;           /**< \brief Bitfield access */
} Ifx_EBU_BUS_WAP;

/** \brief EBU Bus Write Configuration Register   */
typedef union
{
    Ifx_UReg_32Bit U;                 /**< \brief Unsigned access */
    Ifx_SReg_32Bit I;                 /**< \brief Signed access */
    Ifx_EBU_BUS_WCON_Bits B;          /**< \brief Bitfield access */
} Ifx_EBU_BUS_WCON;

/** \brief EBU Clock Control Register   */
typedef union
{
    Ifx_UReg_32Bit U;                 /**< \brief Unsigned access */
    Ifx_SReg_32Bit I;                 /**< \brief Signed access */
    Ifx_EBU_CLC_Bits B;               /**< \brief Bitfield access */
} Ifx_EBU_CLC;

/** \brief EBU External Boot Configuration Register   */
typedef union
{
    Ifx_UReg_32Bit U;                 /**< \brief Unsigned access */
    Ifx_SReg_32Bit I;                 /**< \brief Signed access */
    Ifx_EBU_EXTBOOT_Bits B;           /**< \brief Bitfield access */
} Ifx_EBU_EXTBOOT;

/** \brief EBU Configuration Register   */
typedef union
{
    Ifx_UReg_32Bit U;                 /**< \brief Unsigned access */
    Ifx_SReg_32Bit I;                 /**< \brief Signed access */
    Ifx_EBU_MODCON_Bits B;            /**< \brief Bitfield access */
} Ifx_EBU_MODCON;

/** \brief EBU Module Identification Register   */
typedef union
{
    Ifx_UReg_32Bit U;                 /**< \brief Unsigned access */
    Ifx_SReg_32Bit I;                 /**< \brief Signed access */
    Ifx_EBU_MODID_Bits B;             /**< \brief Bitfield access */
} Ifx_EBU_MODID;

/** \brief EBU SDRAM Control Register   */
typedef union
{
    Ifx_UReg_32Bit U;                 /**< \brief Unsigned access */
    Ifx_SReg_32Bit I;                 /**< \brief Signed access */
    Ifx_EBU_SDRMCON_Bits B;           /**< \brief Bitfield access */
} Ifx_EBU_SDRMCON;

/** \brief EBU SDRAM Mode Register   */
typedef union
{
    Ifx_UReg_32Bit U;                 /**< \brief Unsigned access */
    Ifx_SReg_32Bit I;                 /**< \brief Signed access */
    Ifx_EBU_SDRMOD_Bits B;            /**< \brief Bitfield access */
} Ifx_EBU_SDRMOD;

/** \brief EBU SDRAM Refresh Control Register   */
typedef union
{
    Ifx_UReg_32Bit U;                 /**< \brief Unsigned access */
    Ifx_SReg_32Bit I;                 /**< \brief Signed access */
    Ifx_EBU_SDRMREF_Bits B;           /**< \brief Bitfield access */
} Ifx_EBU_SDRMREF;

/** \brief EBU SDRAM Status Register   */
typedef union
{
    Ifx_UReg_32Bit U;                 /**< \brief Unsigned access */
    Ifx_SReg_32Bit I;                 /**< \brief Signed access */
    Ifx_EBU_SDRSTAT_Bits B;           /**< \brief Bitfield access */
} Ifx_EBU_SDRSTAT;

/** \brief EBU Test/Control Configuration Register   */
typedef union
{
    Ifx_UReg_32Bit U;                 /**< \brief Unsigned access */
    Ifx_SReg_32Bit I;                 /**< \brief Signed access */
    Ifx_EBU_USERCON_Bits B;           /**< \brief Bitfield access */
} Ifx_EBU_USERCON;

/** \}  */

/******************************************************************************/
/******************************************************************************/
/** \addtogroup IfxSfr_Ebu_BUS_struct
 * \{  */
/******************************************************************************/
/** \name Object L1
 * \{  */
/** \brief BUS object */
typedef volatile struct _Ifx_EBU_BUS
{
       Ifx_EBU_BUS_RCON                    RCON;                   /**< \brief 0, EBU Bus Configuration Register*/
       Ifx_EBU_BUS_RAP                     RAP;                    /**< \brief 4, EBU Bus Read Access Parameter Register*/
       Ifx_EBU_BUS_WCON                    WCON;                   /**< \brief 8, EBU Bus Write Configuration Register*/
       Ifx_EBU_BUS_WAP                     WAP;                    /**< \brief C, EBU Bus Write Access Parameter Register*/
} Ifx_EBU_BUS;
/** \}  */
/******************************************************************************/
/** \}  */
/******************************************************************************/
/******************************************************************************/

/******************************************************************************/
/** \addtogroup IfxSfr_Ebu_Registers_struct
 * \{  */
/******************************************************************************/
/** \name Object L0
 * \{  */

/** \brief EBU object */
typedef volatile struct _Ifx_EBU
{
       Ifx_EBU_CLC                         CLC;                    /**< \brief 0, EBU Clock Control Register*/
       Ifx_EBU_MODCON                      MODCON;                 /**< \brief 4, */
       Ifx_EBU_MODID                       MODID;                  /**< \brief 8, EBU Module Identification Register*/
       Ifx_EBU_USERCON                     USERCON;                /**< \brief C, EBU Test/Control Configuration Register*/
       Ifx_EBU_EXTBOOT                     EXTBOOT;                /**< \brief 10, EBU External Boot Configuration Register*/
       Ifx_UReg_8Bit                       reserved_14[4];         /**< \brief 14, \internal Reserved */
       Ifx_EBU_ADDRSEL                     ADDRSEL[3];             /**< \brief 18, EBU Address Select Register ${x}*/
       Ifx_UReg_8Bit                       reserved_24[4];         /**< \brief 24, \internal Reserved */
       Ifx_EBU_BUS                         BUS[3];                 /**< \brief 28, EBU Bus Write Access Parameter Register*/
       Ifx_UReg_8Bit                       reserved_58[16];        /**< \brief 58, \internal Reserved */
       Ifx_EBU_SDRMCON                     SDRMCON;                /**< \brief 68, EBU SDRAM Control Register*/
       Ifx_EBU_SDRMOD                      SDRMOD;                 /**< \brief 6C, EBU SDRAM Mode Register*/
       Ifx_EBU_SDRMREF                     SDRMREF;                /**< \brief 70, EBU SDRAM Refresh Control Register*/
       Ifx_EBU_SDRSTAT                     SDRSTAT;                /**< \brief 74, EBU SDRAM Status Register*/
       Ifx_UReg_8Bit                       reserved_78[56];        /**< \brief 78, \internal Reserved */
       Ifx_EBU_ACCEN0                      ACCEN0;                 /**< \brief B0, EBU Access Enable Register 0*/
       Ifx_EBU_ACCEN1                      ACCEN1;                 /**< \brief B4, EBU Access Enable Register 1*/
       Ifx_UReg_8Bit                       reserved_B8[65352];     /**< \brief B8, \internal Reserved */
} Ifx_EBU;

/** \}  */
/******************************************************************************/
/** \}  */


/******************************************************************************/

/******************************************************************************/

#endif /* IFXEBU_REGDEF_H */
