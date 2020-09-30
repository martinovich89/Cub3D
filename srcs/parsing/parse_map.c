#include "cub.h"

void    set_w_h(t_cub *cub)
{
    int     fd;
    char    *line;

    fd = open(cub->conf->file, O_RDONLY);
    while (get_next_line(fd, &line) > 0 && !is_charset_str(line, " 1"))
        free(line);
    if (!is_charset_str(line, " 1") || !is_in_str(line, '1'))
        ft_error("no map or spaces in line");
    if (ft_strlen(line) > (size_t)cub->conf->map_w)
            cub->conf->map_w = ft_strlen(line);
        cub->conf->map_h++;
    if (line)
        free(line);
    while (get_next_line(fd, &line) > 0)
    {
        if (!is_charset_str(line, "NEWS 012") || !is_in_str(line, '1'))
            ft_error("invalid map line (map must be last element)");
        if (ft_strlen(line) > (size_t)cub->conf->map_w)
            cub->conf->map_w = ft_strlen(line);
        cub->conf->map_h++;
    }
    if (ft_strlen(line) > (size_t)cub->conf->map_w)
        cub->conf->map_w = ft_strlen(line);
    cub->conf->map_h++;
    if (line)
        free(line);
    close(fd);
}

char    **ft_build_tab(int xmax, int ymax)
{
    char    **tab;
    int     i;

    if (!(tab = malloc(sizeof(char) * ymax + 1)))
        ft_error("ram allocation error");
    i = 0;
    while (i < ymax)
    {
        if (!(tab[i] = calloc((xmax + 1), 1)))
            ft_error("ram allocation error");
        ft_memset(tab[i], ' ', xmax);
        i++;
    }
    return (tab);
}

void    fill_tab(t_cub *cub)
{
    char    *line;
    int     fd;
    int     i;

    fd = open(cub->conf->file, O_RDONLY);
    i = 0;
	while (get_next_line(fd, &line) > 0)
	{
		if (is_charset_str(line, "NEWS 012"))
		{
			strcpy(cub->conf->map[i], line);
            i++;
		}
		free(line);
	}
    free(line);
    close(fd);
}

void    parse_map(t_cub *cub)
{
    set_w_h(cub);
    cub->conf->map = ft_build_tab(cub->conf->map_w, cub->conf->map_h);
    fill_tab(cub);
}

/*void    parse_map()
{
    char    *line;

    open();
    while(get_next_line())
    {

    }
    free();
    close();
}

void    parse_params()
{

}

void    launch_game()
{
    parse_params();
    parse_map();
}

int main()
{
    launch_game()
}*/