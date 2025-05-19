/* /////////////////////////////////////////////////////////////////////////
 * File:    util_str.c
 *
 * Purpose: UNIXem.Util.Str implementation.
 *
 * Created: 18th May 2025
 * Updated: 18th May 2025
 *
 * Home:    https://github.com/synesissoftware/UNIXem
 *
 * Copyright (c) 2025, Matthew Wilson and Synesis Information Systems
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


/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

#include <unixem/util/str.h>

#include <assert.h>
#include <string.h>


/* /////////////////////////////////////////////////////////////////////////
 * API functions
 */

int
unixem_util_str_begins_with(
    char const* s
,   char const* prefix
)
{
    assert(NULL != s);
    assert(NULL != prefix);

    {
        size_t const    len_prefix  =   strlen(prefix);

        return 0 == strncmp(s, prefix, len_prefix);
    }
}

int
unixem_util_str_ends_with(
    char const* s
,   char const* suffix
)
{
    assert(NULL != s);
    assert(NULL != suffix);

    {
        size_t const    len_s       =   strlen(s);
        size_t const    len_suffix  =   strlen(suffix);

        if (len_s < len_suffix)
        {
            return 0;
        }
        else
        {
            return 0 == strcmp(s + (len_s - len_suffix), suffix);
        }
    }
}

char*
unixem_util_str_stpcpy(
    char*       target
,   char const* source
)
{
    for (;; ++target, ++source)
    {
        *target = *source;

        if ('\0' == *target)
        {
            break;
        }
    }

    return target;
}

char*
unixem_util_str_stpncpy(
    char*       target
,   char const* source
,   size_t      n
)
{
    for (; 0 != n; --n, ++target)
    {
        *target = *source;

        if ('\0' != *source)
        {
            ++source;
        }
    }

    return target;
}

wchar_t*
unixem_util_str_wcpcpy(
    wchar_t*        target
,   wchar_t const*  source
)
{
    for (;; ++target, ++source)
    {
        *target = *source;

        if ('\0' == *target)
        {
            break;
        }
    }

    return target;
}

wchar_t*
unixem_util_str_wcpncpy(
    wchar_t*        target
,   wchar_t const*  source
,   size_t          n
)
{
    for (; 0 != n; --n, ++target)
    {
        *target = *source;

        if ('\0' != *source)
        {
            ++source;
        }
    }

    return target;
}


/* ///////////////////////////// end of file //////////////////////////// */

