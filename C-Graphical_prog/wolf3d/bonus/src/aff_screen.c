/*
** aff_screen.c for aff_screen.c in /home/frostiz/wolf3d/bonus
** 
** Made by thibaut trouve
** Login   <frostiz@epitech.net>
** 
** Started on  Thu Jan 12 18:13:46 2017 thibaut trouve
** Last update Fri Jan 13 15:58:55 2017 thibaut trouve
*/

#include "my.h"

void	aff_columns(t_cols *cols, t_calc *calc, t_map *data, t_window *win)
{
  cols->from.x = WIDTH/2 - 220 + calc->x;
  cols->to.x = WIDTH/2 - 220 + calc->x;
  calc->cosa = cos((raycast(data->pos, data->direction, data->map,
			    data->mapsize) -
		    raycast(data->pos, calc->fov, data->map, data->mapsize))
		   * (M_PI / 180));
  calc->correction = raycast(data->pos, calc->fov, data->map, data->mapsize)
    * calc->cosa;
  calc->hauteur = 1.0 / calc->correction * (((WIDTH-(WIDTH/2) + 220)/2)
					    /tan(30*(M_PI / 180)));
  cols->from.y = HEIGHT/2 - (calc->hauteur / 2);
  cols->to.y = HEIGHT/2 + (calc->hauteur / 2);
  cols->top.x = cols->to.x;
  cols->bot.x = cols->to.x;
  if (cols->from.y > 0.1)
    my_draw_line(win->buffer, cols->from, cols->top, sfWhite);
  my_draw_line(win->buffer, cols->from, cols->to, sfRed);
  if (cols->from.y > 0.1)
    my_draw_line(win->buffer, cols->bot, cols->to, sfWhite);
  calc->fov += 0.0789473684;
  cols->from.x++;
  cols->to.x++;
  calc->x++;
}

void	aff_screen(t_map *data, t_window *win)
{
  t_cols        cols;
  t_calc        calc;

  calc.x = 0;
  calc.fov = data->direction - 30.0;
  cols.top.y = 0;
  cols.bot.y = HEIGHT;
  while (calc.fov <= data->direction + 30.0)
    aff_columns(&cols, &calc, data, win);
}

void	aff(t_map *data, t_window *win)
{
  reset_buffer(win->buffer);
  aff_screen(data, win);
  aff_minimap(data, win);
  sfTexture_updateFromPixels(win->texture, win->buffer->pixels,
			     WIDTH, HEIGHT, 0, 0);
}
