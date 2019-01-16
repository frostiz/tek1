/*
** tekadventure.h for tekadventure in /home/thibaut/Repository/tekadventure
**
** Made by Thibaut Trouvé
** Login   <thibaut.trouve@epitech.eu>
**
** Started on  Thu May  4 17:04:10 2017 Thibaut Trouvé
** Last update Sun May 28 22:10:10 2017 Vincent Roye
*/

#ifndef TEKADVENTURE_H_
# define TEKADVENTURE_H_
# define SCREEN_WIDTH 1920
# define SCREEN_HEIGHT 1080
# define WIDTH 1280
# define HEIGHT 720

# include		<SFML/Graphics/RenderWindow.h>
# include		<SFML/Graphics/Texture.h>
# include		<SFML/Graphics.h>
# include		"main_screen.h"
# include		"character.h"
# include		"dialog.h"

typedef struct          s_diag
{
  int			x_inclin;
  int			y_inclin;
  int			cumul;
  int			dx;
  int			dy;
  int			i;
  int			x;
  int			y;
}                       t_diag;

typedef struct		s_text2
{
  sfFont*		font;
  sfText*		text;
  sfVector2f		text_pos;
}			t_text2;

typedef struct		s_object
{
  int			(*object)[2];
  char			**obj;
  int			nb_passed;
}			t_object;

typedef struct		s_characters
{
  int			(*character)[2];
  char			**charac;
  char			**sentence;
  int			nb_passed;
}			t_characters;

typedef struct		s_map
{
  int			nb_room;
  char			*name_room;
  char			*background;
  int			(*walkzone)[2];
  int			(*doorzone)[2];
  t_object		objects;
  t_characters		characters;
  int			**pers;
  struct s_map		**new_room;
}			t_map;

typedef struct		s_background
{
  sfTexture		*texture;
  sfSprite		*sprite;
}			t_background;

typedef struct		s_inventory
{
  int			is_open;
  int			gold_key;
  int			sword;
  int			piece_ship[6];
  char			*piece[6];
  sfSprite		*sprites[9];
  sfTexture		*textures[9];
  sfSprite		*sprites_character[9];
  sfTexture		*texture_character[9];
  sfSprite		*sprites_character_s[6];
  sfTexture		*texture_character_s[6];
}			t_inventory;

typedef struct		s_creating
{
  char			*str;
  char			*conf_words[6];
  int			i;
}			t_creating;

typedef struct		s_objects
{
  sfTexture		*texture;
  sfSprite		*sprite;
  char			*name;
}			t_objects;

typedef struct		s_char
{
  sfTexture		*texture;
  sfSprite		*sprite;
}			t_char;

typedef struct		s_loop
{
  sfVector2i		from;
  sfVector2f		spawn;
  sfVector2i		to;
  sfVector2f		actual_pos;
  sfEvent		event;
  int			move_click;
  int			door;
  int			new_room;
  int			good_room;
}			t_loop;

typedef struct		s_game
{
  sfRenderWindow*	window;
  sfMusic		*music;
  t_character		*character;
  t_background		*bg;
  t_inventory		inventory;
  char			*background;
  int			same_bg;
  t_objects		**obj;
  t_char		**charac;
  char			**stock_obj;
  int			nb_obj;
  int			nb_char;
  int			end;
  sfVector2i		save;
}			t_game;

