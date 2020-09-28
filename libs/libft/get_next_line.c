/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhenry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 10:02:59 by mhenry            #+#    #+#             */
/*   Updated: 2020/02/13 09:30:12 by mhenry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*static void	ft_strdel(char *s)
{
	if (s != NULL && *s != NULL)
	{
		free(*s);
		*s = NULL;
	}
}*/

static int	strjoin(char **s1, char s2[BUFFER_SIZE + 1])
{
	char	*tmp;
	size_t	size;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	size = ft_strlen(*s1) + ft_strlen(s2);
	if (!(tmp = malloc(sizeof(char) * (size + 1))))
		return (-1);
	while ((*s1)[i])
	{
		tmp[i] = (*s1)[i];
		i++;
	}
	while (s2[j])
	{
		tmp[i + j] = s2[j];
		j++;
	}
	tmp[i + j] = 0;
	ft_strdel(*s1);
	*s1 = tmp;
	return (1);
}

int			get_next_line(int fd, char **line)
{
	static char	*save = NULL;
	char		buf[BUFFER_SIZE + 1];
	int			ret;

	if (BUFFER_SIZE <= 0 || fd < 0 || !line)
		return (-1);
	if (!save)
		save = ft_strdup("");
	ret = 1;
	while (ret && where_in_str(save, '\n') == -1)
	{
		if ((ret = read(fd, buf, BUFFER_SIZE)) < 0)
		{
			ft_strdel(save);
			return (-1);
		}
		buf[ret] = 0;
		strjoin(&save, buf);
	}
	if (where_in_str(save, '\n') != -1)
		return ((savehandler(&save, line) == 0) ? -1 : 1);
	*line = ft_strdup(save);
	if (ret <= 0)
		ft_strdel(save);
	return (0);
}
