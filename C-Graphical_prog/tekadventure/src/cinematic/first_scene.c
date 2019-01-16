/*
** first_scene.c for tekadventure in /home/frostiz/repository/tekadventure
** 
** Made by thibaut trouve
** Login   <frostiz@epitech.net>
** 
** Started on  Fri May 26 16:22:06 2017 thibaut trouve
** Last update Sun May 28 20:30:58 2017 Victor Dubret
*/

#include <stdlib.h>
#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include "tekadventure.h"
#include "cinematic.h"

int	first_scene(t_cinematic *cin)
{
  while ((cin->ship->attrib.pos.x > 760.0 && cin->ship->attrib.pos.y > 169.0))
    {
      if (sfKeyboard_isKeyPressed(sfKeyEscape) == sfTrue)
	{
	  sfRenderWindow_close(cin->win);
	  return (1);
	}
      sfRenderWindow_clear(cin->win, sfGreen);
      sfRenderWindow_drawSprite(cin->win, cin->background->sprite, NULL);
      sfSprite_setPosition(cin->ship->sprite, cin->ship->attrib.pos);
      cin->ship->attrib.pos.x -= 0.05;
      cin->ship->attrib.pos.y -= 0.09;
      sfSprite_setScale(cin->ship->sprite, cin->ship->attrib.scale);
      cin->ship->attrib.scale.x -= 0.00005;
      cin->ship->attrib.scale.y -= 0.00005;
      sfRenderWindow_drawSprite(cin->win, cin->ship->sprite, NULL);
      sfRenderWindow_display(cin->win);
    }
  return (0);
}
