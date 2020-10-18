/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_skip_space.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhenry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 13:13:44 by mhenry            #+#    #+#             */
/*   Updated: 2019/11/08 15:13:35 by mhenry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_skip_space(const char *s)
{
	int i;

	i = 0;
	while (s[i] == ' ' || (s[i] > 8 && s[i] < 14))
		i++;
	return (i);
}