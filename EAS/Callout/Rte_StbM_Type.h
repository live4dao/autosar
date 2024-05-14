/*  BEGIN_FILE_HDR
********************************************************************************
*   File Name       : Rte_StbM_Type.h
********************************************************************************
*   Project/Product : AUTOSAR BSW PROJECT
*   Title           : Rte module configuration File
*   Author          : Hirain
********************************************************************************
*   Description     : Rte module configuration File
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

#ifndef RTE_STBM_TYPE_H
#define RTE_STBM_TYPE_H
/*******************************************************************************
*   Includes
*******************************************************************************/
#include "Rte_Type.h"


typedef uint8 StbM_CustomerIdType;
/*SWS_StbM_00142*/
typedef uint16 StbM_SynchronizedTimeBaseType;
/*SWS_StbM_00239*/
typedef struct
{
    uint8 TIMEOUT           : 1; /*bit 0*/
    uint8 TIMELEAP          : 1; /*bit 1*/
    uint8 SYNC_TO_GATEWAY   : 1; /*bit 2*/
    uint8 GLOBAL_TIME_BASE  : 1; /*bit 3*/
    uint8 Reserved          : 4; /*bit 4~7*/
} StbM_TimeBaseStatusType;
/*SWS_StbM_00241*/
typedef struct
{
    StbM_TimeBaseStatusType timeBaseStatus;
    uint16 secondsHi;
    uint32 seconds;
    uint32 nanoseconds;
} StbM_TimeStampType;

/*SWS_StbM_00242*/
typedef struct
{
    StbM_TimeBaseStatusType timeBaseStatus;
    uint32 nanoseconds;
    uint64 seconds;
} StbM_TimeStampExtendedType;

/*SWS_StbM_00243*/
typedef struct
{
    uint8 userDataLength;
    uint8 userByte0;
    uint8 userByte1;
    uint8 userByte2;
} StbM_UserDataType;
#endif /* RTE_STBM_TYPE_H */

