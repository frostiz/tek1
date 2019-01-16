/*
** get_nb_fourmi.c for lemin in /home/thibaut/Repository/CPE_2016_Lemin
** 
** Made by Thibaut Trouvé
** Login   <thibaut.trouve@epitech.eu>
** 
** Started on  Fri Apr 21 18:35:37 2017 Thibaut Trouvé
** Last update Sun Apr 30 17:31:15 2017 Vincent Roye
*/

#include <stdlib.h>
#include "lemin.h"
#include "my.h"

static int	is_not_empty(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] != ' ' && str[i] != '\t')
	return (1);
      i++;
    }
  return (0);
}

static int	is_num(char *str)
{
  char	**tmp;

  tmp = my_str_to_wordtab(str);
  if (tmp == NULL)
    return (-1);
  if (array_len(tmp) != 1)
    {
      free_tab(tmp);
      return (-1);
    }
  free_tab(tmp);
  return (1);
}

int	get_nb_fourmi(char **stock)
{
  int	i;

  i = 0;
  while (stock[i] != NULL)
    {
      if (is_not_empty(stock[i]) == 1)
	{
	  if (is_num(stock[i]) == 1)
	    return (my_getnbr(stock[i]));
	  return (0);
	}
      i++;
    }
  return (-1);
}
