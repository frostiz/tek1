##
## Makefile for Matchstick in /home/thibaut/Repository/CPE_2016_matchstick
## 
## Made by 
## Login   <thibaut.trouve@epitech.eu>
## 
## Started on  Mon Feb 13 09:08:14 2017 
## Last update Sun Mar 19 19:42:17 2017 
##

CC	=	gcc

NAME	=	raytracer1

SRC	=	src/newmain.c		\
		src/my_put_pixel.c	\
		src/framebuffer_create.c\
		src/calc_dir_vector.c	\
		src/sphere.c		\
		src/plane.c		\
		src/cone.c		\
		src/cylinder.c		\
		src/translate.c		\
		src/rotate.c		\
		src/raytrace.c		\
		src/error.c		\
		src/my_strcpy.c		\
		src/my_strlen.c		\
		src/my_putstr_err.c	\
		src/my_strncmp.c


OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-g -lc_graph_prog -lm -W -Wall -Wextra -Iinclude/

all: $(NAME)

$(NAME):	$(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all
