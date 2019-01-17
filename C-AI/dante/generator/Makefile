##
## Makefile for Makefile in /home/roye_v/delivery/dante
## 
## Made by Vincent Roye
## Login   <roye_v@epitech.net>
## 
## Started on  Wed Apr 12 12:27:00 2017 Vincent Roye
## Last update Sun May 14 21:02:07 2017 Thibaut Trouvé
##

SRC	=	src/main.c			\
		src/display.c			\
		src/check_neighbour.c		\
		src/check_around.c		\
		src/list.c			\
		src/mainloop.c			\
		src/perfect/perfect_maze.c	\
		src/imperfect/imperfect.c

CFLAGS	=	-Iinclude/ -Wall -Wextra -W -O2

CC	=	gcc

NAME	=	generator

OBJ	=	$(SRC:.c=.o)

all:	$(NAME)

$(NAME): $(OBJ)
	 $(CC) -o $(NAME) $(OBJ)

clean:
	@$(RM) $(OBJ)

fclean: clean
	@$(RM) $(NAME) $(OBJ)

re:     fclean all
