/*
** aff_minimap.c for aff_minimap.c in /home/frostiz/wolf3d/bonus/src
** 
** Made by thibaut trouve
** Login   <frostiz@epitech.net>
** 
** Started on  Thu Jan 12 18:10:27 2017 thibaut trouve
** Last update Fri Jan 13 15:58:39 2017 thibaut trouve
*/

#include "my.h"

void	draw_square(int x, int y, t_window *win, float pas)
{
  int   i;
  int   j;

  i = 0;
  j = 0;
  while (j < pas)
    {
      while (i < pas)
	{
	  my_put_pixel(win->buffer, x*pas + i, y*pas + j, win->color);
	  i++;
	}
      i = 0;
      j++;
    }
}

void	aff_compass(t_map *data, t_window *win)
{
  sfVector2i from;
  sfVector2f tmp;
  sfVector2i to;

  win->color = sfRed;
  draw_square((int)data->pos.x, (int)data->pos.y, win, data->pas);
  from.x = data->pas * (int)data->pos.x + data->pas / 2;
  from.y = data->pas * (int)data->pos.y + data->pas / 2;
  tmp.x = from.x + 30*cos(data->direction*(M_PI/180));
  tmp.y = from.y + 30*sin(data->direction*(M_PI/180));
  to.x = (int)tmp.x;
  to.y = (int)tmp.y;
  my_draw_line(win->buffer, from, to, sfBlack);
}

void	aff_minimap(t_map *data, t_window *win)
{
  int   i;
  int   j;

  j = 0;
  i = 0;
  while (i < data->mapsize.y)
    {
      while (j < data->mapsize.x)
	{
	  if (data->map[i][j] == 1)
	    {
	      win->color = sfBlue;
	      draw_square(j, i, win, data->pas);
	    }
	  else
	    {
	      win->color = sfWhite;
	      draw_square(j, i, win, data->pas);
	    }
	  j++;
	}
      j = 0;
      i++;
    }
  aff_compass(data, win);
}
