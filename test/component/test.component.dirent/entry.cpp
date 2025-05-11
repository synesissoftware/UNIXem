
#include <dirent.h>

#include <xtests/terse-api.h>

#include <stlsoft/smartptr/scoped_handle.hpp>
#include <winstl/filesystem/readdir_sequence.hpp>

#include <algorithm>
#include <string>
#include <vector>

#include <errno.h>
#include <stdlib.h>
#include <string.h>


namespace {

    void TEST_readdir_CWD_FOR_DIRECTORIES_AND_FILES_AND_DOTS();
    void TEST_readdir_CWD_FOR_DIRECTORIES_AND_FILES_NO_DOTS();
} // anonymous namespace


int main(int argc, char** argv)
{
    int retCode = EXIT_SUCCESS;
    int verbosity = 2;

    XTESTS_COMMANDLINE_PARSE_HELP_OR_VERBOSITY(argc, argv, &verbosity);

    if (XTESTS_START_RUNNER("test.component.dirent", verbosity))
    {
        XTESTS_RUN_CASE(TEST_readdir_CWD_FOR_DIRECTORIES_AND_FILES_AND_DOTS);
        XTESTS_RUN_CASE(TEST_readdir_CWD_FOR_DIRECTORIES_AND_FILES_NO_DOTS);

        XTESTS_PRINT_RESULTS();

        XTESTS_END_RUNNER_UPDATE_EXITCODE(&retCode);
    }

    return retCode;
}


namespace {

    using winstl::readdir_sequence;


void TEST_readdir_CWD_FOR_DIRECTORIES_AND_FILES_AND_DOTS()
{
    readdir_sequence            entries(".", readdir_sequence::directories | readdir_sequence::files | readdir_sequence::includeDots);
    std::vector<std::string>    rds_entries(entries.begin(), entries.end());

    std::sort(rds_entries.begin(), rds_entries.end());

    DIR* const dir = ::opendir(".");

    if (NULL == dir)
    {
        int const e = errno;

#ifdef _MSC_VER
# pragma warning(push)
# pragma warning(disable : 4996)
#endif

        XTESTS_FAIL_WITH_QUALIFIER("failed to `opendir()` on '.'", strerror(e));

#ifdef _MSC_VER
# pragma warning(pop)
#endif
    }
    else
    {
        stlsoft::scoped_handle<DIR*>    scoper(dir, ::closedir);

        std::vector<std::string>        rd_entries;

        for (dirent* de; NULL != (de = ::readdir(dir)); )
        {
            rd_entries.push_back(de->d_name);
        }

        std::sort(rd_entries.begin(), rd_entries.end());

        TEST_INT_EQ(rds_entries.size(), rd_entries.size());

        for (size_t i = 0; rds_entries.size() != i; ++i)
        {
            TEST_MS_EQ(rds_entries[i], rd_entries[i]);
        }
    }
}

void TEST_readdir_CWD_FOR_DIRECTORIES_AND_FILES_NO_DOTS()
{
    readdir_sequence            entries(".", readdir_sequence::directories | readdir_sequence::files);
    std::vector<std::string>    rds_entries(entries.begin(), entries.end());

    std::sort(rds_entries.begin(), rds_entries.end());

    DIR* const dir = ::opendir(".");

    if (NULL == dir)
    {
        int const e = errno;

#ifdef _MSC_VER
# pragma warning(push)
# pragma warning(disable : 4996)
#endif

        XTESTS_FAIL_WITH_QUALIFIER("failed to `opendir()` on '.'", strerror(e));

#ifdef _MSC_VER
# pragma warning(pop)
#endif
    }
    else
    {
        stlsoft::scoped_handle<DIR*>    scoper(dir, ::closedir);

        std::vector<std::string>        rd_entries;

        for (dirent* de; NULL != (de = ::readdir(dir)); )
        {
            if (0 == ::strcmp(".", de->d_name))
            {
                continue;
            }
            if (0 == ::strcmp("..", de->d_name))
            {
                continue;
            }

            rd_entries.push_back(de->d_name);
        }

        std::sort(rd_entries.begin(), rd_entries.end());

        TEST_INT_EQ(rds_entries.size(), rd_entries.size());

        for (size_t i = 0; rds_entries.size() != i; ++i)
        {
            TEST_MS_EQ(rds_entries[i], rd_entries[i]);
        }
    }
}
} // anonymous namespace


/* ///////////////////////////// end of file //////////////////////////// */

