
/*******************************************************************************
**                                                                            **
** Copyright (C) Infineon Technologies (2022)                                 **
**                                                                            **
** All rights reserved.                                                       **
**                                                                            **
** This document contains proprietary information belonging to Infineon       **
** Technologies. Passing on and copying of this document, and communication   **
** of its contents is not permitted without prior written authorization.      **
**                                                                            **
********************************************************************************
**                                                                            **
**  FILENAME  : Can_17_McmCan_PBCfg.c                                         **
**                                                                            **
**  VERSION   : 32.0.0                                                        **
**                                                                            **
**  DATE, TIME: 2024-04-30, 14:07:28          !!!IGNORE-LINE!!!               **
**                                                                            **
**  GENERATOR : Build b191017-0938            !!!IGNORE-LINE!!!               **
**                                                                            **
**  BSW MODULE DECRIPTION : Can_17_McmCan.bmd                                 **
**                                                                            **
**  VARIANT   : Variant PB                                                    **
**                                                                            **
**  PLATFORM  : Infineon AURIX2G                                              **
**                                                                            **
**  AUTHOR    : DL-AUTOSAR-Engineering                                        **
**                                                                            **
**  VENDOR    : Infineon Technologies                                         **
**                                                                            **
**  DESCRIPTION  : Can configuration generated out of ECUC file               **
**                                                                            **
**  SPECIFICATION(S) : Specification of Can Driver, AUTOSAR Release 4.2.2 and **
**                     4.4.0                                                  **
**                                                                            **
**  MAY BE CHANGED BY USER : no                                               **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
/* [cover parentID={BDE616FE-5D39-4b9d-9390-8351CC6C490C}]
[/cover] */
/* Include CAN Driver Header File */
#include "Can_17_McmCan.h"

/*******************************************************************************
**                      Private Macro Definitions                             **
*******************************************************************************/
/*******************************************************************************
**                      Global Function Definitions                           **
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


/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers going beyond 32 chars
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers going beyond 32 chars
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers going beyond 32 chars
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers going beyond 32 chars
in generated code due to Autosar Naming constraints.*/
#define CAN_17_MCMCAN_START_SEC_CONFIG_DATA_QM_CORE0_UNSPECIFIED
/* MISRA2012_RULE_20_1_JUSTIFICATION: Memmap header usage as per Autosar
   guideline. */
/* MISRA2012_RULE_4_10_JUSTIFICATION: Memmap header is repeatedly included
   without safegaurd. It complies to Autosar guidelines. */
#include "Can_17_McmCan_MemMap.h"

/*******************************************************************************
               Can Controller Configurations for Core0
********************************************************************************
    { Can node Base Address,Combination value of Rx pin select and
    Loopback mode Support,{First Tx Hardware Object, No.of Tx Hardware Objects,
    First Rx Standard Hardware Object, No.of Rx Standard Hardware Objects,
    First Rx Extended Hardware Object, No.of Rx Extended Hardware Objects},
    Default baudrate Config index,First baudrate index for the controller,
    No.of baudrate configuration,Associated kernel Id, Controller Hw Id,
    Logical controller Id,[FD support status] }
********************************************************************************
       Note: [1] The configuration shall be generated only for the activated
                 controller
             [2] The Generation of FD support status Shall be enabled only if
             atleast one of the baudrates configured in the configuration set is
             FD.
*******************************************************************************/
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers going beyond 32 chars.
  in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers going beyond 32 chars.
  in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers going beyond 32 chars.
  in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers going beyond 32 chars.
  in generated code due to Autosar Naming constraints.*/
