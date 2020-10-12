#ifndef CUB_H
#define CUB_H

#include "libft.h"
#include "get_next_line.h"
#include "mlx.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

# ifndef MAX_RES_W
#  define MAX_RES_W 1920
# endif

# ifndef MAX_RES_H
#  define MAX_RES_H 1080
# endif

# ifndef CONF_PATH
#  define CONF_PATH "/home/martin/Desktop/42-projects/Cub3D/conf.cub"
# endif

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
	int		left;
	int		right;
	int		up;
	int		down;
	int		strafe_left;
	int		strafe_right;
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
void			parse_map(t_env *env);
void			translation(t_env *env, int nb);
float			rad_conv(float angle);

void			plane_calc(t_vector dir, t_vector *plane, float angle);
void			cam_calc(t_env *env, int nb);
void			ray_calc(t_env *env);
void			gap_calc(t_env *env);
void			mapXY_calc(t_map *map);
void			sign_calc(t_map *map);
void			next_calc(t_env *env);
void			wall_dist_calc(t_env *env);
void			perp_wall_dist_calc(t_map *map);
void			wall_calc(t_env *env);
void			ratio_calc(t_env *env);
void			wallX_calc(t_env *env);
void			pick_texture(t_env *env);
void			texPos_calc(t_env *env);
void			texXY_calc(t_env *env);
int				get_tex_color(t_env *env);
void			fill_stripe(t_env *env, int i);




void			init_dir(t_env *env);
void			init_pos(t_env *env);
void			init_fov(t_env *env);
void			init_plane(t_env *env);
void			init_player(t_env *env);
void			init_dir(t_env *env);
void			init_pos(t_env *env);
void			init_fov(t_env *env);
void			init_plane(t_env *env);

int				is_valid_path(char *str);
void			set_tex_path(t_env *env, char *path, int nb);
void			parse_tex(t_env *env, char *line, int nb);
void			set_colr(t_env *env, char *str, int nb);
int				is_valid_colr(char *str);
void			parse_color(t_env *env, char *line, int nb);
void			set_res_h(t_env *env, int nb);
void			set_res_w(t_env *env, int nb);
void			parse_res(t_env *env, char *line);

void			check_map_line(t_env *env, char *line);
int				is_valid_char(t_conf *conf, size_t i, size_t j);
int				is_valid_map(t_conf *conf);

#endif