NAME		=	libft.a

SRCS		=	ft_atoi.c ft_bzero.c ft_isalnum.c ft_toupper.c ft_isascii.c \
				ft_isdigit.c ft_isprint.c ft_memccpy.c ft_itoa.c ft_memcmp.c \
				ft_memcpy.c ft_memmove.c ft_memset.c ft_isalpha.c ft_putendl_fd.c \
				ft_putnbr_fd.c ft_putstr_fd.c ft_skip_space.c ft_split.c \
				ft_strchr.c ft_strdup.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c \
				ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strndup.c ft_strnstr.c \
				ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c \
				ft_calloc.c ft_memchr.c ft_putchar_fd.c \
				is_in_str.c ft_skip_digit.c is_charset_str.c \
				ft_skip_alpha.c destroy.c ft_tabdel.c ft_tablen.c is_charset.c \
				ft_putstr.c ft_putchar.c ft_strdel.c ft_strcmp.c

INCLUDES	=	./

OBJS		=	${SRCS:.c=.o}

GCC			=	gcc
RM			=	rm -f

AR			=	ar rc

CFLAGS		=	-Wall -Wextra -Werror -I${INCLUDES}

%.o: %.c
				${GCC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
				${AR} ${NAME} ${OBJS}
				ranlib ${NAME}

all:		${NAME}

clean:
				${RM} ${OBJS}

fclean:		clean
			   	${RM} ${NAME}

re:
	$(MAKE) fclean
	$(MAKE) all

.PHONY:		all clean fclean re