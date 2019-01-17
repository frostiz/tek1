/*
** next_cell.c for next_cell.c in /home/roye_v/delivery/dante/astar
** 
** Made by Vincent Roye
** Login   <roye_v@epitech.net>
** 
** Started on  Sun May 14 15:57:07 2017 Vincent Roye
** Last update Sun May 14 22:20:43 2017 Vincent Roye
*/

#include	<stdlib.h>
#include	"astar.h"

static t_cell	*north(t_cell *save_cell, t_pos *pos, t_coord coord)
{
  t_coord	tmp;

  tmp.x = pos->line - 1;
  tmp.y = pos->col;
  pos->maze[pos->line - 1][pos->col] = 'S';
  save_cell = addlist(save_cell, pos->maze, tmp, coord.f_cost);
  return (save_cell);
}

static t_cell	*right(t_cell *save_cell, t_pos *pos, t_coord coord)
{
  t_coord	tmp;

  tmp.x = pos->line;
  tmp.y = pos->col + 1;
  pos->maze[pos->line][pos->col + 1] = 'L';
  save_cell = addlist(save_cell, pos->maze, tmp, coord.f_cost);
  return (save_cell);
}

static t_cell	*south(t_cell *save_cell, t_pos *pos, t_coord coord)
{
  t_coord	tmp;

  tmp.x = pos->line + 1;
  tmp.y = pos->col;
  pos->maze[pos->line + 1][pos->col] = 'N';
  save_cell = addlist(save_cell, pos->maze, tmp, coord.f_cost);
  return (save_cell);
}

static t_cell	*left(t_cell *save_cell, t_pos *pos, t_coord coord)
{
  t_coord	tmp;

  tmp.x = pos->line;
  tmp.y = pos->col - 1;
  pos->maze[pos->line][pos->col - 1] = 'R';
  save_cell = addlist(save_cell, pos->maze, tmp, coord.f_cost);
  return (save_cell);
}

t_cell		*next_cell(t_cell *save_cell,
			   t_pos *pos, t_coord coord)
{
  if (pos->line > 0)
    {
      if (pos->maze[pos->line - 1][pos->col] == '*')
	save_cell = north(save_cell, pos, coord);
    }
  if (pos->maze[pos->line][pos->col] != '\0')
    {
      if (pos->maze[pos->line][pos->col + 1] == '*')
	save_cell = right(save_cell, pos, coord);
    }
  if (pos->maze[pos->line + 1] != NULL)
    {
      if (pos->maze[pos->line + 1][pos->col] == '*')
	save_cell = south(save_cell, pos, coord);
    }
  if (pos->col > 0)
    {
      if (pos->maze[pos->line][pos->col - 1] == '*')
	save_cell = left(save_cell, pos, coord);
    }
  return (save_cell);
}
