/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rndr_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/17 00:28:37 by martin            #+#    #+#             */
/*   Updated: 2020/10/17 00:28:38 by martin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void			my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bpp / 8));
	*(unsigned int *)dst = color;
}

void			reset_sheet(t_env *env)
{
	int i;
	int j;

	i = 0;
	while (i < env->conf->res_h)
	{
		j = 0;
		while (j < env->conf->res_w)
		{
			env->rndr->sheet[i][j] = 0;
			j++;
		}
		i++;
	}
}

void			draw_image(t_env *env, t_data *data, unsigned int **tab)
{
	int x;
	int y;

	y = 0;
	while (y < env->conf->res_h)
	{
		x = 0;
		while (x < env->conf->res_w)
		{
			my_mlx_pixel_put(data, x, y, tab[y][x]);
			x++;
		}
		y++;
	}
}
