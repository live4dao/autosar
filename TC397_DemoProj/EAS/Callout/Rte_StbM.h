/*  BEGIN_FILE_HDR
********************************************************************************
*   File Name       : Rte_StbM.h
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
#ifndef RTE_STBM_H
#define RTE_STBM_H

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
#include "StbM.h"
#include "Rte_StbM_Type.h"
#define RTE_START_SEC_CODE
#include "MemMap.h"

#define StbM_Rte_GlobalTime_RestoreFromNonVolatile          Rte_Call_StbM_GlobalTime_RestoreFromNonVolatile
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_StbM_GlobalTime_RestoreFromNonVolatile
(
    VAR(StbM_SynchronizedTimeBaseType, AUTOMATIC) timeBaseId,
    P2VAR(StbM_TimeStampType, AUTOMATIC, RTE_APPL_DATA) timeStampPtr,
    P2VAR(StbM_UserDataType, AUTOMATIC, RTE_APPL_DATA) userDataPtr
);

#define RTE_STOP_SEC_CODE
#include "MemMap.h"

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif  /*RTE_STBM_H*/


