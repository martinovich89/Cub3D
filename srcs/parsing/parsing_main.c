#include "cub.h"
#define MAX_RES_W 1920
#define MAX_RES_H 1080

// vérif res
int     check_res(char *line)
{
    line += ft_skip_space(line);
    if (ft_atoi(line) < 300)
        return (1);
    line += ft_skip_digit(line);
    if (ft_atoi(line) < 300)
        return (1);
    line += ft_skip_digit(line);
    line += ft_skip_space(line);
    if (*line)         // si apres avoir tout skip, on a encore autre chose que des espaces...
        return (1);
    return (0);
}

// Vérif validité path.
int     check_path(char *str)
{
    int     fd;

    str += ft_skip_space(str);
    if ((fd = open(str, O_RDONLY)) <= 0)
        return (1);
    else
    {
        close(fd);
        return (0);
    }
}

// Juste pour mettre le path dans la structure.
char    *set_tex_path(char *str)
{
    char *tex_path;

    tex_path = NULL;
    str += ft_skip_space(str);
    if (!(tex_path = ft_strdup(str)))
        ft_error();
    return (tex_path);
}

// Skip les lettres / espaces / virgules, check ques les chiffres soient bons, et set.
int     set_ceiling(t_cub *cub, char *line)
{
    line += ft_skip_alpha(line);
    line += ft_skip_space(line);
    if (!ft_isdigit(*line) || ft_atoi(line) > 255 || ft_atoi(line) < 0)
        return (1);
    cub->conf->ceil_r = (unsigned char)ft_atoi(line);
    line += ft_skip_digit(line);
    while (is_charset_str(line, " ,"))
        line++;
    if (!ft_isdigit(*line) || ft_atoi(line) > 255 || ft_atoi(line) < 0)
        return (1);
    cub->conf->ceil_g = (unsigned char)ft_atoi(line);
    line += ft_skip_digit(line);
    while (is_charset_str(line, " ,"))
        line++;
    if (!ft_isdigit(*line) || ft_atoi(line) > 255 || ft_atoi(line) < 0)
        return (1);
    cub->conf->ceil_b = (unsigned char)ft_atoi(line);
    line += ft_skip_digit(line);
    line += ft_skip_space(line);
    return (*line ? 1 : 0);
}

int     set_floor(t_cub *cub, char *line)
{
    line += ft_skip_alpha(line);
    line += ft_skip_space(line);
    if (!ft_isdigit(*line) || ft_atoi(line) > 255 || ft_atoi(line) < 0)
        return (1);
    cub->conf->floo_r = (unsigned char)ft_atoi(line);
    line += ft_skip_digit(line);
    while (is_charset_str(line, " ,"))
        line++;
    if (!ft_isdigit(*line) || ft_atoi(line) > 255 || ft_atoi(line) < 0)
        return (1);
    cub->conf->floo_g = (unsigned char)ft_atoi(line);
    line += ft_skip_digit(line);
    while (is_charset_str(line, " ,"))
        line++;
    if (!ft_isdigit(*line) || ft_atoi(line) > 255 || ft_atoi(line) < 0)
        return (1);
    cub->conf->floo_b = (unsigned char)ft_atoi(line);
    line += ft_skip_digit(line);
    line += ft_skip_space(line);
    return (*line ? 1 : 0);
}

// On check validité, skip les lettres, récupère premiers chiffres, skip to next, récupère next.
int     parse_res(t_cub *cub, char *line)
{
    if (check_res(line + 1))
        return (1);
    line += ft_skip_alpha(line);
    cub->conf->res_w = (ft_atoi(line) > MAX_RES_W) ? MAX_RES_W : ft_atoi(line);
    line += ft_skip_space(line);
    line += ft_skip_digit(line);
    cub->conf->res_h = (ft_atoi(line) > MAX_RES_H) ? MAX_RES_H : ft_atoi(line);
    return (0);
}

