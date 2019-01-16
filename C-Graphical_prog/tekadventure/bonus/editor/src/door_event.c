/*
** door_event.c for  in /home/Zarkkos/Delivery/C_Graphical_Prog/tekadventure/editor/src
**
** Made by Antoine Duez
** Login   <Zarkkos@epitech.net>
**
** Started on  Sat May 27 02:20:26 2017 Antoine Duez
** Last update Sat May 27 17:28:17 2017 Antoine Duez
*/

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <SFML/Graphics/Texture.h>
#include <SFML/Graphics/Sprite.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "editor.h"

void		draw_door_elems(sfText *list, t_window *win)
{
  sfRenderWindow_clear(win->window, sfBlack);
  sfRenderWindow_drawSprite(win->window,
			    win->editor.scene[win->editor.pos]->s.background,
			    NULL);
  sfRenderWindow_drawSprite(win->window,
			    win->editor.scene[win->editor.pos]->s.walk_zone,
			    NULL);
  sfRenderWindow_drawSprite(win->window,
			    win->editor.scene[win->editor.pos]->s.door,
			    NULL);
  sfRenderWindow_drawSprite(win->window,
			    win->editor.scene[win->editor.pos]->s.spawn,
			    NULL);
  sfRenderWindow_drawSprite(win->window,
			    win->editor.scene[win->editor.pos]->s.object,
			    NULL);
  draw_each_text(win);
  sfRenderWindow_drawText(win->window, list, NULL);
  sfRenderWindow_display(win->window);
}

void		door_statement(t_window *win, int *i)
{
  if (sfKeyboard_isKeyPressed(sfKeyLeft) == sfTrue)
    {
      while (sfKeyboard_isKeyReleased(sfKeyLeft, win) != sfTrue)
	(void)win;
      if (*i > 0)
	i[0]--;
      else
	*i = win->editor.background_max;
    }
  if (sfKeyboard_isKeyPressed(sfKeyRight) == sfTrue)
    {
      while (sfKeyboard_isKeyReleased(sfKeyRight, win) != sfTrue)
	(void)win;
      if (*i < win->editor.background_max)
	i[0]++;
      else
	*i = 0;
    }
}

char		*door_loop(t_window *win, sfText *list)
{
  char		*string;
  int		i;

  i = 0;
  while (sfKeyboard_isKeyReleased(sfKeySpace, win) != sfTrue)
    {
      string = strdup("Scene ");
      string = realloc(string, strlen(string) + intlen(i) + 1);
      string = strcat(string, int_to_string(i));
      sfText_setString(list, string);
      draw_door_elems(list, win);
      door_statement(win, &i);
      if (sfKeyboard_isKeyReleased(sfKeySpace, win) != sfTrue)
	free(string);
    }
  return (string);
}

void		draw_door_square(t_window *win)
{
  my_draw_square(win->editor.scene[win->editor.pos]->doorbuffer,
		 win->editor.scene[win->editor.pos]->
		 d_zone.from[count_vector2i_tab(win->editor.scene[win->
								  editor.pos]->
						d_zone.from) - 1],
		 win->editor.scene[win->editor.pos]->
		 d_zone.to[count_vector2i_tab(win->editor.scene[win->
								editor.pos]->
					      d_zone.to) - 1], sfBlue);
  sfTexture_updateFromPixels(win->editor.scene[win->editor.pos]->t.door,
			     win->editor.scene[win->editor.pos]->
			     doorbuffer->pixels, SCREEN_WIDTH, SCREEN_HEIGHT,
			     0, 0);
}

void		draw_door(t_window *win)
{
  sfVector2i	value;
  sfVector2f	text_pos;
  sfVector2f	list_pos;
  sfText	*tmp;
  sfText	*list;
  char		*string;

  list_pos.x = SCREEN_WIDTH / 2 - 80;
  list_pos.y = SCREEN_HEIGHT / 2 - 16;
  value = sfMouse_getPositionRenderWindow(win->window);
  win->editor.scene[win->editor.pos]->d_zone.from =
    add_vector2i_value(win->editor.scene[win->editor.pos]->d_zone.from, value);
  while (sfMouse_isButtonReleased(sfMouseLeft, win) != sfTrue)
    (void)win;
  value = sfMouse_getPositionRenderWindow(win->window);
  win->editor.scene[win->editor.pos]->d_zone.to =
    add_vector2i_value(win->editor.scene[win->editor.pos]->d_zone.to, value);
  draw_door_square(win);
  list = prepare_door_list(list_pos, win);
  text_pos = get_text_pos(win);
  string = door_loop(win, list);
  tmp = prepare_door_tmp(string, text_pos, win);
  win->editor.scene[win->editor.pos]->d_zone.text =
    add_text_value(win->editor.scene[win->editor.pos]->d_zone.text, tmp);
}
