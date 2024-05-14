/*  BEGIN_FILE_HDR
********************************************************************************
*   NOTICE
*   This software is the property of HiRain Technologies. Any information
*   contained in this doc should not be reproduced, or used, or disclosed
*   without the written authorization from HiRain Technologies.
********************************************************************************
*   File Name       : CanSM_BswM.h
********************************************************************************
*   Project/Product : AUTOSAR 4.2
*   Title           : CanSM module Header File
*   Author          : Hirain
********************************************************************************
*   Description     : CanSM module Header File
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
#ifndef CANSM_BSWM_H
#define CANSM_BSWM_H

/*******************************************************************************
*   API Declare SWS_CanSM_00347
*******************************************************************************/
/*SWS_CanSM_00598*/
typedef enum
{
    CANSM_BSWM_NO_COMMUNICATION       =      1,
    CANSM_BSWM_SILENT_COMMUNICATION   =      2,
    CANSM_BSWM_FULL_COMMUNICATION     =      3,
    CANSM_BSWM_BUS_OFF                =      4,
    CANSM_BSWM_CHANGE_BAUDRATE        =      5
} CanSM_BswMCurrentStateType;


#endif /*#ifndef CANSM_BSWM_H*/

