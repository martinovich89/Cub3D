/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julnolle <julnolle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 16:51:22 by julnolle          #+#    #+#             */
/*   Updated: 2020/08/11 18:26:41 by julnolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include <stdio.h>
# include <stdlib.h>
# include "mlx.h"
// # include "libft.h"

# define SUCCESS	0
# define FAILURE	-1
# define TRUE		1
# define FALSE		0

/*
** mlibx structure
*/

typedef struct		s_mlx
{
	void			*mlx_ptr;
	void			*mlx_win;
	int				max_w;
	int				max_h;
	void			*img;
	char			*addr;
	int				bpp;
	int				line_len;
	int				end;
	char			pad[4];
}					t_mlx;

/*
** window structure
*/

typedef struct		s_win
{
	int			w;
	int			h;
	double		x;
	double		y;
}					t_win;

/*
** Keycodes and screen size LINUX
*/
#  define MAX_W		1920
#  define MAX_H		1080

#  define ESC		65307
#  define LEFT		65361
#  define RIGHT		65363
#  define KEY_S		115

#endif
