/*
** multiple_label.c for multiple_label.c in /home/roye_v/delivery/CPE_2016/CPE_2016_corewar
** 
** Made by Vincent Roye
** Login   <roye_v@epitech.net>
** 
** Started on  Sun Apr  2 10:57:46 2017 Vincent Roye
** Last update Sun Apr  2 19:38:14 2017 Thibaut Trouvé
*/

#include <stdlib.h>
#include "asm.h"
#include "op.h"
#include "my.h"

static void	init_values(int *i, int *j,
			    int *line, int *next_one)
{
  *i = 1;
  *j = 0;
  *line = 0;
  *next_one = 0;
}

static int		write_error(char **stock, int j)
{
  my_put_error("Label appear twice :");
  my_put_error(stock[j]);
  my_put_error("\n");
  return (1);
}

static void	incr_values(int *next_one, int *j,
			    int *i, int *line)
{
  (*next_one)++;
  *j = *next_one;
  *i = *next_one + 1;
  (*line)++;
}

static int	array_len(char **stock)
{
  int		i;

  i = 0;
  while (stock[i] != NULL)
    i++;
  return (i);
}

int		multiple_label(t_label *label)
{
  int		i;
  int		j;
  int		line;
  int		max;
  int		next_one;
  char		**stock;

  stock = my_label_to_wordtab(label);
  init_values(&i, &j, &line, &next_one);
  max = array_len(stock);
  while (stock[line] != NULL)
    {
      while (i < max)
	{
	  if (stock[i] != NULL && stock[j] != NULL)
	    {
	      if (my_strcmp(stock[j], stock[i]) == 0)
		if (write_error(stock, j) == 1)
		  return (1);
	    }
	  i++;
	}
      incr_values(&next_one, &j, &i, &line);
    }
  return (0);
}
