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
	env->sp.hit_line.posx = env->map->pos.x + env->sp.vector.x;
	env->sp.hit_line.posy = env->map->pos.y + env->sp.vector.y;
	rotation(&env->sp.hit_line, (M_PI / 2));
	env->sp.hit_line.coef = env->sp.hit_line.y / env->sp.hit_line.x;
	env->sp.hit_line.intercept = env->sp.hit_line.posy
	- env->sp.hit_line.posx * env->sp.hit_line.coef;
}

void	intersection_calc(t_env *env)
{
	if ((env->map->ray.coef - env->sp.hit_line.coef) == 0.0001
	&& (env->map->ray.coef - env->sp.hit_line.coef) >= -0.0001)
		gogole_un(env);
	else if (env->sp.hit_line.coef <= 0.0001
	&& env->sp.hit_line.coef >= -0.0001)
		gogole_deux(env);
	else if (1 / env->sp.hit_line.coef <= 0.0001
	&& 1 / env->sp.hit_line.coef >= -0.0001)
		gogole_trois(env);
	else
		gogole_quatre(env);
}

void	set_inter(t_env *env)
{
	env->map->inter.x = env->sp.hit_posx - env->map->pos.x;
	env->map->inter.y = env->sp.hit_posy - env->map->pos.y;
}

void	set_hit(t_env *env)
{
	env->sp.hitx = sqrtf(powf((env->sp.hit_posx - env->sp.hit_line.posx), 2.0F)
	+ powf((env->sp.hit_posy - env->sp.hit_line.posy), 2.0F));
	set_inter(env);
	if (env->sp.hitx <= 0.5)
	{
		env->sp.ok = 1;
		if (env->map->ray.y < 0
		&& fabs(env->map->ray.y) >= fabs(env->map->ray.x))
			env->sp.hitx = (env->map->inter.x > env->sp.vector.x)
			? 0.5 + env->sp.hitx : 0.5 - env->sp.hitx;
		else if (env->map->ray.x > 0
		&& fabs(env->map->ray.x) >= fabs(env->map->ray.y))
			env->sp.hitx = (env->map->inter.y > env->sp.vector.y)
			? 0.5 + env->sp.hitx : 0.5 - env->sp.hitx;
		else if (env->map->ray.y > 0
		&& fabs(env->map->ray.y) >= fabs(env->map->ray.x))
			env->sp.hitx = (env->map->inter.x < env->sp.vector.x)
			? 0.5 + env->sp.hitx : 0.5 - env->sp.hitx;
		else if (env->map->ray.x < 0
		&& fabs(env->map->ray.x) >= fabs(env->map->ray.y))
			env->sp.hitx = (env->map->inter.y < env->sp.vector.y)
			? 0.5 + env->sp.hitx : 0.5 - env->sp.hitx;
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
