
#include <unixem/util/str.h>

#include <assert.h>
#include <string.h>


int
unixem_util_str_begins_with(
    char const* s
,   char const* prefix
)
{
    assert(NULL != s);
    assert(NULL != prefix);

    {
        size_t const    len_prefix  =   strlen(prefix);

        return 0 == strncmp(s, prefix, len_prefix);
    }
}

int
unixem_util_str_ends_with(
    char const* s
,   char const* suffix
)
{
    assert(NULL != s);
    assert(NULL != suffix);

    {
        size_t const    len_s       =   strlen(s);
        size_t const    len_suffix  =   strlen(suffix);

        if (len_s < len_suffix)
        {
            return 0;
        }
        else
        {
            return 0 == strcmp(s + (len_s - len_suffix), suffix);
        }
    }
}
