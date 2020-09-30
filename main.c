#include "cub.h"

/*void	launch_game(t_cub *cub)
{
	parse_params(cub);
	parse_map(cub);
}

void	screenshoot()
{

}

void	check_arg(t_cub *cub, int argc, char **argv)
{
	if (argc < 1)
		ft_error("No argument");
	else if (argc > 0 && argc < 2)
		ft_error("Empty argument");
	else if (argc > 3)
		ft_error("Too many arguments");
	else if (argc == 3 && ft_strcmp(argv[2], "--save") != 0)
		ft_error("Incorrect argument for save image");
	else if (argc == 3)
		cub->conf->is_bmp = 1;
	else
		cub->conf->is_bmp = 0;
}

void	check_fd(char **argv)
{
	char	*line;
	int		fd;

	line = NULL;
	fd = 0;
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		ft_error("The file does not exist");
	if ((line = (ft_strrchr(argv[1], '.'))) != NULL)
	{
		if (ft_strncmp(line, ".cub", 4) != 0)
			ft_error("Wrong file extension, please use .cub");
	}
	else
		ft_error("Wrong file extension, please use .cub");
	close(fd);
}

t_cub	*env_alloc()
{
	t_cub *ptr;

	if (!(ptr = malloc(sizeof(t_cub))))
		return (NULL);
	if (!(ptr->conf = malloc(sizeof(t_conf))))
		return (NULL);
	return (ptr);
}

void	init_env(t_cub *cub)
{
	cub->conf->res_w = -1;
    cub->conf->res_h = -1;
    cub->conf->path_no = NULL;
    cub->conf->path_ea = NULL;
    cub->conf->path_we = NULL;
    cub->conf->path_so = NULL;
    cub->conf->path_no = NULL;
    cub->conf->ceil_r = 0;
    cub->conf->ceil_g = 0;
    cub->conf->ceil_b = 0;
    cub->conf->ceil_is_set = 0;
    cub->conf->floo_r = 0;
    cub->conf->floo_g = 0;
    cub->conf->floo_b = 0;
    cub->conf->floo_is_set = 0;
}

int		main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	t_cub	*cub;

	if ((cub = env_alloc()) == NULL)
		ft_error("ram allocation error");
	check_arg(cub, argc, argv);
	check_fd(argv);
	cub->conf->file = argv[1];
	init_env(cub);
	launch_game(cub);/
	return (0);
}*/

void    test_print_twice_fd(int fd, int ret, char *str, char *path)
{

        fd = open(path, O_RDONLY);
        while ((ret = get_next_line(fd, &str) >= 0))
        {
            printf("%d-%s\n", ret, str);
            free(str);
        }
        printf("%d-%s\n", ret, str);
}

int        main(int argc, char **argv)
{
    int        fd;
    int        ret;
    char    *str;

    if (argc == 2)
    {
        fd = open(argv[1], O_RDONLY);
        while ((ret = get_next_line(fd, &str) > 0))
        {
            printf("%d-%s\n", ret, str);
            free(str);
        }
        printf("%d-%s\n", ret, str);
		free(str);
//        test_print_twice_fd(fd, ret, str, argv[1]);
		close(fd);
		fd = open(argv[1], O_RDONLY);
        while ((ret = get_next_line(fd, &str) >= 0))
        {
            printf("%d-%s\n", ret, str);
            free(str);
        }
        printf("%d-%s\n", ret, str);
		close(fd);
    }
    return (0);
}