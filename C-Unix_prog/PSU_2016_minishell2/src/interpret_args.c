/*
** interpret_args.c for minishell2 in /home/thibaut/Repository/PSU_2016_minishell2
** 
** Made by Thibaut Trouvé
** Login   <thibaut.trouve@epitech.eu>
** 
** Started on  Wed Apr  5 22:39:42 2017 Thibaut Trouvé
** Last update Wed May  3 05:35:21 2017 Thibaut Trouvé
*/

#include <stdlib.h>
#include "my.h"
#include "main.h"

static int	search_op(char **args)
{
  int	i;
  int	j;
  char	*op_tab[7] = {";", ">", ">>", "<", "<<", "|", NULL};

  j = 0;
  i = 0;
  while (args[i] != NULL)
    {
      j = 0;
      while (op_tab[j] != NULL)
	{
	  if (my_strcmp(args[i], op_tab[j]) == 0)
	    return (j);
	  j++;
	}
      i++;
    }
  return (-1);
}

static void	stock_left_redir(char **arg, int *i, int *j, char *ops)
{
  if (arg[*i][1] == '<')
    {
      ops[*j] = DOUBLE_LEFT;
      (*i)++;
    }
  else
    ops[*j] = SIMPLE_LEFT;
  (*j)++;
}

static void	check_op(char **arg, int *i, int *j, char *ops)
{
  if (arg[*i][0] == '<')
    stock_left_redir(arg, i, j, ops);
  else if (arg[*i][0] == '|')
    {
      ops[*j] = PIPE;
      (*j)++;
    }
  else if (arg[*i][0] == '>')
    {
      if (arg[*i][1] == '>')
	{
	  ops[*j] = DOUBLE_RIGHT;
	  (*i)++;
	}
      else
	ops[*j] = SIMPLE_RIGHT;
      (*j)++;
    }
}

char	*check_redirect_pipe(char **arg)
{
  int	i;
  int	j;
  char	*ops;

  ops = malloc(sizeof(char) * my_tablen(arg));
  if (ops == NULL)
    return (NULL);
  i = 0;
  j = 0;
  while (arg[i] != NULL)
    {
      check_op(arg, &i, &j, ops);
      i++;
    }
  ops[j] = '\0';
  return (ops);
}

int	interpret_args(t_tab **data, char **args)
{
  int	idx;
  int	ret;

  if (args[0] == NULL)
    return (0);
  idx = search_op(args);
  if (idx == -1)
    {
      ret = exec_simple_command(data, args);
      if (ret == -1)
	return (-1);
    }
  else
    {
      ret = exec_complex_command(data, args);
      if (ret == -1)
	return (-1);
    }
  return (0);
}
