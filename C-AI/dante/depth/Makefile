##
## Makefile for Makefile in /home/roye_v/delivery/dante
## 
## Made by Vincent Roye
## Login   <roye_v@epitech.net>
## 
## Started on  Wed Apr 12 12:27:00 2017 Vincent Roye
## Last update Sun May 14 19:46:53 2017 Thibaut Trouvé
##

SRC	=	src/main.c		\
		src/depth.c		\
		src/check_errors.c	\
		src/prepare_depth.c	\
		src/display.c		\
		src/check_around.c	\
		src/move.c

CFLAGS	=	-Iinclude/ -Wall -Wextra -W -O2

CC	=	gcc

NAME	=	solver

OBJ	=	$(SRC:.c=.o)

all:	$(NAME)

$(NAME): $(OBJ)
	 $(CC) -o $(NAME) $(OBJ)
	 $(OK)

clean:
	@$(RM) $(OBJ)

fclean: clean
	@$(RM) $(NAME) $(OBJ)

re:     fclean all
