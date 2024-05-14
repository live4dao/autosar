/*  BEGIN_FILE_HDR
********************************************************************************
*   File Name       : Nm_Callout.h
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

#ifndef NM_CALLOUT_H
#define NM_CALLOUT_H

/*******************************************************************************
*   Includes
*******************************************************************************/
#include "NmStack_Types.h"

#define NM_START_SEC_CODE
#include "MemMap.h"

extern FUNC(void, NM_CODE) Nm_PduRxIndication_Callout
(
    CONST(NetworkHandleType, NMIF_CONST) nmNetworkHandle
);
extern FUNC(void, NM_CODE) Nm_StateChangeIndCallout
(
    CONST(NetworkHandleType, NMIF_CONST) nmNetworkHandle,
    CONST(Nm_StateType, NMIF_CONST) nmPreviousState,
    CONST(Nm_StateType, NMIF_CONST) nmCurrentState
);

#define NM_STOP_SEC_CODE
#include "MemMap.h"

#endif



