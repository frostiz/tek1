/*
** fondu.c for tekadventur in /home/frostiz/repository/tekadventure
** 
** Made by thibaut trouve
** Login   <frostiz@epitech.net>
** 
** Started on  Fri May 26 16:56:49 2017 thibaut trouve
** Last update Sun May 28 20:31:16 2017 Victor Dubret
*/

#include <stdlib.h>
#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include "tekadventure.h"
#include "cinematic.h"

static void init_rect(t_cinematic *cin, sfColor *black, sfVector2f *size,
		      sfRectangleShape *rect)
{
  black->r = 0;
  black->g = 0;
  black->b = 0;
  black->a = 0;
  size->x = WIDTH;
  size->y = HEIGHT;
  sfRectangleShape_setSize(rect, *size);
  size->x = 0;
  size->y = 0;
  sfRectangleShape_setPosition(rect, *size);
  sfClock_restart(cin->chrono);
  while (sfClock_getElapsedTime(cin->chrono).microseconds < 100000);
}

int	fondu(t_cinematic *cin)
{
  sfColor               black;
  sfRectangleShape      *rect;
  sfVector2f            size;

  rect = sfRectangleShape_create();
  if (!rect)
    return (84);
  init_rect(cin, &black, &size, rect);
  while (black.a < 255)
    {
      if (sfKeyboard_isKeyPressed(sfKeyEscape) == sfTrue)
	{
	  sfRenderWindow_close(cin->win);
	  return (1);
	}
      sfRectangleShape_setFillColor(rect, black);
      sfRenderWindow_clear(cin->win, sfGreen);
      sfRenderWindow_drawSprite(cin->win, cin->background->sprite, NULL);
      sfRenderWindow_drawRectangleShape(cin->win, rect, NULL);
      sfRenderWindow_display(cin->win);
      sfClock_restart(cin->chrono);
      while (sfClock_getElapsedTime(cin->chrono).microseconds < 10000);
      black.a++;
    }
  return (0);
}
