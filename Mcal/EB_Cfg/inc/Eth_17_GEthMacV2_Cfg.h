/*******************************************************************************
**                                                                            **
** Copyright (C) Infineon Technologies (2020)                                 **
**                                                                            **
** All rights reserved.                                                       **
**                                                                            **
** This document contains proprietary information belonging to Infineon       **
** Technologies. Passing on and copying of this document, and communication   **
** of its contents is not permitted without prior written authorization.      **
**                                                                            **
********************************************************************************
**                                                                            **
**  FILENAME  : Eth_17_GEthMacV2_Cfg.h                                        **
**                                                                            **
**  VERSION   : 3.0.0                                                         **
**                                                                            **
**  DATE, TIME: 2024-02-04, 18:05:18      !!!IGNORE-LINE!!!                   **
**                                                                            **
**  GENERATOR : Build b191017-0938          !!!IGNORE-LINE!!!                 **
**                                                                            **
**  BSW MODULE DECRIPTION : NA                                                **
**                                                                            **
**  VARIANT   : Variant PB                                                    **
**                                                                            **
**  PLATFORM  : Infineon AURIX2G                                              **
**                                                                            **
**  AUTHOR    : DL-AUTOSAR-Engineering                                        **
**                                                                            **
**  VENDOR    : Infineon Technologies                                         **
**                                                                            **
**  DESCRIPTION  : Eth configuration generated out of ECUC file               **
**                                                                            **
**  SPECIFICATION(S) : Specification of Eth Driver, AUTOSAR Release 4.4.0     **
**                                                                            **
**  MAY BE CHANGED BY USER : no                                               **
**                                                                            **
*******************************************************************************/

#ifndef ETH_17_GETHMACV2_CFG_H
#define ETH_17_GETHMACV2_CFG_H
/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/

/*******************************************************************************
**                      Global Macro Definitions                              **
*******************************************************************************/

#define ETH_17_GETHMACV2_AR_RELEASE_MAJOR_VERSION      (4U)
#define ETH_17_GETHMACV2_AR_RELEASE_MINOR_VERSION      (4U)
#define ETH_17_GETHMACV2_AR_RELEASE_REVISION_VERSION   (0U)

#define ETH_17_GETHMACV2_SW_MAJOR_VERSION              (20U)
#define ETH_17_GETHMACV2_SW_MINOR_VERSION              (25U)
#define ETH_17_GETHMACV2_SW_PATCH_VERSION              (0U)

/*
Configuration: ETH_17_GETHMACV2_DEV_ERROR_DETECT
- if STD_ON, Development error is Enabled
- if STD_OFF,Development error is Disabled
This parameter shall activate or deactivate the detection of all
development errors.
*/
#define ETH_17_GETHMACV2_DEV_ERROR_DETECT  (STD_OFF)

/*
Configuration: ETH_17_GETHMACV2_VERSION_INFO_API
- if STD_ON, Function Eth_17_GEthMacV2_GetVersionInfo is available
- if STD_OFF,Function Eth_17_GEthMacV2_GetVersionInfo is not available
*/
#define ETH_17_GETHMACV2_VERSION_INFO_API  (STD_OFF)

/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
#ifndef Eth_17_GEthMacV2Conf_EthCtrlConfig_EthCtrlConfig_0
/* Macro to hold index of the configured controller */
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
#define Eth_17_GEthMacV2Conf_EthCtrlConfig_EthCtrlConfig_0 (0U)
#endif

/*
Configuration: ETH_17_GETHMACV2_INDEX
- Ethernet Driver Instance ID, used in DET  Interface.
*/
#define ETH_17_GETHMACV2_INDEX (0U)

/*
Configuration: ETH_17_GETHMACV2_ENA_MII_API
- if STD_ON, Functions Eth_17_WriteMii,Eth_17_ReadMii are available
- if STD_OFF,Functions Eth_17_WriteMii,Eth_17_ReadMii are not available
*/
#define ETH_17_GETHMACV2_ENA_MII_API  (STD_ON)

