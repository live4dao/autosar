/*****************************************************************************
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
**  FILENAME  : Adc_PBcfg.c                                                   **
**                                                                            **
**  VERSION   : 14.0.0                                                         **
**                                                                            **
**  DATE, TIME: 2024-04-29, 19:19:22            !!!IGNORE-LINE!!!             **
**                                                                            **
**  GENERATOR : Build b191017-0938              !!!IGNORE-LINE!!!             **
**                                                                            **
**  BSW MODULE DECRIPTION : Adc.bmd                                           **
**                                                                            **
**  VARIANT   : Variant PB                                                    **
**                                                                            **
**  PLATFORM  : Infineon AURIX2G                                              **
**                                                                            **
**  AUTHOR    : DL-AUTOSAR-Engineering                                        **
**                                                                            **
**  VENDOR    : Infineon Technologies                                         **
**                                                                            **
**  DESCRIPTION :  Adc configuration generated out of ECUC file               **
**                                                                            **
**  SPECIFICATION(S) : Specification of ADC Driver,                           **
**                     AUTOSAR Release 4.2.2 and 4.4.0                        **
**                                                                            **
**  MAY BE CHANGED BY USER : no                                               **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
/* Inclusion of module header file */
#include "Adc.h"
/*Function declaration for Notification Function of AdcGroup_0*/
extern void IoHwAb_AdcNotificationG0(void);
/*Function declaration for Notification Function of AdcGroup_1*/
extern void IoHwAb_AdcNotificationG1(void);
/*Function declaration for Notification Function of AdcGroup_2*/
extern void IoHwAb_AdcNotificationG2(void);
/*Function declaration for Notification Function of AdcGroup_3*/
extern void IoHwAb_AdcNotificationG3(void);

/***********Global configuration of EMUX feature***********/

/***********Configuration for External HW trigger and gating signals***********/

/*******************Group Definition - Channel Sequence*******************/
/* MISRA2012_RULE_5_1_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/

#define ADC_START_SEC_CONFIG_DATA_ASIL_B_CORE1_UNSPECIFIED
/* MISRA2012_RULE_20_1_JUSTIFICATION: Memmap header usage as per Autosar 
   guideline. */
/* MISRA2012_RULE_4_10_JUSTIFICATION: Memmap header is repeatedly included
   without safegaurd. It complies to Autosar guidelines. */ 
#include "Adc_MemMap.h"
/**Group Definition of AdcGroup_0- ID0 of HW Unit 0 */
static const Adc_GroupDefType Adc_kHwUnit0GrpAdcGroup_0_Config[7]=
{
  /*AS Logical Channel*/ /*Analog Channel*/ /*Result Register*/ /*Channel Diagnostic Data*/
        {  0U,                   0U,                0U,                0x00000000U},
        {  1U,                   1U,                1U,                0x00000000U},
        {  2U,                   2U,                2U,                0x00000000U},
        {  3U,                   3U,                3U,                0x00000000U},
        {  4U,                   4U,                4U,                0x00000000U},
        {  5U,                   6U,                5U,                0x00000000U},
        {  6U,                   7U,                6U,                0x00000000U}
};
/* MISRA2012_RULE_5_1_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/

#define ADC_STOP_SEC_CONFIG_DATA_ASIL_B_CORE1_UNSPECIFIED
/* MISRA2012_RULE_20_1_JUSTIFICATION: Memmap header usage as per Autosar 
   guideline. */
/* MISRA2012_RULE_4_10_JUSTIFICATION: Memmap header is repeatedly included
   without safegaurd. It complies to Autosar guidelines. */ 
#include "Adc_MemMap.h"
/* MISRA2012_RULE_5_1_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/

#define ADC_START_SEC_CONFIG_DATA_ASIL_B_CORE1_UNSPECIFIED
/* MISRA2012_RULE_20_1_JUSTIFICATION: Memmap header usage as per Autosar 
   guideline. */
/* MISRA2012_RULE_4_10_JUSTIFICATION: Memmap header is repeatedly included
   without safegaurd. It complies to Autosar guidelines. */ 
#include "Adc_MemMap.h"
/**Group Definition of AdcGroup_1- ID32 of HW Unit 1 */
static const Adc_GroupDefType Adc_kHwUnit1GrpAdcGroup_1_Config[6]=
{
  /*AS Logical Channel*/ /*Analog Channel*/ /*Result Register*/ /*Channel Diagnostic Data*/
        {  0U,                   0U,                0U,                0x00000000U},
        {  1U,                   1U,                1U,                0x00000000U},
        {  2U,                   2U,                2U,                0x00000000U},
        {  3U,                   3U,                3U,                0x00000000U},
        {  4U,                   4U,                4U,                0x00000000U},
        {  5U,                   7U,                5U,                0x00000000U}
};
/* MISRA2012_RULE_5_1_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/

#define ADC_STOP_SEC_CONFIG_DATA_ASIL_B_CORE1_UNSPECIFIED
/* MISRA2012_RULE_20_1_JUSTIFICATION: Memmap header usage as per Autosar 
   guideline. */
/* MISRA2012_RULE_4_10_JUSTIFICATION: Memmap header is repeatedly included
   without safegaurd. It complies to Autosar guidelines. */ 
#include "Adc_MemMap.h"
/* MISRA2012_RULE_5_1_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/

#define ADC_START_SEC_CONFIG_DATA_ASIL_B_CORE1_UNSPECIFIED
/* MISRA2012_RULE_20_1_JUSTIFICATION: Memmap header usage as per Autosar 
   guideline. */
/* MISRA2012_RULE_4_10_JUSTIFICATION: Memmap header is repeatedly included
   without safegaurd. It complies to Autosar guidelines. */ 
#include "Adc_MemMap.h"
/**Group Definition of AdcGroup_2- ID64 of HW Unit 2 */
static const Adc_GroupDefType Adc_kHwUnit2GrpAdcGroup_2_Config[5]=
{
  /*AS Logical Channel*/ /*Analog Channel*/ /*Result Register*/ /*Channel Diagnostic Data*/
        {  0U,                   0U,                0U,                0x00000000U},
        {  1U,                   4U,                1U,                0x00000000U},
        {  2U,                   5U,                2U,                0x00000000U},
        {  3U,                   6U,                3U,                0x00000000U},
        {  4U,                   7U,                4U,                0x00000000U}
};
/* MISRA2012_RULE_5_1_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/

#define ADC_STOP_SEC_CONFIG_DATA_ASIL_B_CORE1_UNSPECIFIED
/* MISRA2012_RULE_20_1_JUSTIFICATION: Memmap header usage as per Autosar 
   guideline. */
/* MISRA2012_RULE_4_10_JUSTIFICATION: Memmap header is repeatedly included
   without safegaurd. It complies to Autosar guidelines. */ 
