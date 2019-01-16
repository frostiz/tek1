/*
** replace_tab.c for 42sh in /home/dubret_v/delivery/semestre2/Unix/PSU_2016_42sh
** 
** Made by dubret_v
** Login   <victor.dubret@epitech.eu>
** 
** Started on  Sun May 21 14:43:52 2017 dubret_v
** Last update Sun May 21 17:46:31 2017 dubret_v
*/

#include		<stdlib.h>
#include		"mysh.h"

static	int	is_quotes(int *i, char *tab, char *str, int *len)
{
  *i += 1;
  cpy_inside_quotes(tab, str, i);
  *len += 1;
  return (1);
}

static	int	is_no_quotes(char *tab, char *str, int *i, int length)
{
  tab[(*i) - length] = str[*i];
  *i += 1;
  return (0);
}

char		**replace_tab(char **tab, char *str, char c)
{
  int		i;
  int		ver;
  int		len;
  int		length;

  len = 0;
  i = 0;
  ver = 0;
  while (str[i] != '\0')
    {
      length = i;
      if (str[i] == '"')
	ver = is_quotes(&i, tab[len], str, &len);
      while (str[i] != c && str[i] != '"' && str[i] != '\0')
	ver = is_no_quotes(tab[len], str, &i, length);
      if (length != i && ver == 0)
	{
	  tab[len][i - length] = '\0';
	  len++;
	}
      if (str[i] != '\0' && str[i] != '"')
	i++;
    }
  return (tab);
}
