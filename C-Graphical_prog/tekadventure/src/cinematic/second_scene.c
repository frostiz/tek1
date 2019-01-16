/*
** second_scene.c for tekadventure in /home/frostiz/repository/tekadventure
** 
** Made by thibaut trouve
** Login   <frostiz@epitech.net>
** 
** Started on  Fri May 26 16:31:35 2017 thibaut trouve
** Last update Sun May 28 21:59:45 2017 Victor Dubret
*/

#include <stdlib.h>
#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include "tekadventure.h"
#include "cinematic.h"

static int	project_redhead(t_cinematic *cin)
{
  cin->redhead = malloc(sizeof(t_img));
  if (cin->redhead == NULL)
    return (84);
  cin->redhead->attrib.scale.x = 2.0;
  cin->redhead->attrib.scale.y = 2.0;
  cin->redhead->attrib.pos.x = 700;
  cin->redhead->attrib.pos.y = 500;
  cin->redhead->attrib.angle = 0;
  init_img(cin->redhead, "pictures/intro_cinematic/redhead.png");
  while (cin->redhead->attrib.pos.y > -100)
    {
      if (sfKeyboard_isKeyPressed(sfKeyEscape) == sfTrue)
	sfRenderWindow_close(cin->win);
      sfRenderWindow_clear(cin->win, sfGreen);
      sfRenderWindow_drawSprite(cin->win, cin->background->sprite, NULL);
      sfRenderWindow_drawSprite(cin->win, cin->redhead->sprite, NULL);
      cin->redhead->attrib.pos.y -= 0.5;
      cin->redhead->attrib.pos.x += 0.5;
      cin->redhead->attrib.angle += 1.0;
      sfSprite_setRotation(cin->redhead->sprite, cin->redhead->attrib.angle);
      sfSprite_setPosition(cin->redhead->sprite, cin->redhead->attrib.pos);
      sfRenderWindow_display(cin->win);
    }
  return (0);
}

static void	display_explosion(t_cinematic *cin)
{
  int		i;

  i = 0;
  sfClock_restart(cin->chrono);
  while (i < EXPLOSION_NB_SPRITE)
    {
      sfRenderWindow_clear(cin->win, sfGreen);
      sfRenderWindow_drawSprite(cin->win, cin->background->sprite, NULL);
      sfRenderWindow_drawSprite(cin->win, cin->explosion[i]->sprite, NULL);
      sfRenderWindow_display(cin->win);
      if (sfClock_getElapsedTime(cin->chrono).microseconds > 50000)
	{
	  i++;
	  sfClock_restart(cin->chrono);
	}
    }
  sfRenderWindow_clear(cin->win, sfGreen);
  sfRenderWindow_drawSprite(cin->win, cin->background->sprite, NULL);
  sfRenderWindow_display(cin->win);
}

static void init_second_scene(t_cinematic *cin)
{
  init_img(cin->background, "pictures/intro_cinematic/background3.jpg");
  cin->ship->attrib.pos.x = -100.0;
  cin->ship->attrib.pos.y = -100.0;
  cin->ship->attrib.scale.x = 0.25;
  cin->ship->attrib.scale.y = 0.25;
  sfSprite_setScale(cin->ship->sprite, cin->ship->attrib.scale);
  sfSprite_rotate(cin->ship->sprite, 150.0);
}

static void	fall_ship(t_cinematic *cin)
{
  sfRenderWindow_clear(cin->win, sfGreen);
  sfRenderWindow_drawSprite(cin->win, cin->background->sprite, NULL);
  sfSprite_setPosition(cin->ship->sprite, cin->ship->attrib.pos);
  cin->ship->attrib.pos.x += 0.50;
  cin->ship->attrib.pos.y += 0.38;
  sfRenderWindow_drawSprite(cin->win, cin->ship->sprite, NULL);
  sfRenderWindow_display(cin->win);
}

int	second_scene(t_cinematic *cin)
{
  sfTime        offset_boum;

  offset_boum.microseconds = 1000000;
  init_second_scene(cin);
  while (cin->ship->attrib.pos.x < 830.0 && cin->ship->attrib.pos.y < 613.0)
    {
      if (sfKeyboard_isKeyPressed(sfKeyEscape) == sfTrue)
	{
	  sfRenderWindow_close(cin->win);
	  return (1);
	}
      fall_ship(cin);
    }
  sfRenderWindow_clear(cin->win, sfGreen);
  sfRenderWindow_drawSprite(cin->win, cin->background->sprite, NULL);
  sfRenderWindow_display(cin->win);
  sfMusic_play(cin->explode);
  sfMusic_setPlayingOffset(cin->explode, offset_boum);
  display_explosion(cin);
  if (project_redhead(cin) == 84)
    return (84);
  if (fondu(cin) == 84)
    return (84);
  return (0);
}
