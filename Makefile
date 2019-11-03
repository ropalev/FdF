NAME = fdf
CC = gcc

SRC = coord.c draw_line.c figure_rotation.c figure_zoom.c main.c map.c parser.c utils.c

OBJ = coord.o draw_line.o figure_rotation.o figure_zoom.o main.o map.o parser.o utils.o

LIB_FLAG = -Llibft/ -lft
MINILIBX_FLAG = -Lminilibx_macos/ -lmlx -framework OpenGL -framework AppKit
CFLAGS = -Wall -Werror -Wextra

all: $(NAME)

%.o : %.c fdf.h
	$(CC) -c $(CFLAGS) $< -o $@ 

$(NAME): $(OBJ)
	make -C libft
	$(CC) -o $(NAME) $(CFLAGS) $(LIB_FLAG) $(OBJ) $(MINILIBX_FLAG)

clean:
	rm -f $(OBJ)
	make -C libft clean

fclean: clean
	rm -f $(NAME)
	make -C libft fclean

re: fclean $(NAME)
