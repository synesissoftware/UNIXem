/* /////////////////////////////////////////////////////////////////////////
 * File:    test.scratch.dlfcn.c
 *
 * Purpose: Unit-test of `dlopen()`, `dlsym()`, `dlclose()`.
 *
 * Created: 1st January 2004
 * Updated: 4th August 2026
 *
 * ////////////////////////////////////////////////////////////////////// */


/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

#include <dlfcn.h>

#include <platformstl/filesystem/path_functions.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/* /////////////////////////////////////////////////////////////////////////
 * constants
 */

/* Defaults so bare invocation (e.g. run_all_scratch_tests.sh) is a useful smoke. */
#define TEST_SCRATCH_DLFCN_DEFAULT_MODULE   "kernel32.dll"
#define TEST_SCRATCH_DLFCN_DEFAULT_SYMBOL   "GetCurrentProcessId"


/* /////////////////////////////////////////////////////////////////////////
 * main()
 */

int main(int argc, char *argv[])
{
    char const* const program_name = platformstl_C_get_executable_name_from_path(argv[0]).ptr;
    char const*       module_name;
    char const*       symbol_name;

    { int i; for (i = 1; i != argc; ++i)
    {
        if (0 == strcmp("--help", argv[i]))
        {
            printf("USAGE: %s [ <module-name> <symbol-name> ]\n", program_name);
            printf("  defaults: %s %s\n", TEST_SCRATCH_DLFCN_DEFAULT_MODULE, TEST_SCRATCH_DLFCN_DEFAULT_SYMBOL);

            return EXIT_SUCCESS;
        }
    }}

    switch (argc)
    {
    case 1:

        module_name = TEST_SCRATCH_DLFCN_DEFAULT_MODULE;
        symbol_name = TEST_SCRATCH_DLFCN_DEFAULT_SYMBOL;
        break;
    case 3:

        module_name = argv[1];
        symbol_name = argv[2];
        break;
    case 2:

        fprintf(stderr, "%s: missing arguments; use --help for usage\n", program_name);

        return EXIT_FAILURE;
    default:

        fprintf(stderr, "%s: too many arguments; use --help for usage\n", program_name);

        return EXIT_FAILURE;
    }

    {
        void* const module = dlopen(module_name, RTLD_NOW);

        if (NULL == module)
        {
            fprintf(stderr
            ,   "%s: failed to open module '%s': %s\n"
            ,   program_name
            ,   module_name
            ,   dlerror()
            );

            return EXIT_FAILURE;
        }
        else
        {
            void* const symbol  =   dlsym(module, symbol_name);
            int         r       =   EXIT_SUCCESS;

            if (NULL == symbol)
            {
                fprintf(stderr
                ,   "%s: failed to retrieve symbol '%s' in '%s': %s\n"
                ,   program_name
                ,   symbol_name
                ,   module_name
                ,   dlerror()
                );

                r = EXIT_FAILURE;
            }
            else
            {
                printf("found symbol '%s' at address %p in '%s'\n"
                ,   symbol_name
                ,   symbol
                ,   module_name
                );
            }

            dlclose(module);

            return r;
        }
    }
}


/* ///////////////////////////// end of file //////////////////////////// */
