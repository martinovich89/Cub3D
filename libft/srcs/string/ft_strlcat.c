/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhenry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 10:52:09 by mhenry            #+#    #+#             */
/*   Updated: 2019/11/12 13:29:29 by mhenry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <stdio.h>
#include <unistd.h>

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t i;
	size_t j;
	size_t catsize;

	catsize = dstsize;
	i = 0;
	while (catsize && dst[i])
	{
		i++;
		catsize--;
	}
	if (catsize <= 0)
		return (i + ft_strlen(src));
	j = 0;
	while (catsize > 1 && src[j])
	{
		dst[i + j] = src[j];
		j++;
		catsize--;
	}
	dst[i + j] = '\0';
	return (i + ft_strlen(src));
}
