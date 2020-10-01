/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcarasso <tcarasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 11:53:24 by tcarasso          #+#    #+#             */
/*   Updated: 2020/10/01 16:45:54 by tcarasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	ft_free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void	ft_clear_env(t_cub *env)
{
	if (env->conf->file)
		free(env->conf->file);
	if (env->conf->path_no)
		free(env->conf->path_no);
	if (env->conf->path_ea)
		free(env->conf->path_ea);
	if (env->conf->path_we)
		free(env->conf->path_we);
	if (env->conf->path_so)
		free(env->conf->path_so);
	if (env->conf->path_sp)
		free(env->conf->path_sp);
	if (env->conf->map)
		ft_free_tab(env->conf->map);
	if (env->conf)
		free(env->conf);
	free(env);
}
