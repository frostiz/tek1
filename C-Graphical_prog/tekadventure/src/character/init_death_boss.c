/*
** init_death_boss.c for init_death_boss.c in /home/roye_v/tekadventure
** 
** Made by Vincent Roye
** Login   <roye_v@epitech.net>
** 
** Started on  Sun May 28 19:56:36 2017 Vincent Roye
** Last update Sun May 28 20:04:52 2017 Vincent Roye
*/

#include	<SFML/Audio.h>
#include	<SFML/Graphics.h>
#include	<unistd.h>
#include	<stdlib.h>
#include	<fcntl.h>
#include	<stdio.h>
#include	"tekadventure.h"
#include	"character.h"

static int	init_sword_texture(t_character *character)
{
  character->boss_death.texture[0] =
    sfTexture_createFromFile("pictures/character/death.png", NULL);
  if (!(character->boss_death.texture[0]))
    return (1);
  character->boss_death.texture[1] =
    sfTexture_createFromFile("pictures/character/death2.png", NULL);
  if (!(character->boss_death.texture[1]))
    return (1);
  character->boss_death.texture[2] =
    sfTexture_createFromFile("pictures/character/death3.png", NULL);
  if (!(character->boss_death.texture[2]))
    return (1);
  character->boss_death.texture[3] =
    sfTexture_createFromFile("pictures/character/death4.png", NULL);
  if (!(character->boss_death.texture[3]))
    return (1);
  character->boss_death.texture[4] =
    sfTexture_createFromFile("pictures/character/death5.png", NULL);
  if (!(character->boss_death.texture[4]))
    return (1);
  character->boss_death.texture[5] =
    sfTexture_createFromFile("pictures/character/death6.png", NULL);
  if (!(character->boss_death.texture[5]))
    return (1);
  return (0);
}

int		init_boss_death(t_character *character)
{
  int		i;

  i = 0;
  while (i <= 6)
    {
      character->boss_death.sprite[i] = sfSprite_create();
      i++;
    }
  if (init_sword_texture(character) == 1)
    return (1);
  sfSprite_setTexture(character->boss_death.sprite[0],
		      character->boss_death.texture[0], sfTrue);
  sfSprite_setTexture(character->boss_death.sprite[1],
		      character->boss_death.texture[1], sfTrue);
  sfSprite_setTexture(character->boss_death.sprite[2],
		      character->boss_death.texture[2], sfTrue);
  sfSprite_setTexture(character->boss_death.sprite[3],
		      character->boss_death.texture[3], sfTrue);
  sfSprite_setTexture(character->boss_death.sprite[4],
		      character->boss_death.texture[4], sfTrue);
  sfSprite_setTexture(character->boss_death.sprite[5],
		      character->boss_death.texture[5], sfTrue);
  return (0);
}
