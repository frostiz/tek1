/*
** astar.c for astar.c in /home/roye_v/delivery/dante/solver
** 
** Made by Vincent Roye
** Login   <roye_v@epitech.net>
** 
** Started on  Sun May  7 23:39:42 2017 Vincent Roye
** Last update Sun May 14 22:44:25 2017 Vincent Roye
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "astar.h"

int		check_end(t_cell *list, int f_line, int f_col)
{
  t_cell	*tmp;

  tmp = list;
  while (tmp != NULL)
    {
      if (tmp->cell[0] == f_line && tmp->cell[1] == f_col)
	return (0);
      tmp = tmp->next;
    }
  return (1);
}

static void	init_values(t_pos *pos, t_coord *coord,
			    t_final *final)
{
  pos->line = 0;
  pos->col = 0;
  final->f_col = strlen(pos->maze[0]) - 1;
  final->f_line = array_len(pos->maze) - 1;
  coord->x = 0;
  coord->y = 0;
  coord->f_cost = final->f_col + final->f_line;
  pos->maze[0][0] = 'o';
}

static int	check_finish(t_cell *list, int f_line,
			     int f_col, t_pos *pos)
{
  if (check_end(list, f_line, f_col) == 0)
    {
      print_final_tab(pos->maze, f_line, f_col);
      exit(0);
    }
  return (0);
}

void	get_new_link(t_coord coord, t_cell *list,
		     t_pos *pos, t_final *final)
{
  coord = new_coord(list, pos->maze,
		    final->f_line, final->f_col);
  pos->line = coord.x;
  pos->col = coord.y;
}

int		astar(t_pos *pos)
{
  t_cell	*list;
  t_coord	coord;
  t_final	final;
  int		finish;

  finish = 0;
  init_values(pos, &coord, &final);
  list = malloc(sizeof(t_cell));
  if (list == NULL)
    exit(84);
  list = NULL;
  while (finish != 2)
    {
      list = next_cell(list, pos, coord);
      coord = next_min(list);
      pos->line = coord.x;
      pos->col = coord.y;
      if (how_many_link(pos->maze, pos->line, pos->col) == 0)
	get_new_link(coord, list, pos, &final);
      if (pos->maze[final.f_line][final.f_col] != '*')
	finish++;
      if (finish == 2)
	check_finish(list, final.f_line, final.f_col, pos);
    }
  return (0);
}
