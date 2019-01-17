/*
** imperfect.c for imperfect in /home/thibaut/Repository/dante/generator
** 
** Made by Thibaut Trouvé
** Login   <thibaut.trouve@epitech.eu>
** 
** Started on  Sat May 13 22:24:53 2017 Thibaut Trouvé
** Last update Sun May 14 20:51:05 2017 Thibaut Trouvé
*/

#include <time.h>
#include <stdlib.h>
#include "generator.h"

static void	destroy_walls(t_maze *data)
{
  int	destroy;
  int	i;

  destroy = data->width * data->height * 5 / 100;
  i = data->width * data->height / 2;
  while (destroy > 0 && i < data->width * data->height)
    {
      while (data->maze[i] != WALL)
	i++;
      if (rand() % 2 == 0)
	{
	  data->maze[i] = VOID;
	  destroy--;
	}
    }
}

int	imperfect(t_maze *data)
{
  t_coord	*frontier;
  int		idx_cell;
  static int	a = 0;

  srand(time(NULL) + a);
  a++;
  frontier = malloc(sizeof(t_coord));
  if (frontier == NULL)
    return (84);
  frontier = NULL;
  idx_cell = 0;
  mainloop(frontier, data, idx_cell);
  if (treat_all(data) == -1)
    return (-1);
  destroy_walls(data);
  display_lab(data);
  return (0);
}

