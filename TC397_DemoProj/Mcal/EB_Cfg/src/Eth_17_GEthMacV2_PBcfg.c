
/******************************************************************************
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
**  FILENAME  : Eth_17_GEthMacV2_PBCfg.c                                      **
**                                                                            **
**  VERSION   : 6.0.0                                                         **
**                                                                            **
**  DATE, TIME: 2024-03-12, 18:16:53     !!!IGNORE-LINE!!!                    **
**                                                                            **
**  GENERATOR : Build b191017-0938       !!!IGNORE-LINE!!!                    **
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
/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
/* Include ETH Module File */
#include "Eth_17_GEthMacV2.h"
/*******************************************************************************
**                      Private Macro Definitions                             **
*******************************************************************************/

/*******************************************************************************
**                      Imported Compiler Switch Check                        **
*******************************************************************************/

/*******************************************************************************
**                      Private Type Definitions                              **
*******************************************************************************/

/*******************************************************************************
**                      Private Function Declarations                         **
*******************************************************************************/

/*******************************************************************************
**                      Global Constant Definitions                           **
*******************************************************************************/

/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
#define ETH_17_GETHMACV2_START_SEC_CONFIG_DATA_QM_GLOBAL_UNSPECIFIED
/* MISRA2012_RULE_4_10_JUSTIFICATION: Memmap header is repeatedly included
without safeguard. It complies to Autosar guidelines. */
/* MISRA2012_RULE_20_1_JUSTIFICATION: Declaration of notification function
before MemMap inclusion It complies to Autosar guidelines. */
#include "Eth_17_GEthMacV2_MemMap.h"
/*Array to store index of the controller in the allocated core.*/
static const uint8 Eth_17_GEthMacV2_ControllerIndexMap [1] =
{
  0x0U,
};

/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
#define ETH_17_GETHMACV2_STOP_SEC_CONFIG_DATA_QM_GLOBAL_UNSPECIFIED
/* MISRA2012_RULE_4_10_JUSTIFICATION: Memmap header is repeatedly included
without safeguard. It complies to Autosar guidelines. */
/* MISRA2012_RULE_20_1_JUSTIFICATION: Declaration of notification function
before MemMap inclusion It complies to Autosar guidelines. */
#include "Eth_17_GEthMacV2_MemMap.h"

/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
#define ETH_17_GETHMACV2_START_SEC_CONFIG_DATA_QM_CORE0_UNSPECIFIED
/* MISRA2012_RULE_4_10_JUSTIFICATION: Memmap header is repeatedly included
without safeguard. It complies to Autosar guidelines. */
/* MISRA2012_RULE_20_1_JUSTIFICATION: Declaration of notification function
before MemMap inclusion It complies to Autosar guidelines. */
#include "Eth_17_GEthMacV2_MemMap.h"

/* Priority to FIFO index mapping */
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
static const uint8 Eth_17_GEthMacV2_TxPrioFifoMapCtrl0[8] =
{
  0x0U,
  0x0U,
  0x0U,
  0x0U,
  0x0U,
  0x0U,
  0x0U,
  0x0U
};

/* Fifo to Egress Queue Mapping */
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
static const uint8 Eth_17_GEthMacV2_TxFifoChnlMapCtrl0[1] =
{
  0U
};

/* Channel to Egress FIFO Mapping */
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
static const uint8 Eth_17_GEthMacV2_TxChnlFifoMapCtrl0[4] =
{
  0U,
  255U,
  255U,
  255U
};

/* Egress FIFO configuration */
static const Eth_17_GEthMacV2_TxFifoCfgType Eth_17_GEthMacV2_TxFifoCfgCtrl0[1] =
{
  {
    /* HiCredit Value */
    (uint32)0x0U,
    /* LoCredit Value */
    (uint32)0x0U,
    /* Egress Fifo buffer total */
    (uint16)4U,
    /* Egress Fifo length byte */
    (uint16)1522U,
    /* Egress Fifo length byte aligned */
    (uint16)1528U,
    /* Idle Slope Credit Value or
    Configured weight for WRR algorithm */
    (uint16)0x0U,
    /* Send Slope Credit Value */
    (uint16)0x0U,
    /* Egress Fifo Index*/
    (uint8)0U,
    /* DMA Channel Weight */
    (uint8)0U,
    /* Egress Queue Mode */
    (uint8)0x2U,
    /* Egress Queue Size */
    (uint8)0xdU
  }
};

