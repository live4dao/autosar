/**
 * \file IfxEbcu_regdef.h
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
 * \defgroup IfxSfr_Ebcu_Registers Ebcu Registers
 * \ingroup IfxSfr
 * 
 * \defgroup IfxSfr_Ebcu_Registers_Bitfields Bitfields
 * \ingroup IfxSfr_Ebcu_Registers
 * 
 * \defgroup IfxSfr_Ebcu_Registers_union Register unions
 * \ingroup IfxSfr_Ebcu_Registers
 * 
 * \defgroup IfxSfr_Ebcu_Registers_struct Memory map
 * \ingroup IfxSfr_Ebcu_Registers
 */
#ifndef IFXEBCU_REGDEF_H
#define IFXEBCU_REGDEF_H 1
/******************************************************************************/
#include "Ifx_TypesReg.h"
/******************************************************************************/

/******************************************************************************/

/******************************************************************************/


/** \addtogroup IfxSfr_Ebcu_Registers_Bitfields
 * \{  */
/** \brief Access Enable Register 0 */
typedef struct _Ifx_EBCU_ACCEN0_Bits
{
    Ifx_UReg_32Bit EN0:1;             /**< \brief [0:0] Access Enable for Master TAG ID 0 (rw) */
    Ifx_UReg_32Bit EN1:1;             /**< \brief [1:1] Access Enable for Master TAG ID 1 (rw) */
    Ifx_UReg_32Bit EN2:1;             /**< \brief [2:2] Access Enable for Master TAG ID 2 (rw) */
    Ifx_UReg_32Bit EN3:1;             /**< \brief [3:3] Access Enable for Master TAG ID 3 (rw) */
    Ifx_UReg_32Bit EN4:1;             /**< \brief [4:4] Access Enable for Master TAG ID 4 (rw) */
    Ifx_UReg_32Bit EN5:1;             /**< \brief [5:5] Access Enable for Master TAG ID 5 (rw) */
    Ifx_UReg_32Bit EN6:1;             /**< \brief [6:6] Access Enable for Master TAG ID 6 (rw) */
    Ifx_UReg_32Bit EN7:1;             /**< \brief [7:7] Access Enable for Master TAG ID 7 (rw) */
    Ifx_UReg_32Bit EN8:1;             /**< \brief [8:8] Access Enable for Master TAG ID 8 (rw) */
    Ifx_UReg_32Bit EN9:1;             /**< \brief [9:9] Access Enable for Master TAG ID 9 (rw) */
    Ifx_UReg_32Bit EN10:1;            /**< \brief [10:10] Access Enable for Master TAG ID 10 (rw) */
    Ifx_UReg_32Bit EN11:1;            /**< \brief [11:11] Access Enable for Master TAG ID 11 (rw) */
    Ifx_UReg_32Bit EN12:1;            /**< \brief [12:12] Access Enable for Master TAG ID 12 (rw) */
    Ifx_UReg_32Bit EN13:1;            /**< \brief [13:13] Access Enable for Master TAG ID 13 (rw) */
    Ifx_UReg_32Bit EN14:1;            /**< \brief [14:14] Access Enable for Master TAG ID 14 (rw) */
    Ifx_UReg_32Bit EN15:1;            /**< \brief [15:15] Access Enable for Master TAG ID 15 (rw) */
    Ifx_UReg_32Bit EN16:1;            /**< \brief [16:16] Access Enable for Master TAG ID 16 (rw) */
    Ifx_UReg_32Bit EN17:1;            /**< \brief [17:17] Access Enable for Master TAG ID 17 (rw) */
    Ifx_UReg_32Bit EN18:1;            /**< \brief [18:18] Access Enable for Master TAG ID 18 (rw) */
    Ifx_UReg_32Bit EN19:1;            /**< \brief [19:19] Access Enable for Master TAG ID 19 (rw) */
    Ifx_UReg_32Bit EN20:1;            /**< \brief [20:20] Access Enable for Master TAG ID 20 (rw) */
    Ifx_UReg_32Bit EN21:1;            /**< \brief [21:21] Access Enable for Master TAG ID 21 (rw) */
    Ifx_UReg_32Bit EN22:1;            /**< \brief [22:22] Access Enable for Master TAG ID 22 (rw) */
    Ifx_UReg_32Bit EN23:1;            /**< \brief [23:23] Access Enable for Master TAG ID 23 (rw) */
    Ifx_UReg_32Bit EN24:1;            /**< \brief [24:24] Access Enable for Master TAG ID 24 (rw) */
    Ifx_UReg_32Bit EN25:1;            /**< \brief [25:25] Access Enable for Master TAG ID 25 (rw) */
    Ifx_UReg_32Bit EN26:1;            /**< \brief [26:26] Access Enable for Master TAG ID 26 (rw) */
    Ifx_UReg_32Bit EN27:1;            /**< \brief [27:27] Access Enable for Master TAG ID 27 (rw) */
    Ifx_UReg_32Bit EN28:1;            /**< \brief [28:28] Access Enable for Master TAG ID 28 (rw) */
    Ifx_UReg_32Bit EN29:1;            /**< \brief [29:29] Access Enable for Master TAG ID 29 (rw) */
    Ifx_UReg_32Bit EN30:1;            /**< \brief [30:30] Access Enable for Master TAG ID 30 (rw) */
    Ifx_UReg_32Bit EN31:1;            /**< \brief [31:31] Access Enable for Master TAG ID 31 (rw) */
} Ifx_EBCU_ACCEN0_Bits;

