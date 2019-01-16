/*
** my_put_pixel.c for my_put_pixel.c in /home/frostiz/bswireframe
** 
** Made by thibaut trouve
** Login   <frostiz@epitech.net>
** 
** Started on  Wed Nov 16 14:20:38 2016 thibaut trouve
** Last update Thu Feb 16 19:22:34 2017 
*/

#include "my.h"

void	my_put_pixel(t_my_framebuffer* framebuffer, int x, int y,
		     sfColor color)
{
  if (x >= 0 && y >= 0 && x <= framebuffer->width && y <= framebuffer->height)
    {
      framebuffer->pixels[(framebuffer->width * y + x) * 4] = color.r;
      framebuffer->pixels[(framebuffer->width * y + x) * 4 + 1] = color.g;
      framebuffer->pixels[(framebuffer->width * y + x) * 4 + 2] = color.b;
      framebuffer->pixels[(framebuffer->width * y + x) * 4 + 3] = color.a;
    }
}
