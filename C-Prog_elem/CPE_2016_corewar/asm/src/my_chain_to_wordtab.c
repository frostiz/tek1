/*
** my_path_to_wordtab.c for my_chain_to_wordtab.c in /home/roye_v/delivery/CPE_2016/CPE_2016_corewar
** 
** Made by Vincent Roye
** Login   <roye_v@epitech.net>
** 
** Started on  Tue Mar 28 20:04:29 2017 Vincent Roye
** Last update Sun Apr  2 20:58:12 2017 Vincent Roye
*/

#include <stdlib.h>
#include "asm.h"
#include "my.h"

static int		count_list(t_elem *list)
{
  int			i;
  t_elem		*tmp;

  i = 0;
  tmp = list;
  while (tmp != NULL)
    {
      i++;
      tmp = tmp->next;
    }
  return (i);
}

static void	init_values(int *line, int *i)
{
  *line = 0;
  *i = 0;
}

static void	new_line(char **stock, int *line, int *i)
{
  stock[*line][*i] = '\0';
  *i = 0;
  (*line)++;
}

char		**my_chain_to_wordtab(t_elem *list)
{
  char		**stock;
  t_elem	*tmp;
  int		line;
  int		i;

  tmp = list;
  init_values(&line, &i);
  stock = malloc(sizeof(char *) * (count_list(list) + 1));
  if (stock == NULL)
    return (NULL);
  while (tmp != NULL)
    {
      stock[line] = malloc(sizeof(char) * my_strlen(tmp->value) + 1);
      if (stock[line] == NULL)
	return (NULL);
      while (tmp->value[i] != '\0')
	{
	  stock[line][i] = tmp->value[i];
	  i++;
	}
      new_line(stock, &line, &i);
      tmp = tmp->next;
    }
  stock[line] = NULL;
  return (stock);
}
