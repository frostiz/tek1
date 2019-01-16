/*
** my_draw_line.c for my_draw_line.c in /home/roye_v/delivery/wireframe/src
** 
** Made by Vincent Roye
** Login   <roye_v@epitech.net>
** 
** Started on  Sat Dec 10 13:51:59 2016 Vincent Roye
** Last update Thu Apr 20 20:51:40 2017 Vincent Roye
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

void	my_put_diag1(t_my_framebuffer *buffer, t_diag draw, sfColor color)
{
  draw.cumul = draw.dx / 2;
  draw.i = 1;
  while (draw.i <= draw.dx)
    {
      draw.x += draw.x_inclin;
      draw.cumul += draw.dy;
      if (draw.cumul >= draw.dx)
	{
	  draw.cumul -= draw.dx;
	  draw.y += draw.y_inclin;
	}
      my_put_pixel(buffer, draw.x, draw.y, color);
      draw.i++;
    }
}

void	my_put_diag2(t_my_framebuffer *buffer, t_diag draw, sfColor color)
{
  draw.cumul = draw.dy / 2;
  draw.i = 1;
  while (draw.i <= draw.dy)
    {
      draw.y += draw.y_inclin;
      draw.cumul += draw.dx;
      if (draw.cumul >= draw.dy)
	{
	  draw.cumul -= draw.dy;
	  draw.x += draw.x_inclin;
	}
      my_put_pixel(buffer, draw.x, draw.y, color);
      draw.i++;
    }
}

void	my_put_diag(t_my_framebuffer* buffer, sfVector2i from,
		    sfVector2i to, sfColor color)
{
  t_diag	draw;

  draw.x = from.x;
  draw.y = from.y;
  draw.dx = to.x - from.x;
  draw.dy = to.y - from.y;
  draw.x_inclin = (draw.dx > 0) ? 1 : -1;
  draw.y_inclin = (draw.dy > 0) ? 1 : -1;
  draw.dx = abs(draw.dx);
  draw.dy = abs(draw.dy);
  my_put_pixel(buffer, draw.x, draw.y, color);
  if (draw.dx > draw.dy)
    my_put_diag1(buffer, draw, color);
  else
    my_put_diag2(buffer, draw, color);
}

void	my_draw_line(t_my_framebuffer* framebuffer, sfVector2i from,
		     sfVector2i to, sfColor color)
{
  if (to.x == from.x)
    {
      while (from.y < to.y)
	{
	  my_put_pixel(framebuffer, from.x, from.y, color);
	  from.y++;
	}
    }
  if (to.y == from.y)
    {
      while (from.x < to.x)
	{
	  my_put_pixel(framebuffer, from.x, from.y, color);
	  from.x++;
	}
    }
  my_put_diag(framebuffer, from, to, color);
}
