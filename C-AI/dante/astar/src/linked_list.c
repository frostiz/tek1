/*
** linked_list.c for linked_list.c in /home/roye_v/delivery/PSU_2016/PSU_2016_minishell2
** 
** Made by Vincent Roye
** Login   <roye_v@epitech.net>
** 
** Started on  Sun Apr  9 23:06:06 2017 Vincent Roye
** Last update Sun May 14 16:20:17 2017 Vincent Roye
*/

#include	<stdlib.h>
#include	<stdio.h>
#include	"astar.h"

t_cell		*rm_list(t_cell *list)
{
  t_cell	*tmp;

  if (list == NULL)
    return (NULL);
  tmp = list->next;
  free(list);
  return (tmp);
}

t_cell		*addlist(t_cell *list, char **maze,
			 t_coord coord, int f_cost)
{
  t_cell	*new_elem;
  t_cell	*tmp;

  new_elem = malloc(sizeof(t_cell));
  tmp = list;
  new_elem->cell[0] = coord.x;
  new_elem->cell[1] = coord.y;
  new_elem->to_base = coord.x + coord.y;
  new_elem->to_end = search_closest_end(maze, coord.x, coord.y);
  new_elem->f_cost = new_elem->to_base + new_elem->to_end;
  new_elem->next = NULL;
  if (list == NULL)
    return (new_elem);
  else
    {
      while (tmp->f_cost < f_cost && tmp->next != NULL)
	tmp = tmp->next;
      new_elem->next = tmp->next;
      tmp->next = new_elem;
      return (list);
    }
}

void		display_list(t_cell *list)
{
  t_cell	*tmp;
  int		i;

  i = 0;
  tmp = list;
  while (tmp != NULL)
    {
      printf("cell[%d] =\n", i);
      printf("x = %d\n", tmp->cell[0]);
      printf("y = %d\n", tmp->cell[1]);
      printf("base = %d\n", tmp->to_base);
      printf("end = %d\n", tmp->to_end);
      printf("f_cost = %d\n", tmp->f_cost);
      tmp = tmp->next;
      i++;
    }
}
