/*  BEGIN_FILE_HDR
********************************************************************************
*   File Name       : Rte_Dem.h
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
#ifndef RTE_DEM_H
#define RTE_DEM_H

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
#include "Dem.h"
#include "Rte_Dem_Type.h"
#define RTE_START_SEC_CODE
#include "MemMap.h"

#define Dem_Rte_Event_0x94001C_GetFaultDetectionCounter     Rte_Call_Dem_CBFaultDetectCtr_Event_0x94001C_GetFaultDetectionCounter
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dem_CBFaultDetectCtr_Event_0x94001C_GetFaultDetectionCounter
(
    P2VAR(sint8, AUTOMATIC, RTE_APPL_DATA) FaultDetectionCounter
);
#define Dem_Rte_Event_0x94001D_GetFaultDetectionCounter     Rte_Call_Dem_CBFaultDetectCtr_Event_0x94001D_GetFaultDetectionCounter
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dem_CBFaultDetectCtr_Event_0x94001D_GetFaultDetectionCounter
(
    P2VAR(sint8, AUTOMATIC, RTE_APPL_DATA) FaultDetectionCounter
);
#define Dem_Rte_Event_0x940054_GetFaultDetectionCounter     Rte_Call_Dem_CBFaultDetectCtr_Event_0x940054_GetFaultDetectionCounter
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dem_CBFaultDetectCtr_Event_0x940054_GetFaultDetectionCounter
(
    P2VAR(sint8, AUTOMATIC, RTE_APPL_DATA) FaultDetectionCounter
);
#define Dem_Rte_Event_0x940056_GetFaultDetectionCounter     Rte_Call_Dem_CBFaultDetectCtr_Event_0x940056_GetFaultDetectionCounter
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dem_CBFaultDetectCtr_Event_0x940056_GetFaultDetectionCounter
(
    P2VAR(sint8, AUTOMATIC, RTE_APPL_DATA) FaultDetectionCounter
);
#define Dem_Rte_Event_0x940089_GetFaultDetectionCounter     Rte_Call_Dem_CBFaultDetectCtr_Event_0x940089_GetFaultDetectionCounter
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dem_CBFaultDetectCtr_Event_0x940089_GetFaultDetectionCounter
(
    P2VAR(sint8, AUTOMATIC, RTE_APPL_DATA) FaultDetectionCounter
);
#define Dem_Rte_Event_0x940091_GetFaultDetectionCounter     Rte_Call_Dem_CBFaultDetectCtr_Event_0x940091_GetFaultDetectionCounter
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dem_CBFaultDetectCtr_Event_0x940091_GetFaultDetectionCounter
(
    P2VAR(sint8, AUTOMATIC, RTE_APPL_DATA) FaultDetectionCounter
);
#define Dem_Rte_Event_0x94011C_GetFaultDetectionCounter     Rte_Call_Dem_CBFaultDetectCtr_Event_0x94011C_GetFaultDetectionCounter
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dem_CBFaultDetectCtr_Event_0x94011C_GetFaultDetectionCounter
(
    P2VAR(sint8, AUTOMATIC, RTE_APPL_DATA) FaultDetectionCounter
);
#define Dem_Rte_Event_0x94011D_GetFaultDetectionCounter     Rte_Call_Dem_CBFaultDetectCtr_Event_0x94011D_GetFaultDetectionCounter
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dem_CBFaultDetectCtr_Event_0x94011D_GetFaultDetectionCounter
(
    P2VAR(sint8, AUTOMATIC, RTE_APPL_DATA) FaultDetectionCounter
);
#define Dem_Rte_Event_0x940189_GetFaultDetectionCounter     Rte_Call_Dem_CBFaultDetectCtr_Event_0x940189_GetFaultDetectionCounter
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dem_CBFaultDetectCtr_Event_0x940189_GetFaultDetectionCounter
(
    P2VAR(sint8, AUTOMATIC, RTE_APPL_DATA) FaultDetectionCounter
);
#define Dem_Rte_Event_0x94021C_GetFaultDetectionCounter     Rte_Call_Dem_CBFaultDetectCtr_Event_0x94021C_GetFaultDetectionCounter
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dem_CBFaultDetectCtr_Event_0x94021C_GetFaultDetectionCounter
(
    P2VAR(sint8, AUTOMATIC, RTE_APPL_DATA) FaultDetectionCounter
);
#define Dem_Rte_Event_0x940254_GetFaultDetectionCounter     Rte_Call_Dem_CBFaultDetectCtr_Event_0x940254_GetFaultDetectionCounter
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dem_CBFaultDetectCtr_Event_0x940254_GetFaultDetectionCounter
(
    P2VAR(sint8, AUTOMATIC, RTE_APPL_DATA) FaultDetectionCounter
);
#define Dem_Rte_Event_0x940306_GetFaultDetectionCounter     Rte_Call_Dem_CBFaultDetectCtr_Event_0x940306_GetFaultDetectionCounter
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dem_CBFaultDetectCtr_Event_0x940306_GetFaultDetectionCounter
(
    P2VAR(sint8, AUTOMATIC, RTE_APPL_DATA) FaultDetectionCounter
);
#define Dem_Rte_Event_0x94031C_GetFaultDetectionCounter     Rte_Call_Dem_CBFaultDetectCtr_Event_0x94031C_GetFaultDetectionCounter
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dem_CBFaultDetectCtr_Event_0x94031C_GetFaultDetectionCounter
(
    P2VAR(sint8, AUTOMATIC, RTE_APPL_DATA) FaultDetectionCounter
);
#define Dem_Rte_Event_0x940406_GetFaultDetectionCounter     Rte_Call_Dem_CBFaultDetectCtr_Event_0x940406_GetFaultDetectionCounter
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dem_CBFaultDetectCtr_Event_0x940406_GetFaultDetectionCounter
(
    P2VAR(sint8, AUTOMATIC, RTE_APPL_DATA) FaultDetectionCounter
);
#define Dem_Rte_Event_0x94041C_GetFaultDetectionCounter     Rte_Call_Dem_CBFaultDetectCtr_Event_0x94041C_GetFaultDetectionCounter
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dem_CBFaultDetectCtr_Event_0x94041C_GetFaultDetectionCounter
(
    P2VAR(sint8, AUTOMATIC, RTE_APPL_DATA) FaultDetectionCounter
);
#define Dem_Rte_Event_0x940498_GetFaultDetectionCounter     Rte_Call_Dem_CBFaultDetectCtr_Event_0x940498_GetFaultDetectionCounter
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dem_CBFaultDetectCtr_Event_0x940498_GetFaultDetectionCounter
(
    P2VAR(sint8, AUTOMATIC, RTE_APPL_DATA) FaultDetectionCounter
);
#define Dem_Rte_Event_0x9404A2_GetFaultDetectionCounter     Rte_Call_Dem_CBFaultDetectCtr_Event_0x9404A2_GetFaultDetectionCounter
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dem_CBFaultDetectCtr_Event_0x9404A2_GetFaultDetectionCounter
(
    P2VAR(sint8, AUTOMATIC, RTE_APPL_DATA) FaultDetectionCounter
);
#define Dem_Rte_Event_0x940504_GetFaultDetectionCounter     Rte_Call_Dem_CBFaultDetectCtr_Event_0x940504_GetFaultDetectionCounter
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dem_CBFaultDetectCtr_Event_0x940504_GetFaultDetectionCounter
(
    P2VAR(sint8, AUTOMATIC, RTE_APPL_DATA) FaultDetectionCounter
);
#define Dem_Rte_Event_0x940506_GetFaultDetectionCounter     Rte_Call_Dem_CBFaultDetectCtr_Event_0x940506_GetFaultDetectionCounter
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dem_CBFaultDetectCtr_Event_0x940506_GetFaultDetectionCounter
(
    P2VAR(sint8, AUTOMATIC, RTE_APPL_DATA) FaultDetectionCounter
);
#define Dem_Rte_Event_0x94051C_GetFaultDetectionCounter     Rte_Call_Dem_CBFaultDetectCtr_Event_0x94051C_GetFaultDetectionCounter
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dem_CBFaultDetectCtr_Event_0x94051C_GetFaultDetectionCounter
(
    P2VAR(sint8, AUTOMATIC, RTE_APPL_DATA) FaultDetectionCounter
);
#define Dem_Rte_Event_0x940604_GetFaultDetectionCounter     Rte_Call_Dem_CBFaultDetectCtr_Event_0x940604_GetFaultDetectionCounter
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dem_CBFaultDetectCtr_Event_0x940604_GetFaultDetectionCounter
(
    P2VAR(sint8, AUTOMATIC, RTE_APPL_DATA) FaultDetectionCounter
);
#define Dem_Rte_Event_0x940606_GetFaultDetectionCounter     Rte_Call_Dem_CBFaultDetectCtr_Event_0x940606_GetFaultDetectionCounter
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dem_CBFaultDetectCtr_Event_0x940606_GetFaultDetectionCounter
(
    P2VAR(sint8, AUTOMATIC, RTE_APPL_DATA) FaultDetectionCounter
);
#define Dem_Rte_Event_0x94061C_GetFaultDetectionCounter     Rte_Call_Dem_CBFaultDetectCtr_Event_0x94061C_GetFaultDetectionCounter
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dem_CBFaultDetectCtr_Event_0x94061C_GetFaultDetectionCounter
(
    P2VAR(sint8, AUTOMATIC, RTE_APPL_DATA) FaultDetectionCounter
);
#define Dem_Rte_Event_0x940704_GetFaultDetectionCounter     Rte_Call_Dem_CBFaultDetectCtr_Event_0x940704_GetFaultDetectionCounter
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dem_CBFaultDetectCtr_Event_0x940704_GetFaultDetectionCounter
(
    P2VAR(sint8, AUTOMATIC, RTE_APPL_DATA) FaultDetectionCounter
);
#define Dem_Rte_Event_0x940706_GetFaultDetectionCounter     Rte_Call_Dem_CBFaultDetectCtr_Event_0x940706_GetFaultDetectionCounter
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dem_CBFaultDetectCtr_Event_0x940706_GetFaultDetectionCounter
(
    P2VAR(sint8, AUTOMATIC, RTE_APPL_DATA) FaultDetectionCounter
);
#define Dem_Rte_Event_0x940754_GetFaultDetectionCounter     Rte_Call_Dem_CBFaultDetectCtr_Event_0x940754_GetFaultDetectionCounter
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dem_CBFaultDetectCtr_Event_0x940754_GetFaultDetectionCounter
(
    P2VAR(sint8, AUTOMATIC, RTE_APPL_DATA) FaultDetectionCounter
);
#define Dem_Rte_Event_0x940804_GetFaultDetectionCounter     Rte_Call_Dem_CBFaultDetectCtr_Event_0x940804_GetFaultDetectionCounter
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dem_CBFaultDetectCtr_Event_0x940804_GetFaultDetectionCounter
(
    P2VAR(sint8, AUTOMATIC, RTE_APPL_DATA) FaultDetectionCounter
);
#define Dem_Rte_Event_0x940854_GetFaultDetectionCounter     Rte_Call_Dem_CBFaultDetectCtr_Event_0x940854_GetFaultDetectionCounter
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dem_CBFaultDetectCtr_Event_0x940854_GetFaultDetectionCounter
(
    P2VAR(sint8, AUTOMATIC, RTE_APPL_DATA) FaultDetectionCounter
);
#define Dem_Rte_Event_0x940904_GetFaultDetectionCounter     Rte_Call_Dem_CBFaultDetectCtr_Event_0x940904_GetFaultDetectionCounter
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dem_CBFaultDetectCtr_Event_0x940904_GetFaultDetectionCounter
(
    P2VAR(sint8, AUTOMATIC, RTE_APPL_DATA) FaultDetectionCounter
);
#define Dem_Rte_Event_0x940A04_GetFaultDetectionCounter     Rte_Call_Dem_CBFaultDetectCtr_Event_0x940A04_GetFaultDetectionCounter
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dem_CBFaultDetectCtr_Event_0x940A04_GetFaultDetectionCounter
(
    P2VAR(sint8, AUTOMATIC, RTE_APPL_DATA) FaultDetectionCounter
);
#define Dem_Rte_Event_0x940B04_GetFaultDetectionCounter     Rte_Call_Dem_CBFaultDetectCtr_Event_0x940B04_GetFaultDetectionCounter
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dem_CBFaultDetectCtr_Event_0x940B04_GetFaultDetectionCounter
(
    P2VAR(sint8, AUTOMATIC, RTE_APPL_DATA) FaultDetectionCounter
);
#define Dem_Rte_Event_0x943009_GetFaultDetectionCounter     Rte_Call_Dem_CBFaultDetectCtr_Event_0x943009_GetFaultDetectionCounter
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dem_CBFaultDetectCtr_Event_0x943009_GetFaultDetectionCounter
(
    P2VAR(sint8, AUTOMATIC, RTE_APPL_DATA) FaultDetectionCounter
);
#define Dem_Rte_Event_0xD20008_GetFaultDetectionCounter     Rte_Call_Dem_CBFaultDetectCtr_Event_0xD20008_GetFaultDetectionCounter
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dem_CBFaultDetectCtr_Event_0xD20008_GetFaultDetectionCounter
(
    P2VAR(sint8, AUTOMATIC, RTE_APPL_DATA) FaultDetectionCounter
);
#define Dem_Rte_Event_0xD20087_GetFaultDetectionCounter     Rte_Call_Dem_CBFaultDetectCtr_Event_0xD20087_GetFaultDetectionCounter
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dem_CBFaultDetectCtr_Event_0xD20087_GetFaultDetectionCounter
(
    P2VAR(sint8, AUTOMATIC, RTE_APPL_DATA) FaultDetectionCounter
);
#define Dem_Rte_Event_0xD20108_GetFaultDetectionCounter     Rte_Call_Dem_CBFaultDetectCtr_Event_0xD20108_GetFaultDetectionCounter
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dem_CBFaultDetectCtr_Event_0xD20108_GetFaultDetectionCounter
(
    P2VAR(sint8, AUTOMATIC, RTE_APPL_DATA) FaultDetectionCounter
);
#define Dem_Rte_Event_0xD20187_GetFaultDetectionCounter     Rte_Call_Dem_CBFaultDetectCtr_Event_0xD20187_GetFaultDetectionCounter
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dem_CBFaultDetectCtr_Event_0xD20187_GetFaultDetectionCounter
(
    P2VAR(sint8, AUTOMATIC, RTE_APPL_DATA) FaultDetectionCounter
);
#define Dem_Rte_Event_0xD20208_GetFaultDetectionCounter     Rte_Call_Dem_CBFaultDetectCtr_Event_0xD20208_GetFaultDetectionCounter
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dem_CBFaultDetectCtr_Event_0xD20208_GetFaultDetectionCounter
(
    P2VAR(sint8, AUTOMATIC, RTE_APPL_DATA) FaultDetectionCounter
);
#define Dem_Rte_Event_0xD20287_GetFaultDetectionCounter     Rte_Call_Dem_CBFaultDetectCtr_Event_0xD20287_GetFaultDetectionCounter
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dem_CBFaultDetectCtr_Event_0xD20287_GetFaultDetectionCounter
(
    P2VAR(sint8, AUTOMATIC, RTE_APPL_DATA) FaultDetectionCounter
);
#define Dem_Rte_Event_0xD20288_GetFaultDetectionCounter     Rte_Call_Dem_CBFaultDetectCtr_Event_0xD20288_GetFaultDetectionCounter
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dem_CBFaultDetectCtr_Event_0xD20288_GetFaultDetectionCounter
(
    P2VAR(sint8, AUTOMATIC, RTE_APPL_DATA) FaultDetectionCounter
);
#define Dem_Rte_Event_0xD20308_GetFaultDetectionCounter     Rte_Call_Dem_CBFaultDetectCtr_Event_0xD20308_GetFaultDetectionCounter
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dem_CBFaultDetectCtr_Event_0xD20308_GetFaultDetectionCounter
(
    P2VAR(sint8, AUTOMATIC, RTE_APPL_DATA) FaultDetectionCounter
);
#define Dem_Rte_Event_0xD20387_GetFaultDetectionCounter     Rte_Call_Dem_CBFaultDetectCtr_Event_0xD20387_GetFaultDetectionCounter
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dem_CBFaultDetectCtr_Event_0xD20387_GetFaultDetectionCounter
(
    P2VAR(sint8, AUTOMATIC, RTE_APPL_DATA) FaultDetectionCounter
);
#define Dem_Rte_Event_0xD20388_GetFaultDetectionCounter     Rte_Call_Dem_CBFaultDetectCtr_Event_0xD20388_GetFaultDetectionCounter
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dem_CBFaultDetectCtr_Event_0xD20388_GetFaultDetectionCounter
(
    P2VAR(sint8, AUTOMATIC, RTE_APPL_DATA) FaultDetectionCounter
);
#define Dem_Rte_Event_0xD20408_GetFaultDetectionCounter     Rte_Call_Dem_CBFaultDetectCtr_Event_0xD20408_GetFaultDetectionCounter
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dem_CBFaultDetectCtr_Event_0xD20408_GetFaultDetectionCounter
(
    P2VAR(sint8, AUTOMATIC, RTE_APPL_DATA) FaultDetectionCounter
);
#define Dem_Rte_Event_0xD20508_GetFaultDetectionCounter     Rte_Call_Dem_CBFaultDetectCtr_Event_0xD20508_GetFaultDetectionCounter
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dem_CBFaultDetectCtr_Event_0xD20508_GetFaultDetectionCounter
(
    P2VAR(sint8, AUTOMATIC, RTE_APPL_DATA) FaultDetectionCounter
);
#define Dem_Rte_Event_0xD20608_GetFaultDetectionCounter     Rte_Call_Dem_CBFaultDetectCtr_Event_0xD20608_GetFaultDetectionCounter
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dem_CBFaultDetectCtr_Event_0xD20608_GetFaultDetectionCounter
(
    P2VAR(sint8, AUTOMATIC, RTE_APPL_DATA) FaultDetectionCounter
);
#define Dem_Rte_Event_0xD20708_GetFaultDetectionCounter     Rte_Call_Dem_CBFaultDetectCtr_Event_0xD20708_GetFaultDetectionCounter
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dem_CBFaultDetectCtr_Event_0xD20708_GetFaultDetectionCounter
(
    P2VAR(sint8, AUTOMATIC, RTE_APPL_DATA) FaultDetectionCounter
);
#define Dem_Rte_Event_0xD20808_GetFaultDetectionCounter     Rte_Call_Dem_CBFaultDetectCtr_Event_0xD20808_GetFaultDetectionCounter
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dem_CBFaultDetectCtr_Event_0xD20808_GetFaultDetectionCounter
(
    P2VAR(sint8, AUTOMATIC, RTE_APPL_DATA) FaultDetectionCounter
);
#define Dem_Rte_Event_0xD20908_GetFaultDetectionCounter     Rte_Call_Dem_CBFaultDetectCtr_Event_0xD20908_GetFaultDetectionCounter
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dem_CBFaultDetectCtr_Event_0xD20908_GetFaultDetectionCounter
(
    P2VAR(sint8, AUTOMATIC, RTE_APPL_DATA) FaultDetectionCounter
);
#define Dem_Rte_Event_0xD20A08_GetFaultDetectionCounter     Rte_Call_Dem_CBFaultDetectCtr_Event_0xD20A08_GetFaultDetectionCounter
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dem_CBFaultDetectCtr_Event_0xD20A08_GetFaultDetectionCounter
(
    P2VAR(sint8, AUTOMATIC, RTE_APPL_DATA) FaultDetectionCounter
);
#define Dem_Rte_Event_0xD20B08_GetFaultDetectionCounter     Rte_Call_Dem_CBFaultDetectCtr_Event_0xD20B08_GetFaultDetectionCounter
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dem_CBFaultDetectCtr_Event_0xD20B08_GetFaultDetectionCounter
(
    P2VAR(sint8, AUTOMATIC, RTE_APPL_DATA) FaultDetectionCounter
);
#define Dem_Rte_Event_0xD20C08_GetFaultDetectionCounter     Rte_Call_Dem_CBFaultDetectCtr_Event_0xD20C08_GetFaultDetectionCounter
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dem_CBFaultDetectCtr_Event_0xD20C08_GetFaultDetectionCounter
(
    P2VAR(sint8, AUTOMATIC, RTE_APPL_DATA) FaultDetectionCounter
);
#define Dem_Rte_Event_0xD20D08_GetFaultDetectionCounter     Rte_Call_Dem_CBFaultDetectCtr_Event_0xD20D08_GetFaultDetectionCounter
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dem_CBFaultDetectCtr_Event_0xD20D08_GetFaultDetectionCounter
(
    P2VAR(sint8, AUTOMATIC, RTE_APPL_DATA) FaultDetectionCounter
);
#define Dem_Rte_Event_0xD20E08_GetFaultDetectionCounter     Rte_Call_Dem_CBFaultDetectCtr_Event_0xD20E08_GetFaultDetectionCounter
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dem_CBFaultDetectCtr_Event_0xD20E08_GetFaultDetectionCounter
(
    P2VAR(sint8, AUTOMATIC, RTE_APPL_DATA) FaultDetectionCounter
);
#define Dem_Rte_Event_0xD20F08_GetFaultDetectionCounter     Rte_Call_Dem_CBFaultDetectCtr_Event_0xD20F08_GetFaultDetectionCounter
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dem_CBFaultDetectCtr_Event_0xD20F08_GetFaultDetectionCounter
(
    P2VAR(sint8, AUTOMATIC, RTE_APPL_DATA) FaultDetectionCounter
);
#define Dem_Rte_Event_0xD21008_GetFaultDetectionCounter     Rte_Call_Dem_CBFaultDetectCtr_Event_0xD21008_GetFaultDetectionCounter
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dem_CBFaultDetectCtr_Event_0xD21008_GetFaultDetectionCounter
(
    P2VAR(sint8, AUTOMATIC, RTE_APPL_DATA) FaultDetectionCounter
);
#define Dem_Rte_Event_0xD21087_GetFaultDetectionCounter     Rte_Call_Dem_CBFaultDetectCtr_Event_0xD21087_GetFaultDetectionCounter
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dem_CBFaultDetectCtr_Event_0xD21087_GetFaultDetectionCounter
(
    P2VAR(sint8, AUTOMATIC, RTE_APPL_DATA) FaultDetectionCounter
);
#define Dem_Rte_Event_0xD21208_GetFaultDetectionCounter     Rte_Call_Dem_CBFaultDetectCtr_Event_0xD21208_GetFaultDetectionCounter
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dem_CBFaultDetectCtr_Event_0xD21208_GetFaultDetectionCounter
(
    P2VAR(sint8, AUTOMATIC, RTE_APPL_DATA) FaultDetectionCounter
);
#define Dem_Rte_Event_0xD21308_GetFaultDetectionCounter     Rte_Call_Dem_CBFaultDetectCtr_Event_0xD21308_GetFaultDetectionCounter
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dem_CBFaultDetectCtr_Event_0xD21308_GetFaultDetectionCounter
(
    P2VAR(sint8, AUTOMATIC, RTE_APPL_DATA) FaultDetectionCounter
);
#define Dem_Rte_Event_0xD21408_GetFaultDetectionCounter     Rte_Call_Dem_CBFaultDetectCtr_Event_0xD21408_GetFaultDetectionCounter
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dem_CBFaultDetectCtr_Event_0xD21408_GetFaultDetectionCounter
(
    P2VAR(sint8, AUTOMATIC, RTE_APPL_DATA) FaultDetectionCounter
);
#define Dem_Rte_Event_0xD21508_GetFaultDetectionCounter     Rte_Call_Dem_CBFaultDetectCtr_Event_0xD21508_GetFaultDetectionCounter
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dem_CBFaultDetectCtr_Event_0xD21508_GetFaultDetectionCounter
(
    P2VAR(sint8, AUTOMATIC, RTE_APPL_DATA) FaultDetectionCounter
);
#define Dem_Rte_Event_0xD21608_GetFaultDetectionCounter     Rte_Call_Dem_CBFaultDetectCtr_Event_0xD21608_GetFaultDetectionCounter
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dem_CBFaultDetectCtr_Event_0xD21608_GetFaultDetectionCounter
(
    P2VAR(sint8, AUTOMATIC, RTE_APPL_DATA) FaultDetectionCounter
);
#define Dem_Rte_Event_0xD21708_GetFaultDetectionCounter     Rte_Call_Dem_CBFaultDetectCtr_Event_0xD21708_GetFaultDetectionCounter
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dem_CBFaultDetectCtr_Event_0xD21708_GetFaultDetectionCounter
(
    P2VAR(sint8, AUTOMATIC, RTE_APPL_DATA) FaultDetectionCounter
);
#define Dem_Rte_Event_0xD23087_GetFaultDetectionCounter     Rte_Call_Dem_CBFaultDetectCtr_Event_0xD23087_GetFaultDetectionCounter
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dem_CBFaultDetectCtr_Event_0xD23087_GetFaultDetectionCounter
(
    P2VAR(sint8, AUTOMATIC, RTE_APPL_DATA) FaultDetectionCounter
);
#define Dem_Rte_Event_0xD23187_GetFaultDetectionCounter     Rte_Call_Dem_CBFaultDetectCtr_Event_0xD23187_GetFaultDetectionCounter
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dem_CBFaultDetectCtr_Event_0xD23187_GetFaultDetectionCounter
(
    P2VAR(sint8, AUTOMATIC, RTE_APPL_DATA) FaultDetectionCounter
);
#define Dem_Rte_Event_0xD23287_GetFaultDetectionCounter     Rte_Call_Dem_CBFaultDetectCtr_Event_0xD23287_GetFaultDetectionCounter
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dem_CBFaultDetectCtr_Event_0xD23287_GetFaultDetectionCounter
(
    P2VAR(sint8, AUTOMATIC, RTE_APPL_DATA) FaultDetectionCounter
);
#define Dem_Rte_Event_0xD23387_GetFaultDetectionCounter     Rte_Call_Dem_CBFaultDetectCtr_Event_0xD23387_GetFaultDetectionCounter
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dem_CBFaultDetectCtr_Event_0xD23387_GetFaultDetectionCounter
(
    P2VAR(sint8, AUTOMATIC, RTE_APPL_DATA) FaultDetectionCounter
);
#define Dem_Rte_Event_0xD23487_GetFaultDetectionCounter     Rte_Call_Dem_CBFaultDetectCtr_Event_0xD23487_GetFaultDetectionCounter
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dem_CBFaultDetectCtr_Event_0xD23487_GetFaultDetectionCounter
(
    P2VAR(sint8, AUTOMATIC, RTE_APPL_DATA) FaultDetectionCounter
);
#define Dem_Rte_Event_0xD23587_GetFaultDetectionCounter     Rte_Call_Dem_CBFaultDetectCtr_Event_0xD23587_GetFaultDetectionCounter
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dem_CBFaultDetectCtr_Event_0xD23587_GetFaultDetectionCounter
(
    P2VAR(sint8, AUTOMATIC, RTE_APPL_DATA) FaultDetectionCounter
);
#define Dem_Rte_Event_0xD23687_GetFaultDetectionCounter     Rte_Call_Dem_CBFaultDetectCtr_Event_0xD23687_GetFaultDetectionCounter
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dem_CBFaultDetectCtr_Event_0xD23687_GetFaultDetectionCounter
(
    P2VAR(sint8, AUTOMATIC, RTE_APPL_DATA) FaultDetectionCounter
);
#define Dem_Rte_CallbackDTCStatusChange                     Rte_Call_Dem_CBStatusDTC_DTCStatus_CallbackDTCStatusChange
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dem_CBStatusDTC_DTCStatus_CallbackDTCStatusChange
(
    VAR(Dem_UdsDTCType, AUTOMATIC) DTC,
    VAR(Dem_UdsStatusByteType, AUTOMATIC) DTCStatusOld,
    VAR(Dem_UdsStatusByteType, AUTOMATIC) DTCStatusNew
);
#define Dem_Rte_DataElement_0x4F01_EcuVoltage_ReadDataElement         Rte_Call_Dem_DataServices_DataElement_0x4F01_EcuVoltage_ReadData
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dem_DataServices_DataElement_0x4F01_EcuVoltage_ReadData
(
    P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) Data
);
#define Dem_Rte_DataElement_0x4F02_TotalMileage_ReadDataElement       Rte_Call_Dem_DataServices_DataElement_0x4F02_TotalMileage_ReadData
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dem_DataServices_DataElement_0x4F02_TotalMileage_ReadData
(
    P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) Data
);
#define Dem_Rte_DataElement_0x4F03_LocalTimeSignal_ReadDataElement    Rte_Call_Dem_DataServices_DataElement_0x4F03_LocalTimeSignal_ReadData
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dem_DataServices_DataElement_0x4F03_LocalTimeSignal_ReadData
(
    P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) Data
);
#define Dem_Rte_DataElement_0x4F04_VehicleSpeed_ReadDataElement       Rte_Call_Dem_DataServices_DataElement_0x4F04_VehicleSpeed_ReadData
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dem_DataServices_DataElement_0x4F04_VehicleSpeed_ReadData
(
    P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) Data
);
#define Dem_Rte_DataElement_0x4F05_ReadyState_ReadDataElement         Rte_Call_Dem_DataServices_DataElement_0x4F05_ReadyState_ReadData
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dem_DataServices_DataElement_0x4F05_ReadyState_ReadData
(
    P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) Data
);
#define Dem_Rte_DataElement_Priority_ReadDataElement        Rte_Call_Dem_DataServices_DataElement_Priority_ReadData
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dem_DataServices_DataElement_Priority_ReadData
(
    P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) Data
);

#define RTE_STOP_SEC_CODE
#include "MemMap.h"

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif  /*RTE_DEM_H*/


