NAME		=	parsing

LIB			=	-L./libft -lft -I/usr/local/include -L/usr/local/lib -lmlx -L/usr/include -lm -lbsd -lX11 -lXext
INC			=	-I./includes

PARSING		=	parsing/parse_params.c \
				parsing/parse_map.c \

RAY-CASTING =	ray-casting/ray_casting.c \
				ray-casting/rc_utils_1.c \

GNL			=	GNL/get_next_line.c \
				GNL/get_next_line_utils.c \

UTILS		=	utils/clear.c \
				utils/ft_build_uint_tab.c\

ERRORS		=	errors/ft_error.c \

SRC_PATH	=	./srcs/
SRC			=	$(PARSING) \
				$(RAY-CASTING) \
				$(GNL) \
				$(UTILS) \
				$(ERRORS) \
				main.c \

SRCS		=	$(addprefix $(SRC_PATH), $(SRC))

FLAGSD		=	-Wall -Wextra -Werror -fsanitize=address
FLAGS		=	-Wall -Wextra -Werror
OBJS		=	$(SRCS:.c=.o)

CC			=	@gcc

RM			=	@rm -f

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
		$(RM) $(NAME)
		@echo "$(NAME) deleted"

re:		fclean all

.PHONY: all clean fclean re