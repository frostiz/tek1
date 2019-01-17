/*
** check_around.c for depth in /home/thibaut/Repository/dante/depth
** 
** Made by Thibaut Trouvé
** Login   <thibaut.trouve@epitech.eu>
** 
** Started on  Sun May 14 19:14:11 2017 Thibaut Trouvé
** Last update Sun May 14 19:20:40 2017 Thibaut Trouvé
*/

#include "depth.h"

static void init_cardinal(int *north, int *east, int *south, t_maze *data)
{
  *north = data->idx - data->width;
  *east = data->idx + 1;
  *south = data->idx + data->width;
}

static void init_border(int *max, int *left_border,
			int *right_border, t_maze *data)
{
  *max = data->width * data->height - 1;
  *left_border = data->idx - (data->idx % data->width);
  *right_border = data->idx + (data->width - data->idx % data->width) - 1;
}

int	check_around(t_maze *data, int idx)
{
  int	around;
  int	north;
  int	east;
  int	south;
  int	west;
  int	max;
  int	left_border;
  int	right_border;

  init_cardinal(&north, &east, &south, data);
  west = data->idx - 1;
  init_border(&max, &left_border, &right_border, data);
  data->str[idx] |= VISITED;
  around = 0;
  if (north >= 0 && !(data->str[north] & VISITED))
    around |= NORTH;
  if (east <= right_border && !(data->str[east] & VISITED))
    around |= EAST;
  if (south <= max && !(data->str[south] & VISITED))
    around |= SOUTH;
  if (west >= left_border && !(data->str[west] & VISITED))
    around |= WEST;
  return (around);
}
