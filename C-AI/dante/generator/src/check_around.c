/*
** check_around.c for dante in /home/thibaut/Repository/dante/generator
** 
** Made by Thibaut Trouvé
** Login   <thibaut.trouve@epitech.eu>
** 
** Started on  Sun May 14 20:30:26 2017 Thibaut Trouvé
** Last update Sun May 14 20:51:34 2017 Thibaut Trouvé
*/

#include "generator.h"

static void	place_frontier(t_maze *data, t_coord **frontier, int pos)
{
  data->maze[pos] = FRONT;
  add_frontier(frontier, pos);
  data->front_len += 1;
}

void	check_around(t_maze *data, int idx_cell, t_coord **frontier)
{
  int		north;
  int		east;
  int		south;
  int		west;
  int		max;
  int		left_border;
  int		right_border;

  north = idx_cell - data->width;
  east = idx_cell + 1;
  south = idx_cell + data->width;
  west = idx_cell - 1;
  max = (data->width * data->height) - 1;
  left_border = idx_cell - (idx_cell % data->width);
  right_border = idx_cell + (data->width - idx_cell % data->width) - 1;
  if (north >= 0 && data->maze[north] == NOT_TREATED)
    place_frontier(data, frontier, north);
  if (east <= right_border && data->maze[east] == NOT_TREATED)
    place_frontier(data, frontier, east);
  if (south <= max && data->maze[south] == NOT_TREATED)
    place_frontier(data, frontier, south);
  if (west >= left_border && data->maze[west] == NOT_TREATED)
    place_frontier(data, frontier, west);
}
