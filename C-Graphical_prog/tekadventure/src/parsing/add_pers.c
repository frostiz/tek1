/*
** add_pers.c for tekadventure in /home/DxCube/delivery/tekadventure
** 
** Made by Victor Dubret
** Login   <victor.dubret@epitech.eu>
** 
** Started on  Sat May 27 17:07:07 2017 Victor Dubret
** Last update Sun May 28 19:08:23 2017 Victor Dubret
*/

#include	<stdlib.h>
#include	"my.h"
#include	"tekadventure.h"

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
  tmp->characters.character[tmp->characters.character[0][0]][0]
    = my_getnbr(arr[0]);
  tmp->characters.character[tmp->characters.character[0][0]][1]
    = my_getnbr(arr[1]);
  return (tmp);
}

static t_map	*sentence_of_charac(t_map *tmp, char *str)
{
  int		len;

  if (tmp->characters.nb_passed == 2)
    {
      tmp->characters.charac = my_realloc_tab(tmp->characters.charac);
      if (tmp->characters.charac == NULL)
	return (NULL);
      len = arr_len(tmp->characters.charac);
      tmp->characters.charac[len] = my_strdup(str);
      tmp->characters.charac[len + 1] = NULL;
      tmp->characters.nb_passed += 1;
    }
  else
    {
      tmp->characters.sentence = my_realloc_tab(tmp->characters.sentence);
      if (tmp->characters.sentence == NULL)
	return (NULL);
      len = arr_len(tmp->characters.sentence);
      tmp->characters.sentence[len] = my_strdup(str);
      tmp->characters.sentence[len + 1] = NULL;
      tmp->characters.nb_passed = 0;
    }
  return (tmp);
}

t_map		*add_characters(t_map *map, int *room, char *str)
{
  t_map		*tmp;

  tmp = map;
  tmp = search_the_room(tmp, room, NULL, tmp);
  if (tmp->nb_room != *room)
    return (NULL);
  if (tmp->characters.nb_passed < 2)
    {
      tmp->characters.character =
	my_realloc_int_arr(tmp->characters.character);
      tmp = is_coords(tmp, str);
      if (tmp == NULL)
	return (NULL);
      tmp->characters.nb_passed++;
    }
  else
    {
      tmp = sentence_of_charac(tmp, str);
      if (tmp == NULL)
	return (NULL);
    }
  return (map);
}
