/*
** my_strncmp.c for my_strncmp in /home/thibaut/Repository/PSU_2016_minishell2
** 
** Made by Thibaut Trouvé
** Login   <thibaut.trouve@epitech.eu>
** 
** Started on  Wed Apr  5 20:37:58 2017 Thibaut Trouvé
** Last update Sun Apr  9 22:22:49 2017 Thibaut Trouvé
*/

#include "my.h"

int	my_strncmp(char *s1, char *s2, int n)
{
  int	i;

  i = 0;
  while (s1[i] == s2[i] && s1[i] && s2[i] && i < n)
    i++;
  return (s1[i] - s2[i]);
}
