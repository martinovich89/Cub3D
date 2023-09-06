/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martin <martin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 23:36:00 by martin            #+#    #+#             */
/*   Updated: 2023/09/06 20:10:04 by martin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

# include "libft.h"
# include "get_next_line.h"
# include "mlx.h"
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <errno.h>

# ifndef FOV
#  define FOV 90
# endif

# ifndef M_PI
#  define M_PI 3.14159265358979323846
# endif

typedef struct		s_vector
{
	float			x;
	float			y;
	float			coef;
	float			intercept;
	float			posx;
	float			posy;
}					t_vector;

typedef struct		s_data
{
	void			*img;
	char			*addr;
	int				bpp;
	int				line_length;
	int				endian;
	int				w;
	int				h;
}					t_data;

typedef struct		s_sprite
{
	t_data			tex;
	t_vector		pos;
	t_vector		vector;
	t_vector		hit_line;
	t_vector		hit;
	float			hit_posx;
	float			hit_posy;
	float			dist;
	float			pdist;
	int				scaledh;
	int				top;
	int				bot;
	float			hitx;
	float			texpos;
	float			ratio;
	int				texx;
	int				texy;
	int				ok;
}					t_sprite;

typedef struct		s_conf
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
	int				end_map;
}					t_conf;

typedef struct		s_map
{
	int				x;
	int				y;
	float			fov;
	t_vector		dir;
	t_vector		pos;
	t_vector		plane;
	t_vector		inter;
	float			cam_ratio;
	t_vector		ray;
	float			nextx;
	float			nexty;
	float			gapx;
	float			gapy;
	int				signx;
	int				signy;
	int				side;
	float			perp_wall_dist;
	float			rota;
}					t_map;

typedef struct		s_rndr
{
	unsigned int	**sheet;
	int				wallh;
	int				wall_bot;
	int				wall_top;
	float			wallx;
	float			ratio;
	t_data			*tex;
	float			texposx;
	int				texx;
	int				texy;
}					t_rndr;

typedef struct		s_env
{
	t_conf			*conf;
	t_map			*map;
	t_rndr			*rndr;
	t_data			img;
	t_data			tex[4];
	t_sprite		sp;
	void			*mlx;
	void			*win;
	int				left;
	int				right;
	int				up;
	int				down;
	int				strafe_left;
	int				strafe_right;
	int				sprite;
}					t_env;

typedef struct		s_bmp
{
	int				im_size;
	int				zero;
	int				data_offset;
	int				size_dib;
	short int		planes;
	short int		bpp;
}					t_bmp;

void				rotation(t_vector *vector, float angle);
void				new_pl_pos(t_env *env);
void				new_pl_dir(t_env *env, int sign);
void				ray_casting(t_env *env);
unsigned int		**ft_build_uint_tab(int w, int h);
void				init_mlx(t_env *env);
void				ft_clear_env(t_env *env);
void				ft_error(char *str, t_env *env);
void				parse_params(t_env *env);
void				parse_map(t_env *env);
void				translation(t_env *env, int nb);
float				rad_conv(float angle);

void				set_dir(t_vector *vector, float x, float y);
void				set_pos(t_vector *vector, float x, float y);
void				plane_calc(t_vector dir, t_vector *plane, float angle);
void				cam_calc(t_env *env, int nb);
void				ray_calc(t_env *env);
void				gap_calc(t_env *env);
void				mapxy_calc(t_map *map);
void				sign_calc(t_map *map);
void				next_calc(t_env *env);
void				wall_dist_calc(t_env *env, int i);
void				perp_wall_dist_calc(t_map *map);
void				wall_calc(t_env *env);
void				ratio_calc(t_env *env);
void				wallx_calc(t_env *env);
void				pick_texture(t_env *env);
void				texpos_calc(t_env *env);
void				texxy_calc(t_env *env);
int					get_tex_color(t_env *env);
void				fill_stripe(t_env *env, int i);

void				sprite_pos_calc(t_env *env);
void				sprite_dist_calc(t_env *env);
void				perp_sprite_dist_calc(t_env *env);
void				sprite_scaled_height_calc(t_env *env);
void				sprite_limits_calc(t_env *env);
void				hit_line_calc(t_env *env);
void				intersection_calc(t_env *env);
void				set_hit(t_env *env);
void				sprite_hit_calc(t_env *env);
void				sprite_ratio_calc(t_env *env);
void				sprite_texpos_calc(t_env *env);
void				sprite_texxy_calc(t_env *env);
void				sprite_calc(t_env *env, int i);
int					get_sprite_color(t_env *env);
void				sprite_fill_stripe(t_env *env, int i);
void				set_hitpos_un(t_env *env);
void				set_hitpos_deux(t_env *env);
void				set_hitpos_trois(t_env *env);
void				set_hitpos_quatre(t_env *env);

int					close_window(t_env *env);
int					key_press(int keycode, t_env *env);
int					key_release(int keycode, t_env *env);

void				my_mlx_pixel_put(t_data *data, int x, int y, int color);
void				reset_sheet(t_env *env);
void				draw_image(t_env *env, t_data *data, unsigned int **tab);

void				init_dir(t_env *env);
void				init_pos(t_env *env);
void				init_fov(t_env *env);
void				init_plane(t_env *env);
void				init_player(t_env *env);
void				init_conf(t_conf *conf);
void				init_img(t_data *img);
void				init_textures(t_env *env);
void				init_mlx(t_env *env);
t_env				*env_alloc();
void				rndr_alloc(t_env *env);
void				map_alloc(t_env *env);
void				conf_alloc(t_env *env);

int					is_valid_path(char *str);
void				set_tex_path(t_env *env, char *path, int nb);
void				parse_tex(t_env *env, char *line, int nb);
void				set_colr(t_env *env, char *str, int nb);
int					is_valid_colr(char *str);
void				parse_color(t_env *env, char *line, int nb);
void				set_res_wh(t_env *env, int x, int y);
void				parse_res(t_env *env, char *line);

void				check_map_line(t_env *env, char *line);
int					is_valid_char(t_conf *conf, size_t i, size_t j);
int					is_valid_map(t_conf *conf);

void				save(t_env *env);

#endif