#include "Adc_MemMap.h"
/* MISRA2012_RULE_5_1_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/

#define ADC_START_SEC_CONFIG_DATA_ASIL_B_CORE1_UNSPECIFIED
/* MISRA2012_RULE_20_1_JUSTIFICATION: Memmap header usage as per Autosar 
   guideline. */
/* MISRA2012_RULE_4_10_JUSTIFICATION: Memmap header is repeatedly included
   without safegaurd. It complies to Autosar guidelines. */ 
#include "Adc_MemMap.h"
/**Group Definition of AdcGroup_3- ID96 of HW Unit 3 */
static const Adc_GroupDefType Adc_kHwUnit3GrpAdcGroup_3_Config[6]=
{
  /*AS Logical Channel*/ /*Analog Channel*/ /*Result Register*/ /*Channel Diagnostic Data*/
        {  0U,                   0U,                0U,                0x00000000U},
        {  1U,                   1U,                1U,                0x00000000U},
        {  2U,                   2U,                2U,                0x00000000U},
        {  3U,                   3U,                3U,                0x00000000U},
        {  4U,                   4U,                4U,                0x00000000U},
        {  5U,                   6U,                5U,                0x00000000U}
};
/* MISRA2012_RULE_5_1_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/

#define ADC_STOP_SEC_CONFIG_DATA_ASIL_B_CORE1_UNSPECIFIED
/* MISRA2012_RULE_20_1_JUSTIFICATION: Memmap header usage as per Autosar 
   guideline. */
/* MISRA2012_RULE_4_10_JUSTIFICATION: Memmap header is repeatedly included
   without safegaurd. It complies to Autosar guidelines. */ 
#include "Adc_MemMap.h"

/***********************Group Configuration Definition***********************/
/* MISRA2012_RULE_5_1_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/ 

#define ADC_START_SEC_CONFIG_DATA_ASIL_B_CORE1_UNSPECIFIED
/* MISRA2012_RULE_20_1_JUSTIFICATION: Memmap header usage as per Autosar 
   guideline. */
/* MISRA2012_RULE_4_10_JUSTIFICATION: Memmap header is repeatedly included
   without safegaurd. It complies to Autosar guidelines. */ 
#include "Adc_MemMap.h"

/*****Group Configuration Definition of HW Unit 0 ******/
static const Adc_GroupCfgType Adc_kHwUnit0Grp_Config[1]=
{

  {/*Group Configuration structure for AdcGroup_0 - ID0*/
    /*
      Group Properties:
      Trigger Source: ADC_TRIGG_SRC_SW
      Trigger Edge: 
      HW Trigger Source: ADC_TRIG_NONE
      HW Gate Source: ADC_GATE_NONE
      Gate Level: ADC_GATE_LVL_HIGH
    */
    /* Notification Function Address */
    IoHwAb_AdcNotificationG0,
    /*Address for Group Definition Structure*/
    &Adc_kHwUnit0GrpAdcGroup_0_Config[0U],
    /*Address for the GTM trigger configuration structure*/
    (const Mcu_17_Gtm_TomAtomChConfigType *)0U,
    /*Address for the GTM gate configuration structure*/
    (const Mcu_17_Gtm_TomAtomChConfigType *)0U,
    /*Address for the ERU trigger configuration structure*/
    (const Adc_EruChannelCfgType *)0U,
    /*Address for the ERU gate configuration structure*/
    (const Adc_EruChannelCfgType *)0U,
    /*Configuration value for the G0QCTRL register*/
    0x00000000U,
    /*Configuration value for the G0QMR register*/
    0x00000001U,
    /*Configuration value for the G0ALIAS register*/
    0x00000100U,
    /* Configuration value for G0REQTM register*/
    0x00000000U,
    /*Bit Mask for all the analog channels configured for the group*/
    0x00dfU,
    /*Bit Mask for all the result registers configured for the group*/
    0x007fU,
    /*Bit Mask for all the analog channels configured for synchronous conversion*/
    0x0000U,
    /*Bit Mask for all the result registers configured for synchronous conversion*/
    0x0000U,
    ADC_TRIGG_SRC_SW,
    ADC_CONV_MODE_ONESHOT,
    ADC_ACCESS_MODE_SINGLE,
    ADC_STREAM_BUFFER_LINEAR,
    1U, /*Number of streaming samples for the group*/
    ADC_OTHER_HW_USED, /*HW peripheral used for Trigger*/
    ADC_OTHER_HW_USED, /*HW peripheral used for Gate*/
    0U, /*Priority Level for the group*/
    7U, /*Channel Count for the group*/
    0U, /*Limit Check enabled for the group*/
    0x00U, /* EMUX configuration of the Group */
    0U /* Diagnostic channels configured for the Group */
  }
};
/* MISRA2012_RULE_5_1_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/

#define ADC_STOP_SEC_CONFIG_DATA_ASIL_B_CORE1_UNSPECIFIED
/* MISRA2012_RULE_20_1_JUSTIFICATION: Memmap header usage as per Autosar 
   guideline. */
/* MISRA2012_RULE_4_10_JUSTIFICATION: Memmap header is repeatedly included
   without safegaurd. It complies to Autosar guidelines. */ 
#include "Adc_MemMap.h"

/* MISRA2012_RULE_5_1_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/ 

#define ADC_START_SEC_CONFIG_DATA_ASIL_B_CORE1_UNSPECIFIED
/* MISRA2012_RULE_20_1_JUSTIFICATION: Memmap header usage as per Autosar 
   guideline. */
/* MISRA2012_RULE_4_10_JUSTIFICATION: Memmap header is repeatedly included
   without safegaurd. It complies to Autosar guidelines. */ 
#include "Adc_MemMap.h"

