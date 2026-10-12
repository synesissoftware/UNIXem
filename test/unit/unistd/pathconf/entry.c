
#include <xtests/terse-api.h>

#include <unistd.h>

#include <limits.h>
#include <stdlib.h>
#include <windows.h>


int main(int argc, char* argv[])
{
    int retCode = EXIT_SUCCESS;
    int verbosity = 2;

    XTESTS_COMMANDLINE_PARSEVERBOSITY(argc, argv, &verbosity);

    if (XTESTS_START_RUNNER("test.unit.unistd.pathconf", verbosity))
    {
        /* Test-1 */
        if (XTESTS_CASE_BEGIN("Test-1", "testing pathconf"))
        {
            TEST_INT_EQ(LONG_MAX,       pathconf("",          _PC_LINK_MAX));
            TEST_INT_EQ(LONG_MAX,       pathconf("",          _PC_MAX_CANON));
            TEST_INT_EQ(LONG_MAX,       pathconf("",          _PC_MAX_INPUT));
            TEST_INT_EQ(_MAX_FNAME - 1, pathconf("/",         _PC_NAME_MAX));
            TEST_INT_EQ(_MAX_FNAME - 9, pathconf("/01234567", _PC_NAME_MAX));
            TEST_INT_EQ(_MAX_PATH - 1,  pathconf("/",         _PC_PATH_MAX));
            TEST_INT_EQ(_MAX_PATH - 9,  pathconf("/01234567", _PC_PATH_MAX));
            TEST_INT_EQ(-1,             pathconf("",          _PC_PIPE_BUF));
            TEST_INT_EQ(-1,             pathconf("",          _PC_CHOWN_RESTRICTED));
            TEST_INT_EQ(-1,             pathconf("",          _PC_NO_TRUNC));
            TEST_INT_EQ(-1,             pathconf("",          _PC_VDISABLE));
            TEST_INT_EQ(-1,             pathconf("",          _PC_AIX_DISK_PARTITION));
            TEST_INT_EQ(-1,             pathconf("",          _PC_AIX_DISK_SIZE));
            TEST_INT_EQ(-1,             pathconf("",          _PC_FILESIZEBITS));
            TEST_INT_EQ(-1,             pathconf("",          _PC_SYNC_IO));

            XTESTS_CASE_END("Test-1");
        }

        XTESTS_PRINT_RESULTS();

        XTESTS_END_RUNNER_UPDATE_EXITCODE(&retCode);
    }

    return retCode;
}


/* ///////////////////////////// end of file //////////////////////////// */

