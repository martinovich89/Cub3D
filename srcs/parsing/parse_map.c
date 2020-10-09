#include "cub.h"

void	check_map_line(t_env *env, char *line)
{
	if (!is_charset_str(line, "NEWS 012") || !is_in_str(line, '1'))
		ft_error("invalid map line (map must be last element)", env);
	if (ft_strlen(line) > (size_t)env->conf->map_w)
		env->conf->map_w = ft_strlen(line);
	env->conf->map_h++;
}

void	set_w_h(t_env *env)
{
	int		fd;
	char	*line;

	fd = open(env->conf->file, O_RDONLY);
	while (get_next_line(fd, &line) > 0 && !is_charset_str(line, " 1"))
		free(line);
	if (!is_charset_str(line, " 1") || !is_in_str(line, '1'))
		ft_error("no map or spaces in line", env);
	if (ft_strlen(line) > (size_t)env->conf->map_w)
		env->conf->map_w = ft_strlen(line);
	env->conf->map_h++;
	if (line)
		free(line);
	while (get_next_line(fd, &line) > 0)
	{
		check_map_line(env, line);
		free(line);
	}
	check_map_line(env, line);
	if (line)
		free(line);
	close(fd);
}

char	**ft_build_tab(int xmax, int ymax, t_env *env)
{
	char **tab;
	int i;

	if (!(tab = (char **)malloc(sizeof(*tab) * (ymax + 1))))
		ft_error("ram allocation error", env);
	i = 0;
	while (i < ymax)
	{
		if (!(tab[i] = ft_calloc((xmax + 1), 1)))
			ft_error("ram allocation error", env);
		ft_memset(tab[i], ' ', xmax);
		i++;
	}
	return (tab);
}

void	fill_tab(t_env *env)
{
	char *line;
	int fd;
	int i;

	fd = open(env->conf->file, O_RDONLY);
	i = 0;
	while (get_next_line(fd, &line) > 0)
	{
		if (is_charset_str(line, "NEWS 012"))
		{
			ft_memcpy(env->conf->map[i], line, ft_strlen(line));
			i++;
		}
		free(line);
	}
	strcpy(env->conf->map[i], line);
	env->conf->map[++i] = NULL;
	free(line);
	close(fd);
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

void	parse_map(t_env *env)
{
	set_w_h(env);
	env->conf->map = ft_build_tab(env->conf->map_w, env->conf->map_h, env);
	fill_tab(env);
	if (!is_valid_map(env->conf))
		ft_error("invalid map character", env);
}