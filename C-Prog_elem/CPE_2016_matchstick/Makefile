##
## Makefile for Matchstick in /home/thibaut/Repository/CPE_2016_matchstick
## 
## Made by 
## Login   <thibaut.trouve@epitech.eu>
## 
## Started on  Mon Feb 13 09:08:14 2017 
## Last update Sun Feb 26 14:54:51 2017 
##

CC	=	gcc

NAME	=	matchstick

SRC	=	src/main.c		\
		src/my_getnbr.c		\
		src/get_next_line.c	\
		src/my_put_nbr.c	\
		src/basics.c		\
		src/check_error.c	\
		src/stock_map.c		\
		src/aff_map.c		\
		src/AI.c		\
		src/player.c		\
		src/ia_info.c

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-g -Iinclude/

all: $(NAME)

$(NAME):	$(OBJ)
	$(CC) -g -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all