/* Channel to Ingress FIFO Mapping */
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
static const uint8 Eth_17_GEthMacV2_RxChnlFifoMapCtrl0[4] =
{
  0U,
  255U,
  255U,
  255U
};

/* Fifo Ingress to Queue Mapping */
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
static const uint8 Eth_17_GEthMacV2_RxFifoChnlMapCtrl0 [1] =
{
  0U
};

/* Ingress FIFO configuration */
static const Eth_17_GEthMacV2_RxFifoCfgType Eth_17_GEthMacV2_RxFifoCfgCtrl0[1] =
{
  {
    /*Ingress Fifo buffer total */
    (uint16)4U,
    /* Ingress Fifo length byte */
    (uint16)1522U,
    /* Ingress Fifo length byte aligned */
    (uint16)1528U,
    /* Ingress Fifo Index*/
    (uint8)0U,
    /* Priority Configured for FIFO
    (the set bits are the configured priorities) */
    (uint8)0xffU,
    /* Ingress queue size */
    (uint8)31U
  }
};

/*  Structure to store controller configuration data for Core0 */
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
static const Eth_17_GEthMacV2_CoreCtrlConfigType Eth_17_GEthMacV2_CoreCtrlCfgCore0[1]=
{
  {
    /*Specifies the Tx[0:3]/Rx[4:7] clock delay in RGMII mode for transmit
    skew timing*/
    (uint32)106,
    /* Element to store GETH_GPCTL register value for current controller */
    (uint32)2,
    /* Recommended time(in ns) to wait for back to back register write */
    (uint32)240,
    /* Address of Egress fifo Configuration */
    Eth_17_GEthMacV2_TxFifoCfgCtrl0,
    /* Address of Egress Queue Mapping */
    Eth_17_GEthMacV2_TxFifoChnlMapCtrl0,
    /* Channel to Egress FIFO Map */
    Eth_17_GEthMacV2_TxChnlFifoMapCtrl0,
    /* Address of fifo Priority Mapping */
    Eth_17_GEthMacV2_TxPrioFifoMapCtrl0,
    /* Address of Ingress fifo Configuration */
    Eth_17_GEthMacV2_RxFifoCfgCtrl0,
    /* Address of Ingress Queue Mapping */
    Eth_17_GEthMacV2_RxFifoChnlMapCtrl0,
    /* Channel to Ingress FIFO Map */
    Eth_17_GEthMacV2_RxChnlFifoMapCtrl0,
    /* Properties of Ethernet Controller
    Bit[0] - Port Select(PS)
    0 for 1000Mbps
    1 for 10 or 100 Mbps
    Bit[1] - Speed(FES)
    0 for 10 Mbps when PS bit is 1 and 1 Gbps when PS bit is 0
    1 for 100 Mbps when PS bit is 1
    Bit[2:4] - PhyInterface (000-MII, 100-RMII,001-RGMII)
    Bit[5] - Mode of the Controller [0 - HALFDUPLEX, 1- FULLDUPLEX]
    Bit[6] - Tx Interrupt Enable/Disable [0 - Disabled, 1- Enabled]
    Bit[7] - Rx Interrupt Enable/Disable [0 - Disabled, 1- Enabled]
    Bit[8] - CRC Stripping Enable/Disable [0 - Disabled, 1- Enabled]
    */
    (uint16)231,
    /*DEM Id for Ethernet controller hardware test failure*/
    ETH_17_GETHMACV2_DISABLE_DEM_REPORT,
    /*DEM Id for Ethernet controller Frames Lost Error*/
    ETH_17_GETHMACV2_DISABLE_DEM_REPORT,
    /*DEM Id for Ethernet controller Frames Alignment Error*/
    ETH_17_GETHMACV2_DISABLE_DEM_REPORT,
    /*DEM Id for Ethernet controller Frames CRC Error*/
    ETH_17_GETHMACV2_DISABLE_DEM_REPORT,
    /*DEM Id for Ethernet controller  Undersize frame Error*/
    ETH_17_GETHMACV2_DISABLE_DEM_REPORT,
    /*DEM Id for Ethernet controller  Oversize frame Error*/
    ETH_17_GETHMACV2_DISABLE_DEM_REPORT,
    /*DEM Id for Ethernet controller Single collision Error*/
    ETH_17_GETHMACV2_DISABLE_DEM_REPORT,
    /*DEM Id for Ethernet controller Multiple collision Error*/
    ETH_17_GETHMACV2_DISABLE_DEM_REPORT,
    /*DEM Id for Ethernet controller Late collision Error*/
    ETH_17_GETHMACV2_DISABLE_DEM_REPORT,
    /* MAC address of the controller in network byte order */
    {
      (uint8)0x00U,
      (uint8)0x03U,
      (uint8)0x19U,
      (uint8)0x00U,
      (uint8)0x00U,
      (uint8)0x01U
    },
    /* Eth Controller Index */
    (uint8)0U,
    /* Total Egress Queue */
    (uint8)1U,
    /* DMA transmit arbitration algorithm */
    (uint8)0U,
    /* MTL transmit scheduling algorithm */
    (uint8)3U,
    /* Total Ingress Queue */
    (uint8)1U,
    /* Queue where the untagged Rx frames are routed */
    (uint8)0U,
    /* Clock configuration for MDC */
    (uint8)0x0U
  },
};

