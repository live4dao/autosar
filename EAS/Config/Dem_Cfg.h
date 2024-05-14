/*  BEGIN_FILE_HDR
********************************************************************************
*   File Name       : Dem_Cfg.h
********************************************************************************
*   Project/Product : AUTOSAR BSW PROJECT
*   Title           : Dem module configuration File
*   Author          : Hirain
********************************************************************************
*   Description     : Dem module configuration File
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
*   V1.0.2_3.5.5_AZ240046       09/05/2024    Eas           N/A          N/A
*
********************************************************************************
* END_FILE_HDR*/
#ifndef DEM_CFG_H
#define DEM_CFG_H


/*******************************************************************************
*   Dem Container:DemGeneral
*******************************************************************************/
#define DEM_CONFIG_VARIANTS                                 STD_CONFIG_VARIANTS_PRECOMPILE

#define DEM_PRIVATE_VERSION_CHECK                           STD_ON
/* generate tool's version*/
#define DEM_SW_MAJOR_VERSION_CFG                            1
#define DEM_SW_MINOR_VERSION_CFG                            2
#define DEM_SW_PATCH_VERSION_CFG                            3
#define DEM_AR_RELEASE_MAJOR_VERSION_CFG                    4
#define DEM_AR_RELEASE_MINOR_VERSION_CFG                    2
#define DEM_AR_RELEASE_REVISION_VERSION_CFG                 2

#define DEM_CMA_PLATFORM_ENABLED                            STD_OFF

