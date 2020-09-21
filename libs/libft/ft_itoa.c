/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhenry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 14:38:54 by mhenry            #+#    #+#             */
/*   Updated: 2019/11/14 14:30:39 by mhenry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

static int	ft_nbrlen(long long n)
{
	int count;

	count = 1;
	if (n < 0)
	{
		n *= -1;
		count++;
	}
	while (n > 9)
	{
		n /= 10;
		count++;
	}
	return (count);
}

static char	*ft_salloc(long long n, int size)
{
	char	*tab;

	if (n < 0)
	{
		n *= -1;
		if (!(tab = malloc(sizeof(char) * (size + 1))))
			return (NULL);
		tab[0] = '-';
	}
	else if (n == 0)
	{
		if (!(tab = malloc(sizeof(char) + 1)))
			return (NULL);
		tab[0] = '0';
	}
	else
	{
		if (!(tab = malloc(sizeof(char) * (size + 1))))
			return (NULL);
	}
	return (tab);
}

char		*ft_itoa(int n)
{
	int			i;
	char		*s;
	long long	ln;

	ln = (long long)n;
	if (!(s = ft_salloc(ln, ft_nbrlen(ln))))
		return (NULL);
	i = ft_nbrlen(ln);
	s[i] = 0;
	i--;
	if (ln < 0)
		ln *= -1;
	while (ln >= 1)
	{
		s[i] = ln % 10 + '0';
		ln /= 10;
		i--;
	}
	return (s);
}
