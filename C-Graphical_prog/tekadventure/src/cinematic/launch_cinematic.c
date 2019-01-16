/*
** launch_cinematic.c for tekadventure in /home/frostiz/repository/tekadventure
** 
** Made by thibaut trouve
** Login   <thibaut.trouve@epitech.eu>
** 
** Started on  Wed May 24 12:29:29 2017 thibaut trouve
** Last update Sun May 28 21:59:31 2017 Victor Dubret
*/

#include <time.h>
#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "cinematic.h"
#include "tekadventure.h"

int	init_img(t_img *img, char *img_path)
{
  img->texture = sfTexture_createFromFile(img_path, NULL);
  if (img->texture == NULL)
    return (84);
  img->sprite = sfSprite_create();
  if (img->sprite == NULL)
    return (84);
  sfSprite_setTexture(img->sprite, img->texture, sfTrue);
  sfSprite_setScale(img->sprite, img->attrib.scale);
  sfSprite_setRotation(img->sprite, img->attrib.angle);
  sfSprite_setPosition(img->sprite, img->attrib.pos);
  return (0);
}

static int	init_cinematic(t_cinematic *cin)
{
  cin->win = create_window("TekAdventure", WIDTH, HEIGHT);
  if (!cin->win)
    return (84);
  if (init_background(cin) == 84)
    return (84);
  if (init_explosion(cin) == 84)
    return (84);
  if (init_spaceship(cin) == 84)
    return (84);
  return (0);
}

static void	cin_destroy(t_cinematic *cin)
{
  int	i;

  sfSprite_destroy(cin->background->sprite);
  sfTexture_destroy(cin->background->texture);
  sfSprite_destroy(cin->ship->sprite);
  sfTexture_destroy(cin->ship->texture);
  i = 0;
  while (i < EXPLOSION_NB_SPRITE)
    {
      sfSprite_destroy(cin->explosion[i]->sprite);
      sfTexture_destroy(cin->explosion[i]->texture);
      free(cin->explosion[i]);
      i++;
    }
  sfMusic_destroy(cin->explode);
  sfClock_destroy(cin->chrono);
  sfRenderWindow_destroy(cin->win);
  free(cin->explosion);
  free(cin->ship);
  free(cin->background);
  free(cin);
}

int		mainloop(t_cinematic *cin)
{
  int		ret;

  ret = first_scene(cin);
  if (ret == 0)
    {
      ret = second_scene(cin);
      if (ret == 84)
	{
	  sfRenderWindow_close(cin->win);
	  return (84);
	}
      if (ret != 1)
	sfRenderWindow_close(cin->win);
    }
  else if (ret == 84)
    {
      sfRenderWindow_close(cin->win);
      return (84);
    }
  return (0);
}

int		launch_cinematic()
{
  t_cinematic	*cin;
  int		ret;

  cin = malloc(sizeof(t_cinematic));
  if (cin == NULL)
    return (84);
  if (init_cinematic(cin) == 84)
    return (84);
  while (sfRenderWindow_isOpen(cin->win))
    {
      ret = mainloop(cin);
      if (ret == 84)
	return (84);
    }
  cin_destroy(cin);
  return (ret);
}
