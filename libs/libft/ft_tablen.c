#include "libft.h"

int ft_tablen(char **tab)
{
    int i;

    i = 0;
    while (tab[i] != NULL)
        i++;
    return (i);
}