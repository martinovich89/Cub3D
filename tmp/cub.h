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

# ifndef FOV
#  define FOV 90
# endif

# ifndef M_PI
#  define M_PI 3.14159265358979323846
# endif

typedef struct  s_vector
{
    float x;
    float y;
}               t_vector;

typedef struct  s_conf
{
    char            *file;
    int             res_w;
    int             res_h;
    char            *path_no;
    char            *path_ea;
    char            *path_we;
    char            *path_so;
    char            *path_sp;
    unsigned int    ceil;
    int             ceil_is_set;
    unsigned int    floo;
    int             floo_is_set;
    char            **map;
    int             map_w;
    int             map_h;
    int             is_bmp;
    char            dir;
}               t_conf;

typedef struct  s_map
{
    int         x;
    int         y;
    float       fov;
    char        **map_tab;
    t_vector    *dir;
    t_vector    *pos;
    t_vector    *plane;
    float       cam_ratio;
    t_vector    *ray;
    float       nextX;
    float       nextY;
    float       gapX;
    float       gapY;
    int         signX;
    int         signY;
    int         side;
    float       perp_wall_dist;
}               t_map;

typedef struct  s_rndr
{
    unsigned int    **img;
    int             texW; // Initialiser texW et texH !!
    int             texH; // Il semble que la fonction mlx_xpm_to_image() soit la solution pour set texW et texH !
    int             wallH;
    int             wall_bot;
    int             wall_top;
    float           wallX;
    float           ratio;
    float           texPos;
    int             texX;
    int             texY;
}               t_rndr;

typedef struct  s_cub
{
    t_conf  *conf;
    t_map   *map;
    t_rndr  *rndr;
}               t_cub;

void    ft_error(char *str);
void    parse_params(t_cub *cub);
void    parse_map();
float	plane_calc(t_vector *dir, t_vector *plane, float angle);
void	rotation(t_vector *vector, float angle);
void	new_pl_pos(t_cub *cub);

#endif