/*
** check_neighbour.c for dante in /home/thibaut/Repository/dante/generator/src
** 
** Made by Thibaut Trouvé
** Login   <thibaut.trouve@epitech.eu>
** 
** Started on  Sun May 14 20:22:33 2017 Thibaut Trouvé
** Last update Sun May 14 20:52:27 2017 Thibaut Trouvé
*/

#include "generator.h"

static int	interpret_stat(int *stat, int west,
			       int left_border, t_maze *data)
{
  if (west >= left_border && data->maze[west] == VOID)
    (*stat) += 8;
  if (*stat == 1 || *stat == 2 || *stat == 4 || *stat == 8)
    return (1);
  return (0);
}

int	check_neighbour(int idx_cell, t_maze *data)
{
  int		north;
  int		east;
  int		south;
  int		west;
  int		max;
  int		left_border;
  int		right_border;
  int		stat;

  stat = 0;
  north = idx_cell - data->width;
  east = idx_cell + 1;
  south = idx_cell + data->width;
  west = idx_cell - 1;
  max = (data->width * data->height) - 1;
  left_border = idx_cell - (idx_cell % data->width);
  right_border = idx_cell + (data->width - idx_cell % data->width) - 1;
  if (north >= 0 && data->maze[north] == VOID)
    stat += 1;
  if (east <= right_border && data->maze[east] == VOID)
    stat += 2;
  if (south <= max && data->maze[south] == VOID)
    stat += 4;
  return (interpret_stat(&stat, west, left_border, data) == 1 ? 1 : 0);
}
