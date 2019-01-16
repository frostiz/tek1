/*
** init_background.c for tekadventure in /home/frostiz/repository/tekadventure
** 
** Made by thibaut trouve
** Login   <frostiz@epitech.net>
** 
** Started on  Fri May 26 16:10:49 2017 thibaut trouve
** Last update Sun May 28 20:31:56 2017 Victor Dubret
*/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <stdlib.h>
#include "tekadventure.h"
#include "cinematic.h"

int	  init_background(t_cinematic *cin)
{
  cin->background = malloc(sizeof(t_img));
  if (cin->background == NULL)
    return (84);
  cin->background->attrib.scale.x = 1;
  cin->background->attrib.scale.y = 1;
  cin->background->attrib.pos.x = 0;
  cin->background->attrib.pos.y = 0;
  cin->background->attrib.angle = 0.0;
  if (init_img(cin->background,
	       "pictures/intro_cinematic/planete-vincent2.png") == 84)
    return (84);
  return (0);
}
