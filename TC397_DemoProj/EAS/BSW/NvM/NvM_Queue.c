/*  BEGIN_FILE_HDR
********************************************************************************
*   NOTICE
*   This software is the property of HiRain Technologies. Any information
*   contained in this doc should not be reproduced, or used, or disclosed
*   without the written authorization from HiRain Technologies.
********************************************************************************
*   File Name       : NvM_Queue.c
********************************************************************************
*   Project/Product : AUTOSAR BSW
*   Title           : NvM module source File
*   Author          : Hirain
********************************************************************************
*   Description     : Implementation of Non-Volatile RAM manager.
*
********************************************************************************
*   Limitations     :
*
********************************************************************************
*
********************************************************************************
*   Revision History
********************************************************************************
* END_FILE_HDR*/

/*******************************************************************************
    Include Files
*******************************************************************************/
#include "NvM.h"
/*******************************************************************
* PRQA S 506
* Dereferencing pointer value that is possibly NULL.
* PRQA S 3869
* Indexing array with value that will apparently be out of bounds.
* MISRA-C:2004 Rule 21.1;
* All functions in this file is called by NvM's API, All the parameters will
* be checked in NVM API, no need to check again.
* This part of code is verified manually and has no impact.
*******************************************************************/

/*******************************************************************************
    Macro Definition
*******************************************************************************/

/*******************************************************************************
    Type Definition
*******************************************************************************/

/*******************************************************************************
    Variable  Definition
*******************************************************************************/
#if(STD_ON == NVM_BSWM_SUPPORT)
#include "BswM_NvM.h"
#endif

#define NVM_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h"

#if(STD_ON == NVM_IMM_BLOCK_SUPPORT)
VAR(NvM_Que_Type, NVM_VAR_NOINIT) NvM_ImmQueue;
VAR(NvM_QueBuf_Type, NVM_VAR_NOINIT) NvM_PreemptJob;

#endif
STATIC VAR(NvM_Que_Type, NVM_VAR_NOINIT) NvM_StandardQueue;
VAR(NvM_QueBuf_Type, NVM_VAR_NOINIT) NvM_MultiJob;
#define NVM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h"

/*******************************************************************************
    Prototype  Declaration
*******************************************************************************/
#define NVM_START_SEC_CODE
#include "MemMap.h"
STATIC FUNC(Std_ReturnType, NVM_CODE) NvM_PushJob
(
    const NvM_BlockIdType BlockId,
    const uint8 ServiceId,
    CONSTP2VAR(uint8, AUTOMATIC, NVM_APPL_DATA)  ramAddr,
    CONSTP2VAR(NvM_Que_Type, AUTOMATIC, NVM_VAR_NOINIT)  QuePtr,
    const uint8 maxQueueSize,
    CONSTP2VAR(NvM_QueBuf_Type, AUTOMATIC, NVM_VAR_NOINIT)  QueBufPtr
);
STATIC FUNC(void, NVM_CODE) NvM_PopJob
(
    const uint8 QueIndex,
    CONSTP2VAR(NvM_Que_Type, AUTOMATIC, NVM_VAR_NOINIT)  QuePtr,
    const uint8 maxQueueSize,
    CONSTP2VAR(NvM_QueBuf_Type, AUTOMATIC, NVM_VAR_NOINIT)  QueBufPtr
);

STATIC FUNC(boolean, NVM_CODE) NvM_IsBlockInQueue
(
    CONST(NvM_BlockIdType, AUTOMATIC) BlockId,
    CONSTP2CONST(NvM_Que_Type, AUTOMATIC, NVM_VAR_NOINIT)  QuePtr,
    const uint8 maxQueueSize,
    CONSTP2CONST(NvM_QueBuf_Type, AUTOMATIC, NVM_VAR_NOINIT)  QueBufPtr,
    CONSTP2VAR(uint8, AUTOMATIC, AUTOMATIC)  index
);

#if(STD_ON ==NVM_JOB_PRIORITIZATION)
STATIC FUNC(void, NVM_CODE) NvM_SortPriQueue(void);
#endif

