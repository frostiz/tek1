/*
** my_tunnel_to_wordtab.c for my_tunnel_to_wordtab.c in /home/roye_v/delivery/CPE_2016/CPE_2016_Lemin
** 
** Made by Vincent Roye
** Login   <roye_v@epitech.net>
** 
** Started on  Wed Apr 19 17:58:37 2017 Vincent Roye
** Last update Sun Apr 30 21:52:18 2017 dubret_v
*/

#include <stdlib.h>
#include "lemin.h"

static void	new_line2(t_index *nb, char **stock)
{
  stock[nb->line][nb->j] = '\0';
  (nb->line)++;
  (nb->i)++;
  stock[nb->line] = malloc(sizeof(char) * (nb->max));
  if (stock[nb->line] == NULL)
    return ;
  nb->j = 0;
}

static int	init_value_to_wordtab(t_index *nb, char *str)
{
  nb->max = 0;
  nb->line = 0;
  nb->i = 0;
  if (str == NULL)
    return (1);
  while (str[nb->i] != '\0')
    {
      (nb->i)++;
      (nb->max)++;
    }
  return (0);
}

static void	copy_character(char **stock, t_index *nb, char *str)
{
  stock[nb->line][nb->j] = str[nb->i];
  (nb->j)++;
  (nb->i)++;
}

static char	**return_stock(char **stock, t_index nb)
{
  if (nb.j == 0)
    {
      stock[nb.line] = NULL;
      return (stock);
    }
  stock[nb.line][nb.j] = '\0';
  stock[nb.line + 1] = NULL;
  return (stock);
}

char		**my_tunnel_to_wordtab(char *str)
{
  char		**stock;
  t_index	nb;

  if (init_value_to_wordtab(&nb, str) == 1)
    return (NULL);
  stock = malloc(sizeof(char *) * (nb.i + 1));
  if (stock == NULL)
    return (NULL);
  stock[0] = malloc(sizeof(char) * (nb.i + 1));
  if (stock[0] == NULL)
    return (NULL);
  nb.i = 0;
  nb.j = 0;
  while ((str[nb.i] == ' ') ||
	 (str[nb.i] == '\t'))
    (nb.i)++;
  while (str[nb.i] != '\0')
    {
      if (str[nb.i] == '-')
	new_line2(&nb, stock);
      if (str[nb.i] != '\0')
	copy_character(stock, &nb, str);
    }
  return (return_stock(stock, nb));
}
