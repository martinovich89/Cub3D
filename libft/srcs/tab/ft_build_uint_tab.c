/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_build_uint_tab.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 23:39:17 by martin            #+#    #+#             */
/*   Updated: 2020/10/16 23:39:19 by martin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	**ft_build_uint_tab(int w, int h)
{
	unsigned int	**tab;
	int				i;
	size_t			j;

	j = h + 1;
	i = 0;
	if (!(tab = ft_calloc(j, sizeof(unsigned int *))))
		return (NULL);
	while (i < h)
	{
		if (!(tab[i] = malloc(sizeof(unsigned int) * w)))
			return (NULL);
		i++;
	}
	return (tab);
}
