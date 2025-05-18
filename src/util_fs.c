
/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

#include <unixem/util/fs.h>

#include <unixem/util/str.h>
#include <unixem/internal/util.h>

#include <windows.h>


/* /////////////////////////////////////////////////////////////////////////
 * API functions
 */

int
unixem_util_fs_char_is_path_sep(char ch)
{
    switch (ch)
    {
    case '/':
    case '\\':

        return 1;
    default:

        return 0;
    }
}

int
unixem_util_fs_directory_exists(char const* path)
{
    DWORD const fa = GetFileAttributesA(path);

    if (INVALID_FILE_ATTRIBUTES == fa)
    {
        /* no such entry */

        return 0;
    }
    else
    {
        if (0 != (FILE_ATTRIBUTE_DIRECTORY & fa))
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
}

int
unixem_util_fs_get_home_directory(
    char  (*ar)[_MAX_PATH]
,   size_t* pnumWritten
)
{
    size_t dummy;

    if (NULL == pnumWritten)
    {
        pnumWritten = &dummy;
    }

    (*ar)[0] = '\0';
    *pnumWritten = 0;

    /* First, try "%USERPROFILE%" */
    DWORD const dw_up = GetEnvironmentVariableA("USERPROFILE", &(*ar)[0], _MAX_PATH);

    if (0 == dw_up)
    {
        // DWORD const le_up = GetLastError();

        SetLastError(0);

        /* Second, try "%HOMEDRIVE%%HOMEPATH%"
         *
         * Because `ExpandEnvironmentStringsA()` requires 1 extra byte for a
         * terminating NUL we try into the given _MAX_PATH-length buffer and
         * take the (very slight) "risk" of having to repeat into a buffer
         * of length (1+_MAX_PATH) and then copying back in.
         */

        DWORD const dw_ees = ExpandEnvironmentStringsA("%HOMEDRIVE%%HOMEPATH%", &(*ar)[0], _MAX_PATH);

        if (0 == dw_ees)
        {
env_var_not_found:

            {
                DWORD const le = ERROR_ENVVAR_NOT_FOUND;

                SetLastError(le);

                errno = unixem_internal_errno_from_Win32(le);

                return 0;
            }
        }
        else
        {
            if (dw_ees > _MAX_PATH + 1)
            {
insufficient_buffer:

                {
                    DWORD const le = ERROR_INSUFFICIENT_BUFFER;

                    SetLastError(le);

                    errno = unixem_internal_errno_from_Win32(le);

                    return 0;
                }
            }
            else
            if (dw_ees == _MAX_PATH + 1)
            {
                /* NODE: `ExpandEnvironmentStringsA()` requires buffer of len + 1 + 1 */

                char        ar2[_MAX_PATH + 1];
                DWORD const dw_ees2 = ExpandEnvironmentStringsA("%HOMEDRIVE%%HOMEPATH%", &ar2[0], _MAX_PATH + 1);

                if (0 == dw_ees2)
                {
                    goto env_var_not_found;
                }
                else if (dw_ees2 > _MAX_PATH)
                {
                    goto insufficient_buffer;
                }
                if (0 != unixem_util_str_begins_with(&ar2[0], "%HOMEDRIVE%") ||
                    0 != unixem_util_str_ends_with(&ar2[0], "%HOMEPATH%"))
                {
                    goto env_var_not_found;
                }
                else
                {
                    CopyMemory(&(*ar)[0], &ar2[0], _MAX_PATH * sizeof(ar2[0]));

                    *pnumWritten = dw_ees2 - 1;
                }
            }
            else
            if (0 != unixem_util_str_begins_with(&(*ar)[0], "%HOMEDRIVE%") ||
                0 != unixem_util_str_ends_with(&(*ar)[0], "%HOMEPATH%"))
            {
                goto env_var_not_found;
            }
            else
            {
                *pnumWritten = dw_ees - 1;
            }

            // if (ERROR_ENVVAR_NOT_FOUND == GetLastError() &&
            //     ERROR_ENVVAR_NOT_FOUND == le_up)
            // {
            //     SetLastError(0);
            // }

        }
    }
    else
    {
        if (dw_up >= _MAX_PATH)
        {
            SetLastError(ERROR_INSUFFICIENT_BUFFER);
        }
        else
        {
            *pnumWritten = dw_up;
        }
    }

    return 1;
}


/* ///////////////////////////// end of file //////////////////////////// */

