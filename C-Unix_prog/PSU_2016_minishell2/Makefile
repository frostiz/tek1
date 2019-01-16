##
## Makefile for Makefile in /home/frostiz/PSU_2016_my_exec
## 
## Made by thibaut trouve
## Login   <frostiz@epitech.net>
## 
## Started on  Wed Jan  4 11:08:56 2017 thibaut trouve
## Last update Wed May  3 06:18:27 2017 Thibaut Trouvé
##

CC	=	gcc

NAME	=	mysh

SRC	=	src/mainloop.c			\
		src/main.c			\
		src/find_path.c			\
		src/exec_simple_command.c	\
		src/exec_complex_command.c	\
		src/interpret_args.c		\
		src/interpret_status.c		\
		src/signal_handler.c		\
		src/get_arg.c			\
		src/is_char.c			\
		src/my_cd_error.c		\
		src/count_separator.c		\
		src/check_builtin.c		\
		src/exec_builtin.c		\
		src/display_env.c		\
		src/my_setenv.c			\
		src/my_setenv_error.c		\
		src/my_unsetenv.c		\
		src/my_cd.c			\
		src/my_exit.c			\
		src/error_without_coredump.c	\
		src/error_with_coredump.c	\
		src/check_redirect_pipe.c	\
		src/exec_all_commands.c		\
		src/get_commands.c		\
		src/interpret_path.c		\
		src/my_wordtab_to_arrtab.c	\
		src/epure_semicolon.c		\
		src/check_cmd_error.c		\
		src/mygnl.c			\
		src/epure_input.c		\
		src/exec_double_left.c		\
		src/open_files_redir.c		\
		src/open_files_redir_failure.c	\
		src/split_cmd.c			\
		src/start_piped.c		\
		src/exec_simple_left.c		\
		src/exec_simple_right.c		\
		src/invert_cmd.c		\
		src/check_cmd_syntax.c		\
		src/check_ambiguous.c		\
		src/interpret_truepath.c	\
		src/epure_space.c		\
		src/full_command_to_wordtab.c	\

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-W -Wall -Wextra -Iinclude/

LIB	=	-L./lib -lmy

LIB_ROOT=	./lib/my

LIB_NAME=	./lib/libmy.a

all:	$(LIB_NAME)	$(NAME)

$(LIB_NAME):
	$(MAKE) --no-print-directory -C $(LIB_ROOT)

$(NAME):	$(OBJ)
	@$(CC) -o $(NAME) $(OBJ) $(LIB)

clean:
	@rm -f $(OBJ)
	@$(MAKE) clean --no-print-directory -s -C $(LIB_ROOT)

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) fclean --no-print-directory -s -C $(LIB_ROOT)

re: fclean all

.PHONY:	all	clean	fclean	re
