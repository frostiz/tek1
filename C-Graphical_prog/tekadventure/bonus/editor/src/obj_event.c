/*
** obj_event.c for  in /home/Zarkkos/Delivery/C_Graphical_Prog/tekadventure/editor/src
**
** Made by Antoine Duez
** Login   <Zarkkos@epitech.net>
**
** Started on  Sat May 27 02:26:01 2017 Antoine Duez
** Last update Sat May 27 17:21:07 2017 Antoine Duez
*/

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <SFML/Graphics/Texture.h>
#include <SFML/Graphics/Sprite.h>
#include <stdio.h>
#include <stdlib.h>
#include "editor.h"

void		obj_statement(t_window *win, int *i)
{
  if (sfKeyboard_isKeyPressed(sfKeyLeft) == sfTrue)
    {
      while (sfKeyboard_isKeyReleased(sfKeyLeft, win) != sfTrue)
	(void)win;
      if (*i > 0)
	i[0]--;
      else
	*i = win->editor.obj_max;
    }
  if (sfKeyboard_isKeyPressed(sfKeyRight) == sfTrue)
    {
      while (sfKeyboard_isKeyReleased(sfKeyRight, win) != sfTrue)
	(void)win;
      if (*i < win->editor.obj_max)
	i[0]++;
      else
	*i = 0;
    }
}

void		draw_obj_elems(sfText *list, t_window *win)
{
  sfRenderWindow_clear(win->window, sfBlack);
  sfRenderWindow_drawSprite(win->window,
			    win->editor.scene[win->editor.pos]->
			    s.background,
			    NULL);
  sfRenderWindow_drawSprite(win->window,
			    win->editor.scene[win->editor.pos]->
			    s.walk_zone,
			    NULL);
  sfRenderWindow_drawSprite(win->window,
			    win->editor.scene[win->editor.pos]->
			    s.door,
			    NULL);
  sfRenderWindow_drawSprite(win->window,
			    win->editor.scene[win->editor.pos]->
			    s.spawn,
			    NULL);
  sfRenderWindow_drawSprite(win->window,
			    win->editor.scene[win->editor.pos]->
			    s.object,
			    NULL);
  draw_each_text(win);
  sfRenderWindow_drawText(win->window, list, NULL);
  sfRenderWindow_display(win->window);
}

sfText		*obj_loop(sfText *list, t_window *win)
{
  int		i;

  i = 0;
  while (sfKeyboard_isKeyReleased(sfKeySpace, win) != sfTrue)
    {
      sfText_setString(list, win->editor.info.object[i]);
      draw_obj_elems(list, win);
      obj_statement(win, &i);
    }
  return (list);
}

void    draw_obj_square(t_window *win)
{
  my_draw_square(win->editor.scene[win->editor.pos]->objectbuffer,
		 win->editor.scene[win->editor.pos]->
		 obj.from[count_vector2i_tab(win->editor.
					     scene[win->editor.pos]->
					     obj.from) - 1],
		 win->editor.scene[win->editor.pos]->
		 obj.to[count_vector2i_tab(win->editor.
					   scene[win->editor.pos]->
					   obj.to) - 1], sfCyan);
  sfTexture_updateFromPixels(win->editor.scene[win->editor.pos]->
			     t.object, win->editor.scene[win->
							 editor.pos]->
			     objectbuffer->pixels, SCREEN_WIDTH, SCREEN_HEIGHT,
			     0, 0);
}

void		draw_object(t_window *win)
{
  sfVector2i	value;
  sfVector2f	text_pos;
  sfVector2f	list_pos;
  sfText	*tmp;
  sfText	*list;

  list_pos.x = SCREEN_WIDTH / 2 - 80;
  list_pos.y = SCREEN_HEIGHT / 2 - 16;
  value = sfMouse_getPositionRenderWindow(win->window);
  win->editor.scene[win->editor.pos]->obj.from =
    add_vector2i_value(win->editor.scene[win->editor.pos]->obj.from, value);
  while (sfMouse_isButtonReleased(sfMouseLeft, win) != sfTrue)
    (void)win;
  value = sfMouse_getPositionRenderWindow(win->window);
  win->editor.scene[win->editor.pos]->obj.to =
    add_vector2i_value(win->editor.scene[win->editor.pos]->obj.to, value);
  draw_obj_square(win);
  list = prepare_obj_list(list_pos, win);
  list = obj_loop(list, win);
  text_pos = get_text_obj_pos(win);
  tmp = prepare_obj_tmp(text_pos, win, list);
  win->editor.scene[win->editor.pos]->obj.text =
    add_text_value(win->editor.scene[win->editor.pos]->obj.text, tmp);
}
