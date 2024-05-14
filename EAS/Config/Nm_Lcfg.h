/*  BEGIN_FILE_HDR
********************************************************************************
*   File Name       : Nm_Lcfg.h
********************************************************************************
*   Project/Product : AUTOSAR BSW PROJECT
*   Title           : Nm module configuration File
*   Author          : Hirain
********************************************************************************
*   Description     : Nm module configuration File
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

#ifndef NM_LCFG_H
#define NM_LCFG_H
/*******************************************************************************
*   Includes
*******************************************************************************/
#include "NmStack_Types.h"
#include "ComM_Nm.h"
#include "CanNm.h"
#include "UdpNm.h"

#define NM_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "MemMap.h"

extern CONST(Nm_ChannelConfigType, NM_CONST) Nm_ChannelCfg[NM_NUM_OF_CHANNELS];

#define NM_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "MemMap.h"



#endif /* NM_LCFG_H */

