/*
** epure_semicolon.c for minishell2 in /home/frostiz/repository/PSU_2016_minishell2
** 
** Made by thibaut trouve
** Login   <frostiz@epitech.net>
** 
** Started on  Tue Apr 25 16:40:46 2017 thibaut trouve
** Last update Wed May  3 06:13:44 2017 Thibaut Trouvé
*/

#include <stdlib.h>
#include "my.h"
#include "main.h"

static void	new_line(int *i, int *j, char *str, char *tmp)
{
  tmp[*j] = str[*i];
  (*j)++;
  (*i)++;
  while (str[*i] && str[*i] == ';')
    (*i)++;
}

char	*epure_semicolon(char *str)
{
  int	i;
  int	j;
  char	*tmp;

  tmp = malloc(sizeof(char) * my_strlen(str) + 1);
  if (tmp == NULL)
    return (NULL);
  i = 0;
  j = 0;
  while (str[i] != '\0')
    {
      if (str[i] != ';')
	{
	  tmp[j] = str[i];
	  j++;
	}
      i++;
      if (str[i] == ';')
	new_line(&i, &j, str, tmp);
    }
  tmp[j] = '\0';
  free(str);
  return (tmp);
}