/*****Group Configuration Definition of HW Unit 1 ******/
static const Adc_GroupCfgType Adc_kHwUnit1Grp_Config[1]=
{

  {/*Group Configuration structure for AdcGroup_1 - ID32*/
    /*
      Group Properties:
      Trigger Source: ADC_TRIGG_SRC_SW
      Trigger Edge: 
      HW Trigger Source: ADC_TRIG_NONE
      HW Gate Source: ADC_GATE_NONE
      Gate Level: ADC_GATE_LVL_HIGH
    */
    /* Notification Function Address */
    IoHwAb_AdcNotificationG1,
    /*Address for Group Definition Structure*/
    &Adc_kHwUnit1GrpAdcGroup_1_Config[0U],
    /*Address for the GTM trigger configuration structure*/
    (const Mcu_17_Gtm_TomAtomChConfigType *)0U,
    /*Address for the GTM gate configuration structure*/
    (const Mcu_17_Gtm_TomAtomChConfigType *)0U,
    /*Address for the ERU trigger configuration structure*/
    (const Adc_EruChannelCfgType *)0U,
    /*Address for the ERU gate configuration structure*/
    (const Adc_EruChannelCfgType *)0U,
    /*Configuration value for the G1QCTRL register*/
    0x00000000U,
    /*Configuration value for the G1QMR register*/
    0x00000001U,
    /*Configuration value for the G1ALIAS register*/
    0x00000100U,
    /* Configuration value for G1REQTM register*/
    0x00000000U,
    /*Bit Mask for all the analog channels configured for the group*/
    0x009fU,
    /*Bit Mask for all the result registers configured for the group*/
    0x003fU,
    /*Bit Mask for all the analog channels configured for synchronous conversion*/
    0x0000U,
    /*Bit Mask for all the result registers configured for synchronous conversion*/
    0x0000U,
    ADC_TRIGG_SRC_SW,
    ADC_CONV_MODE_ONESHOT,
    ADC_ACCESS_MODE_SINGLE,
    ADC_STREAM_BUFFER_LINEAR,
    1U, /*Number of streaming samples for the group*/
    ADC_OTHER_HW_USED, /*HW peripheral used for Trigger*/
    ADC_OTHER_HW_USED, /*HW peripheral used for Gate*/
    0U, /*Priority Level for the group*/
    6U, /*Channel Count for the group*/
    0U, /*Limit Check enabled for the group*/
    0x00U, /* EMUX configuration of the Group */
    0U /* Diagnostic channels configured for the Group */
  }
};
/* MISRA2012_RULE_5_1_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/

#define ADC_STOP_SEC_CONFIG_DATA_ASIL_B_CORE1_UNSPECIFIED
/* MISRA2012_RULE_20_1_JUSTIFICATION: Memmap header usage as per Autosar 
   guideline. */
/* MISRA2012_RULE_4_10_JUSTIFICATION: Memmap header is repeatedly included
   without safegaurd. It complies to Autosar guidelines. */ 
#include "Adc_MemMap.h"

/* MISRA2012_RULE_5_1_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/ 

#define ADC_START_SEC_CONFIG_DATA_ASIL_B_CORE1_UNSPECIFIED
/* MISRA2012_RULE_20_1_JUSTIFICATION: Memmap header usage as per Autosar 
   guideline. */
/* MISRA2012_RULE_4_10_JUSTIFICATION: Memmap header is repeatedly included
   without safegaurd. It complies to Autosar guidelines. */ 
#include "Adc_MemMap.h"

/*****Group Configuration Definition of HW Unit 2 ******/
static const Adc_GroupCfgType Adc_kHwUnit2Grp_Config[1]=
{

  {/*Group Configuration structure for AdcGroup_2 - ID64*/
    /*
      Group Properties:
      Trigger Source: ADC_TRIGG_SRC_SW
      Trigger Edge: 
      HW Trigger Source: ADC_TRIG_NONE
      HW Gate Source: ADC_GATE_NONE
      Gate Level: ADC_GATE_LVL_HIGH
    */
    /* Notification Function Address */
    IoHwAb_AdcNotificationG2,
    /*Address for Group Definition Structure*/
    &Adc_kHwUnit2GrpAdcGroup_2_Config[0U],
    /*Address for the GTM trigger configuration structure*/
    (const Mcu_17_Gtm_TomAtomChConfigType *)0U,
    /*Address for the GTM gate configuration structure*/
    (const Mcu_17_Gtm_TomAtomChConfigType *)0U,
    /*Address for the ERU trigger configuration structure*/
    (const Adc_EruChannelCfgType *)0U,
    /*Address for the ERU gate configuration structure*/
    (const Adc_EruChannelCfgType *)0U,
    /*Configuration value for the G2QCTRL register*/
    0x00000000U,
    /*Configuration value for the G2QMR register*/
    0x00000001U,
    /*Configuration value for the G2ALIAS register*/
    0x00000100U,
    /* Configuration value for G2REQTM register*/
    0x00000000U,
    /*Bit Mask for all the analog channels configured for the group*/
    0x00f1U,
    /*Bit Mask for all the result registers configured for the group*/
    0x001fU,
    /*Bit Mask for all the analog channels configured for synchronous conversion*/
    0x0000U,
    /*Bit Mask for all the result registers configured for synchronous conversion*/
    0x0000U,
    ADC_TRIGG_SRC_SW,
    ADC_CONV_MODE_ONESHOT,
    ADC_ACCESS_MODE_SINGLE,
    ADC_STREAM_BUFFER_LINEAR,
    1U, /*Number of streaming samples for the group*/
    ADC_OTHER_HW_USED, /*HW peripheral used for Trigger*/
    ADC_OTHER_HW_USED, /*HW peripheral used for Gate*/
    0U, /*Priority Level for the group*/
    5U, /*Channel Count for the group*/
    0U, /*Limit Check enabled for the group*/
    0x00U, /* EMUX configuration of the Group */
    0U /* Diagnostic channels configured for the Group */
  }
};
/* MISRA2012_RULE_5_1_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/

#define ADC_STOP_SEC_CONFIG_DATA_ASIL_B_CORE1_UNSPECIFIED
/* MISRA2012_RULE_20_1_JUSTIFICATION: Memmap header usage as per Autosar 
   guideline. */
/* MISRA2012_RULE_4_10_JUSTIFICATION: Memmap header is repeatedly included
   without safegaurd. It complies to Autosar guidelines. */ 
#include "Adc_MemMap.h"

/* MISRA2012_RULE_5_1_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/ 

#define ADC_START_SEC_CONFIG_DATA_ASIL_B_CORE1_UNSPECIFIED
/* MISRA2012_RULE_20_1_JUSTIFICATION: Memmap header usage as per Autosar 
   guideline. */
/* MISRA2012_RULE_4_10_JUSTIFICATION: Memmap header is repeatedly included
   without safegaurd. It complies to Autosar guidelines. */ 
#include "Adc_MemMap.h"

