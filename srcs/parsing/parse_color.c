/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 23:49:53 by martin            #+#    #+#             */
/*   Updated: 2020/10/16 23:49:54 by martin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	set_colr(t_env *env, char *str, int nb)
{
	char	**tab;

	tab = NULL;
	if (!(tab = ft_split(str, ',')))
		ft_error("ram allocation error\n", env);
	if (nb == 1)
	{
		env->conf->ceil = (ft_atoi(tab[0]) << 16 | ft_atoi(tab[1]) << 8 |
				ft_atoi(tab[2]));
		env->conf->ceil_is_set = 1;
	}
	if (nb == 2)
	{
		env->conf->floo = (ft_atoi(tab[0]) << 16 | ft_atoi(tab[1]) << 8 |
				ft_atoi(tab[2]));
		env->conf->floo_is_set = 1;
	}
	if (tab)
		ft_tabdel(tab);
}

int		is_valid_colr(char *str)
{
	int	i;

	i = 0;
	if (!is_charset_str(str, "0123456789,"))
		return (0);
	if (ft_atoi(str + i) > 255 || ft_atoi(str + i) < 0 || !ft_isdigit(str[i]))
		return (0);
	i += ft_skip_digit(str + i);
	if (str[i++] != ',')
		return (0);
	if (ft_atoi(str + i) > 255 || ft_atoi(str + i) < 0 || !ft_isdigit(str[i]))
		return (0);
	i += ft_skip_digit(str + i);
	if (str[i++] != ',')
		return (0);
	if (ft_atoi(str + i) > 255 || ft_atoi(str + i) < 0 || !ft_isdigit(str[i]))
		return (0);
	i += ft_skip_digit(str + i);
	if (str[i])
		return (0);
	return (1);
}

void	parse_color(t_env *env, char *line, int nb)
{
	char	**tab;

	tab = NULL;
	if (!(tab = ft_split(line, ' ')))
		ft_error("erreur d'allocation mémoire\n", env);
	if (ft_tablen(tab) != 2 || !is_valid_colr(tab[1]))
	{
		ft_tabdel(tab);
		ft_error("invalid color line in .cub file\n", env);
	}
	set_colr(env, tab[1], nb);
	if (tab)
		ft_tabdel(tab);
}
