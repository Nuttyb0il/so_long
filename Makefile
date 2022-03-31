NAME = so_long
NAME_LIBFT = libft.a
NAME_MLX = libmlx.a

MLX_DIR = minilibx-linux

NORMINETTE_BIN = norminette
NM_BIN = nm

SRCS =  animations/clocks.c \
		animations/init.c \
		animations/player.c \
		animations/register.c \
		animations/render.c \
		animations/stop.c \
		errors/clean_exit.c \
		errors/load_fail.c \
		errors/markdown.c \
		hooks/key_hook.c \
		hooks/loop.c \
		hooks/redcross.c \
		map/collision.c \
		map/is_ber.c \
		map/line_length.c \
		map/load_map.c \
		map/map_closed.c \
		map/valid_charset.c \
		portrait/integrity.c \
		portrait/load_sprite.c \
		portrait/render_map.c \
		portrait/render_sprite.c \
		portrait/table.c \
		utils/adaptive_size.c \
		utils/random.c \
		utils/spawn.c \
		so_long.c \

OBJS := ${SRCS:.c=.o}

CC = clang

RM = rm -f

INCLUDE_DIR = includes

CFLAGS = -Wall -Wextra -Werror -O2

MLX_FLAGS = -lXext -lX11

.c.o:
	${CC} ${CFLAGS} -c -I ${INCLUDE_DIR} $< -o ${<:.c=.o}

all: $(NAME_LIBFT) $(NAME_MLX) $(NAME)

$(NAME): ${OBJS}
	$(CC) $(CFLAGS) $(MLX_FLAGS) -o $(NAME) ${OBJS} $(NAME_LIBFT) $(NAME_MLX)

$(NAME_LIBFT):
	${RM} $(NAME_LIBFT)
	make -C libft/
	cp libft/libft.a $(NAME_LIBFT)

$(NAME_MLX):
	${RM} $(NAME_MLX)
	make -C $(MLX_DIR)/
	cp $(MLX_DIR)/libmlx_Linux.a $(NAME_MLX)

clean:
	make -C libft/ clean
	make -C $(MLX_DIR)/ clean
	${RM} ${OBJS}

fclean: clean
	${RM} $(NAME_LIBFT) $(NAME_MLX) $(NAME)

re: fclean all

norme:
	@${NORMINETTE_BIN} ${SRCS} includes/so_long.h
	make -C libft/ norme

sym:
	${NM_BIN} -n $(OBJS)

.PHONY: all clean fclean re norme sym