/*
** window.c for window in /home/roye_v/delivery/installer
** 
** Made by root
** Login   <roye_v@epitech.net>
** 
** Started on  Thu Nov 10 09:16:18 2016 root
** Last update Tue Mar 21 11:06:57 2017 Vincent Roye
*/

#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Texture.h>
#include <SFML/Graphics/Sprite.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <math.h>
#include <stdio.h>
#include "tekadventure.h"

sfRenderWindow*		create_window(char* name, int width, int height)
{
  sfRenderWindow*	window;
  sfVideoMode		mode;

  mode.width = width;
  mode.height = height;
  mode.bitsPerPixel = 32;
  window = sfRenderWindow_create(mode, name, sfResize | sfClose, NULL);
  return (window);
}

t_my_framebuffer*	my_framebuffer_create(int width, int height)
{
  t_my_framebuffer*	 buffer;
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
