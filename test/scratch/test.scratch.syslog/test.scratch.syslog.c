/* //////////////////////////////////////////////////////////////////////////
 * File:    test.scratch.syslog.c
 *
 * Purpose: Unit-test of `syslog()`.
 *
 * Created: 1st October 2006
 * Updated: 16th October 2024
 *
 * /////////////////////////////////////////////////////////////////////// */


/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

/* STLSoft header files */
#include <stlsoft/stlsoft.h>

/* PlatformSTL header files */
#include <platformstl/platformstl.h>


/* UNIXem header files */
#include <unixem/unixem.h>

/* Standard C header files */
#include <stdio.h>
#include <stdlib.h>

#if defined(_MSC_VER) && \
    defined(_DEBUG)
# include <crtdbg.h>
#endif /* _MSC_VER) && _DEBUG */


/* /////////////////////////////////////////////////////////////////////////
 * macros and definitions
 */

#ifdef true
# undef true
#endif /* true */
#ifdef false
# undef false
#endif /* false */
#define true    (1)
#define false   (0)


/* /////////////////////////////////////////////////////////////////////////
 * globals
 */

#if defined(_DEBUG) || \
    defined(_SYB_DEBUG)
static int  s_bDebugging                =   true;
#else /* ? debug */
static int  s_bDebugging                =   false;
#endif /* debug */
//extern "C" const char FE_SIMPLE_PROCESS_IDENTITY[]    =   "test.scratch.syslog";


/* /////////////////////////////////////////////////////////////////////////
 * typedefs
 */


/* /////////////////////////////////////////////////////////////////////////
 * forward declarations
 */


/* /////////////////////////////////////////////////////////////////////////
 * main()
 */

int main(int argc, char *argv[])
{
#if defined(_DEBUG) || \
    defined(__SYNSOFT_DBS_DEBUG)
    puts("test.scratch.syslog: " STLSOFT_COMPILER_LABEL_STRING);
#endif /* debug */

#if 0
    { size_t i; for (i = 0; i < 0xffffffff; ++i){} }
#endif /* 0 */

    ((void)argc);
    ((void)argv);
    /* . */
    return EXIT_SUCCESS;
}


/* ///////////////////////////// end of file //////////////////////////// */

