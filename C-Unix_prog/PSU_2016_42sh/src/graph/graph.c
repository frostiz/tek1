/*
** graph.c for 42sh in /home/dubret_v/delivery/semestre2/Unix/PSU_2016_42sh
**
** Made by dubret_v
** Login   <victor.dubret@epitech.eu>
**
** Started on  Sat May 13 16:50:58 2017 dubret_v
** Last update Sun May 21 23:35:18 2017 Thibaut Trouvé
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "mysh.h"

static	void		create_limit(char *limit[8])
{
  limit[0] = ";";
  limit[1] = "||";
  limit[2] = "&&";
  limit[3] = "|";
  limit[4] = ">>";
  limit[5] = "<<";
  limit[6] = ">";
  limit[7] = "<";
}

static	int		init_find_limit(char *limit[8], char **str,
					int *remove_parentheses)
{
  create_limit(limit);
  remove_spare_spaces((*str));
  *remove_parentheses = is_only_parentheses(*str);
  if (*remove_parentheses == 84)
    return (-1);
  return (0);
}

static	int		check_parentheses(char **str, int limit_idx,
					  int *i, int remove_parentheses)
{
  if ((*str)[*i] == '(')
    {
      limit_idx = find_parentheses(i, str, limit_idx, remove_parentheses);
      if (limit_idx == -1)
	return (-2);
    }
  return (limit_idx);
}

int			find_limit(char **str, int *i)
{
  char			*limit[8];
  int			idx;
  int			remove_parentheses;

  idx = init_find_limit(limit, str, &remove_parentheses);
  while (idx < 8 && idx >= 0)
    {
      *i = 0;
      while ((*str)[*i] != '\0')
	if ((*str)[*i] == '"' || (*str)[*i] == '`')
	  *i = go_through_quotes(*str, *(i) + 1, (*str)[*i]);
	else if ((*str)[*i] == '(')
	  idx = check_parentheses(str, idx, i, remove_parentheses);
	else if ((*str)[*i] != '\0')
	  {
	    if (strncmp(limit[idx], &(*str)[*i], strlen(limit[idx])) == 0)
	      return (idx);
	    *i += 1;
	  }
      idx++;
    }
  return (idx);
}
