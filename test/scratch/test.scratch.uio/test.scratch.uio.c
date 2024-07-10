/* /////////////////////////////////////////////////////////////////////////
 * File:    test.scratch.uio.c
 *
 * Purpose: Unit-test of `uio()`.
 *
 * Created: 19th September 2005
 * Updated: 10th July 2024
 *
 * ////////////////////////////////////////////////////////////////////// */


/* Standard C header files */
#include <fcntl.h>
#include <io.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
//#include <sys/stat.h>
#include <sys/uio.h>


/* /////////////////////////////////////////////////////////////////////////
 * forward declarations
 */


/* /////////////////////////////////////////////////////////////////////////
 * main()
 */

static int main_(int argc, char **argv)
{
    /* . */
    if (argc < 2)
    {
        fprintf(stderr, "Must specify file\n");
    }
    else
    {
        char const*     fileName    =   argv[1];
        int             fd          =   _open(fileName, _O_RDONLY);
        struct iovec    vectors[3];
        char            sz1[10];
        char            sz2[2];
        char            sz3[21];
        size_t          n;

        vectors[0].iov_base =   &sz1[0];
        vectors[0].iov_len  =   sizeof(sz1);
        vectors[1].iov_base =   &sz2[0];
        vectors[1].iov_len  =   sizeof(sz2);
        vectors[2].iov_base =   &sz3[0];
        vectors[2].iov_len  =   sizeof(sz3);

        n                   =   readv(fd, &vectors[0], 3);
    }

    return 0;
}

int main(int argc, char *argv[])
{
    return main_(argc, argv);
}


/* ///////////////////////////// end of file //////////////////////////// */

