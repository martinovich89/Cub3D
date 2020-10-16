NAME		= libft.a

CHECK		= check/ft_isalnum.c \
			  check/ft_isalpha.c \
			  check/ft_isascii.c \
			  check/ft_isdigit.c \
			  check/ft_isprint.c \
			  check/is_charset.c \
			  check/is_charset_str.c \
			  check/is_in_str.c \

CONVERT		= convert/ft_atoi.c \
			  convert/ft_itoa.c \
			  convert/ft_tolower.c \
			  convert/ft_toupper.c \

DISPLAY		= display/ft_putchar.c \
			  display/ft_putstr.c \
			  display/ft_putchar_fd.c \
			  display/ft_putendl_fd.c \
			  display/ft_putnbr_fd.c \
			  display/ft_putstr_fd.c \

MEMORY		= memory/ft_bzero.c \
			  memory/ft_calloc.c \
			  memory/ft_memccpy.c \
			  memory/ft_memchr.c \
			  memory/ft_memcmp.c \
			  memory/ft_memcpy.c \
			  memory/ft_memmove.c \
			  memory/ft_memset.c \
			  memory/ft_uint_strdel.c \

STRING		= string/ft_skip_alpha.c \
			  string/ft_skip_digit.c \
			  string/ft_skip_space.c \
			  string/ft_strchr.c \
			  string/ft_strcmp.c \
			  string/ft_strdel.c \
			  string/ft_strdup.c \
			  string/ft_strjoin.c \
			  string/ft_strlcat.c \
			  string/ft_strlcpy.c \
			  string/ft_strlen.c \
			  string/ft_strmapi.c \
			  string/ft_strncmp.c \
			  string/ft_strndup.c \
			  string/ft_strnstr.c \
			  string/ft_strrchr.c \
			  string/ft_strtrim.c \
			  string/ft_substr.c \

TAB			= tab/ft_build_uint_tab.c \
			  tab/ft_split.c \
			  tab/ft_tabdel.c \
			  tab/ft_tablen.c \
			  tab/ft_uint_tabdel.c \
			  tab/ft_uint_tablen.c \

SRC_PATH	= ./srcs/
SRC			= $(DISPLAY) $(CHECK) $(CONVERT) $(MEMORY) $(STRING) $(TAB)
SRCS		= $(addprefix $(SRC_PATH), $(SRC))

FLAGS		= -Wall -Wextra -Werror
INC			= -I./includes
HEADERS		= includes/libft.h

OBJS 		= $(SRCS:.c=.o)

CC			= @gcc

RM			= @rm -f

%.o: %.c $(HEADERS)
	$(CC) $(FLAGS) $(INC) -c $< -o $@

all:	$(NAME)

$(NAME):${OBJS}
		@ar rcs ${NAME} ${OBJS}
		@echo "$(NAME) created"
		@ranlib $(NAME)
		@echo "$(NAME) indexed"

clean:
		$(RM) $(OBJS)
		@echo "$(OBJS) deleted"

fclean:	clean
		$(RM) $(NAME)
		@echo "$(NAME) deleted"

re:		fclean all

.PHONY:	fclean clean clean_b re all