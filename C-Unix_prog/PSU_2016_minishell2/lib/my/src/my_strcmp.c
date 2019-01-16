/*
** my_strcmp.c for strcmp in /home/thibaut/Repository/PSU_2016_minishell2
** 
** Made by Thibaut Trouvé
** Login   <thibaut.trouve@epitech.eu>
** 
** Started on  Tue Apr  4 21:25:56 2017 Thibaut Trouvé
** Last update Tue Apr  4 21:27:25 2017 Thibaut Trouvé
*/

#include "my.h"

int	my_strcmp(char *s1, char *s2)
{
  int	i;

  i = 0;
  while (s1[i] == s2[i] && s1[i] && s2[i])
    i++;
  return (s1[i] - s2[i]);
}
