NAME		= parsing

GCC			= clang

CFLAGS		= -Wall -Wextra -Werror

SRCS		= ./srcs/parsing/parse_params.c ./srcs/parsing/parse_map.c \
				./main.c

OBJS		=   $(SRCS:.c=.o)

INCLUDES	= ./includes/

LIBFT_DIR	= ./libs/libft/

MLX_DIR		= ./libs/mlx/

LIBFT		= libft.a

MLX			= compmlx

ALL_INC		= -I$(INCLUDES) -I$(LIBFT_DIR) -I$(MLX_DIR)

ALL_LIB		= -L $(MLX_DIR) -lmlx -lX11 -lXext -lm -L$(LIBFT_DIR) -lft

all: $(NAME)

$(OBJS): %.o : %.c                           #on a rajouté les dépendances au petit bonheur la chance ;)
	$(GCC) $(CFLAGS) -c $< -o $@ $(ALL_INC)

$(NAME): $(LIBFT) $(MLX) $(OBJS)
	$(GCC) $(CFLAGS) $(OBJS) -o $@ $(ALL_INC) $(ALL_LIB)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(MLX) :
	$(MAKE) -C $(MLX_DIR)

clean:
	$(MAKE) clean -C $(LIBFT_DIR)
	$(MAKE) clean -C $(MLX_DIR)
	$(RM) -R $(MLX_DIR)*.o
	$(RM) -R ./srcs/*.o

fclean: clean
	$(MAKE) fclean -C $(LIBFT_DIR)
	$(RM) $(NAME)

re: fclean
	$(MAKE)
