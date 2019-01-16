/*
** framebuffer.c for framebuffer.c in /home/roye_v/delivery/CPE_2016/CPE_2016_Lemin/bonus/New_Bonus
** 
** Made by Vincent Roye
** Login   <roye_v@epitech.net>
** 
** Started on  Fri Apr 28 23:17:05 2017 Vincent Roye
** Last update Sun Apr 30 23:15:55 2017 Vincent Roye
*/

#include <stdio.h>
#include <stdlib.h>
#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include "graph.h"
#include "lemin.h"
#include "my.h"

sfRenderWindow		*create_window()
{
  sfVideoMode		mode;
  sfRenderWindow	*window;

  mode.width = SCREEN_WIDTH;
  mode.height = SCREEN_HEIGHT;
  mode.bitsPerPixel = 32;
  window = sfRenderWindow_create(mode, "Lemin",
				 sfResize | sfClose, NULL);
  return (window);
}

t_my_framebuffer*	my_framebuffer_create(int width, int height)
{
  t_my_framebuffer*	buffer;
  sfUint8		*pixels;
  int			i;

  buffer = malloc(sizeof(t_my_framebuffer));
  if (buffer == NULL)
    return ((t_my_framebuffer*)0);
  buffer->height = height;
  buffer->width = width;
  buffer->pixels = malloc(sizeof(*pixels) * 4 * width * height);
  if (buffer->pixels == NULL)
    return ((t_my_framebuffer*)0);
  i = 0;
  while (i < width * height * 4)
    {
      buffer->pixels[i] = 0;
      i = i + 1;
    }
  return (buffer);
}

void	free_framebuffer(t_my_framebuffer *framebuffer)
{
  int	incr;

  incr = 0;
  while (((SCREEN_WIDTH * SCREEN_HEIGHT) * 4) < incr)
    {
      framebuffer->pixels[incr] = 0;
      incr++;
    }
}
