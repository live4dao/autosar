/*  BEGIN_FILE_HDR
********************************************************************************
*   NOTICE
*   This software is the property of HiRain Technologies. Any information
*   contained in this doc should not be reproduced, or used, or disclosed
*   without the written authorization from HiRain Technologies.
********************************************************************************
*   File Name       : DoIP_Cbk.h
********************************************************************************
*   Project/Product : DoIP Module
*   Title           : DoIP.h
*   Author          : qing.wang
********************************************************************************
*   Description     : DoIP source code call-back file
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
*   01.00.00    01/09/2017    qing.wang     N/A          Original
********************************************************************************
* END_FILE_HDR*/
#ifndef DOIP_CBK_H
#define DOIP_CBK_H

/*******************************************************************************
* Includes
*******************************************************************************/
#include "DoIP.h"

/*******************************************************************************
* API Declare
*******************************************************************************/
#define DOIP_START_SEC_CODE
#include "MemMap.h"
/* SWS_DoIP_00039 */
extern FUNC (void, DOIP_CODE) DoIP_SoConModeChg
(
    SoAd_SoConIdType SoConId,
    SoAd_SoConModeType Mode
);
/* SWS_DoIP_00244 */
extern FUNC (void, DOIP_CODE) DoIP_SoAdIfRxIndication
(
    PduIdType RxPduId,
    const PduInfoType *PduInfoPtr
);
/* SWS_DoIP_00245 */
extern FUNC (void, DOIP_CODE) DoIP_SoAdIfTxConfirmation
(
    PduIdType TxPduId
);
/* SWS_DoIP_00031 */
extern FUNC (BufReq_ReturnType, DOIP_CODE) DoIP_SoAdTpCopyTxData
(
    PduIdType id,
    const PduInfoType *info,
    RetryInfoType *retry,
    PduLengthType *AvailableDataPtr
);
/* SWS_DoIP_00033 */
extern FUNC (BufReq_ReturnType, DOIP_CODE) DoIP_SoAdTpCopyRxData
(
    PduIdType id,
    const PduInfoType *info,
    PduLengthType *bufferSizePtr
);
/* SWS_DoIP_00037 */
extern FUNC (BufReq_ReturnType, DOIP_CODE) DoIP_SoAdTpStartOfReception
(
    PduIdType id,
    const PduInfoType *info,
    PduLengthType TpSduLength,
    PduLengthType *bufferSizePtr
);
/* SWS_DoIP_00038 */
extern FUNC (void, DOIP_CODE) DoIP_SoAdTpRxIndication
(
    PduIdType id,
    Std_ReturnType result
);
/* SWS_DoIP_00040 */
extern FUNC (void, DOIP_CODE) DoIP_LocalIpAddrAssignmentChg
(
    SoAd_SoConIdType SoConId,
    TcpIp_IpAddrStateType State
);
/* SWS_DoIP_00032 */
extern FUNC (void, DOIP_CODE) DoIP_SoAdTpTxConfirmation
(
    PduIdType id,
    Std_ReturnType result
);
#define DOIP_STOP_SEC_CODE
#include "MemMap.h"

#endif/*DOIP_CBK_H*/

