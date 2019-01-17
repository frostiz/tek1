/*
** mainloop.c for dante in /home/thibaut/Repository/dante/generator
** 
** Made by Thibaut Trouvé
** Login   <thibaut.trouve@epitech.eu>
** 
** Started on  Sun May 14 20:41:43 2017 Thibaut Trouvé
** Last update Sun May 14 20:42:18 2017 Thibaut Trouvé
*/

#include <stdlib.h>
#include "generator.h"

void    carve(t_maze *data, int idx_cell, t_coord **frontier)
{
  data->maze[idx_cell] = VOID;
  check_around(data, idx_cell, frontier);
}

int     treat_all(t_maze *data)
{
  int i;

  if (data->maze == NULL)
    return (0);
  i = 0;
  while (i < data->width * data->height)
    {
      if (data->maze[i] == NOT_TREATED)
        data->maze[i] = WALL;
      i++;
    }
  if (data->maze[i - 1] == WALL)
    return (-1);
  return (0);
}

void    mainloop(t_coord *frontier, t_maze *data, int idx_cell)
{
  carve(data, idx_cell, &frontier);
  while (frontier != NULL)
    {
      idx_cell = pick_rand(&frontier, data);
      if (check_neighbour(idx_cell, data) == 1)
        {
          carve(data, idx_cell, &frontier);
        }
      else
        {
          data->maze[idx_cell] = WALL;
        }
      frontier = free_maillon(frontier, idx_cell);
      data->front_len -= 1;
    }
}
