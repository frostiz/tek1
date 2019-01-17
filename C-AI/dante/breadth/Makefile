##
## Makefile for Makefile in /home/roye_v/delivery/maze_solver
## 
## Made by Vincent Roye
## Login   <roye_v@epitech.net>
## 
## Started on  Thu May 11 19:20:08 2017 Vincent Roye
## Last update Sun May 14 20:04:19 2017 Vincent Roye
##

SRC		=	src/main.c		\
			src/check_error.c	\
			src/east.c		\
			src/north.c		\
			src/south.c		\
			src/west.c		\
			src/linked_list.c	\
			src/get_data.c		\
			src/breadth.c

CC		=	gcc -o

OBJ		=	 $(SRC:.c=.o)

NAME		=	solver

RM		=	rm -rf

CFLAGS		=	-W -Wall -Wextra -Iinclude/ -g

all:		$(NAME)

$(NAME):	$(OBJ)
		$(CC) $(NAME) $(OBJ)

clean:
		$(RM) $(OBJ)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all
