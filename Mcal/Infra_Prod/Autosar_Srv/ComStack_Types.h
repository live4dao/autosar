/*******************************************************************************
**                                                                            **
** Copyright (C) Infineon Technologies (2020)                                 **
**                                                                            **
** All rights reserved.                                                       **
**                                                                            **
** This document contains proprietary information belonging to Infineon       **
** Technologies. Passing on and copying of this document, and communication   **
** of its contents is not permitted without prior written authorization.      **
**                                                                            **
********************************************************************************
**                                                                            **
**  FILENAME     : ComStack_Types.h                                           **
**                                                                            **
**  VERSION      : 4.0.0                                                      **
**                                                                            **
**  DATE         : 2020-06-28                                                 **
**                                                                            **
**  VARIANT      : NA                                                         **
**                                                                            **
**  PLATFORM     : Infineon AURIX2G                                           **
**                                                                            **
**  AUTHOR       : DL-AUTOSAR-Engineering                                     **
**                                                                            **
**  VENDOR       : Infineon Technologies                                      **
**                                                                            **
**  DESCRIPTION  : Type Definition for Com Stack                              **
**                                                                            **
**  SPECIFICATION(S) : AUTOSAR_SWS_CommunicationStackTypes.pdf, AUTOSAR       **
**                     Release 4.2.2 and 4.4.0                                **
**                                                                            **
**  MAY BE CHANGED BY USER : yes                                              **
**                                                                            **
*******************************************************************************/
/* Traceability:
 [cover parentID={6EFE97CB-F5F0-460e-B4C5-1D143599991E}]
 Files inclusion
 [/cover]*/

#ifndef COMSTACK_TYPES_H
#define COMSTACK_TYPES_H

/*****************************************************************************
**                      Include Section                                     **
*****************************************************************************/
/* Traceability:
 [cover parentID={B6DD2FBA-E4D7-4e6f-9065-124B8D8B5F50}]
 [/cover]*/
#include "Std_Types.h"                  /* standard AUTOSAR types           */
//#include "ComStack_Cfg.h"
#include "ComStack_Types_Cfg.h"
#include "McalLib.h"

/*****************************************************************************
**                      Global Symbols                                      **
*****************************************************************************/

/*****************************************************************************
**                      Global Data Types (ECU independent)                 **
*****************************************************************************/
/* The Icom configuration ID */
typedef uint8  IcomConfigIdType;
/* The type for errors which can occur when activating or
deactivating Pretended Networking. */
typedef enum
{
  ICOM_SWITCH_E_OK,
  ICOM_SWITCH_E_FAILED
} IcomSwitch_ErrorType;

/* Used to store the identifier of a partial network cluster. */
/*typedef uint8  PNCHandleType;
typedef uint8 NetworkHandleType;*/

/* Variables of this type shall be used to return the bus status
   evaluated by a transceiver. */
typedef uint8  BusTrcvErrorType;
#define BUSTRCV_OK ((BusTrcvErrorType)0x00u)
#define BUSTRCV_E_ERROR ((BusTrcvErrorType)0x01u)

#if (MCAL_AR_VERSION == MCAL_AR_422)
/* Basic information about a PDU of any type */
typedef struct
{
  uint8          *SduDataPtr;
  PduLengthType   SduLength;
} PduInfoType;
#else
  /* Basic information about a PDU of any type */
#if 0
typedef struct
{
  uint8          *SduDataPtr;
  uint8          *MetaDataPtr;
  PduLengthType   SduLength;
} PduInfoType;
#endif
#endif

/* Variables of this type shall be used to store the result of a buffer request. */
typedef enum
{
  BUFREQ_OK,
  BUFREQ_E_NOT_OK,
  BUFREQ_E_BUSY,
  BUFREQ_E_OVFL
} BufReq_ReturnType;

/* Added by Hirain for EAS-422_BSW */
typedef uint8    NotifResultType;
/*General return codes for NotifResultType*/

