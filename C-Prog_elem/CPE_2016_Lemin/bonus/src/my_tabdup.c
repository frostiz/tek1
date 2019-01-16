/*
** my_tabdup.c for lemin in /home/dubret_v/delivery/semestre2/CPE/CPE_2016_Lemin
** 
** Made by dubret_v
** Login   <victor.dubret@epitech.eu>
** 
** Started on  Sun Apr 30 16:17:08 2017 dubret_v
** Last update Mon May  1 00:20:36 2017 dubret_v
*/

#include		<stdlib.h>
#include		"my.h"

char			**my_tabdup(char **path)
{
  int			i;
  char			**tmp;

  i = 0;
  tmp = malloc(sizeof(char *) * (array_len(path) + 1));
  if (tmp == NULL)
    return (NULL);
  while (path[i] != NULL)
    {
      tmp[i] = my_strdup(path[i]);
      if (tmp[i] == NULL)
	return (NULL);
      i++;
    }
  tmp[i] = NULL;
  return (tmp);
}
