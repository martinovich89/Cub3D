/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 23:34:57 by martin            #+#    #+#             */
/*   Updated: 2020/10/16 23:35:45 by martin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <stdlib.h>
# include <unistd.h>

typedef struct	s_elem
{
	char			*data;
	int				fd;
	int				ret;
	struct s_elem	*next;
}				t_elem;

int				get_next_line(int fd, char **line);
size_t			ft_strlen(const char *s);
char			*ft_strchr(const char *s, int c);
char			*ft_strjoin(const char *s1, const char *s2);
char			*ft_substr(const char *s, unsigned int start, size_t len);
char			*ft_read(t_elem *curr);
t_elem			*ft_getcontent(int fd, t_elem **stat);
int				ft_cpytoline(t_elem *curr, char **line);
void			ft_free_elem(t_elem *curr, t_elem **stat);

#endif