/* Structure to store core0 configuration data */
static const Eth_17_GEthMacV2_CoreConfigType Eth_17_GEthMacV2_ConfigCore0 =
{
  /* Starting address of the controller configuration for core0 */
  /* MISRA2012_RULE_11_8_JUSTIFICATION: No side effects foreseen
  * by violating this MISRA rule */
  /* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers going beyond 32 chars.
  in generated code due to Autosar Naming constraints.*/
  /* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers going beyond 32 chars.
  in generated code due to Autosar Naming constraints.*/
  /* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers going beyond 32 chars.
  in generated code due to Autosar Naming constraints.*/
  /* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers going beyond 32 chars.
  in generated code due to Autosar Naming constraints.*/
  (Eth_17_GEthMacV2_CoreCtrlConfigType*)Eth_17_GEthMacV2_CoreCtrlCfgCore0,
  1U /* Maximum controllers allocated to core0 */
};

/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
#define ETH_17_GETHMACV2_STOP_SEC_CONFIG_DATA_QM_CORE0_UNSPECIFIED
/* MISRA2012_RULE_4_10_JUSTIFICATION: Memmap header is repeatedly included
without safeguard. It complies to Autosar guidelines. */
/* MISRA2012_RULE_20_1_JUSTIFICATION: Declaration of notification function
before MemMap inclusion It complies to Autosar guidelines. */
#include "Eth_17_GEthMacV2_MemMap.h"


/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
#define ETH_17_GETHMACV2_START_SEC_CONFIG_DATA_QM_GLOBAL_UNSPECIFIED
/* MISRA2012_RULE_4_10_JUSTIFICATION: Memmap header is repeatedly included
without safeguard. It complies to Autosar guidelines. */
/* MISRA2012_RULE_20_1_JUSTIFICATION: Memmap header usage as per Autosar
guideline. */
#include "Eth_17_GEthMacV2_MemMap.h"
const Eth_17_GEthMacV2_ConfigType Eth_17_GEthMacV2_Config =
{
  /* starting address of Core<x> Configuration data */
  {
    /* MISRA2012_RULE_11_8_JUSTIFICATION: No side effects foreseen
    * by violating this MISRA rule */
    (Eth_17_GEthMacV2_CoreConfigType*)&Eth_17_GEthMacV2_ConfigCore0,
    /* MISRA2012_RULE_11_8_JUSTIFICATION: No side effects foreseen
    * by violating this MISRA rule */
    NULL_PTR,
    NULL_PTR,
    NULL_PTR,
    NULL_PTR,
    NULL_PTR
  },
  /* Address of index mapping array */
  (uint8*)Eth_17_GEthMacV2_ControllerIndexMap
  /* MISRA2012_RULE_11_8_JUSTIFICATION: No side effects foreseen
  * by violating this MISRA rule */
};

/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
#define ETH_17_GETHMACV2_STOP_SEC_CONFIG_DATA_QM_GLOBAL_UNSPECIFIED
/* MISRA2012_RULE_4_10_JUSTIFICATION: Memmap header is repeatedly included
without safeguard. It complies to Autosar guidelines. */
/* MISRA2012_RULE_20_1_JUSTIFICATION: Memmap header usage as per Autosar
guideline. */
#include "Eth_17_GEthMacV2_MemMap.h"
