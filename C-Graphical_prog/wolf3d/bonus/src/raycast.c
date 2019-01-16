/*
** raycast.c for raycast.c in /home/frostiz/wolf3d
** 
** Made by thibaut trouve
** Login   <frostiz@epitech.net>
** 
** Started on  Wed Dec 21 18:47:42 2016 thibaut trouve
** Last update Sun Jan 15 21:32:23 2017 thibaut trouve
*/

#include "my.h"

float	raycast(sfVector2f pos, float a, int **map, sfVector2i mapSize)
{
  sfVector2f	pos_init;
  float		distance;

  pos_init.x = pos.x;
  pos_init.y = pos.y;
  if (map[(int)pos.y][(int)pos.x] == 0)
    while (map[(int)pos.y][(int)pos.x] == 0 &&
	   pos.x < mapSize.x - 1 &&
	   pos.y < mapSize.y - 1 &&
	   pos.x > 1 && pos.y > 1)
      {
	pos = move_forward(pos, a, 0.01);
      }
  distance = sqrtf
    (powf((pos.x - pos_init.x), 2) + powf((pos.y - pos_init.y), 2));

  return (distance);
}
