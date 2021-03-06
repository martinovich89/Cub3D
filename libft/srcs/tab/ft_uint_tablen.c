/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uint_tablen.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 23:40:36 by martin            #+#    #+#             */
/*   Updated: 2020/10/16 23:40:38 by martin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
