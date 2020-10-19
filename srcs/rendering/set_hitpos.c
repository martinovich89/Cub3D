/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gogole.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/17 21:41:19 by martin            #+#    #+#             */
/*   Updated: 2020/10/17 21:41:28 by martin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	set_hitpos_un(t_env *env)
{
	env->sp.hit_posx = env->sp.pos.x;
	env->sp.hit_posy = env->sp.pos.y;
}

void	set_hitpos_deux(t_env *env)
{
	env->sp.hit_posx = (env->sp.hit_line.intercept
	- env->map->ray.intercept) / (env->map->ray.coef - env->sp.hit_line.coef);
	env->sp.hit_posy = env->sp.pos.y;
}

void	set_hitpos_trois(t_env *env)
{
	env->sp.hit_posx = env->sp.pos.x;
	env->sp.hit_posy = env->map->ray.coef
	* env->sp.hit_posx + env->map->ray.intercept;
}

void	set_hitpos_quatre(t_env *env)
{
	env->sp.hit_posx = (env->sp.hit_line.intercept
	- env->map->ray.intercept) / (env->map->ray.coef - env->sp.hit_line.coef);
	env->sp.hit_posy = env->map->ray.coef
	* env->sp.hit_posx + env->map->ray.intercept;
}
