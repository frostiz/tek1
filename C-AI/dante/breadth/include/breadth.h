/*
** my.h for breadth.h in /home/roye_v/delivery/maze_solver
** 
** Made by Vincent Roye
** Login   <roye_v@epitech.net>
** 
** Started on  Thu May 11 19:33:48 2017 Vincent Roye
** Last update Sun May 14 22:50:55 2017 Vincent Roye
*/

#ifndef BREADTH_H_
# define BREADTH_H_
# define NORTH 1
# define SOUTH 2
# define WEST 3
# define EAST 4

typedef struct	s_pile
{
  struct s_pile	*prev;
  int		x;
  int		y;
}		t_pile;

typedef struct	s_pos
{
  struct s_pos	*prev;
  struct s_pos	*next;
  int		from_x;
  int		from_y;
  int		x;
  int		y;
  t_pile	*pile;
}		t_pos;

typedef struct	s_list
{
  t_pos		*first;
  t_pos		*last;
}		t_list;

typedef struct	s_coord
{
  int		height;
  int		width;
}		t_coord;

void		add_new_cell(t_pile **, int, int);
void		new_pile(t_pos *, t_list *, int, int);
int		west(t_pos *, t_list *, t_coord *, char **);
int		east(t_pos *, t_list *, t_coord *, char **);
int		south(t_pos *, t_list *, t_coord *, char **);
int		north(t_pos *, t_list *, t_coord *, char **);
int		check_error(char **, t_coord *);
char		**stock_file(char *, t_coord *);
char		**breadth(t_list *, t_coord *, char **);
int		array_len(char **);
int		check_neighbours(t_pos *, t_list *,
				 t_coord *, char **);

#endif /* !BREADTH_H_ */
