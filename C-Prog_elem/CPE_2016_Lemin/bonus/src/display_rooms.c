/*
** display_rooms.c for display_rooms.c in /home/roye_v/delivery/CPE_2016/CPE_2016_Lemin
** 
** Made by Vincent Roye
** Login   <roye_v@epitech.net>
** 
** Started on  Sun Apr 30 18:03:10 2017 Vincent Roye
** Last update Sun Apr 30 19:05:44 2017 Vincent Roye
*/

#include <stdlib.h>
#include "lemin.h"
#include "my.h"

static int	init_values(int *i, int *start,
			    int *end, t_rooms *rooms)
{
  *i = 0;
  *start = 0;
  *end = 0;
  if (rooms == NULL)
    return (-1);
  return (0);
}

static int	start_end_error()
{
  my_put_error("No start // end found\n");
  return (-1);
}

static int	check(t_rooms *rooms, int i, t_rooms *tmp)
{
  if (check_room(rooms, tmp->data->name, i) == 1)
    return (-1);
  else if (check_coord(rooms, tmp->data->x, tmp->data->y, i) == 1)
    return (-1);
  return (0);
}

static void	print_name(int end, int start, t_rooms *tmp)
{
  if (end == 1 && tmp->data->pos == END)
    my_printf("##end\n");
  else if (start == 1 && tmp->data->pos == START)
    my_printf("##start\n");
  my_printf("%s %d %d\n",
	    tmp->data->name, tmp->data->x, tmp->data->y);
}

int		display_rooms(t_rooms *rooms)
{
  t_rooms	*tmp;
  int		start;
  int		end;
  int		i;

  if (init_values(&i, &start, &end, rooms) == -1)
    return (-1);
  tmp = rooms;
  while (tmp != NULL)
    {
      if (check_end_start(tmp, &start, &end) == -1)
	return (-1);
      if (check(rooms, i, tmp) == -1)
	return (-1);
      if (tmp->data->name != NULL)
	print_name(end, start, tmp);
      else
	return (-1);
      i++;
      tmp = tmp->next;
    }
  if (start == 0 || end == 0)
    return (start_end_error());
  return (0);
}