/*******************************************************************************
    Function  Definition
*******************************************************************************/

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: NvM_ClearJob
*
* Description:  Clear all job from queue.
*
* Inputs:       None
*
* Outputs:      None
*
* Limitations:  None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, NVM_CODE) NvM_ClearJob(void)
{
    uint8 index;

#if(STD_ON == NVM_IMM_BLOCK_SUPPORT)
    for(index = (uint8)0; index < NVM_SIZE_IMMEDIATE_JOB_QUEUE; index++)
    {
        NvM_ImmQueBuf[index].BlockId   = NVM_INVALID_BLOCKID;
        NvM_ImmQueBuf[index].ServiceId = NVM_JOB_IDLE;
        NvM_ImmQueBuf[index].RamAddr = NVM_NULL;

    }
    NvM_ImmQueue.Header = NVM_QUE_INVALID_POS;
    NvM_ImmQueue.Tail = (uint8)0;

    NvM_PreemptJob.BlockId   = NVM_INVALID_BLOCKID;
    NvM_PreemptJob.ServiceId = NVM_JOB_IDLE;
    NvM_PreemptJob.RamAddr = NVM_NULL;
	
#endif
    for(index = (uint8)0; index < NVM_SIZE_STANDARD_JOB_QUEUE; index++)
    {
        NvM_QueBuf[index].BlockId   = NVM_INVALID_BLOCKID;
        NvM_QueBuf[index].ServiceId = NVM_JOB_IDLE;
        NvM_QueBuf[index].RamAddr = NVM_NULL;

    }
    NvM_StandardQueue.Header = NVM_QUE_INVALID_POS;
    NvM_StandardQueue.Tail = (uint8)0;
    NvM_MultiJob.BlockId   = NVM_INVALID_BLOCKID;
    NvM_MultiJob.ServiceId = NVM_JOB_IDLE;
    NvM_MultiJob.RamAddr = NVM_NULL;
}


