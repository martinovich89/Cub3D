/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rndr_sprite_calcs_2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/17 10:23:08 by martin            #+#    #+#             */
/*   Updated: 2020/10/17 10:23:10 by martin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	hit_line_calc(t_env *env)
{
	env->sp.hit_line.x = env->sp.vector.x;
	env->sp.hit_line.y = env->sp.vector.y;
	env->sp.hit_line.posX = env->map->pos.x + env->sp.vector.x;
	env->sp.hit_line.posY = env->map->pos.y + env->sp.vector.y;
	rotation(&env->sp.hit_line, (M_PI / 2));
	env->sp.hit_line.coef = env->sp.hit_line.y / env->sp.hit_line.x;
	env->sp.hit_line.intercept = env->sp.hit_line.posY - env->sp.hit_line.posX * env->sp.hit_line.coef;
}

void	intersection_calc(t_env *env)
{
	if ((env->map->ray.coef - env->sp.hit_line.coef) == 0.0001 && (env->map->ray.coef - env->sp.hit_line.coef) >= -0.0001)
	{
		env->sp.hit_posX = env->sp.pos.x;
		env->sp.hit_posY = env->sp.pos.y;
	}
	else if (env->sp.hit_line.coef <= 0.0001 && env->sp.hit_line.coef >= -0.0001)
	{
		env->sp.hit_posX = (env->sp.hit_line.intercept - env->map->ray.intercept) / (env->map->ray.coef - env->sp.hit_line.coef);
		env->sp.hit_posY = env->sp.pos.y;
	}
	else if (1 / env->sp.hit_line.coef <= 0.0001 && 1 / env->sp.hit_line.coef >= -0.0001)
	{
		env->sp.hit_posX = env->sp.pos.x;
		env->sp.hit_posY = env->map->ray.coef * env->sp.hit_posX + env->map->ray.intercept;
	}
	else
	{
		env->sp.hit_posX = (env->sp.hit_line.intercept - env->map->ray.intercept) / (env->map->ray.coef - env->sp.hit_line.coef);
		env->sp.hit_posY = env->map->ray.coef * env->sp.hit_posX + env->map->ray.intercept;
	}
}

void	set_inter(t_env *env)
{
	env->map->inter.x = env->sp.hit_posX - env->map->pos.x;
	env->map->inter.y = env->sp.hit_posY - env->map->pos.y;
}

void	set_hit(t_env *env)
{
	env->sp.hitX = sqrtf(powf((env->sp.hit_posX - env->sp.hit_line.posX), 2.0F)
	+ powf((env->sp.hit_posY - env->sp.hit_line.posY), 2.0F));
	set_inter(env);
	if (env->sp.hitX <= 0.5)
	{
		env->sp.ok = 1;
		if (env->map->ray.y < 0
		&& fabs(env->map->ray.y) >= fabs(env->map->ray.x))
			env->sp.hitX = (env->map->inter.x > env->sp.vector.x)
			? 0.5 + env->sp.hitX : 0.5 - env->sp.hitX;
		else if (env->map->ray.x > 0
		&& fabs(env->map->ray.x) >= fabs(env->map->ray.y))
			env->sp.hitX = (env->map->inter.y > env->sp.vector.y)
			? 0.5 + env->sp.hitX : 0.5 - env->sp.hitX;
		else if (env->map->ray.y > 0
		&& fabs(env->map->ray.y) >= fabs(env->map->ray.x))
			env->sp.hitX = (env->map->inter.x < env->sp.vector.x)
			? 0.5 + env->sp.hitX : 0.5 - env->sp.hitX;
		else if (env->map->ray.x < 0
		&& fabs(env->map->ray.x) >= fabs(env->map->ray.y))
			env->sp.hitX = (env->map->inter.y < env->sp.vector.y)
			? 0.5 + env->sp.hitX : 0.5 - env->sp.hitX;
	}
	else
		env->sp.ok = 0;
}

void	sprite_hit_calc(t_env *env)
{
	hit_line_calc(env);
	intersection_calc(env);
	set_hit(env);
}
