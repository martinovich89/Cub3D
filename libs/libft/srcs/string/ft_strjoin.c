/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhenry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 16:12:26 by mhenry            #+#    #+#             */
/*   Updated: 2019/11/14 14:05:22 by mhenry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t		i;
	size_t		j;
	char		*tab;

	if (!s1)
		return (NULL);
	if (!(tab = malloc(sizeof(char) * (ft_strlen((char *)s1) +
	ft_strlen((char *)s2)) + 1)))
		return (NULL);
	i = 0;
	while (i < ft_strlen((char *)s1))
	{
		tab[i] = s1[i];
		i++;
	}
	j = 0;
	while (j < ft_strlen((char *)s2))
	{
		tab[i + j] = s2[j];
		j++;
	}
	tab[i + j] = 0;
	return (tab);
}
