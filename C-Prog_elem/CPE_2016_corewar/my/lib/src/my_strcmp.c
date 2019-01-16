/*
** my_strcmp.c for my_strcmp.c in /home/roye_v/delivery/raytracer1/src/my/lib/src
** 
** Made by Vincent Roye
** Login   <roye_v@epitech.net>
** 
** Started on  Sat Feb 11 19:12:57 2017 Vincent Roye
** Last update Fri Mar 31 11:17:02 2017 dubret_v
*/

#include <stdlib.h>
#include "my.h"

int	my_strcmp(char *s1, char *s2)
{
  int	i;

  i = 0;
  if (s1 == NULL || s2 == NULL)
    return (0);
  while (s1[i] && s2[i] && s1[i] == s2[i])
    i++;
  return (s1[i] - s2[i]);
}
