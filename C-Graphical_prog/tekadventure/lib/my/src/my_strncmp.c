/*
** my_strncmp.c for my_strncmp.c in /home/roye_v/delivery/raytracer1/src/my/lib/src
** 
** Made by Vincent Roye
** Login   <roye_v@epitech.net>
** 
** Started on  Sat Feb 11 19:12:57 2017 Vincent Roye
** Last update Thu May  4 17:14:46 2017 Thibaut Trouvé
*/

#include "my.h"

int	my_strncmp(char *s1, char *s2, int n)
{
  int	i;

  i = 0;
  while (s1[i] && s2[i] && s1[i] == s2[i] && i < n)
    i++;
  return (s1[i] - s2[i]);
}
