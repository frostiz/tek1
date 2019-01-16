/*
** stock_tunnel.c for stock_tunnel.c in /home/roye_v/delivery/CPE_2016/CPE_2016_Lemin
** 
** Made by Vincent Roye
** Login   <roye_v@epitech.net>
** 
** Started on  Sat Apr 22 21:23:58 2017 Vincent Roye
** Last update Sun Apr 30 16:01:43 2017 dubret_v
*/

#include <stdlib.h>
#include "lemin.h"
#include "tunnel.h"
#include "my.h"

int	check_rooms_validity(char **tunnel, t_rooms *rooms)
{
  t_rooms	*tmp;
  int		i;
  int		err[2];

  err[0] = 0;
  err[1] = 0;
  i = 0;
  while (i < 2)
    {
      tmp = rooms;
      while (tmp != NULL)
	{
	  if (my_strcmp(tmp->data->name, tunnel[i]) == 0)
	    {
	      err[i] = 1;
	    }
	  tmp = tmp->next;
	}
      i++;
    }
  if (err[0] == 1 && err[1] == 1)
    return (0);
  return (-1);
}

int	get_idx_error(char **stock, int idx, t_rooms *rooms)
{
  char	**tunnel;

  while (stock[idx] != NULL)
    {
      if (stock[idx][0] != '\0')
	{
	  tunnel = my_tunnel_to_wordtab(stock[idx]);
	  if (tunnel == NULL)
	    return (-1);
	  if (tunnel[1] == NULL)
	    return (idx);
	  if (check_rooms_validity(tunnel, rooms) == -1)
	    return (idx);
	}
      idx++;
    }
  return (idx);
}

static void	check_tunnel(t_stock *link, char *str)
{
  if (my_strcmp(link->tmp[0], str) == 0)
    {
      if (check_double_link(link->tunnel, link->tmp[1], link->i) == 0)
	{
	  link->tunnel[link->i] = link->tmp[1];
	  (link->i)++;
	}
    }
  else if (my_strcmp(link->tmp[1], str) == 0)
    {
      if (check_double_link(link->tunnel, link->tmp[0], link->i) == 0)
	{
	  link->tunnel[link->i] = link->tmp[0];
	  (link->i)++;
	}
    }
}

char	**stock_tunnel2(char **stock, int idx, char *str, int idx_error)
{
  t_stock	link;

  link.i = 0;
  link.tunnel = malloc(sizeof(char *) * (array_len(stock) + 1));
  if (link.tunnel == NULL)
    return (NULL);
  if (idx_error == -1)
    return (NULL);
  while (idx < idx_error && stock[idx])
    {
      link.tmp = my_tunnel_to_wordtab(stock[idx]);
      if (link.tmp == NULL)
	return (NULL);
      if (link.tmp[0] != NULL)
	{
	  check_tunnel(&link, str);
	}
      idx++;
    }
  link.tunnel[link.i] = NULL;
  return (link.tunnel);
}
