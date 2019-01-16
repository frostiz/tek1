/*
** glob_check.c for 42sh in /home/Lucas/delivery/PSU/PSU_2016_42sh
**
** Made by Lucas Dumy
** Login   <lucas.dumy@epitech.eu>
**
** Started on  Sun May 21 14:39:22 2017 Lucas Dumy
** Last update Sun May 21 14:46:19 2017 Lucas Dumy
*/

#include	"mysh.h"

static int	check_brackets(char *str1, char *str2, int *i, int *j)
{
  int		tmp;

  tmp = *i;
  (*i)++;
  while (str1[tmp] != ']')
    {
      if (str1[tmp] == '\0' || str1[tmp] == '/')
	return (1);
      tmp++;
    }
  while (str1[*i] != ']')
    {
      if ((str1[*i] == '-' && str1[*i - 1] != '[' &&
	   str1[*i + 1] != ']' && str2[*j] >= str1[*i - 1]
	   && str2[*j] <= str1[*i + 1]) || str1[*i] == str2[*j])
	{
	  while (str1[*i] != ']')
	    (*i)++;
	  return (0);
	}
      (*i)++;
    }
  return (1);
}

static int	check_wildcard(char *str1, char *str2, int *i, int *j)
{
  int		tmp_i;
  int		tmp_j;

  while (str1[*i] == '*')
    (*i)++;
  if (str1[*i] == '\0' || str1[*i] == '/')
    {
      while (str2[*j] != '\0' && str2[*j] != '/')
	(*j)++;
      return (0);
    }
  tmp_i = *i;
  tmp_j = *j;
  while (str2[tmp_j] != '\0' && str2[tmp_j] != '/')
    {
      *i = tmp_i;
      *j = tmp_j;
      if (glob_and_cmp(str1, str2, i, j) == 0)
	return (0);
      tmp_j++;
    }
  return (1);
}

int		glob_and_cmp(char *str1, char *str2, int *i, int *j)
{
  while (str1[*i] != '\0' && str1[*i] != '/')
    {
      if (str1[*i] == '[' && check_brackets(str1, str2, i, j) != 0)
	return (1);
      if (str1[*i] == '*' && check_wildcard(str1, str2, i, j) != 0)
	return (1);
      if (str1[*i] != str2[*j] && str1[*i] != '?' && str1[*i] != ']')
	return (1);
      if (str1[*i] != '\0' && str1[*i] != '/')
	{
	  (*i)++;
	  (*j)++;
	}
    }
  if (str1[*i] == str2[*j])
    return (0);
  return (2);
}
