/*  BEGIN_FILE_HDR
********************************************************************************
*   File Name       : MemMap.h
********************************************************************************
*   Project/Product : AUTOSAR BSW PROJECT
*   Title           : MemMap module configuration File
*   Author          : Hirain
********************************************************************************
*   Description     : MemMap module configuration File
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
#if defined (START_WITH_IF)
/*******************************************************************************
*   MEM_OS_APPLICATION0_CORE0_CODE
*******************************************************************************/
#if defined (Mem_OS_Application0_Core0_START_SEC_CODE)
#undef Mem_OS_Application0_Core0_START_SEC_CODE
#pragma section all ="MemMapAddressingModeSet_Core0_Application0"
#elif defined (Mem_OS_Application0_Core0_STOP_SEC_CODE)
#undef Mem_OS_Application0_Core0_STOP_SEC_CODE 
#pragma section all restore
#endif

#endif /* START_WITH_IF */