/*****Group Configuration Definition of HW Unit 3 ******/
static const Adc_GroupCfgType Adc_kHwUnit3Grp_Config[1]=
{

  {/*Group Configuration structure for AdcGroup_3 - ID96*/
    /*
      Group Properties:
      Trigger Source: ADC_TRIGG_SRC_SW
      Trigger Edge: 
      HW Trigger Source: ADC_TRIG_NONE
      HW Gate Source: ADC_GATE_NONE
      Gate Level: ADC_GATE_LVL_HIGH
    */
    /* Notification Function Address */
    IoHwAb_AdcNotificationG3,
    /*Address for Group Definition Structure*/
    &Adc_kHwUnit3GrpAdcGroup_3_Config[0U],
    /*Address for the GTM trigger configuration structure*/
    (const Mcu_17_Gtm_TomAtomChConfigType *)0U,
    /*Address for the GTM gate configuration structure*/
    (const Mcu_17_Gtm_TomAtomChConfigType *)0U,
    /*Address for the ERU trigger configuration structure*/
    (const Adc_EruChannelCfgType *)0U,
    /*Address for the ERU gate configuration structure*/
    (const Adc_EruChannelCfgType *)0U,
    /*Configuration value for the G3QCTRL register*/
    0x00000000U,
    /*Configuration value for the G3QMR register*/
    0x00000001U,
    /*Configuration value for the G3ALIAS register*/
    0x00000100U,
    /* Configuration value for G3REQTM register*/
    0x00000000U,
    /*Bit Mask for all the analog channels configured for the group*/
    0x005fU,
    /*Bit Mask for all the result registers configured for the group*/
    0x003fU,
    /*Bit Mask for all the analog channels configured for synchronous conversion*/
    0x0000U,
    /*Bit Mask for all the result registers configured for synchronous conversion*/
    0x0000U,
    ADC_TRIGG_SRC_SW,
    ADC_CONV_MODE_ONESHOT,
    ADC_ACCESS_MODE_SINGLE,
    ADC_STREAM_BUFFER_LINEAR,
    1U, /*Number of streaming samples for the group*/
    ADC_OTHER_HW_USED, /*HW peripheral used for Trigger*/
    ADC_OTHER_HW_USED, /*HW peripheral used for Gate*/
    0U, /*Priority Level for the group*/
    6U, /*Channel Count for the group*/
    0U, /*Limit Check enabled for the group*/
    0x00U, /* EMUX configuration of the Group */
    0U /* Diagnostic channels configured for the Group */
  }
};
/* MISRA2012_RULE_5_1_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/

#define ADC_STOP_SEC_CONFIG_DATA_ASIL_B_CORE1_UNSPECIFIED
/* MISRA2012_RULE_20_1_JUSTIFICATION: Memmap header usage as per Autosar 
   guideline. */
/* MISRA2012_RULE_4_10_JUSTIFICATION: Memmap header is repeatedly included
   without safegaurd. It complies to Autosar guidelines. */ 
#include "Adc_MemMap.h"


/***********************Channel Configuration Definition***********************/
/*****Channel Configuration Definition of HW Unit 0 *****/
/* MISRA2012_RULE_5_1_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/

#define ADC_START_SEC_CONFIG_DATA_ASIL_B_CORE1_UNSPECIFIED
/* MISRA2012_RULE_20_1_JUSTIFICATION: Memmap header usage as per Autosar 
   guideline. */
/* MISRA2012_RULE_4_10_JUSTIFICATION: Memmap header is repeatedly included
   without safegaurd. It complies to Autosar guidelines. */ 
#include "Adc_MemMap.h"
static const Adc_ChannelCfgType Adc_kHwUnit0Ch_Config[7]=
{

  {
    0x00000000U, /*Configuration value for the G0CHCTR0 register*/
    0x00000000U, /*Configuration value for the G0BOUND register*/
    0U, /*Analog Channel number for the corresponding Logical Channel*/
    0U /*Limit Check channel or not */
  },

  {
    0x00000000U, /*Configuration value for the G0CHCTR1 register*/
    0x00000000U, /*Configuration value for the G0BOUND register*/
    1U, /*Analog Channel number for the corresponding Logical Channel*/
    0U /*Limit Check channel or not */
  },

  {
    0x00000000U, /*Configuration value for the G0CHCTR2 register*/
    0x00000000U, /*Configuration value for the G0BOUND register*/
    2U, /*Analog Channel number for the corresponding Logical Channel*/
    0U /*Limit Check channel or not */
  },

  {
    0x00000000U, /*Configuration value for the G0CHCTR3 register*/
    0x00000000U, /*Configuration value for the G0BOUND register*/
    3U, /*Analog Channel number for the corresponding Logical Channel*/
    0U /*Limit Check channel or not */
  },

  {
    0x00000000U, /*Configuration value for the G0CHCTR4 register*/
    0x00000000U, /*Configuration value for the G0BOUND register*/
    4U, /*Analog Channel number for the corresponding Logical Channel*/
    0U /*Limit Check channel or not */
  },

  {
    0x00000000U, /*Configuration value for the G0CHCTR6 register*/
    0x00000000U, /*Configuration value for the G0BOUND register*/
    6U, /*Analog Channel number for the corresponding Logical Channel*/
    0U /*Limit Check channel or not */
  },

  {
    0x00000000U, /*Configuration value for the G0CHCTR7 register*/
    0x00000000U, /*Configuration value for the G0BOUND register*/
    7U, /*Analog Channel number for the corresponding Logical Channel*/
    0U /*Limit Check channel or not */
  }
};
/* MISRA2012_RULE_5_1_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
#define ADC_STOP_SEC_CONFIG_DATA_ASIL_B_CORE1_UNSPECIFIED
/* MISRA2012_RULE_20_1_JUSTIFICATION: Memmap header usage as per Autosar 
   guideline. */
/* MISRA2012_RULE_4_10_JUSTIFICATION: Memmap header is repeatedly included
   without safegaurd. It complies to Autosar guidelines. */ 
#include "Adc_MemMap.h"

/*****Channel Configuration Definition of HW Unit 1 *****/
/* MISRA2012_RULE_5_1_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/

#define ADC_START_SEC_CONFIG_DATA_ASIL_B_CORE1_UNSPECIFIED
/* MISRA2012_RULE_20_1_JUSTIFICATION: Memmap header usage as per Autosar 
   guideline. */
/* MISRA2012_RULE_4_10_JUSTIFICATION: Memmap header is repeatedly included
   without safegaurd. It complies to Autosar guidelines. */ 
