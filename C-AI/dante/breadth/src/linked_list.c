/*
** linked_list.c for linked_list.c in /home/roye_v/delivery/maze_solver
** 
** Made by Vincent Roye
** Login   <roye_v@epitech.net>
** 
** Started on  Thu May 11 22:29:01 2017 Vincent Roye
** Last update Sun May 14 20:24:58 2017 Vincent Roye
*/

#include	<stdio.h>
#include	<stdlib.h>
#include	"breadth.h"

static void	exit_error()
{
  fprintf(stderr, "Error while allocating memory.\n");
  exit(84);
}

void		add_new_cell(t_pile **list, int x, int y)
{
  t_pile	*tmp;

  if ((tmp = malloc(sizeof(t_pile))) == NULL)
    exit_error();
  if (tmp != NULL)
    {
      tmp->x = x;
      tmp->y = y;
      tmp->prev = (*list);
      (*list) = tmp;
    }
}

void		new_pile(t_pos *pos, t_list *list, int x, int y)
{
  t_pos		*tmp;

  tmp = malloc(sizeof(t_pos));
  if (tmp == NULL)
    exit_error();
  tmp->pile = malloc(sizeof(t_pos));
  if (tmp->pile == NULL)
    exit_error();
  tmp->pile->prev = NULL;
  if (pos)
    tmp->pile = pos->pile;
  else
    tmp->pile = NULL;
  tmp->x = x;
  tmp->y = y;
  tmp->from_x = x;
  tmp->from_y = y;
  add_new_cell(&tmp->pile, x, y);
  tmp->next = list->first;
  tmp->prev = NULL;
  if (list->first)
    list->first->prev = tmp;
  else
    list->last = tmp;
  list->first = tmp;
}
