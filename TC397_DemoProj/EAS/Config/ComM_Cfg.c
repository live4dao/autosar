/*  BEGIN_FILE_HDR
********************************************************************************
*   File Name       : ComM_Cfg.c
********************************************************************************
*   Project/Product : AUTOSAR BSW PROJECT
*   Title           : ComM module configuration File
*   Author          : Hirain
********************************************************************************
*   Description     : ComM module configuration File
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
#include "ComM.h"
#include "CanSM.h"
#include "EthSM.h"
#include "Nm.h"
#include "Rte_ComM.h"


/*******************************************************************************
*   Config Parameters
*******************************************************************************/



/*******************************************************************************
*   ComMConfigSet
*******************************************************************************/

#define COMM_START_SEC_CONFIG_DATA_8
#include "MemMap.h"

/* ECUC_ComM_00563 */
CONST(ComM_InhibitionStatusType, COMM_CONST) ComMEcuGroupClassificationDefault = 0x3;

/* ECUC_ComM_00568 */
CONST(uint8, COMM_CONST) ComMNmVariant[3] =
{
    COMM_FULL,
    COMM_LIGHT,
    COMM_FULL
};

/* ECUC_ComM_00567 */
CONST(ComM_BusType, COMM_CONST) ComMBusType[3] =
{
    COMM_BUS_TYPE_CAN,
    COMM_BUS_TYPE_CAN,
    COMM_BUS_TYPE_ETH
};

/* ECUC_ComM_00657 ECUC_ComM_00658 */
CONST(uint8, COMM_CONST) ComMUserMappingChannelStart[1] =
{
    0
};

CONST(uint8, COMM_CONST) ComMUserMappingChannelNum[1] =
{
    3
};

CONST(NetworkHandleType, COMM_CONST) ComMUserMappingChannel[3] =
{
    0,
    1,
    2
};

/* channel mapping to actual user*/
CONST(uint8, COMM_CONST) ComMChannelMappingUserStart[3] =
{
    0,
    1,
    2
};

CONST(uint8, COMM_CONST) ComMChannelMappingUserNum[3] =
{
    1,
    1,
    1
};

CONST(ComM_UserHandleType, COMM_CONST) ComMChannelMappingUser[3] =
{
    0,
    0,
    0
};

CONST(NetworkHandleType, COMM_CONST) ComMMappingChannelToBusSM[3] =
{
    CanSM_ComM_CanCtrl_0,
    CanSM_ComM_CanCtrl_1,
    EthSM_ComM_EthCtrl
};

CONST(NetworkHandleType, COMM_CONST) ComMMappingChannelToNm[3] =
{
    NM_ComM_CanCtrl_0,
    NM_INVALID_CHANNEL,
    NM_ComM_EthCtrl
};

/* ECUC_ComM_00556 */
CONST(uint8, COMM_CONST) ComMMainFunctionPeriod[3] =
{
    5,
    5,
    5
};

#define COMM_STOP_SEC_CONFIG_DATA_8
#include "MemMap.h"

#define COMM_START_SEC_CONFIG_DATA_16
#include "MemMap.h"

/* ECUC_ComM_00557 */
CONST(uint16, COMM_CONST) ComMTMinFullComModeDuration[3] =
{
    1000,
    1000,
    1000
};

/* ECUC_ComM_00606 */
CONST(uint16, COMM_CONST) ComMNmLightTimeout[3] =
{
    2000,
    1600,
    2000
};

#define COMM_STOP_SEC_CONFIG_DATA_16
#include "MemMap.h"

#define COMM_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "MemMap.h"

CONST(ComM_RteSwitchFctPtrType, COMM_CONST) ComM_RteSwitchFunction[COMM_NUM_OF_USER] =
{
    Rte_Switch_UM_User_ComMMode
};

#define COMM_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "MemMap.h"


