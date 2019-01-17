/*
** perfect_maze.c for perfect_maze in /home/thibaut/Repository/dante
** 
** Made by Thibaut Trouvé
** Login   <thibaut.trouve@epitech.eu>
** 
** Started on  Sun Apr 23 20:31:15 2017 Thibaut Trouvé
** Last update Sun May 14 20:42:24 2017 Thibaut Trouvé
*/

#include <unistd.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include "generator.h"

int	perfect_maze(t_maze *data)
{
  t_coord	*frontier;
  int		idx_cell;
  static int a = 0;

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
  display_lab(data);
  return (0);
}
