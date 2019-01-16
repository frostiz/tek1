/*
** intersect_plane.c for s in /home/thibaut/Repository/bsraytracer1/src
** 
** Made by 
** Login   <thibaut.trouve@epitech.eu>
** 
** Started on  Tue Feb  7 15:55:46 2017 
** Last update Thu Mar 16 15:02:02 2017 
*/

#include "my.h"

sfVector3f	get_normal_plane(int upward)
{
  sfVector3f	result;

  result.x = 0;
  result.y = 0;
  if (upward == 1)
    result.z = 100;
  else
    result.z = -100;
  return (result);
}

float	intersect_plane(sfVector3f eye_pos, sfVector3f dir_vector)
{
  float	k;

  if (dir_vector.z == 0)
    return (-1.0);
  k = -eye_pos.z / dir_vector.z;
  if (k < 0.0)
    return (-1.0);
  else
    return (k);
}
