/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting_map_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 23:51:13 by martin            #+#    #+#             */
/*   Updated: 2020/10/16 23:51:15 by martin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	plane_calc(t_vector dir, t_vector *plane, float angle)
{
	plane->x = dir.x;
	plane->y = dir.y;
	rotation(plane, angle);
	plane->x *= tan(angle / 2);
	plane->y *= tan(angle / 2);
}

void	cam_calc(t_env *env, int nb)
{
	env->map->cam_ratio = ((float)nb
	/ ((float)env->conf->res_w / 2.0F)) - 1.0F;
}

void	ray_calc(t_env *env)
{
	env->map->ray.x = env->map->dir.x
	+ env->map->plane.x * env->map->cam_ratio;
	env->map->ray.y = env->map->dir.y
	+ env->map->plane.y * env->map->cam_ratio;
	env->map->ray.posx = env->map->pos.x;
	env->map->ray.posy = env->map->pos.y;
	env->map->ray.coef = env->map->ray.y / env->map->ray.x;
	env->map->ray.intercept = env->map->pos.y
	- env->map->ray.coef * env->map->pos.x;
}

void	gap_calc(t_env *env)
{
	if (env->map->ray.y == 0.0F)
		env->map->gapx = 0.0F;
	else
		env->map->gapx = (env->map->ray.x == 0.0F)
		? 1.0F : fabs(1.0F / env->map->ray.x);
	if (env->map->ray.x == 0.0F)
		env->map->gapy = 0.0F;
	else
		env->map->gapy = (env->map->ray.y == 0.0F)
		? 1.0F : fabs(1.0F / env->map->ray.y);
}

void	mapxy_calc(t_map *map)
{
	map->x = (int)map->pos.x;
	map->y = (int)map->pos.y;
}
