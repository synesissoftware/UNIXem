
#include <unixem/util/fs.h>

#include <stlsoft/string/simple_string.hpp>

#include <xtests/terse-api.h>

#include <platformstl/system/environment_variable_scope.hpp>

#include <errno.h>
#include <stdlib.h>
#include <string.h>

#include <windows.h>


namespace {

    /* 259 characters long */
    char const path_MAX_PATH[] = "X:\\Users\\abcdefghij012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789";

    /* 257 characters long */
    char const directory_MAX_PATH_less_2[] = "\\Users\\abcdefghij012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789";

    /* 258 characters long */
    char const directory_MAX_PATH_less_1[] = "\\Users\\abcdefghij0123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890";
} // anonymous namespace

namespace {

    void TEST_char_is_path_sep();
    void TEST_directory_exists();
    void TEST_get_home_directory_REAL();
    void TEST_get_home_directory_SYNTHETIC_NOT_FOUND();
    void TEST_get_home_directory_SYNTHETIC_userprofile();
    void TEST_get_home_directory_SYNTHETIC_userprofile_MAXPATH();
    void TEST_get_home_directory_SYNTHETIC_homedrive_AND_homepath();
    void TEST_get_home_directory_SYNTHETIC_homedrive_AND_homepath_MAXPATH();
    void TEST_get_home_directory_SYNTHETIC_homedrive_AND_homepath_MAXPATH_PLUS_1();
} // anonymous namespace