/** \brief Access Enable Register 1 */
typedef struct _Ifx_EBCU_ACCEN1_Bits
{
    Ifx_UReg_32Bit reserved_0:32;     /**< \brief [31:0] \internal Reserved */
} Ifx_EBCU_ACCEN1_Bits;

/** \brief BCU EDC Alarm Clear Register ${x} */
typedef struct _Ifx_EBCU_ALCLR_Bits
{
    Ifx_UReg_32Bit CLR00:1;           /**< \brief [0:0] Clear alarm 0 (w) */
    Ifx_UReg_32Bit CLR01:1;           /**< \brief [1:1] Clear alarm 1 (w) */
    Ifx_UReg_32Bit CLR02:1;           /**< \brief [2:2] Clear alarm 2 (w) */
    Ifx_UReg_32Bit CLR03:1;           /**< \brief [3:3] Clear alarm 3 (w) */
    Ifx_UReg_32Bit CLR04:1;           /**< \brief [4:4] Clear alarm 4 (w) */
    Ifx_UReg_32Bit CLR05:1;           /**< \brief [5:5] Clear alarm 5 (w) */
    Ifx_UReg_32Bit CLR06:1;           /**< \brief [6:6] Clear alarm 6 (w) */
    Ifx_UReg_32Bit CLR07:1;           /**< \brief [7:7] Clear alarm 7 (w) */
    Ifx_UReg_32Bit CLR08:1;           /**< \brief [8:8] Clear alarm 8 (w) */
    Ifx_UReg_32Bit CLR09:1;           /**< \brief [9:9] Clear alarm 9 (w) */
    Ifx_UReg_32Bit CLR10:1;           /**< \brief [10:10] Clear alarm 10 (w) */
    Ifx_UReg_32Bit CLR11:1;           /**< \brief [11:11] Clear alarm 11 (w) */
    Ifx_UReg_32Bit CLR12:1;           /**< \brief [12:12] Clear alarm 12 (w) */
    Ifx_UReg_32Bit CLR13:1;           /**< \brief [13:13] Clear alarm 13 (w) */
    Ifx_UReg_32Bit CLR14:1;           /**< \brief [14:14] Clear alarm 14 (w) */
    Ifx_UReg_32Bit CLR15:1;           /**< \brief [15:15] Clear alarm 15 (w) */
    Ifx_UReg_32Bit CLR16:1;           /**< \brief [16:16] Clear alarm 16 (w) */
    Ifx_UReg_32Bit CLR17:1;           /**< \brief [17:17] Clear alarm 17 (w) */
    Ifx_UReg_32Bit CLR18:1;           /**< \brief [18:18] Clear alarm 18 (w) */
    Ifx_UReg_32Bit CLR19:1;           /**< \brief [19:19] Clear alarm 19 (w) */
    Ifx_UReg_32Bit CLR20:1;           /**< \brief [20:20] Clear alarm 20 (w) */
    Ifx_UReg_32Bit CLR21:1;           /**< \brief [21:21] Clear alarm 21 (w) */
    Ifx_UReg_32Bit CLR22:1;           /**< \brief [22:22] Clear alarm 22 (w) */
    Ifx_UReg_32Bit CLR23:1;           /**< \brief [23:23] Clear alarm 23 (w) */
    Ifx_UReg_32Bit CLR24:1;           /**< \brief [24:24] Clear alarm 24 (w) */
    Ifx_UReg_32Bit CLR25:1;           /**< \brief [25:25] Clear alarm 25 (w) */
    Ifx_UReg_32Bit CLR26:1;           /**< \brief [26:26] Clear alarm 26 (w) */
    Ifx_UReg_32Bit CLR27:1;           /**< \brief [27:27] Clear alarm 27 (w) */
    Ifx_UReg_32Bit CLR28:1;           /**< \brief [28:28] Clear alarm 28 (w) */
    Ifx_UReg_32Bit CLR29:1;           /**< \brief [29:29] Clear alarm 29 (w) */
    Ifx_UReg_32Bit CLR30:1;           /**< \brief [30:30] Clear alarm 30 (w) */
    Ifx_UReg_32Bit CLR31:1;           /**< \brief [31:31] Clear alarm 31 (w) */
} Ifx_EBCU_ALCLR_Bits;

/** \brief BCU EDC Alarm Control Register */
typedef struct _Ifx_EBCU_ALCTRL_Bits
{
    Ifx_UReg_32Bit ALOV:1;            /**< \brief [0:0] Alarm Overflow (rh) */
    Ifx_UReg_32Bit ALOVCLR:1;         /**< \brief [1:1] Alarm Overflow Clear (w) */
    Ifx_UReg_32Bit reserved_2:30;     /**< \brief [31:2] \internal Reserved */
} Ifx_EBCU_ALCTRL_Bits;

