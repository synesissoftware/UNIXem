/* /////////////////////////////////////////////////////////////////////////
 * File:    unixem/util/fs.h
 *
 * Purpose: UNIXem.Util.FS header.
 *
 * Created: 11th May 2025
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


/** \file unixem/util/fs.h
 *
 * UNIXem.Util.FS header.
 */

#ifndef SYNSOFT_UNIXEM_INCL_UNIXEM_UTIL_H_FS
#define SYNSOFT_UNIXEM_INCL_UNIXEM_UTIL_H_FS

/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

#include <stddef.h>


/* /////////////////////////////////////////////////////////////////////////
 * API functions
 */

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */



/** Indicates whether the given character is a path separator (i.e. `'/'` or
 * `'\'`)
 *
 * \retval 0 The character is not a separator;
 * \retval 1 The character is a separator;
 */
int
unixem_util_fs_char_is_path_sep(char ch);

/** Indicates whether the given path refers to an existing file-system entry
 * that is a directory.
 *
 * \retval 0 `path` does not name a directory, or names a file-sytem entry
 *  that is not a directory;
 * \retval 1 `path` names an existing directory;
 */
int
unixem_util_fs_directory_exists(char const* path);

/** Attempts to obtain the home directory.
 *
 * \param ar Pointer to an array of `char` of size 260 (=== _MAX_PATH);
 * \param pnumWritten Optional pointer to a variable to receive the number
 *  of characters written (excluding the NUL terminator);
 *
 * \retval 0 The character is not a separator;
 * \retval 1 The character is a separator;
 */
int
unixem_util_fs_get_home_directory(
    char  (*ar)[260]
,   size_t* pnumWritten
);


/* ////////////////////////////////////////////////////////////////////// */

#ifdef __cplusplus
}
#endif /* __cplusplus */


/* ////////////////////////////////////////////////////////////////////// */

#endif /* SYNSOFT_UNIXEM_INCL_UNIXEM_UTIL_H_FS */

/* ///////////////////////////// end of file //////////////////////////// */

