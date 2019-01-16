/*
** test.c for test.c in /home/frostiz/bswolf3d/src
** 
** Made by thibaut trouve
** Login   <frostiz@epitech.net>
** 
** Started on  Thu Dec 15 15:33:25 2016 thibaut trouve
** Last update Mon Jan  9 22:53:14 2017 thibaut trouve
*/

#include "my.h"

sfVector2f	move_forward(sfVector2f pos, float direction, float distance)
{
  sfVector2f	converted;

  direction = direction * PI/180;
  converted.x = pos.x + distance * cos(direction);
  converted.y = pos.y + distance * sin(direction);
  return (converted);
}
