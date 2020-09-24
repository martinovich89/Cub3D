#ifndef CUB_H
# define CUB_H

# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "libft.h"
# include "mlx.h"

# ifndef CONF_PATH
#  define CONF_PATH "/home/martin/Desktop/42-projects/Cub3D/conf.cub"
# endif

typedef struct  s_conf
{
    int             res_w;
    int             res_h;
    char            *path_no;
    char            *path_ea;
    char            *path_we;
    char            *path_so;
    char            *path_sp;
    unsigned char   ceil_r;
    unsigned char   ceil_g;
    unsigned char   ceil_b;
    int             ceil_is_set;
    unsigned char   floo_r;
    unsigned char   floo_g;
    unsigned char   floo_b;
    int             floo_is_set;
    char            **map;
}               t_conf;

/*
typedef struct  s_map
{
    int prout;
    char **map_tab;
}               t_map;
*/

typedef struct  s_rndr
{
    int             prout;
    unsigned int    **img;
}               t_rndr;

typedef struct  s_cub
{
    t_conf  *conf;
//    t_map   *map;
    t_rndr  *rndr;
}               t_cub;

void    ft_error(char *str);
void    parse_params(t_cub *cub, int fd);
void    parse_map();

#endif