ifeq ($(shell uname), Darwin)
	MLX_DIR := minilibx-macos
	OS_SPECIFIC := -framework OpenGL -framework AppKit
else
	MLX_DIR := minilibx-linux
	OS_SPECIFIC := -lXext -lX11
endif

NAME	:= fdf
C_FLAGS	:= -Wall -Wextra -Werror
SRCS	:= fdf.c hooks.c colors.c free.c parse.c draw.c isometric.c utils.c images.c ui.c trgb.c osspecific.c keys.c cabinet.c projections.c key_hooks.c
LIBS	:= -lm libft/libft.a $(MLX_DIR)/libmlx.a $(OS_SPECIFIC)

.PHONY: all clean fclean re

all: $(NAME)

$(NAME):
	@make -C libft
	@echo "Compiling MLX..."
	@make -C $(MLX_DIR)
	@echo "Compiling FdF..."
	@cc $(C_FLAGS) $(addprefix src/, $(SRCS)) $(LIBS) -O3 -o $(NAME)

clean:
	@make clean -C libft
	@make clean -C $(MLX_DIR)

fclean: clean
	@rm -f $(NAME)
	@make fclean -C libft

re: fclean all