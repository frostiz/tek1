##
## Makefile for  in /home/Zarkkos/delivery/CProg_Elem/CPE_2016_Pushswap
##
## Made by Antoine Duez
## Login   <Zarkkos@epitech.net>
##
## Started on  Mon Nov 21 09:32:28 2016 Antoine Duez
## Last update Sun May 28 18:25:54 2017 thibaut trouve
##

SRC		=	my_put_pixel.c	\
			main.c		\
			load.c		\
			

CC		=	gcc -g

CFLAGS		+=	-W -I./include

RM		=	rm -rf

NAME		=	image

OBJS		=	$(SRC:.c=.o)

all		:	$(NAME)

$(NAME)		:	$(OBJS)
			$(CC) -o $(NAME) $(OBJS) -lc_graph_prog -lm

clean		:
			$(RM) $(OBJS)

fclean		:	clean
			$(RM) $(NAME)

re		:	fclean all
