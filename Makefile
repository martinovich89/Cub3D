NAME		=	cub3D

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
				rendering/rndr_sprite_calcs_1.c \
				rendering/rndr_sprite_calcs_2.c \
				rendering/rndr_sprite_calcs_3.c \
				rendering/gogole.c \

GNL			=	GNL/get_next_line.c \
				GNL/get_next_line_utils.c \

UTILS		=	utils/clear.c \
				utils/save.c \
				utils/screen.c \

ERRORS		=	errors/ft_error.c \

INPUTS		=	inputs/inputs.c \

INITS		=	inits/allocs.c \
				inits/inits.c \

SRC_PATH	=	./srcs/
SRC			=	$(PARSING) \
				$(RAY-CASTING) \
				$(RENDERING) \
				$(GNL) \
				$(UTILS) \
				$(ERRORS) \
				$(INPUTS) \
				$(INITS) \
				main.c \

SRCS		=	$(addprefix $(SRC_PATH), $(SRC))

FLAGSD		=	-Wall -Wextra -Werror -fsanitize=address -g3
FLAGS		=	-Wall -Wextra -Werror
OBJS		=	$(SRCS:.c=.o)

CC			=	@clang

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