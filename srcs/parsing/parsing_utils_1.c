#include "rc.h"

void	set_player_dir(t_map *map, char c)
{
	if (c == 'N' || c == 'S')
	{
		map->pl_dir_x = 0;
		map->pl_dir_y = (c == 'N') ? 1 : -1;
	}
	if (c == 'W' || c == 'E')
	{
		map->pl_dir_x = (c == 'E') ? 1 : -1;
		map->pl_dir_y = 0;
	}
}

void	set_player_vector(t_map *map)
{
	int i;
	int j;

	i = 0;
	while (map->map[i][j])
	{
		j = 0;
		while (map->map[i][j])
		{
			if (is_in_str(map->map[i][j], "NEWS"))
			{
				map->pl_pos_x = j + 0.5;
				map->pl_pox_y = i + 0.5;
				set_player_dir(map, map->map[i][j]);
			}
			j++;
		}
		i++;
	}
}
