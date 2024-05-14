/*  BEGIN_FILE_HDR
********************************************************************************
*   File Name       : Rte_ComM_Type.h
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
#ifndef RTE_COMM_TYPE_H
#define RTE_COMM_TYPE_H
/*******************************************************************************
*   Includes.
*******************************************************************************/
#include "Rte_Type.h"

#ifndef RTE_MODETYPE_ComMMode
#define RTE_MODETYPE_ComMMode
typedef uint8 Rte_ModeType_ComMMode;
#endif
#ifndef RTE_MODE_ComMMode_COMM_FULL_COMMUNICATION
#define RTE_MODE_ComMMode_COMM_FULL_COMMUNICATION           0U
#endif
#ifndef RTE_MODE_ComMMode_COMM_NO_COMMUNICATION
#define RTE_MODE_ComMMode_COMM_NO_COMMUNICATION             1U
#endif
#ifndef RTE_TRANSITION_ComMMode
#define RTE_TRANSITION_ComMMode                             2U
#endif

#endif



