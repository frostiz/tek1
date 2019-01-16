##
## Makefile for  in /home/sahel/rendu/PSU/PSU_2016_tetris
## 
## Made by Sahel
## Login   <sahel.lucas-saoudi@epitech.eu@epitech.net>
## 
## Started on  Tue Feb 21 18:29:47 2017 Sahel
## Last update Sun Mar 19 22:02:43 2017 
##

SRC	=	src/main.c			\
		src/help.c			\
		src/parse_.c			\
		src/puterror_.c			\
		src/getenv_.c			\
		src/without_before_.c		\
		src/debug/debug.c		\
		src/tetrimino/tetrimino.c	\
		src/sp_len_.c			\
		src/concat.c			\
		src/get_next_line.c		\
		src/get_next_line2.c		\
		src/move_str.c			\
		src/free_tab.c			\
		src/str_managing.c		\
		src/tetrimino/list.c		\
		src/close_.c			\
		src/square_tab.c

SRCFLAG	=	src/flags/flags_left.c		\
		src/flags/flags_right.c		\
		src/flags/flags_turn.c		\
		src/flags/flags_drop.c		\
		src/flags/flags_pause.c		\
		src/flags/flags_quit.c		\
		src/flags/flags_level.c		\
		src/flags/flags_mapsize.c	\
		src/flags/flags_without.c	\
		src/flags/flags_debug.c		\
		src/tetrimino/debug.c

SRCSTRC	=	src/struct_init/flag.c		\
		src/struct_init/game.c

SRCARG	=	src/argument/check_flags.c	\
		src/argument/need_help.c

SRCGAME	=	src/game/game_loop.c		\
		src/game/my_realloc.c		\
		src/game/sequences.c		\
		src/game/get_sequences.c	\
		src/game/show_game.c		\
		src/game/show_game_stats.c	\
		src/game/show_next_tetrimino.c	\
		src/game/start_game.c		\
		src/game/movement.c		\
		src/game/interpret_exist.c	\
		src/game/colision.c		\
		src/game/score.c

OBJ	=	$(SRC:.c=.o)		\
		$(SRCFLAG:.c=.o)	\
		$(SRCSTRC:.c=.o)	\
		$(SRCARG:.c=.o)		\
		$(SRCGAME:.c=.o)

CFLAGS	=	-Wall -Wextra -Iinclude -g 

NAME	=	tetris

MLIB	=	basic

all:	$(NAME)

$(MLIB):
	make -C lib

$(NAME):	$(MLIB) $(OBJ)
	@gcc -o $(NAME) $(OBJ) -lncurses -Llib -lbasic

clean:
	make clean -C lib
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: 	fclean $(MLIB) all

.PHONY: all clean fclean re
