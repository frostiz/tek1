/*
** mapping.c for  in /home/Zarkkos/Delivery/CProg_Elem/CPE_2016_Lemin/src
**
** Made by Antoine Duez
** Login   <Zarkkos@epitech.net>
**
** Started on  Wed Apr 19 17:42:03 2017 Antoine Duez
** Last update Sun Apr 30 21:52:00 2017 Thibaut Trouvé
*/

#include <stdlib.h>
#include <stdio.h>
#include "lemin.h"
#include "my.h"

int	new_tunnels_loop(t_map **rooms, t_map *block, char **tunnels, int i)
{
  t_map	*tmp;
  int	j;

  j = 0;
  tmp = rooms[0];
  block->link.link_name[i] = tunnels[i];
  while (my_strcmp(tunnels[i], tmp->data.name) != 0)
    {
      j++;
      if (rooms[j] != NULL)
	tmp = rooms[j];
      else
	return (-1);
    }
  block->link.link_address[i] = tmp;
  return (0);
}

int	add_new_tunnels(t_map **rooms, t_map *block, char **tunnels)
{
  int	i;

  i = 0;
  if (tunnels == NULL)
    return (-1);
  block->link.link_name = malloc(sizeof(char *) *
				 (tunnel_counter(tunnels) + 1));
  if (block->link.link_name == NULL)
    return (-1);
  block->link.link_address = malloc(sizeof(t_map *) *
  				    (tunnel_counter(tunnels) + 1));
  if (block->link.link_address == NULL)
    return (-1);
  while (tunnels[i] != NULL)
    {
      if (new_tunnels_loop(rooms, block, tunnels, i) == -1)
	return (-1);
      i++;
    }
  block->link.link_name[i] = NULL;
  block->link.link_address[i] = NULL;
  return (0);
}

int		set_tunnels(t_map **rooms, t_rooms *tmp_data)
{
  int		j;
  t_rooms	*tmp;

  tmp = tmp_data;
  j = 0;
  while (rooms[j] != NULL)
    {
      if (add_new_tunnels(rooms, (t_map *)rooms[j], tmp->tunnel) == -1)
	return (-1);
      j++;
      tmp = tmp->next;
    }
  return (0);
}

t_map		*get_first_block(t_map **rooms)
{
  int		i;

  i = 0;
  while (rooms[i] != NULL)
    {
      if (rooms[i]->data.pos == START)
	return (rooms[i]);
      i++;
    }
  return (NULL);
}

t_map		*mapping(t_rooms *tmp_data)
{
  t_map		**rooms;
  t_map		*block;

  if (tmp_data == NULL)
    return (NULL);
  rooms = NULL;
  rooms = prepare_rooms(tmp_data);
  if (!rooms)
    return (NULL);
  rooms = stock_struct_address(rooms);
  if (!rooms)
    return (NULL);
  if (fill_datamap(rooms, tmp_data) == -1)
    return (NULL);
  if (set_tunnels(rooms, tmp_data) == -1)
    return (NULL);
  block = get_first_block(rooms);
  return (block);
}
