
/*
 * Created: ...
 * Updated: 12th October 2026
 */

#include <unistd.h>

#include <xtests/terse-api.h>

#include <unixem/util/fs.h>

#include <stdlib.h>


int main(int argc, char* argv[])
{
    int retCode = EXIT_SUCCESS;
    int verbosity = 2;

    XTESTS_COMMANDLINE_PARSEVERBOSITY(argc, argv, &verbosity);

    if (XTESTS_START_RUNNER("test.component.unistd.mkdtemp", verbosity))
    {
        /* Test-1 */
        if (XTESTS_CASE_BEGIN("Test-1", "testing mkdtemp in local directory"))
        {
            char        template_path[] =   "abc.XXX";
            char const* r               =   mkdtemp(template_path);

            if (NULL == r)
            {
                int const e = errno;

                fprintf(stderr, "mkdtemp() failed to create '%s': %s (%d)\n", template_path, strerror(e), e);
            }
            else
            {
                size_t const len = strlen(template_path);

                rmdir(template_path);

                XTESTS_REQUIRE(TEST_INT_EQ(7u, len));
                TEST_MS_EQ_N("abc.", template_path, 4u);
                TEST_BOOLEAN_TRUE(isdigit(template_path[len - 3]));
                TEST_BOOLEAN_TRUE(isdigit(template_path[len - 2]));
                TEST_BOOLEAN_TRUE(isdigit(template_path[len - 1]));
            }

            XTESTS_CASE_END("Test-1");
        }

        /* Test-2 */
        if (XTESTS_CASE_BEGIN("Test-2", "testing mkdtemp in specific directory"))
        {
            if (unixem_util_fs_directory_exists("C:\\temp"))
            {
                char        template_path[] =   "C:\\temp\\abc.XXXX";
                char const* r               =   mkdtemp(template_path);

                if (NULL == r)
                {
                    int const e = errno;

                    fprintf(stderr, "mkdtemp() failed to create '%s': %s (%d)\n", template_path, strerror(e), e);
                }
                else
                {
                    size_t const len = strlen(template_path);

                    rmdir(template_path);

                    XTESTS_REQUIRE(TEST_INT_EQ(16u, len));
                    TEST_MS_EQ_N("C:\\temp\\abc.", template_path, 12u);
                    TEST_BOOLEAN_TRUE(isdigit(template_path[len - 4]));
                    TEST_BOOLEAN_TRUE(isdigit(template_path[len - 3]));
                    TEST_BOOLEAN_TRUE(isdigit(template_path[len - 2]));
                    TEST_BOOLEAN_TRUE(isdigit(template_path[len - 1]));
                }
            }

            XTESTS_CASE_END("Test-2");
        }

        XTESTS_PRINT_RESULTS();

        XTESTS_END_RUNNER_UPDATE_EXITCODE(&retCode);
    }

    return retCode;
}


/* ///////////////////////////// end of file //////////////////////////// */

