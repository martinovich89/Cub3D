#include "cub.h"

void	sign_calc(t_map *map)
{
	map->signX = (map->ray.x < 0.0F) ? -1 : 1;
	map->signY = (map->ray.y < 0.0F) ? -1 : 1;
}

void	next_calc(t_env *env)
{
	env->map->nextX = (env->map->ray.x < 0.0F)
	? (env->map->pos.x - (float)env->map->x) * env->map->gapX
	: ((float)env->map->x + 1.0F - env->map->pos.x) * env->map->gapX;
	env->map->nextY = (env->map->ray.y < 0.0F)
	? (env->map->pos.y - (float)env->map->y) * env->map->gapY
	: ((float)env->map->y + 1.00F - env->map->pos.y) * env->map->gapY;
}

void	wall_dist_calc(t_env *env)
{
	while (env->conf->map[env->map->y][env->map->x] != '1')
	{
		if (env->map->nextX < env->map->nextY)
		{
			env->map->nextX += env->map->gapX;
			env->map->x += env->map->signX;
			env->map->side = (env->map->ray.x < 0.0F) ? 0 : 3;
		}
		else
		{
			env->map->nextY += env->map->gapY;
			env->map->y += env->map->signY;
			env->map->side = (env->map->ray.y < 0.0F) ? 2 : 1;
		}
	}
}

void	perp_wall_dist_calc(t_map *map)
{
	if (map->side == 0 || map->side == 3)
		map->perp_wall_dist = ((float)map->x
		- map->pos.x + (1.0F - (float)map->signX) / 2.0F) / map->ray.x;
	else
		map->perp_wall_dist = ((float)map->y - map->pos.y
		+ (1.0F - (float)map->signY) / 2.0F) / map->ray.y;
}