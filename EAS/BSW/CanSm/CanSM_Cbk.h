/*  BEGIN_FILE_HDR
********************************************************************************
*   NOTICE
*   This software is the property of HiRain Technologies. Any information
*   contained in this doc should not be reproduced, or used, or disclosed
*   without the written authorization from HiRain Technologies.
********************************************************************************
*   File Name       : CanSM_Cbk.h
********************************************************************************
*   Project/Product : AUTOSAR 4.2
*   Title           : CanSM module Header File
*   Author          : Hirain
********************************************************************************
*   Description     : CanSM module Header File
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
#ifndef CANSM_CBK_H
#define CANSM_CBK_H

/*******************************************************************************
*   Includes
*******************************************************************************/
#include "CanSM_Types.h"

/*******************************************************************************
*   API Declare
*******************************************************************************/
#define CANSM_START_SEC_CODE
#include "MemMap.h"

extern FUNC(void, CANSM_CODE) CanSM_ControllerBusOff
(
    uint8 ControllerId
);

extern FUNC(void, CANSM_CODE) CanSM_ControllerModeIndication
(
    uint8 ControllerId,
    CanIf_ControllerModeType ControllerMode
);
#if(STD_ON == CANSM_CANTRCV_SUPPORT)
extern FUNC(void, CANSM_CODE) CanSM_TransceiverModeIndication
(
    uint8 TransceiverId,
    CanTrcv_TrcvModeType TransceiverMode
);
#endif

#if(STD_ON == CANSM_ICOM_SUPPORT)/*SWS_CanSM_00599*/
extern FUNC(void, CANSM_CODE) CanSM_CurrentIcomConfiguration
(
    uint8 ControllerId,
    IcomConfigIdType ConfigurationId,
    IcomSwitch_ErrorType Error
);
#endif

#if(STD_ON == CANSM_PNC_SUPPORT)
#if(STD_ON == CANSM_CANTRCV_SUPPORT)
extern FUNC(void, CANSM_CODE) CanSM_ClearTrcvWufFlagIndication
(
    uint8 Transceiver
);
extern FUNC(void, CANSM_CODE) CanSM_CheckTransceiverWakeFlagIndication
(
    uint8 Transceiver
);
extern FUNC(void, CANSM_CODE) CanSM_ConfirmPnAvailability
(
    uint8 TransceiverId
);
#endif
#endif

#define CANSM_STOP_SEC_CODE
#include "MemMap.h"

#endif /*#ifndef CANSM_CBK_H*/

