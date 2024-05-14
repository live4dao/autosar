/*  BEGIN_FILE_HDR
********************************************************************************
*   NOTICE                             
*   This software is the property of HiRain Technologies. Any information
*   contained in this doc should not be reproduced, or used, or disclosed
*   without the written authorization from HiRain Technologies.
********************************************************************************
*   File Name       : TcpIp_Cbk.h
********************************************************************************
*   Project/Product : AUTOSAR 4.2
*   Title           : The TcpIp Stack
*   Author          : mingqing.tang
********************************************************************************
*   Description     : The header file TcpIp_Cbk.h contains the declaration of the
*                     callback of the TcpIp module.
*                                           
********************************************************************************
*   Limitations     : only used for AUTOSAR 4.2 version
*
********************************************************************************
*
********************************************************************************
*   Revision History:
*
*   Version     Date          Initials        CR#          Descriptions
*   ---------   ----------    -------------   ----------   ---------------
*   01.00.00    21/09/2016    mingqing.tang   N/A          Original
*   02.00.00    21/05/2018    mingqing.tang   N/A          AUTOSAR V4.2.2
*   02.01.00    25/06/2018    mingqing.tang   N/A          Enable DHCP, AutoIP
********************************************************************************
* END_FILE_HDR*/
#ifndef _TCPIP_CBK_H_
#define _TCPIP_CBK_H_
/*******************************************************************************
*   Includes
*******************************************************************************/
#include "EthIf.h"

/*******************************************************************************
*   Macro
*******************************************************************************/
/*SWS_TCPIP_00029*/
FUNC(void, TCPIP_CODE) TcpIp_RxIndication
(
    uint8 CtrlIdx,
    Eth_FrameType FrameType,
    boolean IsBroadcast,
    P2CONST(uint8, AUTOMATIC, AUTOMATIC) PhysAddrPtr,
    P2VAR(uint8, AUTOMATIC, AUTOMATIC) DataPtr,
    uint16 LenByte
);

#endif /* _TCPIP_CBK_H_ */
