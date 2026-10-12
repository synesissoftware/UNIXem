/* /////////////////////////////////////////////////////////////////////////
 * File:    sys/utsname.h
 *
 * Purpose: Declaration of the uname() API function and supporting
 *          types for the Windows platform.
 *
 * Created: 12th October 2026
 * Updated: 15th October 2026
 *
 * Home:    https://github.com/synesissoftware/UNIXem
 *
 * Copyright (c) 2026, Matthew Wilson and Synesis Information Systems
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * - Redistributions of source code must retain the above copyright notice, this
 *   list of conditions and the following disclaimer.
 * - Redistributions in binary form must reproduce the above copyright notice,
 *   this list of conditions and the following disclaimer in the documentation
 *   and/or other materials provided with the distribution.
 * - Neither the names of Matthew Wilson and Synesis Software nor the names of
 *   any contributors may be used to endorse or promote products derived from
 *   this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 * ////////////////////////////////////////////////////////////////////// */


/** \file sys/utsname.h
 *
 * Contains utsname functions and types.
 */

#ifndef SYNSOFT_UNIXEM_INCL_SYS_H_UTSNAME
#define SYNSOFT_UNIXEM_INCL_SYS_H_UTSNAME

#ifndef UNIXEM_DOCUMENTATION_SKIP_SECTION
# define SYNSOFT_UNIXEM_VER_SYS_H_UTSNAME_MAJOR     1
# define SYNSOFT_UNIXEM_VER_SYS_H_UTSNAME_MINOR     0
# define SYNSOFT_UNIXEM_VER_SYS_H_UTSNAME_REVISION  0
# define SYNSOFT_UNIXEM_VER_SYS_H_UTSNAME_EDIT      2
#endif /* !UNIXEM_DOCUMENTATION_SKIP_SECTION */


/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

#include <unixem/sys/utsname.h>

/* ////////////////////////////////////////////////////////////////////// */

/** \weakgroup unixem Synesis Software UNIX Emulation for Windows
 * \brief The UNIX emulation library
 */

/** \weakgroup unixem_utsname utsname API
 * \ingroup UNIXem unixem
 * \brief utsname functions and types
 * @{
 */

/* ////////////////////////////////////////////////////////////////////// */

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */


/** \def utsname
 *
 * Results structure for uname()
 *
 * \see unixem_utsname
 */
#define utsname                                             unixem_utsname

/** Get name and information about current kernel.
 *
 * Retrieves system identification information.
 *
 * \param name Pointer to an utsname structure to receive the utsname
 *  information.
 *
 * \note This is a macro, which resolves to unixem_uname()
 */
#ifdef UNIXEM_DOCUMENTATION_SKIP_SECTION
int uname(
    struct utsname* name
);
#else /* ? UNIXEM_DOCUMENTATION_SKIP_SECTION */
# define uname                                              unixem_uname
#endif /* UNIXEM_DOCUMENTATION_SKIP_SECTION */

#ifdef __cplusplus
} /* extern "C" */
#endif /* __cplusplus */


/* ////////////////////////////////////////////////////////////////////// */

/** @} // end of group unixem_utsname */

/* ////////////////////////////////////////////////////////////////////// */

#endif /* SYNSOFT_UNIXEM_INCL_SYS_H_UTSNAME */

/* ///////////////////////////// end of file //////////////////////////// */

