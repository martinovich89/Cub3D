/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhenry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 10:57:36 by mhenry            #+#    #+#             */
/*   Updated: 2019/11/14 12:34:57 by mhenry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

static int	ft_tab_len(char const *s, char c)
{
	int count;
	int i;

	count = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i] != c && s[i])
			count++;
		while (s[i] != c && s[i])
			i++;
	}
	return (count);
}

char		**ft_split(char const *s, char c)
{
	char	**tab;
	int		i;
	int		j;
	int		flag;

	flag = 0;
	if (!s)
		return (NULL);
	if (!(tab = malloc(sizeof(char *) * (ft_tab_len(s, c) + 1))))
		return (NULL);
	i = 0;
	j = 0;
	while (i < ft_tab_len(s, c))
	{
		while (s[j] == c && s[j])
			j++;
		if (s[j] != c && s[j])
			flag = j;
		while (s[j] != c && s[j])
			j++;
		tab[i] = ft_strndup(s + flag, (j - flag));
		i++;
	}
	tab[ft_tab_len(s, c)] = NULL;
	return (tab);
}
