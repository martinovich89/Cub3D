/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting_map_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 23:51:23 by martin            #+#    #+#             */
/*   Updated: 2020/10/16 23:51:24 by martin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	sign_calc(t_map *map)
{
	map->signx = (map->ray.x < 0.0F) ? -1 : 1;
	map->signy = (map->ray.y < 0.0F) ? -1 : 1;
}

void	next_calc(t_env *env)
{
	env->map->nextx = (env->map->ray.x < 0.0F)
	? (env->map->pos.x - (float)env->map->x) * env->map->gapx
	: ((float)env->map->x + 1.0F - env->map->pos.x) * env->map->gapx;
	env->map->nexty = (env->map->ray.y < 0.0F)
	? (env->map->pos.y - (float)env->map->y) * env->map->gapy
	: ((float)env->map->y + 1.00F - env->map->pos.y) * env->map->gapy;
}

void	wall_dist_calc(t_env *env, int i)
{
	while (env->conf->map[env->map->y][env->map->x] != '1')
	{
		if (env->map->nextx < env->map->nexty)
		{
			env->map->nextx += env->map->gapx;
			env->map->x += env->map->signx;
			env->map->side = (env->map->ray.x < 0.0F) ? 0 : 3;
			if (env->conf->map[env->map->y][env->map->x] == '2')
				sprite_calc(env, i);
		}
		else
		{
			env->map->nexty += env->map->gapy;
			env->map->y += env->map->signy;
			env->map->side = (env->map->ray.y < 0.0F) ? 2 : 1;
			if (env->conf->map[env->map->y][env->map->x] == '2')
				sprite_calc(env, i);
		}
	}
}

void	perp_wall_dist_calc(t_map *map)
{
	if (map->side == 0 || map->side == 3)
		map->perp_wall_dist = ((float)map->x
		- map->pos.x + (1.0F - (float)map->signx) / 2.0F) / map->ray.x;
	else
		map->perp_wall_dist = ((float)map->y - map->pos.y
		+ (1.0F - (float)map->signy) / 2.0F) / map->ray.y;
}

void	sprite_calc(t_env *env, int i)
{
	sprite_pos_calc(env);
	sprite_dist_calc(env);
	sprite_scaled_height_calc(env);
	sprite_limits_calc(env);
	sprite_hit_calc(env);
	sprite_ratio_calc(env);
	sprite_texpos_calc(env);
	sprite_texxy_calc(env);
	if (env->sp.ok == 1)
		sprite_fill_stripe(env, i);
}
