
/*
 * Copyright (c) 2001, Swedish Institute of Computer Science.
 * All rights reserved. 
 *
 * Redistribution and use in source and binary forms, with or without 
 * modification, are permitted provided that the following conditions 
 * are met: 
 * 1. Redistributions of source code must retain the above copyright 
 *    notice, this list of conditions and the following disclaimer. 
 * 2. Redistributions in binary form must reproduce the above copyright 
 *    notice, this list of conditions and the following disclaimer in the 
 *    documentation and/or other materials provided with the distribution. 
 * 3. Neither the name of the Institute nor the names of its contributors 
 *    may be used to endorse or promote products derived from this software 
 *    without specific prior written permission. 
 *
 * THIS SOFTWARE IS PROVIDED BY THE INSTITUTE AND CONTRIBUTORS ``AS IS'' AND 
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE 
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE 
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE INSTITUTE OR CONTRIBUTORS BE LIABLE 
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL 
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS 
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) 
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT 
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY 
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF 
 * SUCH DAMAGE. 
 *
 * This file is part of the lwIP TCP/IP stack.
 * 
 * Author: Adam Dunkels <adam@sics.se>
 *
 */
#ifndef __ARCH_CC_H__
#define __ARCH_CC_H__

#include "Platform_Types.h"

#ifndef CPU_BYTE_ORDER
#error "we need know the byte endian of MCU."
#endif


//#define LWIP_PROVIDE_ERRNO

#if (CPU_BYTE_ORDER == LOW_BYTE_FIRST)
#define BYTE_ORDER          LITTLE_ENDIAN
#else
#define BYTE_ORDER          BIG_ENDIAN
#endif


#define ETH_HWADDR_LEN      6
#define _SIZE_T_DEF         1 //modified by Yibo: To adapt Tasking compiler
#define LWIP_NO_STDDEF_H    1
typedef unsigned long   size_t;
typedef signed   long   ptrdiff_t;

#define LWIP_NO_STDINT_H    1
typedef unsigned char   u8_t;
typedef signed   char   s8_t;
typedef unsigned short  u16_t;
typedef signed   short  s16_t;
typedef unsigned long   u32_t;
typedef signed   long   s32_t;
typedef unsigned long   mem_ptr_t;

#define LWIP_NO_LIMITS_H    1
#define LWIP_NO_INTTYPES_H  1
#define U16_F "u"
#define S16_F "d"
#define X16_F "x"
#define U32_F "lu"
#define S32_F "ld"
#define X32_F "lx"

#define PACK_STRUCT_FIELD(x) x
#define PACK_STRUCT_STRUCT
#define PACK_STRUCT_BEGIN
#define PACK_STRUCT_END


//#define LWIP_NOASSERT
#define LWIP_PLATFORM_DIAG(x)
#define LWIP_PLATFORM_ASSERT(x)

typedef u8_t sys_prot_t;
//#define SYS_ARCH_DECL_PROTECT(x)
//#define SYS_ARCH_PROTECT(x)
//#define SYS_ARCH_UNPROTECT(x)

#endif /* __ARCH_CC_H__ */
