/*
** obj_event_next.c for  in /home/Zarkkos/Delivery/C_Graphical_Prog/tekadventure/editor/src
**
** Made by Antoine Duez
** Login   <Zarkkos@epitech.net>
**
** Started on  Sat May 27 02:36:55 2017 Antoine Duez
** Last update Sat May 27 17:21:13 2017 Antoine Duez
*/

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <SFML/Graphics/Texture.h>
#include <SFML/Graphics/Sprite.h>
#include <stdio.h>
#include <stdlib.h>
#include "editor.h"

sfText *prepare_obj_list(sfVector2f list_pos, t_window *win)
{
  sfText *list;

  list = sfText_create();
  sfText_setColor(list, sfWhite);
  sfText_setCharacterSize(list, 32);
  sfText_setPosition(list, list_pos);
  sfText_setFont(list, win->editor.scene[win->editor.pos]->obj.font);
  return (list);
}

sfText *prepare_obj_tmp(sfVector2f text_pos, t_window *win, sfText *list)
{
  sfText *tmp;

  tmp = sfText_create();
  sfText_setColor(tmp, sfWhite);
  sfText_setCharacterSize(tmp, 12);
  sfText_setString(tmp, sfText_getString(list));
  sfText_setPosition(tmp, text_pos);
  sfText_setFont(tmp, win->editor.scene[win->editor.pos]->obj.font);
  return (tmp);
}

sfVector2f get_text_obj_pos(t_window *win)
{
  sfVector2f text_pos;

  text_pos.x = win->editor.scene[win->editor.pos]->
    obj.from[count_vector2i_tab(win->editor.scene[win->editor.pos]->
				obj.from) - 1].x;
  text_pos.y = win->editor.scene[win->editor.pos]->
    obj.from[count_vector2i_tab(win->editor.scene[win->editor.pos]->
				obj.from) - 1].y;
  return (text_pos);
}
