/*  BEGIN_FILE_HDR
********************************************************************************
*   NOTICE
*   This software is the property of HiRain Technologies. Any information
*   contained in this doc should not be reproduced, or used, or disclosed
*   without the written authorization from HiRain Technologies.
********************************************************************************
*   File Name       : Xcp_Std.c
********************************************************************************
*   Project/Product : AUTOSAR 4.2
*   Title           : Xcp module source File
*   Author          : Hirain
********************************************************************************
*   Description     : Implementation of Xcp provided functionality
*
********************************************************************************
*   Limitations     : None
*
********************************************************************************
*
********************************************************************************
*   Revision History:
********************************************************************************
* END_FILE_HDR*/

/*******************************************************************************
*   Includes
*******************************************************************************/
#include "Xcp_Std.h"

/*******************************************************************************
*   Macro
*******************************************************************************/
#if(STD_ON == XCP_SEEDKEY_SUPPORT)
/* Seed&Key*/
#define XCP_SEEDKEY_IDLE                 (0)
#define XCP_SEEDKEY_REMAIN_SEED          (1)
#define XCP_SEEDKEY_WAITINGKEY           (2)
#define XCP_SEEDKEY_REMAIN_KEY           (3)
#define XCP_GETSEED_POSRES_LEN           (2)
#endif
#define XCP_MODE_NUM                     ((uint8)2)
#define XCP_USER_MODE_INDEX              ((uint8)1)
#define XCP_CONNECT_POSRES_LEN           ((PduLengthType)8)

#define XCP_GETSTATUS_POSRES_LEN         ((PduLengthType)6)

#define XCP_GETCOMMMODE_POSRES_LEN       ((PduLengthType)8)

#if(STD_ON == XCP_MASTER_BLOCK_MODE_SUPPORT)
#define XCP_DOWNLOAD_FIX_BYTES           ((uint8)2)
#endif

#if(STD_ON == XCP_GETSLAVEID_SUPPORT)
#define XCP_GETIDE_POSRES_LEN            (8)
#endif

#if(STD_ON == XCP_SETREQ_SUPPORT)
#define XCP_STORECALREQ_MODE_ONLY        (1)
#define XCP_STOREDAQ_NORESUME_MODE_ONLY  (2)
#define XCP_STOREDAQ_RESUME_MODE_ONLY    (4)
#define XCP_CLEARDAQREQ_MODE_ONLY        (8)
#define XCP_ENABLE_RESUME_MODE           ((uint8)0x132U)
#define XCP_DISABLE_RESUME_MODE          ((uint8)0x127U)
#endif

#define XCP_GETSEED_FIRST_PART_MODE      (0)
#define XCP_GETSEED_REMAIN_PART_MODE     (1)

#define XCP_UNLOCK_POSRES_LEN            (2)

#define  XCP_UPLOAD_POSRES_LEN           XCP_AG
#define  XCP_UPLOADSHORT_POSRES_LEN      XCP_AG

#if(STD_ON == XCP_BUILDCS_SUPPORT)
#define  XCP_BUILD_CHECKSUM_RES_LEN      (8)
#endif
/*******************************************************************************
*   local Data Define
*******************************************************************************/
#define XCP_START_SEC_CODE
#include "MemMap.h"

#if(STD_ON == XCP_SEEDKEY_SUPPORT)
STATIC FUNC(Std_ReturnType, XCP_CODE) Xcp_GetUnlockRes
(
    const uint8 res
);
STATIC FUNC(void, XCP_CODE) Xcp_GetSeedProcess
(
    const uint16 maxDataLen
);
STATIC FUNC(void, XCP_CODE) Xcp_ResetSeedKey (void);
#endif


#define XCP_STOP_SEC_CODE
#include "MemMap.h"



#define XCP_START_SEC_VAR_NOINIT_8
#include "MemMap.h"

VAR (uint8, XCP_VAR_NOINIT) Xcp_ProtectMask;
VAR (Xcp_Status_Type, XCP_VAR_NOINIT) Xcp_Status;
/*******************************************************************************
* PRQA S 759 MISRA-C:2004 Rule 18.4
* Use union to fullfill xcp protocol and also union make the code easy to
* read and implement.
* This part of code is verified manually and has no impact.
*******************************************************************************/
VAR (Xcp_Current_Session_Status_Type, XCP_VAR_NOINIT) Xcp_SessionStatus;
VAR (uint8, XCP_VAR_NOINIT) Xcp_AddressExtension;

#if(STD_ON == XCP_BUILDCS_SUPPORT)
STATIC VAR (uint8, XCP_VAR_NOINIT)  Xcp_CS_Type;
#endif

#if(STD_ON == XCP_SEEDKEY_SUPPORT)
/* Seed&Key*/
STATIC VAR (uint8, XCP_VAR_NOINIT) Xcp_RemainLength;
STATIC VAR (uint8, XCP_VAR_NOINIT) Xcp_SeedKeyIndex;
STATIC VAR (uint8, XCP_VAR_NOINIT) Xcp_SeedKeyStatus;
STATIC VAR (uint8, XCP_VAR_NOINIT) Xcp_TargetUnlockMask;
STATIC VAR (uint8, XCP_VAR_NOINIT) Xcp_SeedSize;
STATIC VAR (uint8, XCP_VAR_NOINIT) Xcp_KeySize;
STATIC VAR (uint8, XCP_VAR_NOINIT) Xcp_SeedBuffer[XCP_MAX_SEED_SIZE];
STATIC VAR (uint8, XCP_VAR_NOINIT) Xcp_KeyBuffer[XCP_MAX_KEY_SIZE];
#endif

#define XCP_STOP_SEC_VAR_NOINIT_8
#include "MemMap.h"


#define XCP_START_SEC_VAR_NOINIT_16
#include "MemMap.h"
#if(STD_ON == XCP_SLAVE_BLOCK_MODE_SUPPORT)
STATIC VAR (uint16, XCP_VAR_NOINIT) Xcp_UploadLength;
#endif
#define XCP_STOP_SEC_VAR_NOINIT_16
#include "MemMap.h"

#define XCP_START_SEC_VAR_NOINIT_32
#include "MemMap.h"
#if(STD_ON == XCP_BUILDCS_SUPPORT)
STATIC VAR (uint32, XCP_VAR_NOINIT)  Xcp_CS_BlockSize;
STATIC VAR (uint32, XCP_VAR_NOINIT)  Xcp_CS_Result;
#endif
#define XCP_STOP_SEC_VAR_NOINIT_32
#include "MemMap.h"

