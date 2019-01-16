/*
** my_strcat.c for my_strcat.c in /home/frostiz/CPool_Day07
** 
** Made by thibaut trouve
** Login   <frostiz@epitech.net>
** 
** Started on  Tue Oct 11 10:23:59 2016 thibaut trouve
** Last update Sun Jan 22 23:01:58 2017 thibaut trouve
*/

#include "my.h"

char	*my_strcat(char *dest, char *src)
{
  int	i;
  int	strlen;

  i = 0;
  strlen = my_strlen(dest);
  while (src[i] != '\0')
    {
      dest[strlen] = src[i];
      i++;
      strlen++;
    }
  dest[strlen] = '\0';
  return (dest);
}
