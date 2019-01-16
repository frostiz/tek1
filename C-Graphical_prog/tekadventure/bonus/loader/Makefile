##
## Makefile for Makefile in /home/roye_v/delivery/raytracer1
## 
## Made by Vincent Roye
## Login   <roye_v@epitech.net>
## 
## Started on  Sat Feb 11 16:22:19 2017 Vincent Roye
## Last update Thu Jun  1 06:38:11 2017 thibaut trouve
##

NAME	=	loader

SRC	=	src/main.c		\
		src/my_put_pixel.c	\
		src/my_draw_line.c	\
		src/load.c		\
		src/my_draw_line2.c	\
		src/my_draw_square.c	\
		src/window.c		\
		src/hex_to_int.c	\
		src/get_tab.c

OBJECTS	=	$(SRC:.c=.o)

CC	=	gcc

CFLAGS	=	-Wall -Wextra -W -Iinclude -g

SOURCES_FOLDER	= src/

OBJECTS_FOLDER 	= src/

SUCCESS =       [ $(C_GOOD)SUCCESS$(C_END) ]

FILE_OK	=	"[\033[32;01m OK \033[00m]"

C_END   =       "\033[00m"

C_GOOD  =       "\033[0;32;40m"

C_OK    =       "\033[1;37;40m"

LIBD	=	lib/my/

MYLIB	=	-L./lib/my -lmy

all: $(NAME)

$(OBJECTS_FOLDER)%.o:
	@$(CC) -c $(subst .o,.c,$(subst $(OBJECTS_FOLDER),$(SOURCES_FOLDER),$(subst __,/,$@))) -I$(INCLUDEFOLDERS) $(CFLAGS) -o $@
	@echo -e $(FILE_OK) "$(subst .o,.c,$(subst $(OBJECTS_FOLDER),$(SOURCES_FOLDER),$(subst __,/,$@)))"


$(NAME): $(OBJECTS)
	@$(MAKE) -C $(LIBD)
	@gcc -o $(NAME) $(OBJECTS) $(MYLIB) -lm -lc_graph_prog_full
	@echo -e "Compiling" $(NAME) $(SUCCESS)

clean:
	@rm -f $(OBJECTS)
	@$(MAKE) clean -C $(LIBD)
	@echo -e "Cleaning" $(NAME) $(SUCCESS)

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) fclean -C $(LIBD)

re: fclean all
