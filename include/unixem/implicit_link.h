/* /////////////////////////////////////////////////////////////////////////
 * File:    unixem/implicit_link.h
 *
 * Purpose: Implicit linking for the UNIXem API.
 *
 * Created: 29th August 2005
 * Updated: 1st May 2025
 *
 * Home:    https://github.com/synesissoftware/UNIXem
 *
 * Copyright (c) 2019-2025, Matthew Wilson and Synesis Information Systems
 * Copyright (c) 2004-2019, Matthew Wilson and Synesis Software
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


/** \file unixem/implicit_link.h Implicit linking for the UNIXem API
 */

#ifndef UNIXEM_INCL_UNIXEM_H_IMPLICIT_LINK
#define UNIXEM_INCL_UNIXEM_H_IMPLICIT_LINK


/* /////////////////////////////////////////////////////////////////////////
 * version
 */

#ifndef UNIXEM_DOCUMENTATION_SKIP_SECTION
# define UNIXEM_VER_UNIXEM_H_IMPLICIT_LINK_MAJOR    2
# define UNIXEM_VER_UNIXEM_H_IMPLICIT_LINK_MINOR    1
# define UNIXEM_VER_UNIXEM_H_IMPLICIT_LINK_REVISION 3
# define UNIXEM_VER_UNIXEM_H_IMPLICIT_LINK_EDIT     24
#endif /* !UNIXEM_DOCUMENTATION_SKIP_SECTION */


/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

#include <unixem/unixem.h>


/* /////////////////////////////////////////////////////////////////////////
 * macros and definitions
 */

#ifndef UNIXEM_DOCUMENTATION_SKIP_SECTION
# define UNIXEM_STRINGIZE_(x)                               #x
# define UNIXEM_STRINGIZE(x)                                UNIXEM_STRINGIZE_(x)
#endif /* !UNIXEM_DOCUMENTATION_SKIP_SECTION */


/* /////////////////////////////////////////////////////////////////////////
 * architecture discrimination
 */

#if 0
#elif defined(__amd64__) || \
      defined(__amd64) || \
      defined(_AMD64_) || \
      defined(_M_AMD64) || \
      defined(_M_X64) || \
      0
# define UNIXEM_ARCH_IS_X64
#elif 0 ||
      defined(__ia64__) || \
      defined(__ia64) || \
      defined(_IA64_) || \
      defined(_M_IA64) || \
      0
# define UNIXEM_ARCH_IS_IA64
#elif 0 || \
      defined(__i386__) || \
      defined(__i386) || \
      defined(_X86_) || \
      defined(_M_IX86) || \
      0
# define UNIXEM_ARCH_IS_X86
#endif /* _M_?? */


/* /////////////////////////////////////////////////////////////////////////
 * implicit linking
 */

#if defined(_WIN32) || \
    defined(_WIN64)

 /* architecture */
# if !defined(UNIXEM_ARCH_IS_X86) && \
     !defined(UNIXEM_ARCH_IS_X64) && \
     !defined(UNIXEM_ARCH_IS_IA64)

  /* see if using PlatformSTL */
#  ifdef PLATFORMSTL_OS_IS_WINDOWS

   /* prefer PlatformSTL discrimination */
#   if defined(UNIXEM_ARCH_IS_X86)
#    define UNIXEM_ARCH_IS_X86
#   elif defined(UNIXEM_ARCH_IS_X64)
#    define UNIXEM_ARCH_IS_X64
#   elif defined(UNIXEM_ARCH_IS_IA64)
#    define UNIXEM_ARCH_IS_IA64
#   endif

#  else /* ? PLATFORMSTL_OS_IS_WINDOWS */

   /* custom discrimination */

#   if defined(_M_IA64)
#    define UNIXEM_ARCH_IS_IA64
#   elif defined(_M_X64) || \
         defined(_M_AMD64)
#    define UNIXEM_ARCH_IS_X64
#   elif defined(_M_IX86)
#    define UNIXEM_ARCH_IS_X86
#   endif /* arch */

#  endif /* PLATFORMSTL_OS_IS_WINDOWS */
# endif /* !UNIXEM_ARCH_IS_???? */


# if defined(__BORLANDC__) || \
     /* defined(__DMC__) || */ \
     defined(__INTEL_COMPILER) || \
     defined(__MWERKS__) || \
     defined(_MSC_VER)
#  if !defined(__COMO__)
#   define UNIXEM_IMPLICIT_LINK_SUPPORT
#  endif /* compiler */
# endif /* compiler */

# if defined(UNIXEM_IMPLICIT_LINK_SUPPORT) && \
     defined(UNIXEM_NO_IMPLICIT_LINK)
#  undef UNIXEM_IMPLICIT_LINK_SUPPORT
# endif /* UNIXEM_IMPLICIT_LINK_SUPPORT && UNIXEM_NO_IMPLICIT_LINK */

# if defined(UNIXEM_IMPLICIT_LINK_SUPPORT)

  /* prefix */

