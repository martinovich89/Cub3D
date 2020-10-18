/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/17 00:25:13 by martin            #+#    #+#             */
/*   Updated: 2020/10/17 00:25:14 by martin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	init_player(t_env *env)
{
	init_dir(env);
	init_pos(env);
	init_fov(env);
	init_plane(env);
}

void	init_conf(t_conf *conf)
{
	conf->res_w = -1;
	conf->res_h = -1;
}

void	init_img(t_data *img)
{
	img->h = 0;
	img->w = 0;
}

void	init_textures(t_env *env)
{
	if (!(env->tex[0].img = mlx_xpm_file_to_image(env->mlx
	, env->conf->path_no, &env->tex[0].w, &env->tex[0].h)))
		ft_error("failed to allocate tex[0].img\n", env);
	if (!(env->tex[0].addr = mlx_get_data_addr(env->tex[0].img
	, &env->tex[0].bpp, &env->tex[0].line_length, &env->tex[0].endian)))
		ft_error("failed to allocate tex[0].addr\n", env);
	if (!(env->tex[1].img = mlx_xpm_file_to_image(env->mlx
	, env->conf->path_ea, &env->tex[1].w, &env->tex[1].h)))
		ft_error("failed to allocate tex[1].img\n", env);
	if (!(env->tex[1].addr = mlx_get_data_addr(env->tex[1].img
	, &env->tex[1].bpp, &env->tex[1].line_length, &env->tex[1].endian)))
		ft_error("failed to allocate tex[1].addr\n", env);
	if (!(env->tex[2].img = mlx_xpm_file_to_image(env->mlx
	, env->conf->path_we, &env->tex[2].w, &env->tex[2].h)))
		ft_error("failed to allocate tex[2].img\n", env);
	if (!(env->tex[2].addr = mlx_get_data_addr(env->tex[2].img
	, &env->tex[2].bpp, &env->tex[2].line_length, &env->tex[2].endian)))
		ft_error("failed to allocate tex[2].addr\n", env);
	if (!(env->tex[3].img = mlx_xpm_file_to_image(env->mlx
	, env->conf->path_so, &env->tex[3].w, &env->tex[3].h)))
		ft_error("failed to allocate tex[3].img\n", env);
	if (!(env->tex[3].addr = mlx_get_data_addr(env->tex[3].img
	, &env->tex[3].bpp, &env->tex[3].line_length, &env->tex[3].endian)))
		ft_error("failed to allocate tex[3].addr\n", env);
}

void	init_mlx(t_env *env)
{
	if (!(env->mlx = mlx_init()))
		ft_error("failed to allocate mlx\n", env);
	if (!env->conf->is_bmp)
		if (!(env->win = mlx_new_window(env->mlx
		, env->conf->res_w, env->conf->res_h, "cub3D")))
			ft_error("failed to allocate win\n", env);
	if (!(env->img.img = mlx_new_image(env->mlx
	, env->conf->res_w, env->conf->res_h)))
		ft_error("failed to allocate img.img\n", env);
	if (!(env->img.addr = mlx_get_data_addr(env->img.img
	, &env->img.bpp, &env->img.line_length, &env->img.endian)))
		ft_error("failed to allocate img.addr\n", env);
	init_textures(env);
	if (!(env->sp.tex.img = mlx_xpm_file_to_image(env->mlx
	, env->conf->path_sp, &env->sp.tex.w, &env->sp.tex.h)))
		ft_error("failed to allocate sp.tex.img\n", env);
	if (!(env->sp.tex.addr = mlx_get_data_addr(env->sp.tex.img
	, &env->sp.tex.bpp, &env->sp.tex.line_length, &env->sp.tex.endian)))
		ft_error("failed to allocate sp.tex.addr\n", env);
	if (!(env->rndr->sheet =
	ft_build_uint_tab(env->conf->res_w, env->conf->res_h)))
		ft_error("failed to allocate rndr->sheet\n", env);
}
