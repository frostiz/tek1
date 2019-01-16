/*
** get_idx_tunnel.c for get_idx_tunnel.c in /home/roye_v/delivery/CPE_2016/CPE_2016_Lemin
** 
** Made by Vincent Roye
** Login   <roye_v@epitech.net>
** 
** Started on  Sun Apr 30 14:25:20 2017 Vincent Roye
** Last update Sun Apr 30 16:01:23 2017 dubret_v
*/

#include <stdlib.h>
#include "lemin.h"
#include "tunnel.h"
#include "my.h"

static void	init_values(t_idx_tunnel *tunnel)
{
  tunnel->dash = 0;
  tunnel->hashtag = 0;
  tunnel->space = 0;
  tunnel->line = 0;
  tunnel->i = 0;
}

static void	back_to_zero(t_idx_tunnel *tunnel)
{
  tunnel->dash = 0;
  tunnel->space = 0;
  tunnel->hashtag = 0;
  tunnel->i = 0;
  (tunnel->line)++;
}

static int	invalid_map(char **stock, int line)
{
  if (check_invalid_map(stock, line) == 1)
    {
      my_put_error("Invalid Map\n");
      return (-1);
    }
  return (0);
}

int		get_idx_tunnel(char **stock)
{
  t_idx_tunnel	tunnel;

  init_values(&tunnel);
  while (stock[tunnel.line] != NULL)
    {
      while (stock[tunnel.line][tunnel.i] != '\0')
	{
	  if (stock[tunnel.line][tunnel.i] == ' ')
	    tunnel.space++;
	  else if (stock[tunnel.line][tunnel.i] == '#')
	    tunnel.hashtag++;
	  else if (stock[tunnel.line][tunnel.i] == '-')
	    tunnel.dash++;
	  tunnel.i++;
	}
      if (tunnel.space == 0 && tunnel.hashtag == 0 &&
	  tunnel.dash == 1)
	return (tunnel.line);
      back_to_zero(&tunnel);
    }
  if (invalid_map(stock, tunnel.line) == -1)
    return (-1);
  return (-1);
}
