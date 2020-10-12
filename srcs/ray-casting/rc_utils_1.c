#include "cub.h"

float	rad_conv(float angle)
{
	float ret;
	ret = angle * M_PI / 180;
	return (ret);
}

void	rotation(t_vector *vector, float angle)
{
	float	x;
	float	y;

	x = vector->x;
	y = vector->y;
	vector->x = x * cos(angle) - y * sin(angle);
	vector->y = x * sin(angle) + y * cos(angle);
}

void	translation(t_env *env, int nb)
{
	t_vector	new_pos;
	t_vector	new_dir;

	new_dir.x = env->map->dir.x;
	new_dir.y = env->map->dir.y;
	rotation(&new_dir, (nb * M_PI / 2));
	new_pos.x = env->map->pos.x + new_dir.x * 0.00005F;
	new_pos.y = env->map->pos.y + new_dir.y * 0.00005F;
	if (is_in_str("0NEWS", env->conf->map
	[(int)(new_pos.y + 0.3)][(int)env->map->pos.x]) && new_dir.y > 0)
		env->map->pos.y = (new_pos.y);
	if (is_in_str("0NEWS", env->conf->map
	[(int)env->map->pos.y][(int)(new_pos.x + 0.3)]) && new_dir.x > 0)
		env->map->pos.x = (new_pos.x);
	if (is_in_str("0NEWS", env->conf->map
	[(int)(new_pos.y - 0.3)][(int)env->map->pos.x]) && new_dir.y < 0)
		env->map->pos.y = (new_pos.y);
	if (is_in_str("0NEWS", env->conf->map
	[(int)env->map->pos.y][(int)(new_pos.x - 0.3)]) && new_dir.x < 0)
		env->map->pos.x = (new_pos.x);
}