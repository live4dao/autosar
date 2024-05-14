/*  BEGIN_FILE_HDR
********************************************************************************
*   File Name       : PduR_PBcfg.h
********************************************************************************
*   Project/Product : AUTOSAR BSW PROJECT
*   Title           : PduR module configuration File
*   Author          : Hirain
********************************************************************************
*   Description     : PduR module configuration File
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
#ifndef PDUR_PBCFG_H
#define PDUR_PBCFG_H

/*******************************************************************************
*   Includes
*******************************************************************************/
#include "PduR_Types.h"

#define PDUR_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "MemMap.h"
extern CONST(PduRRoutingPathInfoType, PDUR_CONST) PduRRoutingTable[PDUR_NUMPDURROUTPATH];


extern CONST(PduRRoutingPduInfoType, PDUR_CONST) PduRComTxPduInfo[PDUR_NUMOFCOMTXPDU];


extern CONST(PduRRoutingPduInfoType, PDUR_CONST) PduRDcmTxPduInfo[PDUR_NUMOFDCMTXPDU];









extern CONST(PduRRoutingPduInfoType, PDUR_CONST) PduRCanIfRxPduInfo[PDUR_NUMOFCANIFRXPDU];




extern CONST(PduRRoutingPduInfoType, PDUR_CONST) PduRCanTpRxPduInfo[PDUR_NUMOFCANTPRXPDU];







extern CONST(PduRRoutingPduInfoType, PDUR_CONST) PduRSoAdIfRxPduInfo[PDUR_NUMOFSOADIFRXPDU];



extern CONST(PduRRoutingPduInfoType, PDUR_CONST) PduRDoIPTpRxPduInfo[PDUR_NUMOFDOIPTPRXPDU];








extern CONST(PduRTxConfMapping_Type, PDUR_CONST)  PduRCanIfTxConfPduInfo[PDUR_NUMOFCANIFTXPDU];




extern CONST(PduRTxConfMapping_Type, PDUR_CONST)  PduRCanTpTxConfPduInfo[PDUR_NUMOFCANTPTXPDU];









extern CONST(PduRTxConfMapping_Type, PDUR_CONST)  PduRSoAdIfTxConfPduInfo[PDUR_NUMOFSOADIFTXPDU];




extern CONST(PduRTxConfMapping_Type, PDUR_CONST)  PduRDoIPTpTxConfPduInfo[PDUR_NUMOFDOIPTPTXPDU];






extern CONST(PduRRxCancelMapping_Type, PDUR_CONST) PduRDcmCancelRxPduInfo[PDUR_NUMOFDCMRXPDU];





#define PDUR_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "MemMap.h"

#endif


