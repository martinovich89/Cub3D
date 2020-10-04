/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhenry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 15:12:29 by mhenry            #+#    #+#             */
/*   Updated: 2019/11/10 15:04:05 by mhenry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>

char	*ft_strrchr(const char *s, int a)
{
	char	*flag;

	flag = NULL;
	while (*s)
	{
		if (*s == (char)a)
			flag = (char *)s;
		s++;
	}
	if (!a)
		return ((char *)s);
	return (flag);
}
