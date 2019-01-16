/*
** my_draw_square.c for my_draw_square.c in /home/roye_v/delivery/tekadventure
** 
** Made by Vincent Roye
** Login   <roye_v@epitech.net>
** 
** Started on  Tue Mar 21 12:26:34 2017 Vincent Roye
** Last update Tue Mar 21 12:31:02 2017 Vincent Roye
*/

#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Texture.h>
#include <SFML/Graphics/Sprite.h>
#include "tekadventure.h"

void	my_draw_square(t_my_framebuffer* framebuffer, sfVector2i from,
		       sfVector2i to, sfColor color)
{
  int	i;

  i = 0;
  while (i < to.y)
    {
      my_draw_line(framebuffer, from, to, color);
      from.y++;
      to.y++;
      i++;
    }
}
