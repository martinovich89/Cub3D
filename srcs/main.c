#include "cub.h"

void			my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bpp / 8));
	*(unsigned int *)dst = color;
}

int				close_window(int keycode, t_env *env)
{
	if (keycode == 65307)
	{
		mlx_destroy_window(env->mlx, env->win);
		exit (1);
	}
	return (1);
}

/*void			fill_img(unsigned int **img_tab)
{
	int x;
	int y;

	y = 0;
	while (y < 600)
	{
		x = 0;
		while (x < 800)
		{
			img_tab[y][x] = 0x00FF0000;
			x++;
		}
		y++;
	}
}*/

void            draw_image(t_data *data, unsigned int **tab)
{
    int x;
    int y;

    y = 0;
    while (y < 600)
    {
        x = 0;
        while (x < 800)
        {
            my_mlx_pixel_put(data, x, y, tab[y][x]);
            x++;
        }
        y++;
    }
}

int		render_next_frame(t_env *env)
{
/*	fill_img(env->rndr->sheet);
	draw_image(&env->img, env->rndr->sheet);*/

	ray_casting(env);
	draw_image(&env->img, env->rndr->sheet);
	mlx_put_image_to_window(env->mlx, env->win, env->img.img, 0, 0);
	return (0);
}

void	launch_game(t_env *env)
{
	parse_params(env);
	parse_map(env);
//	render_next_frame(env);
	init_mlx(env);
	mlx_key_hook(env->win, close_window, env);
	mlx_loop_hook(env->mlx, render_next_frame, env);
	mlx_loop(env->mlx);
}

void	screenshoot()
{
}

void	check_arg(t_env *env, int argc, char **argv)
{
	if (argc < 1)
		exit(1);
		//ft_error("No argument", env);
	else if (argc > 0 && argc < 2)
		exit(1);
		//ft_error("Empty argument", env);
	else if (argc > 3)
		exit(1);
		//ft_error("Too many arguments", env);
	else if (argc == 3 && ft_strcmp(argv[2], "--save") != 0)
		exit(1);
		//ft_error("Incorrect argument for save image", env);
	else if (argc == 3)
		env->conf->is_bmp = 1;
	else
		env->conf->is_bmp = 0;

}

void	check_fd(char **argv, t_env *env)
{
	char *line;
	int fd;

	line = NULL;
	fd = 0;
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		ft_error("The file does not exist", env);
	if ((line = (ft_strrchr(argv[1], '.'))) != NULL)
	{
		if (ft_strncmp(line, ".cub", 4) != 0)
			ft_error("Wrong file extension, please use .cub", env);
	}
	else
		ft_error("Wrong file extension, please use .cub", env);
	close(fd);
}

t_env	*env_alloc()
{
	t_env *ptr;

	if (!(ptr = malloc(sizeof(t_env))))
		return (NULL);
	if (!(ptr->conf = malloc(sizeof(t_conf))))
		return (NULL);
	if (!(ptr->map = malloc(sizeof(t_map))))
		return (NULL);
	if (!(ptr->rndr = malloc(sizeof(t_conf))))
		return (NULL);
	return (ptr);
}

/*void	init_ptrs(t_env *env)
{
	env->conf->file = NULL;
	env->conf->path_no = NULL;
	env->conf->path_ea = NULL;
	env->conf->path_we = NULL;
	env->conf->path_so = NULL;
	env->conf->path_sp = NULL;
	env->conf->map = NULL;
	env->rndr->sheet = NULL;
}*/

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
}

void	init_textures(t_env *env)
{
	int i;

	i = 0;
	while (i < 4)
	{
		if (!(env->tex[i].img = mlx_xpm_file_to_image(env->mlx, "./textures/bluestone.xpm", &env->tex[i].W, &env->tex[i].H)))
			ft_error("failed to allocate tex[i].img\n", env);
		if (!(env->tex[i].addr = mlx_get_data_addr(env->tex[i].img, &env->tex[i].bpp, &env->tex[i].line_length, &env->tex[i].endian)))
			ft_error("failed to allocate tex[i].addr\n", env); 
		i++;
	}
}

void	init_mlx(t_env *env)
{
	if (!(env->mlx = mlx_init()))
		ft_error("failed to allocate mlx\n", env);
	if(!(env->win = mlx_new_window(env->mlx, env->conf->res_w, env->conf->res_h, "cub3D")))
		ft_error("failed to allocate win\n", env);
	if (!(env->img.img = mlx_new_image(env->mlx, env->conf->res_w, env->conf->res_h)))
		ft_error("failed to allocate img.img\n", env);
	if (!(env->img.addr = mlx_get_data_addr(env->img.img, &env->img.bpp, &env->img.line_length, &env->img.endian)))
		ft_error("failed to allocate img.addr\n", env);
	init_textures(env);
	if (!(env->rndr->sheet = ft_build_uint_tab(env->conf->res_w, env->conf->res_h)))
		ft_error("failed to allocate rndr->sheet\n", env);
}

int		main(int argc, char **argv)
{
	t_env *env;

	if ((env = env_alloc()) == NULL)
		exit(1);
	check_arg(env, argc, argv);
	check_fd(argv, env);
	init_env(env);
	env->conf->file = ft_strdup(argv[1]);
	launch_game(env);
	ft_clear_env(env);
	return (0);
}