#include "cub.h"

void	wall_calc(t_env *env)
{
	env->rndr->wallH
	= (int)((float)env->conf->res_h / env->map->perp_wall_dist);
	env->rndr->wall_top
	= (int)(((float)env->conf->res_h - (float)env->rndr->wallH) / 2.0F);
	env->rndr->wall_bot
	= (int)((float)env->conf->res_h / 2.0F + (float)env->rndr->wallH / 2.0F);
	if (env->rndr->wall_top < 0)
		env->rndr->wall_top = 0;
	if (env->rndr->wall_bot >= env->conf->res_h)
		env->rndr->wall_bot = env->conf->res_h - 1;
}

void	ratio_calc(t_env *env)
{
	env->rndr->ratio = (float)env->tex->H / (float)env->rndr->wallH;
}

void	wallX_calc(t_env *env)
{
	if (env->map->side == 0 || env->map->side == 3)
		env->rndr->wallX = env->map->pos.y
		+ env->map->perp_wall_dist * env->map->ray.y;
	else
		env->rndr->wallX = env->map->pos.x
		+ env->map->perp_wall_dist * env->map->ray.x;
	env->rndr->wallX -= floor((env->rndr->wallX));
}

void	pick_texture(t_env *env)
{
	env->rndr->tex = &env->tex[env->map->side];
}

void	texPos_calc(t_env *env)
{
	env->rndr->texPosX = (((float)env->rndr->wallH
	- (float)env->conf->res_h) / 2.0F + (float)env->rndr->wall_top)
	* env->rndr->ratio;
}