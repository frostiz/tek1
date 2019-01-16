/*
** intersect_sphere.c for d in /home/thibaut/Repository/bsraytracer1/src
** 
** Made by 
** Login   <thibaut.trouve@epitech.eu>
** 
** Started on  Tue Feb  7 14:45:32 2017 
** Last update Sun Mar 19 18:26:30 2017 
*/

#include "my.h"

sfVector3f	get_normal_cylinder(sfVector3f intersection_point)
{
  sfVector3f result;

  result.x = intersection_point.x;
  result.y = intersection_point.y;
  result.z = 0;
  return (result);
}

float	delta_positive_cylinder(float delta, float a, float b)
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

float	interpret_delta_cylinder(float delta, float a, float b)
{
  float k1;

  if (delta > 0.0)
    {
      return (delta_positive_cylinder(delta, a, b));
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

float	intersect_cylinder(sfVector3f eye_pos,
			   sfVector3f dir_vector, float radius)
{
  float a;
  float b;
  float c;
  float delta;

  a = dir_vector.x * dir_vector.x +
    dir_vector.y * dir_vector.y;
  b = 2 * (eye_pos.x * dir_vector.x +
	   eye_pos.y * dir_vector.y);
  c = eye_pos.x * eye_pos.x +
    eye_pos.y * eye_pos.y -
    (radius * radius);
  delta = (b * b) - (4 * a * c);
  return (interpret_delta_cylinder(delta, a, b));
}
