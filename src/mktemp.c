/* /////////////////////////////////////////////////////////////////////////
 * File:    mktemp.c
 *
 * Purpose: mkstemp()/mkdtemp() etc. for the Windows platform.
 *
 * Created: 4th October 2015
 * Updated: 14th October 2019
 *
 * Home:    http://synesis.com.au/software/
 *
 * Copyright (c) 2015-2019, Matthew Wilson and Synesis Software
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


#ifndef UNIXEM_DOCUMENTATION_SKIP_SECTION
# define _SYNSOFT_VER_C_MKTEMP_MAJOR        1
# define _SYNSOFT_VER_C_MKTEMP_MINOR        0
# define _SYNSOFT_VER_C_MKTEMP_REVISION     4
# define _SYNSOFT_VER_C_MKTEMP_EDIT         5
#endif /* !UNIXEM_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

/* If we're going to include 'windows.h', then it has to be included first, so
 * as to put off the defintion of timeval in sys/time.h. Regrettably, the
 * WinSock header defines it without any conception of sys/time.h. Thanks MS!
 */
#ifndef __MWERKS__
# include <windows.h>
#endif /* !__MWERKS__ */

#include <unixem/unistd.h>

#include <unixem/internal/safestr.h>

#include <assert.h>
#include <direct.h>
#include <errno.h>
#include <fcntl.h>
#include <io.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>

#if defined(UNIXEM_USING_SAFE_STR_FUNCTIONS)
# include <share.h>
#endif

/* /////////////////////////////////////////////////////////////////////////
 * internal helper functions
 */

/* /////////////////////////////////////////////////////////////////////////
 * helper functions
 */

/* /////////////////////////////////////////////////////////////////////////
 * API functions
 */

int
unixem_mkstemp(
    char*   template_path
)
{
    size_t      len;
    unsigned    n;
    unsigned    nX;
    char*       pX;
    char        fmt[21];
    unsigned    limit;
    unsigned    access_failures = 0;

    assert(NULL != template_path);

    len = strlen(template_path);

    for(n = 0, nX = 0, limit = 1; n != len; ++n, ++nX, limit *= 10)
    {
        char const ch = template_path[len - (1 + n)];

        if('X' != ch)
        {
            break;
        }
    }

#if defined(UNIXEM_USING_SAFE_STR_FUNCTIONS)
    _snprintf_s(&fmt[0], sizeof(fmt), sizeof(fmt) / sizeof(fmt[0]), "%%0%uu", nX);

#elif defined(_MSC_VER)
    _snprintf(&fmt[0], sizeof(fmt) / sizeof(fmt[0]), "%%0%uu", nX);

#else
    snprintf(&fmt[0], sizeof(fmt) / sizeof(fmt[0]), "%%0%uu", nX);

#endif


    pX = &template_path[0] + (len - nX);

    for(n = 0; n != limit; ++n)
    {
        int hFile;

#if defined(UNIXEM_USING_SAFE_STR_FUNCTIONS)
        _snprintf_s(pX, (1 + nX), (1 + nX), fmt, n);

#elif defined(_MSC_VER)
        _snprintf(pX, (1 + nX), fmt, n);

#else
        snprintf(pX, (1 + nX), fmt, n);

#endif

#if defined(UNIXEM_USING_SAFE_STR_FUNCTIONS)
        if(0 != _sopen_s(&hFile, template_path, _O_WRONLY | _O_CREAT | _O_EXCL, _SH_DENYNO, _S_IREAD | _S_IWRITE))
        {
            hFile = -1;
        }

#elif defined(_MSC_VER)
        hFile = _open(template_path, O_WRONLY | O_CREAT | O_EXCL, S_IREAD | S_IWRITE);

#else
        hFile = open(template_path, O_WRONLY | O_CREAT | O_EXCL, S_IREAD | S_IWRITE);

#endif

        if(-1 != hFile)
        {
            return hFile;
        }
        else
        {
            int const e = errno;

            switch(e)
            {
            case EACCES:
            case EPERM:
                if(100 == ++access_failures)
                {
            case ENOMEM:
                    return -1;
                }
                break;
            default:
                break;
            }
        }
    }

    return -1;
}

char*
unixem_mkdtemp(
    char*   template_path
)
{
    size_t      len;
    unsigned    n;
    unsigned    nX;
    char*       pX;
    char        fmt[21];
    unsigned    limit;

    assert(NULL != template_path);

    len = strlen(template_path);

    for(n = 0, nX = 0, limit = 1; n != len; ++n, ++nX, limit *= 10)
    {
        char const ch = template_path[len - (1 + n)];

        if('X' != ch)
        {
            break;
        }
    }

#if defined(UNIXEM_USING_SAFE_STR_FUNCTIONS)
    _snprintf_s(&fmt[0], sizeof(fmt), sizeof(fmt) / sizeof(fmt[0]), "%%0%uu", nX);

#elif defined(_MSC_VER)
    _snprintf(&fmt[0], sizeof(fmt) / sizeof(fmt[0]), "%%0%uu", nX);

#else
    snprintf(&fmt[0], sizeof(fmt) / sizeof(fmt[0]), "%%0%uu", nX);

#endif

    pX = &template_path[0] + (len - nX);

    for(n = 0; n != limit; ++n)
    {
#if defined(UNIXEM_USING_SAFE_STR_FUNCTIONS)
        _snprintf_s(pX, (1 + nX), (1 + nX), fmt, n);

#elif defined(_MSC_VER)
        _snprintf(pX, (1 + nX), fmt, n);

#else
        snprintf(pX, (1 + nX), fmt, n);

#endif

#if defined(UNIXEM_USING_SAFE_STR_FUNCTIONS)
        if(-1 != _mkdir(template_path))
#else
        if(-1 != mkdir(template_path))
#endif
        {
            return template_path;
        }
    }

    return NULL;
}

/* ///////////////////////////// end of file //////////////////////////// */
