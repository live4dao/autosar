/*  BEGIN_FILE_HDR
********************************************************************************
*   File Name       : Rte_ComM.h
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
*   V1.0.2_3.5.5_AZ240046       10/05/2024    Eas           N/A          N/A
*
********************************************************************************
* END_FILE_HDR*/
#ifndef RTE_COMM_H
#define RTE_COMM_H

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
#include "ComM.h"
#include "Rte_ComM_Type.h"
#define RTE_START_SEC_CODE
#include "MemMap.h"

#define Rte_Switch_UM_User_ComMMode                         Rte_Switch_ComM_UM_User_ComMMode
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Switch_ComM_UM_User_ComMMode
(
    VAR(Rte_ModeType_ComMMode, AUTOMATIC) nextMode
);

#define RTE_STOP_SEC_CODE
#include "MemMap.h"

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif  /*RTE_COMM_H*/


