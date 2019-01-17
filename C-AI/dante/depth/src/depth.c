/*
** new.c for depth in /home/thibaut/Repository/dante/solver/depth2
** 
** Made by Thibaut Trouvé
** Login   <thibaut.trouve@epitech.eu>
** 
** Started on  Thu May 11 23:32:58 2017 Thibaut Trouvé
** Last update Sun May 14 19:40:08 2017 Thibaut Trouvé
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "depth.h"

int	add_save(t_coord **save, int idx)
{
  t_coord	*new;

  new = malloc(sizeof(t_coord));
  if (new == NULL)
    return (84);
  new->idx = idx;
  new->next = *save;
  *save = new;
  return (0);
}

void	choose_direction(int around, int *idx, t_maze *data)
{
  if (around & EAST && !(data->str[*idx + 1] & VISITED))
    *idx = *idx + 1;
  else if (around & SOUTH && !(data->str[*idx + data->width] & VISITED))
    *idx = *idx + data->width;
  else if (around & WEST && !(data->str[*idx - 1] & VISITED))
    *idx = *idx - 1;
  else if (around & NORTH && !(data->str[*idx - data->width] & VISITED))
    *idx = *idx - data->width;
}

int	mainloop(t_maze *data, int max, t_coord *save, t_coord *last)
{
  int	around;

  around = 0;
  while (data->idx != max - 1)
    {
      around = check_around(data, data->idx);
      if (around == 0 || around == NORTH || around == EAST ||
	  around == SOUTH || around == WEST)
	{
	  if (move(around, &save, data, &last) == 84)
	    return (84);
	}
      else
	{
	  if (add_save(&save, data->idx) == 84)
	    return (84);
	  choose_direction(around, &data->idx, data);
	}
      add_save(&last, data->idx);
    }
  data->str[data->idx] |= VISITED;
  return (0);
}

int	start_algo(t_maze *data)
{
  int		max;
  t_coord	*last;
  t_coord	*save;

  last = malloc(sizeof(t_coord));
  if (last == NULL)
    return (84);
  last = NULL;
  save = malloc(sizeof(t_coord));
  if (save == NULL)
    return (84);
  save = NULL;
  max = data->height * data->width;
  if (mainloop(data, max, save, last) == 84)
    return (84);
  return (0);
}

int	depth(char *filename)
{
  t_maze	*data;

  data = malloc(sizeof(t_maze));
  if (data == NULL)
    return (84);
  data->height = 0;
  data->width = 0;
  data->idx = 0;
  if (get_data(filename, data) == 84)
    return (84);
  if (check_errors(data) == 84)
    return (84);
  if (start_algo(data) == 84)
    return (84);
  display_lab(data);
  return (0);
}
