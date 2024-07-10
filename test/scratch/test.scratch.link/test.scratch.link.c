/* /////////////////////////////////////////////////////////////////////////
 * File:    test.scratch.link.c
 *
 * Purpose: Unit-test of `link()`.
 *
 * Created: 2nd September 2005
 * Updated: 10th July 2024
 *
 * ////////////////////////////////////////////////////////////////////// */


/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

/* UNIXem header files */
#include <unixem/unixem.h>

/* Standard C header files */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>


/* /////////////////////////////////////////////////////////////////////////
 * forward declarations
 */


/* /////////////////////////////////////////////////////////////////////////
 * main()
 */

int main(int argc, char *argv[])
{
#if 0
    { for(size_t i = 0; i < 0xffffffff; ++i){} }
#endif /* 0 */

    if (argc < 3)
    {
        fprintf(stderr, "USAGE: test.scratch.link <originalFile> <linkName>\n");

        return EXIT_FAILURE;
    }
    else
    {
        int res =   link(argv[1], argv[2]);

        if (0 == res)
        {
            fprintf(stdout, "\"%s\" => \"%s\"\n", argv[1], argv[2]);

            return EXIT_SUCCESS;
        }
        else
        {
            fprintf(stderr, "link() failed: %d (%s)\n", errno, strerror(errno));

            return EXIT_FAILURE;
        }
    }
}


/* ///////////////////////////// end of file //////////////////////////// */

