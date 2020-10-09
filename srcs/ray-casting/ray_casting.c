#include "cub.h"

void	init_dir(t_env *env)
{
	if (env->conf->dir = 'N')
	{
		env->map->dir->x = -1.0F;
		env->map->dir->y = 0.0F;
	}
	if (env->conf->dir = 'E')
	{
		env->map->dir->x = 0.0F;
		env->map->dir->y = 1.0F;
	}
	if (env->conf->dir = 'W')
	{
		env->map->dir->x = 0.0F;
		env->map->dir->y = -1.0F;
	}
	if (env->conf->dir = 'S')
	{
		env->map->dir->x = 1.0F;
		env->map->dir->y = 0.0F;
	}
}

void	init_pos(t_env *env)
{
	int	i;
	int	j;

	i = 0;
	while (env->conf->map[i])
	{
		j = 0;
		while (env->conf->map[i][j])
		{
			if (is_in_str("NEWS", env->conf->map[i][j]))
			{
				env->map->pos->x = (float)j;
				env->map->pos->y = (float)i;
			}
			j++;
		}
		i++;
	}
}

float	rad_conv(float angle)
{
	float ret;
	ret = angle * M_PI / 180;
	return (ret);
}

void	init_fov(t_env *env)
{
	env->map->fov = rad_conv(FOV);
}

void	init_plane(t_env *env)
{
	env->map->plane->x = plane_calc(env->map->dir, env->map->plane, env->map->fov);
}

void	cam_calc(t_env *env, int nb)
{
	env->map->cam_ratio = ((float)nb / ((float)env->conf->res_w / 2.0F)) - 1.0F;
}

void	ray_calc(t_env *env)
{
	env->map->ray->x = env->map->dir->x + env->map->plane->x * env->map->cam_ratio;
	env->map->ray->y = env->map->dir->y + env->map->plane->y * env->map->cam_ratio;
}

void	gab_calc(t_env *env)
{
	if (env->map->ray->y == 0.0F)
		env->map->gapX = 0.0F;
	else
	{
		env->map->gapX = (env->map->ray->x == 0.0F) ? 1.0F : abs(1.0F / env->map->ray->x);
	}
	if (env->map->ray->x == 0.0F)
		env->map->gapY = 0.0F;
	else
	{
		env->map->gapY = (env->map->ray->y == 0.0F) ? 1.0F : abs(1.0F / env->map->ray->y);
	}
}

void	mapXY_calc(t_map *map)
{
	map->x = (int)map->pos->x;
	map->y = (int)map->pos->y;
}

void	sign_calc(t_map *map)
{
	map->signX = (map->dir->x < 0.0F) ? -1 : 1;
	map->signY = (map->dir->y < 0.0F) ? -1 : 1;
}

void	next_calc(t_env *env)
{
	env->map->gapX = (env->map->ray->x < 0.0F)
						 ? (env->map->pos->x - (float)env->map->x) * env->map->gapX
						 : ((float)env->map->x + 1.0F - env->map->pos->x) * env->map->gapX;
	env->map->gapY = (env->map->ray->y < 0.0F)
						 ? (env->map->pos->y - (float)env->map->y) * env->map->gapY
						 : ((float)env->map->y + 1.00F - env->map->pos->y) * env->map->gapY;
}

void	wall_dist_calc(t_env *env)
{
	int	mapX;
	int	mapY;

	mapX = env->map->x;
	mapY = env->map->y;
	while (env->conf->map[mapX][mapY] != 1)
	{
		if (env->map->nextX < env->map->nextY)
		{
			env->map->nextX += env->map->gapX;
			mapX += env->map->signX;
			env->map->side = (env->map->dir->x < 0.0F) ? 0 : 3;
		}
		else
		{
			env->map->nextY += env->map->gapY;
			mapY += env->map->signY;
			env->map->side = (env->map->dir->y < 0.0F) ? 2 : 1;
		}
	}
}

void	perp_wall_dist_calc(t_map *map)
{
	if (map->side == 0 || map->side == 3)
		map->perp_wall_dist = ((float)map->x - map->pos->x + (1.0F - (float)map->signX) / 2.0F) / map->ray->x;
	else
		map->perp_wall_dist = ((float)map->y - map->pos->y + (1.0F - (float)map->signY) / 2.0F) / map->ray->y;
}

void	wall_calc(t_env *env)
{
	env->rndr->wallH = (int)((float)env->conf->res_h / env->map->perp_wall_dist);
	env->rndr->wall_top = (int)(((float)env->conf->res_h - (float)env->rndr->wallH) / 2.0F);
	env->rndr->wall_bot = (int)((float)env->conf->res_h / 2.0F + (float)env->rndr->wallH / 2.0F); // -hmur/2 + hmur = hmur/2
	if (env->rndr->wall_top < 0)
		env->rndr->wall_top = 0;
	if (env->rndr->wall_top >= env->conf->res_h)
		env->rndr->wall_top = env->conf->res_h - 1;
}

void	ratio_calc(t_env *env)
{
	env->rndr->ratio = (float)env->rndr->wallH / (float)env->conf->res_h;
}

void	wallX_calc(t_env *env)
{
	if (env->map->side == 0 || env->map->side == 3)
		env->rndr->wallX = env->map->pos->y + env->map->perp_wall_dist * env->map->ray->y;
	else
		env->rndr->wallX = env->map->pos->x + env->map->perp_wall_dist * env->map->ray->x;
	if (env->map->side == 0 || env->map->side == 2)
		env->rndr->wallX = (float)env->map->x + 1.0F - env->rndr->wallX;
	else
		env->rndr->wallX = env->rndr->wallX - (float)env->map->x;
}

void	texPos_calc(t_env *env)
{
	env->rndr->texPos = (((float)env->rndr->wallH - (float)env->conf->res_h) / 2.0F + (float)env->rndr->wall_top) * env->rndr->ratio;
}

void	texXY_calc(t_env *env)
{
	env->rndr->texX = (int)(env->rndr->wallX * (float)env->rndr->texW);
	env->rndr->texY = (int)env->rndr->texPos;
}

void	fill_stripe(t_env *env, int i)
{
	int	j;

	j = 0;
	while (j < env->conf->res_h && j < env->rndr->wall_top)
	{
		env->rndr->img[i][j] = (unsigned int)env->conf->ceil;
		j++;
	}
	while (j >= env->rndr->wall_top && j <= env->rndr->wall_bot)
	{
		env->rndr->img[i][j] = (tex[env->map->side][env->rndr->texX][env->rndr->texY]);
		env->rndr->texPos += env->rndr->ratio;
		env->rndr->texY = (int)env->rndr->texPos & (env->rndr->texH - 1);
		j++;
	}
	while (j < env->conf->res_h)
	{
		env->rndr->img[i][j] = (unsigned int)env->conf->floo;
		j++;
	}
}

void	ray_casting(t_env *env)
{
	int	i;

	ft_build_uint_tab(env->conf->res_w, env->conf->res_h);
	i = 0;
	while (i < env->conf->res_w)
	{
		cam_calc(env, i);
		ray_calc(env);
		gap_calc(env);
		mapXY_calc(env->map);
		sign_calc(env->map);
		next_calc(env);
		wall_dist_calc(env);
		perp_wall_dist_calc(env->map);
		wall_calc(env);
		ratio_calc(env);
		wallX_calc(env);
		texPos_calc(env);
		texXY_calc(env);
		fill_stripe(env, i);
		i++;
	}
}