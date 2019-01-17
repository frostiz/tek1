/*
** astar.h for astar.h in /home/roye_v/delivery/dante/solver/include
** 
** Made by Vincent Roye
** Login   <roye_v@epitech.net>
** 
** Started on  Tue May  9 13:47:06 2017 Vincent Roye
** Last update Sun May 14 19:46:06 2017 Thibaut Trouvé
*/

#ifndef DEPTH_H_
# define DEPTH_H_

# define NORTH 1
# define EAST 2
# define SOUTH 4
# define WEST 8
# define VISITED 16
# define PATH 32
# define WALL 64

typedef struct		s_coord
{
  struct s_coord	*next;
  int			idx;
}			t_coord;

typedef struct		s_maze
{
  int			width;
  int			height;
  int			idx;
  char			*str;
}			t_maze;

int	check_around(t_maze *, int);
int	move(int, t_coord **, t_maze *, t_coord **);
int	get_data(char *, t_maze *);
int	check_errors(t_maze *);
void	display_lab(t_maze *);
int	depth(char *);

#endif /* DEPTH_H_ */
