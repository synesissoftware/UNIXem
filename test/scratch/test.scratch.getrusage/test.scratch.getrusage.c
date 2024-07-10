/* /////////////////////////////////////////////////////////////////////////
 * File:    test.scratch.getrusage.c
 *
 * Purpose: Unit-test of `getrusage()`.
 *
 * Created: 9th June 2006
 * Updated: 10th July 2024
 *
 * ////////////////////////////////////////////////////////////////////// */


/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

/* UNIXem header files */
#include <sys/resource.h>
#include <unixem/internal/safestr.h>

/* Standard C header files */
#include <stdio.h>
#include <stdlib.h>

#if defined(_MSC_VER) && \
    defined(_DEBUG)
# include <crtdbg.h>
#endif /* _MSC_VER) && _DEBUG */


/* /////////////////////////////////////////////////////////////////////////
 * main()
 */

int main(int argc, char *argv[])
{
    ((void)argc);
    ((void)argv);

    {
        struct rusage   usage;

        { size_t i; for(i = 0; i < 0xffffff; ++i){} }

        { size_t i; for(i = 0; i < 10; ++i)
        {
#ifdef UNIXEM_USING_SAFE_STR_FUNCTIONS
            FILE*   f;
            errno_t e = fopen_s(&f, "abc", "w");

            if (0 == e)
#else /* ? UNIXEM_USING_SAFE_STR_FUNCTIONS */
            FILE*   f = fopen("abc", "w");

            if (NULL != f)
#endif /* UNIXEM_USING_SAFE_STR_FUNCTIONS */
            {
                char    buf[100]    =   "";
                int     j;

                for(j = 0; j < 100; ++j)
                {
                    fwrite(&buf[0], 100, 1, f);
                }

                fclose(f);
            }
        }}

        getrusage(0, &usage);

        printf("system: %ld - %ld\n", usage.ru_stime.tv_sec, usage.ru_stime.tv_usec);
        printf("user:   %ld - %ld\n", usage.ru_utime.tv_sec, usage.ru_utime.tv_usec);
    }

    return EXIT_SUCCESS;
}


/* ///////////////////////////// end of file //////////////////////////// */

