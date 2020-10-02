#include "libft.h"

int is_charset_str(char *str, char *charset)
{
    int i;
    int j;

    i = 0;
    if (!str[i] || !str)
        return (0);
    while (str[i])
    {
        j = 0;
        while (charset[j] && str[i] != charset[j])
        {
            j++;
        }
        if (!charset[j])
            return (0);
        i++;
    }
    return (1);
}