static const Can_17_McmCan_ControllerConfigType \
  Can_17_McmCan_kControllerConfigCore0[2] =
{
  {
    /* Can controller Base Node address */
    /* MISRA2012_RULE_11_6_JUSTIFICATION: The pointer cast is used to
    cast the generated address with CAN Node structure type */
    /* MISRA2012_RULE_11_4_JUSTIFICATION: conversion between pointer and
    integer type. Permitted for special function registers.*/
    (volatile Ifx_CAN_N*)0xf0228100U,
    /* combination of Loopback and receive input pin selection setting */
    0x2U,
    /* The controller Hw object configuration mapping information */
    {
      /* Tx Message storage start Index */
      0x0U,
      /* Total no of Tx Message configured */
      0x20U,
      /* Rx Message SID filter mask start Index */
      0x0U,
      /* Total no of SID filter mask configured */
      0x20U,
      /* Rx Message XID filter mask start Index */
      0x0U,
      /* Total no of XID filter mask configured */
      0x0U
    },
    /* Default baudrate configuration Index */
    0x0U,
    /* Start index value of Baudrate configuration */
    0x0U,
    /* Total no of Baudrate configuration */
    0x1U,
    /* The controller Associated Kernel configuration Index */
    0x2U,
    /* The CAN controller Hw Index */
    0x00U,
    /* The CAN controller Logical Hw Index - Controller ID defined by user */
    0,
    /* FD support status of the controller */
    FALSE,
    /* RxFIFO0 Processing configuration */
    CAN_17_MCMCAN_RX_FIFO_NOT_CONFIGURED,
    /* RxFIFO1 Processing configuration */
    CAN_17_MCMCAN_RX_FIFO_NOT_CONFIGURED,
    /* Hrh polling mask for NDAT1 */
    0x0U,
    /* Hrh polling mask for NDAT2 */
    0x0U,
    /* Hth polling mask for the controller */
    0x0U,
    /* Interrupt mask for the controller */
    0x2081000U,
  },
  {
    /* Can controller Base Node address */
    /* MISRA2012_RULE_11_6_JUSTIFICATION: The pointer cast is used to
    cast the generated address with CAN Node structure type */
    /* MISRA2012_RULE_11_4_JUSTIFICATION: conversion between pointer and
    integer type. Permitted for special function registers.*/
    (volatile Ifx_CAN_N*)0xf0228500U,
    /* combination of Loopback and receive input pin selection setting */
    0x0U,
    /* The controller Hw object configuration mapping information */
    {
      /* Tx Message storage start Index */
      0x20U,
      /* Total no of Tx Message configured */
      0x1U,
      /* Rx Message SID filter mask start Index */
      0x20U,
      /* Total no of SID filter mask configured */
      0x13U,
      /* Rx Message XID filter mask start Index */
      0x0U,
      /* Total no of XID filter mask configured */
      0x0U
    },
    /* Default baudrate configuration Index */
    0x1U,
    /* Start index value of Baudrate configuration */
    0x1U,
    /* Total no of Baudrate configuration */
    0x1U,
    /* The controller Associated Kernel configuration Index */
    0x2U,
    /* The CAN controller Hw Index */
    0x01U,
    /* The CAN controller Logical Hw Index - Controller ID defined by user */
    1,
    /* FD support status of the controller */
    TRUE,
    /* RxFIFO0 Processing configuration */
    CAN_17_MCMCAN_RX_FIFO_NOT_CONFIGURED,
    /* RxFIFO1 Processing configuration */
    CAN_17_MCMCAN_RX_FIFO_NOT_CONFIGURED,
    /* Hrh polling mask for NDAT1 */
    0x0U,
    /* Hrh polling mask for NDAT2 */
    0x0U,
    /* Hth polling mask for the controller */
    0x0U,
    /* Interrupt mask for the controller */
    0x2081000U,
  }
};

/*******************************************************************************
              Controller Id to Index Map configuration for Core0
********************************************************************************
    {Array holding the respective logical Controller ID at the core specific
    controller index }
********************************************************************************
           Note: This shall be generated only for the controllers allocated
           for the current core.
*******************************************************************************/
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers going beyond 32 chars.
  in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers going beyond 32 chars.
  in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers going beyond 32 chars.
  in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers going beyond 32 chars.
  in generated code due to Autosar Naming constraints.*/
static const Can_17_McmCan_ControllerIndexType \
  Can_17_McmCan_kControllerIndexingCore0[2] =
{0,1};

/*******************************************************************************
              Message RAM partition configuration for Core0
********************************************************************************
      {{start address of SID section,start address of XID section,
      start address of FIFO0 section,start address of FIFO1 section,start
      address of Rx dedicated buffer section,start address of Tx Event section,
      start address of Tx dedicated buffer section},Tx_ded_Buff size,
      Tx_Evnt size,[Rx_FIFO0 size],[Rx_FIFO0 Threshold],[Rx_FIFO1 size],
      [Rx_FIFO1 Threshold],[Tx_Queue size],[Tx_Queue Enable Status]}
********************************************************************************
           Note: This shall be generated only for the activated controller
*******************************************************************************/
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers going beyond 32 chars.
  in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers going beyond 32 chars.
  in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers going beyond 32 chars.
  in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers going beyond 32 chars.
  in generated code due to Autosar Naming constraints.*/
