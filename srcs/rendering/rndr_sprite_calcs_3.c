/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rndr_sprite_calcs_3.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/17 10:25:30 by martin            #+#    #+#             */
/*   Updated: 2020/10/17 10:25:31 by martin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	sprite_ratio_calc(t_env *env)
{
	env->sp.ratio = (float)env->sp.tex.H / (float)env->sp.scaledH;
}

void	sprite_texpos_calc(t_env *env)
{
	env->sp.texPos = (((float)env->sp.scaledH - (float)env->conf->res_h)
	/ 2.0F + (float)env->sp.top) * env->sp.ratio;
}

void	sprite_texxy_calc(t_env *env)
{
	env->sp.texX = (int)((float)env->sp.tex.W * env->sp.hitX);
	env->sp.texY = (int)env->sp.texPos;
}
