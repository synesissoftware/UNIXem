/* /////////////////////////////////////////////////////////////////////////
 * File:    test.scratch.setenv.c
 *
 * Purpose: Unit-test of `setenv()`.
 *
 * Created: 9th December 2005
 * Updated: 29th November 2024
 *
 * ////////////////////////////////////////////////////////////////////// */


#include <unixem/setenv.h>

/* STLSoft header files */
#include <stlsoft/stlsoft.h>


/* Standard C header files */
#include <stdio.h>
#include <stdlib.h>


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
    ((void)&argc);
    ((void)&argv);

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

