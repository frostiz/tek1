/*
** list.c for dante in /home/thibaut/Repository/dante/generator
** 
** Made by Thibaut Trouvé
** Login   <thibaut.trouve@epitech.eu>
** 
** Started on  Sun May 14 20:35:33 2017 Thibaut Trouvé
** Last update Sun May 14 20:54:37 2017 Thibaut Trouvé
*/

#include <stdlib.h>
#include "generator.h"

int	coord_len(t_coord *frontier)
{
  t_coord	*tmp;
  int		i;

  i = 0;
  tmp = frontier;
  while (tmp != NULL)
    {
      tmp = tmp->next;
      i++;
    }
  return (i);
}

int		pick_rand(t_coord **frontier, t_maze *data)
{
  t_coord	*tmp;
  int		random;
  int		i;

  i = 0;
  tmp = *frontier;
  random = rand() % data->front_len - 1;
  while (random >= 0 && tmp && i < 10)
    {
      tmp = tmp->next;
      random--;
      i++;
    }
  return (tmp->idx);
}

t_coord		*free_maillon(t_coord *frontier, int idx_cell)
{
  t_coord	*tmp;
  t_coord	*prev;

  if (frontier == NULL)
    return (frontier);
  prev = frontier;
  if (prev->idx == idx_cell)
    {
      frontier = prev->next;
      free(prev);
      return frontier;
    }
  tmp = prev->next;
  while (tmp != NULL)
    {
      if (tmp->idx == idx_cell)
	{
	  prev->next = tmp->next;
	  free(tmp);
	  return (frontier);
	}
      prev = tmp;
      tmp = tmp->next;
    }
  return (frontier);
}

void		add_frontier(t_coord **frontier, int idx_cell)
{
  t_coord	*new;

  new = malloc(sizeof(t_coord));
  if (new == NULL)
    return ;
  new->idx = idx_cell;
  if (*frontier != NULL)
    new->next = *frontier;
  else
    new->next = NULL;
  *frontier = new;
}
