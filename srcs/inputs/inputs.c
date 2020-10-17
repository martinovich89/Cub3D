/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/17 00:16:45 by martin            #+#    #+#             */
/*   Updated: 2020/10/17 00:16:47 by martin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int		close_window(int keycode, t_env *env)
{
	if (keycode == 65307)
		ft_clear_env(env);
	exit(0);
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
		close_window(keycode, env);
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
