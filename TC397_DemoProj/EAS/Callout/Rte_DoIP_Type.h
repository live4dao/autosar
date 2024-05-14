/*  BEGIN_FILE_HDR
********************************************************************************
*   File Name       : Rte_DoIP_Type.h
********************************************************************************
*   Project/Product : AUTOSAR BSW PROJECT
*   Title           : Rte module configuration File
*   Author          : Hirain
********************************************************************************
*   Description     : Rte module configuration File
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
#ifndef RTE_DOIP_TYPE_H
#define RTE_DOIP_TYPE_H
/*******************************************************************************
*   Includes.
*******************************************************************************/
#include "Rte_Type.h"

#ifndef RTE_MODETYPE_currentDoIPActivationLineStatus
#define RTE_MODETYPE_currentDoIPActivationLineStatus
typedef uint8 Rte_ModeType_currentDoIPActivationLineStatus;
#endif
#ifndef RTE_MODE_currentDoIPActivationLineStatus_DOIP_ACTIVATION_LINE_ACTIVE
#define RTE_MODE_currentDoIPActivationLineStatus_DOIP_ACTIVATION_LINE_ACTIVE    0U
#endif
#ifndef RTE_MODE_currentDoIPActivationLineStatus_DOIP_ACTIVATION_LINE_INACTIVE
#define RTE_MODE_currentDoIPActivationLineStatus_DOIP_ACTIVATION_LINE_INACTIVE  1U
#endif
#ifndef RTE_TRANSITION_currentDoIPActivationLineStatus
#define RTE_TRANSITION_currentDoIPActivationLineStatus      2U
#endif

#endif



