#include "cub.h"

void	texXY_calc(t_env *env)
{
	env->rndr->texX = (int)(env->rndr->wallX * (float)env->rndr->tex->W);
	env->rndr->texY = (int)env->rndr->texPosX;
}

int		get_tex_color(t_env *env)
{
	int color;

	if (env->rndr->texPosX >= 0 && env->rndr->texPosX < env->rndr->tex->H
	&& env->rndr->texX >= 0 && env->rndr->texX < env->rndr->tex->W)
		color = *(int*)(env->rndr->tex->addr
		+ (4 * env->rndr->tex->W * (int)env->rndr->texY)
		+ (4 * (int)env->rndr->texX));
	return (color);
}

void	fill_stripe(t_env *env, int i)
{
	int	j;

	j = 0;

	while (j < env->conf->res_h && j < env->rndr->wall_top)
	{
		env->rndr->sheet[j][i] = (unsigned int)env->conf->ceil;
		j++;
	}
	while (j >= env->rndr->wall_top && j <= env->rndr->wall_bot)
	{
		env->rndr->sheet[j][i] = get_tex_color(env);
		env->rndr->texPosX += env->rndr->ratio;
		env->rndr->texY = (int)env->rndr->texPosX & (env->rndr->tex->H - 1);
		j++;
	}
	while (j < env->conf->res_h)
	{
		env->rndr->sheet[j][i] = (unsigned int)env->conf->floo;
		j++;
	}
}