#include "cub.h"

// Check de la position de la map.
void    check_map_pos(char *line, int fd)
{
    while (get_next_line(fd, &line) > 0  // 3e condition : a voir si on tolere lignes avec que des espaces
    && !is_charset_str(line, " 1"))
    {
        if (line)
            ft_strdel(line);
    }
    if (!is_charset_str(line, " 1") || is_charset_str(line, " "))
        ft_error("no map or invalid line spaces");
    ft_strdel(line);
    while (get_next_line(fd, &line) > 0)
    {
        if (!is_charset_str(line, "012 NEWS") || !is_in_str(line, '1'))  // 2e condition : a voir si on tolere lignes vides
            ft_error("check spaces in empty lines or map pos.");
        if (line)
            ft_strdel(line);
    }
    if (line)
        ft_strdel(line);
}

// Parcours du fichier pour déterminer xmax et ymax de la map.
void    set_w_h(t_cub *cub, int fd1)
{
    char *line;
    int     fd2;

    line = NULL;
    if ((fd2 = open(cub->conf->file, O_RDONLY)) <= 0)
        ft_error("invalid .cub file path");
    check_map_pos(line, fd2);
    close(fd2);
    while (get_next_line(fd1, &line) > 0)
    {
        if (is_charset_str(line, "012 NEWS") && is_in_str(line, '1'))
        {
            if (ft_strlen(line) > cub->conf->res_w)
                cub->conf->res_w = ft_strlen(line);
            cub->conf->res_h++;
        }
        if (line)
            ft_strdel(line);
    }
    if (line)
        ft_strdel(line);
}

//  Build un tableau de chars rectangulaire. Intégrer à libft ?
char    **ft_build_tab(int w, int h)
{
    char **tab;
    int i;

    if (!(tab = malloc(sizeof(char) * h + 1)))
        ft_error("ram allocation error");
    i = 0;
    while (i < h)
    {
        if (!(tab[i] = calloc((w + 1), 1)))
            ft_error("ram allocation error");
        ft_memset(tab[i], ' ', w);
        i++;
    }
    return (tab);
}

void	fill_tab(t_cub *cub, int fd)
{
	char    *line;
	size_t  i;

	// copier les lignes de description de map dans le tableau de str conf->map
	while (get_next_line(fd, &line) > 0)
	{
		i = 0;
		while (i < cub->conf->res_w && is_charset_str(line, "NEWS 012"))
		{
			strcpy(cub->conf->map[i], line);
			i++;
		}
		ft_strdel(line);
	}
}

int		check_map(char **tab)
{
	size_t i;
	size_t j;

	i = 0;
	while (tab[i])
	{
		j = 0;
		while (tab[j])
		{
			// les if qui suivent permet de vérifier que les bords de map sont des 1.
			// 1. verifier qu'il n'y a pas '0', '2', 'N'... sur les bords.
			if ((!i || !j || !tab[i + 1] || !tab[i][j + 1])
			&& is_charset(tab[i][j], "02NEWS"))
				return (1);
			// 2. verifier qu'il n'y a pas '0', '2', 'N'... en dehors de la "cloture" de 1.
			if ((i && j && tab[i + 1] && tab[i][j + 1])
			&& is_charset(tab[i][j], "02NEWS")
			&& (tab[i + 1][j] == ' ' || tab[i][j + 1] == ' '
			|| tab[i - 1][j] == ' ' || tab[i][j - 1] == ' '))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

void    parse_map(t_cub *cub)
{
    int fd;

    if ((fd = open(CONF_PATH, O_RDONLY)) <= 0)
        ft_error("invalid .cub file path");
    set_w_h(cub, fd);
    close(fd);
    cub->conf->map = ft_build_tab(cub->conf->res_w, cub->conf->res_h);
    if ((fd = open(CONF_PATH, O_RDONLY)) <= 0)
        ft_error("invalid .cub file path");
    fill_tab(cub, fd);
    close (fd);
    check_map(cub->conf->map);
}