sfRenderWindow		*create_window(char *, int, int);
int			check_env(char **);
int			check_valid_coord(int (*)[2], sfVector2f);
int			launch_cinematic();
int			check_object(t_map *, sfVector2i, t_game *);
int			init_zone(t_game *, t_map *, sfVector2f);
int			arr_len(char **);
int			check_str(char *, t_game *);
int			end_game(t_game *, t_map *);
int			check_piece(t_game *);
void			di_fifth_animation(t_game *);
void			final_boss_win(t_game *, t_map *);
void			init_text_boss(t_text2 *);
void			refresh_screen(t_game *, t_map *, t_text2);
void			first_anim(t_game *, t_map *);
void			second_anim(t_game *);
void			third_anim(t_game *);
void			house_parallax(t_game *);
void			move_player(t_game *, t_map *, t_loop *);
int			usual_event(t_game *, t_map *, t_loop *);
void			refresh_game(t_game *, t_map *, t_loop *);
void			final_boss(t_game *, t_map *);
void			free_struct(t_game *);
void			print_character(t_game *);
void			print_object(t_game *);
void			my_puterror(char *);
void			print_text(char *, t_window *, float, float);
void			print_text2(char *, t_window *, float, float);
void			print_left(t_game *, int, sfVector2f);
void			print_right(t_game *, int, sfVector2f);
void			print_up(t_game *, int, sfVector2f);
void			print_down(t_game *, int, sfVector2f);
void			print_everything(t_game *, t_diag, sfVector2i);
void			make_this_parallax(t_game *, t_diag);
void			draw_objects(sfRenderWindow *, t_inventory);
void			display_map(t_game *, sfVector2f);
void			do_sixth_animation(t_game *);
void			di_third_animation(t_game *, t_map *, t_text2);
int			print_first_text(t_game *, sfVector2i *, t_map *);
char			*int_to_string(int);
char			**my_realloc_tab(char **);
t_map			*next_door(t_game *, t_map *, t_loop *);
t_map			*check_move_click(t_game *, t_map *, t_loop *);
sfVector2i		init_vector(int, int);
sfVector2f		int_to_float(sfVector2i);
sfVector2f		get_pos_object(int (*object)[2], int);
sfVector2f		init_float_vector(int, int);
sfVector2i		ord_sup(t_game *, sfVector2i, sfVector2i);
sfVector2i		ord_inf(t_game *, sfVector2i, sfVector2i);
sfVector2i		abs_sup(t_game *, sfVector2i, sfVector2i);
sfVector2i		abs_inf(t_game *, sfVector2i, sfVector2i);
int			is_inf(int, int);
int			is_sup(int, int);
int			actions(sfVector2i *, t_game *);
t_loop			my_event(t_game *, t_loop);
sfVector2i		movement_cannot_change(t_game *game,
					       sfVector2i from,
					       sfVector2i to);
void			display_all(t_game *, sfVector2i *, t_dialog);
int			init_for_text(t_attribute *, t_datatext *,
				      sfVector2i, char *);
sfVector2i		my_put_diag1(t_game *, t_diag,
				     sfVector2i, int (*)[2]);
sfVector2i		my_put_diag2(t_game *, t_diag,
				     sfVector2i, int (*)[2]);
sfVector2i		move_character(t_game *, sfVector2i,
				       sfVector2i, int (*)[2]);
sfRenderWindow		*create_window(char *, int, int);
t_my_framebuffer	*my_framebuffer_create(int, int);
int			draw_inventory(sfRenderWindow *, t_inventory,
				       t_game *, sfVector2f);
int			(*my_realloc_int_arr(int (*)[2]))[2];
int			*realloc_int(int *);
int			next_len(t_map **);
int			is_ever_passed(int, int *);
int			main_loop(t_game *, t_map *);
int			check_door(t_map *, sfVector2i *, int *, t_game *);
int			check_background(t_map *);
int			check_walkzone(t_map *);
int			checking_walkzone(t_map *);
int			check_doorzone(t_map *);
int			checking_doorzone(t_map *);
int			check_character(t_map *);
int			check_objects(t_map *);
t_inventory		init_inventory(int *);
t_map			**realloc_next_tab(t_map **);
t_map			*create_graph(char *);
t_map			*add_background(t_map *, int *, char *);
t_map			*add_walkzone(t_map *, int *, char *);
t_map			*add_characters(t_map *, int *, char *);
t_map			*add_object(t_map *, int *, char *);
t_map			*search_the_room(t_map *, int *, int *, t_map *);
t_map			*add_doorzone(t_map *, int *, char *);
t_map			*create_node(t_map *, int *, char *);
int			*error_checking(t_map *, int *, int *);
t_inventory		init_textures_s(t_inventory, int *);

#endif /* !TEKADVENTURE_H_ */