#define DEM_NVM_SUPPORT                                     STD_ON
#define DEM_FIM_SUPPORT                                     STD_ON
/*DemAgingCycleCounterProcessing*/
#define DEM_CFG_AGINGCYCLECOUNTERPROCESSING                 DEM_PROCESS_AGINGCTR_INTERN
/*DemAgingRequiresTestedCycle*/
#define DEM_CFG_AGINGREQUIRESTESTEDCYCLE                    STD_ON
/*DemAvailabilitySupport*/
#define DEM_CFG_AVAILABILITYSUPPORT                         DEM_NO_AVAILABILITY
/*DemBswErrorBufferSize*/
#define DEM_CFG_BSWERRORBUFFERSIZE                          8
/*DemClearDTCBehavior*/
#define DEM_CFG_CLEARDTCBEHAIOR                             DEM_CLRRESP_VOLATILE
/*DemClearDTCLimitation*/
#define DEM_CFG_CLEARDTCLIMITATION                          DEM_ALL_SUPPORTED_DTCS
/*DemDataElementDefaultEndianness*/
#define DEM_CFG_DATAELEMENTDEFAULTENDIANNESS                DEM_OPAQUE
/*DemDebounceCounterBasedSupport*/ /*SWS_Dem_00526*/
#define DEM_CFG_DEBOUNCECOUNTERBASEDSUPPORT                 STD_ON
/*DemDebounceTimeBasedSupport*//*SWS_Dem_00527*/
#define DEM_CFG_DEBOUNCETIMEBASEDSUPPORT                    STD_ON
#define DEM_CFG_MAXNUMBEREVENTENTRY_MIRROR                  0
/*DemDevErrorDetect*/
#define DEM_DEV_ERROR_DETECT                                STD_OFF
/*DemDtcStatusAvailabilityMask*/
#define DEM_CFG_DTCSTATUSAVAILABILITYMASK                   ((uint8)0xFF)
/*DemEnvironmentDataCapture*/
#define DEM_CFG_ENVIRONMENTDATACAPTURE                      DEM_CAPTURE_ASYNCHRONOUS_TO_REPORTING
/*DemEventCombinationSupport*/
#define DEM_CFG_EVENTCOMBINATIONSUPPORT                     DEM_EVCOMB_DISABLED
/*DemEventDisplacementStrategy*/
#define DEM_CFG_EVENTDISPLACEMENTSTRATEGY                   DEM_DISPLACEMENT_NONE
/*DemEventMemoryEntryStorageTrigger*/
#define DEM_CFG_EVENTMEMORYENTRYSTORAGETRIGGER              DEM_TRIGGER_ON_PENDING
/*DemGeneralInterfaceSupport*/
#define DEM_CFG_GENERALINTERFACESUPPORT                     STD_OFF
/*DemImmediateNvStorageLimit*/
#define DEM_CFG_IMMEDIATENVMSTORAGELIMIT                    1
/*DemMILIndicatorRef*/
#define DEM_CFG_MILINDICATORREF                             0xFF
/*DemMaxNumberEventEntryEventBuffer*/
#define DEM_CFG_MAXNUMBEREVENTENTRY_ENENTBUFFER             1
/*DemMaxNumberEventEntryPermanent*/
#define DEM_CFG_MAXNUMBEREVENTENTRY_PERMANENT               0
/*DemMaxNumberPrestoredFF*/
#define DEM_CFG_MAXNUMBER_PRESTOREDFF                       0
/*DemMaxNumberEventEntryPrimary*/
#define DEM_CFG_MAXNUMBEREVENTENTRY_PRIMARY                 121
/*DemOBDSupport*/
#define DEM_CFG_OBD_SUPPORT                                 DEM_OBD_NO_OBD_SUPPORT
/*DemJ1939Support*/
#define DEM_J1939_SUPPORT                                   STD_OFF
/*DemOccurrenceCounterProcessing*/
#define DEM_CFG_OCCURRENCECOUNTERPROCESSING                 DEM_PROCESS_OCCCTR_TF
/*DemOperationCycleStatusStorage*/
#define DEM_CFG_OPERATIONCYCLESTATUSSTORAGE                 STD_OFF
/*DemPTOSupport*/
#define DEM_CFG_PTO_SUPPORT                                 STD_OFF
/*DemResetConfirmedBitOnOverflow*/
#define DEM_CFG_RESETCONFIRMEDBITONOVERFLOW                 STD_ON
/*DemStatusBitHandlingTestFailedSinceLastClear*/
#define DEM_CFG_STATUSBITHANDLING_TFSLC                     DEM_STATUS_BIT_AGING_AND_DISPLACEMENT
/*DemStatusBitStorageTestFailed*/
#define DEM_CFG_STATUSBITSTORAGE_TF                         STD_OFF
/*DemSuppressionSupport*/
#define DEM_CFG_SUPPRESSIONSUPPORT                          DEM_NO_SUPPRESSION
/*DemTaskTime*/
#define DEM_TASK_TIME                                       5
/*DemTriggerDcmReports*/
#define DEM_CFG_TRIGGER_DCM_REPORTS                         STD_OFF
/*DemTriggerDltReports*/
#define DEM_CFG_TRIGGER_DLT_REPORTS                         STD_OFF
/*DemTriggerFiMReports*/
#define DEM_CFG_TRIGGER_FIM_REPORTS                         STD_ON
/*DemTriggerMonitorInitBeforeClearOk*/
#define DEM_CFG_TRIGGERMONITORINITBEFORECLEAROK             STD_OFF
/*DemTypeOfDTCSupported*/
#define DEM_CFG_TYPE_OF_DTC_SUPPORTED                       DEM_DTC_TRANSLATION_ISO14229_1
/*DemTypeOfFreezeFrameRecordNumeration*/
#define DEM_CFG_TYPE_OF_FF_RECORD_NUMERATION                DEM_FF_RECNUM_CONFIGURED
/*DemVersionInfoApi*/
#define DEM_VERSION_INFO_API                                STD_ON


/*******************************************************************************
*   Dem Container:DemGeneralOBD ECUC_Dem_00756
*******************************************************************************/
#define DEM_NUM_OF_INDICATOR                                0
#define DEM_NUM_OF_BYTE_RECORD_INDICATOR_STATE              0

/*******************************************************************************
*   Dem Container:DemGeneralJ1939
*******************************************************************************/
/*ECUC_Dem_00821 DemAmberWarningLampIndicatorRef*/
#define DEM_CFG_AMBER_LAMP_REF                              0xFF
/*ECUC_Dem_00822 DemProtectLampIndicatorRef*/
#define DEM_CFG_PROTECT_LAMP_REF                            0xFF
/*ECUC_Dem_00820 DemRedStopLampIndicatorRef*/
#define DEM_CFG_RED_LAMP_REF                                0xFF
/*ECUC_Dem_00872 DemJ1939ClearDtcSupport*/
#define DEM_CFG_J1939CLEAR_DTC_SUPPORT                      STD_OFF
/*ECUC_Dem_00868 DemJ1939Dm31Support*/
#define DEM_CFG_J1939DM31_SUPPORT                           STD_OFF
/*ECUC_Dem_00873 DemJ1939ExpandedFreezeFrameSupport*/
#define DEM_CFG_J1939EX_FF_SUPPORT                          STD_OFF
/*ECUC_Dem_00866 DemJ1939FreezeFrameSupport*/
#define DEM_CFG_J1939_FF_SUPPORT                            STD_OFF
/*ECUC_Dem_00867 DemJ1939RatioSupport*/
#define DEM_CFG_J1939_RATIO_SUPPORT                         STD_OFF
/*ECUC_Dem_00869 DemJ1939Readiness1Support*/
#define DEM_CFG_J1939READINESS_1_SUPPORT                    STD_OFF
/*ECUC_Dem_00870 DemJ1939Readiness2Support*/
#define DEM_CFG_J1939READINESS_2_SUPPORT                    STD_OFF
/*ECUC_Dem_00871 DemJ1939Readiness3Support*/
#define DEM_CFG_J1939READINESS_3_SUPPORT                    STD_OFF
/*ECUC_Dem_00865 DemJ1939ReadingDtcSupport*/
#define DEM_CFG_J1939READING_DTC_SUPPORT                    STD_OFF

