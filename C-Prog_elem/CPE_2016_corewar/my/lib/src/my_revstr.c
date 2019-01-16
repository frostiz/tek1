/*
** my_revstr.c for my_revstr.c in /home/roye_v/delivery/CPool_Day06
** 
** Made by Vincent Roye
** Login   <roye_v@epitech.net>
** 
** Started on  Mon Oct 10 13:59:13 2016 Vincent Roye
** Last update Sat Feb 11 18:37:30 2017 Vincent Roye
*/

#include <unistd.h>
#include "my.h"

char	*my_revstr(char *str)
{
  int	a;
  int	b;
  char	c;

  a = 0;
  b = my_strlen(str) - 1;
  while (a < b)
    {
      c = str[a];
      str[a] = str[b];
      str[b] = c;
      a++;
      b--;
    }
  return (str);
}