/*
Configuration: ETH_17_GETHMACV2_RX_IRQHDLR
- if STD_ON, the receive interrupt handler is available
- if STD_OFF, the receive interrupt handler is not available
*/
#define ETH_17_GETHMACV2_RX_IRQHDLR  (STD_ON)

/*
Configuration: ETH_17_GETHMACV2_TX_IRQHDLR
- if STD_ON, the transmit interrupt handler is available
- if STD_OFF, the transmit interrupt handler is not available
*/
#define ETH_17_GETHMACV2_TX_IRQHDLR  (STD_ON)

/* Maximum time in nanoseconds to wait for hardware timeout errors*/
#define ETH_17_GETHMACV2_MAXTIMEOUT_COUNT  (100000U)

/*
Configuration: ETH_17_GETHMACV2_SWT_MANAGEMENT_SUPPORT
- if STD_ON, Ethernet switch management support is enabled
- if STD_OFF, Ethernet switch management support is disabled
*/
#define ETH_17_GETHMACV2_SWT_MANAGEMENT_SUPPORT        (STD_OFF)

/* Rx buffer count and size for controller0 FIFO Index0 */
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers going beyond 32
characters due to MIP added as per AUTOSAR requirement. Since compiler
supports more than 32 characters, no side effects seen. */
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers going beyond 32
characters due to MIP added as per AUTOSAR requirement. Since compiler
supports more than 32 characters, no side effects seen. */
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers going beyond 32
characters due to MIP added as per AUTOSAR requirement. Since compiler
supports more than 32 characters, no side effects seen. */
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers going beyond 32
characters due to MIP added as per AUTOSAR requirement. Since compiler
supports more than 32 characters, no side effects seen. */
#define ETH_17_GETHMACV2_FIFO0_CTRL0_RXBUF_COUNT      (4U)

/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers going beyond 32
characters due to MIP added as per AUTOSAR requirement. Since compiler
supports more than 32 characters, no side effects seen. */
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers going beyond 32
characters due to MIP added as per AUTOSAR requirement. Since compiler
supports more than 32 characters, no side effects seen. */
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers going beyond 32
characters due to MIP added as per AUTOSAR requirement. Since compiler
supports more than 32 characters, no side effects seen. */
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers going beyond 32
characters due to MIP added as per AUTOSAR requirement. Since compiler
supports more than 32 characters, no side effects seen. */
#define ETH_17_GETHMACV2_FIFO0_CTRL0_RXBUF_SIZE       (6112U)

/* Rx buffer count and size for controller0 FIFO Index1 */
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers going beyond 32
characters due to MIP added as per AUTOSAR requirement. Since compiler
supports more than 32 characters, no side effects seen. */
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers going beyond 32
characters due to MIP added as per AUTOSAR requirement. Since compiler
supports more than 32 characters, no side effects seen. */
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers going beyond 32
characters due to MIP added as per AUTOSAR requirement. Since compiler
supports more than 32 characters, no side effects seen. */
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers going beyond 32
characters due to MIP added as per AUTOSAR requirement. Since compiler
supports more than 32 characters, no side effects seen. */
#define ETH_17_GETHMACV2_FIFO1_CTRL0_RXBUF_COUNT      (0U)

/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers going beyond 32
characters due to MIP added as per AUTOSAR requirement. Since compiler
supports more than 32 characters, no side effects seen. */
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers going beyond 32
characters due to MIP added as per AUTOSAR requirement. Since compiler
supports more than 32 characters, no side effects seen. */
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers going beyond 32
characters due to MIP added as per AUTOSAR requirement. Since compiler
supports more than 32 characters, no side effects seen. */
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers going beyond 32
characters due to MIP added as per AUTOSAR requirement. Since compiler
supports more than 32 characters, no side effects seen. */
#define ETH_17_GETHMACV2_FIFO1_CTRL0_RXBUF_SIZE       (0U)

