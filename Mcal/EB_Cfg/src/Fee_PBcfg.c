/*******************************************************************************
**                                                                            **
** Copyright (C) Infineon Technologies (2021)                                 **
**                                                                            **
** All rights reserved.                                                       **
**                                                                            **
** This document contains proprietary information belonging to Infineon       **
** Technologies. Passing on and copying of this document, and communication   **
** of its contents is not permitted without prior written authorization.      **
**                                                                            **
********************************************************************************
**                                                                            **
**  FILENAME    : Fee_PBCfg.c                                                 **
**                                                                            **
**  VERSION     : 12.0.0                                                      **
**                                                                            **
**  DATE, TIME  : 2024-04-30, 14:47:58   !!!IGNORE-LINE!!!                **
**                                                                            **
**  GENERATOR   : Build b191017-0938                                        **
**                                                                            **
**  BSW MODULE DECRIPTION : Fee.bmd                                           **
**                                                                            **
**  VARIANT     : Variant PB                                                  **
**                                                                            **
**  PLATFORM    : Infineon AURIX2G                                            **
**                                                                            **
**  AUTHOR      : DL-AUTOSAR-Engineering                                      **
**                                                                            **
**  VENDOR      : Infineon Technologies                                       **
**                                                                            **
**  DESCRIPTION :  Fee configuration generated out of ECUC file               **
**                                                                            **
**  SPECIFICATION(S) : Specification of Fee Driver,                           **
**                     AUTOSAR Release 4.2.2 and 4.4.0                        **
**                                                                            **
**  MAY BE CHANGED BY USER : no                                               **
**                                                                            **
*******************************************************************************/


/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
/* Include Fee Module Header File */
#include "Fee.h"
/*******************************************************************************
**                      Imported Compiler Switch Checks                       **
*******************************************************************************/

/*******************************************************************************
**                      Private Macro Definitions                             **
*******************************************************************************/

/*******************************************************************************
**                      Private Type Definitions                              **
*******************************************************************************/

/*******************************************************************************
**                      Private Function Declarations                         **
*******************************************************************************/

/*******************************************************************************
**                      Global Function Declarations                          **
*******************************************************************************/

/*******************************************************************************
**                      Global Constant Definitions                           **
*******************************************************************************/
/* Allocate space for state data variables in RAM */
#define FEE_START_SEC_VAR_CLEARED_ASIL_B_LOCAL_UNSPECIFIED
/*MISRA2012_RULE_4_10_JUSTIFICATION: Memmap header is repeatedly included
without safegaurd. It complies to Autosar guidelines. */
/*MISRA2012_RULE_20_1_JUSTIFICATION: Memmap header usage as per Autosar
guideline. */
#include "Fee_MemMap.h"

/* Fee State Variable structure */
/*MISRA2012_RULE_8_7_JUSTIFICATION: Fee_StateVar has not been declared as static
as this structure is being passed to the Fee.c file. It has scope beyond the 
file.*/
/*MISRA2012_RULE_8_4_JUSTIFICATION: MISRA is assuming as a function but it 
branches out as assembly equivalent or compiler routine..*/
Fee_StateDataType Fee_StateVar;
#define FEE_STOP_SEC_VAR_CLEARED_ASIL_B_LOCAL_UNSPECIFIED
/*MISRA2012_RULE_4_10_JUSTIFICATION: Memmap header is repeatedly included
without safegaurd. It complies to Autosar guidelines. */
/*MISRA2012_RULE_20_1_JUSTIFICATION: Memmap header usage as per Autosar
guideline. */
#include "Fee_MemMap.h"


