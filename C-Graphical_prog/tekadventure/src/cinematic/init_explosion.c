/*
** init_explosion.c for tekadventure in /home/frostiz/repository/tekadventure
** 
** Made by thibaut trouve
** Login   <frostiz@epitech.net>
** 
** Started on  Fri May 26 16:14:21 2017 thibaut trouve
** Last update Sun May 28 20:34:00 2017 Victor Dubret
*/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <stdlib.h>
#include "tekadventure.h"
#include "cinematic.h"

static char	**init_explosion_path()
{
  char		**path;

  path = malloc(sizeof(char *) * (EXPLOSION_NB_SPRITE + 1));
  if (path == NULL)
    return (NULL);
  path[0] = "pictures/intro_cinematic/explosion-1.png";
  path[1] = "pictures/intro_cinematic/explosion-2.png";
  path[2] = "pictures/intro_cinematic/explosion-3.png";
  path[3] = "pictures/intro_cinematic/explosion-4.png";
  path[4] = "pictures/intro_cinematic/explosion-5.png";
  path[5] = "pictures/intro_cinematic/explosion-6.png";
  path[6] = "pictures/intro_cinematic/explosion-7.png";
  path[7] = "pictures/intro_cinematic/explosion-8.png";
  path[8] = "pictures/intro_cinematic/explosion-9.png";
  path[9] = "pictures/intro_cinematic/explosion-10.png";
  path[10] = "pictures/intro_cinematic/explosion-11.png";
  path[11] = "pictures/intro_cinematic/explosion-12.png";
  path[12] = "pictures/intro_cinematic/explosion-13.png";
  path[13] = "pictures/intro_cinematic/explosion-14.png";
  path[14] = "pictures/intro_cinematic/explosion-15.png";
  return (path);
}

static int	init_explosion_texture(t_cinematic *cin)
{
  int	i;
  char	**path;

  path = init_explosion_path();
  if (path == NULL)
    return (84);
  i = 0;
  while (i < EXPLOSION_NB_SPRITE)
    {
      cin->explosion[i] = malloc(sizeof(t_img));
      if (cin->explosion[i] == NULL)
	return (84);
      cin->explosion[i]->attrib.scale.x = 3;
      cin->explosion[i]->attrib.scale.y = 3;
      cin->explosion[i]->attrib.pos.x = 550.0;
      cin->explosion[i]->attrib.pos.y = 413.0;
      cin->explosion[i]->attrib.angle = 0.0;
      if (init_img(cin->explosion[i], path[i]) == 84)
	return (84);
      i++;
    }
  free(path);
  return (0);
}

int	init_explosion(t_cinematic *cin)
{
  cin->explosion = malloc(sizeof(t_img *) * (EXPLOSION_NB_SPRITE + 1));
  if (cin->explosion == NULL)
    return (84);
  if (init_explosion_texture(cin) == 84)
    return (84);
  cin->explode = sfMusic_createFromFile
    ("pictures/intro_cinematic/explosion.flac");
  if (!cin->explode)
    return (84);
  cin->chrono = sfClock_create();
  if (!cin->chrono)
    return (84);
  return (0);
}
