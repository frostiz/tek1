##
## Makefile for Makefile in /home/roye_v/delivery/my_lib
## 
## Made by Vincent Roye
## Login   <roye_v@epitech.net>
## 
## Started on  Sat Feb 11 17:40:25 2017 Vincent Roye
## Last update Sat May 27 03:21:00 2017 Vincent Roye
##

CC	=	gcc

RM	=	rm -f

SRC	=	src/my_putchar.c	\
		src/my_getnbr.c		\
		src/my_put_nbr.c	\
		src/my_int_swap.c	\
		src/my_realloc.c	\
		src/my_memset.c		\
		src/my_revstr.c		\
		src/my_strcpy.c		\
		src/my_strcat.c		\
		src/my_strcmp.c		\
		src/my_strncmp.c	\
		src/my_putstr.c		\
		src/my_printf.c		\
		src/my_strdup.c		\
		src/my_put_binary.c	\
		src/my_put_octal.c	\
		src/my_put_unsigned.c	\
		src/my_strlen.c		\
		src/my_str_to_wordtab.c	\

OBJECTS	=	$(SRC:.c=.o)

CFLAGS	=	-Wall -Wextra -Iinclude

AR	=	ar rc

NAME	=	libmy.a

all:	$(NAME)

$(NAME): $(OBJECTS)
	 @$(AR) $(NAME) $(OBJECTS)

clean:
	@$(RM) $(OBJECTS)

fclean:	clean
	@$(RM) $(NAME)

re: fclean all
