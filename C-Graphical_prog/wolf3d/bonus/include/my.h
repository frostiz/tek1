/*
** my.h for my.h in /home/frostiz/bootstrap_graphical_programming
** 
** Made by thibaut trouve
** Login   <frostiz@epitech.net>
** 
** Started on  Thu Nov 10 14:58:13 2016 thibaut trouve
** Last update Fri Jan 20 13:38:25 2017 thibaut trouve
*/

#ifndef MY_H_
# define MY_H_

# define WIDTH 1080
# define HEIGHT 1080
# define PI 3.14159265

#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Texture.h>
#include <SFML/Window/Window.h>
#include <SFML/Window/Event.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

typedef struct          s_my_framebuffer
{
  sfUint8*              pixels;
  int                   width;
  int                   height;
}                       t_my_framebuffer;

typedef struct          s_my_lines
{
  int			dist_x;
  int			dist_y;
  int			i;
  int			inclin_x;
  int			inclin_y;
  int			stack;
}                       t_lines;

typedef struct          s_my_window
{
  sfRenderWindow	*window;
  sfEvent		event;
  t_my_framebuffer	*buffer;
  sfSprite		*sprite;
  sfTexture		*texture;
  sfColor		color;
}                       t_window;

typedef struct		s_my_maps_info
{
  int		**map;
  sfVector2f	pos;
  sfVector2i	mapsize;
  float		direction;
  float		pas;
}			t_map;

typedef struct		s_my_vector
{
  sfVector2i    from;
  sfVector2i    to;
  sfVector2i    bot;
  sfVector2i    top;
}			t_cols;

typedef struct		s_my_calc
{
  int           x;
  float         hauteur;
  float         correction;
  float         cosa;
  float		fov;
}			t_calc;

typedef struct		s_my_count
{
  int	buf;
  int	col;
  int	row;
}			t_count;

float			raycast(sfVector2f, float, int **, sfVector2i);
t_my_framebuffer*       my_framebuffer_create(int, int);
void			my_put_pixel(t_my_framebuffer *, int, int, sfColor);
sfRenderWindow*		create_window(char *, int, int);
void			my_draw_line(t_my_framebuffer *,
				     sfVector2i, sfVector2i, sfColor);
void			my_draw_line_modified(t_my_framebuffer *,
				     sfVector2i, sfVector2i, sfColor);
void			my_putline(sfVector2i, sfVector2i,
				   t_my_framebuffer *, sfColor);
sfVector2f		move_forward(sfVector2f, float, float);
int			**stock_file(char **);
void			reset_buffer(t_my_framebuffer *);
void			aff_minimap(t_map *, t_window *);
void			move_ahead(t_map *, t_window *);
void			move_left_right(t_map *, t_window *, int);
void			move_back(t_map *, t_window *);
void			reset_buffer(t_my_framebuffer*);
int			make_window(t_window *, t_map *, char **);
void			init_struct(t_count *, int *, char **);
int			get_mapsize(char **, int *);
void			aff(t_map *, t_window *);
void			destroy_wall(t_map *, t_window *);
int			check_error(t_map, char **);
int			check_env(char **);
int			my_strcmp(char *, char *);
int			get_x_y(char *, int *);
#endif
