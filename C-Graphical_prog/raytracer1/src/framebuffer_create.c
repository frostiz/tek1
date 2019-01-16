/*
** framebuffer_create.c for framebuffer_create.c in /home/frostiz/bswireframe
** 
** Made by thibaut trouve
** Login   <frostiz@epitech.net>
** 
** Started on  Wed Nov 16 14:23:45 2016 thibaut trouve
** Last update Sun Mar 19 19:02:24 2017 
*/

#include "my.h"

t_my_framebuffer*	my_framebuffer_create(int width, int height)
{
  sfUint8		*pixels;
  t_my_framebuffer	*buffer;
  int			i;

  buffer = malloc(sizeof(t_my_framebuffer));
  if (buffer == NULL)
    return (NULL);
  buffer->pixels = malloc(sizeof(*pixels) * width * height * 4);
  if (buffer->pixels == NULL)
    return (NULL);
  buffer->height = height;
  buffer->width = width;
  i = 0;
  while (i < width * height * 4)
    {
      buffer->pixels[i]= 0;
      i++;
    }
  return (buffer);
}
