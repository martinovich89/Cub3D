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

static int	fill_split(char **tab, char const *s, char c, int len)
{
	int i;
	int j;
	int flag;

	i = 0;
	j = 0;
	flag = 0;
	while (i < len)
	{
		while (s[j] == c && s[j])
			j++;
		if (s[j] != c && s[j])
			flag = j;
		while (s[j] != c && s[j])
			j++;
		if (!(tab[i] = ft_strndup(s + flag, (j - flag))))
			return (1);
		i++;
	}
	return (0);
}

char		**ft_split(char const *s, char c)
{
	char	**tab;
	int		len;

	if (!s)
		return (NULL);
	len = ft_tab_len(s, c);
	if (!(tab = malloc(sizeof(char *) * (len + 1))))
		return (NULL);
	ft_memset(tab, 0, sizeof(char *) * len);
	if (fill_split(tab, s, c, len))
		ft_tabdel(tab);
	tab[len] = NULL;
	return (tab);
}