/** \brief BCU EDC Alarm Status Register ${x} */
typedef struct _Ifx_EBCU_ALSTAT_Bits
{
    Ifx_UReg_32Bit AL00:1;            /**< \brief [0:0] Alarm 0 (rh) */
    Ifx_UReg_32Bit AL01:1;            /**< \brief [1:1] Alarm 1 (rh) */
    Ifx_UReg_32Bit AL02:1;            /**< \brief [2:2] Alarm 2 (rh) */
    Ifx_UReg_32Bit AL03:1;            /**< \brief [3:3] Alarm 3 (rh) */
    Ifx_UReg_32Bit AL04:1;            /**< \brief [4:4] Alarm 4 (rh) */
    Ifx_UReg_32Bit AL05:1;            /**< \brief [5:5] Alarm 5 (rh) */
    Ifx_UReg_32Bit AL06:1;            /**< \brief [6:6] Alarm 6 (rh) */
    Ifx_UReg_32Bit AL07:1;            /**< \brief [7:7] Alarm 7 (rh) */
    Ifx_UReg_32Bit AL08:1;            /**< \brief [8:8] Alarm 8 (rh) */
    Ifx_UReg_32Bit AL09:1;            /**< \brief [9:9] Alarm 9 (rh) */
    Ifx_UReg_32Bit AL10:1;            /**< \brief [10:10] Alarm 10 (rh) */
    Ifx_UReg_32Bit AL11:1;            /**< \brief [11:11] Alarm 11 (rh) */
    Ifx_UReg_32Bit AL12:1;            /**< \brief [12:12] Alarm 12 (rh) */
    Ifx_UReg_32Bit AL13:1;            /**< \brief [13:13] Alarm 13 (rh) */
    Ifx_UReg_32Bit AL14:1;            /**< \brief [14:14] Alarm 14 (rh) */
    Ifx_UReg_32Bit AL15:1;            /**< \brief [15:15] Alarm 15 (rh) */
    Ifx_UReg_32Bit AL16:1;            /**< \brief [16:16] Alarm 16 (rh) */
    Ifx_UReg_32Bit AL17:1;            /**< \brief [17:17] Alarm 17 (rh) */
    Ifx_UReg_32Bit AL18:1;            /**< \brief [18:18] Alarm 18 (rh) */
    Ifx_UReg_32Bit AL19:1;            /**< \brief [19:19] Alarm 19 (rh) */
    Ifx_UReg_32Bit AL20:1;            /**< \brief [20:20] Alarm 20 (rh) */
    Ifx_UReg_32Bit AL21:1;            /**< \brief [21:21] Alarm 21 (rh) */
    Ifx_UReg_32Bit AL22:1;            /**< \brief [22:22] Alarm 22 (rh) */
    Ifx_UReg_32Bit AL23:1;            /**< \brief [23:23] Alarm 23 (rh) */
    Ifx_UReg_32Bit AL24:1;            /**< \brief [24:24] Alarm 24 (rh) */
    Ifx_UReg_32Bit AL25:1;            /**< \brief [25:25] Alarm 25 (rh) */
    Ifx_UReg_32Bit AL26:1;            /**< \brief [26:26] Alarm 26 (rh) */
    Ifx_UReg_32Bit AL27:1;            /**< \brief [27:27] Alarm 27 (rh) */
    Ifx_UReg_32Bit AL28:1;            /**< \brief [28:28] Alarm 28 (rh) */
    Ifx_UReg_32Bit AL29:1;            /**< \brief [29:29] Alarm 29 (rh) */
    Ifx_UReg_32Bit AL30:1;            /**< \brief [30:30] Alarm 30 (rh) */
    Ifx_UReg_32Bit AL31:1;            /**< \brief [31:31] Alarm 31 (rh) */
} Ifx_EBCU_ALSTAT_Bits;

/** \brief BCU Control Register */
typedef struct _Ifx_EBCU_CON_Bits
{
    Ifx_UReg_32Bit TOUT:16;           /**< \brief [15:0] BCU Bus Time-Out Value (rw) */
    Ifx_UReg_32Bit DBG:1;             /**< \brief [16:16] BCU Debug Trace Enable (rw) */
    Ifx_UReg_32Bit reserved_17:2;     /**< \brief [18:17] \internal Reserved */
    Ifx_UReg_32Bit reserved_19:1;     /**< \brief [19:19] \internal Reserved */
    Ifx_UReg_32Bit reserved_20:4;     /**< \brief [23:20] \internal Reserved */
    Ifx_UReg_32Bit SPC:8;             /**< \brief [31:24] Starvation Period Control (rw) */
} Ifx_EBCU_CON_Bits;

/** \brief BCU Debug Address 1 Register */
typedef struct _Ifx_EBCU_DBADR1_Bits
{
    Ifx_UReg_32Bit ADR1:32;           /**< \brief [31:0] Debug Trigger Address 1 (rw) */
} Ifx_EBCU_DBADR1_Bits;

/** \brief BCU Debug Address 2 Register */
typedef struct _Ifx_EBCU_DBADR2_Bits
{
    Ifx_UReg_32Bit ADR2:32;           /**< \brief [31:0] Debug Trigger Address 2 (rw) */
} Ifx_EBCU_DBADR2_Bits;

/** \brief BCU Debug Trapped Address Register */
typedef struct _Ifx_EBCU_DBADRT_Bits
{
    Ifx_UReg_32Bit FPIADR:32;         /**< \brief [31:0] FPI Bus Address Status (rh) */
} Ifx_EBCU_DBADRT_Bits;

/** \brief BCU Debug Bus Operation Signals Register */
typedef struct _Ifx_EBCU_DBBOS_Bits
{
    Ifx_UReg_32Bit OPC:4;             /**< \brief [3:0] Opcode for Signal Status Debug Trigger (rw) */
    Ifx_UReg_32Bit SVM:1;             /**< \brief [4:4] SVM Signal for Status Debug Trigger (rw) */
    Ifx_UReg_32Bit reserved_5:3;      /**< \brief [7:5] \internal Reserved */
    Ifx_UReg_32Bit WR:1;              /**< \brief [8:8] Write Signal for Status Debug Trigger (rw) */
    Ifx_UReg_32Bit reserved_9:3;      /**< \brief [11:9] \internal Reserved */
    Ifx_UReg_32Bit RD:1;              /**< \brief [12:12] Write Signal for Status Debug Trigger (rw) */
    Ifx_UReg_32Bit reserved_13:19;    /**< \brief [31:13] \internal Reserved */
} Ifx_EBCU_DBBOS_Bits;

