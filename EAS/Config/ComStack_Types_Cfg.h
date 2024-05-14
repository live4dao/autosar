/*  BEGIN_FILE_HDR
********************************************************************************
*   File Name       : ComStack_Types_Cfg.h
********************************************************************************
*   Project/Product : AUTOSAR BSW PROJECT
*   Title           : ComStack module configuration File
*   Author          : Hirain
********************************************************************************
*   Description     : ComStack module configuration File
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
#ifndef COMSTACK_TYPES_CFG_H
#define COMSTACK_TYPES_CFG_H

/*******************************************************************************
*   Includes
*******************************************************************************/
#include "Std_Types.h"
/*******************************************************************************
*   Typedef
*******************************************************************************/
/*The size of this global type depends on the maximum number of PDUs used
within one software module.*/
typedef uint8       PduIdType;
#define COMSTACK_INVALID_PDUID    ((PduIdType)0xFFU)
/*The size of this global type depends on the maximum length of PDUs to be
sent by an ECU.*/
typedef uint16       PduLengthType;

typedef uint8    NetworkHandleType;
typedef uint8    PNCHandleType;
#define COMSTACK_INVALID_NETWORK_HANDLE    (0xFFU)
#endif  /* COMSTACK_TYPES_CFG_H */
