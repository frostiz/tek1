##
## Makefile for Makefile in /home/frostiz/PSU_2016_my_sokoban
## 
## Made by thibaut trouve
## Login   <frostiz@epitech.net>
## 
## Started on  Mon Dec 19 11:06:44 2016 thibaut trouve
## Last update Mon Dec 19 15:53:34 2016 thibaut trouve
##


NAME	=	my_sokoban

SRC	=	src/main.c		\
		src/basic_functions.c	\
		src/analyze_map.c	\
		src/aff_map.c		\
		src/check_end.c		\
		src/move.c		\
		src/stock_map.c		\
		src/check_error.c

CFLAGS	=	-W	-Wall	-Iinclude/

OBJ	=	$(SRC:.c=.o)

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ) -lncurses

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
