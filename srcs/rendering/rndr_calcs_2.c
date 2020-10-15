#include "cub.h"

void	texXY_calc(t_env *env)
{
	env->rndr->texX = (int)(env->rndr->wallX * (float)env->rndr->tex->W);
	env->rndr->texY = (int)env->rndr->texPosX;
}

int		get_tex_color(t_env *env)
{
	int color;

	color = 0;
	if (env->rndr->texPosX >= 0 && env->rndr->texPosX < env->rndr->tex->H
	&& env->rndr->texX >= 0 && env->rndr->texX < env->rndr->tex->W)
		color = *(int*)(env->rndr->tex->addr
		+ (4 * env->rndr->tex->W * (int)env->rndr->texY)
		+ (4 * (int)env->rndr->texX));
	return (color);
}

int		get_sprite_color(t_env *env)
{
	int color;

	color = 0;
	if (env->sp.texPos >= 0 && env->sp.texPos < env->sp.tex.H
	&& env->sp.texX >= 0 && env->sp.texX < env->sp.tex.W)
		color = *(int*)(env->sp.tex.addr
		+ (4 * env->sp.tex.W * (int)env->sp.texY)
		+ (4 * (int)env->sp.texX));
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
		env->rndr->texPosX += env->rndr->ratio;
		env->rndr->texY = (int)env->rndr->texPosX & (env->rndr->tex->H - 1);
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
		if ((color = get_sprite_color(env)) && !env->rndr->sheet[j][i])
			env->rndr->sheet[j][i] = color;
		env->sp.texPos += env->sp.ratio;
		env->sp.texY = (int)env->sp.texPos;
		if (env->sp.texY >= env->sp.tex.H)
			env->sp.texY = env->sp.tex.H - 1;
		j++;
	}
}