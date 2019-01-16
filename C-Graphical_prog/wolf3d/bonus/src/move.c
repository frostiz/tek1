/*
** move.c for move.c in /home/frostiz/wolf3d/bonus/src
** 
** Made by thibaut trouve
** Login   <frostiz@epitech.net>
** 
** Started on  Thu Jan 12 18:03:16 2017 thibaut trouve
** Last update Fri Jan 13 16:27:30 2017 thibaut trouve
*/

#include "my.h"

void	move_ahead(t_map *data, t_window *win)
{
  if (data->pos.x > 0.0 && data->pos.y > 0.0 &&
      raycast(data->pos, data->direction, data->map, data->mapsize) > 0.4)
    data->pos = move_forward(data->pos, data->direction, 0.20);
  else
    {
      if (raycast(data->pos, data->direction + 45, data->map, data->mapsize) >
	  raycast(data->pos, data->direction - 45, data->map, data->mapsize))
	{
	  if (data->pos.x > 0.0 && data->pos.y > 0.0 &&
	      raycast(data->pos, data->direction + 45, data->map, data->mapsize)
	      > 0.4)
	    data->pos = move_forward(data->pos, data->direction + 45 , 0.30);
	}
      else
	if (data->pos.x > 0.0 && data->pos.y > 0.0 &&
	    raycast(data->pos, data->direction - 45, data->map, data->mapsize)
	    > 0.4)
	  data->pos = move_forward(data->pos, data->direction - 45 , 0.03);
    }
  data->pos = move_forward(data->pos, data->direction, 0);
  aff(data, win);
}

void	move_back(t_map *data, t_window *win)
{
  if (data->pos.x > 0.0 - 0.1 && data->pos.y > 0.0 - 0.1 &&
      raycast(data->pos, data->direction + 180, data->map, data->mapsize)
      > 0.4)

    data->pos = move_forward(data->pos, data->direction - 180, 0.20);
  else
    {
      if (raycast(data->pos, data->direction + 180 + 45, data->map,
		  data->mapsize) > raycast(data->pos, data->direction + 180 - 45
					   , data->map, data->mapsize))
	{
	  if (data->pos.x > 0.0 && data->pos.y > 0.0 &&
	      raycast(data->pos, data->direction + 180 + 45, data->map,
		      data->mapsize) > 0.4)
	    data->pos = move_forward(data->pos, data->direction + 180 + 45,
				     0.30);
	}
      else
	if (data->pos.x > 0.0 && data->pos.y > 0.0 &&
	    raycast(data->pos, data->direction + 180 - 45, data->map,
		    data->mapsize) > 0.4)
	  data->pos = move_forward(data->pos, data->direction + 180 - 45, 0.03);
    }
  data->pos = move_forward(data->pos, data->direction, 0);
  aff(data, win);
}

void	move_left_right(t_map *data, t_window *win, int opt)
{
  if (opt == 1)
    data->direction += 9;
  else
    data->direction -= 9;
  data->pos = move_forward(data->pos, data->direction, 0);
  aff(data, win);
}

void	destroy_wall(t_map *data, t_window *win)
{
  if (raycast(data->pos, data->direction, data->map, data->mapsize) < 0.35)
    {
      reset_buffer(win->buffer);
      if ((int)(data->pos.y + sin(data->direction*(M_PI/180)) > 1 &&
		(int)(data->pos.x + cos(data->direction * (M_PI/180)) > 1) &&
		(int)(data->pos.y + sin(data->direction*(M_PI/180)) <
		                            data->mapsize.y - 1 &&
		      (int)(data->pos.x + cos(data->direction * (M_PI/180)) <
			    data->mapsize.x - 1))))
	data->map[(int)(data->pos.y + sin(data->direction*(M_PI/180)))]
	  [(int)(data->pos.x + cos(data->direction * (M_PI/180)))] = 0;
      aff(data, win);
    }
}
