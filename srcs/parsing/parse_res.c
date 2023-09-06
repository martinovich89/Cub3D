/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_res.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martin <martin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 23:50:18 by martin            #+#    #+#             */
/*   Updated: 2023/09/06 17:23:29 by martin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	set_res_wh(t_env *env, int x, int y)
{
	int w;
	int h;

	if (!(env->mlx = mlx_init()))
		ft_error("failed to allocate mlx ptr\n", env);
	mlx_get_screen_size(env->mlx, &w, &h);
	if (x > w)
		env->conf->res_w = w;
	if (x <= w)
		env->conf->res_w = x;
	if (y > h)
		env->conf->res_h = h;
	if (y <= h)
		env->conf->res_h = y;
	mlx_destroy_display(env->mlx);
	free(env->mlx);
	env->mlx = NULL;
}

void	parse_res(t_env *env, char *line)
{
	char	**tab;

	if (!(tab = ft_split(line, ' ')))
	{
		ft_strdel(&line);
		ft_error("allocation error\n", env);
	}
	if (ft_tablen(tab) != 3 || ft_atoi(tab[1]) < 300 || ft_atoi(tab[2]) < 300
	|| !is_charset_str(tab[1], "0123456789")
	|| !is_charset_str(tab[2], "0123456789"))
	{
		ft_strdel(&line);
		ft_tabdel(&tab);
		ft_error("invalid res line. (only digits. min res : 300 300)\n", env);
	}
	set_res_wh(env, ft_atoi(tab[1]), ft_atoi(tab[2]));
	if (tab)
		ft_tabdel(&tab);
}
