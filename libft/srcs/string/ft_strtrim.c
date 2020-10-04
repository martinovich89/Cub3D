/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhenry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 16:25:09 by mhenry            #+#    #+#             */
/*   Updated: 2019/11/14 14:29:47 by mhenry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_check_set(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char		*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		j;
	int		k;
	char	*tab;

	if (!s1)
		return (NULL);
	i = 0;
	while (s1[i] && ft_check_set(s1[i], set) == 1)
		i++;
	j = ft_strlen((char *)s1) - 1;
	while (s1[j] && ft_check_set(s1[j], set) == 1 && j > i)
		j--;
	if (!(tab = malloc(sizeof(char) * (j - i + 2))))
		return (NULL);
	k = 0;
	while (i + k <= j)
	{
		tab[k] = s1[i + k];
		k++;
	}
	tab[k] = 0;
	return (tab);
}
