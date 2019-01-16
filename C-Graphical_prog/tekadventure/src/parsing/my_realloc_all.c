/*
** my_realloc_all.c for tekadventure in /home/dubret_v/delivery/semestre2/infographie/tekadventure
** 
** Made by dubret_v
** Login   <victor.dubret@epitech.eu>
** 
** Started on  Thu May 25 15:52:31 2017 dubret_v
** Last update Sat May 27 16:53:39 2017 Victor Dubret
*/

#include	<stdlib.h>
#include	"tekadventure.h"
#include	"my.h"

int		*realloc_int(int *arr)
{
  int		*tmp;
  int		i;

  i = 0;
  if (arr == NULL)
    {
      arr = malloc(sizeof(int) * 2);
      arr[0] = 1;
      arr[1] = 0;
      return (arr);
    }
  tmp = malloc(sizeof(int) * (arr[0] + 2));
  while (i <= arr[0])
    {
      tmp[i] = arr[i];
      i++;
    }
  tmp[0] += 1;
  return (tmp);
}

int		(*my_realloc_int_arr(int (*arr)[2]))[2]
{
  int		(*tmp)[2];
  int		i;

  i = 1;
  if (arr == NULL)
    {
      arr = malloc(sizeof(int *) * 2);
      if (arr == NULL)
	return (NULL);
      arr[0][0] = 1;
      arr[0][1] = 0;
      return (arr);
    }
  tmp = malloc(sizeof(int *) * (arr[0][0] + 2));
  while (i <= arr[0][0])
    {
      tmp[i][0] = arr[i][0];
      tmp[i][1] = arr[i][1];
      i++;
    }
  tmp[0][0] = arr[0][0] + 1;
  tmp[0][1] = 0;
  return (tmp);
}

t_map		**realloc_next_tab(t_map **new_room)
{
  t_map		**tmp;
  int		len;
  int		i;

  i = 0;
  if (new_room == NULL)
    {
      new_room = malloc(sizeof(t_map *) * 2);
      if (new_room == NULL)
	return (NULL);
      new_room[0] = NULL;
      new_room[1] = NULL;
      return (new_room);
    }
  len = next_len(new_room);
  tmp = malloc(sizeof(t_map *) * (len + 2));
  if (tmp == NULL)
    return (NULL);
  while (i < len)
    {
      tmp[i] = new_room[i];
      i++;
    }
  tmp[i] = NULL;
  return (tmp);
}

char		**my_realloc_tab(char **arr)
{
  char		**tmp;
  int		i;

  i = 0;
  if (arr == NULL)
    {
      tmp = malloc(sizeof(char *) * 2);
      if (tmp == NULL)
	return (NULL);
      tmp[0] = NULL;
      tmp[1] = NULL;
      return (tmp);
    }
  tmp = malloc(sizeof(char *) * (arr_len(arr) + 2));
  if (tmp == NULL)
    return (NULL);
  while (arr[i] != NULL)
    {
      tmp[i] = my_strdup(arr[i]);
      free(arr[i]);
      i++;
    }
  tmp[i] = NULL;
  return (tmp);
}
