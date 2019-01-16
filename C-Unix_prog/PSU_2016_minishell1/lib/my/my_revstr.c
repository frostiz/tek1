/*
** my_revstr.c for my_revstr.c in /home/frostiz/CPool_Day06
** 
** Made by thibaut trouve
** Login   <frostiz@epitech.net>
** 
** Started on  Mon Oct 10 10:47:28 2016 thibaut trouve
** Last update Sun Jan 22 23:02:48 2017 thibaut trouve
*/

#include "my.h"

char	*my_revstr(char *str)
{
  int	i;
  int	strlen;
  char	temp;

  i = 0;
  strlen = my_strlen(str) - 1;
  while (strlen > i)
    {
      temp = str[i];
      str[i] = str[strlen];
      str[strlen] = temp;
      i++;
      strlen--;
    }
  return (str);
}
