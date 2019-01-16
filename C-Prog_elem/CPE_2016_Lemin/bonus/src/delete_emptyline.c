/*
** delete_emptyline.c for delete_emptyline.c in /home/roye_v/delivery/CPE_2016/CPE_2016_Lemin
** 
** Made by Vincent Roye
** Login   <roye_v@epitech.net>
** 
** Started on  Sun Apr 30 15:07:13 2017 Vincent Roye
** Last update Sun Apr 30 15:57:52 2017 dubret_v
*/

#include <stdlib.h>
#include "lemin.h"
#include "my.h"
#include "tunnel.h"

static int	init_values(t_empty *stk, char **stock)
{
  stk->i = 0;
  stk->j = 0;
  stk->line = 0;
  stk->line2 = 0;
  if (stock[0] == NULL)
    return (1);
  stk->tmp = malloc(sizeof(char *) * (array_len(stock) + 1));
  if (stk->tmp == NULL)
    return (1);
  return (0);
}

static void	copy_char(char **stock, t_empty *stk)
{
  stk->tmp[stk->line2][stk->j] = stock[stk->line][stk->i];
  (stk->i)++;
  (stk->j)++;
}

static void	new_line(t_empty *stk)
{
  stk->tmp[stk->line2][stk->j] = '\0';
  stk->j = 0;
  stk->i = 0;
  (stk->line2)++;
  (stk->line)++;
}

static char	**return_finish(t_empty stk)
{
  stk.tmp[stk.line2] = NULL;
  return (stk.tmp);
}

char	    **delete_emptyline(char **stock)
{
  t_empty	stk;

  if (init_values(&stk, stock) == 1)
    return (NULL);
  while (stock[stk.line] != NULL)
    {
      while (stock[stk.line] != NULL && stock[stk.line][0] == '\0')
	stk.line++;
      if (stock[stk.line] == NULL)
	return (return_finish(stk));
      stk.tmp[stk.line2] = malloc(sizeof(char) *
				  (my_strlen(stock[stk.line]) + 1));
      if (stk.tmp[stk.line2] == NULL)
	return (NULL);
      while (stock[stk.line][stk.i] == ' ' ||
	     stock[stk.line][stk.i] == '\t')
	stk.i++;
      while (stock[stk.line][stk.i] != '\0')
	copy_char(stock, &stk);
      new_line(&stk);
    }
  stk.tmp[stk.line2] = NULL;
  return (stk.tmp);
}
