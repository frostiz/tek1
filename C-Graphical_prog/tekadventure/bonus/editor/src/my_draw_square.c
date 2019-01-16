/*
** my_draw_square.c for my_draw_square.c in /home/roye_v/delivery/tekadventure
**
** Made by Vincent Roye
** Login   <roye_v@epitech.net>
**
** Started on  Tue Mar 21 12:26:34 2017 Vincent Roye
** Last update Sun May 28 04:13:32 2017 Antoine Duez
*/

#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Texture.h>
#include <SFML/Graphics/Sprite.h>
#include "editor.h"

void		my_draw_square(t_my_framebuffer* framebuffer, sfVector2i from,
			       sfVector2i to, sfColor color)
{
  sfVector2i	save;

  if (to.y - from.y < 0)
    {
      save.y = to.y;
      to.y = from.y;
      from.y = save.y;
    }
  save.x = to.x;
  while (from.y < to.y)
    {
      save.y = from.y;
      my_draw_line(framebuffer, from, save, color);
      from.y++;
    }
}

void		draw_ext(t_my_framebuffer* framebuffer, sfVector2i from,
			 sfVector2i to, sfColor color)
{
  sfVector2i	save;

  save.x = to.x;
  save.y = from.y;
  my_draw_line(framebuffer, from, save, color);
  save.x = from.x;
  save.y = to.y;
  my_draw_line(framebuffer, from, save, color);
  save.y = from.y;
  from.y = to.y;
  my_draw_line(framebuffer, from, to, color);
  from.y = save.y;
  from.x = to.x;
  my_draw_line(framebuffer, from, to, color);
}
