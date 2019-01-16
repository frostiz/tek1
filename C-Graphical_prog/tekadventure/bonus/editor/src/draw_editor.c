/*
** draw_editor.c for  in /home/Zarkkos/Delivery/C_Graphical_Prog/tekadventure
**
** Made by Antoine Duez
** Login   <Zarkkos@epitech.net>
**
** Started on  Tue May 23 14:54:44 2017 Antoine Duez
** Last update Sat May 27 16:34:01 2017 Antoine Duez
*/

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <SFML/Graphics/Texture.h>
#include <SFML/Graphics/Sprite.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "editor.h"

void		draw_walk_zone(t_window *win)
{
  sfVector2i	value;

  value = sfMouse_getPositionRenderWindow(win->window);
  win->editor.scene[win->editor.pos]->w_zone.from =
    add_vector2i_value(win->editor.scene[win->editor.pos]->w_zone.from, value);
  while (sfMouse_isButtonReleased(sfMouseLeft, win) != sfTrue)
    (void)win;
  value = sfMouse_getPositionRenderWindow(win->window);
  win->editor.scene[win->editor.pos]->w_zone.to =
    add_vector2i_value(win->editor.scene[win->editor.pos]->w_zone.to, value);
  my_draw_square(win->editor.scene[win->editor.pos]->drawbuffer,
		 win->editor.scene[win->editor.pos]->
		 w_zone.from[count_vector2i_tab(win->editor.scene[win->
								  editor.pos]->
						w_zone.from) - 1],
		 win->editor.scene[win->editor.pos]->
		 w_zone.to[count_vector2i_tab(win->editor.scene[win->
								editor.pos]->
					      w_zone.to) - 1], sfYellow);
  sfTexture_updateFromPixels(win->editor.scene[win->editor.pos]->
			     t.walk_zone, win->editor.scene[win->editor.pos]->
			     drawbuffer->pixels, SCREEN_WIDTH,
			     SCREEN_HEIGHT, 0, 0);
}

int		intlen(int nb)
{
  int		i;

  i = 1;
  while (nb / 10 != 0)
    {
      nb /= 10;
      i++;
    }
  return (i);
}

void		draw_spawn(t_window *win)
{
  sfVector2i	value;

  win->editor.scene[win->editor.pos]->spawnbuffer =
    my_framebuffer_create(SCREEN_WIDTH, SCREEN_HEIGHT);
  value = sfMouse_getPositionRenderWindow(win->window);
  win->editor.scene[win->editor.pos]->spawn.from.x = value.x - 5;
  win->editor.scene[win->editor.pos]->spawn.from.y = value.y - 5;
  win->editor.scene[win->editor.pos]->spawn.to.x = value.x + 5;
  win->editor.scene[win->editor.pos]->spawn.to.y = value.y + 5;
  my_draw_square(win->editor.scene[win->editor.pos]->spawnbuffer,
		 win->editor.scene[win->editor.pos]->spawn.from,
		 win->editor.scene[win->editor.pos]->spawn.to, sfMagenta);
  sfTexture_updateFromPixels(win->editor.scene[win->editor.pos]->t.spawn,
			     win->editor.scene[win->editor.pos]->
			     spawnbuffer->pixels, SCREEN_WIDTH,
			     SCREEN_HEIGHT, 0, 0);
}
