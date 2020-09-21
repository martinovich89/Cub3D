#include "cub.h"

double	plane_calc(double angle)
{
	double plane;

	plane = tan(angle/2) * 1;
	return (plane);
}

void	rotation(t_vector *vector, double angle)
{
	vector->x = vector->x * cos(angle) - vector->y * sin(angle);
	vector->y = vector->x * sin(angle) + vector->y * cos(angle);
}

void	new_pl_pos(t_map *map)
{
	double new_pos_x;
	double new_pos_y;

	new_pos_x = map->pl_pos_x + map->pl_dir->x * 0.017;
	new_pos_y = map->pl_pos_y + map->pl_dir->y * 0.017;
	if (map->map[int(new_pos_x + 0.2)][int(map->pl_pos_y)] == '0')
		map->pl_pos_x = (new_pos_x);
	if (map->map[int(map->pl_pos_x)][int(new_pos_y + 0.2)] == '0')
		map->pl_pos_y = (new_pos_y);
}

void	new_pl_dir(t_map *map)
{
	
}