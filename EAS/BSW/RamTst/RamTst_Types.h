/*  BEGIN_FILE_HDR
********************************************************************************
*   NOTICE
*   This software is the property of HiRain Technologies. Any information
*   contained in this doc should not be reproduced, or used, or disclosed
*   without the written authorization from HiRain Technologies.
********************************************************************************
*   File Name       : RamTst_Types.h
********************************************************************************
*   Project/Product : AUTOSAR 4.2.2
*   Title           : RamTst Interface module type definitions head File
*   Author          : Juncheng Li
********************************************************************************
*   Description     : The header file RamTst_Types.h contains the  common type
*                     definitions of the module Can Interface
*
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


#ifndef RAMTST_TYPES_H
#define RAMTST_TYPES_H
/*******************************************************************************
*   Includes
*******************************************************************************/
#include "RamTst_Cfg.h"
#include "RamTst_Version.h"
#include "Std_Types.h"


/*******************************************************************************
*   Typedef
*******************************************************************************/
typedef enum
{
    RAMTST_EXECUTION_UNINIT = 0,    /*RamTst006*/
    RAMTST_EXECUTION_STOPPED,
    RAMTST_EXECUTION_RUNNING,
    RAMTST_EXECUTION_SUSPENDED
} RamTst_ExecutionStatusType;   /*RamTst189*/

typedef enum
{
    RAMTST_RESULT_NOT_TESTED = 0,   /*RamTst012*/
    RAMTST_RESULT_OK,
    RAMTST_RESULT_NOT_OK,
    RAMTST_RESULT_UNDEFINED
} RamTst_TestResultType;        /*RamTst190*/

typedef enum
{
    RAMTEST_NON_DESTRUCTIVE = 0,/*RamTst200*/
    RAMTEST_DESTRUCTIVE         /*RamTst201*/
} RamTst_TestPolicyType;

typedef enum
{
    RAMTST_ALGORITHM_UNDEFINED = 0, /*RamTst013*/
#if (STD_ON == RAMTST_CHECKERBOARD_TEST_SELECTED)
    RAMTST_CHECKERBOARD_TEST,
#endif

#if (STD_ON == RAMTST_MARCH_TEST_SELECTED)
    RAMTST_MARCH_TEST,
#endif

#if (STD_ON == RAMTST_WALK_PATH_TEST_SELECTED)
    RAMTST_WALK_PATH_TEST,
#endif

#if (STD_ON == RAMTST_GALPAT_TEST_SELECTED)
    RAMTST_GALPAT_TEST,
#endif

#if (STD_ON == RAMTST_TRANSP_GALPAT_TEST_SELECTED)
    RAMTST_TRANSP_GALPAT_TEST,
#endif

#if (STD_ON == RAMTST_ABRAHAM_TEST_SELECTED)
    RAMTST_ABRAHAM_TEST,
#endif

    RAMTST_ALGORITHM_CHECKER    /*check if the algorithm configuration is error.*/
} RamTst_AlgorithmType;         /*RamTst227*/

typedef uint8  RamTst_AlgParamsIdType;          /*RamTst191*/
typedef uint32 RamTst_NumberOfTestedCellsType;  /*RamTst173*/
typedef uint16 RamTst_NumberOfBlocksType;       /*RamTst174*/

typedef P2FUNC(void, TYPEDEF, RamTst_NotificationFunType)(void);

typedef    P2FUNC(RamTst_TestResultType, TYPEDEF, RamTst_AlgorithmFunType)(uint32 Address,
        P2VAR(RamTst_NumberOfTestedCellsType, AUTOMATIC, AUTOMATIC) TestedNumber);

typedef struct
{
    RamTst_NumberOfBlocksType BlockId;
    RamTst_NumberOfBlocksType AlgParamsBlockId;
    uint32 Address;
    uint32 RemainCells;
} RamTst_TestContextType;

typedef struct
{
    RamTst_NumberOfBlocksType AlgParamsBlockId;
    RamTst_NumberOfBlocksType BlockId;
    RamTst_TestPolicyType TestPolicy;
    uint32 FillPattern;
    uint32 StartAddress;
    uint32 EndAddress;
} RamTst_ConfigBlockParamsType;

typedef struct
{
    RamTst_AlgParamsIdType AlgParamsId;
    RamTst_AlgorithmType Algorithm;
    RamTst_NumberOfBlocksType NumberOfBlocks;
    RamTst_NumberOfTestedCellsType NumberOfTestedCells;
    RamTst_NumberOfTestedCellsType MaxNumberOfTestedCells;
    RamTst_NumberOfTestedCellsType ExtNumberOfTestedCells;
    P2CONST(RamTst_ConfigBlockParamsType, AUTOMATIC, RAMTST_CONST) BlockParams;
} RamTst_ConfigAlgParamsType;

typedef struct
{
    RamTst_AlgParamsIdType DefaultAlgParamsId;
    RamTst_AlgParamsIdType NumberOfAlgParamSets;
    RamTst_NumberOfTestedCellsType MinNumberOfTestedCells;
    P2CONST(RamTst_ConfigAlgParamsType, AUTOMATIC, RAMTST_CONST) AlgParamSets;
    RamTst_NotificationFunType TestErrorNotification;
    RamTst_NotificationFunType TestCompletedNotification;
} RamTst_ConfigParamsType;

typedef uint8 RamTst_ConfigType;/*RamTst1011*/

#endif

