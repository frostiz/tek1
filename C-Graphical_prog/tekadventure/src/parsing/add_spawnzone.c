/*
** add_spawnzone.c for tekadventure in /home/dubret_v/delivery/semestre2/infographie/tekadventure/src/parsing
** 
** Made by dubret_v
** Login   <victor.dubret@epitech.eu>
** 
** Started on  Thu May 25 17:30:32 2017 dubret_v
** Last update Thu May 25 17:37:42 2017 dubret_v
*/

t_map	*add_spawnzone(t_map *map, int *room, char *str)
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
  tmp->spawn = my_realloc_int_arr(tmp->spawn);
  if (is_only_digit(arr) != 0)
    {
      my_puterror("Only digit for coords\n");
      return (NULL);
    }
  tmp->spawn[tmp->spawn[0][0]][0] = my_getnbr(arr[0]);
  tmp->spawn[tmp->spawn[0][0]][1] = my_getnbr(arr[1]);
  return (map);
}
