/*
** main_screen_loop.c for main_screen_loop.c in /home/roye_v/delivery/tekadventure
** 
** Made by Vincent Roye
** Login   <roye_v@epitech.net>
** 
** Started on  Mon May 22 14:09:42 2017 Vincent Roye
** Last update Sun May 28 22:00:38 2017 Vincent Roye
*/

#include	<SFML/Audio.h>
#include	<SFML/Graphics.h>
#include	<SFML/Graphics/Texture.h>
#include	<SFML/Graphics/Sprite.h>
#include	<unistd.h>
#include	<stdlib.h>
#include	<fcntl.h>
#include	<math.h>
#include	<stdio.h>
#include	"tekadventure.h"
#include	"main_screen.h"

void		keyboard(t_window *win)
{
  if (sfKeyboard_isKeyPressed(sfKeyEscape) == sfTrue)
    sfRenderWindow_close(win->window);
}

void		keep_screen(t_window *win)
{
  sfRenderWindow_clear(win->window, sfBlack);
  sfRenderWindow_drawSprite(win->window, win->sprite, NULL);
  sfRenderWindow_drawSprite(win->window, win->cockpit.sprite, NULL);
  sfRenderWindow_drawText(win->window, win->text.text, NULL);
  sfRenderWindow_drawText(win->window, win->text2.text, NULL);
  sfRenderWindow_drawText(win->window, win->main_menu.new_game.text, NULL);
  sfRenderWindow_drawText(win->window, win->main_menu.options.text, NULL);
  sfRenderWindow_drawText(win->window, win->main_menu.main_title.text, NULL);
  sfRenderWindow_display(win->window);
}

int		main_screen_loop()
{
  t_window	win;

  if (init_main_screen(&win) == -1)
    return (84);
  win.music = sfMusic_createFromFile("src/main_screen/main_screen_theme.ogg");
  if (!(win.music))
    return (84);
  sfMusic_setLoop(win.music, sfTrue);
  sfMusic_play(win.music);
  while (sfRenderWindow_isOpen(win.window) && win.main_menu.clicked != 1)
    {
      keyboard(&win);
      parallax_main_screen(&win);
      keep_screen(&win);
    }
  sfRenderWindow_destroy(win.window);
  sfMusic_stop(win.music);
  sfMusic_destroy(win.music);
  sfText_destroy(win.text.text);
  sfText_destroy(win.text2.text);
  sfText_destroy(win.main_menu.new_game.text);
  sfText_destroy(win.main_menu.options.text);
  sfText_destroy(win.main_menu.main_title.text);
  return (0);
}
