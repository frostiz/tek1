/*
** my_path_to_wordtab.c for my_chain_to_wordtab.c in /home/roye_v/delivery/CPE_2016/CPE_2016_corewar
** 
** Made by Vincent Roye
** Login   <roye_v@epitech.net>
** 
** Started on  Tue Mar 28 20:04:29 2017 Vincent Roye
** Last update Thu Mar 30 22:27:51 2017 Vincent Roye
*/

#include <stdlib.h>
#include "asm.h"
#include "my.h"

static int		count_list(t_label *list)
{
  int			i;
  t_label		*tmp;

  i = 0;
  tmp = list;
  while (tmp != NULL)
    {
      i++;
      tmp = tmp->next;
    }
  return (i);
}

char		**my_label_to_wordtab(t_label *list)
{
  char		**stock;
  t_label	*tmp;
  int		line;
  int		i;

  tmp = list;
  line = 0;
  i = 0;
  stock = malloc(sizeof(char *) * (count_list(list) + 1));
  while (tmp != NULL)
    {
      stock[line] = malloc(sizeof(char) * my_strlen(tmp->value) + 1);
      while (tmp->value[i] != '\0')
	{
	  stock[line][i] = tmp->value[i];
	  i++;
	}
      stock[line][i] = '\0';
      i = 0;
      line++;
      tmp = tmp->next;
    }
  stock[line] = NULL;
  return (stock);
}
