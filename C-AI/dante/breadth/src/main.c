/*
** main.c for main.c in /home/roye_v/delivery/dante/solver/breadth/test
** 
** Made by Vincent Roye
** Login   <roye_v@epitech.net>
** 
** Started on  Thu May 11 17:44:44 2017 Vincent Roye
** Last update Sun May 14 20:23:55 2017 Vincent Roye
*/

# include	<string.h>
# include	<unistd.h>
# include	<stdlib.h>
# include	<stdio.h>
# include	"breadth.h"

void		print_map(char **map)
{
  t_coord	maze;
  int		k;
  int		i;

  k = 0;
  i = 0;
  maze.height = array_len(map);
  maze.width = (int)strlen(map[0]);
  while (k < maze.height)
    {
      while (i < maze.width)
	{
	  if (map[k][i] == 'X')
	    printf("X");
	  else if (map[k][i] == '1' || map[k][i] == '*')
	    printf("*");
	  else if (map[k][i] == 'O')
	    printf("o");
	  i++;
	}
      k++;
      if (k < maze.height)
	printf("\n");
      i = 0;
    }
}

static void	init_values(t_list *list)
{
  list->first = NULL;
  list->last = NULL;
}

int		main(int ac, char **argv)
{
  t_coord	maze;
  t_list	list;
  char		**map;

  if (ac != 2)
    {
      fprintf(stderr, "Usage: ./breadth [file]\n");
      exit(84);
    }
  map = stock_file(argv[1], &maze);
  init_values(&list);
  map = breadth(&list, &maze, map);
  if (map == NULL)
    {
      fprintf(stderr, "No solution found\n");
      exit(84);
    }
  print_map(map);
  return (0);
}
