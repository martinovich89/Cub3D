#include "cub.h"

void	init_player(t_env *env)
{
	init_dir(env);
	init_pos(env);
	init_fov(env);
	init_plane(env);
}

void	init_conf(t_conf *conf)
{
	conf->map = NULL;
	conf->file = NULL;
	conf->path_no = NULL;
	conf->path_ea = NULL;
	conf->path_we = NULL;
	conf->path_so = NULL;
	conf->path_sp = NULL;
	conf->res_w = -1;
	conf->res_h = -1;
	conf->ceil = 0;
	conf->ceil_is_set = 0;
	conf->floo = 0;
	conf->floo_is_set = 0;
	conf->map_h = 0;
	conf->map_w = 0;
	conf->player = '\0';
	conf->dir = '\0';
}

void	init_map(t_map *map)
{
	map->x = 0;
	map->y = 0;
	map->fov = 0;
	map->dir.x = 0;
	map->dir.y = 0;
	map->pos.x = 0;
	map->pos.y = 0;
	map->plane.x = 0;
	map->plane.y = 0;
	map->cam_ratio = 0;
	map->nextX = 0;
	map->nextY = 0;
	map->gapX = 0;
	map->gapY = 0;
	map->signX = 0;
	map->signY = 0;
	map->side = 0;
	map->perp_wall_dist = 0;
}

void	init_rndr(t_rndr *rndr)
{
//	rndr->sheet = NULL;
	rndr->wallH = 0;
	rndr->wall_bot = 0;
	rndr->wall_top = 0;
	rndr->wallX = 0;
	rndr->ratio = 0.0F;
	rndr->texPosX = 0.0F;
	rndr->texX = 0;
	rndr->texY = 0;
}

void	init_img(t_data *img)
{
	img->H = 0;
	img->W = 0;
}

void	init_env(t_env *env)
{
	init_conf(env->conf);
	init_map(env->map);
	init_rndr(env->rndr);
	init_img(&env->img);
	env->left = 0;
	env->right = 0;
	env->up = 0;
	env->down = 0;
	env->strafe_left = 0;
	env->strafe_right = 0;
	env->sprite = 0;
}

void	init_textures(t_env *env)
{
	int i;
	char *textures[4] = {env->conf->path_no
	, env->conf->path_ea, env->conf->path_we, env->conf->path_so};
	i = 0;
	while (i < 4)
	{
		if (!(env->tex[i].img = mlx_xpm_file_to_image(env->mlx
		, textures[i], &env->tex[i].W, &env->tex[i].H)))
			ft_error("failed to allocate tex[i].img\n", env);
		if (!(env->tex[i].addr = mlx_get_data_addr(env->tex[i].img
		, &env->tex[i].bpp, &env->tex[i].line_length, &env->tex[i].endian)))
			ft_error("failed to allocate tex[i].addr\n", env); 
		i++;
	}
}

void	init_mlx(t_env *env)
{
	if (!(env->mlx = mlx_init()))
		ft_error("failed to allocate mlx\n", env);
	if(!(env->win = mlx_new_window(env->mlx
	, env->conf->res_w, env->conf->res_h, "cub3D")))
		ft_error("failed to allocate win\n", env);
	if (!(env->img.img = mlx_new_image(env->mlx
	, env->conf->res_w, env->conf->res_h)))
		ft_error("failed to allocate img.img\n", env);
	if (!(env->img.addr = mlx_get_data_addr(env->img.img
	, &env->img.bpp, &env->img.line_length, &env->img.endian)))
		ft_error("failed to allocate img.addr\n", env);
	init_textures(env);
	if (!(env->sp.tex.img = mlx_xpm_file_to_image(env->mlx
	, env->conf->path_sp, &env->sp.tex.W, &env->sp.tex.H)))
		ft_error("failed to allocate sp.tex.img\n", env);
	if (!(env->sp.tex.addr = mlx_get_data_addr(env->sp.tex.img
	, &env->sp.tex.bpp, &env->sp.tex.line_length, &env->sp.tex.endian)))
		ft_error("failed to allocate sp.tex.addr\n", env);
	if (!(env->rndr->sheet
	= ft_build_uint_tab(env->conf->res_w, env->conf->res_h)))
		ft_error("failed to allocate rndr->sheet\n", env);
}