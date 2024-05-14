/*  BEGIN_FILE_HDR
********************************************************************************
*   NOTICE
*   This software is the property of HiRain Technologies. Any information
*   contained in this doc should not be reproduced, or used, or disclosed
*   without the written authorization from HiRain Technologies.
********************************************************************************
*   File Name       : ComM_Types.h
********************************************************************************
*   Project/Product : AUTOSAR 4.2
*   Title           : ComM_Types.h
*   Author          : Hirain
********************************************************************************
*   Description     : The header file ComM_Types.h contains the  common type
*                     definitions of the module COM Manager
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
#ifndef COMM_TYPES_H
#define COMM_TYPES_H

/*******************************************************************************
*   Includes
*******************************************************************************/
#include "ComStack_Types.h"

/*******************************************************************************
*   Typedef
*******************************************************************************/
/*SWS_ComM_00649*/
#define COMM_E_MODE_LIMITATION 0x02 /*Function call has been successfully but mode can not be granted because of mode inhibition.*/

/*SWS_ComM_00668*/
typedef enum
{
    COMM_UNINIT = 0, /*The COM Manager is not initialized or not usable.*/
    COMM_INIT = 1    /*The COM Manager is initialized and usable.*/
} ComM_InitStatusType;

/*SWS_ComM_00669*/
typedef uint8 ComM_InhibitionStatusType;
#define COMM_WAKE_UP_INHIBITION_ACTIVE             (0x1)
#define COMM_LIMIT_TO_COMM_FULL_COMMUNICATION_MODE (0x2)

/*SWS_ComM_00670*/
typedef uint8 ComM_UserHandleType;
#define COMM_NOT_USED_USER_ID        ((ComM_UserHandleType)255)

#define COMM_FULL    0
#define COMM_LIGHT   1
#define COMM_NONE    2
#define COMM_PASSIVE 3

/*SWS_ComM_00672 SWS_ComM_00867 SWS_ComM_00879*/
typedef uint8 ComM_ModeType;
#define COMM_NO_COMMUNICATION     ((ComM_ModeType)0) /*ComM state machine is in "No Communication" mode. Configured channel shall have no transmission or reception capability.*/
#define COMM_SILENT_COMMUNICATION ((ComM_ModeType)1) /*ComM state machine is in "Silent Communication" mode. Configured channel shall have only reception capability, no transmission capability.*/
#define COMM_FULL_COMMUNICATION   ((ComM_ModeType)2) /*ComM state machine is in "Full Communication" mode. Configured channel shall have both transmission and reception capability.*/

/*SWS_ComM_00673*//*SWS_ComM_00907*/
typedef enum
{
    COMM_PNC_REQUESTED          = 0,     /*PNC is requested by a local ComM user*/
    COMM_PNC_READY_SLEEP        = 1,     /*PNC is requested by a remote ComM user*/
    COMM_PNC_PREPARE_SLEEP      = 2,     /*PNC is active with no deadline monitoring*/
    COMM_PNC_NO_COMMUNICATION   = 3      /*PNC does not communicate*/
} ComM_PncModeType;

/*SWS_ComM_00674 SWS_ComM_00051*/
typedef uint8 ComM_StateType;
#define COMM_NO_COM_NO_PENDING_REQUEST  ((ComM_StateType)0)
#define COMM_NO_COM_REQUEST_PENDING     ((ComM_StateType)1)
#define COMM_FULL_COM_NETWORK_REQUESTED ((ComM_StateType)2)
#define COMM_FULL_COM_READY_SLEEP       ((ComM_StateType)3)
#define COMM_SILENT_COM                 ((ComM_StateType)4)


typedef enum
{
    COMM_BUS_TYPE_CAN       = 0,
    COMM_BUS_TYPE_CDD       = 1,
    COMM_BUS_TYPE_ETH       = 2,
    COMM_BUS_TYPE_FR        = 3,
    COMM_BUS_TYPE_INTERNAL  = 4,
    COMM_BUS_TYPE_LIN       = 5
} ComM_BusType;

typedef enum
{
    COMM_GATEWAY_TYPE_ACTIVE   = 0,
    COMM_GATEWAY_TYPE_PASSIVE  = 1
} ComM_PncGatewayType;

typedef uint8 ComM_PncIdType;

/*SWS_ComM_00162*/
typedef struct
{
    boolean ComMPncEnabled;
} ComM_ConfigType;

typedef P2FUNC(Std_ReturnType, COMM_APPL_CODE, ComM_CddSMRequestComModeType)(NetworkHandleType, ComM_ModeType);
typedef P2FUNC(Std_ReturnType, COMM_APPL_CODE, ComM_CddSMGetCurrentComModeType)(NetworkHandleType, P2VAR(ComM_ModeType, AUTOMATIC, COMM_APPL_DATA));
typedef P2FUNC(Std_ReturnType, COMM_APPL_CODE, ComM_RteSwitchFctPtrType)(ComM_ModeType);

#endif/* COMM_TYPES_H  */

