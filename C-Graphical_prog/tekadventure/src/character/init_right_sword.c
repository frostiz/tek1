/*
** init_right_sword.c for init_right_sword.c in /home/roye_v/delivery/tekadventure
** 
** Made by Vincent Roye
** Login   <roye_v@epitech.net>
** 
** Started on  Wed May 24 15:57:57 2017 Vincent Roye
** Last update Sat May 27 01:05:42 2017 Vincent Roye
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
#include	"character.h"

static int	init_sword_texture(t_character *character)
{
  character->right_sword.texture[0] =
    sfTexture_createFromFile("pictures/character/Sword7.png", NULL);
  if (!(character->right_sword.texture[0]))
    return (1);
  character->right_sword.texture[1] =
    sfTexture_createFromFile("pictures/character/Sword8.png", NULL);
  if (!(character->right_sword.texture[1]))
    return (1);
  character->right_sword.texture[2] =
    sfTexture_createFromFile("pictures/character/Sword9.png", NULL);
  if (!(character->right_sword.texture[2]))
    return (1);
  character->right_sword.texture[3] =
    sfTexture_createFromFile("pictures/character/Sword10.png", NULL);
  if (!(character->right_sword.texture[3]))
    return (1);
  character->right_sword.texture[4] =
    sfTexture_createFromFile("pictures/character/Sword11.png", NULL);
  if (!(character->right_sword.texture[4]))
    return (1);
  character->right_sword.texture[5] =
    sfTexture_createFromFile("pictures/character/Sword12.png", NULL);
  if (!(character->right_sword.texture[5]))
    return (1);
  return (0);
}

int		init_sword_right(t_character *character)
{
  int		i;

  i = 0;
  while (i <= 6)
    {
      character->right_sword.sprite[i] = sfSprite_create();
      i++;
    }
  if (init_sword_texture(character) == 1)
    return (1);
  sfSprite_setTexture(character->right_sword.sprite[0],
		      character->right_sword.texture[0], sfTrue);
  sfSprite_setTexture(character->right_sword.sprite[1],
		      character->right_sword.texture[1], sfTrue);
  sfSprite_setTexture(character->right_sword.sprite[2],
		      character->right_sword.texture[2], sfTrue);
  sfSprite_setTexture(character->right_sword.sprite[3],
		      character->right_sword.texture[3], sfTrue);
  sfSprite_setTexture(character->right_sword.sprite[4],
		      character->right_sword.texture[4], sfTrue);
  sfSprite_setTexture(character->right_sword.sprite[5],
		      character->right_sword.texture[5], sfTrue);
  return (0);
}
