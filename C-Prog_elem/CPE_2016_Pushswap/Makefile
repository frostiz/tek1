##
## Makefile for Makefile in /home/frostiz/CPE_2016_Pushswap
## 
## Made by thibaut trouve
## Login   <frostiz@epitech.net>
## 
## Started on  Mon Nov 21 00:30:44 2016 thibaut trouve
## Last update Wed Nov 23 16:37:19 2016 thibaut trouve
##

NAME	=	push_swap

CC	=	gcc

SRC	=	src/pushswap.c		\
		src/basic_functions.c	\
		src/allowed_op.c	\
		src/main.c

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-Iinclude/

all:	$(NAME)

$(NAME):	$(OBJ)
	$(CC) -o $(NAME) $(OBJ)

clean:
	rm -f *.o

fclean :	clean
	rm -f $(NAME)

re:	fclean all
