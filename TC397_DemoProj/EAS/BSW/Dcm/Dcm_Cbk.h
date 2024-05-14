/*  BEGIN_FILE_HDR
********************************************************************************
*   NOTICE
*   This software is the property of HiRain Technologies. Any information
*   contained in this doc should not be reproduced, or used, or disclosed
*   without the written authorization from HiRain Technologies.
********************************************************************************
*   File Name       : Dcm_Cbk.h
********************************************************************************
*   Project/Product : AUTOSAR 4.2
*   Title           : Dcm_Cbk.h
*   Author          : Hirain
********************************************************************************
*   Description: Callback header file of the AUTOSAR Dcm Module.
*
********************************************************************************
*   Limitations: None
*
********************************************************************************
*
********************************************************************************
*   Revision History:
*   Reference to Core C File
********************************************************************************
* END_FILE_HDR */

#ifndef DCM_CBK_H
#define DCM_CBK_H

/*******************************************************************************
* Include files
*******************************************************************************/
#include "Dcm_Types.h"
#include "Dcm_Version.h"

/*******************************************************************************
* Global Function Prototype
*******************************************************************************/
#define DCM_START_SEC_CODE
#include "MemMap.h"

/*SWS_Dcm_00094*/
extern FUNC(BufReq_ReturnType, DCM_CODE) Dcm_StartOfReception
(
    PduIdType id,
    P2CONST(PduInfoType, AUTOMATIC, DCM_APPL_DATA) info,
    PduLengthType TpSduLength,
    P2VAR(PduLengthType, AUTOMATIC, DCM_APPL_DATA) bufferSizePtr
);

/*SWS_Dcm_00556*/
extern FUNC(BufReq_ReturnType, DCM_CODE) Dcm_CopyRxData
(
    PduIdType id,
    P2CONST(PduInfoType, AUTOMATIC, DCM_APPL_DATA) info,
    P2VAR(PduLengthType, AUTOMATIC, DCM_APPL_DATA) bufferSizePtr
);

/*SWS_Dcm_00093*/
extern FUNC(void, DCM_CODE) Dcm_TpRxIndication
(
    PduIdType id,
    Std_ReturnType result
);

/*SWS_Dcm_00092*/
extern FUNC(BufReq_ReturnType, DCM_CODE) Dcm_CopyTxData
(
    PduIdType id,
    P2CONST(PduInfoType, AUTOMATIC, DCM_APPL_DATA) info,
    P2VAR(RetryInfoType, AUTOMATIC, DCM_APPL_DATA) retry,
    P2VAR(PduLengthType, AUTOMATIC, DCM_APPL_DATA) availableDataPtr
);

/*SWS_Dcm_00351*/
extern FUNC(void, DCM_CODE) Dcm_TpTxConfirmation
(
    PduIdType id,
    Std_ReturnType result
);

/*SWS_Dcm_01092*/
extern FUNC(void, DCM_CODE) Dcm_TxConfirmation
(
    PduIdType TxPduId
);

#define DCM_STOP_SEC_CODE
#include "MemMap.h"


#define DCM_START_SEC_CODE
#include "MemMap.h"

#if(DCM_COMM_SUPPORT == STD_ON)
/*SWS_Dcm_00356*/
extern FUNC(void, DCM_CODE) Dcm_ComM_NoComModeEntered
(
    uint8 NetworkId
);

/*SWS_Dcm_00358*/
extern FUNC(void, DCM_CODE) Dcm_ComM_SilentComModeEntered
(
    uint8 NetworkId
);

/*SWS_Dcm_00360*/
extern FUNC(void, DCM_CODE) Dcm_ComM_FullComModeEntered
(
    uint8 NetworkId
);
#endif/*(DCM_COMM_SUPPORT == STD_ON)*/

#define DCM_STOP_SEC_CODE
#include "MemMap.h"


#endif/*DCM_CBK_H*/


