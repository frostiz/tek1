##
## Makefile for tekadventure in /home/roye_v/delivery/tekadventure
## 
## Made by Vincent Roye
## Login   <roye_v@epitech.net>
## 
## Started on  Thu May  4 20:53:05 2017 Vincent Roye
## Last update Mon May 29 00:25:40 2017 Vincent Roye
##

NAME	=	tekadventure

SRC	=	src/main.c				\
		src/get_next_line.c			\
		src/parsing/parse.c			\
		src/parsing/add_background.c		\
		src/parsing/add_walkzone.c		\
		src/parsing/add_doorzone.c		\
		src/parsing/add_pers.c			\
		src/parsing/add_object.c		\
		src/parsing/create_node.c		\
		src/parsing/is_ever_passed.c		\
		src/parsing/my_realloc_all.c		\
		src/parsing/search_the_room.c		\
		src/parsing/error_checking.c		\
		src/parsing/checking_conditions.c	\
		src/parsing/check_condition.c		\
		src/cinematic/launch_cinematic.c	\
		src/cinematic/init_background.c		\
		src/cinematic/init_explosion.c		\
		src/cinematic/init_spaceship.c		\
		src/cinematic/first_scene.c		\
		src/cinematic/second_scene.c		\
		src/cinematic/fondu.c			\
		src/my_puterror.c			\
		src/main_screen/init_main_screen.c	\
		src/main_screen/main_screen_loop.c	\
		src/main_screen/parallax.c		\
		src/character/init_character.c		\
		src/character/init_left_sword.c		\
		src/character/init_right_sword.c	\
		src/character/init_right_walk.c		\
		src/character/init_left_walk.c		\
		src/character/init_up_walk.c		\
		src/character/init_down_walk.c		\
		src/character/init_wait_boss.c		\
		src/character/init_walk_boss.c		\
		src/character/init_death_boss.c		\
		src/character/init_attack_boss.c	\
		src/character/print_direction.c		\
		src/character/print_everything.c	\
		src/character/put_diag1.c		\
		src/character/put_diag2.c		\
		src/character/parallax_move.c		\
		src/inventory/inventory.c		\
		src/inventory/init_inventory.c		\
		src/inventory/init_texture_s.c		\
		src/inventory/display_map.c		\
		src/boss_cinematic.c			\
		src/anim_boss_one.c			\
		src/anim_boss_two.c			\
		src/anim_boss_three.c			\
		src/check_and_print.c			\
		src/check_and_refresh.c			\
		src/init_end_game.c			\
		src/happy_end1.c			\
		src/happy_end2.c			\
		src/happy_end3.c			\
		src/end_game.c				\
		src/init_zone.c				\
		src/sad_boss.c				\
		src/happy_boss.c			\
		src/free_struct.c			\
		src/check_object.c			\
		src/check_door.c			\
		src/move_character.c			\
		src/main_loop.c				\
		src/init_vectors.c			\
		src/window.c				\
		src/create_dialog.c			\
		src/my_event.c				\
		src/check_env.c					\
		src/first_animation_ig/print_first_text.c	\
		src/first_animation_ig/what_sup_first_text.c	\
		src/first_animation_ig/incr_sup_print.c		\
		src/first_animation_ig/action_print_text.c	\

OBJECTS		=	$(SRC:.c=.o)

SOURCES_FOLDER	=	src/

OBJECTS_FOLDER	=	src/

CC		=	gcc

CFLAGS		=	-Wall -Wextra -W -Iinclude

LIBD		=	lib/my

MYLIB		=	-L./lib/my -lmy

all: $(NAME) $(EDITOR_NAME)

$(NAME): $(OBJECTS)
	@$(MAKE) -C $(LIBD)
	@gcc -o $(NAME) $(OBJECTS) $(MYLIB) -lm -lc_graph_prog_full

clean:
	@rm -f $(OBJECTS)
	@$(MAKE) clean -s -C $(LIBD)
	@rm -f $(EDITOR_OBJS)

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) fclean -s -C $(LIBD)
	@rm -f $(EDITOR_NAME)

re: fclean all
