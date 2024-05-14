/*  BEGIN_FILE_HDR
********************************************************************************
*   File Name       : EcuM_Generated_Types.h
********************************************************************************
*   Project/Product : AUTOSAR BSW PROJECT
*   Title           : EcuM module configuration File
*   Author          : Hirain
********************************************************************************
*   Description     : EcuM module configuration File
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
#ifndef ECUM_GENERATED_TYPES_H
#define ECUM_GENERATED_TYPES_H

/*******************************************************************************
*   Includes
*******************************************************************************/

#include "Mcu.h"
#include "BswM_Types.h"
#include "ComStack_Types.h"
#include "Os.h"


/*******************************************************************************
*   Global Data Declaration
*******************************************************************************/

typedef uint8 EcuM_UserType;                                /*SWS_EcuM_04067*/
#define ECUM_USER_NUMBER                                    (1)
#define ECUM_USER0                                          (0)

typedef uint8 EcuM_ResetType;                               /*SWS_EcuM_04044*/
#define ECUM_RESET_NUMBER                                   (3)
/*The pre-defined reset target*/
#define ECUM_RESET_MCU                                      (0)
#define ECUM_RESET_WDG                                      (1)
#define ECUM_RESET_IO                                       (2)

typedef uint8 EcuM_ShutdownCauseType;                       /*SWS_EcuM_04045*/
typedef uint32 EcuM_TimeType;                               /*SWS_EcuM_04102*/
#define ECUM_CAUSE_NUMBER                                   (4)
/*The pre-defined shutdown cause*/
#define ECUM_CAUSE_UNKNOWN                                  ((EcuM_ShutdownCauseType)0)
#define ECUM_CAUSE_ECU_STATE                                ((EcuM_ShutdownCauseType)1)
#define ECUM_CAUSE_WDGM                                     ((EcuM_ShutdownCauseType)2)
#define ECUM_CAUSE_DCM                                      ((EcuM_ShutdownCauseType)3)

typedef uint32 EcuM_WakeupSourceType;                       /*SWS_EcuM_04040*/
#define ECUM_WKSOURCE_NUMBER                                (5)
#define ECUM_WKSOURCE_VALID_MASK                            ((EcuM_WakeupSourceType)0x0000001F)
#define ECUM_WKSOURCE_INVALID_MASK                          ((EcuM_WakeupSourceType)0xFFFFFFE0)
/*The pre-defined wakeup sources*/
#define ECUM_WKSOURCE_POWER                                 ((EcuM_WakeupSourceType)0x00000001)
#define ECUM_WKSOURCE_RESET                                 ((EcuM_WakeupSourceType)0x00000002)
#define ECUM_WKSOURCE_INTERNAL_RESET                        ((EcuM_WakeupSourceType)0x00000004)
#define ECUM_WKSOURCE_INTERNAL_WDG                          ((EcuM_WakeupSourceType)0x00000008)
#define ECUM_WKSOURCE_EXTERNAL_WDG                          ((EcuM_WakeupSourceType)0x00000010)


#define ECUM_IS_WAKEUPSOURCE(src,mask)                      (((src) & (mask)) > (EcuM_WakeupSourceType)0)
#define ECUM_MAKE_WAKEUPSOURCE(id)                          ((uint32)(0x01) << (id))

/*SWS_EcuM_04136*/
typedef uint8 EcuM_ShutdownTargetType;
#define ECUM_SHUTDOWN_TARGET_SLEEP                          ((uint8)0x0)
#define ECUM_SHUTDOWN_TARGET_RESET                          ((uint8)0x1)
#define ECUM_SHUTDOWN_TARGET_OFF                            ((uint8)0x2)

/*SWS_EcuM_04101*/
typedef uint16 EcuM_ShutdownModeType;

typedef struct
{
    boolean Polling;
} EcuM_WakeupSourceConfigType;

typedef struct
{
    /*Module Configuration set*/
    P2CONST(BswM_ConfigType, AUTOMATIC, AUTOMATIC) BswMConfigPtr;

} EcuM_FlexModuleConfigType;

typedef struct
{
    TaskType TaskId;
    EventMaskType ShutdownEventMask;
    EventMaskType SleepEventMask;
} EcuM_CoreShutdownInfoType;

#endif /* ECUM_GENERATED_TYPES_H */



