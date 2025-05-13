
#include <unixem/util/fs.h>

#include <stlsoft/string/simple_string.hpp>

#include <xtests/terse-api.h>

#include <stdlib.h>
#include <string.h>


namespace {

    void TEST_char_is_path_sep();
} // anonymous namespace

int main(int argc, char* argv[])
{
    int retCode = EXIT_SUCCESS;
    int verbosity = 2;

    XTESTS_COMMANDLINE_PARSEVERBOSITY(argc, argv, &verbosity);

    if (XTESTS_START_RUNNER("test.unit.util.fs", verbosity))
    {
        XTESTS_RUN_CASE(TEST_char_is_path_sep);

        XTESTS_PRINT_RESULTS();

        XTESTS_END_RUNNER_UPDATE_EXITCODE(&retCode);
    }

    return retCode;
}

namespace {

void TEST_char_is_path_sep()
{
    TEST_BOOLEAN_TRUE(unixem_util_fs_char_is_path_sep('/'));
    TEST_BOOLEAN_TRUE(unixem_util_fs_char_is_path_sep('\\'));

    TEST_BOOLEAN_FALSE(unixem_util_fs_char_is_path_sep('\0'));
    TEST_BOOLEAN_FALSE(unixem_util_fs_char_is_path_sep('a'));
    TEST_BOOLEAN_FALSE(unixem_util_fs_char_is_path_sep('Z'));
    TEST_BOOLEAN_FALSE(unixem_util_fs_char_is_path_sep(':'));
    TEST_BOOLEAN_FALSE(unixem_util_fs_char_is_path_sep('|'));
}
} // anonymous namespace

