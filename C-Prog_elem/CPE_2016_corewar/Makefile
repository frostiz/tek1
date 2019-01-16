##
## Makefile for Makefile in /home/roye_v/delivery/CPE_2016/CPE_2016_corewar
## 
## Made by Vincent Roye
## Login   <roye_v@epitech.net>
## 
## Started on  Tue Mar 28 13:38:52 2017 Vincent Roye
## Last update Sun Apr  2 19:28:37 2017 Thibaut Trouvé
##

CC	=	gcc

RM	=	rm -f

SRC	=	asm/src/main.c			\
		asm/src/list.c			\
		asm/src/print_tab.c		\
		asm/src/link_list.c		\
		asm/src/get_next_line.c		\
		asm/src/my_chain_to_wordtab.c	\
		asm/src/my_label_to_wordtab.c	\
		asm/src/header.c		\
		asm/src/head_name_comment.c	\
		asm/src/asm.c			\
		asm/src/put_error.c		\
		asm/src/copy_and_epure.c	\
		asm/src/syntax_error.c		\
		asm/src/label_copy.c		\
		asm/src/check_comment.c		\
		asm/src/check_name.c		\
		asm/src/multiple_label.c	\
		asm/src/label_checker.c		\
		asm/src/check_file_extension.c	\
		asm/src/check_syntax.c		\
		asm/src/check_instruction.c	\
		asm/src/check_label.c		\
		asm/src/interpret_first_word.c	\
		asm/src/my_str_to_wordtab.c	\
		asm/src/fill_parse_w.c		\
		asm/src/op.c			\
		asm/src/decalage_bit.c		\
		asm/src/check_instruction_arg.c \
		asm/src/interpret_args.c	\
		asm/src/add_parse_w.c		\
		asm/src/error_message.c		\
		asm/src/init_types.c

SRC2	=	VM/src/main.c

OBJ	=	$(SRC:.c=.o)

OBJ2	=	$(SRC2:.c=.o)

SUCCESS	=	[ $(C_GOOD)SUCCESS$(C_END) ]

OK	=	[ $(C_OK)OK$(C_END) ]

NAME	=	asm/asm

NAME2	=	corewar

CFLAGS	=	-Wall -Wextra -Iinclude -g

LIBD	=	my/lib

MYLIB	=	-L./my/lib/ -lmy

SOURCES_FOLDER  = asm/src/

OBJECTS_FOLDER = asm/src/

LIBDONE	=	"[\033[32;40m $(NAME) DONE \033[0m]"
DONE	=	"Compiling $(NAME)\033[0;32;40m\033[0m"
FILE_OK =       "[\033[32;01m OK \033[00m]"
C_END	=	"\033[00m"
C_OK	=	"\033[1;37;40m"
C_GOOD	=	"\033[0;32;40m"
C_ERROR	=	"\033[31m"
C_WARN	=	"\033[33m"

all:		$(NAME) $(NAME2)

#$(OBJECTS_FOLDER)%.o:
#	@$(CC) -c $(subst .o,.c,$(subst $(OBJECTS_FOLDER),$(SOURCES_FOLDER),$(subst __,/,$@))) $(CFLAGS) -o $@
#	@echo -e $(CC) $(CFLAGS) $(FILE_OK) "$(subst .o,.c,$(subst $(OBJECTS_FOLDER),$(SOURCES_FOLDER),$#(subst __,/,$@)))"


$(NAME):	$(OBJ) $(OBJ2)
		@$(MAKE) -C $(LIBD)
		@$(CC) -o $(NAME) $(OBJ) $(MYLIB)
		@$(CC) -o $(NAME2) $(OBJ2) $(MYLIB)
	        @echo -e $(DONE) $(SUCCESS)

clean:
		@$(RM) $(OBJ)
		@$(RM) $(OBJ2)
		@$(MAKE) clean -C $(LIBD)
	        @echo -e "Cleaning" $(NAME) $(OK)
	        @echo -e "Cleaning" $(NAME2) $(OK)

fclean:		clean
		@$(RM) $(NAME)
		@$(RM) $(NAME2)
		@$(MAKE) fclean -C $(LIBD)
	        @echo -e "Deleting" $(NAME) $(OK)
	        @echo -e "Deleting" $(NAME2) $(OK)

re:		fclean all
