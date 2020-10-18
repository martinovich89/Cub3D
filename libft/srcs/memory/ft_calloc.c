/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhenry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 13:53:14 by mhenry            #+#    #+#             */
/*   Updated: 2019/11/14 14:19:52 by mhenry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char		*tab;

	if (!(tab = (unsigned char *)malloc(size * count)))
		return (NULL);
	ft_bzero(tab, count * size);
	return ((void *)tab);
}