/* Rx buffer count and size for controller0 FIFO Index2 */
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers going beyond 32
characters due to MIP added as per AUTOSAR requirement. Since compiler
supports more than 32 characters, no side effects seen. */
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers going beyond 32
characters due to MIP added as per AUTOSAR requirement. Since compiler
supports more than 32 characters, no side effects seen. */
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers going beyond 32
characters due to MIP added as per AUTOSAR requirement. Since compiler
supports more than 32 characters, no side effects seen. */
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers going beyond 32
characters due to MIP added as per AUTOSAR requirement. Since compiler
supports more than 32 characters, no side effects seen. */
#define ETH_17_GETHMACV2_FIFO2_CTRL0_RXBUF_COUNT      (0U)

/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers going beyond 32
characters due to MIP added as per AUTOSAR requirement. Since compiler
supports more than 32 characters, no side effects seen. */
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers going beyond 32
characters due to MIP added as per AUTOSAR requirement. Since compiler
supports more than 32 characters, no side effects seen. */
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers going beyond 32
characters due to MIP added as per AUTOSAR requirement. Since compiler
supports more than 32 characters, no side effects seen. */
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers going beyond 32
characters due to MIP added as per AUTOSAR requirement. Since compiler
supports more than 32 characters, no side effects seen. */
#define ETH_17_GETHMACV2_FIFO2_CTRL0_RXBUF_SIZE       (0U)

/* Rx buffer count and size for controller0 FIFO Index3 */
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers going beyond 32
characters due to MIP added as per AUTOSAR requirement. Since compiler
supports more than 32 characters, no side effects seen. */
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers going beyond 32
characters due to MIP added as per AUTOSAR requirement. Since compiler
supports more than 32 characters, no side effects seen. */
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers going beyond 32
characters due to MIP added as per AUTOSAR requirement. Since compiler
supports more than 32 characters, no side effects seen. */
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers going beyond 32
characters due to MIP added as per AUTOSAR requirement. Since compiler
supports more than 32 characters, no side effects seen. */
#define ETH_17_GETHMACV2_FIFO3_CTRL0_RXBUF_COUNT      (0U)

/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers going beyond 32
characters due to MIP added as per AUTOSAR requirement. Since compiler
supports more than 32 characters, no side effects seen. */
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers going beyond 32
characters due to MIP added as per AUTOSAR requirement. Since compiler
supports more than 32 characters, no side effects seen. */
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers going beyond 32
characters due to MIP added as per AUTOSAR requirement. Since compiler
supports more than 32 characters, no side effects seen. */
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers going beyond 32
characters due to MIP added as per AUTOSAR requirement. Since compiler
supports more than 32 characters, no side effects seen. */
#define ETH_17_GETHMACV2_FIFO3_CTRL0_RXBUF_SIZE       (0U)

/* Number of Receive FIFOs configured */
#define ETH_17_GETHMACV2_CTRL0_RXFIFO_CFGD       (1U)

/* Tx buffer count and size for controller0 FIFO Index0 */
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers going beyond 32
characters due to MIP added as per AUTOSAR requirement. Since compiler
supports more than 32 characters, no side effects seen. */
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers going beyond 32
characters due to MIP added as per AUTOSAR requirement. Since compiler
supports more than 32 characters, no side effects seen. */
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers going beyond 32
characters due to MIP added as per AUTOSAR requirement. Since compiler
supports more than 32 characters, no side effects seen. */
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers going beyond 32
characters due to MIP added as per AUTOSAR requirement. Since compiler
supports more than 32 characters, no side effects seen. */
#define ETH_17_GETHMACV2_FIFO0_CTRL0_TXBUF_COUNT      (4U)

/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers going beyond 32
characters due to MIP added as per AUTOSAR requirement. Since compiler
supports more than 32 characters, no side effects seen. */
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers going beyond 32
characters due to MIP added as per AUTOSAR requirement. Since compiler
supports more than 32 characters, no side effects seen. */
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers going beyond 32
characters due to MIP added as per AUTOSAR requirement. Since compiler
supports more than 32 characters, no side effects seen. */
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers going beyond 32
characters due to MIP added as per AUTOSAR requirement. Since compiler
supports more than 32 characters, no side effects seen. */
#define ETH_17_GETHMACV2_FIFO0_CTRL0_TXBUF_SIZE       (6112U)

