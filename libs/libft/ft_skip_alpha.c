#include "libft.h"

int ft_skip_alpha(char *str)
{
    int i;

    i = 0;
    while (str[i] && ft_isalpha(str[i]))
        i++;
    return (i);
}