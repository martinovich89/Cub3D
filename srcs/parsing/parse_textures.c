/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 23:50:30 by martin            #+#    #+#             */
/*   Updated: 2020/10/16 23:50:31 by martin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int		is_valid_path(char *str)
{
	int		fd;
	int		ret;
	char	buffer[1];

	fd = open(str, O_RDONLY);
	if (fd < 0 || (ret = read(fd, buffer, 1)) < 0)
		return (0);
	close(fd);
	return (1);
}

void	set_tex_path(t_env *env, char *path, int nb)
{
	if (nb == 1)
		if (env->conf->path_no || !(env->conf->path_no = ft_strdup(path)))
			ft_error("ram allocation error\n", env);
	if (nb == 2)
		if (env->conf->path_ea || !(env->conf->path_ea = ft_strdup(path)))
			ft_error("ram allocation error\n", env);
	if (nb == 3)
		if (env->conf->path_we || !(env->conf->path_we = ft_strdup(path)))
			ft_error("ram allocation error\n", env);
	if (nb == 4)
		if (env->conf->path_so || !(env->conf->path_so = ft_strdup(path)))
			ft_error("ram allocation error\n", env);
	if (nb == 5)
		if (env->conf->path_sp || !(env->conf->path_sp = ft_strdup(path)))
			ft_error("ram allocation error\n", env);
}

void	parse_tex(t_env *env, char *line, int nb)
{
	char	**tab;

	if (!(tab = ft_split(line, ' ')))
	{
		ft_strdel(line);
		ft_error("ram allocation error\n", env);
	}
	if (ft_tablen(tab) != 2 || !is_valid_path(tab[1]))
	{
		ft_strdel(line);
		ft_tabdel(tab);
		ft_error("invalid texture line\n", env);
	}
	set_tex_path(env, tab[1], nb);
	if (tab)
		ft_tabdel(tab);
}