static const Can_17_McmCan_ControllerMsgRAMConfigType \
  Can_17_McmCan_kControllerMsgRAMMapConfigCore0[2] =
{
  {
    /* Start Address of each section within the Message RAM */
    {
      0xf0220000UL,
      0x00000000UL,
      0x00000000UL,
      0x00000000UL,
      0xf0220080UL,
      0xf0220280UL,
      0xf0220380UL
    },
    0x20U,
    0x20U,
    0x0U,
    0x0U,
    0x0U,
    0x0U},
  {
    /* Start Address of each section within the Message RAM */
    {
      0xf0220580UL,
      0x00000000UL,
      0x00000000UL,
      0x00000000UL,
      0xf02205ccUL,
      0xf0220b24UL,
      0xf0220b2cUL
    },
    0x1U,
    0x1U,
    0x0U,
    0x0U,
    0x0U,
    0x0U}
};

/*******************************************************************************
            CAN Controller Baudrate Configurations for Core0
********************************************************************************
           { CANx_NBTP value, Configured Baudrate ,FDBaudrate config Index ,
             FD Support Status  }
********************************************************************************
                           Baudrate Setting
    (uint32)((NSJW << 25)|(NBRP << 16)|(TSEG1 << 8)|(TSEG2))
    NSJW   -> CanControllerSyncJumpWidth - 1
    NTSEG1 -> CanControllerPropSeg + CanControllerSeg1 - 1
    NTSEG2 -> CanControllerSeg2 - 1
*******************************************************************************/
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
static const Can_17_McmCan_ControllerBaudrateConfigType \
  Can_17_McmCan_kBaudrateConfigCore0[2] =
{
  {
    /* Configured Baudrate -> 500.0 kbps */
    /* Actual Baudrate     -> 500.0 kbps */
    /* NBRP   -> 0 */
    /* NSJW   -> 3  */
    /* NTSEG1 -> 23  */
    /* NTSEG2 -> 14  */
    0x600170eU,
    500U,
    0x0U,
    FALSE
  },
  {
    /* Configured Baudrate -> 500.0 kbps */
    /* Actual Baudrate     -> 500.0 kbps */
    /* NBRP   -> 0 */
    /* NSJW   -> 3  */
    /* NTSEG1 -> 23  */
    /* NTSEG2 -> 14  */
    0x600170eU,
    500U,
    0x0U,
    TRUE
  }
};

/*******************************************************************************
                CAN Controller FD Config Parameters for Core0
********************************************************************************
           { CANx_DBTP value, TrcvDelayCompensationOffset, BRS Status }
********************************************************************************

        (uint32)((DBRP << 16)|(DTSEG1 << 8)|(DTSEG2 << 4)|(DSJW ))
        DSJW   -> CanControllerSyncJumpWidth - 1
        DTSEG1 -> CanControllerPropSeg + CanControllerSeg1 - 1
        DTSEG2 -> CanControllerSeg2 - 1
*******************************************************************************/
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
static const Can_17_McmCan_ControllerFDBaudrateConfigType \
  Can_17_McmCan_kFDBaudrateConfigCore0[1] =
{
  {
    /* Configured FD Baudrate -> 2000.0 kbps */
    /* Actual Baudrate     -> 2000.0 kbps */
    /* DBRP   -> 0 */
    /* DSJW   -> 0  */
    /* DTSEG1 -> 4  */
    /* DTSEG2 -> 3  */
    0x430U,
    0x0U,
    TRUE
  }
};

