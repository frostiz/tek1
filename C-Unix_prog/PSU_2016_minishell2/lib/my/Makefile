##
## Makefile for libmy in /home/thibaut/Repository/PSU_2016_minishell2/lib/my
## 
## Made by Thibaut Trouvé
## Login   <thibaut.trouve@epitech.eu>
## 
## Started on  Mon Apr  3 21:19:57 2017 Thibaut Trouvé
## Last update Fri Apr  7 17:12:45 2017 Thibaut Trouvé
##

SRC	=	src/my_strlen.c		\
		src/my_tablen.c		\
		src/my_strdup.c		\
		src/my_strcpy.c		\
		src/my_strcat.c		\
		src/my_strcmp.c		\
		src/my_strncmp.c	\
		src/my_getnbr.c		\
		src/print_tab.c		\
		src/my_putstr.c		\
		src/free_tab.c		\
		src/my_copy_tab.c	\
		src/my_realloc.c	\
		src/is_alphanum.c	\
		src/my_str_to_wordtab.c

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

HEADER	=	my.h

ROOT	=	/home/thibaut/Repository/PSU_2016_minishell2

CFLAGS	=	-W	-Wall	-Wextra	-Iinclude/

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)
	cp ./include/my.h $(ROOT)/include/
	cp $(NAME) $(ROOT)/lib/
clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	clean all
