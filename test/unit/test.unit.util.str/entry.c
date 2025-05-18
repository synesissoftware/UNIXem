
#include <unixem/util/str.h>

#include <xtests/terse-api.h>

#include <stdlib.h>


static void TEST_begins_with(void);
static void TEST_ends_with(void);
static void TEST_stpcpy(void);
static void TEST_stpncpy(void);

int main(int argc, char* argv[])
{
    int retCode = EXIT_SUCCESS;
    int verbosity = 2;

    XTESTS_COMMANDLINE_PARSEVERBOSITY(argc, argv, &verbosity);

    if (XTESTS_START_RUNNER("test.unit.util.fs", verbosity))
    {
        XTESTS_RUN_CASE(TEST_begins_with);
        XTESTS_RUN_CASE(TEST_ends_with);
        XTESTS_RUN_CASE(TEST_stpcpy);
        XTESTS_RUN_CASE(TEST_stpncpy);

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

static void TEST_stpcpy(void)
{
    {
        char buffer[1];

        {
            char* r1 = unixem_util_str_stpcpy(buffer, "");

            TEST_PTR_EQ(&buffer[0], r1);
        }

        {
            char* r2 = unixem_util_str_stpcpy(buffer, "");

            TEST_PTR_EQ(&buffer[0], r2);
        }
    }

    {
        char buffer[11];

        {
            char* r1 = unixem_util_str_stpcpy(buffer, "abc");

            TEST_PTR_EQ(&buffer[0] + 3, r1);
        }

        {
            char* r2 = unixem_util_str_stpcpy(buffer + 3, "def");

            TEST_PTR_EQ(&buffer[0] + 6, r2);
        }

        {
            char* r3 = unixem_util_str_stpcpy(buffer + 6, "gh");

            TEST_PTR_EQ(&buffer[0] + 8, r3);
        }

        {
            char* r4 = unixem_util_str_stpcpy(buffer + 8, "ij");

            TEST_PTR_EQ(&buffer[0] + 10, r4);
        }

        TEST_MS_EQ("abcdefghij", buffer);
    }

    {
        char buffer[11];

        unixem_util_str_stpcpy(
            unixem_util_str_stpcpy(
                unixem_util_str_stpcpy(
                    unixem_util_str_stpcpy(buffer
                        ,   "abc"
                    ),  "def"
                ),  "gh"
            ),  "ij"
        );

        TEST_MS_EQ("abcdefghij", buffer);
    }
}

static void TEST_stpncpy(void)
{
    {
        char buffer[1];

        {
            char* r1 = unixem_util_str_stpncpy(buffer, "", 0);

            TEST_PTR_EQ(&buffer[0], r1);
        }

        {
            char* r2 = unixem_util_str_stpncpy(buffer, "", 0);

            TEST_PTR_EQ(&buffer[0], r2);
        }
    }

    {
        char buffer[13];

        {
            char* r1 = unixem_util_str_stpncpy(buffer, "abc", 3);

            TEST_PTR_EQ(&buffer[0] + 3, r1);
        }

        {
            char* r2 = unixem_util_str_stpncpy(buffer + 3, "def", 3);

            TEST_PTR_EQ(&buffer[0] + 6, r2);
        }

        {
            char* r3 = unixem_util_str_stpncpy(buffer + 6, "ghXXXX", 2);

            TEST_PTR_EQ(&buffer[0] + 8, r3);
        }

        {
            char* r4 = unixem_util_str_stpncpy(buffer + 8, "ij", 4);

            TEST_PTR_EQ(&buffer[0] + 12, r4);
        }

        TEST_MS_EQ("abcdefghij", buffer);
    }

    {
        char buffer[13];

        unixem_util_str_stpncpy(
            unixem_util_str_stpncpy(
                unixem_util_str_stpncpy(
                    unixem_util_str_stpncpy(buffer
                        ,   "abc",  3
                    ),  "def",  3
                ),  "ghXXXX",   2
            ),  "ij",   4
        );

        TEST_MS_EQ("abcdefghij", buffer);
    }
}
