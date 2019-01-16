/*
** add_object.c for tekadventure in /home/DxCube/delivery/tekadventure
** 
** Made by Victor Dubret
** Login   <victor.dubret@epitech.eu>
** 
** Started on  Sat May 27 16:46:06 2017 Victor Dubret
** Last update Sun May 28 19:07:35 2017 Victor Dubret
*/

#include	<stdlib.h>
#include	"tekadventure.h"
#include	"my.h"

static	t_map	*is_coords(t_map *tmp, char *str)
{
  char		**arr;

  arr = str_to_wordtab(str, ':');
  if (arr == NULL)
    return (NULL);
  if (arr_len(arr) != 2)
    {
      my_puterror("Invalid config file\n");
      return (NULL);
    }
  else if (is_only_digit(arr) != 0)
    {
      my_puterror("Only digit for coords\n");
      return (NULL);
    }
  tmp->objects.object[tmp->objects.object[0][0]][0] = my_getnbr(arr[0]);
  tmp->objects.object[tmp->objects.object[0][0]][1] = my_getnbr(arr[1]);
  return (tmp);
}

t_map		*is_name_object(t_map *tmp, char *str)
{
  int		len;

  tmp->objects.obj = my_realloc_tab(tmp->objects.obj);
  if (tmp->objects.obj == NULL)
    return (NULL);
  len = arr_len(tmp->objects.obj);
  tmp->objects.obj[len] = my_strdup(str);
  tmp->objects.obj[len + 1] = NULL;
  return (tmp);
}

t_map		*add_object(t_map *map, int *room, char *str)
{
  t_map		*tmp;

  tmp = map;
  tmp = search_the_room(tmp, room, NULL, tmp);
  if (tmp->nb_room != *room)
    return (NULL);
  if (tmp->objects.nb_passed != 2)
    {
      tmp->objects.object = my_realloc_int_arr(tmp->objects.object);
      if (tmp->objects.object == NULL)
	return (NULL);
      tmp = is_coords(tmp, str);
      if (tmp == NULL)
	return (NULL);
      tmp->objects.nb_passed++;
    }
  else
    {
      tmp = is_name_object(tmp, str);
      if (tmp == NULL)
	return (NULL);
      tmp->objects.nb_passed = 0;
    }
  return (map);
}
