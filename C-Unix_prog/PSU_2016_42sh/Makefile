##
## Makefile for 42sh in /home/dubret_v/delivery/semestre2/Unix/PSU_2016_42sh
## 
## Made by dubret_v
## Login   <victor.dubret@epitech.eu>
## 
## Started on  Sat May 13 15:41:59 2017 dubret_v
## Last update Mon May 22 15:37:11 2017 Vincent Roye
##

CC	=	gcc

RM	=	rm -f

SRC	=	src/main.c			\
		src/graph/check_cmd_cond.c	\
		src/graph/check_invalid_cmd.c	\
		src/graph/count_redir.c		\
		src/graph/create_graph.c	\
		src/graph/error_checking.c	\
		src/graph/graph.c		\
		src/graph/parentheses.c		\
		src/graph/show_graph.c		\
		src/graph/modify_for_redirect.c	\
		src/graph/find_parentheses.c	\
		src/builtin/exec_builtins.c	\
		src/builtin/my_cd_back.c	\
		src/builtin/my_cd.c		\
		src/builtin/my_which.c		\
		src/builtin/my_where.c		\
		src/builtin/my_cd_home.c	\
		src/builtin/my_echo.c		\
		src/builtin/my_env.c		\
		src/builtin/my_envdup.c		\
		src/builtin/my_exit.c		\
		src/builtin/my_setenv.c		\
		src/builtin/my_unsetenv.c	\
		src/builtin/set_pwd.c		\
		src/builtin/add_var.c		\
		src/builtin/new_str.c		\
		src/builtin/repeat.c		\
		src/builtin/if.c		\
		src/builtin/backtick.c		\
		src/builtin/epur_back.c		\
		src/exec/binary.c		\
		src/exec/cat_path.c		\
		src/exec/cat_values.c		\
		src/exec/exec.c			\
		src/exec/fd_reset.c		\
		src/exec/globbing.c		\
		src/exec/glob_check.c		\
		src/exec/glob_util.c		\
		src/exec/left.c			\
		src/exec/my_close.c		\
		src/exec/pipe.c			\
		src/exec/right.c		\
		src/exec/set_value.c		\
		src/exec/signal.c		\
		src/exec/split_command.c	\
		src/exec/wait_all.c		\
		src/util/which_access.c		\
		src/util/where_access.c		\
		src/util/prompt.c		\
		src/util/compare_builtin.c	\
		src/util/all_free.c		\
		src/util/quotes.c		\
		src/util/get_next_line.c	\
		src/util/my_epur_str.c		\
		src/util/my_is_alphanum.c	\
		src/util/array_len.c		\
		src/util/my_perror.c		\
		src/util/my_putstr.c		\
		src/util/my_show_wordtab.c	\
		src/util/my_split.c		\
		src/util/my_str.c		\
		src/util/my_strcat.c		\
		src/util/swap.c			\
		src/util/in_env.c		\
		src/util/is_char.c		\
		src/util/get_env_of.c		\
		src/util/tablen.c		\
		src/util/is_int.c		\
		src/read/add_char.c		\
		src/read/history.c		\
		src/read/sequence.c		\
		src/read/line_editing.c		\
		src/read/modify_input.c		\
		src/read/arrow_keys.c		\
		src/read/keys_up.c		\
		src/read/keys_down.c		\
		src/read/mode.c			\
		src/read/init_term.c		\
		src/read/ctrl_d.c		\
		src/read/control_keys.c		\
		src/read/autocomplete.c		\
		src/read/get_word.c		\
		src/read/get_file.c		\
		src/read/get_filepath.c		\

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-W -Wall -Wextra -Iinclude

NAME	=	42sh

all:		$(NAME)

$(NAME):	$(OBJ)
		@$(CC) -o $(NAME) $(OBJ) -lncurses

clean:
		@$(RM) $(OBJ)

fclean:		clean
		@$(RM) $(NAME)

re:		fclean all

.PHONY:		all clean fclean re
