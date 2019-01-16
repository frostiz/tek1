/*
** my_strdup.c for  in /home/sahel/bin/lib
** 
** Made by Sahel
** Login   <sahel.lucas-saoudi@epitech.eu@epitech.net>
** 
** Started on  Fri Feb 17 08:22:05 2017 Sahel
** Last update Thu Mar  9 16:09:55 2017 Sahel
*/

#include <stdlib.h>
#include "basic.h"

char	*strdup_(char *str)
{
  char	*new;
  int	str_i;

  if (!str)
    return (NULL);
  if (!(new = malloc(sizeof(char) * strlen_(str) + 1)))
    return (NULL);
  str_i = 0;
  while (str[str_i])
    {
      new[str_i] = str[str_i];
      str_i++;
    }
  new[str_i] = '\0';
  return (new);
}

char	*strndup_(char *str, int limit)
{
  char	*new;
  int	new_i;

  if (!(new = malloc(sizeof(char) * (limit + 1))))
    return (NULL);
  new_i = 0;
  while (new_i < limit && str[new_i])
    {
      new[new_i] = str[new_i];
      new_i++;
    }
  new[new_i] = '\0';
  return (new);
}

char	*strdupn_(char *str, int start)
{
  char	*new;
  int	new_i;

  if (strlen_(str) - start + 1 == 0)
    return (NULL);
  if (!(new = malloc(sizeof(char) * (strlen_(str) - start + 1))))
    return (NULL);
  new_i = 0;
  while (str[start])
    {
      new[new_i] = str[start];
      new_i++;
      start++;
    }
  new[new_i] = '\0';
  free_(str);
  return (new);
}
