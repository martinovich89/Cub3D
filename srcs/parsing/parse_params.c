/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_params.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martin <martin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/17 00:04:39 by martin            #+#    #+#             */
/*   Updated: 2023/09/06 19:42:28 by martin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	norminette_quit(char *line, t_env *env)
{
	ft_strdel(&line);
	ft_error("invalid line in .cub file\n", env);
}

int		cmp_and_parse(t_env *env, char *line)
{
	if (*line)
	{
		if (!ft_strncmp(line, "R ", 2))
			parse_res(env, line);
		else if (!ft_strncmp(line, "NO ", 3))
			parse_tex(env, line, 1);
		else if (!ft_strncmp(line, "EA ", 3))
			parse_tex(env, line, 2);
		else if (!ft_strncmp(line, "WE ", 3))
			parse_tex(env, line, 3);
		else if (!ft_strncmp(line, "SO ", 3))
			parse_tex(env, line, 4);
		else if (!ft_strncmp(line, "S ", 2))
			parse_tex(env, line, 5);
		else if (!ft_strncmp(line, "C ", 2))
			parse_color(env, line, 1);
		else if (!ft_strncmp(line, "F ", 2))
			parse_color(env, line, 2);
		else
			norminette_quit(line, env);
		return (1);
	}
	return (0);
}

int		is_valid_conf(t_env *env)
{
	if (env->conf->res_w == -1 || env->conf->res_h == -1)
		return (0);
	if (!env->conf->path_no || !env->conf->path_ea || !env->conf->path_we ||
		!env->conf->path_so || !env->conf->path_sp)
		return (0);
	if (!env->conf->ceil_is_set || !env->conf->floo_is_set)
		return (0);
	return (1);
}

int		space_at_end_line(char *str)
{
	int i;

	if (!*str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	if (str[i - 1] == ' ')
		return (1);
	return (0);
}

void	parse_params(t_env *env)
{
	char	*line = NULL;
	int		i;
	int		fd;

	fd = open(env->conf->file, O_RDONLY);
	i = 0;
	while (get_next_line(fd, &line) > 0
	&& !(is_charset_str(line, " 1") && is_in_str(line, '1')))
	{
		if (space_at_end_line(line) || (i == 0 && !*line))
		{
			ft_strdel(&line);
			ft_error("invalid space or empty line\n", env);
		}
		if (cmp_and_parse(env, line))
			i++;
		ft_strdel(&line);
	}
	if (line)
		ft_strdel(&line);
	if (i != 8)
		ft_error("invalid parameter lines count\n", env);
	if (!is_valid_conf(env))
		ft_error("one or more parameters are invalid\n", env);
	close(fd);
}