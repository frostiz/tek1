/*
** window.c for window.c in /home/frostiz/wolf3d/bonus/src
** 
** Made by thibaut trouve
** Login   <frostiz@epitech.net>
** 
** Started on  Thu Jan 12 18:04:29 2017 thibaut trouve
** Last update Fri Jan 20 13:38:28 2017 thibaut trouve
*/

#include "my.h"

void	init_struct(t_count *count, int *fd, char **argv)
{
  *fd = open(argv[1], O_RDONLY);
  count->buf = 0;
  count->col = 0;
  count->row = 0;
}

int	make_window(t_window *win, t_map *data, char **argv)
{
  win->window = create_window("wolf3d", WIDTH, HEIGHT);
  win->sprite = sfSprite_create();
  win->texture = sfTexture_create(WIDTH, HEIGHT);
  win->buffer = my_framebuffer_create(WIDTH, HEIGHT);
  sfRenderWindow_setVerticalSyncEnabled(win->window, sfTrue);
  sfRenderWindow_setFramerateLimit(win->window, 60);
  data->direction = 90 + 180;
  data->pos.x = 2.5;
  data->pos.y = 2.5;
  data->mapsize.y = 0;
  data->mapsize.x = get_mapsize(argv, &(data->mapsize.y));
  if (data->mapsize.x > data->mapsize.y)
    data->pas = WIDTH/3/data->mapsize.x;
  else
    data->pas = WIDTH/3/data->mapsize.y;
  if (data->mapsize.x == -1)
    return (84);
  return (0);
}

void	reset_buffer(t_my_framebuffer* buffer)
{
  int   i;

  i = 0;
  while (i < WIDTH * HEIGHT * 4)
    {
      buffer->pixels[i] = 0;
      i++;
    }
}

int	get_x_y(char buffmap[], int *max_x)
{
  int   i;
  int   j;
  int	max_y;

  max_y = 0;
  *max_x = 0;
  i = 0;
  j = 0;
  while (buffmap[i] != '\0')
    {
      if (buffmap[i] == '\n')
	{
	  max_y++;
	  if (j > *max_x)
	    *max_x = j;
	  j = 0;
	}
      j++;
      i++;
    }
  return (max_y - 1);
}
