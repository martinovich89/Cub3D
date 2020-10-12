#include "libft.h"

int		ft_uint_tablen(unsigned int **tab)
{
	int i;

	i = 0;
	while (tab && tab[i] != NULL)
	{
		i++;
	}
	return (i);
}