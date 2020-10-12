#ifndef CUB_H
#define CUB_H

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "libft.h"
#include "get_next_line.h"
#include "mlx.h"

#ifndef CONF_PATH
#define CONF_PATH "/home/martin/Desktop/42-projects/Cub3D/conf.cub"
#endif

# ifndef FOV
#  define FOV 90
# endif

# ifndef M_PI
#  define M_PI 3.14159265358979323846
# endif

typedef struct	s_vector
{
	float x;
	float y;
}				t_vector;

typedef struct	s_data
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
	int		W;
	int		H;
}				t_data;

typedef struct	s_conf
{
	char			*file;
	int				res_w;
	int				res_h;
	char			*path_no;
	char			*path_ea;
	char			*path_we;
	char			*path_so;
	char			*path_sp;
	unsigned int	ceil;
	int				ceil_is_set;
	unsigned int	floo;
	int				floo_is_set;
	char			**map;
	int				map_w;
	int				map_h;
	int				is_bmp;
	char			player;
	char			dir;
}				t_conf;

typedef struct	s_map
{
	int			x;
	int			y;
	float		fov;
	char		**map_tab;
	t_vector	dir;
	t_vector	pos;
	t_vector	plane;
	float		cam_ratio;
	t_vector	ray;
	float		nextX;
	float		nextY;
	float		gapX;
	float		gapY;
	int			signX;
	int			signY;
	int			side;
	float		perp_wall_dist;
	float		rota;
}				t_map;

typedef struct	s_rndr
{
	unsigned int	**sheet;
	int				wallH;
	int				wall_bot;
	int				wall_top;
	float			wallX;
	float			ratio;
	t_data			*tex;
	float			texPosX;
	int				texX;
	int				texY;
}				t_rndr;

typedef struct	s_env
{
	t_conf	*conf;
	t_map	*map;
	t_rndr 	*rndr;
	t_data	img;
	t_data	tex[4];
	t_data	sp;
	void	*mlx;
	void	*win;
}				t_env;

void			rotation(t_vector *vector, float angle);
void			new_pl_pos(t_env *env);
void			new_pl_dir(t_env *env, int sign);
void			ray_casting(t_env *env);
unsigned int	**ft_build_uint_tab(int w, int h);
void			init_mlx(t_env *env);
void			ft_clear_env(t_env *env);
void			ft_error(char *str, t_env *env);
void			parse_params(t_env *env);
void			parse_map();
void			plane_calc(t_vector dir, t_vector *plane, float angle);
void			new_pl_pos(t_env *env);


#endif