/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhenry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 12:20:35 by mhenry            #+#    #+#             */
/*   Updated: 2019/11/14 14:33:35 by mhenry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stddef.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>

# define BUFFER_SIZE 1

void    ft_putchar(char c);
void    ft_putstr(char *str);
int     is_charset(char c, char *str);
int     ft_tablen(char **tab);
void    ft_tabdel(char **tab);
void    destroy(void **ptr);
int     ft_skip_alpha(char *str);
int     ft_skip_digit(char *str);
void	ft_strdel(char *s);
int		get_next_line(int fd, char **line);
size_t	ft_strlen(const char *str);
int		where_in_str(char *str, char c);
//char	*ft_strdup(const char *str);
char	*ft_substr(char const *s, unsigned int start, size_t len);
//int		strjoin(char **s1, char s2[BUFFER_SIZE + 1]);
size_t	savehandler(char **s1, char **s2);
void	ft_strdel(char *s);
int     get_next_line(int fd, char **line);
int     is_in_str(char *str, char c);
int     is_charset_str(char *s1, char *s2);
void	*ft_memset(void *b, int c, size_t len);
void	ft_bzero(void *s, size_t n);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memccpy(void *dst, const void *src, int c, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t len);
size_t	ft_strlen(const char *s);
int		ft_isaplha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
int		ft_toupper(int c);
int		ft_tolower(int c);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int a);
int 	ft_strcmp(const char *s1, const char *s2);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcat(char *dst, const char *src, size_t dstdize);
char	*ft_strnstr(const char *str, const char *tofind, size_t len);
char	*ft_strndup(char const *s1, size_t n);
int		ft_skip_space(char const *s);
//void	ft_putchar(char c, int fd);
char	**ft_split(char const *s, char c);
void	*ft_calloc(size_t count, size_t size);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
char	*ft_strdup(const char *s1);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_atoi(const char *str);
int		ft_isalpha(int c);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_itoa(int n);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);

#endif
