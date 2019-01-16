/*
** my.h for my.h in /home/frostiz/bootstrap_graphical_programming
** 
** Made by thibaut trouve
** Login   <frostiz@epitech.net>
** 
** Started on  Thu Nov 10 14:58:13 2016 thibaut trouve
** Last update Sun Mar 19 19:43:20 2017 
*/

#ifndef MY_H_
# define MY_H_

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

#include <SFML/Graphics.h>

#define WIDTH 600
#define HEIGHT 400

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

typedef struct		s_my_vector
{
  sfVector2i    from;
  sfVector2i    to;
  sfVector2i    bot;
  sfVector2i    top;
}			t_cols;

typedef struct		s_prod_matrix
{
  int	line;
  int	col;
  int	linecol;
  int	stock_y;
  int	stock_x;
}			t_prod_matrix;

typedef struct		s_scene
{
  sfVector2i		screen_size;
  sfVector2i		screen_pos;
  sfVector3f		eye_pos;
}			t_scene;

int			my_strlen(char *);
char			*my_strcpy(char *, char *);
int			my_strncmp(char *, char *, int);
void			my_putstr_err(char *);
char			*get_var_env_value(char **, char *);
t_my_framebuffer*       my_framebuffer_create(int, int);
void			my_put_pixel(t_my_framebuffer *, int, int, sfColor);
void			my_draw_line(t_my_framebuffer *,
				     sfVector2i, sfVector2i, sfColor);
sfVector3f		calc_dir_vector(float, sfVector2i, sfVector2i);
float			intersect_sphere(sfVector3f, sfVector3f, float);
float			intersect_cylinder(sfVector3f, sfVector3f, float);
float			intersect_cone(sfVector3f, sfVector3f, float);
float			intersect_plane(sfVector3f, sfVector3f);
float			**rotate_matrix_x(sfVector3f);
float			**rotate_matrix_y(sfVector3f);
float			**rotate_matrix_z(sfVector3f);
float			**product_matrix(float **, float **, sfVector3f);
sfVector3f		rotate_xyz(sfVector3f, sfVector3f);
sfVector3f		rotate_zyx(sfVector3f, sfVector3f);
void			raytrace_scene_sphere(t_my_framebuffer *);
void			raytrace_scene_cone(t_my_framebuffer *);
void			raytrace_scene_cylinder(t_my_framebuffer *);

#endif