/*******************************************************************************
    CAN Controller Handling of Events for Core0 : Interrupt/Polling
********************************************************************************
        { CanTxProcessing Mode, CanRxProcessing Mode,
          CanBusoffProcessing Mode, CanWakeupProcessing Mode }
********************************************************************************
           Note: If the CAN controller is not activated then,
                 { 0U, 0U, 0U, 0U } will be generated
*******************************************************************************/
/* CanConfigSet -> CAN Controller - Handling of Events */
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
static const Can_17_McmCan_EventHandlingType \
  Can_17_McmCan_kEventHandlingConfigCore0[2] =
{
  {
      CAN_17_MCMCAN_INTERRUPT,
      CAN_17_MCMCAN_INTERRUPT,
      CAN_17_MCMCAN_INTERRUPT,
      CAN_17_MCMCAN_INTERRUPT
  },
  {
      CAN_17_MCMCAN_INTERRUPT,
      CAN_17_MCMCAN_INTERRUPT,
      CAN_17_MCMCAN_INTERRUPT,
      CAN_17_MCMCAN_INTERRUPT
  }
};
/*******************************************************************************
               Receive Hardware Object Configurations for Core0
********************************************************************************
        This is the combination of SID filter elements
        Rx Object -> { Combination of Mask and filter value S0, HRH HwObject Id,
        Hw Controller Id, Rx BufferType, [Pretended Support Status] }
********************************************************************************
       Note: [1] If the associated CAN Controller is not activated then,
                   Hw Controller Id -> 255
             [2] If CanFilterMaskRef is not configured then,
                   Mask -> 0x7ff - for STANDARD Msg Id Type
*******************************************************************************/
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
static const Can_17_McmCan_SIDFilterConfigType \
  Can_17_McmCan_kSIDFilterConfigCore0[51] =
{
  {
    0xbe000000U,
    0U,
    0U,
    CAN_17_MCMCAN_RX_DED_BUFFER
  },
  {
    0xb8800001U,
    1U,
    0U,
    CAN_17_MCMCAN_RX_DED_BUFFER
  },
  {
    0xb9060002U,
    2U,
    0U,
    CAN_17_MCMCAN_RX_DED_BUFFER
  },
  {
    0xb9090003U,
    3U,
    0U,
    CAN_17_MCMCAN_RX_DED_BUFFER
  },
  {
    0xb9220004U,
    4U,
    0U,
    CAN_17_MCMCAN_RX_DED_BUFFER
  },
  {
    0xb9230005U,
    5U,
    0U,
    CAN_17_MCMCAN_RX_DED_BUFFER
  },
  {
    0xb9240006U,
    6U,
    0U,
    CAN_17_MCMCAN_RX_DED_BUFFER
  },
  {
    0xb9250007U,
    7U,
    0U,
    CAN_17_MCMCAN_RX_DED_BUFFER
  },
  {
    0xb9320008U,
    8U,
    0U,
    CAN_17_MCMCAN_RX_DED_BUFFER
  },
  {
    0xb9620009U,
    9U,
    0U,
    CAN_17_MCMCAN_RX_DED_BUFFER
  },
  {
    0xb967000aU,
    10U,
    0U,
    CAN_17_MCMCAN_RX_DED_BUFFER
  },
  {
    0xb97e000bU,
    11U,
    0U,
    CAN_17_MCMCAN_RX_DED_BUFFER
  },
  {
    0xb97f000cU,
    12U,
    0U,
    CAN_17_MCMCAN_RX_DED_BUFFER
  },
  {
    0xb9e2000dU,
    13U,
    0U,
    CAN_17_MCMCAN_RX_DED_BUFFER
  },
  {
    0xb9f0000eU,
    14U,
    0U,
    CAN_17_MCMCAN_RX_DED_BUFFER
  },
  {
    0xb9f1000fU,
    15U,
    0U,
    CAN_17_MCMCAN_RX_DED_BUFFER
  },
  {
    0xb9f20010U,
    16U,
    0U,
    CAN_17_MCMCAN_RX_DED_BUFFER
  },
  {
    0xba020011U,
    17U,
    0U,
    CAN_17_MCMCAN_RX_DED_BUFFER
  },
  {
    0xba300012U,
    18U,
    0U,
    CAN_17_MCMCAN_RX_DED_BUFFER
  },
  {
    0xba690013U,
    19U,
    0U,
    CAN_17_MCMCAN_RX_DED_BUFFER
  },
  {
    0xba700014U,
    20U,
    0U,
    CAN_17_MCMCAN_RX_DED_BUFFER
  },
  {
    0xba9e0015U,
    21U,
    0U,
    CAN_17_MCMCAN_RX_DED_BUFFER
  },
  {
    0xbaa40016U,
    22U,
    0U,
    CAN_17_MCMCAN_RX_DED_BUFFER
  },
  {
    0xbb2b0017U,
    23U,
    0U,
    CAN_17_MCMCAN_RX_DED_BUFFER
  },
  {
    0xbbe20018U,
    24U,
    0U,
    CAN_17_MCMCAN_RX_DED_BUFFER
  },
  {
    0xbbf10019U,
    25U,
    0U,
    CAN_17_MCMCAN_RX_DED_BUFFER
  },
  {
    0xbbf7001aU,
    26U,
    0U,
    CAN_17_MCMCAN_RX_DED_BUFFER
  },
  {
    0xbc20001bU,
    27U,
    0U,
    CAN_17_MCMCAN_RX_DED_BUFFER
  },
  {
    0xbc2b001cU,
    28U,
    0U,
    CAN_17_MCMCAN_RX_DED_BUFFER
  },
  {
    0xbcd4001dU,
    29U,
    0U,
    CAN_17_MCMCAN_RX_DED_BUFFER
  },
  {
    0xbfb1001eU,
    30U,
    0U,
    CAN_17_MCMCAN_RX_DED_BUFFER
  },
  {
    0xbfdf001fU,
    31U,
    0U,
    CAN_17_MCMCAN_RX_DED_BUFFER
  },
  {
    0xb8300000U,
    32U,
    1U,
    CAN_17_MCMCAN_RX_DED_BUFFER
  },
  {
    0xb8520001U,
    33U,
    1U,
    CAN_17_MCMCAN_RX_DED_BUFFER
  },
  {
    0xba000002U,
    34U,
    1U,
    CAN_17_MCMCAN_RX_DED_BUFFER
  },
  {
    0xba010003U,
    35U,
    1U,
    CAN_17_MCMCAN_RX_DED_BUFFER
  },
  {
    0xba020004U,
    36U,
    1U,
    CAN_17_MCMCAN_RX_DED_BUFFER
  },
  {
    0xba030005U,
    37U,
    1U,
    CAN_17_MCMCAN_RX_DED_BUFFER
  },
  {
    0xba040006U,
    38U,
    1U,
    CAN_17_MCMCAN_RX_DED_BUFFER
  },
  {
    0xba050007U,
    39U,
    1U,
    CAN_17_MCMCAN_RX_DED_BUFFER
  },
  {
    0xba060008U,
    40U,
    1U,
    CAN_17_MCMCAN_RX_DED_BUFFER
  },
  {
    0xba070009U,
    41U,
    1U,
    CAN_17_MCMCAN_RX_DED_BUFFER
  },
  {
    0xba08000aU,
    42U,
    1U,
    CAN_17_MCMCAN_RX_DED_BUFFER
  },
  {
    0xba09000bU,
    43U,
    1U,
    CAN_17_MCMCAN_RX_DED_BUFFER
  },
  {
    0xba0a000cU,
    44U,
    1U,
    CAN_17_MCMCAN_RX_DED_BUFFER
  },
  {
    0xba0b000dU,
    45U,
    1U,
    CAN_17_MCMCAN_RX_DED_BUFFER
  },
  {
    0xba0c000eU,
    46U,
    1U,
    CAN_17_MCMCAN_RX_DED_BUFFER
  },
  {
    0xba0d000fU,
    47U,
    1U,
    CAN_17_MCMCAN_RX_DED_BUFFER
  },
  {
    0xba0e0010U,
    48U,
    1U,
    CAN_17_MCMCAN_RX_DED_BUFFER
  },
  {
    0xba0f0011U,
    49U,
    1U,
    CAN_17_MCMCAN_RX_DED_BUFFER
  },
  {
    0xba100012U,
    50U,
    1U,
    CAN_17_MCMCAN_RX_DED_BUFFER
  }
};
/*******************************************************************************
           Transmit Hardware Object Configurations for Core0
********************************************************************************
 Tx Object -> { CanTxHwObjId, CanTxBuffIndx, HwControllerId, [CanFdPaddValue],
               CanTxHwObjIdType , CanTxBufferType, CanTrigTxStatus}
********************************************************************************
       Note: [1] If the associated CAN Controller is not activated then,
                   this shall not be generated.
*******************************************************************************/
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
static const Can_17_McmCan_TxHwObjectConfigType \
  Can_17_McmCan_kTxHwObjectConfigCore0[33] =
{
  {
    51U,
    0U,
    0U,
    0U,
    CAN_17_MCMCAN_ID_STANDARD,
    CAN_17_MCMCAN_TX_DED_BUFFER,
    FALSE
  },
  {
    52U,
    1U,
    0U,
    0U,
    CAN_17_MCMCAN_ID_STANDARD,
    CAN_17_MCMCAN_TX_DED_BUFFER,
    FALSE
  },
  {
    53U,
    2U,
    0U,
    0U,
    CAN_17_MCMCAN_ID_STANDARD,
    CAN_17_MCMCAN_TX_DED_BUFFER,
    FALSE
  },
  {
    54U,
    3U,
    0U,
    0U,
    CAN_17_MCMCAN_ID_STANDARD,
    CAN_17_MCMCAN_TX_DED_BUFFER,
    FALSE
  },
  {
    55U,
    4U,
    0U,
    0U,
    CAN_17_MCMCAN_ID_STANDARD,
    CAN_17_MCMCAN_TX_DED_BUFFER,
    FALSE
  },
  {
    56U,
    5U,
    0U,
    0U,
    CAN_17_MCMCAN_ID_STANDARD,
    CAN_17_MCMCAN_TX_DED_BUFFER,
    FALSE
  },
  {
    57U,
    6U,
    0U,
    0U,
    CAN_17_MCMCAN_ID_STANDARD,
    CAN_17_MCMCAN_TX_DED_BUFFER,
    FALSE
  },
  {
    58U,
    7U,
    0U,
    0U,
    CAN_17_MCMCAN_ID_STANDARD,
    CAN_17_MCMCAN_TX_DED_BUFFER,
    FALSE
  },
  {
    59U,
    8U,
    0U,
    0U,
    CAN_17_MCMCAN_ID_STANDARD,
    CAN_17_MCMCAN_TX_DED_BUFFER,
    FALSE
  },
  {
    60U,
    9U,
    0U,
    0U,
    CAN_17_MCMCAN_ID_STANDARD,
    CAN_17_MCMCAN_TX_DED_BUFFER,
    FALSE
  },
  {
    61U,
    10U,
    0U,
    0U,
    CAN_17_MCMCAN_ID_STANDARD,
    CAN_17_MCMCAN_TX_DED_BUFFER,
    FALSE
  },
  {
    62U,
    11U,
    0U,
    0U,
    CAN_17_MCMCAN_ID_STANDARD,
    CAN_17_MCMCAN_TX_DED_BUFFER,
    FALSE
  },
  {
    63U,
    12U,
    0U,
    0U,
    CAN_17_MCMCAN_ID_STANDARD,
    CAN_17_MCMCAN_TX_DED_BUFFER,
    FALSE
  },
  {
    64U,
    13U,
    0U,
    0U,
    CAN_17_MCMCAN_ID_STANDARD,
    CAN_17_MCMCAN_TX_DED_BUFFER,
    FALSE
  },
  {
    65U,
    14U,
    0U,
    0U,
    CAN_17_MCMCAN_ID_STANDARD,
    CAN_17_MCMCAN_TX_DED_BUFFER,
    FALSE
  },
  {
    66U,
    15U,
    0U,
    0U,
    CAN_17_MCMCAN_ID_STANDARD,
    CAN_17_MCMCAN_TX_DED_BUFFER,
    FALSE
  },
  {
    67U,
    16U,
    0U,
    0U,
    CAN_17_MCMCAN_ID_STANDARD,
    CAN_17_MCMCAN_TX_DED_BUFFER,
    FALSE
  },
  {
    68U,
    17U,
    0U,
    0U,
    CAN_17_MCMCAN_ID_STANDARD,
    CAN_17_MCMCAN_TX_DED_BUFFER,
    FALSE
  },
  {
    69U,
    18U,
    0U,
    0U,
    CAN_17_MCMCAN_ID_STANDARD,
    CAN_17_MCMCAN_TX_DED_BUFFER,
    FALSE
  },
  {
    70U,
    19U,
    0U,
    0U,
    CAN_17_MCMCAN_ID_STANDARD,
    CAN_17_MCMCAN_TX_DED_BUFFER,
    FALSE
  },
  {
    71U,
    20U,
    0U,
    0U,
    CAN_17_MCMCAN_ID_STANDARD,
    CAN_17_MCMCAN_TX_DED_BUFFER,
    FALSE
  },
  {
    72U,
    21U,
    0U,
    0U,
    CAN_17_MCMCAN_ID_STANDARD,
    CAN_17_MCMCAN_TX_DED_BUFFER,
    FALSE
  },
  {
    73U,
    22U,
    0U,
    0U,
    CAN_17_MCMCAN_ID_STANDARD,
    CAN_17_MCMCAN_TX_DED_BUFFER,
    FALSE
  },
  {
    74U,
    23U,
    0U,
    0U,
    CAN_17_MCMCAN_ID_STANDARD,
    CAN_17_MCMCAN_TX_DED_BUFFER,
    FALSE
  },
  {
    75U,
    24U,
    0U,
    0U,
    CAN_17_MCMCAN_ID_STANDARD,
    CAN_17_MCMCAN_TX_DED_BUFFER,
    FALSE
  },
  {
    76U,
    25U,
    0U,
    0U,
    CAN_17_MCMCAN_ID_STANDARD,
    CAN_17_MCMCAN_TX_DED_BUFFER,
    FALSE
  },
  {
    77U,
    26U,
    0U,
    0U,
    CAN_17_MCMCAN_ID_STANDARD,
    CAN_17_MCMCAN_TX_DED_BUFFER,
    FALSE
  },
  {
    78U,
    27U,
    0U,
    0U,
    CAN_17_MCMCAN_ID_STANDARD,
    CAN_17_MCMCAN_TX_DED_BUFFER,
    FALSE
  },
  {
    79U,
    28U,
    0U,
    0U,
    CAN_17_MCMCAN_ID_STANDARD,
    CAN_17_MCMCAN_TX_DED_BUFFER,
    FALSE
  },
  {
    80U,
    29U,
    0U,
    0U,
    CAN_17_MCMCAN_ID_STANDARD,
    CAN_17_MCMCAN_TX_DED_BUFFER,
    FALSE
  },
  {
    81U,
    30U,
    0U,
    0U,
    CAN_17_MCMCAN_ID_STANDARD,
    CAN_17_MCMCAN_TX_DED_BUFFER,
    FALSE
  },
  {
    82U,
    31U,
    0U,
    0U,
    CAN_17_MCMCAN_ID_STANDARD,
    CAN_17_MCMCAN_TX_DED_BUFFER,
    FALSE
  },
  {
    83U,
    0U,
    1U,
    0U,
    CAN_17_MCMCAN_ID_STANDARD,
    CAN_17_MCMCAN_TX_DED_BUFFER,
    FALSE
  }
};

