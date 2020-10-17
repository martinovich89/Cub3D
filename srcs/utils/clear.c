/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 23:53:10 by martin            #+#    #+#             */
/*   Updated: 2020/10/16 23:53:15 by martin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	ft_clear_conf(t_conf *conf)
{
	free(conf->file);
	conf->file = NULL;
	free(conf->path_no);
	conf->path_no = NULL;
	free(conf->path_ea);
	conf->path_ea = NULL;
	free(conf->path_we);
	conf->path_we = NULL;
	free(conf->path_so);
	conf->path_so = NULL;
	free(conf->path_sp);
	conf->path_sp = NULL;
	if (conf->map)
		ft_tabdel(conf->map);
	free(conf);
}

void	ft_clear_map(t_map *map)
{
	free(map);
	map = NULL;
}

void	ft_clear_rndr(t_rndr *rndr)
{
	if (rndr && rndr->sheet)
		ft_uint_tabdel(rndr->sheet);
	free(rndr);
}

void	ft_clear_tex(t_env *env)
{
	int i;

	i = 0;
	while (i < 4)
	{
		if (env->tex[i].img)
		{
			mlx_destroy_image(env->mlx, env->tex[i].img);
			env->tex[i].img = NULL;
		}
		i++;
	}
}

void	ft_clear_env(t_env *env)
{
	if (env)
	{
		if (env->conf)
			ft_clear_conf(env->conf);
		if (env->map)
			ft_clear_map(env->map);
		if (env->rndr)
			ft_clear_rndr(env->rndr);
		if (env->sp.tex.img)
			mlx_destroy_image(env->mlx, env->sp.tex.img);
		if (env->mlx && env->tex[0].img)
			ft_clear_tex(env);
		if (env->mlx && env->win && env->img.img)
			mlx_destroy_image(env->mlx, env->img.img);
		if (env->mlx && env->win)
			mlx_destroy_window(env->mlx, env->win);
		if (env->mlx)
			free(env->mlx);
		env->mlx = NULL;
		free(env);
	}
}
