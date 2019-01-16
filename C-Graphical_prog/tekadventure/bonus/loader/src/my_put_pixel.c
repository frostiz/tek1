/*
** my_put_pixel.c for my_put_pixel.c in /home/roye_v/delivery/raytracer1
** 
** Made by Vincent Roye
** Login   <roye_v@epitech.net>
** 
** Started on  Sun Mar 19 20:44:49 2017 Vincent Roye
** Last update Tue Mar 21 17:15:52 2017 Vincent Roye
*/

#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Texture.h>
#include <SFML/Graphics/Sprite.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "tekadventure.h"

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

void	my_put_pixel2(t_my_framebuffer* framebuffer,
		      sfVector2i from, sfColor color, int *i)
{
  if (from.x > 0 && from.y > 0 && from.x < framebuffer->width &&
      from.y < framebuffer->height)
    {
      framebuffer->pixels[(framebuffer->width *
			   from.y + from.x) * 4] = color.r;
      framebuffer->pixels[(framebuffer->width *
			   from.y + from.x) * 4 + 1] = *i;
      framebuffer->pixels[(framebuffer->width *
			   from.y + from.x) * 4 + 2] = color.b;
      framebuffer->pixels[(framebuffer->width *
			   from.y + from.x) * 4 + 3] = *i;
      if (*i > 0)
	*i = *i - 5;
      if (*i <= 0)
	*i = 255;
    }
}

void	my_put_pixel3(t_my_framebuffer* framebuffer,
		      sfVector2i from, sfColor color, int *i)
{
  if (from.x > 0 && from.y > 0 && from.x < framebuffer->width &&
      from.y < framebuffer->height)
    {
      framebuffer->pixels[(framebuffer->width *
			   from.y + from.x) * 4] = color.r;
      framebuffer->pixels[(framebuffer->width *
			   from.y + from.x) * 4 + 1] = color.g;
      framebuffer->pixels[(framebuffer->width *
			   from.y + from.x) * 4 + 2] = color.b;
      framebuffer->pixels[(framebuffer->width *
			   from.y + from.x) * 4 + 3] = *i;
      if (*i > 0)
	(*i)--;
    }
}
