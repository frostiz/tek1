/*
** tunnel.c for tunnel.c in /home/roye_v/delivery/CPE_2016/CPE_2016_Lemin
** 
** Made by Vincent Roye
** Login   <roye_v@epitech.net>
** 
** Started on  Wed Apr 19 19:53:30 2017 Vincent Roye
** Last update Sun Apr 30 16:00:53 2017 dubret_v
*/

#include <stdio.h>
#include <stdlib.h>
#include "lemin.h"
#include "tunnel.h"
#include "my.h"

int	max_str_size(char **stock)
{
  int	i;
  int	line;
  int	max;

  max = 0;
  i = 0;
  line = 0;
  while (stock[line] != NULL)
    {
      while (stock[line][i] != '\0')
	{
	  i++;
	}
      if (i > max)
	max = i;
      i = 0;
      line++;
    }
  return (max);
}

int	count_room(char **stock, int line, char **tmp)
{
  int	i;
  int	j;

  i = 0;
  j = 0;
  while (stock[line] != NULL)
    {
      i++;
      line++;
    }
  while (j < i)
    {
      tmp[j] = malloc(sizeof(char) * max_str_size(stock));
      if (tmp[j] == NULL)
	return (-1);
      tmp[j] = NULL;
      j++;
    }
  return (0);
}

int	check_double_link(char **stock, char *tunnel, int array_end)
{
  int	line;

  line = 0;
  while (line < array_end)
    {
      if (my_strcmp(stock[line], tunnel) == 0)
	return (1);
      line++;
    }
  return (0);
}
