/* /////////////////////////////////////////////////////////////////////////
 * File:    time.c
 *
 * Purpose: gettimeofday() for the Win32 platform.
 *
 * Created: 1st November 2003
 * Updated: 14th October 2019
 *
 * Home:    http://synesis.com.au/software/
 *
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


#ifndef UNIXEM_DOCUMENTATION_SKIP_SECTION
# define _SYNSOFT_VER_C_TIME_MAJOR      3
# define _SYNSOFT_VER_C_TIME_MINOR      1
# define _SYNSOFT_VER_C_TIME_REVISION   2
# define _SYNSOFT_VER_C_TIME_EDIT       29
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

#include <unixem/time.h>
#include <unixem/sys/time.h>

#include <unixem/internal/util.h>

struct timezone;

#include <windows.h>

#include <assert.h>
#include <errno.h>
#include <time.h>

/* /////////////////////////////////////////////////////////////////////////
 * internal helper functions
 */

static
int
unixem_impl_numberOfDaysInMonth(
    int year
,   int month
)
{
    assert(year >= 1970);
    assert(month >= 0 && month < 12);

    switch(month)
    {
        case    3:  /* Apr */
        case    5:  /* Jun */
        case    8:  /* Sep */
        case    10: /* Nov */
            return 30;

        case    1:  /* Feb */
            if(unixem_internal_yearIsLeap(year))
            {
                return 29;
            }
            else
            {
                return 28;
            }

        default:
            return 31;
    }
}

/* /////////////////////////////////////////////////////////////////////////
 * helper functions
 */

/** This function is from the STLSoft libraries */
extern
long
unixem_internal_FILETIMEToUNIXTime(
    void const*     pv
,   long*           microseconds
)
{
	FILETIME const* const ft = (FILETIME const*)(pv);

#if defined(__COMO__)
    long long   i;
#else /* ? compiler */
    LONGLONG    i;
#endif /* compiler */

    i = ft->dwHighDateTime;
    i <<= 32;
    i |= ft->dwLowDateTime;

#if (   (   defined(__BORLANDC__) && \
            __BORLANDC__ >= 0x0582) || \
        defined(__DMC__) || \
        defined(__COMO__) || \
        defined(__GNUC__) || \
        defined(__MWERKS__))
    i -= 116444736000000000LL;
#else
    i -= 116444736000000000L;
#endif /* compiler */
    if(NULL != microseconds)
    {
        *microseconds = (long)((i % 10000000) / 10);
    }
    i /= 10000000;

    return (long)i;
}

int
unixem_internal_yearIsLeap(
    int year
)
{
    if(0 != (year % 4))
    {
        return 0;
    }
    else
    if(0 != (year % 100))
    {
        return 1;
    }
    else
    if(0 == (year % 400))
    {
        return 1;
    }

    return 0;
}

/* /////////////////////////////////////////////////////////////////////////
 * API functions
 */

int
unixem_gettimeofday(
    struct unixem_timeval*  tv
,   void*                   dummy
)
{
    SYSTEMTIME  st;
    FILETIME    ft;

    assert(NULL != tv);

    ((void)dummy);

    GetSystemTime(&st);

    if(!SystemTimeToFileTime(&st, &ft))
    {
        DWORD const e = GetLastError();

        errno = unixem_internal_errno_from_Win32(e);

        tv->tv_sec  =   0;
        tv->tv_usec =   0;

        return -1;
    }
    else
    {
        tv->tv_sec = unixem_internal_FILETIMEToUNIXTime(&ft, &tv->tv_usec);

        return 0;
    }
}

time_t
unixem_timegm(
    struct tm* tm
)
{
    time_t t = 0;

    assert(NULL != tm);
    assert(tm->tm_year >= 0);
    assert(tm->tm_mon >= 0);
    assert(tm->tm_yday >= 0);
    assert(tm->tm_mday >= 0);
    assert(tm->tm_wday >= 0);
    assert(tm->tm_hour >= 0);
    assert(tm->tm_min >= 0);
    assert(tm->tm_sec >= 0);

    assert(tm->tm_mon < 12);
    assert(tm->tm_yday < 367);
    assert(tm->tm_mday < 32);
    assert(tm->tm_wday < 6);
    assert(tm->tm_hour < 24);
    assert(tm->tm_min < 60);
    assert(tm->tm_sec < 60);

    /* days (from year, month, and day) */

    { int y; for(y = 70; y != tm->tm_year; ++y)
    {
        t += 365;

        if(unixem_internal_yearIsLeap(1900 + y))
        {
            ++t;
        }
    }}

    { int m; for(m = 0; m != tm->tm_mon; ++m)
    {
        t += unixem_impl_numberOfDaysInMonth(tm->tm_year + 1900, m);
    }}

    t += tm->tm_mday - 1;

    /* hours */

    t *= 24;

    t += tm->tm_hour;

    /* minutes */

    t *= 60;

    t += tm->tm_min;

    /* seconds */

    t *= 60;

    t += tm->tm_sec;


    return t;
}

/* ///////////////////////////// end of file //////////////////////////// */
