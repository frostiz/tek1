##
## Makefile for Makefile in /home/frostiz/bootstrap_printf
## 
## Made by thibaut trouve
## Login   <frostiz@epitech.net>
## 
## Started on  Wed Nov  9 11:02:40 2016 thibaut trouve
## Last update Wed Nov 16 16:14:37 2016 thibaut trouve
##

CC	=	gcc

LIB	=	ar rc

LIB_NAME=	libmy.a

SRC	=	src/basic_functions.c			\
		src/my_printf.c			\
		src/convert_base.c			\
		src/print_spaces_and_value.c		\
		src/print_spaces_and_value2.c		\
		src/print_spaces_and_value3.c

OBJ	=	$(SRC:.c=.o)

CFLAGS 	=	-Iinclude/

all:		$(LIB_NAME)

$(LIB_NAME):	$(OBJ)
		$(LIB) $(LIB_NAME) $(OBJ)

clean:
		rm -f $(OBJ)

fclean: 	clean
		rm -f $(LIB_NAME)

re:		fclean all
