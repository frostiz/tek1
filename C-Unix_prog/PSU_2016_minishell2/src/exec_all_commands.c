/*
** exec_all_commands.c for minishell2 in /home/thibaut/Repository/PSU_2016_minishell2
** 
** Made by Thibaut Trouvé
** Login   <thibaut.trouve@epitech.eu>
** 
** Started on  Sun Apr  9 14:09:11 2017 Thibaut Trouvé
** Last update Wed May  3 05:57:21 2017 Thibaut Trouvé
*/

#include <stdlib.h>
#include "main.h"
#include "my.h"

int	exec_all_commands(t_tab **data, int err)
{
  t_cmd	*tmp;
  int	ret;

  if (err == 1)
    return (0);
  tmp = (*data)->cmd;
  while (tmp != NULL)
    {
      ret = interpret_args(data, tmp->args);
      if (ret == -1)
	return (-1);
      free_tab(tmp->args);
      tmp = tmp->next;
    }
  return (0);
}
