/*  BEGIN_FILE_HDR
********************************************************************************
*   NOTICE
*   This software is the property of HiRain Technologies. Any information
*   contained in this doc should not be reproduced, or used, or disclosed
*   without the written authorization from HiRain Technologies.
********************************************************************************
*   File Name       : CanTSyn_Cbk.h
********************************************************************************
*   Project/Product : AutoSar
*   Title           : CanTSyn module call back head File
*   Author          : Hirain
********************************************************************************
*   Description     : The header file CanTSyn_Cbk.h contains the declaration of
*                     callback functions which is called by the CanTSyn module
*
********************************************************************************
*   Limitations     : None
*
********************************************************************************
*
********************************************************************************
*   Revision History:
*   Reference to Core C File
********************************************************************************
* END_FILE_HDR*/
#ifndef CANTSYN_CBK_H
#define CANTSYN_CBK_H

/*******************************************************************************
*   Includes
*******************************************************************************/
#include "CanTSyn_Types.h"

#define CANTSYN_START_SEC_CODE
#include "MemMap.h"

/*******************************************************************************
*  Global Function Declaration
*******************************************************************************/
#if(0 < CANTSYN_SYNC_SLAVE_NUM || 0 < CANTSYN_OFS_SLAVE_NUM)
extern FUNC(void, CANTSYN_CODE) CanTSyn_RxIndication
(
    PduIdType RxPduId,
    P2CONST(PduInfoType, AUTOMATIC, CANTSYN_APPL_DATA) PduInfoPtr
);
#endif
#if (0 < CANTSYN_SYNC_MASTER_NUM || 0 < CANTSYN_OFS_MASTER_NUM)
extern FUNC(void, CANTSYN_CODE) CanTSyn_TxConfirmation
(
    PduIdType TxPduId
);
#endif
#define CANTSYN_STOP_SEC_CODE
#include "MemMap.h"

#endif /*CANTSYN_CBK_H*/

