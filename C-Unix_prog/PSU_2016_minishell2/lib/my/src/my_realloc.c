/*
** my_realloc.c for my_realloc in /home/thibaut/Repository/PSU_2016_minishell2
** 
** Made by Thibaut Trouvé
** Login   <thibaut.trouve@epitech.eu>
** 
** Started on  Tue Apr  4 19:40:59 2017 Thibaut Trouvé
** Last update Tue Apr  4 19:44:00 2017 Thibaut Trouvé
*/

#include <stdlib.h>
#include "my.h"

char	*my_realloc(char *str, int size)
{
  int	i;
  char	*new;

  i = 0;
  new = malloc(sizeof(char) * size);
  if (new == NULL)
    return (NULL);
  while (str[i] != '\0')
    {
      new[i] = str[i];
      i++;
    }
  new[i] = '\0';
  free(str);
  return (new);
}
