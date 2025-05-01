/* /////////////////////////////////////////////////////////////////////////
 * File:    test.component.unistd.usleep/entry.cpp
 *
 * Purpose: Unit-test of `usleep()`.
 *
 * Created: 29th November 2024
 * Updated: 29th November 2024
 *
 * ////////////////////////////////////////////////////////////////////// */


/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

#include <unistd.h>

#include <xtests/terse-api.h>

#include <platformstl/diagnostics/stopwatch.hpp>
#include <stlsoft/diagnostics/doomgram.hpp>
#include <stlsoft/diagnostics/gram_scope.hpp>


/* /////////////////////////////////////////////////////////////////////////
 * forward declarations
 */

namespace
{

    void TEST_TIME_ZERO();
    void TEST_S_1();
    void TEST_MS_100();
} // anonymous namespace


/* /////////////////////////////////////////////////////////////////////////
 * main()
 */

int main(int argc, char **argv)
{
    int retCode = EXIT_SUCCESS;
    int verbosity = 2;

    XTESTS_COMMANDLINE_PARSEVERBOSITY(argc, argv, &verbosity);

    if (XTESTS_START_RUNNER("test.component.unistd.usleep", verbosity))
    {
        XTESTS_RUN_CASE(TEST_TIME_ZERO);
        XTESTS_RUN_CASE(TEST_S_1);
        XTESTS_RUN_CASE(TEST_MS_100);

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

void TEST_TIME_ZERO()
{
    platformstl::stopwatch  sw;
    stlsoft::doomgram       gram;

    {
        stlsoft::gram_scope<
            stlsoft::doomgram
        ,   platformstl::stopwatch
        >   scope(gram, sw);

        usleep(0);
    }

    platformstl::stopwatch::interval_type const total_time_ns = gram.total_event_time_ns_raw();

    XTESTS_TEST_INTEGER_GREATER_OR_EQUAL(0, total_time_ns);
    XTESTS_TEST_INTEGER_LESS_OR_EQUAL(100000, total_time_ns);
}

void TEST_S_1()
{
    platformstl::stopwatch  sw;
    stlsoft::doomgram       gram;

    {
        stlsoft::gram_scope<
            stlsoft::doomgram
        ,   platformstl::stopwatch
        >   scope(gram, sw);

        usleep(1000000);
    }

    platformstl::stopwatch::interval_type const total_time_ns = gram.total_event_time_ns_raw();

    XTESTS_TEST_INTEGER_GREATER_OR_EQUAL(1000000000, total_time_ns);
    XTESTS_TEST_INTEGER_LESS_OR_EQUAL(1100000000, total_time_ns);
}

void TEST_MS_100()
{
    platformstl::stopwatch  sw;
    stlsoft::doomgram       gram;

    {
        stlsoft::gram_scope<
            stlsoft::doomgram
        ,   platformstl::stopwatch
        >   scope(gram, sw);

        usleep(100000);
    }

    platformstl::stopwatch::interval_type const total_time_ns = gram.total_event_time_ns_raw();

    XTESTS_TEST_INTEGER_GREATER_OR_EQUAL(100000000, total_time_ns);
    XTESTS_TEST_INTEGER_LESS_OR_EQUAL(150000000, total_time_ns);
}
} // anonymous namespace


/* ///////////////////////////// end of file //////////////////////////// */

