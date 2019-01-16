/*
** button_event.c for  in /home/Zarkkos/Delivery/C_Graphical_Prog/tekadventure
**
** Made by Antoine Duez
** Login   <Zarkkos@epitech.net>
**
** Started on  Tue May 23 14:44:01 2017 Antoine Duez
** Last update Sat May 27 16:17:11 2017 Antoine Duez
*/

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <SFML/Graphics/Texture.h>
#include <SFML/Graphics/Sprite.h>
#include <stdio.h>
#include <stdlib.h>
#include "editor.h"

int		button_next_background(t_window *win)
{
  while (sfMouse_isButtonReleased(sfMouseLeft, win) != sfTrue)
    (void)win->editor.pos;
  win->editor.pos++;
  if (win->editor.pos > win->editor.background_max)
    win->editor.pos = 0;
  win->editor.scene[win->editor.pos]->t.background =
    sfTexture_createFromFile(win->editor.scene[win->editor.pos]->name, NULL);
  if (!win->editor.scene[win->editor.pos]->t.background)
    return (1);
  sfSprite_setTexture(win->editor.scene[win->editor.pos]->s.background,
		      win->editor.scene[win->editor.pos]->t.background,
		      sfTrue);
  sfTexture_updateFromPixels(win->editor.scene[win->editor.pos]->t.walk_zone,
			     win->editor.scene[win->editor.pos]->
			     drawbuffer->pixels,
			     SCREEN_WIDTH, SCREEN_HEIGHT, 0, 0);
  return (0);
}

int		button_previous_background(t_window *win)
{
  while (sfMouse_isButtonReleased(sfMouseLeft, win) != sfTrue)
    (void)win->editor.pos;
  win->editor.pos--;
  if (win->editor.pos < 0)
    win->editor.pos = win->editor.background_max;
  win->editor.scene[win->editor.pos]->t.background =
    sfTexture_createFromFile(win->editor.scene[win->editor.pos]->name,
			     NULL);
  if (!win->editor.scene[win->editor.pos]->t.background)
    return (1);
  sfSprite_setTexture(win->editor.scene[win->editor.pos]->s.background,
		      win->editor.scene[win->editor.pos]->t.background,
		      sfTrue);
  sfTexture_updateFromPixels(win->editor.scene[win->editor.pos]->t.walk_zone,
			     win->editor.scene[win->editor.pos]->
			     drawbuffer->pixels, SCREEN_WIDTH, SCREEN_HEIGHT,
			     0, 0);
  return (0);
}

void		draw_local_music(t_window *win, sfText *list, int i)
{
  sfText_setString(list, win->editor.info.music[i]);
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

void		music_button_condition(t_window *win, int *i)
{
  if (sfKeyboard_isKeyPressed(sfKeyLeft) == sfTrue)
    {
      while (sfKeyboard_isKeyReleased(sfKeyLeft, win) != sfTrue)
	(void)win;
      if (*i > 0)
	i[0]--;
      else
	*i = win->editor.music_max;
    }
  if (sfKeyboard_isKeyPressed(sfKeyRight) == sfTrue)
    {
      while (sfKeyboard_isKeyReleased(sfKeyRight, win) != sfTrue)
	(void)win;
      if (*i < win->editor.music_max)
	i[0]++;
      else
	*i = 0;
    }
}

int		button_music(t_window *win)
{
  sfVector2f	list_pos;
  sfText	*list;
  int		i;

  i = 0;
  list_pos.x = SCREEN_WIDTH / 2 - 80;
  list_pos.y = SCREEN_HEIGHT / 2 - 16;
  list = sfText_create();
  sfText_setColor(list, sfWhite);
  sfText_setCharacterSize(list, 18);
  sfText_setPosition(list, list_pos);
  sfText_setFont(list, win->editor.scene[win->editor.pos]->d_zone.font);
  while (sfKeyboard_isKeyReleased(sfKeySpace, win) != sfTrue)
    {
      draw_local_music(win, list, i);
      music_button_condition(win, &i);
    }
  sfText_setString(win->editor.scene[win->editor.pos]->music.text,
		   sfText_getString(list));
  return (0);
}
