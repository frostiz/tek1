/*
** my_strncmp.c for my_strncmp in /home/thibaut/Repository/CPE_2016_corewar
** 
** Made by 
** Login   <thibaut.trouve@epitech.eu>
** 
** Started on  Wed Mar 29 01:39:45 2017 
** Last update Wed Mar 29 01:40:45 2017 
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
