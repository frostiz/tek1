##
## Makefile for Makefile in /home/roye_v/delivery/CPE_2016_n4s
## 
## Made by Vincent Roye
## Login   <roye_v@epitech.net>
## 
## Started on  Fri Jun  2 14:27:14 2017 Vincent Roye
## Last update Sun Jun  4 20:36:35 2017 Victor Dubret
##

SRC		=       src/main.c              \
			src/my_strlen.c		\
			src/my_str_to_wordtab.c	\
			src/move.c		\
			src/check.c

CC		=       gcc -o

OBJ		=        $(SRC:.c=.o)

NAME		=       ai

RM		=       rm -rf

CFLAGS		=       -W -Wall -Wextra -Iinclude/ -g

all:            	$(NAME)

$(NAME):		$(OBJ)
			$(CC) $(NAME) $(OBJ)

clean:
			$(RM) $(OBJ)

fclean:			clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:			re clean fclean all
