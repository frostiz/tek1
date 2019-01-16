/*
** calc_dir_vector.c for bsraytracer in /home/thibaut/Repository/bsraytracer1/src
** 
** Made by 
** Login   <thibaut.trouve@epitech.eu>
** 
** Started on  Tue Feb  7 09:27:04 2017 
** Last update Fri Mar 17 09:33:03 2017 
*/

#include "my.h"

sfVector3f	calc_dir_vector
(float dist_to_plane, sfVector2i screen_size, sfVector2i screen_pos)
{
  sfVector3f	dir_vector;

  dir_vector.x = dist_to_plane;
  dir_vector.y = (screen_size.x / 2) - screen_pos.x;
  dir_vector.z = (screen_size.y / 2) - screen_pos.y;
  return (dir_vector);
}
