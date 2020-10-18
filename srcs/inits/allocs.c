/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/17 00:22:01 by martin            #+#    #+#             */
/*   Updated: 2020/10/17 00:22:02 by martin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	conf_alloc(t_env *env)
{
	if (!(env->conf = malloc(sizeof(t_conf))))
		ft_error("failed to allocate env.conf\n", env);
	ft_memset(env->conf, 0, sizeof(t_conf));
}

void	map_alloc(t_env *env)
{
	if (!(env->map = malloc(sizeof(t_map))))
		ft_error("failed to allocate env->map\n", env);
	ft_memset(env->map, 0, sizeof(t_map));
}

void	rndr_alloc(t_env *env)
{
	if (!(env->rndr = malloc(sizeof(t_rndr))))
		ft_error("failed to allocate env->rndr\n", env);
	ft_memset(env->rndr, 0, sizeof(t_rndr));
}

t_env	*env_alloc(void)
{
	t_env	*ptr;
	int		i;

	if (!(ptr = malloc(sizeof(t_env))))
		return (NULL);
	i = 0;
	while (i < 4)
	{
		ft_memset(&ptr->tex[i], 0, sizeof(t_data));
		i++;
	}
	ft_memset(ptr, 0, sizeof(t_env));
	conf_alloc(ptr);
	map_alloc(ptr);
	rndr_alloc(ptr);
	return (ptr);
}
