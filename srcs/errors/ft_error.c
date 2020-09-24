#include "cub.h"

// les fonctions del prennent des pointeurs sur items pour pouvoir set a NULL.
// J'ai essayé d'imaginer une syntaxe pour que ça rentre dans ces fonctions...
void    destroy_cub(t_cub *cub)
{
    if (cub->conf->map)
        ft_tabdel(cub->conf->map);
    if (cub->rndr->img)
        ft_int_tabdel(cub->rndr->img, cub->conf->res_w, cub->conf->res_h);
    if (cub->conf->path_no)
        ft_strdel(cub->conf->path_no);
    if (cub->conf->path_ea)
        ft_strdel(cub->conf->path_ea);
    if (cub->conf->path_we)
        ft_strdel(cub->conf->path_we);
    if (cub->conf->path_so)
        ft_strdel(cub->conf->path_so);
    if (cub->conf->path_sp)
        ft_strdel(cub->conf->path_sp);
    if (cub)
        destroy(cub);
}

// On free tout et on fait exit() (qui est sensé tout free a ce qui parait, mais bon)
void    ft_error(char *str)
{
    ft_putstr(str);
/*    if (cub)
        destroy_cub(cub);*/
/*    if (line)
        ft_strdel(line);*/
    exit(1);
}