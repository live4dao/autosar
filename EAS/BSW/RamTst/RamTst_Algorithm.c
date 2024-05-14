/*  BEGIN_FILE_HDR
********************************************************************************
*   NOTICE                              
*   This software is the property of HiRain Technologies. Any information 
*   contained in this doc should not be reproduced, or used, or disclosed 
*   without the written authorization from HiRain Technologies.
********************************************************************************
*   File Name       : RamTst_Algorithm.c
********************************************************************************
*   Project/Product : AUTOSAR BSW PROJECT
*   Title           : RamTst module configuration Algorithm File
*   Author          : Hirain
********************************************************************************
*   Description     : RamTst module configuration Algorithm File
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

/*******************************************************************************
*   Includes 
*******************************************************************************/

#include "RamTst.h"
/*******************************************************************************
*   Macro 
*******************************************************************************/

#define RAMTST_CHECKERBOARD_PATTERN       ((uint32)0x55555555)
#define RAMTST_CHECKERBOARD_MIN_NUMBER   ((uint32)0x08)

#define RAMTST_MARCH_PATTERN               ((uint32)0)
#define RAMTST_MARCH_MIN_NUMBER            ((uint32)0x08)

#define RAMTST_ADDR_OFFSET                 ((uint32)0x04)

#define RAMTST_START_SEC_CODE
#include "MemMap.h"

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: RamTst_DefaultTest
*                
* Description:  .This function with no real function   
*               
* Inputs:        Address: start address 
*                TestedNumber:number of test cells in this test algorithm 
*                   
* Outputs:       None
* 
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(RamTst_TestResultType, AUTOMATIC) RamTst_DefaultTest
(
	uint32 Address, 
	P2VAR(RamTst_NumberOfTestedCellsType,AUTOMATIC,AUTOMATIC) TestedNumber
)
{
	(void)Address;
	(void)TestedNumber;

	return RAMTST_RESULT_NOT_OK;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: RamTst_CheckerBoardTest
*                
* Description:  .Use the CheckerBoard algorithm test RAM
*               
* Inputs:        Address: start address 
*                TestedNumber:number of test cells in this test algorithm 
*                   
* Outputs:       None
* 
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
#if (STD_ON == RAMTST_CHECKERBOARD_TEST_SELECTED)
FUNC(RamTst_TestResultType, AUTOMATIC) RamTst_CheckerBoardTest
(
	uint32 Address, 
	P2VAR(RamTst_NumberOfTestedCellsType,AUTOMATIC,AUTOMATIC) TestedNumber
)
{
	register RamTst_TestResultType result = RAMTST_RESULT_NOT_OK;
	register uint32 backup0;
	register uint32 backup1;
	register P2VAR(uint32, AUTOMATIC, AUTOMATIC) dataFirst;
	register P2VAR(uint32, AUTOMATIC, AUTOMATIC) dataSecond;

	dataFirst = (uint32*)Address;
	dataSecond = (uint32*)(Address + RAMTST_ADDR_OFFSET);
    
	backup0 = *dataFirst;
	backup1 = *dataSecond;

    
	
	*dataFirst = RAMTST_CHECKERBOARD_PATTERN;/*step 1 */
	*dataSecond = RAMTST_CHECKERBOARD_PATTERN;
	RamTst_ClearCache();
	if ((*dataFirst == RAMTST_CHECKERBOARD_PATTERN)    /*step 2*/
		&& (*dataSecond == RAMTST_CHECKERBOARD_PATTERN))
	{
		*dataFirst = ~RAMTST_CHECKERBOARD_PATTERN;   /*step 3*/
		*dataSecond = ~RAMTST_CHECKERBOARD_PATTERN;
		RamTst_ClearCache();
		if ((*dataFirst == ~RAMTST_CHECKERBOARD_PATTERN) /*step 4*/
			&& (*dataSecond == ~RAMTST_CHECKERBOARD_PATTERN))
		{
			result = RAMTST_RESULT_OK;
		}
	}

	*dataFirst = backup0;
	*dataSecond = backup1;
	
	*TestedNumber = RAMTST_CHECKERBOARD_MIN_NUMBER;

	return result;
}
#endif

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: RamTst_MarchTest
*                
* Description:  .Use the March algorithm test RAM  
*               
* Inputs:        Address: start address 
*                TestedNumber:number of test cells in this test algorithm 
*                   
* Outputs:       None
* 
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
#if (STD_ON == RAMTST_MARCH_TEST_SELECTED)
FUNC(RamTst_TestResultType, AUTOMATIC) RamTst_MarchTest
(
	uint32 Address, 
	P2VAR(RamTst_NumberOfTestedCellsType,AUTOMATIC,AUTOMATIC) TestedNumber
)
{
	register RamTst_TestResultType result = RAMTST_RESULT_NOT_OK;
	register uint32 backup0;
	register uint32 backup1;
	register P2VAR(uint32, AUTOMATIC, AUTOMATIC) dataFirst;
	register P2VAR(uint32, AUTOMATIC, AUTOMATIC) dataSecond;

	dataFirst = (uint32*)Address;
	dataSecond = (uint32*)(Address + RAMTST_ADDR_OFFSET);

	/*{up(w0); up(r0,w1); down(r1,w0,r0)}*/
	backup0 = *dataFirst;
	backup1 = *dataSecond;

	*dataFirst = RAMTST_MARCH_PATTERN;/*W0*/
	*dataSecond = RAMTST_MARCH_PATTERN;

	RamTst_ClearCache();
	if((*dataFirst == RAMTST_MARCH_PATTERN)    /*R0*/
		&& (*dataSecond == RAMTST_MARCH_PATTERN))
	{
		*dataFirst = ~RAMTST_MARCH_PATTERN;   /*AND W1*/
		*dataSecond = ~RAMTST_MARCH_PATTERN;
		RamTst_ClearCache();
		if ((*dataSecond == ~RAMTST_MARCH_PATTERN)   /*R1*/
			&& (*dataFirst == ~RAMTST_MARCH_PATTERN))
		{
			*dataSecond = RAMTST_MARCH_PATTERN;         /*AND W0*/
			*dataFirst = RAMTST_MARCH_PATTERN;
			RamTst_ClearCache();
			if ((*dataSecond == RAMTST_MARCH_PATTERN)   /*R0*/
				&&(*dataFirst == RAMTST_MARCH_PATTERN))
			{
				result = RAMTST_RESULT_OK;
			}
		}
	}

	*dataFirst = backup0;
	*dataSecond = backup1;
    
	*TestedNumber = RAMTST_MARCH_MIN_NUMBER;

	return result;
}
#endif


#define RAMTST_STOP_SEC_CODE
#include "MemMap.h"



