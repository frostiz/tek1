/*
** my_realloc.c for my_realloc.c in /home/roye_v/delivery/my_lib/src
** 
** Made by Vincent Roye
** Login   <roye_v@epitech.net>
** 
** Started on  Mon Mar 20 20:22:15 2017 Vincent Roye
** Last update Mon Mar 20 20:23:29 2017 Vincent Roye
*/

#include <stdlib.h>
#include "my.h"

char	*my_realloc(char *str, int size)
{
  char	*tmp;
  int	i;

  i = 0;
  tmp = malloc(sizeof(char) * (my_strlen(str) + size + 1));
  if (tmp == NULL)
    return (NULL);
  while (str[i] != '\0')
    {
      tmp[i] = str[i];
      i++;
    }
  tmp[i] = '\0';
  return (tmp);
}
