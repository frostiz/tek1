/*
** free_tab.c for free_tab.c in /home/thibaut/Repository/PSU_2016_minishell2/lib/my
** 
** Made by Thibaut Trouvé
** Login   <thibaut.trouve@epitech.eu>
** 
** Started on  Tue Apr  4 00:58:52 2017 Thibaut Trouvé
** Last update Tue Apr  4 01:06:28 2017 Thibaut Trouvé
*/

#include <stdlib.h>
#include "my.h"

void	free_tab(char **tab)
{
  int	i;

  i = 0;
  if (tab != NULL)
    {
      while (tab[i] != NULL)
	{
	  free(tab[i]);
	  i++;
	}
      free(tab);
    }
}