/** \brief BCU Debug Trapped Bus Operation Signals Register */
typedef struct _Ifx_EBCU_DBBOST_Bits
{
    Ifx_UReg_32Bit FPIOPC:4;          /**< \brief [3:0] FPI Bus Opcode Status (rh) */
    Ifx_UReg_32Bit FPISVM:1;          /**< \brief [4:4] FPI Bus Supervisor Mode Status (rh) */
    Ifx_UReg_32Bit FPIACK:2;          /**< \brief [6:5] FPI Bus Acknowledge Status (rh) */
    Ifx_UReg_32Bit FPIRDY:1;          /**< \brief [7:7] FPI Bus Ready Status (rh) */
    Ifx_UReg_32Bit FPIWR:1;           /**< \brief [8:8] FPI Bus Write Indication Status (rh) */
    Ifx_UReg_32Bit FPIRST:2;          /**< \brief [10:9] FPI Bus Reset Status (rh) */
    Ifx_UReg_32Bit FPIOPS:1;          /**< \brief [11:11] FPI Bus OCDS Suspend Status (rh) */
    Ifx_UReg_32Bit FPIRD:1;           /**< \brief [12:12] FPI Bus Read Indication Status (rh) */
    Ifx_UReg_32Bit FPIABORT:1;        /**< \brief [13:13] FPI Bus Abort Status (rh) */
    Ifx_UReg_32Bit FPITOUT:1;         /**< \brief [14:14] FPI Bus Time-out Status (rh) */
    Ifx_UReg_32Bit ENDINIT:1;         /**< \brief [15:15] FPI Bus Endinit Status (rh) */
    Ifx_UReg_32Bit FPITAG:6;          /**< \brief [21:16] FPI Bus Master TAG Status (rh) */
    Ifx_UReg_32Bit reserved_22:10;    /**< \brief [31:22] \internal Reserved */
} Ifx_EBCU_DBBOST_Bits;

/** \brief BCU Debug Control Register */
typedef struct _Ifx_EBCU_DBCNTL_Bits
{
    Ifx_UReg_32Bit EO:1;              /**< \brief [0:0] Status of BCU Debug Support Enable (r) */
    Ifx_UReg_32Bit OA:1;              /**< \brief [1:1] Status of BCU Breakpoint Logic (rh) */
    Ifx_UReg_32Bit reserved_2:2;      /**< \brief [3:2] \internal Reserved */
    Ifx_UReg_32Bit RA:1;              /**< \brief [4:4] Rearm BCU Breakpoint Logic (w) */
    Ifx_UReg_32Bit reserved_5:2;      /**< \brief [6:5] \internal Reserved */
    Ifx_UReg_32Bit reserved_7:1;      /**< \brief [7:7] \internal Reserved */
    Ifx_UReg_32Bit reserved_8:4;      /**< \brief [11:8] \internal Reserved */
    Ifx_UReg_32Bit CONCOM0:1;         /**< \brief [12:12] Grant and Address Trigger Relation (rw) */
    Ifx_UReg_32Bit CONCOM1:1;         /**< \brief [13:13] Address 1 and Address 2 Trigger Relation (rw) */
    Ifx_UReg_32Bit CONCOM2:1;         /**< \brief [14:14] Address and Signal Trigger Relation (rw) */
    Ifx_UReg_32Bit reserved_15:1;     /**< \brief [15:15] \internal Reserved */
    Ifx_UReg_32Bit ONG:1;             /**< \brief [16:16] Grant Trigger Enable (rw) */
    Ifx_UReg_32Bit reserved_17:3;     /**< \brief [19:17] \internal Reserved */
    Ifx_UReg_32Bit ONA1:2;            /**< \brief [21:20] Address 1 Trigger Control (rw) */
    Ifx_UReg_32Bit reserved_22:2;     /**< \brief [23:22] \internal Reserved */
    Ifx_UReg_32Bit ONA2:2;            /**< \brief [25:24] Address 2 Trigger Control (rw) */
    Ifx_UReg_32Bit reserved_26:2;     /**< \brief [27:26] \internal Reserved */
    Ifx_UReg_32Bit ONBOS0:1;          /**< \brief [28:28] Op code Signal Status Trigger Condition (rw) */
    Ifx_UReg_32Bit ONBOS1:1;          /**< \brief [29:29] Supervisor Mode Signal Trigger Condition (rw) */
    Ifx_UReg_32Bit ONBOS2:1;          /**< \brief [30:30] Write Signal Trigger Condition (rw) */
    Ifx_UReg_32Bit ONBOS3:1;          /**< \brief [31:31] Read Signal Trigger Condition (rw) */
} Ifx_EBCU_DBCNTL_Bits;

/** \brief BCU Debug Data Status Register */
typedef struct _Ifx_EBCU_DBDAT_Bits
{
    Ifx_UReg_32Bit FPIDATA:32;        /**< \brief [31:0] FPI Bus Data Status (rh) */
} Ifx_EBCU_DBDAT_Bits;

