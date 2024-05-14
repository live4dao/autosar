/*  BEGIN_FILE_HDR
********************************************************************************
*   File Name       : Rte_CtApUss_Pdc.h
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
#ifndef RTE_CTAPUSS_PDC_H
#define RTE_CTAPUSS_PDC_H

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
#include "Rte_CtApUss_Pdc_Type.h"
/*******************************************************************************
*   define for a symbolic name of the RunnableEntity.
*******************************************************************************/
#define RTE_RUNNABLE_TSK_Uss_Pdc_40ms                       TSK_Uss_Pdc_40ms
#define RTE_RUNNABLE_USS_Pdc_init                           USS_Pdc_init

/*******************************************************************************
*   Instance Handle
*******************************************************************************/
#ifndef RTE_CORE
typedef CONSTP2CONST(Rte_CDS_CtApUss_Pdc, AUTOMATIC, RTE_CONST) Rte_Instance;
#endif

/*******************************************************************************
*   Macro definition.
*******************************************************************************/
#define Rte_Write_PiUssPdcInfo_PiUssPdcInfo                 Rte_Write_CtApUss_Pdc_PiUssPdcInfo_PiUssPdcInfo
#define Rte_Write_PiUssPdcWorkingStatus_PiUssPdcWorkingStatus         Rte_Write_CtApUss_Pdc_PiUssPdcWorkingStatus_PiUssPdcWorkingStatus
#define Rte_Read_PiCarInfoH_PiCarInfoH                      Rte_Read_CtApUss_Pdc_PiCarInfoH_PiCarInfoH
#define Rte_Read_PiCarInfoL_PiCarInfoL                      Rte_Read_CtApUss_Pdc_PiCarInfoL_PiCarInfoL
#define Rte_Read_PiGlobalPoseBuffer_PiGlobalPoseBuffer      Rte_Read_CtApUss_Pdc_PiGlobalPoseBuffer_PiGlobalPoseBuffer
#define Rte_Read_PiUssStatusSet_PiUssStatusSet              Rte_Read_CtApUss_Pdc_PiUssStatusSet_PiUssStatusSet
#define Rte_Read_PiPdcCommand_PiPdcCommand                  Rte_Read_CtApUss_Pdc_PiPdcCommand_PiPdcCommand
#define Rte_Read_PiUssInfo_PiUssInfo                        Rte_Read_CtApUss_Pdc_PiUssInfo_PiUssInfo
/*******************************************************************************
*   Extended
*******************************************************************************/
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtApUss_Pdc_PiUssPdcInfo_PiUssPdcInfo
(
    P2VAR(UssPdcInfo, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtApUss_Pdc_PiUssPdcWorkingStatus_PiUssPdcWorkingStatus
(
    P2VAR(WorkingStatus, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtApUss_Pdc_PiCarInfoH_PiCarInfoH
(
    P2VAR(CarInfoH, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtApUss_Pdc_PiCarInfoL_PiCarInfoL
(
    P2VAR(CarInfoL, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtApUss_Pdc_PiGlobalPoseBuffer_PiGlobalPoseBuffer
(
    P2VAR(GlobalPoseBuffer, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtApUss_Pdc_PiUssStatusSet_PiUssStatusSet
(
    P2VAR(UssStatusSet, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtApUss_Pdc_PiPdcCommand_PiPdcCommand
(
    P2VAR(Command, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtApUss_Pdc_PiUssInfo_PiUssInfo
(
    P2VAR(UssInfo, AUTOMATIC, RTE_APPL_DATA) data
);

/*******************************************************************************
*   Runnable Extended
*******************************************************************************/

#define CtApUss_Pdc_START_SEC_CODE
#include "CtApUss_Pdc_MemMap.h"

extern FUNC(void, CtApUss_Pdc_CODE) USS_Pdc_init
(
    void
);
#define CtApUss_Pdc_STOP_SEC_CODE
#include "CtApUss_Pdc_MemMap.h"


#define CtApUss_Pdc_START_SEC_CODE
#include "CtApUss_Pdc_MemMap.h"

extern FUNC(void, CtApUss_Pdc_CODE) TSK_Uss_Pdc_40ms
(
    void
);
#define CtApUss_Pdc_STOP_SEC_CODE
#include "CtApUss_Pdc_MemMap.h"


# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif  /*RTE_CTAPUSS_PDC_H*/


