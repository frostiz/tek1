/*
** init_left_walk.c for init_left_walk.c in /home/roye_v/delivery/tekadventure
**
** Made by Vincent Roye
** Login   <roye_v@epitech.net>
**
** Started on  Wed May 24 17:12:55 2017 Vincent Roye
** Last update Sun May 28 08:32:54 2017 Vincent Roye
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
  sfSprite_setTexture(character->walk_boss.sprite[0],
		      character->walk_boss.texture[0], sfTrue);
  sfSprite_setTexture(character->walk_boss.sprite[1],
		      character->walk_boss.texture[1], sfTrue);
  sfSprite_setTexture(character->walk_boss.sprite[2],
		      character->walk_boss.texture[2], sfTrue);
  sfSprite_setTexture(character->walk_boss.sprite[3],
		      character->walk_boss.texture[3], sfTrue);
  sfSprite_setTexture(character->walk_boss.sprite[4],
		      character->walk_boss.texture[4], sfTrue);
  sfSprite_setTexture(character->walk_boss.sprite[5],
		      character->walk_boss.texture[5], sfTrue);
  sfSprite_setTexture(character->walk_boss.sprite[6],
		      character->walk_boss.texture[6], sfTrue);
  sfSprite_setTexture(character->walk_boss.sprite[7],
		      character->walk_boss.texture[7], sfTrue);
  sfSprite_setTexture(character->walk_boss.sprite[8],
		      character->walk_boss.texture[8], sfTrue);
}

static int	set_sprite2(t_character *character)
{
  character->walk_boss.texture[5] =
    sfTexture_createFromFile("pictures/character/clement_walk6.png", NULL);
  if (!(character->walk_boss.texture[5]))
    return (1);
  character->walk_boss.texture[6] =
    sfTexture_createFromFile("pictures/character/clement_walk7.png", NULL);
  if (!(character->walk_boss.texture[6]))
    return (1);
  character->walk_boss.texture[7] =
    sfTexture_createFromFile("pictures/character/clement_walk8.png", NULL);
  if (!(character->walk_boss.texture[7]))
    return (1);
  character->walk_boss.texture[8] =
    sfTexture_createFromFile("pictures/character/clement_walk9.png", NULL);
  if (!(character->walk_boss.texture[8]))
    return (1);
  return (0);
}

static int	set_sprite(t_character *character)
{
  character->walk_boss.texture[0] =
    sfTexture_createFromFile("pictures/character/clement_walk.png", NULL);
  if (!(character->walk_boss.texture[0]))
    return (1);
  character->walk_boss.texture[1] =
    sfTexture_createFromFile("pictures/character/clement_walk2.png", NULL);
  if (!(character->walk_boss.texture[1]))
    return (1);
  character->walk_boss.texture[2] =
    sfTexture_createFromFile("pictures/character/clement_walk3.png", NULL);
  if (!(character->walk_boss.texture[2]))
    return (1);
  character->walk_boss.texture[3] =
    sfTexture_createFromFile("pictures/character/clement_walk4.png", NULL);
  if (!(character->walk_boss.texture[3]))
    return (1);
  character->walk_boss.texture[4] =
    sfTexture_createFromFile("pictures/character/clement_walk5.png", NULL);
  if (!(character->walk_boss.texture[4]))
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
      size = sfTexture_getSize(character->walk_boss.texture[i]);
      f_size.x = (float)size.x / 2;
      f_size.y = (float)size.y;
      sfSprite_setOrigin(character->walk_boss.sprite[i], f_size);
      i++;
    }
}

int		init_walk_boss(t_character *character)
{
  int		i;

  i = 0;
  while (i <= 8)
    {
      character->walk_boss.sprite[i] = sfSprite_create();
      i++;
    }
  if (set_sprite(character) == 1)
    return (1);
  set_texture(character);
  set_origin(character);
  return (0);
}
