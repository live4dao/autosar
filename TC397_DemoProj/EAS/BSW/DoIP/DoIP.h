/*  BEGIN_FILE_HDR
********************************************************************************
*   NOTICE
*   This software is the property of HiRain Technologies. Any information
*   contained in this doc should not be reproduced, or used, or disclosed
*   without the written authorization from HiRain Technologies.
********************************************************************************
*   File Name       : DoIP.h
********************************************************************************
*   Project/Product : DoIP Module
*   Title           : DoIP.h
*   Author          : qing.wang
********************************************************************************
*   Description     : DoIP source code header file
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
#ifndef DoIP_H
#define DoIP_H

/*******************************************************************************
* Includes
*******************************************************************************/
#include "PduR_DoIP.h"
#include "DoIP_Lcfg.h"
#include "DoIP_Types.h"
#include "DoIP_Cfg.h"
#include "SoAd.h"

#if(DOIP_HOZON_PLATFORM == DOIP_OEM_PLATFORM)
#include "DoIP_Callout.h"
#endif

/*******************************************************************************
* Macros and Typedef
*******************************************************************************/
/* DoIP API Id defines */
#define DOIP_API_ID_GET_VERSION_INFO                    ((uint8)0x00)
#define DOIP_API_ID_INIT                                ((uint8)0x01)
#define DOIP_API_ID_MAINFUNCTION                        ((uint8)0x02)
#define DOIP_API_ID_TP_TRANSMIT                         ((uint8)0x03)
#define DOIP_API_ID_TP_CANCEL_TRANSMIT                  ((uint8)0x04)
#define DOIP_API_ID_TP_CANCEL_RECEIVE                   ((uint8)0x05)
#define DOIP_API_ID_SO_CON_MODE_CHG                     ((uint8)0x0B)
#define DOIP_API_ID_LOC_IP_ADDR_ASSIGN_CHG              ((uint8)0x0C)
#define DOIP_API_ID_ACTIVATION_LINE_SWITCH              ((uint8)0x0F)
#define DOIP_API_ID_IF_TX_CONFIRMATION                  ((uint8)0x40)
#define DOIP_API_ID_IF_RX_INDICATION                    ((uint8)0x42)
#define DOIP_API_ID_TP_COPY_TX_DATA                     ((uint8)0x43)
#define DOIP_API_ID_TP_COPY_RX_DATA                     ((uint8)0x44)
#define DOIP_API_ID_TP_RX_INDICATION                    ((uint8)0x45)
#define DOIP_API_ID_TP_START_OF_RECEPTION               ((uint8)0x46)
#define DOIP_API_ID_TP_TX_CONFIRMATION                  ((uint8)0x48)
#define DOIP_API_ID_IF_TRANSMIT                         ((uint8)0x49)
#define DOIP_API_ID_IF_CANCEL_TRANSMIT                  ((uint8)0x4A)

/*******************************************************************************
* API Declare
*******************************************************************************/
#define DOIP_START_SEC_CODE
#include "MemMap.h"
/* SWS_DoIP_00026 */
extern FUNC (void, DOIP_CODE) DoIP_Init
(
    P2CONST (DoIP_ConfigType, AUTOMATIC, DOIP_CONST) DoIPConfigPtr
);
/* SWS_DoIP_00251 */
extern FUNC (void, DOIP_CODE) DoIP_ActivationLineSwitch
(
    void
);
/* SWS_DoIP_00022 */
extern FUNC (Std_ReturnType, DOIP_CODE) DoIP_TpTransmit
(
    PduIdType DoIPPduRTxId,
    const PduInfoType *DoIPPduRTxInfoPtr
);
/* SWS_DoIP_00023 */
extern FUNC (Std_ReturnType, DOIP_CODE) DoIP_TpCancelTransmit
(
    PduIdType DoIPPduRTxId
);
/* SWS_DoIP_00024 */
extern FUNC (Std_ReturnType, DOIP_CODE) DoIP_TpCancelReceive
(
    PduIdType PduRRxPduId
);
/* SWS_DoIP_00277 */
extern FUNC (Std_ReturnType, DOIP_CODE) DoIP_IfTransmit
(
    PduIdType id,
    const PduInfoType *info
);
/* SWS_DoIP_00278 */
extern FUNC (Std_ReturnType, DOIP_CODE) DoIP_IfCancelTransmit
(
    PduIdType id
);
/* SWS_DoIP_00041 */
extern FUNC (void, DOIP_CODE) DoIP_MainFunction
(
    void
);
/*SWS_DoIP_00027*/
#if(DOIP_VERSION_INFO_API == STD_ON)
extern FUNC (void, DOIP_CODE) DoIP_GetVersionInfo
(
    Std_VersionInfoType *versioninfo
);
#endif

#define DOIP_STOP_SEC_CODE
#include "MemMap.h"

#endif/*DOIP_H*/

