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

void	gogole_un(t_env *env)
{
	env->sp.hit_posX = env->sp.pos.x;
	env->sp.hit_posY = env->sp.pos.y;
}

void	gogole_deux(t_env *env)
{
	env->sp.hit_posX = (env->sp.hit_line.intercept - env->map->ray.intercept) / (env->map->ray.coef - env->sp.hit_line.coef);
	env->sp.hit_posY = env->sp.pos.y;
}

void	gogole_trois(t_env *env)
{
	env->sp.hit_posX = env->sp.pos.x;
	env->sp.hit_posY = env->map->ray.coef * env->sp.hit_posX + env->map->ray.intercept;
}

void	gogole_quatre(t_env *env)
{
	env->sp.hit_posX = (env->sp.hit_line.intercept - env->map->ray.intercept) / (env->map->ray.coef - env->sp.hit_line.coef);
	env->sp.hit_posY = env->map->ray.coef * env->sp.hit_posX + env->map->ray.intercept;
}