/*
** player.c for matchstick in /home/thibaut/Repository/CPE_2016_matchstick
** 
** Made by 
** Login   <thibaut.trouve@epitech.eu>
** 
** Started on  Sun Feb 26 14:45:28 2017 
** Last update Sun Feb 26 17:21:12 2017 
*/

#include "my.h"

void	init_turn(int *error, char *line, char *nbstick)
{
  *error = 0;
  line = NULL;
  nbstick = NULL;
  my_putstr("\nYour turn:\n");
}

int	my_turn(t_map2 info)
{
  char	*line;
  char	*nbstick;
  int	error;

  init_turn(&error, line, nbstick);
  while (error != 1)
    {
      while (error != 1)
	{
	  my_putstr("Line: ");
	  line = get_next_line(0);
	  if ((error = check_input_line_error
	       (line, info.map, info.init_nbline)) == 2)
	    return (1);
	}
      my_putstr("Matches: ");
      nbstick = get_next_line(0);
      if ((error = check_input_nb_stick_error(nbstick, info, line)) == 2)
	return (1);
    }
  delete_stick(line, nbstick, info.map);
  aff_removed(line, nbstick);
  return (0);
}

static void	aff_removed(char *line, char *nb_stick)
{
  my_putstr("Player removed ");
  my_put_nbr(my_getnbr(nb_stick));
  my_putstr(" match(es) from line ");
  my_put_nbr(my_getnbr(line));
  my_putchar('\n');
}

static void	delete_stick(char *input_line,
			     char *input_nb_stick, char **map)
{
  int	del_stick;

  del_stick = my_getnbr(input_nb_stick);
  while (del_stick > 0)
    {
      del_last_elem(my_getnbr(input_line), map);
      del_stick--;
    }
}

void	del_last_elem(int line, char **map)
{
  int	i;

  i = 0;
  if (map[line - 1][0] != ' ')
    {
      while (map[line - 1][i] != ' ' && map[line - 1][i] != '\0')
	{
	  i++;
	}
      map[line - 1][i - 1] = ' ';
    }
  return ;
}
