/*  BEGIN_FILE_HDR
********************************************************************************
*   File Name       : UdpNm_Lcfg.c
********************************************************************************
*   Project/Product : AUTOSAR BSW PROJECT
*   Title           : UdpNm module configuration File
*   Author          : Hirain
********************************************************************************
*   Description     : UdpNm module configuration File
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


#include "UdpNm_Types.h"
#include "UdpNm_Lcfg.h"
#include "SoAd_Cfg.h"

/*******************************************************************************
*   Configuration
*******************************************************************************/
#define UDPNM_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h"
VAR(Nm_StateType, UDPNM_VAR_NOINIT) UdpNm_State[UDPNM_NUMBER_OF_CHANNELS];
VAR(uint8, UDPNM_VAR_NOINIT) UdpNm_TxPduData[UDPNM_NUMBER_OF_CHANNELS * 8];
VAR(PduInfoType, UDPNM_VAR_NOINIT) UdpNm_TxPdu[UDPNM_NUMBER_OF_CHANNELS];
VAR(uint8, UDPNM_VAR_NOINIT) UdpNm_ImmTrans[UDPNM_NUMBER_OF_CHANNELS];
VAR(boolean, UDPNM_VAR_NOINIT) UdpNm_TxConfFlg[UDPNM_NUMBER_OF_CHANNELS];
VAR(boolean, UDPNM_VAR_NOINIT) UdpNm_TxReqFlg[UDPNM_NUMBER_OF_CHANNELS];
VAR(boolean, UDPNM_VAR_NOINIT) UdpNm_RptMsgReq[UDPNM_NUMBER_OF_CHANNELS];
VAR(uint8, UDPNM_VAR_NOINIT) UdpNm_RxPduData[UDPNM_NUMBER_OF_CHANNELS * 8];
VAR(PduInfoType, UDPNM_VAR_NOINIT) UdpNm_RxPdu[UDPNM_NUMBER_OF_CHANNELS];
VAR(Nm_ModeType, UDPNM_VAR_NOINIT) UdpNm_Mode[UDPNM_NUMBER_OF_CHANNELS];
VAR(UdpNm_NetworkStateType, UDPNM_VAR_NOINIT) UdpNm_NetworkState[UDPNM_NUMBER_OF_CHANNELS];
VAR(boolean, UDPNM_VAR_NOINIT) UdpNm_RxIndFlg[UDPNM_NUMBER_OF_CHANNELS];
VAR(UdpNm_NetworkReqType, UDPNM_VAR_NOINIT) UdpNm_NetworkReqCmd[UDPNM_NUMBER_OF_CHANNELS];
VAR(boolean, UDPNM_VAR) UdpNm_PnFilterEnable[UDPNM_NUMBER_OF_CHANNELS];
VAR(uint16, UDPNM_CONST) UdpNm_PnEraPnTimer[UDPNM_NUMBER_OF_CHANNELS][8];
VAR(uint8, UDPNM_VAR) UdpNm_PnEraArray[UDPNM_NUMBER_OF_CHANNELS][1];
VAR(uint8, UDPNM_VAR) UdpNm_PnEraNewReq[UDPNM_NUMBER_OF_CHANNELS][1];
VAR(UdpNm_ComCtrlType, UDPNM_VAR_NOINIT) UdpNm_ComCtrlReq[UDPNM_NUMBER_OF_CHANNELS];
VAR(UdpNm_ComCtrlType, UDPNM_VAR_NOINIT) UdpNm_ComCtrlState[UDPNM_NUMBER_OF_CHANNELS];
VAR(UdpNm_NetworkRestartType, UDPNM_VAR_NOINIT) UdpNm_RestartState[UDPNM_NUMBER_OF_CHANNELS];
VAR(UdpNm_TimerType, UDPNM_VAR_NOINIT) UdpNm_Timer[UDPNM_NUMBER_OF_CHANNELS];

#define UDPNM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h"

#define UDPNM_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "MemMap.h"
CONST(UdpNm_ChannelConfigType, UDPNM_CONST) UdpNm_LConfig[1] =
{
	
	/* UdpNmChannelConfig, index = 0 */
    {
    	FALSE,	    			/*UdpNmActiveWakeupBitEnabled*/                   
        5,                 /*UdpNmImmediateNmTransmissions*/
        2,                 /*UdpNmMsgCycleOffset*/
        100,                 /*UdpNmMsgCycleTime*/
        20,                 /*UdpNmMsgTimeoutTime*/
        0x8,                 /*UdpNmNodeId*/
        UDPNM_PDU_BYTE_0,                 /*UdpNmPduNidPosition*/
        UDPNM_PDU_BYTE_1,                 /*UdpNmPduCbvPosition*/
        300,                /*UdpNmRepeatMessageTime*/
        400,                /*UdpNmTimeoutTime*/
        1000,                /*UdpNmWaitBusSleepTime*/        
        NM_ComM_EthCtrl,     			/*UdpMNetworkHandleRef*/
        8,                /*UdpNmPduLength*/                            	   
        0,                /*UdpNmPduStartIndex*/	
    	0, 						/*UdpNmPduNIDIndex*/
    	1, 					   	/*UdpNmPduCBVIndex*/
		2,                /*UdpNmPduUserDataStartIndex*/
        6,                /*UdpNmPduUserDataLength*/
        FALSE,                /*UdpNmPnEnabled*/
        SoAd_UdpNm_UdpNm_Tx,                  	/* UdpNmTxPduIdRef */
    },       
};

 


CONST(UdpNm_ConfigType, UDPNM_CONST) UdpNm_Config =
{
    FALSE,   /*UdpNmCarWakeUpFilterEnabled*/
    0,                            /*UdpNmCarWakeUpFilterNodeId*/ 
    FALSE,       /*UdpNmCarWakeUpRxEnabled*/
};


#define UDPNM_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "MemMap.h"

