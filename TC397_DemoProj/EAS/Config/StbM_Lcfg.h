/*  BEGIN_FILE_HDR
********************************************************************************
*   File Name       : StbM_Lcfg.h
********************************************************************************
*   Project/Product : AUTOSAR BSW PROJECT
*   Title           : StbM module configuration File
*   Author          : Hirain
********************************************************************************
*   Description     : StbM module configuration File
*
********************************************************************************
*   Limitations     : None
*
********************************************************************************
*
********************************************************************************
*   Revision History:
*
*   Version     Date          Initials      CR#          Descriptions
*   ---------   ----------    ------------  ----------   ---------------
*   V1.0.0_3.5.5_AZ240046       27/03/2024    Eas           N/A          N/A
*
********************************************************************************
* END_FILE_HDR*/
#ifndef STBM_LCFG_H
#define STBM_LCFG_H
/*******************************************************************************
*   Includes
*******************************************************************************/
#include "StbM_Types.h"

#define STBM_START_SEC_CONFIG_DATA_8
#include "MemMap.h"

extern CONST(uint8, STBM_CONST) StbM_TimeBaseIdMap[(uint8)32];

#define STBM_STOP_SEC_CONFIG_DATA_8
#include "MemMap.h"

#define STBM_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "MemMap.h"


extern CONST(StbM_SynchronizedTimeBaseInfoType, STBM_CONST) StbM_SynchronizedTimeBaseInfo[STBM_NUM_OF_TIMEBASE];


#if(STBM_NUM_OF_TRIGGEREDCUSTOMER > 0)
extern CONST(StbM_TriggeredCustomerType, STBM_CONST) StbM_TriggeredCustomer[STBM_NUM_OF_TRIGGEREDCUSTOMER];
#endif

#define STBM_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "MemMap.h"



#endif /* STBM_LCFG_H */

