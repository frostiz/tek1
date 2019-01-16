/*
** init_vectors.c for tekadventure in /home/DxCube/delivery/tekadventure
** 
** Made by Victor Dubret
** Login   <victor.dubret@epitech.eu>
** 
** Started on  Sun May 28 07:28:40 2017 Victor Dubret
** Last update Sun May 28 19:05:34 2017 Victor Dubret
*/

#include		"tekadventure.h"

sfVector2f	init_float_vector(int x, int y)
{
  sfVector2f		tmp;

  tmp.x = (float)x;
  tmp.y = (float)y;
  return (tmp);
}

sfVector2i	init_vector(int x, int y)
{
  sfVector2i		tmp;

  tmp.x = x;
  tmp.y = y;
  return (tmp);
}
