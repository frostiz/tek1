/*
** check_cmd_syntax.c for minishell2 in /home/thibaut/Repository/PSU_2016_minishell2/src
** 
** Made by Thibaut Trouvé
** Login   <thibaut.trouve@epitech.eu>
** 
** Started on  Wed May  3 04:46:33 2017 Thibaut Trouvé
** Last update Wed May  3 05:11:37 2017 Thibaut Trouvé
*/

#include <stdlib.h>
#include "main.h"
#include "my.h"

static int	check_redir_error(t_cmd *tmp, int i)
{
  if (tmp->args[i + 1] == NULL)
    return (2);
  else if (is_in(tmp->args[i + 1][0], "><|") == 1)
    return (2);
  else if (i == 0)
    {
      if (tmp->args[i + 2] == NULL)
	return (1);
    }
  return (0);
}

static int	check_pipe_error(t_cmd *tmp, int i)
{
  if (i == 0)
    return (1);
  if (tmp->args[i + 1] == NULL)
    return (1);
  else if (is_in(tmp->args[i + 1][0], "><|") == 1)
    return (1);
  return (0);
}

static int	check_cmd_errors(t_cmd *tmp, int i)
{
  int	ret;

  if (is_in(tmp->args[i][0], "><") == 1)
    {
      ret = check_redir_error(tmp, i);
      if (ret != 0)
	return (ret);
    }
  else if (is_in(tmp->args[i][0], "|") == 1)
    {
      ret = check_pipe_error(tmp, i);
      if (ret != 0)
	return (ret);
    }
  return (0);
}

int	check_invalid_syntax(t_cmd *cmd)
{
  t_cmd	*tmp;
  int	i;
  int	ret;

  tmp = cmd;
  while (tmp != NULL)
    {
      i = 0;
      while (tmp->args[i] != NULL)
	{
	  ret = check_cmd_errors(tmp, i);
	  if (ret != 0)
	    return (ret);
	  i++;
	}
      tmp = tmp->next;
    }
  return (0);
}