/*******************************************************************************
*   Internal Function Define
*******************************************************************************/
#define XCP_START_SEC_CODE
#include "MemMap.h"

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name : Xcp_StdInit
*
* Description   : Init vars used in std cmd
*
* Inputs        : None

* Outputs       : None
*
* Limitations   : None
********************************************************************************
END_FUNCTION_HDR */
FUNC(void, XCP_CODE) Xcp_StdInit (void)
{
    Xcp_Status = XCP_STATUS_DISCONNECTED;
    Xcp_ProtectMask = XCP_LOCK_INIT;
    Xcp_SessionStatus.Byte = (uint8)0;
    Xcp_AddressExtension = (uint8)0;
    Xcp_AsynJob = XCP_NO_ASYN_JOB;
#if(STD_ON == XCP_SLAVE_BLOCK_MODE_SUPPORT)
    Xcp_UploadLength = (uint16)0;
#endif
#if(STD_ON == XCP_SEEDKEY_SUPPORT)
    Xcp_ResetSeedKey();
#endif
#if(STD_ON == XCP_BUILDCS_SUPPORT)
    Xcp_CS_BlockSize = (uint32)0;
    Xcp_CS_Result = (uint32)0;
    Xcp_CS_Type = (uint8)0;
#endif
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name : Xcp_FuncConnect
*
* Description   : Implementation of Xcp_FuncConnect command
*
* Inputs        : None

* Outputs       : None
*
* Limitations   : None
********************************************************************************
END_FUNCTION_HDR */
FUNC(void, XCP_CODE) Xcp_FuncConnect (void)
{
    uint8 mode;

    SchM_Enter_Xcp_XCP_EXCLUSIVE_AREA_0();
    mode = Xcp_RxData[XCP_PACKET_BYTE1];
    SchM_Exit_Xcp_XCP_EXCLUSIVE_AREA_0();

    if (mode < XCP_MODE_NUM)
    {
#if(STD_ON == XCP_USER_CONNECT_MODE_SUPPORT)

        if (XCP_USER_MODE_INDEX == mode)
        {
            /* user define connect mode */
            Xcp_App_Connected_UserMode();
        }

#endif

        Xcp_TxData[XCP_PACKET_BYTE0] = XCP_CMD_RES_CODE;
        Xcp_TxData[XCP_PACKET_BYTE1] = XCP_RESOURCE_IN_CONNECT;
        Xcp_TxData[XCP_PACKET_BYTE2] = XCP_COMM_MODE_BASIC;
        Xcp_TxData[XCP_PACKET_BYTE3] = Xcp_TpProConfig[Xcp_ActiveLink.XcpTpHandle].MaxCto;
        Xcp_TxData[XCP_PACKET_BYTE4] = Xcp_GetHighByte (Xcp_TpProConfig[Xcp_ActiveLink.XcpTpHandle].MaxDto);
        Xcp_TxData[XCP_PACKET_BYTE5] = Xcp_GetLowByte (Xcp_TpProConfig[Xcp_ActiveLink.XcpTpHandle].MaxDto);
        Xcp_TxData[XCP_PACKET_BYTE6] = XCP_VERSION_MAJOR;
        Xcp_TxData[XCP_PACKET_BYTE7] = XCP_TP_VERSION_MAJOR;/*ning.chen*/
        Xcp_TxPduInfo.SduLength = XCP_CONNECT_POSRES_LEN;
        Xcp_TxPduInfo.SduDataPtr = Xcp_TxData;

        Xcp_Status = XCP_STATUS_CONNECTED;

    }
    else
    {
        Xcp_CreatErrResponse (XCP_ERR_OUT_OF_RANGE);
    }

    /* send response */
    Xcp_Transmit();

}


/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name : Xcp_FuncDisconnect
*
* Description   : Implementation of DISCONNECT command
*
* Inputs        : None

* Outputs       : None
*
* Limitations   : None
********************************************************************************
END_FUNCTION_HDR */
FUNC(void, XCP_CODE) Xcp_FuncDisconnect (void)
{

    /* split the reset before and after responce is send, as some vars is needed
       when transmit responce
       if all reset job is placed after responce is send, and if connect is request
       by master very soon after disconnect, the quickly connect may lost.
    */
    Xcp_PreReset();

    Xcp_TxData[XCP_PACKET_BYTE0] = XCP_CMD_RES_CODE;
    Xcp_TxPduInfo.SduLength = XCP_NORMAL_POSLEN;
    Xcp_TxPduInfo.SduDataPtr = Xcp_TxData;

    /* send response */
    Xcp_Transmit();

    Xcp_PostReset();
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name : Xcp_FuncGetStatus
*
* Description   : Implementation of Xcp_FuncGetStatus command
*
* Inputs        : None

* Outputs       : None
*
* Limitations   : None
********************************************************************************
END_FUNCTION_HDR */
FUNC(void, XCP_CODE) Xcp_FuncGetStatus (void)
{
    /* Set response data */
    Xcp_TxData[XCP_PACKET_BYTE0] = XCP_CMD_RES_CODE;
    Xcp_TxData[XCP_PACKET_BYTE1] = Xcp_SessionStatus.Byte;
    Xcp_TxData[XCP_PACKET_BYTE2] = Xcp_ProtectMask;
    Xcp_TxData[XCP_PACKET_BYTE3] = XCP_RESERVED_BYTE;
    Xcp_TxData[XCP_PACKET_BYTE4] = (uint8)0;
    Xcp_TxData[XCP_PACKET_BYTE5] = (uint8)0; /* not support session id used in resume */
    Xcp_TxPduInfo.SduLength = XCP_GETSTATUS_POSRES_LEN;
    Xcp_TxPduInfo.SduDataPtr = Xcp_TxData;

    /* send response */
    Xcp_Transmit();
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name : Xcp_FuncSynch
*
* Description   : Implementation of Xcp_FuncSynch command
*
* Inputs        : None

* Outputs       : None
*
* Limitations   : None
********************************************************************************
END_FUNCTION_HDR */
FUNC(void, XCP_CODE) Xcp_FuncSynch (void)
{
    /* used to synchronize command execution after timeout conditions,used to
       synchronize command execution after timeout conditions */
    Xcp_CreatErrResponse (XCP_ERR_CMD_SYNCH);
    Xcp_Transmit();
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name : Xcp_FuncGetCommModeInfo
*
* Description   : Implementation of Xcp_FuncGetCommModeInfo command
*
* Inputs        : None

* Outputs       : None
*
* Limitations   : None
********************************************************************************
END_FUNCTION_HDR */
FUNC(void, XCP_CODE) Xcp_FuncGetCommModeInfo (void)
{
    uint8 maxBS;
#if(STD_ON == XCP_MASTER_BLOCK_MODE_SUPPORT)
    /* if buffersize is too small ,maxBS =0, the config tool must report error */
#if(XCP_AG > 2)
    maxBS = (uint8) (XCP_MASTER_BLOCK_BUFFER_SIZE / (Xcp_TpProConfig[Xcp_ActiveLink.XcpTpHandle].MaxCto - XCP_AG) );
#else
    maxBS = (uint8) ((uint8)XCP_MASTER_BLOCK_BUFFER_SIZE / (Xcp_TpProConfig[Xcp_ActiveLink.XcpTpHandle].MaxCto - XCP_DOWNLOAD_FIX_BYTES) );
#endif

#else
    maxBS = (uint8)0;
#endif

    Xcp_TxData[XCP_PACKET_BYTE0] = XCP_CMD_RES_CODE;
    Xcp_TxData[XCP_PACKET_BYTE1] = XCP_RESERVED_BYTE;
    Xcp_TxData[XCP_PACKET_BYTE2] = XCP_COMM_MODE_OPTIONAL;
    Xcp_TxData[XCP_PACKET_BYTE3] = XCP_RESERVED_BYTE;
    Xcp_TxData[XCP_PACKET_BYTE4] = maxBS;
    Xcp_TxData[XCP_PACKET_BYTE5] = XCP_MIN_ST;
    Xcp_TxData[XCP_PACKET_BYTE6] = XCP_QUEUE_SIZE;
    Xcp_TxData[XCP_PACKET_BYTE7] = Xcp_Get_Drive_Version (XCP_VERSION_MAJOR, XCP_VERSION_MINOR);
    Xcp_TxPduInfo.SduLength = XCP_GETCOMMMODE_POSRES_LEN;
    Xcp_TxPduInfo.SduDataPtr = Xcp_TxData;

    /*Send Positive Response*/
    Xcp_Transmit();
}

#if(STD_ON == XCP_GETSLAVEID_SUPPORT)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name : Xcp_FuncGetID
*
* Description   : Implementation of Xcp_FuncGetID command
*
* Inputs        : None

* Outputs       : None
*
* Limitations   : None
********************************************************************************
END_FUNCTION_HDR */
FUNC(void, XCP_CODE) Xcp_FuncGetID (void)
{
    /* Only supported Mode=0 response which means tester may need to use
       upload cmd to get session id
       User need to fill callback to  return id's locate address and id length

       if app dont supported  this feather, return errcode
       ERR_OUT_OF_RANGE : do not support this id type
       ERR_CMD_UNKNOWN:total unsupport this cmd
    */
    uint8 errcode = XCP_ERR_CMD_UNKNOWN;

#if(STD_ON == XCP_GETSLAVEID_SUPPORT)
    uint32 ID_Length = 0;
    uint8 ID_Type;


    SchM_Enter_Xcp_XCP_EXCLUSIVE_AREA_0();
    ID_Type = Xcp_RxData[XCP_PACKET_BYTE1];
    SchM_Exit_Xcp_XCP_EXCLUSIVE_AREA_0();

    Xcp_App_GetSlaveID (ID_Type, &Xcp_MTA, &ID_Length, &errcode);

    if (errcode == XCP_NO_ERR)
    {
        /* Set response data */
        Xcp_TxData[XCP_PACKET_BYTE0] = XCP_CMD_RES_CODE;
        Xcp_TxData[XCP_PACKET_BYTE1] = 0;   /* mode always = 0*/
        Xcp_TxData[XCP_PACKET_BYTE2] = XCP_RESERVED_BYTE;
        Xcp_TxData[XCP_PACKET_BYTE3] = XCP_RESERVED_BYTE;
        Xcp_TxData[XCP_PACKET_BYTE4] = Xcp_GetFirstByte (ID_Length);
        Xcp_TxData[XCP_PACKET_BYTE5] = Xcp_GetSecondByte (ID_Length);
        Xcp_TxData[XCP_PACKET_BYTE6] = Xcp_GetThirdByte (ID_Length);
        Xcp_TxData[XCP_PACKET_BYTE7] = Xcp_GetFourthByte (ID_Length);
        Xcp_TxPduInfo.SduLength = XCP_GETIDE_POSRES_LEN;
        Xcp_TxPduInfo.SduDataPtr = Xcp_TxData;
    }
    else
#endif
    {
        Xcp_CreatErrResponse (errcode);
    }

    Xcp_Transmit();
}
#endif

#if(STD_ON == XCP_SETREQ_SUPPORT)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name : Xcp_FuncSetRequest
*
* Description   : Implementation of Xcp_FuncSetRequest command
*
* Inputs        : None

* Outputs       : None
*
* Limitations   : None
********************************************************************************
END_FUNCTION_HDR */
FUNC(void, XCP_CODE) Xcp_FuncSetRequest (void)
{
    /* not supported clear save DAQ request  ,related with resume
       Store cal data will be precess in mainfuntion
    */
    /***************************************************************************
    * PRQA S 759 MISRA-C:2004 Rule 18.4
    * Use union to fullfill xcp protocol and also union make the code easy to
    * read and implement.
    * This part of code is verified manually and has no impact.
    ***************************************************************************/
    Xcp_Current_Session_Status_Type mode;
    /*uint16 sessionId; reverse to use */
    Std_ReturnType tem_Ret;
#if(STD_ON == XCP_REQ_STORECALDATA_ASYN_SUPPORT)
    boolean sendflag = TRUE;
#endif


    SchM_Enter_Xcp_XCP_EXCLUSIVE_AREA_0();
    mode.Byte = Xcp_RxData[XCP_PACKET_BYTE1];
    /*sessionId = Xcp_Make16Bits(Xcp_RxData[XCP_PACKET_BYTE2],Xcp_RxData[XCP_PACKET_BYTE3]);*/
    SchM_Exit_Xcp_XCP_EXCLUSIVE_AREA_0();

    if (XCP_STORECALREQ_MODE_ONLY == mode.Byte)
    {
        tem_Ret = Xcp_AppStoreCalInfo();

        if (XCP_ASYN_JOB_OK == tem_Ret)
        {
            /* send pos reponse */
            Xcp_TxData[XCP_PACKET_BYTE0] = XCP_CMD_RES_CODE;
            Xcp_TxPduInfo.SduLength = XCP_NORMAL_POSLEN;
            Xcp_TxPduInfo.SduDataPtr = Xcp_TxData;
        }

#if(STD_ON == XCP_REQ_STORECALDATA_ASYN_SUPPORT)
        else if (XCP_ASYN_JOB_PENDING == tem_Ret)
        {
            /* pengding do nothing */
            sendflag = FALSE;
            Xcp_AsynJob = XCP_STORECALDATA_JOB;
            Xcp_SessionStatus.Bit.STORE_CAL_REQ = 1;
        }

#endif
        else
        {
            /* send neg reponse */
            Xcp_CreatErrResponse (XCP_ERR_GENERIC);
        }

        /* dont send resp here */
    }
    else
    {
        /*if((1 == mode.Bit.CLEAR_DAQ_REQ) || (1 == mode.Bit.STORE_DAQ_REQ))
          or (0 == mode.Byte)
          or orther
          return err
        */
        Xcp_CreatErrResponse (XCP_ERR_OUT_OF_RANGE);
    }

#if(STD_ON == XCP_REQ_STORECALDATA_ASYN_SUPPORT)

    if (TRUE == sendflag)
#endif
    {
        Xcp_Transmit();
    }

}
#endif

#if(STD_ON == XCP_SEEDKEY_SUPPORT)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name : Xcp_ResetSeedKey
*
* Description   : reset key seed status when err or unlock finish
*
* Inputs        : res

* Outputs       : None
*
* Limitations   : None
********************************************************************************
END_FUNCTION_HDR */
STATIC FUNC(void, XCP_CODE) Xcp_ResetSeedKey (void)
{
    Xcp_SeedKeyStatus = XCP_SEEDKEY_IDLE;
    Xcp_TargetUnlockMask = XCP_NO_PROTECTED;
    Xcp_RemainLength = 0;
    Xcp_SeedSize = 0;
    Xcp_KeySize = 0;
    Xcp_SeedKeyIndex = 0;
}


/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name : Xcp_GetUnlockRes
*
* Description   : check if the target unlock res valid
*
* Inputs        : res

* Outputs       : E_OK,E_NOT_OK
*
* Limitations   : None
********************************************************************************
END_FUNCTION_HDR */
STATIC FUNC(Std_ReturnType, XCP_CODE) Xcp_GetUnlockRes
(
    const uint8 res
)
{

    uint8 ret = E_OK;
    uint8 count = 0;

    if (XCP_CAL_PROTECTED == ( (uint8) (res & XCP_CAL_PROTECTED) ) )
    {
        count++;
    }

    if (XCP_DAQ_PROTECTED == ( (uint8) (res & XCP_DAQ_PROTECTED) ) )
    {
        count++;
    }

    if (XCP_STIM_PROTECTED == ( (uint8) (res & XCP_STIM_PROTECTED) ) )
    {
        count++;
    }

    if (XCP_PGM_PROTECTED == ( (uint8) (res & XCP_PGM_PROTECTED) ) )
    {
        count++;
    }

    if (1 != count)
    {
        ret = E_NOT_OK;
    }

    return ret;

}


/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name : Xcp_GetSeedProcess
*
* Description   : Implementation of Xcp_FuncGetSeed command internal
*
* Inputs        : maxDataLen

* Outputs       : None
*
* Limitations   : None
********************************************************************************
END_FUNCTION_HDR */
STATIC FUNC(void, XCP_CODE) Xcp_GetSeedProcess
(
    const uint16 maxDataLen
)
{
    uint8 seedIndex;
    uint16 templength;


    Xcp_TxData[XCP_PACKET_BYTE0] = XCP_CMD_RES_CODE;
    Xcp_TxData[XCP_PACKET_BYTE1] = Xcp_RemainLength;

    if (Xcp_RemainLength > maxDataLen)
    {
        Xcp_SeedKeyStatus = XCP_SEEDKEY_REMAIN_SEED;
        templength = maxDataLen;

        /* length --*/
        Xcp_RemainLength = Xcp_RemainLength - (uint8) maxDataLen;
    }
    else
    {
        templength = Xcp_RemainLength;
        Xcp_SeedKeyStatus = XCP_SEEDKEY_WAITINGKEY;
        Xcp_RemainLength = 0;
    }

    for (seedIndex =  0; seedIndex < templength; seedIndex++)
    {
        Xcp_TxData[XCP_PACKET_BYTE2 + seedIndex] = Xcp_SeedBuffer[Xcp_SeedKeyIndex];
        Xcp_SeedKeyIndex++;
    }

    Xcp_TxPduInfo.SduLength = templength + XCP_GETSEED_POSRES_LEN;
    Xcp_TxPduInfo.SduDataPtr = Xcp_TxData;

}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name : Xcp_FuncGetSeed
*
* Description   : Implementation of Xcp_FuncGetSeed command
*
* Inputs        : None

* Outputs       : None
*
* Limitations   : None
********************************************************************************
END_FUNCTION_HDR */
FUNC(void, XCP_CODE) Xcp_FuncGetSeed (void)
{
    uint8 mode;
    uint8 res;
    Std_ReturnType tempres;
    boolean errFlag = FALSE;
    uint8 errcode = XCP_ERR_GENERIC;
    const uint16 maxdatalen =
        Xcp_TpProConfig[Xcp_ActiveLink.XcpTpHandle].MaxDto - XCP_GETSEED_POSRES_LEN;


    SchM_Enter_Xcp_XCP_EXCLUSIVE_AREA_0();
    mode = Xcp_RxData[XCP_PACKET_BYTE1];
    res = Xcp_RxData[XCP_PACKET_BYTE2];
    SchM_Exit_Xcp_XCP_EXCLUSIVE_AREA_0();

    if (mode > XCP_GETSEED_REMAIN_PART_MODE)
    {
        /* mode valid */
        errFlag = TRUE;
        errcode = XCP_ERR_OUT_OF_RANGE;
    }
    else
    {
        if (XCP_SEEDKEY_IDLE == Xcp_SeedKeyStatus)
        {
            /* in idle ,only process mode = 0, first part seed */
            if (XCP_GETSEED_FIRST_PART_MODE != mode)
            {
                errFlag = TRUE;
                errcode = XCP_ERR_SEQUENCE;
            }
            else
            {
                tempres = Xcp_GetUnlockRes (res);

                if (E_NOT_OK == tempres)
                {
                    /* only unlock 1 res each time, */
                    errFlag = TRUE;
                    errcode = XCP_ERR_OUT_OF_RANGE;
                }
                else
                {
                    Xcp_TargetUnlockMask = res;

                    if (0 == (Xcp_ProtectMask & res) )
                    {
                        /* if res is not protected, dont need to unlock  return length 0*/
                        Xcp_TxData[XCP_PACKET_BYTE0] = XCP_CMD_RES_CODE;
                        Xcp_TxData[XCP_PACKET_BYTE1] = 0;
                        Xcp_TxPduInfo.SduLength = XCP_GETSEED_POSRES_LEN;
                        Xcp_TxPduInfo.SduDataPtr = Xcp_TxData;
                        Xcp_ResetSeedKey();
                    }
                    else
                    {
                        /* get seed from App and send out */
                        Xcp_AppGetSeed (res, &Xcp_SeedSize, Xcp_SeedBuffer);

                        if ( (0 == Xcp_SeedSize) || (Xcp_SeedSize > XCP_MAX_SEED_SIZE) )
                        {
                            /* app data is invlaid ,not supported this getseed cmd */
                            errFlag = TRUE;
                            errcode = XCP_ERR_CMD_UNKNOWN;
                        }
                        else
                        {
                            Xcp_RemainLength = Xcp_SeedSize;
                            Xcp_SeedKeyIndex = 0;
                            Xcp_GetSeedProcess (maxdatalen);
                        }
                    }
                }
            }
        }
        else if (XCP_SEEDKEY_REMAIN_SEED == Xcp_SeedKeyStatus)
        {
            /* in remain ,only process mode = 1, remain part seed */
            if (XCP_GETSEED_REMAIN_PART_MODE != mode)
            {
                errFlag = TRUE;
                errcode = XCP_ERR_SEQUENCE;
            }
            else
            {
                /* no need to check length or ptr here, which has been checked in idle */
                Xcp_GetSeedProcess (maxdatalen);
            }
        }
        else
        {
            /* other state recive get seed , report err */
            errFlag = TRUE;
            errcode = XCP_ERR_SEQUENCE;
        }

    }

    if (TRUE == errFlag)
    {
        Xcp_CreatErrResponse (errcode);
        Xcp_ResetSeedKey();
    }

    Xcp_Transmit();
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name : Xcp_FuncUnlock
*
* Description   : Implementation of Xcp_FuncUnlock command
*
* Inputs        : None

* Outputs       : None
*
* Limitations   : None
********************************************************************************
END_FUNCTION_HDR */
FUNC(void, XCP_CODE) Xcp_FuncUnlock (void)
{
    boolean errFlag = FALSE;
    boolean keyErrFlag = FALSE;
    uint8 errcode = XCP_ERR_GENERIC;
    uint8 keyLen;
    const uint16 maxdatalen =
        Xcp_TpProConfig[Xcp_ActiveLink.XcpTpHandle].MaxDto - XCP_UNLOCK_POSRES_LEN;
    uint8 keyIndex;
    uint8 temlength;
    Std_ReturnType temResult;

    SchM_Enter_Xcp_XCP_EXCLUSIVE_AREA_0();
    keyLen = Xcp_RxData[XCP_PACKET_BYTE1];
    SchM_Exit_Xcp_XCP_EXCLUSIVE_AREA_0();


    if (Xcp_SeedKeyStatus < XCP_SEEDKEY_WAITINGKEY)
    {
        /* not get seed */
        errFlag = TRUE;
        errcode = XCP_ERR_SEQUENCE;
    }
    else
    {
        if (XCP_SEEDKEY_WAITINGKEY == Xcp_SeedKeyStatus)
        {
            /* first part of key
               check total length
            */
            if (keyLen > XCP_MAX_KEY_SIZE)
            {
                errFlag = TRUE;
                errcode = XCP_ERR_ACCESS_DENIED;
            }
            else
            {
                Xcp_RemainLength =  keyLen;
                Xcp_KeySize =  keyLen;
                Xcp_SeedKeyIndex = 0;
                /* switch statu to XCP_SEEDKEY_REMAIN_KEY
                 if err happened, this will return to idle
                 if no err, key data will be receive and checked until all key bytes passed
                */
                Xcp_SeedKeyStatus = XCP_SEEDKEY_REMAIN_KEY;
            }
        }

        if (FALSE == errFlag)
        {

            /* every time receive new keyPacket, check remaining length */
            if (keyLen != Xcp_RemainLength)
            {
                errFlag = TRUE;
                errcode = XCP_ERR_ACCESS_DENIED;
            }
            else
            {
                if (Xcp_RemainLength > maxdatalen)
                {
                    temlength =  (uint8) maxdatalen;
                    Xcp_RemainLength = Xcp_RemainLength - temlength;
                }
                else
                {
                    temlength = Xcp_RemainLength;
                    Xcp_RemainLength = 0;
                }

                for (keyIndex = 0; keyIndex < temlength; keyIndex++)
                {
                    Xcp_KeyBuffer[Xcp_SeedKeyIndex] =  Xcp_RxData[XCP_PACKET_BYTE2 + keyIndex];
                    Xcp_SeedKeyIndex++;
                }

                if (0 == Xcp_RemainLength)
                {
                    /* call back to check seed and key */
                    temResult = Xcp_AppCheckKey (Xcp_TargetUnlockMask, Xcp_SeedSize,
                                                 Xcp_SeedBuffer, Xcp_KeySize, Xcp_KeyBuffer);

                    if (E_NOT_OK == temResult)
                    {
                        errFlag = TRUE;
                        errcode = XCP_ERR_ACCESS_LOCKED;
                        keyErrFlag = TRUE;
                    }
                    else
                    {
                        /* All key bytes are correct */
                        /* clear target protect bit */
                        Xcp_ProtectMask = (Xcp_ProtectMask & ( (uint8) ~Xcp_TargetUnlockMask) );
                        Xcp_ResetSeedKey();
                    }
                }
            }
        }
    }

    if (TRUE == errFlag)
    {
        Xcp_CreatErrResponse (errcode);
        Xcp_ResetSeedKey();
    }
    else
    {
        Xcp_TxData[XCP_PACKET_BYTE0] = XCP_CMD_RES_CODE;
        Xcp_TxData[XCP_PACKET_BYTE1] = Xcp_ProtectMask;
        Xcp_TxPduInfo.SduLength = XCP_UNLOCK_POSRES_LEN;
        Xcp_TxPduInfo.SduDataPtr = Xcp_TxData;
    }

    Xcp_Transmit();

    /* unlock failed disconnect xcp slave */
    if (TRUE == keyErrFlag)
    {
        Xcp_Reset();
    }
}
#endif

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name : Xcp_FuncSetMta
*
* Description   : Implementation of Xcp_FuncSetMta command
*
* Inputs        : None

* Outputs       : None
*
* Limitations   : None
********************************************************************************
END_FUNCTION_HDR */
FUNC(void, XCP_CODE) Xcp_FuncSetMta (void)
{
#if(STD_ON == XCP_CHECK_MTA_CBK_SUPPORT)
    Std_ReturnType tem;
#endif
    uint32 tempMTA;
    uint8 tempAddrExt;

    SchM_Enter_Xcp_XCP_EXCLUSIVE_AREA_0();
    tempMTA = Xcp_Make32Bits (Xcp_RxData[XCP_PACKET_BYTE4], Xcp_RxData[XCP_PACKET_BYTE5],
                              Xcp_RxData[XCP_PACKET_BYTE6], Xcp_RxData[XCP_PACKET_BYTE7]);
    tempAddrExt = Xcp_RxData[XCP_PACKET_BYTE3];
    SchM_Exit_Xcp_XCP_EXCLUSIVE_AREA_0();

    /* user need to check addr range */
#if(STD_ON == XCP_CHECK_MTA_CBK_SUPPORT)
    tem = Xcp_AppCheckAddrInMTA (tempMTA, tempAddrExt);

    if (E_OK != tem)
    {
        Xcp_CreatErrResponse (XCP_ERR_ACCESS_DENIED);
    }
    else
#endif
    {
        Xcp_TxData[XCP_PACKET_BYTE0] = XCP_CMD_RES_CODE;
        Xcp_TxPduInfo.SduLength = XCP_NORMAL_POSLEN;
        Xcp_TxPduInfo.SduDataPtr = Xcp_TxData;
        Xcp_MTA = tempMTA;
        Xcp_AddressExtension = tempAddrExt;
    }

    /* may need to reset pgm fomat here */

    Xcp_Transmit();

}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name : Xcp_FuncUpload
*
* Description   : Implementation of Xcp_FuncUpload command
*
* Inputs        : None

* Outputs       : None
*
* Limitations   : None
********************************************************************************
END_FUNCTION_HDR */
FUNC(void, XCP_CODE) Xcp_FuncUpload (void)
{
    uint8 NumOfElement;
#if(STD_ON == XCP_CHECK_READMTA_CBK_SUPPORT)
    Std_ReturnType tem;
#endif
    uint16 lengthInBytes;
    const uint16 maxDto = Xcp_TpProConfig[Xcp_ActiveLink.XcpTpHandle].MaxDto;
#if((STD_OFF == XCP_SPECIAL_ACCESS_RAM) || (XCP_AG > 1))
    uint16 index;
#endif
    uint16 templength;

    SchM_Enter_Xcp_XCP_EXCLUSIVE_AREA_0();
    NumOfElement = Xcp_RxData[XCP_PACKET_BYTE1];
    SchM_Exit_Xcp_XCP_EXCLUSIVE_AREA_0();

    /* caculate data size from element AG to bytes */
    lengthInBytes = NumOfElement;
#if(XCP_AG > 1)
    lengthInBytes = lengthInBytes * XCP_AG;
#endif

    /* check num element */
    if ((uint8)0 == NumOfElement)
    {
        Xcp_CreatErrResponse (XCP_ERR_OUT_OF_RANGE);
    }

#if(STD_OFF == XCP_SLAVE_BLOCK_MODE_SUPPORT)
    else if ( (lengthInBytes + XCP_AG) > maxDto)
    {
        /* numElement = MAXDTO/AG - 1*/
        Xcp_CreatErrResponse (XCP_ERR_OUT_OF_RANGE);
    }

#endif
    else
    {
        /* user need to check addr range */
#if(STD_ON == XCP_CHECK_READMTA_CBK_SUPPORT)
        tem = Xcp_AppCheckReadAddr (Xcp_MTA, Xcp_AddressExtension, lengthInBytes);

        if (E_OK != tem)
        {
            Xcp_CreatErrResponse (XCP_ERR_ACCESS_DENIED);
        }
        else
#endif
        {
            Xcp_TxData[XCP_PACKET_BYTE0] = XCP_CMD_RES_CODE;

#if(XCP_AG > 1)

            for (index = (uint16)0; index < ((uint16)XCP_AG - (uint16)1); index++)
            {
                Xcp_TxData[XCP_PACKET_BYTE1 + index] = XCP_RESERVED_BYTE;
            }

#endif

            templength = lengthInBytes;
#if(STD_ON == XCP_SLAVE_BLOCK_MODE_SUPPORT)

            if ( (lengthInBytes + (uint16)XCP_AG) > maxDto)
            {
                templength = maxDto - (uint16)XCP_AG;
                Xcp_AsynJob = XCP_BLOCK_UPLOAD_JOB;
                Xcp_UploadLength = lengthInBytes - templength;
            }

#endif

            SchM_Enter_Xcp_XCP_EXCLUSIVE_AREA_1();
#if(STD_ON == XCP_SPECIAL_ACCESS_RAM)
            Xcp_App_ReadRam (Xcp_MTA, templength, &Xcp_TxData[XCP_PACKET_HEADER + (uint16)XCP_AG]);
            Xcp_MTA = Xcp_MTA + templength;
#else

            for (index = (uint16)0; index < templength; index++)
            {
                Xcp_TxData[XCP_PACKET_HEADER + (uint16)XCP_AG + index] = * (uint8 *) (Xcp_MTA);
                Xcp_MTA++;
            }

#endif
            SchM_Exit_Xcp_XCP_EXCLUSIVE_AREA_1();
            Xcp_TxPduInfo.SduLength = templength + XCP_UPLOAD_POSRES_LEN;/* add rescode FF */
            Xcp_TxPduInfo.SduDataPtr = Xcp_TxData;

        }
    }

    Xcp_Transmit();

}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name : Xcp_BlockUploadContinue
*
* Description   : Implementation remain data  of Xcp_FuncUpload command in block mode
*
* Inputs        : None

* Outputs       : None
*
* Limitations   : None
********************************************************************************
END_FUNCTION_HDR */
#if(STD_ON == XCP_SLAVE_BLOCK_MODE_SUPPORT)
FUNC(void, XCP_CODE) Xcp_BlockUploadContinue (void)
{
    const uint16 maxDto = Xcp_TpProConfig[Xcp_ActiveLink.XcpTpHandle].MaxDto;
#if(STD_OFF == XCP_SPECIAL_ACCESS_RAM)
    uint16 index;
#endif
    uint16 templength;

    /* dont check parameters here which has been checked in upload */
    if (XCP_BLOCK_UPLOAD_JOB == Xcp_AsynJob)
    {
        if (Xcp_UploadLength > (uint16)0)
        {

            Xcp_TxData[XCP_PACKET_BYTE0] = XCP_CMD_RES_CODE;
#if(XCP_AG > 1)

            for (index = (uint16)0; index < ((uint16)XCP_AG - (uint16)1); index++)
            {
                Xcp_TxData[XCP_PACKET_BYTE1 + index] = XCP_RESERVED_BYTE;
            }

#endif

            if ( (Xcp_UploadLength + (uint16)XCP_AG) > maxDto)
            {
                templength = maxDto - (uint16)XCP_AG;
                Xcp_UploadLength = Xcp_UploadLength - templength;
            }
            else
            {
                templength = Xcp_UploadLength;
                Xcp_UploadLength = (uint16)0;
                Xcp_AsynJob = XCP_NO_ASYN_JOB;
            }

            SchM_Enter_Xcp_XCP_EXCLUSIVE_AREA_1();
#if(STD_ON == XCP_SPECIAL_ACCESS_RAM)
            Xcp_App_ReadRam (Xcp_MTA, templength, &Xcp_TxData[XCP_PACKET_HEADER + (uint16)XCP_AG]);
            Xcp_MTA = Xcp_MTA + templength;
#else

            for (index = (uint16)0; index < templength; index++)
            {
                Xcp_TxData[XCP_PACKET_HEADER + (uint16)XCP_AG + index] = * (uint8 *) (Xcp_MTA);
                Xcp_MTA++;
            }

#endif
            SchM_Exit_Xcp_XCP_EXCLUSIVE_AREA_1();

            Xcp_TxPduInfo.SduLength = templength + (uint16)1;/* add rescode FF */
            Xcp_TxPduInfo.SduDataPtr = Xcp_TxData;
            Xcp_Transmit();
        }
        else
        {
            Xcp_AsynJob = XCP_NO_ASYN_JOB;
        }
    }
}
#endif



/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name : Xcp_FuncShortUpload
*
* Description   : Implementation of Xcp_FuncShortUpload command
*
* Inputs        : None

* Outputs       : None
*
* Limitations   : None
********************************************************************************
END_FUNCTION_HDR */
FUNC(void, XCP_CODE) Xcp_FuncShortUpload (void)
{
    uint8 NumOfElement;
#if(STD_ON == XCP_CHECK_READMTA_CBK_SUPPORT)
    Std_ReturnType tem;
#endif
    uint16 lengthInBytes;
    const uint16 maxDto = Xcp_TpProConfig[Xcp_ActiveLink.XcpTpHandle].MaxDto;
#if((STD_OFF == XCP_SPECIAL_ACCESS_RAM) || (XCP_AG > 1))
    uint16 index;
#endif
    uint32 tempMTA;
    uint8 tempAddrExt;

    SchM_Enter_Xcp_XCP_EXCLUSIVE_AREA_0();
    tempMTA = Xcp_Make32Bits (Xcp_RxData[XCP_PACKET_BYTE4], Xcp_RxData[XCP_PACKET_BYTE5],
                              Xcp_RxData[XCP_PACKET_BYTE6], Xcp_RxData[XCP_PACKET_BYTE7]);
    tempAddrExt = Xcp_RxData[XCP_PACKET_BYTE3];
    NumOfElement = Xcp_RxData[XCP_PACKET_BYTE1];
    SchM_Exit_Xcp_XCP_EXCLUSIVE_AREA_0();

    /* caculate data size from element AG to bytes */
    lengthInBytes = NumOfElement;
#if(XCP_AG > 1)
    lengthInBytes = lengthInBytes * XCP_AG;
#endif


    if ((uint8)0 == NumOfElement)
    {
        Xcp_CreatErrResponse (XCP_ERR_OUT_OF_RANGE);
    }
    else if ( (lengthInBytes + (uint16)XCP_AG) > maxDto)
    {
        /* numElement = MAXDTO/AG - 1*/
        Xcp_CreatErrResponse (XCP_ERR_OUT_OF_RANGE);
    }
    else
    {
        /* user need to check addr range */
#if(STD_ON == XCP_CHECK_READMTA_CBK_SUPPORT)
        tem = Xcp_AppCheckReadAddr (Xcp_MTA, Xcp_AddressExtension, lengthInBytes);

        if (E_OK != tem)
        {
            Xcp_CreatErrResponse (XCP_ERR_ACCESS_DENIED);
        }
        else
#endif
        {
            Xcp_MTA = tempMTA;
            Xcp_AddressExtension = tempAddrExt;

            Xcp_TxData[XCP_PACKET_BYTE0] = XCP_CMD_RES_CODE;

#if(XCP_AG > 1)

            for (index = 0; index < (XCP_AG - 1); index++)
            {
                Xcp_TxData[XCP_PACKET_BYTE1 + index] = XCP_RESERVED_BYTE;
            }

#endif

            SchM_Enter_Xcp_XCP_EXCLUSIVE_AREA_1();
#if(STD_ON == XCP_SPECIAL_ACCESS_RAM)
            Xcp_App_ReadRam (Xcp_MTA, lengthInBytes, &Xcp_TxData[XCP_PACKET_HEADER + XCP_AG]);
            Xcp_MTA = Xcp_MTA + lengthInBytes;
#else

            for (index = (uint16)0; index < lengthInBytes; index++)
            {
                Xcp_TxData[XCP_PACKET_HEADER + (uint16)XCP_AG + index] = * (uint8 *) (Xcp_MTA);
                Xcp_MTA++;
            }

#endif
            SchM_Exit_Xcp_XCP_EXCLUSIVE_AREA_1();
            Xcp_TxPduInfo.SduLength = lengthInBytes + XCP_UPLOADSHORT_POSRES_LEN;/* add rescode FF */
            Xcp_TxPduInfo.SduDataPtr = Xcp_TxData;

        }
    }

    Xcp_Transmit();
}

#if(STD_ON == XCP_BUILDCS_SUPPORT)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name : Xcp_FuncBuildCheckSum
*
* Description   : Implementation of Xcp_FuncBuildCheckSum  command
*
* Inputs        : None

* Outputs       : None
*
* Limitations   : None
********************************************************************************
END_FUNCTION_HDR */
FUNC(void, XCP_CODE) Xcp_FuncBuildCheckSum (void)

{
    Std_ReturnType tem;
    uint32 maxBlockSize = 0;
#if(STD_ON == XCP_BUILDCS_ASYN_SUPPORT)
    uint8 respFlag = TRUE;
#endif
    uint8 errcode;

    SchM_Enter_Xcp_XCP_EXCLUSIVE_AREA_0();
    Xcp_CS_BlockSize = Xcp_Make32Bits (Xcp_RxData[XCP_PACKET_BYTE4], Xcp_RxData[XCP_PACKET_BYTE5],
                                       Xcp_RxData[XCP_PACKET_BYTE6], Xcp_RxData[XCP_PACKET_BYTE7]);
    SchM_Exit_Xcp_XCP_EXCLUSIVE_AREA_0();

#if(XCP_AG > 1)
    Xcp_CS_BlockSize = Xcp_CS_BlockSize * XCP_AG;
#endif

    /*
      app caculate checksum if err return maxblocksize of app
    */
    tem = Xcp_AppChecksum (Xcp_MTA, Xcp_AddressExtension, Xcp_CS_BlockSize, &Xcp_CS_Type, &Xcp_CS_Result, &maxBlockSize, &errcode);

    if (XCP_ASYN_JOB_OK == tem)
    {
        Xcp_TxData[XCP_PACKET_BYTE0] = XCP_CMD_RES_CODE;
        Xcp_TxData[XCP_PACKET_BYTE1] = Xcp_CS_Type;
        Xcp_TxData[XCP_PACKET_BYTE2] = XCP_RESERVED_BYTE;
        Xcp_TxData[XCP_PACKET_BYTE3] = XCP_RESERVED_BYTE;
        Xcp_TxData[XCP_PACKET_BYTE4] = Xcp_GetFirstByte (Xcp_CS_Result);
        Xcp_TxData[XCP_PACKET_BYTE5] = Xcp_GetSecondByte (Xcp_CS_Result);
        Xcp_TxData[XCP_PACKET_BYTE6] = Xcp_GetThirdByte (Xcp_CS_Result);
        Xcp_TxData[XCP_PACKET_BYTE7] = Xcp_GetFourthByte (Xcp_CS_Result);
        Xcp_MTA = Xcp_MTA + Xcp_CS_BlockSize;
    }

#if(STD_ON == XCP_BUILDCS_ASYN_SUPPORT)
    else if (XCP_ASYN_JOB_PENDING == tem)
    {
        respFlag = FALSE;
        Xcp_AsynJob = XCP_BUILDCS_JOB;
    }

#endif
    else
    {
#if(XCP_AG > 1)
        maxBlockSize = maxBlockSize / XCP_AG;
#endif
        Xcp_TxData[XCP_PACKET_BYTE0] = XCP_CMD_ERROR_CODE;
        Xcp_TxData[XCP_PACKET_BYTE1] = errcode;
        Xcp_TxData[XCP_PACKET_BYTE2] = XCP_RESERVED_BYTE;
        Xcp_TxData[XCP_PACKET_BYTE3] = XCP_RESERVED_BYTE;
        Xcp_TxData[XCP_PACKET_BYTE4] = Xcp_GetFirstByte (maxBlockSize);
        Xcp_TxData[XCP_PACKET_BYTE5] = Xcp_GetSecondByte (maxBlockSize);
        Xcp_TxData[XCP_PACKET_BYTE6] = Xcp_GetThirdByte (maxBlockSize);
        Xcp_TxData[XCP_PACKET_BYTE7] = Xcp_GetFourthByte (maxBlockSize);
    }

#if(STD_ON == XCP_BUILDCS_ASYN_SUPPORT)

    if (TRUE == respFlag)
#endif
    {
        Xcp_TxPduInfo.SduLength = XCP_BUILD_CHECKSUM_RES_LEN;
        Xcp_TxPduInfo.SduDataPtr = Xcp_TxData;
        Xcp_Transmit();
    }

}
#endif

#if((STD_ON == XCP_BUILDCS_SUPPORT) && (STD_ON == XCP_BUILDCS_ASYN_SUPPORT))
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name : Xcp_BuildCSEndNotification
*
* Description   : This function is used to notify  xcp that buildcs is finished
*
* Inputs        : None

* Outputs       : None
*
* Limitations   : None
********************************************************************************
END_FUNCTION_HDR */
FUNC(void, XCP_CODE) Xcp_BuildCSEndNotification (void)
{
    Xcp_TxData[XCP_PACKET_BYTE0] = XCP_CMD_RES_CODE;
    Xcp_TxData[XCP_PACKET_BYTE1] = Xcp_CS_Type;
    Xcp_TxData[XCP_PACKET_BYTE2] = XCP_RESERVED_BYTE;
    Xcp_TxData[XCP_PACKET_BYTE3] = XCP_RESERVED_BYTE;
    Xcp_TxData[XCP_PACKET_BYTE4] = Xcp_GetFirstByte (Xcp_CS_Result);
    Xcp_TxData[XCP_PACKET_BYTE5] = Xcp_GetSecondByte (Xcp_CS_Result);
    Xcp_TxData[XCP_PACKET_BYTE6] = Xcp_GetThirdByte (Xcp_CS_Result);
    Xcp_TxData[XCP_PACKET_BYTE7] = Xcp_GetFourthByte (Xcp_CS_Result);

    Xcp_MTA = Xcp_MTA + Xcp_CS_BlockSize;
    Xcp_TxPduInfo.SduLength = XCP_BUILD_CHECKSUM_RES_LEN;
    Xcp_TxPduInfo.SduDataPtr = Xcp_TxData;
    Xcp_Transmit();
    Xcp_CS_BlockSize = 0;
    Xcp_AsynJob = XCP_NO_ASYN_JOB;
}
/* no need to error report for buildcs asyn job
as all err will be report at start of buildcs*/

#endif




#define XCP_STOP_SEC_CODE
#include "MemMap.h"

