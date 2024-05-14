/*  BEGIN_FILE_HDR
********************************************************************************
*   File Name       : Xcp_Cfg.c
********************************************************************************
*   Project/Product : AUTOSAR BSW PROJECT
*   Title           : Xcp module configuration File
*   Author          : Hirain
********************************************************************************
*   Description     : Xcp module configuration File
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

/*******************************************************************************
*   Include files
*******************************************************************************/
#include "XcpOnEth.h"

/*******************************************************************************
*  Config Data define
*******************************************************************************/
#define XCP_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "MemMap.h"

CONST(Xcp_TpProConfigType, XCP_CONST) Xcp_TpProConfig[XCP_NUMBER_OF_SUPPORTED_PRO] =
{
    {200,200,200,4,0,&Xcp_TransmitOnEth}
};
STATIC CONST(Xcp_PduType, XCP_CONST) Xcp_Connections_0[1] =
{
    /* TxPduId, TxConPduId */
    {SoAdIf_Xcp_Tx,XCP_PRO_HANDLE_ON_ETH},
};
CONST(Xcp_ConfigType, XCP_CONST) Xcp_Config[XCP_CONFIG_NUM] =
{
    {1,&Xcp_Connections_0[0]},
};

#define XCP_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "MemMap.h"
