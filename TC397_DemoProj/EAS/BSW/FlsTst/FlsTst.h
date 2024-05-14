/*  BEGIN_FILE_HDR
********************************************************************************
*   NOTICE
*   This software is the property of HiRain Technologies. Any information
*   contained in this doc should not be reproduced, or used, or disclosed
*   without the written authorization from HiRain Technologies.
********************************************************************************
*   File Name       : FlsTst.h
********************************************************************************
*   Project/Product : AUTOSAR 4.2
*   Title           : FlsTst.h
*   Author          : Hirain
********************************************************************************
*   Description     : Main header file of the AUTOSAR FlsTst Module
*
********************************************************************************
*   Limitations     :
*
********************************************************************************
*
********************************************************************************
*   Revision History:
*   Reference to Core C File
********************************************************************************
* END_FILE_HDR*/

#ifndef FLSTST_H
#define FLSTST_H

#include "Std_Types.h"
#include "FlsTst_Cfg.h"
#include "FlsTst_Version.h"

/*******************************************************************************
*   Macro   SWS_FlsTst_00007
*******************************************************************************/
/* Det ErrorCode*/
#define FLSTST_E_STATE_FAILURE          ((uint8)0x01)
#define FLSTST_E_PARAM_INVALID          ((uint8)0x02)
#define FLSTST_E_UNINIT                 ((uint8)0x03)
#define FLSTST_E_ALREADY_INITIALIZED    ((uint8)0x04)
#define FLSTST_E_PARAM_CONFIG           ((uint8)0x05)
#define FLSTST_E_PARAM_POINTER          ((uint8)0x06)

/* ApiId*/
#define FLSTST_INIT_API_ID                      ((uint8)0x00)
#define FLSTST_DEINIT_API_ID                    ((uint8)0x01)
#define FLSTST_START_FGND_API_ID                ((uint8)0x02)
#define FLSTST_ABORT_API_ID                     ((uint8)0X03)

#define FLSTST_SUSPEND_API_ID                   ((uint8)0x04)
#define FLSTST_RESUME_API_ID                    ((uint8)0x05)
#define FLSTST_GET_CURRENT_STATE_API_ID         ((uint8)0x06)
#define FLSTST_GET_TEST_RESULT_BGND_API_ID      ((uint8)0x07)
#define FLSTST_GET_TEST_RESULT_FGND_API_ID      ((uint8)0x0E)
#define FLSTST_VERSION_INFO_API_ID              ((uint8)0x08)
#define FLSTST_GET_TEST_SIGNATURE_BGND_API_ID   ((uint8)0x09)
#define FLSTST_GET_TEST_SIGNATURE_FGND_API_ID   ((uint8)0x0A)
#define FLSTST_GET_ERROR_DETAILS_API_ID         ((uint8)0x0B)
#define FLSTST_TEST_ECC_API_ID                  ((uint8)0x0C)
#define FLSTST_MAINFUNCTION_API_ID              ((uint8)0x0D)


/*******************************************************************************
*   typedef
*******************************************************************************/
/*SWS_FlsTst_00048*/
typedef enum
{
    FLSTST_UNINIT = 0,
    FLSTST_INIT,
    FLSTST_RUNNING,
    FLSTST_ABORTED,
    FLSTST_SUSPENDED
} FlsTst_StateType;

/*SWS_FlsTst_00164*/
typedef enum
{
    FLSTST_RESULT_NOT_TESTED = 0,
    FLSTST_RESULT_OK,
    FLSTST_RESULT_NOT_OK
} FlsTst_TestResultType;

/*SWS_FlsTst_00052*/
typedef enum
{
    FLSTST_NOT_TESTED = 0,
    FLSTST_OK,
    FLSTST_NOT_OK
} FlsTst_TestResultFgndType;


/*SWS_FlsTst_00100*/
#define FLSTST_INVALID_BLOCKID   ((uint32)0xFFFFFFFF)
typedef uint32 FlsTst_IntervalIdType;
typedef uint32 FlsTst_BlockIdFgndType;
typedef uint32 FlsTst_BlockIdBgndType;


typedef uint32 FlsTst_SignatureType;


typedef void (*FlsTst_CompletedNotificationFunType)(void);
typedef void (*FlsTst_AlgorithmFunType)(uint32 Address,
                                        uint32 Size,
                                        boolean First,
                                        P2VAR(FlsTst_SignatureType, TYPEDEF, TYPEDEF) SignaturePtr);

/*SWS_FlsTst_00153*/
typedef struct
{
    FlsTst_IntervalIdType IntervalId;
    FlsTst_TestResultType Result;
} FlsTst_TestResultBgndType;

/*SWS_FlsTst_00108*/
typedef struct
{
    FlsTst_BlockIdBgndType ErrBgndBlockId; /* first err BlockId of bgnd*/
    FlsTst_IntervalIdType  ErrBgndIntervalId;
    FlsTst_BlockIdBgndType  ErrBgndCnt;

    FlsTst_BlockIdFgndType ErrFgndBlockId;
} FlsTst_ErrorDetailsType;

