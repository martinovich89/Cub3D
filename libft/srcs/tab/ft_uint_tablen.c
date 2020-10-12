#include "libft.h"

int		ft_uint_tablen(unsigned int **tab)
{
	int i;

	i = 0;
	if (tab == NULL)
		write (1, "lol3\n", 5);
	while (tab && tab[i] != NULL)
	{
		i++;
	}
	return (i);
}