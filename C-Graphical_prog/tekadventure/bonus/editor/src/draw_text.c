/*
** draw_text.c for  in /home/Zarkkos/Delivery/C_Graphical_Prog/tekadventure/editor/src
**
** Made by Antoine Duez
** Login   <Zarkkos@epitech.net>
**
** Started on  Sat May 27 17:07:05 2017 Antoine Duez
** Last update Sat May 27 17:28:41 2017 Vincent Roye
*/

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <SFML/Graphics/Texture.h>
#include <SFML/Graphics/Sprite.h>
#include <stdio.h>
#include <stdlib.h>
#include "editor.h"

int draw_each_text_bis(t_window *win, int i)
{
  i = 0;
  if (win->editor.scene[win->editor.pos]->obj.text == NULL)
    (void)win;
  else
    while (win->editor.scene[win->editor.pos]->obj.text[i] != NULL)
      {
	sfRenderWindow_drawText(win->window,
				win->editor.scene[win->editor.pos]->
				obj.text[i],
				NULL);
	i++;
      }
  return (0);
}

int	draw_each_text(t_window *win)
{
  int	i;

  i = 0;
  sfRenderWindow_drawText(win->window,
			  win->editor.scene[win->editor.pos]->music.text,
			  NULL);
  if (win->editor.scene[win->editor.pos]->d_zone.text == NULL)
    (void)win;
  else
    while (win->editor.scene[win->editor.pos]->d_zone.text[i] != NULL)
      {
	sfRenderWindow_drawText(win->window,
				win->editor.scene[win->editor.pos]->
				d_zone.text[i],
				NULL);
	i++;
      }
  draw_each_text_bis(win, i);
  return (0);
}
