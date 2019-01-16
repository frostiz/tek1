/*
** my_draw_line.c for my_draw_line.c in /home/roye_v/delivery/tekadventure
** 
** Made by Vincent Roye
** Login   <roye_v@epitech.net>
** 
** Started on  Tue Mar 21 12:19:31 2017 Vincent Roye
** Last update Sun May 28 18:37:12 2017 thibaut trouve
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

static void	my_put_diag1(t_my_framebuffer *buffer,
			     t_diag draw, sfColor color, int *i)
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
      sfVector2i caca;
      caca.x = draw.x;
      caca.y = draw.y;
      my_put_pixel2(buffer, caca, color, i);
      draw.i++;
    }
}

static void	my_put_diag2(t_my_framebuffer *buffer,
			     t_diag draw, sfColor color, int *i)
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
      sfVector2i caca;
      caca.x = draw.x;
      caca.y = draw.y;
      my_put_pixel2(buffer, caca, color, i);
      draw.i++;
    }
}

static void	my_put_diag(t_my_framebuffer* buffer, sfVector2i from,
		    sfVector2i to, sfColor color, int *i)
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
  my_put_pixel2(buffer, from, color, i);
  if (draw.dx > draw.dy)
    my_put_diag1(buffer, draw, color, i);
  else
    my_put_diag2(buffer, draw, color, i);
}

void	my_draw_line2(t_my_framebuffer* framebuffer, sfVector2i from,
		     sfVector2i to, sfColor color)
{
  int	i;

  i = 0;
  if (to.x == from.x)
    {
      while (from.y < to.y)
	{
	  my_put_pixel2(framebuffer, from, color, &i);
	  from.y++;
	}
    }
  if (to.y == from.y)
    {
      while (from.x < to.x)
	{
	  my_put_pixel2(framebuffer, from, color, &i);
	  from.x++;
	}
    }
  my_put_diag(framebuffer, from, to, color, &i);
}
