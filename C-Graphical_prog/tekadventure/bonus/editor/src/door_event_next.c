/*
** door_event_next.c for  in /home/Zarkkos/Delivery/C_Graphical_Prog/tekadventure/editor/src
**
** Made by Antoine Duez
** Login   <Zarkkos@epitech.net>
**
** Started on  Sat May 27 02:22:30 2017 Antoine Duez
** Last update Sat May 27 16:53:54 2017 Antoine Duez
*/

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <SFML/Graphics/Texture.h>
#include <SFML/Graphics/Sprite.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "editor.h"

sfText		*prepare_door_list(sfVector2f list_pos, t_window *win)
{
  sfText	*list;

  list = sfText_create();
  sfText_setColor(list, sfWhite);
  sfText_setCharacterSize(list, 32);
  sfText_setPosition(list, list_pos);
  sfText_setFont(list, win->editor.scene[win->editor.pos]->d_zone.font);
  return (list);
}

sfText		*prepare_door_tmp(char *string, sfVector2f text_pos,
				  t_window *win)
{
  sfText	*tmp;

  tmp = sfText_create();
  sfText_setColor(tmp, sfWhite);
  sfText_setCharacterSize(tmp, 12);
  sfText_setString(tmp, string);
  sfText_setPosition(tmp, text_pos);
  sfText_setFont(tmp, win->editor.scene[win->editor.pos]->d_zone.font);
  return (tmp);
}

sfVector2f  get_text_pos(t_window *win)
{
  sfVector2f text_pos;

  text_pos.x = win->editor.scene[win->editor.pos]->
    d_zone.from[count_vector2i_tab(win->editor.scene[win->editor.pos]->
				   d_zone.from) - 1].x;
  text_pos.y = win->editor.scene[win->editor.pos]->
    d_zone.from[count_vector2i_tab(win->editor.scene[win->editor.pos]->
				   d_zone.from) - 1].y;
  return (text_pos);
}
