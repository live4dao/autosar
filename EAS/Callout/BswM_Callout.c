/*  BEGIN_FILE_HDR
********************************************************************************
*   File Name       : BswM_Callout.c
********************************************************************************
*   Project/Product : AUTOSAR BSW PROJECT
*   Title           : BswM module configuration File
*   Author          : Hirain
********************************************************************************
*   Description     : BswM module configuration File
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
#include "BswM_Cfg.h"
#include "Os.h"
/* Input File User Code start*/
#include "Compiler.h"

#include "Rte_Main.h"

#include "CanIf.h"
#include "CanSM.h"
#include "CanNm.h"
#include "CanTp.h"
#include "PduR.h"
#include "Nm.h"
#include "Com.h"
#include "Dcm.h"
#include "Dem.h"
#include "Dem_NvM.h"
#include "FiM.h"
#include "ComM.h"
#include "NvM.h"
#include "StbM.h"
#include "CanTsyn.h"
#include "WdgM.h"
#include "FlsTst.h"
#include "RamTst.h"
#include "EthTSyn.h"
#include "SoAd.h"
#include "TcpIp.h"
#include "EthTrcv.h"
//#include "EthSwt.h"
#include "EthIf.h"
#include "DoIP.h"
#include "Xcp.h"
#include "UdpNm.h"
/* Input File User Code end*/

#define BSWM_START_SEC_CODE
#include "MemMap.h"


/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: BswM_InitBlockIICallout
*
* Description:   None
*
* Inputs:        None
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, BSWM_CODE)  BswM_InitBlockIICallout(void)
{
    /*Initialiaze memory stack modules such as Eep/Ea/Fls/Fee/NvM.
      This function will be called only once after power-on.
    */
    /* BswM_InitBlockIICallout User Code start*/
	CanIf_Init(NULL_PTR);
	CanSM_Init(NULL_PTR);
	CanTp_Init(NULL_PTR);
	CanNm_Init(NULL_PTR);

	Com_Init(NULL_PTR);
	PduR_Init(NULL_PTR);
	Nm_Init();
	ComM_Init(NULL_PTR);
	NvM_Init(NULL_PTR);

	Dcm_Init(NULL_PTR);
	(void)Dcm_SetActiveDiagnostic(TRUE);
	FiM_Init(NULL_PTR);

	StbM_Init(NULL_PTR);
	CanTSyn_Init(NULL_PTR);

  Xcp_Init(&Xcp_Config[0]);
  UdpNm_Init(NULL_PTR);
  DoIP_Init(NULL_PTR);
  DoIP_ActivationLineSwitch();
  EthIf_Init(NULL_PTR);
  EthSM_Init(); 
  TcpIp_Init(NULL_PTR);
  SoAd_Init(NULL_PTR);
  EthTSyn_Init(NULL_PTR);
//	WdgM_Init(NULL_PTR);
//	FlsTst_Init(NULL_PTR);
//	RamTst_Init(NULL_PTR);
//	Xcp_Init(NULL_PTR);

	/* Active OS Task */
	SetRelAlarm(OsAlarm_Core0_Bsw_5ms, 1, 5);
	SetRelAlarm(OsAlarm_Core0_App_10ms, 2, 10);
	SetRelAlarm(OsAlarm_Core0_BswWdgM_1ms, 3, 1);

    /* BswM_InitBlockIICallout User Code end*/
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: BswM_PostReadAllCallout
*
* Description:   None
*
* Inputs:        None
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
static boolean FirstInit = TRUE;
FUNC(void, BSWM_CODE)  BswM_PostReadAllCallout(void)
{
    /*Non-volatile data has been restored to RAM. Initialize modules and SWCs that
      rely on those data. This function will be called after power-on and every wakeup,
      so make sure modules are initialized only once.
    */
    /* BswM_PostReadAllCallout User Code start*/
	if(FirstInit)
	{
		(void)Dem_NvM_InitStorageMem();
		Dem_Init(NULL_PTR);

		(void)Rte_Start();

		FirstInit = FALSE;
	}
    /* BswM_PostReadAllCallout User Code end*/
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: BswM_WriteNvMToSleepCallout
*
* Description:   None
*
* Inputs:        None
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, BSWM_CODE)  BswM_WriteNvMToSleepCallout(void)
{
    /*Call EcuM_GoHalt() or EcuM_GoPoll() to set system to sleep. Or call EcuM_GoDown()
      to set system to shutdown.
    */
    /* BswM_WriteNvMToSleepCallout User Code start*/
	(void)Rte_Stop();
    /* BswM_WriteNvMToSleepCallout User Code end*/
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: BswM_NvMWriteAllCallout
*
* Description:   None
*
* Inputs:        None
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, BSWM_CODE)  BswM_NvMWriteAllCallout(void)
{
    /*Call NvM_WriteAll() to save data to non-volatile devices. This function
      will be called before power-off and sleep, so you should decide when
      to write or not.
    */
    /* BswM_NvMWriteAllCallout User Code start*/
    NvM_WriteAll();
    /* BswM_NvMWriteAllCallout User Code end*/
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: BswM_NvMReadAllCallout
*
* Description:   None
*
* Inputs:        None
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, BSWM_CODE)  BswM_NvMReadAllCallout(void)
{
    /*Call NvM_ReadAll() to restore data from non-volatile devices. This function
      will be called after power-on and after wakeup, so you should decide when
      to read or not.
    */
    /* BswM_NvMReadAllCallout User Code start*/
    NvM_ReadAll();
    /* BswM_NvMReadAllCallout User Code end*/
}
#define BSWM_STOP_SEC_CODE
#include "MemMap.h"




