/*
** intersect_sphere.c for d in /home/thibaut/Repository/bsraytracer1/src
** 
** Made by 
** Login   <thibaut.trouve@epitech.eu>
** 
** Started on  Tue Feb  7 14:45:32 2017 
** Last update Sun Mar 19 18:19:42 2017 
*/

#include "my.h"

sfVector3f	get_normal_sphere(sfVector3f intersection_point)
{
  return (intersection_point);
}

float	delta_positive_sphere(float delta, float a, float b)
{
  float	k1;
  float	k2;

  k1 = (-b + sqrtf(delta)) / (2 * a);
  k2 = (-b - sqrtf(delta)) / (2 * a);
  if (k1 < 0.0 && k2 < 0.0)
    return (-1.0);
  if (k1 < k2)
    {
      if (k1 > 0.0)
	return (k1);
      if (k1 < 0.0 && k2 > 0.0)
	return (k2);
    }
  if (k2 < k1)
    {
      if (k2 > 0.0)
	return (k2);
      if (k2 < 0.0 && k1 > 0.0)
	return (k1);
    }
  else
    return (k1);
  return (k1);
}

float	interpret_delta_sphere(float delta, float a, float b)
{
  float	k1;

  if (delta > 0.0)
    {
      return (delta_positive_sphere(delta, a, b));
    }
  else if (delta == 0.0)
    {
      k1 = -b / (2 * a);
      if (k1 > 0.0)
	return (k1);
      return (-1.0);
    }
  else
    return (-1.0);
}

float	intersect_sphere(sfVector3f eye_pos,
			 sfVector3f dir_vector, float radius)
{
  float	a;
  float	b;
  float	c;
  float	delta;

  a = dir_vector.x * dir_vector.x +
    dir_vector.y * dir_vector.y +
    dir_vector.z * dir_vector.z;
  b = 2 * (eye_pos.x * dir_vector.x +
	   eye_pos.y * dir_vector.y +
	   eye_pos.z * dir_vector.z);
  c = eye_pos.x * eye_pos.x +
    eye_pos.y * eye_pos.y +
    eye_pos.z * eye_pos.z -
    (radius * radius);
  delta = (b * b) - (4 * a * c);
  return (interpret_delta_sphere(delta, a, b));
}