/*******************************************************************************
*   DemGeneral Macros
*******************************************************************************/
#define DEM_NUM_OF_OPCYCLE                                  1
#define DEM_NUM_OF_EN_CONDITION                             5
#define DEM_NUM_OF_EN_GROUP                                 2
#define DEM_NUM_OF_STOR_CONDITION                           0
#define DEM_NUM_OF_STOR_GROUP                               0
#define DEM_NUM_OF_BLOCKID                                  1
#define DEM_NUM_OF_DTCGROUP                                 1
#define DEM_NUM_OF_DID                                      5
#define DEM_NUM_OF_DATA                                     9
#define DEM_NUM_OF_EXTDATACLASS                             1
#define DEM_NUM_OF_EXTDATAREC                               4
#define DEM_NUM_OF_FFRECCLASS                               2
#define DEM_NUM_OF_FFRECNUM                                 1

#define DEM_MAXNUM_CAPTURE_DATA_PER_MAINCYCLE               4


/*******************************************************************************
*   DemConfigSet Macros
*******************************************************************************/

#define Dem_Event_0x940009                                  0
#define Dem_Event_0x94001C                                  1
#define Dem_Event_0x94001D                                  2
#define Dem_Event_0x940054                                  3
#define Dem_Event_0x940056                                  4
#define Dem_Event_0x940089                                  5
#define Dem_Event_0x940091                                  6
#define Dem_Event_0x9400A2                                  7
#define Dem_Event_0x9400A3                                  8
#define Dem_Event_0x940109                                  9
#define Dem_Event_0x94011C                                  10
#define Dem_Event_0x94011D                                  11
#define Dem_Event_0x940189                                  12
#define Dem_Event_0x9401A3                                  13
#define Dem_Event_0x94021C                                  14
#define Dem_Event_0x940254                                  15
#define Dem_Event_0x940306                                  16
#define Dem_Event_0x94031C                                  17
#define Dem_Event_0x940354                                  18
#define Dem_Event_0x940406                                  19
#define Dem_Event_0x94041C                                  20
#define Dem_Event_0x940498                                  21
#define Dem_Event_0x9404A2                                  22
#define Dem_Event_0x940504                                  23
#define Dem_Event_0x940506                                  24
#define Dem_Event_0x94051C                                  25
#define Dem_Event_0x940604                                  26
#define Dem_Event_0x940606                                  27
#define Dem_Event_0x94061C                                  28
#define Dem_Event_0x940704                                  29
#define Dem_Event_0x940706                                  30
#define Dem_Event_0x940709                                  31
#define Dem_Event_0x940754                                  32
#define Dem_Event_0x940804                                  33
#define Dem_Event_0x940854                                  34
#define Dem_Event_0x940904                                  35
#define Dem_Event_0x940A04                                  36
#define Dem_Event_0x940B04                                  37
#define Dem_Event_0x942009                                  38
#define Dem_Event_0x942209                                  39
#define Dem_Event_0x942309                                  40
#define Dem_Event_0x942409                                  41
#define Dem_Event_0x942509                                  42
#define Dem_Event_0x942609                                  43
#define Dem_Event_0x942D09                                  44
#define Dem_Event_0x942F09                                  45
#define Dem_Event_0x943009                                  46
#define Dem_Event_0xD20008                                  47
#define Dem_Event_0xD20086                                  48
#define Dem_Event_0xD20087                                  49
#define Dem_Event_0xD20108                                  50
#define Dem_Event_0xD20186                                  51
#define Dem_Event_0xD20187                                  52
#define Dem_Event_0xD20208                                  53
#define Dem_Event_0xD20286                                  54
#define Dem_Event_0xD20287                                  55
#define Dem_Event_0xD20288                                  56
#define Dem_Event_0xD20308                                  57
#define Dem_Event_0xD20386                                  58
#define Dem_Event_0xD20387                                  59
#define Dem_Event_0xD20388                                  60
#define Dem_Event_0xD20408                                  61
#define Dem_Event_0xD20486                                  62
#define Dem_Event_0xD20508                                  63
#define Dem_Event_0xD20586                                  64
#define Dem_Event_0xD20608                                  65
#define Dem_Event_0xD20686                                  66
#define Dem_Event_0xD20708                                  67
#define Dem_Event_0xD20786                                  68
#define Dem_Event_0xD20808                                  69
#define Dem_Event_0xD20886                                  70
#define Dem_Event_0xD20908                                  71
#define Dem_Event_0xD20986                                  72
#define Dem_Event_0xD20A08                                  73
#define Dem_Event_0xD20A86                                  74
#define Dem_Event_0xD20B08                                  75
#define Dem_Event_0xD20B86                                  76
#define Dem_Event_0xD20C08                                  77
#define Dem_Event_0xD20C86                                  78
#define Dem_Event_0xD20D08                                  79
#define Dem_Event_0xD20D86                                  80
#define Dem_Event_0xD20E08                                  81
#define Dem_Event_0xD20E86                                  82
#define Dem_Event_0xD20F08                                  83
#define Dem_Event_0xD20F86                                  84
#define Dem_Event_0xD21008                                  85
#define Dem_Event_0xD21087                                  86
#define Dem_Event_0xD21208                                  87
#define Dem_Event_0xD21287                                  88
#define Dem_Event_0xD21308                                  89
#define Dem_Event_0xD21387                                  90
#define Dem_Event_0xD21408                                  91
#define Dem_Event_0xD21441                                  92
#define Dem_Event_0xD21487                                  93
#define Dem_Event_0xD21508                                  94
#define Dem_Event_0xD21541                                  95
#define Dem_Event_0xD21608                                  96
#define Dem_Event_0xD21708                                  97
#define Dem_Event_0xD22086                                  98
#define Dem_Event_0xD22186                                  99
#define Dem_Event_0xD22286                                  100
#define Dem_Event_0xD22386                                  101
#define Dem_Event_0xD22486                                  102
#define Dem_Event_0xD22586                                  103
#define Dem_Event_0xD22686                                  104
#define Dem_Event_0xD22786                                  105
#define Dem_Event_0xD22787                                  106
#define Dem_Event_0xD22887                                  107
#define Dem_Event_0xD22987                                  108
#define Dem_Event_0xD23087                                  109
#define Dem_Event_0xD23187                                  110
#define Dem_Event_0xD23287                                  111
#define Dem_Event_0xD23387                                  112
#define Dem_Event_0xD23487                                  113
#define Dem_Event_0xD23587                                  114
#define Dem_Event_0xD23687                                  115


