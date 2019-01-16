/*
** init_left_sword.c for init_left_sword.c in /home/roye_v/delivery/tekadventure
** 
** Made by Vincent Roye
** Login   <roye_v@epitech.net>
** 
** Started on  Wed May 24 15:05:49 2017 Vincent Roye
** Last update Sat May 27 01:05:09 2017 Vincent Roye
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
  character->left_sword.texture[0] =
    sfTexture_createFromFile("pictures/character/Sword1.png", NULL);
  if (!(character->left_sword.texture[0]))
    return (1);
  character->left_sword.texture[1] =
    sfTexture_createFromFile("pictures/character/Sword2.png", NULL);
  if (!(character->left_sword.texture[1]))
    return (1);
  character->left_sword.texture[2] =
    sfTexture_createFromFile("pictures/character/Sword3.png", NULL);
  if (!(character->left_sword.texture[2]))
    return (1);
  character->left_sword.texture[3] =
    sfTexture_createFromFile("pictures/character/Sword4.png", NULL);
  if (!(character->left_sword.texture[3]))
    return (1);
  character->left_sword.texture[4] =
    sfTexture_createFromFile("pictures/character/Sword5.png", NULL);
  if (!(character->left_sword.texture[4]))
    return (1);
  character->left_sword.texture[5] =
    sfTexture_createFromFile("pictures/character/Sword6.png", NULL);
  if (!(character->left_sword.texture[5]))
    return (1);
  return (0);
}

int		init_sword_left(t_character *character)
{
  int		i;

  i = 0;
  while (i <= 6)
    {
      character->left_sword.sprite[i] = sfSprite_create();
      i++;
    }
  if (init_sword_texture(character) == 1)
    return (1);
  sfSprite_setTexture(character->left_sword.sprite[0],
		      character->left_sword.texture[0], sfTrue);
  sfSprite_setTexture(character->left_sword.sprite[1],
		      character->left_sword.texture[1], sfTrue);
  sfSprite_setTexture(character->left_sword.sprite[2],
		      character->left_sword.texture[2], sfTrue);
  sfSprite_setTexture(character->left_sword.sprite[3],
		      character->left_sword.texture[3], sfTrue);
  sfSprite_setTexture(character->left_sword.sprite[4],
		      character->left_sword.texture[4], sfTrue);
  sfSprite_setTexture(character->left_sword.sprite[5],
		      character->left_sword.texture[5], sfTrue);
  return (0);
}
