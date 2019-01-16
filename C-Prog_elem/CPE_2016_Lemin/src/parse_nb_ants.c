/*
** parse_nb_ants.c for lemin in /home/thibaut/Repository/CPE_2016_Lemin
** 
** Made by Thibaut Trouvé
** Login   <thibaut.trouve@epitech.eu>
** 
** Started on  Sat Apr 29 19:31:34 2017 Thibaut Trouvé
** Last update Sun Apr 30 21:53:42 2017 Thibaut Trouvé
*/

#include <stdlib.h>
#include "my.h"
#include "lemin.h"

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
  int	i;

  tmp = my_str_to_wordtab(str);
  if (tmp == NULL)
    return (-1);
  if (array_len(tmp) != 1)
    {
      free_tab(tmp);
      return (-1);
    }
  free_tab(tmp);
  i = 0;
  while (str[i] != '\0' && (str[i] == '\t' || str[i] == ' '))
    i++;
  while (str[i] != '\0' && (str[i] == '-' || str[i] == '+'))
    i++;
  while (str[i] != '\0' && (str[i] >= '0' && str[i] <= '9'))
    i++;
  while (str[i] != '\0' && (str[i] == '\t' || str[i] == ' '))
    i++;
  if (str[i] == '\0')
    return (1);
  return (-1);
}

static int	get_nb_ants(char **stock, int *idx)
{
  if (stock == NULL)
    return (-1);
  while (stock[*idx] != NULL)
    {
      if (is_not_empty(stock[*idx]) == 1)
	{
	  if (is_num(stock[*idx]) == 1)
	    return (my_getnbr(stock[*idx]));
	  else
	    return (-1);
	}
      (*idx)++;
    }
  return (-1);
}

int	parse_nb_ants(char **stock, int *idx)
{
  int	nb_ants;

  my_printf("#number_of_ants\n");
  nb_ants = get_nb_ants(stock, idx);
  if (nb_ants <= 0)
    my_put_error("Invalid number of ants !\n");
  else
    my_printf("%d\n", nb_ants);
  return (nb_ants);
}