#include "Adc_MemMap.h"
static const Adc_ChannelCfgType Adc_kHwUnit1Ch_Config[6]=
{

  {
    0x00000000U, /*Configuration value for the G1CHCTR0 register*/
    0x00000000U, /*Configuration value for the G1BOUND register*/
    0U, /*Analog Channel number for the corresponding Logical Channel*/
    0U /*Limit Check channel or not */
  },

  {
    0x00000000U, /*Configuration value for the G1CHCTR1 register*/
    0x00000000U, /*Configuration value for the G1BOUND register*/
    1U, /*Analog Channel number for the corresponding Logical Channel*/
    0U /*Limit Check channel or not */
  },

  {
    0x00000000U, /*Configuration value for the G1CHCTR2 register*/
    0x00000000U, /*Configuration value for the G1BOUND register*/
    2U, /*Analog Channel number for the corresponding Logical Channel*/
    0U /*Limit Check channel or not */
  },

  {
    0x00000000U, /*Configuration value for the G1CHCTR3 register*/
    0x00000000U, /*Configuration value for the G1BOUND register*/
    3U, /*Analog Channel number for the corresponding Logical Channel*/
    0U /*Limit Check channel or not */
  },

  {
    0x00000000U, /*Configuration value for the G1CHCTR4 register*/
    0x00000000U, /*Configuration value for the G1BOUND register*/
    4U, /*Analog Channel number for the corresponding Logical Channel*/
    0U /*Limit Check channel or not */
  },

  {
    0x00000000U, /*Configuration value for the G1CHCTR7 register*/
    0x00000000U, /*Configuration value for the G1BOUND register*/
    7U, /*Analog Channel number for the corresponding Logical Channel*/
    0U /*Limit Check channel or not */
  }
};
/* MISRA2012_RULE_5_1_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
#define ADC_STOP_SEC_CONFIG_DATA_ASIL_B_CORE1_UNSPECIFIED
/* MISRA2012_RULE_20_1_JUSTIFICATION: Memmap header usage as per Autosar 
   guideline. */
/* MISRA2012_RULE_4_10_JUSTIFICATION: Memmap header is repeatedly included
   without safegaurd. It complies to Autosar guidelines. */ 
#include "Adc_MemMap.h"

/*****Channel Configuration Definition of HW Unit 2 *****/
/* MISRA2012_RULE_5_1_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/

#define ADC_START_SEC_CONFIG_DATA_ASIL_B_CORE1_UNSPECIFIED
/* MISRA2012_RULE_20_1_JUSTIFICATION: Memmap header usage as per Autosar 
   guideline. */
/* MISRA2012_RULE_4_10_JUSTIFICATION: Memmap header is repeatedly included
   without safegaurd. It complies to Autosar guidelines. */ 
#include "Adc_MemMap.h"
static const Adc_ChannelCfgType Adc_kHwUnit2Ch_Config[5]=
{

  {
    0x00000000U, /*Configuration value for the G2CHCTR0 register*/
    0x00000000U, /*Configuration value for the G2BOUND register*/
    0U, /*Analog Channel number for the corresponding Logical Channel*/
    0U /*Limit Check channel or not */
  },

  {
    0x00000000U, /*Configuration value for the G2CHCTR4 register*/
    0x00000000U, /*Configuration value for the G2BOUND register*/
    4U, /*Analog Channel number for the corresponding Logical Channel*/
    0U /*Limit Check channel or not */
  },

  {
    0x00000000U, /*Configuration value for the G2CHCTR5 register*/
    0x00000000U, /*Configuration value for the G2BOUND register*/
    5U, /*Analog Channel number for the corresponding Logical Channel*/
    0U /*Limit Check channel or not */
  },

  {
    0x00000000U, /*Configuration value for the G2CHCTR6 register*/
    0x00000000U, /*Configuration value for the G2BOUND register*/
    6U, /*Analog Channel number for the corresponding Logical Channel*/
    0U /*Limit Check channel or not */
  },

  {
    0x00000000U, /*Configuration value for the G2CHCTR7 register*/
    0x00000000U, /*Configuration value for the G2BOUND register*/
    7U, /*Analog Channel number for the corresponding Logical Channel*/
    0U /*Limit Check channel or not */
  }
};
/* MISRA2012_RULE_5_1_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
#define ADC_STOP_SEC_CONFIG_DATA_ASIL_B_CORE1_UNSPECIFIED
/* MISRA2012_RULE_20_1_JUSTIFICATION: Memmap header usage as per Autosar 
   guideline. */
/* MISRA2012_RULE_4_10_JUSTIFICATION: Memmap header is repeatedly included
   without safegaurd. It complies to Autosar guidelines. */ 
#include "Adc_MemMap.h"

/*****Channel Configuration Definition of HW Unit 3 *****/
/* MISRA2012_RULE_5_1_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/

#define ADC_START_SEC_CONFIG_DATA_ASIL_B_CORE1_UNSPECIFIED
/* MISRA2012_RULE_20_1_JUSTIFICATION: Memmap header usage as per Autosar 
   guideline. */
/* MISRA2012_RULE_4_10_JUSTIFICATION: Memmap header is repeatedly included
   without safegaurd. It complies to Autosar guidelines. */ 
#include "Adc_MemMap.h"
static const Adc_ChannelCfgType Adc_kHwUnit3Ch_Config[6]=
{

  {
    0x00000000U, /*Configuration value for the G3CHCTR0 register*/
    0x00000000U, /*Configuration value for the G3BOUND register*/
    0U, /*Analog Channel number for the corresponding Logical Channel*/
    0U /*Limit Check channel or not */
  },

  {
    0x00000000U, /*Configuration value for the G3CHCTR1 register*/
    0x00000000U, /*Configuration value for the G3BOUND register*/
    1U, /*Analog Channel number for the corresponding Logical Channel*/
    0U /*Limit Check channel or not */
  },

  {
    0x00000000U, /*Configuration value for the G3CHCTR2 register*/
    0x00000000U, /*Configuration value for the G3BOUND register*/
    2U, /*Analog Channel number for the corresponding Logical Channel*/
    0U /*Limit Check channel or not */
  },

  {
    0x00000000U, /*Configuration value for the G3CHCTR3 register*/
    0x00000000U, /*Configuration value for the G3BOUND register*/
    3U, /*Analog Channel number for the corresponding Logical Channel*/
    0U /*Limit Check channel or not */
  },

  {
    0x00000000U, /*Configuration value for the G3CHCTR4 register*/
    0x00000000U, /*Configuration value for the G3BOUND register*/
    4U, /*Analog Channel number for the corresponding Logical Channel*/
    0U /*Limit Check channel or not */
  },

  {
    0x00000000U, /*Configuration value for the G3CHCTR6 register*/
    0x00000000U, /*Configuration value for the G3BOUND register*/
    6U, /*Analog Channel number for the corresponding Logical Channel*/
    0U /*Limit Check channel or not */
  }
};
/* MISRA2012_RULE_5_1_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
#define ADC_STOP_SEC_CONFIG_DATA_ASIL_B_CORE1_UNSPECIFIED
/* MISRA2012_RULE_20_1_JUSTIFICATION: Memmap header usage as per Autosar 
   guideline. */
/* MISRA2012_RULE_4_10_JUSTIFICATION: Memmap header is repeatedly included
   without safegaurd. It complies to Autosar guidelines. */ 
#include "Adc_MemMap.h"

/********************HW Unit Converter Configurations********************/

/**HW Unit 0 Converter Configurations **/
/* MISRA2012_RULE_5_1_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
#define ADC_START_SEC_CONFIG_DATA_ASIL_B_CORE1_UNSPECIFIED
/* MISRA2012_RULE_20_1_JUSTIFICATION: Memmap header usage as per Autosar 
   guideline. */
