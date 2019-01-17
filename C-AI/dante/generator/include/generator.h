/*
** main.h for dante in /home/thibaut/Repository/dante/include
** 
** Made by Thibaut Trouvé
** Login   <thibaut.trouve@epitech.eu>
** 
** Started on  Sun Apr 23 17:07:42 2017 Thibaut Trouvé
** Last update Sun May 14 21:01:49 2017 Thibaut Trouvé
*/

#ifndef GENERATOR_H_
# define GENERATOR_H_

# define NOT_TREATED '?'
# define FRONT ','
# define VOID '*'
# define WALL 'X'
# define BUFF_SIZE 2097152

typedef struct  s_maze
{
  int		width;
  int		height;
  int		front_len;
  char		*maze;
}		t_maze;

typedef struct	s_coord
{
  struct s_coord	*next;
  int			idx;
}		t_coord;

void		add_frontier(t_coord **, int);
void		check_around(t_maze *, int, t_coord **);
void		carve(t_maze *, int, t_coord **);
int		coord_len(t_coord *);
int		pick_rand(t_coord **, t_maze *);
int		check_neighbour(int , t_maze *);
void		display_lab(t_maze *);
int		perfect_maze(t_maze *);
int		imperfect(t_maze *);
t_coord		*free_maillon(t_coord *, int);
void		mainloop(t_coord *, t_maze *, int);
int		treat_all(t_maze *);

#endif /* GENERATOR_H_ */
