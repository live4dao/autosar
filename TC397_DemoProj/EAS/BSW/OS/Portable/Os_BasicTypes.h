/*  BEGIN_FILE_HDR
********************************************************************************
*   NOTICE
*   This software is the property of HiRain Technologies. Any information
*   contained in this doc should not be reproduced, or used, or disclosed
*   without the written authorization from HiRain Technologies.
********************************************************************************
* File Name:       Os_BasicTypes.h
********************************************************************************
* Project/Product: AUTOSAR EAS
* Title:           Os_BasicTypes.h
* Author:          Hirain
********************************************************************************
* Description:     Definition of OS basic types. 
*                  These basic types need to be changed when hw or compiler changed
*
********************************************************************************
* Limitations     : None
*
********************************************************************************
*
********************************************************************************
*   Revision History:
*   Reference to Os_Cpu.c File
********************************************************************************
* END_FILE_HDR*/

#ifndef OS_BASIC_TYPES_H
#define OS_BASIC_TYPES_H
#include "Os_Pl_Cfg.h"
#include "Std_Types.h"
#include "Compiler.h"
/*****************************************************************************
* General QAC Suppression
******************************************************************************/
/*PRQA S 3453,3429 EOF*/
/*
The macros "OS_INLINE_FUNC" and "OS_LOCAL_INLINE" are not function-like macro.
*/

/*****************************************************************************
* Type define
******************************************************************************/

typedef unsigned char       Os_uint8;         /* 0 .. 255 */
typedef unsigned short      Os_uint16;        /* 0 .. 65535 */
typedef unsigned int        Os_uint32;        /* 0 .. 4294967295 */
typedef unsigned long long  Os_uint64;
typedef signed char			Os_sint8;
typedef signed short		Os_sint16;
typedef signed int          Os_sint32;
typedef signed long long  	Os_sint64;
typedef float				Os_float32;
typedef double              Os_float64;
typedef unsigned char       Os_boolean;       /* TRUE .. FALSE */

/* signed type and float type and 64bit type are not allowed to use in OS coce */


typedef Os_uint32  Os_AddrType;         /* hw Address type */


#define OS_NULL             ((void *)0)


#define OS_TRUE   ((Os_boolean) 1)
#define OS_FALSE  ((Os_boolean) 0)

#define OS_ON     (1)
#define OS_OFF    (0)

#if defined(OS_QAC)

#define OS_INLINE_FUNC(rettype, memclass)   inline rettype
#define OS_LOCAL_INLINE(rettype)   static inline rettype

#else

#define OS_INLINE_FUNC(rettype, memclass)   static inline __attribute__ ((always_inline))  rettype
#define OS_LOCAL_INLINE(rettype)   static __inline__ __attribute__((__always_inline__)) rettype

#endif

#endif