/* MISRA2012_RULE_4_10_JUSTIFICATION: Memmap header is repeatedly included
   without safegaurd. It complies to Autosar guidelines. */ 
#include "Adc_MemMap.h"
static const Adc_HwCfgType Adc_kHwUnit0Hw_Config=
{
  0x00600004U, /*Configuration value for G0ANCFG register*/
  0x00000003U, /*Configuration value for G0ARBCFG register*/
  0x01000000U, /*Configuration value for G0ARBPR register*/
  0x0000000aU, /*Configuration value for G0ICLASS0 register*/
  0x0000000aU, /*Configuration value for G0ICLASS1 register*/
  0x00000000U /*Configuration value for G0SYNCTR register*/
};
/* MISRA2012_RULE_5_1_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
#define ADC_STOP_SEC_CONFIG_DATA_ASIL_B_CORE1_UNSPECIFIED
/* MISRA2012_RULE_20_1_JUSTIFICATION: Memmap header usage as per Autosar 
   guideline. */
/* MISRA2012_RULE_4_10_JUSTIFICATION: Memmap header is repeatedly included
   without safegaurd. It complies to Autosar guidelines. */ 
#include "Adc_MemMap.h"


/**HW Unit 1 Converter Configurations **/
/* MISRA2012_RULE_5_1_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
#define ADC_START_SEC_CONFIG_DATA_ASIL_B_CORE1_UNSPECIFIED
/* MISRA2012_RULE_20_1_JUSTIFICATION: Memmap header usage as per Autosar 
   guideline. */
/* MISRA2012_RULE_4_10_JUSTIFICATION: Memmap header is repeatedly included
   without safegaurd. It complies to Autosar guidelines. */ 
#include "Adc_MemMap.h"
static const Adc_HwCfgType Adc_kHwUnit1Hw_Config=
{
  0x00600004U, /*Configuration value for G1ANCFG register*/
  0x00000003U, /*Configuration value for G1ARBCFG register*/
  0x01000000U, /*Configuration value for G1ARBPR register*/
  0x0000000aU, /*Configuration value for G1ICLASS0 register*/
  0x0000000aU, /*Configuration value for G1ICLASS1 register*/
  0x00000000U /*Configuration value for G1SYNCTR register*/
};
/* MISRA2012_RULE_5_1_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
#define ADC_STOP_SEC_CONFIG_DATA_ASIL_B_CORE1_UNSPECIFIED
/* MISRA2012_RULE_20_1_JUSTIFICATION: Memmap header usage as per Autosar 
   guideline. */
/* MISRA2012_RULE_4_10_JUSTIFICATION: Memmap header is repeatedly included
   without safegaurd. It complies to Autosar guidelines. */ 
#include "Adc_MemMap.h"


/**HW Unit 2 Converter Configurations **/
/* MISRA2012_RULE_5_1_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
#define ADC_START_SEC_CONFIG_DATA_ASIL_B_CORE1_UNSPECIFIED
/* MISRA2012_RULE_20_1_JUSTIFICATION: Memmap header usage as per Autosar 
   guideline. */
/* MISRA2012_RULE_4_10_JUSTIFICATION: Memmap header is repeatedly included
   without safegaurd. It complies to Autosar guidelines. */ 
#include "Adc_MemMap.h"
static const Adc_HwCfgType Adc_kHwUnit2Hw_Config=
{
  0x00600004U, /*Configuration value for G2ANCFG register*/
  0x00000003U, /*Configuration value for G2ARBCFG register*/
  0x01000000U, /*Configuration value for G2ARBPR register*/
  0x0000000aU, /*Configuration value for G2ICLASS0 register*/
  0x0000000aU, /*Configuration value for G2ICLASS1 register*/
  0x00000000U /*Configuration value for G2SYNCTR register*/
};
/* MISRA2012_RULE_5_1_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
#define ADC_STOP_SEC_CONFIG_DATA_ASIL_B_CORE1_UNSPECIFIED
/* MISRA2012_RULE_20_1_JUSTIFICATION: Memmap header usage as per Autosar 
   guideline. */
/* MISRA2012_RULE_4_10_JUSTIFICATION: Memmap header is repeatedly included
   without safegaurd. It complies to Autosar guidelines. */ 
#include "Adc_MemMap.h"


/**HW Unit 3 Converter Configurations **/
/* MISRA2012_RULE_5_1_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
#define ADC_START_SEC_CONFIG_DATA_ASIL_B_CORE1_UNSPECIFIED
/* MISRA2012_RULE_20_1_JUSTIFICATION: Memmap header usage as per Autosar 
   guideline. */
/* MISRA2012_RULE_4_10_JUSTIFICATION: Memmap header is repeatedly included
   without safegaurd. It complies to Autosar guidelines. */ 
#include "Adc_MemMap.h"
static const Adc_HwCfgType Adc_kHwUnit3Hw_Config=
{
  0x00600004U, /*Configuration value for G3ANCFG register*/
  0x00000003U, /*Configuration value for G3ARBCFG register*/
  0x01000000U, /*Configuration value for G3ARBPR register*/
  0x0000000aU, /*Configuration value for G3ICLASS0 register*/
  0x0000000aU, /*Configuration value for G3ICLASS1 register*/
  0x00000000U /*Configuration value for G3SYNCTR register*/
};
/* MISRA2012_RULE_5_1_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
#define ADC_STOP_SEC_CONFIG_DATA_ASIL_B_CORE1_UNSPECIFIED
/* MISRA2012_RULE_20_1_JUSTIFICATION: Memmap header usage as per Autosar 
   guideline. */
/* MISRA2012_RULE_4_10_JUSTIFICATION: Memmap header is repeatedly included
   without safegaurd. It complies to Autosar guidelines. */ 
#include "Adc_MemMap.h"


/***************************HW Unit Configuration ***************************/

/*************HW Unit 0 Configuration **************/
/* MISRA2012_RULE_5_1_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
   #define ADC_START_SEC_CONFIG_DATA_ASIL_B_CORE1_UNSPECIFIED
/* MISRA2012_RULE_20_1_JUSTIFICATION: Memmap header usage as per Autosar 
   guideline. */
/* MISRA2012_RULE_4_10_JUSTIFICATION: Memmap header is repeatedly included
   without safegaurd. It complies to Autosar guidelines. */ 
