/*
** malloc_tab.c for 42sh in /home/dubret_v/delivery/semestre2/Unix/PSU_2016_42sh
**
** Made by dubret_v
** Login   <victor.dubret@epitech.eu>
**
** Started on  Sun May 21 14:43:31 2017 dubret_v
** Last update Sun May 21 19:18:20 2017 dubret_v
*/

#include	<stdlib.h>
#include	"mysh.h"

static	char	*is_quotes(int *i, char *str, char *tab)
{
  int		len;

  len = (*i) + 1;
  *i = go_through_quotes(str, (*i) + 1);
  len = ((*i) - 1) - len;
  tab = malloc(sizeof(char) * (len + 5));
  if (tab == NULL)
    return (NULL);
  return (tab);
}

static	char	*is_not_quotes(int *i, char *str, char *tab, char c)
{
  int		len;

  len = *i;
  while (str[*i] != c && str[*i] != '\0')
    *i += 1;
  len = (*i) - len;
  tab = malloc(sizeof(char) * (len + 1));
  if (tab == NULL)
    return (NULL);
  return (tab);
}

char		**malloc_tab(char **tab, char *str, char c)
{
  int		count;
  int		i;

  count = 0;
  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] == '"')
	{
	  tab[count] = is_quotes(&i, str, tab[count]);
	  if (tab[count] == NULL)
	    return (NULL);
	  count++;
	}
      else if (str[i] != c && str[i] != '\0')
	{
	  tab[count] = is_not_quotes(&i, str, tab[count], c);
	  if (tab[count] == NULL)
	    return (NULL);
	  count++;
	}
      else if (str[i] != '\0' && str[i] != '"')
	i++;
    }
  return (tab);
}
