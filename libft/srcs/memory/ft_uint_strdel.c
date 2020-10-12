#include "libft.h"

void    ft_uint_strdel(unsigned int *str)
{
    if (str)
    {
        free(str);
        str= NULL;
    }
}