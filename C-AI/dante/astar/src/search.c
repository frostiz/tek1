/*
** search.c for search.c in /home/roye_v/delivery/dante/astar
** 
** Made by Vincent Roye
** Login   <roye_v@epitech.net>
** 
** Started on  Sun May 14 20:27:13 2017 Vincent Roye
** Last update Sun May 14 22:22:18 2017 Vincent Roye
*/

#include	<stdio.h>
#include	<stdlib.h>
#include	"astar.h"

int		how_many_link(char **maze, int line,
			      int col)
{
  int		link;

  link = 0;
  if (line > 0)
    if (maze[line - 1][col] == '*')
      link++;
  if (maze[line][col] != '\0')
    if (maze[line][col + 1] == '*')
      link++;
  if (maze[line + 1] != NULL)
    if (maze[line + 1][col] == '*')
      link++;
  if (col > 0)
    if (maze[line][col - 1] == '*')
      link++;
  return (link);
}

int		search_closest_end(char **maze, int col, int line)
{
  int		result;
  int		save_col;
  int		save_line;

  save_line = 0;
  save_col = 0;
  if (line > array_len(maze))
    exit(84);
  if (maze[line] != NULL)
    {
      while (maze[line][col] != '\0')
	{
	  save_col++;
	  col++;
	}
    }
  while (maze[line] != NULL)
    {
      save_line++;
      line++;
    }
  result = save_col + save_line - 2;
  return (result);
}

int	array_len(char **stock)
{
  int	line;

  line = 0;
  while (stock[line] != NULL)
    line++;
  return (line);
}

t_coord		next_min(t_cell *list)
{
  t_cell	*tmp;
  t_coord	coord;

  tmp = list;
  coord.x = tmp->cell[0];
  coord.y = tmp->cell[1];
  coord.f_cost = tmp->f_cost;
  return (coord);
}

t_coord		new_coord(t_cell *list, char **maze,
			  int f_line, int f_col)
{
  t_cell	*tmp;
  t_coord	coord;

  (void)f_line;
  (void)f_col;
  tmp = list;
  while (tmp != NULL)
    {
      if (how_many_link(maze, tmp->cell[0], tmp->cell[1]) != 0)
	{
	  coord.x = tmp->cell[0];
	  coord.y = tmp->cell[1];
	  coord.f_cost = tmp->f_cost;
	  return (coord);
	}
      tmp = tmp->next;
    }
  fprintf(stderr, "No path found.\n");
  exit(84);
  return (coord);
}
