/* /////////////////////////////////////////////////////////////////////////
 * File:    glob.c
 *
 * Purpose: Definition of the glob() API functions for the Windows platform.
 *
 * Created: 13th November 2002
 * Updated: 18th May 2025
 *
 * Home:    https://github.com/synesissoftware/UNIXem
 *
 * Copyright (c) 2019-2025, Matthew Wilson and Synesis Information Systems
 * Copyright (c) 2002-2019, Matthew Wilson and Synesis Software
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
# define _SYNSOFT_VER_C_UNIXEM_GLOB_MAJOR       3
# define _SYNSOFT_VER_C_UNIXEM_GLOB_MINOR       1
# define _SYNSOFT_VER_C_UNIXEM_GLOB_REVISION    7
# define _SYNSOFT_VER_C_UNIXEM_GLOB_EDIT        63
#endif /* !UNIXEM_DOCUMENTATION_SKIP_SECTION */


/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

#include <unixem/glob.h>

#include <unixem/unixem.h>
#include <unixem/internal/safestr.h>
#include <unixem/internal/util.h>

#include <assert.h>
#include <errno.h>
#include <stdlib.h>
#include <windows.h>

#include <unixem/util/fs.h>


/* /////////////////////////////////////////////////////////////////////////
 * helper functions
 */

static char const* unixem_strrpbrk_(
    char const* string
,   char const* strCharSet
)
{
    char*       part = NULL;
    char const* pch;

    for (pch = strCharSet; *pch; ++pch)
    {
        char* p = strrchr(string, *pch);

        if (NULL != p)
        {
            if (NULL == part)
            {
                part = p;
            }
            else
            {
                if (part < p)
                {
                    part = p;
                }
            }
        }
    }

    return part;
}

static
int
unixem_glob_isdots_(
    char const* s
)
{
    if ('.' == s[0])
    {
        if ('\0' == s[1])
        {
            return 1;
        }
        else if ('.' == s[1])
        {
            if ('\0' == s[2])
            {
                return 1;
            }
        }
    }

    return 0;
}

static
int
unixem_glob_sort_random_order_(
    void const* p1
,   void const* p2
)
{
    ((void)&p1);
    ((void)&p2);

    return (rand() % 3) - 1;
}


/* /////////////////////////////////////////////////////////////////////////
 * API functions
 */

/* It gives you back the matched contents of your pattern, so for Windows,
 * the directories must be included
 */

