/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_skip_alpha.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 23:44:29 by martin            #+#    #+#             */
/*   Updated: 2020/10/16 23:44:30 by martin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_skip_alpha(char *str)
{
	int i;

	i = 0;
	while (str[i] && ft_isalpha(str[i]))
		i++;
	return (i);
}