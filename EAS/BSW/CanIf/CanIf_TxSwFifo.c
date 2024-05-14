/* BEGIN_FILE_HDR
********************************************************************************
* NOTICE
* This software is the property of HiRain Technologies. Any information
* contained in this doc should not be reproduced, or used, or disclosed
* without the written authorization from HiRain Technologies.
********************************************************************************
* File Name:       Can_Sw_Fifo.c
********************************************************************************
* Project/Product: AUTOSAR  PROJECT
* Title:           CanIf_TxSwFifo.c
* Author:          Hirain
********************************************************************************
* Description:      tx sw fifo implement 
*
********************************************************************************
* Limitations     : None
*
********************************************************************************
*
********************************************************************************
*   Revision History:
*   Reference to Core C File
********************************************************************************
* END_FILE_HDR*/

/*******************************************************************************
*   Includes
*******************************************************************************/
#include "CanIf.h"

#if(STD_ON == CANIF_PRIVATE_SWTXFIFO_SUPPORT)

/*****************************************************************************
* static variables define
******************************************************************************/
#define CANIF_START_SEC_VAR_NOINIT_8
#include "MemMap.h"
STATIC VAR(boolean, CANIF_VAR)  CanIf_TxSwFifo_IsHthBusy[CANIF_MAX_HTH_NUM];

#if(CANIF_PRIVATE_SWTXFIFO_RETRY == STD_ON)
STATIC VAR(uint8, CANIF_VAR)  CanIf_TxSwFifo_HthTxCnt[CANIF_MAX_HTH_NUM];
#endif

#define CANIF_STOP_SEC_VAR_NOINIT_8
#include "MemMap.h"

#define CANIF_START_SEC_CODE
#include "MemMap.h"
STATIC FUNC(Can_ReturnType, CANIF_CODE) CanIf_TxSwFifo_AddMsgToFifo
(
    Can_HwHandleType Hth,
    P2CONST(Can_PduType, AUTOMATIC, CANIF_APPL_DATA) PduInfo
);

STATIC FUNC(void, CANIF_CODE) CanIf_TxSwFifo_GetNextMsg
(
    Can_HwHandleType Hth,
    P2VAR(Can_PduType, AUTOMATIC, AUTOMATIC) PduInfo
);

STATIC FUNC(boolean, CANIF_CODE) CanIf_TxSwFifo_DelMsgFromFifo
(
    Can_HwHandleType Hth,
    PduIdType CanTxPduId
);

#define CANIF_STOP_SEC_CODE
#include "MemMap.h"


#if(CANIF_PRIVATE_SWTXFIFO_DEBUG == STD_ON)
#define CANIF_TXSWFIFO_DEBUG_LOOP()    while(1)
#else
#define CANIF_TXSWFIFO_DEBUG_LOOP()
#endif

#define CANIF_PRIVATE_SWTXFIFO_TXTIMEOUT_STOP_VAL      ((uint8)0xFF)

