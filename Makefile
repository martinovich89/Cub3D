NAME		= parsing

LIB			= -L./libft -lft -I/usr/local/include -L/usr/local/lib -lmlx -L/usr/include -lm -lbsd -lX11 -lXext
INC			= -I./includes

PARSING		=parsing/parse_params.c \
			 parsing/parse_map.c \

GNL			=GNL/get_next_line.c \
			GNL/get_next_line_utils.c \

UTILS		=utils/clear.c \

ERRORS		=errors/ft_error.c \

SRC_PATH	= ./srcs/
SRC			= $(PARSING) \
			  $(GNL) \
			  $(UTILS) \
			  $(ERRORS) \
			  main.c \

SRCS		= $(addprefix $(SRC_PATH), $(SRC))

FLAGSD		= -Wall -Wextra -Werror -fsanitize=address
FLAGS		= -Wall -Wextra -Werror
OBJS		= $(SRCS:.c=.o)

CC			= @gcc

RM			= @rm -f

all:	$(NAME)

$(NAME):$(OBJS)
		@make -C libft
		@make -C libs/mlx
		$(CC) $(FLAGSD) $(INC) -o $(NAME) $(OBJS) $(LIB)
		@echo "$(NAME) created"

%.o: %.c
	$(CC) $(FLAGS) $(INC) -o $@ -c $<

clean:
		@make $@ -C libft
		@make $@ -C libs/mlx
		$(RM) $(OBJS)
		@echo "$(OBJS) deleted"

fclean: clean
		@make $@ -C libft
		@make $@ -C libs/mlx
		$(RM) $(NAME)
		@echo "$(NAME) deleted"

re:		fclean all

.PHONY: all clean fclean re