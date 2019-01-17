##
## Makefile for Makefile in /home/roye_v/delivery/dante
## 
## Made by Vincent Roye
## Login   <roye_v@epitech.net>
## 
## Started on  Wed Apr 12 12:27:00 2017 Vincent Roye
## Last update Sun May 14 22:17:21 2017 Vincent Roye
##

SRC	=	src/main.c		\
		src/search.c		\
		src/next_cell.c		\
		src/check_error.c	\
		src/display.c		\
		src/linked_list.c	\
		src/astar.c

CFLAGS	=	-Iinclude/ -Wall -Wextra -W -g

CC	=	gcc

NAME	=	solver

OBJ	=	$(SRC:.c=.o)

all:	$(NAME)

$(NAME): $(OBJ)
	 $(CC) -o $(NAME) $(OBJ)


clean:
	@$(RM) $(OBJ)

fclean: clean
	@$(RM) $(NAME) $(OBJ)

re:     fclean all
