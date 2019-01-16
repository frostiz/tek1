/*
** my_memset.c for my_memset.c in /home/roye_v/delivery/my_lib
** 
** Made by Vincent Roye
** Login   <roye_v@epitech.net>
** 
** Started on  Mon Mar 20 20:14:18 2017 Vincent Roye
** Last update Mon Mar 20 20:14:57 2017 Vincent Roye
*/

#include <stdlib.h>
#include "my.h"

char	*my_memset(char c, int len)
{
  int	i;
  int	j;
  char	*tmp;

  i = len;
  tmp = malloc(sizeof(char) * (i + 1));
  if (tmp == NULL)
    return (NULL);
  j = 0;
  while (j < i)
    {
      tmp[j] = c;
      j++;
    }
  tmp[j] = '\0';
  return (tmp);
}
