
#include <unixem/util/str.h>

#include <xtests/terse-api.h>


static void TEST_begins_with(void);
static void TEST_ends_with(void);

int main(int argc, char* argv[])
{
    int retCode = EXIT_SUCCESS;
    int verbosity = 2;

    XTESTS_COMMANDLINE_PARSEVERBOSITY(argc, argv, &verbosity);

    if (XTESTS_START_RUNNER("test.unit.util.fs", verbosity))
    {
        XTESTS_RUN_CASE(TEST_begins_with);
        XTESTS_RUN_CASE(TEST_ends_with);

        XTESTS_PRINT_RESULTS();

        XTESTS_END_RUNNER_UPDATE_EXITCODE(&retCode);
    }

    return retCode;
}

static void TEST_begins_with(void)
{
    {
        TEST_INT_EQ(1, unixem_util_str_begins_with("", ""));
        TEST_INT_EQ(0, unixem_util_str_begins_with("", "abc"));
        TEST_INT_EQ(1, unixem_util_str_begins_with("abc", ""));
    }

    {
        TEST_INT_EQ(1, unixem_util_str_begins_with("abc", "abc"));
        TEST_INT_EQ(1, unixem_util_str_begins_with("abc", "ab"));
        TEST_INT_EQ(1, unixem_util_str_begins_with("abc", "a"));
        TEST_INT_EQ(0, unixem_util_str_begins_with("abc", "abd"));
        TEST_INT_EQ(0, unixem_util_str_begins_with("abc", "ad"));
    }

    {
        TEST_INT_EQ(1, unixem_util_str_begins_with("abcdefghijklmnopqrstuvwxyz", "abc"));
        TEST_INT_EQ(1, unixem_util_str_begins_with("abcdefghijklmnopqrstuvwxyz", "ab"));
        TEST_INT_EQ(1, unixem_util_str_begins_with("abcdefghijklmnopqrstuvwxyz", "a"));
        TEST_INT_EQ(0, unixem_util_str_begins_with("abcdefghijklmnopqrstuvwxyz", "abd"));
        TEST_INT_EQ(0, unixem_util_str_begins_with("abcdefghijklmnopqrstuvwxyz", "ad"));
    }
}

static void TEST_ends_with(void)
{
    {
        TEST_INT_EQ(1, unixem_util_str_ends_with("", ""));
        TEST_INT_EQ(0, unixem_util_str_ends_with("", "abc"));
        TEST_INT_EQ(1, unixem_util_str_ends_with("abc", ""));
    }

    {
        TEST_INT_EQ(1, unixem_util_str_ends_with("abc", "abc"));
        TEST_INT_EQ(1, unixem_util_str_ends_with("abc", "bc"));
        TEST_INT_EQ(1, unixem_util_str_ends_with("abc", "c"));
        TEST_INT_EQ(0, unixem_util_str_ends_with("abc", "bbc"));
        TEST_INT_EQ(0, unixem_util_str_ends_with("abc", "ac"));
    }
}