/*Action has been successfully finished:
- message sent out (in case of confirmation),
- message received (in case of indication) */
#define NTFRSLT_OK                       ((NotifResultType)0x00)
/*Error notification:
- message not successfully sent out (in case of confirmation),
- message not successfully received (in case of indication) */
#define NTFRSLT_E_NOT_OK                 ((NotifResultType)0x01)
/*Error notification:
- timer N_Ar/N_As (according to ISO specification [ISONM]) has passed its
time-out value N_Asmax/N_Armax.This value can be issued to service user on
both the sender and receiver side. */
#define NTFRSLT_E_TIMEOUT_A              ((NotifResultType)0x02)
/*Error notification:
- timer N_Bs has passed its time-out value N_Bsmax (according to ISO
specification [ISONM]).This value can be issued to the service user on the
sender side only. */
#define NTFRSLT_E_TIMEOUT_BS             ((NotifResultType)0x03)
/*Error notification:
- timer N_Cr has passed its time-out value N_Crmax.
This value can be issued to the service user on the receiver side only. */
#define NTFRSLT_E_TIMEOUT_CR             ((NotifResultType)0x04)
/*Error notification:
- unexpected sequence number (PCI.SN) value received.
This value can be issued to the service user on the receiver side only. */
#define NTFRSLT_E_WRONG_SN               ((NotifResultType)0x05)
/*Error notification:
- invalid or unknown FlowStatus value has been received in a flow control
(FC) N_PDU.
This value can be issued to the service user on the sender side only. */
#define NTFRSLT_E_INVALID_FS             ((NotifResultType)0x06)
/*Error notification:
- unexpected protocol data unit received.
This value can be issued to the service user on both the sender and
receiver side. */
#define NTFRSLT_E_UNEXP_PDU              ((NotifResultType)0x07)
/*Error notification:
- flow control WAIT frame that exceeds the maximum counter N_WFTmax received.
This value can be issued to the service user on the receiver side. */
#define NTFRSLT_E_WFT_OVRN               ((NotifResultType)0x08)
/*Error notification:
Flow control (FC) N_PDU with FlowStatus = ABORT received. It indicates an abort
of a transmission. A possible reason for this is that the receiver is currently
busy and can not take the request at that point in time.*/
#define NTFRSLT_E_ABORT                  ((NotifResultType)0x09)
/*Error notification:
- flow control (FC) N_PDU with FlowStatus = OVFLW received.
  It indicates that the buffer on the receiver side of a segmented message
  transmission cannot store the number of bytes specified by the FirstFrame
  DataLength (FF_DL) parameter in the FirstFrame and therefore the transmission
  of the 19 of 23 AUTOSAR_SWS_ComStackTypes segmented message was aborted.
- no buffer within the TP available to transmit the segmented I-PDU.
This value can be issued to the service user on both the sender and receiver
side. */
#define NTFRSLT_E_NO_BUFFER              ((NotifResultType)0x0A)
/*Action has been successfully finished:
- Requested cancellation has been executed.*/
#define NTFRSLT_E_CANCELATION_OK         ((NotifResultType)0x0B)
/*Error notification:
- Due to an internal error the requested cancelation has not been executed.
This will happen e.g., if the to be canceled transmission has been executed
already.*/
#define NTFRSLT_E_CANCELATION_NOT_OK     ((NotifResultType)0x0C)
/*The parameter change request has been successfully executed */
#define NTFRSLT_PARAMETER_OK             ((NotifResultType)0x0D)
/*The request for the change of the parameter did not complete successfully*/
#define NTFRSLT_E_PARAMETER_NOT_OK       ((NotifResultType)0x0E)
/*The parameter change request not executed successfully due to an ongoing
reception*/
#define NTFRSLT_E_RX_ON                  ((NotifResultType)0x0F)
/*The parameter change request not executed successfully due to a wrong value*/
#define NTFRSLT_E_VALUE_NOT_OK           ((NotifResultType)0x10)

#define NTFRSLT_E_CAN_WRONG_CFDL         ((NotifResultType)0x11)
/* 0x12-0x1E Reserved values for  future usage. */

typedef P2VAR(uint8, TYPEDEF, TYPEDEF) SduDataPtrType;
typedef struct
{
    SduDataPtrType SduDataPtr;
    PduLengthType   SduLength;
} PduInfoType;

typedef enum
{
    TP_STMIN,            /*Separation Time*/
    TP_BS,               /*Block Size*/
    TP_BC                /*The Band width control parameter used in FlexRay
                           transport protocol module.*/
} TPParameterType;

typedef enum
{
    TP_DATACONF,     /*indicates that all data, that have been copied so far,
                     are confirmed and can be removed from the TP buffer.
                     Data copied by this API call are excluded and will be
                     confirmed later.*/
    TP_DATARETRY,    /*indicates that this API call shall copy already copied
                     data in order to recover from an error. In this case
                     TxTpDataCnt specifies the offset of the first byte to be
                     copied by the API call.*/
    TP_CONFPENDING   /*indicates that the previously copied data must remain
                     in the TP*/
} TpDataStateType;

typedef struct
{
    TpDataStateType TpDataState;
    PduLengthType TxTpDataCnt;
} RetryInfoType;

/*****************************************************************************
**                      Global Data                                         **
*****************************************************************************/


/*****************************************************************************
**                      Global Functions                                    **
*****************************************************************************/


#endif /* COMSTACK_TYPES_H */
