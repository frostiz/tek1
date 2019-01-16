/*
** my_str_to_wordtab.c for minishell1 in /home/dubret_v/delivery/Unix/PSU_2016_minishell1
** 
** Made by dubret_v
** Login   <victor.dubret@epitech.eu@epitech.net>
** 
** Started on  Mon Jan 16 13:55:41 2017 dubret_v
** Last update Fri Apr 14 19:57:07 2017 dubret_v
*/

#include <stdio.h>
#include <stdlib.h>

static	int	nb_args(char *str, char sep)
{
  int		i;
  int		count;

  i = 0;
  count = 1;
  while (str[i] != '\0')
    {
      if (str[i] == sep)
	{
	  i++;
	  count += 1;
	}
      if (str[i] != '\0')
	i++;
    }
  return (count);
}

static	int	len_arg(char *str, int i, char sep)
{
  int		count;

  count = 0;
  while (str[i] != '\0' && str[i] != sep)
    {
      count++;
      i++;
    }
  return (count);
}

static	char	*stock_in_tab(char *str, int *i, char *tab_str, char sep)
{
  int		j;

  j = 0;
  while (str[*i] != '\0' && (str[*i] == ' ' || str[*i] == '\t'))
    *i += 1;
  while (str[*i] != '\0' && str[*i] != sep)
    {
      tab_str[j] = str[*i];
      if (tab_str[j] == sep)
	while (str[*i] == sep && str[*i] != '\0')
	  *i += 1;
      else
	*i += 1;
      j++;
    }
  tab_str[j] = '\0';
  if (str[*i] != '\0')
    *i += 1;
  return (tab_str);
}

char	**str_to_wordtab(char *str, char sep)
{
  char		**tab;
  int		i;
  int		row;

  tab = malloc(sizeof(char *) * (nb_args(str, sep) + 1));
  if (tab == NULL)
    return (NULL);
  i = 0;
  row = 0;
  while (str[i] != '\0')
    {
      tab[row] = malloc(sizeof(char) * (len_arg(str, i, sep)) + 1);
      if (tab[row] == NULL)
	return (NULL);
      tab[row] = stock_in_tab(str, &i, tab[row], sep);
      row += 1;
    }
  tab[row] = NULL;
  return (tab);
}
