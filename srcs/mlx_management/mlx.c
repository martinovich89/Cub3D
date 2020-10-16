#include "cub.h"

void			my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bpp / 8));
	*(unsigned int *)dst = color;
}

int				close_window(int keycode, t_env *env)
{
	if (keycode == 65307)
	{
		mlx_destroy_window(env->mlx, env->win);
		exit (1);
	}
	return (keycode);
}

int		key_press(int keycode, t_env *env)
{
	if (keycode == 65361)
		env->left = 1;
	if (keycode == 65363)
		env->right = 1;
	if (keycode == 119)
		env->up = 1;
	if (keycode == 97)
		env->strafe_left = 1;
	if (keycode == 100)
		env->strafe_right = 1;
	if (keycode == 115)
		env->down = 1;
	return (0);
}

int		key_release(int keycode, t_env *env)
{
	if (keycode == 65307)
	{
		mlx_destroy_window(env->mlx, env->win);
		exit (1);
	}
	if (keycode == 65361)
		env->left = 0;
	if (keycode == 65363)
		env->right = 0;
	if (keycode == 119)
		env->up = 0;
	if (keycode == 97)
		env->strafe_left = 0;
	if (keycode == 100)
		env->strafe_right = 0;
	if (keycode == 115)
		env->down = 0;
	return (0);
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

void            draw_image(t_data *data, unsigned int **tab)
{
    int x;
    int y;

    y = 0;
    while (y < 600)
    {
        x = 0;
        while (x < 800)
        {
            my_mlx_pixel_put(data, x, y, tab[y][x]);
            x++;
        }
        y++;
    }
}

int		render_next_frame(t_env *env)
{
	reset_sheet(env);
	ray_casting(env);
	draw_image(&env->img, env->rndr->sheet);
	mlx_put_image_to_window(env->mlx, env->win, env->img.img, -1, 0);
	return (-1);
}