/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: NvM_PushJob
*
* Description:   Add job to queue.
*
* Inputs:        BlockId,ServiceId,QuePtr,maxQueueSize,QueBufPtr
*
* Outputs:       Std_ReturnType:Return NotOK, when queue is full
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(Std_ReturnType, NVM_CODE) NvM_PushJob
(
    const NvM_BlockIdType BlockId,
    const uint8 ServiceId,
    CONSTP2VAR(uint8, AUTOMATIC, NVM_APPL_DATA)  ramAddr,
    CONSTP2VAR(NvM_Que_Type, AUTOMATIC, NVM_VAR_NOINIT)  QuePtr,
    const uint8 maxQueueSize,
    CONSTP2VAR(NvM_QueBuf_Type, AUTOMATIC, NVM_VAR_NOINIT)  QueBufPtr
)
{
    uint8 tail = QuePtr->Tail;
    uint8 header = QuePtr->Header;
    Std_ReturnType ret = E_OK;

    /* if buf of tail is filled and tail = header
       means ths queue is full
     */
    if(tail == NVM_QUE_INVALID_POS)
    {
        ret = E_NOT_OK;
    }
    else
    {
        /* queue is not full, fill the tail buffer and tail++*/
        QueBufPtr[tail].BlockId = BlockId;
        QueBufPtr[tail].ServiceId = ServiceId;
        QueBufPtr[tail].RamAddr = ramAddr;

        tail++;
        if(tail >= maxQueueSize)
        {
            tail = (uint8)0;
        }

        if(NVM_QUE_INVALID_POS == header)
        {
            QuePtr->Header = (uint8)0;
        }

        if(tail == QuePtr->Header)
        {
            tail = NVM_QUE_INVALID_POS;
        }

        QuePtr->Tail = tail;

    }
    return ret;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: NvM_SortPriQueue
*
* Description:   put last job to right position accroding the priority
*
* Inputs:        void
*
* Outputs:       None
*
* Limitations:   Used after job is pushed into NvM_StandardQueue
********************************************************************************
END_FUNCTION_HDR*/
#if(STD_ON ==NVM_JOB_PRIORITIZATION)
STATIC FUNC(void, NVM_CODE) NvM_SortPriQueue(void)
{

    uint8 tempPri;
    uint8 savedPri;
    uint8 header = NvM_StandardQueue.Header;
    uint8 tail = NvM_StandardQueue.Tail;
    uint8 lastIndex;
    uint8 tempIndex;
    NvM_BlockIdType saveId;
    uint8 saveSevId;
    P2VAR(uint8, AUTOMATIC, NVM_APPL_DATA)  saveRamAddr;


    if(tail == NVM_QUE_INVALID_POS)
    {
        tail = header;
    }

    if(tail > (uint8)0)
    {
        tail = tail - (uint8)1;
    }
    else
    {
        tail = NVM_SIZE_STANDARD_JOB_QUEUE - (uint8)1;
    }


    savedPri = NvM_Config[NvM_QueBuf[tail].BlockId].BlockPri;
    tempIndex = tail;

    while(tempIndex != header) /* only 1 job is in queue*/
    {

        if(tempIndex > (uint8)0)
        {
            lastIndex = tempIndex - (uint8)1;
        }
        else
        {
            lastIndex = NVM_SIZE_STANDARD_JOB_QUEUE - (uint8)1;
        }

        tempPri = NvM_Config[NvM_QueBuf[lastIndex].BlockId].BlockPri;

        if(savedPri < tempPri)   /* if pri is high switch*/
        {

            saveId = NvM_QueBuf[lastIndex].BlockId;
            saveSevId = NvM_QueBuf[lastIndex].ServiceId;
            saveRamAddr = NvM_QueBuf[lastIndex].RamAddr;

            NvM_QueBuf[lastIndex].BlockId = NvM_QueBuf[tempIndex].BlockId;
            NvM_QueBuf[lastIndex].ServiceId = NvM_QueBuf[tempIndex].ServiceId;
            NvM_QueBuf[lastIndex].RamAddr = NvM_QueBuf[tempIndex].RamAddr;


            NvM_QueBuf[tempIndex].BlockId = saveId;
            NvM_QueBuf[tempIndex].ServiceId = saveSevId;
            NvM_QueBuf[tempIndex].RamAddr =  saveRamAddr;

            tempIndex = lastIndex;
        }
        else
        {
            break; /* sort finish */
        }

    }

}
#endif


/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: NvM_IsBlockInQueue
*
* Description:   check if the block is in queue
*
* Inputs:        BlockId
*
* Outputs:       255:invalid value,means block is not in queue
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(boolean, NVM_CODE) NvM_IsBlockInQueue
(
    CONST(NvM_BlockIdType, AUTOMATIC) BlockId,
    CONSTP2CONST(NvM_Que_Type, AUTOMATIC, NVM_VAR_NOINIT)  QuePtr,
    const uint8 maxQueueSize,
    CONSTP2CONST(NvM_QueBuf_Type, AUTOMATIC, NVM_VAR_NOINIT)  QueBufPtr,
    CONSTP2VAR(uint8, AUTOMATIC, AUTOMATIC)  index
)
{
    uint8 header = QuePtr->Header;
    uint8 QueIndex;
    uint8 retIndex = NVM_QUE_INVALID_POS;
    uint8 tail = QuePtr->Tail;
    boolean flag = FALSE;

    if(NVM_QUE_INVALID_POS != header)
    {
        if(NVM_QUE_INVALID_POS == tail)
        {
            /* queue is full search from 0 to end*/
            tail =  header;
        }

        QueIndex = header;
        do
        {
            if(QueBufPtr[QueIndex].BlockId == BlockId)
            {
                retIndex = QueIndex;
                flag = TRUE;
                break;
            }
            QueIndex++;
            if(QueIndex >= maxQueueSize)
            {
                QueIndex = (uint8)0;
            }
        }
        while(QueIndex != tail);

        if((TRUE == flag) && (NULL_PTR != index))
        {
            *index = retIndex;
        }
    }

    return flag;
}


/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: NvM_IsBlockInQueue
*
* Description:   check if the block is in queue
*
* Inputs:        BlockId  isWriteJob
*
* Outputs:       true,false
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(boolean, NVM_CODE) NvM_CheckBlockPending
(
    const NvM_BlockIdType BlockId,
    const boolean isWriteJob
)
{
    boolean ret = FALSE;

#if(STD_ON == NVM_IMM_BLOCK_SUPPORT)
    if(((uint8)0 == NvM_Config[BlockId].BlockPri)
            && (TRUE == isWriteJob))
    {
        ret = NvM_IsBlockInQueue(BlockId, &NvM_ImmQueue,
                                 NVM_SIZE_IMMEDIATE_JOB_QUEUE, NvM_ImmQueBuf, NULL_PTR);
    }
    else if(BlockId == NvM_PreemptJob.BlockId)
    {
        ret = TRUE;
    }
    else
#endif
    {
        ret = NvM_IsBlockInQueue(BlockId, &NvM_StandardQueue,
                                 NVM_SIZE_STANDARD_JOB_QUEUE, NvM_QueBuf, NULL_PTR);
    }


    return ret;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: NvM_PopJob
*
* Description:   remove job from queue.
*
* Inputs:        QueIndex,QuePtr,maxQueueSize,QueBufPtr
*
* Outputs:       None
*
* Limitations:   Used when process job or cancel job
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, NVM_CODE) NvM_PopJob
(
    const uint8 QueIndex,
    CONSTP2VAR(NvM_Que_Type, AUTOMATIC, NVM_VAR_NOINIT)  QuePtr,
    const uint8 maxQueueSize,
    CONSTP2VAR(NvM_QueBuf_Type, AUTOMATIC, NVM_VAR_NOINIT)  QueBufPtr
)
{
    uint8 tail = QuePtr->Tail;
    uint8 header = QuePtr->Header;
#if(STD_ON == NVM_CANCELJOB_API)
    uint8 next;
    uint8 tempQueIndex;
#endif

    if(QueIndex == header)
    {
        QueBufPtr[header].BlockId = NVM_INVALID_BLOCKID;
        QueBufPtr[header].ServiceId = NVM_JOB_IDLE;
        QueBufPtr[header].RamAddr =  NVM_NULL;

        if(tail == NVM_QUE_INVALID_POS)
        {
            tail = header;
        }

        header++;
        if(header >= maxQueueSize)
        {
            header = (uint8)0;
        }


        QuePtr->Tail = tail;
        QuePtr->Header = header;
    }
#if(STD_ON == NVM_CANCELJOB_API)
    else/* only used when cancel job is running */
    {

        tempQueIndex = QueIndex;
        if(tail == NVM_QUE_INVALID_POS)
        {
            if(header > (uint8)0)
            {
                tail = header - (uint8)1;
            }
            else
            {
                tail = maxQueueSize - (uint8)1;
            }
        }

        while(tempQueIndex != tail)
        {
            next = tempQueIndex + (uint8)1;
            if(next >= maxQueueSize)
            {
                next = (uint8)0;
            }
            QueBufPtr[tempQueIndex].BlockId = QueBufPtr[next].BlockId;
            QueBufPtr[tempQueIndex].ServiceId = QueBufPtr[next].ServiceId;
            QueBufPtr[tempQueIndex].RamAddr = QueBufPtr[next].RamAddr;
            tempQueIndex++;
            if(tempQueIndex >= maxQueueSize)
            {
                tempQueIndex = (uint8)0;
            }
        }
        QueBufPtr[tempQueIndex].BlockId = NVM_INVALID_BLOCKID;
        QueBufPtr[tempQueIndex].ServiceId = NVM_JOB_IDLE;
        QueBufPtr[tempQueIndex].RamAddr = NVM_NULL;
        /* move tail --*/
        if(tail > (uint8)0)
        {
            QuePtr->Tail = tail - (uint8)1;
        }
        else
        {
            QuePtr->Tail = maxQueueSize - (uint8)1;
        }
    }
#endif
    /* if queue is empty, reset header and tail */
    if(QuePtr->Tail == QuePtr->Header)
    {
        QuePtr->Tail = (uint8)0;
        QuePtr->Header = NVM_QUE_INVALID_POS;
    }

}


/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: NvM_QueueJob
*
* Description:   Add job to queue.
*
* Inputs:          BlockId :Block ID.
*                     ServiceId :Service ID.
*
* Outputs:        E_OK:Push ok
*                     E_NOT_OK:Queue is full
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, NVM_CODE) NvM_QueueJob
(
    const NvM_BlockIdType BlockId,
    const uint8 ServiceId,
    CONSTP2VAR(uint8, AUTOMATIC, NVM_APPL_DATA)  ramAddr
)
{
    Std_ReturnType  ret = E_OK;

    /*
       NvM.c must ensure BlockId and ServiceId is valid
    */

    if((NVM_JOB_READALL == ServiceId)
            || (NVM_JOB_WRITEALL == ServiceId)
            || (NVM_JOB_VALIDATEALL == ServiceId))
    {
        NvM_MultiJob.ServiceId = ServiceId;
        NvM_MultiJob.BlockId = BlockId;

        /*For intergration reason we report to BswM here.*/
#if(STD_ON == NVM_BSWM_MULTI_BLOCK_JOB_STATUS_INFORMATION)
#if(STD_CONFIG_VARIANTS_LINKTIME == NVM_CONFIG_VARIANTS)
        if(TRUE == NvM_BswMMultiBlockJobStatusInformation)
#endif
        {
            BswM_NvM_CurrentJobMode(ServiceId, NVM_REQ_PENDING);
        }
#endif
    }
    else
    {
#if(STD_ON == NVM_IMM_BLOCK_SUPPORT)
        if(((uint8)0 == NvM_Config[BlockId].BlockPri)
                && ((ServiceId == NVM_JOB_WRITE) || (ServiceId == NVM_JOB_WRITE_PRAMBLOCK)))
        {
            ret = NvM_PushJob(BlockId, ServiceId, ramAddr, &NvM_ImmQueue,
                              NVM_SIZE_IMMEDIATE_JOB_QUEUE, NvM_ImmQueBuf);

        }
        else
#endif
        {

            ret = NvM_PushJob(BlockId, ServiceId, ramAddr, &NvM_StandardQueue,
                              NVM_SIZE_STANDARD_JOB_QUEUE, NvM_QueBuf);
#if(STD_ON ==NVM_JOB_PRIORITIZATION)
            if(ret == E_OK)
            {
                NvM_SortPriQueue();
            }
#endif
        }

#if(STD_ON == NVM_BSWM_SUPPORT)
        if((ret == E_OK) && (TRUE == NvM_Config[BlockId].EnReportBswM) 
		&& (NvM_AdmBlock[BlockId].NvErrStatus != NVM_REQ_PENDING))
        {
            BswM_NvM_CurrentBlockMode(BlockId, NVM_REQ_PENDING);
        }
#endif

    }



    return ret;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: NvM_DeleteAllPengdingJobOfBlock
*
* Description:  delete all job of block in queue.
*
* Inputs:       BlockId
*
* Outputs:      None
*
* Limitations:  Used in Cancel
********************************************************************************
END_FUNCTION_HDR*/
#if(STD_ON == NVM_CANCELJOB_API)
FUNC(Std_ReturnType, NVM_CODE) NvM_DeleteAllPengdingJobOfBlock
(
    const NvM_BlockIdType BlockId
)
{
    Std_ReturnType ret = E_NOT_OK;
    uint8 index;
    uint8 SevId;

#if(STD_ON == NVM_IMM_BLOCK_SUPPORT)
    if((uint8)0 == NvM_Config[BlockId].BlockPri)
    {
        if(TRUE == NvM_IsBlockInQueue(BlockId, &NvM_ImmQueue,
                                      NVM_SIZE_IMMEDIATE_JOB_QUEUE, NvM_ImmQueBuf, &index))
        {
            SevId = NvM_ImmQueBuf[index].ServiceId;
            NvM_PopJob(index, &NvM_ImmQueue, NVM_SIZE_IMMEDIATE_JOB_QUEUE, NvM_ImmQueBuf);
            if(NvM_SingleCallBackFunPtr[BlockId] != NVM_NULL)
            {
                (void)NvM_SingleCallBackFunPtr[BlockId](SevId, NVM_REQ_CANCELLED);
            }
            ret = E_OK;
        }
    }
    if(BlockId == NvM_PreemptJob.BlockId)
    {
        NvM_PreemptJob.ServiceId = NVM_JOB_IDLE;
        NvM_PreemptJob.BlockId = NVM_INVALID_BLOCKID;
        NvM_PreemptJob.RamAddr = NULL_PTR;
	
        if(NvM_SingleCallBackFunPtr[BlockId] != NVM_NULL)
        {
            (void)NvM_SingleCallBackFunPtr[BlockId](SevId, NVM_REQ_CANCELLED);
        }
        ret = E_OK;
    }
#endif

    if(TRUE == NvM_IsBlockInQueue(BlockId, &NvM_StandardQueue,
                                  NVM_SIZE_STANDARD_JOB_QUEUE, NvM_QueBuf, &index))
    {
        SevId = NvM_QueBuf[index].ServiceId;

        NvM_PopJob(index, &NvM_StandardQueue, NVM_SIZE_STANDARD_JOB_QUEUE, NvM_QueBuf);


        if(NvM_SingleCallBackFunPtr[BlockId] != NVM_NULL)
        {
            (void)NvM_SingleCallBackFunPtr[BlockId](SevId, NVM_REQ_CANCELLED);
        }
        ret = E_OK;
    }


    return ret;
}
#endif

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: NvM_GetJob
*
* Description:   Get the high pri job from queue.
*
* Inputs:        Job :The pointer to element.
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, NVM_CODE) NvM_GetJob
(
    CONSTP2VAR(NvM_QueBuf_Type, AUTOMATIC, AUTOMATIC) Job
)
{
    Std_ReturnType ret = E_OK;


    /* first search immQueue*/
#if(STD_ON == NVM_IMM_BLOCK_SUPPORT)
    if(NvM_ImmQueue.Header != NVM_QUE_INVALID_POS)
    {
        Job->BlockId = NvM_ImmQueBuf[NvM_ImmQueue.Header].BlockId;
        Job->ServiceId = NvM_ImmQueBuf[NvM_ImmQueue.Header].ServiceId;
        Job->RamAddr = NvM_ImmQueBuf[NvM_ImmQueue.Header].RamAddr;

        NvM_PopJob(NvM_ImmQueue.Header, &NvM_ImmQueue, NVM_SIZE_IMMEDIATE_JOB_QUEUE, NvM_ImmQueBuf);
    }
    else if(NVM_JOB_IDLE != NvM_PreemptJob.ServiceId)/*Preempt job has 2nd priority*/
    {
        /* interrupted multi job has high priority than single job  EAS_SWS_NvM_003*/
        Job->BlockId = NvM_PreemptJob.BlockId;
        Job->ServiceId = NvM_PreemptJob.ServiceId;
        Job->RamAddr = NvM_PreemptJob.RamAddr;
		
        NvM_PreemptJob.ServiceId = NVM_JOB_IDLE;
        NvM_PreemptJob.BlockId = NVM_INVALID_BLOCKID;
        NvM_PreemptJob.RamAddr = NULL_PTR;
    }
    else
#endif
    {
        if(NvM_StandardQueue.Header != NVM_QUE_INVALID_POS)  /* single job will be process first*/
        {
            Job->BlockId = NvM_QueBuf[NvM_StandardQueue.Header].BlockId;
            Job->ServiceId = NvM_QueBuf[NvM_StandardQueue.Header].ServiceId;
            Job->RamAddr = NvM_QueBuf[NvM_StandardQueue.Header].RamAddr;

            NvM_PopJob(NvM_StandardQueue.Header, &NvM_StandardQueue, NVM_SIZE_STANDARD_JOB_QUEUE, NvM_QueBuf);
        }
        else
        {
            if(NvM_MultiJob.ServiceId != NVM_JOB_IDLE)/* multi job pending?*/
            {
                Job->BlockId = NvM_MultiJob.BlockId;
                Job->ServiceId = NvM_MultiJob.ServiceId;
                Job->RamAddr = NvM_MultiJob.RamAddr;

                NvM_MultiJob.ServiceId = NVM_JOB_IDLE;
                NvM_MultiJob.BlockId = NVM_INVALID_BLOCKID;
            }
            else
            {
                ret = E_NOT_OK; /* All Queue empty, no job pop out*/
            }
        }
    }



    return ret;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: IsQueueEmpty
*
* Description:   Is there job pending?
*
* Inputs:        None
*
* Outputs:       True/False
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(boolean, NVM_CODE) NvM_IsQueueEmpty(void)
{
    boolean ret = FALSE;

    if((NvM_MultiJob.ServiceId == NVM_JOB_IDLE)
#if(STD_ON == NVM_IMM_BLOCK_SUPPORT)
	&& (NvM_ImmQueue.Header == NVM_QUE_INVALID_POS)
	&& (NvM_PreemptJob.ServiceId == NVM_JOB_IDLE)
#endif
    && (NvM_StandardQueue.Header == NVM_QUE_INVALID_POS))
    {
        ret = TRUE;
    }


    return ret;

}


/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: NvM_IsMultiJobEmpty
*
* Description:   Is there multi job pending?
*
* Inputs:        None
*
* Outputs:       True/False
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(boolean, NVM_CODE) NvM_IsMultiJobEmpty(void)
{
    boolean ret = FALSE;

    if((NvM_MultiJob.ServiceId == NVM_JOB_IDLE)
#if(STD_ON == NVM_IMM_BLOCK_SUPPORT)
    && (NvM_PreemptJob.ServiceId != NVM_JOB_VALIDATEALL)
    && (NvM_PreemptJob.ServiceId != NVM_JOB_READALL)
    && (NvM_PreemptJob.ServiceId != NVM_JOB_WRITEALL)		
#endif
    && (NvM_CurrentJobInfo.ServiceId != NVM_JOB_VALIDATEALL)
    && (NvM_CurrentJobInfo.ServiceId != NVM_JOB_READALL)
    && (NvM_CurrentJobInfo.ServiceId != NVM_JOB_WRITEALL))
    {
        ret = TRUE;
    }


    return ret;

}


#define NVM_STOP_SEC_CODE
#include "MemMap.h"