/******************************************************************************/
             /* CAN Configuration Pointer for Core0 */
/******************************************************************************/
    /* Core sepcific CAN configurations */
/******************************************************************************/
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
static const Can_17_McmCan_CoreConfigType \
  Can_17_McmCan_kMcmCanConfigCore0=
{
  /* Number of controllers configured for the core */
  2,
  /* Array of all the controllers configured */
  &Can_17_McmCan_kControllerIndexingCore0[0],
  /* Pointer to CAN controller configuration settings */
  &Can_17_McmCan_kControllerConfigCore0[0],
  /* Pointer to Message RAM configuration settings */
  &Can_17_McmCan_kControllerMsgRAMMapConfigCore0[0],
  /* Pointer to CAN Controller Handling of Events : Interrupt/Polling */
  &Can_17_McmCan_kEventHandlingConfigCore0[0],
  /* Pointer to Baudrate configuration settings */
  &Can_17_McmCan_kBaudrateConfigCore0[0],
  /* Pointer to FDBaudrate configuration settings */
  &Can_17_McmCan_kFDBaudrateConfigCore0[0],
  /* Pointer to CAN Controller <-> Tx Hardware Objects Mapping */
  &Can_17_McmCan_kTxHwObjectConfigCore0[0],
  /* Pointer to CAN Controller <-> Rx Hardware Objects Mapping for Standard
     messages */
  &Can_17_McmCan_kSIDFilterConfigCore0[0],
  /* Pointer to CAN Controller <-> Rx Hardware Objects Mapping for Extended
  messages */
  NULL_PTR
};
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers going beyond 32 chars
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers going beyond 32 chars
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers going beyond 32 chars
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers going beyond 32 chars
in generated code due to Autosar Naming constraints.*/
#define CAN_17_MCMCAN_STOP_SEC_CONFIG_DATA_QM_CORE0_UNSPECIFIED
/* MISRA2012_RULE_20_1_JUSTIFICATION: Memmap header usage as per Autosar
   guideline. */
