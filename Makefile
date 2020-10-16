NAME		=	cub3d

LIB			=	-L./libft -lft -I/usr/local/include -L/usr/local/lib -lmlx -L/usr/include -lm -lbsd -lX11 -lXext
INC			=	-I./includes

PARSING		=	parsing/parse_params.c \
				parsing/parse_map.c \
				parsing/parse_color.c \
				parsing/parse_textures.c \
				parsing/parse_res.c \
				parsing/map_checks.c \

RAY-CASTING =	ray-casting/ray_casting.c \
				ray-casting/rc_utils_1.c \
				ray-casting/ray_casting_init.c \
				ray-casting/ray_casting_map_1.c \
				ray-casting/ray_casting_map_2.c \

RENDERING	=	rendering/rndr_calcs_1.c \
				rendering/rndr_calcs_2.c \

GNL			=	GNL/get_next_line.c \
				GNL/get_next_line_utils.c \

UTILS		=	utils/clear.c \

ERRORS		=	errors/ft_error.c \

SRC_PATH	=	./srcs/
SRC			=	$(PARSING) \
				$(RAY-CASTING) \
				$(RENDERING) \
				$(GNL) \
				$(UTILS) \
				$(ERRORS) \
				main.c \

SRCS		=	$(addprefix $(SRC_PATH), $(SRC))

FLAGSD		=	-Wall -Wextra -Werror -fsanitize=address
FLAGS		=	-Wall -Wextra -Werror
OBJS		=	$(SRCS:.c=.o)
HEADERS		= 	includes/cub.h \
				includes/get_next_line.h \
				includes/libft.h \

CC			=	@clang

RM			=	@rm -f

all:	$(NAME)

$(NAME):$(OBJS)
		@make -C libft
		@make -C libs/mlx
		$(CC) $(FLAGSD) $(INC) -o $@ $^ $(LIB)
		@echo "$@ created"

%.o: %.c $(HEADERS)
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