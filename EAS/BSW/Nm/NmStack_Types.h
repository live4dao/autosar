/*  BEGIN_FILE_HDR
********************************************************************************
*   NOTICE
*   This software is the property of HiRain Technologies. Any information
*   contained in this doc should not be reproduced, or used, or disclosed
*   without the written authorization from HiRain Technologies.
********************************************************************************
*   File Name       : NmStack_Types.h
********************************************************************************
*   Project/Product : AUTOSAR 4.2
*   Title           : NmStack_Types.h
*   Author          : Hirain
********************************************************************************
*   Description     : The header file contains the  common type definitions of NM
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
#ifndef NM_STACK_TYPES_H
#define NM_STACK_TYPES_H

/*******************************************************************************
*   Includes
*******************************************************************************/
#include "Nm_Cfg.h"
#if(STD_ON == NM_STATE_CHANGE_IND_ENABLED)
#include "Com_Types.h"
#endif


/* Return values for NM functions */
#define NM_E_OK            ((uint8)E_OK)      /* Function call has been successfully accomplished and
                                                  returned */
#define NM_E_NOT_OK        ((uint8)E_NOT_OK)  /* Function call has been unsuccessfully accomplished and
                                                 returned because of an internal execution error.  */
#define NM_E_NOT_EXECUTED  ((uint8)2u)        /* Function call has been successfully accomplished and
                                                 returned since execution of a service in the current 
                                                 state is not allowed. */

/*******************************************************************************
*  GLOBAL FUNCTION MACROS
*******************************************************************************/

/*******************************************************************************
*  GLOBAL DATA TYPES AND STRUCTURES
*******************************************************************************/

/* Modes of the network management state machine */
/*SWS_Nm_00274*/
typedef enum
{
    NM_MODE_BUS_SLEEP           = 0,   /* Bus-Sleep Mode */
    NM_MODE_PREPARE_BUS_SLEEP   = 1,   /* Prepare Bus-Sleep Mode */
    NM_MODE_SYNCHRONIZE         = 2,   /* Synchronized Mode */
    NM_MODE_NETWORK             = 3    /* Network Mode */
} Nm_ModeType;

/* State of the Nm state machine */
/*SWS_Nm_00275*/
typedef enum
{
    NM_STATE_UNINIT                 = 0,   /* Uninitialized State */
    NM_STATE_BUS_SLEEP              = 1,   /* Bus-Sleep State */
    NM_STATE_PREPARE_BUS_SLEEP      = 2,   /* Prepare Bus-Sleep State */
    NM_STATE_READY_SLEEP            = 3,   /* Ready Sleep State */
    NM_STATE_NORMAL_OPERATION       = 4,   /* Normal Operation State */
    NM_STATE_REPEAT_MESSAGE         = 5,   /* Repeat Message State */
    NM_STATE_SYNCHRONIZE            = 6,   /* Synchronized State */
    NM_STATE_OFFLINE                = 7,   /* Wait Check Activation */
    NM_STATE_WAIT_NETWORK_STARTUP   = 8    /* Wait Network Startup */
} Nm_StateType;


/*SWS_Nm_00276*/
typedef enum
{
    NM_BUSNM_CANNM              = 0,   /*CAN NM type*/
    NM_BUSNM_FRNM               = 1,   /*FR NM type*/
    NM_BUSNM_LINNM              = 2,   /*LIN NM type*/
    NM_BUSNM_UDPNM              = 3,   /*UDP NM type*/
    NM_BUSNM_GENERICNM          = 4,   /*Generic NM type*/
    NM_BUSNM_J1939NM            = 5,   /*SAE J1939 NM type*/
    NM_BUSNM_OSEKNM             = 6,   /*OSEK NM type*/
    NM_BUSNM_UNDEF              = 0xff  /*NM type undefined*/
} Nm_BusNmType;

#define NM_RM_BSM   (0x01) /*NM in state RepeatMessage (transition from BusSleepMode)*/
#define NM_RM_PBSM  (0x02) /*NM in state RepeatMessage (transition from PrepareBusSleepMode)*/
#define NM_NO_RM    (0x04) /*NM in state NormalOperation (transition from RepeatMessage)*/
#define NM_NO_RS    (0x08) /*NM in state NormalOperation (transition from ReadySleep)*/
#define NM_RM_RS    (0x10) /*NM in state RepeatMessage (transition from ReadySleep)*/
#define NM_RM_NO    (0x20) /*NM in state RepeatMessage (transition from NormalOperation)*/


/*Nm197_Conf*/
typedef struct
{
#if(STD_CONFIG_VARIANTS_PRECOMPILE == NM_CONFIG_VARIANTS)
    Nm_BusNmType  NmBusType;
    NetworkHandleType NmComMChannelId;    /*Nm217_Conf*/
    NetworkHandleType NmBusNmChannelId;
    boolean       NmChannelSleepMaster;   /*Nm227_Conf*/
    uint8         NmCoordClusterIndex;    /*Nm221_Conf*/
    uint16        NmShutdownDelayTimer;   /*Nm222_Conf*/
    boolean       NmSynchronizingNetwork; /*Nm223_Conf*/
#endif
#if(STD_ON == NM_COORDINATOR_SUPPORT)
    boolean       NmActiveCoordinator;    /*Nm236_Conf*/
#endif
#if(NM_PASSIVEMODE == NM_PASSIVEMODE_VARIES)
    boolean       NmPassiveModeEnabled;   /*Nm209_Conf*/
#endif
#if(STD_ON == NM_STATE_CHANGE_IND_ENABLED)
    boolean       NmStateReportEnabled;   /*Nm231_Conf*/
    Com_SignalIdType NmStateReportSignal; /*Nm232_Conf*/
#endif
} Nm_ChannelConfigType;

#if(STD_CONFIG_VARIANTS_LINKTIME == NM_CONFIG_VARIANTS)
typedef struct
{
    Nm_BusNmType  NmBusType;
    NetworkHandleType NmComMChannelId;    /*Nm217_Conf*/
    NetworkHandleType NmBusNmChannelId;
    boolean       NmChannelSleepMaster;   /*Nm227_Conf*/
    uint8         NmCoordClusterIndex;    /*Nm221_Conf*/
    uint16        NmShutdownDelayTimer;   /*Nm222_Conf*/
    boolean       NmSynchronizingNetwork; /*Nm223_Conf*/
} Nm_ChannelLCfgType;
#endif

#endif  /* _NM_STACK_TYPES_H_ */

