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

void	ft_clear_conf(t_conf *conf)
{
	if (conf)
	{

		if (conf->file)
			free(conf->file);
		if (conf->path_no)
			free(conf->path_no);
		if (conf->path_ea)
			free(conf->path_ea);
		if (conf->path_we)
			free(conf->path_we);
		if (conf->path_so)
			free(conf->path_so);
		if (conf->path_sp)
			free(conf->path_sp);
		if (conf->map)
			ft_free_tab(conf->map);
		free(conf);
	}
}

void	ft_clear_map(t_map *map)
{
	(void)map;
}

void	ft_clear_rndr(t_rndr *rndr)
{
	if (rndr && rndr->sheet)
		ft_uint_tabdel(rndr->sheet);
}

void	ft_clear_env(t_env *env)
{
	ft_clear_conf(env->conf);
	ft_clear_map(env->map);
	ft_clear_rndr(env->rndr);
	if (env)
		free(env);
}