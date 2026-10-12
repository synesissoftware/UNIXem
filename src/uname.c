/* /////////////////////////////////////////////////////////////////////////
 * File:    uname.c
 *
 * Purpose: Implementation of the uname() function.
 *
 * Created: 12th October 2026
 * Updated: 14th October 2026
 *
 * Home:    https://github.com/synesissoftware/UNIXem
 *
 * Copyright (c) 2019-2026, Matthew Wilson and Synesis Information Systems
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


#ifndef UNIXEM_DOCUMENTATION_SKIP_SECTION
# define _SYNSOFT_VER_C_UNAME_MAJOR     1
# define _SYNSOFT_VER_C_UNAME_MINOR     0
# define _SYNSOFT_VER_C_UNAME_REVISION  0
# define _SYNSOFT_VER_C_UNAME_EDIT      1
#endif /* !UNIXEM_DOCUMENTATION_SKIP_SECTION */


/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

#include <unixem/sys/utsname.h>

#include <unixem/unixem.h>
#include <unixem/internal/safestr.h>
#include <unixem/internal/util.h>

#include <assert.h>
#include <errno.h>
#include <stdio.h>
#include <string.h>
#include <windows.h>


/* /////////////////////////////////////////////////////////////////////////
 * API functions
 */

int unixem_uname(
    struct unixem_utsname*  name
)
{
    SYSTEM_INFO si;
    DWORD       cchName;
    DWORD       dwVersion;
    DWORD       dwMajorVersion;
    DWORD       dwMinorVersion;
    DWORD       dwBuild;

    assert(NULL != name);

    if (NULL == name)
    {
        errno = EFAULT;

        return -1;
    }

    /* 1. sysname */
    strncpy(name->sysname, "Windows", sizeof(name->sysname) - 1);
    name->sysname[sizeof(name->sysname) - 1] = '\0';

    /* 2. nodename */
    cchName = (DWORD)sizeof(name->nodename);
    if (!GetComputerNameA(name->nodename, &cchName))
    {
        strncpy(name->nodename, "localhost", sizeof(name->nodename) - 1);
        name->nodename[sizeof(name->nodename) - 1] = '\0';
    }

    /* 3 & 4. release & version */
    dwVersion = GetVersion();

    dwMajorVersion = (DWORD)(LOBYTE(LOWORD(dwVersion)));
    dwMinorVersion = (DWORD)(HIBYTE(LOWORD(dwVersion)));
    dwBuild = 0;
    if (dwVersion < 0x80000000)
    {
        dwBuild = (DWORD)(HIWORD(dwVersion));
    }

    /* release: "major.minor" */
    sprintf(name->release, "%u.%u", (unsigned)dwMajorVersion, (unsigned)dwMinorVersion);

    /* version: "Build buildNumber" */
    sprintf(name->version, "Build %u", (unsigned)dwBuild);

    /* 5. machine */
    GetSystemInfo(&si);

    switch (si.wProcessorArchitecture)
    {
        case PROCESSOR_ARCHITECTURE_AMD64:
            strncpy(name->machine, "x86_64", sizeof(name->machine) - 1);
            break;
        case PROCESSOR_ARCHITECTURE_IA64:
            strncpy(name->machine, "ia64", sizeof(name->machine) - 1);
            break;
        case PROCESSOR_ARCHITECTURE_INTEL:
            strncpy(name->machine, "i686", sizeof(name->machine) - 1);
            break;
        case PROCESSOR_ARCHITECTURE_ARM:
            strncpy(name->machine, "arm", sizeof(name->machine) - 1);
            break;
        case PROCESSOR_ARCHITECTURE_ARM64:
            strncpy(name->machine, "arm64", sizeof(name->machine) - 1);
            break;
        default:
            strncpy(name->machine, "unknown", sizeof(name->machine) - 1);
            break;
    }
    name->machine[sizeof(name->machine) - 1] = '\0';

    return 0;
}


/* ///////////////////////////// end of file //////////////////////////// */

