/*
** my_strdup.c for my_strdup.c in /home/frostiz/CPool_Day08/task01
** 
** Made by thibaut trouve
** Login   <frostiz@epitech.net>
** 
** Started on  Wed Oct 12 09:28:27 2016 thibaut trouve
** Last update Wed Dec 14 15:38:40 2016 thibaut trouve
*/

#include "my.h"

char	*my_strdup(char *src)
{
  int	i;
  char	*str;

  str = malloc(sizeof(char) * (my_strlen(src) + 1));
  if (str == NULL)
    return (NULL);
  i = 0;
  while (src[i] != '\0')
    {
      str[i] = src[i];
      i++;
    }
  str[i] = '\0';
  return (str);
}
