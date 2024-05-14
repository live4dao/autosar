/*  BEGIN_FILE_HDR
********************************************************************************
*   File Name       : Rte_Main.h
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
#ifndef RTE_MAIN_H
#define RTE_MAIN_H
/*******************************************************************************
*   Includes.
*******************************************************************************/
#include "Rte.h"

#define RTE_START_SEC_CODE
#include "MemMap.h"

/*Rte*/
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Start(void);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Stop(void);



/*SchM*/
extern FUNC(void, RTE_CODE) SchM_Init(void);
extern FUNC(void, RTE_CODE) SchM_Deinit(void);
#define RTE_STOP_SEC_CODE
#include "MemMap.h"
#endif



