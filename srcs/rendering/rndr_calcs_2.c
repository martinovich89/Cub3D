/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rndr_calcs_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 23:51:56 by martin            #+#    #+#             */
/*   Updated: 2020/10/16 23:51:57 by martin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	texxy_calc(t_env *env)
{
	env->rndr->texx = (int)(env->rndr->wallx * (float)env->rndr->tex->w);
	env->rndr->texy = (int)env->rndr->texposx;
}

int		get_tex_color(t_env *env)
{
	int color;

	color = 0;
	if (env->rndr->texposx >= 0 && env->rndr->texposx < env->rndr->tex->h
	&& env->rndr->texx >= 0 && env->rndr->texx < env->rndr->tex->w)
		color = *(int*)(env->rndr->tex->addr
		+ (4 * env->rndr->tex->w * (int)env->rndr->texy)
		+ (4 * (int)env->rndr->texx));
	return (color);
}

int		get_sprite_color(t_env *env)
{
	int color;

	color = 0;
	if (env->sp.texpos >= 0 && env->sp.texpos < env->sp.tex.h
	&& env->sp.texx >= 0 && env->sp.texx < env->sp.tex.w)
		color = *(int*)(env->sp.tex.addr
		+ (4 * env->sp.tex.w * (int)env->sp.texy)
		+ (4 * (int)env->sp.texx));
	return (color);
}

void	fill_stripe(t_env *env, int i)
{
	int	j;

	j = 0;
	while (j < env->conf->res_h && j < env->rndr->wall_top)
	{
		if (!env->rndr->sheet[j][i])
			env->rndr->sheet[j][i] = (unsigned int)env->conf->ceil;
		j++;
	}
	while (j >= env->rndr->wall_top && j <= env->rndr->wall_bot)
	{
		if (!env->rndr->sheet[j][i])
			env->rndr->sheet[j][i] = get_tex_color(env);
		env->rndr->texposx += env->rndr->ratio;
		env->rndr->texy = (int)env->rndr->texposx & (env->rndr->tex->h - 1);
		j++;
	}
	while (j < env->conf->res_h)
	{
		if (!env->rndr->sheet[j][i])
			env->rndr->sheet[j][i] = (unsigned int)env->conf->floo;
		j++;
	}
}

void	sprite_fill_stripe(t_env *env, int i)
{
	int j;
	int color;

	j = 0;
	while (j < env->conf->res_h && j < env->sp.top)
		j++;
	while (j < env->conf->res_h && j <= env->sp.bot)
	{
		if ((color = get_sprite_color(env) & 0x00FFFFFF)
		&& !env->rndr->sheet[j][i])
			env->rndr->sheet[j][i] = color;
		env->sp.texpos += env->sp.ratio;
		env->sp.texy = (int)env->sp.texpos;
		if (env->sp.texy >= env->sp.tex.h)
			env->sp.texy = env->sp.tex.h - 1;
		j++;
	}
}
