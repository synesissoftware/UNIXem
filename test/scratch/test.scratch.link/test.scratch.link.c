/* /////////////////////////////////////////////////////////////////////////
 * File:    test.scratch.link.c
 *
 * Purpose: Unit-test of `link()`.
 *
 * Created: 2nd September 2005
 * Updated: 28th November 2024
 *
 * ////////////////////////////////////////////////////////////////////// */


/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

#include <unistd.h>

#include <platformstl/filesystem/path_functions.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/* /////////////////////////////////////////////////////////////////////////
 * forward declarations
 */


/* /////////////////////////////////////////////////////////////////////////
 * main()
 */

int main(int argc, char *argv[])
{
    char const* const   program_name    =   platformstl_C_get_executable_name_from_path(argv[0]).ptr;
    char const*         module_name;
    char const*         symbol_name;

    { int i; for (i = 1; i != argc; ++i)
    {
        if (0 == strcmp("--help", argv[i]))
        {
            printf("USAGE: %s <source-path> <link-path>\n", program_name);

            return EXIT_SUCCESS;
        }
    }}

    switch (argc)
    {
    case 1:
    case 2:

        fprintf(stderr, "%s: missing arguments; use --help for usage\n", program_name);

        return EXIT_FAILURE;
    case 3:

        module_name = argv[1];
        symbol_name = argv[2];
        break;
    default:

        fprintf(stderr, "%s: too many arguments; use --help for usage\n", program_name);

        return EXIT_FAILURE;
    }

    if (argc < 3)
    {
        fprintf(stderr, "USAGE: test.scratch.link <originalFile> <linkName>\n");

        return EXIT_FAILURE;
    }
    else
    {
        int const res = link(module_name, symbol_name);

        if (0 == res)
        {
            fprintf(stdout, "\"%s\" => \"%s\"\n", module_name, symbol_name);

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

