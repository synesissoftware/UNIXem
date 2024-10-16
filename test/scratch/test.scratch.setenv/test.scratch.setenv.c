/* /////////////////////////////////////////////////////////////////////////
 * File:    test.scratch.setenv.c
 *
 * Purpose: Unit-test of `setenv()`.
 *
 * Created: 9th December 2005
 * Updated: 16th October 2024
 *
 * ////////////////////////////////////////////////////////////////////// */


#include <unixem/setenv.h>

/* STLSoft header files */
#include <stlsoft/stlsoft.h>


/* Standard C header files */
#include <stdio.h>
#include <stdlib.h>

#if defined(_MSC_VER) && \
    defined(_DEBUG)
# include <crtdbg.h>
#endif /* _MSC_VER) && _DEBUG */

/* /////////////////////////////////////////////////////////////////////////
 * compatibility
 */

#define setenv                                              unixem_setenv
#define unsetenv                                            unixem_unsetenv


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
    puts("test.scratch.setenv: " STLSOFT_COMPILER_LABEL_STRING);
#endif /* debug */

    ((void)argc);
    ((void)argv);

#if 0
    { for (size_t i = 0; i < 0xffffffff; ++i){} }
#endif /* 0 */

    setenv("SOMETHING_VERY_UNLIKELY_2_B_SET", "bat", 0);

    printf("SOMETHING_VERY_UNLIKELY_2_B_SET=%s\n", getenv("SOMETHING_VERY_UNLIKELY_2_B_SET"));

    setenv("SOMETHING_VERY_UNLIKELY_2_B_SET", "out", 0);

    printf("SOMETHING_VERY_UNLIKELY_2_B_SET=%s\n", getenv("SOMETHING_VERY_UNLIKELY_2_B_SET"));

    setenv("SOMETHING_VERY_UNLIKELY_2_B_SET", "of", 1);

    printf("SOMETHING_VERY_UNLIKELY_2_B_SET=%s\n", getenv("SOMETHING_VERY_UNLIKELY_2_B_SET"));

    setenv("SOMETHING_VERY_UNLIKELY_2_B_SET", "hell", 0);

    printf("SOMETHING_VERY_UNLIKELY_2_B_SET=%s\n", getenv("SOMETHING_VERY_UNLIKELY_2_B_SET"));

    unsetenv("SOMETHING_VERY_UNLIKELY_2_B_SET");

    setenv("SOMETHING_VERY_UNLIKELY_2_B_SET", "deadringer", 0);

    printf("SOMETHING_VERY_UNLIKELY_2_B_SET=%s\n", getenv("SOMETHING_VERY_UNLIKELY_2_B_SET"));

    return EXIT_SUCCESS;
}


/* ///////////////////////////// end of file //////////////////////////// */

