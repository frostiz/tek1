/*
** modify_for_redirect.c for 42sh in /home/dubret_v/delivery/semestre2/Unix/PSU_2016_42sh
**
** Made by dubret_v
** Login   <victor.dubret@epitech.eu>
**
** Started on  Tue May 16 11:23:25 2017 dubret_v
** Last update Sun May 21 20:52:15 2017 dubret_v
*/

#include <string.h>
#include <stdlib.h>
#include "mysh.h"

static	int	after_arg(char *tmp2, int j, int beginning)
{
  int			space;
  int			len;

  space = 0;
  if (tmp2[j] != ' ' && tmp2[j] != '\t')
    space++;
  len = 0;
  while (tmp2[j] != '<' && tmp2[j] != '>' &&
	 tmp2[j] != '&' && tmp2[j] != '|' &&
	 tmp2[j] != '\0' && space != 2)
    {
      if (tmp2[j] == '(')
	return (-1);
      if (tmp2[j] == '"')
	{
	  j++;
	  cpy_inside_quotes(&(tmp2[beginning]), tmp2, &j);
	}
      if (tmp2[j] == ' ')
	space++;
      if (tmp2[j] != '\0')
	j++;
      len++;
    }
  return (j);
}

static void	set_tmp(char *tmp, char *tmp2, int j, int *i)
{
  tmp = strcat(tmp, &(tmp2[j]));
  tmp2[j] = '\0';
  *i = (int)strlen(tmp);
  tmp = strcat(tmp, tmp2);
  free(tmp2);
}

char		*modify_for_redir(char *str, int *i, int limit)
{
  char			*tmp;
  char			*tmp2;
  int			idx;
  int			j;

  j = 0;
  idx = -1;
  tmp = malloc(sizeof(char) * (strlen(str) + 1));
  if (tmp == NULL)
    return (NULL);
  while (idx < *i)
    {
      idx++;
      tmp[idx] = str[idx];
    }
  tmp[idx] = '\0';
  tmp2 = strdup(&str[idx]);
  if (tmp2 == NULL)
    return (NULL);
  j += (limit == 4 || limit == 5) ? (2) : (1);
  j = after_arg(tmp2, j, j);
  if (j == -1)
    return (NULL);
  set_tmp(tmp, tmp2, j, i);
  return (tmp);
}
