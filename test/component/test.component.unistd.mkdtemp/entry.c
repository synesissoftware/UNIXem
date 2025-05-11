
/*
 * Created:
 * Updated: 29th November 2024
 */

#include <unistd.h>

#include <xtests/xtests.h>

#include <stdlib.h>

int main(int argc, char** argv)
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

                fprintf(stderr, "mkdtemp() failed: %s (%d)\n", strerror(e), e);
            }
            else
            {
                size_t const len = strlen(template_path);

                rmdir(template_path);

                XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(7u, len));
                XTESTS_TEST_MULTIBYTE_STRING_EQUAL_N("abc.", template_path, 4u);
                XTESTS_TEST_BOOLEAN_TRUE(isdigit(template_path[len - 3]));
                XTESTS_TEST_BOOLEAN_TRUE(isdigit(template_path[len - 2]));
                XTESTS_TEST_BOOLEAN_TRUE(isdigit(template_path[len - 1]));
            }

            XTESTS_CASE_END("Test-1");
        }

        /* Test-2 */
        if (XTESTS_CASE_BEGIN("Test-2", "testing mkdtemp in specific directory"))
        {
            char        template_path[] =   "C:\\temp\\abc.XXXX";
            char const* r               =   mkdtemp(template_path);

            if (NULL == r)
            {
                int const e = errno;

                fprintf(stderr, "mkdtemp() failed: %s (%d)\n", strerror(e), e);
            }
            else
            {
                size_t const len = strlen(template_path);

                rmdir(template_path);

                XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(16u, len));
                XTESTS_TEST_MULTIBYTE_STRING_EQUAL_N("C:\\temp\\abc.", template_path, 12u);
                XTESTS_TEST_BOOLEAN_TRUE(isdigit(template_path[len - 4]));
                XTESTS_TEST_BOOLEAN_TRUE(isdigit(template_path[len - 3]));
                XTESTS_TEST_BOOLEAN_TRUE(isdigit(template_path[len - 2]));
                XTESTS_TEST_BOOLEAN_TRUE(isdigit(template_path[len - 1]));
            }

            XTESTS_CASE_END("Test-2");
        }

        XTESTS_PRINT_RESULTS();

        XTESTS_END_RUNNER_UPDATE_EXITCODE(&retCode);
    }

    return retCode;
}


/* ///////////////////////////// end of file //////////////////////////// */

