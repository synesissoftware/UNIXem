/* /////////////////////////////////////////////////////////////////////////
 * File:    unixem/asm/atomic.h
 *
 * Purpose: Declaration of Linux like atomic functions for the
 *          Windows platform.
 *
 * Created: 21st November 2003
 * Updated: 13th October 2026
 *
 * Home:    https://github.com/synesissoftware/UNIXem
 *
 * Copyright (c) 2019-2026, Matthew Wilson and Synesis Information Systems
 * Copyright (c) 2003-2019, Matthew Wilson and Synesis Software
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are
 * met:
 *
 * - Redistributions of source code must retain the above copyright notice,
 *   this list of conditions and the following disclaimer.
 * - Redistributions in binary form must reproduce the above copyright
 *   notice, this list of conditions and the following disclaimer in the
 *   documentation and/or other materials provided with the distribution.
 * - Neither the name(s) of Matthew Wilson and Synesis Software nor the
 *   names of any contributors may be used to endorse or promote products
 *   derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS
 * IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 * ////////////////////////////////////////////////////////////////////// */


#ifndef SYNSOFT_UNIXEM_INCL_UNIXEM_ASM_H_ATOMIC
#define SYNSOFT_UNIXEM_INCL_UNIXEM_ASM_H_ATOMIC

#ifndef UNIXEM_DOCUMENTATION_SKIP_SECTION
# define SYNSOFT_UNIXEM_VER_UNIXEM_ASM_H_ATOMIC_MAJOR       3
# define SYNSOFT_UNIXEM_VER_UNIXEM_ASM_H_ATOMIC_MINOR       0
# define SYNSOFT_UNIXEM_VER_UNIXEM_ASM_H_ATOMIC_REVISION    1
# define SYNSOFT_UNIXEM_VER_UNIXEM_ASM_H_ATOMIC_EDIT        24
#endif /* !UNIXEM_DOCUMENTATION_SKIP_SECTION */


/* /////////////////////////////////////////////////////////////////////////
 * compatibility
 */

#ifndef _WIN32
# error This file is only currently defined for compilation on Windows systems
#endif /* _WIN32 */


/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

#include <unixem/unixem.h>


/* /////////////////////////////////////////////////////////////////////////
 * types
 */

typedef signed long                                         unixem_atomic_t;


/* /////////////////////////////////////////////////////////////////////////
 * constants and definitions
 */

#define UNIXEM_ATOMIC_INIT(i)                               (i)


/* /////////////////////////////////////////////////////////////////////////
 * language
 */

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */


/* /////////////////////////////////////////////////////////////////////////
 * API functions
 */

void    unixem_atomic_set(unixem_atomic_t volatile* v, int i);
int     unixem_atomic_write(unixem_atomic_t volatile* v, int i);
int     unixem_atomic_read(unixem_atomic_t volatile* v);

void    unixem_atomic_add(int i, unixem_atomic_t volatile* v);
void    unixem_atomic_sub(int i, unixem_atomic_t volatile* v);

void    unixem_atomic_inc(unixem_atomic_t volatile* v);
void    unixem_atomic_dec(unixem_atomic_t volatile* v);

/** Returns the previous value */
int     unixem_atomic_inc_and_test(unixem_atomic_t volatile* v);
/** Returns the previous value */
int     unixem_atomic_dec_and_test(unixem_atomic_t volatile* v);

/** Returns the previous value */
int     unixem_atomic_add_and_test(int i, unixem_atomic_t volatile* v);
/** Returns the previous value */
int     unixem_atomic_sub_and_test(int i, unixem_atomic_t volatile* v);


/* /////////////////////////////////////////////////////////////////////////
 * language
 */

#ifdef __cplusplus
} /* extern "C" */
#endif /* __cplusplus */


/* /////////////////////////////////////////////////////////////////////////
 * inclusion control
 */

#ifdef STLSOFT_CF_PRAGMA_ONCE_SUPPORT
# pragma once
#endif /* STLSOFT_CF_PRAGMA_ONCE_SUPPORT */

#endif /* SYNSOFT_UNIXEM_INCL_UNIXEM_ASM_H_ATOMIC */

/* ///////////////////////////// end of file //////////////////////////// */

