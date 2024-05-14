/*  BEGIN_FILE_HDR
********************************************************************************
*   File Name       : CanSM_Callout.c
********************************************************************************
*   Project/Product : AUTOSAR BSW PROJECT
*   Title           : CanSM module configuration File
*   Author          : Hirain
********************************************************************************
*   Description     : CanSM module configuration File
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


/*******************************************************************************
*   Includes
*******************************************************************************/
#include "CanSM.h"


/* Input File User Code start*/
#include "Rte_Dem.h"
/* Input File User Code end*/
#define CANSM_START_SEC_CODE
#include "MemMap.h"

FUNC(void, CANSM_CODE) CanSM_EnterBorL1_Indication
(
    NetworkHandleType Channel
)
{

/* CanSM_EnterBorL1_Indication User Code start*/
	if(CanSM_ComM_CanCtrl_0 == Channel) {
//		Rte_Call_EnableCond_ACAN_NoBusOff_SetEnableCondition(FALSE);
	}
	else if(CanSM_ComM_CanCtrl_0 == Channel) {
//		Rte_Call_EnableCond_ACAN_NoBusOff_SetEnableCondition(FALSE);
	}
	else {

	}
/* CanSM_EnterBorL1_Indication User Code end*/
}

FUNC(void, CANSM_CODE) CanSM_EnterBorL2_Indication
(
    NetworkHandleType Channel
)
{

/* CanSM_EnterBorL2_Indication User Code start*/

/* CanSM_EnterBorL2_Indication User Code end*/
}

FUNC(void, CANSM_CODE) CanSM_BORSuccess_Indication
(
    NetworkHandleType Channel
)
{

/* CanSM_BORSuccess_Indication User Code start*/
	if(CanSM_ComM_CanCtrl_0 == Channel) {
//		Rte_Call_EnableCond_ACAN_NoBusOff_SetEnableCondition(TRUE);
	}
	else if(CanSM_ComM_CanCtrl_0 == Channel) {
//		Rte_Call_EnableCond_ACAN_NoBusOff_SetEnableCondition(TRUE);
	}
	else {

	}
/* CanSM_BORSuccess_Indication User Code end*/
}

#define CANSM_STOP_SEC_CODE
#include "MemMap.h"


