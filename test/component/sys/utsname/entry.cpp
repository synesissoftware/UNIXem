/* /////////////////////////////////////////////////////////////////////////
 * File:    test/component/sys/utsname/entry.cpp
 *
 * Purpose: Component test of uname().
 *
 * Created: 12th October 2026
 * Updated: 14th October 2026
 *
 * ////////////////////////////////////////////////////////////////////// */


/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

#include <sys/utsname.h>

#include <xtests/terse-api.h>

#include <string.h>


/* /////////////////////////////////////////////////////////////////////////
 * forward declarations
 */

namespace
{
    void TEST_UNAME_CALL();
} // anonymous namespace


/* /////////////////////////////////////////////////////////////////////////
 * main()
 */

int main(int argc, char* argv[])
{
    int retCode = EXIT_SUCCESS;
    int verbosity = 2;

    XTESTS_COMMANDLINE_PARSEVERBOSITY(argc, argv, &verbosity);

    if (XTESTS_START_RUNNER("test.component.sys.utsname", verbosity))
    {
        XTESTS_RUN_CASE(TEST_UNAME_CALL);

        XTESTS_PRINT_RESULTS();

        XTESTS_END_RUNNER_UPDATE_EXITCODE(&retCode);
    }

    return retCode;
}


/* /////////////////////////////////////////////////////////////////////////
 * test function implementations
 */

namespace
{

void TEST_UNAME_CALL()
{
    struct utsname name;

    memset(&name, 0, sizeof(name));

    /* call uname and verify success */
    int const r = uname(&name);

    XTESTS_TEST_INTEGER_EQUAL(0, r);

    /* sysname should be non-empty and start with "Windows" */
    XTESTS_TEST_INTEGER_GREATER(0, ::strlen(name.sysname));
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("Windows", name.sysname);

    /* nodename should be non-empty */
    XTESTS_TEST_INTEGER_GREATER(0, ::strlen(name.nodename));

    /* release should be non-empty */
    XTESTS_TEST_INTEGER_GREATER(0, ::strlen(name.release));

    /* version should be non-empty */
    XTESTS_TEST_INTEGER_GREATER(0, ::strlen(name.version));

    /* machine should be non-empty */
    XTESTS_TEST_INTEGER_GREATER(0, ::strlen(name.machine));
}

} // anonymous namespace


/* ///////////////////////////// end of file //////////////////////////// */

