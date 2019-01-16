/*
** add_background.c for tekadventure in /home/dubret_v/delivery/semestre2/infographie/tekadventure
** 
** Made by dubret_v
** Login   <victor.dubret@epitech.eu>
** 
** Started on  Wed May 24 17:05:42 2017 dubret_v
** Last update Sat May 27 16:53:27 2017 Victor Dubret
*/

#include	<stdlib.h>
#include	"my.h"
#include	 "tekadventure.h"

int		arr_len(char **arr)
{
  int		i;

  i = 0;
  if (arr == NULL)
    return (i);
  while (arr[i] != NULL)
    i++;
  return (i);
}

t_map		*add_background(t_map *map, int *room, char *str)
{
  t_map		*tmp;

  tmp = map;
  tmp = search_the_room(tmp, room, NULL, tmp);
  if (tmp->nb_room != *room)
    return (NULL);
  if (tmp->background != NULL)
    {
      my_puterror("Too many Background\n");
      return (NULL);
    }
  tmp->background = my_strdup(str);
  if (tmp->background == NULL)
    return (NULL);
  return (map);
}