/* Tx buffer count and size for controller0 FIFO Index1 */
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers going beyond 32
characters due to MIP added as per AUTOSAR requirement. Since compiler
supports more than 32 characters, no side effects seen. */
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers going beyond 32
characters due to MIP added as per AUTOSAR requirement. Since compiler
supports more than 32 characters, no side effects seen. */
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers going beyond 32
characters due to MIP added as per AUTOSAR requirement. Since compiler
supports more than 32 characters, no side effects seen. */
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers going beyond 32
characters due to MIP added as per AUTOSAR requirement. Since compiler
supports more than 32 characters, no side effects seen. */
#define ETH_17_GETHMACV2_FIFO1_CTRL0_TXBUF_COUNT      (0U)

/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers going beyond 32
characters due to MIP added as per AUTOSAR requirement. Since compiler
supports more than 32 characters, no side effects seen. */
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers going beyond 32
characters due to MIP added as per AUTOSAR requirement. Since compiler
supports more than 32 characters, no side effects seen. */
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers going beyond 32
characters due to MIP added as per AUTOSAR requirement. Since compiler
supports more than 32 characters, no side effects seen. */
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers going beyond 32
characters due to MIP added as per AUTOSAR requirement. Since compiler
supports more than 32 characters, no side effects seen. */
#define ETH_17_GETHMACV2_FIFO1_CTRL0_TXBUF_SIZE       (0U)

/* Tx buffer count and size for controller0 FIFO Index2 */
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers going beyond 32
characters due to MIP added as per AUTOSAR requirement. Since compiler
supports more than 32 characters, no side effects seen. */
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers going beyond 32
characters due to MIP added as per AUTOSAR requirement. Since compiler
supports more than 32 characters, no side effects seen. */
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers going beyond 32
characters due to MIP added as per AUTOSAR requirement. Since compiler
supports more than 32 characters, no side effects seen. */
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers going beyond 32
characters due to MIP added as per AUTOSAR requirement. Since compiler
supports more than 32 characters, no side effects seen. */
#define ETH_17_GETHMACV2_FIFO2_CTRL0_TXBUF_COUNT      (0U)

/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers going beyond 32
characters due to MIP added as per AUTOSAR requirement. Since compiler
supports more than 32 characters, no side effects seen. */
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers going beyond 32
characters due to MIP added as per AUTOSAR requirement. Since compiler
supports more than 32 characters, no side effects seen. */
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers going beyond 32
characters due to MIP added as per AUTOSAR requirement. Since compiler
supports more than 32 characters, no side effects seen. */
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers going beyond 32
characters due to MIP added as per AUTOSAR requirement. Since compiler
supports more than 32 characters, no side effects seen. */
#define ETH_17_GETHMACV2_FIFO2_CTRL0_TXBUF_SIZE       (0U)

/* Tx buffer count and size for controller0 FIFO Index3 */
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers going beyond 32
characters due to MIP added as per AUTOSAR requirement. Since compiler
supports more than 32 characters, no side effects seen. */
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers going beyond 32
characters due to MIP added as per AUTOSAR requirement. Since compiler
supports more than 32 characters, no side effects seen. */
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers going beyond 32
characters due to MIP added as per AUTOSAR requirement. Since compiler
supports more than 32 characters, no side effects seen. */
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers going beyond 32
characters due to MIP added as per AUTOSAR requirement. Since compiler
supports more than 32 characters, no side effects seen. */
#define ETH_17_GETHMACV2_FIFO3_CTRL0_TXBUF_COUNT      (0U)

/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers going beyond 32
characters due to MIP added as per AUTOSAR requirement. Since compiler
supports more than 32 characters, no side effects seen. */
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers going beyond 32
characters due to MIP added as per AUTOSAR requirement. Since compiler
supports more than 32 characters, no side effects seen. */
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers going beyond 32
characters due to MIP added as per AUTOSAR requirement. Since compiler
supports more than 32 characters, no side effects seen. */
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers going beyond 32
characters due to MIP added as per AUTOSAR requirement. Since compiler
supports more than 32 characters, no side effects seen. */
#define ETH_17_GETHMACV2_FIFO3_CTRL0_TXBUF_SIZE       (0U)