#include "Adc_MemMap.h"
static const Adc_HwUnitCfgType Adc_kHwUnit0_Config=
{
  &Adc_kHwUnit0Hw_Config, /*Analog Converter Configuration*/
  &Adc_kHwUnit0Ch_Config[0U], /*Channel Configuration structure*/
  &Adc_kHwUnit0Grp_Config[0U], /*Group Configuration structure*/
  0x00000001U, /* Mask for SW triggered groups*/
  0x00000000U,/* Mask for HW triggered groups*/
  ADC_SYNC_CONV_MODE_NONE, /* Synchronous conversion mode */
  { 0xffU, 0xffU, 0xffU }, /* Slave Kernels */
  1U, /* Group Count for HW Unit 0*/
  1U /* Bit Mask for SRNs used for HW Unit 0*/
};
/* MISRA2012_RULE_5_1_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
#define ADC_STOP_SEC_CONFIG_DATA_ASIL_B_CORE1_UNSPECIFIED
/* MISRA2012_RULE_20_1_JUSTIFICATION: Memmap header usage as per Autosar 
   guideline. */
/* MISRA2012_RULE_4_10_JUSTIFICATION: Memmap header is repeatedly included
   without safegaurd. It complies to Autosar guidelines. */ 
#include "Adc_MemMap.h"


/*************HW Unit 1 Configuration **************/
/* MISRA2012_RULE_5_1_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
   #define ADC_START_SEC_CONFIG_DATA_ASIL_B_CORE1_UNSPECIFIED
/* MISRA2012_RULE_20_1_JUSTIFICATION: Memmap header usage as per Autosar 
   guideline. */
/* MISRA2012_RULE_4_10_JUSTIFICATION: Memmap header is repeatedly included
   without safegaurd. It complies to Autosar guidelines. */ 
#include "Adc_MemMap.h"
static const Adc_HwUnitCfgType Adc_kHwUnit1_Config=
{
  &Adc_kHwUnit1Hw_Config, /*Analog Converter Configuration*/
  &Adc_kHwUnit1Ch_Config[0U], /*Channel Configuration structure*/
  &Adc_kHwUnit1Grp_Config[0U], /*Group Configuration structure*/
  0x00000001U, /* Mask for SW triggered groups*/
  0x00000000U,/* Mask for HW triggered groups*/
  ADC_SYNC_CONV_MODE_NONE, /* Synchronous conversion mode */
  { 0xffU, 0xffU, 0xffU }, /* Slave Kernels */
  1U, /* Group Count for HW Unit 1*/
  1U /* Bit Mask for SRNs used for HW Unit 1*/
};
/* MISRA2012_RULE_5_1_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
#define ADC_STOP_SEC_CONFIG_DATA_ASIL_B_CORE1_UNSPECIFIED
/* MISRA2012_RULE_20_1_JUSTIFICATION: Memmap header usage as per Autosar 
   guideline. */
/* MISRA2012_RULE_4_10_JUSTIFICATION: Memmap header is repeatedly included
   without safegaurd. It complies to Autosar guidelines. */ 
#include "Adc_MemMap.h"


/*************HW Unit 2 Configuration **************/
/* MISRA2012_RULE_5_1_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
   #define ADC_START_SEC_CONFIG_DATA_ASIL_B_CORE1_UNSPECIFIED
/* MISRA2012_RULE_20_1_JUSTIFICATION: Memmap header usage as per Autosar 
   guideline. */
/* MISRA2012_RULE_4_10_JUSTIFICATION: Memmap header is repeatedly included
   without safegaurd. It complies to Autosar guidelines. */ 
#include "Adc_MemMap.h"
static const Adc_HwUnitCfgType Adc_kHwUnit2_Config=
{
  &Adc_kHwUnit2Hw_Config, /*Analog Converter Configuration*/
  &Adc_kHwUnit2Ch_Config[0U], /*Channel Configuration structure*/
  &Adc_kHwUnit2Grp_Config[0U], /*Group Configuration structure*/
  0x00000001U, /* Mask for SW triggered groups*/
  0x00000000U,/* Mask for HW triggered groups*/
  ADC_SYNC_CONV_MODE_NONE, /* Synchronous conversion mode */
  { 0xffU, 0xffU, 0xffU }, /* Slave Kernels */
  1U, /* Group Count for HW Unit 2*/
  1U /* Bit Mask for SRNs used for HW Unit 2*/
};
/* MISRA2012_RULE_5_1_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
#define ADC_STOP_SEC_CONFIG_DATA_ASIL_B_CORE1_UNSPECIFIED
/* MISRA2012_RULE_20_1_JUSTIFICATION: Memmap header usage as per Autosar 
   guideline. */
/* MISRA2012_RULE_4_10_JUSTIFICATION: Memmap header is repeatedly included
   without safegaurd. It complies to Autosar guidelines. */ 
#include "Adc_MemMap.h"


/*************HW Unit 3 Configuration **************/
/* MISRA2012_RULE_5_1_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
   #define ADC_START_SEC_CONFIG_DATA_ASIL_B_CORE1_UNSPECIFIED
/* MISRA2012_RULE_20_1_JUSTIFICATION: Memmap header usage as per Autosar 
   guideline. */
/* MISRA2012_RULE_4_10_JUSTIFICATION: Memmap header is repeatedly included
   without safegaurd. It complies to Autosar guidelines. */ 
#include "Adc_MemMap.h"
static const Adc_HwUnitCfgType Adc_kHwUnit3_Config=
{
  &Adc_kHwUnit3Hw_Config, /*Analog Converter Configuration*/
  &Adc_kHwUnit3Ch_Config[0U], /*Channel Configuration structure*/
  &Adc_kHwUnit3Grp_Config[0U], /*Group Configuration structure*/
  0x00000001U, /* Mask for SW triggered groups*/
  0x00000000U,/* Mask for HW triggered groups*/
  ADC_SYNC_CONV_MODE_NONE, /* Synchronous conversion mode */
  { 0xffU, 0xffU, 0xffU }, /* Slave Kernels */
  1U, /* Group Count for HW Unit 3*/
  1U /* Bit Mask for SRNs used for HW Unit 3*/
};
/* MISRA2012_RULE_5_1_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
#define ADC_STOP_SEC_CONFIG_DATA_ASIL_B_CORE1_UNSPECIFIED
/* MISRA2012_RULE_20_1_JUSTIFICATION: Memmap header usage as per Autosar 
   guideline. */
/* MISRA2012_RULE_4_10_JUSTIFICATION: Memmap header is repeatedly included
   without safegaurd. It complies to Autosar guidelines. */ 
#include "Adc_MemMap.h"


/* MISRA2012_RULE_5_1_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/

#define ADC_START_SEC_CONFIG_DATA_ASIL_B_CORE0_UNSPECIFIED
/* MISRA2012_RULE_20_1_JUSTIFICATION: Memmap header usage as per Autosar 
   guideline. */
/* MISRA2012_RULE_4_10_JUSTIFICATION: Memmap header is repeatedly included
   without safegaurd. It complies to Autosar guidelines. */ 
