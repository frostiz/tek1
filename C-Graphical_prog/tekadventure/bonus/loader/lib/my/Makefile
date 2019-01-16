##
## Makefile for Makefile in /home/roye_v/delivery/my_lib
## 
## Made by Vincent Roye
## Login   <roye_v@epitech.net>
## 
## Started on  Sat Feb 11 17:40:25 2017 Vincent Roye
## Last update Mon Mar 20 20:23:05 2017 Vincent Roye
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
		src/my_putstr.c		\
		src/my_printf.c		\
		src/my_strdup.c		\
		src/my_put_binary.c	\
		src/my_put_octal.c	\
		src/my_put_unsigned.c	\
		src/my_strlen.c

OBJECTS	=	$(SRC:.c=.o)

CFLAGS	=	-Wall -Wextra -Iinclude

AR	=	ar rc

NAME	=	libmy.a

SOURCES_FOLDER	= src/

OBJECTS_FOLDER = src/

SUCCESS	=	[ $(C_GOOD)SUCCESS$(C_END) ]

FILE_OK =       "[\033[32;01m OK \033[00m]"

OK      =       "[\033[0;32;40m DONE \033[0m]"

C_END	=	"\033[00m"

C_GOOD	=	"\033[0;32;40m"

C_OK	=	"\033[1;37;40m"

all:	$(NAME)

$(OBJECTS_FOLDER)%.o:
	@$(CC) -c $(subst .o,.c,$(subst $(OBJECTS_FOLDER),$(SOURCES_FOLDER),$(subst __,/,$@))) -I$(INCLUDEFOLDERS) $(CFLAGS) -o $@
	@echo -e $(FILE_OK) "$(subst .o,.c,$(subst $(OBJECTS_FOLDER),$(SOURCES_FOLDER),$(subst __,/,$@)))"

$(NAME): $(OBJECTS)
	 @$(AR) $(NAME) $(OBJECTS)
	 @echo -e "Compiling $(NAME)" $(OK)

clean:
	@$(RM) $(OBJECTS)
	@echo -e "Cleaning" $(NAME) $(SUCCESS)

fclean:	clean
	@$(RM) $(NAME)

re: fclean all
