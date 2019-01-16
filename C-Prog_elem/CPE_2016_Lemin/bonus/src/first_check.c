/*
** first_check.c for first_check.c in /home/roye_v/delivery/CPE_2016/CPE_2016_Lemin
** 
** Made by Vincent Roye
** Login   <roye_v@epitech.net>
** 
** Started on  Sun Apr 30 17:57:42 2017 Vincent Roye
** Last update Sun Apr 30 18:10:52 2017 Vincent Roye
*/

#include <stdlib.h>
#include "lemin.h"
#include "my.h"

int	check_invalid_map(char **stock, int line_tunnel)
{
  int	i;

  i = 0;
  while (stock[line_tunnel] != NULL)
    {
      while (stock[line_tunnel][i] != '\0')
	{
	  if (stock[line_tunnel][i] == ' ')
	    return (1);
	  i++;
	}
      i = 0;
      line_tunnel++;
    }
  return (0);
}

int	check_end_start(t_rooms *tmp, int *start, int *end)
{
  if (tmp->data->pos == START && *start == 0)
    *start = 1;
  else if (tmp->data->pos == START && *start == 1)
    {
      my_put_error("Multiple start found\n");
      return (-1);
    }
  else if (tmp->data->pos == END && *end == 0)
    *end = 1;
  else if (tmp->data->pos == END && *end == 1)
    {
      my_put_error("Multiple end found\n");
      return (-1);
    }
  return (0);
}
