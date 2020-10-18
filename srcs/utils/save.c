/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 23:53:20 by martin            #+#    #+#             */
/*   Updated: 2020/10/16 23:53:30 by martin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

t_bmp			init_bmp(t_env *env)
{
	t_bmp bmp;

	bmp.im_size = env->conf->res_w * env->conf->res_h * 4;
	bmp.zero = 0;
	bmp.data_offset = 54;
	bmp.size_dib = 40;
	bmp.bpp = 32;
	return (bmp);
}

static void		write_header(t_env *env, int fd, t_bmp bmp)
{
	write(fd, &"BM", 2);
	write(fd, &bmp.im_size, 4);
	write(fd, &bmp.zero, 4);
	write(fd, &bmp.data_offset, 4);
	write(fd, &bmp.size_dib, 4);
	write(fd, &env->conf->res_w, 4);
	write(fd, &env->conf->res_h, 4);
	write(fd, &bmp.planes, 2);
	write(fd, &bmp.bpp, 2);
	write(fd, &bmp.zero, 8);
	write(fd, &bmp.zero, 8);
	write(fd, &bmp.zero, 8);
}

static void		write_img(t_env *env, int fd)
{
	int y;
	int x;

	y = env->conf->res_h;
	while (y-- >= 0)
	{
		x = 0;
		while (x < env->conf->res_w)
		{
			write(fd, &(env->img.addr
			[(y * env->conf->res_w * 4) + x++ * 4]), 4);
		}
	}
}

void			save(t_env *env)
{
	int		fd;
	t_bmp	bmp;

	errno = 0;
	if ((fd = open("save.bmp"
	, O_WRONLY | O_CREAT | O_TRUNC | O_APPEND, 0644)) < 0)
	{
		perror("l'erreur est");
		ft_clear_env(env);
	}
	bmp = init_bmp(env);
	write_header(env, fd, bmp);
	write_img(env, fd);
	close(fd);
	mlx_destroy_image(env->mlx, env->img.img);
}
