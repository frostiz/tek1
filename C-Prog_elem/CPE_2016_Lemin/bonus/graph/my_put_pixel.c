/*
** my_put_pixel.c for my_put_pixel.c in /home/roye_v/delivery/wireframe/src
** 
** Made by Vincent Roye
** Login   <roye_v@epitech.net>
** 
** Started on  Sat Dec 10 13:50:58 2016 Vincent Roye
** Last update Thu Apr 20 20:51:54 2017 Vincent Roye
*/

#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Texture.h>
#include <SFML/Graphics/Sprite.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <math.h>
#include <stdio.h>
#include "graph.h"

void	my_put_pixel(t_my_framebuffer* framebuffer,
		     int x, int y, sfColor color)
{
  if (x > 0 && y > 0 && x < framebuffer->width &&
      y < framebuffer->height)
    {
      framebuffer->pixels[(framebuffer->width * y + x) * 4] = color.r;
      framebuffer->pixels[(framebuffer->width * y + x) * 4 + 1] = color.g;
      framebuffer->pixels[(framebuffer->width * y + x) * 4 + 2] = color.b;
      framebuffer->pixels[(framebuffer->width * y + x) * 4 + 3] = 255;
    }
}
