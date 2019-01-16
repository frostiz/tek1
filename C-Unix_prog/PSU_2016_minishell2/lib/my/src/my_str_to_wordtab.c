/*
** my_str_to_wordtab.c for corewar in /home/thibaut/Repository/CPE_2016_corewar
** 
** Made by Thibaut Trouvé
** Login   <thibaut.trouve@epitech.eu>
** 
** Started on  Wed Mar 29 20:28:12 2017 Thibaut Trouvé
** Last update Sun Apr  9 22:21:39 2017 Thibaut Trouvé
*/

#include <stdlib.h>
#include "my.h"
#include "wordtab.h"

static void	init_count(t_count *i)
{
  i->line = 0;
  i->col = 0;
  i->idx_str = 0;
}

static int	is_in(char c, char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      if (c == str[i])
	return (1);
      i++;
    }
  return (0);
}

static void	cpy(char *str, char **tab, t_count *i, char *separator)
{
  while (str[i->idx_str] != '\0' && is_in(str[i->idx_str], separator) == 0 &&
	 str[i->idx_str] > ' '  && str[i->idx_str] < 127)
    {
      tab[i->line][i->col] = str[i->idx_str];
      i->col++;
      i->idx_str++;
    }
  tab[i->line][i->col] = '\0';
  i->line++;
  i->col = 0;
  i->idx_str--;
}

static	int	nb_word(char *str, char *sep)
{
  int		i;
  int		j;
  int		count;

  i = 0;
  count = 1;
  while (str[i] != '\0')
    {
      j = 0;
      while (sep[j] != '\0')
	{
	  if (str[i] == sep[j])
	    {
	      count++;
	      j = my_strlen(sep) - 1;
	    }
	  j++;
	}
      if (sep[j] == '\0')
	if (str[i] <= ' ' && str[i] >= 0)
	  count++;
      i++;
    }
  return (count);
}

char		**my_str_to_wordtab(char *str, char *separator)
{
  t_count	i;
  char		**tab;

  init_count(&i);
  tab = malloc(sizeof(char *) * (nb_word(str, separator) + 2));
  if (tab == NULL)
    return (NULL);
  while (str[i.idx_str] != '\0')
    {
      if (is_in(str[i.idx_str], separator) == 0 && str[i.idx_str] > ' ' &&
	  str[i.idx_str] < 127)
	{
	  tab[i.line] = malloc(sizeof(char) * (my_strlen(str) + 1
					       - i.idx_str));
	  if (tab[i.line] == NULL)
	    return (NULL);
	  cpy(str, tab, &i, separator);
	}
      i.idx_str++;
    }
  tab[i.line] = NULL;
  return (tab);
}
