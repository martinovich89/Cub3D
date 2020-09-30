/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcarasso <tcarasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 11:53:24 by tcarasso          #+#    #+#             */
/*   Updated: 2020/09/30 18:56:45 by tcarasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	ft_free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i++]);
	}
	free(tab);
}

void	ft_clear_env(t_cub *env)
{
	free(env->conf->file);
	free(env->conf->path_no);
	free(env->conf->path_ea);
	free(env->conf->path_we);
	free(env->conf->path_so);
	free(env->conf->path_sp);
	ft_free_tab(env->conf->map);
	free(env);
}
