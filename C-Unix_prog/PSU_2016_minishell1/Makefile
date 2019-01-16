##
## Makefile for Makefile in /home/frostiz/PSU_2016_my_exec
## 
## Made by thibaut trouve
## Login   <frostiz@epitech.net>
## 
## Started on  Wed Jan  4 11:08:56 2017 thibaut trouve
## Last update Tue Jan 24 15:06:34 2017 thibaut trouve
##

NAME	=	mysh

SRC	=	src/minishell.c		\
		src/get_next_line.c	\
		src/basic_functions.c	\
		src/stock.c		\
		src/my_strncmp.c	\
		src/my_strcmp.c		\
		src/my_strcpy.c		\
		src/my_strcat.c		\
		src/my_strdup.c		\
		src/change_dir.c	\
		src/env.c		\
		src/setenv.c		\
		src/unsetenv.c		\
		src/redirection.c	\
		src/path.c		\
		src/chdir_path.c	\

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-W -Wall -Wextra -Iinclude/ -g

LIB	=	-L./lib/my -lmy

MAKE_LIB=	make -C lib/my/

all:	$(NAME)

$(NAME):	$(OBJ)
	$(MAKE_LIB)
	gcc -o $(NAME) $(OBJ) $(LIB)

clean:
	rm -f $(OBJ)
	make clean -C ./lib/my/

fclean: clean
	rm -f $(NAME)
	make fclean -C ./lib/my/

re: fclean all
