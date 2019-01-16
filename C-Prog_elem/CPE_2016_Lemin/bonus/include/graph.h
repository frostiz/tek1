/*
** graph.h for graph.h in /home/roye_v/delivery/CPE_2016/CPE_2016_Lemin
** 
** Made by Vincent Roye
** Login   <roye_v@epitech.net>
** 
** Started on  Thu Apr 20 20:19:11 2017 Vincent Roye
** Last update Mon May  1 00:16:38 2017 dubret_v
*/

#ifndef GRAPH_H_
# define GRAPH_H_
# define SCREEN_WIDTH 1920
# define SCREEN_HEIGHT 1080
# include "lemin.h"

typedef struct	s_my_framebuffer
{
  sfUint8*	pixels;
  int		width;
  int		height;
}		t_my_framebuffer;

typedef struct		s_tab
{
  int			**base_pos;
  char			**stock;
}			t_tab;

typedef struct		s_graph
{
  int			max;
  int			dont_print;
  sfVector2i		from;
  sfVector2i		to;
  int			k;
  int			base_connect;
  t_tab			tab;
}			t_graph;

typedef struct	s_diag
{
  int		x_inclin;
  int		y_inclin;
  int		cumul;
  int		dx;
  int		dy;
  int		i;
  int		x;
  int		y;
}		t_diag;

void		my_put_pixel(t_my_framebuffer* framebuffer,
			     int x, int y, sfColor color);
void		my_draw_line(t_my_framebuffer* framebuffer, sfVector2i from,
			     sfVector2i to, sfColor color);
void		draw_square(int, int, t_my_framebuffer*, int);
sfRenderWindow*	create_window();
sfVector2i	count_max_size(t_rooms *);
int		get_max_size(t_rooms *);
int		stock_data(t_tab *, t_rooms *, int);
int		count_linked(t_rooms *);
void		print_this(t_graph *, t_my_framebuffer*, t_rooms *);
t_my_framebuffer*	my_framebuffer_create(int width, int height);

#endif /* !GRAPH_H_ */
