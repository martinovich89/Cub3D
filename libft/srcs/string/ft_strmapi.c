/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhenry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 15:48:45 by mhenry            #+#    #+#             */
/*   Updated: 2019/11/14 12:12:53 by mhenry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*tab;
	unsigned int	i;

	if (!s)
		return (NULL);
	i = 0;
	if (!(tab = malloc(sizeof(char) * (ft_strlen((char *)s) + 1))))
		return (NULL);
	while (s[i])
	{
		tab[i] = (*f)(i, ((char *)s)[i]);
		i++;
	}
	tab[i] = 0;
	return (tab);
}
