/*  BEGIN_FILE_HDR
********************************************************************************
*   NOTICE
*   This software is the property of HiRain Technologies. Any information
*   contained in this doc should not be reproduced, or used, or disclosed
*   without the written authorization from HiRain Technologies.
********************************************************************************
*   File Name       : Nm_Cbk.h
********************************************************************************
*   Project/Product : AUTOSAR 4.2
*   Title           : Nm Callback module Source File
*   Author          : Hirain
********************************************************************************
*   Description     : Callback header file of the AUTOSAR NM.
*                     The header file contains the declaration of the API used
*                     by BusNm module.
********************************************************************************
*   Limitations     :
*
********************************************************************************
*
********************************************************************************
*   Revision History:
*   Reference to Core C File
********************************************************************************
* END_FILE_HDR*/
#ifndef NM_CBK_H
#define NM_CBK_H

/*******************************************************************************
*  General QAC Suppression
*******************************************************************************/
/*PRQA S 3614,3214,0862 EOF*/
/*
According to the requirements of AUTOSAR Specification,when locating address 
segments in the files of each module,#include "MemMap.h" is required.Defined 
XXX_START_SEC_ will undefine in MemMap.h
*/

/*******************************************************************************
*   Includes
*******************************************************************************/
#include "NmStack_Types.h"
#include "Nm_Version.h"
#include "Nm_Lcfg.h"

/*******************************************************************************
* Prototypes of export functions
*******************************************************************************/
#define NM_START_SEC_CODE
#include "MemMap.h"

extern FUNC(void, NM_CODE) Nm_NetworkStartIndication
(
    CONST(NetworkHandleType, NMIF_CONST) nmNetworkHandle
);

extern FUNC(void, NM_CODE) Nm_NetworkMode
(
    CONST(NetworkHandleType, NMIF_CONST) nmNetworkHandle
);

extern FUNC(void, NM_CODE) Nm_BusSleepMode
(
    CONST(NetworkHandleType, NMIF_CONST) nmNetworkHandle
);

extern FUNC(void, NM_CODE) Nm_PrepareBusSleepMode
(
    CONST(NetworkHandleType, NMIF_CONST) nmNetworkHandle
);

extern FUNC(void, NM_CODE) Nm_RemoteSleepIndication
(
    CONST(NetworkHandleType, NMIF_CONST) nmNetworkHandle
);

extern FUNC(void, NM_CODE) Nm_RemoteSleepCancellation
(
    CONST(NetworkHandleType, NMIF_CONST) nmNetworkHandle
);

extern FUNC(void, NM_CODE) Nm_SynchronizationPoint
(
    CONST(NetworkHandleType, NMIF_CONST) nmNetworkHandle
);

#if(STD_ON == NM_PDU_RXINDICATION_ENABLED)
extern FUNC(void, NM_CODE) Nm_PduRxIndication
(
    CONST(NetworkHandleType, NMIF_CONST) nmNetworkHandle
);
#endif

#if(STD_ON == NM_STATE_CHANGE_IND_ENABLED)
extern FUNC(void, NM_CODE) Nm_StateChangeNotification
(
    CONST(NetworkHandleType, NMIF_CONST) nmNetworkHandle,
    CONST(Nm_StateType, NMIF_CONST) nmPreviousState,
    CONST(Nm_StateType, NMIF_CONST) nmCurrentState
);
#endif


#if(STD_ON == NM_REPEAT_MSG_IND_ENABLED)
extern FUNC(void, NM_CODE) Nm_RepeatMessageIndication
(
    CONST(NetworkHandleType, NMIF_CONST) nmNetworkHandle
);
#endif


extern FUNC(void, NM_CODE) Nm_TxTimeoutException
(
    CONST(NetworkHandleType, NMIF_CONST) nmNetworkHandle
);

#if(STD_ON == NM_CAR_WAKEUP_RX_ENABLED)
extern FUNC(void, NM_CODE) Nm_CarWakeUpIndication
(
    CONST(NetworkHandleType, NMIF_CONST) nmNetworkHandle
);
#endif

extern FUNC(void, NM_CODE) Nm_CoordReadyToSleepIndication
(
    CONST(NetworkHandleType, NMIF_CONST) nmNetworkHandle
);

#define NM_STOP_SEC_CODE
#include "MemMap.h"

#endif/* _NM_CBK_H_ */


