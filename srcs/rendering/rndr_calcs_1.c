/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rndr_calcs_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 23:51:50 by martin            #+#    #+#             */
/*   Updated: 2020/10/16 23:51:51 by martin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	wall_calc(t_env *env)
{
	env->rndr->wallh =
	(int)((float)env->conf->res_h / env->map->perp_wall_dist);
	env->rndr->wall_top =
	(int)(((float)env->conf->res_h - (float)env->rndr->wallh) / 2.0F);
	env->rndr->wall_bot =
	(int)((float)env->conf->res_h / 2.0F + (float)env->rndr->wallh / 2.0F);
	if (env->rndr->wall_top < 0)
		env->rndr->wall_top = 0;
	if (env->rndr->wall_bot >= env->conf->res_h)
		env->rndr->wall_bot = env->conf->res_h - 1;
}

void	ratio_calc(t_env *env)
{
	env->rndr->ratio = (float)env->tex->h / (float)env->rndr->wallh;
}

void	wallx_calc(t_env *env)
{
	if (env->map->side == 0 || env->map->side == 3)
		env->rndr->wallx = env->map->pos.y
		+ env->map->perp_wall_dist * env->map->ray.y;
	else
		env->rndr->wallx = env->map->pos.x
		+ env->map->perp_wall_dist * env->map->ray.x;
	env->rndr->wallx -= floor((env->rndr->wallx));
}

void	pick_texture(t_env *env)
{
	env->rndr->tex = &env->tex[env->map->side];
}

void	texpos_calc(t_env *env)
{
	env->rndr->texposx = (((float)env->rndr->wallh
	- (float)env->conf->res_h) / 2.0F + (float)env->rndr->wall_top)
	* env->rndr->ratio;
}
