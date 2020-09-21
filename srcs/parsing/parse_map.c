// fonction utilitaire pour free une str.
void	free_str(char **str)
{
	if (*str)
	{
		free(*str);
		*str = NULL;
	}
}

// Vérifie si le caractère c fait partie du charset str.
int		is_charset(char c, char *str);
{
	int i;

	i = 0;
	while (str[i])
	{
		if (c == str[i])
			return (1);
		i++;
	}
	return (0);
}

// Vérifie si tous les caracteres de s1 sont compris dans s2. Retourne 1 si oui, 0 sinon.
int		is_charset_str(char *s1, char *s2);
{
	int i;

	i = 0;
	while (s1[i])
	{
		if (!is_charset(s1[i], s2)
			return (0);
		i++;
	}
	return (1);
}

int		set_x_y(size_t *xmax, size_t *ymax, int fd)
{
	char *line;
	char charset[9];

	ft_strcpy(charset, "NEWS 012");
	*xmax = 0;
	*ymax = 0;
	while ((ret = get_next_line(&line, fd)) > 0)
	{
		if (is_charset(line, charset))
		{
			if (*xmax < ft_strlen(line))
				*xmax = ft_strlen(line);
			*ymax++;
		}
		if (*ymax > 0 && !is_charset(line, charset))
			return (1);
		free_str(&line);
	}
	if (*xmax < 3 || *ymax < 3)
		return (1);
	return (0);
}

char	**build_tab(size_t xmax, size_t ymax)
{
	char	**tab;
	int		i;

	tab = NULL;
	if (!(tab = malloc(sizeof(char *) * ymax + 1)))	// malloc tableau de strings
		return (NULL);
	ft_bzero(tab, (ymax + 1) * sizeof(char *)); // remplir tab de '\0';
	i = 0;
	while (i < ymax && tab)
	{
		if (!(tab[i] = ft_calloc((xmax + 1) * sizeof(char)))) // malloc string + remplir '\0'
		{
			free_split(&tab, i);
			return (NULL);
		}
		ft_memset(tab[i], ' ', xmax); // remplir tout sauf 1 avec ' ' , ainsi on a '\0' a la fin
		i++;
	}
	return (tab);
}

void	fill_tab(t_conf *conf, size_t xmax, size_t ymax, int fd)
{
	char *line;
	size_t i;

	// copier les lignes de description de map dans le tableau de str conf->map
	while ((ret = get_next_line(&line, fd) > 0))
	{
		i = 0;
		while (i < xmax && is_charset_str(line, "NEWS 012"))
		{
			strcpy(conf->map[i], line);
			i++;
		}
		free_str(&line);
	}
}

int		check_map(t_conf *conf)
{
	size_t i;
	size_t j;

	i = 0;
	while (conf->map[i])
	{
		j = 0;
		while (conf->map[j])
		{
			// les if qui suivent permet de vérifier que les bords de map sont des 1.
			// 1. verifier qu'il n'y a pas '0', '2', 'N'... sur les bords.
			if ((!i || !j || !conf->map[i + 1] || !conf->map[i][j + 1])
			&& is_charset(conf->map[i][j], "02NEWS"))
				return (1);
			// 2. verifier qu'il n'y a pas '0', '2', 'N'... en dehors de la "cloture" de 1.
			if ((i && j && conf->map[i + 1] && conf->map[i][j + 1])
			&& is_charset(conf->map[i][j], "02NEWS")
			&& (conf->map[i + 1][j] == ' ' || conf->map[i][j + 1] == ' '
			|| conf->map[i - 1][j] == ' ' || conf->map[i][j - 1] == ' '))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int		get_map(t_conf *conf, int fd)
{
	size_t	xmax;
	size_t	ymax;
	int ret;

	set_x_y(&xmax,&ymax, fd);
	conf->map = build_tab(xmax, ymax);
	fill_tab(conf, xmax, ymax, fd);
	if (check_map(conf) != 0)
	{
		free_split(&conf->map, xmax); // a affiner / preciser
		return (1);
	}
	return (0);
}
