##
## Makefile for Makefile in /home/roye_v/delivery/CPE_2016/CPE_2016_Lemin
## 
## Made by Vincent Roye
## Login   <roye_v@epitech.net>
## 
## Started on  Thu Apr 13 19:59:38 2017 Vincent Roye
## Last update Sun Apr 30 21:41:38 2017 Thibaut Trouvé
##

SRC	=	src/main.c			\
		src/get_next_line.c		\
		src/print_tab.c			\
		src/copy_file.c			\
		src/tunnel.c			\
		src/my_str_to_wordtab.c		\
		src/my_tunnel_to_wordtab.c	\
		src/get_idx_tunnel.c		\
		src/stock_tunnel.c		\
		src/get_name_coord.c		\
		src/epure_stock.c		\
		src/get_nb_fourmi.c		\
		src/check_errors.c		\
		src/first_check.c		\
		src/delete_emptyline.c		\
		src/room_error.c		\
		src/mapping.c			\
		src/recursive.c			\
		src/display_graph.c		\
		src/display_rooms.c		\
		src/search_path.c		\
		src/init_passed.c		\
		src/parse_nb_ants.c		\
		src/parse_rooms.c		\
		src/parse_tunnels.c		\
		src/go_through_graph.c		\
		src/path_len.c			\
		src/my_tabdup.c			\
		src/init_ever_passed.c		\
		src/prepare_tunnels.c		\
		src/check_duplicate.c		\

CFLAGS	=	-Iinclude/ -Wall -Wextra -W

CC	=	gcc

NAME	=	lem_in

SOURCES_FOLDER  = src/

OBJECTS_FOLDER	= src/

FILE_OK	=	"[\033[32;01m OK \033[00m]"

OK	=	"[\033[0;32;40m DONE \033[0m]"

OBJECTS	=	$(SRC:.c=.o)

LIBS	=	-L./include -L./lib/ -lmy

LIBD	=	./lib/

all:	$(NAME)

$(OBJECTS_FOLDER)%.o:
	@$(CC) -c $(subst .o,.c,$(subst $(OBJECTS_FOLDER),$(SOURCES_FOLDER),$(subst __,/,$@))\
) $(CFLAGS) -o $@
	@echo -e $(CC) $(CFLAGS) "\t$(subst .o,.c,$(subst $(OBJECTS_FOLDER),$(SOURCE\
S_FOLDER),$(subst __,/,$@)))"


$(NAME): $(OBJECTS)
	 @$(MAKE) -s -C $(LIBD)
	 @$(CC) -o $(NAME) $(OBJECTS) $(LIBS)
	 @echo -e "Bloc de transmission" $(OK)

clean:
	@$(RM) $(OBJECTS)
	@$(MAKE) clean -s -C $(LIBD)
	@echo -e "Cleaning" $(NAME) $(OK)

fclean: clean
	@$(RM) $(NAME)
	@$(MAKE) fclean -s -C $(LIBD)
	@echo -e "Deleting" $(NAME) $(OK)

re:     fclean all
