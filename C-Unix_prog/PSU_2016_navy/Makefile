##
## Makefile for Makefile in /home/thibaut/Repository/PSU_2016_navy
## 
## Made by 
## Login   <thibaut.trouve@epitech.eu>
## 
## Started on  Tue Jan 31 12:21:45 2017 
## Last update Wed Feb 15 17:58:02 2017 
##

CC	=	gcc

NAME	=	navy


SRC	=	src/main.c		\
		src/cpool_function.c	\
		src/my_getnbr.c		\
		src/stock_maps.c	\
		src/strings.c		\
		src/show_map.c		\
		src/player_one.c	\
		src/player_two.c	\
		src/check_map_error.c	\
		src/check_boat_error.c	\
		src/attack.c		\
		src/check_input.c


OBJ	=	$(SRC:.c=.o)

INCLUDE	=	-Iinclude/

LIB	=	-L./lib/ -lgnl

CFLAGS	=	-W -Wall -Wextra -g $(INCLUDE)

all:	$(NAME)

$(NAME):	$(OBJ)
	$(CC) $(CFLAGS) $(SRC) -o $(NAME) $(LIB)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean	all
