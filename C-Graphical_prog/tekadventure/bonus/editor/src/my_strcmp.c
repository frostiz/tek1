/*
** my_strcmp.c for  in /home/Zarkkos/Delivery/C_Graphical_Prog/tekadventure/editor
**
** Made by Antoine Duez
** Login   <Zarkkos@epitech.net>
**
** Started on  Thu May 18 23:21:32 2017 Antoine Duez
** Last update Thu May 18 23:21:33 2017 Antoine Duez
*/

#include <stdlib.h>
#include <stdio.h>
#include "my.h"

int	my_strcmp(char *str, char *cmp)
{
  int	i;

  i = 0;
  while (str[i] != '\0' && cmp[i] != '\0')
    {
      if (str[i] != cmp[i])
	return (0);
      i++;
    }
  if (str[i] != '\0' && str[i] == '=')
    return (3);
  if (str[i] != '\0')
    return (2);
  if (cmp[i] != '\0')
    return (0);
  return (1);
}

char	*my_strdup(char *str)
{
  int	i;
  char	*new;

  i = 0;
  new = malloc(sizeof(char) * (my_strlen(str) + 1));
  if (new == NULL)
    return (NULL);
  while (str[i] != '\0')
    {
      new[i] = str[i];
      i++;
    }
  new[i] = '\0';
  return (new);
}