#define Dem_OpCycle_DemOperationCycle                       0


#define Dem_EnableCond_IGN_ON                               0
#define Dem_EnableCond_After_5s                             1
#define Dem_EnableCond_Power_Normal                         2
#define Dem_EnableCond_CAN0_NoBusOff                        3
#define Dem_EnableCond_CAN1_NoBusOff                        4

#define DEM_NUM_OF_EVENT                                    116
#define DEM_NUM_OF_DTC                                      116
#define DEM_NUM_OF_DTCATB                                   3
#define DEM_NUM_OF_COUNTER_BASED                            2
#define DEM_NUM_OF_TIME_BASED                               2
#define DEM_MAX_FFSIZE_OF_DTC                               46
#define DEM_MAX_EXTSIZE_OF_DTC                              8
#define DEM_MAX_J1939FFSIZE_OF_DTC                          0
#define DEM_MAX_J1939EXPFFSIZE_OF_DTC                       0

#define Dem_WriteBlock(BlockId,DataPtr)                     NvM_WriteBlock(BlockId,(uint8*)DataPtr)
#define Dem_SetRamBlockStatus(BlockId,Changed)              NvM_SetRamBlockStatus(BlockId,Changed)
#define Dem_GetErrorStatus(BlockId,ResultPtr)               NvM_GetErrorStatus(BlockId,ResultPtr)

#endif /* DEM_CFG_H */



