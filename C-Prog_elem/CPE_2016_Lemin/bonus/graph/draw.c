/*
** draw.c for draw.c in /home/roye_v/delivery/CPE_2016/CPE_2016_Lemin/bonus
** 
** Made by Vincent Roye
** Login   <roye_v@epitech.net>
** 
** Started on  Sun Apr 30 23:06:29 2017 Vincent Roye
** Last update Sun Apr 30 23:29:31 2017 Vincent Roye
*/

#include <stdio.h>
#include <stdlib.h>
#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include "graph.h"
#include "lemin.h"
#include "my.h"

void		draw_square(int x, int y,
			    t_my_framebuffer* framebuffer, int status)
{
  sfVector2i	from;
  sfVector2i	to;
  int		max_col;

  max_col = y + 5;
  from.x = x - 5;
  from.y = y - 5;
  to.x = x + 5;
  to.y = y - 5;
  while (from.y < max_col)
    {
      if (status == 1)
	my_draw_line(framebuffer, from, to, sfGreen);
      else if (status == 2)
	my_draw_line(framebuffer, from, to, sfRed);
      else
	my_draw_line(framebuffer, from, to, sfWhite);
      from.y++;
      to.y++;
    }
}

sfVector2i	count_max_size(t_rooms *rooms)
{
  t_rooms	*tmp;
  sfVector2i	max_size;

  max_size.x = 0;
  max_size.y = 0;
  tmp = rooms;
  while (tmp != NULL)
    {
      if (tmp->data->x >= max_size.x)
	max_size.x = tmp->data->x;
      if (tmp->data->y >= max_size.y)
	max_size.y = tmp->data->y;
      tmp = tmp->next;
    }
  return (max_size);
}

int		get_max_size(t_rooms *rooms)
{
  sfVector2i	max_size;
  float		max;

  max = 0;
  max_size = count_max_size(rooms);
  if (max_size.x <= 100 && max_size.y <= 100)
    {
      max = 10;
    }
  else if (max_size.x <= 200 && max_size.y <= 200)
    max = 5;
  else if (max_size.x <= 400 && max_size.y <= 400)
    max = 3;
  else
    max = 1;
  return (max);
}

int		stock_data(t_tab *tab, t_rooms *rooms, int max)
{
  t_rooms	*coords;
  int		j;

  j = 0;
  coords = rooms;
  while (coords != NULL)
    {
      tab->stock[j] = malloc(sizeof(char) * 100);
      if (tab->stock[j] == NULL)
	return (1);
      tab->base_pos[j] = malloc(sizeof(int) * 10);
      if (tab->base_pos[j] == NULL)
	return (1);
      tab->stock[j] = coords->data->name;
      tab->base_pos[j][0] = coords->data->x * max;
      tab->base_pos[j][1] = coords->data->y * max;
      j++;
      coords = coords->next;
    }
  tab->stock[j] = NULL;
  return (0);
}

int		count_linked(t_rooms *rooms)
{
  t_rooms	*tmp;
  int		i;

  i = 0;
  tmp = rooms;
  while (tmp != NULL)
    {
      tmp = tmp->next;
      i++;
    }
  return (i + 1);
}
