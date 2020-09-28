#include "libft.h"

void    ft_strdel(char *str)
{
    if (str)
    {
        free(str);
        str= NULL;
    }
}