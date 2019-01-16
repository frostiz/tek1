/*
** my_tablen.c for my_tablen.c in /home/thibaut/Repository/PSU_2016_minishell2/lib/my
** 
** Made by Thibaut Trouvé
** Login   <thibaut.trouve@epitech.eu>
** 
** Started on  Mon Apr  3 21:14:32 2017 Thibaut Trouvé
** Last update Mon Apr  3 21:26:21 2017 Thibaut Trouvé
*/

#include <stdlib.h>
#include "my.h"

int	my_tablen(char **tab)
{
  int	i;

  i = 0;
  while (tab[i] != NULL)
    {
      i++;
    }
  return (i);
}
