#include "libft.h"

int is_charset_str(char *s1, char *s2)
{
    int i;
    int j;

    i = 0;
    while (s1[i])
    {
        j = 0;
        while (s2[j] && s1[i] != s2[j])
            j++;
        if (s1[i] != s2[j])
            return (0);
        i++;
    }
    return (1);
}