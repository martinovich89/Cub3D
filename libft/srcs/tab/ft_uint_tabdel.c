/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uint_tabdel.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 23:39:57 by martin            #+#    #+#             */
/*   Updated: 2020/10/16 23:40:20 by martin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
