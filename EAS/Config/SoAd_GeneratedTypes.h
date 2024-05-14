/*  BEGIN_FILE_HDR
********************************************************************************
*   File Name       : SoAd_GeneratedTypes.h
********************************************************************************
*   Project/Product : AUTOSAR BSW PROJECT
*   Title           : SoAd module configuration File
*   Author          : Hirain
********************************************************************************
*   Description     : SoAd module configuration File
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
#ifndef _SOAD_GENERATEDTYPES_H_
#define _SOAD_GENERATEDTYPES_H_


/*******************************************************************************
*   Includes
*******************************************************************************/
#include "ComStack_Types.h"


/*******************************************************************************
*   Macro
*******************************************************************************/


/*******************************************************************************
*   Global Data Declaration
*******************************************************************************/
typedef uint8 SoAd_RoutingGroupIdType;
typedef uint8 SoAd_SoConIdType;
typedef uint8 SoAd_SoConGroupIdType;
typedef uint8 SoAd_PduRouteIdType;
typedef uint8 SoAd_PduRouteDestIdType;
typedef uint8 SoAd_SocketRouteIdType;
typedef uint16 SoAd_IfTxUnconfirmedType;

typedef uint16 SoAd_IfTxTimerType;

typedef struct
{
  uint8 Mask[1];	/*the type of Mask is determined by SOAD_ROUTINGGROUP_MAX*/
  uint8 RoutingState[1];	/*the type of RoutingState is determined by SOAD_ROUTINGGROUP_MAX*/
} SoAd_RoutingGroupCtrlType;


/*
 *  The Index of UpLayer modules of SoAd module.
 */
typedef enum
{
    /*Add the Index of UpLayer module supported by SoAd module.*/
    SOAD_UL_DOIP = 0,
    SOAD_UL_UDPNM = 1,
    SOAD_UL_PDUR = 2,
    SOAD_UL_XCP = 3,
    SOAD_UL_MAX
} SoAd_ULIndexType;

/*******************************************************************************
*   Global Function Declaration
*******************************************************************************/

#endif /*_SOAD_GENERATEDTYPES_H_*/

