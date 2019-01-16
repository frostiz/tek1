/*
** my_copytab.c for my_copytab.c in /home/thibaut/Repository/PSU_2016_minishell2/lib/my
** 
** Made by Thibaut Trouvé
** Login   <thibaut.trouve@epitech.eu>
** 
** Started on  Mon Apr  3 21:15:53 2017 Thibaut Trouvé
** Last update Sun Apr  9 22:22:22 2017 Thibaut Trouvé
*/

#include <stdlib.h>
#include "my.h"

char	**my_copy_tab(char **tab)
{
  char	**new_tab;
  int	i;

  i = 0;
  if (tab == NULL)
    return (NULL);
  new_tab = malloc(sizeof(char *) * (my_tablen(tab) + 1));
  if (new_tab == NULL)
    return (NULL);
  while (tab[i] != NULL)
    {
      new_tab[i] = my_strdup(tab[i]);
      if (new_tab[i] == NULL)
	return (NULL);
      i++;
    }
  new_tab[i] = NULL;
  return (new_tab);
}
