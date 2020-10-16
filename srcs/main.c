#include "cub.h"

void	launch_game(t_env *env)
{
	parse_params(env);
	parse_map(env);
	init_player(env);
	init_mlx(env);
	mlx_hook(env->win, 02, 1L<<0, key_press, env);
	mlx_hook(env->win, 03, 1L<<1, key_release, env);
	mlx_loop_hook(env->mlx, render_next_frame, env);
	mlx_loop(env->mlx);
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