/** \brief EBCU Debug Trapped Master Register */
typedef struct _Ifx_EBCU_DBGNTT_Bits
{
    Ifx_UReg_32Bit IOC32P:1;          /**< \brief [0:0] IOC32P FPI Bus Master Status (rh) */
    Ifx_UReg_32Bit reserved_1:1;      /**< \brief [1:1] \internal Reserved */
    Ifx_UReg_32Bit reserved_2:1;      /**< \brief [2:2] \internal Reserved */
    Ifx_UReg_32Bit IOC32E:1;          /**< \brief [3:3] IOC32E FPI Bus Master Status (rh) */
    Ifx_UReg_32Bit reserved_4:1;      /**< \brief [4:4] \internal Reserved */
    Ifx_UReg_32Bit reserved_5:1;      /**< \brief [5:5] \internal Reserved */
    Ifx_UReg_32Bit SFI_S2F:1;         /**< \brief [6:6] SFI_S2F FPI Bus Master Status (rh) */
    Ifx_UReg_32Bit reserved_7:1;      /**< \brief [7:7] \internal Reserved */
    Ifx_UReg_32Bit reserved_8:1;      /**< \brief [8:8] \internal Reserved */
    Ifx_UReg_32Bit reserved_9:1;      /**< \brief [9:9] \internal Reserved */
    Ifx_UReg_32Bit reserved_10:1;     /**< \brief [10:10] \internal Reserved */
    Ifx_UReg_32Bit reserved_11:1;     /**< \brief [11:11] \internal Reserved */
    Ifx_UReg_32Bit reserved_12:1;     /**< \brief [12:12] \internal Reserved */
    Ifx_UReg_32Bit reserved_13:1;     /**< \brief [13:13] \internal Reserved */
    Ifx_UReg_32Bit reserved_14:1;     /**< \brief [14:14] \internal Reserved */
    Ifx_UReg_32Bit reserved_15:1;     /**< \brief [15:15] \internal Reserved */
    Ifx_UReg_32Bit reserved_16:16;    /**< \brief [31:16] \internal Reserved */
} Ifx_EBCU_DBGNTT_Bits;

/** \brief EBCU Debug Grant Mask Register */
typedef struct _Ifx_EBCU_DBGRNT_Bits
{
    Ifx_UReg_32Bit IOC32P:1;          /**< \brief [0:0] IOC32P Trigger Enable (rw) */
    Ifx_UReg_32Bit reserved_1:1;      /**< \brief [1:1] \internal Reserved */
    Ifx_UReg_32Bit reserved_2:1;      /**< \brief [2:2] \internal Reserved */
    Ifx_UReg_32Bit IOC32E:1;          /**< \brief [3:3] IOC32E Grant Trigger Enable (rw) */
    Ifx_UReg_32Bit reserved_4:1;      /**< \brief [4:4] \internal Reserved */
    Ifx_UReg_32Bit reserved_5:1;      /**< \brief [5:5] \internal Reserved */
    Ifx_UReg_32Bit SFI_S2F:1;         /**< \brief [6:6] SFI_S2F Grant Trigger Enable (rw) */
    Ifx_UReg_32Bit reserved_7:1;      /**< \brief [7:7] \internal Reserved */
    Ifx_UReg_32Bit reserved_8:1;      /**< \brief [8:8] \internal Reserved */
    Ifx_UReg_32Bit reserved_9:1;      /**< \brief [9:9] \internal Reserved */
    Ifx_UReg_32Bit reserved_10:1;     /**< \brief [10:10] \internal Reserved */
    Ifx_UReg_32Bit reserved_11:1;     /**< \brief [11:11] \internal Reserved */
    Ifx_UReg_32Bit reserved_12:1;     /**< \brief [12:12] \internal Reserved */
    Ifx_UReg_32Bit reserved_13:1;     /**< \brief [13:13] \internal Reserved */
    Ifx_UReg_32Bit reserved_14:1;     /**< \brief [14:14] \internal Reserved */
    Ifx_UReg_32Bit reserved_15:1;     /**< \brief [15:15] \internal Reserved */
    Ifx_UReg_32Bit reserved_16:16;    /**< \brief [31:16] \internal Reserved */
} Ifx_EBCU_DBGRNT_Bits;

/** \brief BCU Error Address Capture Register */
typedef struct _Ifx_EBCU_EADD_Bits
{
    Ifx_UReg_32Bit FPIADR:32;         /**< \brief [31:0] Captured FPI Bus Address - FPIADR (rwh) */
} Ifx_EBCU_EADD_Bits;

/** \brief BCU Error Control Capture Register */
typedef struct _Ifx_EBCU_ECON_Bits
{
    Ifx_UReg_32Bit ERRCNT:14;         /**< \brief [13:0] FPI Bus Error Counter (rwh) */
    Ifx_UReg_32Bit TOUT:1;            /**< \brief [14:14] State of FPI Bus Time-Out Signal (rwh) */
    Ifx_UReg_32Bit RDY:1;             /**< \brief [15:15] State of FPI Bus Ready Signal (rwh) */
    Ifx_UReg_32Bit ABT:1;             /**< \brief [16:16] State of FPI Bus Abort Signal (rwh) */
    Ifx_UReg_32Bit ACK:2;             /**< \brief [18:17] State of FPI Bus Acknowledge Signals (rwh) */
    Ifx_UReg_32Bit SVM:1;             /**< \brief [19:19] State of FPI Bus Supervisor Mode Signal (rwh) */
    Ifx_UReg_32Bit WRN:1;             /**< \brief [20:20] State of FPI Bus Write Signal (rwh) */
    Ifx_UReg_32Bit RDN:1;             /**< \brief [21:21] State of FPI Bus Read Signal (rwh) */
    Ifx_UReg_32Bit TAG:6;             /**< \brief [27:22] FPI Bus Master Tag Number Signals (rwh) */
    Ifx_UReg_32Bit OPC:4;             /**< \brief [31:28] FPI Bus Operation Code Signals (rwh) */
} Ifx_EBCU_ECON_Bits;

