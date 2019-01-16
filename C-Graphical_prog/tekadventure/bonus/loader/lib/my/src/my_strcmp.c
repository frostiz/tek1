/*
** my_strcmp.c for my_strcmp.c in /home/roye_v/delivery/raytracer1/src/my/lib/src
** 
** Made by Vincent Roye
** Login   <roye_v@epitech.net>
** 
** Started on  Sat Feb 11 19:12:57 2017 Vincent Roye
** Last update Sat Feb 11 19:13:47 2017 Vincent Roye
*/

#include "my.h"

int	my_strcmp(char *s1, char *s2)
{
  int	i;

  i = 0;
  while (s1[i] && s2[i] && s1[i] == s2[i])
    i++;
  return (s1[i] - s2[i]);
}
