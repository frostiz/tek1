/*
** search_the_room.c for tekadventure in /home/dubret_v/delivery/semestre2/infographie/tekadventure
** 
** Made by dubret_v
** Login   <victor.dubret@epitech.eu>
** 
** Started on  Thu May 25 15:10:15 2017 dubret_v
** Last update Sat May 27 14:18:39 2017 Victor Dubret
*/

#include	<stdlib.h>
#include	"tekadventure.h"

static t_map	*loop(t_map *tmp, int *ever_passed, int *room, int *i)
{
  if (tmp->new_room[*i] != NULL &&
      is_ever_passed(tmp->new_room[*i]->nb_room, ever_passed) == 0)
    {
      tmp = search_the_room(tmp->new_room[*i], room, ever_passed, tmp);
      if (tmp->nb_room == *room)
	{
	  *i = 10;
	  return (tmp);
	}
    }
  return (tmp);
}

t_map		*search_the_room(t_map *tmp, int *room,
				 int *ever_passed, t_map *from_hir)
{
  int		i;

  i = 0;
  ever_passed = realloc_int(ever_passed);
  ever_passed[ever_passed[0]] = tmp->nb_room;
  if (tmp->nb_room == *room)
    return (tmp);
  if (tmp->new_room == NULL)
    {
      if (from_hir != NULL)
	return (from_hir);
      return (tmp);
    }
  while (tmp->new_room != NULL && tmp->new_room[i] != NULL)
    {
      tmp = loop(tmp, ever_passed, room, &i);
      if (i == 10)
	return (tmp);
      i++;
    }
  if (tmp->nb_room == *room)
    return (tmp);
  return (from_hir);
}
