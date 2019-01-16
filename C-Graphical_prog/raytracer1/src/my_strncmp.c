/*
** my_strncmp.c for my_strncmp.c in /home/frostiz/CPool_Day06
** 
** Made by thibaut trouve
** Login   <frostiz@epitech.net>
** 
** Started on  Mon Oct 10 15:32:40 2016 thibaut trouve
** Last update Sun Mar 19 23:30:04 2017 
*/

#include "my.h"

int	my_strncmp(char *s1, char *s2, int n)
{
  int	i;

  i = 0;
  if (n < 0)
    {
      if (my_strlen(s1) >= my_strlen(s2))
	n = my_strlen(s1);
      else
	n = my_strlen(s2);
    }
  while (s1[i] ==  s2[i] && i < n - 1)
    {
      if (s1[i] == n && s2[i] == n)
	return (0);
      i++;
    }
  if (s1[i] < s2[i] && i != n)
    return (s1[i] - s2[i]);
  else
    return (s1[i] - s2[i]);
  return (0);
}
