/*
** add_doorzone.c for tekadventure in /home/dubret_v/delivery/semestre2/infographie/tekadventure
** 
** Made by dubret_v
** Login   <victor.dubret@epitech.eu>
** 
** Started on  Wed May 24 19:42:30 2017 dubret_v
** Last update Sat May 27 16:41:50 2017 Victor Dubret
*/

#include	<stdio.h>

#include	<stdlib.h>
#include	"my.h"
#include	"tekadventure.h"

static	int	is_only_digit_str(char *str)
{
  int		i;

  i = 0;
  while (str[i] != '\0')
    {
      if ((str[i] < '0' || str[i] > '9')
	  && str[i] != '-' && str[i] != '+')
	return (1);
      i++;
    }
  return (0);
}

int		next_len(t_map **tab)
{
  int		i;

  i = 0;
  while (tab[i] != NULL)
    i++;
  return (i);
}

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
  tmp->doorzone[tmp->doorzone[0][0]][0] = my_getnbr(arr[0]);
  tmp->doorzone[tmp->doorzone[0][0]][1] = my_getnbr(arr[1]);
  return (tmp);
}

static t_map		*is_id_room(char *str, t_map *map, t_map *tmp)
{
  int		nb;
  int		len;
  t_map		*tmp2;

  nb = my_getnbr(str);
  tmp->doorzone[tmp->doorzone[0][0]][0] = nb;
  if (is_only_digit_str(str) != 0)
    {
      my_puterror("Only digit for id room\n");
      return (NULL);
    }
  tmp->new_room = realloc_next_tab(tmp->new_room);
  len = next_len(tmp->new_room);
  tmp2 = map;
  tmp2 = search_the_room(tmp2, &nb, NULL, tmp2);
  if (tmp2->nb_room != nb)
    tmp->new_room[len] = create_node(tmp->new_room[len], &nb, str);
  else
    tmp->new_room[len] = tmp2;
  tmp->new_room[len + 1] = NULL;
  return (tmp);
}

t_map		*add_doorzone(t_map *map, int *room, char *str)
{
  t_map		*tmp;

  tmp = map;
  tmp = search_the_room(tmp, room, NULL, tmp);
  if (tmp->nb_room != *room)
    return (NULL);
  tmp->doorzone = my_realloc_int_arr(tmp->doorzone);
  if (tmp->doorzone[0][0] % 3 != 0)
    {
      tmp = is_coords(tmp, str);
      if (tmp == NULL)
	return (NULL);
    }
  else
    {
      tmp = is_id_room(str, map, tmp);
      if (tmp == NULL)
	return (NULL);
    }
  return (map);
}
