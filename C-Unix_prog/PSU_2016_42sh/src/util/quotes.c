/*
** quotes.c for 42sh in /home/dubret_v/delivery/semestre2/Unix/PSU_2016_42sh
**
** Made by dubret_v
** Login   <victor.dubret@epitech.eu>
**
** Started on  Sat May 20 19:26:39 2017 dubret_v
** Last update Sun May 21 22:12:31 2017 dubret_v
*/

#include	<stdlib.h>
#include	"mysh.h"

void		cpy_inside_quotes(char *stock, char *str, int *i)
{
  int		j;

  j = 0;
  while (str[*i] != '"' && str[*i] != '\0')
    {
      stock[j] = str[*i];
      j++;
      *i += 1;
    }
  if (str[*i] == '"')
    *i += 1;
  stock[j] = '\0';
}

int		go_through_quotes(char *str, int i, char c)
{
  while (str[i] != c && str[i] != '\0')
    i++;
  if (str[i] == c)
    i++;
  return (i);
}

void		remove_quotes(char *str)
{
  unsigned int	i;

  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] == '"')
	remove_character(str, i);
      else
	i++;
    }
}

void		remove_all_quotes(char **tab)
{
  int		i;

  i = 0;
  while (tab != NULL && tab[i] != NULL)
    {
      remove_quotes(tab[i]);
      i++;
    }
}
