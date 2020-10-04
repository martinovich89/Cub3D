/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhenry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 17:26:41 by mhenry            #+#    #+#             */
/*   Updated: 2019/11/08 17:49:16 by mhenry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*d;
	char	*s;

	if (n == 0 || dst == src)
		return (dst);
	d = (char *)dst;
	s = (char *)src;
	while (--n)
		*d++ = *s++;
	*d = *s;
	return (dst);
}
