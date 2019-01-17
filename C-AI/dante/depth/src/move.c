/*
** move.c for depth in /home/thibaut/Repository/dante/depth
** 
** Made by Thibaut Trouvé
** Login   <thibaut.trouve@epitech.eu>
** 
** Started on  Sun May 14 19:26:28 2017 Thibaut Trouvé
** Last update Sun May 14 19:42:25 2017 Thibaut Trouvé
*/

#include <stdio.h>
#include <stdlib.h>
#include "depth.h"

int		backtrack(t_coord **save, t_coord **last, t_maze *data)
{
  t_coord	*tmp;

  while (*last && *save && (*last)->idx != (*save)->idx)
    {
      data->str[(*last)->idx] -= PATH;
      tmp = (*last)->next;
      free(*last);
      *last = tmp;
    }
  if (*save == NULL)
    {
      printf("No path found !\n");
      return (84);
    }
  data->idx = (*save)->idx;
  tmp = (*save)->next;
  free(*save);
  *save = tmp;
  return (0);
}

int	move(int around, t_coord **save, t_maze *data, t_coord **last)
{
  if (around == 0)
    {
      if (backtrack(save, last, data) == 84)
	return (84);
    }
  else if (around == NORTH)
    data->idx = data->idx - data->width;
  else if (around == EAST)
    (data->idx)++;
  else if (around == SOUTH)
    data->idx = data->idx + data->width;
  else if (around == WEST)
    (data->idx)--;
  return (0);
}
