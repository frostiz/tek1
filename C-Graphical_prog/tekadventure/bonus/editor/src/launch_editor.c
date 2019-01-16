/*
** launch_editor.c for  in /home/Zarkkos/Delivery/C_Graphical_Prog/tekadventure/editor
**
** Made by Antoine Duez
** Login   <Zarkkos@epitech.net>
**
** Started on  Thu May 18 23:35:46 2017 Antoine Duez
** Last update Sun May 28 22:07:02 2017 Vincent Roye
*/

#include	<SFML/Audio.h>
#include	<SFML/Graphics.h>
#include	<SFML/Graphics/Texture.h>
#include	<SFML/Graphics/Sprite.h>
#include	<stdio.h>
#include	<stdlib.h>
#include	"editor.h"

void		draw_screen_sprite(t_window *win)
{
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
}

void	keep_screen(t_window *win)
{
  sfRenderWindow_clear(win->window, sfBlack);
  draw_screen_sprite(win);
  draw_each_text(win);
  if (win->menu.display_standard_ui == 1)
    {
      draw_square_next_background(win);
      draw_square_previous_background(win);
      draw_square_walk_button(win);
      draw_square_spawn_button(win);
      draw_square_door_button(win);
      draw_square_music_button(win);
      draw_square_object_button(win);
    }
  sfRenderWindow_display(win->window);
}

int	keyboard(t_window *win)
{
  if (sfKeyboard_isKeyPressed(sfKeyEscape) == sfTrue)
    sfRenderWindow_close(win->window);
  if (sfKeyboard_isKeyPressed(sfKeyK) == sfTrue)
    {
      while (sfKeyboard_isKeyReleased(sfKeyK, win) != sfTrue)
	(void)win->menu.display_standard_ui;
      win->menu.display_standard_ui *= -1;
    }
  return (0);
}

int	launch_editor(t_window win)
{
  init_screen(&win);
  if (init_main_screen(&win) == 1)
    return (84);
  while (sfRenderWindow_isOpen(win.window))
    {
      if (keyboard(&win) == 1)
	return (84);
      if (mouse(&win) == 1)
	return (84);
      keep_screen(&win);
    }
  sfRenderWindow_destroy(win.window);
  return (0);
}
