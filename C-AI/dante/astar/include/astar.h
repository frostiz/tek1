/*
** astar.h for astar.h in /home/roye_v/delivery/dante/solver/include
** 
** Made by Vincent Roye
** Login   <roye_v@epitech.net>
** 
** Started on  Tue May  9 13:47:06 2017 Vincent Roye
** Last update Sun May 14 20:56:44 2017 Vincent Roye
*/

#ifndef ASTAR_H_
# define ASTAR_H_

# define NORTH 1
# define EAST 2
# define SOUTH 3
# define WEST 4

typedef struct          s_cell
{
  struct s_cell         *next;
  int			cell[2];
  int			to_base;
  int			to_end;
  int			f_cost;
}			t_cell;

typedef struct		s_pos
{
  char			**maze;
  int			line;
  int			col;
}			t_pos;

typedef struct		s_final
{
  int			f_line;
  int			f_col;
}			t_final;

typedef struct		s_coord
{
  int			x;
  int			y;
  int			f_cost;
}			t_coord;

int	astar(t_pos *);
int	check_error(char **);
int	search_closest_end(char **, int, int);
int	how_many_link(char **, int, int);
int	search_closest_end(char **, int, int);
int	array_len(char **);
void	print_final_tab(char **, int, int);
t_coord	next_min(t_cell *);
t_coord	new_coord(t_cell *, char **, int, int);
t_cell	*next_cell(t_cell *, t_pos *, t_coord);
t_cell	*addlist(t_cell *, char **, t_coord, int);

#endif /* ASTAR_H_ */
