/*
** epure_input.c for minishell2 in /home/thibaut/Repository/PSU_2016_minishell2/unit_test
** 
** Made by Thibaut Trouvé
** Login   <thibaut.trouve@epitech.eu>
** 
** Started on  Mon May  1 05:12:03 2017 Thibaut Trouvé
** Last update Wed May  3 06:15:16 2017 Thibaut Trouvé
*/

#include <stdlib.h>
#include <stdio.h>
#include "my.h"

void	add_char(char c, char **tmp_ptr, int *idx, char *str)
{
  char	*dup;

  dup = malloc(sizeof(char) * 5);
  if (dup == NULL)
    return ;
  dup[0] = ' ';
  dup[1] = c;
  dup[2] = c;
  dup[3] = ' ';
  dup[4] = '\0';
  if (str[(*idx) + 1] == c)
    {
      *tmp_ptr = my_realloc(*tmp_ptr, my_strlen(*tmp_ptr) + 1 + 4);
      my_strcat(*tmp_ptr, dup);
      (*idx)++;
    }
  else
    {
      dup[2] = ' ';
      dup[3] = '\0';
      *tmp_ptr = my_realloc(*tmp_ptr, my_strlen(*tmp_ptr) + 1 + 3);
      my_strcat(*tmp_ptr, dup);
    }
  free(dup);
}

int	choose_char(char *str, int *i, char **tmp_ptr)
{
  char	*c;

  if (str[*i] == '|')
    add_char('|', tmp_ptr, i, str);
  else if (str[*i] == '<')
    add_char('<', tmp_ptr, i, str);
  else if (str[*i] == '>')
    add_char('>', tmp_ptr, i, str);
  else
    {
      c = my_strdup(&str[*i]);
      c[1] = '\0';
      *tmp_ptr = my_realloc(*tmp_ptr, my_strlen(*tmp_ptr) + 1 + 1);
      my_strcat(*tmp_ptr, c);
      free(c);
    }
  return (0);
}

char	*epure_input(char *str)
{
  int	i;
  char	*tmp;

  tmp = malloc(sizeof(char) * 1);
  if (tmp == NULL)
    return (NULL);
  i = 0;
  tmp[0] = '\0';
  while (str[i] != '\0')
    {
      if (str[i] == ';')
	{
	  tmp = my_realloc(tmp, my_strlen(tmp) + 1 + 3);
	  my_strcat(tmp, " ; ");
	}
      else
	choose_char(str, &i, &tmp);
      i++;
    }
  free(str);
  return (tmp);
}
