/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 23:49:43 by martin            #+#    #+#             */
/*   Updated: 2020/10/16 23:49:44 by martin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	check_map_line(t_env *env, char *line)
{
	if (!is_charset_str(line, "NEWS 012") || !is_in_str(line, '1'))
		ft_error("invalid map line (map must be last element)\n", env);
	if (ft_strlen(line) > (size_t)env->conf->map_w)
		env->conf->map_w = ft_strlen(line);
	env->conf->map_h++;
}

int		is_valid_char(t_conf *conf, size_t i, size_t j)
{
	if (is_charset(conf->map[i][j], "NEWS") &&
							conf->player != 0)
		return (0);
	if (is_charset(conf->map[i][j], "NEWS"))
		conf->player = conf->map[i][j];
	if ((!i || !j || !conf->map[i + 1] || !conf->map[i][j + 1]) &&
							is_charset(conf->map[i][j], "02NEWS"))
		return (0);
	if ((i && j && conf->map[i + 1] && conf->map[i][j + 1]) &&
		is_charset(conf->map[i][j], "02NEWS") &&
		(conf->map[i + 1][j] == ' ' || conf->map[i][j + 1] == ' ' ||
		conf->map[i - 1][j] == ' ' || conf->map[i][j - 1] == ' '))
		return (0);
	return (1);
}

int		is_valid_map(t_conf *conf)
{
	size_t	i;
	size_t	j;

	conf->player = 0;
	i = 0;
	while (conf->map[i])
	{
		j = 0;
		while (conf->map[i][j])
		{
			if (!is_valid_char(conf, i, j))
				return (0);
			j++;
		}
		i++;
	}
	if (conf->player == 0)
		return (0);
	return (1);
}
