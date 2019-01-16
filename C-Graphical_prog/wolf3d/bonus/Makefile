##
## Makefile for Makefile in /home/frostiz/repository/bswolf3d
## 
## Made by thibaut trouve
## Login   <frostiz@epitech.net>
## 
## Started on  Tue Dec 20 09:13:02 2016 thibaut trouve
## Last update Fri Jan 13 16:41:06 2017 thibaut trouve
##

NAME	=	wolf3d

SRC	=	src/my_draw_line.c		\
		src/my_put_pixel.c		\
		src/move_forward.c		\
		src/framebuffer_create.c	\
		src/open_window.c		\
		src/raycast.c			\
		src/main.c			\
		src/stock_map.c			\
		src/move.c			\
		src/window.c			\
		src/aff_minimap.c		\
		src/aff_screen.c		\
		src/check_error.c		\
		src/my_strcmp.c

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-W -Wall -Iinclude/

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ) -lm -lc_graph_prog

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
