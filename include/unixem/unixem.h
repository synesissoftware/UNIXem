/* /////////////////////////////////////////////////////////////////////////
 * File:    unixem/unixem.h
 *
 * Purpose: Version header for the UNIXem API.
 *
 * Created: 29th August 2005
 * Updated: 18th May 2025
 *
 * Home:    https://github.com/synesissoftware/UNIXem
 *
 * Copyright (c) 2019-2025, Matthew Wilson and Synesis Information Systems
 * Copyright (c) 2005-2019, Matthew Wilson and Synesis Software
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
 * - Neither the name(s) of Matthew Wilson and Synesis Information Systems
 *   nor the names of any contributors may be used to endorse or promote
 *   products derived from this software without specific prior written
 *   permission.
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


/** \file unixem/unixem.h Version header for the UNIXem API
 */

#ifndef UNIXEM_INCL_UNIXEM_H_UNIXEM
#define UNIXEM_INCL_UNIXEM_H_UNIXEM


/* /////////////////////////////////////////////////////////////////////////
 * version
 */

#ifndef UNIXEM_DOCUMENTATION_SKIP_SECTION
# define UNIXEM_VER_UNIXEM_H_UNIXEM_MAJOR       1
# define UNIXEM_VER_UNIXEM_H_UNIXEM_MINOR       7
# define UNIXEM_VER_UNIXEM_H_UNIXEM_REVISION    7
# define UNIXEM_VER_UNIXEM_H_UNIXEM_EDIT        31
#endif /* !UNIXEM_DOCUMENTATION_SKIP_SECTION */

/** \def UNIXEM_VER_MAJOR
 * The major version number of UNIXem
 */

/** \def UNIXEM_VER_MINOR
 * The minor version number of UNIXem
 */

/** \def UNIXEM_VER_PATCH
 * The patch (aka revision) version number of UNIXem
 */

/** \def UNIXEM_VER
 * The current composite version number of UNIXem
 */

#define UNIXEM_VER_MAJOR        1
#define UNIXEM_VER_MINOR        13
#define UNIXEM_VER_PATCH        0
#define UNIXEM_VER_ALPHABETA    0x41

#define UNIXEM_VER \
    (0\
        |   (   UNIXEM_VER_MAJOR       << 24   ) \
        |   (   UNIXEM_VER_MINOR       << 16   ) \
        |   (   UNIXEM_VER_PATCH       <<  8   ) \
        |   (   UNIXEM_VER_ALPHABETA   <<  0   ) \
    )

#define UNIXEM_VER_REVISION     UNIXEM_VER_PATCH


/* ////////////////////////////////////////////////////////////////////// */

#endif /* UNIXEM_INCL_UNIXEM_H_UNIXEM */

/* ///////////////////////////// end of file //////////////////////////// */

