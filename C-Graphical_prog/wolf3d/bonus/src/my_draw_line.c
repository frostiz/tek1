/*
** my_draw_line.c for my_draw_line.c in /home/frostiz/bswireframe
** 
** Made by thibaut trouve
** Login   <frostiz@epitech.net>
** 
** Started on  Wed Nov 16 14:05:02 2016 thibaut trouve
** Last update Fri Jan 13 16:00:04 2017 thibaut trouve
*/

#include "my.h"

void	my_put_line(t_lines *lines, sfColor color, t_my_framebuffer
		    *framebuffer, sfVector2i from)
{
  lines->stack = lines->dist_x / 2;
  lines->i = 1;
  while (lines->i <= lines->dist_x)
    {
      from.x += lines->inclin_x ;
      lines->stack += lines->dist_y;
      if (lines->stack >= lines->dist_x)
	{
	  lines->stack -= lines->dist_x;
	  from.y += lines->inclin_y;
	}
      my_put_pixel(framebuffer, from.x, from.y, color);
      lines->i++;
    }
}

void	my_put_line_inv(t_lines *lines, sfColor color, t_my_framebuffer
			*framebuffer, sfVector2i from)
{
  lines->stack = lines->dist_y / 2 ;
  lines->i = 1;
  while (lines->i <= lines->dist_y)
    {
      from.y += lines->inclin_y ;
      lines->stack += lines->dist_x ;
      if ( lines->stack >= lines->dist_y )
	{
	  lines->stack -= lines->dist_y ;
	  from.x += lines->inclin_x ;
	}
      my_put_pixel(framebuffer, from.x, from.y, color);
      lines->i++;
    }
}

void	my_draw_line(t_my_framebuffer *framebuffer, sfVector2i from,
		     sfVector2i to, sfColor color)
{
  t_lines	lines;

  lines.dist_x = to.x - from.x;
  lines.dist_y = to.y - from.y;
  lines.inclin_x = (lines.dist_x > 0) ? 1 : -1;
  lines.inclin_y = (lines.dist_y > 0) ? 1 : -1;
  lines.dist_x = abs(lines.dist_x);
  lines.dist_y = abs(lines.dist_y);
  my_put_pixel(framebuffer, from.x, from.y, color);
  if (lines.dist_x > lines.dist_y)
    my_put_line(&lines, color, framebuffer, from);
  else
    my_put_line_inv(&lines, color, framebuffer, from);
}
