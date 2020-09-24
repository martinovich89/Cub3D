#include "cub.h"

// Check de la position de la map.
void    check_map_pos(char **line, int fd)
{
    while (get_next_line(fd, line) > 0  // 3e condition : a voir si on tolere lignes avec que des espaces
    && !is_charset_str(*line, " 1"))
    {
        if (*line)
            ft_strdel(*line);
    }
    if (!is_charset_str(*line, " 1"))
        ft_error("no map");
    ft_strdel(*line);
    while (get_next_line(fd, line) > 0)
    {
        if (!(is_charset_str(*line, "012 NEWS") || *line[0] != '\0'))  // 2e condition : a voir si on tolere lignes vides
            ft_error("map must be the last element in .cub file");
        if (*line)
            ft_strdel(*line);
    }
    if (*line)
        ft_strdel(*line);
}

// Parcours du fichier pour déterminer xmax et ymax de la map.
void    set_w_h(int *w, int *h, int fd)
{
    char *line;

    line = NULL;
    check_map_pos(&line, fd);
    while (get_next_line(fd, &line) > 0)
    {
        if (is_charset_str(line, "012 NEWS"))
        {
            if (ft_strlen(line) > *w)
                *w = ft_strlen(line);
            *h++;
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

    tab = malloc(sizeof(char) * h + 1);
    i = 0;
    while (i < h)
    {
        tab[i] = calloc(w, 1);
        i++;
    }
    return (tab);
}

void    parse_map(t_cub *cub, int fd)
{
    set_w_h(&cub->conf->res_w, &cub->conf->res_h, fd);
    cub->conf->map = ft_build_tab(cub->conf->res_w, cub->conf->res_h);
    check_map(cub->conf->map);
}