#define CANIF_START_SEC_CODE
#include "MemMap.h"
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: CanIf_TxSwFifo_ResetFifo
*
* Description:   reset fifo,called from init or fetaerror
*
* Inputs:        Hth. Hth of canif level, start from 0
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, CANIF_CODE) CanIf_TxSwFifo_ResetFifo
(
    Can_HwHandleType Hth
)
{
    P2VAR(CanIf_TxSwFifo_Que_Type, AUTOMATIC, CANIF_VAR_NOINIT) fifoCtrlPtr = CANIF_HTH_CFG_INFO[Hth].fifoCtrl;
    P2VAR(CanIf_TxSwFifo_Buf_Type, AUTOMATIC, CANIF_VAR_NOINIT) fifoBufPtr = CANIF_HTH_CFG_INFO[Hth].fifoBuf;
    uint8 i = (uint8)0;
	
	P2VAR(uint8, AUTOMATIC, CANIF_VAR_NOINIT) tmpPtr = NULL_PTR;


    if(fifoCtrlPtr != NULL_PTR)
    {
        fifoCtrlPtr->Header = CANIF_TXSWFIFO_INVALID_POS;
        fifoCtrlPtr->Tail = 0;
    }

    /*init sdu ptr*/
    if(fifoBufPtr != NULL_PTR)
    {   
        for(i = (uint8)0; i < CANIF_HTH_CFG_INFO[Hth].quedepth; i++)
        {
			/*must cast to single pointer
			  as dlc is same in different hth, and P2P2 pointer can not add directly
			*/
			/*fifoBufPtr[i].sdu = (uint8 *)(&(CANIF_HTH_CFG_INFO[Hth].fifoData[i]));*/
			tmpPtr = (uint8 *)CANIF_HTH_CFG_INFO[Hth].fifoData;
			tmpPtr += i * CANIF_HTH_CFG_INFO[Hth].sbufsize;

            fifoBufPtr[i].sdu = (uint8 *)tmpPtr;
			
			
        }
    }


    CanIf_TxSwFifo_IsHthBusy[Hth] = FALSE;
#if(CANIF_PRIVATE_SWTXFIFO_RETRY == STD_ON)
    CanIf_TxSwFifo_HthTxCnt[Hth] = CANIF_PRIVATE_SWTXFIFO_TXTIMEOUT_STOP_VAL; /*means stop counting*/
#endif
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: CanIf_TxSwFifo_AddMsgToFifo
*
* Description:   add msg to fifo
*
* Inputs:        Hth. Hth of canif level, start from 0
*                PduInfo msg need to add
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(Can_ReturnType, CANIF_CODE) CanIf_TxSwFifo_AddMsgToFifo
(
    Can_HwHandleType Hth,
    P2CONST(Can_PduType, AUTOMATIC, CANIF_APPL_DATA) PduInfo
)
{
    uint8 i;
    P2VAR(CanIf_TxSwFifo_Que_Type, AUTOMATIC, CANIF_VAR_NOINIT) fifoCtrlPtr = CANIF_HTH_CFG_INFO[Hth].fifoCtrl;
    P2VAR(CanIf_TxSwFifo_Buf_Type, AUTOMATIC, CANIF_VAR_NOINIT) fifoBufPtr = CANIF_HTH_CFG_INFO[Hth].fifoBuf;

    uint8 tail = fifoCtrlPtr->Tail;
    uint8 header = fifoCtrlPtr->Header;
    Can_ReturnType ret = CAN_OK;

    if(tail == CANIF_TXSWFIFO_INVALID_POS)/* buffer full */
    {
        ret = CAN_NOT_OK;
        CANIF_TXSWFIFO_DEBUG_LOOP();
    }
    else
    {
        /* queue is not full, fill the tail buffer and tail++*/
        fifoBufPtr[tail].swPduHandle = PduInfo->swPduHandle;
        fifoBufPtr[tail].length = PduInfo->length;
        fifoBufPtr[tail].id = PduInfo->id;
        for(i = (uint8)0; i < PduInfo->length; i++)
        {
            fifoBufPtr[tail].sdu[i] = PduInfo->sdu[i];
        }

        tail++;
        if(tail >= CANIF_HTH_CFG_INFO[Hth].quedepth)
        {
            tail = (uint8)0;
        }

        if(CANIF_TXSWFIFO_INVALID_POS == header)
        {
            fifoCtrlPtr->Header = (uint8)0;
        }

        if(tail == fifoCtrlPtr->Header)
        {
            tail = CANIF_TXSWFIFO_INVALID_POS;
        }

        fifoCtrlPtr->Tail = tail;
    }        
    return ret;

}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: CanIf_TxSwFifo_DelMsgFromFifo
*
* Description:   del 1 msg from fifo
*
* Inputs:        Hth,CanTxPduId
*
* Outputs:       boolean: fifo empty or not after del
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(boolean, CANIF_CODE) CanIf_TxSwFifo_DelMsgFromFifo
(
    Can_HwHandleType Hth,
    PduIdType CanTxPduId
)
{
    P2VAR(CanIf_TxSwFifo_Que_Type, AUTOMATIC, CANIF_VAR_NOINIT) fifoCtrlPtr = CANIF_HTH_CFG_INFO[Hth].fifoCtrl;
    P2VAR(CanIf_TxSwFifo_Buf_Type, AUTOMATIC, CANIF_VAR_NOINIT) fifoBufPtr = CANIF_HTH_CFG_INFO[Hth].fifoBuf;
    uint8 tail = fifoCtrlPtr->Tail;
    uint8 header = fifoCtrlPtr->Header;
    boolean emptyflag = FALSE;

    if ((tail == 0) && (header == CANIF_TXSWFIFO_INVALID_POS))
    {
        /* try to del msg but fifo is empty, this feta error*/
        CANIF_TXSWFIFO_DEBUG_LOOP();
        CanIf_TxSwFifo_ResetFifo(Hth);
        emptyflag = TRUE;/*return empty so in txconfirmaton do nothing, reset so that app can send again next cycle*/
    }
    else
    {
        if((header < CANIF_HTH_CFG_INFO[Hth].quedepth) && (CanTxPduId == fifoBufPtr[header].swPduHandle))
        {
            if(tail == CANIF_TXSWFIFO_INVALID_POS)
            {
                tail = header;
            }

            header++;
            if(header >= CANIF_HTH_CFG_INFO[Hth].quedepth)
            {
                header = (uint8)0;
            }


            fifoCtrlPtr->Tail = tail;
            fifoCtrlPtr->Header = header;

            /* if queue is empty, reset header and tail */
            if(fifoCtrlPtr->Tail == fifoCtrlPtr->Header)
            {
                fifoCtrlPtr->Tail = (uint8)0;
                fifoCtrlPtr->Header = CANIF_TXSWFIFO_INVALID_POS;
                emptyflag = TRUE;
            }
        }
        else
        {
            /* try to del msg but fifo is empty, this feta error*/
            CANIF_TXSWFIFO_DEBUG_LOOP();
            CanIf_TxSwFifo_ResetFifo(Hth);
            emptyflag = TRUE;/*return empty so in txconfirmaton do nothing, reset so that app can send again next cycle*/
        }
    }

    return emptyflag;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: CanIf_TxSwFifo_GetNextMsg
*
* Description:   get next msg from fifo
*
* Inputs:        Hth,PduInfo
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, CANIF_CODE) CanIf_TxSwFifo_GetNextMsg
(
    Can_HwHandleType Hth,
    P2VAR(Can_PduType, AUTOMATIC, AUTOMATIC) PduInfo
)
{
    P2VAR(CanIf_TxSwFifo_Que_Type, AUTOMATIC, CANIF_VAR_NOINIT) fifoCtrlPtr = CANIF_HTH_CFG_INFO[Hth].fifoCtrl;
    P2VAR(CanIf_TxSwFifo_Buf_Type, AUTOMATIC, CANIF_VAR_NOINIT) fifoBufPtr = CANIF_HTH_CFG_INFO[Hth].fifoBuf;
    uint8 header = fifoCtrlPtr->Header;

    if(header < ((uint8)CANIF_HTH_CFG_INFO[Hth].quedepth))
    {
        PduInfo->id = fifoBufPtr[header].id;
        PduInfo->length = fifoBufPtr[header].length;
        PduInfo->swPduHandle = fifoBufPtr[header].swPduHandle;
        PduInfo->sdu  = fifoBufPtr[header].sdu;
    }
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: CanSwFifo_Write
*
* Description:   send msg or add to fifo
*
* Inputs:        Hth,PduInfo
*
* Outputs:       Can_ReturnType
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Can_ReturnType, CANIF_CODE) CanIf_TxSwFifo_Write
(
    Can_HwHandleType Hth,
    P2CONST(Can_PduType, AUTOMATIC, CAN_APPL_DATA) PduInfo
)
{
    Can_ReturnType ret = CAN_OK;
    boolean sendflag = FALSE;

    CanIf_CanWriteType canWriteFctPtr;
    uint8 ctrlIdx = (uint8)0;

/* Access Controller*/
#if(STD_ON == CANIF_PUBLIC_MULTIPLE_DRV_SUPPORT)
    ctrlIdx = CanIf_CtrlCfg[CANIF_HTH_CFG_INFO[Hth].CanIfCtrlIdRef].CanDrvIndex;
#endif

    canWriteFctPtr = CanIf_Can_Write[ctrlIdx];

    /*hth alreadcheck */

    if((CANIF_HTH_CFG_INFO[Hth].quedepth > (uint8)0) && (CANIF_HTH_CFG_INFO[Hth].fifoCtrl != NULL_PTR))
    {
        /* to reduce cost need new area4*/
        SchM_Enter_CanIf_CANIF_EXCLUSIVE_AREA_4();
        /*when gw pdu route, this may be called in isr context, when exit, resume will not re-enable interrpt*/

        if(CanIf_TxSwFifo_IsHthBusy[Hth] == FALSE) /*no msg txing*/
        {
            CanIf_TxSwFifo_IsHthBusy[Hth] = TRUE;
            sendflag = TRUE;
        }
        /*no matter queue empty or not, add msg to queue; if queue full return notok*/ 
        ret = CanIf_TxSwFifo_AddMsgToFifo(Hth, PduInfo);
        if((sendflag == TRUE) && (ret == CAN_OK))
        {
#if(CANIF_PRIVATE_SWTXFIFO_RETRY == STD_ON)
        	/*if first tx, start cnt*/
            if(CanIf_TxSwFifo_HthTxCnt[Hth] == CANIF_PRIVATE_SWTXFIFO_TXTIMEOUT_STOP_VAL)
            {
            	CanIf_TxSwFifo_HthTxCnt[Hth] = CANIF_PRIVATE_SWTXFIFO_TXTIMEOUT_VAL;
            }
#endif
            ret = canWriteFctPtr(CANIF_HTH_CFG_INFO[Hth].HthIdSymRef, PduInfo);
            if(CAN_OK != ret)      
            {   
                /* this is not possible, if happened reset*/
                /* if busy need to call cancel to cancel msg*/
                CANIF_TXSWFIFO_DEBUG_LOOP();
                CanIf_TxSwFifo_ResetFifo(Hth);

            }
        }


        SchM_Exit_CanIf_CANIF_EXCLUSIVE_AREA_4();
    }
    else
    {
        /* no fifo for this hth  call canwrite directly*/
        ret = canWriteFctPtr(CANIF_HTH_CFG_INFO[Hth].HthIdSymRef, PduInfo);
    }
    return ret;
        
}



/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: CanIf_TxSwFifo_TxConfirmation
*
* Description:   called in CanIf_TxConfirmation
*
* Inputs:        Hth,PduInfo
*
* Outputs:       Can_ReturnType
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, CANIF_CODE) CanIf_TxSwFifo_TxConfirmation
(
    PduIdType CanTxPduId
)
{
    Can_HwHandleType Hth = CANIF_TXPDU_CFG_INFO[CanTxPduId].HthRef;

    CanIf_CanWriteType canWriteFctPtr;
    boolean emptyflag = FALSE;
    boolean sendflag = FALSE;
    Can_PduType PduInfo;
    Std_ReturnType ret;

    uint8 ctrlIdx = (uint8)0;

/* Access Controller*/
#if(STD_ON == CANIF_PUBLIC_MULTIPLE_DRV_SUPPORT)
    ctrlIdx = CanIf_CtrlCfg[CANIF_HTH_CFG_INFO[Hth].CanIfCtrlIdRef].CanDrvIndex;
#endif

    canWriteFctPtr = CanIf_Can_Write[ctrlIdx];


    if((CANIF_HTH_CFG_INFO[Hth].quedepth > (uint8)0) && (CANIF_HTH_CFG_INFO[Hth].fifoCtrl != NULL_PTR))
    {
        SchM_Enter_CanIf_CANIF_EXCLUSIVE_AREA_5();
        if(CanIf_TxSwFifo_IsHthBusy[Hth] == FALSE)
        {
            /*tx not busy but enter txconfirmation, this is not possible */
            CANIF_TXSWFIFO_DEBUG_LOOP();
            CanIf_TxSwFifo_ResetFifo(Hth);
        }
        else
        {
#if(CANIF_PRIVATE_SWTXFIFO_RETRY == STD_ON)
        	/* reset timeout when enter confirmation*/
        	CanIf_TxSwFifo_HthTxCnt[Hth] = CANIF_PRIVATE_SWTXFIFO_TXTIMEOUT_VAL;
#endif
            emptyflag = CanIf_TxSwFifo_DelMsgFromFifo(Hth, CanTxPduId);
            if(emptyflag == TRUE)
            {
                /* del all msg */
                CanIf_TxSwFifo_IsHthBusy[Hth] = FALSE;
#if(CANIF_PRIVATE_SWTXFIFO_RETRY == STD_ON)
				/* stop timeout when no more tx request*/
				CanIf_TxSwFifo_HthTxCnt[Hth] = CANIF_PRIVATE_SWTXFIFO_TXTIMEOUT_STOP_VAL;
#endif
            }
            else
            {
                sendflag = TRUE;
                CanIf_TxSwFifo_GetNextMsg(Hth, &PduInfo);
            }
        }
        /*send next msg */
        SchM_Exit_CanIf_CANIF_EXCLUSIVE_AREA_5();

        if(sendflag == TRUE)
        {
            ret = canWriteFctPtr(CANIF_HTH_CFG_INFO[Hth].HthIdSymRef, &PduInfo);
            if(CAN_OK != ret) /* this is not possible, if happened reset*/
            {    
                /* this is not possible, if happened reset*/
                /* if busy need to call cancel to cancel msg*/
                CANIF_TXSWFIFO_DEBUG_LOOP();
                CanIf_TxSwFifo_ResetFifo(Hth);
            }
        }
    }

    /* no fifo for this hth  do nothing*/

}

#if(CANIF_PRIVATE_SWTXFIFO_RETRY == STD_ON)
FUNC(void, CANIF_CODE) CanIf_TxSwFifo_MainFunction(void)
{
	Can_HwHandleType Hth = (Can_HwHandleType)0;


	for(Hth = (Can_HwHandleType)0; Hth < CANIF_USED_HTH_NUM; Hth++)
	{
		if(CanIf_TxSwFifo_HthTxCnt[Hth] != CANIF_PRIVATE_SWTXFIFO_TXTIMEOUT_STOP_VAL)
		{
			if(CanIf_TxSwFifo_HthTxCnt[Hth] == (uint8)0)
			{
				/* timeout*/
				CANIF_TXSWFIFO_DEBUG_LOOP();
				CanIf_TxSwFifo_ResetFifo(Hth);
			}
			if(CanIf_TxSwFifo_HthTxCnt[Hth] > (uint8)0)
			{
				CanIf_TxSwFifo_HthTxCnt[Hth]--;
			}
		}

	}


}
#endif


#define CANIF_STOP_SEC_CODE
#include "MemMap.h"


#endif/*#if(STD_ON == CANIF_PRIVATE_SWTXFIFO_SUPPORT)*/
