/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcarasso <tcarasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/05 17:32:07 by tcarasso          #+#    #+#             */
/*   Updated: 2020/07/01 17:28:37 by tcarasso         ###   ########.fr       */
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
