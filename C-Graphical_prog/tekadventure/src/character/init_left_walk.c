/*
** init_left_walk.c for init_left_walk.c in /home/roye_v/delivery/tekadventure
**
** Made by Vincent Roye
** Login   <roye_v@epitech.net>
**
** Started on  Wed May 24 17:12:55 2017 Vincent Roye
** Last update Sun May 28 03:09:35 2017 Antoine Duez
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
#include	"main_screen.h"
#include	"character.h"

static void	set_texture(t_character *character)
{
  sfSprite_setTexture(character->left_walk.sprite[0],
		      character->left_walk.texture[0], sfTrue);
  sfSprite_setTexture(character->left_walk.sprite[1],
		      character->left_walk.texture[1], sfTrue);
  sfSprite_setTexture(character->left_walk.sprite[2],
		      character->left_walk.texture[2], sfTrue);
  sfSprite_setTexture(character->left_walk.sprite[3],
		      character->left_walk.texture[3], sfTrue);
  sfSprite_setTexture(character->left_walk.sprite[4],
		      character->left_walk.texture[4], sfTrue);
  sfSprite_setTexture(character->left_walk.sprite[5],
		      character->left_walk.texture[5], sfTrue);
  sfSprite_setTexture(character->left_walk.sprite[6],
		      character->left_walk.texture[6], sfTrue);
  sfSprite_setTexture(character->left_walk.sprite[7],
		      character->left_walk.texture[7], sfTrue);
  sfSprite_setTexture(character->left_walk.sprite[8],
		      character->left_walk.texture[8], sfTrue);
}

static int	set_sprite2(t_character *character)
{
  character->left_walk.texture[5] =
    sfTexture_createFromFile("pictures/character/Walk15.png", NULL);
  if (!(character->left_walk.texture[5]))
    return (1);
  character->left_walk.texture[6] =
    sfTexture_createFromFile("pictures/character/Walk16.png", NULL);
  if (!(character->left_walk.texture[6]))
    return (1);
  character->left_walk.texture[7] =
    sfTexture_createFromFile("pictures/character/Walk17.png", NULL);
  if (!(character->left_walk.texture[7]))
    return (1);
  character->left_walk.texture[8] =
    sfTexture_createFromFile("pictures/character/Walk18.png", NULL);
  if (!(character->left_walk.texture[8]))
    return (1);
  return (0);
}

static int	set_sprite(t_character *character)
{
  character->left_walk.texture[0] =
    sfTexture_createFromFile("pictures/character/Walk10.png", NULL);
  if (!(character->left_walk.texture[0]))
    return (1);
  character->left_walk.texture[1] =
    sfTexture_createFromFile("pictures/character/Walk11.png", NULL);
  if (!(character->left_walk.texture[1]))
    return (1);
  character->left_walk.texture[2] =
    sfTexture_createFromFile("pictures/character/Walk12.png", NULL);
  if (!(character->left_walk.texture[2]))
    return (1);
  character->left_walk.texture[3] =
    sfTexture_createFromFile("pictures/character/Walk13.png", NULL);
  if (!(character->left_walk.texture[3]))
    return (1);
  character->left_walk.texture[4] =
    sfTexture_createFromFile("pictures/character/Walk14.png", NULL);
  if (!(character->left_walk.texture[4]))
    return (1);
  if (set_sprite2(character) == 1)
    return (1);
  return (0);
}

static void	set_origin(t_character *character)
{
  sfVector2u	size;
  sfVector2f	f_size;
  int		i;

  i = 0;
  while (i < 9)
    {
      size = sfTexture_getSize(character->left_walk.texture[i]);
      f_size.x = (float)size.x / 2;
      f_size.y = (float)size.y;
      sfSprite_setOrigin(character->left_walk.sprite[i], f_size);
      i++;
    }
}

int		init_left_walk(t_character *character)
{
  int		i;

  i = 0;
  while (i <= 8)
    {
      character->left_walk.sprite[i] = sfSprite_create();
      i++;
    }
  if (set_sprite(character) == 1)
    return (1);
  set_texture(character);
  set_origin(character);
  return (0);
}
