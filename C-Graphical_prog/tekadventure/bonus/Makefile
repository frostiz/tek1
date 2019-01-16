##
## Makefile for Makefile in /home/roye_v/tekadventure/bonus
## 
## Made by Vincent Roye
## Login   <roye_v@epitech.net>
## 
## Started on  Sun May 28 16:01:23 2017 Vincent Roye
## Last update Sun May 28 16:16:19 2017 Vincent Roye
##

EDITOR_NAME	=	map_editor

EDITOR_SRC	=	editor/src/main.c               \
                        editor/src/gnl.c                \
                        editor/src/my_strcmp.c          \
                        editor/src/launch_editor.c      \
                        editor/src/window.c             \
                        editor/src/special_sfml.c       \
                        editor/src/my_put_pixel.c       \
                        editor/src/my_draw_line.c       \
                        editor/src/my_draw_square.c     \
                        editor/src/draw_menu.c          \
                        editor/src/draw_text.c          \
                        editor/src/draw_basic_menu.c    \
                        editor/src/draw_editor.c        \
                        editor/src/button_event.c       \
                        editor/src/special_sfvector.c   \
                        editor/src/int_to_string.c      \
                        editor/src/get_nb.c             \
                        editor/src/lecter.c             \
                        editor/src/print_special.c      \
                        editor/src/initialization.c     \
                        editor/src/mouse.c              \
                        editor/src/main_screen.c        \
                        editor/src/basic_button.c       \
                        editor/src/door_event.c         \
                        editor/src/door_event_next.c    \
                        editor/src/obj_event.c          \
                        editor/src/obj_event_next.c

EDITOR_OBJS	=	$(EDITOR_SRC:.c=.o)

CFLAGS		=	-Wall -Wextra -W -I../include

MYLIB		=	-L../lib/my -lmy

LIBD		=	../lib/my

all:		$(EDITOR_NAME)

$(EDITOR_NAME):	$(EDITOR_OBJS)
	        @$(MAKE) -C $(LIBD)
		gcc -o $(EDITOR_NAME) $(EDITOR_OBJS) $(MYLIB) -lm -lc_graph_prog_full

clean:
	@rm -f $(EDITOR_OBJS)
	@$(MAKE) clean -C $(LIBD)

fclean:	clean
	@rm -f $(EDITOR_NAME)
	@$(MAKE) fclean -C $(LIBD)
	@rm -f $(EDITOR_NAME)

re: fclean all
