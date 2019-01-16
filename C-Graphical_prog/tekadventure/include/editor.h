/*
** editor.h for  in /home/Zarkkos/Delivery/C_Graphical_Prog/tekadventure
**
** Made by Antoine Duez
** Login   <Zarkkos@epitech.net>
**
** Started on  Thu May 18 22:51:38 2017 Antoine Duez
** Last update Sat May 27 17:21:30 2017 Antoine Duez
*/

#include <SFML/Graphics.h>

#ifndef EDITOR_H_
# define EDITOR_H_

# define SCREEN_WIDTH 1280
# define SCREEN_HEIGHT 720

# define NONE 0
# define WALK 1
# define SPAWN 2
# define DOOR 3
# define OBJECT 4

typedef struct		s_my_framebuffer
{
  sfUint8		*pixels;
  int			width;
  int			height;
}			t_my_framebuffer;

typedef struct		s_sprite
{
  sfSprite		*background;
  sfSprite		*walk_zone;
  sfSprite		*spawn;
  sfSprite		*door;
  sfSprite		*object;
}			t_sprite;

typedef struct		s_texture
{
  sfTexture		*background;
  sfTexture		*walk_zone;
  sfTexture		*spawn;
  sfTexture		*door;
  sfTexture		*object;
}			t_texture;

typedef struct		s_walk_zone
{
  sfVector2i		*from;
  sfVector2i		*to;
}			t_walk_zone;

typedef struct		s_door
{
  sfVector2i		*from;
  sfVector2i		*to;
  sfFont		*font;
  sfText		**text;
}			t_door;

typedef struct		s_object
{
  sfVector2i		*from;
  sfVector2i		*to;
  sfFont		*font;
  sfText		**text;
}			t_object;

typedef struct		s_spawn
{
  sfVector2i		from;
  sfVector2i		to;
}			t_spawn;

typedef struct		s_music
{
  sfFont		*font;
  sfText		*text;
  char			*music;
}			t_music;

typedef struct		s_scene
{
  t_my_framebuffer	*drawbuffer;
  t_my_framebuffer	*spawnbuffer;
  t_my_framebuffer	*doorbuffer;
  t_my_framebuffer	*objectbuffer;
  t_walk_zone		w_zone;
  t_door		d_zone;
  t_object		obj;
  t_spawn		spawn;
  t_music		music;
  t_texture		t;
  t_sprite		s;
  char			*name;
}			t_scene;

typedef struct		s_elems
{
  char			**background;
  char			**music;
  char			**object;
  int			*scene;
}			t_elems;

typedef struct		s_editor
{
  t_scene		**scene;
  t_elems		info;
  int			pos;
  int			background_max;
  int			music_max;
  int			obj_max;
}			t_editor;

typedef struct		s_menu_sprite
{
  sfSprite		*next;
  sfSprite		*previous;
  sfSprite		*walk_zone;
  sfSprite		*spawn;
  sfSprite		*door;
  sfSprite		*music;
  sfSprite		*object;
}			t_menu_sprite;

typedef struct		s_menu_texture
{
  sfTexture		*next;
  sfTexture		*previous;
  sfTexture		*walk_zone;
  sfTexture		*spawn;
  sfTexture		*door;
  sfTexture		*music;
  sfTexture		*object;
}			t_menu_texture;

typedef struct		s_menu
{
  t_menu_sprite		s;
  t_menu_texture	t;
  int			draw_right;
  int			display_standard_ui;
}			t_menu;

typedef struct		s_window
{
  t_my_framebuffer	*framebuffer;
  t_menu		menu;
  t_editor		editor;
  sfRenderWindow	*window;
}			t_window;

typedef struct		s_diag
{
  int			x_inclin;
  int			y_inclin;
  int			cumul;
  int			dx;
  int			dy;
  int			i;
  int			x;
  int			y;
}			t_diag;

CSFML_WINDOW_API sfBool	sfMouse_isButtonReleased(sfMouseButton button,
						 t_window *win);
CSFML_WINDOW_API sfBool	sfKeyboard_isKeyReleased(sfKeyCode key,
						 t_window *win);
t_my_framebuffer	*my_framebuffer_create(int width, int height);
sfRenderWindow		*create_window(char *name, int width, int height);
sfVector2i		*add_vector2i_value(sfVector2i *vector,
					    sfVector2i new_value);
sfText			**add_text_value(sfText **text, sfText *new_value);
sfText			*prepare_door_list(sfVector2f list_pos, t_window *win);
sfText			*prepare_obj_list(sfVector2f list_pos, t_window *win);
sfText			*prepare_door_tmp(char *string, sfVector2f text_pos,
					  t_window *win);
sfText			*prepare_obj_tmp(sfVector2f text_pos, t_window *win,
					 sfText *list);
void			my_put_pixel(t_my_framebuffer *framebuffer,
				     int x, int y, sfColor color);
void			my_draw_line(t_my_framebuffer *framebuffer,
				     sfVector2i from, sfVector2i to,
				     sfColor color);
void			draw_ext(t_my_framebuffer *framebuffer,
				 sfVector2i from, sfVector2i to,
				 sfColor color);
void			my_draw_square(t_my_framebuffer *framebuffer,
				       sfVector2i from, sfVector2i to,
				       sfColor color);
void			print_door_zone(sfVector2i *from, sfVector2i *to,
					sfText **text);
void			print_object_zone(sfVector2i *from, sfVector2i *to,
					  sfText **text);
void			draw_square_next_background(t_window *win);
void			draw_square_previous_background(t_window *win);
void			draw_square_walk_button(t_window *win);
void			draw_square_spawn_button(t_window *win);
void			draw_square_door_button(t_window *win);
void			draw_square_music_button(t_window *win);
void			draw_square_object_button(t_window *win);
void			draw_walk_zone(t_window *win);
void			draw_door(t_window *win);
void			draw_spawn(t_window *win);
void			draw_object(t_window *win);
void			background_lecter(t_window *win);
void			music_lecter(t_window *win);
void			object_lecter(t_window *win);
void			print_walk_zone(sfVector2i *from, sfVector2i *to);
void			init_screen(t_window *win);
int			count_text_tab(sfText **text);
int			my_strcmp(char *str, char *cmp);
int			launch_editor(t_window win);
int			button_next_background(t_window *win);
int			button_previous_background(t_window *win);
int			button_walk_zone(t_window *win);
int			button_spawn(t_window *win);
int			button_door(t_window *win);
int			button_music(t_window *win);
int			button_object(t_window *win);
int			count_vector2i_tab(sfVector2i *vector);
int			draw_each_text(t_window *win);
int			get_background_nb();
int			get_music_nb();
int			get_object_nb();
int			mouse(t_window *win);
int			init_main_screen(t_window *win);
int			intlen(int nb);
char			*get_next_line(int fd);
char			*int_to_string(int nb);
sfVector2f  get_text_pos(t_window *win);
int	draw_each_text(t_window *win);
sfVector2f get_text_obj_pos(t_window *win);

#endif /* !EDITOR_H_ */
