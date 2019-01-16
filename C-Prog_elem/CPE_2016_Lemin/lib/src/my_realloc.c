/*
** my_realloc.c for my_realloc.c in /home/roye_v/delivery/PSU_2016/PSU_2016_minishell2
** 
** Made by Vincent Roye
** Login   <roye_v@epitech.net>
** 
** Started on  Tue Apr  4 19:26:07 2017 Vincent Roye
** Last update Sun Apr  9 18:07:00 2017 Vincent Roye
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
  free(str);
  return (tmp);
}
