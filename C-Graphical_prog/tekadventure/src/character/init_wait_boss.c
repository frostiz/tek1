/*
** init_wait_boss.c for init_wait_boss.c in /home/roye_v/delivery/tekadventure
** 
** Made by Vincent Roye
** Login   <roye_v@epitech.net>
** 
** Started on  Sun May 28 07:34:58 2017 Vincent Roye
** Last update Sun May 28 12:58:48 2017 Vincent Roye
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
  sfSprite_setTexture(character->wait_boss.sprite[0],
		      character->wait_boss.texture[0], sfTrue);
  sfSprite_setTexture(character->wait_boss.sprite[1],
		      character->wait_boss.texture[1], sfTrue);
  sfSprite_setTexture(character->wait_boss.sprite[2],
		      character->wait_boss.texture[2], sfTrue);
  sfSprite_setTexture(character->wait_boss.sprite[3],
		      character->wait_boss.texture[3], sfTrue);
  sfSprite_setTexture(character->wait_boss.sprite[4],
		      character->wait_boss.texture[4], sfTrue);
  sfSprite_setTexture(character->wait_boss.sprite[5],
		      character->wait_boss.texture[5], sfTrue);
  sfSprite_setTexture(character->wait_boss.sprite[6],
		      character->wait_boss.texture[6], sfTrue);
}

static int	set_sprite2(t_character *character)
{
  character->wait_boss.texture[5] =
    sfTexture_createFromFile("pictures/character/clement6.png", NULL);
  if (!(character->wait_boss.texture[5]))
    return (1);
  character->wait_boss.texture[6] =
    sfTexture_createFromFile("pictures/character/clement7.png", NULL);
  if (!(character->wait_boss.texture[6]))
    return (1);
  return (0);
}

static int	set_sprite(t_character *character)
{
  character->wait_boss.texture[0] =
    sfTexture_createFromFile("pictures/character/clement.png", NULL);
  if (!(character->wait_boss.texture[0]))
    return (1);
  character->wait_boss.texture[1] =
    sfTexture_createFromFile("pictures/character/clement2.png", NULL);
  if (!(character->wait_boss.texture[1]))
    return (1);
  character->wait_boss.texture[2] =
    sfTexture_createFromFile("pictures/character/clement3.png", NULL);
  if (!(character->wait_boss.texture[2]))
    return (1);
  character->wait_boss.texture[3] =
    sfTexture_createFromFile("pictures/character/clement4.png", NULL);
  if (!(character->wait_boss.texture[3]))
    return (1);
  character->wait_boss.texture[4] =
    sfTexture_createFromFile("pictures/character/clement5.png", NULL);
  if (!(character->wait_boss.texture[4]))
    return (1);
  if (set_sprite2(character) == 1)
    return (1);
  return (0);
}

int		init_wait_boss(t_character *character)
{
  int		i;

  i = 0;
  while (i <= 6)
    {
      character->wait_boss.sprite[i] = sfSprite_create();
      i++;
    }
  if (set_sprite(character) == 1)
    return (1);
  set_texture(character);
  return (0);
}