#include "Adc_MemMap.h"
/******************Global Configuration*******************/

static const Adc_GlobalCfgType Adc_kGlob_Config=
{
  0x00000000U, /*Configuration value for GLOBCFG register */
  0x0000000aU, /*Configuration value for GLOBICLASS0 register */
  0x0000000aU, /*Configuration value for GLOBICLASS1 register */
  0x00000000U /*Configuration value for EMUXSEL register */
};
/* MISRA2012_RULE_5_1_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/

#define ADC_STOP_SEC_CONFIG_DATA_ASIL_B_CORE0_UNSPECIFIED
/* MISRA2012_RULE_20_1_JUSTIFICATION: Memmap header usage as per Autosar 
   guideline. */
/* MISRA2012_RULE_4_10_JUSTIFICATION: Memmap header is repeatedly included
   without safegaurd. It complies to Autosar guidelines. */ 
#include "Adc_MemMap.h"


/***************************Core Configuration ***************************/
/*******Core0 Configuration*******/
/* MISRA2012_RULE_5_1_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/

#define ADC_START_SEC_CONFIG_DATA_ASIL_B_CORE0_UNSPECIFIED
/* MISRA2012_RULE_20_1_JUSTIFICATION: Memmap header usage as per Autosar 
   guideline. */
/* MISRA2012_RULE_4_10_JUSTIFICATION: Memmap header is repeatedly included
   without safegaurd. It complies to Autosar guidelines. */ 
#include "Adc_MemMap.h"
static const Adc_CoreConfigType Adc_kCore0_Config=
{
  {
    (Adc_HwUnitCfgType*)0U, /* HW Unit 1 Configuration */
    (Adc_HwUnitCfgType*)0U, /* HW Unit 2 Configuration */
    (Adc_HwUnitCfgType*)0U, /* HW Unit 3 Configuration */
    (Adc_HwUnitCfgType*)0U, /* HW Unit 4 Configuration */
    (Adc_HwUnitCfgType*)0U, /* HW Unit 5 Configuration */
    (Adc_HwUnitCfgType*)0U, /* HW Unit 6 Configuration */
    (Adc_HwUnitCfgType*)0U, /* HW Unit 7 Configuration */
    (Adc_HwUnitCfgType*)0U, /* HW Unit 8 Configuration */
    (Adc_HwUnitCfgType*)0U, /* HW Unit 9 Configuration */
    (Adc_HwUnitCfgType*)0U, /* HW Unit 10 Configuration */
    (Adc_HwUnitCfgType*)0U, /* HW Unit 11 Configuration */
    (Adc_HwUnitCfgType*)0U /* HW Unit 12 Configuration */
  }
};
/* MISRA2012_RULE_5_1_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/

#define ADC_STOP_SEC_CONFIG_DATA_ASIL_B_CORE0_UNSPECIFIED
/* MISRA2012_RULE_20_1_JUSTIFICATION: Memmap header usage as per Autosar 
   guideline. */
/* MISRA2012_RULE_4_10_JUSTIFICATION: Memmap header is repeatedly included
   without safegaurd. It complies to Autosar guidelines. */ 
#include "Adc_MemMap.h"
  
/*******Core1 Configuration*******/
/* MISRA2012_RULE_5_1_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/

#define ADC_START_SEC_CONFIG_DATA_ASIL_B_CORE1_UNSPECIFIED
/* MISRA2012_RULE_20_1_JUSTIFICATION: Memmap header usage as per Autosar 
   guideline. */
/* MISRA2012_RULE_4_10_JUSTIFICATION: Memmap header is repeatedly included
   without safegaurd. It complies to Autosar guidelines. */ 
#include "Adc_MemMap.h"
static const Adc_CoreConfigType Adc_kCore1_Config=
{
  {
    &Adc_kHwUnit0_Config, /* HW Unit 1 Configuration */
    &Adc_kHwUnit1_Config, /* HW Unit 2 Configuration */
    &Adc_kHwUnit2_Config, /* HW Unit 3 Configuration */
    &Adc_kHwUnit3_Config, /* HW Unit 4 Configuration */
    (Adc_HwUnitCfgType*)0U, /* HW Unit 5 Configuration */
    (Adc_HwUnitCfgType*)0U, /* HW Unit 6 Configuration */
    (Adc_HwUnitCfgType*)0U, /* HW Unit 7 Configuration */
    (Adc_HwUnitCfgType*)0U, /* HW Unit 8 Configuration */
    (Adc_HwUnitCfgType*)0U, /* HW Unit 9 Configuration */
    (Adc_HwUnitCfgType*)0U, /* HW Unit 10 Configuration */
    (Adc_HwUnitCfgType*)0U, /* HW Unit 11 Configuration */
    (Adc_HwUnitCfgType*)0U /* HW Unit 12 Configuration */
  }
};
/* MISRA2012_RULE_5_1_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/

#define ADC_STOP_SEC_CONFIG_DATA_ASIL_B_CORE1_UNSPECIFIED
/* MISRA2012_RULE_20_1_JUSTIFICATION: Memmap header usage as per Autosar 
   guideline. */
/* MISRA2012_RULE_4_10_JUSTIFICATION: Memmap header is repeatedly included
   without safegaurd. It complies to Autosar guidelines. */ 
#include "Adc_MemMap.h"
  

/*******Configuration Root*******/ 
#define ADC_START_SEC_CONFIG_DATA_ASIL_B_GLOBAL_UNSPECIFIED
/* MISRA2012_RULE_20_1_JUSTIFICATION: Memmap header usage as per Autosar 
   guideline. */
/* MISRA2012_RULE_4_10_JUSTIFICATION: Memmap header is repeatedly included
   without safegaurd. It complies to Autosar guidelines. */ 
#include "Adc_MemMap.h"

const Adc_ConfigType Adc_Config=
{
  &Adc_kGlob_Config, /* Global Configuration */
  {
    &Adc_kCore0_Config, /* Core0 Configuration */
    &Adc_kCore1_Config, /* Core1 Configuration */
    (const Adc_CoreConfigType*)0U, /* Core2 Configuration */
    (const Adc_CoreConfigType*)0U, /* Core3 Configuration */
    (const Adc_CoreConfigType*)0U, /* Core4 Configuration */
    (const Adc_CoreConfigType*)0U /* Core5 Configuration */
  }
};


#define ADC_STOP_SEC_CONFIG_DATA_ASIL_B_GLOBAL_UNSPECIFIED
/* MISRA2012_RULE_20_1_JUSTIFICATION: Memmap header usage as per Autosar
   guideline. */
/* MISRA2012_RULE_4_10_JUSTIFICATION: Memmap header is repeatedly included
   without safegaurd. It complies to Autosar guidelines. */ 
#include "Adc_MemMap.h"


