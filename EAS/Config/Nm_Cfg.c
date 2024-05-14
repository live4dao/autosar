/*  BEGIN_FILE_HDR
********************************************************************************
*   File Name       : Nm_Cfg.c
********************************************************************************
*   Project/Product : AUTOSAR BSW PROJECT
*   Title           : Nm module configuration File
*   Author          : Hirain
********************************************************************************
*   Description     : Nm module configuration File
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
    Includes Files
*******************************************************************************/
#include "Nm_Lcfg.h"

/*******************************************************************************
*   Config Parameters
*******************************************************************************/

#define NM_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "MemMap.h"


/*******************************************************************************
*   NmChannelConfig
*******************************************************************************/
/*newConfig*/
CONST(Nm_ChannelConfigType, NM_CONST) Nm_ChannelCfg[NM_NUM_OF_CHANNELS] =
{
    /* Channel ID 0: */
    {
        NM_BUSNM_CANNM,
        ComM_ComM_CanCtrl_0,    /*to ComM*/
        CanNM_ComM_CanCtrl_0,   /*to BusNm*/
        FALSE,
        0,
        50,
        FALSE,
        FALSE,
        0
    },
    /* Channel ID 1: */
    {
        NM_BUSNM_UDPNM,
        ComM_ComM_EthCtrl,    /*to ComM*/
        UdpNM_ComM_EthCtrl,   /*to BusNm*/
        FALSE,
        0,
        50,
        FALSE,
        FALSE,
        0
    }
};

#define NM_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "MemMap.h"

