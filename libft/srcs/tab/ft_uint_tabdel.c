#include "libft.h"

/*void    ft_uint_strdel(unsigned int *str)
{
    if (str)
    {
        free(str);
        str= NULL;
    }
}

int		ft_uint_tablen(unsigned int **tab)
{
	int i;

	i = 0;
	while (tab[i] != NULL)
		i++;
	return (i);
}*/

void	ft_uint_tabdel(unsigned int **tab)
{
	int len;
	int i;

	len = ft_uint_tablen(tab);
	i = 0;
	while (tab[i])
	{
		ft_uint_strdel(tab[i]);
		i++;
	}
	if (tab)
		free(tab);
	len++;
	tab = NULL;
}