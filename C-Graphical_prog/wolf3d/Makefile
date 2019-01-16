##
## Makefile for Makefile in /home/frostiz/repository/bswolf3d
## 
## Made by thibaut trouve
## Login   <frostiz@epitech.net>
## 
## Started on  Tue Dec 20 09:13:02 2016 thibaut trouve
## Last update Thu Jan 12 20:47:17 2017 thibaut trouve
##

NAME	=	wolf3d

SRC	=	src/my_draw_line.c		\
		src/my_put_pixel.c		\
		src/move_forward.c		\
		src/raycast.c			\
		src/main.c			\

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-W -Wall -Iinclude/

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ) -lm -lc_graph_prog
	make -C bonus/

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	make fclean -C bonus/
re: fclean all
	make re -C bonus/
