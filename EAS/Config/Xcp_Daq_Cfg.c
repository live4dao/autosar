/*  BEGIN_FILE_HDR
********************************************************************************
*   File Name       : Xcp_Daq_Cfg.c
********************************************************************************
*   Project/Product : AUTOSAR BSW PROJECT
*   Title           : Xcp module configuration File
*   Author          : Hirain
********************************************************************************
*   Description     : Xcp module configuration File
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
*   Include files
*******************************************************************************/
#include "Xcp_Types.h"

#if(XCP_DAQ_SUPPORTED == STD_ON)
/*******************************************************************************
*   Config Data define
*******************************************************************************/
#define XCP_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h"

/* ODTs In Daq Daq0*/
STATIC Xcp_OdtEntry_Type Xcp_EntryInODT0[199];
STATIC Xcp_OdtEntry_Type Xcp_EntryInODT1[199];
STATIC Xcp_OdtEntry_Type Xcp_EntryInODT2[199];
STATIC Xcp_OdtEntry_Type Xcp_EntryInODT3[199];
STATIC Xcp_OdtEntry_Type Xcp_EntryInODT4[199];
STATIC Xcp_OdtEntry_Type Xcp_EntryInODT5[199];
STATIC Xcp_OdtEntry_Type Xcp_EntryInODT6[199];
STATIC Xcp_OdtEntry_Type Xcp_EntryInODT7[199];
STATIC Xcp_OdtEntry_Type Xcp_EntryInODT8[199];
STATIC Xcp_OdtEntry_Type Xcp_EntryInODT9[199];
STATIC Xcp_OdtEntry_Type Xcp_EntryInODT10[199];
STATIC Xcp_OdtEntry_Type Xcp_EntryInODT11[199];
STATIC Xcp_OdtEntry_Type Xcp_EntryInODT12[199];
STATIC Xcp_OdtEntry_Type Xcp_EntryInODT13[199];
STATIC Xcp_OdtEntry_Type Xcp_EntryInODT14[199];
STATIC Xcp_OdtEntry_Type Xcp_EntryInODT15[199];
STATIC Xcp_OdtEntry_Type Xcp_EntryInODT16[199];
STATIC Xcp_OdtEntry_Type Xcp_EntryInODT17[199];
STATIC Xcp_OdtEntry_Type Xcp_EntryInODT18[199];
STATIC Xcp_OdtEntry_Type Xcp_EntryInODT19[199];
STATIC Xcp_OdtEntry_Type Xcp_EntryInODT20[199];
STATIC Xcp_OdtEntry_Type Xcp_EntryInODT21[199];
STATIC Xcp_OdtEntry_Type Xcp_EntryInODT22[199];
STATIC Xcp_OdtEntry_Type Xcp_EntryInODT23[199];
STATIC Xcp_OdtEntry_Type Xcp_EntryInODT24[199];
STATIC Xcp_OdtEntry_Type Xcp_EntryInODT25[199];
STATIC Xcp_OdtEntry_Type Xcp_EntryInODT26[199];
STATIC Xcp_OdtEntry_Type Xcp_EntryInODT27[199];
STATIC Xcp_OdtEntry_Type Xcp_EntryInODT28[199];
STATIC Xcp_OdtEntry_Type Xcp_EntryInODT29[199];
STATIC Xcp_OdtEntry_Type Xcp_EntryInODT30[199];
STATIC Xcp_OdtEntry_Type Xcp_EntryInODT31[199];
STATIC Xcp_OdtEntry_Type Xcp_EntryInODT32[199];
STATIC Xcp_OdtEntry_Type Xcp_EntryInODT33[199];
STATIC Xcp_OdtEntry_Type Xcp_EntryInODT34[199];

#define XCP_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h"

#define XCP_START_SEC_CONFIG_DATA_8
#include "MemMap.h"

/*Event0*/
STATIC CONST(uint8, XCP_CONST) Xcp_EventName0[6] = {"Event0"};

#define XCP_STOP_SEC_CONFIG_DATA_8
#include "MemMap.h"


#define XCP_START_SEC_CONFIG_DATA_16
#include "MemMap.h"


/*Event0*/
STATIC CONST(uint16, XCP_CONST) Xcp_DaqInEvent0[1] =
{0};

#define XCP_STOP_SEC_CONFIG_DATA_16
#include "MemMap.h"


#define XCP_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "MemMap.h"

CONST(Xcp_Event_Config_Type, XCP_CONST) Xcp_EventConfig[XCP_MAX_EVENT_CHANNEL] =
{
    /*Event0*/
    {
        0x04, /* DAQ_Event_Properties */
        1, /* XcpEventChannelMaxDaqList */
        0, /* XcpEventChannelPriority */
        1, /* XcpEventTimeCycle */
        Xcp_DaqInEvent0, /* DAQ ref */
        6, /* name length */
        Xcp_EventName0, /* Name ref */
    }
};

/*Daq0*/
STATIC CONST(Xcp_ODT_Config_Type, XCP_CONST) Xcp_ODTInDAQ0[35] =
{
    /* XcpDtoPid, entry Ref */
    {0,Xcp_EntryInODT0},
    {1,Xcp_EntryInODT1},
    {2,Xcp_EntryInODT2},
    {3,Xcp_EntryInODT3},
    {4,Xcp_EntryInODT4},
    {5,Xcp_EntryInODT5},
    {6,Xcp_EntryInODT6},
    {7,Xcp_EntryInODT7},
    {8,Xcp_EntryInODT8},
    {9,Xcp_EntryInODT9},
    {10,Xcp_EntryInODT10},
    {11,Xcp_EntryInODT11},
    {12,Xcp_EntryInODT12},
    {13,Xcp_EntryInODT13},
    {14,Xcp_EntryInODT14},
    {15,Xcp_EntryInODT15},
    {16,Xcp_EntryInODT16},
    {17,Xcp_EntryInODT17},
    {18,Xcp_EntryInODT18},
    {19,Xcp_EntryInODT19},
    {20,Xcp_EntryInODT20},
    {21,Xcp_EntryInODT21},
    {22,Xcp_EntryInODT22},
    {23,Xcp_EntryInODT23},
    {24,Xcp_EntryInODT24},
    {25,Xcp_EntryInODT25},
    {26,Xcp_EntryInODT26},
    {27,Xcp_EntryInODT27},
    {28,Xcp_EntryInODT28},
    {29,Xcp_EntryInODT29},
    {30,Xcp_EntryInODT30},
    {31,Xcp_EntryInODT31},
    {32,Xcp_EntryInODT32},
    {33,Xcp_EntryInODT33},
    {34,Xcp_EntryInODT34}
};

CONST(Xcp_DAQ_Config_Type, XCP_CONST) Xcp_DAQConfig[XCP_MAX_DAQ] =
{
    /*Daq0*/
    {
        0, /* XcpRelateEvent */
        0x06, /* XcpDaqProperties 0x07 = fixevent, no stim, no predefine*/
        35, /* XcpMaxOdt */
        199, /* XcpMaxOdtEntries */
        Xcp_ODTInDAQ0, /* ODT Ref */
    }
};

#define XCP_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "MemMap.h"

#endif /* #if(XCP_DAQ_SUPPORTED == STD_ON) */

