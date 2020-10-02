#include "libft.h"

int ft_skip_digit(char *str)
{
    int i;

    i = 0;
    while (str[i] && ft_isdigit(str[i]))
        i++;
    return (i);
}