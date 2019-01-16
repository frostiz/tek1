/*
** parallax.c for parallax.c in /home/roye_v/delivery/tekadventure
** 
** Made by Vincent Roye
** Login   <roye_v@epitech.net>
** 
** Started on  Mon May 22 14:15:12 2017 Vincent Roye
** Last update Sun May 28 12:38:29 2017 Victor Dubret
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

static void	sound_click(sfVector2i *mouse_coords, t_window *win)
{
  int		i;

  i = 0;
  if (mouse_coords->x > ((SCREEN_WIDTH / 2) + 205) &&
      mouse_coords->x < ((SCREEN_WIDTH / 2) + 345) &&
      mouse_coords->y > (SCREEN_HEIGHT - 260) &&
      mouse_coords->y < (SCREEN_HEIGHT - 235))
    {
      sfText_setColor(win->main_menu.options.text, sfRed);
      while (sfMouse_isButtonPressed(sfMouseLeft) == sfTrue)
	i = 1;
      if (i == 1)
	{
	  win->main_menu.sound++;
	  if (win->main_menu.sound % 2 != 0)
	    sfMusic_pause(win->music);
	  else
	    sfMusic_play(win->music);
	}
    }
  else
    sfText_setColor(win->main_menu.options.text, sfBlue);
}

static void	get_mouse_toolbar(sfVector2i *mouse_coords, t_window *win)
{
  if (mouse_coords->x > ((SCREEN_WIDTH / 2) + 205) &&
      mouse_coords->x < ((SCREEN_WIDTH / 2) + 345) &&
      mouse_coords->y > (SCREEN_HEIGHT - 290) &&
      mouse_coords->y < (SCREEN_HEIGHT - 265))
    {
      sfText_setColor(win->main_menu.new_game.text, sfRed);
      if (sfMouse_isButtonPressed(sfMouseLeft) == sfTrue)
	win->main_menu.clicked = 1;
    }
  else
    sfText_setColor(win->main_menu.new_game.text, sfBlue);
  sound_click(mouse_coords, win);
}

static void	move_background(t_window *win,
				sfVector2i mouse_coords, sfVector2f pic_pos)
{
  if (mouse_coords.x > (SCREEN_WIDTH / 2) &&
      win->bg_pos.x < 0)
    pic_pos.x = 1;
  else if (mouse_coords.x < (SCREEN_WIDTH / 2) &&
	   win->bg_pos.x > -600)
    pic_pos.x = -1;
  else
    pic_pos.x = 0;
  if (mouse_coords.y > (SCREEN_HEIGHT / 2) &&
      win->bg_pos.y < 0)
    pic_pos.y = 1;
  else if (mouse_coords.y < (SCREEN_HEIGHT / 2) &&
	   win->bg_pos.y > -700)
    pic_pos.y = -1;
  else
    pic_pos.y = 0;
  sfSprite_move(win->sprite, pic_pos);
}

int		parallax_main_screen(t_window *win)
{
  sfVector2i	mouse_coords;
  sfVector2f	pic_pos;

  mouse_coords = sfMouse_getPosition((sfWindow *)win->window);
  get_mouse_toolbar(&mouse_coords, win);
  win->bg_pos = sfSprite_getPosition(win->sprite);
  move_background(win, mouse_coords, pic_pos);
  return (0);
}
