/*
** prepare_tunnels.c for  in /home/Zarkkos/Delivery/CProg_Elem/CPE_2016_Lemin/src
**
** Made by Antoine Duez
** Login   <antoine.duez@epitech.net>
**
** Started on  Sun Apr 30 19:51:02 2017 Antoine Duez
** Last update Sun Apr 30 21:30:32 2017 Vincent Roye
*/

#include <stdlib.h>
#include <stdio.h>
#include "lemin.h"
#include "my.h"

t_map		**prepare_rooms(t_rooms *tmp_data)
{
  t_map		**rooms;
  t_rooms	*tmp;
  int		i;
  int		j;

  j = 0;
  i = 0;
  tmp = tmp_data;
  while (tmp != NULL)
    {
      tmp = tmp->next;
      i++;
    }
  rooms = malloc(sizeof(t_map *) * (i + 1));
  if (rooms == NULL)
    return (NULL);
  while (j < i)
    {
      rooms[j] = malloc(sizeof(t_map));
      if (rooms[j] == NULL)
	return (NULL);
      j++;
    }
  rooms[i] = NULL;
  return (rooms);
}

t_map		**stock_struct_address(t_map **rooms)
{
  int		i;
  t_map		*block;

  i = 0;
  while (rooms[i] != NULL)
    {
      block = malloc(sizeof(t_map));
      if (!block)
	return (NULL);
      rooms[i] = block;
      i++;
    }
  return (rooms);
}

int		fill_datamap(t_map **rooms, t_rooms *tmp_data)
{
  t_rooms	*tmp;
  t_map		*block;
  int		i;

  tmp = tmp_data;
  i = 0;
  while (rooms[i] != NULL)
    {
      block = rooms[i];
      if (!block)
	return (-1);
      block->data.name = tmp->data->name;
      block->data.x = tmp->data->x;
      block->data.y = tmp->data->y;
      block->data.pos = tmp->data->pos;
      i++;
      tmp = tmp->next;
    }
  return (0);
}

int	tunnel_counter(char **tunnels)
{
  int	i;

  i = 0;
  if (tunnels == NULL)
    return (0);
  while (tunnels[i] != NULL)
    i++;
  return (i);
}