/** \brief BCU Error Data Capture Register */
typedef struct _Ifx_EBCU_EDAT_Bits
{
    Ifx_UReg_32Bit FPIDAT:32;         /**< \brief [31:0] Captured FPI Bus Data - FPIDAT (rwh) */
} Ifx_EBCU_EDAT_Bits;

/** \brief FPI Error Generation Control Register */
typedef struct _Ifx_EBCU_FEGEN_Bits
{
    Ifx_UReg_32Bit SEDM:3;            /**< \brief [2:0] SEDM (Slave Encoder) (rw) */
    Ifx_UReg_32Bit reserved_3:5;      /**< \brief [7:3] \internal Reserved */
    Ifx_UReg_32Bit MEDM:3;            /**< \brief [10:8] MEDM (Master Encoder) Type of Error (rw) */
    Ifx_UReg_32Bit reserved_11:5;     /**< \brief [15:11] \internal Reserved */
    Ifx_UReg_32Bit EN:3;              /**< \brief [18:16] Enable Signal Type of Error (rw) */
    Ifx_UReg_32Bit reserved_19:5;     /**< \brief [23:19] \internal Reserved */
    Ifx_UReg_32Bit BCU:2;             /**< \brief [25:24] BCU Type of Error (rw) */
    Ifx_UReg_32Bit reserved_26:6;     /**< \brief [31:26] \internal Reserved */
} Ifx_EBCU_FEGEN_Bits;

/** \brief Module Identification Register */
typedef struct _Ifx_EBCU_ID_Bits
{
    Ifx_UReg_32Bit MOD_REV:8;         /**< \brief [7:0] Module Revision Number - MOD_REV (r) */
    Ifx_UReg_32Bit MOD_NUMBER:8;      /**< \brief [15:8] Module Number Value - MOD_NUMBER (r) */
    Ifx_UReg_32Bit reserved_16:16;    /**< \brief [31:16] \internal Reserved */
} Ifx_EBCU_ID_Bits;

/** \brief Arbiter Priority Register High */
typedef struct _Ifx_EBCU_PRIOH_Bits
{
    Ifx_UReg_32Bit reserved_0:4;      /**< \brief [3:0] \internal Reserved */
    Ifx_UReg_32Bit reserved_4:4;      /**< \brief [7:4] \internal Reserved */
    Ifx_UReg_32Bit reserved_8:4;      /**< \brief [11:8] \internal Reserved */
    Ifx_UReg_32Bit reserved_12:4;     /**< \brief [15:12] \internal Reserved */
    Ifx_UReg_32Bit reserved_16:4;     /**< \brief [19:16] \internal Reserved */
    Ifx_UReg_32Bit reserved_20:4;     /**< \brief [23:20] \internal Reserved */
    Ifx_UReg_32Bit reserved_24:4;     /**< \brief [27:24] \internal Reserved */
    Ifx_UReg_32Bit reserved_28:4;     /**< \brief [31:28] \internal Reserved */
} Ifx_EBCU_PRIOH_Bits;

/** \brief Arbiter Priority Register Low */
typedef struct _Ifx_EBCU_PRIOL_Bits
{
    Ifx_UReg_32Bit IOC32P:4;          /**< \brief [3:0] IOC32P Priority (Index 0) (rw) */
    Ifx_UReg_32Bit reserved_4:4;      /**< \brief [7:4] \internal Reserved */
    Ifx_UReg_32Bit reserved_8:4;      /**< \brief [11:8] \internal Reserved */
    Ifx_UReg_32Bit IOC32E:4;          /**< \brief [15:12] IOC32E Priority (Index 3) (rw) */
    Ifx_UReg_32Bit reserved_16:4;     /**< \brief [19:16] \internal Reserved */
    Ifx_UReg_32Bit reserved_20:4;     /**< \brief [23:20] \internal Reserved */
    Ifx_UReg_32Bit SFI_S2F:4;         /**< \brief [27:24] SFI Bridge SRI2FPI Priority (Index 6) (rw) */
    Ifx_UReg_32Bit reserved_28:4;     /**< \brief [31:28] \internal Reserved */
} Ifx_EBCU_PRIOL_Bits;

/** \}  */
/******************************************************************************/
/******************************************************************************/
/** \addtogroup IfxSfr_ebcu_Registers_union
 * \{   */
/** \brief Access Enable Register 0   */
typedef union
{
    Ifx_UReg_32Bit U;                 /**< \brief Unsigned access */
    Ifx_SReg_32Bit I;                 /**< \brief Signed access */
    Ifx_EBCU_ACCEN0_Bits B;           /**< \brief Bitfield access */
} Ifx_EBCU_ACCEN0;

/** \brief Access Enable Register 1   */
typedef union
{
    Ifx_UReg_32Bit U;                 /**< \brief Unsigned access */
    Ifx_SReg_32Bit I;                 /**< \brief Signed access */
    Ifx_EBCU_ACCEN1_Bits B;           /**< \brief Bitfield access */
} Ifx_EBCU_ACCEN1;

