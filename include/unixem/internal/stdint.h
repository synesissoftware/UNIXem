/* /////////////////////////////////////////////////////////////////////////
 * File:    unixem/internal/stdint.h
 *
 * Purpose: Discrimination of integers.
 *
 * Created: 29th November 2024
 * Updated: 29th November 2024
 *
 * Home:    https://github.com/synesissoftware/UNIXem
 *
 * Copyright (c) 2024, Matthew Wilson and Synesis Information Systems
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


/** \file unixem/internal/stdint.h Discrimination of integers
 */

#ifndef UNIXEM_INCL_UNIXEM_internal_h_stdint
#define UNIXEM_INCL_UNIXEM_internal_h_stdint


/* /////////////////////////////////////////////////////////////////////////
 * version
 */

#ifndef UNIXEM_DOCUMENTATION_SKIP_SECTION
# define UNIXEM_VER_UNIXEM_internal_h_stdint_MAJOR      1
# define UNIXEM_VER_UNIXEM_internal_h_stdint_MINOR      0
# define UNIXEM_VER_UNIXEM_internal_h_stdint_REVISION   0
# define UNIXEM_VER_UNIXEM_internal_h_stdint_EDIT       1
#endif /* !UNIXEM_DOCUMENTATION_SKIP_SECTION */


/* /////////////////////////////////////////////////////////////////////////
 * includes - 1
 */

#include <unixem/unixem.h>

#include <stddef.h>


/* /////////////////////////////////////////////////////////////////////////
 * compatibility
 */

#if 0
#elif __STDC_VERSION__ >= 199901L

# define UNIXEM_HAS_h_stdint_
#elif 0 ||\
      (   defined(_MSC_VER) &&\
          _MSC_VER >= 1310) ||\
      0

# define UNIXEM_HAS_h_stdint_
#else

#endif


/* /////////////////////////////////////////////////////////////////////////
 * includes - 2
 */

#ifdef UNIXEM_HAS_h_stdint_
# include <stdint.h>
#endif


/* /////////////////////////////////////////////////////////////////////////
 * macros
 */



/* /////////////////////////////////////////////////////////////////////////
 * integer types
 */

#if 0
#elif defined(UNIXEM_HAS_h_stdint_)

typedef intptr_t                                            unixem_ssize_t;
#elif defined(_WIN64)

# if 0
# elif defined(__LP64__)

typedef signed long                                         unixem_ssize_t;
# elif defined(__LLP64__)

typedef signed long long                                    unixem_ssize_t;
# else

typedef signed __int64                                      unixem_ssize_t;
# endif
#else

typedef signed long                                         unixem_ssize_t;
#endif


/* /////////////////////////////////////////////////////////////////////////
 * function declarations
 */


/* ////////////////////////////////////////////////////////////////////// */

#endif /* UNIXEM_INCL_UNIXEM_internal_h_stdint */

/* ///////////////////////////// end of file //////////////////////////// */
