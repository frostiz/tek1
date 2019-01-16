/*
** my_strcat.c for my_strcat.c in /home/roye_v/delivery/my_lib
** 
** Made by Vincent Roye
** Login   <roye_v@epitech.net>
** 
** Started on  Mon Mar 20 20:19:30 2017 Vincent Roye
** Last update Mon Mar 20 20:20:49 2017 Vincent Roye
*/

#include <stdlib.h>
#include "my.h"

char	*my_strcat(char *dest, char *src)
{
  int	i;
  int	j;

  i = 0;
  j = my_strlen(dest);
  while (src[i] != '\0')
    {
      dest[i + j] = src[i];
      i++;
    }
  dest[j + i] = '\0';
  return (dest);
}
