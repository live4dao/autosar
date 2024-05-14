/*  BEGIN_FILE_HDR
********************************************************************************
*   NOTICE
*   This software is the property of HiRain Technologies. Any information
*   contained in this doc should not be reproduced, or used, or disclosed
*   without the written authorization from HiRain Technologies.
********************************************************************************
*   File Name       : RamTst.h
********************************************************************************
*   Project/Product : AUTOSAR 4.2.2
*   Title           : RamTst Interface module head File
*   Author          : Juncheng Li
********************************************************************************
*   Description     : RamTst Interface module head File
********************************************************************************
*   Limitations     : None
*
********************************************************************************
*
********************************************************************************
*   Revision History:
*   Reference to Core C File
********************************************************************************
* END_FILE_HDR*/

#ifndef RAMTST_H
#define RAMTST_H

/*******************************************************************************
*   Includes
*******************************************************************************/

#include "RamTst_Lcfg.h"


/*******************************************************************************
*   Macro
*******************************************************************************/

#define RAMTST_E_STATUS_FAILURE     ((uint8)0x01)
#define RAMTST_E_OUT_OF_RANGE       ((uint8)0x02)
#define RAMTST_E_UNINIT             ((uint8)0x03)
#define RAMTST_E_PARAM_POINTER      ((uint8)0x04)

#define RAMTST_INIT_API_ID          ((uint8)0x00)
#define RAMTST_DEINIT_API_ID        ((uint8)0x0C)
#define RAMTST_STOP_API_ID          ((uint8)0x02)
#define RAMTST_ALLOW_API_ID         ((uint8)0x03)
#define RAMTST_SUSPEND_API_ID       ((uint8)0x0D)
#define RAMTST_RESUME_API_ID        ((uint8)0x0E)

#define RAMTST_GET_EXECUTION_STATUS_API_ID          ((uint8)0x04)
#define RAMTST_GET_TEST_RESULT_API_ID               ((uint8)0x05)
#define RAMTST_GET_TEST_RESULT_PER_BLOCK_API_ID     ((uint8)0x06)
#define RAMTST_GET_VERSION_INFO_API_ID              ((uint8)0x0A)
#define RAMTST_GET_ALG_PARAMS_API_ID                ((uint8)0x12)
#define RAMTST_GET_TEST_ALGORITHM_API_ID            ((uint8)0x07)
#define RAMTST_GET_NUMBER_OF_TESTED_CELLS_API_ID    ((uint8)0x09)
#define RAMTST_SELECT_ALG_PARAMS_API_ID             ((uint8)0x0B)
#define RAMTST_CHANGE_NUMBER_OF_TESTED_CELLS_API_ID ((uint8)0x08)
#define RAMTST_RUN_FULL_TEST_API_ID                 ((uint8)0x10)
#define RAMTST_RUN_PARTIAL_TEST_API_ID              ((uint8)0x11)





/*******************************************************************************
*   Local Functions declare
*******************************************************************************/

#define RAMTST_START_SEC_CODE
#include "MemMap.h"

extern FUNC(RamTst_TestResultType, AUTOMATIC) RamTst_DefaultTest
(
    uint32 Address,
    P2VAR(RamTst_NumberOfTestedCellsType, AUTOMATIC, AUTOMATIC) TestedNumber
);

#if (STD_ON == RAMTST_CHECKERBOARD_TEST_SELECTED)
extern FUNC(RamTst_TestResultType, AUTOMATIC) RamTst_CheckerBoardTest
(
    uint32 Address,
    P2VAR(RamTst_NumberOfTestedCellsType, AUTOMATIC, AUTOMATIC) TestedNumber
);
#endif

#if (STD_ON == RAMTST_MARCH_TEST_SELECTED)
extern FUNC(RamTst_TestResultType, AUTOMATIC) RamTst_MarchTest
(
    uint32 Address,
    P2VAR(RamTst_NumberOfTestedCellsType, AUTOMATIC, AUTOMATIC) TestedNumber
);
#endif

