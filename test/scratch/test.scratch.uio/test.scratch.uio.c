/* /////////////////////////////////////////////////////////////////////////
 * File:    test.scratch.uio.c
 *
 * Purpose: Unit-test of `uio()`.
 *
 * Created: 19th September 2005
 * Updated: 29th November 2024
 *
 * ////////////////////////////////////////////////////////////////////// */


#include <sys/uio.h>

#include <platformstl/filesystem/path_functions.h>

#include <fcntl.h>
#include <io.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


/* /////////////////////////////////////////////////////////////////////////
 * main()
 */

static int main_(int argc, char **argv)
{
    char const* const program_name = platformstl_C_get_executable_name_from_path(argv[0]).ptr;

    { int i; for (i = 1; i != argc; ++i)
    {
        if (0 == strcmp("--help", argv[i]))
        {
            printf("USAGE: %s <file-name>\n", program_name);

            return EXIT_SUCCESS;
        }
    }}

    switch (argc)
    {
    case 1:

        fprintf(stderr, "%s: missing argument; use --help for usage\n", program_name);

        return EXIT_FAILURE;
    case 2:

        break;
    default:

        fprintf(stderr, "%s: too many arguments; use --help for usage\n", program_name);

        return EXIT_FAILURE;
    }

    {
        char const*     fileName    =   argv[1];
        int             fd          =   _open(fileName, _O_RDONLY);
        struct iovec    vectors[3];
        char            sz1[10];
        char            sz2[2];
        char            sz3[21];
        unixem_ssize_t  n;

        vectors[0].iov_base =   &sz1[0];
        vectors[0].iov_len  =   sizeof(sz1);
        vectors[1].iov_base =   &sz2[0];
        vectors[1].iov_len  =   sizeof(sz2);
        vectors[2].iov_base =   &sz3[0];
        vectors[2].iov_len  =   sizeof(sz3);

        n                   =   readv(fd, &vectors[0], 3);

        if (n < 0)
        {
            fprintf(stderr, "%s: failed to invoke `readv()` on '%s': %ld\n", program_name, fileName, (long)n);
        }
        else
        {
            printf("read following block sizes by `readv()` from '%s': %llu, %llu, %llu; total-read=%ld\n", fileName, vectors[0].iov_len, vectors[1].iov_len, vectors[2].iov_len, (long)n);

            close(fd);
        }
    }

    return 0;
}

int main(int argc, char *argv[])
{
    return main_(argc, argv);
}


/* ///////////////////////////// end of file //////////////////////////// */