int unixem_glob(
    char const*     pattern
,   int             flags
,   int           (*errfunc)(char const *, int)
,   unixem_glob_t*  pglob
)
{
    int                 result;
    char                szRelative[1 + _MAX_PATH];
    char const*         file_part;
    WIN32_FIND_DATAA    find_data;
    HANDLE              hFind;
    char*               buffer;
    char                szHomePrefixedPath[1 + _MAX_PATH];
    size_t const        cchPattern          =   strlen(pattern);
    char const*         effectivePattern    =   pattern;
    char const*         leafMost;
    int const           bMagic              =   (NULL != strpbrk(pattern, "?*"));
    int                 bNoMagic            =   0;
    int                 bMagic0;
    int                 bLeafIsDots;
    size_t              maxMatches          =   ~(size_t)(0);

    assert(NULL != pglob);

    if (flags & UNIXEM_GLOB_NOMAGIC)
    {
        bNoMagic = !bMagic;
    }

    if (flags & UNIXEM_GLOB_LIMIT)
    {
        maxMatches = (size_t)pglob->gl_matchc;
    }

    if (flags & UNIXEM_GLOB_TILDE)
    {
        /* Check that begins with "~/" */
        if ('~' == pattern[0] &&
            (   '\0' == pattern[1] ||
                unixem_util_fs_char_is_path_sep(pattern[1])))
        {
            char    szHomeDir[_MAX_PATH];
            size_t  n;

            if (!unixem_util_fs_get_home_directory(&szHomeDir, &n))
            {
                DWORD const le = GetLastError();

                errno = unixem_internal_errno_from_Win32(le);

                return UNIXEM_GLOB_ABEND;
            }
            else
            if (cchPattern + n + 1 > _MAX_PATH - 1)
            {
                DWORD const le = ERROR_INVALID_PARAMETER;

                errno = unixem_internal_errno_from_Win32(le);

                return UNIXEM_GLOB_ABEND;
            }
            else
            {
                CopyMemory(&szHomePrefixedPath[0] + 0, &szHomeDir[0], (1 + n) * sizeof(szHomePrefixedPath[0]));
                CopyMemory(&szHomePrefixedPath[0] + n, &pattern[1], (cchPattern - 1 + 1) * sizeof(szHomePrefixedPath[0]));

                effectivePattern = szHomePrefixedPath;
            }
        }
    }

    file_part = unixem_strrpbrk_(effectivePattern, "\\/");

    if (NULL != file_part)
    {
        leafMost = ++file_part;

        (void)lstrcpyA(szRelative, effectivePattern);
        szRelative[file_part - effectivePattern] = '\0';
    }
    else
    {
        szRelative[0] = '\0';
        leafMost = effectivePattern;
    }

    bMagic0 =   (leafMost == strpbrk(leafMost, "?*"));
    bLeafIsDots = unixem_glob_isdots_(leafMost);

    hFind   =   FindFirstFileA(effectivePattern, &find_data);
    buffer  =   NULL;

    pglob->gl_pathc = 0;
    pglob->gl_pathv = NULL;

    if (0 == (flags & UNIXEM_GLOB_DOOFFS))
    {
        pglob->gl_offs = 0;
    }

    if (INVALID_HANDLE_VALUE == hFind)
    {
        /* If this was a pattern search, and the
         * directory exists, then we return 0
         * matches, rather than UNIXEM_GLOB_NOMATCH
         */
        if (bMagic &&
            NULL != file_part)
        {
            result = 0;
        }
        else
        {
            if (NULL != errfunc)
            {
                (void)errfunc(effectivePattern, (int)GetLastError());
            }

            result = UNIXEM_GLOB_NOMATCH;
        }
    }
    else
    {
        int     cbCurr      =   0;
        size_t  cbAlloc     =   0;
        size_t  cMatches    =   0;

        result = 0;

        do
        {
            int     cch;
            size_t  new_cbAlloc;

            if (bMagic0 &&
                0 == (flags & UNIXEM_GLOB_PERIOD))
            {
                if ('.' == find_data.cFileName[0])
                {
                    continue;
                }
            }

            if (find_data.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
            {
#ifdef UNIXEM_GLOB_ONLYREG
                if (flags & UNIXEM_GLOB_ONLYREG)
                {
                    continue;
                }
#endif /* UNIXEM_GLOB_ONLYREG */

                if (bMagic0 &&
                    UNIXEM_GLOB_NODOTSDIRS == (flags & UNIXEM_GLOB_NODOTSDIRS))
                {
                    /* Pattern must begin with '.' to match either dots directory */
                    if (unixem_glob_isdots_(find_data.cFileName))
                    {
                        continue;
                    }
                }

                if (flags & UNIXEM_GLOB_MARK)
                {
                    (void)lstrcatA(find_data.cFileName, "/");
                }
            }
            else
            {
                if (flags & UNIXEM_GLOB_ONLYDIR)
                {
                    /* Skip all further actions, and get the next entry */
                    continue;
                }
            }

            if (bLeafIsDots)
            {
                (void)lstrcpyA(find_data.cFileName, leafMost);

                if (flags & UNIXEM_GLOB_MARK)
                {
                    (void)lstrcatA(find_data.cFileName, "/");
                }
            }

            cch = lstrlenA(find_data.cFileName);
            if (NULL != file_part)
            {
                cch += (int)(file_part - effectivePattern);
            }

            new_cbAlloc = (size_t)cbCurr + cch + 1;
            if (new_cbAlloc > cbAlloc)
            {
                char* new_buffer;

                new_cbAlloc *= 2;

                new_cbAlloc = (new_cbAlloc + 31) & ~(31);

                new_buffer  = (char*)realloc(buffer, new_cbAlloc);

                if (NULL == new_buffer)
                {
                    result = UNIXEM_GLOB_NOSPACE;
                    free(buffer);
                    buffer = NULL;
                    break;
                }

                buffer = new_buffer;
                cbAlloc = new_cbAlloc;
            }

            (void)lstrcpynA(buffer + cbCurr, szRelative, 1 + (int)(file_part - effectivePattern));
            (void)lstrcatA(buffer + cbCurr, find_data.cFileName);
            cbCurr += cch + 1;

            ++cMatches;
        }
        while(FindNextFile(hFind, &find_data) && cMatches != maxMatches);

        (void)FindClose(hFind);

        if (0 == result)
        {
            /* Now expand the buffer, to fit in all the pointers. */
            size_t  cbPointers  =   (1 + cMatches + pglob->gl_offs) * sizeof(char*);
            char*   new_buffer  =   (char*)realloc(buffer, cbAlloc + cbPointers);

            if (NULL == new_buffer)
            {
                result = UNIXEM_GLOB_NOSPACE;
                free(buffer);
            }
            else
            {
                char**  pp;
                char**  begin;
                char**  end;
                char*   next_str;

                buffer = new_buffer;

                (void)memmove(new_buffer + cbPointers, new_buffer, cbAlloc);

                /* Handle the offsets. */
                begin =   (char**)new_buffer;
                end   =   begin + pglob->gl_offs;

                for (; begin != end; ++begin)
                {
                    *begin = NULL;
                }

                /* Sort, or no sort. */
                pp    =   (char**)new_buffer + pglob->gl_offs;
                begin =   pp;
                end   =   begin + cMatches;

                if (flags & UNIXEM_GLOB_NOSORT)
                {
                    /* The way we need in order to test the removal of dots in the findfile_sequence. */
                    *end = NULL;
                    for (begin = pp, next_str = buffer + cbPointers; begin != end; --end)
                    {
                        *(end - 1) = next_str;

                        /* Find the next string. */
                        next_str += 1 + lstrlenA(next_str);
                    }

                    qsort(
                        pp
                    ,   cMatches
                    ,   sizeof(char const*)
                    ,   unixem_glob_sort_random_order_
                    );
                }
                else
                {
                    /* The normal way. */
                    for (begin = pp, next_str = buffer + cbPointers; begin != end; ++begin)
                    {
                        *begin = next_str;

                        /* Find the next string. */
                        next_str += 1 + lstrlenA(next_str);
                    }
                    *begin = NULL;
                }

                /* Return results to caller. */
                pglob->gl_pathc =   (int)cMatches;
                pglob->gl_matchc=   (int)cMatches;
                pglob->gl_flags =   0;
                if (bMagic)
                {
                    pglob->gl_flags |= UNIXEM_GLOB_MAGCHAR;
                }
                pglob->gl_pathv =   (char**)new_buffer;
            }
        }

        if (0 == cMatches)
        {
            result = UNIXEM_GLOB_NOMATCH;
        }
    }

    if (UNIXEM_GLOB_NOMATCH == result)
    {
        if ((flags & UNIXEM_GLOB_TILDE_CHECK) &&
            effectivePattern == szHomePrefixedPath)
        {
            result = UNIXEM_GLOB_NOMATCH;
        }
        else if (bNoMagic ||
                (flags & UNIXEM_GLOB_NOCHECK))
        {
            size_t const    effPattLen  =   strlen(effectivePattern);
            size_t const    cbNeeded    =   ((2 + pglob->gl_offs) * sizeof(char*)) + (1 + effPattLen);
            char**          pp          =   (char**)realloc(buffer, cbNeeded);

            if (NULL == pp)
            {
                result = UNIXEM_GLOB_NOSPACE;
                free(buffer);
            }
            else
            {
                /* Handle the offsets. */
                char**  begin   =   pp;
                char**  end     =   pp + pglob->gl_offs;
                char*   dest    =   (char*)(pp + 2 + pglob->gl_offs);

                for (; begin != end; ++begin)
                {
                    *begin = NULL;
                }

                /* Synthesise the pattern result. */
#ifdef UNIXEM_USING_SAFE_STR_FUNCTIONS
                pp[0 + pglob->gl_offs]  =   (strcpy_s(dest, effPattLen + 1, effectivePattern), dest);
#else /* ? UNIXEM_USING_SAFE_STR_FUNCTIONS */
                pp[0 + pglob->gl_offs]  =   strcpy(dest, effectivePattern);
#endif /* UNIXEM_USING_SAFE_STR_FUNCTIONS */
                pp[1 + pglob->gl_offs]  =   NULL;

                /* Return results to caller. */
                pglob->gl_pathc =   1;
                pglob->gl_matchc=   1;
                pglob->gl_flags =   0;
                if (bMagic)
                {
                    pglob->gl_flags |= UNIXEM_GLOB_MAGCHAR;
                }
                pglob->gl_pathv =   pp;

                result = 0;
            }
        }
    }
    else if (0 == result)
    {
        if ((size_t)pglob->gl_matchc == maxMatches)
        {
            result = UNIXEM_GLOB_NOSPACE;
        }
    }

    return result;
}

void unixem_globfree(unixem_glob_t* pglob)
{
    if (NULL != pglob)
    {
        free(pglob->gl_pathv);
        pglob->gl_pathc = 0;
        pglob->gl_pathv = NULL;
    }
}


/* ///////////////////////////// end of file //////////////////////////// */

