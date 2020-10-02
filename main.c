#include "cub.h"

void	launch_game(t_env *env)
{
	parse_params(env);
	parse_map(env);
}

void	screenshoot()
{
}

void	check_arg(t_env *env, int argc, char **argv)
{
	if (argc < 1)
		ft_error("No argument", env);
	else if (argc > 0 && argc < 2)
		ft_error("Empty argument", env);
	else if (argc > 3)
		ft_error("Too many arguments", env);
	else if (argc == 3 && ft_strcmp(argv[2], "--save") != 0)
		ft_error("Incorrect argument for save image", env);
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
	return (ptr);
}

void	init_env(t_env *env)
{
	env->conf->res_w = -1;
	env->conf->res_h = -1;
	env->conf->path_no = NULL;
	env->conf->path_ea = NULL;
	env->conf->path_we = NULL;
	env->conf->path_so = NULL;
	env->conf->path_sp = NULL;
	env->conf->ceil_r = 0;
	env->conf->ceil_g = 0;
	env->conf->ceil_b = 0;
	env->conf->ceil_is_set = 0;
	env->conf->floo_r = 0;
	env->conf->floo_g = 0;
	env->conf->floo_b = 0;
	env->conf->floo_is_set = 0;
	env->conf->map = NULL;
	env->conf->map_h = 0;
	env->conf->map_w = 0;
}

int		main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	t_env *env;

	if ((env = env_alloc()) == NULL)
		ft_error("ram allocation error", env);
	check_arg(env, argc, argv);
	check_fd(argv, env);
	env->conf->file = ft_strdup(argv[1]);
	init_env(env);
	launch_game(env);
	ft_clear_env(env);
	return (0);
}