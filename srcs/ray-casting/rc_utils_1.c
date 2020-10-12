#include "cub.h"

void	rotation(t_vector *vector, float angle)
{
	float	x;
	float	y;

	x = vector->x;
	y = vector->y;
	vector->x = x * cos(angle) - y * sin(angle);
	vector->y = x * sin(angle) + y * cos(angle);
}

void	plane_calc(t_vector dir, t_vector *plane, float angle)
{
	plane->x = dir.x;
	plane->y = dir.y;
	rotation(plane, angle);
	plane->x *= tan(angle / 2);
	plane->y *= tan(angle / 2);
/*	if (plane->x < 0)
		plane->x *= -1;*/
}

void	new_pl_pos(t_env *env)
{
	float	new_pos_x;
	float	new_pos_y;

	new_pos_x = env->map->pos.x + env->map->dir.x * 0.017;
	new_pos_y = env->map->pos.y + env->map->dir.y * 0.017;
	if (env->conf->map[(int)(new_pos_x + 0.2)][(int)env->map->pos.y] == '0')
		env->map->pos.x = (new_pos_x);
	if (env->conf->map[(int)env->map->pos.x][(int)(new_pos_y + 0.2)] == '0')
		env->map->pos.y = (new_pos_y);
}

void	new_pl_dir(t_env *env, int sign)
{
	rotation(&env->map->dir, (env->map->fov / 20.0F * (float)sign));
}