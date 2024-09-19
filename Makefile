NAME = fdf
INCLUDES = ./src/
PRINTF = ./libraries/ft_printf/libftprintf.a
LIBFT = ./libraries/Libft/libft.a
MINILIB = ./libraries/minilib/libmlx.a
GNL = libraries/get_next_line/get_next_line.c

CC = gcc
CFLAGS = -Wall -Wextra -Werror -I$(INCLUDES)

SRCS = src/colors.c src/3d.c src/init.c src/map.c src/matrix.c src/drawing.c fdf.c $(GNL)
OBJECTS = $(SRCS:.c=.o)


all: $(NAME)

$(NAME): $(OBJECTS) $(PRINTF) $(LIBFT) $(MINILIB)
	$(CC) $(CFLAGS) $(OBJECTS) $(PRINTF) $(LIBFT) $(MINILIB) -lm -lX11 -lXext -o $(NAME)

$(PRINTF):
	@make -C ./libraries/ft_printf

$(LIBFT):
	@make -C ./libraries/Libft

$(MINILIB):
	@make -C ./libraries/minilib

clean:
	@make clean -C ./libraries/ft_printf
	@make clean -C ./libraries/Libft
	@make clean -C ./libraries/minilib
	rm -f $(OBJECTS)

fclean: clean
	@make fclean -C ./libraries/ft_printf
	@make fclean -C ./libraries/Libft
	@make clean -C ./libraries/minilib
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