/*SWS_FlsTst_00109*/
typedef struct
{
    FlsTst_BlockIdFgndType FgndBlockId;
    FlsTst_SignatureType Signature;
} FlsTst_TestSignatureFgndType;

/*SWS_FlsTst_00155*/
typedef struct
{
    FlsTst_IntervalIdType IntervalId;
    FlsTst_SignatureType Signature;
} FlsTst_TestSignatureBgndType;


typedef struct
{
    /*runtime information*/
    boolean First;
    uint32 Address;
    uint32 RemainSize;
    FlsTst_SignatureType Signature;
    FlsTst_BlockIdBgndType BlockIndex;
} FlsTst_TestContextType;



typedef struct
{
    uint32 Address;
    uint32 Size;
    uint32 SignatureAddress;
    uint8 Algorithm;
} FlsTst_BlockType;


/*SWS_FlsTst_00018*/
typedef struct
{
    FlsTst_BlockIdBgndType BlockNumberBgnd;
    FlsTst_BlockIdFgndType BlockNumberFgnd;
    P2CONST(FlsTst_BlockType, TYPEDEF, FLSTST_CONST) BlockBgnd;
    P2CONST(FlsTst_BlockType, TYPEDEF, FLSTST_CONST) BlockFgnd;
    FlsTst_CompletedNotificationFunType CompletedNotification;
} FlsTst_ConfigType;


extern const FlsTst_ConfigType FlsTstConfig;
extern const FlsTst_AlgorithmFunType FlsTstAlgorithm[];


/*******************************************************************************
*   api extern
*******************************************************************************/
#define FLSTST_START_SEC_CODE
#include "MemMap.h"

extern FUNC(void, FLSTST_CODE) FlsTst_Init
(
    P2CONST(FlsTst_ConfigType, AUTOMATIC, AUTOMATIC) ConfigPtr
);

extern FUNC(void, FLSTST_CODE) FlsTst_DeInit
(
    void
);

extern FUNC(void, FLSTST_CODE) FlsTst_MainFunction
(
    void
);

extern FUNC(void, FLSTST_CODE) FlsTst_Abort
(
    void
);

#if (FLSTST_START_FGND_API == STD_ON)
extern FUNC(Std_ReturnType, FLSTST_CODE) FlsTst_StartFgnd
(
    FlsTst_BlockIdFgndType FgndBlockId
);
#endif

#if (FLSTST_SUSPEND_RESUME_API == STD_ON)
extern FUNC(void, FLSTST_CODE) FlsTst_Suspend
(
    void
);
#endif

#if (FLSTST_SUSPEND_RESUME_API == STD_ON)
extern FUNC(void, FLSTST_CODE) FlsTst_Resume
(
    void
);
#endif

#if (FLSTST_GET_CURRENT_STATE_API == STD_ON)
extern FUNC(FlsTst_StateType, FLSTST_CODE) FlsTst_GetCurrentState
(
    void
);
#endif

#if (FLSTST_GET_TEST_RESULT_BGND_API == STD_ON)
extern FUNC(FlsTst_TestResultBgndType, FLSTST_CODE) FlsTst_GetTestResultBgnd
(
    void
);
#endif

#if (FLSTST_GET_TEST_RESULT_FGND_API == STD_ON)
extern FUNC(FlsTst_TestResultFgndType, FLSTST_CODE) FlsTst_GetTestResultFgnd
(
    void
);
#endif

#if (FLSTST_VERSION_INFO_API == STD_ON)
extern FUNC(void, FLSTST_CODE) FlsTst_GetVersionInfo
(
    P2VAR(Std_VersionInfoType, AUTOMATIC, AUTOMATIC) VersionInfoPtr
);
#endif

#if (FLSTST_GET_TEST_SIGNATURE_BGND_API == STD_ON)
extern FUNC(FlsTst_TestSignatureBgndType, FLSTST_CODE) FlsTst_GetTestSignatureBgnd
(
    void
);
#endif

#if (FLSTST_GET_TEST_SIGNATURE_FGND_API == STD_ON)
extern FUNC(FlsTst_TestSignatureFgndType, FLSTST_CODE) FlsTst_GetTestSignatureFgnd
(
    void
);
#endif

#if (FLSTST_GET_ERROR_DETAILS_API == STD_ON)
extern FUNC(FlsTst_ErrorDetailsType, FLSTST_CODE) FlsTst_GetErrorDetails
(
    void
);
#endif

#if (FLSTST_TEST_ECC_API == STD_ON)
extern FUNC(Std_ReturnType, FLSTST_CODE) FlsTst_TestEcc
(
    void
);
#endif


#define FLSTST_STOP_SEC_CODE
#include "MemMap.h"

#endif

