/*
** find_parentheses.c for 42sh in /home/dubret_v/delivery/semestre2/Unix/PSU_2016_42sh/src/graph
** 
** Made by dubret_v
** Login   <victor.dubret@epitech.eu>
** 
** Started on  Sun May 21 19:22:59 2017 dubret_v
** Last update Sun May 21 19:25:04 2017 dubret_v
*/

#include		<string.h>
#include		<stdlib.h>
#include		"mysh.h"

static	char		*get_out_parentheses(char *str, int *j)
{
  char			*tmp;
  int			i;

  i = 1;
  tmp = malloc(sizeof(char) * (int)strlen(str));
  if (tmp == NULL)
    return (NULL);
  while (i < (int)strlen(str) - 1)
    {
      tmp[i - 1] = str[i];
      i++;
    }
  tmp[i - 1] = '\0';
  *j = i - 1;
  return (tmp);
}

static	int		parentheses(char **str, int *i, int *nb_parentheses,
				    int remove_parentheses)
{
  while (*nb_parentheses != 0 && (*str)[*i] != '\0')
    {
      if ((*str)[*i] == ')')
	*nb_parentheses -= 1;
      else if ((*str)[*i] == '(')
	*nb_parentheses += 1;
      *i += 1;
    }
  if (*nb_parentheses == 0)
    {
      if ((*str)[*i] == '\0' && remove_parentheses == 1)
	{
	  (*str) = get_out_parentheses((*str), i);
	  if ((*str) == NULL)
	    return (84);
	  remove_spare_spaces(*str);
	  *i = 0;
	  return (1);
	}
    }
  return (0);
}

int			find_parentheses(int *i, char **str,
					 int limit_idx, int remove_parentheses)
{
  int			nb_parentheses;
  int			ret;

  nb_parentheses = 1;
  *i += 1;
  ret = parentheses(str, i, &nb_parentheses, remove_parentheses);
  if (ret == 84)
    return (-1);
  else if (ret == 1)
    limit_idx = 0;
  return (limit_idx);
}
