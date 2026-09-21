/* /////////////////////////////////////////////////////////////////////////
 * File:    test.scratch.link.c
 *
 * Purpose: Unit-test of `link()`.
 *
 * Created: 2nd September 2005
 * Updated: 4th August 2026
 *
 * ////////////////////////////////////////////////////////////////////// */


/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

#include <unistd.h>

#include <platformstl/filesystem/path_functions.h>

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/* /////////////////////////////////////////////////////////////////////////
 * main()
 */

int main(int argc, char *argv[])
{
    char const* const   program_name    =   platformstl_C_get_executable_name_from_path(argv[0]).ptr;
    char const*         source_path;
    char const*         link_path;
    char                default_source[64];
    char                default_link[64];
    int                 using_defaults  =   0;
    int                 r               =   EXIT_FAILURE;

    { int i; for (i = 1; i != argc; ++i)
    {
        if (0 == strcmp("--help", argv[i]))
        {
            printf("USAGE: %s [ <source-path> <link-path> ]\n", program_name);
            printf("  with no arguments, creates and links a pair of temporary files\n");

            return EXIT_SUCCESS;
        }
    }}

    switch (argc)
    {
    case 1:

        sprintf(default_source, "unixem-scratch-link-src-%d.tmp", (int)getpid());
        sprintf(default_link, "unixem-scratch-link-dst-%d.tmp", (int)getpid());

        {
            FILE* const f = fopen(default_source, "wb");

            if (NULL == f)
            {
                fprintf(stderr, "%s: failed to create temporary source '%s': %s\n", program_name, default_source, strerror(errno));

                return EXIT_FAILURE;
            }

            if (1 != fwrite("x", 1, 1, f))
            {
                fclose(f);
                remove(default_source);

                fprintf(stderr, "%s: failed to write temporary source '%s'\n", program_name, default_source);

                return EXIT_FAILURE;
            }

            fclose(f);
        }

        source_path = default_source;
        link_path = default_link;
        using_defaults = 1;
        break;
    case 3:

        source_path = argv[1];
        link_path = argv[2];
        break;
    case 2:

        fprintf(stderr, "%s: missing arguments; use --help for usage\n", program_name);

        return EXIT_FAILURE;
    default:

        fprintf(stderr, "%s: too many arguments; use --help for usage\n", program_name);

        return EXIT_FAILURE;
    }

    {
        int const res = link(source_path, link_path);

        if (0 == res)
        {
            fprintf(stdout, "\"%s\" => \"%s\"\n", source_path, link_path);

            r = EXIT_SUCCESS;
        }
        else
        {
            fprintf(stderr, "link() failed: %d (%s)\n", errno, strerror(errno));

            r = EXIT_FAILURE;
        }
    }

    if (using_defaults)
    {
        remove(link_path);
        remove(source_path);
    }

    return r;
}


/* ///////////////////////////// end of file //////////////////////////// */

