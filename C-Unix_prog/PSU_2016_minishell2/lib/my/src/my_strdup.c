/*
** my_strdup.c for my_strdup.c in /home/thibaut/Repository/PSU_2016_minishell2/lib/my
** 
** Made by Thibaut Trouvé
** Login   <thibaut.trouve@epitech.eu>
** 
** Started on  Mon Apr  3 21:10:28 2017 Thibaut Trouvé
** Last update Tue Apr  4 01:12:12 2017 Thibaut Trouvé
*/

#include <stdlib.h>
#include "my.h"

char	*my_strdup(char *str)
{
  char	*new;
  int	i;

  new = malloc(sizeof(char) * (my_strlen(str) + 1));
  if (new == NULL)
    return (NULL);
  i = 0;
  while (str[i] != '\0')
    {
      new[i] = str[i];
      i++;
    }
  new[i] = '\0';
  return (new);
}