int main(int argc, char* argv[])
{
    int retCode = EXIT_SUCCESS;
    int verbosity = 2;

    XTESTS_COMMANDLINE_PARSEVERBOSITY(argc, argv, &verbosity);

    if (XTESTS_START_RUNNER("test.unit.util.fs", verbosity))
    {
        XTESTS_RUN_CASE(TEST_char_is_path_sep);
        XTESTS_RUN_CASE(TEST_directory_exists);
        XTESTS_RUN_CASE(TEST_get_home_directory_REAL);
        XTESTS_RUN_CASE(TEST_get_home_directory_SYNTHETIC_NOT_FOUND);
        XTESTS_RUN_CASE(TEST_get_home_directory_SYNTHETIC_userprofile);
        XTESTS_RUN_CASE(TEST_get_home_directory_SYNTHETIC_userprofile_MAXPATH);
        XTESTS_RUN_CASE(TEST_get_home_directory_SYNTHETIC_homedrive_AND_homepath);
        XTESTS_RUN_CASE(TEST_get_home_directory_SYNTHETIC_homedrive_AND_homepath_MAXPATH);
        XTESTS_RUN_CASE(TEST_get_home_directory_SYNTHETIC_homedrive_AND_homepath_MAXPATH_PLUS_1);

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

void TEST_directory_exists()
{
    TEST_BOOLEAN_TRUE(unixem_util_fs_directory_exists("."));
    TEST_BOOLEAN_TRUE(unixem_util_fs_directory_exists("/"));
    TEST_BOOLEAN_TRUE(unixem_util_fs_directory_exists("C:\\"));
#if 0

    TEST_BOOLEAN_TRUE(unixem_util_fs_directory_exists("\\\\?\\C:\\"));
#endif

    TEST_BOOLEAN_FALSE(unixem_util_fs_directory_exists(""));
    TEST_BOOLEAN_FALSE(unixem_util_fs_directory_exists("|"));
    TEST_BOOLEAN_FALSE(unixem_util_fs_directory_exists("|/"));
    TEST_BOOLEAN_FALSE(unixem_util_fs_directory_exists("|C:\\"));
    TEST_BOOLEAN_FALSE(unixem_util_fs_directory_exists("X:/-does-not-exist-/-does-not-exist-/-does-not-exist-/-does-not-exist-"));
}

void TEST_get_home_directory_REAL()
{
    char        buff[_MAX_PATH];
    size_t      n;
    int const   r = unixem_util_fs_get_home_directory(&buff, &n);

    if (0 == r)
    {
        int const e = errno;

        XTESTS_FAIL_WITH_QUALIFIER("could not obtain home directory", strerror(e));
    }
    else
    {
        stlsoft::simple_string const homedir(getenv("HOME"));

        TEST_INT_EQ(homedir.length(), n);
        TEST_MS_EQ(homedir, buff);
    }
}

void TEST_get_home_directory_SYNTHETIC_NOT_FOUND()
{
    {
        platformstl::environment_variable_scope scoper_USERPROFILE("USERPROFILE", NULL);
        platformstl::environment_variable_scope scoper_HOMEDRIVE("HOMEDRIVE", NULL);
        platformstl::environment_variable_scope scoper_HOMEPATH("HOMEPATH", "\\Users\\me");

        errno = 0;
        ::SetLastError(ERROR_SUCCESS);

        {
            char        buff[_MAX_PATH];
            size_t      n;
            int const   r   =   unixem_util_fs_get_home_directory(&buff, &n);
            int const   e   =   errno;

            TEST_INT_EQ(0, r);
            TEST_INT_EQ(ENOENT, e);
            TEST_INT_EQ(ERROR_ENVVAR_NOT_FOUND, ::GetLastError());
        }
    }
}

void TEST_get_home_directory_SYNTHETIC_userprofile()
{
    {
        platformstl::environment_variable_scope scoper_USERPROFILE("USERPROFILE", "X:\\Users\\me");

        errno = 0;
        ::SetLastError(ERROR_SUCCESS);

        {
            char        buff[_MAX_PATH];
            size_t      n;
            int const   r = unixem_util_fs_get_home_directory(&buff, &n);

            if (0 == r)
            {
                int const e = errno;

                XTESTS_FAIL_WITH_QUALIFIER("could not obtain home directory", strerror(e));
            }
            else
            {
                TEST_INT_EQ(0, errno);
                TEST_INT_EQ(0, ::GetLastError());

                TEST_INT_EQ(11, n);
                TEST_MS_EQ("X:\\Users\\me", buff);
            }
        }
    }
}

void TEST_get_home_directory_SYNTHETIC_userprofile_MAXPATH()
{
    {
        platformstl::environment_variable_scope scoper_USERPROFILE("USERPROFILE", path_MAX_PATH);

        errno = 0;
        ::SetLastError(ERROR_SUCCESS);

        {
            char        buff[_MAX_PATH];
            size_t      n;
            int const   r = unixem_util_fs_get_home_directory(&buff, &n);

            if (0 == r)
            {
                int const e = errno;

                XTESTS_FAIL_WITH_QUALIFIER("could not obtain home directory", strerror(e));
            }
            else
            {
                TEST_INT_EQ(0, errno);
                TEST_INT_EQ(0, ::GetLastError());

                TEST_INT_EQ(_MAX_PATH - 1, n);
                TEST_MS_EQ(path_MAX_PATH, buff);
            }
        }
    }
}

void TEST_get_home_directory_SYNTHETIC_homedrive_AND_homepath()
{
    {
        platformstl::environment_variable_scope scoper_USERPROFILE("USERPROFILE", NULL);
        platformstl::environment_variable_scope scoper_HOMEDRIVE("HOMEDRIVE", "X:");
        platformstl::environment_variable_scope scoper_HOMEPATH("HOMEPATH", "\\Users\\me");

        errno = 0;
        ::SetLastError(ERROR_SUCCESS);

        {
            char        buff[_MAX_PATH];
            size_t      n;
            int const   r = unixem_util_fs_get_home_directory(&buff, &n);

            if (0 == r)
            {
                int const e = errno;

                XTESTS_FAIL_WITH_QUALIFIER("could not obtain home directory", strerror(e));
            }
            else
            {
                TEST_INT_EQ(0, errno);
                TEST_INT_EQ(0, ::GetLastError());

                TEST_INT_EQ(11, n);
                TEST_MS_EQ("X:\\Users\\me", buff);
            }
        }
    }
}

void TEST_get_home_directory_SYNTHETIC_homedrive_AND_homepath_MAXPATH()
{
    {
        platformstl::environment_variable_scope scoper_USERPROFILE("USERPROFILE", NULL);
        platformstl::environment_variable_scope scoper_HOMEDRIVE("HOMEDRIVE", "X:");
        platformstl::environment_variable_scope scoper_HOMEPATH("HOMEPATH", directory_MAX_PATH_less_2);

        errno = 0;
        ::SetLastError(ERROR_SUCCESS);

        {
            char        buff[_MAX_PATH];
            size_t      n;
            int const   r = unixem_util_fs_get_home_directory(&buff, &n);

            if (0 == r)
            {
                int const e = errno;

                XTESTS_FAIL_WITH_QUALIFIER("could not obtain home directory", strerror(e));
            }
            else
            {
                TEST_INT_EQ(0, errno);
                TEST_INT_EQ(0, ::GetLastError());

                TEST_INT_EQ(_MAX_PATH - 1, n);
                TEST_MS_EQ(path_MAX_PATH, buff);
            }
        }
    }
}

void TEST_get_home_directory_SYNTHETIC_homedrive_AND_homepath_MAXPATH_PLUS_1()
{
    {
        platformstl::environment_variable_scope scoper_USERPROFILE("USERPROFILE", NULL);
        platformstl::environment_variable_scope scoper_HOMEDRIVE("HOMEDRIVE", "X:");
        platformstl::environment_variable_scope scoper_HOMEPATH("HOMEPATH", directory_MAX_PATH_less_1);

        errno = 0;
        ::SetLastError(ERROR_SUCCESS);

        {
            char        buff[_MAX_PATH];
            size_t      n;
            int const   r   =   unixem_util_fs_get_home_directory(&buff, &n);
            int const   e   =   errno;

            TEST_INT_EQ(0, r);
            TEST_INT_EQ(ENOMEM, e);
            TEST_INT_EQ(ERROR_INSUFFICIENT_BUFFER, ::GetLastError());
        }
    }
}
} // anonymous namespace

