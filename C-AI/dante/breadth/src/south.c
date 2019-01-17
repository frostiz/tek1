/*
** south.c for south.c in /home/roye_v/delivery/maze_solver
** 
** Made by Vincent Roye
** Login   <roye_v@epitech.net>
** 
** Started on  Thu May 11 21:32:52 2017 Vincent Roye
** Last update Sun May 14 17:21:25 2017 Vincent Roye
*/

#include	"breadth.h"

static void	add_3(t_pos *pos, t_list *list,
		      char **maze)
{
  new_pile(pos, list, pos->x, pos->y - 1);
  maze[pos->x][pos->y] = '1';
}

static void	add_2(t_pos *pos, t_list *list,
		      char **maze)
{
  new_pile(pos, list, pos->x, pos->y + 1);
  maze[pos->x][pos->y] = '1';
}

static void	add_1(t_pos *pos, t_list *list,
		      char **maze)
{
  new_pile(pos, list, pos->x + 1, pos->y);
  maze[pos->x][pos->y] = '1';
}

int		south(t_pos *pos, t_list *list,
		      t_coord *coord, char **maze)
{
  if ((pos->x - 1) != -1 && maze[pos->x - 1][pos->y] == '*')
    {
      if (((pos->x + 1) != coord->height)
	  && maze[pos->x + 1][pos->y] == '*')
	add_1(pos, list, maze);
      if (((pos->y + 1) != coord->width) && maze[pos->x][pos->y + 1] == '*')
	add_2(pos, list, maze);
      if ((pos->y - 1 != -1) && maze[pos->x][pos->y - 1] == '*')
	add_3(pos, list, maze);
      pos->x -= 1;
      add_new_cell(&pos->pile, pos->x, pos->y);
      return (1);
    }
  return (0);
}
