/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcarasso <tcarasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/05 17:31:56 by tcarasso          #+#    #+#             */
/*   Updated: 2020/07/01 17:27:31 by tcarasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_elem	*ft_getcontent(int fd, t_elem **stat)
{
	t_elem	*lst;
	t_elem	*last_elem;

	lst = *stat;
	last_elem = lst;
	while (lst)
	{
		if (lst->fd == fd)
			return (lst);
		last_elem = lst;
		lst = lst->next;
	}
	if (!(lst = malloc(sizeof(*lst))))
		return (NULL);
	lst->fd = fd;
	lst->next = NULL;
	if (!(lst->data = ft_substr("", 0, 0)))
		return (NULL);
	if (!(lst->data = ft_read(lst)))
		return (NULL);
	if (last_elem)
		last_elem->next = lst;
	else
		*stat = lst;
	return (lst);
}

char	*ft_read(t_elem *curr)
{
	char	buf[BUFFER_SIZE + 1];
	char	*tmp;

	while ((curr->ret = read(curr->fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[curr->ret] = '\0';
		tmp = curr->data;
		if (!(curr->data = ft_strjoin(curr->data, buf)))
			return (NULL);
		free(tmp);
		tmp = NULL;
		if (ft_strchr(buf, '\n'))
			break ;
	}
	if (curr->ret < 0)
		return (NULL);
	return (curr->data);
}

int		ft_cpytoline(t_elem *curr, char **line)
{
	char	*tmp;
	size_t	i;
	size_t	j;

	i = 0;
	tmp = curr->data;
	while (curr->data[i] && curr->data[i] != '\n')
		i++;
	if (!(*line = ft_substr(curr->data, 0, (i))))
		return (0);
	j = ft_strlen(curr->data);
	if (!(curr->data = ft_substr(curr->data, i + 1, j - (i + 1))))
		return (0);
	free(tmp);
	tmp = NULL;
	return (1);
}

void	ft_free_elem(t_elem *curr, t_elem **stat)
{
	t_elem	*lst;

	lst = *stat;
	if (curr == *stat)
		*stat = ((*stat)->next) ? ((*stat)->next) : NULL;
	else
		while (lst)
		{
			if (lst->next == curr)
				lst->next = curr->next;
			lst = lst->next;
		}
	free(curr->data);
	curr->data = NULL;
	free(curr);
	curr = NULL;
}

int		get_next_line(int fd, char **line)
{
	static t_elem	*lst;
	t_elem			*curr;

	if (fd < 0 || BUFFER_SIZE <= 0 || !line)
		return (-1);
	if (!(curr = ft_getcontent(fd, &lst)))
		return (-1);
	if (!(ft_strchr(curr->data, '\n')) && curr->ret > 0)
		if (!(curr->data = ft_read(curr)))
		{
			ft_free_elem(curr, &lst);
			return (-1);
		}
	if (!(ft_cpytoline(curr, line)))
	{
		ft_free_elem(curr, &lst);
		return (-1);
	}
	if (curr->ret > 0)
		return (1);
	else
	{
		ft_free_elem(curr, &lst);
		return (0);
	}
}