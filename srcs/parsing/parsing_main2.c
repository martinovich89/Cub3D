#include "cub.h"
# define MAX_RES_W 1920
# define MAX_RES_H 1080

// Setter de la hauteur de résolution.
void    set_res_h(t_cub *cub, int nb)
{
    if (nb > MAX_RES_H)
        cub->conf->res_h = MAX_RES_H;
    if ((nb <= MAX_RES_H) && nb >= 300)
        cub->conf->res_h = MAX_RES_H;

}

// Setter de la largeur de résolution.
void    set_res_w(t_cub *cub, int nb)
{
    if (nb > MAX_RES_W)
        cub->conf->res_w = MAX_RES_W;
    if ((nb <= MAX_RES_W) && nb >= 300)
        cub->conf->res_w = MAX_RES_W;
}

// Check de la string de résolution et envoi aux setters.
void    parse_res(t_cub **cub, char **line)
{
    char **tab;

    if (!(tab = ft_split(*line, ' ')))
        ft_error(cub, line);
    if (ft_tablen(tab) != 3)
        ft_error(cub, line);
    if (ft_atoi(tab[1]) < 300 || ft_atoi(tab[2] < 300))
        ft_error(cub, line);
    set_res_w(*cub, ft_atoi(tab[1]));
    set_res_h(*cub, ft_atoi(tab[2]));
    if (tab);
        ft_tabdel(&tab);
}

int     ft_check_path(char *str)
{
    if (open(str, O_RDONLY) <= 0)
        return (1);
    return (0);
}

// Setter des paths de textures.
void    set_tex_path(t_cub **cub, char **line, int nb)
{
    if (nb == 1)
        if (!((*cub)->conf->path_no = ft_strdup(*line)))
            ft_error(cub, line);
    if (nb == 2)
        if (!((*cub)->conf->path_ea = ft_strdup(*line)))
            ft_error(cub, line);
    if (nb == 3)
        if (!((*cub)->conf->path_we = ft_strdup(*line)))
            ft_error(cub, line);
    if (nb == 4)
        if (!((*cub)->conf->path_so = ft_strdup(*line)))
            ft_error(cub, line);
    if (nb == 5)
        if(!((*cub)->conf->path_sp = ft_strdup(*line)))
            ft_error(cub, line);
}

// Check du format des paths de textures, et envoi au setter.
void    parse_tex(t_cub **cub, char **line, int nb)
{
    char **tab;

    if (!(tab = ft_split(*line, ' ')))
        ft_error(cub, line);
    if (ft_tablen (tab) != 2)
        ft_error(cub, line);
    if (ft_check_path(tab[1]))
        ft_error(cub, line);
    set_tex_path(cub, line, nb);
    if (tab)
        ft_tabdel(&tab);
}

// Le setter des colors du sol et du plafond.
void    set_clr(t_cub **cub, char **line, char *str, int nb)
{
    char    **tab;

    if (!(tab = ft_split(str, ',')))
        ft_error(cub, line);
    if (nb == 1)
        (*cub)->conf->ceil_r = (unsigned char)ft_atoi(tab[0]);
        (*cub)->conf->ceil_g = (unsigned char)ft_atoi(tab[1]);
        (*cub)->conf->ceil_b = (unsigned char)ft_atoi(tab[2]);
    if (nb == 2)
        (*cub)->conf->floo_r = (unsigned char)ft_atoi(tab[0]);
        (*cub)->conf->floo_g = (unsigned char)ft_atoi(tab[1]);
        (*cub)->conf->floo_b = (unsigned char)ft_atoi(tab[2]);
    if (tab)
        ft_tabdel(&tab);
}

// Le check du format des strings décrivant les couleurs, et des values.
int     ft_check_clr(char *str)
{
    int i;

    i = 0;
    if (!is_charset_str(str, "0123456789,"))
        return (1);
    if (ft_atoi(str + i) > 255 || ft_atoi(str + i) < 0 || !ft_isdigit(str[i]))
        return (1);
    i += ft_skip_digit(str + i);
    if (str[i++] != ',')
        return (1);
    if (ft_atoi(str + i) > 255 || ft_atoi(str + i) < 0 || !ft_isdigit(str[i]))
        return (1);
    i += ft_skip_digit(str + i);
    if (str[i++] != ',')
        return (1);
    if (ft_atoi(str + i) > 255 || ft_atoi(str + i) < 0 || !ft_isdigit(str[i]))
        return (1);
    i += ft_skip_digit(str + i);
    if (str[i])
        return (1);
    return (0);
}

// On check et on envoie pour set les couleurs.
void    parse_clr(t_cub **cub, char **line, int nb)
{
    char **tab;

    if (!(tab = ft_split(*line, ' ')))
        ft_error(cub, line);
    if (ft_tablen (tab) != 2)
        ft_error(cub, line);
    if (ft_check_clr(tab[1]));
        ft_error(cub, line);
    set_clr(cub, line, tab[1], nb);
    if (tab)
        ft_tabdel(&tab);
}

// La fameuse forêt d'if (askip c'est toxique) pour rediriger vers fonctions.
void    cmp_and_parse(t_cub **cub, char **line)
{
    if (**line)
    {
        if (!ft_strncmp(line, "R ", 2))
            parse_res(cub, line);
        else if (!ft_strncmp(line, "NO ", 3))
            parse_tex(cub, line, 1);
        else if (!ft_strncmp(line, "EA ", 3))
            parse_tex(cub, line, 2);
        else if (!ft_strncmp(line, "WE ", 3))
            parse_tex(cub, line, 3);
        else if (!ft_strncmp(line, "SO ", 3))
            parse_tex(cub, line, 4);
        else if (!ft_strncmp(line, "S ", 2))
            parse_tex(cub, line, 5);
        else if (!ft_strncmp(line, "C ", 2))
            parse_clr(cub, line, 1);
        else if (!ft_strncmp(line, "F ", 2))
            parse_clr(cub, line, 2);
        else
            ft_error(cub, line);
    }
}

// La boucle qui fait gnl pour checker les lignes 1 par 1.
void    init_parsing(t_cub **cub, int fd)
{
    char    *line;
    int     i;

    i = 0;
    while (get_next_line(fd, &line) >= 0 && !(is_charset_str(line, " 1") && is_in_str(line, '1')))
    {
        cmp_and_parse(cub, &line);
        i++;
        if (line)
            ft_strdel(&line);
    }
    if (i != 8)
        ft_error(cub, &line);
    if (line)
        ft_strdel(&line);
    return (0);
}

// On déclare la struct, on ouvre le fichier de conf, on envoie le parsing.
void    parsing_main()
{
    t_cub   *cub;
    int     fd;

    cub = malloc(sizeof(t_cub));
    fd = open(CONF_PATH, O_RDONLY);
    init_parsing(&cub, fd);
    if (fd > 0)
        close(fd);
}