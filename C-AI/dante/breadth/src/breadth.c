/*
** breadth.c for breadth.c in /home/roye_v/delivery/maze_solver
** 
** Made by Vincent Roye
** Login   <roye_v@epitech.net>
** 
** Started on  Thu May 11 21:04:03 2017 Vincent Roye
** Last update Sat May 13 03:49:44 2017 Vincent Roye
*/

#include	<stdlib.h>
#include	"breadth.h"

int		check_neighbours(t_pos *pos, t_list *list,
				 t_coord *maze, char **map)
{
  if ((east(pos, list, maze, map) == 1))
    return (1);
  else if ((north(pos, list, maze, map) == 1))
    return (1);
  else if ((south(pos, list, maze, map) == 1))
    return (1);
  else if ((west(pos, list, maze, map) == 1))
    return (1);
  return (0);
}

t_pos		*delete_pos(t_list *list, t_pos *pos)
{
  t_pos		*tmp;

  tmp = pos;
  if (tmp->prev)
    tmp->prev->next = tmp->next;
  else
    list->first = tmp->next;
  if (tmp->next)
    tmp->next->prev = tmp->prev;
  else
    list->last = tmp->prev;
  tmp = tmp->next;
  return (tmp);
}

static void	new_path(t_pile *list, char **map)
{
  t_pile	*tmp;

  tmp = list;
  while (tmp != NULL)
    {
      if (map[tmp->x][tmp->y] != '\0')
	map[tmp->x][tmp->y] = 'O';
      tmp = tmp->prev;
    }
}

char		**breadth(t_list *list, t_coord *maze, char **stock)
{
  t_pos		*pos;

  pos = NULL;
  stock[0][0] = 'O';
  new_pile(pos, list, 0, 0);
  pos = list->first;
  while (pos != NULL)
    {
      stock[pos->x][pos->y] = '1';
      if ((check_neighbours(pos, list, maze, stock)) == 0)
	pos = delete_pos(list, pos);
      if (pos && pos->x == maze->height - 1 && pos->y == maze->width - 1)
	{
	  new_path(pos->pile, stock);
	  return (stock);
	}
      if (pos != NULL)
	{
	  stock[pos->x][pos->y] = '1';
	  pos = pos->next;
	}
      if (pos == NULL)
	pos = list->first;
    }
  return (NULL);
}