/** \brief BCU EDC Alarm Clear Register ${x}   */
typedef union
{
    Ifx_UReg_32Bit U;                 /**< \brief Unsigned access */
    Ifx_SReg_32Bit I;                 /**< \brief Signed access */
    Ifx_EBCU_ALCLR_Bits B;            /**< \brief Bitfield access */
} Ifx_EBCU_ALCLR;

/** \brief BCU EDC Alarm Control Register   */
typedef union
{
    Ifx_UReg_32Bit U;                 /**< \brief Unsigned access */
    Ifx_SReg_32Bit I;                 /**< \brief Signed access */
    Ifx_EBCU_ALCTRL_Bits B;           /**< \brief Bitfield access */
} Ifx_EBCU_ALCTRL;

/** \brief BCU EDC Alarm Status Register ${x}   */
typedef union
{
    Ifx_UReg_32Bit U;                 /**< \brief Unsigned access */
    Ifx_SReg_32Bit I;                 /**< \brief Signed access */
    Ifx_EBCU_ALSTAT_Bits B;           /**< \brief Bitfield access */
} Ifx_EBCU_ALSTAT;

/** \brief BCU Control Register   */
typedef union
{
    Ifx_UReg_32Bit U;                 /**< \brief Unsigned access */
    Ifx_SReg_32Bit I;                 /**< \brief Signed access */
    Ifx_EBCU_CON_Bits B;              /**< \brief Bitfield access */
} Ifx_EBCU_CON;

/** \brief BCU Debug Address 1 Register   */
typedef union
{
    Ifx_UReg_32Bit U;                 /**< \brief Unsigned access */
    Ifx_SReg_32Bit I;                 /**< \brief Signed access */
    Ifx_EBCU_DBADR1_Bits B;           /**< \brief Bitfield access */
} Ifx_EBCU_DBADR1;

/** \brief BCU Debug Address 2 Register   */
typedef union
{
    Ifx_UReg_32Bit U;                 /**< \brief Unsigned access */
    Ifx_SReg_32Bit I;                 /**< \brief Signed access */
    Ifx_EBCU_DBADR2_Bits B;           /**< \brief Bitfield access */
} Ifx_EBCU_DBADR2;

/** \brief BCU Debug Trapped Address Register   */
typedef union
{
    Ifx_UReg_32Bit U;                 /**< \brief Unsigned access */
    Ifx_SReg_32Bit I;                 /**< \brief Signed access */
    Ifx_EBCU_DBADRT_Bits B;           /**< \brief Bitfield access */
} Ifx_EBCU_DBADRT;

/** \brief BCU Debug Bus Operation Signals Register   */
typedef union
{
    Ifx_UReg_32Bit U;                 /**< \brief Unsigned access */
    Ifx_SReg_32Bit I;                 /**< \brief Signed access */
    Ifx_EBCU_DBBOS_Bits B;            /**< \brief Bitfield access */
} Ifx_EBCU_DBBOS;

/** \brief BCU Debug Trapped Bus Operation Signals Register   */
typedef union
{
    Ifx_UReg_32Bit U;                 /**< \brief Unsigned access */
    Ifx_SReg_32Bit I;                 /**< \brief Signed access */
    Ifx_EBCU_DBBOST_Bits B;           /**< \brief Bitfield access */
} Ifx_EBCU_DBBOST;

/** \brief BCU Debug Control Register   */
typedef union
{
    Ifx_UReg_32Bit U;                 /**< \brief Unsigned access */
    Ifx_SReg_32Bit I;                 /**< \brief Signed access */
    Ifx_EBCU_DBCNTL_Bits B;           /**< \brief Bitfield access */
} Ifx_EBCU_DBCNTL;

/** \brief BCU Debug Data Status Register   */
typedef union
{
    Ifx_UReg_32Bit U;                 /**< \brief Unsigned access */
    Ifx_SReg_32Bit I;                 /**< \brief Signed access */
    Ifx_EBCU_DBDAT_Bits B;            /**< \brief Bitfield access */
} Ifx_EBCU_DBDAT;

/** \brief EBCU Debug Trapped Master Register   */
typedef union
{
    Ifx_UReg_32Bit U;                 /**< \brief Unsigned access */
    Ifx_SReg_32Bit I;                 /**< \brief Signed access */
    Ifx_EBCU_DBGNTT_Bits B;           /**< \brief Bitfield access */
} Ifx_EBCU_DBGNTT;

/** \brief EBCU Debug Grant Mask Register   */
typedef union
{
    Ifx_UReg_32Bit U;                 /**< \brief Unsigned access */
    Ifx_SReg_32Bit I;                 /**< \brief Signed access */
    Ifx_EBCU_DBGRNT_Bits B;           /**< \brief Bitfield access */
} Ifx_EBCU_DBGRNT;

/** \brief BCU Error Address Capture Register   */
typedef union
{
    Ifx_UReg_32Bit U;                 /**< \brief Unsigned access */
    Ifx_SReg_32Bit I;                 /**< \brief Signed access */
    Ifx_EBCU_EADD_Bits B;             /**< \brief Bitfield access */
} Ifx_EBCU_EADD;

/** \brief BCU Error Control Capture Register   */
typedef union
{
    Ifx_UReg_32Bit U;                 /**< \brief Unsigned access */
    Ifx_SReg_32Bit I;                 /**< \brief Signed access */
    Ifx_EBCU_ECON_Bits B;             /**< \brief Bitfield access */
} Ifx_EBCU_ECON;