// Check validité du path et set variable. Err de malloc à gérer. "+ 2" : skip les lettres
// Pour le malloc, je dirais qu'il faut set les paths à "NO ", comme ça on vérifie si null et on return 1.
int     parse_tex(t_cub *cub, char *line)
{
    if (check_path(line + 2))   
        return (1);
    if (ft_strncmp(line, "NO ", 3))
        // return (((cub->conf->path_no = set_tex_path(line + 2)) == NULL) ? 1 : 0); // autre façon de gérer err malloc.
        cub->conf->path_no = set_tex_path(line + 2);
    else if (ft_strncmp(line, "EA ", 3))
        cub->conf->path_ea = set_tex_path(line + 2);
    else if (ft_strncmp(line, "WE ", 3))
        cub->conf->path_we = set_tex_path(line + 2);
    else if (ft_strncmp(line, "SO ", 3))
        cub->conf->path_so = set_tex_path(line + 2);
    else if (ft_strncmp(line, "S ", 2))
        cub->conf->path_sp = set_tex_path(line + 1);
    if (!(cub->conf->path_no && cub->conf->path_ea && cub->conf->path_we
    && cub->conf->path_so && cub->conf->path_sp)) // si 1 path == NULL, erreur de malloc.
        return (1);
    return (0);
}

//check validité des couleurs du plafond / sol.
int     parse_clr(t_cub *cub, char *line)
{
    /*if (check_clr(line))
        return (1);*/
    if (!(ft_strncmp(line, "C ", 2)))
        return ((set_ceiling(cub, line)) ? 1 : 0);
    else
        return ((set_floor(cub, line)) ? 1 : 0);
    /*line += ft_skip_space(line);
    cub->conf->ceil_r = ft_atoi(line);
    line += ft_skip_digit(line);
    while (is_charset_str(line, " ,"))
        line++;
    cub->conf->ceil_g = ft_atoi(line);
    line += ft_skip_digit(line);
    while (is_charset_str(line, " ,"))
        line++;
    cub->conf->ceil_b = ft_atoi(line);    
    return */
}

// La fameuse forêt d'ifs (c'est toxique askip') pour detecter et parser. 
int     cmp_and_parse(t_cub *cub, char *line)
{
    int ret;

    if (!ft_strncmp(line, "R ", 2))
        ret = parse_res(cub, line);
    else if (!ft_strncmp(line, "NO ", 3))
        ret = parse_tex(cub, line);
    else if (!ft_strncmp(line, "EA ", 3))
        ret = parse_tex(cub, line);
    else if (!ft_strncmp(line, "WE ", 3))
        ret = parse_tex(cub, line);
    else if (!ft_strncmp(line, "SO ", 3))
        ret = parse_tex(cub, line);
    else if (!ft_strncmp(line, "S ", 2))
        ret = parse_tex(cub, line);
    else if (!ft_strncmp(line, "C ", 2))
        ret = parse_clr(cub, line);
    else if (!ft_strncmp(line, "F ", 2))
        ret = parse_clr(cub, line);
    else if (is_charset_str(line, " \n\t\v\f\r") || !line[0])
        ret = 0;
    else
        ret = 1;
    return (ret);
}

// La boucle avec get_next_line, ou on incrémente un i pour vérifier le nombre de params.
int     init_parse(t_cub *cub, int fd)
{
    char    *line;
    int     i;

    i = 0;
    while (get_next_line(fd, &line) >= 0 && !(is_charset_str(line, " 1") && is_in_str(line, '1')))
    {
        if (cmp_and_parse(cub, line))
            return (1);
        i++;
        free(&line);
    }
    if (i != 8)
        return (1);
    return (0);
}

// Le main.
int     parsing_main(t_cub *cub, int fd)
{
    if (init_parse(cub, fd))
        return (1);
    return (0);
}

int main(void)
{
    int ret;
    t_cub *cub;

    if (!(cub = malloc(sizeof(t_cub))))
        return (1);
    ret = parsing_main(cub, open("/home/martin/Desktop/42-projects/Cub3D/conf.cub", O_RDONLY));
    if (cub)
    destroy(cub);
    return (ret);
}

// LE CEILING ET FLOOR RESTENT A GERER. PB DE TYPAGE !