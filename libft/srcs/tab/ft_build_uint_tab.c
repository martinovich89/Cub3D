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

	i = 0;
	tab = NULL;
	if (!(tab = malloc(sizeof(*tab) * h + 1)))
		return (NULL);
	ft_memset(tab, 0, sizeof(unsigned int *) * h + 1);
	while (i < h)
	{
		if (!(tab[i] = malloc(sizeof(**tab) * w)))
			return (NULL);
		ft_memset(tab[i], 0, sizeof(unsigned int) * w);
		i++;
	}
	return (tab);
}
