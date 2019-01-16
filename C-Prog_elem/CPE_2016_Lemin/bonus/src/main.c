/*
** main.c for main.c in /home/roye_v/delivery/CPE_2016/CPE_2016_Lemin
**
** Made by Vincent Roye
** Login   <roye_v@epitech.net>
**
** Started on  Sat Apr 29 17:36:44 2017 Vincent Roye
** Last update Sun Apr 30 23:04:57 2017 Vincent Roye
*/

#include <stdio.h>
#include <stdlib.h>
#include "lemin.h"
#include "graph.h"
#include "my.h"

static int	print_invalid_room()
{
  my_put_error("Invalid rooms !\n");
  return (-1);
}

static int	print_invalid_tunnel()
{
  my_put_error("Invalid tunnels !\n");
  return (-1);
}

static int	init_values(int *idx, int *nb_ants, char **stock)
{
  *idx = 0;
  *nb_ants = parse_nb_ants(stock, &*idx);
  if (*nb_ants <= 0)
    return (-1);
  return (0);
}

int		lemin()
{
  t_rooms	*rooms;
  t_map		*graph;
  char		**stock;
  int		idx;
  int		nb_ants;

  if ((stock = copy_file()) == NULL)
    return (-1);
  stock = epure_stock(stock);
  if (init_values(&idx, &nb_ants, stock) == -1)
    return (-1);
  rooms = parse_rooms(NULL, stock, &idx);
  if (rooms == NULL)
    return (print_invalid_room());
  rooms = parse_tunnels(rooms, stock, &idx);
  if (rooms == NULL)
    return (print_invalid_tunnel());
  my_printf("#moves\n");
  if (check_end_tunnel(rooms) == -1)
    return (-1);
  graph = mapping(rooms);
  if (recursive_functions(graph, nb_ants) == -1)
    return (-1);
  print_map(rooms);
  return (0);
}

int	main(void)
{
  if (lemin() == -1)
    return (84);
  return (0);
}
