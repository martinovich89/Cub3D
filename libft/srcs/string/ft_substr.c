/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhenry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 14:38:08 by mhenry            #+#    #+#             */
/*   Updated: 2019/11/14 16:22:34 by mhenry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*tab;
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	if (!(tab = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (len-- > 0 && start < ft_strlen(s))
	{
		tab[i] = s[start];
		i++;
		start++;
	}
	tab[i] = 0;
	return (tab);
}
