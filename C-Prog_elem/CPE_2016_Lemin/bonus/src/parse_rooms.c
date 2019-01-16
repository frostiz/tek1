/*
** parse_rooms.c for lemin in /home/thibaut/Repository/CPE_2016_Lemin
** 
** Made by Thibaut Trouvé
** Login   <thibaut.trouve@epitech.eu>
** 
** Started on  Sat Apr 29 19:50:06 2017 Thibaut Trouvé
** Last update Sun Apr 30 23:37:21 2017 Vincent Roye
*/

#include <stdlib.h>
#include "lemin.h"
#include "my.h"

t_rooms		*add_rooms(t_rooms *rooms, t_dataroom *data)
{
  t_rooms	*new;

  new = malloc(sizeof(t_rooms));
  if (new == NULL)
    return (NULL);
  new->data = data;
  if (rooms == NULL)
    new->next = NULL;
  else
    new->next = rooms;
  new->tunnel = NULL;
  return (new);
}

t_rooms		*get_name_coord(t_rooms *rooms, char **stock, int *idx)
{
  t_dataroom	*data;

  (*idx)++;
  data = get_data(stock, idx);
  while (data != NULL)
    {
      rooms = add_rooms(rooms, data);
      data = get_data(stock, idx);
    }
  return (rooms);
}

t_rooms		*parse_rooms(t_rooms *rooms, char **stock, int *idx)
{
  my_printf("#rooms\n");
  rooms = get_name_coord(rooms, stock, idx);
  if (rooms == NULL)
    return (NULL);
  if (display_rooms(rooms) == -1)
    return (NULL);
  if (check_room_error(rooms) == 1)
    return (NULL);
  return (rooms);
}
