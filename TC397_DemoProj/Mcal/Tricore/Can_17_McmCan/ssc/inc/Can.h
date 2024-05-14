/*  BEGIN_FILE_HDR
********************************************************************************
*   NOTICE
*   This software is the property of HiRain Technologies. Any information
*   contained in this doc should not be reproduced, or used, or disclosed
*   without the written authorization from HiRain Technologies.
********************************************************************************
*   File Name       : Can.h
********************************************************************************
*   Project/Product : AUTOSAR 4.2
*   Title           : CAN Driver module Header File
*   Author          : Hirain
********************************************************************************
*   Description     : CAN Driver module Header File
*
********************************************************************************
*   Limitations     : none
*
********************************************************************************
*
********************************************************************************
*   Revision History:
*   Reference to Core C File
********************************************************************************
* END_FILE_HDR*/

#ifndef CAN_H
#define CAN_H

/*******************************************************************************
*   Includes
*******************************************************************************/
#include "Can_17_McmCan.h"

/*******************************************************************************
*   Macro
*******************************************************************************/
#define Can_Write                          Can_17_McmCan_Write
#define Can_SetControllerMode              Can_17_McmCan_SetControllerMode
//#define Can_CheckWakeup                    Can_17_McmCan_CheckWakeup
//#define Can_ChangeBaudrate                 Can_17_McmCan_ChangeBaudrate
#define Can_SetIcomConfiguration          

/*******************************************************************************
*   Critical Area
*******************************************************************************/


/*******************************************************************************
*   Global Function Declaration
*******************************************************************************/

#endif /* CAN_H */