#  define UNIXEM_IMPL_LINK_PREFIX

  /* library basename */

#  define UNIXEM_IMPL_LINK_LIBRARY_BASENAME                 "unixem"

  /* major version */

#  define UNIXEM_IMPL_LINK_MAJOR_VERSION                    "." UNIXEM_STRINGIZE(UNIXEM_VER_MAJOR)

  /* module name */

#  define UNIXEM_IMPL_LINK_MODULE_NAME                      ".core"

  /* compiler tag */

#  if defined(__BORLANDC__)
#   if __BORLANDC__ == 0x0550
#    define UNIXEM_IMPL_LINK_COMPILER_NAME                  "bc55"
#   elif (__BORLANDC__ == 0x0551)
#    define UNIXEM_IMPL_LINK_COMPILER_NAME                  "bc551"
#   elif (__BORLANDC__ == 0x0560)
#    define UNIXEM_IMPL_LINK_COMPILER_NAME                  "bc56"
#   elif (__BORLANDC__ == 0x0564)
#    define UNIXEM_IMPL_LINK_COMPILER_NAME                  "bc564"
#   elif (__BORLANDC__ == 0x0582)
#    define UNIXEM_IMPL_LINK_COMPILER_NAME                  "bc582"
#   elif (0x0590 == (__BORLANDC__ & 0xfff0))
#    define UNIXEM_IMPL_LINK_COMPILER_NAME                  "bc59x"
#   elif (0x0610 == (__BORLANDC__ & 0xfff0))
#    define UNIXEM_IMPL_LINK_COMPILER_NAME                  "bc61x"
#   else /* ? __BORLANDC__ */
#    error Unrecognised value of __BORLANDC__
#   endif /* __BORLANDC__ */

/*
#  elif defined(__DMC__)
#   define UNIXEM_IMPL_LINK_COMPILER_NAME                   "dm"
 */

#  elif defined(__INTEL_COMPILER)
#   if (__INTEL_COMPILER == 600)
#    define   UNIXEM_IMPL_LINK_COMPILER_NAME                "icl6"
#   elif (__INTEL_COMPILER == 700)
#    define   UNIXEM_IMPL_LINK_COMPILER_NAME                "icl7"
#   elif (__INTEL_COMPILER == 800)
#    define   UNIXEM_IMPL_LINK_COMPILER_NAME                "icl8"
#   elif (__INTEL_COMPILER == 900)
#    define   UNIXEM_IMPL_LINK_COMPILER_NAME                "icl9"
#   elif (__INTEL_COMPILER == 1000)
#    define   UNIXEM_IMPL_LINK_COMPILER_NAME                "icl10"
#   elif (__INTEL_COMPILER == 1100)
#    define   UNIXEM_IMPL_LINK_COMPILER_NAME                "icl11"
#   else /* ? __INTEL_COMPILER */
#    error Intel C/C++ version not supported
#   endif /* __INTEL_COMPILER */

#  elif defined(__MWERKS__)
#   if ((__MWERKS__ & 0xFF00) == 0x2400)
#    define UNIXEM_IMPL_LINK_COMPILER_NAME                  "cw7"
#   elif ((__MWERKS__ & 0xFF00) == 0x3000)
#    define UNIXEM_IMPL_LINK_COMPILER_NAME                  "cw8"
#   elif ((__MWERKS__ & 0xFF00) == 0x3200)
#    define UNIXEM_IMPL_LINK_COMPILER_NAME                  "cw9"
#   else /* ? __MWERKS__ */
#    error CodeWarrior version not supported
#   endif /* __MWERKS__ */

#  elif defined(_MSC_VER)
#   if _MSC_VER == 1000
#    define UNIXEM_IMPL_LINK_COMPILER_NAME                  "vc4"
#   elif _MSC_VER == 1020
#    define UNIXEM_IMPL_LINK_COMPILER_NAME                  "vc42"
#   elif _MSC_VER == 1100
#    define UNIXEM_IMPL_LINK_COMPILER_NAME                  "vc5"
#   elif _MSC_VER == 1200
#    define UNIXEM_IMPL_LINK_COMPILER_NAME                  "vc6"
#   elif _MSC_VER == 1300
#    define UNIXEM_IMPL_LINK_COMPILER_NAME                  "vc7"
#   elif _MSC_VER == 1310
#    define UNIXEM_IMPL_LINK_COMPILER_NAME                  "vc71"
#   elif _MSC_VER == 1400
#    define UNIXEM_IMPL_LINK_COMPILER_NAME                  "vc8"
#   elif _MSC_VER == 1500
#    define UNIXEM_IMPL_LINK_COMPILER_NAME                  "vc9"
#   elif _MSC_VER == 1600
#    define UNIXEM_IMPL_LINK_COMPILER_NAME                  "vc10"
#   elif _MSC_VER == 1700
#    define UNIXEM_IMPL_LINK_COMPILER_NAME                  "vc11"
#   elif _MSC_VER == 1800
#    define UNIXEM_IMPL_LINK_COMPILER_NAME                  "vc12"
#   elif _MSC_VER == 1900
#    define UNIXEM_IMPL_LINK_COMPILER_NAME                  "vc14"
#   elif _MSC_VER >= 1910
#    if 0
#    elif _MSC_VER < 1920
#     define UNIXEM_IMPL_LINK_COMPILER_NAME                 "vc15"
#    elif _MSC_VER <= 1929
#     define UNIXEM_IMPL_LINK_COMPILER_NAME                 "vc16"
#    elif _MSC_VER <= 1943
#     define UNIXEM_IMPL_LINK_COMPILER_NAME                 "vc17"
#    else
#     error Visual C++ version that is >= vc17 is not recognised
#    endif
#   else /* ? _MSC_VER */
#    error Visual C++ version not supported
#   endif /* _MSC_VER */