/* MISRA2012_RULE_4_10_JUSTIFICATION: Memmap header is repeatedly included
   without safegaurd. It complies to Autosar guidelines. */
#include "Can_17_McmCan_MemMap.h"

/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers going beyond 32 chars
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers going beyond 32 chars
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers going beyond 32 chars
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers going beyond 32 chars
in generated code due to Autosar Naming constraints.*/
#define CAN_17_MCMCAN_START_SEC_CONFIG_DATA_QM_GLOBAL_UNSPECIFIED
/* MISRA2012_RULE_20_1_JUSTIFICATION: Memmap header usage as per Autosar
   guideline. */
/* MISRA2012_RULE_4_10_JUSTIFICATION: Memmap header is repeatedly included
   without safegaurd. It complies to Autosar guidelines. */
#include "Can_17_McmCan_MemMap.h"

/*******************************************************************************
              CAN Kernel configuration parameters
********************************************************************************
     { CAN Global Kernel Address, The status of the nodes in the configured
     kernel }
********************************************************************************
           Note: 1. If any of CAN controllers in the kernel is not activated
                 then, the configuration for that kernel will not be generated.
                 2. CAN controllers that are activated in the kernel will be
                 set to True state and the pending controller nodes shall be
                 set to False state.
*******************************************************************************/
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
static const Can_17_McmCan_McmModuleConfigType \
  Can_17_McmCan_kMcmCanModuleConfig[1] =
{
  {
    /* The Global Base address of Kernel module */
    /* MISRA2012_RULE_11_6_JUSTIFICATION: The pointer cast is used to
    cast the generated address with CAN Kernel structure type */
    /* MISRA2012_RULE_11_4_JUSTIFICATION: conversion between pointer and
    integer type. Permitted for special function registers.*/
    (volatile Ifx_CAN*) 0xf0220000U,
    /* The CAN node is enabled or not within the kernel*/
    {
      /* Node 0 of kernel enable state */
      TRUE,
      /* Node 1 of kernel enable state */
      TRUE,
      /* Node 2 of kernel enable state */
      FALSE,
      /* Node 3 of kernel enable state */
      FALSE
    }
  }
};
/*******************************************************************************
              Overall CAN Hth Indexing Configuration
********************************************************************************
     { Hth handle Core assignment, Hth handle logical index (HOH ID),
     Hth handle core specific index}
********************************************************************************
           Note: 1. If there are no Transmit objects configured, this structure
           shall not be generated.
*******************************************************************************/
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
static const Can_17_McmCan_HthIndexType \
  Can_17_McmCan_kMcmCanHthIndexConfig[33] =
{
  {0,0,0},
  {0,0,1},
  {0,0,2},
  {0,0,3},
  {0,0,4},
  {0,0,5},
  {0,0,6},
  {0,0,7},
  {0,0,8},
  {0,0,9},
  {0,0,10},
  {0,0,11},
  {0,0,12},
  {0,0,13},
  {0,0,14},
  {0,0,15},
  {0,0,16},
  {0,0,17},
  {0,0,18},
  {0,0,19},
  {0,0,20},
  {0,0,21},
  {0,0,22},
  {0,0,23},
  {0,0,24},
  {0,0,25},
  {0,0,26},
  {0,0,27},
  {0,0,28},
  {0,0,29},
  {0,0,30},
  {0,0,31},
  {0,1,32}
};
/*******************************************************************************
              Overall CAN Logical Controller Indexing Configuration
********************************************************************************
     { CAN Controller Core assignment, CAN logical indexing indicating the core
       specific indexing,Physical node index and kernel index}
********************************************************************************
           Note:
*******************************************************************************/
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
static const Can_17_McmCan_LogicalControllerIndexType \
  Can_17_McmCan_kMcmCanLogicContIndexConfig[2] =
{
  {0,0,0,2},
  {0,1,1,2}
};
/******************************************************************************/
        /* Overall Physical CAN Controller Indexing Configuration */
