NAME		:= fdf
C_FLAGS		:= -Werror -Wall -Wextra
LIBS_FLAGS	:= -lm -lmlx -framework OpenGL -framework AppKit
SRCS		:= fdf.c

.PHONY: all clean fclean re

all: $(NAME)

$(NAME):
	make -C libft
	gcc $(C_FLAGS) $(LIBS_FLAGS) libft/libft.a $(SRCS) -o $(NAME)

clean:
	make clean -C libft

fclean: clean
	rm -f $(NAME)
	make fclean -C libft

re: fclean all