#  else /* ? compiler */
#   error Unrecognised compiler
#  endif /* compiler */


  /* operating system tag */

#  if !defined(UNIXEM_IMPL_LINK_OS_TAG)
#   define UNIXEM_IMPL_LINK_OS_TAG                          ""
#  endif /* !UNIXEM_IMPL_LINK_OS_TAG */


  /* architecture tag */

#  if defined(UNIXEM_ARCH_IS_X86)
#   define UNIXEM_IMPL_LINK_ARCH_TAG                        ""
#  elif defined(UNIXEM_ARCH_IS_X64)
#   define UNIXEM_IMPL_LINK_ARCH_TAG                        ".x64"
#  elif defined(UNIXEM_ARCH_IS_IA64)
#   define UNIXEM_IMPL_LINK_ARCH_TAG                        ".ia64"
#  endif /* arch */

#  if !defined(UNIXEM_IMPL_LINK_ARCH_TAG)
#   define UNIXEM_IMPL_LINK_ARCH_TAG                        ""
#  endif /* !UNIXEM_IMPL_LINK_ARCH_TAG */


  /* encoding tag */

#  if defined(UNIXEM_CHAR_TYPE_IS_WCHAR)
#   define UNIXEM_IMPL_LINK_ENCODING_TAG                    ".widestring"
#  else /* ? UNIXEM_CHAR_TYPE_IS_WCHAR */
#   define UNIXEM_IMPL_LINK_ENCODING_TAG                    ""
#  endif /* UNIXEM_CHAR_TYPE_IS_WCHAR */


  /* threading tag */

#  if defined(__MT__) || \
      defined(_REENTRANT) || \
      defined(_MT)
#   if defined(_DLL) || \
       defined(__DLL)
#    define UNIXEM_IMPL_LINK_THREADING_TAG                  ".dll"
#   else /* ? dll */
#    define UNIXEM_IMPL_LINK_THREADING_TAG                  ".mt"
#   endif /* dll */
#  else /* ? mt */
#    define UNIXEM_IMPL_LINK_THREADING_TAG                  ""
#  endif /* mt */


  /* debug tag */

#  if !defined(NDEBUG) && \
      defined(_DEBUG)
#   define UNIXEM_IMPL_LINK_DEBUG_TAG                       ".debug"
#  else /* ? debug */
#   define UNIXEM_IMPL_LINK_DEBUG_TAG                       ""
#  endif /* debug */


  /* suffix */

#  define UNIXEM_IMPL_LINK_SUFFIX                           ".lib"


   /* Library name is:
    *
    * [lib]<library-basename>.<major-version>.<module-name>.<compiler-name>[.<os-arch-tag>][.<char-encoding-tag>][.<threading-tag>][.<nox-tag>][.<debug-tag>].{a|lib}
    */

#  define UNIXEM_IMPL_LINK_LIBRARY_NAME     \
    UNIXEM_IMPL_LINK_PREFIX                 \
    UNIXEM_IMPL_LINK_LIBRARY_BASENAME       \
    UNIXEM_IMPL_LINK_MAJOR_VERSION          \
    UNIXEM_IMPL_LINK_MODULE_NAME            \
    "." UNIXEM_IMPL_LINK_COMPILER_NAME      \
    UNIXEM_IMPL_LINK_OS_TAG                 \
    UNIXEM_IMPL_LINK_ARCH_TAG               \
    UNIXEM_IMPL_LINK_ENCODING_TAG           \
    UNIXEM_IMPL_LINK_THREADING_TAG          \
    UNIXEM_IMPL_LINK_DEBUG_TAG              \
    UNIXEM_IMPL_LINK_SUFFIX


#  pragma message("lib: " UNIXEM_IMPL_LINK_LIBRARY_NAME)

#  pragma comment(lib, UNIXEM_IMPL_LINK_LIBRARY_NAME)

# endif /* UNIXEM_IMPLICIT_LINK_SUPPORT */
#endif /* Win-32 || Win-64 */


/* ////////////////////////////////////////////////////////////////////// */

#endif /* !UNIXEM_INCL_UNIXEM_H_IMPLICIT_LINK */

/* ///////////////////////////// end of file //////////////////////////// */

