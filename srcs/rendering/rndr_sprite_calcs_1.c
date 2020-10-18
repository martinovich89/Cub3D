/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rndr_sprite_calcs_1.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/17 10:18:29 by martin            #+#    #+#             */
/*   Updated: 2020/10/17 10:18:31 by martin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	sprite_pos_calc(t_env *env)
{
	env->sp.pos.x = (float)env->map->x + 0.5F;
	env->sp.pos.y = (float)env->map->y + 0.5F;
}

void	perp_sprite_dist_calc(t_env *env)
{
	float	xr;
	float	yr;

	env->map->plane.posX = env->map->pos.x + env->map->dir.x;
	env->map->plane.posY = env->map->pos.y + env->map->dir.y;
	env->map->plane.coef = env->map->plane.y / env->map->plane.x;
	env->map->plane.intercept = env->map->plane.posY
	- env->map->plane.coef * env->map->plane.posX;
	env->sp.vector.posX = env->map->pos.x;
	env->sp.vector.posY = env->map->pos.y;
	env->sp.vector.coef = env->sp.vector.y / env->sp.vector.x;
	env->sp.vector.intercept = env->sp.vector.posY
	- env->sp.vector.coef * env->sp.vector.posX;
	xr = (env->map->plane.intercept - env->sp.vector.intercept)
	/ (env->sp.vector.coef - env->map->plane.coef);
	yr = env->sp.vector.coef * xr + env->sp.vector.intercept;
	env->sp.pdist = env->sp.dist / sqrt(pow(xr - env->map->pos.x, 2)
	+ pow(yr - env->map->pos.y, 2));
}

void	sprite_dist_calc(t_env *env)
{
	env->sp.vector.x = env->sp.pos.x - env->map->pos.x;
	env->sp.vector.y = env->sp.pos.y - env->map->pos.y;
	env->sp.dist = sqrtf(powf(env->sp.pos.x - env->map->pos.x, 2.0F)
	+ powf(env->sp.pos.y - env->map->pos.y, 2.0F));
	perp_sprite_dist_calc(env);
}

void	sprite_scaled_height_calc(t_env *env)
{
	env->sp.scaledH = (int)((float)env->conf->res_h / env->sp.pdist);
}

void	sprite_limits_calc(t_env *env)
{
	env->sp.top = (env->conf->res_h - env->sp.scaledH) / 2;
	if (env->sp.top < 0)
		env->sp.top = 0;
	env->sp.bot = (env->conf->res_h + env->sp.scaledH) / 2;
	if (env->sp.bot >= env->conf->res_h)
		env->sp.bot = env->conf->res_h - 1;
}
