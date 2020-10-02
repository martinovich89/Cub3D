#include "cub.h"
# define MAX_RES_W 1920
# define MAX_RES_H 1080

// Setter de la hauteur de résolution.
void    set_res_h(t_env *env, int nb)
{
    if (nb > MAX_RES_H)
        env->conf->res_h = MAX_RES_H;
    if ((nb <= MAX_RES_H) && nb >= 300)
        env->conf->res_h = nb;
}

// Setter de la largeur de résolution.
void    set_res_w(t_env *env, int nb)
{
    if (nb > MAX_RES_W)
        env->conf->res_w = MAX_RES_W;
    if ((nb <= MAX_RES_W) && nb >= 300)
        env->conf->res_w = nb;
}

// Check de la string de résolution et envoi aux setters.
void    parse_res(t_env *env, char *line)
{
    char **tab;

    if (!(tab = ft_split(line, ' ')))
        ft_error("ram allocation error", env);
    if (ft_tablen(tab) != 3 || ft_atoi(tab[1]) < 300 || ft_atoi(tab[2]) < 300)
    {
        ft_tabdel(tab);
        ft_error("invalid res line", env);
    }
    set_res_w(env, ft_atoi(tab[1]));
    set_res_h(env, ft_atoi(tab[2]));
    if (tab)
        ft_tabdel(tab);
}

// /!\ A ajouter : is_valid_tex()
int     is_valid_path(char *str)
{
    int fd;

    if ((fd = open(str, O_RDONLY)) < 0)
        return (0);
    close(fd);
    return (1);
}

// Setter des paths de textures.
void    set_tex_path(t_env *env, char *path, int nb)
{
    if (nb == 1)
        if (!(env->conf->path_no = ft_strdup(path)))
            ft_error("ram allocation error", env);
    if (nb == 2)
        if (!(env->conf->path_ea = ft_strdup(path)))
            ft_error("ram allocation error", env);
    if (nb == 3)
        if (!(env->conf->path_we = ft_strdup(path)))
            ft_error("ram allocation error", env);
    if (nb == 4)
        if (!(env->conf->path_so = ft_strdup(path)))
            ft_error("ram allocation error", env);
    if (nb == 5)
        if(!(env->conf->path_sp = ft_strdup(path)))
            ft_error("ram allocation error", env);
}

// Check du format des paths de textures, et envoi au setter.
void    parse_tex(t_env *env, char *line, int nb)
{
    char **tab;

    if (!(tab = ft_split(line, ' ')))
        ft_error("ram allocation error", env);
    if (ft_tablen(tab) != 2 || !is_valid_path(tab[1]))
    {
        ft_tabdel(tab);
        ft_error("invalid texture line", env);
    }
    set_tex_path(env, tab[1], nb);
    if (tab)
        ft_tabdel(tab);
}

// Le setter des colors du sol et du plafond.
void    set_colr(t_env *env, char *str, int nb)
{
    char    **tab;

    if (!(tab = ft_split(str, ',')))
        ft_error("ram allocation error", env);
    if (nb == 1)
    {
        env->conf->ceil_r = (unsigned char)ft_atoi(tab[0]);
        env->conf->ceil_g = (unsigned char)ft_atoi(tab[1]);
        env->conf->ceil_b = (unsigned char)ft_atoi(tab[2]);
        env->conf->ceil_is_set = 1;
    }
    if (nb == 2)
    {
        env->conf->floo_r = (unsigned char)ft_atoi(tab[0]);
        env->conf->floo_g = (unsigned char)ft_atoi(tab[1]);
        env->conf->floo_b = (unsigned char)ft_atoi(tab[2]);
        env->conf->floo_is_set = 1;
    }
    if (tab)
        ft_tabdel(tab);
}

// Le check du format des strings décrivant les couleurs, et des values.
int     is_valid_colr(char *str)
{
    int i;

    i = 0;
    if (!is_charset_str(str, "0123456789,"))
        return (0);
    if (ft_atoi(str + i) > 255 || ft_atoi(str + i) < 0 || !ft_isdigit(str[i]))
        return (0);
    i += ft_skip_digit(str + i);
    if (str[i++] != ',')
        return (0);
    if (ft_atoi(str + i) > 255 || ft_atoi(str + i) < 0 || !ft_isdigit(str[i]))
        return (0);
    i += ft_skip_digit(str + i);
    if (str[i++] != ',')
        return (0);
    if (ft_atoi(str + i) > 255 || ft_atoi(str + i) < 0 || !ft_isdigit(str[i]))
        return (0);
    i += ft_skip_digit(str + i);
    if (str[i])
        return (0);
    return (1);
}

// On check et on envoie pour set les couleurs.
void    parse_colr(t_env *env, char *line, int nb)
{
    char **tab;

    if (!(tab = ft_split(line, ' ')))
        ft_error("erreur d'allocation mémoire", env);
    if (ft_tablen (tab) != 2 || !is_valid_colr(tab[1]))
    {
        ft_tabdel(tab);
        ft_error("invalid color line in .cub file", env);
    }
    set_colr(env, tab[1], nb);
    if (tab)
        ft_tabdel(tab);
}

// La fameuse forêt d'if (askip c'est toxique) pour rediriger vers fonctions.
int     cmp_and_parse(t_env *env, char *line)
{
    if (*line)
    {
        if (!ft_strncmp(line, "R ", 2))
            parse_res(env, line);
        else if (!ft_strncmp(line, "NO ", 3))
            parse_tex(env, line, 1);
        else if (!ft_strncmp(line, "EA ", 3))
            parse_tex(env, line, 2);
        else if (!ft_strncmp(line, "WE ", 3))
            parse_tex(env, line, 3);
        else if (!ft_strncmp(line, "SO ", 3))
            parse_tex(env, line, 4);
        else if (!ft_strncmp(line, "S ", 2))
            parse_tex(env, line, 5);
        else if (!ft_strncmp(line, "C ", 2))
            parse_colr(env, line, 1);
        else if (!ft_strncmp(line, "F ", 2))
            parse_colr(env, line, 2);
        else
            ft_error("invalid line in .cub file", env);
        return (1);
    }
    return (0);
}

// Check de la validité de la conf.
int     is_valid_conf(t_env *env)
{
    if (env->conf->res_w == -1 || env->conf->res_h == -1)
        return (0);
    if (!env->conf->path_no || !env->conf->path_ea || !env->conf->path_we
    || !env->conf->path_so || !env->conf->path_sp)
        return (0);
    if (!env->conf->ceil_is_set || !env->conf->floo_is_set)
        return (0);
    return (1);
}

// La boucle qui fait gnl pour checker les lignes 1 par 1.
void    init_parsing(t_env *env)
{
    char    *line;
    int     i;
    int     fd;

    fd = open(env->conf->file, O_RDONLY);
    i = 0;
    while (get_next_line(fd, &line) > 0 && !(is_charset_str(line, " 1") && is_in_str(line, '1')))
    {
        if (cmp_and_parse(env, line))
            i++;
        ft_strdel(line);
    }
    if (line)
        ft_strdel(line);
    if (i != 8)
        ft_error("invalid parameter lines count", env);
    if (!is_valid_conf(env))
        ft_error("one or more parameters are invalid", env);
    close(fd);
}

// On déclare la struct, on ouvre le fichier de conf, on envoie le parsing.
void    parse_params(t_env *env)
{
/*   env= malloc(sizeof(t_env));
    fd = open(CONF_PATH, O_RDONLY);*/
    init_parsing(env);
}
