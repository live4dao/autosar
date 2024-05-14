/*  BEGIN_FILE_HDR
********************************************************************************
*   File Name       : Os_GenHook.c
********************************************************************************
*   Project/Product : AUTOSAR BSW PROJECT
*   Title           : OS module configuration File
*   Author          : Hirain
********************************************************************************
*   Description     : OS module configuration File
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

#include "Os.h"
/* Input File User Code start*/
#include "Can_17_McmCan.h"
#include "Eth_17_GEthMacV2.h"
/* Input File User Code end*/

/*****************************************************************************
* General QAC Suppression
******************************************************************************/
/*PRQA S 0862 EOF*/
/*
The code segment like:

#define XXX
#include "Os_MemMap.h"

is a part of AUTOSAR specification, but will be an error in PRQA.
*/

/*PRQA S 3206 EOF*/
/* Some parameters which are not used in OS code are reserved for users. */
#define OS_START_SEC_CALLOUT_CODE
#include "Os_MemMap.h"


/*-------------------------------------------------------*/
/*-------------------HOOK FUNCTION----------------------*/
/*-------------------------------------------------------*/

/*ErrorHook*/
FUNC(void, OS_CALLOUT_CODE) ErrorHook(StatusType Error)
{
    /* ErrorHook User Code start*/

    /* ErrorHook User Code end*/
}


/*Isr Function*/
FUNC(void, OS_CALLOUT_CODE) ISR_CAN0_Core0_CAN2SR0(void)
{
    /* ISR_CAN0_Core0_CAN2SR0 User Code start*/
	Can_17_McmCan_IsrReceiveHandler(CAN_17_MCMCAN_HWMCMKERNEL2_ID, (uint8)0); //CAN_17_MCMCAN_HWMCMCONTROLLER0_ID = 0
    /* ISR_CAN0_Core0_CAN2SR0 User Code end*/
}

/*Isr Function*/
FUNC(void, OS_CALLOUT_CODE) ISR_CAN0_Core0_CAN2SR1(void)
{
    /* ISR_CAN0_Core0_CAN2SR1 User Code start*/
	Can_17_McmCan_IsrTransmitHandler(CAN_17_MCMCAN_HWMCMKERNEL2_ID, (uint8)0); //CAN_17_MCMCAN_HWMCMCONTROLLER0_ID = 0
    /* ISR_CAN0_Core0_CAN2SR1 User Code end*/
}

/*Isr Function*/
FUNC(void, OS_CALLOUT_CODE) ISR_CAN0_Core0_CAN2SR2(void)
{
    /* ISR_CAN0_Core0_CAN2SR2 User Code start*/
	Can_17_McmCan_IsrBusOffHandler(CAN_17_MCMCAN_HWMCMKERNEL2_ID, (uint8)0); //CAN_17_MCMCAN_HWMCMCONTROLLER0_ID = 0
    /* ISR_CAN0_Core0_CAN2SR2 User Code end*/
}

/*Isr Function*/
FUNC(void, OS_CALLOUT_CODE) ISR_CAN0_Core0_CAN2SR3(void)
{
    /* ISR_CAN0_Core0_CAN2SR3 User Code start*/
	Can_17_McmCan_IsrRxFIFOHandler(CAN_17_MCMCAN_HWMCMKERNEL2_ID, (uint8)0); //CAN_17_MCMCAN_HWMCMCONTROLLER0_ID = 0
    /* ISR_CAN0_Core0_CAN2SR3 User Code end*/
}

/*Isr Function*/
FUNC(void, OS_CALLOUT_CODE) ISR_CAN1_Core0_CAN2SR4(void)
{
    /* ISR_CAN1_Core0_CAN2SR4 User Code start*/
	Can_17_McmCan_IsrReceiveHandler(CAN_17_MCMCAN_HWMCMKERNEL2_ID, (uint8)1); //CAN_17_MCMCAN_HWMCMCONTROLLER1_ID = 1
    /* ISR_CAN1_Core0_CAN2SR4 User Code end*/
}

/*Isr Function*/
FUNC(void, OS_CALLOUT_CODE) ISR_CAN1_Core0_CAN2SR5(void)
{
    /* ISR_CAN1_Core0_CAN2SR5 User Code start*/
	Can_17_McmCan_IsrTransmitHandler(CAN_17_MCMCAN_HWMCMKERNEL2_ID, (uint8)1); //CAN_17_MCMCAN_HWMCMCONTROLLER1_ID = 1
    /* ISR_CAN1_Core0_CAN2SR5 User Code end*/
}

/*Isr Function*/
FUNC(void, OS_CALLOUT_CODE) ISR_CAN1_Core0_CAN2SR6(void)
{
    /* ISR_CAN1_Core0_CAN2SR6 User Code start*/
	Can_17_McmCan_IsrBusOffHandler(CAN_17_MCMCAN_HWMCMKERNEL2_ID, (uint8)1); //CAN_17_MCMCAN_HWMCMCONTROLLER1_ID = 1
    /* ISR_CAN1_Core0_CAN2SR6 User Code end*/
}

/*Isr Function*/
FUNC(void, OS_CALLOUT_CODE) ISR_CAN1_Core0_CAN2SR7(void)
{
    /* ISR_CAN1_Core0_CAN2SR7 User Code start*/
	Can_17_McmCan_IsrRxFIFOHandler(CAN_17_MCMCAN_HWMCMKERNEL2_ID, (uint8)1); //CAN_17_MCMCAN_HWMCMCONTROLLER1_ID = 1
    /* ISR_CAN1_Core0_CAN2SR7 User Code end*/
}

/*Isr Function*/
FUNC(void, OS_CALLOUT_CODE) ISR_Core0_ETHSR2(void)
{
    /* ISR_Core0_ETHSR2 User Code start*/
	Eth_17_GEthMacV2_TxDmaIrqHdlr(0,0);
    /* ISR_Core0_ETHSR2 User Code end*/
}

/*Isr Function*/
FUNC(void, OS_CALLOUT_CODE) ISR_Core0_ETHSR6(void)
{
    /* ISR_Core0_ETHSR6 User Code start*/
	Eth_17_GEthMacV2_RxDmaIrqHdlr(0,0);
    /* ISR_Core0_ETHSR6 User Code end*/
}

#define OS_STOP_SEC_CALLOUT_CODE
#include "Os_MemMap.h"

