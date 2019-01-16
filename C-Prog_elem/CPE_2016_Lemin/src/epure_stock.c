/*
** epure_stock.c for lemin in /home/thibaut/Repository/CPE_2016_Lemin
** 
** Made by Thibaut Trouvé
** Login   <thibaut.trouve@epitech.eu>
** 
** Started on  Fri Apr 21 18:18:04 2017 Thibaut Trouvé
** Last update Sun Apr 30 21:50:14 2017 Thibaut Trouvé
*/

#include <stdlib.h>
#include "lemin.h"
#include "tunnel.h"
#include "my.h"

int	check_line(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] == '#')
	{
	  if (my_strcmp(&str[i + 1], "#start") != 0 &&
	      my_strcmp(&str[i + 1], "#end") != 0)
	    {
	      str[i] = '\0';
	    }
	  return (0);
	}
      i++;
    }
  return (0);
}

void	epure_endspace(char **stock)
{
  int	i;
  int	len;

  i = 0;
  while (stock[i] != NULL)
    {
      len = my_strlen(stock[i]) - 1;
      if (len > 0)
	{
	  if (stock[i][len] == ' ' || stock[i][len] == '\t')
	    {
	      while ((stock[i][len] == ' ' || stock[i][len] == '\t') && len > 0)
		len--;
	      len++;
	      stock[i][len] = '\0';
	    }
	}
      i++;
    }
}

char	**epure_stock(char **stock)
{
  int	i;

  i = 0;
  epure_endspace(stock);
  while (stock[i] != NULL)
    {
      check_line(stock[i]);
      i++;
    }
  stock = delete_emptyline(stock);
  if (stock == NULL)
    return (NULL);
  return (stock);
}
