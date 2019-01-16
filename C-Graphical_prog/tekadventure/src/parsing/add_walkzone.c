/*
** add_walkzone.c for tekadventure in /home/dubret_v/delivery/semestre2/infographie/tekadventure
** 
** Made by dubret_v
** Login   <victor.dubret@epitech.eu>
** 
** Started on  Wed May 24 17:17:45 2017 dubret_v
** Last update Thu May 25 15:52:59 2017 dubret_v
*/

#include	<stdlib.h>
#include	"my.h"
#include	"tekadventure.h"

int		is_only_digit(char **arr)
{
  int		i;
  int		j;

  i = 0;
  while (i < 2)
    {
      j = 0;
      while (arr[i][j] != '\0')
	{
	  if ((arr[i][j] < '0' || arr[i][j] > '9')
	      && arr[i][j] != '-' && arr[i][j] != '+')
	    return (1);
	  j++;
	}
      i++;
    }
  return (0);
}

t_map		*add_walkzone(t_map *map, int *room, char *str)
{
  t_map		*tmp;
  char		**arr;

  tmp = map;
  tmp = search_the_room(tmp, room, NULL, tmp);
  if (tmp->nb_room != *room)
    {
      my_putstr("Salle pas encore créée\n");
      return (NULL);
    }
  arr = str_to_wordtab(str, ':');
  if (arr_len(arr) != 2)
    {
      my_puterror("Invalid config file\n");
      return (NULL);
    }
  tmp->walkzone = my_realloc_int_arr(tmp->walkzone);
  if (is_only_digit(arr) != 0)
    {
      my_puterror("Only digit for coords\n");
      return (NULL);
    }
  tmp->walkzone[tmp->walkzone[0][0]][0] = my_getnbr(arr[0]);
  tmp->walkzone[tmp->walkzone[0][0]][1] = my_getnbr(arr[1]);
  return (map);
}
