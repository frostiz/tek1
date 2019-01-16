/*
** rotate.c for raytracer in /home/thibaut/Repository/raytracer1
** 
** Made by 
** Login   <thibaut.trouve@epitech.eu>
** 
** Started on  Thu Feb 23 11:05:53 2017 
** Last update Sun Mar 19 17:54:08 2017 
*/

#include "my.h"

sfVector3f	rotate_xyz(sfVector3f to_rotate, sfVector3f angles)
{
  sfVector3f	result;

  angles.x = angles.x * M_PI / 180;
  angles.y = angles.y * M_PI / 180;
  angles.z = angles.z * M_PI / 180;
  result.x = to_rotate.x;
  result.y = to_rotate.y * (cos(angles.x)) + to_rotate.z * (-sin(angles.x));
  result.z = to_rotate.y * (sin(angles.x)) + to_rotate.z * (cos(angles.x));
  to_rotate.x = result.x * (cos(angles.y)) + result.z * (sin(angles.y));
  to_rotate.y = result.y;
  to_rotate.z = result.x * (-sin(angles.y)) + result.z * (cos(angles.y));
  result.x = to_rotate.x * (cos(angles.z)) + to_rotate.y * (-sin(angles.z));
  result.y = to_rotate.x * (sin(angles.z)) + to_rotate.y * (cos(angles.z));
  result.z = to_rotate.z;
  return (result);
}

sfVector3f	rotate_zyx(sfVector3f to_rotate, sfVector3f angles)
{
  sfVector3f	result;

  angles.z = angles.z * M_PI / 180;
  angles.y = angles.y * M_PI / 180;
  angles.x = angles.x * M_PI / 180;
  result.z = to_rotate.z;
  result.y = to_rotate.x * (sin(angles.z)) + to_rotate.y * (cos(angles.z));
  result.x = to_rotate.x * (cos(angles.z)) + to_rotate.y * (-sin(angles.z));
  to_rotate.z = result.x * (-sin(angles.y)) + result.z * (cos(angles.y));
  to_rotate.y = result.y;
  to_rotate.x = result.x * (cos(angles.y)) + result.z * (sin(angles.y));
  result.z = to_rotate.y * (sin(angles.x)) + to_rotate.z * (cos(angles.x));
  result.y = to_rotate.y * (cos(angles.x)) + to_rotate.z * (-sin(angles.x));
  result.x = to_rotate.x;
  return (result);
}