/* Number of Transmit FIFOs configured */
#define ETH_17_GETHMACV2_CTRL0_TXFIFO_CFGD       (1U)

/* fSPB (SPB frequency) period in nanoseconds */
#define ETH_17_GETHMACV2_FSPB_PERIOD_IN_NANOSEC   (10U)

/* fGETH frequency in Hz - basic frequency for the Gigabit Ethernet Kernel */
/* Timestamp Addend register value for fine update to get 20 ns
resolution */
#define ETH_17_GETHMACV2_TIMESTAMP_ADDEND_VAL     (1431655765U)

/* Wait time in nanoseconds after a kernel reset in RGMII mode */
#define ETH_17_GETHMACV2_KRNLRST_RGMII_WAITCNT    (350U)

/* Wait time in nanoseconds after a kernel reset in MII/ RMII mode */
#define ETH_17_GETHMACV2_KRNLRST_MII_WAITCNT      (700U)

/* Number of fSPB cycles to wait after a DMA software reset */
#define ETH_17_GETHMACV2_DMA_RESET_WAITCYCLE      (4U)

/*
Configuration: ETH_17_GETHMACV2_GETCNTRVALUES_API
- if STD_ON, Function Eth_17_GEthMacV2_GetCounterValues is available
- if STD_OFF,Function Eth_17_GEthMacV2_GetCounterValues is not available
*/
#define  ETH_17_GETHMACV2_GETCNTRVALUES_API    (STD_OFF)

/*
Configuration: ETH_17_GETHMACV2_GETRXSTATS_API
- if STD_ON, Function Eth_17_GEthMacV2_GetRxStats is available
- if STD_OFF,Function Eth_17_GEthMacV2_GetRxStats is not available
*/
#define  ETH_17_GETHMACV2_GETRXSTATS_API   (STD_OFF)

/*
Configuration: ETH_17_GETHMACV2_GETTXSTATS_API
- if STD_ON, Eth_17_GEthMacV2_GetTxStats() API is available
- if STD_OFF, Eth_17_GEthMacV2_GetTxStats() API is unavailable
*/
#define  ETH_17_GETHMACV2_GETTXSTATS_API   (STD_OFF)

/*
Configuration: ETH_17_GETHMACV2_GETTXERRCNTRVAL_API
- if STD_ON, Eth_17_GEthMacV2_GetTxErrorCounterValues() API is available
- if STD_OFF, Eth_17_GEthMacV2_GetTxErrorCounterValues() API is unavailable
*/
#define  ETH_17_GETHMACV2_GETTXERRCNTRVAL_API   (STD_OFF)

/*
Configuration: ETH_17_GETHMACV2_GLOBALTIMESUPPORT
- if STD_ON, TimeStamp feature is enabled.
- if STD_OFF,TimeStamp feature is disabled.
*/
#define  ETH_17_GETHMACV2_GLOBALTIMESUPPORT   (STD_OFF)

/*
Configuration: ETH_17_GETHMACV2_MULTICORE_ERROR_DETECT :
Adds/removes the Multi-core error detection and reporting
from the code
- if STD_ON, Multi-core error detection and reporting is enabled
- if STD_OFF, Multi-core error detection and reporting is disabled
*/
#define ETH_17_GETHMACV2_MULTICORE_ERROR_DETECT           (STD_OFF)

/*
Configuration: ETH_17_GETHMACV2_ICMP_CHECKSUMOFFLOAD_ENABLE
- if STD_ON, Hardware offloading for ICMP checksums is enabled.
- if STD_OFF,Hardware offloading for ICMP checksums is disabled.
*/
#define ETH_17_GETHMACV2_ICMP_CHECKSUMOFFLOAD_ENABLE  (STD_OFF)

