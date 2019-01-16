/*
** check_errors.c for lemin in /home/thibaut/Repository/CPE_2016_Lemin
** 
** Made by Thibaut Trouvé
** Login   <thibaut.trouve@epitech.eu>
** 
** Started on  Sat Apr 22 19:06:51 2017 Thibaut Trouvé
** Last update Sun Apr 30 21:42:13 2017 dubret_v
*/

#include <stdio.h>
#include <stdlib.h>
#include "lemin.h"
#include "my.h"

static int	check_pos(t_rooms *tmp, int pos)
{
  int	is_pos;

  is_pos = 0;
  while (tmp != NULL)
    {
      if (tmp->data->pos == pos)
	is_pos = 1;
      tmp = tmp->next;
    }
  if (is_pos == 0)
    return (-1);
  return (0);
}

static int	check_exist(t_rooms *tmp, char *to)
{
  int		ok;

  ok = 0;
  while (tmp != NULL)
    {
      if (my_strcmp(to, tmp->data->name) == 0)
	ok = 1;
      tmp = tmp->next;
    }
  if (ok == 0)
    return (-1);
  return (0);
}

static int	check_tunnels_err(t_rooms *tmp)
{
  t_rooms *tmp_tmp;
  int	i;

  tmp_tmp = tmp;
  while (tmp != NULL)
    {
      i = 0;
      while (tmp->tunnel[i] != NULL)
	{
	  if (check_exist(tmp_tmp, tmp->tunnel[i]) == -1)
	    return (-1);
	  i++;
	}
      tmp = tmp->next;
    }
  return (0);
}

static	int	pos_and_tunnels(t_rooms *rooms)
{
  t_rooms	*tmp;

  tmp = rooms;
  if (check_pos(tmp, START) == -1)
    {
      my_put_error("Start not found\n");
      return (-1);
    }
  tmp = rooms;
  if (check_tunnels_err(tmp) == -1)
    {
      my_put_error("Error with tunnels\n");
      return (-1);
    }
  return (0);
}

int		check_errors(t_rooms *rooms, int nb_fourmi)
{
  t_rooms	*tmp;

  if (nb_fourmi <= 0)
    {
      my_put_error("Number of ants less or equal to 0.\n");
      return (-1);
    }
  tmp = rooms;
  if (check_pos(tmp, END) == -1)
    {
      my_put_error("End not found\n");
      return (-1);
    }
  if (pos_and_tunnels(rooms) == -1)
    return (-1);
  return (0);
}
