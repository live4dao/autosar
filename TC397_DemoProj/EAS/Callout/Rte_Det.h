/*  BEGIN_FILE_HDR
********************************************************************************
*   File Name       : Rte_Det.h
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
#ifndef RTE_DET_H
#define RTE_DET_H

#ifndef RTE_CORE
#ifdef RTE_APPLICATION_HEADER_FILE
#error Multiple application header files included.
#endif /* RTE_APPLICATION_HEADER_FILE */
#define RTE_APPLICATION_HEADER_FILE
#endif
# ifdef __cplusplus
extern "C"
{
# endif /* __cplusplus */

/*******************************************************************************
*   Includes.
*******************************************************************************/
#include "Det.h"
#include "Rte_Det_Type.h"
#define RTE_START_SEC_CODE
#include "MemMap.h"


#define RTE_STOP_SEC_CODE
#include "MemMap.h"

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif  /*RTE_DET_H*/


