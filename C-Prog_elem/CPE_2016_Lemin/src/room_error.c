/*
** room_error.c for room_error.c in /home/roye_v/delivery/CPE_2016/CPE_2016_Lemin
** 
** Made by Vincent Roye
** Login   <roye_v@epitech.net>
** 
** Started on  Sat Apr 29 22:55:33 2017 Vincent Roye
** Last update Sun Apr 30 19:14:51 2017 Vincent Roye
*/

#include <stdlib.h>
#include "lemin.h"
#include "my.h"

int		linked_len(t_rooms *rooms)
{
  t_rooms	*tmp;
  int		i;

  i = 0;
  tmp = rooms;
  while (tmp != NULL)
    {
      tmp = tmp->next;
      i++;
    }
  return (i);
}

int		check_room(t_rooms *rooms, char *str, int i)
{
  t_rooms	*tmp;
  int		checker;

  tmp = rooms;
  checker = 0;
  while (tmp != NULL && i >= 0)
    {
      if (my_strcmp(tmp->data->name, str) == 0)
	checker++;
      tmp = tmp->next;
      i--;
    }
  if (checker == 1)
    return (0);
  else
    {
      my_put_error("room appears twice :");
      my_put_error(str);
      my_put_error("\n");
      return (1);
    }
}

int		check_coord(t_rooms *rooms, int x, int y, int i)
{
  t_rooms	*tmp;
  int		occurence;

  occurence = 0;
  tmp = rooms;
  while (tmp != NULL && i >= 0)
    {
      if (tmp->data->x == x && tmp->data->y == y)
	occurence++;
      tmp = tmp->next;
      i--;
    }
  if (occurence == 1)
    return (0);
  else
    {
      my_put_error("Two rooms have the same coordinates !\n");
      return (1);
    }
}

/*int		same_coord(t_rooms *rooms)
{
  t_rooms	*tmp;

  tmp = rooms;
  while (tmp != NULL)
    {
      if (check_coord(rooms, tmp->data->x, tmp->data->y) == 1)
	return (1);
      tmp = tmp->next;
    }
  return (0);
  }*/

int		check_room_error(t_rooms *rooms)
{
  if (linked_len(rooms) == 0)
    {
      my_put_error("No rooms.\n");
      return (1);
    }
  return (0);
}
