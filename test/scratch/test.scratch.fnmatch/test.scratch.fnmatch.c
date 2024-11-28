/* /////////////////////////////////////////////////////////////////////////
 * File:    test.scratch.fnmatch.c
 *
 * Purpose: Unit-test of `fnmatch()`.
 *
 * Created: 24th April 2006
 * Updated: 28th November 2024
 *
 * ////////////////////////////////////////////////////////////////////// */


/* UNIXem header files */
#include <fnmatch.h>

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
#define true                                                (1)
#define false                                               (0)


/* /////////////////////////////////////////////////////////////////////////
 * globals
 */



/* /////////////////////////////////////////////////////////////////////////
 * typedefs
 */


/* /////////////////////////////////////////////////////////////////////////
 * forward declarations
 */

static void test_1(void);
static void test_2(void);
static void test_3(void);


/* /////////////////////////////////////////////////////////////////////////
 * main()
 */

int main(int argc, char *argv[])
{
#if 0
    { size_t i; for (i = 0; i < 0xffffffff; ++i){} }
#endif /* 0 */

    ((void)argc);
    ((void)argv);
    /* . */

    test_1();

    return EXIT_SUCCESS;
}


/* /////////////////////////////////////////////////////////////////////////
 * test function implementations
 */

static void test_1(void)
{
    if (0 != fnmatch("a", "a", 0))
    {
        fprintf(stderr, "test failed!\n");
    }
    if (0 == fnmatch("a", "b", 0))
    {
        fprintf(stderr, "test failed!\n");
    }

    if (0 != fnmatch("[a-d]", "a", 0))
    {
        fprintf(stderr, "test failed!\n");
    }

    if (0 == fnmatch("[^A-Zb-z0-9]", "a", 0))
    {
        fprintf(stderr, "test failed!\n");
    }
}

static void test_2(void)
{
//  int fnmatch(char const *pattern, char const *string, int flags);
}

static void test_3(void)
{
//  int fnmatch(char const *pattern, char const *string, int flags);
}


/* ///////////////////////////// end of file //////////////////////////// */