/******************************************************************************/
      /* Physical CAN indexing indicating the Logical controller ID,
         Core specific controller ID and Core assignment.
         This has a constant array size of 12
         i.e.(PhyKernelID * No of Node in kernel)+(PhyNodeID)*/
/******************************************************************************/
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
static const Can_17_McmCan_PhyControllerIndexType \
  Can_17_McmCan_kMcmCanPhyContIndexConfig[12] =
{
  {255,255,255},
  {255,255,255},
  {255,255,255},
  {255,255,255},
  {255,255,255},
  {255,255,255},
  {255,255,255},
  {255,255,255},
  {0,0,0},
  {1,1,0},
  {255,255,255},
  {255,255,255}
};
/******************************************************************************/
                  /* Overall CAN Configuration */
/******************************************************************************/
      /* Over all CAN configurations, structure that points to one of the
           configuration is passed as parameter to Can_Init API */
/******************************************************************************/

const Can_17_McmCan_ConfigType \
  Can_17_McmCan_Config=
{
  /********************* Core specific configuration set **********************/
  /* Pointer to the Core specific CAN configuration set */
  {
    &Can_17_McmCan_kMcmCanConfigCore0,
    NULL_PTR,
    NULL_PTR,
    NULL_PTR,
    NULL_PTR,
    NULL_PTR
  },
  /****************** Global data shared amongst all cores ********************/
  /* Number of Kernels configured */
  1U,
  /* Number of Hrh configured */
  (Can_HwHandleType)51U,
  /* The number of hardware objects (includes Tx and Rx) configured in a
  ConfigSet */
  (Can_HwHandleType) 84U,

  /* Pointer to CAN Kernel configuration */
  &Can_17_McmCan_kMcmCanModuleConfig[0],
  /* Pointer holding physical controller index data */
  &Can_17_McmCan_kMcmCanPhyContIndexConfig[0],
  /* Pointer holding logical controller index data */
  &Can_17_McmCan_kMcmCanLogicContIndexConfig[0],
  /* Pointer holding configured Hth index data */
  &Can_17_McmCan_kMcmCanHthIndexConfig[0]};

/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers going beyond 32 chars
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers going beyond 32 chars
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers going beyond 32 chars
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers going beyond 32 chars
in generated code due to Autosar Naming constraints.*/
#define CAN_17_MCMCAN_STOP_SEC_CONFIG_DATA_QM_GLOBAL_UNSPECIFIED
/* MISRA2012_RULE_20_1_JUSTIFICATION: Memmap header usage as per Autosar
   guideline. */
/* MISRA2012_RULE_4_10_JUSTIFICATION: Memmap header is repeatedly included
   without safegaurd. It complies to Autosar guidelines. */
#include "Can_17_McmCan_MemMap.h"

/*******************************************************************************
**                      Global Variable Definitions                           **
*******************************************************************************/
/*******************************************************************************
**                      Private Constant Definitions                          **
*******************************************************************************/
/*******************************************************************************
**                      Private Variable Definitions                          **
*******************************************************************************/
/*******************************************************************************
**                      Private Function Definitions                          **
*******************************************************************************/
