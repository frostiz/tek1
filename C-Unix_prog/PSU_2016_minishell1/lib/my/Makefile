##
## Makefile for Makefile in /home/frostiz/bootstrap_printf
## 
## Made by thibaut trouve
## Login   <frostiz@epitech.net>
## 
## Started on  Wed Nov  9 11:02:40 2016 thibaut trouve
## Last update Sun Jan 22 19:20:39 2017 thibaut trouve
##

CC	=	gcc

LIB	=	ar rc

LIB_NAME=	libmy.a

SRC	=	basic_functions.c		\
		my_printf.c			\
		convert_base.c			\
		print_spaces_and_value.c	\
		print_spaces_and_value2.c	\
		print_spaces_and_value3.c	\
		my_revstr.c

OBJ	=	$(SRC:.c=.o)

all:		$(LIB_NAME)

$(LIB_NAME):	$(OBJ)
		$(LIB) $(LIB_NAME) $(OBJ)

clean:
		rm -f $(OBJ)

fclean: 	clean
		rm -f $(LIB_NAME)

re:		fclean all
