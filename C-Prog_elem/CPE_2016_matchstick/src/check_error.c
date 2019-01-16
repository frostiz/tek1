/*
** check_error.c for matchstick in /home/thibaut/Repository/CPE_2016_matchstick
** 
** Made by 
** Login   <thibaut.trouve@epitech.eu>
** 
** Started on  Sun Feb 26 14:27:29 2017 
** Last update Sun Feb 26 17:24:28 2017 
*/

#include "my.h"

static int	is_number(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] < '0' || str[i] > '9')
	return (0);
      i++;
    }
  if (i > 0)
    return (1);
  else
    return (0);
}

int	check_input_line_error(char *input_line, char **map, int nb_line_max)
{
  if (input_line == NULL)
    return (2);
  if (is_number(input_line) == 0)
    {
      my_putstr("Error: invalid input (positive number expected)\n");
      return (0);
    }
  if (my_getnbr(input_line) > nb_line_max || my_getnbr(input_line) <= 0)
    {
      my_putstr("Error: this line is out of range\n");
      return (0);
    }
  return (1);
}

int	check_input_nb_stick_error(char *input_nb_stick,
				   t_map2 info, char *line)
{
  if (input_nb_stick == NULL)
    return (2);
  if (is_number(input_nb_stick) == 0 && my_getnbr(input_nb_stick) <= 0)
    {
      my_putstr("Error: invalid input (positive number expected)\n");
      return (0);
    }
  if (my_getnbr(input_nb_stick) > info.del_max)
    {
      my_putstr("Error: you cannot remove more than ");
      my_put_nbr(info.del_max);
      my_putstr(" matches per turn\n");
      return (0);
    }
  if (my_getnbr(input_nb_stick) > next_space(info.map[my_getnbr(line) - 1]))
    {
      my_putstr("Error: not enough matches on this line\n");
      return (0);
    }
  if (my_getnbr(input_nb_stick) <= 0)
    {
      my_putstr("Error: you have to remove at least one match\n");
      return (0);
    }
  return (1);
}
