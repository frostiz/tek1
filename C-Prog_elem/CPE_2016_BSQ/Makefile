##
## Makefile for Makefile in /home/frostiz/PSU_2016_my_ls
## 
## Made by thibaut trouve
## Login   <frostiz@epitech.net>
## 
## Started on  Mon Nov 28 13:13:34 2016 thibaut trouve
## Last update Sun Dec 18 17:03:29 2016 thibaut trouve
##

NAME	=	bsq

SRC	=	src/core.c		\
		src/my_strdup.c		\
		src/basic_functions.c	\
		src/aff.c		\
		src/special_case.c	\
		src/check.c		\
		src/stockage.c

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-W -Wall -Wextra -Iinclude/


all:	$(NAME)

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all
