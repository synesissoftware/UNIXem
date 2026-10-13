
#include <xtests/terse-api.h>

#include <unistd.h>

/* Include after <unistd.h> to lock the VC++ <process.h> / getpid
 * coexistence fix (unistd.h must include <process.h> first).
 */
#include <process.h>

#include <stdlib.h>
#include <windows.h>


int main(int argc, char* argv[])
{
    int retCode = EXIT_SUCCESS;
    int verbosity = 2;

    XTESTS_COMMANDLINE_PARSEVERBOSITY(argc, argv, &verbosity);

    if (XTESTS_START_RUNNER("test.unit.unistd.getpid", verbosity))
    {
        /* Test-1 */
        if (XTESTS_CASE_BEGIN("Test-1", "testing getpid"))
        {
            TEST_INT_EQ((pid_t)GetCurrentProcessId(), getpid());

            XTESTS_CASE_END("Test-1");
        }

        /* Test-2 */
        if (XTESTS_CASE_BEGIN("Test-2", "getpid agrees with _getpid"))
        {
            TEST_INT_EQ((pid_t)_getpid(), getpid());

            XTESTS_CASE_END("Test-2");
        }

        XTESTS_PRINT_RESULTS();

        XTESTS_END_RUNNER_UPDATE_EXITCODE(&retCode);
    }

    return retCode;
}


/* ///////////////////////////// end of file //////////////////////////// */