/*
Configuration: ETH_17_GETHMACV2_IPV4_CHECKSUMOFFLOAD_ENABLE
- if STD_ON, Hardware offloading for IPV4 checksums is enabled.
- if STD_OFF,Hardware offloading for IPV4 checksums is disabled.
*/
#define ETH_17_GETHMACV2_IPV4_CHECKSUMOFFLOAD_ENABLE  (STD_OFF)

/*
Configuration: ETH_17_GETHMACV2_TCP_CHECKSUMOFFLOAD_ENABLE
- if STD_ON, Hardware offloading for TCP checksums is enabled.
- if STD_OFF,Hardware offloading for TCP checksums is disabled.
*/
#define ETH_17_GETHMACV2_TCP_CHECKSUMOFFLOAD_ENABLE   (STD_OFF)

/*
Configuration: ETH_17_GETHMACV2_UDP_CHECKSUMOFFLOAD_ENABLE
- if STD_ON, Hardware offloading for UDP checksums is enabled.
- if STD_OFF,Hardware offloading for UDP checksums is disabled.
*/
#define ETH_17_GETHMACV2_UDP_CHECKSUMOFFLOAD_ENABLE   (STD_OFF)

/*
Configuration: ETH_17_GETHMACV2_INIT_API_MODE
- if ETH_17_GETHMACV2_MCAL_SUPERVISOR - Init API is executed in supervisor mode.
- if ETH_17_GETHMACV2_MCAL_USER1 - Init API is executed in user1 mode.
*/
#define ETH_17_GETHMACV2_INIT_API_MODE         (ETH_17_GETHMACV2_MCAL_SUPERVISOR)

/*
Configuration: ETH_17_GETHMACV2_RUNTIME_API_MODE
- if ETH_17_GETHMACV2_MCAL_SUPERVISOR - Runtime APIs are executed in supervisor mode.
- if ETH_17_GETHMACV2_MCAL_USER1 - Runtime APIs are executed in user1 mode.
*/
#define ETH_17_GETHMACV2_RUNTIME_API_MODE      (ETH_17_GETHMACV2_MCAL_SUPERVISOR)

/* Controller0 is configured to CORE0 */
#define ETH_17_GETHMACV2_CTRL0_CORE0  (STD_ON)

/* Controller0 is configured in this project */
#define ETH_17_GETHMACV2_CTRL0_CONFIGURED         (STD_ON)

/* Maximum Controllers allocated to CORE0
Value = 255- represents core is not available in current device */
#define ETH_17_GETHMACV2_MAX_CTRL_CORE0               (1U)

/* Maximum Controllers allocated to CORE1
Value = 255- represents core is not available in current device */
#define ETH_17_GETHMACV2_MAX_CTRL_CORE1               (0U)

/* Maximum Controllers allocated to CORE2
Value = 255- represents core is not available in current device */
#define ETH_17_GETHMACV2_MAX_CTRL_CORE2               (0U)

/* Maximum Controllers allocated to CORE3
Value = 255- represents core is not available in current device */
#define ETH_17_GETHMACV2_MAX_CTRL_CORE3               (0U)

/* Maximum Controllers allocated to CORE4
Value = 255- represents core is not available in current device */
#define ETH_17_GETHMACV2_MAX_CTRL_CORE4               (0U)

/* Maximum Controllers allocated to CORE5
Value = 255- represents core is not available in current device */
#define ETH_17_GETHMACV2_MAX_CTRL_CORE5               (0U)

/* Maximum available cores in this device */
#define ETH_17_GETHMACV2_MAX_CORES                     (6U)

/* Maximum controllers available in this device */
#define ETH_17_GETHMACV2_MAX_CONTROLLERS               (1U)

/*******************************************************************************
**                      Global Type Definitions                               **
*******************************************************************************/

/*******************************************************************************
**                      Global Constant Declarations                          **
*******************************************************************************/

/*******************************************************************************
**                      Global Variable Declarations                          **
*******************************************************************************/

/*******************************************************************************
**                      Global Inline Function Definitions                    **
*******************************************************************************/

#endif  /* ETH_17_GETHMACV2_CFG_H */


