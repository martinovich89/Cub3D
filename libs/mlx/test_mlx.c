/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julnolle <julnolle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 15:55:10 by julnolle          #+#    #+#             */
/*   Updated: 2020/08/12 09:03:34 by julnolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_close(t_mlx *mlx)
{
	mlx_clear_window(mlx->mlx_ptr, mlx->mlx_win);
	free(mlx->mlx_ptr);
	exit(SUCCESS);
}

int	key_event(int key, t_mlx *mlx)
{
	if (key == ESC)
		ft_close(mlx);
	return (0);
}

int		rgb_to_int(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}

void	print_square(t_mlx *mlx)
{
	int y;
	int x;
	int color;

	color = rgb_to_int(119, 206, 36);
	x = 0;
	while(x < 300)
	{
		y = 0;
		while (y < 300)
		{
			mlx_pixel_put(mlx->mlx_ptr, mlx->mlx_win, x, y, color);
			y++;
		}
		x++;
	}
}

int	test_mlx(void)
{
	t_mlx	mlx;
	t_win	win;

	win.h = 600;
	win.w = 600;
	if ((mlx.mlx_ptr = mlx_init()) == NULL)
		return (FAILURE);
	mlx.mlx_win = mlx_new_window(mlx.mlx_ptr, win.w, win.h, "Test MLX");
	if (mlx.mlx_win == NULL)
		return (FAILURE);
	print_square(&mlx);
	mlx_hook(mlx.mlx_win, 2, (1L << 0), key_event, &mlx);
	mlx_hook(mlx.mlx_win, 17, (1L << 17), ft_close, &mlx);
	mlx_loop(mlx.mlx_ptr);
	return (SUCCESS);
}

int main(void)
{
	if (test_mlx() == FAILURE)
	//	ft_putendl("Erreur MLX");
	return (0);
}
