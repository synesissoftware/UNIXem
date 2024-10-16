/* /////////////////////////////////////////////////////////////////////////
 * File:    test.scratch.getrusage.c
 *
 * Purpose: Unit-test of `getrusage()`.
 *
 * Created: 9th June 2006
 * Updated: 16th October 2024
 *
 * ////////////////////////////////////////////////////////////////////// */


/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

#include <sys/resource.h>

#include <stdio.h>
#include <stdlib.h>


/* /////////////////////////////////////////////////////////////////////////
 * main()
 */

int main(int argc, char *argv[])
{
    ((void)argc);
    ((void)argv);

    {
        struct rusage usage;

        { size_t i; for (i = 0; i < 0xffffff; ++i){} }

        { size_t i; for (i = 0; i < 10; ++i)
        {
            FILE* f = fopen("abc", "w");

            if (NULL != f)
            {
                char    buf[100] = "";
                int     j;

                for (j = 0; j < 100; ++j)
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

