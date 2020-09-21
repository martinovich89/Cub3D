#include "libft.h"

void    ft_tabdel(char ***tab)
{
    int len;
    int i;

    len = ft_tablen(*tab);
    i = 0;
    while (*tab[i])
    {
        ft_strdel(*tab[i]);
        i++;
    }
    if (*tab)
        free(*tab);
    *tab = NULL;
}