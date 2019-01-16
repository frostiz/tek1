/*
** init_main_character.c for init_main_character.c in /home/roye_v/delivery/tekadventure
** 
** Made by Vincent Roye
** Login   <roye_v@epitech.net>
** 
** Started on  Thu May 25 16:12:44 2017 Vincent Roye
** Last update Sun May 28 20:02:36 2017 Vincent Roye
*/

#include        <SFML/Audio.h>
#include        <SFML/Graphics.h>
#include        <SFML/Graphics/Texture.h>
#include        <SFML/Graphics/Sprite.h>
#include        <unistd.h>
#include        <stdlib.h>
#include        <fcntl.h>
#include        <math.h>
#include        <stdio.h>
#include        "tekadventure.h"
#include        "character.h"

int		init_character(t_character *character)
{
  if (init_right_walk(character) == 1)
    return (1);
  if (init_left_walk(character) == 1)
    return (1);
  if (init_up_walk(character) == 1)
    return (1);
  if (init_down_walk(character) == 1)
    return (1);
  if (init_sword_left(character) == 1)
    return (1);
  if (init_sword_right(character) == 1)
    return (1);
  if (init_wait_boss(character) == 1)
    return (1);
  if (init_walk_boss(character) == 1)
    return (1);
  if (init_attack_boss(character) == 1)
    return (1);
  if (init_boss_death(character) == 1)
    return (1);
  return (0);
}
