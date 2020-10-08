#include "cub.h"

float	plane_calc(t_vector *dir, t_vector *plane, float angle)
{
	plane->x = dir->x;
	plane->y = dir->y;
	rotation(plane, -M_PI / 2);
	plane->x *= tan(angle / 2);
	plane->y *= tan(angle / 2);
}

void	rotation(t_vector *vector, float angle)
{
	float tmp;

	tmp = vector->x;
	vector->x = vector->x * cos(angle) - vector->y * sin(angle);
	vector->y = tmp * sin(angle) + vector->y * cos(angle);
}

void	new_pl_pos(t_cub *cub)
{
	float new_pos_x;
	float new_pos_y;

	new_pos_x = cub->map->pos->x + cub->map->dir->x * 0.017;
	new_pos_y = cub->map->pos->y + cub->map->dir->y * 0.017;
	if (cub->conf->map[(int)(new_pos_x + 0.2)][(int)cub->map->pos->y] == '0')
		cub->map->pos->x = (new_pos_x);
	if (cub->conf->map[(int)cub->map->pos->x][(int)(new_pos_y + 0.2)] == '0')
		cub->map->pos->y = (new_pos_y);
}

void	new_pl_dir(t_map *map)
{
	
}