extern FUNC(void, RAMTST_CODE) RamTst_Init
(
    P2CONST(RamTst_ConfigType, AUTOMATIC, AUTOMATIC) ConfigPtr
);

extern FUNC(void, RAMTST_CODE) RamTst_DeInit
(
    void
);

extern FUNC(void, RAMTST_CODE) RamTst_MainFunction
(
    void
);

#if (STD_ON == RAMTST_STOP_API)
extern FUNC(void, RAMTST_CODE) RamTst_Stop
(
    void
);
#endif

#if (STD_ON == RAMTST_ALLOW_API)
extern FUNC(void, RAMTST_CODE) RamTst_Allow
(
    void
);
#endif

#if (STD_ON == RAMTST_SUSPEND_API)
extern FUNC(void, RAMTST_CODE) RamTst_Suspend
(
    void
);
#endif

#if (STD_ON == RAMTST_RESUME_API)
extern FUNC(void, RAMTST_CODE) RamTst_Resume
(
    void
);
#endif

#if (STD_ON == RAMTST_GET_EXECUTION_STATUS_API)
extern FUNC(RamTst_ExecutionStatusType, RAMTST_CODE) RamTst_GetExecutionStatus
(
    void
);
#endif

#if (STD_ON == RAMTST_GET_TEST_RESULT_API)
extern FUNC(RamTst_TestResultType, RAMTST_CODE) RamTst_GetTestResult
(
    void
);
#endif

#if (STD_ON == RAMTST_GET_TEST_RESULT_PER_BLOCK_API)
extern FUNC(RamTst_TestResultType, RAMTST_CODE) RamTst_GetTestResultPerBlock
(
    RamTst_NumberOfBlocksType BlockId
);
#endif

#if (STD_ON == RAMTST_GET_VERSION_INFO_API)
extern FUNC(void, RAMTST_CODE) RamTst_GetVersionInfo
(
    P2VAR(Std_VersionInfoType, AUTOMATIC, AUTOMATIC) VersionInfoPtr
);
#endif

#if (STD_ON == RAMTST_GET_ALG_PARAMS_API)
extern FUNC(RamTst_AlgParamsIdType, RAMTST_CODE) RamTst_GetAlgParams
(
    void
);
#endif

#if (STD_ON == RAMTST_GET_TEST_ALGORITHM_API)
extern FUNC(RamTst_AlgorithmType, RAMTST_CODE) RamTst_GetTestAlgorithm
(
    void
);
#endif

#if (STD_ON == RAMTST_GET_NUMBER_OF_TESTED_CELLS_API)
extern FUNC(RamTst_NumberOfTestedCellsType, RAMTST_CODE) RamTst_GetNumberOfTestedCells
(
    void
);
#endif

#if (STD_ON == RAMTST_SELECT_ALG_PARAMS_API)
extern FUNC(void, RAMTST_CODE) RamTst_SelectAlgParams
(
    RamTst_AlgParamsIdType NewAlgParamsId
);
#endif

#if (STD_ON == RAMTST_CHANGE_NUMBER_OF_TESTED_CELLS_API)
extern FUNC(void, RAMTST_CODE) RamTst_ChangeNumberOfTestedCells
(
    RamTst_NumberOfTestedCellsType NewNumberOfTestedCells
);
#endif


#if (STD_ON == RAMTST_RUN_FULL_TEST_API)
extern FUNC(void, Std_VersionInfoType) RamTst_RunFullTest
(
    void
);
#endif

#if (STD_ON == RAMTST_RUN_PARTIAL_TEST_API)
extern FUNC(void, Std_VersionInfoType) RamTst_RunPartialTest
(
    RamTst_NumberOfBlocksType BlockId
);
#endif

#define RAMTST_STOP_SEC_CODE
#include "MemMap.h"

#endif

