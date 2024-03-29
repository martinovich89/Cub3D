/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martin <martin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 23:50:52 by martin            #+#    #+#             */
/*   Updated: 2023/09/08 10:21:21 by martin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	map_all_calc(t_env *env, int i)
{
	plane_calc(env->map->dir, &env->map->plane, -env->map->fov);
	cam_calc(env, i);
	ray_calc(env);
	gap_calc(env);
	mapxy_calc(env->map);
	sign_calc(env->map);
	next_calc(env);
	wall_dist_calc(env, i);
	perp_wall_dist_calc(env->map);
	wall_calc(env);
	pick_texture(env);
	ratio_calc(env);
	wallx_calc(env);
	texpos_calc(env);
	texxy_calc(env);
}

void apply_moves(t_env *env) {
	if (env->left == 1)
		rotation(&env->map->dir, (env->map->fov / 50000 * -1));
	if (env->right == 1)
		rotation(&env->map->dir, (env->map->fov / 50000));
	if (env->up == 1)
		translation(env, 0);
	if (env->down == 1)
		translation(env, 2);
	if (env->strafe_left == 1)
		translation(env, 3);
	if (env->strafe_right == 1)
		translation(env, 1);
}

void	ray_casting(t_env *env)
{
	int	i;

	i = 0;
	while (i < env->conf->res_w)
	{
		apply_moves(env);
		map_all_calc(env, i);
		fill_stripe(env, i);
		i++;
	}
}
