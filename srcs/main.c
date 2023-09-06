/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martin <martin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/17 00:07:02 by martin            #+#    #+#             */
/*   Updated: 2023/09/06 19:51:18 by martin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int		render_next_frame(t_env *env)
{
	reset_sheet(env);
	ray_casting(env);
	draw_image(env, &env->img, env->rndr->sheet);
	mlx_put_image_to_window(env->mlx, env->win, env->img.img, 0, 0);
	return (0);
}

void	launch_game(t_env *env)
{
	parse_params(env);
	parse_map(env);
	init_player(env);
	init_mlx(env);

	if (env->conf->is_bmp)
	{
		reset_sheet(env);
		ray_casting(env);
		draw_image(env, &env->img, env->rndr->sheet);
		save(env);
		exit(0);
	}
	mlx_hook(env->win, 2, 1L << 0, key_press, env);
	mlx_hook(env->win, 3, 1L << 1, key_release, env);
	mlx_hook(env->win, 17, 1L << 17, close_window, env);
	mlx_loop_hook(env->mlx, render_next_frame, env);
	mlx_loop(env->mlx);
}

void	check_arg(t_env *env, int argc, char **argv)
{
	if (argc < 1)
		ft_error("No argument\n", env);
	else if (argc > 0 && argc < 2)
		ft_error("Empty argument\n", env);
	else if (argc > 3)
		ft_error("Too many arguments\n", env);
	else if (argc == 3 && ft_strcmp(argv[2], "--save") != 0)
		ft_error("Incorrect argument for save image\n", env);
	else if (argc == 3)
		env->conf->is_bmp = 1;
	else
		env->conf->is_bmp = 0;
}

void	check_fd(char **argv, t_env *env)
{
	char	*line;
	int		fd;
	int		ret;
	char	buffer[1];

	line = NULL;
	fd = 0;
	fd = open(argv[1], O_RDONLY);
	if (fd < 0 || (ret = read(fd, buffer, 1)) < 0)
		ft_error("The file does not exist\n", env);
	if ((line = (ft_strrchr(argv[1], '.'))) != NULL)
	{
		if (ft_strncmp(line, ".cub", 4) != 0)
			ft_error("Wrong file extension, please use .cub\n", env);
	}
	else
		ft_error("Wrong file extension, please use .cub\n", env);
	close(fd);
}

int		main(int argc, char **argv)
{
	t_env *env;

	if ((env = env_alloc()) == NULL)
		ft_error("failed to allocate env\n", env);

	check_arg(env, argc, argv);
	check_fd(argv, env);
	init_conf(env->conf);
	if (!(env->conf->file = ft_strdup(argv[1])))
		ft_error("failed to allocate conf.file\n", env);
	launch_game(env);
	ft_clear_env(env);
	return (0);
}
