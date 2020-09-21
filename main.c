#include "cub.h"

void	launch_game()
{
	/*a remplir*/
}

void	screenshoot()
{
	/*a remplir*/
}

void	check_arg(t_cub *cub, int argc, char **argv)
{
	if (argc < 1)
		ft_error(/*"No argument"*/);
	else if (argc > 0 && argc < 2)
		ft_error(/*"Empty argument"*/);
	else if (argc > 3)
		ft_error(/*"Too many arguments"*/);
	else if (argc == 3 && ft_strcmp(argv[2], "--save") != 0)
		ft_error(/*"Incorrect argument for save image"*/);
	else if (argc == 3)
		cub->is_bmp = TRUE;
	else
		cub->is_bmp = FALSE;
}

void	check_fd(t_cub *cub, char **argv)
{
	char	*line;
	int		fd;

	line = NULL;
	fd = 0;
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		ft_error(/*"The file does not exist"*/);
	if ((line = (ft_strrchr(argv[1], '.'))) != NULL)
	{
		if (ft_strncmp(line, ".cub", 4) != 0)
			ft_error(/*"Wrong file extension, please use .cub"*/);
	}
	else
		ft_error(/*"Wrong file extension, please use .cub"*/);
	close(fd);
}


int		main(int argc, char **argv)
{
	t_cub	cub;

	check_arg(&cub, argc, argv);
	check_fd(&cub, argv);
	cub.argv = argv[1];
	launch_game();
	if (cub.is_bmp == TRUE)
		screenshoot();
	return (0);
}
