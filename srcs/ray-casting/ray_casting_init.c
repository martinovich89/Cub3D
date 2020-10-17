/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting_init.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 23:51:02 by martin            #+#    #+#             */
/*   Updated: 2020/10/16 23:51:03 by martin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	init_dir(t_env *env)
{
	if (env->conf->player == 'N')
	{
		env->map->dir.x = 0.0F;
		env->map->dir.y = -1.0F;
	}
	if (env->conf->player == 'E')
	{
		env->map->dir.x = 1.0F;
		env->map->dir.y = 0.0F;
	}
	if (env->conf->player == 'W')
	{
		env->map->dir.x = -1.0F;
		env->map->dir.y = 0.0F;
	}
	if (env->conf->player == 'S')
	{
		env->map->dir.x = 0.0F;
		env->map->dir.y = 1.0F;
	}
}

void	init_pos(t_env *env)
{
	int	i;
	int	j;

	i = 0;
	while (env->conf->map[i])
	{
		j = 0;
		while (env->conf->map[i][j])
		{
			if (is_in_str("NEWS", env->conf->map[i][j]))
			{
				env->map->pos.x = (float)j + 0.5F;
				env->map->pos.y = (float)i + 0.5F;
			}
			j++;
		}
		i++;
	}
}

void	init_fov(t_env *env)
{
	env->map->fov = rad_conv(FOV);
}

void	init_plane(t_env *env)
{
	plane_calc(env->map->dir, &env->map->plane, -env->map->fov);
}
