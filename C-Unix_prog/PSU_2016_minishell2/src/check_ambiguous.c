/*
** check_ambiguous.c for minishell2 in /home/thibaut/Repository/PSU_2016_minishell2/src
** 
** Made by Thibaut Trouvé
** Login   <thibaut.trouve@epitech.eu>
** 
** Started on  Wed May  3 05:02:02 2017 Thibaut Trouvé
** Last update Wed May  3 05:51:40 2017 Thibaut Trouvé
*/

#include <stdlib.h>
#include "main.h"
#include "my.h"

static int	check_nb_redir(t_cmd *tmp, int *i,
			       int *count_input, int *count_output)
{
  if (tmp->args[*i][0] == '<')
    {
      tmp->input = tmp->args[*i + 1];
      if (check_input(tmp->args, *i) == -1)
	return (1);
      (*count_input)++;
    }
  if (tmp->args[*i][0] == '>')
    {
      tmp->output = tmp->args[*i + 1];
      if (check_output(tmp->args, *i) == -1)
	return (2);
      (*count_output)++;
    }
  (*i)++;
  return (0);
}

int	check_ambiguous(t_cmd *cmd)
{
  t_cmd	*tmp;
  int	ret;
  int	i;
  int	count_input;
  int	count_output;

  count_input = 0;
  count_output = 0;
  tmp = cmd;
  while (tmp != NULL)
    {
      i = 0;
      while (tmp->args[i] != NULL)
	{
	  ret = check_nb_redir(tmp, &i, &count_input, &count_output);
	  if (ret != 0)
	    return (ret);
	}
      tmp = tmp->next;
    }
  if (count_input >= 2)
    return (1);
  else if (count_output >= 2)
    return (2);
  return (0);
}