/* User configured logical block initialization structure */
#define FEE_START_SEC_CONFIG_DATA_ASIL_B_LOCAL_UNSPECIFIED
/*MISRA2012_RULE_4_10_JUSTIFICATION: Memmap header is repeatedly included
without safegaurd. It complies to Autosar guidelines. */
/*MISRA2012_RULE_20_1_JUSTIFICATION: Memmap header usage as per Autosar
guideline. */
#include "Fee_MemMap.h"
/*[cover parentID={01870B59-CB19-45ea-8F7F-F16AC029FB7A}][/cover]*/ 
static const Fee_BlockType Fee_BlockConfig[] =
{
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_NORMAL_DATA,  /* Block type is Normal */
    2U, /* Block number */
    3U, /* Fee Block Size */
/*MISRA2012_RULE_10_3_JUSTIFICATION: Exception MISRA 10_3 is not applicable
to the initializer {0} which may be used to initialize an aggregate.
Here it is defined as enum and first element initialized to 0.
*/
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_NORMAL_DATA,  /* Block type is Normal */
    3U, /* Block number */
    3U, /* Fee Block Size */
/*MISRA2012_RULE_10_3_JUSTIFICATION: Exception MISRA 10_3 is not applicable
to the initializer {0} which may be used to initialize an aggregate.
Here it is defined as enum and first element initialized to 0.
*/
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_NORMAL_DATA,  /* Block type is Normal */
    4U, /* Block number */
    9449U, /* Fee Block Size */
/*MISRA2012_RULE_10_3_JUSTIFICATION: Exception MISRA 10_3 is not applicable
to the initializer {0} which may be used to initialize an aggregate.
Here it is defined as enum and first element initialized to 0.
*/
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_NORMAL_DATA,  /* Block type is Normal */
    6U, /* Block number */
    18U, /* Fee Block Size */
/*MISRA2012_RULE_10_3_JUSTIFICATION: Exception MISRA 10_3 is not applicable
to the initializer {0} which may be used to initialize an aggregate.
Here it is defined as enum and first element initialized to 0.
*/
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_NORMAL_DATA,  /* Block type is Normal */
    8U, /* Block number */
    17U, /* Fee Block Size */
/*MISRA2012_RULE_10_3_JUSTIFICATION: Exception MISRA 10_3 is not applicable
to the initializer {0} which may be used to initialize an aggregate.
Here it is defined as enum and first element initialized to 0.
*/
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_NORMAL_DATA,  /* Block type is Normal */
    10U, /* Block number */
    2U, /* Fee Block Size */
/*MISRA2012_RULE_10_3_JUSTIFICATION: Exception MISRA 10_3 is not applicable
to the initializer {0} which may be used to initialize an aggregate.
Here it is defined as enum and first element initialized to 0.
*/
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_NORMAL_DATA,  /* Block type is Normal */
    12U, /* Block number */
    2U, /* Fee Block Size */
/*MISRA2012_RULE_10_3_JUSTIFICATION: Exception MISRA 10_3 is not applicable
to the initializer {0} which may be used to initialize an aggregate.
Here it is defined as enum and first element initialized to 0.
*/
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_NORMAL_DATA,  /* Block type is Normal */
    14U, /* Block number */
    3U, /* Fee Block Size */
/*MISRA2012_RULE_10_3_JUSTIFICATION: Exception MISRA 10_3 is not applicable
to the initializer {0} which may be used to initialize an aggregate.
Here it is defined as enum and first element initialized to 0.
*/
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_NORMAL_DATA,  /* Block type is Normal */
    16U, /* Block number */
    8U, /* Fee Block Size */
/*MISRA2012_RULE_10_3_JUSTIFICATION: Exception MISRA 10_3 is not applicable
to the initializer {0} which may be used to initialize an aggregate.
Here it is defined as enum and first element initialized to 0.
*/
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_NORMAL_DATA,  /* Block type is Normal */
    18U, /* Block number */
    2U, /* Fee Block Size */
/*MISRA2012_RULE_10_3_JUSTIFICATION: Exception MISRA 10_3 is not applicable
to the initializer {0} which may be used to initialize an aggregate.
Here it is defined as enum and first element initialized to 0.
*/
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_NORMAL_DATA,  /* Block type is Normal */
    20U, /* Block number */
    17U, /* Fee Block Size */
/*MISRA2012_RULE_10_3_JUSTIFICATION: Exception MISRA 10_3 is not applicable
to the initializer {0} which may be used to initialize an aggregate.
Here it is defined as enum and first element initialized to 0.
*/
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_NORMAL_DATA,  /* Block type is Normal */
    21U, /* Block number */
    17U, /* Fee Block Size */
/*MISRA2012_RULE_10_3_JUSTIFICATION: Exception MISRA 10_3 is not applicable
to the initializer {0} which may be used to initialize an aggregate.
Here it is defined as enum and first element initialized to 0.
*/
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_NORMAL_DATA,  /* Block type is Normal */
    22U, /* Block number */
    2U, /* Fee Block Size */
/*MISRA2012_RULE_10_3_JUSTIFICATION: Exception MISRA 10_3 is not applicable
to the initializer {0} which may be used to initialize an aggregate.
Here it is defined as enum and first element initialized to 0.
*/
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_NORMAL_DATA,  /* Block type is Normal */
    24U, /* Block number */
    2U, /* Fee Block Size */
/*MISRA2012_RULE_10_3_JUSTIFICATION: Exception MISRA 10_3 is not applicable
to the initializer {0} which may be used to initialize an aggregate.
Here it is defined as enum and first element initialized to 0.
*/
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_NORMAL_DATA,  /* Block type is Normal */
    26U, /* Block number */
    2U, /* Fee Block Size */
/*MISRA2012_RULE_10_3_JUSTIFICATION: Exception MISRA 10_3 is not applicable
to the initializer {0} which may be used to initialize an aggregate.
Here it is defined as enum and first element initialized to 0.
*/
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_NORMAL_DATA,  /* Block type is Normal */
    27U, /* Block number */
    268U, /* Fee Block Size */
/*MISRA2012_RULE_10_3_JUSTIFICATION: Exception MISRA 10_3 is not applicable
to the initializer {0} which may be used to initialize an aggregate.
Here it is defined as enum and first element initialized to 0.
*/
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_NORMAL_DATA,  /* Block type is Normal */
    28U, /* Block number */
    7U, /* Fee Block Size */
/*MISRA2012_RULE_10_3_JUSTIFICATION: Exception MISRA 10_3 is not applicable
to the initializer {0} which may be used to initialize an aggregate.
Here it is defined as enum and first element initialized to 0.
*/
  },
};
const Fee_ConfigType Fee_Config =
{  
  /* Fee State Data Structure */
  &Fee_StateVar,
  /* Pointer to logical block configurations */
  &Fee_BlockConfig[0],

  /* Fee Job end notification API */
  &NvM_JobEndNotification,

  /* Fee Job error notification API */
  &NvM_JobErrorNotification,

/*MISRA2012_RULE_11_3_JUSTIFICATION:  The warning is coming for NULL_PTR defined by 
AUTOSAR. The function pointer is being allocated NULL_PTR as the particular 
function will not be required. The function is correctly getting assigned to NULL VALUE*/
/*MISRA2012_RULE_11_3_JUSTIFICATION:  The warning is coming for NULL_PTR defined by 
AUTOSAR. The function pointer is being allocated NULL_PTR as the particular 
function will not be required. The function is correctly getting assigned to NULL VALUE*/
  /* Fee threshold value */
  10240U,
  /* Number of blocks configured */
  17U,
  {
    /* Ignore the unconfigured blocks */
    FEE_UNCONFIG_BLOCK_IGNORE,
    /* Restart Garbage Collection during initialization */
    FEE_GC_RESTART_INIT,
    /* Erase Suspend feature is disabled */
    FEE_ERASE_SUSPEND_DISABLED,
    
    /* Reserved */
    0U
  },


/*MISRA2012_RULE_11_3_JUSTIFICATION: Pointers are accessing the correct memory 
range locations. Out of bounds checks were checked during functional verification. */
  
  /* Fee NVM Illegal State notification */
  (Fee_NotifFunctionPtrType)NULL_PTR,

/*MISRA2012_RULE_11_3_JUSTIFICATION: Pointers are accessing the correct memory 
range locations. Out of bounds checks were checked during functional verification. */
  
  /* Fee QS Illegal State notification */
  (Fee_NotifFunctionPtrType)NULL_PTR,
/*MISRA2012_RULE_11_3_JUSTIFICATION: Pointers are accessing the correct memory 
range locations. Out of bounds checks were checked during functional verification. */
  /* QS Hardening Error notification */
  (Fee_NotifFunctionPtrType)NULL_PTR,
  /* Erase All feature is enabled */
  (boolean)TRUE

};

#define FEE_STOP_SEC_CONFIG_DATA_ASIL_B_LOCAL_UNSPECIFIED
/*MISRA2012_RULE_4_10_JUSTIFICATION: Memmap header is repeatedly included
without safegaurd. It complies to Autosar guidelines. */
/*MISRA2012_RULE_20_1_JUSTIFICATION: Memmap header usage as per Autosar
guideline. */
#include "Fee_MemMap.h"
