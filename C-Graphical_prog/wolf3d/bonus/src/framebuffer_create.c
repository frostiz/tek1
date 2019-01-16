/*
** framebuffer_create.c for framebuffer_create.c in /home/frostiz/bswireframe
** 
** Made by thibaut trouve
** Login   <frostiz@epitech.net>
** 
** Started on  Wed Nov 16 14:23:45 2016 thibaut trouve
** Last update Fri Jan 13 16:19:36 2017 thibaut trouve
*/

#include "my.h"

t_my_framebuffer*	my_framebuffer_create(int width, int height)
{
  sfUint8               *pixels;
  t_my_framebuffer      *buffer;
  int                   i;

  if ((buffer = malloc(sizeof(t_my_framebuffer))) == NULL)
    return (NULL);
  if ((buffer->pixels = malloc(sizeof(*pixels) * width * height * 4)) == NULL)
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