/** \brief BCU Error Data Capture Register   */
typedef union
{
    Ifx_UReg_32Bit U;                 /**< \brief Unsigned access */
    Ifx_SReg_32Bit I;                 /**< \brief Signed access */
    Ifx_EBCU_EDAT_Bits B;             /**< \brief Bitfield access */
} Ifx_EBCU_EDAT;

/** \brief FPI Error Generation Control Register   */
typedef union
{
    Ifx_UReg_32Bit U;                 /**< \brief Unsigned access */
    Ifx_SReg_32Bit I;                 /**< \brief Signed access */
    Ifx_EBCU_FEGEN_Bits B;            /**< \brief Bitfield access */
} Ifx_EBCU_FEGEN;

/** \brief Module Identification Register   */
typedef union
{
    Ifx_UReg_32Bit U;                 /**< \brief Unsigned access */
    Ifx_SReg_32Bit I;                 /**< \brief Signed access */
    Ifx_EBCU_ID_Bits B;               /**< \brief Bitfield access */
} Ifx_EBCU_ID;

/** \brief Arbiter Priority Register High   */
typedef union
{
    Ifx_UReg_32Bit U;                 /**< \brief Unsigned access */
    Ifx_SReg_32Bit I;                 /**< \brief Signed access */
    Ifx_EBCU_PRIOH_Bits B;            /**< \brief Bitfield access */
} Ifx_EBCU_PRIOH;

/** \brief Arbiter Priority Register Low   */
typedef union
{
    Ifx_UReg_32Bit U;                 /**< \brief Unsigned access */
    Ifx_SReg_32Bit I;                 /**< \brief Signed access */
    Ifx_EBCU_PRIOL_Bits B;            /**< \brief Bitfield access */
} Ifx_EBCU_PRIOL;

/** \}  */

/******************************************************************************/
/** \addtogroup IfxSfr_Ebcu_Registers_struct
 * \{  */
/******************************************************************************/
/** \name Object L0
 * \{  */

/** \brief EBCU object */
typedef volatile struct _Ifx_EBCU
{
       Ifx_UReg_8Bit                       reserved_0[8];          /**< \brief 0, \internal Reserved */
       Ifx_EBCU_ID                         ID;                     /**< \brief 8, Module Identification Register*/
       Ifx_UReg_8Bit                       reserved_C[4];          /**< \brief C, \internal Reserved */
       Ifx_EBCU_CON                        CON;                    /**< \brief 10, BCU Control Register*/
       Ifx_EBCU_PRIOH                      PRIOH;                  /**< \brief 14, */
       Ifx_EBCU_PRIOL                      PRIOL;                  /**< \brief 18, */
       Ifx_UReg_8Bit                       reserved_1C[4];         /**< \brief 1C, \internal Reserved */
       Ifx_EBCU_ECON                       ECON;                   /**< \brief 20, BCU Error Control Capture Register*/
       Ifx_EBCU_EADD                       EADD;                   /**< \brief 24, BCU Error Address Capture Register*/
       Ifx_EBCU_EDAT                       EDAT;                   /**< \brief 28, BCU Error Data Capture Register*/
       Ifx_UReg_8Bit                       reserved_2C[4];         /**< \brief 2C, \internal Reserved */
       Ifx_EBCU_DBCNTL                     DBCNTL;                 /**< \brief 30, BCU Debug Control Register*/
       Ifx_EBCU_DBGRNT                     DBGRNT;                 /**< \brief 34, */
       Ifx_EBCU_DBADR1                     DBADR1;                 /**< \brief 38, BCU Debug Address 1 Register*/
       Ifx_EBCU_DBADR2                     DBADR2;                 /**< \brief 3C, BCU Debug Address 2 Register*/
       Ifx_EBCU_DBBOS                      DBBOS;                  /**< \brief 40, BCU Debug Bus Operation Signals Register*/
       Ifx_EBCU_DBGNTT                     DBGNTT;                 /**< \brief 44, */
       Ifx_EBCU_DBADRT                     DBADRT;                 /**< \brief 48, BCU Debug Trapped Address Register*/
       Ifx_EBCU_DBBOST                     DBBOST;                 /**< \brief 4C, BCU Debug Trapped Bus Operation Signals Register*/
       Ifx_EBCU_DBDAT                      DBDAT;                  /**< \brief 50, BCU Debug Data Status Register*/
       Ifx_UReg_8Bit                       reserved_54[12];        /**< \brief 54, \internal Reserved */
       Ifx_EBCU_ALSTAT                     ALSTAT[4];              /**< \brief 60, BCU EDC Alarm Status Register ${x}*/
       Ifx_EBCU_ALCLR                      ALCLR[4];               /**< \brief 70, BCU EDC Alarm Clear Register ${x}*/
       Ifx_EBCU_ALCTRL                     ALCTRL;                 /**< \brief 80, BCU EDC Alarm Control Register*/
       Ifx_EBCU_FEGEN                      FEGEN;                  /**< \brief 84, FPI Error Generation Control Register*/
       Ifx_UReg_8Bit                       reserved_88[112];       /**< \brief 88, \internal Reserved */
       Ifx_EBCU_ACCEN1                     ACCEN1;                 /**< \brief F8, Access Enable Register 1*/
       Ifx_EBCU_ACCEN0                     ACCEN0;                 /**< \brief FC, Access Enable Register 0*/
} Ifx_EBCU;

/** \}  */
/******************************************************************************/
/** \}  */


/******************************************************************************/

/******************************************************************************/

#endif /* IFXEBCU_REGDEF_H */
