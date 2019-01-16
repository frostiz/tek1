/*
** my_put_pixel.c for my_put_pixel.c in /home/roye_v/delivery/raytracer1
**
** Made by Vincent Roye
** Login   <roye_v@epitech.net>
**
** Started on  Sun Mar 19 20:44:49 2017 Vincent Roye
** Last update Fri May 19 00:38:23 2017 Antoine Duez
*/

#include <SFML/Graphics/RenderWindow.h>
#include "editor.h"

void	my_put_pixel(t_my_framebuffer* framebuffer,
		     int x, int y, sfColor color)
{
  if (x > 0 && y > 0 && x < framebuffer->width &&
      y < framebuffer->height)
    {
      framebuffer->pixels[(framebuffer->width * y + x) * 4] = color.r;
      framebuffer->pixels[(framebuffer->width * y + x) * 4 + 1] = color.g;
      framebuffer->pixels[(framebuffer->width * y + x) * 4 + 2] = color.b;
      framebuffer->pixels[(framebuffer->width * y + x) * 4 + 3] = color.a;
    }
}
