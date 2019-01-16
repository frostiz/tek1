/*
** init_spaceship.c for tekadventure in /home/frostiz/repository/tekadventure
** 
** Made by thibaut trouve
** Login   <frostiz@epitech.net>
** 
** Started on  Fri May 26 16:18:24 2017 thibaut trouve
** Last update Sun May 28 20:34:13 2017 Victor Dubret
*/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <stdlib.h>
#include "tekadventure.h"
#include "cinematic.h"

int	init_spaceship(t_cinematic *cin)
{
  cin->ship = malloc(sizeof(t_img));
  if (cin->ship == NULL)
    return (84);
  cin->ship->attrib.scale.x = 0.250;
  cin->ship->attrib.scale.y = 0.250;
  cin->ship->attrib.pos.x = 1000;
  cin->ship->attrib.pos.y = 600;
  cin->ship->attrib.angle = -15.0;
  if (init_img(cin->ship,
	       "pictures/intro_cinematic/spaceship.png") == 84)
    return (84);
  return (0);
}
